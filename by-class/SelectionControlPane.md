*** UID:0000CR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectionControlPane

## Status

- Confidence: strong for the recovered method and field offset, medium for final original class/file naming.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Exact memory: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Field docs: [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- Current recovered file: `source-3/simroot_v2/class_SelectionControlPane.cpp`

## Class Purpose

`SelectionControlPane` is currently represented by one tiny helper that stores a selected value and triggers redraw. The known direct caller is [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md), which uses it to flip the pause/play control art between frame ids `37` and `48`.

Treat this as a generic button/choice-control helper, not as music-dialog-owned code. The current generated one-class file is useful evidence but probably not an original source-file boundary.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetSelectionAndRefresh` | [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) | Stores selection value at `+0x10c` and tail-calls vtable slot `+0x20` with redraw argument `0`. |

## Evidence Notes

- Wave3 effective grade is 94.0 with only one recovered range and no constructor/vtable inventory.
- 2026-05-26 IDA MCP reports `0x00495cb0` as a real `0x19` function.
- IDA MCP reports one direct xref to `0x00495cb0` from `0x0052a1e2`, inside `MusicControlDialog::TogglePauseState`.
- IDA MCP disassembly confirms the selected value write at `[ecx+0x10c]` and the tail-call through `[vtable+0x20]`.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the only recovered method has IDA-confirmed boundaries, caller, field offset, and shared button-control context; completion stays limited because constructor/vtable inventory and final class/file ownership remain unresolved.
