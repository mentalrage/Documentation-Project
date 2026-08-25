** TARGET-REPORT-UID:0000L5 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000L5 MapTileImageLib Empty-Emitter Family Source-Quality Report

Assignment: `B011-report-0000L5-MapTileImageLib-empty-emitter-family-20260701`  
Mode: report-only research. No by-* implementation edits were made.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000L5] `by-file/MapTileImageLib.md` as `NexusTK/render/MapTileImageLib.cpp` source root and replace the twelve generated empty markers with source declarations, source-authored first-draft bodies, or exact formal no-code comments according to each marker's source role.
- Final disposition: implementation callback should edit the listed target/support by-* docs only after supervisor acceptance. Do not edit generated C++ by hand.
- Required action: insert exact formal `RECONSTRUCTION_CPP CODE` block content for [UID:00007T], [UID:0002IZ], [UID:0002J0], [UID:0001V3], [UID:0000RG], and [UID:0002J1]; insert exact formal comment-only no-code markers for [UID:0002J2], [UID:0001V2], [UID:0001Y3], [UID:0001OU], [UID:0000V0], and [UID:000180].
- Confidence: high for ownership/routing and no-code dispositions; medium-high for first-draft constructor/draw/helper source names because helper/wrapper spellings remain inferred but behavior and range evidence are strong.

## Target

- Target UID: [UID:0000L5]
- Target path: `by-file/MapTileImageLib.md`
- Generated file: `auto-generated/NexusTK/render/MapTileImageLib.cpp`
- Queue row: files with empty emitters, `13` total emitters, `1` filled, `12` empty, `7.7%` complete.
- Current scores and parent state: file root `87/86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

Current generated `MapTileImageLib.cpp` header at the start of this pass:

- `validator-command-id: 000000003584`
- `validator-refreshed-at: 2026-07-01T06:21:25-04:00`
- emits only [UID:000178] `MapTileImageLib::~MapTileImageLib()`.
- contains empty markers for [UID:00007T], [UID:0002IZ], [UID:0002J0], [UID:0002J2], [UID:0001V2], [UID:0001V3], [UID:0001Y3], [UID:0000RG], [UID:0001OU], [UID:0000V0], [UID:0002J1], and [UID:000180].

Existing docs already establish the source family:

- [UID:0000L5] owns the terrain tile image-library source file, `TILE%d.EPF` metadata loading, `TILE.TBL` palette/filter table, `TILE.TBD` legacy guard, and `g_pMapTileImageLib`.
- [UID:00007T] owns class methods and layout state.
- [UID:000178] already emits the ordinary destructor body and should remain the only source-authored destructor cleanup body.
- [UID:000177] is a non-emitting exact-child index, not an aggregate emitter.

The stale blocker pattern is older blank-C++ wording that treated missing original helper/type spellings as a reason to leave every related emitter empty. Current by-structure rules allow formal code once the item is reconstructable, has a valid emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided the code/no-code disposition is target-specific and behavior-safe.

## Evidence Checked

Project/read-gate evidence:

- `tools/leaser/Agents/Agent-B011/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `references/b-agent-research-and-implementation-workflow.md`
- `references/supervisor-rule26-review-and-incorporation-standard.md`
- `references/b-agent-report-template.md`
- `references/score-blocker-audit-standard.md`
- `by-structure.md` code-entry and emitter-route rules.

Target/support docs checked:

- `by-file/MapTileImageLib.md`
- `by-class/MapTileImageLib.md`
- `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`
- `by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md`
- `by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`
- `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`
- `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`
- `by-type/by-struct/MapTileImageLibLayout.md`
- `by-type/by-struct/MapTileRecord.md`
- `by-type/by-vtable/MapTileImageLibVtable.md`
- `by-global/g_pMapTileImageLib.md`
- `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`
- `by-item/LoadTileEpfMetadata_004D1B80.md`
- `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md`
- `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`
- `by-memory/0x0061b660-0x0061b670.MapTileImageLibVtableData.md`
- `by-item/EPFArchiveMetadataTable.md`
- `by-file/ImageFrameTable.md`
- `by-file/DATFile.md`, `by-class/DATFile.md`
- related render support docs for `PaletteSlotTable`, `SurfaceRenderCallbackTable`, `EPFTileContext`, and `LoadFrameDrawRecord`.

Old/executed report search terms:

- `TARGET-REPORT-UID:0000L5`, `0000L5`, `MapTileImageLib`, `0002IZ`, `0002J0`, `0002J1`, `0002J2`, `000180`, `0001OU`, `0001V3`.

Relevant old/executed reports opened:

- `executed-b-agent-research/B003/0002IZ-0002J1-maptileimagelib-source-quality.md`
- `executed-b-agent-research/B003/000178-00017G-00017I-00017W-00017X-00017Z-000180-0002J2-image-library-cleanup-source-quality.md`
- `executed-b-agent-research/B015/000177-MapTileImageLibLocalMethodCluster-source-quality.md`

Live IDA MCP evidence:

- MCP endpoint `http://127.0.0.1:13337/mcp` was available.
- `server_health`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Database/session used: `supervisor_resume_20260629`.
- `lookup_funcs` rechecked starts/sizes for `0x004d1860`, `0x004d19a0`, `0x004d1a20`, `0x004d1b80`, `0x004e5bc0`, and `0x004e66a0`.
- `xrefs_to` rechecked constructor, DrawTile, metadata helper, singleton clear helper, scalar deleting destructor, `0x0067a75c`, and `0x0061b664`.
- `callees` rechecked constructor, DrawTile, metadata helper, singleton clear helper, and scalar deleting destructor.
- `decompile` rechecked constructor, DrawTile, metadata helper, singleton clear helper, and scalar deleting destructor.
- `get_bytes` rechecked boundary padding, singleton initial storage, and vtable data.

Negative checks:

- No evidence was found that [UID:000177] should emit aggregate C++.
- No evidence was found that [UID:0002J1] should move to `ImageFrameTable.cpp` or `DATFile`.
- No evidence was found that [UID:000180] or [UID:0002J2] is source-authored API code.
- IDA/source docs do not prove original exact spellings for all wrapper helpers, so this report labels source-facing names as inferred where necessary.

## IDA MCP Facts

Function/range facts:

| Item | MCP fact |
| --- | --- |
| `0x004d1860` | `sub_4D1860`, size `0x13e`; constructor decompile publishes `dword_67A75C`, installs `MapTileImageLib::vftable`, calls `LoadTileEpfMetadata(L"TILE.EPF")`, opens `TILE.TBL`, validates count, allocates `4 * count`, and decodes each 16-bit record. |
| `0x004d1a20` | `sub_4D1A20`, size `0x152`; DrawTile decompile checks render suspension, palette-filter state, legacy `TILE.TBD`, `LoadFrameDrawRecord`, `tileRecords`, fallback fill callback, palette slot lookup, and blit callback. |
| `0x004d1b80` | `sub_4D1B80`, size `0x3a2`; helper decompile scans `TILE%d.EPF`, uses `HasDATEntry`, DATFile objects, 12-byte table header, `24 * (frameCount + 1)` records, payload rebasing, sentinel append, reverse close, and cleanup. |
| `0x004e5bc0` | `sub_4E5BC0`, size `0xb`; decompile is only `dword_67A75C = 0`. |
| `0x004e66a0` | `sub_4E66A0`, size `0xa8`; scalar deleting destructor decompile restores vtable, frees metadata records/table, frees tile records, clears singleton, calls base cleanup, and conditionally deletes storage based on flags. |

Padding/data facts:

| Address | Bytes / meaning |
| --- | --- |
| `0x004d199e` | `cc cc`, padding after constructor. |
| `0x004d1a1c` | four `cc` bytes, padding after ordinary destructor. |
| `0x004d1b72` | fourteen `cc` bytes, padding before metadata helper. |
| `0x004d1f22` | fourteen `cc` bytes, padding before ObjectStatusBlob parser boundary. |
| `0x004e5bcb` | five `cc` bytes after singleton clear helper. |
| `0x004e6748` | eight `cc` bytes after scalar deleting destructor. |
| `0x0067a75c` | `00 00 00 00`, zero-initialized singleton pointer storage. |
| `0x0061b660` | `0x00648774, 0x004e66a0, 0x004f4b10, 0x0041b6c0`, RTTI-adjacent locator plus three-slot vtable data. |

Xref/caller facts:

- Constructor has one startup/allocation caller at `0x004f6055`.
- DrawTile has four code refs: `0x00424441`, raw/no-function `0x0050c3d7`, `0x0050d984`, and `0x005497d0`.
- `LoadTileEpfMetadata` has one code ref at `0x004d18d1` from the constructor.
- `g_pMapTileImageLib` storage has the expected ten xrefs through construction, destruction, cleanup, shutdown/lifetime, and map/photo consumers.
- `0x0061b664` vtable address has refs from constructor, ordinary destructor, and scalar deleting destructor stores.

## Heuristic / Inference Reanalysis And Validation

The family has three distinct source-form classes:

1. Source-authored declarations/data that should be emitted: class declaration, `MapTileRecord`, and `g_pMapTileImageLib`.
2. Source-authored methods/helpers with behavior-complete first-draft bodies: constructor, DrawTile, and the tile EPF metadata helper.
3. Compiler/generated-binary or duplicate alias pages that should not hand-author behavior: scalar deleting destructor, vtable data, layout-support duplicate, singleton storage duplicate, by-item alias duplicate, and singleton clear helper.

Resolved source names:

- `tileFrameTable` remains the best source-facing name for object `+0x04`: constructor stores the `ArchiveMetadataTable *`, DrawTile passes it to `LoadFrameDrawRecord`, and destructor/scalar cleanup frees `table->records` then the table.
- `tileRecords` remains the best source-facing name for object `+0x08`: constructor allocates `4 * tileCount`, DrawTile consumes `2 * tileId` word/flag accesses, and destructor/scalar cleanup frees the array.
- `MapTileRecord::paletteIndex` remains better than `frameIndex`; DrawTile uses the requested tile id for frame lookup and passes the low 15-bit value to palette lookup.
- `MapTileRecord::allowPaletteFilter` remains better than gameplay/collision names; the high bit only gates palette-filter drawing.
- `LoadTileEpfMetadata(const wchar_t *unusedArchiveName)` preserves the observed one-argument call convention while documenting that the body hardcodes `TILE%d.EPF`.

Rejected alternatives:

- Leave every empty marker blank: rejected. Current by-structure says intentional no-body targets should use formal comments, not empty markers, and source-authored eligible emitters need first-draft C++ or target-specific no-code proof.
- Emit [UID:000177] aggregate C++: rejected. It is `RECONSTRUCTABLE:FALSE`, has no emitter route, contains exact source children plus padding, and ends before a different owner at `0x004d1f30`.
- Put `LoadTileEpfMetadata` under `ImageFrameTable.cpp`: rejected. Shared archive structures live there, but this helper has one constructor caller and hardcoded `TILE%d.EPF` tile-resource policy.
- Emit [UID:0002J2] as `ScalarDeletingDestructor`: rejected. That would duplicate the ordinary destructor and hand-author compiler ABI glue.
- Emit [UID:000180] as `ClearMapTileImageLibSingleton`: rejected. It is a two-instruction cleanup/unwind helper with no `this` and no source API semantics.
- Duplicate the global pointer definition on both [UID:0000RG] and [UID:0001OU]: rejected. The by-global page should own the source definition; the by-memory page should document storage and emit only an alias/no-duplicate comment.

Wave2/Wave3/simroot handling:

- Recovered generated/simroot source remains lead material only. Current recommendations are based on by-* docs plus live MCP evidence. Stale `95+`/`final-source gate` wording should be historicalized or replaced with the active current code-entry rule.

## Ranked Ownership Analysis

### 1. Keep `MapTileImageLib.cpp` / class split under [UID:0000L5] and [UID:00007T]

- Evidence for: constructor/destructor/draw/scalar wrapper all use class fields/vtable/singleton; file owns tile-specific resources and global state; current emitter chains surface to `auto-generated/NexusTK/render/MapTileImageLib.cpp`.
- Evidence against: exact original helper and parameter spellings are not recovered.
- Decision: accepted. Missing original spellings cap final confidence but do not block first-draft source or no-code comments.

### 2. Move all EPF table loading to `ImageFrameTable.cpp`

- Evidence for: shared `ArchiveMetadataTable`, `PackedArchiveRecord`, and `LoadFrameDrawRecord` declarations live with ImageFrameTable support.
- Evidence against: `LoadTileEpfMetadata` has one MapTile constructor caller, hardcoded `TILE%d.EPF`, and tile-resource-specific ownership. Accepted ImageFrameTable docs explicitly keep asset-specific builders with their owning image-library files unless common original source proof appears.
- Decision: rejected.

### 3. Treat empty markers as non-emitting/no-owner state

- Evidence for: several targets should not hand-author behavior.
- Evidence against: the targets already have reconstructable status and valid emitters; by-structure requires comment-only formal markers for intentional covered-by/generated-binary targets instead of leaving generated empty markers.
- Decision: rejected. Use exact formal comments where source C++ body is not appropriate.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Recommended Status |
| --- | --- | --- | --- | --- | --- | --- |
| File root | [UID:0000L5] `by-file/MapTileImageLib.md` | source root | n/a | FILE | `87/86` | `88/88`, document family disposition. |
| Class | [UID:00007T] `by-class/MapTileImageLib.md` | class declaration/child route | TRUE | `0000L5` | `86/88` | `88/90`, formal class declaration + `[[CHILDREN]]`. |
| `0x004d1860-0x004d199e` | [UID:0002IZ] constructor | source-authored method | TRUE | `00007T` | `87/91` | `89/92`, first-draft constructor C++. |
| `0x004d19a0-0x004d1a1c` | [UID:000178] ordinary destructor | source-authored method | TRUE | `00007T` | `88/92` | already coded; no required edit except cross-reference context if desired. |
| `0x004d1a20-0x004d1b72` | [UID:0002J0] DrawTile | source-authored method | TRUE | `00007T` | `86/89` | `88/90`, first-draft DrawTile C++. |
| `0x004d1b80-0x004d1f22` | [UID:0002J1] LoadTileEpfMetadata | file-local helper | TRUE | `0000L5` | `87/91` | `89/92`, first-draft helper C++. |
| `0x004e66a0-0x004e6748` | [UID:0002J2] scalar deleting destructor | compiler-generated wrapper | TRUE | `00007T` | `87/92` | `88/92`, formal no-code comment. |
| Type/layout | [UID:0001V2] `MapTileImageLibLayout` | duplicate layout evidence | TRUE | `00007T` | `86/90` | `87/90`, formal no-duplicate comment. |
| Type | [UID:0001V3] `MapTileRecord` | source record declaration | TRUE | `00007T` | `85/90` | `88/91`, formal struct declaration. |
| Vtable | [UID:0001Y3] `MapTileImageLibVtable` | compiler-generated vtable data | TRUE | `00007T` | `85/90` | `86/91`, formal generated-binary comment. |
| Global | [UID:0000RG] `g_pMapTileImageLib` | source global definition | TRUE | `0000L5` | `87/88` | `88/90`, formal global definition. |
| Storage | [UID:0001OU] singleton storage | backing data | TRUE | `0000RG` | `86/90` | `87/91`, formal no-duplicate storage comment. |
| Alias | [UID:0000V0] `LoadTileEpfMetadata_004D1B80` | by-item index | TRUE | `0000L5` | `85/90` | `86/90`, formal alias comment. |
| `0x004e5bc0-0x004e5bcb` | [UID:000180] singleton clear helper | cleanup/unwind glue | TRUE | `0000L5` | `85/90` | `86/90`, formal no-code comment. |

## First-Draft C++ Recommendation

Every code/comment below is exact proposed formal `RECONSTRUCTION_CPP CODE` multiline block content. The single-line header value `RECONSTRUCTION_CPP CODE:[[[]]]` should remain unchanged unless the validator requires otherwise.

### [UID:00007T] `by-class/MapTileImageLib.md`

```cpp
class MapTileImageLib : public LObject
{
public:
    MapTileImageLib();
    virtual ~MapTileImageLib();

    void DrawTile(void *drawTarget, const RectBounds *destinationRect, unsigned int tileId);

private:
    ArchiveMetadataTable *tileFrameTable;
    MapTileRecord *tileRecords;
};

[[CHILDREN]]
```

Reason: this page is the class declaration/child route, not a child-body duplicate. `DrawTile` parameter types remain inferred source-facing aliases; destination and target roles are directly supported by decompile/caller docs.

### [UID:0002IZ] `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`

```cpp
MapTileImageLib::MapTileImageLib()
    : tileFrameTable(0),
      tileRecords(0)
{
    g_pMapTileImageLib = this;

    tileFrameTable = LoadTileEpfMetadata(L"TILE.EPF");

    DATFile tileTable;
    tileTable.Open(L"TILE.TBL");

    unsigned int tileCount = 0;
    tileTable.Read(&tileCount, sizeof(tileCount));

    if (tileFrameTable == 0 || tileCount != tileFrameTable->frameCount)
    {
        ShowFatalTileFileError(L"Error on Tile File!");
        return;
    }

    tileRecords = tileCount != 0 ? new MapTileRecord[tileCount] : 0;

    for (unsigned int index = 0; index < tileCount; ++index)
    {
        short packedRecord = 0;
        tileTable.Read(&packedRecord, sizeof(packedRecord));

        tileRecords[index].allowPaletteFilter = packedRecord < 0;
        tileRecords[index].paletteIndex =
            static_cast<unsigned short>(packedRecord & 0x7fff);
    }
}
```

Notes:

- `ShowFatalTileFileError` is an inferred source-facing alias for the documented `sub_467380`/`sub_4673A0`/`MessageBoxW(... "Error on Tile File!" ... 0x30)`/fatal-exit path. If the implementation callback finds a project-standard fatal helper name, use that helper name while preserving the exact fatal behavior.
- Do not write `reserved`; the observed constructor never initializes byte `+0x03`.
- Do not copy the decompiler `this == -4` guard; docs already identify it as compiler/decompiler cleanup residue around the singleton write.

### [UID:0002J0] `by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`

```cpp
void MapTileImageLib::DrawTile(void *drawTarget,
                               const RectBounds *destinationRect,
                               unsigned int tileId)
{
    if (g_tileRenderingSuspended)
    {
        return;
    }

    const bool paletteFilterActive = PaletteLib_IsFilterActive(g_pPaletteLib);
    EPFTileContext tileContext;
    InitEPFTileContext(&tileContext);

    unsigned int resolvedTileId = tileId;
    if (!g_useTileEpfMetadata)
    {
        DATFile tileBounds;
        tileBounds.Open(L"TILE.TBD");

        unsigned int tileBoundsCount = 0;
        tileBounds.Read(&tileBoundsCount, sizeof(tileBoundsCount));

        if (resolvedTileId >= tileBoundsCount)
        {
            resolvedTileId = 0;
        }
    }

    if (resolvedTileId != 0)
    {
        LoadFrameDrawRecord(tileFrameTable, resolvedTileId, &tileContext);

        if (tileContext.payloadStart != 0)
        {
            const MapTileRecord *tileRecord = &tileRecords[resolvedTileId];
            if (!paletteFilterActive || tileRecord->allowPaletteFilter)
            {
                void *palette =
                    GetPaletteSlotPalette(g_pPaletteLib, 0, tileRecord->paletteIndex, 0);
                BlitTileFrame(&tileContext, destinationRect, 0, palette, 0);
            }
            return;
        }

        if (paletteFilterActive)
        {
            return;
        }
    }

    FillTileTarget(drawTarget, 128);
    DrawTileFallback(drawTarget, destinationRect);
}
```

Notes:

- Helper/global names in this draft are source-facing aliases for the decompiled `byte_69B420`, `sub_543D20`, `sub_457A60`, `byte_66DA97`, `dword_69B3FC`, `sub_4D1600`, `sub_543E40`, and `dword_69B3E8` path.
- The source block preserves the observed early returns: render suspension returns immediately; unresolved nonzero tile returns without fallback when palette filtering is active; tile id `0` or unresolved non-filtered tile uses the fallback fill/draw path.
- The direct decompile indexes `tileRecords[resolvedTileId]`, not `tileRecords[resolvedTileId - 1]`; preserve that index unless a later instruction-level caller audit proves a one-based source abstraction.

### [UID:0002J2] `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`

```cpp
// No handwritten C++ body should be emitted for [UID:0002J2].
// This range is the compiler-generated scalar deleting destructor for
// MapTileImageLib. Source-authored cleanup is emitted once by
// [UID:000178] MapTileImageLib::~MapTileImageLib(); the class declaration's
// virtual destructor should regenerate this vtable ABI wrapper.
```

### [UID:0001V2] `by-type/by-struct/MapTileImageLibLayout.md`

```cpp
// No separate layout C++ should be emitted for [UID:0001V2].
// The MapTileImageLib class declaration emitted by [UID:00007T] owns the
// source layout fields: LObject base/vptr at +0x00, tileFrameTable at +0x04,
// and tileRecords at +0x08. This page preserves offset evidence only.
```

### [UID:0001V3] `by-type/by-struct/MapTileRecord.md`

```cpp
struct MapTileRecord
{
    unsigned short paletteIndex;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};
```

Do not add a constructor or zero-initializer; byte `+0x03` is intentionally documented as reserved/unwritten by the observed constructor.

### [UID:0001Y3] `by-type/by-vtable/MapTileImageLibVtable.md`

```cpp
// No handwritten vtable data should be emitted for [UID:0001Y3].
// The primary MapTileImageLib vtable at 0x0061b664 is compiler-generated from
// the class declaration and virtual destructor; [UID:0002J2] documents the
// scalar deleting destructor slot.
```

### [UID:0000RG] `by-global/g_pMapTileImageLib.md`

```cpp
MapTileImageLib *g_pMapTileImageLib = 0;
```

### [UID:0001OU] `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`

```cpp
// Backing storage for g_pMapTileImageLib is emitted by [UID:0000RG].
// This exact data range is the zero-initialized 0x0067a75c singleton pointer
// storage; do not duplicate the global definition from this by-memory page.
```

### [UID:0000V0] `by-item/LoadTileEpfMetadata_004D1B80.md`

```cpp
// LoadTileEpfMetadata is emitted by the exact function page [UID:0002J1].
// This by-item page is an alias/index for 0x004d1b80 and must not duplicate
// the helper body in MapTileImageLib.cpp.
```

### [UID:0002J1] `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`

```cpp
ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct TileArchiveShardHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    int shardCount = 0;
    wchar_t archiveName[20];
    while (shardCount < 100)
    {
        swprintf(archiveName, 20, L"TILE%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    TileArchiveShardHeader *headers =
        shardCount > 0 ? new TileArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"TILE%d.EPF", i);
        archives[i].Open(archiveName);
        archives[i].Read(&headers[i], 8);

        table->frameCount =
            static_cast<unsigned short>(table->frameCount + headers[i].frameCount);
        if (table->maxWidth < headers[i].maxWidth)
        {
            table->maxWidth = headers[i].maxWidth;
        }
        if (table->maxHeight < headers[i].maxHeight)
        {
            table->maxHeight = headers[i].maxHeight;
        }
    }

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *outRecord = table->records;
    unsigned char *lastPayloadBase = 0;
    int lastRecordTableOffset = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        int recordTableOffset = 0;
        archives[i].Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archives[i].GetDataPointer();
        lastPayloadBase = payloadBase;
        lastRecordTableOffset = recordTableOffset;

        archives[i].Seek(recordTableOffset, 1);

        for (int recordIndex = 0; recordIndex < headers[i].frameCount; ++recordIndex)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            int payloadStartOffset = 0;
            int payloadEndOffset = 0;

            archives[i].Read(&top, sizeof(top));
            archives[i].Read(&left, sizeof(left));
            archives[i].Read(&bottom, sizeof(bottom));
            archives[i].Read(&right, sizeof(right));
            archives[i].Read(&payloadStartOffset, sizeof(payloadStartOffset));
            archives[i].Read(&payloadEndOffset, sizeof(payloadEndOffset));

            InitRectBounds(&outRecord->bounds, left, top, right, bottom);
            outRecord->payloadStart = payloadBase + payloadStartOffset;
            outRecord->payloadEnd = payloadBase + payloadEndOffset;
            ++outRecord;
        }
    }

    InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
    outRecord->payloadStart =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;
    outRecord->payloadEnd =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;

    for (int i = shardCount - 1; i >= 0; --i)
    {
        archives[i].Close();
    }

    delete [] archives;
    delete [] headers;

    return table;
}
```

This mirrors the already-accepted source shape for sibling `BuildEffectArchiveTable`, with `TILE%d.EPF` and `TileArchiveShardHeader`. It preserves the observed unused parameter, 100-shard cap, 20-wide-character buffer, 12-byte header, 24-byte records, sentinel, DATFile cleanup, and source-file ownership.

### [UID:000180] `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md`

```cpp
// No handwritten C++ API should be emitted for [UID:000180].
// This two-instruction cleanup helper only clears g_pMapTileImageLib during
// constructor/static cleanup routing. Source-authored lifetime behavior is
// represented by MapTileImageLib construction/destruction and the global
// definition, not by a public or file-local ClearMapTileImageLibSingleton API.
```

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata changes |
| --- | ---: | ---: | --- |
| [UID:0000L5] | `87/86` | `88/88` | Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CANONICAL_OWNER:FILE`. |
| [UID:00007T] | `86/88` | `88/90` | Keep owner/emitter `0000L5`; add class declaration + `[[CHILDREN]]`. |
| [UID:0002IZ] | `87/91` | `89/92` | Keep owner/emitter `00007T`; add constructor C++. |
| [UID:0002J0] | `86/89` | `88/90` | Keep owner/emitter `00007T`; add DrawTile C++. |
| [UID:0002J2] | `87/92` | `88/92` | Keep owner/emitter `00007T`; add formal no-code comment. |
| [UID:0001V2] | `86/90` | `87/90` | Keep owner/emitter `00007T`; add no-duplicate layout comment. |
| [UID:0001V3] | `85/90` | `88/91` | Keep owner/emitter `00007T`; add `MapTileRecord` struct. |
| [UID:0001Y3] | `85/90` | `86/91` | Keep owner/emitter `00007T`; add generated-vtable comment. |
| [UID:0000RG] | `87/88` | `88/90` | Keep owner/emitter `0000L5`; add global definition. |
| [UID:0001OU] | `86/90` | `87/91` | Keep owner/emitter `0000RG`; add backing-storage/no-duplicate comment. |
| [UID:0000V0] | `85/90` | `86/90` | Keep owner/emitter `0000L5`; add alias/no-duplicate comment. |
| [UID:0002J1] | `87/91` | `89/92` | Keep owner/emitter `0000L5`; add helper C++. |
| [UID:000180] | `85/90` | `86/90` | Keep owner/emitter `0000L5`; add cleanup-glue no-code comment. |

Reason not higher:

- Exact original spellings for `ShowFatalTileFileError`, DrawTile callback helpers, palette helper names, and the final class header organization remain inferred.
- The vtable, scalar deleting destructor, singleton storage, and clear helper are documented source effects but not source-authored bodies.
- The generated output still needs a validator-backed implementation refresh before the empty-marker count is proven fixed.

## Claim And Incorporation Ledger

| Claim ID | Claim / fact to preserve | Confidence | Evidence | Destination / exclusion | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | `MapTileImageLib.cpp` remains the source root for the terrain tile library, `TILE%d.EPF`, `TILE.TBL`, `TILE.TBD`, singleton, class, and helper family. | High | File doc, live MCP xrefs/callees, generated path. | `by-file/MapTileImageLib.md` status/file role now has B011 source-root/rejected-owner note. | incorporate | applied; validator `000000003655`, ok `1`. |
| C02 | Current generated file emits only [UID:000178] and has twelve empty markers under command `000000003584`. | High | Generated header/content read. | `by-file/MapTileImageLib.md` generated-output note preserves the baseline and supersession. | incorporate | applied; generated header now `000000003680` / `2026-07-01T06:52:10-04:00`, no `Empty Emitter Marker` lines. |
| C03 | [UID:00007T] should emit class declaration plus `[[CHILDREN]]`, not remain an empty class marker. | High | Class doc, by-structure child route, current destructor child emission. | `by-class/MapTileImageLib.md` formal C++ block. | incorporate | applied; validator `000000003657`, generated line `UID:00007T` emits class declaration. |
| C04 | Constructor is source-authored and first-draft C++ ready with `tileFrameTable`, `tileRecords`, `TILE.TBL`, count validation, and packed record decode. | Medium-high | MCP decompile `0x004d1860`, docs, old B003 report. | `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`. | incorporate | applied; validator `000000003659`, generated line `UID:0002IZ` emits constructor. |
| C05 | Constructor must not initialize `MapTileRecord::reserved`; observed code writes only word `+0x00` and byte `+0x02`. | High | MCP decompile and MapTileRecord docs. | Constructor page and `MapTileRecord` page. | incorporate | applied; constructor code omits `reserved`, MapTileRecord page records unwritten padding, validators `000000003659` and `000000003667`. |
| C06 | DrawTile is source-authored and first-draft C++ ready, with inferred aliases for unresolved callback/helper names. | Medium | MCP decompile `0x004d1a20`, DrawTile docs, caller docs. | `by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`. | incorporate | applied; validator `000000003661`, generated line `UID:0002J0` emits DrawTile. |
| C07 | DrawTile fallback and palette-filter early-return behavior must be preserved. | High | MCP decompile branch structure and current DrawTile doc. | DrawTile page formal C++ notes/body. | incorporate | applied; formal body preserves palette-filter early returns/fallback, validator `000000003661`. |
| C08 | Scalar deleting destructor is compiler-generated ABI glue regenerated from virtual destructor declaration and [UID:000178]. | High | MCP decompile `0x004e66a0`, vtable bytes, B003 cleanup report. | Scalar deleting destructor page formal comment. | incorporate | applied; validator `000000003663`, generated no-code comment present. |
| C09 | Layout support should not duplicate the class declaration; it should emit a no-duplicate offset-evidence comment. | High | by-structure duplicate/covered-by rule and class/layout docs. | `by-type/by-struct/MapTileImageLibLayout.md`. | incorporate | applied; validator `000000003665`, generated no-duplicate comment present. |
| C10 | `MapTileRecord` should emit a three-field POD struct with `paletteIndex`, `allowPaletteFilter`, and `reserved`. | High | Constructor/DrawTile decompile and MapTileRecord doc. | `by-type/by-struct/MapTileRecord.md`. | incorporate | applied; validator `000000003667`, generated `struct MapTileRecord` present. |
| C11 | Vtable data should not be hand-authored; class declaration and virtual destructor regenerate it. | High | Vtable docs, MCP bytes at `0x0061b660`, scalar wrapper slot. | `by-type/by-vtable/MapTileImageLibVtable.md`. | incorporate | applied; validator `000000003669`, generated no-vtable-data comment present. |
| C12 | `g_pMapTileImageLib` source definition belongs on the by-global page as `MapTileImageLib *g_pMapTileImageLib = 0;`. | High | Global docs, storage bytes, xrefs. | `by-global/g_pMapTileImageLib.md`. | incorporate | applied; validator `000000003671`, generated definition present. |
| C13 | Backing storage page must not duplicate the global definition; bytes are zero/null at `0x0067a75c`. | High | MCP `get_bytes`, storage doc. | `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`. | incorporate | applied; validator `000000003673`, zero-byte/storage evidence preserved and no duplicate generated section. |
| C14 | By-item `LoadTileEpfMetadata_004D1B80` is an alias/index and should not duplicate [UID:0002J1] body. | High | by-item and exact by-memory docs. | `by-item/LoadTileEpfMetadata_004D1B80.md`. | incorporate | applied; validator `000000003675`, generated alias/no-duplicate comment present. |
| C15 | Exact metadata helper [UID:0002J1] should emit the tile-specific EPF shard builder body, parallel to accepted `BuildEffectArchiveTable`. | Medium-high | MCP decompile `0x004d1b80`; accepted sibling formal code. | `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`. | incorporate | applied; validator `000000003677`, generated helper body present. |
| C16 | Singleton clear helper [UID:000180] is cleanup/unwind glue, not a source API; emit formal no-code comment. | High | MCP decompile `0x004e5bc0`, bytes, B003 cleanup report. | `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md`. | incorporate | applied; validator `000000003679`, generated no-API comment present. |
| C17 | [UID:000177] remains a non-emitting index and should not be edited except as already-present support if callback context needs cross-checking. | High | B015 executed report and current page. | `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`. | already-present | already-present; file not edited, route preserved in target/support notes. |
| C18 | Prior B003 blank-C++ rationale for constructor/helper is superseded by current shared declarations and accepted sibling helper-body style. | Medium-high | B003 report, `EPFArchiveMetadataTable` formal declarations, `BuildEffectArchiveTable` code. | Historical/stale notes in constructor/helper/file/class docs. | historicalize | applied; stale blank-C++ notes historicalized in constructor, DrawTile, metadata helper, class, layout, record, by-item, and file notes. |
| C19 | No generated reports, coverage reports, generated C++, queue/tool state, archives, supervisor ledgers, by-project-structure docs, or IDA DB should be manually edited by B011 in this implementation callback. | High | Goal.md and workflow. | Exclusion in report/checklist only. | not-applicable | applied; B011 manually edited only listed by-* docs and this report; generated/tool files changed only via validators. |

## Recommended Target Doc Changes

Apply only after supervisor callback:

- `by-file/MapTileImageLib.md`: update file-root status/generated-output section with this family decision, current MCP session facts, current generated header proof, and recommended score `88/88`.
- `by-class/MapTileImageLib.md`: update score to `88/90`, replace stale class-level blank C++ wording, add class declaration formal block, preserve method inventory and no-duplicate child route.
- `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`: update score to `89/92`, add first-draft constructor block and notes about inferred fatal helper name and uninitialized reserved byte.
- `by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`: update score to `88/90`, add first-draft DrawTile block, and preserve unresolved helper/callback aliases as inferred names rather than blockers.
- `by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`: update score to `88/92`, add formal no-code comment, and state [UID:000178] plus virtual destructor declaration regenerate the wrapper.
- `by-type/by-struct/MapTileImageLibLayout.md`: update score to `87/90`, add formal no-duplicate layout comment, and replace stale `95+`/blank-gate language with current class-declaration route.
- `by-type/by-struct/MapTileRecord.md`: update score to `88/91`, add formal struct block, and preserve the padding/reserved byte caveat.
- `by-type/by-vtable/MapTileImageLibVtable.md`: update score to `86/91`, add formal generated-binary comment.
- `by-global/g_pMapTileImageLib.md`: update score to `88/90`, add global definition block, and document source definition/backing storage split.
- `by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md`: update score to `87/91`, add backing-storage/no-duplicate comment, preserve zero storage bytes.
- `by-item/LoadTileEpfMetadata_004D1B80.md`: update score to `86/90`, add alias/no-duplicate comment and link [UID:0002J1] as exact body owner.
- `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`: update score to `89/92`, add first-draft helper block and accepted `BuildEffectArchiveTable` sibling precedent.
- `by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md`: update score to `86/90`, add cleanup-glue no-code comment, preserve exact bytes/body and cleanup/unwind routing.

No manual `-coverage-report.md` or generated-report text is recommended for B011 to edit. Validator-generated reports should refresh after implementation validators and supervisor report execution.

## Validator / Generated Refresh Expectations

Run scoped validators from `source-3/project-documentation` after implementation. Use `--wait-generated` because `auto-generated/NexusTK/render/MapTileImageLib.cpp` freshness matters.

Recommended commands:

> Executable block R001 was removed from this report and preserved verbatim in [0000L5-MapTileImageLib-empty-emitter-family-source-quality-removed.md](0000L5-MapTileImageLib-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness expectation:

- After the last scoped validator, inspect `auto-generated/NexusTK/render/MapTileImageLib.cpp`.
- Its `validator-command-id` and `validator-refreshed-at` must be equal/newer than the last relevant validator command metadata.
- It should no longer contain `Empty Emitter Marker` comments for the twelve audited UIDs.
- It should contain the pre-existing [UID:000178] destructor, class/type/global declarations, constructor, DrawTile, LoadTileEpfMetadata, and formal no-code comments for duplicate/generated targets.

## Open Questions With Attempted Resolution

- Exact original spelling for DrawTile parameters and render callback helpers remains unresolved. Current evidence supports source-facing aliases enough for first-draft C++ but not final-audit confidence.
- `ShowFatalTileFileError` is an inferred alias for the constructor fatal path. The implementation callback may replace it with an existing project-standard fatal helper if found, but must preserve the documented `MessageBoxW` fatal behavior and not silently drop the error path.
- Exact header/file factoring is still broader than this report; this report only supplies formal block text for current by-* emitters.

These are not blockers for the report recommendations because behavior, ownership, range, emitter route, and generated-binary exclusions are resolved enough under current rules.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B011/research/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md`
- Modified by-* docs: none in this report-only pass.
- Generated files/reports: none edited.
- IDA DB: no edits.
- Leases: none used.
- Validators: none run, because this is report-only and implementation has not been authorized.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor sent implementation callback; this row is no longer a report-only blocker.
- [x] `by-file\MapTileImageLib.md`: update score `87/86 -> 88/88`; add B011 2026-07-01 empty-emitter-family note with MCP session, generated header `000000003584` / `2026-07-01T06:21:25-04:00`, and disposition that the file should emit destructor plus class/type/global declarations, constructor, DrawTile, metadata helper, and formal no-code comments for generated/duplicate markers. Proof: file updated; validator `000000003655`, ok `1`.
- [x] `by-class\MapTileImageLib.md`: update score `86/88 -> 88/90`; insert the exact class declaration + `[[CHILDREN]]` formal block from this report; replace stale class-level blank-C++ wording with current source route; preserve field/method inventory and generated-binary exclusions. Proof: formal block present; validator `000000003657`, ok `1`.
- [x] `by-memory\0x004d1860-0x004d199e.MapTileImageLibConstructor.md`: update score `87/91 -> 89/92`; insert exact constructor formal C++ block; document inferred `ShowFatalTileFileError` alias and the requirement not to initialize `MapTileRecord::reserved`. Proof: formal block and alias/reserved notes present; validator `000000003659`, ok `1`.
- [x] `by-memory\0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md`: update score `86/89 -> 88/90`; insert exact DrawTile formal C++ block; preserve helper/callback names as inferred aliases and preserve palette-filter/fallback early returns. Proof: formal block and source-quality note present; validator `000000003661`, ok `1`.
- [x] `by-memory\0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md`: update score `87/92 -> 88/92`; insert exact scalar-deleting no-code formal comment; preserve ordinary-destructor parity and compiler ABI wrapper proof. Proof: formal comment present; validator `000000003663`, ok `1`.
- [x] `by-type\by-struct\MapTileImageLibLayout.md`: update score `86/90 -> 87/90`; insert exact no-duplicate layout formal comment; historicalize stale `95+`/blank gate language where present. Proof: formal comment and historicalized stale language present; validator `000000003665`, ok `1`.
- [x] `by-type\by-struct\MapTileRecord.md`: update score `85/90 -> 88/91`; insert exact `struct MapTileRecord` formal block; preserve `reserved` byte as unwritten padding. Proof: formal struct and padding note present; validator `000000003667`, ok `1`.
- [x] `by-type\by-vtable\MapTileImageLibVtable.md`: update score `85/90 -> 86/91`; insert exact generated-vtable no-code formal comment; preserve `0x0061b660-0x0061b670` vtable data facts. Proof: formal comment and vtable facts present; validator `000000003669`, ok `1`.
- [x] `by-global\g_pMapTileImageLib.md`: update score `87/88 -> 88/90`; insert exact global definition formal block; document that backing storage is not a duplicate definition owner. Proof: formal definition present; validator `000000003671`, ok `1`.
- [x] `by-memory\0x0067a75c-0x0067a760.g_pMapTileImageLib.md`: update score `86/90 -> 87/91`; insert exact backing-storage/no-duplicate formal comment; preserve zero bytes `00 00 00 00` and ten-xref lifecycle evidence. Proof: formal comment and storage evidence present; validator `000000003673`, ok `1`.
- [x] `by-item\LoadTileEpfMetadata_004D1B80.md`: update score `85/90 -> 86/90`; insert exact alias/no-duplicate formal comment; state [UID:0002J1] owns the exact helper body. Proof: formal comment present; validator `000000003675`, ok `1`.
- [x] `by-memory\0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`: update score `87/91 -> 89/92`; insert exact `LoadTileEpfMetadata` formal C++ block; preserve one-argument unused parameter, `TILE%d.EPF`, 100-shard cap, 20-wide-character buffer, DATFile flow, 12-byte table header, 24-byte records, sentinel, reverse close, and cleanup. Proof: formal body and source-quality note present; validator `000000003677`, ok `1`.
- [x] `by-memory\0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md`: update score `85/90 -> 86/90`; insert exact cleanup-glue no-code formal comment; preserve exact `mov dword_67A75C, 0; ret` bytes and cleanup/unwind provenance. Proof: formal comment and byte/provenance notes present; validator `000000003679`, ok `1`.
- [x] `by-memory\0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`: no required edit unless supervisor wants an already-present cross-check note; keep [UID:000177] non-emitting/index-only and do not emit aggregate C++. Proof: not edited; already-present index policy preserved through class/file/support notes.
- [x] Claim And Incorporation Ledger: during callback, update every accepted row from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof. Proof: rows C01-C19 updated above.
- [x] Historical/stale assumptions: preserve useful history but supersede old blank-C++ rationale for constructor/helper where it conflicts with current code-entry rule and accepted sibling helper formal source style. Proof: constructor/helper/class/file/layout/record/by-item stale blank-gate wording historicalized or superseded.
- [x] Do not edit generated reports, generated C++ files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Proof: B011 manual edits were limited to listed by-* docs and this report; validator refreshed generated/tool state.
- [x] Run scoped validators with `--wait-generated` for every edited doc using the exact commands listed in this report. Proof: compact rerun command ids `000000003655`, `000000003657`, `000000003659`, `000000003661`, `000000003663`, `000000003665`, `000000003667`, `000000003669`, `000000003671`, `000000003673`, `000000003675`, `000000003677`, `000000003679`, all exit `0`, ok `1`, generated refresh completed.
- [x] Verify generated `auto-generated\NexusTK\render\MapTileImageLib.cpp` freshness by comparing generated header command id/timestamp to validator metadata; confirm no old empty markers remain for the twelve audited UIDs. Proof: generated header `validator-command-id: 000000003680`, `validator-refreshed-at: 2026-07-01T06:52:10-04:00`, newer than the last scoped validator `000000003679`; `rg "Empty Emitter Marker"` returned no matches; audited UIDs are present as emitted code/comment sections.
- [x] Report validator command ids/timestamps/results, generated freshness proof, changed files, checklist status, and confirmation no B011 leases remain. Proof: final response will include compact command table and lease check.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T06:56:28","uid":"0000L5"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000L5-MapTileImageLib-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000L5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
