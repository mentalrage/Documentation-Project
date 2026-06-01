*** UID:0001VD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib Layout

## Status

- Confidence: strong for observed offsets, medium for final field names.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Evidence: IDA constructor/destructor/cache-loader decompilation and xrefs on 2026-05-26.

## Layout

```text
MonsterImageLib
  +0x00  LObject/vtable
  +0x04  MonsterImageEntry* monsterEntries
  +0x08  uint32 monsterEntryCount
  +0x0c  unknown/reserved dword
  +0x10  uint32* archiveOffsetsBegin
  +0x14  uint32* archiveOffsetsEnd
  +0x18  uint32* archiveOffsetsCapacity
  +0x1c  DATIndexVector openArchiveIndex
  +0x3c  DATIndexVector boundsBucketIndex
```

`DATIndexVector` is 0x20 bytes in the current recovered layout. The two embedded instances are initialized by the constructor, consumed by `GetArchiveBoundsBucket`, and destroyed by both ordinary and scalar destructor paths.

## Notes

- The constructor writes [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), constructs the `LObject` base, stores the [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md), zeros the archive-offset vector, initializes both embedded cache/index tables, then calls `LoadMonsterTables` and `LoadMonsterArchives`.
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) fills the 0x0c-byte [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) vector and the monster table count from `MONSTER.DNA` or `MONSTER.DND`.
- `LoadMonsterArchives` scans `DATA/MON%d.DAT` archive files, opens entries through DAT helpers, and appends frame/archive offsets to the vector at `+0x10`.
- `GetArchiveBoundsBucket` uses the `+0x1c` index for opened archive readers and the `+0x3c` index for cached [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records.
- `ClearLoadedData` walks and frees both cache/index lists, including open archive readers and bounds buckets, then resets their table state.
- The ordinary and scalar deleting destructors free table entries, destroy both index tables, release the archive-offset vector, call `LObject` cleanup, and clear the singleton.

## IDA Verification Notes

- 2026-05-31 IDA MCP `decompile 0x004daec0` confirms constructor writes singleton `dword_69B440`, calls the `LObject` base constructor, stores `MonsterImageLib::vftable`, initializes the archive-offset vector at `this[4..6]` (`+0x10..+0x18`), initializes the first embedded index at `this[7..12]` (`+0x1c..+0x30`), initializes the second embedded index at `this[15..20]` (`+0x3c..+0x50`), then calls table/archive loaders.
- 2026-05-31 IDA MCP `decompile 0x004dbe60` confirms `GetArchiveBoundsBucket` searches and inserts through `this + 0x3c` for bounds buckets and inserts opened archive readers through `this + 0x1c`.
- 2026-05-31 IDA MCP `decompile 0x004dc2e0` confirms cleanup walks list state at `this + 0x20/+0x24` for opened archive readers, resets the first index through `sub_423B00(this + 0x1c, 8)`, then walks list state at `this + 0x40/+0x44` for bounds buckets, frees bucket entry arrays, and resets the second index through `sub_423B00(this + 0x3c, 8)`.
- 2026-05-31 IDA MCP `decompile 0x004db010` confirms the ordinary destructor calls `ClearLoadedData`, destroys both embedded index tables through `sub_4573D0(this + 15)` and `sub_4573D0(this + 7)`, releases the `+0x10` vector, calls `LObject` cleanup, and clears the singleton.
- Scores stay below `95` because final field names, all method-side field uses, and the exact source declaration have not been fully audited.

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

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `78`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified constructor, destructor, cache-loader, and cleanup use of the singleton, vtable, archive-offset vector, and two embedded DATIndexVector-style indexes at `+0x1c` and `+0x3c`. Scores remain below `95` because source-level field names and every downstream method use are not yet exhaustively audited.
