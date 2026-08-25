*** UID:0000U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BuildEffectArchiveTable 0x004de420

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Owner/emitter: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Memory range: `0x004de420-0x004de7c2`
- Current IDA label: `BuildEffectArchiveTable` saved on 2026-06-16.

## Function Role

`BuildEffectArchiveTable` scans numbered `EFFECT%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record.

IDA xrefs show one caller: `EffectObjImageLib::EffectObjImageLib` at `0x004de007`.

The body follows the same per-asset archive-table pattern as the tile and static-object builders: probe up to 100 numbered archive shards, allocate temporary DAT readers and per-shard headers, accumulate total frame count and max metrics, allocate one contiguous record table plus a sentinel, and rebase each record's payload offsets by the owning `DATFile` payload pointer.

## Live IDA Evidence

Checked on 2026-06-06:

- `lookup_funcs` reports IDA `sub_4DE420` at `0x004de420`, size `0x3a2`; `0x004de7c2` is not a function, and the next function is `sub_4DE7D0` at `0x004de7d0`.
- `callers(0x004de420)` reports one direct caller, `0x004de007` inside [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md).
- The decompile reports `_DWORD *__stdcall sub_4DE420(int a1)` and shows a formatted `EFFECT%d.EPF` probe loop through `sub_41B9B0` plus [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), stopping at the first missing numbered archive or after 100 probes.
- The helper allocates an array of per-shard 12-byte header buffers and an array of temporary `DATFile` objects, opens each `EFFECT%d.EPF` shard through the DAT vtable open slot, and reads the first eight header bytes before accumulating the shard entry count and max metric fields.
- The returned table is a 12-byte header plus `24 * (entryCount + 1)` bytes of packed records. Each raw record is read as four 16-bit bounds fields plus two 32-bit payload offsets, normalized through `InitRectBounds` (`0x004b7c50`), and rebased by `DATFile::GetDataPointer` (`sub_49C550`).
- The final record is a zero-rectangle sentinel. Its start/end payload offsets are both set to the last shard data pointer plus the record-table offset read from that shard, matching [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md).
- Cleanup walks opened temporary `DATFile` objects in reverse, closes/destroys them, frees per-shard header storage and pointer arrays, destructs the stack DAT helper, and returns the merged table pointer.

Checked again on 2026-06-14 with live IDA MCP session `a001_goal2_class_batch`:

- `lookup_funcs` reconfirmed `0x004de420` size `0x3a2`; `0x004de7c2` is still not a function, and the next modeled helper remains `0x004de7d0` size `0x453`.
- `analyze_function 0x004de420` reports one caller and 14 callees; `xrefs_to 0x004de420` still reports the sole constructor call at `0x004de007`.
- Targeted decompilation reconfirmed the `EFFECT%d.EPF` candidate formatter, shard probe loop capped at `100 == 0x64` (verified with `int_convert.py`), existence probing through `0x0049c700`, record allocation as `24 * (entryCount + 1)` where `24 == 0x18` (verified with `int_convert.py`), record/sentinel rectangle setup through `0x004b7c50`, and payload-base rebasing through `DATFile::GetDataPointer` at `0x0049c550`.

Checked again on 2026-06-16 with live IDA MCP session `b001_0001KM_20260616`:

- `lookup_funcs` still reported `sub_4DE420` size `0x3a2`; `analyze_function` reported prototype `_DWORD *__stdcall(int)`, one caller `sub_4DDF60`, 14 callees, and xref `0x004de007`.
- The decompiler reconfirmed the `L"EFFECT%d.EPF"` scan, the `i < 100` probe cap, `HasDATEntry_49C700` probing, temporary `DATFile` construction, 12-byte header buffers, allocation helpers, `DATFile::GetDataPointer` rebasing, rectangle setup, and cleanup helper/free paths.
- Dry-run rename accepted `sub_4DE420 -> BuildEffectArchiveTable`; C001 applied the function label, saved `NexusTK.exe.i64`, and post-save `lookup_funcs` verified the label at `0x004de420`.

## Callee Inventory

IDA MCP `callees(0x004de420)` reports the expected EPF archive-table builder family:

| Callee | Current interpretation |
| --- | --- |
| `sub_41B9B0` | Wide formatted path construction for `EFFECT%d.EPF`. |
| [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) / `0x0049c700` | Numbered shard existence probe. |
| `sub_49C130`, `sub_49C160`, `sub_49C550` | `DATFile` construction/destruction and payload-base access. |
| `sub_516030`, `sub_516050`, `operator new`, `j_j_j___free_base` | Memory-manager allocation and temporary-array cleanup. |
| `sub_4B7C50` | 16-byte rectangle initialization for each packed record and sentinel. |
| DAT vtable read/seek/open/close slots | Opens numbered archives, reads header/record data, and seeks to the raw record table. |

## Ownership Decision

Keep this with `render/EffectObjImageLib.cpp` unless the shared EPF archive-table loaders are later consolidated into `render/ImageFrameTable.cpp`.

## Score Rationale

- Completion is now `89` because the page records exact half-open bounds, single constructor caller, shard probe limit, DATFile lifecycle, merged header/record allocation shape, raw-to-packed record conversion, payload rebasing, sentinel semantics, cleanup flow, owner/emitter route, current IDA refresh, saved entry label, and formal first-draft C++.
- Confidence is now `92` because repeated live IDA evidence matches the neighboring tile/static archive-table builders and the shared [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) layout, and the low-risk entry label is saved. Confidence remains below final audit because the original helper signature, final table type names, and exact by-memory promotion are still unresolved.

## Source-Quality Decision

The function label is safe: current xrefs prove one constructor caller from EffectObjImageLib, and decompilation proves effect archive table construction from `EFFECT%d.EPF` shards. B008's callback attaches first-draft C++ because the source-owned archive-table behavior is no longer a marker-only blocker. The helper signature, local DAT helper spellings, and final `EPFArchiveMetadataTable` source type spelling remain provisional.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)

## Changes

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `86/91`, formal C++ blank despite source-owned archive-table behavior.
  - After: `89/92`, formal first-draft C++ attached under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, and score-blocker rework evidence to preserve the sole constructor caller at `0x004de007`, `EFFECT%d.EPF` probe cap `100`, `HasDATEntry` stop condition, per-shard header reads, merged frame count/max metrics, `24 * (entryCount + 1)` record allocation, `DATFile::GetDataPointer` payload rebasing, zero-rectangle sentinel, reverse close/free cleanup, and rejected consolidation into unrelated shared archive owners.

- 2026-06-06 A002 live IDA evidence pass:
  - Before: the page was `78/86`, described the archive merge only at a high level, and still used the old `0x004de7c1` end spelling.
  - After: raised to `82/88`, corrected the half-open range to `0x004de420-0x004de7c2`, and documented live caller/callee, shard-probe, allocation, record-packing, sentinel, and cleanup evidence.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, and decompilation on 2026-06-06 confirm the `0x3a2`-byte helper, one constructor caller, `EFFECT%d.EPF` probe loop, DATFile temporary readers, 12-byte table header, `24 * (entryCount + 1)` record allocation, payload rebasing through `DATFile::GetDataPointer`, zero-rectangle sentinel, and cleanup sequence. B008's 2026-06-30 callback later attached formal first-draft C++.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and stale generated-source wording was removed.
  - Before: the effect archive-table builder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned source under the validated EffectObjImageLib file root. B008's 2026-06-30 callback later attached formal first-draft C++ while preserving final table-type and field-name caveats.
  - Evidence: live IDA MCP confirms `sub_4DE420` at `0x004de420`, size `0x3a2`, one direct caller in `sub_4DDF60`, and archive/table-related callees including `0x0049c700`, `0x0049c160`, `0x0049c550`, `0x00516030`, and `0x00516050`.

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented effect archive table behavior, one caller, shared EPF pattern, and owner decision but remained unevaluated.
  - After: score reflects documented scan/merge/rebase/sentinel behavior and strong `EffectObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: xrefs show the sole caller from `EffectObjImageLib::EffectObjImageLib`; behavior matches the linked EPF archive metadata table/resource docs.
- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had a strong 2026-06-06 pass but still used legacy parent/final-code wording and lacked a current verification of endpoint and record constants.
  - After: added current live IDA evidence, refreshed score rationale, and kept C++ blank pending source-quality table names and exact memory promotion.
  - Evidence: `lookup_funcs`, `analyze_function`, `xrefs_to`, and targeted decompile checks reconfirmed the endpoint, sole constructor caller, `EFFECT%d.EPF` shard scan, `0x64` probe cap, `0x18` record allocation, `DATFile` payload-base rebasing, and zero-rectangle sentinel setup.

- 2026-06-16 C001 safe IDA refresh: Raised from `85/90` to `86/91`.
  - Before: the item had strong current ownership and behavior evidence, but IDA still named the entry `sub_4DE420`.
  - After: saved the `BuildEffectArchiveTable` IDA function label, recorded current caller/callee/decompile evidence, and kept owner/emitter route through [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Prototype/type/local changes and final C++ remain unsafe pending final table type names and exact source signature.
  - Evidence: IDA MCP `lookup_funcs`, `analyze_function`, `rename` dry-run/apply, `idb_save`, and post-save `lookup_funcs` on 2026-06-16.
