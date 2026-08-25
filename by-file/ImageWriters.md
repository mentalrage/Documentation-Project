*** UID:0000K4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ImageWriters

## Status

- Confidence: very strong for JPEG wrapper behavior, PNG dependency split, retained source-manager callback/static-data ownership, definition-before-use order, and `render/ImageWriters.cpp` placement; exact original filename spelling remains inferred rather than symbol-proven.
- Proposed module: `render/ImageWriters.cpp`
- Projected reconstruction path: `NexusTK/render/ImageWriters.cpp`
- Recovered source caveat: `WriteRGBA8PNGFile_00443E40.cpp` exists, but source comparison identifies `0x00443e40` as stock `lodepng_encode32_file`, not NexusTK-owned `ImageWriters.cpp` code. The JPEG wrapper at `0x004efbc0` and its source-manager/error support island are binary-backed product code; `ImageWriters.cpp` is the best inferred human source file even though its original name is not preserved.
- Primary consumer: [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Backend codec owner: [UID:0000KW][LodePNG](by-file/LodePNG.md)
- Evidence basis: live IDA MCP lookup/caller/callee/byte/pointer-route checks through UID0002ZL session `b3b2bf88`, exact ImageWriters/ImageLoaders callback-family comparison, libjpeg 6b structure layout, current by-* ownership, and source comparison against obtained LodePNG code.

## File Role

`ImageWriters.cpp` is the current source-structure candidate for project-facing image file output helpers that are not stock third-party APIs. Earlier notes placed the PNG fixed-format helper here, but comparison against the obtained LodePNG `20160501` source now maps `0x00443db0` to `lodepng_encode_file` and `0x00443e40` to `lodepng_encode32_file`. Those PNG functions should be owned by [UID:0000KW][LodePNG](by-file/LodePNG.md), with [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) depending on the vendored library directly or through whatever original include boundary existed.

A second writer wrapper at `0x004efbc0` writes JPEG from a 16-bit source surface through the bundled [UID:0000KN][LibJPEG](by-file/LibJPEG.md) encoder path. Its only code xref is from the complete but unmodeled [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md), so the path is retained/legacy screenshot output rather than an unresolved source-placement blocker.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `lodepng_encode_file` | `0x00443db0-0x00443e32` | Excluded from this file; stock LodePNG public disk encode API. |
| `lodepng_encode32_file` | `0x00443e40-0x00443e5d` | Excluded from this file; stock LodePNG public RGBA8 disk encode API used by PNG screenshot capture. |
| `WriteJpegFileFromRgb565Surface` and local JPEG callbacks | `0x004efbc0-0x004efe94` | Converts a 16-bit surface to temporary RGB rows, writes JPEG scanlines through IJG libjpeg, and owns the adjacent retained memory-source and live error-callback support island. |
| `s_jpegEoiMarker` | [UID:0002ZG][JpegScreenshotEoiMarker](by-global/JpegScreenshotEoiMarker.md), [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md) | Mutable file-static `JOCTET[2]` `FF D9` fallback used by retained `JpegMemorySourceFill` after its saved input has been supplied. |

## Evidence

- IDA MCP confirms `0x00443e40` as a `0x1d` function and `0x00443db0` as a `0x82` function.
- IDA callers show `0x00443e40` has one direct caller: `SaveScreenshotPNG` at `0x00557e80`.
- IDA callees show `0x00443e40` only forwards to `0x00443db0`.
- IDA callees show `0x00443db0` uses `fopen`, `fwrite`, `fclose`, `free`, and the LodePNG encode front end at `0x00443c80`.
- Obtained-source comparison identifies those two PNG functions as stock LodePNG `lodepng_encode_file` and `lodepng_encode32_file`, so their recovered file is a staging artifact rather than original project ownership evidence.
- IDA strings around the backend include `LodePNG`, LodePNG RTTI strings, PNG error text, and `LodePNGEncoderSettings.filter_strategy`.
- IDA xrefs on 2026-05-25 show `WriteJpegFileFromRgb565Surface` is called from raw code at `0x005579d3` inside the unmodeled JPG screenshot path.
- 2026-05-26 IDA MCP recheck reconfirmed `0x004efbc0` size `0x222`, no modeled callers, and the same raw xref at `0x005579d3`.
- 2026-05-28 IDA MCP recheck shows the adjacent `0x004efdf0-0x004efe94` JPEG callback/null-stub island belongs with the writer wrapper: `sub_4EFBC0` assigns the error callback at `0x004efc0d`, and complete raw helper bodies appear at `0x004efe00` and `0x004efe40`. The then-current destination interpretation is historical and corrected below.
- IDA callees for `0x004efbc0` show IJG compression helpers in the `0x00401000-0x00414283` library island plus a temporary heap allocation/free for 24-bit RGB rows.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, `sub_4EFBC0` at `0x004efbc0` size `0x222`, no modeled callers, the raw code xref to the writer at `0x005579d3`, and the `0x0066db40` data xref at `0x004efe22` from the writer-local raw callback. A byte read of `0x0066db3c-0x0066db4c` returned `ff d9 00 00 ff d9 01 00 84 e4 61 00 f0 e6 61 00`, proving the screenshot fallback marker is the second `FF D9` pair and not the image-decode marker or startup-logo flag.
- 2026-06-16 A001 live IDA MCP recheck reconfirmed `0x00443db0` size `0x82`, `0x00443e40` size `0x1d`, `0x00443c80` size `0xe1`, `0x004efbc0` size `0x222`, `nullsub_36` at `0x004efdf0`, `sub_4EFE70` size `0x24`, and no IDA functions at raw support starts `0x004efe00`/`0x004efe40` or screenshot JPG raw start `0x00557840`.
- The same 2026-06-16 xref pass found `0x00443e40` called once from `SaveScreenshotPNG` at `0x0055817b`, `0x00443db0` referenced from `0x00443e53` and raw `0x00443e73`, `0x004efbc0` referenced only from raw `0x005579d3`, `0x0066db40` referenced only from raw callback `0x004efe22`, and `0x004efe70` assigned by the writer at `0x004efc0d`.
- 2026-06-16 byte reads reconfirmed the JPG raw body prologue at `0x00557840`, the raw call sequence around `0x005579d3`, the helper body at `0x004efe00`, and fallback marker bytes at `0x0066db3c-0x0066db4c`. Current libjpeg layout and duplicate-family proof identify that helper as source-manager `fill_input_buffer`.

## UID0002ZL Source-Manager And Marker Resolution

### Translation-Unit Contents

- [UID:0002ZG][JpegScreenshotEoiMarker](by-global/JpegScreenshotEoiMarker.md) emits the common C/libjpeg include prologue and `static JOCTET s_jpegEoiMarker[2] = { 0xff, JPEG_EOI };` at emitter position `0`.
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) emits `JpegScreenshotErrorManager`, `JpegMemorySourceManager`, declarations and bodies for init/fill/skip/term/error callbacks, and `WriteJpegFileFromRgb565Surface`.
- The exact storage page [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md) emits only a covered-by trace comment so the two bytes have one source definition.
- No public header declaration is emitted. Both the marker and callbacks have internal linkage, and no header, exported alias, cross-file pointer route, or public API use was found.

### Exact Source-Manager Semantics

- `jpeg_decompress_struct +0x18` is `src`. Manager offsets `+0/+4` are `next_input_byte/bytes_in_buffer`; extended fields `+0x1c/+0x20` save the source pointer/count; byte field `+0x24` records whether that source has been loaded.
- `0x004efe00-0x004efe35` publishes the saved input on first fill, then points to `s_jpegEoiMarker` with count `2` on later fill and returns `TRUE`.
- `0x004efe40-0x004efe57` implements signed-positive `skip_input_data`. The one-byte bodies at `0x004efdf0` and `0x004efe60` are no-op `init_source` and `term_source` hooks.
- ImageWriters range `0x004efdf0-0x004efe61` is byte-identical for 113 bytes to active ImageLoaders callbacks `0x004e4e60-0x004e4ed1` except for the file-local marker operand.
- Active ImageLoaders initializer `0x004e7030` installs init/fill/skip/term in source-manager slots `+8/+0x0c/+0x10/+0x18`, places IJG `jpeg_resync_to_restart` at `+0x14`, and is reached by callers `0x004d0869` and `0x004d0b21`. This independently proves the retained ImageWriters helper roles.
- The older destination-manager, external const array, and `const_cast` model is disproven. It is retained only as explicitly historical context in earlier entries, not as active source guidance.

### Liveness, Routes, And Placement

- The retained source-helper starts have no inbound xrefs and no absolute-VA, RVA, or raw-offset pointer routes. Complete bodies and the exact live duplicate prove source semantics despite dead/retained linkage.
- The main writer's only code xref is the direct call at `0x005579d3` inside raw [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md). That range has no modeled function/xref/pointer route to its entry, but bounded bytes form a complete screenshot JPG source body. It is retained/legacy workflow evidence, not a pending investigation.
- The marker has exactly one data xref at `0x004efe22`; its second byte has no xref; no alternate VA/RVA/raw-offset route exists. Adjacent ImageLoaders marker and startup-logo flag have independent owners and references.
- The writer, retained source callbacks, error exit, and marker are one contiguous/related product-side image-output cluster over public libjpeg interfaces. This supports `render/ImageWriters.cpp` over `ScreenshotCapture.cpp`, `LibJPEG`, `ImageLoaders`, or a speculative standalone `JpegScreenshotWriter.cpp`.
- PNG public wrappers remain stock LodePNG and excluded. IJG internals remain under LibJPEG. Screenshot workflow policy remains under ScreenshotCapture.

### Source Ordering And Style

1. Shared implementation includes.
2. File-static `s_jpegEoiMarker` definition.
3. Private error/source-manager structs and helper declarations.
4. `WriteJpegFileFromRgb565Surface` and private callback bodies in range-backed order.

The source-facing names are descriptive high-probability reconstructions consistent with the project's human mid-2000s C++ style. No compiler-generated `sub_`, `nullsub_`, `unk_`, or address-bearing name enters formal source.

## Ownership Decision

Keep this as render/image output support, not as screenshot feature code. [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns when and why screenshots are written; the PNG writer functions at `0x00443db0` and `0x00443e40` now belong to vendored [UID:0000KW][LodePNG](by-file/LodePNG.md), not this file.

Do not absorb the LodePNG encoder body or its public disk wrappers into `ImageWriters.cpp`. The state class, encode core, public encode/file helpers, and anonymous `0x0044xxxx` helper cluster belong with bundled [UID:0000KW][LodePNG](by-file/LodePNG.md) source.

Likewise, do not absorb IJG libjpeg internals into `ImageWriters.cpp`. The JPEG writer wrapper belongs here; the library implementation remains [UID:0000KN][LibJPEG](by-file/LibJPEG.md), and the screenshot hotkey/save workflow remains [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).

## Source Split Cross-Check

[UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) has an explicit `render/ImageWriters.cpp` and `render/ScreenshotCapture.cpp` split. It assigns [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) to this file as project-owned JPEG output wrapper code, assigns JPG/BMP/PNG capture workflows to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), and assigns PNG public APIs at `0x00443db0`/`0x00443e40` to [UID:0000KW][LodePNG](by-file/LodePNG.md). Current callback-family and retained-path analysis resolves the behavioral/placement questions; only the exact historical filename spelling remains inferred.

Historical 2026-06-16 notes treated raw JPG liveness as unresolved because [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) is not an IDA function and has no modeled caller. The UID0002ZL pass exhaustively checked entry xrefs and VA/RVA/raw-offset routes, confirmed the complete bounded body and exact writer call, and classifies it as retained/legacy source. That resolves the blocker without moving the JPEG wrapper into [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md); caller/workflow ownership and writer/helper ownership remain separate.

## Score Rationale

| Dimension | Score | Rationale |
| --- | --- | --- |
| Completion | `90` | Project/third-party split, JPEG wrapper and source-manager contents, marker definition, emitter order, CPP/H disposition, callback semantics, active duplicate, route negatives, retained workflow, file placement, and source style are documented across the full file aggregate. |
| Confidence | `92` | Binary behavior and ownership are strongly corroborated by exact bytes, xrefs, libjpeg layout, active duplicate/table evidence, and current source-tree grouping. The original translation-unit filename is not symbol-proven, so confidence remains below final-audit levels. |

## Cross-References

- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-01 B002 UID0002ZL implementation callback:
  - Raised `87/86 -> 90/92`; preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"` and `CANONICAL_OWNER:FILE`.
  - Incorporated the complete ImageWriters-side JPEG marker/source-manager resolution: mutable file-static marker, definition-before-use position, exact fill/skip/init/term semantics, byte-identical active duplicate and initializer slots, retained-helper and raw-workflow route negatives, no-header/no-external-route proof, and high-probability `ImageWriters.cpp` placement.
  - Preserved the existing PNG/LodePNG exclusion, IJG library boundary, ScreenshotCapture workflow split, JPEG writer behavior, caller/callee evidence, RGB conversion, error callback, range, and ownership history.
  - Historicalized the earlier destination-manager and unresolved-liveness assumptions; they no longer direct active reconstruction.

- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Historical summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed PNG wrapper sizes and one PNG caller, `0x004efbc0` as the project JPEG writer size `0x222`, raw helper boundaries, writer-local `0x004efe70` assignment, the single raw writer xref at `0x005579d3`, and fallback marker bytes at `0x0066db40`. That pass retained raw JPG liveness/original file naming as blockers; current UID0002ZL evidence resolves liveness and callback semantics while retaining only inferred filename spelling.
- 2026-06-07 A010 Batch077 parent-route repair:
  - What existed before: confidence was `82`, and [UID:0002ZG][JpegScreenshotEoiMarker](by-global/JpegScreenshotEoiMarker.md) could not be routed upward for generated coverage because this direct source-file parent did not clear the corrected `85/85` gate.
  - Changed to: confidence `85`; completion remains `86`.
  - Summary/evidence: live IDA reconfirmed the project-owned JPEG writer wrapper anchor at `0x004efbc0`, the raw callback fallback xref to `0x0066db40`, and the exact adjacent bytes separating the image-decode marker, screenshot marker, startup-logo flag, and staff-resource pointer. This is enough to route the writer-local marker global to `ImageWriters.cpp`; remaining uncertainty about exact original filename and legacy JPG path reachability still keeps the score below final-audit levels.

- 2026-06-07 A003 source-split cross-check:
  - What existed before: confidence was `78`, with strong local JPEG/PNG evidence but the status still capped confidence on exact module name and JPEG path reachability.
  - Changed to: confidence `82`, with a new source-split cross-check tying `ImageWriters.cpp` to only the project JPEG wrapper while excluding LodePNG public PNG APIs and ScreenshotCapture workflow code.
  - Historical summary/evidence: existing docs agreed that [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) is NexusTK-owned wrapper code over [UID:0000KN][LibJPEG](by-file/LibJPEG.md), [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md) is third-party LodePNG, and [UID:0001G8][0x00557840-0x00557a96.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a96.ScreenshotJpegCapturePath.md) remained ScreenshotCapture-owned with then-unresolved liveness. The current pass supersedes only that liveness status.

- 2026-06-05: Assigned projected reconstruction path `NexusTK/render/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree place `ImageWriters.cpp` under `render/`.
  - After: set the validator path to `NexusTK/render/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ImageWriters.cpp` under `render`, and live IDA MCP lookup on 2026-06-05 confirms the project-owned JPEG writer anchor at `0x004efbc0` as a real function of size `0x222`.

### 2026-05-28 - Expanded JPEG writer ownership range

- What existed before: `ImageWriters` listed only `0x004efbc0-0x004efde1` for `WriteJpegFileFromRgb565Surface`.
- What changed: the proposed contents now list `0x004efbc0-0x004efe94` for the writer and adjacent local JPEG callback support island.
- Historical evidence: IDA MCP shows the main writer ends at `0x004efde2`, assigns `sub_4EFE70` as its error callback, and is followed by writer-local helper/error bodies before `KeySpeedMgr` starts at `0x004efea0`. The current pass identifies those helpers as source-manager callbacks.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: PNG/LodePNG exclusion, JPEG writer wrapper behavior, screenshot consumer, callback island, LibJPEG dependency, and ownership decisions are documented; confidence is capped by exact final module name and JPEG path reachability.
