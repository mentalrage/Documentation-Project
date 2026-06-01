*** UID:0000K4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ImageWriters

## Status

- Confidence: strong for JPEG wrapper behavior and PNG dependency split; medium for exact final module name and JPEG path reachability.
- Proposed module: `render/ImageWriters.cpp`
- Current recovered source caveat: `source-3/simroot_v2/recovered/WriteRGBA8PNGFile_00443E40.cpp` exists, but later source comparison identifies `0x00443e40` as stock `lodepng_encode32_file`, not NexusTK-owned `ImageWriters.cpp` code. The JPEG writer at `0x004efbc0` is IDA-backed and not currently materialized as a named generated file.
- Primary consumer: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Backend codec owner: [UID:0000KW][LodePNG](by-file/LodePNG.md)
- Evidence basis: generated recovered source plus read-only IDA MCP lookup/caller/callee checks on 2026-05-24 and 2026-05-25. `wave3.py` was not executed for this pass.

## File Role

`ImageWriters.cpp` is the current source-structure candidate for project-facing image file output helpers that are not stock third-party APIs. Earlier notes placed the PNG fixed-format helper here, but comparison against the obtained LodePNG `20160501` source now maps `0x00443db0` to `lodepng_encode_file` and `0x00443e40` to `lodepng_encode32_file`. Those PNG functions should be owned by [UID:0000KW][LodePNG](by-file/LodePNG.md), with [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) depending on the vendored library directly or through whatever original include boundary existed.

A second writer wrapper at `0x004efbc0` writes JPEG from a 16-bit source surface through the bundled [UID:0000KN][LibJPEG](by-file/LibJPEG.md) encoder path. Its only current code xref is from an unmodeled [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md), so treat it as retained or legacy screenshot output until reachability is resolved.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `lodepng_encode_file` | `0x00443db0-0x00443e32` | Excluded from this file; stock LodePNG public disk encode API. |
| `lodepng_encode32_file` | `0x00443e40-0x00443e5d` | Excluded from this file; stock LodePNG public RGBA8 disk encode API used by PNG screenshot capture. |
| `WriteJpegFileFromRgb565Surface` and local JPEG callbacks | `0x004efbc0-0x004efe94` | Converts a 16-bit surface to temporary RGB rows, writes JPEG scanlines through IJG libjpeg, and owns the adjacent writer-local JPEG error/destination callback support island. |

## Evidence

- IDA MCP confirms `0x00443e40` as a `0x1d` function and `0x00443db0` as a `0x82` function.
- IDA callers show `0x00443e40` has one direct caller: `SaveScreenshotPNG` at `0x00557e80`.
- IDA callees show `0x00443e40` only forwards to `0x00443db0`.
- IDA callees show `0x00443db0` uses `fopen`, `fwrite`, `fclose`, `free`, and the LodePNG encode front end at `0x00443c80`.
- Obtained-source comparison identifies those two PNG functions as stock LodePNG `lodepng_encode_file` and `lodepng_encode32_file`, so their generated recovered file is a staging artifact rather than original project ownership evidence.
- IDA strings around the backend include `LodePNG`, LodePNG RTTI strings, PNG error text, and `LodePNGEncoderSettings.filter_strategy`.
- IDA xrefs on 2026-05-25 show `WriteJpegFileFromRgb565Surface` is called from raw code at `0x005579d3` inside the unmodeled JPG screenshot path.
- 2026-05-26 IDA MCP recheck reconfirmed `0x004efbc0` size `0x222`, no modeled callers, and the same raw xref at `0x005579d3`.
- 2026-05-28 IDA MCP recheck shows the adjacent `0x004efdf0-0x004efe94` JPEG callback/null-stub island belongs with the writer wrapper: `sub_4EFBC0` assigns the error callback at `0x004efc0d`, and raw destination callback bodies appear at `0x004efe00` and `0x004efe40`.
- IDA callees for `0x004efbc0` show IJG compression helpers in the `0x00401000-0x00414283` library island plus a temporary heap allocation/free for 24-bit RGB rows.

## Ownership Decision

Keep this as render/image output support, not as screenshot feature code. [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns when and why screenshots are written; the PNG writer functions at `0x00443db0` and `0x00443e40` now belong to vendored [UID:0000KW][LodePNG](by-file/LodePNG.md), not this file.

Do not absorb the LodePNG encoder body or its public disk wrappers into `ImageWriters.cpp`. The state class, encode core, public encode/file helpers, and anonymous `0x0044xxxx` helper cluster belong with bundled [UID:0000KW][LodePNG](by-file/LodePNG.md) source.

Likewise, do not absorb IJG libjpeg internals into `ImageWriters.cpp`. The JPEG writer wrapper belongs here; the library implementation remains [UID:0000KN][LibJPEG](by-file/LibJPEG.md), and the screenshot hotkey/save workflow remains [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).

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

### 2026-05-28 - Expanded JPEG writer ownership range

- What existed before: `ImageWriters` listed only `0x004efbc0-0x004efde1` for `WriteJpegFileFromRgb565Surface`.
- What changed: the proposed contents now list `0x004efbc0-0x004efe94` for the writer and adjacent local JPEG callback support island.
- Evidence: IDA MCP shows the main writer ends at `0x004efde2`, assigns `sub_4EFE70` as its error callback, and is followed by writer-local destination/error callback bodies before `KeySpeedMgr` starts at `0x004efea0`.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: PNG/LodePNG exclusion, JPEG writer wrapper behavior, screenshot consumer, callback island, LibJPEG dependency, and ownership decisions are documented; confidence is capped by exact final module name and JPEG path reachability.
