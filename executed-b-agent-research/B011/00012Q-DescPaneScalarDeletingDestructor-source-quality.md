** TARGET-REPORT-UID:00012Q **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00012Q DescPaneScalarDeletingDestructor Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:00012Q] `0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor` as no-code compiler-generated MSVC scalar deleting destructor glue, not a source-bearing method body.
- Final disposition: `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++ for [UID:00012Q]. Keep `DescPane` as semantic context in prose and cross-references.
- Required action: move source-authored destructor emission to [UID:00012L] `0x0049d740-0x0049d769.DescPaneDestructor` with first-draft `DescPane::~DescPane()` C++ that clears `g_pDescPane`; update support text on [UID:00003Q], [UID:00012K], and [UID:0001XC] so scalar-deleting wrapper/thunk names are treated as compiler artifacts.
- Confidence: strong. Existing IDA-backed docs and exported function JSON agree on the wrapper shape, extra delete-flags parameter, vtable/thunk route, ordinary destructor sibling, singleton clear, base cleanup, and optional object-free behavior.

## Supporting Research

## Target

- Target UID: `00012Q`
- Target path: `source-3/project-documentation/by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00012Q-DescPaneScalarDeletingDestructor-source-quality.md`
- Source queue/report row: supervisor B-agent source-quality assignment for [UID:00012Q].
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00003Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003Q`, blank formal C++ with stale below-95 wording.
- Current generated state: `auto-generated/-ag-memory-coverage.md` reports [UID:00012Q] as `emits` through [UID:00003Q] to `auto-generated/NexusTK/ui/controls/DescPane.cpp`, but the formal C++ block is empty.

## Executive Recommendation

The target should not stay source-bearing. It is the MSVC scalar deleting destructor wrapper generated from a source-declared virtual destructor and the ordinary destructor body. The wrapper is still valuable documentation because it proves the primary vtable destructor slot, secondary/tertiary adjustor thunk route, singleton clear, base cleanup call, and object-free flag behavior, but it should not emit a handwritten C++ function.

The source-authored destructor is [UID:00012L] `0x0049d740-0x0049d769.DescPaneDestructor`. That page already has the exact ordinary destructor body: restore compiler vtables, clear [UID:0000QR] `g_pDescPane`, and tail into shared `Pane`/pane-family cleanup at `0x00544580`. Source C++ should express only the source-visible body:

```cpp
DescPane::~DescPane()
{
    g_pDescPane = NULL;
}
```

Do not hand-write vtable stores, `Pane::~Pane()`, scalar-delete flags, guard calls, or `operator delete` in either destructor page's source block. Those are compiler lowering from the class declaration, inheritance layout, base/member destructors, and delete expression handling.

## Supervisor Active Recheck

This was a report-only B011 pass. I did not edit target/support `by-*` docs, generated reports, generated source, IDA database state, or `by-memory/-coverage-report.md`.

No live IDA MCP tool was available in this Codex session. Evidence checked consisted of current IDA-backed project documentation plus local exported function JSON under `resources/exported_data/functions`. I do not claim a new live IDA mutation or fresh MCP query in this report.

The target does not require range split repair. The exact target range is already isolated after the two adjustor thunks and twelve bytes of `0xcc` padding, and it ends at the one-byte `0xcc` gap before `DialogPane`.

## Inference Research Guidance Check

I treated existing docs as leads and rechecked the key claims against independent local exports where possible:

- [UID:00012L] ordinary destructor proves a separate source-authored destructor body already exists at `0x0049d740`.
- [UID:00012Q] scalar deleting destructor duplicates the ordinary destructor behavior and adds deleting-destructor flag handling plus optional storage free.
- [UID:00012P] adjustor thunks are already non-reconstructable compiler glue and route only to [UID:00012Q].
- [UID:0001XC] and [UID:0002NA] prove primary vtable slot `0x006189dc -> 0x0049d840`, secondary `0x00618a28 -> 0x0049d81e`, and tertiary `0x00618a58 -> 0x0049d829`.
- [UID:0000QR]/[UID:0001PB] prove the singleton lifecycle: constructor publish, ordinary destructor clear, getter read, scalar wrapper clear.

Fact versus inference:

- Fact: range, vtable/thunk refs, delete-flag parameter, callee set, singleton clear, base cleanup, and optional `0x004f4ac0` free are documented and independently present in exported function JSON.
- Inference: original source had a normal `DescPane::~DescPane()` declaration/body and no user-authored `ScalarDeletingDestructor` method. This is the standard MSVC interpretation of the wrapper pattern and is reinforced by the separate ordinary destructor body.
- Rebuild policy inference: [UID:00012Q] should be no-code compiler glue, while [UID:00012L] should carry source C++.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus Compiler Glue

- Best direction: [UID:00012Q] is no-code compiler-generated scalar deleting destructor glue.
- Evidence checked: exported function JSON gives size 95, signature with an extra delete-flags parameter, xrefs from two thunk jumps and primary vtable data, callees `0x00544580`, `0x004f4ac0`, and guard-check helper. Current target docs record the same facts from live IDA MCP.
- Rejected alternative: keep [UID:00012Q] as a source-authored `DescPane::ScalarDeletingDestructor` or `DescPane::~DescPane(unsigned int flags)` body. Rejected because the flag parameter, optional object free, guard path, vtable-only route, and adjustor-thunk callers are ABI wrapper behavior rather than human project source.
- Final direction: make [UID:00012Q] `RECONSTRUCTABLE:FALSE`, blank owner/emitter/code, and document it as semantic support for [UID:00003Q] and [UID:00012L].

### Ordinary Destructor Placement

- Best source-facing owner: [UID:00012L] is `DescPane::~DescPane()`.
- Evidence checked: [UID:00012L] has exact range `0x0049d740-0x0049d769`, restores all three DescPane vtables, clears `g_pDescPane`, and tail-jumps to `0x00544580`. Exported `0x0049d740.json` decompiles the body as the same no-flag destructor and has no deleting flag parameter.
- Rejected alternatives: leave destructor source blank because no direct callers are modeled; assign destructor source to [UID:00012Q]; treat `0x0049d740` as a helper instead of destructor. Rejected because `0x0049d740` has ordinary destructor shape and the scalar wrapper duplicates it before optional delete.
- Recommended metadata: raise [UID:00012L] to `COMPLETION:86`, `CONFIDENCE:91`, keep owner/emitter [UID:00003Q], and populate first-draft C++.

### Singleton Clear / Global Behavior

- Best source-facing global name: `g_pDescPane`.
- Evidence checked: [UID:0000QR] and [UID:0001PB] document raw storage `0x0069adf8`, constructor store at `0x0049d731`, ordinary destructor clear at `0x0049d75a`, getter read at `0x0049d770`, scalar wrapper clear at `0x0049d860`, and no xref fanout outside the DescPane island.
- Source decision: ordinary destructor source should clear `g_pDescPane = NULL;` unconditionally. Do not use `dword_69ADF8` in emitted source. Do not add an `if (g_pDescPane == this)` guard because the observed source-level body is an unconditional clear.
- Wrapper interpretation: [UID:00012Q] repeats the singleton clear because the ordinary destructor body is inlined/duplicated inside the deleting wrapper; this does not make [UID:00012Q] a separate source method.

### Delete Wrapper / Base Destructor Behavior

- `0x00544580` is the shared pane-family base cleanup currently documented as `Pane` base cleanup on DescPane pages. Some Ghidra export aliases print a more derived control-pane name, but the DescPane constructor calls `Pane(1)` and the active docs consistently treat `0x00544580` as the base pane teardown route.
- `0x004f4ac0` is the ordinary object-free helper used only when the scalar-delete flag bit 1 is set and vector-delete flag bit 4 is clear.
- The guard-check path on bit 4 is compiler delete-wrapper behavior, not source-authored DescPane logic.
- Source C++ should rely on normal C++ destructor and delete lowering to regenerate this behavior.

### Stale Below-95 No-Code Wording

- [UID:00012Q] currently says final C++ is blank because the page is below the old 95/95 threshold. That is stale under current `by-structure.md`, which uses the combined-score/emitter gate.
- The correct reason for blank C++ is not score. It is no-code proof: the page documents compiler ABI glue generated from `virtual ~DescPane()` / `DescPane::~DescPane()`.
- [UID:00012L] also has stale below-95 wording; unlike [UID:00012Q], it is source-authored and should receive first-draft C++ after score/support text is updated.

### Compiler-Generated Names

- Reject source use of `sub_49D840`, `virt_deldtor_0x49d840`, `DescPaneScalarDeletingDestructor`, and `DescPane::~DescPane(DescPane*, uint)` as user-authored C++ names/signatures.
- Keep `DescPaneScalarDeletingDestructor` as a documentation filename/role label only.
- Source-facing names should be `DescPane::~DescPane()` for [UID:00012L] and a virtual destructor declaration in the class/header shape. The exact wrapper name is compiler/ABI output.

### Open Questions

- No target-level open question remains that should block the [UID:00012Q] no-code classification.
- Remaining class-wide issues from [UID:00003Q] and [UID:00012K] still matter for full class finalization: provider-interface original spelling, source-facing setter helper name, inherited/default slot names, and `Pane(1)` mode constant. These do not affect [UID:00012Q]'s compiler-glue status or [UID:00012L]'s minimal destructor source body.
- A future class/header pass should decide whether to declare `virtual ~DescPane();` explicitly in the class block and how to order child method snippets under [UID:00003Q].

## Evidence Standards Used

- Current IDA-backed by-memory/by-class/by-file/by-global/by-type docs for ranges, behavior, xrefs, and source placement.
- Exported local function JSON:
  - `resources/exported_data/functions/0x0049d740.json`
  - `resources/exported_data/functions/0x0049d81e.json`
  - `resources/exported_data/functions/0x0049d829.json`
  - `resources/exported_data/functions/0x0049d840.json`
- Generated coverage state:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
- Negative evidence: no ordinary direct callers for the ordinary destructor/getter/scalar wrapper in current docs; wrapper route comes from vtable/thunk dispatch, not ordinary source calls.

The evidence is strong enough for [UID:00012Q] `86/92` as no-code compiler glue and [UID:00012L] `86/91` with first-draft C++. It is not a `95+` final-audit case because this pass did not include a fresh live MCP/byte audit and class-wide provider/interface names remain inferred.

## IDA / Exported Function Facts

- `0x0049d740`: exported IDA data reports `sub_49D740`, size 41, no delete-flags parameter, decompiled as vtable restore, `dword_69ADF8 = 0`, and jump/call to `sub_544580`.
- `0x0049d81e`: exported data reports an 11-byte wrapper with data xref from `0x00618a28`, subtracting `0xa0` / 40 dwords from `this` and jumping to `0x0049d840`.
- `0x0049d829`: exported data reports an 11-byte wrapper with data xref from `0x00618a58`, subtracting `0xa4` / 41 dwords from `this` and jumping to `0x0049d840`.
- `0x0049d840`: exported data reports size 95, extra delete-flags parameter, xrefs from `0x0049d824`, `0x0049d82f`, and primary vtable cell `0x006189dc`, and callees `0x00544580`, `0x004f4ac0`, and guard-check helper `0x0041b6a0`.
- Current target docs record the end boundary bytes as `retn 4` ending at `0x0049d89e`, `0x0049d89f` as one `0xcc`, and `DialogPane` starting at `0x0049d8a0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049d6f0-0x0049d89f` | [UID:00012K] `DescPane` | Class-method aggregate/index | `TRUE` | [UID:00003Q] | no score change | Keep as aggregate; update wording to say scalar wrapper is no-code support. |
| `0x0049d740-0x0049d769` | [UID:00012L] `DescPaneDestructor` | Ordinary source destructor | `TRUE` | [UID:00003Q] | `86/91` | Populate first-draft `DescPane::~DescPane()` C++. |
| `0x0049d81e-0x0049d834` | [UID:00012P] `DescPaneDestructorAdjustorThunks` | Secondary/tertiary adjustor thunks | `FALSE` | `NONE` | keep `88/92` | Already correct no-code compiler glue. |
| `0x0049d840-0x0049d89f` | [UID:00012Q] `DescPaneScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper | `FALSE` | `NONE` | `86/92` | Reclassify to no-code compiler glue. |
| `0x006189dc-0x00618a60` | [UID:0002NA] `DescPaneVtableData` | Vtable data | `TRUE` | [UID:0001XC] | no score change | Keep source-declared/generated-binary data; class declaration regenerates dwords. |
| `0x0069adf8-0x0069adfc` | [UID:0001PB] `g_pDescPane` | Singleton storage | `TRUE` | [UID:0000QR] | no score change | Supports constructor/destructor/getter lifecycle. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006189dc` | primary vtable data ref to `0x0049d840` | Primary virtual destructor dispatch route uses scalar deleting wrapper. |
| `0x00618a28` | vtable data ref to `0x0049d81e` | Secondary view destructor dispatch uses adjustor thunk. |
| `0x00618a58` | vtable data ref to `0x0049d829` | Tertiary view destructor dispatch uses adjustor thunk. |
| `0x0049d824` | thunk jump to `0x0049d840` | Adjusts `this - 0xa0` before wrapper. |
| `0x0049d82f` | thunk jump to `0x0049d840` | Adjusts `this - 0xa4` before wrapper. |
| `0x0049d75a` | ordinary destructor clear of `0x0069adf8` | Source-authored `g_pDescPane = NULL;`. |
| `0x0049d860` | scalar wrapper clear of `0x0069adf8` | Duplicated/inlined ordinary destructor behavior inside wrapper. |
| `0x00544580` | callee from both destructor paths | Shared pane-family base cleanup. |
| `0x004f4ac0` | callee from scalar wrapper only | Optional object storage free on scalar-delete path. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00012L] documents the separate ordinary no-flag destructor body.
- [UID:00012Q] documents delete-flag tests and optional free helper.
- [UID:00012P] is already non-reconstructable compiler adjustor glue.
- [UID:00003Q] records source-policy decisions that vtable writes are compiler output.
- [UID:0001XC] records primary/secondary/tertiary vtable slots and already treats adjustor thunks as non-emitting compiler glue.
- [UID:0000QR] / [UID:0001PB] document `g_pDescPane` as the source-facing singleton name.

Existing docs that are stale or incomplete:

- [UID:00012Q] is still `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00003Q], and says C++ is blank because of the old 95/95 threshold.
- [UID:00012L] also has stale below-95 wording despite being eligible for first-draft source under the active combined-score/emitter gate.
- [UID:00012K] aggregate row says scalar-destructor split but does not say [UID:00012Q] is no-code compiler glue.
- `auto-generated/-ag-memory-coverage.md` currently reports [UID:00012Q] as `emits`; this should change to `not_reconstructable` after metadata validation/autogen refresh.

## Ranked Ownership Analysis

### 1. No standalone source owner for [UID:00012Q]

- Evidence for: delete flags, optional storage free, guard path, primary vtable slot, thunk jumps, no ordinary callers, and duplicate ordinary destructor body all identify compiler-generated ABI wrapper.
- Evidence against: wrapper is semantically tied to `DescPane` and manipulates `g_pDescPane`, so it still needs context docs and cross-links.
- Decision: accepted for metadata. Use `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++; retain semantic class references in body text.

### 2. [UID:00003Q] `DescPane` as semantic context

- Evidence for: all vtable/global refs are inside the DescPane island, and the wrapper is generated for `DescPane` virtual destruction.
- Evidence against: not a source owner for this exact wrapper body under strict no-code classification.
- Decision: use as context and support owner for [UID:00012L], not as [UID:00012Q] canonical owner/emitter.

### 3. [UID:00012L] ordinary destructor as source-bearing direct child

- Evidence for: exact no-flag body, no delete wrapper logic, source-visible singleton clear, base destructor tail, same vtable restores, valid class/file route.
- Evidence against: no modeled direct callers in current IDB.
- Decision: accepted as source destructor; direct callers are not required for a compiler-emitted ordinary destructor body when the virtual route uses the scalar deleting wrapper.

### 4. [UID:0000IS] `DescPane.cpp` source file

- Evidence for: file/class docs and proposed source tree route to `NexusTK/ui/controls/DescPane.cpp`; singleton and methods are class-local.
- Evidence against: file page is not the narrowest direct owner for method pages when the class page exists.
- Decision: keep as source root through [UID:00003Q].

### 5. `Pane` / base cleanup owner

- Evidence for: both destructor paths call `0x00544580`.
- Evidence against: base cleanup is a callee/dependency, not owner of the DescPane destructor/wrapper; vtables and singleton are DescPane-specific.
- Decision: rejected as direct owner.

## Negative Evidence Summary

- No ordinary caller to `0x0049d740`: does not block source destructor identity; the scalar deleting destructor and vtable route are normal compiler emission paths.
- No ordinary caller to `0x0049d840`: supports vtable/thunk-only compiler wrapper treatment.
- Ghidra/OOAnalyzer names like `virt_deldtor_0x49d840` and Ghidra `~DescPane(DescPane*, uint)` are decompiler/compiler-ABI labels, not source signatures.
- Keeping [UID:00012Q] as emitted but blank creates generated-output pollution: coverage reports an emitting page with no source body even though the correct source representation belongs to [UID:00012L].

## First-Draft C++ Recommendation

### [UID:00012Q] Target

Do not populate [UID:00012Q]'s formal `RECONSTRUCTION_CPP CODE` block.

Exact no-code proof:

- The function takes a delete-flags parameter and returns through `retn 4`.
- The only code references are secondary/tertiary adjustor thunk jumps; the other route is the primary vtable cell.
- It duplicates [UID:00012L]'s destructor behavior and adds MSVC scalar-delete flag tests plus optional object free.
- The wrapper's source representation is `virtual ~DescPane();` plus the ordinary destructor source body, not a handwritten C++ method.

### [UID:00012L] Ordinary Destructor

Populate [UID:00012L]'s formal C++ block after applying the score/support updates:

```cpp
DescPane::~DescPane()
{
    g_pDescPane = NULL;
}
```

Rationale:

- `g_pDescPane = NULL;` is the only source-visible DescPane-local operation.
- Vtable stores, base `Pane` teardown, and the scalar deleting wrapper are compiler-generated around the destructor body.
- `NULL` matches the existing constructor page's mid-2000s source style.

## Recommended Exact Documentation Changes

### [UID:00012Q] Header

Replace:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the formal C++ block empty.

### [UID:00012Q] Status Replacement

Replace the current Status section with:

```md
## Status

- Disposition: no-code compiler-generated MSVC scalar deleting destructor glue for `DescPane`.
- Entity kind: scalar deleting destructor wrapper / primary vtable destructor entry.
- Semantic class context: [UID:00003Q][DescPane](by-class/DescPane.md)
- Source representation: [UID:00012L][DescPane::~DescPane](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) plus the `DescPane` virtual destructor declaration; do not emit this wrapper as handwritten source.
- Confidence: very strong for exact range, delete-wrapper behavior, vtable/thunk reachability, singleton clear duplication, base cleanup, optional storage free, and non-emitting compiler-glue classification.
- Formal C++ is intentionally blank because this exact body is ABI wrapper output generated from the source destructor, not because of the stale 95/95 code threshold.
```

### [UID:00012Q] Behavior Replacement

Replace Behavior with:

```md
The wrapper is the primary `DescPane` vtable deleting-destructor entry. It restores the compiler-emitted `DescPane` vtable views, clears [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md), runs the shared pane-family base cleanup at `0x00544580`, and conditionally frees object storage through `0x004f4ac0` when the MSVC scalar-delete flag bit is set and the vector-delete flag bit is clear.

This duplicates the source-visible cleanup in [UID:00012L][DescPane::~DescPane](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) and adds compiler delete-wrapper behavior. The source project should express the ordinary destructor and class declaration, not a `DescPaneScalarDeletingDestructor` function.
```

### [UID:00012Q] Add No-Code Proof Section

Insert after Evidence:

```md
## No-Code Compiler Glue Proof

- The wrapper has an extra delete-flags parameter and returns with `retn 4`, matching MSVC scalar deleting destructor ABI shape.
- `xrefs_to 0x0049d840` are the two adjusted-this thunk jumps at `0x0049d824` and `0x0049d82f` plus the primary vtable data cell at `0x006189dc`; there are no ordinary source-call xrefs.
- [UID:00012P][DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) already documents the secondary and tertiary thunk routes as non-emitting compiler glue.
- [UID:00012L][DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) is the ordinary source destructor body. This wrapper repeats that cleanup and then handles optional object deletion.
- Formal C++ must stay blank here; source emission belongs to the ordinary destructor and class declaration.
```

### [UID:00012Q] Ownership Decision Section

Add or replace:

```md
## Ownership / Rebuild Decision

`CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++ are intentional for this exact range. [UID:00003Q][DescPane](by-class/DescPane.md) remains the semantic class context, but the wrapper body is compiler-generated ABI support. Source reconstruction should emit [UID:00012L][DescPane::~DescPane](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) and a normal virtual destructor declaration, allowing the compiler to regenerate the deleting destructor and adjusted-this thunks.
```

### [UID:00012L] Ordinary Destructor Updates

Recommended header:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace stale final-C++ sentence with:

```md
- Formal first-draft C++ is ready for the source-authored ordinary destructor. The source-visible cleanup is the `g_pDescPane` clear; vtable stores, base `Pane` teardown, and scalar deleting destructor support are compiler lowering.
```

Populate formal C++ with:

```cpp
DescPane::~DescPane()
{
    g_pDescPane = NULL;
}
```

Add score rationale:

```md
## Score Rationale

- `COMPLETION:86`: exact ordinary destructor bounds, three vtable restores, `g_pDescPane` clear, base cleanup tail, singleton lifecycle refs, scalar-wrapper contrast, no-direct-caller caveat, and first-draft source C++ are documented.
- `CONFIDENCE:91`: IDA-backed docs and exported function data agree on the no-flag destructor shape and its relationship to the scalar deleting wrapper. Confidence stays below final-audit range because no fresh live MCP pass was available in the B011 report session and final class/header destructor declaration style remains a broader class task.
```

### [UID:00003Q] DescPane Support Update

Update the method table rows to distinguish source and compiler output:

```md
| non-deleting destructor | [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) | Source-authored `DescPane::~DescPane()` body: clears `g_pDescPane`; compiler lowering restores vtables and runs `Pane` base cleanup. |
| destructor adjustor thunks | [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) | Non-emitting compiler-generated secondary/tertiary adjusted-this thunks. |
| scalar deleting destructor | [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) | Non-emitting MSVC deleting-destructor wrapper generated from `DescPane::~DescPane()`; documents vtable/thunk route, singleton-clear duplication, base cleanup, and optional delete behavior. |
```

### [UID:00012K] Aggregate Update

In Reconstruction Notes, replace the scalar-destructor wording with:

```md
[UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) owns the source destructor body and should emit `DescPane::~DescPane() { g_pDescPane = NULL; }`. [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) and [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) are compiler-generated destructor dispatch/delete glue and must stay formal-C++ blank.
```

### [UID:0001XC] Vtable Support Update

In Slot Notes, update the primary slot text:

```md
| primary `+0x00` / `0x0049d840` | Non-emitting MSVC scalar deleting destructor wrapper generated from source `DescPane::~DescPane()`; do not hand-author as C++. |
```

## Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly as B011. Supervisor should replace the current [UID:00012L] and [UID:00012Q] rows around the DescPane neighborhood with the following exact rows after accepting/applying the by-* doc changes.

Replace current [UID:00012L] row with:

```text
    - [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) 0x0049d740-0x0049d769 | destructor body | DescPaneDestructor : reconstructable : 86% : very strong : Source-authored ordinary `DescPane::~DescPane()` body; B011 source-quality pass confirms exact no-flag destructor range, three compiler vtable restores, `g_pDescPane` clear at `0x0049d75a`, terminal pane-family base cleanup through `0x00544580`, no modeled direct callers, scalar deleting destructor contrast, boundary padding before the singleton getter, and first-draft formal C++ `g_pDescPane = NULL;`.
```

Replace current [UID:00012Q] row with:

```text
    - [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) 0x0049d840-0x0049d89f | compiler deleting destructor | DescPaneScalarDeletingDestructor : ignored : 86% : very strong : No-code MSVC scalar deleting destructor wrapper for `DescPane`; B011 source-quality pass confirms exact `0x5f` body, primary vtable slot `0x006189dc`, adjusted-this thunk jumps from `0x0049d824`/`0x0049d82f`, duplicate ordinary destructor cleanup with `g_pDescPane` clear at `0x0049d860`, shared pane-family base cleanup `0x00544580`, scalar-delete flag tests, optional object free through `0x004f4ac0`, guard-check path, single-byte padding before `DialogPane`, and blank formal C++ because source emission belongs to [UID:00012L] `DescPane::~DescPane()`.
```

After validator/autogen refresh, `auto-generated/-ag-memory-coverage.md` should no longer list [UID:00012Q] as `emits`; expected generated status is `not_reconstructable` with owner `NONE`, matching the existing [UID:00012P] adjustor thunk treatment.

## Validator Needs

No validators were run in this report-only pass.

Suggested validation after supervisor implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00012Q-DescPaneScalarDeletingDestructor-source-quality-removed.md](00012Q-DescPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor applies the pending manual coverage rows, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [00012Q-DescPaneScalarDeletingDestructor-source-quality-removed.md](00012Q-DescPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Final Recommendation

- [UID:00012Q]: `84/90 -> 86/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Treat as no-code compiler scalar deleting destructor glue.
- [UID:00012L]: `84/90 -> 86/91`, keep owner/emitter [UID:00003Q], populate first-draft `DescPane::~DescPane()` C++.
- [UID:00003Q]/[UID:00012K]/[UID:0001XC]: update support wording so the ordinary destructor is source-bearing and the scalar wrapper/adjustor thunks are compiler output.
- [UID:0000QR]/[UID:0001PB]: no ownership change; their singleton lifecycle evidence supports the destructor source.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for [UID:00012Q] `86/92` and [UID:00012L] `86/91`.
- Remaining uncertainty: no target-level blocker. Broader class/header uncertainties remain around provider interface naming, setter helper source name, inherited/default slot names, and the `Pane(1)` mode constant.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00012Q-DescPaneScalarDeletingDestructor-source-quality.md`
- Modified: none outside the B011 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00012Q-DescPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00012Q"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00012Q-DescPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00012Q-DescPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00012Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
