** TARGET-REPORT-UID:0001JS **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Research Report: UID0001JS TextEditPaneInputNavigationWrapAndTextRunHelpers Source Quality


Report status: Implementation callback artifact in `tools/leaser/Agents/Agent-B005/research/`, awaiting supervisor execute. Supervisor Gate 1 passed in `tools/leaser/Agents/b-report-validation-audit.md` entry `2026-07-07T01:54:20-04:00 - B005 UID0001JS Repaired Gate 1 Passed`. Accepted target/support by-* documentation details have been applied; this report has not been executed, archived, or moved. No manual generated edits, manual coverage edits, supervisor-ledger edits, lifecycle/archive commands, manual report moves, or `execute_report` commands were run.

Report path: `tools/leaser/Agents/Agent-B005/research/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md`

Current MCP evidence session: `supervisor-nexustk-20260707`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, checked 2026-07-07T01:20-04:00 through 2026-07-07T01:28-04:00.

## Finalized Report / Current Recommendation

[UID:0001JS] `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` is a real TextEditPane source-bearing aggregate, not padding, not an empty/no-code row, and not a support-object row. It should remain attached to [UID:0000ON] `TextEditPane.cpp` with [UID:0000EO] `TextEditPane` as the covered class.

The current aggregate must not receive a monolithic first-draft C++ body. Fresh MCP evidence confirms that `0001JS` contains seven IDA-modeled functions, five raw no-function helper bodies, two adjacent compiler switch tables, and multiple alignment spans. The implementation-ready disposition is:

- Preserve the current half-open range `0x00594040-0x00594e60`.
- Keep `CANONICAL_OWNER:0000ON`, `EMITTER_UIDS:0000ON`, and `RECONSTRUCTABLE:TRUE` until exact child pages exist.
- Raise only modestly to `COMPLETION:88`, `CONFIDENCE:90` after report incorporation, because the range/source/ownership/split decision is now current-MCP backed, but final source names and raw helper signatures are not solved.
- Keep the formal `RECONSTRUCTION_CPP` block blank on `0001JS`.
- Add a target-specific no-code proof explaining that aggregate C++ is rejected because the row is split-required.
- Add an exact child split plan for the next source-quality implementation pass. If the supervisor explicitly approves child creation, split first, then consider per-child first-draft C++ only after each child has its own signature and source-name audit.

## Supporting Research

Current docs checked:

- `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`
- `by-file/TextEditPane.md`
- `by-class/TextEditPane.md`
- Neighboring callback docs: `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`, `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`, and `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md`
- Successor support-object docs: `by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md`, `by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md`, and `by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md`
- Generated state was read only: `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-memory-coverage.md`

Executed research checked:

- `executed-b-agent-research/B001/0001JP-0001JS-texteditpane-format-nav-source-quality.md`
- `executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md`
- `executed-b-agent-research/B004/0000ON-TextEditPane-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B006/0001JR-DrawTextRunCallback-source-quality.md`
- `executed-b-agent-research/B007/0001JQ-TextRunMeasureCallback-source-quality.md`

History summary: B001 repaired the stale endpoint and kept `0001JS` aggregated to avoid losing real raw code. Later B005/B004 support policy clarified that `0001JS` is still real source code but should remain split-before-body-C++ rather than receiving a broad aggregate body. This report keeps the accepted ownership/range history and upgrades the blocker analysis into an exact split/no-code plan.

## Target

Target UID: `0001JS`

Target file: `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`

Target range: `0x00594040-0x00594e60`

Current role: TextEditPane input/navigation/wrap/text-run helper aggregate containing character input, selected and forward delete, navigation dispatch, compiler switch tables, lower text-run rendering, wrapping/measurement helpers, word-boundary lookup, selection autoscroll, and raw pre-support draw/callback-state helper code.

Covered class: [UID:0000EO] `TextEditPane`

Source file / current emitter: [UID:0000ON] `TextEditPane`, proposed generated source `NexusTK/ui/controls/TextEditPane.cpp`

## Current Target State

Current target metadata:

| Field | Current value |
| --- | --- |
| UID | `0001JS` |
| COMPLETION | `88` |
| CONFIDENCE | `90` |
| CANONICAL_OWNER | `0000ON` |
| RECONSTRUCTABLE | `TRUE` |
| EMITTER_UIDS | `0000ON` |
| Formal C++ | blank |
| Nested | `-8` |

Current generated state after scoped validators:

- `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` header lists `validator-command-id: 000000007777`, `validator-refreshed-at: 2026-07-07T02:02:40-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` now lists `// UID:0001JS | by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md | Completion:88 | Confidence:90 | Empty Emitter Marker`.
- `auto-generated/-ag-memory-coverage.md` was updated by the scoped validator refresh; `0001JS` remains emitter-routed through [UID:0000ON] `TextEditPane.cpp` with direct generated route still represented by the empty marker.

Current report artifact/lifecycle status: this report remains active in `tools/leaser/Agents/Agent-B005/research/` after implementation callback. It is implemented in target/support docs, not executed, not archived, not moved, and not marked as an executed report.

Current target prose is materially useful. The repair needed is not range discovery from scratch; it is a source-quality disposition repair: replace generic "pending field names" blockers with exact current evidence, exact no-code proof, and a concrete split plan.

## Heuristic / Inference Reanalysis And Validation

The prior blocker wording was too broad for a current xHigh report. Fresh MCP evidence narrows the blockers as follows.

1. Aggregate C++ is the primary blocker, not owner uncertainty. The target combines unrelated source units: event navigation helpers, delete helpers, text-run drawing, wrap measurement, word-boundary logic, autoscroll, raw helper bodies, and switch-table data. A single by-memory C++ block would either omit live bytes or paste multiple functions and data tables into one inappropriate body.

2. The switch-table blocker is now precise. `0x00594618-0x00594658` is not one vague padding island. It is two adjacent tables in `sub_5941F0`: a 4-entry table referenced at `0x00594226` and a 12-entry action table referenced at `0x0059427f`. The action names are still inferred from behavior, not recovered source names.

3. Raw helper liveness is proven, but signatures remain below first-draft quality. `lookup_funcs` returns `Not a function` for `0x00594190`, `0x00594660`, `0x00594680`, `0x005949c0`, `0x00594a30`, and `0x00594e20`, while byte/disassembly checks show normal prologue or executable helper code and correct returns. `xrefs_to` reports no direct raw-start refs for those starts, so each raw helper needs a child signature audit before source C++.

4. TextEditPane source placement is validated. Caller, callee, field-offset, neighboring callback, and support-object boundary evidence all tie this target to `TextEditPane.cpp`. No evidence supports moving it to TextEditObject/TextEditScrap, TextFilter, TextBoxPane, ScrollBar, FittingRoom, RankingEvent, GrafPort, or a compiler-only no-code bucket.

5. Score can rise modestly because the current report resolves the stale "generic pending names" blocker into exact next steps. Score should not rise above low-90s or receive C++ because exact original event/key enum names, helper spellings, table names, and several raw signatures remain unresolved.

## Evidence Standards Used

- Live MCP evidence is required and was obtained from session `supervisor-nexustk-20260707`. `idb_list` returned one active adopted session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Current project docs were treated as durable context only when consistent with fresh MCP or executed reports.
- Generated and tracker files were read only during Gate 1 research. During implementation callback, no manual generated/coverage/validator-state edits were made; scoped validators produced their own generated refresh and validator-state side effects.
- Source-facing names are accepted only as descriptive names unless direct evidence proves original spelling. This report labels unresolved names accordingly.
- First-draft C++ is rejected for this aggregate unless exact child split and per-child signatures are accepted first.
- No fallback-only research was used. MCP was available for all required current verification facts.

## Evidence Checked

| Evidence route | Current result |
| --- | --- |
| MCP availability | `idb_list` showed session `supervisor-nexustk-20260707`, backend worker PID `14640`, `is_active:true`; `server_health` was `ok` with Hex-Rays and strings cache ready. |
| `lookup_funcs` | Functions exist at `0x00594040` size `0xd6`, `0x00594120` size `0x70`, `0x005941f0` size `0x428`, `0x005946b0` size `0x1ef`, `0x005948a0` size `0x11e`, `0x00594b50` size `0x160`, and `0x00594cb0` size `0x162`. No function object exists at raw starts `0x00594190`, `0x00594618`, `0x00594660`, `0x00594680`, `0x005949c0`, `0x00594a30`, `0x00594e20`, or successor boundary `0x00594e60`. |
| `xrefs_to` key starts | `0x00594040` has two code xrefs from `sub_58EB50` and `sub_5909F0`; `0x00594120` has three code xrefs from `sub_58EBE0` and `sub_5909F0`; `0x005941f0` has two code xrefs from `sub_594040`; `0x005946b0` has two refs from `sub_593DB0` and raw draw variant code at `0x0059402d`; `0x005948a0` has four refs including `sub_592FB0`, `sub_5936E0`, raw `0x005939e6`, and raw `0x00594ab7`; `0x00594b50` has five code refs from mouse/cursor/navigation paths; `0x00594cb0` has two code refs from `sub_590DE0`. |
| `xrefs_to` switch tables | `0x00594618` has a data xref from `0x00594226` in `sub_5941F0`; `0x00594628` has a data xref from `0x0059427f` in `sub_5941F0`; `0x00594658` has no refs and is the first padding byte after the tables. |
| `callees` | `sub_594040` calls `sub_5941F0` and `sub_58F2A0`; `sub_594120` calls `sub_593280` and `sub_591400`; `sub_5941F0` calls line/coordinate helpers `sub_58F740`, `sub_58F690`, `sub_58F0D0`, word-boundary `sub_594B50`, width helper `sub_4BAAA0`, and `std::ctype<char>::do_narrow`; `sub_5946B0` calls GrafPort/text routines including `sub_4BAB20`, `sub_4BAB70`, `sub_4B95E0`, `sub_4B9600`, and `_wcscpy_s`; `sub_5948A0` calls `StringIter` helpers at `0x00584d80`, `0x00584df0`, `0x00584e40`, and `sub_4B6020`; `sub_594CB0` calls scroll helpers `sub_55E950`, `sub_55EAE0`, and `sub_4BAAA0`. |
| `decompile 0x00594040` | Reads event bytes at `a2+8` and `a2+0x10a`, selection words `this+0x144/+0x146`, branches on event flag bit `4`, calls navigation `sub_5941F0`, and applies range/caret through `sub_58F2A0`. |
| `decompile 0x00594120` | Delete-selection/backspace behavior reads editor flag byte `this+0x15c`, selection endpoints `+0x144/+0x146`, deletes via `sub_593280`, and invalidates/updates through `sub_591400`. |
| `disasm 0x00594190` | Raw forward-delete helper tests `this+0x15c` bit `4`, uses `+0x144/+0x146`, checks text length at `m_textStorage+0x0c`, calls `sub_593280`, resets both selection words, calls `sub_591400`, and returns before 13 bytes of `0xcc` alignment. |
| `decompile/disasm 0x005941f0` | Navigation dispatcher converts event bytes through `std::ctype<char>::do_narrow`, handles key codes `0x80-0x83`, folds modifier bits from `a2+0x10a`, dispatches through 12 action cases, uses line/cursor helpers, word-boundary helper, and line table at `this+0x138`. |
| Switch bytes | `0x00594618-0x00594658` decodes to pointers `0x00594240`, `0x00594234`, `0x0059422d`, `0x0059423b`, then `0x00594286`, `0x005942a6`, `0x005942cb`, `0x00594302`, `0x00594339`, `0x00594372`, `0x005943ab`, `0x00594484`, `0x00594574`, `0x005945a0`, `0x005945e5`, `0x005945f3`. |
| `disasm 0x00594660` | Raw clamp helper returns `max(value, min)` then `min(result, max)` using three stack arguments and `retn 0x0c`. |
| `disasm 0x00594680` | Raw selection-pair normalization helper compares two pointed 16-bit values and swaps them when the second is lower; returns `retn 8`. |
| `decompile 0x005946b0` | Lower renderer sets byte `this+0x88`, uses masked-text byte `this+0x16a`, numeric/comma mode byte `this+0x173`, handles leading `<B>`/`<b>` markup, calls `_wcscpy_s`, `wcslen`, `sub_4BAB70`, `sub_4BAB20`, `sub_4B95E0`, and `sub_4B9600`. |
| `decompile 0x005948a0` | Wrap/measure helper constructs a `StringIter`, reads multiple characters, calls `sub_4B6020`, tracks remaining width through caller pointers, and destroys the iterator. |
| `disasm 0x005949c0` | Raw masked/plain width helper checks `this+0x16a`, uses UTF-16 wildcard literal `0x0062e168` (`L"*"`), calls `sub_4BA9A0`, compares start/end words, and returns with `retn 0x18`. |
| `disasm 0x00594a30` | Raw wrap segment helper scans UTF-16 CR/LF (`0x0d`/`0x0a`), calls `sub_5948A0`, trims backwards over characters `<= 0x20`, writes an output word, and returns `retn 0x18`. |
| `decompile 0x00594b50` | Word-boundary helper classifies UTF-16 whitespace against space, tab, CR, and LF, walks backward/forward across matching class, and fills two output words. |
| `decompile 0x00594cb0` | Autoscroll helper checks editor flags and mouse mode, compares pointer coordinates to viewport bounds, clamps scroll deltas to `48`, calls vertical/horizontal scroll helpers, and returns `1`. |
| `disasm 0x00594e20` | Raw pre-support helper tests `this+0x15c` bit `2`, saves/restores GrafPort-like state at `+0x70/+0x74/+0x80`, calls `sub_4B9660`, calls through `unk_69B3FC`, and returns with `retn 4`. |
| Padding and successor bytes | `0x00594116-0x00594120`, `0x005941e3-0x005941f0`, `0x00594658-0x00594660`, `0x0059467e-0x00594680`, `0x005946a4-0x005946b0`, `0x0059489f-0x005948a0`, `0x005949be-0x005949c0`, `0x00594a21-0x00594a30`, `0x00594b47-0x00594b50`, `0x00594e12-0x00594e20`, and `0x00594e5f-0x00594e60` are `0xcc` alignment bytes of the expected sizes. `0x00594e60` begins the successor `TextEditObject` constructor-shaped code. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | `0001JS` is real TextEditPane source-bearing code and not a no-code/empty row. | High | Current `lookup_funcs`, xrefs, decompile/disasm evidence, and generated empty marker show seven modeled functions, raw helper code, and local switch data in the range. | Target `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` -> `Item Summary`, `Status`, `Evidence Notes`; support `by-file/TextEditPane.md` -> `Source Emission Policy`. | applied | applied |
| C002 | Preserve the target range and filename at half-open `0x00594040-0x00594e60`. | High | Fresh bytes show `0x00594e20-0x00594e5f` raw TextEditPane helper, `0x00594e5f` one `0xcc`, and `0x00594e60` successor `TextEditObject` constructor-shaped code. | Target -> `Function And Byte Inventory`, `Boundary Notes`, `Ownership Decision`; support `by-file/TextEditPane.md` -> `Proposed Contents` and `Source Emission Policy`. | applied | applied |
| C003 | Refine `0x00594618-0x00594658` as two adjacent local switch tables for `sub_5941F0`, not padding or one vague table. | High | `xrefs_to 0x00594618` from `0x00594226`; `xrefs_to 0x00594628` from `0x0059427f`; decoded table pointers target `sub_5941F0` basic blocks; `0x00594658` has no refs and begins `0xcc` padding. | Target -> `Function And Byte Inventory`, `Evidence Notes`, `Open Questions`; support `by-class/TextEditPane.md` -> `Raw Callback And Support Boundaries` / helper table; support `by-file/TextEditPane.md` -> `Source Emission Policy`. | applied | applied |
| C004 | Keep source-facing name `TextEditPane::DrawTextRunSegment` for `0x005946b0` as inferred/descriptive lower renderer; do not emit aggregate C++. | High for behavior, medium-high for exact spelling | `xrefs_to` from [UID:0001JR] and raw draw variant; B006 evidence; current decompile shows masked text `+0x16a`, comma mode `+0x173`, `<B>/<b>` markup, `_wcscpy_s`, `wcslen`, and GrafPort text calls. | Target -> `Source-Facing Naming Direction`, `Function And Byte Inventory`, `First-Draft C++ Recommendation`; support `by-file/TextEditPane.md` -> callback/source-emission summary; support `by-class/TextEditPane.md` -> method/helper table. | applied | applied |
| C005 | Raw helper starts are live code but remain signature-weak and must be split/audited before C++. | High for liveness, medium for source signatures | `lookup_funcs` returns `Not a function` and `xrefs_to` returns zero direct start refs for raw starts, while `get_bytes`/`disasm` show executable helper bodies and returns at `0x00594190`, `0x00594660`, `0x00594680`, `0x005949c0`, `0x00594a30`, and `0x00594e20`. | Target -> `Function And Byte Inventory`, `Range / Split / Padding / Reclassification Analysis`, `Open Questions`; support `by-file/TextEditPane.md` -> `Source Emission Policy`; support `by-class/TextEditPane.md` -> `Raw Callback And Support Boundaries`. | applied | applied |
| C006 | Keep current source placement and metadata route through [UID:0000ON] `TextEditPane.cpp`; [UID:0000EO] remains covered class/declaration support. | High | Field offsets, target callers/callees, neighboring callback docs, generated route, and successor support-object boundary all point to TextEditPane; alternatives lack ownership evidence. | Target -> metadata headers, `Ownership Decision`, `Cross-References`; support `by-file/TextEditPane.md` -> `Source Placement` / `Source Emission Policy`; support `by-class/TextEditPane.md` -> `Source Placement And Rejected Owners`. | applied | applied |
| C007 | Recommend `COMPLETION:88`, `CONFIDENCE:90`, with `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000ON`, `EMITTER_UIDS:0000ON`, and blank formal C++. | Medium-high | MCP resolves exact range, two switch tables, raw helper liveness, support boundary, generated state, and no-code proof; unresolved source spellings/raw signatures cap higher score and C++ readiness. | Target -> metadata headers, `Status`, `Score Rationale`/`Changes`; support `by-file/TextEditPane.md` -> `B004 Empty-Emitter Callback Disposition` or current generated-state note; support `by-class/TextEditPane.md` -> `Current Caveats`. | applied | applied |
| C008 | Add split-required child candidate plan without creating child pages during this report or any implementation callback unless explicitly granted. | High | Target contains separate modeled functions, raw helper bodies, two switch tables, and padding; current workflow requires split-before-body-C++ for large mixed aggregates. | Target -> `Range / Split / Padding / Reclassification Analysis`, `First-Draft C++ Recommendation`; support `by-file/TextEditPane.md` -> `Source Emission Policy`; report `Implementation Tracking Checklist`. | applied | applied |
| C009 | Preserve negative evidence rejecting TextEditObject/TextEditScrap, TextFilter, TextBoxPane, ScrollBar/ScrollPane/GrafPort ownership, FittingRoom/RankingEvent generated pollution, and compiler-only/no-code treatment. | High | Current field/caller evidence ties range to TextEditPane; support objects begin at `0x00594e60`; GrafPort/scroll code are callees; generated FittingRoom/RankingEvent names are stale/polluted. | Target -> `Negative Evidence Summary`, `Ranked Ownership Analysis`, `Ownership Decision`; support `by-file/TextEditPane.md` -> `Current Caveats`; support `by-class/TextEditPane.md` -> `Source Placement And Rejected Owners`. | applied | applied |
| C010 | Neighbor callback docs [UID:0001JQ], [UID:0001JR], and [UID:0003FD] are supporting evidence only; no required edit unless implementation finds a contradiction. | Medium-high | Current docs already contain TextRunMeasure/Draw state and lower renderer context; this report uses them as corroboration and does not require changing them. | `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`, `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`, `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md` -> existing evidence sections. | already-present | already-present |

## Positive Evidence Summary

- The range has multiple direct callers from existing TextEditPane layout/key/mouse/input paths, including `sub_5909F0` and `sub_590DE0`.
- The decompiled and raw helper bodies use TextEditPane fields already documented by [UID:0000EO]: `m_textStorage +0x134`, `m_lineTable +0x138`, selection endpoints `+0x144/+0x146`, editor flags `+0x15c`, masked-text byte `+0x16a`, format/comma byte `+0x173`, text-area/viewport fields, and GrafPort draw state.
- Neighboring [UID:0001JQ] and [UID:0001JR] support the text-run iterator/draw model and already provide first-draft-ready callback context for measurement and draw callbacks. `0001JS` consumes that context through `DrawTextRunSegment` and wrap/measurement helpers.
- The successor boundary at `0x00594e60` is exact: code at `0x00594e20-0x00594e5f` still uses TextEditPane/GrafPort state, while `0x00594e60` begins `TextEditObject` constructor-shaped code with the `TextEditObject` vtable.
- Current generated `TextEditPane.cpp` shows `0001JS` as an empty emitter marker, matching documentation that this is real source-bearing work waiting on split/body quality rather than a finished no-code row.

## Negative Evidence Summary

- Not TextEditObject/TextEditScrap: support-object code begins at `0x00594e60`; the raw helper just before it uses TextEditPane fields and GrafPort callback state, not TextEditObject payload fields.
- Not TextFilter or TextBoxPane: those are neighboring source families after the support-object islands and have no ownership evidence for this range.
- Not ScrollBar/ScrollPane/GrafPort: scroll and draw helpers are dependencies, but the callers and fields are TextEditPane editor state.
- Not FittingRoom or RankingEvent: current TextEditPane docs already reject generated owner pollution around nearby callback/helper addresses; MCP route evidence ties this target to TextEditPane.
- Not compiler-only data/padding: only the listed alignment spans are `0xcc`; the functions, raw helpers, and switch tables are live code/data.
- Not safe for a broad first-draft body: the range contains separate source functions and local tables with unresolved signatures. A monolithic C++ block would misrepresent source structure.

## Ranked Ownership Analysis

| Rank | Candidate owner | Disposition |
| ---: | --- | --- |
| 1 | [UID:0000ON] `TextEditPane` by-file / `NexusTK/ui/controls/TextEditPane.cpp` | Strongest owner and current emitter. It owns the editor source module, file-local callbacks, raw helper pockets, support-object adjacency, and generated route. |
| 2 | [UID:0000EO] `TextEditPane` by-class | Covered class and declaration authority. Method/helper names belong in class support prose, but current mixed aggregate metadata should not be moved from file owner to class owner without a broader source-route change. |
| 3 | Neighboring text-run callback pages [UID:0001JQ]/[UID:0001JR]/[UID:0003FD] | Dependencies and caller/sibling evidence only. They explain measurement/draw state but do not own `0001JS`. |
| 4 | TextEditObject/TextEditScrap support object pages | Rejected for this target range; they start at `0x00594e60` after the one-byte pad. |
| 5 | GrafPort/text helper pages | Callee/source dependency for measuring and drawing text. They own primitives, not TextEditPane policy. |
| 6 | ScrollBar/TextBoxPane/TextFilter/FittingRoom/RankingEvent | Rejected. Current evidence gives no ownership path for this byte range. |

## Source Placement

Recommended source placement remains `NexusTK/ui/controls/TextEditPane.cpp`, with declarations in `NexusTK/ui/controls/TextEditPane.h` through [UID:0000EO] as currently documented.

The target combines member-style TextEditPane behavior and file-local/raw helper code. Keeping current `0000ON` file ownership is the least disruptive route and matches existing `TextRunMeasureCallback`, `DrawTextRunCallback`, support-object, and generated `TextEditPane.cpp` policy. The class page should keep helper declarations and field names, while exact method/raw helper bodies should live on exact by-memory child pages after split.

## Range / Split / Padding / Reclassification Analysis

Current range should remain `0x00594040-0x00594e60`. It is too broad for first-draft C++ and should be treated as split-required source debt. Candidate child UIDs are not assigned in this report; allocator/validator-owned UID creation should be used only if the supervisor explicitly approves a child-split implementation callback.

| Range | Classification | Current evidence | Split recommendation |
| --- | --- | --- | --- |
| `0x00594040-0x00594116` | IDA function `sub_594040`, size `0xd6` | Character/navigation input handler; xrefs from `sub_58EB50` and `sub_5909F0`; calls `sub_5941F0` and selection helper `sub_58F2A0`. | Exact child candidate `TextEditPaneHandleCharacterNavigationInput`; first-draft blocked by event struct/key flag names. |
| `0x00594116-0x00594120` | padding | Ten `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594120-0x00594190` | IDA function `sub_594120`, size `0x70` | Delete selected/backward character behavior; calls `sub_593280` and `sub_591400`; uses selection endpoints and editor flag bit. | Exact child candidate `TextEditPaneDeleteSelectionOrBackspace`; closest to body-ready but still needs source spelling. |
| `0x00594190-0x005941e3` | raw no-function helper | Forward-delete helper; no direct xrefs; executable body uses `m_textStorage`, selection endpoints, `sub_593280`, `sub_591400`; returns before padding. | Exact raw child candidate `TextEditPaneDeleteForwardRawHelper`; body blocked by raw signature/source route. |
| `0x005941e3-0x005941f0` | padding | Thirteen `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x005941f0-0x00594658` | IDA function plus local switch tables | `sub_5941F0` size `0x428` through `0x00594618`; two adjacent tables `0x00594618-0x00594658` are referenced by the function and dispatch key/action cases. | Single exact child candidate `TextEditPaneMoveCursorNavigationDispatcher` should include the local tables. Body blocked by event/key enum names and table action names. |
| `0x00594658-0x00594660` | padding | Eight `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594660-0x0059467e` | raw no-function helper | Three-argument clamp helper returning bounded index; `retn 0x0c`; no direct xrefs. | Exact raw child candidate `TextEditPaneClampTextIndexRawHelper`; no aggregate C++. |
| `0x0059467e-0x00594680` | padding | Two `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594680-0x005946a4` | raw no-function helper | Normalizes two pointed 16-bit indices by swapping when out of order; `retn 8`; no direct xrefs. | Exact raw child candidate `TextEditPaneNormalizeSelectionPairRawHelper`. |
| `0x005946a4-0x005946b0` | padding | Twelve `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x005946b0-0x0059489f` | IDA function `sub_5946B0`, size `0x1ef` | Lower text-run renderer called by [UID:0001JR] and raw draw variant; handles masked text, comma formatting, `<B>/<b>` tag, and GrafPort text calls. | Exact child candidate `TextEditPaneDrawTextRunSegment`; candidate for later first-draft after source-name/signature audit. |
| `0x0059489f-0x005948a0` | padding | One `0xcc` byte. | Ignore/record as alignment if split. |
| `0x005948a0-0x005949be` | IDA function `sub_5948A0`, size `0x11e` | Wrap/measure helper using `StringIter`, lookahead, width calculation, and caller output pointers. | Exact child candidate `TextEditPaneMeasureTextRunWrapSegment`; body blocked by parameter names and line-wrap state names. |
| `0x005949be-0x005949c0` | padding | Two `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x005949c0-0x00594a21` | raw no-function helper | Masked/plain text width helper; checks `m_maskedText`, uses `L"*"` at `0x0062e168`, calls `sub_4BA9A0`, returns `retn 0x18`. | Exact raw child candidate `TextEditPaneMeasureMaskedOrPlainTextWidthRawHelper`. |
| `0x00594a21-0x00594a30` | padding | Fifteen `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594a30-0x00594b47` | raw no-function helper | Wrap segment helper scanning CR/LF, calling `sub_5948A0`, trimming spaces/control chars, and writing output index. | Exact raw child candidate `TextEditPaneWrapSegmentRawHelper`. |
| `0x00594b47-0x00594b50` | padding | Nine `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594b50-0x00594cb0` | IDA function `sub_594B50`, size `0x160` | Word-boundary helper; five callers from mouse/cursor/navigation; whitespace classification over UTF-16. | Exact child candidate `TextEditPaneFindWordBoundary`; likely body-ready after signature/name audit. |
| `0x00594cb0-0x00594e12` | IDA function `sub_594CB0`, size `0x162` | Selection autoscroll helper; callers from `sub_590DE0`; uses viewport fields, scroll helpers, and 48-pixel clamp. | Exact child candidate `TextEditPaneAutoScrollSelectionToPoint`; likely body-ready after source field/scroll naming audit. |
| `0x00594e12-0x00594e20` | padding | Fourteen `0xcc` bytes. | Ignore/record as alignment if split. |
| `0x00594e20-0x00594e5f` | raw no-function helper | Pre-support TextEditPane draw/callback-state helper; tests `m_editorFlags`, calls `sub_4B9660` and `unk_69B3FC`, restores draw state, returns `retn 4`. | Exact raw child candidate `TextEditPaneInvokeStyleDrawCallbackRawHelper`; signature/source role still medium confidence. |
| `0x00594e5f-0x00594e60` | padding | One `0xcc` byte before support-object constructor-shaped bytes. | Keep as boundary alignment. |

## First-Draft C++ Recommendation

Do not add first-draft C++ to [UID:0001JS] in its current aggregate form.

Target-specific no-code proof:

- The aggregate contains seven modeled functions, several raw helper bodies, local switch-table data, and alignment bytes. It is not one source function.
- The local switch-table data at `0x00594618-0x00594658` must stay with the navigation dispatcher child, but the source enum/action names remain inferred.
- Raw helper starts have executable code but no IDA function objects and no direct start xrefs; their source signatures remain below first-draft quality.
- Decompiler prototypes remain generic for important functions, including `char __thiscall sub_594040(int this, int a2)`, `__int16 __thiscall sub_5941F0(int this, int a2, __int16 a3)`, and `__int16 __thiscall sub_5948A0(__int16 *this, int, __int16, int, int *, _BYTE *, int, int)`.
- Emitting broad C++ here would summarize away the evidence and would conflict with current `TextEditPane.cpp` policy that exact method bodies belong on child by-memory pages.

Per-child first-draft candidates after split are strongest for `0x00594120`, `0x005946b0`, `0x00594b50`, and `0x00594cb0`, but each still needs its own accepted child-page source/signature pass. The current report recommends no formal code insertion.

## Final Recommendation

Implementation callback disposition now applied:

- `0001JS` is updated to `88/90`, owner/emitter unchanged, formal C++ still blank.
- Generic blockers were replaced with exact MCP-backed range inventory, two-switch-table finding, raw-helper liveness/signature blockers, and support-object boundary proof.
- The target now carries split-required/no-aggregate-C++ proof and the exact candidate child table.
- `by-file/TextEditPane.md` and `by-class/TextEditPane.md` now include the same report-level details without compressing away evidence.
- No child pages or UIDs were created; child creation remains future supervisor-only scope.
- No `execute_report`, lifecycle/archive command, manual generated edit, manual coverage edit, supervisor-ledger edit, or manual validator-state edit was run.

## Recommended Target Doc Changes

For `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`:

1. Metadata:
   - Set `COMPLETION:88`.
   - Set `CONFIDENCE:90`.
   - Keep `CANONICAL_OWNER:0000ON`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Keep `EMITTER_UIDS:0000ON`.
   - Keep formal `RECONSTRUCTION_CPP` blank.

2. Item Summary:
   - State that this is a split-required TextEditPane source-bearing aggregate with exact MCP-backed evidence for seven modeled functions, raw helper pockets, two adjacent switch tables, lower `DrawTextRunSegment`, `FindWordBoundary`, `AutoScrollSelectionToPoint`, and pre-support helper `0x00594e20`.
   - State that generated empty output is intentional deferred split/body work, not no-code evidence.

3. Status:
   - Replace broad "field names unresolved" wording with the exact no-code proof above.
   - Add current MCP session `supervisor-nexustk-20260707`, health facts, and key lookup/xref/decompile/byte results.

4. Source-Facing Naming Direction:
   - Keep `DeleteSelection`, `FindWordBoundary`, `AutoScrollSelectionToPoint`, and `DrawTextRunSegment` as best descriptive source-facing names.
   - Mark `MoveCursor`/`HandleNavigationKey`, `DeleteForward`, clamp/normalize helpers, width/wrap raw helpers, and pre-support callback helper as inferred pending child signatures.

5. Function And Byte Inventory:
   - Update the table with the exact split inventory in this report.
   - Refine `0x00594618-0x00594658` from one generic switch table to two adjacent tables: `0x00594618-0x00594628` and `0x00594628-0x00594658`.
   - Preserve padding rows and successor boundary `0x00594e60`.

6. Ownership Decision:
   - Keep file owner/emitter [UID:0000ON], covered class [UID:0000EO].
   - Reject support-object/TextFilter/TextBoxPane/GrafPort/FittingRoom/ScrollBar owner alternatives with current evidence.

7. Open Questions:
   - Replace generic blockers with precise unresolved items: event struct/key enum names, modifier/action names for the two switch tables, raw helper signatures, line/wrap table field names, and original source spelling for descriptive helper names.

8. Changes:
   - Add a 2026-07-07 B005 source-quality report entry with report path, fresh MCP session, current result, score recommendation, and "formal C++ remains blank pending split."

## Recommended Support Doc Changes

For `by-file/TextEditPane.md`:

- Update Source Emission Policy so the `0001JS` row says: real source-bearing aggregate, current score recommendation `88/90`, formal C++ blank, split-required before body C++, and exact child candidates as listed in this report.
- Update Proposed Contents / generated empty-family notes to say `0001JS` remains an intentional empty marker because it is split-required, not no-code.
- Add evidence that `0x00594618-0x00594658` contains two local switch tables referenced from `sub_5941F0`, and that `0x00594e20-0x00594e5f` is TextEditPane pre-support helper code before `TextEditObject` begins at `0x00594e60`.

For `by-class/TextEditPane.md`:

- Update the Method Families table for input navigation/wrapping to include the exact split-required status of `0x00594040-0x00594e60`.
- Update helper-name table rows for `0x00594120`, `0x00594190`, `0x005941f0`, `0x005946b0`, `0x005948a0`, `0x00594b50`, `0x00594cb0`, and `0x00594e20`.
- Add or refine the caveat that exact method-body C++ belongs on child by-memory pages; this aggregate should not emit body C++.

For neighboring target docs:

- [UID:0001JQ] `TextRunMeasureCallback` and [UID:0001JR] `DrawTextRunCallback` already contain accepted first-draft-ready state/callback details. No required edit unless implementation reveals a contradiction.
- [UID:0003FD] `DrawTextRunCallbackThiscallRaw` remains a raw caller/sibling evidence page. No required edit unless implementation needs to add a cross-reference to `DrawTextRunSegment`.
- Support-object successor docs do not require edits for this pass; target/support notes should cite them for the `0x00594e60` boundary only.

## Score And Metadata Recommendation

Recommended current target metadata after report incorporation:

| Field | Recommended value | Reason |
| --- | --- | --- |
| COMPLETION | `88` | Current report resolves exact range, switch table structure, raw helper liveness, owner/source placement, generated state, and no-code/split disposition. |
| CONFIDENCE | `90` | Current MCP evidence agrees with current docs and executed reports. Confidence remains capped by unresolved exact source spellings and raw helper signatures. |
| CANONICAL_OWNER | `0000ON` | Current file owner/emitter remains strongest for this mixed source/file-local/raw aggregate. |
| RECONSTRUCTABLE | `TRUE` | The row still contains real source code and should remain tracked until exact child pages exist. |
| EMITTER_UIDS | `0000ON` | Keep current generated route so the empty marker remains visible as source debt. |
| Formal C++ | blank | Aggregate body rejected; split first. |

Do not reclassify the current target to `RECONSTRUCTABLE:FALSE` unless a later supervisor-approved child split creates exact child pages that cover the code-bearing subranges. After child pages exist and carry reconstruction responsibility, the parent could become a non-emitting split-audit container. Making that metadata change before child coverage exists would hide live source debt.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current disposition |
| --- | --- | --- |
| What are the exact event struct and key enum names for `0x00594040`/`0x005941f0`? | Checked decompiler output and switch-table bytes; event byte offsets `+0x08` and `+0x10a` and key codes `0x80-0x83` are clear. | Behavior-backed only. Need child-level naming pass before C++ body. |
| Are the switch bytes padding, one table, or two tables? | Checked `get_bytes`, `xrefs_to 0x00594618`, and `xrefs_to 0x00594628`. | Resolved: two adjacent tables, 4 entries and 12 entries, both local to `sub_5941F0`. |
| Are raw helper starts live code? | Checked `lookup_funcs`, `xrefs_to`, `get_bytes`, and `disasm` for every raw start. | Resolved as live code, not padding; signatures still unresolved because no function object/direct raw-start refs. |
| Should the aggregate be moved to class owner [UID:0000EO]? | Compared current by-file/by-class policy and existing callback rows. | No. Keep current `0000ON` owner/emitter for the mixed file/source aggregate; [UID:0000EO] remains covered class and declaration support. |
| Is `0x00594e20` support-object code? | Checked disasm and successor bytes. `0x00594e20` uses TextEditPane/GrafPort state; `0x00594e60` starts `TextEditObject` constructor/vtable setup. | Resolved: keep `0x00594e20-0x00594e5f` in `0001JS`, stop at `0x00594e60`. |
| Can this report add C++? | Checked range contents and current source emission policy. | No. C++ requires exact child split and per-child signature/source-name audit. |

## Validator Results

Scoped validators authorized in `goal.md` were run only after supervisor implementation callback:

| File | Command | Command ID | Timestamp | Result |
| --- | --- | --- | --- | --- |
| `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md` | `python .\tools\validator.py --mode file --file by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md --apply --queue-timeout 240` | `000000007775` | `2026-07-07T02:02:22-04:00` | `ok: 1`; applied completion `88`, confidence `90`; reported existing missing-ref UID `0003FD` warnings; inserted missing UID link for `0000ON`; generated refresh deferred under same command id. |
| `by-file/TextEditPane.md` | `python .\tools\validator.py --mode file --file by-file\TextEditPane.md --apply --queue-timeout 240` | `000000007776` | `2026-07-07T02:02:32-04:00` | `ok: 1`; reported existing missing-ref UID warnings for support rows including `00040S`, `00040T`, `0003M8`, `0003FC`, and `0003FD`; inserted three missing UID links for `0001JS`; generated refresh deferred under same command id. |
| `by-class/TextEditPane.md` | `python .\tools\validator.py --mode file --file by-class\TextEditPane.md --apply --queue-timeout 240` | `000000007777` | `2026-07-07T02:02:40-04:00` | `ok: 1`; reported existing missing-ref UID warnings for support rows including `00040S`, `00040T`, `0003M8`, `0003FC`, and `0003FD`; generated refresh deferred under same command id. |

Generated-output freshness: deferred generated refresh completed in `auto-generated/NexusTK/ui/controls/TextEditPane.cpp` with header `validator-command-id: 000000007777`, `validator-refreshed-at: 2026-07-07T02:02:40-04:00`, and `validator-refresh-source: deferred-generated-refresh`. The UID0001JS generated marker now shows `Completion:88 | Confidence:90 | Empty Emitter Marker`, which is expected because aggregate formal C++ remains blank pending split.

No `execute_report`, lifecycle/archive command, manual report move, dry-run/probing equivalent, manual generated edit, manual coverage edit, supervisor-ledger edit, manual validator-state edit, child UID creation, or split child page creation was run.

## Lease Notes

- Lease acquisition command: `python .\tools\leaser\leaser.py B005 lease by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md by-file\TextEditPane.md by-class\TextEditPane.md`; all three returned `Success`.
- Release command after validators: `python .\tools\leaser\leaser.py B005 unlease by-memory\0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md by-file\TextEditPane.md by-class\TextEditPane.md`; all three returned `Rejected[No active lease]`.
- Read-only `tools/leaser/Agents/current_leases.md` check after the release attempt showed no active B005 lease rows; only unrelated B011 leases were present.

## Changed Files

Manual implementation/report edits:

- `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`
- `by-file/TextEditPane.md`
- `by-class/TextEditPane.md`
- `tools/leaser/Agents/Agent-B005/research/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md`

Scoped validator-owned side effects observed:

- `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

Leaser-owned side effect observed:

- `tools/leaser/Agents/current_leases.md`

No supervisor ledgers, lifecycle headers/footers, archive files, executed report archives, `-coverage-report.md` files, or by-* docs outside the target/support scope were intentionally edited by B005.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 validated this active report artifact in `Agent-B005/research` and issued explicit implementation callback before by-* edits.
- [x] Updated every accepted `Claim And Incorporation Ledger` row from `proposed` to one of: `applied` or `already-present`.
- [x] C001 destination check: target `Item Summary`, target `Status`/`Evidence Notes`, and `by-file/TextEditPane.md` `Source Emission Policy` now describe `0001JS` as real source-bearing TextEditPane code, not a no-code/empty row.
- [x] C002 destination check: target path/range `0x00594040-0x00594e60` preserved; `0x00594e20-0x00594e5f`, `0x00594e5f`, and `0x00594e60` boundary facts documented.
- [x] C003 destination check: two-table switch finding applied to target inventory and support helper/boundary sections.
- [x] C004 destination check: `TextEditPane::DrawTextRunSegment` preserved as inferred/descriptive naming; aggregate C++ kept blank.
- [x] C005 destination check: raw helper liveness/signature weakness documented for `0x00594190`, `0x00594660`, `0x00594680`, `0x005949c0`, `0x00594a30`, and `0x00594e20`.
- [x] C006 destination check: target metadata/source placement kept on [UID:0000ON] `TextEditPane.cpp`; rejected-owner reasoning preserved.
- [x] C007 destination check: target metadata now `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter/reconstructable unchanged, formal C++ blank, with score rationale.
- [x] C008 destination check: split-required child candidate plan added to target and support source-emission policy; no child pages or UIDs created.
- [x] C009 destination check: negative evidence/rejected-owner reasoning preserved in target/support sections.
- [x] C010 destination check: neighboring callback docs [UID:0001JQ], [UID:0001JR], and [UID:0003FD] verified as support evidence only; ledger row marked `already-present`; no edits made to those files.
- [x] Leased target/support docs before edit batch; release command found no active B005 leases after validators and `current_leases.md` confirmed no active B005 entries.
- [x] Ran scoped validators only for changed by-* docs and recorded command IDs/timestamps/results.
- [x] No split child pages or new UIDs were created.
- [x] Ready to return `READY_FOR_SUPERVISOR_EXECUTE`; `execute_report` and lifecycle/archive handling remain for the supervisor.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007782","destination_path":"executed-b-agent-research/B005/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md","timestamp":"2026-07-07T02:13:00-04:00","uid":"0001JS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
