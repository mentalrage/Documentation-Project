*** UID:0000HU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: very strong for the complete direct Pane/Singleton class, exact `0xfc` EBO layout, sole singleton definition, six authored methods, UserPane lifecycle, vtable/resource coverage, compiler exclusions, and standalone source route; historical private-companion grouping remains rejected provenance.
- Proposed module: `ui/panels/BowGaugeObjectPane.cpp`; [UID:0000P1][UserPane](by-file/UserPane.md) owns callers that manipulate the pane but does not replace this emitter route.
- Proposed reconstruction path: `NexusTK/ui/panels/`
- Primary class doc: [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- Main address doc: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)

## File Role

`BowGaugeObjectPane` is not part of the attached map-object hierarchy despite the object-pane-like name. It derives directly from `Pane` and empty `Singleton<BowGaugeObjectPane>`, is allocated by `UserPane::UserPane`, owns one external active pointer definition, draws `BGAUGE.EPF`, and schedules timer-driven repaint/update work.

Some current helper labels in drawing calls are owner-polluted fitting-room names. Those helper labels should not move the class into `cashshop/FittingRoom.cpp` without stronger caller evidence.

[UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) and [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) confirm the active-pane pointer belongs to this local-player HUD feature: constructor write at `0x00538be4`, destructor clear at `0x0053cfe6`, and `UserPane` show/hide/destructor consumers.

[UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) ties the exact BowGauge vtable data back to the executable anchors, while [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) and parent inventory [UID:0002SO][0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants](by-memory/0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants.md) record resource-string consumers including the bow-gauge paint path.

2026-07-07 B005 current MCP evidence keeps UID000352 on this source route: compiler-emitted BowGauge RTTI/vtable data is regenerated through the `BowGaugeObjectPane` class declaration, virtual methods, scalar destructor and adjusted thunks, and the current `NexusTK/ui/panels/BowGaugeObjectPane.cpp` route. It should not be emitted as a hand-authored vtable table.

## 2026-07-21 B002 Complete File Contract

### Exact source order

| Position | UID | Source/content role |
| --- | --- | --- |
| 0 | [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) | Sole external `BowGaugeObjectPane *` definition initialized to zero. |
| 10 | [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) | Complete Pane plus Singleton class, inline empty virtual destructor, terminal tick field, size guard, extern declaration, and child insertion point. |
| 20 | [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) | Authored base initialization only. |
| 30 | [UID:0004VO][0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation](by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md) | Epoch store plus timer schedule. |
| 40 | [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | Inherited TimerHandler cleanup wrapper. |
| 50 | [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) | Exact background, frame lookup/render, and composite behavior. |
| 60 | [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) | Exact one-store setter. |
| 70 | [UID:0004VQ][0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer](by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md) | Adjusted TimerHandler callback; historical OnShow rejected. |
| 80 | [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) | Compiler-generated ABI covered marker only. |
| 90 | [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) | Source literals covered by OnPaint; no standalone arrays. |

### Header, include, and one-definition route

- The source requires the Pane/Singleton class declarations, timer wrappers, EPFTileContext/RectBounds/GrafPort rendering declarations, EPF library global, UserPane declaration/global, and `timeGetTime` visibility.
- UID000011 carries the `extern BowGaugeObjectPane *g_pBowGaugeObjectPane` declaration. UID0000QA carries the sole definition. Physical UID0001PY is false/non-emitting.
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) declares BowGauge friendship so `OnPaint` can preserve direct access to inherited UserPane `m_nameVisible` without inventing a getter.
- UserPane remains a separate source root and caller. External global linkage and class/header visibility are required across the two translation units.

### Compiler and data exclusions

- Do not emit constructor singleton publication/null adjustment, destructor singleton clear, vptr stores, EH/security cookies, adjusted thunks, scalar deleting flags, Pane teardown calls, sized/generic delete, RTTI/vtable arrays, or separate resource arrays.
- Do not expose `+0xa0`/`+0xa4` as explicit fields; Pane supplies inherited EventHandler/TimerHandler views.
- Do not initialize the separate OnPaint `compositeRect`, add null/result checks, release frame buffers, add a lower frame clamp, or change unconditional composite ordering.
- Broad UID0001DB and UID0001DL remain mixed non-emitting inventories. Exact children carry all authored source or compiler/data dispositions.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BowGaugeObjectPane` | `0x00538bc0-0x00538d4b`, compiler scalar wrapper at `0x0053cfe0` | Local-player bow gauge pane with exact constructor/animation/cleanup/paint/setter/timer source and one external active pointer. |
| [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) | `0x0069ba24` | Active bow-gauge pane pointer written by the constructor, cleared by the destructor, and consumed by `UserPane` cleanup/show/hide paths. |
| [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) | `0x00538bc0-0x00538c0a` | Exact source constructor; Singleton publication/null adjustment and vptr stores remain compiler lowering. |
| [UID:0004VO][0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation](by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md) | `0x00538c10-0x00538c3a` | Stores unsigned animation epoch and schedules timer `(1,1,0,0)`. |
| [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | `0x00538c40-0x00538c4b` | Public lifecycle wrapper delegates to the inherited `TimerHandler` facet; historical `BulletinSession` labeling is owner pollution. |
| [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) | `0x00538c50-0x00538cfa` | Exact behavior-identical paint override with resource literals and preserved uninitialized composite rectangle. |
| [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) | `0x00538d00-0x00538d10` | Exact `SetAnimationStartTick(unsigned int)` source member that stores `m_animationStartTick` at `+0xf8`; UID0004SL is its target-live UserPane caller and `OnPaint` consumes the field for elapsed-frame selection. |
| [UID:0004VQ][0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer](by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md) | `0x00538d10-0x00538d4b` | Exact adjusted TimerHandler callback invalidates, reschedules, and returns true; not OnShow. |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) dependency | `0x004ba540-0x004ba6ad` | `GrafPort::CompositePixels`, not a BowGauge-owned helper. `BowGaugeObjectPane::OnPaint` remains one direct consumer at `0x00538ce5` after drawing `BGAUGE.EPF`/`BGAUGE.pal`; TextEditPane owns the other two direct call sites. |

## Boundary Notes

- IDA reports the constructor xref from `UserPane::UserPane` at `0x005a2956`, not from fitting-room construction.
- Calls labeled `FittingRoomListPane::SetTextColor` and `FittingRoomDownloadControlPane::RenderTileFrame` should be treated as polluted helper labels until the underlying helpers are reviewed.
- IDA MCP caller checks and B003's 2026-06-18 raw PE recheck show `0x004ba540` also called from [UID:0000ON][TextEditPane](by-file/TextEditPane.md) draw and invalidation functions. That makes `BowGaugeObjectPane::CompositePixels` an owner-label artifact; [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) is now best routed as `GrafPort::CompositePixels`.
- Raw PE/IDA-backed evidence confirms `sub_538C40` at `0x00538c40-0x00538c4b` as `BowGaugeObjectPane::RemovePendingTimers()`: it adjusts `ecx` by `+0xa4` and tail-jumps to [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) at `0x00597600`. Fresh B003 rel32/dword scans find exactly three direct UserPane cleanup/hide callers and no hidden VA/RVA/raw pointer-table route; keep it here instead of `BulletinSession`.
- Keep this class out of [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md); it does not use the attached-object base constructor/destructor path.
- `by-project-structure/proposed-source-tree.md` lists `ui/panels/BowGaugeObjectPane.cpp` beside `UserPane.cpp`; function/data/global/class clustering and external consumers make this the accepted route. The older private-companion possibility remains historical only.

## Live IDA Evidence

- IDA MCP confirms `sub_538BC0` at `0x00538bc0-0x00538c0a`. It calls `sub_544460(this, 1)`, stores `this` to `dword_69BA24` / [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md), and installs three BowGauge vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- IDA MCP plus B003 raw PE recheck confirm `sub_538C40` at `0x00538c40-0x00538c4b` as `BowGaugeObjectPane::RemovePendingTimers()`, a source-shaped member wrapper that adjusts to the `TimerHandler` facet at `this+0xa4` and tail-jumps to `TimerHandler::RemovePendingTimers`.
- IDA MCP confirms `sub_538C50` at `0x00538c50-0x00538cfa` as paint: it initializes scratch state, clears pane text state, invalidates `this+0x44`, gates drawing on [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748` byte `+0x1d1`, derives a frame from `(timeGetTime() - this+0xf8) / 0x8a` clamped to `36`, looks up `BGAUGE.EPF`, renders with `BGAUGE.pal`, then calls `GrafPort::CompositePixels` at `0x004ba540`.
- Resource refs are direct and unique to paint: `0x00538cbc -> 0x00620b90` (`BGAUGE.EPF`) and `0x00538cc8 -> 0x00620ba8` (`BGAUGE.pal`).
- `GrafPort::CompositePixels` / historical `sub_4BA540` at `0x004ba540-0x004ba6ad` has exactly three direct rel32 callers in B003's current raw PE scan: `0x00538ce5` from BowGauge paint and `0x00590960`/`0x005917a3` from TextEditPane paths. It is a shared GrafPort pixel-effect dependency, not BowGauge source.
- IDA MCP confirms `sub_538D10` at `0x00538d10-0x00538d4b` as exact `OnTimer`: the inherited `+0xa4` TimerHandler receiver is normalized, `m_visibleBounds` is invalidated, timer `(1,1,0,0)` is rescheduled, and true is returned after three ignored arguments.
- IDA MCP confirms `sub_53CFE0` at `0x0053cfe0-0x0053d025` as scalar deleting destructor behavior: it clears `dword_69BA24`, calls pane cleanup `sub_544580`, and conditionally frees through `sub_4F4AC0`.
- Live xrefs to `0x0069ba24` include constructor write `0x00538be4`, destructor clear `0x0053cfe6`, `UserPane` destructor reads at `0x005a2d1b`/`0x005a2d2d`, show/name-label reads at `0x005a8e97`, `0x005a8ea2`, `0x005a8ef2`, `0x005a8f0e`, `0x005a8f3f`, hide read at `0x005a8f71`, another show/update read at `0x005a8fe5`, and scalar-destructor reads at `0x005b82f2`/`0x005b8304`.
- BowGauge vtable slots in the mixed object-pane vtable block include scalar deleting destructor `0x006206b0 -> 0x0053cfe0`, paint `0x006206f4 -> 0x00538c50`, and adjusted TimerHandler `OnTimer` `0x00620730 -> 0x00538d10`.
- 2026-07-07 B005 MCP evidence reconfirmed UID000352 as exact source-declared/generated-binary RTTI/vtable data on this file route: range `0x006206ac-0x00620734`, primary/adjusted bases `0x006206b0/0x006206fc/0x0062072c`, constructor stores `0x00538beb/0x00538bf1/0x00538bfb`, scalar destructor `0x0053cfe0`, adjusted thunks `0x0053cea4/0x0053ceaf`, paint slot `0x00538c50`, timer slot `0x00538d10`, and no raw source-authored vtable arrays.

## Cross-References

- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
- [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md)
- [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md)
- [UID:0002SO][0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants](by-memory/0x00620b90-0x00620c70.ObjectPaneResourceStringsAndOverlayConstants.md)

## Changes

- 2026-07-21 B002 UID0001PY implementation: raised `85/90` to `92/94` while retaining `NexusTK/ui/panels/`; added the exact position 0-90 global/class/six-method/vtable/resource order, four real child UIDs, complete Pane/Singleton EBO layout, one-definition/header/include route, direct Living friendship dependency, preserved OnPaint edge behavior, exact OnTimer correction, and exhaustive compiler/data exclusions. No by-file reconstruction metadata was added.

- 2026-07-16 B004 UID0003TQ source-route synchronization:
  - Changed `84/88` to `85/90`, retained `NexusTK/ui/panels/`, and added real UID0004SJ as the exact one-store `SetAnimationStartTick(unsigned int)` source member.
  - The current UID000011 class declaration now closes the former field/formal blocker with exact `0xfc` size and `m_animationStartTick`; UID0004SL supplies direct target-live caller evidence, while paint consumes the same field. Singleton/resource/vtable/timer/compositor facts and compiler-only vptr/adjustor/deleting-destructor/EH/table dispositions remain unchanged.
  - The older private-UserPane-companion possibility remains historical source-placement evidence, not a reason to route the source away from this current file emitter or leave C++ blank.

- 2026-06-07 A008 alias cleanup:
  - Before: the live paint evidence used bare `dword_67A748+0x1d1` wording for the player/client-state gate.
  - Changed to: linked [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the `g_pCollectionData` global page documents `0x0067a748` as a broad player/client-state pointer with many non-collection typed views.
- 2026-06-02:
  - Before: scored `70/82` with blank `PROPOSED_RECONSTRUCTION_PATH`, leaving the source root listed in projected-path errors despite already being represented in the proposed source tree.
  - After: scored `74/84` and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Summary/evidence: added global-memory, vtable-data, resource-string, and proposed-source-tree evidence. The page still keeps the standalone-vs-private-UserPane companion caveat, so confidence stays below final-source quality.
- What existed before: the page documented class behavior, owner pollution, anchors, and UserPane relationship but had unevaluated scores.
- What it was changed to: scores were set to `70/82`.
- Summary and evidence: behavior and anchors are strong; final source placement is still medium because it may live as a `UserPane` companion rather than a standalone file.
- 2026-06-04 live IDA refresh:
  - Before: the page was scored `74/84` and relied on older anchor summaries while still carrying owner-label pollution caveats.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, with no C++ added.
  - Summary/evidence: live IDA confirms exact method ranges, constructor/global/vtable writes, `g_pBowGaugeObjectPane` lifecycle and UserPane consumer xrefs, paint behavior with `BGAUGE.EPF`/`BGAUGE.pal`, the shared `sub_4BA540` caller set, show/timer scheduling, and vtable slots for destructor/paint/show. The score remains below final because field names and standalone-vs-UserPane source split are still not final-source quality.
- 2026-06-18 B003 CompositePixels support sync:
  - Score unchanged at `84/88`.
  - Changed [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) wording from a generic shared compositor dependency to the accepted `GrafPort::CompositePixels` route.
  - Evidence: B003 raw PE/Capstone recheck found the BowGauge paint caller at `0x00538ce5` after `BGAUGE.EPF`/`BGAUGE.pal` rendering plus TextEditPane callers at `0x00590960` and `0x005917a3`; the target body uses GrafPort draw state, embedded surface-context fields, and palette mapping rather than BowGauge-specific fields.
- 2026-06-18 B003 RemovePendingTimers support sync:
  - Score unchanged at `84/88`.
  - Updated [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) to `BowGaugeObjectPane::RemovePendingTimers()` and documented the `TimerHandler` facet at `this+0xa4`.
  - Evidence: exact bytes/padding, the tail-jump to [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) `TimerHandler::RemovePendingTimers`, three UserPane callers, no hidden pointer-table route, and BowGauge constructor vtable stores at `+0x00/+0xa0/+0xa4`.
- 2026-07-07 B005 UID000352 vtable marker support sync:
  - Score unchanged at `84/88`; proposed path and file-level metadata remain unchanged.
  - Added source-route support that UID000352 is regenerated by the `BowGaugeObjectPane` declaration, virtual methods, scalar destructor/adjusted thunks, and current `NexusTK/ui/panels/BowGaugeObjectPane.cpp` route rather than a hand-authored table.
  - Evidence: session `supervisor-nexustk-20260707` reconfirmed exact range `0x006206ac-0x00620734`, primary/adjusted bases `0x006206b0/0x006206fc/0x0062072c`, constructor stores `0x00538beb/0x00538bf1/0x00538bfb`, scalar destructor `0x0053cfe0`, adjusted thunks `0x0053cea4/0x0053ceaf`, paint slot `0x00538c50`, show/timer slot `0x00538d10`, and no source-authored raw table evidence.
