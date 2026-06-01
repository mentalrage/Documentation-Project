*** UID:0000D3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSpellMenuDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ServerSpellMenuDialog.cpp`
- Address range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)

## Class Purpose

`ServerSpellMenuDialog` displays spell actions supplied by server packet data. It parses the server text and row strings, builds a merchant-style spell menu, and sends the selected row text back in an opcode `0x39` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSpellMenuDialog` | `0x0051ca40-0x0051d519` | Initializes the dialog, parses packet text/list entries, builds background/buttons/object preview/static text/list controls, and shows the dialog. |
| `HandleMenuCommand` | `0x0051d520-0x0051d6b1` | Handles action/request/cancel commands; action sends selected spell-menu text in an opcode `0x39` packet. |
| `UpdateActionButtonState` | `0x0051d6c0-0x0051d6fc` | Enables or disables the action button based on enabled-entry count in the spell list; structural sibling of the client helper. |

## Evidence Notes

- Wave3 effective grade is `97.3`.
- IDA MCP confirms the three method ranges above.
- The constructor has dispatcher xrefs from `0x005176c3` and `0x00517b77`.
- The class shares layout resources and control construction with `ClientSpellMenuDialog`, but its list rows are server-supplied.
- 2026-05-24 IDA MCP decompilation shows the same action/list child-slot pattern as the client dialog: child `1` is the action button, child `6` is the spell list, and enabled-entry count controls button enable/disable.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `90`.
- Evidence: the page documents behavior, ownership, by-memory range, constructor/command/update methods, dispatcher xrefs, child-slot pattern, and sibling relationship with client spell menus; remaining completion gap is full source-level reconstruction.
