*** UID:00007W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Current recovered file: `source-3/simroot_v2/class_MenuPane.cpp`

## Class Purpose

`MenuPane` is the reusable popup/context menu pane. It owns a list of menu entries, lays out item regions, handles pointer and keyboard navigation, and calls an external selection callback target when the user confirms or cancels.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00516290-0x00516345` | `MenuPane::MenuPane(void* selectionTarget)` | Constructs pane state, entry list, and selection callback target. |
| `0x00516350-0x005163fa` | `~MenuPane()` | Releases entries, the entry list, callback target, and base pane state. |
| `0x005164e0-0x005164f7` | `GetItemByIndex(int)` | Returns the indexed menu item object. |
| `0x00516790-0x0051693e` | `InitializeLayout()` | Builds menu background/border and per-item regions. |
| `0x00516940-0x00516a62` | `HandlePointerEvent(const PointerEvent*)` | Hit-tests mouse movement/click/cancel behavior. |
| `0x00516a70-0x00516ba8` | `HandleKeyboardEvent(const KeyEvent*)` | Handles Enter/Space/Escape and up/down navigation. |
| `0x005172be-0x005172d4` | Adjustor/thunk helpers | Vtable-referenced deleting-destructor thunks. |
| `0x00517320-0x005173fe` | `ScalarDeletingDestructor(uint32_t flags)` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- Wave3 grades the class at effective `97.0`.
- IDA MCP confirms all listed starts as exact functions.
- Older Wave2 notes restored `GetItemByIndex` under `MenuPane` after reviewing `PopupMenuControlPane::OnDraw` and `RadioGroupControlPane::GetItemByIndex`.
- `MenuPane` selection dispatch can invoke the popup callback helper documented as [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md).

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: the popup/context menu pane has clear role, exact method boundaries, selection callback behavior, entry ownership, pointer/key navigation, and restored ownership evidence, with only final C++ rewrite and deeper state-field naming below full completion. Evidence: linked `MenuPaneAndItems` memory range, IDA-confirmed starts, Wave2 restoration note for `GetItemByIndex`, and popup selection callback reference.
