*** UID:0001RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Startup Logo Media

## Status

- Confidence: strong for `.LGO` static logo format, `LOGO.PAK`/`LOGO.PAD` selection, and memory-backed segmented Bink payload handling; medium for final source asset packaging.
- Owner modules: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Related classes: [UID:00007G][LogoPane](by-class/LogoPane.md), [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md), [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)

## Resource Families

| Resource | Loader | Format evidence |
| --- | --- | --- |
| `NEXON.LGO` or equivalent startup logo path | `LogoPane::LogoPane` at `0x004f4c10` | Dword compressed image size, compressed image bytes, dword palette size, palette bytes. |
| `LOGO.PAK` | standalone startup Bink playback helper at `0x004f5710` | Selected when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA label `byte_66DA97` is `1`; existence checked through [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md), read into `_AUTOBUF<unsigned char>`, first dword is the first segment size, and first Bink data starts at `buffer + 4`. |
| `LOGO.PAD` | standalone startup Bink playback helper at `0x004f5710` | Selected when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA label `byte_66DA97` is not `1`; same existence check and memory-backed Bink payload handling as `LOGO.PAK`. |
| caller-supplied startup Bink payload | `LogoPlayerPane::LogoPlayerPane` at `0x004f53b0` | File path is supplied by the caller; the file is read into `_AUTOBUF<unsigned char>`, first dword is treated as first segment size, and Bink data starts immediately after that dword. |

## Static Logo Format

`LogoPane` uses screen width/height globals [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) / `word_66DA94` and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) / `word_66DA98` to size the decoded pixel buffer. It reads a compressed image byte count, allocates compressed and decoded buffers, calls `Uncompress`, stores the decoded pixels into the pane tile context, reads a palette blob, loads it into `DLPalette`, and builds the RLE mask used for blitting.

This is a startup-logo-specific container, not a general DAT archive entry format.

## IDA MCP Evidence

- UTF-16 `NEXON.LGO` was verified at `0x0061d24c`.
- `NEXON.LGO` has xrefs from `0x004f6401` and `0x004f6435` inside `0x004f5fb0-0x004f6490`, the startup decision path that checks whether the logo file exists and creates the logo pane when present.
- IDA decompilation of `0x004f4c10-0x004f53a8` shows `LogoPane` opening the file path passed to it, reading compressed image size/data, uncompressing into the screen-sized buffer, then reading and loading palette data.
- IDA decompilation of the startup logo decision path confirms `NEXON.LGO` is used as the static logo asset before falling back to later startup flow.

## Segmented Bink Payload

`LogoPlayerPane` reads the whole movie file through `StdioFile` into an embedded `_AUTOBUF<unsigned char>`. The first dword is stored as the segment size at pane offset `+0x114`. The first Bink stream begins at `buffer + 4`; the next segment probe uses `buffer + segmentSize + 4`.

IDA decompilation of `0x005c0110` shows `BinkOpen(segmentData, 67633152)`, and `67633152 == 0x04080000`. Public Bink flag references identify that bit pair as `BINKFROMMEMORY | BINKNOSKIP`, so the current Wave3 `filePath` parameter name is wrong. Treat the helper as memory-backed Bink open logic.

The constructor and advance path both pass a segment size/remaining-size argument to `0x005c0110`, but the recovered helper does not consume it before calling `BinkOpen`. Keep that unused-size argument in the open questions for source rewrite rather than inventing a length-check side effect.

2026-06-03 live IDA MCP disassembly confirms the standalone startup playback path:

- byte-pattern scanning finds UTF-16 `LOGO.PAK` at `0x0061d0c4` with xrefs at `0x004f5760` and `0x004f5775`;
- UTF-16 `LOGO.PAD` is at `0x0061d0d8` with xrefs at `0x004f577c` and `0x004f5791`;
- `0x004f5750` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, probes the selected file through `0x00582460`, and exits early if the file is absent;
- after reading the selected file into `_AUTOBUF<unsigned char>`, `0x004f57d4` reads the first dword as the first segment size, `0x004f57de` sets the first Bink pointer to `buffer + 4`, `0x004f57e4` stores the next segment pointer in `dword_69B474`, and `0x004f57f2` stores the remaining length in `dword_69B478`;
- `0x004f5809-0x004f580f` opens the first segment through `BinkOpen(buffer + 4, 0x04080000)`;
- [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md) reopens from `dword_69B474` with the same `0x04080000` flags when [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md) is still set and the current frame is before the midpoint.

Local file-system check on 2026-06-03 found no loose `NEXON.LGO`, `LOGO.PAK`, `LOGO.PAD`, `.LGO`, `.PAK`, `.PAD`, or `.BIK` files under the extracted `C:\Users\admin\Desktop\Clone\NexusTK` tree or under `source-3` staging. Treat this only as a current local-package observation: the IDA path-existence checks prove these media files are optional loose startup assets, but the original distribution/installer packaging still needs archive-level confirmation.

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md)
- [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md)
- [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md)
- [UID:00029G][0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals](by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- What existed before: the page was scored unevaluated despite having static-logo and Bink-format notes.
- Changed to: scored `COMPLETION:68` / `CONFIDENCE:84` and added direct IDA MCP evidence for `NEXON.LGO` and the static logo loader.
- Summary and evidence: the static logo file and loader format are now tied to IDA string/xref/decompilation evidence; score remains moderate because the Bink payload helper and final ownership details still need a separate whole-item audit.
- 2026-06-03: raised to `COMPLETION:78` / `CONFIDENCE:88` after live IDA MCP byte-pattern and disassembly checks verified the `LOGO.PAK`/`LOGO.PAD` UTF-16 literals, exact xrefs, `byte_66DA97` selection branch, `PathExistsViaStat` gating, `_AUTOBUF` payload layout, first-segment and next-segment pointer math, `BinkOpen(..., 0x04080000)` callsites, and midpoint reopen path through `byte_66DB42`/`dword_69B474`. Added the local extracted-tree absence caveat; completion remains below final quality because archive/installer packaging and exact source asset provenance are still unproven.
- 2026-06-07 A005 resolved-name cleanup:
  - What existed before: startup-logo media notes used only raw global labels `byte_66DA97`, `word_66DA94`, and `word_66DA98`.
  - What it was changed to: the same evidence now records resolved global names `g_useEpfAssets`, `g_screenWidth`, and `g_screenHeight` beside the historical IDA labels.
  - Summary/evidence: generated resolved-name reports map the raw labels to those globals, and the existing IDA evidence on this page already proves the branch and dimension uses.
