** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper Second-Pass Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003N9][by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) as `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, and below gate at `COMPLETION:82`, `CONFIDENCE:84`.
- Final disposition: no split, merge, reclassification, parent repair, canonical-owner assignment, or emitter route is justified by the second-pass evidence. The best forced semantic candidate remains [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) / [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md), but it still does not clear the owner/emitter gate.
- Required action: no by-* documentation edit is required. If the supervisor wants `by-memory/-coverage-report.md` to reflect this second pass, replace only the existing nested `0003N9` row under `0002PD` with the exact row in this report.
- Confidence: high that the bytes are an exact source-shaped ControlPane-like draw helper; high that current evidence does not prove a valid owner/emitter route; medium that the original source intent was a private ControlPane helper because that is inferred from field/layout context rather than proven by a caller, vtable slot, or pointer.

## Supporting Research

## Target
- Target UID: `0003N9`
- Target path: `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` currently lists `0003N9` as `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003N9`, reopened for `B002-0003N9-second-pass`.
- Prior report: `tools/leaser/Agents/Agent-B003/research/executed/0003N9-ControlPaneDrawActiveFrameHelper.md`.
- Current metadata: `COMPLETION:82`, `CONFIDENCE:84`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`.

## Executive Recommendation
- Keep the target visible as reconstructable NexusTK code-shaped bytes, but do not route it through ControlPane or ProgressBarControlPane yet.
- Do not add `EMITTER_UIDS:000038`. Under the current owner/emitter model, an emitter route needs a proven source-use/output context. This target is not a pooled literal/shared constant case, and no caller, table slot, pointer, or source-use context proves that `ControlPane.cpp` must emit it.
- Do not add `CANONICAL_OWNER:000038`. ControlPane is the strongest semantic candidate, but the child itself remains below `85/85` because the start is not an IDA function, has no external xrefs, has no raw pointer or branch target, and has no ControlPane/ProgressBar vtable slot.
- Do not split. The exact range is already half-open and source-shaped: previous function returns at `0x00494c49`, `0x00494c4a-0x00494c50` is `0xcc` padding, the helper bytes occupy `0x00494c50-0x00494c80`, and the `ProgressBarControlPane` constructor begins at `0x00494c80`.
- No IDA metadata repair is required before this ownership decision. Creating an IDA function at `0x00494c50` might improve decompilation, but it would not create the missing entry mechanism or prove owner/emitter routing.

## Supervisor Active Recheck
- Supervisor instruction: perform a fresh second-pass review of the current no-owner/non-emitting item and either prove a valid 85/85+ owner/emitter route, identify required split or IDA repair, or defend continued `CANONICAL_OWNER:NONE` with blank emitters.
- Result: the second pass strengthens the negative evidence but does not produce new positive routing evidence.
- Before score: `82/84`.
- After score recommendation: unchanged `82/84`. The confidence that no current route clears the gate increased, but the item score should not be inflated because source placement remains unproven.

## Inference Research Guidance Check
- `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`: ownership is the direct semantic owner, while emitters are generated-output routes that must lead to a valid source root.
- `by-structure.md` explicitly allows `RECONSTRUCTABLE:TRUE` with blank owner/emitter when NexusTK-owned source must be rebuilt but the final owner, emitter route, exact source file, or final C++ is not ready.
- Multiple emitters with `CANONICAL_OWNER:NONE` are valid for proven source-use contexts such as pooled literals or shared constants. This target is executable code with no proven consumer, not shared read-only data.
- `inference_research.md` supports best-effort inference from adjacency, layout, vtables, callers, and negative evidence. Here, adjacency/field evidence points toward ControlPane, while entrypoint and table evidence still fail the stricter assignment gate.

## Evidence Standards Used
- IDA MCP evidence: `server_health`, `idb_list`, `lookup_funcs`, `entity_query`, `disasm`, `get_bytes`, `xrefs_to`, `xref_query`, `decompile`, `callees`, `find_bytes`, and `make_signature_for_range`.
- Raw PE evidence: independent parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` to search absolute VA/RVA encodings and direct/conditional branch encodings into the helper start and plausible interior entry points.
- Documentation evidence: target page `0003N9`, prior B003 report, aggregate/container `0002PD`, `ControlPane` class/file/vtable pages, `ProgressBarControlPane` class/file/constructor pages, sibling `ControlPaneActivate` and `ControlPaneDeactivate` pages, generated no-owner rows, and tracker row.
- Negative evidence was weighted heavily because the only positive owner signal is semantic/adjacent field use, while every checked entry mechanism remains absent.

## IDA MCP Facts
- Active IDB: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x400000`, auto-analysis and Hex-Rays ready.
- Function/range facts:
  - `lookup_funcs` reports `sub_494C30` at `0x00494c30` size `0x1a`.
  - `lookup_funcs` reports no function at `0x00494c4a`, `0x00494c50`, `0x00494c51`, `0x00494c53`, or `0x00494c7e`.
  - `lookup_funcs` reports `sub_494C80` at `0x00494c80` size `0x12a`.
  - `entity_query` over `0x00494a80-0x00494ec0` lists modeled starts at `0x00494b50`, `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494bf0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, `0x00494c80`, `0x00494de0`, and `0x00494eb0`; it does not list `0x00494c50`.
- Body facts:
  - `disasm 0x00494c50` names the region `<no function>` but decodes a coherent body: save `ecx` in `esi`, test bytes `[esi+0x101]` and `[esi+0x102]`, `push 0x80`, call `0x004b9660`, clear `[esi+0x70]`, pass `esi+0x44`, call `0x004ba450`, then `pop esi; retn`.
  - `get_bytes 0x00494c40 size 0x60` confirms the previous helper return at `0x00494c49`, six `0xcc` bytes before `0x00494c50`, the exact `0x30` helper bytes, and the `0x00494c80` constructor prologue.
  - `make_signature_for_range 0x00494c50-0x00494c80` with operand wildcards disabled produced a unique signature:

```text
56 8B F1 80 BE 01 01 00 00 00 74 22 80 BE 02 01 00 00 00 74 19 68 80 00 00 00 E8 F1 49 02 00 8D 46 44 C6 46 70 00 50 8B CE E8 D2 57 02 00 5E C3
```

- Xref facts:
  - `xrefs_to 0x00494c50` returns zero xrefs.
  - `xrefs_to 0x00494c51` and `0x00494c53` returns only local sequential flow from the previous instruction inside the same raw body.
  - `xrefs_to 0x00494c7e` returns only internal short-branch/control-flow refs from `0x00494c5a`, `0x00494c63`, and `0x00494c79`.
  - `xref_query` for `0x00494c50` in both directions shows only the outgoing sequential code edge from `0x00494c50` to `0x00494c51`; no incoming external edge exists.
  - `decompile 0x00494c50` fails because IDA has no function at the address.
  - `callees 0x00494c50` reports `No function found`; the two direct callee addresses are visible only in raw disassembly.
- Callee-context facts:
  - `xref_query` to `0x004ba450` reports 49 code references; `0x00494c79` is one no-function caller among many UI drawing users.
  - `xref_query` to `0x004b9660` reports 319 code references. This makes the color/draw calls behavioral evidence, not ownership evidence.
- Vtable/global facts:
  - `entity_query` over `0x00617a80-0x00617bd4` lists only `ControlPane` vtable bases at `0x00617a90`, `0x00617af8`, `0x00617b28` and `ProgressBarControlPane` vtable bases at `0x00617b34`, `0x00617b9c`, `0x00617bcc`.
  - `get_bytes` over the ControlPane/ProgressBar vtable island includes entries for neighboring helpers such as `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, and `0x00494c30`, but no `0x00494c50` dword.
  - IDA `find_bytes` finds no little-endian absolute pointer or RVA encoding for `0x00494c50`, `0x00494c51`, `0x00494c53`, or `0x00494c7e`.

## Raw PE Facts
- File scanned: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE facts: image base `0x400000`; `.text` VA `0x1000`, raw offset `0x400`, raw size `0x20b600`; `.rdata` VA `0x20d000`.
- Target mapping: `0x00494c50` is RVA `0x00094c50`, file offset `0x94050`, section `.text`.
- Absolute pointer/RVA scans:
  - `0x00494c50`: VA pattern `50 4c 49 00` count `0`; RVA pattern `50 4c 09 00` count `0`.
  - Plausible interior entries `0x00494c51`, `0x00494c53`, and internal return label `0x00494c7e`: all VA/RVA pattern counts `0`.
  - Sanity check: neighboring `0x00494c30` VA pointer pattern count `46`, and neighboring `0x00494b80` VA pointer pattern count `43`, matching documented vtable/data fan-in for assigned ControlPane state helpers.
- Direct control-transfer scan over `.text`:
  - No `E8/E9` rel32 call/jump, `0F 80-8F` rel32 conditional jump, short `70-7F` conditional jump, `EB` short jump, or loop/jecxz branch targets `0x00494c50`, `0x00494c51`, or `0x00494c53`.
  - Sanity check: same scanner finds the two expected branches to `0x00494c7e` from inside the helper, one call to `0x00494c80` from `0x005472d7`, two jumps to `0x00494c30`, and six calls to `0x00494b80`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Six `0xcc` alignment bytes | FALSE | none | `100/strong` | Already ignored; no change. |
| `0x00494c50-0x00494c80` | [UID:0003N9][ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | Raw ControlPane-like frame helper | TRUE | none | `82/84` before, `82/84` after | Keep no-owner/no-emitter. |
| `0x00494c80-0x00494daa` | [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | ProgressBarControlPane constructor | TRUE | [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) | `86/90` | Successor boundary; does not absorb target. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00494c50` | IDA `xrefs_to`: none; raw PE branch scan: none | No external entrypoint to helper start. |
| `0x00494c51`, `0x00494c53` | only local sequential flow | No alternate interior entrypoint. |
| `0x00494c7e` | internal short-branch target only | Local skip label; not an entry. |
| `0x00494c6a -> 0x004b9660` | raw direct call | Selects draw state/color; shared callee with 319 code refs, not owner proof. |
| `0x00494c79 -> 0x004ba450` | raw direct call | Draws frame for `this+0x44`; shared callee with 49 code refs, not owner proof. |
| ControlPane vtable data | contains neighboring `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, `0x00494c30`, not `0x00494c50` | Rejects virtual-slot route. |
| ProgressBar vtable data | no `0x00494c50`; constructor starts after target at `0x00494c80` | Rejects successor-class route. |

## Documentation Evidence And IDA Status
- Existing docs supporting the no-route conclusion:
  - [UID:0003N9][target page](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) records the exact raw helper body, candidate ControlPane semantics, no function object, no xrefs, and below-gate status.
  - [UID:0002PD][ControlFamilyStateVirtualHelpers](../../../../../by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) is now a non-reconstructable mixed audit/container and lists `0003N9` as the only unresolved raw child.
  - [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) and [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md) list `0003N9` only as a candidate raw draw-state helper below gate.
  - [UID:0003J8][ControlPaneVtableData](../../../../../by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) and [UID:0003J9][ControlPaneVtables](../../../../../by-type/by-vtable/ControlPaneVtables.md) document the ControlPane vtable bases and do not route `0x00494c50`.
  - [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md), [UID:0000MT][ProgressBarControlPane](../../../../../by-file/ProgressBarControlPane.md), and [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) confirm a clean successor boundary at `0x00494c80`.
- Existing docs that are stale or superseded:
  - Older ButtonChoice/ButtonControl barrier wording that pulled this neighborhood into the button family has already been superseded by the `0002PD` split and C001 boundary repairs.
  - No current by-* page proves a function object, callsite, vtable slot, raw pointer, or recovered indirect-call target for `0x00494c50`.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Evidence for:
  - No IDA function object at the start.
  - No external IDA xrefs to the start.
  - No raw absolute VA/RVA pointer to the start or plausible interior entries.
  - No raw direct/conditional branch into the start or plausible interior entries.
  - No ControlPane or ProgressBar vtable slot contains `0x00494c50`.
  - The target is executable code, not pooled/shared literal data with independent source-use emitters.
- Evidence against:
  - Body semantics strongly resemble ControlPane drawing support: it tests `+0x101` and `+0x102`, uses rectangle `+0x44`, clears `+0x70`, and sits adjacent to ControlPane state helpers.
- Decision: accepted. This is the only route that preserves the evidence without turning plausible ControlPane semantics into an output route.

### 2. [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) / [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md)
- Evidence for:
  - Strongest semantic match.
  - `+0x101` is the visible-state byte controlled by neighboring ControlPane set/clear helpers.
  - `+0x102` is the active/focus-like byte controlled by neighboring ControlPane activate/deactivate helpers.
  - `+0x44` is the inherited pane rectangle used by neighboring invalidation/draw paths.
  - The helper is located immediately after assigned ControlPane state virtuals and before the ProgressBar constructor boundary.
- Evidence against:
  - No function object, no external xref, no raw branch/pointer, and no table/vtable slot.
  - The ControlPane docs can prove adjacent virtual helpers because they have vtable slots and/or callers; this raw helper lacks that ownership-grade signal.
  - Adding only `EMITTER_UIDS:000038` would still assert that ControlPane output must contain this helper, which is not proven.
- Decision: best forced candidate, but rejected for current owner/emitter assignment.

### 3. [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) / [UID:0000MT][ProgressBarControlPane](../../../../../by-file/ProgressBarControlPane.md)
- Evidence for:
  - Physical adjacency: the ProgressBar constructor begins at `0x00494c80`.
- Evidence against:
  - Clean half-open boundary at `0x00494c80`.
  - Target does not touch progress fields `+0xf8`, `+0xfa`, or `+0xfc`.
  - ProgressBar vtables do not contain `0x00494c50`.
  - ProgressBar constructor/draw/update pages already explain the successor class cluster without absorbing this helper.
- Decision: rejected.

### 4. ButtonControlPane / ButtonChoice / other later control-family owners
- Evidence for:
  - Same broad UI-control address neighborhood and later use of GrafPort frame drawing.
- Evidence against:
  - Repaired ButtonChoice core begins later at `0x00494eb0`.
  - The target is before the ProgressBar constructor and uses base ControlPane state bytes, not button/choice fields.
  - Current ButtonControl/ControlFamily docs explicitly separate this state-helper band from the later button/choice core.
- Decision: rejected.

### 5. New source file/grouping
- Proposed owner/name/path: none.
- Likely full contents: no standalone source file is justified. If the helper is ever proven reachable or source-declared, it would likely be a private ControlPane member/helper in `NexusTK/ui/core/ControlPane.cpp`.
- Candidate related items that belong: none newly recommended; adjacent exact children already route through ControlPane or ProgressBarControlPane when supported.
- Candidate related items rejected: ProgressBar constructor/draw/update helpers and ButtonChoice/ButtonControl raw helpers have separate documented ranges and source candidates.
- Decision: rejected as an actionable owner.

## Negative Evidence Summary
- Revisited prior B003 blockers:
  - No function object: still true.
  - No xrefs to start: still true.
  - No ControlPane/ProgressBar vtable slot: still true.
  - No raw pointer: still true, now checked for VA and RVA encodings for start and plausible interior entries.
  - No caller/entry mechanism: still true, now checked with an independent `.text` branch/call scan.
- Added second-pass negative evidence:
  - Direct/conditional branch scan finds zero transfers to `0x00494c50`, `0x00494c51`, or `0x00494c53`.
  - Scanner sanity checks find expected neighboring entries, so the zero result is meaningful rather than a broken scan.
  - Shared GrafPort callees are too broad to act as source-owner evidence.

## Final Recommendation
- Exact metadata recommendation:
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `EMITTER_POSITION_OPTIONAL:` blank
  - `COMPLETION:82`
  - `CONFIDENCE:84`
- Exact classification recommendation: keep as `raw-helper`, `reconstructable/no-owner`, non-emitting.
- Exact split recommendation: no split and no merge.
- Exact parent/source repair recommendation: none required.
- Exact IDA metadata recommendation: no required IDA repair before routing. Optional future IDA function creation at `0x00494c50-0x00494c80` would be an analysis convenience only, not ownership proof.
- Exact condition that would change the result: a real entry mechanism, such as an external call/jump, table/vtable slot, raw function pointer, recovered indirect-call target, or source/debug evidence proving this helper belongs in ControlPane output.

## Optional Coverage-Report Row For Supervisor Application

No coverage-report edit is required for metadata correctness because the current row already keeps `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`. If the supervisor wants the manual coverage row to record this second-pass raw PE scan, replace the existing `0003N9` row nested under [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](../../../../../by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md), immediately after the `0x00494c4a-0x00494c50` padding row, with:

```markdown
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable/no-owner : 82% : medium-strong : B002 second pass keeps this exact raw helper below gate: source-shaped ControlPane-like drawing body checks `this+0x101` and `this+0x102`, selects color `0x80`, clears `this+0x70`, and calls the GrafPort frame drawer for `this+0x44`, but live IDA and raw PE scans still find no IDA function object, zero external xrefs to `0x00494c50`, no ControlPane/ProgressBar vtable slot, no absolute VA/RVA pointer to the start or plausible interior entries, no direct/conditional branch into the start, and no caller/entry mechanism. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`.
```

## Follow-Up Actions
- Supervisor actions:
  - Mark tracker row `0003N9` complete with recommendation `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, unchanged `82/84`.
  - Optionally apply the coverage-report row refresh above.
- A-agent actions:
  - None required now. Do not emit C++ for this helper until the route and source placement are proven.
- B-agent future research:
  - Reopen only if a future IDA pass recovers an entrypoint, a new table/vtable child includes `0x00494c50`, or source/debug evidence appears.

## Confidence
- Recommendation confidence: high.
- Score confidence: keep `82/84`; the second-pass evidence improves confidence in the no-route decision, not in the source owner/emitter assignment.
- Remaining uncertainty: the original source may still have had a private ControlPane helper compiled into the object file without a discovered caller, but current binary evidence cannot distinguish that from orphaned/dead source-shaped code strongly enough to assign or emit.

## Validator Results
- Commands run: none.
- Results: no validator run was required because no by-* target, child, parent, generated, project-level, or coverage-report file was edited.
- Not used: no dry-run validator mode and no memory-range validator mode.

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B002/research/0003N9-ControlPaneDrawActiveFrameHelper-second-pass.md`
- Modified:
  - none outside this B002 research report.
- Renamed:
  - none.
- Moved to executed:
  - none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B002/0003N9-ControlPaneDrawActiveFrameHelper-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
