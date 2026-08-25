*** UID:0000U6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ArchiveMetadataTable *BuildTilecArchiveTable(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct TilecArchiveShardHeader
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
        swprintf(archiveName, 20, L"TILEC%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    TilecArchiveShardHeader *headers =
        shardCount > 0 ? new TilecArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"TILEC%d.EPF", i);
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
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BuildTilecArchiveTable 0x004dda60

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Autogen parent: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Memory range: `0x004dda60-0x004dde01`
- Current source form: first-draft formal C++ ready and emitted through this page.

## Function Role

`BuildTilecArchiveTable` scans numbered `TILEC%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record. IDA decompilation matches the `LoadTileEpfMetadata` pattern: probe up to 100 shards, allocate temporary DAT readers/headers, accumulate total entries and max metrics, then emit one contiguous merged metadata table.

IDA xrefs show one caller: `StaticObjImageLib::StaticObjImageLib`.

B010's 2026-07-01 implementation callback resolves the previous blank-C++ blocker. The remaining unknowns are original spellings, not behavior or source placement. The source-facing names `ArchiveMetadataTable`, `PackedArchiveRecord`, `DATFile`, `HasDATEntry`, `InitRectBounds`, and `DATFile::GetDataPointer` are already accepted project vocabulary through [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md), and the neighboring [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) implementation. This helper remains StaticObjImageLib-owned because current xrefs still show only the constructor call at `0x004dd0f0`.

## Live IDA MCP Evidence

Rechecked on 2026-06-14 with live IDA MCP session `b001_0002bd`:

- `server_health` reports active `NexusTK.exe.i64`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reconfirms `sub_4DDA60` at `0x004dda60`, size `0x3a2` / 930 bytes (Verified with int_convert.py), immediately inside the [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) local cluster.
- `xrefs_to 0x004dda60` reports exactly one code xref, from `0x004dd0f0` inside `sub_4DCF60` / `StaticObjImageLib::StaticObjImageLib`.
- `get_bytes 0x004dda50` shows `0xcc` padding before the `0x004dda60` prologue, and `get_bytes 0x004dddf0` shows the `retn 4` tail at the end of `sub_4DDA60`, padding through `0x004dde0f`, and successor function prologue at `0x004dde10`.
- Hex-Rays decompilation reconfirms the wide `TILEC%d.EPF` shard probe loop with limit `0x64` / 100 (Verified with int_convert.py), buffer count `0x14` / 20 (Verified with int_convert.py), temporary `0x0c` / 12-byte (Verified with int_convert.py) per-shard header allocation, merged `0x18` / 24-byte (Verified with int_convert.py) output records, one terminal sentinel record, and cleanup of every temporary archive reader/header.
- `callees 0x004dda60` reconfirms the helper uses string formatting, DAT-entry probing, DAT/archive reader construction/open/read/seek/size helpers, rectangle/metadata packing helper `0x004b7c50`, allocation/free routines, and security-cookie cleanup. This supports StaticObjImageLib ownership and a shared EPF-table pattern without proving a separate common source owner.

Rechecked on 2026-06-16 with live IDA MCP session `b001_mappane_0001AW_20260616`:

- IDA DB labels were saved for `sub_4DDA60 -> BuildTilecArchiveTable` and `sub_4DCF60 -> StaticObjImageLib_Constructor`; after-save lookup reports `BuildTilecArchiveTable` size `0x3a2` and `StaticObjImageLib_Constructor` size `0x278`.
- `xrefs_to 0x004dda60` still reports exactly one code xref from `0x004dd0f0` inside `StaticObjImageLib_Constructor`, so owner/emitter remains [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- `lookup_funcs 0x004dde10` still reports the successor loader function, preserving the `0x004dde02-0x004dde10` padding/split boundary after the Tilec builder.
- Hex-Rays still shows the `TILEC%d.EPF` loop capped at 100 shards, temporary archive/header allocation, merged 24-byte metadata table plus sentinel, offset rebasing, and cleanup. The saved name is source-quality for this helper role, but individual table fields and any common EPF-loader consolidation are still unresolved.

Rechecked by B010 on 2026-07-01 with live IDA MCP session `supervisor_resume_20260629`:

- `server_health` reported `status=ok`, auto-analysis ready, Hex-Rays ready, and one active IDB session.
- `lookup_funcs 0x004dda60` reports `sub_4DDA60`, size `0x3a2`; neighboring StaticObjImageLib family functions resolve at their expected exact starts.
- `xrefs_to 0x004dda60` reports one code xref from `0x004dd0f0` inside `sub_4DCF60`, preserving the StaticObjImageLib constructor-only source route.
- `analyze_function 0x004dda60` reports size 930, 44 basic blocks, cyclomatic complexity 18, and callees for allocation, DAT-entry probing, DAT/archive reader construction/open/read/seek/payload-base access, rectangle initialization, cleanup, free, and security-cookie check.
- `decompile 0x004dda60` reconfirms the `TILEC%d.EPF` scan, 100-shard cap, 20-wchar name buffer, stop on first missing shard, 8-byte shard-header reads into 12-byte temporary headers, accumulated `frameCount`/max metrics, `24 * (frameCount + 1)` merged record allocation, raw `top/left/bottom/right` record reads, `InitRectBounds` conversion, DAT payload-base rebasing, terminal zero-rectangle sentinel using the last shard base plus record-table offset, reverse close, and temporary cleanup.
- `decompile 0x004dcf60` confirms the modern constructor path stores the returned table at `StaticObjImageLib +0x04` and that legacy mode still uses the shared `LoadImageFrameTable` route.

## Ownership Decision

Keep this with `render/StaticObjImageLib.cpp`. The shared EPF archive-table declarations live in [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md), but the helper body is asset-specific: it builds the static-object `TILEC%d.EPF` metadata table and has a single StaticObjImageLib constructor caller. A future shared-loader consolidation would have to preserve that source route and is not a reason to leave this current emitter blank.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 89 | The page now records saved IDA names, current function size, caller, byte boundaries, decompiled table-building steps, key constants with int_convert verification, helper dependencies, owner context, the accepted first-draft formal C++ body, and the rejected shared-owner/no-code alternatives. |
| Confidence | 91 | Live IDA agrees with the StaticObjImageLib cluster and EPFImageResources docs: the helper has one constructor caller, stable boundaries, and behavior matching the `TILEC%d.EPF` metadata merge path. Confidence remains below final-audit quality because exact original helper/local/type spellings remain inferred. |
| Reconstructable | true | Source-authored StaticObjImageLib helper code. B010's accepted report resolves the previous blank-C++ blocker by emitting first-draft formal C++ using accepted archive-table support names. |

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and stale generated-source wording was removed.
  - Before: the TILEC archive-table builder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned source under the validated StaticObjImageLib file root; C++ remains blank because table field names and final helper signature are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4DDA60` at `0x004dda60`, size `0x3a2`, one direct caller in `sub_4DCF60`, and the same EPF archive-table loader shape as the already assigned tile/effect table builders.

- 2026-06-14 C001 live-evidence refresh:
  - Before: score was `78/86`; ownership and high-level behavior were documented, but current byte-boundary, callee, and constant evidence was not written on the item page.
  - After: score is `86/88`; ownership, emitter route, and blank reconstruction C++ are unchanged.
  - Evidence: live IDA MCP session `b001_0002bd` reconfirmed function size `0x3a2` / 930 bytes (Verified with int_convert.py), the single constructor caller at `0x004dd0f0`, padding before `0x004dda60` and before successor `0x004dde10`, the `TILEC%d.EPF` probe loop to `0x64` / 100 shards (Verified with int_convert.py), 12-byte temporary headers, 24-byte merged metadata records, sentinel append, DAT/archive-reader callees, and cleanup behavior. No IDA DB change or final C++ was made because final source names and table fields remain provisional.

- 2026-06-16 C001 item/IDA refresh:
  - Before: score was `86/88`; the page had strong behavior evidence but still used generic IDA names.
  - After: score is `87/90`; owner/emitter route and blank reconstruction C++ are unchanged.
  - IDA DB changes saved to `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`: `sub_4DDA60 -> BuildTilecArchiveTable` and `sub_4DCF60 -> StaticObjImageLib_Constructor`.
  - Evidence: after-save lookup verified the saved labels and unchanged sizes; `xrefs_to 0x004dda60` still reports only the constructor call at `0x004dd0f0`; the successor `0x004dde10` loader boundary remains separate; Hex-Rays still proves the Tilec shard scan, 24-byte merged table records, sentinel append, offset rebasing, and cleanup. Final table field names/common-loader consolidation remain unresolved.

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented TILEC archive-table behavior, one caller, and owner decision but remained unevaluated.
  - After: score reflects documented shard scan, metadata merge/rebase/sentinel behavior, and `StaticObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: IDA xrefs show one caller from `StaticObjImageLib::StaticObjImageLib`; decompilation matches the shared EPF archive-table pattern.
- 2026-07-01 B010 StaticObjImageLib empty-emitter family implementation:
  - Raised from `87/90` to `89/91` and populated first-draft formal C++.
  - Summary/evidence: B010's accepted report used live MCP session `supervisor_resume_20260629`, the current generated file, current EPF support docs, and the accepted sibling [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) source form. The implementation preserves the single constructor caller at `0x004dd0f0`, `TILEC%d.EPF` resource ownership, 100-shard cap, 20-wchar name buffer, 8-byte shard headers, `frameCount + 1` packed record allocation, raw bounds conversion through `InitRectBounds`, DAT payload rebasing, sentinel row, reverse close, and cleanup. Remaining original-name uncertainty is documented as a confidence cap rather than a no-code blocker.
