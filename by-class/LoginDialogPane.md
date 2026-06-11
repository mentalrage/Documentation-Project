*** UID:00007F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoginDialogPane

## Status

- Confidence: strong for constructor, vtable handlers, singleton/resource ownership, request-helper handoff, and successful-login transition; field names and final source-level cleanup shape remain below final C++ quality.
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

## Related Helper

| Helper | Address | Role |
| --- | --- | --- |
| [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) | `0x004fb2d0-0x004fb62a` | File-local login packet builder called once from `HandleLoginDialogCommand` at `0x004fadbd`; it is not a virtual class method, but it is directly owned by the same login source module. |

## Evidence Notes

- IDA confirms constructor, virtual handlers, and destructor starts.
- `MainMenuPane::ActivateMenuItem` and `EnsureLoginDialogPane_4F8B30` construct this class.
- The success path calls [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f7d10`; keep that as a global UI bootstrap, not a login-dialog method.
- 2026-06-07 live IDA MCP reconfirms exact core functions at `0x004fa7a0-0x004faacd`, `0x004fab10-0x004face9`, `0x004fad00-0x004fae22`, `0x004fae30-0x004fae88`, and `0x004fae90-0x004fb2a6`, plus the raw constructor-cleanup fragment at `0x004faad0-0x004fab0f`.
- Constructor/data evidence ties the class to singleton slot `0x0069b484`, vtable bases `0x0061d388`, `0x0061d3e8`, and `0x0061d418`, resources `DLGLOGIN.EPF`/`DLGLOGIN.PAL`, saved-account config reads from `g_pConfig`, and screen/layer attachment through main UI layer slots.
- Vtable/read-only data refs bind `0x004fad00`, `0x004fae30`, `0x004fae90`, and `0x004fab10` to the `LoginDialogPane` dispatch table. The command handler has the only direct call to [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md).
- Raw-byte checks keep switch/data tables inside the documented memory child and show `0xcc` alignment before adjacent `SendLoginRequest`.

## Corrected Assignment Gate

This class now clears the corrected direct-parent gate and is attached to [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). The child class is `86/88`, the direct parent file page is `88/86`, and the ownership is supported by constructor callers from main-menu login paths, login dialog resources, singleton/vtable refs, and the login request helper relationship. Final C++ remains blank because field names, enum names, and cleanup-fragment source form are still below the 95/95 reconstruction threshold.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The page now records exact core method bounds, the raw cleanup fragment, vtable-dispatched methods, constructor/resource/global state, related file-local request helper, caller evidence, and the corrected parent assignment gate. |
| Confidence | `88` | Live IDA MCP confirms function starts, callers, vtable slot refs, data/resource refs, request-helper callsite, and table/padding boundaries. Confidence remains under final reconstruction quality because source-level names and cleanup syntax are not fully recovered. |

## Cross-References

- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000IE][Config](by-file/Config.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this is NexusTK-owned login UI source with constructor, server-message, command, enable-state, mouse/drag, and destructor functions. Kept `AUTOGEN_PARENT_UID` blank because this class is `78/84`, below the 80/80 parent-attachment gate, even though [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x004fa7a0`, `0x004fab10`, `0x004fad00`, `0x004fae30`, `0x004fae90`, and `0x005027d0`; `callers` confirms the constructor is reached from `0x004f7b13` in `sub_4F7A10` and `0x004f8b79` in `sub_4F8B30`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: the login dialog has clear constructor, command, server-message, enable-state, mouse handling, destructor, and startup handoff documentation, but it is not yet a complete source-level dialog reconstruction. Evidence: linked main-menu login/account memory range, constructor/handler method table, login packet/result behavior, `InitializeMainUiGraph` handoff, and main-menu construction evidence.
- 2026-06-07 A006 Batch006 parent-gate pass: changed completion/confidence from `78/84` to `86/88` and set `AUTOGEN_PARENT_UID:0000KX`. Evidence: live IDA MCP reconfirmed exact core method ranges, raw cleanup/table islands, constructor/resource/singleton/vtable refs, constructor callers from main-menu login paths, and the single `SendLoginRequest` call from the command handler. The direct parent [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) is `88/86`, so both sides satisfy the corrected 85/85 gate.
