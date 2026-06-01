*** UID:00003B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: strong for behavior; medium for current emitted-body completeness.
- Likely source file: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Current recovered file: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`

## Class Purpose

`CreateUserDialogPane` is a full-screen create-user dialog. It builds the `DLGNEW3` account/character setup UI, randomizes initial body/hair/face state, drives gender/body selection, updates the preview, validates password fields, and sends the create-user request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateUserDialogPane` | `0x0052dd30` | Builds `DLGNEW3` dialog, text edits, gender/body buttons, hair/face selectors, color lists, and preview. |
| `SelectBodyShape` | `0x0052e770` | Updates selected body shape and description text. |
| `SelectMale` / `SelectFemale` | `0x0052e850`, `0x0052e8c0` | Toggles gender state and resets selectors. |
| `SetHairColorIndex` / `SetFaceColorIndex` | `0x0052e930`, `0x0052e950` | Listed by Wave3, but missing from the current emitted file. |
| `OnDialogAction` | `0x0052ea80` | Handles gender, body, scroll, submit, cancel, and preview-direction commands. |
| `OnKeyEvent` / `OnDialogShow` | `0x0052ecc0`, `0x0052ed00` | Listed by Wave3, but missing from the current emitted file. |
| `SubmitCreateUser` | `0x0052ed80` | Validates password digit/match rules, shows alerts, and sends create-account request. |
| `ScalarDeletingDestructor` | `0x0052f800` | Clears singleton and destroys dialog state. |

## Evidence Notes

- IDA confirms the constructor and submit method starts.
- Wave3 class inspection lists 13 methods, but the generated file currently omits several listed methods. This is recorded as a Wave3 data/materialization issue.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md)
- [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md)
- [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md)
- [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md)
- [UID:0000FK][UserHairColorSelectListPane](by-class/UserHairColorSelectListPane.md)
- [UID:0000FI][UserFaceColorSelectListPane](by-class/UserFaceColorSelectListPane.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/78`.
  - Summary/evidence: major UI responsibility, constructor/action/submit/destructor roles, companion appearance controls, and missing emitted-method caveat are documented; remaining work is detailed body reconstruction and resolving Wave3 materialization gaps.
