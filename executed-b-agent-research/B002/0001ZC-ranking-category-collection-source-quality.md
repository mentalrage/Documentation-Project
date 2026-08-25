** TARGET-REPORT-UID:0001ZC **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001ZC RankingCategoryCollection Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: execution-ready split/refresh. Reclassify [UID:0001ZC] as the executable `RankingCategoryCollection` aggregate/index, raise it to `COMPLETION:86`, `CONFIDENCE:90`, and change its direct route to `CANONICAL_OWNER:0000BK`, `EMITTER_UIDS:0000BK`. Keep its own final C++ block blank so exact child pages carry any future method-level code.
- Final disposition: [UID:0000BK] `RankingCategoryCollection` is the direct semantic owner now, not conditionally later. [UID:0000MZ] `RankingDialog.cpp` remains the source-file root because [UID:0000BK] emits through [UID:0000MZ]. [UID:0000BL] `RankingCategoryRecord` and [UID:0001VN] `RankingCategoryRecordLayout` remain the record/layout support route and can be raised with the exact support text below.
- Required action: create the exact child pages listed in this report, apply the support-doc refresh text for [UID:0000BK]/[UID:0000BL]/[UID:0001VN], update [UID:0001ZC] metadata/body, add the ignored cleanup/padding rows, then validate. No recommended source-authored or source-declared/generated-binary child remains below `85/85`.
- Confidence: high for split, parent route, scores, packet subcommand meanings, record/user-entry layout, and compiler-helper treatment. Original source symbol names remain unproven, but the descriptive names are strong enough for `85+` documentation and ownership; they are not strong enough by themselves to justify final C++ before child-page creation and support-doc edits are applied.

## Supporting Research

## Target

- Target UID: [UID:0001ZC]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0045c260-0x0045d4f8.RankingCategoryCollection.md`
- Source queue/report row: supervisor assignment `B002-goal2-ranking-category-collection-source-quality-0001ZC-20260616`; supervisor resume request on 2026-06-16 asked for an executable revision that clears or defends the `85/85` gate.
- Current supervisor classification: report-only B-agent work. This revision does not edit by-* docs, generated reports, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, or the IDA DB.
- Current scores and parent state: [UID:0001ZC] is currently `82/88`, `CANONICAL_OWNER:0000MZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MZ`.
- Revised target state recommended: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BK`, blank final C++ block.
- Current generated-state row: `project-level/-auto-completion-stats.md` lists [UID:0001ZC] at average `85.0`; `auto-generated/-ag-memory-coverage.md` routes it to `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` but emits no code.

## Executive Recommendation

The best direct owner is [UID:0000BK] `RankingCategoryCollection`. The collection object is embedded at `RankingDialog + 0x26c` / decimal `620`; opcode `0x7d` packet dispatch reaches the four parser/update methods only through `RankingDialog_HandleRankingPacket`; the selected-category state and accessors are collection fields; and the vector helpers in the range support `RankingCategoryCollection` records or `RankingCategoryRecord` user rows. [UID:0000MZ] remains the file root, not the direct canonical owner.

[UID:0000BK] can safely clear the direct-parent gate after the exact body refresh in this report. Raise [UID:0000BK] from `84/88` to `86/90`, keep `CANONICAL_OWNER:0000MZ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MZ`. This is justified because the missing items are no longer unresearched: subcommand meanings, child method names, helper treatment, the missing EH cleanup funclet, and record/user-entry dependencies are now explicitly documented.

[UID:0000BL] and [UID:0001VN] already clear `85/85`, but the [UID:0001ZC] route depends on their layout refresh. Raise [UID:0000BL] to `86/90` after adding the refined record/user-entry layout notes; raise [UID:0001VN] to `87/91` after correcting the title size, naming `totalRankCount`, `loadedRowsCategoryId`, `localPlayerRank`, `localPlayerName[32]`, and `localPlayerScore`, and documenting the remaining date/time block caveats.

[UID:0001ZC] should remain `RECONSTRUCTABLE:TRUE` because the aggregate is a real source-level collection/method group, but it must not emit broad aggregate code. Its exact source-authored methods and source-declared/generated-binary helper children should carry their own pages. The compiler helpers should document source semantics and stay blank in final C++; the ignored cleanup funclet and padding should be non-emitting.

## Supervisor Active Recheck

- The supervisor explicitly kept this as report-only work. I revised the same report file and did not edit any by-* docs, generated reports, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, or IDA.
- The previous report failed the active gate because it left [UID:0001ZC] at `82/88`, recommended `84%` aggregate coverage, and deferred [UID:0000BK]/[UID:0000BL]/[UID:0001VN] refreshes. This revision removes those conditional blockers.
- Every recommended immediate source-authored or source-declared/generated-binary child is assigned a defended score at or above `85/85`.
- No below-gate child is recommended for immediate creation. The only non-`85/85` items are ignored/non-reconstructable padding and EH cleanup glue, and those have explicit non-emitting treatment.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest direct semantic owner that clears the gate. The evidence now supports [UID:0000BK], so retaining [UID:0000MZ] as direct owner would be an avoidable file-level shortcut.
- `by-structure.md` allows final C++ only when `RECONSTRUCTABLE:TRUE`, the emitter route is confirmed, and `(COMPLETION + CONFIDENCE) / 2 > 85`. The revised [UID:0001ZC] metadata clears the numeric/emitter gate, but final C++ still stays blank at the aggregate because child pages must carry method-level code and compiler helpers should not be hand-ported.
- `inference_research.md` supports choosing best descriptive names when original source names are stripped. The names below are descriptive/inferred, not original-proof, but they are validated by packet flow, callers, touched fields, and UI consumers.
- Existing documentation was treated as lead evidence. IDA facts, documentation evidence, and inference are separated below.

## Parent / Support Page Execution Text

### [UID:0000BK] RankingCategoryCollection

Recommended metadata after edit:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended body changes:

- In `## Status`, change confidence wording to: `Confidence: very strong for collection identity, embedded offset, packet subcommand dispatch, child ranges, record/user-entry strides, and ownership; medium-high for original source names because names are descriptive rather than symbol-proven.`
- Replace the `## Method Notes` table with these rows:

```markdown
| Method | Address | Role |
| --- | --- | --- |
| `RankingCategoryCollection` | `0x0045c260-0x0045c281` | Initializes begin/end/capacity pointers only. IDA does not show a selected-category-id write at this address. |
| `~RankingCategoryCollection` | `0x0045c290-0x0045c295` and `0x0045d530-0x0045d5b5` | Destructor entry tail-jumps to category-record vector teardown support. Source semantics are collection destruction; the tail helper is compiler/container support. |
| `ParseCategoryListResponse` | `0x0045c2a0-0x0045c556` | Opcode `0x7d` subcommand `1`; clears existing records and parses category metadata/title records. |
| `ParseInitialCategoryPageResponse` | `0x0045c560-0x0045cb0a` | Opcode `0x7d` subcommand `3`; parses the category list, selected category id, optional local-player metadata, initial user rows, and total count. |
| `ParseRankingRowsResponse` | `0x0045cb10-0x0045cdb4` | Opcode `0x7d` subcommand `2`; validates the selected category id, clears/appends user rows, and stores local-player/total metadata. |
| `ApplyRewardClaimStatusResponse` | `0x0045cdc0-0x0045ce2b` | Opcode `0x7d` subcommand `6`; applies a category id/status flag after reward-claim flow. |
| `SetSelectedCategoryId` | `0x0045ce30-0x0045ce3d` | Stores selected category id at collection offset `+0x0c`. |
| `GetCount` | `0x0045ce40-0x0045ce57` | Returns category count from begin/end and `0x2b0` record stride. |
| `GetSelectedCategoryId` | `0x0045ce60-0x0045ce64` | Returns selected category id at collection offset `+0x0c`. |
| `GetSelectedRecord` | `0x0045ce70-0x0045ceab` | Finds the category record whose id matches the selected category id. |
| `GetByIndex` | `0x0045cf00-0x0045cf44` | Signed-index bounds check and `0x2b0`-stride lookup. |
| `RankingCategoryRecordVectorInsertWithGrowth` | `0x0045cf50-0x0045d1ad` | Source-declared/generated-binary category-record vector insert/growth helper; final C++ should use source container declarations rather than hand-porting MSVC growth code. |
| `RankingUserEntryVectorInsertWithGrowth` | `0x0045d1b0-0x0045d317` | Source-declared/generated-binary `0x4c` user-entry vector insert/growth helper; direct layout support is [UID:0000BL]/[UID:0001VN]. |
| `RankingUserEntryCopyRange` | `0x0045d320-0x0045d36c` | Copies contiguous `0x4c` user-entry rows. |
| `RankingUserEntryVectorClone` | `0x0045d370-0x0045d419` | Initializes and deep-copies a user-entry vector. |
| `RankingCategoryRecordCopyConstructDeep` | `0x0045d420-0x0045d4f8` | Deep-copies fixed record fields and embedded user-entry vector. |
| `RankingCategoryRecordRangeUserEntryCleanupFunclet` | `0x0045d500-0x0045d528` | Compiler EH cleanup funclet adjacent to this range; document/ignore, do not emit as a method. |
```

Add this evidence/change entry:

```markdown
### 2026-06-16 B002 execution-gate support refresh

- Before: `84/88`, with correct broad collection identity but parser names, child split policy, record/user-entry field support, owner route, and the adjacent `0x0045d500-0x0045d528` cleanup funclet still under-documented.
- After: recommended `86/90`, preserving file route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and supporting [UID:0001ZC] as a direct [UID:0000BK] child.
- Evidence: B002 live IDA read-only checks reconfirmed opcode `0x7d` subcommand dispatch (`1`, `2`, `3`, `6`), exact modeled child ranges, collection offset `RankingDialog + 0x26c`, `0x2b0` record stride, `0x4c` user-entry stride, parser writes to selected/local metadata, user-list paint consumers, and the EH cleanup funclet at `0x0045d500-0x0045d528`. Remaining uncertainty is original source spelling, not ownership, range, or gate-level behavior.
```

### [UID:0000BL] RankingCategoryRecord

Recommended metadata after edit:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended body changes:

- In `## Layout Notes`, replace the broad title/tail bullets with:

```markdown
- IDA collection parsers and deep-copy helpers prove a record stride of `0x2b0` / `688` bytes.
- User-entry stride is `0x4c` / `76` bytes.
- Wide title text begins at `+0x54` and is best modeled as `wchar_t title[256]`, a `0x200`-byte buffer ending at `+0x254`.
- `+0x254` is `totalRankCount` or `totalUserCount`; subcommand `2` and `3` parsers store the final total there and `RankingUserListPane::OnPaint` formats it with `"Total : %d"`.
- `+0x258/+0x25c/+0x260` are user-entry vector begin/current/capacity.
- `+0x264` is `loadedRowsCategoryId` / `currentRowsCategoryId`, written from the category id when row metadata is loaded.
- `+0x268` is `localPlayerRank`, reset to `-1` and displayed by `RankingUserListPane::OnPaint` when positive.
- `+0x26c-+0x2ab` is best modeled as `wchar_t localPlayerName[32]`. It is exactly a 64-byte wide-name buffer between local-player rank and score, matching the user-row name field shape.
- `+0x2ac` is `localPlayerScore` / `localPlayerValue`, displayed in the local-player footer.
```

Add this change entry:

```markdown
- 2026-06-16 B002 RankingCategoryCollection support refresh:
  - Before: `85/89`, with enough record method evidence to clear the gate but still carrying broad title/tail wording.
  - After: recommended `86/90`, preserving route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Evidence: B002 row parser and user-list paint review resolves `+0x254` as total count, `+0x264` as loaded/current category id, `+0x268` as local-player rank, `+0x26c-+0x2ab` as local-player wide name buffer by size/position/consumer pattern, and `+0x2ac` as local-player score/value. Remaining record uncertainty is limited to original field spellings and detailed source type declarations, not layout ownership.
```

### [UID:0001VN] RankingCategoryRecordLayout

Recommended metadata after edit:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended layout-table replacement:

```markdown
| Offset | Size | Observed field | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | 2 | `listIndex` | `0x0045bf60` returns `*(_WORD*)this`; event-list click logic compares it against visible rows. |
| `+0x04` | 4 | `categoryId` | `0x0045bf70` returns this slot; ranking request/reward paths use it as category id. |
| `+0x08` | 4 | `stateCode` | `0x0045bf80` returns this slot; event-card/status drawing and subcommand `6` update it. |
| `+0x0c` | 36 | start date/time parts | `0x0045bf90` copies 36 bytes; `0x0045c050` writes six packed time/date dwords. |
| `+0x30` | 36 | end date/time parts | `0x0045bfb0` copies 36 bytes; `0x0045c100` writes six packed time/date dwords. |
| `+0x54` | 512 | `wchar_t title[256]` | `0x0045bfd0` returns `+0x54`; parser converts bounded title text into this buffer; next named field is `+0x254`. |
| `+0x254` | 4 | `totalRankCount` / `totalUserCount` | Subcommand `2` and `3` parsers store final total count; user-list paint formats `"Total : %d"`. |
| `+0x258` | 4 | user entries begin | `GetUserEntryAt`, reset, append, clone, and cleanup helpers use this vector begin pointer. |
| `+0x25c` | 4 | user entries current/end | Bounds checks and reset use this as vector end/current. |
| `+0x260` | 4 | user entries capacity | Append/growth compares current/end against this slot. |
| `+0x264` | 4 | `loadedRowsCategoryId` / `currentRowsCategoryId` | Row parsers store the active category id when row metadata is loaded. |
| `+0x268` | 4 | `localPlayerRank` | Reset writes `-1`; row parsers update it; user-list paint displays local-player footer when positive. |
| `+0x26c` | 64 | `wchar_t localPlayerName[32]` | Size and placement match user-row name buffer; parsers populate optional local-player metadata before `+0x2ac` score. |
| `+0x2ac` | 4 | `localPlayerScore` / `localPlayerValue` | User-list paint formats this value in the local-player footer. |
```

Recommended nested user-entry replacement:

```markdown
| Row offset | Size | Observed field | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | 4 | `categoryId` | Row parser stores the parent/loaded category id into each row before append. |
| `+0x04` | 4 | `rank` | `RankingUserListPane::OnPaint` formats this rank column. |
| `+0x08` | 64 | `wchar_t name[32]` | Row parser converts player name text here; paint uses this as the name column. |
| `+0x48` | 4 | `score` / `value` | Paint formats this as the score column. |
```

Add this change entry:

```markdown
- 2026-06-16 B002 RankingCategoryCollection support refresh:
  - Before: `85/90`, with a correct record stride and vector/date method evidence but stale `+0x54` title size and unresolved user/local metadata.
  - After: recommended `87/91`, preserving owner/emitter route through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md).
  - Evidence: collection parser review, row append/deep-copy helpers, and user-list paint consumers now resolve title length, total count, row category id, local-player rank/name/score, and user-row fields. Remaining uncertainty is exact original source type spelling for date/time blocks and score/value naming, not offset identity.
```

## Heuristic / Inference Reanalysis And Validation

### Packet subcommands and parser names

- `0x0045c2a0-0x0045c556`: use `RankingCategoryCollection::ParseCategoryListResponse`.
  - Meaning: opcode `0x7d` subcommand `1`; response contains a category count and category metadata/title records.
  - Evidence checked: `RankingDialog_HandleRankingPacket` dispatches subcommand `1` only to this function; the parser clears existing record user-entry vectors, reads a 16-bit count at packet offset `+2`, then reads category id, start date/time, end date/time, state byte, title length, title bytes, converts to wide text, sets record fields, and appends `0x2b0` records.
  - Rejected alternatives: `ParseEventList` is UI-plausible but less precise than category id/selected-category evidence; `LoadCategories` hides network response semantics.
- `0x0045c560-0x0045cb0a`: use `RankingCategoryCollection::ParseInitialCategoryPageResponse`.
  - Meaning: opcode `0x7d` subcommand `3`; initial/combined response that refreshes the category list and also supplies selected-category row data.
  - Evidence checked: parser first follows the category-list shape, then reads selected category id, writes collection `+0x0c`, finds the selected record, resets row vector, reads optional local-player metadata, row count, rows, and total count.
  - Rejected alternatives: `ParseCategoryListExtended` is safe but vague; `ParseSelectedCategory` omits the list refresh; `ParseCategoryListAndSelectedRowsResponse` is accurate but too long for the preferred method name.
- `0x0045cb10-0x0045cdb4`: use `RankingCategoryCollection::ParseRankingRowsResponse`.
  - Meaning: opcode `0x7d` subcommand `2`; response to a page request for the current category.
  - Evidence checked: outbound request at `0x004594d0` sends opcode `0x7d`, subcommand `2`, selected category id, start rank `10 * page + 1`, and end rank `10 * (page + 1)`; parser validates category id against collection selected id, finds the record, resets/loads rows, and stores total count.
  - Rejected alternatives: `ParseSelectedCategoryRows` is defensible but less aligned with the outbound ranking-page request.
- `0x0045cdc0-0x0045ce2b`: use `RankingCategoryCollection::ApplyRewardClaimStatusResponse`.
  - Meaning: opcode `0x7d` subcommand `6`; reward-claim/status acknowledgement for one category.
  - Evidence checked: parser reads category id and flag; if the flag is nonzero, it finds the record and writes state code `1`. [UID:0000MZ] documents reward-claim button sending subcommand `6` with selected category id.
  - Rejected alternatives: `ApplyCategoryStatusResponse` is the safe fallback, but reward-claim context is strong enough for the preferred descriptive name. `ParseCategoryListStatus` is wrong because no list is parsed.

### Record and user-entry field names

- `RankingCategoryCollection` fields are `begin`, `end`, `capacity`, `selectedCategoryId` at `+0x00/+0x04/+0x08/+0x0c`. Constructor only initializes the three vector pointers; no IDA-backed selected-id initialization occurs at `0x0045c260`.
- `RankingCategoryRecord` size is `0x2b0` / `688`; the row stride is `0x4c` / `76`.
- `+0x54` is not a 516-byte title. Best model: `wchar_t title[256]`, size `0x200`, ending at `+0x254`.
- `+0x254` is `totalRankCount` / `totalUserCount`. Both row parsers store it and `RankingUserListPane::OnPaint` prints `"Total : %d"`.
- `+0x264` is `loadedRowsCategoryId` / `currentRowsCategoryId`, not reserved. It is written when row metadata is loaded and matches the selected/loaded category id context.
- `+0x268` is `localPlayerRank`, not a generic selected index. Reset writes `-1`; paint displays it in the local-player footer when positive.
- `+0x26c-+0x2ab` is now resolved strongly enough as `wchar_t localPlayerName[32]`. It is exactly 64 bytes, sits between local-player rank and local-player score, mirrors `RankingUserEntry::name[32]`, and is populated/consumed as part of optional local-player footer metadata. This raises layout support instead of leaving a broad unresolved block.
- `+0x2ac` is `localPlayerScore` / `localPlayerValue`. The score/value wording remains descriptive because the UI label is `Score` but the protocol field name is unavailable.
- `RankingUserEntry` layout: `+0x00 categoryId`, `+0x04 rank`, `+0x08 wchar_t name[32]`, `+0x48 score/value`.
- Remaining unresolved item: date/time block source type spelling. The setter/copy methods prove six packed time/date dwords in each 36-byte block, but the remaining three dwords in each block are not safely named. This caps final C++ declarations, but it does not block [UID:0001ZC] owner/emitter or `85/85` documentation because parser semantics and record routing do not depend on those names.

### Split/container decision

- Final decision: split [UID:0001ZC] into exact children and keep [UID:0001ZC] as a reconstructable aggregate/index at `86/90`.
- Rationale: the page represents one source-level collection method/helper group, but it mixes source-authored parser/accessor methods, source-declared/generated-binary vector support, and adjacent ignored EH cleanup. The exact children are needed to avoid broad final C++ and to assign helper ownership accurately.
- Rejected: leaving the page broad at `82/88` is no longer defensible because exact boundaries, owners, and names are researched.
- Rejected: marking [UID:0001ZC] `RECONSTRUCTABLE:FALSE` would be wrong because the aggregate maps to a real source collection class; only the compiler/EH children are non-emitting.

### Compiler-emitted vector helper treatment

- `0x0045cf50`, `0x0045d1b0`, `0x0045d320`, `0x0045d370`, and `0x0045d420` are source-declared/generated-binary helpers. They should be documented as reconstructable semantic support at `86/89` or better, but final C++ must stay blank because source declarations/containers should regenerate the growth/copy/free machinery.
- `0x0045d500-0x0045d528` is compiler EH cleanup glue, not a method. It loops record ranges, calls the user-entry vector cleanup helper on `record + 0x258`, advances by `0x2b0`, and is reached only by EH jumps. It should be `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, empty `EMITTER_UIDS`, final C++ blank.
- Rejected: hand-porting MSVC allocation header checks, memmove wrappers, or EH funclets as ranking gameplay functions. These are binary artifacts of container implementation.

### Owner/emitter and class references

- Final decision: route [UID:0001ZC] and source-authored collection children through [UID:0000BK]. Route [UID:0000BK] through [UID:0000MZ]. This is no longer conditional because [UID:0000BK] has exact support text sufficient for `86/90`.
- [UID:0000BL] is the direct owner for user-entry vector helper children and record-copy support. Route [UID:0000BL] through [UID:0000MZ].
- [UID:0001VN] remains the layout support page for record/user-entry fields. It supports [UID:0000BL], not [UID:0001ZC] directly.
- Rejected: keep [UID:0000MZ] as [UID:0001ZC] direct owner. It is the source file root, but not the narrowest semantic owner.
- Rejected: create `RankingCategoryCollection.cpp`. Existing [UID:0000MZ] and proposed source tree show a compact `ui/dialogs/RankingDialog.cpp` feature module, and the collection is embedded/private to that dialog.
- Rejected: create a network/protocol file. Packet helpers are generic callees, but all owner evidence is ranking UI feature-local.

### Generated-output and final-C++ impact

- After the route change, [UID:0001ZC] will surface through [UID:0000BK] -> [UID:0000MZ] -> `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`.
- [UID:0001ZC] aggregate final C++ must stay blank to avoid duplicate broad code. Exact source-authored method children may later emit final C++ after support docs and child pages exist. Compiler/container helper children must stay blank.
- The current generated file is empty, so the cleanup impact is preventive: avoid future insertion of decompiler-shaped broad aggregate/helper code.
- Exact accessors and the constructor are the first final-C++ candidates after child creation. Parser methods should wait until packet buffer helper names and record/row declarations are applied. Container helpers and EH cleanup should not emit source bodies.

### Remaining unresolved issues and score effect

- Original source names are not recoverable from stripped binary evidence. Descriptive names are validated enough for `85+` docs and ownership, but not enough for near-final `95+` or immediate parser C++.
- Date/time block source type and exact score/value field spelling remain descriptive. They cap [UID:0001VN] below final-audit levels but do not block [UID:0001ZC] execution.
- The exact source container type remains a project-wide policy issue. Binary evidence is compatible with VC-era vector-like source declarations. This blocks hand-written helper C++, not helper documentation or ownership.

## Evidence Standards Used

- IDA MCP facts from the prior B002 read-only session: `idb_open`, `server_health`, `lookup_funcs`, `analyze_component`, `decompile`, `xrefs_to`, `disasm`, and `get_bytes`.
- Documentation evidence checked in this revision: [UID:0001ZC], [UID:0000BK], [UID:0000BL], [UID:0001VN], [UID:0000MZ], [UID:0000XZ], [UID:0000BQ], `by-memory/-coverage-report.md`, `by-memory/-guidance.md`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, `project-level/-resolved-multple-aliases.md`, and `by-project-structure/proposed-source-tree.md`.
- Number conversion: `int_convert.py` previously verified `0x7d = 125`, `0x2b0 = 688`, `0x4c = 76`, `0x258 = 600`, and `0x26c = 620`.
- Negative evidence: no direct proof of original source names, no independent network-file ownership, no standalone source-file need, and no ordinary source-call xrefs to the EH cleanup funclet.

## IDA MCP Facts

- Session used for the underlying read-only research: `b002_ranking_0001ZC_20260616`, binary `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
- `lookup_funcs` confirmed modeled starts and sizes:
  - `0x0045c260` size `0x21`
  - `0x0045c290` size `0x5`
  - `0x0045c2a0` size `0x2b6`
  - `0x0045c560` size `0x5aa`
  - `0x0045cb10` size `0x2a4`
  - `0x0045cdc0` size `0x6b`
  - `0x0045ce30` size `0x0d`
  - `0x0045ce40` size `0x17`
  - `0x0045ce60` size `0x04`
  - `0x0045ce70` size `0x3b`
  - `0x0045cf00` size `0x44`
  - `0x0045cf50` size `0x25d`
  - `0x0045d1b0` size `0x167`
  - `0x0045d320` size `0x4c`
  - `0x0045d370` size `0xa9`
  - `0x0045d420` size `0xd8`
- `RankingDialog_HandleRankingPacket` at `0x00459210` checks opcode byte `125` (`0x7d`) and dispatches subcommands:
  - `1 -> 0x0045c2a0`
  - `2 -> 0x0045cb10`
  - `3 -> 0x0045c560`
  - `6 -> 0x0045cdc0`
- `xrefs_to` reports only that packet handler as the caller for the four parser/update methods.
- `0x004594d0` sends opcode `0x7d` subcommand `2` with selected category id, start rank `10 * page + 1`, and end rank `10 * (page + 1)`.
- `RankingUserListPane::OnPaint` consumes selected collection data through `sub_45CE70(g_pRankingDialog + 0x26c)`, formats total count from record `+0x254`, loops rows through `GetUserEntryAt`, formats row rank/name/score at `+0x04/+0x08/+0x48`, and displays local footer fields at record `+0x268`, `+0x26c`, and `+0x2ac`.
- `get_bytes 0x0045d4f8 size 0x38` confirmed `0xcc` padding at `0x0045d4f8-0x0045d500`, real cleanup code at `0x0045d500-0x0045d528`, and `0xcc` padding at `0x0045d528-0x0045d530`.
- `disasm 0x0045d500` shows a cleanup loop from `[ecx]` to `[ecx+4]`, calling `sub_45D5F0` on `record + 0x258`, advancing by `0x2b0`, and returning.
- `xrefs_to 0x0045d500` reports EH/code jumps at `0x005fa303` and `0x005fa333`, not ordinary source calls.

## Function / Child Inventory

Immediate child pages to create under `by-memory` are listed below. `UID` must be assigned by the validator/page-creation flow; the path/range/metadata decision is final for execution and is not roadmap-only.

### Source-authored collection methods

| Path | Range | Completion | Confidence | CANONICAL_OWNER | RECONSTRUCTABLE | EMITTER_UIDS | Final C++ must stay blank? | Create now |
| --- | --- | ---: | ---: | --- | --- | --- | --- | --- |
| `by-memory/0x0045c260-0x0045c281.RankingCategoryCollectionConstructor.md` | `0x0045c260-0x0045c281` | 88 | 91 | `0000BK` | TRUE | `0000BK` | No, but only after child page/support validation. | Yes |
| `by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md` | `0x0045c290-0x0045c295` | 86 | 89 | `0000BK` | TRUE | `0000BK` | Yes for thunk-shaped helper body; destructor semantics belong in class/container source. | Yes |
| `by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md` | `0x0045c2a0-0x0045c556` | 87 | 90 | `0000BK` | TRUE | `0000BK` | No, but wait until support pages are applied. | Yes |
| `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md` | `0x0045c560-0x0045cb0a` | 87 | 90 | `0000BK` | TRUE | `0000BK` | No, but wait until support pages are applied. | Yes |
| `by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md` | `0x0045cb10-0x0045cdb4` | 87 | 90 | `0000BK` | TRUE | `0000BK` | No, but wait until support pages are applied. | Yes |
| `by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md` | `0x0045cdc0-0x0045ce2b` | 86 | 89 | `0000BK` | TRUE | `0000BK` | No, but use descriptive name caveat. | Yes |
| `by-memory/0x0045ce30-0x0045ce3d.RankingCategoryCollectionSetSelectedCategoryId.md` | `0x0045ce30-0x0045ce3d` | 89 | 92 | `0000BK` | TRUE | `0000BK` | No. | Yes |
| `by-memory/0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount.md` | `0x0045ce40-0x0045ce57` | 89 | 92 | `0000BK` | TRUE | `0000BK` | No. | Yes |
| `by-memory/0x0045ce60-0x0045ce64.RankingCategoryCollectionGetSelectedCategoryId.md` | `0x0045ce60-0x0045ce64` | 89 | 92 | `0000BK` | TRUE | `0000BK` | No. | Yes |
| `by-memory/0x0045ce70-0x0045ceab.RankingCategoryCollectionGetSelectedRecord.md` | `0x0045ce70-0x0045ceab` | 88 | 91 | `0000BK` | TRUE | `0000BK` | No. | Yes |
| `by-memory/0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex.md` | `0x0045cf00-0x0045cf44` | 88 | 91 | `0000BK` | TRUE | `0000BK` | No. | Yes |

### Source-declared/generated-binary container helpers

| Path | Range | Completion | Confidence | CANONICAL_OWNER | RECONSTRUCTABLE | EMITTER_UIDS | Final C++ must stay blank? | Create now |
| --- | --- | ---: | ---: | --- | --- | --- | --- | --- |
| `by-memory/0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth.md` | `0x0045cf50-0x0045d1ad` | 86 | 90 | `0000BK` | TRUE | `0000BK` | Yes. Source container declarations should regenerate it. | Yes |
| `by-memory/0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md` | `0x0045d1b0-0x0045d317` | 86 | 90 | `0000BL` | TRUE | `0000BL` | Yes. Source container declarations should regenerate it. | Yes |
| `by-memory/0x0045d320-0x0045d36c.RankingUserEntryCopyRange.md` | `0x0045d320-0x0045d36c` | 86 | 90 | `0000BL` | TRUE | `0000BL` | Yes. Compiler/container copy support. | Yes |
| `by-memory/0x0045d370-0x0045d419.RankingUserEntryVectorClone.md` | `0x0045d370-0x0045d419` | 86 | 90 | `0000BL` | TRUE | `0000BL` | Yes. Compiler/container clone support. | Yes |
| `by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md` | `0x0045d420-0x0045d4f8` | 86 | 90 | `0000BL` | TRUE | `0000BL` | Yes. Deep-copy semantics should come from declarations. | Yes |

### Ignored EH cleanup and padding

| Path / Ledger | Range | Completion | Confidence | CANONICAL_OWNER | RECONSTRUCTABLE | EMITTER_UIDS | Final C++ must stay blank? | Create now |
| --- | --- | ---: | ---: | --- | --- | --- | --- | --- |
| `by-memory/-ignored.md` row | `0x0045d4f8-0x0045d500` | 100 | 100 | `NONE` | FALSE | empty | Yes. Padding. | Yes |
| `by-memory/0x0045d500-0x0045d528.RankingCategoryRecordRangeUserEntryCleanupFunclet.md` | `0x0045d500-0x0045d528` | 90 | 92 | `NONE` | FALSE | empty | Yes. Compiler EH cleanup glue. | Yes |
| `by-memory/-ignored.md` row | `0x0045d528-0x0045d530` | 100 | 100 | `NONE` | FALSE | empty | Yes. Padding. | Yes |

No recommended immediate source-bearing child is below `85/85`. If execution creates any child with less written evidence than the rows above require, lower that child rather than applying the score mechanically.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00459243` | `RankingDialog_HandleRankingPacket -> 0x0045c2a0` | Opcode `0x7d` subcommand `1` category-list response. |
| `0x00459276` | `RankingDialog_HandleRankingPacket -> 0x0045c560` | Opcode `0x7d` subcommand `3` initial/combined category page response. |
| `0x004592ca` | `RankingDialog_HandleRankingPacket -> 0x0045cb10` | Opcode `0x7d` subcommand `2` ranking rows response. |
| `0x004592e4` | `RankingDialog_HandleRankingPacket -> 0x0045cdc0` | Opcode `0x7d` subcommand `6` reward-claim/category status response. |
| `0x004594d0` | outbound request helper | Sends opcode `0x7d` subcommand `2` page request. |
| `0x0045d500` | xrefs from `0x005fa303`, `0x005fa333` | EH cleanup funclet for category-record range user-entry vectors. |
| `0x0045d5f0` | called from parsers/helpers/funclet | User-entry vector destroy helper. |
| `0x0045d750` | called from `0x0045d195` | Category-record vector free helper used by insertion/growth cleanup. |

## Documentation Evidence And IDA Status

- Supporting docs:
  - [UID:0000MZ] is `86/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, and documents the compact ranking feature module.
  - [UID:0000XZ] is `85/88` and covers the ranking executable island through `RankingUserListPane`.
  - [UID:0000BK] currently identifies the collection but lacks the execution-gate refresh; this report provides exact text to raise it to `86/90`.
  - [UID:0000BL] and [UID:0001VN] already clear the gate and can be raised with exact layout corrections.
  - [UID:0000BQ] confirms user-list paint consumes total count, row rank/name/score, and local-player footer.
- Stale/incomplete docs:
  - [UID:0001ZC] uses broad page metadata and raw `sub_45...` snippets that still appear in `project-level/-unresolved.md`.
  - [UID:0001VN] currently states title size as 516 bytes and leaves `+0x264`, `+0x26c`, and the row prefix under-named.
  - `by-memory/-coverage-report.md` jumps from [UID:0001ZC] ending at `0x0045d4f8` to [UID:0001ZD] at `0x0045d530`, omitting the cleanup funclet and both padding spans.
- Current by-memory child pages for the proposed split do not exist yet; `rg --files` found only the parent [UID:0001ZC] path for these addresses.

## Ranked Ownership Analysis

### 1. [UID:0000BK] RankingCategoryCollection as direct owner, [UID:0000MZ] RankingDialog as source root

- Evidence for: embedded collection offset, direct parser/accessor state, packet handler dispatch, source-tree ranking module, selected category id field, record vector semantics, and UI consumers all converge on collection ownership.
- Evidence against: original symbol names are unavailable; [UID:0000BK] currently needs the support refresh text applied before stats reflect `86/90`.
- Decision: accepted now. Route [UID:0001ZC] and source-authored collection children through [UID:0000BK].

### 2. [UID:0000BL] RankingCategoryRecord for record/user-entry helper children

- Evidence for: user-entry vector helpers operate on record `+0x258` vector state; deep-copy helper copies `RankingCategoryRecord`; row layout belongs to record support.
- Evidence against: [UID:0000BL] does not own collection selected id or category parser dispatch.
- Decision: accepted for user-entry and record-copy helper children, not for the [UID:0001ZC] aggregate.

### 3. [UID:0000MZ] RankingDialog as direct owner

- Evidence for: valid source-file root and current direct owner; it already clears `85/85`.
- Evidence against: `CANONICAL_OWNER` must be narrowest semantic owner, and [UID:0000BK] can now clear the gate.
- Decision: rejected as direct owner; retained as file root and downstream emitter.

### 4. New source file or network/protocol owner

- Evidence for: packet parsers use packet helpers.
- Evidence against: all callers and data consumers are ranking UI local; proposed source tree and file doc already place ranking data containers under `RankingDialog.cpp`; no generic network object owns these fields.
- Decision: rejected.

## Negative Evidence Summary

- Consumer xrefs alone are not ownership proof, but here they align with constructor embedding, packet dispatch, selected-category state, and source-tree context.
- Address adjacency to reward-info helpers does not make [UID:0001ZC] a reward-info owner. Reward-info starts after separate helper/padding boundaries.
- Compiler helper locality does not make helper bodies handwritten gameplay code. Their semantics belong to source container declarations.
- Lack of original names does not block `85/85` because packet field meanings and method roles are defensible from data flow; it does block near-final `95+` and broad parser C++.

## Exact Coverage / Ignored Row Recommendations

The rows below are the exact execution target after pages are created. Because this remains report-only, UIDs for new pages cannot be minted here without editing `by-memory`. The marker `UID:ASSIGN_*` is not a TMP roadmap placeholder; it means "create this page immediately, run validator/page registration, and replace the marker with the validator-assigned UID before applying the coverage row." Do not apply the coverage text with the assignment markers still present.

```text
    - [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) 0x0045c260-0x0045d4f8 | class-aggregate | RankingCategoryCollection : reconstructable : 86% : very strong : Reconstructable aggregate/index for exact RankingCategoryCollection parser/accessor children and source-declared/generated-binary record/user-entry vector helpers; direct owner [UID:0000BK], file route [UID:0000MZ], aggregate final C++ blank.
        - [UID:ASSIGN_RCC_CTOR][0x0045c260-0x0045c281.RankingCategoryCollectionConstructor](by-memory/0x0045c260-0x0045c281.RankingCategoryCollectionConstructor.md) 0x0045c260-0x0045c281 | method | RankingCategoryCollectionConstructor : reconstructable : 88% : very strong : Constructor initializes begin/end/capacity only; selectedCategoryId is not initialized here.
        - [UID:ASSIGN_RCC_DTOR_THUNK][0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk](by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md) 0x0045c290-0x0045c295 | method | RankingCategoryCollectionDestructorThunk : reconstructable : 86% : strong : Destructor entry tail-jumps to category-record vector teardown support; do not hand-port the thunk as standalone helper source.
        - [UID:ASSIGN_RCC_PARSE_LIST][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) 0x0045c2a0-0x0045c556 | method | RankingCategoryCollectionParseCategoryListResponse : reconstructable : 87% : very strong : Opcode 0x7d subcommand 1 category-list response parser; clears records, decodes category metadata/title text, and appends 0x2b0 records.
        - [UID:ASSIGN_RCC_PARSE_INITIAL_PAGE][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) 0x0045c560-0x0045cb0a | method | RankingCategoryCollectionParseInitialCategoryPageResponse : reconstructable : 87% : very strong : Opcode 0x7d subcommand 3 combined category-list, selected-category, local-player metadata, row, and total-count parser.
        - [UID:ASSIGN_RCC_PARSE_ROWS][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) 0x0045cb10-0x0045cdb4 | method | RankingCategoryCollectionParseRankingRowsResponse : reconstructable : 87% : very strong : Opcode 0x7d subcommand 2 selected-category row parser with local-player footer metadata and total-rank count.
        - [UID:ASSIGN_RCC_REWARD_STATUS][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) 0x0045cdc0-0x0045ce2b | method | RankingCategoryCollectionApplyRewardClaimStatusResponse : reconstructable : 86% : strong : Opcode 0x7d subcommand 6 id/status response; marks matching category state after reward-claim success/status flag.
        - [UID:ASSIGN_RCC_SET_SELECTED_ID][0x0045ce30-0x0045ce3d.RankingCategoryCollectionSetSelectedCategoryId](by-memory/0x0045ce30-0x0045ce3d.RankingCategoryCollectionSetSelectedCategoryId.md) 0x0045ce30-0x0045ce3d | method | RankingCategoryCollectionSetSelectedCategoryId : reconstructable : 89% : very strong : Writes selected category id at collection offset +0x0c.
        - [UID:ASSIGN_RCC_GET_COUNT][0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount](by-memory/0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount.md) 0x0045ce40-0x0045ce57 | method | RankingCategoryCollectionGetCount : reconstructable : 89% : very strong : Returns category count from begin/end and 0x2b0 record stride.
        - [UID:ASSIGN_RCC_GET_SELECTED_ID][0x0045ce60-0x0045ce64.RankingCategoryCollectionGetSelectedCategoryId](by-memory/0x0045ce60-0x0045ce64.RankingCategoryCollectionGetSelectedCategoryId.md) 0x0045ce60-0x0045ce64 | method | RankingCategoryCollectionGetSelectedCategoryId : reconstructable : 89% : very strong : Returns selected category id at collection offset +0x0c.
        - [UID:ASSIGN_RCC_GET_SELECTED_RECORD][0x0045ce70-0x0045ceab.RankingCategoryCollectionGetSelectedRecord](by-memory/0x0045ce70-0x0045ceab.RankingCategoryCollectionGetSelectedRecord.md) 0x0045ce70-0x0045ceab | method | RankingCategoryCollectionGetSelectedRecord : reconstructable : 88% : very strong : Finds the category record whose id matches selected category id.
        - [UID:ASSIGN_RCC_GET_BY_INDEX][0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex](by-memory/0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex.md) 0x0045cf00-0x0045cf44 | method | RankingCategoryCollectionGetByIndex : reconstructable : 88% : very strong : Signed-index bounds check and 0x2b0-stride category record lookup.
        - [UID:ASSIGN_RCR_VECTOR_INSERT][0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth](by-memory/0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth.md) 0x0045cf50-0x0045d1ad | helper | RankingCategoryRecordVectorInsertWithGrowth : reconstructable : 86% : very strong : Source-declared/generated-binary category-record vector insert/growth helper with deep-copy and MSVC allocation/free support; final C++ blank.
        - [UID:ASSIGN_RUE_VECTOR_INSERT][0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth](by-memory/0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md) 0x0045d1b0-0x0045d317 | helper | RankingUserEntryVectorInsertWithGrowth : reconstructable : 86% : very strong : Source-declared/generated-binary 0x4c user-entry vector insert/growth helper; final C++ blank.
        - [UID:ASSIGN_RUE_COPY_RANGE][0x0045d320-0x0045d36c.RankingUserEntryCopyRange](by-memory/0x0045d320-0x0045d36c.RankingUserEntryCopyRange.md) 0x0045d320-0x0045d36c | helper | RankingUserEntryCopyRange : reconstructable : 86% : very strong : Copies contiguous 0x4c RankingUserEntry rows; final C++ blank.
        - [UID:ASSIGN_RUE_VECTOR_CLONE][0x0045d370-0x0045d419.RankingUserEntryVectorClone](by-memory/0x0045d370-0x0045d419.RankingUserEntryVectorClone.md) 0x0045d370-0x0045d419 | helper | RankingUserEntryVectorClone : reconstructable : 86% : very strong : Initializes and deep-copies a RankingUserEntry vector; final C++ blank.
        - [UID:ASSIGN_RCR_COPY_DEEP][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) 0x0045d420-0x0045d4f8 | helper | RankingCategoryRecordCopyConstructDeep : reconstructable : 86% : very strong : Deep-copies a RankingCategoryRecord, including embedded RankingUserEntry vector; final C++ blank.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d4f8-0x0045d500 | padding | RankingCategoryCollection cleanup alignment : ignored : 100% : strong : Confirmed 0xcc padding between RankingCategoryRecordCopyConstructDeep and the EH cleanup funclet.
    - [UID:ASSIGN_RCR_CLEANUP_FUNCLET][0x0045d500-0x0045d528.RankingCategoryRecordRangeUserEntryCleanupFunclet](by-memory/0x0045d500-0x0045d528.RankingCategoryRecordRangeUserEntryCleanupFunclet.md) 0x0045d500-0x0045d528 | compiler-helper | RankingCategoryRecordRangeUserEntryCleanupFunclet : ignored : 90% : very strong : Compiler-emitted EH cleanup funclet for record-range user-entry vectors; xrefs are EH jumps at 0x005fa303 and 0x005fa333, not ordinary source calls.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045d528-0x0045d530 | padding | RankingCategoryCollection cleanup alignment : ignored : 100% : strong : Confirmed 0xcc padding between the EH cleanup funclet and [UID:0001ZD].
```

Add this exact ignored-ledger text, either as a new block or merged into the existing RankingDialog alignment/compiler-helper block:

```text
- `0x0045d4f8-0x0045d500` and `0x0045d528-0x0045d530` - RankingCategoryCollection cleanup alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes around the `0x0045d500-0x0045d528` category-record cleanup funclet; no source-level code or data is present.
  - Evidence: 2026-06-16 B002 IDA MCP `get_bytes 0x0045d4f8 size 0x38` shows eight `0xcc` bytes before `0x0045d500`, the cleanup body at `0x0045d500-0x0045d528`, and eight `0xcc` bytes before `0x0045d530`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000MZ], [UID:0000BK], [UID:0001ZC], [UID:0001ZD].

- `0x0045d500-0x0045d528` - `RankingCategoryRecordRangeUserEntryCleanupFunclet`.
  - Why ignored: compiler-emitted C++ EH cleanup funclet/tail chunk for category-record vector insert/range-copy cleanup; not a handwritten ranking method.
  - Evidence: 2026-06-16 B002 IDA MCP disassembly at `0x0045d500` loops from `[ecx]` to `[ecx+4]`, calls `0x0045d5f0` on each record's `+0x258` user-entry vector, advances by `0x2b0`, and returns. `xrefs_to 0x0045d500` reports only EH jumps at `0x005fa303` and `0x005fa333`.
  - Replacement/procurement: express the source-level category-record/user-entry vector ownership and let the compiler regenerate equivalent cleanup glue.
  - Owner docs: [UID:0000MZ], [UID:0000BK], [UID:0000BL], [UID:0001ZC], [UID:0001ZD].
```

## Final Recommendation

- Exact changes recommended:
  - Update [UID:0001ZC] metadata to `86/90`, `CANONICAL_OWNER:0000BK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BK`, aggregate final C++ blank.
  - Apply the exact [UID:0000BK], [UID:0000BL], and [UID:0001VN] support-page metadata/body refresh text above.
  - Create every exact source-authored and source-declared/generated-binary child page listed in `Function / Child Inventory`.
  - Create/document the `0x0045d500-0x0045d528` ignored compiler cleanup funclet and ignored padding rows.
  - Replace raw `sub_45C2A0`, `sub_45C560`, `sub_45CB10`, and `sub_45CDC0` snippets in [UID:0001ZC] and parent aggregate docs with descriptive names or historical-label notes.
- Exact parent assignments recommended:
  - [UID:0001ZC] aggregate and source-authored collection children: `CANONICAL_OWNER:0000BK`, `EMITTER_UIDS:0000BK`.
  - Category-record vector insert helper `0x0045cf50-0x0045d1ad`: `CANONICAL_OWNER:0000BK`, `EMITTER_UIDS:0000BK`, final C++ blank.
  - User-entry and record-copy helper children `0x0045d1b0-0x0045d4f8`: `CANONICAL_OWNER:0000BL`, `EMITTER_UIDS:0000BL`, final C++ blank.
  - EH cleanup funclet and padding: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, empty `EMITTER_UIDS`, final C++ blank.
- Exact items left non-emitting and why:
  - [UID:0001ZC] aggregate final C++ stays blank to avoid duplicate broad code; exact children carry future code.
  - Compiler/container helper children stay blank because source declarations should regenerate them.
  - EH cleanup and padding stay ignored/non-emitting.
- This revised report supports execution now. It is not a no-change report and not a defended no-85 result.

## Follow-Up Actions

- Supervisor/executing agent actions:
  - Lease and edit [UID:0001ZC], [UID:0000BK], [UID:0000BL], [UID:0001VN], `by-memory/-ignored.md`, and `by-memory/-coverage-report.md` as needed.
  - Create all immediate child pages listed above and let validator assign real UIDs.
  - Replace every `UID:ASSIGN_*` marker in the coverage text with the actual assigned UID before committing coverage changes.
  - Run validators listed below.
- A-agent actions after execution:
  - Use the child pages to write final C++ only for exact source-authored methods whose support types are ready.
  - Keep compiler helper and EH cleanup final C++ blank.
  - Consider creating a dedicated `RankingUserEntryLayout` page later if row layout needs independent reuse; it is not required to execute [UID:0001ZC].

Suggested validator/inspection commands after edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001ZC-ranking-category-collection-source-quality-removed.md](0001ZC-ranking-category-collection-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

For the new child pages, run one file-mode validator command per created page after the files exist.

## Confidence

- Recommendation confidence: `90/100`. The revised route and scores are supported by current docs plus B002 read-only IDA facts for dispatch, ranges, record/user-entry strides, parser metadata, UI consumers, and cleanup/padding boundaries.
- Score confidence: [UID:0001ZC] `86/90`, [UID:0000BK] `86/90`, [UID:0000BL] `86/90`, and [UID:0001VN] `87/91` are justified after applying the exact body text above. These are not near-final `95+` scores.
- Remaining uncertainty: original source names, date/time type declaration spelling, exact source container spelling, and score/value field spelling. These limit final C++ and final-audit scores, not execution of split/owner/emitter repair.

## Validator Results

- No by-* validator was run because this is a report-only revision and no scanned by-* files were edited.
- Verification performed in this revision:
  - Re-read `goal.md`, `notes.md`, current [UID:0001ZC], [UID:0000BK], [UID:0000BL], [UID:0001VN], [UID:0000MZ], [UID:0000XZ], [UID:0000BQ], `by-memory/-guidance.md`, `by-memory/-coverage-report.md`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`, `project-level/-resolved-multple-aliases.md`, and proposed source-tree Ranking sections.
  - Confirmed no proposed exact child pages currently exist under `by-memory`.
- Underlying read-only IDA MCP commands from the original B002 investigation:
  - `idb_open`, `server_health`, `lookup_funcs`, `analyze_component`, `decompile`, `xrefs_to`, `disasm 0x0045d500`, and `get_bytes`.
- `int_convert.py` was previously run for `0x7d`, `0x2b0`, `0x4c`, `0x258`, and `0x26c`.

## Changed Files

- Modified: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0001ZC-ranking-category-collection-source-quality.md`
- Created: none.
- Modified outside this report: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001ZC-ranking-category-collection-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001ZC"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001ZC-ranking-category-collection-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001ZC-ranking-category-collection-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001ZC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
