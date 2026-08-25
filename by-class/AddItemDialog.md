*** UID:000007 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ItemDialogs.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/Surface.h"
#include "../panels/UserPane.h"

class AddItemDialog : public DialogPane
{
public:
    AddItemDialog(unsigned int exchangeSessionId,
                  unsigned char allowMultipleSelection);
    virtual ~AddItemDialog();

    virtual int OnAction(unsigned int actionId);
    virtual int OnClosePacket(const unsigned char *packet);
    virtual void UpdateActionButton();
    void SendSelectedItemPacket(char selectedInventorySlot);

protected:
    unsigned int m_exchangeSessionId;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddItemDialog

## UID0000LO Accepted ItemDialogs Prefix And Order - 2026-08-14

This class is ItemDialogs file position `10`; its existing methods and class
shape are unchanged. The CPP channel now supplies the exact visibility prefix
required by the folded MyItemListPane methods: local `ItemDialogs.h`, render
EPFTileContext, ItemObjImageLib, Surface, and UserPane. The prefix emits once
before the existing AddItemDialog declaration and ItemDialogs children. The
MyItemListPane route follows at file position `20`; no list pointer is added to
AddItemDialog and its transferred ScrollableControlPane ownership remains
unchanged.

## Status

- Confidence: strong for behavior and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- Vtable/layout anchor: [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md); mixed index [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- Parent attachment: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) owns and emits this class in the item-dialog source module.
- C++ reconstruction: the accepted declaration now records the exact DialogPane base, constructor ABI, accepted virtual/nonvirtual surface, one proven local field, and child emission route. Unresolved unrelated private control/row spellings remain prose-level and do not require a blank declaration.

## Class Purpose

`AddItemDialog` is the base modal item-selection dialog used by exchange-style workflows. Its constructor creates a local [UID:00008W][MyItemListPane](by-class/MyItemListPane.md), configures inherited multiple-selection state, transfers that list to a ScrollableControlPane, builds exact EPF/EPD layouts, and publishes the active singleton only after dialog activation. Later methods handle action buttons and selected-item packets.

## Class Shape

- Base class: [UID:00003T][DialogPane](by-class/DialogPane.md), constructed as `DialogPane(L"",9,1)`, with three vfptr views at object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Exact object size is `0x270`. Derived employee/mixing dialogs allocate `0x274` and use their own dword at `+0x270`; AddItemDialog has no field there.
- Constructor signature is `AddItemDialog(unsigned int exchangeSessionId, unsigned char allowMultipleSelection)`. Two four-byte stack slots are popped by `retn 8`; the byte parameter is not stored.
- Primary child control: [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) is a constructor-local object wrapped and owned by ScrollableControlPane, not an AddItemDialog member.
- Layout mode: exact equality `g_useEpfAssets == 1` selects `DLGEXC2.EPF`/`PAL01.PAL`, `241x340`, inset 13; the other arm selects `DLGEXC2.EPD`/`NPAL8.PAL`, `287x277`, inset 0.
- Control insertion order is background, action id 36, cancel id 22, then scroll/list wrapper. Hover/focused/pending selectors are `3/1/2`; selector 3 is insertion-order-derived.
- `UpdateActionButton` uses zero-based insertion indexes `1` and `3`: selector 1 resolves the action ImageButtonControlPane, selector 3 resolves the ScrollableControlPane wrapper, and `GetScrollablePane()` exposes the owned ListPane/MyItemListPane. AddItemDialog stores neither control as a direct field.
- Owner/context field: object offset `+0x26c` is the exchange/context id used by the `0x4A` add-item packet path. `ExchangeDialog` passes its `m_exchangeSessionId`, while mix-derived paths pass zero and install derived vtables. Best current field name for the exchange-send path is `m_exchangeSessionId`; fallback generic name is `m_contextId` if final source keeps the base picker exchange-neutral.
- Constructor lifecycle after layout is `OnCreate`, `OnShow`, `SlideOpenVertical`, then `g_pAddItemDialog = this` last.
- Destructor source lifecycle is the single unconditional statement `g_pAddItemDialog = 0`. The binary then performs compiler-emitted vptr restoration and tail-calls the direct DialogPane base destructor; no `g_pAddItemDialog == this` guard exists.
- RTTI confirms a direct DialogPane base and seven hierarchy entries: AddItemDialog, DialogPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler. There is no `Singleton<AddItemDialog>` base relationship.
- Source placement: reusable item picker code belongs in [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), not exchange/session or inventory-pane source.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemDialog` constructor | [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md) | Exact source-ready constructor: DialogPane base; EPF/EPD four-control tree; local MyItemListPane selection-mode setup; context store; create/show/slide; singleton publish last. |
| `~AddItemDialog` ordinary destructor | [UID:0004BN][0x004ae900-0x004ae929.AddItemDialogDestructor](by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md) | Exact source-ready destructor at source position 20: unconditionally clears `g_pAddItemDialog`; vptr resets and the DialogPane tail teardown are compiler mechanics. |
| `OnAction` | [UID:0004BO][0x004ae930-0x004aea3a.AddItemDialogOnAction](by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md) | Source position 30. Selector 3 is the ScrollableControlPane wrapper; the handler unwraps its ListPane, exports selected rows, sends one `0x4A/1` record per nonnull row, then closes. |
| `UpdateActionButton` | [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) | Source position 40 and primary virtual slot `+0x4c`. Resolves action control 1 and scroll wrapper 3, calls inherited [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md), and tail-dispatches ImageButtonControlPane Enable or Disable without null checks. |
| `AddItemDialog` remaining core | [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md) | Constructor container plus non-deleting destructor, action handler, and button-state updater children. |
| `ExchangePacketCloseHandler` | [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md) | Vtable-only secondary-view handler that reacts to packet bytes `0x42/0x04`, dismisses the dialog, and invokes the primary close slot. |
| `SubmitPacketHelper` | [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md) | Active singleton accessor plus retained/no-direct-route private send helper. Best source name `SendSelectedItemPacket(char selectedInventorySlot)`; builds client exchange packet `0x4A/1` from `m_exchangeSessionId`/context id and selected inventory slot, writes an unsent scratch terminator, and queues seven bytes through `g_packetSender`. |
| `SecondaryDestructorAdjustorThunk` | `0x004b08a1-0x004b08ac` | Compiler-generated secondary-view adjustor thunk for the destructor path. |
| `TertiaryDestructorAdjustorThunk` | `0x004b08ac-0x004b08b7` | Compiler-generated tertiary-view adjustor thunk for the delete path. |
| `ScalarDeletingDestructor` | `0x004b0910-0x004b096f` | Restores vtables, clears the active singleton, runs the destructor path, and conditionally frees. |

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-06 confirms the exact half-open ranges listed above, including the 0xb-byte adjustor thunks.
- IDA MCP `callers 0x004ae4c0` reports constructor calls from `EmployeeDialogPane::OnButtonAction` inline construction (`0x004a339f`), `ExchangeDialog::OnButtonAction` (`0x004ad124`), `MixItemDialog::HandleAction` (`0x004af924`), and the `AddMixingItemDialog` constructor (`0x004b0031`).
- UID0004BM direct reanalysis adds raw AddEmployee call `0x004a4aee`, completing five call sites. Exact/derived allocations are `0x270` and `0x274`; the derived dword at `+0x270` is outside AddItemDialog.
- IDA MCP `callers 0x004ae930` reports the derived [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) action handler forwarding non-confirm actions to the base handler at `0x004a4b60`.
- IDA MCP reports `MyItemListPane` constructor calls inside this constructor at `0x004ae63e` and `0x004ae7f0`.
- Direct constructor evidence proves those MyItemListPane objects are locals transferred to ScrollableControlPane. [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md) receives the EPF byte parameter and forced value one in the EPD arm; no list pointer or byte-mode member is stored in AddItemDialog.
- The exact constructor allocates the background, two buttons, list, and scroll wrapper in each arm; preserves all resource, palette, rectangle, inset, and selector literals; then stores `m_exchangeSessionId`, calls `OnCreate`, `OnShow`, and `SlideOpenVertical`, and publishes the singleton last.
- Ten allocation cleanup states plus base state zero are standard compiler constructor-unwind lowering. Three vptr writes, EH tables/funclets, cookie checks, and adjacent padding are excluded from handwritten source.
- Historical shallow names `packetType`, `m_packetType`, `mode`, `m_mode`, `CreateItemDialogControls`, `m_itemList`, and explicit `AddChild(3,...)` are contradicted. No direct constructor call reaches `UpdateActionButton`, but the broader historical conclusion that button state is handled only later is superseded: constructor `OnCreate` synchronously calls generic wrapper `0x0049fe20`, which dispatches AddItemDialog primary slot `+0x4c` after the controls and final AddItem vtables exist.
- IDA MCP vtable checks confirm table bases at `0x00619e8c`, `0x00619eec`, and `0x00619f1c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; live store sites include `0x004ae500`, `0x004ae509`, `0x004ae513`, destructor/reset stores at `0x004ae900`, `0x004ae906`, `0x004ae910`, and scalar-deleting stores at `0x004b0916`, `0x004b091c`, and `0x004b0926`.
- 2026-06-12 A004 split refresh adds source-local by-vtable child [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md), routed here at child `88/92` with this direct parent at `85/89`; live IDA MCP reconfirmed the exact `0x00619e88-0x00619f24` cluster, decorated bases, slot target sizes, primary lifecycle stores, successor boundary, and unique signature.
- IDA MCP xrefs to [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) show the active AddItemDialog singleton is published at `0x004ae8d2`; exact zero stores occur at ordinary destructor site `0x004ae91a`, AddItemDialog scalar-wrapper copy `0x004b0930`, and inherited AddMixingItemDialog scalar-wrapper copy `0x004b0990`. Each clear is unconditional, with no preceding singleton load or pointer comparison.
- UID0004BN direct instruction evidence fixes the ordinary destructor at `[0x004ae900,0x004ae929)`: three vptr stores at `0x004ae900`, `0x004ae906`, and `0x004ae910`, the authored singleton clear at `0x004ae91a`, and a tail jump at `0x004ae924` to DialogPane cleanup `0x0049d9f0`. Eleven leading and seven trailing `0xcc` bytes are padding, not body bytes.
- Exactly three direct xrefs reach the ordinary destructor: `0x004a4d06` from the AddEmployee scalar-deleting wrapper and EH cleanup calls at `0x005fe61e` and `0x005fe6db` associated with AddMixing construction. Vtables instead route deleting destruction through `0x004b0910`, with secondary-view adjustors at `0x004b08a1` and `0x004b08ac`.
- AddItemDialog RTTI anchors at COL `0x00647318`, type descriptor `0x00675cc8`, and hierarchy descriptor `0x00646ad4`. The recovered seven-entry hierarchy supports the declared direct DialogPane base and rejects historical generic singleton-base interpretations.
- Scalar wrappers at `0x004b0910` and `0x004b0970` repeat the destructor stores and base teardown, then conditionally delete complete objects of `0x270` and `0x274` bytes. Those duplicate vptr/base/delete/adjustor operations are compiler-generated and remain excluded from the class's authored method bodies.
- Historical guarded source of the form `g_pAddItemDialog == this` was an unsupported hygiene inference. The accepted destructor declaration remains unchanged, while UID0004BN supplies the exact unconditional out-of-line definition.
- Decompilation/disassembly of `0x004ae930` shows button id `1` iterating selected item rows, resolving each row payload through the list helper, reading payload byte `+0x00` as the selected inventory slot, writing opcode `0x4A`, subtype `1`, exchange/context id at `+0x26c`, and sending the built seven-byte record through `g_packetSender`; button id `2` shares the close path. Decompilation of `0x004aea40` shows child selector `1` for the action button, child selector `3` for the picker/list control, and virtual enable/disable dispatch from the selection-state check.
- Exact updater routing is `0x00619ed8 -> 0x004aea40` for AddItemDialog, `0x00619120 -> 0x004aea40` for inherited AddEmployee behavior, and `0x0061a170 -> 0x004aea40` for inherited AddMixing behavior. AddItemWithCount provides the class-specific override `0x0061a038 -> 0x004af480`; it does not route to the base updater.
- `0x004aea40` has 23 instructions and no ordinary code xref. Its virtual-only reachability, exact class control composition, and derived vtable reuse are positive owner evidence. The method has no null tests and no boolean setter: a positive integer count selects virtual `Enable` slot `+0x4c`, while zero/nonpositive selects `Disable` slot `+0x50`.
- Eight structural sibling updaters use the same typed-child/ListPane-count/two-tail shape with different selectors. No exact duplicate body exists, so they corroborate the class-source pattern without changing ownership.
- 2026-06-08 IDA MCP `lookup_funcs`, `decompile`, `callers`, `callees`, and `xrefs_to` split the previously aggregate-only `0x004aea80-0x004aeab0` handler: it has a vtable ref at `0x00619efc`, no direct callers, checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, calls close helper `0x0049eb90`, and then invokes the primary close slot.
- 2026-06-10 B001-026 split the previously aggregate-only core and raw helper rows as [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md) and [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md). The retained helper/accessor island has no ordinary xrefs and B003 PE scans found no rel32 branch target, VA/RVA/raw-offset pointer, or end-pointer route to `0x004aeab0`, `0x004aeac0`, or `0x004aeb2f`; byte evidence still proves opcode `0x4A`, subtype `1`, exchange/context read at `this+0x26c`, selected-inventory-slot byte, local scratch terminator, and seven-byte send. The live `0x004ae930` action handler contains the inline equivalent selected-row send loop.
- This is item-selection UI and should not be merged into item inventory panes or item image libraries.

## Score Rationale

- Completion `91` reflects the exact class declaration route, constructor/destructor/OnAction/updater source order, updater virtual declaration, constructor ABI/body, complete five-caller/object-layout evidence, proven local wrapper/list ownership, integer selection helper, enable/disable dispatch, indirect refresh route, derived vtable table, lifecycle, and preserved sibling method evidence.
- Confidence `93` reflects direct binary range/control/field/global/EH evidence plus accepted support declarations and exact updater routing. It remains below 95 because access specifiers and private lexical spellings are not symbol-recovered, and unrelated broad row/control internals remain unresolved.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md)
- [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md)
- [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md)
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)

## Changes

- 2026-07-13 B005 UID0004BP callback:
  - Raised `90/92` to `91/93` and changed the declaration from nonvirtual to virtual while preserving the complete accepted class block and `[[CHILDREN]]` placement.
  - Added exact selector/control types, wrapper/ListPane access, UID0004M9 integer-count dependency, no-null and two-tail behavior, AddItem/AddEmployee/AddMixing inherited vtable routes, AddItemWithCount override exclusion, source positions `10/20/30/40`, and the synchronous `OnCreate -> 0x0049fe20 -> virtual +0x4c` constructor refresh route.
  - Historicalized the earlier broad claim that button state was handled only later; the no-direct-call fact remains valid.

- 2026-07-13 B001 UID0004BN callback:
  - Added exact ordinary-destructor child [UID:0004BN][0x004ae900-0x004ae929.AddItemDialogDestructor](by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md) at source position 20 without changing the accepted class declaration or `90/92` score.
  - Recorded the unconditional singleton clear, three direct callers, exact vptr/base-teardown sequence, RTTI hierarchy, scalar-wrapper duplicates, compiler/source boundary, and rejection of the prior guarded-clear and singleton-base assumptions.

- 2026-07-13 B001 UID0004BM callback: raised the class to `90/92`; added the exact DialogPane declaration/child route, constructor ABI/layout/control/lifecycle, five callers and object-size proof, local MyItemListPane ownership and UID0004LX route, compiler-EH exclusions, and rejected shallow constructor history while preserving all existing sibling evidence.

- 2026-06-06 live IDA attachment pass:
  - What existed before: the page was scored `72/86`, had no autogen parent, used stale source-owner wording, and recorded several function ranges with final executed-byte endpoints instead of half-open IDA ranges.
  - What changed: raised scores to `82/88`, attached the class to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), converted method rows to half-open live IDA ranges, replaced stale owner wording with IDA-backed caller/vtable/singleton/behavior evidence, added score rationale, and kept final C++ blank below the 95/95 gate.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `decompile`, and `py_eval` on 2026-06-06 confirm the constructor/destructor/action/update/thunk boundaries, constructor caller fanout, AddEmployee fallback caller, MyItemListPane construction sites, AddItemDialog vtable stores, active singleton publish/clear refs, and selected-row/action-button behavior.
- What existed before: the page had strong evidence but metadata remained `0/0`, and the class-level layout/source-placement summary was implicit in evidence bullets.
- What it was changed to: scores were set to `72/86`, and a class-shape section now records base/vfptr layout, child picker ownership, layout branching, and final source placement.
- Summary and evidence: existing IDA MCP function/vtable checks support strong confidence, while unresolved exact field naming keeps completion below high.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the constructor, destructor, command handler, and button-state method starts at `0x004ae4c0`, `0x004ae900`, `0x004ae930`, and `0x004aea40`, and `callers` showed the constructor is live from nearby item/exchange dialog code. Parent attachment was deferred at that time because the class completion score was still below the 80+ attachment gate.
- 2026-06-08 A007 Batch 116 packet handler split:
  - Before: score `82/88`; `0x004aea80` was mentioned only as an unsplit aggregate helper.
  - After: score `85/89`; added exact child [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), keeping final C++ blank.
  - Summary/evidence: current IDA MCP confirms the `0x30`-byte vtable-only helper, vtable ref `0x00619efc`, `0x42/0x04` packet check, `this - 0xa0` adjustment, close helper call, and direct AddItemDialog ownership. This raises the class above the strict 85/85 parent gate for the new child.
- 2026-06-10 B001-026 split repair:
  - Added exact core child [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md), exact raw helper child [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md), and linked the non-emitting mixed destructor/thunk strip [UID:00033Y][0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip](by-memory/0x004b08a1-0x004b0b15.ItemExchangeDestructorAndThunkStrip.md).
  - Evidence: B001 IDA disassembly confirmed the raw helper body that the broad aggregate had not split; class score remains `85/89`, which clears the direct-parent gate.
- 2026-06-12 A004 vtable split:
  - Added source-local vtable child [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md); score remains `85/89`.
  - Evidence: live IDA MCP reconfirmed the exact `AddItemDialog` vtable cluster and boundary before `MyItemListPane`.
- 2026-06-20 B003 Rule 26 source-quality sync for [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md):
  - Changed from `85/89` to `86/90`.
  - Added the `+0x26c` exchange/context id naming decision, `SendSelectedItemPacket(char selectedInventorySlot)` role, no-direct-route PE scan result for the retained helper/accessor island, inline-equivalent `0x004ae930` action-send loop, `0x4A/1` packet semantics, and local scratch terminator distinction.
  - Evidence: B003 report `00033R-AddItemDialogSubmitPacketHelper-source-quality.md` plus existing AddItemDialog core, singleton-global, MyItemListPane, PacketBuffer, and Socket send docs.
