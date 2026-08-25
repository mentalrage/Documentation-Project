** TARGET-REPORT-UID:0003M1 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003M1 MonsterImageLib Scalar Deleting Destructor Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](../../../../../by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) should route through [UID:00008N][MonsterImageLib](../../../../../by-class/MonsterImageLib.md).
- Final disposition: assign `CANONICAL_OWNER:00008N`, set `EMITTER_UIDS:00008N`, keep `RECONSTRUCTABLE:TRUE`, keep `RECONSTRUCTION_CPP` blank, and treat the function as source-declared/generated-binary destructor glue.
- Required action: target page has been updated and validated. Supervisor should update the tracker row and apply the manual `by-memory/-coverage-report.md` row replacement listed below.
- Confidence: high. Direct IDA evidence proves exact function bounds, the MonsterImageLib vtable slot, constructor/destructor/scalar vptr references, ordinary-destructor cleanup parity, singleton clear, and neighboring ImageLib-family boundaries. No split or adjacent parent repair is required.

## Supporting Research

## Target

- Target UID: `0003M1`
- Target path: `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, originally no-owner with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.
- Supervisor tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003M1`.
- Current applied state after B002 repair: `COMPLETION:85`, `CONFIDENCE:91`, `CANONICAL_OWNER:00008N`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008N`.

## Executive Recommendation

This target is already an exact child function, not a mixed aggregate. The best direct owner is the `MonsterImageLib` class because the function is the first slot of `??_7MonsterImageLib@@6B@`, restores that same vtable in the body, runs the MonsterImageLib cleanup sequence, and clears `g_pMonsterImageLib`. The file parent [UID:0000LJ][MonsterImageLib](../../../../../by-file/MonsterImageLib.md) is the indirect source root through the class.

Do not leave this page no-owner/non-emitting. The wrapper has no hand-written C++ body to emit, but the class destructor/vtable declaration must recreate it in the rebuilt binary. The owner/emitter model used by the sibling [UID:0002IO][ImageLib scalar deleting destructor](../../../../../by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) applies here: class owner/emitter, blank C++ body, reconstructable generated-binary effect.

## Supervisor Active Recheck

- Supervisor assignment `B002-0003M1` asked whether this no-owner item should route through `MonsterImageLib`, stay no-owner/non-emitting, gain emitters, be reclassified, or require adjacent ImageLib parent/child repair.
- Split-first check: no split is needed. IDA reports one function at `0x004e6750-0x004e6860`, with `0xcc` alignment before and after; the next function begins at `0x004e6870`.
- Child creation/repair: no new child pages were justified. The in-scope repair was the existing exact target page metadata/body.

## Inference Research Guidance Check

- `by-structure.md` owner rules favor the narrowest true semantic owner. Here that is the class, not the broader file, because the destructor wrapper is a virtual slot and operates on a `MonsterImageLib` object.
- `inference_research.md` supports making the best defensible source inference when direct original source proof is unavailable. The IDA facts are stronger than inference alone: the vtable name, singleton, cleanup path, and ordinary destructor parity all point to `MonsterImageLib`.
- Existing docs were treated as leads, then checked against live IDA MCP. The previous target page's `CANONICAL_OWNER:NONE` was contradicted by current vtable/body evidence and by the already-gated `MonsterImageLib` class/file pages.

## Evidence Standards Used

- IDA MCP facts: `server_health`, `lookup_funcs`, `entity_query`, `xrefs_to`, `callees`, `decompile`, `get_int`, `int_convert`, `get_bytes`, and `list_globals`.
- Documentation evidence: target page, `MonsterImageLib` class/file pages, ordinary destructor page, vtable/vtable-data pages, `g_pMonsterImageLib`, sibling `ImageLib` scalar deleting destructor page, generated memory coverage, manual by-memory coverage context, and no-owner tracker.
- Negative evidence: adjacent Human/Item/Light/MapTile/NewHuman/Riding/StaticObj ImageLib-family functions, generic `ImageLib` pages, consumer global xrefs, and the old mixed ImageLib-family aggregate model.

## IDA MCP Facts

### Function/range facts

| Query | Result | Meaning |
| --- | --- | --- |
| `server_health` | `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready | Live IDA session was usable for direct evidence. |
| `lookup_funcs 0x004e6750` | `sub_4E6750`, size `0x110` | Exact target function is `0x004e6750-0x004e6860`. |
| `lookup_funcs 0x004e6860` | not a function | Confirms exclusive end and no hidden child at the boundary. |
| `entity_query functions 0x004e6400-0x004e6b00` | functions at `0x004e6460`, `0x004e64a0`, `0x004e6580`, `0x004e65e0`, `0x004e66a0`, `0x004e6750`, `0x004e6870`, `0x004e68b0`, `0x004e6990`, `0x004e6ab0`, `0x004e6ae0` | Places this function among adjacent ImageLib-family scalar destructors without overlap. |
| `get_bytes 0x004e6748 size 8` | eight `0xcc` bytes | Padding before target. |
| `get_bytes 0x004e6860 size 32` | sixteen `0xcc` bytes, then next prologue at `0x004e6870` | Padding after target; no split needed. |

### Vtable/global facts

| Query | Result | Meaning |
| --- | --- | --- |
| `xrefs_to 0x004e6750` | one data xref at `0x0061b6e4` | The function is reached as vtable data, not ordinary direct code. |
| `entity_query names 0x0061b6d0-0x0061b700` | `??_7HumanImageLib@@6B@` at `0x0061b6d4`, `??_7MonsterImageLib@@6B@` at `0x0061b6e4`, `??_7RidingImageLib@@6B@` at `0x0061b6f4` | The slot belongs to `MonsterImageLib`, with neighboring class boundaries clear. |
| `get_int 0x0061b6e4 u32le` + `int_convert` | `0x004e6750` | The `MonsterImageLib` vtable slot points to this target. |
| `get_int 0x0061b6e0/0x0061b6f0 u32le` + `int_convert` | `0x00648c14` / `0x00648cb4` | Monster RTTI precedes the slot; Riding RTTI begins the next table. |
| `list_globals *MonsterImageLib*` | vtable `0x0061b6e4`, RTTI `0x00648c14`, Singleton RTTI records, type descriptors | Live names agree with the class owner model. |

### Xref/callee/decompile facts

| Address / Item | Xref / Callee | Meaning |
| --- | --- | --- |
| `0x0061b6e4` | xrefs from `0x004daf16`, `0x004db036`, `0x004e677d` | Constructor installs, ordinary destructor restores, scalar destructor self-restores the same vtable. |
| `0x0069b440` | 22 xrefs, including `0x004daef7`, `0x004daefe`, `0x004db0d7`, `0x004e5bd0`, `0x004e681e` | `g_pMonsterImageLib` lifecycle belongs to the MonsterImageLib class/file. |
| `0x004dc2e0` | called from `0x004db03c`, `0x004e6783`, `0x00505054` | The scalar wrapper calls `ClearLoadedData` at the same cleanup point as the ordinary destructor. |
| `callees 0x004e6750` | `0x004dc2e0`, vector destructor/free helpers, `0x004573d0`, `0x004f4a90`, `0x004f4ac0`, guard/invalid-parameter support | Matches documented MonsterImageLib cleanup plus optional delete. |
| `decompile 0x004e6750` | sets `*Block = &MonsterImageLib::vftable`, calls `sub_4DC2E0`, frees table/cache/vector fields, calls `sub_4F4A90`, clears `unk_69B440`, conditionally calls `sub_4F4AC0` | Direct body evidence for class destructor wrapper semantics. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e6750-0x004e6860` | [UID:0003M1](../../../../../by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) | `MonsterImageLib` scalar deleting destructor | TRUE | [UID:00008N][MonsterImageLib](../../../../../by-class/MonsterImageLib.md) | `85/91` | Repaired and validated. |
| `0x004e6860-0x004e6870` | no page needed | `0xcc` alignment | ignored/padding | none | n/a | Not a child function; no page created. |

## Documentation Evidence And IDA Status

- Target page evidence: before B002 it already documented exact `sub_4E6750`, cleanup path, vtable slot, and source-declared/generated-binary handling, but metadata still said `CANONICAL_OWNER:NONE`.
- [UID:00008N][MonsterImageLib](../../../../../by-class/MonsterImageLib.md): already `85/85`, lists this scalar deleting destructor, `g_pMonsterImageLib`, vtable `0x0061b6e4`, ordinary destructor, `ClearLoadedData`, and file parent `0000LJ`.
- [UID:0000LJ][MonsterImageLib](../../../../../by-file/MonsterImageLib.md): already `86/86`, lists the scalar destructor in the source-owned range inventory and records constructor/destructor/scalar vtable refs plus singleton lifecycle.
- [UID:0001Y7][MonsterImageLibVtable](../../../../../by-type/by-vtable/MonsterImageLibVtable.md) and [UID:0002MM][MonsterImageLibVtableData](../../../../../by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md): already route through the `MonsterImageLib` class and identify slot `+0x00 -> 0x004e6750`.
- [UID:00017D][MonsterImageLibDestructor](../../../../../by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md): documents ordinary destructor cleanup parity and the scalar wrapper's optional delete path.
- [UID:0002IO][ImageLibScalarDeletingDestructor](../../../../../by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md): sibling precedent uses class owner/emitter with blank C++ for a source-declared/generated-binary scalar deleting destructor.
- Generated memory coverage before repair: `0003M1` appeared in the no-owner list with `CANONICAL_OWNER:NONE` and blank emitters.
- Generated memory coverage after validator: `0003M1` appears as `emits`, owner `00008N`, emitter `00008N`, output `auto-generated/NexusTK/render/MonsterImageLib.cpp`, no code body.

## Ranked Ownership Analysis

### 1. [UID:00008N] MonsterImageLib class

- Evidence for: vtable slot is named `??_7MonsterImageLib@@6B@`; slot dword points to `0x004e6750`; body writes the MonsterImageLib vtable, runs MonsterImageLib cleanup, clears `g_pMonsterImageLib`, and shares `ClearLoadedData` with the ordinary destructor.
- Evidence against: final source C++ for the class destructor/layout is not at the `95/95` source gate, so the wrapper body should not be hand-emitted.
- Decision: accepted. This is the narrowest direct semantic owner and it clears the strict gate at `85/85`.

### 2. [UID:0000LJ] MonsterImageLib file

- Evidence for: file page owns the render/image module, resource inputs, singleton, class, constructor/destructor/cache cleanup, and projected path `NexusTK/render/MonsterImageLib.cpp`.
- Evidence against: the function is a virtual class destructor wrapper, so the class is the more precise direct owner under by-structure rules.
- Decision: accepted as indirect source root only through class `00008N`; do not set direct owner to the file.

### 3. [UID:00006E]/[UID:0000K2] ImageLib generic class/file

- Evidence for: same address neighborhood and same broad ImageLib-family destructor island.
- Evidence against: target vtable slot is `MonsterImageLib`, not generic `ImageLib`; singleton is `g_pMonsterImageLib`, not `g_pEPFLib`; cleanup path is MonsterImageLib table/cache/archive state, not ImageLib EPF list state.
- Decision: rejected.

### 4. `CANONICAL_OWNER:NONE` with no emitters

- Evidence for: the wrapper is compiler-generated and final C++ should stay blank.
- Evidence against: source-declared/generated-binary artifacts still need owner/emitter routing when their class declaration must regenerate the bytes. Sibling scalar destructor pages already follow that model.
- Decision: rejected. Blank C++ does not mean no owner or non-emitting.

### 5. Split or adjacent parent/child repair

- Evidence for: the surrounding ImageLib family has a history of broad aggregate/barrier repair.
- Evidence against: the assigned target is already exact, has padding boundaries, and does not include adjacent child functions. Parent docs for `MonsterImageLib`, its vtable, vtable data, singleton, and ordinary destructor already clear the owner gate.
- Decision: no split and no adjacent ImageLib parent repair required for this target.

## Negative Evidence Summary

- Consumer xrefs to `g_pMonsterImageLib` do not transfer ownership to `Application`, render consumers, object panes, or map/UI code; they are reads/users of the singleton, while writes and destructor clears stay in MonsterImageLib lifecycle code.
- Adjacent scalar destructors for Human/Image/Item/Light/MapTile/NewHuman/Riding/StaticObj image libraries are separate functions with separate vtable slots and singleton/global evidence.
- Generic `ImageLib` is a sibling/base-style image library, not this target's direct owner. Its scalar destructor at `0x004e64a0` has its own vtable and singleton evidence.
- The `0x004e6860-0x004e6870` gap is padding, so there is no hidden unresolved child that would justify keeping the target as a container or mixed aggregate.

## Final Recommendation

- Applied target metadata repair:
  - `COMPLETION:82 -> 85`
  - `CONFIDENCE:90 -> 91`
  - `CANONICAL_OWNER:NONE -> 00008N`
  - `EMITTER_UIDS: -> 00008N`
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `RECONSTRUCTION_CPP` remains blank
- No child pages created.
- No parent docs edited. Existing `MonsterImageLib`, `MonsterImageLib` file, vtable, vtable-data, ordinary destructor, singleton helper, and global docs already support the route.
- No by-memory coverage report edit was made by B002.

## Exact Supervisor Actions Required

1. Update `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003M1` to complete/reclassified with recommendation `CANONICAL_OWNER:00008N`; `EMITTER_UIDS:00008N`; validated yes.
2. Apply this exact replacement row in `by-memory/-coverage-report.md`, replacing the current line between the MapTile row and the NewHuman row:

```markdown
    - [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) 0x004e6750-0x004e6860 | scalar-deleting-destructor | MonsterImageLibScalarDeletingDestructor : reconstructable : 85% : strong : B002 assigned this source-declared/generated-binary wrapper to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md); live IDA confirms `sub_4E6750` size `0x110`, vtable slot `0x0061b6e4 -> 0x004e6750`, constructor/destructor/scalar vptr refs, `ClearLoadedData` parity with the ordinary destructor, `g_pMonsterImageLib` clear at `0x004e681e`, optional delete handling, and padding/neighbor boundaries, with final C++ intentionally blank below the class source gate.
```

3. No `by-memory/-coverage-report.md` insertion is needed; this is a row replacement only.

## Follow-Up Actions

- Supervisor: apply the tracker and manual coverage-report updates, then move this report to the executed folder if accepted.
- A-agent actions: none required for this target. Future normal ownership polish could revisit [UID:00017D][MonsterImageLibDestructor](../../../../../by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md), whose direct metadata currently routes to file while its body is a class destructor, but that is outside this assignment and not a blocker for `0003M1`.
- B002 future research actions: none for `0003M1` after supervisor acceptance.

## Confidence

- Recommendation confidence: high (`91`). The class owner is proven by vtable, body, global, and cleanup evidence.
- Score confidence: `85/91` is justified for strict parent assignment but still below final-source quality because the class destructor source spelling and complete layout names are not final.
- Remaining uncertainty: exact original source spelling of the destructor declaration and helper names, not owner/emitter routing.

## Validator Results

- Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0003M1-MonsterImageLibScalarDeletingDestructor-removed.md](0003M1-MonsterImageLibScalarDeletingDestructor-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `ok: 1`.
- Reported key updates: `completion_update 0003M1 ... 85`; `confidence_update 0003M1 ... 91`; `canonical_owner_update 0003M1 ... NONE -> 00008N`; `autogen_registry_update 0003M1 ... -> 00008N`; `autogen_report_update auto-generated/-ag-memory-coverage.md`; `projected_stats_update project-level/-auto-completion-stats.md`; `autogen_emitter_has_no_code 00000D by-class/Application.md emitting children only`.
- Generated coverage state after validation: `0003M1` appears as `emits`, owner `00008N`, emitter `00008N`, output `auto-generated/NexusTK/render/MonsterImageLib.cpp`, and no code body.
- Unresolved validator errors: none observed.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B002/research/0003M1-MonsterImageLibScalarDeletingDestructor.md`
- Modified directly by B002:
  - `by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md`
- Modified by validator `--apply` side effects:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - validator reported registry rebuild/update and backup creation under `tools/validator_autogen_backup/20260613-140554`
- Not edited:
  - `by-memory/-coverage-report.md`
  - `by-class/MonsterImageLib.md`
  - `by-file/MonsterImageLib.md`
  - adjacent ImageLib-family parent/child pages

## Blockers

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0003M1-MonsterImageLibScalarDeletingDestructor.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"0003M1"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003M1-MonsterImageLibScalarDeletingDestructor-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0003M1-MonsterImageLibScalarDeletingDestructor.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003M1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
