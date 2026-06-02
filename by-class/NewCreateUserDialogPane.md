*** UID:00008Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewCreateUserDialogPane

## Status

- Confidence: strong
- Likely source file: [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Current recovered file: `source-3/simroot_v2/class_NewCreateUserDialogPane.cpp`

## Class Purpose

`NewCreateUserDialogPane` is a newer full-screen create-user dialog variant. It uses `DLGNEW.EPF`, `GENDER.EPF`, `DIREC.EPF`, and `NEWBUTT.PAL`, with username/password fields, gender and totem selection, body-shape preview, and submit validation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewCreateUserDialogPane` | `0x0052c360` | Builds the newer full-screen create-user dialog and child controls. |
| `SelectGender` / `SelectTotem` | `0x0052cef0`, `0x0052cf80` | Updates selection buttons and state. |
| `SelectMale` / `SelectFemale` | `0x0052d060`, `0x0052d0b0` | Gender-specific selection setup. |
| `OnCommand` | `0x0052d210` | Dialog command dispatcher. |
| `OnDialogEvent` / `OnDialogNotify` | `0x0052d2f0`, `0x0052d330` | Dialog event/notification stubs or simple handlers. |
| `SubmitCreateUser` | `0x0052d3e0` | Validates and sends create-user request. |
| Destructor family | `0x0052f751`, `0x0052f75c`, `0x0052f870` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms the constructor, submit, adjustor, and destructor starts.
- IDA MCP caller checks on 2026-05-24 currently show no direct callers for constructor `0x0052c360`, even though the method is fully modeled and constructs `NewUserShapeSelectControlPane`.
- Generated source shows direct dependency on `NewUserShapeSelectControlPane`, so that helper should stay nearby.
- Reconstructable attachment: this class now attaches to [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) after that file page was assigned to `NexusTK/login/`; the C++ block remains blank because field names, helper names, and reachability status are not final-source quality.

## Cross-References

- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already contained purpose, method, evidence, and cross-reference documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: the page documents the dialog's assets, major controls, command/submit methods, destructor family, and file/memory/class relationships; remaining gaps are detailed layout/state fields and confirmed live constructor reachability.
- 2026-06-02 autogen attachment:
  - What existed before: the class had no reconstructable flag or parent attachment.
  - Changed to: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000LP`.
  - Summary/evidence: exact child memory evidence and the validated login/create-user file parent support attachment; reconstructed C++ remains blank until final names, layout, and reachability are audited.
