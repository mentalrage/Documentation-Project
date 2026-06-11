*** UID:0002X7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewCreateUserDialogPane

## Status

- Address: `0x0069b4a8` (`dword_69B4A8` in IDA).
- Type: `NewCreateUserDialogPane *`.
- Owner file: [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), under the create-user/login dialog family.
- Disposition: reconstructable NexusTK singleton global.
- Rebuild handling: `source-declared/generated-binary`.

## Role

`g_pNewCreateUserDialogPane` stores the active newer create-user dialog singleton. The constructor publishes the pane pointer, constructor fallback and cleanup paths clear it, the shared create-user destructor/helper island clears it, and [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) reads it while closing pre-login dialogs.

## Evidence

- IDA MCP `py_eval` on 2026-06-07 reports `0x0069b4a8-0x0069b4ac` as a four-byte item named `dword_69B4A8`, bytes `ff ff ff ff`, initialized dword `0xffffffff`, with six xrefs.
- Xrefs are main-menu cleanup read `0x004f6a13`, constructor publish/fallback writes `0x0052c3b8` and `0x0052c3bf`, constructor-adjacent cleanup clear `0x0052cd7a`, singleton helper clear `0x0052f720`, and scalar deleting destructor clear `0x0052f89d`.
- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) and [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md) document the dialog source role, constructor/submit flow, vtable block, and login/create-user ownership.
- The exact storage split is [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md).

## Ownership Decision

Declare this with `login/NewCreateUserDialogPane.cpp` or the final create-user dialog source split. The main-menu cleanup helper is only a consumer; it does not own the declaration.

## Cross-References

- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:00008Z][NewCreateUserDialogPane](by-class/NewCreateUserDialogPane.md)
- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md)
- [UID:0002SJ][0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe30.NewCreateUserDialogPaneVtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4a8` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `NewCreateUserDialogPane` constructor/destructor/helper paths.
