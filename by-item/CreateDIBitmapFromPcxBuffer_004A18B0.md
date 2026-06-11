*** UID:0000U9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateDIBitmapFromPcxBuffer 0x004A18B0

## Status

- Confidence: strong for behavior and owner relationship.
- Entity kind: free image-loader helper.
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Autogen parent: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x004a18b0-0x004a1b0c`

## Behavior

`CreateDIBitmapFromPcxBuffer` decodes an 8-bit PCX buffer to temporary RGB565 pixels, allocates and constructs a `DIBitmap`, validates the DIB pixel pointer, copies each decoded row into the DIB section using the DIB's aligned stride, frees the temporary decode buffer, and returns the bitmap.

It returns null on decode failure, invalid dimensions, allocation failure, or DIB-section pixel failure.

IDA MCP confirms one direct caller, `LoadPcxImage` at `0x004a1876`, and a direct call to `DecodePcxToRgb565Buffer` at `0x004a18f5`.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and stale generated-source wording was removed.
  - Before: the PCX-to-DIB helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned image loader source under the validated ImageLoaders file root; C++ remains blank because final helper names and DIB/PCX type declarations are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4A18B0` at `0x004a18b0`, size `0x25c`, one direct caller from `sub_4A17B0`, and the direct PCX decoder callee at `0x00549410`.

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented PCX-to-DIB behavior, owner relationship, one caller, and decode helper link but remained unevaluated.
  - After: score reflects documented decode/allocation/validation/copy/free failure behavior and source placement.
  - Evidence: IDA notes confirm direct caller `LoadPcxImage`, direct call to [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md), and the linked DIBitmap/PCX loader memory range.
