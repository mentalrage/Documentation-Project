*** UID:0002ZG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# JpegScreenshotEoiMarker

## Status

- Address: `0x0066db40`
- Exact storage: `by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md`.
- Current IDA name: `unk_66DB40`.
- Kind: two-byte JPEG End-Of-Image fallback marker.
- Proposed source owner: [UID:0000K4][ImageWriters](by-file/ImageWriters.md), specifically the writer-local support data for [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md).
- Rebuild handling: source-declared static marker data.

## Role

The screenshot JPEG destination callback at raw body `0x004efe00-0x004efe35` uses this `FF D9` marker as a two-byte fallback buffer.

## Evidence

- 2026-06-07 A007 IDA MCP reads `ff d9` at `0x0066db40`.
- `xrefs_to 0x0066db40` reports one reference at `0x004efe22`.
- The instruction window at `0x004efe22` stores `offset unk_66DB40`, stores count `2`, writes those fields into the destination manager record, and returns success.
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) already documents the raw callback as writer-local support.

## Source Ownership

This marker belongs to the NexusTK-owned screenshot JPEG writer wrapper, not the statically linked IJG library and not the image-decode marker at `0x0066db3c`.

## Assignment Gate

- `AUTOGEN_PARENT_UID` is set to [UID:0000K4][ImageWriters](by-file/ImageWriters.md).
- This by-global parent is `86/91`, and the direct source-file parent is now `86/85`, so both sides clear the corrected `85/85` assignment gate.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed the writer anchor at `0x004efbc0`, the raw code xref to it at `0x005579d3`, the marker data xref at `0x004efe22`, and byte-level separation from the neighboring image-decode marker and startup-logo flag.

## Cross-References

- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)

## Changes

- 2026-06-07 A010 Batch077: Set `AUTOGEN_PARENT_UID:0000K4` after refreshing [UID:0000K4][ImageWriters](by-file/ImageWriters.md) to `86/85`. This repairs generated coverage for memory child [UID:0002ZL][0x0066db40-0x0066db42.JpegScreenshotEoiMarker](by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md) without changing this page's `86/91` score.
- 2026-06-07 A007 Batch 052: Created exact by-global parent for the split screenshot JPEG EOI marker after live IDA confirmed the marker bytes and writer-local callback xref.
