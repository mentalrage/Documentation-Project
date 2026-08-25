*** UID:0000VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VectorGrowArchiveIndex 0x004e5990

## Status

- Entity kind: item/index alias for the exact by-memory helper page.
- Exact by-memory child: [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
- Owner: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), not [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- Function boundary: live IDA MCP on 2026-06-04 reports `sub_4E5990` at `0x004e5990-0x004e5a62`, size `0xd2`.
- Evidence basis: live IDA MCP caller/callee, boundary, alignment, and decompilation checks.
- Rebuild handling: non-reconstructable alias cleanup. Exact executable behavior and the formal no-code disposition are owned by [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md); this item page should not emit source or create a duplicate empty marker.

## Behavior

`VectorGrowArchiveIndex` grows a contiguous 4-byte archive-index array, moves existing entries when required, and returns the insertion position for the caller. This item preserves the evidence alias only; the exact executable range and reconstruction disposition now belong to [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md). The working shape from IDA is:

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

The 2026-06-16 recheck keeps that ownership decision: generic allocation/error helpers have broad callers, but `0x004e5990` itself still has only the MonsterImageLib archive-loading caller, and its storage-replacement helper `0x004e6df0` is only called by this grow helper.

## IDA MCP Evidence

- 2026-06-04 `lookup_funcs` reports `sub_4E5990` at `0x004e5990-0x004e5a62`, size `0xd2`.
- 2026-06-04 neighbor scan reports previous function [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) ending at `0x004e598a`; immediate bytes `0x004e5a62-0x004e5a70` are all `0xcc` post-body alignment.
- 2026-06-04 `xrefs_to 0x004e5990` reports one code caller at `0x004dbd8f` inside `0x004dbc60-0x004dbdfb`, the `MonsterImageLib::LoadMonsterArchives` range.
- 2026-06-04 callee scan reports allocation helper `0x00421520`, `_memmove_0` at `0x004e5a13`, `0x004e5a26`, and `0x004e5a39`, storage replacement helper `0x004e6df0`, and length-error helper `0x00421500`.
- 2026-06-04 Hex-Rays confirms the 4-byte vector-state arithmetic, capacity growth, inserted entry write, prefix/suffix moves, storage replacement, and inserted-pointer return.

Rechecked with live IDA MCP on 2026-06-16:

- `lookup_funcs` reports `sub_4DBC60` at `0x004dbc60` size `0x19b`, `sub_4E5990` at `0x004e5990` size `0xd2`, and storage replacement helper `sub_4E6DF0` at `0x004e6df0` size `0x59`; `0x004e5a62` is still not a function start.
- `xrefs_to 0x004e5990` reports one code caller, `0x004dbd8f` in `sub_4DBC60` / `MonsterImageLib::LoadMonsterArchives`. `xrefs_to 0x004dbc60` reports its constructor call at `0x004daff5` inside `sub_4DAEC0`, keeping the caller chain inside `MonsterImageLib`.
- Decompilation of `LoadMonsterArchives` shows the vector state at `this + 0x10/+0x14/+0x18`: the fast path writes the 32-bit archive-index value directly to `[end]` and advances `end` by four bytes; the capacity-full path calls `0x004e5990` with the vector state, current end pointer, and new index value.
- Decompilation of `0x004e5990` confirms a three-pointer, 4-byte-entry vector grow/insert helper: insertion index from `insertPos - begin`, current length from `end - begin`, `0x3fffffff` length guard, capacity growth by `capacity + capacity / 2`, allocation through `0x00421520`, prefix/suffix `_memmove_0`, storage replacement through `0x004e6df0`, and return of the inserted pointer.
- Decompilation of `0x004e6df0` confirms it frees/replaces the old vector storage and writes `begin`, `end`, and `capacity_end` from the new storage pointer, length, and capacity. `xrefs_to 0x004e6df0` reports only the `0x004e5a4a` call from this helper.
- Boundary bytes reconfirm `0x004e5990` begins after `0xcc` alignment following [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md), and `0x004e5a62-0x004e5a70` is `0xcc` alignment before the next code.

## Blocker Investigation

- Owner: semantic evidence remains [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), but this alias has no emitter route. The single caller, constructor reachability, archive resource loop, and vector-state fields inside the `MonsterImageLib` object support the exact by-memory page's local MonsterImageLib disposition over [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md).
- Container/helper type: the helper is now documented as a three-pointer 4-byte vector grow/insert routine for the archive-index vector at `this + 0x10`. It is still unsafe to claim an original source template or final helper name because IDA exposes the inlined vector shape and support helpers, not the source declaration.
- Source placement: no B-agent escalation is recommended for ownership. The checked evidence is narrow and supports `MonsterImageLib.cpp`; exact output now comes only through [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md).
- Final C++: intentionally absent because this page is a duplicate/index alias. The exact by-memory page emits the accepted no-code marker; this item page must not emit a second marker or body.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
- [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Changed `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`, cleared `EMITTER_UIDS`, and kept `CANONICAL_OWNER:0000LJ` as semantic evidence context.
  - Evidence: this page is a duplicate/index alias for [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md). Exact range, one-caller evidence, and formal no-code disposition are on the by-memory page, so this item must not emit a duplicate empty marker or body.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the function boundary, single MonsterImageLib caller, vector-growth behavior, `_memmove_0` usage, and allocation/error helper callees. The score remains below 95 because the exact container type and source-vs-template-generated boundary are not fully audited.
- 2026-06-04: Raised completion/confidence from `70/85` to `84/90` and attached the [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) owner/emitter route.
  - What existed before: the item had live boundary/caller notes but no exact by-memory child and no owner/emitter route.
  - Changed to: added exact child [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md), linked it to the `MonsterImageLib` aggregate, and attached the item to the high-confidence [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) source parent.
  - Summary/evidence: live IDA MCP on 2026-06-04 confirmed exact function boundary, one `LoadMonsterArchives` caller, immediate post-body alignment, callee set, and vector-growth behavior. Final C++ remains blank because container field names and helper naming are still below the final reconstruction bar.
- 2026-06-16 A002 Goal 2 refresh: raised from `84/90` to `86/91`.
  - Evidence: live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the exact helper/caller/storage-replacement function sizes, one `LoadMonsterArchives` caller, constructor reachability into that caller, caller fast/slow append split, three-pointer vector-state location at `this + 0x10`, one-caller `0x004e6df0` storage replacement, boundary padding, and remaining final helper/type-name blockers.
  - IDA DB changes: none. No rename/type/comment was applied because the final vector field names and helper source shape remain provisional.
