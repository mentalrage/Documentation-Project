*** UID:00006S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InventoryPane2

## Status

- Confidence: strong for alternate inventory-pane behavior, medium for constructor boundary.
- Likely source file: [UID:0000KA][InventoryPane](by-file/InventoryPane.md) or `ui/inventory/InventoryPane.cpp`
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_InventoryPane2.cpp`

## Class Purpose

`InventoryPane2` is an alternate compact item inventory pane. It renders list/grid inventory layouts, supports page navigation, hit-tests fixed item rectangles, and sends the same item use or drag-transfer style actions as the other item inventory panes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InventoryPane2` | `0x004ee650-0x004ee6a6` | Wave3-projected constructor; IDA does not currently define a function at this start. |
| `OnPaint` | `0x004ee6f0-0x004eee5b` | Draws list/grid item inventory with `ITEMINV.EPF` assets. |
| `OnKeyEvent` | `0x004eee60-0x004eeedb` | Handles Page Up/Page Down. |
| `OnMouseEvent` | `0x004eeee0-0x004ef279` | Handles hover, mode switching, item use, right-click alt-use, and drag/drop packet `0x66`. |
| `GetButtonRect` | `0x004ef630-0x004ef701` | Returns fixed rectangles for left/right and up/down buttons. |
| `HitTestSlot` | `0x004ef890-0x004ef961` | Hit-tests list/grid inventory slots. |
| `ScalarDeletingDestructor` | `0x004efa40-0x004efa94` | Destroys parent state and conditionally frees storage. |

## Evidence Notes

- IDA MCP confirms `OnPaint`, `OnMouseEvent`, and scalar deleting destructor boundaries.
- IDA reports no function at `0x004ee650`; previous function is `0x004ee5a0-0x004ee643`, next function is `0x004ee6b0-0x004ee6cf`. This is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: alternate compact inventory-pane behavior, core draw/key/mouse/hit-test/destructor methods, and source placement are documented, but the constructor boundary remains unresolved and tracked as a data issue. Evidence: `InventoryPanes`, IDA-confirmed method boundaries, and no-function note for `0x004ee650`.
