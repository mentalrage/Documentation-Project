*** UID:0000QK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCollectionData

## Status

- Address: `0x0067a748` (`dword_67A748` in IDA)
- Memory doc: [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- Symbol kind: global pointer/view into large player data block
- Likely owner file: unresolved player/client-state module; collection view documented in [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Confidence: strong for collection offsets, medium for final canonical global name.

## Purpose

Existing collection and player-state docs use `0x0067a748` under several aliases:

- `g_pCollectionData` in `CollectionPane`;
- `g_pPlayerData` in `CollectionDialogPane` and `CollectionEntryControlPane`;
- `g_collectionProgressTable` in `CollectionBarControlPane`.

IDA shows all of these collection paths reading `dword_67A748`. Treat the collection names as typed views over the same broader player-data block until the final owner of the player-state structure is documented.

IDA MCP `py_eval` reports `0x0067a748` as a four-byte `.data` item with 505 direct xrefs, so this is not collection-private storage even though collection docs use the `g_pCollectionData` view name.

2026-05-27 IDA MCP recheck found another non-collection typed view: `ChangeSpellSlotInputPane::SubmitSpellSlotChange` reads spell-slot state at `dword_67A748 + 0x13a6ec + slot * 0x148` and clears byte `dword_67A748 + 0x13ead4` when either source/destination slot is active. This reinforces that the canonical owner should be a broader player/client-state structure, with collection and spell-slot names treated as local views.

2026-05-27 IDA MCP recheck of `DropGoldInputPane` and `GiveGoldInputPane` found another item-command view: both gold submit paths check byte `dword_67A748 + 0x3ec0` before sending the drop/give gold packet. Document this as a player/client-state busy gate, not as collection-owned state.

2026-05-27 IDA MCP recheck of `WieldInputPane` and `WearInputPane` found another item-command view: both constructors call the local player-name helper with `dword_67A748` before formatting their prompt text. This reinforces that the storage is a broad player/client-state pointer, not collection-only data.

2026-05-27 IDA MCP recheck of `ThrowInputPane`, `UseInputPane`, and `EatInputPane` found the same item-command player-state view. All three constructors call the local player-name helper with `dword_67A748`; `ThrowInputPane::OnSubmitInput` checks byte `dword_67A748 + 0x3ec0` before sending the direct throw packet, and `UseInputPane::OnSubmitInput` passes `dword_67A748` into [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md).

## Collection Layout View

Observed collection offsets:

| Offset | Meaning |
| --- | --- |
| `+0x1340c8` | collection group count |
| `+0x13eb1d` | collection input lock flag used by `CollectionPane::HandleInput` |
| `+group * 0x2604 + 0x3ec8` | group loaded/active flag |
| `+group * 0x2604 + 0x3ec9` | group type/volume id |
| `+group * 0x2604 + 0x3eca` | total entry count |
| `+group * 0x2604 + 0x3ecb` | collected entry count |
| `+group * 0x2604 + 0x3efc + entry * 0x4c` | per-entry state/name/description region |

See [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) for the struct hypothesis.

## Other Player-State Views

Non-collection consumers currently observed through this same pointer:

| Offset | Meaning |
| --- | --- |
| `+0x3ec0` | player/client-state busy gate used by drop/give gold and direct throw prompts before sending packets |
| `+0x13a6ec + slot * 0x148` | spell-slot state used by `ChangeSpellSlotInputPane` |
| `+0x13ead4` | spell-slot change flag cleared by `ChangeSpellSlotInputPane` |

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:00002U][CollectionBarControlPane](by-class/CollectionBarControlPane.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents the backing address, broad alias set, 505-xref player/client-state role, collection layout offsets, non-collection spell/item/gold views, and many class/memory refs; final canonical owner/name remains medium-confidence.
- 2026-06-05: Marked reconstructable and intentionally left unassigned. Evidence: live IDA MCP xrefs confirm broad reads of `0x0067a748`; decompilation of `0x0056fc80` shows the collection-pane detail/request path indexing collection data through `dword_67A748`. The storage is recoverable, but source ownership remains broader than [UID:0000IC][CollectionPane](by-file/CollectionPane.md) because spell-slot, item, gold, and player-name paths also read the same client-state pointer.
