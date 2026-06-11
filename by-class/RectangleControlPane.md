*** UID:0000BT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: strong for constructor, paint virtual, destructor, and fixed type id.
- Likely source file: [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- Vtable layout: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)

## Class Purpose

`RectangleControlPane` is a simple solid-rectangle visual control. It derives from `ControlPane`, stores/applies a draw color, fills its bounds through the shared rectangle draw path, and reports fixed control type id `21`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Constructs the base `ControlPane`, installs rectangle vtables, and applies the configured color. |
| non-deleting destructor helper | `0x00499ce0-0x00499cfe` | Restores the three Rectangle vtables and tail-jumps to shared pane teardown. |
| paint/invalidating virtual | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Gets bounds and draws/fills the full rectangle. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler-generated destructor adjustor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |
| control type id | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md) | Returns fixed type id `21`. |

## Evidence Notes

- Live IDA confirms the only ordinary constructor caller at `0x0045252c`, inside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Live IDA confirms vtable data refs to the paint virtual at `0x00618478`, the type-id virtual at `0x00618494`, the secondary/tertiary adjustor thunks at `0x0061849c` and `0x006184cc`, and the primary destructor wrapper slot at `0x00618434`.
- The constructor calls `ControlPane` base construction with kind `8`, installs the three Rectangle vtables, and applies the constructor color argument through the shared color/draw-state setter.
- Paint calls the shared bounds helper at `0x004b8e00` and the shared draw callback slot at `0x0069b3fc`.
- The scalar deleting destructor restores the three Rectangle vtables, calls shared pane teardown, and frees the object only for the normal deleting flag path.
- Final C++ is intentionally blank because the class remains below the 95/95 reconstruction-code threshold.

## Cross-References

- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md)
- [UID:00011Q][0x00499c60-0x00499d36.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d36.RectangleControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)

## Changes

- 2026-06-05 A004 live refresh:
  - Before: the class still carried recovered-source provenance, blank parent metadata, and older stale-tool caveats.
  - After: raised from `82/84` to `84/88`, attached to [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md), removed stale provenance, added the omitted `0x00499ce0` helper, and kept final C++ blank.
  - Evidence: live IDA confirms constructor/helper/paint/destructor/type-id sizes, constructor caller, vtable refs, color setter, bounds/draw callback path, adjustor-thunk routing, and source-file parent eligibility.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/84`.
  - Before: The page was unevaluated despite documenting constructor, paint, destructor thunk handling, type id, vtables, and generated teardown pollution.
  - After: Scored as high completion and strong confidence for a small visual control.
  - Evidence: Existing method notes, IDA caller/vtable evidence, destructor thunk classification, and control-pane cross-references support the score.
