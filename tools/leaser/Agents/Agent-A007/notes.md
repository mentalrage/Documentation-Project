# Agent A007 Notes

## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

## Retired-Agent Status

- Agent-A007 is stopped/offline for the current supervisor workflow. No open pending implementation entries remain in this note file.
- The old InventoryPanes IDA retry note was pruned as retired-agent context only; later supervisor/A001 work refreshed the active InventoryPanes documentation path, so A007 has no exact pending patch to apply.

## 2026-06-11 Supervisor Cleanup

- Applied valid blocked report syncs from A007 Batches 106, 116, and 139, including image-lib class rows, item-dialog split child report rows, related file/class/vtable rows, and Browser GUID row refresh.
- Applied the old new-file workflow follow-up by creating and validating exact TargetObjectWithKeyboardPane suffix pages [UID:00036R], [UID:00036S], [UID:00036T], and [UID:00036U], updating class/file docs, and adding the manual coverage rows.
- Confirmed stale/superseded and left intact: DIBitmap/PCX rows already replaced by newer B001 non-emitting inventory, Browser OLE aggregate already improved by B001, FittingRoom release helpers already reflected, `PatchPane2VtableData` already routed cleanly, and `g_mapTilePixelWidth` intentionally re-rooted by newer A001/MapTilePixelDimensions work.

## 2026-06-11 A007 Batch 154

- Changed files:
  - `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
  - `by-type/by-vtable/RingBufferVtables.md`
  - `tools/leaser/Agents/Agent-A007/notes.md`
  - Validator-owned generated outputs were refreshed by scoped validator runs: `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-type-coverage.md`, `project-level/-auto-completion-stats.md`, and validator autogen registry state.
- Leases used:
  - Acquired A007 leases for `ItemActionInputPaneVtableFamily.md`, `RingBufferVtables.md`, and this `notes.md`.
  - Tried to lease `by-type/by-vtable/-coverage-report.md`; rejected because another agent already held the lease. The supervisor applied and validated the exact row replacements on 2026-06-11.
- Score changes:
  - [UID:0001XU] `ItemActionInputPaneVtableFamily`: `84/88` -> `86/89`; set `AUTOGEN_PARENT_UID:0000KC` after child `86/89` and direct file parent [UID:0000KC] `ItemActionInputPanes` `90/85` cleared the strict gate.
  - [UID:0001YN] `RingBufferVtables`: `86/90` -> `87/90`; set `AUTOGEN_PARENT_UID:0000N8` after child `87/90` and direct file parent [UID:0000N8] `RingBuffer` `86/85` cleared the strict gate. Exact by-memory child [UID:0002OQ] remains routed directly to the file root for generated memory coverage.
- Evidence added:
  - Live IDA MCP `py_eval` on 2026-06-11 rechecked all fourteen item-action primary/secondary/tertiary vtable triples, COL pointers, primary action slots, shared destructor/adjustor first slots, and constructor/factory/dispatcher store xrefs.
  - Live IDA MCP `py_eval` on 2026-06-11 rechecked RingBuffer predecessor terminator `0x006230c4`, `ScreenPane` successor COL at `0x006230e8`, both RingBuffer/RingBufferIterator COL pointers, both three-slot vtables, slot targets, and vptr-store xrefs.
- Validation:
  - `python tools/validator.py --mode file --file by-type/by-vtable/ItemActionInputPaneVtableFamily.md --apply` -> `ok: 1`; first run applied completion/confidence and autogen parent update, later confirmation run rebuilt autogen registry with `3039` edges and left generated reports unchanged.
  - `python tools/validator.py --mode file --file by-type/by-vtable/RingBufferVtables.md --apply` -> `ok: 1`; final run rebuilt autogen registry with `3039` edges and refreshed validator-owned `auto-generated/-ag-class-coverage.md` and `auto-generated/-ag-type-coverage.md`.
- Blockers:
  - No Batch154 report rows remain open; the supervisor applied and validated the `by-type/by-vtable/-coverage-report.md` row updates on 2026-06-11.
  - No `by-memory/-coverage-report.md` update is required by this batch; the supervisor-banned report was not edited.

## 2026-06-11 A007 Batch 161

- Changed files:
  - `by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md` (renamed from `0x00500640-0x00502754.SpecializedButtonPanes.md`)
  - `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`
  - `by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md`
  - `by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md`
  - `by-memory/0x00502ab0-0x00502b58.ScrolledPictureControlPaneScalarDeletingDestructor.md`
  - `by-class/DirectionButtonControlPane.md`
  - `by-class/GenderButtonControlPane.md`
  - `by-class/ScrolledPictureControlPane.md`
  - `by-file/SpecializedButtonPanes.md`
  - `by-file/ScrolledPictureControlPane.md`
  - `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md`
  - `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md`
  - `by-type/by-vtable/SpecializedButtonPaneVtables.md`
  - `tools/leaser/Agents/Agent-A007/notes.md`
  - Validator reference phase also normalized UID links in validator-owned/generated/indexed outputs and, despite the supervisor ban, normalized the [UID:0001A4] link path in `by-memory/-coverage-report.md`; no manual coverage-row edit was made.
- Leases used:
  - A007 leased both assigned targets, related class/file/vtable/vtable-data docs, new child memory docs after creation, and this `notes.md`.
  - The temporary supervisor ban prevented direct edits to `by-memory/-coverage-report.md`; the supervisor later applied and validated the Batch 161 by-memory report rows.
- Score and parent changes:
  - [UID:0001A4] `SpecializedButtonPanes` aggregate: `82/86` -> `85/87`; renamed/corrected range from `0x00500640-0x00502754` to `0x00500640-0x00502755`; parent remains blank because the aggregate is mixed ownership.
  - [UID:00036V] new `GenderDirectionButtonControlPaneMethods`: `0/0` -> `86/88`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000NY] after child and file parent clear `85/85`.
  - [UID:00036W] new `DirectionButtonControlPaneScalarDeletingDestructor`: `0/0` -> `86/90`; `RECONSTRUCTABLE:TRUE`; parent [UID:00003X] after child and class parent clear `85/85`.
  - [UID:00036X] new `GenderButtonControlPaneScalarDeletingDestructor`: `0/0` -> `86/90`; `RECONSTRUCTABLE:TRUE`; parent [UID:00005P] after child and class parent clear `85/85`.
  - [UID:0001AI] `ScrolledPictureControlPaneScalarDeletingDestructor`: `85/90` -> `86/90`; parent [UID:0000CH] after class `85/88` and file `88/85` clear `85/85`.
  - [UID:00003X] `DirectionButtonControlPane`: `80/84` -> `85/86`.
  - [UID:00005P] `GenderButtonControlPane`: `80/84` -> `85/86`.
  - [UID:0000CH] `ScrolledPictureControlPane` class: `84/88` -> `85/88`.
  - [UID:0000NH] `ScrolledPictureControlPane` file: `88/84` -> `88/85`.
  - [UID:0002OV] `GenderButtonControlPaneVtableData`: score stayed `85/90`; parent set to [UID:00005P].
  - [UID:0002OW] `DirectionButtonControlPaneVtableData`: score stayed `85/90`; parent set to [UID:00003X].
  - [UID:0001YW] `SpecializedButtonPaneVtables`: `84/90` -> `85/90`; parent set to [UID:0000NY].
- Evidence added:
  - 2026-06-11 live IDA MCP reconfirmed `0x00500640` and `0x005007a0` as raw constructor-shaped `NOFUNC` starts with no xrefs or raw pointer hits.
  - Live IDA MCP reconfirmed exact modeled functions for gender/direction accessor/state/paint methods, vtable refs, constructor vtable stores, and scalar deleting destructor bodies.
  - Live IDA MCP reconfirmed `0x005026a0-0x005026f5`, `0x00502700-0x00502755`, and `0x00502ab0-0x00502b58` destructor extents, thunk/vtable refs, vtable reset stores, base teardown calls, and guarded delete paths.
- Validation:
  - Initial positional validator invocation failed with `unrecognized arguments`; retried with the documented `--file` form.
  - Per-file loop: `python tools/validator.py --mode file --file <file> --apply` for all 13 edited by-* docs -> exit code `0`. First renamed-aggregate validation reported `ok: 1`, `path_update 0001A4 ... was by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md`, completion/confidence updates, reference index updates, and autogen registry rebuild. Subsequent per-file validations completed successfully.
- Blockers:
  - No evidence blocker remains for the two Batch 161 targets. Both now clear child+parent `85/85` where assigned, or remain intentionally parentless for mixed ownership.
  - No Batch 161 `by-memory/-coverage-report.md` rows remain open; the supervisor applied and validated the rows for [UID:0001A4], [UID:00036V], [UID:00036W], [UID:00036X], and [UID:0001AI] on 2026-06-11.
