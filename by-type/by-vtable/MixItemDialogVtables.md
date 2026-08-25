*** UID:0003IG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MixItemDialog Vtables

## Status

- Current role: non-reconstructable, non-emitting inventory for compiler-generated `MixItemDialog` primary, secondary, and tertiary vtable/RTTI views.
- Semantic owner: [UID:00008J][MixItemDialog](by-class/MixItemDialog.md). The class declaration and virtual methods regenerate these tables; this page must not emit manual arrays.
- Source context: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
- Mixed source page: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Backing memory neighborhood: [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md).

## Layout

The exact `MixItemDialog` vtable cluster at `0x0061a084-0x0061a120` is `0x9c` bytes / decimal 156 bytes (Verified with int_convert.py). It starts at the primary complete-object locator dword and ends before the `AddMixingItemDialog` locator at `0x0061a120`.

| View | RTTI / locator | Vtable base | Key slots |
| --- | --- | --- | --- |
| Primary | `0x0061a084` | `0x0061a088` | slot `+0x00 -> 0x004b0ad0` scalar deleting destructor; action slot `0x0061a0d0 -> 0x004af8b0`. |
| Secondary | `0x0061a0e4` | `0x0061a0e8` | slot `+0x00 -> 0x004b08f9`, an adjustor thunk subtracting `0xa0` / decimal 160 (Verified with int_convert.py); inherited/no-op slot `0x0061a0f8 -> 0x0041d6b0`. |
| Tertiary | `0x0061a114` | `0x0061a118` | slot `+0x00 -> 0x004b0904`, an adjustor thunk subtracting `0xa4` / decimal 164 (Verified with int_convert.py); shared/default slot `0x0061a11c -> 0x00544e90`. |

## 2026-06-12 A004 IDA Recheck

Live IDA MCP session `b001_nexustk` reconfirmed this page's direct class ownership:

- `entity_query` reports `??_7MixItemDialog@@6B@` at `0x0061a088`, `??_7MixItemDialog@@6B@_0` at `0x0061a0e8`, `??_7MixItemDialog@@6B@_1` at `0x0061a118`, and successor `AddMixingItemDialog` locator/table at `0x0061a120/0x0061a124`.
- `lookup_funcs` reports scalar deleting destructor `0x004b0ad0` size `0x45`, secondary adjustor `0x004b08f9` size `0x0b`, and tertiary adjustor `0x004b0904` size `0x0b`.
- Existing class and family audits record constructor stores from `0x004af570`, action slot `0x0061a0d0 -> 0x004af8b0`, and the singleton/quantity-helper paths that make this a direct `MixItemDialog` child.
- B009's submit-helper route recheck confirms the action slot points to [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) at `0x004af8b0`, not to the retained submit helper [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md). The live submit case is action case 3 at `0x004afa3a`; the standalone helper has no vtable slot or direct dispatch route.
- `trace_data_flow backward 0x0061a120` reports only the `AddMixingItemDialog` RTTI locator dword, proving this cluster ends before the neighboring class.
- `make_signature_for_range 0x0061a084-0x0061a120` returned a unique byte signature for the exact cluster.

## Assignment Gate

`CANONICAL_OWNER` remains [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) as semantic context. This page is `92/95` and its direct class parent is `91/93`, so both clear the strict gate. `RECONSTRUCTABLE:FALSE`, blank emitters, blank position, and blank formal C++ prevent compiler data from appearing as handwritten source. The callback-template vtable at `0x0061a3b0` remains split separately because its direct source owner is the callback wrapper class/template, not `MixItemDialog` itself.

## RTTI Hierarchy And Constructor Links

- MixItemDialog type descriptor is `0x00676038` (`.?AVMixItemDialog@@`); `Singleton<MixItemDialog>` type descriptor is `0x00676054` (`.?AV?$Singleton@VMixItemDialog@@@@`).
- Primary complete-object locator `0x00647468`, hierarchy descriptor `0x0064747c`, base array `0x0064748c`, MixItemDialog base-class descriptor `0x006474b0`, and Singleton descriptor `0x006474cc` describe eight hierarchy entries: MixItemDialog, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and Singleton.
- Singleton descriptor values `mdisp=0x26c`, `pdisp=-1`, `vdisp=0`, attributes `0x40` prove a direct nonvirtual empty base at the complete-object end. Both callers and the scalar wrapper independently establish complete size `0x26c`.
- Constructor [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md) stores `0x0061a088`, `0x0061a0e8`, and `0x0061a118` at complete-object offsets `+0`, `+0xa0`, and `+0xa4` after base construction.
- The primary deleting slot reaches `[0x004b0ad0,0x004b0b15)`, which clears the Singleton slot, tears down DialogPane, interprets deleting flags, and conditionally frees `0x26c`. Secondary and tertiary entries are compiler adjustors at `0x004b08f9` and `0x004b0904`.
- Action slot `0x0061a0d0 -> 0x004af8b0` reaches the live OnAction body and its inline case-3 serializer. No vtable slot points to retained no-direct-route helper UID00033V.

## Compiler-Generated No-Code Disposition

- Vtable arrays, complete-object locators, base arrays/descriptors, RTTI names, scalar deleting wrappers, and this-adjustor thunks are compiler products of the class declaration, inheritance, and virtual methods.
- The exact formal block remains blank. A handwritten table, RTTI array, placeholder comment, or Empty Emitter Marker would duplicate compiler output and misrepresent source.
- Historical reconstructable/emitter metadata is superseded by the exact source-generation model. The physical data and slots remain fully documented here for audit and layout evidence.
- The `AddMixingItemDialog` locator at `0x0061a120` is the exact successor and is excluded from this page. Callback-template data at `0x0061a3b0` is separately owned and also excluded.

## Score Rationale

`92/95` reflects exact cluster range and size, all three table views, key slots and adjustors, constructor stores, successor boundary, unique signature, complete RTTI hierarchy, Singleton EBO, scalar route, and a resolved compiler-generated no-code disposition. Confidence is capped only because not every inherited slot has an original lexical method name.

## Cross-References

- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)

## Changes

- 2026-06-12 A004 Batch 324:
  - Created as the exact source-local `MixItemDialog` vtable child split from [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
  - Evidence: live IDA MCP reconfirmed decorated bases, slot target sizes, existing constructor/action evidence, the `AddMixingItemDialog` successor boundary, and a unique exact-range signature.
