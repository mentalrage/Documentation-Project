*** UID:0000LS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewInventoryPane

## Status

- Confidence: strong for newer item-inventory behavior, `NexusTK/ui/inventory/` placement, and companion scrollbar relationship; medium-high for whether the original source kept the scrollbar in a separate file.
- Proposed module: `ui/inventory/NewInventoryPane.cpp`
- Companion module candidate: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) / `ui/inventory/ScrollInventoryPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_NewInventoryPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks on 2026-05-24.
- Autogen root: `auto-generated/NexusTK/ui/inventory/NewInventoryPane.cpp`

## File Role

`NewInventoryPane.cpp` should own the updated item inventory pane: filtered visible slot list, list/grid layouts, tab buttons, hover/highlight state, drag/drop and right-click item actions, scroll-wheel handling, sound stop behavior, and view-mode toggling.

The embedded [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) is a private companion. IDA-backed documentation currently shows its constructor `0x00563260` called only from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`, so folding it into this source is plausible if the original project did not keep a separate scrollbar file.

## Source Split Decision

Use `ui/inventory/NewInventoryPane.cpp` as the primary source root for the newer item-inventory pane. Keep [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) as a reviewed companion root for now, but treat it as private to this pane family rather than generic scrollbar UI. The current split should be:

```text
ui/inventory/NewInventoryPane.cpp
ui/inventory/InventoryScrollPane.cpp   // companion; may fold into NewInventoryPane.cpp later
```

Do not merge this page into the broad [UID:0000KA][InventoryPane](by-file/InventoryPane.md) root just because the executable ranges are interleaved. [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) is an address-neighborhood aggregate over legacy inventory, new inventory, alternate inventory, and three BackPane helper children; exact source ownership should use the child ranges and class/file pages instead of the aggregate alone.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md) | `0x004eb420-0x004efbb6` | Newer item inventory pane and item-slot interaction owner. |
| [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) | `0x00563260-0x0056470c` | Private/companion scrollbar; keep as `ScrollInventoryPane.cpp` only if final layout preserves inventory-specific scrollbars as separate files. |
| [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) | `0x0061c7e4`, `0x0061c834`, `0x0061c864` | `NewInventoryPane` primary/secondary/tertiary vtables; source-declared/generated-binary data from class declarations. |

## Key Method Families

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x004eb420-0x004ebb1f` | construction, refresh, resize, slot-list rebuild, scrollbar sync, layout/show | Constructs the pane, constructs `ScrollInventoryPane`, rebuilds visible inventory slots, and keeps the child scrollbar range/position synchronized. |
| `0x004ebb20-0x004ec913` | paint | Draws item slots, item icons, text/count overlays, view controls, and pane chrome. |
| `0x004ec920-0x004ed9c4` | keyboard/mouse input | Handles paging, selection, drag/drop, right-click context behavior, hover help, and scroll-wheel movement. |
| `0x004edb70-0x004ee5df` | scroll, hit-test, layout helper, view/audio helpers | Maps visual to physical slots, resolves button/slot rectangles, stops active item sound, and toggles list/grid mode. |
| `0x004efb50-0x004efbb6` | scalar deleting destructor | Dismisses child scrollbar and tears down the `PanelPane` base. |

## Evidence Notes

- IDA MCP confirms `0x004eb420` as a `0xf0`-byte constructor, `0x004ebb20` as a `0xdf3`-byte paint method, and `0x004ecb50` as a `0xe74`-byte mouse handler.
- IDA MCP `callees` for `0x004eb420` include `0x00563260` (`ScrollInventoryPane` constructor) and `0x00563400` (scrollbar enable/activation helper).
- IDA MCP `callers` for `0x00563260` show only `0x004eb4e4` inside the new item inventory constructor.
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md) already projects inventory UI source to `NexusTK/ui/inventory/` and lists `NewInventoryPane.cpp` as a likely split file.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the same `NewInventoryPane` subrange and the surrounding inventory source-split decision.
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records the `NewInventoryPane` vtables and inventory resource strings.
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) now records the stronger owner-chain rationale for the scrollbar aggregate: `InventoryScrollPane` is reviewed as `84/80`, the `ScrollInventoryPane` class is attached at `80/80`, the reset raw child is split, and the final standalone-versus-folded source decision remains the main blocker.
- The corrected read-only data page keeps the `NewInventoryPane` vtable island at `0x0061c7e4`, `0x0061c834`, and `0x0061c864` inside the inventory data span and excludes the following `KeySpeedMgr` locator at `0x0061c9c4`.
- Generated `class_NewInventoryPane.cpp` still has low automated fidelity and several unresolved dependency labels, so use the address ranges and docs rather than generated local type names for migration.

## Score Rationale

- Completion is `82` because the page has a valid projected source path, file-role summary, method-family ranges, companion scrollbar ownership, a source-split decision, aggregate boundary caveats, and links to executable, scrollbar, and read-only data evidence.
- Confidence is `82` because the `ui/inventory/` placement matches [UID:0000KA][InventoryPane](by-file/InventoryPane.md), IDA-backed method ranges, the one-caller scrollbar constructor evidence, the strengthened scrollbar aggregate owner chain, and the corrected inventory vtable/resource range. It stays below final confidence because exact child method pages for `NewInventoryPane` are still mostly unsplit, generated method names are not final, and `InventoryScrollPane.cpp` may later fold into this file.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md)
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents pane role, companion scrollbar, method-family ranges, and IDA constructor/caller checks, but generated source has low fidelity and exact split from `InventoryPane`/scrollbar code remains open.
- 2026-06-03 projected-path and confidence pass:
  - Before: the page text proposed `ui/inventory/NewInventoryPane.cpp`, but `PROPOSED_RECONSTRUCTION_PATH` was blank and the validator reported this by-file root as an autogen error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/"`, score `80/80`, and explicit autogen-root/score-rationale notes.
  - Summary/evidence: [UID:0000KA][InventoryPane](by-file/InventoryPane.md), [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md), [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md), and [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) support the folder and class/file relationship while leaving final C++ and private-scrollbar split unresolved.
- 2026-06-07 A006 source-split and evidence refresh:
  - Before: the page had the projected path and core method ranges but did not explicitly describe how to use the `InventoryScrollPane` companion root or the mixed inventory aggregate when planning migration.
  - Changed to: score `82/82`, added a source-split decision, added the corrected `NewInventoryPane` vtable/read-only data row, and tied the score rationale to the strengthened scrollbar aggregate owner chain.
  - Summary/evidence: existing UID-linked pages now record the `NewInventoryPane` executable range, the one-caller scrollbar constructor relationship, the reviewed `InventoryScrollPane` companion source root, the corrected inventory read-only data span, and the aggregate warning that BackPane helper children are physically interleaved but not inventory-owned.
