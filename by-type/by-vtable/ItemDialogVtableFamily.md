*** UID:0001XV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Item Dialog Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), with [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) quantity-callback support.
- Confidence: strong for table bases, constructor/store xrefs, callback table ownership, key action slots, and source-family placement; medium for inherited slot naming and final source-level virtual declarations.
- Evidence basis: IDA MCP `list_globals` and vtable xref checks on 2026-05-26, IDA MCP `py_eval`/`list_globals` recheck on 2026-05-31, plus current `simroot_v2` metadata checks only as a generated-data issue lead.

## Dialog Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:000007][AddItemDialog](by-class/AddItemDialog.md) | `0x00619e8c` | `0x00619eec` | `0x00619f1c` | Constructor stores at `0x004ae500`, `0x004ae509`, and `0x004ae513`; destructor/reset stores at `0x004ae900`, `0x004ae906`, `0x004ae910`, `0x004b0916`, `0x004b091c`, `0x004b0926`, `0x004b0976`, `0x004b097c`, and `0x004b0986`. |
| [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md) | `0x00619fec` | `0x0061a04c` | `0x0061a07c` | Constructor stores at `0x004af0ae`, `0x004af0b4`, and `0x004af0be`. |
| [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) | `0x0061a088` | `0x0061a0e8` | `0x0061a118` | Constructor stores at `0x004af5ee`, `0x004af5f4`, and `0x004af5fe`. |
| [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) | `0x0061a124` | `0x0061a184` | `0x0061a1b4` | Stores at `0x004b0039`, `0x004b003f`, and `0x004b0049`; `MixItemDialog::HandleAction` also installs these tables at `0x004af929`, `0x004af92f`, and `0x004af939` after constructing the base picker path. |

## Callback Table

| Template instance | Vtable | Store/xref evidence | Notes |
| --- | --- | --- | --- |
| [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | `0x0061a3b0` | Construction stores at `0x004afd62` and `0x004b0370`; invoke slot data ref at `0x0061a3bc` points to `0x004b0880`. | The callback is built by mix quantity paths and passed to [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md). Keep it with function-object/template support while cross-referencing item mixing. |

## Slot Boundary Notes

- The dialog classes use the same three-view layout seen across `DialogPane`-derived UI: primary vfptr at `+0x00`, secondary view at `+0xa0`, and tertiary/event view at `+0xa4`.
- `AddItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0910`; the secondary/tertiary first slots point to adjustor thunks `0x004b08a1` and `0x004b08ac`.
- `AddItemDialog` secondary-view packet slot at data ref `0x00619efc` points to [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), a vtable-only handler for exchange packet bytes `0x42/0x04`.
- `AddItemWithCountDialog` secondary-view packet slot at data ref `0x0061a05c` points to [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md), the quantity-aware dialog's equivalent packet-close handler.
- `AddMixingItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0970`; secondary/tertiary first slots point to adjustor thunks `0x004b08b7` and `0x004b08c2`.
- `MixItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0ad0`; secondary/tertiary first slots point to adjustor thunks `0x004b08f9` and `0x004b0904`.
- Do not over-extend short secondary or tertiary tables into the next class: `MyItemListPane`, `MixItemDialog`, `AddMixingItemDialog`, `ExchangeAlertPane`, and `FieldMapPane` RTTI/table data follow nearby in `.rdata`.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked item dialog class even though IDA confirms the bases listed above:

`AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and `AddMixingItemDialog`.

The active generated `.cpp` files may still install placeholder vtable symbols in constructor bodies, but source reconstruction should use the IDA-backed bases and store xrefs on this page until generated metadata catches up.

## Current IDA Recheck

2026-05-31 IDA MCP `py_eval` walked the listed dialog vtable triples and callback table using IDA names, dword reads, function containment, and data xrefs. The pass confirmed:

- all four dialog classes have the documented three-view MSVC vtable layout with decorated names at the primary, secondary `+0xa0`, and tertiary `+0xa4` bases;
- the first slots resolve to the documented scalar deleting destructors or adjustor thunks, including `0x004b0910` for `AddItemDialog`, `0x0047eaf0` for `AddItemWithCountDialog`, `0x004b0ad0` for `MixItemDialog`, and `0x004b0970` for `AddMixingItemDialog`;
- primary `+0x48` slots point to the class-specific action paths: `0x004ae930`, `0x004af380`, `0x004af8b0`, and `0x004b0120`;
- secondary first slots and tertiary first slots point to the expected compiler adjustor thunks or inherited dialog-pane thunks, while tertiary `+0x04` points to shared default/update helper `0x00544e90`;
- constructor/destructor/store xrefs match the rows above, including `AddItemDialog` destructor/reset stores and `MixItemDialog::HandleAction` installing `AddMixingItemDialog` tables;
- `0x0061a3b0` is the `DoubleParamMemberFunctionObject<...MixItemDialog...>` vtable, with construction stores at `0x004afd62` and `0x004b0370` and invoke slot `0x0061a3bc -> 0x004b0880`.

2026-06-08 Batch 116 adds exact child pages for two vtable-only packet handlers and two MixItemDialog quantity helpers. IDA MCP confirms the packet handler data refs at `0x00619efc` and `0x0061a05c`, and the callback object stores that target [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) before dispatch through the callback vtable family.

## Reconstruction Notes

Use this page as the layout anchor for the item-picker and mix-dialog source pass. The vtable stores reinforce a compact original module around reusable item selection (`AddItemDialog`, `AddItemWithCountDialog`, `MyItemListPane`) plus a nearby mix-dialog file or section (`MixItemDialog`, `AddMixingItemDialog`). `AddEmployeeItemDialog` is a derived employee-specific reuse case and should remain with [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), not treated as generic item-dialog ownership evidence.

The adjustor thunks are compiler-generated layout glue. Final source should model the C++ inheritance/destructor layout rather than porting the tiny thunk functions as handwritten item-dialog methods.

`AUTOGEN_PARENT_UID` remains blank for this vtable family. The page now clears `86/89`, but it is a type/layout inventory spanning concrete item-dialog class tables and the MixItemDialog callback-template table; the exact memory children attach to their concrete class/file parents instead of routing the whole vtable family to one source parent.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogExchangePacketCloseHandler.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-05-31 - Scored IDA-verified item-dialog vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank even though it contained a structured vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because inherited virtual names, callback declaration spelling, and final source-level declarations are not final-audit complete.
- Evidence: IDA MCP `py_eval` and `list_globals` on 2026-05-31 confirmed the decorated vtable names, first/action slots, adjustor slots, constructor/destructor/store xrefs, callback table target, and nearby non-owned boundaries.

### 2026-06-08 - Batch 116 packet-slot refresh

- Before: `COMPLETION:84`, `CONFIDENCE:88`; the family inventory had the major vtable bases but not the exact new packet-close child pages.
- Changed to: `COMPLETION:86`, `CONFIDENCE:89`; added the exact AddItemDialog and AddItemWithCountDialog packet handler slot refs plus the MixItemDialog quantity callback target relationship.
- Evidence: current IDA MCP confirms vtable/data refs at `0x00619efc`, `0x0061a05c`, callback vtable `0x0061a3b0`, and callback target stores for [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md). The family stays unassigned because it is a layout/type inventory, not one direct source owner.
