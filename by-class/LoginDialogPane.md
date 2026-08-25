*** UID:00007F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LoginDialogPane : public DialogPane
{
public:
    LoginDialogPane();
    virtual ~LoginDialogPane();

    virtual void OnControlCommand(int commandId, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoginDialogPane

## Status

- Confidence: very strong for the complete no-derived-field class surface, six human methods, three vtable views, singleton/resource/caller/source ownership, exact children, and compiler exclusions. Original stripped lexical spellings alone remain below final certainty.
- Source file: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), `NexusTK/login/LoginDialogPane.cpp`.
- Address range: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Historical recovered lead: `source-3/simroot_v2/class_LoginDialogPane.cpp`; current by-* and IDA evidence control where it differs.

## Class Purpose

`LoginDialogPane` owns the username/password login dialog, login packet submission, login-result alert handling, saved account-name persistence, and successful-login handoff to [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoginDialogPane` | `0x004fa7a0` | Builds the centered `DLGLOGIN.EPF` dialog with account/password edits and login/cancel buttons. |
| `HandlePacketEvent` | `0x004fab10` | Handles login reply packet type `2`, exact failure focus/text alert behavior, and ordered success close/MainMenu/account-persistence transition. |
| `OnControlCommand` | `0x004fad00` | Reads account/password controls, preserves independent config-gated argument shifts, calls file-local SendLoginRequest, copies server state, creates ScreenDimmer, or closes on cancel. |
| `UpdateActionButton` | `0x004fae30` | Enables child 1 only when account child 3 and password child 4 are both nonempty. |
| `HandlePointerOrMouseEvent` | `0x004fae90` | Exact move/down/double/up/wheel control dispatch, title drag/clamp/save, release redraw/presentation, and legacy MainMenu relay. |
| `~LoginDialogPane` | `0x005027d0` | Ordinary source deletes an active ScreenDimmer and clears the singleton; adjustor/scalar wrapper mechanics are compiler output. |

## Related Helper

| Helper | Address | Role |
| --- | --- | --- |
| [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) | `0x004f8b30-0x004f8b8d` | File-local login helper that checks `g_pLoginDialogPane` and constructs `LoginDialogPane` through source-level `new LoginDialogPane;`; recovered alias [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md). |
| [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) | `0x004fb2d0-0x004fb62a` | Source-ready file-local `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)` helper called once from `OnControlCommand` at `0x004fadbd`; it emits directly through [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), not through this class or a virtual/member route. |

## Evidence Notes

- IDA confirms constructor, virtual handlers, and destructor starts.
- `MainMenuPane::ActivateMenuItem` and [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) construct this class; the by-global [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) page preserves the recovered alias only.
- The success path calls [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f7d10`; keep that as a global UI bootstrap, not a login-dialog method.
- 2026-06-07 live IDA MCP reconfirms exact core functions at `0x004fa7a0-0x004faacd`, `0x004fab10-0x004face9`, `0x004fad00-0x004fae22`, `0x004fae30-0x004fae88`, and `0x004fae90-0x004fb2a6`, plus the raw constructor-cleanup fragment at `0x004faad0-0x004fab0f`.
- Constructor/data evidence ties the class to singleton slot `0x0069b484`, vtable bases `0x0061d388`, `0x0061d3e8`, and `0x0061d418`, resources `DLGLOGIN.EPF`/`DLGLOGIN.PAL`, saved-account config reads from `g_pConfig`, and screen/layer attachment through main UI layer slots.
- Vtable/read-only data refs bind `0x004fad00`, `0x004fae30`, `0x004fae90`, and `0x004fab10` to the `LoginDialogPane` dispatch table. The command handler has the only direct call to [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md); B005's accepted MCP session `6eab6bcb` evidence confirms the helper has no `this`/vtable/class-member route and should emit as a file-local [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) helper.
- Raw-byte checks keep switch/data tables inside the reviewed non-emitting parent and show exact alignment before adjacent `SendLoginRequest`.
- Allocation size `0x26c` equals the accepted DialogPane layout and every target access resolves to inherited fields or locals. LoginDialogPane therefore declares no derived data members.
- Primary vtable base `0x0061d388` carries the destructor and primary command/action slots; EventHandler-adjusted base `0x0061d3e8` carries pointer and packet slots; tertiary base `0x0061d418` is installed/restored by lifecycle code but contributes no additional sufficiently resolved human declaration.
- Exact source/coverage children are UID0004PJ constructor, UID0004PN constructor-unwind marker, UID0004PQ packet, UID0004PR command, UID0004PS action update, UID0004PT pointer/mouse, and UID0004PU destructor.

## Corrected Assignment Gate

This class is `92/94`, reconstructable, and emitted through [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). Constructor callers, resources, singleton, three vtable views, six exact human methods, inherited-size layout, source children, and existing file-local helpers establish the direct class/file route. The complete declaration is now formal; no behavior, field, cleanup, or source-placement blocker remains.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `92` | Complete inheritance, no-field layout, six-method declaration, vtable routes, exact children, singleton/resource/caller/helper/source ownership, compiler exclusions, negatives, and formal class block are resolved. |
| Confidence | `94` | Direct binary and current documentation support the full surface; only unknowable original lexical spellings keep confidence below final-audit quality. |

## Cross-References

- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0002Q4][0x004fa7a0-0x004fb2d0.LoginDialogPaneCore](by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md)
- [UID:0004PJ][0x004fa7a0-0x004faacd.LoginDialogPaneConstructor](by-memory/0x004fa7a0-0x004faacd.LoginDialogPaneConstructor.md)
- [UID:0004PN][0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup](by-memory/0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup.md)
- [UID:0004PQ][0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent](by-memory/0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent.md)
- [UID:0004PR][0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand](by-memory/0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand.md)
- [UID:0004PS][0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton](by-memory/0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton.md)
- [UID:0004PT][0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent](by-memory/0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent.md)
- [UID:0004PU][0x005027d0-0x00502841.LoginDialogPaneDestructor](by-memory/0x005027d0-0x00502841.LoginDialogPaneDestructor.md)
- [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md)

## Changes

- 2026-06-05: Marked reconstructable because live IDA MCP confirms this is NexusTK-owned login UI source with constructor, server-message, command, enable-state, mouse/drag, and destructor functions. Kept `AUTOGEN_PARENT_UID` blank because this class is `78/84`, below the 80/80 parent-attachment gate, even though [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x004fa7a0`, `0x004fab10`, `0x004fad00`, `0x004fae30`, `0x004fae90`, and `0x005027d0`; `callers` confirms the constructor is reached from `0x004f7b13` in `sub_4F7A10` and `0x004f8b79` in `sub_4F8B30`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/84`. Summary: the login dialog has clear constructor, command, server-message, enable-state, mouse handling, destructor, and startup handoff documentation, but it is not yet a complete source-level dialog reconstruction. Evidence: linked main-menu login/account memory range, constructor/handler method table, login packet/result behavior, `InitializeMainUiGraph` handoff, and main-menu construction evidence.
- 2026-06-07 A006 Batch006 parent-gate pass: changed completion/confidence from `78/84` to `86/88` and set `AUTOGEN_PARENT_UID:0000KX`. Evidence: live IDA MCP reconfirmed exact core method ranges, raw cleanup/table islands, constructor/resource/singleton/vtable refs, constructor callers from main-menu login paths, and the single `SendLoginRequest` call from the command handler. The direct parent [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) is `88/86`, so both sides satisfy the corrected 85/85 gate.
- 2026-06-20 B001 EnsureLoginDialogPane source-quality sync: score unchanged. Added the exact helper link for [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md), recorded that the helper emits through the login file as `static void EnsureLoginDialogPane()`, and retained [UID:0000PL][EnsureLoginDialogPane_4F8B30](by-global/EnsureLoginDialogPane_4F8B30.md) as a recovered alias/index.
- 2026-07-04 B005 UID0002Q5 implementation callback: score unchanged. Updated the related-helper inventory to record [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) as a source-ready file-local helper used by `HandleLoginDialogCommand`, emitted through [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md), and explicitly not a `LoginDialogPane` class method or virtual.
- 2026-07-14 B005 UID0002Q4 callback: raised `86/88` to `92/94` and applied the complete no-derived-field `DialogPane` subclass declaration with constructor, virtual destructor, `OnControlCommand`, `UpdateActionButton`, `HandlePointerOrMouseEvent`, `HandlePacketEvent`, and `[[CHILDREN]]`. Synchronized seven exact source/coverage children, three vtable views, `0x26c` inherited layout, two constructor callers, singleton/resources/config/MainMenu/ScreenDimmer routes, file-local Ensure/Send ownership, packet/command/pointer behavior, ordinary destructor source, compiler unwind/table/thunk/scalar exclusions, and historical stale method/mode/wait assumptions without removing earlier evidence.
