*** UID:00009I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "NexonclubRegistrationDialog.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../core/DialogPane.h"
#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"

class Event;
class VersatileAlertPane;

class NexonclubRegistrationDialog : public DialogPane
{
public:
    NexonclubRegistrationDialog(
        const wchar_t *messageText,
        FunctionObjectT<
            const mystr::StringBase<
                wchar_t,
                mystr::mychar_traits<wchar_t> > &> *registrationResultCallback);
    virtual ~NexonclubRegistrationDialog();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleType19Event(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void OnPendingRegistrationAlertClosed(unsigned long result);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        GetAccountText() const;
    void ShowRegistrationResultAlert(int stringId);

    FunctionObjectT<
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &> *m_registrationResultCallback;
    bool m_registrationRequestPending;
    unsigned char m_registrationRequestPadding[3];
    VersatileAlertPane *m_pendingStatusAlert;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NexonclubRegistrationDialog

## Status

- Confidence: very strong for class responsibility, exact direct inheritance and inherited handler facets, `0x278` layout, all derived vtable slots, resource and callback source causes, method contracts, parent file ownership, and formal class CPP/H routing. Complete executable method bodies remain independent UID0001CT/UID0001CU work.
- Current parent: [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- Main address range: [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- Support-helper detail: [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- Read-only data: [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md)
- Current recovered file: `source-3/simroot_v2/class_NexonclubRegistrationDialog.cpp`

## Class Purpose

`NexonclubRegistrationDialog` is a registration form dialog for Nexonclub accounts. It owns the account/password fields, submit/cancel/web actions, pending request alert, timeout cleanup, server response handling, and result callback. The submit path queues NCA work through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).

## Method Families

| Range | Method | Role |
| --- | --- | --- |
| `0x0052f950-0x0052ff9b` | constructor | Builds the account/password form from `DLGNC` resources, installs the primary/secondary/tertiary vtables, and assumes ownership of the caller-provided result callback at `+0x26c`. |
| `0x0052ffa0-0x00530015` | destructor | Cancels outstanding callback/status state, releases the owned result callback at `+0x26c`, and restores the class vtables while releasing alert objects. |
| `0x00530020-0x00530052` | `OnPendingRegistrationAlertClosed(unsigned long)` | Clears request-pending state, cancels timeout, and destroys status alert state; executable support detail remains in [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md). |
| `0x00530060-0x0053022b` | `OnControlCommand(int,int)` | Handles submit, cancel, web-registration commands, and the registration-time callback object setup. |
| `0x00530230-0x005303ef` | `HandleType19Event(Event*)` | Processes registration response/status data and routes result codes through the inherited EventHandler facet; executable support detail remains in UID0001CU. |
| `0x00530410-0x005304b4` | `OnTimer(int,int,int)` | Performs timeout cleanup and shows localized timeout string `234` through the inherited TimerHandler facet. |
| `0x005304c0-0x005304e1` | `StringBase<wchar_t,...> GetAccountText() const` | Reads account text control `2` through the MSVC hidden-result ABI; the wide `StringBase` return and callback parameter are the compiler-consistent source types, superseding the earlier `SimpleUString` approximation. Executable support detail remains in UID0001CU. |
| `0x005304f0-0x00530565` | `ShowRegistrationResultAlert(int)` | Creates localized registration-result alerts for string ids `228..232`; executable support detail remains in UID0001CU. |
| `0x00530565-0x0053057b` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Compiler thunk support. |
| `0x00530580-0x00530636` | scalar deleting destructor | Deleting-destructor wrapper. |

## Key Relationships

- Constructed by [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) and other registration launch sites. The proxy constructor provides the decoded prompt text plus a `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>` callback bound to `NexonclubProxyDialog::OnReplyText`; this class stores/releases/invokes that result callback after construction but does not own the proxy packet parse or opcode `0x3a` reply serialization.
- Submit reads [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) and calls the [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) NCA-update request wrapper at `0x00528310`.
- Uses [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) for account/password fields.
- Uses [UID:0000HE][AlertPanes](by-file/AlertPanes.md) for pending and result alerts.
- Owns [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md), including the three registration dialog vtable views, `DLGNC` resource strings, and the submit-time `PlainMemberFunctionObject` callback vtable.
- B002 2026-06-17 source-quality pass resolves the core private state directions: `m_registrationResultCallback` at `+0x26c`, `m_registrationRequestPending` at `+0x270`, `m_pendingStatusAlert` at `+0x274`, inherited `DialogPane` control manager at `+0x1fc`, and notification/timer callback subobject dispatch at `+0xa0/+0xa4`.
- Parent-chain gate: [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) is `92/94`; aggregate memory page [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) is `88/92`; support-helper page [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) is `94/95`; read-only data child [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) is `94/96`.

## CreateUserDialogPane Provider And Callback Contract

- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) is one of four proven constructor providers. When its boolean gate is false it sends the create-character request directly; when true it constructs the registration result callback and this dialog.
- The concrete callback is `PlainMemberFunctionObjectT<void (__thiscall CreateUserDialogPane::*)(const StringBaseW&), CreateUserDialogPane, const StringBaseW&>`. Its 24-byte object binds [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md), zero member adjustment, and the pane object.
- The constructor takes ownership at `m_registrationResultCallback` / object offset `+0x26c`. Cancel invokes the callback with an empty value; successful NCA state `0` invokes it with account text; the destructor releases it. The provider therefore must not delete the callback after construction.
- For this specialization, UID00046P stores only a non-empty callback value in the CreateUserDialogPane field at `+0x27c`, then always sends the character request. This class owns the generic registration lifecycle, not the CreateUserDialogPane-specific result policy.
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) is non-emitting compiler-generated support immediately before this class's existing read-only data at `0x006200a8`. Reusable callback source remains in [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md).

## Exact Inheritance And Object Layout

The only direct source base is `DialogPane`, whose established size is `0x26c`. RTTI lists `EventHandler` and `TimerHandler` because those facets are inherited through the existing Pane/DialogPane chain at complete-object offsets `+0xa0` and `+0xa4`; they must not be repeated as direct source bases. Allocation and field traffic establish a complete size of `0x278`.

| Offset | Size | Source field/region | Evidence |
| ---: | ---: | --- | --- |
| `+0x000` | `0x26c` | `DialogPane` direct base | existing UDT size and RTTI hierarchy |
| `+0x26c` | `4` | `FunctionObjectT<const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >&> *m_registrationResultCallback` | constructor ownership store, cancel/success invokes, destructor release; decorated callback vtables prove the wide StringBase contract and supersede the historical SimpleUString approximation |
| `+0x270` | `1` | `bool m_registrationRequestPending` | submit, event, timer, and cleanup reads/writes |
| `+0x271` | `3` | alignment padding | exact gap before pointer field |
| `+0x274` | `4` | `VersatileAlertPane *m_pendingStatusAlert` | pending alert store, cleanup, destruction, nulling |

The primary, EventHandler-facet, and TimerHandler-facet vptrs are stored by the constructor at `0x0052f999`, `0x0052f99f`, and `0x0052f9a9`, restored by the destructor at `0x0052ffcb`, `0x0052ffd1`, and `0x0052ffdb`, and used by the scalar deleting wrapper at `0x005305b2`, `0x005305b8`, and `0x005305c2`.

## Exact Virtual Contract

The 23-slot primary table contains compiler destruction, inherited LObject/Pane/DialogPane methods, and one source override: `OnControlCommand(int,int)` at slot `+0x48`. In order, the slots are scalar deleting destructor; `GetRuntimeClass`; `OnChangeMessage`; `UpdateRenderRegion`; `DrawOnTarget`; `Show`; `Hide`; `GetParentPane`; `InvalidateRect`; `GetDescription`; `GetScreenBounds`; `SetBounds`; `OnCreate`; layer insertion; `OnDestroy`; `OnShow`; `OnHide`; `OnPaint`; `OnControlCommand`; inherited no-op `UpdateActionButton`; `DrawBackground`; `DrawBorder`; and `SetHoverControl`. The current IDA guard-style label at primary slot `+0x4c` is misleading and does not indicate a derived source override.

The 11-slot EventHandler view starts at `0x0062010c`. Its slots are the `+0xa0` deleting-destructor adjustor, inherited pointer/mouse, key/text, IME, false packet-event, and system/control handlers, source override `HandleType19Event(Event*)` at `+0x18`, then handler-order forwarding, `GetLocalEventPair`, `GetScreenEventPair`, and `ShouldAcceptEvent`. The two-slot TimerHandler view starts at `0x0062013c` and contains the `+0xa4` deleting-destructor adjustor followed by source override `OnTimer(int,int,int)`.

## Resolved Source Methods And Callback

| Range | Source contract | Behavioral role |
| --- | --- | --- |
| `0x0052f950-0x0052ff9b` | constructor | builds the `DLGNC` form and assumes callback ownership |
| `0x0052ffa0-0x00530015` | destructor | releases callback and pending alert; compiler performs facet teardown |
| `0x00530020-0x00530052` | `OnPendingRegistrationAlertClosed(unsigned long)` | clears pending state, cancels timer 0, destroys and nulls alert; callback result is ignored |
| `0x00530060-0x0053022b` | `OnControlCommand(int,int)` | selectors 4/5/6 submit, cancel, or open the web-registration URL |
| `0x00530230-0x005303ef` | `HandleType19Event(Event*)` | EventHandler facet consumes channel `0x4e634175` and result states 0..5 |
| `0x00530410-0x005304b4` | `OnTimer(int,int,int)` | TimerHandler facet clears pending state and shows string 234 |
| `0x005304c0-0x005304e1` | `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetAccountText() const` | returns control 2 text through the MSVC hidden-result ABI; the former SimpleUString spelling is historical only |
| `0x005304f0-0x00530565` | `ShowRegistrationResultAlert(int)` | creates localized result alerts for ids 228..232 |
| `0x00530565-0x0053057b` | compiler adjustors | subtract `0xa0`/`0xa4` and dispatch deleting destruction |
| `0x00530580-0x00530636` | compiler scalar deleting destructor | generated from the virtual source destructor |

At `0x00530189`, `OnControlCommand` constructs a 24-byte `PlainMemberFunctionObject<void (__thiscall NexonclubRegistrationDialog::*)(unsigned long), NexonclubRegistrationDialog>`, stores member target `0x00530020` at `0x0053018f`, uses zero adjustment, and captures this dialog. Shared invoke/destructor/object-size support is generated through UID0001WQ; only the concrete binding belongs in this class method source.

## Resource And Compiler-Data Ownership

Constructor expressions consume `L"DLGNC.PAL"` at `0x00620144`, `L"DLGNC.EPF"` at `0x00620158`, and `L"DLGNC.EPD"` at `0x0062016c`. These are in-function source literals, not class globals. UID0003C7 contains the three class RTTI/vtable views, those literals, and the unsigned-long callback RTTI/vtable. It is class-owned evidence but false/non-emitting because the compiler/linker regenerate every table and the literals arise from constructor expressions. The class declaration and ordinary method definitions are the source causes; no raw table arrays belong in this file.

## Data Caveats

Historical `simroot_v2` output omitted several IDA-confirmed helper functions and carried stale method-name grading artifacts. Those omissions remain historical lead-quality problems, not ownership or declaration blockers. The accepted formal CPP/H above now supplies the one class declaration route. UID0001CT remains independent constructor/destructor work with blank formal blocks, while UID0001CU supplies the complete six-method formal CPP payload and intentionally blank H under this class-owned declaration route. The class declaration therefore must not be interpreted as completion of the independently owned UID0001CT bodies.

## Cross-References

- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md)
- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md)
- [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md)
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)

## 2026-08-11 UID0001CU Implementation Callback

- Current metadata is `94/95`; owner and emitter remain [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), position remains `0`, and the class remains reconstructable.
- The complete declaration is owned here in the formal H channel. The formal CPP channel remains the self-header include plus `[[CHILDREN]]`; support-helper bodies remain owned by [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md).
- The callback member at `+0x26c` and `GetAccountText` now use `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, matching the hidden-result ABI and the three create-user consumers. The historical `SimpleUString` spelling is retained above only as a superseded assumption.
- The physical `0x278` layout remains callback `+0x26c`, pending byte `+0x270`, three-byte padding, and pending alert pointer `+0x274`. No direct EventHandler or TimerHandler base was added: those facets remain inherited through `DialogPane`.
- The class declaration does not emit method bodies. Constructor/destructor coverage remains in [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md), and the six support bodies plus compiler-covered switch/adjustors remain in [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md).

## Changes

- 2026-07-26 B005 UID0003C7 callback incorporation:
  - Raised the class to `92/94`, retained owner/emitter UID0000M0, set emitter position `0`, and installed the accepted formal CPP/H declaration route.
  - Added exact direct `DialogPane` inheritance, inherited EventHandler/TimerHandler facets at `+0xa0/+0xa4`, complete `0x278` layout, all primary/facet virtual contracts, resolved source method names, callback specialization/binding, and `DLGNC` resource ownership.
  - Reclassified UID0003C7 as class-owned but non-emitting compiler/source-cause data. Preserved UID0001CT/UID0001CU as independent executable method-body work and rejected raw RTTI/vtable arrays or duplicate template declarations.

- 2026-07-22 B003 UID00046O provider/lifetime sync:
  - Kept class score `86/86`, parent UID0000M0, and existing aggregate/helper/data ownership.
  - Added UID00046O as a fourth exact constructor provider, the concrete three-parameter `CreateUserDialogPane` callback type, UID00046P binding, ownership transfer at `+0x26c`, cancel/success invocation, and destructor release.
  - Added UID0004WH as exact compiler-generated support and preserved the class/feature/template separation. No class-wide formal C++ was introduced by this support-only closure.

- 2026-06-17 B002 source-quality sync:
  - What existed before: the class page still described final helper/field names as provisional and cited only incomplete generated output.
  - Changed to: class relationship text now reflects [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md) at `86/90` and [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) at `85/90`, records the resolved `+0x26c/+0x270/+0x274/+0x1fc/+0xa0/+0xa4` directions, and clarifies that generated output is zero bytes while formal C++ remains blocked by coordinated class declaration and child-helper treatment.
  - Evidence: B002 reanalysis validated callback object setup, vtable/subobject liveness, NCA response state routing, account/password controls, alert/timer cleanup, and rejected proxy/alert/MiscWorkThread ownership moves.

- 2026-06-26 B008 proxy callback support sync:
  - What existed before: the class relationship text named `NexonclubProxyDialog` as a construction source but did not include the accepted source-facing callback target name from the proxy pass.
  - Changed to: clarified that the proxy provides `OnReplyText` through `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>` and that registration is the callback consumer/owner after construction.
  - Evidence: B008 live MCP session `80de0a67` confirms the proxy callback wrapper fields and the registration constructor handoff. Scores remain `86/86`.

- 2026-06-12 A002 Batch 257 parent-gate repair:
  - What existed before: the class was `82/80`; it was already attached to [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), but the confidence score was stale relative to the documented executable and helper evidence and blocked the exact read-only data child.
  - Changed to: `86/86`, refreshed method endpoints to current half-open IDA ranges, added the read-only data child [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md), and documented why the generated-source omission caveat is a final-C++ blocker rather than an ownership blocker.
  - Evidence: 2026-06-12 live IDA MCP `lookup_funcs` reconfirms constructor/destructor/command/response/status/helper/thunk/deleting-destructor bounds through `0x00530636`; `xrefs_to` and `py_eval` confirm the three vtable views, `DLGNC` resource-string refs, callback-object table, and URL successor boundary in the class-owned `.rdata` island.

- 2026-06-07: Raised confidence from `78` to `80` and attached parent `0000M0`.
  - Before: The class stayed just below the parent-attach gate even though the file page and by-memory evidence had already been refreshed.
  - After: The class is attached to [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) while final C++ remains gated by provisional field/helper names and active generated-output omissions.
  - Evidence: The file parent is `86/80`; the aggregate memory page is `82/88`; the support-helper page is `82/90`; together they document constructor/destructor/command/response/status/helper/thunk/deleting-destructor boundaries, constructor callers, NCA submission, response-state switch table, vtable refs, helper omissions, and padding.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed registration constructor/destructor/command/response/alert/helper/thunk/deleting-destructor starts at `0x0052f950`, `0x0052ffa0`, `0x00530020`, `0x00530060`, `0x00530230`, `0x00530410`, `0x005304c0`, `0x005304f0`, `0x00530565`, and `0x00530580`. Left `AUTOGEN_PARENT_UID` blank because this class confidence is below the 80 attachment gate even though [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) is the likely source-module parent.

### 2026-05-28 - Scalar Deleting Destructor Endpoint Corrected

- What existed before: the scalar deleting destructor was recorded as `0x00530580-0x00530635`.
- What changed: the range is now `0x00530580-0x00530636`.
- Why: IDA MCP reports `sub_530580` ending at `0x00530636`; the byte at `0x00530635` is part of the function.
- Before: completion/confidence metadata were `0/0` even though the page already contained detailed constructor/destructor, command, helper, status-alert, work-thread, and generated-output caveat notes.
- Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
- Evidence: IDA-backed method ranges, support-helper pages, construction relationships, text-edit/alert/work-thread dependencies, and data caveats are documented; confidence remains medium-high because active generated output still omits several helper bodies and should not be used alone for migration.
