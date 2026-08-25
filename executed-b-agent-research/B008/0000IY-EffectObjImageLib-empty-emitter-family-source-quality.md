** TARGET-REPORT-UID:0000IY **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000IY EffectObjImageLib Empty-Emitter Family Source-Quality Report

Assignment: `B008-report-0000IY-EffectObjImageLib-empty-emitter-family-20260630`

Revision assignment: `B008-revise-0000IY-EffectObjImageLib-empty-emitter-family-20260630`

Implementation callback assignment: `B008-implement-0000IY-EffectObjImageLib-empty-emitter-family-20260630`

Primary target: [UID:0000IY] `by-file/EffectObjImageLib.md`

Mode: implementation callback complete after supervisor acceptance. By-* docs listed in this report were updated under short leases; scoped validators were run with `--wait-generated`; leases were released. No manual generated-file, coverage-report, project-level report, validator/tool-state, IDA DB, executed archive, supervisor ledger, or lock-file edits were made.

## Executive Recommendation

Implement a family repair for `NexusTK/render/EffectObjImageLib.cpp` that preserves the accepted UID0002H9 constructor body and replaces the 17 remaining generated empty markers with either source-quality first-draft declarations/bodies or explicit no-code/source-form markers.

The key disposition is mixed:

- Source-ready code/declaration insertions: [UID:00017L] `EffectObjImageLib::~EffectObjImageLib`, [UID:00017M] `RenderEffectFrame`, [UID:0002HA] `GetEffectInfo`, [UID:0002HB] `LoadEffectTables`, [UID:0000U4] `BuildEffectArchiveTable`, [UID:0000UR] `GetSpriteBounds`, [UID:0000QT] `g_pEffectObjImageLib`, [UID:0001U7] `EffectFrameRecord`, [UID:0001U8] `EffectInfo`, and [UID:0001UA] `EffectPixMapInfo`.
- Marker-only insertions: [UID:00004A], [UID:0002HC], [UID:0001U9], [UID:0001XG], [UID:0001PQ], [UID:00017W], and [UID:0002MK]. These markers are intentional generated-output artifacts, not source bodies. They clear empty markers where the source form is a class/layout/vtable/storage/compiler artifact rather than a handwritten function.
- Source placement remains [UID:0000IY] `NexusTK/render/EffectObjImageLib.cpp`. Do not move ownership to `Effects`, `MapPane`, `EffectObjectPane`, `ImageLib`, `ProtectedArray`, or shared EPF resource docs.
- Update [UID:0000IY] by-file text after implementation to record the family disposition, current generated state, and the distinction between first-draft code and marker-only pages. A modest by-file score update to `90/88` is justified after implementation because the file-level empty-emitter family will have explicit source-form disposition, but exact original filename and some private field names remain confidence caps.

## Current Generated State

Pre-callback read-only generated output check:

- File: `auto-generated/NexusTK/render/EffectObjImageLib.cpp`
- Header: `validator-command-id: 000000002476`
- Header timestamp: `2026-06-30T06:05:16-04:00`
- Refresh source: `foreground-generated-refresh`
- Tracker row: 18 emitters, 1 filled, 17 empty, 5.6%.

Filled emitter:

- [UID:0002H9] `EffectObjImageLibConstructor`, implemented by accepted B002 report and currently emitting `EffectObjImageLib::EffectObjImageLib()`.

Current empty markers in generated output:

| UID | Path | Current score | Recommended disposition |
| --- | --- | --- | --- |
| 00004A | `by-class/EffectObjImageLib.md` | 85/87 | marker-only class ownership/layout marker; optional score `86/88`; set position `10`. |
| 00017L | `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md` | 88/91 | first-draft source destructor body; raise to `90/92`. |
| 00017M | `by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md` | 86/90 | first-draft render body with explicit support-type caveats; raise to `88/91`. |
| 0002HA | `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md` | 88/92 | first-draft source body; raise to `90/93`. |
| 0002HB | `by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md` | 88/90 | first-draft loader body using current `EffectInfo`, `EffectFrameRecord`, `EffectPixMapInfo`, `DATFile`, and `ProtectedArray<T>::Resize` support; raise to `90/91`. |
| 0002HC | `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md` | 88/91 | marker-only compiler wrapper note; score unchanged. |
| 0001U9 | `by-type/by-struct/EffectObjImageLibLayout.md` | 86/89 | marker-only covered-by-class/member-layout note; score unchanged. |
| 0001XG | `by-type/by-vtable/EffectObjImageLibVtable.md` | 84/90 | marker-only vtable/RTTI note; raise completion to `85/90`. |
| 0000QT | `by-global/g_pEffectObjImageLib.md` | 86/89 | source global pointer definition; raise to `88/90`; set position `4`. |
| 0001PQ | `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md` | 86/90 | marker-only covered-storage note; score unchanged. |
| 0000U4 | `by-item/BuildEffectArchiveTable_004DE420.md` | 86/91 | first-draft archive-table builder body with unused incoming-name caveat; raise to `89/92`. |
| 0000UR | `by-item/GetSpriteBounds_004DE2A0.md` | 85/90 | first-draft bounds helper body using the four-field `EffectFrameRecord` forwarding signature; raise to `88/91`. |
| 00017W | `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md` | 85/90 | marker-only compiler/static cleanup note; score unchanged. |
| 0002MK | `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md` | 86/91 | marker-only raw-vtable-data note plus stale summary repair; score unchanged. |
| 0001U7 | `by-type/by-struct/EffectFrameRecord.md` | 86/89 | first-draft POD declaration; raise to `88/90`; set position `1`. |
| 0001U8 | `by-type/by-struct/EffectInfo.md` | 86/89 | first-draft POD declaration; raise to `88/90`; set position `2`. |
| 0001UA | `by-type/by-struct/EffectPixMapInfo.md` | 85/91 | first-draft one-field POD declaration; raise to `87/91`; set position `3`. |

Post-callback generated output:

- Final generated file: `auto-generated/NexusTK/render/EffectObjImageLib.cpp`
- Final header: `validator-command-id: 000000002660`
- Final header timestamp: `2026-06-30T07:03:51-04:00`
- Refresh source: `foreground-generated-refresh`
- Empty marker search: no `Empty emitter`, `EMPTY`, or former empty-marker comments remain in the final file.
- Emitted by-file output now contains [UID:0001U7], [UID:0001U8], [UID:0001UA], [UID:0000QT], [UID:00004A], [UID:0000U4], [UID:0000UR], [UID:00017W], and [UID:0002MK].
- Current generator traversal still suppresses class/global-owned child pages [UID:00017L], [UID:00017M], [UID:0002HA], [UID:0002HB], [UID:0002HC], [UID:0001U9], [UID:0001XG], and [UID:0001PQ] from the by-file output. Their by-* pages now contain accepted formal source/marker text and passed scoped validators, so the absence is a generator traversal state, not a remaining marker-only report blocker.

## MCP Evidence

IDA MCP was available and current. Evidence source:

- MCP database/session: `supervisor_resume_20260629`
- `server_health`: status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, string-cache size `2067`.
- Narrow schema-current calls used across the original report and rework: `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_int`, `analyze_function`, and `decompile`.

Function boundary and xref evidence from current MCP:

| Item | Current MCP fact |
| --- | --- |
| Constructor | `0x004ddf60` is `sub_4DDF60`, size `0xee`; `0x004de04e` is not a function; bytes at `0x004de04e` are `cc cc`. |
| Ordinary destructor | `0x004de050` is `sub_4DE050`, size `0x13a`; prototype `void __thiscall(_DWORD *this)`; no direct callers; callees include free helpers, archive cleanup helpers, and base cleanup. |
| RenderEffectFrame | `0x004de190` is `sub_4DE190`, size `0x110`; one code xref at `0x00538ba0` in `sub_538AF0`; decompile confirms `byte_69B420` guard, offsets `+0x4c/+0x50/+0x58/+0x5c`, palette category `11`, callback `unk_69B3E8`, and encoded-alpha helper. |
| GetSpriteBounds | `0x004de2a0` is `sub_4DE2A0`, size `0x132`; two code xrefs at `0x00538903` and `0x00538994`; decompile confirms `EFFECT%d.EPF`, `spriteGroup / 200`, `spriteGroup % 200`, legacy `EFFECT.EPD`, empty-rectangle path, and tile-centering offsets. |
| GetEffectInfo | `0x004de3e0` is `sub_4DE3E0`, size `0x40`; three code xrefs at `0x0050e33b`, `0x0050e89d`, and `0x005a2ef4`; decompile confirms one-based id, fallback at `this + 0x14`, descriptor pointer at `this[3]`, 52-byte stride, and three 16-byte copies plus final dword. |
| BuildEffectArchiveTable | `0x004de420` is `sub_4DE420`, size `0x3a2`; one code xref at `0x004de007` in the constructor; decompile confirms `EFFECT%d.EPF` scan capped at 100, DAT entry probing, 12-byte shard header buffers, archive metadata allocation, record packing, payload rebasing, and sentinel setup. |
| LoadEffectTables | `0x004de7d0` is `sub_4DE7D0`, size `0x453`; one code xref at `0x004ddffb` in the constructor; decompile confirms `EFFECT.TBL`, 52-byte descriptors, two 16-byte frame arrays, `EFFECT.FRM`, four-byte remap entries, and load/error byte writes. |
| Singleton clear helper | `0x004e5b70` is `sub_4E5B70`, size `0x0b`; body decompiles to `unk_69B44C = 0`; no callees; xref at `0x0060008a`; bytes are `c7 05 4c b4 69 00 00 00 00 00 c3`, followed by five `cc` bytes. |
| Scalar deleting destructor | `0x004e62f0` is `sub_4E62F0`, size `0x166`; prototype `char *__thiscall(char *Block, char)`; no direct callers; vtable data xref via `0x0061b724`; cleanup prefix matches ordinary destructor, then delete-helper predicate. |
| Vtable data | `0x0061b720/724/728/72c/730` read as `0x00648df4`, `0x004e62f0`, `0x004f4b10`, `0x0041b6c0`, `0x00648fc4`; xrefs to `0x0061b724` are constructor, ordinary destructor, scalar destructor. |
| Singleton storage | `0x0069b44c` bytes `00 00 00 00`, `u32le 0`; 12 direct xrefs: constructor publish/fallback null, ordinary/helper/scalar clears, shutdown read, map/effect/living consumers. |
| Resource strings | `0x0061c230` has one `EFFECT.TBL` loader xref at `0x004de867`; `0x0061c248` has one `EFFECT.FRM` loader xref at `0x004deb48`. |

### Score-Blocker Rework MCP Addendum

The 2026-06-30 targeted rework used the same live session and did not fall back to static-only evidence.

- `tools/list` call id `1` returned the schema-current tool set including `idb_list`, `server_health`, `decompile`, `xrefs_to`, `get_bytes`, and `get_int`.
- `idb_list` call id `3` returned active session `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker pid `17592`.
- `server_health` call id `4` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.
- `decompile` call id `6` on `0x004de2a0` proves `GetSpriteBounds` has a usable first-draft source body: EPF mode branches on `byte_66DA97 == 1`, formats `EFFECT%d.EPF`, divides/mods the frame id by `200`, uses legacy `EFFECT.EPD` otherwise, initializes an empty rectangle for negative frame ids, and offsets the result by `word_66DA9C / 2` and `word_66DAA0 / 2`.
- `decompile` call id `7` on `0x004de050` proves the destructor body is not a no-code exception: it iterates descriptors by `52` bytes, frees secondary frame arrays before primary frame arrays, clears counts/ranges, releases the archive metadata records/table, destroys the two protected-array buffers, clears `g_pEffectObjImageLib`, and falls through to base cleanup.
- `decompile` call id `8` on `0x004de190` proves `RenderEffectFrame` has a sourceable first draft: the caller context argument is stored but unused in the body, the second argument is the destination bounds/target region passed to both the primary frame-blit callback and encoded-alpha overlay, the `EffectPixMapInfo` remap is selected from offsets `+0x4c/+0x50` or fallback `+0x58`, `LoadFrameDrawRecord` reads from archive metadata at `+0x5c`, palette category `11` is used, `renderScalar > 0` builds a two-field alpha-parameter block, and overlay strength is `int(overlayStrength * 32.0 + 0.5)`.
- `decompile` calls `9` through `12` on `0x004d1600`, `0x00462f20`, `0x00457a60`, and `0x00543e40` support the renderer draft: `LoadFrameDrawRecord` fills a 40-byte `FrameDrawRecord`, `DrawEncodedAlphaFrame` consumes the destination bounds and source rectangle with replace/add/subtract mode, the initializer sets `FrameDrawRecord` defaults plus empty bounds, and palette lookup uses category/remap slots.
- `decompile` call id `13` on `0x004de7d0` resolves the loader blocker into first-draft C++: descriptor fields are read at `+0x00`, secondary count/range `+0x28/+0x2c/+0x30`, primary count/range `+0x10/+0x14/+0x18`, secondary records allocate from pointer `+0x1c`, primary records allocate from pointer `+0x04`, each `EffectFrameRecord` is read as int, int, float, int, and `EFFECT.FRM` resizes/loads one four-byte `EffectPixMapInfo` remap per entry with fallback `+0x58 = -1`.
- `decompile` call id `14` on `0x004de420` resolves the archive-builder blocker into first-draft C++: the incoming parameter is not read, the body scans `EFFECT%d.EPF` shards up to `100`, opens each shard through `DATFile`, merges per-shard headers into a 12-byte `ArchiveMetadataTable`, allocates `24 * (frameCount + 1)` record storage, rebases payload offsets by `DATFile::GetDataPointer()`, appends the zero-rectangle sentinel, and closes/frees temporary shard readers and header buffers.
- `decompile` call ids `15` through `17` on `0x00538af0`, `0x005388c0`, and `0x00538960` confirm the caller contract: `EffectObjectPane` forwards all four `EffectFrameRecord` fields to `RenderEffectFrame` and `GetSpriteBounds`; overlay gate/strength come from the render context at `a2 + 992` and `a2 + 988`; bounds helpers pass the same four fields plus an output `RectBounds`.

## Source Placement And Ownership

Keep direct source-file placement under [UID:0000IY] `NexusTK/render/EffectObjImageLib.cpp`.

Positive evidence:

- The constructor publishes `g_pEffectObjImageLib`, installs the class vtable, initializes `ProtectedArray<EffectInfo>` and `ProtectedArray<EffectPixMapInfo>`, calls the constructor-only loader/archive helpers, and validates `EFFECT.EPF` archive coverage.
- `LoadEffectTables` owns the `EFFECT.TBL` descriptor and `EFFECT.FRM` remap loaders.
- `RenderEffectFrame` reads only `EffectObjImageLib` resource fields and is called by `EffectObjectPane` as a consumer.
- `GetSpriteBounds` is a file-level helper in the same effect resource family; it has no `this` but only effect resource callers.
- `BuildEffectArchiveTable` has the same source-file owner because the only direct caller is the constructor and the archive family is `EFFECT%d.EPF`.
- Global/vtable/layout pages are source-declaration effects of the same class/file family.

Rejected alternatives:

- `Effects`, `EffectObjectPane`, and `MapPane` ownership is rejected. Their xrefs are consumer paths that schedule or render effects through `g_pEffectObjImageLib`; they do not own the `EFFECT.TBL`, `EFFECT.FRM`, `EFFECT.EPF`, palette remap, archive metadata, or descriptor array lifecycle.
- `ImageLib` ownership is rejected for this family. Shared image-library globals such as `ImageLibraryLoadErrorFlag` stay with broader ImageLib docs, but the effect resource loaders and frame draw path remain `EffectObjImageLib` participants.
- `ProtectedArray` ownership is rejected. The template owns reusable container mechanics; this file owns the `EffectInfo` and `EffectPixMapInfo` instantiations and data.
- Shared `EPFImageResources` or `ImageFrameTable` ownership is rejected for the current target. `BuildEffectArchiveTable` follows a shared pattern, but its only caller and resource strings are effect-specific.
- Raw vtable/global storage source is rejected. The compiler/linker should regenerate vtable/RTTI and global storage from declarations; memory pages should not hand-emit raw `.rdata` or duplicate `.data`.

## Exact Formal Insertion Text

The following blocks are the accepted formal `RECONSTRUCTION_CPP CODE` insertion text used for the implementation callback. Fenced blocks use `text` so sentinel lines are not treated as C++.

### [UID:00004A] `by-class/EffectObjImageLib.md`

Recommended metadata after callback:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:10
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00004A] EffectObjImageLib class ownership/layout marker.
// Exact type declarations and out-of-class method bodies are emitted by the member/type pages in this source family.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: do not emit a wrapper class around existing out-of-class child method definitions. The class page should document ownership and route children, not duplicate a declaration that would make generated output look more complete than current virtual/interface declarations support.

### [UID:00017L] `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md`

Recommended metadata after callback:

```text
COMPLETION:90
CONFIDENCE:92
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EffectObjImageLib::~EffectObjImageLib()
{
    for (int i = 0; i < effectInfoArray.count; ++i)
    {
        EffectInfo *info = &effectInfoArray.entries[i];

        if (info->secondaryFrames != 0)
        {
            delete [] info->secondaryFrames;
        }
        info->secondaryFrames = 0;
        info->secondaryFrameCount = 0;
        info->secondaryRangeStart = -1;
        info->secondaryRangeEnd = -1;

        if (info->primaryFrames != 0)
        {
            delete [] info->primaryFrames;
        }
        info->primaryFrames = 0;
        info->primaryFrameCount = 0;
        info->primaryRangeStart = -1;
        info->primaryRangeEnd = -1;
    }

    if (effectFileInfo != 0)
    {
        if (effectFileInfo->records != 0)
        {
            delete [] effectFileInfo->records;
        }
        delete effectFileInfo;
        effectFileInfo = 0;
    }

    g_pEffectObjImageLib = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: score-blocker rework call id `7` proves this is source-authored cleanup, not a no-code exception. The formal body uses current source-facing field names from `EffectInfo` and `ArchiveMetadataTable`: secondary frames are released before primary frames, counts are cleared, ranges reset to `-1`, archive record/table storage is released, and the singleton is cleared. The decompiled tail also contains compiler-lowered member/base destruction for `ProtectedArray<EffectPixMapInfo>`, `ProtectedArray<EffectInfo>`, and `LObject`; the source body above leaves that to C++ lowering rather than hand-emitting vtable writes.

### [UID:00017M] `by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md`

Recommended metadata after callback:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int EffectObjImageLib::RenderEffectFrame(
    MapPane *mapPaneOrRenderContext,
    RectBounds *destinationBounds,
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    AlphaMaskSurface *overlayMaskGate,
    float overlayStrength)
{
    (void)mapPaneOrRenderContext;
    (void)timerDelayAndRenderArg;
    (void)lightingAndRenderArg;

    int result = reinterpret_cast<int>(overlayMaskGate);
    if (g_imageLibraryLoadErrorFlag)
    {
        return result;
    }

    const EffectPixMapInfo *remap = &fallbackFrameRemap;
    if (frameResourceId >= 0 && frameResourceId < effectPixMapInfoArray.count)
    {
        remap = &effectPixMapInfoArray.entries[frameResourceId];
    }

    FrameDrawRecord frameRecord;
    frameRecord.reserved0 = 1;
    frameRecord.payloadStart = 0;
    frameRecord.reserved8 = 0;
    frameRecord.width = 0;
    InitRectBounds(&frameRecord.sourceRect, 0, 0, 0, 0);
    frameRecord.payloadSpan = 0;
    frameRecord.payloadEnd = 0;

    LoadFrameDrawRecord(effectFileInfo, static_cast<short>(frameResourceId), &frameRecord);

    void *palette = g_pPaletteLib->GetSlotPalette(11, remap->frameRemapOrPaletteSlot, 0);

    struct EffectRenderAlphaParams
    {
        unsigned char enabled;
        float scalar;
    };

    EffectRenderAlphaParams alphaParams;
    EffectRenderAlphaParams *alphaParamsPtr = 0;
    if (renderScalar > 0.0f)
    {
        alphaParams.enabled = 1;
        alphaParams.scalar = renderScalar;
        alphaParamsPtr = &alphaParams;
    }

    result = g_surfaceRenderCallbacks.primaryFrameBlit(
        &frameRecord,
        &frameRecord.sourceRect,
        destinationBounds,
        1,
        palette,
        alphaParamsPtr);

    if (overlayMaskGate != 0)
    {
        const unsigned char overlayByte =
            static_cast<unsigned char>(overlayStrength * 32.0f + 0.5f);

        return DrawEncodedAlphaFrame(
            overlayMaskGate,
            destinationBounds,
            &frameRecord,
            &frameRecord.sourceRect,
            destinationBounds->bottom,
            overlayByte,
            destinationBounds->top,
            0,
            1);
    }

    return result;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: score-blocker rework call ids `8`, `9`, `10`, `11`, `12`, and `15` resolve the prior blocker into first-draft source. The formal body is bounded to `0x004de190-0x004de29f`: it preserves the load-error guard return, remap/fallback selection, `FrameDrawRecord` initialization, archive-table projection, palette category `11`, optional render-scalar alpha block, primary frame-blit callback, and encoded-alpha overlay call. The second parameter is named `destinationBounds` because the sole caller passes it through and `DrawEncodedAlphaFrame` consumes its `top`/`bottom` endpoints (`a3[1]` and `a3[3]`); this supersedes the older review-only `drawTarget->field_04/field_0c` placeholders without pretending final callback typedef names are original symbols.

### [UID:0002HA] `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md`

Recommended metadata after callback:

```text
COMPLETION:90
CONFIDENCE:93
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EffectInfo *EffectObjImageLib::GetEffectInfo(EffectInfo *outInfo, int effectId)
{
    const int index = effectId - 1;
    if (index < 0 || index >= effectInfoArray.count)
    {
        *outInfo = effectInfoScratch;
    }
    else
    {
        *outInfo = effectInfoArray.entries[index];
    }

    return outInfo;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: current MCP proves a leaf method with 52-byte descriptor copy, one-based id, fallback scratch descriptor, descriptor array stride, return of the output pointer, and three direct consumers. `entries` remains the descriptive protected-array field name already used in support prose; exact original spelling caps confidence but does not block the first-draft body.

### [UID:0002HB] `by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md`

Recommended metadata after callback:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void EffectObjImageLib::LoadEffectTables()
{
    EffectInfo emptyInfo = {};
    effectInfoScratch = emptyInfo;

    DATFile effectTable;
    effectTable.Open(L"EFFECT.TBL");

    int effectCount = 0;
    if (!effectTable.ReadEncodedTableInt(&effectCount))
    {
        g_imageLibraryLoadErrorFlag = 1;
    }

    if (effectCount > 0)
    {
        effectInfoArray.Resize(effectCount);
    }

    for (int i = 0; i < effectCount; ++i)
    {
        EffectInfo info = {};

        int descriptorReads = 0;
        descriptorReads += effectTable.ReadEncodedTableInt(&info.effectKeyOrId);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryFrameCount);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryRangeStart);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryRangeEnd);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryFrameCount);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryRangeStart);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryRangeEnd);
        if (descriptorReads != 7)
        {
            g_imageLibraryLoadErrorFlag = 1;
        }

        if (info.secondaryFrameCount > 0)
        {
            info.secondaryFrames = new EffectFrameRecord[info.secondaryFrameCount];
            for (int frame = 0; frame < info.secondaryFrameCount; ++frame)
            {
                EffectFrameRecord *record = &info.secondaryFrames[frame];
                int frameReads = 0;
                frameReads += effectTable.ReadEncodedTableInt(&record->frameResourceId);
                frameReads += effectTable.ReadEncodedTableInt(&record->timerDelayAndRenderArg);
                frameReads += effectTable.ReadEncodedTableFloat(&record->renderScalar);
                frameReads += effectTable.ReadEncodedTableInt(&record->lightingAndRenderArg);
                if (frameReads != 4)
                {
                    g_imageLibraryLoadErrorFlag = 1;
                }
            }
        }

        if (info.primaryFrameCount > 0)
        {
            info.primaryFrames = new EffectFrameRecord[info.primaryFrameCount];
            for (int frame = 0; frame < info.primaryFrameCount; ++frame)
            {
                EffectFrameRecord *record = &info.primaryFrames[frame];
                int frameReads = 0;
                frameReads += effectTable.ReadEncodedTableInt(&record->frameResourceId);
                frameReads += effectTable.ReadEncodedTableInt(&record->timerDelayAndRenderArg);
                frameReads += effectTable.ReadEncodedTableFloat(&record->renderScalar);
                frameReads += effectTable.ReadEncodedTableInt(&record->lightingAndRenderArg);
                if (frameReads != 4)
                {
                    g_imageLibraryLoadErrorFlag = 1;
                }
            }
        }

        if (i >= 0 && i < effectInfoArray.count)
        {
            effectInfoArray.entries[i] = info;
        }
        else
        {
            effectInfoScratch = info;
        }
    }

    fallbackFrameRemap.frameRemapOrPaletteSlot = -1;

    DATFile frameTable;
    frameTable.Open(L"EFFECT.FRM");

    int frameRemapCount = 0;
    frameTable.Read(&frameRemapCount, sizeof(frameRemapCount));
    if (frameRemapCount > 0)
    {
        effectPixMapInfoArray.Resize(frameRemapCount);
    }

    for (int i = 0; i < frameRemapCount; ++i)
    {
        EffectPixMapInfo *remap =
            (i >= 0 && i < effectPixMapInfoArray.count)
                ? &effectPixMapInfoArray.entries[i]
                : &fallbackFrameRemap;
        frameTable.Read(remap, sizeof(*remap));
    }

    frameTable.Close();
    effectTable.Close();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: score-blocker rework call id `13` removes the marker-only blocker. The draft keeps the exact `EFFECT.TBL` / `EFFECT.FRM` split, `0x34` descriptor shape, seven descriptor integer reads, secondary sequence first and primary sequence second, `0x10` frame-record reads as int/int/float/int, `g_imageLibraryLoadErrorFlag` behavior when expected encoded reads fail, `ProtectedArray<T>::Resize` preservation semantics, fallback descriptor/remap handling, and one four-byte remap read per `EFFECT.FRM` entry. `ReadEncodedTableInt` and `ReadEncodedTableFloat` are the caller-side aliases already permitted by DATFile support docs for the `0x0049c4a0` / `0x0049c4f0` encoded table helpers.

### [UID:0002HC] `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md`

Recommended metadata: keep current `88/91`, owner/emitter `00004A`, blank optional position.

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002HC] MSVC scalar deleting destructor wrapper for EffectObjImageLib.
// Rebuilt from the virtual destructor declaration and delete-flag lowering; do not hand-emit a source wrapper body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: current MCP confirms the wrapper mirrors ordinary cleanup, has vtable-data linkage, and conditionally calls the delete helper. The source should be the ordinary virtual destructor, not a handwritten scalar-deleting wrapper.

### [UID:0001U9] `by-type/by-struct/EffectObjImageLibLayout.md`

Recommended metadata: keep current `86/89`, owner/emitter `00004A`, blank optional position.

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001U9] EffectObjImageLib object layout is emitted through the class/member declarations.
// Do not emit a duplicate EffectObjImageLibLayout structure.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: the page is layout evidence for the class, not a separate source type. It should not duplicate fields already represented by class/method/resource-record pages.

### [UID:0001XG] `by-type/by-vtable/EffectObjImageLibVtable.md`

Recommended metadata after callback:

```text
COMPLETION:85
CONFIDENCE:90
CANONICAL_OWNER:00004A
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004A
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001XG] EffectObjImageLib vtable/RTTI evidence only.
// MSVC regenerates this table from the EffectObjImageLib class declaration and virtual method set.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: the current page still says final C++ is blank under an old final-source gate. The better source-form is explicit no-raw-vtable output. Current MCP proves the slot dwords and three vptr-store refs.

### [UID:0000QT] `by-global/g_pEffectObjImageLib.md`

Recommended metadata after callback:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:4
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class EffectObjImageLib;

EffectObjImageLib *g_pEffectObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: current MCP proves the exact zero-initialized slot and lifecycle refs. The source-facing global declaration is mature enough; exact original symbol spelling remains medium-high rather than final-audit confidence.

### [UID:0001PQ] `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`

Recommended metadata: keep current `86/90`, owner/emitter `0000QT`, blank optional position.

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001PQ] Exact storage for g_pEffectObjImageLib is emitted by [UID:0000QT].
// This page documents the .data slot at 0x0069b44c and should not duplicate the global definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: memory page should not duplicate the semantic global definition.

### [UID:0000U4] `by-item/BuildEffectArchiveTable_004DE420.md`

Recommended metadata after callback:

```text
COMPLETION:89
CONFIDENCE:92
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ArchiveMetadataTable *BuildEffectArchiveTable(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct EffectArchiveShardHeader
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
        swprintf(archiveName, 20, L"EFFECT%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    EffectArchiveShardHeader *headers =
        shardCount > 0 ? new EffectArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"EFFECT%d.EPF", i);
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: score-blocker rework call id `14` proves this helper is sourceable with current support. The draft uses the accepted `ArchiveMetadataTable` / `PackedArchiveRecord` declarations, keeps the observed unused incoming parameter, scans `EFFECT%d.EPF` shards through `HasDATEntry` with the `100` cap, reads per-shard headers, allocates one extra sentinel record, converts raw top/left/bottom/right to `RectBounds`, rebases payload offsets through `DATFile::GetDataPointer()`, appends the zero-rectangle sentinel, and closes temporary `DATFile` readers. `EffectArchiveShardHeader` is a local first-draft source name for the eight bytes read from each shard header; final original field names remain confidence caps, not marker-only blockers.

### [UID:0000UR] `by-item/GetSpriteBounds_004DE2A0.md`

Recommended metadata after callback:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RectBounds *GetSpriteBounds(
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    RectBounds *outBounds)
{
    (void)timerDelayAndRenderArg;
    (void)renderScalar;
    (void)lightingAndRenderArg;

    if (frameResourceId < 0)
    {
        InitRectBounds(outBounds, 0, 0, 0, 0);
        return outBounds;
    }

    if (g_useEpfAssets == 1)
    {
        wchar_t archiveName[20];
        swprintf(archiveName, 20, L"EFFECT%d.EPF", frameResourceId / 200);
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            archiveName,
            static_cast<short>(frameResourceId % 200),
            outBounds);
    }
    else
    {
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            L"EFFECT.EPD",
            static_cast<short>(frameResourceId),
            outBounds);
    }

    OffsetRectBounds(outBounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
    return outBounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: score-blocker rework call ids `6`, `16`, and `17` prove a true first-draft body. The signature preserves the five pushed arguments while naming the first four from the `EffectFrameRecord` forwarding contract. The body keeps the negative empty-rectangle branch, EPF mode split, `EFFECT%d.EPF` shard math (`/ 200` and `% 200`), legacy `EFFECT.EPD` lookup, `g_pEPFLib` routing, and tile-center offset. `OffsetRectBounds` is the source-facing name for `sub_4B7E10`; final original helper spelling remains a confidence cap, not a reason to leave the target marker-only.

### [UID:00017W] `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md`

Recommended metadata: keep current `85/90`, owner/emitter `0000IY`, blank optional position.

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00017W] Compiler/static-lifetime cleanup helper that clears g_pEffectObjImageLib.
// Exact body is mov dword_69B44C, 0; ret; do not hand-emit ClearEffectObjImageLibSingleton().
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: matches accepted B003 cleanup policy and current MCP bytes/xref proof.

### [UID:0002MK] `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md`

Recommended metadata: keep current `86/91`, owner/emitter `0000IY`, blank optional position.

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002MK] EffectObjImageLib RTTI/vtable data is source-declared/generated-binary.
// The compiler emits equivalent .rdata from the EffectObjImageLib class declaration; do not hand-emit raw dwords.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: also repair the stale Item Summary phrase that still says there is a no-assignment gate. Current metadata and by-file support already establish assignment; the remaining action is source-form clarity.

### [UID:0001U7] `by-type/by-struct/EffectFrameRecord.md`

Recommended metadata after callback:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:1
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectFrameRecord
{
    int frameResourceId;
    int timerDelayAndRenderArg;
    float renderScalar;
    int lightingAndRenderArg;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: MCP and support docs prove the 16-byte POD read pattern and runtime consumption. Field names remain descriptive, so the score should not exceed first-draft confidence.

### [UID:0001U8] `by-type/by-struct/EffectInfo.md`

Recommended metadata after callback:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:2
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectInfo
{
    int effectKeyOrId;
    EffectFrameRecord *primaryFrames;
    int primaryUnknown0;
    unsigned char primaryFlagOrReserved;
    unsigned char primaryPadding[3];
    int primaryFrameCount;
    int primaryRangeStart;
    int primaryRangeEnd;
    EffectFrameRecord *secondaryFrames;
    int secondaryUnknown0;
    unsigned char secondaryFlagOrReserved;
    unsigned char secondaryPadding[3];
    int secondaryFrameCount;
    int secondaryRangeStart;
    int secondaryRangeEnd;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: current docs and MCP prove the exact 52-byte shape, two sequence headers, descriptor-copy behavior, loader/destructor offsets, and consumer selection. `primary`/`secondary` and scalar names are documentation terms, so score remains conservative.

### [UID:0001UA] `by-type/by-struct/EffectPixMapInfo.md`

Recommended metadata after callback:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000IY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IY
EMITTER_POSITION_OPTIONAL:3
```

Exact formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectPixMapInfo
{
    int frameRemapOrPaletteSlot;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale: MCP and support docs prove a one-dword `EFFECT.FRM` record consumed by palette category `11`. It may still be a typedef in original source, so keep completion below final-audit range.

## Target By-File Update Recommendation

For [UID:0000IY] `by-file/EffectObjImageLib.md` after implementation:

- Recommended score: `COMPLETION:90`, `CONFIDENCE:88`.
- Keep path `NexusTK/render/`.
- Preserve the existing UID0002H9 constructor implementation note.
- Add a new change entry for the UID0000IY family repair explaining that the 17 remaining empty markers were converted to first-draft code where source-quality is sufficient and marker-only comments where the source form is a compiler, layout, vtable, or storage artifact.
- Update generated-output caveat after validators with the real generated header, validator command id, freshness timestamp, and remaining empty markers if any.
- Correct any lingering old-code-gate language in touched support docs. The current implementation basis is the combined score/emitter/source-quality gate plus explicit no-code/source-form proof, not the old blanket `95/95` wording.
- In the owned-method table, spell ranges as half-open where exact pages already do so: `BuildEffectArchiveTable` is `0x004de420-0x004de7c2` half-open even though the filename-style inclusive end is `0x004de7c1`.

## Implementation Callback Results

Changed by-* docs:

- `by-file/EffectObjImageLib.md`
- `by-class/EffectObjImageLib.md`
- `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md`
- `by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md`
- `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md`
- `by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md`
- `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md`
- `by-type/by-struct/EffectObjImageLibLayout.md`
- `by-type/by-vtable/EffectObjImageLibVtable.md`
- `by-global/g_pEffectObjImageLib.md`
- `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md`
- `by-item/BuildEffectArchiveTable_004DE420.md`
- `by-item/GetSpriteBounds_004DE2A0.md`
- `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md`
- `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md`
- `by-type/by-struct/EffectFrameRecord.md`
- `by-type/by-struct/EffectInfo.md`
- `by-type/by-struct/EffectPixMapInfo.md`

Validator-owned generated refresh:

- `auto-generated/NexusTK/render/EffectObjImageLib.cpp` was refreshed by scoped validators, not manually edited.
- Final header is `validator-command-id: 000000002660`, `validator-refreshed-at: 2026-06-30T07:03:51-04:00`.
- Final generated file has no prior empty marker comments. It emits file-owned declarations/helpers and source-form markers, while class/global-owned child pages named in the generated-state section remain generator-suppressed.

Lease use:

- Initial broad edit lease command succeeded for all 18 by-* files at `2026-06-30T10:41:51Z`, expiring `2026-06-30T10:46:51Z`; after expiration, `unlease` reported `Rejected[No active lease]`, and the ledger was clear.
- Validation used per-file short leases. Each validation lease/unlease pair returned `Success`.
- Final support-prose repair leased `by-file/EffectObjImageLib.md`, `by-class/EffectObjImageLib.md`, and `by-type/by-struct/EffectObjImageLibLayout.md`; final `current_leases.md` reports `No active leases`.

Scoped validator results:

| File | Command id | Timestamp | Exit | OK | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/EffectObjImageLib.md` | `000000002660` | `2026-06-30T07:03:51-04:00` | 0 | 1 | Final by-file validation after generated-state wording; `--wait-generated` refreshed final generated file. |
| `by-class/EffectObjImageLib.md` | `000000002658` | `2026-06-30T07:01:56-04:00` | 0 | 1 | Final class validation after stale blocker wording repair. |
| `by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md` | `000000002639` | `2026-06-30T06:54:21-04:00` | 0 | 1 | Formal first-draft destructor body validated. |
| `by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md` | `000000002640` | `2026-06-30T06:54:32-04:00` | 0 | 1 | Formal first-draft render body validated. |
| `by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md` | `000000002641` | `2026-06-30T06:54:42-04:00` | 0 | 1 | Formal first-draft accessor body validated. |
| `by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md` | `000000002642` | `2026-06-30T06:54:52-04:00` | 0 | 1 | Formal first-draft loader body validated. |
| `by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md` | `000000002643` | `2026-06-30T06:55:03-04:00` | 0 | 1 | Compiler-wrapper marker validated. |
| `by-type/by-struct/EffectObjImageLibLayout.md` | `000000002659` | `2026-06-30T07:02:07-04:00` | 0 | 1 | Final layout validation after stale blocker wording repair. |
| `by-type/by-vtable/EffectObjImageLibVtable.md` | `000000002645` | `2026-06-30T06:55:25-04:00` | 0 | 1 | Vtable/RTTI marker validated. |
| `by-global/g_pEffectObjImageLib.md` | `000000002646` | `2026-06-30T06:55:35-04:00` | 0 | 1 | Global declaration validated. |
| `by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md` | `000000002647` | `2026-06-30T06:55:46-04:00` | 0 | 1 | No-duplicate-storage marker validated. |
| `by-item/BuildEffectArchiveTable_004DE420.md` | `000000002648` | `2026-06-30T06:55:58-04:00` | 0 | 1 | Formal archive-builder body validated. |
| `by-item/GetSpriteBounds_004DE2A0.md` | `000000002649` | `2026-06-30T06:56:08-04:00` | 0 | 1 | Formal bounds-helper body validated. |
| `by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md` | `000000002650` | `2026-06-30T06:56:19-04:00` | 0 | 1 | Cleanup-glue marker validated. |
| `by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md` | `000000002651` | `2026-06-30T06:56:30-04:00` | 0 | 1 | Raw-vtable-data marker and summary repair validated. |
| `by-type/by-struct/EffectFrameRecord.md` | `000000002652` | `2026-06-30T06:56:40-04:00` | 0 | 1 | POD declaration validated. |
| `by-type/by-struct/EffectInfo.md` | `000000002653` | `2026-06-30T06:56:51-04:00` | 0 | 1 | POD declaration validated. |
| `by-type/by-struct/EffectPixMapInfo.md` | `000000002654` | `2026-06-30T06:57:02-04:00` | 0 | 1 | One-field POD declaration validated. |

Warnings:

- Validators repeatedly reported unrelated `autogen_children_marker_missing` preferences for other by-class/by-global pages such as `DDError`, `ErrorMessage`, `FileError`, `HumanImageLib`, `StaticObjImageLib`, `MapTilePixelDimensions`, and UI globals. No target-specific warning or error was reported for the 18 changed by-* files.

Manual-edit exclusions:

- No IDA DB, generated report, manual `-coverage-report.md`, project-level report, validator/tool-state, executed archive, supervisor ledger, or lock file was manually edited.
- `auto-generated/NexusTK/render/EffectObjImageLib.cpp` changed only through validator-generated refresh.

## Claim And Incorporation Ledger

Implementation callback verification states are final for this B008 pass: `applied`, `already-present`, or `excluded-with-reason`. There are no blocked accepted claims.

| Claim ID | Claim | Evidence/confidence | Destination | Applied action | Verification state |
| --- | --- | --- | --- | --- | --- |
| C01 | UID0000IY family had 18 emitters, 1 filled and 17 empty before callback; UID0002H9 was the sole filled emitter. | Pre-callback generated header `000000002476`; final generated header `000000002660`. | UID0000IY by-file status/change note; generated-state section. | Generated-state caveat updated with pre/post state, emitted UIDs, suppressed child UIDs, and final freshness. | applied |
| C02 | Source placement remains `NexusTK/render/EffectObjImageLib.cpp`. | By-file path and ownership evidence retained; rejected owner moves preserved. | UID0000IY by-file and support docs. | Source placement unchanged; by-file score now `90/88`; no owner moved to Effects/MapPane/ImageLib/ProtectedArray/EPF docs. | already-present/applied |
| C03 | [UID:00004A] should not emit a full class wrapper now; use marker-only class ownership/layout text. | Marker now in formal block; class metadata `86/88`, position `10`. | `by-class/EffectObjImageLib.md`. | Applied exact marker and wording; validator `000000002658`, exit 0, ok 1. | applied |
| C04 | [UID:00017L] ordinary destructor is source-ready first-draft C++ rather than marker-only. | Formal destructor body present; score `90/92`. | destructor target. | Applied accepted body and rationale; validator `000000002639`, exit 0, ok 1. | applied |
| C05 | [UID:00017M] RenderEffectFrame is source-ready first-draft C++ with explicit callback/type caveats. | Formal render body present; score `88/91`; old review-only blocker text superseded. | render target. | Applied accepted body and caveat wording; validator `000000002640`, exit 0, ok 1. | applied |
| C06 | [UID:0002HA] GetEffectInfo is source-ready first-draft code. | Formal accessor body present; score `90/93`. | GetEffectInfo target. | Applied accepted body and stale gate repair; validator `000000002641`, exit 0, ok 1. | applied |
| C07 | [UID:0002HB] LoadEffectTables is source-ready first-draft C++ using current resource-record and DATFile support names. | Formal loader body present; score `90/91`. | LoadEffectTables target. | Applied accepted body and stale gate repair; validator `000000002642`, exit 0, ok 1. | applied |
| C08 | [UID:0002HC] scalar deleting destructor is generated-binary wrapper and should not be hand-emitted. | Compiler-wrapper marker present; score unchanged `88/91`. | scalar deleting destructor target. | Applied exact marker; validator `000000002643`, exit 0, ok 1. | applied |
| C09 | [UID:0001U9] layout page should not duplicate a source struct. | Covered-by-class/member marker present; score unchanged `86/89`. | layout target. | Applied exact marker and repaired stale blocker phrasing; final validator `000000002659`, exit 0, ok 1. | applied |
| C10 | [UID:0001XG] vtable page should emit no raw table, but should no longer be an empty marker. | Vtable/RTTI marker present; score `85/90`. | vtable target. | Applied exact marker and score; validator `000000002645`, exit 0, ok 1. | applied |
| C11 | [UID:0000QT] `g_pEffectObjImageLib` is ready for source global declaration. | Pointer definition present; score `88/90`; position `4`. | global target. | Applied declaration and metadata; validator `000000002646`, exit 0, ok 1. | applied |
| C12 | [UID:0001PQ] exact storage page should not duplicate the global definition. | Covered-storage marker present; score unchanged `86/90`; stale `0xffffffff` summary repaired. | storage target. | Applied exact marker and summary repair; validator `000000002647`, exit 0, ok 1. | applied |
| C13 | [UID:0000U4] BuildEffectArchiveTable is source-ready first-draft C++ with an explicit unused incoming-parameter caveat. | Formal archive-builder body present; score `89/92`. | item target. | Applied accepted body; validator `000000002648`, exit 0, ok 1. | applied |
| C14 | [UID:0000UR] GetSpriteBounds is source-ready first-draft C++ using the four-field EffectFrameRecord forwarding signature. | Formal bounds body present; score `88/91`. | item target. | Applied accepted body; validator `000000002649`, exit 0, ok 1. | applied |
| C15 | [UID:00017W] singleton clear helper should be marker-only generated cleanup glue. | Cleanup-glue marker present; score unchanged `85/90`. | helper target. | Applied exact marker; validator `000000002650`, exit 0, ok 1. | applied |
| C16 | [UID:0002MK] vtable data summary is stale and formal block should be raw-data marker. | Raw-data marker present; summary no longer says no-assignment gate; score unchanged `86/91`. | vtable-data target. | Applied exact marker and summary repair; validator `000000002651`, exit 0, ok 1. | applied |
| C17 | [UID:0001U7] EffectFrameRecord is ready for POD struct declaration. | Formal POD present; score `88/90`; position `1`. | EffectFrameRecord target. | Applied declaration and metadata; validator `000000002652`, exit 0, ok 1. | applied |
| C18 | [UID:0001U8] EffectInfo is ready for first-draft POD struct declaration with caveated names. | Formal POD present; score `88/90`; position `2`. | EffectInfo target. | Applied declaration and metadata; validator `000000002653`, exit 0, ok 1. | applied |
| C19 | [UID:0001UA] EffectPixMapInfo is ready for one-field POD declaration. | Formal one-field POD present; score `87/91`; position `3`. | EffectPixMapInfo target. | Applied declaration and metadata; validator `000000002654`, exit 0, ok 1. | applied |
| C20 | By-file UID0000IY should record family-level repair after implementation. | By-file status/change note updated; score `90/88`; generated caveat records final command `000000002660` state. | `by-file/EffectObjImageLib.md`. | Applied family repair text, exact range corrections, generated-suppression caveat; final validator `000000002660`, exit 0, ok 1. | applied |
| C21 | No IDA DB rename/type/comment work is required for this callback. | MCP evidence was read-only; no IDA DB files edited. | report/checklist. | No IDA DB edits performed. | excluded-with-reason |
| C22 | No generated, coverage-report, tracker, validator-state, executed archive, or ledger files should be manually edited. | User constraints and workflow. | report/checklist/callback. | No manual edits to forbidden files. `auto-generated/NexusTK/render/EffectObjImageLib.cpp` changed only by validator refresh as required by `--wait-generated`. | excluded-with-reason |

## Implementation Tracking Checklist

Report and callback checklist:

- [x] Read project-level `ntk-b-agent-workflow` skill and B008 `goal.md`. Proof: assignment and workflow requirements are reflected in this report and callback result section.
- [x] Verified MCP availability and used current schema calls. Proof: `server_health` status `ok`; MCP evidence section lists calls and results.
- [x] Re-read target by-file and current support docs. Proof: by-* edits were made against current content, preserving UID0002H9 and accepted B002/B003 wording while superseding stale blocker text.
- [x] Inventoried pre-callback generated empty markers and tracker state. Proof: current generated state section records pre-callback `000000002476`, 18 emitters, 1 filled, 17 empty.
- [x] Reanalyzed score-blocker targets [UID:00017L], [UID:00017M], [UID:0002HB], [UID:0000U4], and [UID:0000UR]. Proof: MCP addendum records decompile call ids `6` through `17`; target docs now carry formal first-draft C++.
- [x] Reanalyzed ownership/source placement and rejected alternatives. Proof: source placement remains `NexusTK/render/EffectObjImageLib.cpp`; rejected alternatives are preserved in report and by-file.
- [x] Supervisor validated this report and assigned implementation callback. Proof: implementation assignment `B008-implement-0000IY-EffectObjImageLib-empty-emitter-family-20260630`.
- [x] Checked leases before edit/validator batches. Proof: edit batch lease succeeded for 18 by-* docs; expired broad lease was cleared; per-file validation leases succeeded and were released.
- [x] Applied by-file UID0000IY update. Proof: by-file is `90/88`, records family disposition, final generated freshness, suppressed children, and exact range corrections.
- [x] Applied [UID:00004A] class marker. Proof: class is `86/88`, position `10`, with formal ownership/layout marker.
- [x] Applied all accepted formal blocks and metadata/score/position changes. Proof: rows C03-C20 list applied files, scores, validators, and formal/marker disposition.
- [x] Preserved UID0002H9 accepted constructor implementation. Proof: no constructor by-memory doc edit was made; by-file/class continue to reference the accepted constructor.
- [x] Repaired stale old-gate/no-assignment/blocker wording in touched docs. Proof: vtable data summary and render/layout/class stale blocker text were updated.
- [x] Ran scoped validators for every changed by-* file. Proof: validator table lists all 18 changed by-* docs, each with exit `0` and ok `1`.
- [x] Ran validators with `--wait-generated` and confirmed generated freshness. Proof: final `auto-generated/NexusTK/render/EffectObjImageLib.cpp` header is `validator-command-id: 000000002660`, `validator-refreshed-at: 2026-06-30T07:03:51-04:00`.
- [x] Updated this report's ledger from report-only states to final states. Proof: rows C01-C22 are now `applied`, `already-present/applied`, or `excluded-with-reason`; no blocked rows remain.
- [x] Updated this checklist with command ids, timestamps, exit codes, ok counts, warnings, generated-refresh state, changed files, and lease release proof. Proof: Implementation Callback Results section.
- [x] Confirmed forbidden manual edits were avoided. Proof: no manual generated/coverage/project-report/tool-state/IDA/archive/supervisor-ledger/lock edits; generated C++ changed only through validator refresh.

## Callback Coordination Note

EffectObjImageLib support docs had prior accepted B002/B003 edits and could have concurrent edits from other agents. B008 re-read current support docs before editing, preserved the accepted UID0002H9 constructor route, kept B002/B003 accepted evidence where still valid, and only superseded stale blocker/blank-C++ wording required by this callback. No active leases remain.

## Callback Compliance

Implementation callback completed for the accepted UID0000IY report. This report was updated in place and was not moved or executed by B008. Changed by-* docs and validator-owned generated refresh are listed above. No manual forbidden-file edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000IY-EffectObjImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000IY-EffectObjImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T13:10:34","uid":"0000IY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
