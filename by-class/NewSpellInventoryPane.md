*** UID:00009A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSpellInventoryPane

## Status

- Confidence: strong for behavior and inventory-module placement.
- Likely source file: [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), under the [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) umbrella
- Address range: [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSpellInventoryPane.cpp`

## Class Purpose

`NewSpellInventoryPane` is the newer spell inventory pane. It owns an embedded [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), rebuilds the visible learned-spell list, supports collapsed and expanded row counts, handles hover/drag/quick-cast/swap interactions, and dispatches spells to direct-cast or input-pane flows.

## Method Families

| Family | Representative methods | Role |
| --- | --- | --- |
| Lifecycle/layout | `NewSpellInventoryPane`, `OnRefresh`, `OnResize`, `SetBoundsForMode`, `OnLayout`, `OnHide`, `ScalarDeletingDestructor` | Creates child scrollbar and keeps collapsed/expanded layout synchronized. |
| Spell list model | `RebuildSpellList`, `ResolveVisibleSpellSlot`, `HitTestSpellRow` | Scans player spell data and maps visible rows to real spell slots. |
| Rendering | `OnPaint`, `GetButtonRect` | Draws the spell list, selection highlight, key labels, names, and expand toggle. |
| Input/timers | `OnKeyEvent`, `OnMouseEvent`, `OnTimerEvent`, `OnScrollPositionChanged` | Handles page keys, mouse interactions, scroll repeat, and scrollbar sync. |
| Spell activation | `CastSpell`, `StopSound`, `ToggleExpandedMode` | Dispatches spell use, stops spell sound, and toggles expanded display. |

## Evidence Notes

- IDA MCP confirms `0x0057cf70-0x0057d03f`, `0x0057d430-0x0057d8c4`, `0x0057d9c0-0x0057e18f`, and `0x0057e2d0-0x0057e56d`.
- Wave3 notes describe player spell data at `g_pPlayerData + 0x13a834`, stride `0x148`, with normal 13-row and expanded 26-row modes.
- `CastSpell` calls several spell input/cast helpers, so exact spell-type names should wait for a spell packet/input-pane pass.

## Cross-References

- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite class purpose, method-family, evidence, and inventory/source-placement notes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: the page documents lifecycle/layout, spell-list model, rendering, input/timer behavior, activation flow, row counts, and player-spell data leads; remaining gaps are detailed field layout and exact spell-type/input helper naming.
