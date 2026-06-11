*** UID:0000KA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InventoryPane

## Status

- Confidence: strong for inventory UI module ownership, `ui/inventory/` placement, and the exact `InventoryPane2` raw constructor split; medium-high for exact legacy/new file split and final helper/field names.
- Proposed module folder: `ui/inventory/`
- Candidate files: `ui/inventory/InventoryPane.cpp`, `ui/inventory/NewInventoryPane.cpp`, and `ui/inventory/ScrollInventoryPane.cpp`
- Current generated sources: `class_InventoryPane.cpp`, `class_InventoryPane2.cpp`, `class_NewInventoryPane.cpp`, and `class_ScrollInventoryPane.cpp`.
- Evidence basis: targeted IDA MCP boundary checks on 2026-05-23, the 2026-06-01 inventory aggregate refresh, companion vtable/resource data, exact [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md), and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) child split.

## Hypothesis

The item inventory panes form a coherent gameplay UI subsystem. They should not be grouped with generic control panes, item image libraries, or cash-shop item catalog code.

The likely original structure had separate source files for the legacy inventory and newer inventory panel:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/ScrollInventoryPane.cpp
```

An alternate compact layout is a single `ui/inventory/InventoryPane.cpp` containing the old, alternate, and new variants plus the private scrollbar. The generated one-class files should be treated as reconstruction staging, not final original layout evidence.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `InventoryPane` | `0x004ea130-0x004efb41` | `class_InventoryPane.cpp` | Legacy item inventory pane with list/grid view, paging, item activation, drag packet, and tooltip message handling. |
| `NewInventoryPane` | `0x004eb420-0x004efbb6` | `class_NewInventoryPane.cpp` | Updated item inventory pane with scrollbar, list/grid layouts, tab buttons, hover, drag/drop, and compact/expanded state. |
| `InventoryPane2` | `0x004ee650-0x004efa94`; exact confirmed children are [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md), and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) | `class_InventoryPane2.cpp` | Alternate smaller inventory pane with dual list/grid layout and arrow buttons; the raw constructor is exact but remains below the assignment/code gates, and BackPane V3 is interleaved between the core and tail children. |
| `ScrollInventoryPane` | `0x00563260-0x0056470c` | `class_ScrollInventoryPane.cpp` | Private/companion scrollbar used by the newer item inventory UI. |

## Behavior Summary

- Legacy inventory draws up to 15 entries per page in list or grid mode and responds to Page Up/Page Down.
- New inventory supports list and 3-column grid layouts, a child scrollbar, slot filtering, hover highlighting, drag/drop, context menu/right-click paths, sound stopping, and view-mode toggling.
- `InventoryPane2` appears to be an alternate compact visual style with fixed button rectangles and a 9-slot grid/list hit-test path.
- `ScrollInventoryPane` owns the EPF-backed scrollbar track, thumb, arrow regions, timer repeat, and highlight state.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x004ea130-0x004ea202`, `0x004ea2a0-0x004ea945`, `0x004ea9d0-0x004eac88`, and `0x004eac90-0x004eae02` for legacy inventory construction, paint, mouse, and message handling.
- `0x004eb420-0x004eb510`, `0x004ebb20-0x004ec913`, `0x004ecb50-0x004ed9c4`, and `0x004ee230-0x004ee3b7` for the updated inventory constructor, paint, mouse, and hit test.
- `0x004ee6f0-0x004eee5c`, `0x004eeee0-0x004ef27a`, and `0x004efa40-0x004efa95` for the alternate inventory render/mouse/delete paths. [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md), and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) record the exact confirmed InventoryPane2 constructor/method/helper islands while excluding the interleaved BackPane V3 helper.
- `0x00563260-0x00563301`, `0x005636a0-0x00563d80`, and `0x005640a0-0x00564327` for the item inventory scrollbar.

IDA still reports no function or direct xrefs at the raw `InventoryPane2` constructor start `0x004ee650`, but [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md) now documents the exact constructor-shaped bytes and padding. IDA also reports no function at `ScrollInventoryPane::ResetScrollState` start `0x005646b0`; that remains a separate data issue.

## File-Split Guidance

Use these working files for future migration planning:

```text
ui/inventory/InventoryPane.cpp
ui/inventory/NewInventoryPane.cpp
ui/inventory/ScrollInventoryPane.cpp
```

Keep [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) separate. Item inventory and spell inventory share UI patterns and scrollbar code shape, but their data sources, activation paths, and input panes are different enough to justify separate original files.

## Cross-References

- [UID:00006R][InventoryPane](by-class/InventoryPane.md)
- [UID:00006S][InventoryPane2](by-class/InventoryPane2.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)
- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md)
- [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md)
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)

## Changes

- 2026-06-10 A002 constructor-child/gate refresh:
  - Raised `82/82` to `84/84`, linked exact raw constructor child [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), and updated the `InventoryPane2` evidence/gate text so the constructor is no longer described as an unsplit unresolved boundary.
  - Evidence: live IDA MCP reconfirmed no function/xrefs at `0x004ee650`, exact constructor bytes through `0x004ee6a7`, `0xcc` padding before `0x004ee650` and before `0x004ee6b0`, and `InventoryPane2` vtable stores from the raw constructor, setup helper, and scalar deleting destructor. The file remains below `85/85` because the final old/new/alternate source split and many helper/field names are still provisional.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/inventory/` and raised `80/76` to `82/82`.
  - Before: the page text proposed `ui/inventory/`, but validator metadata had no projected path and confidence stayed below the parent-attachment threshold.
  - After: projected path and confidence now match the written source-placement evidence; [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) record the exact confirmed `InventoryPane2` method/helper children while preserving the unresolved constructor-start caveat and excluding the interleaved BackPane helper.
  - Evidence: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records IDA function inventory and source-split ownership; [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records inventory vtables and resource strings; [UID:0002SU][0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) split the alternate-pane method islands.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: legacy/new/alternate inventory pane roles, scrollbar companion, behavior summary, representative IDA boundaries, and file-split guidance are documented; confidence is capped by exact legacy/new split, raw starts, and Wave3 data issues.
