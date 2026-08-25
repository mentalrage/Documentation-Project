** TARGET-REPORT-UID:0001AR **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001AR] DrawVisibleTilesHelper Source-Quality Report

Agent: B005
Target: [UID:0001AR] `by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md`
Required report path: `tools/leaser/Agents/Agent-B005/research/0001AR-DrawVisibleTilesHelper-source-quality.md`
Assignment type: report-only B-preferred source-quality / heuristic-inference pass.

## Retry-Free Final Recommendation

Path to the completion gate is available. Recommend raising the target from `84/88` to `88/90`, preserving `RECONSTRUCTABLE:TRUE`, and rerouting the direct owner/emitter from the broad file root [UID:0000L3][MapPane](../../../by-file/MapPane.md) to the class owner [UID:00007Q][MapPane](../../../by-class/MapPane.md). [UID:0000L3] remains the source module for `map/MapPane.cpp`.

The helper is a source-authored `MapPane` instance method. The strongest source-facing name is `MapPane::RedrawVisibleTiles()` or, if the supervisor wants the no-clear distinction explicit, `MapPane::DrawVisibleTilesNoClear()`. I recommend `RedrawVisibleTiles()` for formal C++ because accepted MapPane movement/render docs already use `DrawVisibleTiles()` for sibling `0x0050d840`, which is the fuller clear-and-draw visible-tile routine. Reusing `DrawVisibleTiles()` for this target would create a source-name collision without a coordinated rename of `0x0050d840`.

Formal first-draft C++ should be populated on [UID:0001AR]. The remaining original-spelling uncertainty does not block code entry: the byte behavior, receiver type, field names, callee roles, caller routes, and non-owner alternatives are all source-quality enough. The spelling uncertainty only caps confidence below final-audit `95`.

No direct edits were made to `by-memory/-coverage-report.md`, generated outputs, or support docs.

## Evidence Checked

Guidance reread: `Agent-B005/goal.md`, `Agent-B005/notes.md`, `Supervisor.md`, `by-structure.md`, and `inference_research.md`.

Live IDA MCP was attempted at the documented local endpoint and was unavailable (`Unable to connect to the remote server`). I therefore used the refreshed local IDA export under `C:\Users\admin\Desktop\CTools\Output\ida` plus current by-* docs. Evidence checked:

- Target doc [UID:0001AR].
- MapPane file/class/aggregate docs: [UID:0000L3], [UID:00007Q], [UID:0001AP], [UID:00037Y], [UID:0001AT].
- Accepted MapPane movement source-quality report/docs around [UID:0002QM], especially the formal `DrawVisibleTiles()` call and field names.
- ScreenPane/Surface/ParcelPane support docs: [UID:0000NB], [UID:0000CB], [UID:0001G5], [UID:0003A2], [UID:0001G6], [UID:0000OC], [UID:0000MF], [UID:0000A6].
- Supporting globals/helpers: [UID:0000PR] `g_activeMapPane`, [UID:0000RG] `g_pMapTileImageLib`, [UID:000165] `SurfacePaintHelpers`, MapPane legacy remap constants.
- Local decompile exports for `0x005051c0`, `0x00505290`, `0x0050d8e0`, `0x0050d840`, `0x00556d50`, and coordinate helpers `0x00505130`, `0x00505170`, `0x00505230`, `0x00505310`, `0x00505350`, `0x00505370`.
- Local function/xref/memory exports: `functions.json`, `xrefs.json`, `memory.bin`, `segments.json`, and `memory.meta`.

## Exact Range, Bytes, And Boundary

The target is a modeled `.text` function:

| Item | Evidence |
| --- | --- |
| Function start | `0x005051c0` |
| Function end | `0x00505228` half-open |
| Size | `0x68` / 104 bytes |
| Preceding bytes | `0x005051bb-0x005051c0`, five `0xcc` bytes |
| Following bytes | `0x00505228-0x00505230`, eight `0xcc` bytes |
| Next modeled function | `0x00505230-0x00505281` |

Local byte dump:

```text
0x005051bb-0x005051c0: cc cc cc cc cc

0x005051c0-0x00505228:
55 8b ec 83 ec 18 53 8b d9 57 89 5d fc 8d 83 28 04 00 00
8b c8 89 45 f8 e8 43 46 fb ff 8d 45 e8 8b cb 50 e8 a8 00
00 00 8b 7d ec 8b 45 f4 3b f8 7d 28 8b 5d f0 56 8b 75 e8
3b f3 7d 17 0f 1f 00 8b 4d fc 6a 00 57 56 e8 d4 86 00 00
46 3b f3 7c ef 8b 45 f4 47 3b f8 7c dd 5e 8b 4d f8 e8 9e
46 fb ff 5f 5b 8b e5 5d c3

0x00505228-0x00505230: cc cc cc cc cc cc cc cc
```

No split or range change is needed. The target's exact half-open range and padding are already correct; the report should only improve ownership, field/helper naming, C++ readiness, and stale support-doc language.

## Function Behavior And Callees

Local decompilation of `0x005051c0` shows:

1. Compute `this + 0x428` and save it as the paint target.
2. Call `0x004b9820` / `UpdateSurfaceInfo` on that embedded GrafPort-style member.
3. Call `0x00505290` with a local four-integer bounds record.
4. Loop `tileY` from `bounds.top` to `bounds.bottom` exclusive.
5. Inside that loop, loop `tileX` from `bounds.left` to `bounds.right` exclusive.
6. Call `0x0050d8e0(this, tileX, tileY, 0)` for each tile.
7. Call `0x004b98c0` / `EndPaint` on the same `this + 0x428` member.

Direct callees from local export:

| VA | Source-facing role | Notes |
| --- | --- | --- |
| `0x004b9820` | `UpdateSurfaceInfo` / begin paint for GrafPort-style surface | Shared Surface/GrafPort paint helper; dependency, not owner. |
| `0x00505290` | `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const` | Uses `m_tileOriginX/Y`, visible spans, and dimensions. |
| `0x0050d8e0` | `MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint)` | Validates tile coords, fetches tile layer ids, draws through `g_pMapTileImageLib`. |
| `0x004b98c0` | `EndPaint` / end paint for GrafPort-style surface | Shared Surface/GrafPort paint helper; dependency, not owner. |

The `0x0050d8e0` repaint flag is resolved: if its fourth parameter is `1`, it opens and closes the `this+0x428` paint lifecycle internally. This target passes `0`, so it intentionally performs a batch draw under the outer paint lifecycle opened by `0x005051c0`.

## Callers, Xrefs, And Reachability

Local `xrefs.json` records exactly two code xrefs to the target:

| Xref | Function model | Interpretation |
| --- | --- | --- |
| `0x00556dee` | Inside modeled `0x00556d50-0x00556f61` `ScreenPane::HandleMessage` body | Direct caller. It loads `g_activeMapPane`, validates the active pane, calls this method, then invokes the pane virtual repaint/update slot at vtable offset `+0x20`. |
| `0x005593e3` | Inside raw, non-modeled `0x005593b0-0x0055940c` ScreenPane palette bridge | Real code xref but not a modeled function caller. It has the same active-map repaint pattern and is documented by [UID:0003A2]. |

The target has no data refs in the local xref record. The raw `0x005593b0` body is not a function record in `functions.json`; `0x00559410` is the next modeled function. Raw bytes around `0x005593b0-0x0055940c` include the direct call to `0x005051c0` and the following four-byte `0xcc` padding at `0x0055940c-0x00559410`.

The unmodeled `0x005593e3` xref should not alter this target's source placement. It is a ScreenPane-owned wrapper/caller that obtains the active MapPane through `g_activeMapPane`; it does not make the called `this` method a ScreenPane, SurfacePresentation, or shared render helper.

## Receiver And Field Model

The receiver is `MapPane *`. The target directly uses `this + 0x428`; its callee chain and neighboring coordinate helpers resolve the rest of the required fields:

| Offset | Source-facing name | Evidence |
| --- | --- | --- |
| `+0x3f4` | `m_mapWidth` | `0x00505290` clamps right edge against unsigned word at `this+0x3f4`; `0x0050d8e0` validates tile X against the same field; MapPane class docs already carry this name. |
| `+0x3f6` | `m_mapHeight` | `0x00505290` clamps bottom edge against unsigned word at `this+0x3f6`; `0x0050d8e0` validates tile Y against the same field; MapPane class docs already carry this name. |
| `+0x3f8` | `m_tileBuffer` | Not read directly by this function, but `0x0050d8e0` reaches `0x0050c120`, which reads tile records from this field; MapPane class docs and B002 remap-constant report carry this name. |
| `+0x3fc` | `m_tileOriginX` | `0x00505130` subtracts `this[255]` for map-to-screen X; `0x00505170` adds `this[255]` for screen-to-map X; `0x00505290` builds left from this field minus one; accepted [UID:0002QM] formal C++ uses `m_tileOriginX`. |
| `+0x400` | `m_tileOriginY` | `0x00505130` subtracts `this[256]` for map-to-screen Y; `0x00505170` adds `this[256]` for screen-to-map Y; `0x00505290` builds top from this field minus one; accepted [UID:0002QM] formal C++ uses `m_tileOriginY`. |
| `+0x404` | `m_visibleTileColumns` | `0x00505290` computes right from left + this field + 2; `0x00505230` validates visible X against this field; constructor/source-quality docs use this name. |
| `+0x408` | `m_visibleTileRows` | `0x00505290` computes bottom from top + this field + 2; `0x00505230` validates visible Y against this field; constructor/source-quality docs use this name. |
| `+0x428` | `m_viewportGrafPort` | Target opens/closes paint lifecycle on this field. MapPane class glossary already names it as an embedded GrafPort-style member. |

The best support-doc update is to add `+0x3fc/+0x400` to the MapPane class glossary if it is still absent there, using the accepted [UID:0002QM] spelling `m_tileOriginX/m_tileOriginY`.

## Helper Names And Signatures

Recommended source-facing names:

| Address | Recommended name/signature | Reasoning |
| --- | --- | --- |
| `0x005051c0` | `void MapPane::RedrawVisibleTiles()` | Lighter visible-tile repaint helper. It batches `DrawTileAt(..., false)` under an existing outer paint lifecycle but does not clear the surface. Avoid `DrawVisibleTiles()` because accepted MapPane docs already use that name for `0x0050d840`. |
| `0x00505290` | `void MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const` | Builds left/top/right/bottom in tile coordinates, expands one tile left/top and two right/bottom, then clamps to dimensions. `GetVisibleTileBounds` is acceptable if the support docs prefer the shorter established name, but the "clamped" qualifier disambiguates it from `0x00505310` and `0x00505370`. |
| `0x0050d8e0` | `void MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint)` | Validates coordinates, fetches tile layer ids, draws through `g_pMapTileImageLib`, and opens/closes paint only when `beginPaint` is true. Existing docs and old integration notes already support `DrawTileAt`. |

Rejected helper names:

- `MapPane::DrawVisibleTiles()` for this exact target: rejected unless `0x0050d840` is renamed at the same time. `0x0050d840` clears/fills the viewport surface before drawing and is already called as `DrawVisibleTiles()` by accepted [UID:0002QM] C++.
- `MapPane::DrawTileRange()` for this target: rejected because the method draws the current clamped visible bounds without coordinate parameters; accepted docs associate tile-range behavior with other MapPane paths.
- `ParcelPane::DrawParcelSlot()` / generated parcel names: rejected by ParcelPane's 0x124-byte object size and by this function's `this+0x428` MapPane/GrafPort field use.
- `Surface::DrawVisibleTiles()` or `GrafPort::DrawVisibleTiles()`: rejected because Surface/GrafPort helpers are callees/dependencies only; the receiver state is MapPane-specific.

## Owner And Source Route Ranking

| Candidate | Ranking | Decision |
| --- | --- | --- |
| [UID:00007Q] `MapPane` class | 1 | Accepted direct owner/emitter. This is a `this` method over MapPane viewport, dimensions, tile buffer, and embedded GrafPort state. Exact child MapPane methods now routinely emit through the class route. |
| [UID:0000L3] `map/MapPane.cpp` file | 2 | Accepted source module, but too broad as direct owner. Keep as file root through the class owner. |
| `ScreenPane` / [UID:0000NB], [UID:0000CB] | 3 | Rejected as owner. It owns caller/wrapper logic at `0x00556dee` and raw `0x005593b0`, not the MapPane receiver method. |
| `SurfacePresentation` / raw repaint support | 4 | Rejected as owner. [UID:0001G6] is a non-emitting mixed container; [UID:0003A2] is the ScreenPane raw wrapper. Both call into MapPane. |
| `Surface` / `GrafPort` | 5 | Rejected as direct owner. They own paint lifecycle/callback support, while this method's receiver and loops are MapPane. |
| `ParcelPane` | 6 | Rejected. Current ParcelPane docs prove generated pollution: the real child is 0x124 bytes, so fields near `+0x428` cannot be ParcelPane state. |
| New shared render helper file/grouping | 7 | Rejected. No independent source route, data table, or multi-class receiver model explains the MapPane fields better than MapPane class ownership. |
| No-owner / ignored / non-reconstructable | 8 | Rejected. The target is modeled code, has two executable caller contexts, source-shaped loops, and a complete C++ body. |

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block on [UID:0001AR] after metadata reroute to [UID:00007Q].

```cpp
void MapPane::RedrawVisibleTiles()
{
    MapRect visibleTiles;

    UpdateSurfaceInfo(&m_viewportGrafPort);
    GetClampedVisibleTileBounds(&visibleTiles);

    for (int tileY = visibleTiles.top; tileY < visibleTiles.bottom; ++tileY)
    {
        for (int tileX = visibleTiles.left; tileX < visibleTiles.right; ++tileX)
            DrawTileAt(tileX, tileY, false);
    }

    EndPaint(&m_viewportGrafPort);
}
```

Notes for supervisor:

- `MapRect` is the same four-int left/top/right/bottom shape used by accepted MapPane child docs. If the project standard prefers `Rect`, use `Rect visibleTiles` without changing behavior.
- `GetClampedVisibleTileBounds` may be shortened to `GetVisibleTileBounds` if a single public-facing helper name is desired, but the longer name is more precise for this exact body.
- `UpdateSurfaceInfo` and `EndPaint` are current support-doc names for the shared paint lifecycle. If the GrafPort class pass later converts these into member calls, this body should be mechanically adjusted.

## Metadata Recommendation

Target metadata replacement:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises because all source-quality blockers called out in the target are now resolved or defensibly inferred: field names, helper names/signatures, owner route, raw xref impact, and first-draft C++ readiness.
- Confidence rises because local bytes/xrefs/decompiles and current support docs agree. It stays below `95` because original spelling for the no-clear repaint helper is inferred and must be coordinated with sibling `0x0050d840`.
- Direct owner should be [UID:00007Q] because this is an instance method. [UID:0000L3] remains the source file route through the class.

## Support-Doc Incorporation Plan

Do not edit generated outputs directly. If the supervisor incorporates this report, recommended exact support-doc updates are:

### Target [UID:0001AR]

In the status section, replace direct owner/source-name wording with:

```text
- Entity kind: [UID:00007Q][MapPane](by-class/MapPane.md) cached visible-tile repaint method.
- Confirmed direct source owner: [UID:00007Q][MapPane](by-class/MapPane.md); source module [UID:0000L3][MapPane](by-file/MapPane.md).
- Source-facing name recommendation: `MapPane::RedrawVisibleTiles()`; `DrawVisibleTilesNoClear` is an acceptable descriptive fallback if the supervisor wants to emphasize the contrast with the sibling clear-and-draw helper at `0x0050d840`.
- Rebuild handling: source-authored map rendering logic; populate the formal C++ block with the first-draft body from the B005 report.
```

Replace the target reconstruction decision with:

```text
Attach this helper to [UID:00007Q][MapPane](by-class/MapPane.md), emitting through [UID:0000L3][MapPane](by-file/MapPane.md). It is a MapPane instance method over `m_viewportGrafPort`, `m_tileOriginX`, `m_tileOriginY`, `m_visibleTileColumns`, `m_visibleTileRows`, `m_mapWidth`, and `m_mapHeight`. The modeled `0x00556dee` caller and raw `0x005593e3` xref are ScreenPane caller contexts that pass `g_activeMapPane` as the receiver; they do not move ownership to ScreenPane, SurfacePresentation, Surface, or ParcelPane.

Populate first-draft C++ as `MapPane::RedrawVisibleTiles()`. The helper names `GetClampedVisibleTileBounds` and `DrawTileAt` are source-quality enough for code entry; exact original spelling remains a confidence cap only.
```

### [UID:00007Q] MapPane class

Add this row to the field glossary near the `+0x3f2/+0x3f4/+0x3f6/+0x3f8` row if absent:

```text
| `+0x3fc`, `+0x400` | `m_tileOriginX`, `m_tileOriginY` | high; accepted [UID:0002QM] C++ uses these names, `0x00505130` subtracts them for map-to-screen conversion, `0x00505170` adds them for screen-to-map conversion, and `0x00505290` builds visible tile bounds from them. |
```

Extend the `+0x428` row if desired:

```text
| `+0x428` | `m_viewportGrafPort` | embedded GrafPort-style member; [UID:0001AR] opens/closes its paint lifecycle when redrawing visible tiles. |
```

### [UID:0000L3] MapPane file

In the "MapPane Subsystems" tile/render row, replace the method list with:

```text
| Tile and cached surface rendering | `DrawTileRange`, `RenderMapView`, `DrawVisibleTiles`, `RedrawVisibleTiles`, `DrawTileAt`, `DrawGroundTiles`, `RenderTileWithEffects` | Renders tile layers, static/effect objects, and cached map surfaces. `RedrawVisibleTiles` is the no-clear visible-tile repaint helper at [UID:0001AR], while the existing `DrawVisibleTiles` name remains with the fuller clear-and-draw helper at `0x0050d840`. |
```

### [UID:0001AP] MapPaneWeatherCoordinateObjectCore

Replace the [UID:0001AR] covered-range row with:

```text
| [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) | `MapPane::RedrawVisibleTiles()` / no-clear visible-tile repaint helper | Opens `m_viewportGrafPort`, gets clamped visible tile bounds, calls `DrawTileAt(tileX, tileY, false)` for each loop-exclusive tile coordinate, and closes the paint lifecycle. |
```

Replace the `0x00505290` row with:

```text
| `0x00505290-0x00505304` | `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const` | Builds the current visible tile rectangle from `m_tileOriginX/Y` and visible span fields with one-tile left/top and two-tile right/bottom expansion, clamped to map dimensions. |
```

### [UID:0000NB] ScreenPane file

Replace the stale paragraph that says the owner is still open between ScreenPane, Surface, and shared root render helper with:

```text
The visible-tile repaint helper at [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) is a `MapPane` class method best named `MapPane::RedrawVisibleTiles()`. `ScreenPane::HandleMessage` and raw helper [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) are caller contexts that load `g_activeMapPane`, validate it, call the MapPane method, and then invoke the active pane repaint/update virtual. They do not own the MapPane method.
```

Replace the ScreenPane helper table row with:

```text
| active MapPane visible-tile repaint call | `0x005051c0-0x00505228` | Calls `MapPane::RedrawVisibleTiles()` on `g_activeMapPane`; current ParcelPane ownership is false, and the method owner is [UID:00007Q][MapPane](by-class/MapPane.md). |
```

### [UID:0000CB] ScreenPane class

Replace the visible-tile row with:

```text
| active MapPane visible-tile repaint call | `0x005051c0-0x00505228` | Caller dependency from `HandleMessage`/raw palette bridge into [UID:00007Q][MapPane](by-class/MapPane.md) `RedrawVisibleTiles`; earlier callsite-only `ParcelPane` ownership is false. |
```

### [UID:0000OC] Surface file

Replace the [UID:0001AR] row in the migration review table with:

```text
| [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) | `0x005051c0-0x00505228` | [UID:00007Q][MapPane](by-class/MapPane.md) | `MapPane::RedrawVisibleTiles()` opens/closes the embedded `m_viewportGrafPort` via Surface/GrafPort paint helpers, but its receiver fields and tile loops are MapPane-owned. Surface owns the paint/callback dependencies, not this method. |
```

Replace the stale bullet saying to keep `0x005051c0` in shared render review with:

```text
- `0x005051c0` was formerly emitted under `ParcelPane`, but current docs and B005 source-quality recheck resolve it as [UID:00007Q][MapPane](by-class/MapPane.md) `RedrawVisibleTiles`. Surface remains a dependency owner for `UpdateSurfaceInfo`, `EndPaint`, and render callbacks only.
```

### ParcelPane docs

No mandatory change is required because [UID:0000MF] and [UID:0000A6] already reject the generated ParcelPane owner. If touched, replace "shared render/pane helpers" for `0x005051c0` with "MapPane visible-tile repaint method".

### [UID:0003A2] ScreenPanePaletteVisibleTilesRedrawRaw

Optional single-sentence addition after the `0x005593e3` evidence:

```text
The `0x005593e3` xref remains caller evidence only; [UID:0001AR] is now resolved as [UID:00007Q][MapPane](by-class/MapPane.md) `RedrawVisibleTiles`, while this raw body remains the ScreenPane palette/active-pane/root-update bridge.
```

## Coverage Recommendation

Placement: replace the current [UID:0001AR] row in `by-memory/-coverage-report.md` immediately after the [UID:0001AQ] row and before the `0x0050637a-0x00506380` padding row.

Current row:

```text
    - [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) : reconstructable : 84% : strong : MapPane cached visible-tile redraw helper; opens the cached surface, computes clamped visible bounds, draws each tile with repaint mode `0`, closes the paint lock, and documents active-map repaint callers plus exact padding.
```

Replacement row:

```text
    - [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) 0x005051c0-0x00505228 | method | MapPane::RedrawVisibleTiles : reconstructable : 88% : very strong : B005 2026-06-18 source-quality pass resolves this as a [UID:00007Q][MapPane](by-class/MapPane.md) no-clear visible-tile repaint method emitting through [UID:0000L3][MapPane](by-file/MapPane.md); exact 0x68 modeled range is bracketed by five-byte and eight-byte `0xcc` padding, the body opens `m_viewportGrafPort`, calls `GetClampedVisibleTileBounds`, loops Y/X over loop-exclusive bounds, calls `DrawTileAt(tileX, tileY, false)`, closes paint, resolves `m_tileOriginX/Y`, visible-span, dimension, and GrafPort fields, and treats modeled `0x00556dee` plus raw `0x005593e3` ScreenPane paths as caller context rather than owner evidence.
```

## Heuristic / Inference Reanalysis And Validation

### 1. Exact range and padding

Evidence checked: current target doc, `functions.json`, `memory.bin` dump, next function record `0x00505230`, and by-memory ignored padding entry.

Rejected alternatives: split the target, extend to `0x00505230`, or merge with neighboring coordinate helpers. The function has a modeled `0x68` record, a normal `ret` at `0x00505227`, and eight `0xcc` bytes before the next modeled function. No split/range change is justified.

Effect: score increases for validation, but no range metadata change is recommended.

### 2. Raw xref `0x005593e3`

Evidence checked: local `xrefs.json`, raw bytes `0x005593b0-0x0055940c`, [UID:0003A2], [UID:0001G6], and `ScreenPane::HandleMessage` decompile at `0x00556d50`.

Rejected alternatives: make the target ScreenPane-owned, make it SurfacePresentation-owned, or treat the raw xref as a pointer/table route. The raw helper is not modeled in `functions.json`, but it is real ScreenPane source-shaped caller code; it loads `g_activeMapPane`, validates the pane, calls this method, and repaints through a virtual slot. That is caller context only.

Effect: source placement remains MapPane class; support docs should stop saying the owner is open because of screen/presentation callsites.

### 3. Direct owner/emitter

Evidence checked: target receiver fields, MapPane class field glossary, MapPane aggregate, accepted exact method routes under [UID:00007Q], and support-doc owner rules.

Rejected alternatives: broad file-root direct owner, ScreenPane, Surface, ParcelPane, shared render helper, no-owner. The method has a `this` receiver and uses MapPane-specific fields. The file root is the module, not the narrow direct owner.

Effect: recommend `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q`, with source module [UID:0000L3]. This is the main metadata correction.

### 4. Source-facing method name

Evidence checked: target behavior, sibling `0x0050d840` decompile, accepted [UID:0002QM] C++ call to `DrawVisibleTiles()`, MapPane file method-family list, and generated-owner pollution notes.

Rejected alternatives: `DrawVisibleTiles` for this target, `DrawParcelSlot`, `DrawTileRange`, Surface/GrafPort names. `0x0050d840` is the stronger existing `DrawVisibleTiles` candidate because it clears/fills the cached surface before drawing and is called from recenter/render/map-change paths. This target is called from ScreenPane palette/repaint paths and performs the same tile loop without the clear/fill prologue.

Best inference: `MapPane::RedrawVisibleTiles()` is source-facing enough for first-draft C++. `DrawVisibleTilesNoClear` is more descriptive but less likely as original mid-2000s naming. The unresolved exact spelling affects confidence only, not owner, split, or C++ readiness.

### 5. Bounds helper name and shape

Evidence checked: decompiles `0x00505290`, `0x00505310`, `0x00505370`, MapPane aggregate role table, accepted [UID:0002QM] C++.

Rejected alternatives: leave as `sub_505290`, treat as generic RECT helper, or name all bounds helpers identically. `0x00505290` specifically clamps to map dimensions; `0x00505310` omits clipping; `0x00505370` extends bottom farther for object/update scanning.

Best inference: `MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const`. If the support docs need shorter spelling, `GetVisibleTileBounds` is acceptable, but the report should record the clamped semantics.

Effect: removes a formal C++ blocker and supports `88/90`.

### 6. Tile renderer name and mode flag

Evidence checked: decompile `0x0050d8e0`, xrefs/callees for `0x0050d8e0`, `g_pMapTileImageLib` docs, MapPane legacy remap constants, old integration/source-quality docs.

Rejected alternatives: generated IDA name, Surface renderer ownership, MapTileImageLib ownership. `0x0050d8e0` is a MapPane method that validates tile coordinates, reads tile ids, draws through MapTileImageLib, and uses the fourth argument to decide whether to begin/end paint internally.

Best inference: `MapPane::DrawTileAt(int tileX, int tileY, bool beginPaint)`. The target passes `false`.

Effect: removes tile-renderer name blocker and clarifies why the target owns the outer paint lifecycle.

### 7. Field names

Evidence checked: accepted [UID:0002QM] C++ and source-quality notes, MapPane class glossary, decompiles for map/screen conversion and bounds helpers.

Rejected alternatives: generic viewport-origin names, ScreenPane fields, Surface fields, ParcelPane fields. The coordinate helpers prove tile-space origin behavior for `+0x3fc/+0x400`; accepted MapPane docs already use `m_tileOriginX/Y`.

Best inference: use `m_mapWidth`, `m_mapHeight`, `m_tileOriginX`, `m_tileOriginY`, `m_visibleTileColumns`, `m_visibleTileRows`, and `m_viewportGrafPort`.

Effect: field/type issues are no longer blockers. Support docs should add `m_tileOriginX/Y` to the MapPane class glossary if still absent there.

### 8. First-draft C++ readiness

Evidence checked: all above plus code-entry gate policy from Supervisor/B-agent instructions.

Rejected alternatives: keep formal C++ blank because helper names are inferred, or mark non-reconstructable/coverage-only. The method has exact bytes, precise callees, fully resolved field roles, a narrow owner, and a straightforward structured body. Inferred but stable source names are allowed at this gate.

Best inference: populate first-draft C++ on the target. The only cap is original spelling of the no-clear helper and future Surface/GrafPort helper spelling.

Effect: raises target to `88/90`, preserves reconstructable/emitting state, and makes the target no longer a low-score B-preferred row.

### 9. Support-doc stale ownership language

Evidence checked: `ScreenPane.md`, `ScreenPane` class doc, `Surface.md`, `SurfacePresentation`, `ScreenPanePaletteVisibleTilesRedrawRaw`, ParcelPane file/class, MapPane file/class/aggregate.

Rejected alternatives: leave stale "owner open" language because the helper has screen/presentation callers. The current evidence is strong enough to close the route: the callers are ScreenPane-owned wrappers, while the target is MapPane-owned.

Effect: recommend exact support-doc replacement text above. No generated file or supervisor-owned coverage was edited directly.

## Validation Notes

Commands/results used for validation:

- Local target decompile: `0x005051c0.json` shows `this+0x428`, calls `0x004b9820`, `0x00505290`, `0x0050d8e0(..., 0)`, and `0x004b98c0`.
- Local bounds decompile: `0x00505290.json` shows left/top expansion and dimension clamps.
- Local renderer decompile: `0x0050d8e0.json` shows `beginPaint` flag behavior and MapTileImageLib draw dependency.
- Local caller decompile: `0x00556d50.json` shows `g_activeMapPane` load, validation, call at `0x00556dee`, and vtable slot `+0x20` repaint/update call.
- Local memory/function/xref script confirmed prepadding, target bytes, postpadding, function records, modeled caller, raw xref, and no data refs in the target xref record.
- `rg` support-doc checks found stale open-owner language in `ScreenPane.md` and `Surface.md`, while ParcelPane docs already reject generated ParcelPane ownership.

No repository validators were run because only this report file was created and no by-* docs were edited.

## Changed Files

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\0001AR-DrawVisibleTilesHelper-source-quality.md`

No other files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001AR-DrawVisibleTilesHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001AR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
