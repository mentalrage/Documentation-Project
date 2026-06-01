*** UID:0000BT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: strong for constructor, paint virtual, destructor, and fixed type id.
- Likely source file: [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- Vtable layout: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_RectangleControlPane.cpp`

## Class Purpose

`RectangleControlPane` is a simple solid-rectangle visual control. It derives from `ControlPane`, stores/applies a draw color, fills its bounds through the shared rectangle draw path, and reports fixed control type id `21`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Constructs the base `ControlPane`, installs rectangle vtables, and applies the configured color. |
| paint/invalidating virtual | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Gets bounds and draws/fills the full rectangle. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler-generated `this`-adjusting destructor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |
| control type id | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md) | Returns fixed type id `21`. |

## Evidence Notes

- IDA confirms the only direct constructor caller found in this pass at `0x0045252c`, inside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- IDA confirms vtable data xrefs to the paint virtual at `0x00618478` and type-id virtual at `0x00618494`.
- 2026-05-26 IDA vtable recheck confirms primary, secondary, and tertiary vtables at `0x00618434`, `0x0061849c`, and `0x006184cc`; current Wave3 metadata reports `vtable_count: 0`, so use the manual vtable page as canonical.
- 2026-05-26 IDA recheck confirms adjustor thunks `0x0049afc1` and `0x0049afcc` forward to scalar deleting destructor `0x0049b490` after `this - 0xa0` and `this - 0xa4`; these are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Current simroot destructor output references `TextButtonExControlPane` teardown naming; IDA shows this is base teardown/helper pollution, not button ownership.

## Cross-References

- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:00011Q][0x00499c60-0x00499d36.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d36.RectangleControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/84`.
  - Before: The page was unevaluated despite documenting constructor, paint, destructor thunk handling, type id, vtables, and generated teardown pollution.
  - After: Scored as high completion and strong confidence for a small visual control.
  - Evidence: Existing method notes, IDA caller/vtable evidence, destructor thunk classification, and control-pane cross-references support the score.
