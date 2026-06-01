*** UID:000042 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DropAllInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DropAllInputPane.cpp`

## Class Purpose

`DropAllInputPane` is a single-character inventory prompt for dropping all items in a selected slot. It formats a player-specific prompt, accepts a slot letter, validates it against the local inventory limit, and either sends the drop-all packet path or opens a confirmation callback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropAllInputPane` | `0x005b44b0-0x005b4577` | Constructs the `CharInputPane` prompt and installs vtables. |
| `OnKeyInput` | `0x005b4580-0x005b45ec` | Opens the help/general-purpose panel for the shortcut key and otherwise delegates input. |
| `OnConfirmInput` | `0x005b45f0-0x005b475c` | Converts slot letters, validates inventory range, and sends or confirms the drop-all action. |

## Evidence Notes

- Wave3 generated source shows shared use of `g_pLanguageMan`, `g_pLocalPlayer`, `g_pPlayerData`, and `g_packetSender`.
- IDA MCP confirms all three function starts.
- This class is part of the direct item action prompt family, not the item selection dialog family.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: prompt role, constructor/key/confirm methods, item-action module ownership, packet/action behavior, IDA-confirmed starts, and sibling pane references are documented; remaining work is fuller internal field naming and final C++ reconstruction.
