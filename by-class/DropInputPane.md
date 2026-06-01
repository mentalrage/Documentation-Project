*** UID:000044 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DropInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DropInputPane.cpp`

## Class Purpose

`DropInputPane` is the standard item-drop prompt. It accepts a single inventory slot letter, routes gold selection into `DropGoldInputPane`, and sends or confirms the item-drop action for normal inventory slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropInputPane` | `0x005b47e0-0x005b48a7` | Constructs the prompt with player name and installs vtables. |
| `OnKeyEvent` | `0x005b48b0-0x005b491c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmit` | `0x005b4920-0x005b4ae4` | Converts input to a slot, creates `DropGoldInputPane` for gold, or sends/confirm drop item opcode `0x08`. |

## Evidence Notes

- Wave3 generated source shows the gold branch manually constructing `DropGoldInputPane`.
- IDA MCP confirms all three function starts.
- The class belongs with the direct item action panes because it owns command-input translation and packet dispatch rather than inventory rendering.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: standard drop prompt role, constructor/key/submit methods, gold branch, opcode behavior, item-action module ownership, and sibling pane links are documented; remaining work is detailed field naming and final reconstructed C++ polish.
