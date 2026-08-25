*** UID:0000M0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NexonclubRegistrationDialog

## Status

- Confidence: very strong for module ownership, exact class declaration/source cause, direct inheritance and layout, executable range inventory, read-only compiler-data regeneration, callback/resource wiring, and the now-populated support-helper source route. Constructor/destructor reconstruction remains independently owned by UID0001CT.
- Proposed module: `ui/dialogs/NexonclubRegistrationDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_NexonclubRegistrationDialog.cpp`
- Main memory range: [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- Support-helper detail: [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- Read-only data: [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md)

## File Role

`NexonclubRegistrationDialog` owns the Nexonclub account-registration form. It builds the username/password dialog, submits the registration request through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), manages a pending alert and timeout, handles server response/status messages, opens the web registration URL when requested, and calls back to the caller with the result.

This is related to [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md), but not identical: the proxy parses an NPC/message packet, decodes the prompt, constructs a `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>` callback bound to `NexonclubProxyDialog::OnReplyText`, and launches this registration dialog; the registration dialog owns the account form and result flow after construction.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NexonclubRegistrationDialog` | `0x0052f950-0x00530636` | Registration form, command handling, pending/status alerts, response callback, destructor/thunk support. |
| `CreateUserDialogPane` registration provider | [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md) | External feature construction site that provides a concrete const-wide-string callback; this file assumes ownership at `+0x26c`, invokes it on cancel/success, and releases it during destruction. |
| registration support helpers | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Six source methods now carried by the target's formal CPP, plus one compiler-covered switch table and two deleting-destructor adjustors. |
| read-only dialog data | [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) | Registration dialog RTTI/vtables, `DLGNC` resource strings, and submit-time callback-object vtable generated from this source module. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x0052f950-0x0052ff9b` | constructor | Builds the `DLGNC` account/password form, sets result handler, installs the class vtables, and enters modal input. |
| `0x0052ffa0-0x00530015` | destructor | Cancels callback/status state, restores vtables, and destroys pending alert state. |
| `0x00530020-0x00530052` | `OnPendingRegistrationAlertClosed(unsigned long)` | Clears pending state, cancels timer `0`, destroys and nulls the pending alert; the callback result is ignored. Executable support detail remains in [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md). |
| `0x00530060-0x0053022b` | `OnControlCommand(int,int)` | Handles submit, cancel, open-web-registration commands, and callback-object setup. |
| `0x00530230-0x005303ef` | `HandleType19Event(Event*)` | Handles NCA notification channel `0x4e634175` and routes result states `0..5` to the callback or result alerts; executable support detail remains in UID0001CU. |
| `0x00530410-0x005304b4` | `OnTimer(int,int,int)` | Clears pending state and timer, releases the pending alert, and shows localized timeout string `234`. |
| `0x005304c0-0x005304e1` | `StringBase<wchar_t,...> GetAccountText() const` | Returns account control `2` text through the MSVC hidden-result ABI; the wide StringBase spelling supersedes the earlier SimpleUString approximation. |
| `0x005304f0-0x00530565` | `ShowRegistrationResultAlert(int)` | Creates localized registration-result alerts for string ids `228..232`; executable support detail remains in UID0001CU. |
| `0x00530565-0x0053057b` | [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md) | Two deleting-destructor adjustor thunks generated from the inherited handler facets; both are compiler-covered and intentionally have no handwritten emitted bodies. |
| `0x00530580-0x00530636` | scalar deleting destructor | Deleting-destructor wrapper. |

## Source-Quality Notes

- B002 2026-06-17 reanalysis resolves the main source-facing private state as `m_registrationResultCallback` at `+0x26c`, `m_registrationRequestPending` at `+0x270`, `m_pendingStatusAlert` at `+0x274`, inherited `DialogPane` control manager at `+0x1fc`, and secondary/tertiary notification/timer callback dispatch at `+0xa0/+0xa4`.
- The accepted six source contracts are `OnPendingRegistrationAlertClosed(unsigned long)` at `0x00530020`, `OnControlCommand(int,int)` at `0x00530060`, `HandleType19Event(Event*)` at `0x00530230`, `OnTimer(int,int,int)` at `0x00530410`, wide `StringBase GetAccountText() const` at `0x005304c0`, and `ShowRegistrationResultAlert(int)` at `0x005304f0`. Earlier generic command/NCA/status helper and SimpleUString alternatives are historical assumptions retained only in dated change records. The switch table at `0x005303f0`, adjustors at `0x00530565/0x00530570`, and scalar deleting destructor at `0x00530580` remain compiler products.
- NCA response state `0` invokes the result callback with the account text and closes the dialog. States `1..5` map to localized messages `228..232`; the pending alert uses `233`, and timeout/status uses `234`. Request/url construction remains owned by `MiscWorkThread`, while proxy dialog remains the callback provider, not the owner after construction.

## Accepted Header And Source Topology

- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md) is the sole class declaration carrier and emits at position `0` through this file. Its CPP channel includes `NexonclubRegistrationDialog.h` and provides `[[CHILDREN]]`; its H channel declares the `DialogPane`-derived class, virtual source methods, private helpers, and exact trailing fields.
- The direct base is only `DialogPane` (`0x26c` bytes). RTTI EventHandler and TimerHandler views at complete-object offsets `+0xa0/+0xa4` are inherited facets, not additional direct source bases.
- The complete object is `0x278` bytes: result callback `+0x26c`, pending byte `+0x270`, three alignment bytes, and pending status alert pointer `+0x274`.
- [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) is now false/non-emitting. Its three class RTTI/vtable views and concrete callback RTTI/vtable are compiler products; `DLGNC.PAL`, `DLGNC.EPF`, and `DLGNC.EPD` are constructor-expression literals. No raw vtable/RTTI arrays or standalone literal globals belong in this module.
- The concrete unsigned-long alert callback is generated from shared UID0001WQ FunctionObjects declarations plus the `OnControlCommand` binding to `OnPendingRegistrationAlertClosed(unsigned long)`. The reusable template is not duplicated here.
- UID0001CT remains independent constructor/destructor reconstruction work. UID0001CU now supplies all six accepted support bodies through its formal CPP while keeping the switch table and deleting adjustors compiler-covered rather than handwritten.

## Exact Class And Compiler-Data Relationship

The primary table at `0x006200ac` has 23 slots and contains one class-specific primary override, `OnControlCommand(int,int)` at `+0x48`; all other source-visible entries are inherited LObject/Pane/DialogPane behavior, while the deleting destructor is compiler output. The EventHandler facet table at `0x0062010c` has 11 slots and carries `HandleType19Event(Event*)` at `+0x18`. The TimerHandler facet table at `0x0062013c` has two slots and carries `OnTimer(int,int,int)` at `+0x04`. Deleting-destructor adjustors at `0x00530565` and `0x00530570` recover the complete object from `+0xa0` and `+0xa4`; the scalar wrapper at `0x00530580` is likewise compiler-generated from the virtual destructor.

The callback table at `0x00620184` has five slots: shared scalar deleting destructor `0x0049b090`, inherited runtime-class and change-message support, shared one-argument invoke wrapper `0x0049af00`, and object-size result `24` at `0x004673f0`. `OnControlCommand` stores this table at `0x00530189`, member target `0x00530020` at `0x0053018f`, zero adjustment, and the dialog object. This establishes source construction rather than a raw table definition.

## Exact Module Method Contracts

| Range | Source-facing contract | File responsibility |
| --- | --- | --- |
| `0x0052f950-0x0052ff9b` | constructor | dialog/resource construction and callback ownership transfer |
| `0x0052ffa0-0x00530015` | destructor | callback/alert release and source-level destruction |
| `0x00530020-0x00530052` | `OnPendingRegistrationAlertClosed(unsigned long)` | pending timer/alert cleanup callback |
| `0x00530060-0x0053022b` | `OnControlCommand(int,int)` | selectors 4/5/6 for submit/cancel/web |
| `0x00530230-0x005303ef` | `HandleType19Event(Event*)` | NCA notification channel `0x4e634175`, states 0..5 |
| `0x00530410-0x005304b4` | `OnTimer(int,int,int)` | timeout cleanup and string 234 alert |
| `0x005304c0-0x005304e1` | `StringBase<wchar_t,...> GetAccountText() const` | control 2 text return through hidden-result ABI |
| `0x005304f0-0x00530565` | `ShowRegistrationResultAlert(int)` | localized ids 228..232 |
| `0x00530565-0x00530636` | compiler adjustors/deleting wrapper | generated from inheritance and virtual destruction; no handwritten bodies |

## CreateUserDialogPane Provider Boundary

- UID00046O is one of four proven callers of the constructor at `0x0052f950`. Its true branch builds this dialog with language string `227`; its false branch bypasses registration and sends the create-character request.
- The concrete object is `PlainMemberFunctionObjectT<void (__thiscall CreateUserDialogPane::*)(const StringBaseW&), CreateUserDialogPane, const StringBaseW&>`. UID00046O allocates 24 bytes, binds [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md), uses zero adjustment, and captures the pane.
- This file owns the callback after the constructor stores it at `m_registrationResultCallback` / `+0x26c`: cancel invokes an empty value, successful NCA state `0` invokes account text, and the destructor releases the object. The CreateUserDialogPane source owns only construction and its callback-specific result policy.
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md) is exact non-emitting compiler support generated from [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) plus UID00046O's construction expression. It is adjacent to, but excluded from, this file's read-only data child beginning at `0x006200a8`.
- The callback provider/lifetime closure strengthens the file inventory but does not justify moving FunctionObjects code, raw vtable data, or CreateUserDialogPane feature code into this module. The current provider-boundary score is `92/94`.

## Ownership Notes

- The helper group at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0` stays with this class. Historical generated-source snapshots omitted or polluted these helpers; the dated command-`000000023107` readback contains the complete accepted route, and later gates must reread validator metadata dynamically rather than revive the old omission.
- `0x005304c0` and `0x005304f0` are response/status helpers for the registration dialog, not chat-color or generic alert ownership by themselves.
- IDA xrefs show the submit path reads [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) and calls the `MiscWorkThread` NCA-update submission wrapper at `0x00528310`.
- The constructor is called from multiple account/registration launch sites, including [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md).
- The proxy constructor call at `0x005538d3` is a provider/consumer boundary: [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) owns packet parsing and opcode `0x3a` reply emission, while this file owns storing, releasing, and invoking the registration result callback.
- Use [UID:0000HE][AlertPanes](by-file/AlertPanes.md) only as the shared alert-control dependency; do not move registration response policy into alert infrastructure.
- [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md) belongs directly to this file through the registration dialog class declaration, constructor resource-name use, and `OnControlCommand` callback-object setup.

## Current Data Caveats

- Current by-* formal channels carry the UID00009I declaration route and the UID0001CU six-method CPP payload. Generated CPP/H refresh and physical output verification remain supervisor-owned; this page does not assert one dated generated artifact as permanently current. UID0001CT remains the separate constructor/destructor source task.
- Historical 2026-05-25 state: active output omitted helpers at `0x00530020`, `0x00530230`, `0x005304c0`, and `0x005304f0`. The UID0001CU callback supersedes that omission with the complete six-method formal payload.
- Historical disabled-output snapshots reported one missing thunk body at `0x00530565`; IDA instead confirms an 11-byte compiler-generated adjustor thunk that subtracts `0xa0` from `this` and jumps to `0x00530580`, so no handwritten body is missing from the accepted source route.
- Current `simroot_v2` `.meta_wave3` and `.meta_old` files contain stale historical grading artifacts and are not current evidence.
- The former blanket formal-C++ blocker is resolved for the class declaration and UID0001CU support-helper routes. UID0001CT constructor/destructor bodies remain separate; compiler tables and adjustors remain intentionally non-emitting.

## Cross-References

- [UID:00009I][NexonclubRegistrationDialog](by-class/NexonclubRegistrationDialog.md)
- [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md)
- [UID:0001CU][0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers](by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md)
- [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md)
- [UID:00046O][0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest](by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md)
- [UID:00046P][0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult](by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md)
- [UID:0004WH][0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData](by-memory/0x00620090-0x006200a8.CreateUserDialogPaneRegistrationCallbackVtableData.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)

## 2026-08-11 UID0001CU Implementation Callback

- Current metadata is `92/94`; canonical ownership remains `FILE` at `NexusTK/ui/dialogs/`.
- The source module now routes the complete UID00009I class H declaration and UID0001CU six-method CPP payload. The pending alert cleanup, selectors 4/5/6, NCA channel/state handling, timeout, wide hidden-result getter, and localized result alert are no longer generic or empty-emitter placeholders.
- The exact source/compiler boundary is retained: the `0x005303f0` switch table, `0x00530565/0x00530570` adjustors, and deleting-destructor wrapper are compiler products; UID0003C7 RTTI/vtables/resource literals remain non-emitting compiler/source-expression evidence.
- The direct class layout remains `0x278`, with callback `+0x26c`, pending byte `+0x270`, padding, and alert pointer `+0x274`. The callback/result type is wide `StringBase`, and the create-user provider consumers retain their own feature-source ownership.
- UID0001CT remains responsible for constructor/destructor source. No FunctionObjects templates, alert implementations, NCA worker code, or create-user policy moved into this module.

## Changes

- 2026-07-26 B005 UID0003C7 callback incorporation:
  - Raised the file to `90/93` while retaining `NexusTK/ui/dialogs/` and file ownership.
  - Added the sole UID00009I CPP/H declaration route, direct `DialogPane` inheritance, inherited facets, `0x278` layout, exact source method contracts, `DLGNC` constructor literals, unsigned-long callback binding, and no-raw-table source policy.
  - Reclassified UID0003C7 as non-emitting compiler/source-cause evidence and kept UID0001CT/UID0001CU executable bodies as independent incomplete work rather than using class declaration output to hide their remaining markers.

- 2026-07-22 B003 UID00046O provider/lifetime sync:
  - Kept file score `87/86`, proposed path, main aggregate/helper/data inventory, and source ownership.
  - Added UID00046O as a fourth constructor provider and documented the concrete three-parameter callback, UID00046P binding, `+0x26c` ownership handoff, cancel/success invocation, and destructor release.
  - Added UID0004WH as exact adjacent compiler support while preserving the source boundary between this registration module, CreateUserDialogPane feature code, and shared FunctionObjects template source.

- 2026-06-17 B002 source-quality sync:
  - What existed before: file ownership was strong, but source-quality text still treated helper/field names as mostly unresolved and did not record the zero-byte generated output caveat.
  - Changed to: added source-quality notes for `m_registrationResultCallback`, `m_registrationRequestPending`, `m_pendingStatusAlert`, inherited control manager, notification/timer subobjects, helper-name directions, NCA state/message routing, and the accepted formal-C++ do-not-populate reason.
  - Evidence: B002 validated the registration-dialog aggregate and support-helper island against live IDA, vtable/callback references, account/password control lookup, NCA worker/notification split, proxy callback provider relationship, and rejected ChattingColor/Alert/MiscWorkThread ownership alternatives.

- 2026-06-26 B008 proxy callback support sync:
  - What existed before: the file page already separated proxy from registration but did not include the accepted `OnReplyText` callback target/source expression from the proxy pass.
  - Changed to: added the provider/consumer boundary: proxy supplies prompt text and `PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(this, &NexonclubProxyDialog::OnReplyText)`, registration stores/releases/invokes the result callback, and proxy keeps packet/reply ownership.
  - Evidence: B008 live MCP session `80de0a67` confirms callback wrapper setup and the constructor call at `0x005538d3`. Scores remain `87/86`.

- 2026-06-12 A002 Batch 257 parent-gate repair:
  - What existed before: the file page was `86/80`; it had a strong role/function map, but the confidence text still treated generated-source omissions as an ownership blocker and did not include the exact registration read-only data child.
  - Changed to: `87/86`, added [UID:0003C7][0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData](by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md), refreshed method endpoints to current IDA half-open ranges, and clarified that the generated-output omissions block final C++ rather than source-file ownership.
  - Summary/evidence: 2026-06-12 live IDA MCP reconfirms all executable function bounds, constructor/destructor/deleting-destructor vtable refs, constructor resource-string xrefs, `OnCommand` callback-object setup, and URL successor boundary. This raises the direct parent chain over the strict `85/85` gate for the registration read-only data child.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented registration-dialog constructor anchor at `0x0052f950`; proposed-source-tree places this account-registration form with adjacent UI dialog modules rather than login shell or network request code.
### 2026-05-28 - Registration Range Endpoint Corrected

- What existed before: the registration-dialog range and scalar deleting destructor were recorded as ending at `0x00530635`.
- What changed: both endpoints are now `0x00530636`.
- Why: IDA MCP reports `sub_530580` ending at `0x00530636`; the byte at `0x00530635` is part of the destructor return instruction.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Historical 2026-05-28 summary/evidence: the page documented role, function map, support helpers, ownership notes, generated-data caveats, range correction, and cross-references; confidence was then capped by the now-superseded Wave3 materialization omissions/pollution.
