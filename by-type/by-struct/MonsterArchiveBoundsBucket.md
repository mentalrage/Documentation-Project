*** UID:0001VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MonsterArchiveBoundsBucket
{
    unsigned short entryCount;
    unsigned short maxExtent02;
    unsigned short maxExtent04;
    unsigned short header06;
    MonsterArchiveBoundsEntry *entries;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterArchiveBoundsBucket

## Status

- Confidence: strong for object size, entry count, entry pointer, allocation/caching behavior, cleanup ownership, `MonsterImageLib` use, and the active role of the two middle 16-bit header metrics; medium for exact source field names and full archive payload semantics.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Size: 0x0c bytes.
- Evidence: IDA decompilation of `MonsterImageLib::GetArchiveBoundsBucket` at `0x004dbe60`, the unreferenced aggregate builder at `0x004db8b0`, the cache resolver at `0x004dc180`, the render-bounds consumer at `0x004db5c0`, and cleanup at `0x004dc2e0`.
- Assignment status: assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md). B001-032 repaired the child to `86/90`; the direct owner class is now `85/85` and its file parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) is `86/86`.
- Formal C++: emits the 12-byte source-facing bucket declaration through the MonsterImageLib class route.

## Layout

```text
MonsterArchiveBoundsBucket
  +0x00  uint16 entryCount
  +0x02  uint16 maxExtent02
  +0x04  uint16 maxExtent04
  +0x06  uint16 header06
  +0x08  MonsterArchiveBoundsEntry* entries
```

## Field Evidence

| Offset | Current name | Evidence-backed role | Remaining caveat |
| --- | --- | --- | --- |
| `+0x00` | `entryCount` | Consumed after the 8-byte header read to allocate `(entryCount + 1) * 0x18` bytes of [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md) rows. The unreferenced aggregate builder sums this field across per-file EPF buckets. | Confirmed as count, but signedness/source typedef remains provisional. |
| `+0x02` | `maxExtent02` | Second 16-bit header field read from `DATA/MON%d.DAT`. The unreferenced `0x004db8b0` aggregate builder keeps the maximum observed value across `MON%d.EPF` source buckets. | Exact axis/source name is unknown; the maximum behavior proves it is an active metric rather than padding. |
| `+0x04` | `maxExtent04` | Low 16 bits of the next header dword. The `0x004db8b0` aggregate builder keeps the maximum observed value across input buckets. | Exact axis/source name is unknown; keep a neutral max/extent name until the archive format is fully decoded. |
| `+0x06` | `header06` | High 16 bits of the 8-byte archive header. The normal loader preserves it from disk, while the aggregate builder zeroes it when creating a merged bucket. | No observed consumer reads this halfword; keep it neutral rather than treating it as a decoded field. |
| `+0x08` | `entries` | Heap pointer written after allocating `(entryCount + 1)` entry rows; cleanup later frees this array before freeing the 0x0c bucket. | Source owner and allocator wrapper names remain provisional. |

## Notes

- The loader allocates 0x0c bytes for the bucket, reads the first eight bytes directly from the `DATA/MON%d.DAT` archive, and then stores the heap-allocated entry array at `+0x08`.
- The loader allocates `(entryCount + 1)` [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md) rows. The extra row is a zero-bounds sentinel whose payload start/end point at the archive payload base plus a separately read payload-start offset.
- The bucket is cached in the [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) `+0x3c` `DATIndexVector` instance and keyed by archive id.
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) inserts the 0x0c bucket into the `+0x3c` cache before filling the header/body, and [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) documents the paired `+0x1c` open-archive index and `+0x3c` bounds-bucket index.
- The unreferenced builder at `0x004db8b0` scans `MON%d.EPF` inputs, reads the same 8-byte per-file header, sums `entryCount`, keeps maxima for the `+0x02` and `+0x04` halfwords, zeroes the `+0x06` halfword in its aggregate header, builds a combined `(entryCount + 1)` entry array, and emits the same sentinel pattern.
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) are the actual owner chain for this struct. The class and file pages now clear the strict `85/85` parent gate; [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) remains supporting layout evidence rather than the direct parent.
- Current generated disabled output names the middle header fields `reserved` and `reserved04`; B001-032 keeps neutral field names but no longer treats `+0x02` and low `+0x04` as mere reserved bytes.
- 2026-06-27 B003 live MCP session `80de0a67` reconfirmed the same bucket construction in [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md): allocate 0x0c bytes, insert the bucket pointer into `m_boundsBucketIndex` at `+0x3c`, read exactly 8 header bytes, allocate `(entryCount + 1)` 0x18-byte entries, store the entry pointer at `+0x08`, and leave cleanup to `ClearLoadedData`.

## IDA Verification Notes

- 2026-05-31 IDA MCP `lookup_funcs 0x004dbe60` reports `sub_4DBE60` at `0x004dbe60` with size `0x315`, giving an exact end at `0x004dc174`.
- IDA MCP decompilation/disassembly of `0x004dbe60` shows `operator new(0x0c)` for the bucket at `0x004dbfa6`, then insertion of `(archiveId, bucketPointer)` into the `this + 0x3c` cache before any bucket payload is read.
- The DAT reader virtual call at `0x004dc01d` reads exactly 8 bytes into the bucket, and the later write at `0x004dc03f` stores the allocated entry array pointer at bucket offset `+0x08`.
- The entry allocation at `0x004dc02e` computes `(entryCount + 1) * 0x18`, proving the bucket's first field is a 16-bit count consumed from the just-read header.
- IDA MCP decompilation of `0x004db8b0` shows the aggregate EPF builder reading 8-byte bucket headers, adding `+0x00` counts, taking maxima over the `+0x02` and `+0x04` halfwords, leaving the `+0x06` halfword zero in the generated aggregate header, and then filling 0x18-byte entry rows.
- IDA MCP decompilation of `0x004dc180` and `0x004db5c0` shows runtime consumers using `entryCount` and `entries` only. No observed consumer reads the middle header metrics directly after the bucket is loaded.
- IDA MCP decompilation of `0x004dc2e0` shows `ClearLoadedData` freeing `bucket->entries` first and then freeing the 0x0c bucket itself while clearing the `+0x3c` cache.
- 2026-06-27 B003 live MCP reconfirmed consumers use the count and entry pointer fields, while no live render consumer proves final original names for `+0x02`, `+0x04`, or `+0x06`. Keep `maxExtent02`, `maxExtent04`, and `header06` as neutral reconstruction vocabulary.
- IDA has no named local struct for this record; the field names remain recovered documentation vocabulary.
- Scores stay below `95` because the exact original names for the two max metrics, the role of `+0x06`, and the surrounding `DATA/MON%d.DAT` payload contract are not fully decoded.

## Assignment Gate

This struct is assigned under the strict supervisor gate.

- Child side: B011 improves the child to `88/91` by adding formal C++ declaration output while preserving B001-032's active max/extent behavior of `+0x02` and low `+0x04`, cleanup ownership, and runtime non-use of the middle header metrics.
- Direct owner side: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) is the narrow direct class owner and now scores `89/90`; [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) scores `89/89`.
- Supporting docs: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) remains `78/86` and unassigned, but it is layout evidence rather than the direct semantic parent for this bucket struct. [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) is a reusable cache helper, not the owner.
- Classification: source-owned MonsterImageLib private/archive bucket record, assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).

## Cross-References

- [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `86/90` to `88/91`.
  - Evidence: inserted the formal `MonsterArchiveBoundsBucket` struct declaration with `entryCount`, neutral `maxExtent02`/`maxExtent04`/`header06`, and `MonsterArchiveBoundsEntry *entries`. Preserved 0x0c size, 8-byte header read, 0x18 entry allocation, `m_boundsBucketIndex` cache insertion, cleanup ownership, neutral naming caveats, and class/file route.
- 2026-06-27 B003 GetArchiveBoundsBucket support sync:
  - Score unchanged at `86/90`.
  - Evidence: added live MCP session `80de0a67` confirmation that [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) allocates the 0x0c bucket, inserts it into `m_boundsBucketIndex`, reads exactly 8 header bytes, writes the `+0x08` entry pointer, and leaves neutral middle-header names in place because original names remain unproven.
- 2026-06-10 B001-032 owner/structure repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` blank, status `reviewed-no-85`.
  - After: `COMPLETION:86`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:00008N`.
  - Evidence: IDA MCP rechecked `GetArchiveBoundsBucket` (`0x004dbe60`), `ResolveMonsterArchiveBounds` (`0x004dc180`), `ComputeRenderBounds` (`0x004db5c0`), `ClearLoadedData` (`0x004dc2e0`), and the unreferenced aggregate builder (`0x004db8b0`). The builder proves the former unknown middle header fields are active 16-bit max metrics at `+0x02` and low `+0x04`, while `+0x06` remains neutral/reserved. Current [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) scores now clear the strict parent gate.
- 2026-06-08 A002 Batch123:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:82`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` still blank.
  - Evidence: expanded the field evidence table, tied `entryCount` to the `(entryCount + 1) * 0x18` allocation, recorded the `+0x08` entry-array pointer write and cleanup ownership, and checked the associated owner chain ([UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md), [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md), and [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md)). At that time the page stayed `reviewed-no-85` because the child was below 85 completion and owner parents were also below the strict gate.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `76`, confidence `86`.
- Summary/evidence: IDA MCP on 2026-05-31 verified the exact loader function boundary, 0x0c bucket allocation, 8-byte header read, `+0x08` entry pointer write, `(entryCount + 1) * 0x18` entry allocation, and `this + 0x3c` cache ownership. Scores remain below `95` because the non-count header fields and full archive format semantics are still provisional.
