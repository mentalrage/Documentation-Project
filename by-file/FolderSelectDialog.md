*** UID:0000JF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FolderSelectDialog

## Status

- Confidence: strong for dialog ownership; medium for whether `FolderTreePane` was compiled in the same `.cpp` or a neighboring control `.cpp`.
- Proposed source file: `ui/dialogs/FolderSelectDialog.cpp`
- Proposed header: `ui/dialogs/FolderSelectDialog.h`
- Current recovered source: `source-3/simroot_v2/class_FolderSelectDialog.cpp`
- Main class: [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)
- Related control: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- Main address doc: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- Evidence basis: Wave3 generated source as a lead plus IDA MCP boundary/decompilation/xref checks through 2026-06-03.

## File Role

`FolderSelectDialog.cpp` owns the modal folder-picker dialog used by the music settings UI. It builds a `DialogPane`, creates a drive list and a [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), enumerates logical drives through Win32, lets the user switch drive roots, and returns either the selected path or an empty result through a callback object.

This should stay in `ui/dialogs/`. The folder tree itself is a reusable control candidate and may live in `ui/controls/FolderTreePane.cpp`, but the dialog-specific drive list, callback dispatch, and OK/cancel policy belong here.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `FolderSelectDialog` | `0x004b1590-0x004b1b87` | Dialog construction, command handling, result dispatch, destructor, and secondary thunks. |
| drive-list population helper | `0x004b1a00-0x004b1b05` | Enumerates `GetLogicalDrives`, creates list items for `A:` through `Z:`, and selects the current drive. IDA confirms a function start, but current active Wave3 source only inlines equivalent logic in the constructor. |
| `g_driveLetterBuf` | global-data reference | Scratch single-letter drive buffer currently emitted from this source. Final owner can remain file-local/static if the symbol is not shared. |
| callback function object | `0x0052a3e0-0x0052a4de` | Owned by [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), not this file; this dialog consumes it through offset `0x270`. |

## Evidence Notes

- IDA xrefs show the constructor at `0x004b1590` is called from `MusicControlDialog::HandleControlCommand` at `0x0052986d`.
- The constructor allocates a `0x17c` byte `FolderTreePane`, places it inside the dialog at `16,32,284,282`, populates the drive list, and optionally navigates to the caller-provided initial path.
- `OnCommand` at `0x004b1920` handles drive-list notifications, confirm, and cancel. Confirm calls the selected-path helper at `0x004b3090` against the folder tree iterator at `tree + 0x170`.
- `0x004b1a00` is a real IDA function duplicating the constructor's drive-list population logic. It currently has no direct IDA code xref and is not emitted as an active Wave3 method; keep it with this source until proven dead or compiler-only.
- The scalar deleting destructor at `0x004b1b20` destroys the callback object when present and chains to a base-dialog teardown currently mislabeled in generated source as `TransferReplyAlert::~DialogPane`.
- 2026-06-03 IDA MCP recheck reconfirmed the source island function starts/sizes, the constructor caller at `0x0052986d`, the no-direct-caller caveat for `0x004b1a00`, and the selected-path helper caller at `0x004b197f`.
- 2026-06-03 IDA MCP xrefs tie the three `FolderSelectDialog` vtables (`0x0061a45c`, `0x0061a4bc`, `0x0061a4ec`) to constructor, unwind/cleanup, and destructor stores, while xrefs to [UID:00027D][0x0066da88-0x0066da90.FolderSelectDriveRootBuffer](by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md) come only from the constructor and drive-list helper.
- 2026-06-03 IDA MCP decompilation confirms `OnCommand` dispatches OK/cancel through the callback at offset `0x270`, builds the selected folder path from the tree iterator at `tree + 0x170`, and handles drive-list notification by resetting the `FolderTreePane` root. The drive helper separately enumerates `GetLogicalDrives`, compares against `GetCurrentDirectoryA`, rewrites the wide `X:\` buffer, and selects the current drive entry.
- 2026-06-03 IDA MCP disassembly confirms the two secondary destructor thunks and the scalar deleting destructor restore all three vtable views, release the callback function object, call the base dialog teardown, and conditionally free the object.

## Ownership Notes

[UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md) opens this dialog for music-folder selection. The callback wrapper should remain with `MusicControlDialog.cpp`; the folder picker should only depend on an abstract callback/function object.

[UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) is physically adjacent and created only here in currently checked IDA xrefs, but it has enough control logic to justify a separate `ui/controls/FolderTreePane.cpp` candidate. If future xrefs show no other real users, merging it as a private helper in `FolderSelectDialog.cpp` remains plausible.

## Cross-References

- [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)
- [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-01 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: the existing file page and proposed source-tree entry already place the modal folder picker under `ui/dialogs/`; IDA MCP recheck confirms the constructor is reached from `MusicControlDialog::HandleControlCommand` at `0x0052986d`, while the embedded tree control remains split to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: modal folder picker role, proposed contents, drive-list helper, MusicControl callback boundary, FolderTreePane split caveat, constructor/command/destructor evidence, and cross-references are documented; confidence remains medium-high because control co-location versus separate file remains unresolved.
- 2026-06-03 MCP verification and attachment support:
  - What existed before: the page had a valid `NexusTK/ui/dialogs/` path and strong role documentation, but confidence remained `78`, below the parent-attachment threshold for the class.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: fresh IDA MCP lookup, caller/callee, xref, decompile, and disassembly checks reconfirmed function boundaries, MusicControlDialog caller ownership, selected-path callback flow, drive-list helper behavior, vtable xrefs, drive-root buffer ownership, and destructor thunk shape. Confidence remains below final-audit quality because the `FolderTreePane` co-location question and final callback/control helper names remain unresolved.
