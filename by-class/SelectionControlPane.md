*** UID:0000CR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelectionControlPane

## Status

- Confidence: strong for the recovered method, field offset, and generic button-control parent; medium-high for final original class/file naming.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Exact memory: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Field docs: [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- Current recovered file: `source-3/simroot_v2/class_SelectionControlPane.cpp`

## Class Purpose

`SelectionControlPane` is currently represented by one tiny helper that stores a selected value and triggers redraw. The known direct caller is [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md), which uses it to flip the pause/play control art between frame ids `37` and `48`.

Treat this as a generic button/choice-control helper, not as music-dialog-owned code. The current generated one-class file is useful evidence but probably not an original source-file boundary.

[UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is now a validated parent candidate with `NexusTK/ui/controls/` projection and confidence above the attachment gate. This class attaches there as a small helper/declaration within the generic button/choice-control family, not as evidence for a standalone `SelectionControlPane.cpp`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetSelectionAndRefresh` | [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) | Stores selection value at `+0x10c` and tail-calls vtable slot `+0x20` with redraw argument `0`. |

## Evidence Notes

- Wave3 effective grade is 94.0 with only one recovered range and no constructor/vtable inventory.
- 2026-05-26 IDA MCP reports `0x00495cb0` as a real `0x19` function.
- IDA MCP reports one direct xref to `0x00495cb0` from `0x0052a1e2`, inside `MusicControlDialog::TogglePauseState`.
- IDA MCP disassembly confirms the selected value write at `[ecx+0x10c]` and the tail-call through `[vtable+0x20]`.
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) records this helper under the reusable button/choice-control source family and documents the same 2026-05-26 IDA recheck.
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) places this exact method in the local image-button/selection-control band while excluding adjacent progress, numeric-string, rectangle, and checkbox ranges.
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md) records the source-level field/layout implication for `+0x10c`.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) because the class is source-owned generic control support and both child and parent confidence are above 80.
- `RECONSTRUCTION_CPP CODE` stays blank. The exact method and field are well understood, but the final class declaration, vtable slot name, and whether this was a tiny helper class or folded into an image/choice-control declaration are still below the 95+ code gate.
- Do not move this to `MusicControlDialog`: that dialog is the only known caller, but the helper body is generic state/redraw control logic.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the only recovered method has IDA-confirmed boundaries, caller, field offset, and shared button-control context; completion stays limited because constructor/vtable inventory and final class/file ownership remain unresolved.
- 2026-06-03: Raised to `80/84`, set `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: the ButtonControlPane file page has confidence above 80 and a valid `NexusTK/ui/controls/` projection; [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md), [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md), and [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md) document exact method, aggregate, and field evidence. C++ remains blank below the final-source gate.
