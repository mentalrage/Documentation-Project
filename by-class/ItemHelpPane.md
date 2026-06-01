*** UID:00006U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemHelpPane

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), possibly split as `ui/controls/ItemHelpPane.cpp`
- Address range: [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md), support helpers in [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_ItemHelpPane.cpp`
- Confidence: strong for behavior; medium for exact source-file split.

## Class Purpose

`ItemHelpPane` is the rich item tooltip pane. It identifies inventory, equipment, or generic item contexts, copies display names, pulls item metadata through `MetaMan`, computes price/stat/requirement lines, sizes the tooltip, clamps it to parent and screen bounds, and draws formatted item help text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ItemHelpPane` | `0x004c82d0-0x004c8b13` | Constructs item tooltip, selects item context, populates item data, sizes/clamps pane, and schedules timer. |
| `~ItemHelpPane` | `0x004c8b20-0x004c8bc2` | Frees allocated stat/value strings, clears [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md), and tears down base pane. |
| `OnPaintFrame` | `0x004c8bd0-0x004ccba0` | Draws item name, description, buy/sell price, stats, owner, protection count, and class/tier requirements. |
| `OnTimerEvent` | `0x004ccc20-0x004ccc3a` | Expires tooltip on timer id `0`. |
| `OnMouseEvent` | `0x004ccc40-0x004ccc7e` | Repaints and cancels timer for mouse-down/double-click style events. |
| `DismissItemHelp` | `0x004ccc80-0x004ccc95` | Closes the active item help singleton if present. |
| `PopulateItemData` | `0x004ccca0-0x004ce0f6` | Loads metadata rows and formats tooltip fields. |
| `CountTextLines` | `0x004ce100-0x004ce160` | Counts wrapped line rows for a given width. |
| support helpers | [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) | Includes a UTF-16 SSO string comparison helper called from `PopulateItemData`, plus neighboring vector/singleton cleanup support shared with the HelpPanes family. |
| `ScalarDeletingDestructor` | `0x004ce430-0x004ce4fb` | Destructor wrapper and optional storage delete. |

## Evidence Notes

- IDA confirms all listed function starts and sizes.
- IDA xrefs to the constructor include callers at `0x004ed957`, `0x0051b383`, `0x0051f7e3`, and `0x00568e84`.
- `PopulateItemData` uses `MetaMan` lookup helpers but remains item-tooltip presentation code.
- `DismissItemHelp` references the active singleton [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md).
- 2026-05-26 IDA MCP storage check confirms `g_pItemHelpPane` as a 4-byte `.data` singleton with 20 data references.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md): `0x004ce160` is called from `PopulateItemData`, and `0x004ce310` is the unwind helper that clears `g_pItemHelpPane`.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:0000R9][g_pItemHelpPane](by-global/g_pItemHelpPane.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `86/82`. Summary: rich item-tooltip responsibility, construction/destruction/painting/timer/mouse/dismiss/populate/count helpers, singleton, MetaMan usage, support helper split, storage checks, and caller evidence are documented in detail; confidence remains limited by exact source-file split within HelpPanes. Evidence: `ItemHelpPaneCore`, `HelpTooltipSupportHelpers`, `HelpTooltipDestructorThunks`, `g_pItemHelpPane`, `ItemDialogs`, and `InventoryPane`.
