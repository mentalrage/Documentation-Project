*** UID:0003JA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Pane Vtables

## Status

- Entity kind: source-local vtable cluster.
- Covered class: [UID:0000A2][Pane](by-class/Pane.md).
- Likely source file: [UID:0000MC][Pane](by-file/Pane.md).
- Exact memory page: [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md).
- Non-emitting aggregate source: [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md).
- Autogen parent: [UID:0000A2][Pane](by-class/Pane.md), now `90/91`.
- Verification: A004 Batch 336 live IDA MCP against `b001_nexustk` on 2026-06-12.

## Vtable Bases

| Object offset | Vtable base | Preceding locator | Notes |
| --- | --- | --- | --- |
| `+0x00` | `0x006219e8` | primary table begins at the documented memory child start | Primary `Pane` view; first slot is scalar deleting destructor `0x00544f50`. |
| `+0xa0` | `0x00621a34` | `0x00621a30` | Secondary event/handler view; first slot is adjustor thunk `0x00544f2e`. |
| `+0xa4` | `0x00621a64` | `0x00621a60` | Tertiary handler view; first slot is adjustor thunk `0x00544f39`. |

Offsets `0xa0` and `0xa4` are 160 and 164 respectively (Verified with `int_convert.py`).

## Evidence

- IDA MCP `entity_query` confirms decorated table names `??_7Pane@@6B@`, `??_7Pane@@6B@_0`, and `??_7Pane@@6B@_1` at `0x006219e8`, `0x00621a34`, and `0x00621a64`.
- B002 2026-06-17 resolved the primary slot used by [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md): `0x00621a08` is primary vtable slot `+0x20` and points to `0x00544800`, the `Pane::InvalidateRect` dirty-rect helper.
- B003 2026-07-12 resolved primary slot `+0x24`, cell `0x00621a0c`, to fresh [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md): `void Pane::GetDescription(int,wchar_t *)`. Exact body writes one wide NUL only for index `-1`; 382 vtable data refs and [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md) establish the shared virtual contract.
- B004 2026-07-13 resolved primary slot `+0x0c`, cell `0x006219f4`, to `0x004b8e20` and the source-facing contract `UpdateRenderRegion(const RectBounds *)`. Fresh [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md) dispatches this slot with an all-zero rectangle after `RemoveFromLayer`; independent primary slot `+0x2c` remains `SetBounds`, rejecting that stale alias.
- B001 2026-07-26 live cross-family verification corrects the prior `+0x48` interpretation: `0x00621a30` is the four-byte complete-object-locator pointer immediately before Pane's secondary `+0xa0` EventHandler-facet table at `0x00621a34`. It is not callable and is not part of the primary table. PanelPane introduces its own pure `+0x48 OnActivate(const unsigned char *packetData)` contract; eight derived PanelPane-family implementations support that separate slot.
- `lookup_funcs` reports constructor `0x00544460-0x00544578`, teardown/destructor helper `0x00544580-0x00544687`, scalar deleting destructor `0x00544f50-0x00545086`, and 11-byte adjustor thunks at `0x00544f2e` and `0x00544f39`.
- `xrefs_to` reports all three table-base store triads: `0x005444bb`/`0x005445b4`/`0x00544f8b` for the primary base, `0x005444c1`/`0x005445ba`/`0x00544f91` for the secondary base, and `0x005444cb`/`0x005445c0`/`0x00544f97` for the tertiary base.
- `get_int` reads `0x00621a6c` as the neighboring `PanelPane` RTTI locator, proving the exclusive end of the exact backing memory child. The backing table body is `0x84` / 132 bytes from `0x006219e8` through `0x00621a6c` (Verified with `int_convert.py`).

## Primary Slot Direction

The inherited primary Pane virtual span is documented with source-facing names where resolved:

| Slot | Target | Direction |
| --- | --- | --- |
| `+0x00` | `0x00544f50` | scalar deleting destructor wrapper for `virtual Pane::~Pane()` |
| `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass()` |
| `+0x08` | `0x0041b6c0` | inherited `LObject::OnChangeMessage(LObject *, Message *)` default |
| `+0x0c` | `0x004b8e20` | `Pane::UpdateRenderRegion(const RectBounds *)`; used by UID0004KU with an all-zero rectangle; distinct from `SetBounds` at `+0x2c` |
| `+0x10` | `0x0041d680` | inferred `Pane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`; exact default is a three-argument no-op ending in `retn 0x0c` |
| `+0x14` | `0x00544730` | `Pane::Show` |
| `+0x18` | `0x00544750` | `Pane::Hide` |
| `+0x1c` | `0x005447a0` | `Pane::GetParentPane()`; reads attached Layer and calls its parent-pane lookup |
| `+0x20` | `0x00544800` | `Pane::InvalidateRect` |
| `+0x24` | `0x00544a20` | [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md); base default clears output only for sentinel `-1` |
| `+0x28` | `0x00544b80` | `Pane::GetScreenBounds` |
| `+0x2c` | `0x00544bd0` | `Pane::SetBounds` |
| `+0x30` | `0x00544c70` | `Pane::AddToLayer` |
| `+0x34` | `0x00544cb0` | `Pane::InsertInLayer` |
| `+0x38` | `0x00544ce0` | `Pane::RemoveFromLayer` |
| `+0x3c` | `0x00544d30` | `Pane::SetPaneOrder` / dispatcher order helper |
| `+0x40` | `0x00544d70` | `Pane::UnregisterEventHandler` |
| `+0x44` | `0x0041b6a0` | empty `Pane::OnPaint()` default; final primary slot |

The `UpdateRenderRegion` and `DrawOnTarget` spellings remain source-facing
inferences rather than recovered symbols, but their signatures and slot roles
are supported by direct call and caller-argument evidence. The `+0x10`
original lexical spelling remains stripped; its ABI, no-op body, and
target-drawing direction are resolved. Pane has exactly 18 primary slots from
`+0x00` through `+0x44`; activation is not a Pane primary contract.

## Secondary And Tertiary Contract

- Secondary `+0xa0` view contains the destructor adjustor followed by the exact EventHandler order: pointer/mouse, key/text, IME, packet, system/control, type-19, handler order, local pair, screen pair, and acceptance predicate.
- Tertiary `+0xa4` view contains the destructor adjustor followed by `Pane::OnTimer(int timerId, int arg0, int arg1)`, whose inherited default returns true.
- EventHandler and TimerHandler are inherited facets of Pane. Derived class declarations must not add them as extra direct source bases or explicit vptr members.

## UID000090 Concrete Facet Source Causality - 2026-07-31

- Pane's complete source declaration is concrete because exact source children [UID:0004ZP][0x00544db0-0x00544e09.PaneDefaultEventHandlers](by-memory/0x00544db0-0x00544e09.PaneDefaultEventHandlers.md) provide all six EventHandler defaults in slot order, [UID:0004ZQ][0x00544e10-0x00544e25.PaneGetLocalOffset](by-memory/0x00544e10-0x00544e25.PaneGetLocalOffset.md) and [UID:0004ZR][0x00544e30-0x00544e66.PaneGetScreenOffset](by-memory/0x00544e30-0x00544e66.PaneGetScreenOffset.md) provide Point-offset overrides, and [UID:0004ZS][0x00544e70-0x00544e8a.PaneShouldAcceptEvent](by-memory/0x00544e70-0x00544e8a.PaneShouldAcceptEvent.md) provides the acceptance predicate.
- [UID:0004ZT][0x00544e90-0x00544e95.PaneOnTimer](by-memory/0x00544e90-0x00544e95.PaneOnTimer.md) supplies the source-authored tertiary default. [UID:0004ZU][0x00544ea0-0x00544eda.PaneSetFocusRegistration](by-memory/0x00544ea0-0x00544eda.PaneSetFocusRegistration.md) is a non-virtual Pane helper that synchronizes focus registration and therefore does not add a vtable cell.
- The compiler generates the three vtable facets and required destructor adjustors from the complete multiple-inheritance declaration and overrides. No literal table array, manual secondary-receiver arithmetic, explicit vptr member, or handwritten adjustor is emitted.
- Historical abstract-Pane/bridge-thunk wording is superseded for these methods. The six delegating bodies are source overrides required to make Pane concrete; their short tail-dispatch lowering does not turn them into compiler-only thunks.

## UID000090 Complete Source Declaration Causality - 2026-07-31

- Pane's three physical vtable facets are compiler output generated from the complete source declaration `Pane : public GrafPort, public EventHandler, public TimerHandler`. They are not three handwritten table arrays, three independent object types, or evidence for redundant direct bases in every derived pane.
- The secondary EventHandler facet is concretized by exact source children [UID:0004ZP][0x00544db0-0x00544e09.PaneDefaultEventHandlers](by-memory/0x00544db0-0x00544e09.PaneDefaultEventHandlers.md), [UID:0004ZQ][0x00544e10-0x00544e25.PaneGetLocalOffset](by-memory/0x00544e10-0x00544e25.PaneGetLocalOffset.md), [UID:0004ZR][0x00544e30-0x00544e66.PaneGetScreenOffset](by-memory/0x00544e30-0x00544e66.PaneGetScreenOffset.md), and [UID:0004ZS][0x00544e70-0x00544e8a.PaneShouldAcceptEvent](by-memory/0x00544e70-0x00544e8a.PaneShouldAcceptEvent.md). The six default event bodies are ordinary Pane overrides delegating to EventHandler defaults, not abstract slots or compiler-only bridges.
- The tertiary TimerHandler facet is concretized by [UID:0004ZT][0x00544e90-0x00544e95.PaneOnTimer](by-memory/0x00544e90-0x00544e95.PaneOnTimer.md), whose source declaration retains the three virtual-contract parameters and whose body returns true.
- [UID:0004ZU][0x00544ea0-0x00544eda.PaneSetFocusRegistration](by-memory/0x00544ea0-0x00544eda.PaneSetFocusRegistration.md) is an ordinary Pane helper rather than a facet slot; it is documented here because it closes the adjacent InputMan registration dependency without changing any vtable shape.
- Historical descriptions of Pane as abstract, the six methods as adjustor-only bridges, or the timer body as an inherited compiler default are superseded. Compiler generation still owns COL records, table cells, secondary/tertiary destructor adjustors, and the scalar deleting destructor.

## Assignment Gate

This page is a single-owner Pane vtable declaration record at `90/94`; the direct class parent is `90/91`, and the backing memory child remains assigned to the same class. Resolving `+0x0c` and correcting the false `+0x48` callable interpretation improves this source-local table without changing the broader [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md), which remains parentless because it spans five direct owners.

## Reconstruction Notes

Do not emit literal vtable bytes from this page. Reconstruct the source-level `Pane` class declaration, inherited interfaces, and virtual method definitions that cause the compiler to emit these primary/secondary/tertiary tables.

Completion `90` and confidence `94` reflect exact `+0x24`, resolved `+0x0c` UpdateRenderRegion behavior, the exact 18-slot primary endpoint at `+0x44`, and the corrected secondary-COL identity at `0x00621a30` while preserving all raw addresses, other slot decisions, and compiler exclusions. Original source spelling and unrelated inherited/default slots remain the score cap; this formal block stays blank because vtable literals are compiler output.

## Pane Versus PanelPane Activation Provenance

- Exact Pane primary table `[0x006219e8,0x00621a30)` contains 18 callable dwords. `0x00621a2c` is `+0x44 Pane::OnPaint`; `0x00621a30` begins secondary RTTI metadata, and the secondary vtable starts at `0x00621a34`.
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md) independently reproduces the inherited Pane primary contract: its PhotoPane primary view also has exactly 18 cells and ends at `+0x44 PhotoPane::OnPaint`, followed by a secondary COL pointer rather than an activation slot.
- PanelPane's separate primary family contains a real `+0x48` pure cell and derived implementations. That evidence establishes `OnActivate(const unsigned char *)` as a PanelPane-introduced contract, not an inherited Pane method.
- Historical correction: the 2026-07-13 B004 pass correctly resolved the derived activation signature and implementation matrix but attached it to the wrong table owner by treating Pane secondary COL cell `0x00621a30` as callable. The activation research is preserved and rerouted to PanelPaneVtables; only Pane ownership is superseded.

## Cross-References

- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0003CA][0x006219e8-0x00621a6c.PaneVtableData](by-memory/0x006219e8-0x00621a6c.PaneVtableData.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md)
- [UID:0004KU][0x00544ee0-0x00544f2e.PaneCollapse](by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md)
- [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md)

## DescPane Vtable Support Synchronization - 2026-07-16

- Preserved `90/94`, owner/emitter UID0000A2, reconstructable true, blank
  position/formal, and every current B004 slot, table, boundary, and facet
  fact.
- Finalized the bounded source direction for primary `+0x10` as
  `DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`.
  Evidence is the exact no-op ABI, Layer caller arguments, 381 derived table
  refs observed in the target research, and behaviorally matching derived
  overrides.
- Primary `+0x1c` remains exact `GetParentPane`; no Repaint alias, extra direct
  EventHandler/TimerHandler base, literal table array, or handwritten adjustor
  is introduced.

## Changes

- 2026-07-31 B002 UID000090 dependency callback: linked exact children UID0004ZP-0004ZT to Pane's concrete EventHandler/TimerHandler facet declarations, classified UID0004ZU as a non-virtual helper, historicalized abstract/bridge-only treatment, and preserved compiler ownership of literal tables and adjustors.

- 2026-07-31 B002 UID000090 dependency callback: tied all three Pane facets to the complete source declaration, registered exact source children UID0004ZP-0004ZT, distinguished UID0004ZU as an ordinary adjacent helper, and historicalized abstract/bridge-only interpretations without emitting table data.

- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Preserved `90/94`, owner/emitter UID0000A2, reconstructable state, and blank formal blocks.
  - Removed the false Pane primary `+0x48 OnActivate` row; exact bytes/items prove `0x00621a30` is the secondary COL pointer and Pane primary ends at `+0x44 OnPaint`.
  - Preserved the valid activation signature and eight-derived implementation evidence by rerouting its ownership to PanelPane, which introduces the pure `+0x48` contract.
  - Added independent PhotoPane inherited-table corroboration and retained the earlier misclassification as an explicit historical correction rather than deleting it.

- 2026-07-16 B001 UID0002NA bounded support synchronization:
  - Added only the accepted `DrawOnTarget` direction at primary `+0x10`,
    preserving `90/94` and the complete concurrent B004 union.
- 2026-07-16 B004 UID0002NB accepted support synchronization:
  - Preserved `90/94`, owner/emitter UID0000A2, reconstructable true, blank position/formal, all table bases/stores/boundaries, and unrelated slot history.
  - Corrected primary `+0x1c` from stale `Repaint` to exact `Pane::GetParentPane()`, resolved `+0x04/+0x08/+0x10/+0x44`, and documented the complete inherited EventHandler/TimerHandler facet order used by DialogSession/DialogInSession.
  - No score, formal, owner, or emitter inflation was applied.
- 2026-07-13 B004 UID00015Y accepted callback: raised `89/93 -> 90/94`; resolved primary `+0x0c` / `0x006219f4 -> 0x004b8e20` as `UpdateRenderRegion(const RectBounds *)`, primary `+0x48` as the pure-base/common `OnActivate(const unsigned char *)` contract, linked exact UID0004KU PaneCollapse evidence, and preserved raw table addresses, compiler-generated tables/wrappers/thunks, RTTI boundaries, and source-spelling caveats.
- 2026-07-12 B003 UID00012O accepted callback: raised completion `88 -> 89` with confidence unchanged `93`; replaced stale primary `+0x24` default-command direction with exact UID0004IX `Pane::GetDescription(int,wchar_t *)`, sentinel/wide-NUL semantics, vtable fanout, and DescPane consumer. All other slot targets, table ranges, owner/file routes, broader mixed-family disposition, adjustor/scalar-destructor compiler handling, and blank formal block remain unchanged.
- 2026-06-18 B002 PaneCore source-quality execution: added the primary-slot direction table for the `Pane` virtual span so [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) can remain a non-emitting split/index while exact method children inherit consistent source-facing slot names.

- 2026-06-17 B002 `PaneSetMode` support sync: recorded primary vtable slot `+0x20` / `0x00621a08 -> 0x00544800` as `Pane::InvalidateRect`, closing the previous target-side slot-name blocker for [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md).

- 2026-06-12 A004 Batch 336:
  - Created this exact source-local vtable page from the previous mixed [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md) aggregate.
  - Evidence: live IDA MCP confirmed decorated bases, constructor/destructor/scalar-destructor store triads, function sizes, adjustor-thunk sizes, and the `PanelPane` successor boundary.
  - Gate: assigned to [UID:0000A2][Pane](by-class/Pane.md) because the child and direct parent both clear the strict `85/85` gate.
