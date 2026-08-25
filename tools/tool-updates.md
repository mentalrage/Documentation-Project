# Canonical Owner and Emitter UID Redesign Plan

Status note, 2026-06-13: the validator and memory-range tool changes described
here have been implemented and the live by-* headers have been migrated. This
file remains the migration/design record. For day-to-day usage, prefer
`validator_README.txt`, `memory_ranges_README.md`, and `by-structure.md`.

## Objective

Split the current `AUTOGEN_PARENT_UID` behavior into two separate concepts:

- `CANONICAL_OWNER`: documentation ownership only. This exists for all validator-managed items, including non-reconstructable items. It does not emit code.
- `EMITTER_UIDS`: reconstruction output routing. This exists on reconstructable items and replaces the current emission behavior of `AUTOGEN_PARENT_UID`. It accepts zero, one, or multiple comma-separated UIDs.

This change must preserve existing data, provide a dry-run migration path, update generated reports, and update all operational documentation so agents no longer treat "owner" and "emitter" as the same field.

First-run migration rule:

- Existing nonblank `AUTOGEN_PARENT_UID` values seed `CANONICAL_OWNER` for every migrated item, even when the item is not reconstructable.
- Existing nonblank `AUTOGEN_PARENT_UID` values also seed `EMITTER_UIDS` only when the item is `RECONSTRUCTABLE:TRUE`.
- `RECONSTRUCTABLE:FALSE` and blank reconstructable items do not receive emitters during migration, because they should not emit code.
- This preserves current generated-output behavior for existing reconstructable items while separating ownership from emission for future work.
- Some existing parent UIDs may have been used as output routes instead of true semantic owners. The migration should preserve them as the initial canonical owner to avoid data loss, then report/audit those cases for later correction rather than trying to infer better ownership during the mechanical migration.

## Affected Areas Summary

Tools:

- `tools/validator.py` - expose and queue new migration/dry-run/cleanup modes; prevent queue dedup from merging dry-run jobs with live apply jobs.
- `tools/validator_background.py` - replace parent-driven autogen with `CANONICAL_OWNER` plus `EMITTER_UIDS`; add migration, dry-run overlays, multi-emitter assembly, dead-end/error reporting, and new report stats.
- `tools/validator.ini` - migrate persisted state from singular parent/root sections to owner/emitter/root/dead-end/error sections; keep old sections readable only during migration compatibility.
- `tools/memory_ranges.py` - replace parent/assigned parsing with owner/emitter parsing; update no-owner/emits/non-emits/multiple-emitter byte stats; add dry-run report support.
- `tools/memory_ranges.data` - no expected schema change, but rerun and confirm the regenerated report after migration.
- `tools/unresolved.py` and config - no parent/emitter parsing expected; confirm normal scans ignore `*.dryrun` and generated wording does not preserve old terminology.
- `tools/find_legacy_references.py` - no semantic change expected; confirm it reads live `validator.ini` and ignores dry-run state unless explicitly requested.
- `tools/inject_unknown_memory_gaps.py` - no autogen-header dependency expected; confirm report wording stays compatible after generated coverage terminology changes.
- `tools/int_convert.py` and `tools/int_convert_readme.md` - no header/state dependency found; no migration change expected.
- `tools/launch_idalib_mcp_nexustk.ps1`, `tools/install_idalib_mcp_transition.ps1`, and `tools/Start_NexusTK_IDA_MCP.bat` - no documentation metadata dependency found; no migration change expected.
- `tools/signature_install_cache/**` - signature install cache only; no migration change expected.
- `tools/validator_update_plan.md` - historical prior validator plan using old parent terminology; update or mark as pre-migration historical so it does not conflict with the new active plan.
- `tools/leaser/*` - no lease-code semantic change expected; active agent goals, notes, and supervisor docs require terminology and workflow updates.

Generated files:

- `auto-generated/-ag-*-coverage.md` - replace `Parent`/`unassigned` output with owner/emitter/no-owner output, add emission stats, `## Dead Ends`, and `## Errors`.
- `auto-generated/by-memory-tool-report.md` - regenerate from updated `memory_ranges.py` with owner/emitter byte accounting.
- `auto-generated/NexusTK/**` - generated C++ assembly must route through `EMITTER_UIDS`, not `CANONICAL_OWNER`.
- `project-level/-unresolved.md`, `project-level/-resolved.md`, and `project-level/-resolved-multple-aliases.md` - regenerate after migration if wording or scanned text changes, and confirm generated text does not preserve old parent/unassigned instructions.
- `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, `by-function/-coverage-report.md`, `by-global/-coverage-report.md`, `by-item/-coverage-report.md`, `by-memory/-coverage-report.md`, `by-resource/-coverage-report.md`, and nested `by-type/*/-coverage-report.md` - these are support/control reports, not header-migrated item docs, but their prose and status wording must be updated from assigned/unassigned/parent UID to owner/emitter/no-owner language where present.

Documentation:

- `by-structure.md` - primary rule change from one parent field to separate documentation ownership and emission routing.
- `by-file/-guidance.md` - document `CANONICAL_OWNER:FILE` roots and reject `FILE` outside singular by-file pages.
- `by-memory/-guidance.md`, `by-class/-guidance.md`, `by-function/-guidance.md`, `by-type/-guidance.md`, `by-global/-guidance.md`, `by-resource/-guidance.md`, and other folder guidance files - update old parent/unassigned instructions to canonical owner/emitter/no-owner rules where those folders can contain validator-managed items.
- `tools/validator_README.txt` and `tools/memory_ranges_README.md` - update CLI, metadata headers, migration/dry-run flow, report interpretation, and error/dead-end definitions.
- Existing singular `by-*/*.md` documents - migration rewrites headers and seeds `CANONICAL_OWNER`/`EMITTER_UIDS` from old `AUTOGEN_PARENT_UID` according to the first-run rules.
- Active `tools/leaser/Agents/**/goal.md`, `notes.md`, `Supervisor.md`, and `Supervisor_notes.md` - update agent instructions so agents do not keep using old parent/unassigned language.
- Root-level and process docs such as `wave3_data_issues.md`, `wave3_tool_guide.md`, `by-meta/**`, `by-external-research/**`, and `by-project-structure/**` - do not add item metadata headers, but update any active guidance that still teaches old assignment/emission terminology.
- Historical research/change-log files - update active recommendation/template sections, or mark preserved old wording as pre-migration historical evidence.

## Review Findings and Gaps Closed

This plan was reviewed against the current repository before implementation. The following findings must be treated as implementation requirements, not optional cleanup.

### Current Validator Code Trace

- `tools/validator.py:327-333`
  - Frontend parser uses `parse_known_args()`, so new background flags can pass through, but frontend-only options and help text still need review.
- `tools/validator.py:342-350`
  - Normalizes validator args, enqueues jobs, and starts the worker. New write-like dry-run/apply modes must preserve queue ordering here.
- `tools/validator_background.py:65-79`
  - Defines `AUTOGEN_PARENT_UID` and `AUTOGEN_PARENT_POSITION_OPTIONAL` regex/prefix constants.
- `tools/validator_background.py:125-132`
  - Defines current `validator.ini` autogen sections: `[reconstructable]`, `[autogen_parent]`, `[autogen_parent_position]`, `[autogen_children]`, `[autogen_root]`, `[autogen_status]`, and `[autogen_errors]`.
- `tools/validator_background.py:186-213`
  - `AutogenMetadata` and `AutogenReportEntry` are singular-parent models.
- `tools/validator_background.py:649-663`
  - `is_autogen_metadata_doc()` excludes `by-file`, `by-resource`, `by-meta`, `by-external-research`, and `by-project-structure`. This cannot be reused as-is for `CANONICAL_OWNER`, because file roots now need `CANONICAL_OWNER:FILE`.
- `tools/validator_background.py:676-684`
  - `is_projected_path_candidate()` identifies singular `by-file/*.md` roots.
- `tools/validator_background.py:787-791`
  - `all_markdown_files()` uses `rglob("*.md")`. Live scans naturally ignore `*.md.dryrun`; dry-run mode needs an explicit input overlay when using existing dry-run files.
- `tools/validator_background.py:1065-1160`
  - `ensure_autogen_metadata_lines()` inserts/restores old autogen metadata. This must split into owner-header insertion plus reconstruction/emitter metadata insertion.
- `tools/validator_background.py:1380-1458`
  - `scan_autogen_metadata()` parses one `parent_uid`.
- `tools/validator_background.py:1501-1521`
  - `remove_autogen_uid()` cleans old singular-parent registry state.
- `tools/validator_background.py:1523-1608`
  - `update_autogen_registry_for_metadata()` writes old parent state and currently errors on code without parent.
- `tools/validator_background.py:2131-2149`
  - `scan_targets()` knows only `full`, `documented`, `file`, `rescore`, `isolated`, and `autogen`. New migration/cleanup modes must be added here.
- `tools/validator_background.py:2281-2336`
  - `build_autogen_children()` and `resolve_autogen_root()` build a single-parent tree and one root per item.
- `tools/validator_background.py:2337-2398`
  - `rebuild_autogen_registry()` writes single-root status and uses `unassigned`.
- `tools/validator_background.py:2443-2510`
  - `assemble_autogen_node()` and `assemble_autogen_root()` assemble a tree. Multi-emitter output must track routes per root.
- `tools/validator_background.py:2584-2696`
  - `autogen_report_stats()`, `render_autogen_report()`, and `autogen_report_entries()` render old stats, `Parent`, and no bottom error/dead-end sections.
- `tools/validator_background.py:2717-2777`
  - `run_autogen_generation()` writes generated C++ and reports from singular roots.
- `tools/validator_background.py:3541-3549`
  - Normal modes call autogen generation and then write live `validator.ini`; dry-run artifact mode must not reuse this path without redirecting outputs/state.
- `tools/validator_background.py:4055-4066`
  - CLI parser mode choices must add `migrate-autogen`, `clear-dryrun-files`, `--dry-run`, and `--use-existing-dryrun`.
- `tools/validator_background.py:3635-3660`
  - Queue dedup classification must know the new modes. Artifact-writing dry-run and clear-dryrun must not be treated as read-only jobs.

### Current Companion Tool Trace

- `tools/memory_ranges.py:25-40`
  - Independently parses `RECONSTRUCTABLE`, `AUTOGEN_PARENT_UID`, and reconstruction code.
- `tools/memory_ranges.py:141-170`
  - `RangeRecord` stores `parent_uid` and derives `assigned`.
- `tools/memory_ranges.py:359-386`
  - `parse_file_metadata()` returns reconstructable status, parent UID, and code presence.
- `tools/memory_ranges.py:779-797`
  - `accumulate_reconstructable_assignment_bytes()` computes `assigned`, `unassigned`, and code-emission byte stats from the old parent field.
- `tools/memory_ranges.py:1114-1133`
  - Report text prints `unassigned`, `assigned`, `emits code`, and `does not emit code`.
- `tools/memory_ranges.py:1355-1408`
  - Report writer always writes the live report path. Dry-run support must redirect report output to `by-memory-tool-report.md.dryrun`.
- `tools/memory_ranges.py:1810-1991`
  - CLI has subcommands and `--data`, but no dry-run artifact mode or `--use-existing-dryrun`.
- `tools/unresolved.py`
  - No parent/emitter parsing found. It scans `RECONSTRUCTABLE` only and writes unresolved/resolved reports. It must ignore `*.dryrun` for normal scans and only needs dry-run support if intentionally pointed at dry-run files.
- `tools/find_legacy_references.py`
  - Uses `validator.ini` `[files]` and scans `rglob("*.md")`, so normal scans ignore `*.dryrun`. No parent/emitter change expected, but confirm it does not read `validator.ini.dryrun` accidentally.
- `tools/inject_unknown_memory_gaps.py`
  - Operates only on `by-memory/-coverage-report.md`; no autogen header dependency found.

### Documentation Search Inventory

Current old-model/assignment-term matches were found in 4,448 files under `project-documentation` after excluding temporary validator queue/backup paths and generated C++ output. This stricter inventory includes literal old header names and generated/status words such as `assigned` and `unassigned`. Approximate affected folder counts:

- `by-memory`: 3,161 files
- `by-class`: 589 files
- `by-type`: 249 files
- `by-global`: 187 files
- `tools`: 112 files
- `by-file`: 67 files
- `by-item`: 66 files
- `auto-generated`: 8 files
- `project-level`: 2 files
- `by-external-research`: 2 files
- `by-structure.md`: 1 file
- `by-meta`: 1 file
- `by-project-structure`: 1 file
- `wave3_data_issues.md`: 1 file
- `wave3_tool_guide.md`: 1 file

Operational docs with exact old-model references:

- `by-structure.md`
- `by-file/-guidance.md`
- `by-memory/-guidance.md`
- `by-class/-guidance.md`
- `tools/validator_README.txt`
- `tools/validator_update_plan.md`
- active agent goals and notes under `tools/leaser/Agents`
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `project-level/-unresolved.md`
- `project-level/-resolved.md`
- root-level migration/process docs such as `wave3_data_issues.md` and `wave3_tool_guide.md` if they contain active old terminology

Generated report files with old columns/stats:

- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-function-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-item-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-type-coverage.md`
- `auto-generated/by-memory-tool-report.md`

### Specific Gaps Fixed In This Plan

- `CANONICAL_OWNER` scope is not the same as current autogen metadata scope. It needs a new owner-metadata eligibility function.
- `by-file` roots are currently excluded from autogen metadata, but now require `CANONICAL_OWNER:FILE`.
- The new artifact-writing dry run is not the same as the current validator no-`--apply` dry run. It must write only `*.dryrun` artifacts and dry-run state.
- Dry-run cleanup must be manifest-based. Do not delete arbitrary `*.dryrun` files without confirming they were created by this tool.
- Normal scans must ignore `*.dryrun`; repeat dry-run scans must explicitly overlay existing `*.dryrun` files and `validator.ini.dryrun`.
- Queue dedup must not merge artifact-writing dry-run jobs with live apply jobs.
- Multi-emitter state cannot use current singular `[autogen_root]` or a global `coded_uids` set without losing per-root output details.

### Tools

- `tools/validator.py`
  - Queue/frontend script. Add pass-through CLI options for the migration mode and update help text if needed.
  - No direct header parsing currently found here, but it must expose any new validator mode safely through the existing queue.
  - `normalize_validator_args()` currently normalizes only `--file`; do not rely on the frontend to map `.md.dryrun` paths. Dry-run overlays belong in the background scan/state layer.

- `tools/validator_background.py`
  - Major change required. This file owns metadata parsing, header insertion/repair, `validator.ini` registry updates, autogen tree building, generated C++ output, and `-ag-*` report generation.
  - Replace singular `parent_uid` model with `canonical_owner` plus `emitter_uids`.
  - Add migration support, dead-end detection, multi-emitter output, and new report stats/sections.

- `tools/validator.ini`
  - Tool-owned state file. Do not manually edit during normal migration.
  - Current relevant sections begin at `[queue]` line 4, `[files]` line 8, `[reconstructable]` line 19339, `[autogen_parent]` line 23580, `[autogen_parent_position]` line 27821, `[autogen_children]` line 40544, `[autogen_root]` line 41405, `[autogen_status]` line 45112, and `[autogen_errors]` line 49353.
  - Add new sections such as `[canonical_owner]`, `[emitter_uids]`, `[emitter_position]`, `[autogen_emitter_children]`, `[autogen_roots]`, `[autogen_dead_ends]`, and updated status/error sections.
  - Keep old `[autogen_parent]` and `[autogen_parent_position]` readable during migration, then stop writing them after apply.

- `tools/validator.json`
  - No `validator.json` file currently exists in `tools`. Confirm this before implementation. The active persistent state is `validator.ini`.
  - If a JSON config is later introduced, mirror the new canonical owner/emitter schema there.

- `tools/memory_ranges.py`
  - Required change. This tool independently parses `AUTOGEN_PARENT_UID` and reports `unassigned` reconstructable bytes.
  - Update it to parse `CANONICAL_OWNER` and `EMITTER_UIDS`, rename report wording to `no-owner`, and add reconstructable emission stats where applicable.

- `tools/memory_ranges.data`
  - Likely no schema change, but rerun and confirm the report remains valid after metadata migration.

- `tools/unresolved.py`, `tools/unresolved.ini`, `tools/unresolved.json`
  - No direct parent/emitter parsing found. It parses `RECONSTRUCTABLE` and writes project-level unresolved/resolved reports.
  - Confirm normal scans ignore `*.dryrun` through extension config and regenerate outputs after migration if report content references old terminology.

- `tools/find_legacy_references.py`
  - No direct parent/emitter parsing found. It uses `validator.ini [files]` and scans `rglob("*.md")`.
  - Confirm it continues to ignore `*.dryrun` during normal operation and does not accidentally read `validator.ini.dryrun`.

- `tools/inject_unknown_memory_gaps.py`
  - No autogen header parsing found. It rewrites `by-memory/-coverage-report.md` from coverage rows.
  - Only documentation wording may need updates if coverage rows or summaries mention old terms.

- `tools/int_convert.py`, IDA/MCP launch scripts, and signature-install cache files
  - No parent/emitter/header/state parsing found. Keep them out of the migration unless a later search finds direct metadata references.

- `tools/validator_update_plan.md`
  - Historical planning document with extensive old `AUTOGEN_PARENT_UID`, `[autogen_parent]`, `[autogen_root]`, `assigned`, and `unassigned` terminology.
  - Either update it to point at `tools/tool-updates.md` as the superseding plan or add a clear pre-migration/historical warning at the top.

- `tools/leaser/*`
  - Leaser code likely does not need semantic changes.
  - Agent goals, supervisor notes, and workflow documentation under `tools/leaser/Agents` do need terminology and instruction updates.

- `tools/validator_README.txt`
  - Required documentation update for metadata headers, migration mode, report meanings, multi-emitter rules, `FILE`, no-owner, and dead-end handling.

- `tools/memory_ranges_README.md`
  - Required documentation update for no-owner/emission terminology and refreshed report interpretation.

### Generated Outputs

- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-function-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-item-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-type-coverage.md`
  - Replace `Parent` column with separate owner/emitter columns.
  - Replace `unassigned` with `no-owner`.
  - Add reconstructable stats: `Total_Reconstructable_Emits`, `Total_Reconstructable_NonEmits`, `Total_Reconstructable_MultipleEmitters`, and `Total_DeadEnds`.
  - Add bottom sections for `Dead Ends` and then `Errors`.

- `auto-generated/NexusTK/**`
  - Generated C++ assembly must use `EMITTER_UIDS`, not `CANONICAL_OWNER`.
  - Multi-emitter items may intentionally appear in more than one generated root.

- `auto-generated/by-memory-tool-report.md`
  - Regenerate with updated `memory_ranges.py`.
  - Rename reconstructable assignment language to owner/emitter language.

- `project-level/-unresolved.md`
- `project-level/-resolved.md`
- `project-level/-resolved-multple-aliases.md`
  - Generated by `tools/unresolved.py`. Regenerate after migration if old terminology appears because the scanned source text changed.

- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-function/-coverage-report.md`
- `by-global/-coverage-report.md`
- `by-item/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `by-resource/-coverage-report.md`
- `by-type/-coverage-report.md`
- all nested `by-type/*/-coverage-report.md`
  - These are support/control reports. Do not insert item metadata headers into them.
  - Update status prose and any generated rows that still teach old `assigned`, `unassigned`, or `AUTOGEN_PARENT_UID` terminology.

### Documentation

- `by-structure.md`
  - Required primary rules update. It currently says `AUTOGEN_PARENT_UID` is both ownership and output routing. This must become explicit owner/emitter separation.

- `by-file/-guidance.md`
  - Required update. `by-file` pages default to `CANONICAL_OWNER:FILE` and are file emission roots. Non-file folders must not use `FILE`.

- `by-memory/-guidance.md`
- `by-class/-guidance.md`
- `by-function/-guidance.md`
- `by-type/-guidance.md`
- `by-global/-guidance.md`
- `by-resource/-guidance.md`
- Other `by-*/*-guidance.md` files
  - Required update from parent UID to canonical owner/emitter wording.

- Existing singular `by-*/*.md` documents
  - Migration must replace `AUTOGEN_PARENT_UID` with `CANONICAL_OWNER` and `EMITTER_UIDS` according to the first-run rules below.
  - Add `CANONICAL_OWNER` to non-reconstructable validator-managed items.

- Existing `by-*` support reports and coverage reports
  - Do not add validator item headers because they are excluded support/control docs.
  - Update old terminology after generated reports are refreshed, especially `assigned`, `unassigned`, `parent UID`, and `AUTOGEN_PARENT_UID` references that are not literal pre-migration history.

- `tools/leaser/Agents/**/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- Active `notes.md` files where they contain pending old-header text
  - Required update so agents request "no-owner" items, set owners separately from emitters, and understand that emission requires a valid `EMITTER_UIDS` route to a file.

- Historical executed research reports
  - Audit. If they are active guidance, update wording. If they are historical evidence, either preserve the old term with a migration note or update only the recommendation sections so future searches do not teach the old model.

## New Metadata Model

### Metadata Scope

Do not reuse the current `is_autogen_metadata_doc()` scope for all new metadata.

Implement two separate scope checks:

1. `is_owner_metadata_doc(root, path)`
   - True for UID-bearing singular item pages under direct `by-*` folders, including nested type subfolders such as `by-type/by-vtable/*.md`.
   - True for singular `by-file/*.md` pages because those roots need `CANONICAL_OWNER:FILE`.
   - True for singular `by-resource/*.md` item pages if they are ordinary UID-bearing item docs.
   - False for files whose basename starts with `-`, coverage reports, guidance/control pages, root docs, generated docs, tool docs, `by-meta`, `by-external-research`, and `by-project-structure`.
   - Inserts/repairs only the `CANONICAL_OWNER` line.

2. `is_reconstruction_metadata_doc(root, path)`
   - Replaces the current `is_autogen_metadata_doc()` behavior for `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, and reconstruction code.
   - Excludes `by-file` roots because file roots are emitted by `CANONICAL_OWNER:FILE` plus `PROPOSED_RECONSTRUCTION_PATH`, not by child reconstruction metadata.
   - Excludes the same support/control folders currently excluded from autogen metadata unless an explicit future rule adds them.

This split avoids a bug where by-file pages never receive `CANONICAL_OWNER:FILE` because the current autogen metadata scope excludes `by-file`.

### Header Names

Use validator-style all-caps headers in Markdown:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes:

- Use `EMITTER_UIDS`, not `EMIITER_UIDS`. The user-facing concept is "emitter uids"; the persisted header should use the corrected spelling.
- `CANONICAL_OWNER` should be displayed as `Canonical_Owner` in prose only if desired, but the file header should be stable and all caps like existing validator headers.
- `EMITTER_POSITION_OPTIONAL` supports both old single numeric sort behavior and per-emitter sort values. A single value applies to every emitter. A comma-separated value list aligns with `EMITTER_UIDS`; empty entries mean no position for that specific emitter, for example `1,,3`. Items with positions sort before items without positions. Items with the same position, or with no position, preserve first-seen scan order.

### `CANONICAL_OWNER`

Allowed values:

- `NONE`: no owner is known or assigned.
- `FILE`: only valid on singular `by-file/*.md` pages that represent emitted source roots.
- One existing six-character UID.

Rules:

- Exists for all validator-managed item documents, including `RECONSTRUCTABLE:FALSE` and blank reconstructable state.
- Does not control generated C++ output.
- May point to non-reconstructable items when the ownership relationship is documentation-only.
- `RECONSTRUCTABLE:FALSE` items may own other `RECONSTRUCTABLE:FALSE` items through `CANONICAL_OWNER` chains when that accurately documents containment, grouping, or semantic ownership.
- `RECONSTRUCTABLE:FALSE` items may also have a reconstructable or file owner if the relationship is documentation-only.
- Must not be treated as proof that code will be emitted.
- `FILE` on any non-`by-file` singular document is a validation error.
- New generated/validator-created non-file items default to `CANONICAL_OWNER:NONE`.
- New singular `by-file` pages default to `CANONICAL_OWNER:FILE`.

### `EMITTER_UIDS`

Allowed values:

- Blank: reconstructable item currently does not emit.
- One existing six-character UID.
- Multiple existing six-character UIDs separated by commas, for example `0000AB,0000CD`.

Rules:

- Exists on reconstructable-capable item docs with the rest of autogen metadata.
- Replaces the output behavior of old `AUTOGEN_PARENT_UID`.
- Only `EMITTER_UIDS` controls generated C++ placement and `[[CHILDREN]]` insertion.
- `RECONSTRUCTABLE:FALSE` and blank reconstructable items may have a blank validator-managed `EMITTER_UIDS` header if the document is in reconstruction metadata scope, but the `EMITTER_UIDS` value must be blank and the reconstruction code block must be empty. Nonblank emitter values or nonblank reconstruction code on those items are errors, and every affected `-ag-*` report must list them.
- A non-reconstructable item can be a canonical owner, but it is not an emission node. A reconstructable item that tries to emit through a non-reconstructable item should be reported as a dead-end or emitter error unless a later explicit forwarding rule is designed.
- Each emitter UID must exist.
- Each emitter route must eventually surface to a valid `by-file` root or `FILE` root.
- Duplicate UIDs in one list are an error or normalized away with an action. Prefer error in strict mode and normalization only in migration dry-run suggestions.
- Multiple emitters mean the same reconstructable snippet can be emitted in multiple generated roots.
- Do not infer multiple emitters automatically during migration unless the old data already contained explicit equivalent evidence. Most old items should migrate with exactly one emitter copied from the old parent UID.

### `FILE`

`FILE` is a special canonical owner value and file-root emission marker for singular `by-file` pages.

Rules:

- Valid only for singular `by-file/*.md` pages.
- A `by-file` page with `CANONICAL_OWNER:FILE` and valid `PROPOSED_RECONSTRUCTION_PATH` is an emission root.
- A non-file document with `CANONICAL_OWNER:FILE` is a validator error.
- If a `by-file` page is reviewed as not standalone, continue using `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and document the reason. Its `CANONICAL_OWNER` can still be `NONE` or the real owning UID if represented, but it must not claim `FILE` unless it is a generated file root.

## Status and Report Semantics

Replace the old overloaded status with separate concepts:

- Owner status:
  - `no-owner`: `CANONICAL_OWNER:NONE`.
  - `owned`: `CANONICAL_OWNER` is a UID or valid `FILE`.
  - `owner-error`: invalid owner UID, invalid `FILE`, or malformed owner header.

- Emission status for reconstructable items:
  - `emits`: has one or more `EMITTER_UIDS`.
  - `non-emits`: has no `EMITTER_UIDS`.
  - `multiple-emitters`: has more than one `EMITTER_UIDS` entry.
  - `dead-end`: has emitted code and emitter UID(s), but at least one emitter route does not reach a generated file root.
  - `emitter-error`: malformed emitter list, unknown emitter UID, cycle, invalid root path, or other route error.

Generated reports can keep one compact `Status` column, but they must include enough columns to show both owner and emitter state:

```text
| UID | Status | Canonical Owner | Emitters | Position | Code | Destination | Path | Detail |
```

Owner and emission are independent axes:

- A reconstructable item can be `no-owner` and still have emitters when the source ownership is genuinely ambiguous but emission sites are known.
- A reconstructable item can be `owned` and still be `non-emits` when ownership is known but final output routing is not ready.
- A non-reconstructable item can be `owned`, but it must not be `emits`.
- Reports must expose both columns/stats so one status label does not hide the other axis.

The status should prefer the most actionable state:

1. `error`
2. `dead-end`
3. `no-owner`
4. `multiple-emitters`
5. `emits`
6. `non-emits`
7. `not_reconstructable`
8. `unclassified`

Do not use the word `unassigned` in newly generated reports. Use `no-owner`.

## New Report Stats

Each `-ag-*` coverage report should include the existing totals plus:

```text
Total_Reconstructable_Emits: 0
Total_Reconstructable_NonEmits: 0
Total_Reconstructable_MultipleEmitters: 0
Total_DeadEnds: 0
```

Definitions:

- `Total_Reconstructable_Emits`: count of reconstructable items with one or more `EMITTER_UIDS`.
- `Total_Reconstructable_NonEmits`: count of reconstructable items with no `EMITTER_UIDS`.
- `Total_Reconstructable_MultipleEmitters`: count of reconstructable items with more than one emitter UID.
- `Total_DeadEnds`: count of reconstructable items with emitted code and emitter routes that do not surface to a generated file root.

Keep existing total names where possible, but rename `Total_Reconstructable_Unassigned` to `Total_Reconstructable_NoOwner`.

## Dead-End Validation

A dead-end is not the same as a non-emitting item.

Dead-end condition:

- Item is `RECONSTRUCTABLE:TRUE`.
- Item has nonblank `RECONSTRUCTION_CPP CODE`.
- Item has at least one `EMITTER_UIDS` entry.
- One or more emitter chains fail to reach a file root that can produce a generated `.cpp`.

Examples:

- Memory item emits to class `000123`; class has no emitter route to a `by-file` page or `FILE` root.
- Type emits to global `000456`; global is reconstructable but has blank emitters.
- Item emits to a non-reconstructable UID. That UID can be a valid canonical owner, but it is not a valid emission route by default.
- Item emits to a UID that exists but is not eligible to participate in emission.
- Emitter chain cycles.
- Emitter chain reaches a `by-file` page with blank/invalid `PROPOSED_RECONSTRUCTION_PATH`.

Dead-end output:

- Add `Total_DeadEnds` to report stats.
- Add a `## Dead Ends` section at the bottom of each `-ag-*` report.
- After `## Dead Ends`, add a `## Errors` section.
- Each dead-end row should include UID, path, emitters, failing chain, and reason.
- Every validator error related to owner/emitter metadata must appear in the matching `-ag-*` report's `## Errors` section, not only in `validator.ini` or logs.
- The `## Errors` section must include at least UID, path, bad field, current value, and error reason.

Suggested error/dead-end names:

- `canonical_owner_invalid`: malformed `CANONICAL_OWNER`.
- `canonical_owner_unknown`: owner UID is not present in `validator.ini [files]`.
- `canonical_owner_cycle`: canonical owner chain repeats, including direct self-ownership.
- `canonical_owner_file_invalid`: `FILE` used outside singular `by-file`.
- `canonical_owner_file_missing`: singular file root has valid projected path but does not have `CANONICAL_OWNER:FILE`.
- `emitter_uids_invalid`: malformed `EMITTER_UIDS`.
- `emitter_uid_unknown`: emitter UID is not present in `validator.ini [files]`.
- `emitter_duplicate`: duplicate UID in one emitter list.
- `emitter_inactive_has_data`: blank or `RECONSTRUCTABLE:FALSE` item has nonblank emitter values or nonblank reconstruction code.
- `emitter_code_without_route`: nonblank reconstruction code with blank `EMITTER_UIDS`.
- `emitter_route_cycle`: emitter chain repeats.
- `emitter_route_dead_end`: emitter chain does not surface to a valid file root.
- `emitter_route_ineligible`: route tries to pass through an item that cannot participate in emission.
- `emitter_root_invalid_projected_path`: route reaches a file root with blank, `NONE`, or invalid projected path.

## Validator Implementation Plan

### 1. Constants and Dataclasses

In `tools/validator_background.py`:

- Replace or supplement:
  - `AUTOGEN_PARENT_UID_LINE_RE`
  - `AUTOGEN_PARENT_POSITION_LINE_RE`
  - `AUTOGEN_PARENT_UID_PREFIX`
  - `AUTOGEN_PARENT_POSITION_PREFIX`
  - `AUTOGEN_PARENT_SECTION`
  - `AUTOGEN_PARENT_POSITION_SECTION`
  - `AUTOGEN_CHILDREN_SECTION`
  - `AUTOGEN_ROOT_SECTION`

- Add:
  - `CANONICAL_OWNER_LINE_RE`
  - `EMITTER_UIDS_LINE_RE`
  - `EMITTER_POSITION_LINE_RE`
  - `CANONICAL_OWNER_PREFIX`
  - `EMITTER_UIDS_PREFIX`
  - `EMITTER_POSITION_PREFIX`
  - `CANONICAL_OWNER_SECTION`
  - `EMITTER_UIDS_SECTION`
  - `EMITTER_POSITION_SECTION`
  - `AUTOGEN_EMITTER_CHILDREN_SECTION`
  - `AUTOGEN_ROOTS_SECTION`
  - `AUTOGEN_DEAD_END_SECTION`

- Change `AutogenMetadata` from:
  - `parent_uid: str`
  - `parent_position: int | None`
  - `parent_position_raw: str`

  to:
  - `canonical_owner: str`
  - `emitter_uids: list[str]`
  - `emitter_uids_raw: str`
  - `emitter_position: int | None`
  - `emitter_position_raw: str`

- Change `AutogenReportEntry` similarly:
  - add `canonical_owner`
  - add `emitter_uids`
  - add `dead_end_detail`
  - replace `parent_uid`.

### 2. Header Insertion and Repair

Current insertion occurs around the autogen metadata block and restores missing `AUTOGEN_PARENT_UID`. Update this logic:

- Insert or restore `CANONICAL_OWNER` for every validator-managed item doc.
- Insert or restore `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, and code block only for docs eligible for reconstruction metadata.
- For non-reconstructable-capable docs that still need ownership tracking, insert only `CANONICAL_OWNER` where appropriate.
- Do not add reconstruction metadata to excluded folders unless the existing rules already allow it.
- Preserve existing code block content.
- Preserve existing position value by renaming `AUTOGEN_PARENT_POSITION_OPTIONAL` to `EMITTER_POSITION_OPTIONAL`.

### 3. Parsing Rules

Add parsers:

- `parse_canonical_owner_line(line) -> tuple[str, bool]`
- `parse_emitter_uids_line(line) -> tuple[str, list[str], bool]`
- `parse_emitter_position_line(line) -> tuple[str, list[int | None], bool]`

Validation:

- `CANONICAL_OWNER` accepts `NONE`, `FILE`, blank only during legacy migration, or one UID.
- `EMITTER_UIDS` accepts blank or comma-separated UIDs.
- `EMITTER_POSITION_OPTIONAL` accepts blank, one integer shared by all emitters, or a comma-separated list aligned with `EMITTER_UIDS`; empty list entries are allowed and mean no position for that emitter.
- More position entries than emitter entries is an error. Fewer position entries are treated as trailing blank positions.
- Spaces around commas should be normalized away.
- Unknown UID checks happen after `validator.ini` file map is loaded, not during line parse.
- `FILE` outside singular `by-file` is an error.
- Non-reconstructable canonical ownership chains are valid. Do not report `RECONSTRUCTABLE:FALSE` items as errors just because they have `CANONICAL_OWNER`.
- Canonical owner chains must still be valid acyclic relationships. Report self-ownership or repeated owner chains as `canonical_owner_cycle`.
- Nonblank `EMITTER_UIDS` or nonblank `RECONSTRUCTION_CPP CODE` on `RECONSTRUCTABLE:FALSE` or blank reconstructable state is an error. A blank managed `EMITTER_UIDS` line is allowed only on reconstruction metadata scoped docs.
- `RECONSTRUCTION_CPP CODE` with no `EMITTER_UIDS` should be an error or at least a strong error-class report, because reconstructable code would not be emitted.

### 4. Registry Changes

Update registry write logic:

- Write `CANONICAL_OWNER_SECTION[uid] = metadata.canonical_owner`.
- Write `EMITTER_UIDS_SECTION[uid] = ",".join(metadata.emitter_uids)`.
- Write `EMITTER_POSITION_SECTION[uid] = metadata.emitter_position_raw`.
- Store owner metadata for `by-file` pages even though they do not appear in reconstruction metadata.
- Store valid file roots in a root-capable section keyed by UID, using `CANONICAL_OWNER:FILE` plus `PROPOSED_RECONSTRUCTION_PATH` status.
- Stop writing old `AUTOGEN_PARENT_SECTION` and `AUTOGEN_PARENT_POSITION_SECTION` after migration apply.
- During compatibility mode, read old sections if new sections are missing.
- Replace singular `[autogen_root]` semantics with a multi-root representation. Use either `[autogen_roots] uid = root1,root2` or a normalized edge section such as `[autogen_emitted_roots] uid = root_uid;root_uid`.
- Track coded output as `(uid, root_uid)` internally. Derive report-level `coded` from whether the UID emitted to at least one root.

Update cleanup:

- Removing a UID must remove it from canonical owner, emitter, root, dead-end, status, and error sections.
- Removing a UID must remove it from every other item's emitter list in `AUTOGEN_EMITTER_CHILDREN_SECTION` rebuild output.

### 5. Emission Graph

Replace `build_autogen_children(metadata_by_uid)` with an emitter graph builder:

- For each reconstructable metadata item:
  - if `EMITTER_UIDS` blank, no output edge.
  - for each emitter UID, add child edge `emitter_uid -> child_uid`.

Sort children using the `EMITTER_POSITION_OPTIONAL` value for the specific emitter edge. Positioned children come first by ascending numeric value. Children with the same value, and children with no position, preserve first-seen scan order rather than forcing UID order.

Multi-emitter behavior:

- A child can appear under multiple emitter parents.
- Assembly must treat cycles per route, not globally.
- The same child can be generated in multiple root files when multiple emitter chains reach different file roots.
- Avoid duplicate insertion under the same emitter if the same UID is repeated.

### 6. Root Resolution

Replace singular `resolve_autogen_root(uid)` with:

```text
resolve_emitter_roots(uid) -> list[root_uid], list[errors], list[dead_ends]
```

Resolution rules:

- Start from each `EMITTER_UIDS` entry.
- Walk emitter chains until a file root is reached.
- A singular `by-file` page with `CANONICAL_OWNER:FILE` and valid `PROPOSED_RECONSTRUCTION_PATH` is a root.
- A singular `by-file` page with a valid `PROPOSED_RECONSTRUCTION_PATH` but missing/invalid `CANONICAL_OWNER:FILE` should be reported as an owner/root consistency error.
- A `by-file` page with `PROPOSED_RECONSTRUCTION_PATH:NONE` is not an emission root.
- A non-file item with no emitter route is a dead-end only if this route is required to emit code.
- Unknown UID, invalid UID, cycle, invalid root path, and ineligible emitter are errors or dead-end details depending on severity.

### 7. Generated C++ Assembly

Update assembly to use emitter children:

- Root files are generated from valid `by-file` roots.
- `[[CHILDREN]]` insertion uses children from `AUTOGEN_EMITTER_CHILDREN_SECTION`.
- `CANONICAL_OWNER` is ignored during C++ assembly.
- Keep generated sentinel and backup behavior.
- Ensure multi-emitter output does not use a global `coded_uids` set that suppresses legitimate emission into a second root. Track coded state as `(uid, root_uid)` for assembly, and derive report-level `coded` from whether the UID emitted anywhere.

### 8. Report Rendering

Update:

- `autogen_report_stats`
- `render_autogen_report`
- `autogen_report_entries`

Required changes:

- Replace `Parent` column with `Canonical Owner` and `Emitters`.
- Replace `Total_Reconstructable_Unassigned` with `Total_Reconstructable_NoOwner`.
- Add `Total_Reconstructable_Emits`, `Total_Reconstructable_NonEmits`, `Total_Reconstructable_MultipleEmitters`, and `Total_DeadEnds`.
- Add `## Dead Ends` and `## Errors` sections after the main table.
- Always render metadata validation errors into the `## Errors` section for that report, including `FILE` misuse, malformed owner values, unknown owner UIDs, malformed emitter lists, unknown emitter UIDs, emitters/code on non-reconstructable items, and invalid emitter routes.
- Continue including generated file destination where known.
- Use `no-owner`, not `unassigned`.

### 9. CLI and Modes

Add a dedicated migration mode. Suggested commands:

```powershell
python tools\validator.py --mode migrate-autogen --dry-run
python tools\validator.py --mode migrate-autogen --apply
python tools\validator.py --mode clear-dryrun-files --apply
python tools\validator.py --mode autogen --dry-run --use-existing-dryrun
python tools\validator.py --mode autogen --apply
python tools\validator.py --mode full --apply
```

Important: `--dry-run` for this migration is an artifact-writing dry run. It is not the same as the validator's current no-`--apply` dry run, which only reports what would change. `--dry-run` must be mutually exclusive with `--apply` and must write only `.dryrun` files/state.

Keep the existing no-`--apply` behavior for normal validator modes unless explicitly changed. For migration mode, a no-`--apply` and no-`--dry-run` invocation should be report-only and must not write either live files or dry-run files.

Migration mode must run through `validator.py` queue, not by directly invoking `validator_background.py`.

Dry-run mode must write a complete parallel test surface, not only a text report:

- For every scanned `by-*/*.md` file that would be updated, create a sibling dry-run document such as `<original>.md.dryrun`.
- The dry-run document contains the fully migrated header/body that would be written to the real file.
- Normal validator scans must ignore `*.dryrun` files.
- Dry-run validator scans must be able to choose the dry-run files as the input source instead of regenerating from originals every time.
- Implement dry-run input selection as a logical-path overlay in `validator_background.py`, not as normal `--file` path normalization in `validator.py`. The frontend currently normalizes only `--file` values to live docs-root-relative `.md` paths; `.md.dryrun` files should remain internal artifacts mapped back to their logical live `.md` path.
- Generated outputs from a dry-run scan must also be written as dry-run artifacts, for example `auto-generated/-ag-memory-coverage.md.dryrun` and generated C++ outputs as `<name>.cpp.dryrun`.
- Dry-run state must be duplicated too, including `tools/validator.ini.dryrun` and any other tool-owned state/config produced by the run. If later JSON state exists, write `*.json.dryrun` alongside it.
- Every dry-run artifact write must be recorded in a manifest such as `tools/autogen_owner_emitter_migration_dryrun_manifest.json`.
- `clear-dryrun-files --apply` removes only artifacts listed in the manifest and verified to still have dry-run marker content. It must not delete arbitrary `*.dryrun` files.

Queue/dedup changes:

- Add `migrate-autogen` and `clear-dryrun-files` to `validator_background.py` mode choices and `queued_command_mode()`.
- Treat `migrate-autogen --dry-run`, `migrate-autogen --apply`, and `clear-dryrun-files --apply` as write jobs for queue ordering.
- Do not deduplicate or merge dry-run artifact jobs with live `full`, `documented`, `autogen`, or `rescore` jobs.
- If strong dedup is enabled, a live apply job must wait behind or run separately from a dry-run artifact job because they write different state files.

## `memory_ranges.py` Implementation Plan

Update independent header parsing:

- Replace `AUTOGEN_PARENT_UID_RE` with:
  - `CANONICAL_OWNER_RE`
  - `EMITTER_UIDS_RE`
- Change `RangeRecord.parent_uid` to:
  - `canonical_owner`
  - `emitter_uids`
- Replace `assigned` property with:
  - `has_owner`
  - `emits`
  - `multiple_emitters`

Report updates:

- Rename `unassigned` to `no-owner`.
- Add reconstructable emission stats:
  - `emits`
  - `non-emits`
  - `multiple-emitters`
- Continue keeping byte coverage classification independent of emission status.
- Regenerate `auto-generated/by-memory-tool-report.md` after migration.

Dry-run support:

- Add `report --dry-run` to write `auto-generated/by-memory-tool-report.md.dryrun`.
- Add `--use-existing-dryrun` so the scanner reads `by-memory/*.md.dryrun` files where present.
- Because `RANGE_FILE_RE` currently expects filenames ending in `.md`, dry-run mode must strip the trailing `.dryrun` before range parsing and keep the logical file name as `<range>.<name>.md`.
- Add `memory_ranges.data.dryrun` if any dry-run mode mutates or tests memory range config. Normal report-only dry-run can read live `memory_ranges.data` but must record that choice in the dry-run report header.
- `clear-dryrun-files --apply` in validator should remove memory-ranges dry-run outputs only if they are listed in the shared dry-run manifest.

## Documentation Update Plan

### Operational Docs

Update these first because agents rely on them:

- `by-structure.md`
- `tools/validator_README.txt`
- `tools/memory_ranges_README.md`
- `by-file/-guidance.md`
- `by-memory/-guidance.md`
- `by-class/-guidance.md`
- `by-type/-guidance.md`
- `by-global/-guidance.md`

Required wording changes:

- Replace `AUTOGEN_PARENT_UID` with separate `CANONICAL_OWNER` and `EMITTER_UIDS`.
- Explain that `CANONICAL_OWNER` is an ownership/research claim and never emits code.
- Explain that `EMITTER_UIDS` is the emission route.
- Replace `unassigned` with `no-owner`.
- Explain `FILE` and the non-file `FILE` error.
- Explain dead-ends and how agents should resolve them.
- Explain that reconstructable code must either emit through a route to file or be deliberately left without code until ready.
- Update all examples.

### Agent Docs

Update:

- `tools/leaser/Agents/Agent-A001/goal.md` through `Agent-A010/goal.md`
- `tools/leaser/Agents/Agent-B001/goal.md` through `Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-C001/goal.md` through `Agent-C003/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- active `Supervisor_notes.md` if it contains open old-model instructions

Required agent instruction changes:

- Work queues should say `no-owner`, not `unassigned`.
- Agents must set `CANONICAL_OWNER` when they have an ownership conclusion.
- Agents must set `EMITTER_UIDS` only when they have a justified emission route to generated source.
- B agents must stop recommending "parentless" reconstructable emitted items if emission is required. They should identify one or more emitters, create a real file/root if justified, or explicitly classify the item as non-emitting until a route is proven.
- Agents must understand multiple emitters are allowed when the same source snippet must be emitted from more than one generated root.
- Agents must treat dead-ends as repair work.

### Existing Data Docs

After tool support exists, run migration over existing singular docs:

- Add or replace `CANONICAL_OWNER`.
- Add or replace `EMITTER_UIDS`.
- Replace old position header with `EMITTER_POSITION_OPTIONAL`.
- Preserve code blocks.
- Preserve scores and UIDs.

After migration, run:

```powershell
rg -n "AUTOGEN_PARENT_UID|AUTOGEN_PARENT_POSITION_OPTIONAL|\\bunassigned\\b|parent UID|parent_uid|Total_Reconstructable_Unassigned|\\| UID \\| Status \\| Parent" source-3\project-documentation
```

Then update remaining live docs manually. Historical reports may keep old wording only if clearly marked as pre-migration evidence.

Cleanup standard:

- There must be zero live header lines named `AUTOGEN_PARENT_UID` or `AUTOGEN_PARENT_POSITION_OPTIONAL`.
- Operational docs, current agent goals, current supervisor docs, generated reports, and active notes must not use old `unassigned` or parent-UID terminology.
- Existing change logs and executed research reports should be updated where practical. If old terminology is preserved for history, add a clear pre-migration note in that file or section.
- Generated reports must not retain `Total_Reconstructable_Unassigned` or `| UID | Status | Parent |`.
- `tools/tool-updates.md` may retain old names only as migration references.

## First-Run Migration Plan

### Preflight

1. Confirm the user backup exists.
2. Pause or stop active agents that might edit headers during migration.
3. Check current state:

```powershell
git -C source-3\project-documentation status --short
python source-3\project-documentation\tools\validator.py --mode full
python source-3\project-documentation\tools\memory_ranges.py
```

4. Save baseline generated reports:
   - `auto-generated/-ag-*-coverage.md`
   - `auto-generated/by-memory-tool-report.md`
   - `project-level/-auto-completion-stats.md`
   - `tools/validator.ini`

### Dry Run 1: Header Migration Preview

Run:

```powershell
python source-3\project-documentation\tools\validator.py --mode migrate-autogen --dry-run
```

Expected dry-run behavior:

- Count of docs that would receive `CANONICAL_OWNER`.
- Count of docs that would receive `EMITTER_UIDS`.
- Count of old `AUTOGEN_PARENT_UID` values copied to `CANONICAL_OWNER`.
- Count of old `AUTOGEN_PARENT_UID` values copied to `EMITTER_UIDS`.
- Count of singular `by-file` docs defaulting to `CANONICAL_OWNER:FILE`.
- Count of new non-file docs defaulting to `CANONICAL_OWNER:NONE`.
- List of invalid old parent values.
- List of old reconstructable code blocks with missing parent/emitter.
- List of any non-file docs that would incorrectly get `FILE`.
- Create dry-run sibling files for every scanned `by-*` Markdown document that would change, using the format `<original>.md.dryrun`.
- Create dry-run copies of generated outputs, using the format `<generated>.dryrun`.
- Create dry-run `auto-generated/-ag-*-coverage.md.dryrun` reports that can be compared against the live pre-migration `auto-generated/-ag-*-coverage.md` reports.
- Create dry-run tool state, especially `tools/validator.ini.dryrun`.
- If any future validator state is JSON, create the matching `*.json.dryrun` file with the migrated data.
- Create or update `tools/autogen_owner_emitter_migration_dryrun_manifest.json` with every dry-run artifact path, source live path, artifact type, creation timestamp, and checksum.
- Dry-run artifacts must include a marker comment or manifest-only checksum that lets cleanup verify they were produced by the migration tool.

Write a dry-run report to:

```text
tools/autogen_owner_emitter_migration_dryrun.md.dryrun
```

Dry-run report comparison requirement:

- Treat the generated `auto-generated/-ag-*-coverage.md.dryrun` files as the primary sanity check that header conversion preserved current behavior.
- For each pre-migration live `-ag-*` row, the dry-run row for the same UID should retain the same effective source path, generated destination, code-present state, and route outcome, aside from deliberate terminology/column changes.
- Old `Parent` values should appear as `Canonical Owner` for every migrated item unless the old value was blank or malformed.
- Old `Parent` values should also appear in `Emitters` only for items that are exactly `RECONSTRUCTABLE:TRUE`.
- Old `unassigned` rows should become `no-owner` only when the old parent was blank. Rows that had an old parent should not become `no-owner` unless the old value was malformed and is reported.
- Existing generated destinations should remain effectively the same for old assigned/coded reconstructable rows unless the dry-run report also records an explicit route error or dead-end that existed implicitly before.
- New stats such as `Total_Reconstructable_Emits`, `Total_Reconstructable_NonEmits`, `Total_Reconstructable_MultipleEmitters`, and `Total_DeadEnds` may add information, but they should reconcile with the old assigned/unassigned/coded counts through the migration mapping.
- Any large unexplained count delta between live `-ag-*` reports and dry-run `-ag-*.md.dryrun` reports is a migration blocker.

### Dry Run 2: Re-Run Against Existing Dry-Run Files

The second and later dry-runs must be able to use the existing dry-run artifacts as their input. This validates that the migrated files update normally and are not only a one-time projection from old headers.

Suggested command:

```powershell
python source-3\project-documentation\tools\validator.py --mode migrate-autogen --dry-run --use-existing-dryrun
```

Expected behavior:

- Read `<original>.md.dryrun` files where they exist.
- Read `tools/validator.ini.dryrun` instead of `tools/validator.ini`.
- Update the existing dry-run files in place, still without touching live `.md` files.
- Rebuild dry-run generated reports and generated C++ from dry-run input files.
- Use a dry-run file overlay because normal `rglob("*.md")` does not match `.md.dryrun` files. The overlay must map logical live path `by-memory/foo.md` to physical dry-run path `by-memory/foo.md.dryrun`.
- Keep logical paths in generated annotations and report rows as normal `.md` paths unless the report is explicitly describing the dry-run artifact path.
- Confirm a stable second dry-run has no unexpected rewrite churn.
- Confirm a normal live validator scan still ignores every `*.dryrun` file.
- Recompare the second dry-run `-ag-*.md.dryrun` reports against the first dry-run. Any difference should be limited to timestamps or explicitly documented derived fields; route/status/count churn means the dry-run overlay is not stable.

### Dry Run 3: Temporary Copy Validation

As an optional extra safety check before touching live files, run the same dry-run artifacts inside a temporary copy:

```powershell
Copy-Item source-3\project-documentation $env:TEMP\project-documentation-migration-test -Recurse
python $env:TEMP\project-documentation-migration-test\tools\validator.py --mode migrate-autogen --dry-run
python $env:TEMP\project-documentation-migration-test\tools\validator.py --mode migrate-autogen --dry-run --use-existing-dryrun
python $env:TEMP\project-documentation-migration-test\tools\validator.py --mode full --dry-run --use-existing-dryrun
python $env:TEMP\project-documentation-migration-test\tools\memory_ranges.py --dry-run --use-existing-dryrun
```

### Apply Migration

Run:

```powershell
python source-3\project-documentation\tools\validator.py --mode migrate-autogen --apply
```

Migration rules:

- If old `AUTOGEN_PARENT_UID` is nonblank:
  - If the old value is a well-formed UID:
    - Set `CANONICAL_OWNER` to that UID for every migrated item, including `RECONSTRUCTABLE:FALSE` and blank reconstructable items.
    - Set `EMITTER_UIDS` to that UID only for items that are exactly `RECONSTRUCTABLE:TRUE`.
    - Leave `EMITTER_UIDS:` blank for `RECONSTRUCTABLE:FALSE` and blank reconstructable items, even if they had an old parent UID.
    - If the UID is not present in `[files]`, preserve it in `CANONICAL_OWNER` and, for `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS`, but report `canonical_owner_unknown` and/or `emitter_uid_unknown`. Do not silently replace an unknown but well-formed legacy UID with `NONE`.
  - If the old value is malformed:
    - Do not write the malformed value into `CANONICAL_OWNER` or `EMITTER_UIDS`.
    - Set `CANONICAL_OWNER:NONE`, leave `EMITTER_UIDS:` blank, and record the raw malformed value in the migration report.
    - Report a migration error such as `legacy_parent_invalid` plus the normal metadata error row so the bad source line is auditable.
- If old `AUTOGEN_PARENT_UID` is blank:
  - For singular `by-file` roots, set `CANONICAL_OWNER:FILE` when they have a valid source-root role.
  - For all other items, set `CANONICAL_OWNER:NONE`.
  - Set `EMITTER_UIDS:` blank.
- Rename `AUTOGEN_PARENT_POSITION_OPTIONAL` to `EMITTER_POSITION_OPTIONAL`.
- Preserve `RECONSTRUCTION_CPP CODE`.
- Preserve `RECONSTRUCTABLE`.
- Preserve UID, completion, confidence, and projected path lines.
- Do not infer multiple emitters during migration.
- Do not try to fix questionable old parent choices during the mechanical migration. Flag them for follow-up if the old parent appears to be an emission shortcut rather than the true canonical owner.

Header conversion table:

```text
Old AUTOGEN_PARENT_UID | RECONSTRUCTABLE state | New CANONICAL_OWNER | New EMITTER_UIDS | Notes
blank                  | any                   | FILE for valid by-file roots, else NONE | blank | by-file roots do not receive reconstruction metadata
valid UID              | TRUE                  | old UID             | old UID          | preserves current output behavior
valid UID              | FALSE or blank        | old UID             | blank            | preserves documentation relationship only
unknown but valid UID  | TRUE                  | old UID             | old UID          | preserve and report unknown UID errors
unknown but valid UID  | FALSE or blank        | old UID             | blank            | preserve and report owner unknown
malformed value        | any                   | NONE                | blank            | raw value only in migration report/error
```

### Post-Migration Validation

Run:

```powershell
python source-3\project-documentation\tools\validator.py --mode full --apply
python source-3\project-documentation\tools\validator.py --mode autogen --apply
python source-3\project-documentation\tools\memory_ranges.py
```

Then verify:

```powershell
rg -n "AUTOGEN_PARENT_UID|AUTOGEN_PARENT_POSITION_OPTIONAL" source-3\project-documentation
rg -n "\bunassigned\b|parent UID|parent_uid" source-3\project-documentation
```

Remaining matches must be either:

- historical pre-migration notes clearly marked as historical, or
- items still needing documentation cleanup.

### Rollback

If validation fails:

1. Do not keep running additional scans.
2. Save failing logs and migration report.
3. Restore from the user's backup or from git/validator generated backups.
4. Fix the migration code and rerun dry-run.

### Dry-Run Cleanup

After dry-run validation is complete and before final apply, remove dry-run artifacts:

```powershell
python source-3\project-documentation\tools\validator.py --mode clear-dryrun-files --apply
```

Cleanup must remove only files generated by dry-run mode:

- `*.md.dryrun`
- `*.cpp.dryrun`
- `*.ini.dryrun`
- `*.json.dryrun`
- dry-run generated reports under `auto-generated`
- dry-run migration reports/logs that are explicitly marked as dry-run artifacts

Cleanup requirements:

- Read `tools/autogen_owner_emitter_migration_dryrun_manifest.json`.
- Delete only manifest-listed paths.
- Before deleting a manifest-listed path, verify that it still has the expected checksum or dry-run marker recorded by the manifest.
- If a manifest-listed file has been manually edited since the dry run, skip it and report `dryrun_cleanup_conflict`.
- Remove the manifest only after all safe listed artifacts have been removed or conflicts have been reported.
- A no-`--apply` cleanup command must be report-only.

Cleanup must not remove live Markdown, live generated C++, live `validator.ini`, or normal validator logs.

## Data Integrity Rules

- Do not manually edit `validator.ini` except for confirmed recovery.
- Migration writes should be atomic.
- Keep a migration report listing every changed file and old/new metadata values.
- Keep compatibility parsing for old headers until the first full migration and docs update are complete.
- Do not delete old generated C++ without validator sentinel checks.
- Preserve UID identity during renames and header rewrites.
- Do not alter scores during metadata migration.

## Testing Plan

Add focused tests or fixture-driven validation for:

- Owner metadata scope includes singular `by-file` and excludes support/control docs.
- Reconstruction metadata scope excludes singular `by-file` but includes normal class/memory/type/global/function/item docs.
- Parsing `CANONICAL_OWNER:NONE`.
- Parsing `CANONICAL_OWNER:FILE`.
- Rejecting `FILE` outside `by-file`.
- Rejecting canonical owner self-links and owner-chain cycles.
- Parsing blank, single, and comma-separated `EMITTER_UIDS`.
- Rejecting unknown/malformed emitter UIDs.
- Allowing a blank `EMITTER_UIDS` header on inactive reconstruction metadata docs while rejecting nonblank emitter values or reconstruction code there.
- Migrating old `AUTOGEN_PARENT_UID` to `CANONICAL_OWNER` for all eligible items, and to `EMITTER_UIDS` only for items that are exactly `RECONSTRUCTABLE:TRUE`.
- Preserving reconstruction code blocks.
- Building a single-emitter route to a file.
- Building a multi-emitter route to two files.
- Detecting emitter cycles.
- Detecting a dead-end where a child emits to a class that does not emit to a file.
- Rendering dead-end and errors sections in each `-ag-*` report.
- Comparing pre-migration live `auto-generated/-ag-*-coverage.md` reports with migration dry-run `auto-generated/-ag-*-coverage.md.dryrun` reports and proving that UID rows, old parent-to-owner mapping, reconstructable parent-to-emitter mapping, generated destinations, and route/status counts reconcile except for intentional terminology/new-stat changes.
- Updating `memory_ranges.py` no-owner/emits/non-emits byte stats.
- Artifact dry-run writes only `*.dryrun` files and `validator.ini.dryrun`.
- Repeat dry-run reads existing `*.dryrun` files and produces stable output.
- Normal validator scans ignore `*.dryrun` files.
- `clear-dryrun-files --apply` deletes only manifest-listed files and refuses modified dry-run artifacts.
- Queue dedup does not merge dry-run artifact jobs with live apply jobs.
- `memory_ranges.py --dry-run --use-existing-dryrun` parses `*.md.dryrun` files as logical `.md` range filenames.

Minimum manual validation after tests:

```powershell
python source-3\project-documentation\tools\validator.py --mode full
python source-3\project-documentation\tools\validator.py --mode autogen
python source-3\project-documentation\tools\memory_ranges.py
```

Then inspect:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-type-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/by-memory-tool-report.md`
- a generated source file under `auto-generated/NexusTK`

## Implementation Order

1. Add owner/reconstruction scope helpers in `validator_background.py`: `is_owner_metadata_doc()` and `is_reconstruction_metadata_doc()`.
2. Add new parser constants, dataclass fields, and helper functions in `validator_background.py`.
3. Add compatibility reading for old headers without changing live write behavior.
4. Add new CLI parser options/modes and queue/dedup classification for `migrate-autogen`, `clear-dryrun-files`, `--dry-run`, and `--use-existing-dryrun`.
5. Add migration report-only mode for `migrate-autogen` without `--dry-run` or `--apply`.
6. Add migration dry-run mode that writes sibling `*.dryrun` Markdown files, generated outputs, dry-run state/config files, and a manifest.
7. Add repeatable dry-run mode that can use existing `*.dryrun` files and `validator.ini.dryrun` as input through a logical-path overlay.
8. Add manifest-based `clear-dryrun-files --apply`.
9. Add migration apply mode.
10. Update registry sections and root/emitter graph logic.
11. Update generated C++ assembly for emitter graph and multi-emitter output.
12. Add dead-end detection and exact error taxonomy.
13. Update report stats, table columns, dead-end section, and error section.
14. Update `memory_ranges.py`, including dry-run report output and `.md.dryrun` logical filename parsing.
15. Update validator and memory range README files.
16. Update `by-structure.md` and all folder guidance docs.
17. Update agent goals and supervisor docs.
18. Run first migration dry-run.
19. Run repeat dry-run against existing dry-run files.
20. Run clear-dryrun-files and confirm cleanup.
21. Run migration apply.
22. Run full validator, autogen, unresolved scan if needed, and memory range refresh.
23. Search for old terms and clean remaining live references.
24. Resume agent work only after reports show the new terminology and no migration errors.

## Open Decisions Before Coding

1. `EMITTER_POSITION_OPTIONAL` position model.
   - Decided: support both a single shared value and comma-aligned per-emitter values such as `1,,3`. Empty entries mean that emitter edge has no position.

2. Should `RECONSTRUCTION_CPP CODE` with blank `EMITTER_UIDS` be a hard validator error?
   - Recommended: yes, because the user requirement is to track that all reconstructable code actually gets emitted.

3. Should a reconstructable item with no code and no emitters be `non-emits` or `no-owner`?
   - Recommended: both concepts should be visible. The owner column says `no-owner` if `CANONICAL_OWNER:NONE`; the emission stats count it as `non-emits`.

4. Should historical executed B-agent research be bulk-edited?
   - Recommended: update active recommendations and templates. Preserve historical evidence sections only if marked as pre-migration terminology.

5. Should `CANONICAL_OWNER` exist in root/support/control docs?
   - Recommended: no. It should exist for validator-managed item docs, not generated reports, root docs, support ledgers, or excluded folders unless the validator already treats that file as an item.
