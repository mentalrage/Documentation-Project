*** UID:0000N1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: strong for class role and method ownership, medium for final original file split.
- Proposed module: `ui/controls/RectangleControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_RectangleControlPane.cpp`
- Main address ranges: `0x00499c60-0x00499d37`, plus destructor/thunk support in `0x0049afc1-0x0049b8f5`
- Vtable layout: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)

## File Role

`RectangleControlPane` is a minimal `ControlPane`-derived filled-rectangle control. It constructs a control of type `8`, stores/applies a drawing color through the shared theme/fill helper, and paints its full bounds as a solid rectangle.

Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md) symbol rendering, where it creates small background rectangles behind symbol/text overlays. The class remains generic visual-control infrastructure rather than minimap-owned code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Constructor; calls `ControlPane::ControlPane` with type `8`, installs rectangle vtables, and applies the configured color. |
| paint/invalidating virtual | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Gets the pane bounds and fills/invalidates the rectangle through the shared rectangle draw callback. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |
| control type id | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md) | Returns fixed type id `21`. |

## Ownership Decision

Keep this as `ui/controls/RectangleControlPane.cpp` for now. It is adjacent to other generic control classes, its recovered source file is a one-class visual control, and its sole confirmed caller is a consumer rather than source-owner evidence.

This file could merge later into a broader `BasicControlPanes.cpp` if more tiny primitive controls prove to have shared original source placement.

## Evidence Notes

- IDA MCP confirms real functions at `0x00499c60`, `0x00499d00`, `0x0049b490`, and `0x0049b8f0`.
- IDA MCP confirms adjustor thunks at `0x0049afc1` and `0x0049afcc`.
- 2026-05-26 IDA recheck decompiles both adjustor thunks as `this`-adjusting forwards into `0x0049b490`; they are compiler glue, while the scalar deleting destructor remains a reconstructable owner method.
- 2026-05-26 IDA vtable recheck confirms table bases at `0x00618434`, `0x0061849c`, and `0x006184cc`; active Wave3 metadata reports `vtable_count: 0`, so vtable reconstruction currently depends on IDA evidence.
- IDA MCP caller lookup reports one direct constructor caller at `0x0045252c` inside `MiniMapDialog::RenderSymbols`.
- The render virtual has a vtable xref at `0x00618478`; the type-id virtual has a vtable xref at `0x00618494`.

## Cross-References

- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:00011Q][0x00499c60-0x00499d36.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d36.RectangleControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents class role, proposed contents, ownership decision, IDA/vtable evidence, constructor caller, and cross-references; confidence remains capped by final split into standalone control file versus broader primitive-control grouping.
