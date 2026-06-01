*** UID:00008J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MixItemDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MixItemDialog.cpp`

## Class Purpose

`MixItemDialog` is the item-mixing UI. It assembles selected inventory items, uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) for player item selection, supports add/remove actions, and submits the completed mix request packet to the server.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MixItemDialog` | `0x004af570-0x004af8ae` | Builds the mix-item dialog and selected-item controls. |
| `HandleAction` | `0x004af8b0-0x004afb64` | Dispatches add/remove/submit/cancel actions. |
| `virt_meth_0x4b08f9` | `0x004b08f9-0x004b0903` | Small thunk currently attached by Wave3. |
| `ScalarDeletingDestructorThunk` | `0x004b0904-0x004b090e` | Small deleting-destructor thunk. |
| `ScalarDeletingDestructor` | `0x004b0ad0-0x004b0b14` | Runs destruction and optional free. |

## Evidence Notes

- Wave3 summary identifies selected-item assembly, add/remove actions, and mix-packet submission.
- IDA MCP confirms constructor/action/destructor function starts and the small thunk starts.
- IDA MCP reports a `MyItemListPane` constructor call at `0x004af7a7` inside the mix dialog constructor.
- IDA MCP vtable checks confirm dialog table bases at `0x0061a088`, `0x0061a0e8`, and `0x0061a118`, plus the double-param callback vtable at `0x0061a3b0`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- `AddMixingItemDialog` stores a pointer back to this dialog and filters available items against the current mix list.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the item-mixing dialog has clear source placement, constructor/action/destructor boundaries, selected-item/list-pane behavior, double-param callback reference, and related dialog ownership, but exact packet/layout internals are not fully expanded here. Evidence: linked `ItemExchangeMixDialogs` range, IDA-confirmed starts and vtable checks, `MyItemListPane` constructor call, `AddMixingItemDialog` relationship, and mix-packet submission summary.
