** TARGET-REPORT-UID:000125 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000125 RectangleControlPane Scalar Deleting Destructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: change [UID:000125] from a source-bearing emitter to no-code MSVC scalar deleting destructor glue.
- Final disposition: `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank formal C++.
- Required action: keep the file/page as exact binary evidence for the `RectangleControlPane` destructor family, but remove it from generated source routing. Put ordinary destructor semantics on the class/source declaration and, if the supervisor wants exact memory coverage, split/create an exact ordinary destructor child for `0x00499ce0-0x00499cff`.
- Confidence: high for compiler-glue classification from existing live-IDA-backed docs; lower than final-audit because B007 could not reach live IDA MCP in this session.

## Supporting Research

## Target

- Target UID: `000125`.
- Target path: `source-3/project-documentation/by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md`.
- Source queue/report row: supervisor B-agent source-quality/heuristic assignment for [UID:000125].
- Current supervisor classification: source-quality / heuristic research for source-bearing versus no-code compiler scalar deleting glue.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BT`.

## Executive Recommendation

[UID:000125] should not emit source C++ and should not remain `RECONSTRUCTABLE:TRUE`. The body is the MSVC deleting-destructor wrapper generated from the `RectangleControlPane` class destructor/inheritance layout:

- inbound route is vtable/adjustor only: primary vtable slot `0x00618434` and adjustor thunks `0x0049afc1` / `0x0049afcc`;
- the body restores the three `RectangleControlPane` vtable views;
- it calls ordinary base teardown at `0x00544580`, now documented as `Pane::~Pane()` by [UID:0001EA];
- it conditionally calls [UID:000197] `0x004f4ac0`, the MemoryMan-backed global `operator delete(void *)`;
- it has the normal scalar-delete flag test and guarded flag-4 no-free branch;
- it has no source-specific Rectangle cleanup, singleton clear, resource release, or field-specific behavior beyond the destructor mechanics.

The source-facing destructor placement is the ordinary/non-deleting helper already recorded inside [UID:00011Q] at `0x00499ce0-0x00499cff`, not this wrapper. That helper also appears to be a compiler-emitted/default destructor body with no class-specific handwritten cleanup. If represented in C++, the most faithful first draft is an empty C++03-era destructor body, not the scalar deleting wrapper:

```cpp
RectangleControlPane::~RectangleControlPane()
{
}
```

However, do not insert that code into [UID:000125]. [UID:000125] should contain exact no-code proof and keep formal C++ blank.

## Supervisor Active Recheck

- Supervisor instruction checked: B-agent report first; do not edit target/support by-* docs; do not edit `by-memory/-coverage-report.md`; include exact replacement row text in this report.
- Split repair: no by-* split was performed because this is explicitly an initial report-only pass. The report recommends an optional exact ordinary destructor child for `0x00499ce0-0x00499cff`.
- Source-bearing children in scope: the scalar deleting destructor page itself is not source-bearing. The ordinary destructor/helper range is the correct source-facing destructor placement if a child is created later.

## Inference Research Guidance Check

`by-structure.md` classifies adjustor thunks, vtable glue, EH/RTTI support, and compiler/linker artifacts as `compiler/linker-generated`; it also says active final C++ eligibility requires a reconstructable item, a valid emitter route, and average score over 85, but that gate is minimum eligibility, not a reason to emit compiler glue.

The stale page text saying final C++ is blank only because the page is below `95/95` is wrong under current rules and wrong for this body. The reason for blank C++ is not a score threshold. The reason is that [UID:000125] is a compiler-generated deleting destructor wrapper whose source equivalent is the class destructor declaration/body, not a handwritten wrapper function.

Existing documentation was treated as evidence only where it contains prior live IDA facts. B007 could not reach live IDA MCP at `127.0.0.1:13337` during this report; the report therefore relies on existing live-MCP-backed project docs plus generated coverage/output state.

## Heuristic / Inference Reanalysis And Validation

### Source-bearing versus compiler glue

- Best inference: [UID:000125] is no-code compiler scalar deleting destructor glue.
- Evidence checked: target page, [UID:000122] adjustor thunk page, [UID:0002OE] exact vtable-data page, [UID:0003IT] source-local vtable page, [UID:00011Y] destructor-band aggregate, [UID:0001EA] PaneCore, and [UID:000197] OperatorDeleteWrapper.
- Rejected alternative: keep [UID:000125] as a source-bearing `RectangleControlPane::~RectangleControlPane()` body. Rejected because the source-facing ordinary destructor helper is at `0x00499ce0-0x00499cff`, while [UID:000125] exists to implement deleting-destructor flags, adjusted `this` dispatch, and optional storage free.
- Rejected alternative: emit a hand-authored function named `RectangleControlPaneScalarDeletingDestructor`. Rejected because that name is compiler/descriptive documentation, not an original source method.

### Ordinary destructor placement

- Best inference: the ordinary/non-deleting destructor body is `0x00499ce0-0x00499cff` inside [UID:00011Q], with one byte of padding at `0x00499cff-0x00499d00`.
- Evidence checked: [UID:00011Q] records live IDA size `0x1f`, vtable restores, tail jump to `0x00544580`, no callers/xrefs, and padding; class/file pages list the helper.
- Recommended repair: fix support wording that says `0x00499ce0-0x00499cfe`; the half-open endpoint should be `0x00499cff`.
- Source C++ impact: if represented explicitly, use an empty/default ordinary destructor. Base `Pane::~Pane()` is implicit and should not be handwritten in the derived destructor body.

### Owner/emitter routing

- Best inference for [UID:000125]: no canonical owner for metadata, no emitters, no C++.
- Semantic context remains [UID:0000BT] `RectangleControlPane`, but the by-structure pattern for no-code compiler wrappers is `CANONICAL_OWNER:NONE`, matching examples such as [UID:00033N] `ArticleDialogScalarDeletingDestructor` and [UID:00037B] `ArgumentedMenuMenuItemListScalarDeletingDestructor`.
- Rejected alternative: route [UID:000125] through [UID:0000BT] with an empty emitter marker. Rejected because the current generated output already shows pollution: `auto-generated/NexusTK/ui/controls/RectangleControlPane.cpp` contains an empty emitter marker for UID `000125`.

### Delete-wrapper and base destructor behavior

- [UID:000197] documents `0x004f4ac0-0x004f4b00` as MemoryMan-backed global `operator delete(void *)`, with `GetMemoryMan` -> `FreeBufferMemory` callees and broad scalar-destructor fanout.
- [UID:0001EA] documents `0x00544580-0x00544687` as ordinary `Pane::~Pane()`, not `TextButtonExControlPane` owner material.
- Source impact: both calls are generated/implicit consequences for this wrapper. Do not write them in [UID:000125] final C++.

### Compiler-generated names

- Keep the filename stable for documentation identity unless the supervisor wants a no-code suffix rename. The current title is acceptable as descriptive binary evidence.
- In source-facing text, use `RectangleControlPane::~RectangleControlPane()` for the ordinary destructor and "MSVC scalar deleting destructor wrapper" for `0x0049b490`.
- Reject raw/source names such as `sub_49B490`, `RectangleControlPaneScalarDeletingDestructor()` as a C++ method, and stale base labels that imply `TextButtonExControlPane` owns the `0x00544580` cleanup.

### Open questions

- Live IDA MCP was unavailable, so no fresh B007 `lookup_funcs`, `decompile`, `xrefs_to`, `callees`, or bytes were collected.
- It is not provable from current docs whether original source explicitly declared an empty `~RectangleControlPane()` or relied on an implicit destructor from a virtual base. This does not change the no-code decision for [UID:000125].
- Constructor/paint/type-id pages in the same class still use stale "below 95/95" wording and are active-gate eligible for later first-draft C++ review. That is adjacent support cleanup, not a reason to keep [UID:000125] emitting.

## Evidence Standards Used

- Documentation evidence: target page and related by-memory/by-class/by-file/by-type docs with prior live IDA facts.
- Generated state: `auto-generated/-ag-memory-coverage.md`, generated `RectangleControlPane.cpp`, `project-level/-auto-completion-stats.md`, and `project-level/-unresolved.md`.
- Negative evidence: current generated output has only an empty emitter marker for UID `000125`; no source C++ exists for the wrapper.
- Tool limitation: IDA MCP endpoint was unreachable from this session (`Unable to connect to the remote server`), so all IDA facts below are inherited from existing docs, not newly observed by B007.

## IDA MCP Facts

These are not newly collected in this session. They are prior live-IDA-backed project facts checked in current docs:

- Function/range facts:
  - [UID:000125] target page records `0x0049b490-0x0049b4e5`, size `0x55`.
  - [UID:00011Q] records ordinary helper `0x00499ce0`, size `0x1f`, so half-open `0x00499ce0-0x00499cff`.
  - [UID:000122] records two `0xb` byte adjustor thunks at `0x0049afc1-0x0049afcc` and `0x0049afcc-0x0049afd7`.
- Data/table/padding facts:
  - [UID:0002OE] records primary vtable slot `0x00618434 -> 0x0049b490`, secondary `0x0061849c -> 0x0049afc1`, tertiary `0x006184cc -> 0x0049afcc`.
  - Target page records `0x0049b4e5-0x0049b4f0` as eleven `0xcc` bytes.
- Xref facts:
  - Target page records no ordinary direct callers.
  - [UID:000122] records code refs from thunks into `0x0049b490` plus the primary vtable ref.
- Vtable/global/type facts:
  - [UID:0003IT] and [UID:0002OE] record the three RectangleControlPane vtable views and constructor/helper/destructor store triads.
  - [UID:0001EA] resolves `0x00544580` as `Pane::~Pane()`.
  - [UID:000197] resolves `0x004f4ac0` as MemoryMan-backed global delete.
- Negative IDA facts:
  - Existing docs record no ordinary code callers to the scalar wrapper or ordinary helper. Liveness is through vtable/destructor dispatch.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00499c60-0x00499cd2` | [UID:00011P] | Constructor | TRUE | [UID:0000BT] | `84/90` | Source-bearing, stale no-code wording should be separately audited. |
| `0x00499ce0-0x00499cff` | currently inside [UID:00011Q] | Ordinary/non-deleting destructor body | source-facing destructor placement, exact child recommended | [UID:0000BT] if split | not separately scored | No direct xrefs; vtable/base cleanup only. |
| `0x00499d00-0x00499d37` | [UID:00011R] | Paint/invalidating virtual | TRUE | [UID:0000BT] | `84/90` | Source-bearing, stale no-code wording should be separately audited. |
| `0x0049afc1-0x0049afd7` | [UID:000122] | Secondary/tertiary destructor adjustor thunks | FALSE | NONE | `88/92` | Correctly ignored/non-emitting compiler glue. |
| `0x0049b490-0x0049b4e5` | [UID:000125] | Scalar deleting destructor wrapper | recommend FALSE | recommend NONE | recommend `88/91` | No-code compiler glue. |
| `0x0049b8f0-0x0049b8f5` | [UID:000128] | Fixed type-id virtual returning `21` | TRUE | [UID:0000BT] | `88/92` | Source-bearing; not part of this no-code decision. |
| `0x00618430-0x006184d4` | [UID:0002OE] | Vtable/RTTI data | TRUE, source-declared/generated-binary | [UID:0000BT] | `87/92` | Rebuild through class declaration, no handwritten vtable bytes. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00618434` | primary vtable slot to `0x0049b490` | Vtable-only deleting-destructor entry. |
| `0x0049afc1` | adjustor thunk, `this -= 0xa0`, jumps to `0x0049b490` | Compiler multiple-inheritance destructor dispatch. |
| `0x0049afcc` | adjustor thunk, `this -= 0xa4`, jumps to `0x0049b490` | Compiler multiple-inheritance destructor dispatch. |
| `0x00544580` | callee from ordinary/scalar destructor paths | Ordinary `Pane::~Pane()` base cleanup per [UID:0001EA]. |
| `0x004f4ac0` | callee on delete flag path | MemoryMan-backed global `operator delete(void *)` per [UID:000197]. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:000122] already classifies the Rectangle adjustor pair as `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, compiler-generated glue.
  - [UID:00011Y] says the broad destructor/thunk band is a non-reconstructable aggregate index and source-level reconstruction belongs to owning classes/declarations that cause the compiler to emit wrappers/thunks.
  - [UID:0002OE] and [UID:0003IT] say vtables should be rebuilt through the `RectangleControlPane` class declaration and inherited interfaces.
  - [UID:0001EA] says scalar deleting destructors should regenerate from `virtual ~Pane()` and delete flags, not be hand-authored.
  - [UID:000197] confirms the storage free callee is the project global delete wrapper, not class-specific Rectangle logic.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:000125] says final C++ is blank because the page is below the 95/95 threshold. That is stale and should be replaced with no-code compiler-wrapper proof.
  - [UID:0000BT] repeats the same stale below-95 wording for class final C++ and should be updated when accepted.
  - [UID:0000N1] and [UID:0000BT] list the ordinary helper as `0x00499ce0-0x00499cfe`; existing size/padding evidence indicates `0x00499ce0-0x00499cff`.
- Generated/coverage report state:
  - `auto-generated/NexusTK/ui/controls/RectangleControlPane.cpp` currently emits only empty markers, including UID `000125`.
  - `auto-generated/-ag-memory-coverage.md` currently marks UID `000125` as `emits`.
  - `by-memory/-coverage-report.md` currently marks UID `000125` as `reconstructable : 84% : strong`.

## Ranked Ownership Analysis

### 1. No-code compiler glue with semantic RectangleControlPane context

- Evidence for: vtable/adjustor-only inbound route, scalar-delete flags, optional global delete, base destructor call, no Rectangle-specific cleanup, local precedent from [UID:00033N], [UID:00037B], and [UID:0001B5].
- Evidence against: target is class-specific and writes Rectangle vtable bases, so it is useful documentation evidence for the class destructor family.
- Decision: accepted. Use `CANONICAL_OWNER:NONE` for metadata, keep semantic owner/context in body text.

### 2. Source-declared/generated-binary TRUE under RectangleControlPane

- Evidence for: some current scalar destructor pages still use `RECONSTRUCTABLE:TRUE` with class owner and blank C++ to represent declaration-side destructor relationships.
- Evidence against: [UID:000125] currently pollutes generated output as an empty emitter marker; the actual source-bearing destructor placement is the ordinary helper/class declaration; the wrapper body is pure ABI mechanics.
- Decision: rejected for this target.

### 3. Source-authored destructor body emitted as C++

- Evidence for: the wrapper performs class vtable restores and calls `Pane::~Pane()`.
- Evidence against: those are compiler destructor mechanics. The source-facing ordinary destructor is `0x00499ce0-0x00499cff`, and even that has no source-specific cleanup beyond default destruction.
- Decision: rejected.

## Proposed new file/grouping, if applicable

- Proposed exact child page: `source-3/project-documentation/by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md`.
- Proposed owner/name/path: [UID:0000BT] `RectangleControlPane`, emitted through [UID:0000N1] only if supervisor accepts an explicit empty destructor body as source output.
- Likely full contents: ordinary/non-deleting destructor body, vtable-store evidence, tail jump to `Pane::~Pane()`, no direct xrefs, scalar wrapper parity, padding before/after.
- Candidate related items that belong: [UID:00011Q] core page should keep the helper listed; [UID:000125] should cross-reference it as ordinary destructor placement.
- Candidate related items rejected: [UID:000122] adjustor thunks and [UID:000125] scalar deleting destructor should stay non-emitting compiler glue.
- Standalone, narrow, or broad source-file inference: narrow exact memory child only; no new source file needed.

## Negative Evidence Summary

- Consumer/vtable refs prove destructor-family liveness but do not prove handwritten source for [UID:000125].
- `0x004f4ac0` is global MemoryMan delete, not RectangleControlPane cleanup.
- `0x00544580` is ordinary Pane base destruction, not TextButtonEx ownership and not RectangleControlPane-specific code.
- Adjustor thunks at [UID:000122] are already ignored compiler glue; [UID:000125] is the same compiler-generated destructor family, just larger because it includes delete flag handling.
- The current empty generated emitter marker is evidence against keeping [UID:000125] routed as source output.

## Final Recommendation

### Exact target metadata recommendation

Replace the target header metadata with:

```text
*** UID:000125 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Exact target body changes recommended

- Rewrite Status to say:
  - entity kind: MSVC scalar deleting destructor wrapper;
  - rebuild handling: compiler/linker-generated, no formal C++;
  - semantic context: [UID:0000BT] `RectangleControlPane`;
  - ordinary destructor placement: `0x00499ce0-0x00499cff` in [UID:00011Q].
- Replace "Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold" with:
  - "Formal C++ is intentionally blank because this exact range is compiler-generated deleting-destructor glue. Source reconstruction should express `RectangleControlPane::~RectangleControlPane()` or the implicit/default class destructor and let the compiler regenerate the deleting wrapper and adjustor thunks."
- Add explicit no-code proof:
  - vtable/adjustor-only inbound route;
  - base `Pane::~Pane()` at `0x00544580`;
  - delete wrapper [UID:000197] at `0x004f4ac0`;
  - flag-4 guarded no-free branch;
  - no Rectangle-specific source cleanup.

### Support doc changes recommended

- [UID:0000BT] `by-class/RectangleControlPane.md`:
  - Change method table "non-deleting destructor helper" range to `0x00499ce0-0x00499cff`.
  - Change scalar deleting destructor role to "compiler-generated deleting-destructor wrapper; no handwritten source body".
  - Replace stale below-95 wording with the no-code compiler-wrapper rationale.
- [UID:0000N1] `by-file/RectangleControlPane.md`:
  - Change ordinary helper range to `0x00499ce0-0x00499cff`.
  - Say `RectangleControlPane.cpp` should express the class constructor/paint/type-id/ordinary destructor semantics, while adjustor thunks and scalar deleting destructor are compiler output.
- [UID:00011Q] `RectangleControlPaneCore`:
  - Change covered ordinary helper range to `0x00499ce0-0x00499cff`.
  - Replace final-C++ stale gate wording for the group/index with "grouping page remains blank because exact children own source emission; scalar wrapper remains no-code."
- Optional new page:
  - create `0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md` only if the supervisor wants exact ordinary destructor coverage outside [UID:00011Q].

### Exact items left no-owner/non-emitting and why

- [UID:000125]: leave `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank code because it is compiler ABI glue.
- [UID:000122]: already correct as no-owner/non-emitting adjustor thunk glue.

## First-Draft C++ / No-Code Proof

Formal C++ for [UID:000125] should remain empty. Do not insert `//` as an emitter marker, because this page should no longer be designated as an emitter.

No-code proof:

```text
0x0049b490 is reached by RectangleControlPane vtable slot 0x00618434 and adjustor thunks 0x0049afc1/0x0049afcc.
It restores RectangleControlPane vtable bases, calls ordinary Pane::~Pane() at 0x00544580, then implements MSVC scalar-delete flag behavior.
The optional storage free is the global MemoryMan-backed operator delete wrapper at 0x004f4ac0.
No source-specific RectangleControlPane field/resource cleanup exists in this range.
Therefore the source should provide RectangleControlPane destructor/class semantics and let the compiler regenerate this wrapper.
```

If the ordinary destructor helper is later split or represented in source, the recommended C++03-style first draft is:

```cpp
RectangleControlPane::~RectangleControlPane()
{
}
```

That draft belongs to an ordinary destructor/class page, not to [UID:000125].

## Follow-Up Actions

- Supervisor actions:
  - If accepting this report, send B007 an implementation checklist for [UID:000125] target metadata/body updates and support wording updates.
  - Decide whether to create the optional exact ordinary destructor child for `0x00499ce0-0x00499cff`.
  - Apply the pending `by-memory/-coverage-report.md` replacement row below because B-agents are banned from editing that file directly.
- A-agent actions:
  - Later audit eligible source-bearing RectangleControlPane constructor/paint/type-id pages for active-gate first-draft C++; their below-95 wording is stale.
- B007 future actions:
  - On implementation callback, lease/edit only the accepted target/support docs and run validator commands listed below.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/91`; do not raise to `95+` because B007 did not get live IDA MCP and the target page still needs written no-code proof before scoring changes are applied.
- Remaining uncertainty: explicit versus implicit original C++ destructor declaration, and whether the supervisor wants an exact ordinary destructor child page.

## Validator Results

- Commands run: none for by-* validation, because this was a report-only pass and no by-* docs were edited.
- IDA MCP status command attempted:
  - PowerShell JSON-RPC `tools/list` to `http://127.0.0.1:13337/mcp`.
  - Result: unable to connect to remote server.
- Validator needs for implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000125-RectangleControlPaneScalarDeletingDestructor-source-quality-removed.md](000125-RectangleControlPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional ordinary destructor child is created, validate that new page before validating support pages.

## Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B007. Supervisor-owned replacement:

Replace current row:

```text
    - [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) : reconstructable : 84% : strong : RectangleControlPane scalar deleting destructor; live IDA confirms `0x55` size, vtable/adjustor-thunk reachability, vtable restoration, shared teardown/free path, alternate deleting-flag branch, parent attachment, and trailing alignment.
```

With:

```text
    - [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) 0x0049b490-0x0049b4e5 | compiler-generated scalar deleting destructor wrapper | RectangleControlPaneScalarDeletingDestructor : not_reconstructable : 88% : very strong : B007 source-quality report resolves this as no-code MSVC deleting-destructor glue for [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md). Existing live-IDA-backed docs confirm primary vtable slot `0x00618434`, adjustor thunk refs `0x0049afc1`/`0x0049afcc`, no ordinary direct callers, vtable restores to `0x00618434`/`0x0061849c`/`0x006184cc`, ordinary [UID:0001EA][Pane](by-memory/0x00544460-0x00545086.PaneCore.md) teardown call `0x00544580`, optional MemoryMan-backed [UID:000197][operator delete](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), guarded flag-4 no-free branch, and `0x0049b4e5-0x0049b4f0` `0xcc` padding. Formal C++ must stay blank because the class declaration/ordinary `RectangleControlPane::~RectangleControlPane()` semantics, with ordinary helper placement at `0x00499ce0-0x00499cff`, should make the compiler regenerate this wrapper.
```

Generated `auto-generated/-ag-memory-coverage.md` should change through validator/autogen refresh, not by manual edit.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md`
- Modified: none outside B007 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"000125"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000125-RectangleControlPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/000125-RectangleControlPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000125"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
