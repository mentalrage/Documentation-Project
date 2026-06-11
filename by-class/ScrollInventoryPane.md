*** UID:0000CK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane

## Status

- Confidence: strong for scrollbar behavior, constructor ownership, layout/vtable anchors, and the `NewInventoryPane` caller; medium for final standalone-vs-folded source split and one reset-helper boundary.
- Likely source file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), with a possible final fold into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). `InventoryScrollPane` is the current by-file parent because it records the matching `ui/inventory/` projected path, dedicated scrollbar file hypothesis, and 80+ parent confidence.
- Address range: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- Layout: [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- Vtables: [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Class Purpose

`ScrollInventoryPane` is the EPF-backed scrollbar pane used by the newer item inventory UI. It manages scroll range, current position, orientation, highlighted region, drag tracking, auto-repeat timers, and scrollbar painting.

## Autogen Status

- Parent file: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- Reconstructable: `TRUE`
- C++ emission: intentionally blank until the standalone `InventoryScrollPane.cpp` versus private `NewInventoryPane.cpp` source split and the raw reset-helper provenance are resolved.

The parent assignment is deliberate but not final-source proof. [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) is the current durable source owner because it records the dedicated `ui/inventory/` scrollbar-file hypothesis, while [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) remains the only documented constructor caller and therefore the main fold candidate.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollInventoryPane` | `0x00563260-0x00563301` | Constructs scrollbar pane with vertical or horizontal orientation. |
| `SetMaxRange` | `0x00563370-0x005633ca` | Clamps max range and current position. |
| `SetScrollPosition` | `0x005633d0-0x005633f6` | Updates scroll position and invalidates. |
| `EnableScrollbar` | `0x00563400-0x00563419` | Enables the control and invalidates. |
| `OnMouseEvent` | `0x00563460-0x00563640` | Handles drag and click interactions. |
| `OnTimerEvent` | `0x00563660-0x00563692` | Handles held-button auto-scroll. |
| `OnPaint` | `0x005636a0-0x00563d7f` | Paints track, thumb, and arrows with EPF assets. |
| `GetScrollbarRegionRect` | `0x005640a0-0x00564326` | Returns rectangles for arrow, track, and thumb parts. |
| `SetHighlightRegion` | `0x00564330-0x0056439f` | Updates highlighted region and invalidates. |
| `UpdateFromDrag` candidate | [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) | Recomputes the scroll position from drag/click geometry and notifies the owning inventory pane. |
| `ResetScrollState` candidate | [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | Raw method-shaped reset helper; IDA does not currently define a function at this start. |

## Evidence Notes

- IDA MCP confirms constructor, paint, and region-rect functions.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x00563260` is only directly called from `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`.
- IDA MCP lookup confirms the activation helper `0x00563400` as a real `0x1a`-byte function.
- IDA reports no function at `0x005646b0`; previous modeled function is `0x00564520-0x005646ad`, and raw disassembly shows method-shaped reset code through `0x0056470c` before the next function at `0x00564710`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records a `0x110`-byte pane object with the scrollbar tail layout now tracked in [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md). The generated `m_highlightRegion` name at `+0x104` is weaker than the raw reset evidence, which treats `+0x103` as the stale hover/highlight part and `+0x104` as active state.
- 2026-05-26 IDA MCP confirms vtable bases `0x0062402c`, `0x00624078`, and `0x006240a8`, with paint, mouse, and timer slots mapped in [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md).
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) now gives the file-level container a reviewed `84/80` score and the same projected `NexusTK/ui/inventory/` path used by the surrounding [UID:0000KA][InventoryPane](by-file/InventoryPane.md) module.
- The raw reset helper and aggregate/update child pages remain useful evidence, but this class page does not attach or rescore by-memory children. [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) and [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) are still below 80 completion, and [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) keeps a function-table/caller-provenance caveat.

## Parent And Score Rationale

| Item | Score | Relevance |
| --- | ---: | --- |
| [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) | `84/80` | Current parent: documents the dedicated scrollbar file hypothesis, projected path, method family, layout/vtable refs, and possible fold into `NewInventoryPane`. |
| [UID:0000KA][InventoryPane](by-file/InventoryPane.md) | `82/82` | Confirms the broader `ui/inventory/` ownership and the item-inventory/new-inventory split that hosts this scrollbar. |
| [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) | `78/84` | Confirms the executable range, constructor caller, vtable stores, field offsets, owner-chain rationale, and raw-helper caveat, but remains below the by-memory attachment completion threshold. |
| [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) | `84/86` | Strong evidence for the reset behavior and exact raw span; keeps final C++ and higher class confidence capped because no modeled function start or caller provenance exists. |

The class confidence is raised only to `82`, not higher, because the local behavior, layout/vtable anchors, parent page, and aggregate memory page now agree, but the original source split and the raw reset-helper identity are still not final-source quality.

Completion is `82` because the class page covers parent metadata, method inventory, layout and vtable evidence, constructor caller, update/reset child pages, and the source-split caveat. It remains below final-source readiness until the update helper reaches the by-memory attachment threshold, the reset helper has stronger provenance, and the standalone/folded source decision is closed.

## Cross-References

- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the inventory scrollbar methods, owner/caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Evidence: IDA MCP confirms `NewInventoryPane::NewInventoryPane` allocates a 0x110-byte pane, calls the `0x00563260` constructor, and stores the result as an owned item-inventory scrollbar; final source-file placement and source-quality C++ are not at the 95+ gate.
- 2026-06-07: Raised confidence from `78` to `80` and attached the class to [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md).
  - Before: The class had 80 completion but stayed below the attachment confidence gate, even though its proposed file parent had already reached `84/80`.
  - Changed to: `AUTOGEN_PARENT_UID` is now `0000KB`, with added parent/score rationale explaining the file attachment, raw reset-helper caveat, and why by-memory children and final C++ are not changed here.
  - Evidence: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) records the dedicated `ui/inventory/` scrollbar source hypothesis, [UID:0000KA][InventoryPane](by-file/InventoryPane.md) corroborates module placement, [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) records caller/layout/vtable evidence, and [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) preserves the reset-helper provenance cap.
- 2026-06-07: Reconciled class status with the strengthened aggregate/layout/vtable pages.
  - Before: The page still cited recovered generated source directly and kept the class at `80/80` despite the aggregate memory page now documenting a stronger `78/84` owner chain and raw reset-helper evidence.
  - Changed to: raised to `82/82`, added autogen-status notes, removed direct generated-source dependency from the status block, refreshed the aggregate-memory score in the rationale table, and kept C++ blank.
  - Evidence: [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) now records the owner chain and boundary evidence at `78/84`; [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md) records the `0x110` object size and tail fields; [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md) records the three constructor-installed vtable views.
