*** UID:0000MC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Pane

## Two-Pane Ordering Contract - 2026-08-16

`NexusTK/ui/core/Pane.h` now declares `SetPaneOrder(Pane *beforePane, Pane *afterPane)`. The body at `0x00544d30-0x00544d6f`, EventDispatcher forwarding, and call-site push order prove two nullable Pane pointers rather than the superseded `Pane *, bool` model. `HistoryViewingPane` uses `SetPaneOrder(NULL, g_pScreenPane)` after status-layer attachment. This is a shared declaration repair only; Pane method ownership, layout, vtable order, and exact child source remain unchanged.

## UID0000L2 Constructor Header Consumer Contract - 2026-08-12

- The generated `NexusTK/ui/core/Pane.h` declaration is `explicit Pane(unsigned char mode);`, not the superseded parameterless `Pane();` form. The constructor ABI and reconstructed derived initializers consistently pass a one-byte pane mode; `MapNamePane::MapNamePane()` uses the evidence-backed `Pane(1)` initializer.
- This is a header-visibility correction only. It preserves the complete `Pane` layout, multiple inheritance, virtual API, source-body children, and `NexusTK/ui/core/Pane.cpp` ownership already documented below.
- The prior parameterless declaration is retained as a historical defect rather than a valid overload. No evidence supports emitting both constructors.

## UID000090 Complete Header And Implementation Contract - 2026-07-31

- `NexusTK/ui/core/Pane.h` owns the complete `Pane : GrafPort, EventHandler, TimerHandler` declaration. It includes `../../render/GrafPort.h`, `../../util/TimerHandler.h`, `EventHandler.h`, `RectBounds.h`, and `Region.h`; `LObject` is supplied by complete GrafPort.h. Forward-declared or PCH-only bases are rejected because C++ requires complete base definitions.
- `NexusTK/ui/core/Pane.cpp` includes `Pane.h`, `../../input/InputMan.h`, and `Layer.h`, then composes exact by-memory children. The complete InputMan declaration is required for `TrackInputTarget`; the complete Layer declaration is required for `GetScreenOffset` and existing layer operations.
- Pane.h owns declarations and the exact `0xf8` layout; Pane.cpp owns source bodies. The six newly isolated source ranges are the default event-handler cluster, local/screen offset methods, acceptance gate, timer default, and focus-registration method. PaneCore remains their non-emitting physical index.
- Historical same-directory TimerHandler/PCH assumptions and the Pane-local `m_bounds` declaration are superseded. `m_visibleBounds` is inherited through GrafPort, and the exact Pane-owned tail begins at `+0xa8`.

## UID0003ZT Header And Source Factoring - 2026-07-23

- Canonical source pair: `NexusTK/ui/core/Pane.h` and `NexusTK/ui/core/Pane.cpp`.
- Pane.h includes `GrafPort.h`, `EventHandler.h`, and `TimerHandler.h` before the complete Pane declaration, giving derived panes complete base and inherited event/timer facet visibility.
- EventHandler, TimerHandler, and GrafPort retain their own declaration/body owners. Pane.h consumes them; Pane.cpp owns Pane methods and shared capture/release helpers already routed here.
- MapPane derives the EventHandler and TimerHandler facets through Pane. The [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) source uses inherited `ReleaseMouseCapture()` and TimerHandler cancellation rather than local helper/member substitutes.
- Scores remain `90/91`; the same-basename source route, layout, child inventory, helper ownership, and all prior evidence remain unchanged.

## Layer Source-Boundary Synchronization - 2026-07-14

Pane.cpp owns the public pane-side wrappers for Layer attachment, insertion, removal, invalidation, membership, parent lookup, and coordinate offset. Their exact Layer callees are UID0004NT/0004NU/0004NV/0004O0/0004NZ/0004O9/0004OA. Layer.cpp owns the corresponding hierarchy implementation, LayerNode storage, dirty/render recursion, and Region/list lifetime.

Pane pointers stored in LayerNode are borrowed; Pane deletion is requested through [UID:0004NW][0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion](by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md), not performed by Layer destruction. This bounded source-boundary clarification does not change Pane file scores, route, or formal C++.

## Bounds And Origin Source-Boundary Synchronization - 2026-07-16

- The `NexusTK/ui/core/Pane.cpp` route owns inherited primary contracts `UpdateRenderRegion` at `+0x0c`, `GetScreenBounds` at `+0x28`, and base `SetBounds` at `+0x2c`.
- `GetScreenBounds` obtains a screen offset through the EventHandler view, copies inherited `GrafPort::m_visibleBounds` at `+0x44`, and offsets the caller output.
- Base `SetBounds` initializes top/Y and left/X into `Point m_origin`, whose accepted layout is `m_origin.y` at `+0xac` and `m_origin.x` at `+0xb0`; it localizes a stack rectangle by negative X/Y and dispatches `UpdateRenderRegion`.
- ObjectPane consumes this source contract without moving ownership: UID0003XW is the source-ready `UpdateRenderRegion` override and UID0003XX is the source-ready two-argument `SetBounds` override with ObjectPane-specific object-data propagation.
- LoginDialog, IMEComposition, MapPane, FittingRoom UID0002DG, and FlyingParcel owner-normalized accesses independently confirm the same Y/X order.
- Historical generic local-bounds aliases, FlyingParcel X-at-`+0xac`, and swapped FittingRoom point/offset expressions are superseded. Scores remain `90/91`; route, source inventory, blank broad class formal policy, and unrelated Pane/Layer/EventHandler/TimerHandler evidence remain unchanged.

## Status

- Confidence: strong for Pane source placement, core ownership, exact SetMode/GetDescription children, vtables, and shared helper families; stale PaneChildRegistry alias and unrelated helper spellings remain tracked separately.
- Proposed module: `ui/core/Pane.cpp`
- Current recovered sources: `source-3/simroot_v2/class_Pane.cpp`; stale adjacent alias `class_PaneChildRegistry.cpp`
- Main method cluster: non-emitting split/index [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md), with exact source children UID0002V7 `Pane::SetMode`, UID0004IX `Pane::GetDescription`, and UID0004KU `Pane::Collapse`, ordinary `Pane::~Pane` at `0x00544580-0x00544687`, and scalar deleting destructor wrapper at `0x00544f50-0x00545086`. `0x004b8d20-0x004b8dc3` remains GrafPort cleanup, not Pane.
- Type docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`Pane` is the base UI object for visible interface elements. It sits on top of `GrafPort`, installs event/timer handler subobjects, tracks visibility and mode state, owns dirty/clip regions, and attaches panes into a `Layer` tree.

The dirty/motion helper family inside the main `0x00544460-0x00545086` cluster is part of this base pane layer. Current `simroot_v2` emits several of those helpers through `class_MapPane.cpp`, but IDA caller evidence routes them through [UID:0000KL][Layer](by-file/Layer.md) traversal and shared presentation code rather than map-specific behavior. The named ScreenPane presentation caller is [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) / `ScreenPane::TraversePresentationList(Region *dirtyRegion)`, which consumes Pane dirty/motion helpers without owning them.

[UID:00004N][EventHandler](by-class/EventHandler.md) is the base virtual interface for the event-handler subobject installed by `Pane` and consumed by [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Keep the handler declaration near UI core; do not treat generated `class_EventHandler.cpp` as a feature pane.

[UID:0000HR][BlackHole](by-file/BlackHole.md) is an adjacent UI-core cleanup queue used by pane close/replacement paths. Its pane-specific helper at `0x00469180` removes a pane from its layer, unregisters event and timer handlers, then queues it for deferred deletion. Current generated data also exposes that same function through the stale [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) alias.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `Pane` | [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) split/index; exact children under this range | Base pane construction, ordinary destruction, source-facing `DrawOnTarget` no-op direction, show/hide, exact `GetParentPane` at `0x005447a0`, invalidation family, `GetScreenBounds`, Y/X `Point m_origin` base `SetBounds`, layer attach/remove, EventHandler/TimerHandler facets, and default virtual support. Parent page is non-emitting; exact child pages carry C++ bodies. |
| [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) | `0x005446b0-0x005446d4` | Exact mode-byte setter child; stores `Pane +0xb5` when changed and dispatches primary vtable slot `+0x20` / `0x00544800` `Pane::InvalidateRect` with local bounds `this + 0x44`. |
| [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) | `0x00544a20-0x00544a35` | Exact source child in `NexusTK/ui/core/Pane.cpp`; primary slot `+0x24`, `void Pane::GetDescription(int,wchar_t *)`, wide-NUL default for `-1`, no write otherwise, 382 vtable data refs, and DescPane consumer. |
| [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) | `0x00544ee0-0x00544f2e` | Exact `void Pane::Collapse()` source child; removes the pane from its layer, zero-initializes a `RectBounds`, and calls primary slot `+0x0c` / `UpdateRenderRegion`. Its only callers are the two GeneralPurposePanel switch methods. |
| vtable family | [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md), [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md) | Primary pane view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x00544f2e`, `0x00544f39` | Compiler-generated secondary/tertiary destructor thunks; not handwritten pane behavior. |
| dirty/motion helpers | `0x00544690-0x00544b7d` | Deferred deletion marker plus dirty-region, motion-region, and paint-state helpers used by layer traversal. |
| layer membership helper | `0x00544c50` | Shared attached-layer test over `Pane +0xa8`; current ParcelPane ownership is generated callsite pollution. |
| `EventHandler` base | `0x004a8970-0x004a8a84` | Shared event-handler interface embedded by pane state and traversed by `EventDispatcher`; the following `0x004a8a84-0x004a8a90` span is alignment padding. |
| `BlackHole` pane queue helper | `0x00469180-0x004691fa` | Pane detach/event unregister/timer cancel path before deferred deletion. |

## Ownership Decision

Keep this separate from [UID:0000JR][GrafPort](by-file/GrafPort.md). `GrafPort` owns render backing storage; `Pane` owns UI object lifetime, layer membership, event handlers, and dirty region semantics.

Keep [UID:0000KL][Layer](by-file/Layer.md) as a neighboring file rather than merging it into `Pane.cpp`. `Pane` calls the layer API, while `Layer` owns a tree container and recursive dirty/render traversal.

## Evidence Notes

- Primary vtable `+0x1c` / `0x005447a0` is `Pane::GetParentPane()`, not Repaint: it reads the attached Layer pointer and calls the Layer parent-pane lookup.
- The primary inherited/default span used by DialogSession/DialogInSession also
  resolves `+0x04` runtime class, `+0x08` change-message default, `+0x0c`
  UpdateRenderRegion, `+0x10` three-argument no-op `DrawOnTarget` direction,
  and `+0x44` empty OnPaint default.
- Secondary `+0xa0` is the exact EventHandler 11-slot facet; tertiary `+0xa4` is the TimerHandler facet with true-return OnTimer default. These are inherited through Pane and are not extra direct bases in derived source.

- Wave3 metadata identifies `Pane` as the base UI pane with `GrafPort` at offset `0`.
- IDA MCP reports `Pane::Pane` has 95 direct call sites, confirming it is the common base constructor for many UI classes.
- IDA MCP `list_globals` confirms three `Pane` vtable bases at `0x006219e8`, `0x00621a34`, and `0x00621a64`. The tertiary table is short and ends before neighboring [UID:0000ME][PanelPane](by-file/PanelPane.md) RTTI.
- 2026-06-12 A004 live IDA MCP split [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) as the exact source-local type page backed by [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md).
- IDA layout review on 2026-05-26 confirms the direct `Pane` state through `+0xf7` and derived-field boundary at `+0xf8`; [UID:0000IT][DialogPane](by-file/DialogPane.md) and [UID:0000IU][DialogSession](by-file/DialogSession.md) both begin their own storage there.
- IDA MCP reports `0x00469180` has broad direct call sites; IDA body checks show it is a `BlackHole` deferred-deletion queue helper rather than child registration.
- IDA MCP caller checks for `0x005446e0`, `0x00544980`, `0x00544a40`, `0x00544ae0`, and `0x00544b50` point at layer recursion and surface/presentation traversal, not `MapPane` ownership.
- 2026-06-17 B002 source-quality reanalysis confirms [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as the exact `0x24`-byte `Pane::SetMode(unsigned char)` method: it updates `+0xb5` only when changed and dispatches primary vtable slot `+0x20`, `0x00621a08 -> 0x00544800`, with local bounds `this + 0x44`; the target is `Pane::InvalidateRect`.
- 2026-07-12 B003 UID00012O callback confirms fresh [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) belongs in this same source route. Exact 21-byte behavior, primary `+0x24` cell, 382 vtable data refs, parent-only adjacent pads, and [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md) consumer reject the stale `OnCommand` name and any DescPane.cpp ownership for the shared default.
- 2026-07-13 B004 UID00015Y callback registers [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) in this source route. The body calls primary `+0x38` `RemoveFromLayer()`, then primary `+0x0c` `UpdateRenderRegion(const RectBounds *)` with an all-zero rectangle. `SetBounds` is independently primary `+0x2c`, and `Hide` is independently primary `+0x18`, rejecting both stale alternatives.
- The inherited primary `+0x48` contract is best declared `virtual void Pane::OnActivate(const unsigned char *packetData)`. The Pane base cell is pure; derived implementations either consume the packet or ignore it while rebuilding/requesting state. This common pointer contract supersedes the historical `bool showChild` interpretation without claiming one behavior-specific name for every override.
- Generated source shows `Pane::AddToLayer`, `InsertInLayer`, and removal helpers calling the `Layer` API directly.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` was used to recheck the current file-parent blockers:

- `lookup_funcs` reconfirmed the core `Pane` starts and sizes: constructor `0x00544460` size `0x118`, ordinary `Pane` destructor `0x00544580` size `0x107`, dirty/motion helpers `0x00544690` size `0x1d`, `0x005446e0` size `0x26`, `0x00544980` size `0x25`, `0x00544a40` size `0x9e`, `0x00544ae0` size `0x66`, `0x00544b50` size `0x2d`, layer membership/attach helpers `0x00544c50` size `0x16`, `0x00544c70` size `0x34`, `0x00544cb0` size `0x27`, `0x00544ce0` size `0x4a`, dispatcher helpers `0x00544d30` size `0x3f` and `0x00544d70` size `0x3e`, default helper `0x00544e90` size `0x5`, adjustor thunks `0x00544f2e`/`0x00544f39` size `0xb`, and scalar/default cleanup body `0x00544f50` size `0x136`. The similarly old `0x004b8d20` destructor reference is now rejected as `GrafPort` cleanup.
- `xrefs_to` reconfirmed the broad file-root anchors: `Pane::Pane` has `95` constructor call refs, the non-deleting destructor has `14` refs, the `Pane` RTTI string exists at `0x006739a8`, and the three vtable bases `0x006219e8`, `0x00621a34`, and `0x00621a64` each have constructor/destructor/scalar-cleanup stores.
- The caller pattern still supports UI-core ownership for dirty/motion helpers rather than feature ownership: `0x005446e0` is called from `Layer` recursion `0x004f15a0` and [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) / `ScreenPane::TraversePresentationList(Region *dirtyRegion)`; `0x00544980` is called from the same ScreenPane presentation traversal; `0x00544a40`, `0x00544ae0`, and `0x00544b50` are called from `Layer` recursion.
- The layer-membership helper `0x00544c50` has six code refs across UI/parcel/surface paths, matching a shared `Pane` infrastructure helper instead of a ParcelPane-private method. `search_structs` found no local IDA UDT for `Pane`, and `find_regex` found no embedded `Pane.cpp` source filename string, so final member names and exact source declaration still cannot be made source-final from this pass.

This source-root decision is backed by constructor fan-in, vtable stores, RTTI, helper caller clusters, exact SetMode/GetDescription children, and support class/type pages. Remaining blockers are unrelated helper/field names, generated owner pollution, and whole-file source polish, not the description virtual.

## Score Rationale

Completion/confidence are `90/91`: the file root now includes exact SetMode, GetDescription, and Collapse children, resolves Collapse's `UpdateRenderRegion` dependency, and records the common pointer-valued `OnActivate` contract in addition to the prior PaneCore/layout/vtable evidence. The route remains `NexusTK/ui/core/`. Original spellings and unrelated broad Pane helper reconstruction still cap whole-file scoring; the formal class block remains intentionally blank rather than inventing a partial declaration.

## Cross-References

- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:00004N][EventHandler](by-class/EventHandler.md)
- [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md)
- [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md)
- [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md)
- [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md)

## DescPane Vtable Support Synchronization - 2026-07-16

- `NexusTK/ui/core/Pane.cpp` owns the primary `+0x10` default at
  `0x0041d680`. The accepted source-facing direction is
  `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`.
- Evidence is the exact three-argument no-op ABI, Layer caller arguments,
  broad vtable reuse, and derived weather-pane overrides. The original lexical
  spelling remains inferred; no new source body or class formal is added here.
- Primary `+0x1c` remains exact `GetParentPane`, and the one stale PaneCore
  `Repaint` row is corrected on that index page.
- Scores, `NexusTK/ui/core/` placement, complete B004/B005 source inventory,
  Layer/EventHandler/TimerHandler union, and unrelated helper history remain
  unchanged.

## Changes

- 2026-07-16 B001 UID0002NA bounded support synchronization:
  - Preserved `90/91`, FILE ownership, `NexusTK/ui/core/`, and the complete
    current cross-agent Pane union.
  - Added only the accepted `DrawOnTarget` direction and retained exact
    `GetParentPane` and inherited facet contracts.
- 2026-07-16 B004 UID0002NB accepted support synchronization:
  - Preserved `90/91`, FILE ownership, `NexusTK/ui/core/`, complete source inventory, all exact children, and unrelated Layer/EventHandler/TimerHandler/dirty-region/deletion history.
  - Corrected the specific `0x005447a0` primary virtual to `Pane::GetParentPane()` and synchronized the inherited primary/secondary/tertiary contracts consumed by DialogSession/DialogInSession without score, route, or broad formal inflation.
- 2026-07-16 Agent-B005 UID0003XX accepted callback:
  - Preserved `90/91`, `NexusTK/ui/core/`, the complete current Pane source inventory, blank broad class-formal policy, and all unrelated Layer/EventHandler/TimerHandler/dirty-region/deletion/vtable history.
  - Added bounded `GrafPort::m_visibleBounds`, `Point m_origin.y/m_origin.x`, `GetScreenBounds`, base `SetBounds`, and `UpdateRenderRegion` source-boundary evidence.
  - Linked source-ready ObjectPane UID0003XW/UID0003XX and historicalized stale X-first/local-bounds aliases without adding file-level C++ or changing source ownership.
- 2026-07-13 B004 UID00015Y accepted callback: raised `89/89 -> 90/91`; added exact UID0004KU PaneCollapse source routing and body semantics, resolved primary `+0x0c` as `UpdateRenderRegion`, recorded primary `+0x48` as the common `OnActivate(const unsigned char *)` contract, and retained a blank formal class surface rather than inventing an incomplete Pane declaration.
- 2026-07-12 B003 UID00012O accepted callback: raised `88/86 -> 89/89`; added exact UID0004IX PaneGetDescription child/source role, primary `+0x24` signature/default semantics, vtable fanout, padding, DescPane consumer, rejected `OnCommand`/DescPane ownership, and score rationale. The Pane.cpp route and all unrelated Pane/BlackHole/EventHandler/Layer facts remain unchanged.
- 2026-06-21 B012 ScreenPanePresentationTraversal support sync:
  - Score unchanged at `88/86`.
  - Named the prior raw `0x00559410` caller as [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) / `ScreenPane::TraversePresentationList(Region *dirtyRegion)`, keeping Pane dirty/motion helpers as UI-core dependencies rather than ScreenPane, MapPane, or Surface-owned code.

- 2026-06-18 B002 PaneCore source-quality execution: [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) is now a non-emitting split/index for the broad physical Pane cluster. Exact source-bearing methods should be emitted by child pages under [UID:0000A2][Pane](by-class/Pane.md), beginning with existing [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) `Pane::SetMode`. The ordinary destructor is `0x00544580-0x00544687`; `0x004b8d20-0x004b8dc3` is documented as `GrafPort` cleanup only.

- 2026-06-17 B002 `PaneSetMode` support sync:
  - What existed before: the file page described [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as a child of this source route but still left the slot `+0x20` callback name unresolved.
  - Changed to: records the resolved `Pane::InvalidateRect` side effect, notes that [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) is directly owned/emitted by [UID:0000A2][Pane](by-class/Pane.md), and keeps this page as the `NexusTK/ui/core/Pane.cpp` source root.
  - Evidence: B002 live IDA review resolved vtable entry `0x00621a08 -> 0x00544800`, confirmed the target body and caller usage, and populated first-draft C++ in the child page.

- Before: the `PaneCore` memory page ended at `0x00545085`.
- Changed to: the page ends at `0x00545086`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545085` is the final operand byte of the `retn 4` in `sub_544F50`; `0x00545086-0x00545090` is alignment padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `84`.
- Summary/evidence: the page documents base UI role, proposed contents, dirty/motion helper ownership, EventHandler and BlackHole relationships, ownership boundaries, IDA evidence, range correction, type/vtable refs, and broad cross-references; confidence remains below exhaustive because some generated owner pollution still needs cleanup.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page and project tree identified `ui/core/Pane.cpp`.
- Changed to: `NexusTK/ui/core/`.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` already lists `Pane.cpp` under `ui/core`, and this page records `ui/core/Pane.cpp` as the proposed module. The 2026-06-03 `PaneSetMode` split adds another exact child method under the same source owner.

- 2026-06-16 A001 Goal2 file-confidence refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:84`.
  - After: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: current IDA MCP reconfirmed core function sizes, 95 constructor refs, destructor refs, vtable base stores, dirty/motion helper caller clusters, `Pane` RTTI, the shared layer-membership helper xrefs, no embedded `Pane.cpp` source filename, and no local UDT. Confidence now clears the direct-parent gate while preserving final helper/member/source-declaration blockers.
