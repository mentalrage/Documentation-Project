** TARGET-REPORT-UID:0000E2 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 source-quality report: [UID:0000E2] StaticObjImageLib

Status: FINISHED report-only. No target/support by-* documentation was edited. `by-memory/-coverage-report.md` was not edited.

## Target And Report Paths

- Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\StaticObjImageLib.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0000E2-StaticObjImageLib-class-source-quality.md`
- Source file parent: [UID:0000O7] `source-3/project-documentation/by-file/StaticObjImageLib.md`
- Principal executable/memory support:
  - [UID:00017H] `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`
  - [UID:00017I] `by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md`
  - [UID:00017J] `by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md`
  - [UID:000184] `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`
  - [UID:0003M2] `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md`
  - [UID:0002OY] `by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md`
  - [UID:0001PP] `by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md`

## Finalized Report / Current Recommendation

Keep [UID:0000E2] source-bearing and emitting through [UID:0000O7] `NexusTK/render/StaticObjImageLib.cpp`. This is not a no-code class page. It should receive declaration-level first-draft C++ and a modest score raise.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000O7
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O7
```

The class page is the right owner for class layout, vtable, ordinary destructor, scalar deleting wrapper, renderer, bounds/pixel/lookup methods, and the resource-derived structs. The file page remains the source root. `StaticObjectPane`, `PhotoPane`, `MapPane`, and `ObjectList` are consumers or caller contexts, not owners of this image-library class.

The most important implementation fixes are:

- Add declaration-level C++ to [UID:0000E2].
- Route [UID:00017J] `RenderStaticObject` directly through class owner/emitter `0000E2`, not directly through file `0000O7`, and populate a first-draft method body in that exact memory page if the supervisor includes it in the callback.
- Keep [UID:00017I] ordinary destructor class-owned with its existing first-draft C++.
- Keep [UID:0003M2] scalar deleting destructor class-owned but formal C++ blank; it is compiler ABI glue regenerated from the virtual destructor.
- Keep [UID:000184] singleton clear helper file-owned and formal C++ blank; it is constructor/static cleanup glue, not a public helper API.
- Refresh stale coverage text: current `by-memory/-coverage-report.md` still shows [UID:00017H] as `0x004dcf60-0x004e6aa6` and reconstructable even though the page is now the non-emitting local cluster `0x004dcf60-0x004ddf60`, and the report lacks a live [UID:0003M2] scalar destructor row.

## Evidence Checked

Required workflow and rules:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/goal.md`, including the Implementation Callback Detail Contract

Target/support docs:

- `by-class/StaticObjImageLib.md`
- `by-file/StaticObjImageLib.md`
- `by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md`
- `by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md`
- `by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md`
- `by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md`
- `by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md`
- `by-memory/0x0061b700-0x0061b710.StaticObjImageLibVtableData.md`
- `by-global/g_pStaticObjImageLib.md`
- `by-type/by-vtable/StaticObjImageLibVtable.md`
- `by-type/by-struct/StaticObjImageLibLayout.md`
- `by-type/by-struct/StaticObjEntry.md`
- `by-type/by-struct/TileClassEntry.md`
- `by-resource/sobj-tbl.md`
- `by-item/BuildTilecArchiveTable_004DDA60.md`
- `by-file/StaticObjectPane.md`
- `by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md`
- `by-file/PhotoPane.md`
- `by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md`
- `by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md`
- `by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md`
- `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`
- `by-project-structure/proposed-source-tree.md`
- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/render/StaticObjImageLib.cpp`
- `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- `source-3/simroot_v2/class_StaticObjImageLib.cpp.source_map.json`
- `source-3/simroot_v2/class_StaticObjImageLib.meta_wave3`

Prior accepted reports checked as leads and revalidated against current docs:

- `tools/leaser/Agents/Agent-B003/research/executed/000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`
- `tools/leaser/Agents/Agent-B001/research/executed/older/0003M2-StaticObjImageLibScalarDeletingDestructor.md`

Export/local binary checks:

- `resources/exported_data/master_function_list.json`
- `resources/exported_data/master_globals.json`
- `resources/exported_data/master_vtables.json`
- `resources/exported_data/master_structs.json`
- `resources/exported_data/master_names.json`
- `resources/ooAnalyzerData.json`
- Read-only PE byte check against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

Current-session IDA MCP status:

- `tool_search` for IDA/MCP tools returned no callable tools in this session.
- No IDA DB writes or live renames were attempted.
- This report distinguishes current local PE/export checks from existing saved live-IDA evidence in the docs.

Current-session PE check results:

```text
0x004dcf60: 55 8b ec 6a ff 68 b2 ff 5f 00 64 a1 00 00 00 00
0x004dd1e0: 55 8b ec 6a ff 68 cd ff 5f 00 64 a1 00 00 00 00
0x004dd2c0: 55 8b ec 6a ff 68 f3 ff 5f 00 64 a1 00 00 00 00
0x004dd850: 55 8b ec 66 8b 45 08 33 d2 66 3b d0 73 3f 0f b7
0x004dd8b0: 55 8b ec 83 ec 44 a1 24 2f 67 00 33 c5 89 45 fc
0x004dda30: 55 8b ec 66 8b 45 08 33 d2 66 3b d0 73 13 0f b7
0x004dda60: 55 8b ec 6a ff 68 31 00 60 00 64 a1 00 00 00 00
0x004dde10: 55 8b ec 6a ff 68 61 00 60 00 64 a1 00 00 00 00
0x004e5c00: c7 05 48 b4 69 00 00 00 00 00 c3 cc cc cc cc cc
0x004e6990: 55 8b ec 6a ff 68 a0 04 60 00 64 a1 00 00 00 00
0x0061b700 -> 0x00648d54
0x0061b704 -> 0x004e6990
0x0061b708 -> 0x004f4b10
0x0061b70c -> 0x0041b6c0
0x0061b710 -> 0x00648e94
```

`0x0069b448` did not map cleanly through the simple raw-file dword reader because that data slot is not reliably present in the raw file span used by the one-off script. Existing exact storage docs and saved IDA xrefs remain the evidence source for the singleton value and 13 xrefs.

## Heuristic / Inference Reanalysis And Validation

### Source Placement And Ownership

Best route:

```text
StaticObjImageLib class [UID:0000E2]
  emits through StaticObjImageLib file [UID:0000O7]
  projected source path NexusTK/render/StaticObjImageLib.cpp
```

Evidence for this route:

- The class page, file page, layout, vtable, global, local cluster, and resource docs all agree that the source unit owns `SOBJ.TBL` render metadata, `TILEC` frame/class resources, `g_pStaticObjImageLib`, the vtable at `0x0061b704`, and the constructor/destructor/render/bounds/helper family.
- Exported RTTI includes `??_7StaticObjImageLib@@6B@`, `??_R4StaticObjImageLib@@6B@`, and `Singleton<StaticObjImageLib>` RTTI records around `0x00648da4-0x00648dd8`.
- The source tree keeps this as a distinct `render/StaticObjImageLib.cpp`, adjacent to but not merged with `MapTileImageLib.cpp`, `EffectObjImageLib.cpp`, or generic image loaders.
- `StaticObjectPane` and `PhotoPane` each call into the image library. They do not own its asset tables, vtable, singleton, or frame/class resource parsers.
- `MapPane` and `ObjectList` consume metadata and construct/update live object panes. They do not own the renderer or static-object resource tables.

Rejected alternatives:

- Direct file owner for every method: too broad for class methods. Use the class as direct owner for the renderer, ordinary destructor, scalar wrapper, vtable, and structs; the file is the downstream source root.
- `StaticObjectPane` owner: rejected because it stores a static-object id and delegates bounds/render/hit-test to `g_pStaticObjImageLib`.
- `PhotoPane` owner: rejected because map-photo composition is only the second renderer caller.
- Generic `ImageLib` or shared EPF owner: rejected because `SOBJ.TBL`, `TILEC.TBL/TBD`, and `TILEC%d.EPF` are static-object-specific; only some low-level archive/palette helpers are shared.
- No-code class page: rejected. The class declaration, fields, resource-derived structs, and source method inventory are source-bearing even though some compiler ABI artifacts stay blank.

### Final Field Names

Recommended class layout names:

```cpp
ArchiveMetadataTable *tileCatalog;      // +0x04
TileClassEntry *tileClasses;            // +0x08
StaticObjEntry **staticObjEntries;      // +0x0c
int staticObjCount;                     // +0x10
```

These are strong source-facing documentation names. They are still descriptive inferences, not proven original identifiers, so confidence should remain below final-audit levels.

Recommended `StaticObjEntry` source-facing layout:

```cpp
struct StaticObjEntry {
    int lightIntensity;                 // +0x00, negative disables attached light
    unsigned char lightHeightClass;     // +0x04, used for light vertical placement
    unsigned char layerCount;           // +0x05, copied from SOBJ record count byte
    unsigned short reserved;            // +0x06, zeroed in memory
    StaticObjEntry *cacheChain;         // +0x08, destructor-only cache/duplicate chain
    unsigned short tileIds[1];          // +0x0c, variable-length layer tile ids
};
```

Evidence:

- Constructor/docs allocate `0x0c + 2 * layerCount`, store dword at `+0x00`, source byte at `+0x04`, layer count at `+0x05`, zero word at `+0x06`, zero pointer at `+0x08`, and copy tile ids at `+0x0c`.
- Renderer and bounds use `+0x05` as layer count and walk tile ids in reverse from `+0x0c`.
- Destructor follows `+0x08` as the optional cache chain and frees the chain separately.
- ObjectList static-object lighting sync calls `StaticObjImageLib::GetStaticObjectEntry`, tests metadata `+0x00` as signed, passes it to `LightingObjectPane::SetIntensity` / constructor, and uses metadata byte `+0x04` in `tileHeight / 2 - tileHeight * metadata[4]` placement.

Rejected field names:

- `objectId` for `+0x00`: rejected as the primary source name. The record index / caller-supplied `staticObjectId` is the object id; the dword field is consumed as lighting/intensity-like metadata, with negative values disabling lights.
- `paletteGroup` for `+0x04`: rejected as primary. No current renderer evidence uses it for palette selection; the strongest executable consumer uses it as vertical/height placement for lighting. Keep `paletteGroup` only as a stale/generated lead in history.
- `nameLength` for the count byte: rejected. The byte copied into in-memory `+0x05` is layer/tile-id count, not a wide-name length.
- Generic `next` for `+0x08`: too broad. `cacheChain` is the best current name because the destructor treats it as an optional per-entry cache/duplicate chain rather than the main table link.

Recommended `TileClassEntry` source-facing layout:

```cpp
struct TileClassEntry {
    unsigned short tileFrameId;          // +0x00, low 15 bits of TILEC row
    unsigned char allowPaletteFilter;    // +0x02, high-bit flag from TILEC row
    unsigned char reserved;              // +0x03
};
```

Evidence:

- Constructor reads signed/encoded 16-bit `TILEC.TBL`/`TILEC.TBD` rows, stores `value & 0x7fff` at `+0x00`, and stores whether the high bit was set at `+0x02`.
- Renderer indexes `tileClasses + 4 * tileId`, reads the word at `+0x00` for frame/palette lookup, and skips the draw under the palette-filter predicate when byte `+0x02` is clear.

Rejected/alternate names:

- `paletteRemapFlag` is an acceptable documentation alias but less directly tied to the branch than `allowPaletteFilter`.
- `highBitSet` is mechanically correct but not source-quality enough.

### Resource Split

Keep one shared resource doc for `SOBJ.TBL`, but document the split parser roles:

- `StaticObjImageLib` owns the full render/lighting metadata view: `lightIntensity`, `lightHeightClass`, `layerCount`, and `tileIds`.
- `MapPane` / `GameServerConfig` owns the compact `g_objectNationMap` classification cache view over the same payload.
- Do not split `SOBJ.TBL` into render and gameplay resources; package parsing already found one current DAT entry in `tile.dat`.

Keep `TILEC` under `StaticObjImageLib`:

- Modern branch: `TILEC.EPF` / `TILEC%d.EPF` archive metadata through `BuildTilecArchiveTable`, plus `TILEC.TBL` tile-class rows.
- Legacy branch: `TILEC.EPD` frame table through `LoadImageFrameTable_004D0F50`, plus `TILEC.TBD` tile-class rows.
- `TILEC.PAL` is a PaletteLib resource / slot context dependency, not a field owned by `StaticObjImageLib` itself.

### Method And Helper Inventory

Recommended source-facing inventory:

| Address | Recommendation | Owner/emitter | C++ disposition |
| --- | --- | --- | --- |
| `0x004dcf60` | `StaticObjImageLib::StaticObjImageLib()` | class `0000E2` | source-authored; future exact constructor child should emit method body |
| `0x004dd1e0` | `StaticObjImageLib::~StaticObjImageLib()` | class `0000E2` | already emits first-draft C++ |
| `0x004dd2c0` | `StaticObjImageLib::RenderStaticObject(...)` | change from file `0000O7` to class `0000E2` | source-authored; should emit first-draft method C++ |
| `0x004dd850` | `StaticObjImageLib::GetStaticObjectBounds(uint16 staticObjectId, Rect *outBounds)` | class `0000E2` | source-authored; create/update exact child if supervisor broadens scope |
| `0x004dd8b0` | `StaticObjImageLib::HitTestStaticObjectPixel(uint16 staticObjectId, int localX, int localY)` | class `0000E2` | source-authored; exact child not yet split |
| `0x004dda30` | `StaticObjImageLib::GetStaticObjectEntry(uint16 staticObjectId)` | class `0000E2` | source-authored tiny accessor; exact child not yet split |
| `0x004dda60` | `BuildTilecArchiveTable(const wchar_t *baseName)` | file `0000O7` | file-local source helper; saved name is good |
| `0x004dde10` | `StaticObjImageLib::LoadStaticObjectRecords()` or `LoadStaticObjectRecordsFromTable()` | class/file context `0000E2` / `0000O7` | source-like retained loader; no direct xref, so keep as local-cluster evidence until exact child review |
| `0x004e5c00` | `StaticObjImageLib` singleton clear helper | file `0000O7` | compiler/static cleanup glue; C++ blank |
| `0x004e6990` | `StaticObjImageLib` scalar deleting destructor | class `0000E2` | compiler-generated ABI wrapper; C++ blank |

### RenderStaticObject Emitted-Source Omission

Current state:

- [UID:00017J] is reconstructable `86/88`, but owner/emitter are still file `0000O7` and formal C++ is blank.
- Current `auto-generated/NexusTK/render/StaticObjImageLib.cpp` emits only [UID:00017I] ordinary destructor and empty emitter markers for class, scalar wrapper, structs, vtable/global/item support, [UID:00017J], and [UID:000184].
- The older `source-3/simroot_v2/class_StaticObjImageLib.cpp` includes constructor, `RenderStaticObject`, `GetStaticObjectBounds`, and scalar-deleting destructor source leads, but its source map uses stale inclusive/last-byte range ends and unresolved/global names. Treat it as a source lead, not authority.

Recommendation:

- Update [UID:00017J] direct owner/emitter to `0000E2`.
- Raise [UID:00017J] to `88/89` after adding class-owner route, final field names, and first-draft body guidance.
- Populate [UID:00017J] formal C++ in an implementation callback if the supervisor includes that support page. The current blockers are polish names for callback/globals, not source/no-code blockers.
- Keep class [UID:0000E2] declaration-level C++ separate from [UID:00017J] method-body C++; do not paste the huge renderer body into the class page.

Recommended source-facing signature:

```cpp
bool StaticObjImageLib::RenderStaticObject(
    GrafPort *target,
    StaticObjectDrawRequest *request,
    unsigned short staticObjectId,
    void *overlayBuffer,
    float overlayAlpha,
    bool enableBlendClip);
```

Signature uncertainty:

- `GrafPort *target` is inferred from render callback and caller shape; if the target type remains too strong, use `RenderSurface *target`.
- `StaticObjectDrawRequest *request` is inferred from `targetRect` / draw request use in docs. It should not stay as raw `int *drawRequest`.
- The two callers are `StaticObjectPane::RenderStaticObjectForTarget` and `PhotoPane` map-photo composition. The first caller passes no overlay buffer, `0.0f`, and final flag true.

Method-body source sketch for [UID:00017J], not for the class page:

```cpp
bool StaticObjImageLib::RenderStaticObject(
    GrafPort *target,
    StaticObjectDrawRequest *request,
    unsigned short staticObjectId,
    void *overlayBuffer,
    float overlayAlpha,
    bool enableBlendClip)
{
    if (g_staticObjectDrawSuspended)
        return false;

    EPFTileContext tileContext;
    tileContext.InitTileContext();

    unsigned short resolvedObjectId = staticObjectId;
    if (!g_useEpfAssets) {
        unsigned int tileClassCount = ReadTileClassCount(L"TILEC.TBD");
        if (resolvedObjectId >= tileClassCount)
            resolvedObjectId = 0;
    }

    if (resolvedObjectId == 0 || resolvedObjectId >= staticObjCount)
        return false;

    StaticObjEntry *entry = staticObjEntries[resolvedObjectId - 1];
    if (entry == 0)
        return false;

    Rect primaryClip;
    Rect secondaryClip;
    BuildStaticObjectBlendClipState(enableBlendClip, &primaryClip, &secondaryClip);

    Rect objectBounds;
    Rect_Set(&objectBounds,
             request->left,
             request->top,
             request->left + g_mapTilePixelWidth,
             request->top + entry->layerCount * g_mapTilePixelHeight);

    bool translatedClip =
        ShouldUseStaticObjectTranslatedClip(primaryClip, objectBounds, resolvedObjectId);

    int drawTop = request->top;
    for (int layerIndex = entry->layerCount - 1; layerIndex >= 0; --layerIndex) {
        unsigned short tileId = entry->tileIds[layerIndex];
        if (tileId != 0) {
            LoadFrameDrawRecord(tileCatalog, tileId, &tileContext);

            if (tileContext.pixelData != 0) {
                Rect drawRect = tileContext.bounds;
                Rect_Offset(&drawRect, request->left, drawTop);

                TileClassEntry &tileClass = tileClasses[tileId];
                if (!g_pPaletteLib->IsPaletteFilterEnabled() || tileClass.allowPaletteFilter) {
                    void *palette = g_pPaletteLib->GetSlotPalette(1, tileClass.tileFrameId, 0);
                    DrawStaticObjectTileWithOptionalHighlight(
                        target,
                        &tileContext,
                        drawRect,
                        palette,
                        translatedClip,
                        secondaryClip);
                }

                if (overlayBuffer != 0) {
                    int intensity = (int)(overlayAlpha * 32.0f + 0.5f);
                    DrawEncodedAlphaFrame(overlayBuffer,
                                          &drawRect,
                                          &tileContext,
                                          &tileContext.bounds,
                                          request->bottom,
                                          intensity,
                                          request->top,
                                          0,
                                          1);
                }
            }
        }

        drawTop += g_mapTilePixelHeight;
    }

    return true;
}
```

This is intentionally first-draft. It avoids raw global names (`dword_67A748`, `dword_67A7C8`, `dword_69B3E8`) and keeps highlight/translated-clip helpers descriptive until the shared render state gets its own naming pass.

### Destructor / Singleton / Scalar Wrapper Policy

- Ordinary destructor [UID:00017I]: source-authored class destructor. Current first-draft C++ is appropriate and should remain class-owned.
- Scalar deleting destructor [UID:0003M2]: class-owned compiler wrapper. Keep formal C++ blank because the source declaration `virtual ~StaticObjImageLib();` plus ordinary destructor should regenerate it.
- Singleton clear helper [UID:000184]: file-owned static cleanup / constructor unwind glue. Keep formal C++ blank; the helper only writes `g_pStaticObjImageLib = 0` and has no `this`, no resource cleanup, and no public API shape.
- Vtable data [UID:0002OY]: compiler-emitted data. Keep formal C++ blank and regenerate from class declaration.

### Open Questions Closed Or Bounded

- Final original field spellings: not source-proven. Best descriptive names are now strong enough for declaration-level C++ and first-draft method C++, but cap confidence below 90.
- `StaticObjEntry +0x00/+0x04`: resolved to lighting intensity and light-height/vertical class for source-facing use, with old `objectId`/`paletteGroup` names retained only as rejected/generated alternatives.
- `RenderStaticObject` C++ blocker: not a no-code blocker. It is source-authored renderer code with two callers; only helper/global polish remains.
- `BuildTilecArchiveTable` owner: keep file-local `StaticObjImageLib.cpp`, not shared EPFImageResources, unless a future common-loader refactor proves a shared source owner.
- `LoadStaticObjectRecords` at `0x004dde10`: source-like retained loader with no current xrefs. Keep in the local cluster and recommend exact child review later rather than forcing it into the class declaration as a public method.
- Current `by-memory/-coverage-report.md` broad row for [UID:00017H]: stale and should be replaced in supervisor-owned coverage updates.

## First-Draft C++ Recommendation

Because this is a by-class page, formal C++ should be declaration-level. Method bodies belong in the exact by-memory pages.

Recommended declaration-level C++ for `by-class/StaticObjImageLib.md`:

```cpp
struct ArchiveMetadataTable;
struct Rect;
struct GrafPort;
struct StaticObjectDrawRequest;

struct TileClassEntry {
    unsigned short tileFrameId;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

struct StaticObjEntry {
    int lightIntensity;
    unsigned char lightHeightClass;
    unsigned char layerCount;
    unsigned short reserved;
    StaticObjEntry *cacheChain;
    unsigned short tileIds[1];
};

class StaticObjImageLib : public LObject {
public:
    StaticObjImageLib();
    virtual ~StaticObjImageLib();

    bool RenderStaticObject(GrafPort *target,
                            StaticObjectDrawRequest *request,
                            unsigned short staticObjectId,
                            void *overlayBuffer,
                            float overlayAlpha,
                            bool enableBlendClip);
    void GetStaticObjectBounds(unsigned short staticObjectId, Rect *outBounds) const;
    bool HitTestStaticObjectPixel(unsigned short staticObjectId,
                                  int localX,
                                  int localY) const;
    StaticObjEntry *GetStaticObjectEntry(unsigned short staticObjectId) const;

private:
    ArchiveMetadataTable *tileCatalog;
    TileClassEntry *tileClasses;
    StaticObjEntry **staticObjEntries;
    int staticObjCount;
};

extern StaticObjImageLib *g_pStaticObjImageLib;
```

Implementation notes:

- Do not put explicit vtable stores, SEH state, security cookies, scalar-delete flags, or base destructor calls in the class C++ block.
- Keep `BuildTilecArchiveTable` as a file-local helper outside the class declaration unless the implementation callback chooses to add private helper declarations.
- If exact method pages are updated in the same callback, put method-body C++ in those pages, not in the class page.

## Recommended Target / Support Doc Changes

### Target [UID:0000E2] `by-class/StaticObjImageLib.md`

Apply:

- Raise to `88/89`.
- Populate declaration-level C++ from this report.
- Replace "medium for final field names" with "strong for descriptive source-facing names, below final original-spelling proof."
- Add `StaticObjEntry` source field conclusions: `lightIntensity`, `lightHeightClass`, `layerCount`, `reserved`, `cacheChain`, `tileIds`.
- Add `TileClassEntry` source field conclusions: `tileFrameId`, `allowPaletteFilter`, `reserved`.
- Update generated-output caveat: current `auto-generated/NexusTK/render/StaticObjImageLib.cpp` emits only ordinary destructor plus empty markers; older simroot contains useful constructor/render/bounds/scalar source leads but has stale range ends and raw/global names.
- Add that [UID:00017J] should route through class owner/emitter and receive first-draft method C++ once accepted.
- Preserve no-code policy for [UID:0003M2] and [UID:000184].
- Preserve rejected alternatives and negative evidence from this report.

### [UID:0000O7] `by-file/StaticObjImageLib.md`

Apply:

- Keep proposed path `NexusTK/render/StaticObjImageLib.cpp`.
- Add a short B007 support note that the class page now has declaration-level C++ readiness and `RenderStaticObject` should be class-owned, while file-local `BuildTilecArchiveTable` and singleton-clear cleanup glue remain file-owned.
- Update any "field names still block C++" wording to "field names are inferred/descriptive and cap confidence, but do not block first-draft declaration/method C++."

### [UID:00017J] `RenderStaticObject`

Apply if included in the callback:

- Change `CANONICAL_OWNER` from `0000O7` to `0000E2`.
- Change `EMITTER_UIDS` from `0000O7` to `0000E2`.
- Raise to `88/89`.
- Add first-draft method-body C++ or method-body source sketch using the names in this report.
- Replace raw argument names with `target`, `request`, `staticObjectId`, `overlayBuffer`, `overlayAlpha`, and `enableBlendClip`.
- Add `TileClassEntry::allowPaletteFilter` / `tileFrameId` and `StaticObjEntry::layerCount` / `tileIds`.
- Keep the helper/global names for highlight translated-clip state descriptive until their owner docs resolve them.

### [UID:00017H] Local Cluster

Apply:

- Keep `RECONSTRUCTABLE:FALSE` and direct owner `NONE`.
- Ensure text and coverage use exact range `0x004dcf60-0x004ddf60`, not stale `0x004dcf60-0x004e6aa6`.
- Add B007 field/name conclusions and point to [UID:0003M2] as a separate exact tail page.

### [UID:0001W9] `StaticObjImageLibLayout`

Apply:

- Keep the four field names `tileCatalog`, `tileClasses`, `staticObjEntries`, and `staticObjCount`.
- Add that these names are now source-quality descriptive names for first-draft C++.

### [UID:0001W8] `StaticObjEntry`

Apply:

- Rename/reframe fields to:
  - `+0x00 int32 lightIntensity`
  - `+0x04 uint8 lightHeightClass`
  - `+0x05 uint8 layerCount`
  - `+0x06 uint16 reserved`
  - `+0x08 StaticObjEntry *cacheChain`
  - `+0x0c uint16 tileIds[layerCount]`
- Keep old `objectId`, `paletteGroup`, and `nameLength` as rejected/historical labels, not current source names.
- Add ObjectList lighting sync evidence as the reason for `lightIntensity` and `lightHeightClass`.

### [UID:0001WC] `TileClassEntry`

Apply:

- Prefer `allowPaletteFilter` over `paletteRemapFlag` / `highBitSet`.
- Keep `tileFrameId` and `reserved`.
- Add renderer branch evidence: palette filter enabled plus clear flag skips draw/remap.

### [UID:0001RL] `sobj-tbl`

Apply:

- Update the `StaticObjImageLib` view field names to match this report:
  - dword -> `lightIntensity` / signed light metadata
  - first byte -> `lightHeightClass`
  - second byte -> discarded/classification byte in the full render loader
  - third byte -> `layerCount`
  - counted words -> `tileIds`
- Keep the two-parser model and the current package provenance.

### [UID:000184] Singleton Clear Helper

Apply:

- Optional wording cleanup: source form is static cleanup / constructor unwind glue with blank formal C++, not "blank until final helper spelling." The spelling is not the blocker; source form is.

### [UID:0003M2] Scalar Deleting Destructor

Apply:

- No metadata change required from current page.
- Optional wording cleanup: this is class-owned generated-binary ABI glue; formal C++ remains blank because `virtual ~StaticObjImageLib()` regenerates it.

## Exact Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` directly as B007. If the supervisor accepts this report, use the following exact rows.

`by-class/-coverage-report.md` replacement row:

```markdown
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) : reconstructable : 88% : very strong : B007 source-quality pass resolves StaticObjImageLib as source-bearing render image-library class under [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), with declaration-level C++ readiness, final descriptive fields `tileCatalog`, `tileClasses`, `staticObjEntries`, `staticObjCount`, `StaticObjEntry` lighting/layer/cache-chain layout (`lightIntensity`, `lightHeightClass`, `layerCount`, `cacheChain`, `tileIds`), `TileClassEntry` layout (`tileFrameId`, `allowPaletteFilter`, `reserved`), `SOBJ.TBL` full metadata versus MapPane classification split, `TILEC` modern/legacy resource split, `RenderStaticObject` class-owner/method-C++ readiness, ordinary destructor C++, scalar deleting destructor no-code compiler wrapper policy, singleton-clear no-code cleanup-glue policy, vtable/singleton evidence, and StaticObjectPane/PhotoPane consumer boundaries.
```

`by-memory/-coverage-report.md` replacement row for [UID:00017H]:

```markdown
    - [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) 0x004dcf60-0x004ddf60 | class-method-cluster | StaticObjImageLib local method cluster : not_reconstructable : 86% : very strong : Non-emitting StaticObjImageLib local cluster ending before EffectObjImageLib, with constructor, ordinary destructor child, renderer child, bounds helper, pixel hit-test helper, entry lookup helper, file-local `BuildTilecArchiveTable`, retained `LoadStaticObjectRecords` body, singleton/vtable/resource evidence, B007 source-quality field names for `StaticObjEntry` and `TileClassEntry`, separated singleton-clear helper [UID:000184] and scalar deleting destructor [UID:0003M2], and exact range correction away from the stale broad `0x004dcf60-0x004e6aa6` coverage row.
```

`by-memory/-coverage-report.md` replacement row for [UID:00017J]:

```markdown
    - [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md) 0x004dd2c0-0x004dd84a | method | StaticObjImageLib::RenderStaticObject : reconstructable : 88% : very strong : B007 source-quality pass reroutes the renderer from direct file ownership to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), confirms the two caller set (`StaticObjectPane` and `PhotoPane`), corrected exclusive end, layered reverse tile-id walk through `StaticObjEntry::tileIds`, `layerCount` bounds, `TileClassEntry::tileFrameId` and `allowPaletteFilter`, modern/legacy `TILEC.TBD` clamp path, PaletteLib slot-1 palette selection, surface render callback and optional alpha overlay, translated/highlight clip globals as unresolved shared render-state names, and first-draft method-body C++ readiness.
```

`by-memory/-coverage-report.md` insertion row for missing [UID:0003M2], placed after the singleton/helper image-library tail section and before the padding row `0x004e6aa6-0x004e6ab0`:

```markdown
    - [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md) 0x004e6990-0x004e6aa6 | scalar-deleting-destructor | StaticObjImageLib scalar deleting destructor : reconstructable : 85% : strong : Exact class-owned compiler scalar deleting destructor for [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), with vtable slot `0x0061b704 -> 0x004e6990`, constructor/destructor/scalar vptr refs, ordinary-destructor cleanup parity for `staticObjEntries`, `StaticObjEntry::cacheChain`, `tileCatalog`, and `tileClasses`, `g_pStaticObjImageLib` clear, base cleanup, delete-flag branch, guard path, exact padding before AUTOBUF helper code, emitter `0000E2`, and formal C++ intentionally blank because the virtual destructor declaration should regenerate this ABI wrapper.
```

If the supervisor also refreshes the already-present [UID:000184] row, use this wording:

```markdown
    - [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md) 0x004e5c00-0x004e5c0b | static cleanup helper | StaticObjImageLib singleton clear helper : reconstructable : 85% : strong : Exact `0xb` file-level constructor/static cleanup helper for [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md); local PE bytes `c7 05 48 b4 69 00 00 00 00 00 c3`, no `this`, no callees, no public API shape, clears only `g_pStaticObjImageLib`, participates in constructor/destructor/scalar/shutdown/consumer lifecycle xrefs, and formal C++ intentionally blank because source lifetime/unwind code should generate this helper.
```

## Validator Needs

Report-only pass validation:

- No write/apply validators were run because this assignment explicitly forbids by-* edits before supervisor review.
- `git status --short` returned `fatal: not a git repository`, matching prior B-agent environment behavior for this workspace root.

Implementation callback should run these scoped validators after edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000E2-StaticObjImageLib-class-source-quality-removed.md](0000E2-StaticObjImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies memory coverage rows, validate separately:

> Executable block R002 was removed from this report and preserved verbatim in [0000E2-StaticObjImageLib-class-source-quality-removed.md](0000E2-StaticObjImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Live IDA validation desired when MCP returns:

- `lookup_funcs` for `0x004dcf60`, `0x004dd1e0`, `0x004dd2c0`, `0x004dd850`, `0x004dd8b0`, `0x004dda30`, `0x004dda60`, `0x004dde10`, `0x004e5c00`, `0x004e6990`.
- `xrefs_to 0x004dd2c0`, `xrefs_to 0x004dd850`, `xrefs_to 0x004dd8b0`, `xrefs_to 0x004dda30`, `xrefs_to 0x004dda60`, `xrefs_to 0x0061b704`, `xrefs_to 0x0069b448`.
- `decompile 0x004dd2c0`, `decompile 0x00530d00`, and `decompile 0x004dcf60` to reconfirm `StaticObjEntry +0x00/+0x04/+0x05/+0x08` naming.
- `get_bytes 0x004dd1d8`, `get_bytes 0x004dd2be`, `get_bytes 0x004dd84a`, `get_bytes 0x004ddf5e`, `get_bytes 0x004e5c00`, and `get_bytes 0x004e6990` for padding/range verification.

## IDA Rename / Type / Comment Recommendations

Apply only during a later IDA-enabled callback:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x004dcf60` | `StaticObjImageLib_Constructor` or typed constructor `StaticObjImageLib::StaticObjImageLib` | high; saved label already reported in docs |
| `0x004dd1e0` | `StaticObjImageLib_Destructor` / `StaticObjImageLib::~StaticObjImageLib` | high |
| `0x004dd2c0` | `StaticObjImageLib_RenderStaticObject` | high |
| `0x004dd850` | `StaticObjImageLib_GetStaticObjectBounds` | high |
| `0x004dd8b0` | `StaticObjImageLib_HitTestStaticObjectPixel` | high |
| `0x004dda30` | `StaticObjImageLib_GetStaticObjectEntry` | high |
| `0x004dda60` | `BuildTilecArchiveTable` | high; saved label already reported |
| `0x004dde10` | `StaticObjImageLib_LoadStaticObjectRecords` | medium; source-like but no direct xref |
| `0x004e5c00` | `StaticObjImageLib_ClearSingletonCleanup` | medium-high; cleanup helper, do not imply public API |
| `0x004e6990` | `StaticObjImageLib_ScalarDeletingDestructor` | high |
| `0x0061b704` | keep `??_7StaticObjImageLib@@6B@` | high |
| `0x0069b448` | `g_pStaticObjImageLib` | high |

Recommended local types:

```cpp
struct StaticObjEntry;
struct TileClassEntry;
struct ArchiveMetadataTable;
class StaticObjImageLib;
```

Recommended member comments:

- `StaticObjImageLib +0x04`: `TILEC archive/frame metadata table`
- `StaticObjImageLib +0x08`: `TILEC class rows: tileFrameId + allowPaletteFilter`
- `StaticObjImageLib +0x0c`: `SOBJ.TBL static-object entry pointer table`
- `StaticObjImageLib +0x10`: `SOBJ.TBL static-object entry count`
- `StaticObjEntry +0x00`: `light intensity; negative disables attached light`
- `StaticObjEntry +0x04`: `light vertical placement/height class`
- `StaticObjEntry +0x05`: `layer/tile-id count`
- `StaticObjEntry +0x08`: `optional cache/duplicate chain`

## Exact Implementation Callback Instructions

If the supervisor accepts this report, send B007 a callback with these exact scope constraints:

1. Edit only the accepted target/support docs listed above plus `by-class/-coverage-report.md`; do not edit `by-memory/-coverage-report.md`.
2. Apply [UID:0000E2] metadata `88/89`, keep owner/emitter `0000O7`, and add declaration-level C++ exactly or equivalently to this report.
3. Incorporate all valid field/resource/method/caller/rejected-alternative details from this report into [UID:0000E2], [UID:0000O7], [UID:0001W8], [UID:0001WC], [UID:0001W9], [UID:0001RL], [UID:00017H], and [UID:00017J] at report-level specificity.
4. For [UID:00017J], change direct owner/emitter to `0000E2`, raise to `88/89`, and add first-draft method-body C++ or a complete accepted method-body source sketch if method C++ is in scope.
5. Keep [UID:0003M2] and [UID:000184] formal C++ blank with explicit no-code proof.
6. Replace the by-class coverage row with the exact row in this report.
7. Record the exact pending `by-memory/-coverage-report.md` replacement/insertion rows in notes or final implementation output for supervisor application.
8. Run the scoped validators listed above and report exact command results.

## Implementation Readiness

Ready for supervisor implementation callback.

No target-specific blocker remains for [UID:0000E2] declaration-level C++. `RenderStaticObject` method-body C++ is also ready as first-draft source if the callback includes [UID:00017J]. Remaining uncertainty is final original spelling for helper/globals and shared highlight/translated-clip state; that uncertainty should cap confidence but should not block source-bearing documentation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000E2-StaticObjImageLib-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000E2"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000E2-StaticObjImageLib-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000E2-StaticObjImageLib-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000E2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
