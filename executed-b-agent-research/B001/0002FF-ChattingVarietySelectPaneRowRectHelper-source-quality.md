** TARGET-REPORT-UID:0002FF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: 0002FF ChattingVarietySelectPaneRowRectHelper Source Quality

Assignment ID: `B001-report-chatting-variety-row-rect-helper-source-quality-0002FF-mcp-20260623`

Agent: `B001`

Target: [UID:0002FF] `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`

Report path: `tools/leaser/Agents/Agent-B001/research/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md`

MCP basis: active IDB session `b880584f` at `http://127.0.0.1:13337/mcp`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

## Executive Recommendation

Raise [UID:0002FF] from `84/91` to `86/92`.

Keep:

- `CANONICAL_OWNER:00001Y`
- `EMITTER_UIDS:00001Y`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP`
- exact range `0x00481010-0x00481056`

The target should no longer remain below 85 completion. Current MCP session `b880584f` converts the old no-route caveat from an offline/local-PE lead into current IDB-backed negative evidence: no modeled function, no inbound xrefs, no code refs, no data refs, and no immediate VA/RVA hits were found for `0x00481010`. The body, padding, behavior, semantic owner, compact-button relationship, and selector-row rejection are now strong enough for an above-85 documentation score.

Do not add first-draft C++ yet. The exact original source declaration remains unproven because no caller or pointer/table route shows whether this was an unused-this member helper, a static member, or a file-local helper. A helper-only C++ body would use a plausible but still invented declaration shape.

Best documentation/source-facing label: `ChattingVarietyPaneCompactButtonRectHelper`.

Best future source-name candidate if a caller or original declaration is later recovered: `GetCompactButtonRect(int index, RectBounds *outRect)` or `ChattingVarietyPane::GetCompactButtonRect(int index, RectBounds *outRect)`. The current filename/report label `ChattingVarietySelectPaneRowRectHelper` is a stale advanced-scan label and should remain only as a searchable alias unless a supervisor explicitly asks for a rename.

## Scope And Inputs

Current assignment source:

- `tools/leaser/Agents/Agent-B001/goal.md`
- project-level `ntk-b-agent-workflow` skill and `references/b-agent-research-and-implementation-workflow.md`
- `by-structure.md` code-entry and scoring guidance

Current docs checked:

- `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`
- `by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md`
- `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`
- `by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md`
- `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md`
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
- `by-class/ChattingVarietyPane.md`
- `by-class/ChattingVarietySelectPane.md`
- `by-file/Chatting.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`

Archived B001/B003 ChattingVariety reports were requested as leads. No standalone archived B001/B003 ChattingVariety report file was found in the current `Agent-B001` or `Agent-B003` research/executed folders during this pass. The incorporated B001/B003 change notes in the by-* pages were treated as lead material and rechecked against MCP, not as authority.

No by-* docs, generated/project-level files, IDA DB/tool state, or coverage reports were edited during this report-only pass.

## Current Target State

Header state:

- `UID:0002FF`
- `COMPLETION:84`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00001Y`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001Y`
- `RECONSTRUCTION_CPP`: blank

The target page already documents the core correct facts: raw IDA-unmodeled helper, compact button rectangle `(0,0,62,24)`, empty rectangle `(-1,-1,-1,-1)`, semantic owner [UID:00001Y] `ChattingVarietyPane`, pair relationship to [UID:0002FG], rejection of selector six-row geometry, no direct xrefs, and blank C++ due unresolved declaration form.

The remaining stale items are:

- The body says the helper remains below the 85 completion gate.
- The target's coverage row in `by-memory/-coverage-report.md` still says `82%`, while the target header is already `84/91`.
- The coverage row and `ChattingUI` aggregate still contain "selector" wording for a compact-button helper.
- The target evidence references earlier "live IDA" and local PE scans, but does not yet cite current MCP session `b880584f`.

## Inference Claim Ledger

| Claim | Strength | Evidence | Risk / Caveat | Recommended action |
| --- | --- | --- | --- | --- |
| The range is exactly `0x00481010-0x00481056`. | Confirmed | MCP `lookup_funcs` shows no function at `0x00481010` or `0x00481056`; `get_bytes` and `insn_query` show a complete body ending in `retn 8` at `0x00481053`; padding begins at `0x00481056`. | None material. | Keep exact range. |
| This is source-owned project code, not padding/compiler glue. | Strong | Body has normal prologue, two behavior paths, two direct calls to `sub_4B7C50`, and stack-arg cleanup `retn 8`; adjacent bytes are explicit `0xcc` padding. | No inbound route is known. | Keep `RECONSTRUCTABLE:TRUE`. |
| Semantic owner is `ChattingVarietyPane`. | Strong | Same compact `(0,0,62,24)` geometry appears inline in `ChattingVarietyPane::OnMouseEvent`; helper sits after the `ChattingVarietyPane` vtable-owned refresh forwarder and before the selector constructor; selector row helpers use different six-row geometry. | Exact declaration member/static/file-local remains unknown. | Keep `CANONICAL_OWNER:00001Y` and `EMITTER_UIDS:00001Y`. |
| It is not `ChattingVarietySelectPane` row geometry. | Confirmed | MCP decompilation of `0x00481a80` writes `(0,row*16+6,67,row*16+22)` and has a direct `OnPaint` caller; MCP decompilation of `0x00481ad0` loops six rows with callers inside selector `OnMouseEvent`. Target only accepts row/index `0` for `(0,0,62,24)`. | Filename/report label remains stale. | Preserve stale label only as an alias; do not move owner. |
| No direct route to the raw start is present in current MCP. | Confirmed for IDA-known routes | `xrefs_to 0x00481010` returns zero; `find code_ref`, `find data_ref`, and `find immediate` for VA `0x00481010` and RVA `0x81010` return zero. | A computed runtime route or lost external object-file route cannot be excluded. | Document no-route as current evidence, not as proof of no original source. |
| Score should rise above 85 completion. | Strong | Behavior, range, padding, source placement, owner, negative route checks, and rejected alternatives are all current-MCP backed. | Missing source declaration still blocks final C++. | Recommend `86/92`. |
| Formal C++ should stay blank. | Strong | No caller proves ECX/receiver use, member vs static vs file-local declaration, original name, or whether helper should be emitted as part of a paired helper policy. | Candidate code shape is simple but declaration is not source-quality. | Keep formal C++ blank. |

## Positive Evidence Summary

- MCP session `b880584f` is active and healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- IDA models the adjacent forwarder at `0x00481000` and the next modeled destructor at `0x00481150`, but not the target, the following hit-test helper, or the raw constructor start.
- Target bytes decode as a compact two-argument rectangle writer ending in `retn 8`.
- Leading `0x0048100a-0x00481010` and trailing `0x00481056-0x00481060` bytes are alignment `0xcc`.
- The first argument controls rectangle selection. `0` writes compact button rect `(0,0,62,24)`; `-1` and all other nonzero values write `(-1,-1,-1,-1)`.
- Both target paths call `sub_4B7C50`, the same rectangle initializer used by nearby selector row helpers and inline `OnMouseEvent` rectangle setup.
- `ChattingVarietyPane::OnMouseEvent` in modeled function `0x00480cd0` performs the same one-candidate compact hit-test geometry before creating or dismissing `ChattingVarietySelectPane`.
- Selector popup row geometry is separately modeled and routed: `0x00481a80` has a direct caller in selector `OnPaint`, and `0x00481ad0` has two direct callers in selector `OnMouseEvent`.

## IDA MCP Facts

MCP health and session:

- Timestamp of main evidence batch: `2026-06-23T07:01:48-04:00`.
- Timestamp of route/decompile follow-up batch: `2026-06-23T07:02:16-04:00`.
- `idb_list`: one active session, `session_id:b880584f`, `input_path:E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `filename:NexusTK.exe.i64`, `is_analyzing:false`, `backend:worker`, `owned:true`, `adopted:true`, PID `27504`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Function status from `lookup_funcs`:

| Query | MCP result |
| --- | --- |
| `0x00481000` | `sub_481000`, size `0xa` |
| `0x00481010` | not a function |
| `0x00481056` | not a function |
| `0x00481060` | not a function |
| `0x004810ea` | not a function |
| `0x004810f0` | not a function |
| `0x00481150` | `sub_481150`, size `0x6c` |
| `0x00480cd0` | `sub_480CD0`, size `0x1b0` |
| `0x00481a80` | `sub_481A80`, size `0x4d` |
| `0x00481ad0` | `sub_481AD0`, size `0x8b` |
| `0x004b7c50` | `sub_4B7C50`, size `0x1f` |
| `0x004b7e80` | `sub_4B7E80`, size `0x27` |

Boundary bytes from `get_bytes`:

- `0x0048100a` size `6`: `cc cc cc cc cc cc`
- `0x00481010` size `0x46`: starts `55 8b ec 8b 45 08 83 f8 ff 74 21 85 c0 75 1d ba 18 00 00 00 b9 3e 00 00 00 ...` and ends `... e8 01 6c 03 00 83 c4 14 5d c2 08 00`
- `0x00481056` size `10`: `cc cc cc cc cc cc cc cc cc cc`
- `0x00481060` size `0x8a`: complete companion compact hit-test raw body, followed by `retn 8` at `0x004810e7`
- `0x004810ea` size `6`: `cc cc cc cc cc cc`

Target instruction facts from MCP `insn_query 0x00481010-0x00481056`:

- `0x00481010`: `push ebp`; raw body has no containing IDA function.
- `0x00481013`: loads first argument from `[ebp+8]`.
- `0x00481016`: compares first argument to `-1`; `0x0048101b` tests for zero.
- `0x0048101f-0x0048102d`: for first argument `0`, pushes rectangle coordinates `0,0,62,24` and destination pointer `[ebp+0Ch]`.
- `0x00481030`: calls `sub_4B7C50`.
- `0x00481039`: `retn 8`.
- `0x0048103c-0x00481047`: for `-1` or other nonzero values, builds four `-1` coordinates and pushes destination pointer `[ebp+0Ch]`.
- `0x0048104a`: calls `sub_4B7C50`.
- `0x00481053`: `retn 8`.
- MCP scanned 30 instructions, no containing function, no truncation.

Companion compact hit-test facts from MCP `insn_query 0x00481060-0x004810ea`:

- Raw body has no containing IDA function.
- Builds a stack `RectBounds` at `[ebp-14h]`.
- Tests candidate `bl = 0`; candidate `0` maps to rectangle `(0,0,62,24)`.
- Calls `sub_4B7C50` at `0x004810a2`.
- Calls `sub_4B7E80` at `0x004810ad`.
- Loop limit is `bl < 1`, so only one compact candidate is checked.
- Miss path returns `0xff`; hit path returns `bl` (`0`).
- Security-cookie checks occur before both `retn 8` exits.

Decompile status:

- `decompile 0x00481010`: `code:null`, error `Decompilation failed at 0x481010`.
- `decompile 0x00481060`: `code:null`, error `Decompilation failed at 0x481060`.
- `decompile 0x004810f0`: `code:null`, error `Decompilation failed at 0x4810f0`.
- These are expected no-function-model failures, not MCP availability failures.

Modeled relationship evidence:

- `decompile 0x00480cd0` shows `ChattingVarietyPane` mouse handling: event subtype byte `a2+4 == 1`, point fields `a2+8` and `a2+0xc`, one-candidate compact rectangle `(0,0,62,24)`, `sub_4B7E80` point test, existing popup dismissal via `sub_544690(this[23])`, otherwise selector allocation `252`, base construction, vtable stores, `+0xf8 = 0`, `+0xf9 = -1`, popup rectangle `(7,617,74,727)`, layer/setup virtual calls, and owner refresh.
- `decompile 0x00481a80` shows selector row rectangle helper: `row == -1` writes empty rect; otherwise writes `(0, 16*row+6, 67, 16*row+22)`.
- `decompile 0x00481ad0` shows selector hit-test loop over six rows; direct callers are inside selector `OnMouseEvent`.

## Direct Xref / Caller Inventory

Current MCP xref and route findings:

| Target | `xrefs_to` / `xref_query` result | `find code_ref` | `find data_ref` | `find immediate` |
| --- | --- | --- | --- | --- |
| `0x00481010` | no inbound xrefs; `xref_query both` only reports raw internal flow from `0x481010` to `0x481011` | 0 | 0 | VA `0x00481010` and RVA `0x81010`: 0 |
| `0x00481060` | no inbound xrefs; `xref_query both` only reports raw internal flow from `0x481060` to `0x481061` | 0 | 0 | VA `0x00481060` and RVA `0x81060`: 0 |
| `0x004810f0` | no inbound xrefs; `xref_query both` only reports raw internal flow from `0x4810f0` to `0x4810f1` | 0 | 0 | VA `0x004810f0` and RVA `0x810f0`: 0 |
| `0x00480cd0` | one data xref at `0x00614ef4` vtable slot | not rechecked here | not rechecked here | not needed |
| `0x00481a80` | one code xref at `0x00481605` inside `sub_481490` selector `OnPaint` | not rechecked here | not rechecked here | not needed |
| `0x00481ad0` | two code xrefs at `0x0048124d` and `0x00481430` inside `sub_4811C0` selector `OnMouseEvent` | not rechecked here | not rechecked here | not needed |

This direct-route inventory is important for the C++ decision. The target's lack of direct route is now a current MCP fact, but it still prevents proving the original declaration form.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Current owner/emitter | Score | MCP-backed status |
| --- | --- | --- | --- | --- | --- |
| `0x00481000-0x0048100a` | [UID:0002FE] `ChattingVarietyPaneRefreshForwarder` | tiny compiler-generated secondary forwarder | `00001Y` context, ignored/rebuild glue | coverage row `80%` ignored | Modeled `sub_481000`, size `0xa`. |
| `0x00481010-0x00481056` | [UID:0002FF] target | compact button rectangle helper | `00001Y` / `00001Y` | current `84/91`; recommend `86/92` | Raw, no function, complete body and no-route evidence. |
| `0x00481060-0x004810ea` | [UID:0002FG] compact hit-test helper | compact button point hit-test | `00001Y` / `00001Y` | `84/91` | Raw, no function, no inbound route, same compact geometry. |
| `0x004810f0-0x00481146` | [UID:0002FH] selector raw constructor | raw constructor body | `00001Z` / `00001Z` | `84/91` | Raw, no function/no route in this pass. |
| `0x00480cd0-0x00480e80` | [UID:0002FC] `ChattingVarietyPane::OnMouseEvent` | compact button click and popup create/dismiss | `00001Y` / `00001Y` | `86/91` | Modeled, vtable-routed, same compact rectangle inline. |
| `0x00481a80-0x00481acd` | [UID:0002FM] selector `GetItemRect` | six-row popup row rectangle | `00001Z` / `00001Z` | `86/92` | Modeled, direct caller in selector `OnPaint`, first-draft C++ present. |
| `0x00481ad0-0x00481b5b` | [UID:000106] selector hit-test | six-row popup hit-test | `00001Z` / `00001Z` | `86/91` | Modeled, two direct callers in selector `OnMouseEvent`. |

## Documentation Evidence And IDA Status

The target and support docs are broadly correct. The current implementation callback, if accepted, should refresh provenance and score, not reverse the ownership model.

Current docs correctly state:

- `0x00481010` is an IDA-unmodeled raw helper.
- The helper writes compact button rectangle `(0,0,62,24)` or invalid rectangle `(-1,-1,-1,-1)`.
- The helper belongs semantically with `ChattingVarietyPane`, not `ChattingVarietySelectPane` row geometry.
- The following [UID:0002FG] helper tests the same compact rectangle and returns `0` or `0xff`.
- Selector popup row geometry lives at [UID:0002FM] and [UID:000106].
- Formal C++ remains blank.

Items to refresh if accepted:

- Replace "below the 85 completion gate" wording with "above-85 documentation-ready but no-code due declaration-route absence".
- Add current MCP session `b880584f` evidence to supersede older live-IDA/offline/local PE phrasing.
- Record `find code_ref`, `find data_ref`, and `find immediate` no-hit results for target VA/RVA.
- Correct coverage row staleness from `82%` to the accepted score.
- Correct "raw selector rectangle helper" aggregate wording in `ChattingUI` to compact-button helper wording.

## Ranked Ownership Analysis

### 1. `ChattingVarietyPane` compact-button helper - accepted

This remains the best direct semantic owner.

Evidence:

- The helper's only positive behavior is compact button geometry `(0,0,62,24)`.
- `ChattingVarietyPane::OnMouseEvent` uses that exact compact rectangle inline for the click that creates/dismisses the selector popup.
- The helper is physically adjacent to `ChattingVarietyPane` modeled methods and the tiny refresh forwarder.
- The helper is paired with [UID:0002FG], which tests only candidate `0` and returns `0` or `-1`.
- The class page already owns `m_selectPane` at `+0xfc` and the popup create/dismiss relationship.

Risk:

- No caller proves whether the original declaration was member, static member, or file-local.

Disposition:

- Keep `CANONICAL_OWNER:00001Y` and `EMITTER_UIDS:00001Y`.
- Keep source route through [UID:0000I5] `Chatting`.

### 2. File-local `Chatting.cpp` helper - plausible declaration form, rejected as metadata owner change

The binary body does not use `this`, and the source declaration could have been a file-local helper in `Chatting.cpp`.

This does not require a metadata owner change. Documentation ownership should stay with the narrow semantic class because the helper supports only `ChattingVarietyPane` compact-button behavior. If later caller evidence proves a file-local source declaration, the generated C++ can still route through `00001Y` into `Chatting.cpp` or the helper can be reclassified with explicit evidence.

### 3. `ChattingVarietySelectPane` row helper - rejected

The filename/report label suggests selector row geometry, but MCP evidence rejects it:

- Target width/right edge is `62`, height/bottom is `24`, and only index `0` produces a valid rectangle.
- Selector row rectangle helper at `0x00481a80` uses right edge `67`, top `row*16+6`, bottom `row*16+22`, and has a direct selector `OnPaint` caller.
- Selector hit-test at `0x00481ad0` loops six rows and has two direct selector `OnMouseEvent` callers.
- Target has no selector caller and no direct route at all.

### 4. `ChattingUI` aggregate - rejected as direct owner

[UID:000104] is a useful parent range and audit map, but it is too broad for a compact helper. It should not be the canonical owner or emitter while [UID:00001Y] clears the attachment gate.

### 5. No-owner / non-emitting retained helper - rejected

The body is source-shaped project code in the chat UI range. It has real behavior and a valid semantic owner. Lack of direct xrefs should block formal C++ declaration, not erase ownership/emission metadata.

### 6. Compiler-generated / runtime / ignored artifact - rejected

The body is not thunk glue, padding, SEH-only glue, import/runtime code, or vtable data. It has normal source helper control flow and direct project helper calls.

## Source Placement

Current source placement remains [UID:0000I5] `Chatting`, proposed source file `NexusTK/social/Chatting.cpp`.

Reasons:

- `ChattingVarietyPane`, `ChattingVarietySelectPane`, and their surrounding chat UI classes are already grouped under `by-file/Chatting.md`.
- The target supports the compact chat-mode button that opens the selector popup.
- No evidence suggests a separate source file, `ChatColorDialog.cpp`, list-pane source, runtime source, or generated-only source owner.

No source-file split is required before score improvement. First-draft C++ remains blocked for the target itself, but the source route is stable.

## Range / Split / Padding / Reclassification Analysis

No range or split change is recommended.

Confirmed layout:

- `0x00481000-0x0048100a`: modeled tiny forwarder `sub_481000`, size `0xa`.
- `0x0048100a-0x00481010`: six bytes of `0xcc` padding.
- `0x00481010-0x00481056`: target raw compact rect helper.
- `0x00481056-0x00481060`: ten bytes of `0xcc` padding.
- `0x00481060-0x004810ea`: companion compact hit-test helper.
- `0x004810ea-0x004810f0`: six bytes of `0xcc` padding.
- `0x004810f0-0x00481146`: raw selector constructor body.
- `0x00481150`: next modeled function `sub_481150`.

The target should not be merged with [UID:0002FG] because the helpers have separate prologues, separate `retn 8` exits, and explicit `0xcc` padding between them.

The target should not be merged into the selector constructor or moved to selector row geometry. The `0x00481056-0x00481060` and `0x004810ea-0x004810f0` padding spans are exact boundaries.

## Negative Evidence Summary

MCP negative checks:

- No IDA function at `0x00481010`, `0x00481056`, or `0x00481060`.
- Hex-Rays cannot decompile `0x00481010`, `0x00481060`, or `0x004810f0` because there is no function model.
- `xrefs_to 0x00481010`: zero inbound xrefs.
- `find code_ref 0x00481010`: zero.
- `find data_ref 0x00481010`: zero.
- `find immediate 0x00481010`: zero.
- `find immediate 0x81010`: zero.
- No vtable/table/global/string route to `0x00481010` was found in current MCP route checks.
- No current MCP route shows a direct caller, pointer table, data pointer, absolute literal, RVA literal, string-owned callback route, or vtable slot for the target.

Rejected stale or weaker assumptions:

- The advanced-scan filename/report label does not prove selector ownership.
- Spatial adjacency before the selector constructor does not override the compact-button geometry and `ChattingVarietyPane` `OnMouseEvent` match.
- Existing B001/B003 notes were treated as leads only; current MCP independently confirms the useful facts.
- The old offline/local PE scan is no longer the primary evidence. It is consistent with MCP but should be superseded by `b880584f` facts in the target doc.

## Heuristic / Inference Reanalysis And Validation

Heuristic: "helper name follows filename label".

- Result: rejected.
- Reason: filename label says `ChattingVarietySelectPaneRowRectHelper`, but the body lacks selector six-row geometry and has no selector caller. A filename label is weaker than live body semantics and MCP xrefs.

Heuristic: "adjacent raw bodies before the selector constructor belong to the selector".

- Result: rejected for the target and companion hit-test.
- Reason: the two raw helpers before `0x004810f0` use compact button geometry. The selector constructor starts after explicit `0xcc` padding at `0x004810f0`; selector-owned geometry appears later at modeled helpers `0x00481a80` and `0x00481ad0`.

Heuristic: "no xrefs means non-reconstructable".

- Result: rejected.
- Reason: the raw body is source-shaped code with concrete behavior inside a source-owned chat UI range. No-route evidence should block formal C++ declaration and original-name confidence, not source ownership.

Heuristic: "simple body can receive C++ once average score clears the numeric gate".

- Result: rejected for this pass.
- Reason: the code-entry rule is a minimum eligibility rule, not permission to invent source declarations. The target lacks the route evidence needed to choose member/static/file-local shape.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are recommended during this report-only pass.

Do not create or rename an IDA function at `0x00481010` yet. IDA currently has no function model or xrefs, and creating a function name would make a source declaration look more certain than the evidence supports.

Documentation naming recommendations:

- Use `ChattingVarietyPaneCompactButtonRectHelper` as the best durable documentation label.
- Preserve `ChattingVarietySelectPaneRowRectHelper` as the existing filename/advanced-scan alias only.
- If source C++ later becomes safe, prefer a source-facing role name such as `GetCompactButtonRect` over the generated report label.

Type/signature evidence:

- Machine ABI: two stack arguments, callee cleanup `retn 8`.
- Argument roles:
  - `[ebp+8]`: index/candidate value.
  - `[ebp+0xc]`: destination `RectBounds *`.
- Probable source shape if later proven:

```cpp
// Candidate only; do not populate formal RECONSTRUCTION_CPP from this report.
static void GetCompactButtonRect(int index, RectBounds *outRect);
```

or, if a future caller proves an ECX receiver:

```cpp
// Candidate only; do not populate formal RECONSTRUCTION_CPP from this report.
void ChattingVarietyPane::GetCompactButtonRect(int index, RectBounds *outRect);
```

## First-Draft C++ Recommendation

Recommendation: keep formal `RECONSTRUCTION_CPP` blank.

No-code proof:

- The target has `RECONSTRUCTABLE:TRUE` and a confirmed emitter route, and this report recommends `86/92`, but the code-entry gate is a minimum, not a guarantee of source readiness.
- Current MCP has no caller, code ref, data ref, immediate VA/RVA hit, vtable entry, table route, string route, or global route to `0x00481010`.
- The body itself does not use ECX or any global/class field, so it cannot distinguish between:
  - a file-local helper in `Chatting.cpp`;
  - a `static` class helper;
  - a non-static `ChattingVarietyPane` member whose `this` was passed in ECX but unused;
  - a retained object-file helper referenced only through a route IDA cannot currently recover.
- The source-facing declaration also depends on shared `RectBounds`/`InitRectBounds` naming and companion compact hit-test policy.
- Emitting a helper-only body now would create plausible pseudo-source, not proven project source. It would also risk mismatching the surrounding `ChattingVarietyPane` declaration-only class policy, where child raw helpers are intentionally blank until route/declaration evidence appears.

Future first-draft C++ may be viable if any of the following appear:

- direct caller or pointer/table route to `0x00481010`;
- original symbol/declaration evidence;
- a paired-helper source policy that intentionally emits retained no-route compact helpers with explicit file-local declarations;
- a synchronized aggregate C++ pass for `ChattingVarietyPane` and its raw compact helpers.

## Final Recommendation

Apply this disposition if accepted:

- Target score: `86/92`.
- Owner/emitter: unchanged, `00001Y`.
- Reconstructable: unchanged, `TRUE`.
- Range/split: unchanged.
- Source placement: unchanged, `NexusTK/social/Chatting.cpp` through [UID:0000I5] `Chatting`.
- Formal C++: keep blank.
- Coverage row: supervisor-owned update recommended because current row is stale and still says `82%`.

## Recommended Target Doc Changes

For `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`:

- Update `COMPLETION:84` to `COMPLETION:86`.
- Update `CONFIDENCE:91` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00001Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Y`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.
- Replace "remains below the 85 completion gate" wording with a current statement that documentation can clear 85 while formal C++ stays blank.
- Add current MCP session `b880584f` evidence:
  - active session and healthy IDB;
  - `lookup_funcs` not-a-function result for `0x00481010`, `0x00481056`, `0x00481060`, and `0x004810f0`;
  - exact bytes and padding;
  - `insn_query` two-path body and `retn 8`;
  - `decompile` no-function failure;
  - `xrefs_to`, `find code_ref`, `find data_ref`, and `find immediate` negative results for target VA/RVA.
- Add exact no-code proof from this report.
- Add score rationale for `86/92`: body/owner/range/no-route evidence complete enough for above-85 documentation; exact original declaration still blocks C++ and higher score.
- Keep `ChattingVarietyPaneCompactButtonRectHelper` as best documentation label; preserve `ChattingVarietySelectPaneRowRectHelper` as the filename/advanced-scan alias.

## Recommended Support Doc Changes

Recommended support docs if implementation is accepted:

- `by-class/ChattingVarietyPane.md`
  - Refresh the raw helper evidence note with MCP session `b880584f`.
  - State that [UID:0002FF] can move to `86/92` while formal C++ remains blank because no current MCP caller/pointer/table route proves declaration form.
  - No class score change required.

- `by-class/ChattingVarietySelectPane.md`
  - Preserve the rejection that [UID:0002FF] is not selector row geometry.
  - If edited, add a narrow MCP-backed note that selector row helpers `0x00481a80`/`0x00481ad0` are modeled and directly routed, unlike compact raw helpers `0x00481010`/`0x00481060`.
  - No class score change required.

- `by-file/Chatting.md`
  - Refresh the `ChattingVarietyPane` contents row if desired to say [UID:0002FF] is now MCP-rechecked at `86/92`.
  - No file score change required.

- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
  - Correct the `0x00481010-0x00481056` row wording from "raw selector rectangle helper" to "compact button rectangle helper".
  - Correct the `0x00481060-0x004810ea` row wording from "raw selector hit-test helper" to "compact button hit-test helper" if the support row is touched.
  - No aggregate score change required.

No changes are required to [UID:0002FC], [UID:0002FM], or [UID:000106] unless the supervisor wants a provenance-only MCP refresh. They already contain the facts needed to support the target recommendation.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:84`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00001Y`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001Y`
- `RECONSTRUCTION_CPP`: blank

Recommended score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:00001Y`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001Y`
- `RECONSTRUCTION_CPP`: blank

Score rationale:

- Completion should rise because current MCP confirms exact range, raw body, leading/trailing padding, two-path rectangle behavior, no function model, no inbound xrefs, no code/data/immediate VA/RVA route, compact `OnMouseEvent` relationship, selector row-helper rejection, and source route.
- Completion should not rise higher because no caller or pointer/table route proves the original declaration, and formal C++ remains intentionally blank.
- Confidence should rise to `92` because the previous no-route and ownership facts are now current-session MCP-backed rather than local/offline leads.
- Confidence should not rise higher because the exact original helper name and member/static/file-local declaration remain unresolved.

## Open Questions With Attempted Resolution

- Is this helper a selector popup row helper?
  - Resolution: no. MCP confirms selector row geometry and callers live in `0x00481a80` and `0x00481ad0`; target is compact button geometry.

- Does the range need a split or merge?
  - Resolution: no. Exact `0xcc` padding separates target from the previous forwarder and following hit-test helper.

- Does current MCP find a direct route to `0x00481010`?
  - Resolution: no. `xrefs_to`, `find code_ref`, `find data_ref`, and `find immediate` all return no inbound route/hits for target VA/RVA.

- Can the target be raised above 85?
  - Resolution: yes. The missing caller is now a documented negative route result rather than an unperformed check; behavior/owner/range evidence supports `86/92`.

- Is first-draft C++ ready?
  - Resolution: no. The declaration form remains unproven.

- Should the file be renamed?
  - Resolution: not in this pass. The source-facing documentation label should be corrected in prose, but filename churn is unnecessary without supervisor direction.

## Exact Supervisor-Owned Coverage Text

Coverage change recommended: yes, only if the supervisor accepts the `86/92` recommendation.

File/placement: `by-memory/-coverage-report.md`, replace the existing [UID:0002FF] row.

Exact replacement text:

```text
        - [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) 0x00481010-0x00481056 | compact button rectangle helper | ChattingVarietyPaneCompactButtonRectHelper : reconstructable : 86% : very strong : MCP session b880584f reconfirms exact raw compact chat-variety button rectangle helper 0x00481010-0x00481056, no modeled function and decompile failure due no function model, exact bytes, six leading and ten trailing 0xcc padding bytes, two sub_4B7C50 rectangle setter calls, ret 8 two-argument shape, compact (0,0,62,24) output for index 0, empty (-1,-1,-1,-1) output for -1 or any nonzero index, no direct xrefs/code refs/data refs/immediate VA or RVA hits to 0x00481010, compact ChattingVarietyPane OnMouseEvent geometry match, selector row-helper rejection because selector geometry is (0,row*16+6,67,row*16+22) in routed helpers 0x00481a80/0x00481ad0, owner/emitter stay ChattingVarietyPane, exact member/static/file-local declaration remains unresolved, and final C++ remains blank.
```

Reason B agent must not apply it directly during this pass: report-only scope forbids editing any `-coverage-report.md`; supervisor owns coverage application.

## Follow-Up Actions

- Supervisor: decide whether to accept `86/92` with blank C++.
- If accepted, implementation callback should edit only the accepted target/support by-* docs and leave coverage to supervisor unless explicitly authorized.
- Future research should focus only on route/declaration evidence: direct caller, pointer/table route, original symbol, object-file/source declaration, or a deliberate retained-helper C++ policy.

## Confidence

- Recommendation confidence: strong.
- Boundary confidence: confirmed.
- Behavior confidence: confirmed.
- Owner/source-placement confidence: strong.
- No-route confidence: strong for current IDA/MCP-visible routes.
- C++ no-code confidence: strong.
- Remaining uncertainty: original helper spelling and declaration form.

## Validator Results

Implementation callback validators run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality-removed.md](0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- Target validator: exit code `0`, `ok: 1`, scanned `1` markdown file; applied `completion_update 0002FF ... 86`, `confidence_update 0002FF ... 92`, one `uid_link_insert 0002FG`, removed stale low-completion stats row, updated projected stats, rebuilt `validator.ini`, and updated validator-owned generated `auto-generated/NexusTK/social/Chatting.cpp`.
- `ChattingVarietyPane` validator: exit code `0`, `ok: 1`, scanned `1` markdown file; inserted six [UID:0002FF] links, reported `stats_incremental_noop 00001Y`, updated projected stats, rebuilt `validator.ini`, and reported `autogen_cpp_noop 0000I5`.
- `ChattingUI` validator: exit code `0`, `ok: 1`, scanned `1` markdown file; inserted one [UID:0002FF] link, reported `stats_incremental_noop 000104`, updated projected stats, rebuilt `validator.ini`, and reported `autogen_cpp_noop 0000I5`.

Supervisor verification correction validator:

> Executable block R002 was removed from this report and preserved verbatim in [0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality-removed.md](0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Correction target validator: exit code `0`, `ok: 1`, scanned `1` markdown file after rewriting the stale 2026-06-17 threshold note; reported `stats_incremental_noop 0002FF`, updated projected stats, rebuilt `validator.ini`, updated validator-owned `auto-generated/NexusTK/app/Application.cpp`, updated validator-owned `auto-generated/-ag-memory-coverage.md`, and created validator backup `tools/validator_autogen_backup/20260623-072930`.

No validators were run for unchanged optional support docs. No `-coverage-report.md` file was edited or validated by B001.

## Changed Files

- Initial report-only pass created: `tools/leaser/Agents/Agent-B001/research/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md`
- Implementation callback modified by B001:
  - `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`
  - `by-class/ChattingVarietyPane.md`
  - `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
  - `tools/leaser/Agents/Agent-B001/research/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md`
- Supervisor verification correction modified by B001:
  - `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`
  - `tools/leaser/Agents/Agent-B001/research/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md`
- Validator-owned side effects reported by scoped validators:
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
  - `auto-generated/NexusTK/social/Chatting.cpp`
  - `auto-generated/NexusTK/app/Application.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `tools/validator_autogen_backup/20260623-072930`
- Renamed: none.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation in the callback.
- [x] Target/support docs to update if accepted identified. Proof: callback listed target and support docs; B001 edited target, `ChattingVarietyPane`, and `ChattingUI`; optional `ChattingVarietySelectPane` and `by-file/Chatting.md` were not edited because the needed selector rejection/source route was already present or not needed for the accepted callback.
- [x] Current target state and actual evidence checked recorded. Proof: report recorded starting `84/91`, owner/emitter `00001Y`, reconstructable true, blank formal C++, current docs, stale coverage row, generated route, and MCP session `b880584f`.
- [x] Metadata/score changes to apply if accepted recorded. Proof: implementation changed the target to `COMPLETION:86` and `CONFIDENCE:92`.
- [x] Owner/emitter/reconstructable changes to apply recorded as none. Proof: target still keeps `CANONICAL_OWNER:00001Y`, `EMITTER_UIDS:00001Y`, `RECONSTRUCTABLE:TRUE`, and blank emitter position.
- [x] Split/rename/new-child changes recorded as none. Proof: target keeps exact range `0x00481010-0x00481056`; no file rename or new child was introduced.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes recorded. Proof: docs keep `NexusTK/social/Chatting.cpp`, no split/reclass, and no IDA DB edit was made.
- [x] First-draft C++ or no-code proof recorded. Proof: target now includes the no-code proof explaining missing caller/pointer/table/original declaration route; formal C++ remains blank.
- [x] Exact target/support doc facts to incorporate recorded. Proof: target/support docs now cite current MCP `lookup_funcs`, bytes/disassembly/decompile no-function status, xref/find no-route matrix, compact `OnMouseEvent` match, selector row-helper rejection, source-facing documentation label, and score rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence recorded. Proof: implemented docs reject stale selector-row ownership and local/offline-only provenance; they preserve no direct xref/caller/pointer/literal/table/string route and the C++ declaration blocker. Supervisor verification correction also rewrote the 2026-06-17 method-family note so the old `82/90` limitation is historical context explicitly superseded by the 2026-06-23 MCP-backed `86/92` result.
- [x] Wave2/Wave3 mentions or artifacts recorded. Proof: report treats the advanced-scan/generated label only as an alias, not owner proof; no current implementation item depended on stale Wave2/Wave3 material.
- [x] Open questions closed or documented as unresolved. Proof: original helper spelling and member/static/file-local declaration remain documented unresolved with score/C++ impact.
- [x] Validators to run after implementation recorded. Proof: scoped validators were run for each changed by-* doc from `source-3/project-documentation`.
- [x] Supervisor-owned coverage-report/tracker text recorded. Proof: exact replacement row remains in this report; B001 did not edit any `-coverage-report.md` file.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback accepted `0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md` and directed application to accepted target/support docs.
- [x] Leases acquired only immediately before editing accepted by-* files and released immediately after edit/validator batch. Proof: initial callback leased exactly `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`, `by-class/ChattingVarietyPane.md`, and `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`, then released all three successfully. Supervisor verification correction leased only `by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md`; `leaser.py B001 unlease ...` returned `Success`; `current_leases.md` then had no active B001 lease entries.
- [x] Target page updated with accepted metadata, MCP evidence, no-code proof, no-route evidence, and score rationale. Proof: target now has `86/92`, session `b880584f` evidence, boundary/padding/body details, no-route matrix, compact-button/selector rejection, blank-C++ proof, and the old 2026-06-17 `82/90` limitation rewritten as superseded historical context.
- [x] Support docs updated or explicitly marked already-present/not-applicable with proof. Proof: `by-class/ChattingVarietyPane.md` now carries the current MCP-backed compact-button helper evidence and C++ blocker; `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md` now corrects selector wording to compact-button rectangle/hit-test wording and carries the current no-route evidence; optional `by-class/ChattingVarietySelectPane.md` and `by-file/Chatting.md` were not edited because their accepted narrow facts were already present or not needed for this callback.
- [x] Formal C++ left blank unless supervisor explicitly overrides this report's no-code recommendation. Proof: no formal `RECONSTRUCTION_CPP` block was added; docs state helper-only C++ remains blocked by missing declaration route.
- [x] Coverage row left untouched unless supervisor explicitly authorizes B001 to edit it. Proof: no `-coverage-report.md` file was edited; supervisor-owned row text remains in this report for separate application.
- [x] Validators run for each changed by-* doc and results recorded. Proof: target, `ChattingVarietyPane`, and `ChattingUI` validators all exited `0` with `ok: 1`; after supervisor verification correction, the target validator was re-run and again exited `0` with `ok: 1`.
- [x] Remaining unapplied accepted items listed with exact reason or blocker. Proof: no accepted non-coverage item remains unapplied; the contradictory historical threshold note is corrected; coverage is supervisor-owned and optional support docs were not edited because already-present/not-applicable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0002FF"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002FF-ChattingVarietySelectPaneRowRectHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002FF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
