*** UID:0000HU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: high for class behavior, anchors, singleton lifecycle, vtable/resource evidence, and source folder; medium-high for final standalone-vs-private-companion source split.
- Proposed module: `ui/panels/BowGaugeObjectPane.cpp`, or a private companion in [UID:0000P1][UserPane](by-file/UserPane.md) if original source grouped local-player HUD children together.
- Proposed reconstruction path: `NexusTK/ui/panels/`
- Primary class doc: [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- Main address doc: [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)

## File Role

`BowGaugeObjectPane` is not part of the attached map-object hierarchy despite the object-pane-like name. It constructs through `Pane`, is allocated by `UserPane::UserPane`, stores a global active pointer, draws `BGAUGE.EPF`, and schedules timer-driven repaint/update work.

Some current helper labels in drawing calls are owner-polluted fitting-room names. Those helper labels should not move the class into `cashshop/FittingRoom.cpp` without stronger caller evidence.

[UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) and [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) confirm the active-pane pointer belongs to this local-player HUD feature: constructor write at `0x00538be4`, destructor clear at `0x0053cfe6`, and `UserPane` show/hide/destructor consumers.

[UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md) ties the mixed object-pane vtable child back to the BowGauge executable anchors, while [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md) records resource-string consumers including the bow-gauge paint path.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `BowGaugeObjectPane` | `0x00538bc0-0x00538d4b`, destructor at `0x0053cfe0` | Local-player bow gauge pane with EPF frame drawing, pixel compositing, show/timer behavior, and global active pointer. |
| [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) | `0x0069ba24` | Active bow-gauge pane pointer written by the constructor, cleared by the destructor, and consumed by `UserPane` cleanup/show/hide paths. |
| [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | `0x00538c40-0x00538c4b` | Private wrapper that removes pending timers from the timer-handler subobject at `this + 0xa4`; current `BulletinSession` labeling is owner pollution. |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) dependency | `0x004ba540-0x004ba6ad` | Shared 16-bit GrafPort/surface compositor called by this pane and TextEditPane drawing paths; do not migrate it as BowGauge-owned source. |

## Boundary Notes

- IDA reports the constructor xref from `UserPane::UserPane` at `0x005a2956`, not from fitting-room construction.
- Calls labeled `FittingRoomListPane::SetTextColor` and `FittingRoomDownloadControlPane::RenderTileFrame` should be treated as polluted helper labels until the underlying helpers are reviewed.
- IDA MCP caller checks show `0x004ba540` also called from [UID:0000ON][TextEditPane](by-file/TextEditPane.md) draw and invalidation functions. That makes `BowGaugeObjectPane::CompositePixels` an owner-label artifact rather than BowGauge-owned source.
- IDA MCP caller checks on 2026-05-26 show `0x00538c40` only reached from `UserPane` cleanup/hide paths through [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md); keep it here instead of `BulletinSession`.
- Keep this class out of [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md); it does not use the attached-object base constructor/destructor path.
- `by-project-structure/proposed-source-tree.md` already lists `ui/panels/BowGaugeObjectPane.cpp` beside `UserPane.cpp`; the valid projected path records that current preferred placement while preserving the private-companion caveat.

## Live IDA Evidence

- IDA MCP confirms `sub_538BC0` at `0x00538bc0-0x00538c0a`. It calls `sub_544460(this, 1)`, stores `this` to `dword_69BA24` / [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md), and installs three BowGauge vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- IDA MCP confirms `sub_538C40` at `0x00538c40-0x00538c4b` as a timer cleanup wrapper around `sub_597600(this+0xa4)`.
- IDA MCP confirms `sub_538C50` at `0x00538c50-0x00538cfa` as paint: it initializes scratch state, clears pane text state, invalidates `this+0x44`, gates drawing on byte `dword_67A748+0x1d1`, derives a frame from `(timeGetTime() - this+0xf8) / 0x8a` clamped to `36`, looks up `BGAUGE.EPF`, renders with `BGAUGE.pal`, then calls the shared compositor `sub_4BA540`.
- Resource refs are direct and unique to paint: `0x00538cbc -> 0x00620b90` (`BGAUGE.EPF`) and `0x00538cc8 -> 0x00620ba8` (`BGAUGE.pal`).
- `sub_4BA540` at `0x004ba540-0x004ba6ad` has code callers at `0x00538ce5` from BowGauge paint and at `0x00590960`/`0x005917a3` from TextEditPane paths, confirming it remains a shared compositor dependency.
- IDA MCP confirms `sub_538D10` at `0x00538d10-0x00538d4b` as the show/timer path: it invokes a secondary-base virtual callback through the `this-0xa4` view and schedules timer work through `sub_597910(dword_67AB80, adjustedThis, 1, 1, 0, 0)`.
- IDA MCP confirms `sub_53CFE0` at `0x0053cfe0-0x0053d025` as scalar deleting destructor behavior: it clears `dword_69BA24`, calls pane cleanup `sub_544580`, and conditionally frees through `sub_4F4AC0`.
- Live xrefs to `0x0069ba24` include constructor write `0x00538be4`, destructor clear `0x0053cfe6`, `UserPane` destructor reads at `0x005a2d1b`/`0x005a2d2d`, show/name-label reads at `0x005a8e97`, `0x005a8ea2`, `0x005a8ef2`, `0x005a8f0e`, `0x005a8f3f`, hide read at `0x005a8f71`, another show/update read at `0x005a8fe5`, and scalar-destructor reads at `0x005b82f2`/`0x005b8304`.
- BowGauge vtable slots in the mixed object-pane vtable block include scalar deleting destructor `0x006206b0 -> 0x0053cfe0`, paint `0x006206f4 -> 0x00538c50`, and show/timer `0x00620730 -> 0x00538d10`.

## Cross-References

- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)
- [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md)
- [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md)

## Changes

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
