*** UID:0000PK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DestroyMotionVector

## Status

- Symbol kind: global/helper function.
- Address range: [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner, role, bounds, and cleanup semantics; medium-high for final helper signature/name.

## Role

`DestroyMotionVector` releases the `Motion.tbl` entry vector used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It handles small allocations directly and large aligned allocations through the stored allocation base pointer.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to the new-human motion table vector.

## Cleanup Semantics

| Detail | Evidence / meaning |
| --- | --- |
| Vector shape | The argument is a three-pointer vector header: `begin`, `end`, and `capacity`. |
| Record size | The capacity-span test divides by `0x42`, matching the `Motion.tbl` entry size documented in [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md). |
| Small allocation path | Frees `begin` directly through the same checked free wrapper used by adjacent vector cleanup helpers. |
| Large aligned path | Reads the stored raw allocation base pointer immediately before `begin`; if the expected alignment delta is invalid, it calls `__invalid_parameter_noinfo_noreturn`. |
| Reset | Clears `begin`, `end`, and `capacity` after successful free. If `begin` is null, the helper returns without changing the triplet. |

## Boundary And Caller Evidence

| Evidence | Result |
| --- | --- |
| Function boundary | [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) records `sub_4E5DD0`, size `0x69`, with the corrected exclusive end at `0x004e5e39`. |
| Caller | The only executable caller observed is [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md), call site `0x004e0547`. |
| Callees | The body calls the checked/free wrapper at `0x005c7526` and `__invalid_parameter_noinfo_noreturn` at `0x005cd607`; no feature-specific callees appear. |
| Neighboring bytes | The memory page records seven `0xcc` bytes at `0x004e5e39-0x004e5e40`, with the next helper starting at `0x004e5e40`. |

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is the `NewHumanImageLib` cleanup/destructor path at `0x004e0250`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4E5DD0`, size `0x69`, the single caller inside `sub_4E0250`, and callees for invalid-parameter termination and aligned-storage release.
- IDA-reviewed behavior clears begin/end/capacity after freeing storage.
- The owning file page records this as the cleanup pair for [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md), which grows the same `Motion.tbl` vector.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-06-06 helper evidence pass:
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: expanded the page with the three-pointer vector shape, `0x42` record-size tie to `Motion.tbl`, small and large allocation cleanup paths, invalid-parameter guard, exact boundary/padding notes, and single-destructor-caller ownership evidence. Completion remains below very high because final helper signature and exact `MotionEntry` field names remain open.
- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented helper role, owner, caller evidence, and vector-free behavior but remained unevaluated.
  - After: score reflects documented new-human motion-vector cleanup behavior and owner assignment, with remaining completion limited by compact type/layout detail.
  - Evidence: IDA caller notes tie the helper to `NewHumanImageLib` cleanup/destructor and confirm free/reset semantics for begin/end/capacity storage.
- 2026-06-05: Marked reconstructable and attached to [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
  - Reason: live IDA MCP recheck confirms this is source-authored vector cleanup with only the `NewHumanImageLib` cleanup/destructor caller observed.
