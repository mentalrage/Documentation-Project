** TARGET-REPORT-UID:0002K7 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002K7]/[UID:0002K8] RankingCategoryRecord Packed Date-Time Setter Source-Quality Report

Agent: Agent-B005  
Date: 2026-06-19  
Targets:

- [UID:0002K7] `by-memory/0x0045c050-0x0045c0f8.RankingCategoryRecordSetStartTimeFromPackedDateTime.md`
- [UID:0002K8] `by-memory/0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`

Required report path: `tools/leaser/Agents/Agent-B005/research/0002K7-0002K8-RankingCategoryRecordPackedDateTimeSetters-source-quality.md`  
Assignment type: report-only B-preferred source-quality / heuristic-inference pass

## Final Recommendation

Both targets are source-authored `RankingCategoryRecord` methods and should now emit first-draft C++ through [UID:0000BL] `RankingCategoryRecord` into [UID:0000MZ] `RankingDialog.cpp`.

Recommended final state after supervisor incorporation:

| UID | Current | Recommended | Owner / emitter | Formal C++ |
| --- | ---: | ---: | --- | --- |
| [UID:0002K7] `SetStartTimeFromPackedDateTime` | `84/90` | `88/91` | [UID:0000BL] / [UID:0000BL] | Populate |
| [UID:0002K8] `SetEndTimeFromPackedDateTime` | `84/90` | `88/91` | [UID:0000BL] / [UID:0000BL] | Populate |

Important range correction: the current target filenames and coverage rows exclude the final `00` byte of the `ret 8` instruction. IDA function-size evidence already says each body is `0xa9` bytes / 169 decimal (Verified with `int_convert.py`). The correct half-open ranges are:

- [UID:0002K7]: `0x0045c050-0x0045c0f9`, not `0x0045c050-0x0045c0f8`.
- [UID:0002K8]: `0x0045c100-0x0045c1a9`, not `0x0045c100-0x0045c1a8`.

The old source-quality blockers are now stale. [UID:0000BL] already emits a first-draft `RankingDateTimeParts` declaration and has `SetStartTimeFromPackedDateTime(int packedDate, int packedTime)` / `SetEndTimeFromPackedDateTime(int packedDate, int packedTime)` in the class surface. [UID:0002K3]/[UID:0002K4] and `RankingUserListPane::OnPaint` validate the field order. The parser callers validate the parameter direction. Exact original spelling is still inferred, but there is no target-specific reason to keep these two method C++ blocks blank.

## Evidence Reviewed

- Mandate and process docs:
  - `tools/leaser/Agents/Agent-B005/goal.md`
  - `tools/leaser/Agents/Agent-B005/notes.md`
  - `tools/leaser/Agents/Supervisor.md`
  - `by-structure.md`
  - `inference_research.md`
- Target pages:
  - [UID:0002K7] `0x0045c050-0x0045c0f8.RankingCategoryRecordSetStartTimeFromPackedDateTime`
  - [UID:0002K8] `0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime`
- Direct support pages:
  - [UID:0000BL] `RankingCategoryRecord`
  - [UID:0001VN] `RankingCategoryRecordLayout`
  - [UID:0000Y9] `0x0045bf60-0x0045c257.RankingCategoryRecord`
  - [UID:0000BK] `RankingCategoryCollection`
  - [UID:0001ZC] `0x0045c260-0x0045d4f8.RankingCategoryCollection`
  - [UID:0003WR] `RankingCategoryCollectionParseCategoryListResponse`
  - [UID:0003WS] `RankingCategoryCollectionParseInitialCategoryPageResponse`
  - [UID:0003WT] `RankingCategoryCollectionParseRankingRowsResponse`
  - [UID:0002K3] `RankingCategoryRecordCopyStartTimeParts`
  - [UID:0002K4] `RankingCategoryRecordCopyEndTimeParts`
  - [UID:0002K9] `RankingCategoryRecordAppendUserEntry`
  - [UID:0000BQ] `RankingUserListPane`
  - [UID:0000MZ] `RankingDialog`
- Executed B-agent reports used as leads and revalidated against current docs/raw bytes:
  - `Agent-B002/research/executed/0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md`
  - `Agent-B002/research/executed/older/0001ZC-ranking-category-collection-source-quality.md`
  - `Agent-B005/research/executed/0000BQ-RankingUserListPane-class-source-quality.md`
- Generated/report context:
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`
  - `by-memory/-coverage-report.md`
  - `project-level/-unresolved.md`
  - `project-level/-resolved.md`
- Raw binary evidence:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

IDA MCP was probed at `http://127.0.0.1:13337/mcp` and was unavailable (`Unable to connect to the remote server`). Current findings therefore combine raw PE bytes, current by-* docs, generated coverage/source output, and previously incorporated live IDA evidence recorded in accepted support docs.

## Exact Boundary / Bytes / Padding

The current pages record IDA `lookup_funcs` size `0xa9`, but their filenames/rows use half-open endpoints that are one byte too short. Raw PE bytes confirm that each current range excludes the last immediate byte of `c2 08 00`.

Corrected [UID:0002K7] body:

```text
K7-corrected-body VA 0x0045c050-0x0045c0f9 raw 0x5b450 len 0xa9 section .text
SHA1 6f8ad81d88a47803ddb555472dcad2896cfa0ce5
55 8b ec 56 8b 75 08 b8 ad 8b db 68 f7 ee 57 8b f9 c1 fa 0c 8b c2 8b ce c1 e8 1f 03 c2 89 47 20 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 c1 fa 05 8b c2 c1 e8 1f 03 c2 89 47 1c b8 1f 85 eb 51 f7 ee b8 ad 8b db 68 c1 fa 05 8b ca c1 e9 1f 03 ca 6b c9 64 2b f1 89 77 18 8b 75 0c 8b ce f7 ee c1 fa 0c 8b c2 c1 e8 1f 03 c2 89 47 14 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 b8 1f 85 eb 51 c1 fa 05 8b ca c1 e9 1f 03 ca f7 ee 89 4f 10 c1 fa 05 8b c2 c1 e8 1f 03 c2 6b c0 64 2b f0 89 77 0c 5f 5e 5d c2 08 00
```

Corrected [UID:0002K7] postpad:

```text
K7-postpad VA 0x0045c0f9-0x0045c100 raw 0x5b4f9 len 0x7 section .text
SHA1 a9ab6e995b9c28065121177aee0dc78e1926528b
cc cc cc cc cc cc cc
```

Corrected [UID:0002K8] body:

```text
K8-corrected-body VA 0x0045c100-0x0045c1a9 raw 0x5b500 len 0xa9 section .text
SHA1 5db36d68b861e1df28309949538868a3f61c2d40
55 8b ec 56 8b 75 08 b8 ad 8b db 68 f7 ee 57 8b f9 c1 fa 0c 8b c2 8b ce c1 e8 1f 03 c2 89 47 44 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 c1 fa 05 8b c2 c1 e8 1f 03 c2 89 47 40 b8 1f 85 eb 51 f7 ee b8 ad 8b db 68 c1 fa 05 8b ca c1 e9 1f 03 ca 6b c9 64 2b f1 89 77 3c 8b 75 0c 8b ce f7 ee c1 fa 0c 8b c2 c1 e8 1f 03 c2 89 47 38 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 b8 1f 85 eb 51 c1 fa 05 8b ca c1 e9 1f 03 ca f7 ee 89 4f 34 c1 fa 05 8b c2 c1 e8 1f 03 c2 6b c0 64 2b f0 89 77 30 5f 5e 5d c2 08 00
```

Corrected [UID:0002K8] postpad before the next raw source-shaped setter:

```text
K8-postpad-before-SetTitle VA 0x0045c1a9-0x0045c1b0 raw 0x5b5a9 len 0x7 section .text
SHA1 a9ab6e995b9c28065121177aee0dc78e1926528b
cc cc cc cc cc cc cc
```

Boundary implications:

- [UID:0002K7] should be renamed or at least internally corrected to `0x0045c050-0x0045c0f9`.
- [UID:0002K8] should be renamed or at least internally corrected to `0x0045c100-0x0045c1a9`.
- The seven bytes after each corrected body are padding, not part of either method.
- The bytes after [UID:0002K8] are not all padding until [UID:0002K9]. Raw source-shaped helpers exist at `0x0045c1b0-0x0045c1cb` and `0x0045c1d0-0x0045c1e0`. They are adjacent support gaps, not part of [UID:0002K8].

## Function Semantics

Both methods are `__thiscall` member functions with two stack arguments and `ret 8`. They have no callees and no allocation or exception handling.

[UID:0002K7] writes the start block at `m_startTime` / record offset `+0x0c`:

| Field | Offset | Value |
| --- | --- | --- |
| `m_startTime.second` | `+0x0c` | `packedTime % 100` |
| `m_startTime.minute` | `+0x10` | `(packedTime % 10000) / 100` |
| `m_startTime.hour` | `+0x14` | `packedTime / 10000` |
| `m_startTime.day` | `+0x18` | `packedDate % 100` |
| `m_startTime.month` | `+0x1c` | `(packedDate % 10000) / 100` |
| `m_startTime.year` | `+0x20` | `packedDate / 10000` |

[UID:0002K8] writes the end block at `m_endTime` / record offset `+0x30`:

| Field | Offset | Value |
| --- | --- | --- |
| `m_endTime.second` | `+0x30` | `packedTime % 100` |
| `m_endTime.minute` | `+0x34` | `(packedTime % 10000) / 100` |
| `m_endTime.hour` | `+0x38` | `packedTime / 10000` |
| `m_endTime.day` | `+0x3c` | `packedDate % 100` |
| `m_endTime.month` | `+0x40` | `(packedDate % 10000) / 100` |
| `m_endTime.year` | `+0x44` | `packedDate / 10000` |

The first argument is `packedDate`, with expected decimal shape `YYYYMMDD`. The second argument is `packedTime`, with expected decimal shape `HHMMSS`. The setters do not clamp or validate ranges. They also do not touch `reserved0`, `reserved1`, or `reserved2`; those fields are preserved only by the 36-byte copy helpers. `0x24` is 36 decimal (Verified with `int_convert.py`) and is the size of `RankingDateTimeParts`.

The compiler implements division by decimal `10000` and `100` with signed magic-constant multiply/shift sequences. The source-facing code should use ordinary integer division and modulo because packet values are nonnegative packed decimal values.

## Caller / Parser / Formatter Correlation

Current docs and accepted B002/C001 evidence identify the two direct callers for each setter:

| Method | Caller site | Source context |
| --- | --- | --- |
| [UID:0002K7] start setter | `0x0045c49c` | [UID:0003WR] `RankingCategoryCollection::ParseCategoryListResponse`, opcode `0x7d` subcommand `1` |
| [UID:0002K7] start setter | `0x0045c770` | [UID:0003WS] `RankingCategoryCollection::ParseInitialCategoryPageResponse`, opcode `0x7d` subcommand `3` |
| [UID:0002K8] end setter | `0x0045c4b3` | [UID:0003WR] `RankingCategoryCollection::ParseCategoryListResponse`, opcode `0x7d` subcommand `1` |
| [UID:0002K8] end setter | `0x0045c787` | [UID:0003WS] `RankingCategoryCollection::ParseInitialCategoryPageResponse`, opcode `0x7d` subcommand `3` |

Parser correlation:

- Subcommand `1` parses category-list records, including category id, start packed date/time, end packed date/time, state, title length, and title text.
- Subcommand `3` parses the initial category page and repeats the category-list record shape before selected-category/user-row metadata.
- Both callers use the same start-then-end setter sequence, which supports the two methods as record field setters rather than parser-local helpers.

Formatter correlation:

- [UID:0002K3] `CopyStartTimeParts` copies 36 bytes from `m_startTime` at `+0x0c`.
- [UID:0002K4] `CopyEndTimeParts` copies 36 bytes from `m_endTime` at `+0x30`.
- [UID:0000BQ] `RankingUserListPane::OnPaint` uses those copies with `From : %02d/%02d/%04d %02d:%02d:%02d` and `To : %02d/%02d/%04d %02d:%02d:%02d`.
- That paint path displays fields in month/day/year/hour/minute/second order, validating the internal storage order `second, minute, hour, day, month, year`.

This resolves the parameter-direction problem. `packedDate, packedTime` is stronger than generic `a2, a3`, `time, date`, or `packedStart, packedEnd`.

## Ownership / Source Placement Ranking

### 1. [UID:0000BL] RankingCategoryRecord

Decision: accepted direct owner and emitter for both targets.

Evidence:

- Both functions are `__thiscall` methods and mutate fields in one `RankingCategoryRecord` receiver.
- Field offsets match [UID:0001VN] and [UID:0000BL].
- [UID:0000BL] already declares both method prototypes and has a `[[CHILDREN]]` insertion point after the class declaration.
- Current generated output routes both targets through [UID:0000BL] to `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`.

### 2. [UID:0000MZ] RankingDialog

Decision: accepted file root, rejected as direct semantic owner.

Evidence:

- `RankingDialog.cpp` is the likely original feature module containing ranking private classes.
- By-structure rules prefer the narrow semantic owner; the methods belong to the record class, not the whole source file.

### 3. [UID:0000BK] RankingCategoryCollection

Decision: caller/parser owner only, rejected as direct owner.

Evidence:

- The collection parsers call the setters while building records.
- The receiver and fields are record-owned. Collection ownership would conflate packet parsing with record mutation helpers.

### 4. Date/time helper file or generic utility

Decision: rejected.

Evidence:

- There is no shared callee and no standalone date/time object. The packed split logic is duplicated directly in two record methods.
- `RankingDateTimeParts` is a record layout member, not a generic date/time abstraction.
- The layout is not `SYSTEMTIME` or `tm`; it uses `second, minute, hour, day, month, year` plus three reserved dwords.

### 5. RankingUserListPane

Decision: consumer only, rejected as owner.

Evidence:

- `RankingUserListPane::OnPaint` formats the copied parts but does not initialize them.
- Its evidence validates the layout, not ownership.

### 6. No-owner/non-emitting

Decision: rejected.

Evidence:

- Both targets are live, reconstructable, source-authored methods with valid owner/emitter route and source-ready type/member names.

## First-Draft C++ Recommendation

Populate [UID:0002K7]:

```cpp
void RankingCategoryRecord::SetStartTimeFromPackedDateTime(int packedDate, int packedTime)
{
    m_startTime.year = packedDate / 10000;
    m_startTime.month = (packedDate % 10000) / 100;
    m_startTime.day = packedDate % 100;

    m_startTime.hour = packedTime / 10000;
    m_startTime.minute = (packedTime % 10000) / 100;
    m_startTime.second = packedTime % 100;
}
```

Populate [UID:0002K8]:

```cpp
void RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime)
{
    m_endTime.year = packedDate / 10000;
    m_endTime.month = (packedDate % 10000) / 100;
    m_endTime.day = packedDate % 100;

    m_endTime.hour = packedTime / 10000;
    m_endTime.minute = (packedTime % 10000) / 100;
    m_endTime.second = packedTime % 100;
}
```

This C++ intentionally leaves `reserved0`, `reserved1`, and `reserved2` untouched, matching the binary. It also uses the existing accepted class declaration and avoids raw offset casts or compiler-generated names.

No no-code proof applies. These are not thunks, not compiler-generated helpers, not aggregate-only ranges, and not data-only records. The only issues were stale source-quality blockers and the half-open endpoint correction.

## Heuristic / Inference Reanalysis And Validation

### Method names

Evidence checked:

- Current target docs, [UID:0000BL] declaration, parser callsites, accepted C001 IDA names, and generated output.

Rejected alternatives:

- `SetStartDateTime` / `SetEndDateTime`: shorter and plausible, but less explicit about the packed input format.
- `ParseStartTime` / `ParseEndTime`: rejected because packet parsing happens in [UID:0000BK]; these are record setters.
- `DecodePackedDateTime`: rejected as a generic helper name; the receiver and field writes make this class-specific.

Best inference:

- Keep `SetStartTimeFromPackedDateTime` and `SetEndTimeFromPackedDateTime`. The names are descriptive/inferred, not original-symbol proof.

Impact:

- No rename needed beyond half-open address filename correction. Supports C++ readiness and [UID:0000BL] owner/emitter route.

### Packed parameter direction

Evidence checked:

- Setter write expressions.
- Parser caller pairing.
- [UID:0002K3]/[UID:0002K4] copy helpers.
- `RankingUserListPane::OnPaint` formatter use.

Rejected alternatives:

- `packedTime, packedDate`: rejected because first stack argument is split into day/month/year fields, and second stack argument into second/minute/hour.
- Single packed timestamp: rejected because there are two separate 32-bit parameters and two independent decimal split sequences.
- Start/end pair as parameters: rejected because start/end distinction is the method target, not the two parameters.

Best inference:

- `int packedDate, int packedTime`.

Impact:

- Removes the current target pages' parameter-name blocker.
- Keeps score below final because exact original spelling remains unproven, but no longer blocks formal C++.

### `RankingDateTimeParts` type and fields

Evidence checked:

- [UID:0001VN] layout table.
- [UID:0000BL] accepted class declaration.
- Copy helpers preserve `0x24` / 36 decimal bytes (Verified with `int_convert.py`).
- Paint formatter consumes month/day/year and hour/minute/second from the copied block.

Rejected alternatives:

- `SYSTEMTIME`: rejected because field order does not match and the block has three extra copied dwords.
- C `tm`: rejected because field order and year/month semantics do not match a standard `tm`.
- A 6-dword struct only: rejected because the copy helpers copy nine dwords / `0x24` bytes.

Best inference:

- `RankingDateTimeParts { second, minute, hour, day, month, year, reserved0, reserved1, reserved2 }`.

Impact:

- Supports both setter C++ bodies.
- The reserved fields should remain documented because setters do not initialize them.

### Start-versus-end invariants

Evidence checked:

- Raw bytes and documented offsets show the same logic with `+0x24` offset displacement between start and end blocks.
- [UID:0002K7] writes `+0x0c` through `+0x20`.
- [UID:0002K8] writes `+0x30` through `+0x44`.

Rejected alternatives:

- Treating the blocks as different layouts: rejected because offset pattern and formatter usage are identical.
- Treating `endTime` as duration: rejected because parser and formatter label it as a second date/time endpoint.

Best inference:

- `m_startTime` and `m_endTime` are parallel `RankingDateTimeParts` endpoint fields.

Impact:

- Supports symmetric C++ and score raise for both targets.

### Range/split correction

Evidence checked:

- Raw PE byte audit for `0x0045c050-0x0045c0f9` and `0x0045c100-0x0045c1a9`.
- Existing target pages record `lookup_funcs` size `0xa9`, which agrees with corrected endpoints and contradicts the current filenames.
- Padding after each corrected body is exactly seven `0xcc` bytes.

Rejected alternatives:

- Leaving current half-open ranges unchanged: rejected because it splits `c2 08 00` and leaves the final `00` byte outside the function.
- Expanding either target into adjacent helpers: rejected because padding separates the bodies and the next source-shaped helper begins at `0x0045c1b0`.

Best inference:

- Rename/update [UID:0002K7] to `0x0045c050-0x0045c0f9`.
- Rename/update [UID:0002K8] to `0x0045c100-0x0045c1a9`.

Impact:

- Required for correct boundary documentation.
- Does not block C++ once supervisor applies the rename/update.

### Adjacent unmodeled record setters

Evidence checked:

- Raw PE bytes between [UID:0002K8] and [UID:0002K9] show:
  - `0x0045c1b0-0x0045c1cb`: `wcscpy_s(this + 0x54, 0x100, input)` shape, best descriptive name `RankingCategoryRecordSetTitleText`.
  - `0x0045c1d0-0x0045c1e0`: stores input dword to `this + 0x254`, best descriptive name `RankingCategoryRecordSetTotalRankCount`.
- Raw PE bytes between [UID:0002K6] and [UID:0002K7] also show short source-shaped setters at `0x0045c020`, `0x0045c030`, and `0x0045c040`, likely `SetListIndex`, `SetCategoryId`, and `SetStateCode`.
- Scanner/generated address lists currently only recognize IDA functions at `0x0045c050`, `0x0045c100`, and `0x0045c1e0` in this immediate subrange.

Rejected alternatives:

- Calling the bytes padding: rejected for the `0x0045c1b0` and `0x0045c1d0` bodies because they are valid prologue/body/return source-shaped functions.
- Folding them into [UID:0002K8] or [UID:0002K9]: rejected by `0xcc` padding and independent prologues.

Best inference:

- These are support gaps in the broader `RankingCategoryRecord` aggregate, not part of the two assigned setter targets.
- Recommend a follow-up supervisor/support audit for exact child pages or ignored/no-xref classification. Do not block [UID:0002K7]/[UID:0002K8] C++ on those adjacent gaps.

Impact:

- The aggregate [UID:0000Y9] "eleven methods" language is now incomplete if the project wants every source-shaped child under the record container.
- [UID:0002K7]/[UID:0002K8] scores can still rise because their own range, behavior, callers, and source route are resolved.

### Owner/source placement

Evidence checked:

- [UID:0000BL] class declaration and emitter route.
- [UID:0000MZ] file root.
- Parser callers in [UID:0000BK] children.
- Formatter consumer [UID:0000BQ].

Rejected alternatives:

- File-owned direct route: too broad under current by-structure rules.
- Collection-owned direct route: caller ownership only.
- New date-time helper file: no evidence of a shared source helper.

Best inference:

- Direct owner/emitter [UID:0000BL], source-file root [UID:0000MZ].

Impact:

- Supports formal C++ population and generated output in `RankingDialog.cpp`.

### Final C++ blockers

Evidence checked:

- Current generated output shows [UID:0002K7]/[UID:0002K8] as empty emitter markers while sibling record methods already emit source.
- [UID:0000BL] declaration has the required methods and fields.
- The arithmetic and field order are fully represented by source-level C++.

Rejected alternatives:

- Keep C++ blank until exact original names are proven: rejected under active B-agent rules; descriptive names are now evidence-backed.
- Emit decompiler-shaped magic-constant arithmetic: rejected because source should express packed decimal division/modulo.

Best inference:

- Populate first-draft C++ for both methods.

Impact:

- Resolves the primary source-quality blocker and should move both targets out of the low-score reconstructable queue.

## Score / Metadata Recommendations

For both targets after half-open range correction:

```text
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000BL
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BL
```

Rationale:

- Exact corrected body bytes, padding, and SHA1 are now documented.
- Function behavior, calling convention, no-callee state, and caller set are understood.
- Parameter semantics are resolved as `packedDate, packedTime`.
- `RankingDateTimeParts` and record field names are accepted in current support docs.
- Owner/emitter route is valid and already produces `RankingDialog.cpp`.
- First-draft source is simple and source-shaped.
- Confidence remains below final audit because original symbol spellings are inferred and live IDA MCP was unavailable during this B005 run.

## Support-Doc Update Plan

Recommended target page changes:

- Rename paths/titles:
  - `by-memory/0x0045c050-0x0045c0f8.RankingCategoryRecordSetStartTimeFromPackedDateTime.md` -> `by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md`
  - `by-memory/0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md` -> `by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`
- Update each page to state exact `0xa9` / 169 decimal bytes (Verified with `int_convert.py`), `__thiscall`, no callees, `ret 8`, seven-byte `0xcc` postpad, and the raw SHA1 from this report.
- Replace the current "do not emit final C++ until parser fields and declaration policy are audited" wording with "source-ready; parser fields and declaration policy are now resolved by [UID:0000BL], [UID:0001VN], [UID:0002K3], [UID:0002K4], [UID:0003WR], and [UID:0003WS]."
- Populate first-draft C++ from this report.

Recommended [UID:0000BL] `RankingCategoryRecord` changes:

- Update method inventory links/ranges for [UID:0002K7]/[UID:0002K8] to the corrected half-open endpoints.
- Add a note that the packed setters initialize only the first six `RankingDateTimeParts` fields and intentionally leave the reserved dwords untouched.
- Optionally add a follow-up note for raw adjacent setters at `0x0045c1b0` and `0x0045c1d0`.

Recommended [UID:0001VN] `RankingCategoryRecordLayout` changes:

- Keep the current `RankingDateTimeParts` struct.
- Add the corrected half-open ranges and raw byte audit evidence.
- Clarify that `reserved0/reserved1/reserved2` are copied by [UID:0002K3]/[UID:0002K4] but not written by [UID:0002K7]/[UID:0002K8].

Recommended [UID:0000Y9] aggregate changes:

- Update child inventory ranges for [UID:0002K7]/[UID:0002K8].
- Add a boundary note that the aggregate currently has additional raw source-shaped setter bodies around `0x0045c020`, `0x0045c030`, `0x0045c040`, `0x0045c1b0`, and `0x0045c1d0`; recommend separate child creation or an explicit no-xref/no-emitter decision later.

Recommended [UID:0003WR]/[UID:0003WS] parser child changes:

- Add the exact setter callsites:
  - `0x0045c49c` / `0x0045c770` call `SetStartTimeFromPackedDateTime`.
  - `0x0045c4b3` / `0x0045c787` call `SetEndTimeFromPackedDateTime`.
- Document that category-list and initial-page parsers supply `packedDate` then `packedTime` for each endpoint.

## Exact by-memory/-coverage-report.md Replacement Rows

Do not edit `by-memory/-coverage-report.md` directly. Replace the current [UID:0002K7] and [UID:0002K8] rows under [UID:0000Y9] with the following after the files are renamed or their internal titles are corrected:

```text
        - [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) 0x0045c050-0x0045c0f9 | method | RankingCategoryRecordSetStartTimeFromPackedDateTime : reconstructable : 88% : very strong : B005 2026-06-19 source-quality pass corrects the half-open range to the full 0xa9-byte `__thiscall` body ending in `c2 08 00` at PE raw offset `0x5b450` (SHA1 `6f8ad81d88a47803ddb555472dcad2896cfa0ce5`), with seven-byte `0xcc` postpad before [UID:0002K8]; two live parser callers at `0x0045c49c` and `0x0045c770`; no callees; source-facing `packedDate, packedTime` semantics; writes `m_startTime` second/minute/hour/day/month/year at `+0x0c..+0x20`; leaves reserved date-time dwords untouched; owner/emitter [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md); first-draft C++ ready.
        - [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) 0x0045c100-0x0045c1a9 | method | RankingCategoryRecordSetEndTimeFromPackedDateTime : reconstructable : 88% : very strong : B005 2026-06-19 source-quality pass corrects the half-open range to the full 0xa9-byte `__thiscall` body ending in `c2 08 00` at PE raw offset `0x5b500` (SHA1 `5db36d68b861e1df28309949538868a3f61c2d40`), with seven-byte `0xcc` postpad before the raw title/total setter gap; two live parser callers at `0x0045c4b3` and `0x0045c787`; no callees; source-facing `packedDate, packedTime` semantics; writes `m_endTime` second/minute/hour/day/month/year at `+0x30..+0x44`; leaves reserved date-time dwords untouched; owner/emitter [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md); first-draft C++ ready.
```

If the supervisor chooses to record the immediate padding rows separately, insert these rows adjacent to the corrected method rows:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045c0f9-0x0045c100 | padding | RankingCategoryRecord start/end packed setter alignment : ignored : 100% : strong : Confirmed seven `0xcc` bytes after [UID:0002K7] and before [UID:0002K8].
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045c1a9-0x0045c1b0 | padding | RankingCategoryRecord end packed setter/title setter alignment : ignored : 100% : strong : Confirmed seven `0xcc` bytes after [UID:0002K8] and before raw source-shaped title setter bytes at `0x0045c1b0`.
```

## Adjacent Support Gap Recommendations

These are not required to accept [UID:0002K7]/[UID:0002K8], but they are worth recording because the boundary audit found real source-shaped bytes in the same aggregate.

Recommended follow-up child pages if the supervisor wants complete nested coverage:

```text
by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md
by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md
```

Suggested coverage rows, using supervisor-assigned UIDs:

```text
        - [UID:TBD][0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md) 0x0045c1b0-0x0045c1cb | raw-method | RankingCategoryRecordSetTitleText : reconstructable : 84% : medium-strong : Raw PE bytes show a source-shaped `__thiscall` setter that calls wide copy helper `0x005cd650` as `wcscpy_s(this+0x54, 0x100, input)`, matching the accepted `wchar_t m_title[256]` field. Direct xref/liveness was not fully resolved in this B005 pass; recommend separate support audit before formal C++.
        - [UID:TBD][0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md) 0x0045c1d0-0x0045c1e0 | raw-method | RankingCategoryRecordSetTotalRankCount : reconstructable : 84% : medium-strong : Raw PE bytes show a source-shaped `__thiscall` setter storing the input dword to record offset `+0x254`, matching accepted `m_totalRankCount`; direct xref/liveness was not fully resolved in this B005 pass, so defer formal C++ until a focused support audit.
```

Also consider a later aggregate-range audit for raw source-shaped setters at `0x0045c020`, `0x0045c030`, and `0x0045c040`, likely list-index/category-id/state-code setters. They are outside the assigned pair and were not fully researched here.

## Generated-Output Expectation

Current generated `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` includes [UID:0000BL] class declaration and sibling method bodies for [UID:0002K0]-[UID:0002K6]/[UID:0002KA], but [UID:0002K7] and [UID:0002K8] are still empty emitter markers.

After supervisor incorporation:

- [UID:0002K7] should emit `RankingCategoryRecord::SetStartTimeFromPackedDateTime`.
- [UID:0002K8] should emit `RankingCategoryRecord::SetEndTimeFromPackedDateTime`.
- The class declaration in [UID:0000BL] already contains matching prototypes, so no new source root is needed.

## Validation / Commands

Commands and checks performed:

- Read mandate docs and target/support docs with `Get-Content`.
- Searched current docs, executed B-agent reports, generated output, unresolved/resolved reports, and coverage reports with `rg` / `Select-String`.
- Probed IDA MCP with JSON-RPC `tools/list`; endpoint unavailable.
- Performed raw PE byte audits against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with a PE section parser in PowerShell.
- Performed direct-call scan over the parser ranges for the assigned setter targets; it confirmed the current documented callsites:
  - `0x0045c49c`, `0x0045c770` -> [UID:0002K7]
  - `0x0045c4b3`, `0x0045c787` -> [UID:0002K8]
- Ran `tools/int_convert.py` for `0xa9`, `0x24`, `0x2b0`, `0x4c`, `0x100`, `0x254`, `0x0c`, and `0x30`; key decimal values used in this report are marked as verified where applicable.

No validator was run because this is report-only and no target/support/coverage docs were directly edited.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B005/research/0002K7-0002K8-RankingCategoryRecordPackedDateTimeSetters-source-quality.md
```

No by-* docs, generated files, coverage reports, or tool-owned files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002K7-0002K8-RankingCategoryRecordPackedDateTimeSetters-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002K7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
