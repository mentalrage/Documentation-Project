** TARGET-REPORT-UID:0003N5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003N5 ControlPaneSetIgnoreHitTesting Ownership / Split Research


## Finalized Report / Current Recommendation

- Current recommendation: retain `0x00494c00-0x00494c10` as the inherited virtual `void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)`, owned/emitted by [UID:000038][ControlPane] through [UID:0000IG][ControlPane] at `NexusTK/ui/core/ControlPane.cpp`.
- Final disposition: source-reconstructable and formal first-draft C++ eligible. Replace the empty emitter marker with the exact one-field setter in this report.
- Required action: raise UID0003N5 from `86/90` to `90/92`, preserve owner/emitter/reconstructable/range/nesting, correct the decompiler-artifact return claim, add the formal body, and synchronize the getter, aggregate, class, and file support docs without changing their scores.
- Confidence: strong. Current MCP proves exact bytes/range, one-byte parameter/store, no callees, 50 inherited-vtable data refs, base vtable slot `+0x54`, unique body signature, and the constructor/getter/consumer field chain.

## Supporting Research

- Historical research state: this began as an independent report-only pass with no by-*, generated, coverage, tracker, supervisor, IDA database, or lifecycle edits. After supervisor Gate 1 acceptance of report SHA256 `6F1A47C7809BBD53829556F123D99319A1BF0CAE56044ED1B28969DEA9A5EB03`, the accepted C01-C12 callback was implemented in the five scoped by-* documents; generated/coverage/tracker artifacts changed only through scoped validators.
- The report supersedes the target's claim that the method source-returns the input byte. The observed `AL` value is the temporary used for the byte store, not a demonstrated source return contract.
- Current project setter precedent is decisive: accepted UID0004GH `FittingRoomTextButtonControlPane::SetSelected(bool)` has the same 16-byte MSVC shape, documents its `AL` result as incidental, and emits a `void` setter.
- Historical Wave2/RadioGroup ownership and raw decompiler labels were treated as stale leads only. Current split docs, vtable data, paired getter, and constructor control the recommendation.

## Target

- Target UID: `0003N5`.
- Target path: `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`.
- Historical source queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`. Current tracker placement and report counts are validator-owned lifecycle state and are not frozen by this report.
- Current supervisor classification: Gate 1 accepted implementation callback completed; ready for independent supervisor Gate 2 verification.
- Current parent state: canonical owner/emitter `000038` (`ControlPane`), source parent `0000IG` (`ControlPane.cpp`), reconstructable true, formal C++ blank.

## Current Target State

- Current metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:000038`, `EMITTER_UIDS:000038`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, exact half-open range `0x00494c00-0x00494c10`.
- Current owner/source state: unchanged and verified. B002 split the mixed physical helper band and assigned this exact child to base `ControlPane`; 50 vtable refs corroborate inherited reuse rather than a narrower derived owner. Source parent remains UID0000IG at `NexusTK/ui/core/ControlPane.cpp`.
- Current C++/generated state: target formal block contains the exact void-bool setter. Post-callback read-only generated snapshot `000000008310` and final B005 observation `000000008315` both emit UID0003N5 at `90/92` with no UID0003N5 empty marker; memory coverage marks it `coded`. Later shared validator refresh command IDs are expected to change independently without changing this source result.
- Resolved stale blocker/claim: target now documents retained `AL` as incidental byte-store reuse rather than a source return and emits the accepted `void` setter.
- Related docs checked: UID0002PC getter, UID0002PB constructor, UID0002PD aggregate, UID0003J8/J9 vtable docs, ControlPane class/file, PopupMenuControlPaneCore consumer, sibling state virtuals, and UID0004GH accepted one-byte setter.
- Current artifact status: accepted report details and validators are incorporated. Supervisor verification/execution/archive status is external validator-owned history; this report does not assert or freeze that lifecycle state.

## Executive Recommendation

- Keep the direct owner/emitter `000038` and source file `0000IG`; no owner move, new source file, or multiple emitter is justified.
- Keep the exact range and `Nested:0`. The target is one modeled six-instruction function with no internal padding or child split.
- Emit `void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)` assigning `m_ignoreHitTesting` directly, with no invalidation, normalization, condition, helper call, or explicit return.
- Raise only the target to `90/92`. Keep ControlPane class/file, getter, and aggregate scores unchanged because their broader completion/confidence caps are unaffected.

## Supervisor Active Recheck

- Gate 1 result: supervisor accepted exact report SHA256 `6F1A47C7809BBD53829556F123D99319A1BF0CAE56044ED1B28969DEA9A5EB03` and authorized C01-C12 implementation in the target plus four support docs.
- Split repair is not required. Current MCP resolves the existing exact child and its adjacent getter/deactivate boundaries without overlap.
- The target is the only source-bearing child in scope. Getter, aggregate, class, and file pages received wording/evidence parity only; their scores and formal-code dispositions remain unchanged.

## Inference Research Guidance Check

- Direct IDA fact: the function loads one stack byte, stores it at receiver offset `+0x104`, and returns with `retn 4`.
- Documentation fact: constructor initializes `m_ignoreHitTesting=false`; getter returns it as `bool`; PopupMenu generic hit testing skips candidates when it is true.
- Source-shape inference: the parameter is `bool`, return type is `void`, and best role names are `SetIgnoreHitTesting` / `ignoreHitTesting` / `m_ignoreHitTesting`.
- Original-proof boundary: exact names and C++ `bool` spelling are not PDB/header-proven. They are project-consistent inferred names/types backed by the complete init/write/read/consume chain.
- Stale Wave2/RadioGroup labels and Hex-Rays `_BYTE *this`, `char a2`, `char result` were rejected where current owner/type evidence is stronger.

## Heuristic / Inference Reanalysis And Validation

1. **Behavior.** Exact source-authored effect is one assignment to receiver byte `+0x104`. No callee, redraw, invalidation, notification, condition, or normalization exists.
2. **Field name/type.** `m_ignoreHitTesting` is accepted across constructor and getter formal C++; PopupMenu consumer establishes positive polarity: true means skip the control during hit testing. Generic `m_flag104`, `m_hitTestEnabled`, or inverted `m_acceptsHitTesting` names are rejected.
3. **Parameter type.** `bool` is strongest because the constructor initializes false, getter returns bool, consumer treats it as a boolean gate, and adjacent accepted source uses bool state setters. `char`/`unsigned char` remain ABI-compatible possibilities but are weaker source-facing choices.
4. **Return type.** Hex-Rays infers `char` only because `AL` still contains the byte loaded for the store. The body never establishes a separate return contract, there are zero direct code xrefs whose post-call use could prove one, and accepted UID0004GH uses the same prolog/load/store/epilog shape as `void SetSelected(bool)`. Emit `void`, not `bool` or `char`.
5. **Method name.** `SetIgnoreHitTesting` is grammatical, matches the target filename and established getter `IgnoresHitTesting`, and describes the field polarity exactly. `SetIgnoresHitTesting`, `DisableHitTesting`, `SetHitTestingEnabled`, and generic `SetFlag104` are weaker or polarity-distorting.
6. **Virtual/inheritance role.** The base primary vtable cell `0x00617ae4` is `ControlPane` slot `+0x54`; target xrefs are 50 data references and zero ordinary code references. The base cell plus 49 derived-table copies establish inherited virtual reachability and base ownership.
7. **Callers/consumers.** No direct setter call is attributable in IDA. The value is consumed through paired getter UID0002PC, whose sole direct caller at `0x0049fb7f` performs post-rectangle-test suppression. Constructor UID0002PB supplies initialization; these are field lifecycle/consumer evidence, not setter callers.
8. **Source placement.** The setter belongs beside constructor/getter and sibling state virtuals in `NexusTK/ui/core/ControlPane.cpp`; ProgressBar/Button/Radio/Popup ownership is rejected as adjacency, inheritance, or consumer context.
9. **Compiler/source shape.** Ordinary assignment to a `bool` field explains the machine body exactly. Explicit `return ignoreHitTesting`, `static_cast<unsigned char>`, double-negation normalization, or raw offset access would add unsupported source semantics.

Rejected alternatives:

- `char ControlPane::SetIgnoreHitTesting(char)`: decompiler-shaped and unsupported by any caller-observed return use.
- `bool ControlPane::SetIgnoreHitTesting(bool)`: no evidence that a source return value is part of the interface; identical accepted setter precedent is void.
- Nonvirtual/private helper: contradicted by base slot `+0x54` and 50 vtable data refs.
- Derived-control owner: inherited vtable copies are not ownership; the base table, constructor, and getter own the field contract.
- Merge with getter or deactivate: each has its own modeled function/range and distinct source method role.

## Evidence Standards Used

- Primary evidence: current IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, and exact-range signature generation.
- Corroboration: accepted constructor/getter C++, ControlPane class/file/vtable docs, aggregate split report, PopupMenu caller analysis, current generated output/tracker, and accepted byte-setter precedent UID0004GH.
- Negative evidence: zero ordinary code xrefs, zero callees, no redraw/helper path, no trailing padding before the next function, and no source-return consumer.
- Evidence ladder: binary fixes range/store/ABI; constructor/getter/consumer chain fixes semantics; established project setter shape fixes the most plausible C++ return/parameter representation; exact spellings remain inferred.

## Evidence Checked

- Current MCP transport session: `3302a154-719c-4839-813e-e62cd6975c16`.
- Active IDB session: `359c7886`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `13016`, auto-analysis/Hex-Rays/string cache ready.
- MCP checks: target/adjacent lookup, target decompile/disassembly, target/getter xrefs, target callees, 64-byte neighborhood, and exact `0x00494c00-0x00494c10` signature.
- Docs/reports searched/opened: target UID/name/address, B002 ControlFamily split report, B015 getter report, constructor/getter/aggregate/class/file/vtable pages, sibling state helpers, generated ControlPane output, research tracker, and UID0004GH setter page.
- Negative checks: no direct target code xref, no target callee, no narrower owner route, no range overlap, no field polarity inversion, and no direct evidence for a source return.
- Failed optional checks: broad rendered-text searches for all `+0x54` calls and `+0x104` accesses, followed by a broad multi-pattern byte search, exceeded request deadlines after the exact target pass had succeeded. They produced no evidence and are excluded from conclusions. Existing exact xrefs/bytes plus current docs provide the bounded evidence used here; no MCP process was managed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Exact modeled range is `0x00494c00-0x00494c10`; getter gap precedes it and Deactivate starts immediately after. | Direct/strong | MCP lookup/bytes/disasm | UID0003N5 Boundary Evidence | Preserve/refresh | Applied/verified: target Boundary Evidence records nine-byte prepad and immediate `0x00494c10` successor; validator `000000008300` `ok:1`. |
| C02 | Exact source behavior is `m_ignoreHitTesting = ignoreHitTesting`. | Direct/strong | MCP body; constructor/getter chain | UID0003N5 Behavior/C++ | Incorporate | Applied/verified: target Behavior and formal block contain the single direct assignment; post-callback generated snapshot `000000008310` matches. |
| C03 | Source return type is `void`; Hex-Rays `char` return is incidental AL reuse. | Strong inference | Six instructions; zero direct callers; UID0004GH identical setter shape | UID0003N5 Behavior/Reconstruction | Correct stale claim | Applied/verified: stale return claim removed; target, getter, aggregate, class, and file record incidental retained `AL` and no source return. |
| C04 | Parameter and field are source-facing `bool` / `m_ignoreHitTesting`. | Strong inference | Constructor false; bool getter; consumer gate | UID0003N5 Status/Behavior/C++ | Incorporate | Applied/verified: target status/behavior/C++, all support parity, and generated constructor/getter/setter use the bool field contract. |
| C05 | Best method/parameter names are `SetIgnoreHitTesting(bool ignoreHitTesting)`. | Strong inference | Getter grammar, field polarity, project naming | UID0003N5 formal block | Incorporate | Applied/verified: exact accepted signature is present in target and generated output. |
| C06 | Base owner/emitter remains ControlPane UID000038; source parent remains UID0000IG. | Direct/strong | Base vtable slot, class/file field chain | Metadata/Status/Parent | Preserve | Applied/verified: target headers retain `000038`/`000038`; class/file routing retains UID0000IG and `NexusTK/ui/core/`. |
| C07 | Target is virtual slot `+0x54`; 50 data refs are base plus inherited derived tables, not direct callers. | Direct/strong | MCP xrefs; vtable base `0x00617a90` | UID0003N5 Xrefs/Inheritance | Incorporate | Applied/verified: target Xrefs/Ownership and all support evidence record base cell `0x00617ae4` plus 49 inherited copies. |
| C08 | Direct setter callers are absent; value consumer is getter caller `0x0049fb7f` in generic hit testing. | Direct/strong | MCP xrefs; UID0002PC caller analysis | UID0003N5 Caller/Consumer inventory | Incorporate | Applied/verified: target and support docs distinguish zero setter code xrefs from getter consumer `0x0049fb7f`. |
| C09 | No split, padding child, reclassification, IDA mutation, or source-file move is needed. | Direct/strong | Boundaries, adjacency, owner docs | Range/Source Placement | Preserve | Applied/verified: exact range/nesting/source route retained; no split, IDA mutation, or source move performed. |
| C10 | Exact formal void setter should replace generated empty marker. | Strong | C01-C09 | UID0003N5 formal block | Apply | Applied/verified: target block and post-callback generated snapshot `000000008310` emit the exact setter; no UID0003N5 empty marker remains. |
| C11 | Target score should become `90/92`; owner/emitter/reconstructable/range/nesting unchanged. | Strong | Closed behavior/type/C++ blockers | UID0003N5 metadata/Score | Apply | Applied/verified: target header is `90/92`; validator `000000008300` records both updates and preserves other metadata. |
| C12 | Getter, aggregate, class, and file require parity wording; their scores remain unchanged. | Strong | Existing support rows/open question | Four support docs | Apply wording only | Applied/verified: all four support docs carry report-level parity; validators `000000008301`, `000000008302`, `000000008303`, and `000000008309` each returned `ok:1` with scores unchanged. |

## Positive Evidence Summary

- Exact bytes: `55 8b ec 8a 45 08 88 81 04 01 00 00 5d c2 04 00`.
- Exact operation: stack byte -> `AL` -> receiver byte `+0x104`; six instructions, no callees.
- Field contract: constructor initializes false, setter writes, getter reads bool, PopupMenu hit test skips when true.
- Virtual contract: base primary vtable `0x00617a90 + 0x54 = 0x00617ae4` points to target; 50 target data xrefs show broad inheritance.
- Source-shape precedent: accepted 16-byte UID0004GH setter treats retained `AL` as incidental and emits `void ... (bool)`.

## IDA MCP Facts

- `server_health`: status `ok`, module `NexusTK.exe`, image base `0x400000`, current IDB/Hex-Rays/analysis/string cache ready.
- `lookup_funcs`: getter `sub_494BF0` `0x7`; no function at `0x00494bf7`; target `sub_494C00` `0x10`; Deactivate `sub_494C10` `0x1a`; no function at `0x00494c2a`; Activate starts `0x00494c30`.
- `decompile`: `this[260] = a2`; Hex-Rays exposes the loaded byte as `char result`, but that is not source-return proof.
- `disasm`: exactly `push ebp; mov ebp,esp; mov al,[ebp+arg_0]; mov [ecx+104h],al; pop ebp; retn 4`.
- `xrefs_to target`: 50 data refs and no code refs. Base ControlPane ref is `0x00617ae4`; other refs are inherited derived-control table entries.
- `xrefs_to getter`: sole code xref `0x0049fb7f` in `sub_49FB10`.
- `callees target`: none.
- `get_bytes`: getter bytes, nine `0xcc` bytes at `0x00494bf7-0x00494c00`, exact target bytes, then immediate start of Deactivate at `0x00494c10`.
- `make_signature_for_range`: exact 16-byte signature above, reported unique.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494bf0-0x00494bf7` | UID0002PC | Bool getter/consumer gateway | Yes | ControlPane | `88/92` | First-draft C++ present |
| `0x00494bf7-0x00494c00` | `by-memory/-ignored.md` | Nine-byte alignment | No source | Adjacent getter/setter | `100` ignored | Preserve |
| `0x00494c00-0x00494c10` | UID0003N5 | Virtual bool-field setter | Yes | ControlPane | `86/90 -> 90/92` | Add formal C++ |
| `0x00494c10-0x00494c2a` | UID0003N6 | Deactivate/active-byte clear | Yes | ControlPane | `86/90` | Adjacent support unchanged |
| `0x00617a8c-0x00617b30` | UID0003J8 | ControlPane vtable data | Yes via declarations | ControlPane | `86/92` | Existing slot proof unchanged |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Consumer | Meaning |
| --- | --- | --- |
| `0x00617ae4` | Base ControlPane primary vtable slot `+0x54` | Direct ownership and virtual interface proof |
| 49 additional `.rdata` cells | Derived-control vtable copies | Inherited reuse; not narrower ownership or ordinary callers |
| No code xref to `0x00494c00` | No direct setter caller identified | Preserve reachability caveat; virtual-table route remains live |
| `0x0049fb7f` -> UID0002PC getter | PopupMenu/generic control hit-test consumer | Skips candidate when `m_ignoreHitTesting` is true |
| UID0002PB constructor | Packed store clears `+0x104` | Initialization source for the field |

## Documentation Evidence And IDA Status

- Current target already has correct owner/source/range/xref counts but stale return/C++ disposition.
- UID0002PC establishes getter name, bool interpretation, sole consumer, and complete read side.
- UID0002PB establishes field initialization and accepted `m_ignoreHitTesting` spelling.
- UID0003J8/J9 and class/file docs establish base vtable/source route; UID0002PD preserves mixed-band split boundaries.
- Post-callback generated ControlPane snapshot `000000008310` and final B005 read-only observation `000000008315` emit constructor, getter, and UID0003N5 setter at `90/92`; the UID0003N5 empty marker is gone.

## Ranked Ownership Analysis

### 1. ControlPane

- Evidence for: base vtable slot `+0x54`, constructor field initialization, paired getter, class/file inventory, and broad inherited-table fanout.
- Evidence against: exact original symbol names are not recovered.
- Decision: retain direct owner/emitter UID000038 and source file UID0000IG.

### 2. Derived control family

- Evidence for: 49 derived vtables copy the target pointer.
- Evidence against: inherited slot reuse is not source ownership; no override or derived field is involved.
- Decision: reject as canonical owner; derived tables are reachability/inheritance evidence only.

### 3. PopupMenuControlPane / Button / ProgressBar / RadioGroup

- Evidence for: PopupMenu consumes the getter; other families are adjacent or inherit ControlPane.
- Evidence against: none calls the target directly or owns `+0x104`; split docs explicitly reject old RadioGroup/Button ownership.
- Decision: reject all.

### Proposed new file/grouping, if applicable

- Not applicable. Existing `NexusTK/ui/core/ControlPane.cpp` is the coherent and already generated source route.

## Source Placement

- Recommended placement: `ControlPane` member definition in [UID:0000IG][ControlPane], projected to `NexusTK/ui/core/ControlPane.cpp`.
- Fit: constructor, getter, state virtuals, vtable declaration, and field consumer all belong to base control infrastructure.
- Rejected placements: ProgressBarControlPane, ButtonControlPane/ButtonChoice, RadioGroupControlPane, PopupMenuControlPane, a free helper, or a new one-method file.
- Remaining uncertainty: exact original header declaration spelling/access section is not recovered; no implementation-path uncertainty remains.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is one `0x10`-byte modeled function, `0x00494c00-0x00494c10`.
- Preceding `0x00494bf7-0x00494c00` is nine `0xcc` bytes and remains ignored alignment.
- No following padding belongs to the target: `ControlPaneDeactivate` begins immediately at `0x00494c10`.
- No child split, merge with getter, range extension, raw-helper conversion, or reclassification is justified.
- UID0002PD remains a non-emitting physical aggregate; exact child UID0003N5 carries source output.

## Negative Evidence Summary

- No ordinary direct target caller and no target callee exists.
- No call-site return consumption supports Hex-Rays `char` as a source return type.
- No invalidation/redraw call means this setter changes hit-test policy without visual side effects.
- Derived vtable references do not prove derived ownership.
- PopupMenu getter consumption does not prove PopupMenu ownership or direct setter reachability.
- Exact source spellings are not symbol-proven, so confidence remains below final-source certainty.

## IDA Rename / Type / Comment Recommendations

- Source-facing name/type: `void __thiscall ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)` with field `bool m_ignoreHitTesting` at `+0x104`.
- Comment: "Sets whether generic hit testing skips this control; no invalidation or normalization."
- Preserve raw evidence aliases `sub_494C00`, `char a2`, and `this[260]` only in IDA/evidence prose.
- No IDA database edit was performed during research or implementation; proposed typing remains documentation guidance for any separately authorized IDB pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Exact formal block insertion:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)
{
    m_ignoreHitTesting = ignoreHitTesting;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior preservation: one byte argument is assigned directly to the one-byte field; source adds no condition, redraw, normalization, call, or return value.
- Plausible original source shape: this is the normal VC6/VC7-era C++ form for a tiny boolean virtual setter and matches accepted project setter style.
- Inferred names/types: method/parameter/field spellings and bool type are descriptive, project-consistent inference; raw bytes and semantics are direct facts.
- Third-party import: not applicable.

## Final Recommendation

- Applied: exact formal setter, corrected behavior/return/type/source-shape prose, current MCP evidence, and UID0003N5 score `90/92`.
- Preserved: owner/emitter `000038`, reconstructable true, exact range, `Nested:0`, and source route UID0000IG.
- Applied: getter UID0002PC, aggregate UID0002PD, ControlPane class, and ControlPane file source-ready setter parity with all four scores unchanged.
- Leave vtable data/type docs unchanged because they already record the correct base slot and declaration-driven handling.
- Future work outside scope: remaining ControlPane state-virtual names, fixed-return virtual, destructor representation, and no-route active-frame helper.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`.
- Applied `86/90 -> 90/92`; all routing/range/nesting metadata is preserved.
- Inserted the exact formal C++ above.
- Corrected "returns that byte" to incidental-AL/void-setter semantics and retained the zero-direct-caller caveat.
- Added current MCP session facts, exact bytes, unique signature, base slot `+0x54`, bool field lifecycle, accepted setter precedent, rejected alternatives, and lifecycle-neutral Changes entry.
- Replaced Item Summary with concise lifecycle-neutral source-ready behavior.

## Recommended Support Doc Changes

- `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`: replaced "setter remains outside" with accepted source-ready setter parity and support/change evidence; score remains `88/92`.
- `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`: updated UID0003N5 row/evidence to `90/92`, void-bool setter, base slot `+0x54`, and formal child C++; aggregate stays `88/91`, nonreconstructable/non-emitting.
- `by-class/ControlPane.md`: updated method row/autogen/evidence/Changes to identify UID0003N5 as first-draft source-ready; class remains `86/88` with blank class declaration.
- `by-file/ControlPane.md`: updated proposed contents/evidence/Changes and generated-state wording; file remains `86/88`, path unchanged.
- UID0003J8/J9 vtable docs: no edit required; existing base slot/source-declaration model is sufficient.

## Score And Metadata Recommendation

- Historical target: `86/90`, owner/emitter `000038`, reconstructable true, blank C++.
- Current implemented target: `90/92`, owner/emitter `000038`, reconstructable true, exact formal C++.
- Completion increase: closes return/type/name/C++ blockers and documents current exact evidence plus consumer lifecycle.
- Confidence increase: independent MCP and identical accepted setter precedent corroborate the simple source shape. Do not exceed `92` because exact original spellings/bool type are inferred and no ordinary setter call site is recovered.
- Score-improvement attempts: exact MCP pass resolved body/range/xrefs/callees/signature; getter/constructor/consumer resolved field polarity/type; vtable math resolved inheritance slot; UID0004GH resolved incidental return/source shape.
- Metadata unchanged: owner, emitters, reconstructable, optional position, nesting, range/path, and parent route.

## Open Questions With Attempted Resolution

- Exact original method/parameter spelling: no symbols/header recovered. `SetIgnoreHitTesting(bool ignoreHitTesting)` best matches getter grammar, field polarity, target naming, and project conventions; nonblocking confidence cap.
- `bool` versus one-byte integer: ABI body alone permits either, but constructor false/getter bool/consumer gate and accepted setter style make bool the defensible source type; nonblocking confidence cap.
- Return type: resolved to `void`; decompiler `char` is incidental AL reuse, with no direct caller return use and exact accepted precedent.
- Virtual call sites: no ordinary code xrefs are resolved to the concrete target because calls dispatch through inherited vtables. Fifty vtable data refs prove virtual reachability; absence of a named indirect caller remains a confidence cap, not a code blocker.
- No unresolved issue blocks owner, source placement, range, score, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Generated coverage and the research tracker are validator-owned and must not be edited manually.
- Actual validator-owned refresh: generated `ControlPane.cpp` emits UID0003N5 at `90/92`, and generated memory coverage marks UID0003N5 `coded`. Research-tracker placement, generated header command IDs, and executed-report counts are validator/lifecycle-owned values that may change independently; this report does not freeze or manually edit them.

## Follow-Up Actions

- Implementation status: C01-C12 are applied and verified in the accepted five-file scope; no B005 implementation item remains.
- Independent supervisor verification/execution/archive state is external validator-owned history and is not inferred or frozen by this report path or wording.
- No A-agent or IDA mutation action is required.

## Confidence

- Recommendation confidence: `92/100`.
- Score confidence: high for `90/92`.
- Remaining uncertainty: original spellings/bool declaration and individually named virtual call sites.

## Validator Results

- Historical report-only pass: no validator ran before Gate 1 acceptance, as required.
- UID0003N5 target: `python .\tools\validator.py --mode file --file by-memory\0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md --apply --wait-generated` -> command `000000008300`, `ok:1`, completion/confidence `90/92`, blank-to-block registry update, generated refresh completed.
- UID0002PC getter: `python .\tools\validator.py --mode file --file by-memory\0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md --apply --wait-generated` -> command `000000008301`, `ok:1`, score unchanged `88/92`, generated refresh completed.
- UID0002PD aggregate: `python .\tools\validator.py --mode file --file by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md --apply --wait-generated` -> command `000000008302`, `ok:1`, score unchanged `88/91`, generated refresh completed.
- ControlPane class: `python .\tools\validator.py --mode file --file by-class\ControlPane.md --apply --wait-generated` -> command `000000008303`, `ok:1`, score unchanged `86/88`, generated refresh completed.
- ControlPane file: `python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --wait-generated` -> command `000000008309`, `ok:1`, score unchanged `86/88`, generated refresh completed.
- Read-only generated proof: post-callback snapshot command `000000008310` / `2026-07-12T17:14:56-04:00` and final B005 observation command `000000008315` / `2026-07-12T17:17:35-04:00` both emit the exact UID0003N5 setter at `90/92`; no UID0003N5 empty marker remains, and generated memory coverage marks the target `coded`. Subsequent shared validator refresh IDs are external churn, not a source-state change.
- Unrelated existing diagnostics: target validator reported missing-reference UIDs `0003N6`/`0003J8`; aggregate/class/file validators reported additional pre-existing missing-reference UIDs outside accepted C01-C12 scope. Every scoped command still returned `ok:1`; no unrelated reference or validator-state repair was attempted.

## Changed Files

- Modified target: `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`.
- Modified support: `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`, `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`, `by-class/ControlPane.md`, and `by-file/ControlPane.md`.
- Modified implementation record: `tools/leaser/Agents/Agent-B005/research/0003N5-ControlPaneSetIgnoreHitTesting-source-quality.md`.
- Validator-owned refreshes include generated `ControlPane.cpp`, generated coverage/research-tracker metadata, projected stats, and validator registry state. None was edited manually.
- Preserved in this callback: UID0002EQ and its implemented files were outside scope and were not touched; their path/hash/lifecycle state is external to this report.
- Renamed/moved files: none. No report execution, lifecycle/registry, move/archive, `execute_report`, generated manual edit, supervisor-file edit, or IDA mutation was performed.
- Lease proof: each by-* file was leased only for its own edit/validator batch and released successfully immediately afterward; final `current_leases.md` contains no B005 entry.

## Implementation Tracking Checklist

Historical report-only pass and Gate 1:

- [x] Supervisor Gate 1 accepted report SHA256 `6F1A47C7809BBD53829556F123D99319A1BF0CAE56044ED1B28969DEA9A5EB03` before implementation.
- [x] Accepted target/support scope limited to UID0003N5, UID0002PC getter, UID0002PD aggregate, `by-class/ControlPane.md`, and `by-file/ControlPane.md`.
- [x] Current target state and MCP/by-*/old-report/generated/tracker evidence recorded.
- [x] Claim And Incorporation Ledger records C01-C12 with destinations and applied/verified proof.
- [x] Metadata/score applied: UID0003N5 `86/90 -> 90/92`; support scores unchanged.
- [x] Score blockers resolved: behavior, void return, bool parameter/field, method name, vtable slot, consumer chain, and formal source shape.
- [x] Owner/emitter/reconstructable disposition: preserve `000038`/`000038`/true.
- [x] Split/range/padding disposition: preserve exact target and ignored prepad; no following target padding.
- [x] Source placement and IDA disposition: preserve `NexusTK/ui/core/ControlPane.cpp`; no IDA mutation.
- [x] First-draft C++ applied: exact managed void-bool setter block in this report.
- [x] Third-party import confirmed not applicable.
- [x] Target/support facts, return correction, xrefs/consumer inventory, score rationale, and lifecycle-neutral Changes wording incorporated.
- [x] Historical/rejected/negative evidence preserved: no direct caller, inherited refs not ownership, PopupMenu consumer-only, ProgressBar/Button/Radio rejection, incidental AL, and no redraw/helper/normalization.
- [x] Wave2/RadioGroup ownership encountered and rejected as stale.
- [x] Open questions closed or retained as evidence-backed confidence caps.
- [x] One scoped validator run for each edited by-* file: commands `000000008300`, `000000008301`, `000000008302`, `000000008303`, and `000000008309`, all `ok:1`.
- [x] Generated refresh completed through validators; no manual coverage/tracker edit or text required.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at the exact Gate 1 hash above.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with applied/verified proof for C01-C12.
- [x] Metadata/score/owner/emitter/range/nesting/C++ changes applied exactly.
- [x] Historical assumptions, rejected alternatives, raw MCP facts, and negative evidence preserved.
- [x] Open questions resolved or retained with evidence-backed confidence caps.
- [x] Validators run per edited file and exact results recorded.
- [x] Generated ControlPane output and generated memory coverage verified read-only; tracker remains validator-owned.
- [x] All leases released immediately; no accepted implementation item remains unapplied.
- [x] No lifecycle/report-move/registry/`execute_report` command or manual generated/coverage/tracker/supervisor edit performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000008335","destination_path":"executed-b-agent-research/B005/0003N5-ControlPaneSetIgnoreHitTesting-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003N5-ControlPaneSetIgnoreHitTesting-source-quality.md","timestamp":"2026-07-12T17:27:53-04:00","uid":"0003N5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
