*** UID:000036 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Pane;

class ConnectionClosedDialog : public AlertPane,
                               public Singleton<ConnectionClosedDialog>
{
public:
    ConnectionClosedDialog();
    explicit ConnectionClosedDialog(Pane *layoutReference);

protected:
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

private:
    void InitializeConnectionState();
};

typedef char ConnectionClosedDialogSizeMustBe624[
    sizeof(ConnectionClosedDialog) == 0x270 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConnectionClosedDialog

## UID0003ZT Complete-Type Consumer Contract - 2026-07-23

- The complete source-ready declaration in this page is exported through [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)'s documented `NexusTK/network/ReconnectDialog.h` contract.
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) includes ReconnectDialog.h before its ordinary `new ConnectionClosedDialog` expression, then allocates the observed `0x270` bytes and invokes the default constructor.
- This new MapPane consumer does not move class, constructor, callback, vtable, singleton, or global ownership into MapPane.cpp. ReconnectDialog.cpp and its exact children remain the sole implementation route.
- Scores remain `92/94`; the complete formal, AlertPane/Singleton inheritance, EBO endpoint, callback order, RTTI, compiler-only publication/cleanup, and CopyWindow exclusion remain unchanged.

## Status

- Disposition: reconstructable NexusTK project class
- Entity kind: connection-loss alert class
- Likely source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- Address range: [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- Parent attachment: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), with file position `30`. The complete source-facing class declaration is now formal-ready: both constructor overloads, inherited packet/button callbacks, private init helper, direct `AlertPane` plus `Singleton<ConnectionClosedDialog>` inheritance, implicit derived virtual destructor, and `0x270` size guard are resolved. `[[CHILDREN]]` is deliberately outside the class and size-guard declarations so method definitions emit at file scope.
- Rebuild handling: source-authored dialog class; compiler-generated adjustor/scalar deleting destructor wrappers should be regenerated from the source-level class declaration.
- Confidence: very strong for class role, inheritance/layout, source-file grouping, constructor ABIs, method-family ownership, private init helper, inherited callback declarations, implicit-destructor boundary, and reconnect/leave behavior. Helper spelling and the inferred `explicit` token remain bounded source-shape inferences rather than runtime blockers.
- Current recovered file: `source-3/simroot_v2/class_ConnectionClosedDialog.cpp`

## Class Purpose

`ConnectionClosedDialog` is the alert shown when the server connection is lost. It offers reconnect and leave actions, directly inherits `Singleton<ConnectionClosedDialog>`, publishes the process-wide [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md) through compiler-lowered base construction, and constructs `ReconnectDialog` when the reconnect path is selected.

It belongs with [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) in `ReconnectDialog.cpp` rather than a generic alert module because both classes implement the same connection-recovery flow: this class presents the post-disconnect choice, while `ReconnectDialog` owns the active reconnect/cancel/timeout state and can recreate this alert after cancel or timeout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ConnectionClosedDialog()` | [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | No-argument overload: `g_pBackPane` layout, localized id `154`, `Reconnect`/`Leave` labels, compiler-lowered Singleton/facet setup, then private `InitializeConnectionState()`. Plain `retn` and a caller that pushes no argument resolve the ABI. |
| `explicit ConnectionClosedDialog(Pane *layoutReference)` | [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | One-argument overload: forwards the supplied layout reference to the same AlertPane initializer, then performs the same compiler-lowered publication/facet setup and private helper call. `[ebp+arg_0]`, three callers, and `retn 4` resolve the pointer ABI; `explicit` is the most plausible source-facing declaration for this converting constructor. |
| `HandlePacketEvent(Event *)` | [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | EventHandler slot at `0x00622dac`; exact five-byte implementation returns `true` unconditionally. |
| `OnPrimaryButton()` | [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Inherited AlertPane callback that deletes `g_pReconnectDialog` and constructs a new [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) from inherited `m_layoutReference`. The older `OnReconnectClicked` label is a descriptive behavior alias, not the selected source declaration. |
| `OnSecondaryButton()` | [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) | Inherited AlertPane callback that calls `g_pApplication->RequestExit()`. The older `OnLeaveClicked` label is retained only as a behavior alias. |
| `InitializeConnectionState()` | [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) | Private inferred source-facing method called by both out-of-line constructors. The third observed context at `0x005543bb` belongs to a compiler-inlined default-constructor mirror, so it does not violate private access. It checks `g_pActiveTextEditPane`, conditionally constructs `CopyWindow`, posts socket mode byte `1`, drains the queue, and optionally dims through `g_pScreenDimmer`. |
| Destructor family | [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md) | EH-only `Singleton<ConnectionClosedDialog>` base-destructor support, two class adjustors, and the scalar deleting wrapper. Keep the compiler bytes non-emitting and regenerate them from the complete class declaration. |

## Direct Singleton Inheritance And Layout Evidence

- Best source shape: `ConnectionClosedDialog : public AlertPane, public Singleton<ConnectionClosedDialog>`.
- The primary class hierarchy contains nine RTTI entries and multiple-inheritance attribute `1`.
- Singleton BCD `0x0064e9d8` names `Singleton<ConnectionClosedDialog>` and uses PMD `mdisp=0x270`, `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- Constructor/factory allocations are `0x270` / 624 bytes (Verified with `int_convert.py`). The empty Singleton base lies at the complete-object endpoint and contributes no ordinary data field.
- Constructor code derives `this+0x270`, tests the adjusted pointer, subtracts `0x270`, and stores the complete object into exact storage [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md). That pattern is compiler lowering of direct base construction, not a handwritten assignment.
- Ordinary destruction, constructor unwind through `0x00554550`, and scalar wrapper clear at `0x005545a6` are the matching compiler-lowered Singleton base destruction paths.
- The sole human source definition is [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md), emitted through ReconnectDialog.cpp. Application heartbeat is an external read-only consumer and does not own the class or global.

## Source And Compiler Boundary

- Preserve the direct `AlertPane` plus `Singleton<ConnectionClosedDialog>` inheritance in the eventual complete class declaration.
- Do not add explicit `g_pConnectionClosedDialog = this` or clear assignments, explicit base destructor calls, EH helpers, vptr stores, vtables/RTTI arrays, adjustor bodies, scalar flags, or delete-wrapper code.
- The complete declaration now includes the no-argument and `Pane *` constructor overloads, protected `HandlePacketEvent`, primary/secondary inherited callbacks, and private `InitializeConnectionState`. The `Event`/`Pane` forward declarations and `0x270` compile-time size guard make the accepted class shape explicit without inventing duplicate fields already inherited from `AlertPane`.
- Do not declare an explicit derived destructor. The virtual destructor inherited through the base hierarchy causes the implicit derived virtual destructor and lets MSVC regenerate the observed complete/adjusted/scalar deleting wrappers. The absence of a handwritten derived destructor body is a source-quality decision, not missing code.
- The primary table represents the complete/AlertPane facet; adjusted views at `+0xa0` and `+0xa4` are the inherited EventHandler and TimerHandler facets. These are base-layout consequences, not new user-declared data members.

## Evidence Notes

- IDA confirms the three local methods and destructor starts.
- IDA callers on 2026-05-25 show `0x00553e60` is called by both constructor forms and by `ReconnectDialog::OnButtonClick` after inline replacement construction.
- 2026-07-04 B013 MCP session `nexustk_supervisor_20260704` reports `0x00553e60-0x00553f36` as size `0xd6` / 214 bytes with caller xrefs `0x00553ca8`, `0x00553d55`, and `0x005543bb`. The helper body is now represented on the exact child page as inferred `ConnectionClosedDialog::InitializeConnectionState()`; exact original spelling remains confidence-capped because no source symbol proves it.
- `ReconnectDialog::OnReconnectTimeout` and cancel paths recreate this dialog after failed reconnect/cancel flows.
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) already records the stronger `network/ReconnectDialog.cpp` placement decision, including packet/reconnect ownership and the `0x00553c10-0x00554635` range correction.
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) records the aggregate method neighborhood, the earlier constructor variant at `0x00553c10`, the corrected final endpoint at `0x00554635`, and the interleaved `CopyWindow` caveat.
- The `CopyWindow` constructor/callback island at [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) is a side path created by the shared helper; it should not be migrated as owned `ConnectionClosedDialog` source even though it is physically nearby.
- 2026-06-11 live IDA MCP Batch178 refresh decompiled the alternate constructor/handler child [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md): `0x00553cc0` contains the compiler-inlined Singleton publication to exact storage UID0004SQ, installs the `ConnectionClosedDialog` vtables, initializes alert text id `154`, and calls the shared helper; `0x00553d80` deletes any existing reconnect dialog, constructs `ReconnectDialog`, and calls reconnect initiation; `0x00553e50` requests application exit. The same refresh links compiler destructor support through [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md).
- 2026-06-16 A001 live source-quality refresh repaired [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) from direct file ownership to this class. IDA confirms the constructor's only caller is `0x00508ffc` inside [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md), but the constructed object and vtable stores are still `ConnectionClosedDialog`; the MapPane caller is runtime reachability, not semantic ownership.
- 2026-07-22 B001 UID00023O callback evidence resolves the complete declaration: target `0x00553c10` has no explicit argument and plain `retn`; sibling `0x00553cc0` consumes a `Pane *` and uses `retn 4`; EventHandler `+0x10` maps to the exact true-return callback; the primary tail slots map to inherited primary/secondary callbacks; all constructor/mirror contexts share localized id `154`, Reconnect/Leave labels, compiler-lowered Singleton publication, three inherited facets, and the private helper.

## Reconstruction Notes

- Recreate this class as part of `ReconnectDialog.cpp`/`.h` with direct `AlertPane` and `Singleton<ConnectionClosedDialog>` inheritance. The external singleton definitions remain separate by-global source items.
- Preserve [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) as the position-`30` exact helper child; do not duplicate its body on this class page. The `0x005543bb` context is an inlined constructor mirror rather than an externally callable private method use.
- Emit the class at file position `30`; place `[[CHILDREN]]` after the closing class and size guard. Child order is default constructor `10`, alternate constructor/callback cluster `20`, init helper `30`, and compiler-regenerated vtable marker `40`.
- Keep the `CopyWindow` class island outside this class even though `InitializeConnectionState()` may construct it. Dependency does not imply source ownership.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The class page now records and emits the complete source-facing declaration: both constructor overloads, direct inheritance, protected packet/button callbacks, private init helper, implicit destructor decision, `0x270` size guard, ordered children, exact facet roles, compiler boundary, singleton/global route, and CopyWindow exclusion. |
| Confidence `94` | RTTI, allocation size, constructor ABIs, adjustment/store sequence, vtable slots, EH/scalar clears, exact global/storage pages, helper body/callers, and file route independently agree. Exact historical `InitializeConnectionState` spelling and the inferred `explicit` token are the remaining bounded lexical caps. |

## Historical / Superseded Assumptions

- The prior `88/92` blank formal was a valid no-incomplete-shell safeguard while signatures, callback slots, helper access, and destructor disposition were unresolved. The accepted UID00023O reanalysis resolves those dependencies, so retaining a blank class now would create empty-emitter debt.
- `OnReconnectClicked` and `OnLeaveClicked` remain useful behavior aliases from earlier documentation. The selected source declarations are the inherited `OnPrimaryButton()` and `OnSecondaryButton()` slots.
- The third helper context was previously described as a direct `ReconnectDialog::OnButtonClick` call after replacement construction. Current byte/caller comparison identifies it more precisely as a compiler-inlined default-constructor mirror containing the private helper call.

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md)
- [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0004SO][g_pConnectionClosedDialog](by-global/g_pConnectionClosedDialog.md)
- [UID:0004SQ][0x0067ab54-0x0067ab58.g_pConnectionClosedDialog](by-memory/0x0067ab54-0x0067ab58.g_pConnectionClosedDialog.md)

## Changes

- 2026-07-22 B001 accepted UID00023O implementation callback:
  - Raised `88/92 -> 92/94`, retained owner/emitter UID0000N0 and reconstructable true, and assigned file position `30`.
  - Added the complete class formal with both constructor declarations, direct AlertPane/Singleton inheritance, protected packet/primary/secondary callbacks, private `InitializeConnectionState()`, no explicit derived destructor, `0x270` size guard, and `[[CHILDREN]]` outside the class.
  - Added exact overload ABI, inherited-facet/vtable, callback-slot, helper-private-access, source/compiler boundary, and ordered-child evidence while preserving Singleton, global/storage, CopyWindow, source-file, and historical evidence.

- 2026-07-16 B003 UID0002VT implementation callback:
  - Raised `86/88 -> 88/92`, preserving owner/emitter UID0000N0, reconstructable true, blank position/formal, all method/helper links, and unrelated class evidence.
  - Added exact direct `AlertPane, Singleton<ConnectionClosedDialog>` source inheritance, nine-entry RTTI, PMD `+0x270`, `0x270` allocation/EBO endpoint, typed global UID0004SO, exact storage UID0004SQ, implicit publication/cleanup, external-linkage route, compiler exclusions, and complete-class no-incomplete-shell proof.
  - Historical direct global-assignment and clear-helper descriptions are superseded by the direct Singleton base source cause while their exact binary sites remain documented.
- 2026-05-28:
  - Before: only the `0x00553cc0` constructor path was called out in the class summary.
  - After: added the `0x00553c10` constructor variant and linked the corrected aggregate `0x00553c10-0x00554635`.
  - Evidence: IDA MCP confirms `0x00553c10-0x00553cbf` installs `ConnectionClosedDialog` vtables and is called from `0x00508ffc`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/86`.
  - Summary/evidence: constructor variants, reconnect/leave handlers, init helper, destructor family, caller notes, and related reconnect classes are documented; remaining work is fuller helper-body reconstruction and exact original member names.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` was left blank at that time because the class completion score was below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x00553c10`, `0x00553cc0`, `0x00553d80`, `0x00553e50`, `0x00553e60`, and `0x005545a0`, with constructor/init callers from connection and reconnect paths; existing project docs place the class in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md).
- 2026-06-06 A007 class attachment pass:
  - Before: score `76/86`, reconstructable but unassigned because completion was below the parent-attach gate.
  - Changed to: `COMPLETION:80`, parent [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), expanded class/source-placement notes, reconstruction caveats, and score rationale.
  - Summary/evidence: the file, class, aggregate, and helper pages already document the constructor variants, reconnect/leave handlers, `0x00553e60` shared init helper, destructor family, connection/reconnect ownership, and interleaved `CopyWindow` caveat. Final C++ remains blank pending a final class declaration/member audit.
- 2026-06-11 A002 Batch178 split refresh:
  - Changed completion/confidence from `80/86` to `86/88`.
  - Added exact method child [UID:00038J][0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods](by-memory/0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods.md) and cleanup/destructor child [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md).
  - Evidence: live IDA MCP decompilation confirms singleton publication/clearing, constructor vtable installation, reconnect and leave handlers, and the destructor wrapper family; parent [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) now clears the strict 85/85 gate.
- 2026-06-16 A001 target-route refresh:
  - Score unchanged at `86/88`.
  - Linked [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) explicitly as the default/no-parent constructor variant and recorded that its direct owner/emitter is this class, not the file root.
  - Evidence: live IDA MCP confirms the target's exact range, single MapPane caller, singleton publication, and three `ConnectionClosedDialog` vtable writes; the class already clears the direct-parent gate and routes to [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md).
- 2026-07-04 B013 helper implementation callback:
  - Added formal-ready method notes for [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md), including the two constructor callers, the `ReconnectDialog::OnButtonClick` replacement-dialog caller, dependency names, and inferred-name confidence cap.
  - Evidence: MCP session `nexustk_supervisor_20260704` confirms exact range `0x00553e60-0x00553f36`, size `0xd6` / 214, conditional CopyWindow construction, `g_packetSender->PostSocketModeByteCommand(1)`, inherited queue drain, optional screen-dimmer call, and stale debug-symbol rejection.
