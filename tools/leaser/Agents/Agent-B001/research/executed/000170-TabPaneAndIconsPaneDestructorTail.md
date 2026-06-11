# 000170 TabPaneAndIconsPaneDestructorTail Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: accepted after supervisor validator `--apply` review.
- Final disposition: keep [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](../../../../../by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) parent-blank, `RECONSTRUCTABLE:FALSE`, and non-emitting. Exact children now carry the source ownership or compiler-artifact disposition.
- Required action: update `Supervisor_notes.md`, move this report to `research/executed`, and assign the next B001 target.
- Confidence: high for function boundaries, vtables, singleton ownership, destructor split, and parent assignment decisions; medium-high for final original source-file grouping between `TabPane.cpp` and `IconsPane.cpp`.

## Supporting Research

## Target

- Target UID: `000170`.
- Target path: `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`.
- Source queue/report row: `by-memory/-coverage-report.md` originally reported the broad range as a reconstructable `85%` mixed destructor/helper tail with blank parent because mixed `TabPane`/`IconsPane` ownership blocked direct assignment.
- Current supervisor classification: unassigned mixed range requiring split-first repair, exact children, parent-gate checks, validators, and final B001 report.
- Current scores and parent state:
  - Before B001-034: `000170` was `85/89`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - After B001-034: `000170` is `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - `TabPane` parent state: [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) remained `86/86`; [UID:0000OF][TabPane](../../../../../by-file/TabPane.md) remained `86/85`.
  - `IconsPane` parent state: [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md) changed from `82/82` to `85/85`; [UID:0000JZ][IconsPane](../../../../../by-file/IconsPane.md) changed from `86/82` to `86/85`.

## Executive Recommendation

Split ownership is resolved. The broad address range is a physical inventory only, not an original source owner. Assign source-bearing `TabPane` children to [UID:0000EB][TabPane](../../../../../by-class/TabPane.md), assign the `IconsPane` scalar deleting destructor child to [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md), and leave compiler-generated thunk/table children parent-blank and non-reconstructable.

The validator apply caveat is resolved. B001 correctly stopped before broader generated/project-level writes; the supervisor then ran targeted validator `--apply` scans over the aggregate, all twelve children, direct parent docs, `IconsPaneCore`, and `by-memory/-coverage-report.md`. All 19 scans exited 0 and reported `ok: 1`.

## Supervisor Active Recheck

- Supervisor instruction: continue B001-034 on `000170`; do not switch targets; resolve the mixed range into exact children or document an IDA-backed blocker.
- Generated/project-level correction: `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md` are read-only evidence sources. B001 must not edit them.
- Split-first result: every source-bearing or compiler-artifact subrange inside `0x004cf980-0x004cfe5f` now has an exact child page or explicit ignored padding in the aggregate inventory.
- Parent gate result: every assigned source-bearing child has a direct parent at or above the corrected `85/85` gate. Non-source artifacts remain parent blank.

## Inference Research Guidance Check

- `by-structure.md` says IDA/MCP is ground truth for addresses, xrefs, ownership, and behavior; generated/simroot docs are leads only. I used existing docs as hypotheses and relied on IDA MCP facts for the split.
- `by-structure.md` also says direct parent links must point to the narrowest true semantic owner and mixed aggregate pages should be `RECONSTRUCTABLE:FALSE` when exact children carry real source ownership.
- `inference_research.md` cautions that adjacency and consumer xrefs are weak by themselves. I treated address adjacency between `IconsPane` and `TabPane` as a layout clue, not ownership proof.
- Fact/inference split:
  - IDA fact: exact function boundaries, bytes, xrefs, vtable refs, global write sites, thunk disassembly.
  - Documentation evidence: existing `TabPane`, `IconsPane`, globals, and coverage pages already identified old-HUD class roles and open grouping questions.
  - Inference: original source likely had adjacent old-layout panel source, but direct ownership of exact methods follows class vtables/singletons rather than file adjacency.

## Evidence Standards Used

- Evidence types: IDA MCP `initialize/tools/list`, `py_eval`, `decompile`, disassembly, bytes, xrefs, callers/callees, vtable refs, singleton global writes/reads, padding spans, current by-* docs, generated coverage rows, and negative evidence for missing xrefs/pointer hits.
- Evidence strength: high for split and class ownership because each source child has vtable/singleton/caller/callee ties to one class. Confidence stays below final-audit range because tab labels, action helper names, and final old-HUD source grouping remain open.

## IDA MCP Facts

- Function/range facts:
  - `0x004cf980-0x004cf9ca` `sub_4CF980`: `TabPane` constructor; caller at `0x004f812d`; calls `0x00544460`; writes `g_pTabPane`.
  - `0x004cf9d0-0x004cf9f9` `sub_4CF9D0`: `TabPane` cleanup helper; no external xrefs found.
  - `0x004cfa00-0x004cfa01` `nullsub_30`: `TabPane` null virtual; vtable xref at `0x0061b514`.
  - `0x004cfa10-0x004cfb0a` `sub_4CFA10`: `TabPane` input handler; vtable xref at `0x0061b520`; calls resolver and action helpers.
  - `0x004cfb10-0x004cfb15` `sub_4CFB10`: `TabPane` false-return virtual; vtable xref at `0x0061b524`.
  - `0x004cfb20-0x004cfc5c`: raw helper bytes with real prolog and switch table; no IDA function object, no xrefs, no loaded-segment pointer hits.
  - `0x004cfc60-0x004cfd4d` `sub_4CFC60`: `TabPane` six-region action-code resolver; direct callers are inside `0x004cfa10`.
  - `0x004cfd6c-0x004cfd77` and `0x004cfd77-0x004cfd82`: `IconsPane` adjustor thunks to `0x004cfda0`.
  - `0x004cfd82-0x004cfd8d` and `0x004cfd8d-0x004cfd98`: `TabPane` adjustor thunks to `0x004cfe00`.
  - `0x004cfda0-0x004cfdff` `sub_4CFDA0`: `IconsPane` scalar deleting destructor.
  - `0x004cfe00-0x004cfe5f` `sub_4CFE00`: `TabPane` scalar deleting destructor.
  - `0x004cfe60` starts successor `IdleWatcher`, outside this target.
- Data/table/padding facts:
  - `0x004cfb15-0x004cfb20`: eleven `0xcc` bytes.
  - `0x004cfc40`: raw helper switch table with targets `0x004cfc22`, `0x004cfb38`, `0x004cfb5e`, `0x004cfb84`, `0x004cfbaa`, `0x004cfbd2`, `0x004cfbfa`.
  - `0x004cfc5c-0x004cfc60`: four `0xcc` bytes.
  - `0x004cfd4d-0x004cfd6c`: resolver alignment/jump-table bytes.
  - `0x004cfd98-0x004cfda0`: eight `0xcc` bytes.
  - `0x004cfe5f-0x004cfe60`: one `0xcc` byte.
- Xref facts:
  - `0x004cfc60` is called only from `0x004cfa10`.
  - `0x004cfb20` has no IDA function object, no xrefs, and no loaded-segment pointer hits.
  - Destructor thunks are reached from vtable entries, not normal source callers.
- Vtable/global/type facts:
  - `TabPane` vtables: `0x0061b4d0`, `0x0061b51c`, `0x0061b54c`; constructor/cleanup/destructor write these at offsets `0`, `0xa0`, and `0xa4`.
  - `IconsPane` vtables: `0x0061b448`, `0x0061b494`, `0x0061b4c4`; constructor/cleanup/destructor paths write these at the same offsets.
  - `g_pTabPane` / `0x0069adfc`: writes at `0x004cf9a4`, `0x004cf9ea`, `0x004cfe20`; reads at `0x0049e5e6`, `0x00504936`.
  - `g_pIconsPane` / `0x0069b41c`: writes at `0x004cf215`, `0x004cf27a`, `0x004cfdc0`; reads at `0x00504a07`, `0x0053da72`, `0x0053dec2`.
- Negative IDA facts:
  - No single function, vtable, singleton, or caller set covers the whole aggregate.
  - No external caller or pointer hit proves `0x004cfb20` is live as an independently entered function.
  - No evidence supports attaching `IconsPane` destructor glue to `TabPane` merely because it is physically interleaved.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004cf980-0x004cf9ca` | [UID:00034L][TabPaneConstructor](../../../../../by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) | `TabPane` constructor | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `85/88` | created, assigned |
| `0x004cf9d0-0x004cf9f9` | [UID:00034M][TabPaneCleanupHelper](../../../../../by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) | `TabPane` cleanup helper | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `85/88` | created, assigned |
| `0x004cfa00-0x004cfa01` | [UID:00034N][TabPaneNullVirtual](../../../../../by-memory/0x004cfa00-0x004cfa01.TabPaneNullVirtual.md) | empty virtual slot | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `86/90` | created, assigned |
| `0x004cfa10-0x004cfb0a` | [UID:00034O][TabPaneHandleInputEvent](../../../../../by-memory/0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent.md) | tab input/action dispatcher | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `86/88` | created, assigned |
| `0x004cfb10-0x004cfb15` | [UID:00034P][TabPaneFalseReturnVirtual](../../../../../by-memory/0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual.md) | false-return virtual | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `86/90` | created, assigned |
| `0x004cfb15-0x004cfb20` | padding | `0xcc` padding | false | none | ignored | documented in aggregate |
| `0x004cfb20-0x004cfc5c` | [UID:00034Q][TabPaneRawRectangleBuilder](../../../../../by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) | raw tab-rectangle helper/table evidence | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `85/86` | created, assigned with reachability caveat |
| `0x004cfc5c-0x004cfc60` | padding | `0xcc` padding | false | none | ignored | documented in aggregate |
| `0x004cfc60-0x004cfd4d` | [UID:00034R][TabPaneResolveActionCode](../../../../../by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md) | six-region action-code resolver | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `86/89` | created, assigned |
| `0x004cfd4d-0x004cfd6c` | [UID:00034S][TabPaneResolveActionCodeJumpTable](../../../../../by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md) | resolver jump-table/alignment bytes | false | blank | `86/90` | created, non-emitting |
| `0x004cfd6c-0x004cfd82` | [UID:00034T][IconsPaneDestructorAdjustorThunks](../../../../../by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md) | `IconsPane` adjustor thunks | false | blank | `86/90` | created, non-emitting |
| `0x004cfd82-0x004cfd98` | [UID:00034U][TabPaneDestructorAdjustorThunks](../../../../../by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md) | `TabPane` adjustor thunks | false | blank | `86/90` | created, non-emitting |
| `0x004cfd98-0x004cfda0` | padding | `0xcc` padding | false | none | ignored | documented in aggregate |
| `0x004cfda0-0x004cfdff` | [UID:00034V][IconsPaneScalarDeletingDestructor](../../../../../by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) | `IconsPane` scalar deleting destructor | true | [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md) | `85/88` | created, assigned |
| `0x004cfe00-0x004cfe5f` | [UID:00034W][TabPaneScalarDeletingDestructor](../../../../../by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) | `TabPane` scalar deleting destructor | true | [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `85/88` | created, assigned |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004cf980` | caller `0x004f812d` in `0x004f7d10` | `TabPane` is constructed from main UI initialization. |
| `0x004cf9d0` | no external xrefs found | cleanup helper is likely vtable/lifecycle local or indirect. |
| `0x004cfa00` | vtable slot `0x0061b514` | `TabPane` empty virtual. |
| `0x004cfa10` | vtable slot `0x0061b520`; calls `0x004cfc60` and action helpers | `TabPane` input dispatcher. |
| `0x004cfb10` | vtable slot `0x0061b524` | `TabPane` false-return virtual. |
| `0x004cfb20` | no xrefs, no pointer hits | raw helper retained as evidence; live reachability not proven. |
| `0x004cfc60` | called from `0x004cfa4c` and `0x004cfaae` inside `0x004cfa10` | resolver belongs to `TabPane` input handling. |
| `0x004cfd6c`, `0x004cfd77` | vtable slots `0x0061b494`, `0x0061b4c4` | `IconsPane` adjustor thunks. |
| `0x004cfd82`, `0x004cfd8d` | vtable slots `0x0061b51c`, `0x0061b54c` | `TabPane` adjustor thunks. |
| `0x004cfda0` | vtable `0x0061b448`, thunks `0x004cfd6c`/`0x004cfd77` | `IconsPane` scalar deleting destructor. |
| `0x004cfe00` | vtable `0x0061b4d0`, thunks `0x004cfd82`/`0x004cfd8d` | `TabPane` scalar deleting destructor. |
| `0x0069adfc` | constructor/cleanup/destructor writes and main UI reads | `TabPane` singleton lifecycle. |
| `0x0069b41c` | constructor/cleanup/destructor writes and option/main UI reads | `IconsPane` singleton lifecycle. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000EB][TabPane](../../../../../by-class/TabPane.md), [UID:0000OF][TabPane](../../../../../by-file/TabPane.md), and [UID:0000SE][g_pTabPane](../../../../../by-global/g_pTabPane.md) already model `TabPane` as an old-layout panel class and singleton owner.
  - [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md), [UID:0000JZ][IconsPane](../../../../../by-file/IconsPane.md), [UID:00016Z][IconsPaneCore](../../../../../by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md), and [UID:0000R6][g_pIconsPane](../../../../../by-global/g_pIconsPane.md) already model `IconsPane` as the old-layout icon-strip class and singleton owner.
- Existing docs that were stale, incomplete, or contradicted:
  - The target aggregate stopped at "mixed ownership" and left reconstructable children unassigned.
  - `IconsPane` class/file confidence was below the corrected parent gate even though the exact destructor evidence was available after split.
  - `IconsPaneCore` still pointed at broad `000170` for destructor glue rather than exact destructor children.
  - The manual by-memory coverage row still described `000170` as reconstructable and unassigned.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md` were treated as read-only after the supervisor correction.
  - `by-memory/-coverage-report.md` was manually updated under lease to record `000170` as a non-reconstructable split inventory.

## Ranked Ownership Analysis

### 1. TabPane exact children

- Evidence for: `TabPane` constructor/cleanup/destructor write `TabPane` vtables and `g_pTabPane`; input handler and resolver are mutually linked; vtable slots point to the null/false/input/thunk/destructor functions; raw rectangle helper matches the six `TabPane` tab rectangles.
- Evidence against: tab labels and final action-helper names remain unresolved; `0x004cfb20` has no IDA function object or reachability proof.
- Decision: assign reconstructable `TabPane` children to [UID:0000EB][TabPane](../../../../../by-class/TabPane.md). Keep `0x004cfb20` assigned as `TabPane` evidence with a clear reachability caveat.

### 2. IconsPane destructor child

- Evidence for: `0x004cfda0` writes `IconsPane` vtables, clears `g_pIconsPane`, calls shared pane cleanup, conditionally frees `this`, and is targeted by `IconsPane` adjustor thunks. The direct class and file pages now meet `85/85`.
- Evidence against: final source grouping with `TabPane` remains open, and older `IconsPane` core children outside this assignment still have lower historical scores.
- Decision: assign [UID:00034V][IconsPaneScalarDeletingDestructor](../../../../../by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) to [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md). Leave compiler thunks parent blank.

### 3. Compiler/linker artifacts

- Evidence for: destructor adjustor thunks are two-instruction `this` adjustments followed by tail jumps; resolver table bytes are switch/alignment data; padding bytes are `0xcc`.
- Evidence against: these artifacts still carry useful ABI/layout evidence and should not be ignored without documentation.
- Decision: create exact non-reconstructable, parent-blank child pages for thunk/table spans; keep padding documented in the aggregate inventory.

### 4. Single broad owner or new combined old-HUD file

- Evidence for: `TabPane` and `IconsPane` are adjacent old-layout HUD panels and share some action-helper families.
- Evidence against: the aggregate crosses class vtables, singleton lifecycles, source methods, raw helper evidence, compiler thunks, jump-table bytes, and padding. No single class/file/global is the direct semantic owner of all children.
- Decision: reject a direct parent claim for `000170`. Do not create a new file/grouping for this target. Keep the existing `TabPane.cpp` and `IconsPane.cpp` docs while leaving final original grouping as an open source-layout question.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none for this assignment.
- Likely full contents: no new owner is needed because existing `TabPane` and `IconsPane` class/file docs cover the source-bearing children.
- Candidate related items that belong: exact `00034L`-`00034W` children are now linked from the existing parent docs.
- Candidate related items rejected: `000170` itself is rejected as a source owner; compiler thunks/table bytes are rejected as source methods.
- Standalone, narrow, or broad source-file inference: current evidence supports narrow existing class ownership. A broader old-HUD controls file remains possible but is not necessary or strong enough to change ownership.

## Negative Evidence Summary

- Address adjacency alone did not drive ownership; the mixed range physically interleaves classes and compiler artifacts.
- Consumer/read xrefs to `g_pTabPane` or `g_pIconsPane` were recorded but not used as primary ownership proof; constructor/destructor writes and vtable stores are stronger.
- `0x004cfb20` was not promoted to a normal named method without caveat because IDA has no function object, xrefs, or pointer hits for its entry.
- Destructor adjustor thunks were not assigned as reconstructable source because by-structure classifies adjustor thunks as compiler/linker-generated artifacts.
- The broad aggregate was not assigned to `TabPane`, `IconsPane`, either by-file page, or a new mixed file because no single direct semantic parent covers all children.

## Final Recommendation

- Exact changes applied:
  - Created exact child pages for all source-bearing and artifact subranges in `000170`.
  - Converted `000170` into a non-emitting, parent-blank split inventory at `88/90`.
  - Updated `TabPane` class/file pages to link exact children without changing scores.
  - Updated `IconsPane` class/file pages to link exact destructor children and clear the corrected parent gate.
  - Updated `IconsPaneCore` neighboring/data notes to point at exact destructor children.
  - Updated `by-memory/-coverage-report.md` row for `000170`.
- Exact parent assignments applied or recommended:
  - `00034L`, `00034M`, `00034N`, `00034O`, `00034P`, `00034Q`, `00034R`, and `00034W` -> [UID:0000EB][TabPane](../../../../../by-class/TabPane.md).
  - `00034V` -> [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md).
  - `00034S`, `00034T`, `00034U`, and `000170` -> parent blank.
- Exact items left unassigned and why:
  - `000170`: mixed inventory, not a source owner.
  - `00034S`: switch/alignment bytes, not source-owned.
  - `00034T` and `00034U`: compiler adjustor thunks, not source-owned methods.
- Exact future work outside this assignment:
  - Name the tab action labels and action helper callees.
  - Resolve whether original source physically grouped `TabPane` and `IconsPane` in one old-HUD controls source file.
  - Supervisor validator apply/generated refresh has been completed for the targeted B001-034 files.

## Follow-Up Actions

- Supervisor actions: accepted after targeted validator `--apply`; update tracking and move this report to `research/executed`.
- A-agent actions: continue action-helper naming and final source-layout research for old-HUD panels; do not re-collapse the split into the broad aggregate.
- B001 future research actions: none required for this target unless the supervisor requests a follow-up on old-HUD source grouping.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `85/85+` child/parent gates, not final-audit `95+`.
- Remaining uncertainty: final UI tab labels, final helper names, and exact original `.cpp` grouping are still open, but they do not block the split or direct child ownership.

## Validator Results

- Commands run:
  - `python .\validator.py --mode file --file <each new child page> --uid-only --apply` for the 12 new child pages. These assigned stable UIDs `00034L` through `00034W` and exited 0.
  - `python .\validator.py --help` confirmed no no-stats/no-generated apply option exists.
  - `python .\validator.py --mode file --file <each of 19 target/child/parent/coverage files> --lock-timeout 60` dry-run after final cleanup. All 19 scans exited 0.
  - Supervisor follow-up: `python .\tools\validator.py --mode file --file <each of 19 target/child/parent/coverage files> --apply` from `E:\NTK\GhidraBridge\source-3\project-documentation`; all 19 scans exited 0 and reported `ok: 1`.
- Results:
  - UID-only apply results: children received stable UIDs and metadata headers.
  - Final dry-run scope: aggregate, 12 children, `TabPane` class/file, `IconsPane` class/file, `IconsPaneCore`, and `by-memory/-coverage-report.md`.
  - Final dry-run result: all 19 targeted file-mode scans exited 0.
- Apply-side resolution:
  - A previous `--uid-only --apply` validator pass reported `projected_stats_update project-level/-auto-completion-stats.md updated projected path completion section` despite being UID-only.
  - Final Git status also shows `auto-generated/-ag-memory-coverage.md` dirty; its diff contains validator-generated current-state rows including `00034L` through `00034W` plus other current validator state. This file was not manually edited.
  - Because the supervisor correction explicitly forbids B001 edits to generated and project-level files, B001 did not run further `--apply` scans after confirming the public help has no safe no-stats apply mode.
  - The supervisor-owned targeted `--apply` refresh has now been run. No unresolved validator errors remain for the targeted B001-034 files.

## Changed Files

- Created:
  - `by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md`
  - `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md`
  - `by-memory/0x004cfa00-0x004cfa01.TabPaneNullVirtual.md`
  - `by-memory/0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent.md`
  - `by-memory/0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual.md`
  - `by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`
  - `by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md`
  - `by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md`
  - `by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md`
  - `by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md`
  - `by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md`
  - `by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md`
- Modified:
  - `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`
  - `by-class/TabPane.md`
  - `by-file/TabPane.md`
  - `by-class/IconsPane.md`
  - `by-file/IconsPane.md`
  - `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
  - `by-memory/-coverage-report.md`
  - `tools/leaser/Agents/Agent-B001/research/000170-TabPaneAndIconsPaneDestructorTail.md`
- Validator side effect observed:
  - `project-level/-auto-completion-stats.md` was reported updated by validator during UID-only apply.
  - `auto-generated/-ag-memory-coverage.md` is dirty in Git after validator activity and contains generated current-state rows for the new children.
  - Neither generated/project-level file was manually edited by B001. The supervisor-owned targeted validator `--apply` refresh was run after acceptance review.
- Renamed: none.
- Moved to executed: pending supervisor archive step after this acceptance note.
