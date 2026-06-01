*** UID:000009 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddMixingItemDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_AddMixingItemDialog.cpp`

## Class Purpose

`AddMixingItemDialog` is the item picker used by `MixItemDialog`. It derives from `AddItemDialog`, filters out items already present in the mix list, and asks for a quantity when the chosen item is stackable.

## Class Shape

- Base class: [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Owner field: generated notes identify a `MixItemDialog*` owner pointer at object offset `+0x270`.
- Vtable family: primary/secondary/tertiary tables at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`.
- Primary behavior: filtered item picker for [UID:00008J][MixItemDialog](by-class/MixItemDialog.md), followed by stack-quantity prompt or direct add callback.
- Source placement: keep adjacent to `MixItemDialog` and [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddMixingItemDialog` | `0x004b0000-0x004b0115` | Builds a filtered add-item dialog linked to an owning mix dialog. |
| `OnConfirm` | `0x004b0120-0x004b0489` | Confirms selected item; opens quantity input for stackable items and dispatches mix add callback. |
| `virt_meth_0x4b08b7` | `0x004b08b7-0x004b08c1` | Small thunk currently attached by Wave3. |
| `AdjustorThunk` | `0x004b08c2-0x004b08cc` | Small adjustor thunk. |
| `ScalarDeletingDestructor` | `0x004b0970-0x004b09ce` | Runs destruction and optional free. |

## Evidence Notes

- Wave3 notes identify inheritance from `AddItemDialog` and a `m_pMixItemDialog` field at offset `0x270`.
- IDA MCP confirms constructor, confirm handler, destructor, and thunk starts.
- IDA MCP vtable checks confirm table bases at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- The constructor removes items already selected in the parent mix dialog from the available item list.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)

## Changes

- What existed before: the page had method/evidence notes but was still scored as unevaluated.
- What it was changed to: scores were set to `68/84`, and a class-shape section now records base class, owner pointer, vtable anchors, behavior, and source placement.
- Summary and evidence: IDA MCP confirms constructor/confirm/destructor/thunk starts and vtable bases, but detailed field names and final source split with `MixItemDialog` still need more method-level documentation.
