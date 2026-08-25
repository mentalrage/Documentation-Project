** TARGET-REPORT-UID:0002UP **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002UP DeserializePredefinedFormArticleEntries Source-Quality Research


## Finalized Report / Current Recommendation

- Current implemented recommendation: keep [UID:0002UP] `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md` as a reconstructable source-authored file-local parser helper owned/emitted through [UID:0000LT] `NewPredefinedFormArticleDialog`.
- Final implemented disposition: range, parser role, constructor-only reachability, field layout, `empty` handling, row-height output, owner/emitter route, and formal first-draft C++ are incorporated in the target/support docs. The target and parser by-item support page are now `90/92`; owner/emitter/reconstructable metadata stayed [UID:0000LT] / `TRUE` / [UID:0000LT].
- Current artifact state: the accepted first-draft `PredefinedFormArticleEntry` declaration and `DeserializePredefinedFormArticleEntries` body are present in the target formal `RECONSTRUCTION_CPP CODE` block. Support docs now record MCP session `b010_00032w_20260703`, source-facing field names, explicit reserved fields, `g_emptyWideString` as the source alias for raw `word_60DB20`, skipped title delimiter handling, dword `rowAdvanceMode`, no extra callers, no named IDA `Predefined*` type, and unchanged file-local source placement.
- Remaining recommendation: no further by-* implementation is required for UID0002UP from this report. Supervisor may proceed with Gate 1 recheck and, after independent Gate 2 verification as needed, execute the report through the normal supervisor-owned lifecycle. Exact original struct/member spellings remain inferred confidence caps, not blockers to the current first-draft C++.

## Supporting Research

Historical report-only context: UID0002UP began as a new report-only assignment, and the initial report-only pass did not edit by-* docs, generated files, coverage reports, validator state, IDA DB state, report lifecycle state, archives, or supervisor ledgers.

Current post-callback artifact state: the accepted implementation callback has been applied. The target and approved support by-* docs were edited, the report ledger/checklist was updated, and scoped validators were run with `--apply`. Validator-derived updates touched `project-level/-auto-completion-stats.md`. No generated report, coverage-report, validator-state file, IDA DB state, supervisor ledger, lifecycle/archive state, manual report move, or `execute_report` command was edited/run by B014.

The assignment required mandatory IDA MCP evidence. Current usable MCP session is `b010_00032w_20260703`; all MCP facts below come from that session on 2026-07-03 unless explicitly labeled as existing documentation or old-report lead evidence. MCP was available after the supervisor override, so this is not a fallback-only report.

## Target

- Target UID: `0002UP`
- Target path: `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
- Historical source queue/report row at assignment time: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable row, score `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: post-callback implemented B-agent source-quality report awaiting repaired Gate 1 recheck. The report has not been executed or archived.
- Current scores and parent state after implementation callback: target `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000LT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LT`, blank emitter position, formal C++ inserted. Parser by-item [UID:0000UE] is also `90/92`, owner/emitter unchanged.

## Current Target State

- Current target metadata: `90/92`, owner/emitter [UID:0000LT], reconstructable true, blank emitter position, formal first-draft C++ present in the target block.
- Current owner/emitter/reconstructable state: unchanged file-local parser helper under [UID:0000LT] `NewPredefinedFormArticleDialog`, with aggregate [UID:0000ZL] and class [UID:000098] as related support. The parser remains a static/file-local helper, not a [UID:000098] class method.
- Current C++/emitter state: the target formal C++ block now contains the inferred source-shaped `PredefinedFormArticleEntry` declaration and `DeserializePredefinedFormArticleEntries` body. The declaration documents the exact `0x40c` layout, explicit reserved alignment fields, `g_emptyWideString` alias for raw `word_60DB20`, skipped title delimiter behavior, and dword `rowAdvanceMode` rationale.
- Current support state: by-item [UID:0000UE] mirrors the parser signature, layout, MCP evidence, implementation notes, and `90/92` score. Constructor [UID:0002UJ] records both rechecked parser call sites and preserves its own blank-C++ caveat. Class/file/aggregate pages mark UID0002UP source-ready at `90/92` and no longer treat parser declaration uncertainty as a blank-C++ blocker; unrelated constructor dynamic-control, alert/helper visibility, and retained `0x00478aa0` caveats remain.
- Current open questions, blockers, placeholder names, stale assumptions, or contradictory claims: older terminal-byte wording `0x00478932` is historical shorthand only; current half-open range is `0x00478650-0x00478933`. No named IDA `Predefined*` type exists, and exact original struct/member spellings remain inferred confidence caps. These do not block the current first-draft formal C++.
- Related target/support docs checked and updated during callback: target by-memory page, by-item parser page [UID:0000UE], constructor [UID:0002UJ], class [UID:000098], file [UID:0000LT], and aggregate [UID:0000ZL]. Submit [UID:0002UL], paint [UID:0002UO], executed B014 submit report for [UID:0002UL], and generated research tracker row were checked as evidence/leads but not edited.
- Current artifact/lifecycle status: this report remains in `tools/leaser/Agents/Agent-B014/research/` for supervisor Gate 1 recheck after report-text repair. It has not been executed, archived, or moved.

## Executive Recommendation

Keep `DeserializePredefinedFormArticleEntries` as a file-local/static parser helper in `NewPredefinedFormArticleDialog.cpp`, emitted through [UID:0000LT]. Do not reparent to [UID:000098]: the parser is a constructor-only free/file-local helper rather than a `thiscall` method, and both call sites pass explicit buffers/out pointers rather than `this`.

The target score has been raised to `90/92` and formal first-draft C++ has been inserted. The current MCP recheck closes the stale "needs recheck" blocker, supports source-facing names for fields, and supplies enough structure for a source-shaped parser body. The missing recovered IDA `Predefined*` type and exact original private member spellings are score caps only. They are not a reason to leave C++ blank when the stride, fields, callers, and consumers are strong.

## Supervisor Active Recheck

- Supervisor instruction: continue UID0002UP only, use existing MCP session `b010_00032w_20260703`, do not call `idb_open`, `idb_close`, process lifecycle commands, archive/lifecycle commands, generated-file edits, coverage-report edits, or `execute_report`.
- Split repair required before final report: no. The exact half-open parser range and neighbor padding are confirmed.
- Source-bearing children in scope: no new child split is required. Related exact children already exist for constructor, paint, submit, transfer reply, and aggregate pages.

## Inference Research Guidance Check

The evidence discipline used direct IDA facts first: lookup, xrefs, decompile/analyze, paged disassembly, byte reads, type queries, and bounded xref queries. Existing by-* docs and old executed B014 submit report were used as leads and cross-checks, not as authority.

Stale Wave2/Wave3/generated-source assumptions were not treated as proof. Current by-* docs mention generated constructor placeholders and recovered parser source caveats; this report keeps those as data issues rather than relying on generated code. The live type catalog has no `Predefined*` type, so any struct declaration is reconstructed, not recovered.

## Heuristic / Inference Reanalysis And Validation

- Parser range: confirmed unchanged. `lookup_funcs` reports `sub_478650`, size `0x2e3`; adjacent `0x0047864c` and `0x00478933` are not functions; bytes show `0xcc` padding before and after.
- Call sites: confirmed exactly two xrefs, both inside constructor `sub_4777A0` at `0x00477848` and `0x00477d0c`. This supports file-local parser ownership and rejects shared parser/module ownership.
- Calling convention/source shape: IDA decompiles `int __stdcall(int, int, _WORD *, _WORD *)`; constructor pushes serialized payload, `this+0x278`, `this+0x276`, and `this+0x274`. This is not a class method with implicit `this`.
- Entry layout: confirmed `0x40c` stride with fields at `+0x00`, `+0x02`, `+0x202`, `+0x203`, `+0x204`, `+0x206`, and `+0x408`.
- Source-facing field names: `titleLength`, `title`, `usesUserImagePane`, `textLineCount`, `bodyLength`, `body`, and `rowAdvanceMode` are the best current names. `rowAdvanceMode` is better than old "extra-row-advance flag" because submit [UID:0002UL] consumes values `0` and `1` as space/carriage-return separators; parser still stores only `v17 == 1`, so values beyond `1` are not produced by this parser.
- Visible-row output: parser computes `visibleRowCount` from `rowAdvanceMode` plus `16 * textLineCount / 21 + 1` when `usesUserImagePane` is false. Constructor and paint consume `this+0x276` as visible row count, not total entry count.
- `empty` behavior: parser compares converted body text to literal `aEmpty` at `0x006149ec`; when equal, it stores body length zero and copies shared empty wide string `word_60DB20`.
- Helper names: `sub_516220` is safely describable as a bounded byte copy/memmove-style helper for local narrow buffers; `sub_516030` remains a compiler/runtime helper setup in this context. Do not force original names into the parser page.
- Formal C++: accepted for first-draft source. The report supplies an inferred `PredefinedFormArticleEntry` declaration and exact formal parser body using source-quality names. The declaration should be incorporated with the target/source route and referenced by constructor/submit docs so the parser does not rely on raw offsets.

## Evidence Standards Used

Evidence types used: IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `decompile`, paged `disasm`, `get_bytes`, `int_convert`, `type_query`, `search_structs`, `xref_query`; current by-* docs; generated tracker rows as read-only queue state; matching executed B-report search results as leads; negative type/query evidence.

The evidence is strong enough for range, ownership, field layout, and score movement because the parser body, callers, constants, xrefs, and neighbors were all rechecked in the current session. It is not strong enough for final parser C++ because no named IDA struct/type exists and constructor-level dynamic control/source declarations remain unresolved.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize` and `tools/list` against `http://127.0.0.1:13337/mcp` to confirm schema-current MCP.
  - `idb_list` returned session `b010_00032w_20260703`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker, `is_analyzing:false`.
  - `server_health` command id `4`: status ok, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
  - `lookup_funcs` command id `5` for `0x00478650`, neighbors, constructor, and submit.
  - `xrefs_to` command id `6` and `xref_query` command id `21` for `0x00478650`.
  - `analyze_function` command id `7` and `decompile` command id `8` for `0x00478650`.
  - `disasm` command ids `9` and `10`, paged 0/160 instructions.
  - `get_bytes` command id `17` for `0x00478640` and `0x00478920`.
  - `disasm` command ids `13` and `14` for constructor call-context pages.
  - `int_convert` command id `15` for numeric facts.
  - `type_query` command id `19` and `search_structs` command id `20` for `Predefined*` types.
  - `xref_query` command id `21` for `aEmpty` and `word_60DB20` references.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
  - `by-item/DeserializePredefinedFormArticleEntries_478650.md`
  - `by-file/NewPredefinedFormArticleDialog.md`
  - `by-class/NewPredefinedFormArticleDialog.md`
  - `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`
  - `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`
  - `by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md`
  - `executed-b-agent-research/B014/0002UL-NewPredefinedFormArticleDialogSubmitArticle-source-quality.md`
  - `auto-generated/-ag-research-tracker.md`
- Negative checks performed: no `Predefined*` IDA type/struct; no extra parser xrefs; no function at `0x0047864c` or `0x00478933`; search in constructor listing for textual `call sub_478650` returned zero because rendered call operands are address/ref formatted, but direct xref/disasm evidence proves the call sites.
- Failed, unavailable, or intentionally skipped checks and why: no fallback-only research was used. The first `get_bytes` attempt used obsolete `start`/`size` arguments and returned a schema error; the call was retried with current `regions` schema and succeeded. No `idb_open`, lifecycle, validator, or archive command was run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Target range remains `0x00478650-0x00478933`, size `0x2e3`, terminal `retn 10h` at `0x00478930`. | confirmed | MCP `lookup_funcs` id 5, `disasm` ids 9/10, `get_bytes` id 17 | Target Address Range/Evidence; by-item Xref Evidence; aggregate IDA MCP Evidence | incorporated | applied; target/by-item/aggregate cite current MCP range, size, terminal return, and boundary padding |
| C2 | Parser has exactly two constructor-only code xrefs at `0x00477848` and `0x00477d0c`. | confirmed | MCP `xrefs_to` id 6, `xref_query` id 21 | Target Evidence/Ownership; by-item Xref Evidence; constructor Layout/Evidence; file/aggregate boundary notes | incorporated | applied; all support pages preserve constructor-only source route and no extra callers |
| C3 | Entry record stride is `0x40c` with title/body/flag fields at `+0x00/+0x02/+0x202/+0x203/+0x204/+0x206/+0x408`. | confirmed | MCP `analyze_function` id 7, `decompile` id 8, `disasm` ids 9/10 | Target Parsed Entry Layout/Source-Facing Parser Shape; by-item layout table; class/file/aggregate parser rows | incorporated | applied; formal declaration includes explicit reserved fields for alignment |
| C4 | `empty` body marker maps to zero body length and shared empty wide string `word_60DB20`. | confirmed | MCP `decompile` id 8, `disasm` id 9, `xref_query` id 21 | Target Behavior/Evidence; by-item layout notes; file/class/aggregate parser rows | incorporated | applied; docs use `g_emptyWideString` as source alias for raw `word_60DB20` |
| C5 | Best current field names are descriptive source-facing names, not recovered original declarations. | strong inference | Parser MCP field writes plus submit/constructor support docs | Target Source-Facing Parser Shape; by-item layout; class/file/aggregate parser support | incorporated | applied; unresolved exact original spelling is documented only as a confidence cap |
| C6 | Formal first-draft parser C++ should be inserted using the inferred source-shaped declaration/body from this report. | strong | MCP field writes, constructor call signature, submit consumers, and current source-quality rules | Target C++ block and Score Rationale; by-item formal readiness; class/file/aggregate source-ready parser rows | incorporated | applied; exact formal C++ block inserted into target |
| C7 | Recommended score is `90/92`, owner/emitter unchanged. | strong | Current MCP closes stale evidence gap and C++ is now source-shaped; exact original spellings remain confidence caps | Target metadata; by-item metadata; support score/blocker rationale | incorporated | applied; target and by-item are `90/92`, owner/emitter unchanged |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: current MCP confirms the function range, size, two constructor-only xrefs, exact parser loop, field offsets, `empty` literal, row count outputs, callee set, and boundary padding.
- Corroborating documentation/generated-report evidence: current by-memory/by-item docs already document the same parser role; constructor/submit/paint support pages independently consume `this+0x274`, `this+0x276`, and `this+0x278` consistently.
- Strongest inference chain: two constructor calls plus explicit serialized-buffer/output-pointer calling convention plus NewPredefined-only consumers make [UID:0000LT] the best source route. The same facts are strong enough to infer a first-draft `PredefinedFormArticleEntry` declaration and parser body without decompiler-shaped pointer arithmetic.

## IDA MCP Facts

- Function/range facts: `lookup_funcs` id 5 reports `sub_478650` at `0x478650`, size `0x2e3` / 739 (Verified with `int_convert` id 15). `0x0047864c` and `0x00478933` are not functions.
- Data/table/padding facts: `get_bytes` id 17 shows four `0xcc` bytes at `0x0047864c-0x00478650` before the parser prologue and `0xcc` padding after `0x00478933` before `sub_478940`.
- Xref facts: `xrefs_to` id 6 and `xref_query` id 21 report only `0x477848` and `0x477d0c`, both in `sub_4777A0`.
- Vtable/global/type facts: `type_query` id 19 and `search_structs` id 20 return no `Predefined*` type or struct. Constructor disassembly id 13 confirms NewPredefined vtable stores and parser argument pushes.
- Negative IDA facts: no named struct is available for `PredefinedFormArticleEntry`; no extra callers or data xrefs to the parser were found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00478650-0x00478933` | [UID:0002UP] `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md` | file-local parser helper | true | [UID:0000LT] | current `90/92` | owner/emitter unchanged; formal first-draft C++ inserted |
| `0x004777a0-0x004781e5` | [UID:0002UJ] constructor | constructor/caller of parser | true | [UID:000098] | `86/88` | support sync applied; constructor blank-C++ caveats preserved |
| `0x00478be0-0x00478f8e` | [UID:0002UL] submit | consumer of parsed record fields | true | [UID:000098] | `90/91` | already source-ready, lead for field names |
| `0x004777a0-0x00478f8e` | [UID:0000ZL] aggregate | dialog cluster | true | [UID:0000LT] | `85/90` | support sync applied; parser declaration uncertainty removed from aggregate blocker list |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00477848` | constructor calls `sub_478650` after pushing serialized packet, `this+0x278`, `this+0x276`, `this+0x274` | current-layout parser path |
| `0x00477d0c` | second constructor call to `sub_478650` in alternate layout branch | legacy/other layout parser path |
| `0x00478650` | no other xrefs | rejects shared/global parser ownership |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target and by-item pages already document `0x40c` stride, field offsets, `empty` handling, and owner/emitter [UID:0000LT]. Constructor page documents parser calls and dynamic control setup. Submit page records field consumption and source-facing names such as `m_predefinedFormEntries`, `usesUserImagePane`, and `rowAdvanceMode`.
- Existing docs that are stale, incomplete, or contradicted: older terminal-byte `0x00478932` wording is historical only; current half-open range is correct. The target's statement that helper/member names block C++ is now stale under current rules and should be replaced by inferred source-quality names plus formal first-draft C++.
- Generated/coverage report state: generated tracker still lists UID0002UP as report count `0`, which this report will resolve only after supervisor lifecycle execution. No generated report was edited.

## Ranked Ownership Analysis

### 1. [UID:0000LT] NewPredefinedFormArticleDialog file-local helper

- Evidence for: exactly two call sites, both in `NewPredefinedFormArticleDialog` constructor; parser fills records stored at `this+0x278` and outputs counts at `this+0x274`/`this+0x276`; class/file/aggregate docs all route this form-article cluster through `NewPredefinedFormArticleDialog.cpp`.
- Evidence against: direct class [UID:000098] owns most method bodies, and submit now uses the entry type name through class fields.
- Decision: best current owner/emitter remains [UID:0000LT], because the parser is a static/file-local helper with explicit output buffers, not a `thiscall` member.

### 2. [UID:000098] NewPredefinedFormArticleDialog class method

- Evidence for: all live callers and consumers are class methods; entry records are class storage.
- Evidence against: parser signature is `__stdcall`-style explicit pointers, no implicit `this`; no vtable/data route; constructor passes output buffers explicitly; current docs already reserve class emission for exact member bodies.
- Decision: reject as canonical owner/emitter for this parser in the current implemented docs.

### 3. Shared serializer/text/parser utility module

- Evidence for: parser uses generic byte-copy and multibyte-to-wide helpers.
- Evidence against: no callers outside constructor; serialized layout is specific to predefined-form article rows and dynamic UI controls.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none. Keep existing `ui/dialogs/NewPredefinedFormArticleDialog.cpp` route.
- Likely full contents: constructor, file-local parser helper, class methods, and predefined transfer-reply helpers already documented on related pages.
- Candidate related items that belong: [UID:0002UJ], [UID:0002UP], [UID:0002UK], [UID:0002UL], [UID:0002UM], [UID:0002UO], and related retained helpers as currently documented.
- Candidate related items rejected: packet/text/global helpers such as `sub_516220`, `MultiByteToWideChar`, `TextEditControlPane`, and packet sender helpers are dependencies, not ownership roots.
- Standalone, narrow, or broad source-file inference: narrow dedicated dialog source file remains best.

## Source Placement

- Recommended source file/class/global/module placement: static/file-local helper in `ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
- Why this placement fits source-tree and subsystem context: only NewPredefined constructor calls it; it parses server-provided form definition bytes into dialog-owned records; submit and paint consume the same records/counts.
- Rejected placements and why: class method rejected due explicit non-thiscall pointer signature; shared parser module rejected due no external callers; packet/text helper owners rejected as dependencies.
- Remaining placement uncertainty, if any: exact original file might have been a compact `ArticleDialogs.cpp`, but current file root [UID:0000LT] remains the documented source route.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: half-open `0x00478650-0x00478933`, size `0x2e3`; prologue begins after four `0xcc` bytes; terminal `retn 10h` at `0x00478930`; successor padding runs to `0x00478940`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: predecessor/successor are alignment bytes, not source-authored parser code.
- Parent/container impact: aggregate [UID:0000ZL] remains correct; no split or merge.

## Negative Evidence Summary

- No IDA type or struct named `Predefined*` exists in current session.
- No parser callers outside constructor were found.
- `word_60DB20` has many consumers and is a shared empty wide string; it is not parser-owned even though parser uses it for the `empty` special case.
- Consumer docs for submit support field names but do not prove recovered original field spellings.
- The constructor still lacks formal C++ because dynamic control helper/member names are provisional; that prevents parser C++ from standing alone as final source.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: documented in the report and by-* docs, but not applied as IDA DB edits.
  - Function: `DeserializePredefinedFormArticleEntries`
  - Parameters: `serializedForm`, `entries`, `outVisibleRowCount`, `outEntryCount`
  - Type concept: `PredefinedFormArticleEntry`
  - Fields: `titleLength`, `title`, `usesUserImagePane`, `textLineCount`, `bodyLength`, `body`, `rowAdvanceMode`
- Evidence for each proposed name/type/comment: field writes from MCP decompile/disasm; constructor and submit consumers; existing docs.
- Items intentionally left unchanged and why: IDA DB names/types/comments remain untouched because the callback authorized documentation/report repair only, not IDA edits.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested and not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has an emitter route through [UID:0000LT], has exact boundaries/callers/fields, and the missing exact original names can be handled with best source-quality inference.
- Implemented code state: the formal target block below has been inserted into [UID:0002UP]. The `PredefinedFormArticleEntry` declaration is part of the accepted formal source shape and is incorporated with the target/class/file support docs so constructor and submit pages share the same layout vocabulary.
- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the body follows the current MCP decompilation/disassembly: reads first title length from `serializedForm[1]`, copies title/body narrow byte runs into 256-byte local buffers, converts with `MultiByteToWideChar(CP_ACP, 0, ..., 256)`, maps body text `L"empty"` to `g_emptyWideString`/`word_60DB20`, writes the exact record fields, computes visible rows with the same extra-row and `16 * textLineCount / 21 + 1` arithmetic, writes `outEntryCount` and `outVisibleRowCount`, and returns visible rows.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: this is a narrow file-local helper beside the dialog constructor, uses simple POD row storage, ordinary Win32 conversion APIs, fixed-size buffers, and source-facing field names tied to constructor/submit consumers rather than raw offsets.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `serializedForm`, `entries`, `outVisibleRowCount`, `outEntryCount`, `PredefinedFormArticleEntry`, `titleLength`, `title`, `usesUserImagePane`, `textLineCount`, `bodyLength`, `body`, and `rowAdvanceMode`.
- Naming/coding style convention used and evidence for consistency: `PredefinedFormArticleEntry`, `m_predefinedFormEntries`, `m_predefinedFormEntryCount`, and `m_visibleFormRowCount` match current NewPredefined constructor/submit docs and read as plausible mid-2000s C++ member/helper names.
- Reason code should remain blank, if applicable: not applicable. Exact original spellings remain caveats, but they are no longer blank-C++ blockers.
- Exact no-code proof, if not eligible: not applicable.

Implemented formal insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PredefinedFormArticleEntry
{
    unsigned char titleLength;
    wchar_t title[256];
    bool usesUserImagePane;
    unsigned char textLineCount;
    unsigned char bodyLength;
    unsigned char reservedAfterBodyLength;
    wchar_t body[256];
    unsigned short reservedBeforeRowAdvanceMode;
    int rowAdvanceMode;
};

static int DeserializePredefinedFormArticleEntries(
    const unsigned char *serializedForm,
    PredefinedFormArticleEntry *entries,
    unsigned short *outVisibleRowCount,
    unsigned short *outEntryCount)
{
    char narrowText[256] = {};
    wchar_t convertedBody[256] = {};

    unsigned char entryCount = 0;
    unsigned char visibleRowCount = 0;

    unsigned char titleByteLength = serializedForm[1];
    int cursor = 2;

    while (titleByteLength != 0)
    {
        PredefinedFormArticleEntry& entry = entries[entryCount];

        memmove(narrowText, serializedForm + cursor, titleByteLength);
        narrowText[titleByteLength] = '\0';

        const unsigned char titleLength =
            static_cast<unsigned char>(
                MultiByteToWideChar(
                    CP_ACP,
                    0,
                    narrowText,
                    titleByteLength,
                    entry.title,
                    256));
        entry.titleLength = titleLength;
        entry.title[titleLength] = L'\0';

        cursor += titleByteLength + 1;

        entry.usesUserImagePane = serializedForm[cursor++] == 1;
        entry.textLineCount = serializedForm[cursor++];

        const unsigned char bodyByteLength = serializedForm[cursor++];
        memmove(narrowText, serializedForm + cursor, bodyByteLength);
        narrowText[bodyByteLength] = '\0';
        cursor += bodyByteLength;

        const unsigned char convertedBodyLength =
            static_cast<unsigned char>(
                MultiByteToWideChar(
                    CP_ACP,
                    0,
                    narrowText,
                    bodyByteLength,
                    convertedBody,
                    256));
        convertedBody[convertedBodyLength] = L'\0';

        const bool bodyIsEmptyMarker = wcscmp(convertedBody, L"empty") == 0;
        entry.bodyLength = bodyIsEmptyMarker ? 0 : convertedBodyLength;
        wcscpy_s(entry.body, 256, bodyIsEmptyMarker ? g_emptyWideString : convertedBody);

        entry.rowAdvanceMode = serializedForm[cursor++] == 1 ? 1 : 0;

        unsigned char rowBase = visibleRowCount;
        if (entry.rowAdvanceMode == 1)
        {
            rowBase = ++visibleRowCount;
        }

        if (!entry.usesUserImagePane)
        {
            visibleRowCount =
                static_cast<unsigned char>(
                    rowBase + (16 * entry.textLineCount) / 21 + 1);
        }

        ++entryCount;
        titleByteLength = serializedForm[cursor++];
    }

    *outEntryCount = entryCount;
    *outVisibleRowCount = visibleRowCount;
    return visibleRowCount;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation notes for the formal block:

- The struct is intentionally source-shaped rather than IDA-shaped. The field layout matches the binary: `titleLength` at `+0x00`, compiler padding before `title` at `+0x02`, `usesUserImagePane` at `+0x202`, `textLineCount` at `+0x203`, `bodyLength` at `+0x204`, `body` at `+0x206`, and `rowAdvanceMode` at `+0x408`, for total stride `0x40c`.
- `reservedAfterBodyLength` and `reservedBeforeRowAdvanceMode` document alignment bytes implied by the exact offsets. They should stay explicit until the final project declaration proves a cleaner packing form.
- `g_emptyWideString` is the source-facing alias for raw `word_60DB20`. If the project has an established empty-string global name at implementation time, use that name while preserving the raw evidence in the docs.
- The `cursor += titleByteLength + 1` step preserves the binary's skipped byte after the title byte run before reading `usesUserImagePane`.
- `rowAdvanceMode` is an `int` because submit [UID:0002UL] consumes the same field as a dword at record-local `+0x408`, even though this parser currently stores only `0` or `1`.

## Final Recommendation

- Exact changes applied or recommended: accepted target/support by-* updates have been applied. Target docs now include current MCP evidence, source-facing names, formal first-draft parser C++, score `90/92`, and unchanged owner/emitter [UID:0000LT]. By-item support is also `90/92`; constructor/class/file/aggregate support pages record source-ready parser status and preserve unrelated caveats.
- Exact parent assignments applied or recommended: kept `CANONICAL_OWNER:0000LT`, `EMITTER_UIDS:0000LT`.
- Exact items left no-owner/non-emitting and why: none.
- Exact future work, if any, outside this assignment scope: later constructor/class-layout work may refine exact original spellings and collapse explicit reserved fields if a better declaration is proven. It should not block this parser first-draft C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
- Implementation state: accepted changes incorporated.
- Exact report facts incorporated:
  - Current MCP session `b010_00032w_20260703` confirms `sub_478650`, size `0x2e3` / 739 (Verified with `int_convert`), exact two constructor xrefs, 201 instructions, 15 blocks, complexity 9, `0x40c` stride, field writes, `empty` behavior, and boundary padding.
  - Source-facing parser signature: `static int DeserializePredefinedFormArticleEntries(const unsigned char *serializedForm, PredefinedFormArticleEntry *entries, unsigned short *outVisibleRowCount, unsigned short *outEntryCount)`.
  - Field names: `titleLength`, `title`, `usesUserImagePane`, `textLineCount`, `bodyLength`, `body`, `rowAdvanceMode`.
  - Formal first-draft C++ from this report is inserted in the target formal block, including the `PredefinedFormArticleEntry` declaration and parser body.
  - Add the implementation notes explaining the `0x40c` layout, reserved alignment fields, `g_emptyWideString` alias for `word_60DB20`, skipped title delimiter byte, and `rowAdvanceMode` dword rationale.
- Metadata/score/owner/emitter/reconstructable/C++ changes: `COMPLETION:85 -> 90`; `CONFIDENCE:89 -> 92`; kept `CANONICAL_OWNER:0000LT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LT`, and blank emitter position.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve terminal-byte `0x00478932` as historical shorthand only; preserve no extra callers; preserve no named IDA type; reject class-method reparenting.

## Recommended Support Doc Changes

- Support path: `by-item/DeserializePredefinedFormArticleEntries_478650.md`
- Exact report facts incorporated: mirrors the target's current MCP evidence, source-facing parser signature, `PredefinedFormArticleEntry` field layout, formal C++ readiness, and implementation notes.
- Metadata/link/score/coverage/source-placement changes: by-item `86/89 -> 90/92`, owner/emitter kept [UID:0000LT].

- Support path: `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`
- Exact report facts incorporated: added a narrow support note that UID0002UP current MCP recheck reconfirms both parser call sites and that parser formal C++ is now source-ready through the inferred `PredefinedFormArticleEntry` declaration. Preserved this constructor's own blank-C++ caveat for dynamic UI/control helper names.
- Metadata/link/score/coverage/source-placement changes: no score or metadata change required.

- Support path: `by-class/NewPredefinedFormArticleDialog.md`, `by-file/NewPredefinedFormArticleDialog.md`, and `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
- Exact report facts incorporated: updated the parser method/helper rows and score rationale so [UID:0002UP] is source-ready at `90/92` with formal first-draft parser C++. Removed parser declaration uncertainty from class/file/aggregate blank-C++ blocker lists; kept unrelated constructor dynamic-control, alert/helper visibility, and retained `0x00478aa0` policy caveats.
- Metadata/link/score/coverage/source-placement changes: no score or metadata change required.

## Score And Metadata Recommendation

- Current score/metadata: target `90/92`, owner/emitter [UID:0000LT], reconstructable true, blank emitter position, formal first-draft C++ inserted. By-item [UID:0000UE] is also `90/92`, owner/emitter unchanged.
- Implemented score/metadata recommendation: target `85/89 -> 90/92`; by-item `86/89 -> 90/92`; owner/emitter/reconstructable unchanged; formal first-draft C++ inserted in the target.
- Score rationale and reason not higher/lower: the move to 90+ is justified because current MCP resolves the assignment's explicit recheck list, supports source-facing names, and this report provides a source-shaped declaration/body that avoids decompiler pointer arithmetic. Do not raise above `92` confidence or toward final-audit `95+` because exact original private spellings and final surrounding class declarations remain inferred rather than recovered.
- Score-improvement attempt:
  - Parser range: checked with lookup/disasm/bytes; resolved.
  - Constructor call sites: checked with xrefs/disasm; resolved.
  - Entry stride/fields: checked with decompile/disasm/int_convert; resolved.
  - Helper/type names: checked support docs and IDA type catalog; converted to source-facing names with caveats.
  - Formal C++: checked constructor/submit support and no `Predefined*` type; resolved with inferred source-quality declaration and parser body.
- Metadata fields changed or left unchanged: changed target/by-item scores and target C++ block/body text; left owner/emitter/reconstructable metadata unchanged.

## Open Questions With Attempted Resolution

- Open question: can parser C++ now be inserted?
  - Evidence checked: current parser MCP, constructor call contexts, submit consumer C++ and executed B014 report, class/file/aggregate docs, IDA type catalog.
  - Best supported resolution: yes. Behavior, range, callers, stride, field offsets, and consumers are strong enough for first-draft source-shaped C++.
  - Remaining unresolved: exact original declaration/spelling for `PredefinedFormArticleEntry` and private field/member names. Score/C++ impact: caps confidence below final audit, but does not block first-draft formal C++.
- Open question: should owner/emitter move from file to class?
  - Evidence checked: call convention, constructor pushes, xrefs, class route.
  - Best supported resolution: no. Keep file-local helper route through [UID:0000LT].
- Open question: are field names defensible?
  - Evidence checked: parser writes and submit/constructor reads.
  - Best supported resolution: yes as descriptive source-facing names, not recovered originals.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Generated `auto-generated/-ag-*` reports and manual coverage reports were not edited. The target source page `Item Summary` remained valid, and validator-derived stats updates were limited to `project-level/-auto-completion-stats.md`. Generated tracker/report counts should update only through supervisor-owned report execution lifecycle.

## Follow-Up Actions

- Supervisor actions: Gate 1 recheck this repaired post-callback report text, then perform any required Gate 2 verification against changed docs/validator output before supervisor-owned execution lifecycle.
- A-agent actions: none required.
- B014 future research actions: none for UID0002UP unless supervisor finds another report-text or implementation mismatch. Target/support docs and scoped validators are already complete for the accepted callback.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `90/92`.
- Remaining uncertainty: exact original field/helper/type spellings and constructor/class declaration shape.

## Validator Results

- Commands run from `source-3/project-documentation` during implementation callback, all with `--apply --queue-timeout 240`:
  - `000000005602` at `2026-07-03T16:16:14-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied completion/confidence updates `90/92`, autogen registry hash/status updates, projected stats update, stats row removal/rescore recommendation; `generated_refresh: deferred`.
  - `000000005604` at `2026-07-03T16:16:20-04:00`: `python .\tools\validator.py --mode file --file by-item/DeserializePredefinedFormArticleEntries_478650.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied completion/confidence updates `90/92`, stats row update, projected stats update; `generated_refresh: deferred`.
  - `000000005606` at `2026-07-03T16:16:34-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied reference index add for UID0002UP, stats row update, projected stats update; `generated_refresh: deferred`.
  - `000000005607` at `2026-07-03T16:16:48-04:00`: `python .\tools\validator.py --mode file --file by-class/NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied two stats row updates and projected stats update; `generated_refresh: deferred`.
  - `000000005609` at `2026-07-03T16:16:57-04:00`: `python .\tools\validator.py --mode file --file by-file/NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied one stats row update and projected stats update; `generated_refresh: deferred`.
  - `000000005610` at `2026-07-03T16:17:06-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`; exit code `0`; `ok: 1`; warnings/errors: none. Applied projected stats update; stats incremental noop for UID0000ZL because the file is not present in generated stats lists; `generated_refresh: deferred`.
- Generated refresh effects: validator-applied derived stats/reference/autogen registry updates only; generated refresh was deferred for every scoped command. No execute_report, lifecycle/archive command, generated report edit, coverage-report edit, or manual report move was run.
- Any accepted claim not applied: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B014/research/0002UP-DeserializePredefinedFormArticleEntries-source-quality.md`
- Modified during implementation callback:
  - `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`
  - `by-item/DeserializePredefinedFormArticleEntries_478650.md`
  - `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`
  - `by-class/NewPredefinedFormArticleDialog.md`
  - `by-file/NewPredefinedFormArticleDialog.md`
  - `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - `project-level/-auto-completion-stats.md` (validator-derived projected/stats updates from scoped `--apply` runs)
  - `tools/leaser/Agents/Agent-B014/research/0002UP-DeserializePredefinedFormArticleEntries-source-quality.md`
- Renamed: none.
- Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: Gate 1 passed for SHA256 `BCDF5168B62A5AD16A8A6CA3853FDB8B1CE2627248A8DE43C01874075AF5F9F8`.
- [x] Target/support docs to update: `by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md`; `by-item/DeserializePredefinedFormArticleEntries_478650.md`; `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`; `by-class/NewPredefinedFormArticleDialog.md`; `by-file/NewPredefinedFormArticleDialog.md`; `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`.
- [x] Current target state and actual evidence checked recorded: current report records MCP session `b010_00032w_20260703`, command ids/evidence, current metadata, and support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger above now records incorporated/applied state row by row.
- [x] Metadata/score changes to apply: target `85/89 -> 90/92`; by-item `86/89 -> 90/92`; no owner/emitter/reconstructable changes.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: formal parser C++ blocker resolved with source-shaped inferred `PredefinedFormArticleEntry` declaration and parser body; exact original spellings remain confidence caps only.
- [x] Owner/emitter/reconstructable changes to apply: none; confirmed unchanged [UID:0000LT]/true/[UID:0000LT].
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: file-local source placement confirmed, no split, no IDA edits.
- [x] First-draft C++ or no-code proof to apply: exact formal first-draft C++ block from this report inserted into [UID:0002UP], including the `PredefinedFormArticleEntry` declaration and parser body.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: current MCP evidence, field names, formal C++ readiness, score rationale, rejected alternatives, struct layout notes, and raw evidence/caveats incorporated in scoped docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: terminal-byte wording historical, no class-method reparenting, no named IDA type, no extra callers preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated/recovered source caveats treated as leads only and not edited.
- [x] Open questions to close or document as evidence-backed unresolved: C++ eligibility closed as ready; remaining exact original declarations documented as score confidence caps, not code blockers.
- [x] Validators to run: scoped file validators passed for target, by-item support, constructor support, class support, file support, and aggregate support; command IDs `000000005602`, `000000005604`, `000000005606`, `000000005607`, `000000005609`, and `000000005610`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh was deferred by each validator; no manual coverage/tracker text or report lifecycle action was applied.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated refresh was deferred by validator, with only derived stats/reference/autogen updates applied; manual coverage/tracker edits remain out of scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000005629","destination_path":"executed-b-agent-research/B014/0002UP-DeserializePredefinedFormArticleEntries-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002UP-DeserializePredefinedFormArticleEntries-source-quality.md","timestamp":"2026-07-03T16:47:25-04:00","uid":"0002UP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
