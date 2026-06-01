*** UID:0000LV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: strong for account-registration behavior; medium for exact split from [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Proposed module: `login/NewUserDialogPane.cpp`, or folded into `login/LoginDialogPane.cpp`.
- Current recovered source: `source-3/simroot_v2/class_NewUserDialogPane.cpp`
- Main class: [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)

## File Role

`NewUserDialogPane.cpp` should own the older account-registration dialog. It collects username, password, and password confirmation text, validates password content/match state, shows alert/dimmer feedback for failures, and sends the new-account request.

Do not confuse this with [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md). `NewUserDialogPane2` is a create-character dialog variant in the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) family, while this page is for account registration near [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) and [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane` constructor | `0x004f9d30` | Builds the `DLGNEW01.EPF` registration dialog and password fields. |
| `OnButtonAction` | `0x004fa120` | Submit or close action. |
| `ValidateInputFields` | `0x004fa150` | Enables the OK button only when required fields have text. |
| `ValidateAndSubmitNewUser` | `0x004fa1d0` | Validates password rules, shows alerts, creates the dimmer, and sends the request. |
| destructor family | `0x0050250e`, `0x00502519`, `0x00502970` | Adjustor and deleting destructor logic. |

## Boundary Notes

- Keep login submission and server response handling in [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Keep password-change behavior in [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).
- Keep create-character variants in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), and [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).
- Generated source currently contains escaped `\!=` in C++ output; use the behavior docs and IDA-confirmed boundaries before treating the emitted source as compile-ready.

## Cross-References

- [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents account-registration role, key method ranges, boundary exclusions, and cross-references; confidence is limited by the exact split from `LoginDialogPane` and emitted-source syntax caveat.
