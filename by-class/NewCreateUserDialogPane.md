*** UID:00008Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Evidence basis: live IDA MCP function, xref, vtable, singleton, command-dispatch, and boundary checks through 2026-06-04.

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

- 2026-06-04 live IDA confirms the constructor, selector helpers, command/event/notify handlers, submit helper, packet/reply helpers, singleton clear helper, adjustor thunks, and scalar deleting destructor starts.
- Live IDA MCP caller checks still show no direct callers for constructor `0x0052c360`, even though the constructor is fully modeled and constructs `NewUserShapeSelectControlPane` through `0x004fd520` at `0x0052c7aa`.
- Live IDA confirms constructor-side writes to singleton `0x0069b4a8` and three `NewCreateUserDialogPane` vtable slots at `0x0061fda0`, `0x0061fe00`, and `0x0061fe30`; the scalar deleting destructor at `0x0052f870` writes the same vtable slots and clears the singleton.
- The `0x0052d210` command dispatcher is a 16-case jump table: case 17 calls submit helper `0x0052d3e0`; cases 4/5 and 9-14 call the local gender/totem selector helpers.
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
- 2026-06-04 live IDA evidence update:
  - What existed before: completion/confidence were `72/84`, with stale recovered-source provenance and lighter evidence notes.
  - Changed to: completion `82`, confidence `86`, and evidence notes now cite live IDA MCP function starts, vtable/singleton writes, shape-control construction, command dispatch, and destructor support.
  - Summary/evidence: the class method map is now backed by live disassembly/xrefs rather than stale provenance. The score remains below final-source status because direct constructor reachability and field/layout names are still unresolved.
