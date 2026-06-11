*** UID:000009 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AddMixingItemDialog

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Exact method pages: [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md), [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), and [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md). The mixed destructor/thunk strip is inventoried by [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).
- Autogen parent: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md); C++ remains blank below the 95+ final-source gate.

## Class Purpose

`AddMixingItemDialog` is the item picker used by `MixItemDialog`. It derives from `AddItemDialog`, filters out items already present in the mix list, and asks for a quantity when the chosen item is stackable.

## Class Shape

- Base class: [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Owner field: live IDA constructor/action decompilation stores the `MixItemDialog*` owner pointer at object offset `+0x270` (`this+0x270`, shown as `+624` in the decompiler).
- Vtable family: primary/secondary/tertiary tables at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`.
- Primary behavior: filtered item picker for [UID:00008J][MixItemDialog](by-class/MixItemDialog.md), followed by stack-quantity prompt or direct add callback.
- Source placement: keep adjacent to `MixItemDialog` and [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md) | `0x004b0000-0x004b0118` | Builds a filtered add-item dialog linked to an owning mix dialog; removes already-selected mix items from the available row list. |
| [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md) | `0x004b0120-0x004b048a` | Confirms selected items; copies single-count rows directly or opens `NumberInputDialog` for stackable quantity input. |
| [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md) | `0x004b08b7-0x004b08cd` | Compiler-generated secondary/tertiary destructor adjustor thunks; ignored for handwritten source. |
| `ScalarDeletingDestructor` | [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md) row `0x004b0970-0x004b09cf` | IDA-confirmed compiler-generated wrapper reached from the primary vtable and two adjustor thunks; model through normal C++ destructor layout. |

## Evidence Notes

- Existing ItemDialogs documentation and live IDA decompilation identify inheritance from `AddItemDialog` and a `MixItemDialog*` owner field at offset `0x270`.
- 2026-06-06 live IDA MCP `lookup_funcs` reconfirms exact half-open ranges: constructor `0x004b0000-0x004b0118` (`0x118` bytes), confirm/action slot `0x004b0120-0x004b048a` (`0x36a` bytes), callback helper `0x004b0880-0x004b08a1`, secondary adjustor `0x004b08b7-0x004b08c2`, tertiary adjustor `0x004b08c2-0x004b08cd`, and scalar deleting destructor `0x004b0970-0x004b09cf`.
- Live raw-byte checks show `CC` padding after the constructor, confirm method, and scalar deleting destructor, so the documented ranges stop before alignment bytes and adjacent function islands.
- Live IDA `xrefs_to` reports no direct code xrefs to the standalone constructor start, but `MixItemDialog::HandleAction` at `0x004af8b0` inlines the allocation/base-constructor/vtable-store path: it allocates `628` bytes, calls `AddItemDialog` construction, writes the three AddMixing vtables at `0x004af929`, `0x004af92f`, and `0x004af939`, stores the owner at `+0x270`, then runs the duplicate-filter loop.
- IDA MCP vtable checks confirm table bases at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`, installed by the standalone constructor at `0x004b0039`, `0x004b003f`, and `0x004b0049` and by the `MixItemDialog::HandleAction` inline path at `0x004af929`, `0x004af92f`, and `0x004af939`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- Live IDA `xrefs_to 0x004b0120` reports the confirm/action method as the primary vtable action slot at `0x0061a16c`; there are no static callers, matching virtual dispatch from the dialog framework.
- Live confirm decompilation shows action `1` iterating selected picker rows, resolving item metadata through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, calling the `MixItemDialog` add callback directly for multi-selected stackable rows, copying single-count rows into the owner mix list when max stack is `<=1`, and allocating the double-parameter callback plus `NumberInputDialog` for stackable single rows.
- 2026-06-08 Batch 116 split the owner callback target as [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md), which has the direct `0x004b02c4` call from this class's confirm handler and the callback-target store at `0x004b0376`.
- Live IDA `xrefs_to 0x004b0970` reports the scalar deleting destructor reached from the primary vtable and the two adjustor thunks at `0x004b08bd` and `0x004b08c8`.
- The constructor page records IDA evidence for `AddItemDialog` base construction, owner pointer store at `+0x270`, parent child selector `5`, picker child selector `3`, list counts, row-id comparison, and duplicate removal.
- The confirm page records IDA evidence for the action-code split, selected-row loop, item-table lookup through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, direct `MixItemDialog` add callback, copied row payload path, callback object construction at `0x004b0370`, and `NumberInputDialog` construction at `0x004b03d6`.
- The adjustor thunk page records vtable-only refs from `0x0061a184` and `0x0061a1b4`, and forwarding to the scalar deleting destructor wrapper.

## Score Rationale

The class is now scored `85/88` because live IDA evidence confirms its exact executable ranges, virtual-only action/destructor anchoring, inline construction path from `MixItemDialog::HandleAction`, owner field offset, duplicate filtering, selected-row handling, quantity-dialog callback construction, vtable data refs, and non-emitting destructor/thunk strip ownership. It remains below the final C++ threshold because source-facing list helper names, row payload field names, and item metadata field names still need a source-level audit.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md)
- [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md)
- [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: item metadata lookup evidence used only historical `dword_67A748`.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IDA-backed evidence already ties the reference to local player/client item metadata used by mix-item selection.
- What existed before: the page had method/evidence notes but was still scored as unevaluated.
- What it was changed to: scores were set to `68/84`, and a class-shape section now records base class, owner pointer, vtable anchors, behavior, and source placement.
- Summary and evidence: IDA MCP confirms constructor/confirm/destructor/thunk starts and vtable bases, but detailed field names and final source split with `MixItemDialog` still need more method-level documentation.
- 2026-06-03 completion/confidence and autogen update:
  - What existed before: the page was scored `68/84`, had no autogen parent, and summarized the constructor/confirm/thunk methods without exact child pages.
  - Changed to: scores were raised to `78/88`, `RECONSTRUCTABLE` was set to `TRUE`, and [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) was attached as the autogen parent while keeping final C++ blank.
  - Summary/evidence: new exact memory pages [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md), [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), and [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md) record 2026-06-03 IDA MCP range, decompile, xref, padding, vtable, owner-pointer, duplicate-filter, quantity-callback, and `NumberInputDialog` evidence. The score remains below `95` because source-facing list helper names, item-info field names, and the scalar deleting destructor split are not final-audit complete.
- 2026-06-06 live IDA cleanup:
  - What existed before: the page was scored `78/88` and still referenced outdated provenance evidence while summarizing the constructor and confirm paths at a high level.
  - Changed to: completion was raised to `82`, stale provenance wording was removed, and the evidence now records live IDA function sizes, padding boundaries, virtual-only callsite shape, inline construction from `MixItemDialog::HandleAction`, owner offset, confirm-path row handling, callback construction, and scalar destructor refs.
  - Summary/evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, `decompile`, and raw-byte probes confirm the class behavior is well constrained but still below `95/95` until source-facing helper and payload field names are final.
- 2026-06-10 B001-026 gate repair:
  - Before: `82/88`, below the strict direct-parent threshold for reconstructable exact children.
  - After: `85/88`; exact constructor/action children are also raised to the gate, and the scalar deleting destructor is covered by the non-emitting mixed strip inventory [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).
  - Evidence: exact ranges, vtable refs, inline construction, owner pointer, duplicate filtering, quantity callback creation, and destructor/thunk strip refs are all IDA-backed.
