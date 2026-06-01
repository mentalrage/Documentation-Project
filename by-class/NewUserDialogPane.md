*** UID:00009D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: medium
- Likely source file: [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md), with [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) as the broader account/login family
- Address range: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewUserDialogPane.cpp`

## Class Purpose

`NewUserDialogPane` is the older account-registration dialog. It collects username, password, and confirmation text, validates that the password contains a digit and matches confirmation, shows alerts for validation failures, and sends a new-user request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserDialogPane` | `0x004f9d30` | Builds `DLGNEW01.EPF` registration dialog and password fields. |
| `OnButtonAction` | `0x004fa120` | Submit or close action. |
| `ValidateInputFields` | `0x004fa150` | Enables the OK button only when required fields have text. |
| `ValidateAndSubmitNewUser` | `0x004fa1d0` | Validates password rules, shows alerts, creates screen dimmer, and sends request. |
| Destructor family | `0x0050250e`, `0x00502519`, `0x00502970` | Adjustor and deleting destructor family. |

## Evidence Notes

- IDA confirms the four local methods and destructor thunks.
- Generated source currently contains escaped `\!=` in C++ output. Treat the behavior summary as useful, but not the file as compile-ready.

## Cross-References

- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite basic method, validation, and file/memory ownership notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:64`.
- Evidence: the page covers purpose, local method roles, destructor family, and validation behavior; confidence stays medium because the generated source has known escaped-output damage and the page lacks detailed layout/state-field documentation.
