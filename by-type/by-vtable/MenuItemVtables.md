*** UID:0001Y4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Menu Item Vtables

## Status

- Confidence: strong for vtable addresses and slot targets, medium for final source-level virtual names.
- Current entity kind: vtable/layout evidence for [UID:00007V][MenuItem](by-class/MenuItem.md), [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), and [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md).
- Likely owner header/source: `ui/menu/MenuItem.h` / [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Evidence basis: IDA MCP `py_eval`, xrefs, decompilation, vtable slot reads, and exact function-boundary lookup. `simroot_v2` is only a lead source; `wave3.py` was not executed for this pass.

## Vtable Run

IDA resolves the three decorated vtable symbols in one compact `.rdata` run:

| Class | RTTI pointer | Vtable base | Slot range | Notes |
| --- | --- | --- | --- | --- |
| [UID:00007V][MenuItem](by-class/MenuItem.md) | `0x0061eb94` | `0x0061eb98` | `0x0061eb98-0x0061ebac` | Base entry type; most behavior slots are pure virtual. |
| [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) | `0x0061ebb0` | `0x0061ebb4` | `0x0061ebb4-0x0061ebc8` | Text item implementation. |
| [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) | `0x0061ebcc` | `0x0061ebd0` | `0x0061ebd0-0x0061ebec` | Separator has two extra fixed-metric/style slots before following string data. |

The next dword after the separator slot run is UTF-16 resource/string data, not another vtable entry.

## Slot Map

| Slot | MenuItem | StringMenuItem | SeparatorMenuItem | Role hypothesis |
| --- | --- | --- | --- | --- |
| `+0x00` | [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) | [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | Scalar deleting destructor. |
| `+0x04` | `0x004f4b10` | `0x004f4b10` | `0x004f4b10` | Inherited `LObject`/runtime virtual. |
| `+0x08` | `0x0041b6c0` | `0x0041b6c0` | `0x0041b6c0` | Shared no-op virtual. |
| `+0x0c` | `__purecall` | [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) | `__purecall` | String item size/metrics slot; base is abstract. |
| `+0x10` | `__purecall` | [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) | `__purecall` | String/text-copy slot; base is abstract. |
| `+0x14` | `__purecall` | [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) | [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) | Draw/render slot. |
| `+0x18` | next RTTI | next RTTI | [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) | Separator fixed-dimensions slot. |
| `+0x1c` | not a slot | not a slot | [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md) | Separator style/flags slot. |

## Constructor And Destructor Evidence

- `xrefs_to 0x0061eb98` reports writes from `MenuItem::MenuItem` at `0x00516f41`, the base-construction portions of `StringMenuItem` at `0x00517031` and `SeparatorMenuItem` at `0x005171f1`, plus base vtable resets in destructors at `0x005172e6` and `0x00517406`.
- `xrefs_to 0x0061ebb4` reports the `StringMenuItem` vtable write at `0x0051704e`.
- `xrefs_to 0x0061ebd0` reports the `SeparatorMenuItem` vtable write at `0x00517205`.
- IDA data xrefs place `StringMenuItem` virtual slots at `0x0061ebc0`, `0x0061ebc4`, and `0x0061ebc8`, and separator slots at `0x0061ebe4`, `0x0061ebe8`, and `0x0061ebec`.

## Data Caveats

Current `simroot_v2` metadata reports `vtable_count: 0` for `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` even though IDA has decorated vtable symbols and constructor/destructor writes for all three classes.

## Cross-References

- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- Before: vtable slots were documented only as raw addresses and the page was ungraded.
- Changed to: reconstructable metadata is set, slot rows link to exact by-memory child pages, and the evidence basis explicitly treats generated data as a lead only.
- Evidence: IDA MCP vtable dword reads, xrefs to slot targets, and `lookup_funcs` confirmed the current slot targets and function extents.
