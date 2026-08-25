*** UID:0000G1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete WeatherLayerPane declaration belongs in canonical
// WeatherLayerPane.h; this source route emits its qualified child definitions.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WeatherLayerPane : public Pane
{
public:
    WeatherLayerPane();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

protected:
    virtual void OnFrameChanged() { }

    signed char m_currentFrame;
    signed char m_frameCount;
    short m_timerInterval;
    RectBounds m_weatherBounds;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerPane

## Status

- Confidence: very strong for exact `0x10c` layout, constructor and timer source bodies, adjusted TimerHandler ABI, Weather-added frame hook, vtable stores, and derived-class dispatch.
- Likely source file: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Main address range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md); exact source-bearing children [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) and [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md)
- Current recovered file: `source-3/simroot_v2/class_WeatherLayerPane.cpp`

## Class Purpose

`WeatherLayerPane` is the base `Pane` subclass for map weather overlays. It computes overlay bounds from map tile dimensions, stores signed animation state, and implements a shared `bool OnTimer(int timerId, int arg0, int arg1)` callback for Weather/Rain/Snow. Timer ID `0` advances the frame, invalidates inherited visible bounds, invokes the Weather-added `OnFrameChanged()` extension hook, and queues the next frame timer.

The CPP formal remains a comment-plus-`[[CHILDREN]]` router. Its independent H channel now emits the complete `0x10c` base declaration at combined-header position 10, after the guarded `SnowParticleEntry` prologue and before every derived declaration. Exact method pages own qualified definitions: position-10 [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) emits the constructor and position-20 [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) emits the timer callback. Layout and vtable-data pages remain support-only. This class page does not duplicate child bodies or hand-author compiler-generated vtable arrays.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c12a0-0x005c13a1` | [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) | Initializes pane/vtables, map-dependent effect bounds, and base animation state. |
| `0x005c13b0-0x005c1408` | [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) | Exact `bool OnTimer(int,int,int)` entered through TimerHandler `+0xa4`; ID 0 advances signed frame state, invalidates `m_visibleBounds`, calls `OnFrameChanged()`, and reschedules. |

## Key Relationships

- Base class for [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- Constructed indirectly through `MapPane` weather setup before concrete derived weather panes install their own vtables.
- `RainingLayerPane` inherits OnTimer with frame/count/interval `0/3/120` and the no-op frame hook. `SnowingLayerPane` inherits OnTimer with `4/5/200` and overrides `OnFrameChanged()` at `0x005c1f50`. `SwallowLayerPane` replaces the TimerHandler callback at `0x005c2500` and does not dispatch to UID0003PH.
- Uses tile count/global asset-mode fields currently named `g_useEpfAssets`, `g_tileColumns`, and `g_tileRows`.
- Concrete rain/snow tables and render callback dependencies are tracked in [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md).

## Data Caveats

Current metadata reports a stored method-name control-character artifact for the constructor. The active source also contains base/helper labels inherited from generated decompilation history; use IDA boundaries and behavior for migration decisions.

2026-05-24 recheck: active `source-3/simroot_v2/class_WeatherLayerPane.cpp` duplicates marker-only `global-data` rows for `g_tileColumns` and `g_tileRows`. IDA confirms `0x005c12a0` and `0x005c13b0` as real function starts, and `0x005c13b0` is referenced from the rain/snow/swallow vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed `sub_5C12A0` as `0x005c12a0-0x005c13a1` and `sub_5C13B0` as `0x005c13b0-0x005c1408`. The base constructor has direct code xrefs from the `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` constructors at `0x005c141a`, `0x005c1bfb`, and `0x005c225b`. It stores the three `WeatherLayerPane` vtable views at `0x00631190`, `0x006311e4`, and `0x00631214` from `0x005c12d0`, `0x005c12d6`, and `0x005c12e0`, and the shared timer handler is present in the derived weather vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.

This raised the class page above the strict `85/85` direct-parent gate for the exact `WeatherLayerPane` vtable-data child. Historical checkpoint: C++ was then blank because field names and one-file versus per-derived-file source placement had not yet been resolved. Later UID0003PJ and UID0003PG passes resolved the tail names, selected the current UID0000P8 route, and supplied the exact constructor child body; only the class-level declaration remains a header obligation.

## UID0002Z7 Vtable Support Route

B004 UID0002Z7 current evidence keeps [UID:0002Z7][0x0063118c-0x0063121c.WeatherLayerPaneVtableData](by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md) as class-owned, source-declared/generated-binary vtable support for `WeatherLayerPane`. The exact target contains three WeatherLayerPane COL/vtable views: primary `0x0063118c -> 0x00653fec` / `0x00631190`, adjusted `_0` `0x006311e0 -> 0x00654048` / `0x006311e4`, and adjusted `_1` `0x00631210 -> 0x0065405c` / `0x00631214`, with the local timer slot at `0x00631218 -> 0x005c13b0`.

The class constructor writes those three vtable views from `0x005c12d0`, `0x005c12d6`, and `0x005c12e0`; derived `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` constructors call the base constructor at `0x005c141a`, `0x005c1bfb`, and `0x005c225b`. Timer cell `0x00631218` enters UID0003PH through the TimerHandler `+0xa4` facet. The primary Weather slot at `+0x4c` is the inferred `OnFrameChanged()` extension point: base/Rain/Swallow use shared no-op `0x0041b6a0`, while Snow cell `0x006312fc` points to `0x005c1f50`. The vtable child is therefore source-declared/generated-binary support, not a standalone C++ vtable array or no-owner output; this class `[[CHILDREN]]` route includes ready child markers without duplicating method bodies or raw vtable data.

Remaining caveats are source-quality caps only: there is no current local IDA UDT for the final `WeatherLayerPane` header, inherited Pane slot names/signatures are not all source-final here, and original physical one-file versus per-layer disk layout is not symbol-proven. Those caps do not block the selected current UID0000P8 route, exact child ownership, or actual UID0003PG constructor source.

## UID0002XW Shared Compiler-Entry Relationship

- Weather primary deleting slot `0x00631190` points to [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md). Adjusted slots `0x006311e4` and `0x00631214` point to the two [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md).
- ButtonControlPane, SelectBoxControlPane, and RainingLayerPane have separately named RTTI/vtables but use the same primary body and adjusted entries. Weather is an equal consumer, not the owner of that compiler page.
- The 59-byte entry performs only Pane teardown and hidden deleting-flags dispatch. It does not read `m_currentFrame`, `m_frameCount`, `m_timerInterval`, or `m_weatherBounds`; its bit-4 path sends `this` and size `0x10c` to a one-byte no-op helper rather than performing vector destruction.
- Best source shape keeps the likely implicit Weather destructor. Do not add a speculative explicit empty destructor or hand-author deleting-wrapper/adjustor ABI code merely to account for the vtable entries.
- Compiler COMDAT/identical-code folding is the highest-probability explanation for one body shared by four `0x10c` Pane-derived classes. Exact linker-option spelling remains unproved but does not affect the current source/class route.

## 2026-07-24 UID0003PG Constructor Source Closure

[UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) is now the behavior-complete source child for `WeatherLayerPane::WeatherLayerPane()`. Current live IDA session `supervisor_gate2b_0002OT_20260723` proves exact range `[0x005c12a0,0x005c13a1)`, size 257, SHA256 `86BF00A162D9935D3FA52F922F1E862D93E040760746D83CC7C36CE5EB0B8E09`, a unique leading signature, and exactly three derived constructor callers: Rain at `0x005c141a`, Snow at `0x005c1bfb`, and Swallow at `0x005c225b`.

The constructor calls the exact `0xf8`-byte Pane constructor with layer flag `1`, then stores the three decorated WeatherLayerPane vptr views at object offsets `+0`, `+0xa0`, and `+0xa4`. The stores are `0x005c12d0 -> 0x00631190`, `0x005c12d6 -> 0x006311e4`, and `0x005c12e0 -> 0x00631214`; each destination has that sole constructor-store xref. These are compiler-generated multiple-inheritance mechanics and are deliberately absent from the source body.

The exact source-visible class tail remains:

| Offset | Member | Constructor action |
| --- | --- | --- |
| `+0xf8` | `signed char m_currentFrame` | set to zero |
| `+0xf9` | `signed char m_frameCount` | set to zero |
| `+0xfa` | `short m_timerInterval` | set to zero |
| `+0xfc` | `RectBounds m_weatherBounds` | set to EPF or legacy 15-by-17-tile bounds |

`g_useEpfAssets` selects `(0,0,15*w,17*h)` versus `(12,14,15*w+12,17*h+14)`, where `w` and `h` are the signed-short map tile dimensions. The observed optimized dword zero at `+0xf8` represents the three distinct source member assignments because UID0003PH and Rain consumers independently prove byte/byte/short types. The inherited TimerHandler view at `+0xa4` receives exact `ScheduleTimer(0, 0, 0, 0)` parameters.

Rain allocates exactly `0x10c` and adds no storage; Snow and Swallow begin derived storage at `+0x10c`. Together with the final `RectBounds` byte at `+0x10b`, this independently fixes `sizeof(WeatherLayerPane)` at `0x10c`. The current human C++03 body uses `Pane(true)`, explicit bounds assignments, individual field zeroing, and inherited `ScheduleTimer`; raw offsets, vptr addresses, EH/cookie scaffolding, explicit `this` return, and a fabricated rectangle helper call are rejected.

Historical UID0003PG checkpoint: this class page then remained `88/90` while only the constructor source child was complete. UID0003PH closure now raises the class to `90/93`; owner/emitter and comment-plus-children router remain unchanged. Canonical `WeatherLayerPane.h` must declare the complete hierarchy after `Pane.h`; lack of generated headers is a materialization dependency, not permission to omit exact child source or create a partial local declaration.

## 2026-07-24 UID0003PH Timer And Frame-Hook Contract

- Exact source declaration is `virtual bool OnTimer(int timerId, int arg0, int arg1);`. The definition may omit unused `arg0`/`arg1` parameter names. At the ABI boundary the override receives the inherited TimerHandler facet at complete-object `+0xa4`; the source declaration remains WeatherLayerPane-owned.
- Timer ID `0` performs signed `(m_currentFrame + 1) % m_frameCount`, calls inherited `InvalidateRect(&m_visibleBounds)`, calls inferred protected virtual `OnFrameChanged()`, and calls inherited `ScheduleTimer(0, m_timerInterval, 0, 0)`. Every ID returns true; nonzero IDs do not change state or reschedule.
- `m_visibleBounds` is inherited at complete `+0x44`; it is distinct from `RectBounds m_weatherBounds` at `+0xfc`. The old generic `invalidates/repaints` description is superseded by exact invalidation plus the separate frame hook.
- Primary vtable slot `+0x44` remains OnPaint and `+0x48` remains the prior Pane extension; Weather introduces no-argument `+0x4c`. Cross-vtable behavior supports human name `OnFrameChanged`, although exact original spelling/access is stripped-binary inference and keeps confidence below final audit.
- Rain shares timer slot `0x006312a8`, sets `0/3/120`, and retains the no-op hook. Snow shares timer slot `0x00631338`, writes tail bytes `04 05 C8 00` (`4/5/200`), and overrides the hook through `0x006312fc -> 0x005c1f50`. Swallow uses timer slot `0x006313c8 -> 0x005c2500` for IDs `0x100/0x101`; it is not a UID0003PH dispatcher.
- Weather construction queues ID 0; concrete derived constructors install their final vtables/state before queued dispatch. TimerHandler destruction owns pending-event removal. No explicit Weather deleting wrapper, adjustor thunk, or timer cancellation belongs in the class source contract.
- Header-source shape remains a complete declaration in canonical WeatherLayerPane.h plus qualified child definitions in WeatherLayerPane.cpp. The class page is a router only and must not duplicate UID0003PG/UID0003PH bodies.

## 2026-07-24 UID0003O0 Snow Derived Layout Contract

- [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md) calls the exact Weather constructor, then specializes the inherited animation state to `m_currentFrame = 4`, `m_frameCount = 5`, and `m_timerInterval = 200` before setting inherited `m_drawOnTarget = true`.
- The complete Weather prefix remains exactly `0x10c` bytes. Snow begins one inline `SnowParticleEntry m_snowParticles[200]` array at derived offset `+0x10c`; each record is `0x14` bytes (`RectBounds bounds`, one-byte `type`, and three bytes of natural tail padding), so the array occupies `0xfa0` bytes and fixes `sizeof(SnowingLayerPane)` at the caller-proven `0x10ac`.
- The Snow constructor initializes each record with bounds `(0,800,8,808)` and `type = 0` while leaving tail padding untouched. The class dependency order is a complete `RectBounds` and helper declaration, `SnowParticleEntry`, this complete `WeatherLayerPane` declaration, then `SnowingLayerPane : public WeatherLayerPane`.
- This page records the derived layout and inherited field contract only. UID0003O0 owns the sole qualified Snow constructor body; no Snow method, array initializer loop, partial derived class declaration, vptr store, or compiler-generated vtable data is duplicated in this class router.
- The current source/header route remains [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) in `WeatherLayerPane.cpp`/`.h`. A dedicated Snow source file remains historical provenance rather than an active placement blocker.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md)
- [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## 2026-07-23 UID0003PJ Class And Header Contract

- `WeatherLayerPane` is a direct `Pane` derivative with exact extent `0x10c`. Its tail after the exact `0xf8`-byte Pane base is:
  - `signed char m_currentFrame` at `+0xf8`;
  - `signed char m_frameCount` at `+0xf9`;
  - `short m_timerInterval` at `+0xfa`;
  - `RectBounds m_weatherBounds` at `+0xfc`.
- Historical UID0003PJ checkpoint used `bool OnTimer(int timerId, int message, int userData)`. UID0003PH closure supersedes those speculative payload labels with generic `arg0/arg1` and adds inferred protected virtual `OnFrameChanged()`; inherited Pane/GrafPort declarations remain outside this class page.
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) derives from this class, adds no storage, and remains `0x10c`. The Rain constructor sets `m_frameCount = 3` and `m_timerInterval = 120` ms; shared timer logic advances signed `m_currentFrame`.
- The class formal remains a comment-plus-`[[CHILDREN]]` routing block because the current validator emits qualified child definitions into `NexusTK/map/WeatherLayerPane.cpp`, not a project header. It must not fabricate a partial local class declaration. Actual [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) behavior emits through the Rain child route.
- Actual [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) constructor behavior now emits through this Weather class route. The class router still must not duplicate that method body.
- Final declaration dependency order is Pane.h, MapPane.h, Surface.h, then WeatherLayerPane.h. The current generated `.cpp` is not claimed to compile standalone while those headers are absent; this is a source-tree materialization dependency rather than a reason to omit exact child method source.
- Historical UID0003PJ score move was `86/88 -> 88/90`. UID0003PH closure now changes `88/90 -> 90/93` for exact timer source, adjusted ABI, frame-hook role, and full derived dispatch; owner/emitter, reconstructable state, blank class position, and child-routing source shape remain unchanged.

## Changes

- 2026-07-24 Agent-B005 UID0003O0 support callback:
  - Metadata, owner/emitter, and the comment-plus-children class router remain unchanged at `90/93` and UID0000P8.
  - Added the exact Snow `0x10ac` derived extent, 200-record inline particle layout, inherited `4/5/200` state, direct-target flag, constructor initialization contract, dependency order, selected source route, and explicit no-duplicate-body boundary.
- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, owner/emitter, class route, formal marker/children insertion, fields, and method child routes unchanged.
  - Added exact primary/adjusted shared deleting-entry evidence, no-weather-state proof, bit-4 no-op correction, compiler-folding explanation, and implicit-destructor source disposition.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the base weather-pane constructor/timer behavior, derived-pane relationships, map/tile/global dependencies, IDA boundary confirmation, and generated metadata caveats.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). C++ remains blank because this page is below the 95+ final-source threshold.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed the exact constructor/timer ranges, derived constructor callers, three base vtable stores, and shared timer-handler vtable slots. The class now clears the direct-parent gate for exact base weather vtable data while retaining source-split and final-field-name caveats.
- 2026-06-16 B001 child-split link update:
  - Metadata unchanged.
  - Summary/evidence: linked exact source-bearing children [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) and [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) after the Weather/Rain aggregate split; the broad [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) page is now a non-emitting migration index.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted a formal comment marker stating that class-owned methods, layout, and vtable support emit on exact child pages. This preserves [UID:0000G1] as a direct class owner without duplicating the exact WeatherLayerPane constructor/timer method bodies or hand-authoring class/vtable output on the broad class page.
- 2026-07-05 B004 UID0002Z7 route repair:
  - Metadata unchanged.
  - Summary/evidence: added `[[CHILDREN]]` to the existing class-route marker and recorded UID0002Z7 as exact source-declared/generated-binary WeatherLayerPane vtable support. Current evidence keeps UID0002Z7 class-owned by [UID:0000G1], rejects a handwritten vtable array/no-owner/broad aggregate disposition, and treats exact header/source split plus inherited slot signatures as confidence caps rather than route blockers.
- 2026-07-24 B001 UID0003PG source-quality callback:
  - Score and owner/emitter/formal router unchanged at `88/90`, UID0000P8, and comment-plus-children.
  - Added the exact constructor hash/range/callers, base and three-vptr setup, complete tail initialization, EPF/legacy bounds, timer-zero call, derived object-size proof, accepted child formal route, source-shape exclusions, and canonical-header obligation.
  - Historicalized old unresolved-field/current-route blocker text while preserving original physical disk-layout uncertainty and the no-duplicate-vtable/compiler-source policy.
- 2026-07-24 B002 UID0003PH source-quality callback:
  - Changed `88/90 -> 90/93`; owner/emitter/reconstructable/class position and comment-plus-children router remain unchanged.
  - Added exact `OnTimer` signature/ABI/body contract, inherited visible-bounds invalidation, inferred `OnFrameChanged` declaration and vtable role, Rain/Snow/Swallow dispatch matrix, timer lifecycle, current header/source route, and no-duplicate-method/vtable policy.
