** TARGET-REPORT-UID:0002K9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002K9] RankingCategoryRecordAppendUserEntry Source-Quality Report

Agent: Agent-B002  
Assignment: B002-goal2-ranking-user-entry-append-source-quality-0002K9-20260616  
Target: `by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md`  
Status: report-only; no by-* docs, generated reports, coverage reports, or IDA database edits performed.

## Executive Decision

[UID:0002K9] should be raised from `82/88` to `86/90`.

The target is a source-authored `RankingCategoryRecord` method boundary whose compiled body is a direct vector append fast path plus a call to the already split generated growth helper [UID:0003X1]. Live IDA evidence resolves the former blocker: the row layout is now supported by [UID:0001VN] and [UID:0000BL], the sole direct caller is the subcommand-2 row parser [UID:0003WT], and the only callee is the `0x4c`-stride user-entry vector growth helper.

Recommended route:

```yaml
UID: 0002K9
PATH: by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md
RANGE: 0x0045c1e0-0x0045c238
IDA_FUNCTION: 0x0045c1e0 size 0x59
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BL
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BL
FINAL_CPP: blank for now; eligible once the RankingCategoryRecord/RankingUserEntry declarations are emitted
```

No new child split is recommended for [UID:0002K9]. The function is already an exact method-sized unit. The generated helper boundary stays in [UID:0003X1], with [UID:0003X2]/[UID:0003X3] as supporting compiler/container copy helpers.

## Evidence Checked

Documentation checked:

- [UID:0002K9] target page: current `82/88`, owner/emitter [UID:0000BL], reconstructable TRUE, blank final C++.
- [UID:0000BL] `RankingCategoryRecord`: current `86/90`, includes the `+0x258/+0x25c/+0x260` user-entry vector and the `AppendUserEntry` method note.
- [UID:0001VN] `RankingCategoryRecordLayout`: current `87/91`, includes `RankingUserEntry` row offsets `+0x00/+0x04/+0x08/+0x48`.
- [UID:0003WT] `RankingCategoryCollectionParseRankingRowsResponse`: current `87/90`, the subcommand-2 row parser and sole direct caller.
- [UID:0003X1] `RankingUserEntryVectorInsertWithGrowth`: current `86/90`, generated growth helper called by this target when full.
- [UID:0003X2]/[UID:0003X3]: generated copy/clone helpers for `0x4c` user-entry ranges.
- [UID:0000Y9] aggregate `RankingCategoryRecord`: current header `85/89`; coverage row remains stale at `84%`.

Live IDA MCP evidence checked on 2026-06-16:

- Active database: `b002_ranking_0001ZC_20260616`, input `NexusTK.exe`, Hex-Rays available.
- `lookup_funcs 0x0045c1e0`: function name `RankingCategoryRecord_AppendUserEntry`, size `0x59`.
- `analyze_function 0x0045c1e0`: prototype modeled as `int __thiscall(_DWORD *this, int)`, caller `sub_45CB10`, callee `sub_45D1B0`, complexity 1.
- `xrefs_to 0x0045c1e0`: one code xref from `0x0045cd5d` inside `sub_45CB10` ([UID:0003WT]).
- `xrefs_to 0x0045d1b0`: xrefs from `0x0045c230` inside this function and `0x0045caa9` inside the subcommand-3 parser; this target owns only the `0x0045c230` append-full call.
- `decompile 0x0045c1e0`: fast path copies exactly one `0x4c` row and advances record `+0x25c` by `76`; full path calls `sub_45D1B0`.
- `decompile 0x0045cb10`: caller builds a stack row as category id, rank, wide name, score/value, then passes its address to this method.

## IDA Function Facts

Documented page range: `0x0045c1e0-0x0045c238`. Live IDA reports start `0x0045c1e0` and size `0x59`, matching bytes `[0x0045c1e0, 0x0045c239)` if expressed half-open. The next real method begins at `0x0045c240`, so the existing page is the correct method page and no padding/child split is needed.

Decompiled shape:

```c
int __thiscall RankingCategoryRecord_AppendUserEntry(_DWORD *this, int a2)
{
  _DWORD *v2;
  int v3;
  int result;

  v2 = this + 150;        // record +0x258 vector begin field
  v3 = this[151];         // record +0x25c vector current/end field
  if (v2[2] == v3)        // record +0x260 capacity == current
    return sub_45D1B0(v3, a2);

  *(_OWORD *)v3 = *(_OWORD *)a2;
  *(_OWORD *)(v3 + 16) = *(_OWORD *)(a2 + 16);
  *(_OWORD *)(v3 + 32) = *(_OWORD *)(a2 + 32);
  *(_OWORD *)(v3 + 48) = *(_OWORD *)(a2 + 48);
  *(_QWORD *)(v3 + 64) = *(_QWORD *)(a2 + 64);
  result = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v3 + 72) = result;
  v2[1] += 76;
  return result;
}
```

Important interpretation:

- `this + 150` is dword indexing, not byte offset `0x150`; it is byte offset `150 * 4 = 0x258`.
- `this[151]` is byte offset `0x25c`, the current/end pointer.
- `v2[2]` is byte offset `0x260`, the capacity pointer.
- The fast path copies `16 + 16 + 16 + 16 + 8 + 4 = 76` bytes, exactly `0x4c`.
- The copied trailing dword is returned by the binary fast path, but the only direct caller ignores the return value. This is not enough to infer a source-level non-void return.

## Caller And Row Construction

The sole direct caller is [UID:0003WT] at `0x0045cd5d` inside `sub_45CB10`.

The caller parses the row response for ranking subcommand 2. It validates the selected category id, finds the matching `RankingCategoryRecord`, resets the record row vector current pointer, then loops through row records. For each row it builds a stack `RankingUserEntry`:

```c
row.categoryId = parsedCategoryId;     // row +0x00
row.rank       = parsedRank;           // row +0x04
row.name[32]   = converted wide name;  // row +0x08
row.score      = parsedScore;          // row +0x48
RankingCategoryRecord_AppendUserEntry(record, &row);
```

The stack row is backed by `v23[0]`, `v23[1]`, `Destination[32]`, and `v25` in the Hex-Rays output. The argument is a pointer to that contiguous stack object.

## Layout Dependencies

Required record fields from [UID:0001VN]/[UID:0000BL]:

```text
RankingCategoryRecord +0x258  RankingUserEntry* userEntriesBegin
RankingCategoryRecord +0x25c  RankingUserEntry* userEntriesEnd/current
RankingCategoryRecord +0x260  RankingUserEntry* userEntriesCapacity
```

Required user-entry row fields:

```text
RankingUserEntry +0x00  uint32_t categoryId
RankingUserEntry +0x04  uint32_t rank
RankingUserEntry +0x08  wchar_t  name[32]       // 64 bytes
RankingUserEntry +0x48  uint32_t score          // candidate spelling: score/value
sizeof(RankingUserEntry) = 0x4c
```

The support pages now justify these offsets. [UID:0001VN] should remain `87/91`; [UID:0000BL] should remain `86/90`. [UID:0002K9] was previously capped because the `RankingUserEntry` fields were under-supported. That blocker is resolved by the executed support refresh.

## Source Boundary And Owner Decision

Final owner decision: keep [UID:0002K9] under [UID:0000BL] `RankingCategoryRecord`.

Reasons:

- The `this` pointer is a record pointer, not a collection pointer.
- The method operates only on the record's user-entry vector at `+0x258/+0x25c/+0x260`.
- The caller [UID:0003WT] first finds a matching record, then calls this method on that record.
- [UID:0000BL] is now above gate (`86/90`) and is the narrowest correct canonical owner.
- [UID:0000MZ] remains the file-level route for generated output, but it is too broad to be the canonical owner for this method.
- [UID:0000BK] owns the collection parser and record container, but not this record-local append method.

Recommended source-facing method name and signature:

```cpp
void RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry);
```

Binary ABI note:

```cpp
int __thiscall RankingCategoryRecord_AppendUserEntry(RankingCategoryRecord* this, const RankingUserEntry* entry);
```

The source-facing signature should be `void` unless later source evidence proves otherwise. The binary returns either the copied `score` dword or the growth helper return, but no observed caller consumes it. Treating that artifact as a source return would lower source quality.

## Target Documentation Recommendation

Recommended metadata replacement for [UID:0002K9]:

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BL
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BL
```

Recommended purpose/status replacement text:

```markdown
## Purpose

Source-authored `RankingCategoryRecord::AppendUserEntry` method. It appends one parsed
`RankingUserEntry` row to the record's user-entry vector at `+0x258/+0x25c/+0x260`.
The fast path copies one `0x4c`-byte row in place and advances the current/end pointer;
the full path dispatches to [UID:0003X1] `RankingUserEntryVectorInsertWithGrowth`.

## Status

Reconstructable as a `RankingCategoryRecord` method owned and emitted by [UID:0000BL].
The final source should express this as a vector append/push operation, not as the
compiler-emitted block-copy sequence. Final C++ may remain blank until the surrounding
`RankingUserEntry` and record-vector declarations are emitted, but the owner/emitter
route is no longer blocked.
```

Recommended behavior/evidence replacement text:

```markdown
## Behavior

- Uses record `+0x258/+0x25c/+0x260` as the `RankingUserEntry` vector
  begin/current/capacity triplet.
- If `current == capacity`, calls [UID:0003X1] at `0x0045d1b0` with the vector
  control, insertion position, and source row pointer.
- Otherwise copies one `0x4c`-byte `RankingUserEntry` from the caller's stack row:
  four 16-byte copies, one 8-byte copy, and one trailing dword copy.
- Advances `+0x25c` by `0x4c`.
- The observed binary return is the trailing copied dword/growth-helper artifact;
  the only direct caller ignores it, so the source-facing method should be modeled
  as `void AppendUserEntry(const RankingUserEntry& entry)`.

## Key Evidence

- Live IDA `lookup_funcs(0x0045c1e0)` reports
  `RankingCategoryRecord_AppendUserEntry`, size `0x59`.
- Live IDA `xrefs_to(0x0045c1e0)` reports one caller:
  [UID:0003WT] at `0x0045cd5d`.
- Live IDA `xrefs_to(0x0045d1b0)` reports the full-path call from this method at
  `0x0045c230`.
- [UID:0003WT] builds the source row as category id, rank, converted
  `wchar_t name[32]`, and score/value before calling this method.
- [UID:0001VN] resolves the row layout:
  `+0x00 categoryId`, `+0x04 rank`, `+0x08 name[32]`, `+0x48 score`.
```

## Support Documentation Recommendations

[UID:0000BL] `RankingCategoryRecord`

No metadata score change is required; keep `86/90`, `CANONICAL_OWNER:0000MZ`, `EMITTER_UIDS:0000MZ`.

Recommended method-note addition or replacement:

```markdown
- [UID:0002K9] `0x0045c1e0-0x0045c238`:
  `RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry)` appends
  one `0x4c`-byte ranking row to the record's `+0x258/+0x25c/+0x260`
  user-entry vector. The fast path copies `categoryId`, `rank`, `name[32]`, and
  `score`; the full path calls [UID:0003X1]. Model the source signature as `void`;
  the decompiler's integer return is a copied trailing-dword artifact ignored by
  the row parser.
```

[UID:0001VN] `RankingCategoryRecordLayout`

No metadata score change is required; keep `87/91`, `CANONICAL_OWNER:0000BL`, `EMITTER_UIDS:0000BL`.

Recommended layout text, if the page is refreshed:

```markdown
### Nested `RankingUserEntry` Row

| Offset | Size | Recommended field | Evidence |
|---:|---:|---|---|
| `+0x00` | 4 | `categoryId` | [UID:0003WT] stores the parsed/selected category id before append. |
| `+0x04` | 4 | `rank` | [UID:0003WT] stores the first per-row dword after name conversion. |
| `+0x08` | 64 | `wchar_t name[32]` | [UID:0003WT] writes a converted wide string and NUL-terminates within 32 WCHARs. |
| `+0x48` | 4 | `score` | [UID:0003WT] stores the second per-row dword; `score` is preferred over `value` for ranking UI semantics. |

The total row size is `0x4c`.
```

[UID:0000Y9] aggregate `RankingCategoryRecord`

The header already says `85/89`, but the coverage row remains stale at `84%`. Refresh the aggregate row and any stale layout summary to match [UID:0000BL]/[UID:0001VN]. No ownership change is required.

Recommended aggregate layout summary replacement:

```markdown
- `+0x254`: total row count for the current ranking response/page.
- `+0x258/+0x25c/+0x260`: `RankingUserEntry` vector begin/current/capacity.
- `+0x264`: loaded/current rows category id used by the parser.
- `+0x268`: local-player rank, initialized to `-1` before row parsing.
- `+0x26c-+0x2ab`: `wchar_t localPlayerName[32]`.
- `+0x2ac`: local-player score/value footer field.
```

[UID:0003WT] row parser

No metadata change is required. It should continue to call out that `0x0045cd5d` invokes [UID:0002K9] after constructing the stack `RankingUserEntry` row.

[UID:0003X1]/[UID:0003X2]/[UID:0003X3] helpers

No metadata change is required. These remain compiler/container helpers with blank final C++.

## Coverage-Report Replacement Text

Replace the [UID:0002K9] row in `by-memory/-coverage-report.md` with:

```markdown
- [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) 0x0045c1e0-0x0045c238 | method | RankingCategoryRecordAppendUserEntry : reconstructable : 86% : very strong : Source-authored `RankingCategoryRecord::AppendUserEntry` method; appends one `0x4c` `RankingUserEntry` row (`categoryId`, `rank`, `name[32]`, `score`) into the record `+0x258/+0x25c/+0x260` vector or dispatches to [UID:0003X1] growth when full. Owner/emitter [UID:0000BL]; final C++ should express a vector append once record/user-entry declarations are emitted.
```

Replace the stale [UID:0000Y9] aggregate row, if still present as `84%`, with:

```markdown
- [UID:0000Y9][RankingCategoryRecord](by-memory/RankingCategoryRecord.md) aggregate | aggregate | RankingCategoryRecord : reconstructable : 85% : very strong : Aggregate record coverage is supported by [UID:0000BL] and [UID:0001VN]; user-entry vector append [UID:0002K9] and generated vector helpers [UID:0003X1]-[UID:0003X3] are split and source-classified.
```

No new ignored row is needed for [UID:0002K9]. The EH cleanup row from the prior collection split remains separate and unrelated to this method.

## Generated Output And Final-C++ Impact

[UID:0002K9] is final-C++ eligible after the metadata raise because it is reconstructable, has a concrete emitter route through [UID:0000BL], and clears the `85/85` source-quality gate.

Recommended final-source treatment:

- Do not emit the OWORD/QWORD/DWORD copy sequence as source.
- Do not emit [UID:0003X1]/[UID:0003X2]/[UID:0003X3] as authored business logic.
- Emit this method only after the generated C++ has a defensible `RankingUserEntry` declaration and a record member representing the `+0x258/+0x25c/+0x260` vector.
- The eventual source body should be semantically equivalent to `m_userEntries.push_back(entry);`.
- Until those declarations exist, keep the target's final C++ body blank even though the metadata gate is cleared.

This is not a no-85 blocker. It is a final-output staging constraint: the method is source-classified and owned correctly, but the final C++ body depends on declarations owned by [UID:0000BL]/[UID:0001VN].

## Heuristic / Inference Reanalysis And Validation

### Method Name And Signature

Best interpretation: `RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry)`.

Validation:

- The live IDA name is already `RankingCategoryRecord_AppendUserEntry`.
- The only direct caller builds one row object and passes its address.
- The body appends exactly one `0x4c` row.
- The method operates on `RankingCategoryRecord` vector fields, not on the collection or dialog.

Rejected alternatives:

- `AddUserRank` / `AppendRankingRow`: too UI/protocol-specific and less aligned with the established `RankingUserEntry` type name.
- `PushBackUserEntry`: describes the vector operation but not the source class method name already established in IDA and docs.
- Non-void source return: the decompiler returns a copied trailing dword, but no caller consumes it. A source return would be overfitting compiler output.
- Pointer signature as the source declaration: the ABI receives an address, but source C++ would more defensibly use `const RankingUserEntry&` for a row append.

### Packet Parser And Subcommand Meaning

Best interpretation: [UID:0003WT] is the ranking rows/page response parser for opcode `0x7d`, subcommand `2`.

Validation:

- It checks the current selected category before appending rows.
- It resets the record's row vector and local-player rank state.
- It loops over variable-length name rows and appends each row through [UID:0002K9].
- It stores a total row count after the row loop.

Rejected alternatives:

- Treating this as a category-list parser: rejected because category-list construction is handled by separate collection child pages and this parser writes user-entry rows.
- Treating this as a selected-category setter: rejected because selected category is only validated; row data is the primary payload.
- Treating subcommand 2 as "local player only": rejected because local-player footer fields are optional metadata and the main loop parses a full row list.

### `RankingUserEntry` Field Names

Best row layout:

```cpp
struct RankingUserEntry {
    uint32_t categoryId;
    uint32_t rank;
    wchar_t name[32];
    uint32_t score;
};
```

Validation:

- `+0x00 categoryId`: [UID:0003WT] stores the parsed/selected category id into the row before append.
- `+0x04 rank`: [UID:0003WT] stores the first per-row dword after name parsing.
- `+0x08 name[32]`: [UID:0003WT] converts a multibyte name to wide characters, checks the 32-WCHAR bound, NUL-terminates, and copies it through the append body.
- `+0x48 score`: [UID:0003WT] stores the second per-row dword; ranking UI semantics favor `score`.

Rejected alternatives:

- `userId` for `+0x00`: no evidence of an account id; the value matches the parsed category id and duplicates the record's selected category context.
- `level` or `position` for `+0x04`: ranking parser usage and UI semantics favor `rank`.
- `value` for `+0x48`: possible at protocol level, but weaker than `score` for ranking UI output. If future UI string evidence contradicts this, `score` can be renamed without changing layout or ownership.
- Dynamic string for `+0x08`: rejected because the row copy is fixed `0x4c`, and the parser writes a bounded inline `wchar_t[32]`.

### Record Footer And `+0x26c..+0x2ab` Block

Best interpretation: `+0x26c..+0x2ab` is `wchar_t localPlayerName[32]` on `RankingCategoryRecord`, not part of `RankingUserEntry`.

Validation:

- [UID:0001VN] and [UID:0000BL] now place the user-entry vector at `+0x258/+0x25c/+0x260`.
- [UID:0003WT] uses footer metadata around `+0x264/+0x268/+0x26c/+0x2ac` separately from the per-row stack object.
- The append method never touches `+0x26c`; it only uses the vector triplet.

Rejected alternatives:

- Treating `+0x26c` as a second vector or record-owned current row: rejected because append never indexes it, and the size exactly matches a 32-WCHAR local-player name buffer.
- Folding local-player name into `RankingUserEntry`: rejected because per-row names live at row `+0x08`, while local-player metadata is stored in the record after the vector fields.

### Compiler Container Helper Boundary

Best interpretation:

- [UID:0002K9] is a source-authored record method whose optimized body includes an inline vector append fast path.
- [UID:0003X1] is generated vector insert/growth support for `RankingUserEntry`.
- [UID:0003X2]/[UID:0003X3] are generated copy/clone helpers for `0x4c` rows.

Validation:

- [UID:0002K9] has a class-method name, one caller, and a clear record method boundary.
- [UID:0003X1] reallocates/copies/frees the underlying vector buffer and is called by multiple append sites, which is compiler/container behavior.
- The final source should contain one append method and omit generated allocator/copy plumbing.

Rejected alternatives:

- Classifying [UID:0002K9] as a pure compiler helper: rejected because it is the named class method called by the parser and has domain-level source meaning.
- Creating children for the fast path copy operations: rejected because the copy sequence is one compiled basic block inside the append method.
- Emitting all helper pages to C++: rejected because it would leak MSVC container internals into authored source.

### Owner, Source File, And Type Placement

Best placement:

- Canonical owner: [UID:0000BL] `RankingCategoryRecord`.
- File emitter path: through [UID:0000BL] to [UID:0000MZ] `RankingDialog.cpp`.
- Support layout/type: [UID:0001VN] for record and nested `RankingUserEntry` layout.

Rejected alternatives:

- Direct [UID:0000MZ] ownership: too broad; it is the source file route, not the narrow class owner.
- [UID:0000BK] ownership: rejected because [UID:0000BK] owns the collection and parsers, while this method mutates one record.
- Separate top-level `RankingUserEntry` page as a blocker: useful later if type docs are split, but [UID:0001VN] already supports the row layout well enough to raise [UID:0002K9].

### Final Score Decision

Raise [UID:0002K9] to `86/90`.

The evidence clears the prior blocker:

- exact method boundary confirmed;
- exact caller and callee confirmed;
- source owner/emitter route confirmed;
- row size and row fields supported by [UID:0001VN];
- source-authored method vs generated helper boundary is now defensible.

Do not cap below 85. The only remaining ambiguity is source spelling (`score` vs `value`) and the exact final C++ member name. Those are not enough to block the source-quality gate because offsets, call shape, ownership, and semantics are resolved.

## Supervisor Actions

1. Update [UID:0002K9] metadata to `86/90`, owner/emitter [UID:0000BL], reconstructable TRUE.
2. Apply the target body text above, especially the source signature and binary-return note.
3. Leave [UID:0000BL] at `86/90`; add or refresh the method-note text for [UID:0002K9].
4. Leave [UID:0001VN] at `87/91`; keep the nested `RankingUserEntry` row layout text, using `score` as the preferred field name and noting `value` only as a weaker alternative if desired.
5. Refresh stale [UID:0000Y9] aggregate coverage text from `84%` to `85%` if it still lags its header.
6. Replace the [UID:0002K9] coverage row with the exact text above.
7. Do not create new child pages or ignored rows for this target.
8. Keep [UID:0003X1]/[UID:0003X2]/[UID:0003X3] final C++ blank as generated helper support.

## Validator Commands

Recommended documentation checks after supervisor execution:

> Executable block R001 was removed from this report and preserved verbatim in [0002K9-ranking-user-entry-append-source-quality-removed.md](0002K9-ranking-user-entry-append-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended IDA validation calls:

```text
idb_list
lookup_funcs: 0x0045c1e0, 0x0045cb10, 0x0045d1b0
analyze_function: 0x0045c1e0
xrefs_to: 0x0045c1e0
xrefs_to: 0x0045d1b0
decompile: 0x0045c1e0
decompile: 0x0045cb10
```

Expected validation result:

- `0x0045c1e0` is `RankingCategoryRecord_AppendUserEntry`, size `0x59`.
- Caller list contains `0x0045cd5d` in [UID:0003WT].
- Full-path callee is [UID:0003X1] at `0x0045d1b0`.
- Fast-path copy remains exactly `0x4c` bytes and advances `+0x25c` by `0x4c`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002K9-ranking-user-entry-append-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002K9"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002K9-ranking-user-entry-append-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002K9-ranking-user-entry-append-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002K9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
