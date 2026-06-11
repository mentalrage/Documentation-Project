*** UID:0000FN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserListDialogPane

## Status

- Confidence: strong for class purpose, source-file parentage, method boundaries, and local child-class ownership; medium for final field/packet names and non-modeled aggregate chunks.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Read-only data: [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md)
- Parent gate: attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md); both pages now meet the 80/80 attachment threshold.

## Class Purpose

`UserListDialogPane` is the main users dialog. It builds high-resolution or low-resolution dialog layouts, parses the initial user-list packet into fixed-size user records, distributes users into five visible list panes, sorts by name or status, filters by category/career, handles selected-user packet updates, and dispatches UI commands.

## Class Shape

- Source family: social user-list feature source under [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), not generic dialog/list infrastructure.
- Owned local collaborators: [UID:0000FO][UserListPane](by-class/UserListPane.md) repeated list panes, [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) command-20 subdialog, and the local `AddUserListSourceMessage_59DE60` helper.
- Reused controls: consumes `CheckBoxTextControlPane`, list, radio, scroll, text-edit, and dialog-pane controls, but those reusable controls keep their own source families.
- Runtime state: active dialog singleton at [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), show-hidden flag at [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md), and legacy nation initialization through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059bc90-0x0059d198` | Constructs high/low-res dialog controls, creates five `UserListPane` children, parses user rows, populates buckets, and initializes labels/counts. |
| `SortListsByName` | `0x0059d1f0-0x0059d24f` | Sorts all five category list panes by user name. |
| `SortListsByStatus` | `0x0059d250-0x0059d2af` | Sorts all five category list panes by status. |
| `RefreshCategoryView` | `0x0059d2b0-0x0059d5fe` | Steps the category filter, redistributes users into buckets, sorts current lists, updates counts and labels. |
| `HandleUserListPacket` | `0x0059d620-0x0059d8f5` | Handles selected-flag sync and source-text updates from network packets. |
| `OnKeyEvent` | `0x0059d900-0x0059da82` | Handles Page Up/Page Down category changes and Ctrl+C copy of selected names. |
| `OnControlCommand` | `0x0059da90-0x0059dbe3` | Handles close, sort-mode change, category step, party-search dialog open, and show-hidden toggle. |
| adjustor thunks | `0x0059f017-0x0059f02d` | User-list dialog destructor adjustors. |
| scalar deleting destructor | `0x0059f110-0x0059f181` | Destroys owned scroll/list state, tears down base dialog, clears singleton, and optionally deletes. |

## Related Local Classes

- [UID:0000FO][UserListPane](by-class/UserListPane.md) implements the repeated list control used by this dialog.
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) is opened by `OnControlCommand(20)`.
- `AddUserListSourceMessage_59DE60` is a local helper called by packet and double-click/source display paths.

## Data Notes

- `g_pUserListDialogPane` is the active dialog singleton.
- `g_bShowHiddenUsers` controls whether hidden users remain visible in category refresh.
- `g_userListDialogHighResLayout` and `g_userListDialogLowResLayout` are resource-layout dependencies.
- User rows are staged as fixed `1044`-byte records in current generated source; field names remain provisional.
- [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md) records matching `UserListDialogPane`, `PartySearchEditPane`, and `UserListPane` vtable/resource data while keeping the interleaved reusable `CheckBoxTextControlPane` child separate.

## Evidence Notes

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) places this class in `NexusTK/social/` and records the social user-list source family, exact constructor callers, user-list pane construction, party-search command ownership, and read-only data island.
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) records the executable aggregate, modeled function boundaries, non-padding tail/table chunks, checkbox-control interleaves, caller/callee refs, and autogen attachment to the file parent.
- IDA MCP confirms the constructor and virtuals as real functions, with the constructor called from packet/UI paths at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) identifies `0x0069b4e0` as the active `UserListDialogPane` singleton slot, written by the constructor and tested by UI/map paths.
- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md) documents the show-hidden flag reads in the constructor and refresh path plus the toggle in `OnControlCommand`.
- Existing generated/recovered source names remain search leads only. Current ownership and scoring are based on UID-backed IDA/project documentation, not generated source quality.

## Score Rationale

- Completion remains `84` because the class purpose, major method map, local child classes, singleton/show-hidden state, read-only data, and source-file parent are documented, but fixed record fields, packet fields, helper names, and final C++ declarations remain open.
- Confidence is raised to `84` because the file parent, memory aggregate, read-only data page, child class pages, and global/flag pages now agree on the class role and ownership. It stays below higher confidence because this pass did not have live MCP access and the aggregate still has unresolved non-modeled chunks.
- Final C++ remains blank under the 95/95 reconstruction-code gate.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, sort/filter/packet/key/control methods, adjustor thunks, and scalar deleting destructor at `0x0059bc90`, `0x0059d1f0`, `0x0059d250`, `0x0059d2b0`, `0x0059d620`, `0x0059d900`, `0x0059da90`, `0x0059f017`, `0x0059f022`, and `0x0059f110`; likely parent [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) passes 80/80, but this class page is `84/78`, so the child-side parent gate does not pass. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the users-dialog responsibility, constructor, sort/filter/packet/key/control method map, related local classes, data notes, constructor callers, and explicit generated-source quality caveat.
- 2026-06-07 A004 parent-gate cleanup:
  - What existed before: the page remained `84/78`, had no parent UID, and still framed confidence around generated-source quality despite stronger UID-backed file, memory, read-only-data, global, and child-class documentation.
  - Changed to: `CONFIDENCE:84`, `AUTOGEN_PARENT_UID:0000OZ`, class-shape notes, data-state references, score rationale, and source-facing evidence based on existing IDA-backed docs.
  - Summary/evidence: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md), [UID:00026U][0x0062e960-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md), [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), and [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogShowHiddenFlag.md) now support the class/file attachment. C++ remains blank because final record/packet fields and helper names are below the reconstruction threshold.
