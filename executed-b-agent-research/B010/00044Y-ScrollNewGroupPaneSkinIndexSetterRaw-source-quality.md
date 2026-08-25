** TARGET-REPORT-UID:00044Y **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 00044Y ScrollNewGroupPaneSkinIndexSetterRaw Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00044Y] `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` as a reconstructable `ScrollNewGroupPane` raw no-entry setter with the existing formal no-standalone marker.
- Final disposition: no formal callable C++ body is safe for this target. The body is real source-authored code and remains owned/emitted through [UID:0000CL] `ScrollNewGroupPane`, but current IDA MCP still proves no function object, no direct xref, no pointer route, no decompilable function, no callee record, and no source-facing API route.
- Implementation callback state: Gate 1 was accepted and the accepted facts have now been incorporated into the target or verified already-present in support docs at same-or-greater detail. Supervisor execution remains valid only after Gate 2 verification of the incorporation/already-present states below.
- Confidence: strong for range, behavior, field role, owner/emitter route, and no-standalone disposition; medium-high for exact original method/API spelling because no caller/declaration route exists.

## Supporting Research

UID00044Y is already in a good implemented state, but it lacks a UID-specific executed report. Earlier B005 and B002 reports created and repaired this child as part of the parent/core or file-family work, and the generated tracker therefore still shows reports `0` for this exact UID. This report supplied current target-specific evidence, using live MCP session `31debdf2`, and the implementation callback incorporated that evidence into the target page. The tracker-zero fact does not by itself permit direct execution after Gate 1; accepted claims needed callback incorporation, exact already-present proof, or explicit exclusion before Gate 2, and the ledger below records that state.

The current evidence strengthens the field role more than UID00044Z: `+0xf8` is not merely initialized and written by a raw setter. `ScrollNewGroupPane::OnPaint` and `ScrollNewGroupPane::GetPartRect` currently read `word ptr [this+0xf8]` and index `dword_624144`, matching the project-wide `m_scrollSkinIndex` / `kScrollPanePartExtentBySkin` convention. That supports the existing field name and score. It still does not prove a callable setter API, because the raw start itself has no IDA function object or inbound route.

## Target

- Target UID: `00044Y`.
- Target path: `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` by-memory not-covered reconstructable row, `85/88`, combined `86.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: Gate 1 accepted for implementation callback / exact already-present verification; only the UID00044Y target page and this B010 report were changed during the callback.
- Current scores and parent state: target `85/88`; direct owner/emitter [UID:0000CL] `ScrollNewGroupPane` is `85/86` and routes to [UID:0000JS] `Group`, which is `90/86`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:41`.
- Existing owner/emitter/reconstructable state: correct. The raw body belongs to `ScrollNewGroupPane`; generated output routes through `ScrollNewGroupPane` to `NexusTK/social/Group.cpp`.
- Existing C++/emitter state: correct formal no-standalone marker under `NC-02`; inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank and the multiline block contains only a comment marker.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: exact original setter name and source declaration route remain unrecovered. The `m_scrollSkinIndex` field name is strong but inferred, not original-symbol proof. Historical `m_scrollStyle` wording remains an alias in older `HitTestPart` C++ and support docs.
- Related target/support docs checked: target page, [UID:0000CL] `ScrollNewGroupPane`, [UID:0000JS] `Group`, [UID:0001GP] `ScrollNewGroupPaneCore`, [UID:0003CQ] `ScrollPaneScrollbarConstantData`, sibling [UID:00044Z] target/report, and generated tracker/coverage rows.
- Current artifact/lifecycle status: this is the active B010 report artifact at `tools/leaser/Agents/Agent-B010/research/00044Y-ScrollNewGroupPaneSkinIndexSetterRaw-source-quality.md`; it has not been executed or archived.

## Executive Recommendation

Keep UID00044Y exactly attached to [UID:0000CL] `ScrollNewGroupPane`, emitted through [UID:0000CL] at position `41`, with no standalone callable C++ body. The Gate 1 implementation callback has incorporated target facts and verified support docs as already-present; supervisor execution remains a post-Gate-2 action. The target should not be renamed away from `SkinIndexSetterRaw`, should not be moved to generic `ScrollPane`, and should not be converted to a formal `SetSkinIndex` method unless a real caller, pointer route, declaration, or original source evidence is found.

## Supervisor Active Recheck

- Triggering instruction: the user first assigned Agent-B010 to produce a report-only source-quality report for UID00044Y, then accepted Gate 1 for implementation callback / exact already-present verification. The callback explicitly prohibited generated reports, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, `execute_report`, and lifecycle/archive commands.
- Split repair requirement: no split repair is required. [UID:0001GP] already splits the `ScrollNewGroupPaneCore` aggregate and lists UID00044Y as the exact raw child between padding ranges.
- Source-bearing child state: UID00044Y already exists, is reconstructable, and has a formal no-standalone marker. The only current report action is UID-specific research/coverage for this child.

## Inference Research Guidance Check

The workflow and `by-structure.md` require direct owner/emitter evidence, source-quality naming reanalysis, negative evidence, and MCP-backed proof. I treated prior B005/B002 reports as leads, not as current proof. Current MCP rechecked the raw start, pointer/xref routes, raw body, decompile/callee failure, constructor initialization, and field consumers. Wave2/Wave3/generated output was used only as supporting context and tracker state; it was not used as authority for ownership or source API shape.

## Heuristic / Inference Reanalysis And Validation

- Field role: `+0xf8` is best documented as `m_scrollSkinIndex`, with historical alias `m_scrollStyle`. Current MCP confirms constructor initialization through `mov dword ptr [esi+0F8h], 10000h`, target write/read width as a word, and consumer reads from `OnPaint` and `GetPartRect` that index `dword_624144`.
- Parameter role: the incoming word is best described as a skin-index/table-index value. A source-facing parameter name such as `skinIndex` is defensible as descriptive wording, but a formal method signature is not safe without an API route.
- No-standalone disposition: revalidated. The body is method-shaped code, but IDA has no function object at `0x005609b0`, no direct xrefs, no VA/RVA pointer-byte hits, Hex-Rays decompilation fails, and `callees` reports no function.
- Rejected stronger API: a guessed `ScrollNewGroupPane::SetSkinIndex(unsigned short skinIndex)` body would be mechanically accurate but would invent a callable source method that no current binary or support evidence proves.
- Rejected weak field names: raw `word_`/`m_trackStateWord` wording is too storage-shaped. Current consumer evidence and generic ScrollPane precedent support `m_scrollSkinIndex`.
- Rejected ownership alternatives: generic `ScrollPane` is useful sibling evidence for table naming, but target-local vtables, constructor, sibling children, and receiver fields are `ScrollNewGroupPane`. [UID:0000JS] `Group` is the file route, not the direct canonical owner.

## Evidence Standards Used

I used exact-address MCP checks first, then bounded support-doc and report searches. Direct IDA facts were required for function status, xrefs, raw instructions, bytes, decompilation/callee failure, and field-consumer instructions. Current by-* docs and generated reports were treated as documentation state. Old executed reports were treated as lead/history unless their claims were rechecked or already present in current docs.

Confidence is capped below final-audit level because the raw body has no current caller/declaration route and the exact original method spelling is unrecovered. Confidence is still strong enough to keep the current owner/field/no-code state because the field consumer and owner evidence are direct and repeated.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `insn_query`, `decompile`, `callees`, and targeted `disasm` on session `31debdf2`.
- Current MCP health: `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Raw target checks: `lookup_funcs` reports `0x005609b0`, `0x005609a1`, and `0x005609d7` are not functions; positive controls `0x00560900`, `0x00560a10`, `0x00561740`, and `0x00561420` are modeled functions.
- Xref/pointer checks: `xrefs_to 0x005609b0` returned zero xrefs; positive control `0x00560a10` returned one code xref from `0x0056cda2`; `find_bytes` for VA `B0 09 56 00` and RVA `B0 09 16 00` returned zero matches.
- Raw bytes/instructions: `get_bytes 0x005609a0 size 80` shows constructor tail/alignment, the complete target body, padding, and the successor raw setter start. `insn_query 0x005609b0-0x005609d7` returned thirteen raw instructions with no function metadata.
- Function-analysis blockers: `decompile 0x005609b0` returned `Decompilation failed at 0x5609b0`; `callees 0x005609b0` returned `No function found`.
- Field consumers: targeted disassembly found constructor `0x00560900` writing `[esi+0F8h] = 10000h`; `OnPaint` at `0x00560d40` reading `word ptr [edi+0F8h]` and `dword_624144[eax*4]`; `GetPartRect` at `0x00561740` reading `word ptr [edi+0F8h]` and `dword_624144[eax*4]`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, `ScrollNewGroupPane.md`, `Group.md`, `ScrollNewGroupPaneCore.md`, `ScrollNewGroupPaneStyleByteSetterRaw.md`, UID00044Z B012 executed report, `ScrollPaneScrollbarConstantData.md`, generated research tracker, generated memory coverage, executed B005 `0001GP`, executed B002 `0000JS`, and sibling generic ScrollPane reports discovered by search.
- Search terms used: `00044Y`, `0x005609b0`, `0x005609d7`, `ScrollNewGroupPaneSkinIndexSetterRaw`, `m_scrollSkinIndex`, `m_scrollStyle`, and `ScrollNewGroupPane`.
- Failed, unavailable, or intentionally skipped checks and why: one bounded `search_text` listing query for `0F8h` across the `ScrollNewGroupPane` band timed out; MCP remained healthy afterward, so I replaced it with narrower targeted `disasm` calls for exact functions instead of retrying a rendered-listing scan. No broad callgraph, batch analysis, or unbounded search was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00044Y is a real raw executable setter over `0x005609b0-0x005609d7`, not padding. | High | MCP bytes and `insn_query`; current target page | Target `Address Range And Boundary`, `Behavior`, `Evidence` | applied | Target now records the exact half-open range, raw/manual method status, padding boundaries, and complete raw setter evidence. |
| C2 | The body compares and writes `word ptr [ecx+0F8h]`, invalidates `this+0x44` through vtable slot `+0x20`, and returns unchanged via `retn 4`. | High | MCP `insn_query` thirteen-instruction body | Target `Behavior`, `Evidence` | applied | Target now includes the exact thirteen-instruction stream and behavior summary. |
| C3 | `lookup_funcs`, decompile, and callees confirm no function object/function analysis at `0x005609b0`. | High | MCP `lookup_funcs`, `decompile`, `callees` | Target `Evidence`, `No-Code Proof` | applied | Target now cites current session `31debdf2`, no function object, decompile failure, and callee failure. |
| C4 | There are zero direct xrefs and zero VA/RVA pointer-byte hits to `0x005609b0`. | High | MCP `xrefs_to`, `find_bytes` | Target `Evidence`, `No-Code Proof` | applied | Target now records zero xrefs, positive-control xref behavior, and zero VA/RVA pointer-byte hits. |
| C5 | Constructor packed initialization writes `0x10000` at `+0xf8`; this initializes `m_scrollSkinIndex` to zero and adjacent style/drag fields. | High | MCP disasm `0x00560900` | Target `Behavior`, `Evidence`; support already-present | applied / support already-present | Target now records `mov dword ptr [esi+0F8h], 10000h`; [UID:0000CL] `ScrollNewGroupPane.md` `Fields / Layout Notes` already records `+0xf8` as `m_scrollSkinIndex` / historical `m_scrollStyle` and `+0xfa` as adjacent scroll-style byte. |
| C6 | `OnPaint` and `GetPartRect` read `+0xf8` as a signed word index into `dword_624144`, strengthening `m_scrollSkinIndex`. | High | MCP targeted disasm; [UID:0003CQ] | Target `Behavior`, `Evidence`; support already-present | applied / support already-present | Target now records current `OnPaint` and `GetPartRect` consumer instructions; [UID:0000CL] `Method Notes` and `Fields / Layout Notes` already preserve `m_scrollSkinIndex` as primary with historical `m_scrollStyle` alias. |
| C7 | Keep owner/emitter `0000CL`, reconstructable `TRUE`, and position `41`; reject no-owner/non-emitting and direct generic scrollbar ownership. | High | Target docs, support docs, MCP locality | Target metadata, `Status`, `Rejected Alternatives`; support already-present | applied / support already-present | Target metadata remained unchanged and `Rejected Alternatives` now explicitly rejects no-owner/non-emitting and direct generic scrollbar ownership. [UID:0000CL] `Method Notes` and [UID:0000JS] `Proposed Contents` already route the no-entry setter through `ScrollNewGroupPane -> Group.cpp`. |
| C8 | Keep the formal no-standalone marker unchanged and do not emit a guessed callable setter body. | High | Negative route evidence plus current generated output | Target formal C++ block, `Status`, `No-Code Proof`; support already-present | applied / already-present | Target formal `RECONSTRUCTION_CPP CODE` header/block was left unchanged; target `No-Code Proof` now cites current negative route evidence. [UID:0000JS] `Changes` already records formal no-body/no-standalone markers for UID00044Y. |
| C9 | Keep score `85/88`; this pass reconfirms current state and explains tracker coverage but does not unlock stronger metadata/C++. | Medium-high | Score-blocker audit and current evidence | Target metadata, `Changes`; report validator state | applied | Target metadata remained `COMPLETION:85` and `CONFIDENCE:88`; target `Changes` records no score movement and why the formal marker remains. |
| C10 | Tracker reports zero because prior matching reports were parent/file-family executions, not a UID00044Y executed report. | High | Generated tracker row; executed B002/B005 report paths | Target `Status`, `Changes`; report `Validator Results` | applied | Target `Status` now records tracker reports `0` because earlier B005/B002 executions were parent/file-family executions; no report lifecycle command was run. |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: the raw body is complete source-shaped code, writes the same field that constructor initializes, and invalidates inherited pane bounds when changed.
- Corroborating documentation/generated-report evidence: current target/class/file docs already route UID00044Y through `ScrollNewGroupPane -> Group.cpp`; generated memory coverage shows the target coded through `auto-generated/NexusTK/social/Group.cpp`.
- Strongest inference chain and why it is sufficient: `ScrollNewGroupPane` constructor and sibling methods establish the receiver; `OnPaint` and `GetPartRect` consume `+0xf8` as the shared extent-table index; support constants docs identify `dword_624144` as a scrollbar extent table. This is enough to keep `m_scrollSkinIndex`, ownership, reconstructable status, and no-standalone marker.

## IDA MCP Facts

- Function/range facts: `0x005609b0`, `0x005609a1`, and `0x005609d7` are not IDA function starts; `0x00560900`, `0x00560a10`, `0x00561420`, and `0x00561740` are positive-control functions.
- Data/table/padding facts: bytes at `0x005609a0` show `0xcc` padding before target, target bytes from `0x005609b0`, `retn 4` at `0x005609d4`, padding through `0x005609df`, and successor raw setter start at `0x005609e0`.
- Xref facts: `xrefs_to 0x005609b0` returned zero; positive-control `xrefs_to 0x00560a10` found the expected code xref from `0x0056cda2`.
- Vtable/global/type facts: the target tail-jumps through `[edx+20h]` after loading `edx = [ecx]`, matching inherited primary-vtable invalidation using `this+0x44`. `OnPaint` and `GetPartRect` read `dword_624144` using the signed `+0xf8` index.
- Negative IDA facts: no function object, no direct xref, no VA/RVA pointer-byte hit, no Hex-Rays decompilation, and no callee analysis for the raw start.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005609a1-0x005609b0` | padding | alignment after constructor child | false | none | n/a | not source code |
| `0x005609b0-0x005609d7` | [UID:00044Y] target | raw `+0xf8` skin-index setter/invalidate body | true | [UID:0000CL] | `85/88` | keep formal no-standalone marker |
| `0x005609d7-0x005609e0` | padding | alignment before [UID:00044Z] | false | none | n/a | not source code |
| `0x005609e0-0x00560a04` | [UID:00044Z] sibling | raw `+0xfa` style byte setter | true | [UID:0000CL] | `85/87` | sibling no-standalone marker already covered by B012 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005609b0` | zero direct xrefs | no callable source route currently proven |
| `0x005609b0` | zero VA/RVA pointer-byte hits for `B0 09 56 00` and `B0 09 16 00` | no function-pointer/table route currently proven |
| `0x005609d0` | tail jump through `[edx+20h]` | mutation invalidates inherited bounds via primary vtable slot |
| `0x00560a10` | code xref from `0x0056cda2` | positive control proves MCP xref query worked in this family |
| `0x00560d40` / `0x00561740` | reads of `[this+0F8h]` and `dword_624144[index]` | `+0xf8` is live skin/extent-table state |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID00044Y target page already states raw no-function status, no xrefs, pointer-byte negative evidence, exact setter behavior, owner route, and no-code proof. `ScrollNewGroupPane.md` lists the method row and field alias table. `Group.md` routes the class through `NexusTK/social/Group.cpp`. [UID:0003CQ] documents the `dword_624144` table and its ScrollNewGroupPane consumers.
- Existing docs that are stale, incomplete, or contradicted: no target contradiction found. Older `m_scrollStyle` wording in [UID:0001GQ] is historical alias wording for the same `+0xf8` field; new target/support refreshes should prefer `m_scrollSkinIndex`.
- Generated/coverage report state: generated memory coverage shows UID00044Y as coded through `auto-generated/NexusTK/social/Group.cpp`; research tracker still lists UID00044Y as not-covered with reports `0`.

## Ranked Ownership Analysis

### 1. [UID:0000CL] `ScrollNewGroupPane`

- Evidence for: target lies inside the exact `ScrollNewGroupPaneCore` child sequence; receiver field offsets match the class scroll-tail block; constructor initializes `+0xf8`; class paint and rectangle methods consume `+0xf8`; current class/file docs route the child through `ScrollNewGroupPane`.
- Evidence against: no direct caller/API route to the raw start.
- Decision: keep as canonical owner and emitter. The missing route blocks standalone C++ only.

### 2. [UID:0000JS] `Group`

- Evidence for: `Group.md` is the accepted source-file route for `ScrollNewGroupPane`, and generated output emits UID00044Y in `NexusTK/social/Group.cpp`.
- Evidence against: it is a file/module route, not the direct semantic owner of the receiver state.
- Decision: keep as file route through [UID:0000CL], not as direct canonical owner.

### 3. Generic scrollbar family / [UID:0000NF] `ScrollBar`

- Evidence for: generic [UID:00042W] `ScrollPane` setter and [UID:0003CQ] constants support `m_scrollSkinIndex` and `kScrollPanePartExtentBySkin` naming.
- Evidence against: target-local constructor, vtables, field block, and surrounding functions are the `ScrollNewGroupPane` / `NewGroupPane` path, not generic `ScrollPane`.
- Decision: use only as sibling/source-family evidence. Reject as direct owner/emitter.

### 4. No-owner / non-emitting

- Evidence for: would avoid source API overclaiming.
- Evidence against: contradicts a real executable body, valid class route, generated marker handling, and live field consumers.
- Decision: reject. The target is reconstructable and routed; it is no-standalone, not no-owner.

## Source Placement

Recommended placement remains `ScrollNewGroupPane` under `NexusTK/social/Group.cpp`, emitted through [UID:0000CL] at position `41` with a formal comment-only marker. This matches current class/file docs and generated output. Do not move this target to `ScrollBar.cpp` or a shared scrollbar source file without a broader source-tree reconciliation proving the original developers factored this `NewGroupPane` scrollbar setter out of the group pane source route.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target half-open range is `0x005609b0-0x005609d7`; predecessor padding is `0x005609a1-0x005609b0`; successor padding is `0x005609d7-0x005609e0`; successor raw setter begins at `0x005609e0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. The split already exists and is correct.
- Padding/table/data/code distinctions: target bytes are code; surrounding `0xcc` bytes are alignment/padding. `dword_624144` is external constant-data support, not part of this target range.
- Parent/container impact: [UID:0001GP] remains a non-emitting split index. No parent metadata change is recommended.

## Negative Evidence Summary

- No IDA function object exists at `0x005609b0`.
- No direct xrefs point to `0x005609b0`.
- No VA/RVA pointer-byte route to `0x005609b0` was found.
- Hex-Rays cannot decompile `0x005609b0`, and `callees` cannot analyze it as a function.
- No support doc proves an original source-facing setter name, access level, declaration, vtable slot, callback table, or direct caller.
- Consumer/read evidence for `+0xf8` proves the field role, not the existence of a callable setter API.
- Prior B002/B005 reports are useful history, but they were executed for parent/file-family targets and do not satisfy UID00044Y tracker coverage.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: prefer `m_scrollSkinIndex` for `+0xf8`; preserve `m_scrollStyle` only as historical alias wording where older accepted C++ already uses it. If a target comment is refreshed, call the raw body a no-entry `ScrollNewGroupPane` skin-index setter and record that it is not a proven callable API.
- Evidence for each proposed name/type/comment: current MCP reads from `OnPaint` and `GetPartRect` index `dword_624144`; [UID:0003CQ] and generic ScrollPane reports use `m_scrollSkinIndex` / extent-table naming for the same source-family role.
- Items intentionally left unchanged and why: do not recommend an IDA function rename at `0x005609b0` because IDA does not model it as a function. Do not recommend a formal method name because no caller/declaration route is proven.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. This report is documentation-only and should not change the IDA DB.

## First-Draft C++ Recommendation

- Eligible for draft C++: no callable body.
- Recommended code: no new C++ and no new marker insertion text. The existing target formal `RECONSTRUCTION_CPP CODE` header/block remains unchanged; the inline code value stays blank and the current comment-only no-standalone marker remains the target's formal block if supervisor verification finds it already present at same-or-greater detail. This report intentionally does not provide standalone report-only marker text.

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the generated source does not invent a callable method for a raw no-entry body; the marker preserves coverage while exact behavior remains documented in the target page.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a raw body without function metadata or any caller route should not be surfaced as a confident source API. Source-facing field naming can be documented separately without inventing a method declaration.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_scrollSkinIndex`, `skinIndex` as descriptive parameter wording only, `InvalidateRect`, and `m_bounds`.
- Naming/coding style convention used and evidence for consistency: `m_scrollSkinIndex` matches current `ScrollNewGroupPane`, `ScrollPane`, `ScrollCollectionPane`, and constants-page support wording for the `+0xf8` extent-table index.
- Reason code should remain blank, if applicable: current MCP proves no function object, no xref, no pointer route, decompile failure, and no callee record for the raw start.
- Exact no-code proof, if not eligible: `NC-02-current`: live MCP session `31debdf2` proves UID00044Y is a real raw `ScrollNewGroupPane` word setter over `+0xf8`, with exact compare/write/invalidate/no-change behavior and byte-verified padding boundaries. Current MCP also proves no function object, no direct xref, no VA/RVA pointer route, no decompilable function, no callee record, and no source declaration route. Constructor, `OnPaint`, `GetPartRect`, and constants evidence prove `+0xf8` is source-relevant `m_scrollSkinIndex` state, but not a callable setter API. A guessed `ScrollNewGroupPane::SetSkinIndex` body would invent unsupported source shape.

## Final Recommendation

- Exact changes applied or recommended: implementation callback incorporated current MCP evidence, negative route proof, rejected alternatives, field-role caveats, and tracker-zero explanation into UID00044Y. The existing metadata and no-standalone marker were preserved unchanged.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:0000CL`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:41`.
- Exact items left no-owner/non-emitting and why: none. Surrounding padding remains non-source; UID00044Y remains reconstructable/routed.
- Exact future work, if any, outside this assignment scope: whole-class declaration normalization may eventually reconcile historical `m_scrollStyle` spelling in older C++ blocks, but that is broader class/source-tree work and not needed for this target's Gate 2 callback.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md`.
- Exact report facts incorporated: current MCP session `31debdf2`; no function object at `0x005609b0`; zero xrefs; zero VA/RVA pointer-byte hits; exact thirteen-instruction compare/write/invalidate body; decompile failure; callee failure; constructor packed initialization; `OnPaint`/`GetPartRect` `+0xf8` consumers; generated tracker reports `0` because earlier reports were parent/file-family executions.
- Metadata/score/owner/emitter/reconstructable/C++ changes: keep `85/88`, owner/emitter `0000CL`, reconstructable `TRUE`, position `41`, and current no-standalone marker.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B005/B002 are historical lead/implementation reports; generic `ScrollPane::SetSkinIndex` is sibling evidence, not direct ownership/API proof; `m_scrollStyle` is historical alias wording; guessed callable API remains rejected.

## Recommended Support Doc Changes

- Support path: `by-class/ScrollNewGroupPane.md`.
- Exact report facts already present: no edit required. Exact section proof: `Method Notes` row for UID00044Y already states this raw setter updates `m_scrollSkinIndex` / historical `m_scrollStyle` and has a formal no-standalone marker because no function object, xref, pointer route, or original method name proves a callable source API. `Fields / Layout Notes` already records `+0xf8` as `m_scrollSkinIndex` / historical `m_scrollStyle`, names `m_scrollSkinIndex` as the preferred support alias, and ties it to the shared fixed-extent table at `dword_624144`.
- Metadata/link/score/coverage/source-placement changes: none.
- Support path: `by-file/Group.md`.
- Exact report facts already present: no edit required. Exact section proof: `Proposed Contents` routes `ScrollNewGroupPane` through `NexusTK/social/Group.cpp` and states raw no-entry setter rows carry formal no-standalone markers rather than invented APIs; `Changes` records the Group empty-emitter implementation where UID00044Y carries a formal no-body/no-standalone marker.
- Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner `0000CL`, reconstructable `TRUE`, emitter `0000CL`, position `41`.
- Recommended score/metadata: keep `85/88`, owner `0000CL`, reconstructable `TRUE`, emitter `0000CL`, position `41`.
- Score rationale and reason not higher/lower: not higher because no new caller, pointer route, original name, source declaration, decompilable signature, or safe formal method API was found. Not lower because current MCP reconfirms exact body, boundaries, live field consumers, class route, and generated no-standalone marker coverage.
- Score-improvement attempt: checked every current score blocker in scope: raw-start function status, xrefs, pointer route, decompile/callee route, field consumers, owner route, support docs, prior reports, and generated tracker state. The result is an exact evidence-backed no-improvement proof for score/C++ movement, not future-work deferral.
- Metadata fields to change or leave unchanged: leave all target metadata unchanged. The tracker report count should change only after normal supervisor-owned execution, and execution is allowed only after Gate 1 plus Gate 2 verification that accepted claims were incorporated, already present at same-or-greater detail with exact section proof, or explicitly excluded.

## Open Questions With Attempted Resolution

- Open questions found: exact original setter/API name; exact source declaration/access route; whether current target should emit formal callable C++; why tracker reports zero.
- Evidence checked for each: function object, xrefs, pointer bytes, decompile/callees, target/class/file docs, generic ScrollPane sibling reports, constants doc, generated coverage, and executed report search.
- Best supported resolution or inference: field role is resolved to `m_scrollSkinIndex`; owner/emitter route is resolved to `ScrollNewGroupPane -> Group.cpp`; no-code disposition remains correct; tracker zero is explained by lack of UID00044Y-specific executed report.
- Questions remaining unresolved, evidence-backed reason, score/C++ impact, and unavailable future evidence: original setter/API name and declaration remain unresolved because all current route evidence is absent. This blocks formal method C++ and caps score, but does not block owner/reconstructable/field-name confidence. Future evidence would need a real caller, pointer table, source declaration, PDB/source artifact, or reliable original naming evidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Applicable only when an explicit manual `-coverage-report.md` or supervisor-owned tracker row needs a change: not applicable.
- File/placement: none.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: generated research tracker and generated coverage are validator-owned. Supervisor-owned `execute_report` should update report coverage only after Gate 1 validation and Gate 2 incorporation/already-present/exclusion verification.

## Follow-Up Actions

- Supervisor actions: run Gate 1 recheck on this repaired report artifact. If Gate 1 passes, proceed to Gate 2 verification of the already-completed implementation callback, including the applied/already-present ledger states, scoped validator result, historical B010 manual stats-restore incident, and supervisor rescore repair command `000000005301`; run supervisor-owned `execute_report` only if both Gate 1 and Gate 2 pass.
- A-agent actions: none.
- B010 future research actions: none unless supervisor returns this same report for further report-text repair or sends a Gate 2 callback-repair request.

## Confidence

- Recommendation confidence: high for keeping current owner/emitter/no-standalone state.
- Score confidence: medium-high for unchanged `85/88`; new current MCP proof is strong, but API route absence still caps final C++ confidence.
- Remaining uncertainty: exact original setter name/declaration and future whole-class alias normalization for `m_scrollSkinIndex` versus historical `m_scrollStyle`.

## Validator Results

- Command run: `python .\tools\validator.py --mode file --file by-memory\0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md --apply --queue-timeout 240` from `source-3/project-documentation`.
- Command metadata: `command_id: 000000005282`; `command_timestamp: 2026-07-03T09:44:15-04:00`; exit code `0`; `ok: 1`; scanned markdown files `1`.
- Validator messages: `projected_stats_update: 1`; `stats_incremental_noop: 1`; `stats_incremental_noop 00044Y project-level/-auto-completion-stats.md file is not present in generated stats lists`.
- Generated refresh status: `generated_refresh: deferred`; `generated_refresh_command_id: 000000005282`; `generated_refresh_timestamp: 2026-07-03T09:44:15-04:00`.
- Historical role-boundary incident: validator command `000000005282` updated `project-level/-auto-completion-stats.md`, then B010 manually ran `git restore -- project-level/-auto-completion-stats.md` from `source-3/project-documentation` after the scoped validator completed. The exact restore command timestamp was not separately captured, but it occurred before this report's `2026-07-03 09:47:23 -04:00` last-write time. This manual project-level generated-file revert/removal exceeded B-agent write scope.
- Supervisor-owned generated/project-level repair: supervisor then repaired generated/project-level state through documented validator tooling from `source-3/project-documentation` with `python .\tools\validator.py --mode rescore --apply --queue-timeout 240`; `command_id: 000000005301`; `command_timestamp: 2026-07-03T09:52:12-04:00`; result `stats_update: 1`; `project-level/-auto-completion-stats.md updated completion/confidence stats`; `generated_refresh: deferred`.
- Any unresolved validator warnings/errors: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B010/research/00044Y-ScrollNewGroupPaneSkinIndexSetterRaw-source-quality.md`.
- Modified: `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` and this B010 research report.
- Support docs reviewed but not modified: `by-class/ScrollNewGroupPane.md`, `by-file/Group.md`.
- Supervisor-owned generated/project-level repair context: `project-level/-auto-completion-stats.md` was repaired by supervisor command `000000005301` (`python .\tools\validator.py --mode rescore --apply --queue-timeout 240`) after the historical B010 manual restore incident.
- Renamed: none.
- Leases: acquired only `by-memory/0x005609b0-0x005609d7.ScrollNewGroupPaneSkinIndexSetterRaw.md` before edit; released immediately after scoped validation. No support-doc lease was needed.
- Report execution: not run. No `tools/validator.py execute_report`, archive/lifecycle command, or manual report move was run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation callback; supervisor execution is allowed only after Gate 2 verification.
- [x] Target/support docs to update or verify as already present: target refresh required; support docs reviewed as already-present.
- [x] Current target state and actual evidence checked recorded: current MCP session `31debdf2`, exact raw body, negative route checks, constructor initialization, field consumers, and report-history search terms.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: none; keep `85/88`, owner/emitter `0000CL`, reconstructable `TRUE`, position `41`.
- [x] Score-limiting blockers researched to resolution: no function object, xref, pointer route, decompile/callee record, source declaration, or API route found; field consumer evidence confirms current name but does not unlock C++.
- [x] Owner/emitter/reconstructable changes to apply: none; explicitly reject no-owner/non-emitting, direct `Group` ownership, and generic scrollbar direct ownership.
- [x] Split/rename/new-child changes to apply: none; exact range already split and bounded.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: keep `ScrollNewGroupPane -> Group.cpp`; no IDA DB edits.
- [x] First-draft C++ or no-code proof to apply or verify: existing target formal no-standalone marker remains unchanged; no callable setter and no standalone report-only marker snippets.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate or verify as already present at report-level detail: current MCP evidence, no-code proof, score/no-improvement rationale, and tracker-zero explanation.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B005/B002 as history, rejected guessed API/no-owner/generic owner, historical `m_scrollStyle` alias, and negative route evidence.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: stale generated/source-route material was not used as authority; current by-* docs and MCP control.
- [x] Open questions closed or documented as evidence-backed unresolved: original setter/API name remains unresolved; exact field role is resolved as `m_scrollSkinIndex`; impact on C++/score documented.
- [x] Validator run after by-* edit: scoped validator command `000000005282`, exit code `0`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual coverage text; no lifecycle command run; generated refresh is deferred for supervisor execution after Gate 2.

Implementation callback pass:
- [x] Target metadata verified unchanged: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:41`.
- [x] Existing formal no-standalone marker verified unchanged; no guessed callable setter body emitted.
- [x] Target incorporated current MCP session `31debdf2`, no function object, zero xrefs, zero VA/RVA pointer-byte hits, exact compare/write/invalidate body, decompile failure, callee failure, constructor packed initialization, `OnPaint` / `GetPartRect` `+0xf8` consumers, and tracker-zero explanation.
- [x] Target preserved rejected alternatives and caveats: guessed `ScrollNewGroupPane::SetSkinIndex` API rejected; no-owner/non-emitting rejected; direct generic scrollbar ownership rejected; `m_scrollStyle` historical alias retained; `m_scrollSkinIndex` retained as strongest source-facing field role.
- [x] `by-class/ScrollNewGroupPane.md` reviewed and not edited because `Method Notes` and `Fields / Layout Notes` already contain the report-level field/no-entry proof and primary `m_scrollSkinIndex` wording with alias caveat.
- [x] `by-file/Group.md` reviewed and not edited because `Proposed Contents` and `Changes` already contain no-entry setter/formal marker routing through `Group.cpp`.
- [x] Lease acquired only for the target page, then released after validation.
- [x] No by-* docs other than the target were edited; no generated reports, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers were intentionally modified; no `execute_report` or lifecycle/archive command was run.
- [x] Supervisor repair resolved: B010 manually ran `git restore -- project-level/-auto-completion-stats.md` after the validator-owned project-level stats side effect; supervisor repaired generated/project-level state with rescore command `000000005301` at `2026-07-03T09:52:12-04:00` (`stats_update: 1`, `generated_refresh: deferred`).

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000005316","destination_path":"executed-b-agent-research/B010/00044Y-ScrollNewGroupPaneSkinIndexSetterRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00044Y-ScrollNewGroupPaneSkinIndexSetterRaw-source-quality.md","timestamp":"2026-07-03T10:34:35-04:00","uid":"00044Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
