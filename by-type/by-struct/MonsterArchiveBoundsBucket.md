*** UID:0001VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterArchiveBoundsBucket

## Status

- Confidence: strong for object size and entry pointer, medium for exact header field names.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: 0x0c bytes.
- Evidence: IDA decompilation of `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`.

## Layout

```text
MonsterArchiveBoundsBucket
  +0x00  uint16 entryCount
  +0x02  uint16 header02
  +0x04  uint32 header04
  +0x08  MonsterArchiveBoundsEntry* entries
```

## Notes

- The loader allocates 0x0c bytes for the bucket, reads the first eight bytes directly from the `DATA/MON%d.DAT` archive, and then stores the heap-allocated entry array at `+0x08`.
- The loader allocates `(entryCount + 1)` [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md) rows. The extra row is a zero-bounds sentinel whose payload start/end point at the archive payload base plus a separately read payload-start offset.
- The bucket is cached in the [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) `+0x3c` `DATIndexVector` instance and keyed by archive id.
- Current generated disabled output names the two middle header fields `reserved` and `reserved04`; keep those field names provisional until the DAT payload format is fully decoded.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs 0x004dbe60` reports `sub_4DBE60` at `0x004dbe60` with size `0x315`, giving an exact end at `0x004dc174`.
- IDA MCP decompilation/disassembly of `0x004dbe60` shows `operator new(0x0c)` for the bucket at `0x004dbfa6`, then insertion of `(archiveId, bucketPointer)` into the `this + 0x3c` cache before any bucket payload is read.
- The DAT reader virtual call at `0x004dc01d` reads exactly 8 bytes into the bucket, and the later write at `0x004dc03f` stores the allocated entry array pointer at bucket offset `+0x08`.
- The entry allocation at `0x004dc02e` computes `(entryCount + 1) * 0x18`, proving the bucket's first field is a 16-bit count consumed from the just-read header.
- Scores stay below `95` because the two middle header fields are still semantically unnamed and the surrounding `DATA/MON%d.DAT` format is not fully decoded.

## Cross-References

- [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `76`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the exact loader function boundary, 0x0c bucket allocation, 8-byte header read, `+0x08` entry pointer write, `(entryCount + 1) * 0x18` entry allocation, and `this + 0x3c` cache ownership. Scores remain below `95` because the non-count header fields and full archive format semantics are still provisional.
