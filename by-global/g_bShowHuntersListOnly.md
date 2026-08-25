*** UID:0002ZX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool g_bShowHuntersListOnly = false;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_bShowHuntersListOnly

## Status

- Canonical symbol: `g_bShowHuntersListOnly`
- Storage: [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md), byte at `0x0069bed0`
- Symbol kind: module-scope boolean flag
- Owner file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Rebuild handling: `source-authored`
- Confidence: very strong for role, storage, and owner; high for inferred source-facing variable name.

## Role

`g_bShowHuntersListOnly` is the inferred source-facing module-scope boolean for the User List dialog hunters-list-only filter. When it is set, constructor and refresh paths include only packed `UserListRecord` rows whose `huntersListFlag` / `partySearchListed` byte at `+0x20e` is nonzero. The flag is read while the dialog is built and while category contents are refreshed, and it is toggled by [UID:000479][0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand](by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md) control id `0x15`.

The previous `g_bShowHiddenUsers` name is a stale historical assumption. No current branch or UI string supports hidden-user semantics. `PartySearchEditPane` supplies the string `"Put me on the hunters list"`, writes local-player state at `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1`, and `UserListDialogPane::HandleUserListPacket` opcode `0x83` mirrors that state into row `+0x20e`.

## Evidence

- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) documents the exact `.data` storage, six direct byte xrefs, and the three trailing unreferenced bytes in the four-byte slot.
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) owns the executable UserListDialogPane family, including constructor, refresh, and control-command methods that use this flag.
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) records this state as `g_bShowHuntersListOnly` and carries the packed `UserListRecord` layout and rejected show-hidden assumption.
- [UID:000479][0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand](by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md) is the exact control-command child for the toggle path: control id `0x15` flips this byte, updates the checkbox state, invalidates the control, and refreshes the filtered category view.
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) records the checkbox label, `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1` write, opcode `0x84` send path, and opcode `0x83` row-sync relationship that identify row `+0x20e` as hunters-list/party-search state.
- The neighboring dispatch table ends at `0x0069bed0`: [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) covers the preceding `GetLocaleInfoW` and `SetFileAttributesW` pointers, so this flag is not part of the PlatformApi dispatch table.

## Ownership Decision

Keep this global with [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). It is dialog feature state, not generic list-control state and not part of the adjacent platform dispatch table. The direct memory child [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) attaches here because both this global page and the child page clear the corrected gate.

## Reconstruction Notes

Recreate this as a file-scope boolean near the user-list dialog implementation:

```cpp
static bool g_bShowHuntersListOnly = false;
```

The exact four-byte initialized storage is compiler/linker layout; the source requirement is the boolean state and its initialization semantics, not a hand-authored four-byte integer table. `g_bUserListHuntersOnly` is a weaker possible source-facing name, but `g_bShowHuntersListOnly` better matches the toggle behavior while preserving the user-visible "show only hunters-list entries" semantics.

## Cross-References

- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md)
- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md)

## Changes

- 2026-06-18 B001 Rule 26 source-quality incorporation:
  - What existed before: the page was `g_bShowHiddenUsers` at `86/88`, with show-hidden wording and no draft declaration.
  - Changed to: renamed to `g_bShowHuntersListOnly`, `88/90`, populated first-draft file-scope boolean C++, corrected role and ownership notes, linked to renamed [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md), and documented `g_bShowHiddenUsers` as stale.
  - Summary/evidence: constructor and refresh branches include only rows with `UserListRecord::huntersListFlag` at `+0x20e` when the byte is set; `PartySearchEditPane`, `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1`, opcode `0x83`, and opcode `0x84` establish hunters-list/party-search semantics. The adjacent wide API dispatch tail remains excluded.
- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated party-search player-state wording to use source-facing `g_pUserPane + 0x3cb1`; `g_pPlayerData` remains only a historical/local-player typed-view alias.
- 2026-06-26 B002 split implementation support sync:
  - Added the exact [UID:000479][0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand](by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md) child link for control id `0x15` toggle evidence. Existing owner/emitter, score, and first-draft boolean C++ remain unchanged.
