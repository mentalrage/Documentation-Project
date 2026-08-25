** TARGET-REPORT-UID:0001PG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001PG g_layoutContext_69B374 Memory Range Advanced-Scan Report

## Finalized Report / Current Recommendation

- Current recommendation: repair the target page text, not the UID/range/owner/emitter routing.
- Final disposition: this is a real scanner-visible document-label gap, plus a stale byte-evidence wording issue. It is not a stale filename, stale range, stale owner, stale emitter, or split/merge issue.
- Required action: add the exact `g_layoutContext_69B374` label to the target body/title text and correct the stale `0xff` byte claim to current zero-initialized `.data` virtual-tail evidence. Leave metadata and routing unchanged.
- Confidence: high for the repair recommendation, high for the current range and routing, medium-high for the provisional source-level variable name/type.

## Supporting Research

## Target

- Target UID: `0001PG`
- Target path: `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan
- Exact scanner complaint: `0x0069b374-0x0069b378.g_layoutContext_69B374.md: missing document text for g_layoutContext_69B374`
- Current supervisor classification: `error-repair-assigned` to Agent-B001 in `tools/leaser/Agents/Supervisor_notes.md`
- Current header state:

```text
UID:0001PG
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000L1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L1
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Current generated routing:

```markdown
| [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) | emits | `0000L1` | `0000L1` |  | no | `auto-generated/NexusTK/ui/MainUiGraph.cpp` | `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md` |  |
```

## Executive Recommendation

The target should remain routed as-is:

- Keep `CANONICAL_OWNER:0000L1` / [UID:0000L1] `MainUiGraph`.
- Keep `EMITTER_UIDS:0000L1`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep scores `86/90`.
- Keep final reconstruction C++ blank under the active 90/90+ code-entry gate, because the original variable name and pointed-to type remain provisional.

The page does need a text repair. `Select-String` over the target body found no literal `g_layoutContext_69B374`; the filename and generated row contain the token, but the scanner requires document text. The page also says the nearby bytes are all `ff`, but current IDA MCP and PE raw section mapping show this address range is zero-initialized virtual `.data` tail storage.

## Supervisor Active Recheck

The supervisor assignment asked whether the memory-ranges advanced-scan warning is only a scanner-visible label/title mismatch or a real documentation/range/name/owner/emitter issue.

Result:

- Scanner label issue: yes, real. The target body lacks exact `g_layoutContext_69B374` text.
- Documentation evidence issue: yes, real. The current page and coverage row contain stale `all ff` / `0xffffffff` byte wording for this slot.
- Range issue: no. `0x0069b374-0x0069b378` remains a clean four-byte slot.
- Filename issue: no. The current filename is correct and already contains the generated label.
- Metadata issue: no. Current owner/emitter/routing is still supported.
- Split/merge issue: no. Adjacent slots and the intervening unreferenced dword remain separate by xref sets and lifecycle evidence.

No by-* files or coverage report files were edited in this assignment, per user instruction.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` both affect the conclusion:

- The owner must be the direct semantic owner, not the heaviest consumer. Browser consumers alone do not make this a `Browser.cpp` or `BrowserControlPane` global.
- `EMITTER_UIDS` is output routing. Since the slot belongs to the MainUiGraph layer-slot family and [UID:0000L1] is the current file root, `EMITTER_UIDS:0000L1` remains appropriate.
- Address adjacency is weak by itself, but here adjacency is supported by startup writes, initialization passes, shutdown release/clear, and grouped slot xrefs.
- A consumer alias page such as [UID:0000QD] `g_pBrowserOverlayLayer` is not ownership proof. Current docs correctly treat it as ignored duplicate alias text.

Documentation assumptions treated as uncertain:

- The exact original source-level name `g_layoutContext_69B374` remains a scanner/generated label, not proven original source.
- The exact pointed-to class/type remains unresolved.
- The older `all ff` / `0xffffffff` initial-byte wording is contradicted by current live IDA MCP and raw PE mapping.

## Evidence Standards Used

Evidence checked:

- Current B001 `goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`
- Target page and related MainUiGraph/MainUiLayerSlots/browser alias docs
- Current generated memory coverage and memory tool reports
- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `get_global_value`, `insn_query`, and `entity_query`
- Read-only raw PE section mapping for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Git/lease state checks

The evidence is strong enough to recommend a text repair and stale byte wording correction. It is not strong enough to enter final C++ because the original source-level name and pointed-to type are still provisional.

## IDA MCP Facts

Session:

- IDA MCP session: `b001_0003gy`
- Input binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`

Function/range facts:

| Address | Function |
| --- | --- |
| `0x0046abd6` | `sub_46AA40`, size `0x2ca` |
| `0x0046acb0` | `sub_46AA40`, size `0x2ca` |
| `0x0046c4b7` | `sub_46C4B0`, size `0x99` |
| `0x0046c4df` | `sub_46C4B0`, size `0x99` |
| `0x0046d263` | `sub_46D050`, size `0x2d4` |
| `0x0046e460` | `sub_46E2A0`, size `0x216` |
| `0x0046e80d` | `sub_46E640`, size `0x27e` |
| `0x004a03ff` | `sub_49FEB0`, size `0x6c5` |
| `0x004f62c6`, `0x004f6356` | `sub_4F5FB0`, size `0x4e0` |
| `0x004f64d1`, `0x004f65b8`, `0x004f65c8` | `sub_4F6490`, size `0x215` |

Xref facts:

| Address | Direct xref count | Meaning |
| --- | ---: | --- |
| `0x0069b374` | 13 | This target slot. Browser/layout, alert/dialog, startup, and shutdown references. |
| `0x0069b370` | 0 | Intervening unreferenced dword remains separate. |
| `0x0069b378` | 14 | Following layer-slot tail item, not part of this target. |
| `0x0069b380` | 13 | Byte-sized active-dialog counter area, separate successor item. |

Current direct xrefs to `0x0069b374`:

```text
0x0046abd6  sub_46AA40
0x0046acb0  sub_46AA40
0x0046c4b7  sub_46C4B0
0x0046c4df  sub_46C4B0
0x0046d263  sub_46D050
0x0046e460  sub_46E2A0
0x0046e80d  sub_46E640
0x004a03ff  sub_49FEB0
0x004f62c6  sub_4F5FB0
0x004f6356  sub_4F5FB0
0x004f64d1  sub_4F6490
0x004f65b8  sub_4F6490
0x004f65c8  sub_4F6490
```

Startup/local instruction facts:

- `0x004f62c6`: `mov dword ptr unk_69B374, eax`
- `0x004f6356`: `push dword ptr unk_69B374`
- `0x004f635e`: `call sub_556CE0`

Shutdown/local instruction facts:

- `0x004f64d1`: `push dword ptr unk_69B374`
- `0x004f64dd`: `call sub_556D20`
- `0x004f65b8`: `mov ecx, dword ptr unk_69B374`
- `0x004f65c8`: `mov dword ptr unk_69B374, 0`

Representative browser/window consumer facts:

- `0x0046c4b7`: `push dword ptr unk_69B374`, then the function calls `sub_544C70`.
- `0x0046c4df`: `mov ecx, dword ptr unk_69B374`, then maps coordinates through `sub_4F14A0` / `sub_465730` before `MoveWindow`.

Representative alert/dialog consumer fact:

- `0x004a03ff`: `push dword ptr unk_69B374` in `sub_49FEB0`.

Data/name facts:

- `entity_query` over `0x0069b360-0x0069b388` returned no named IDA entities. IDA renders this as `unk_69B374`, not an applied final name.
- `get_global_value` returned `0x0` for `0x0069b370`, `0x0069b374`, `0x0069b378`, and `0x0069b380`.
- `get_bytes` returned zero bytes for `0x0069b360-0x0069b388`, including `0x0069b374`.

## PE / Raw Evidence

Read-only PE mapping of `NexusTK.exe`:

```text
image_base=0x00400000
.data VA=0x0066d000-0x0069ce24 RVA=0x0026d000 vsize=0x2fe24 raw_ptr=0x26ac00 raw_size=0xd800 raw_backed_VA_end=0x0067a800
VA 0x0069b360 section=.data file_off=0x298f60 raw_end=0x278400 backed=False value_bytes=zero-fill (RVA past section raw data)
VA 0x0069b370 section=.data file_off=0x298f70 raw_end=0x278400 backed=False value_bytes=zero-fill (RVA past section raw data)
VA 0x0069b374 section=.data file_off=0x298f74 raw_end=0x278400 backed=False value_bytes=zero-fill (RVA past section raw data)
VA 0x0069b378 section=.data file_off=0x298f78 raw_end=0x278400 backed=False value_bytes=zero-fill (RVA past section raw data)
VA 0x0069b380 section=.data file_off=0x298f80 raw_end=0x278400 backed=False value_bytes=zero-fill (RVA past section raw data)
```

This contradicts the target page sentence that says live IDA bytes for `0x0069b360-0x0069b388` are all `ff`. The current evidence supports zero-initialized pointer/global storage in the virtual tail of `.data`, later populated by startup and cleared by shutdown.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b364-0x0069b370` | [UID:00029M] `MainUiLayerSlotsHead` | Three preceding active layer/context slots | TRUE | [UID:0000T6] | `87/91` | Related sibling; stale zero-vs-ff wording appears likely. |
| `0x0069b370-0x0069b374` | [UID:00029N] `UnreferencedInitializedDword_69B370` | Intervening no-xref dword | FALSE | NONE | `90/91` | Separate gap; current IDA/PE evidence says zero-fill, not `0xffffffff`. |
| `0x0069b374-0x0069b378` | [UID:0001PG] this target | Shared layout/context slot | TRUE | [UID:0000L1] | `86/90` | Needs scanner label and byte-wording repair only. |
| `0x0069b378-0x0069b380` | [UID:00029O] `MainUiLayerSlotsTail` | Two following active layer/context slots | TRUE | [UID:0000T6] | `86/90` | Related sibling; stale zero-vs-ff wording appears likely. |
| `0x0069b380-0x0069b381` | [UID:0001PH] `g_activeDialogCount` | Active dialog counter | TRUE | related dialog/global docs | not regraded | Separate successor. |

The target does not need a split. It is already the exact four-byte slot with a separate no-xref predecessor and separate referenced successor slots.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f62c6` | startup writes `unk_69B374` | Startup stores the allocated slot object pointer. |
| `0x004f6356` / `0x004f635e` | startup pushes slot then calls `sub_556CE0` | Slot participates in the same layer-slot initialization sequence. |
| `0x004f64d1` / `0x004f64dd` | shutdown pushes slot then calls `sub_556D20` | Slot participates in shutdown detach/release. |
| `0x004f65b8` / `0x004f65c8` | shutdown reads slot and clears it to zero | Slot has lifecycle cleanup, then null reset. |
| `0x0046c4b7`, `0x0046c4df` | browser window bounds sync uses slot twice | Browser is a consumer of the shared context, not owner. |
| `0x004a03ff` | alert/dialog placement pushes slot | Non-browser UI consumer supports shared layout role. |
| `0x0069b370` | zero xrefs | Supports a separate gap before this target. |
| `0x0069b378` | 14 xrefs | Supports a separate following layer-slot child. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-file/MainUiGraph.md` lists `MainUiLayerSlots` as proposed content under `ui/MainUiGraph.cpp`.
- `by-global/MainUiLayerSlots.md` documents the slot family, startup/shutdown lifecycle, and alias cleanup.
- `by-global/g_pBrowserOverlayLayer.md` correctly treats the browser overlay name as an ignored duplicate/generated alias over this storage.
- `by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md` and `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md` cross-reference this target as part of the startup/shutdown slot family.
- `by-project-structure/proposed-source-tree.md` places `MainUiGraph.cpp` under `NexusTK/ui/`, matching the current generated route.

Existing docs that are stale or incomplete:

- The target page body lacks literal `g_layoutContext_69B374`, causing the scanner complaint.
- The target page says live bytes for `0x0069b360-0x0069b388` are all `ff`; current IDA MCP and PE raw evidence contradict this.
- `by-memory/-coverage-report.md` row for [UID:0001PG] repeats the `all-0xff` claim.
- Related sibling pages and `by-global/MainUiLayerSlots.md` also contain `0xffffffff` wording. Those broader pages are related evidence but outside the requested no-direct-edit scope for this report.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` correctly routes [UID:0001PG] as emitted through [UID:0000L1] to `auto-generated/NexusTK/ui/MainUiGraph.cpp`.
- `auto-generated/by-memory-tool-report.md` currently reports only the missing document text issue for this target, not a range overlap or metadata error.

## Ranked Ownership Analysis

### 1. [UID:0000L1] MainUiGraph

- Evidence for: startup/shutdown slot lifecycle in `sub_4F5FB0` / `sub_4F6490`, current source-tree placement under `NexusTK/ui/`, parent [UID:0000T6] `MainUiLayerSlots` owned by MainUiGraph, and mixed UI consumers beyond Browser.
- Evidence against: final original variable name and pointed-to type are still not proven; the slot might eventually model as a field of a recovered graph/context object rather than a standalone global.
- Decision: keep as current canonical owner/emitter route. The unresolved final type/name does not undermine the current direct MainUiGraph ownership at 86/90.

### 2. [UID:0000T6] MainUiLayerSlots

- Evidence for: direct family-level global page, neighboring slot inventory, and lifecycle grouping.
- Evidence against: current target metadata uses [UID:0000L1] directly rather than the narrower [UID:0000T6], while [UID:0000T6] itself routes through [UID:0000L1]. Changing the owner now would be a terminology cleanup choice, not required to clear the scanner warning.
- Decision: do not change this target's metadata in this assignment. If a later global-family normalization pass wants all individual slot memory pages to use [UID:0000T6] as canonical owner, it should update the full slot family consistently, not only [UID:0001PG].

### 3. [UID:0000HV] Browser / [UID:0000QD] g_pBrowserOverlayLayer alias

- Evidence for: browser/control-pane functions consume the slot, including the browser window bounds sync path.
- Evidence against: xrefs also include startup, shutdown, alert/dialog placement, and other layout consumers. Browser docs and ignored-global ledger already classify `g_pBrowserOverlayLayer` as a generated consumer alias, not source-owned storage.
- Decision: reject as owner. Browser remains a consumer only.

### 4. No-owner/non-emitting

- Evidence for: final original source variable name/type remains uncertain.
- Evidence against: lifecycle, direct writes, release/clear behavior, and source-tree owner context are strong enough for current MainUiGraph routing.
- Decision: reject. This item should not become `CANONICAL_OWNER:NONE` or blank-emitter.

### Proposed new file/grouping

No new file/grouping is recommended. [UID:0000L1] `MainUiGraph` and [UID:0000T6] `MainUiLayerSlots` already model the likely original source grouping well enough for this pass.

## Negative Evidence Summary

Checked and rejected:

- Filename/range mismatch: rejected. Filename, UID mapping, and generated coverage row all point to the intended `0x0069b374-0x0069b378` page.
- Missing document text as harmless scanner issue: rejected. The scanner is correct that the target body lacks the exact label.
- Owner/emitter problem: rejected. Current IDA evidence still supports MainUiGraph routing.
- Split/merge repair: rejected. `0x0069b370` has zero xrefs, `0x0069b374` has 13 xrefs, `0x0069b378` has 14 xrefs, and `0x0069b380` has separate active-dialog counter evidence.
- Browser ownership: rejected. Browser has consumers only.
- Final C++ entry: rejected under 90/90+ gate and unresolved final source-level type/name.

## Final Recommendation

Exact changes recommended for supervisor/A-agent application:

### Target page text repair

File:

```text
by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md
```

Replace the title:

```markdown
# 0x0069b374-0x0069b378 Shared Layout Context Slot
```

with:

```markdown
# 0x0069b374-0x0069b378 g_layoutContext_69B374 Shared Layout Context Slot
```

Add this bullet under `## Status` after `- Entity kind: main UI layout/context slot pointer.`:

```markdown
- Document label: `g_layoutContext_69B374` is the current filename/generated memory-range label for this shared slot; the final original source-level name and pointed-to type remain provisional.
```

Replace the current neighboring-storage byte sentence:

```markdown
Live IDA bytes for `0x0069b360-0x0069b388` are all `ff`, but the reference sets split the block into separate slots:
```

with:

```markdown
Current IDA MCP bytes for `0x0069b360-0x0069b388` are all `00`. A PE/raw section check confirms this area is zero-filled virtual `.data` tail storage beyond the initialized raw `.data` bytes (`.data` raw-backed VA end `0x0067a800`), but the reference sets still split the block into separate slots:
```

Append this change note:

```markdown
- 2026-06-14 B001 memory-range advanced-scan audit recommendation: add scanner-visible `g_layoutContext_69B374` document text and correct stale `all ff` byte wording to current zero-initialized `.data` virtual-tail evidence. Live IDA still confirms the exact 13-reference set, startup/shutdown lifecycle, consumer grouping, and neighboring boundaries; keep `CANONICAL_OWNER:0000L1`, `EMITTER_UIDS:0000L1`, `RECONSTRUCTABLE:TRUE`, and blank C++.
```

### Shared coverage row

Do not directly edit `by-memory/-coverage-report.md` from this report. If the supervisor applies a shared-row update, replace the current [UID:0001PG] row with:

```markdown
    - [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) 0x0069b374-0x0069b378 | global layer/context slot | g_layoutContext_69B374 : reconstructable : 86% : strong : MainUiGraph layout/context slot; current IDA MCP and PE/raw checks confirm zero-initialized `.data` virtual-tail storage at `0x0069b374`, exactly 13 refs, startup write/initializer, shutdown release/cleanup/clear, browser/alert/layout consumers, and clean neighboring slot boundaries.
```

### Metadata and route

No metadata change recommended:

```text
CANONICAL_OWNER:0000L1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L1
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

### Related follow-up outside this exact target

The same current IDA/PE evidence suggests stale `0xffffffff` / `all ff` byte wording in related MainUiLayerSlots sibling pages and the global overview:

- [UID:00029M] `0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- [UID:00029N] `0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md`
- [UID:00029O] `0x0069b378-0x0069b380.MainUiLayerSlotsTail.md`
- [UID:0000T6] `by-global/MainUiLayerSlots.md`

Those should be handled by a focused follow-up/owner pass rather than silently changed under this no-direct-edit assignment.

## Follow-Up Actions

Supervisor actions:

- Apply the target page text repair above.
- Apply the [UID:0001PG] shared coverage row replacement if desired for byte-evidence consistency.
- Regenerate `auto-generated/by-memory-tool-report.md` after target repair to verify the warning clears.

A-agent actions:

- Validate the target page after applying the edit:

> Executable block R001 was removed from this report and preserved verbatim in [0001PG-g_layoutContext_69B374-memory-range-report-removed.md](0001PG-g_layoutContext_69B374-memory-range-report-removed.md). The archived block is non-authoritative and must not be executed.

- If the shared coverage row is updated, validate the shared coverage report as normally required by supervisor workflow.

B001 future research actions:

- If assigned a broader slot-family cleanup, recheck and repair the zero-fill wording across [UID:00029M], [UID:00029N], [UID:00029O], and [UID:0000T6].

## Confidence

- Recommendation confidence: high.
- Score confidence: current `86/90` remains defensible after the text repair because xrefs, lifecycle, and route evidence are strong.
- Remaining uncertainty: final original variable name, exact pointed-to type, and whether the original source declared these as standalone globals or fields behind a recovered UI graph/context object.

## Validator Results

- Commands run: no validator command was run because this assignment explicitly prohibited direct by-* edits and this pass created only the Agent-B001 research report.
- Results: not applicable.
- Unresolved validator warnings/errors: none introduced by this pass.
- No dry runs were used.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0001PG-g_layoutContext_69B374-memory-range-report.md`

Modified:

- None by this pass outside the B001 research report.

Renamed:

- None.

Moved to executed:

- None.

At report time, `git status` already showed existing modifications to `by-memory/-coverage-report.md` and `by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md`. This pass did not modify or revert those files.

## Lease State

No lease was acquired because no leased-scope file was edited. Final lease check of `tools/leaser/Agents/current_leases.md` found no `B001`, `0001PG`, `0069b374`, or `g_layoutContext_69B374` match.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001PG-g_layoutContext_69B374-memory-range-report.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001PG"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001PG-g_layoutContext_69B374-memory-range-report-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001PG-g_layoutContext_69B374-memory-range-report.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001PG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
