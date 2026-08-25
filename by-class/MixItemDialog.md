*** UID:00008J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MixItemDialog : public DialogPane,
                      public Singleton<MixItemDialog>
{
public:
    MixItemDialog();

    virtual int OnAction(unsigned int actionId);

    void AddMixItem(unsigned char itemId,
                    unsigned short itemSerial,
                    const wchar_t *itemName,
                    unsigned char style);

private:
    void SubmitMixPacket();
    void OnMixItemQuantity(unsigned int count,
                           unsigned char itemId,
                           unsigned char style);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MixItemDialog

## Status

- Confidence: very strong for behavior, direct bases, no-field layout, item-dialog module placement, vtable/Singleton evidence, constructor, and mix-child callback flow; exact original lexical helper names remain the principal cap.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- Vtable/layout anchor: [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md); callback-template vtable anchor [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md); mixed index [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- Historical recovered artifact: `source-3/simroot_v2/class_MixItemDialog.cpp`; it is evidence history, not the accepted source route.
- Exact declaration model: `class MixItemDialog : public DialogPane, public Singleton<MixItemDialog>` with complete size `0x26c` and no derived fields. `[[CHILDREN]]` follows the closed class so qualified method definitions emit at namespace scope.

## Class Purpose

`MixItemDialog` is the item-mixing UI. It assembles selected inventory items, uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) for player item selection, supports add/remove actions, and submits the completed mix request packet to the server.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MixItemDialog()` | [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md) | Sole source-emitting parameterless constructor; exact DialogPane/Singleton bases, six-control tree, local list transfer, row clearing, selectors, and lifecycle. |
| `OnAction` | [UID:0004BU][0x004af8b0-0x004afb65.MixItemDialogOnAction](by-memory/0x004af8b0-0x004afb65.MixItemDialogOnAction.md) | Live add/remove/submit/cancel dispatcher. Case 3 contains the active inline submit serialization. |
| Mix core split index | [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) | Non-emitting constructor/action/table inventory; exact children carry source and compiler-data dispositions. |
| `SubmitMixPacket` / retained submit helper | [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) | Retained private helper that serializes opcode `0x6b` with current mix-list rows and closes the dialog; standalone start has no observed direct branch/pointer route, while live `HandleAction` case 3 duplicates the submit serialization inline. |
| `QuantityPromptHelper` | [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) | Adds non-stackable rows directly or builds a `NumberInputDialog` with a double-param callback for stackable items. |
| `QuantityCallback` | [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) | Receives the chosen quantity, updates item text/count payload, and appends the selected row to the mix list. |
| `Singleton<MixItemDialog>` base destructor instantiation | [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md) | EH-only generated-binary support that clears the active slot during failed construction; historical free-helper identity is rejected. |
| destructor/thunk strip rows | [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md) rows `0x004b08f9-0x004b090f` and `0x004b0ad0-0x004b0b15` | Compiler-generated adjustor thunks and scalar deleting destructor wrapper. |

## Evidence Notes

- Existing item-dialog memory documentation identifies selected-item assembly, add/remove actions, and mix-packet submission.
- IDA MCP confirms constructor/action/destructor function starts and the small thunk starts.
- IDA MCP reports a `MyItemListPane` constructor call at `0x004af7a7` inside the mix dialog constructor.
- IDA MCP vtable checks confirm dialog table bases at `0x0061a088`, `0x0061a0e8`, and `0x0061a118`, plus the double-param callback vtable at `0x0061a3b0`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- 2026-06-12 A004 split refresh adds source-local dialog vtable child [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md), routed here at child `89/92` with this direct parent at `87/88`; the callback-template vtable is split separately as [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) under the callback wrapper class.
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) records the active MixItemDialog singleton slot at `0x0069b32c`, constructor publish/fallback clear, destructor clears, and two open-if-null creation gates.
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) stores a pointer back to this dialog, filters available items against the current mix list, and is installed inline by `MixItemDialog::HandleAction`.
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md) and [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) document the quantity callback path used by stackable mix-item selection.
- 2026-06-08 Batch 116 current IDA MCP split the quantity path into exact children: `0x004afcc0-0x004afe38` constructs the direct row or `NumberInputDialog` path, and `0x004afe40-0x004afff7` is the bound callback target stored by both `0x004afcc0` and [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md).
- 2026-06-10 B001-026 split core and raw submit helper rows as [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) and [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md). It also split [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md) and inventoried destructor/thunk rows in [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).
- 2026-06-22 B009 Rule 26 submit-helper pass refines [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) as source-authored retained `MixItemDialog::SubmitMixPacket()` logic, not compiler glue. The standalone body at `0x004afb80-0x004afcb7` has no VA/RVA/raw pointer hits and no direct `.text` branch/call route, but [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) case 3 at `0x004afa3a` contains an inline/duplicated copy of the same packet serialization. The action switch table entries are `0x004af8fa`, `0x004af9f9`, `0x004afa3a`, and `0x004afb3b`; no entry targets `0x004afb80`.

## Exact Inheritance And Layout

- Both constructor callers allocate `0x26c`, and the scalar deleting wrapper's size-aware path uses the same complete-object size.
- RTTI type descriptors identify both `MixItemDialog` and `Singleton<MixItemDialog>`. The eight-entry hierarchy is MixItemDialog, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and Singleton.
- The Singleton base-class descriptor records `mdisp=0x26c`, `pdisp=-1`, `vdisp=0`, attributes `0x40`: it is a direct, nonvirtual empty base placed at the complete-object end by EBO.
- Constructor stores the three dialog-view vptrs at complete-object offsets `+0`, `+0xa0`, and `+0xa4`, with tables `0x0061a088`, `0x0061a0e8`, and `0x0061a118`.
- No constructor or later method write establishes storage after DialogPane. Therefore `MixItemDialog` declares no data members; `+0x26c` is the Singleton base address, not an `m_itemList` field.
- The implicit destructor remains intentionally undeclared as an authored out-of-line method. Virtual base behavior and the class tables produce the observed scalar deleting wrapper, adjustors, DialogPane teardown, and Singleton clear.

## Constructor, Controls, And Singleton Lifetime

- Constructor [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md) invokes `DialogPane(L"",9,1)`, then constructs the direct Singleton base, which publishes complete `this` to typed global `g_pMixItemDialog` at `0x0069b32c`.
- The constructor builds one EPF background using `MIXITEM.EPF`/`MIXITEM.PAL`, four image buttons with IDs `36`, `21`, `14`, `22`, and one scroll wrapper around a parameterless local `MyItemListPane`. Insertion indexes are 0-5; selectors are hover/focused/pending `1/3/4`.
- The local list is transferred to `ScrollableControlPane(&bounds,itemList,0,0,0)` and is never stored in this class. After `OnCreate`, rows are removed from `GetItemCount()-1` down to zero using `RemoveItems(index,1)`.
- Lifecycle calls are `OnCreate(fullBounds,0,NULL,overlayPaneLayerContext)`, `OnShow(NULL,NULL)`, and `SlideOpenVertical()`. Unlike the AddItem sibling, no `g_pBackPane` argument is used.
- The global slot has exactly six refs: constructor publish/fallback, EH-only Singleton destruction, scalar-wrapper destruction, and two open-if-null gates. This is template-base lifetime, not a manually paired free helper.
- Seven allocation unwind states cover the background, four buttons, local list, and scroll wrapper. Vptr writes, raw allocation-null branches, delete funclets, security-cookie checks, scalar flags, and this-adjustor thunks are compiler output represented by normal C++ declarations and `new` expressions.

## Historical Corrections And Negative Evidence

- Historical `Dialog` inheritance is superseded by the exact direct `DialogPane` constructor and RTTI.
- Historical direct singleton assignment and `ClearActiveMixItemDialog` source are superseded by the `Singleton<MixItemDialog>` base, constructor EH state 1, and identical Singleton comparator behavior.
- Historical `m_itemList`, `new MyItemListPane(this)`, `CreateMixItemDialogControls`, `AddChild`, and `ClearMixRows` are rejected by the parameterless local-list flow, no member store, six direct `AddControl` calls, and exact removal loop.
- No handwritten vtable/RTTI arrays, EH funclets, scalar wrapper, adjustor thunk, or standalone resource-storage definition belongs in class source.
- Exact original local/helper spellings and the original physical `ItemDialogs.cpp` versus `MixItemDialog.cpp` split are not symbol-proven; they cap confidence without changing the accepted owner, layout, declaration, or route.

## Submit Packet Field Model

- `this+0x1fc` is best documented as the dialog child-control/page list; selector `5` is the central mix-list control.
- The selected list/control wrapper row storage is at `+0x108`; each row supplies an item id byte from `+0x00`.
- Row `+0x208` is the selected quantity. [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md) and [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) are the supporting row-quantity producers.
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / raw `dword_67A748` supplies item metadata. Metadata byte `+0x1ec` is the stackable/quantity flag for this helper; metadata near `+0x1e8` remains the sibling max-stack/count metadata used by prompt/callback paths.
- The packet payload is byte-oriented: opcode `0x6b`, selected-row count byte, one item-id byte per row, and one optional quantity byte for quantity-tracked rows. The helper does not emit a four-byte quantity and does not send spare zero bytes left by scalar packet-byte helpers.
- Submit/empty-list paths both call the shared slide/close helper at `0x0049eb90` and the close/deferred-delete helper at `0x0049dad0`.
- Source route remains under [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md). If this project later splits `MixItemDialog.cpp`, move the whole class family together rather than isolating the retained helper.

## Ownership And Parent Gate

This class is assigned to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md). The child is `91/93`, the direct parent is `92/92`, and the supporting docs all keep the constructor, action handler, item-list pane setup, add-mixing child dialog, singleton slot, and vtable family inside the item-dialog module.

The larger [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md) range is mixed and therefore not used as a direct parent for this class. It remains the executable evidence range; the direct source parent is the narrower ItemDialogs file page, which is already above the strict gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The page records the complete no-field declaration, exact direct bases, 0x26c layout, constructor/action/helper inventory, selected-item behavior, local-list ownership, controls/resources/lifecycle, typed singleton state, RTTI/vtables, EH/scalar distinctions, quantity flow, and packet support. Original lexical helper names remain the principal cap. |
| Confidence | 93 | Independent bytes, callers, RTTI, EH, vtables, globals, by-memory children, and file ownership converge on the source model. The exact original physical filename and some later helper names remain inferred. |
| Parent | [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) | Child `91/93` and parent `92/92` clear the strict gate; the relationship is direct because the class, globals, resources, and accepted method children share the ItemDialogs source route. |

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md)
- [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md)
- [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md)
- [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md)
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
- 2026-06-12 A004 vtable split:
  - Added source-local vtable child [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md) and callback-template vtable cross-reference [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md); score remains `87/88`.
  - Evidence: live IDA MCP reconfirmed the exact `MixItemDialog` vtable cluster and boundary before `AddMixingItemDialog`.
- 2026-06-22 B009 submit-packet source-quality pass:
  - Score unchanged at `87/88`; [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) now carries first-draft `MixItemDialog::SubmitMixPacket()` C++ and detailed route-negative evidence.
  - Summary/evidence: the class page now records the retained helper versus live inline case-3 distinction, switch table dwords, selector `5` mix-list route, row item/quantity offsets, metadata `+0x1ec` quantity flag, byte-width packet semantics, unconditional close/dismiss tail, rejected `AddMixingItemDialog`/PacketBuffer/no-owner alternatives, and future class-file split policy.
