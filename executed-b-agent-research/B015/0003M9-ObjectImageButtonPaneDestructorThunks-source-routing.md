** TARGET-REPORT-UID:0003M9 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003M9 **
# 0003M9 ObjectImageButtonPaneDestructorThunks Source Routing Report

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md`  
Target path: `source-3/project-documentation/by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`  
Target UID: [UID:0003M9]  
Status: report-only. No by-* docs edited. `by-memory/-coverage-report.md` not edited.

## Final Recommendation

- Keep [UID:0003M9] as compiler/linker-generated destructor adjustor glue.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Raise target score from `84/88` to `86/91`.
- Source-facing owner remains [UID:00009N] `ObjectImageButtonPane`; source-file route remains [UID:0000M3] `ObjectImageControlPane`.
- Do not emit source C++ for this exact range. The source-level behavior is a normal/implicit `ObjectImageButtonPane` destructor and class/vtable declaration; the compiler should regenerate these two secondary/tertiary this-adjustor thunks from the inheritance/vtable layout.

Confidence is high for boundaries and role because the raw bytes, vtable data refs, neighboring ranges, generated coverage, and existing IDA-backed docs all agree. Confidence stays below final-audit level because live IDA MCP was unavailable in this B015 session and the class declaration/field names remain not final-source quality.

## Target And Current State

Current target metadata:

```text
COMPLETION:84
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Current target summary is directionally correct: it identifies the range as two compiler-generated adjustor thunks for [UID:00009N] `ObjectImageButtonPane`, forwarding to [UID:0003MA] `ObjectImageButtonPaneScalarDeletingDestructor`. The gaps are source-quality detail, exact raw bytes, exact vtable refs, current coverage repair text, and a stronger no-code/source-routing proof.

## Evidence Checked

- Required instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
- Target/sibling docs:
  - [UID:0003M9] `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`
  - [UID:0003MA] `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`
  - [UID:0001BV] `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`
  - [UID:0001BU] `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`
  - [UID:0001BX] `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
- Owner/support docs:
  - [UID:00009N] `by-class/ObjectImageButtonPane.md`
  - [UID:00009O] `by-class/ObjectImageControlPane.md`
  - [UID:0000M3] `by-file/ObjectImageControlPane.md`
  - [UID:00025U] `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
  - [UID:0003CA] `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`
  - [UID:000197] `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
  - `wave3_data_issues.md`
- Generated/report evidence:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp`
  - `project-level/-auto-completion-stats.md`
  - `project-level/-resolved.md`
  - `project-level/-unresolved.md`
  - `by-memory/-coverage-report.md`
- Fresh raw PE evidence:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

Live IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and failed with `Unable to connect to the remote server`. This report therefore uses existing IDA-backed documentation plus a fresh raw PE byte/xref scan.

## Raw PE Facts

Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`  
Image base: `0x00400000`; `.text` contains the target bytes.

Exact target bytes:

| Range | Bytes | Meaning |
| --- | --- | --- |
| `0x00520ae7-0x00520af2` | `81 e9 a0 00 00 00 e9 6e 01 00 00` | `ecx -= 0xa0`; jump to `0x00520c60`. |
| `0x00520af2-0x00520afd` | `81 e9 a4 00 00 00 e9 63 01 00 00` | `ecx -= 0xa4`; jump to `0x00520c60`. |

Size evidence:

- Each thunk is `0xb` / 11 bytes (Verified with `int_convert.py`).
- Combined target range is `0x16` / 22 bytes (Verified with `int_convert.py`).
- The first thunk adjusts by `0xa0` / 160 bytes (Verified with `int_convert.py`).
- The second thunk adjusts by `0xa4` / 164 bytes (Verified with `int_convert.py`).
- [UID:0003MA] scalar deleting destructor is `0x3b` / 59 bytes (Verified with `int_convert.py`).
- [UID:0003MA] guarded bit-4/no-op path pushes complete object size `0x150` / 336 bytes (Verified with `int_convert.py`).

Boundary evidence:

- Predecessor [UID:0001BY] ends exactly at `0x00520ae7`.
- Successor `ObjectImageControlPane` thunk pair starts exactly at `0x00520afd`.
- There is no padding inside [UID:0003M9]; it is two contiguous 11-byte functions.
- The larger [UID:0001BX] destructor island is a mixed compiler-glue strip, not one source routine.

Vtable/ref evidence from raw PE scan:

- Primary `ObjectImageButtonPane` vtable base `0x0061f764` first slot points to [UID:0003MA] `0x00520c60`.
- Secondary `ObjectImageButtonPane` vtable base `0x0061f7cc` first slot points to thunk `0x00520ae7`.
- Tertiary `ObjectImageButtonPane` vtable base `0x0061f7fc` first slot points to thunk `0x00520af2`.
- Constructor/core bytes contain vtable base immediates:
  - `0x00520837` references `0x0061f764`.
  - `0x00520843` references `0x0061f7cc`.
  - `0x0052084d` references `0x0061f7fc`.
- There are no ordinary `.text` rel32 call/jump refs to the thunk starts `0x00520ae7` or `0x00520af2`.
- The only code refs to [UID:0003MA] `0x00520c60` are the two thunk jumps at `0x00520aed` and `0x00520af8`.

Scalar sibling [UID:0003MA] bytes confirm the wrapper relation:

- Calls [UID:0003CA]-supported `Pane` teardown at `0x00544580`.
- Tests scalar-delete flag bit `1`.
- Ordinary delete path calls [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0`.
- Bit-4 path pushes object size `0x150` / 336 and calls `0x0041b6a0`, whose raw bytes are `c3` followed by padding; this is guard/no-op compiler support, not a second meaningful class cleanup path.

## Function / Child Inventory

| Range / item | UID / path | Role | Reconstructable | Direct source owner | Score recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00520820-0x00520a90` | [UID:0001BV] `ObjectImageButtonPaneCore` | Source-bearing constructor, key handler, paint, highlight setter | TRUE | [UID:0000M3] through [UID:00009N] | No target change here; coverage row should use current `85/88` and corrected range | Source methods; C++ still blank pending class fields/descriptors. |
| `0x00520ae7-0x00520afd` | [UID:0003M9] target | Secondary/tertiary destructor this-adjustor thunk pair | FALSE | Source-related to [UID:00009N], but metadata owner remains `NONE` | `84/88 -> 86/91` | Exact no-code compiler glue. |
| `0x00520c60-0x00520c9b` | [UID:0003MA] scalar deleting destructor | Primary deleting destructor wrapper | FALSE | Source-related to [UID:00009N], but metadata owner remains `NONE` | No independent score change from this report unless supervisor wants support sync | Compiler wrapper; ordinary source destructor/class declaration should generate it. |
| `0x00520540-0x00520816` | [UID:0001BU] `ObjectImageControlPane` | Base preview-control source methods | TRUE | [UID:0000M3] | No target change; coverage row is stale and should reflect current `85/86` | Source base class used by button constructor. |
| `0x00520abb-0x00520e2b` | [UID:0001BX] mixed destructor island | Mixed compiler-generated destructor/thunk ledger | FALSE | None | Coverage row is stale and should reflect current `87/90` non-reconstructable policy | Index over exact owner-specific glue. |

## Heuristic / Inference Reanalysis And Validation

### Adjustor thunk boundaries

Best-supported conclusion: [UID:0003M9] contains exactly two 11-byte adjustor thunks and no hidden source body.

Evidence:

- Raw bytes show two repeated `sub ecx, imm32; jmp rel32` patterns.
- The first thunk starts exactly at the predecessor endpoint `0x00520ae7`.
- The second thunk starts exactly at `0x00520af2`.
- The successor starts exactly at `0x00520afd`.
- Vtable slots reference the thunk starts directly.

Rejected alternatives:

- Not padding: executable bytes are valid thunk instructions and are vtable-referenced.
- Not one 22-byte source function: each 11-byte chunk has an independent vtable slot and independent jump.
- Not part of [UID:0001BY]: predecessor ends at this range and uses the same pattern for different list-pane owners.
- Not part of `ObjectImageControlPane`: the next two thunks at `0x00520afd`/`0x00520b08` route to `0x00520ca0`, not this target's `0x00520c60`.

### Source-facing destructor role

Best-supported conclusion: these thunks are generated for the `ObjectImageButtonPane` destructor entry in secondary and tertiary vtable views. The source-facing role is not a handwritten function. It is the `ObjectImageButtonPane` class declaration/inheritance layout plus a default/ordinary destructor path.

Evidence:

- Constructor stores `ObjectImageButtonPane` vtables at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- The thunk deltas subtract exactly `0xa0` and `0xa4`, recovering the complete object pointer before forwarding to the primary scalar deleting destructor.
- The primary vtable first slot uses [UID:0003MA] directly; secondary/tertiary first slots use the two adjustors.
- [UID:0003MA] performs no derived `ObjectImageButtonPane` cleanup beyond pane-base teardown and scalar delete handling.

Recommended source policy:

- Do not emit a destructor body from [UID:0003M9].
- If a future class declaration needs a visible destructor for vtable clarity, place that declaration with [UID:00009N] / [UID:0000M3], not in this memory page.
- Source shape should be no more than an implicit/empty `ObjectImageButtonPane` destructor; these thunks should be compiler output.

### Source owner and file route

Best-supported source route:

- Semantic class: [UID:00009N] `ObjectImageButtonPane`.
- Source file family: [UID:0000M3] `ObjectImageControlPane`.
- Metadata for [UID:0003M9]: keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, because the exact bytes are compiler/linker-generated and should not appear as a source-emitting child.

Why [UID:0000M3] remains the source family:

- The constructor at [UID:0001BV] calls [UID:0001BU] `ObjectImageControlPane` at `0x00520830`.
- [UID:0000M3] already models both the preview control and button subclass.
- `HeadSelectDialog` is a consumer that creates and toggles these buttons; it is not the class source owner.
- [UID:0000NY] `SpecializedButtonPanes` remains only a historical/generated-source lead.

Rejected owner alternatives:

- [UID:0000JT] `HeadSelectDialog`: rejected because it only constructs and uses the button grid.
- [UID:0000NY] `SpecializedButtonPanes`: rejected as stale generic bucket; current base-constructor and source-family evidence favors object-image controls.
- [UID:0001BX] `MenuDialogDestructorThunks`: rejected as a mixed compiler-glue ledger, not a source owner.
- [UID:00025U] read-only aggregate: rejected as physical `.rdata` context, not a source owner for executable thunks.
- [UID:0003MA] scalar deleting destructor: sibling/target of jumps, not a parent source owner.

### Generated-name pollution

Current docs and unresolved reports still expose generated names such as `sub_544580`, `sub_4F4AC0`, and stale `TextButtonExControlPane::~Pane` wording.

Recommended source-quality names:

- `0x00544580`: `Pane::~Pane()` or neutral `PaneBaseTeardown`, supported by [UID:0003CA] `PaneVtableData`; not `TextButtonExControlPane`.
- `0x004f4ac0`: [UID:000197] `OperatorDeleteWrapper`.
- `0x0041b6a0`: guard/no-op return stub; do not name it as an object-image callback.
- `0x00520c60`: `ObjectImageButtonPaneScalarDeletingDestructor`.
- `0x00520ae7`: `ObjectImageButtonPaneDtorAdjustor_A0` or IDA comment "this -= 0xa0; jump to scalar deleting destructor".
- `0x00520af2`: `ObjectImageButtonPaneDtorAdjustor_A4` or IDA comment "this -= 0xa4; jump to scalar deleting destructor".

The target page should keep historical raw labels only as search aliases. Source-facing docs should use class/destructor roles and the helper UIDs above.

### Generated output state

Generated output `auto-generated/NexusTK/ui/controls/ObjectImageControlPane.cpp` contains only empty emitter markers for [UID:00009N], [UID:00009O], [UID:0001BU], and [UID:0001BV]. [UID:0003M9] and [UID:0003MA] do not emit, which matches the recommended policy.

Generated memory coverage correctly lists [UID:0003M9] as `not_reconstructable` with `NONE`, but the hand-authored `by-memory/-coverage-report.md` local block is stale and omits the target row.

## Exact No-Code Proof

Formal C++ for [UID:0003M9] should remain blank. The whole range is compiler ABI glue:

```asm
; [UID:0003M9] 0x00520ae7-0x00520af2
; Secondary vtable destructor adjustor for ObjectImageButtonPane.
sub ecx, 0xa0
jmp ObjectImageButtonPaneScalarDeletingDestructor ; 0x00520c60

; [UID:0003M9] 0x00520af2-0x00520afd
; Tertiary vtable destructor adjustor for ObjectImageButtonPane.
sub ecx, 0xa4
jmp ObjectImageButtonPaneScalarDeletingDestructor ; 0x00520c60
```

Source should instead be represented by the class declaration/destructor semantics in [UID:00009N] and [UID:0000M3]. A future source-style note can say:

```cpp
// No ObjectImageButtonPane destructor body is proven here.
// The binary thunks are generated from the class's secondary/tertiary vtable views.
```

Do not place this snippet in [UID:0003M9]'s `RECONSTRUCTION_CPP CODE`; it is explanatory only.

## Score / Metadata Recommendation

Recommended target header:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Score rationale:

- Completion rises because the report resolves exact byte boundaries, thunk instruction shapes, vtable refs, source-routing policy, scalar sibling relationship, generated-name pollution, and coverage repair text.
- Confidence rises because local raw PE evidence independently confirms the existing IDA-backed documentation.
- Completion remains below 90 because this is not a source-emitting item and the support docs still need incorporation.
- Confidence remains below 92/95 because live IDA MCP was unavailable and the object-image class declarations are not final-source complete.

## Exact Recommended Implementation Checklist

### Target: `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`

- Change `COMPLETION:84` to `COMPLETION:86`.
- Change `CONFIDENCE:88` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep C++ blank.
- Add a B015 raw PE evidence section with:
  - exact two thunk byte sequences;
  - sizes `0xb` / 11 each and combined `0x16` / 22, all Verified with `int_convert.py`;
  - offsets `0xa0` / 160 and `0xa4` / 164, Verified with `int_convert.py`;
  - jump target [UID:0003MA] `0x00520c60`;
  - vtable slot refs `0x0061f7cc -> 0x00520ae7` and `0x0061f7fc -> 0x00520af2`;
  - no ordinary code callers to thunk starts.
- Add exact no-code proof: compiler adjustor thunks only; source destructor/class declaration should live with [UID:00009N]/[UID:0000M3].
- Replace generic "forwarding from adjacent adjusted slot" wording with "secondary `+0xa0` and tertiary `+0xa4` view adjustors".
- Add relationship note to [UID:0003MA] and [UID:0001BV].
- Add generated-name cleanup note: do not use `TextButtonExControlPane` as destructor/base owner; use `Pane::~Pane()`/`PaneBaseTeardown` for `0x00544580` and [UID:000197] for `0x004f4ac0`.

### Support: `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`

- Add a short cross-note that [UID:0003M9] thunks at `0x00520ae7` and `0x00520af2` are the only code refs to this scalar wrapper in the raw PE scan.
- Add the primary vtable slot `0x0061f764 -> 0x00520c60`.
- If not superseded by B002's dedicated [UID:0003MA] report, add the scalar-wrapper byte behavior:
  - calls `Pane` teardown at `0x00544580`;
  - ordinary delete path calls [UID:000197] `OperatorDeleteWrapper`;
  - bit-4 path pushes object size `0x150` / 336 (Verified with `int_convert.py`) and calls `0x0041b6a0`, a one-byte no-op return stub.
- Keep `RECONSTRUCTABLE:FALSE`, owner `NONE`, emitters blank, and C++ blank.

### Support: `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`

- Add exact vtable/destructor-routing note:
  - constructor stores `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`;
  - primary destructor slot routes to [UID:0003MA];
  - secondary/tertiary destructor slots route through [UID:0003M9].
- Keep the source-bearing core range exactly `0x00520820-0x00520a90`.
- Preserve blank C++ until the object-image descriptor and class field names are source-quality.

### Support: `by-class/ObjectImageButtonPane.md`

- Update adjustor-thunk method row from loose `0x00520ae7-0x00520afc` wording to exact exclusive range `0x00520ae7-0x00520afd`, with child ranges `0x00520ae7-0x00520af2` and `0x00520af2-0x00520afd`.
- Add the vtable route:
  - `0x0061f764[0] -> 0x00520c60`;
  - `0x0061f7cc[0] -> 0x00520ae7`;
  - `0x0061f7fc[0] -> 0x00520af2`.
- Replace unresolved/generated helper text:
  - `sub_544580` -> `Pane::~Pane()` / `PaneBaseTeardown` with [UID:0003CA].
  - `sub_4F4AC0` -> [UID:000197] `OperatorDeleteWrapper`.
  - `TextButtonExControlPane` destructor/base labels -> historical generated-name pollution, not inheritance proof.
- Add source-facing destructor note: no derived cleanup is proven; compiler-generated thunk/scalar-wrapper bytes should rebuild from class declaration/vtable layout.

### Support: `by-file/ObjectImageControlPane.md`

- Add a B015 note under proposed contents/source-family evidence:
  - [UID:0003M9] is exact non-emitting secondary/tertiary destructor glue for `ObjectImageButtonPane`;
  - [UID:0003MA] is the primary scalar deleting destructor wrapper;
  - both are evidence for the class declaration and vtable layout, not source functions in `ObjectImageControlPane.cpp`.
- Keep [UID:0000M3] as the preferred route over `SpecializedButtonPanes`.

### Support: `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`

- Add a small object-image vtable slot detail if low risk:
  - `ObjectImageButtonPane` primary `0x0061f764` first slot `0x00520c60`;
  - secondary `0x0061f7cc` first slot `0x00520ae7`;
  - tertiary `0x0061f7fc` first slot `0x00520af2`.
- Keep this page a non-emitting mixed `.rdata` aggregate; do not assign it to [UID:0000M3].

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` from this B-agent pass. Recommended supervisor-owned coverage changes:

Replace the stale [UID:0001BU] and [UID:0001BV] rows with:

```markdown
    - [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) 0x00520540-0x00520816 | class-method-cluster | ObjectImageControlPane : reconstructable : 85% : strong : Current object-image preview-control method cluster; live IDA-backed docs confirm constructor `0x00520540-0x005205b4`, paint handler `0x005205c0-0x00520816`, descriptor copy/state at `+0x108..+0x148`, human/monster/EPF paint dispatch, vtable refs `0x0061f6c0`/`0x0061f728`/`0x0061f758`, non-contiguous generated destructor/thunk support, source route [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), and blank final C++ pending descriptor field/source declaration quality.
    - [UID:0001BV][0x00520820-0x00520a90.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md) 0x00520820-0x00520a90 | class-method-cluster | ObjectImageButtonPane source-bearing core : reconstructable : 85% : strong : Source-bearing ObjectImageButtonPane constructor/key/paint/highlight cluster after the 2026-06-12 split; constructor calls [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) at `0x00520830`, installs vtable bases `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`, HeadSelectDialog creates/toggles the button grid, and generated destructor glue is split into [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) plus [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md). Final C++ remains blank pending descriptor/field source-quality work.
```

Replace the stale [UID:0001BX] row with:

```markdown
    - [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) 0x00520abb-0x00520e2b | destructor/thunk island | MenuDialogDestructorThunks : not_reconstructable : 87% : very-strong : Reviewed mixed compiler-generated destructor/thunk ledger; exact child pages carry owner-specific routing while the aggregate stays non-emitting because the physical island crosses argumented-menu, shared client/spell list, object-image, server-item, text-menu, and shared scalar-deleting destructor glue. B015 2026-06-19 recheck confirms the object-image subranges [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) and [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) are exact compiler glue, not source functions for this aggregate.
```

Insert the target row immediately after [UID:0001BY] `0x00520ad1-0x00520ae7` and before any `0x00520afd` / `0x00520b13` successor rows:

```markdown
    - [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) 0x00520ae7-0x00520afd | compiler adjustor thunks | ObjectImageButtonPane destructor adjustor thunks : not_reconstructable : 86% : very-strong : B015 2026-06-19 raw PE recheck confirms two adjacent `0xb` / 11-byte thunks (Verified with int_convert.py): `0x00520ae7-0x00520af2` subtracts `0xa0` / 160 from `ecx` (Verified with int_convert.py) and jumps to [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md), while `0x00520af2-0x00520afd` subtracts `0xa4` / 164 (Verified with int_convert.py) and jumps to the same scalar deleting destructor. The thunk starts have exact `.rdata` vtable slot refs `0x0061f7cc -> 0x00520ae7` and `0x0061f7fc -> 0x00520af2`, no ordinary direct callers, and source should model the class/destructor through [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) / [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) rather than emitting handwritten C++ for this byte range.
```

Insert the scalar sibling row immediately after [UID:0001C1] `0x00520c20-0x00520c5b` and before [UID:0001C2] `0x00520ce0-0x00520d47`, unless superseded by B002's dedicated [UID:0003MA] report:

```markdown
    - [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) 0x00520c60-0x00520c9b | scalar-deleting-destructor | ObjectImageButtonPane scalar deleting destructor : not_reconstructable : 84% : strong : Exact compiler-generated primary deleting wrapper for [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md); primary vtable slot `0x0061f764 -> 0x00520c60`, code refs only from [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md), calls Pane teardown at `0x00544580`, conditionally frees through [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), and should remain blank/no-code because the source class declaration or implicit destructor should regenerate this wrapper.
```

## Validation Commands Needed After Accepted Implementation

Run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md](0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Run autogen if metadata/support changes are accepted:

> Executable block R002 was removed from this report and preserved verbatim in [0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md](0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Coverage report remains supervisor-owned:

> Executable block R003 was removed from this report and preserved verbatim in [0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md](0003M9-ObjectImageButtonPaneDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

When IDA MCP is available, rerun:

- `lookup_funcs` for `0x00520ae7`, `0x00520af2`, `0x00520c60`, `0x00520afd`, and `0x00520b08`.
- `xrefs_to` for `0x00520ae7`, `0x00520af2`, `0x00520c60`, `0x0061f764`, `0x0061f7cc`, and `0x0061f7fc`.
- `disasm` or `get_bytes` for `0x00520ae7-0x00520afd` and `0x00520c60-0x00520c9b`.
- `callees` for `0x00520c60`.
- vtable/rdata scan for `0x0061f764-0x0061f808`.

## IDA Rename / Type / Comment Recommendations

IDA function names or comments:

- `0x00520ae7`: `ObjectImageButtonPane_dtor_adjustor_a0` or comment "ObjectImageButtonPane secondary destructor adjustor; this -= 0xa0; jumps to 0x00520c60".
- `0x00520af2`: `ObjectImageButtonPane_dtor_adjustor_a4` or comment "ObjectImageButtonPane tertiary destructor adjustor; this -= 0xa4; jumps to 0x00520c60".
- `0x00520c60`: `ObjectImageButtonPane_scalar_deleting_destructor`.
- `0x00544580`: `Pane::~Pane` / `PaneBaseTeardown`, not `TextButtonExControlPane`.
- `0x004f4ac0`: `OperatorDeleteWrapper`.
- `0x0041b6a0`: `GuardNoopRet` / guard no-op return stub.

Type/layout notes:

- `ObjectImageButtonPane` has vtable views at complete-object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Complete object size evidence from sibling wrapper is `0x150` / 336 bytes (Verified with `int_convert.py`).
- Destructor thunks are vtable-entry ABI artifacts for secondary/tertiary views, not methods to expose in source.

## Confidence And Remaining Uncertainty

Recommendation confidence: high.  
Score confidence: high for `86/91`, capped below final-audit level.

Remaining uncertainty:

- Live IDA MCP could not be rerun in this session.
- The final `ObjectImageButtonPane` class declaration and descriptor field names remain source-quality incomplete.
- Whether the original source explicitly declared an empty destructor or relied on an implicit destructor is not provable from this thunk range. This does not affect the target's no-code policy: either source shape would still make these adjustor thunks compiler-generated.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md`

Modified:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003M9","source_path":"executed-b-agent-research/B015/0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
