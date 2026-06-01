*** UID:0000D4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerSpellMenuItemList

## Status

- Confidence: strong.
- Likely source file: [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ServerSpellMenuItemList.cpp`
- Address range: [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)

## Class Purpose

`ServerSpellMenuItemList` is the list-pane widget for server-supplied spell menu rows. It stores packet/action context, forwards activation to the owning dialog state, and draws highlighted spell rows with ellipsis truncation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ServerSpellMenuItemList` | `0x0051d700-0x0051d76b` | Constructs the fixed-layout list pane and stores spell category/group/level/context fields. |
| `OnItemActivated` | `0x0051da20-0x0051da2a` | Tail-call style activation helper that tells the owning spell context to update pending selection state. |
| `DrawListItem` | `0x0051da30-0x0051db37` | Draws selected/unselected row background and text, truncating row text from `entry + 2`. |

## Evidence Notes

- Wave3 effective grade is `97.7`.
- IDA MCP confirms all three method ranges.
- Constructor xrefs come from `ServerSpellMenuDialog` at `0x0051cbee` and `0x0051d131`.
- Server/client action-button helpers both fetch child slot `6` as the spell list and call the same enabled-entry count helper, supporting a shared private list-pane pattern within `SpellMenuDialogs.cpp`.
- IDA xrefs show this class shares destructor adjustor thunks `0x00520ad1`/`0x00520adc` and scalar deleting destructor `0x00520c20` with `ClientSpellMenuItemList` and `ClientItemMenuItemList`.

## Cross-References

- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002S][ClientSpellMenuItemList](by-class/ClientSpellMenuItemList.md)
- [UID:0000VH][SpellMenuActionButtonState_51d6c0_51e600](by-item/SpellMenuActionButtonState_51d6c0_51e600.md)
- [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md)
- [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents behavior, ownership, constructor/activation/draw methods, constructor callers, shared helper pattern, and destructor-thunk/scalar-destructor cross-references; remaining completion gap is full source-level reconstruction.
