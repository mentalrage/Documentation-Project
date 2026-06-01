*** UID:0000AU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProfileDialog

## Status

- Confidence: strong for class behavior and file ownership, medium-high for helper/destructor-owner cleanup.
- Likely source file: [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- Address range: [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- Current recovered file: `source-3/simroot_v2/class_ProfileDialog.cpp`

## Class Purpose

`ProfileDialog` is the profile UI dialog. It builds either the compact `DLGPROFL.EPF` layout or older `PROFILE.EPF` layout, displays stored profile text from config, accepts/cancels profile text selection, writes accepted text to `g_profileNameBuffer`, and notifies the dialog/session dispatcher when closed.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0053f940-0x0053fd95` | Builds profile dialog controls, background/profile resources, profile text pane, and action buttons. |
| non-deleting destructor helper | `0x0053fda0-0x0053fdbf` | Restores ProfileDialog vtables and tail-jumps to the shared base teardown; no direct IDA xrefs. |
| action handler | `0x0053fdc0-0x0053fe87` | On accept, reads/sanitizes profile text and copies it into `g_profileNameBuffer`; on accept/cancel, applies profile selection and dispatches close notification. |
| refresh wrapper | `0x0053fe90-0x0053fe9b` | Tiny wrapper around `RefreshSelectedProfileData`; no direct IDA xrefs. |
| thunks/destructor | `0x00542639`, `0x00542644`, `0x005429a0-0x005429f5` | Adjustor/deleting thunk and scalar deleting destructor. |

## Evidence Notes

- Wave3 class summary describes profile viewing, but the action handler also commits selected profile text.
- The destructor body currently references `TransferReplyAlert::~DialogPane`; treat that as generated base-owner pollution, not proof of a transfer-alert relationship.
- 2026-05-24 IDA MCP decompilation shows `0x0053fda0` and `0x005429a0` both restore the three `ProfileDialog` vtables and call shared base teardown helper `0x0049d9f0`. This makes the generated `TransferReplyAlert::~DialogPane` label a naming/owner artifact.
- `0x00542639` and `0x00542644` are adjustor thunks into `0x005429a0`, with vtable/data refs at `0x00620fe0` and `0x00621010`.
- `0x0053fe90` calls `RefreshSelectedProfileData`; the actual storage/sidecar probing remains documented under `ProfileStorage`.
- 2026-06-01 IDA MCP function map: constructor `0x0053f940-0x0053fd95`, cleanup helper `0x0053fda0-0x0053fdbf`, action handler `0x0053fdc0-0x0053fe87`, and refresh wrapper `0x0053fe90-0x0053fe9b`.
- 2026-06-01 IDA MCP xrefs: constructor callers at `0x0053e139` and `0x005bd273`; action-handler vtable/data ref at `0x00620fc8`; scalar deleting destructor refs at `0x00620f80`, `0x0054263f`, and `0x0054264a`; adjustor-thunk refs at `0x00620fe0` and `0x00621010`.
- 2026-06-01 IDA MCP callees: constructor uses dialog/control/resource helpers (`0x0049d8a0`, `0x0049dc10`, `0x0049dfd0`, `0x0049e190`, `0x0049eac0`, `0x004f4aa0`, `0x0058fc30`); action handler uses text extraction `0x00498c10`, sanitizer `0x005957c0`, `_wcscpy_s`, dialog apply/close `0x0049eb90`, refresh `0x005063e0`, and dispatcher notify `0x00469180`.

## Reconstruction Notes

- Reconstructable is `TRUE` because the class ownership, function map, vtable refs, and behavior are now supported by IDA evidence and the parent file has a projected path.
- The C++ block remains blank because field names at offsets like `+0x1fc` and helper names around the dialog/control layer are not final-source quality.

## Cross-References

- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/78`.
  - Before: The page was unevaluated despite documenting purpose, primary methods, helper ownership, and destructor naming caveats.
  - After: Scored as moderately high completion with medium residual confidence around helper/destructor-owner cleanup.
  - Evidence: Existing method notes and IDA MCP evidence identify constructor/action/refresh/destructor helpers and explain generated base-owner pollution.
- 2026-06-01: Changed completion/confidence from `78/78` to `82/82`, marked reconstructable, and attached parent [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).
  - Before: exact function endpoints, xref map, and parent confidence were not sufficient for attachment.
  - After: current IDA MCP evidence confirms spans, xrefs, callees, and byte boundaries; final C++ remains deferred.
