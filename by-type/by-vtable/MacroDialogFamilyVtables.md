*** UID:0001Y1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MacroDialog Family Vtables

## Status

- Entity kind: MSVC vtable families for macro dialogs and macro edit-row controls
- Likely source owner: [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- Current generated owners: [UID:00007I][MacroDialog](by-class/MacroDialog.md), [UID:0000DP][SpellMacroDialog](by-class/SpellMacroDialog.md), [UID:000094][NewMacroDialog](by-class/NewMacroDialog.md), [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md), [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md), [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md), and [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md)
- Confidence: confirmed for addresses, RTTI-backed identity, and constructor/destructor stores.

## Evidence

IDA symbol enumeration on 2026-05-26 shows decorated vtable symbols and RTTI descriptors for all seven macro classes. Each vtable view has a complete-object-locator pointer immediately before the first slot. Constructor, non-deleting teardown, and scalar deleting destructor paths write the corresponding three views for each class.

IDA MCP recheck on 2026-06-01 confirms the current IDB still has the expected MSVC decorated vtable globals and RTTI complete-object locators for all listed views. `list_globals` finds `??_7MacroDialog@@6B@`, `??_7SpellMacroDialog@@6B@`, `??_7NewMacroDialog@@6B@`, `??_7IntegrateMacroDialog@@6B@`, `??_7SpellMacroEditControlPane@@6B@`, `??_7NewMacroEditControlPane@@6B@`, and `??_7IntegrateMacroEditControlPane@@6B@`, plus their secondary/tertiary views and `??_R4...` locator symbols. A `py_eval` vtable walk verified each table's locator pointer at `base - 4`, the documented primary/secondary/tertiary slot counts, the key override slot values in the tables below, and constructor/destructor xrefs back to the owning executable ranges: `0x0053e520`, `0x0053e8d0`, `0x0053e960`, `0x0053ecd0`, `0x0053ed90`, `0x0053f080`, `0x00541b30`, `0x00541e30`, `0x0057f760`, `0x0057f7b0`, `0x0057f9d0`, `0x0057fa80`, `0x0057fd10`, `0x00580690`, `0x00580710`, and `0x00580770`.

The same recheck also verifies the local boundaries. The dialog vtable views end immediately before the next RTTI locator/view; the edit-control group ends at `0x0062d3cc`, where the next named item is the `Ctrl+D` string. This supports keeping the vtables as source-declared/generated-binary data rather than folding them into adjacent string or unrelated read-only data.

Current `simroot_v2` metadata still reports `vtable_count: 0` for every macro-dialog and macro-edit-control class in this family, so use this page rather than generated vtable metadata when reconstructing declarations.

## Dialog Vtables

Half-open slot ranges below exclude the following view's RTTI locator pointer.

| Class/view | Slot range | Slots | Key overrides |
| --- | --- | ---: | --- |
| `MacroDialog` primary | `0x00620d10-0x00620d6c` | 23 | `+0x00` scalar deleting destructor `0x005427a0`; `+0x48` `SaveMacros` `0x0053e8f0`. |
| `MacroDialog` secondary | `0x00620d70-0x00620d9c` | 11 | Adjustor/destructor slot `0x005425e1`; otherwise shared pane/input helpers. |
| `MacroDialog` tertiary | `0x00620da0-0x00620da8` | 2 | Adjustor/destructor slot `0x005425ec`; shared base helper `0x00544e90`. |
| `SpellMacroDialog` primary | `0x00620dac-0x00620e08` | 23 | `+0x00` scalar deleting destructor `0x00542a00`; `+0x48` `OnConfirm` `0x0053ecf0`; `+0x58` visibility hook `0x0053ed80`. |
| `SpellMacroDialog` secondary | `0x00620e0c-0x00620e38` | 11 | Adjustor/destructor slot `0x0054264f`; otherwise shared pane/input helpers. |
| `SpellMacroDialog` tertiary | `0x00620e3c-0x00620e44` | 2 | Adjustor/destructor slot `0x0054265a`; shared base helper `0x00544e90`. |
| `NewMacroDialog` primary | `0x00620e48-0x00620ea4` | 23 | `+0x00` scalar deleting destructor `0x00542800`; `+0x48` `OnCommand` `0x0053f0a0`; `+0x58` `SetActiveControl` `0x0053f170`. |
| `NewMacroDialog` secondary | `0x00620ea8-0x00620ed4` | 11 | Adjustor/destructor slot `0x005425f7`; otherwise shared pane/input helpers. |
| `NewMacroDialog` tertiary | `0x00620ed8-0x00620ee0` | 2 | Adjustor/destructor slot `0x00542602`; shared base helper `0x00544e90`. |
| `IntegrateMacroDialog` primary | `0x00621130-0x0062118c` | 23 | `+0x00` scalar deleting destructor `0x00542740`; `+0x44` `OnDraw` `0x00541e50`; `+0x48` `OnButtonClick` `0x00541fa0`. |
| `IntegrateMacroDialog` secondary | `0x00621190-0x006211bc` | 11 | Adjustor/destructor slot `0x005425cb`; `+0x08` `HandleKeyInput` `0x005420c0`. |
| `IntegrateMacroDialog` tertiary | `0x006211c0-0x006211c8` | 2 | Adjustor/destructor slot `0x005425d6`; shared base helper `0x00544e90`. |

## Edit-Control Vtables

The edit controls use the larger `ControlPane`-derived slot shape: 25 primary slots, 11 secondary slots, and 2 tertiary slots.

| Class/view | Slot range | Slots | Key overrides |
| --- | --- | ---: | --- |
| `SpellMacroEditControlPane` primary | `0x0062d1e4-0x0062d248` | 25 | `+0x00` scalar deleting destructor `0x00580770`; `+0x44` `OnPaint` `0x0057f7d0`. |
| `SpellMacroEditControlPane` secondary | `0x0062d24c-0x0062d278` | 11 | `+0x00` adjustor thunk `0x00580671`; `+0x04` `IsSelectable` `0x0057f9a0`; `+0x08` `OnKeyEvent` `0x0057f930`. |
| `SpellMacroEditControlPane` tertiary | `0x0062d27c-0x0062d284` | 2 | Adjustor thunk `0x0058067c`; shared base helper `0x00544e90`. |
| `NewMacroEditControlPane` primary | `0x0062d288-0x0062d2ec` | 25 | `+0x00` scalar deleting destructor `0x00580710`; `+0x44` `OnPaint` `0x0057faa0`. |
| `NewMacroEditControlPane` secondary | `0x0062d2f0-0x0062d31c` | 11 | `+0x00` adjustor thunk `0x0058065b`; `+0x04` `IsSelectable` `0x0057fd00`; `+0x08` `OnKeyEvent` `0x0057fc80`. |
| `NewMacroEditControlPane` tertiary | `0x0062d320-0x0062d328` | 2 | Adjustor thunk `0x00580666`; shared base helper `0x00544e90`. |
| `IntegrateMacroEditControlPane` primary | `0x0062d32c-0x0062d390` | 25 | `+0x00` scalar deleting destructor `0x00580690`; `+0x30` attach hook `0x00580550`; `+0x38` hide hook `0x005805c0`; `+0x44` `OnPaint` `0x0057ffb0`; `+0x58` `SyncEditControl` `0x005805e0`; `+0x5c` activate thunk `0x00580640`. |
| `IntegrateMacroEditControlPane` secondary | `0x0062d394-0x0062d3c0` | 11 | `+0x00` adjustor thunk `0x00580645`; `+0x04` `ForwardMouseEvent` `0x00580460`; `+0x08` `OnKeyEvent` `0x00580320`; `+0x0c` `ForwardFocusEvent` `0x00580490`. |
| `IntegrateMacroEditControlPane` tertiary | `0x0062d3c4-0x0062d3cc` | 2 | Adjustor thunk `0x00580650`; shared base helper `0x00544e90`. |

## Source Reconstruction Notes

These vtable groups support the current [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) source grouping: the older macro dialogs, newer paged dialog, integrated macro dialog, and edit-row controls all share the same `DialogPane`/`ControlPane` multiple-vtable pattern and are separated by behavior rather than by unrelated subsystem ownership.

The vtable slots also confirm that several tiny methods around `0x005425cb-0x0054265a` and `0x00580640-0x00580686` are ABI thunks or adjustor slots, not feature behavior requiring separate source files.

## Cross-References

- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md)
- [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md)
- [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md)
- [UID:000261][0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData](by-memory/0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData.md)
- [UID:00026J][0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062d02c-0x0062d418.SpellInventoryMacroReadOnlyData.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag even though it contained earlier vtable inventory. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:84` and `CONFIDENCE:88`. This is justified by current IDA MCP verification of the decorated vtable/RTTI globals, slot values, constructor/destructor xrefs, and read-only data boundaries. The score remains below the 95+ final-audit gate because exact source declarations, class layouts, and every called helper name are not yet fully reconstructed.
