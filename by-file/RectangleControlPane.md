*** UID:0000N1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: strong for class role and method ownership, medium for final original file split.
- Proposed module: `ui/controls/RectangleControlPane.cpp`
- Main address ranges: `0x00499c60-0x00499d37`, plus destructor/thunk support in `0x0049afc1-0x0049b8f5`
- Vtable layout: [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) and [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)

## File Role

`RectangleControlPane` is a minimal `ControlPane`-derived filled-rectangle control. It constructs a control of type `8`, stores/applies a drawing color through the shared theme/fill helper, and paints its full bounds as a solid rectangle.

Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md) symbol rendering, where it creates small background rectangles behind symbol/text overlays. The class remains generic visual-control infrastructure rather than minimap-owned code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Constructor; calls `ControlPane::ControlPane` with type `8`, installs rectangle vtables, and applies the configured color. |
| non-deleting destructor helper | `0x00499ce0-0x00499cfe` | Restores the three Rectangle vtables and tail-jumps to shared pane teardown. |
| paint/invalidating virtual | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Gets the pane bounds and fills/invalidates the rectangle through the shared rectangle draw callback. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |
| control type id | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md) | Returns fixed type id `21`. |
| vtable/RTTI data | [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) | Source-declared/generated-binary primary, secondary, and tertiary vtable views with RTTI pointers, paint/type-id slots, and destructor adjustor entries. |

## Ownership Decision

Keep this as `ui/controls/RectangleControlPane.cpp` for now. It is adjacent to other generic control classes, its recovered source file is a one-class visual control, and its sole confirmed caller is a consumer rather than source-owner evidence.

This file could merge later into a broader `BasicControlPanes.cpp` if more tiny primitive controls prove to have shared original source placement.

## Evidence Notes

- Live IDA confirms real functions at `0x00499c60`, `0x00499ce0`, `0x00499d00`, `0x0049b490`, and `0x0049b8f0`, plus compiler adjustor thunks at `0x0049afc1` and `0x0049afcc`.
- The constructor calls `ControlPane` base construction with kind `8`, installs Rectangle vtables, applies the configured color through the shared color/draw-state setter, and has one ordinary caller at `0x0045252c` inside `MiniMapDialog::RenderSymbols`.
- The paint virtual has a vtable data ref at `0x00618478`, calls the shared bounds helper, and fills via the shared draw callback slot at `0x0069b3fc`.
- The type-id virtual has a vtable data ref at `0x00618494` and returns fixed type id `21`.
- The primary destructor wrapper has a vtable data ref at `0x00618434`; secondary and tertiary adjustor thunk table cells are at `0x0061849c` and `0x006184cc`.
- The exact [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) page records the primary RTTI/vtable span at `0x00618430-0x00618498`, the secondary RTTI/vtable span at `0x00618498-0x006184c8`, and the tertiary RTTI/vtable span at `0x006184c8-0x006184d4`, bounded by `NumericStringControlPane` before it and `CheckBoxControlPane` after it.
- Vtable reconstruction should come from the class declaration and inherited pane/control interfaces. The secondary and tertiary deleting-destructor slots are compiler-generated adjustor thunk entries, not handwritten source bodies for this file.

## Cross-References

- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:00011Q][0x00499c60-0x00499d36.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d36.RectangleControlPaneCore.md)
- [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)

## Changes

- 2026-06-06 A008 vtable-data consistency pass:
  - Before: the file page referenced the shared vtable type page and method refs, but did not list the exact `0x00618430-0x006184d4` RectangleControlPane `.rdata` child or its neighboring boundaries.
  - After: raised from `84/86` to `86/88`, added the exact vtable-data child to proposed contents and cross-references, and documented source-declared/generated-binary handling for primary/secondary/tertiary vtable views.
  - Evidence: [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) records the RTTI pointers, decorated vtable globals, constructor/destructor vptr stores, paint/type-id table refs, and `NumericStringControlPane`/`CheckBoxControlPane` boundaries.
- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented rectangle-control constructor anchor at `0x00499c60`; proposed-source-tree groups this fixed visual control with reusable UI controls beside `NumericStringControlPane.cpp`.
- 2026-06-05 A004 live refresh:
  - Before: the file page still carried recovered-source provenance and stale external-tool caveats, and it omitted the local non-deleting destructor helper.
  - After: raised from `82/78` to `84/86`, removed stale provenance, added the `0x00499ce0` helper, and refreshed evidence for constructor/paint/destructor/type-id behavior.
  - Evidence: live IDA confirms function sizes, constructor caller, vtable refs, color setter, bounds/draw callback path, type-id constant, adjustor thunk routing, and generic source-file placement.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents class role, proposed contents, ownership decision, IDA/vtable evidence, constructor caller, and cross-references; confidence remains capped by final split into standalone control file versus broader primitive-control grouping.
