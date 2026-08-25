## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

## Supervisor-Applied Coverage Updates

- Agent-A010 is stopped/offline for the current supervisor workflow. No open pending implementation entries remain in this note file.

- None for `by-memory/-coverage-report.md`. The supervisor applied and validated the Batch 167 rows for [UID:0001D1], [UID:0002JS], and [UID:0002JT] on 2026-06-11.

The supervisor applied the Batch 157 banned `by-memory/-coverage-report.md` rows for `00018N` and `00018T`; no Batch 157 blocked rows remain.

Supervisor follow-up: B001 later researched [UID:00018T] and the supervisor assigned it to [UID:0000KK][LanguageMan](../../../by-file/LanguageMan.md), then applied and validated the target page and `by-memory/-coverage-report.md`. The older A010 ownership blocker is superseded.

## Batch 167 Work Log

- Changed files:
  - `by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md`
  - `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`
  - `by-memory/0x00531260-0x00531473.ObjectListDestructor.md`
  - `auto-generated/-ag-memory-coverage.md` (validator-owned generated update during aggregate validation)
  - `project-level/-auto-completion-stats.md` (validator-owned generated stats update)
  - `tools/validator_autogen_backup/20260611-092624` (validator-created generated backup)
  - `tools/leaser/Agents/Agent-A010/notes.md`
- Leases used:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00530ee0-0x0053125d.ObjectListConstructor.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00530ee0-0x00531473.ObjectListLifecycle.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00531260-0x00531473.ObjectListDestructor.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A010\notes.md`
  - Closeout: `current_leases.md` no longer listed A010 before release; explicit `unlease` returned `Rejected[No active lease]` for the three target pages and notes, then notes was re-leased only to record this closeout.
- Score changes:
  - UID `0002JS` ObjectListConstructor: `82/90` -> `85/91`; `AUTOGEN_PARENT_UID` blank -> `0001D1`.
  - UID `0001D1` ObjectListLifecycle: `80/90` -> `85/91`; `AUTOGEN_PARENT_UID` blank -> `00009Q`.
  - UID `0002JT` ObjectListDestructor: `84/90` -> `85/91`; `AUTOGEN_PARENT_UID` blank -> `0001D1`.
- Validation:
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00530ee0-0x00531473.ObjectListLifecycle.md" --apply`
    - Result: `ok: 1`; completion update to `85`, confidence update to `91`, autogen registry update `0001D1 -> 00009Q`; validator-owned `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md` were updated; backup `tools/validator_autogen_backup/20260611-092624` was created.
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00530ee0-0x0053125d.ObjectListConstructor.md" --apply`
    - Result: `ok: 1`; completion update to `85`, confidence update to `91`, autogen registry update `0002JS -> 0001D1`; generated reports unchanged.
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00531260-0x00531473.ObjectListDestructor.md" --apply`
    - Result: `ok: 1`; completion update to `85`, confidence update to `91`, autogen registry update `0002JT -> 0001D1`; generated reports unchanged.
- Blockers / unresolved:
  - No Batch 167 `by-memory/-coverage-report.md` rows remain open; the supervisor applied and validated them on 2026-06-11.
  - No final C++ was emitted because the ObjectList row/global tier names and final source declaration shape remain below the `95/95` reconstruction-code gate.
  - Related scalar deleting destructor [UID:0001D4] was reviewed as associated evidence but not edited in this batch; it remains a compiler-generated destructor wrapper around this ordinary destructor.

## Batch 157 Work Log

- Changed files:
  - `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md`
  - `by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md`
  - `auto-generated/-ag-memory-coverage.md` (validator-owned generated update)
  - `tools/validator_autogen_backup/20260611-090954` (validator-created generated backup)
  - `tools/leaser/Agents/Agent-A010/notes.md`
- Leases used:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004efbc0-0x004efe94.JpegScreenshotWriter.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md`
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A010\notes.md`
- Score changes:
  - UID `00018N` JpegScreenshotWriter: `84/88` -> `86/89`; `AUTOGEN_PARENT_UID` blank -> `0000K4`.
  - UID `00018T` LocalizationAdjacentZeroInitializer: `80/88` -> `82/90` -> `85/91` during A010 work; later B001/supervisor follow-up assigned it to `0000KK`.
- Validation:
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004efbc0-0x004efe94.JpegScreenshotWriter.md" --apply`
    - Result: `ok: 1`; completion update to `86`, confidence update to `89`, autogen registry update `00018N -> 0000K4`.
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md" --apply`
    - Result: `ok: 1`; completion update to `82`, confidence update to `90`.
  - Continuation rerun: `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file "E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md" --apply`
    - Result: `ok: 1`; completion update to `85`, confidence update to `91`, reference index added UID `000072`; validator-owned `auto-generated/-ag-memory-coverage.md` was updated and backup `tools/validator_autogen_backup/20260611-090954` was created.
- Blockers / unresolved:
  - No Batch157 coverage-report rows remain open; the supervisor applied and validated them.
  - The older UID `00018T` ownership blocker is superseded by B001/supervisor follow-up assigning the page to [UID:0000KK][LanguageMan](../../../by-file/LanguageMan.md).
