*** UID:0000MR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/profile/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProfileDialog

## Status

- Confidence: strong for `ProfileDialog` ownership, module placement, and the dialog/storage split; medium-high for final source-visible destructor/thunk and field names.
- Proposed module: `profile/ProfileDialog.cpp`
- Current recovered source: `class_ProfileDialog.cpp`
- Evidence basis: generated source, existing profile-storage notes, and IDA MCP boundary/xref/callee checks through 2026-06-01.

## File Role

`ProfileDialog.cpp` owns the editable/viewable profile dialog shown from profile/social UI paths. It builds the `Profile` dialog, selects old/new profile resources, displays the configured profile text, accepts/cancels profile text selection, updates `g_profileNameBuffer`, and notifies the surrounding dialog/session UI.

This should live under `profile/` near `ProfileStorage.cpp`, but it should not own the profile file serializer. The storage helpers remain in [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md); this source is the dialog layer that consumes saved profile text and commits the selected profile text back to the profile/session globals.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ProfileDialog` | `0x0053f940-0x0053fe87`, thunks/destructor at `0x00542639`, `0x00542644`, `0x005429a0` | Profile dialog construction, accept/cancel handling, dialog close notification, and destructor behavior. |
| Destructor/helper island | `0x0053fda0`, `0x00542639`, `0x00542644`, `0x005429a0` | [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md); IDA shows vtable restore plus shared base teardown, not transfer-alert ownership. |
| Profile refresh wrapper | `0x0053fe90-0x0053fe9b` | Tiny wrapper around `RefreshSelectedProfileData`; real sidecar logic remains in [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md). |
| `g_profileNameBuffer` | global-data | Destination for accepted/sanitized profile text. |

## Split Notes

`ProfilePane` is a separate profile view pane under the user-look/profile-display UI, not the same dialog source. It appears near `UserLookPane` methods around `0x005a1df0` and should be reviewed with that feature cluster rather than forced into `ProfileDialog.cpp`.

## Evidence Notes

- IDA MCP confirms `ProfileDialog::ProfileDialog` at `0x0053f940-0x0053fd95`, helper `0x0053fda0-0x0053fdbf`, `HandleDialogAction` at `0x0053fdc0-0x0053fe87`, and tiny refresh wrapper `0x0053fe90-0x0053fe9b`.
- IDA shows `FriendListDialog` ends just before this profile block. The previous broad FriendList memory page has been split so the profile block has its own range.
- Wave3 reports `ProfileDialog` grade `96.2`. Current generated destructor calls are still typed through `TransferReplyAlert::~DialogPane`, which should be treated as base-owner pollution until the base teardown is reconciled.
- 2026-05-24 MCP recheck: decompilation of `0x0053fda0` and `0x005429a0` both restore `ProfileDialog` vtables and call the same shared base teardown at `0x0049d9f0`. Adjustor thunks `0x00542639` and `0x00542644` have vtable/data refs and forward to `0x005429a0`.
- `HandleDialogAction` calls `RefreshSelectedProfileData` directly at `0x0053fe65`; `0x0053fe90` is a second tiny wrapper to the same storage helper and has no direct xrefs in IDA.
- 2026-06-01 MCP recheck: constructor xrefs are `0x0053e139` and `0x005bd273`; the action-handler vtable/data ref is `0x00620fc8`; scalar deleting destructor refs are `0x00620f80`, `0x0054263f`, and `0x0054264a`; adjustor-thunk refs are `0x00620fe0` and `0x00621010`.
- 2026-06-01 MCP recheck: callee evidence keeps storage refresh and persistence split out of this source. The action handler calls text read `0x00498c10`, sanitizer `0x005957c0`, `_wcscpy_s`, dialog apply/close `0x0049eb90`, refresh `0x005063e0`, and dispatcher notify `0x00469180`; the wrapper `0x0053fe90` is only `mov ecx, dword_67A764; jmp 0x005063e0`.
- Raw byte review shows `0xcc` padding before the constructor at `0x0053f939-0x0053f940`, after the action handler at `0x0053fe87-0x0053fe90`, and after the wrapper at `0x0053fe9b-0x0053fea0`.
- 2026-06-10 gate review reconciled the already-recorded IDA MCP evidence across the file, class, core memory, wrapper, and helper-index pages. The parent file now clears the current `85/85` attachment gate for the ProfileDialog class/core/helper chain while final C++ emission remains deferred below the `95/95` source-quality bar.

## Cross-References

- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents dialog role, proposed contents, split notes, IDA evidence, helper/destructor caveats, storage relationship, and cross-references; confidence remains capped by one short unmodeled helper and base-owner pollution.
- 2026-06-01: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/profile/`, raised completion/confidence from `82/78` to `84/82`, and added current IDA xref/callee/boundary evidence.
  - Before: the page had a proposed module name but no validator path and parent confidence was below the child-attachment threshold.
  - After: the source path is explicit and confidence is high enough for child pages to attach to this file while keeping final C++ reconstruction deferred.
- 2026-06-10: Raised completion/confidence from `84/82` to `86/86`.
  - Before: the file parent still sat below the current strict `85/85` child-assignment gate even though its child pages already contained endpoint, xref, callee, vtable, padding, and storage-split evidence.
  - After: the file parent clears the gate for the ProfileDialog class, core memory range, destructor/helper index, and refresh wrapper. Final source emission remains blank because field/helper names and destructor/thunk source shape are not yet final.
