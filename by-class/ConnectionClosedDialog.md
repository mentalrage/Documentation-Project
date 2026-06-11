*** UID:000036 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConnectionClosedDialog

## Status

- Disposition: reconstructable NexusTK project class
- Entity kind: connection-loss alert class
- Likely source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- Address range: [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- Parent attachment: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md). This class is now `80/86` and the source-file parent is `84/80`, satisfying the 80/80 attachment gate. Final C++ remains blank because constructor signatures, member names, and destructor-family details are not at final-source confidence.
- Rebuild handling: source-authored dialog class; compiler-generated adjustor/scalar deleting destructor wrappers should be regenerated from the source-level class declaration.
- Confidence: strong for class role, source-file grouping, method-family ownership, shared init helper, and reconnect/leave behavior; lower for final source spelling and exact member names.
- Current recovered file: `source-3/simroot_v2/class_ConnectionClosedDialog.cpp`

## Class Purpose

`ConnectionClosedDialog` is the alert shown when the server connection is lost. It offers reconnect and leave actions, owns the connection-closed singleton pointer, and constructs `ReconnectDialog` when the reconnect path is selected.

It belongs with [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) in `ReconnectDialog.cpp` rather than a generic alert module because both classes implement the same connection-recovery flow: this class presents the post-disconnect choice, while `ReconnectDialog` owns the active reconnect/cancel/timeout state and can recreate this alert after cancel or timeout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ConnectionClosedDialog` | `0x00553c10`, `0x00553cc0` | Constructor variants that build reconnect/leave alert state, publish the connection-closed singleton, install the class vtables, and call the shared post-construction helper. |
| `OnReconnectClicked` | `0x00553d80` | Destroys/replaces reconnect dialog state and starts a new [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md) reconnect flow. |
| `OnLeaveClicked` | `0x00553e50` | Requests the application exit/leave path after connection loss. |
| init/focus helper | [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) | Shared post-construction helper; refreshes modal/focus state and conditionally creates a `CopyWindow` side dialog for active text edit state. |
| Destructor family | `0x0055456b`, `0x00554576`, `0x005545a0` | Adjustor and scalar deleting destructor logic for the alert class; keep wrapper bytes in by-memory and regenerate them from the final class declaration. |

## Evidence Notes

- IDA confirms the three local methods and destructor starts.
- IDA callers on 2026-05-25 show `0x00553e60` is called by both constructor forms and by `ReconnectDialog::OnButtonClick` after inline replacement construction.
- 2026-05-26 IDA MCP recheck reports `0x00553e60` still has size `0xd6` and the same three callers. Current `simroot_v2` only names the call `InitializeConnectionState()` in `class_ConnectionClosedDialog.cpp`; the active file still lacks the helper body.
- `ReconnectDialog::OnReconnectTimeout` and cancel paths recreate this dialog after failed reconnect/cancel flows.
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) already records the stronger `network/ReconnectDialog.cpp` placement decision, including packet/reconnect ownership and the `0x00553c10-0x00554635` range correction.
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) records the aggregate method neighborhood, the earlier constructor variant at `0x00553c10`, the corrected final endpoint at `0x00554635`, and the interleaved `CopyWindow` caveat.
- The `CopyWindow` constructor/callback island at [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) is a side path created by the shared helper; it should not be migrated as owned `ConnectionClosedDialog` source even though it is physically nearby.

## Reconstruction Notes

- Recreate this class as part of `ReconnectDialog.cpp`/`.h` with the active reconnect alert class and the two singleton pointers.
- Preserve the helper/body split until the final source pass decides whether the `0x00553e60` behavior was an out-of-line private helper, a shared initializer, or compiler-shaped extracted code.
- Do not place final class C++ in this page yet. Completion is sufficient for parent attachment, but original constructor signatures, vtable declaration shape, destructor wrapper mapping, and member/global names still need a final audit.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `80` | The class page now records source-file attachment, constructor variants, reconnect/leave handlers, shared init helper, destructor family, singleton/reconnect relationship, CopyWindow side-path caveat, and final-C++ gate. Remaining work is full field/member naming and final class declaration shape. |
| Confidence `86` | Confidence stays strong because the class role and source placement are supported by the file page, aggregate by-memory page, helper page, and reconnect class page. It remains below final confidence because exact original method names and destructor wrapper mapping still need audit. |

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)

## Changes

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
