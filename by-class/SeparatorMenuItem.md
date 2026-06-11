*** UID:0000CY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SeparatorMenuItem

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_SeparatorMenuItem.cpp`

## Class Purpose

`SeparatorMenuItem` is a non-interactive menu separator. It reports fixed metrics/style flags and draws a horizontal separator line centered in its item bounds.

IDA currently confirms no fields beyond the shared [UID:00007V][MenuItem](by-class/MenuItem.md) base. The separator-specific behavior is vtable-driven: draw at slot `+0x14`, fixed dimensions at `+0x18`, and style/flags at `+0x1c`.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) | `SeparatorMenuItem::SeparatorMenuItem()` | Initializes base menu item state and installs separator vtable. |
| [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) | `GetDefaultDimensions(...)` | Returns fixed separator dimensions. |
| [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md) | `GetStyleFlags(...)` | Returns style flags. |
| [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) | `DrawSeparator(...)` | Draws centered separator line. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all listed starts and extents as exact functions.
- 2026-05-26 IDA MCP resolves the decorated `SeparatorMenuItem` vtable symbol to `0x0061ebd0`; generated metadata still reports `vtable_count: 0`.
- The separator constructor writes the base `MenuItem` vtable first, clears the shared state word to `0`, then installs `SeparatorMenuItem`'s vtable.
- 2026-06-07 A010 Batch096 parent-gate review confirms this class already clears the corrected child gate at `86/90`. Associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85` by synchronizing the newer `MenuPaneAndItems`, `MenuItemVtables`, `MenuItemLayouts`, and proposed-source-tree evidence.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). The child remains `86/90`, the direct source-file parent is now `86/85`, and by-structure ownership is direct: `SeparatorMenuItem` is a concrete menu item implemented in the reusable popup-menu/menu-item source family rather than a feature-dialog local class.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)

## Changes

- 2026-06-07 A010 Batch096 class coverage toss-up:
  - Before: score `86/90`, `AUTOGEN_PARENT_UID` blank because the likely direct parent was below the corrected gate.
  - After: score remains `86/90`, `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: the class already had exact constructor/metric/style/draw child pages and vtable/layout evidence; associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85`, satisfying the strict child-and-parent gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `90`.
- Evidence: the page documents the class role, file ownership, main by-memory range, vtable/layout links, exact constructor and virtual method ranges, and IDA-confirmed vtable symbol; remaining completion gap is final source-ready C++ detail.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK-owned menu infrastructure. Autogen parent/code remain blank because final source-ready C++ and parent attachment are below the `95+` gate.
- Method-map split update: existed before as raw address rows; changed to UID links for exact by-memory child pages. Evidence: IDA MCP exact function-boundary lookup and vtable slot xrefs support the child pages.
