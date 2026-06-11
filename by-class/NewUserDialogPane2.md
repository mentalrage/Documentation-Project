*** UID:00009E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Main address range: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), inside aggregate [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
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
| packet/reply helpers | `0x0052bbc0-0x0052c325` | Encodes login/create-character payloads, sends through the connection global, and handles server replies. |
| Destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) records exact IDA function starts for the constructor-like body, selector/update helpers, command/event handlers, submit validation path, packet encoder, create-character payload builder, and response handler.
- The constructor is reached from the main-menu create-user paths at `0x004f7ad0` and [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f9041`.
- Vtable and singleton evidence are paired: `0x0061fd04` is referenced by constructor/destructor vtable stores, and singleton slot `0x0069b4a4` is written/cleared by the constructor, destructor, and clear helper. The exact vtable child is [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md).
- Submit-path decompilation evidence in the child memory page shows the three edit-field reads, digit-in-password requirement, confirmation comparison, alert fallback, packet encoding through string conversion/length-prefix helpers, send through `dword_67A7EC`, and server-reply alert/reset handling.
- Wave3's method name for `0x0052a540` should be corrected from destructor-like text to constructor.
- Reconstructable attachment: this class attaches to [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) after that file page was assigned to `NexusTK/login/`; the class C++ block stays blank because current method names, field names, and exact source split are not final-source quality.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, method boundaries, assets, destructor family, and Wave3 naming caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor/destructor starts, selector/submit method inventory, fixed-layout resources, and cross-links support a moderate-high score; confidence remains medium because the current Wave3 constructor name is wrong and detailed state/layout fields remain incomplete.
- 2026-06-02 autogen attachment:
  - What existed before: the class had no reconstructable flag or parent attachment and was scored `72/76`.
  - Changed to: `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000LW`, completion `74`, and confidence `80`.
  - Summary/evidence: the exact child memory page records constructor, singleton, vtable, selector, submit, packet, and response-handler evidence; the class now has a validated login/create-user file parent, but reconstructed C++ remains blank until final names and layout are audited.

- 2026-06-06 evidence sync:
  - What existed before: the class page remained at `74/80` even though the linked exact child and vtable pages now record the constructor callers, selector helpers, submit/packet/reply paths, vtable refs, singleton slot, and boundary split.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md), and [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) now cover the core method inventory, constructor reachability, vtable/singleton evidence, and login/create-user ownership. C++ remains blank under the 95/95 final-source gate.
