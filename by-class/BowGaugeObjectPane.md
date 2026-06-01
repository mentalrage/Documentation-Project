*** UID:000011 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: strong for class anchors; medium for original file placement.
- Likely source file: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md), possibly private to [UID:0000P1][UserPane](by-file/UserPane.md)
- Current recovered file: `source-3/simroot_v2/class_BowGaugeObjectPane.cpp`
- Current Wave3 grade: `97.6`
- Current Wave3 coverage: 7 modeled methods, zero missing target refs.
- Singleton global: [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) at `0x0069ba24`

## Class Purpose

`BowGaugeObjectPane` is a local-player HUD pane that draws and animates the bow gauge. It creates a `Pane` child, stores `g_pBowGaugeObjectPane`, renders `BGAUGE.EPF` frames, composites pixels into its buffer, and reschedules timer-driven updates.

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

## Cross-References

- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)

## Changes

- What existed before: the page had class anchors, method notes, global ownership, and helper-pollution caveats, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: IDA-backed constructor/destructor/global/timer evidence supports the class identity, while file placement and shared helper ownership remain unresolved enough to cap both completion and confidence.
