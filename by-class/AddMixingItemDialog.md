*** UID:000009 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Exact method pages: [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md), [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), and [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md).
- Current recovered file: `source-3/simroot_v2/class_AddMixingItemDialog.cpp`
- Autogen parent: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md); C++ remains blank below the 95+ final-source gate.

## Class Purpose

`AddMixingItemDialog` is the item picker used by `MixItemDialog`. It derives from `AddItemDialog`, filters out items already present in the mix list, and asks for a quantity when the chosen item is stackable.

## Class Shape

- Base class: [UID:000007][AddItemDialog](by-class/AddItemDialog.md).
- Owner field: IDA MCP constructor decompilation stores the `MixItemDialog*` owner pointer at object offset `+0x270`.
- Vtable family: primary/secondary/tertiary tables at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`.
- Primary behavior: filtered item picker for [UID:00008J][MixItemDialog](by-class/MixItemDialog.md), followed by stack-quantity prompt or direct add callback.
- Source placement: keep adjacent to `MixItemDialog` and [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md) | `0x004b0000-0x004b0118` | Builds a filtered add-item dialog linked to an owning mix dialog; removes already-selected mix items from the available row list. |
| [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md) | `0x004b0120-0x004b048a` | Confirms selected items; copies single-count rows directly or opens `NumberInputDialog` for stackable quantity input. |
| [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md) | `0x004b08b7-0x004b08cd` | Compiler-generated secondary/tertiary destructor adjustor thunks; ignored for handwritten source. |
| `ScalarDeletingDestructor` | `0x004b0970-0x004b09cf` | IDA-confirmed wrapper reached from the primary vtable and the two adjustor thunks; keep modeled through normal C++ destructor layout until a separate destructor page is split. |

## Evidence Notes

- Wave3 notes identify inheritance from `AddItemDialog` and a `m_pMixItemDialog` field at offset `0x270`.
- 2026-06-03 IDA MCP confirms exact constructor range `0x004b0000-0x004b0118`, confirm range `0x004b0120-0x004b048a`, adjustor thunk range `0x004b08b7-0x004b08cd`, and scalar deleting destructor range `0x004b0970-0x004b09cf`.
- IDA MCP vtable checks confirm table bases at `0x0061a124`, `0x0061a184`, and `0x0061a1b4`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- The constructor page records IDA evidence for `AddItemDialog` base construction, owner pointer store at `+0x270`, parent child selector `5`, picker child selector `3`, list counts, row-id comparison, and duplicate removal.
- The confirm page records IDA evidence for the action-code split, selected-row loop, item-table lookup through `dword_67A748`, direct `MixItemDialog` add callback, copied row payload path, callback object construction at `0x004b0370`, and `NumberInputDialog` construction at `0x004b03d6`.
- The adjustor thunk page records vtable-only refs from `0x0061a184` and `0x0061a1b4`, and forwarding to the scalar deleting destructor wrapper.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md)
- [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md)
- [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)

## Changes

- What existed before: the page had method/evidence notes but was still scored as unevaluated.
- What it was changed to: scores were set to `68/84`, and a class-shape section now records base class, owner pointer, vtable anchors, behavior, and source placement.
- Summary and evidence: IDA MCP confirms constructor/confirm/destructor/thunk starts and vtable bases, but detailed field names and final source split with `MixItemDialog` still need more method-level documentation.
- 2026-06-03 completion/confidence and autogen update:
  - What existed before: the page was scored `68/84`, had no autogen parent, and summarized the constructor/confirm/thunk methods without exact child pages.
  - Changed to: scores were raised to `78/88`, `RECONSTRUCTABLE` was set to `TRUE`, and [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) was attached as the autogen parent while keeping final C++ blank.
  - Summary/evidence: new exact memory pages [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md), [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), and [UID:0002U3][0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks](by-memory/0x004b08b7-0x004b08cd.AddMixingItemDialogAdjustorThunks.md) record 2026-06-03 IDA MCP range, decompile, xref, padding, vtable, owner-pointer, duplicate-filter, quantity-callback, and `NumberInputDialog` evidence. The score remains below `95` because source-facing list helper names, item-info field names, and the scalar deleting destructor split are not final-audit complete.
