*** UID:0000CL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollNewGroupPane

## Status

- Confidence: strong for confirmed scrollbar methods; medium for final original source split because the helper family is generated under `TextEditPane` in current simroot data.
- Likely source file: [UID:0000JS][Group](by-file/Group.md), with possible split to [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- Address ranges: [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md), [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md), [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md), and [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_ScrollNewGroupPane.cpp`

## Class Purpose

`ScrollNewGroupPane` is the custom EPF-backed scrollbar used by `NewGroupPane`. It tracks range, position, active part, mouse capture/drag state, and draws slide background/thumb art from `SLIDEBG.EPF` and `SCRBUTT.EPF`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollNewGroupPane` | `0x00560900-0x005609a0` | Constructs pane state and installs scrollbar vtables. |
| `SetMaxRange` | `0x00560a10-0x00560a6a` | Clamps range and invalidates when changed. |
| `SetScrollPosition` | `0x00560a70-0x00560a96` | Updates position and invalidates. |
| `Show` | `0x00560aa0-0x00560ab9` | Enables display and invalidates. |
| `OnMouseEvent` | `0x00560b00-0x00560ce0` | Handles mouse move/down/up, capture, drag state, and part invalidation. |
| `CanResize` | `0x00560cf0-0x00560cf4` | Returns false. |
| `OnSelectionChanged` | `0x00560d00-0x00560d32` | Schedules scroll update callbacks. |
| `OnPaint` | `0x00560d40-0x0056141f` | Draws track and thumb EPF assets. |
| `HitTestPart` | `0x00561420-0x0056173d` | Tests point/cursor position against scrollbar parts `0..4`. |
| `GetPartRect` | `0x00561740-0x005619c7` | Computes endcap, track, and thumb rectangles. |
| `SetHighlightedPart` | `0x005619d0-0x00561a3d` | Raw/manual method boundary; IDA does not create a function object. |
| `BeginPartInteraction` | `0x00561a40-0x00561aff` | Raw/manual method boundary; sets highlight/drag point, active part, and schedules repeated updates. |
| `UpdateActiveInteraction` | `0x00561b00-0x00561bbf` | Updates drag/click interaction from current cursor state. |
| `UpdateScrollPositionFromCursor` | `0x00561bc0-0x00561d4c` | Converts cursor position to scroll position and calls `NewGroupPane::SetScrollPosition`. |
| `Deactivate` | `0x00561d50-0x00561dab` | Raw/manual method boundary; cancels effect scheduling and clears highlight state. |

## Evidence Notes

- IDA MCP confirms real starts at `0x00560900`, `0x00560a10`, `0x00560a70`, `0x00560aa0`, `0x00560b00`, `0x00560cf0`, `0x00560d00`, `0x00560d40`, `0x00561420`, `0x00561740`, `0x00561b00`, and `0x00561bc0`.
- IDA reports no function objects at `0x005619d0`, `0x00561a40`, or `0x00561d50`, but raw disassembly shows complete method bodies at those addresses.
- Current simroot data owns `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0` under `TextEditPane`; IDA xrefs tie them to this scrollbar path, and `0x00561bc0` calls the `NewGroupPane::SetScrollPosition` callback at `0x0056df00`.
- Vtables are documented at [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md): primary `0x00623f1c`, secondary `0x00623f68`, and tertiary `0x00623f98`.
- IDA confirms `0x00561db0` as a [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)-style constructor, called from [UID:00002X][CollectionPane](by-class/CollectionPane.md) at `0x0056e940`.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0001GP][0x00560900-0x0056141f.ScrollNewGroupPaneCore](by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md)
- [UID:0001GQ][0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart](by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md)
- [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md)
- [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md)
- [UID:0001YR][ScrollNewGroupPaneVtables](by-type/by-vtable/ScrollNewGroupPaneVtables.md)
- [UID:000090][NewGroupPane](by-class/NewGroupPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite detailed method ranges, raw helper boundaries, vtable mapping, and generated owner pollution notes.
  - After: Scored as high completion with medium-high confidence because confirmed scrollbar behavior is strong, while final source split and raw helper modeling remain unresolved.
  - Evidence: Existing method notes, IDA evidence notes, vtable/type references, and exact by-memory child pages support the score.
