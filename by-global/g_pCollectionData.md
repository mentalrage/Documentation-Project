*** UID:0000QK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pUserPane / g_pCollectionData

## UID0000LO MyItemListPane Consumer Link - 2026-08-14

[UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
uses `g_pUserPane->GetInventorySlotAddress(slotIndex)` to obtain each
`LocalInventorySlotRecord`. This is a read/member-call dependency only;
existing combined-global ownership, emitter, score, and storage dispositions
remain unchanged.

## Status

- Address: `0x0067a748` (`dword_67A748` in IDA)
- Memory doc: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- Canonical source-facing symbol: `g_pUserPane`
- Stable/historical page name: `g_pCollectionData`
- Symbol kind: semantic/global alias page for the active local-player `UserPane *` singleton and its typed feature views
- Direct owner file: [UID:0000P1][UserPane](by-file/UserPane.md) / local-player pane state; collection view documented in [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Confidence: very strong for address, lifetime owner, source-facing `UserPane *` type/name, collection offsets, and typed-view aliases.
- Emission policy: non-emitting support page. The single formal definition is on [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):

```cpp
class UserPane;

UserPane *g_pUserPane = 0;
```

Keep this page's formal C++ block blank to avoid a duplicate global definition.

## Purpose

`0x0067a748` is the source-level active `UserPane *` singleton. The canonical source-facing name is `g_pUserPane`; this stable `g_pCollectionData` page records aliases and typed views for link/search continuity.

The UID0001LM source-quality callback closes the prompt-constructor view without changing this alias page's `89/90` score, owner, route, or blank formal. Six `SpellInputPanes.cpp` constructors read `UserPane::m_spellCommandSlots[spellIndex - 1].prompt` through the public inline `GetSpellPromptText(char) const` accessor. The table begins at `+0x13a834`, each record is `0x148` bytes, and `prompt[80]` begins at `+0xa8`, exactly matching `dword_67A748 + 0x13a794 + 0x148*spellIndex`. This is further bounded evidence for canonical `UserPane *g_pUserPane` ownership; it does not create a separate `SpellManager`, collection pointer, spell-record global, accessor body, or second definition.

UID000415 adds the shared default-chat history view without changing this page's `89/90` score, alias status, blank formal, or sole-definition route. [UID:000415][0x005b3570-0x005b3670.SayInputPaneHandleKeyInput](by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md) calls `g_pUserPane->GetPreviousChatHistoryLine` and `GetNextChatHistoryLine`; [UID:000416][0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat](by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md) calls `g_pUserPane->SaveChatHistoryLine(wideText)`. The three members operate on `List *UserPane::m_chatHistory` at complete-object `+0x13eb04`. Historical `g_pCollectionData` remains a stable alias/path, not the source receiver spelling, and no second global or chat-owned storage is introduced.

The previous/next helpers use a caller-owned signed-short cursor and bounded wide destination; previous wraps from the oldest entry to the newest, next can return an empty string after the newest entry, and save ignores empty input, suppresses the newest duplicate, appends a copied line, and trims beyond ten entries. Adjacent `+0x13eb08/+0x13eb0c/+0x13eb10` recipient-history views remain separate and unchanged.

Existing collection and player-state docs use the same storage under several aliases:

- `g_pCollectionData` in `CollectionPane`;
- `g_pPlayerData` in `CollectionDialogPane` and `CollectionEntryControlPane`;
- `g_collectionProgressTable` in `CollectionBarControlPane`.

IDA shows all of these collection paths reading `dword_67A748`. Treat the collection names as typed views over `g_pUserPane`, not as separate storage declarations.

The accepted collection source view is [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md): `CollectionPlayerDataView` contains `CollectionGroupRecord groups[128]`, `groupCount`, and `metadataLoaded`. Source-bearing collection children reach it through mutable/const `UserPane::GetCollectionData()`. This is an inline-capable typed view over the same object beginning at `g_pUserPane+0x3ec8`; it does not create a `CollectionPlayerDataView *` global, allocation, lifetime, or second definition.

IDA MCP `py_eval` reports `0x0067a748` as a four-byte `.data` item with 505 direct xrefs, and the accepted B001 raw PE pass decoded 505 direct memory-operand references to `[0x67a748]`, so this is not collection-private storage even though collection docs use the `g_pCollectionData` view name.

The exact storage page ties pointer lifetime to [UID:0000P1][UserPane](by-file/UserPane.md): IDA-backed notes record `UserPane` construction storing `this` into `dword_67A748`, constructor failure cleanup clearing it, the non-deleting/scalar destructor paths clearing it, and a small clear helper at `0x005b7640`. The accepted B001 pass found only five writes to this address, all from UserPane constructor/destructor/clear paths. The direct parent therefore clears the strict assignment gate as `g_pUserPane`, while the collection-specific name remains a view alias rather than proof of collection-owned storage.

2026-05-27 IDA MCP recheck found another non-collection typed view: `ChangeSpellSlotInputPane::SubmitSpellSlotChange` reads spell-slot state at `g_pUserPane + 0x13a6ec + slot * 0x148` and clears byte `g_pUserPane + 0x13ead4` when either source/destination slot is active. This reinforces that collection and spell-slot names are local views of the active UserPane object.

2026-06-17 B001 source-quality reanalysis of [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md), [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md), and [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md) confirmed the same storage also backs local-player spell prompt and command-slot dispatch state. The spell input paths use the slot-record stride `0x148`, prompt/name text, learned/active flags, and the `+0x13ead4` guard/dirty flag through the `g_pUserPane` local-player view. Do not introduce a generated `SpellManager` or `g_pSpellMan` global for these uses without stronger source evidence.

2026-06-20 B002 ChangeSpellSlotInputPane source-quality sync refines the spell-slot view used by [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md): the slot byte is one-based and indexes `g_pUserPane + 0x13a6ec + slot * 0x148`; record-local byte `+0` is the active byte, and `+0x13ead4` is best treated as `m_spellSlotCacheDirty` / `m_spellSlotStateDirty`. In this path active-byte checks only decide whether to clear the dirty/cache byte; they do not suppress the outgoing spell-slot reorder packet after both slot bytes validate.

2026-06-21 B007 legacy SpellInventoryPane sync adds [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) as another spell-slot typed view over this storage. Legacy `SpellInventoryPane::CastSpell` uses one-based spell records at `g_pUserPane + 0x13a6ec + slot * 0x148`, record-local `+0` as learned/active, record-local `+4` as input type / cast route, and prompt/name material at record `+0xa8` / `+0x13a794 + slot * 0x148`. The older `+0x13a82c` wording in legacy spell-inventory docs is stale for that body, and generated `SpellManager` / `g_pSpellMan` names remain rejected for this global.

2026-06-23 B001 SpellMenuDialogs implementation adds the client spell-menu typed view: `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md` loops one-based spell slots `1..52`, tests the active byte at `g_pUserPane + slot * 0x148 + 0x13a834`, and copies display name text from `g_pUserPane + slot * 0x148 + 0x13a83c` into `by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md` rows. This is another local-player/UserPane spell-slot feature view, not a separate `SpellManager` or `g_pSpellMan` owner.

2026-05-27 IDA MCP recheck of `DropGoldInputPane` and `GiveGoldInputPane` found another item-command view: both gold submit paths check byte `g_pUserPane + 0x3ec0` before sending the drop/give gold packet. Document this as a UserPane/local-player item-command busy gate, not as collection-owned state.

2026-05-27 IDA MCP recheck of `WieldInputPane` and `WearInputPane` found another item-command view: both constructors call the local player-name helper with `g_pUserPane` / historical `dword_67A748` before formatting their prompt text. This reinforces that the storage is the broad active UserPane/local-player pointer, not collection-only data.

2026-05-27 IDA MCP recheck of `ThrowInputPane`, `UseInputPane`, and `EatInputPane` found the same item-command player-state view. All three constructors call the local player-name helper with `g_pUserPane`; `ThrowInputPane::OnSubmitInput` checks byte `g_pUserPane + 0x3ec0` before sending the direct throw packet, and `UseInputPane::OnSubmitInput` passes `g_pUserPane` into [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md).

2026-06-19 B001 accepted source-quality implementation updates this alias page after [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) became the single definition site for `UserPane *g_pUserPane = 0`. The old `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` names are retained as typed-view aliases; generated `g_pSpellMan`/spell-manager readings of this address are rejected.

2026-06-19 B007 EarthquakeEffecter support sync adds another non-collection typed view: [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) reads bytes at `g_pUserPane + 0x1c4` and `g_pUserPane + 0x1c5` while applying camera-lock axis suppression. The best-supported names are inferred `m_cameraLockEnabled` / `m_cameraLockActive` for `+0x1c4` and `m_cameraLockDirection` for `+0x1c5`. These bytes are local-player/UserPane camera state, not collection-list data and not generated `g_pAppMan` fields.

2026-06-20 B003 Rule 26 reanalysis adds the drop/give confirmation callback view: [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) captures this storage as the active local `UserPane *` target for `UserPaneItemActionCallbackObject`. DropAll/Drop bind `UserPane::SendDropItemPacket(signed char,bool)` and GiveAll/Give bind `UserPane::SendGiveItemPacket(signed char,bool)`. This strengthens the `g_pUserPane` source name; do not globally rename the stable `g_pCollectionData` page from this callback use alone.

## Collection Layout View

Observed collection offsets:

| Offset | Meaning |
| --- | --- |
| `+0x1340c8` | collection group count |
| `+0x13eb1d` | collection input lock feature-view alias for the broader UserPane/local input-lock byte |
| `+group * 0x2604 + 0x3ec8` | group loaded/active flag |
| `+group * 0x2604 + 0x3ec9` | group type/volume id |
| `+group * 0x2604 + 0x3eca` | total entry count |
| `+group * 0x2604 + 0x3ecb` | collected entry count |
| `+group * 0x2604 + 0x3ecc + entry * 0x4c` | logical entry record base; entry-local `+0x00` is the `Collections` column-2 `SimpleUString` |
| `+group * 0x2604 + 0x3ee4 + entry * 0x4c` | entry-local `+0x18` row name/key `SimpleUString` |
| `+group * 0x2604 + 0x3efc + entry * 0x4c` | entry-local `+0x30` `Collections` column-3 `SimpleUString`, not the entry base |
| `+group * 0x2604 + 0x3f14 + entry * 0x4c` | entry-local `+0x48` collected/unlocked state byte written from detail-dialog packet bits |

See [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) for the accepted exact feature-view structs. `sizeof(CollectionGroupRecord)==0x2604` and `128*0x2604==0x130200`, so the groups beginning at `+0x3ec8` end exactly at `+0x1340c8` for `groupCount`, followed by `metadataLoaded` at `+0x1340c9`.

## Other Player-State Views

Non-collection consumers currently observed through this same pointer:

| Offset | Meaning |
| --- | --- |
| `+0xa4` | UserPane timer-owner subobject view used by [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) before `MapPane::ExitToMenu(true)` |
| `+0x1a0` | heartbeat/session byte read by the Application heartbeat/status helper after a non-null `g_pUserPane` check |
| `+0x1c4` | inferred local-player/UserPane camera-lock enabled/active byte consumed by `EarthquakeEffecter::ApplyEffect` |
| `+0x1c5` | inferred local-player/UserPane camera-lock direction byte passed through MapPane direction-to-tile-delta helper `0x00505080` by `EarthquakeEffecter::ApplyEffect` |
| `+0x3cb1` | typed `unsigned char UserPane::m_huntersListFlag`; incoming UID000477 0x83 store, UID000470 checkbox read, UID00047B outbound read, and PartySearch write converge here; historical opaque `m_preCollectionState[0]` / `g_pPlayerData` view is superseded. |
| `+0x3cb2..+0x3eb1` | typed `wchar_t UserPane::m_partySearchSourceText[256]`, consumed by [UID:00047B][0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw](by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md) and PartySearch support; this is local-player UserPane state, not separate `g_pUserListDialogPane` storage. Two residual bytes at `+0x3eb2..+0x3eb3` preserve the next field at `+0x3eb4` and total class size. |
| `+0x3eb4` | current chat variety/mode, best source-facing name `m_currentSayMode`; ChattingVarietyPane writes mode values `0..4`, and [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) consumes it as the default/shout/whisper/group/clan dispatcher switch. |
| `+0x3ec0` | UserPane/local-player item-command busy gate used by drop/give gold and direct throw prompts before sending packets |
| `+0x133f08 + inventorySlot * 0x1fc` | local inventory slot record table used by [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md); record fields include `active`, `itemId`, `iconStyle`, `displayName`, `quantityOrCount`, `quantityPromptFlag`, and `targetMode` |
| `+0x13a6ec + slot * 0x148` | one-based spell/command slot record base used by `ChangeSpellSlotInputPane`, spell prompt construction, legacy spell inventory, and [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md); record-local byte `+0` is active/populated and record-local dword `+4` is the input kind/cast route. B010 maps `UseCommandSlot` input kinds `1` string, `2` target/who, `3` four-number, `4` three-number, `5` immediate no-argument opcode `0x0f`, `6` two-number, `7` one-number, and `8` spell-slot character prompt. |
| `+0x13a794 + slot * 0x148` | spell prompt/name text used by dispatch-created spell input panes |
| `+0x13a834 + slot * 0x148` | spell learned/active flag used by the available-slot range helper at `0x005a4310` |
| `+0x13a83c + slot * 0x148` | spell display name consumed by `ClientSpellMenuDialog` while populating client-local spell menu rows |
| `+0x13ead4` | spell-slot cache/dirty/guard flag, best draft name `m_spellSlotCacheDirty` / `m_spellSlotStateDirty`; cleared by `ChangeSpellSlotInputPane` when either selected one-based slot record is active |
| `+0x13eb08` | outgoing recent say/direct-message recipient list, best source-facing name `m_recentSayRecipients`; [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) reads the last entry for whisper mode, and `sub_5A4B60` deduplicates/caps/inserts the current recipient into this list. |
| `+0x13eb10` | recent-recipient selector byte set to `1` by `sub_5A4B60` after outgoing recent-list update and cleared by the incoming/fallback sender-history path. |
| `+0x13eb1d` | local input lock; collection input-lock and Chatting UI feature-view alias |

B014's [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md) reanalysis adds the MapPane event-`7` action-poll receiver view: [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) loads `dword_67A748` / `g_pUserPane` directly before calling `LivingObjectPane::TryPerformAction`. This is a local-player/UserPane object view compatible with LivingObjectPane action methods; it does not create a second global and does not move storage ownership away from UserPane.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md)
- [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)

## Changes

- 2026-07-30 B007 UID000415 support synchronization: preserved `89/90`, non-emitting alias status, stable `g_pCollectionData` path, and the sole [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) definition while adding `g_pUserPane` chat-history member consumers and exact `+0x13eb04` `m_chatHistory` ownership. Historical collection/player aliases and adjacent recipient-history views remain intact.

- 2026-07-19 Agent-B003 UID0001LM support sync: preserved `89/90`, blank formal, stable alias filename, sole UID0001OR definition, and all lifetime/collection/inventory/social/history evidence while adding the exact signed one-based spell-prompt table/accessor consumer model and rejecting a separate spell manager/global.
- 2026-07-19 B003 UID000477 support synchronization:
  - Score, alias status, formal, route, and the single UID0001OR storage definition remain unchanged.
  - Typed complete-object `+0x3cb1` as `m_huntersListFlag`, `+0x3cb2..+0x3eb1` as `m_partySearchSourceText[256]`, and retained two residual bytes before `+0x3eb4`; documented inline accessor use without creating a second global or storage definition.
  - Preserved every collection, spell, inventory, movement, camera, group, and historical alias view already present.

- 2026-07-13 B004 UID00010X split callback: preserved `89/90`, blank formal C++, non-emitting status, aliases, and one-pointer lifetime while adding `CollectionPlayerDataView` as the accepted collection feature view.
  - Evidence: [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) exact sizes/boundary, [UID:0000FQ][UserPane](by-class/UserPane.md) mutable/const accessor contract, constructor vector setup, and every accepted dialog/control child resolve to the same in-object storage.
  - Rejected alternative: no second `CollectionPlayerDataView *`, `g_pCollectionData`, `g_pPlayerData`, or `g_collectionProgressTable` definition, allocation, or owner is introduced; raw offsets remain binary evidence only.

- 2026-06-22 Rule 26 support sync from B014 [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md):
  - Added the `g_pUserPane` action-poll receiver view used by MapPane event `7` before calling `LivingObjectPane::TryPerformAction`, preserving this page's alias/non-emitting policy.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the local inventory slot typed view `+0x133f08 + inventorySlot * 0x1fc` over `g_pUserPane` / historical `g_pCollectionData`.
  - Preserved `g_pUserPane` as the canonical global owner/name and documented the inventory slot table as a feature view rather than a separate global.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Added inferred UserPane camera-lock bytes `+0x1c4/+0x1c5` as non-collection typed views consumed by `EarthquakeEffecter::ApplyEffect`; rejected generated `g_pAppMan` camera-lock ownership for this path.
- 2026-06-20 B003 callback-target support sync:
  - Added the [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) view where this storage is captured as the active local `UserPane *` target for drop/give confirmation action objects.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents the backing address, broad alias set, 505-xref player/client-state role, collection layout offsets, non-collection spell/item/gold views, and many class/memory refs; final canonical owner/name remains medium-confidence.
- 2026-06-05: Marked reconstructable and intentionally left unassigned. Evidence: live IDA MCP xrefs confirm broad reads of `0x0067a748`; decompilation of `0x0056fc80` shows the collection-pane detail/request path indexing collection data through `dword_67A748`. The storage is recoverable, but source ownership remains broader than [UID:0000IC][CollectionPane](by-file/CollectionPane.md) because spell-slot, item, gold, and player-name paths also read the same client-state pointer.
- 2026-06-11: Assigned to direct owner [UID:0000P1][UserPane](by-file/UserPane.md) and raised confidence to `86`. Evidence: the exact storage page [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) records UserPane constructor, constructor-fallback, destructor, scalar-deleting destructor, and clear-helper writes to the global; the child now clears `88/86` and the direct parent clears `89/85`, satisfying the strict `85/85` gate while keeping the final source-facing global name conservative.
- 2026-06-13: Corrected the collection entry view without changing the `88/86` score. Evidence: live IDA MCP checks of the metadata loader, dialog constructor, entry-control draw path, and progress-bar constructor confirm logical entry records start at `+0x3ecc + entry * 0x4c`; `+0x3efc` is entry-local `+0x30`, and packet state bits land at entry-local `+0x48` (`+0x3f14 + entry * 0x4c` absolute).
- 2026-06-17: Integrated B001 SpellSpellInputPane source-quality findings without changing the `88/86` score. Evidence: the spell prompt constructor, accept handler, and command-slot dispatch confirm slot-record, prompt/name, learned/active, and guard/dirty offsets on the same local-player/UserPane state object; generated `SpellManager`/`g_pSpellMan` naming was rejected pending stronger source evidence.
- 2026-06-19 B013 QuitInputPane split sync: added [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) evidence that the affirmative typed quit path treats `g_pCollectionData + 0xa4` as a nullable `TimerHandler` owner subobject passed to `TimerMgr::RemovePendingTimersForOwner` before `MapPane::ExitToMenu(true)`. This strengthens the local-player/UserPane state interpretation and does not change the `88/86` score or force a final global rename.
- 2026-06-19 B001 accepted source-quality implementation:
  - Changed to `89/90` and retitled the page as `g_pUserPane / g_pCollectionData` while preserving the stable filename/path.
  - This page is now non-emitting semantic alias documentation; [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) is the single formal C++ definition site for `UserPane *g_pUserPane = 0`.
  - Evidence incorporated from B001: zero `.data` window, 505 exact direct operand references, only five writes all from UserPane constructor/destructor/clear paths, alias retention/rejection, and typed-view roles for heartbeat, timer-owner, chat, item-command, collection, spell, map-pane, party-search, and local input-lock offsets.
- 2026-06-20 B002 ChangeSpellSlotInputPane support sync: refined the `+0x13a6ec + slot * 0x148` spell-slot view as one-based, named record-local byte `+0` as the active byte, named `+0x13ead4` as `m_spellSlotCacheDirty` / `m_spellSlotStateDirty`, and recorded that active-byte checks do not gate packet send in the slot-change submitter.
- 2026-06-21 B010 UseCommandSlot support sync: added [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md) as the source-quality command/spell slot dispatcher over this `g_pUserPane` view, including the one-based `1..52` slot guard, record byte `+0`, record dword `+4` case map, guard byte `+0x13ead4`, and rejection of generated `SpellManager`/`g_pSpellMan` names.
- 2026-06-21 B007 legacy SpellInventoryPane support sync: added [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) as a legacy spell-dispatch consumer of the one-based `+0x13a6ec + slot * 0x148` spell-record table, rejected stale `+0x13a82c` wording for that body, and preserved the existing `g_pUserPane`/alias policy.
- 2026-06-23 B001 SpellMenuDialogs support sync: score unchanged; added `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md` and `by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md` as client spell-menu consumers of the one-based `g_pUserPane` spell-slot active/name view at `+0x13a834/+0x13a83c`.
- 2026-06-26 B009 SayInputPanes support sync: score unchanged; strengthened the chat-mode typed view by naming `+0x3eb4` as `m_currentSayMode`, adding the outgoing recent-recipient list at `+0x13eb08` / `m_recentSayRecipients`, and adding selector byte `+0x13eb10` as the state set by [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md)'s mode-2 recent-recipient helper route.
