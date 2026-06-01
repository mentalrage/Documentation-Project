*** UID:0000VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VectorGrowArchiveIndex 0x004e5990

## Status

- Entity kind: free helper
- Current recovered file: `source-3/simroot_v2/recovered/VectorGrowArchiveIndex_004E5990.cpp`
- Proposed owner: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), not [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- Function boundary: IDA MCP `lookup_funcs` reports `sub_4E5990` size `0xd2`.
- Evidence basis: Wave2 report notes and IDA MCP caller/callee checks on 2026-05-24.
- Rebuild handling: likely `source-declared/generated-binary` container-growth helper for the MonsterImageLib archive-index vector. Marked reconstructable because the owning source container/insert operation must reproduce this behavior, but the helper should not receive final C++ until the container type and template/runtime boundary are proven.

## Behavior

`VectorGrowArchiveIndex` grows a contiguous archive-index array, moves existing entries when required, and returns the insertion position for the caller. The imported signature in `by-memory/-report.md` is:

```cpp
std::uint32_t* VectorGrowArchiveIndex(
    ArchiveIndexVector* self,
    std::uint32_t* insertPos,
    const std::uint32_t* entry);
```

IDA MCP `callees` reported calls to allocation/length helpers, `_memmove_0`, and `0x004e6df0`.

2026-05-31 IDA MCP recheck reports `sub_4E5990` with exclusive end `0x004e5a62`. The decompilation computes insertion index from `insertPos - begin`, grows capacity by `capacity + capacity / 2` when possible, inserts the new 32-bit entry, moves existing prefix/suffix blocks with `_memmove_0`, calls `0x004e6df0` during the move/cleanup path, and uses `0x00421500` for the length-error path.

## Ownership Evidence

IDA MCP `callers` on 2026-05-24 found only:

- `0x004dbc60`: `MonsterImageLib::LoadMonsterArchives`.

The 2026-05-31 IDA recheck again found a single code reference from `0x004dbd8f` inside the same MonsterImageLib loading neighborhood.

This helper should therefore stay with `MonsterImageLib` archive-index loading unless new callers appear. It is adjacent to DAT/resource research but is not part of `DATIndexVector`.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, single MonsterImageLib caller, vector-growth behavior, `_memmove_0` usage, and allocation/error helper callees. The score remains below 95 because the exact container type and source-vs-template-generated boundary are not fully audited.
