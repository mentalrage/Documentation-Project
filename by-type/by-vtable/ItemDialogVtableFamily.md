*** UID:0001XV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Item Dialog Vtable Family

## Status

- Entity kind: reviewed non-emitting vtable-family index. Source-local reconstructable children now carry the direct routes.
- Covered module: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), with [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) quantity-callback support.
- Confidence: very strong for table bases, constructor/store xrefs, callback table ownership, key action slots, packet-handler slots, RTTI locator adjacency, split boundaries, unique signatures, and source-family placement; medium-high for inherited slot naming and final source-level virtual declarations.
- Evidence basis: IDA MCP `list_globals` and vtable xref checks on 2026-05-26, IDA MCP `py_eval`/`list_globals` rechecks on 2026-05-31 and 2026-06-11, A004 live IDA MCP `entity_query`, `lookup_funcs`, `trace_data_flow`, and `make_signature_for_range` split refresh on 2026-06-12, plus current generated metadata checks only as a generated-data issue lead.

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

## Source-Local Split Pages

This aggregate is not a source-emitting object because it combines four concrete dialog classes with one callback-template vtable. The source-owned vtable documentation is carried by these exact children:

| Child | Direct parent | Exact range | Gate result |
| --- | --- | --- | --- |
| [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md) | [UID:000007][AddItemDialog](by-class/AddItemDialog.md) | `0x00619e88-0x00619f24` | child `90/93`; direct parent `91/93` |
| [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md) | [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md) | `0x00619fe8-0x0061a084` | child `88/92`; direct parent `91/93` |
| [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md) | [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) | `0x0061a084-0x0061a120` | child `89/92`; direct parent `87/88` |
| [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md) | [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) | `0x0061a120-0x0061a1bc` | child `88/92`; direct parent `85/88` |
| [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) | [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md) | `0x0061a3ac-0x0061a3c4` | child `88/92`; direct parent `85/88` |

## Slot Boundary Notes

- The dialog classes use the same three-view layout seen across `DialogPane`-derived UI: primary vfptr at `+0x00`, secondary view at `+0xa0`, and tertiary/event view at `+0xa4`.
- `AddItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0910`; the secondary/tertiary first slots point to adjustor thunks `0x004b08a1` and `0x004b08ac`.
- `AddItemWithCountDialog` primary slot `0x0061a034`, relative `+0x48`, points to [UID:0004BR][0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand](by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md), the exact two-argument `OnControlCommand` override. Selector 1 reads and clamps selector-4 count text, sends opcode `0x4a/2` with the signed inventory slot, then slides and closes; selector 2 only slides and closes.
- AddItemDialog primary updater slot `0x00619ed8`, relative `+0x4c`, points to [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md). AddEmployee `0x00619120` and AddMixing `0x0061a170` inherit that implementation, while AddItemWithCount primary slot `0x0061a038`, also relative `+0x4c`, points to its separate B002-owned [UID:0004BS][0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton](by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md) override. The latter retrieves selectors 1 and 4 and reaches distinct disable/enable tails according to whether the editor is empty.
- `AddItemDialog` secondary-view packet slot at data ref `0x00619efc` points to [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), a vtable-only handler for exchange packet bytes `0x42/0x04`.
- `AddItemWithCountDialog` secondary-view packet slot at data ref `0x0061a05c`, relative `+0x10` from the secondary table, points to [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md). This is the `EventHandler` packet-event override: it reads `event->packet` without a null test, slides and closes only for packet bytes `0x42/0x04`, and returns false on every path. The secondary-this adjustment is compiler ABI glue rather than authored source.
- `AddMixingItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0970`; secondary/tertiary first slots point to adjustor thunks `0x004b08b7` and `0x004b08c2`.
- `MixItemDialog` primary slot `+0x00` points to scalar deleting destructor `0x004b0ad0`; secondary/tertiary first slots point to adjustor thunks `0x004b08f9` and `0x004b0904`.
- Do not over-extend short secondary or tertiary tables into the next class: `MyItemListPane`, `MixItemDialog`, `AddMixingItemDialog`, `ExchangeAlertPane`, and `FieldMapPane` RTTI/table data follow nearby in `.rdata`.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked item dialog class even though IDA confirms the bases listed above:

`AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and `AddMixingItemDialog`.

Historically generated `.cpp` files installed placeholder vtable symbols in constructor bodies. Current source reconstruction instead uses the IDA-backed bases, store xrefs, and source-level class declarations documented here; the compiler owns vptr initialization and no handwritten vtable/table body belongs in this family page.

## Current IDA Recheck

2026-05-31 IDA MCP `py_eval` walked the listed dialog vtable triples and callback table using IDA names, dword reads, function containment, and data xrefs. The pass confirmed:

- all four dialog classes have the documented three-view MSVC vtable layout with decorated names at the primary, secondary `+0xa0`, and tertiary `+0xa4` bases;
- the first slots resolve to the documented scalar deleting destructors or adjustor thunks, including `0x004b0910` for `AddItemDialog`, `0x0047eaf0` for `AddItemWithCountDialog`, `0x004b0ad0` for `MixItemDialog`, and `0x004b0970` for `AddMixingItemDialog`;
- primary `+0x48` slots point to the class-specific action paths: `0x004ae930`, `0x004af380`, `0x004af8b0`, and `0x004b0120`; the AddItemWithCount target at `0x004af380` is specifically `OnControlCommand`, not the stale generic `OnAction` name;
- secondary first slots and tertiary first slots point to the expected compiler adjustor thunks or inherited dialog-pane thunks, while tertiary `+0x04` points to shared default/update helper `0x00544e90`;
- constructor/destructor/store xrefs match the rows above, including `AddItemDialog` destructor/reset stores and `MixItemDialog::HandleAction` installing `AddMixingItemDialog` tables;
- `0x0061a3b0` is the `DoubleParamMemberFunctionObject<...MixItemDialog...>` vtable, with construction stores at `0x004afd62` and `0x004b0370` and invoke slot `0x0061a3bc -> 0x004b0880`.

2026-06-08 Batch 116 adds exact child pages for two vtable-only packet handlers and two MixItemDialog quantity helpers. IDA MCP confirms the packet handler data refs at `0x00619efc` and `0x0061a05c`, and the callback object stores that target [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) before dispatch through the callback vtable family.

2026-06-11 A003 IDA MCP `py_eval` rechecked the concrete slot data and store xrefs:

- `AddItemDialog` primary `0x00619e8c` has RTTI locator `0x00647318`, scalar deleting destructor slot `0x004b0910`, and action slot `0x00619ed4 -> 0x004ae930`; secondary `0x00619eec` has adjustor thunk `0x004b08a1` and packet-close slot `0x00619efc -> 0x004aea80`; tertiary `0x00619f1c` has adjustor thunk `0x004b08ac` and shared update/default slot `0x00619f20 -> 0x00544e90`.
- `AddItemWithCountDialog` primary `0x00619fec` has RTTI locator `0x006473e0`, scalar deleting destructor/inherited slot `0x0047eaf0`, `OnControlCommand` slot `0x0061a034 -> 0x004af380`, and updater slot `0x0061a038 -> 0x004af480`; secondary `0x0061a04c` has inherited adjustor thunk `0x0047e8d9` and `HandlePacketEvent` slot `0x0061a05c -> 0x004af4c0`; tertiary `0x0061a07c` has inherited adjustor thunk `0x0047e8e4` and shared update/default slot `0x0061a080 -> 0x00544e90`.
- `MixItemDialog` primary `0x0061a088` has RTTI locator `0x00647468`, scalar deleting destructor slot `0x004b0ad0`, and action slot `0x0061a0d0 -> 0x004af8b0`; secondary `0x0061a0e8` has adjustor thunk `0x004b08f9` and inherited/no-op slot `0x0061a0f8 -> 0x0041d6b0`; tertiary `0x0061a118` has adjustor thunk `0x004b0904` and shared update/default slot `0x0061a11c -> 0x00544e90`.
- `AddMixingItemDialog` primary `0x0061a124` has RTTI locator `0x00647544`, scalar deleting destructor slot `0x004b0970`, and action slot `0x0061a16c -> 0x004b0120`; secondary `0x0061a184` has adjustor thunk `0x004b08b7` and inherited/no-op slot `0x0061a194 -> 0x0041d6b0`; tertiary `0x0061a1b4` has adjustor thunk `0x004b08c2` and shared update/default slot `0x0061a1b8 -> 0x00544e90`.
- The `DoubleParamMemberFunctionObject<...MixItemDialog...>` callback vtable at `0x0061a3b0` has RTTI locator `0x00647738`, construction stores at `0x004afd62` and `0x004b0370`, destructor/base slots at `0x0049b090` and `0x004f4b10`, and invoke slot `0x0061a3bc -> 0x004b0880`.
- The store xrefs confirm source ownership remains split by concrete class or callback helper: `AddMixingItemDialog` table stores occur both in its constructor at `0x004b0039/0x004b003f/0x004b0049` and in `MixItemDialog::HandleAction` at `0x004af929/0x004af92f/0x004af939`. This is not a single class vtable, so the family page remains an inventory anchor rather than a direct autogen child.

2026-07-13 B005 UID0004BP slot synchronization adds the exact updater relation without changing this mixed index's score or route:

- AddItem `0x00619ed8`, AddEmployee `0x00619120`, and AddMixing `0x0061a170` all point to `0x004aea40` at the primary `+0x4c` slot. The shared body resolves action control 1 and scroll wrapper 3, queries ListPane integer selection count, and dispatches Enable/Disable without null checks.
- AddItemWithCount `0x0061a038 -> 0x004af480` is a class-specific override at the same conceptual slot. It is not an ownership route to the AddItem body.
- Generic DialogPane refresh wrapper `0x0049fe20` reaches whichever dynamic `+0x4c` implementation the current dialog vtable supplies. This explains virtual-only target reachability and does not turn the mixed family index into an emitter.

2026-06-12 A004 live IDA MCP split refresh used session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and confirmed the five exact child records:

- `entity_query 0x00619e80-0x0061a3d0` reports the four dialog triples, the callback-template vtable at `0x0061a3b0`, neighboring `MyItemListPane` at `0x00619f28`, `ExchangeAlertPane` at `0x0061a1c0`, and `FieldMapPane` named vtable base at `0x0061a3c8` after the `0x0061a3c4` COL pointer.
- `lookup_funcs` reconfirmed the key destructor/adjustor/callback slot sizes: `0x004b0910` size `0x5f`, `0x0047eaf0` size `0x3b`, `0x004b0ad0` size `0x45`, `0x004b0970` size `0x5f`, adjustor thunks size `0x0b`, callback invoke `0x004b0880` size `0x21`, and function-object support slots `0x0049b090` size `0x3e` and `0x004f4b10` size `0x06`.
- `trace_data_flow backward` reconfirmed representative vptr stores for `AddItemDialog`, all inline/standalone `AddMixingItemDialog` stores, and callback vtable construction stores at `0x004afd62` and `0x004b0370`.
- Successor checks prove the child boundaries: `0x00619f24` is `MyItemListPane` RTTI, `0x0061a084` is `MixItemDialog` RTTI, `0x0061a120` is `AddMixingItemDialog` RTTI, `0x0061a1bc` is `ExchangeAlertPane` RTTI, and `0x0061a3c4` is the next `FieldMapPane` COL pointer before the named vtable at `0x0061a3c8`.
- `make_signature_for_range` returned unique signatures for all five exact child records.

## Reconstruction Notes

Use this page as the layout anchor for the item-picker and mix-dialog source pass. The vtable stores reinforce a compact original module around reusable item selection (`AddItemDialog`, `AddItemWithCountDialog`, `MyItemListPane`) plus a nearby mix-dialog file or section (`MixItemDialog`, `AddMixingItemDialog`). `AddEmployeeItemDialog` is a derived employee-specific reuse case and should remain with [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), not treated as generic item-dialog ownership evidence.

The adjustor thunks are compiler-generated layout glue. Final source should model the C++ inheritance/destructor layout rather than porting the tiny thunk functions as handwritten item-dialog methods.

`AUTOGEN_PARENT_UID` remains blank for this vtable family and `RECONSTRUCTABLE` is `FALSE`. The page now clears `90/93`, but it is a type/layout inventory spanning concrete item-dialog class tables and the MixItemDialog callback-template table; the source-local split children attach to their concrete class/template parents instead of routing the whole vtable family to one source parent.

Score rationale: completion improved because the page now records concrete RTTI locators, key slot dwords, constructor/store xrefs, packet-handler slots, callback invoke slot, and the ownership-split reason. Confidence improved because the 2026-06-11 IDA pass agrees with the earlier 2026-05-31 and 2026-06-08 checks. It stays below final-audit levels because inherited pane-interface slot names and final header declarations are still not completely reconstructed.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md)
- [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md)
- [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md)
- [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md)
- [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md)
- [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-07-13 - B003 UID0004BQ callback slot-name synchronization

- Preserved `90/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, and the mixed-family no-route disposition.
- Synchronized the AddItemWithCount child parent score to `91/93` and named the exact primary `+0x48` UID0004BR `OnControlCommand`, primary `+0x4c` B002-owned UID0004BS updater, and secondary `+0x10` UID000318 `HandlePacketEvent` relationships.
- Preserved the compiler-generated vtable/adjustor-thunk no-code policy, recorded the signed inventory-slot and packet-event behavior, and historicalized obsolete generated-placeholder wording without changing unrelated class-table evidence.

### 2026-07-13 - B005 UID0004BP updater-slot synchronization

- Preserved `90/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal body, and all mixed-family boundaries.
- Added the exact AddItem/AddEmployee/AddMixing `+0x4c -> 0x004aea40` inheritance table, AddItemWithCount `+0x4c -> 0x004af480` override exclusion, updated AddItem child/class scores, and generic refresh dispatch consequence.

### 2026-05-31 - Scored IDA-verified item-dialog vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank even though it contained a structured vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because inherited virtual names, callback declaration spelling, and final source-level declarations are not final-audit complete.
- Evidence: IDA MCP `py_eval` and `list_globals` on 2026-05-31 confirmed the decorated vtable names, first/action slots, adjustor slots, constructor/destructor/store xrefs, callback table target, and nearby non-owned boundaries.

### 2026-06-08 - Batch 116 packet-slot refresh

- Before: `COMPLETION:84`, `CONFIDENCE:88`; the family inventory had the major vtable bases but not the exact new packet-close child pages.
- Changed to: `COMPLETION:86`, `CONFIDENCE:89`; added the exact AddItemDialog and AddItemWithCountDialog packet handler slot refs plus the MixItemDialog quantity callback target relationship.
- Evidence: current IDA MCP confirms vtable/data refs at `0x00619efc`, `0x0061a05c`, callback vtable `0x0061a3b0`, and callback target stores for [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md). The family stays unassigned because it is a layout/type inventory, not one direct source owner.

### 2026-06-11 - A003 Batch 150 slot and ownership-split audit

- Before: `COMPLETION:86`, `CONFIDENCE:89`; the page had table bases and representative slots, but not a written slot-level audit for all four class triples plus the callback table.
- Changed to: `COMPLETION:88`, `CONFIDENCE:91`; `AUTOGEN_PARENT_UID` remains blank.
- Evidence: live IDA MCP `py_eval` reconfirmed RTTI locators, scalar/inherited destructor slots, class action slots, secondary packet-handler slots, tertiary shared update/default slots, constructor/store xrefs, the `DoubleParamMemberFunctionObject<...MixItemDialog...>` construction stores, and invoke slot `0x0061a3bc -> 0x004b0880`. The family remains intentionally unassigned because it combines four concrete dialog-class table triples and one callback-template table; by-structure requires exact children to route through their direct class/file/template owners instead of forcing this aggregate under one parent.

### 2026-06-12 - B001-00025A callback-tail repair

- Before: [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) ended at `0x0061a3c0` and omitted the `0x0061a3c0 -> 0x004673f0` tail slot.
- Changed to: exact child range `0x0061a3ac-0x0061a3c4`, score `88/92`; the family remains a non-emitting index and the child remains routed to [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md).
- Evidence: B001 live IDA/PE boundary audit proved `0x0061a3c4` is the FieldMapPane COL successor and not part of the callback record.
### 2026-06-12 - A004 Batch 324 split

- Before: `COMPLETION:88`, `CONFIDENCE:91`, `RECONSTRUCTABLE:TRUE`, and parent blank even though the page documented mixed ownership.
- Changed to: `COMPLETION:90`, `CONFIDENCE:93`, `RECONSTRUCTABLE:FALSE`, and parent blank as a non-emitting mixed-owner index; source-local children [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md), [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md), [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md), [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md), and [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) carry the reconstructable class/template routes.
- Evidence: live IDA MCP `entity_query`, `lookup_funcs`, `trace_data_flow`, successor checks, and unique exact-range signatures reconfirmed the split boundaries and direct owners.
