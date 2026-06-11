*** UID:0002X3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewUserDialogPane2

## Status

- Address: `0x0069b4a4` (`dword_69B4A4` in IDA).
- Type: `NewUserDialogPane2 *`.
- Owner file: [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md), under the create-user/login dialog family.
- Disposition: reconstructable NexusTK singleton global.
- Rebuild handling: `source-declared/generated-binary`.

## Role

`g_pNewUserDialogPane2` stores the active alternate 640x480 create-user dialog singleton. The constructor publishes the pane pointer, constructor fallback and cleanup paths clear it, the shared create-user destructor/helper island clears it, and [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md) reads it while closing pre-login dialogs.

## Evidence

- IDA MCP `py_eval` on 2026-06-07 reports `0x0069b4a4-0x0069b4a8` as a four-byte item named `dword_69B4A4`, bytes `ff ff ff ff`, initialized dword `0xffffffff`, with six xrefs.
- Xrefs are main-menu cleanup read `0x004f6a22`, constructor publish/fallback writes `0x0052a597` and `0x0052a59e`, constructor-adjacent cleanup clear `0x0052b07a`, singleton helper clear `0x0052f730`, and scalar deleting destructor clear `0x0052f90d`.
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md) and [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md) document the dialog source role, constructor/submit flow, vtable block, and login/create-user ownership.
- The exact storage split is [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md).

## Ownership Decision

Declare this with `login/NewUserDialogPane2.cpp` or the final create-user dialog source split. The main-menu cleanup helper is only a consumer; it does not own the declaration.

## Cross-References

- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## Changes

- 2026-06-07 Batch 043: Created canonical global page for the exact `0x0069b4a4` singleton slot. Evidence: live IDA MCP confirmed the item bounds, initial value, six xrefs, and direct ownership by `NewUserDialogPane2` constructor/destructor/helper paths.
