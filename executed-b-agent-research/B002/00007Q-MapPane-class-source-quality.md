** TARGET-REPORT-UID:00007Q **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-mappane-class-source-quality-00007Q-20260618

## Scope And Direct-Edit Statement

Agent-B002 report-only pass for [UID:00007Q] `by-class/MapPane.md`.

I did not edit by-* documentation, generated reports, generated source, IDA DB files, or `by-memory/-coverage-report.md`. This report is the only file created for this assignment.

Primary recommendation: keep [UID:00007Q] as the source-owned `MapPane` class attached to [UID:0000L3] `by-file/MapPane.md`, update stale open-question text and coverage rows, raise the class metadata to `88/87`, and keep the class formal C++ block blank for now because exact by-memory children already own emitted method bodies and a stable class/header declaration is not ready.

## Evidence Checked

- Active supervisor/B002 instructions: `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B002/goal.md`, and `tools/leaser/Agents/Agent-B002/notes.md`.
- Primary/support docs: `by-class/MapPane.md`, `by-file/MapPane.md`, `by-project-structure/by-structure.md`, `by-project-structure/proposed-source-tree.md`, `inference_research.md`.
- MapPane aggregate and duplicate pages: [UID:0001AP] `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`, [UID:0001AT] `0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`, [UID:0001AW] `0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, [UID:0001AX] `0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md`, and [UID:0001G6] `0x00557140-0x00559aef.SurfacePresentation.md`.
- Support pages: `MapServerPacketOpcode`, `ObjectList`, `ObjectPane`, `ObjectStatusBlob`, `g_activeMapPane`, `Surface`, `WeatherLayerPane`, and `Effects`.
- Accepted prior B reports now reflected in docs: `0002I2-mappane-find-active-effect-source-quality.md`, `0002I7-0002QF-mappane-lifecycle-source-quality.md`, `0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md`, and `0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md`.
- Generated output and reports: `auto-generated/NexusTK/map/MapPane.cpp`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-memory/-coverage-report.md`.

## Heuristic / Inference Reanalysis And Validation

### Class Ownership And Emission Route

The current class owner/emitter route is correct: [UID:00007Q] remains `MapPane`, with canonical owner and emitter [UID:0000L3] `MapPane.cpp`. The class is not just an index page. It owns the live map pane instance state, vtable-backed lifecycle, packet/render/weather/object method families, `g_activeMapPane` publication/clear behavior, `ObjectList` at `MapPane +0x424`, and the MapPane coordinate/movement surface including `g_movementSubstepScale`.

Rejected alternative: converting [UID:00007Q] to a non-emitting split/index. That would be wrong because exact method pages now use this class as the semantic source owner and several accepted reports have already populated child C++ through the class/file route.

Rejected alternative: emitting broad method bodies directly from [UID:00007Q]. That would duplicate exact child emitters and would mix class declaration work with method-body reconstruction. The active policy favors exact source-bearing by-memory pages for method bodies.

### Weather Source Placement

Best defensible split:

- `MapPane.cpp` owns packet-driven weather/day-night orchestration, map runtime state, weather selection, screen-effecter list lifecycle, and fields `+0xf8/+0xfc/+0x100` as `m_screenEffecterCount`, `m_screenEffecterCapacity`, and `m_screenEffecters`.
- `WeatherLayerPane`, `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` remain map-weather overlay pane sources under `NexusTK/map/`, not generic render sources. Their constructors and vtables are separate class/source evidence, with construction reached from MapPane state changes.
- `Effects.cpp` owns runtime `ScreenEffecter` classes and pixel/effect behavior. MapPane owns the list and consumers; it does not own the effecter class implementations.

This validates the current docs that keep MapPane weather orchestration in `MapPane.cpp`, but it makes the class open question "Resolve final file placement for weather" stale at the MapPane class level. The remaining weather uncertainty is one-file versus per-weather-pane organization inside the weather-family support docs, not a blocker for MapPane class placement.

Rejected alternatives:

- Moving all MapPane weather logic into `Effects.cpp`: rejected because MapPane owns packet state, day/night fields, and weather-layer construction.
- Folding all weather layer classes into `MapPane.cpp`: rejected because the weather layer pages have independent class/vtable/resource evidence and source-family pages.
- Treating `g_pWeatherState` as a separate weather singleton: rejected by current `WeatherLayerPane`/`Effects` docs; it is a generated alias for `g_activeMapPane`.

### `0x00510400` Raw Duplicate Boundary

[UID:0001AX] should remain a retained raw duplicate evidence page for the opcode `0x20` day/night body, not an independent `MapPane::HandleWeatherPacket` method. Evidence already in the current docs is decisive enough for class-level closure:

- IDA does not model `0x00510400` as a function.
- The raw bytes form a function-shaped body ending before the modeled `0x005104d0` helper, but there are no direct callers/xrefs/pointer-route hits to `0x00510400`.
- The live dispatcher contains the same body inline at `0x00507e45-0x00507f04` under opcode `0x20`.
- [UID:0001AX] records the hour/index validation, writes to `MapPane +0x40f`, table load from `dword_66DD78`, lighting/fade field updates, and apply-helper call.

Impact: class/file open-question text should stop asking to "review the `0x00510400` weather-handler function boundary before migrating that method." The defensible action is to keep it as raw duplicate support and avoid formal C++ on [UID:0001AX] unless new function/xref evidence appears.

Rejected alternative: split `0x00510400` as a source method. There is no modeled function, no direct route, and the dispatcher duplicate is the proven source route.

### `0x00557140-0x00559aef` Surface Presentation Ownership

This is resolved away from MapPane for current class-quality purposes. [UID:0001G6] `SurfacePresentation` is a non-emitting mixed-owner container. Exact children split across Surface, ScreenPane, and ScreenshotCapture ownership. Current `MapPane.md` says the range "remains tracked under Surface as a shared DirectDraw presentation review bucket"; that is broadly correct but should be strengthened to say it is not a MapPane unresolved source-placement item.

Impact: remove this range from MapPane's open class questions. Keep only a generated-owner-pollution note.

Rejected alternative: treat `0x00557140-0x00559aef` as MapPane rendering methods because generated output or old rows placed presentation-like names near MapPane. Exact child evidence now proves mixed ownership.

### Packet-Handler Split, Protocol Family, And Naming Direction

[UID:0001AW] should remain a class-owned aggregate over MapPane packet handlers with blank C++, while exact children continue to carry source. The accepted B001/B002 splits now prove many direct opcode handlers and no-receiver file-static helpers:

- Class methods: exact handlers such as draw-objects, movement/speech, object move/effect, world-map creation, action, flying-object update, animation/sound, object-status, object-info, and map-transition handlers.
- File-static or no-receiver helpers: outbound object/action/coordinate/status helpers and [UID:000231] `SendObjectRefreshRequest` / `RequestMissingObjectById`.
- Raw duplicate support: [UID:0001AX] for opcode `0x20`.

Best naming direction: keep descriptive handler names by opcode role while [UID:0001SO] remains a working dispatcher enum/payload index. Do not force final enum names or payload struct names into the class page. Place final packet names in exact handler pages and the enum/type support page after payload structures stabilize.

Rejected alternatives:

- Split [UID:0001AW] by every opcode family now: premature for the aggregate page. Exact children already split routeable handlers; unsplit raw/no-route bodies remain child-level backlog.
- Move packet handlers to `ObjectList`, `ObjectStatusBlob`, `WorldMapPane`, `TimerPane`, or object-pane files because those classes are constructed or consumed. Rejected: MapPane owns the inbound dispatcher/parse/control flow; constructed classes own their own implementations.

### Low-Grade Child Review Priorities

The class page should keep a short prioritized backlog instead of a generic "Review low-grade child methods" open question. The important class-level priorities are:

- Effect-list siblings [UID:0002I1], [UID:0002I3], [UID:0002I4], and [UID:0002I6]. The shared field triplet is now resolved to `m_screenEffecterCount`, `m_screenEffecterCapacity`, and `m_screenEffecters`; remaining blockers are helper/source names, no-direct-route evidence for reset/configure, and exact effecter subtype naming.
- Coordinate/object interior helpers under [UID:0001AP], especially unsplit or still-descriptive helpers around `0x00505080-0x0050571d`, `0x00505940`, `0x00505cc0`, `0x00505de0`, and referenced no-op callbacks `0x00505730`/`0x00505740`.
- Input/shared hit-test [UID:0001AU], which is not BackPane-owned but still needs exact receiver/source placement between MapPane and target-selection module usage.
- [UID:000232] object/effect descriptor dispatch, because it is MapPane-owned and source-bearing but still uses descriptor/helper terminology that should be aligned with effect-object and ObjectList support docs.
- Raw/no-route packet bodies remaining inside [UID:0001AW], including helper starts and switch islands not yet exact-child owned.

Impact: these priorities cap [UID:00007Q] below final-source quality but do not justify leaving class ownership, weather placement, or presentation placement open.

### Field Glossary And Class Declaration Readiness

Field reanalysis supports the existing class glossary updates:

- `+0xf8/+0xfc/+0x100`: `m_screenEffecterCount`, `m_screenEffecterCapacity`, `m_screenEffecters`.
- `+0x118/+0x398/+0x39c`: deferred/queued motion records, record count, and defer-active flag.
- `+0x108/+0x10c`: selected/highlighted living-object active flag and pointer.
- `+0x414`: pending/deferred cleanup pane.
- `+0x418/+0x41c/+0x420/+0x424`: active/local object pane, auxiliary pane, active screen layer, and `m_objectList`.
- `+0x428`: embedded viewport `GrafPort`.

Remaining class-declaration blockers:

- The exact original spelling for "selected" versus "highlighted" object fields remains unresolved.
- Day/night/weather fields such as `+0x3b8/+0x3c8/+0x3cc/+0x3e4/+0x3e8/+0x40f` are behaviorally understood but not final declaration-quality names.
- `+0x4c8` family and `+0x90c/+0x90e` runtime/state flags remain descriptive.
- Packet payload structs and object/effect descriptor record names are not stable enough for a class header.
- Generated output still contains stale field aliases such as `m_layerStates` and `m_objectListDetachPreserve`, while the docs now prefer deferred-motion and active/local-object terminology.

Impact: the class page can score above the active gate on ownership/source-quality evidence, but formal class-level C++ should remain blank until the declaration emitter can avoid stale field names and duplicated child bodies.

### Generated Output Pollution

`auto-generated/NexusTK/map/MapPane.cpp` confirms current output is useful but not declaration-clean:

- It contains exact child method bodies for accepted pages, including constructor/destructor, queue/teardown/object helpers, and `SendObjectRefreshRequest`.
- It still shows stale aliases `m_layerStates` and `m_objectListDetachPreserve`, conflicting with the current class glossary.
- The class page should not be used to paste method bodies or to force a class declaration that would lock in those stale names.

Impact: record generated-output pollution as a source-quality blocker for class-level C++, not as a reason to undo emitted child C++.

## Score And Metadata Recommendation

Update [UID:00007Q] from `85/85` to:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: class ownership, weather/source placement, raw duplicate treatment, presentation exclusion, lifecycle/object fields, ObjectList relationship, active singleton, and many exact child emitters are now resolved beyond the old `85/85` state. Confidence should remain under 90 because final class declaration names, packet payload structs, and several child/helper names remain unresolved.

No score change is required for [UID:0000L3] `by-file/MapPane.md` in this class pass; the current `89/85` still fits a broad source-file page with strong placement and medium-high companion split confidence.

## First-Draft C++ Recommendation

Do not populate [UID:00007Q] formal C++ in this pass.

This is target-specific no-code proof, not a stale threshold argument:

- [UID:00007Q] is a class hub. Exact by-memory children already emit source-bearing method bodies through [UID:0000L3] `MapPane.cpp`.
- A class-page formal block would currently need to be declaration/header material, not method bodies. The documentation pipeline is already emitting a `.cpp` file from exact child pages; a partial class declaration here would not have a proven header emitter and could conflict with generated child output.
- The field glossary is strong enough for source-quality notes but not for a stable full class declaration. Stale generated names such as `m_layerStates` and `m_objectListDetachPreserve` prove the emitted file and current glossary are not synchronized.
- Packet payload structs, day/night/runtime fields, object/effect descriptor record types, and several helper names are not declaration-quality yet.

Source-shape guidance only, not recommended for direct insertion into `RECONSTRUCTION_CPP`:

```cpp
// Source-shape guidance for a future MapPane.h/MapPane.cpp split.
// Do not place this in the current class formal block until the header emitter
// and field glossary are synchronized with exact child C++.
class MapPane : public Pane {
public:
    MapPane(int visibleTileColumns, int visibleTileRows);
    virtual ~MapPane();

    bool HasScreenEffecters() const;
    ScreenEffecter *FindActivePixelEffecter();
    void ResetScreenEffecterList();
    void ConfigureScreenEffecters(int mode);
    void ClearScreenEffecters();

    void QueueMotionMessage(const Rect *rect);
    void ExitToMenu(bool notifyServer);
    void OnTagDetachMessage(Pane *sender, const TaggedPaneMessage *message);

    void ScrollViewportByDirection(unsigned char direction);
    void RecenterAndSendPosition(int worldX, int worldY);
    ObjectPane *CreateOrUpdateObjectPane(int objectId, const ObjectStatusBlob *status);
    void RemoveObjectPaneById(int objectId);
    void DetachObjectPane(ObjectPane *objectPane);
    bool HasObjectIntersectingRect(const Rect *rect) const;

private:
    int m_screenEffecterCount;
    int m_screenEffecterCapacity;
    ScreenEffecter **m_screenEffecters;
    DeferredMotionRecord m_deferredMotionRecords[32];
    int m_deferredMotionRecordCount;
    bool m_deferMotionMessages;
    AlphaMaskSurface *m_selectionOverlay;
    ObjectPane *m_selectedObjectPane;
    ObjectPane *m_activeObjectPane;
    Pane *m_auxiliaryPane;
    Layer *m_activeScreenLayer;
    ObjectList m_objectList;
    GrafPort m_viewportGrafPort;
};

static void SendObjectRefreshRequest(int objectId);
```

The draft intentionally omits method bodies and leaves several names descriptive. Formal code should instead continue to live on exact child pages until a dedicated class/header pass resolves all layout and emitter constraints.

## Exact Supervisor Edits

### `by-class/MapPane.md` Header

Replace only the completion/confidence values:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### `by-class/MapPane.md` Status Bullet

Replace:

```text
- Autogen parent: [UID:0000L3][MapPane](by-file/MapPane.md). The class is source-owned, but final C++ remains blank until packet fields, companion splits, and generated field names are final-source quality.
```

with:

```text
- Autogen parent: [UID:0000L3][MapPane](by-file/MapPane.md). The class is source-owned and exact method bodies should continue to emit from by-memory children through the MapPane.cpp file route. Keep this class formal C++ block blank until a stable header/class declaration emitter exists and the remaining field, packet-payload, and descriptor names are synchronized with generated child output.
```

### `by-class/MapPane.md` Major Method Families Weather Row

Replace the weather row with:

```text
| Weather and lighting | `0x00503e80`, `0x00503e90`, `0x00503ef0`, `0x005040a0`, `0x0050a8b0`, `0x0050db50`, retained raw duplicate `0x00510400` | Runtime screen-effecter list checks/configuration/cleanup, weather-layer construction, day-night state, lighting effects, and weather packets. MapPane owns orchestration and the `+0xf8/+0xfc/+0x100` effect-list fields; runtime `ScreenEffecter` classes belong with Effects; weather overlay pane implementations belong with the WeatherLayerPane/Raining/Snowing/Swallow map-weather family. `0x00510400` is raw duplicate evidence for dispatcher opcode `0x20`, not an independent migrated method. |
```

### `by-class/MapPane.md` Ownership Notes Pollution Bullets

Replace:

```text
- `0x00557140-0x00559aef` remains tracked under [UID:0000OC][Surface](by-file/Surface.md) as a shared DirectDraw presentation review bucket.
```

with:

```text
- `0x00557140-0x00559aef` is not an unresolved MapPane ownership range. [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) is a non-emitting mixed-owner container whose exact children route to Surface, ScreenPane, or ScreenshotCapture.
```

### `by-class/MapPane.md` Open Questions Section

Replace the full `## Open Questions` section with:

```text
## Resolved / Remaining Source-Quality Work

- Weather/source placement: MapPane owns packet-driven weather/day-night orchestration, `m_screenEffecters`, state changes, and construction calls into weather layers. Runtime effecter classes belong to [UID:0000IZ][Effects](by-file/Effects.md); weather overlay pane implementations belong to the WeatherLayerPane/Raining/Snowing/Swallow map-weather family. Generic render-only weather placement for MapPane methods is rejected.
- Raw `0x00510400`: keep [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) as retained raw duplicate evidence for dispatcher opcode `0x20`. Do not migrate it as an independent `MapPane::HandleWeatherPacket` method unless new function/xref/table evidence appears.
- Surface presentation: [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) proves a mixed non-emitting Surface/ScreenPane/ScreenshotCapture container, not MapPane source.
- Packet handlers: exact child pages now split most direct opcode handlers and no-receiver file-static helpers. [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) should remain a class-owned aggregate with blank C++ until final payload structs/opcode names and raw/no-route helper bodies are resolved on exact children.
- Low-grade child priorities: review [UID:0002I1]/[UID:0002I3]/[UID:0002I4]/[UID:0002I6] effect-list helpers, coordinate/object interior helpers under [UID:0001AP], shared hit-test [UID:0001AU], descriptor dispatch [UID:000232], and remaining raw/no-route packet bodies under [UID:0001AW] before rename-heavy migrations.
- Class declaration readiness: keep [UID:00007Q] formal C++ blank. Exact method bodies emit from child pages; a class/header block requires stable field layout, packet payload structs, and synchronization with generated output.
```

### `by-file/MapPane.md` Open Questions Section

Replace the full `## Open Questions` section with:

```text
## Resolved / Remaining Source-Split Questions

- Resolved for MapPane: `0x00557140-0x00559aef` is not MapPane. [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) is a non-emitting mixed Surface/ScreenPane/ScreenshotCapture presentation container.
- Resolved for current migration: weather orchestration, day/night packet state, and the runtime effecter list stay in `MapPane.cpp`; weather overlay pane implementations stay in the WeatherLayerPane/Raining/Snowing/Swallow map-weather family; runtime `ScreenEffecter` classes stay in [UID:0000IZ][Effects](by-file/Effects.md). One-file versus per-layer organization remains a weather-family question, not a MapPane owner blocker.
- Resolved: `MapPaneSpatialIndex` should be treated as a generated/provisional ObjectList alias or private view over the same object-list layout, not as a separate original source file.
- Still open: whether `MapNamePane` and `MapRefreshDimmer` were private helper classes in `MapPane.cpp` or separate map UI files.
- Still open: whether the nation-entry helper currently named `GameServerConfig` was a separate `map/GameServerConfig.cpp` or private MapPane source-local helper.
- Still open: final naming for [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) values and packet payload structures.
- Still open: whether `TimerPane` was a standalone map UI source file or a private helper inside `MapPane.cpp`.
- Still open: final MapPane class declaration names for remaining runtime, day/night, descriptor, and packet fields. Exact child method bodies should continue to own formal C++ until those names stabilize.
```

### Support Docs

No metadata changes are required for `ObjectList`, `ObjectPane`, `ObjectStatusBlob`, `g_activeMapPane`, `Surface`, `WeatherLayerPane`, or `Effects`; the current support docs already carry the key owner/exclusion facts at equal or greater detail.

Recommended insert in `by-type/by-enum/MapServerPacketOpcode.md` under its declaration-readiness/source-quality notes:

```text
- 2026-06-18 B002 MapPane class pass: keep this enum as a working dispatcher/payload index rather than a final emitted protocol header. MapPane exact handler pages may use descriptive opcode names, but [UID:00007Q][MapPane](by-class/MapPane.md) should not emit a class-level C++ enum/declaration until payload structures and handler names are synchronized.
```

## Coverage Row Recommendation

### `by-class/-coverage-report.md`

Replace the current [UID:00007Q] row with:

```text
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 88% : strong : Live game-world pane class attached to [UID:0000L3][MapPane](by-file/MapPane.md); accepted lifecycle/effect/movement/object/teardown passes resolve constructor/destructor, screen-effecter fields, deferred-motion records, selected/local object fields, ObjectList ownership, raw `0x00510400` as retained opcode `0x20` duplicate, and `0x00557140-0x00559aef` as non-MapPane mixed Surface/ScreenPane/Screenshot work. Keep formal C++ blank for this class hub until a stable header/class declaration emitter and remaining packet payload/field names are synchronized; exact method bodies emit from by-memory children.
```

### `by-file/-coverage-report.md`

Replace the current [UID:0000L3] row with:

```text
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : strong : Major `NexusTK/map/MapPane.cpp` source module with accepted lifecycle/effect/movement/object/teardown C++ children, companion-class split guidance, active-map singleton and ObjectList relationships, [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) ownership, weather orchestration split from WeatherLayerPane/Effects, raw `0x00510400` retained as dispatcher duplicate, and `0x00557140-0x00559aef` excluded as mixed Surface/ScreenPane/Screenshot presentation work; remaining blockers are final packet payload/field names and small companion private-vs-separate file decisions.
```

### `by-memory/-coverage-report.md`

Replace the current [UID:0001AP], [UID:0001AT], and [UID:0001AW] rows in the MapPane cluster with:

```text
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) 0x00503ef0-0x0050637a | class aggregate | MapPaneWeatherCoordinateObjectCore : reconstructable : 86% : strong : MapPane weather/effect, lifecycle, map-cache, coordinate, scroll, and object-core aggregate attached to [UID:00007Q][MapPane](by-class/MapPane.md); exact constructor/destructor/effect/motion/teardown/object helpers now carry source-quality evidence or C++, field aliases are updated for screen-effecters and deferred motion records, and aggregate C++ stays blank to avoid duplicating child bodies while interior coordinate/object/state helpers finish.
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) 0x00506970-0x0050e320 | mixed-owner audit aggregate | MapPaneInputPacketRenderCore : not_reconstructable : 88% : very strong : Reviewed non-emitting physical container over exact MapPane child ranges and the excluded ProfileStorage [UID:0001AV][0x00508e10-0x0050902c.SaveUserSettings](by-memory/0x00508e10-0x0050902c.SaveUserSettings.md) island; MapPane source-bearing children attach directly to [UID:00007Q][MapPane](by-class/MapPane.md), so this aggregate stays parentless/RECONSTRUCTABLE:FALSE with blank C++.
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | class aggregate | MapPanePacketHandlers : reconstructable : 85% : strong : Class-owned MapPane packet-handler aggregate ending before MapRefreshDimmer; exact opcode/object/effect/action/status children and no-receiver MapPane.cpp helpers are now split, [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) remains retained raw opcode `0x20` duplicate evidence, destructor glue is split out, and aggregate C++ stays blank because final payload structs/opcode names and raw/no-route bodies remain child-level work.
```

No coverage-row change is required for [UID:0001AX]; its current row already states the retained raw duplicate/no-C++ conclusion. Exact effect-list child row wording for [UID:0002I3] and [UID:0002I6] is stale about unresolved field/object type names, but those rows should be corrected in a future exact child pass rather than this class-level report.

## Validator Commands

Run after supervisor applies the recommended edits:

> Executable block R001 was removed from this report and preserved verbatim in [00007Q-MapPane-class-source-quality-removed.md](00007Q-MapPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: first two commands show updated rows; third command should not find stale class/file open-question wording; fourth command may still find generated-output stale aliases until exact child C++ or generator inputs are refreshed.

## Changed Files

- Created report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00007Q-MapPane-class-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00007Q-MapPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00007Q"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007Q-MapPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00007Q-MapPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
