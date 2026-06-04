*** UID:0000VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VectorGrowArchiveIndex 0x004e5990

## Status

- Entity kind: free helper
- Exact by-memory child: [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
- Owner: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), not [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- Function boundary: live IDA MCP on 2026-06-04 reports `sub_4E5990` at `0x004e5990-0x004e5a62`, size `0xd2`.
- Evidence basis: live IDA MCP caller/callee, boundary, alignment, and decompilation checks.
- Rebuild handling: source-owned container-growth helper for the `MonsterImageLib` archive-index vector. Marked reconstructable because the owning source container/insert operation must reproduce this behavior, but the helper should not receive final C++ until the container type, field names, and helper boundary are proven.

## Behavior

`VectorGrowArchiveIndex` grows a contiguous 4-byte archive-index array, moves existing entries when required, and returns the insertion position for the caller. The working shape from IDA is:

```cpp
std::uint32_t* VectorGrowArchiveIndex(
    std::uint32_t** vectorState,
    std::uint32_t* insertPos,
    const std::uint32_t* entry);
```

2026-06-04 live IDA MCP confirms the decompilation computes the insertion index from `insertPos - begin`, grows capacity by `capacity + capacity / 2` when possible, inserts the new 32-bit entry, moves existing prefix/suffix blocks with `_memmove_0`, calls `0x004e6df0` during the move/cleanup path, and uses `0x00421500` for the length-error path.

## Ownership Evidence

Live IDA MCP `xrefs_to 0x004e5990` on 2026-06-04 finds only:

- `0x004dbc60`: `MonsterImageLib::LoadMonsterArchives`.

The exact callsite is `0x004dbd8f`. The caller-window disassembly shows a direct fast append path when capacity is available, and the slow path pushes the new archive-index value plus current insertion position before calling this helper.

This helper should therefore stay with `MonsterImageLib` archive-index loading unless new callers appear. It is adjacent to DAT/resource research but is not part of `DATIndexVector`.

## IDA MCP Evidence

- 2026-06-04 `lookup_funcs` reports `sub_4E5990` at `0x004e5990-0x004e5a62`, size `0xd2`.
- 2026-06-04 neighbor scan reports previous function [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) ending at `0x004e598a`; immediate bytes `0x004e5a62-0x004e5a70` are all `0xcc` post-body alignment.
- 2026-06-04 `xrefs_to 0x004e5990` reports one code caller at `0x004dbd8f` inside `0x004dbc60-0x004dbdfb`, the `MonsterImageLib::LoadMonsterArchives` range.
- 2026-06-04 callee scan reports allocation helper `0x00421520`, `_memmove_0` at `0x004e5a13`, `0x004e5a26`, and `0x004e5a39`, storage replacement helper `0x004e6df0`, and length-error helper `0x00421500`.
- 2026-06-04 Hex-Rays confirms the 4-byte vector-state arithmetic, capacity growth, inserted entry write, prefix/suffix moves, storage replacement, and inserted-pointer return.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
- [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, single MonsterImageLib caller, vector-growth behavior, `_memmove_0` usage, and allocation/error helper callees. The score remains below 95 because the exact container type and source-vs-template-generated boundary are not fully audited.
- 2026-06-04: Raised completion/confidence from `70/85` to `84/90` and attached `AUTOGEN_PARENT_UID:0000LJ`.
  - What existed before: the item had live boundary/caller notes but no exact by-memory child and no autogen parent.
  - Changed to: added exact child [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md), linked it to the `MonsterImageLib` aggregate, and attached the item to the high-confidence [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) source parent.
  - Summary/evidence: live IDA MCP on 2026-06-04 confirmed exact function boundary, one `LoadMonsterArchives` caller, immediate post-body alignment, callee set, and vector-growth behavior. Final C++ remains blank because container field names and helper naming are still below the final reconstruction bar.
