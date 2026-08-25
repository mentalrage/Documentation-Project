*** UID:0000KE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ItemDialogs

## UID0000LO Gate 2A AddMixing Header Closure - 2026-08-14

UID000009 now emits a complete AddMixingItemDialog class declaration through
`ItemDialogs.h` and routes its existing constructor/action children through
`ItemDialogs.cpp`. The declaration records the `MixItemDialog *` owner at
`+0x270`, exact `0x274` class size, and matching constructor/action signatures.
The prior generated UID000009 Empty Emitter Marker is therefore superseded;
compiler adjustor/deleting-destructor artifacts remain non-emitting. The file
score stays `92/92`: this fixes an implementation omission without changing the
remaining original-file-split and lexical confidence caps.

## UID0000LO Accepted MyItemListPane Fold - 2026-08-14

`NexusTK/ui/dialogs/ItemDialogs.cpp` and `ItemDialogs.h` are the sole physical
source route for MyItemListPane. The accepted ordered class routes are
AddItemDialog at file position `10`, MyItemListPane at `20`, and
AddItemWithCountDialog at `30`; each class then emits its own children in
binary/source order. This preserves the observed contiguous sequence:
AddItemDialog methods through `0x004aea7d`, MyItemListPane constructor/accessor/
renderer at `0x004aeb30-0x004af031`, and AddItemWithCountDialog beginning at
`0x004af040`.

ItemDialogs H receives the H-only `MyItemListEntry` declaration, the complete
`MyItemListPane : public ListPane` declaration, and ordered child declarations.
ItemDialogs CPP receives `MyItemListPane` constructor, selected-slot accessor,
and row renderer after the class route's `[[CHILDREN]]` marker. The former
UID0000LO root remains documentation-only with path/owner `NONE`; a standalone
`MyItemListPane.cpp` is not part of the proposed source tree or generated
readback contract.

Required visibility is supplied by AddItemDialog's accepted include prefix:
`ItemDialogs.h`, EPFTileContext, ItemObjImageLib, Surface, and UserPane.
ClanBankPane includes ItemDialogs H at its first emitter, and ItemObjImageLib H
exposes `GetItemGlyphBounds` as a member. Constructor EH, vtables/RTTI,
deleting destructors, adjustor thunks, padding, literals, globals, and imports
remain compiler/shared dependencies and are not duplicated here.

All older separate-file and unresolved compact-layout statements below are
preserved as historical research and superseded by this accepted route.

## Status

- Confidence: very strong for item selection, MixItemDialog construction/class/lifetime, item-dialog singleton storage, and accepted generated route; the exact original physical split between ItemDialogs and a possible MixItemDialog file remains inferred.
- Proposed module folder: `ui/dialogs/`
- Projected reconstruction path: `NexusTK/ui/dialogs/`
- Candidate files: `ui/dialogs/ItemDialogs.cpp`, [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), `ui/dialogs/MixItemDialog.cpp`, and `ui/dialogs/ItemActionInputPanes.cpp`
- Historical generated-source inventory included `class_AddItemDialog.cpp`, `class_AddItemWithCountDialog.cpp`, `class_MyItemListPane.cpp`, `class_AddEmployeeItemDialog.cpp`, `class_MixItemDialog.cpp`, `class_AddMixingItemDialog.cpp`, and item-menu class files. The accepted route now generates source-bearing AddItemDialog children through `NexusTK/ui/dialogs/ItemDialogs.cpp`; employee and item-menu ownership corrections below remain in force.
- Placement update: `class_AddEmployeeItemDialog.cpp` is generated near item picker code, but 2026-05-24 IDA evidence ties final ownership to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Evidence basis: Wave3 metadata and targeted IDA MCP boundary/vtable checks on 2026-05-23, 2026-05-24, and 2026-05-26. Use [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) as the current IDA-backed layout anchor.
- Vtable split anchors: [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md), [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md), [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md), and [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md) carry the class-owned item-dialog vtable routes; [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) is retained as a non-emitting mixed index.

## Historical Source-Split Hypothesis

The item dialog code was likely grouped by gameplay UI feature rather than one class per file. The core file should own exchange/mix item-selection dialogs and item context menus; direct command input panes such as drop, give, use, wear, wield, and take-off likely live nearby in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).

Player-to-player exchange itself is now documented separately in [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). This file should keep the reusable item picker dialogs that exchange calls, but not absorb the live trade window, exchange packet dispatcher, money edit control, or exchange alerts.

Likely split:

```text
ui/dialogs/ItemDialogs.cpp
ui/dialogs/MyItemListPane.cpp
ui/dialogs/ItemMenuDialogs.cpp
ui/dialogs/MixItemDialog.cpp
ui/dialogs/ItemActionInputPanes.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/ItemDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `AddItemDialog` | `0x004ae4c0-0x004b096e`; exact constructor [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md); destructor [UID:0004BN][0x004ae900-0x004ae929.AddItemDialogDestructor](by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md); action [UID:0004BO][0x004ae930-0x004aea3a.AddItemDialogOnAction](by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md); updater [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md); packet-close child UID000317; retained helper/accessor island UID00033R | `NexusTK/ui/dialogs/ItemDialogs.cpp` | Modal item selection dialog. Exact source order is constructor `10`, ordinary destructor `20`, OnAction `30`, and virtual UpdateActionButton `40`, followed by packet-close/accessor/send helpers. UpdateActionButton resolves action control 1 and scroll wrapper 3, calls inherited ListPane integer selection count, and dispatches Enable/Disable without null checks. The live OnAction path unwraps the same wrapper and inlines opcode `0x4A/1` sends; vptr resets, DialogPane teardown, delete dispatch, and adjustors are compiler-only. |
| `AddItemWithCountDialog` | Constructor [UID:0004BQ][0x004af040-0x004af371.AddItemWithCountDialogConstructor](by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md); control command [UID:0004BR][0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand](by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md); updater [UID:0004BS][0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton](by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md); packet event [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md); retained helper [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | `NexusTK/ui/dialogs/ItemDialogs.cpp` | Direct `DialogPane` subclass with exact source positions `10/20/30/40`; builds localized DLGEXC3 count controls for a signed local inventory slot, sends opcode `0x4a/2`, and closes through EventHandler packet `0x42/0x04`. The raw submit helper is retained/no-route with blank formal C++. |
| `MyItemListPane` | `0x004aeb30-0x004af031` | accepted `NexusTK/ui/dialogs/ItemDialogs.cpp` route; historical `class_MyItemListPane.cpp` only | Player inventory item-picker list used by add-item, mix-item, and clan-deposit flows; exact route order is class position 20 with constructor/accessor/renderer positions 10/20/30. |
| `AddEmployeeItemDialog` | `0x004a4ae0`, `0x004a4b20-0x004a4d3a` | `class_AddEmployeeItemDialog.cpp` | Employee-specific `AddItemDialog` variant; final owner is likely [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), while the base picker remains here. |
| `MixItemDialog` | Exact constructor [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md), action/table split index [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md), retained submit helper [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md), and quantity children [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md), [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md) | accepted `NexusTK/ui/dialogs/ItemDialogs.cpp` route; historical `class_MixItemDialog.cpp` only | DialogPane/Singleton-derived no-field class; constructor builds the exact MIXITEM controls and local-list wrapper, action handles add/remove/submit/cancel, quantity helpers populate rows, and opcode `0x6b` submission has live inline plus retained no-route forms. |
| `AddMixingItemDialog` | `0x004b0000-0x004b09cf` | `class_AddMixingItemDialog.cpp` | Item picker used by the mix dialog; filters already selected items and handles stack quantity flow. |
| `AddItemDialog` vtables | [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md) | by-vtable child | Source-local primary/secondary/tertiary vtable documentation routed to [UID:000007][AddItemDialog](by-class/AddItemDialog.md). |
| `AddItemWithCountDialog` vtables | [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md) | by-vtable child | Source-local primary/secondary/tertiary vtable documentation routed to [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md). |
| `MixItemDialog` vtables | [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md) | by-vtable child | Source-local primary/secondary/tertiary vtable documentation routed to [UID:00008J][MixItemDialog](by-class/MixItemDialog.md). |
| `AddMixingItemDialog` vtables | [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md) | by-vtable child | Source-local primary/secondary/tertiary vtable documentation routed to [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md). |
| [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) | `0x0069b328-0x0069b330` | generated global-data slots | Active `AddItemDialog` and `MixItemDialog` singleton pointers now split from the former mixed `.data` cluster. |
| [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md) caller use | `0x00530640-0x00530cf7` | `class_NumberInputDialog.cpp` | Reusable numeric prompt invoked by item-mixing quantity paths; implementation should stay in `ui/dialogs/NumberInputDialog.cpp`, not this file. |
| `ServerItemMenuDialog` | [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md) | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | Server-provided item action menu over the shared merchant-menu dialog base; exact method child now carries first-draft C++. |
| `ServerItemMenuItemList` | [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | Private row-list widget for server-provided item menu entries; corrected row has no `actionId` and sends selected/caller-supplied row names. |
| `ClientItemMenuDialog` | [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | Client-side item action context menu over the shared merchant-menu dialog base; exact method child now carries first-draft C++. |
| `ClientItemMenuItemList` | [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) | [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) | Private row-list widget for client-side item action entries; corrected row stores `actionId`, item id/style, and name. |

## AddItemDialog Constructor Source Disposition

- UID0004BM is one exact source-authored constructor at `0x004ae4c0-0x004ae8f5`; ten-byte pre-padding and eleven-byte post-padding remain outside it. Its `__thiscall` ABI uses two four-byte stack slots and `retn 8`.
- Source begins with `DialogPane(L"",9,1)`. The three AddItemDialog vptr stores and ten allocation cleanup states plus base cleanup are compiler-generated ABI/EH lowering, not extra ItemDialogs source statements or children.
- EPF layout uses `DLGEXC2.EPF`, `PAL01.PAL`, bounds `241x340`, button rectangles `(55,303,118,327)` and `(132,303,195,327)`, list wrapper `(30,30,218,270)`, and inset 13. EPD uses `DLGEXC2.EPD`, `NPAL8.PAL`, bounds `287x277`, button rectangles `(69,225,141,241)` and `(146,225,218,241)`, wrapper `(36,61,251,205)`, and inset 0.
- Both branches add background, action id 36, cancel id 22, and scroll/list wrapper in order. Hover/focused/pending selectors are `3/1/2`; there is no explicit selector-bearing AddChild source call.
- MyItemListPane is local and transferred to ScrollableControlPane. EPF passes `allowMultipleSelection` to UID0004LX; EPD forces value one. No `m_itemList` or persistent byte-mode AddItemDialog field exists.
- Common source tail stores `m_exchangeSessionId` at `+0x26c`, invokes OnCreate using `g_mainUiLayerSlots.overlayPaneLayerContext`, OnShow using `g_pBackPane`, and SlideOpenVertical, then publishes `g_pAddItemDialog` last.
- Five callers span employee, exchange, mix, and add-mixing flows. Exact AddItemDialog allocation is `0x270`; employee/mixing derived allocations are `0x274` and use their own dword at `+0x270`.
- Historical generated UID0004BM output used `Dialog`, `packetType`/`mode`, `CreateItemDialogControls`, `m_itemList`, explicit AddChild, early singleton publication, and a direct constructor-time UpdateActionButton call. Direct binary evidence rejects those current-source claims. The direct-call negative remains true, but constructor `OnCreate` synchronously reaches the updater through generic wrapper `0x0049fe20` and virtual slot `+0x4c`.

## AddItemDialog Destructor Source Disposition

- [UID:0004BN][0x004ae900-0x004ae929.AddItemDialogDestructor](by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md) is the exact ordinary, non-deleting destructor at source position `20`, immediately after constructor position `10` in `NexusTK/ui/dialogs/ItemDialogs.cpp`.
- Exact bytes install AddItemDialog vptrs at `this+0x00`, `this+0xa0`, and `this+0xa4`, unconditionally store zero to `g_pAddItemDialog` at `0x004ae91a`, and tail-jump to DialogPane cleanup `0x0049d9f0`.
- The source body contains only the unconditional singleton assignment. There is no singleton load, `this` comparison, conditional branch, or evidence for a guard; historical guarded-clear output is superseded.
- The three direct ordinary-destructor xrefs are `0x004a4d06` from the AddEmployee scalar wrapper and EH cleanup calls `0x005fe61e`/`0x005fe6db` associated with AddMixing construction paths.
- Vtables use scalar wrapper `0x004b0910` and adjustors `0x004b08a1`/`0x004b08ac`, not the ordinary destructor directly. Wrapper `0x004b0970` repeats the inherited teardown for AddMixingItemDialog.
- Exact singleton zero stores at `0x004ae91a`, `0x004b0930`, and `0x004b0990` are one authored statement plus two compiler-expanded wrapper copies. Generated source must emit the ordinary destructor once and must not emit explicit vptr assignments, base-destructor calls, delete calls, or adjustor bodies for UID0004BN.
- AddItemDialog RTTI (COL `0x00647318`, type descriptor `0x00675cc8`, hierarchy descriptor `0x00646ad4`) identifies direct DialogPane inheritance and the Pane/GrafPort/LObject/EventHandler/TimerHandler ancestry. It provides no `Singleton<AddItemDialog>` base route.
- Padding `[0x004ae8f5,0x004ae900)` and `[0x004ae929,0x004ae930)` remains non-emitting inventory outside the function.

## AddItemDialog Action And Updater Source Disposition

- [UID:0004BO][0x004ae930-0x004aea3a.AddItemDialogOnAction](by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md) is source position `30`; selector `3` resolves ScrollableControlPane, `GetScrollablePane()` exposes the owned ListPane/MyItemListPane, and the accepted packet loop remains unchanged apart from that corrected access path.
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) is source position `40`, exact virtual slot `+0x4c`, range 61 bytes, 23 instructions, and three CFG blocks. Six leading and three trailing `0xcc` bytes are external alignment.
- The updater resolves zero-based control insertion indexes `1` and `3`. Selector 1 is ImageButtonControlPane; selector 3 is ScrollableControlPane, whose `m_scrollablePane` at `+0x108` is dynamically MyItemListPane and generically ListPane.
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) returns integer selection count, including values greater than one. Positive selects ImageButton virtual `Enable` slot `+0x4c`; zero/nonpositive selects `Disable` slot `+0x50`.
- No action-button, wrapper, or list null test exists. There is no boolean `SetEnabled` call and no AddItemDialog control/list field. Historical `ButtonPane`, direct selector-to-ListPane, `HasSelection`, `SetEnabled`, and null-test output is superseded.
- AddItem `0x00619ed8`, AddEmployee `0x00619120`, and AddMixing `0x0061a170` route their primary `+0x4c` slot to UID0004BP. AddItemWithCount `0x0061a038` points to its separate `0x004af480` override.
- Constructor `OnCreate` calls generic refresh wrapper `0x0049fe20`; the wrapper has ten direct callers and reaches the target only for dynamic AddItem-family receivers. This corrects the old broad no-constructor-refresh claim without inventing a direct constructor call.
- Eight structural sibling updaters corroborate the child/count/two-tail source pattern. No exact duplicate UID0004BP body exists, and no target split, third-party import, or generated-file manual edit is appropriate.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x004ae4c0`, `0x004ae900`, `0x004ae930`, `0x004aea40`, and `0x004b0910` for `AddItemDialog`.
- 2026-07-13 UID0004BM reanalysis resolves the constructor as a `0x435`-byte, 398-instruction, 48-block function with five callers, exact branch/control/resource/lifecycle behavior, object size `0x270`, and no target-internal split. The second argument configures generic ListPane helper UID0004LX rather than a stored dialog mode.
- 2026-07-13 UID0004BN reanalysis resolves the destructor as a `0x29`-byte, five-instruction, two-block ordinary destructor with complexity 1. It has three direct callers, one unconditional singleton clear, direct DialogPane base teardown, and no guarded comparison; scalar wrapper copies remain compiler artifacts.
- `0x004af040`, `0x004af380`, and `0x004af480` for `AddItemWithCountDialog`.
- `0x004aeb30` and `0x004aec90` for `MyItemListPane`; constructor callers are `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`.
- 2026-05-26 vtable follow-up confirms `MyItemListPane` table bases `0x00619f28`, `0x00619fb0`, and `0x00619fe0`, with `DrawListEntry` at primary slot `+0x80`; see [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md).
- `0x004af570`, `0x004af8b0`, and `0x004b0ad0` for `MixItemDialog`.
- `0x004b0000`, `0x004b0120`, and `0x004b0970` for `AddMixingItemDialog`.
- 2026-06-07 Batch038 IDA refresh confirms the item-dialog singleton slots now split as [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md): `0x0069b328` refs at `0x004ad670`, `0x004ade32`, `0x004ae8d2`, `0x004ae91a`, `0x004aeab0`, `0x004b0930`, `0x004b0990`; `0x0069b32c` refs at `0x004af5c7`, `0x004af5ce`, `0x004b0870`, `0x004b0ad6`, `0x005a4e03`, and `0x005a5fbb`.
- 2026-06-08 Batch 116 IDA MCP split four previously aggregate-only item/mix helpers: AddItemDialog packet-close handler `0x004aea80-0x004aeab0`, AddItemWithCountDialog packet-close handler `0x004af4c0-0x004af4f0`, MixItemDialog quantity prompt helper `0x004afcc0-0x004afe38`, and MixItemDialog quantity callback `0x004afe40-0x004afff7`.
- 2026-05-26 vtable pass confirms three-view dialog tables for `AddItemDialog`, `AddItemWithCountDialog`, `MixItemDialog`, and `AddMixingItemDialog`, with object vfptr offsets `+0x00`, `+0xa0`, and `+0xa4`; see [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md).
- 2026-06-12 A004 vtable split refresh creates exact source-local vtable children [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md), [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md), [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md), and [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md). Live IDA MCP reconfirmed the decorated bases, slot target sizes, store refs, exact successor boundaries, and unique signatures; [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) is now only the mixed family index.
- 2026-06-20 B003 Rule 26 source-quality sync confirms [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md) as the `GetActiveAddItemDialog` accessor plus retained/no-direct-route `AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)` helper for opcode `0x4A/1`. PE scans found no direct caller/pointer route to `0x004aeab0` or `0x004aeac0`, while [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md) contains the live inline-equivalent selected-row send loop. Keep the helper in `ItemDialogs.cpp`; ExchangeDialog supplies the exchange id but does not own the picker implementation.
- [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) is retained AddItemWithCountDialog submit code, not padding. Raw PE scans found no route to its start, while live UID0004BR `OnControlCommand` contains equivalent packet serialization inline after parsing/clamping. Its formal C++ stays blank by resolved no-code policy: emitting an invented helper in addition to the live body would create unsupported duplicate source.
- AddItemWithCount exact class/source contract: direct base `DialogPane(L"",9,1)`; object size `0x274`; `unsigned int m_exchangeSessionId` at `+0x26c`; signed `char m_inventorySlot` at `+0x270`; natural tail alignment only. The constructor builds the DLGEXC3 background, action/cancel buttons, localized id-158 display-name prompt, and selector-4 count editor before create/show/open lifecycle. `OnCreate` synchronously reaches generic refresh and the class-specific `+0x4c` updater after controls/fields exist.
- UID0004BR is `void OnControlCommand(int controlIndex, int notifyCode)`, not `OnAction`: control 1 reads selector-4 text with capacity 4, scans `"%hu"`, clamps `>=0xff`, writes/sends eight packet bytes using `m_inventorySlot`, then slides/closes; control 2 only slides/closes. UID000318 is `bool HandlePacketEvent(Event *event)`, not `OnClosePacket`: it checks `event->packet` for `0x42/0x04`, slides/closes, and always returns false; the `this-0xa0` adjustment is compiler lowering.
- UID0004BS remains an independently owned target page. Its established contract is selector-4 `IsEmpty()` with distinct selector-1 ImageButton `Disable()`/`Enable()` calls and no numeric validation/null test. This file records its position and route without overriding that page.
- 2026-06-22 B009 Rule 26 source-quality sync confirms [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) is retained `MixItemDialog::SubmitMixPacket()` helper code for opcode `0x6b`, not compiler glue or aggregate padding. Raw PE scans found no VA/RVA/raw pointer route and no direct `.text` branch/call route to `0x004afb80`, while [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) case 3 at `0x004afa3a` duplicates the packet send inline. The helper is now first-draft C++ ready on the exact child page; keep it documented under `ItemDialogs.cpp` unless a future source split moves the whole `MixItemDialog` family together.
- `0x0051a520`, `0x0051acb0`, and `0x0051ae50` for `ServerItemMenuDialog`.
- `0x0051ae90` is raw constructor-shaped code for `ServerItemMenuItemList`; IDA confirms the vtable virtuals at `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0`.
- `0x0051b880`, `0x0051c310`, and `0x0051c430` for `ClientItemMenuDialog`.
- `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0` for `ClientItemMenuItemList`, with raw helper-shaped code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`.

IDA reports no function at Wave3's `AddEmployeeItemDialog` constructor start `0x004a4ae0`; this is tracked in [wave3_data_issues](../wave3_data_issues.md). A 2026-05-24 recheck shows `EmployeeDialogPane::OnButtonAction` constructs an `AddItemDialog`, then patches its vtables to `AddEmployeeItemDialog`; a 2026-05-27 recheck still finds no function/xrefs or raw pointer-table references to `0x004a4ae0`. Source migration should attach the employee-specific subclass to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) unless stronger original-file evidence appears.

## MixItemDialog Source And Compiler Inventory

- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md) is a `0x26c` `DialogPane` plus direct empty `Singleton<MixItemDialog>` class with no derived fields. RTTI's Singleton descriptor uses `mdisp=0x26c`, and both constructor callers and the scalar wrapper establish the same complete size.
- [UID:0004BT][0x004af570-0x004af8af.MixItemDialogConstructor](by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md) is the sole constructor emitter at source position 10. Its exact 831-byte body is parameterless, constructs `DialogPane(L"",9,1)`, builds the six-control `MIXITEM` tree, transfers a local parameterless MyItemListPane to ScrollableControlPane, sets selectors `1/3/4`, clears rows last-to-first, and completes create/show/vertical-open lifecycle.
- The constructor's background uses `MIXITEM.EPF` and `MIXITEM.PAL`; four buttons use IDs `36`, `21`, `14`, `22`; wrapper bounds are `(37,68,264,236)`. `OnCreate` uses overlay context, and `OnShow` uses null/null rather than `g_pBackPane`.
- [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) is a non-emitting split index over constructor, one-byte alignment, OnAction, and switch-table/tail data. Its `Nested:8` is retained as a relative address-sorted delta, not a child count.
- OnAction's live case 3 at `0x004afa3a` inlines the opcode-`0x6b` packet send. Retained UID00033V has a complete source-shaped equivalent but no direct branch, call, table, vtable, VA/RVA, or raw-pointer route; preserve both facts without making the aggregate or retained route duplicate the live emitter.
- [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md) is the EH-only generated-binary `Singleton<MixItemDialog>` base-destructor instantiation. Its historical free `ClearActiveMixItemDialog` identity and body are superseded by exact bytes, sole EH xref, `this+0x26c` adjustment, RTTI, and the analogous Singleton comparator.
- [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md) is non-emitting compiler data. Its exact primary/secondary/tertiary tables are `0x0061a088`, `0x0061a0e8`, `0x0061a118`; RTTI includes eight hierarchy entries and the Singleton EBO. No manual vtable/RTTI array belongs in source.
- [UID:0003NJ][0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings](by-memory/0x0061a37c-0x0061a3ac.MixItemDialogResourceStrings.md) is non-emitting source-derived literal storage. Its three target-only xrefs are covered by the constructor's two literal expressions; no duplicate byte-array or string object should emit.
- [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) emits the two exact zero-initialized typed declarations once. `g_pMixItemDialog` has six exact refs spanning Singleton construction/fallback, EH destruction, scalar destruction, and two open-if-null gates.
- Seven constructor allocation cleanup states, three vptr stores, security-cookie mechanics, scalar deleting wrapper `0x004b0ad0`, and adjustors `0x004b08f9/0x004b0904` are compiler lowering. They remain documented support and are not copied into source.
- Historical `Dialog`, manual singleton assignment, `m_itemList`, `new MyItemListPane(this)`, `CreateMixItemDialogControls`, `AddChild`, `ClearMixRows`, handwritten vtable arrays, and a handwritten clear helper are rejected by exact base/layout/data-flow/EH evidence.
- The accepted project route remains `NexusTK/ui/dialogs/ItemDialogs.cpp`. A separate original `MixItemDialog.cpp` is lexically plausible, but no source path string, PDB, or independent original file boundary outweighs the established current route. If later evidence proves a physical split, move the whole class family together.
- Generated-source expectation: the class declaration must close before `[[CHILDREN]]`; constructor R1 and every accepted Mix method must appear once; the two singleton globals appear once; UID00033U/UID00033X/UID0003IG/UID0003NJ must contribute no empty/unattached markers; no handwritten vtable/RTTI arrays or stale clear-helper body may appear.

## Ownership Notes

- Exchange/mix item selection is dialog/session UI, not inventory pane rendering. Keep it separate from [UID:0000KA][InventoryPane](by-file/InventoryPane.md) and item image code.
- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) is reusable player-inventory picker UI. Keep it adjacent to item dialogs or as its own `ui/dialogs/MyItemListPane.cpp`; do not migrate it into generic [UID:0000KT][ListPane](by-file/ListPane.md) or social/clan ownership just because clan deposit uses it.
- `MyItemListPane` consumes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) for icon drawing, but the singleton and draw routines remain owned by [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Player-to-player exchange session UI belongs to [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). `AddItemDialog` is invoked by exchange as a picker, but `ExchangeDialog`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, and `ExchangeAlertPane` should migrate as a separate source module.
- `AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)` and the singleton accessor stay in this item-dialog source family. The helper builds the client exchange action packet `0x4A/1` using the exchange/context id at `AddItemDialog+0x26c` and the selected inventory slot from `MyItemListPane`; the current binary has no direct route to the retained helper body, and the live action handler inlines the equivalent send loop.
- `AddItemDialog` construction also stays in this family: all five callers consume the reusable dialog, but none changes source ownership. The local MyItemListPane is transferred to ScrollableControlPane and configured through generic ListPane method UID0004LX; that helper itself remains owned by `ListPane.cpp`.
- `AddItemDialog` destruction also stays in this family: the exact ordinary body belongs beside the constructor in `ItemDialogs.cpp`; AddEmployee/AddMixing call and cleanup routes establish reuse but do not transfer source ownership. Compiler-expanded scalar wrappers and secondary-view adjustors remain non-emitting support evidence.
- Do not invent `AddItemWithCountDialog::SendSelectedItemWithCountPacket`. The retained [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) builds `0x4a/2` from exchange-session id, signed inventory slot, and count, but no branch/table/vtable route reaches it and live `OnControlCommand` inlines the same send before closing. Preserve raw evidence and blank formal C++.
- `MixItemDialog::SubmitMixPacket()` is the best descriptive name for the retained [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md) helper shape. It builds opcode `0x6b` from selector `5` mix-list row storage, emits count/item id bytes and optional one-byte quantity values from row `+0x208` when `g_pCollectionData` metadata `+0x1ec` marks the item quantity-tracked, sends through `g_packetSender`, and closes the dialog. No static branch/table/vtable route reaches `0x004afb80`, and live [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) action case 3 at `0x004afa3a` inlines the same send/close sequence.
- Batch 116 checked the overlapping [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) as a plausible parent/source candidate for the broad [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md) aggregate. The result is negative for direct ownership: this file owns the item/mix picker children, while [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) owns the exchange alert/money/control tail rows. No single direct source parent should be assigned to the broad overlapping aggregate.
- `AddMixingItemDialog` derives from `AddItemDialog` and stores a pointer back to `MixItemDialog`, so those files should stay adjacent even if split.
- The item dialog vtables sit immediately before/among adjacent `MyItemListPane`, `ExchangeAlertPane`, and `FieldMapPane` RTTI/table data. Use the confirmed table bases rather than a broad `.rdata` neighborhood when assigning class layout.
- Stackable item quantity prompts call [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md). Treat this as a reusable dialog dependency, not as proof that `NumberInputDialog` belongs in item-dialog source.
- `AddEmployeeItemDialog` also derives from/reuses `AddItemDialog`, but its owner pointer and command path are employee-specific. Keep it cross-referenced here but do not use it as generic `ItemDialogs.cpp` ownership proof.
- AddEmployeeItemDialog cross-reference clarified by B004 2026-06-18: `ItemDialogs` owns generic `AddItemDialog` construction, fallback button handling, and base destruction. The `AddEmployeeItemDialog` override [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) is employee-dialog-specific and should remain emitted through the `EmployeeDialogPane` source family. The retained raw constructor-shaped island [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) is layout evidence only under current no-route scans.
- Item context menus around `0x0051a520+` are later in memory than the exchange/mix constructors but are still item-action UI and should cross-reference this module. The stronger file-level split is now documented in [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md): [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) is a non-emitting split index, [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md) and [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) carry dialog method C++, and [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)/[UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) carry private row-list C++.
- Item context menu vtables share [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)'s [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md); keep that shared base adjacent but do not migrate it as item-only source.
- The item menu dialog/list vtables are directly covered by [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), with [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) retained as broader mixed-family context.
- Historical/superseded generated observation (recorded no later than 2026-06-20): the then-fragmented `ServerItemMenuItemList` output included article/mail pagination and shared `ListPane` helpers. This remains useful chronology for rejecting bulletin/mail ownership, but it no longer describes validator-owned output and never proved that bulletin/mail paging belonged in `ItemMenuDialogs.cpp`.
- Current clean unified generated truth (2026-08-23 owning-page refresh): validator-owned `NexusTK/ui/dialogs/ItemMenuDialogs.cpp` and required sibling `ItemMenuDialogs.h` are the UID0000KF output pair. The CPP contains exactly nine `ServerItemMenuItemList` definitions in source order: constructor, destructor, `AppendItem`, `SendSelectedItemName`, `SendItemName`, `OnItemSelected`, `OnItemActivated`, `OnMouseEvent`, and `DrawListEntry`; it contains zero case-insensitive `article`, `mail`, `pagination`, `PageUp`, or `PageDown` occurrences. The H carries the unified `ServerItemMenuItemList` declaration, and no legacy `class_ServerItemMenuItemList.cpp` exists anywhere under `source-3`. Shared `ListPane` implementation remains external, and bulletin/mail pagination remains outside ItemMenuDialogs ownership.
- Spell action context menus are a sibling family now covered by [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), not part of the item-dialog source itself.
- Clan item deposit/withdraw dialogs are intentionally deferred to a future clan-dialog module because their ownership is social/clan banking rather than generic item actions.

## Cross-References

- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0004BN][0x004ae900-0x004ae929.AddItemDialogDestructor](by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md)
- [UID:0004BO][0x004ae930-0x004aea3a.AddItemDialogOnAction](by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md)
- [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md)
- [UID:000008][AddItemWithCountDialog](by-class/AddItemWithCountDialog.md)
- [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md)
- [UID:00008W][MyItemListPane](by-class/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md)
- [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md)
- [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md)
- [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md)
- [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md)
- [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)

## Changes

- 2026-08-23 B006 CKF-041/CKF-054 bounded current-prose repair: preserved the former fragmented `ServerItemMenuItemList` article/mail/ListPane observation as explicitly historical/superseded chronology and replaced its active-current conclusion with the clean unified `ItemMenuDialogs.cpp` plus required `ItemMenuDialogs.h` route. Current generated evidence is exactly nine server-list definitions, zero `article`/`mail`/`pagination`/`PageUp`/`PageDown` occurrences, and no legacy `class_ServerItemMenuItemList.cpp` under `source-3`; shared ListPane and bulletin/mail ownership remain external.
- 2026-07-13 B003 UID0004BT callback: raised `91/90 -> 92/92` without changing `NexusTK/ui/dialogs/`; installed exact MixItemDialog constructor/class/layout/control/local-list/lifecycle/Singleton evidence; made UID00033U, UID0003IG, and UID0003NJ non-emitting; completed the validator-preserving UID00033X rename and reclassified it as the EH-only Singleton base destructor; retained typed globals and the live-versus-retained packet-helper distinction; historicalized stale decompiler-shaped source and recorded generated uniqueness/no-compiler-array requirements while preserving all concurrent AddItem/AddItemWithCount/MyItemListPane/menu evidence.

- 2026-07-13 UID0004BQ callback: preserved B005's current AddItem/ListPane/control additions and file score/route; replaced the stale `class_AddItemWithCountDialog.cpp` route with `NexusTK/ui/dialogs/ItemDialogs.cpp`, installed exact constructor/control/updater/packet-event/helper inventory and positions, corrected direct base/layout/signed-slot/callback/lifecycle evidence, and resolved retained-helper blank-formal policy.

- 2026-07-13 B005 UID0004BP callback: retained `91/90` and `NexusTK/ui/dialogs/`; added exact AddItem source order `10/20/30/40`, typed selector/wrapper/ListPane contracts, UID0004M9 integer helper, Enable/Disable tails, no-null and no-duplicate evidence, synchronous `OnCreate` refresh, AddItem/AddEmployee/AddMixing inherited routes, AddItemWithCount override exclusion, target padding, and generated-output expectations while preserving all unrelated item/mix/menu ownership and historical evidence.

- 2026-07-13 B001 UID0004BN callback: retained `91/90`; routed the exact source-ready ordinary destructor through `NexusTK/ui/dialogs/ItemDialogs.cpp` at position 20; recorded unconditional singleton semantics, exact instruction/caller/RTTI evidence, wrapper duplication and compiler exclusions, surrounding padding, generated-source uniqueness requirements, and superseded guarded-clear/singleton-base assumptions without changing unrelated dialog-family ownership.

- 2026-07-13 B001 UID0004BM callback: raised to `91/90`; routed the exact source-ready constructor through `NexusTK/ui/dialogs/ItemDialogs.cpp`; recorded exact ABI, branches, resources, control order, local-list ownership, UID0004LX dependency, context/lifecycle/singleton order, five callers/object sizes, compiler EH/vptr exclusions, and historicalized stale generated constructor tokens without changing unrelated dialog-family ownership.

- 2026-06-12 A004 Batch 324 vtable split:
  - What existed before: [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) was the only item-dialog vtable anchor and remained reconstructable despite mixed class/template ownership.
  - Changed to: exact source-local vtable children [UID:0003ID][AddItemDialogVtables](by-type/by-vtable/AddItemDialogVtables.md), [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md), [UID:0003IG][MixItemDialogVtables](by-type/by-vtable/MixItemDialogVtables.md), and [UID:0003IF][AddMixingItemDialogVtables](by-type/by-vtable/AddMixingItemDialogVtables.md) carry class-owned routes through the item-dialog class pages; this file remains `90/87`.
  - Summary/evidence: live IDA MCP reconfirmed all four exact vtable clusters, class store refs, slot target sizes, successor boundaries, and unique signatures.

- 2026-06-18 B004 AddEmployee boundary clarification:
  - What existed before: the page correctly treated `AddEmployeeItemDialog` as an employee-specific boundary but did not incorporate the latest source-quality result.
  - Changed to: documented that only generic `AddItemDialog` construction/fallback/destruction is an `ItemDialogs` dependency; [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) emits through `EmployeeDialogPane`, and [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) remains non-emitting retained constructor-shaped evidence.
  - Summary/evidence: B004 route scans reject standalone raw-constructor emission and tie the override to `EmployeeDialogPane` owner state, quantity prompt resources, and command event `5`.

- 2026-06-08 A007 Batch 116 helper split and parent-source check:
  - What existed before: `COMPLETION:89`, `CONFIDENCE:85`; the page had item-dialog singleton evidence but did not link exact children for the `0x004aea80`, `0x004af4c0`, `0x004afcc0`, and `0x004afe40` helper rows.
  - Changed to: `COMPLETION:90`, `CONFIDENCE:87`; added exact helper children [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md), [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md), and [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md), and documented the negative direct-ownership result for broad overlapping aggregate [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md).
  - Summary/evidence: current IDA MCP confirms the two packet-close handler vtable refs, the MixItemDialog stackable/non-stackable quantity flow, callback construction, callback-target stores, and row append behavior. This strengthens ItemDialogs as the direct parent for exact item/mix children while keeping the broad exchange-overlap aggregate unassigned.

- 2026-06-07 A009 Batch038 singleton split:
  - What existed before: `COMPLETION:88`, `CONFIDENCE:80`; the page documented item-dialog ownership but did not include the exact `.data` singleton split needed for corrected-gate assignment.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:85`; added [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) to proposed contents and recorded exact AddItemDialog/MixItemDialog singleton refs.
  - Summary/evidence: live IDA confirms both slots are item-dialog state, while ExchangeDialog and FpsPane data have been split to their own pages. This raises confidence only to the gate threshold because final source split between `ItemDialogs.cpp`, `MixItemDialog.cpp`, and sibling files remains a documented caveat.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: item picker, mix, menu-dialog, list-pane, employee-dialog boundary, vtable family, ownership notes, exchange/menu/action split, and cross-references are well documented; confidence is capped by exact original split among item dialogs, exchange, mix, context menus, and item-action input files.
- 2026-06-03 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though this page and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already placed `ItemDialogs.cpp` under `ui/dialogs/`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Summary/evidence: the page's status, proposed contents, and project-structure entry consistently place the item picker/mix/menu dialog family under `ui/dialogs/`; this assignment allows attached child documentation such as [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md) to resolve to a concrete generated source root while preserving the documented caveat that some adjacent classes may later split into `MyItemListPane.cpp`, `ItemMenuDialogs.cpp`, or `MixItemDialog.cpp`.
- 2026-06-20 B002 ItemMenuDialogs Rule 26 cross-reference: score unchanged. Updated item-menu context rows to point at [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), exact dialog children [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)/[UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md), row-list children [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)/[UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md), and dedicated [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), while preserving this page as broader item-dialog context rather than the direct item-menu owner.
- 2026-06-20 B003 AddItemDialog retained packet-helper sync: score unchanged. Updated the AddItemDialog proposed-contents row, IDA evidence, and ownership notes for [UID:00033R][0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper](by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md), including source names `GetActiveAddItemDialog` and `AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)`, `0x4A/1` selected-slot packet semantics, no-direct-route PE scan caveat, live inline-equivalent send loop, and `ItemDialogs.cpp` source placement.
- 2026-06-19 B011 AddItemWithCount retained packet-helper sync: score unchanged. Updated the AddItemWithCountDialog proposed-contents row, IDA evidence, ownership notes, and cross-references for [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md), including opcode `0x4A/2` count-aware packet semantics, no-direct-route PE scan caveat, live inline-equivalent action send, scratch-zero-as-unsent-byte semantics, and `ItemDialogs.cpp` source placement.
- 2026-06-22 B009 MixItemDialog retained packet-helper sync: score unchanged. Updated the MixItemDialog proposed-contents row, IDA evidence, ownership notes, and cross-references for [UID:00033V][0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper](by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md), including opcode `0x6b` mix-submit packet semantics, selector `5` mix-list route, count/item/quantity byte serialization, no-direct-route PE scan caveat, live inline-equivalent action case 3 at `0x004afa3a`, `g_pCollectionData` and `g_packetSender` dependencies, close/dismiss tail, first-draft helper C++ readiness, and `ItemDialogs.cpp` source placement.
- 2026-06-30 B007 ItemDialogs empty-emitter implementation: raised confidence from `87` to `88` after applying the accepted B007 source-quality report. Converted [UID:00033Q][0x004ae4c0-0x004aea7d.AddItemDialogCore](by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md), [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md), and [UID:00033U][0x004af570-0x004afb80.MixItemDialogCore](by-memory/0x004af570-0x004afb80.MixItemDialogCore.md) to `[[CHILDREN]]` aggregate emitters with exact constructor/action/update/switch-table child pages. Inserted first-draft formal C++ for [UID:000317][0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler](by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md), [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md), [UID:000319][0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper](by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md), [UID:00031A][0x004afe40-0x004afff7.MixItemDialogQuantityCallback](by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md), [UID:0002U1][0x004b0000-0x004b0118.AddMixingItemDialogConstructor](by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md), [UID:0002U2][0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm](by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md), [UID:00033X][0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor](by-memory/0x004b0870-0x004b087b.MixItemDialogSingletonBaseDestructor.md), and [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md). Preserved [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) as a retained raw helper with blank formal C++; no modeled IDA function at `0x004af4f0` remains route/modeling evidence only, not padding proof. Current B007 MCP bytes for [UID:0002AY][0x0069b328-0x0069b330.ItemDialogSingletonGlobals](by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md) supersede older `0xffffffff` singleton-initializer assumptions and support zero-initialized `g_pAddItemDialog` / `g_pMixItemDialog` declarations.
