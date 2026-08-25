*** UID:0000UD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for DecodePcxToRgb565Buffer is covered by [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DecodePcxToRgb565Buffer 0x00549410

## Status

- Confidence: strong for PCX/RGB565 behavior, medium for final original file name.
- Entity kind: free image-codec helper.
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) or a small `render/PcxDecode.cpp`
- Owner/emitter route: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x00549410-0x00549616`

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now documents the exact boundary, one caller, allocator-only callee shape, PCX validation gates, output allocation contract, RLE loop, scanline padding handling, optional palette-index remap, transparent pixel handling, RGB565 packing, and ImageLoaders owner/emitter route. |
| Confidence | 90 | Live IDA MCP evidence agrees with exact memory page [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md), the PCX-to-DIB caller page, and the ImageLoaders file page. Confidence stays below final-source quality because the original helper name, PCX header representation, and source parameter names remain unresolved. |

## Behavior

`DecodePcxToRgb565Buffer` validates an 8-bit PCX image with a 256-color palette footer, expands the RLE stream, maps palette indices when a caller supplies a remap table, converts RGB triples into RGB565, and writes transparent-index pixels as zero.

The function allocates the output pixel buffer and returns width/height to the caller. IDA MCP confirms its only direct caller is `CreateDIBitmapFromPcxBuffer` at `0x004a18f5`.

## 2026-06-14 Live IDA Refresh

- `lookup_funcs` resolves `0x00549410` to `sub_549410`, size `0x206`; `0x00549616` is not a function. Decimal size `518 == 0x206` was verified with `int_convert.py`.
- `analyze_function 0x00549410` reports one caller and one allocator-style callee; `xrefs_to 0x00549410` reports the single code ref at `0x004a18f5` inside `sub_4A18B0`.
- Targeted decompilation reconfirmed the hard validation gates: the output buffer pointer must be null, `a1[a2 - 769]` must be the PCX palette marker byte `12`, and the header bits-per-pixel byte must be `8`.
- The decoder starts encoded image reads at `a1 + 128` and reads the 256-entry palette footer from the final `768` bytes; `128 == 0x80`, `768 == 0x300`, `769 == 0x301`, and `12 == 0x0c` were verified with `int_convert.py`.
- The output allocation is `2 * width * height` bytes, the source stride is even-width padded as `width + width % 2`, and the loop handles PCX RLE bytes with high bits `0xc0`.
- When a remap table is supplied, the palette index is replaced by `*(a7 + 4 * index)` before the transparent-index comparison; matching transparent pixels write zero, otherwise the final palette RGB triple is packed into RGB565.
- Final reconstruction C++ stays blank despite the confirmed emitter route because the source-level signature, PCX header struct, remap-table type, transparent-index naming, and allocator/free contract are not yet final-source quality.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-07-01 B009 ImageLoaders empty-emitter implementation:
  - Formal C++ changed from blank to a covered-by comment pointing to exact by-memory child [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md).
  - Summary/evidence: this item page is a name-centric alias for the exact PCX/RLE/RGB565 decoder. The accepted report preserves the item-level behavior and live IDA evidence here while routing the first-draft implementation through the exact by-memory page to avoid duplicate generated bodies.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and stale generated-source wording was removed.
  - Before: the PCX decoder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned image codec source under the validated ImageLoaders file root; C++ remains blank because final decoder signature, PCX structs, and palette/remap names are not at source-quality evidence.
  - Evidence: live IDA MCP confirms `sub_549410` at `0x00549410`, size `0x206`, exactly one direct caller from `sub_4A18B0`, and no project callees beyond runtime support.

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented PCX/RGB565 decode behavior, caller, owner options, and cross-references but remained unevaluated.
  - After: score reflects documented validation, RLE expansion, palette remapping, RGB565 conversion, transparent-index handling, output allocation, and single caller.
  - Evidence: IDA notes confirm the exact range and only direct caller from [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md).

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had the correct high-level decode summary but lacked current score rationale and written proof for the parameter/validation/allocation mechanics already present in the exact memory page.
  - After: added live IDA MCP boundary/caller/decompile refresh, `int_convert.py`-verified PCX header/palette constants, and current source-quality blocker wording.
