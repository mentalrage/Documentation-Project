*** UID:00002R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientSpellMenuDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ClientSpellMenuDialog.cpp`
- Address range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)

## Class Purpose

`ClientSpellMenuDialog` displays spell actions built from local player spell data. It parses the packet shell and object preview, then populates the list from the local spell table and sends the selected spell code in an opcode `0x39` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientSpellMenuDialog` | `0x0051db40-0x0051e4d2` | Initializes the dialog, parses packet text/object data, populates client spell rows from `g_pPlayerData`, and builds the control tree. |
| `HandleMenuCommand` | `0x0051e4e0-0x0051e5f1` | Handles action/request/cancel commands; action sends selected spell code with packet type/value/list seed. |
| `UpdateActionButtonState` | `0x0051e600-0x0051e63c` | Enables or disables the action button based on enabled spell-list entries; generated source has a polluted `ChattingColorListPane*` local type. |

## Evidence Notes

- Wave3 effective grade is `98.0`.
- IDA MCP confirms the three method ranges above.
- The constructor has dispatcher xrefs from `0x0051770b` and `0x00517c07`.
- Current generated `UpdateActionButtonState` names the list as `ChattingColorListPane`; this is treated as owner-name pollution and should not imply chat ownership.
- 2026-05-24 IDA MCP decompilation confirms the method fetches child slot `1` for the action button and child slot `6` for the spell list, then calls the generic enabled-entry count helper before jumping to action-button enable/disable virtuals.
- `ClientSpellMenuItemList` constructor and renderer evidence shows the list object stores client spell packet context and draws row text from `entry + 4`; no chat-color constructor xref reaches this dialog.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)

## Changes

- What existed before: the page documented client spell-menu construction, command handling, action-button state, and generated owner-pollution caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: method ranges, dispatcher xrefs, local spell data use, list child semantics, and polluted `ChattingColorListPane` type are covered; final row/action enum naming and full layout remain below exhaustive.
