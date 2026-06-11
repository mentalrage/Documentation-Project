*** UID:00006R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InventoryPane

## Status

- Confidence: strong for behavior and inventory-module placement.
- Likely source file: [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_InventoryPane.cpp`

## Class Purpose

`InventoryPane` is the legacy player item inventory pane. It renders item slots in list or grid mode, pages through visible inventory entries, handles mouse item activation and drag-transfer packets, and displays server-provided item tooltip text through a help pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InventoryPane` | `0x004ea130-0x004ea201` | Initializes `PanelPane`, vtables, scroll/view state, and item effect interface. |
| `~InventoryPane` | `0x004ea210-0x004ea270` | Resets vtables and marks item effects for cleanup. |
| `OnPaint` | `0x004ea2a0-0x004ea944` | Draws inventory background, items, labels, and navigation/view buttons. |
| `OnKeyDown` | `0x004ea950-0x004ea9cb` | Handles Page Up/Page Down. |
| `OnMouseInput` | `0x004ea9d0-0x004eac87` | Handles navigation buttons, item activation, double-click policy, and drag opcode `0x66`. |
| `OnServerMessage` | `0x004eac90-0x004eae01` | Handles close opcodes and item tooltip text. |
| `GetButtonRect` | `0x004eb050-0x004eb125` | Returns navigation/view button rectangles. |
| `HitTestSlot` | `0x004eb2b0-0x004eb381` | Hit-tests 15 visible item slots. |
| `ScalarDeletingDestructor` | `0x004efaa0-0x004efb41` | Runs cleanup and conditional free. |

## Evidence Notes

- IDA MCP confirms the constructor, paint, mouse, message, button rect, and destructor boundaries.
- Wave3 notes identify `g_pConfig + 0x28de5a` as the single-click vs double-click activation flag.
- This class is item inventory UI and should not be merged into item image library code.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:00006S][InventoryPane2](by-class/InventoryPane2.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed inventory-pane methods at `0x004ea130`, `0x004ea210`, `0x004ea2a0`, `0x004ea950`, `0x004ea9d0`, `0x004eac90`, `0x004eb050`, `0x004eb2b0`, and `0x004efaa0`. Left `AUTOGEN_PARENT_UID` blank because this class is still below the 80 completion attachment gate.
- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: legacy inventory-pane role, constructor/destructor, paint/key/mouse/server-message behavior, button/slot hit-tests, drag opcode, config flag, and module placement are documented with strong confidence; remaining work is deeper layout naming and final C++ reconstruction. Evidence: `InventoryPanes`, `NewInventoryPane`, `InventoryPane2`, and IDA-confirmed method boundaries.
