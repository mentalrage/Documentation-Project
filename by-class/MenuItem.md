*** UID:00007V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuItem

## Status

- Confidence: strong for base class role.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_MenuItem.cpp`

## Class Purpose

`MenuItem` is the base menu entry object. It initializes an empty bounds rectangle and enabled state, then provides the base deleting destructor for derived menu items.

The shared base layout starts with the vtable pointer at `+0x00`, a bounds rectangle at `+0x04`, and a state/flag word at `+0x14`. `StringMenuItem` extends this with an inline label buffer, while `SeparatorMenuItem` only changes behavior through vtable slots.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) | `MenuItem::MenuItem()` | Initializes `LObject`, vtable, bounds, and enabled state. |
| [UID:0002J4][0x00516f70-0x00516f74.MenuItemStateFlag0Accessor](by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md) | state flag byte accessor | Returns the low byte of the shared state word at `+0x14`; final source name unresolved. |
| [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetStateFlag0](by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md) | state flag byte setter | Writes the low byte of the shared state word at `+0x14`; final source name unresolved. |
| [UID:0002J5][0x00516f90-0x00516f94.MenuItemStateFlag1Accessor](by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md) | state flag byte accessor | Returns byte `+0x15`, which `StringMenuItem` draw logic uses as highlighted/selected state. |
| [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetStateFlag1](by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md) | state flag byte setter | Writes byte `+0x15`; final source name unresolved. |
| [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect](by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md) | bounds getter/copy helper | Copies the 16-byte bounds rectangle at `+0x04` into a caller buffer. |
| [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBoundsRect](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md) | bounds setter/copy helper | Copies a caller rectangle into the 16-byte bounds field at `+0x04`. |
| [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | scalar deleting destructor | Base destructor wrapper used by `MenuItem` and `SeparatorMenuItem` vtables. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the modeled constructor, two state accessors, and scalar deleting destructor as exact function starts; IDA disassembly confirms four adjacent raw method-shaped helpers at `0x00516f80`, `0x00516fa0`, `0x00516fb0`, and `0x00516fd0`.
- 2026-05-26 IDA MCP resolves the decorated `MenuItem` vtable symbol to `0x0061eb98`; current `simroot_v2` metadata still reports `vtable_count: 0`.
- The base vtable has pure virtual behavior slots at `+0x0c`, `+0x10`, and `+0x14`, supporting `MenuItem` as an abstract/reusable entry type.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the abstract base menu entry role, layout, constructor/destructor, vtable, and derived-class relationships are documented, but the page remains concise and lacks full source-level method/body reconstruction. Evidence: linked menu-pane/items range, `MenuItemVtables`, `MenuItemLayouts`, IDA-confirmed starts, and pure virtual slot notes.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK menu infrastructure that must be represented in the rebuilt source, but autogen parent/code are intentionally blank because exact original source shape is not at the `95+` threshold.
- Method-map split update: existed before with only broad address rows for constructor/destructor; changed to UID links for exact by-memory child pages including state-byte accessors/setters and bounds-copy helpers. Evidence: IDA MCP `lookup_funcs`, disassembly, and byte review confirmed the modeled and raw helper bodies.
