** TARGET-REPORT-UID:0000LR **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000LR] NewHumanImageLib Empty-Emitter Family Source-Quality Report

**ASSIGNMENT-ID:B011-report-0000LR-NewHumanImageLib-empty-emitter-family-20260701**  
**MODE:report-only research; no by-* implementation in this pass**

## Scope And Recommendation

Target family:

- Primary by-file: [UID:0000LR] `by-file/NewHumanImageLib.md`
- Generated output: `auto-generated/NexusTK/render/NewHumanImageLib.cpp`
- Current generated header inspected: `validator-command-id: 000000003290`, `validator-refreshed-at: 2026-07-01T04:46:53-04:00`
- Current generated row shape: 26 total routed emitters, 13 filled emitters, 13 empty emitter markers.

Recommendation: accept a first callback that removes all 13 empty markers with one source global, one best-defensible source helper body, and eleven formal no-code/comment dispositions. Revision resolves the returned [UID:0002VD] blocker in scope: `ResolveSpritePartPath` should emit first-draft formal C++ using the already accepted `ArchiveMetadataTable` / `PackedArchiveRecord` declarations, the accepted `BuildEffectArchiveTable` archive-builder source style, and the current DAT reader method vocabulary. The helper signature, DAT wrapper spelling, and table names remain source-facing inferred names, but they are now good enough for first-draft formal C++ rather than a future-pass blocker.

Recommended score changes:

| UID | File | Current | Recommended | Reason |
| --- | --- | ---: | ---: | --- |
| 0000LR | `by-file/NewHumanImageLib.md` | 87/85 | 90/89 | Family routing, ownership, and every empty-marker disposition are now callback-ready, including the resolver helper body. |
| 0000RT | `by-global/g_pNewHumanImageLib.md` | 87/91 | 88/92 | Live storage bytes/value and xrefs support the exact source singleton declaration. |
| 0000VA | `by-item/ResolveSpritePartPath_004E19D0.md` | 86/90 | 87/91 | Duplicate/item page can now point to the exact body emitter and remove stale helper-body-deferral wording. |
| 0002VD | `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md` | 86/90 | 89/91 | Current MCP plus accepted sibling archive-builder style support first-draft formal C++ for the exact helper. |
| 0001OV | `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md` | 87/92 | unchanged | Exact storage support page; source emission belongs to [UID:0000RT]. |
| 000182 | `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md` | 85/93 | 86/93 | Formal no-code disposition removes ambiguity for the tiny cleanup-table helper. |
| all other listed support docs | various | unchanged | Existing scores are adequate; the callback should add formal no-code proof, not inflate confidence. |

## Generated Empty-Marker Inventory

`auto-generated/NexusTK/render/NewHumanImageLib.cpp` currently has these empty markers:

| UID | Generated target | Current score | Disposition |
| --- | --- | ---: | --- |
| 000092 | `by-class/NewHumanImageLib.md` | 86/88 | Add formal comment-only aggregate-class no-code proof. Do not emit a partial class declaration. |
| 0002VN | `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md` | 86/91 | Add formal comment-only compiler-generated scalar deleting destructor proof. |
| 0001VF | `by-type/by-struct/NewHumanImageLibLayout.md` | 85/88 | Add formal comment-only layout-support proof. |
| 0001Y9 | `by-type/by-vtable/NewHumanImageLibVtable.md` | 86/90 | Add formal comment-only compiler-generated vtable proof. |
| 0000PK | `by-global/DestroyMotionVector.md` | 86/89 | Add formal comment-only global/index proof pointing to destructor-owned vector cleanup. |
| 0000TO | `by-global/VectorGrowMotion.md` | 86/88 | Add formal comment-only global/index proof pointing to `LoadMotionTable` push-back source. |
| 0000RT | `by-global/g_pNewHumanImageLib.md` | 87/91 | Emit source global `NewHumanImageLib *g_pNewHumanImageLib = 0;`. |
| 0001OV | `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md` | 87/92 | Add formal comment-only exact-storage proof pointing to [UID:0000RT]. |
| 0000VA | `by-item/ResolveSpritePartPath_004E19D0.md` | 86/90 | Add formal comment-only duplicate/item-page proof pointing to exact helper [UID:0002VD]; update stale body-deferral and `100`-shard wording. |
| 0002VD | `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md` | 86/90 | Emit best-defensible first-draft formal C++ for `ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)`. |
| 00017T | `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md` | 86/88 | Add formal comment-only exact compiler/STL grow-helper proof. |
| 000182 | `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md` | 85/93 | Add formal comment-only cleanup-table helper proof. |
| 000185 | `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md` | 86/89 | Add formal comment-only exact compiler/STL vector-cleanup proof. |

## MCP Evidence

Live MCP was available and responsive. Session health reported active `NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and string cache ready. One unsupported helper method (`py_eval`) returned `Method 'py_eval' not found`; this was not an MCP availability failure because equivalent read-only evidence was obtained through supported byte/global/value calls.

Current MCP facts used:

- `lookup_funcs` confirms exact function starts and sizes: `0x004e6870` size `0x38`, `0x004e19d0` size `0x557`, `0x004e5240` size `0x1d5`, `0x004e5dd0` size `0x69`, `0x004e5be0` size `0x0b`, plus current constructor/destructor/loaders in the same family.
- `xrefs_to 0x0061b76c` reports vtable stores from constructor/destructor only.
- `get_global_value` and `get_int` show `0x0067a760 == 0`; `get_bytes 0x0067a760 4` returns `00 00 00 00`.
- `xrefs_to 0x0067a760` reports 52 references, including constructor set/check, destructor clear/check, singleton clear helper, shutdown, and many render/UI consumers.
- `get_global_value` for the vtable slots confirms `0x0061b768 -> 0x006490f4`, `0x0061b76c -> 0x004e6870`, `0x0061b770 -> 0x004f4b10`, and `0x0061b774 -> 0x0041b6c0`.
- `analyze_function 0x004e6870` decompiles as a scalar deleting destructor wrapper: call ordinary destructor `sub_4E0250(Block)`, test delete flags, optionally call deallocator `sub_4F4AC0`, and return `Block`. No code callers; vtable data xref only.
- `analyze_function 0x004e5240` shows a 66-byte motion-entry vector growth helper called from `0x004e0ff2` in `LoadMotionTable`; it performs allocation/growth/copy/free logic, not source-authored NewHumanImageLib behavior.
- `analyze_function 0x004e5dd0` shows motion-vector cleanup called from the ordinary destructor and referenced from a cleanup table; it frees old vector storage and zeroes begin/end/capacity.
- `analyze_function 0x004e5be0` shows only `dword_67A760 = 0; return;` with no code callers and a cleanup-table xref.
- `decompile 0x004e19d0` confirms `ResolveSpritePartPath` behavior: numbered `%s%d.EPF` probing, fallback `%s.EPF`, DAT-backed reads, `0x0c` table header allocation, 24-byte record allocation, rectangle normalization, payload offset rebasing, sentinel record, and temporary reader cleanup. Direct code xrefs are only the constructor call at `0x004e00f0` and `LoadPartTable` call at `0x004e12fe`.
- 2026-07-01 revision MCP check through JSON-RPC `initialize` / `idb_list` / `server_health` / `lookup_funcs` / `xrefs_to` / `analyze_function` / `decompile` reconfirmed active session `supervisor_resume_20260629`, health `ok`, `sub_4E19D0` at `0x004e19d0` size `0x557`, `0x004e1f27` not a function, exactly two xrefs, and decompiler prototype `_DWORD *__stdcall(void *ArgList)`. The current decompile shows the numbered path counts consecutive `<base>%d.EPF` names with an unsigned-byte shard count and no explicit `100` cap; stale support wording that says this resolver scans up to `100` shards should be corrected to "consecutive numbered shards" with the unsigned-byte counter caveat.

## Existing Report And Doc Evidence

Targeted executed-report search was used as lead evidence, not as a substitute for live checks.

- B002 [UID:0002VN] accepted the scalar deleting destructor page as compiler-generated ABI glue. The source-level declaration is the virtual destructor plus ordinary destructor body, not a hand-authored scalar wrapper.
- B002 [UID:000419] accepted `NewHumanImageLib::LoadMotionTable`; the source-level vector operation is `m_motionEntries.push_back(...)`, while `VectorGrowMotion` is compiler/STL lowering.
- B010 [UID:00017S] accepted the ordinary destructor source body and confirms destructor-owned vector cleanup.
- B011 [UID:0002JR] accepted constructor source that sets `g_pNewHumanImageLib` and calls `ResolveSpritePartPath(part.name)`.
- B007 [UID:00041B] accepted `NewHumanImageLib::LoadPartTable` and documents the second resolver call site.
- [UID:0000UN] `EPFArchiveMetadataTable` now has formal inferred declarations for `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord`, but it still records inferred names and does not settle this helper's DAT wrapper/allocation contract.
- [UID:0000U4] `BuildEffectArchiveTable_004DE420.md` is the accepted sibling precedent for formal archive-table builder C++ using `ArchiveMetadataTable`, `PackedArchiveRecord`, `DATFile::Open`, `DATFile::Read`, `DATFile::Seek`, `DATFile::GetDataPointer`, `HasDATEntry`, and `InitRectBounds`. That removes the old objection that DAT wrapper spelling or table type names alone block every first-draft archive-builder body.

## Ownership And Source Placement

Ranked placement decisions:

1. [UID:0000LR] `NewHumanImageLib.cpp` remains the correct generated source root. The by-file page already has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, and all inspected empty emitters either belong to this file family or are compiler/data support for it.
2. [UID:0000RT] `g_pNewHumanImageLib` should emit as a source-level global in this file. Live bytes are zero, live value is null, and the constructor/destructor/helper/consumer xrefs prove a file-level singleton.
3. [UID:0001OV] is the exact storage address for that singleton and should not emit a second global. It should formally point to [UID:0000RT].
4. The vtable and scalar deleting destructor are compiler outputs from the class declaration and virtual destructor. Their docs should carry formal no-code proof, not synthetic vtable or wrapper source.
5. `VectorGrowMotion` and `DestroyMotionVector` are compiler/STL vector-management lowerings. Their source-level effects are already present in accepted `LoadMotionTable` and destructor bodies.
6. [UID:000182] is static cleanup-table glue that clears the singleton; the source-level state and lifecycle are represented by [UID:0000RT], constructor, and destructor.
7. [UID:0000VA] is an item/topic page for the exact helper [UID:0002VD], so it should not duplicate a body.
8. [UID:0002VD] should emit the exact source-authored resolver body in `NewHumanImageLib.cpp`; it is not a DATFileMgr helper because both direct callers are NewHumanImageLib constructor/part-loader paths and the helper builds new-human sprite part metadata.

Negative placement evidence:

- No MCP evidence supports moving the singleton, vector helpers, scalar wrapper, vtable, or resolver into generic DAT/archive source.
- `ResolveSpritePartPath` has only two direct callers, both in the NewHumanImageLib family. It is not a generic `DATArchive` helper despite using DAT APIs, and it should not be moved to `ImageFrameTable.cpp` because it formats caller-supplied new-human part names rather than shared old-human/effect/tile fixed prefix families.
- The vector grow/cleanup helpers have compiler allocation/free patterns and are not source-authored standalone algorithms.

## Heuristic And Inference Reanalysis

The current generated file's empty-marker heuristic correctly identified routed pages with blank formal blocks, but not every blank block means "needs C++ body." This family has four distinct cases:

- Source code ready: [UID:0000RT] should emit a real global declaration, and [UID:0002VD] should emit a first-draft resolver helper body.
- Compiler/generated artifact: scalar deleting destructor, vtable, vector grow, vector cleanup, and cleanup-table helper need formal no-code proof.
- Support/aggregate page: class aggregate, layout page, and exact singleton storage need formal comments that prevent duplicate or partial source emission.
- Duplicate/index page: [UID:0000VA] should stay a comment-only item page while [UID:0002VD] carries the exact resolver body.

The by-file score should improve because the family now has explicit implementation-ready dispositions for every empty marker. It must stay below final-source quality because the aggregate class declaration is still intentionally deferred and the resolver's helper/type names are inferred first-draft names rather than final original-source proof.

## ResolveSpritePartPath Blocker Resolution

The returned blocker is resolved by first-draft C++, not by a rare no-improvement exception.

Evidence routes attempted and accepted:

- Current MCP reconfirmed exact range, endpoint, two call sites, DAT lifecycle callees, filename literals, table allocation, record reads, payload rebasing, and sentinel behavior.
- [UID:0000UN] supplies formal `ArchiveMetadataTable` and `PackedArchiveRecord` declarations already used by accepted archive-table helper bodies.
- [UID:0000U4] supplies the closest accepted source-shape precedent: an EPF archive-table builder with provisional but formal C++ using `DATFile`, `HasDATEntry`, `InitRectBounds`, and `PackedArchiveRecord`.
- [UID:0002JR] and [UID:00041B] already emit call sites as `ResolveSpritePartPath(part.name)`, so the helper name/signature are coherent enough for a first-draft body.

Rejected routes:

| Route | Decision |
| --- | --- |
| Leave [UID:0002VD] blank as a future helper-body pass. | Rejected by supervisor direction and by score-blocker standard; current evidence is sufficient for first-draft C++. |
| Insert a comment-only no-code proof for [UID:0002VD]. | Rejected because the helper is source-authored and required by emitted call sites. |
| Move the body to `DATFileMgr.cpp` or `DATFile.cpp`. | Rejected because the helper builds new-human sprite-part metadata and has no direct non-NewHumanImageLib callers. |
| Move the body to `ImageFrameTable.cpp`. | Rejected because it is caller-specific to new-human part-name resources, unlike shared fixed-prefix image-frame loaders. |
| Paste raw decompiler-style C++ with `_DWORD`, `sub_`, vtable-slot calls, or manual scalar-deleting-destructor cleanup. | Rejected as not source-quality; the accepted sibling archive-builder style gives a better source-facing body while preserving behavior. |
| Keep stale `100`-shard wording. | Rejected for this resolver. Current MCP decompile shows an unsigned-byte shard count and no explicit `100` cap; `100` applies to sibling fixed-prefix builders such as `BuildEffectArchiveTable`, not this helper. |

## First-Draft C++ Readiness

Ready source C++ for [UID:0000RT]:

```cpp
NewHumanImageLib *g_pNewHumanImageLib = 0;
```

Ready source C++ for [UID:0002VD]:

```cpp
ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)
{
    struct SpritePartArchiveHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    wchar_t archiveName[20];
    swprintf(archiveName, 20, L"%s%d.EPF", baseName, 0);

    if (HasDATEntry(archiveName))
    {
        int probeIndex = 0;
        unsigned char shardCount = 0;
        do
        {
            ++probeIndex;
            ++shardCount;
            swprintf(archiveName, 20, L"%s%d.EPF", baseName, probeIndex);
        }
        while (HasDATEntry(archiveName));

        const int shardTotal = shardCount;
        SpritePartArchiveHeader *headers =
            shardTotal > 0 ? new SpritePartArchiveHeader[shardTotal] : 0;
        DATFile *archives = shardTotal > 0 ? new DATFile[shardTotal] : 0;

        ArchiveMetadataTable *table = new ArchiveMetadataTable;
        table->frameCount = 0;
        table->maxWidth = 0;
        table->maxHeight = 0;
        table->reserved = 0;
        table->records = 0;

        for (int i = 0; i < shardTotal; ++i)
        {
            swprintf(archiveName, 20, L"%s%d.EPF", baseName, i);
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

        for (int i = 0; i < shardTotal; ++i)
        {
            int recordTableOffset = 0;
            archives[i].Read(&recordTableOffset, sizeof(recordTableOffset));

            unsigned char *payloadBase = archives[i].GetDataPointer();
            lastPayloadBase = payloadBase;
            lastRecordTableOffset = recordTableOffset;

            archives[i].Seek(recordTableOffset, 1);

            for (int recordIndex = 0;
                 recordIndex < headers[i].frameCount;
                 ++recordIndex)
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

        for (int i = shardTotal - 1; i >= 0; --i)
        {
            archives[i].Close();
        }

        delete [] archives;
        delete [] headers;

        return table;
    }

    swprintf(archiveName, 20, L"%s.EPF", baseName);
    if (!HasDATEntry(archiveName))
    {
        return 0;
    }

    DATFile archive;
    archive.Open(archiveName);

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    archive.Read(table, 8);

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *outRecord = table->records;

    int recordTableOffset = 0;
    archive.Read(&recordTableOffset, sizeof(recordTableOffset));

    unsigned char *payloadBase = archive.GetDataPointer();
    archive.Seek(recordTableOffset, 1);

    for (int recordIndex = 0; recordIndex < table->frameCount; ++recordIndex)
    {
        short top = 0;
        short left = 0;
        short bottom = 0;
        short right = 0;
        int payloadStartOffset = 0;
        int payloadEndOffset = 0;

        archive.Read(&top, sizeof(top));
        archive.Read(&left, sizeof(left));
        archive.Read(&bottom, sizeof(bottom));
        archive.Read(&right, sizeof(right));
        archive.Read(&payloadStartOffset, sizeof(payloadStartOffset));
        archive.Read(&payloadEndOffset, sizeof(payloadEndOffset));

        InitRectBounds(&outRecord->bounds, left, top, right, bottom);
        outRecord->payloadStart = payloadBase + payloadStartOffset;
        outRecord->payloadEnd = payloadBase + payloadEndOffset;
        ++outRecord;
    }

    InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
    outRecord->payloadStart = payloadBase + recordTableOffset;
    outRecord->payloadEnd = payloadBase + recordTableOffset;

    archive.Close();
    return table;
}
```

Ready formal comment-only blocks:

```cpp
// NewHumanImageLib method bodies and data are emitted by exact child pages; the aggregate class declaration remains deferred until header/layout/helper declarations are source-ready.
```

```cpp
// Compiler-generated scalar deleting destructor for NewHumanImageLib; source reconstruction is represented by the virtual destructor declaration and [UID:00017S] ordinary destructor body.
```

```cpp
// NewHumanImageLib layout/type facts support the class and method emitters; no standalone source body is emitted from this layout page.
```

```cpp
// NewHumanImageLib vtable bytes are compiler-generated from the class declaration and virtual member definitions; no hand-authored vtable object is emitted here.
```

```cpp
// The source-level singleton declaration is emitted by [UID:0000RT] g_pNewHumanImageLib; this exact storage range is not hand-emitted separately.
```

```cpp
// ResolveSpritePartPath source-body ownership belongs to exact helper [UID:0002VD]; this item page does not emit a duplicate helper body.
```

```cpp
// Motion-table vector growth is emitted as m_motionEntries.push_back(...) in [UID:000419] NewHumanImageLib::LoadMotionTable; this compiler/STL grow helper is not hand-authored separately.
```

```cpp
// VectorGrowMotion is documented by exact helper [UID:00017T] and emitted source behavior lives in [UID:000419] NewHumanImageLib::LoadMotionTable; no duplicate global helper body is emitted here.
```

```cpp
// Motion-table vector cleanup is emitted by [UID:00017S] NewHumanImageLib::~NewHumanImageLib; this compiler/STL cleanup helper is not hand-authored separately.
```

```cpp
// DestroyMotionVector is documented by exact helper [UID:000185] and emitted source behavior lives in [UID:00017S] NewHumanImageLib::~NewHumanImageLib; no duplicate global helper body is emitted here.
```

```cpp
// Static cleanup glue clears g_pNewHumanImageLib through the cleanup table; source-level singleton state is emitted by [UID:0000RT] and lifecycle code, so this helper is not hand-authored separately.
```

The [UID:0002VD] body intentionally uses inferred source-facing names. It rejects raw `_DWORD`/vtable-slot/decompiler temporaries, but preserves the observed behavior: numbered probe first, single-archive fallback, 8-byte header read, separate record-table offset read, 24-byte packed records, `InitRectBounds(left, top, right, bottom)`, payload-pointer rebasing through `DATFile::GetDataPointer`, final sentinel, reverse close for numbered archives, and null return when no matching resource exists.

## Claim And Incorporation Ledger

| Claim/fact to preserve | Evidence | Destination/exclusion | Action | Verification state |
| --- | --- | --- | --- | --- |
| `NewHumanImageLib.cpp` remains the source root for this family. | `by-file/NewHumanImageLib.md` has valid `NexusTK/render/` path; generated file is current at command `000000003431`; all direct helper call sites are NewHumanImageLib-family. | `by-file/NewHumanImageLib.md` status/changes; generated freshness check after callback. | incorporate | applied |
| Family has 13 empty markers, and all 13 now have callback-ready dispositions. | Generated inventory plus current docs, current revision MCP reanalysis, accepted sibling archive-builder precedent, and final generated empty-marker count `0`. | `by-file/NewHumanImageLib.md`; callback checklist; generated freshness proof. | incorporate | applied |
| `g_pNewHumanImageLib` storage is zero/null, not `0xffffffff`. | MCP `get_bytes 0x0067a760 4` -> `00 00 00 00`; `get_global_value/get_int` -> `0`; docs now preserve zero/null language. | `by-global/g_pNewHumanImageLib.md`; `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`; by-file summary. | incorporate | applied |
| Source global should be `NewHumanImageLib *g_pNewHumanImageLib = 0;`. | Zero storage, 52 xrefs, constructor/destructor/lifecycle usage; generated file line contains the declaration after command `000000003431`. | Formal multiline block in `by-global/g_pNewHumanImageLib.md`. | incorporate | applied |
| Exact singleton storage page should not emit a duplicate global. | Same bytes/value as global page; exact storage page routes to [UID:0000RT]. | Formal comment in `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`. | incorporate | applied |
| Scalar deleting destructor is compiler-generated ABI glue, not hand-authored source. | MCP decompile calls ordinary destructor then optional deallocator; only vtable data xref; B002 accepted report. | Formal comment in `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`. | incorporate | applied |
| Vtable bytes are compiler-generated from class declaration/virtual methods. | MCP vtable slot values and constructor/destructor vptr stores; no source-authored data object evidence. | Formal comment in `by-type/by-vtable/NewHumanImageLibVtable.md`. | incorporate | applied |
| Class aggregate page should not emit partial class declaration. | Current class doc defers coherent class block; child method bodies already emit. | Formal comment in `by-class/NewHumanImageLib.md`. | incorporate | applied |
| Layout page supports declarations but should not emit standalone body. | Current layout doc is support/type evidence; no standalone source body. | Formal comment in `by-type/by-struct/NewHumanImageLibLayout.md`. | incorporate | applied |
| `VectorGrowMotion` is compiler/STL vector growth, source effect is `m_motionEntries.push_back(...)`. | MCP vector grow decompile and single caller in [UID:000419]; B002 accepted `LoadMotionTable`. | Formal comments in `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md` and `by-global/VectorGrowMotion.md`. | incorporate | applied |
| `DestroyMotionVector` is compiler/STL cleanup, source effect belongs to destructor. | MCP cleanup decompile, destructor caller, cleanup-table ref; B010 accepted destructor. | Formal comments in `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md` and `by-global/DestroyMotionVector.md`. | incorporate | applied |
| Singleton clear helper is cleanup-table glue, not standalone hand-authored source. | MCP decompile only assigns `dword_67A760 = 0`; cleanup-table xref only. | Formal comment and score bump in `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md`. | incorporate | applied |
| Resolver item page should not duplicate exact helper body. | [UID:0000VA] and [UID:0002VD] describe the same address/function; exact page now carries the first-draft body. | Formal comment and stale-deferral cleanup in `by-item/ResolveSpritePartPath_004E19D0.md`. | incorporate | applied |
| Resolver exact helper should emit first-draft formal C++ as `ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)`. | Current MCP confirms exact behavior; [UID:0000UN] supplies the table/record declarations; accepted [UID:0000U4] body proves this archive-builder source style is acceptable with inferred names; generated file line contains the function after command `000000003431`. | Formal multiline block, status, score, and changes in `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`. | incorporate | applied |
| Stale `ResolveSpritePartPath` wording that says the numbered path scans up to `100` shards should be corrected. | Current MCP decompile shows an unsigned-byte shard counter and no explicit `100` cap; `100` is a sibling fixed-prefix builder pattern. | `by-item/ResolveSpritePartPath_004E19D0.md`; `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`; by-file support note if present. | reject-stale | applied |
| Comment-only suppression for [UID:0002VD] is invalid. | The helper has emitted constructor/part-loader call sites and real DAT-backed table construction behavior. | Report body and checklist; exact helper formal block now contains first-draft C++, not a no-code comment. | reject-invalid | applied |
| Old Wave2/Wave3 material should not drive this callback. | Goal file override; current MCP and current by-* docs are sufficient. | Report evidence discipline only. | reject-stale | applied |

## Implementation Tracking Checklist

Implementation callback applied on 2026-07-01.  The single-line `RECONSTRUCTION_CPP CODE:[[[]]]` header values were left unchanged; accepted bodies/comments were inserted into the multiline formal blocks.

- [x] `by-file/NewHumanImageLib.md`: scores changed to `90/89`; Changes/status prose records the empty-emitter-family callback, 13 marker dispositions, [UID:0002VD] first-draft resolver body, and stale `100`-shard correction. Validator: `python .\tools\validator.py --mode file --file by-file\NewHumanImageLib.md --apply --wait-generated` -> command `000000003396`, timestamp `2026-07-01T05:31:49-04:00`, `ok: 1`.
- [x] `by-global/g_pNewHumanImageLib.md`: scores changed to `88/92`; formal block emits `NewHumanImageLib *g_pNewHumanImageLib = 0;`; zero/null prose preserved. Validator: command `000000003397`, timestamp `2026-07-01T05:32:00-04:00`, `ok: 1`.
- [x] `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`: scores kept `87/92`; formal block has the storage-only no-duplicate comment; stale `0xffffffff` wording remains absent and zero/null evidence is preserved. Validator: command `000000003398`, timestamp `2026-07-01T05:32:10-04:00`, `ok: 1`.
- [x] `by-class/NewHumanImageLib.md`: scores kept `86/88`; formal block has the aggregate no-standalone-source comment; prose now says comment-only rather than blank. Validator: command `000000003399`, timestamp `2026-07-01T05:32:21-04:00`, `ok: 1`.
- [x] `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`: scores kept `86/91`; formal block has the compiler-generated scalar-deleting destructor comment; current prose now says comment-only. Validator: command `000000003401`, timestamp `2026-07-01T05:32:31-04:00`, `ok: 1`.
- [x] `by-type/by-struct/NewHumanImageLibLayout.md`: scores kept `85/88`; formal block has the layout/type-support no-standalone-source comment; current prose now says comment-only. Validator: command `000000003402`, timestamp `2026-07-01T05:32:41-04:00`, `ok: 1`.
- [x] `by-type/by-vtable/NewHumanImageLibVtable.md`: scores kept `86/90`; formal block has the compiler-generated vtable/no-hand-authored-object comment. Validator: command `000000003404`, timestamp `2026-07-01T05:32:52-04:00`, `ok: 1`.
- [x] `by-global/VectorGrowMotion.md`: scores kept `86/88`; formal block has the accepted no-duplicate global-helper comment. Validator: command `000000003405`, timestamp `2026-07-01T05:33:02-04:00`, `ok: 1`.
- [x] `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`: scores kept `86/88`; formal block has the accepted compiler/STL grow-helper comment. Validator: command `000000003407`, timestamp `2026-07-01T05:33:13-04:00`, `ok: 1`.
- [x] `by-global/DestroyMotionVector.md`: scores kept `86/89`; formal block has the accepted no-duplicate cleanup-helper comment. Validator: command `000000003409`, timestamp `2026-07-01T05:33:24-04:00`, `ok: 1`.
- [x] `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md`: scores kept `86/89`; formal block has the accepted compiler/STL cleanup-helper comment. Validator: command `000000003410`, timestamp `2026-07-01T05:33:36-04:00`, `ok: 1`.
- [x] `by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md`: completion changed to `86`, confidence kept `93`; formal block has the accepted cleanup-table glue comment. Validator: command `000000003411`, timestamp `2026-07-01T05:33:47-04:00`, `ok: 1`.
- [x] `by-item/ResolveSpritePartPath_004E19D0.md`: scores changed to `87/91`; formal block has the accepted no-duplicate item comment; stale helper-body deferral and fixed-`100` shard wording were removed. Validator: command `000000003412`, timestamp `2026-07-01T05:33:57-04:00`, `ok: 1`.
- [x] `by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md`: scores changed to `89/91`; formal block has the accepted `ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)` body; blocker language is historicalized and stale `100`-shard assumptions are corrected. Validator: command `000000003414`, timestamp `2026-07-01T05:34:08-04:00`, `ok: 1`.
- [x] Final generated refresh: `python .\tools\validator.py --mode autogen --apply --wait-generated` -> command `000000003415`, timestamp `2026-07-01T05:34:19-04:00`, generated refresh command `000000003415`.
- [x] Generated output proof: `auto-generated/NexusTK/render/NewHumanImageLib.cpp` header now has `validator-command-id: 000000003431` and `validator-refreshed-at: 2026-07-01T05:37:44-04:00`; it contains `NewHumanImageLib *g_pNewHumanImageLib = 0;`, `ArchiveMetadataTable *ResolveSpritePartPath(const wchar_t *baseName)`, the direct generated marker comments for this file route, and `Empty Emitter Marker` count is `0`.  The storage/layout/vtable/scalar wrapper formal comments are validated in their by-* docs but are not separate direct file entries under the current generator child routing.
- [x] B011 leases released after validation with `python .\leaser.py B011 unlease`; all 14 target paths returned `Success`.
- [x] Supervisor-owned coverage/tracker action remains validator-owned only. No generated reports, project-level reports, manual coverage reports, queue/state files, archives, supervisor ledgers, by-project-structure docs, generated C++ files, or IDA DB were manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000LR-NewHumanImageLib-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000LR-NewHumanImageLib-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T05:39:25","uid":"0000LR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
