*** UID:00002S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClientSpellMenuItemList

## Status

- Confidence: strong.
- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ClientSpellMenuItemList.cpp`
- Address range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)

## Class Purpose

`ClientSpellMenuItemList` is the list-pane widget for client-local spell menu rows. It stores packet/action context, keeps each row's selected spell slot/code payload, and draws highlighted spell names with ellipsis truncation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClientSpellMenuItemList` | `0x0051e640-0x0051e6ab` | Constructs the fixed-layout list pane and stores spell category/group/level/context fields. |
| `OnItemActivated` | `0x0051e880-0x0051e88a` | Tail-call style activation helper that tells the owning spell context to update pending selection state. |
| `DrawListItem` | `0x0051e890-0x0051e998` | Draws selected/unselected row background and text, truncating row text from `entry + 4`; endpoint includes the full `retn 0Ch` instruction. |

## Evidence Notes

- Wave3 effective grade is `97.7`.
- IDA MCP confirms all three method ranges.
- Constructor xrefs come from `ClientSpellMenuDialog` at `0x0051dce7` and `0x0051e189`.
- 2026-05-24 IDA MCP decompilation of `0x0051e640` confirms this list installs `ClientSpellMenuItemList` vtables and stores packet/list context at offsets `+0x14c`, `+0x150`, `+0x154`, and `+0x158`.
- `DrawListItem` at `0x0051e890` draws text from `entry + 4`, matching the generated client spell row payload after the one-byte slot/code field.
- IDA xrefs show this class shares destructor adjustor thunks `0x00520ad1`/`0x00520adc` and scalar deleting destructor `0x00520c20` with `ServerSpellMenuItemList` and `ClientItemMenuItemList`.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:0000D4][ServerSpellMenuItemList](by-class/ServerSpellMenuItemList.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- What existed before: the page documented list-pane construction, activation, drawing, context offsets, and shared destructor thunks, but metadata was still `0/0`.
- What it was changed to: scores were set to `80/88`.
- Summary and evidence: constructor, row payload, draw behavior, dialog constructor xrefs, and shared destructor evidence are covered; final spell-row struct names and complete source-level declaration remain open.
