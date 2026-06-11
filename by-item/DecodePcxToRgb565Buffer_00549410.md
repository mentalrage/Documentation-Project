*** UID:0000UD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DecodePcxToRgb565Buffer 0x00549410

## Status

- Confidence: strong for PCX/RGB565 behavior, medium for final original file name.
- Entity kind: free image-codec helper.
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) or a small `render/PcxDecode.cpp`
- Autogen parent: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x00549410-0x00549616`

## Behavior

`DecodePcxToRgb565Buffer` validates an 8-bit PCX image with a 256-color palette footer, expands the RLE stream, maps palette indices when a caller supplies a remap table, converts RGB triples into RGB565, and writes transparent-index pixels as zero.

The function allocates the output pixel buffer and returns width/height to the caller. IDA MCP confirms its only direct caller is `CreateDIBitmapFromPcxBuffer` at `0x004a18f5`.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and stale generated-source wording was removed.
  - Before: the PCX decoder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned image codec source under the validated ImageLoaders file root; C++ remains blank because final decoder signature, PCX structs, and palette/remap names are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_549410` at `0x00549410`, size `0x206`, exactly one direct caller from `sub_4A18B0`, and no project callees beyond runtime support.

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented PCX/RGB565 decode behavior, caller, owner options, and cross-references but remained unevaluated.
  - After: score reflects documented validation, RLE expansion, palette remapping, RGB565 conversion, transparent-index handling, output allocation, and single caller.
  - Evidence: IDA notes confirm the exact range and only direct caller from [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md).
