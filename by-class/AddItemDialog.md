*** UID:000007 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddItemDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_AddItemDialog.cpp`

## Class Purpose

`AddItemDialog` is the base modal item-selection dialog used by exchange-style workflows. It creates a [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) player-inventory picker, supports high-resolution and low-resolution layouts, handles action buttons, and updates button availability from the selected item state.

## Class Shape

- Base class: dialog pane family with three vfptr views at object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Primary child control: [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), wrapped by a scrollable pane.
- Layout mode: branches on the client display mode byte to build high-resolution and low-resolution resource layouts.
- Owner/context field: generated source places an owner/context value near the tail of the object; exact final field name is still provisional.
- Source placement: reusable item picker code belongs in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), not exchange/session or inventory-pane source.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemDialog` | `0x004ae4c0-0x004ae8f4` | Builds item-selection layout and list controls. |
| `~AddItemDialog` | `0x004ae900-0x004ae928` | Destroys dialog-specific state. |
| `OnButtonClick` | `0x004ae930-0x004aea39` | Handles OK/cancel/list actions. |
| `UpdateActionButtonState` | `0x004aea40-0x004aea7c` | Enables or disables the action button based on selection state. |
| `virt_meth_0x4b08a1` | `0x004b08a1-0x004b08ab` | Small adjustor/destructor thunk currently attached by Wave3. |
| `AdjustorThunk_ScalarDeletingDestructor` | `0x004b08ac-0x004b08b6` | Small adjustor thunk into delete path. |
| `ScalarDeletingDestructor` | `0x004b0910-0x004b096e` | Runs destructor path and optional free. |

## Evidence Notes

- Wave3 summary identifies this as a modal item-add dialog with high-res and low-res layouts.
- IDA MCP confirms all listed function starts, including the 0xb-byte thunks.
- IDA MCP reports `MyItemListPane` constructor calls inside this constructor at `0x004ae63e` and `0x004ae7f0`.
- IDA MCP vtable checks confirm table bases at `0x00619e8c`, `0x00619eec`, and `0x00619f1c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- This is item-selection UI and should not be merged into item inventory panes or item image libraries.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)

## Changes

- What existed before: the page had strong evidence but metadata remained `0/0`, and the class-level layout/source-placement summary was implicit in evidence bullets.
- What it was changed to: scores were set to `72/86`, and a class-shape section now records base/vfptr layout, child picker ownership, layout branching, and final source placement.
- Summary and evidence: existing IDA MCP function/vtable checks and `simroot_v2/class_AddItemDialog.cpp` support strong confidence, while unresolved exact field naming keeps completion below high.
