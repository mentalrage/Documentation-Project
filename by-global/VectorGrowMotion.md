*** UID:0000TO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// VectorGrowMotion is documented by exact helper [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) and emitted source behavior lives in [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md) NewHumanImageLib::LoadMotionTable; no duplicate global helper body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VectorGrowMotion

## Status

- Symbol kind: global/helper function.
- Address range: [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner, range, role, sole caller, current callee set, vector layout, and function boundary; medium for final helper spelling and record-field names.
- Assignment status: exact child [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) now records the refreshed B005 `87/90` source-quality disposition, while this global alias page remains a no-duplicate marker route through direct parent [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

## Role

`VectorGrowMotion` grows and inserts records in the `Motion.tbl` entry vector used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It manipulates fixed-size `0x42` byte records, 66 decimal bytes (Verified with int_convert.py), and follows MSVC vector growth/allocation behavior.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to `Motion.tbl` data records in the new human image library.

Source-level role: a file-local helper beside `NewHumanImageLib::LoadMotionTable`, not a general vector utility. The helper's record stride, sole caller, resource-page owner, and direct parent all point to `render/NewHumanImageLib.cpp`.

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is `NewHumanImageLib::LoadMotionTable` at `0x004e0e20`.
- IDA MCP recheck on 2026-06-05 confirmed the current IDA alias `sub_4E5240`, size `0x1d5`, 469 decimal bytes (Verified with int_convert.py), the single caller inside `NewHumanImageLib::LoadMotionTable` / current IDA alias `sub_4E0E20`, and callees for allocation, `memmove`, checked free, length-error, and invalid-parameter handling.
- IDA MCP recheck on 2026-06-14 again reports `sub_4E5240` at `0x004e5240`, size `0x1d5`, 469 decimal bytes (Verified with int_convert.py), exactly one code xref at `0x004e0ff2` from `sub_4E0E20`, 23 basic blocks, cyclomatic complexity 9, and callees limited to `operator new`, `memmove`, checked free, invalid-parameter failure, and the length-error path.
- B005 current MCP session `60724697` reconfirmed exact child `sub_4E5240` at `0x004e5240-0x004e5415`, size `0x1d5`, 176 disassembled instructions, sole UID000419 callsite `0x004e0ff2`, callee set limited to `operator new`, `_memmove_0`, checked free, invalid-parameter, and length-error support, loader decompile source route `m_motionEntries.push_back(motion)`, no IDA source names/types, no little-endian pointer/immediate matches for start/end/successor, unique first-byte signature, and padding before successor UID00041G.
- Linked exact memory evidence records the exclusive range `0x004e5240-0x004e5415`, the fallback length-error call bytes at `0x004e5410-0x004e5415`, eleven `0xcc` padding bytes at `0x004e5415-0x004e5420`, and the adjacent next helper at `0x004e5420`.
- IDA-reviewed behavior models `MotionEntry` as a packed `0x42`-byte record, 66 decimal bytes (Verified with int_convert.py), stored in a three-pointer vector. The max-size guard uses `0x3e0f83e`, 65075262 decimal (Verified with int_convert.py).
- Allocation behavior is vector-specific but compiler-shaped: allocations below `0x1000`, 4096 decimal bytes (Verified with int_convert.py), use direct `operator new`; larger allocations add `0x23`, 35 decimal bytes (Verified with int_convert.py), align the usable pointer to `0x20`, 32 decimal bytes (Verified with int_convert.py), and preserve the raw pointer for checked free.
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md) independently ties `Motion.tbl` to the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) vector at object offset `+0x1c`, while [UID:0000LL][Motion](by-file/Motion.md) explicitly excludes this helper from the runtime Motion source bucket.

## Open Questions

- Exact source-level helper spelling remains provisional; `VectorGrowMotion` describes the recovered role, while IDA still uses the raw `sub_4E5240` alias.
- Final `Motion.tbl` field names and original helper spelling remain open, so no standalone global helper body is emitted. Exact child UID00017T emits only a formal source-disposition marker; emitted source behavior lives in UID000419 `NewHumanImageLib::LoadMotionTable` as `m_motionEntries.push_back(motion)`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Exact range, exclusive boundary, caller, callee set, record stride, vector growth behavior, allocation/free rules, parent route, runtime Motion exclusion, and remaining source-name/type caveats are documented. |
| Confidence | 88 | Live IDA MCP on 2026-06-14 and B005 session `60724697` match [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) for size, sole caller, callee set, local vector shape, loader source route, pointer-negative evidence, and boundary padding; this alias page stays below final-source level because original helper spelling, `Motion.tbl` row fields, and final template/header policy are still unresolved. |
| Parent | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) | Child `86/88` and direct parent `87/85` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/render/NewHumanImageLib.cpp`. |

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-07-04 B005 UID00017T implementation sync:
  - Updated this global alias page to the current exact-child disposition: UID00017T is `87/90` file-local NewHumanImageLib marker support for the `NewHumanMotionEntry` vector-growth slow path, and no duplicate global helper body should be emitted.
  - Evidence: MCP session `60724697` reconfirmed exact range/size, 176 instructions, sole UID000419 callsite, target and loader decompiles, vector-runtime callee set, no IDA source names/types, no pointer/immediate matches, unique first-byte signature, and padding before successor UID00041G. Source behavior is UID000419 `m_motionEntries.push_back(motion)`; [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) is only a compatibility-template fallback.
- 2026-07-01 B011 empty-emitter implementation: filled the global-helper marker formal block with the accepted no-duplicate comment pointing to [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md) and [UID:000419][0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable](by-memory/0x004e0e20-0x004e103f.NewHumanImageLibLoadMotionTable.md).
- 2026-06-10 A001 gate repair and evidence consolidation:
  - Before: score `82/84` while `AUTOGEN_PARENT_UID:0000LR` was already set, leaving the child side below the strict `85/85` gate.
  - Changed to: score `85/86`; retained `AUTOGEN_PARENT_UID:0000LR`.
  - Summary/evidence: consolidated the linked IDA-backed memory/resource/file evidence into this global ownership page, including the exact `0x004e5240-0x004e5415` range, `0x1d5` size, sole `LoadMotionTable` caller, `Motion.tbl` record stride, capacity/allocation behavior, padding/next-helper boundary, and explicit exclusion from the runtime [UID:0000LL][Motion](by-file/Motion.md) source bucket. Current IDA MCP was temporarily unavailable during this pass, so the update relies on existing IDA-backed docs plus fresh `int_convert.py` checks rather than a new live decompile.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/84`. Summary/evidence: the page documents the helper range, owner, role, IDA caller evidence, stale-name correction, and resource/file refs; the page is short because the helper itself is narrow.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Reason: live IDA MCP recheck confirms this is source-authored vector growth code with only the `NewHumanImageLib` motion-table loader caller observed.
- 2026-06-14 A003 score refresh:
  - Before: `85/86`; the exact memory page had already reached `86/88` after a live IDA refresh.
  - Changed to: `86/88`, retaining [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) as canonical owner/emitter; the old blank C++ state was superseded by the 2026-07-01 no-duplicate marker comment.
  - Summary/evidence: live IDA MCP on database `a001_goal2_class_batch` reports `sub_4E5240`, size `0x1d5`, one caller from `sub_4E0E20` at `0x004e0ff2`, 23 basic blocks, cyclomatic complexity 9, and only vector-allocation/copy/free/error callees. Original helper spelling and final `Motion.tbl` row field names remain the blockers below final code entry.
