*** UID:0001RN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Startup Logo Media

## Status

- Confidence: very strong for `.LGO` static logo format, `LOGO.PAK`/`LOGO.PAD` selection, memory-backed segmented Bink payload handling, current consumer xrefs, and repeated negative DAT/loose-media audits; medium for original installer asset packaging.
- Owner modules: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- Related classes: [UID:00007G][LogoPane](by-class/LogoPane.md), [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md), [UID:0000FV][VideoPlayerPane](by-class/VideoPlayerPane.md)

## Resource Families

| Resource | Loader | Format evidence |
| --- | --- | --- |
| `NEXON.LGO` or equivalent startup logo path | `LogoPane::LogoPane` at `0x004f4c10`; retained helper [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) | Dword compressed image size, compressed image bytes, dword palette size, palette bytes. |
| `LOGO.PAK` | standalone startup Bink playback helper at `0x004f5710` | Selected when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA label `byte_66DA97` is `1`; existence checked through [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md), read into `_AUTOBUF<unsigned char>`, first dword is the first segment size, and first Bink data starts at `buffer + 4`. |
| `LOGO.PAD` | standalone startup Bink playback helper at `0x004f5710` | Selected when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA label `byte_66DA97` is not `1`; same existence check and memory-backed Bink payload handling as `LOGO.PAK`. |
| caller-supplied startup Bink payload | `LogoPlayerPane::LogoPlayerPane` at `0x004f53b0` | File path is supplied by the caller; the file is read into `_AUTOBUF<unsigned char>`, first dword is treated as first segment size, and Bink data starts immediately after that dword. |

## Static Logo Format

`LogoPane` uses screen width/height globals [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) / `word_66DA94` and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) / `word_66DA98` to size the decoded pixel buffer. The constructor and retained [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) path both read a compressed image byte count, allocate compressed and decoded buffers, call stock zlib 1.1.4 `uncompress`, store the decoded pixels into the pane tile context, read a palette blob, load it into `DLPalette`, and build the RLE mask used for blitting.

The palette field is `[u32 compressedPaletteSize][compressedPaletteBytes]`, where the decompressed payload is exactly 768 bytes: 256 packed Windows `RGBTRIPLE` records in B/G/R byte order. [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md) performs the palette inflation and calls Surface slot 9 `g_pfnPackPixel` as red, green, blue for each record. Both constructor call `0x004f4dfe` and retained-loader call `0x004f51f3` ignore EAX, confirming the source-facing palette member is `void`. This resource contract does not move ownership: LogoPane owns file parsing, DLPalette owns palette conversion, zlib owns `uncompress`, and Surface owns runtime RGB555/RGB565 packing.

This is a startup-logo-specific container, not a general DAT archive entry format.

## IDA MCP Evidence

- UTF-16 `NEXON.LGO` was verified at `0x0061d24c`.
- `NEXON.LGO` has xrefs from `0x004f6401` and `0x004f6435` inside `0x004f5fb0-0x004f6490`, the startup decision path that checks whether the logo file exists and creates the logo pane when present.
- IDA decompilation of `0x004f4c10-0x004f53a8` shows `LogoPane` opening the file path passed to it, reading compressed image size/data, uncompressing into the screen-sized buffer, then reading and loading palette data.
- IDA decompilation of the startup logo decision path confirms `NEXON.LGO` is used as the static logo asset before falling back to later startup flow.
- 2026-06-14 IDA MCP refresh in IDB `a001_goal2_class_batch` confirmed the relevant function surface: `0x004f4c10` (`sub_4F4C10`, static logo pane constructor), `0x004f53b0` (`sub_4F53B0`, caller-supplied logo player constructor), `0x004f5710` (`sub_4F5710`, standalone startup Bink playback loop), `0x004f5ae0` (`sub_4F5AE0`, midpoint restart helper), `0x004f5fb0` (`sub_4F5FB0`, startup logo decision path), and `0x005c0110` (`sub_5C0110`, memory-backed Bink open helper).
- The same refresh rechecked `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD` xrefs at `0x004f6401`/`0x004f6435`, `0x004f5760`/`0x004f5775`, and `0x004f577c`/`0x004f5791`, respectively.
- 2026-06-16 A002 refresh on IDA session `b001_mappane_0001AW_20260616` reconfirmed the current function surface and sizes: `0x004f4c10` static logo pane constructor size `0x29c`, `0x004f53b0` caller-supplied logo player constructor size `0x150`, `0x004f5710` standalone startup Bink playback helper size `0x2b6`, `0x004f59d0` temporary WndProc size `0xf7`, `0x004f5ae0` midpoint restart helper size `0x3e`, `0x004f5fb0` startup decision path size `0x4e0`, and `0x005c0110` memory-backed Bink open helper size `0x64`.
- The same 2026-06-16 xref pass reconfirmed `NEXON.LGO` refs only in `sub_4F5FB0` at `0x004f6401`/`0x004f6435`, `LOGO.PAK` refs only in `sub_4F5710` at `0x004f5760`/`0x004f5775`, and `LOGO.PAD` refs only in `sub_4F5710` at `0x004f577c`/`0x004f5791`. Filtered decompilation reconfirmed `sub_4F5FB0` probes `NEXON.LGO` via `PathExistsViaStat_00582460` before constructing `LogoPane`, while `sub_4F5710` chooses `LOGO.PAK` versus `LOGO.PAD`, checks existence, reads the file into `_AUTOBUF<unsigned char>`, and opens the first memory-backed Bink segment.
- 2026-06-17 B002 source-quality pass added [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) as a second binary confirmation of the static `.LGO` contract. The retained loader helper reads the same `[compressedImageSize][compressedImage][paletteSize][paletteBlob]` layout, inflates to `g_screenWidth * g_screenHeight`, loads the palette through `DLPalette::LoadFromBitmapPalette`, and then finalizes the `EPFTileContext` mask data.

## Segmented Bink Payload

`LogoPlayerPane` reads the whole movie file through `StdioFile` into an embedded `_AUTOBUF<unsigned char>`. The first dword is stored as the segment size at pane offset `+0x114`. The first Bink stream begins at `buffer + 4`; the next segment probe uses `buffer + segmentSize + 4`.

IDA decompilation of `0x005c0110` shows `BinkOpen(segmentData, 67633152)`, and `67633152 == 0x04080000`. Public Bink flag references identify that bit pair as `BINKFROMMEMORY | BINKNOSKIP`, so the current Wave3 `filePath` parameter name is wrong. Treat the helper as memory-backed Bink open logic.

The constructor and advance path both pass a segment size/remaining-size argument to `0x005c0110`, but the recovered helper does not consume it before calling `BinkOpen`. Keep that unused-size argument in the open questions for source rewrite rather than inventing a length-check side effect.

2026-06-20 B003 Rule 26 reanalysis resolves the object-pane segment-advance names and cutoff:

- `LogoPlayerPane +0x100/+0x104/+0x108` is the embedded `_AUTOBUF<unsigned char> m_movieData`, with `m_movieData.m_data` pointing at the loaded payload and `m_movieData.m_count` storing the loaded byte count.
- `LogoPlayerPane +0x114` is `m_firstSegmentSize`, the first payload dword. The constructor opens `m_movieData.m_data + 4`; `LogoPlayerPane::AdvanceToNextSegment()` opens `m_movieData.m_data + 4 + m_firstSegmentSize`.
- `LogoPlayerPane +0x110` is `m_hasRequestedSegmentAdvance`, a one-shot guard set before the second-segment open attempt. A failed open still consumes the user-requested advance.
- The object-pane path uses inherited `m_binkHandle->FrameNum < 100` as the user-skip cutoff for early segment advance. The standalone startup-logo WndProc path instead uses [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md)'s `FrameNum < Frames / 2` cutoff, `g_startupLogoBinkRestartPending`, and `g_startupLogoBinkNextSegment`.
- `0x005c0110` is best documented as protected `VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)`: caller-specific payload slices come from `LogoPlayerPane`, while Bink handle ownership and setup remain in `VideoPlayerPane`.

2026-06-03 live IDA MCP disassembly confirms the standalone startup playback path:

- byte-pattern scanning finds UTF-16 `LOGO.PAK` at `0x0061d0c4` with xrefs at `0x004f5760` and `0x004f5775`;
- UTF-16 `LOGO.PAD` is at `0x0061d0d8` with xrefs at `0x004f577c` and `0x004f5791`;
- `0x004f5750` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, probes the selected file through `0x00582460`, and exits early if the file is absent;
- after reading the selected file into `_AUTOBUF<unsigned char>`, `0x004f57d4` reads the first dword as the first segment size, `0x004f57de` sets the first Bink pointer to `buffer + 4`, `0x004f57e4` stores the next segment pointer in `dword_69B474`, and `0x004f57f2` stores the remaining length in `dword_69B478`;
- `0x004f5809-0x004f580f` opens the first segment through `BinkOpen(buffer + 4, 0x04080000)`;
- [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md) reopens from `g_startupLogoBinkNextSegment` / `dword_69B474` with the same `0x04080000` flags when [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md) / `g_startupLogoBinkRestartPending` is still set and the current frame is before half of the total frame count.

Local file-system check on 2026-06-03 found no loose `NEXON.LGO`, `LOGO.PAK`, `LOGO.PAD`, `.LGO`, `.PAK`, `.PAD`, or `.BIK` files under the extracted `C:\Users\admin\Desktop\Clone\NexusTK` tree or under `source-3` staging. Treat this only as a current local-package observation: the IDA path-existence checks prove these media files are optional loose startup assets, but the original distribution/installer packaging still needs archive-level confirmation.

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data`, checked the read-only client tree for loose exact filenames, and performed a narrow raw-name scan of the packaged executables. No current DAT entry or loose file was found for `NEXON.LGO`, `LOGO.PAK`, or `LOGO.PAD`.

| Resource | Package audit result | Payload conclusion |
| --- | --- | --- |
| `NEXON.LGO` | No exact DAT entry and no loose exact file under the read-only package tree. UTF-16 literal appears in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` at raw offset `2,210,892`. | Runtime/code contract is proven, but the media payload is not present in the current audited resource package. Treat as optional loose/installer media until an original installer source is found. |
| `LOGO.PAK` | No exact DAT entry and no loose exact file under the read-only package tree. UTF-16 literal appears in the same executables at raw offset `2,210,500`. | Runtime segmented-Bink handling is proven, but the package payload remains unresolved. |
| `LOGO.PAD` | No exact DAT entry and no loose exact file under the read-only package tree. UTF-16 literal appears in the same executables at raw offset `2,210,520`. | Runtime segmented-Bink handling is proven, but the package payload remains unresolved. |

2026-06-14 A002 package-provenance continuation reran corrected DAT start-offset parsing across the current archives, searched loose files across all of `E:\2026\Resources`, and repeated the raw executable scan. The result did not change the payload status: `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD` are executable literals only in this audited distribution, with no current DAT entry and no loose media file.

2026-06-16 A002 repeated the same current-package checks during the resource-provenance pass. Fixed-table DAT parsing found no `NEXON.LGO`, `LOGO.PAK`, or `LOGO.PAD` entry in the current 250 DAT archives; an exact loose-file search under `E:\2026\Resources` found no matching media files; and UTF-16 executable scans again found the same raw offsets in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`: `LOGO.PAK` at `2,210,500`, `LOGO.PAD` at `2,210,520`, and `NEXON.LGO` at `2,210,892`. This strengthens the current-distribution absence finding but still does not identify the original installer/loose-media source.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The code-facing resource names, owner modules, loader functions, static `.LGO` image/palette layout, optional-path gating, segmented Bink buffer layout, first/next segment pointer math, Bink flags, midpoint restart globals, current function/xref refresh, and repeated negative package/loose-file audit are documented. Completion remains capped because the actual startup media payloads are absent from the audited package and original installer/archive provenance is still not proven. |
| Confidence | 94 | Confidence is very strong for the runtime contract because current IDA xrefs and decompilation confirm all named startup logo resources and consumers, and repeated corrected package/loose/raw scans confirm these names are not current DAT or loose payloads in the audited tree. It is not higher because the original distribution source for the optional media is still unknown. |

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md)
- [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md)
- [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md)
- [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md)
- [UID:00029G][0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals](by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)

## Changes

- 2026-07-28 B001 UID0004I4 static-logo format synchronization:
  - Score and unresolved original installer/media-payload provenance unchanged.
  - Refined the `.LGO` palette field from opaque bytes to a size-prefixed zlib-compressed 256-entry `RGBTRIPLE`/768-byte BGR payload, linked both exact caller sites, and documented the DLPalette/Surface/zlib ownership boundary.

- 2026-06-25 B013 TryAdvanceStartupLogoBinkSegment sync:
  - Score unchanged at `87/94`.
  - Summary/evidence: updated standalone segmented-Bink text to use [UID:00022U][0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment](by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md), `g_startupLogoBinkNextSegment`, `g_startupLogoBinkRestartPending`, and the half-total-frame cutoff. Package provenance remains the score-limiting blocker and is unchanged.
- What existed before: the page was scored unevaluated despite having static-logo and Bink-format notes.
- Changed to: scored `COMPLETION:68` / `CONFIDENCE:84` and added direct IDA MCP evidence for `NEXON.LGO` and the static logo loader.
- Summary and evidence: the static logo file and loader format are now tied to IDA string/xref/decompilation evidence; score remains moderate because the Bink payload helper and final ownership details still need a separate whole-item audit.
- 2026-06-03: raised to `COMPLETION:78` / `CONFIDENCE:88` after live IDA MCP byte-pattern and disassembly checks verified the `LOGO.PAK`/`LOGO.PAD` UTF-16 literals, exact xrefs, `byte_66DA97` selection branch, `PathExistsViaStat` gating, `_AUTOBUF` payload layout, first-segment and next-segment pointer math, `BinkOpen(..., 0x04080000)` callsites, and midpoint reopen path through `byte_66DB42`/`dword_69B474`. Added the local extracted-tree absence caveat; completion remains below final quality because archive/installer packaging and exact source asset provenance are still unproven.
- 2026-06-07 A005 resolved-name cleanup:
  - What existed before: startup-logo media notes used only raw global labels `byte_66DA97`, `word_66DA94`, and `word_66DA98`.
  - What it was changed to: the same evidence now records resolved global names `g_useEpfAssets`, `g_screenWidth`, and `g_screenHeight` beside the historical IDA labels.
  - Summary/evidence: generated resolved-name reports map the raw labels to those globals, and the existing IDA evidence on this page already proves the branch and dimension uses.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:78` / `CONFIDENCE:88` documented the startup logo formats and Bink split but still relied on older evidence for several function boundaries.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:91` after a refreshed IDA MCP pass confirmed current function bounds, logo string xrefs, standalone playback selection, segmented memory-backed Bink layout, and midpoint restart support.
  - Remaining below gate: original installer/archive media provenance and exact loose-file sourcing remain unproven by the binary.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:91`, with runtime media contracts proven but package provenance open.
  - After: raised to `COMPLETION:86`, `CONFIDENCE:92`, with a current DAT/loose-file negative audit for `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD`, plus executable UTF-16 literal offsets proving the audited package contains only code references for these names.
- 2026-06-14 A002 package-provenance continuation:
  - Before: `COMPLETION:86`, `CONFIDENCE:92`, with startup media payloads absent from the first current-package audit.
  - After: `COMPLETION:86`, `CONFIDENCE:93`; corrected DAT parsing, all-`E:\2026\Resources` loose-file search, and repeated raw executable scan reconfirmed `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD` are executable-literal-only in the audited distribution. Completion does not move because the actual media payloads remain missing.
- 2026-06-16 A002 resource-provenance refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:93`.
  - After: `COMPLETION:87`, `CONFIDENCE:94`; current IDA `lookup_funcs`, `xrefs_to`, and filtered decompilation reconfirmed the startup logo consumer split, and repeated DAT/loose/raw scans again classified `NEXON.LGO`, `LOGO.PAK`, and `LOGO.PAD` as executable-literal-only in the audited current distribution.
  - Remaining blocker: actual media payload provenance is still unresolved because no DAT entry, loose file, or installer payload has been found for the three runtime-probed names.
- 2026-06-17 B002 static-logo retained-helper sync:
  - What changed: added [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) as a second binary confirmation for the static `.LGO` image/palette layout.
  - Summary/evidence: B002's source-quality audit verified the retained helper reads the same compressed-image and palette blobs as the constructor, updates the embedded `EPFTileContext` and `DLPalette`, and remains source-placed under [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md). Score unchanged because media payload provenance is still unresolved.
- 2026-06-20 B003 object-pane segment-advance sync:
  - Score unchanged at `87/94`.
  - Summary/evidence: [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) now records first-draft C++ and resolves the caller-supplied segmented payload names `m_movieData`, `m_firstSegmentSize`, and `m_hasRequestedSegmentAdvance`; this page now contrasts the object-pane fixed `FrameNum < 100` skip cutoff with the standalone half-total-frame restart path. Payload provenance remains the score-limiting blocker, so metadata is unchanged.
