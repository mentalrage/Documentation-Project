*** UID:0001V5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Menu Item Layouts

## Status

- Confidence: strong for shared base offsets and `StringMenuItem` text storage, medium for final flag names.
- Current entity kind: recovered layout notes for [UID:00007V][MenuItem](by-class/MenuItem.md), [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), and [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md).
- Likely owner header/source: `ui/menu/MenuItem.h` / [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Autogen parent: attached to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md); the file scores `84/80` and this multi-class layout scores `84/88`, so both sides satisfy the 80/80 parent gate. File-level attachment is used because the shared base layout spans `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem`.
- Evidence basis: IDA MCP decompilation/disassembly, function-boundary lookup, vtable xrefs, and [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md). `simroot_v2` remains only a lead source and is not used as authority.

## Shared MenuItem Base

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | primary vtable pointer | Constructors write `MenuItem`, `StringMenuItem`, or `SeparatorMenuItem` vtables here. |
| `+0x04` | `16` | bounds rectangle `{left, top, right, bottom}` | Constructors call the rectangle initializer on `this + 4`; draw helpers read left/top/right/bottom from these offsets; [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect](by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md) and [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBoundsRect](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md) copy this exact 16-byte field. |
| `+0x14` | `2` | state flags word | [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) writes word `1`; [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) writes word `0`. |
| `+0x14` | `1` | first state-flag byte, final source name unresolved | [UID:0002J4][0x00516f70-0x00516f74.MenuItemStateFlag0Accessor](by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md) returns this byte; [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetStateFlag0](by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md) writes it. |
| `+0x15` | `1` | selected/highlight flag within the state word, final source name unresolved | [UID:0002J5][0x00516f90-0x00516f94.MenuItemStateFlag1Accessor](by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md) returns this byte; [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetStateFlag1](by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md) writes it; [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) checks it to select highlighted rendering. |

The exact split of the `+0x14` state word is still provisional. A safe source rewrite should name the observed roles, such as enabled/interactable and selected/highlighted, only after reviewing `MenuPane` selection writes.

## StringMenuItem Extension

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x18` | `0x100` | inline UTF-16 label buffer, `wchar_t[0x80]` | [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) calls `wcscpy_s(this + 0x18, 0x80, source)`; [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) and [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) copy from byte offset `+0x18`. |

The minimum recovered `StringMenuItem` object size is therefore `0x118` bytes before allocator padding or compiler bookkeeping.

## SeparatorMenuItem Extension

No class-specific data fields are confirmed beyond the shared `MenuItem` base. Its behavior differs through vtable slots: [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md), [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md), and [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md).

## Source-Layout Impact

These layouts support grouping menu item declarations together in the reusable popup-menu/menu-pane source rather than keeping generated one-class files. `StringMenuItem` is a fixed-buffer menu entry, and `SeparatorMenuItem` is a data-light subclass that changes behavior through virtual slots.

## Cross-References

- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- 2026-06-06: Attached the shared menu item layouts to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). Scores remain `84/88`; this multi-class layout is better parented to the source file than to one subclass.
- Before: layout confidence relied partly on generated `simroot_v2` source and the state word was only summarized broadly.
- Changed to: IDA MCP is the stated authority; exact child memory pages now support the state bytes, string buffer, and separator behavior slots.
- Evidence: IDA MCP `lookup_funcs`, raw disassembly, byte review, decompilation, and vtable xrefs confirmed the child ranges and the byte/field accesses recorded above.
