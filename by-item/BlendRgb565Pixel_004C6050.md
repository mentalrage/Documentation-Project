*** UID:0000U1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlendRgb565Pixel 0x004C6050

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Autogen parent: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x004c6050-0x004c60c7`

## Behavior

`BlendRgb565Pixel` blends one RGB565 source pixel into one destination pixel using a 0..32 weight. It handles the green lane separately from the combined red/blue lanes and recombines the result into a 16-bit RGB565 color.

## Evidence

- Live IDA MCP `lookup_funcs 0x004c6050` reports `sub_4C6050` size `0x77`.
- Live IDA MCP reports broad calls from `0x004c0770`, `0x004c0850`, `0x004c0f80`, `0x004c3ea0`, and `0x004c4380` render neighborhoods.
- The adjacent packed-pair helper at `0x004c60d0` uses the same source-level category.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md)
- [UID:0000U0][BlendRgb565Pair_004C60D0](by-item/BlendRgb565Pair_004C60D0.md)
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), and stale generated-source evidence wording was replaced with live IDA evidence.
  - Before: the item was unclassified and the evidence section still cited generated metadata.
  - After: it is marked as a NexusTK-owned RGB565 pixel helper under the validated SoftwareBlend16 file root; C++ remains blank because final helper naming/signature and the surrounding declarations are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4C6050` at `0x004c6050`, size `0x77`, with broad direct callers in `sub_4C0770`, `sub_4C0850`, `sub_4C0F80`, `sub_4C3EA0`, and `sub_4C4380`; the helper has no project callees.

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented RGB565 weighted blend behavior, ownership, caller neighborhoods, and adjacent packed-pair helper but remained unevaluated.
  - After: score reflects strong documentation for this small software-render helper.
  - Evidence: IDA caller notes place the helper in broad RGB565 render neighborhoods under [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
