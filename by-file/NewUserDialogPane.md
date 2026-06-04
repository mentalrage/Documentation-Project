*** UID:0000LV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: strong for account-registration behavior, method boundaries, packet flow, lifecycle ownership, and login-family placement; medium for exact standalone split from [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Proposed module: `login/NewUserDialogPane.cpp`, or folded into `login/LoginDialogPane.cpp`.
- Main class: [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)

## File Role

`NewUserDialogPane.cpp` should own the older account-registration dialog. It collects username, password, and password confirmation text, validates password content/match state, shows alert/dimmer feedback for failures, and sends the new-account request.

Do not confuse this with [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md). `NewUserDialogPane2` is a create-character dialog variant in the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) family, while this page is for account registration near [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) and [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane` class | [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md) | Owns the older account-registration dialog object. |
| constructor | `0x004f9d30-0x004fa0a9` | Builds the `DLGNEW01.EPF` dialog, two command controls, three account/password fields, and singleton registration. |
| constructor cleanup fragment | `0x004fa0b0-0x004fa0ef` | Unregistered unwind cleanup code that restores class vtables, closes the active dimmer, clears the singleton, and tail-calls inherited cleanup. |
| packet event adapter | `0x004fa0f0-0x004fa116` | Secondary-interface vtable slot that accepts opcode `2` and forwards to the reply handler. |
| command/default handlers | `0x004fa120-0x004fa1c9` | Submit/close action routing and default-control updates from child ids `1`, `3`, `4`, and `5`. |
| validate/submit path | `0x004fa1d0-0x004fa39c` | Validates digit/match rules, opens alerts, creates the dimmer, and calls the request encoder. |
| request encoder | `0x004fa3a0-0x004fa5a5` | Converts wide fields to bounded multibyte strings, writes opcode `2`, length-prefixes the fields, enforces the local buffer cap, and sends through the packet queue. |
| reply handler | `0x004fa5b0-0x004fa773` | Maps reply codes to alert modes, shows returned messages, or closes the dialog and opens the next account dialog on success. |
| local reply table/padding | `0x004fa773-0x004fa7a0` | Switch/table bytes and `0xcc` padding before the next `LoginDialogPane` constructor. |
| singleton/lifecycle helpers | `0x005023f0`, `0x0050250e`, `0x00502519`, `0x00502970-0x005029e1` | Singleton clear helper, adjusted destructor thunks, and scalar deleting destructor. |

## Boundary Notes

- Keep login submission and server response handling in [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Keep password-change behavior in [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).
- Keep create-character variants in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), and [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).
- Keep this file below final reconstruction status until member names, child-control field names, and the exact source expression for the hidden cleanup fragment are proven at source quality.

## Live IDA Evidence

- Function enumeration on 2026-06-05 confirms the constructor and local helper island at `0x004f9d30`, `0x004fa0f0`, `0x004fa120`, `0x004fa150`, `0x004fa1d0`, `0x004fa3a0`, and `0x004fa5b0`, plus the lifecycle helpers at `0x005023f0`, `0x0050250e`, `0x00502519`, and `0x00502970`.
- `??_7NewUserDialogPane@@6B@`, `??_7NewUserDialogPane@@6B@_0`, and `??_7NewUserDialogPane@@6B@_1` bind the primary command/default handlers, the secondary packet adapter, and the deleting destructor through read-only data slots.
- `dword_69B480` xrefs show constructor setup, hidden-fragment cleanup, explicit clear helper cleanup, and deleting-destructor cleanup for the older account-registration singleton.
- Raw-byte checks keep the memory page split precise: the internal gaps are `0xcc` padding, while `0x004fa773-0x004fa793` is local reply switch/table data before padding to the next constructor.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page documents the account-registration role, constructor/cleanup split, event adapter, command/default handlers, submit path, request encoder, reply handler, local table/padding, lifecycle helpers, exact memory anchor, login-family boundaries, and create-character exclusions. Completion remains capped by unresolved field/control names and the final standalone-vs-folded source split. |
| Confidence `88` | Confidence is supported by [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md), live IDA function enumeration, vtable slot xrefs, singleton xrefs, and raw-byte checks. Confidence is not higher because final source grouping and member names remain open. |

## Cross-References

- [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## Changes

- 2026-06-05: Raised completion/confidence from `80/80` to `86/88` after live IDA MCP evidence confirmed the local method island, hidden cleanup fragment, packet adapter, request/reply helpers, lifecycle helpers, vtable slots, singleton xrefs, and table/padding split. The file stays below final reconstruction quality because the exact standalone/folded source split and member names remain unresolved.
- 2026-06-02: Raised completion/confidence from `74/72` to `80/80` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/login/`. Evidence: exact NewUser core memory page records corrected account-flow boundaries through `0x004fa7a0`, packet sender/reply helpers, and login-family placement.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents account-registration role, key method ranges, boundary exclusions, and cross-references; confidence is limited by the exact split from `LoginDialogPane`.
