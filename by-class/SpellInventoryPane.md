*** UID:0000DN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInventoryPane

## Status

- Confidence: strong for behavior and inventory-module placement.
- Likely source file: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- Address range: [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellInventoryPane.cpp`

## Class Purpose

`SpellInventoryPane` is the legacy player spell inventory pane. It displays up to 13 learned spells per page, handles page navigation and spell slot clicks, creates spell UI effects, and closes itself on relevant message commands.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellInventoryPane` | `0x0057c2d0-0x0057c39e` | Initializes `PanelPane`, vtables, page index, and spell effect interface. |
| `~SpellInventoryPane` | `0x0057c3a0-0x0057c400` | Resets vtables and marks spell effects for cleanup. |
| `ResetPage` | `0x0057c410-0x0057c424` | Resets page index to zero and refreshes display. |
| `DrawSpells` | `0x0057c450-0x0057c70f` | Draws up to 13 spell entries with key bindings and scroll buttons. |
| `OnKeyDown` | `0x0057c710-0x0057c78b` | Handles Page Up/Page Down. |
| `OnMouseDown` | `0x0057c790-0x0057c978` | Handles scroll button navigation and spell slot selection. |
| `OnMessage` | `0x0057c980-0x0057c9a7` | Handles close/hide message commands. |
| `ScalarDeletingDestructor` | `0x0057f6a0-0x0057f741` | Runs cleanup and conditional free. |

## Evidence Notes

- IDA MCP confirms the constructor, draw, mouse, and scalar deleting destructor boundaries.
- Wave3 notes place spell records in player data with stride `0x148` and up to 52 spell slots.
- This is spell inventory UI, not spell rendering or effect-object code.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)
- [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `86`.
- Evidence: the page documents pane behavior, source placement, main range, constructor/destructor/reset/draw/key/mouse/message/destructor methods, player spell-slot model, and sibling relationships; remaining completion gap is deeper field naming and source-ready C++.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the documented spell inventory constructor, destructor, reset, draw, keyboard, mouse, message, and scalar deleting destructor anchors from `0x0057c2d0` through `0x0057f6a0`; both class (`84/86`) and parent file (`82/82`) meet the 80/80 gate.
