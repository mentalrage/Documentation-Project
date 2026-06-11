# 0002EE FittingRoomCategoryStorageAndStringHelpers

## Finalized Report / Current Recommendation

- Target: [UID:0002EE] `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
- Current recommendation: keep the original aggregate unassigned and non-reconstructable as a mixed address-container. Exact child pages carry all source/ignored ownership.
- Recommended status/classification: `COMPLETION:85`, `CONFIDENCE:87`, `RECONSTRUCTABLE:FALSE`, blank `AUTOGEN_PARENT_UID`.
- Confidence: high for the mixed-container recommendation, `87/100`. IDA MCP confirms the function boundaries, caller split, string/vector/DAT/helper mixture, and ignored spans; no single direct parent covers the whole physical island.
- Concrete next action for A-agents/supervisor: accept the split-first repair. Do not assign the aggregate to `FittingRoom` or create a new aggregate owner. Use the exact child ownership map below.
- Report state: final for B001-005. Remaining work is normal source-quality naming/layout refinement on exact children, not a blocker for aggregate classification.

Key child repairs applied:

- [UID:0002U5] `0x00423060-0x00423204` raised `82/88 -> 85/88` and rerouted from broad `StringUtil` to direct [UID:0000D9] `SimpleUString`; [UID:0000OB] `StringUtil` remains the broad file parent.
- [UID:0002U6] `0x00423210-0x004233ea` raised `82/88 -> 85/88`, parent retained as [UID:000051] `FittingRoomDialogItemState`.
- [UID:0002UG] `0x00423960-0x00423a57` raised `84/90 -> 85/90`, remains `RECONSTRUCTABLE:FALSE` and unassigned; a distinct ignored-ledger entry was added.
- [UID:0002EE] aggregate changed `RECONSTRUCTABLE:TRUE -> FALSE` because it is not a source unit after exact child routing.

Review fix, 2026-06-10: supervisor review found stale manual rows in `by-memory/-coverage-report.md`. B001 reacquired a lease and synced the `0002EE`, `0002U5`, `0002U6`, and `0002UG` rows to the repaired docs/generated coverage; B001 also synced adjacent stale `0002U8` from `82%` to `85%` because its child page already clears `85/88`.

## Supporting Research

## Assignment Scope

B001-005 targeted one aggregate:

- [UID:0002EE] `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`

The updated B001 goal required split-first execution before any master recommendation. I treated existing docs as prior hypotheses and rechecked the low-score/ambiguous children with IDA MCP. I did not create new child pages because the existing `0002U4` through `0002UI` children cover every modeled function in the aggregate. I updated existing child/source-owner docs where needed to make the split valid under the `85/85` child and direct-parent gate.

## Split Result

| Item | Range | Before | After | Reconstructable | Parent/action |
| --- | --- | ---: | ---: | --- | --- |
| [UID:0002EE] | `0x00423000-0x00423af4` | `85/87`, `TRUE` | `85/87`, `FALSE` | no | Mixed container; parent stays blank. |
| [UID:0002U4] | `0x00423000-0x0042305c` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002U5] | `0x00423060-0x00423204` | `82/88`, parent [UID:0000OB] | `85/88`, parent [UID:0000D9] | yes | Direct `SimpleUString` SSO-7 helper; `StringUtil` remains broad file parent. |
| [UID:0002U6] | `0x00423210-0x004233ea` | `82/88` | `85/88` | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002U7] | `0x004233f0-0x00423465` | `85/88` | unchanged | yes | [UID:00003K] `DATIndexVector`. |
| [UID:0002U8] | `0x00423470-0x0042365d` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002U9] | `0x00423660-0x004236d7` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002UA] | `0x004236e0-0x00423710` | `85/88` | unchanged | yes | [UID:0000OB] `StringUtil`. |
| [UID:0002UB] | `0x00423710-0x00423777` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002UC] | `0x00423800-0x00423805` | `88/92` | unchanged | no | Compiler jump thunk, unassigned/ignored. |
| [UID:0002UD] | `0x00423810-0x00423860` | `85/88` | unchanged | yes | [UID:0000P3] `VectorHelpers`. |
| [UID:0002UE] | `0x00423870-0x004238e3` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002UF] | `0x004238f0-0x00423952` | `86/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002UG] | `0x00423960-0x00423a57` | `84/90` | `85/90` | no | Generic SSO-15 byte-string support, ignored/unassigned. |
| [UID:0002UH] | `0x00423a60-0x00423a8d` | `86/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |
| [UID:0002UI] | `0x00423a90-0x00423af4` | `85/88` | unchanged | yes | [UID:000051] `FittingRoomDialogItemState`. |

Non-page spans are covered in [UID:0000VN] `by-memory/-ignored.md`: internal padding, `0x00423780-0x00423796`, `0x004237a0-0x004237f2`, and `0x00423800-0x00423805`. B001 added a distinct ignored row for [UID:0002UG] because it is a real function but not handwritten NexusTK source.

## IDA MCP Evidence

### Aggregate and Existing Exact Children

Current IDA MCP caller/callee checks confirm mixed ownership across the island:

- `0x00423000` has caller `0x00422d8b` in `sub_422BA0` and callee `0x00423a60`; this supports `FittingRoomDialogItemState` category lookup ownership.
- `0x004233f0` has callers `0x00423be9` and `0x00423c15` in `sub_423B00` and no direct callees; this supports the existing DAT/vector-adjacent routing rather than fitting-room aggregate ownership.
- `0x00423470` has callers `0x00422dd3` and recursive `0x00423610`; callees include `0x00423a90`, `0x00423c40`, recursive `0x00423470`, `0x00423660`, `0x00423b00`, and C++ throw support.
- `0x00423660` is called from `0x0042364f` inside `sub_423470` and calls `0x00423a90`.
- `0x004236e0` has broad non-fitting-room caller fan-in and calls only `0x0041b9a0` plus `___stdio_common_vswprintf_s`; this supports `StringUtil`.
- `0x00423710`, `0x00423870`, `0x004238f0`, `0x00423a60`, and `0x00423a90` route through fitting-room item-state lifecycle/category paths.
- `0x00423810` has vector-storage cleanup callers and runtime free/error callees, matching the existing `VectorHelpers` routing.

This binary spread is the core reason the aggregate cannot have a single source parent.

### 0002U5 Direct Parent Repair

IDA MCP `analyze_funcs` on `0x00423060` reports `sub_423060`, exact range `0x00423060-0x00423204`, size `0x1a4`.

Facts:

- Decompilation shows a `this` object with length at `+0x10`, capacity at `+0x14`, inline threshold `8`, UTF-16 code-unit writes, `(length + 1) | 7` growth, `(capacity + 1) * 2` allocation through `0x00423d00`, old-content `_memmove`, old-heap release through `0x005c7526`, and cleanup through `0x00421310`.
- `callers` reports exactly two direct call sites: `0x00421bc5` in fitting-room catalog conversion and `0x00581d22` in startup update-check conversion.
- `callees` reports `_memmove`, `__CxxThrowException@8`, `0x0041b6d0`, invalid-parameter abort, `0x00423d00`, `0x005c7526`, and `0x00421310`.

Inference:

- This is not a fitting-room entry-part vector helper despite its old filename. It is shared SSO-7 `SimpleUString` narrow-byte-range to UTF-16 append/grow support.
- Direct parent should be [UID:0000D9] `SimpleUString`, not the broader [UID:0000OB] `StringUtil`, because [UID:0000D9] is `85/87` and explicitly owns the SSO-7 layout. `StringUtil` remains the source-file parent of the class at `87/88`.

### 0002U6 Gate Repair

IDA MCP `analyze_funcs` on `0x00423210` reports `sub_423210`, exact range `0x00423210-0x004233ea`, size `0x1da`.

Facts:

- `callers` reports one call: `0x00421e89` in `sub_421A40` / [UID:0002E4] `FittingRoomCatalogEntryFromJson`.
- Decompilation shows a begin/end/capacity vector of 6-byte records, pointer-delta division by six, `0x2aaaaaaa` element cap, growth by `max(size + 1, capacity + capacity / 2)`, dword-plus-word record copy, old-storage free, and triplet update.
- `callees` reports `operator new`, `0x005c7526`, invalid-parameter abort, and vector-too-long helper `0x00421500`.

Inference:

- The function is container-shaped, but the only direct ordinary caller and storage context are fitting-room catalog entry parsing. [UID:000051] `FittingRoomDialogItemState` is the best direct parent and clears `86/88`.

### 0002UG Ignored Function Repair

IDA MCP `analyze_funcs` on `0x00423960` reports `sub_423960`, exact range `0x00423960-0x00423a57`, size `0xf7`.

Facts:

- `callers` reports fitting-room-local uses at `0x00422130`, `0x00422147`, `0x00422157`, `0x0042229e`, `0x00422aa4`, and `0x00422f6d`.
- Decompilation shows a 24-byte SSO-15 byte-string object with length at `+0x10`, capacity at `+0x14`, inline threshold `0x10`, growth by `length | 0x0f`, allocation through `0x0041b6e0`, old-heap release, and large-allocation validation.
- `callees` reports `_memmove`, `_memmove_0`, `0x0041b6d0`, `0x0041b6e0`, `0x005c7526`, and invalid-parameter abort.

Inference:

- Even though all direct callers are fitting-room, the body is generic small-string support and matches existing runtime/string support docs [UID:0002CZ] and [UID:0000WN]. It should remain `RECONSTRUCTABLE:FALSE`, blank parent, with an ignored-ledger row.

## Ranked Owner Candidates for the Aggregate

1. Exact-child ownership with non-reconstructable aggregate container - selected.
   - For: matches IDA caller/callee evidence and by-structure split-first rules; each real child has a more specific owner or ignored classification.
   - Against: requires consumers to follow child pages rather than the convenience aggregate.

2. [UID:0000JE] `FittingRoom` / [UID:000051] `FittingRoomDialogItemState` as aggregate parent - rejected.
   - For: many category-storage and lifecycle children are fitting-room item-state local.
   - Against: fails direct-owner rule for [UID:0002U5], [UID:0002U7], [UID:0002UA], [UID:0002UD], [UID:0002UC], and [UID:0002UG]. Physical adjacency is not source ownership.

3. [UID:0000OB] `StringUtil` as aggregate parent - rejected.
   - For: owns [UID:0002UA] and broad source file for [UID:0002U5] through [UID:0000D9].
   - Against: does not own fitting-room category lookup/tree/lifecycle helpers or DAT/vector children.

4. New `FittingRoomCategoryStorageHelpers` file/grouping - rejected.
   - For: would name the physical island.
   - Against: likely contents would improperly include shared SimpleUString/StringUtil/DAT/vector/runtime support. The only sensible source contents for such a file are the existing fitting-room category-storage children already owned by [UID:000051], so a new file would duplicate rather than improve the source tree.

5. [UID:0000P3] `VectorHelpers` or [UID:00003K] `DATIndexVector` as aggregate parent - rejected.
   - For: each owns a narrow helper slice.
   - Against: neither covers the fitting-room category storage nor string helpers.

## Files Changed

By-docs updated under the split workflow:

- `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
- `by-memory/0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md`
- `by-memory/0x00423210-0x004233ea.FittingRoomEntryPartAllocatorCopy.md`
- `by-memory/0x00423960-0x00423a57.SmallString24AssignCopyHelper.md`
- `by-class/SimpleUString.md`
- `by-file/StringUtil.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md` (2026-06-10 review fix: synced stale manual rows for `0002EE`, `0002U5`, `0002U6`, `0002U8`, and `0002UG`)

Validator side effects from file-mode `--apply`:

- `tools/validator.ini`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-memory-coverage.md`

## Validation

Before editing, B001 leased the target aggregate, repaired children, direct/broad parent docs, and `by-memory/-ignored.md` with Agent ID `B001`. File-mode validation was run with `--apply` for each changed by-doc:

- `python validator.py --mode file --file ..\by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply`
- `python validator.py --mode file --file ..\by-memory\0x00423060-0x00423204.FittingRoomEntryPartVectorGrowCopy.md --apply`
- `python validator.py --mode file --file ..\by-memory\0x00423210-0x004233ea.FittingRoomEntryPartAllocatorCopy.md --apply`
- `python validator.py --mode file --file ..\by-memory\0x00423960-0x00423a57.SmallString24AssignCopyHelper.md --apply`
- `python validator.py --mode file --file ..\by-class\SimpleUString.md --apply`
- `python validator.py --mode file --file ..\by-file\StringUtil.md --apply`
- `python validator.py --mode file --file ..\by-memory\-ignored.md --apply`

All validator commands exited `0`.

## Final Recommendation

Close [UID:0002EE] as a reviewed, non-reconstructable mixed aggregate/container with no aggregate parent. Accept the repaired exact child routing:

- `0002U5 -> 0000D9 SimpleUString -> 0000OB StringUtil`
- `0002U6 -> 000051 FittingRoomDialogItemState`
- `0002UG -> ignored/non-reconstructable support`
- keep the existing exact child parents for the remaining children.

No new owner or source file should be created for the aggregate. If a future A-agent improves source output, it should work on exact children and owning structures/classes, not on this aggregate page.
