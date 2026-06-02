*** UID:0000OY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# UserInfoDialogPane

## Status

- Confidence: strong for class behavior and boundaries, medium for exact launch path.
- Proposed module: `login/UserInfoDialogPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_UserInfoDialogPane.cpp`
- Main class: [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md)
- Main address doc: [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- Support thunk doc: [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), tracked in [UID:0000VN][-ignored](by-memory/-ignored.md)

## File Role

`UserInfoDialogPane.cpp` owns a Korean account/user-information form dialog. The constructor decodes packet-provided fields into read-only text controls, fills optional choice controls, validates the final user-entered selections, and sends packet `0x53` subtype `1` with the completed form data.

This should stay near login/account UI code rather than generic in-game dialogs. The form handles account identity fields, resident-registration-number checksum validation, parent-name validation, and demographic/preference selections.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserInfoDialogPane` | `0x00599cc0-0x0059bc8b`, thunks [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md) | Dialog construction, focus/input forwarding, validation, packet send, close/cancel handling, and destructor thunks. |
| `g_alertPaneButtonLayout` dependency | generated global in `class_UserInfoDialogPane.cpp` | Alert button layout consumed when validation fails; not owned by this file. |

## Evidence Notes

- IDA MCP confirms real functions at `0x00599cc0`, `0x0059b000`, `0x0059b0f0`, `0x0059b110`, `0x0059b130`, `0x0059b150`, `0x0059b260`, `0x0059b5c0`, `0x0059bc2d`, `0x0059bc38`, and `0x0059bc50`.
- IDA confirms the next large function starts at `0x0059bc90`, which belongs to the existing [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) range, so the user-info dialog boundary ends at `0x0059bc8b`.
- `xrefs_to 0x00599cc0` currently reports no direct code xrefs in IDA. Treat construction as likely indirect through a packet/dialog factory path until a caller is recovered.
- 2026-06-02 raw IDA export and IDA MCP recheck agree on exact function sizes: constructor `0x1330`, command handler `0xed`, input/key forwarders `0x20` each, focus handler `0x1a`, OK-state updater `0x103`, validation helper `0x354`, packet sender `0x66c`, two `0xb` adjustor thunks, and scalar deleting destructor `0x3b`.
- 2026-06-02 byte checks confirm `0xcc` alignment around the executable island, including the preceding `0x00599cb3-0x00599cc0` and following `0x0059bc8b-0x0059bc90` gaps already tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), plus intra-island alignment between the methods.
- [UID:00026T][0x0062e624-0x0062e960.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e960.UserInfoReadOnlyData.md) documents the matching `UserInfoDialogPane` vtables, title string, resource names, and label string island.

## Ownership Notes

- Use `login/UserInfoDialogPane.cpp` as the current source-layout hypothesis.
- Do not merge this with [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) just because the next address block is adjacent; the behavior and controls are account-form specific.
- Disabled generated output omits code for the real `0x0059bc2d` adjustor thunk. The thunk exists in IDA, is documented at [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), and is excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA MCP recheck confirms `0x0059bc2d` and `0x0059bc38` as `this - 0xa0` / `this - 0xa4` destructor wrappers into `0x0059bc50`. Keep the scalar deleting destructor reconstructable.
- The file-level parent is now above the `80%` confidence attachment threshold. The executable range can attach to this file for autogen ownership, but no final C++ should be emitted until method names, field offsets, helper names, packet field names, and resource/string meanings reach final-source quality.

## Cross-References

- [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md)
- [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md)
- [UID:00026T][0x0062e624-0x0062e960.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e960.UserInfoReadOnlyData.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/78`. Summary/evidence: the page captures the account/user-info source role, likely contents, IDA-backed field/widget/resource evidence, boundaries, and unresolved launch-path caveat.
- 2026-06-02 source-placement and scoring update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page stayed at `84/78`, below the file-parent attachment confidence threshold.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, `COMPLETION:86`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP/raw export rechecked exact function sizes, vtable refs, alignment bytes, adjacent boundaries, and matching read-only data, while preserving the unresolved indirect launch-path caveat.
