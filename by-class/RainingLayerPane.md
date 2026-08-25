*** UID:0000BJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete RainingLayerPane declaration belongs in canonical
// WeatherLayerPane.h; this source route emits its qualified child definitions.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RainingLayerPane : public WeatherLayerPane
{
public:
    RainingLayerPane();
    virtual void DrawOnTarget(GrafPort *target,
                              const RectBounds *sourceBounds,
                              const RectBounds *targetBounds);
    virtual void OnPaint();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RainingLayerPane

## Status

- Confidence: very strong for the source-ready constructor, behavior-complete `OnPaint` and `DrawOnTarget`, constructor caller/ABI, vtable stores, inherited layout, and rain render table ownership.
- Current source-family route: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) remains the historical dedicated-file hypothesis.
- Main address range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md); exact source-bearing children [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), and [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md)
- Current recovered file: `source-3/simroot_v2/class_RainingLayerPane.cpp`

## Class Purpose

`RainingLayerPane` is a `WeatherLayerPane` derivative that renders animated rain over the map view. It uses writable file-static coordinate arrays for 18 streaks, 7 small splashes, and 7 large splashes per rendered frame.
The exact table block is documented at [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md).

The formal CPP block remains a child router after the 2026-07-01 B008 empty-emitter family callback. The independent H channel now emits the complete zero-added-storage derived declaration at combined-header position 20, after the complete Weather base. Exact constructor/paint/target-draw method pages and vtable-data pages own definitions and compiler evidence without duplicate bodies.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c1410-0x005c145a` | [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) | Source-ready no-argument constructor; compiler supplies base/vptr ABI, then source assigns inherited `m_timerInterval = 120`, `m_frameCount = 3`, and `m_drawOnTarget = true`. |
| `0x005c1460-0x005c180c` | [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) | Draws rain streaks and splash patterns on the pane using main-view tables at `0x00670528`, `0x006706d8`, and `0x00670730`. |
| `0x005c1810-0x005c1bc7` | [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) | Behavior-complete `void DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` override: Layer configures target clipping before virtual dispatch, both bounds are intentionally unused, and Rain renders exact 18/7/7 target-table loops after the active-map readiness gate. |

## Key Relationships

- Derived from [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md).
- Constructed by [UID:0000L3][MapPane](by-file/MapPane.md) weather setup.
- Neighboring concrete weather overlays are [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) now resolves the class's table source model: `RainStreak { short x, y, length; }`, `RainSplash { short x, y; }`, three `s_targetRain*` arrays for the supplied target-port method, and three `s_rain*` arrays for `OnPaint`.
- Streak arrays are `3x24` with 18 drawn and six zero records per frame; splash arrays are `3x7`. Corresponding target/main arrays are byte-identical but remain six distinct writable internal-linkage objects, separated where needed by three symbol-free compiler-alignment gaps.
- The current compilation route is UID0000P8/`WeatherLayerPane.cpp`, supported by contiguous code, RTTI/vtables, rain/snow data, and existing class/global/type routes. Historical dedicated `RainingLayerPane.cpp` placement remains documented but is no longer a table/source-route blocker.
- Inherited `Pane+0xf6` is direct-target paint mode, not generic enable/visibility state. Pane clears it, Rain/Snow/Swallow set it, and `Layer_UpdateDirtyRegionsRecursive` dispatches primary `OnPaint` only when it is zero. Preferred source spelling is positive bool `m_drawOnTarget`; separate Pane byte `+0xb4` remains visibility.
- Generated `g_pWeatherState` is a stale alias for [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md); rain rendering checks byte `+0x3f0` on that active map pane.
- 2026-05-24 historical recheck: IDA caller data tied the constructor call to `MapPane::SetMapState` at `0x0050dc3b`; vtable refs pointed at `OnPaint` (`0x00631264`) and the then-descriptively named `DrawRainOnTarget` slot (`0x00631230`). Current source-contract evidence supersedes that spelling with `DrawOnTarget`; the stable by-memory filename preserves the historical label without changing source code.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed the constructor `sub_5C1410` as `0x005c1410-0x005c145a`, `OnPaint` as `0x005c1460-0x005c180c`, and the then-labeled `DrawRainOnTarget` body as `0x005c1810-0x005c1bc7`. The constructor is called from `MapPane::SetMapState` at `0x0050dc3b`, calls the base weather constructor at `0x005c141a`, and stores the rain vtable views at `0x00631220`, `0x00631274`, and `0x006312a4` from `0x005c1424`, `0x005c1433`, and `0x005c143d`. Vtable slots point to the rain render bodies at `0x00631264 -> 0x005c1460` and `0x00631230 -> 0x005c1810`; current Pane/Layer evidence resolves the latter source method as `DrawOnTarget`.

This raises the class page above the strict `85/85` direct-parent gate for the exact `RainingLayerPane` vtable-data child. The broad class formal remains comment-only because exact constructor/paint/target-draw child pages own method bodies and vtable compiler output; the table/source-family blocker is resolved by UID0001ON and UID0000P8.

## UID0002XW Shared Compiler-Entry Relationship

- Rain primary deleting slot `0x00631220` points to [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md). Adjusted slots `0x00631274` and `0x006312a4` point to the two [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md).
- ButtonControlPane, SelectBoxControlPane, and WeatherLayerPane have separately named RTTI/vtables but use the same primary body and adjusted entries. Rain is an equal consumer, not the owner of that compiler page.
- `RainingLayerPane` adds no storage to the exact `0x10c` Weather base. The 59-byte entry performs only Pane teardown and deleting-flags dispatch; it reads no rain frame/timer/bounds state and releases no Rain-specific resource.
- The bit-4 path pushes `0x10c` and `this` to a one-byte no-op helper. Historical vector-delete interpretation is rejected by direct callee behavior.
- Best source shape keeps the likely implicit Rain destructor. Do not add a speculative explicit empty destructor or hand-author deleting-wrapper/adjustor ABI code.
- One class-neutral body shared by four distinct vtable families is best explained by compiler COMDAT/identical-code folding. Exact linker-option spelling remains unproved but does not affect Rain ownership, layout, or source placement.

## Cross-References

- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md)
- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md)
- [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)

## 2026-07-23 UID0003PJ Class And Paint Closure

- `RainingLayerPane` derives from [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), adds no instance storage, and has exact extent `0x10c`. Its inherited animation state is signed-byte `m_currentFrame`, signed-byte `m_frameCount`, signed-short `m_timerInterval`, and `RectBounds m_weatherBounds`.
- The constructor establishes three frames and a 120 ms interval. Historical wording that treated 120 as a frame count or 3 as a frame step is superseded.
- Final WeatherLayerPane.h should declare the Rain constructor, `void OnPaint()`, and `void DrawOnTarget(GrafPort *target, const RectBounds *sourceBounds, const RectBounds *targetBounds)`. The complete base and callback declarations come from canonical Pane.h and Surface.h; direct MapPane field access comes from complete MapPane.h.
- Exact [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) behavior:
  - set draw color zero and fill inherited `m_bounds`;
  - return when `g_activeMapPane->m_waitingForLocalPlayerStatus` is nonzero, with no null guard;
  - select rain color 143;
  - draw 18 streaks through `MoveTo` and `g_pfnDrawLineDelta`;
  - draw seven two-pixel small splashes and seven four-pixel large splashes through `g_pfnDrawPixel`;
  - preserve signed source fields, exact multiplication/division/truncation order, and repeated `m_currentFrame` loads.
- The class formal is an exact comment-plus-`[[CHILDREN]]` source router. It routes the actual UID0003PJ formal through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md); it does not duplicate the method body or invent a partial class declaration in the generated `.cpp`.
- Canonical Pane.h, MapPane.h, Surface.h, and WeatherLayerPane.h remain required final source artifacts. Their absence from the current `.cpp`-only generated tree is documented without treating the paint method as code-empty or claiming standalone compilation.
- Score moves from `88/90` to `90/92` for exact layout/inheritance, source declarations, resolved paint behavior, and actual child formal routing. Owner/emitter [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), reconstructable true, and blank optional position remain unchanged.

## 2026-07-24 UID0003PK DrawOnTarget Class Closure

- The exact virtual source contract is `void RainingLayerPane::DrawOnTarget(GrafPort *target, const RectBounds *sourceBounds, const RectBounds *targetBounds)`. The inherited `Pane::DrawOnTarget` declaration and `Layer::RenderRecursive` call through primary vtable slot `+0x10` prove the return, receiver, and two rectangle-pointer arguments; the target's older IDA `int,int` guess and documentation-only `DrawRainOnTarget` spelling are superseded.
- `Layer::RenderRecursive` configures the supplied `GrafPort` clip before dispatch. The Rain override intentionally ignores both rectangle pointers and performs no local clip, fill, blend change, restore, random call, frame advance, table mutation, object-state update, or array bounds check.
- The override directly returns while `g_activeMapPane->m_waitingForLocalPlayerStatus` is nonzero, without a singleton null guard. Otherwise it selects palette index 143, draws 18 streaks, seven two-pixel small splashes, and seven four-pixel large splashes from the three target-port arrays, for 18 line-delta and 42 pixel calls.
- `s_targetRainStreaks`, `s_targetRainSmallSplashes`, and `s_targetRainLargeSplashes` retain signed-short `RainStreak`/`RainSplash` records, physical separation from their byte-identical main-view counterparts, and exclusive target-method consumers. Every signed load and multiplication/division/truncation step remains in observed order; `m_currentFrame` is reloaded around callbacks rather than normalized into decompiler-style temporary state.
- The exact method page owns the behavior-complete formal C++. This class page remains a comment-plus-`[[CHILDREN]]` router and must not duplicate method bodies, local support declarations, vtable arrays, or compiler wrappers.
- Source route remains [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), with the declaration in canonical WeatherLayerPane.h and qualified child definition in WeatherLayerPane.cpp. [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) remains a historical dedicated-file hypothesis only.
- Score moves `90/92 -> 91/93` because both Rain rendering overrides now have exact source contracts and behavior-complete child formals. It stays below 95 because original local lexical names, exact historical physical-file split, canonical generated header set, and rebuilt binary/codegen identity remain unproved.

## 2026-07-24 UID0003PI Constructor Class Closure

- Exact target `[0x005c1410,0x005c145a)` is 74 bytes with SHA256 `B302EDA90BEA72A3FA45D2C16C9C6059B3ECE41F29FAFA5024A85986D56BB29E`. Its sole MapPane caller allocates `0x10c`, calls the constructor at `0x0050dc3b`, stores the result at `+0x414`, and owns unwind cleanup.
- The sole target callee is the Weather base constructor. Primary and two adjusted Rain vptr stores plus returned `this` are compiler ABI operations; the source-visible body is exactly the three inherited assignments recorded by UID0003PI.
- `m_timerInterval` and `m_frameCount` belong to the Weather tail at `+0xfa/+0xf9`. `m_drawOnTarget` belongs to the inherited Pane prefix at `+0xf6`; therefore the constructor does not add Rain storage and `sizeof(RainingLayerPane)` remains `0x10c`.
- The `+0xf6` name follows complete cross-function behavior: Pane zero default, exactly three concrete-weather writers, and unique Layer reader that bypasses generic virtual `OnPaint` when nonzero. Visibility, reserved/padding, readiness, raw-offset, and negative `m_skipOnPaint` alternatives are rejected.
- UID0003PI now owns the exact qualified constructor formal and emits through this class page's `[[CHILDREN]]` insertion into [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). This class page retains its declaration/header and route role and does not duplicate the body.
- Historical constructor blank-C++, generic enabled-state, and one-file/per-layer blockers are preserved on the exact child as superseded evidence stages. Class metadata remains `91/93`; constructor closure improves child completeness but does not resolve the class page's remaining physical-file/header/codegen caps.

## Changes

- 2026-07-24 Agent-B003 UID0003PI implementation callback:
  - Preserved `91/93`, owner/emitter UID0000P8, class-router formal, both completed render-method closures, and all compiler-entry history.
  - Added exact constructor hash/caller/base/ABI/source-body facts, inherited direct-target mode semantics and naming, no-added-storage proof, exact child emission route, and superseded blank/enabled/source-split assumptions.
- 2026-07-24 B005 UID0003PK implementation callback:
  - Changed `90/92 -> 91/93`; retained [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) owner/emitter, reconstructable state, class-router formal, and stable source-family route.
  - Added the exact DrawOnTarget contract, caller-managed clipping, intentional bounds nonuse, active-map gate, 18/7/7 target-array behavior, signed-data and operation-order constraints, complete negative behavior, source placement, and historical method-name correction without duplicating the child body.
- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, owner/emitter, class route, formal marker/children insertion, no-added-storage layout, and method child routes unchanged.
  - Added exact primary/adjusted shared deleting-entry evidence, no-rain-state proof, bit-4 no-op correction, compiler-folding explanation, and implicit-destructor source disposition.
- 2026-07-22 B005 RainCoordinateTables source-quality callback:
  - Changed `86/88 -> 88/90`; retained `CANONICAL_OWNER:0000P8`, `EMITTER_UIDS:0000P8`, and the comment-plus-`[[CHILDREN]]` formal route.
  - Added exact file-static signed-short rain types, six array declarations, dimensions, target-port/main-view consumer split, physical duplication, alignment gaps, and current WeatherLayerPane source-family placement.
  - Removed only the table-name and source-route blockers. Exact method helper, GrafPort, object-field, and child-body questions remain on their exact method pages.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/86`.
  - Before: The page was unevaluated despite documenting constructor, two rain-rendering paths, coordinate tables, relationships, and stale alias caveats.
  - After: Scored as high completion and strong confidence for the rain weather overlay.
  - Evidence: Existing method map, key relationships, IDA caller/vtable notes, and rain-table cross-references document behavior and boundaries.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the current weather-layer source-family parent. C++ remains blank because this page is below the 95+ final-source threshold and final separate-file ownership is still being tracked.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed the constructor, paint, and target-draw ranges, `MapPane` weather-setup caller, base-constructor call, rain vtable stores, and rain render vtable slots. The class now clears the direct-parent gate for exact rain vtable data.
- 2026-06-16 B001 child-split link update:
  - Metadata unchanged.
  - Summary/evidence: linked exact source-bearing children [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), and [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) after the Weather/Rain aggregate split; the broad [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) page is now a non-emitting migration index.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted a formal comment marker stating that RainingLayerPane class-owned methods and vtable support emit on exact child pages. This preserves [UID:0000BJ] as a direct class owner without duplicating exact rain constructor/paint/target-draw bodies or hand-authoring vtable output on the broad class page.
