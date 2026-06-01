*** UID:0000TW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaBlendSpan16Blocks 0x00460B00

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/AlphaBlendSpan16Blocks_00460B00.cpp`
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x00460b00-0x00460c0a`

## Behavior

`AlphaBlendSpan16Blocks` blends RGB565 rows in four-pixel blocks using a 0..32 weight. It is the non-50-percent bulk path under `AlphaBlendSpan16`, handling the row loop and pitch advancement while writing blended pixels into the destination span.

## Evidence

- Wave3 metadata identifies it as the weighted RGB565 block helper restored from report item `0x00460b00`.
- IDA MCP reports the direct caller from `AlphaBlendSpan16` at `0x004605fd`.
- The function has no object receiver or asset-library state.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md)
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/90`.
  - Before: page documented behavior, ownership, caller evidence, and cross-links but remained unevaluated.
  - After: score reflects strong documentation for this small RGB565 row/block blend helper.
  - Evidence: Wave3 metadata and IDA caller evidence tie `0x00460b00-0x00460c0a` directly to [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md) under [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
