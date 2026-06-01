*** UID:0000VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScaleDirectionOffsetToPixels 0x00505100

## Status

- Confidence: strong for exact function range and behavior; medium for final source name.
- Entity kind: small global map-coordinate helper.
- Exact range: `0x00505100-0x00505123`.
- Current generated source: `source-3/simroot_v2/recovered/ScaleDirectionOffsetToPixels_00505100.cpp`.
- Likely owner file: [UID:0000L3][MapPane](by-file/MapPane.md) or a small map-coordinate helper beside it.
- Rebuild handling: `source-authored` map-coordinate helper. It should be rebuilt, but parent attachment and C++ are blank until the surrounding coordinate helpers and tile-dimension names are 95% audited.

## Behavior

`ScaleDirectionOffsetToPixels` scales a two-integer map offset in place from tile units into pixels. It multiplies the second component by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) and the first component by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md).

The apparent component order suggests the input pair is stored as row/column or dy/dx rather than conventional x/y. Do not use this helper alone to rename the tile globals as height/width in reverse.

## IDA Evidence

- `lookup_funcs 0x00505100` reports `sub_505100` size `0x24`.
- IDA decompile shows:

```c
a1[1] *= word_66DA9C;
result = *a1 * word_66DAA0;
*a1 = result;
```

- IDA data refs from this function hit `word_66DA9C` at `0x00505106` and `word_66DAA0` at `0x00505114`.
- 2026-05-31 IDA MCP recheck reports function `sub_505100` with exclusive end `0x00505124` (documented inclusive end `0x00505123`). It has direct callers at `0x00468572`, `0x0053863f`, `0x0053873f`, `0x00539b5f`, `0x0053c767`, `0x0053c889`, and `0x005a8917`, and no function callees.

## Ownership Decision

Keep this as map-coordinate support. It is a tiny helper and should not drive a standalone file in the final source tree unless more nearby coordinate helpers prove an original helper module.

## Cross-References

- [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, seven direct callsites, lack of callees, and data references to the map tile dimension globals. The score remains below 95 because final source naming and related map-coordinate helper ownership are not fully audited.
