*** UID:00009M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NumericStringControlPane

## Status

- Confidence: strong for constructor, destructor, and render virtual.
- Likely source file: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- Vtable layout: [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- Current recovered file: `source-3/simroot_v2/class_NumericStringControlPane.cpp`

## Class Purpose

`NumericStringControlPane` is a fixed-width numeric text control. It stores a wide string, alignment mode, color variant, and a DAT-loaded font handle, then draws each digit in 9x11 cells. It skips spaces and `/`, and draws `-` through the `FONTSYMB.EPF` symbol path.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NumericStringControlPane` | [UID:00011L][0x00499910-0x004999c1.NumericStringControlPaneConstructor](by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md) | Constructs the base `ControlPane`, copies the text, records alignment/color, and loads `9X11FONT.BIN`. |
| `~NumericStringControlPane` | [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md) | Releases the font handle and destroys local text/base control state. |
| `RenderNumericString` | [UID:00011O][0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString](by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md) | Computes alignment, advances a 9-pixel cursor, and draws numeric glyphs. |
| adjustor thunks | [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) | Compiler-generated `this`-adjusting destructor thunks; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md) | Destructor/delete wrapper. |

## Evidence Notes

- IDA confirms constructor callers at `0x00451143` and `0x004511d8`, both in [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) coordinate-control setup.
- IDA confirms the render virtual through a data xref at `0x006183d4`.
- 2026-05-26 IDA vtable recheck confirms primary, secondary, and tertiary vtables at `0x00618390`, `0x006183f8`, and `0x00618428`; current Wave3 metadata reports `vtable_count: 0`, so use the manual vtable page as canonical.
- 2026-05-26 IDA recheck confirms adjustor thunks `0x0049af7f` and `0x0049af8a` forward to scalar deleting destructor `0x0049b2f0` after `this - 0xa0` and `this - 0xa4`; these are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Current simroot output contains an unused `ChattingColorPane` deleting-destructor typedef before this class; treat that as generated owner pollution, not class evidence.

## Cross-References

- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md)
- [UID:00011M][0x00499910-0x00499be6.NumericStringControlPaneCore](by-memory/0x00499910-0x00499be6.NumericStringControlPaneCore.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite detailed constructor/destructor/render, vtable, caller, thunk, and generated-pollution notes.
- Changed to: `COMPLETION:82` and `CONFIDENCE:84`.
- Evidence: the page documents digit rendering behavior, font/resource use, IDA-confirmed callers, vtable addresses, destructor thunks, scalar deleting destructor, and owner-pollution caveats; remaining gaps are final field names and body-level reconstructed C++.
