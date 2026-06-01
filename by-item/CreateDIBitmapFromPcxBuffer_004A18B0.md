*** UID:0000U9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateDIBitmapFromPcxBuffer 0x004A18B0

## Status

- Confidence: strong for behavior and owner relationship.
- Entity kind: free image-loader helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/CreateDIBitmapFromPcxBuffer_004A18B0.cpp`
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
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

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented PCX-to-DIB behavior, owner relationship, one caller, and decode helper link but remained unevaluated.
  - After: score reflects documented decode/allocation/validation/copy/free failure behavior and source placement.
  - Evidence: IDA notes confirm direct caller `LoadPcxImage`, direct call to [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md), and the linked DIBitmap/PCX loader memory range.
