*** UID:0002ZG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "jpeglib.h"

static JOCTET s_jpegEoiMarker[2] = { 0xff, JPEG_EOI };
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Mutable file-static ImageWriters JPEG memory-source EOI fallback array FF D9; one retained fill-input callback uses its base with count 2 after the saved source is exhausted, while an exact active ImageLoaders callback duplicate proves jpeg_source_mgr field semantics, translation-unit ownership, and definition-before-use placement. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# JpegScreenshotEoiMarker

## Summary

- Semantic object: the two-byte JPEG End-Of-Image fallback array at `0x0066db40-0x0066db42`.
- Exact storage owner: [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md).
- Source-file owner and emitter: [UID:0000K4][ImageWriters](by-file/ImageWriters.md).
- Sole ImageWriters consumer: the retained memory-source fill callback at `0x004efe00-0x004efe35` in [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md).
- Source disposition: one mutable file-static `JOCTET[2]` definition placed before the writer and source-manager helpers.

This semantic carrier emits the object once. The exact by-memory storage page emits only a covered-by trace comment, preventing duplicate definitions while preserving range accountability.

## Exact Storage And Type

- Bytes: `ff d9`, exactly two bytes in writable initialized `.data`.
- Address: VA `0x0066db40`, PE RVA `0x26db40`, raw offset `0x26b740`.
- Source declaration: `static JOCTET s_jpegEoiMarker[2] = { 0xff, JPEG_EOI };`.
- `JOCTET` and `JPEG_EOI` are public libjpeg 6b vocabulary; the array itself is NexusTK product-side wrapper data.
- The ordered bytes are not a packed `unsigned short`. The consumer loads the base address and literal byte count `2` independently.
- Writable `.data`, local-only use, and `jpeg_source_mgr::next_input_byte` being `const JOCTET *` support mutable storage without an emitted `const` qualifier or `const_cast`.

## Source-Manager Behavior

- `0x004efe00` obtains `cinfo->src` through `cinfo + 0x18`, identifying a decompressor `jpeg_source_mgr`, not a compressor `jpeg_destination_mgr`.
- On the first fill, manager fields `+0x1c/+0x20` supply the saved memory pointer/count to public fields `next_input_byte/bytes_in_buffer`; byte flag `+0x24` is then set.
- On a later fill, `0x004efe22` loads `0x0066db40`, `0x004efe27` loads count `2`, and the callback publishes this EOI fallback pair before returning `TRUE`.
- The companion helper at `0x004efe40` implements signed-positive `skip_input_data` adjustment of `next_input_byte` and `bytes_in_buffer`.
- Init and term callbacks are no-op source-manager hooks. The error callback at `0x004efe70` remains independently live through writer assignment `0x004efc0d`.

## Exact Callback-Family Proof

- The 113-byte ImageWriters helper family `0x004efdf0-0x004efe61` is byte-identical to active ImageLoaders source helpers `0x004e4e60-0x004e4ed1` except for the marker address (`0x0066db40` versus `0x0066db3c`).
- Active ImageLoaders initializer `0x004e7030` installs init/fill/skip/term at `jpeg_source_mgr` slots `+8/+0x0c/+0x10/+0x18`, with IJG `jpeg_resync_to_restart` at `+0x14`.
- The active duplicate therefore independently proves the retained ImageWriters family's source-manager role and public field interpretation.
- The ImageWriters local helper starts have no inbound xrefs and no VA/RVA/raw-offset pointer routes. They are retained or dead source bodies, not evidence for a different owner or destination-manager contract.

## Reference And Negative Evidence

- Live read-only IDA MCP session `b3b2bf88` found exactly one data xref to the base, from `0x004efe22`.
- The second byte at `0x0066db41` has no independent xref.
- Absolute VA bytes `40 db 66 00` occur only at the callback operand; no target RVA pattern `40 db 26 00` or raw-offset pattern `40 b7 26 00` occurs.
- The byte sequence `ff d9` has 30 matches and therefore cannot establish identity without the pointer route and callback semantics.
- No write to the array, exported alias, header reference, alternate pointer, or cross-translation-unit use was found.
- No evidence merges this storage with the predecessor ImageLoaders EOI slot at `0x0066db3c` or successor startup-logo flag at `0x0066db42`.

## Ownership And Placement

- [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md) owns the exact bytes but delegates emitted source to this semantic object.
- This object delegates final source-file assembly to [UID:0000K4][ImageWriters](by-file/ImageWriters.md), with emitter position `0` so includes and the file-static definition precede [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md).
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) owns the consuming function range and callback bodies, not data outside its address range.
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns the capture workflow and raw JPG path, not this source-manager object.
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md) owns bundled IJG implementation internals. This product wrapper only consumes its public API and types.
- ImageLoaders owns a separate active marker/callback copy. File-static spelling can be identical in the two translation units without shared storage or linkage collision.

## Formal Emission

- CPP contains the required C/libjpeg prologue followed by the exact file-static definition.
- H remains intentionally blank: an internal-linkage implementation object has no public declaration and no header route.
- There is no `extern const JOCTET JpegScreenshotEoiMarker[2]` declaration and no `const_cast`. Those forms would invent external linkage and compensate for an incorrect const model.
- No `third_party_embeds/...` import directive applies because the object is product-owned wrapper data rather than retained static third-party implementation code.

## Current IDA State And Supervisor Handoff

- IDA currently models `0x0066db40` and `0x0066db41` as separate one-byte items with no declaration/type; the first has auto-name `unk_66DB40`; regular/repeatable comments are blank.
- The accepted supervisor-owned action is to form one two-byte unsigned-char array, name it `s_jpegEoiMarker`, and attach the exact source-manager repeatable comment after deterministic prestate verification.
- B002 performs no IDA mutation in this ordinary implementation callback.

## Score Rationale

| Dimension | Score | Rationale |
| --- | --- | --- |
| Completion | `92` | Storage, declaration, source-manager behavior, sole route, active duplicate, negative routes, owner/emitter ordering, CPP definition, blank-H proof, and library boundary are incorporated. |
| Confidence | `94` | Binary storage and behavior are exact and independently proven by the active callback family. Only original source spelling is inferred, keeping the object below the final-audit `95+` threshold. |

## Historical Assumptions Corrected

- Batch052 and Batch077 correctly identified the bytes, sole reference, owner chain, and adjacent-storage split.
- Their destination-callback wording is historical and disproven. The `cinfo->src` offset, source-manager public fields, signed skip helper, active initializer table, and exact duplicate establish memory-source semantics.
- The earlier externally linked const-array/`const_cast` concept is likewise historical and disproven. The emitted model is one mutable file-static array consumed through a pointer-to-const field.

## Cross-References

- [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md)
- [UID:0002ZM][0x0066db42-0x0066db44.StartupLogoBinkRestartFlag](by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)

## Changes

- 2026-08-01 B002 UID0002ZL implementation callback: raised `86/91 -> 92/94`; added emitter position `0`, exact CPP prologue and mutable file-static marker definition, intentional blank-H proof, full memory-source behavior and duplicate-family evidence, sole-route negatives, source ownership/order, library boundary, score rationale, IDA handoff, and explicit historical corrections.
- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000K4` after refreshing [UID:0000K4][ImageWriters](by-file/ImageWriters.md) to `86/85`; retained the writer anchor, marker xref, and adjacent-byte separation.
- 2026-06-07 A007 Batch052: Created the exact by-global parent after live IDA confirmed marker bytes and the sole writer-local callback reference. Its destination-manager interpretation is superseded as documented above.
