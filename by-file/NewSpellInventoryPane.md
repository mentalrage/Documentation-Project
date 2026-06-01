*** UID:0000LU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewSpellInventoryPane

## Status

- Confidence: strong for newer spell-inventory behavior; medium for exact split from [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md).
- Proposed module: `ui/inventory/NewSpellInventoryPane.cpp`
- Companion module candidate: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) / `ui/inventory/ScrollSpellInventoryPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_NewSpellInventoryPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks on 2026-05-24.

## File Role

`NewSpellInventoryPane.cpp` should own the newer spell inventory pane with embedded spell scrollbar, learned-spell list rebuild, collapsed/expanded row modes, hover/drag/quick-cast/swap interactions, sound stop behavior, and dispatch into direct-cast or spell-specific input panes.

The embedded [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) is a private companion. IDA currently shows its constructor `0x0055f450` called only from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`, so folding it into this source is plausible if the original project did not keep a separate scrollbar file.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md) | `0x0057cf70-0x0057f636` | Newer spell inventory pane and spell activation owner. |
| [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) | `0x0055f450-0x005608fc` | Private/companion scrollbar; keep as a separate file only if final layout preserves inventory-specific scrollbars as separate modules. |

## Key Method Families

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0057cf70-0x0057d42f` | construction, refresh, resize, mode bounds, spell-list rebuild, scrollbar sync, layout/hide | Constructs and activates the child spell scrollbar, scans learned spell data, and keeps the visible row model synchronized. |
| `0x0057d430-0x0057d8c4` | paint | Draws the spell inventory list, selection/hover state, key labels, names, and expand toggle. |
| `0x0057d8d0-0x0057e18f` | keyboard/mouse input | Handles page keys, row interactions, quick-cast/swap gestures, hover state, and scrollbar movement. |
| `0x0057e1e0-0x0057e56d` | timer and cast dispatch | Handles repeat/timer behavior and sends the selected spell into direct-cast or spell-input-pane flows. |
| `0x0057e690-0x0057ea1f` | button, hit-test, visible-slot, audio, expand helpers | Resolves UI rectangles/rows, stops spell sound, and toggles expanded mode. |
| `0x0057f5d0-0x0057f636` | scalar deleting destructor | Tears down child pane/base state. |

## Evidence Notes

- IDA MCP confirms `0x0057cf70` as a `0xcf`-byte constructor, `0x0057d430` as a `0x494`-byte paint method, and `0x0057d9c0` as a `0x7cf`-byte mouse handler.
- IDA MCP `callees` for `0x0057cf70` include `0x0055f450` (`ScrollSpellInventoryPane` constructor) and `0x0055f5f0` (scrollbar activation helper).
- IDA MCP `callers` for `0x0055f450` show only `0x0057d013` inside the new spell inventory constructor.
- Generated `class_NewSpellInventoryPane.cpp` is useful for behavior but should not be used alone for final spell-type/input-pane naming.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents pane role, companion scrollbar, method-family ranges, and IDA constructor/caller checks, but final spell-type/input-pane naming and exact split from older spell inventory code remain unresolved.
