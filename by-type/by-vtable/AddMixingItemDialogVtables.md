*** UID:0003IF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000009 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000009 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddMixingItemDialog Vtables

## Status

- Current role: source-local by-vtable page for the `AddMixingItemDialog` primary, secondary, and tertiary dialog views.
- Direct owner: [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md).
- Source context: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Mixed source page: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Backing memory neighborhood: [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md).

## Layout

The exact `AddMixingItemDialog` vtable cluster at `0x0061a120-0x0061a1bc` is `0x9c` bytes / decimal 156 bytes (Verified with int_convert.py). It starts at the primary complete-object locator dword and ends before the `ExchangeAlertPane` locator at `0x0061a1bc`.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x0061a120` | `0x0061a124` | slot `+0x00 -> 0x004b0970` scalar deleting destructor; action slot `0x0061a16c -> 0x004b0120`; inherited updater slot `0x0061a170`, relative `+0x4c -> 0x004aea40`. |
| Secondary | `0x0061a180` | `0x0061a184` | slot `+0x00 -> 0x004b08b7`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py); inherited/no-op slot `0x0061a194 -> 0x0041d6b0`. |
| Tertiary | `0x0061a1b0` | `0x0061a1b4` | slot `+0x00 -> 0x004b08c2`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); shared/default slot `0x0061a1b8 -> 0x00544e90`. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` reconfirmed this page's direct class ownership:

- `entity_query` reports `??_7AddMixingItemDialog@@6B@` at `0x0061a124`, `??_7AddMixingItemDialog@@6B@_0` at `0x0061a184`, `??_7AddMixingItemDialog@@6B@_1` at `0x0061a1b4`, and successor `ExchangeAlertPane` locator/table at `0x0061a1bc/0x0061a1c0`.
- `lookup_funcs` reports scalar deleting destructor `0x004b0970` size `0x5f`, secondary adjustor `0x004b08b7` size `0x0b`, and tertiary adjustor `0x004b08c2` size `0x0b`.
- `trace_data_flow backward` reports inline `MixItemDialog::HandleAction` stores at `0x004af929`, `0x004af92f`, and `0x004af939`, and standalone constructor stores at `0x004b0039`, `0x004b003f`, and `0x004b0049`.
- `trace_data_flow backward 0x0061a1bc` reports only the `ExchangeAlertPane` RTTI locator dword, proving this cluster ends before the neighboring class.
- `make_signature_for_range 0x0061a120-0x0061a1bc` returned a unique byte signature for the exact cluster.
- Primary cell `0x0061a170 -> 0x004aea40` inherits [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md). The body resolves action control 1 and selector-3 ScrollableControlPane, queries the owned ListPane's integer selection count, and dispatches Enable/Disable without null checks.
- Generic DialogPane refresh wrapper `0x0049fe20` reaches this inherited implementation for dynamic AddMixing receivers. No AddMixing-specific override, raw vtable source array, score change, or owner transfer follows from the shared cell.

## Assignment Gate

Canonical owner/emitter is [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md). The child remains `88/92` and the direct class parent remains `85/88`; the broader family page remains a non-emitting mixed index because it crosses sibling dialog and callback-template ownership.

## Cross-References

- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)

## Changes

- 2026-07-13 B005 UID0004BP support sync: score, owner/emitter, exact range, blank formal block, all constructor/store/RTTI/boundary evidence remain unchanged; added inherited primary `+0x4c` cell `0x0061a170 -> 0x004aea40`, updater behavior, and generic refresh route.

- 2026-06-12 A004 Batch 324:
  - Created as the exact source-local `AddMixingItemDialog` vtable child split from [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
  - Evidence: live IDA MCP reconfirmed decorated bases, slot target sizes, inline and standalone vptr-store sites, the `ExchangeAlertPane` successor boundary, and a unique exact-range signature.
