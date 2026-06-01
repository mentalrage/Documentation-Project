*** UID:0001RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Startup Logo Media

## Status

- Confidence: strong for `.LGO` static logo format and memory-backed segmented Bink payload handling; medium for final Bink helper ownership.
- Owner modules: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Related classes: [UID:00007G][LogoPane](by-class/LogoPane.md), [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md), [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)

## Resource Families

| Resource | Loader | Format evidence |
| --- | --- | --- |
| `NEXON.LGO` or equivalent startup logo path | `LogoPane::LogoPane` at `0x004f4c10` | Dword compressed image size, compressed image bytes, dword palette size, palette bytes. |
| startup Bink payload | `LogoPlayerPane::LogoPlayerPane` at `0x004f53b0` | File is read into `_AUTOBUF<unsigned char>`; first dword is treated as first segment size; Bink data starts immediately after that dword. |

## Static Logo Format

`LogoPane` uses screen width/height globals `word_66DA94` and `word_66DA98` to size the decoded pixel buffer. It reads a compressed image byte count, allocates compressed and decoded buffers, calls `Uncompress`, stores the decoded pixels into the pane tile context, reads a palette blob, loads it into `DLPalette`, and builds the RLE mask used for blitting.

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

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- What existed before: the page was scored unevaluated despite having static-logo and Bink-format notes.
- Changed to: scored `COMPLETION:68` / `CONFIDENCE:84` and added direct IDA MCP evidence for `NEXON.LGO` and the static logo loader.
- Summary and evidence: the static logo file and loader format are now tied to IDA string/xref/decompilation evidence; score remains moderate because the Bink payload helper and final ownership details still need a separate whole-item audit.
