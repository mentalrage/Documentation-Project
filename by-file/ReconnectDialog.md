*** UID:0000N0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ReconnectDialog

## Status

- Disposition: reconstructable source-file root.
- Confidence: strong for `ReconnectDialog` and `ConnectionClosedDialog` grouping; medium-high for final original folder choice because `network/` is the active reconstruction path while `login/` remains a plausible historical alternative.
- Proposed module folder: `network/`
- Proposed source file: `network/ReconnectDialog.cpp`
- Current generated sources: `class_ReconnectDialog.cpp`, `class_ConnectionClosedDialog.cpp`
- Current generated source names are retained only as search leads. Current ownership is based on existing IDA-backed by-memory/by-class/by-global documentation, especially [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md), [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md), and the attached class pages.

## Hypothesis

`ReconnectDialog` and `ConnectionClosedDialog` are network-session UI alerts. They should be kept together because both are thin `AlertPane` specializations over the same reconnect/leave/cancel flow and share singleton globals such as `g_pReconnectDialog` and `g_pConnectionClosedDialog`.

The likely source placement is near networking/session recovery rather than generic alert UI:

```text
network/ReconnectDialog.cpp
network/ReconnectDialog.h
```

If the original tree grouped all login-screen UI together, `login/ReconnectDialog.cpp` is also plausible, but the packet send/disconnect/reconnect behavior makes `network/` the stronger current hypothesis.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md) | `0x00553c10`, `0x00553cc0-0x00553f36`, destructor family at `0x0055456b+` | `class_ConnectionClosedDialog.cpp` search lead | Shows reconnect/leave alert after connection loss and runs post-construction modal/focus init. The class now attaches to this source root. |
| [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) | `0x00553f40-0x005544b7`, destructor family at `0x00554581+` and `0x005545f0` | `class_ReconnectDialog.cpp` search lead | Shows cancel alert while reconnecting, sends reconnect/cancel/disconnect packet sequence, handles timeout. The class now attaches to this source root. |
| `g_pConnectionClosedDialog` | [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) | exact global-data child | Singleton pointer for the connection-closed alert; the split child is attached to this file. |
| `g_pReconnectDialog` | [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) | exact global-data child | Singleton pointer for the active reconnect alert; the split child is attached to this file. |

## Current Exact Children

| UID | Range / page | Current handling |
| --- | --- | --- |
| [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) | Exact constructor variant | Attached to this file at position `10`; final C++ blank pending constructor signature and overload audit. |
| [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) | Shared post-construction helper | Attached to this file at position `40`; final C++ blank because the helper name/source extraction remains open. |
| [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) | Broader method-neighborhood aggregate | Kept unassigned as a research map because it includes a separate [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) island and still needs exact child splits. |
| [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) | Interleaved CopyWindow constructor/callback island | Belongs to [UID:0000IH][CopyWindow](by-file/CopyWindow.md), not this file, despite physical adjacency. |

## Key Behavior

- `ConnectionClosedDialog::OnReconnectClicked` destroys an existing reconnect dialog, constructs `ReconnectDialog`, and starts the reconnect attempt.
- `ConnectionClosedDialog::OnLeaveClicked` calls the shared application exit path.
- `ConnectionClosedDialog` construction paths call the helper at `0x00553e60`, which refreshes modal/focus state and may create a `CopyWindow` side dialog if an active text edit pane has eligible state.
- `ReconnectDialog::InitiateReconnect` marks reconnecting state, sends a connect request using the saved server address/port, and arms a 10 second timer.
- `ReconnectDialog::OnButtonClick` handles cancel/reconnect branches, closes related UI panes, sends packet cleanup/reconnect messages, and calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md) on the confirmed IDA caller path.
- `ReconnectDialog::OnReconnectTimeout` cancels reconnect, disconnects, and recreates the connection-closed dialog.

## Boundary Notes

- The broader `0x00553c10-0x00554635` address neighborhood includes the `CopyWindow` constructor/callback island at `0x005544c0-0x0055454b`. Keep that island with [UID:0000IH][CopyWindow](by-file/CopyWindow.md) for source migration even though it is physically interleaved with reconnect code.
- The stale IDA symbol on `0x00553e60` should not be used as naming evidence.
- 2026-05-26 recheck: current `simroot_v2/class_ConnectionClosedDialog.cpp` calls `InitializeConnectionState()` for the `0x00553e60` helper but does not emit the helper body in the active file. Keep the exact body tracked by [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md).
- 2026-06-06 A007 update: [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) is now attached to this file, while [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) remains unassigned until the remaining internal spans are split.

## Remaining File-Level Work

- Split or create exact by-memory pages for the unsplit `ConnectionClosedDialog` alternate constructor/handlers at `0x00553cc0-0x00553e5b`, the `ReconnectDialog` constructors/handlers at `0x00553f40-0x005544b8`, and the destructor/thunk region at `0x0055454b-0x00554635`.
- Audit whether the final original source used a standalone private helper for `0x00553e60` or whether the generated `InitializeConnectionState()` name is only a call-site convenience.
- Continue method-body splits for the unsplit constructor/handler/destructor ranges; the `g_pConnectionClosedDialog` and `g_pReconnectDialog` storage is now split as [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md).
- Keep final generated C++ blank on child pages until method signatures, field/global names, and destructor wrapper mapping are near final-source confidence.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The file page now records the active reconstruction path, attached classes, attached exact constructor/helper children, mixed aggregate handling, singleton global-data support, CopyWindow exclusion, and concrete remaining split targets. |
| Confidence `86` | Confidence is stronger after the class, constructor, helper, and exact singleton-storage attachments. It remains below final audit level because the `network/` versus historical `login/` source-folder question, unsplit internal method ranges, and final class/header declaration audit remain open. |

## Cross-References

- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md)
- [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:00029B][0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals](by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)

## Changes

- 2026-05-28:
  - Before: the connection/reconnect neighborhood was cited as `0x00553cc0-0x00554634`.
  - After: corrected it to `0x00553c10-0x00554635` and kept the interleaved `CopyWindow` ownership note unchanged.
  - Evidence: IDA MCP confirms an earlier `ConnectionClosedDialog` constructor variant at `0x00553c10-0x00553cbf` and the final byte of the trailing destructor/helper range at `0x00554634`.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Summary/evidence: the page documents reconnect/closed dialog grouping, key behavior, boundaries, IDA evidence, range correction, globals, and cross-references; confidence is strong but still capped by final `network/` versus `login/` source placement.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/network/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` places `ReconnectDialog.cpp` under `network/`, and the refreshed IDA MCP pass on the `0x00553e60` helper confirms the flow is connection/reconnect session UI with a conditional `CopyWindow` side path rather than generic alert or copy-window ownership.
- 2026-06-06 A007 file-owner refresh:
  - Before: score `84/80`, with high-level generated-source and IDA boundary evidence plus broad proposed contents.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:82`, direct references to attached `ConnectionClosedDialog`, `ReconnectDialog`, constructor variant, init helper, mixed aggregate, CopyWindow exception, singleton global-data support, and remaining split targets.
  - Summary/evidence: the exact constructor variant now attaches to this source root, `ConnectionClosedDialog` and `ReconnectDialog` class pages are parented here, and the aggregate page now documents why its mixed CopyWindow island keeps the aggregate unassigned. Final C++ remains deferred pending exact child splits and class/header audit.
- 2026-06-07 A006 singleton split refresh:
  - Before: score `86/82`, and dialog singleton storage still pointed at the mixed `0x0067ab54-0x0067ab84` aggregate.
  - Changed to: confidence `86`, with exact singleton-storage child [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md) attached to this file.
  - Summary/evidence: live IDA-backed split evidence confirms `g_pConnectionClosedDialog` and `g_pReconnectDialog` are published and cleared by the reconnect-dialog method family, while application timing code only reads them as heartbeat gates.
