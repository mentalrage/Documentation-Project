*** UID:000046 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class EarthquakeEffecter : public PixelEffecter
{
public:
    EarthquakeEffecter(unsigned short xAmplitude, unsigned short yAmplitude);
    virtual ~EarthquakeEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    unsigned short m_xAmplitude;
    unsigned short m_yAmplitude;
    int m_currentYOffset;
    int m_currentXOffset;
    unsigned int m_lastShakeTick;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EarthquakeEffecter

## Status

- Confidence: strong for role, source-module placement, vtable identity, and `ApplyEffect` behavior; medium-high for the constructor boundary because IDA does not currently model `0x0055b110` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Read-only data: [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) records the `EarthquakeEffecter` vtable at `0x00623be4`.
- Documentation basis: IDA-backed raw constructor bytes, modeled `ApplyEffect` behavior, destructor-strip evidence, vtable/read-only data, runtime-cluster placement, and the shared [UID:0000IZ][Effects](by-file/Effects.md) source-module page.
- Recovered-output caveat: one-class recovered output is only a lead; sibling docs and the vtable family support shared `render/Effects.cpp` ownership.

## Responsibility

`EarthquakeEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that shakes the map render by random X/Y offsets within configured amplitudes. It throttles offset updates, resets map scroll on a new shake sample, respects camera-lock state, and blits the map through the adjusted destination rectangle.

## Hierarchy And Layout Evidence

| Item | Evidence |
| --- | --- |
| Source module | [UID:0000IZ][Effects](by-file/Effects.md) groups `EarthquakeEffecter` with the runtime `ScreenEffecter`/`PixelEffecter` family in `render/Effects.cpp`, not a standalone one-class source file. |
| Base class | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) places `EarthquakeEffecter` in the single-primary pixel-effect branch with `PixelEffecter`, `XWaveEffecter`, `YFlipEffecter`, and `LakeEffecter`. |
| Vtable | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `??_7EarthquakeEffecter@@6B@` at `0x00623be4`, with constructor store evidence at `0x0055b114`. |
| Runtime cluster | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) groups `0x0055b110-0x0055b5c2` as the earthquake, X-wave, and Y-flip displacement-effect block. |

## Field Layout

Recommended 20-byte object layout after the `PixelEffecter` vptr:

| Offset | Field | Meaning and evidence |
| --- | --- | --- |
| `+0x04` | `unsigned short m_xAmplitude` | Horizontal amplitude. The constructor stores the first 16-bit argument here, and `ApplyEffect` zero-extends it before computing `rand() % (2 * amplitude + 1) - amplitude` for the X offset. |
| `+0x06` | `unsigned short m_yAmplitude` | Vertical amplitude. The constructor stores the second 16-bit argument here, and `ApplyEffect` uses the same unsigned symmetric random range for the Y offset. |
| `+0x08` | `int m_currentYOffset` | Current/reused Y shake offset. The constructor zeroes it; `ApplyEffect` stores the accepted Y sample here and reloads it during the cooldown path. |
| `+0x0c` | `int m_currentXOffset` | Current/reused X shake offset. The constructor zeroes it; `ApplyEffect` stores the accepted X sample here and reloads it during the cooldown path. |
| `+0x10` | `unsigned int m_lastShakeTick` / `m_lastSampleTick` | Last accepted shake-sample tick. The constructor seeds it with `g_pTimerMgr->+0x18 - 0x3c`, and `ApplyEffect` overwrites it whenever `currentTick - m_lastShakeTick > 0x50`. |

The Y-before-X current-offset order is intentional. Generated names such as `m_elapsed`, `m_phase`, `m_startTick`, or swapped `m_lastShakeX`/`m_lastShakeY` do not match the field writes and should not be copied into source-facing docs.

## State And Behavior Notes

- Constructor state is documented from raw bytes in [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md): half-open range `0x0055b110-0x0055b151`, vtable store `0x00623be4`, read `g_pTimerMgr` / `dword_67AB80`, load current tick from `+0x18`, subtract `0x3c`, store `m_xAmplitude` and `m_yAmplitude`, zero `m_currentXOffset` and `m_currentYOffset`, store `m_lastShakeTick`, and return with `ret 8` at `0x0055b14e`. The following `0x0055b151-0x0055b160` span is `0xcc` alignment before `ApplyEffect`.
- `ApplyEffect` at half-open range `0x0055b160-0x0055b293` reads the current timer tick, prepares fresh random X/Y offsets within the configured amplitudes, and accepts a fresh sample only when `currentTick - m_lastShakeTick > 0x50`. During the cooldown path it discards fresh random values and reuses `m_currentXOffset`/`m_currentYOffset`; during the accept path it overwrites `m_lastShakeTick`, `m_currentXOffset`, and `m_currentYOffset`, then calls the active map pane virtual slot `+0x20` with argument `0` to refresh/reset the map view after the new sample.
- `ApplyEffect` respects local-player/UserPane camera-lock state read through historical `dword_67A748`: inferred byte `+0x1c4` enables the branch and byte `+0x1c5` supplies the lock direction. The direction is passed to MapPane helper `0x00505080`, best named `MapPaneDirectionToTileDelta` / `GetDirectionTileDelta`; if the helper returns nonzero `dy`, the X shake offset is suppressed, and if it returns nonzero `dx`, the Y shake offset is suppressed.
- After camera-lock suppression, `ApplyEffect` copies the source rectangle, calls [UID:0000N2][RectBounds](by-file/RectBounds.md) member offset helper `0x004b78f0` (`RectBounds::Offset`) with the chosen X/Y shake offsets, and tail-calls [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md). The destination receiver is the first virtual argument, the source GrafPort-like object is `g_activeMapPane`, the adjusted source rect is the local temp, the destination rect is the third virtual argument, and the blit mode comes from `*(g_activeMapPane + 0xb5)`.
- The scalar deleting destructor thunk at half-open range `0x0055bb90-0x0055bbb4` belongs to the effecter destructor strip. It resets the object vptr to base `ScreenEffecter` table `0x006235a4`, conditionally calls `0x005c7526(this, 0x14)` when `flags & 1`, returns `this`, and should be represented in source as a normal virtual destructor declaration, not as an authored `ScalarDeletingDestructor` method.
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed that `0x0055b110` is raw constructor bytes rather than an IDA function object, `0x0055b160` is modeled as size `0x133`, and `0x0055bb90` is modeled as size `0x24`. Xrefs tie `0x00623be4` to the constructor store at `0x0055b114`, and vtable slots reference `ApplyEffect` at `0x0055b160` and the scalar deleting destructor at `0x0055bb90`.
- 2026-06-14 constructor bytes reconfirm `c7 01 e4 3b 62 00`, the timer baseline load from `0x0067ab80`, `-0x3c` initialization, short amplitude stores at offsets `+4/+6`, zeroed state at offsets `+8/+0xc`, and `retn 8`; the following `0x0055b151-0x0055b160` span is `0xcc` alignment before `ApplyEffect`.
- Local B007 PE/Capstone recheck found no VA pointer, RVA pointer, raw-offset pointer, rel32 call, rel32 jump, or rel32 conditional branch route to constructor start `0x0055b110`. Positive controls still exist at the vtable store `0x0055b114 -> 0x00623be4` and vtable slots for `ApplyEffect`/destructor, so this remains a source constructor-shaped raw body with unresolved construction route rather than padding or data.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b110-0x0055b151` | `EarthquakeEffecter::EarthquakeEffecter(unsigned short xAmplitude, unsigned short yAmplitude)` | Raw constructor-shaped body. It installs `0x00623be4`, seeds `m_lastShakeTick = g_pTimerMgr->currentTick - 0x3c`, stores X/Y amplitudes, zeroes current offsets, and returns with `ret 8`. IDA still lacks a function object for the start, and B007 found no direct pointer or branch route to `0x0055b110`; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |
| `0x0055b160-0x0055b293` | `EarthquakeEffecter::ApplyEffect` | Applies timer-throttled random shake offsets, reuses the previous sample for `<= 0x50` tick deltas, refreshes the map view after accepted samples through active MapPane vslot `+0x20`, applies camera-lock axis suppression through `0x00505080`, offsets a temporary `RectBounds`, and blits through `GrafPort::BlitSurface`. |
| `0x0055bb90-0x0055bbb4` | scalar deleting destructor thunk | Compiler glue for `virtual ~EarthquakeEffecter()`: resets to base `ScreenEffecter` vtable `0x006235a4`, conditionally deallocates 20 bytes through `0x005c7526(this, 0x14)`, and should not be emitted as a source method body. |

## Reconstruction Notes

- Marked reconstructable because this is source-owned runtime effecter code under [UID:0000IZ][Effects](by-file/Effects.md), with an exact vtable anchor and documented constructor/apply/destructor ranges.
- Declaration-only C++ is now appropriate for this class page: class identity, base class, owner/emitter, vtable, field layout, destructor policy, and method names are stable enough for a source-shaped declaration.
- Do not emit constructor, `ApplyEffect`, or destructor method bodies from this class page yet. The constructor start is still raw/non-modeled and has no direct route in the local PE scan, `ApplyEffect` still depends on inferred local-player camera-lock field names and an unresolved active-MapPane vslot `+0x20` source name, and the constructor/apply/destructor bodies do not yet have exact by-memory child pages analogous to the YFlip/Lake splits.
- Do not treat recovered one-class output as original source layout; sibling docs and the vtable family support a shared `render/Effects.cpp` owner.
- Preserve generated-output corrections: reject generated `m_elapsed`, `m_phase`, `m_startTick`, wrong X/Y offset order, `g_pTimer`, `g_pMapPane`/`g_pParcelPane`, `g_pAppMan` camera-lock fields, `MapPane::GetCameraLockOffset`, `OffsetRect`, `GrafPort::BitBlt`, and any source-level `ScalarDeletingDestructor` method. The current source-facing routes are `g_pTimerMgr`, `g_activeMapPane`, local-player/UserPane camera-lock bytes, a direction-to-tile-delta helper, `RectBounds::Offset`, `GrafPort::BlitSurface`, and a normal virtual destructor.

## Heuristic / Inference Reanalysis And Validation

| Blocker | Reanalysis result |
| --- | --- |
| Raw constructor promotion | Still raw/non-modeled and no direct route found. It is source constructor-shaped by prologue, vtable store, argument stores, object initialization, and `ret 8`, so document it as `EarthquakeEffecter::EarthquakeEffecter` while retaining the route caveat and avoiding constructor body emission. |
| Amplitude field names | Resolved to `m_xAmplitude` and `m_yAmplitude` (or longer horizontal/vertical equivalents). `ApplyEffect` uses `movzx`/unsigned arithmetic, so `unsigned short` is the best declaration type. |
| Current offset fields | Resolved to `m_currentYOffset` at `+0x08` and `m_currentXOffset` at `+0x0c`; the Y/X order is real, not a documentation typo. |
| Timer baseline/cadence | Resolved to mutable `m_lastShakeTick` / `m_lastSampleTick`. Constructor seed `currentTick - 0x3c` and `ApplyEffect` threshold `> 0x50` imply a short initial grace interval, not an immediate forced first shake. |
| Camera-lock fields | High-probability local-player/UserPane bytes at `g_pUserPane + 0x1c4/+0x1c5`, best described as `m_cameraLockEnabled`/`m_cameraLockDirection`. Exact original spellings remain inferred, so prose should mark them as inferred and method bodies should wait. |
| Direction helper | Resolved behaviorally as `MapPaneDirectionToTileDelta` / `GetDirectionTileDelta` at `0x00505080`, not a camera-only helper. Direction mapping is `{0:{-1,0}, 1:{0,1}, 2:{1,0}, 3:{0,-1}, 4/default:{0,0}}`. |
| MapPane vslot `+0x20` | Still unnamed at source level. Best description is map-view redraw/reset/invalidation after a new shake sample. Do not promote a final method name until MapPane vtable docs resolve the slot. |
| `ApplyEffect` signature | Declaration can use `virtual void ApplyEffect(GrafPort *destination, const RectBounds *sourceRect, const RectBounds *destinationRect)`. Binary tail returns the blit helper's EAX, but the base effecter declaration is still the controlling source-shape gate. |
| Destructor placement | Resolved as compiler scalar deleting destructor thunk for a normal `virtual ~EarthquakeEffecter()` declaration. No source `ScalarDeletingDestructor` should be emitted. |
| Source owner | Keep [UID:0000IZ][Effects](by-file/Effects.md) / `render/Effects.cpp`; MapPane, TimerMgr, RectBounds, and GrafPort are dependencies. |

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page now has current constructor-byte evidence, modeled `ApplyEffect` and destructor boundaries, vtable slot/store evidence, runtime-cluster support, direct Effects file ownership, resolved 20-byte layout, resolved timer cadence naming, camera-lock helper semantics, rejected generated-output corrections, and declaration-only C++. Completion stays below 90 because Earthquake method bodies remain unsplit and the raw constructor route is still unproven. |
| Confidence `88` | Confidence is strong for `render/Effects.cpp` ownership and class identity because the direct file parent is `89/85`, the vtable family records `EarthquakeEffecter` at `0x00623be4`, and IDA/local PE evidence agree on constructor bytes, `ApplyEffect`, destructor, callees, and vtable slots. Confidence is not higher because `0x0055b110` is still not an IDA-modeled function object, no static construction route was found, and camera-lock field spellings plus MapPane vslot `+0x20` remain inferred. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-06-19 B007 accepted source-quality implementation:
  - Before: `85/86`, blank formal C++, and stale active `90/90+` code-entry wording even though the class-level declaration facts were stable.
  - After: `87/88`, declaration-only C++ emitted, owner/emitter unchanged at [UID:0000IZ][Effects](by-file/Effects.md), and method bodies explicitly deferred.
  - Summary/evidence: B007 resolved the 20-byte layout as X/Y amplitude shorts, current Y/X offsets, and mutable last-shake tick; normalized constructor/apply/destructor half-open ranges; preserved the raw-constructor no-route proof; documented `0x50` cadence, `g_pTimerMgr->+0x18 - 0x3c` seed, camera-lock axis suppression through UserPane bytes `+0x1c4/+0x1c5` and MapPane direction-to-tile-delta helper `0x00505080`, `RectBounds::Offset`, `GrafPort::BlitSurface`, destructor thunk/base-vtable behavior, and rejected stale generated names.
- 2026-06-02:
  - Before: scored `68/74`, reconstructable/parent blank, with role and method list but missing the stronger source-module, vtable-data, runtime-cluster, and constructor-boundary evidence now present in related docs.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) confirm the single-primary `EarthquakeEffecter` vtable at `0x00623be4` and constructor store at `0x0055b114`; [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) confirms the runtime displacement-effect block and representative callees; [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the raw constructor bytes and the remaining IDA function-object caveat.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/74`.
  - Summary/evidence: effect role, raw constructor bytes, apply-effect behavior, destructor, map/timer relationships, and vtable family references are documented; score remains limited because IDA does not currently model the constructor start as a function object.
- 2026-06-06 provenance cleanup:
  - Before: the status section still presented a direct recovered-source path as current evidence, and the reconstruction notes named a one-class recovered output path as a layout caveat.
  - After: replaced the status evidence with the IDA-backed documentation basis and kept the source-layout warning without a direct recovered-source path.
  - Evidence: constructor bytes, `ApplyEffect` behavior, destructor-strip evidence, vtable data, runtime-cluster placement, and Effects module ownership were already documented. Scores, parent, and blank C++ gate remain unchanged.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with the right owner but stale low-score evidence.
  - After: `85/86`, with fresh IDA MCP confirmation of raw constructor bytes, `ApplyEffect`/destructor modeled sizes, vtable slot/store xrefs, and the active `90/90+` C++ blocker.
  - Summary/evidence: no owner/emitter routing changed; the support cluster [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) was refreshed separately.
