# A006 Notes

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

- Agent-A006 is stopped/offline for the current supervisor workflow. No open pending implementation entries remain in this note file.

## Supervisor-Applied Follow-Ups

- None for stopped A006 shared report rows. The supervisor applied and validated the Batch153 by-struct row, Batch160 by-class row, Batch160 by-memory rows, and Batch170 by-memory rows on 2026-06-11.

## Batch170 Report

- Changed files: `by-memory/0x00539bc0-0x0053d614.MotionAnimation.md`, `by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`, `by-memory/0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md`, and this `notes.md`.
- Related docs researched but not changed: `by-class/Motion.md` (`85/85`, parent `0000LL`), `by-file/Motion.md` (`86/85`), `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`, `by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md`, and current `by-memory/-coverage-report.md` rows.
- Validator-managed/generated files touched by targeted apply scans: validator UID/autogen state, `project-level/-auto-completion-stats.md`, and generated autogen coverage outputs as reported by validator. `by-memory/-coverage-report.md` was not edited due supervisor ban.
- Leases used: successful leases for all three target pages, `by-class/Motion.md`, `by-file/Motion.md`, and `notes.md`. The Motion class/file leases were used for research context and were not edited. `by-memory/-coverage-report.md` was not leased or edited.
- Score/parent changes: `MotionAnimation` `84/86 -> 85/88`, `RECONSTRUCTABLE:TRUE -> FALSE`, parent remains blank as mixed non-emitting aggregate; `MotionAnimationAlternateConstructor` `82/86 -> 85/88`, `AUTOGEN_PARENT_UID` blank -> `00008R`; `MotionAnimationTimerTick` `84/88 -> 86/90`, `AUTOGEN_PARENT_UID` blank -> `00008R`.
- Assignment/gate results: `0002QX` and `0002QY` attach directly to [UID:00008R][Motion](by-class/Motion.md) because each child clears `85/85` and the direct class parent clears `85/85`; [UID:0000LL][Motion](by-file/Motion.md) remains the class parent at `86/85`. `0001DD` stays parent-blank/non-emitting because it spans exact Motion children plus non-Motion LivingObjectPane/ObjectPane code and no single direct parent owns the whole range.
- Evidence summary: 2026-06-11 live IDA MCP reconfirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`; exact Motion function ranges `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, `0x00539fe0-0x0053a10c`, and `0x0053d590-0x0053d614`; Motion vtable refs at `0x00620954`, `0x00620964`, and `0x00620968`; Motion pool ref `0x0069b984`; local constructor table/padding pockets; and dense non-Motion function inventory from `0x0053a110` through `0x0053d589`. Decompiler review of `0x00539de0` and `0x00539fe0` confirmed the alternate constructor argument/field mapping and timer tick frame/sound/list/reschedule/cleanup flow.
- Validation apply commands/results: apply loop over `by-memory\0x00539bc0-0x0053d614.MotionAnimation.md`, `by-memory\0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`, and `by-memory\0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md` exited `0`; validator reported `ok: 1` for the aggregate apply and updated `0001DD` registry from true to false.
- Validation dry-run results: filtered dry loop over the same three target files reported `scanned markdown files: 1` and `ok: 1` for each, with no missing, duplicate, tmp, or invalid reference counters.
- Blockers: no Batch170 `by-memory/-coverage-report.md` changes remain open; the supervisor applied and validated them on 2026-06-11. No IDA MCP blocker. B001 was not used.

## Batch160 Report

- Changed files: `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`, `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`, new `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`, `by-class/MainMenuPane.md`, and this `notes.md`.
- Validator-managed/generated files touched by targeted apply scans: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and validator-managed UID/autogen state. `by-memory/-coverage-report.md` was not edited due supervisor ban.
- Leases used: successful leases for both Batch160 target pages, `notes.md`, `by-class/MainMenuPane.md`, and new child `0x004f6700-0x004f7d10.MainMenuPaneCore.md`; the original Batch160 target leases expired once and were reacquired before edits; lease request for `by-class/-coverage-report.md` was rejected because A003 already held it. `by-memory/-coverage-report.md` was not leased or edited.
- Score changes: `MainMenuLoginAndAccountDialogs` `78/86 -> 85/88` and `RECONSTRUCTABLE:TRUE -> FALSE`; `NewUserMiscShapeAndPasswordDialogs` `82/86 -> 85/88` and `RECONSTRUCTABLE:TRUE -> FALSE`; new `MainMenuPaneCore` assigned UID `00036Y` at `85/88`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:00007O`; `MainMenuPane` class `84/88 -> 85/89`.
- Assignment/gate results: exact `MainMenuPaneCore` attaches directly to `MainMenuPane` because child `85/88` and parent `85/89` clear the strict direct-parent gate. Both Batch160 aggregate pages remain parent-blank/non-emitting because they are reviewed mixed-owner containers and no single direct parent owns the whole physical range.
- Evidence summary: live IDA MCP rechecked full function inventories, surrounding padding, callers, and raw bytes. For `00019I`, the new child records modeled `MainMenuPane` functions from `0x004f6700` through `0x004f7a10`, constructor callers, activation callers, and raw unmodeled function-shaped bodies at `0x004f6a40-0x004f6a5e` and `0x004f79f0-0x004f7a0d`. For `00019U`, live IDA reconfirmed the five existing child splits, constructor callers for `0x004fb630`, `0x004fce80`, `0x004fd520`, and `0x004fdd40`, the `0x004fe782-0x004fe790` padding, and adjacent password-change packet-helper boundary.
- Validation apply commands/results: `validator.py --queue-timeout 120 --mode file --file by-memory\0x004f6700-0x004f7d10.MainMenuPaneCore.md --apply` assigned UID `00036Y`; a follow-up apply loop over `by-class\MainMenuPane.md`, the new child, and both target pages exited `0`.
- Validation dry-run results: filtered dry loop over `by-class\MainMenuPane.md`, `by-memory\0x004f6700-0x004f7d10.MainMenuPaneCore.md`, `by-memory\0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`, and `by-memory\0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` reported `scanned markdown files: 1` and `ok: 1` for each file, with no missing, duplicate, tmp, or invalid reference counters.
- Blockers: none for shared report rows. The supervisor applied and validated the Batch160 by-class row and by-memory rows on 2026-06-11. No IDA MCP blocker.

## Batch153 Report

- Changed files: `by-type/by-struct/StaticObjEntry.md`, `by-global/MapPaneCmapSignaturePointer.md`, `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`, `by-global/-coverage-report.md`.
- Validator-managed/generated files touched by file scans: `auto-generated/-ag-type-coverage.md`, `auto-generated/-ag-global-coverage.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Leases used: successful leases for `StaticObjEntry.md`, `MapPaneCmapSignaturePointer.md`, `by-global/-coverage-report.md`, and `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`; lease rejected for `by-type/by-struct/-coverage-report.md` because another agent already held it. `by-memory/-coverage-report.md` was not leased or edited due supervisor ban. Release command `python leaser.py Agent-A006 unlease` returned `Agent-A006: No active leases`.
- Score changes: `StaticObjEntry` `76/86 -> 85/88`, `AUTOGEN_PARENT_UID` blank -> `0000E2`; `MapPaneCmapSignaturePointer` `87/92 -> 89/93`, `AUTOGEN_PARENT_UID` blank -> `0000L3`; exact memory child `0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer` score unchanged `87/92`, `AUTOGEN_PARENT_UID` blank -> `0000L3` as generated-memory fallback.
- Evidence summary: live IDA MCP rechecked StaticObjImageLib constructor/destructor/render/bounds plus ObjectList relight consumer; live IDA MCP rechecked CMAP pointer bytes, target bytes, two MapPane load/save xrefs, target-literal xref, and empty following dword refs.
- Validation apply commands: `validator.py --queue-timeout 120 --mode file --file by-type\by-struct\StaticObjEntry.md --apply`, `... by-global\MapPaneCmapSignaturePointer.md --apply`, `... by-memory\0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md --apply`, and `... by-global\-coverage-report.md --apply`.
- Validation results: apply scans exited `0`; follow-up dry scans for all four edited files reported `ok: 1`, no missing/duplicate/tmp/invalid reference lines, and all seven autogen coverage reports unchanged on dry rerun. Autogen coverage now shows `StaticObjEntry` assigned to `0000E2`, `MapPaneCmapSignaturePointer` assigned to `0000L3`, and memory child `0002ZN` assigned to `0000L3`.
- Blockers: none for shared report rows. The supervisor applied and validated the Batch153 by-struct row and banned by-memory row on 2026-06-11.
