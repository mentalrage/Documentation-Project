## Finalized Report / Current Recommendation

- Target: [UID:0000WT] `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`
- Assignment: B001-006, from `Supervisor_notes.md` `split-recheck-assigned`
- Current recommendation: accept the split repair. Keep `0000WT` as a reviewed non-reconstructable/ignored mixed aggregate container with blank parent; use the exact child pages for real source ownership or ignored runtime/generated classification.
- Recommended status/classification: `reviewed-split-container-nonreconstructable; exact children resolved/raised where justified`
- Confidence: high, 88/100 for the aggregate/container recommendation. The exact function inventory, gaps, child owners, and ignored spans are IDA-backed; final original source names remain below final-source certainty.
- Concrete next action for A-agents/supervisor: remove `0000WT` from reconstructable-unassigned/split-recheck queues. Treat `0002DV`, `0002DX`, `0002DZ`, and `0002E3` as assigned through their direct parents; treat `0000WT`, `0002DY`, `0002E1`, and `0002E2` as non-reconstructable/ignored.
- Report state: final for B001-006. No blocker remains for the aggregate. A later unrelated parent-chain audit may decide whether [UID:0000NY] `SpecializedButtonPanes` should itself be raised above the file-parent gate, but that does not block `0002DZ` because its direct parent [UID:000022] now clears `85/85`.

## Supporting Research

### Scope And Workflow

B001 followed the split-first workflow for the mixed by-memory target. Existing documentation was treated as prior inferred evidence, not ground truth. No lease commands were used because the user explicitly gave a temporary lease override for this assignment.

No new child pages were created. The current split already had exact child pages for every real source-bearing or runtime helper range, and `by-memory/-ignored.md` already covered the internal padding, thunk, generated-wrapper, and runtime helper spans. The required work was to repair stale child scores/parents, parent-gate evidence, aggregate classification, ignored ledger coverage for the aggregate itself, and manual coverage rows.

### IDA MCP Binary Facts

Fresh IDA MCP evidence on 2026-06-10 confirmed the function inventory inside `0x00421310-0x004216cb`:

| Range | IDA function | Fact |
| --- | --- | --- |
| `0x00421310-0x00421362` | `sub_421310` | `SimpleUString` SSO-7 clear/reset helper. |
| `0x00421370-0x00421375` | `sub_421370` | One-instruction thunk: `jmp sub_544580`. |
| `0x00421380-0x004213e1` | `sub_421380` | Fitting-room `0xb4` byte entry nested-vector release helper. |
| `0x004213e2-0x0042140e` | `sub_4213E2`, `sub_4213ED`, `sub_4213F8`, `sub_421403` | Four `this` adjustor thunks into deleting destructors. |
| `0x00421410-0x00421477` | `sub_421410` | `FittingRoomListPane` scalar deleting destructor. |
| `0x00421480-0x004214bb` | `sub_421480` | Shared scroll-pane-family scalar deleting destructor wrapper. |
| `0x004214c0-0x004214c5` | `sub_4214C0` | `return 22` control-type virtual helper. |
| `0x004214d0-0x004214f7` | `sub_4214D0` | Fitting-room entry range release helper. |
| `0x00421500-0x0042150a` and `0x00421510-0x0042151a` | `sub_421500`, `sub_421510` | MSVC/Dinkumware vector throw helpers. |
| `0x00421520-0x00421584` | `sub_421520` | Shared aligned dword-array allocation helper. |
| `0x00421590-0x004216cb` | `sub_421590` | `SimpleUString` counted wide assign/grow helper. |

IDA byte audit confirmed all gaps as `0xcc`: `0x00421362-0x00421370`, `0x00421375-0x00421380`, `0x004213e1-0x004213e2`, `0x0042140e-0x00421410`, `0x00421477-0x00421480`, `0x004214bb-0x004214c0`, `0x004214c5-0x004214d0`, `0x004214f7-0x00421500`, `0x0042150a-0x00421510`, `0x0042151a-0x00421520`, and `0x00421584-0x00421590`.

Selected IDA ownership anchors:

- `0x00421310`: decompile reads capacity at `this + 0x14`, frees heap storage when capacity is at least `8`, then writes length `0`, capacity `7`, and UTF-16 NUL. `xrefs_to` reports 83 xrefs to the function start across 22 caller functions.
- `0x00421590`: decompile performs counted UTF-16 assignment/growth over SSO-7 fields, with `length | 7`, 1.5x growth check, allocator/memmove/free/string-too-long dependencies, and 74 xrefs to the function start across 16 caller functions.
- `0x00421410`: xrefs are the two adjustor-thunk jumps and primary vtable slot `0x0060dd10 -> 0x00421410`; IDA names that slot `??_7FittingRoomListPane@@6B@`. Disassembly writes three `FittingRoomListPane` vtables, releases child at `+0x11c`, calls pane-base teardown, then handles scalar-delete flags.
- `0x00421480`: no class-specific field/state; decompile and disassembly show pane-base teardown plus optional delete wrapper. Vtable refs span `FittingRoomScrollPane`, `RankingEventScrollPane`, `ScrollPane`, `ScrollSpellInventoryPane`, `ScrollNewGroupPane`, `ScrollCollectionPane`, `ScrollInventoryPane`, and `ScrollVolumePane`.
- `0x004214c0`: decompile returns constant `22`/`0x16`, no callees. Xrefs are vtable data refs, including `0x0062e9fc -> 0x004214c0` for `CheckBoxTextControlPane`.
- `0x00421520`: decompile/disassembly show `count * 4`, direct `operator new` below `0x1000`, zero-size null return, large overreserve by `35`, 32-byte alignment, and raw pointer at `aligned[-1]`. `xrefs_to` reports 10 cross-module vector/template callers.

### Child Map And Actions

| Child/range | Before | After | Direct owner/classification |
| --- | --- | --- | --- |
| [UID:0000WT] `0x00421310-0x004216cb` aggregate | `82/86`, `RECONSTRUCTABLE:TRUE`, blank parent | `85/88`, `RECONSTRUCTABLE:FALSE`, blank parent | Ignored/non-emitting mixed aggregate container. |
| [UID:0002DV] `0x00421310-0x00421362.SimpleUStringClear` | `82/88`, parent `0000OB` | `85/88`, parent `0000D9` | Direct `SimpleUString` SSO-7 method; emits through `StringUtil`. |
| `0x00421362-0x00421380` padding/thunk | ignored ledger rows existed | unchanged | Padding plus pane-base thunk in `-ignored.md`. |
| [UID:0002DW] `0x00421380-0x004213e1.FittingRoomDialogItemEntryRelease` | page already `85/88`, manual coverage stale `84%` | page unchanged, coverage row synced to `85%` | File-level [UID:0000JE] `FittingRoom`. |
| `0x004213e2-0x0042140e` adjustor thunks | ignored ledger rows existed | unchanged | Compiler-generated vtable adjustor thunks. |
| [UID:0002DX] `0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor` | `84/88`, parent `000053` but child below gate | `85/88`, parent `000053` | Direct [UID:000053] `FittingRoomListPane`; parent now `85/87`. |
| [UID:0002DY] `0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor` | `82/88`, false, blank parent | `85/90`, false, blank parent | Ignored shared generated scroll-pane wrapper. |
| [UID:0002DZ] `0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType` | `88/92`, parent `000022`; parent below active gate | child unchanged, parent [UID:000022] raised to `85/87` | Direct [UID:000022] `CheckBoxTextControlPane`. |
| [UID:0002E0] `0x004214d0-0x004214f7.FittingRoomDialogItemEntryRangeRelease` | `85/88`, parent `0000JE` | unchanged | File-level [UID:0000JE] `FittingRoom`. |
| [UID:0002E1] `0x00421500-0x0042151a.MsvcVectorThrowHelpers` | `86/90`, false | unchanged | Ignored MSVC/Dinkumware vector support. |
| [UID:0002E2] `0x00421520-0x00421584.AllocateAlignedDwordArray` | `82/90`, false | `85/90`, false | Ignored runtime/STL-style aligned vector allocator support. |
| [UID:0002E3] `0x00421590-0x004216cb.SimpleUStringAssignWideCount` | `84/88`, parent `0000OB` | `85/88`, parent `0000D9` | Direct `SimpleUString` SSO-7 method; emits through `StringUtil`. |

### Ownership Inference

Facts:

- There is no IDA or documentation evidence for one source-level item spanning `0x00421310-0x004216cb`.
- The range interleaves string class helpers, fitting-room item cleanup helpers, vtable-only destructor glue, a reusable checkbox-control method, and MSVC/STL vector support.
- Exact source-bearing children now have direct parents that clear `85/85`.
- Generated/runtime children are documented as non-reconstructable and represented in the ignored ledger.

Inference:

- The aggregate is an address-neighborhood artifact from earlier documentation, not an original source owner. The strongest action is to keep it as a split checklist/audit container and mark the aggregate itself non-reconstructable.
- No new source file or grouping is warranted for the aggregate. The likely complete contents of any proposed aggregate file would immediately cross unrelated owners (`StringUtil`, `FittingRoom`, `FittingRoomListPane`, `CheckBoxTextControlPane`, runtime/STL), which is exactly the evidence against creating such a file.

Rejected alternatives:

- Assign aggregate to `StringUtil`: rejected because only endpoint helpers `0x00421310` and `0x00421590` are SSO-7 string helpers; middle functions are fitting-room, checkbox, thunk, and runtime code.
- Assign aggregate to `FittingRoom`: rejected because endpoint SSO helpers, checkbox method, and runtime/STL helpers do not belong to fitting-room source.
- Assign aggregate to `FittingRoomListPane`: rejected because only `0x00421410` and some related entry cleanup/vector helpers are fitting-room/list-pane evidence; most of the range is unrelated.
- Create new `EarlySimpleUStringAndAdjacentHelperIsland.cpp`: rejected because the proposed contents would be a mixed address container, not a plausible source unit.

### Files Changed

- `by-class/CheckBoxTextControlPane.md`
- `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`
- `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`
- `by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md`
- `by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md`
- `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md`
- `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md`
- `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`

Validator side effects updated validator-managed/autogen state, including `auto-generated/-ag-memory-coverage.md`, where the relevant rows now show `0000WT` as `not_reconstructable`, `0002DV`/`0002E3` assigned to `0000D9`, `0002DX` assigned to `000053`, `0002DZ` assigned to `000022`, and `0002DY`/`0002E1`/`0002E2` as `not_reconstructable`.

### Validation

Ran targeted validator file scans with `--apply` for:

- `by-class/CheckBoxTextControlPane.md`
- `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`
- `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`
- `by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md`
- `by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md`
- `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md`
- `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md`
- `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`

All targeted validator commands exited successfully. Post-validation generated coverage rows were checked for the relevant UIDs and matched the intended state.

### Collision/Lease Note

No leases were created or released per the user's temporary lease override. I did not detect an available Git repository at `E:\NTK\GhidraBridge` or `source-3` for a normal dirty-worktree collision check, so collision risk was controlled by limiting edits to the current target split scope and validating the changed files directly.
