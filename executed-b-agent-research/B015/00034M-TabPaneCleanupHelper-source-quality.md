** TARGET-REPORT-UID:00034M **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# [UID:00034M] TabPaneCleanupHelper Source-Quality Report

## Target

- Target UID: `00034M`
- Target path: `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md`
- Assignment: `B015-report-00034M-TabPaneCleanupHelper-20260702`
- Expected report path: `tools/leaser/Agents/Agent-B015/research/00034M-TabPaneCleanupHelper-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EB`
- Current target formal C++:

```cpp
void TabPane::CleanupForDestruction()
{
    g_pTabPane = NULL;
    Pane::CleanupForDestruction();
}
```

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 91
CANONICAL_OWNER: 0000EB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000EB
```

Recommended target formal `RECONSTRUCTION_CPP CODE` content:

```cpp
TabPane::~TabPane()
{
    g_pTabPane = NULL;
}
```

## Current Target State

The target currently has the correct class owner, file route, range, singleton-clear behavior, and first-draft C++ presence, but it still presents the exact body as a named `CleanupForDestruction` helper and hand-writes an explicit `Pane::CleanupForDestruction()` call. Fresh MCP evidence and current project destructor precedents support a stronger source-quality disposition: `0x004cf9d0-0x004cf9f9` is the complete-object / ordinary `TabPane::~TabPane()` body, while the tail transfer to `0x00544580` is implicit base destructor chaining to `Pane::~Pane()`, not a source statement.

The current generated output `auto-generated/NexusTK/ui/panels/TabPane.cpp` emits both UID `00034M` as `TabPane::CleanupForDestruction()` and UID `00034W` as `TabPane::~TabPane()`. That duplicates the singleton clear in source output. The sibling scalar deleting destructor page [UID:00034W] should keep class-owned reconstructable metadata but switch to scalar-wrapper / comment-only source content, matching the accepted `FpsPane` ordinary-destructor plus scalar-wrapper pattern.

## Evidence Checked

Instruction and workflow evidence:

- `tools/leaser/Agents/Agent-B015/goal.md`
- Project-level `ntk-b-agent-workflow` skill
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `by-structure.md` -> `IDA MCP Output Discipline`

Target and support docs:

- `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md`
- `by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md`
- `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`
- `by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md`
- `by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md`
- `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md`
- `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md`
- `by-memory/0x00544460-0x00545086.PaneCore.md`
- `by-class/TabPane.md`
- `by-file/TabPane.md`
- `by-global/g_pTabPane.md`
- `auto-generated/NexusTK/ui/panels/TabPane.cpp` as generated-output lead only
- `auto-generated/-ag-research-tracker.md`, row for `00034M`

Existing B-report searches and relevant matches:

- Search terms included `00034M`, `0x004cf9d0`, `TabPaneCleanupHelper`, `TabPane Cleanup Helper`, `sub_4CF9D0`, `CleanupForDestruction`, `TabPane.cpp`, `g_pTabPane`, `Pane::~Pane`, `sub_544580`, and `0x00544580`.
- Relevant executed match: `executed-b-agent-research/B001/000170-TabPaneAndIconsPaneDestructorTail.md`, which created [UID:00034M] as the `0x004cf9d0-0x004cf9f9` `TabPane` cleanup helper child, found no external xrefs to `0x004cf9d0`, and assigned it to [UID:0000EB] `TabPane`.
- Relevant executed match: `executed-b-agent-research/B005/00034Q-TabPaneRawRectangleBuilder-source-quality.md`, which used the target as support for the `TabPane.cpp` split and kept the `TabPane` owner/file route.
- Relevant precedent matches: `executed-b-agent-research/B004/00015E-FpsPaneDestructor-source-quality.md`, `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md`, and `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md`, which distinguish an ordinary destructor source body from a class-owned scalar deleting wrapper.
- No prior executed B report directly targets UID `00034M`.

IDA MCP evidence, session `supervisor_resume_20260629`, endpoint `http://127.0.0.1:13337/mcp`:

- `initialize` succeeded; server `ida-pro-mcp` returned protocol `2025-06-18`.
- `idb_list` reported active `NexusTK.exe.i64`, worker PID `14860`, not analyzing.
- `server_health` reported `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- `lookup_funcs` on `0x004cf980`, `0x004cf9d0`, `0x004cfa00`, and `0x004cfe00` returned `sub_4CF980` size `0x4a`, `sub_4CF9D0` size `0x29`, `nullsub_30` size `0x1`, and `sub_4CFE00` size `0x5f`.
- `analyze_function 0x004cf9d0` returned prototype `void __thiscall(_DWORD *this)`, size `41`, 2 basic blocks, no callers, no strings, no constants, no ordinary callees, and decompile showing three `TabPane` vtable writes, `unk_69ADFC = 0`, and `sub_544580(this)`.
- `disasm 0x004cf9d0` with `max_instructions=40` returned exactly 5 instructions and total instruction count 5:
  - `0x004cf9d0`: write `??_7TabPane@@6B@` to `[ecx]`
  - `0x004cf9d6`: write `??_7TabPane@@6B@_0` to `[ecx+0xa0]`
  - `0x004cf9e0`: write `??_7TabPane@@6B@_1` to `[ecx+0xa4]`
  - `0x004cf9ea`: clear `unk_69ADFC`
  - `0x004cf9f4`: tail jump to `sub_544580`
- `decompile 0x004cf9d0` returned refs to `0x0061b4d0`, `0x0061b51c`, `0x0061b54c`, `0x0069adfc`, and `0x00544580`.
- `xref_query` found no xrefs to `0x004cf9d0`.
- `xref_query` for `0x0069adfc` found 5 data refs: reads at `0x0049e5e6` and `0x00504936`, constructor write at `0x004cf9a4`, target clear at `0x004cf9ea`, and scalar-wrapper clear at `0x004cfe20`.
- `xref_query` for `0x0061b4d0`, `0x0061b51c`, and `0x0061b54c` found the same three `TabPane` lifecycle writers for each vtable: constructor `0x004cf980`, target `0x004cf9d0`, and scalar wrapper `0x004cfe00`.
- `get_bytes` around the target returned `0xcc` padding at `0x004cf9ca-0x004cf9d0`, the full target byte sequence ending in the tail jump plus one `0xcc`, and `0xcc` padding at `0x004cf9fa-0x004cfa00`.

## Positive Evidence Summary

- The exact range is a modeled function: `sub_4CF9D0`, size `0x29`, beginning at `0x004cf9d0` and ending before post-body alignment at `0x004cf9f9`.
- The body has the classic project pattern for a complete-object ordinary destructor: restore the most-derived class vtable views, perform source-authored teardown (`g_pTabPane = NULL`), then tail-chain to the inherited base destructor body.
- All class identity evidence points to `TabPane`: the three vtable constants are `TabPane` vtables, the singleton slot is `g_pTabPane`, and the same vtable/singleton pattern appears in the `TabPane` constructor and scalar deleting wrapper.
- The base cleanup target is resolved by `PaneCore`: `0x00544580-0x00544687` is ordinary `Pane::~Pane`, not a target-specific `TabPane` helper.
- No xrefs to `0x004cf9d0` are expected for this source shape. The vtable-visible delete route is the scalar deleting wrapper [UID:00034W], while the ordinary destructor body may be present for compiler/internal complete-object destruction.
- The accepted `FpsPane` precedent is materially parallel: an ordinary `0x29` destructor with three vtable restores, singleton clear, tail jump to `Pane::~Pane`, no direct xrefs, and a separate `0x5f` scalar deleting wrapper.

## Negative Evidence Summary

- No evidence supports moving this target to `Pane`: `Pane::~Pane` is only the inherited tail callee, while the target writes `TabPane` vtables and clears `g_pTabPane`.
- No evidence supports `IconsPane` ownership: the target does not touch `IconsPane` vtables, `g_pIconsPane`, or the interleaved `IconsPane` scalar deleting destructor range.
- No direct caller or xref evidence supports keeping `CleanupForDestruction` as a public/source-named method called by ordinary code. The body shape and no-xref status fit an ordinary destructor lowered by the compiler.
- The current explicit source call `Pane::CleanupForDestruction();` is not source-faithful. Current `PaneCore` and destructor precedents classify the `0x00544580` transfer as implicit base destructor chaining.
- The current generated output duplicates source destructor semantics by emitting both UID `00034M` and UID `00034W` as source methods that clear `g_pTabPane`. The scalar wrapper should not duplicate the ordinary destructor source body.
- The unresolved final `TabPane`/`IconsPane` physical source grouping does not block this target's owner or C++ shape. The body is class-specific and can be emitted through the existing `TabPane` route.

## Heuristic / Inference Reanalysis And Validation

### Function Identity And Source Shape

The best source-facing identity for `0x004cf9d0-0x004cf9f9` is `TabPane::~TabPane()`, not `TabPane::CleanupForDestruction()`. The binary body matches the same destructor-lowering pattern already accepted for [UID:00015E] `FpsPane::~FpsPane()`: most-derived vtable stores at `+0x00`, `+0xa0`, and `+0xa4`, one source-authored singleton clear, then an inherited `Pane::~Pane()` tail transfer.

The three vtable stores should remain documented as binary evidence, not handwritten C++. The base destructor tail jump should likewise remain documented as implicit C++ base destruction. The only source-authored statement proven inside this exact body is clearing the active singleton.

### Scalar Deleting Destructor Relationship

[UID:00034W] `0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md` is the vtable/delete wrapper. It has primary vtable and adjustor-thunk reachability, repeats the same vtable stores and singleton clear, calls `Pane::~Pane()`, and conditionally frees `this` through `0x004f4ac0` based on delete flags.

That wrapper should remain class-owned and reconstructable in the source-declared/generated-binary sense, but its formal C++ should become comment-only/no-code, as with [UID:00015L] `FpsPaneScalarDeletingDestructor`. Handwritten source belongs to the ordinary destructor target [UID:00034M].

Recommended [UID:00034W] formal C++ replacement:

```cpp
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().
```

### Ownership And Source-Placement Dependency

The ownership and source-placement decisions are normalized into the standalone `## Ranked Ownership Analysis` and `## Source Placement` sections below because this report recommends both [UID:00034M] ordinary-destructor source routing and [UID:00034W] scalar-wrapper C++ handling.

### Range And Boundary

No split or merge is recommended. `lookup_funcs` returns `sub_4CF9D0` size `0x29`, and `get_bytes` confirms `0xcc` padding before and after the target. The predecessor constructor ends at `0x004cf9ca`; the next modeled function starts at `0x004cfa00`.

### Naming And Style

Use `TabPane::~TabPane()` for source-facing C++. Keep `sub_4CF9D0` only as IDA evidence. Avoid `CleanupForDestruction` unless a later project-wide rule deliberately names ordinary destructor bodies as cleanup helpers. If such a rule appears, it still should not hand-write `Pane::~Pane()`/`Pane::CleanupForDestruction()` inside the derived body.

Use `g_pTabPane = NULL;` in this target to match the current `TabPane` page and generated output style. `g_pTabPane = 0;` would also be era-plausible, but there is no need to churn style here.

## Ranked Ownership Analysis

1. [UID:0000EB] `TabPane` / [UID:0000OF] `TabPane.cpp`: accepted.
   Evidence for: MCP disassembly at `0x004cf9d0` writes the three `TabPane` vtable views `0x0061b4d0`, `0x0061b51c`, and `0x0061b54c`; clears [UID:0000SE] `g_pTabPane` at `0x004cf9ea`; and then tail-jumps to `0x00544580`. MCP xrefs show the same three vtable views are written by the `TabPane` constructor at `0x004cf980`, this ordinary cleanup/destructor body, and the `TabPane` scalar deleting wrapper at `0x004cfe00`. `g_pTabPane` xrefs likewise tie the constructor write, this clear, and the scalar-wrapper clear to the same class lifecycle. Current `TabPane` class/file/global docs and the executed B001 split report all route this exact child through [UID:0000EB] to [UID:0000OF].
   Evidence against: no ordinary direct xrefs to `0x004cf9d0`; however, this is expected for a complete-object ordinary destructor body whose vtable-visible delete route is [UID:00034W], not evidence against `TabPane` ownership.
   Decision: keep owner/emitter [UID:0000EB] and source route through [UID:0000OF]. Model [UID:00034M] as the ordinary `TabPane::~TabPane()` source body.

2. [UID:0000A2] `Pane`: rejected as owner.
   Evidence for: the target tail-jumps to `0x00544580`, and `PaneCore` identifies `0x00544580-0x00544687` as ordinary `Pane::~Pane()`.
   Evidence against: the target's class-specific work happens before the tail jump: it writes `TabPane` vtables and clears `g_pTabPane`. `Pane` is the inherited base destructor callee, not the owner of this derived destructor body. Accepted destructor precedents treat the base transfer as implicit C++ base destruction, not source ownership.
   Decision: mention `Pane::~Pane()` as a dependency/base cleanup path only; do not move ownership, emitter, or source placement to `Pane`.

3. [UID:00006B] `IconsPane` / [UID:0000JZ] `IconsPane.cpp`: rejected.
   Evidence for: `IconsPane` code is physically adjacent in the old-HUD pane region, and the broad [UID:000170] aggregate historically mixed `TabPane` and `IconsPane` destructor-tail material.
   Evidence against: [UID:00034M] does not write `IconsPane` vtables, does not clear `g_pIconsPane`, and does not branch into `IconsPane` destructor ranges. The separate [UID:0002SX] `IconsPaneCleanupHelper` and [UID:00034V] `IconsPaneScalarDeletingDestructor` pages carry the `IconsPane` lifecycle paths.
   Decision: reject `IconsPane` as owner or source file for [UID:00034M] and [UID:00034W].

4. [UID:000170] mixed aggregate: rejected as owner/emitter.
   Evidence for: [UID:000170] is the physical split inventory that originally contained this target and the neighboring `TabPane`/`IconsPane` destructor-tail children.
   Evidence against: current [UID:000170] is intentionally `RECONSTRUCTABLE:FALSE`, parent blank, and non-emitting; exact child pages carry real class ownership. B001's executed split report explicitly assigned [UID:00034M] and [UID:00034W] to `TabPane` while leaving [UID:000170] as a mixed inventory.
   Decision: keep [UID:000170] as context/cross-reference only. Do not emit source or route ownership through the aggregate.

5. No-owner/non-emitting: rejected.
   Evidence for: no ordinary xrefs to `0x004cf9d0` could superficially resemble unreferenced helper material.
   Evidence against: the body is not padding, thunk-only data, or ownerless glue. It is a modeled `0x29` function with a source-authored singleton clear, strong `TabPane` vtable/singleton parity, and a valid owner/emitter path. The no-xref status is explained by ordinary destructor versus scalar-wrapper dispatch separation.
   Decision: keep [UID:00034M] reconstructable and source-bearing. Keep [UID:00034W] class-owned but scalar-wrapper/comment-only for C++ emission, not no-owner.

## Source Placement

Recommended source route is [UID:00034M] -> [UID:0000EB] `TabPane` -> [UID:0000OF] `TabPane.cpp` under `NexusTK/ui/panels/`.

[UID:00034M] should be the single source-facing ordinary destructor body for `TabPane`:

```cpp
TabPane::~TabPane()
{
    g_pTabPane = NULL;
}
```

The source-placement reason is behavioral and structural, not only physical adjacency. MCP shows this exact body performs `TabPane` class teardown evidence: the three `TabPane` vtable restores, `g_pTabPane` clear, and inherited `Pane::~Pane()` tail transfer. Current `TabPane` class/file/global docs already route the singleton and class methods through [UID:0000EB] and [UID:0000OF], and the generated `TabPane.cpp` route is already viable. The recommended repair changes the emitted source shape, not the owning source module.

[UID:00034W] should remain in the same `TabPane` source family as class-owned scalar deleting destructor glue. It should not emit a second `TabPane::~TabPane()` source body. Its formal C++ should be comment-only:

```cpp
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().
```

This mirrors the accepted `FpsPane` placement pattern: the ordinary destructor page emits the source-authored singleton clear, while the scalar deleting wrapper page documents vtable/delete-flag ABI support generated from the virtual destructor declaration. Keeping [UID:00034W] owner/emitter metadata with `TabPane` is appropriate because rebuilding `TabPane` must regenerate the wrapper, but handwritten source should live on [UID:00034M].

Do not reroute source placement to `Pane`: `0x00544580` is inherited base destructor cleanup reached after the derived body, and source C++ must rely on implicit base destruction. Do not reroute to `IconsPane`: no `IconsPane` vtables or singleton appear in [UID:00034M] or [UID:00034W]. Do not route through [UID:000170]: that page is a non-emitting mixed physical inventory after the B001 split, and exact children carry source ownership.

## Recommended Target Doc Changes

`by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md` / [UID:00034M] target:

- Change metadata from `COMPLETION:85`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000EB`.
- Change the source-facing identity from provisional `CleanupForDestruction` helper wording to ordinary/non-deleting `TabPane::~TabPane()` source body wording. The physical filename can remain unchanged unless the supervisor explicitly assigns a rename.
- Replace the formal C++ block with `TabPane::~TabPane() { g_pTabPane = NULL; }` using the multiline block shown in `## First-Draft C++ Recommendation`.
- Add MCP-backed evidence at report-level detail: active IDA session, `sub_4CF9D0` size `0x29`, five-instruction body, no xrefs to `0x004cf9d0`, three `TabPane` vtable writes, `g_pTabPane` clear at `0x004cf9ea`, tail jump to `0x00544580`, and surrounding `0xcc` boundary padding.
- Add source-shape notes that vtable stores and `Pane::~Pane()` tail transfer are compiler/implicit destructor mechanics, not handwritten C++.
- Add rejected alternatives for `Pane` owner, `IconsPane` owner, [UID:000170] aggregate emitter, no-owner/non-emitting, explicit base-cleanup source call, and normal called helper method.

## Recommended Support Doc Changes

`by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md` / [UID:00034W] sibling support:

- Keep owner/emitter [UID:0000EB] and `RECONSTRUCTABLE:TRUE`, because this class-owned scalar deleting wrapper must be regenerated from the `TabPane` virtual destructor declaration and class layout.
- Change source-shape wording to scalar deleting destructor glue / source-declared generated-binary support, not a second source destructor body.
- Replace the current duplicate `TabPane::~TabPane()` formal C++ body with a comment-only marker:

```cpp
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().
```

- Preserve existing exact evidence for vtable restores, `g_pTabPane` clear, `Pane::~Pane()` base cleanup, delete flags, adjustor-thunk/primary-vtable route, optional free helper, and successor boundary.
- Score recommendation if fully incorporated: raise from `85/88` to approximately `86/91`, because the source-routing/scalar-wrapper policy would be resolved while the wrapper remains compiler-generated ABI support.

`by-class/TabPane.md` / [UID:0000EB] support:

- Update the method inventory row for [UID:00034M] so it names the ordinary/non-deleting `TabPane::~TabPane()` source body rather than a generic cleanup helper, while preserving the binary facts that it restores vtables, clears `g_pTabPane`, and tails to `Pane::~Pane()`.
- Update the method inventory/source-shape notes for [UID:00034W] so the scalar deleting destructor is documented as compiler-generated wrapper glue regenerated from `TabPane::~TabPane()`, not a separate handwritten source destructor.
- Preserve existing open questions about tab labels, action helper names, helper spelling, and final physical grouping with `IconsPane`; they do not block this destructor source-shape repair.

`by-file/TabPane.md` / [UID:0000OF] support:

- Update proposed contents and data caveats so `ui/panels/TabPane.cpp` emits one source destructor body through [UID:00034M].
- State that [UID:00034W] should only contribute scalar-wrapper evidence/comment marker output, avoiding duplicate generated `TabPane::~TabPane()` definitions.
- Keep the source route through `TabPane.cpp`; do not reroute to `Pane`, `IconsPane`, [UID:000170], or a new old-HUD source file.

`by-global/g_pTabPane.md` / [UID:0000SE] optional support:

- No required edit. The page already records the lifecycle at sufficient detail: constructor write at `0x004cf9a4`, [UID:00034M] clear at `0x004cf9ea`, scalar-wrapper clear at `0x004cfe20`, and shutdown/application reads.
- Optional edit only if the supervisor wants terminology parity: clarify that the `0x004cf9ea` clear belongs to the ordinary `TabPane::~TabPane()` source body after this report is accepted.

`by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md` / [UID:000170] optional support:

- No required metadata or ownership edit. It is already a non-emitting mixed split inventory with [UID:00034M] and [UID:00034W] assigned to [UID:0000EB].
- Optional wording-only edit if the supervisor wants inventory parity: change the [UID:00034M] child role from cleanup helper to ordinary/non-deleting `TabPane::~TabPane()` source body and note [UID:00034W] as scalar deleting wrapper glue. Do not change [UID:000170] `RECONSTRUCTABLE:FALSE`, blank owner/emitter, or non-emitting disposition.

Generated files and coverage/tracker files:

- Do not edit manually. After callback edits and scoped validators, expected generated `auto-generated/NexusTK/ui/panels/TabPane.cpp` result is one `TabPane::~TabPane()` source body with `g_pTabPane = NULL;`; [UID:00034W] should appear only as scalar-wrapper comment/marker evidence, not as a second destructor definition.
- No manual `-coverage-report.md`, `auto-generated/-ag-research-tracker.md`, validator state, archive, or supervisor-ledger edit is recommended from this report.

## Score And Metadata Recommendation

Raise [UID:00034M] from `85/88` to `88/91`.

Rationale:

- Completion improves because this pass resolves the source-facing destructor identity, scalar-wrapper relationship, no-xref interpretation, and first-draft C++ shape instead of leaving the page as a generic cleanup helper.
- Confidence improves because live MCP reconfirmed the exact function, body, xrefs, vtable refs, singleton refs, boundary bytes, and base destructor identity; current project precedents independently support the same ordinary-destructor policy.
- Keep `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000EB`. The target remains a `TabPane` source-bearing destructor body routed through `TabPane.cpp`.

Recommended target item summary:

```text
Ordinary/non-deleting TabPane destructor body: live MCP reconfirms exact 0x004cf9d0-0x004cf9f9 range, no direct xrefs, three TabPane vtable restores at +0x00/+0xa0/+0xa4, g_pTabPane clear at 0x004cf9ea, tail transfer to Pane::~Pane at 0x00544580, constructor/scalar-wrapper vtable and singleton parity, boundary padding, owner/emitter route through TabPane, and source C++ as TabPane::~TabPane() with only the singleton clear while vtable/base cleanup are compiler/implicit destructor mechanics.
```

Recommended support metadata:

- [UID:00034W] should keep owner/emitter `0000EB`, `RECONSTRUCTABLE:TRUE`, and score can rise from `85/88` to approximately `86/91` if the scalar-wrapper/no-code policy is incorporated with the exact current evidence already present.
- No class/file owner reroute is recommended. [UID:0000EB] and [UID:0000OF] already satisfy the source route; they need method/source-shape wording updates, not a metadata move.

## First-Draft C++ Recommendation

Populate [UID:00034M] with this exact formal C++:

```cpp
TabPane::~TabPane()
{
    g_pTabPane = NULL;
}
```

Do not include explicit vtable writes, `Pane::~Pane()`, `Pane::CleanupForDestruction()`, delete flags, or operator delete calls in this target's C++. Those are compiler/implicit destructor mechanics or scalar-wrapper behavior.

The current [UID:00034W] formal destructor body should be replaced with a comment-only compiler-wrapper marker so `auto-generated/NexusTK/ui/panels/TabPane.cpp` does not emit duplicate `TabPane::~TabPane()` definitions:

```cpp
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().
```

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| [UID:00034M] is the ordinary/non-deleting `TabPane::~TabPane()` body, not a normal called `CleanupForDestruction` method. | MCP `lookup_funcs`, `analyze_function`, `disasm`, no xrefs, FpsPane precedent. | `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md` status, behavior, reconstruction notes, title/source-facing name wording. | incorporate | applied: target title/status/behavior/reconstruction notes now describe ordinary/non-deleting `TabPane::~TabPane()`; class/file/aggregate support synced. Validator `000000004634` ok:1 for target, `000000004636` ok:1 for class, `000000004637` ok:1 for file, `000000004639` ok:1 for aggregate. |
| The source-authored statement in [UID:00034M] is `g_pTabPane = NULL;`. | MCP disasm clear at `0x004cf9ea`; `g_pTabPane` support doc; constructor/scalar parity. | Target C++ block and behavior notes. | incorporate | applied: target formal C++ is `TabPane::~TabPane() { g_pTabPane = NULL; }`; generated `auto-generated/NexusTK/ui/panels/TabPane.cpp` header `validator-command-id: 000000004637` emits exactly one destructor body with that statement. |
| Vtable stores at `+0x00`, `+0xa0`, and `+0xa4` are compiler destructor lowering. | MCP disasm refs to `0x0061b4d0`, `0x0061b51c`, `0x0061b54c`; destructor precedents. | Target reconstruction notes; TabPane class/file method notes. | incorporate | applied: target Behavior/IDA Evidence/Reconstruction Notes and class/file source-shape notes state vtable stores are compiler destructor-layout output, not handwritten C++. |
| Tail jump to `0x00544580` is implicit base destructor chaining to `Pane::~Pane()`, not a handwritten source call. | `PaneCore` identifies `0x00544580-0x00544687` as `Pane::~Pane`; MCP disasm tail jump; FpsPane precedent. | Target behavior/reconstruction notes; remove explicit `Pane::CleanupForDestruction()` from target C++. | incorporate | applied: target C++ no longer calls `Pane::CleanupForDestruction`; target/class/file docs describe the transfer as inherited `Pane::~Pane()` base destruction. |
| No xrefs to `0x004cf9d0` do not make the body dead or ownerless. | MCP `xref_query` total 0; scalar wrapper [UID:00034W] carries vtable/thunk route; accepted ordinary-destructor precedents. | Target source-quality / xrefs notes. | incorporate | applied: target IDA Evidence and Ownership Decision explain no xrefs as expected for ordinary destructor with [UID:00034W] vtable-visible delete route, rejecting no-owner/non-emitting. |
| [UID:00034W] is class-owned scalar deleting destructor glue and should not emit a second `TabPane::~TabPane()` body. | Sibling doc, generated `TabPane.cpp`, FpsPane scalar-wrapper policy. | `by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md` C++/reconstruction notes. | incorporate | applied: sibling formal C++ is comment-only scalar-wrapper marker, score `86/91`, owner/emitter unchanged; generated `TabPane.cpp` shows UID00034W as comment only. Validator `000000004635` ok:1. |
| Owner/emitter remain [UID:0000EB] `TabPane`; file route remains [UID:0000OF] `TabPane.cpp`. | `TabPane` vtables, `g_pTabPane`, support docs, B001 split report. | Target metadata and support docs. | already-present | applied: target and sibling keep `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EB`; class/file route through [UID:0000EB]/[UID:0000OF] preserved. |
| [UID:000170] remains non-emitting mixed inventory. | B001 report and current aggregate page. | No direct edit required except possible cross-reference wording if supervisor wants parity. | already-present | applied: aggregate metadata remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters; child inventory wording/scores were updated because stale rows contradicted accepted UID00034M/UID00034W changes. Validator `000000004639` ok:1. |
| `IconsPane` is rejected as owner. | No `IconsPane` vtable/global refs in target; separate IconsPane cleanup/scalar ranges. | Target rejected alternatives. | incorporate | applied: target Ownership Decision rejects `IconsPane`; class/file route remains `TabPane`; aggregate still separates `IconsPane` children. |

## Implementation Tracking Checklist

- [x] Update `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md` metadata from `85/88` to `88/91`, keeping `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000EB`. Proof: target metadata updated; validator `python .\tools\validator.py --mode file --file by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md --apply --queue-timeout 240`, command_id `000000004634`, timestamp `2026-07-02T16:04:52-04:00`, exit `0`, `ok:1`.
- [x] Update the target title/status/body wording from provisional `CleanupForDestruction` helper toward ordinary/non-deleting `TabPane::~TabPane()` source body while preserving the historical filename/UID. Proof: target title is `TabPane Ordinary Destructor`; filename/UID unchanged.
- [x] Replace the target formal C++ block with:

```cpp
TabPane::~TabPane()
{
    g_pTabPane = NULL;
}
```

- [x] Add/expand target evidence: MCP session state, function size `0x29`, five-instruction body, no xrefs to `0x004cf9d0`, three `TabPane` vtable writes, `g_pTabPane` clear at `0x004cf9ea`, tail jump to `0x00544580`, and boundary `0xcc` padding. Proof: target `IDA Evidence` section.
- [x] Add target reconstruction notes that vtable writes and the `Pane::~Pane()` tail transfer are compiler/implicit destructor mechanics, not handwritten source statements. Proof: target `Behavior` and `Reconstruction Notes`.
- [x] Add target rejected alternatives: `Pane` owner, `IconsPane` owner, mixed aggregate emitter, no-owner/non-emitting, explicit base-cleanup source call, and normal called helper method. Proof: target `Ownership Decision`.
- [x] Update `by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md` to mirror the accepted FpsPane scalar-wrapper policy: keep class-owned reconstructable metadata, classify source handling as compiler-generated scalar deleting destructor glue, and replace duplicate destructor C++ with:

```cpp
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().
```

- [x] Raise [UID:00034W] confidence to `86/91` because the scalar-wrapper/no-code policy is fully incorporated; preserve exact flag/delete evidence already present. Proof: sibling metadata/summary/reconstruction notes; validator `000000004635`, timestamp `2026-07-02T16:04:54-04:00`, exit `0`, `ok:1`.
- [x] Update `by-class/TabPane.md` method inventory and draft-C++/status notes so [UID:00034M] is the ordinary destructor source body and [UID:00034W] is scalar-wrapper glue. Preserve existing open questions about tab labels, action-helper names, and final source grouping. Proof: class Important Methods, Live IDA Evidence, Draft C++ Status, Changes; validator `000000004636`, timestamp `2026-07-02T16:04:56-04:00`, exit `0`, `ok:1`.
- [x] Update `by-file/TabPane.md` proposed contents/data caveats to avoid duplicate source destructor emission and to record that `TabPane.cpp` should emit one source destructor body through [UID:00034M]. Proof: file Proposed Contents, Behavior Notes, Live Function Map, Data Caveats, Changes; validator `000000004637`, timestamp `2026-07-02T16:04:58-04:00`, exit `0`, `ok:1`.
- [x] Verify `by-global/g_pTabPane.md`. Proof: no edit needed; lifecycle already records constructor write at `0x004cf9a4`, [UID:00034M] clear at `0x004cf9ea`, scalar deleting destructor clear at `0x004cfe20`, and reads at `0x0049e5e6`/`0x00504936`. Marked already-present; no lease/edit/validator run for this file.
- [x] Update [UID:000170] aggregate because its child inventory contradicted accepted UID00034M/UID00034W role/score changes. Proof: aggregate child rows now list [UID:00034M] as `88/91` ordinary/non-deleting `TabPane::~TabPane()` source body and [UID:00034W] as `86/91` scalar deleting destructor glue; aggregate metadata unchanged as non-emitting. Validator `000000004639`, timestamp `2026-07-02T16:05:08-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validators after callback edits:
  - `python .\tools\validator.py --mode file --file by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md --apply --queue-timeout 240` -> command_id `000000004634`, timestamp `2026-07-02T16:04:52-04:00`, exit `0`, `ok:1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md --apply --queue-timeout 240` -> command_id `000000004635`, timestamp `2026-07-02T16:04:54-04:00`, exit `0`, `ok:1`.
  - `python .\tools\validator.py --mode file --file by-class/TabPane.md --apply --queue-timeout 240` -> command_id `000000004636`, timestamp `2026-07-02T16:04:56-04:00`, exit `0`, `ok:1`.
  - `python .\tools\validator.py --mode file --file by-file/TabPane.md --apply --queue-timeout 240` -> command_id `000000004637`, timestamp `2026-07-02T16:04:58-04:00`, exit `0`, `ok:1`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md --apply --queue-timeout 240` -> command_id `000000004639`, timestamp `2026-07-02T16:05:08-04:00`, exit `0`, `ok:1`.
- [x] Inspect generated `auto-generated/NexusTK/ui/panels/TabPane.cpp` after validator refresh. Proof: after queue status `000000004642` showed no queued/processing generated refresh jobs, generated file header is `validator-command-id: 000000004637`, `validator-refreshed-at: 2026-07-02T16:04:58-04:00`, and output has one `TabPane::~TabPane()` body with `g_pTabPane = NULL;`; UID00034W appears only as `// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().`
- [x] Update this report's Claim And Incorporation Ledger during callback from `proposed` to `applied`, `already-present`, or `excluded-with-reason` claim by claim. Proof: ledger above.
- [x] Supervisor-owned generated tracker/coverage refresh should happen through validator/report execution only; no manual coverage-report or `auto-generated/-ag-research-tracker.md` edit is recommended. Proof: no manual coverage/generated edits; validator reported projected stats updates and generated refreshes.
- [x] B-agent must not run any `execute_report`, lifecycle/archive, registry repair, or manual report move command. Proof: no such command was run; only scoped file validators, queue-status checks, and lease/unlease commands were used.

Lease cleanup:

- [x] Leased immediate edit batch as `B015`: target, sibling, class, file docs. Later leased aggregate after contradiction was found. Release result: aggregate lease released successfully; the first four leases were already not active by cleanup (`Rejected[No active lease]`). Current lease report after cleanup shows no active B015 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004680","destination_path":"executed-b-agent-research/B015/00034M-TabPaneCleanupHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/00034M-TabPaneCleanupHelper-source-quality.md","timestamp":"2026-07-02T16:29:55-04:00","uid":"00034M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
