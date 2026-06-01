*** UID:0000I3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ChangePasswordDialogPane

## Status

- Confidence: strong for behavior; medium for standalone original file.
- Proposed module: `login/ChangePasswordDialogPane.cpp`, or folded into [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Current recovered source: `source-3/simroot_v2/class_ChangePasswordDialogPane.cpp`

## File Role

`ChangePasswordDialogPane.cpp` is the login/account password-change dialog source candidate. It builds old/new asset variants, validates required fields and password confirmation, and submits the password-change request after creating the screen dimmer.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md) | `0x004fdd40-0x004fe782`, adjacent helper cluster [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md), exact packet children [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md), [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md), [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md), destructor family at `0x00502474`, `0x0050247f`, `0x00502650` | Password-change dialog construction, validation, action handling, submit, packet send/reply helpers, and teardown. |
| [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md) | `0x004f9060-0x004f90b4` | Retained launcher that allocates `620` bytes and constructs this dialog; owner may be `MainMenuPane.cpp` if launch helpers stay grouped there. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x004fdd40` size `0x720`, `0x004fe460` size `0x2e`, `0x004fe490` size `0x96`, and `0x004fe560` size `0x222`.
- 2026-06-01 IDA MCP resplit records the exact UI/core method island as [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md), ending at the `0x004fe782-0x004fe790` padding gap before the adjacent packet helpers.
- IDA MCP `callers 0x004fdd40` reports direct construction at `0x004f7b49` inside `MainMenuPane::ActivateMenuItem` and at `0x004f90a0` inside [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md).
- IDA MCP `callers 0x004fe560` reports the submit path is called from the action handler at `0x004fe484`.
- 2026-05-28 IDA MCP recheck confirms [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) as the adjacent packet helper cluster: `0x004fe9e0` is called from `0x004fe778` inside `SubmitPasswordChange`, while `0x004febf0` decodes password-change reply packets from the local dispatcher at `0x004fe530`.
- 2026-06-01 IDA MCP resplit adds exact packet-helper pages: [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md), [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md), [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), and [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md).
- The generated `simroot_v2` source uses `DLGPASS.EPF`/`DLGPASS.PAL` and `DLGPASS.EPD`/`NPAL8.PAL` layout branches, matching a pre-login account dialog.

## Boundary Notes

This can fold into `LoginDialogPane.cpp` in a compact source layout because it is opened from [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) and belongs to the same pre-login account UI family. Keep create-user body/shape dialogs in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).

Keep [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md) documented as a retained opener with unresolved direct reachability. It is not runtime/library code despite the current IDA name.

## Cross-References

- [UID:00001L][ChangePasswordDialogPane](by-class/ChangePasswordDialogPane.md)
- [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md)
- [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) Change-password packet helper cluster
- [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md)
- [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md)
- [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md)
- [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented dialog role, proposed ownership, launcher, packet helper cluster, and IDA evidence but remained unevaluated.
  - After: score reflects documented password-change construction/validation/submit behavior, launcher ownership, packet send/reply helper cluster, asset branches, and login/main-menu placement caveats.
  - Evidence: IDA notes confirm constructor/action/submit starts, direct construction callers, submit-path caller, and adjacent packet-helper calls from the dialog.
- Before: proposed file contents only listed the UI method range `0x004fdd40-0x004fe781` for `ChangePasswordDialogPane`.
- After: proposed contents include the adjacent [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) packet send/reply helper cluster as part of this source-file candidate.
- Why: IDA MCP shows `0x004fe9e0` is reached directly from `SubmitPasswordChange`, and `0x004febf0` handles packet replies for the same dialog family.
- Evidence: 2026-05-28 IDA MCP decompiles for `0x004fe560`, `0x004fe9e0`, `0x004fe530`, and `0x004febf0`.
- After: the adjacent packet helper cluster is now split into exact child pages [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md), [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md), [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), and [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md); `0x004fee40` is explicitly retained with the password/account helper family and excluded from `RankingDialog`.
- Evidence: 2026-06-01 IDA MCP lookup/caller/xref/callee/decompile/disassembly/raw-byte pass over `0x004fe790-0x004ff040`.
