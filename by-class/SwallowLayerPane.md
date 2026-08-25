*** UID:0000E9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SwallowLayerPane class-owned methods, resources, and vtable support emit on exact child pages; no duplicate broad class body is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SwallowLayerPane : public WeatherLayerPane
{
public:
    SwallowLayerPane();
    virtual ~SwallowLayerPane();

    virtual void DrawOnTarget(GrafPort *port,
                              const RectBounds *sourceBounds,
                              const RectBounds *targetBounds);
    virtual void OnPaint();
    virtual void MoveBy(int dx, int dy);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    enum
    {
        kStartFlightTimerId = 0x100,
        kStepFlightTimerId = 0x101
    };

    void StartSwallowFlight();
    void StepSwallowFlight();
    void InvalidateSwallowRect();
    void GetCurrentSwallowRect(RectBounds *outBounds) const;

    bool m_swallowActive;
    int m_swallowX;
    int m_swallowY;
    int m_swallowDirection;
    EPFTileContext m_swallowFrames[2];
};

typedef char SnowParticleEntrySizeMustBe0x14[sizeof(SnowParticleEntry) == 0x14 ? 1 : -1];
typedef char WeatherLayerPaneSizeMustBe0x10C[sizeof(WeatherLayerPane) == 0x10c ? 1 : -1];
typedef char RainingLayerPaneSizeMustBe0x10C[sizeof(RainingLayerPane) == 0x10c ? 1 : -1];
typedef char SnowingLayerPaneSizeMustBe0x10AC[sizeof(SnowingLayerPane) == 0x10ac ? 1 : -1];
typedef char SwallowLayerPaneSizeMustBe0x16C[sizeof(SwallowLayerPane) == 0x16c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SwallowLayerPane

## Status

- Confidence: very strong for modeled behavior, exact `0x16c` layout, IDA boundaries, vtable/resource evidence, ten source methods, compiler-only destructor support, and Swallow class ownership; original private spellings and historical object-file split remain the only material confidence caps.
- Current canonical CPP/H route: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) is retained as a comprehensive historical dedicated-file candidate, not a competing emitter.
- Main address docs: [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- Documentation basis: IDA-confirmed modeled methods, raw flight-helper byte reviews, vtable references, constructor caller evidence, and linked by-memory weather-layer pages.

## Class Purpose

`SwallowLayerPane` is a `WeatherLayerPane` derivative that periodically moves a two-frame sprite across the map view. It uses two loaded `SWALLOW` frames, a current position, active flag, direction field, and timers for flight start and step behavior.

The CPP formal is a route comment plus `[[CHILDREN]]`. Exact source children [UID:00054K][0x005c2230-0x005c2340.SwallowLayerPaneConstructor](by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md) through [UID:00054S][0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect](by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md) and [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) emit the ten definitions in positions 10 through 100. Compiler children [UID:00054T][0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks](by-memory/0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks.md)/[UID:00054U][0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor](by-memory/0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor.md), vtable [UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md), and constructor-covered resources [UID:0002ZB][0x006313cc-0x006313fc.SwallowLayerResourceStrings](by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md) remain non-handwritten support. The independent H channel emits the complete class at combined-header position 40, after complete Weather and EPFTileContext visibility, then supplies all five size checks and the single closing include guard.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c2230-0x005c2340` | constructor | Loads frames, initializes flight state, and schedules first start timer. |
| `0x005c2340-0x005c235f` | destructor | Non-deleting destructor documented with the class core. |
| `0x005c2360-0x005c2423` | `OnPaint` | Clears/refreshes and paints active sprite. |
| `0x005c2430-0x005c24fa` | `MoveBy` | Invalidates old/new rectangles and changes position. |
| `0x005c2500-0x005c26a6` | `OnTimer` | Starts and steps timed sprite flight. |
| `0x005c26b0-0x005c275c` | `DrawOnTarget` | Draws the active sprite. |
| `0x005c2760-0x005c2835` | `StartSwallowFlight` | Retained private source method emitted by [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md). The historical absence of an IDA function object, inbound xrefs, and pointer/vtable routes remains negative binary evidence, but the complete body, exact class-field family, timer call path, and neighboring retained helper family support source reconstruction. |
| `0x005c2840-0x005c292e` | `StepSwallowFlight` | Retained private source method emitted by [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md); it advances position, invalidates through the exact Swallow helper family, reschedules the 10 ms timer, and transitions to a randomized restart delay. |
| `0x005c2930-0x005c299f` | current-rect invalidation helper | Real IDA function owned by the Swallow class core. |
| `0x005c29a0-0x005c29ec` | `GetCurrentSwallowRect` | Retained private source method emitted by [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md). It copies the direction-selected frame bounds and offsets them by the current X/Y position; the no-function/no-xref evidence is preserved as historical route evidence rather than treated as proof that the source method did not exist. |
| `0x005c2a02-0x005c2a17` | thunks | Adjustor thunk support. |
| `0x005c2a60-0x005c2ab5` | scalar deleting destructor | Deleting-destructor wrapper. |

## Historical Data Caveats Superseded By 2026-08-16

Recovered metadata includes a bad/excluded method row at `0x00570053`; IDA places that address inside `0x00570030`, not at a function start, and the decompiled behavior is not this class. Recovered class output includes real helpers at `0x005c2340` and `0x005c2930`, but a recovered `class_BackPane.cpp` owner still misplaces the raw flight helpers at `0x005c2760` and `0x005c2840`. The destructor tail is interleaved with [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), so use the shared island for per-method migration.

2026-05-24 recheck: MCP still reports `0x005c2760` and `0x005c2840` as `Not a function`, while modeled Swallow starts and vtable refs remain stable. Constructor call-in is from `MapPane::SetMapState` at `0x0050dbf3`; vtable data refs cover `OnPaint`, `MoveBy`, `OnTimerEvent`, `DrawSwallow`, and the scalar deleting destructor.

Historical 2026-06-17 B002 reanalysis, corrected by the 2026-06-23 MCP-backed accepted implementation and superseded for current source routing by the 2026-08-16 whole-file audit: `0x005c29a0-0x005c29ec` is a separate Swallow-shaped raw helper after the corrected `0x005c2930-0x005c299f` invalidation helper. That pass correctly found no caller/pointer/table route and therefore kept `GetCurrentSwallowRect(...) const` descriptive rather than emitted at the time. Field directions are `+0x10c` flight-active, `+0x110/+0x114` X/Y, `+0x118` direction, and `+0x11c/+0x144` frame records with rect fields at `+0x12c/+0x154`; the raw rect helper itself directly reads `+0x118`, selects rect subfields at `+0x12c` or `+0x154`, writes the 16-byte rect to the caller output pointer, and offsets it through `0x004b78f0` using `+0x110/+0x114`.

Historical 2026-06-27 B011 accepted implementation, superseded for current source routing by the 2026-08-16 whole-file audit: [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) recorded that MCP session `b001_000241_20260627` found no function objects at `0x005c2760` or `0x005c2840`, zero xrefs to both raw starts/endpoints, no VA/RVA pointer route, no Swallow vtable slot, and no confirmed external direct-transfer route. `decompile 0x005c2500` showed that the modeled `OnTimerEvent` family shares the same active flag `+0x10c`, direction `+0x118`, position `+0x110/+0x114`, frame-rect invalidation, 10 ms step scheduling, and random restart delay. Those negative route checks remain valid and are retained; the later whole-file reconstruction resolves the source-shape question by placing the complete retained bodies in exact children [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md) and [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md), rather than leaving their behavior absent from the reconstructed module.

## 2026-06-23 Raw Rect Helper Boundary Correction

B002 accepted implementation corrected [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) from the stale `0x005c29a0-0x005c29ea` range to `0x005c29a0-0x005c29ec` using IDA MCP session `0b5e057e`. `lookup_funcs` reports no function at `0x005c29a0` and reports successor `sub_5C29EC` at `0x005c29ec` size `0xb`; MCP `get_bytes`/`disasm` shows `0x005c29e9: retn 4` consumes bytes through `0x005c29eb`; bytes `0x005c29ea-0x005c29eb` are operands of that return instruction, not padding. The successor Snowing thunk starts immediately at `0x005c29ec`, so no `0x005c29ea-0x005c29ec` padding child should be created.

The helper remains Swallow-owned class evidence because it reads the same concrete Swallow direction, current-position, and frame-rectangle fields as the modeled timer/draw/invalidation family. MCP `decompile 0x005c2930` corroborates the same `+0x118`, `+0x110/+0x114`, and `+0x12c/+0x154` field family; MCP `decompile 0x005c2500` corroborates timer ids 256/257, `sub_4B78F0`, `sub_4B8E00`, `_rand`, `sub_5975E0`, and the live modeled call to `sub_5C2930`. B002's historical negative route checks found no IDA function object, target decompilation failed, `callees 0x005c29a0` returned `No function found`, `xrefs_to 0x005c29a0` returned zero, and no raw-start/stale-endpoint pointer or Swallow-vtable route was present. The nearby pointer `0x00631304 -> 0x005c29ec` is Snowing thunk data, not a route to this helper, and the body prefix is unique at `0x005c29a0`. BackPane ownership, Snowing ownership, base WeatherLayerPane direct method ownership, and padding/ignored treatment remain rejected. The 2026-08-16 whole-file audit accepts inferred `GetCurrentSwallowRect(RectBounds *) const` as the best human-source disposition and emits it through [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), while preserving the absent-route evidence and inferred-name/type status.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed the modeled Swallow constructor/destructor and virtual method ranges: `0x005c2230-0x005c2340`, `0x005c2340-0x005c235f`, `0x005c2360-0x005c2423`, `0x005c2430-0x005c24fa`, `0x005c2500-0x005c26a6`, `0x005c26b0-0x005c275c`, `0x005c2930-0x005c299f`, thunks at `0x005c2a02-0x005c2a0d` and `0x005c2a0d-0x005c2a18`, and scalar deleting destructor `0x005c2a60-0x005c2ab5`. The constructor is called from `MapPane::SetMapState` at `0x0050dbf3`, calls the base weather constructor at `0x005c225b`, and stores the Swallow vtable views at `0x00631340`, `0x00631394`, and `0x006313c4` from constructor/destructor/deleting-destructor family addresses. Vtable slots point to `DrawSwallow`, `OnPaint`, `MoveBy`, `OnTimerEvent`, adjustor thunks, and the scalar deleting destructor. The UTF-16 `SWALLOW.EPF` and `SWALLOW.EPD` literals at `0x006313cc` and `0x006313e4` have only constructor xrefs from `0x005c22d6`/`0x005c22e9` and `0x005c22f0`/`0x005c2303`.

Historical 2026-06-10 disposition: this raised the class page above the strict `85/85` direct-parent gate while leaving formal C++ blank because the raw flight helpers were then unmodeled/no-xref/no-route starts. The 2026-08-16 whole-file audit supersedes that source-output decision: ten exact source children now emit the complete Swallow method family through this class router, while compiler-only destructor support, vtable/RTTI data, resource literals, and padding remain non-authored evidence.

## Cross-References

- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Evidence: the page documents the weather-layer behavior, method map, raw helper caveats, recovered-owner misplacement, constructor call-in, vtable refs, and shared destructor island; confidence remains capped by raw flight helpers that IDA still does not model as functions.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the current weather-layer source-family parent. C++ remains blank because raw flight-helper ownership/liveness needs more work and the class is below the 95+ final-source threshold.
- 2026-06-06 provenance cleanup:
  - Before: the status, method map, data caveats, and coverage row still described the class through output-provenance wording.
  - After: replaced those phrases with IDA/by-memory evidence basis and recovered-owner caveat wording; scores, parent attachment, and blank final C++ were unchanged.
  - Evidence: [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and the shared weather-layer aggregate already carry the exact boundaries and caveats.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed modeled Swallow ranges, constructor caller, base-constructor call, vtable stores, method/thunk/deleting-destructor slots, and `SWALLOW.EPF`/`SWALLOW.EPD` constructor xrefs. The class now clears the direct-parent gate for exact Swallow vtable and resource-string children while raw helper liveness still blocks final C++.
- 2026-06-17 B002 source-quality sync:
  - Metadata unchanged.
  - Summary/evidence: synced [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)'s corrected half-open end `0x005c299f`, added adjacent [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), recorded source-facing field/method directions, and preserved the blank class C++ policy because raw helper liveness and final weather-family source split remain unresolved.
- 2026-06-23 B002 MCP-backed raw-rect endpoint correction:
  - Metadata unchanged.
  - Summary/evidence: corrected the adjacent raw rect-helper reference from stale `0x005c29a0-0x005c29ea` to `0x005c29a0-0x005c29ec` with accepted MCP session `0b5e057e`. `lookup_funcs` reports no function at the raw start and successor `sub_5C29EC` at `0x005c29ec`; `get_bytes`/`disasm` proves the `retn 4` at `0x005c29e9` consumes bytes through `0x005c29eb`; modeled `sub_5C2930`/`sub_5C2500` decompiles corroborate the field family; xref/pointer/vtable checks find no live route to `0x005c29a0`; `0x00631304 -> 0x005c29ec` is Snowing thunk data. Preserved the no-live-route proof, rejected BackPane/Snowing/base WeatherLayerPane direct ownership plus padding/ignored and forced-C++ alternatives, kept `GetCurrentSwallowRect` descriptive only, kept `RectBounds`/`RECT` type uncertainty, and kept class C++ blank.
- 2026-06-27 B011 raw flight-helper marker sync:
  - Metadata unchanged.
  - Summary/evidence: synced [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)'s accepted `87/90` no-code-marker disposition. Current MCP session `b001_000241_20260627` keeps no function/xref/pointer/vtable/direct-transfer route for the raw start and step helpers, while [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)'s modeled `OnTimerEvent` covers the live timer behavior. Preserved Swallow ownership, generated BackPane pollution rejection, inferred-only `StartSwallowFlight`/`StepSwallowFlight` names, and blank class C++.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted a formal comment marker stating that SwallowLayerPane class-owned methods, resources, and vtable support emit on exact child pages. This preserves [UID:0000E9] as direct class owner without duplicating modeled Swallow method bodies, raw-helper marker dispositions, resource handling, or vtable output on the broad class page.
- 2026-07-05 B009 UID0002ZA generated-route repair:
  - Metadata unchanged.
  - Summary/evidence: added the formal `[[CHILDREN]]` marker to the existing class-route comment, matching [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), and [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md). This keeps [UID:0000E9] as the direct Swallow class owner while allowing exact child pages, including [UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md), to emit through the weather-family generated source route without duplicating class bodies or hand-authored vtable arrays.
