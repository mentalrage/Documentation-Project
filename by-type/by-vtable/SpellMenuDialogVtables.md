*** UID:00031X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Spell Menu Dialog Vtables

## Status

- Entity kind: owner-specific MSVC vtable layout.
- Source owner: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md).
- Covered classes: `ServerSpellMenuDialog`, `ServerSpellMenuItemList`, `ClientSpellMenuDialog`, and `ClientSpellMenuItemList`.
- Mixed-family master: [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).
- IDA evidence basis: B001-008 live IDA MCP `py_eval` on 2026-06-10 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Binary Evidence

| Class | Vtable bases | Store/xref evidence |
| --- | --- | --- |
| `ServerSpellMenuDialog` | `0x0061f168`, `0x0061f1c8`, `0x0061f1f8` | Constructor `0x0051ca40` stores at `0x0051ca95`, `0x0051ca9b`, and `0x0051caa5`. |
| `ServerSpellMenuItemList` | `0x0061f204`, `0x0061f28c`, `0x0061f2bc` | Constructor `0x0051d700` stores at `0x0051d736`, `0x0051d73c`, and `0x0051d746`. |
| `ClientSpellMenuDialog` | `0x0061f2c8`, `0x0061f328`, `0x0061f358` | Constructor `0x0051db40` stores at `0x0051db95`, `0x0051db9b`, and `0x0051dba5`. |
| `ClientSpellMenuItemList` | `0x0061f364`, `0x0061f3ec`, `0x0061f41c` | Constructor `0x0051e640` stores at `0x0051e68b`, `0x0051e691`, and `0x0051e69b`. |

Every listed base has a decorated `??_7...@@6B@` name and a complete-object-locator pointer at `base - 4`. The server and client dialog secondary views contain inherited `0x00517d80` slots at `0x0061f1d8` and `0x0061f338`.

## Ownership Inference

The spell-menu vtable subfamily belongs to [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md). Its constructor stores are inside [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md), and the existing file parent clears the corrected `85/85` gate.

## Assignment Gate

| Candidate parent | Gate result | Reason |
| --- | --- | --- |
| [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md) | selected | Direct owner bucket for server/client spell-menu dialogs and their private spell-list companions. |
| Individual spell class pages | rejected for this grouped page | Some exact class pages remain below `85/85`; this page is an owner-specific source-family page. |
| [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) | rejected | Supplies inherited dialog-base virtual only. |
| [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) | rejected | Mixed inventory across unrelated source owners. |

## Reconstruction Notes

Reconstruct these vtables through the spell-menu class declarations and list-pane companion declarations. Do not emit raw vtable data as source.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)

## Changes

- 2026-06-10 B001-008 split:
  - Created as the owner-specific `SpellMenuDialogs` child of the mixed merchant-menu vtable family.
  - Evidence: live IDA MCP confirms decorated vtable names, complete-object-locator pointers, constructor store xrefs, and inherited dialog-base slots for the two dialog classes.
