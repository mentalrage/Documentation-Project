*** UID:00005S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GiveAllInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_GiveAllInputPane.cpp`

## Class Purpose

`GiveAllInputPane` is a single-character prompt for giving all items in a selected slot to another player. It mirrors the drop-all prompt shape but builds a give callback and confirmation message.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveAllInputPane` | `0x005b4cc0-0x005b4d87` | Constructs prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b4d90-0x005b4dfc` | Handles help-panel shortcut and delegates input. |
| `OnSubmitInput` | `0x005b4e00-0x005b4eee` | Converts slot letter, validates inventory range, and creates a give-all confirmation callback. |

## Evidence Notes

- Wave3 generated source shows callback creation through `GiveItemsToSlot` with the all-items flag set.
- IDA MCP confirms all three function starts.
- The class should migrate beside [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) and [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: give-all prompt role, constructor/key/submit methods, callback behavior, inventory validation, and sibling placement are documented with strong confidence; remaining work is final source reconstruction and field naming. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4cc0`, `0x005b4d90`, and `0x005b4e00`, plus ItemActionInputPanes vtable documentation.
