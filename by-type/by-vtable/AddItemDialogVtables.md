*** UID:0003ID | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000007 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000007 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddItemDialog Vtables

## Status

- Current role: source-local by-vtable page for the `AddItemDialog` primary, secondary, and tertiary dialog views.
- Direct owner: [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Source context: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Mixed source page: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Backing memory neighborhood: [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md).

## Layout

The exact `AddItemDialog` vtable cluster at `0x00619e88-0x00619f24` is `0x9c` bytes / decimal 156 bytes (Verified with int_convert.py). It starts at the primary complete-object locator dword and ends before the `MyItemListPane` locator at `0x00619f24`.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x00619e88` | `0x00619e8c` | slot `+0x00 -> 0x004b0910` scalar deleting destructor; action slot `0x00619ed4 -> 0x004ae930`; virtual updater slot `0x00619ed8`, relative `+0x4c -> 0x004aea40` UID0004BP. |
| Secondary | `0x00619ee8` | `0x00619eec` | slot `+0x00 -> 0x004b08a1`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py); packet-close slot `0x00619efc -> 0x004aea80`. |
| Tertiary | `0x00619f18` | `0x00619f1c` | slot `+0x00 -> 0x004b08ac`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); shared/default slot `0x00619f20 -> 0x00544e90`. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed this page's direct class ownership:

- `entity_query` over `0x00619e80-0x0061a3d0` reports `??_7AddItemDialog@@6B@` at `0x00619e8c`, `??_7AddItemDialog@@6B@_0` at `0x00619eec`, `??_7AddItemDialog@@6B@_1` at `0x00619f1c`, and the successor `MyItemListPane` locator/table at `0x00619f24/0x00619f28`.
- `lookup_funcs` reports scalar deleting destructor `0x004b0910` size `0x5f`, secondary adjustor `0x004b08a1` size `0x0b`, and tertiary adjustor `0x004b08ac` size `0x0b`.
- `trace_data_flow backward 0x00619e8c` reports vptr stores at `0x004ae500`, `0x004ae900`, `0x004b0916`, and `0x004b0976`.
- Existing slot-level audit in [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) records the secondary and tertiary store refs at `0x004ae509`/`0x004ae513`, destructor/reset refs, action slot, and packet-close slot.
- Constructor stores install the three views at `0x004ae500`, `0x004ae509`, and `0x004ae513`. Ordinary destructor/reset stores occur at `0x004ae900`, `0x004ae906`, and `0x004ae910`; scalar-deleting wrapper copies occur at `0x004b0916`, `0x004b091c`, and `0x004b0926`. These stores generate binary vptr mechanics and do not become handwritten source assignments.
- Primary cell `0x00619ed8 -> 0x004aea40` proves [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) is a virtual AddItemDialog method. The body resolves action control 1 and scroll wrapper 3, calls ListPane integer selection count, and tail-dispatches Enable/Disable without null checks.
- Derived-route comparison: AddEmployee cell `0x00619120` and AddMixing cell `0x0061a170` inherit `0x004aea40`; AddItemWithCount cell `0x0061a038` instead points to its own override at `0x004af480`. The latter is an override exclusion, not an alternate owner for UID0004BP.
- No ordinary code xref is expected for UID0004BP because dynamic entry is through the vtable and generic DialogPane refresh wrapper `0x0049fe20`. No raw vtable bytes should be emitted as source; the class declaration carries `virtual void UpdateActionButton()`.
- `trace_data_flow backward 0x00619f24` reports only the `MyItemListPane` RTTI locator dword, proving this cluster ends before the neighboring class.
- `make_signature_for_range 0x00619e88-0x00619f24` returned a unique byte signature for the exact cluster.

## Assignment Gate

Canonical owner/emitter is [UID:000007][AddItemDialog](by-class/AddItemDialog.md). This vtable page is `90/93` and the direct class parent is `91/93`; both support the current class route. The broader [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) stays a non-emitting mixed index because it also contains sibling dialog and callback-template tables.

## Cross-References

- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)

## Changes

- 2026-07-13 B005 UID0004BP callback: raised `88/92` to `90/93`; added missing primary `+0x4c` updater cell, exact constructor/destructor/wrapper store inventory, class-declaration consequence, AddEmployee/AddMixing inheritance, AddItemWithCount override exclusion, virtual-only refresh route, and no-raw-vtable source disposition while preserving owner/emitter and the blank formal block.

- 2026-06-12 A004 Batch 324:
  - Created as the exact source-local `AddItemDialog` vtable child split from [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
  - Evidence: live IDA MCP reconfirmed decorated bases, slot target sizes, primary lifecycle stores, the `MyItemListPane` successor boundary, and a unique exact-range signature.
