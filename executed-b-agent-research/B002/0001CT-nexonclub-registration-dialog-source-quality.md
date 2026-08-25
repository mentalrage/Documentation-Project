** TARGET-REPORT-UID:0001CT **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CT NexonclubRegistrationDialog Source-Quality Research

Assignment: `B002-goal2-nexonclub-registration-dialog-source-quality-0001CT-20260617`

Primary target: [UID:0001CT] `by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md`

Mode: report-only. I did not edit by-memory docs, by-class docs, by-file docs, generated source, generated reports, the IDA database, or `by-memory/-coverage-report.md`.

## Executive Recommendation

Raise [UID:0001CT] from `82/88` to `86/90`, keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter [UID:0000M0] `NexonclubRegistrationDialog`, and keep the generated route `NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp`.

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0001CT] yet. The target is a multi-method aggregate containing constructor, ordinary destructor, command handler, notification handler, alert/timer callback, private helper methods, adjustor thunks, and scalar deleting destructor wrapper. The source shape is now high-confidence, but a formal block would need coordinated class declaration spelling, callback template typedefs, DialogPane subobject interface names, and child-helper treatment.

Recommended support sync: [UID:0001CU] can be raised from `82/90` to `85/90` if the supervisor updates its helper names and field/type notes from this report. It should also keep formal C++ blank pending the same coordinated declaration work.

## Evidence Reviewed

- Primary docs: [UID:0001CT] `0x0052f950-0x00530636.NexonclubRegistrationDialog`, [UID:0001CU] `0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers`, [UID:0000M0] class/file docs, and [UID:00009I] read-only data `0x006200a8-0x00620198`.
- Callback and alert docs: `FunctionObjectTemplates`, `PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback`, `AlertPanes`, `VersatileAlertPane`, and the executed B002 VersatileAlertPane callback report.
- Protocol/work-thread docs: `MiscWorkThread`, `g_pMiscWorkThread`, `MiscWorkThreadMessageId`, `ncauth::Notification`, `NcauthNotificationState`, and `NcauthConfirmUserUrlObfuscated`.
- Dialog/control docs: `DialogPane`, `TextEditControlPaneReadTextForwarder`, `MainUiLayerSlots`, `g_pLanguageMan`, and `g_useEpfAssets`.
- Generated context: `auto-generated/NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp` is currently zero bytes; `rg` found no generated bodies for the `sub_530xxx` helper island.
- Prior reports: the older B003 support-helper warning report, B001 FunctionObject destructor/template work, B001 NCA URL work, and the executed B002 VersatileAlertPane callback report were used as leads and then rechecked against docs/IDA.
- IDA MCP evidence: live IDB `NexusTK.exe.i64`; function inventory, Hex-Rays decompilation, xrefs, vtable refs, switch-table bytes, and direct PE abs32/rel32 scans were checked for starts inside `0x0052f950-0x00530636`.

## Boundaries And Liveness

The exact aggregate range should remain `0x0052f950-0x00530636`. `0x00530636-0x00530640` is `0xcc` padding, and `0x00530640` starts the next `NumberInputDialog` constructor. The target contains:

| Address | Source role |
| --- | --- |
| `0x0052f950-0x0052ff9b` | `NexonclubRegistrationDialog` constructor |
| `0x0052ffa0-0x00530015` | ordinary destructor body |
| `0x00530020-0x00530052` | pending-alert callback / pending-state cleanup |
| `0x00530060-0x0053022b` | command handler for submit/cancel/web registration |
| `0x00530230-0x00530410` | NCA notification/response handler with switch table |
| `0x00530410-0x005304b4` | timeout/status callback that clears pending state and shows id `234` |
| `0x005304c0-0x005304e1` | account text read helper |
| `0x005304f0-0x00530565` | localized result/failure alert helper |
| `0x00530565-0x00530570` | secondary-subobject destructor adjustor thunk |
| `0x00530570-0x0053057b` | tertiary-subobject destructor adjustor thunk |
| `0x00530580-0x00530636` | scalar deleting destructor wrapper |

Important padding/split points: `0x00530015-0x00530020`, `0x00530408-0x00530410`, `0x005304b4-0x005304c0`, `0x005304e1-0x005304f0`, `0x0053057b-0x00530580`, and `0x00530636-0x00530640`.

Liveness is not limited to direct calls. Constructor callers exist at `0x0052b6f4`, `0x0052d1a4`, `0x0052ea14`, and `0x005538d3` (`NexonclubProxyDialog` construction path). Support/helper liveness is via member-function callback objects and vtables:

- `0x00530020` is stored as a member-function pointer at `0x0053018f` into a `PlainMemberFunctionObject` used by `VersatileAlertPane`.
- `0x00530060`, `0x00530230`, and `0x00530410` are referenced by read-only vtables at `0x006200f4`, `0x00620124`, and `0x00620140`.
- `0x005304c0` is called from the success arm at `0x005302eb`.
- `0x005304f0` is called by failure arms for message ids `228..232`.
- `0x00530565` and `0x00530570` are vtable destructor adjustor thunks; `0x00530580` is the scalar deleting destructor referenced at `0x006200ac`.
- The switch table at `0x005303f0-0x00530408` is loaded from `0x005302e1` and has targets for states `0..5`.

PE-aware direct-edge/pointer scan supports the same treatment: real direct callers exist for the constructor and local helpers, and vtable/member-function-pointer data accounts for the no-direct-call methods. No evidence supports a dead-code or orphan-helper classification.

## Source Shape, Fields, And Helper Names

Recommended constructor signature direction:

```cpp
NexonclubRegistrationDialog::NexonclubRegistrationDialog(
    const wchar_t* messageText,
    FunctionObjectT<const StringBaseW&>* resultCallback);
```

Use a conservative `FunctionObject*` spelling if the exact project typedef for `FunctionObjectT<const StringBaseW&>` is not yet formalized. The first parameter is displayed in the dialog text in both EPF/PAL and legacy EPD construction paths. The second parameter is stored at `this+0x26c`, released by the destructor, and invoked with a string result on cancel/success.

Recommended field/type directions:

| Offset | Recommended source-facing role |
| --- | --- |
| `+0x0` | primary `NexonclubRegistrationDialog` vptr |
| `+0xa0` | secondary notification/listener subobject vptr |
| `+0xa4` | tertiary timer/status callback subobject vptr |
| `+0x1fc` | inherited `DialogPane` control manager pointer |
| `+0x26c` | `m_registrationResultCallback`, `FunctionObjectT<const StringBaseW&>*` direction |
| `+0x270` | `m_requestPending` / `m_registrationRequestPending`, byte |
| `+0x274` | `m_pendingStatusAlert` / `m_pendingRegistrationAlert`, `DialogPane*` or `AlertPane*` direction |

Recommended helper names/signatures:

| Address | Recommended name/signature direction | Notes |
| --- | --- | --- |
| `0x00530020` | `OnPendingRegistrationAlertClosed(unsigned long result)` or private `ClearPendingRegistrationState()` callback target | It ignores the alert result, clears `+0x270`, cancels timer through `+0xa4`, destroys `+0x274`, and is explicitly stored in a member callback object. |
| `0x00530060` | `OnCommand(unsigned int commandId, unsigned int commandParam)` | Handles submit id `4`, cancel id `5`, and web-registration id `6`. |
| `0x00530230` | `OnNcauthNotification(...)` / `HandleNcauthNotification(...)` | Secondary-vtable callback, consumes the NCA notification channel and payload state. |
| `0x00530410` | `OnRegistrationRequestTimeout(...)` / `ShowRegistrationStatusAlert(...)` | Tertiary/timer callback; clears pending state, cancels timer, destroys pending alert, shows localized id `234`. |
| `0x005304c0` | `GetAccountText(StringBaseW& out) const` / `ReadAccountText(...)` | Uses inherited control manager `+0x1fc`, control id `2`, and the shared text-edit read forwarder. |
| `0x005304f0` | `ShowRegistrationResultAlert(unsigned int messageId)` | Allocates a base alert pane using `g_pLanguageMan` and the shared alert button/table pointer. |
| `0x00530565`, `0x00530570` | destructor adjustor thunks | Compiler-generated, not source-authored functions. |
| `0x00530580` | scalar deleting destructor | Compiler wrapper for the ordinary virtual destructor; do not hand-author as a source method. |

Account/password access is now defensible: On submit, the control manager at `+0x1fc` is asked for control id `2` and id `3`, then both controls are read through the shared text-edit read forwarder. Control id `2` is the account/name field; control id `3` is the password field. The stale `ChattingColorPane::GetInputText` style naming should be rejected for these call sites; it is a shared text-control forwarding helper, not a chat/color feature method.

## Protocol, Alerts, And External Ownership

The request path is owned by `MiscWorkThread`, not by this dialog. On submit, `OnCommand` reads account/password text, calls `g_pMiscWorkThread->RequestNCAUpdate(...)`, marks `+0x270` pending, creates a `VersatileAlertPane` pending alert with localized string id `233`, and starts a `30000` ms timer through the `+0xa4` subobject.

The worker request id is `0x4e434175` (`NCAu` in `MiscWorkThreadMessageId`). The dialog response handler checks notification channel `0x4e634175`, reads the `ncauth::Notification` payload pointer from the envelope, and reads the state at payload `+4`.

State/message mapping:

| State | Meaning direction | Dialog action |
| --- | --- | --- |
| `0` | accepted / registration confirmed | read account text, invoke `m_registrationResultCallback`, close dialog |
| `1` | account/id rejected | show localized message id `228` |
| `2` | password rejected | show localized message id `229` |
| `3` | rejected-other/server failure | show localized message id `230` |
| `4` | open/connect failed | show localized message id `231` |
| `5` | read/parse failed | show localized message id `232` |

The timeout/status callback shows localized message id `234`. The pending/waiting alert uses id `233`. The web-registration button opens:

```text
http://www.nexon.com/KR/Page/NX.aspx?URL=Login/Register
```

The fallback confirm-user URL `http://mail.nexonclub.com/clubadmin/confirmuser?ID=%s&PW=%s` remains owned by `MiscWorkThread::ProcessNCAUpdate` and the obfuscated NCA URL data page, not by this dialog.

Global/type naming recommendations:

- Use `g_pMiscWorkThread` for `0x0067ab50`.
- Use `g_pLanguageMan` for `0x0067a750`.
- Use `g_useEpfAssets` / `byte_66DA97` as the EPF/PAL versus legacy EPD resource branch flag.
- Use the existing `MainUiLayerSlots` direction for `dword_69B36C`; do not create a registration-dialog-local global name for it.
- Treat `off_613A18` and `off_614CBC` as shared alert button/layout tables until their final source names are established.

## Callback And Source Placement

`NexonclubProxyDialog` constructs a `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBase&>` callback and passes it to the registration dialog constructor. The registration dialog stores that object at `+0x26c`, owns/releases it, and invokes it with an empty string on cancel or the accepted account string on success. That makes `NexonclubProxyDialog` the provider of the result callback and `NexonclubRegistrationDialog` the owner/consumer after construction.

`0x00530020` is a source-authored member callback target because the dialog writes that member function address into a 24-byte `PlainMemberFunctionObject` for `VersatileAlertPane`. It should not be classified as a duplicate, orphan, or compiler artifact merely because it lacks normal direct-call xrefs.

`VersatileAlertPane` and base alert pane allocation remain owned by `AlertPanes`. Callback object templates remain owned by `FunctionObjects`. NCA worker request and network/url fallback remain owned by `MiscWorkThread`. The primary owner/emitter for this target should remain [UID:0000M0] `NexonclubRegistrationDialog`; no evidence supports moving this aggregate under `NexonclubProxyDialog`, `AlertPanes`, or `MiscWorkThread`.

## Generated Output Caveat

The active generated file `auto-generated/NexusTK/ui/dialogs/NexonclubRegistrationDialog.cpp` is zero bytes, and `rg` found no generated `sub_530xxx` helper output. The by-memory route is still correct, but generated output is currently effectively missing for this class. This should be recorded as a generation/output caveat, not as evidence that the functions are not reconstructable or not source-authored.

## Heuristic / Inference Reanalysis And Validation

Best defensible source directions:

- The source unit is `NexonclubRegistrationDialog.cpp` under [UID:0000M0], with constructor/destructor plus private command, notification, timeout/status, account-read, and localized-alert helpers.
- `+0x26c` is a result callback field, best named `m_registrationResultCallback` or `m_resultCallback`. Evidence: constructor stores parameter `a3`; cancel and success paths invoke vtable slot `+0x0c` with a string; destructor releases through the callback object's release/destroy slot; proxy constructor provides the concrete string callback object.
- `+0x270` is a pending/request-active byte, best named `m_registrationRequestPending` or `m_requestPending`. Evidence: set to `1` immediately after queuing `RequestNCAUpdate`, checked before accepting NCA notifications, and cleared in response, timeout, and alert-close cleanup paths.
- `+0x274` is a pending/status alert pointer, best named `m_pendingStatusAlert` or `m_pendingRegistrationAlert`. Evidence: submit stores a `VersatileAlertPane` there, cleanup paths destroy and null it, response path destroys it before showing final alerts, and timeout/status paths destroy it before showing message id `234`.
- `+0xa0` and `+0xa4` are subobject/interface vptr regions. Evidence: vtable refs to response/status methods, destructor adjustor thunks subtract `0xa0`/`0xa4`, and timer calls target `this+0xa4`.
- `+0x1fc` is inherited `DialogPane` control manager state. Evidence: DialogPane docs and decompilation show control lookup by ids `2` and `3`; it is not a registration-specific pointer.

Evidence checked:

- IDA function starts and decompilation for every child range from `0x0052f950` through `0x00530636`.
- Vtable references in `0x006200a8-0x00620198`, including primary/secondary/tertiary vtables and callback-object vtable at `0x00620184`.
- Xrefs to constructor, member-function callback target, OnCommand, notification/status virtual slots, helper calls, and destructor thunks.
- PE abs32/rel32 scans for helper starts and switch-table target data.
- Existing class/file/support docs, proxy callback docs, function-object docs, alert-pane docs, MiscWorkThread/NCA docs, and generated output route.

Rejected alternatives:

- Treating `0x00530020` as a retained duplicate or dead helper is rejected. Its address is materialized into a callback object in `OnCommand`, and its behavior exactly matches the pending-alert cleanup role.
- Treating `0x00530230` and `0x00530410` as no-direct-xref dead methods is rejected. Both are vtable-referenced callbacks with subobject adjustor/destructor evidence.
- Naming the text read helper as a chat/color-specific method is rejected. The local call path is through the inherited dialog control manager and the shared text-edit read forwarder.
- Moving protocol ownership to `NexonclubRegistrationDialog` is rejected. The dialog queues the request and consumes notifications; URL construction, fallback URL data, worker message dispatch, and network/read failure semantics are owned by `MiscWorkThread` and `ncauth` docs.
- Moving result-callback ownership to `NexonclubProxyDialog` after construction is rejected. Proxy constructs/provides the callback; the registration dialog stores, invokes, and releases it.
- Populating final C++ now is rejected despite the score lift. The source shape is clear enough for score improvement, but the formal block would conflate an aggregate range with multiple source methods, compiler thunks, and project-wide declaration spelling still being finalized.

Validation of current docs:

- Current docs are correct on the aggregate range, owner/emitter, constructor/destructor/helper island, NCA switch table, and reconstructability.
- Current docs understate the source quality by leaving field/helper names and no-direct-xref treatment as unresolved. The evidence above resolves those points enough to clear the 85/85 gate.
- Current docs should be updated to explicitly call out generated output being zero bytes rather than merely incomplete.
- Current docs should keep blank formal C++, but for a different reason than uncertainty about helper liveness: the remaining blocker is formal aggregate/source-declaration integration, not behavioral reconstruction.

Score/source-placement/final-C++ impact:

- [UID:0001CT] should become `86/90`, still reconstructable and emitting through [UID:0000M0].
- [UID:0001CU] can become `85/90` if synchronized with this helper-name/field-name research.
- No owner/emitter move is recommended.
- Formal C++ should remain blank for [UID:0001CT] and [UID:0001CU] until a coordinated class declaration and child-helper C++ pass is performed.

## First-Draft C++ Recommendation

Because the recommended [UID:0001CT] score clears the 85/85 gate, this section is included. Formal `RECONSTRUCTION_CPP CODE` for [UID:0001CT] should remain blank. The sketch below is review-only source shape and must not be pasted into the formal block as-is.

```cpp
class NexonclubRegistrationDialog : public DialogPane {
public:
    NexonclubRegistrationDialog(const wchar_t* messageText,
                                FunctionObjectT<const StringBaseW&>* resultCallback);
    ~NexonclubRegistrationDialog() override;

private:
    int OnCommand(unsigned int commandId, unsigned int commandParam);
    int OnNcauthNotification(const NotificationEnvelope* notification);
    int OnRegistrationRequestTimeout(/* timer callback args */);
    void OnPendingRegistrationAlertClosed(unsigned long result);
    void ReadAccountText(StringBaseW& out) const;
    void ShowRegistrationResultAlert(unsigned int messageId);

    FunctionObjectT<const StringBaseW&>* m_registrationResultCallback; // +0x26c
    unsigned char m_registrationRequestPending;                         // +0x270
    AlertPane* m_pendingStatusAlert;                                    // +0x274
};

void NexonclubRegistrationDialog::OnPendingRegistrationAlertClosed(unsigned long) {
    m_registrationRequestPending = 0;
    CancelTimerThroughTertiarySubobject();
    if (m_pendingStatusAlert != nullptr) {
        DestroyDialogPane(m_pendingStatusAlert);
        m_pendingStatusAlert = nullptr;
    }
}

int NexonclubRegistrationDialog::OnCommand(unsigned int commandId, unsigned int) {
    switch (commandId) {
    case 4: {
        StringBaseW account;
        StringBaseW password;
        ReadControlText(2, account);
        ReadControlText(3, password);
        g_pMiscWorkThread->RequestNCAUpdate(account, password);
        m_registrationRequestPending = 1;
        m_pendingStatusAlert = CreateVersatileAlertPane(this, 233, OnPendingRegistrationAlertClosed);
        StartRegistrationTimer(30000);
        return 1;
    }
    case 5: {
        StringBaseW empty;
        m_registrationResultCallback->Invoke(empty);
        DestroyDialogPane(this);
        return 1;
    }
    case 6:
        ShellExecuteA(nullptr, nullptr,
                      "http://www.nexon.com/KR/Page/NX.aspx?URL=Login/Register",
                      nullptr, nullptr, SW_SHOWNORMAL);
        return 1;
    default:
        return 0;
    }
}
```

## Metadata Recommendation

Recommended [UID:0001CT] header values:

```text
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000M0
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000M0
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: leave blank
```

Recommended [UID:0001CU] support sync, if applied:

```text
COMPLETION: 85
CONFIDENCE: 90
CANONICAL_OWNER: 0001CT
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000M0
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: leave blank
```

## Supervisor-Owned Coverage Rows

Replace the existing [UID:0001CT] row in `by-memory/-coverage-report.md` at the current `0x0052f950-0x00530636` placement with:

```text
    - [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis confirms exact 0x0052f950-0x00530636 aggregate, constructor/destructor/command/NCA-notification/status/helper/thunk/deleting-destructor boundaries, response-state switch table 0x005303f0-0x00530408, result callback field +0x26c as shared FunctionObjectT<const StringBase&> direction, pending byte +0x270, pending/status alert pointer +0x274, DialogPane control manager +0x1fc account/password controls 2/3, 30-second timer path on +0xa4, NCAu request/notification split through MiscWorkThread/ncauth::Notification, proxy callback ownership, generated zero-byte output caveat, and formal C++ remains blank because the target is a multi-method aggregate with compiler destructor/thunk artifacts and unresolved final declaration spelling.
```

If the supervisor applies the support sync for [UID:0001CU], replace its existing row immediately after [UID:0001CT] with:

```text
    - [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) : reconstructable : 85% : very strong : B002 2026-06-17 source-quality reanalysis resolves the support island as NexonclubRegistrationDialog-owned private helper/virtual/callback code: pending-alert callback 0x00530020, OnCommand submit/cancel/web cases, NCAu notification handler 0x00530230 with switch table 0x005303f0-0x00530408, account text getter 0x005304c0, localized alert helper 0x005304f0 for ids 228-234, +0x26c result callback, +0x270 pending byte, +0x274 pending/status alert pointer, +0x1fc DialogPane control manager, +0xa0/+0xa4 subobject dispatch, adjustor thunks 0x00530565/0x00530570, and final C++ remains blank pending coordinated exact method declarations.
```

No insert/delete coverage rows are recommended.

## Support Docs To Update

- [UID:0001CT] target page: update field names/types, helper names, NCA state/message table, generated zero-byte output caveat, and do-not-populate formal C++ rationale.
- [UID:0001CU] support helper page: update helper names/signatures, field offsets, callback/vtable liveness evidence, switch-table state meanings, and thunk/deleting-destructor treatment.
- [UID:0000M0] class/file pages: update method map and field table with `m_registrationResultCallback`, `m_registrationRequestPending`, and `m_pendingStatusAlert`; note that generated output is currently zero bytes.
- [UID:00009I] read-only data page: no score change required, but it can cross-link the callback-object vtable `0x00620184` and the primary/secondary/tertiary vtable roles from this report.
- `NexonclubProxyDialog` docs: optional cross-link only; proxy remains callback provider/caller, not owner of [UID:0001CT].
- `MiscWorkThread`, `ncauth::Notification`, `NcauthNotificationState`, `FunctionObjects`, and `AlertPanes` docs do not require metadata changes from this pass.

## Validation Commands

After supervisor-owned doc edits, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001CT-nexonclub-registration-dialog-source-quality-removed.md](0001CT-nexonclub-registration-dialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files, Leases, Blockers

Changed file:

- `tools/leaser/Agents/Agent-B002/research/0001CT-nexonclub-registration-dialog-source-quality.md`

Leases used: none beyond the assigned B002 report-only scope.

Blockers: none for supervisor review. The only remaining blocker is for formal C++ population, not for score/source-quality execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001CT-nexonclub-registration-dialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001CT"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CT-nexonclub-registration-dialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001CT-nexonclub-registration-dialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
