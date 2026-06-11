*** UID:00008J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MixItemDialog

## Status

- Confidence: strong for behavior, item-dialog module placement, vtable/singleton evidence, and mix-child callback flow; medium for final packet/member names.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MixItemDialog.cpp`

## Class Purpose

`MixItemDialog` is the item-mixing UI. It assembles selected inventory items, uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) for player item selection, supports add/remove actions, and submits the completed mix request packet to the server.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MixItemDialog` core | [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) | Constructor, action dispatcher, and action switch table. |
| `SubmitPacketHelper` | [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) | Raw helper that serializes opcode `0x6b` with current mix-list rows and closes the dialog. |
| `QuantityPromptHelper` | [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) | Adds non-stackable rows directly or builds a `NumberInputDialog` with a double-param callback for stackable items. |
| `QuantityCallback` | [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) | Receives the chosen quantity, updates item text/count payload, and appends the selected row to the mix list. |
| `SingletonClearHelper` | [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md) | Clears the active `MixItemDialog` singleton. |
| destructor/thunk strip rows | [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md) rows `0x004b08f9-0x004b090f` and `0x004b0ad0-0x004b0b15` | Compiler-generated adjustor thunks and scalar deleting destructor wrapper. |

## Evidence Notes

- Existing item-dialog memory documentation identifies selected-item assembly, add/remove actions, and mix-packet submission.
- IDA MCP confirms constructor/action/destructor function starts and the small thunk starts.
- IDA MCP reports a `MyItemListPane` constructor call at `0x004af7a7` inside the mix dialog constructor.
- IDA MCP vtable checks confirm dialog table bases at `0x0061a088`, `0x0061a0e8`, and `0x0061a118`, plus the double-param callback vtable at `0x0061a3b0`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) records the active MixItemDialog singleton slot at `0x0069b32c`, constructor publish/fallback clear, destructor clears, and two open-if-null creation gates.
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) stores a pointer back to this dialog, filters available items against the current mix list, and is installed inline by `MixItemDialog::HandleAction`.
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) and [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) document the quantity callback path used by stackable mix-item selection.
- 2026-06-08 Batch 116 current IDA MCP split the quantity path into exact children: `0x004afcc0-0x004afe38` constructs the direct row or `NumberInputDialog` path, and `0x004afe40-0x004afff7` is the bound callback target stored by both `0x004afcc0` and [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md).
- 2026-06-10 B001-026 split core and raw submit helper rows as [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) and [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md). It also split [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md) and inventoried destructor/thunk rows in [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).

## Ownership And Parent Gate

This class is assigned to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md). The child now clears `87/88`, the direct parent is scored `90/87`, and the supporting docs all keep the constructor, action handler, item-list pane setup, add-mixing child dialog, singleton slot, and vtable family inside the item-dialog module.

The larger [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md) range is mixed and therefore not used as a direct parent for this class. It remains the executable evidence range; the direct source parent is the narrower ItemDialogs file page, which is already above the strict gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page now records constructor/action/destructor/thunk boundaries, selected-item behavior, list-pane setup, item-dialog vtables, singleton lifecycle, add-mixing child ownership, exact quantity prompt helper, and exact quantity callback target. Completion remains below 90 because exact packet fields, member names, and final source split between generic item pickers and mix-specific code remain open. |
| Confidence | 88 | Confidence is strong for placement and behavior because independent by-memory, by-type, by-file, and singleton-slot pages all point to the ItemDialogs source family. It remains below final because some names still derive from current documentation labels rather than a final source audit. |
| Parent | [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) | Child `87/88` and parent `90/87` both clear the strict 85/85 gate; the relationship is direct because the mix dialog is one of the item picker/mix dialog classes owned by that module. |

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md)
- [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md)
- [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonClearHelper.md)
- [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)

## Changes

- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:76`, `CONFIDENCE:84`, and no parent because the class page itself was below the attachment gate.
  - After: `COMPLETION:85`, `CONFIDENCE:86`, and parent [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).
  - Why: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is `89/85`; [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md), [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md), [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md), and the mix executable range together document direct item-dialog ownership, vtables, singleton lifecycle, child picker flow, and callback support.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/action/thunk/deleting-destructor starts at `0x004af570`, `0x004af8b0`, `0x004b08f9`, `0x004b0904`, and `0x004b0ad0`. Left `AUTOGEN_PARENT_UID` blank at that time because this class page had not yet cleared the attachment gate even though [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) was the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the item-mixing dialog has clear source placement, constructor/action/destructor boundaries, selected-item/list-pane behavior, double-param callback reference, and related dialog ownership, but exact packet/layout internals are not fully expanded here. Evidence: linked `ItemExchangeMixDialogs` range, IDA-confirmed starts and vtable checks, `MyItemListPane` constructor call, `AddMixingItemDialog` relationship, and mix-packet submission summary.
- 2026-06-08 A007 Batch 116 quantity helper split:
  - Before: score `85/86`; quantity helper/callback behavior was mostly carried by the broad aggregate and callback wrapper pages.
  - After: score `87/88`; added exact children [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) and [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md).
  - Summary/evidence: current IDA MCP confirms the helper range, direct/non-stackable row insertion, callback object construction, `NumberInputDialog` dependency, callback-target stores, direct AddMixingItemDialog caller, quantity string replacement, and row append behavior.
- 2026-06-10 B001-026 split repair:
  - Added exact core, raw submit helper, singleton clear helper, and mixed destructor/thunk strip links.
  - Evidence: B001 IDA disassembly confirms the action switch table at `0x004afb68`, raw opcode `0x6b` submit helper at `0x004afb80`, singleton clear of `dword_69B32C` at `0x004b0870`, and compiler-generated destructor/thunk rows for `0x004b08f9-0x004b090f` and `0x004b0ad0-0x004b0b15`.
