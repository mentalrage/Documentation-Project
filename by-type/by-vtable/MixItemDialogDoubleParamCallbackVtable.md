*** UID:0003IH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000041 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000041 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MixItemDialog Double-Param Callback Vtable

## Status

- Current role: source-local by-vtable page for the `DoubleParamMemberFunctionObject<...MixItemDialog...>` callback-template vtable.
- Direct owner: [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md).
- Source context: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), with construction sites in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Mixed source page: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Backing memory neighborhood: [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md).

## Layout

The exact callback-template vtable record at `0x0061a3ac-0x0061a3c4` is `0x18` bytes / decimal 24 bytes. It starts at the complete-object locator dword and covers the callback vtable through the added shared-helper tail slot before the FieldMapPane COL successor.

| Field | Address | Meaning |
| --- | --- | --- |
| Locator | `0x0061a3ac` | Complete-object locator for `DoubleParamMemberFunctionObject<...MixItemDialog...>`. |
| Slot 0 | `0x0061a3b0 -> 0x0049b090` | Destructor/base callback support slot. |
| Slot 1 | `0x0061a3b4 -> 0x004f4b10` | Shared function-object support slot. |
| Slot 2 | `0x0061a3b8 -> 0x0041b6c0` | Shared default/support slot. |
| Slot 3 | `0x0061a3bc -> 0x004b0880` | `MixItemDialog` double-param invoke wrapper. |
| Slot 4 | `0x0061a3c0 -> 0x004673f0` | Additional shared callback/helper slot identified by B001-00025A; successor `FieldMapPane` COL begins at `0x0061a3c4`. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` reconfirmed this page's direct callback-template ownership:

- `entity_query` reports `??_7?$DoubleParamMemberFunctionObject@P8MixItemDialog@@AEXKCE@ZV1@CE@@6B@` at `0x0061a3b0` and successor `??_7FieldMapPane@@6B@` at `0x0061a3c8`.
- `lookup_funcs` reports slot targets `0x0049b090` size `0x3e`, `0x004f4b10` size `0x06`, and invoke wrapper `0x004b0880` size `0x21`.
- `trace_data_flow backward 0x0061a3b0` reports construction stores at `0x004afd62` in `MixItemDialog` quantity-prompt code and `0x004b0370` in `AddMixingItemDialog` confirm code.
- `trace_data_flow backward 0x0061a3bc` confirms the invoke slot dword `0x004b0880`; the wrapper body is documented by [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md).
- B001-00025A rechecked `0x0061a3c0` and found it is an in-record tail slot pointing to `0x004673f0`; `0x0061a3c4` is the `FieldMapPane` COL pointer and `0x0061a3c8` is the named FieldMapPane vtable base, so this page ends at `0x0061a3c4`.
- B001-00025A updates the exact callback record to `0x0061a3ac-0x0061a3c4`; the previous `0x0061a3ac-0x0061a3c0` signature omitted the tail slot.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md). The child is `88/92` and the direct callback-template parent is `85/88`, so both sides clear the strict `85/85` gate. This vtable should not be attached directly to `MixItemDialog`; `MixItemDialog` owns the construction sites, while the template class owns the vtable declaration shape.

## Cross-References

- [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)

## Changes

- 2026-06-12 A004 Batch 324:
  - Created as the exact source-local callback-template vtable child split from [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
  - Evidence: live IDA MCP reconfirmed decorated callback vtable name, slot target sizes, construction stores, invoke slot, successor neighborhood, and a unique exact-range signature.
