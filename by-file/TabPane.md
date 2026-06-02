*** UID:0000OF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: strong for local behavior, range, and `ui/panels/` placement; medium-high for final source grouping with `IconsPane`.
- Proposed module: `ui/panels/TabPane.cpp`
- Current generated source: `class_TabPane.cpp`
- Main class: [UID:0000EB][TabPane](by-class/TabPane.md)
- Main address doc: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- Evidence basis: `simroot_v2`, Wave2 report notes, and IDA MCP decompilation/function/caller/xref checks on 2026-05-24.

## File Role

`TabPane.cpp` owns a compact old-layout tab/action input pane. It maps mouse coordinates in six fixed rectangular regions to shared UI action helpers, while `IconsPane` maps eight icon slots to similar actions.

The class should sit near [UID:0000JZ][IconsPane](by-file/IconsPane.md) under `ui/panels/`. Current evidence supports separate class docs, but the final original source may have grouped both small old-HUD control panes in one `.cpp`.

## Score Rationale

The projected path is now `NexusTK/ui/panels/` because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TabPane.cpp` beside `IconsPane.cpp`, and existing IDA-backed memory/global/class docs show it is an old-layout UI panel rather than a generic tab control. Confidence is raised to `80` for placement, but remains capped by the open question of whether the original source kept `TabPane` and `IconsPane` separate or grouped in one old-HUD controls file.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TabPane` | `0x004cf980-0x004cfe5f` | Constructor, cleanup helper, null virtual, input handler, action-code resolver, destructor thunks, scalar deleting destructor. |
| `g_pTabPane` | `0x0069adfc` | Singleton pointer registered by constructor, cleared by cleanup/destructor paths, and read during main UI shutdown. |
| Vtable set | `0x0061b4d0`, `0x0061b51c`, `0x0061b54c` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x004cf980` calls `Pane::Pane(..., 1)`, writes [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), and installs three `TabPane` vtables.
- The cleanup helper at `0x004cf9d0` reinstalls vtables, clears the singleton, and calls shared pane cleanup.
- `HandleInputEvent` at `0x004cfa10` skips work if `g_pAppMan + 0x13eb1d` is set, resolves a tab action code from mouse coordinates, and dispatches a subset of action helpers for event modes `1` and `2`.
- `ResolveTabActionCode` at `0x004cfc60` hit-tests six horizontal rectangles. Current evidence names the return values by behavior only, not final UI labels.
- The destructor thunks at `0x004cfd82` and `0x004cfd8d` subtract `0xa0` and `0xa4` respectively before forwarding to `0x004cfe00`.

## Data Caveats

The `0x004cf980-0x004cfe5f` memory area includes both `TabPane` functions and interleaved `IconsPane` destructor glue. Active generated `class_TabPane.cpp` omits `0x004cf9d0`, `0x004cfa00`, `0x004cfc60`, and the accurate second adjustor thunk at `0x004cfd8d`. Use the memory doc as the boundary anchor.

## Cross-References

- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
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
