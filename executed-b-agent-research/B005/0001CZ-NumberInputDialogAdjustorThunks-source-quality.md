** TARGET-REPORT-UID:0001CZ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001CZ] NumberInputDialogAdjustorThunks Source-Quality Report

Agent: Agent-B005  
Task type: B-agent source-quality / heuristic research  
Target: `source-3/project-documentation/by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md`  
Required disposition: report-only. No target/support by-* docs edited. No coverage report edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep `0001CZ` non-reconstructable/ignored, but refresh it from support-level wording to a resolved class-ABI thunk page.
- Final disposition: compiler/linker-generated secondary/tertiary destructor adjustor thunks for [UID:00009K] `NumberInputDialog`; no `RECONSTRUCTION_CPP` body.
- Required action: update target metadata, target prose, stale generated-output wording, and the supervisor-owned coverage row.
- Confidence: very strong for range, thunk behavior, vtable refs, scalar deleting destructor target, no-code policy, and source replacement.

Recommended target metadata:

```yaml
COMPLETION: 86
CONFIDENCE: 92
CANONICAL_OWNER: 00009K
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

Recommended target C++: keep blank.

Rationale: the two functions are exact `0x0b` / decimal `11` byte adjustor thunks (Verified with `tools/int_convert.py`) that subtract `0xa0` / decimal `160` and `0xa4` / decimal `164` from `this` (Verified with `tools/int_convert.py`) before jumping to [UID:0001D0] `0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor`. They are class-owned ABI evidence, not handwritten source methods. The source replacement is the normal `NumberInputDialog` virtual destructor declaration and the ordinary destructor body at [UID:0001CX].

## Supporting Research

## Target

- Target UID: `0001CZ`
- Target path: `by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md`
- Current scores and metadata: `82/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
- Current coverage state: `by-memory/-coverage-report.md` already lists the page as ignored with exact `-0xa0/-0xa4`, vtable refs, scalar destructor code refs, padding, and stale generated-output rejections, but still at `82% : strong`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists `0001CZ` as `not_reconstructable`; `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp` contains constructor, ordinary destructor, and action-handler C++ and does not emit thunk source.

## Executive Recommendation

`0001CZ` should remain a no-code ignored page. The only metadata change I recommend is using [UID:00009K] `NumberInputDialog` as the canonical owner context, because these thunks are specific class ABI artifacts referenced from the class secondary and tertiary vtables. `EMITTER_UIDS` must stay blank because `RECONSTRUCTABLE:FALSE` pages should not emit C++.

This is not an unresolved source-placement blocker. Source placement is already resolved:

- Source module: [UID:0000M1] `NumberInputDialog`, projected to `NexusTK/ui/dialogs/NumberInputDialog.cpp`.
- Direct semantic class owner: [UID:00009K] `NumberInputDialog`.
- Source destructor body: [UID:0001CX] `NumberInputDialog::~NumberInputDialog()`.
- Generated scalar deleting destructor ABI target: [UID:0001D0] `0x00530c90-0x00530cf7`.
- This page: ignored secondary/tertiary destructor adjustor thunks.

If the supervisor prefers the older convention used by some ignored thunk pages, `CANONICAL_OWNER:NONE` can be retained; however, the current by-structure rules allow `RECONSTRUCTABLE:FALSE` pages to carry semantic ownership when useful, and the MapNamePane thunk precedent [UID:0003XL] uses its class owner. The best current source-quality recommendation is therefore `CANONICAL_OWNER:00009K`, no emitter.

## Supervisor Active Recheck

The user assigned this as a new report-only task after the finished `0001AN` report. I did not modify or archive `0001AN`, and I did not modify target/support docs or `by-memory/-coverage-report.md`.

The assignment asked for a recheck of:

- compiler-generated adjustor-thunk classification;
- exact no-code proof including `this - 0xa0`, `this - 0xa4`, vtable refs, scalar deleting destructor target, and stale generated-output corrections;
- support-doc implications for NumberInputDialog class/file/aggregate/scalar destructor;
- score/metadata recommendation;
- exact coverage replacement row.

All of those are addressed below. No by-structure split is needed because `0001CZ` already exactly covers the two adjacent thunk bodies and excludes the two-byte padding at `0x00530c8e-0x00530c90`.

## Inference Research Guidance Check

`by-structure.md` classifies adjustor thunks as `compiler/linker-generated`: document them for recognition and exclusion, but do not hand-port them as source. It also says `RECONSTRUCTABLE:FALSE` pages may keep a canonical owner when that owner documents semantic context, while emitters and C++ must remain blank.

`inference_research.md` supports ranking source ownership by xrefs, vtable relationships, constructor/destructor stores, adjacent range context, and disconfirming evidence. Here, the evidence is not just adjacency:

- vtable slots point directly at both thunks;
- both thunks jump into the class scalar deleting destructor;
- constructor, raw destructor, and scalar deleting destructor all store the same three NumberInputDialog vtable bases;
- the surrounding class/file docs are above gate and already accepted as the NumberInputDialog route.

Existing docs were treated as evidence, not authority. I rechecked the target, class, file, aggregate, raw destructor, scalar deleting destructor, vtable data, generated output, coverage row, and executed B002 report. Current IDA MCP was unavailable, so this report relies on the already-written live-IDA-backed evidence in those docs.

## Heuristic / Inference Reanalysis And Validation

### Adjustor-thunk classification

Best inference: confirmed compiler-generated multiple-inheritance destructor adjustor thunks.

Evidence:

- Target page records `lookup_funcs` starts at `0x00530c78` and `0x00530c83`, each size `0x0b`.
- Target page records bytes:
  - `0x00530c78`: `81 e9 a0 00 00 00 e9 0d 00 00 00`
  - `0x00530c83`: `81 e9 a4 00 00 00 e9 02 00 00 00`
- Those bodies are `sub ecx, 0xa0/0xa4; jmp 0x00530c90` patterns, not source-level dialog behavior.
- `0xa0` is decimal `160`, `0xa4` is decimal `164`, and `0xb` is decimal `11` (Verified with `tools/int_convert.py` during this pass).
- Vtable refs are `0x00620234 -> 0x00530c78` and `0x00620264 -> 0x00530c83`.
- Both thunks forward to [UID:0001D0] scalar deleting destructor `0x00530c90`.

Rejected alternatives:

- Source-authored helper methods: rejected because the only work is receiver adjustment and tail jump to a destructor wrapper.
- Ordinary destructor body: rejected because [UID:0001CX] is the ordinary destructor body and carries source C++.
- Scalar deleting destructor body: rejected because [UID:0001D0] is the target wrapper.
- Missing/generated-output gap: rejected because both functions have exact starts, bytes, refs, and target.

### `this - 0xa0` / `this - 0xa4` offsets

Best inference: secondary and tertiary subobject destructor adjustments for the inherited pane/event-handler views of `NumberInputDialog`.

Evidence:

- Target page records decompilation of `0x00530c78` as forwarding after subtracting `160` bytes from `this`.
- Target page records decompilation of `0x00530c83` as forwarding after subtracting `164` bytes from `this`.
- [UID:0003C8] `NumberInputDialogVtableData` records:
  - primary vtable base `0x006201d4`;
  - secondary adjusted vtable base `0x00620234`;
  - tertiary adjusted vtable base `0x00620264`;
  - constructor vtable stores at `0x005306aa`, `0x005306b0`, `0x005306ba`;
  - raw destructor stores at `0x00530b09`, `0x00530b0f`, `0x00530b19`;
  - scalar deleting destructor stores at `0x00530c9c`, `0x00530ca2`, `0x00530cac`.
- [UID:00009K] class page records the same offsets and states the two adjusted vtables point through these thunks before jumping to `0x00530c90`.

Rejected stale value:

- `this - 0x1dc` is wrong. `0x1dc` is decimal `476` (Verified with `tools/int_convert.py`) and does not match target bytes, decompiler evidence, vtable layout, or class support docs.

### Vtable refs and scalar deleting destructor target

Best inference: the thunks are only reached by vtable dispatch and forward into the class scalar deleting destructor.

Evidence:

- `xrefs_to` evidence in target and aggregate docs records data refs:
  - `0x00620234 -> 0x00530c78`;
  - `0x00620264 -> 0x00530c83`;
  - `0x006201d4 -> 0x00530c90`.
- `xrefs_to 0x00530c90` records code refs from `0x00530c7e` and `0x00530c89`, which are the jumps inside the two thunks.
- `callers 0x00530c90` has no ordinary caller list despite the code xrefs, matching vtable-only destructor dispatch.
- [UID:0001D0] is already accepted as a class-owned scalar deleting destructor wrapper with blank formal C++.

Rejected alternatives:

- Route through ItemDialogs/MixItemDialog callback logic: rejected. Constructor callers are quantity flows, but thunk xrefs are vtable-only class ABI refs.
- Route through FunctionObjects: rejected. FunctionObjects own callback wrappers, not destructor ABI glue.
- Treat [UID:0001CW] aggregate as the thunk owner: rejected for semantic ownership; the aggregate is a range/index context, while the thunks belong to the NumberInputDialog class ABI shape.

### Stale generated-output corrections

Current facts:

- Historical disabled `class_NumberInputDialog.cpp.disabled` emitted `0x00530c78` with `this - 0x1dc`; wrong.
- The same disabled output treated `0x00530c83` as missing code; wrong.
- Current `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp` contains constructor, ordinary destructor, and action handler C++. It does not emit these thunks, which is correct.
- `auto-generated/-ag-memory-coverage.md` lists `0001CZ` as `not_reconstructable`, which is correct.

Recommended wording direction:

- Do not say generated output should "materialize" C++ for these thunks.
- Treat the old `this - 0x1dc` and missing-code notes as historical generated-data defects that are now resolved by the ignored-thunk classification and current non-emission state.
- If `wave3_data_issues.md` is touched, update its "Fix/generated-materialize both destructor adjustor thunks" language to say the corrected project state is documented ignored thunks with no source emission, not generated thunk C++.

### Source placement and final-C++ policy

Best source replacement:

```cpp
// No RECONSTRUCTION_CPP body for 0001CZ.
// The compiler emits these adjustor thunks from the NumberInputDialog
// inheritance/vtable layout and virtual destructor.
```

No formal C++ should be inserted into `0001CZ`. The source-facing destructor remains:

- [UID:0001CX] `NumberInputDialog::~NumberInputDialog()` for ordinary destructor source.
- [UID:0001D0] class-owned scalar deleting destructor ABI wrapper, blank C++.
- [UID:0003C8] class vtable data, source-declared/generated-binary, blank C++.

This page proves ABI layout and thunk behavior; it does not define a source method name/signature.

## Evidence Standards Used

Evidence types used:

- Existing live-IDA-backed target documentation for `lookup_funcs`, `decompile`, `xrefs_to`, `callers`, bytes, and boundary padding.
- Existing live-IDA-backed vtable data page [UID:0003C8].
- Existing accepted B002 source-quality report and post-execution support docs.
- Current generated output and generated coverage reports.
- Current `by-memory/-coverage-report.md` row.
- `tools/int_convert.py` for required hex/decimal conversions.
- Negative evidence: no ordinary caller route, no source-level body behavior, no current generated thunk source emission.

Current IDA MCP status:

- I attempted `tools/list` against `http://127.0.0.1:13337/mcp` during this pass.
- Result: `Unable to connect to the remote server`.
- Impact: no new live MCP facts were added in this pass. Confidence remains very strong because multiple current docs already contain live IDA checks from 2026-05-25, 2026-05-26, 2026-06-01, 2026-06-06, and 2026-06-12, and those checks agree with current generated output.

## IDA MCP Facts

These are documented live-IDA facts from current by-* pages, not newly queried MCP facts from this pass:

- Function/range facts:
  - `0x00530c78-0x00530c83`: real function, size `0x0b`.
  - `0x00530c83-0x00530c8e`: real function, size `0x0b`.
  - `0x00530c8e-0x00530c90`: two `0xcc` bytes before scalar deleting destructor.
  - `0x00530c90-0x00530cf7`: scalar deleting destructor [UID:0001D0], size `0x67`.
- Byte facts:
  - `0x00530c78`: `81 e9 a0 00 00 00 e9 0d 00 00 00`.
  - `0x00530c83`: `81 e9 a4 00 00 00 e9 02 00 00 00`.
- Xref facts:
  - vtable/data ref `0x00620234 -> 0x00530c78`.
  - vtable/data ref `0x00620264 -> 0x00530c83`.
  - scalar deleting destructor vtable ref `0x006201d4 -> 0x00530c90`.
  - code refs into `0x00530c90` from `0x00530c7e` and `0x00530c89`.
- Vtable/global/type facts:
  - [UID:0003C8] records primary, secondary, and tertiary NumberInputDialog vtable chunks at `0x006201d4`, `0x00620234`, and `0x00620264`.
  - Constructor, raw destructor, and scalar deleting destructor restore all three vtable bases.
- Negative IDA facts:
  - No ordinary caller list for the scalar deleting destructor beyond vtable/thunk dispatch.
  - No source-level logic inside the thunks beyond receiver adjustment and jump.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00530b00-0x00530b35` | [UID:0001CX] `NumberInputDialogRawDestructor` | ordinary destructor body | TRUE | [UID:00009K] | `88/91` | first-draft destructor C++ populated |
| `0x00530c78-0x00530c83` | [UID:0001CZ] target subrange | secondary destructor adjustor thunk | FALSE | recommended [UID:00009K] | recommend `86/92` | ignored/no C++ |
| `0x00530c83-0x00530c8e` | [UID:0001CZ] target subrange | tertiary destructor adjustor thunk | FALSE | recommended [UID:00009K] | recommend `86/92` | ignored/no C++ |
| `0x00530c8e-0x00530c90` | [UID:0000VN] ignored padding context | two-byte `0xcc` padding | FALSE | none | ledger only | not part of target |
| `0x00530c90-0x00530cf7` | [UID:0001D0] `NumberInputDialogScalarDeletingDestructor` | scalar deleting destructor wrapper | TRUE, source-declared/generated-binary | [UID:00009K] | `86/92` | blank C++ by design |
| `0x006201d0-0x0062026c` | [UID:0003C8] `NumberInputDialogVtableData` | class vtable data | TRUE, source-declared/generated-binary | [UID:00009K] | `88/92` | blank C++ by design |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00620234` | data ref to `0x00530c78` | secondary NumberInputDialog vtable first slot points at adjustor thunk |
| `0x00620264` | data ref to `0x00530c83` | tertiary NumberInputDialog vtable first slot points at adjustor thunk |
| `0x00530c7e` | code ref into `0x00530c90` | first thunk jump into scalar deleting destructor |
| `0x00530c89` | code ref into `0x00530c90` | second thunk jump into scalar deleting destructor |
| `0x006201d4` | data ref to `0x00530c90` | primary NumberInputDialog vtable first slot points at scalar deleting destructor |
| `0x005306b0` / `0x005306ba` | constructor stores adjusted vtable bases | constructor establishes secondary/tertiary class ABI views |
| `0x00530b0f` / `0x00530b19` | raw destructor stores adjusted vtable bases | ordinary destructor restores same adjusted ABI views |
| `0x00530ca2` / `0x00530cac` | scalar destructor stores adjusted vtable bases | scalar wrapper restores same adjusted ABI views |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md`
  - Contains the exact start/size, byte, decompile, xref, and padding facts.
- `by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md`
  - Confirms scalar deleting destructor role, incoming thunk refs, vtable refs, and blank C++ policy.
- `by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md`
  - Confirms primary/secondary/tertiary vtable bases and slot targets.
- `by-memory/0x00530640-0x00530cf7.NumberInputDialog.md`
  - Confirms contiguous class range, child page map, two exact thunks, and stale generated output corrections.
- `by-class/NumberInputDialog.md`
  - Confirms reusable dialog class ownership, field names, accepted source policy, and that `0001CZ` remains non-reconstructable compiler glue.
- `by-file/NumberInputDialog.md`
  - Confirms `NexusTK/ui/dialogs/NumberInputDialog.cpp` source placement and no hand-written scalar/adjustor bodies.
- `by-memory/-ignored.md`
  - Already lists `0x00530c78-0x00530c8e` as ignored NumberInputDialog secondary/tertiary destructor adjustor thunks.
- `Agent-B002/research/executed/0001CV-0001CX-0001CY-0001D0-NumberInputDialog-source-quality.md`
  - Accepted/executed source-quality report that resolved class/file placement, ordinary destructor vs scalar wrapper, and adjustor-thunk no-code policy.

Existing docs that are stale, incomplete, or should be sharpened:

- Target metadata remains `82/90` and `CANONICAL_OWNER:NONE`, despite the accepted support docs now making class context and no-code proof stronger.
- Target covered-range notes say "disabled generated output currently uses" the wrong `this - 0x1dc` / missing-code state. That should become historical generated-output defect wording, because current autogen correctly does not emit thunk source.
- `wave3_data_issues.md` still contains an older "Fix/generated-materialize both destructor adjustor thunks" direction. If touched, update it to "document/keep ignored thunks, no source emission."

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists `0001CZ` as `not_reconstructable`, which is correct.
- `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp` currently has no thunk C++ bodies, which is correct.
- `project-level/-auto-completion-stats.md` still shows `0001CZ` as `82/90`; if the target metadata is updated, validator rescore/autogen should refresh it.

## Ranked Ownership Analysis

### 1. [UID:00009K] NumberInputDialog class

Evidence for:

- Both thunks target the NumberInputDialog scalar deleting destructor [UID:0001D0].
- Both thunks are referenced from NumberInputDialog secondary/tertiary vtable bases [UID:0003C8].
- Constructor, raw destructor, and scalar destructor store the same three NumberInputDialog vtable bases.
- B002's accepted source-quality execution already rerouted the source-bearing NumberInputDialog method pages and scalar wrapper to [UID:00009K].
- [UID:00009K] and [UID:0000M1] are above gate and validated support pages.

Evidence against:

- Some older ignored adjustor-thunk pages use `CANONICAL_OWNER:NONE` to emphasize no source emission.
- The target does not emit source C++ and should not participate in generated source assembly.

Decision:

- Recommended `CANONICAL_OWNER:00009K`, `RECONSTRUCTABLE:FALSE`, blank emitter. This documents semantic class context without emitting generated thunk source.

### 2. [UID:0000M1] NumberInputDialog file

Evidence for:

- File owns the source module `NexusTK/ui/dialogs/NumberInputDialog.cpp`.
- Current target body says "Covered file/module: [UID:0000M1]".

Evidence against:

- `CANONICAL_OWNER` should be the narrowest true owner. These thunks are class ABI artifacts, not file-level free helpers.
- The class page now clears the gate and already owns related method/vtable pages.

Decision:

- Reject direct file owner for target metadata. Keep file as source route through [UID:00009K].

### 3. [UID:0001CW] NumberInputDialog aggregate range

Evidence for:

- Aggregate records the contiguous method range and child inventory.
- Existing older routing used the aggregate as source route/context.

Evidence against:

- The aggregate is an index/context page, not the semantic owner of class-specific ABI thunks.
- B002's accepted pass moved direct method ownership to the class while keeping the aggregate as range documentation.

Decision:

- Reject aggregate as direct owner. Keep cross-reference only.

### 4. `CANONICAL_OWNER:NONE`

Evidence for:

- Current target has `NONE`.
- [UID:00015K] `FpsPaneAdjustorThunks` keeps `NONE` for similar ignored thunks.
- `NONE` is safe if the project wants ignored compiler thunks out of the ownership graph.

Evidence against:

- By-structure allows owner context on `RECONSTRUCTABLE:FALSE` pages.
- [UID:0003XL] `MapNamePaneDestructorAdjustorThunks` uses its direct class owner while still `RECONSTRUCTABLE:FALSE`.
- The user specifically asked not to leave source-placement policy passive; class context is fully resolved.

Decision:

- Reject as the primary recommendation. Accept only as fallback if supervisor standardizes all ignored thunk pages to `NONE`.

## Negative Evidence Summary

Checked and rejected:

- Generated `this - 0x1dc`: contradicted by bytes, decompilation, vtable offsets, and `tools/int_convert.py` conversion.
- "Missing code" for `0x00530c83`: contradicted by `lookup_funcs`, bytes, xrefs, and scalar-destructor code refs.
- Handwritten thunk methods: contradicted by `sub ecx, imm; jmp` bodies and vtable-only refs.
- ItemDialogs/MixItemDialog ownership: constructor callers only configure the dialog; destructor thunks are class ABI, not item business logic.
- FunctionObjects ownership: callback wrappers are caller-side objects; destructor thunks do not call them.
- TextEdit/LanguageMan/AlertPane helper ownership: those are dependencies of the action handler, not thunk owners.
- Reconstructable source body: rejected because source replacement is ordinary destructor/class declaration; thunk source would be decompiler-shaped ABI code.

## Final Recommendation

Recommended target changes for `by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md`:

1. Change metadata:

```yaml
COMPLETION: 86
CONFIDENCE: 92
CANONICAL_OWNER: 00009K
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

2. Keep `RECONSTRUCTION_CPP CODE` blank.

3. Replace or sharpen the status/ownership text:

```text
Disposition: compiler/linker-generated NumberInputDialog secondary/tertiary destructor adjustor thunks.
Semantic owner context: [UID:00009K] NumberInputDialog.
Source module context: [UID:0000M1] NumberInputDialog.
Source replacement: the ordinary virtual destructor declaration/body at [UID:0001CX], plus compiler-generated scalar deleting destructor ABI documented by [UID:0001D0].
No formal C++ body belongs on this page.
```

4. Replace the stale generated-output wording in the covered-ranges table:

```text
Historical disabled generated output used the wrong `this - 0x1dc` adjustment for this thunk; current source-quality state is `this - 0xa0` / decimal `160` (Verified with `tools/int_convert.py`) and no emitted C++ body.
```

```text
Historical disabled generated output marked this thunk as missing code; current source-quality state is a real `0x0b` / decimal `11` byte thunk (Verified with `tools/int_convert.py`) using `this - 0xa4` / decimal `164` (Verified with `tools/int_convert.py`) and no emitted C++ body.
```

5. Add the current generated-output correction:

```text
Current `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp` correctly receives constructor, ordinary destructor, and action-handler C++ from [UID:0001CV], [UID:0001CX], and [UID:0001CY]. It should not emit these adjustor thunks; `auto-generated/-ag-memory-coverage.md` should continue to classify [UID:0001CZ] as `not_reconstructable`.
```

6. Add a change-log entry:

```text
2026-06-19 B005 source-quality recheck: recommended `82/90 -> 86/92` and semantic owner context [UID:00009K] while keeping `RECONSTRUCTABLE:FALSE`, blank emitter, and blank C++. The recheck confirms both `0x0b` thunks, `this - 0xa0` / `this - 0xa4` offsets, vtable refs `0x00620234` / `0x00620264`, code refs into [UID:0001D0] at `0x00530c90`, two-byte padding before the scalar deleting destructor, current generated non-emission, and rejection of stale `this - 0x1dc` / missing-code generated output.
```

## Recommended Support-Doc Updates

`by-class/NumberInputDialog.md` [UID:00009K]:

- No score change recommended; current `90/91` remains justified.
- Add or sharpen one sentence in the method-family row or source-quality closure:

```text
[UID:0001CZ] is class-owned ABI evidence for the secondary and tertiary destructor views, but remains `RECONSTRUCTABLE:FALSE` with blank emitters/C++; it is regenerated from the class inheritance/vtable layout and virtual destructor source, not handwritten.
```

`by-file/NumberInputDialog.md` [UID:0000M1]:

- No score change recommended; current `91/90` remains justified.
- Replace any "Use [UID:0001CZ] until generated data is fixed" style wording with:

```text
Historical disabled generated output decoded the first adjustor as `this - 0x1dc` and omitted the second thunk. Current source-quality state is documented ignored thunk evidence: `0x00530c78` uses `this - 0xa0`, `0x00530c83` uses `this - 0xa4`, and neither thunk should appear as C++ in `NumberInputDialog.cpp`.
```

`by-memory/0x00530640-0x00530cf7.NumberInputDialog.md` [UID:0001CW]:

- No score or metadata change recommended; current `89/91` reconstructable range/index state is consistent with the accepted B002 implementation.
- In `Generated Data Caveats`, change the disabled-output notes from active generated defects to historical corrections and state the current generated state:

```text
The corrected output policy is no adjustor-thunk C++ emission. [UID:0001CZ] remains an ignored class-ABI evidence page while source bodies are carried by the constructor, ordinary destructor, and action-handler children.
```

`by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md` [UID:0001D0]:

- No score or metadata change recommended; current `86/92`, owner/emitter [UID:00009K], blank C++ policy remains correct.
- Optional wording addition:

```text
The incoming adjusted jumps from [UID:0001CZ] are generated secondary/tertiary destructor dispatch glue. They further support this page's scalar deleting destructor ABI role but do not require thunk C++.
```

`by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md` [UID:0003C8]:

- No score or metadata change recommended.
- Optional wording addition:

```text
If [UID:0001CZ] is updated to `86/92` and `CANONICAL_OWNER:00009K`, this page can cite that refreshed target as the exact ignored code counterpart for secondary slot `0x00620234` and tertiary slot `0x00620264`.
```

`by-memory/-ignored.md` [UID:0000VN ledger context]:

- Do not edit during this report-only pass.
- If touched after implementation, update the NumberInputDialog ignored entry evidence line to mention the refreshed `86/92` page and semantic class context:

```text
  - Evidence: [UID:0001CZ] records the refreshed B005 source-quality no-code proof: two exact `0x0b` adjustor thunks, `this - 0xa0` and `this - 0xa4` offsets, vtable refs at `0x00620234` and `0x00620264`, code refs into scalar deleting destructor `0x00530c90`, and class context [UID:00009K].
```

`wave3_data_issues.md`:

- If support scope includes this file, update the old "Fix/generated-materialize both destructor adjustor thunks" line to:

```text
Resolution: do not materialize C++ for these thunks. Keep [UID:0001CZ] as ignored compiler-generated NumberInputDialog adjustor-thunk evidence, with `this - 0xa0` and `this - 0xa4` documented and current generated `NumberInputDialog.cpp` omitting thunk source.
```

`auto-generated` / project-level reports:

- Do not edit by hand.
- After implementation, validator/autogen should update:
  - `auto-generated/-ag-memory-coverage.md` target score/owner if metadata changes;
  - `project-level/-auto-completion-stats.md` from `82/90` to `86/92`;
  - no thunk C++ should be added to `auto-generated/NexusTK/ui/dialogs/NumberInputDialog.cpp`.

## Exact Coverage Report Text

Do not edit `by-memory/-coverage-report.md` during report-only work. If the target recommendation is accepted, replace the current `0001CZ` row with:

```text
    - [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) : ignored : 86% : very strong : Source-quality recheck confirms NumberInputDialog secondary/tertiary destructor adjustor thunks at `0x00530c78-0x00530c83` and `0x00530c83-0x00530c8e`; each is an exact `0x0b` / decimal `11` byte compiler-generated thunk (Verified with `tools/int_convert.py`) that subtracts `0xa0` / decimal `160` or `0xa4` / decimal `164` from `this` (Verified with `tools/int_convert.py`) and jumps through code refs `0x00530c7e` / `0x00530c89` to [UID:0001D0] scalar deleting destructor `0x00530c90`, with vtable refs `0x00620234` / `0x00620264`, primary scalar slot `0x006201d4`, two-byte `0xcc` padding before `0x00530c90`, rejected stale generated `this - 0x1dc` / missing-code output, semantic class context [UID:00009K], blank emitter/C++ policy, and source replacement by the ordinary virtual destructor [UID:0001CX].
```

If the supervisor keeps `CANONICAL_OWNER:NONE` for ignored-thunk convention, use the same row but replace `semantic class context [UID:00009K]` with `documented NumberInputDialog class context [UID:00009K]`.

## Validator Needs After Implementation

No validator was run for this report-only task.

If only the target page is changed:

> Executable block R001 was removed from this report and preserved verbatim in [0001CZ-NumberInputDialogAdjustorThunks-source-quality-removed.md](0001CZ-NumberInputDialogAdjustorThunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional support docs are touched, run scoped file validation for each touched doc:

> Executable block R002 was removed from this report and preserved verbatim in [0001CZ-NumberInputDialogAdjustorThunks-source-quality-removed.md](0001CZ-NumberInputDialogAdjustorThunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not validate or edit `by-memory/-coverage-report.md` from the B-agent implementation pass while the shared-file ban is active; return the exact pending coverage row above for supervisor-owned application.

## Implementation Readiness

Ready for implementation callback.

Minimum safe implementation:

1. Update `0001CZ` metadata to `86/92`, `CANONICAL_OWNER:00009K`, `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
2. Replace active/stale generated-output phrasing with historical-defect wording and current non-emission state.
3. Add active no-code proof tying both thunks to vtable slots and [UID:0001D0].
4. Leave [UID:0001CX], [UID:0001D0], [UID:00009K], [UID:0000M1], and [UID:0001CW] source policies intact unless the supervisor explicitly asks for support-doc wording updates.
5. Do not add thunk source C++ and do not alter generated `NumberInputDialog.cpp` by hand.

Remaining issues:

- Fresh IDA MCP was unavailable in this pass. Existing documentation contains multiple recent live IDA confirmations, and no current generated output contradicts them.
- Exact original class declaration/inheritance names for the secondary/tertiary views remain class-header work, not a blocker for this thunk no-code proof.
- Project convention is mixed on whether ignored thunks keep `CANONICAL_OWNER:NONE` or a class owner. B005 recommends class owner [UID:00009K] because the direct class context is resolved and by-structure permits ownership context on non-reconstructable pages.

## Validator Results

- Commands run: none.
- IDA MCP availability check: failed with `Unable to connect to the remote server`.
- Numeric conversion checks: `tools/int_convert.py` confirmed `0xa0 -> 160`, `0xa4 -> 164`, `0x1dc -> 476`, and `0xb -> 11`.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0001CZ-NumberInputDialogAdjustorThunks-source-quality.md`
- Modified: none outside the B005 research folder.
- Renamed: none.
- Moved to executed: none.

Leases used: none. B005 research report path is agent-owned and does not require target/support leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001CZ-NumberInputDialogAdjustorThunks-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0001CZ"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CZ-NumberInputDialogAdjustorThunks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001CZ-NumberInputDialogAdjustorThunks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
