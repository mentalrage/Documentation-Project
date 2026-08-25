*** UID:0000VC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this helper is covered by [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScaleDirectionOffsetToPixels 0x00505100

## Status

- Confidence: strong for exact function range, behavior, caller set, and owner route; medium for final source-facing helper name.
- Entity kind: small global map-coordinate helper.
- Exact range: `0x00505100-0x00505123`.
- Owner file: [UID:0000L3][MapPane](by-file/MapPane.md) coordinate support, unless a later map-coordinate helper split is proven.
- Rebuild handling: `source-authored` map-coordinate helper. The exact emitted body is owned by [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md); this by-item alias carries only the formal covered-by comment.

## Behavior

`ScaleDirectionOffsetToPixels` scales a two-integer map offset in place from tile units into pixels. It multiplies `pair[1]` by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) / `g_mapTilePixelWidth` and `pair[0]` by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) / `g_mapTilePixelHeight`.

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
- 2026-06-16 live IDA MCP `analyze_function 0x00505100` reconfirms the one-basic-block `__stdcall` body, exact size `36` / `0x24`, no callees, and callers `sub_468520`, `sub_538600`, `sub_5386C0`, `sub_539B20`, `sub_53C700`, `sub_53C810`, and `sub_5A88D0`. Assembly still reads `word_66DA9C` at `0x00505106`, writes `[ecx+4]`, reads `word_66DAA0` at `0x00505114`, writes `[ecx]`, and returns with `retn 4`.
- Existing support now resolves [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) to MapPane-owned `g_mapTilePixelWidth` / `g_mapTilePixelHeight` storage and keeps the row/column pair-order caveat; this helper does not justify reversing those global names.

## Ownership Decision

Keep this as [UID:0000L3][MapPane](by-file/MapPane.md) coordinate support. It is a tiny helper and should not drive a standalone file in the final source tree unless more nearby coordinate helpers prove an original helper module.

## Source-Quality Blockers Checked

- Helper split/name: checked the exact memory page, [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), and project-level resolved-name evidence. `ScaleDirectionOffsetToPixels_00505100` is the current documentation name; no original source symbol or broader coordinate-helper source file is proven.
- Caller/reachability: live IDA sees seven direct code xrefs and no callees. The callers span MapPane coordinate setup plus attached/static/object/user movement consumers, which supports MapPane coordinate ownership but does not prove a standalone helper module.
- Final C++: [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md) now emits the accepted first-draft body. This alias stays non-duplicating and records a formal covered-by comment because final helper spelling, argument type/order, and any surrounding coordinate-helper split are still not final-source quality.

## Cross-References

- [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- 2026-06-29 Agent-B004 MapPane empty-emitter callback:
  - Inserted the accepted formal covered-by comment pointing to [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md).
  - Evidence: current MCP `221`/`222` proves the exact helper body at the by-memory child; duplicating that body in the by-item alias would create a second emitter for the same `0x00505100` helper.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, seven direct callsites, lack of callees, and data references to the map tile dimension globals. The score remains below 95 because final source naming and related map-coordinate helper ownership are not fully audited.
- 2026-06-03: Completion/confidence changed from `70/85` to `84/90`, and `AUTOGEN_PARENT_UID` set to [UID:0000L3][MapPane](by-file/MapPane.md).
  - Before: the page had the basic multiply behavior and caller list but no parent attachment and still cited stale generated-output provenance.
  - After: live IDA MCP reconfirmed the exact half-open range, all seven direct callers, no callees, the `__stdcall` decompile, the two tile-dimension data refs and values, and padding after the function; `MapPane` is a high-confidence `NexusTK/map/` parent that already documents this helper as coordinate support.
  - Remaining gap: final reconstruction C++ stays blank because the original helper name and any broader map-coordinate helper split remain below the `95/95` gate.
- 2026-06-16 A001 Goal 2 refresh: completion raised from `84` to `86`; confidence stays `90`. Live IDA MCP reconfirmed the exact one-block body, seven-callsite reachability, no-callee status, and width/height global reads, while support docs now resolve the tile-dimension globals through MapPane. Final C++ remains blank because helper spelling, pair type/order, and source split are still unresolved.
