*** UID:0000PK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DestroyMotionVector is a documented/search alias for exact helper [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md).
// Source behavior lives in [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) NewHumanImageLib::~NewHumanImageLib and the m_motionEntries vector member cleanup; no duplicate global helper body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DestroyMotionVector

## Status

- Symbol kind: global/helper function.
- Address range: [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner, role, bounds, cleanup semantics, current caller/callee set, vector-reset behavior, no-name/type checks, and no-duplicate marker disposition; exact original helper/type spellings remain inferred.

## Role

`DestroyMotionVector` is the page/global/search alias for the lowered cleanup helper that releases the `m_motionEntries` vector storage used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). Current IDA does not prove `DestroyMotionVector` as an original source-authored function name, so this page stays a no-duplicate marker. Source behavior is represented by [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md): it frees each `NewHumanMotionEntry` payload, then reaches the lowered vector-storage cleanup.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to the new-human motion table vector.

## Cleanup Semantics

| Detail | Evidence / meaning |
| --- | --- |
| Vector shape | The argument is a three-pointer vector header: `begin`, `end`, and `capacity`. |
| Record size | The capacity-span test divides by `0x42`, matching the in-memory `NewHumanMotionEntry` stride documented in [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md). The `Motion.tbl` file payload is a fixed prefix plus count-driven frame payloads, not a fixed 0x42-byte file row. |
| Small allocation path | Frees `begin` directly through the same checked free wrapper used by adjacent vector cleanup helpers. |
| Large aligned path | Reads the stored raw allocation base pointer immediately before `begin`; if the expected alignment delta is invalid, it calls `__invalid_parameter_noinfo_noreturn`. |
| Reset | Clears `begin`, `end`, and `capacity` after successful free. If `begin` is null, the helper returns without changing the triplet. |

## Boundary And Caller Evidence

| Evidence | Result |
| --- | --- |
| Function boundary | [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) records `sub_4E5DD0`, size `0x69`, with the corrected exclusive end at `0x004e5e39`. |
| Caller | The only executable caller observed is [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md), call site `0x004e0547`. |
| Callees | The body calls the checked-free/runtime allocator wrapper at `0x005c7526` and `__invalid_parameter_noinfo_noreturn` at `0x005cd607`; no feature-specific callees appear and no local source wrapper name is proven. |
| Neighboring bytes | The memory page records seven `0xcc` bytes at `0x004e5e39-0x004e5e40`, with the next helper starting at `0x004e5e40`. |

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is the `NewHumanImageLib` cleanup/destructor path at `0x004e0250`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4E5DD0`, size `0x69`, the single caller inside `sub_4E0250`, and callees for invalid-parameter termination and aligned-storage release.
- Live IDA MCP on 2026-06-14 rechecked `sub_4E5DD0` at `0x004e5dd0`, size `0x69`, 105 decimal bytes (Verified with int_convert.py), seven basic blocks, cyclomatic complexity 3, and callees limited to checked free `sub_5C7526` plus `__invalid_parameter_noinfo_noreturn`.
- The 2026-06-14 function analysis still reports only `sub_4E0250` / [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) as the executable caller. `xrefs_to` additionally reports a constructor-associated reference at `0x0060025a` tied to `sub_4DFD10`; this supports construction/cleanup metadata adjacency but does not make the helper a general runtime Motion owner.
- IDA-reviewed behavior clears begin/end/capacity after freeing storage.
- The owning file page records this as the cleanup pair for [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md), which grows the same `Motion.tbl` vector.
- Current MCP session `supervisor_recovery_20260705` rechecked `sub_4E5DD0` at `0x004e5dd0`, size `0x69`, exact range `0x004e5dd0-0x004e5e39`; successor `0x004e5e40` resolves to `sub_4E5E40`.
- Current `xrefs_to` / `xref_query` report exactly two refs: ordinary destructor callsite `0x004e0547` in `sub_4E0250` and constructor cleanup-table/code reference `0x0060025a` in `sub_4DFD10`. The constructor ref is lifetime/unwind metadata, not an ordinary constructor source call.
- Current `callees`, `analyze_component`, `decompile`, and `disasm` report only `sub_5C7526` plus `__invalid_parameter_noinfo_noreturn`; seven basic blocks; cyclomatic complexity 3; null-begin no-op; large raw-base guard `begin - rawBase - 4 > 0x1f`; checked-free call; and zeroing of begin/end/capacity.
- Current `get_bytes 0x004e5e30 size 24` proves the invalid-parameter call bytes through `0x004e5e38`, seven `0xcc` bytes at `0x004e5e39-0x004e5e40`, and successor prologue at `0x004e5e40`.
- Current signature evidence is unique for full range `0x004e5dd0-0x004e5e39`, and the first 18 target bytes match only at `0x004e5dd0`.
- Current `lookup_funcs`, `type_query`, and scoped `search_text` found no source symbol/type/listing proof for `DestroyMotionVector`, `MotionEntryVector`, or `NewHumanMotionEntry`. This keeps `DestroyMotionVector` as a historical/search alias and keeps source-facing prose on `m_motionEntries` / three-pointer vector storage.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page records exact range, current size, destructor caller, constructor-associated metadata reference, callee set, three-pointer vector shape, `0x42` in-memory `NewHumanMotionEntry` stride, small/large allocation cleanup, invalid-parameter guard, reset semantics, padding boundary, unique signature, no-name/type checks, parent/emitter route, and Motion-class owner rejection. |
| Confidence | 91 | Current MCP session `supervisor_recovery_20260705` matches the documented behavior and NewHumanImageLib ownership: one ordinary destructor caller, cleanup-table lifetime ref, cleanup-only callees, and the same `m_motionEntries` vector semantics as [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md). Confidence remains below final-source level because exact original helper spelling, final vector declaration policy, and original row-field spellings remain inferred. |
| Parent | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) | Child `86/89` and direct parent `87/85` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/render/NewHumanImageLib.cpp`. |

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-07-06 B015 source-quality implementation:
  - Changed to: `COMPLETION:88` and `CONFIDENCE:91`; owner/emitter metadata remains [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Changed formal marker/prose to historicalize `DestroyMotionVector` as a documented/search alias for [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md), with no duplicate global helper body. Source behavior stays in [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md) and the `m_motionEntries` vector member cleanup.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirms exact range `0x004e5dd0-0x004e5e39`, successor/padding at `0x004e5e39-0x004e5e40`, destructor call `0x004e0547`, constructor cleanup-table ref `0x0060025a`, callee set, raw-base guard, triplet reset, unique signature, and no source symbol/type/listing hits for the helper/type aliases.
- 2026-07-01 B011 empty-emitter implementation: filled the global cleanup-helper marker formal block with the accepted no-duplicate comment pointing to [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) and [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md).
- 2026-06-06 helper evidence pass:
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: expanded the page with the three-pointer vector shape, `0x42` record-size tie to `Motion.tbl`, small and large allocation cleanup paths, invalid-parameter guard, exact boundary/padding notes, and single-destructor-caller ownership evidence. Completion remains below very high because final helper signature and exact `MotionEntry` field names remain open.
- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented helper role, owner, caller evidence, and vector-free behavior but remained unevaluated.
  - After: score reflects documented new-human motion-vector cleanup behavior and owner assignment, with remaining completion limited by compact type/layout detail.
  - Evidence: IDA caller notes tie the helper to `NewHumanImageLib` cleanup/destructor and confirm free/reset semantics for begin/end/capacity storage.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Reason: live IDA MCP recheck confirms this is source-authored vector cleanup with only the `NewHumanImageLib` cleanup/destructor caller observed.
- 2026-06-14 A003 score refresh:
  - Before: `84/88`; the page had strong behavior evidence but lacked a current score rationale and live function/xref recheck.
  - Changed to: `86/89`, retaining [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) as canonical owner/emitter; the old blank C++ state was superseded by the 2026-07-01 no-duplicate marker comment.
  - Summary/evidence: live IDA MCP rechecked `sub_4E5DD0`, `0x69` / 105-byte size (Verified with int_convert.py), executable destructor caller `sub_4E0250`, cleanup-only callee set, and the constructor-associated metadata reference. Final helper signature/name and `MotionEntry` fields remain the blockers below final code entry.
