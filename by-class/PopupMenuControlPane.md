*** UID:0000AN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PopupMenuControlPane

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:00011F][0x00498040-0x0049b8e5.PopupMenuControlPane](by-memory/0x00498040-0x0049b8e5.PopupMenuControlPane.md)
- Current recovered file: `source-3/simroot_v2/class_PopupMenuControlPane.cpp`

## Class Purpose

`PopupMenuControlPane` is a control widget that owns a `MenuPane`, draws `POPUP_MENU` EPF pieces, renders the selected menu item label, and maps mouse/key input to item selection.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00498040-0x0049812b` | `PopupMenuControlPane::PopupMenuControlPane(int menuType, int* parentBlock)` | Constructs the base control, callback object, owned `MenuPane`, and selected-index state. |
| `0x00498270-0x004984bc` | `OnDraw()` | Draws popup menu art and selected item text. |
| `0x004984c0-0x0049851a` | `OnMouseEvent(Event*)` | Handles click selection. |
| `0x00498520-0x00498599` | `OnKeyEvent(Event*)` | Handles keyboard selection from scroll position. |
| `0x0049af95-0x0049afab` | Destructor adjustor/thunk helpers | Secondary-vtable deleting-destructor thunks. |
| `0x0049b3b0-0x0049b417` | `~PopupMenuControlPane()` | Releases the owned `MenuPane` and base pane state. |
| `0x0049b8e0-0x0049b8e5` | `GetControlType()` | Returns control type `12`. |

## Evidence Notes

- Wave3 grades the class at effective `96.4`.
- IDA MCP confirms all listed starts as exact functions.
- The generated callback helper at `0x0049af00-0x0049af11` belongs near this file; use [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) as the short alias because the full generated template name is unwieldy.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite class role, method map, source-file placement, IDA boundaries, and callback-helper links.
- Changed to: `COMPLETION:76` and `CONFIDENCE:84`.
- Evidence: constructor, drawing, mouse/key event handling, destructor thunks, destructor, control type id, owned `MenuPane`, and selection callback are documented; remaining gaps are field layout and full reconstructed C++.
