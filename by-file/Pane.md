*** UID:0000MC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Pane

## Status

- Confidence: strong for `Pane`; stale `PaneChildRegistry` alias is tracked separately.
- Proposed module: `ui/core/Pane.cpp`
- Current recovered sources: `source-3/simroot_v2/class_Pane.cpp`; stale adjacent alias `class_PaneChildRegistry.cpp`
- Main method cluster: `0x00544460-0x00545086`, with destructor at `0x004b8d20`
- Type docs: [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`Pane` is the base UI object for visible interface elements. It sits on top of `GrafPort`, installs event/timer handler subobjects, tracks visibility and mode state, owns dirty/clip regions, and attaches panes into a `Layer` tree.

The dirty/motion helper family inside the main `0x00544460-0x00545086` cluster is part of this base pane layer. Current `simroot_v2` emits several of those helpers through `class_MapPane.cpp`, but IDA caller evidence routes them through [UID:0000KL][Layer](by-file/Layer.md) traversal and shared presentation code rather than map-specific behavior.

[UID:00004N][EventHandler](by-class/EventHandler.md) is the base virtual interface for the event-handler subobject installed by `Pane` and consumed by [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). Keep the handler declaration near UI core; do not treat generated `class_EventHandler.cpp` as a feature pane.

[UID:0000HR][BlackHole](by-file/BlackHole.md) is an adjacent UI-core cleanup queue used by pane close/replacement paths. Its pane-specific helper at `0x00469180` removes a pane from its layer, unregisters event and timer handlers, then queues it for deferred deletion. Current generated data also exposes that same function through the stale [UID:0000MD][PaneChildRegistry](by-file/PaneChildRegistry.md) alias.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `Pane` | `0x00544460-0x00545086` plus `0x004b8d20` | Base pane construction, show/hide, repaint, invalidation, bounds, layer attach/remove, input/timer hooks, destruction. |
| [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) | `0x005446b0-0x005446d4` | Exact mode-byte setter child; stores `Pane +0xb5` when changed and dispatches vtable slot `+0x20` with `this + 0x44`. |
| vtable family | `0x006219e8`, `0x00621a34`, `0x00621a64` | Primary pane view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x00544f2e`, `0x00544f39` | Compiler-generated secondary/tertiary destructor thunks; not handwritten pane behavior. |
| dirty/motion helpers | `0x00544690-0x00544b7d` | Deferred deletion marker plus dirty-region, motion-region, and paint-state helpers used by layer traversal. |
| layer membership helper | `0x00544c50` | Shared attached-layer test over `Pane +0xa8`; current ParcelPane ownership is generated callsite pollution. |
| `EventHandler` base | `0x004a8970-0x004a8a84` | Shared event-handler interface embedded by pane state and traversed by `EventDispatcher`; the following `0x004a8a84-0x004a8a90` span is alignment padding. |
| `BlackHole` pane queue helper | `0x00469180-0x004691fa` | Pane detach/event unregister/timer cancel path before deferred deletion. |

## Ownership Decision

Keep this separate from [UID:0000JR][GrafPort](by-file/GrafPort.md). `GrafPort` owns render backing storage; `Pane` owns UI object lifetime, layer membership, event handlers, and dirty region semantics.

Keep [UID:0000KL][Layer](by-file/Layer.md) as a neighboring file rather than merging it into `Pane.cpp`. `Pane` calls the layer API, while `Layer` owns a tree container and recursive dirty/render traversal.

## Evidence Notes

- Wave3 metadata identifies `Pane` as the base UI pane with `GrafPort` at offset `0`.
- IDA MCP reports `Pane::Pane` has 95 direct call sites, confirming it is the common base constructor for many UI classes.
- IDA MCP `list_globals` confirms three `Pane` vtable bases at `0x006219e8`, `0x00621a34`, and `0x00621a64`. The tertiary table is short and ends before neighboring [UID:0000ME][PanelPane](by-file/PanelPane.md) RTTI.
- IDA layout review on 2026-05-26 confirms the direct `Pane` state through `+0xf7` and derived-field boundary at `+0xf8`; [UID:0000IT][DialogPane](by-file/DialogPane.md) and [UID:0000IU][DialogSession](by-file/DialogSession.md) both begin their own storage there.
- IDA MCP reports `0x00469180` has broad direct call sites; IDA body checks show it is a `BlackHole` deferred-deletion queue helper rather than child registration.
- IDA MCP caller checks for `0x005446e0`, `0x00544980`, `0x00544a40`, `0x00544ae0`, and `0x00544b50` point at layer recursion and surface/presentation traversal, not `MapPane` ownership.
- 2026-06-03 IDA MCP confirms [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) as the exact `0x24`-byte pane mode setter: it updates the `+0xb5` mode byte only when changed and dispatches the primary vtable slot `+0x20` with `this + 0x44`.
- Generated source shows `Pane::AddToLayer`, `InsertInLayer`, and removal helpers calling the `Layer` API directly.

## Cross-References

- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f43.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md)
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

## Changes

- Before: the `PaneCore` memory page ended at `0x00545085`.
- Changed to: the page ends at `0x00545086`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545085` is the final operand byte of the `retn 4` in `sub_544F50`; `0x00545086-0x00545090` is alignment padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `84`.
- Summary/evidence: the page documents base UI role, proposed contents, dirty/motion helper ownership, EventHandler and BlackHole relationships, ownership boundaries, IDA evidence, range correction, type/vtable refs, and broad cross-references; confidence remains below exhaustive because some generated owner pollution still needs cleanup.

- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page and project tree identified `ui/core/Pane.cpp`.
- Changed to: `NexusTK/ui/core/`.
- Summary/evidence: `by-project-structure/proposed-source-tree.md` already lists `Pane.cpp` under `ui/core`, and this page records `ui/core/Pane.cpp` as the proposed module. The 2026-06-03 `PaneSetMode` split adds another exact child method under the same source owner.
