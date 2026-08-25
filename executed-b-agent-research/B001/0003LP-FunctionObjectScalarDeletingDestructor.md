** TARGET-REPORT-UID:0003LP **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003LP **
# 0003LP FunctionObjectScalarDeletingDestructor Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: assign UID `0003LP` to [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) after the parent class page is repaired from `80/82` to `85/88`.
- Final disposition: exact base `FunctionObject::vftable` scalar deleting destructor support; `source-declared/generated-binary`, reconstructable, no handwritten C++ body.
- Required action: repair the [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) class evidence and score, then set UID `0003LP` to `CANONICAL_OWNER:00005K`, `EMITTER_UIDS:00005K`, `RECONSTRUCTABLE:TRUE`, with blank reconstruction C++.
- Confidence: high (`0.88`) for the direct class owner after parent repair. This is stronger than UID `000123` because `0x0049b250` is the actual `FunctionObject::vftable` slot.

## Supporting Research

## Target

- Target UID: `0003LP`.
- Target path: `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, currently:

```markdown
| [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |  |
```

- Tracker: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003LP`, assigned to Agent-B001 on 2026-06-13.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.

## Executive Recommendation

The direct semantic owner is [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md). The evidence is now sufficient to repair that class page to the strict `85/85` gate, then assign UID `0003LP` through the class. Do not route UID `0003LP` directly to [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md); that would bypass the narrower true class owner. The class already routes to `FunctionObjects`, so `EMITTER_UIDS:00005K` will still surface output under `auto-generated/NexusTK/util/FunctionObjects.cpp`.

This target should not be reclassified to `RECONSTRUCTABLE:FALSE`. The exact bytes are compiler-emitted scalar-deleting-destructor glue, but the rebuilt source must still declare the `FunctionObject` callback base/virtual destructor shape that causes the compiler to emit the wrapper. Keep the C++ block blank.

No split is needed. C001 already split the old sparse `0x0049b090-0x0049b28e` range, and IDA confirms `0x0049b250-0x0049b28e` is one exact `0x3e` byte function with padding before and after.

## Supervisor Active Recheck

- Supervisor assignment: research UID `0003LP` as the sibling of accepted B001-000123, determine FunctionObject/FunctionObjects/no-owner/reclassification outcome, and create this one report in B001's research root.
- Split status: no split repair is required. The target covers exactly one function; the intervening `0x0049b0ce-0x0049b250` mixed span is already excluded.
- Source-bearing child status: UID `0003LP` can clear `85/88` once the new evidence is added. Its direct parent [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) can also clear `85/88` after adding the base vtable layout and purecall-slot evidence recorded below.

## Inference Research Guidance Check

- `by-structure.md` says `CANONICAL_OWNER` should use the narrowest true owner and specifically warns not to bypass a class/type/global owner merely to reach a file root.
- `by-structure.md` also supports `source-declared/generated-binary`: source declarations are required even though exact binary bytes should be compiler/linker output.
- Fact: `0x0049b250` has a single data xref from the named base `FunctionObject::vftable` at `0x006186a8`.
- Fact: the base vtable has FunctionObject RTTI and purecall slots.
- Inference: the original source likely declared an abstract `FunctionObject` callback base with a virtual destructor and pure virtual callback operations under the shared `FunctionObjects` utility family.

## Evidence Standards Used

Evidence types used:

- IDA MCP function lookup, decompilation, disassembly, callees, component analysis, bytes, integer slot reads, vtable/name queries, and xrefs.
- Documentation evidence from the target page, [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md), [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md), [UID:0001WQ][FunctionObjectTemplates](../../../../../by-type/by-template/FunctionObjectTemplates.md), [UID:0001Q9][client_callback_dispatch](../../../../../by-meta/client_callback_dispatch.md), proposed source tree, destructor-band aggregate, generated rows, and the B001-000123 context.
- Negative evidence: no ordinary code callers, no concrete feature constructor stores to this function, and no multi-consumer callback-template vtable refs like UID `000123`.

The evidence is sufficient because it matches the already accepted `FunctionObject0` ownership pattern: exact destructor child pages attach to the callback-base class when the class page reaches `85/85`, and the class routes to [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md).

## IDA MCP Facts

Function/range facts:

- `lookup_funcs` reports `0x0049b250` as `sub_49B250`, size `0x3e`.
- `lookup_funcs` reports `0x0049b28e` is not a function and `0x0049b290` is the successor function start.
- `get_bytes` reports `0xcc` at `0x0049b24f` before the function and `0xcc 0xcc` at `0x0049b28e` after it.
- `0x0049b250-0x0049b28e` is one exact scalar deleting destructor body.

Decompile/disassembly facts:

- `sub_49B250` writes `FunctionObject::vftable` to `*this` at `0x0049b256`.
- It calls `sub_4F4A90`, which decompiles to storing `LObject::vftable`.
- It tests scalar deleting flags `(flags & 1)` and `(flags & 4)`.
- It calls `sub_4F4AC0` only on ordinary delete; `sub_4F4AC0` calls allocator/free helpers.
- Its guard/no-free path pushes constant `0x04`, matching a 4-byte base object shell. This contrasts with UID `000123` at `0x0049b090`, whose guard path pushes `0x18` for the 24-byte callback-template objects.
- Callees are only `sub_4F4A90`, `sub_4F4AC0`, and `_guard_check_icall_nop`.

Vtable/global/type facts:

- `entity_query` names `0x006186a8` as `??_7FunctionObject@@6B@`.
- `entity_query` names `0x0064620c` as `??_R4FunctionObject@@6B@`; the dword immediately before the vtable, `0x006186a4`, points to this RTTI locator.
- `get_int` slot reads:
  - `0x006186a4 -> 0x0064620c` (`FunctionObject` complete-object locator);
  - `0x006186a8 -> 0x0049b250` (base scalar deleting destructor);
  - `0x006186ac -> 0x004f4b10` (shared support slot);
  - `0x006186b0 -> 0x0041b6c0` (`nullsub_18`);
  - `0x006186b4 -> 0x005ca28c` (`__purecall`);
  - `0x006186b8 -> 0x005ca28c` (`__purecall`).
- `lookup_funcs 0x005ca28c` identifies `__purecall`, size `0x1b`; decompilation calls the purecall handler and then aborts.

Xref facts:

- `xrefs_to 0x0049b250` returns exactly one data ref: `0x006186a8`.
- `xrefs_to 0x006186a8` returns only vtable reset writes inside `sub_49B090` and `sub_49B250`; no feature constructor stores a base `FunctionObject` vtable.
- `xrefs_to 0x005ca28c` includes `0x006186b4` and `0x006186b8`, confirming abstract purecall slots in the `FunctionObject` vtable.

Negative IDA facts:

- There are no ordinary direct code callers for `0x0049b250`.
- There are no concrete callback-template vtable refs to `0x0049b250`; those go to UID `000123` for 24-byte callback-template destructor support.
- No evidence ties this exact body to PopupMenu, MixItemDialog, NexonclubRegistrationDialog, TerminalPane, or ButtonControlPane feature ownership.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049b250-0x0049b28e` | `0003LP` / target page | base `FunctionObject::vftable` scalar deleting destructor | TRUE | recommend `00005K` | recommend `85/88` | assign after parent repair |
| `0x0049b090-0x0049b0ce` | `000123` | 24-byte callback-template scalar deleting destructor support | TRUE | routed to `0000JO` per B001-000123 | `85/strong` in current coverage | separate sibling, not base vtable slot |
| [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) | class page | abstract callback base declaration/vtable | TRUE | `0000JO` | recommend `85/88` | parent repair required before assignment |
| [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) | file page | shared callback utility family | n/a file root | FILE | `87/85` | source-family route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049b250` | data ref from `0x006186a8` | base `FunctionObject::vftable` destructor slot |
| `0x006186a4` | points to `0x0064620c ??_R4FunctionObject@@6B@` | RTTI locator before vtable |
| `0x006186b4`, `0x006186b8` | point to `0x005ca28c __purecall` | abstract callback base pure virtual slots |
| `0x004f4a90` | callee from destructor | `LObject` base cleanup |
| `0x004f4ac0` | callee from destructor | heap/free helper on delete flags |
| `0x0041b6a0` | callee on guard path | `_guard_check_icall_nop`, compiler/security glue |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already says UID `0003LP` is an exact `FunctionObject` scalar deleting destructor variant and identifies [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) as the related class.
- [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) now distinguishes UID `000123` as callback-template destructor support and `0x0049b250` as the base `FunctionObject::vftable` destructor candidate.
- [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) owns the shared callback-object utility family and explicitly lists `FunctionObject` as part of that family.
- [UID:0001WQ][FunctionObjectTemplates](../../../../../by-type/by-template/FunctionObjectTemplates.md) records `class FunctionObject;` in the likely declaration family.
- [UID:00005L][FunctionObject0](../../../../../by-class/FunctionObject0.md) provides the closest accepted analogue: exact scalar deleting destructor children attach to the callback-base class, and the class emits through [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md).

Existing docs needing repair:

- [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) remains `80/82` even though current IDA and documentation evidence now supports the same gate-clearing quality as [UID:00005L][FunctionObject0](../../../../../by-class/FunctionObject0.md).
- The current target page still says parent assignment remains blank only because the class is below gate. That is now a repairable state, not a terminal no-owner result.
- The proposed source tree still says UID `000123` is the confirmed `FunctionObject` destructor support. It should be updated to say UID `000123` is the 24-byte callback-template destructor support, while UID `0003LP` is the base `FunctionObject::vftable` destructor support.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently marks UID `0003LP` as `no-owner`, `CANONICAL_OWNER:NONE`, blank emitters.
- `by-memory/-coverage-report.md` currently lists UID `0003LP` as reconstructable `84% : strong` and explicitly cites the parent-gate block.
- `by-class/-coverage-report.md` currently lists UID `00005K` as reconstructable `80% : strong`.

## Ranked Ownership Analysis

### 1. [UID:00005K] FunctionObject

- Evidence for:
  - `0x006186a8` is named `FunctionObject::vftable` and points directly to `0x0049b250`.
  - The vtable has a FunctionObject RTTI locator at `0x006186a4 -> 0x0064620c`.
  - Tail slots include `__purecall`, which matches an abstract callback base class.
  - The function writes `FunctionObject::vftable`, calls `LObject` cleanup, and uses base-object guard size `0x04`.
  - This mirrors accepted `FunctionObject0` destructor ownership where exact scalar deleting destructor pages attach to the callback-base class.
- Evidence against:
  - The class page is currently `80/82`, below strict gate.
  - Final original header/source spelling remains inferred.
- Decision:
  - Accept after parent repair. Raise FunctionObject to `85/88`, raise target to `85/88`, then set target owner/emitter to `00005K`.

### 2. [UID:0000JO] FunctionObjects

- Evidence for:
  - The source family owns `FunctionObject` and the shared callback utility declarations.
  - The file page is already `87/85`, and all output ultimately routes through it.
- Evidence against:
  - `by-structure.md` says not to bypass a narrower true class owner.
  - The target is not a free helper or file-level data object; it is the destructor slot of `FunctionObject::vftable`.
- Decision:
  - Reject as canonical owner for the target. Use it as the source-family parent of [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md), reached through `EMITTER_UIDS:00005K`.

### 3. Keep `CANONICAL_OWNER:NONE`

- Evidence for:
  - Current metadata is no-owner because the class page was below gate.
- Evidence against:
  - The direct owner is now clear and repairable.
  - Leaving no-owner would ignore the base vtable name, RTTI, purecall slots, and accepted FunctionObject0 analogue.
- Decision:
  - Reject as final disposition. It is only the current temporary state before parent repair.

### 4. Reclassify `RECONSTRUCTABLE:FALSE`

- Evidence for:
  - The exact scalar deleting destructor body is compiler-generated and should not be hand-written.
- Evidence against:
  - Project policy treats these callback-base destructor wrappers as source-declared/generated-binary, not non-source. The required source declaration still belongs in the rebuilt project.
  - FunctionObject0 destructor children are `RECONSTRUCTABLE:TRUE`, assigned to the class, with blank C++.
- Decision:
  - Reject. Keep `RECONSTRUCTABLE:TRUE`, blank C++.

### 5. Feature/control owners or the ButtonChoiceControlDestructors aggregate

- Evidence for:
  - Physical locality is within the UI control destructor/thunk band.
- Evidence against:
  - The vtable ref is `FunctionObject::vftable`, not a control-pane vtable.
  - The aggregate is explicitly an address-ordered mixed map and non-reconstructable.
  - Feature modules do not store or call this base vtable destructor directly.
- Decision:
  - Reject.

## Proposed New File/Grouping

No new file/grouping is needed. The existing hierarchy is sufficient:

- [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) should own this exact base destructor child.
- [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) remains the source-family/file route.
- [UID:0001WQ][FunctionObjectTemplates](../../../../../by-type/by-template/FunctionObjectTemplates.md) remains supporting type/template documentation.

The likely original source was not a standalone file for this destructor. It was a callback utility declaration, likely in `util/FunctionObjects.h` with optional emitted support represented by `util/FunctionObjects.cpp`.

## Negative Evidence Summary

- The sibling UID `000123` is not evidence that `0003LP` should be routed directly to [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md). UID `000123` had four concrete callback-template vtable consumers and guard size `0x18`; UID `0003LP` has one base vtable ref and guard size `0x04`.
- Lack of direct code callers is expected for virtual destructor slots and does not weaken class ownership.
- Address adjacency to EPF/control-pane destructors does not matter more than the named `FunctionObject` vtable and RTTI.
- `__purecall` is CRT/runtime support. The source-owned fact is that `FunctionObject` declares abstract virtual slots, not that NexusTK owns `__purecall`.

## Final Recommendation

Recommended target metadata for `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` after parent repair:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:00005K
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005K
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Recommended parent metadata for `by-class/FunctionObject.md`:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000JO
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JO
RECONSTRUCTION_CPP CODE: blank
```

Required FunctionObject class content repair:

- Add a base vtable layout section documenting:
  - `0x006186a4 -> 0x0064620c ??_R4FunctionObject@@6B@`;
  - `0x006186a8 -> 0x0049b250` scalar deleting destructor;
  - `0x006186ac -> 0x004f4b10`;
  - `0x006186b0 -> 0x0041b6c0 nullsub_18`;
  - `0x006186b4/0x006186b8 -> 0x005ca28c __purecall`.
- Change Method Notes so UID `0003LP` is the base `FunctionObject::vftable` destructor child and UID `000123` is only related callback-template destructor support.
- Change parent-gate wording to say the page now clears `85/85` after the B001-0003LP repair, while final C++ remains blank below the `95/95` final-source gate.
- Update score rationale to explain the raise from `80/82` to `85/88` using base vtable RTTI, exact destructor child, purecall abstract slots, FunctionObjects source-family routing, and the FunctionObject0 analogue.

Expected `auto-generated/-ag-memory-coverage.md` row after normal metadata refresh:

```markdown
| [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) | emits | `00005K` | `00005K` |  | no | `auto-generated/NexusTK/util/FunctionObjects.cpp` | `by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md` |  |
```

Exact `by-memory/-coverage-report.md` row replacement. Place where the current UID `0003LP` row appears, between UID `0003LO` and UID `0002XZ`:

```markdown
    - [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md) 0x0049b250-0x0049b28e | destructor support | FunctionObjectScalarDeletingDestructor : reconstructable : 85% : strong : Exact base FunctionObject::vftable scalar deleting destructor; assign to [UID:00005K][FunctionObject](by-class/FunctionObject.md) after parent repair to 85/88. IDA confirms the sole destructor data xref from 0x006186a8, FunctionObject RTTI at 0x006186a4, helper/nullsub/purecall vtable slots, base cleanup/free callees, guard size 0x04, source-declared/generated-binary handling, and separation from the 24-byte callback-template sibling [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md).
```

Exact `by-class/-coverage-report.md` row replacement. Place where the current UID `00005K` row appears, between UID `00005J` and UID `00005L`:

```markdown
- [UID:00005K][FunctionObject](by-class/FunctionObject.md) : reconstructable : 85% : strong : Attached to `FunctionObjects`; abstract callback base declaration/support with IDA-confirmed FunctionObject RTTI/vtable at 0x006186a4/0x006186a8, exact base scalar deleting destructor child [UID:0003LP][0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor](by-memory/0x0049b250-0x0049b28e.FunctionObjectScalarDeletingDestructor.md), separated 24-byte callback-template destructor support [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md), helper/nullsub/purecall slot layout, source-declared/generated-binary handling, and final header/template spelling still open.
```

Proposed source-tree wording repair:

- In the `util/FunctionObjects.cpp` / `util/FunctionObjects.h` section, replace the note that UID `000123` is the confirmed FunctionObject destructor support with:
  - "`FunctionObject` owns the base vtable destructor/pure-virtual callback support; UID `0003LP` is the base `FunctionObject::vftable` scalar deleting destructor. UID `000123` is the separate 24-byte callback-template scalar deleting destructor reused by concrete FunctionObject callback vtables."

## Follow-Up Actions

Supervisor actions:

- Assign an A-agent or apply the FunctionObject class repair and target metadata repair in the order above.
- Run the normal project validation/metadata refresh flow, not dry-run mode.
- Apply the exact coverage row replacements above if the normal refresh does not regenerate them.

A-agent actions:

- Update [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) with the base vtable layout and score repair.
- Update UID `0003LP` target metadata and status/evidence wording.
- Update proposed source-tree wording as noted.

B001 future research actions:

- None required for this target. Any broader callback-template declaration spelling work belongs to final source reconstruction, not this ownership decision.

## Confidence

- Recommendation confidence: high (`0.88`).
- Score confidence: `85/88` for both the class and child is justified by IDA vtable/RTTI/purecall/destructor evidence and the accepted FunctionObject0 pattern.
- Remaining uncertainty: exact original header spelling and whether the compiler emitted/folded multiple deleting destructor bodies. This does not change the direct owner or route.

## Validator Results

- IDA MCP commands/results used:
  - `idb_list` / `server_health`: active session `b001_0003lq`, `NexusTK.exe.i64`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs`: `0x0049b250` size `0x3e`; `0x0049b28e` not a function; `0x0049b290` successor; `0x005ca28c` is `__purecall`.
  - `decompile` / `disasm`: `0x0049b250` writes `FunctionObject::vftable`, calls base cleanup, checks scalar delete flags, conditionally frees, and uses guard size `0x04`.
  - `callees` / `analyze_component`: target calls only `sub_4F4A90`, `sub_4F4AC0`, and `_guard_check_icall_nop`; no strings.
  - `xrefs_to`: `0x0049b250` has exactly one data ref at `0x006186a8`; `0x005ca28c` has purecall slot refs including `0x006186b4` and `0x006186b8`.
  - `entity_query`: `0x006186a8` named `??_7FunctionObject@@6B@`; `0x0064620c` named `??_R4FunctionObject@@6B@`.
  - `get_int` / `get_bytes`: base vtable slot layout and padding before/after the exact function.
- Normal validator was not run because B001 changed only this research report and did not edit validator-managed docs.
- Dry-run validator and memory-range modes were not used.
- No unresolved tool blocker.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003LP-FunctionObjectScalarDeletingDestructor.md`
- Modified:
  - none
- Renamed:
  - none
- Moved to executed:
  - none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003LP","source_path":"executed-b-agent-research/B001/0003LP-FunctionObjectScalarDeletingDestructor.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
