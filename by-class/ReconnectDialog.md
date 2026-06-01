*** UID:0000BR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ReconnectDialog

## Status

- Confidence: strong
- Likely source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- Address range: [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ReconnectDialog.cpp`

## Class Purpose

`ReconnectDialog` is the active reconnect-in-progress alert. It sends reconnect requests, handles cancel/reconnect button actions, performs network cleanup, and falls back to `ConnectionClosedDialog` on timeout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ReconnectDialog` | `0x00553f40`, `0x00553ff0` | Constructors for default/parent-pane alert setup. |
| `InitiateReconnect` | `0x005540a0` | Marks reconnecting state, sends connect request, and starts timeout timer. |
| `OnButtonClick` | `0x00554210` | Handles cancel and reconnect actions with packet cleanup/send behavior. |
| `OnReconnectTimeout` | `0x00554410` | Cancels reconnect, disconnects, and recreates connection-closed dialog. |
| Destructor family | `0x00554581`, `0x0055458c`, `0x005545f0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms all local method starts.
- Behavior couples directly to packet sender state, `g_pConfig` saved server address/port, and reconnect globals.
- IDA decompilation of `OnButtonClick` shows the cancel path can construct a replacement `ConnectionClosedDialog` inline and then call the helper at `0x00553e60`.
- IDA MCP callers on 2026-05-25 show `OnButtonClick` calls [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), the queued 8-byte position/status upload helper in the request-sender cluster.
- 2026-05-26 IDA MCP recheck reconfirmed `0x005543bb` inside `OnButtonClick` as one of the three callers to the `0x00553e60` post-construction helper.

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0000NS][Socket](by-file/Socket.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page contained method roles, memory cross-references, caller/callee notes, and reconnect state evidence.
  - After: changed completion/confidence to `82/86`.
  - Evidence: existing method notes, IDA evidence notes, `ConnectionClosedDialog` relationship, packet sender dependency, and aggregate memory range cross-references support high-confidence class documentation.

- 2026-05-28:
  - Before: the class page only linked helper-level reconnect ranges.
  - After: added the corrected aggregate `0x00553c10-0x00554635` so the earlier `ConnectionClosedDialog` constructor variant is visible from the reconnect class family.
  - Evidence: IDA MCP confirms the aggregate now starts at `0x00553c10` and includes the constructor variant preceding the previously documented reconnect/connection-closed methods.
