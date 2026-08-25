** TARGET-REPORT-UID:0002K0 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002K0-0002K6 / 0002KA / 0001ZD RankingCategoryRecord Source-Quality Report

## Executive Recommendation

Raise the eight `RankingCategoryRecord` accessor/helper targets [UID:0002K0]-[UID:0002K6] and [UID:0002KA] above the current `85/85` formal-C++ gate. Their range boundaries, field offsets, callers, and source-facing names are now strong enough to populate method-level first-draft C++ in [UID:0000BL] `RankingCategoryRecord`.

Do not populate formal C++ for [UID:0001ZD] as a single page. The range `0x0045d530-0x0045d740` is a mixed helper island: category-record vector teardown/range construction belongs to [UID:0000BK] `RankingCategoryCollection`, while user-entry vector teardown/allocation belongs to [UID:0000BL] `RankingCategoryRecord`. The current broad page should be reclassified as a non-emitting split/index or replaced by exact child pages, with final C++ blank for the parent and for compiler/vector helper children.

No by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited. This report is the only changed file intended for supervisor review.

## Scope And Inputs Checked

- Read current B002 assignment/rules from `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B002/goal.md`, `tools/leaser/Agents/Agent-B002/notes.md`, plus `by-structure.md` and `inference_research.md`.
- Primary docs checked: all nine assigned target pages, [UID:0000BL] `RankingCategoryRecord`, [UID:0000MZ] `RankingDialog`, [UID:0000Y9] `RankingCategoryRecord` aggregate, [UID:0001VN] `RankingCategoryRecordLayout`, [UID:0000BK] `RankingCategoryCollection`, [UID:0001ZC] `RankingCategoryCollection`, [UID:0002K7]/[UID:0002K8] packed date/time setters, and [UID:0002K9] append-user-entry.
- Existing executed B reports searched and treated as leads: B002 `0001ZC-ranking-category-collection-source-quality.md`, B002 `0002K9-ranking-user-entry-append-source-quality.md`, and B001 `0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md`.
- Coverage and generated context checked: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`. The generated `RankingDialog.cpp` file is currently empty, so these accepted snippets would be new source-quality content rather than replacing active generated code.
- Live IDA/GhidraBridge MCP evidence checked read-only against `NexusTK.exe` IDB session `b003_00018a_ime_comp_20260617`: function lookup, decompile, disassembly, and xrefs for all primary starts and helper starts.

## Direct Evidence

### Exact Accessor And Helper Bodies

IDA names and sizes:

- `0x0045bf60` `RankingCategoryRecord_GetListIndex`, size `0x4`.
- `0x0045bf70` `RankingCategoryRecord_GetCategoryId`, size `0x4`.
- `0x0045bf80` `RankingCategoryRecord_GetStateCode`, size `0x4`.
- `0x0045bf90` `RankingCategoryRecord_CopyStartTimeParts`, size `0x1f`.
- `0x0045bfb0` `RankingCategoryRecord_CopyEndTimeParts`, size `0x1f`.
- `0x0045bfd0` `RankingCategoryRecord_GetTitleText`, size `0x4`.
- `0x0045bfe0` `RankingCategoryRecord_GetUserEntryAt`, size `0x3b`.
- `0x0045c240` `RankingCategoryRecord_ResetUserEntries`, size `0x17`.

Decompile confirms:

- [UID:0002K0] returns the 16-bit field at `this + 0x00`.
- [UID:0002K1] returns the 32-bit field at `this + 0x04`.
- [UID:0002K2] returns the 32-bit field at `this + 0x08`.
- [UID:0002K3] copies `0x24` bytes from `this + 0x0c` to an output buffer and returns the output pointer.
- [UID:0002K4] copies `0x24` bytes from `this + 0x30` to an output buffer and returns the output pointer.
- [UID:0002K5] returns `this + 0x54`, the wide title buffer.
- [UID:0002K6] computes `(m_userEntriesEnd - m_userEntriesBegin) / 0x4c`; if that count is greater than the supplied signed index, it returns `m_userEntriesBegin + 0x4c * index`, otherwise `NULL`. There is no explicit negative-index guard in the binary; callers checked during this pass supply nonnegative UI row indexes.
- [UID:0002KA] assigns `m_userEntriesEnd = m_userEntriesBegin` and writes `-1` to `this + 0x268`; the returned begin pointer is a compiler artifact and source-facing return should be `void`.

Decimal/stride checks verified with `tools/int_convert.py`: `0x2b0 = 688`, `0x4c = 76`, `0x258 = 600`, `0x25c = 604`, `0x260 = 608`, `0x264 = 612`, `0x268 = 616`, `0x26c = 620`, `0x2ac = 684`, `0x54 = 84`, `0x254 = 596`, `0x0c = 12`, `0x30 = 48`, and `0x24 = 36`.

### Caller And Xref Recheck

- [UID:0002K0] has one live event-list caller at `0x0045b511` inside `sub_45B460`.
- [UID:0002K1] has nine current xrefs, not the older seven-count summary: `0x004589a8`, `0x00458af4`, `0x0045951b`, raw/null `0x004595c1`, `0x0045b3c4`, `0x0045b5d3`, `0x0045dd0f`, `0x0045de4d`, and raw/null `0x0045eaa7`.
- [UID:0002K2] has state/status UI callers at `0x004596dd`, `0x0045bb06`, and `0x0045bb1a`.
- [UID:0002K3] and [UID:0002K4] are both consumed by the user-list paint path around `0x0045f4fe` and `0x0045f56f`.
- [UID:0002K5] has rendering/title callers at `0x0045bc9d`, `0x0045bcb7`, `0x0045e4c9`, `0x0045e4e3`, `0x0045f47b`, and `0x0045f495`.
- [UID:0002K6] is used by the user-list paint path at `0x0045f637`.
- [UID:0002KA] is used at `0x004594f7` by the ranking response/update path.

### Date/Time Type Resolution

[UID:0002K7] and [UID:0002K8] split packed date/time values into six fields. The user-list paint caller validates the display order. The format string `L"From : %02d/%02d/%04d %02d:%02d:%02d"` consumes the copied block as:

- `+0x00`: second.
- `+0x04`: minute.
- `+0x08`: hour.
- `+0x0c`: day.
- `+0x10`: month.
- `+0x14`: year.
- `+0x18/+0x1c/+0x20`: copied reserved/uninitialized or future fields; the 36-byte copy preserves them exactly.

Best support type:

```cpp
struct RankingDateTimeParts
{
    int second;
    int minute;
    int hour;
    int day;
    int month;
    int year;
    int reserved0;
    int reserved1;
    int reserved2;
};
```

This resolves the older "date/time type name remains open" blocker enough for [UID:0002K3] and [UID:0002K4]. It also supports a future support-doc refresh for [UID:0002K7]/[UID:0002K8]: the source-facing setter parameters are best documented as `packedDate` and `packedTime`.

### State And User-Entry Field Meanings

- `+0x00` is `m_listIndex` / list-order index. It is 16-bit in the accessor body.
- `+0x04` is `m_categoryId`.
- `+0x08` is best kept as `m_stateCode`. State values `0`, `1`, and `2` are used by event-card/list UI logic. The response handler at `0x0045cdc0` sets this field to `1` for a category id after subcommand `6`; the render/button code distinguishes `0`, `1`, and `2`. A narrower name such as `rewardClaimState` is plausible but overfits one caller, so `stateCode` remains the safest source-quality name.
- `+0x54` is `wchar_t m_title[256]`.
- `+0x254` is the total rank/user count displayed by the ranking user list.
- `+0x258/+0x25c/+0x260` are user-entry vector begin/end/capacity.
- `+0x264` is the loaded/current rows category id, not reset by [UID:0002KA].
- `+0x268` is `m_localPlayerRank`, not a selected-user index. [UID:0002KA] resets it to `-1`; the user-list paint code displays the local-player rank when positive.
- `+0x26c` is `wchar_t m_localPlayerName[32]`.
- `+0x2ac` is `m_localPlayerScore`.
- `RankingUserEntry` is a `0x4c` row: `categoryId`, `rank`, `wchar_t name[32]`, and `score`.

## Per-Target Recommendations

| UID | Current | Recommended | Owner / emitter | Formal C++ |
| --- | ---: | ---: | --- | --- |
| [UID:0002K0] `GetListIndex` | `82/90` | `87/92` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K1] `GetCategoryId` | `82/90` | `88/93` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K2] `GetStateCode` | `82/90` | `86/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K3] `CopyStartTimeParts` | `82/90` | `86/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K4] `CopyEndTimeParts` | `82/90` | `86/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K5] `GetTitleText` | `82/90` | `88/93` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K6] `GetUserEntryAt` | `82/90` | `86/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002KA] `ResetUserEntries` | `82/90` | `86/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0001ZD] helper island | `82/90` | `86/91` split/index | no direct emitter after split | Do not populate |

[UID:0002K2] stays slightly lower than the pure field accessors because `stateCode` is a best descriptive name rather than a source-symbol proof, and the exact names of states `0/1/2` are not proven. That uncertainty no longer blocks the gate because field offset, caller behavior, and source placement are strong.

[UID:0002K3]/[UID:0002K4] can clear the gate because the field order is now validated by the paint formatter and the setters. The final type name `RankingDateTimeParts` is inferred, but the memory contract is exact.

## [UID:0001ZD] Helper-Island Split Recommendation

Function lookup and disassembly show five real helpers with padding between them:

- `0x0045d530-0x0045d5b5`: destroys a category-record vector. It walks records by `0x2b0`, calls user-entry vector destruction for each record at `record + 0x258`, then frees the category-record buffer and clears begin/end/capacity. Best name: `RankingCategoryRecordVectorDestroy`. Best owner: [UID:0000BK] `RankingCategoryCollection`.
- `0x0045d5b5-0x0045d5c0`: `0xcc` padding.
- `0x0045d5c0-0x0045d5eb`: destroys embedded user-entry vectors across a category-record range by `0x2b0`. Best name: `RankingCategoryRecordRangeDestroyUserEntries`. Best owner: [UID:0000BK], because the only ordinary caller is category-record vector insert/growth cleanup.
- `0x0045d5eb-0x0045d5f0`: `0xcc` padding.
- `0x0045d5f0-0x0045d653`: destroys a `RankingUserEntry` vector triplet, including MSVC large-allocation validation and pointer clearing. Best name: `RankingUserEntryVectorDestroy`. Best owner: [UID:0000BL].
- `0x0045d653-0x0045d660`: `0xcc` padding.
- `0x0045d660-0x0045d6d6`: SEH-wrapped deep range copy-construction of category records, calling the deep copy constructor at `0x0045d420` for each `0x2b0` record. Best name: `RankingCategoryRecordRangeCopyConstructDeep`. Best owner: [UID:0000BK].
- `0x0045d6d6-0x0045d6e0`: `0xcc` padding.
- `0x0045d6e0-0x0045d740`: allocates `RankingUserEntry` vector storage for `count * 0x4c`, with zero-count null return, large-allocation aligned allocation, and max-count check. Best name: `RankingUserEntryVectorAllocateStorage`. Best owner: [UID:0000BL].

This is not one source-authored method. It is a source-declared/generated-binary helper island caused by container lifetime, range construction, and vector allocation/destruction. The narrow owners are split between collection storage and record user-entry storage. The parent [UID:0001ZD] should therefore be a non-emitting split/index, or replaced by child pages with blank formal C++.

Rejected alternatives:

- Keep [UID:0001ZD] as [UID:0000MZ] file-owned aggregate: rejected because the helper semantics route through concrete [UID:0000BK]/[UID:0000BL] types and the file-level owner is too broad.
- Route all helpers to [UID:0000BK] `RankingCategoryCollection`: rejected because `0x0045d5f0` and `0x0045d6e0` are generic `RankingUserEntry` vector storage helpers used by user-entry vector insert/clone children, not collection-only logic.
- Route all helpers to [UID:0000BL] `RankingCategoryRecord`: rejected because `0x0045d530`, `0x0045d5c0`, and `0x0045d660` are category-record vector/range helpers and their ordinary call paths originate in category-record vector management.
- Populate C++ for current [UID:0001ZD]: rejected because hand-porting MSVC allocation, EH, and container helper bodies into one formal block would obscure the source declaration that should produce them.

## Heuristic / Inference Reanalysis And Validation

Best defensible source directions:

- The accessor names `GetListIndex`, `GetCategoryId`, `GetStateCode`, `CopyStartTimeParts`, `CopyEndTimeParts`, `GetTitleText`, `GetUserEntryAt`, and `ResetUserEntries` should be retained. They match current IDA names, exact body behavior, and call-site usage. More embellished names such as `GetRankingCategoryId`, `GetRewardState`, `GetStartDateTime`, or `ClearUserRows` were considered but rejected because they either add redundant class context, overfit one caller, or lose the exact copy/reset semantics in the binary.
- `RankingDateTimeParts` is the best support type name. The type is not symbol-proven, but the layout is validated by both the setters and UI formatter. A Windows `SYSTEMTIME`-style name was rejected because the field order is `second, minute, hour, day, month, year` plus three extra copied dwords, not a standard `SYSTEMTIME`.
- `m_stateCode` is better than `m_rewardState` for `+0x08`. The reward-claim response writes state `1`, but list and event-card callers also use values `0` and `2` to choose UI availability/icons. The broader field name keeps the documented behavior accurate until state constants are proven.
- `m_localPlayerRank` is the correct interpretation of `+0x268`. The old coverage wording "selected-user index" is contradicted by reset-to-`-1`, parser/local-player writes, and user-list paint display behavior. This should be corrected in [UID:0002KA], [UID:0000BL], [UID:0001VN], and coverage.
- [UID:0002K6] is source-ready despite the lack of explicit lower-bound guard. The binary implements only an upper-bound test, and checked callers pass nonnegative indexes. The first-draft C++ intentionally preserves the binary-shaped `index < count` condition instead of adding a new `index >= 0` guard.
- [UID:0001ZD] should not be treated as dead or legacy. It has live ordinary xrefs: `0x0045d530` from the collection destructor thunk, `0x0045d5c0` from category-record vector growth cleanup, `0x0045d5f0` from parsers/copy/destruct paths, `0x0045d660` from vector growth, and `0x0045d6e0` from user-entry insert/clone helpers. It is live generated/container support, not a source-authored aggregate method.

Evidence checked:

- Exact IDA decompilation for every primary accessor/helper and all five [UID:0001ZD] helper starts.
- Current xrefs for all primary starts and helper starts.
- Disassembly end boundaries and padding bytes for [UID:0001ZD].
- Prior executed B reports for [UID:0001ZC], [UID:0002K9], and ranking reward vector helpers.
- Layout docs and class docs for `RankingCategoryRecord`, `RankingCategoryCollection`, and `RankingCategoryRecordLayout`.
- User-list paint call sequence validating date/time field order.
- Packed setter bodies [UID:0002K7]/[UID:0002K8] validating packed date/time parameter direction.

Validation or contradiction of existing docs:

- Existing docs correctly identify all eight accessor/helper ranges and the broad [UID:0001ZD] helper island.
- Existing coverage/doc text is stale for [UID:0002K1] xref count, [UID:0002K3]/[UID:0002K4] date/time type uncertainty, and [UID:0002KA] "selected-user index" wording.
- Existing [UID:0001ZD] docs are directionally correct that the range contains vector teardown/copy/allocation helpers, but the parent page is too broad for formal C++ and should be split or reclassified as a non-emitting index.

Score/source-placement/final-C++ impact:

- The eight `RankingCategoryRecord` child methods can rise to `86/91` or better and receive formal C++ because they are exact, source-facing method bodies with valid owner/emitter route through [UID:0000BL].
- [UID:0001ZD] can rise as documented evidence but should not emit as a single helper-group. The score increase reflects resolved liveness, boundaries, owner split, and helper names; it does not imply formal C++ readiness.
- Support docs should update field/type names so generated [UID:0000BL] class declarations can support these method snippets without raw offsets or `sub_`/`dword_` placeholders.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:0002K0]-[UID:0002K6] and [UID:0002KA] after the support type/field-name refresh is applied. Use source-like class methods, not raw offset casts.

[UID:0002K0]:

```cpp
short RankingCategoryRecord::GetListIndex() const
{
    return m_listIndex;
}
```

[UID:0002K1]:

```cpp
int RankingCategoryRecord::GetCategoryId() const
{
    return m_categoryId;
}
```

[UID:0002K2]:

```cpp
int RankingCategoryRecord::GetStateCode() const
{
    return m_stateCode;
}
```

[UID:0002K3]:

```cpp
RankingDateTimeParts* RankingCategoryRecord::CopyStartTimeParts(RankingDateTimeParts* out) const
{
    *out = m_startTime;
    return out;
}
```

[UID:0002K4]:

```cpp
RankingDateTimeParts* RankingCategoryRecord::CopyEndTimeParts(RankingDateTimeParts* out) const
{
    *out = m_endTime;
    return out;
}
```

[UID:0002K5]:

```cpp
const wchar_t* RankingCategoryRecord::GetTitleText() const
{
    return m_title;
}
```

[UID:0002K6]:

```cpp
RankingUserEntry* RankingCategoryRecord::GetUserEntryAt(int index) const
{
    if (index < m_userEntriesEnd - m_userEntriesBegin)
        return m_userEntriesBegin + index;

    return NULL;
}
```

[UID:0002KA]:

```cpp
void RankingCategoryRecord::ResetUserEntries()
{
    m_userEntriesEnd = m_userEntriesBegin;
    m_localPlayerRank = -1;
}
```

Do not populate formal C++ for current [UID:0001ZD]. If exact child pages are created, keep their formal C++ blank as source-declared/generated-binary container helpers. The intended source C++ should be expressed by `RankingCategoryCollection` and `RankingCategoryRecord` declarations and methods, not by hand-authored MSVC vector helper bodies.

## Exact Score And Metadata Recommendations

For the eight `RankingCategoryRecord` method pages:

```text
[UID:0002K0] COMPLETION:87 CONFIDENCE:92 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K1] COMPLETION:88 CONFIDENCE:93 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K2] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K3] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K4] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K5] COMPLETION:88 CONFIDENCE:93 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002K6] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[UID:0002KA] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
```

For [UID:0001ZD]:

```text
[UID:0001ZD] COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:NONE RECONSTRUCTABLE:FALSE EMITTER_UIDS:
```

If the supervisor keeps [UID:0001ZD] as a temporary broad page before child creation, keep formal C++ blank and describe it as a split/index, not a source-authored method.

Recommended child-page metadata if split now:

```text
[NEW] 0x0045d530-0x0045d5b5 RankingCategoryRecordVectorDestroy COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BK RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BK
[NEW] 0x0045d5c0-0x0045d5eb RankingCategoryRecordRangeDestroyUserEntries COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BK RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BK
[NEW] 0x0045d5f0-0x0045d653 RankingUserEntryVectorDestroy COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
[NEW] 0x0045d660-0x0045d6d6 RankingCategoryRecordRangeCopyConstructDeep COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BK RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BK
[NEW] 0x0045d6e0-0x0045d740 RankingUserEntryVectorAllocateStorage COMPLETION:86 CONFIDENCE:91 CANONICAL_OWNER:0000BL RECONSTRUCTABLE:TRUE EMITTER_UIDS:0000BL
```

## Support Docs To Update

- [UID:0000BL] `by-class/RankingCategoryRecord.md`: update method inventory and field wording for `m_stateCode`, `RankingDateTimeParts`, `m_userEntriesBegin/End/Capacity`, `m_loadedRowsCategoryId`, `m_localPlayerRank`, `m_localPlayerName[32]`, and `m_localPlayerScore`.
- [UID:0001VN] `by-type/by-struct/RankingCategoryRecordLayout.md`: add the `RankingDateTimeParts` support struct and correct `+0x268` from selected-user wording to local-player rank.
- [UID:0000Y9] aggregate page: refresh child status text to show [UID:0002K0]-[UID:0002K6]/[UID:0002KA] clearing the method-level gate and [UID:0001ZD] requiring split/index treatment.
- [UID:0001ZC]/[UID:0000BK] collection docs: add [UID:0001ZD] child split notes for category-record vector destroy/range copy helper ownership.
- [UID:0002K7]/[UID:0002K8] support pages: optional but recommended wording refresh only, documenting packed parameter order as `packedDate` then `packedTime` and the six `RankingDateTimeParts` fields. No score change is required by this assignment.
- `auto-generated/-ag-memory-coverage.md` and generated output should be refreshed only after supervisor doc edits and rescoring.

## Supervisor-Owned Coverage Row Text

Placement: replace rows for [UID:0002K0]-[UID:0002K6] and [UID:0002KA] under the existing [UID:0000Y9] `RankingCategoryRecord` aggregate. Leave [UID:0002K7], [UID:0002K8], and [UID:0002K9] rows in place unless the supervisor separately chooses to refresh their support text.

```markdown
        - [UID:0002K0][0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex](by-memory/0x0045bf60-0x0045bf63.RankingCategoryRecordGetListIndex.md) 0x0045bf60-0x0045bf63 | method | RankingCategoryRecordGetListIndex : reconstructable : 87% : very strong : Exact source-facing accessor returning the 16-bit `m_listIndex` field at `+0x00`; one live event-list caller and formal C++ ready.
        - [UID:0002K1][0x0045bf70-0x0045bf73.RankingCategoryRecordGetCategoryId](by-memory/0x0045bf70-0x0045bf73.RankingCategoryRecordGetCategoryId.md) 0x0045bf70-0x0045bf73 | method | RankingCategoryRecordGetCategoryId : reconstructable : 88% : very strong : Exact category-id accessor returning `m_categoryId` at `+0x04`; current IDA shows nine ranking dialog/list/reward xrefs including two raw/null-function references, and formal C++ ready.
        - [UID:0002K2][0x0045bf80-0x0045bf83.RankingCategoryRecordGetStateCode](by-memory/0x0045bf80-0x0045bf83.RankingCategoryRecordGetStateCode.md) 0x0045bf80-0x0045bf83 | method | RankingCategoryRecordGetStateCode : reconstructable : 86% : very strong : Exact state/status accessor returning `m_stateCode` at `+0x08`; values `0/1/2` drive event-card/list UI and reward-status handling, and formal C++ ready.
        - [UID:0002K3][0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts](by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md) 0x0045bf90-0x0045bfae | method | RankingCategoryRecordCopyStartTimeParts : reconstructable : 86% : very strong : Exact `RankingDateTimeParts` 36-byte copy from `m_startTime` at `+0x0c`; paint formatter and packed setter validate second/minute/hour/day/month/year order, and formal C++ ready.
        - [UID:0002K4][0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts](by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md) 0x0045bfb0-0x0045bfce | method | RankingCategoryRecordCopyEndTimeParts : reconstructable : 86% : very strong : Exact `RankingDateTimeParts` 36-byte copy from `m_endTime` at `+0x30`; paint formatter and packed setter validate second/minute/hour/day/month/year order, and formal C++ ready.
        - [UID:0002K5][0x0045bfd0-0x0045bfd3.RankingCategoryRecordGetTitleText](by-memory/0x0045bfd0-0x0045bfd3.RankingCategoryRecordGetTitleText.md) 0x0045bfd0-0x0045bfd3 | method | RankingCategoryRecordGetTitleText : reconstructable : 88% : very strong : Exact title-buffer accessor returning `m_title` / `wchar_t[256]` at `+0x54`; rendering callers validated, and formal C++ ready.
        - [UID:0002K6][0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01a.RankingCategoryRecordGetUserEntryAt.md) 0x0045bfe0-0x0045c01a | method | RankingCategoryRecordGetUserEntryAt : reconstructable : 86% : very strong : Bounds-checked lookup in the `RankingUserEntry` vector at `+0x258/+0x25c` with `0x4c` stride; caller supplies nonnegative UI row indexes and formal C++ should preserve the binary-shaped upper-bound test.
        - [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) 0x0045c240-0x0045c256 | method | RankingCategoryRecordResetUserEntries : reconstructable : 86% : very strong : Resets the user-entry vector current/end pointer to begin and resets `m_localPlayerRank` at `+0x268` to `-1`; prior selected-user-index wording is rejected, and formal C++ should be `void`.
```

Placement: replace the current [UID:0001ZD] row at `0x0045d530-0x0045d740` with this non-emitting split/index row, then insert exact child and padding rows below it if the split is executed now. Keep the existing `0x0045d740-0x0045d750` padding row after the split block.

```markdown
    - [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) 0x0045d530-0x0045d740 | split-index | RankingCategoryVectorStorageHelpers : ignored/non-emitting : 86% : very strong : Mixed live source-declared/generated-binary helper island now split by evidence into category-record vector helpers owned by [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) and user-entry vector helpers owned by [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md); current parent formal C++ must remain blank.
        - [UID:ASSIGN_RCR_VECTOR_DESTROY][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md) 0x0045d530-0x0045d5b5 | compiler-helper | RankingCategoryRecordVectorDestroy : reconstructable : 86% : very strong : Destroys a `0x2b0`-stride category-record vector, tears down each embedded user-entry vector, frees storage, and clears begin/end/capacity; owner/emitter [UID:0000BK], final C++ blank.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d5b5-0x0045d5c0 | padding | RankingCategory vector helper alignment : ignored : 100% : strong : Confirmed `0xcc` padding between category-record vector destroy and range user-entry cleanup helper.
        - [UID:ASSIGN_RCR_RANGE_USERENTRY_DESTROY][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md) 0x0045d5c0-0x0045d5eb | compiler-helper | RankingCategoryRecordRangeDestroyUserEntries : reconstructable : 86% : very strong : Walks a `0x2b0` category-record range and destroys each embedded user-entry vector at record `+0x258`; owner/emitter [UID:0000BK], final C++ blank.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d5eb-0x0045d5f0 | padding | RankingCategory vector helper alignment : ignored : 100% : strong : Confirmed `0xcc` padding between range user-entry cleanup and user-entry vector destroy.
        - [UID:ASSIGN_USERENTRY_VECTOR_DESTROY][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) 0x0045d5f0-0x0045d653 | compiler-helper | RankingUserEntryVectorDestroy : reconstructable : 86% : very strong : Destroys/frees a `RankingUserEntry` vector triplet with `0x4c` stride and MSVC large-allocation validation; owner/emitter [UID:0000BL], final C++ blank.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d653-0x0045d660 | padding | RankingCategory vector helper alignment : ignored : 100% : strong : Confirmed `0xcc` padding between user-entry vector destroy and category-record range copy construction.
        - [UID:ASSIGN_RCR_RANGE_COPY_DEEP][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md) 0x0045d660-0x0045d6d6 | compiler-helper | RankingCategoryRecordRangeCopyConstructDeep : reconstructable : 86% : very strong : SEH-wrapped `0x2b0`-stride range copy construction that calls `RankingCategoryRecordCopyConstructDeep` for each record; owner/emitter [UID:0000BK], final C++ blank.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d6d6-0x0045d6e0 | padding | RankingCategory vector helper alignment : ignored : 100% : strong : Confirmed `0xcc` padding between category-record range copy construction and user-entry vector allocation.
        - [UID:ASSIGN_USERENTRY_VECTOR_ALLOCATE][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md) 0x0045d6e0-0x0045d740 | compiler-helper | RankingUserEntryVectorAllocateStorage : reconstructable : 86% : very strong : Allocates `count * 0x4c` bytes for `RankingUserEntry` storage, returning null for zero count and using aligned large-allocation metadata for allocations at or above `0x1000`; owner/emitter [UID:0000BL], final C++ blank.
```

Replace `ASSIGN_*` marker UIDs with supervisor-assigned UIDs if child pages are created.

## Validation Commands

Run after supervisor applies doc/support/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality-removed.md](0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the [UID:0001ZD] split is executed, add the new child paths to the doc-link and completion-score validation commands, then refresh generated coverage/source output.

## Blockers And Follow-Up

- No blocker remains for [UID:0002K0]-[UID:0002K6] or [UID:0002KA] to clear the `85/85` gate and receive formal method C++ after supervisor support-doc updates.
- [UID:0001ZD] requires supervisor-owned split/reclassification work before it is source-quality clean. The evidence is strong enough to execute that split; the blocker is only that B002 is report-only for this assignment.
- Useful follow-up: separately refresh [UID:0002K7]/[UID:0002K8] with the now-validated `RankingDateTimeParts` field order and `packedDate`/`packedTime` parameter names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002K0"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002K0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
