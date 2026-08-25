*** UID:0003IE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000008 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000008 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddItemWithCountDialog Vtables

## Status

- Current role: source-local by-vtable page for the `AddItemWithCountDialog` primary, secondary, and tertiary dialog views.
- Direct owner: [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md).
- Source context: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Mixed source page: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Backing memory neighborhood: [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md).

## Layout

The exact `AddItemWithCountDialog` vtable cluster at `0x00619fe8-0x0061a084` is `0x9c` bytes / decimal 156 bytes (Verified with int_convert.py). It starts at the primary complete-object locator dword and ends before the `MixItemDialog` locator at `0x0061a084`.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x00619fe8` | `0x00619fec` | slot `+0x00 -> 0x0047eaf0` inherited/scalar destructor path; `+0x48`, cell `0x0061a034 -> 0x004af380`, is [UID:0004BR][0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand](by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md) `void OnControlCommand(int,int)`; `+0x4c`, cell `0x0061a038 -> 0x004af480`, is class-specific [UID:0004BS][0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton](by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md). |
| Secondary | `0x0061a048` | `0x0061a04c` | slot `+0x00 -> 0x0047e8d9`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py); EventHandler `+0x10`, cell `0x0061a05c -> 0x004af4c0`, is [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md). |
| Tertiary | `0x0061a078` | `0x0061a07c` | slot `+0x00 -> 0x0047e8e4`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); shared/default slot `0x0061a080 -> 0x00544e90`. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` reconfirmed this page's direct class ownership:

- `entity_query` reports `??_7AddItemWithCountDialog@@6B@` at `0x00619fec`, `??_7AddItemWithCountDialog@@6B@_0` at `0x0061a04c`, `??_7AddItemWithCountDialog@@6B@_1` at `0x0061a07c`, and successor `MixItemDialog` locator/table at `0x0061a084/0x0061a088`.
- `lookup_funcs` reports slot targets `0x0047eaf0` size `0x3b`, `0x0047e8d9` size `0x0b`, and `0x0047e8e4` size `0x0b`.
- Existing class and family audits record constructor stores at `0x004af0ae`, `0x004af0b4`, and `0x004af0be`, control-command/updater refs at `0x0061a034/0x0061a038`, and EventHandler packet-event ref `0x0061a05c`.
- Cell `0x0061a038 -> 0x004af480` is the AddItemWithCount-specific `UpdateActionButton` override. It occupies the same conceptual primary `+0x4c` slot as AddItemDialog cell `0x00619ed8 -> 0x004aea40`, but must not be routed to UID0004BP.
- Generic DialogPane refresh wrapper `0x0049fe20` dispatches the current receiver's `+0x4c` slot; AddItemWithCount receivers therefore execute `0x004af480`. This override distinction changes no score, owner, route, or formal block here.
- No AddItemWithCountDialog vtable slot points to retained helper `0x004af4f0`. Primary `+0x48` points to live UID0004BR `OnControlCommand`, and secondary `+0x10` points to UID000318 `HandlePacketEvent`; this is direct negative evidence against emitting the no-route retained helper as another virtual.
- `trace_data_flow backward 0x0061a084` reports only the `MixItemDialog` RTTI locator dword, proving this cluster ends before the neighboring class.
- `make_signature_for_range 0x00619fe8-0x0061a084` returned a unique byte signature for the exact cluster.

## Assignment Gate

Canonical owner/emitter is [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md). This vtable page remains `88/92`, the direct class parent is `91/93`, and the broader family page remains a non-emitting mixed index. Formal C++ stays blank because these tables, RTTI locators, vptr stores, and adjustor thunks are compiler output generated from the class declarations.

## Cross-References

- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md)
- [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md)
- [UID:0004BR][0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand](by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md)
- [UID:0004BS][0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton](by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)

## Changes

- 2026-07-13 UID0004BQ vtable sync: score/owner/emitter/range/blank formal unchanged; named primary `+0x48` as UID0004BR `OnControlCommand`, primary `+0x4c` as B002-owned UID0004BS updater, and secondary `+0x10` as UID000318 `HandlePacketEvent`; preserved RTTI, compiler adjustor/no-code proof, retained-helper negative route, and exact successor boundary.

- 2026-07-13 B005 UID0004BP support sync: score, owner/emitter, exact range, blank formal block, and all existing slot/boundary evidence remain unchanged; added class-specific primary `+0x4c` cell `0x0061a038 -> 0x004af480`, generic refresh consequence, and explicit exclusion from UID0004BP inheritance.

- 2026-06-12 A004 Batch 324:
  - Created as the exact source-local `AddItemWithCountDialog` vtable child split from [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
  - Evidence: live IDA MCP reconfirmed decorated bases, slot target sizes, constructor/slot refs from existing audits, the `MixItemDialog` successor boundary, and a unique exact-range signature.
- 2026-06-19 B011 retained-helper route note:
  - Score unchanged. Added negative-route evidence for [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md): the vtable routes the action handler and packet-close handler, but no slot points to the retained submit helper body.
