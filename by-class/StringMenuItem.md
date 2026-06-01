*** UID:0000E8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringMenuItem

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_StringMenuItem.cpp`

## Class Purpose

`StringMenuItem` is a text menu entry. It stores a fixed wide-character label, reports its required size to the owning pane, copies its label for selected-display rendering, and draws highlighted or normal text.

IDA confirms the inline label buffer begins at byte offset `+0x18` and is copied with capacity `0x80` wide characters. Text-copy helpers at `0x00517070` and `0x005170d0` both read from that same offset.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) | `StringMenuItem::StringMenuItem(wchar_t* text)` | Initializes base menu item state and copies label text. |
| [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) | `CopyTextToWideBuffer(...)` | Copies label into caller buffer. |
| [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) | `GetItemSize(...)` | Measures label width and returns item dimensions. |
| [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) | `GetText(...)` | Copies label into caller buffer. |
| [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) | `DrawItem(...)` | Draws normal or selected text. |
| [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) | `ScalarDeletingDestructor(int flags)` | Derived destructor wrapper. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all listed starts and extents as exact functions.
- Constructor xrefs come from several dialog/menu creation paths, making this reusable infrastructure rather than one feature's private item class.
- 2026-05-26 IDA MCP resolves the decorated `StringMenuItem` vtable symbol to `0x0061ebb4`; generated metadata still reports `vtable_count: 0`.
- Vtable data xrefs place `GetItemSize`, `GetText`, and `DrawItem` at slots `+0x0c`, `+0x10`, and `+0x14`.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `90`.
- Evidence: the page documents the menu-item role, buffer offset/capacity, exact method map, reusable caller evidence, vtable symbol, and slot refs; remaining completion gap is source-ready C++ detail.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK-owned source infrastructure. Autogen parent/code remain blank because final source-ready C++ and parent attachment are below the `95+` gate.
- Method-map split update: existed before as raw address rows; changed to UID links for exact by-memory child pages. Evidence: IDA MCP exact function-boundary lookup and vtable slot xrefs support the child pages.
