*** UID:0000TV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaBlendSpan16 0x00460500

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/AlphaBlendSpan16_00460500.cpp`
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x00460500-0x00460709`

## Behavior

`AlphaBlendSpan16` blends RGB565 source rows into destination rows. It divides each row into four-pixel blocks and a scalar tail. For an exact 50 percent source weight (`16` of `32`), it dispatches block work to `HalfBlendSpan16Blocks` and half-blends tail pixels directly. For other weights, it dispatches block work to `AlphaBlendSpan16Blocks` and uses `BlendRgb565Pixel` for tail pixels.

The return value is the advanced source pointer after the final processed row.

## Evidence

- Wave3 metadata restores this as a true global render helper from report item `0x00460500`.
- IDA MCP reports one direct caller from the `0x004c0f80` render path and callees to the two block helpers.
- The generated body is state-free and only performs 16-bit blend math and pitch advancement.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md)
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md)
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)

## Changes

- 2026-05-30: Grading changed from unevaluated `0/0` to `88/92`.
  - Before: item had behavior/evidence notes but no completion/confidence score.
  - After: score reflects the exact memory range, recovered dispatcher body, block-helper split, and source ownership under [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
  - Evidence: current `simroot_v2/recovered/AlphaBlendSpan16_00460500.cpp` reconstructs the 50-percent and weighted paths, and the linked by-memory page records the exact IDA range and callees.
