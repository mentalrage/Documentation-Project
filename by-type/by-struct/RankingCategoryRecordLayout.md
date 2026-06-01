*** UID:0001VN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000BL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryRecordLayout

## Status

- Confidence: strong for observed offsets and vector/date helper behavior; medium for semantic names of date/time parts and user-entry tail fields.
- Likely owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Primary memory evidence: [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- Size evidence: `688` bytes from category collection stride usage in IDA decompilation; generated metadata is only a lead.
- Reconstructable: source-declared fixed-record layout for the reconstructed ranking dialog module. Final C++ declaration is deferred until the row/date-time types and field names are stronger.

## Layout Hypothesis

`RankingCategoryRecord` stores one ranking event/category plus the ranking rows loaded for that category. It is a plain fixed-size record, not a polymorphic class.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 2 | `listIndex` | `0x0045bf60` returns `*(_WORD*)this`; event-list click logic compares this against the visible row. |
| `+0x04` | 4 | `categoryId` | `0x0045bf70` returns `this[1]`; ranking request/reward paths use it as category id. |
| `+0x08` | 4 | `stateCode` | `0x0045bf80` returns `this[2]`; event-card drawing branches on it. |
| `+0x0c` | 36 | start time/date parts | `0x0045bf90` copies 36 bytes from this offset; `0x0045c050` writes six packed date/time parts into dwords `+0x0c..+0x20`. |
| `+0x30` | 36 | end time/date parts | `0x0045bfb0` copies 36 bytes from this offset; `0x0045c100` writes six packed date/time parts into dwords `+0x30..+0x44`. |
| `+0x54` | 516 | wide title text buffer | `0x0045bfd0` returns `this + 84`; the next confirmed vector field begins at `+0x258`. |
| `+0x258` | 4 | user entries begin | `0x0045bfe0` and `0x0045c240` read this as the vector begin pointer. |
| `+0x25c` | 4 | user entries current/end | `0x0045bfe0` uses this as the end pointer; `0x0045c240` resets it to begin. |
| `+0x260` | 4 | user entries capacity | Disabled generated layout names this as capacity. |
| `+0x264` | 4 | reserved/vector bookkeeping | Present between capacity and selected index in generated disabled layout. |
| `+0x268` | 4 | selected/local user index | `0x0045c240` writes `-1`. |
| `+0x26c` | 68 | tail storage / padding | Remainder to 688-byte stride; not yet named. |

## Nested User Entry

`GetUserEntryAt` proves a user-entry stride of `76` bytes. The row layout is consumed by [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), but its fields still need a dedicated offset pass before final names.

`0x0045c1e0` appends one 76-byte row to the vector at `+0x258`. If current end equals capacity it calls growth helper `0x0045d1b0`; otherwise it copies 76 bytes into the current end and advances `+0x25c` by `0x4c`.

## Date/Time Part Blocks

Both 36-byte date/time blocks contain at least six dword fields. The remaining three dwords in each block are not yet named.

Observed packed-date setter writes:

| Block | Offset | Stored value |
| --- | --- | --- |
| start | `+0x0c` | `packedTime % 100` |
| start | `+0x10` | `(packedTime % 10000) / 100` |
| start | `+0x14` | `packedTime / 10000` |
| start | `+0x18` | `packedDate % 100` |
| start | `+0x1c` | `(packedDate % 10000) / 100` |
| start | `+0x20` | `packedDate / 10000` |
| end | `+0x30` | `packedTime % 100` |
| end | `+0x34` | `(packedTime % 10000) / 100` |
| end | `+0x38` | `packedTime / 10000` |
| end | `+0x3c` | `packedDate % 100` |
| end | `+0x40` | `(packedDate % 10000) / 100` |
| end | `+0x44` | `packedDate / 10000` |

## Evidence Notes

- 2026-05-31 IDA MCP recheck confirmed all eleven method starts, current decompilation of the date/time setters, the 76-byte user-entry copy in `AppendUserEntry`, caller sets for every accessor/helper, and `688`-byte category-record stride in collection parser loops.
- Current active generated source emits only the category-id accessor; `class_RankingCategoryRecord.cpp.disabled` contains the other seven methods.
- Current active and disabled generated source both omit the date-part setters at `0x0045c050`/`0x0045c100` and the user-entry append helper at `0x0045c1e0`.
- IDA caller evidence confirms the disabled helpers are used by ranking event-list drawing, user-list painting, reward-info drawing, and selected-category reset paths.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)

## Changes

- 2026-05-31: Grading changed from `0/0` to `78/86`, marked reconstructable, and attached to [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md).
  - Before: page contained a useful offset table but still looked unevaluated to validator/stat tooling.
  - After: score reflects current IDA-verified method starts, caller evidence, date/time setter writes, vector offsets, record stride, and known remaining caveats for final field names and tail storage.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, and `callers` checks on 2026-05-31 for the eleven exact method starts and collection/parser callers.
- 2026-05-27: Expanded the date/time blocks and user-entry vector evidence after IDA confirmed `0x0045c050`, `0x0045c100`, and `0x0045c1e0`. Before this change, the layout only documented copy/access/reset helpers and did not capture the packed-date setters or append behavior.
