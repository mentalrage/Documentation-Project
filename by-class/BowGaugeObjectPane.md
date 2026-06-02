*** UID:000011 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: strong for class anchors, global lifecycle, timer-helper ownership, and local-player HUD behavior; medium-high for final source split because it may be standalone or a private `UserPane` companion.
- Likely source file: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), possibly private to [UID:0000P1][UserPane](by-file/UserPane.md)
- Current recovered file: `source-3/simroot_v2/class_BowGaugeObjectPane.cpp`
- Singleton global: [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) at `0x0069ba24`
- Vtable/resource data: [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md) and [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md)

## Class Purpose

`BowGaugeObjectPane` is a local-player HUD pane that draws and animates the bow gauge. It creates a `Pane` child, stores `g_pBowGaugeObjectPane`, renders `BGAUGE.EPF` frames, composites pixels into its buffer, and reschedules timer-driven updates.

## Ownership And Layout Evidence

| Topic | Evidence |
| --- | --- |
| Source owner | [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) documents `NexusTK/ui/panels/` placement, with an open caveat that the original source may have kept this as a private [UID:0000P1][UserPane](by-file/UserPane.md) companion. |
| Base/role separation | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) and [UID:0000M5][ObjectPane](by-file/ObjectPane.md) both exclude this class despite the generated name because it constructs through `Pane` and is allocated by `UserPane`, not the attached-object base. |
| Vtable data | [UID:0002SM][0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData](by-memory/0x006205fc-0x00620894.EffectGaugeDamageInfoObjectPaneVtableData.md) maps the mixed object-pane vtable child to `BowGaugeObjectPane` via the executable anchors in [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md). |
| Resource strings | [UID:0002SO][0x00620b90-0x00620bf8.ObjectPaneResourceStrings](by-memory/0x00620b90-0x00620bf8.ObjectPaneResourceStrings.md) records object-pane resource strings, including the bow-gauge paint consumer at `0x00538cbc`. |
| Singleton state | [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) and [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) document the constructor write, destructor clear, and `UserPane` show/hide/destructor consumers. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) dependency | `0x004ba540-0x004ba6ad` | Shared 16-bit GrafPort/surface helper currently emitted as a BowGauge method; also called by TextEditPane draw/invalidation paths. |
| constructor | `0x00538bc0-0x00538c0a` | Constructs `Pane`, stores the global active pointer, and installs vtables. |
| [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | `0x00538c40-0x00538c4b` | Tiny helper that removes pending timers for the timer-handler subobject at `this + 0xa4`; currently generated as `BulletinSession::RemoveFromUpdateScheduler`. |
| `OnPaint` | `0x00538c50-0x00538cfa` | Draws current `BGAUGE.EPF` frame and composites pixels. |
| `OnShow` | `0x00538d10-0x00538d4b` | Invokes a callback and schedules a timer. |
| scalar deleting destructor | `0x0053cfe0-0x0053d025` | Clears the global active pointer, tears down the base pane, and frees memory when requested. |

## Evidence Notes

- IDA confirms the constructor is called from `UserPane::UserPane` at `0x005a2956`.
- IDA caller checks on 2026-05-25 confirm `0x004ba540` is shared with [UID:0000EO][TextEditPane](by-class/TextEditPane.md), so it is a dependency rather than BowGauge-owned source.
- IDA MCP on 2026-05-26 confirms `0x00538c40` is a one-call wrapper around timer removal at `this + 0xa4`; callers are only `UserPane` destructor/hide paths that read [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md).
- IDA MCP `xrefs_to 0x0069ba24` ties the global to the BowGauge constructor/destructor and `UserPane` show/hide/destructor cleanup.
- Generated helper names in `OnPaint` currently reference fitting-room classes; treat those as helper-owner pollution until reviewed.
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) records concrete global xrefs: constructor write at `0x00538be4`, destructor clear at `0x0053cfe6`, and `UserPane` cleanup/show/hide reads.
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) proves the generated `BowGaugeObjectPane::CompositePixels` ownership is polluted by recording TextEditPane callers at `0x00590960` and `0x005917a3`.

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
