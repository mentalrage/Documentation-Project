*** UID:000036 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConnectionClosedDialog

## Status

- Confidence: strong
- Likely source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- Address range: [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ConnectionClosedDialog.cpp`

## Class Purpose

`ConnectionClosedDialog` is the alert shown when the server connection is lost. It offers reconnect and leave actions, owns the connection-closed singleton pointer, and constructs `ReconnectDialog` when the reconnect path is selected.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ConnectionClosedDialog` | `0x00553c10`, `0x00553cc0` | Constructor variants that build reconnect/leave alert state and initialize connection/focus state. |
| `OnReconnectClicked` | `0x00553d80` | Destroys existing reconnect dialog and starts a new reconnect flow. |
| `OnLeaveClicked` | `0x00553e50` | Requests application exit. |
| init/focus helper | `0x00553e60` | Shared post-construction helper; refreshes modal/focus state and conditionally creates a `CopyWindow` side dialog for active text edit state. |
| Destructor family | `0x0055456b`, `0x00554576`, `0x005545a0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms the three local methods and destructor starts.
- IDA callers on 2026-05-25 show `0x00553e60` is called by both constructor forms and by `ReconnectDialog::OnButtonClick` after inline replacement construction.
- 2026-05-26 IDA MCP recheck reports `0x00553e60` still has size `0xd6` and the same three callers. Current `simroot_v2` only names the call `InitializeConnectionState()` in `class_ConnectionClosedDialog.cpp`; the active file still lacks the helper body.
- `ReconnectDialog::OnReconnectTimeout` and cancel paths recreate this dialog after failed reconnect/cancel flows.

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)

## Changes

- 2026-05-28:
  - Before: only the `0x00553cc0` constructor path was called out in the class summary.
  - After: added the `0x00553c10` constructor variant and linked the corrected aggregate `0x00553c10-0x00554635`.
  - Evidence: IDA MCP confirms `0x00553c10-0x00553cbf` installs `ConnectionClosedDialog` vtables and is called from `0x00508ffc`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/86`.
  - Summary/evidence: constructor variants, reconnect/leave handlers, init helper, destructor family, caller notes, and related reconnect classes are documented; remaining work is fuller helper-body reconstruction and exact original member names.
