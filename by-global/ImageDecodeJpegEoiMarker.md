*** UID:0002ZF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned char s_jpegEoiMarker[2] = { 0xff, 0xd9 };
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ImageDecodeJpegEoiMarker

## Status

- Address: `0x0066db3c`
- Exact storage: `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`.
- Current IDA name: `unk_66DB3C`.
- Kind: two-byte JPEG End-Of-Image fallback marker plus adjacent slot padding.
- Source owner: image decode/JPEG loader callback support in [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
- Rebuild handling: source-declared static marker data.
- Assignment: this page is `90/93` and the direct file parent [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) is `93/90` after the B009 ImageLoaders empty-emitter implementation, so the corrected `85/85` gate is satisfied.

## Role

The image-decode source-manager callback at `0x004e4e70-0x004e4ea5` returns this `FF D9` marker as a two-byte fallback buffer. The callback writes the marker address and length `2` into its output record before returning success. The accepted source declaration is mutable file-static storage because the callback path writes the marker pointer through a mutable output record and the bytes live in writable initialized data.

## Evidence

- 2026-06-07 A007 IDA MCP reads `ff d9 00 00` at `0x0066db3c-0x0066db40`.
- `xrefs_to 0x0066db3c` reports one reference at `0x004e4e92`.
- The instruction window at `0x004e4e92` stores `offset unk_66DB3C`, stores count `2`, and returns success.
- Byte-level xref scanning shows no direct xrefs to `0x0066db3e` or `0x0066db3f`.
- 2026-06-08 A007 IDA MCP reads `ff d9 00 00 ff d9 01 00` at `0x0066db3c-0x0066db44`, reconfirming this marker's split from the screenshot marker at `0x0066db40` and the startup-logo flag at `0x0066db42`.
- `lookup_funcs 0x004e4e70` reports `sub_4E4E70`, range `0x004e4e70-0x004e4ea5`. Its decompile shows the callback normally returns the caller's source buffer, but when the source state flag is already set it writes `&unk_66DB3C` and length `2` into the output record.
- `xrefs_to 0x004e4e70` reports a data reference at `0x004e7075` inside `0x004e7030`, the decode callback-record initializer documented by [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md).
- Neighbor checks keep ownership separate: `0x0066db40` is referenced by screenshot-writer callback code, while `0x0066db42` is referenced by startup-logo Bink restart code.

## Source Ownership

This marker is product-owned callback support around JPEG decoding, not stock libjpeg data and not the screenshot writer's separate marker. Batch 130 ties the callback record setup at `0x004e7030`, the callback body at `0x004e4e70`, and the exact marker slot at `0x0066db3c` to the project-facing decode wrapper family, so [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) is the direct source owner. [UID:0000KN][LibJPEG](by-file/LibJPEG.md) remains the owner for IJG internals, not for this application-side fallback marker.

The exact by-memory child [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) uses [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) as its validator parent. This by-global page remains the semantic/evidence anchor for the named static marker.

## Score Rationale

- Completion is raised from `88` to `90` because the page now records the callback-record initializer xref, the current decompile behavior of the marker-return callback, explicit neighboring-marker separation, direct ImageLoaders parent assignment, and first-draft file-static source declaration.
- Confidence is raised from `92` to `93` because live IDA evidence links the marker, callback body, decode callback table setup, and mutable storage route without relying on the older broad-owner caveat.
- Remaining score limit: the exact original static name is inferred as `s_jpegEoiMarker`, although the mutable `static unsigned char[2]` source shape is supported by the writable initialized slot and callback pointer use.

## Cross-References

- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)

## Changes

- 2026-07-01 B009 ImageLoaders empty-emitter implementation:
  - Changed score from `88/92` to `90/93`.
  - Changed formal C++ from blank to `static unsigned char s_jpegEoiMarker[2] = { 0xff, 0xd9 };`.
  - Summary/evidence: accepted B009 report used live MCP `get_bytes` for `0x0066db3c` (`ff d9 00 00`), decompilation of `0x004e4e70` showing the exhausted source-manager path writes the marker pointer and length `2`, and `0x004e7030` setup evidence. The exact slot page [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) now carries a covered-by comment so the marker is declared only once.

- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split image-decode JPEG EOI marker after live IDA confirmed the marker bytes and single callback xref.
- 2026-06-07 A007 Batch 076 coverage-error repair: documented that [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) must remain autogen-unassigned while generated memory coverage rejects by-global parent UIDs. This page remains the exact semantic/evidence anchor at `86/90`.
- 2026-06-08 A007 Batch 130 parent/source refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`, with `AUTOGEN_PARENT_UID:0000K3`.
  - Summary/evidence: live IDA MCP reconfirmed the marker bytes, the `0x004e4e70` fallback callback behavior, the callback-record initializer reference at `0x004e7075`, and the neighboring screenshot/startup-logo split. The direct source parent [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) now clears the `85/85` gate.
