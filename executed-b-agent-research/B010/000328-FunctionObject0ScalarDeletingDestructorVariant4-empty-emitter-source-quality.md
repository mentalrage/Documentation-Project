** TARGET-REPORT-UID:000328 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000328 FunctionObject0ScalarDeletingDestructorVariant4 Empty-Emitter Source-Quality Report

## Lifecycle Status

- Initial report-only research: completed by B010 for [UID:000328] with current MCP evidence then available from session `c9671f69`.
- Supervisor disposition: accepted for implementation callback. The target was confirmed as compiler-emitted `FunctionObject0` scalar deleting destructor glue for the guard-size `0x04` variant.
- Implementation callback: completed. The target and required support docs were edited at report-level detail; optional/extra support docs were checked and either left already-present or excluded as not applicable in the ledger/checklist.
- Validators: completed for every edited by-* doc. Commands `000000000683`, `000000000686`, `000000000696`, and `000000000699` all exited `0` with `ok: 1`.
- Generated output: checked read-only after validation. `auto-generated\NexusTK\util\FunctionObjects.cpp` no longer contains `UID:000328` as an Empty Emitter Marker; continuation recheck showed validator-owned header `000000000707` at `2026-06-29T12:20:50-04:00`.
- Current execution status: implementation is complete and ready for supervisor verification/execution handling. The report remains in `research/` until supervisor executes it with the validator-owned report lifecycle command.

## Finalized Report / Applied Disposition

- Applied disposition: [UID:000328] is intentional non-emitting source-declared/generated-binary metadata. `CANONICAL_OWNER:00005L` and `RECONSTRUCTABLE:TRUE` were kept, `EMITTER_UIDS:` was cleared, and the formal `RECONSTRUCTION_CPP` fields remain blank.
- Final disposition: compiler-emitted scalar deleting destructor glue for the base/small `FunctionObject0::vftable` variant. The human-written source representation is the shared `FunctionObject0` / FunctionObjects class/template declaration and destructor semantics, not a handwritten concrete deleting-destructor body and not a formal comment marker.
- Completed action after supervisor acceptance: target and shared FunctionObjects support docs now pair blank formal C++ with blank `EMITTER_UIDS:` and a prose no-code proof. This resolved the generated empty-emitter marker without inventing source for compiler glue.
- Confidence: high. MCP session `c9671f69` supplied the accepted implementation evidence for exact range, body shape, vtable reset, base cleanup/free callees, scalar-delete flag gates, guard size `0x04` / decimal `4`, vtable-only reachability, endpoint negative evidence, sibling contrast, and FunctionObjects source-family context. Later supervisor notice marks `c9671f69` stale/dead for future MCP work; any future MCP-backed verification should use live session `b2ae72ec` or pause if MCP disappears.

## Target

- Assignment id: `B010-empty-emitter-report-000328-FunctionObject0ScalarDeletingDestructorVariant4-20260629`
- Target UID: `000328`
- Target path: `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists [UID:000328] at `85/88`, combined `86.5`, reconstructable `true`, reports `0`.
- Initial generated symptom before callback: `auto-generated/NexusTK/util/FunctionObjects.cpp` line 69 showed [UID:000328] as an Empty Emitter Marker in generated command `000000000674`, refreshed `2026-06-29T11:40:18-04:00`. This is now superseded by the completed implementation and generated-output rechecks recorded below.
- Initial scores and parent state before callback: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00005L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005L`, blank formal `RECONSTRUCTION_CPP`. Current applied target metadata is `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00005L`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, and blank formal `RECONSTRUCTION_CPP`.

## Initial Target State Before Callback

At report-only time, the target already had the correct semantic owner and useful binary evidence. The source-quality blocker was the metadata/formal-code combination: the page had a nonblank emitter route through [UID:00005L] while both formal C++ fields were blank. That combination caused the generator to emit [UID:000328] as an unresolved empty-emitter marker. This section is historical report-only context; the implementation callback cleared the emitter and the generated marker is now gone.

Useful current facts to preserve:

- Exact range `0x004672c0-0x004672fe`.
- Function start `sub_4672C0`, size `0x3e` / decimal `62` (Verified with MCP `int_convert`).
- Body resets `FunctionObject0::vftable` at `0x0061262c`, calls `sub_4F4A90`, tests scalar deleting flags `1` and `4`, conditionally calls `sub_4F4AC0`, and calls `@_guard_check_icall_nop@4` on the guard path.
- Guard-size immediate is `0x04` / decimal `4` (Verified with MCP `int_convert`).
- Reachability is vtable/data only: one data ref from `0x0061262c`, no code xrefs/callers.
- Sibling [UID:000327] has the same destructor shape but uses guard size `0x18` / decimal `24` and has five callback-vtable pointer cells.

## Supervisor Active Recheck At Report Time

The initial supervisor assignment was report-only research for [UID:000328] from the FunctionObjects empty-emitter queue. It explicitly required current IDA MCP evidence, support-doc review, old-report search, owner/source-route reanalysis, and a first-draft C++ versus no-code disposition. Supervisor MCP all-clear at that time named active session `c9671f69` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; this report did not use stale session `d4d50b81` as current evidence. After implementation, supervisor reported `c9671f69` stale/dead and named `b2ae72ec` for any future MCP-backed verification.

No split repair is needed. [UID:000328] is already an exact child of the mixed [UID:0000YU] neighborhood, and MCP confirms the target function is one exact `0x3e` byte function preceded by `0xcc` padding from `0x004672b7-0x004672c0` and followed by `0xcc` padding from `0x004672fe-0x00467300`.

## Inference Research Guidance Check

Direct IDA/MCP facts drive the range, bytes, body, xref, and negative endpoint findings. Documentation evidence drives the source-family route through [UID:00005L] `FunctionObject0` and [UID:0000JO] `FunctionObjects`. Inference is limited to source-shape classification: this exact binary body is compiler/linker-emitted scalar deleting destructor support from shared callback class/template declarations and should not be represented as a handwritten function body.

The initial generated output was treated as a symptom, not authority. Older "blank C++ because not final-source-ready" wording is superseded for this exact target by current by-structure rules and the accepted FunctionObjects scalar-destructor policy already applied to sibling [UID:000327].

## Heuristic / Inference Reanalysis And Validation

Source-quality issue: empty-emitter marker.

Resolution: clear `EMITTER_UIDS:` on the target and keep blank formal C++. This is implementation-ready because target-local evidence proves compiler-emitted scalar destructor glue, and current FunctionObjects support policy says scalar deleting destructor pages should be non-emitting metadata when their source representation is the shared declaration.

Source-quality issue: owner/source placement.

Resolution: keep `CANONICAL_OWNER:00005L`. The body writes `FunctionObject0::vftable`, the only pointer cell is the `FunctionObject0` vtable slot itself, and [UID:00005L] is the narrow semantic class owner. [UID:0000JO] remains the source-file family through the class, but [UID:000328] itself should not emit generated source.

Source-quality issue: formal C++.

Resolution: no formal C++ and no formal comment marker. A handwritten scalar deleting destructor body would be decompiler-shaped compiler glue. A comment-only marker would still emit artificial source text for scalar destructor glue and would broaden the current comment-only invoke/object-size precedent beyond policy. The no-code proof belongs in target prose.

Source-quality issue: split/range.

Resolution: no split or merge. The target is exactly one modeled function with padding before and after; [UID:0000YU] already carries the mixed-neighborhood inventory.

Rejected alternatives:

- Keep `EMITTER_UIDS:00005L`: rejected because it preserves the generated empty-emitter marker with blank formal C++.
- Add a formal destructor body: rejected because the body is compiler-generated scalar deleting destructor glue, not plausible handwritten source.
- Add a formal comment marker: rejected because current FunctionObjects policy reserves comment-only formal proof for proven invoke and object-size virtual wrappers, not scalar destructor glue.
- Set `RECONSTRUCTABLE:FALSE`: rejected because the shared `FunctionObject0` declaration/destructor semantics must still exist in rebuilt source.
- Reassign to [UID:0000JO] directly: rejected because [UID:00005L] is the narrower semantic class owner and already routes to the file family.
- Reassign to Application, PasswordError, RegistryConfig, WinMain, or [UID:0000YU]: rejected because adjacency in the mixed neighborhood is not source ownership evidence.

## Evidence Standards Used

Evidence used:

- MCP `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `find_bytes`, `make_signature_for_range`, `entity_query`, and `int_convert` in current session `c9671f69`.
- Current target/support docs: [UID:000328], [UID:000327], [UID:0000YU], [UID:00005L], [UID:00005K], [UID:0000JO], and [UID:0001WQ].
- Generated symptom docs: `auto-generated/NexusTK/util/FunctionObjects.cpp` and `auto-generated/-ag-research-tracker.md`.
- Existing report leads: executed B001 [UID:0000YU], executed B007 [UID:000327], and executed B008 [UID:00032C].

The evidence is strong enough because independent signals agree: exact body shape, vtable-only reachability, `FunctionObject0` vtable reset, guard size, sibling contrast, current support policy, and generated-output symptom all point to non-emitting metadata rather than source-body emission.

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks performed:

- Supervisor all-clear reported session `c9671f69`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19076`.
- `server_health(database='c9671f69')`: `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x004672c0` is `sub_4672C0`, size `0x3e`; `0x004672fe` is not a function; sibling `0x004671f0` is `sub_4671F0`, size `0x3e`; `0x0046722e` is not a function; neighboring `0x00467230` and `0x00467300` are separate functions.
- `analyze_function` / `decompile` / `disasm` on `0x004672c0`: confirmed vtable reset, cleanup/free callees, scalar-delete flag gates, `push 4`, 26 instructions, no strings, no callers.
- `xrefs_to` / `xref_query`: one data ref to `0x004672c0` from `0x0061262c`, no code xrefs, no refs to endpoint `0x004672fe`.
- `find_bytes`: little-endian pointer pattern `c0 72 46 00` found only at `0x0061262c`; endpoint pattern `fe 72 46 00` not found; sibling pointer pattern `f0 71 46 00` found at five callback vtable cells; endpoint pattern `2e 72 46 00` not found.
- `make_signature_for_range 0x004672b7-0x00467300`: confirmed nine `0xcc` bytes before the target, exact target bytes, and two `0xcc` bytes after the target. The target byte sequence includes `6A 04` on the guard path.
- `entity_query 0x00612620-0x00612644`: names `0x0061262c` as `??_7FunctionObject0@@6B@`; next named item is unrelated `aWin9502d02d` at `0x00612640`.
- `xrefs_to 0x0061262c`: only the two destructor bodies write the vtable address as data refs from `0x004671f6` and `0x004672c6`.
- Sibling check on `0x004671f0`: same destructor body shape, same callees, no code callers, five data refs, guard path `push 18h`.
- `int_convert`: verified `0x3e` equals decimal `62`, `0x04` equals decimal `4`, and `0x18` equals decimal `24`.

Docs/reports checked:

- `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`
- `by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md`
- `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`
- `by-class/FunctionObject0.md`
- `by-class/FunctionObject.md`
- `by-file/FunctionObjects.md`
- `by-type/by-template/FunctionObjectTemplates.md`
- `auto-generated/NexusTK/util/FunctionObjects.cpp`
- `auto-generated/-ag-research-tracker.md`
- `executed-b-agent-research/B001/0000YU-ApplicationFunctionObject0Callbacks.md`
- `executed-b-agent-research/B007/000327-FunctionObject0ScalarDeletingDestructorVariant24-empty-emitter-source-quality.md`
- `executed-b-agent-research/B008/00032C-PlainMemberFunctionObject0ApplicationGetObjectSize-empty-emitter-source-quality.md`

Report search terms used:

`000328`, `004672c0`, `FunctionObject0ScalarDeletingDestructorVariant4`, `FunctionObject0`, `FunctionObjects`, `ApplicationFunctionObject0Callbacks`, `000327`, and `00005L`.

Failed, unavailable, or intentionally skipped checks:

- No broad unbounded function/global/string/callgraph searches were run.
- No IDA DB edits, saves, renames, type edits, or process management were performed.
- Historical report-only phase note: no validators were run during the initial research pass because no by-* docs were edited at that time. This is superseded by the completed implementation callback validators recorded in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:000328] is exactly `0x004672c0-0x004672fe`, `sub_4672C0`, size `0x3e` / decimal `62`. | High | MCP `lookup_funcs`, `int_convert`, endpoint not a function. | Target `IDA Evidence`; [UID:00005L] support evidence; [UID:0000JO]/[UID:0001WQ] scalar policy examples | incorporate | applied; target/class/file/template docs updated; validators `000000000683`, `000000000686`, `000000000696`, `000000000699` passed |
| C2 | The body resets `FunctionObject0::vftable`, calls `sub_4F4A90`, tests scalar-delete flags `1` and `4`, conditionally calls `sub_4F4AC0`, and uses guard-size `0x04` / decimal `4`. | High | MCP `decompile`, `disasm`, `analyze_function`, `callees`, `int_convert`. | Target `Behavior` / `IDA Evidence`; [UID:00005L] evidence; [UID:0000JO]/[UID:0001WQ] scalar policy text | incorporate | applied; target no-code proof and all required support policy docs record `0x04` / decimal `4` |
| C3 | Reachability is vtable/data only: one data ref at `0x0061262c`, no code callers or code xrefs. | High | MCP `analyze_function`, `xrefs_to`, `xref_query`, `find_bytes`. | Target `IDA Evidence` / no-code proof; [UID:00005L] support evidence; [UID:0000JO] support evidence | incorporate | applied; target/support docs state local vtable data ref only and no code callers/refs |
| C4 | `0x0061262c` is named `??_7FunctionObject0@@6B@`; the target is the scalar deleting destructor slot for the `FunctionObject0::vftable` itself. | High | MCP `entity_query`, `xrefs_to`, `decompile`, target/support docs. | Target ownership/no-code proof; [UID:00005L], [UID:0000JO], [UID:0001WQ] support notes | incorporate | applied; direct owner kept as [UID:00005L], source route kept through FunctionObjects policy |
| C5 | Endpoint `0x004672fe` is not a function, has no refs, has no pointer pattern, and is followed by `0xcc` padding. | High | MCP `lookup_funcs`, `xrefs_to`, `xref_query`, `find_bytes`, `make_signature_for_range`. | Target `IDA Evidence` / `No-Code Proof` / `Rejected Alternatives` | incorporate | applied; target records endpoint negatives, raw pointer negatives, and `CC` padding boundaries |
| C6 | Sibling [UID:000327] is the same scalar destructor shape but with guard size `0x18` / decimal `24` and five callback-vtable pointer cells. | High | MCP `lookup_funcs`, `disasm`, `analyze_function`, `xrefs_to`, `find_bytes`; current sibling doc and executed B007 report. | Target sibling-comparison note; [UID:00005L]/[UID:0000JO]/[UID:0001WQ] support policy notes | incorporate | applied; target and support docs preserve UID000327/UID000328 sibling contrast |
| C7 | Keep `CANONICAL_OWNER:00005L` and `RECONSTRUCTABLE:TRUE`; clear `EMITTER_UIDS:` and leave formal C++ blank. | High | Current owner evidence, by-structure source-declared/generated-binary rule, executed B007 scalar-destructor precedent, generated empty-emitter symptom. | Target metadata and no-code proof; support policy docs | incorporate | applied; target validator `000000000683` confirmed owner `00005L`, completion `87`, confidence `90`, blank emitter, blank formal C++ |
| C8 | Do not add a formal destructor body or comment marker for this scalar destructor. | High | Compiler-emitted destructor shape; current FunctionObjects support policy; rejected body/marker alternatives. | Target `No-Code Proof` / `Rejected Alternatives`; [UID:0000JO]/[UID:0001WQ] scalar policy text | incorporate | applied; formal blocks remain blank and support docs keep comment-only markers limited to invoke/object-size wrappers |
| C9 | Generated `FunctionObjects.cpp` currently shows [UID:000328] as an Empty Emitter Marker under command `000000000674`. | High | Read-only generated file check. | Target current/generated symptom history; implementation validator/generated proof after callback | incorporate | applied; initial symptom preserved in prose, refreshed generated `FunctionObjects.cpp` header `000000000695` at `2026-06-29T12:15:45-04:00` no longer contains `UID:000328` as an Empty Emitter Marker |
| C10 | No split, child creation, rename, new file, IDA rename/type/comment, or manual coverage edit is needed for this target. | High | Exact function/padding evidence; existing [UID:0000YU] split inventory; assignment scope. | Target `Rejected Alternatives`; checklist; support-doc non-edit note for parent aggregate | incorporate | applied/excluded-with-reason; no split, rename, new child, IDA DB edit, manual coverage edit, optional parent edit, or optional vtable edit performed |

## Positive Evidence Summary

- The target is one exact scalar deleting destructor body with no strings, no ordinary callers, and only vtable/data reachability.
- The body's only semantic work is destructor glue: vtable reset, base cleanup, delete-flag checks, optional free, guard helper.
- The only pointer cell is `0x0061262c`, named `FunctionObject0::vftable`, making [UID:00005L] the narrow semantic owner.
- The direct class owner [UID:00005L] already documents `FunctionObject0` as source-declared callback-base support under [UID:0000JO] `FunctionObjects`.
- Executed B007 [UID:000327] established the matching scalar-destructor policy for the sibling variant: blank formal C++ plus blank `EMITTER_UIDS:` rather than handwritten or comment-marker destructor output.

## IDA MCP Facts

- `sub_4672C0` starts at `0x004672c0`, size `0x3e` / decimal `62` (Verified with MCP `int_convert`).
- `0x004672fe` is not a function.
- `0x004672b7-0x004672c0` is nine `0xcc` padding bytes before the target.
- `0x004672fe-0x00467300` is two `0xcc` padding bytes after the target.
- Instruction `0x004672c6` writes `0x0061262c`, named `??_7FunctionObject0@@6B@`, into `*this`.
- Disassembly includes `push 4` on the guard path at `0x004672ec`, confirming guard size `0x04` / decimal `4` (Verified with MCP `int_convert`).
- `xrefs_to 0x004672c0` reports one data ref from `0x0061262c`.
- `xref_query` reports no code xrefs to `0x004672c0`.
- `find_bytes c0 72 46 00` finds only `0x0061262c`.
- `0x004672fe` has no xrefs and no `fe 72 46 00` pointer-pattern hit.
- Sibling `0x004671f0` has the same destructor shape, guard path `push 18h`, five data refs, and no code callers.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004672c0-0x004672fe` | [UID:000328] `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md` | base/small `FunctionObject0::vftable` scalar deleting destructor glue | TRUE | keep `00005L`; clear emitter | current `85/88`, recommend `87/90` | target of this report |
| `0x004671f0-0x0046722e` | [UID:000327] `by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md` | 24-byte callback-template scalar deleting destructor glue | TRUE | `00005L`; emitter already blank | `87/90` | accepted/executed sibling precedent |
| `0x004671a0-0x004673f6` | [UID:0000YU] parent aggregate | mixed neighborhood / split inventory | FALSE | NONE | `88/90` | no target edit needed |
| `0x0061262c-0x00612640` | [UID:0003OE] `FunctionObject0VtableData` | `FunctionObject0::vftable` data containing target pointer | TRUE | [UID:0000JO] currently | `88/92` | support evidence only; no required metadata change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004672c0` | Data ref from `0x0061262c`; no code xrefs/callers | vtable-only scalar destructor reachability |
| `0x0061262c` | Named `??_7FunctionObject0@@6B@`; refs from `0x004671f6` and `0x004672c6` as vtable reset constants | direct `FunctionObject0::vftable` evidence |
| `0x004672fe` | no xrefs; pointer pattern absent | exact half-open endpoint |
| `0x004671f0` | five sibling data refs from callback vtables | contrast with 24-byte callback-template variant |
| `sub_4F4A90` | callee from target | base cleanup / `LObject`-family cleanup helper |
| `sub_4F4AC0` | conditional callee from target | ordinary delete/free helper |
| `@_guard_check_icall_nop@4` | guard-path callee after `push 4` | compiler/security guard helper |

## Documentation Evidence And IDA Status

- [UID:000328] already documents exact range, behavior, class owner, source family, and sibling contrast, but it still has `EMITTER_UIDS:00005L` with blank formal C++.
- [UID:000327] is now the accepted sibling precedent: same scalar-destructor family, blank formal C++, blank `EMITTER_UIDS:`, target prose no-code proof, and no handwritten/comment-marker destructor output.
- [UID:00005L] documents `FunctionObject0` as the zero-argument callback-base class under [UID:0000JO] `FunctionObjects`, with [UID:000328] as the guard-size-4 destructor child.
- [UID:0000JO] and [UID:0001WQ] distinguish scalar deleting destructor targets from invoke/object-size wrappers: scalar destructor pages should remain source-declared/generated-binary metadata with blank formal C++ and blank `EMITTER_UIDS:` unless a future supervisor explicitly approves a nonblank formal marker.
- [UID:0000YU] is a reviewed mixed, non-emitting split inventory. It should not become the owner/emitter for this exact child.
- Generated `FunctionObjects.cpp` line 69 confirms the unresolved generated symptom for [UID:000328].

## Ranked Ownership Analysis

### 1. [UID:00005L] FunctionObject0

- Evidence for: target writes `FunctionObject0::vftable` at `0x0061262c`; the only pointer cell to `0x004672c0` is the `FunctionObject0::vftable` entry; current class docs already own both destructor variants; source family routes through [UID:0000JO].
- Evidence against: exact original class declaration spelling and header basename remain inferred rather than source-proven.
- Decision: keep as direct semantic owner.

### 2. [UID:0000JO] FunctionObjects by-file source family

- Evidence for: shared callback-template/base policy, valid `NexusTK/util/` source root, FunctionObjects/template support docs, and accepted scalar-destructor policy.
- Evidence against: by-structure says direct owner should be the narrow semantic class/type when available; [UID:0000JO] is the source-file family, not the direct target owner.
- Decision: keep as source-family route through [UID:00005L]; do not set it as direct owner for [UID:000328].

### 3. [UID:0000YU] mixed parent aggregate

- Evidence for: physically contains the target range.
- Evidence against: executed B001 proves the interval is mixed and non-emitting; exact children carry source ownership. The span contains StringBase, Application, PasswordError, RegistryConfig, WinMain, and FunctionObjects children.
- Decision: reject as source owner/emitter.

### 4. Feature consumers / neighboring classes

- Evidence for: physical adjacency to Application and PasswordError destructor support in the mixed neighborhood.
- Evidence against: no direct code callers; the only pointer cell is `FunctionObject0::vftable`, not a feature vtable or construction site.
- Decision: reject. Adjacency is not ownership evidence.

### 5. No-owner / non-reconstructable

- Evidence for: current empty marker may look like an unresolved output route.
- Evidence against: owner is known and source declaration/destructor semantics are rebuild-relevant. The defect is target-level emission, not ownership or reconstructability.
- Decision: reject no-owner and `RECONSTRUCTABLE:FALSE`. Use known owner plus blank emitter.

## Source Placement

- Recommended source placement: source-declared/generated-binary metadata under [UID:00005L] `FunctionObject0`, with reusable source declaration semantics in [UID:0000JO] `FunctionObjects` / [UID:0001WQ] `FunctionObjectTemplates`.
- Why this fits: Visual C++ should regenerate scalar deleting destructor glue from the class/template declaration and vtable use; hand-authored source should not contain an address-shaped deleting destructor wrapper.
- Rejected placements: direct feature modules, mixed parent container, standalone helper file, and target-level generated C++ body.
- Remaining uncertainty: exact original header basename and final template/class spelling remain broader FunctionObjects source-reconstruction work. This does not block the target-local empty-emitter repair.

## Range / Split / Padding / Reclassification Analysis

- Exact function range remains `0x004672c0-0x004672fe`.
- Predecessor gap `0x004672b7-0x004672c0` is nine `0xcc` bytes.
- Successor gap `0x004672fe-0x00467300` is two `0xcc` bytes before the PasswordError destructor start.
- No split, merge, rename, child creation, or parent reclassification is needed.
- Parent [UID:0000YU] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter.

## Negative Evidence Summary

- No ordinary direct code callers were found for `0x004672c0`.
- No code xrefs were found for `0x004672c0`.
- No refs or pointer pattern were found for endpoint `0x004672fe`.
- No feature-owner pointer cell was found; the sole pointer is `FunctionObject0::vftable`.
- No evidence supports a formal handwritten destructor body or comment marker for scalar destructor glue.
- No evidence supports `RECONSTRUCTABLE:FALSE`; the shared declaration semantics remain source-relevant.

## IDA Rename / Type / Comment Recommendations

No IDA DB rename, type, or comment edits are recommended in this report-only pass.

The source-facing target name `FunctionObject0ScalarDeletingDestructorVariant4` remains useful and should not be renamed in this callback. It distinguishes the `0x04` guard-size base/small variant from sibling [UID:000327] with guard size `0x18` / decimal `24`. Exact original compiler symbol spelling is not necessary for the documentation repair and should not be forced into IDA.

## First-Draft C++ Recommendation

- Eligible for draft C++: no.
- Recommended formal content: inline `RECONSTRUCTION_CPP CODE` remains `[[[]]]`; multiline `RECONSTRUCTION_CPP CODE` block remains empty; `EMITTER_UIDS:` should be cleared to blank.
- Third-party import directive: not applicable.
- Reason code should remain blank: the body is compiler-generated scalar deleting destructor glue. It resets a vtable, calls base cleanup/free helpers, and tests deleting-destructor flags. Writing this as target-level C++ would create decompiler-shaped source that the original developers probably did not author. The source-level behavior belongs in the shared `FunctionObject0` / FunctionObjects declaration and destructor semantics so the compiler/linker can regenerate the deleting destructor support.
- Exact no-code proof to incorporate in target prose: [UID:000328] is non-emitting source-declared/generated-binary metadata for compiler-emitted `FunctionObject0` scalar deleting destructor glue. MCP session `c9671f69` confirms exact range `0x004672c0-0x004672fe`, a `0x3e` / decimal `62` byte body that resets `FunctionObject0::vftable`, calls `sub_4F4A90`, conditionally calls `sub_4F4AC0` through scalar-delete flag gates, uses guard-size `0x04` / decimal `4`, and is reached only through the `FunctionObject0::vftable` data cell at `0x0061262c`. The target intentionally keeps blank `EMITTER_UIDS:` and blank formal C++ because the human-written source representation is the shared FunctionObjects callback-base/template declaration, not a handwritten deleting-destructor body or artificial source marker.

## Final Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:00005L
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Recommended target prose changes:

- Add current MCP evidence from session `c9671f69`.
- Add the no-code proof above.
- Replace the current empty-emitter state with explicit non-emitting source-declared/generated-binary metadata.
- Preserve owner, vtable, callee, flag, guard-size, xref, sibling, padding, rejected-alternative, and generated-output facts.
- Refine the current "duplicate exact" wording: the sibling has the same destructor shape, but this target is the `0x04` guard-size base/small `FunctionObject0::vftable` variant rather than an exact byte duplicate of [UID:000327].

Items left unchanged:

- `CANONICAL_OWNER:00005L`
- `RECONSTRUCTABLE:TRUE`
- Formal C++ blocks blank
- Parent aggregate [UID:0000YU]
- Sibling [UID:000327], already handled by executed B007 report

## Recommended Target Doc Changes

Target path: `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`

Exact report facts to incorporate:

- Current MCP session `c9671f69` and health facts.
- Exact function/range facts and padding proof.
- Body evidence: vtable reset, `sub_4F4A90`, `sub_4F4AC0`, `_guard_check_icall_nop`, scalar-delete flag gates, and guard size `0x04` / decimal `4`.
- Xref evidence: one `FunctionObject0::vftable` data ref, no code callers, no endpoint refs or pointer pattern.
- Sibling comparison: [UID:000327] same destructor shape, `push 18h`, five pointer cells; already resolved as non-emitting scalar destructor metadata.
- Generated symptom: `FunctionObjects.cpp` currently emits [UID:000328] as an Empty Emitter Marker under command `000000000674`.
- Rejected alternatives: no handwritten body, no formal marker, no feature owner, no direct file-owner bypass, no split, no `RECONSTRUCTABLE:FALSE`.

Metadata/score/owner/emitter/reconstructable/C++ changes:

- Change `COMPLETION:85` to `COMPLETION:87`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:00005L`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS:00005L` to blank `EMITTER_UIDS:`.
- Keep inline and multiline `RECONSTRUCTION_CPP CODE` blank.

## Recommended Support Doc Changes

Support path: `by-class/FunctionObject0.md`

- Preserve [UID:000327] and [UID:000328] as exact destructor support children.
- Add that [UID:000328] is non-emitting source-declared/generated-binary metadata after B010 current MCP proof, with blank formal C++ and blank `EMITTER_UIDS:`.
- Refine the method row/status wording so [UID:000328] follows the accepted scalar deleting destructor policy rather than remaining a blank nonblank-emitter page.
- Preserve the [UID:00005L] class-level route through [UID:0000JO] `FunctionObjects`.

Support path: `by-file/FunctionObjects.md`

- Add [UID:000328] explicitly to the scalar deleting destructor compiler-artifact caveat list beside [UID:000327].
- State that accepted scalar deleting destructor metadata pages such as [UID:000327] and [UID:000328] keep blank formal C++ and blank `EMITTER_UIDS:` unless a future supervisor explicitly approves nonblank formal marker content.
- Keep the comment-only marker precedent limited to proven invoke/object-size wrappers, not scalar destructor glue.

Support path: `by-type/by-template/FunctionObjectTemplates.md`

- Add [UID:000328] as the `FunctionObject0` `0x04` guard-size scalar deleting destructor example under the existing scalar deleting destructor no-code policy.
- Preserve the source-declared/generated-binary explanation: the shared template/base declarations are source, while exact scalar deleting destructor bodies are compiler/linker output.

Support path: `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`

- No required metadata or body edit. If touched during implementation, add only a short cross-reference note that [UID:000328] is now non-emitting metadata; the parent aggregate remains `RECONSTRUCTABLE:FALSE`, owner blank, and non-emitting.

Support path: `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`

- No required metadata edit. If touched, preserve it as vtable support evidence that `0x0061262c -> 0x004672c0`.

No manual coverage-report, generated report, validator state, IDA DB, or project-level generated file edits are recommended.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00005L`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005L`
- Formal reconstruction block: blank

Recommended score/metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00005L`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:` blank
- Formal reconstruction block: blank

Score rationale:

- Completion rises because the target-local empty-emitter blocker is resolved into an implementation-ready metadata/no-code repair, and the report adds current MCP proof for exact range, bytes, vtable refs, padding, endpoint negatives, and formal C++ disposition.
- Confidence rises because current MCP confirms all target-local behavior and negative evidence, and current FunctionObjects policy resolves the previous blank-emitter ambiguity.

Reason not higher:

- Exact original header basename and final template/class declaration spelling remain broader FunctionObjects source reconstruction work.
- This report does not audit every remaining FunctionObjects empty emitter.
- Final project C++ for the shared FunctionObjects declaration remains outside this target-level report-only assignment.

Score-limiting blockers researched:

- Empty-emitter marker: resolved by recommended blank `EMITTER_UIDS:` plus no-code proof.
- Formal C++ question: resolved as blank formal C++; body and comment marker rejected.
- Owner/source placement: resolved as semantic owner [UID:00005L], non-emitting target.
- Range/split question: resolved; exact function with padding and no hidden endpoint refs.
- Consumer/neighbor ownership question: resolved; adjacency and vtable consumers do not override the `FunctionObject0::vftable` owner evidence.

## Open Questions With Attempted Resolution

Open question: should [UID:000328] emit a formal first-draft C++ body?

Resolution: no. MCP proves this is scalar deleting destructor glue. Current support policy rejects handwritten scalar destructor bodies for this family.

Open question: should [UID:000328] emit a formal comment-only no-code marker?

Resolution: no. The accepted comment-only marker precedent is for proven invoke wrappers and object-size virtuals, not scalar deleting destructor glue. For scalar destructor pages, blank formal C++ plus blank emitter is the current policy.

Open question: should `CANONICAL_OWNER` be cleared or changed to [UID:0000JO]?

Resolution: no. [UID:00005L] is the narrower semantic class owner. Clearing the emitter does not require losing class-owner evidence.

Open question: should the page be `RECONSTRUCTABLE:FALSE`?

Resolution: no. The exact emitted body should not be hand-emitted, but the shared `FunctionObject0` declaration/destructor semantics are still source-relevant for rebuild.

Remaining unresolved question: exact original FunctionObjects header/template spelling.

Impact: does not block [UID:000328] metadata repair. It keeps the score below final-audit territory and belongs to broader FunctionObjects source reconstruction, not this target-local empty-emitter fix.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is recommended.

The generated `auto-generated/-ag-*` reports and generated `FunctionObjects.cpp` were refreshed through normal scoped validator/generator flow during the accepted by-* implementation. Do not manually edit generated reports, manual `-coverage-report.md` files, supervisor ledgers, or validator state for this report.

## Follow-Up Actions

Supervisor actions after completed callback:

- Verify the completed by-* doc implementation, updated ledger/checklist, validator results, and generated-output proof.
- If verification passes, execute the report with the validator-owned executed-report command.

Historical proposed B010 implementation callback actions:

- These proposed actions were completed during the implementation callback.
- Target/support docs were edited under short leases, target metadata and no-code proof were applied, support-doc policy updates were incorporated, scoped validators ran for every edited by-* doc, and generated `FunctionObjects.cpp` was checked read-only for removal of the [UID:000328] Empty Emitter Marker.

Future work:

- Broader FunctionObjects final template/header spelling remains future source-reconstruction work, not a blocker for this target.
- Remaining unrelated FunctionObjects empty markers should be handled by their own target-specific assignments; this report does not mass-migrate them.

## Confidence

- Recommendation confidence: high.
- Score confidence: `87/90` is justified after implementation because target-local binary facts and policy disposition are current and specific, while broader original-source declaration details are still inferred.
- Remaining uncertainty: exact original header basename/template spelling. It does not change the no-code metadata recommendation.

## Validator Results

Historical report-only phase:

- No validators were run during the initial research pass because no target/support by-* docs were edited at that time. This is historical context only; the implementation callback validator evidence below is the current validation state.

Implementation callback phase:

- `python .\tools\validator.py --mode file --file by-memory\0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md --apply --queue-timeout 240 --wait-generated`
  - Exit code: `0`.
  - Command ID/timestamp: `000000000683`, `2026-06-29T12:11:22-04:00`.
  - Result: `ok: 1`; target metadata updated to completion `87`, confidence `90`, canonical owner `00005L`; generated refresh completed with command ID `000000000683`.
- `python .\tools\validator.py --mode file --file by-class\FunctionObject0.md --apply --queue-timeout 240`
  - Exit code: `0`.
  - Command ID/timestamp: `000000000686`, `2026-06-29T12:11:38-04:00`.
  - Result: `ok: 1`; generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file\FunctionObjects.md --apply --queue-timeout 240 --wait-generated`
  - Exit code: `0`.
  - Command ID/timestamp: `000000000696`, `2026-06-29T12:15:47-04:00`.
  - Result: `ok: 1`; generated refresh completed. Scoped validator reported pre-existing FunctionObjects missing-reference warnings for old `[UID:000123]`, `[UID:0003LP]`, `[UID:000366]`, and `[UID:0003OQ]` references, but did not fail.
- `python .\tools\validator.py --mode file --file by-type\by-template\FunctionObjectTemplates.md --apply --queue-timeout 240`
  - Exit code: `0`.
  - Command ID/timestamp: `000000000699`, `2026-06-29T12:16:03-04:00`.
  - Result: `ok: 1`; generated refresh deferred. Scoped validator reported pre-existing FunctionObjects-template missing-reference warnings for old `[UID:000123]`, `[UID:0003LP]`, `[UID:000366]`, `[UID:000365]`, and `[UID:00036G]` references, but did not fail.
- Generated freshness: read-only check of `auto-generated\NexusTK\util\FunctionObjects.cpp` after the validator batch showed header `validator-command-id: 000000000695`, `validator-refreshed-at: 2026-06-29T12:15:45-04:00`. Continuation recheck after the corrected `goal.md` showed newer validator-owned header `validator-command-id: 000000000707`, `validator-refreshed-at: 2026-06-29T12:20:50-04:00`. In both checks, `rg` found no `UID:000328` line; [UID:000328] no longer appears as an Empty Emitter Marker.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B010/research/000328-FunctionObject0ScalarDeletingDestructorVariant4-empty-emitter-source-quality.md` during the report-only phase.

Modified in implementation callback:

- `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`
- `by-class/FunctionObject0.md`
- `by-file/FunctionObjects.md`
- `by-type/by-template/FunctionObjectTemplates.md`
- `tools/leaser/Agents/Agent-B010/research/000328-FunctionObject0ScalarDeletingDestructorVariant4-empty-emitter-source-quality.md`

Not modified:

- `by-class/FunctionObject.md` (goal continuation checked it; not applicable because UID000328 is `FunctionObject0::vftable` scalar deleting destructor metadata, while this page owns the separate base `FunctionObject` scalar deleting destructor support).
- `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md` (optional support doc not needed).
- `by-memory/0x004671f0-0x0046722e.FunctionObject0ScalarDeletingDestructorVariant24.md` (sibling UID000327 already contains the accepted non-emitting scalar-destructor policy and the UID000328 contrast at same-or-greater detail; no B010 edit needed).
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` (optional support doc not needed).
- Generated files, manual coverage reports, validator/tool state, IDA DB, executed archives, and supervisor ledgers were not manually edited.

Renamed:

- None.

Report execution:

- Not run. Execution remains supervisor-owned after verification.

Leases:

- Initial required-doc lease batch: B010 leased `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`, `by-class/FunctionObject0.md`, `by-file/FunctionObjects.md`, and `by-type/by-template/FunctionObjectTemplates.md` at `2026-06-29T16:04:37Z`, expiring `2026-06-29T16:09:37Z`.
- After that lease expired, B012 held `by-file/FunctionObjects.md` and `by-type/by-template/FunctionObjectTemplates.md` from `2026-06-29T16:10:10Z` to `2026-06-29T16:15:10Z`; B010 waited, rechecked the B010 text, and did not validate those files during B012's active lease.
- B010 re-leased target/class for validation, then released them successfully after validators `000000000683` and `000000000686`.
- B010 re-leased `by-file/FunctionObjects.md` and `by-type/by-template/FunctionObjectTemplates.md` after B012 expiry, then released them successfully after validators `000000000696` and `000000000699`.
- Final lease check: no active B010 leases remain; only unrelated B007 Application leases were present.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted by supervisor for callback on 2026-06-29.
- [x] Target doc update: `by-memory/0x004672c0-0x004672fe.FunctionObject0ScalarDeletingDestructorVariant4.md`. Applied in callback.
- [x] Support doc update: `by-class/FunctionObject0.md`. Applied in callback.
- [x] Support doc update: `by-file/FunctionObjects.md`. Applied in callback.
- [x] Support doc update: `by-type/by-template/FunctionObjectTemplates.md`. Applied in callback.
- [x] Optional support doc update only if touched: `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`. Not touched; not needed for contradiction/cross-reference.
- [x] Optional support doc update only if touched: `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`. Not touched; not needed for contradiction/cross-reference.
- [x] Corrected `goal.md` continuation named `by-class/FunctionObject.md` and sibling [UID:000327] as only-if-needed support. Checked on continuation: `by-class/FunctionObject.md` is not applicable to UID000328 because it documents the separate base `FunctionObject` destructor family, and sibling UID000327 already preserves the accepted non-emitting scalar-destructor contrast. No by-* edit needed.
- [x] Current target state and actual evidence checked recorded: MCP session `c9671f69`; generated `FunctionObjects.cpp` command `000000000674`; target/support docs and executed reports listed in `Evidence Checked`.
- [x] Claim And Incorporation Ledger updated with destination and report-only `proposed` verification state for every accepted claim; callback verification state now updated above.
- [x] Metadata/score changes to apply: target `85/88` to `87/90`; keep `CANONICAL_OWNER:00005L`; keep `RECONSTRUCTABLE:TRUE`; clear `EMITTER_UIDS:`; keep formal C++ blank. Applied and validated by command `000000000683`.
- [x] Score-limiting empty-emitter blocker researched to implementation-ready repair: blank emitter plus target no-code proof, not body or marker.
- [x] Owner/emitter/reconstructable changes to apply: semantic owner unchanged; target emitter cleared; reconstructable unchanged.
- [x] Split/rename/new-child changes to apply: none; exact range and parent aggregate preserved.
- [x] Source-placement/range/padding/reclassification facts to apply: source-declared/generated-binary metadata under FunctionObject0/FunctionObjects; exact padding at `0x004672b7-0x004672c0` and `0x004672fe-0x00467300`; no reclassification to false.
- [x] First-draft C++ or no-code proof to apply: no formal C++; no-code proof added to target prose.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: function size/body, vtable ref, no callers, endpoint negatives, sibling comparison, generated symptom, rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old blank-C++-with-emitter state rejected; no feature owner; no direct file-owner bypass; no `RECONSTRUCTABLE:FALSE`; no formal marker.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated output treated only as current symptom; old source-output/gate language superseded by current by-structure and FunctionObjects policy.
- [x] Open questions closed or documented as evidence-backed unresolved: final header/template spelling remains broader work.
- [x] Validators to run after accepted by-* edits: target with `--wait-generated`, plus every edited support by-* doc with scoped validator. Commands `000000000683`, `000000000686`, `000000000696`, and `000000000699`.
- [x] Generated report refresh completed: `FunctionObjects.cpp` refreshed and omits [UID:000328] Empty Emitter Marker; generated tracker refresh is validator-owned. Verified absent after refresh header `000000000695`, and still absent after continuation recheck header `000000000707`.
- [x] No manual supervisor-owned coverage/tracker text to apply.
- [x] Do not manually edit generated files, project-level generated files, manual `-coverage-report.md`, validator/tool state, IDA DB, executed archives, or supervisor ledgers.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and callback verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded with command id, timestamp, exit code, ok count, and generated refresh status.
- [x] Generated refresh completed by validator or queue/autogen follow-up recorded.
- [x] Leases taken only for accepted implementation edit batch and released or confirmed expired/no active lease.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/000328-FunctionObject0ScalarDeletingDestructorVariant4-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/000328-FunctionObject0ScalarDeletingDestructorVariant4-empty-emitter-source-quality.md","timestamp":"2026-06-29T12:30:58","uid":"000328"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
