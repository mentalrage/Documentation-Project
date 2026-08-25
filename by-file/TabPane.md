*** UID:0000OF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: very strong for local behavior, live boundaries, the explicit empty primary `+0x44` `OnPaint`, exact EventHandler secondary overrides, signed-byte/y-x resolver contract, complete class declaration, three-view RTTI/vtable lifecycle, Singleton EBO/`0xf8` route, retained raw-helper policy, source/compiler disposition, and `ui/panels/` placement; bounded for final tab/action/helper lexical names and physical grouping with `IconsPane`.
- Proposed module: `ui/panels/TabPane.cpp`
- Generated source route: `auto-generated/NexusTK/ui/panels/TabPane.cpp` through this page's unchanged `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
- Main class: [UID:0000EB][TabPane](by-class/TabPane.md)
- Split address inventory: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global alias/lifecycle page: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), which emits a covered-by marker rather than duplicate storage.
- Singleton storage definition: [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md), which emits the sole `TabPane *g_pTabPane;` definition.
- Evidence basis: existing generated source as a lead plus IDA MCP decompilation/function/caller/xref checks through the 2026-06-04 live pass, refreshed for UID00034O by session `60724697`, refreshed for UID00034N/table/RTTI/source cause by session `e98ecbb2`, revalidated for UID00034O/34P/34R and complete class/source shape through healthy resumed database `3fc1dcef`, and rechecked for the singleton storage/lifecycle route through recovered database `6b2e78f3` on 2026-07-14.

## File Role

`TabPane.cpp` owns a compact old-layout tab/action input pane. It maps mouse coordinates in six fixed rectangular regions to shared UI action helpers and explicitly supplies an empty `TabPane::OnPaint` override at the Pane-family primary `+0x44` slot, while `IconsPane` maps eight icon slots to similar actions and has its own full paint override.

The class should sit near [UID:0000JZ][IconsPane](by-file/IconsPane.md) under `ui/panels/`. Current evidence supports separate class docs, but the final original source may have grouped both small old-HUD control panes in one `.cpp`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | The page summarizes the constructor, ordinary destructor, explicit empty `OnPaint`, exact pointer/mouse and key/text overrides, signed-byte/y-x resolver, retained raw helper, complete class declaration, scalar-wrapper split, exact zero-filled singleton storage definition/alias/extern factorization, five lifecycle/consumer refs, exact three-view vtable/RTTI route, six-region geometry, action dispatch, compiler-only table policy, padding inventory, and `IconsPane` interleave. |
| Confidence | 93 | Live class, Event/EventHandler, memory, PE virtual-tail storage, exact `4/5/23` singleton boundaries, primary/secondary slot comparisons, RTTI/PMD, allocation, lifecycle, exact bytes, call-order evidence, and generated route confirm the behavior, one-definition `g_pTabPane` relationship, source/compiler split, and `BuildTabActionRect` placement policy. Final tab labels, helper lexical names/access tokens, token-level zero-initializer spelling, and physical grouping with `IconsPane` remain bounded caps. |

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `TabPane` exact method pages | [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md), [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md), [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md), [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md), [UID:00034P][0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent](by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md), and [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md) | Constructor, ordinary `TabPane::~TabPane()` body, exact empty `void TabPane::OnPaint()` primary override, `bool HandlePointerOrMouseEvent(Event *)`, `bool HandleKeyOrTextEvent(Event *)`, and `signed char ResolveTabActionCode(int mouseY, int mouseX) const`. UID00034W remains compiler scalar deleting glue and must not emit a second destructor. |
| raw rectangle builder | [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) | Retained source-shaped private `TabPane::BuildTabActionRect` helper/dead or inlined duplicate. B005 direct PE scans found unique body/table bytes and no rel32/rel8/VA/RVA/export route; keep as `TabPane.cpp` helper evidence, not aggregate-owned table data. |
| compiler artifacts | [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md), [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md) | Non-reconstructable switch/table and ABI thunk evidence; do not emit as source methods. |
| RTTI/vtable data | [UID:0003BO][0x0061b4cc-0x0061b568.TabPaneVtableData](by-memory/0x0061b4cc-0x0061b568.TabPaneVtableData.md) | Compiler-generated primary/EventHandler/TimerHandler RTTI-vtable island, lifecycle stores, Singleton EBO/PMDs, and trailing `ICONS.EPD` literal. Class declarations/method definitions cause these bytes; keep the page non-reconstructable with no raw array source. |
| `g_pTabPane` | [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md), alias [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) | Exact loader-zero-filled singleton storage. UID00029C emits the sole external-linkage definition; UID0000SE emits a covered-by marker; UID0000EB supplies the sole extern. Constructor publishes it, ordinary/scalar cleanup clear it, and DialogPane/exit-to-menu paths consume it. |
| Vtable set | `0x0061b4d0`, `0x0061b51c`, `0x0061b54c` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x004cf980` calls `Pane::Pane(..., 1)`, writes [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), and installs three `TabPane` vtables.
- Recovered MCP database `6b2e78f3` confirms `0x0069adfc` has exactly five refs: DialogPane event-dispatch read `0x0049e5e6`, constructor publish `0x004cf9a4`, ordinary destructor clear `0x004cf9ea`, scalar-wrapper clear `0x004cfe20`, and exit-to-menu layer-removal read `0x00504936`. Exact target VA pattern occurs only at these five operands; target RVA pattern has no hit.
- PE arithmetic proves target RVA `0x0029adfc` is in `.data` virtual extent but `0x205fc` bytes beyond its raw end, so the storage is loader-zero-filled rather than initialized to `0xffffffff`. Source definition is the era-consistent `TabPane *g_pTabPane;`; token-level `= NULL`/`= 0` alternatives remain behaviorally equivalent confidence caps.
- B014's 2026-07-02 constructor recheck found the main UI initializer `sub_4F7D10` allocates `248` bytes, calls [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) at `0x004f812d`, places the resulting pane at `(808,79)-(831,365)`, and attaches it through pane virtual calls. This supports the existing `ui/panels/TabPane.cpp` route for the old-layout vertical tab strip and does not require a path or score change.
- The ordinary destructor body at `0x004cf9d0` reinstalls vtables, clears the singleton, and tail-transfers to inherited `Pane::~Pane()` at `0x00544580`; source C++ should emit only `TabPane::~TabPane()` with `g_pTabPane = NULL;`.
- [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md) is the exact empty `void TabPane::OnPaint()` override. Its body is one byte `c3`, one block, no arguments or side effects, and its sole xref is primary cell `0x0061b514` at `+0x44`. Pane's same slot targets `0x0041b6a0`, while IconsPane's same slot targets its full `OnPaint` at `0x004cf300`; the distinct TabPane target proves source-authored override rather than inheritance, sharing, folding, or compiler glue.
- UID00034O at `0x004cfa10` is exact `bool TabPane::HandlePointerOrMouseEvent(Event *event)`. It is the EventHandler secondary `+0x04` target, skips work when canonical `g_pUserPane + 0x13eb1d` is locked, accepts left-button-down/double-click types, calls the resolver with pointer `m_y,m_x`, preserves the counterintuitive key-overlay `m_messageTime +0x10c` action-0 argument, and follows the exact action restrictions and helper ABI classes. UID00034P at secondary `+0x08` is exact `bool HandleKeyOrTextEvent(Event *)` and always returns false.
- `ResolveTabActionCode` at `0x004cfc60` hit-tests six horizontal rectangles through canonical `PointInRect(mouseY, mouseX, &rect)` and returns signed-byte action codes `0..5`, or `-1` when no rectangle contains the point. The executable resolver duplicates/inlines the rectangle construction with a local table at `0x004cfd50` and does not call UID00034Q; generated source retains `BuildTabActionRect` only as the accepted source-level factoring/inlining hypothesis.
- The destructor thunks at `0x004cfd82` and `0x004cfd8d` subtract `0xa0` and `0xa4` respectively before forwarding to `0x004cfe00`.
- The scalar deleting destructor at `0x004cfe00` restores all three vtables, clears [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), calls inherited pane cleanup, and conditionally frees `this` unless the no-delete flag path is active. It is compiler-generated scalar-wrapper glue regenerated from `TabPane::~TabPane()` and should contribute only comment/marker output, not a duplicate source destructor.
- RTTI names primary, EventHandler, TimerHandler, and `Singleton<TabPane>` views with PMD displacements `0`, `+0xa0`, `+0xa4`, and `+0xf8`. The sole constructor caller allocates `0xf8` bytes, proving Singleton empty-base optimization and no TabPane-owned data field beyond Pane. Constructor, ordinary destructor, and scalar wrapper each write all three vtable bases.
- Secondary `+0x04` and `+0x08` are now resolved and emitted as UID00034O `HandlePointerOrMouseEvent(Event *)` and UID00034P `HandleKeyOrTextEvent(Event *)`. Their historical generic/false-return labels are search provenance only.

## Live Function Map

| Range | Owner | Role |
| --- | --- | --- |
| `0x004cf980-0x004cf9ca` | `TabPane` | Constructor called from `InitializeMainUiGraph` at `0x004f812d`. |
| `0x004cf9d0-0x004cf9f9` | `TabPane` | Ordinary/non-deleting `TabPane::~TabPane()` source body. |
| `0x004cfa00-0x004cfa01` | `TabPane` | Explicit empty `void TabPane::OnPaint()` at primary slot `+0x44`; historical `nullsub_30`, `TabPaneNullVirtual`, and `OnNoOpVirtual` labels are superseded provenance. |
| `0x004cfa10-0x004cfb0a` | `TabPane` | Exact `bool HandlePointerOrMouseEvent(Event *)`; EventHandler secondary `+0x04`, no direct callers, handled-status action dispatcher. |
| `0x004cfb10-0x004cfb15` | `TabPane` | Exact `bool HandleKeyOrTextEvent(Event *)`; EventHandler secondary `+0x08`, unused argument, returns false. |
| `0x004cfb20-0x004cfc5c` | `TabPane` retained raw helper | Builds the same six rectangles through `0x004b7c50`; no IDA function object, no entrypoint xrefs, no pointer hits, and B005 direct PE scans found no rel32/rel8/VA/RVA/export route. |
| `0x004cfc60-0x004cfd4d` | `TabPane` | Six-region action-code resolver. |
| `0x004cfd6c-0x004cfd82` | `IconsPane` | Destructor adjustor thunks interleaved in this physical range. |
| `0x004cfd82-0x004cfd98` | `TabPane` | Destructor adjustor thunks. |
| `0x004cfda0-0x004cfdff` | `IconsPane` | Scalar deleting destructor interleaved after the `TabPane` resolver. |
| `0x004cfe00-0x004cfe5f` | `TabPane` | Scalar deleting destructor glue; class-owned generated-binary wrapper, comment-only/no duplicate source destructor. |

## Dispatch And Geometry

| Code | Rect | Dispatch notes |
| --- | --- | --- |
| `0` | `(2, 1)-(20, 46)` | Left-button-down and double-click; calls free one-argument helper `0x005a4f70` with exact key-payload overlay field `+0x10c` / 268 (Verified with int_convert.py). It sends opcode `0x2d` / 45, subtype `0`, length `2`, then stores the extra value. |
| `1` | `(2, 47)-(20, 93)` | Left-button-down and double-click; calls free zero-argument helper `0x005a4db0`, which sets panel mode `2` and plays effect/sound `0x198` for `0x64` / 100. |
| `2` | `(2, 95)-(20, 140)` | Left-button-down and double-click; calls free zero-argument helper `0x005a4e40`, which sets panel mode `3` and plays effect/sound `0x198` for `0x64` / 100. |
| `3` | `(2, 142)-(20, 187)` | Left-button-down only; calls free zero-argument helper `0x005a4e70`, which sets panel mode `4` and plays effect/sound `0x198` for `0x64` / 100. |
| `4` | `(2, 189)-(20, 234)` | Left-button-down only; calls true UserPane-receiver helper `0x005a4ea0` through canonical `g_pUserPane`; it sends opcode `0x27` length `3` or switches panel mode `5` with optional sound. |
| `5` | `(2, 236)-(20, 281)` | Left-button-down and double-click; calls free zero-argument helper `0x005a4f40`, which sets panel mode `6` and plays effect/sound `0x198` for `0x64` / 100. |

## Data Caveats

The `0x004cf980-0x004cfe5f` memory area includes both `TabPane` functions and interleaved `IconsPane` destructor glue. Historical generated `class_TabPane.cpp` omissions are source-quality history, not current identity. UID0000EB emits the complete Pane/Singleton class declaration and sole `extern TabPane *g_pTabPane;` before all children; UID00029C emits the single namespace-scope definition; UID0000SE emits only the alias/lifecycle covered-by marker. UID00034N emits `OnPaint`; UID00034O/34P emit exact EventHandler overrides; UID00034Q/R emit private geometry helpers; UID00034M remains the single source destructor; UID00034W remains compiler scalar-wrapper coverage. UID0003BO documents compiler-generated tables/RTTI and emits no raw arrays. Final tab/action/helper spellings, zero-initializer token choice, and physical grouping with `IconsPane` remain confidence caps, not declaration/source blockers. UID000170 remains the boundary anchor.

The singleton slots remain non-merged: predecessor `g_pDescPane` has four refs, `g_pTabPane` has five, and successor `g_pSimpleHelpPane` has 23. DialogPane and MapPane are consumers only; IconsPane has a separate singleton/vtable lifecycle. Do not emit duplicate storage, handwritten scalar-wrapper code, vptr stores, vtable/RTTI arrays, or raw address labels.

## Cross-References

- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md)
- [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md)
- [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md)
- [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md)
- [UID:00034P][0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent](by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md)
- [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md)
- [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md)
- [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md)
- [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md)
- [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-14 B003 UID00029C singleton-definition callback:
  - Before: `91/92`; UID0000SE and UID00029C were both blank emitters, the class extern had no definition, and singleton storage prose retained stale `0xffffffff`/old-gate history.
  - Changed to: `92/93`, path/file-root unchanged, UID00029C as the sole `TabPane *g_pTabPane;` definition carrier, UID0000SE as alias/lifecycle covered-by marker, UID0000EB as sole extern, exact PE zero-fill/five-ref/`4/5/23` boundary evidence, source/compiler destructor split, consumer roles, negative routes, and one-definition generated policy.
  - Preserved: every existing class/helper/action/compiler/RTTI/padding/IconsPane fact, route, historical correction, and lexical/grouping confidence cap.
- 2026-07-14 B003 UID00034N focused family/file repair:
  - Before: `88/89`, provisional `HandleInputEvent(PaneInputEvent *)`, generic false-return virtual, stale int/x-y resolver shape, complete class declaration open, and generated UID0000EB Empty Emitter Marker.
  - Changed to: `91/92` with exact UID00034O/34P names/signatures, signed-byte y/x resolver, helper ABI/source dependencies, complete no-field Pane/Singleton class declaration, preserved source/compiler split, and unchanged `NexusTK/ui/panels/` route.
  - Evidence: resumed MCP database `3fc1dcef`, Event/EventHandler declarations, exact bytes/slots/call order, RTTI/PMDs, allocation, and current managed destination blocks.

- 2026-07-14 B003 UID00034N OnPaint file/source sync:
  - Before: `87/86`; the source inventory called UID00034N a null virtual, current/generated wording retained the old placeholder role, and the file page did not separate that source-authored override from compiler-generated UID0003BO tables.
  - Changed to: `88/89`; preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"` and file-root ownership, renamed the inventory entry to explicit empty `TabPane::OnPaint`, recorded exact primary-slot/base/sibling/RTTI/EBO/allocation/lifecycle evidence, and separated source child output from non-reconstructable no-array table data. All unrelated helper, action, tab-label, raw-body, destructor-wrapper, IconsPane grouping, and historical caveats remain.
  - Evidence: B003 live MCP session `e98ecbb2` proved UID00034N's one-byte body/hash/ABI, sole primary `+0x44` cell, Pane/IconsPane same-slot targets, explicit-override cause, three table views, RTTI PMDs, `0xf8` allocation, lifecycle stores, negative routes, and unchanged file placement.
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
- 2026-06-18 Rule 26 draft-C++ incorporation:
  - Changed: exact TabPane split children now include conservative first-draft C++ for constructor, cleanup, virtual stubs, input dispatch, rectangle construction, resolver behavior, and destructor source effects.
  - Summary/evidence: drafts preserve the documented six rectangles, mode-specific helper dispatch, singleton lifecycle, raw-helper reachability caveat, and compiler-generated vtable/thunk policy. Final source labels/grouping remain open, but the previous blanket "blank C++ below 95" position is superseded for these emitting children.
- 2026-06-21 Rule 26 B005 raw-helper incorporation:
  - Changed to: completion `87`, confidence `86`; the raw rectangle-builder row and data caveats now record [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) as a retained source-shaped `TabPane.cpp` helper/dead or inlined duplicate with no live entry route.
  - Summary/evidence: B005 direct PE scan found unique body/table bytes, exact local table targets, no rel32/rel8/VA/RVA/export route, resolver-local table `0x004cfd50`, and no machine-code call from [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md) to [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md). `ui/panels/TabPane.cpp` remains the recommended placement; no reroute to `IconsPane` or a new old-HUD module is currently justified.
- 2026-07-02 B014 constructor source-placement sync:
  - No file score or path change.
  - Summary/evidence: B014 fresh MCP checks for [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) confirmed `sub_4CF980` as the 74-byte `TabPane` constructor, with one direct caller at `0x004f812d`. The caller allocates `248` bytes, constructs the pane, positions it at `(808,79)-(831,365)`, and attaches it into the main UI pane graph. This is additional source-placement evidence for `NexusTK/ui/panels/TabPane.cpp`, while final physical grouping with [UID:0000JZ][IconsPane](by-file/IconsPane.md) remains an open class/file-level question.
- 2026-07-02 B015 destructor source-shape sync:
  - No file score or path change.
  - Summary/evidence: [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) is now the single emitted ordinary `TabPane::~TabPane()` source body, while [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) is class-owned scalar deleting destructor glue with comment-only output. B015 MCP evidence reconfirmed [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) as an exact `0x29` function with no direct xrefs, `TabPane` vtable restores, `g_pTabPane` clear, tail transfer to `Pane::~Pane()`, and boundary padding. This keeps source route through `ui/panels/TabPane.cpp` and prevents duplicate generated destructor definitions.
- 2026-07-04 B003 UID00034O source-output sync:
  - No file score or path change.
  - Historical stage: UID00034O then emitted `bool TabPane::HandleInputEvent(const PaneInputEvent *event)` after session `60724697` confirmed its exact body/route. The 2026-07-14 focused family repair supersedes that provisional lexical/formal shape with `HandlePointerOrMouseEvent(Event *)` while preserving the earlier binary evidence.
