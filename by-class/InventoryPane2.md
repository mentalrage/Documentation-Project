*** UID:00006S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InventoryPane2

## Status

- Confidence: strong for alternate inventory-pane behavior, source placement, exact raw constructor bytes, and vtable evidence; medium-high for final field/helper names and live caller reachability.
- Likely source file: [UID:0000KA][InventoryPane](by-file/InventoryPane.md) / `ui/inventory/InventoryPane.cpp`
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Exact confirmed children: [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md), and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_InventoryPane2.cpp`
- Autogen handling: parent intentionally blank under the corrected `85/85` gate because this class is `82/86` and [UID:0000KA][InventoryPane](by-file/InventoryPane.md) remains below the parent gate.

## Class Purpose

`InventoryPane2` is an alternate compact item inventory pane. It renders list/grid inventory layouts, supports page navigation, hit-tests fixed item rectangles, and sends the same item use or drag-transfer style actions as the other item inventory panes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InventoryPane2` | `0x004ee650-0x004ee6a7` | Exact raw constructor child; IDA does not define a function or xrefs at this start, but the byte body calls `PanelPane`, stores all three `InventoryPane2` vtables, clears fields, and returns `this`. |
| `OnPaint` | `0x004ee6f0-0x004eee5b` | Draws list/grid item inventory with `ITEMINV.EPF` assets. |
| `OnKeyEvent` | `0x004eee60-0x004eeedb` | Handles Page Up/Page Down. |
| `OnMouseEvent` | `0x004eeee0-0x004ef279` | Handles hover, mode switching, item use, right-click alt-use, and drag/drop packet `0x66`. |
| `GetButtonRect` | `0x004ef630-0x004ef701` | Returns fixed rectangles for left/right and up/down buttons. |
| `HitTestSlot` | `0x004ef890-0x004ef961` | Hit-tests list/grid inventory slots. |
| `ScalarDeletingDestructor` | `0x004efa40-0x004efa94` | Destroys parent state and conditionally frees storage. |

## Evidence Notes

- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md) records the exact raw constructor bytes, no-function/no-xref status at `0x004ee650`, `PanelPane` base-constructor call, three `InventoryPane2` vtable stores, state clears, return, and `0x004ee6a7-0x004ee6b0` padding.
- [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md) records the confirmed core `InventoryPane2` method/helper island from the first modeled function at `0x004ee6b0` through `0x004ef3fc`.
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) records the tail rectangle/hit-test helpers, tiny thunk-like bodies, and scalar deleting destructor. The interleaved [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) remains excluded from `InventoryPane2` ownership.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the broader inventory executable neighborhood, source-split map, and the three interleaved BackPane packet helpers that should not be treated as inventory-owned methods.
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records the `InventoryPane2` primary, secondary, and tertiary vtables at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0`.
- IDA MCP confirms `OnPaint`, `OnMouseEvent`, and scalar deleting destructor boundaries in the existing aggregate evidence.
- 2026-06-10 A002 live IDA MCP rechecked the constructor boundary: IDA still reports no function or xrefs at `0x004ee650`, bytes `0x004ee643-0x004ee650` and `0x004ee6a7-0x004ee6b0` are `0xcc` padding, and the vtable data refs at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0` include stores from the raw constructor, `sub_4EE6B0`, and `sub_4EFA40`.

## Reconstruction Notes

- `InventoryPane2` is marked reconstructable because the class role, likely inventory source file, exact raw constructor, confirmed method/helper islands, and vtable data are now documented with stable UID-linked evidence.
- `RECONSTRUCTION_CPP CODE` remains blank. The final C++ still needs live caller/reachability resolution for the raw constructor, final field names, helper names, item lookup/packet helper ownership, and selector-notification layout to be audited.
- Do not treat the interleaved [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), or [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) helper pages as `InventoryPane2` methods.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md)
- [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md)
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md)
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md)
- [UID:00006R][InventoryPane](by-class/InventoryPane.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)

## Changes

- 2026-06-10 A002 constructor-child/gate refresh:
  - Raised `78/82` to `82/86`, cleared the below-gate `AUTOGEN_PARENT_UID:0000KA`, added exact raw constructor child [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), and replaced the stale unresolved-constructor boundary text.
  - Evidence: live IDA MCP reconfirmed no function/xrefs at `0x004ee650`, raw constructor bytes through `0x004ee6a7`, `0xcc` padding before `0x004ee650` and before `0x004ee6b0`, and vtable stores from the raw constructor, setup helper, and scalar deleting destructor. Class/file attachment remains blank because the class and file parent do not clear the strict `85/85` gate.
- 2026-06-02: Raised `68/76` to `78/82`, marked reconstructable, and attached to [UID:0000KA][InventoryPane](by-file/InventoryPane.md). Added exact children [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md), companion vtable-data evidence, source-placement evidence, and reconstruction blockers. C++ remains blank because constructor/setup and field/helper names are not final.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: alternate compact inventory-pane behavior, core draw/key/mouse/hit-test/destructor methods, and source placement are documented, but the constructor boundary remains unresolved and tracked as a data issue. Evidence: `InventoryPanes`, IDA-confirmed method boundaries, and no-function note for `0x004ee650`.
