** TARGET-REPORT-UID:000324 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 000324 PlainMemberFunctionObject0 Application Invoke Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000324] `by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md` as the exact `PlainMemberFunctionObject0<Application>::Invoke` compiler-emitted callback-template wrapper owned by [UID:0000AJ] `PlainMemberFunctionObject0<void (__thiscall Application::*)(), Application>`.
- Final disposition: preserve `CANONICAL_OWNER:0000AJ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000AJ`, raise the target from `85/88` to `87/90`, and replace the blank formal C++ block with a comment-only generated-binary proof marker. Do not write a handwritten invoke body.
- Required action: after supervisor validation, update the target page with current MCP session `d4d50b81` evidence, exact body/xref/byte/vtable/construction-site facts, comment-only formal C++ text, and score rationale. Refresh the direct class and FunctionObjects support docs where they still imply old `95/95` blank-block policy.
- Confidence: strong. Live IDA MCP confirms the exact half-open function range, five-instruction body, four data-only vtable refs, zero code xrefs, successor padding, Application construction-store route, and sibling object-size virtual. Remaining uncertainty is original shared FunctionObjects header/template spelling, not target-local behavior or owner/emitter route.

## Target

- Target UID: `000324`.
- Target path: `by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md`.
- Assignment id: `B002-empty-emitter-report-000324-PlainMemberFunctionObject0ApplicationInvoke-20260629`.
- Source queue/report row: `auto-generated/NexusTK/util/FunctionObjects.cpp` currently lists [UID:000324] at `Completion:85 | Confidence:88 | Empty Emitter Marker`.
- Current supervisor classification: report-only source-quality research for an empty emitter; live IDA MCP required.
- Current score and parent state: target page is `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AJ`, blank formal C++; direct owner [UID:0000AJ] is `85/86` and emits through [UID:0000JO] `FunctionObjects`.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AJ`, blank `EMITTER_POSITION_OPTIONAL`, blank inline and multiline `RECONSTRUCTION_CPP CODE`.
- Existing owner/emitter/reconstructable state: already assigned to the correct concrete callback-wrapper class [UID:0000AJ], with emitter chain through [UID:0000AJ] to [UID:0000JO] `FunctionObjects`.
- Existing C++/emitter state: eligible routed emitter by current combined-score gate, but generated `FunctionObjects.cpp` shows only an Empty Emitter Marker because formal C++ is blank.
- Existing stale assumptions/blockers: the direct class page still says C++ remains blank below an old `95/95` reconstruction-code gate. Current `by-structure.md` uses the combined-score/emitter gate and requires a target-specific C++ or no-code disposition instead of silently leaving an eligible emitted item blank.
- Related docs checked: target page, direct class [UID:0000AJ], [UID:00005L] `FunctionObject0`, [UID:00005K] `FunctionObject`, [UID:0000JO] `FunctionObjects`, [UID:0001WQ] `FunctionObjectTemplates`, parent container [UID:0000YU], sibling [UID:00032C], vtable/RTTI pages [UID:0003OF]/[UID:000486], construction site [UID:0002H3] `ApplicationRequestExit`, generated `auto-generated/NexusTK/util/FunctionObjects.cpp`, and matching executed reports listed below.

## Executive Recommendation

[UID:000324] should remain an emitting exact by-memory child, but the emitted content should be a comment-only no-code proof marker, not a handwritten C++ body and not blank C++.

The target is analogous to accepted invoke-wrapper precedents [UID:0002N2] `MusicControlDialogFolderCallbackInvoke` and [UID:0001N5] `UserPaneDoubleParamCallback`: the exact machine-code body is compiler-generated template glue, while the human source belongs in the shared FunctionObjects template declaration and the feature construction site. For this target, the feature construction site is [UID:0002H3] `ApplicationRequestExit`, which allocates a 24-byte callback object, stores the `PlainMemberFunctionObject0<Application>` vtable at `0x00464ec6`, stores target helper `0x00464e20` at `+0x08`, stores zero adjustment at `+0x0c`, and stores the `Application` object at `+0x10`.

Recommended formal C++ insertion:

```cpp
// Compiler-emitted invoke wrapper for PlainMemberFunctionObject0<Application>;
// generated from the shared FunctionObjects template declaration and the
// Application::RequestExit binding in [UID:0002H3].
```

This resolves the empty-emitter state without inventing a standalone method body. Clearing `EMITTER_UIDS:` is rejected for this target because invoke-wrapper policy has accepted comment-only generated-binary markers when the route is proven; blank emitters are reserved for targets that should not contribute even a marker, such as accepted non-emitting scalar-destructor metadata pages after emitter clearing.

## Supervisor Active Recheck

- Supervisor instruction: B002 report-only research for [UID:000324], required report path `tools/leaser/Agents/Agent-B002/research/000324-PlainMemberFunctionObject0ApplicationInvoke-empty-emitter-source-quality.md`.
- Split repair: not required. Current [UID:0000YU] container and B001 executed split report already made this an exact child. Live MCP reconfirmed `0x004671a0` size `0x0d` and `0x004671ad` as not a function, with `CC CC CC` alignment bytes after the end.
- Source-bearing children in scope: no child creation is required. Sibling [UID:00032C] `0x004673f0-0x004673f6` remains the object-size virtual and is assigned to another agent for its own empty-emitter report.
- Report-only restrictions followed: no by-* docs, generated files, validator/tool state, IDA DB state, executed archives, supervisor ledgers, leases, or coverage reports were edited.
- Implementation callback `B002-implement-000324-PlainMemberFunctionObject0ApplicationInvoke-20260629` applied on 2026-06-29 after supervisor acceptance. The accepted by-* edits were made directly; generated output was inspected read-only after validator refresh.

## Inference Research Guidance Check

Direct IDA facts, documentation evidence, and inference are separated below. Current by-structure rules were applied: `CANONICAL_OWNER` records the narrow semantic owner, `EMITTER_UIDS` records output routing, and eligible routed reconstructable items need an explicit formal-code or no-code disposition. The target satisfies the minimum gate because it is `85/88`, reconstructable, and has a nonblank emitter route to generated `FunctionObjects.cpp`.

Stale old-gate wording was treated as a documentation artifact, not a reason to keep the blank block. Wave2/Wave3 material was not used as evidence. Generated output was used only as current symptom evidence for the empty emitter.

## Heuristic / Inference Reanalysis And Validation

- Generated name: `sub_4671A0` remains an IDA/search alias only. Source-facing role should be `PlainMemberFunctionObject0<Application>::Invoke` or "compiler-emitted invoke wrapper for `PlainMemberFunctionObject0<Application>`".
- Behavior: the five-instruction body uses the callback-object `this` pointer in `ecx`, reads the captured target pointer at `+0x10`, adds the stored `this` adjustment at `+0x0c`, loads the member callback pointer at `+0x08`, and tail-jumps to that pointer. This is exactly the expected zero-argument member-function callback invoke glue.
- Liveness/reachability: zero ordinary code callers is positive evidence here, not dead-code evidence. Live MCP reports four data refs to `0x004671a0`; byte search finds the function pointer only at those four vtable slots.
- Construction-site validation: `ApplicationRequestExit` constructs this concrete callback object for the deferred shutdown path. Live MCP decompilation and disassembly show 24-byte allocation, `LObject`/base initialization, vtable store `0x00612e40`, target helper `0x00464e20`, zero adjustment, and captured Application object.
- Source placement: reusable template source belongs under [UID:0000JO] `FunctionObjects`; the concrete binding belongs in [UID:0002H3] `ApplicationRequestExit`. The exact by-memory target documents the generated binary wrapper and should emit a comment marker only.
- Final C++ blocker: resolved to comment-only formal C++. A real C++ body would mirror compiler output and overfit decompiler syntax; a blank block preserves the current empty-emitter bug despite available target-local proof.

Rejected alternatives:

- Handwritten invoke body: rejected because this is generated template glue, not source-authored Application logic.
- Blank formal C++ with nonblank emitter: rejected because the current route and evidence meet the no-code marker policy used by accepted invoke-wrapper targets.
- Clearing `EMITTER_UIDS:`: rejected because the target is a proven invoke-wrapper emitted special case, unlike scalar deleting destructor metadata pages where the accepted fix may be blank emitter plus blank formal C++.
- Application as canonical owner: rejected because Application owns construction and target helper behavior, not the reusable callback-wrapper implementation.
- `FunctionObjects` file as direct canonical owner: rejected because by-structure prefers the narrow class owner when the exact method belongs to [UID:0000AJ] and that class clears the gate.
- No-owner/non-emitting: rejected because the vtable, construction site, direct class owner, and emitter chain are proven.

## Evidence Standards Used

Evidence used in this pass:

- IDA MCP live session `d4d50b81`: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `get_int`, `find_bytes`, `entity_query`, and `make_signature_for_range`.
- `tools/int_convert.py` for numeric conversions: `0x0d` is 13 decimal, `0x18` is 24 decimal, and `0x03` is 3 decimal (Verified with `tools/int_convert.py`).
- Current by-* docs, generated `FunctionObjects.cpp`, and matching executed B reports as lead/support evidence.
- Negative evidence: no code xrefs/callers to the wrapper, no endpoint refs/pointer bytes, no ordinary caller path, no broader owner for the mixed parent container.

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks performed:

- `idb_list`: active session `d4d50b81`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19640`, `is_analyzing:false`.
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs`: `0x004671a0` is `sub_4671A0`, size `0x0d` / 13 decimal (Verified with `tools/int_convert.py`); `0x004671ad` is not a function. Sibling `0x004673f0` is `sub_4673F0`, size `0x06`; `0x004673f6` is not a function. Construction site `0x00464e40` is `sub_464E40`, size `0xf4`.
- `analyze_function 0x004671a0`: one basic block, complexity `1`, no callees, no callers, four data xrefs at `0x00612e4c`, `0x0061d00c`, `0x0061d244`, and `0x0061fee4`.
- `decompile 0x004671a0`: calls stored member-function pointer at `this+0x08` with adjusted target `*(this+0x0c) + *(this+0x10)`.
- `disasm 0x004671a0`: five instructions: `mov eax, ecx`; `mov ecx, [eax+10h]`; `add ecx, [eax+0Ch]`; `mov eax, [eax+8]`; `jmp eax`.
- `xrefs_to` / `xref_query`: zero code xrefs to `0x004671a0`; four data xrefs to `0x004671a0`; no xrefs to endpoint `0x004671ad`; sibling `0x004673f0` has fourteen data refs; vtable base `0x00612e40` has one data xref from `0x00464ec6` inside `ApplicationRequestExit`.
- `get_bytes`: target bytes are `8b c1 8b 48 10 03 48 0c 8b 40 08 ff e0`; `0x004671ad-0x004671b0` is `cc cc cc`; sibling object-size bytes are `b8 18 00 00 00 c3`; `0x00612e3c-0x00612e54` contains RTTI/COL pointer plus vtable dwords.
- `get_int`: `0x00612e3c -> 0x0064222c`; `0x00612e40 -> 0x004671f0`; `0x00612e44 -> 0x004f4b10`; `0x00612e48 -> 0x0041b6c0`; `0x00612e4c -> 0x004671a0`; `0x00612e50 -> 0x004673f0`.
- `find_bytes`: little-endian `0x004671a0` occurs only at `0x00612e4c`, `0x0061d00c`, `0x0061d244`, and `0x0061fee4`; little-endian endpoint `0x004671ad` has no matches. Little-endian `0x004673f0` occurs at the fourteen known object-size vtable slots; endpoint `0x004673f6` has no matches.
- `make_signature_for_range 0x004671a0-0x004671ad`: unique signature `8B C1 8B 48 ? 03 48 ? 8B 40 ? FF E0`.
- `analyze_function` / `disasm 0x00464e40`: `ApplicationRequestExit` allocates `0x18` / 24 decimal bytes (Verified with `tools/int_convert.py`), initializes the object, stores vtable `0x00612e40` at `0x00464ec6`, stores target helper `0x00464e20` at `0x00464ecc`, stores zero adjustment at `0x00464ed3`, stores the `Application` object at `0x00464eda`, and passes the callback to `sub_559110`.
- `entity_query`: `0x00612e40` is named `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`; related RTTI names for the same `PlainMemberFunctionObject0<Application>` specialization exist at `0x0064222c`, `0x00642240`, `0x00642250`, `0x00642260`, and `0x006746e0`.

by-* docs, support docs, old reports, generated reports, and trackers checked:

- Target [UID:000324], direct owner [UID:0000AJ], [UID:00005L] `FunctionObject0`, [UID:00005K] `FunctionObject`, [UID:0000JO] `FunctionObjects`, [UID:0001WQ] `FunctionObjectTemplates`, [UID:0000YU] parent container, sibling [UID:00032C], [UID:0003OF] vtable data, [UID:000486] RTTI/COL pointer, [UID:0002H3] `ApplicationRequestExit`, and generated `auto-generated/NexusTK/util/FunctionObjects.cpp`.
- Report search terms used across active, executed, central, and archived report locations: `000324`, `004671a0`, `PlainMemberFunctionObject0ApplicationInvoke`, `ApplicationFunctionObject0Callbacks`, `PlainMemberFunctionObject0<Application>`, `PlainMemberFunctionObject0`, `FunctionObjects`, `FunctionObject0`, `00032C`, and `0000AJ`.
- Matching reports opened as lead/policy context: B001 `0000YU-ApplicationFunctionObject0Callbacks.md`, B001 `0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md`, B014 `0001N5-UserPaneDoubleParamCallback-source-quality.md`, B006 `0001CQ-FunctionObjectTStringDestructor-source-quality.md`, and B007 `0001CS-FunctionObjectTConstStringDestructors-empty-emitter-source-quality.md`.

Failed, unavailable, or intentionally skipped checks:

- No MCP failure occurred. No incident playbook was needed.
- No IDA mutation, rename, type, comment, save, or process-management call was performed.
- No validators were run because this is report-only and no by-* implementation edit was made.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | [UID:000324] is exactly `0x004671a0-0x004671ad`, size `0x0d` / 13 decimal, with no function at endpoint `0x004671ad`. | Confirmed | MCP `lookup_funcs`, `get_bytes`, `make_signature_for_range`; int conversion. | Target `IDA Evidence`, `Scope`, `Score Rationale` | incorporated | Applied in target `Scope` / `IDA Evidence`; validator `000000000665` ok. |
| C002 | The body is a five-instruction zero-argument member callback invoke wrapper using fields `+0x08` callback, `+0x0c` this adjustment, and `+0x10` target object. | Confirmed | MCP `disasm`, `decompile`, `analyze_function`. | Target `Behavior`, `Reconstruction Notes` | incorporated | Applied in target `Behavior`, `IDA Evidence`, and `Reconstruction Notes`; validator `000000000665` ok. |
| C003 | Reachability is vtable/data only: four data refs, zero code refs/callers, and no endpoint refs. | Confirmed | MCP `xrefs_to`, `xref_query`, `find_bytes`. | Target `IDA Evidence`, `Negative Evidence` | incorporated | Applied in target `IDA Evidence` and rejected-alternative notes; validator `000000000665` ok. |
| C004 | The Application-specific vtable at `0x00612e40` contains destructor/support/invoke/object-size slots and is referenced by `ApplicationRequestExit` at `0x00464ec6`. | Confirmed | MCP `get_int`, `get_bytes`, `xrefs_to 0x00612e40`, `entity_query`, `ApplicationRequestExit` disasm. | Target `IDA Evidence`; support class/vtable notes | incorporated | Applied in target, [UID:0000AJ], [UID:0000JO], and [UID:0001WQ]; validators `000000000665`-`000000000668` ok. |
| C005 | `ApplicationRequestExit` constructs the 24-byte callback object and binds helper `0x00464e20`, zero adjustment, and the Application object. | Strong | MCP `analyze_function` and `disasm 0x00464e40`; current [UID:0002H3] page. | Target `Construction-Site Evidence`; optional support mention in [UID:0000AJ] | incorporated | Applied in target `IDA Evidence`, class/file/template support notes; read-only [UID:0002H3] check showed no contradiction. |
| C006 | Direct owner [UID:0000AJ] and emitter route through [UID:0000AJ] to [UID:0000JO] remain correct. | Strong | Target metadata, class page, FunctionObjects docs, live vtable/type evidence, B001 split report. | Target metadata/rationale; class support doc | incorporated | Target metadata preserved `CANONICAL_OWNER:0000AJ`, `EMITTER_UIDS:0000AJ`; support docs preserve FunctionObjects route; validators ok. |
| C007 | Formal C++ should be comment-only generated-binary proof, not handwritten body and not blank. | Strong | Current by-structure gate, generated empty marker, accepted [UID:0002N2]/[UID:0001N5] invoke-wrapper precedents, live target proof. | Target `RECONSTRUCTION_CPP CODE`; target reconstruction notes; FunctionObjects/template policy notes | incorporated | Exact three-line marker applied to target; generated inspection shows UID000324 marker lines 37-40 and no UID000324 empty marker. |
| C008 | Raise target score to `87/90`; do not exceed final-audit range because original shared template/header spelling remains inferred. | Strong | Current MCP closes target-local blank-emitter/source-quality blocker; support docs still retain broader FunctionObjects header uncertainty. | Target metadata and score rationale | incorporated | Target metadata now `COMPLETION:87`, `CONFIDENCE:90`; validator `000000000665` recorded completion/confidence updates. |
| C009 | Parent container [UID:0000YU] remains non-emitting mixed inventory; no split/merge/range change is needed. | Strong | Current parent page and B001 executed split report; live exact target boundary/padding. | Target cross-reference and split/range notes | already-present | Preserved as cross-reference only; no split/merge/new-child edit made. |
| C010 | Sibling [UID:00032C] remains a separate object-size virtual and is not incorporated into this target's formal C++. | Strong | MCP `lookup_funcs`, `xrefs_to`, `get_bytes`; sibling page. | Target `Function / Child Inventory`; no C++ for sibling here | incorporated | Target cross-references and evidence mention sibling slot/size; generated output keeps UID00032C as its own adjacent marker. |

## Positive Evidence Summary

- Live IDA MCP proves the exact target range, body, endpoint, padding, unique signature, and vtable-only reachability.
- The body matches the documented `PlainMemberFunctionObject0<Application>` callback layout and sibling object-size virtual.
- `ApplicationRequestExit` proves the concrete construction site and binding route for this specific vtable.
- Current support docs already route the source family through `FunctionObjects`; accepted invoke-wrapper reports establish comment-only no-code marker handling for compiler-emitted invoke wrappers.

## IDA MCP Facts

- Function/range facts: `sub_4671A0`, `.text`, size `0x0d` / 13 decimal (Verified with `tools/int_convert.py`), half-open range `0x004671a0-0x004671ad`, five instructions, one basic block.
- Data/table/padding facts: `0x004671ad-0x004671b0` is `CC CC CC`; `0x00612e3c` points to RTTI/COL `0x0064222c`; vtable dwords at `0x00612e40-0x00612e50` are `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, and `0x004673f0`.
- Xref facts: target has four data refs at `0x00612e4c`, `0x0061d00c`, `0x0061d244`, and `0x0061fee4`; zero code xrefs; no endpoint refs.
- Vtable/global/type facts: IDA name for `0x00612e40` is the decorated `PlainMemberFunctionObject0<Application>` vtable; related RTTI/type names exist for the same specialization.
- Negative IDA facts: no code callers, no endpoint pointer bytes, no direct call path, and no function at `0x004671ad`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004671a0-0x004671ad` | [UID:000324] target | `PlainMemberFunctionObject0<Application>::Invoke` generated invoke wrapper | TRUE | [UID:0000AJ] | current `85/88`, recommend `87/90` | add comment-only proof marker |
| `0x004671ad-0x004671b0` | no page | alignment padding | FALSE/ignored | n/a | n/a | confirmed `CC CC CC` |
| `0x004673f0-0x004673f6` | [UID:00032C] | object-size virtual returning `0x18` / 24 decimal | TRUE | [UID:0000AJ] | current `85/88` | sibling; separate report target |
| `0x00612e3c-0x00612e40` | [UID:000486] | RTTI/COL pointer | TRUE | [UID:0000JO] | `86/91` | current support data |
| `0x00612e40-0x00612e54` | [UID:0003OF] | `PlainMemberFunctionObject0<Application>` vtable data | TRUE | [UID:0000JO] | `88/92` | current support data |
| `0x00464e40-0x00464f34` | [UID:0002H3] | `Application::RequestExit` construction site | TRUE | [UID:00000D] | `87/90` | construction/binding source context |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00612e4c -> 0x004671a0` | data xref from Application callback vtable invoke slot | Concrete `ApplicationRequestExit` callback table reaches target |
| `0x0061d00c -> 0x004671a0` | data xref | Another `PlainMemberFunctionObject0<Application>`-style vtable user |
| `0x0061d244 -> 0x004671a0` | data xref | Another vtable slot using the same invoke wrapper |
| `0x0061fee4 -> 0x004671a0` | data xref | Another vtable slot using the same invoke wrapper |
| `0x00464ec6 -> 0x00612e40` | data xref inside `ApplicationRequestExit` | Construction site stores this concrete vtable |
| `0x00464ecc -> 0x00464e20` | construction-site store | Binds private Application shutdown helper as target member pointer |
| `0x00464ed3` | construction-site store `0` at `+0x0c` | Zero `this` adjustment |
| `0x00464eda` | construction-site store `this` at `+0x10` | Captured Application object |

## Documentation Evidence And IDA Status

- [UID:000324] already records the correct exact child, class owner, FunctionObjects source family, and vtable-only reachability. It lacks current-session evidence and an explicit current-policy C++ disposition.
- [UID:0000AJ] correctly owns the exact invoke and object-size children but still says C++ remains blank below the old `95/95` gate. This should be replaced by current comment-only/no-handwritten-body policy for [UID:000324] after supervisor acceptance.
- [UID:0000JO] and [UID:0001WQ] already contain accepted policy for [UID:0002N2] and [UID:0001N5] invoke wrappers using comment-only no-code proof markers. Add [UID:000324] to that policy family.
- [UID:0002H3] already documents the deferred callback path, helper `0x00464e20`, vtable `0x00612e40`, and 24-byte allocation. It appears already sufficient; no support edit is required unless the supervisor wants a short B002 backlink.
- Generated `FunctionObjects.cpp` header is current as of validator command id `000000000645`, refreshed `2026-06-29T11:05:37-04:00`; it shows [UID:000324] as an unresolved Empty Emitter Marker.

## Ranked Ownership Analysis

### 1. [UID:0000AJ] PlainMemberFunctionObject0<Application>

- Evidence for: exact method belongs to the concrete `PlainMemberFunctionObject0<Application>` vtable; direct class page clears `85/85`; target body operates only on the callback-wrapper layout; sibling object-size virtual shares this owner.
- Evidence against: exact original source template spelling is inferred rather than source-symbol proven, but IDA decorated names preserve the template family and `Application` parameterization.
- Decision: keep as canonical owner and direct emitter.

### 2. [UID:0000JO] FunctionObjects

- Evidence for: shared callback-template source family, generated output root, project docs route reusable callback declarations here.
- Evidence against: by-structure requires the narrow class owner for a concrete class method when supported; file-level owner is the source family and route, not direct semantic owner.
- Decision: support/emitter-root source family only; do not change target canonical owner to the file.

### 3. [UID:00000D]/[UID:0000HG] Application

- Evidence for: `ApplicationRequestExit` constructs the concrete callback and binds private helper `0x00464e20`.
- Evidence against: Application owns construction and target helper behavior only. The wrapper method reads generic callback object fields and has vtable-only reachability from callback tables.
- Decision: reject as canonical owner/emitter for [UID:000324]; cite as construction-site support.

### 4. Parent container [UID:0000YU]

- Evidence for: physical range contains the target.
- Evidence against: accepted split proves the parent is a mixed non-emitting inventory with multiple unrelated source families.
- Decision: keep as parent/container context only.

### 5. No-owner / non-emitting

- Evidence for: no ordinary code callers.
- Evidence against: vtable/data refs, concrete construction-site route, direct class owner, and emitter chain are proven; no-caller state is expected for virtual callback glue.
- Decision: reject.

## Source Placement

Recommended source placement is the existing FunctionObjects source family:

- direct class/target documentation: [UID:0000AJ] and [UID:000324];
- generated output route: [UID:0000JO] `NexusTK/util/FunctionObjects`;
- concrete construction and binding source: [UID:0002H3] `ApplicationRequestExit`.

The human source should ultimately be a shared template declaration for `PlainMemberFunctionObject0` plus Application-side construction code. The exact by-memory target should not become a standalone handwritten function.

## Range / Split / Padding / Reclassification Analysis

No split, merge, rename, or reclassification is recommended.

The target function is exactly `0x004671a0-0x004671ad`; `0x004671ad-0x004671b0` is three bytes of `0xcc` alignment padding before successor [UID:000325] `StringBaseAppendWideLiteral`. The sibling object-size virtual at `0x004673f0-0x004673f6` remains separate and should not be represented by this target's formal C++ block.

## Negative Evidence Summary

- No code xrefs or ordinary callers target `0x004671a0`.
- No xrefs or raw pointer bytes target endpoint `0x004671ad`.
- No source evidence supports assigning the wrapper to Application as a method body.
- No evidence supports treating the entire [UID:0000YU] container as FunctionObjects source.
- No current policy supports leaving [UID:000324] as a nonblank emitter with blank formal C++ now that the target-local no-code proof is available.

## First-Draft C++ Recommendation

- Eligible for draft C++: eligible for a formal `RECONSTRUCTION_CPP CODE` entry by metadata gate, but not eligible for a handwritten function body.
- Recommended formal content: exact comment-only no-code marker:

```cpp
// Compiler-emitted invoke wrapper for PlainMemberFunctionObject0<Application>;
// generated from the shared FunctionObjects template declaration and the
// Application::RequestExit binding in [UID:0002H3].
```

- Reason it preserves exact behavior: the compiler should regenerate the actual tail-jump wrapper from the shared template declaration and concrete Application binding. The marker documents that this exact binary range is generated glue, avoiding a fake source body.
- Reason it matches likely original source shape: Visual C++ callback-template code would be header/template declaration plus construction site, not a manually written `sub_4671A0`-style function in `FunctionObjects.cpp`.
- Inferred source-facing names: `PlainMemberFunctionObject0<Application>`, `Application::RequestExit`, and `ApplicationSignalExitEvent` / `Application::SignalExitRequested` as the private target helper role from [UID:0002H3]; exact helper spelling remains an Application target-page issue.
- Third-party import directive: not applicable.
- Exact no-code proof: the range is compiler-emitted invoke glue reached only through callback vtable data. The source representation is the shared FunctionObjects template declaration and the Application construction site, so this exact page should emit only the comment marker above.

## Recommended Target Doc Changes

Target path: `by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md`.

Apply these changes after supervisor acceptance:

- Change `COMPLETION:85` to `COMPLETION:87`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000AJ`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000AJ`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank.
- Insert the exact three-line comment-only formal block listed above between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`.
- Refresh `Item Summary` to mention current MCP session `d4d50b81`, exact 13-byte invoke wrapper, vtable/data-only refs, ApplicationRequestExit construction binding, sibling object-size virtual, and comment-only generated-template proof.
- Add current IDA evidence: session/health, exact range, bytes, disassembly/decompile, four vtable data refs, no code refs, endpoint negative, vtable dwords, Application construction site, and unique signature.
- Replace stale blank-C++ rationale with current no-code marker policy. Preserve rejected alternatives: no handwritten body, no Application owner, no parent-container ownership, no no-owner/non-emitting disposition.

## Recommended Support Doc Changes

Support path: `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`.

- Replace stale "C++ remains blank because final template declaration spelling and construction-site coverage are below the `95/95` reconstruction-code gate" wording with current policy: [UID:000324] has current target-local proof and should carry a formal comment-only generated-binary marker; broader original template/header spelling remains a support-family score cap, not a blocker to resolving the empty emitter.
- Add a short B002 evidence note: MCP session `d4d50b81`, `sub_4671A0` size `0x0d`, four data refs/no code refs, vtable `0x00612e40`, and ApplicationRequestExit construction store at `0x00464ec6`.
- No class score change is required unless the supervisor wants support-score alignment after implementation.

Support path: `by-file/FunctionObjects.md`.

- Add [UID:000324] to the accepted invoke-wrapper policy next to [UID:0002N2] and [UID:0001N5]: proven invoke wrappers may emit comment-only generated-binary proof markers through the shared template route, not handwritten concrete bodies and not unexplained empty markers.
- Keep scalar deleting destructor policy separate: do not broaden this report to destructor glue.
- No file score change is required.

Support path: `by-type/by-template/FunctionObjectTemplates.md`.

- Add or refine the `PlainMemberFunctionObject0<Application>` note: target-level invoke wrappers such as [UID:000324] may use comment-only no-code proof when vtable/construction route is proven; reusable source remains in the shared template declaration and concrete binding source.
- No type-template score change is required.

Support path: `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`.

- No edit required by this report because the page already records the deferred callback path, vtable `0x00612e40`, 24-byte allocation, private helper `0x00464e20`, and callback type. Optional backlink only if supervisor wants support alignment.

Support path: `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`.

- No edit required; existing page already records slot `0x00612e4c -> 0x004671a0`, slot `0x00612e50 -> 0x004673f0`, and construction xref from `Application::RequestExit`.

## Score And Metadata Recommendation

- Current target score/metadata: `85/88`, owner `0000AJ`, reconstructable true, emitter `0000AJ`, blank formal C++.
- Recommended score/metadata: `87/90`, owner `0000AJ`, reconstructable true, emitter `0000AJ`, comment-only formal C++ marker.
- Score rationale: current live MCP closes the target-local stale-evidence and blank-emitter blockers. The body, boundary, vtable refs, no-code-ref state, endpoint negative, construction-site binding, vtable data, and sibling relationship are now current and implementation-ready.
- Reason not higher: exact original `FunctionObjects` header name, final template spelling, and broader callback-family declaration shape remain inferred at support-doc level. The target is compiler-generated invoke glue, so it should not receive final-audit source score based only on the wrapper body.
- Score-limiting blockers researched:
  - Empty-emitter blocker: resolved by comment-only marker plan.
  - Old `95/95` gate blocker: rejected as stale policy; current by-structure gate applied.
  - Owner/emitter route: resolved as [UID:0000AJ] owner/emitter with [UID:0000JO] root route.
  - No-caller liveness: resolved as vtable-only dispatch.
  - Source-body readiness: resolved to no handwritten body; comment-only marker is the accepted source-quality closure.

## Open Questions With Attempted Resolution

- Open question: should this exact target emit a real C++ `Invoke` body?
  - Evidence checked: live body/decompile, accepted [UID:0002N2] and [UID:0001N5] invoke-wrapper policy, FunctionObjects/template docs.
  - Resolution: no. Emit comment-only proof marker instead.
- Open question: should the emitter be cleared like [UID:0001CS]?
  - Evidence checked: B007 [UID:0001CS] report, B006 scalar destructor policy, invoke-wrapper precedents.
  - Resolution: no. [UID:0001CS] is scalar destructor metadata; [UID:000324] is a proven invoke wrapper with accepted comment-only marker precedent.
- Open question: does incomplete original template/header spelling block target completion?
  - Evidence checked: [UID:0000JO], [UID:0001WQ], [UID:0000AJ], live decorated names.
  - Resolution: no target-local blocker remains. It caps score below final-audit but does not block resolving this empty emitter.
- Remaining unresolved: exact original shared template/header spelling and exact source typedef facade for `PlainMemberFunctionObject0`. This is broader [UID:0000JO]/[UID:0001WQ] future work and does not change target owner, emitter, or comment-only C++ disposition.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not manually edit generated `auto-generated/-ag-*` reports or any manual `-coverage-report.md` file in this B-agent workflow. Generated `FunctionObjects.cpp`, generated coverage, and generated tracker rows should refresh through scoped validators after accepted source-doc implementation.

## Follow-Up Actions

- Supervisor: validate this report and checklist. If accepted, send B002 an implementation callback with the exact target/support files to edit.
- B002 callback if accepted: lease only the by-* docs being edited, apply the target/support updates above, update this checklist with proof, run scoped validators, verify generated `FunctionObjects.cpp` no longer shows [UID:000324] as an empty emitter, and release leases immediately.
- Future broader work: final shared `FunctionObjects` template/header declaration audit, coordinated with [UID:00032C] and other FunctionObjects empty-emitter targets.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `87/90`.
- Remaining uncertainty: original shared template/header spelling and broader callback-family declaration source shape. These are not target-local blockers for ownership, emitter route, or comment-only C++ marker.

## Validator Results

Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory\0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md --apply --queue-timeout 240 --wait-generated`
  - Result: exit `0`, `ok: 1`.
  - Command metadata: `command_id: 000000000665`, `command_timestamp: 2026-06-29T11:32:38-04:00`.
  - Generated refresh: `completed`; `generated_refresh_command_id: 000000000665`, `generated_refresh_timestamp: 2026-06-29T11:32:38-04:00`.
- `python .\tools\validator.py --mode file --file by-class\PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`.
  - Command metadata: `command_id: 000000000666`, `command_timestamp: 2026-06-29T11:32:55-04:00`.
- `python .\tools\validator.py --mode file --file by-file\FunctionObjects.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`.
  - Command metadata: `command_id: 000000000667`, `command_timestamp: 2026-06-29T11:33:00-04:00`.
  - Notes: existing unrelated missing-reference warnings remained for historical `000123`/`0003LP`/`000366`/`0003OQ` references.
- `python .\tools\validator.py --mode file --file by-type\by-template\FunctionObjectTemplates.md --apply --queue-timeout 240`
  - Result: exit `0`, `ok: 1`.
  - Command metadata: `command_id: 000000000668`, `command_timestamp: 2026-06-29T11:33:07-04:00`.
  - Notes: existing unrelated missing-reference warnings remained for historical `000123`/`0003LP`/`000366`/`000365`/`00036G` references.

Generated output inspection, read-only:

- Command: `Select-String -Path auto-generated\NexusTK\util\FunctionObjects.cpp -Pattern "000324|PlainMemberFunctionObject0<Application>|Compiler-emitted invoke wrapper|Empty Emitter Marker" -Context 2,4`
- Result: [UID:000324] appears at generated lines 37-40 with `Completion:87 | Confidence:90` and the accepted comment-only marker:
  - `// Compiler-emitted invoke wrapper for PlainMemberFunctionObject0<Application>;`
  - `// generated from the shared FunctionObjects template declaration and the`
  - `// Application::RequestExit binding in [UID:0002H3]...`
- [UID:000324] is no longer reported as an `Empty Emitter Marker`. Other unrelated FunctionObjects empty markers remain.
- Validator note: `validator.py` link-normalized the UID reference in the formal comment from raw `[UID:0002H3]` to `[UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md)` in the target and generated output.

## Changed Files

- Created earlier: `tools/leaser/Agents/Agent-B002/research/000324-PlainMemberFunctionObject0ApplicationInvoke-empty-emitter-source-quality.md`.
- Modified by implementation:
  - `by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md`
  - `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
  - `by-file/FunctionObjects.md`
  - `by-type/by-template/FunctionObjectTemplates.md`
  - this report file
- Read/check-only, no edit: `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`; `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`; `auto-generated/NexusTK/util/FunctionObjects.cpp`.
- Leases used: B002 acquired short leases for the four edited by-* docs before patching. Post-validator release attempt returned `Rejected[No active lease]` for the UID000324 target and `Rejected[Lease owned by B008]` for the three shared support docs. Final B002 cleanup command `python .\tools\leaser\leaser.py B002 unlease` returned `B002: No active leases`; final `tools/leaser/Agents/current_leases.md` showed no active leases.
- Generated/project-level/tool-state/IDA DB changes: no manual edits. Validator-generated refresh occurred under command `000000000665`; `FunctionObjects.cpp` was inspected read-only.
- Report execution: not run.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: supervisor accepted UID000324 report and assigned callback `B002-implement-000324-PlainMemberFunctionObject0ApplicationInvoke-20260629`.
- [x] Target/support docs to update: `by-memory/0x004671a0-0x004671ad.PlainMemberFunctionObject0ApplicationInvoke.md`; `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`; `by-file/FunctionObjects.md`; `by-type/by-template/FunctionObjectTemplates.md`; optional already-present check only for `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md` and `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`. Proof: four by-* docs modified; two read-only pages checked and found consistent.
- [x] Current target state and actual evidence checked recorded: preserve prior `85/88`, owner/emitter `0000AJ`, generated empty-emitter symptom, MCP session `d4d50b81`, exact body/range/xref/byte/vtable/construction facts, support docs, and matching executed-report precedents. Proof: target change note records `85/88 -> 87/90`; generated inspection confirms UID000324 no longer empty.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C001-C010 ledger rows above now record applied/already-present states and validator/generated proof.
- [x] Metadata/score changes to apply: target `COMPLETION:87`, `CONFIDENCE:90`; no support score changes unless supervisor explicitly accepts alignment. Proof: target header and validator `000000000665` completion/confidence updates.
- [x] Score-limiting blockers researched to resolution: old policy gate rejected as stale, empty-emitter state resolved by comment-only marker, no-caller liveness resolved as vtable-only dispatch, target-local C++ resolved as no handwritten body. Proof: target `Reconstruction Notes`, support policy notes, and generated inspection lines 37-40.
- [x] Owner/emitter/reconstructable changes to apply: keep target `CANONICAL_OWNER:0000AJ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AJ`, blank emitter position. Proof: target metadata preserved; validator `000000000665` ok.
- [x] Split/rename/new-child changes to apply: none. Proof: no new by-* child files created; parent [UID:0000YU] remains cross-reference only.
- [x] Source-placement/range/padding/reclassification changes to apply: document exact `0x004671a0-0x004671ad` range, `0x004671ad-0x004671b0` padding, no split/merge, and FunctionObjects template route with Application construction-site binding. Proof: target `Scope`, `IDA Evidence`, and `Reconstruction Notes`.
- [x] First-draft C++ or no-code proof to apply: insert exact three-line comment-only formal C++ marker; do not insert a handwritten invoke body. Proof: target formal block and generated `FunctionObjects.cpp` lines 37-40, with validator-normalized UID link on the third comment line.
- [x] Third-party import directive to apply or confirm not applicable: not applicable. Proof: report conclusion unchanged.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP health/session, lookup, body bytes, disassembly, decompile, xrefs, endpoint negatives, vtable dwords, ApplicationRequestExit construction stores, sibling object-size relationship, accepted invoke-wrapper policy, and rejected scalar-destructor/non-emitting alternative. Proof: target and support docs updated; validators `000000000665`-`000000000668` ok.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old `95/95` wording as stale, no code callers, no endpoint refs, rejected Application owner, rejected handwritten body, rejected blank nonblank-emitter state, rejected no-owner/non-emitting state. Proof: class support stale gate replaced; target rejected-alternative notes added.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: none used. Proof: no Wave2/Wave3 artifact references added.
- [x] Open questions to close or document as evidence-backed unresolved: close target-local blank-emitter/C++ blocker; leave broader original FunctionObjects header/template spelling as score cap only. Proof: score rationale and support docs state broader header spelling as remaining cap only.
- [x] Validators to run after accepted implementation: scoped validators listed in `Validator Results`, with `--wait-generated` for target validator. Proof: validator command IDs `000000000665`, `000000000666`, `000000000667`, and `000000000668` all exit `0`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh expected from validator; no manual coverage/tracker edit by B002. Proof: command `000000000665` generated refresh completed; generated `FunctionObjects.cpp` inspected read-only.
- [x] Implementation leases resolved. Proof: B002 lease release attempt after validators found no active B002 target lease and temporary B008 ownership on three shared support docs; final cleanup command returned `B002: No active leases`, and final `current_leases.md` showed no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000324-PlainMemberFunctionObject0ApplicationInvoke-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000324-PlainMemberFunctionObject0ApplicationInvoke-empty-emitter-source-quality.md","timestamp":"2026-06-29T11:40:54","uid":"000324"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
