*** UID:0000U0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlendRgb565Pair_4C60D0 0x004C60D0

## Status

- Confidence: medium-high for behavior, medium for final original name.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Autogen parent: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x004c60d0-0x004c6151`

## Behavior

`BlendRgb565Pair_4C60D0` blends two packed RGB565 pixels at once. The inputs are 32-bit values containing two 16-bit RGB565 colors, and the helper applies the same 0..32 weighted blend math across both packed pixels.

## Evidence

- Live IDA MCP `lookup_funcs 0x004c60d0` reports `sub_4C60D0` size `0x81`.
- Live IDA MCP reports four callers in `0x004c0850`, `0x004c0f80`, and `0x004c4380` render neighborhoods.
- It is adjacent to `BlendRgb565Pixel`, supporting a shared original helper file.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), and stale generated-source evidence wording was replaced with live IDA evidence.
  - Before: the item was unclassified and the evidence section still cited generated import metadata.
  - After: it is marked as a NexusTK-owned packed RGB565 render helper under the validated SoftwareBlend16 file root; C++ remains blank because final helper naming/signature is not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4C60D0` at `0x004c60d0`, size `0x81`, with direct callers in `sub_4C0850`, `sub_4C0F80`, and `sub_4C4380`; the helper has no project callees.

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented packed RGB565 pair blending behavior, ownership, callers, and adjacent pixel helper but remained unevaluated.
  - After: score reflects documented behavior and source placement, with remaining confidence limited by final original helper name.
  - Evidence: IDA caller notes tie the helper to software render neighborhoods and adjacency to [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md) supports shared [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) ownership.
