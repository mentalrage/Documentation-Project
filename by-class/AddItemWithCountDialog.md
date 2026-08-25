*** UID:000008 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class AddItemWithCountDialog : public DialogPane
{
public:
    AddItemWithCountDialog(unsigned int exchangeSessionId,
                           char inventorySlot);

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePacketEvent(Event *event);
    virtual void UpdateActionButton();

private:
    unsigned int m_exchangeSessionId;
    char m_inventorySlot;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AddItemWithCountDialog

## UID0000LO Accepted ItemDialogs Order - 2026-08-14

This class remains behaviorally unchanged and now has explicit ItemDialogs file
position `30`, after folded MyItemListPane position `20`. Its own child order,
owner UID0000KE, score `91/93`, and formal declaration/body routes are
preserved. The position closes deterministic generation order without moving
any AddItemWithCountDialog address or source responsibility.

## Status

- Confidence: very strong for behavior, exact layout, callback contracts, and item-dialog module placement.
- Likely source file: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- Address range: [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- Vtable/layout anchor: [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md); mixed index [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- Parent attachment: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) is the established `NexusTK/ui/dialogs/ItemDialogs.cpp` source route.
- Rebuild handling: source-authored direct `DialogPane` subclass with complete class declaration and recursively emitted constructor/callback children.

## Class Purpose

`AddItemWithCountDialog` is the exchange quantity dialog for one signed local inventory-slot selection. It constructs its own prompt/count/action/cancel controls, sends opcode `0x4a` subcommand `2` with exchange-session, slot, and count state, and closes on the corresponding exchange packet event.

## Class Shape

- Base relationship: direct `DialogPane` subclass. [UID:000007][AddItemDialog](by-class/AddItemDialog.md) is a source sibling, not a base class.
- Vtable family: primary/secondary/tertiary tables at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`.
- Class-specific updater: primary cell `0x0061a038`, relative `+0x4c`, points to `0x004af480`; this class overrides the AddItemDialog updater and must not be routed to UID0004BP at `0x004aea40`.
- Role split: this class owns the item-specific count dispatch path; generic numeric input behavior should remain with the reusable numeric/dialog input classes.
- Stored constructor state: `unsigned int m_exchangeSessionId` at `+0x26c` and signed `char m_inventorySlot` at `+0x270`, followed only by natural tail alignment.
- Source placement: [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Ownership And Boundary Evidence

| Evidence | Meaning |
| --- | --- |
| [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) lists `AddItemWithCountDialog` in the reusable item-picker/mix source cluster. | The class belongs with generic item dialog source, not with the exchange session window or inventory rendering. |
| [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md) covers the quantity-aware add-item dialog range around `0x004af040-0x004af4b7`. | The class body is physically inside the reviewed item exchange/mix dialog island, with `0x004af4b7-0x004af570` alignment before `MixItemDialog`. |
| [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md) records constructor stores for the three dialog vfptr views. | The class is a concrete dialog variant using the same three-view layout as `AddItemDialog`, `MixItemDialog`, and `AddMixingItemDialog`. |
| [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) constructs this dialog from exchange packet data. | Exchange is a caller/consumer; it should not own the picker implementation. |
| [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) constructs this dialog directly for exchange packet subcommand `1`. | This is the live constructor route. UID00014M is a real retained duplicate caller with no current static route; neither consumer transfers class ownership to `ExchangeDialog.cpp`. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AddItemWithCountDialog` constructor | [UID:0004BQ][0x004af040-0x004af371.AddItemWithCountDialogConstructor](by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md) | Direct `DialogPane(L"",9,1)` construction, five controls, localized inventory prompt, field stores, create/show/open lifecycle. |
| `OnControlCommand` | [UID:0004BR][0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand](by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md) | Primary `+0x48` override with source contract `void OnControlCommand(int controlIndex, int notifyCode)`; control 1 reads/clamps/sends and controls 1/2 close. |
| `UpdateActionButton` override | [UID:0004BS][0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton](by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md) | Primary `+0x4c` override; selector-4 empty text disables selector-1 ImageButton, otherwise enables it. `OnCreate` reaches it synchronously through generic refresh. The target page is independently B002-owned. |
| `HandlePacketEvent` | [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md) | EventHandler secondary `+0x10` override; packet `0x42/0x04` slides/closes and all paths return false. The `this-0xa0` adjustment is compiler lowering. |
| `SubmitPacketHelper` | [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) | Retained no-route raw helper that serializes `{ 0x4a, 2, exchangeSessionId, inventorySlot, count }`. `OnControlCommand` contains the equivalent live send inline, so this helper remains reconstructable with blank formal C++. |

## Reconstruction Notes

- Treat this as a reusable `ItemDialogs` dialog variant. Exchange passes the session and signed local slot into it, but the class implementation stays with item-dialog UI.
- Do not fold it into [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md); this class owns item-specific selection/count dispatch, while number-entry behavior remains a reusable dialog dependency.
- Emit the managed class declaration above. Constructor parameters, fields, inherited callback contracts, layout, and source order are resolved to implementation-ready quality; only original lexical spellings and access specifiers remain inferred.

## Exact Layout And Lifecycle

| Offset | Size | Source-facing member | Evidence |
| --- | ---: | --- | --- |
| `+0x000` | `0x26c` | `DialogPane` base | Direct base constructor call and accepted DialogPane size. |
| `+0x26c` | `4` | `unsigned int m_exchangeSessionId` | Constructor store; control-command and retained-helper packet serialization. |
| `+0x270` | `1` | `char m_inventorySlot` | Constructor signed-byte store; `GetInventorySlotAddress(char)` and packet-byte reuse. |
| `+0x271` | `3` | natural tail alignment | Both callers allocate exact total `0x274`; no authored padding field is required. |

The constructor installs primary/EventHandler/tertiary vptr views at `+0`, `+0xa0`, and `+0xa4` as compiler effects. It builds controls before storing the two members, then calls `OnCreate`, `OnShow`, and `SlideOpenVertical`. `OnCreate` synchronously calls generic refresh `0x0049fe20`, which dispatches virtual `+0x4c` only after the class is fully initialized. No singleton publication, direct updater call, or AddItemDialog base behavior exists.

The class declaration intentionally omits raw offsets, explicit padding, vptr fields, EH cleanup, and retained-helper declarations. The compiler supplies the three vtable views and secondary-this adjustment; the no-route helper remains documented as binary/source-retention evidence without being invented as a declared member.

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-06-06 confirms exact half-open ranges `0x004af040-0x004af371`, `0x004af380-0x004af47a`, and `0x004af480-0x004af4b7`; `0x004af4b7` is not a function and is followed by alignment before `MixItemDialog` starts at `0x004af570`.
- IDA MCP `callers 0x004af040` reports the two constructor call sites: [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) at `0x004ad3bf` and [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) at `0x004adaeb`.
- 2026-07-13 B003 rechecked both constructor callers. Dispatcher `0x004ad3bf` is the live route; retained helper `0x004adaeb` has no current static route. Both allocate `0x274` and pass the exchange id plus signed local inventory slot from packet `+2`; this slot is stored at `+0x270` and later serialized in opcode `0x4a` subcommand `2` with the count, while the exchange id is stored at `+0x26c`.
- IDA MCP `xrefs_to 0x004af380` and `0x004af480` reports data refs at `0x0061a034` and `0x0061a038`, matching the class-specific action/update virtual slots in the AddItemWithCountDialog vtable.
- Exact comparison with AddItemDialog confirms `0x00619ed8 -> 0x004aea40` for UID0004BP and `0x0061a038 -> 0x004af480` here. Generic DialogPane refresh wrapper `0x0049fe20` dispatches the receiver's current `+0x4c` slot, so AddItemWithCount receivers do not execute UID0004BP.
- IDA MCP vtable checks confirm table bases at `0x00619fec`, `0x0061a04c`, and `0x0061a07c`, installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`; live constructor stores are `0x004af0ae`, `0x004af0b4`, and `0x004af0be`.
- 2026-06-12 A004 split refresh adds source-local by-vtable child [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md), routed here at child `88/92` with this direct parent at `85/89`; live IDA MCP reconfirmed the exact `0x00619fe8-0x0061a084` cluster, decorated bases, slot target sizes, successor boundary, and unique signature.
- Constructor evidence records the exact member stores at `+0x26c/+0x270`, resolves the signed slot through the local-inventory accessor, formats LanguageMan id 158 with record `displayName`, and builds the exact background, action, cancel, prompt, and count controls.
- Action decompilation reads child selector `4` as the count input, parses it with wide `"%hu"`, clamps values `>= 0xff` down to `255`, serializes packet bytes `0x4a` and `2`, includes the context dword from `this+0x26c`, includes the stored item/type byte from `this+0x270`, and sends an eight-byte record.
- 2026-06-19 B011 raw PE/Capstone recheck confirms [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md) is real helper code, not padding, but has no exact branch/VA/RVA/vtable route. The helper reads exchange-session id and signed inventory slot, accepts a one-byte count, sends eight bytes, and writes a scratch zero outside the sent payload. The live control-command method builds the same packet inline after parsing and clamping the count.
- 2026-06-08 IDA MCP split the previously aggregate-only `0x004af4c0-0x004af4f0` helper: it has a vtable ref at `0x0061a05c`, no direct callers, checks packet bytes `0x42/0x04`, adjusts `this - 0xa0`, and calls close helpers `0x0049eb90` and `0x0049dad0`.
- 2026-06-10 B001-026 split the previously aggregate-only core and raw helper rows as [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) and [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md). The raw helper contradicts the stale target claim that `0x004af4f0-0x004af570` was padding.
- The class belongs with exchange/mix item dialogs rather than generic numeric input panes because it owns the item-specific dispatch.

## Score Rationale

- Completion `91` records the direct base, exact `0x274` layout, complete declaration, constructor/control/update/packet-event contracts, both callers and liveness, controls/resources/localization, lifecycle, vtable views, packet behavior, retained-helper disposition, source route, and corrected history.
- Confidence `93` reflects convergent binary, caller, vtable, class-layout, resource, and current API evidence. Original member/local spellings and whether callbacks were lexically public or protected are stripped, which keeps the page below final-audit certainty without blocking formal source.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md)
- [UID:00014T][0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0ba5.ItemExchangeMixDialogs.md)
- [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md)
- [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md)
- [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md)
- [UID:0001XV][ItemDialogVtableFamily](by-type/by-vtable/ItemDialogVtableFamily.md)
- [UID:000007][AddItemDialog](by-class/AddItemDialog.md)
- [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md)
- [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md)
- [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)

## Changes

- 2026-07-13 UID0004BQ callback: raised `85/89 -> 91/93`, inserted the exact managed class declaration, corrected the base from an ambiguous AddItemDialog variant to direct `DialogPane`, corrected item/type to signed inventory-slot state, resolved the exact `0x274` layout and callback signatures, historicalized the two-live-callers claim, and preserved the retained no-route helper/compiler-vtable exclusions.

- 2026-07-13 B005 UID0004BP support sync: score, owner/emitter, blank formal block, constructor/packet evidence, and ItemDialogs route remain unchanged; explicitly documented `0x0061a038 -> 0x004af480` as the class-specific `+0x4c` override and rejected routing AddItemWithCount receivers to UID0004BP.

- 2026-06-18 B003 exchange caller recheck:
  - Summary/evidence: added the [UID:00014M][0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper](by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md) caller-side confirmation that the two constructor calls to `0x004af040` are still dispatcher `0x004ad3bf` and retained helper `0x004adaeb`, that both pass the exchange id plus the selected item/type byte from exchange packet `packet+2`, and that this selected byte is the value stored at `this+0x270` and later serialized with opcode `0x4A` subcommand `2` and the user-entered count. Scores unchanged.

- 2026-06-06 live IDA attachment pass:
  - What existed before: the page was scored `72/86`, had no autogen parent, used stale source-owner wording, and recorded final-byte method endpoints.
  - What changed: raised scores to `82/88`, attached the class to [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md), converted method rows to half-open IDA ranges, added constructor caller and vtable-slot evidence, documented stored offsets `+0x26c`/`+0x270`, documented confirm/count packet behavior, and kept final C++ blank below final-source quality.
  - Summary/evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, and byte-boundary checks on 2026-06-06 confirm the three method ranges, two live constructor call sites, data refs for action/update virtual slots, vtable constructor stores, child selector behavior, count clamp, packet serialization, and alignment before `MixItemDialog`.
- What existed before: the page was documented but still scored as unevaluated.
- What it was changed to: scores were set to `66/84`, and a short class-shape section now records vtable anchors, family relationship, role split, and source placement.
- Summary and evidence: IDA MCP confirms the three method starts and vtable bases, but the page still needs deeper field/parameter naming and full method-level cross-links before completion should be high.
- 2026-06-02: Raised from `66/84` to `72/86` after adding ownership/boundary and reconstruction notes.
  - Added evidence tying the class to `ItemDialogs`, the exact `ItemExchangeMixDialogs` range, the item-dialog vtable family, and the exchange helper that constructs it.
  - Kept reconstruction C++ blank because source-quality parameter names, inherited slot names, and count/item field layout are still open.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the constructor/action/dispatch method starts at `0x004af040`, `0x004af380`, and `0x004af480`, and `callers` showed the constructor is still reached from exchange item-dialog helpers. Parent attachment was deferred at that time because the class completion score was still below the 80+ attachment gate.
- 2026-06-08 A007 Batch 116 packet handler split:
  - Before: score `82/88`; `0x004af4c0` was mentioned only as an unsplit aggregate helper.
  - After: score `85/89`; added exact child [UID:000318][0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent](by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md), keeping final C++ blank.
  - Summary/evidence: current IDA MCP confirms the `0x30`-byte vtable-only helper, vtable ref `0x0061a05c`, `0x42/0x04` packet check, `this - 0xa0` adjustment, close helper calls, and direct AddItemWithCountDialog ownership. This raises the class above the strict 85/85 parent gate for the new child.
- 2026-06-10 B001-026 split repair:
  - Added exact core child [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) and raw helper child [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md).
  - Evidence: B001 IDA disassembly confirmed the raw `0x4a/2` packet helper; class score remains `85/89`, which clears the direct-parent gate.
- 2026-06-12 A004 vtable split:
  - Added source-local vtable child [UID:0003IE][AddItemWithCountDialogVtables](by-type/by-vtable/AddItemWithCountDialogVtables.md); score remains `85/89`.
  - Evidence: live IDA MCP reconfirmed the exact `AddItemWithCountDialog` vtable cluster and boundary before `MixItemDialog`.
- 2026-06-19 B011 retained submit helper recheck:
  - Score unchanged at `85/89`; method row and evidence now distinguish the active inline send in [UID:00033S][0x004af040-0x004af4b7.AddItemWithCountDialogCore](by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md) from retained no-route helper [UID:00033T][0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper](by-memory/0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md).
  - Evidence: B011 raw PE/Capstone checks confirmed no exact branch/VA/RVA/vtable route to `0x004af4f0`, corrected the scratch-zero-as-unsent-byte semantics, and tied the helper's fields to `this+0x26c` exchange/session id and `this+0x270` selected item/type token.
