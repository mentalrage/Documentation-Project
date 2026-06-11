*** UID:00005Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GeneralPurposePanel

## Status

- Confidence: strong for class behavior and helper-owner cleanup; medium for final member names.
- Likely source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- Current recovered file: `source-3/simroot_v2/class_GeneralPurposePanel.cpp`

## Functionality

`GeneralPurposePanel` is the main in-game side-panel shell. It constructs and stores seven child panes, tracks the active pane id, switches the visible child pane, and exposes child lookup/active-child helpers.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x004b83d0-0x004b857d` | Constructs self look, user look, inventory, spell inventory, group, collection, and option child panes; sets `g_pGeneralPurposePanel`. |
| destructor | `0x004b8580-0x004b85e2` | Registers/cleans all seven child panes and clears the singleton. |
| child lookup | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) | Returns child by index with EPF/legacy child-count bounds; stale generated owner was `SpellOneArgInputPane`. |
| active-child helpers | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) | Return or refresh the active child from the same child array and active-index slot. |
| `SwitchActiveTab` | [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) | Hides/deactivates the old child and lays out/activates the new child; stale generated owner was `SpellOneArgInputPane`. |
| scalar deleting destructor | `0x004b8b40-0x004b8bd3` | Deleting destructor wrapper; 2026-05-28 boundary check shows `0x004b8bd2` is the final byte of `retn 4`. |

## Notes

Generated constructor labels the children clearly, and live IDA evidence now ties the accessor/switch helper island back to this same seven-child layout. Some generated Wave3 ownership remains stale, but documentation should use the IDA-confirmed `0x004b83d0-0x004b8822` island as the current source-layout anchor. The singleton backing this shell is [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md).

## Child Index Map

The constructor stores child panes in this order. The active child index is read by macro editing, item/spell input panes, and side-panel refresh helpers:

| Index | Child |
| --- | --- |
| `0` | self-look pane |
| `1` | user-look/profile pane |
| `2` | inventory pane |
| `3` | spell inventory pane |
| `4` | group pane |
| `5` | collection pane |
| `6` | option pane |

This mapping is important for [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md): the integrated macro editor writes state `2` / `.usr` `S` from child index `3`, and state `3` / `.usr` `I` from child index `2`.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:0000A4][PanelPane](by-class/PanelPane.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: side-panel shell role, seven-child layout, singleton, constructor/destructor, child accessors, active-tab switch, child index map, and macro-editor implications are documented; helper ownership cleanup remains medium-confidence. Evidence: `0x004b83d0-0x004b8bd3` memory page, child accessor/switch pages, `g_pGeneralPurposePanel`, and child index map.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `78/82`, below the 80/80 parent-attachment gate, even though [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b83d0`, `0x004b8580`, `0x004b85f0`, `0x004b8650`, and `0x004b8b40`; current `callers` confirms constructor references from `InitializeMainUiGraph` at `0x004f7ff7` and `0x004f8835`.
- 2026-06-06: Raised to `82/86` and attached the class to [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). Live IDA MCP reconfirmed the constructor/destructor starts, the three child accessor helpers, `SwitchActiveTab`, broad side-panel caller sets, and the matching child-array/active-index behavior; final field names and exact source declarations remain below final-code certainty.
