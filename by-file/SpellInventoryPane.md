*** UID:0000O1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SpellInventoryPane

## Status

- Confidence: strong for spell inventory UI module ownership, medium for exact legacy/new split.
- Proposed module folder: `ui/inventory/`
- Candidate files: `ui/inventory/SpellInventoryPane.cpp`, `ui/inventory/NewSpellInventoryPane.cpp`, and `ui/inventory/ScrollSpellInventoryPane.cpp`
- Current generated sources: `class_SpellInventoryPane.cpp`, `class_SpellInventoryPane2.cpp`, `class_NewSpellInventoryPane.cpp`, and `class_ScrollSpellInventoryPane.cpp`.
- Evidence basis: Wave3 metadata and targeted IDA MCP boundary checks on 2026-05-23.

## Hypothesis

The spell inventory panes are the spell-side counterpart to the item inventory module. They display learned spells from player data, handle page or scroll navigation, and dispatch spell activation to direct-cast paths or spell-specific input panes.

The likely original structure was:

```text
ui/inventory/SpellInventoryPane.cpp
ui/inventory/NewSpellInventoryPane.cpp
ui/inventory/ScrollSpellInventoryPane.cpp
```

The exact split between old/new files is still open, but these classes belong under inventory UI, not under generic controls or spell-effect rendering.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `SpellInventoryPane` | `0x0057c2d0-0x0057f741` | `class_SpellInventoryPane.cpp` | Legacy spell inventory pane with page display, [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md), mouse selection, and close-message handling. |
| `NewSpellInventoryPane` | `0x0057cf70-0x0057f636` | `class_NewSpellInventoryPane.cpp` | New spell inventory pane with scrollbar, collapsed/expanded modes, hover, quick-cast, swap, and type-based cast dispatch. |
| `SpellInventoryPane2` | `0x0057ea60-0x0057f694` | `class_SpellInventoryPane2.cpp` | Alternate grid/page spell inventory variant. |
| `ScrollSpellInventoryPane` | `0x0055f450-0x005608fc` | `class_ScrollSpellInventoryPane.cpp` | Private/companion scrollbar for spell inventory panes. |

## Behavior Summary

- Legacy spell inventory displays up to 13 spells per page and uses Page Up/Page Down plus scroll buttons.
- New spell inventory scans the global spell table, supports normal 13-row and expanded 26-row modes, and uses a child scrollbar.
- `CastSpell` dispatches spell slots through different input panes or direct-cast paths based on the spell type record.
- Scrollbar code mirrors item scrollbar behavior but has separate addresses, owner classes, and helper names.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x0057c2d0-0x0057c39f`, `0x0057c450-0x0057c710`, and `0x0057c790-0x0057c979` for legacy spell inventory construction, draw, and mouse handling.
- `0x0057cf70-0x0057d03f`, `0x0057d430-0x0057d8c4`, `0x0057d9c0-0x0057e18f`, and `0x0057e2d0-0x0057e56d` for the new spell inventory constructor, paint, mouse, and cast dispatcher.
- `0x0057eb00-0x0057eda4`, `0x0057ee30-0x0057eff7`, and `0x0057f640-0x0057f695` for the alternate spell inventory render, click, and destructor paths.
- `0x0055f450-0x0055f4f1`, `0x0055f890-0x0055ff70`, and `0x00560290-0x00560517` for the spell inventory scrollbar.

IDA reports no function at Wave3's `SpellInventoryPane2::SpellInventoryPane2` start `0x0057ea60` and no function at `ScrollSpellInventoryPane::ResetScrollState` start `0x005608a0`; both are tracked in [wave3_data_issues](../wave3_data_issues.md).

## File-Split Guidance

Use these working files for future migration planning:

```text
ui/inventory/SpellInventoryPane.cpp
ui/inventory/NewSpellInventoryPane.cpp
ui/inventory/ScrollSpellInventoryPane.cpp
```

Keep item inventory source separate from spell inventory source. The controls are visually similar, but spell inventory reads spell-table records and dispatches cast/input-pane behavior rather than item use, tooltip, or drag-transfer packets.

## Cross-References

- [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md)
- [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `78`.
  - Evidence: document covers legacy/new/alternate spell inventory roles, proposed source split, behavior summary, IDA boundary checks, file-split guidance, and cross-references; confidence remains capped by unresolved exact legacy/new split and raw constructor/reset starts.
