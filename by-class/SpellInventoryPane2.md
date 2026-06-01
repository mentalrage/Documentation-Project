*** UID:0000DO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellInventoryPane2

## Status

- Confidence: strong for alternate spell-pane behavior, medium for constructor boundary.
- Likely source file: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) or `ui/inventory/SpellInventoryPane.cpp`
- Address range: [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellInventoryPane2.cpp`

## Class Purpose

`SpellInventoryPane2` is an alternate grid/page spell inventory pane. It displays spell icons and names, supports page buttons and Page Up/Page Down keys, and handles spell selection/info clicks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellInventoryPane2` | `0x0057ea60-0x0057ea9f` | Wave3-projected constructor; IDA does not currently define a function at this start. |
| `ResetPage` | `0x0057eac0-0x0057ead4` | Resets to first page. |
| `OnPaint` | `0x0057eb00-0x0057eda3` | Renders up to 13 spell entries with icons and names. |
| `OnKeyDown` | `0x0057edb0-0x0057ee2b` | Handles Page Up/Page Down. |
| `OnMouseClick` | `0x0057ee30-0x0057eff6` | Handles page buttons and spell selection/info. |
| `~SpellInventoryPane2` | `0x0057f640-0x0057f694` | Destroys `PanelPane` base and conditionally frees storage. |

## Evidence Notes

- IDA MCP confirms paint, click, and destructor boundaries.
- IDA reports no function at `0x0057ea60`; previous function is `0x0057e9d0-0x0057ea57`, next function is `0x0057eaa0-0x0057eabf`. This is tracked in [wave3_data_issues](../wave3_data_issues.md).

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `74`.
- Evidence: the page documents alternate spell-pane behavior, file/range ownership, paint/key/click/destructor methods, and the projected-constructor caveat; confidence remains capped because IDA does not define the generated constructor start.
