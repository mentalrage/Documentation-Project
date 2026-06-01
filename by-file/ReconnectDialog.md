*** UID:0000N0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ReconnectDialog

## Status

- Confidence: strong for `ReconnectDialog` and `ConnectionClosedDialog` grouping.
- Proposed module folder: `network/` or `login/`
- Proposed source file: `network/ReconnectDialog.cpp`
- Current generated sources: `class_ReconnectDialog.cpp`, `class_ConnectionClosedDialog.cpp`
- Evidence basis: Wave3 class inspection, generated source, and IDA MCP boundary checks on 2026-05-23.

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
| `ConnectionClosedDialog` | `0x00553c10`, `0x00553cc0-0x00553f36`, destructor family at `0x0055456b+` | `class_ConnectionClosedDialog.cpp` | Shows reconnect/leave alert after connection loss and runs post-construction modal/focus init. |
| `ReconnectDialog` | `0x00553f40-0x005544b7`, destructor family at `0x00554581+` and `0x005545f0` | `class_ReconnectDialog.cpp` | Shows cancel alert while reconnecting, sends reconnect/cancel/disconnect packet sequence, handles timeout. |
| `g_pConnectionClosedDialog` | global-data | multiple emitted files | Singleton pointer for the connection-closed alert. |
| `g_pReconnectDialog` | global-data | multiple emitted files | Singleton pointer for the active reconnect alert. |

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

## Cross-References

- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
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
