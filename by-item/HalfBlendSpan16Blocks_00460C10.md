*** UID:0000US | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HalfBlendSpan16Blocks 0x00460C10

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/HalfBlendSpan16Blocks_00460C10.cpp`
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x00460c10-0x00460c8c`

## Behavior

`HalfBlendSpan16Blocks` is the exact 50 percent RGB565 block path. It averages source and destination pixels in four-pixel groups using the standard RGB565 half-blend mask formula, then advances source and destination spans by their pitches for each row.

## Evidence

- Wave3 metadata restores it as a true global render helper from report item `0x00460c10`.
- IDA MCP recheck on 2026-05-31 confirms `sub_460C10` starts at `0x00460c10`, ends half-open at `0x00460c8c`, has no project callees, and is referenced from `sub_460500` plus another alpha-blend-family code reference at `0x0046073e`.
- IDA MCP decompile shows the MMX four-pixel loop, RGB565 half-blend masks `0xF7DEF7DEF7DEF7DE` and `0x0821082108210821`, row-pitch advancement, `pushaw`/`popaw`, and `_m_empty()`.
- The generated body is a state-free block pixel helper.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md)
- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented a 50 percent RGB565 helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the existing researched body and fresh IDA verification. Parent UID and C++ remain blank because the surrounding blend family and final source-level names are not at the `95+` final-code gate.
  - Evidence: IDA MCP confirms the exact `0x00460c10-0x00460c8c` function range, two alpha-blend-family references, no project callees, and a decompiled MMX RGB565 half-blend loop.
