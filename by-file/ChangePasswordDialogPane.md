*** UID:0000I3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Lifecycle And Routing

| Area | Evidence | File-level decision |
| --- | --- | --- |
| UI/core method island | [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) records the constructor, command/action helper, validation helper, reply dispatcher, submit helper, singleton publish at `dword_69B48C`, resource branch names, and padding boundary before the packet helpers. | Own this island with `ChangePasswordDialogPane.cpp`; final field/control names remain below source-emission quality. |
| Packet helpers | [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) and its exact children cover the active send helper, reply handlers, raw alternate sender, switch table, and internal padding. | Keep the source-authored helpers with this account dialog family; do not move `0x004fee40` to `RankingDialog` without a later caller proof. |
| Launcher paths | [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md) documents the retained duplicate allocation wrapper, while `MainMenuPane::ActivateMenuItem` directly duplicates the same `620`-byte allocation and constructor call. | Treat the wrapper as retained address-matching support; active runtime behavior is already represented by the main-menu action path. |
| Singleton slot | [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md) documents the exact active `ChangePasswordDialogPane` pointer, with constructor publish/fallback-clear, main-menu cleanup read, support-helper clear, and destructor-family clear refs. | Model as source-owned dialog singleton state under this file; final declaration spelling and folded-vs-standalone grouping remain open. |
| Read-only data | [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) places `ChangePasswordDialogPane` inside the selection/password-control vtable and resource-literal band. | Rebuild vtables/resources through class declarations and source literals; no standalone `.rdata` source should be emitted here. |
| Neighbor ownership | `NewUserShapeSelectControlPane` ends before `0x004fdd40`, packet helpers end before `ScrolledTextControlPane`, and the singleton/read-only aggregates are mixed-owner bridges. | Keep this page focused on password-change UI/account behavior and preserve neighboring new-user, scrolled-control, staff/history, and login-dialog owner boundaries. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page now covers the class/core method island, exact packet-helper children, retained opener, main-menu launcher context, exact singleton lifecycle child, read-only vtable/resource band, boundary decisions, and unresolved source split. It remains below final-source quality because field/control names, exact singleton declaration spelling, and `ChangePasswordDialogPane.cpp` versus folded `LoginDialogPane.cpp` grouping are not final. |
| Confidence | `88` | Confidence is strong because class, memory, global, and read-only data pages agree on constructor/submit/reply behavior, launcher paths, singleton lifecycle, and resource/vtable ownership. It stays below final-audit range because retained-launcher reachability and original source grouping remain partly unresolved. |

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
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)
- [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md)
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md)
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
- 2026-06-07 lifecycle/source-routing pass:
  - Before: the page covered the dialog UI methods, opener, packet helpers, and placement caveats but did not tie in current singleton lifecycle and read-only-data evidence.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`, with lifecycle/source-routing and score-rationale sections plus singleton/read-only-data cross-links.
  - Evidence: existing docs now agree on the exact core child, packet helper children, retained opener, active main-menu construction path, `0x0069b48c` singleton slot lifecycle, and the main-menu/new-user read-only vtable/resource band. Scores stay below final-source quality because original file folding, field/control names, and final static/global declarations remain unresolved.
- 2026-06-07 A002 Batch 042 singleton parent-gate refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:88`, and the singleton evidence was still linked through the mixed account-dialog aggregate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, with exact singleton child [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md).
  - Summary/evidence: the split child records exact one-dword storage, initialized value, main-menu cleanup read, constructor publish/fallback refs, support-helper clear, and destructor-family clear. This page now clears the strict direct-parent gate for [UID:0002XM][0x0069b48c-0x0069b490.g_pChangePasswordDialogPane](by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md) while remaining capped by field/control names, declaration spelling, and folded-vs-standalone source-grouping caveats.
