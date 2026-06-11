*** UID:00003B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CreateUserDialogPane

## Status

- Confidence: strong for behavior and lifecycle ownership; medium for current emitted-body completeness.
- Likely source file: [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), under [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Exact method-range evidence: [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md), with lifecycle glue in [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- Associated generated/static data: [UID:0002SI][0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md) and [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
- Current recovered file: `source-3/simroot_v2/class_CreateUserDialogPane.cpp`
- Autogen parent: [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md). C++ remains blank because field names, helper names, and final source shape remain below the 95+ reconstruction gate.

## Class Purpose

`CreateUserDialogPane` is a full-screen create-user dialog. It builds the `DLGNEW3` account/character setup UI, randomizes initial body/hair/face state, drives gender/body selection, updates the preview, validates password fields, and sends the create-user request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CreateUserDialogPane` | `0x0052dd30` | Builds `DLGNEW3` dialog, text edits, gender/body buttons, hair/face selectors, color lists, and preview. |
| `SelectBodyShape` | `0x0052e770` | Updates selected body shape and description text. |
| `SelectMale` / `SelectFemale` | `0x0052e850`, `0x0052e8c0` | Toggles gender state and resets selectors. |
| `SetHairColorIndex` / `SetFaceColorIndex` | `0x0052e930`, `0x0052e950` | IDA MCP confirms these as 0x1f-byte color setter helpers. They are missing from the active emitted file but are called from the hair/face color-list controls. |
| `OnDialogAction` | `0x0052ea80` | Handles gender, body, scroll, submit, cancel, and preview-direction commands. |
| `OnKeyEvent` / `OnDialogShow` | `0x0052ecc0`, `0x0052ed00` | Listed by Wave3, but missing from the current emitted file. |
| `SubmitCreateUser` | `0x0052ed80` | Validates password digit/match rules, shows alerts, and sends create-account request. |
| `ScalarDeletingDestructor` | `0x0052f800` | Restores the `CreateUserDialogPane` vtables, destroys dialog state, clears the [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md), runs the base destructor, and optionally frees `this`. |

## Evidence Notes

- IDA confirms the constructor and submit method starts.
- Wave3 class inspection lists 13 methods, but the generated file currently omits several listed methods. This is recorded as a Wave3 data/materialization issue.
- 2026-06-03 IDA MCP recheck confirms method boundaries for the core old-dialog methods: constructor `0x0052dd30` size `0x9bb`, `SelectBodyShape` `0x0052e770` size `0xc2`, color setters `0x0052e930`/`0x0052e950` size `0x1f` each, command dispatcher `0x0052ea80` size `0x200`, submit validator `0x0052ed80` size `0x1cc`, packet helpers `0x0052ef50` size `0x205`, `0x0052f160` size `0x22d`, response handler `0x0052f390` size `0x355`, singleton clear helper `0x0052f710` size `0xb`, adjustor thunks `0x0052f73b`/`0x0052f746` size `0xb`, and scalar deleting destructor `0x0052f800` size `0x6c`.
- 2026-06-03 IDA MCP caller checks show the constructor called from `0x004f7a82` and `0x004f8ff8`, the command dispatcher calling `0x0052ed80`, the submit validator calling `0x0052ef50`, and the appearance payload helper `0x0052f160` called from local helpers and the response handler.
- 2026-06-03 IDA MCP xrefs tie [UID:0002SI][0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md) to constructor/destructor references at `0x0052dda2`, `0x0052e6f9`, and `0x0052f80c`, and [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md) to constructor writes/reads plus cleanup at `0x0052f710` and `0x0052f82d`.
- 2026-06-03 IDA MCP decompilation confirms `0x0052e930` looks up control id 6 and writes the selected byte to offset `269`; `0x0052e950` does the same for control id 7. Xrefs to the setters come from the hair/face color-list controls at `0x00501eee`, `0x005020b9`, `0x005021ae`, and `0x00502379`.
- 2026-06-03 IDA MCP decompilation of `0x0052ed80` confirms the submit path reads three text-edit controls, requires at least one digit in the password, compares password confirmation with `wcscmp`, shows alert panes on validation failure, and calls `0x0052ef50` after a successful validation.
- 2026-06-03 IDA MCP disassembly confirms the two 0xb-byte adjustor thunks subtract `0xa0` or `0xa4` from `ecx` before jumping to `0x0052f800`, and the scalar deleting destructor restores three `CreateUserDialogPane` vtables, destroys the description text, clears the `CreateUserDialogPane` singleton slot, runs the base destructor, and conditionally frees `this`.
- The current by-memory child pages split the old-dialog implementation into [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md) and [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md); the gap before `0x0052f710` is documented as padding/alignment, not additional class logic.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md)
- [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md)
- [UID:0002SI][0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData](by-memory/0x0061fe3c-0x0061fecc.CreateUserDialogPaneVtableData.md)
- [UID:0002B3][0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot](by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md)
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
- 2026-06-03 MCP verification and parent attachment:
  - What existed before: the class remained unassigned at `68/78`, with some behavior documented but no fresh verification for the omitted setter methods or destructor-thunk details.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md).
  - Summary/evidence: live IDA MCP lookup/caller/callee/xref/decompile/disassembly checks confirmed the old dialog method boundaries, constructor callers, color setter behavior, submit validation flow, vtable/singleton xrefs, and destructor adjustor thunks. C++ remains blank because the final field layout, helper names, and exact original source shape are not 95+ verified.
- 2026-06-07 A009 documentation synchronization:
  - What existed before: the page described the singleton and vtable evidence but did not link the exact by-memory child pages or canonical singleton-slot page.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, explicit links to the core-method child, destructor/thunk island, vtable data, and singleton-slot pages.
  - Summary/evidence: existing project-documentation pages now tie the old dialog method range, lifecycle glue, generated vtable block, and static singleton storage together without adding unverified C++.
