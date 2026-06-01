*** UID:00005U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GiveInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_GiveInputPane.cpp`

## Class Purpose

`GiveInputPane` is the standard item-give prompt. It accepts a single inventory slot letter, routes gold selection into `GiveGoldInputPane`, and opens a confirmation callback for normal item slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveInputPane` | `0x005b4f70-0x005b5037` | Constructs the prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b5040-0x005b50ac` | Handles help-panel shortcut and delegates normal input. |
| `OnConfirmInput` | `0x005b50b0-0x005b5223` | Converts slot input, creates `GiveGoldInputPane` for gold, or opens give confirmation. |

## Evidence Notes

- Wave3 generated source shows the gold branch manually constructing a `NumberInputPane` and assigning `GiveGoldInputPane` vtables.
- IDA MCP confirms all three function starts.
- This class is the give counterpart to [UID:000044][DropInputPane](by-class/DropInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: standard give prompt role, constructor/key/confirm methods, gold branch, sibling relationship, and item-action module placement are documented with strong confidence; remaining work is detailed layout naming and final source reconstruction. Evidence: `0x005b44b0-0x005b538a` memory page, IDA-confirmed starts for `0x005b4f70`, `0x005b5040`, and `0x005b50b0`, plus GiveAll/GiveGold cross-references.
