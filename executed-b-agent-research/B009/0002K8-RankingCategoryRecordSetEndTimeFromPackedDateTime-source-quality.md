** TARGET-REPORT-UID:0002K8 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002K8] RankingCategoryRecordSetEndTimeFromPackedDateTime Source-Quality Report

Agent: Agent-B009  
Date: 2026-06-19  
Assignment: report-only B-agent source-quality / heuristic reanalysis  
Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0002K8] as a source-authored `RankingCategoryRecord` method, correct its half-open range to `0x0045c100-0x0045c1a9`, raise to `88/91`, and populate first-draft C++ through [UID:0000BL] `RankingCategoryRecord`.
- Final disposition: no split is needed inside the method. The current page/path is one byte short and should be renamed or internally corrected from `0x0045c100-0x0045c1a8` to `0x0045c100-0x0045c1a9` because the final `00` byte of `ret 8` is currently outside the documented range.
- Required action: supervisor callback should lease the target/support docs, rename/update the target, populate the method C++, update support rows/ranges, and leave `by-memory/-coverage-report.md` to supervisor-owned application using the exact row below.
- Confidence: very strong for behavior, owner/emitter route, range correction, and source C++ shape; medium-high for exact original spelling because no symbols prove the original method/field names.

## Target

- Target UID: [UID:0002K8].
- Current target path: `by-memory/0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`.
- Recommended target path/title: `by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`.
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BL`, blank formal C++.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000BL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BL`.
- Current source route: [UID:0002K8] -> [UID:0000BL] `RankingCategoryRecord` -> [UID:0000MZ] `RankingDialog` / `NexusTK/ui/dialogs/RankingDialog.cpp`.
- Current generated-output state: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` already declares `void SetEndTimeFromPackedDateTime(int packedDate, int packedTime);` in `RankingCategoryRecord`, but [UID:0002K8] is still emitted only as an empty marker.

## Executive Recommendation

Populate [UID:0002K8] as:

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

This source order matches the binary's source-level grouping: the first stack argument is split into date fields first (`year`, `month`, `day`), then the second stack argument is split into time fields (`hour`, `minute`, `second`). The method intentionally does not touch `RankingDateTimeParts::reserved0`, `reserved1`, or `reserved2`; those trailing dwords are only preserved by the 36-byte copy helpers.

No no-code proof applies. This is not compiler glue, not a thunk, not a vector helper, and not an aggregate-only page. It is a live `__thiscall` source-authored record mutator with a valid emitter route and a source-ready support declaration.

## Supervisor Active Recheck

- This task was assigned specifically for [UID:0002K8] after earlier B reports left this row at `84/90` with blank formal C++.
- The assignment did not authorize by-* edits. No by-* docs or coverage reports were edited in this report pass.
- Split repair inside the target is not required, but path/range repair is required because the current half-open end excludes the final byte of the method's `ret 8`.
- Adjacent source-shaped raw setters after the target are not part of [UID:0002K8]. They remain a support/aggregate follow-up and should not be folded into this method.

## Evidence Checked

- Process and rules:
  - `tools/leaser/Agents/Agent-B009/goal.md`
  - `tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `by-structure.md`
  - `inference_research.md`
- Primary target/support docs:
  - [UID:0002K8] `by-memory/0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`
  - [UID:0002K7] `by-memory/0x0045c050-0x0045c0f8.RankingCategoryRecordSetStartTimeFromPackedDateTime.md`
  - [UID:0002K3] `by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md`
  - [UID:0002K4] `by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md`
  - [UID:0000BL] `by-class/RankingCategoryRecord.md`
  - [UID:0001VN] `by-type/by-struct/RankingCategoryRecordLayout.md`
  - [UID:0000Y9] `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md`
  - [UID:0000BK] `by-class/RankingCategoryCollection.md`
  - [UID:0003WR] `by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md`
  - [UID:0003WS] `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md`
  - [UID:0000BQ] `by-class/RankingUserListPane.md`
  - [UID:0000MZ] `by-file/RankingDialog.md`
- Prior reports checked as leads, not authority:
  - `tools/leaser/Agents/Agent-B002/research/executed/0002K0-0002K6-0002KA-0001ZD-ranking-category-record-source-quality.md`
  - `tools/leaser/Agents/Agent-B002/research/executed/older/0001ZC-ranking-category-collection-source-quality.md`
  - `tools/leaser/Agents/Agent-B005/research/executed/0000BQ-RankingUserListPane-class-source-quality.md`
  - `tools/leaser/Agents/Agent-B005/research/0002K7-0002K8-RankingCategoryRecordPackedDateTimeSetters-source-quality.md`
- Generated and report context:
  - `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
- Raw binary evidence:
  - `E:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
  - Raw PE byte/range scan for `0x0045c100-0x0045c1a9`, prepad/postpad, adjacent raw setters, direct rel32 calls, and VA/RVA/raw-offset pointer patterns.
- IDA MCP status:
  - Probed `http://127.0.0.1:13337/mcp` during this pass. It was unavailable: `Unable to connect to the remote server`.
  - Current findings therefore use raw PE bytes, existing docs that record earlier live IDA checks, generated output, and local direct-call/pointer scans. Confidence remains below final-audit levels for that reason.

## IDA / Raw PE Facts

### Range, Bytes, And Padding

The current target filename and coverage row say `0x0045c100-0x0045c1a8`, but the modeled function size in the target doc is `0xa9` / 169 decimal (Verified with `int_convert.py`). Raw bytes confirm that the current half-open endpoint captures only `c2 08` and excludes the final `00` of `c2 08 00`.

Current documented body, one byte short:

```text
K8-current-doc VA 0x0045c100-0x0045c1a8 raw 0x5b500 len 0xa8 sha1 5f64140bfb81b0e56eef30425bbbfcbdfaaaeb90
55 8b ec 56 8b 75 08 b8 ad 8b db 68 f7 ee 57 8b f9 c1 fa 0c 8b c2 8b ce c1 e8 1f 03 c2 89 47 44 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 c1 fa 05 8b c2 c1 e8 1f 03 c2 89 47 40 b8 1f 85 eb 51 f7 ee b8 ad 8b db 68 c1 fa 05 8b ca c1 e9 1f 03 ca 6b c9 64 2b f1 89 77 3c 8b 75 0c 8b ce f7 ee c1 fa 0c 8b c2 c1 e8 1f 03 c2 89 47 38 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 b8 1f 85 eb 51 c1 fa 05 8b ca c1 e9 1f 03 ca f7 ee 89 4f 34 c1 fa 05 8b c2 c1 e8 1f 03 c2 6b c0 64 2b f0 89 77 30 5f 5e 5d c2 08
```

Correct full body:

```text
K8-corrected-body VA 0x0045c100-0x0045c1a9 raw 0x5b500 len 0xa9 sha1 5db36d68b861e1df28309949538868a3f61c2d40
55 8b ec 56 8b 75 08 b8 ad 8b db 68 f7 ee 57 8b f9 c1 fa 0c 8b c2 8b ce c1 e8 1f 03 c2 89 47 44 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 c1 fa 05 8b c2 c1 e8 1f 03 c2 89 47 40 b8 1f 85 eb 51 f7 ee b8 ad 8b db 68 c1 fa 05 8b ca c1 e9 1f 03 ca 6b c9 64 2b f1 89 77 3c 8b 75 0c 8b ce f7 ee c1 fa 0c 8b c2 c1 e8 1f 03 c2 89 47 38 69 c0 10 27 00 00 2b c8 b8 1f 85 eb 51 f7 e9 b8 1f 85 eb 51 c1 fa 05 8b ca c1 e9 1f 03 ca f7 ee 89 4f 34 c1 fa 05 8b c2 c1 e8 1f 03 c2 6b c0 64 2b f0 89 77 30 5f 5e 5d c2 08 00
```

Padding and adjacent functions:

```text
K7-postpad-before-K8 VA 0x0045c0f9-0x0045c100 raw 0x5b4f9 len 0x7
cc cc cc cc cc cc cc

K8-postpad VA 0x0045c1a9-0x0045c1b0 raw 0x5b5a9 len 0x7
cc cc cc cc cc cc cc

K8-next-raw1 VA 0x0045c1b0-0x0045c1cb raw 0x5b5b0 len 0x1b sha1 b7a92bc2100b56c35a2630cda2ebff4da9eefd5a
55 8b ec ff 75 08 8d 41 54 68 00 01 00 00 50 e8 93 14 17 00 83 c4 0c 5d c2 04 00

K8-next-pad VA 0x0045c1cb-0x0045c1d0 raw 0x5b5cb len 0x5
cc cc cc cc cc

K8-next-raw2 VA 0x0045c1d0-0x0045c1e0 raw 0x5b5d0 len 0x10 sha1 3cc98a12a7b6cb223e9ab4e2a5f8500e336db13b
55 8b ec 8b 45 08 89 81 54 02 00 00 5d c2 04 00
```

Interpretation:

- The target should end at `0x0045c1a9`, not `0x0045c1a8`.
- The seven bytes at `0x0045c1a9-0x0045c1b0` are padding.
- The next raw body at `0x0045c1b0-0x0045c1cb` is a separate likely `RankingCategoryRecordSetTitleText` helper (`this + 0x54`, length `0x100`, call to the wide copy helper), not part of [UID:0002K8].
- The raw body at `0x0045c1d0-0x0045c1e0` stores a dword to `this + 0x254`, best `RankingCategoryRecordSetTotalRankCount`, also not part of [UID:0002K8].

### Direct Calls And Pointer Hits

Direct rel32 call scan over `.text` found exactly two direct calls to `0x0045c100`:

```text
Direct rel32 calls to 0x0045c100: 0x0045c4b3, 0x0045c787
```

Callsite bytes:

```text
around-call-45c4b3 VA 0x0045c490-0x0045c4bd raw 0x5b890 len 0x2d
8b 85 2c fa ff ff 89 85 44 fa ff ff e8 af fb ff ff ff b5 20 fa ff ff 8d 8d 40 fa ff ff ff b5 1c fa ff ff e8 48 fc ff ff 0f be 85 3f fa

around-call-45c787 VA 0x0045c760-0x0045c791 raw 0x5bb60 len 0x31
f4 f7 ff ff 8b 85 cc f7 ff ff 89 85 f8 f7 ff ff e8 db f8 ff ff ff b5 d4 f7 ff ff 8d 8d f4 f7 ff ff ff b5 ec f7 ff ff e8 74 f9 ff ff 0f be 85 e7 f7
```

The same local parser regions call the start-time twin first:

```text
around-start-call-45c49c VA 0x0045c480-0x0045c4a6 raw 0x5b880 len 0x26
c6 89 4d fc 8d 8d 40 fa ff ff 89 85 40 fa ff ff 8b 85 2c fa ff ff 89 85 44 fa ff ff e8 af fb ff ff ff b5 20 fa ff

around-start-call-45c770 VA 0x0045c750-0x0045c77a raw 0x5bb50 len 0x2a
b5 d8 f7 ff ff 89 4d fc 8d 8d f4 f7 ff ff 89 85 f4 f7 ff ff 8b 85 cc f7 ff ff 89 85 f8 f7 ff ff e8 db f8 ff ff ff b5 d4 f7 ff
```

Raw pattern scan for little-endian target VA/RVA/raw-offset found no non-call pointer/storage hits:

```text
VA hits for 0x0045c100: none
RVA hits for 0x0005c100: none
Raw-offset hits for 0x0005b500: none
```

The method is therefore reached as ordinary parser code, not through a vtable or static pointer table.

## Function Semantics

[UID:0002K8] is a `__thiscall` member function with two stack arguments and `ret 8`. Current docs record no callees; the raw body contains arithmetic, stores, register save/restore, and return only. The compiler uses signed multiply/shift magic constants for division by decimal `10000` (`0x2710`, Verified with `int_convert.py`) and `100` (`0x64`, Verified with `int_convert.py`). Source should express this as ordinary `/` and `%` on nonnegative packet integers.

Binary/source order:

| Binary write order | Field | Offset | Source expression |
| ---: | --- | --- | --- |
| 1 | `m_endTime.year` | `+0x44` | `packedDate / 10000` |
| 2 | `m_endTime.month` | `+0x40` | `(packedDate % 10000) / 100` |
| 3 | `m_endTime.day` | `+0x3c` | `packedDate % 100` |
| 4 | `m_endTime.hour` | `+0x38` | `packedTime / 10000` |
| 5 | `m_endTime.minute` | `+0x34` | `(packedTime % 10000) / 100` |
| 6 | `m_endTime.second` | `+0x30` | `packedTime % 100` |

Offset order:

| Offset | Field | Stored expression |
| --- | --- | --- |
| `+0x30` | `m_endTime.second` | `packedTime % 100` |
| `+0x34` | `m_endTime.minute` | `(packedTime % 10000) / 100` |
| `+0x38` | `m_endTime.hour` | `packedTime / 10000` |
| `+0x3c` | `m_endTime.day` | `packedDate % 100` |
| `+0x40` | `m_endTime.month` | `(packedDate % 10000) / 100` |
| `+0x44` | `m_endTime.year` | `packedDate / 10000` |

Important negative behavior:

- No range validation or clamping occurs.
- No date/time normalization occurs.
- No allocation or string conversion occurs.
- No parser cursor reads happen in this method; parser helpers prepare the two packed integer arguments before calling it.
- No reserved date-time fields are touched. `RankingDateTimeParts` is `0x24` / 36 bytes (Verified with `int_convert.py`), but this setter initializes only six dwords / 24 bytes. The trailing three dwords are copied by [UID:0002K3]/[UID:0002K4] and deep-copy helpers.

## Packed Date/Time Parameter Order

Best source-facing signature:

```cpp
void RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime);
```

Evidence:

- Inside [UID:0002K8], `[ebp+8]` is split into `year/month/day` fields and `[ebp+0x0c]` is split into `hour/minute/second` fields.
- [UID:0002K7] has the same argument order and writes the same layout into the start-time block.
- [UID:0002K3]/[UID:0002K4] copy the date/time blocks as 36-byte `RankingDateTimeParts` values, proving the end block starts at `+0x30` and has the same layout as start.
- [UID:0000BQ] `RankingUserListPane::OnPaint` formats copied parts with `From : %02d/%02d/%04d %02d:%02d:%02d` and `To : %02d/%02d/%04d %02d:%02d:%02d`, validating `month/day/year hour/minute/second` display use for both copied blocks.
- Parser callsites call the start setter and then the end setter from the same category-list parser records, matching category/event start and end endpoint semantics.

Rejected alternatives:

- `packedTime, packedDate`: rejected because the first argument produces date fields and the second argument produces time fields.
- One packed timestamp argument: rejected because the function has two 32-bit stack arguments and `ret 8`.
- `start, end` parameters: rejected because start/end is the method target; the two parameters are date and time halves for one endpoint.
- Generic `DecodePackedDateTime`: rejected as a source-facing name because this function writes `this->m_endTime` directly and is not a reusable utility.

## Relationship To Start-Time Twin

[UID:0002K7] at `0x0045c050` is the exact start-time twin. Raw PE evidence confirms its corrected full range is `0x0045c050-0x0045c0f9`, also `0xa9` / 169 bytes (Verified with `int_convert.py`), with seven `0xcc` bytes before [UID:0002K8]. The twin writes the same six expressions into `m_startTime` at `+0x0c..+0x20`.

The two functions differ only in destination offsets:

- Start setter: `+0x20/+0x1c/+0x18` for date, then `+0x14/+0x10/+0x0c` for time.
- End setter: `+0x44/+0x40/+0x3c` for date, then `+0x38/+0x34/+0x30` for time.

Support implication: the supervisor can safely apply the same source-quality policy to [UID:0002K7] later, but this report's required target and exact coverage row are [UID:0002K8].

## Copy Helpers And Formatter Consumers

- [UID:0002K4] `RankingCategoryRecordCopyEndTimeParts` copies 36 bytes from `m_endTime` at `+0x30`, returns the destination pointer, and already emits:

```cpp
RankingDateTimeParts* RankingCategoryRecord::CopyEndTimeParts(RankingDateTimeParts* out) const
{
    *out = m_endTime;
    return out;
}
```

- [UID:0002K3] does the same for `m_startTime` at `+0x0c`.
- The copy helpers prove the type/block size, while [UID:0002K8] proves the meaning of the first six fields in `m_endTime`.
- [UID:0000BQ] `RankingUserListPane::OnPaint` consumes both copied blocks for the `From`/`To` display lines. It formats date as `month/day/year` and time as `hour:minute:second`, so the internal order `second, minute, hour, day, month, year` is not an arbitrary offset guess.

## Heuristic / Inference Reanalysis And Validation

### Source-facing method name

- Existing name: `RankingCategoryRecordSetEndTimeFromPackedDateTime`.
- Best source method: `RankingCategoryRecord::SetEndTimeFromPackedDateTime`.
- Evidence: direct `this` field writes into the `m_endTime` block, paired start-time twin, parser records supplying packed date/time halves, and class declaration already containing the method.
- Rejected: `ParseEndTime` because parser work is in [UID:0003WR]/[UID:0003WS]; `DecodeEndDateTime` because it would hide the direct mutation; `SetEndDateTime` because it loses the important packed input-format distinction.
- Confidence: high descriptive, not symbol-proven.

### Parameter names and types

- Best source signature: `void SetEndTimeFromPackedDateTime(int packedDate, int packedTime)`.
- Evidence: stack arg 1 splits into year/month/day; stack arg 2 splits into hour/minute/second; parser/copy/formatter correlation validates this direction.
- Type: `int` is the safest source-facing type because support docs and generated class declaration already use `int`, packet values are nonnegative decimal integers, and the compiler's signed division sequences are compatible with source `int`.
- Rejected: `unsigned int` because the observed compiler sequence is sign-corrected and the current source declaration uses `int`; `short`/`WORD` because the values include `YYYYMMDD` and `HHMMSS`-shaped decimal integers.
- Confidence: high for order and width, medium-high for exact original spelling.

### End-time fields and offsets

- Best field path: `m_endTime.second/minute/hour/day/month/year`.
- Evidence: [UID:0001VN] records `m_endTime` at offset `+0x30` / 48 decimal (Verified with `int_convert.py`) and the setter writes through `+0x44` / 68 decimal (Verified with `int_convert.py`); [UID:0002K4] copies exactly 36 bytes from that block.
- Rejected: `SYSTEMTIME` because the field order does not match Windows `SYSTEMTIME` and the block has three extra dwords; C `tm` because year/month semantics and field order do not match `tm`.
- Confidence: high for offsets and field roles; medium-high for the invented support type name `RankingDateTimeParts`.

### Reserved date-time fields

- Best names: `reserved0`, `reserved1`, `reserved2` on `RankingDateTimeParts`.
- Evidence: copy helpers copy 36 bytes but setters write only the first six logical fields. No checked source path in this pass writes the three trailing dwords as date/time parts.
- Rejected: treating the setter as initializing the full `RankingDateTimeParts` object.
- Impact: C++ must not zero or assign the reserved fields.

### Source placement

- Best direct owner/emitter: [UID:0000BL] `RankingCategoryRecord`.
- Source root: [UID:0000MZ] `RankingDialog.cpp`.
- Evidence: [UID:0000BL] owns the record fields and declares the method; [UID:0000MZ] is the feature source root for ranking UI private classes; [UID:0000BK] parser functions call but do not own this field mutation; [UID:0000BQ] only consumes copied fields for painting.
- Rejected: direct [UID:0000BK] `RankingCategoryCollection` ownership because collection parser code is only a caller; generic date/time helper ownership because there is no reusable function or global table; no-owner/non-emitting because the current route already emits through a valid file root.

### Prior B002 claims

- Validated: B002's `RankingDateTimeParts` order, copy-helper agreement, and `packedDate, packedTime` direction remain correct.
- Superseded: B002's old statement that no score change was required for [UID:0002K7]/[UID:0002K8] is stale under the current 85/85-plus C++ gate and current support declaration state. The blockers have been resolved enough for formal C++.
- Superseded in support context: older B002 `+0x26c` `localPlayerName[32]` claims are not directly part of [UID:0002K8] but are stale in some support docs. B005's later `m_reservedLocalPlayerFooter[0x40]` correction is the current best support direction.

### Prior B005 packed-setter report

- Validated: B005's range correction, body SHA1, direct callsites, and first-draft C++ direction match this independent raw audit.
- Scoped difference: this B009 report is target-specific for [UID:0002K8], so the exact implementation/coverage row below focuses on [UID:0002K8]. The start-time twin should receive matching treatment in its own accepted callback or a paired supervisor action.

### Range/split/merge

- Best action: correct the endpoint to include the full `ret 8`.
- Rejected: leaving the filename at `0x0045c100-0x0045c1a8`, because it excludes a real instruction byte.
- Rejected: expanding through `0x0045c1e0`, because `0x0045c1a9-0x0045c1b0` is padding and the next two raw bodies are independent helper starts.
- Impact: target page should be renamed or at least have its title, evidence, and coverage row corrected. Support docs should use `0x0045c100-0x0045c1a9`.

### Compiler-generated/raw-name policy

- [UID:0002K8] itself is not compiler-generated. It should not be documented as no-code glue.
- Raw adjacent helpers at `0x0045c1b0` and `0x0045c1d0` are separate source-shaped record setters. They should be researched/created separately if the supervisor wants the aggregate fully split, but their unresolved state does not block [UID:0002K8].
- IDA/generated placeholder `sub_45C100` should be replaced with `RankingCategoryRecord_SetEndTimeFromPackedDateTime` or equivalent IDB name.

### Final C++ readiness

- Current combined score `84/90` already averages above 85, and the emitter route is nonblank and valid. The only old reason for blank C++ was source-quality uncertainty.
- Current support declarations now resolve the old blocker: [UID:0000BL] declares `RankingDateTimeParts`, `m_endTime`, and the method prototype.
- The method is a complete function range, not a fragment, so the by-memory page can carry the whole method body.
- Recommendation: populate formal C++ in the target during implementation callback.

## Ranked Ownership Analysis

### 1. [UID:0000BL] RankingCategoryRecord - accepted

- Evidence for: direct field writes to the record; class declaration already contains `m_endTime` and method prototype; start/end/copy helpers all attach to the class; layout page clears support gate.
- Evidence against: exact original class/member names are inferred rather than symbol-proven, but current docs and generated output already use these names consistently.
- Decision: keep as canonical owner and emitter.

### 2. [UID:0000MZ] RankingDialog - accepted file root, rejected as direct owner

- Evidence for: ranking record is private support for the ranking dialog source module; generated route surfaces to `NexusTK/ui/dialogs/RankingDialog.cpp`.
- Evidence against: by-structure rules prefer the direct semantic owner; the method is a record member, not a file-level free helper.
- Decision: keep as source root only.

### 3. [UID:0000BK] RankingCategoryCollection - rejected as direct owner

- Evidence for: two parser methods call the end setter while constructing/updating records.
- Evidence against: parser caller ownership does not supersede record field ownership; the receiver is the record object.
- Decision: document caller relationship but do not move ownership/emitter to collection.

### 4. [UID:0000BQ] RankingUserListPane - rejected

- Evidence for: it displays the copied end date/time.
- Evidence against: consumer/read/formatter xrefs validate layout but do not own the setter.
- Decision: keep as consumer evidence only.

### 5. No-owner/non-emitting - rejected

- Evidence for: none under current docs.
- Evidence against: target is reconstructable, has a valid direct owner/emitter, and has source-ready C++.
- Decision: do not leave non-emitting.

## Score / Metadata Recommendation

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000BL
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000BL
```

Rationale:

- Raise completion from `84` to `88` because the report resolves the stale source-quality blocker, verifies corrected raw range/bytes/SHA1/padding, gives direct-call evidence, documents no pointer-table route, resolves parameter direction, names the end-time fields, ties the method to copy helpers and formatter consumers, and supplies first-draft C++.
- Raise confidence from `90` to `91` because independent raw PE evidence confirms the most important boundary and callsite claims, while existing accepted docs provide earlier live IDA support for decompilation, callers, and layout.
- Keep below `95` because live IDA MCP was unavailable in this pass, exact original source spellings are inferred/descriptive, and adjacent raw record setters still need their own child pages or no-xref policy.

## First-Draft C++ Recommendation

Populate [UID:0002K8]'s formal `RECONSTRUCTION_CPP CODE` block with:

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

Why this is plausible mid-2000s source:

- It uses the existing simple record class and member names rather than raw pointer arithmetic.
- It uses ordinary decimal division/modulo rather than compiler magic constants.
- It keeps the method focused on one record endpoint and does not pull parser code or formatter code into the method.
- It avoids zeroing/copying reserved fields that the binary does not touch.
- It matches the existing class declaration already emitted by [UID:0000BL].

## Exact Recommended Target Doc Changes

For `by-memory/0x0045c100-0x0045c1a8.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`:

1. Rename to `by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md`, or if the supervisor defers filesystem rename, update the title/body to state the correct half-open range clearly.
2. Change metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter/reconstructable metadata unchanged.
3. Replace stale wording that keeps final C++ blocked by parser field names/declaration policy. The current support declaration and layout evidence are strong enough for first-draft method C++.
4. Add exact raw byte evidence:
   - Current old range `0xa8` bytes, SHA1 `5f64140bfb81b0e56eef30425bbbfcbdfaaaeb90`, missing the last `00`.
   - Correct body `0x0045c100-0x0045c1a9`, raw `0x5b500`, `0xa9` / 169 bytes (Verified with `int_convert.py`), SHA1 `5db36d68b861e1df28309949538868a3f61c2d40`.
   - Seven `0xcc` prepad from start twin at `0x0045c0f9-0x0045c100`.
   - Seven `0xcc` postpad at `0x0045c1a9-0x0045c1b0`.
5. Add direct-call evidence:
   - `0x0045c4b3` in [UID:0003WR] `ParseCategoryListResponse`.
   - `0x0045c787` in [UID:0003WS] `ParseInitialCategoryPageResponse`.
   - No VA/RVA/raw-offset pointer pattern hits for `0x0045c100`.
6. Add behavior tables in both binary write order and field-offset order.
7. Add first-draft C++ exactly as recommended above.
8. Add a source-quality note rejecting no-code/compiler-glue classification.

## Support-Doc Update Checklist

Required or strongly recommended during supervisor implementation callback:

- [UID:0000BL] `by-class/RankingCategoryRecord.md`
  - Update method inventory endpoint for [UID:0002K8] to `0x0045c100-0x0045c1a9`.
  - Add that `SetEndTimeFromPackedDateTime` initializes only `m_endTime.year/month/day/hour/minute/second` and leaves `reserved0/reserved1/reserved2` untouched.
  - No score change required unless supervisor also applies paired [UID:0002K7] range/C++ work.
- [UID:0001VN] `by-type/by-struct/RankingCategoryRecordLayout.md`
  - Add corrected [UID:0002K8] range and raw byte/range note.
  - Clarify the setter writes only the first six fields of the `+0x30` block, while copy helpers preserve the full `0x24` / 36-byte block (Verified with `int_convert.py`).
  - No score change required by this target alone.
- [UID:0000Y9] `by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md`
  - Update child inventory link/range for [UID:0002K8] to `0x0045c100-0x0045c1a9`.
  - Correct stale layout summary line `+0x26c-+0x2ab: wchar_t localPlayerName[32]` to the current supported wording: `copied/reserved local-player footer tail` / `m_reservedLocalPlayerFooter[0x40]`.
  - Add boundary note that `0x0045c1b0-0x0045c1cb` and `0x0045c1d0-0x0045c1e0` are adjacent source-shaped raw setters outside [UID:0002K8].
- [UID:0003WR] `by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md`
  - Add exact callsite `0x0045c4b3` to `SetEndTimeFromPackedDateTime`, after the start setter call at `0x0045c49c`, and document that the parser supplies `packedDate` then `packedTime`.
- [UID:0003WS] `by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md`
  - Add exact callsite `0x0045c787` to `SetEndTimeFromPackedDateTime`, after the start setter call at `0x0045c770`, and document that the parser supplies `packedDate` then `packedTime`.
  - Correct stale local-player metadata wording that still says `localPlayerName[32]` to the current `m_reservedLocalPlayerFooter[0x40]` support wording unless a later focused parser pass proves otherwise.
- [UID:0000BQ] `by-class/RankingUserListPane.md`
  - No required score/path change. It already records that `OnPaint` uses `CopyEndTimeParts` and formats the `To` date/time line; only add a backlink if the supervisor wants a tighter source-quality trail.
- [UID:0000MZ] `by-file/RankingDialog.md`
  - No direct change required. The file route already clears the gate and generated output already includes the class declaration.

## Exact Supervisor-Owned Coverage Row Text

Do not edit `by-memory/-coverage-report.md` directly in the B-agent report pass. Replace the current [UID:0002K8] row under [UID:0000Y9] with this row after the target is renamed or internally corrected:

```text
        - [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) 0x0045c100-0x0045c1a9 | method | RankingCategoryRecordSetEndTimeFromPackedDateTime : reconstructable : 88% : very strong : B009 2026-06-19 source-quality pass corrects the half-open range to the full `0xa9` / 169-byte body (Verified with `int_convert.py`) ending in `c2 08 00` at PE raw `0x5b500` (SHA1 `5db36d68b861e1df28309949538868a3f61c2d40`), with seven `0xcc` bytes at `0x0045c1a9-0x0045c1b0`; source-authored `RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime)`; no callees; direct parser calls at `0x0045c4b3` and `0x0045c787`; no VA/RVA/raw-offset pointer hits; writes `m_endTime.year/month/day` from `packedDate` and `m_endTime.hour/minute/second` from `packedTime` at offsets `+0x44/+0x40/+0x3c/+0x38/+0x34/+0x30`; leaves `RankingDateTimeParts` reserved dwords untouched; owner/emitter [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); first-draft C++ ready.
```

If the supervisor chooses to add an explicit ignored padding row, insert this adjacent to the corrected row:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0045c1a9-0x0045c1b0 | padding | RankingCategoryRecord end packed setter/title setter alignment : ignored : 100% : strong : Confirmed seven `0xcc` bytes after [UID:0002K8] and before raw source-shaped title setter bytes at `0x0045c1b0`.
```

## Validator Commands Expected After Implementation

From `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality-removed.md](0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback renames the target file, validate the new path after the move. If validator reports stale references to the old path, update the support docs that contain generated annotations for [UID:0002K8] and rerun scoped file validators. A broad documented cleanup should not be necessary unless UID mapping/path state remains stale after file-mode validation.

No validators were run during this report-only pass because no by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

- Rename IDA function at `0x0045c100` from any raw/generated name such as `sub_45C100` to `RankingCategoryRecord_SetEndTimeFromPackedDateTime`.
- Use a function type equivalent to:

```cpp
void __thiscall RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime);
```

or IDA C-style:

```cpp
void __thiscall RankingCategoryRecord_SetEndTimeFromPackedDateTime(RankingCategoryRecord *this, int packedDate, int packedTime);
```

- Apply/confirm struct fields:
  - `RankingCategoryRecord::m_endTime` at `+0x30`.
  - `RankingDateTimeParts::second` at block `+0x00`, `minute` at `+0x04`, `hour` at `+0x08`, `day` at `+0x0c`, `month` at `+0x10`, `year` at `+0x14`, then reserved dwords.
- Add a repeatable IDA comment at `0x0045c100`: "Splits packedDate YYYYMMDD and packedTime HHMMSS into RankingCategoryRecord::m_endTime; leaves reserved date-time dwords untouched."
- Add callsite comments at `0x0045c4b3` and `0x0045c787` noting the category-list parser end-time setter route.

## Implementation Instructions For Supervisor Callback

When the supervisor accepts this report, send B009 an implementation checklist with these exact actions:

1. Lease all existing target/support docs before editing. Do not edit `by-memory/-coverage-report.md`.
2. Rename/update [UID:0002K8] from `0x0045c100-0x0045c1a8...` to `0x0045c100-0x0045c1a9...`.
3. Set metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep owner/emitter/reconstructable values.
4. Replace stale no-C++/defer wording with source-ready reasoning and populate the C++ block exactly as listed in this report.
5. Add raw byte, SHA1, padding, direct-call, negative pointer-hit, parameter-order, field-offset, and rejected-alternative evidence at report-level detail.
6. Update support docs listed above, including the [UID:0000Y9] stale `+0x26c` layout summary and [UID:0003WS] stale `localPlayerName[32]` sentence if those files are included in the callback.
7. Run the scoped validator commands listed above and report exact results.
8. Record the exact pending supervisor-owned `by-memory/-coverage-report.md` replacement row from this report in implementation notes/final response.

## Open Questions And Their Status

- Exact original method spelling: unresolved because symbols are unavailable and IDA MCP was offline. Best descriptive name is still strong enough for source output because current class docs, generated code, and sibling methods already use this naming family.
- Exact original support type spelling: unresolved; `RankingDateTimeParts` is descriptive/inferred. It is still the strongest current type name because it is used consistently by the class declaration and copy-helper C++ and because standard alternatives are contradicted by field order/size.
- Adjacent raw setters: not resolved in this target pass. Raw bytes strongly suggest `SetTitleText` and `SetTotalRankCount` helpers, but direct xref/liveness and child page creation should be handled separately. They do not cap [UID:0002K8] below `88/91`.
- Live IDA decompilation refresh: unavailable in this session. Existing accepted docs record earlier live IDA checks; raw bytes and direct-call scans independently validate the target-critical claims.

## Changed Files

Created:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality.md
```

Modified: none.  
Moved/renamed: none.  
By-* docs edited: none.  
Coverage reports edited: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002K8"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002K8-RankingCategoryRecordSetEndTimeFromPackedDateTime-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002K8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
