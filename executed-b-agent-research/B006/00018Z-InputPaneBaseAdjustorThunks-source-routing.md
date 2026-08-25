** TARGET-REPORT-UID:00018Z **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018Z InputPaneBaseAdjustorThunks Source Routing Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00018Z] as a non-reconstructable compiler-generated MSVC this-adjustor thunk island. Do not attach it to a source owner, do not emit C++, and do not split it into source-bearing children.
- Required action: repair the documented half-open range from `0x004f2e59-0x004f2e9a` to `0x004f2e59-0x004f2e9b`. The six thunk starts are each `0x0b` bytes, so the last thunk at `0x004f2e90` includes byte `0x004f2e9a` and ends at exclusive address `0x004f2e9b`.
- Final disposition after accepted implementation: `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP`.
- Source route: the source-facing declarations belong to the reusable input-pane class family in [UID:0000K7][InputPanes](../../../../../by-file/InputPanes.md), with vtable/declaration handling anchored by [UID:0001XS][InputPaneBaseVtableFamily](../../../../../by-type/by-vtable/InputPaneBaseVtableFamily.md). The thunk bytes themselves are generated from the secondary/tertiary base layout and scalar deleting destructors.
- Confidence: high. The only material repair is the off-by-one endpoint in the current filename/prose/coverage row.

## Target

- Target UID: `00018Z`
- Current target path: `source-3/project-documentation/by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md`
- Recommended target path after implementation: `source-3/project-documentation/by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00018Z-InputPaneBaseAdjustorThunks-source-routing.md`
- Current metadata: `84/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters and C++.
- Current coverage row: nested under [UID:00018X][InputPaneBases](../../../../../by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) at line 2002 of `by-memory/-coverage-report.md`, using the stale end `0x004f2e9a`.
- Assignment: B006 report-only source-routing audit for exact thunk boundaries, vtable-owner mapping, source destructor/inheritance route, scalar deleting destructor targets, support-doc gaps, generated-name pollution, score cap, coverage text, and no-code proof.

## Executive Recommendation

Use one non-emitting memory page for the six contiguous thunks, but correct its range to half-open `0x004f2e59-0x004f2e9b`.

The source-facing class and destructor shape should be documented in the class/vtable pages, not in this memory page's `RECONSTRUCTION_CPP` block:

- `LineInputPane` has the real complete destructor at `0x004f2dd0-0x004f2e59` and the shared scalar deleting destructor at `0x004f2ea0-0x004f2f63`.
- `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` reuse the `LineInputPane` scalar deleting destructor entries for this vtable family; no custom destructor thunk/body should be invented for them.
- `CharInputPane` has the scalar deleting destructor at `0x004f2f70-0x004f2fab`.
- `ConfirmInputPane` has a complete destructor at `0x004f29d0-0x004f2a05` and the scalar deleting destructor at `0x004f2fb0-0x004f3017`.
- Secondary views use `-0xa0` adjustors; tertiary views use `-0xa4` adjustors.

Do not model the six functions as source methods such as `virt_meth_0x4f2e59`. The best descriptive names are ABI labels:

- `LineInputPaneFamilySecondaryScalarDeletingDestructorAdjustorThunk`
- `LineInputPaneFamilyTertiaryScalarDeletingDestructorAdjustorThunk`
- `CharInputPaneSecondaryScalarDeletingDestructorAdjustorThunk`
- `CharInputPaneTertiaryScalarDeletingDestructorAdjustorThunk`
- `ConfirmInputPaneSecondaryScalarDeletingDestructorAdjustorThunk`
- `ConfirmInputPaneTertiaryScalarDeletingDestructorAdjustorThunk`

These labels are descriptive for IDA/docs only, not original source names.

## Supervisor Active Recheck

- This was a report-only assignment. I did not edit by-* docs and did not edit `by-memory/-coverage-report.md`.
- The target does not need source-bearing split repair. The exact children would be six `0x0b` compiler thunks with no independent source-authored behavior, so splitting would increase bookkeeping without improving reconstruction.
- One range repair is needed: rename/update the target and all support references from current half-open-looking `0x004f2e59-0x004f2e9a` to true half-open `0x004f2e59-0x004f2e9b`.

## Inference Research Guidance Check

- Direct facts used: exported IDA function JSON for `0x004f2e59`, `0x004f2e64`, `0x004f2e6f`, `0x004f2e7a`, `0x004f2e85`, `0x004f2e90`, scalar destructor target pages, vtable data/family pages, and current coverage rows.
- Documentation evidence used as leads: B001-042 executed report and current `InputPaneBases`, class, file, vtable, ignored-ledger, and scalar destructor pages.
- Inference used: source-facing class/destructor roles where the binary shows vtable reuse but cannot prove exact original C++ declarations. Those inferences are marked as likely/descriptive, not original-source proof.
- Rejected generated evidence: Ghidra/OOAnalyzer names such as `virt_meth_0x4f2e59` and decompiler-shaped class methods are data pollution for this target. They point to vtable slots, not handwritten source methods.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Exact range | Exported IDA sizes show six functions of `0x0b` bytes at starts `0x004f2e59`, `0x004f2e64`, `0x004f2e6f`, `0x004f2e7a`, `0x004f2e85`, `0x004f2e90`. `0x004f2e90 + 0x0b = 0x004f2e9b`; scalar target starts at `0x004f2ea0`. | Rename/update to `0x004f2e59-0x004f2e9b`; padding is `0x004f2e9b-0x004f2ea0`. | Current `0x004f2e59-0x004f2e9a` under-ranges the final thunk by one byte if interpreted half-open and causes the aggregate padding map to treat byte `0x004f2e9a` as padding. |
| Source status | Each body is only adjusted `this` plus tail jump. Inbound refs are vtable data offsets only. | Compiler/linker-generated adjustor thunks; `RECONSTRUCTABLE:FALSE`. | Rejected source method pages or C++ thunk functions; source should express normal virtual destructors/classes. |
| Vtable-owner mapping | `InputPaneBaseVtableFamily`, `InputPaneBaseVtableData`, and master vtable export map the thunk starts into secondary/tertiary destructor slots. | Owner context is the reusable input-pane vtable family in `InputPanes.cpp`, but the thunk memory page itself keeps `CANONICAL_OWNER:NONE`. | Rejected assigning to [UID:0000K7] or [UID:0001XS] because that would imply source ownership of generated glue; those pages own the declarations that cause the compiler to emit this glue. |
| Scalar destructor targets | Target pages [UID:00036E], [UID:00036F], [UID:00036G] document the three scalar deleting destructors and their class owners. | Tail targets are `LineInputPane` family, `CharInputPane`, and `ConfirmInputPane` scalar deleting destructors. | Rejected treating every class with a vtable ref as having an independent destructor body inside this range. |
| Number/Args/MultiLine destructor role | Vtable slots for `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` point to the same two LineInputPane-family adjustors. | Likely no source-authored custom destructor for those derived variants in this cluster; source relies on base cleanup or compiler-folded/default derived destructor behavior. | Rejected adding destructor C++ bodies for those classes from this thunk range. |
| Generated-name pollution | Exported data labels the thunks as `sub_4F2E59` in IDA and `virt_meth_0x4f2e59` in Ghidra/OOAnalyzer, with Ghidra decompilation styling them as source-like virtual methods. | Use descriptive ABI labels only; do not propagate `virt_meth_*` or raw `sub_*` into source-facing docs except as search aliases. | Rejected generated virtual method names in class method inventories and final output. |
| Split model | All six functions are contiguous, uniform, compiler-generated, and share one vtable-family source route. | Keep one non-emitting thunk island page; optionally document each thunk in a table after the endpoint repair. | Rejected per-thunk child pages and class-owned splits because no child is source-authored. |
| First-draft C++ readiness | `RECONSTRUCTABLE:FALSE`; no source-authored behavior in the range. | Keep formal C++ blank. Class/vtable pages may eventually hold class declaration drafts; this target should not. | Rejected adding `[[CHILDREN]]`, comments, or source declarations to this memory range. |
| Score cap | Evidence is strong but not final-audit raw-byte complete in the target page today; source declarations still live elsewhere. | After endpoint/support repair, `86/92` is justified. Cap below `90/94` unless raw bytes/disassembly and every support ref are written into the page. | Rejected `95+`; compiler-generated pages still need exact written evidence and should not be treated as final-source code. |

## Evidence Standards Used

- Exported IDA facts from `resources/exported_data/functions/*.json`: function start, IDA size, decompiled one-liners, xrefs-to, xrefs-from.
- Vtable evidence from [UID:0001XS][InputPaneBaseVtableFamily](../../../../../by-type/by-vtable/InputPaneBaseVtableFamily.md), [UID:000389][InputPaneBaseVtableData](../../../../../by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md), and `resources/exported_data/master_vtables.json`.
- Source-family evidence from [UID:0000K7][InputPanes](../../../../../by-file/InputPanes.md) and class pages for [UID:000077], [UID:00009L], [UID:00001P], [UID:000035], [UID:00001O], [UID:00009J], and [UID:00008T].
- Previous research evidence from `Agent-B001/research/executed/older/00018X-InputPaneBases.md`, rechecked against current docs and exports.
- Negative evidence: no ordinary code callers in the exported xrefs; only vtable data refs into the thunk starts and tail-jump refs out to scalar deleting destructors.

## IDA / Export Facts

### Function and Boundary Facts

| Start | True half-open range | Exported IDA size | IDA decompile summary | Tail target |
| --- | --- | --- | --- | --- |
| `0x004f2e59` | `0x004f2e59-0x004f2e64` | `0x0b` | `return sub_4F2EA0(this - 40, flags);` | `0x004f2ea0` |
| `0x004f2e64` | `0x004f2e64-0x004f2e6f` | `0x0b` | `return sub_4F2EA0(this - 41, flags);` | `0x004f2ea0` |
| `0x004f2e6f` | `0x004f2e6f-0x004f2e7a` | `0x0b` | `return sub_4F2F70(this - 40, flags);` | `0x004f2f70` |
| `0x004f2e7a` | `0x004f2e7a-0x004f2e85` | `0x0b` | `return sub_4F2F70(this - 41, flags);` | `0x004f2f70` |
| `0x004f2e85` | `0x004f2e85-0x004f2e90` | `0x0b` | `return sub_4F2FB0(this - 40, flags);` | `0x004f2fb0` |
| `0x004f2e90` | `0x004f2e90-0x004f2e9b` | `0x0b` | `return sub_4F2FB0(this - 41, flags);` | `0x004f2fb0` |

`this - 40` is a `_DWORD *` decompiler rendering of `sub ecx, 0xa0`; `this - 41` is `sub ecx, 0xa4`. The target range should therefore include all bytes through address `0x004f2e9a` and use exclusive end `0x004f2e9b`.

Adjacent facts:

- Predecessor [UID:00036D] `0x004f2dd0-0x004f2e59` is the `LineInputPane` complete/non-deleting destructor and ends exactly where the first thunk begins.
- Successor [UID:00036E] `0x004f2ea0-0x004f2f63` starts the shared `LineInputPane` scalar deleting destructor.
- Padding between the final thunk and successor scalar destructor is `0x004f2e9b-0x004f2ea0`, five bytes. Current support prose that says `0x004f2e9a-0x004f2ea0` should be corrected.

### Direct Vtable / Xref Inventory

| Thunk | Adjust | Vtable refs | Source-facing owners of those vtable views |
| --- | --- | --- | --- |
| `0x004f2e59` | `-0xa0` | `0x0061caa8`, `0x0061cb34`, `0x0061ccd8`, `0x0061cd64`, `0x0061cdf0` | `LineInputPane`, `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, `MultiLineInputPane` secondary views |
| `0x004f2e64` | `-0xa4` | `0x0061cad8`, `0x0061cb64`, `0x0061cd08`, `0x0061cd94`, `0x0061ce20` | Same family tertiary views |
| `0x004f2e6f` | `-0xa0` | `0x0061cbc0` | `CharInputPane` secondary view |
| `0x004f2e7a` | `-0xa4` | `0x0061cbf0` | `CharInputPane` tertiary view |
| `0x004f2e85` | `-0xa0` | `0x0061cc4c` | `ConfirmInputPane` secondary view |
| `0x004f2e90` | `-0xa4` | `0x0061cc7c` | `ConfirmInputPane` tertiary view |

No ordinary code caller was found in the exported xrefs. Each thunk has exactly one outgoing `JUMP_NEAR` to its scalar deleting destructor target.

## Function / Child Inventory

| Range / Item | Role | Source ownership decision | Reconstructable | Score recommendation |
| --- | --- | --- | --- | --- |
| `0x004f2e59-0x004f2e9b` [UID:00018Z] | Six compiler-generated secondary/tertiary scalar deleting destructor adjustor thunks | No canonical owner; generated from `InputPanes.cpp` class/vtable declarations | `FALSE` | `86/92` |
| `0x004f2e59-0x004f2e64` | LineInputPane-family secondary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |
| `0x004f2e64-0x004f2e6f` | LineInputPane-family tertiary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |
| `0x004f2e6f-0x004f2e7a` | CharInputPane secondary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |
| `0x004f2e7a-0x004f2e85` | CharInputPane tertiary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |
| `0x004f2e85-0x004f2e90` | ConfirmInputPane secondary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |
| `0x004f2e90-0x004f2e9b` | ConfirmInputPane tertiary adjustor | Descriptive ABI subentry only | `FALSE` | no child page |

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` for this memory page

- Evidence for: thunks are generated ABI glue; inbound refs are vtable data only; no source-authored behavior or object state lives inside the range.
- Evidence against: the vtables and classes that cause the thunks are confidently in [UID:0000K7][InputPanes](../../../../../by-file/InputPanes.md), so there is a strong source-generation route.
- Decision: accepted. Source-generation context is documented in support pages, but the thunk memory page itself should remain ownerless/non-emitting.

### 2. Assign to [UID:0001XS] `InputPaneBaseVtableFamily`

- Evidence for: all vtable refs are in that family, and the page describes exactly these secondary/tertiary destructor slots.
- Evidence against: [UID:0001XS] is the source-declared/generated-binary vtable-family declaration anchor, not the owner of executable compiler glue in `.text`.
- Decision: rejected for `CANONICAL_OWNER`; use it as support/source route only.

### 3. Assign to [UID:0000K7] `InputPanes`

- Evidence for: the source declarations for the classes live there, and the file is the final source route for class declarations.
- Evidence against: assigning the thunk page to the file would risk generated-output pollution and suggest explicit source functions should be emitted.
- Decision: rejected for this memory page; keep `InputPanes` as "replacement/source route" in prose and ignored ledger.

### 4. Split/assign to individual classes

- Evidence for: each thunk maps to specific class vtable views.
- Evidence against: no thunk contains class-specific source behavior; the LineInputPane-family thunks are reused by five class views; the target is contiguous, uniform, and non-source.
- Decision: rejected. Keep a single thunk island with an internal table.

## Negative Evidence Summary

- Direct callers are absent. The exported `xrefs_to` for all six starts are `DATA_OFFSET` refs from `.rdata` vtable slots, not `CALL_NEAR` or ordinary branch callers.
- The `is_thunk` flag in the cached IDA export is false, but the bodies and vtable-only use prove the semantic thunk role. Do not let a missing IDA flag override the instruction pattern.
- Ghidra class/method names are misleading here. The export shows names like `virt_meth_0x4f2e59` and class-oriented signatures, but the IDA decompiler reduces each function to an adjusted tail call.
- The current target filename and coverage row look exact but are one byte short under the prevailing half-open range convention. This should cap the current page until repaired.

## No-Code Proof

This target should not receive `RECONSTRUCTION_CPP CODE`.

Target-specific proof:

1. The page is `RECONSTRUCTABLE:FALSE`, and the recommended disposition preserves that state.
2. Every function body is an ABI-generated `this` adjustor plus tail jump to an already documented scalar deleting destructor.
3. Source C++ should express class declarations and virtual destructors in `InputPanes.cpp`; MSVC should regenerate secondary/tertiary adjustor thunks from inheritance layout.
4. Any explicit function such as `LineInputPaneFamilySecondaryScalarDeletingDestructorAdjustorThunk()` in source would be decompiler-shaped ABI glue and would pollute final output.
5. `[[CHILDREN]]` is also wrong because this exact memory page is not a source container; it is an ignored compiler artifact with no source-bearing children.

## Recommended Exact Doc / Support Changes

### Target [UID:00018Z]

1. Rename file:
   - from `by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md`
   - to `by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md`
2. Update header/title and every internal range table to true half-open ranges:
   - `0x004f2e59-0x004f2e64`
   - `0x004f2e64-0x004f2e6f`
   - `0x004f2e6f-0x004f2e7a`
   - `0x004f2e7a-0x004f2e85`
   - `0x004f2e85-0x004f2e90`
   - `0x004f2e90-0x004f2e9b`
3. Replace the current evidence bullet with: each thunk is `0x0b` bytes; the target range is `0x004f2e59-0x004f2e9b`; `0x004f2e9b-0x004f2ea0` is padding; `0x004f2ea0` begins [UID:00036E].
4. Add the direct vtable/xref table from this report.
5. Add the generated-name pollution/rejected alternatives section from this report.
6. Change metadata to `COMPLETION:86`, `CONFIDENCE:92`; leave `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++.

### Support docs

- [UID:00018X] `InputPaneBases`: update the child inventory row to `0x004f2e59-0x004f2e9b`; fix the boundary/padding map from `0x004f2e9a-0x004f2ea0` to `0x004f2e9b-0x004f2ea0`; add the no-code/source-route rationale.
- [UID:0000K7] `InputPanes`: update the compiler artifact link/path and range; optionally add one sentence that `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` reuse the LineInputPane-family scalar deleting destructor slots rather than owning custom destructor bodies in this cluster.
- [UID:0001XS] `InputPaneBaseVtableFamily`: update the adjustor range to `0x004f2e59-0x004f2e9b`; replace legacy body wording such as `AUTOGEN_PARENT_UID` with current `CANONICAL_OWNER` / `EMITTER_UIDS` language when touched; add the six-thunk descriptive-name mapping.
- [UID:000389] `InputPaneBaseVtableData`: update the cross-reference path/range after rename; existing slot target table is otherwise correct.
- [UID:000077] `LineInputPane`: update method-map adjustor row to half-open `0x004f2e59-0x004f2e6f`; keep it described as compiler thunks.
- [UID:00001P] `CharInputPane`: update method-map adjustor row to `0x004f2e6f-0x004f2e85`.
- [UID:000035] `ConfirmInputPane`: update method-map adjustor row to `0x004f2e85-0x004f2e9b`.
- [UID:00009L] `NumberInputPane`, [UID:00001O] `CharArgsInputPane`, [UID:00009J] `NumberArgsInputPane`, [UID:00008T] `MultiLineInputPane`: add a short compiler-adjustor note/cross-reference because their secondary/tertiary destructor slots point into [UID:00018Z] via the LineInputPane-family thunks.
- `by-memory/-ignored.md`: update ignored range to `0x004f2e59-0x004f2e9b` and mention padding starts at `0x004f2e9b`.
- `wave3_data_issues.md` or the target page's data-caution section: keep/expand the note that generated `virt_meth_*` and source-like method inventories for these addresses are wrong for final source.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly during B-agent report mode. If the supervisor accepts the endpoint repair, replace the current nested row under [UID:00018X] with:

```markdown
        - [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md) 0x004f2e59-0x004f2e9b | compiler-thunk | InputPaneBaseAdjustorThunks : ignored/non-emitting : 86% : very strong : Six MSVC this-adjustor thunks, each `0x0b` bytes, subtract `0xa0` or `0xa4` from `ecx` and tail-jump to `LineInputPane`, `CharInputPane`, or `ConfirmInputPane` scalar deleting destructors; vtable-only refs, parent blank, non-reconstructable by design, and final padding begins at `0x004f2e9b`.
```

If the supervisor adds explicit internal padding rows inside the `InputPaneBases` aggregate, insert this optional row immediately after the [UID:00018Z] row and before [UID:00036E]:

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f2e9b-0x004f2ea0 | padding | InputPane adjustor-thunk to scalar destructor alignment : ignored : 100% : strong : Exported IDA sizes show the final `0x004f2e90` thunk ends at `0x004f2e9b`; remaining bytes are alignment before `0x004f2ea0`.
```

Do not use the optional padding row unless the supervisor wants internal padding rows for this aggregate; current report only requires the [UID:00018Z] row repair.

## IDA Rename / Type / Comment Recommendations

Recommended descriptive IDA names, confidence high for role but not original names:

| Address | Recommended descriptive label | Type/comment direction |
| --- | --- | --- |
| `0x004f2e59` | `LineInputPaneFamilySecondaryScalarDeletingDestructorAdjustorThunk` | `this` is secondary subobject pointer; subtract `0xa0`; tail-jump to `LineInputPane` scalar deleting destructor. |
| `0x004f2e64` | `LineInputPaneFamilyTertiaryScalarDeletingDestructorAdjustorThunk` | `this` is tertiary subobject pointer; subtract `0xa4`; tail-jump to `LineInputPane` scalar deleting destructor. |
| `0x004f2e6f` | `CharInputPaneSecondaryScalarDeletingDestructorAdjustorThunk` | subtract `0xa0`; tail-jump to `CharInputPane` scalar deleting destructor. |
| `0x004f2e7a` | `CharInputPaneTertiaryScalarDeletingDestructorAdjustorThunk` | subtract `0xa4`; tail-jump to `CharInputPane` scalar deleting destructor. |
| `0x004f2e85` | `ConfirmInputPaneSecondaryScalarDeletingDestructorAdjustorThunk` | subtract `0xa0`; tail-jump to `ConfirmInputPane` scalar deleting destructor. |
| `0x004f2e90` | `ConfirmInputPaneTertiaryScalarDeletingDestructorAdjustorThunk` | subtract `0xa4`; tail-jump to `ConfirmInputPane` scalar deleting destructor. |

Recommended common type if IDA typing is desired:

```c
void *__thiscall AdjustorScalarDeletingDestructorThunk(void *subobjectThis, unsigned int scalarDeleteFlags);
```

Use this only as an analysis signature. Do not put it in final reconstructed source.

## Validation Commands Needed After Accepted Implementation

Run after the target rename and support-doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md](00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Supervisor-owned coverage validation after applying the exact row:

> Executable block R002 was removed from this report and preserved verbatim in [00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md](00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Post-update searches:

> Executable block R003 was removed from this report and preserved verbatim in [00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md](00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

Ready for supervisor implementation callback.

Exact checklist for B006 if accepted:

1. Rename [UID:00018Z] to `0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md`.
2. Update [UID:00018Z] metadata to `86/92`; keep owner `NONE`, reconstructable `FALSE`, blank emitters, blank C++.
3. Replace target internal ranges/evidence with the corrected half-open ranges, vtable refs, generated-name caution, and no-code proof from this report.
4. Update support docs listed above, especially `InputPaneBases`, `InputPaneBaseVtableFamily`, `InputPaneBaseVtableData`, `InputPanes`, the seven class pages, and `by-memory/-ignored.md`.
5. Do not edit `by-memory/-coverage-report.md`; supervisor applies the exact replacement row above.
6. Run the scoped validators and post-update searches.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00018Z-InputPaneBaseAdjustorThunks-source-routing.md`
- Modified: none outside this report.
- Coverage edited: no.
- Target/support docs edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00018Z-InputPaneBaseAdjustorThunks-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00018Z"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018Z-InputPaneBaseAdjustorThunks-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00018Z-InputPaneBaseAdjustorThunks-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
