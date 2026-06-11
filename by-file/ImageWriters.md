*** UID:0000K4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ImageWriters

## Status

- Confidence: strong for JPEG wrapper behavior, PNG dependency split, writer-local callback/static-data ownership, and current source-tree placement; medium for exact original file name and JPEG path reachability.
- Proposed module: `render/ImageWriters.cpp`
- Projected reconstruction path: `NexusTK/render/ImageWriters.cpp`
- Recovered source caveat: `WriteRGBA8PNGFile_00443E40.cpp` exists, but later source comparison identifies `0x00443e40` as stock `lodepng_encode32_file`, not NexusTK-owned `ImageWriters.cpp` code. The JPEG writer at `0x004efbc0` is IDA-backed and not currently materialized as a named source file.
- Primary consumer: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Backend codec owner: [UID:0000KW][LodePNG](by-file/LodePNG.md)
- Evidence basis: live IDA MCP lookup/caller/callee checks on 2026-05-24 and 2026-05-25 plus source comparison against obtained LodePNG code.

## File Role

`ImageWriters.cpp` is the current source-structure candidate for project-facing image file output helpers that are not stock third-party APIs. Earlier notes placed the PNG fixed-format helper here, but comparison against the obtained LodePNG `20160501` source now maps `0x00443db0` to `lodepng_encode_file` and `0x00443e40` to `lodepng_encode32_file`. Those PNG functions should be owned by [UID:0000KW][LodePNG](by-file/LodePNG.md), with [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) depending on the vendored library directly or through whatever original include boundary existed.

A second writer wrapper at `0x004efbc0` writes JPEG from a 16-bit source surface through the bundled [UID:0000KN][LibJPEG](by-file/LibJPEG.md) encoder path. Its only current code xref is from an unmodeled [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md), so treat it as retained or legacy screenshot output until reachability is resolved.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `lodepng_encode_file` | `0x00443db0-0x00443e32` | Excluded from this file; stock LodePNG public disk encode API. |
| `lodepng_encode32_file` | `0x00443e40-0x00443e5d` | Excluded from this file; stock LodePNG public RGBA8 disk encode API used by PNG screenshot capture. |
| `WriteJpegFileFromRgb565Surface` and local JPEG callbacks | `0x004efbc0-0x004efe94` | Converts a 16-bit surface to temporary RGB rows, writes JPEG scanlines through IJG libjpeg, and owns the adjacent writer-local JPEG error/destination callback support island. |
| `JpegScreenshotEoiMarker` | [UID:0002ZG][JpegScreenshotEoiMarker](by-global/JpegScreenshotEoiMarker.md), [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md) | Two-byte `FF D9` fallback marker used only by the writer-local raw destination callback at `0x004efe00-0x004efe35`. |

## Evidence

- IDA MCP confirms `0x00443e40` as a `0x1d` function and `0x00443db0` as a `0x82` function.
- IDA callers show `0x00443e40` has one direct caller: `SaveScreenshotPNG` at `0x00557e80`.
- IDA callees show `0x00443e40` only forwards to `0x00443db0`.
- IDA callees show `0x00443db0` uses `fopen`, `fwrite`, `fclose`, `free`, and the LodePNG encode front end at `0x00443c80`.
- Obtained-source comparison identifies those two PNG functions as stock LodePNG `lodepng_encode_file` and `lodepng_encode32_file`, so their recovered file is a staging artifact rather than original project ownership evidence.
- IDA strings around the backend include `LodePNG`, LodePNG RTTI strings, PNG error text, and `LodePNGEncoderSettings.filter_strategy`.
- IDA xrefs on 2026-05-25 show `WriteJpegFileFromRgb565Surface` is called from raw code at `0x005579d3` inside the unmodeled JPG screenshot path.
- 2026-05-26 IDA MCP recheck reconfirmed `0x004efbc0` size `0x222`, no modeled callers, and the same raw xref at `0x005579d3`.
- 2026-05-28 IDA MCP recheck shows the adjacent `0x004efdf0-0x004efe94` JPEG callback/null-stub island belongs with the writer wrapper: `sub_4EFBC0` assigns the error callback at `0x004efc0d`, and raw destination callback bodies appear at `0x004efe00` and `0x004efe40`.
- IDA callees for `0x004efbc0` show IJG compression helpers in the `0x00401000-0x00414283` library island plus a temporary heap allocation/free for 24-bit RGB rows.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, `sub_4EFBC0` at `0x004efbc0` size `0x222`, no modeled callers, the raw code xref to the writer at `0x005579d3`, and the `0x0066db40` data xref at `0x004efe22` from the writer-local raw callback. A byte read of `0x0066db3c-0x0066db4c` returned `ff d9 00 00 ff d9 01 00 84 e4 61 00 f0 e6 61 00`, proving the screenshot fallback marker is the second `FF D9` pair and not the image-decode marker or startup-logo flag.

## Ownership Decision

Keep this as render/image output support, not as screenshot feature code. [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns when and why screenshots are written; the PNG writer functions at `0x00443db0` and `0x00443e40` now belong to vendored [UID:0000KW][LodePNG](by-file/LodePNG.md), not this file.

Do not absorb the LodePNG encoder body or its public disk wrappers into `ImageWriters.cpp`. The state class, encode core, public encode/file helpers, and anonymous `0x0044xxxx` helper cluster belong with bundled [UID:0000KW][LodePNG](by-file/LodePNG.md) source.

Likewise, do not absorb IJG libjpeg internals into `ImageWriters.cpp`. The JPEG writer wrapper belongs here; the library implementation remains [UID:0000KN][LibJPEG](by-file/LibJPEG.md), and the screenshot hotkey/save workflow remains [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).

## Source Split Cross-Check

[UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) now has an explicit `render/ImageWriters.cpp` and `render/ScreenshotCapture.cpp` split. That source-tree section assigns [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) to this file as project-owned JPEG output wrapper code, assigns the JPG/BMP/PNG capture workflows to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), and assigns the PNG public APIs at `0x00443db0`/`0x00443e40` to [UID:0000KW][LodePNG](by-file/LodePNG.md). This removes most of the earlier module-boundary ambiguity while leaving the original source file name and raw JPG reachability as open questions.

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-07 A010 Batch077 parent-route repair:
  - What existed before: confidence was `82`, and [UID:0002ZG][JpegScreenshotEoiMarker](by-global/JpegScreenshotEoiMarker.md) could not be routed upward for generated coverage because this direct source-file parent did not clear the corrected `85/85` gate.
  - Changed to: confidence `85`; completion remains `86`.
  - Summary/evidence: live IDA reconfirmed the project-owned JPEG writer wrapper anchor at `0x004efbc0`, the raw callback fallback xref to `0x0066db40`, and the exact adjacent bytes separating the image-decode marker, screenshot marker, startup-logo flag, and staff-resource pointer. This is enough to route the writer-local marker global to `ImageWriters.cpp`; remaining uncertainty about exact original filename and legacy JPG path reachability still keeps the score below final-audit levels.

- 2026-06-07 A003 source-split cross-check:
  - What existed before: confidence was `78`, with strong local JPEG/PNG evidence but the status still capped confidence on exact module name and JPEG path reachability.
  - Changed to: confidence `82`, with a new source-split cross-check tying `ImageWriters.cpp` to only the project JPEG wrapper while excluding LodePNG public PNG APIs and ScreenshotCapture workflow code.
  - Summary/evidence: existing docs now agree that [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) is NexusTK-owned wrapper code over [UID:0000KN][LibJPEG](by-file/LibJPEG.md), [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md) is third-party LodePNG, and [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) remains ScreenshotCapture-owned with unresolved liveness. Completion stays `86` because no new live IDA reachability proof was added.

- 2026-06-05: Assigned projected reconstruction path `NexusTK/render/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree place `ImageWriters.cpp` under `render/`.
  - After: set the validator path to `NexusTK/render/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ImageWriters.cpp` under `render`, and live IDA MCP lookup on 2026-06-05 confirms the project-owned JPEG writer anchor at `0x004efbc0` as a real function of size `0x222`.

### 2026-05-28 - Expanded JPEG writer ownership range

- What existed before: `ImageWriters` listed only `0x004efbc0-0x004efde1` for `WriteJpegFileFromRgb565Surface`.
- What changed: the proposed contents now list `0x004efbc0-0x004efe94` for the writer and adjacent local JPEG callback support island.
- Evidence: IDA MCP shows the main writer ends at `0x004efde2`, assigns `sub_4EFE70` as its error callback, and is followed by writer-local destination/error callback bodies before `KeySpeedMgr` starts at `0x004efea0`.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: PNG/LodePNG exclusion, JPEG writer wrapper behavior, screenshot consumer, callback island, LibJPEG dependency, and ownership decisions are documented; confidence is capped by exact final module name and JPEG path reachability.
