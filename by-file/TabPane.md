*** UID:0000OF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: strong for local behavior, live function boundaries, singleton/vtable lifecycle, and `ui/panels/` placement; medium-high for final source grouping with `IconsPane`.
- Proposed module: `ui/panels/TabPane.cpp`
- Current generated source: `class_TabPane.cpp`
- Main class: [UID:0000EB][TabPane](by-class/TabPane.md)
- Split address inventory: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- Evidence basis: existing generated source as a lead plus IDA MCP decompilation/function/caller/xref checks through the 2026-06-04 live pass.

## File Role

`TabPane.cpp` owns a compact old-layout tab/action input pane. It maps mouse coordinates in six fixed rectangular regions to shared UI action helpers, while `IconsPane` maps eight icon slots to similar actions.

The class should sit near [UID:0000JZ][IconsPane](by-file/IconsPane.md) under `ui/panels/`. Current evidence supports separate class docs, but the final original source may have grouped both small old-HUD control panes in one `.cpp`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now summarizes the constructor/cleanup/null/input/false-return/resolver/destructor method set, singleton and vtable ownership, six-region hit-test geometry, action-helper dispatch, the raw rectangle-helper caveat, and the `IconsPane` destructor interleave. |
| Confidence | 85 | Live class, memory, and singleton-storage docs confirm the important behavior, boundaries, and direct `g_pTabPane` parent relationship. Confidence remains below final-source range because final tab labels, action-helper names, and whether original source grouped `TabPane` with `IconsPane` are still unresolved. |

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TabPane` exact method pages | [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md), [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md), [UID:00034N][0x004cfa00-0x004cfa01.TabPaneNullVirtual](by-memory/0x004cfa00-0x004cfa01.TabPaneNullVirtual.md), [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent.md), [UID:00034P][0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual](by-memory/0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual.md), [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md), and [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) | Constructor, cleanup helper, virtual slots, input handler, action-code resolver, and scalar deleting destructor. |
| raw rectangle builder | [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) | Unreferenced raw helper that builds the same six tab rectangles as the resolver; keep as boundary/geometry evidence until reachability is proven. |
| compiler artifacts | [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md), [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md) | Non-reconstructable switch/table and ABI thunk evidence; do not emit as source methods. |
| `g_pTabPane` | `0x0069adfc` | Singleton pointer registered by constructor, cleared by cleanup/destructor paths, and read during main UI shutdown. |
| Vtable set | `0x0061b4d0`, `0x0061b51c`, `0x0061b54c` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x004cf980` calls `Pane::Pane(..., 1)`, writes [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), and installs three `TabPane` vtables.
- The cleanup helper at `0x004cf9d0` reinstalls vtables, clears the singleton, and calls shared pane cleanup at `0x00544580`.
- `HandleInputEvent` at `0x004cfa10` skips work if [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748` byte `+0x13eb1d` is set, resolves a tab action code from mouse coordinates, and dispatches a subset of action helpers for event modes `1` and `2`.
- `ResolveTabActionCode` at `0x004cfc60` hit-tests six horizontal rectangles and returns action codes `0..5`, or `-1` when no rectangle contains the point. Current evidence names the return values by behavior only, not final UI labels.
- The destructor thunks at `0x004cfd82` and `0x004cfd8d` subtract `0xa0` and `0xa4` respectively before forwarding to `0x004cfe00`.
- The scalar deleting destructor at `0x004cfe00` restores all three vtables, clears [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), calls shared pane cleanup, and conditionally frees `this` unless the no-delete flag path is active.

## Live Function Map

| Range | Owner | Role |
| --- | --- | --- |
| `0x004cf980-0x004cf9ca` | `TabPane` | Constructor called from `InitializeMainUiGraph` at `0x004f812d`. |
| `0x004cf9d0-0x004cf9f9` | `TabPane` | Non-deleting cleanup helper. |
| `0x004cfa00-0x004cfa01` | `TabPane` | Null virtual slot. |
| `0x004cfa10-0x004cfb0a` | `TabPane` | Input handler and action dispatcher. |
| `0x004cfb10-0x004cfb15` | `TabPane` | False-return virtual. |
| `0x004cfb20-0x004cfc5c` | `TabPane` adjacent raw helper | Builds the same six rectangles through `0x004b7c50`; no IDA function object, no entrypoint xrefs, and no pointer hits. |
| `0x004cfc60-0x004cfd4d` | `TabPane` | Six-region action-code resolver. |
| `0x004cfd6c-0x004cfd82` | `IconsPane` | Destructor adjustor thunks interleaved in this physical range. |
| `0x004cfd82-0x004cfd98` | `TabPane` | Destructor adjustor thunks. |
| `0x004cfda0-0x004cfdff` | `IconsPane` | Scalar deleting destructor interleaved after the `TabPane` resolver. |
| `0x004cfe00-0x004cfe5f` | `TabPane` | Scalar deleting destructor. |

## Dispatch And Geometry

| Code | Rect | Dispatch notes |
| --- | --- | --- |
| `0` | `(2, 1)-(20, 46)` | Mode `1` and mode `2`; calls `0x005a4f70` with event field `+0x10c`. |
| `1` | `(2, 47)-(20, 93)` | Mode `1` and mode `2`; calls `0x005a4db0`. |
| `2` | `(2, 95)-(20, 140)` | Mode `1` and mode `2`; calls `0x005a4e40`. |
| `3` | `(2, 142)-(20, 187)` | Mode `1`; calls `0x005a4e70`. |
| `4` | `(2, 189)-(20, 234)` | Mode `1`; calls `0x005a4ea0`. |
| `5` | `(2, 236)-(20, 281)` | Mode `1` and mode `2`; calls `0x005a4f40`. |

## Data Caveats

The `0x004cf980-0x004cfe5f` memory area includes both `TabPane` functions and interleaved `IconsPane` destructor glue. Active generated `class_TabPane.cpp` has historically omitted or under-modeled the cleanup helper, null virtual, resolver, raw rectangle builder, and accurate adjustor thunk split. Use [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) as the boundary anchor.

## Cross-References

- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md)
- [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md)
- [UID:00034N][0x004cfa00-0x004cfa01.TabPaneNullVirtual](by-memory/0x004cfa00-0x004cfa01.TabPaneNullVirtual.md)
- [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent.md)
- [UID:00034P][0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual](by-memory/0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual.md)
- [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md)
- [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md)
- [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md)
- [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md)
- [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `78`.
  - Evidence: document captures old-layout tab pane role, proposed contents, singleton/vtable anchors, input/action behavior, destructor thunk notes, IconsPane interleave caveat, and cross-references; confidence remains capped by final source grouping with `IconsPane`.
- 2026-06-02 projected path update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence was `78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"` and confidence `80`.
  - Summary/evidence: proposed source tree and existing memory/global/class docs place `TabPane.cpp` in the old-layout UI panels folder.
- 2026-06-07 A001 file-page reconciliation:
  - What existed before: the file page had the correct old-layout role and source path but lagged the class/memory pages for live boundaries, dispatch details, raw helper handling, and resolved global naming.
  - Changed to: completion `86`, confidence `84`; added a score-rationale table, live function map, dispatch/geometry table, `g_pCollectionData` gate naming, raw `0x004cfb20` caveat, and explicit `IconsPane` destructor interleave.
  - Summary/evidence: [UID:0000EB][TabPane](by-class/TabPane.md), [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md), and [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) now support the file-level ownership, while final tab labels, action-helper names, and source grouping with [UID:0000JZ][IconsPane](by-file/IconsPane.md) remain open.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: retained the documented source-split caveats but raised confidence to the corrected parent gate because the direct singleton child [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) and exact storage page [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md) now tie the global declaration directly to the already audited `TabPane` lifecycle.
- 2026-06-10 B001-034 split repair:
  - Changed: proposed contents and cross-references now list exact child pages [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) through [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md), while [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) is a non-emitting mixed inventory.
  - Summary/evidence: IDA MCP verified the exact TabPane bodies, raw helper, jump table, destructor thunks, scalar deleting destructor, singleton lifecycle, and the interleaved `IconsPane` destructor boundary. Score remains `86/85`; the file parent gate remains satisfied.
