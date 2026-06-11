*** UID:00001L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangePasswordDialogPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md), or folded into [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- Address range: [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md) plus adjacent packet helpers in [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_ChangePasswordDialogPane.cpp`

## Class Purpose

`ChangePasswordDialogPane` owns the password-change dialog opened from the main menu. It builds old/new asset variants, validates non-empty fields, checks the new password and confirmation, and sends the password-change request after creating a screen dimmer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChangePasswordDialogPane` | `0x004fdd40`, size `0x720` | Builds `DLGPASS.EPF` or `DLGPASS.EPD` dialog variant. |
| `OnDialogAction` | `0x004fe460`, size `0x2e` | OK submits, cancel closes. |
| `ValidateInputFields` | `0x004fe490`, size `0x96` | Enables/disables action button based on required text fields. |
| `SubmitPasswordChange` | `0x004fe560`, size `0x222` | Validates password digit/match rules and sends password-change request. |
| `SendPasswordChangeRequest` | `0x004fe9e0`, size `0x202` | Builds opcode `38` password-change packet from three wide strings and sends through `dword_67A7EC`. |
| `HandlePasswordChangeReply` | `0x004febf0`, size `0x221` | Parses password-change reply result/message and updates the dialog or closes on success. |
| `HandlePasswordChangeReplySimple` | `0x004fee40`, size `0x1ff` | Similar reply-message handler; no direct xref currently, but behavior/locality tie it to this account dialog family. |
| Destructor family | `0x00502474`, `0x0050247f`, `0x00502650` | Adjustor and deleting destructor family. |

## Evidence Notes

- IDA confirms the four local method starts and destructor family.
- `MainMenuPane::ActivateMenuItem` constructs this dialog for menu item `2`.
- IDA MCP `callers 0x004fdd40` also reports a retained launcher call at `0x004f90a0` inside [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md).
- IDA MCP `callers 0x004fe560` reports the submit method is reached from `OnDialogAction` at `0x004fe484`.
- 2026-05-28 IDA MCP decompile shows `SubmitPasswordChange` calls `sub_4FE9E0(v15, v16, v18)` at `0x004fe778`, tying the packet-send helper to this class.
- 2026-05-28 IDA MCP decompile of `sub_4FE530` dispatches packet type `2` to `sub_4FEBF0`, and `sub_4FEBF0` decodes result/message bytes for a dialog reply.
- IDA's current name for `0x004f9060` is `___std_parallel_algorithms_hw_threads@0_0`, but decompilation shows a password-dialog allocation wrapper, not library code.
- The generated source uses both high-res EPF and old EPD layout branches, supporting a login/account UI source placement.

## Cross-References

- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:0000TA][OpenChangePasswordDialog_4F9060](by-global/OpenChangePasswordDialog_4F9060.md)
- [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) Change-password packet helper cluster
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)

## Changes

- Before: the method inventory ended at `SubmitPasswordChange` and destructor-family entries.
- After: the inventory includes the adjacent password-change packet send/reply helpers in [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md).
- Why: IDA MCP shows `0x004fe9e0` is directly called by `SubmitPasswordChange`, and `0x004febf0` is the dispatcher target for password-change packet replies.
- Evidence: 2026-05-28 IDA MCP xrefs and decompiles for `0x004fe560`, `0x004fe9e0`, `0x004fe530`, and `0x004febf0`.

- What existed before: the page had strong password-dialog and packet-helper evidence, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor variants, validation, submit, send/reply packet helpers, menu launcher, and destructor family are documented; exact original file fold with login/account dialogs remains the main open item.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and attached the class to [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md). Current IDA MCP `lookup_funcs` reconfirmed constructor/action/validation/submit/send/reply/destructor starts at `0x004fdd40`, `0x004fe460`, `0x004fe490`, `0x004fe560`, `0x004fe9e0`, `0x004febf0`, and `0x00502650`, and `callers` shows the dialog constructor reached from main-menu/password launcher paths. Both class (`82/88`) and file (`80/84`) clear the 80+ attachment gate; reconstruction C++ remains blank pending final field names and source split.
