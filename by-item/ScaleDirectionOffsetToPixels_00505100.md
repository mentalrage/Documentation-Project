*** UID:0000VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScaleDirectionOffsetToPixels 0x00505100

## Status

- Confidence: strong for exact function range and behavior; medium for final source name.
- Entity kind: small global map-coordinate helper.
- Exact range: `0x00505100-0x00505123`.
- Owner file: [UID:0000L3][MapPane](by-file/MapPane.md) coordinate support, unless a later map-coordinate helper split is proven.
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
- 2026-06-03 live IDA MCP recheck reconfirms `sub_505100` as `0x00505100-0x00505124`, size `0x24`, with no callees and the same seven direct code callers.
- 2026-06-03 live IDA MCP decompile shows `int __stdcall sub_505100(int* pair)`: it multiplies `pair[1]` by `word_66DA9C`, multiplies `pair[0]` by `word_66DAA0`, stores the second result back to `pair[0]`, and returns that scaled first component.
- 2026-06-03 live IDA MCP `py_eval` confirms the helper's data refs to `word_66DA9C` at `0x00505106` and `word_66DAA0` at `0x00505114`, both initialized to `48`, and shows `0xcc` padding after the `retn 4`.

## Ownership Decision

Keep this as [UID:0000L3][MapPane](by-file/MapPane.md) coordinate support. It is a tiny helper and should not drive a standalone file in the final source tree unless more nearby coordinate helpers prove an original helper module.

## Cross-References

- [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, seven direct callsites, lack of callees, and data references to the map tile dimension globals. The score remains below 95 because final source naming and related map-coordinate helper ownership are not fully audited.
- 2026-06-03: Completion/confidence changed from `70/85` to `84/90`, and `AUTOGEN_PARENT_UID` set to [UID:0000L3][MapPane](by-file/MapPane.md).
  - Before: the page had the basic multiply behavior and caller list but no parent attachment and still cited stale generated-output provenance.
  - After: live IDA MCP reconfirmed the exact half-open range, all seven direct callers, no callees, the `__stdcall` decompile, the two tile-dimension data refs and values, and padding after the function; `MapPane` is a high-confidence `NexusTK/map/` parent that already documents this helper as coordinate support.
  - Remaining gap: final reconstruction C++ stays blank because the original helper name and any broader map-coordinate helper split remain below the `95/95` gate.
