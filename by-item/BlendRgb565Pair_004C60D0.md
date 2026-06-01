*** UID:0000U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlendRgb565Pair_4C60D0 0x004C60D0

## Status

- Confidence: medium-high for behavior, medium for final original name.
- Entity kind: free render helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/BlendRgb565Pair_004C60D0.cpp`
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x004c60d0-0x004c6151`

## Behavior

`BlendRgb565Pair_4C60D0` blends two packed RGB565 pixels at once. The inputs are 32-bit values containing two 16-bit RGB565 colors, and the helper applies the same 0..32 weighted blend math across both packed pixels.

## Evidence

- Wave3 imports this as a recovered global, but the current metadata has no summary or grade.
- IDA MCP reports four callers in `0x004c0850`, `0x004c0f80`, and `0x004c4380` render neighborhoods.
- It is adjacent to `BlendRgb565Pixel`, supporting a shared original helper file.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented packed RGB565 pair blending behavior, ownership, callers, and adjacent pixel helper but remained unevaluated.
  - After: score reflects documented behavior and source placement, with remaining confidence limited by final original helper name.
  - Evidence: IDA caller notes tie the helper to software render neighborhoods and adjacency to [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md) supports shared [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) ownership.
