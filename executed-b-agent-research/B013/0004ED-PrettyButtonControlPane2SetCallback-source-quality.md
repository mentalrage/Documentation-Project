** TARGET-REPORT-UID:0004ED **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004ED PrettyButtonControlPane2SetCallback Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: promote [UID:0004ED][0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback](by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md) from a blank child to an emitting `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` method through [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md).
- Final disposition: source-authored `PrettyButtonControlPane2` method child, still not IDA-modeled as a function, but exact bytes/instructions, class2 constructor/destructor/click behavior, sibling class1 setter, and shared FunctionObjects documentation are sufficient for first-draft formal C++.
- Required action after supervisor approval: update only the target doc unless support verification during callback finds directly stale text; set `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000AS`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AS`, leave `EMITTER_POSITION_OPTIONAL` blank unless validator/by-structure requires an ordering value, and insert the formal C++ body below.
- Confidence: high for behavior, owner, source placement, and callback-family type direction; still below final-source confidence because no original method/type symbol is recovered and the raw start has no direct xrefs.

## Supporting Research
- Assignment: `B013-report-0004ED-PrettyButtonControlPane2SetCallback-20260702`.
- Report path: `tools/leaser/Agents/Agent-B013/research/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md`.
- Initial research pass was report-only. Supervisor callback on 2026-07-03 accepted target/support by-* implementation for UID0004ED only; B013 edited the target and directly stale class support doc, ran scoped validators, and did not run any report lifecycle/archive command.
- MCP availability: `idb_list` initially listed stale session `b010_0002r7_20260702`; `server_health` for it returned `Session not found`. Per assignment, `idb_open` was used for the canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; MCP adopted ready session `b011_0004EC_20260702`.
- Active MCP health from `idb_open` warmup: status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

## Target
- Target UID: `0004ED`
- Target path: `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md`
- Target title/range: `0x0054ba00-0x0054ba24 PrettyButtonControlPane2 SetCallback`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Queue row at assignment/current read-only check: `83/88`, average `85.5`, reconstructable `true`, B reports `0`.
- Current source module context: [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) / `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Current Target State
- Existing metadata: `COMPLETION:83`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing summary: non-modeled `PrettyButtonControlPane2` callback replacement child split from UID0001F9; prior callback released through `this+0x128`, new argument stored at `this+0x128`.
- Existing blocker: formal C++ blank until callback type and ownership helper names are accepted.
- Direct parent/support state: [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md) is `87/89`, reconstructable, owner/emitter [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md); [UID:0000MP] is `87/89` with path `NexusTK/ui/controls/`.
- Current generated state: `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` header shows validator-command-id `000000004924`, refreshed `2026-07-02T19:12:14-04:00`. It currently contains empty emitter markers for [UID:0000AR], [UID:0002UW], [UID:0000AS], and [UID:0002UX], plus scalar deleting destructor marker [UID:0004EL]; UID0004ED does not appear because its emitter is blank.

## Heuristic / Inference Reanalysis And Validation
- Function shape: `0x0054ba00-0x0054ba24` is a non-modeled but complete source method body. It has a normal prologue/epilogue, one explicit argument, `retn 4`, and exact behavior matching the modeled class1 sibling setter at `0x0054b720-0x0054b744`.
- Callback storage: the complete-object field is `this+0x128` / decimal `296` (Verified with `int_convert.py`). Constructor decompile initializes `*(this+296)=0`. Destructor-body disassembly releases the same field before string/object cleanup. Setter disassembly releases the old value and stores the new value.
- Callback type: the old pointer is released via vtable slot `+0x00` with scalar-delete flag `1`; `OnClick` invokes the same logical field through virtual slot `+0x0c` with no payload arguments. Project-wide FunctionObjects documentation defines `FunctionObject0` as the zero-argument callback base with `Invoke()` and virtual destructor. Therefore `FunctionObject0 *callback` is a defensible first-draft type, stronger than a pane-local invented `PrettyButtonCallback` type and more specific than `void *`.
- Adjusted-this validation: `PrettyButtonControlPane2::OnClick` decompiles as reading `this[33]` / offset `+0x84`, while the setter/destructor use complete-object offset `+0x128`. The vtable data records tertiary/secondary adjusted views at `+0xa4`/`+0xa0`; `0xa4 + 0x84 = 0x128`, so the apparent offset mismatch is a multiple-inheritance adjusted receiver artifact, not a different field.
- Method name: `SetCallback` is not a recovered original symbol, but it is the best source-facing documentation and draft-C++ name. It matches existing class docs, file docs, the class1 sibling page [UID:0004E6], and the exact behavior: delete/replace an owned callback object. Rejected alternatives: `SetClickCallback` is more descriptive but not used by current docs; `SetAction`, `SetHandler`, and raw `sub_54BA00` are weaker because they either lose the established class-family naming or preserve synthetic IDA naming.
- Source-level return type: decompiler-style `int` return is not source-quality. The body leaves the new pointer in `eax` as a byproduct of loading/storing the argument, but setter callers are not recovered and the source shape is a mutator. `void` is the most plausible original source type; it still preserves binary behavior because the caller-visible return is unused/unproven.
- No rare no-improvement exception applies. The old blocker "callback type and ownership helper names" was investigated through target/sibling instructions, constructor/destructor/click behavior, shared FunctionObjects docs, type/name catalog, and PE/IDA reachability checks. A conservative `FunctionObject0 *` draft is now safe enough for first-draft formal C++.

## Evidence Standards Used
- Direct IDA/MCP facts were preferred for range, bytes, disassembly, modeled/non-modeled status, xrefs, decompile artifacts, vtable/adjusted-this interpretation, and type/name searches.
- Documentation evidence was used only after checking it against current MCP facts: target/support docs, class/file docs, vtable-data pages, FunctionObjects docs, generated C++ state, and executed B011 split report.
- Negative evidence includes no direct xrefs, no VA pointer bytes, no direct `E8/E9` branch hits, no recovered PrettyButton UDT/type, and no original method symbol.
- The source-quality inference is considered first-draft, not final-source proof. Scores and confidence stay below 95 because exact original declarations are not recovered and the raw start remains outside IDA's function model.

## Evidence Checked
- Required reading: `tools/leaser/Agents/Agent-B013/goal.md`, project `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, `score-blocker-audit-standard.md`, and `by-structure.md` `IDA MCP Output Discipline`.
- Target/support docs read: UID0004ED target; parent split/index [UID:0001F9]; [UID:0000AS][PrettyButtonControlPane2](by-class/PrettyButtonControlPane2.md); [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md); [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md); vtable child [UID:0002UX]; sibling setter [UID:0004E6]; class2 constructor [UID:0004EA]; class2 destructor body [UID:0004EB]; FunctionObjects docs [UID:00005K], [UID:0001WQ], [UID:0000JO].
- Old report search terms: `0004ED`, `0x0054ba00`, `PrettyButtonControlPane2SetCallback`, `PrettyButtonControlPane2 SetCallback`, `PrettyButtonControlPane2`, `SetCallback`, `0001F9`, `0000AS`, `0000MP`, and callback/source-family terms.
- Relevant old report: `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`, used as historical split evidence only. It created UID0004ED and documented the raw span as callback replacement, but left child source-quality/C++ decisions for later.
- MCP calls used: `idb_list`, `idb_open`, `tools/list`, `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `decompile`, `callees`, `basic_blocks`, `type_query`, `entity_query`, and `int_convert`. Calls were exact-address or bounded/paged.
- MCP lookup results: `0x0054ba00`, `0x0054ba24`, and `0x0054b9e0` are not functions; successor `0x0054ba30` is `sub_54BA30`, size `0x62`; sibling setter `0x0054b720` is `sub_54B720`, size `0x24`.
- MCP target `insn_query` over `0x0054ba00-0x0054ba24`: 15 instructions, no function object, `mov ecx,[esi+128h]`, null-check, `mov eax,[ecx]`, `push 1`, `call dword ptr [eax]`, `mov eax,[ebp+8]`, `mov [esi+128h],eax`, `retn 4`.
- MCP bytes: pre-padding `0x0054b9f9-0x0054ba00` is seven `0xcc` bytes; target bytes are `55 8b ec 56 8b f1 8b 8e 28 01 00 00 85 c9 74 06 8b 01 6a 01 ff 10 8b 45 08 89 86 28 01 00 00 5e 5d c2 04 00`; post-padding `0x0054ba24-0x0054ba30` is twelve `0xcc` bytes.
- MCP xrefs: no xrefs to `0x0054ba00` or `0x0054ba24`; sibling `0x0054b720` has two code xrefs from `sub_52A540` at `0x0052a907` and `0x0052a9b0`.
- MCP decompile: `0x0054ba00` decompilation failed because no function is modeled. `callees` reports `No function found`; `basic_blocks` reports `Function not found`.
- MCP sibling decompile: `sub_54B720(_DWORD *this, int a2)` releases `this[73]` through `(**v3)(v3,1)`, stores `a2`, and returns it. Its disassembly is the same 15-instruction pattern at offset `+0x124`.
- MCP constructor decompile: `sub_54B8C0` initializes frame/resource fields, stores all three class2 vtables, initializes strings, writes state byte, and sets `*(this+296)=0`.
- MCP destructor-body `insn_query`: `0x0054b990-0x0054b9db` resets all three class2 vtables, reads `ecx=[esi+128h]`, releases it via slot zero with `push 1`, cleans fields at `+0x124` and `+0x120` through `sub_582B70`, then jumps to `sub_544580`.
- MCP click decompile/disassembly: `sub_54BB50` schedules a 150 ms action through `sub_5975E0`, reads adjusted field `[esi+84h]`, and if non-null calls virtual slot `+0x0c` with no arguments. Class1 `sub_54B880` is the same pattern at adjusted field `[esi+80h]`.
- MCP type/name checks: `type_query '*PrettyButton*'` found no recovered PrettyButton UDT/declaration; `type_query '*Callback*'` found system/import callback typedefs only. `entity_query` found PrettyButton RTTI/vtable names but no `SetCallback` or project callback type symbol.
- Local read-only PE scan: no absolute VA pointer encodings to `0x0054ba00` or `0x0054ba24`, no direct `E8/E9` branches to either, no RVA encoding for `0x0054ba24`. RVA bytes for `0x0054ba00` appear at `0x004cfbae`, `0x004cfbd6`, `0x004cfbfe`, and `0x004f9cbb`, but scoped disassembly shows unrelated `0x14` immediates, not address references.
- Numeric conversions: `0x24` = 36 bytes, `0x0c` = 12 bytes, `0x07` = 7 bytes, `0x128` = 296 bytes (Verified with `int_convert.py`).

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| ED-C01 | UID0004ED is a source-authored `PrettyButtonControlPane2` method child, not padding or compiler glue. | High | 15-instruction setter body; constructor/destructor/click use same field; sibling setter analogy. | Target Evidence / Ownership And C++ Policy; class Exact Child Pages | incorporate | applied: target now documents raw body/source-method proof; class row identifies UID0004ED as source method child. |
| ED-C02 | Metadata should move from `83/88` to `88/90`, keep owner `0000AS`, keep reconstructable true, and set `EMITTER_UIDS:0000AS`. | Medium-high | Parent/class/file gates clear; behavior and type direction resolved; no direct xrefs still cap confidence. | Target metadata and Score Rationale | incorporate | applied: target metadata is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AS`; validator `000000004959` confirmed completion/confidence and registry updates. |
| ED-C03 | Formal C++ should be inserted as `void PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)`. | Medium-high | FunctionObject0 template docs; slot `+0x0c` zero-arg invoke; slot `+0x00` virtual destructor release; setter body exact. | Target formal `RECONSTRUCTION_CPP` block | incorporate | applied: target formal block contains the accepted `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` body; generated `PrettyButtonControlPane.cpp` header `000000004967` contains UID0004ED body. |
| ED-C04 | Field name should be documented as inferred `m_callback` at complete-object offset `+0x128` / decimal 296. | High | Constructor zero store, destructor release, setter replacement, adjusted click read mapping. | Target Evidence/Reconstruction Notes and support class doc if stale | incorporate | applied: target Evidence and Ownership/C++ Policy document inferred `m_callback` and complete-object `+0x128`; class Evidence Notes records owned `FunctionObject0` pointer at `+0x128`. |
| ED-C05 | `SetCallback` is an inferred but accepted documentation/source-facing method name; reject raw `sub_54BA00` and pane-local callback interface names. | Medium-high | Existing docs use SetCallback; sibling class1 setter; no recovered original symbol. | Target naming/source-quality notes | incorporate | applied: target Ownership And C++ Policy documents inferred `SetCallback`, `m_callback`, `FunctionObject0 *`, and rejected alternatives. |
| ED-C06 | No direct call/xref/pointer route is recovered for the raw start and must remain a caveat. | High | MCP `xrefs_to`; PE VA/RVA/rel32 scan; IDA raw non-function state. | Target Negative Evidence/Score Rationale | incorporate | applied: target Evidence and Score Rationale preserve no-xref/no-PE-route/no-IDA-function caveats. |
| ED-C07 | Parent/source placement remains class [UID:0000AS] under file [UID:0000MP] `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; reject file-direct, ButtonControlPane, CreateUser dialog, no-owner, and generated/callsite ownership. | High | Class2 vtables, constructor/destructor/click methods, source-file docs, dependency/caller analysis. | Target ownership/source-placement notes | already-present plus incorporate | applied: target Ownership And C++ Policy records class owner/emitter, file placement, and rejected alternatives; class support row points UID0004ED through class ownership. |
| ED-C08 | Split/range facts should be preserved exactly: pre-padding `0x0054b9f9-0x0054ba00`, target `0x0054ba00-0x0054ba24`, post-padding `0x0054ba24-0x0054ba30`, successor `sub_54BA30`. | High | MCP `lookup_funcs`, `get_bytes`, `insn_query`, int conversions. | Target Range/Split/Padding notes | incorporate | applied: target Evidence and Range / Split Notes preserve exact body, padding, and successor UID0004EE. |
| ED-C09 | Support docs are mostly sufficient but should be verified for stale "C++ blank pending callback type" wording after this report; edit only directly stale target/support text during callback. | Medium-high | Current class/file docs list child and current blocker; new report resolves blocker for UID0004ED only. | `by-class/PrettyButtonControlPane2.md`, `by-file/PrettyButtonControlPane.md`, optional sibling notes | incorporate if stale, otherwise already-present | applied: class support stale row was applied and validated by `000000004962`; by-file support now documents UID0004ED `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)`, raw `sub_54BA00` / `0x0054ba00-0x0054ba24`, `this+0x128` callback slot, old-callback cleanup/replacement, create-user caller/consumer context, FunctionObjects route, and rejected raw/blank-emitter dispositions; validator `000000004992` passed. |
| ED-C10 | No IDA DB rename/type/function-definition edit should be part of this report-only callback; defining the raw start as a function is not required for documentation/source emission. | High | Raw body is documented; MCP decompile/basic-block failures are IDA-model limitations; assignment forbids IDA DB edits. | Target evidence/implementation checklist | not-applicable | excluded-with-reason: no IDA DB edit, function definition, or external lifecycle command was requested or run; target documents raw non-function state as an IDA-model limitation. |

## Positive Evidence Summary
- The body is exact, compact, and source-shaped: replace an owned callback pointer after deleting the old object.
- The constructor initializes the field to null, destructor releases it, setter replaces it, and click invokes it through a zero-argument virtual slot.
- The class1 sibling setter is modeled by IDA at `0x0054b720` and has the same body at offset `+0x124`; class2 uses `+0x128`.
- The shared FunctionObjects pages already define `FunctionObject0` and document the same destructor/invoke slot convention used by other zero-argument callback consumers.
- Parent [UID:0000AS] and file [UID:0000MP] already clear the current score gate, so the child can emit through the direct class route after callback.

## IDA MCP Facts
- Active session: `b011_0004EC_20260702`; health ok via `idb_open` warmup.
- `lookup_funcs`: target start/end not functions; successor `0x0054ba30` modeled size `0x62`; sibling class1 setter `0x0054b720` modeled size `0x24`.
- Target instructions: 15 instruction non-modeled body from `0x0054ba00` through `retn 4` at `0x0054ba21`.
- Target bytes: 36-byte body, seven bytes of `0xcc` pre-padding, twelve bytes of `0xcc` post-padding.
- Xrefs: zero xrefs to `0x0054ba00` and `0x0054ba24`; class1 sibling setter has two code xrefs from `sub_52A540`.
- Decompiler/model limits: target decompile failed, callees returned no function, basic blocks returned no function.
- Constructor fact: class2 constructor writes `*(this+296)=0`.
- Destructor fact: class2 destructor body releases `[esi+128h]` through virtual slot zero with scalar delete flag `1`.
- Click fact: class2 click reads adjusted `[esi+84h]` and invokes virtual slot `+0x0c`; adjusted view explains complete-object `+0x128`.
- Type/name facts: no PrettyButton UDT/type declaration and no recovered `SetCallback` symbol; RTTI/vtable names for PrettyButton classes are present.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b9f9-0x0054ba00` | parent inventory only | `0xcc` padding after state-byte forwarder | false | none | n/a | preserve as padding |
| `0x0054ba00-0x0054ba24` | [UID:0004ED][by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md](by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md) | `PrettyButtonControlPane2::SetCallback` owned callback replacement | true | [UID:0000AS] | current `83/88`; recommended `88/90` | emit first-draft C++ |
| `0x0054ba24-0x0054ba30` | parent inventory only | `0xcc` padding before visual-state method | false | none | n/a | preserve as padding |
| `0x0054ba30-0x0054ba92` | [UID:0004EE][by-memory/0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState.md](by-memory/0x0054ba30-0x0054ba92.PrettyButtonControlPane2SetVisualState.md) | successor visual state / animation scheduling | true | [UID:0000AS] | current sibling | no split change |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0054ba00` | `xrefs_to`: none | no recovered direct call/data xref to raw setter start |
| `0x0054ba24` | `xrefs_to`: none | no endpoint/ref evidence |
| `0x0054b720` | two code xrefs from `sub_52A540` at `0x0052a907`, `0x0052a9b0` | class1 sibling setter is directly called; UID0004ED likely has weaker/unrecovered reachability |
| `0x0054bb50` | click method invokes callback slot `+0x0c` after `sub_5975E0` | proves stored pointer is a zero-argument callback object |
| `0x0054b990-0x0054b9db` | destructor body releases `this+0x128` then cleans adjacent fields | proves ownership/release semantics for same field |

## Documentation Evidence And IDA Status
- Existing UID0004ED target correctly states callback replacement at `this+0x128` but is under-documented and still blank because callback type was unresolved.
- [UID:0000AS] class doc lists UID0004ED as source method child and currently says C++ is blank pending callback type.
- [UID:0000MP] file doc lists UID0004ED as a callback replacement child in `PrettyButtonControlPane.cpp`.
- [UID:0002UX] vtable data confirms class2 vtable views and slot targets for draw/state/click/destructor, supporting class ownership.
- FunctionObjects docs provide the missing callback-family type direction: `FunctionObject0` for zero-argument callback objects with virtual destructor and `Invoke()`.
- Generated `PrettyButtonControlPane.cpp` does not include UID0004ED because its emitter is blank; after callback validation, generated output should include the new method body or at least no longer omit UID0004ED for blank-emitter reasons.

## Ranked Ownership Analysis

### 1. [UID:0000AS] PrettyButtonControlPane2
- Evidence for: target is in class2 method island; class2 constructor initializes `+0x128`, destructor releases it, click invokes it; class2 vtables and class docs already own the surrounding methods; parent clears `87/89`.
- Evidence against: target has no direct xrefs and no IDA function object.
- Decision: accept as direct owner and emitter.

### 2. [UID:0000MP] PrettyButtonControlPane file
- Evidence for: file owns both PrettyButton classes and source placement under `NexusTK/ui/controls/`; class [UID:0000AS] emits through this file.
- Evidence against: by-structure direct owner should be the class for a class method; file-direct ownership would skip the class route.
- Decision: keep as source module/context, not direct owner.

### 3. [UID:0000HY] ButtonControlPane
- Evidence for: constructor calls the generic base control constructor and the method participates in button behavior.
- Evidence against: base class dependency does not own derived callback field; PrettyButton class/vtable/source docs are stronger.
- Decision: reject as dependency-only support.

### 4. CreateUser dialog caller family
- Evidence for: class2 constructor has two caller refs from CreateUser construction code; class1 sibling setter has caller refs in `sub_52A540`.
- Evidence against: caller/consumer evidence does not own reusable styled-button method code; no direct xref to UID0004ED was recovered.
- Decision: reject feature-caller ownership.

### 5. FunctionObjects source family
- Evidence for: callback object type and release/invoke conventions come from FunctionObjects.
- Evidence against: FunctionObjects owns reusable callback declarations and concrete callback wrappers, not this PrettyButton field setter.
- Decision: reject as direct owner; use as type/support evidence.

### 6. No-owner / non-emitting / generated-callsite ownership
- Evidence for: raw start has no direct xrefs and no IDA function object.
- Evidence against: behavior, field ownership, constructor/destructor/click evidence, and direct class parent are strong enough for source method ownership.
- Decision: reject.

## Source Placement
- Recommended source placement: `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, inside the `PrettyButtonControlPane2` class implementation.
- This placement fits current class/file docs, vtable data, constructor/click/destructor evidence, and the existing two-class PrettyButton source module.
- Rejected placements: `ButtonControlPane.cpp` because that is only a base dependency; CreateUser dialog files because they are consumers; `FunctionObjects.cpp` because it owns the callback object declarations/templates, not the control method; generated/callsite ownership because no address-table route exists.
- Remaining placement uncertainty: exact header declaration and whether the original source spelled the member as `SetCallback`, `SetClickCallback`, or another name is not directly recovered. The documentation and sibling pattern make `SetCallback` the best first-draft name.

## Range / Split / Padding / Reclassification Analysis
- No split or merge is recommended. UID0004ED is already the exact child range.
- Preserve pre-padding `0x0054b9f9-0x0054ba00`: seven bytes / decimal 7 (Verified with `int_convert.py`) of `0xcc`.
- Preserve target range `0x0054ba00-0x0054ba24`: `0x24` / decimal 36 bytes (Verified with `int_convert.py`).
- Preserve post-padding `0x0054ba24-0x0054ba30`: `0x0c` / decimal 12 bytes (Verified with `int_convert.py`) of `0xcc`.
- Preserve successor [UID:0004EE] at `0x0054ba30`; no overlap or boundary change.

## Negative Evidence Summary
- No direct xrefs/callers to `0x0054ba00`.
- No absolute VA pointer encoding for `0x0054ba00` or `0x0054ba24`.
- No direct `E8/E9` branch hit to `0x0054ba00` or `0x0054ba24`.
- RVA pattern hits for `0x0054ba00` are unrelated immediates in scoped disassembly.
- No IDA function object, no decompile, no basic blocks, and no callee list for the raw start.
- No recovered PrettyButton UDT, no recovered original `SetCallback` method symbol, and no exact original member field name.
- These negatives cap confidence and require inferred source names, but they do not overcome the constructor/destructor/click/sibling evidence for source-authored method ownership.

## IDA Rename / Type / Comment Recommendations
- Do not request IDA DB edits during this report-only pass.
- Do not define `0x0054ba00` as a function in IDA as part of this report; documentation/source emission can proceed from the exact raw span. If a later IDA cleanup is separately approved, a function definition may improve decompilation but is not required for this callback.
- Source-facing names recommended for documentation/formal C++: `PrettyButtonControlPane2::SetCallback`, parameter `callback`, member `m_callback`, type `FunctionObject0 *`.
- Rejected type/name choices: `void *` is too weak; `PrettyButtonCallback`/pane-local callback interface invents a type not supported by the project-wide callback family; raw `sub_54BA00` is not source-quality.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes.
- Recommended code: insert only the following content between the existing `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers in the target file:

```cpp
void PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
```

- Reason it preserves exact original behavior: `delete m_callback` matches the observed null-check plus virtual slot-zero scalar deleting destructor call with flag `1`; assignment matches `mov [esi+128h], eax`; the source-level `void` return permits the compiler to leave `callback` in `eax` without making a source-visible return contract.
- Reason it matches plausible original source shape: this is a normal owned callback replacement setter for a UI control, using the existing project callback object base rather than decompiler `_DWORD *` types or raw vtable calls.
- Inferred names/types: `FunctionObject0` comes from [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md); `m_callback` is inferred from constructor/destructor/click/setter use and the existing file/class docs; `SetCallback` is inferred from current class/file documentation and the class1 sibling setter.
- Remaining caveat: if a later class-declaration pass chooses a more exact field name such as `m_clickCallback`, update both the target C++ and class docs consistently. This is not a blocker for first-draft formal C++.

## Final Recommendation
- Update UID0004ED target only unless support verification finds stale direct text.
- Promote target to `88/90`, set `EMITTER_UIDS:0000AS`, preserve owner/reconstructable/range/title, and insert the C++ body above.
- Add current MCP/PE evidence, FunctionObject0 type resolution, ownership reanalysis, negative reachability caveat, and split/padding preservation to the target.
- Support docs probably need only verification: [UID:0000AS] currently says C++ is blank pending callback type; after callback, either update that line to say UID0004ED now emits first-draft C++ or record already-present if current text has changed.

## Recommended Target Doc Changes
- Target path: `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md`.
- Metadata: change `COMPLETION:83` to `COMPLETION:88`; change `CONFIDENCE:88` to `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000AS`; keep `RECONSTRUCTABLE:TRUE`; set `EMITTER_UIDS:0000AS`; keep `EMITTER_POSITION_OPTIONAL:` blank unless validator/by-structure requires an order.
- Formal C++: insert the exact `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` body from `## First-Draft C++ Recommendation`.
- Evidence to add: MCP session `b011_0004EC_20260702` health/session state; stale-session note for `b010_0002r7_20260702`; exact lookup results; 15-instruction raw body; bytes and padding; xref negatives; decompile/callee/basic-block failures; constructor/destructor/click field proof; class1 sibling comparison; FunctionObject0 type support; PE scan negative/false-positive results.
- Preserve caveats: non-modeled raw start, no direct xrefs, no recovered original symbol/UDT, and inferred field/method names.
- Ownership/source placement: accept [UID:0000AS] direct class owner and [UID:0000MP] file placement; reject direct file, ButtonControlPane dependency, CreateUser caller, FunctionObjects direct ownership, no-owner, and generated/callsite ownership.

## Recommended Support Doc Changes
- `by-class/PrettyButtonControlPane2.md`: verify and, if still stale, update the UID0004ED row from "C++ blank pending callback type" to "emits first-draft `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` after B013 UID0004ED source-quality report"; preserve class score unless callback implementation reveals a direct score correction.
- `by-file/PrettyButtonControlPane.md`: verify child inventory already lists UID0004ED as callback replacement; edit only if it still implies all method children remain blank or callback type is unresolved for UID0004ED.
- `by-class/PrettyButtonControlPane.md`: no expected edit; use sibling UID0004E6 as comparison evidence only.
- `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`: no expected edit; current vtable/click slot facts already support class ownership.
- FunctionObjects docs: no edit; use [UID:0001WQ] / [UID:0000JO] as already-present type support.

## Score And Metadata Recommendation
- Current target score/metadata: `83/88`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- Recommended target score/metadata: `88/90`, `CANONICAL_OWNER:0000AS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AS`, blank emitter position unless required, formal C++ body inserted.
- Why completion rises: the old callback-type blocker is resolved to the shared `FunctionObject0` family; exact current MCP evidence, PE reachability negatives, sibling comparison, and first-draft C++ are now documented.
- Why confidence rises only modestly: owner/behavior/type direction are strong, but no direct xrefs, no IDA function object, no original method symbol, and no recovered UDT keep the score below final-source levels.
- Why not lower: every material blocker named by current docs was investigated, and the remaining uncertainty is source-name exactness rather than behavior or ownership.
- Why not higher: class layout/resource/member declaration remains broader class work, and the exact original type spelling could have been a typedef/alias over `FunctionObject0`.

## Open Questions With Attempted Resolution
- Is the raw start live source code or padding? Resolved as source code. Evidence: 15 instruction body, prologue/epilogue, callback release/store semantics, pre/post `0xcc` padding, and sibling setter comparison.
- Is callback type still a blocker? Resolved enough for first-draft C++. Evidence: FunctionObjects docs define `FunctionObject0`; click invokes slot `+0x0c` with no args; destructor/setter release slot `+0x00`; no project-specific callback typedef was recovered.
- Is direct reachability recovered? No. Evidence: `xrefs_to` zero, VA/RVA/rel32 PE scan negative except unrelated RVA immediates. Impact: confidence cap and caveat, not no-code blocker because constructor/destructor/click prove field role.
- Should the method return `int`/pointer because decompiler leaves `eax=callback`? No. Best source shape is `void`; the register result is incidental and no caller use is recovered.
- Should support docs be changed immediately? Not during report-only pass. Callback should verify exact stale text first and edit only directly stale support lines.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. The only coverage/tracker changes expected are validator-owned generated updates after a later implementation callback validates changed by-* docs. B013 should not edit manual coverage reports or generated tracker files.

## Follow-Up Actions
- Supervisor: Gate 1 validate this report as a standalone report artifact.
- B013 callback if accepted: lease only target and any directly stale support docs immediately before edits; apply metadata/C++/evidence at report-level detail; run scoped validators for every changed by-* doc; check generated `PrettyButtonControlPane.cpp` freshness and UID0004ED output/empty-marker state; release leases.
- Future broader work: class declaration/source pass can standardize PrettyButton field names and decide whether `m_callback` should become `m_clickCallback` or another accepted member name across class1/class2.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high for `88/90`.
- Remaining uncertainty: no recovered original source symbol/type, no raw-start xrefs, no IDA function model, and exact class field/member declarations remain inferred.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory\0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md --apply --queue-timeout 240`
  - Working directory: `source-3/project-documentation`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000004959`
  - `command_timestamp: 2026-07-03T01:53:44-04:00`
  - Relevant updates: completion `88`, confidence `90`, UID0004ED emitter registry set to `0000AS`, formal block registry changed from blank to block, UID links/reference index updated, projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-class\PrettyButtonControlPane2.md --apply --queue-timeout 240`
  - Working directory: `source-3/project-documentation`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000004962`
  - `command_timestamp: 2026-07-03T01:53:56-04:00`
  - Relevant updates: projected stats updated; generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file\PrettyButtonControlPane.md --apply --queue-timeout 240`
  - Working directory: `source-3/project-documentation`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000004992`
  - `command_timestamp: 2026-07-03T02:22:38-04:00`
  - Relevant updates: projected stats updated; generated refresh deferred.
- Generated freshness: `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` later refreshed with `validator-command-id: 000000004967`, `validator-refreshed-at: 2026-07-03T01:54:25-04:00`, which is newer than both scoped validator timestamps and contains UID0004ED with `void PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)`.
- Generated freshness after by-file repair: generated refresh for `000000004992` was deferred; B013 checked the generated file freshness separately after the repair in the final handoff.
- Unresolved validator warnings/errors: none from the scoped validators.

## Changed Files
- Modified: `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md`.
- Modified: `by-class/PrettyButtonControlPane2.md`.
- Modified: `by-file/PrettyButtonControlPane.md`.
- Modified: `tools/leaser/Agents/Agent-B013/research/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md`.
- Leases: B013 leased the target and class support doc for the first edit/validator batch and released both immediately after validation. On follow-up repair, B013 leased only `by-file/PrettyButtonControlPane.md`, validated it, and released it immediately. Lease release output was `Success` for all B013-edited by-* files.
- Report execution: not run. No `execute_report`, dry-run/probing execute-report variant, registry lifecycle command, manual report move, or archive command was run.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation. Proof: goal.md callback says Gate 1 passed for current report artifact and accepted the UID0004ED disposition.
- [x] Target doc updated: `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md`. Proof: metadata/evidence/C++ sections edited and validator `000000004959` passed.
- [x] Verify support docs and edit only directly stale text: `by-class/PrettyButtonControlPane2.md`, `by-file/PrettyButtonControlPane.md`; use `by-class/PrettyButtonControlPane.md`, `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`, and FunctionObjects docs as support evidence unless stale text is found. Proof: `by-class/PrettyButtonControlPane2.md` stale UID0004ED row was updated and validator `000000004962` passed; `by-file/PrettyButtonControlPane.md` now has UID0004ED-specific support wording for the class2 setter, raw range, callback slot, cleanup/replacement behavior, caller context, FunctionObjects route, and rejected blank/raw dispositions, with validator `000000004992` passed.
- [x] Apply target metadata: `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000AS`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AS`, keep blank `EMITTER_POSITION_OPTIONAL` unless validator/by-structure requires ordering. Proof: target header and validator `000000004959`.
- [x] Insert formal C++ exactly between existing target C++ markers without duplicating marker lines:
```cpp
void PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
```
Proof: target formal block and generated `PrettyButtonControlPane.cpp` header `000000004967` contain the body.
- [x] Incorporate MCP evidence from session `b011_0004EC_20260702`: health/session state, exact lookup/non-function results, target 15-instruction body, bytes/padding, xref negatives, decompile/callee/basic-block failures, constructor/destructor/click proof, sibling setter comparison, type/name query results, and generated-output state. Proof: target Evidence, Ownership And C++ Policy, Score Rationale, Range / Split Notes.
- [x] Incorporate PE scan evidence: no absolute VA hits, no direct `E8/E9` hits, no endpoint hits, and RVA hits for `0x0054ba00` are unrelated immediates. Proof: target Evidence reachability caveat.
- [x] Preserve split/range facts: `0x0054b9f9-0x0054ba00` seven-byte padding, target `0x0054ba00-0x0054ba24` 36-byte body, `0x0054ba24-0x0054ba30` twelve-byte padding, successor UID0004EE at `0x0054ba30`. Proof: target Evidence and Range / Split Notes.
- [x] Preserve ownership reanalysis: accept class owner [UID:0000AS] and file placement [UID:0000MP]; reject direct file ownership, ButtonControlPane dependency ownership, CreateUser caller ownership, FunctionObjects direct ownership, no-owner, and generated/callsite ownership. Proof: target Ownership And C++ Policy.
- [x] Preserve source-quality caveats: `SetCallback`, `m_callback`, and `FunctionObject0 *` are inferred/source-facing, not recovered original symbols; no direct raw-start xrefs recovered. Proof: target Ownership And C++ Policy, Evidence, Score Rationale.
- [x] Update this report ledger during callback from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked`, with path/section proof for every claim. Proof: Claim And Incorporation Ledger updated above; ED-C09 is now applied for both class and by-file support docs.
- [x] Run scoped validator from `source-3/project-documentation` for the changed target: `python .\tools\validator.py --mode file --file by-memory\0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md --apply --queue-timeout 240`. Proof: command `000000004959`, timestamp `2026-07-03T01:53:44-04:00`, exit `0`, `ok:1`.
- [x] If support docs are edited, run scoped validators for each changed support doc. Proof: edited `by-class/PrettyButtonControlPane2.md`, validator command `000000004962`, timestamp `2026-07-03T01:53:56-04:00`, exit `0`, `ok:1`; edited `by-file/PrettyButtonControlPane.md`, validator command `000000004992`, timestamp `2026-07-03T02:22:38-04:00`, exit `0`, `ok:1`.
- [x] Check generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` after validator refresh; report validator command id/timestamp, generated header freshness, whether UID0004ED emits the new method body, and whether it remains an empty marker. Proof: generated header `validator-command-id: 000000004967`, `validator-refreshed-at: 2026-07-03T01:54:25-04:00`, newer than scoped commands, and contains UID0004ED method body rather than an empty marker.
- [x] Do not edit generated files, coverage-report files, project-level generated files, validator state, supervisor ledgers, archives, or report lifecycle state; do not run `execute_report` or any lifecycle/archive/manual move command. Proof: only target, class support doc, and this B013 report were manually edited; scoped validators caused validator-owned generated/projected side effects.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004999","destination_path":"executed-b-agent-research/B013/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md","timestamp":"2026-07-03T02:26:12-04:00","uid":"0004ED"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
