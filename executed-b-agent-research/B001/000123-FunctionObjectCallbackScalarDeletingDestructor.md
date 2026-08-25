** TARGET-REPORT-UID:000123 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000123 FunctionObjectCallbackScalarDeletingDestructor Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: repair UID `000123` from no-owner to the shared FunctionObjects source-family route: `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`, `RECONSTRUCTABLE:TRUE`.
- Final disposition: source-declared/generated-binary callback-template destructor support. Do not hand-write a C++ destructor body; route it through [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) the same way the other compiler-emitted FunctionObject callback wrappers are routed.
- Required action: update the target page and generated/coverage rows only after a normal metadata refresh. Also repair wording in the related FunctionObject docs so `0x0049b090` is not described as the base `FunctionObject` vtable's own destructor slot; the base vtable uses the sibling `0x0049b250` body.
- Confidence: high for the routing recommendation (`0.86`). The exact binary facts are stronger than the final original header spelling, which remains inferred.

## Supporting Research

## Target

- Target UID: `000123`.
- Target path: `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, currently:

```markdown
| [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |  |
```

- Tracker: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row for `000123`, assigned to Agent-B001 on 2026-06-13.
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.

## Executive Recommendation

The best direct route is [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md), not [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) and not any feature module that constructs one of the callback objects.

IDA shows that `0x0049b090` is installed in four concrete callback-template vtables for 24-byte callback objects. It is not referenced by the base `FunctionObject::vftable`; the base vtable references the sibling body at `0x0049b250`. The `0x0049b090` function writes `FunctionObject::vftable` because it is tearing down a derived callback-template object and then entering base destruction. That write is base-destruction behavior, not proof that [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) is the narrow direct owner of this exact folded wrapper.

This item should stay reconstructable because the original source needs the shared callback-template declarations and virtual destructor semantics. It should not become `RECONSTRUCTABLE:FALSE`; that would be inconsistent with the existing source-declared/generated-binary model used for `FunctionObjects` callback wrappers. The generated C++ block should remain blank.

## Supervisor Active Recheck

- The supervisor assignment requested one B001 research report for UID `000123`.
- This was not a split-execution target. C001 already split the old sparse `0x0049b090-0x0049b28e` range into exact children `000123` and `0003LP`, with intervening mixed destructor-band ownership excluded.
- No by-* documentation, tracker, auto-generated file, or coverage report was edited by B001 in this pass. The exact row text below is for supervisor/A-agent application.

## Inference Research Guidance Check

- `by-structure.md` separates semantic ownership from emitter routing. It also allows source-declared/generated-binary pages where the source declaration is required but exact bytes should be produced by the compiler/linker.
- The prior docs were treated as useful leads, not authoritative proof. They correctly identify `FunctionObjects` as the source family and correctly keep feature construction sites separate. They are less precise where they describe both `0x0049b090` and `0x0049b250` as base `FunctionObject` destructor bodies.
- Fact: the target function is vtable-only referenced by callback-template vtables.
- Inference: the body is a compiler-emitted/folded scalar deleting destructor for 24-byte callback-template objects generated from the `FunctionObjects` template family.

## Evidence Standards Used

Evidence used:

- IDA MCP `server_health`, `lookup_funcs`, `decompile`, `disasm`, `callees`, `analyze_component`, `xrefs_to`, `entity_query`, `get_int`, and `get_bytes`.
- Exact function starts/ends, padding bytes, vtable slot values, constructor stores, callee set, no ordinary code xrefs, and sibling destructor comparison.
- Documentation evidence from `by-memory`, `by-class`, `by-file`, `by-type`, `by-meta`, `by-project-structure`, generated coverage, and the no-owner tracker.

The evidence is strong enough to recommend a metadata repair because independent signals agree: vtable data refs, concrete callback vtable names, 24-byte object-size slot, 24-byte delete-path constant, feature constructor stores, and existing `FunctionObjects` routing policy all point to shared callback-template support.

## IDA MCP Facts

Function/range facts:

- `lookup_funcs` reports `0x0049b090` as `sub_49B090`, size `0x3e`; `0x0049b0ce` is not a function start.
- Neighbor bytes are padding: `0x0049b087-0x0049b090` is `0xcc` padding and `0x0049b0ce-0x0049b0d0` is `0xcc` padding.
- Sibling `0x0049b250` is also a real `0x3e` byte function; `0x0049b28e` is not a function start.

Decompile/disassembly facts:

- `sub_49B090` stores `FunctionObject::vftable`, calls `sub_4F4A90`, tests scalar deleting flags, conditionally calls `sub_4F4AC0`, and otherwise returns `this`.
- `sub_4F4A90` stores `LObject::vftable`, consistent with base cleanup.
- `sub_4F4AC0` calls allocator/free helpers and returns.
- The `0x0049b090` guard/no-op path pushes `0x18`; the sibling `0x0049b250` path pushes `0x04`. This matches a 24-byte callback-template object body versus a small base `FunctionObject` body.
- `0x004673f0` decompiles to `return 24`, and it appears as the tail helper/size slot in the same callback vtables that use `0x0049b090`.

Xref and vtable facts:

- `xrefs_to 0x0049b090` returns only four data refs: `0x006187e8`, `0x0061a3b0`, `0x00620184`, and `0x0062dde8`.
- `xrefs_to 0x0049b250` returns the base `FunctionObject::vftable` cell at `0x006186a8`.
- `entity_query` names the `0x0049b090` refs as callback-template vtables:
  - `0x006187e8`: `PlainMemberFunctionObject<PopupMenuControlPane,long>`.
  - `0x0061a3b0`: `DoubleParamMemberFunctionObject<MixItemDialog,...>`.
  - `0x00620184`: `PlainMemberFunctionObject<NexonclubRegistrationDialog,ulong>`.
  - `0x0062dde8`: `PlainMemberFunctionObject<TerminalPane,ulong>`.
- The callback vtable slots are consistent:
  - slot 0 `0x0049b090`;
  - slot 1 `0x004f4b10`;
  - slot 2 `0x0041b6c0`;
  - invoke slot varies by callback, for example `0x004b0880` for MixItemDialog and `0x0049af00` for PopupMenu/Nexonclub/Terminal-style plain member wrappers;
  - tail size/helper slot `0x004673f0`.

Constructor-store facts:

- `xrefs_to 0x006187e8` reports construction store `0x004980bc` in `sub_498040`; decompilation line installs `PlainMemberFunctionObject<PopupMenuControlPane,long>::vftable`.
- `xrefs_to 0x0061a3b0` reports construction stores `0x004afd62` in `sub_4AFCC0` and `0x004b0370` in `sub_4B0120`; decompilation installs the `DoubleParamMemberFunctionObject<MixItemDialog,...>::vftable`.
- `xrefs_to 0x00620184` reports construction store `0x00530189` in `sub_530060`; decompilation installs the `PlainMemberFunctionObject<NexonclubRegistrationDialog,ulong>::vftable`.
- `xrefs_to 0x0062dde8` reports construction store `0x0058b567` in `sub_58B470`; decompilation installs the `PlainMemberFunctionObject<TerminalPane,ulong>::vftable`.

Negative IDA facts:

- No ordinary code caller was found for `0x0049b090`; reachability is through vtable data refs.
- The base `FunctionObject::vftable` does not point to `0x0049b090`; it points to `0x0049b250`.
- The concrete feature constructors store callback-object vtables, not a function pointer to this destructor directly.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049b090-0x0049b0ce` | `000123` / target page | 24-byte callback-template scalar deleting destructor body reused by multiple FunctionObjects callback vtables | TRUE | recommend `0000JO` | recommend `85/88+` | assign/reroute after doc repair |
| `0x0049b250-0x0049b28e` | `0003LP` | base `FunctionObject::vftable` scalar deleting destructor body | TRUE | unresolved; likely `00005K` after FunctionObject class repair | `84/88` | keep as separate sibling |
| `0x0049b0ce-0x0049b250` | mixed intervening span | padding and unrelated control/EPF destructors | mixed | multiple | n/a | already split away from target |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049b090` | data refs from `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8` | shared callback-template destructor slot |
| `0x0049b250` | data ref from `0x006186a8` | base `FunctionObject::vftable` destructor slot |
| `0x0061a3b0` | stores from `0x004afd62` and `0x004b0370` | MixItemDialog callback object construction |
| `0x00620184` | store from `0x00530189` | NexonclubRegistrationDialog callback object construction |
| `0x0062dde8` | store from `0x0058b567` | TerminalPane callback object construction |
| `0x006187e8` | store from `0x004980bc` | PopupMenuControlPane callback object construction |
| `sub_4F4A90` | callee of both destructor bodies | LObject base cleanup |
| `sub_4F4AC0` | callee of both destructor bodies | heap/free helper on scalar-delete flags |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) defines the shared callback utility family, including `FunctionObject`, `PlainMemberFunctionObject*`, and `DoubleParamMemberFunctionObject*` support. It says feature modules own construction sites, while FunctionObjects owns reusable declarations and emitted support.
- [UID:0001WQ][FunctionObjectTemplates](../../../../../by-type/by-template/FunctionObjectTemplates.md) describes source-declared/generated-binary callback-template support and rejects standalone source files for each long compiler-template name.
- [UID:0001Q9][client_callback_dispatch](../../../../../by-meta/client_callback_dispatch.md) says base destructors and callback-template wrappers are shared utility support, with construction sites kept in feature modules.
- [UID:0003IH][MixItemDialogDoubleParamCallbackVtable](../../../../../by-type/by-vtable/MixItemDialogDoubleParamCallbackVtable.md) documents `0x0061a3b0 -> 0x0049b090` as a callback-template destructor/base support slot and records construction stores.
- [UID:00011Y][ButtonChoiceControlDestructors](../../../../../by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) correctly treats `0x0049b090-0x0049b0ce` as a separate FunctionObject-style wrapper inside a mixed destructor/thunk band, not a button/control-pane source body.

Existing docs that need repair or precision:

- [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) currently lists both `0x0049b090` and `0x0049b250` as `FunctionObject` scalar deleting destructors. IDA now separates them more sharply: `0x0049b250` is the base vtable slot, while `0x0049b090` is a 24-byte callback-template deleting destructor that enters `FunctionObject` base cleanup.
- The target page says the owner interpretation is high-confidence but blocked by the `FunctionObject` class score. That gate explanation was reasonable under the older base-destructor framing, but the current vtable evidence supports routing this exact callback destructor through [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md), matching other compiler-emitted callback-template glue such as [UID:00014W][MixItemDialogDoubleParamCallback](../../../../../by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md).

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently marks UID `000123` as `no-owner`, `CANONICAL_OWNER:NONE`, blank emitters.
- `by-memory/-coverage-report.md` currently lists it as reconstructable `84% : strong`, with the strict parent-gate block documented.

## Ranked Ownership Analysis

### 1. [UID:0000JO] FunctionObjects

- Evidence for:
  - Existing file doc owns shared callback-object declarations and emitted support.
  - IDA xrefs tie `0x0049b090` to multiple `PlainMemberFunctionObject` / `DoubleParamMemberFunctionObject` vtables rather than to a single feature class.
  - Existing emitted callback wrapper pages, for example UID `00014W`, already use `CANONICAL_OWNER:0000JO` and `EMITTER_UIDS:0000JO` for compiler-emitted FunctionObjects glue with blank final C++.
  - `0000JO` currently clears the parent route threshold at `87/85`.
- Evidence against:
  - The exact original source may have been header-only `FunctionObjects.h` rather than a real `FunctionObjects.cpp`. This is already acknowledged by the file doc and proposed source tree.
  - The machine code is compiler-generated and may be COMDAT/folded, so the generated source should not contain a hand-authored function body.
- Decision:
  - Accept. Use `0000JO` as both canonical owner and emitter route, with blank reconstruction C++ and source-declared/generated-binary handling.

### 2. [UID:00005K] FunctionObject

- Evidence for:
  - `sub_49B090` writes `FunctionObject::vftable` and calls the `LObject` base cleanup helper.
  - Existing target/class docs currently use [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) as the related class.
- Evidence against:
  - The base `FunctionObject::vftable` xref points to sibling `0x0049b250`, not to `0x0049b090`.
  - The `0x0049b090` vtable refs are all concrete callback-template vtables for 24-byte objects.
  - The size/helper slot `0x004673f0` returns `24`, and `0x0049b090` pushes `0x18` on the delete/no-op path. The sibling base body pushes `0x04`.
  - [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) is still `80/82`, below the strict direct-parent gate.
- Decision:
  - Reject as the direct owner for UID `000123`. Keep it as an important base-class relationship and repair its wording. If a future agent handles sibling `0003LP`, `00005K` is the better direct candidate for that sibling after class-page score repair.

### 3. Concrete callback-template class pages

- Candidates:
  - `PlainMemberFunctionObject<PopupMenuControlPane,long>` / UID `0000AK`.
  - `DoubleParamMemberFunctionObject<MixItemDialog,...>` / UID `000041`.
  - The concrete NexonclubRegistrationDialog and TerminalPane plain-member callback instantiations.
- Evidence for:
  - Their vtables point at `0x0049b090`.
  - Their constructors write the vtable addresses into 24-byte callback objects.
- Evidence against:
  - No single concrete class owns all four observed uses.
  - The function body is identical shared destructor support rather than a concrete callback target method.
  - Routing to one concrete class would be arbitrary; routing to all concrete classes would duplicate compiler-generated glue and imply multiple handwritten source bodies.
- Decision:
  - Reject as canonical owner and reject as emitters. Keep as consumer/vtable evidence.

### 4. Feature modules: PopupMenuControls, ItemDialogs/MixItemDialog, NexonclubRegistrationDialog, TerminalPane

- Evidence for:
  - Feature constructors allocate/configure callback objects and store the vtables.
- Evidence against:
  - These modules own construction semantics, callback targets, and UI workflow, not the reusable callback-template destructor.
  - Consumer/write xrefs to vtables do not make the feature file the owner of shared template destructor code.
- Decision:
  - Reject.

### 5. [UID:0001WQ] FunctionObjectTemplates

- Evidence for:
  - It is the closest conceptual template-family doc.
- Evidence against:
  - It is a by-type summary owned by `0000JO`, scored `82/88`, and is not the established generated source root.
  - Existing generated rows route comparable exact callback glue directly to `0000JO`.
- Decision:
  - Use as supporting evidence, not canonical owner/emitter.

### 6. Keep `CANONICAL_OWNER:NONE`

- Evidence for:
  - The body is compiler-generated and likely folded across multiple callback-template instantiations.
  - Current metadata is no-owner and has a historical parent-gate explanation.
- Evidence against:
  - B001 should not leave no-owner when the best existing source-family owner is supported.
  - The project already has a stable shared owner for this family: [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md).
  - This is not a pooled literal/shared constant that needs `NONE` with multiple emitters; it is generated callback-template support with one source-family owner.
- Decision:
  - Reject as the final state. `NONE` was understandable as a temporary gate artifact, but the better route is `0000JO`.

### 7. Reclassify to `RECONSTRUCTABLE:FALSE`

- Evidence for:
  - The exact machine body is compiler-generated and should not be hand-emitted.
- Evidence against:
  - `by-structure.md` explicitly supports `source-declared/generated-binary` pages where source declarations are required but exact bytes are compiler/linker output.
  - Existing FunctionObjects destructor/wrapper pages use `RECONSTRUCTABLE:TRUE` with blank C++ for this same pattern.
  - Setting only this one target to `FALSE` would make it inconsistent with sibling and template-support pages without a project-wide policy change.
- Decision:
  - Reject. Keep `RECONSTRUCTABLE:TRUE`; leave C++ blank.

## Proposed New File/Grouping

No new file or grouping is needed. [UID:0000JO][FunctionObjects](../../../../../by-file/FunctionObjects.md) already covers the likely original source family:

- `util/FunctionObjects.h` for the callback-object declarations/templates.
- Optional `util/FunctionObjects.cpp` placeholder for emitted/base support in generated documentation.
- Existing related items include UID `00014W`, UID `0001CQ`, UID `0001CS`, UID `000327`, UID `000328`, UID `000324`, UID `00032C`, and callback vtable data pages.

This target is not standalone. It belongs to the broad FunctionObjects callback-template family, while feature-specific construction sites remain in their feature modules.

## Negative Evidence Summary

- Nearby address clustering in the button/control destructor band does not prove ButtonControlPane ownership. The aggregate page documents this as a mixed compiler/destructor neighborhood.
- Concrete feature constructor stores do not prove feature ownership of the destructor body. They only prove which callbacks instantiate/use the shared vtable.
- `FunctionObject::vftable` write inside `sub_49B090` is not enough to make [UID:00005K][FunctionObject](../../../../../by-class/FunctionObject.md) the direct owner; derived destructors commonly reset the vptr to the base during teardown.
- A no-owner with multiple `EMITTER_UIDS` is not justified. There is one shared source-family route, not independent source-use contexts that must each emit this exact helper.
- A new source file is not justified. The existing FunctionObjects module already models the template family and is referenced by the proposed source tree.

## Final Recommendation

Recommended target metadata after documentation repair:

```text
COMPLETION:85
CONFIDENCE:88 or 89
CANONICAL_OWNER:0000JO
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JO
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Exact `auto-generated/-ag-memory-coverage.md` row expected after metadata refresh:

```markdown
| [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) | emits | `0000JO` | `0000JO` |  | no | `auto-generated/NexusTK/util/FunctionObjects.cpp` | `by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md` |  |
```

Exact `by-memory/-coverage-report.md` row recommended for supervisor placement. Replace the current UID `000123` row at the existing position between UID `000122` and UID `0002XW`:

```markdown
    - [UID:000123][0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor](by-memory/0x0049b090-0x0049b0ce.FunctionObjectCallbackScalarDeletingDestructor.md) 0x0049b090-0x0049b0ce | destructor support | FunctionObjectCallbackScalarDeletingDestructor : reconstructable : 85% : strong : Exact compiler-emitted 24-byte FunctionObjects callback-template scalar deleting destructor reused by PopupMenu, MixItemDialog, NexonclubRegistrationDialog, and TerminalPane callback vtables; source-declared/generated-binary under FunctionObjects, with the base FunctionObject destructor sibling at 0x0049b250 kept separate and no feature-owner emitter.
```

Recommended documentation wording repairs outside B001 scope:

- Target page: replace the strict `FunctionObject` class parent-gate explanation with FunctionObjects source-family routing and add the base-vs-callback distinction.
- FunctionObject class page: keep UID `000123` as related support evidence, but do not list it as the base vtable's own scalar deleting destructor. Reserve that role for sibling UID `0003LP`.
- FunctionObjects file and FunctionObjectTemplates docs: mention UID `000123` as shared 24-byte callback-template scalar deleting destructor support.
- Client callback dispatch: clarify that UID `000123` is callback-template destructor support, while UID `0003LP` is the base `FunctionObject` vtable destructor support.

## Follow-Up Actions

Supervisor actions:

- Apply or assign the metadata repair for UID `000123`.
- Refresh generated reports with the normal project tool flow, not dry-run validation.
- Apply the exact coverage row above if the refresh does not update it automatically.

A-agent actions:

- Update the target page, FunctionObject class page, FunctionObjects file page, and callback dispatch wording as described.
- Re-run normal validator/report refresh for the changed docs and record commands/results.

B001 future research actions:

- If assigned, research sibling UID `0003LP` separately. It likely has a different direct-owner answer because it is the actual `FunctionObject::vftable` destructor slot.

## Confidence

- Recommendation confidence: high (`0.86`).
- Score confidence: `85/88` is justified once the new vtable-owner distinction is added to the target page. Raising confidence to `89` would also be defensible, but `88` is already strong and avoids overinflating final original-header certainty.
- Remaining uncertainty: exact original header/source spelling (`FunctionObjects.h` versus another callback utility header) and whether the linker folded several template destructors into this one body. Neither uncertainty changes the recommended `0000JO` route under the current model.

## Validator Results

- IDA MCP validation/research commands run:
  - `server_health` for session `b001_0003lq`: healthy, `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs` for `0x0049b090`, `0x0049b0ce`, `0x0049b0d0`, `0x0049b250`, `0x0049b28e`, `0x0049b290`, `0x0049af00`, `0x004f4a90`, `0x004f4ac0`, `0x004f4b10`.
  - `decompile` / `disasm` for `0x0049b090` and `0x0049b250`.
  - `callees` and `analyze_component` for `0x0049b090` and `0x0049b250`.
  - `xrefs_to` for `0x0049b090`, `0x0049b250`, and vtable bases `0x006187e8`, `0x0061a3b0`, `0x00620184`, `0x0062dde8`, `0x006186a8`.
  - `entity_query` around the callback/base vtable name ranges.
  - `get_int` for callback/base vtable slots.
  - `decompile` for `0x004673f0`, `0x0041b6c0`, `0x004f4a90`, `0x004f4ac0`, and `0x004f4b10`.
- Normal documentation validator was not run because B001 changed only this research report and did not edit validator-managed by-* metadata files.
- Dry-run validator and memory-range modes were not used.
- No unresolved tool blocker.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/000123-FunctionObjectCallbackScalarDeletingDestructor.md`
- Modified:
  - none
- Renamed:
  - none
- Moved to executed:
  - none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000123-FunctionObjectCallbackScalarDeletingDestructor.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000123"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
