*** UID:0001VD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MonsterImageLibLayout is an evidence page for the concrete MonsterImageLib
// object layout. Do not emit a duplicate ABI struct; source declarations belong
// on [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and exact child pages.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib Layout

## Status

- Confidence: strong for observed offsets, owner class, cache/table/vector roles, and direct parent placement; medium for final field names and the inactive `+0x0c` gap.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Assignment: attached to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) after this layout reached `86/90` and the direct class parent is `85/85`; the source file parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`.
- Formal C++: emits an evidence-only no-duplicate-layout marker. This page must not declare a separate `MonsterImageLibLayout` ABI struct because the fields belong to the actual `MonsterImageLib` class.
- Evidence: IDA constructor/destructor/archive-loader/cache-loader/cleanup decompilation and xrefs through 2026-06-11.

## Layout

```text
MonsterImageLib
  +0x00  LObject/vtable
  +0x04  MonsterImageEntry* m_monsters        (older alias: monsterEntries)
  +0x08  uint32 m_monsterCount                (older alias: monsterEntryCount)
  +0x0c  reserved/unobserved dword gap
  +0x10  uint32* m_archiveOffsets.begin       (older alias: archiveOffsetsBegin)
  +0x14  uint32* m_archiveOffsets.end         (older alias: archiveOffsetsEnd)
  +0x18  uint32* m_archiveOffsets.capacity    (older alias: archiveOffsetsCapacity)
  +0x1c  DATIndexVector m_openArchiveIndex    (older alias: openArchiveIndex)
  +0x3c  DATIndexVector m_boundsBucketIndex   (older alias: boundsBucketIndex)
```

`DATIndexVector` is 0x20 bytes in the current recovered layout. The two embedded instances are initialized by the constructor, consumed by `GetArchiveBoundsBucket`, cleared by `ClearLoadedData`, and destroyed by both ordinary and scalar destructor paths.

## Field Evidence

| Offset | Current name | Evidence-backed role | Remaining caveat |
| --- | --- | --- | --- |
| `+0x00` | `LObject/vtable` | Constructor calls the base initializer then stores the [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md); ordinary/scalar destructors restore the same vtable before cleanup. | Final base-class declaration details remain in the common `LObject` docs. |
| `+0x04` | `m_monsters` | [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) stores the 0x0c [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) vector pointer here; [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) now emits `delete[] m_monsters`, which lowers to the row destructor `0x00528950` and array free. | Older alias `monsterEntries` remains useful for search/history. Exact original member spelling is inferred. |
| `+0x08` | `m_monsterCount` | `LoadMonsterTables` stores the row count here after reading `MONSTER.DNA`/`MONSTER.DND`; render/table lookup pages use this as the bounds check for entry selection. | Older alias `monsterEntryCount` remains useful. Exact signedness/source typedef remains provisional. |
| `+0x0c` | `reservedOrUnobservedGap` | The constructor, table loader summary, destructor, archive loader, lazy bounds loader, and cleanup paths do not currently show a live access here; it separates the entry count from the archive-offset vector triplet. | Keep neutral until a direct use or original declaration proves whether this is padding, reserved state, or an unmodeled field. |
| `+0x10/+0x14/+0x18` | `m_archiveOffsets` internals (`begin/end/capacity`) | Constructor zeroes `this[4..6]`; `LoadMonsterArchives` appends 4-byte cumulative archive offsets through this vector and its slow path [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md); [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) records the free/zero as compiler-emitted member destruction, not handwritten destructor C++. | Older aliases `archiveOffsetsBegin/End/Capacity` remain useful. Exact container declaration remains inferred vector-like storage. |
| `+0x1c` | `m_openArchiveIndex` | Constructor initializes `this[7..12]` as a DATIndexVector-style instance; `GetArchiveBoundsBucket` inserts opened `DATA/MON%d.DAT` archive readers through `this + 7`; `ClearLoadedData` walks `this + 0x20/+0x24` list state and resets `this + 0x1c`; destructor compiler-emits `DATIndexVector::~DATIndexVector`. | Older alias `openArchiveIndex` remains useful. Embedded helper layout is documented by [UID:00003K][DATIndexVector](by-class/DATIndexVector.md), whose final field split remains provisional. |
| `+0x3c` | `m_boundsBucketIndex` | Constructor initializes `this[15..20]`; `GetArchiveBoundsBucket` finds/inserts [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records through `this + 15`; `ClearLoadedData` frees bucket entry arrays, clears `this + 0x40/+0x44` list state, and resets `this + 0x3c`; destructor compiler-emits `DATIndexVector::~DATIndexVector`. | Older alias `boundsBucketIndex` remains useful. Same DATIndexVector helper caveat as the open-archive index. |

## Notes

- The constructor writes [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), constructs the `LObject` base, stores the [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md), zeros the archive-offset vector, initializes both embedded cache/index tables, then calls `LoadMonsterTables` and `LoadMonsterArchives`.
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) fills the 0x0c-byte [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) vector and the monster table count from `MONSTER.DNA` or `MONSTER.DND`.
- `LoadMonsterArchives` scans `DATA/MON%d.DAT` archive files, opens entries through DAT helpers, and appends frame/archive offsets to the vector at `+0x10`.
- `GetArchiveBoundsBucket` uses the `+0x1c` index for opened archive readers and the `+0x3c` index for cached [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records.
- `ClearLoadedData` walks and frees both cache/index lists, including open archive readers and bounds buckets, then resets their table state.
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) now emits the ordinary destructor body as `ClearLoadedData(); delete[] m_monsters;`. The ordinary and scalar deleting destructor binaries also destroy both index tables, release `m_archiveOffsets`, call `LObject` cleanup, and clear the singleton, but those are compiler-lowered member/base/static-lifetime teardown effects rather than source statements in the target destructor body.
- The current evidence does not justify treating `+0x0c` as an active member. It is left as a reserved/unobserved gap rather than a named field.

## IDA Verification Notes

- 2026-05-31 IDA MCP `decompile 0x004daec0` confirms constructor writes singleton `dword_69B440`, calls the `LObject` base constructor, stores `MonsterImageLib::vftable`, initializes the archive-offset vector at `this[4..6]` (`+0x10..+0x18`), initializes the first embedded index at `this[7..12]` (`+0x1c..+0x30`), initializes the second embedded index at `this[15..20]` (`+0x3c..+0x50`), then calls table/archive loaders.
- 2026-05-31 IDA MCP `decompile 0x004dbe60` confirms `GetArchiveBoundsBucket` searches and inserts through `this + 0x3c` for bounds buckets and inserts opened archive readers through `this + 0x1c`.
- 2026-05-31 IDA MCP `decompile 0x004dc2e0` confirms cleanup walks list state at `this + 0x20/+0x24` for opened archive readers, resets the first index through `sub_423B00(this + 0x1c, 8)`, then walks list state at `this + 0x40/+0x44` for bounds buckets, frees bucket entry arrays, and resets the second index through `sub_423B00(this + 0x3c, 8)`.
- 2026-05-31 IDA MCP `decompile 0x004db010` confirms the ordinary destructor calls `ClearLoadedData`, destroys both embedded index tables through `sub_4573D0(this + 15)` and `sub_4573D0(this + 7)`, releases the `+0x10` vector, calls `LObject` cleanup, and clears the singleton.
- 2026-06-11 live IDA MCP `lookup_funcs` reconfirmed the layout-bearing functions: constructor `0x004daec0` size `0x14e`, ordinary destructor `0x004db010` size `0xe7`, `LoadMonsterArchives` `0x004dbc60` size `0x19b`, `GetArchiveBoundsBucket` `0x004dbe60` size `0x315`, `ClearLoadedData` `0x004dc2e0` size `0x135`, and scalar deleting destructor `0x004e6750` size `0x110`.
- 2026-06-11 live IDA MCP `xrefs_to` reconfirmed one constructor caller at `0x004f60c7`, no direct callers to the ordinary destructor, `GetArchiveBoundsBucket` callers at `0x004db647`, `0x004dc1b9`, and `0x004dc279`, `ClearLoadedData` callers at `0x004db03c`, `0x004e6783`, and `0x00505054`, and vtable writes/uses at `0x004daf16`, `0x004db036`, and `0x004e677d`.
- 2026-06-11 decompilation of `LoadMonsterArchives` shows the archive-offset vector passed as `this + 4` (`+0x10`) and using `this[5]`/`this[6]` for end/capacity; the slow path calls [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) when `end == capacity`.
- 2026-06-25 B011 live MCP rechecked [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md), its scalar peer, `ClearLoadedData`, constructor setup, `DATIndexVector` destructor, `MonsterImageEntry` row destructor, and [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md). The target now uses the source-facing member names `m_monsters`, `m_monsterCount`, `m_archiveOffsets`, `m_openArchiveIndex`, and `m_boundsBucketIndex`, with older aliases preserved as search/history terms.
- 2026-06-27 B003 live MCP session `80de0a67` rechecked [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) and reconfirmed the paired cache roles: the method inserts opened `DATA/MON%d.DAT` readers through `m_openArchiveIndex` at `+0x1c`, finds/inserts [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) through `m_boundsBucketIndex` at `+0x3c`, and cleanup later frees/clears both indexes through `ClearLoadedData`.
- The 2026-06-27 pass also reconfirmed that `+0x0c` remains unobserved in constructor, loader, destructor, archive-loader, lazy bounds-loader, and cleanup paths. Keep it as a reserved/unobserved gap until direct access or original declarations prove a field name.
- Scores stay below `95` because final field names, all method-side field uses, and the exact source declaration have not been fully audited.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md). This layout page is `86/90`, the direct class parent is `85/85`, and the file parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`.

The relationship is direct: this by-struct page describes the concrete object layout of the `MonsterImageLib` class. [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) remains a reusable embedded helper, not the semantic owner of the `MonsterImageLib` object layout. The source file page is the next parent in the chain, not the direct by-struct parent.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The page now records the full observed object field map, constructor initialization, table-loader entry vector, archive-offset vector append path, two embedded DATIndexVector cache roles, destructor/cleanup ownership, singleton/vtable context, direct parent chain, explicit `+0x0c` caveat, and formal no-duplicate-ABI-struct marker. |
| Confidence | 90 | Confidence is strong because constructor, table loader, archive loader, lazy bounds loader, clear-loaded-data, ordinary destructor, scalar destructor, vtable xrefs, and singleton xrefs agree on the same offsets. It remains below final-source confidence because original member names, DATIndexVector subfield names, and the `+0x0c` gap are not fully recovered. |

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `86/90` to `87/90`.
  - Evidence: inserted the formal evidence-only layout marker rejecting a duplicate `MonsterImageLibLayout` ABI struct. Preserved object field map, constructor/destructor/archive-loader/cache-loader evidence, `+0x0c` unobserved caveat, DATIndexVector helper caveat, and class/child source-declaration route.
- 2026-06-27 B003 GetArchiveBoundsBucket support sync:
  - Score unchanged at `86/90`.
  - Evidence: added live MCP session `80de0a67` confirmation that [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) uses `m_openArchiveIndex` at `+0x1c` for opened archive readers and `m_boundsBucketIndex` at `+0x3c` for cached bounds buckets, while `+0x0c` remains unobserved. Original member spelling and DATIndexVector subfield names remain below final-audit certainty.
- 2026-06-25 B011 destructor implementation callback:
  - Score unchanged at `86/90`.
  - Evidence: synchronized member names with accepted destructor C++ and loader C++. `+0x04` is now `m_monsters`, `+0x08` is `m_monsterCount`, `+0x10/+0x14/+0x18` are `m_archiveOffsets` internals, `+0x1c` is `m_openArchiveIndex`, and `+0x3c` is `m_boundsBucketIndex`, with older aliases preserved. Added the destructor source-shape distinction that `delete[] m_monsters` is handwritten source while archive-offset/index/base/singleton teardown is compiler-lowered.
- 2026-06-11 A001 strict-gate assignment:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank, and no assignment gate or field-evidence table.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, and `AUTOGEN_PARENT_UID:00008N`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/archive/cache function sizes, singleton/vtable xrefs, constructor initialization of `+0x10..+0x18`, `+0x1c`, and `+0x3c`, `LoadMonsterArchives` use of the archive-offset vector and `VectorGrowArchiveIndex`, `GetArchiveBoundsBucket` use of the two DATIndexVector-style caches, and `ClearLoadedData`/destructor cleanup ownership. The direct class parent [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) is `85/85`, and the file parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`, so the strict child/direct-parent gate clears.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `78`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified constructor, destructor, cache-loader, and cleanup use of the singleton, vtable, archive-offset vector, and two embedded DATIndexVector-style indexes at `+0x1c` and `+0x3c`. Scores remain below `95` because source-level field names and every downstream method use are not yet exhaustively audited.
