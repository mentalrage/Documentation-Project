*** UID:0000BG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# QuitDialog

## Status

- Confidence: strong for role and IDA boundaries.
- Likely source file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- Main address range: [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md)
- Current recovered file: `source-3/simroot_v2/class_QuitDialog.cpp`

## Class Purpose

`QuitDialog` is the modal Yes/No confirmation shown before returning to the main menu or disconnecting. It derives from the alert/dialog pane family, uses localized string id `3` for the title, and accepts both button clicks and `Y`/`N` keyboard shortcuts.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005addf0-0x005ade40` | `QuitDialog::QuitDialog()` | Builds an `AlertPane` with `Yes (Y)` and `No (N)` labels and installs `QuitDialog` vtables. |
| `0x005ade40-0x005adedb` | `OnKeyEvent(...)` | Handles key message type `8`; `Y/y` calls OK and closes, `N/n` calls cancel and closes, otherwise defers to `DialogPane::OnKeyEvent`. |
| `0x005adf20-0x005adf2e` | `OnOkButton()` | Calls the parcel/main-menu transition helper with action `1`. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the three listed function starts and sizes.
- IDA MCP caller checks show constructor references from `0x005bd202` in [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) and from the mode-gated launcher [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md).
- IDA MCP `xrefs_to` for `0x005ade40` and `0x005adf20` show vtable data xrefs, matching virtual event and OK-button handlers.
- The constructor uses `dword_67A740` as the alert context/parent. The generated name `g_pReconnectServer` remains provisional.

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md)
- [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/86`.
  - Before: The page was unevaluated despite documenting role, constructor, keyboard handling, OK action, callers, and vtable refs.
  - After: Scored as high completion and strong confidence for the modal quit confirmation dialog.
  - Evidence: Existing method map and IDA MCP evidence notes confirm function boundaries, constructor callers, and virtual handler xrefs.
