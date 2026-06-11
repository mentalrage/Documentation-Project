*** UID:0000TO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VectorGrowMotion

## Status

- Symbol kind: global/helper function.
- Address range: [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner, range, role, and sole caller; medium for final helper spelling and record-field names.
- Assignment status: this helper now clears the strict child gate at `85/86`, and direct parent [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) clears the parent gate at `87/85`, so `AUTOGEN_PARENT_UID:0000LR` is retained.

## Role

`VectorGrowMotion` grows and inserts records in the `Motion.tbl` entry vector used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It manipulates fixed-size `0x42` byte records, 66 decimal bytes (Verified with int_convert.py), and follows MSVC vector growth/allocation behavior.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to `Motion.tbl` data records in the new human image library.

Source-level role: a file-local helper beside `NewHumanImageLib::LoadMotionTable`, not a general vector utility. The helper's record stride, sole caller, resource-page owner, and direct parent all point to `render/NewHumanImageLib.cpp`.

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is `NewHumanImageLib::LoadMotionTable` at `0x004e0e20`.
- IDA MCP recheck on 2026-06-05 confirmed the current IDA alias `sub_4E5240`, size `0x1d5`, 469 decimal bytes (Verified with int_convert.py), the single caller inside `NewHumanImageLib::LoadMotionTable` / current IDA alias `sub_4E0E20`, and callees for allocation, `memmove`, checked free, length-error, and invalid-parameter handling.
- Linked exact memory evidence records the exclusive range `0x004e5240-0x004e5415`, the fallback length-error call bytes at `0x004e5410-0x004e5415`, eleven `0xcc` padding bytes at `0x004e5415-0x004e5420`, and the adjacent next helper at `0x004e5420`.
- IDA-reviewed behavior models `MotionEntry` as a packed `0x42`-byte record, 66 decimal bytes (Verified with int_convert.py), stored in a three-pointer vector. The max-size guard uses `0x3e0f83e`, 65075262 decimal (Verified with int_convert.py).
- Allocation behavior is vector-specific but compiler-shaped: allocations below `0x1000`, 4096 decimal bytes (Verified with int_convert.py), use direct `operator new`; larger allocations add `0x23`, 35 decimal bytes (Verified with int_convert.py), align the usable pointer to `0x20`, 32 decimal bytes (Verified with int_convert.py), and preserve the raw pointer for checked free.
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md) independently ties `Motion.tbl` to the [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md) vector at object offset `+0x1c`, while [UID:0000LL][Motion](by-file/Motion.md) explicitly excludes this helper from the runtime Motion source bucket.

## Open Questions

- Exact source-level helper spelling remains provisional; `VectorGrowMotion` describes the recovered role, while IDA still uses the raw `sub_4E5240` alias.
- Final `Motion.tbl` field names remain open, so no reconstruction C++ is emitted despite the strong owner/range evidence.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-06-10 A001 gate repair and evidence consolidation:
  - Before: score `82/84` while `AUTOGEN_PARENT_UID:0000LR` was already set, leaving the child side below the strict `85/85` gate.
  - Changed to: score `85/86`; retained `AUTOGEN_PARENT_UID:0000LR`.
  - Summary/evidence: consolidated the linked IDA-backed memory/resource/file evidence into this global ownership page, including the exact `0x004e5240-0x004e5415` range, `0x1d5` size, sole `LoadMotionTable` caller, `Motion.tbl` record stride, capacity/allocation behavior, padding/next-helper boundary, and explicit exclusion from the runtime [UID:0000LL][Motion](by-file/Motion.md) source bucket. Current IDA MCP was temporarily unavailable during this pass, so the update relies on existing IDA-backed docs plus fresh `int_convert.py` checks rather than a new live decompile.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/84`. Summary/evidence: the page documents the helper range, owner, role, IDA caller evidence, stale-name correction, and resource/file refs; the page is short because the helper itself is narrow.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Reason: live IDA MCP recheck confirms this is source-authored vector growth code with only the `NewHumanImageLib` motion-table loader caller observed.
