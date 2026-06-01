*** UID:00007F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoginDialogPane

## Status

- Confidence: strong
- Likely source file: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- Address range: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_LoginDialogPane.cpp`

## Class Purpose

`LoginDialogPane` owns the username/password login dialog, login packet submission, login-result alert handling, saved account-name persistence, and successful-login handoff to [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoginDialogPane` | `0x004fa7a0` | Builds the centered `DLGLOGIN.EPF` dialog with account/password edits and login/cancel buttons. |
| `OnServerMessage` | `0x004fab10` | Handles login reply packet type `2`, displays error alerts, switches reconnect modes, and on success closes login and initializes the main UI graph. |
| `HandleLoginDialogCommand` | `0x004fad00` | Sends login request from text controls or closes on cancel. |
| `UpdateLoginButtonEnabledState` | `0x004fae30` | Enables login button when account and password fields are non-empty. |
| `HandleMouseEvent` | `0x004fae90` | Dialog drag/control mouse handling with optional relay to main UI graph. |
| Destructor family | `0x005024cc`, `0x005024d7`, `0x005027d0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms constructor, virtual handlers, and destructor starts.
- `MainMenuPane::ActivateMenuItem` and `EnsureLoginDialogPane_4F8B30` construct this class.
- The success path calls [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f7d10`; keep that as a global UI bootstrap, not a login-dialog method.

## Cross-References

- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000IE][Config](by-file/Config.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: the login dialog has clear constructor, command, server-message, enable-state, mouse handling, destructor, and startup handoff documentation, but it is not yet a complete source-level dialog reconstruction. Evidence: linked main-menu login/account memory range, constructor/handler method table, login packet/result behavior, `InitializeMainUiGraph` handoff, and main-menu construction evidence.
