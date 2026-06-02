*** UID:00009E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewUserDialogPane2

## Status

- Confidence: strong for behavior and file ownership; medium-high for current generated constructor naming.
- Likely source file: [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Current recovered file: `source-3/simroot_v2/class_NewUserDialogPane2.cpp`

## Class Purpose

`NewUserDialogPane2` is an alternate create-user dialog variant for a fixed 640x480 layout. It uses `DLGNEW02.EPD` and `NPAL3.PAL`, displays multiple shape previews, and provides gender, totem, body-shape, direction, and submit controls.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserDialogPane2` | `0x0052a540` | Constructor; Wave3 currently names the row `~NewUserDialogPane2`, but signature/source are constructor-like. |
| `ShiftShapesLeft` / `ShiftShapesRight` | `0x0052b090`, `0x0052b1d0` | Rotates visible shape preview choices. |
| `SelectGender`, `SelectTotem`, `SelectShapeSlot` | `0x0052b310`, `0x0052b3a0`, `0x0052b470` | Updates selected create-user attributes. |
| `SelectMale` / `SelectFemale` | `0x0052b530`, `0x0052b5c0` | Gender-specific selector setup. |
| `OnCommand` | `0x0052b760` | Command dispatcher. |
| `OnDialogEvent` / `OnDialogNotify` | `0x0052b890`, `0x0052b940` | Dialog event/notification handlers. |
| `SubmitCreateUser` | `0x0052b9f0` | Validates and sends create-user request. |
| Destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- IDA confirms the constructor at `0x0052a540` and destructor at `0x0052f8e0`.
- Wave3's method name for `0x0052a540` should be corrected from destructor-like text to constructor.
- Reconstructable attachment: this class now attaches to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) after that file page was assigned to `NexusTK/login/`; the class C++ block stays blank because current method and field names are not final-source quality.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, assets, destructor family, and Wave3 naming caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor/destructor starts, selector/submit method inventory, fixed-layout resources, and cross-links support a moderate-high score; confidence remains medium because the current Wave3 constructor name is wrong and detailed state/layout fields remain incomplete.
- 2026-06-02 autogen attachment:
  - What existed before: the class had no reconstructable flag or parent attachment and was scored `72/76`.
  - Changed to: `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000LW`, completion `74`, and confidence `80`.
  - Summary/evidence: the exact child memory page records constructor, singleton, vtable, selector, submit, packet, and response-handler evidence; the class now has a validated login/create-user file parent, but reconstructed C++ remains blank until final names and layout are audited.
