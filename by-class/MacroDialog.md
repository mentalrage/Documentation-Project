*** UID:00007I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MacroDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Main address doc: [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- Generated recovery hint: `source-3/simroot_v2/class_MacroDialog.cpp`; use as a lead only, not authority.
- Vtable family: [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Functionality

`MacroDialog` is the older keyboard macro setup dialog in the [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) source family. It builds the older macro setup UI, owns the save path for those edited macro entries, and is opened from [UID:00009V][OptionPane](by-class/OptionPane.md) / [UID:0000M7][OptionPane](by-file/OptionPane.md) rather than being implemented inside the option-pane source itself.

The class sits at the front of the contiguous [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) executable island, before `SpellMacroDialog` and `NewMacroDialog`. The module-level file page records this as the older generation of the macro-dialog family, while the newer paged dialog and integrated macro dialog have separate class pages.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053e520-0x0053e8ce` | Builds the older macro dialog and edit controls. |
| non-deleting destructor helper | `0x0053e8d0-0x0053e8ee` | IDA-confirmed helper adjacent to the save method. |
| `SaveMacros` | `0x0053e8f0-0x0053e958` | Saves macro entries. |
| scalar deleting destructor | `0x005427a0-0x005427f4` | Deleting destructor wrapper in the shared dialog-destructor island. |

## Evidence Notes

- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) records the exact older `MacroDialog` constructor, non-deleting destructor helper, `SaveMacros`, and padding boundaries before `SpellMacroDialog`.
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) places this class in `NexusTK/ui/dialogs/MacroDialogs.cpp` and records why the implementation stays in the macro-dialog source family despite being opened by `OptionPane`.
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) verifies the `MacroDialog` primary, secondary, and tertiary vtable views at `0x00620d10-0x00620da8`; the primary table contains scalar deleting destructor slot `0x005427a0` and `SaveMacros` slot `0x0053e8f0`.
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) classifies the related secondary/tertiary destructor adjustor support as compiler/vtable glue rather than handwritten macro behavior.
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) owns the scalar deleting destructor wrapper for this class; the source reconstruction should declare the destructor, not hand-port the wrapper body as feature logic.
- Live IDA MCP was unavailable during the 2026-06-07 A005 pass, so the new consolidation here relies on existing UID-backed file, memory, and vtable documentation instead of adding fresh disassembly claims.

## Dependencies And State

| Dependency | Role |
| --- | --- |
| [UID:00009V][OptionPane](by-class/OptionPane.md) / [UID:0000M7][OptionPane](by-file/OptionPane.md) | Opens the older macro setup flow; does not own this class implementation. |
| [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) | Proposed source owner and parent for the older, spell, newer, integrated, and edit-control macro family. |
| [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) | Exact method-island evidence for this class and its neighboring macro dialog generations. |
| [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) | Source-declared/generated-binary vtable and RTTI evidence for method slots and destructor support. |
| [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) | Module-level macro/hotkey profile row storage edited by macro-dialog family code; exact older dialog field mapping still needs deeper body-level reconstruction. |

## Autogen Handling

Attach this class to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md). The class now satisfies the 80/80 attachment gate after this evidence consolidation, and the parent source file is already `88/82`. Keep final C++ blank because constructor field layout, control ids, exact save-loop local names, and source-facing destructor declarations remain below the 95/95 final-source gate.

## Score Rationale

Completion is raised to `80` because the page now records source ownership, exact method ranges, vtable identity, destructor-island separation, option-pane opener, macro-record dependency, and autogen handling. Confidence rises modestly to `84` because those claims are backed by existing UID-linked docs, but this pass did not add fresh live IDA evidence and the older dialog's constructor/save internals are still too thin for final source emission.

## Cross References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md)

## Changes

- 2026-06-07: Raised completion/confidence from `74/82` to `80/84` and attached `AUTOGEN_PARENT_UID:0000KY`. The class page now records the MacroDialogs parent, exact method island, vtable-slot evidence, destructor/adjustor island separation, option-pane opener, macro-record dependency, and final-C++ gate. Live IDA MCP was unavailable after three connection attempts during this pass, so the score remains conservative and the new claims are limited to existing UID-backed documentation.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms the older macro dialog constructor/save/destructor functions are NexusTK-owned UI behavior. Kept `AUTOGEN_PARENT_UID` blank because this class is `74/82`, below the 80/80 parent-attachment gate, even though [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0053e520` (`sub_53E520`, size `0x3af`), `0x0053e8d0` (`sub_53E8D0`, size `0x1f`), `0x0053e8f0` (`sub_53E8F0`, size `0x69`), and `0x005427a0` (`sub_5427A0`, size `0x55`); `callers` confirms the constructor is called at `0x0053e0f1` in `sub_53DDB0`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: the older macro setup dialog has purpose, source owner, vtable family, opening path, and main methods documented, but method-level behavior remains comparatively brief. Evidence: linked macro-dialog memory range, constructor/save/destructor method map, and `OptionPane::OnOptionCommand` ownership evidence.
