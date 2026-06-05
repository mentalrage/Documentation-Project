*** UID:000011 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: high for class anchors, global lifecycle, timer-helper ownership, resource/vtable evidence, and local-player HUD behavior; medium-high for final source split because it may be standalone or a private `UserPane` companion.
- Likely source file: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), possibly private to [UID:0000P1][UserPane](by-file/UserPane.md)
- Singleton global: [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) at `0x0069ba24`
- Vtable/resource data: [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md) and [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md)

## Class Purpose

`BowGaugeObjectPane` is a local-player HUD pane that draws and animates the bow gauge. It creates a `Pane` child, stores `g_pBowGaugeObjectPane`, renders `BGAUGE.EPF` frames, composites pixels into its buffer, and reschedules timer-driven updates.

## Ownership And Layout Evidence

| Topic | Evidence |
| --- | --- |
| Source owner | [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) documents `NexusTK/ui/panels/` placement, with an open caveat that the original source may have kept this as a private [UID:0000P1][UserPane](by-file/UserPane.md) companion. |
| Base/role separation | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) and [UID:0000M5][ObjectPane](by-file/ObjectPane.md) both exclude this class despite the object-pane-like name because it constructs through `Pane` and is allocated by `UserPane`, not the attached-object base. |
| Vtable data | [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md) maps the mixed object-pane vtable child to `BowGaugeObjectPane` via the executable anchors in [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md). |
| Resource strings | [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md) records object-pane resource strings, including the bow-gauge paint consumer at `0x00538cbc`. |
| Singleton state | [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) and [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) document the constructor write, destructor clear, and `UserPane` show/hide/destructor consumers. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) dependency | `0x004ba540-0x004ba6ad` | Shared 16-bit GrafPort/surface helper mislabeled as a BowGauge method by some current labels; also called by TextEditPane draw/invalidation paths. |
| constructor | `0x00538bc0-0x00538c0a` | Constructs `Pane`, stores the global active pointer, and installs vtables. |
| [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | `0x00538c40-0x00538c4b` | Tiny helper that removes pending timers for the timer-handler subobject at `this + 0xa4`; `BulletinSession` labeling is owner pollution. |
| `OnPaint` | `0x00538c50-0x00538cfa` | Draws current `BGAUGE.EPF` frame and composites pixels. |
| `OnShow` | `0x00538d10-0x00538d4b` | Invokes a callback and schedules a timer. |
| scalar deleting destructor | `0x0053cfe0-0x0053d025` | Clears the global active pointer, tears down the base pane, and frees memory when requested. |

## Live IDA Evidence

- IDA MCP confirms `sub_538BC0` at `0x00538bc0-0x00538c0a`. It calls `sub_544460(this, 1)`, stores `this` to `dword_69BA24` / [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md), and installs three BowGauge vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- IDA MCP confirms `sub_538C40` at `0x00538c40-0x00538c4b` as a timer cleanup wrapper around `sub_597600(this+0xa4)`.
- IDA MCP confirms `sub_538C50` at `0x00538c50-0x00538cfa` as paint: it initializes scratch state, clears pane text state, invalidates `this+0x44`, gates drawing on byte `dword_67A748+0x1d1`, derives a frame from `(timeGetTime() - this+0xf8) / 0x8a` clamped to `36`, looks up `BGAUGE.EPF`, renders with `BGAUGE.pal`, then calls shared compositor `sub_4BA540`.
- Resource refs are direct and unique to paint: `0x00538cbc -> 0x00620b90` (`BGAUGE.EPF`) and `0x00538cc8 -> 0x00620ba8` (`BGAUGE.pal`).
- `sub_4BA540` at `0x004ba540-0x004ba6ad` has code callers at `0x00538ce5` from BowGauge paint and at `0x00590960`/`0x005917a3` from TextEditPane paths, confirming it remains a shared compositor dependency.
- IDA MCP confirms `sub_538D10` at `0x00538d10-0x00538d4b` as the show/timer path: it invokes a secondary-base virtual callback through the `this-0xa4` view and schedules timer work through `sub_597910(dword_67AB80, adjustedThis, 1, 1, 0, 0)`.
- IDA MCP confirms `sub_53CFE0` at `0x0053cfe0-0x0053d025` as scalar deleting destructor behavior: it clears `dword_69BA24`, calls pane cleanup `sub_544580`, and conditionally frees through `sub_4F4AC0`.
- Live xrefs to `0x0069ba24` include constructor write `0x00538be4`, destructor clear `0x0053cfe6`, `UserPane` destructor reads at `0x005a2d1b`/`0x005a2d2d`, show/name-label reads at `0x005a8e97`, `0x005a8ea2`, `0x005a8ef2`, `0x005a8f0e`, `0x005a8f3f`, hide read at `0x005a8f71`, another show/update read at `0x005a8fe5`, and scalar-destructor reads at `0x005b82f2`/`0x005b8304`.
- BowGauge vtable slots in the mixed object-pane vtable block include scalar deleting destructor `0x006206b0 -> 0x0053cfe0`, paint `0x006206f4 -> 0x00538c50`, and show/timer `0x00620730 -> 0x00538d10`.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) because the class page now has a validated source-root candidate, exact method anchors, global lifecycle evidence, and resource/vtable-data links.
- Keep reconstructed C++ blank for now. The page still lacks final field names for the timer-handler subobject, frame/current-state fields, and paint callback path, and the source split between standalone `BowGaugeObjectPane.cpp` and a private `UserPane` companion is not final.
- Do not move the shared [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) helper into BowGauge source; it remains a GrafPort/Surface helper dependency.

## Cross-References

- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md)
- [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)

## Changes

- 2026-06-02:
  - Before: scored `68/76`, with reconstructable/parent blank and no class-level vtable/resource/global evidence map.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md).
  - Summary/evidence: added source-owner, base-separation, vtable-data, resource-string, global lifecycle, timer-helper, and shared-compositor evidence from existing recorded IDA-backed docs. C++ remains blank because final field names and standalone-versus-UserPane source placement remain unresolved.
- What existed before: the page had class anchors, method notes, global ownership, and helper-pollution caveats, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: IDA-backed constructor/destructor/global/timer evidence supports the class identity, while file placement and shared helper ownership remain unresolved enough to cap both completion and confidence.
- 2026-06-04 live IDA refresh:
  - Before: the class was scored `78/84` and had strong anchors but lacked current method-body, resource, vtable-slot, and global-consumer detail.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with C++ reconstruction still blank.
  - Summary/evidence: live IDA confirms exact method ranges, constructor/global/vtable writes, `g_pBowGaugeObjectPane` lifecycle and UserPane consumer xrefs, paint behavior with `BGAUGE.EPF`/`BGAUGE.pal`, the shared `sub_4BA540` caller set, show/timer scheduling, and vtable slots for destructor/paint/show. The score remains below final because field names and standalone-vs-UserPane source split are still not final-source quality.
