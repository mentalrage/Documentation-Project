*** UID:0000CR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelectionControlPane : public ImageButtonControlPane
{
public:
    void SetSelectionAndRefresh(int selectedValue);

private:
    int m_selectedValue; // +0x10c, selected image/frame/value id
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelectionControlPane

## Status

- Confidence: strong for the recovered method, field offset, caller-side values, and generic button-control parent; medium-high for final original class/file naming.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Exact memory: [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Field docs: [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- Caller-side evidence: [UID:0003ML][0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState](by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md)
- Current recovered file: `source-3/simroot_v2/class_SelectionControlPane.cpp`

## Class Purpose

`SelectionControlPane` is currently represented by one tiny helper that stores a selected value and triggers redraw. The known direct caller is [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md), which uses it to flip the pause/play control art between frame ids `37` / `0x25` (Verified with int_convert.py) and `48` / `0x30` (Verified with int_convert.py).

Treat this as a generic button/choice-control helper, not as music-dialog-owned code. The current generated one-class file is useful evidence but probably not an original source-file boundary.

[UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is now a validated parent candidate with `NexusTK/ui/controls/` projection and confidence above the attachment gate. This class attaches there as a small helper/declaration within the generic button/choice-control family, not as evidence for a standalone `SelectionControlPane.cpp`.

2026-06-30 B010 implementation callback promotes the previous no-code state into a minimal formal declaration plus `[[CHILDREN]]`. The `ImageButtonControlPane` base name remains an inference from the adjacent image-button constructor family and route shape, not a proven original symbol, but it is the best current source-facing model. Current MCP `analyze_function 0x00495cb0` proves the only recovered body writes `[ecx+0x10c]` and tail-calls vtable slot `+0x20`; the class declaration owns the `m_selectedValue` field and exact method child.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetSelectionAndRefresh` | [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md) | Stores selection value at `+0x10c` and tail-calls vtable slot `+0x20` with redraw argument `0`. |

## Field Notes

| Offset | Source-level role | Evidence |
| --- | --- | --- |
| `+0x10c` | Selected value/frame id for this helper's control instance. | [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md) records the exact write and the MusicControlDialog pause/play values. |

The `+0x10c` offset is class-local in this documentation. A 2026-06-13 C001 IDA listing search over the broader [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) range found many `+0x10c` references with different meanings in sibling controls, including a `TextButtonExControlPane` child-provider pointer. This class page only claims the selected-value role for the exact `SelectionControlPane` setter.

## Evidence Notes

- Wave3 effective grade is 94.0 with only one recovered range and no constructor/vtable inventory.
- 2026-05-26 IDA MCP reports `0x00495cb0` as a real `0x19` function.
- IDA MCP reports one direct xref to `0x00495cb0` from `0x0052a1e2`, inside `MusicControlDialog::TogglePauseState`.
- IDA MCP disassembly confirms the selected value write at `[ecx+0x10c]` and the tail-call through `[vtable+0x20]`.
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) records this helper under the reusable button/choice-control source family and documents the same 2026-05-26 IDA recheck.
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) places this exact method in the local image-button/selection-control band while excluding adjacent progress, numeric-string, rectangle, and checkbox ranges.
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md) records the source-level field/layout implication for `+0x10c`.
- 2026-06-13 C001 live IDA 9.1 MCP `lookup_funcs` reconfirmed `sub_495CB0` at `0x00495cb0` with size `0x19`, no function at the preceding `0x00495ca5` endpoint, and `sub_495CD0` as the successor at `0x00495cd0`.
- 2026-06-13 C001 MCP `analyze_function 0x00495cb0` reconfirmed the exact one-basic-block body, `this[67] = a2`, the `mov [ecx+10Ch], eax` write, zero normal callees, and sole caller `sub_52A180`.
- 2026-06-13 C001 MCP `analyze_function 0x0052a180` reconfirmed `TogglePauseState` fetches control id `12`, selects `0x25` or `0x30`, moves the target control into `ecx`, and calls `sub_495CB0` at `0x0052a1e2`.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) because the class is source-owned generic control support and both child and direct file parent now clear the strict `85/85` gate.
- `RECONSTRUCTION_CPP CODE` now contains the accepted first-draft class shape. The exact original spelling of `SelectionControlPane`, `SetSelectionAndRefresh`, and `m_selectedValue` remains inferred, but the declaration is source-quality enough to carry the proven field and method route while preserving the caveat that the final original split may have folded this helper into a broader image/choice-control declaration.
- Do not move this to `MusicControlDialog`: that dialog is the only known caller, but the helper body is generic state/redraw control logic.
- Score rationale: `85/87` reflects exact method, field, caller, and source-family evidence plus an explicit offset-reuse caveat. It stays below final-source quality because no constructor, independent vtable block, or final class declaration has been proven.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
- [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md)
- [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md)
- [UID:0003ML][0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState](by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `68`, confidence `76`.
- Evidence: the only recovered method has IDA-confirmed boundaries, caller, field offset, and shared button-control context; completion stays limited because constructor/vtable inventory and final class/file ownership remain unresolved.
- 2026-06-03: Raised to `80/84`, set `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: the ButtonControlPane file page has confidence above 80 and a valid `NexusTK/ui/controls/` projection; [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md), [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md), and [UID:0001SV][SelectionControlPaneSelectedValue_0x10c](by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md) document exact method, aggregate, and field evidence. C++ remains blank below the final-source gate.
- 2026-06-13 C001 parent-gate pass:
  - Raised from `80/84` to `85/87`.
  - Evidence: live IDA 9.1 MCP reconfirmed the exact setter body, caller, constants, and boundary padding; the target field page now documents why `+0x10c` is scoped to this helper despite offset reuse in sibling controls. The direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) was already `86/88`, so the class now clears the strict child/direct-parent gate while final C++ remains withheld.
