*** UID:000011 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BowGaugeObjectPane : public Pane,
                           public Singleton<BowGaugeObjectPane>
{
public:
    BowGaugeObjectPane();
    virtual ~BowGaugeObjectPane() {}

    void StartAnimation(unsigned int startTick);
    void RemovePendingTimers();
    void SetAnimationStartTick(unsigned int startTick);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    unsigned int m_animationStartTick;
};

typedef char BowGaugeObjectPaneSizeMustBe252[
    sizeof(BowGaugeObjectPane) == 0xfc ? 1 : -1];

extern BowGaugeObjectPane *g_pBowGaugeObjectPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BowGaugeObjectPane

## Status

- Confidence: very strong for the complete `0xfc` Pane plus direct empty Singleton declaration, exact EBO field, class anchors, global lifecycle, six authored methods, timer-helper ownership, resource/vtable evidence, and standalone local-player HUD source. Historical private-UserPane-companion placement is retained only as rejected provenance.
- Source file: [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md); [UID:0000P1][UserPane](by-file/UserPane.md) is the source route of callers, not the class emitter.
- Singleton global: [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) at `0x0069ba24`
- Vtable/resource data: [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) and [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md)

## Class Purpose

`BowGaugeObjectPane` is a local-player HUD pane that draws and animates the bow gauge. It creates a `Pane` child, stores `g_pBowGaugeObjectPane`, renders `BGAUGE.EPF` frames, composites pixels into its buffer, and reschedules timer-driven updates.

## 2026-07-21 B002 Complete Source Declaration

### Direct bases, EBO, and exact layout

- RTTI names `Pane` and direct nonvirtual empty `Singleton<BowGaugeObjectPane>` bases. The Singleton PMD record has `mdisp +0xf8`, `pdisp -1`, `vdisp 0`, attributes `0x40`.
- Pane supplies inherited EventHandler and TimerHandler adjusted views at `+0xa0` and `+0xa4`; they are not additional direct BowGauge bases or explicit source fields.
- Empty-base optimization allows the first derived member `unsigned int m_animationStartTick` to occupy `+0xf8`, and the class ends exactly at `0xfc`. There is no reserve or tail-padding member.
- The size guard and class closing brace remain before `[[CHILDREN]]`.

### Authored methods and exact source order

| Position | UID / range | Source disposition |
| --- | --- | --- |
| 20 | [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) | `Pane(1)` and empty Singleton base initialization; publication/null adjustment/vptr stores are compiler lowering. |
| 30 | [UID:0004VO][0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation](by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md) | Stores unsigned epoch and schedules timer `(1,1,0,0)`. |
| 40 | [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | Source wrapper delegates to inherited TimerHandler. |
| 50 | [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) | Exact background/visibility/frame/resource/render/composite behavior. |
| 60 | [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) | Exact one-store unsigned setter. |
| 70 | [UID:0004VQ][0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer](by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md) | Invalidates, reschedules, returns true; supersedes OnShow. |

- The public inline empty virtual destructor is the authored source cause for compiler scalar-deleting wrapper [UID:0004VR][0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor](by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md). UID0004VR is the validator-allocated BowGauge identity; historical duplicate UID000380 remains canonical to JsonCpp.
- `OnPaint` and `OnTimer` are protected virtual overrides; lifecycle helpers are public because UserPane calls them directly.
- `extern BowGaugeObjectPane *g_pBowGaugeObjectPane` is declared after the size guard; [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) owns the sole source definition at file position 0.

### Source and compiler boundary

- Constructor Singleton publication/clear, null fallback arithmetic, all vptr stores, EH/cookies, adjusted destructor thunks, scalar deleting flags, size-guarded delete, Pane teardown calls, RTTI, and raw vtable arrays are compiler output.
- [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) is covered by this declaration and the virtual definitions at position 80.
- [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) is covered by the two source literals in `OnPaint` at position 90.
- No duplicate global, raw resource array, explicit handler-subobject member, or handwritten scalar/adjustor/vtable source belongs to this class.

## Ownership And Layout Evidence

| Topic | Evidence |
| --- | --- |
| Source owner | [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) documents the accepted standalone `NexusTK/ui/panels/` placement. Historical private [UID:0000P1][UserPane](by-file/UserPane.md) companion placement is weaker because the function/data/global/class clusters and external consumer linkage are distinct. |
| Base/role separation | [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) and [UID:0000M5][ObjectPane](by-file/ObjectPane.md) both exclude this class despite the object-pane-like name because it constructs through `Pane` and is allocated by `UserPane`, not the attached-object base. |
| Vtable data | [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) maps the exact `BowGaugeObjectPane` RTTI/vtable child to constructor stores at `0x00538beb`, `0x00538bf1`, and `0x00538bfb`. |
| TimerHandler facet | Constructor store at `this + 0xa4` installs adjusted BowGauge vtable `0x0062072c`; [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) adds `0xa4` before calling `TimerHandler::RemovePendingTimers`, and the timer callback path is reached through the adjusted view. Treat this as a `TimerHandler` base/facet, not an unknown data field. |
| Resource strings | [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) records `BGAUGE.EPF` and `BGAUGE.pal`, including the bow-gauge paint consumers at `0x00538cbc` and `0x00538cc8`. |
| Singleton state | [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) and [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) document the constructor write, destructor clear, and `UserPane` show/hide/destructor consumers. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) dependency | `0x004ba540-0x004ba6ad` | `GrafPort::CompositePixels`, not a BowGauge-owned helper. `BowGaugeObjectPane::OnPaint` remains one direct consumer at `0x00538ce5` after drawing `BGAUGE.EPF`/`BGAUGE.pal`; TextEditPane owns the other two direct call sites. |
| [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) | `0x00538bc0-0x00538c0a` | Authored Pane/Singleton base construction; global publication and vptr stores are compiler lowering. |
| [UID:0004VO][0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation](by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md) | `0x00538c10-0x00538c3a` | Stores unsigned animation epoch and schedules timer 1 after one millisecond. |
| [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) | `0x00538c40-0x00538c4b` | `RemovePendingTimers()` member wrapper; adjusts from the primary BowGauge object to the `TimerHandler` facet at `this + 0xa4` and tail-jumps to `TimerHandler::RemovePendingTimers`; `BulletinSession` labeling is owner pollution. |
| [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) | `0x00538c50-0x00538cfa` | Draws current `BGAUGE.EPF` frame and composites pixels while preserving exact absent checks and uninitialized composite rectangle. |
| [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) | `0x00538d00-0x00538d10` | Exact one-store `SetAnimationStartTick(unsigned int)` member for `m_animationStartTick` at `+0xf8`; UID0003TQ reaches it through UID0004SL and `OnPaint` consumes the field for elapsed-frame selection. |
| [UID:0004VQ][0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer](by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md) | `0x00538d10-0x00538d4b` | TimerHandler adjusted-view callback invalidates, reschedules `(1,1,0,0)`, and returns true; historical `OnShow` is rejected. |
| [UID:0004VR][0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor](by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md) | `0x0053cfe0-0x0053d025` | Clears the global active pointer, tears down the base pane, and frees memory when requested. |

## Live IDA Evidence

- IDA MCP confirms `sub_538BC0` at `0x00538bc0-0x00538c0a`. It calls `sub_544460(this, 1)`, stores `this` to `dword_69BA24` / [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md), and installs three BowGauge vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`.
- IDA MCP plus B003 raw PE recheck confirm `sub_538C40` at `0x00538c40-0x00538c4b` as `BowGaugeObjectPane::RemovePendingTimers()`, a source-shaped member wrapper that adjusts to the `TimerHandler` facet at `this+0xa4` and tail-jumps to `TimerHandler::RemovePendingTimers`.
- IDA MCP confirms `sub_538C50` at `0x00538c50-0x00538cfa` as paint: it initializes scratch state, clears pane text state, invalidates `this+0x44`, gates drawing on byte [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` `+0x1d1`, derives a frame from `(timeGetTime() - this+0xf8) / 0x8a` clamped to `36`, looks up `BGAUGE.EPF`, renders with `BGAUGE.pal`, then calls `GrafPort::CompositePixels` at `0x004ba540`.
- Resource refs are direct and unique to paint: `0x00538cbc -> 0x00620b90` (`BGAUGE.EPF`) and `0x00538cc8 -> 0x00620ba8` (`BGAUGE.pal`).
- `GrafPort::CompositePixels` / historical `sub_4BA540` at `0x004ba540-0x004ba6ad` has exactly three direct rel32 callers in B003's current raw PE scan: `0x00538ce5` from BowGauge paint and `0x00590960`/`0x005917a3` from TextEditPane paths. It is a shared GrafPort pixel-effect dependency, not BowGauge source.
- IDA MCP confirms `sub_538D10` at `0x00538d10-0x00538d4b` as exact `OnTimer`: the adjusted `+0xa4` TimerHandler receiver is normalized to the complete object, inherited visible bounds are invalidated, timer `(1,1,0,0)` is rescheduled, and true is returned after three ignored arguments.
- IDA MCP confirms `sub_53CFE0` at `0x0053cfe0-0x0053d025` as scalar deleting destructor behavior: it clears `dword_69BA24`, calls pane cleanup `sub_544580`, and conditionally frees through `sub_4F4AC0`.
- Live xrefs to `0x0069ba24` include constructor write `0x00538be4`, destructor clear `0x0053cfe6`, `UserPane` destructor reads at `0x005a2d1b`/`0x005a2d2d`, show/name-label reads at `0x005a8e97`, `0x005a8ea2`, `0x005a8ef2`, `0x005a8f0e`, `0x005a8f3f`, hide read at `0x005a8f71`, another show/update read at `0x005a8fe5`, and scalar-destructor reads at `0x005b82f2`/`0x005b8304`.
- BowGauge vtable slots in the mixed object-pane vtable block include scalar deleting destructor `0x006206b0 -> 0x0053cfe0`, paint `0x006206f4 -> 0x00538c50`, and adjusted TimerHandler `OnTimer` `0x00620730 -> 0x00538d10`.
- 2026-07-07 B005 MCP evidence keeps [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) as class-owned compiler RTTI/vtable data, not raw arrays. It reconfirmed exact range, primary/adjusted bases, constructor stores, scalar destructor, adjusted thunks, paint slot, and the `0x00538d10` timer slot; B002 resolves the older show/timer ambiguity as exact `OnTimer`.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) because the validated source route, exact method anchors, global lifecycle, resource/vtable-data links, `0xfc` size, TimerHandler facet, and `m_animationStartTick` field now support the complete managed declaration above.
- Historical blank-class wording is superseded. The exact [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) and [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) children emit their own definitions, while the class block closes before `[[CHILDREN]]`. Explicit vptrs, TimerHandler adjustors, scalar deleting-destructor mechanics, RTTI/vtable arrays, allocation-pool details, and compiler EH state remain excluded from human source.
- Do not move [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) into BowGauge source. It is now best routed as `GrafPort::CompositePixels`; this class is only a consumer through `OnPaint`.
- Do not hand-author raw C++ vtable/RTTI arrays for [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md). The class declaration, virtual methods, scalar destructor, and adjusted thunk/facet declarations should regenerate that `.rdata` family through normal compiler output.

## Cross-References

- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md)
- [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md)
- [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md)
- [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md)
- [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md)
- [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-07-21 B002 UID0001PY implementation: raised `90/92` to `92/94`, set position 10, installed the complete direct Pane plus Singleton class formal, inline empty virtual destructor, StartAnimation declaration, exact public/protected/private order, terminal `+0xf8` tick member, size guard, external singleton declaration, and four real children UID0004VN/UID0004VO/UID0004VP/UID0004VQ. Added full EBO/layout, source order, behavior, compiler exclusion, vtable/resource/global, and standalone-source evidence while preserving prior UserPane/compositor/history detail.

- 2026-07-16 B004 UID0003TQ support synchronization:
  - What existed before: `86/88` with a blank class formal and a still-open field/source-placement blocker, despite exact constructor, paint, timer, singleton, resource, and vtable evidence.
  - Changed to: `90/92` with the complete source-clean `0xfc` Pane-derived declaration, `m_animationStartTick`, exact `SetAnimationStartTick(unsigned int)` declaration, and real child UID0004SJ; owner/emitter UID0000HU and all unrelated methods/evidence remain unchanged.
  - Evidence: `[0x00538d00,0x00538d10)` is an exact one-store member; UID0004SL is its target-live UserPane caller; `OnPaint` reads `+0xf8` to calculate elapsed animation frames; constructor/destructor/vtable/resource/global evidence closes the declaration while compiler vptr/adjustor/deleting-destructor/EH/pool mechanics remain excluded.

- 2026-06-07 A005 resolved-name cleanup:
  - Before: BowGauge paint evidence used only historical `dword_67A748`.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IDA-backed evidence already ties the byte at `+0x1d1` to player/client state gating BowGauge drawing.
- 2026-06-02:
  - Before: scored `68/76`, with reconstructable/parent blank and no class-level vtable/resource/global evidence map.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md).
  - Summary/evidence: added source-owner, base-separation, vtable-data, resource-string, global lifecycle, timer-helper, and shared-compositor evidence from existing recorded IDA-backed docs. C++ remains blank because final field names and standalone-versus-UserPane source placement remain unresolved.
- What existed before: the page had class anchors, method notes, global ownership, and helper-pollution caveats, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Historical summary: earlier IDA-backed evidence supported class identity while file placement/helper ownership were still unresolved. B002 now closes those blockers with the standalone source route, real method children, complete formal declaration, and exact compiler exclusions.
- 2026-06-04 live IDA refresh:
  - Before: the class was scored `78/84` and had strong anchors but lacked current method-body, resource, vtable-slot, and global-consumer detail.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, with C++ reconstruction still blank.
  - Historical summary/evidence: live IDA confirmed exact method ranges, global/vtable lifecycle, resources, compositor callers, timer scheduling, and destructor/paint/timer slots. The former field/source-split cap is superseded by the B002 complete declaration and standalone source decision.
- 2026-06-10 B001-035 vtable split update:
  - What existed before: vtable/resource references pointed at broad mixed read-only data aggregates.
  - Changed to: references now point at exact [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) BowGauge vtable data and exact [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) BowGauge resource strings.
  - Evidence: fresh IDA MCP confirms exact BowGauge RTTI/vtable range `0x006206ac-0x00620734` and resource literals at `0x00620b90/0x00620ba8`.
- 2026-06-18 B003 CompositePixels support sync:
  - Score unchanged at `86/88`.
  - Changed [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) wording from a generic GrafPort/Surface helper dependency to the accepted `GrafPort::CompositePixels` route.
  - Evidence: B003 raw PE/Capstone recheck found the BowGauge paint caller at `0x00538ce5` after `BGAUGE.EPF`/`BGAUGE.pal` rendering plus TextEditPane callers at `0x00590960` and `0x005917a3`; the target body uses GrafPort draw state, embedded surface-context fields, and palette mapping rather than BowGauge-specific fields.
- 2026-06-18 B003 RemovePendingTimers support sync:
  - Score unchanged at `86/88`.
  - Changed [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) wording from a generic tiny timer helper to `BowGaugeObjectPane::RemovePendingTimers()` and documented `this+0xa4` as the adjusted `TimerHandler` base/facet.
  - Evidence: B003 raw PE/Capstone recheck confirms exact target bytes/padding, the tail-jump to [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) `TimerHandler::RemovePendingTimers`, three direct UserPane callers, no hidden VA/RVA/raw pointer route, and constructor vtable stores at `+0x00/+0xa0/+0xa4`.
- 2026-07-07 B005 UID000352 vtable marker support sync:
  - Score unchanged at `86/88`; metadata and class-level formal C++ remain unchanged.
  - Added current support for [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) as source-declared/generated-binary BowGauge RTTI/vtable data covered by this class declaration and the `BowGaugeObjectPane.cpp` route, with no raw vtable-array source.
  - Evidence: session `supervisor-nexustk-20260707` reconfirmed server health, exact range `0x006206ac-0x00620734`, bases `0x006206b0/0x006206fc/0x0062072c`, constructor stores `0x00538beb/0x00538bf1/0x00538bfb`, scalar destructor `0x0053cfe0`, adjusted thunks `0x0053cea4/0x0053ceaf`, paint slot `0x00538c50`, and timer slot `0x00538d10`.
