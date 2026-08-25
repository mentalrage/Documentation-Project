# Validator Author Agent Specs Header Plan

## Goal

Add a mandatory report provenance header to every B-agent research report:

```md
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
```

The new header is required alongside the existing report lifecycle headers:

```md
** TARGET-REPORT-UID:0000A0 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
```

For the initial migration, all existing executed reports and all current active B-agent `research/*.md` reports are to be treated as authored by `CHATGPT | 5.5 | xHigh`.

## Header Rules

- Header name: `AUTHOR-AGENT-SPECS`.
- Required format: three non-empty fields separated by literal pipe characters.
- Field 1: model base/provider label, for example `CHATGPT`, `Claude-Opus`, `Claude-Sonnet`.
- Field 2: model version, for example `5.5`, `4.8`.
- Field 3: thinking level, for example `xHigh`, `High`, `Medium`.
- Canonical migrated value: `CHATGPT | 5.5 | xHigh`.
- The validator should trim whitespace around fields and render the canonical form with one space on both sides of each pipe.
- Do not make the model/provider field an enum. It should reject empty fields and embedded `|` or newline characters, but otherwise allow future provider names without validator code changes.
- Header order should be stable: target UID first, author ID second, author specs third. If revalidation headers are present, render them after the provenance headers and before the report body.

## Validator Code Changes

Primary file:

`source-3/project-documentation/tools/validator_background.py`

Add constants near the current report header regexes:

- `REPORT_HEADER_SCAN_LINES = 15`
- `REPORT_AUTHOR_SPECS_HEADER_RE`
- `DEFAULT_AUTHOR_AGENT_SPECS = "CHATGPT | 5.5 | xHigh"`
- `RESEARCH_REPORT_AGENT_SPECS_SECTION = "research_report_agent_specs"`

Update `ensure_config_sections()` so `research_report_agent_specs` always exists in `tools/validator.ini`.

Add helper functions near the existing report-header helpers:

- `normalize_author_agent_specs(value: str) -> str`
- `make_report_author_specs_header(specs: str) -> str`
- `default_report_author_specs() -> str`
- Prefer a small structured return type for report headers, such as
  `ReportHeaderMetadata`, instead of expanding long positional tuples as the
  plan adds author specs, validation status, and revalidation reason fields.

Update these existing functions:

- `parse_report_headers(text)`:
  - Return `(target_uid, author_agent, author_specs)` instead of only two values.
  - Search the same initial header window as the current target/author headers. If needed, expand from the first 10 lines to the first 15 lines so reports with a title spacer still parse safely.
- `report_file_metadata(...)`:
  - Cache and return `report_header_specs`.
  - Treat old metadata cache entries that lack `report_header_specs` as stale for report-header purposes.
- `upsert_report_headers(text, target_uid, agent, specs)`:
  - Remove any existing `TARGET-REPORT-UID`, `AUTHOR-AGENT-ID`, and `AUTHOR-AGENT-SPECS` headers in the top header window.
  - Reinsert the three canonical headers in stable order.
  - Preserve newline style and final newline behavior exactly as the current helper does.
- `ResearchReportRecord`:
  - Add `agent_specs: str`.
- `report_record_from_file(...)`:
  - Accept `agent_specs` or parse it from the file.
  - For new report execution, use the normalized specs passed by `run_execute_report_command`.
- `add_report_registry_record(...)` and `remove_report_registry_path(...)`:
  - Store and remove `research_report_agent_specs[report_path]`.
- `run_execute_report_command(...)`:
  - Ensure the source report gets `AUTHOR-AGENT-SPECS`.
  - For current behavior without a CLI argument, insert `CHATGPT | 5.5 | xHigh`.
  - Record that value in the registry when the report is moved to `executed-b-agent-research`.
  - Clear any validator-owned `REPORT-VALIDATION-STATUS` / `REPORT-REVALIDATION-REASON` headers when a repaired report is successfully re-executed against the requested current UID.
  - Preserve any existing validator-owned footer history on reports that were returned for rework, then append the new execution/retargeting event instead of recreating the footer from scratch.
  - Change the action detail from `TARGET-REPORT-UID/AUTHOR-AGENT-ID` to include `AUTHOR-AGENT-SPECS`.
- Executed-report validation/reporting paths:
  - `run_execute_rescan_reports_command(...)`
  - `collect_research_tracker_errors(...)`
  - `research_tracker_report_records(...)`
  - Error if an executed report is missing `AUTHOR-AGENT-SPECS`.
  - Error if the header value differs from `research_report_agent_specs[report_path]`.
  - If the registry value is missing but the header exists, report a registry repair need rather than silently accepting it.
  - Do not let unregistered central reports, invalidated reports, or
    `needs-revalidation` reports count as ordinary coverage. Safe unregistered
    reports should be repaired through `execute-rescan-reports --apply`; stale
    or unrepairable reports should remain errors until revalidated, reworked, or
    invalidated.
- `run_execute_rescan_reports_command(...)`:
  - Verify the specs header and registry value in the same way it currently verifies UID, author, size, and hash.
- `run_executed_reassign_command(...)`:
  - Preserve the existing author specs value when moving a report to a new agent folder.
  - If the report lacks specs during reassign, insert the default migrated value and refresh the registry size/hash.
- `run_migrate_executed_reports_command(...)`:
  - Insert the default specs header while migrating older report locations into the central executed tree.
  - Store the specs value in the registry.

Wrapper file:

`source-3/project-documentation/tools/validator.py`

If a new lifecycle command is added for the one-time specs backfill, add the command alias there as well.

## Research Tracker Covered-Section Thinking Columns

Add thinking-level visibility to `auto-generated/-ag-research-tracker.md`
without changing coverage scoring.

Output requirement:

- In the per-folder covered sections only:
  - `### Covered Files - Reconstructable`
  - `### Covered Files - Not Reconstructable`
- Add three numeric columns:
  - `xHigh`
  - `High`
  - `Medium`
- Do not add these columns to:
  - the `## Summary` folder table,
  - `### Not-Covered Files - Reconstructable`,
  - `### Not-Covered Files - Not Reconstructable`,
  - `## Report Count Changes`,
  - `## Files With Empty Emitters`.

Counting rules:

- The columns count valid coverage-counting reports for that row, grouped by
  the third field of `AUTHOR-AGENT-SPECS`.
- With the default `Only_Count_B_Reports_For_Coverage = true`, this means the
  counts are based on valid B-agent reports only.
- Invalidated, unregistered, malformed, and `needs-revalidation` reports must
  not contribute to the thinking-level columns because they do not contribute to
  normal coverage.
- If multiple valid reports cover the same item, count each valid report in the
  matching thinking-level column.
- Normalize common casing only for bucket selection:
  - `xhigh` / `xHigh` / `XHIGH` -> `xHigh`
  - `high` / `High` -> `High`
  - `medium` / `Medium` -> `Medium`
- If a valid report uses another non-empty thinking level, keep the report's
  specs header valid but do not silently hide the mismatch: add a tracker error
  identifying the report path and unsupported tracker thinking bucket. Do not
  add an `Other` column unless the output requirement is changed later.

Implementation notes:

- Extend `ResearchReportRecord` or the derived tracker record data with a
  normalized `thinking_level_bucket` derived once from `agent_specs`.
- Do not reread report files to populate these columns. Use the same
  `report_file_metadata(...)` / `research_tracker_report_records(...)` data
  already required for specs validation.
- Extend `ResearchTrackerEntry` with per-row thinking counts, or compute the
  counts while building entries from `report_records_by_uid`.
- Change `research_tracker_table(...)` / `research_tracker_row(...)` to accept
  an `include_thinking_columns` flag. Call it with `false` for both not-covered
  sections and `true` for the two covered sections.
- Keep existing covered-row sorting unchanged unless a later task explicitly
  asks to sort by thinking level.

## Steady-State Performance Requirements

Do not optimize primarily for the one-time migration. The repeated paths that need to stay efficient are:

- `execute_report`
- `execute-rescan-reports`
- `collect_research_tracker_errors`
- generated research-tracker refreshes that read executed-report metadata
- `executed-reassign`

Required implementation constraints:

- Parse `AUTHOR-AGENT-SPECS` as part of the existing report-header parse. Do not add a second independent scan of the report text.
- Keep report-header parsing bounded to the top header window. Use a shared limit constant such as `REPORT_HEADER_SCAN_LINES = 15`; do not scan the full report body looking for `AUTHOR-AGENT-SPECS`.
- Prefer a helper that iterates only the initial lines needed for headers instead of repeatedly calling `text.splitlines()` and allocating all report lines for large reports.
- Extend `report_file_metadata(...)` to return target UID, author ID, author specs, size, sha256, and read error from one metadata path. Do not create a separate `report_file_agent_specs(...)` helper that rereads the same file.
- Extend the existing metadata cache entry with `report_header_specs`. A cache entry that already matches file `mtime_ns` and size should supply all report header fields and cached sha256 together.
- Avoid recomputing `file_sha256(path)` only to prove a cache entry is valid when `mtime_ns` and size are unchanged. Recompute sha256 when the file mtime/size changed, when writing/moving a report, or when a command explicitly refreshes size/hash. This avoids hashing every executed report on every rescan/tracker validation pass.
- In `run_execute_report_command(...)`, read the active report once, normalize the default or parsed specs once, upsert all headers once, and pass the canonical specs into `report_record_from_file(...)` / `add_report_registry_record(...)`. Do not parse the destination report again just to recover the specs value after moving it.
- In `executed-reassign`, preserve the already parsed or registry specs value and pass it through the header upsert/registry write. Do not recalculate report metadata more than once for the same file.
- In `collect_research_tracker_errors(...)` and `run_execute_rescan_reports_command(...)`, use the expanded `report_file_metadata(...)` result. Do not add an extra per-report read, regex pass, or config lookup loop for specs.
- Do not add a generated refresh solely because a report specs header was normalized. `execute_report` still refreshes/deferred-refreshes the research tracker because report coverage changed. Specs-only repair commands should skip generated refresh unless they also change report coverage/registration data.
- Keep action output summarized. If a command touches many reports, rely on existing per-action suppression instead of printing every changed path unless `--verbose` is used.
- Do not introduce a broad in-memory index of every executed report body. Keep only header/spec metadata in the existing metadata cache; full report bodies should not be retained beyond the current command's needs.
- The `xHigh` / `High` / `Medium` tracker columns must be computed from the
  already parsed `AUTHOR-AGENT-SPECS` metadata. Do not add a second report-file
  read or regex pass for these columns.

Acceptable one-time migration behavior:

- The migration may scan and rewrite the 1600+ existing reports once.
- The migration may recompute size/hash for reports it actually changes.
- Do not add complex migration-only caches, parallelism, or persistent side indexes unless they also benefit the repeated validator paths above.

## One-Time Migration Command

Add a dedicated validator lifecycle command:

```powershell
python .\tools\validator.py migrate-report-agent-specs --apply
```

Dry run should be the default without `--apply`.

The command should scan:

- `source-3/project-documentation/executed-b-agent-research/*/*.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B*/research/**/*.md`

Current audit before implementation found:

- Executed reports: 1607
- Active B-agent research reports: 10

Migration behavior:

- For every file in those two scopes, insert or replace `AUTHOR-AGENT-SPECS` with `CHATGPT | 5.5 | xHigh`.
- Preserve `TARGET-REPORT-UID` and `AUTHOR-AGENT-ID`.
- Insert the specs line immediately after `AUTHOR-AGENT-ID`.
- Preserve all report body content.
- Preserve newline style where possible.
- For executed reports, update the registry size and sha256 after writing the header.
- For executed reports, write `research_report_agent_specs[report_path] = CHATGPT | 5.5 | xHigh`.
- Do not change `research_report_executed_at`.
- Do not add report count change events.
- Do not move files.
- Do not refresh coverage counts except normal generated refresh side effects caused by validator command completion.
- Do not create footer history for active B-agent research reports that have never been executed. Active reports should only keep existing footer history when they were previously de-executed for rework.

Actions should be specific and easy to audit:

- `research_report_agent_specs_add`
- `research_report_agent_specs_update`
- `research_report_agent_specs_registry_update`
- `research_report_agent_specs_ok`
- `research_report_agent_specs_error`

## Validation After Implementation

Run from:

`source-3/project-documentation`

Required checks:

```powershell
python -m py_compile .\tools\validator_background.py .\tools\validator.py
python .\tools\validator.py execute-rescan-reports --queue-timeout 240
python .\tools\validator.py migrate-report-agent-specs --queue-timeout 240
python .\tools\validator.py migrate-report-agent-specs --apply --queue-timeout 240
python .\tools\validator.py execute-rescan-reports --apply --queue-timeout 240
```

Manual verification:

- Confirm every executed report has the three-line header block.
- Confirm every active `Agent-B*/research/*.md` report has the specs header.
- Confirm no report body content was removed or reordered.
- Confirm executed report registry size/hash values were refreshed after migration.
- Confirm a second `execute-rescan-reports` pass uses cached report metadata and does not rehash unchanged report files just to validate cached headers/specs.
- Confirm `execute-rescan-reports` and generated tracker errors no longer
  report missing specs after migration.
- Confirm `execute_report` on a test report inserts all three headers before moving the report.
- Confirm `executed-reassign` preserves an existing specs header.
- Confirm `-ag-research-tracker.md` adds `xHigh`, `High`, and `Medium` columns
  only to `### Covered Files - Reconstructable` and
  `### Covered Files - Not Reconstructable`, and that the counts match the
  coverage-counting reports' `AUTHOR-AGENT-SPECS` thinking level.

Suggested spot-check commands:

```powershell
rg -L "^\*\* AUTHOR-AGENT-SPECS:" .\executed-b-agent-research -g "*.md"
Get-ChildItem .\tools\leaser\Agents -Directory -Filter Agent-B* |
  ForEach-Object {
    $dir = Join-Path $_.FullName "research"
    if (Test-Path $dir) { rg -L "^\*\* AUTHOR-AGENT-SPECS:" $dir -g "*.md" }
  }
```

Both checks should return no report paths after migration.

## Executed Report Invalidated Archive And Revalidation Plan

This section plans the executed-report invalidation/revalidation extension. Do
not implement this by manually moving files or editing `tools/validator.ini`;
all state changes must be validator-owned.

### Goals

- Add a validator-owned archive for executed reports that are known invalid:
  `source-3/project-documentation/executed-b-agent-research/invalidated/`.
- Add a lifecycle command that targets an executed report under
  `executed-b-agent-research/` and moves it into the invalidated archive.
- Ensure invalidated reports do not count for coverage, report counts, research
  tracker covered rows, or report count change totals except as an explicit
  removal event at invalidation time.
- Add a metadata tag for executed reports that may no longer match current UID
  state after splits, UID removals, target path loss, or other target drift.
- Keep normal rename/move handling unchanged: a by-* file rename with the same
  UID should not mark reports stale.

### Invalidated Archive Layout

Create this root:

```text
executed-b-agent-research/invalidated/
```

Archive reports under per-agent subfolders to avoid filename collisions and to
avoid matching the current `executed_root.glob("*/*.md")` central-report scan:

```text
executed-b-agent-research/invalidated/B001/report-name.md
executed-b-agent-research/invalidated/B010/report-name.md
```

Also update `central_report_files(root)` defensively so it explicitly skips
`executed-b-agent-research/invalidated/**` even if a file is accidentally placed
directly under `invalidated/`.

### New Lifecycle Command

Add a dedicated command rather than overloading the existing rework command:

```powershell
python .\tools\validator.py executed-mark-invalid B002 report-name.md --apply
```

Optional path-targeting form, if added later, must not reuse `--file` because
that flag already means a by-* scan target in normal validator mode. Use
`--report-path` instead and validate the resolved path exactly like the
positional form:

```powershell
python .\tools\validator.py executed-mark-invalid --report-path executed-b-agent-research/B002/report-name.md --apply
```

Preferred initial implementation is the positional `agent_id + report_file`
form because it matches `execute-confirm-change`, `executed-reassign`, and
`invalidate-execute`.

Command behavior:

- Dry run by default.
- Resolve only files currently under `executed-b-agent-research/<agent>/`.
- Refuse paths already under `executed-b-agent-research/invalidated/`.
- Refuse files outside `executed-b-agent-research/`.
- Move the file to `executed-b-agent-research/invalidated/<agent>/`.
- Use `unique_destination_path(...)` to avoid overwriting previous invalidated
  reports.
- Remove the source path from executed-report registry sections with
  `remove_report_registry_path(...)`.
- Remove the report from `research_reports[uid]` through the normal registry
  helper.
- Clear any stored `research_report_errors[source_rel]`.
- Add a report count change event of `-1` for the report UID if the report was
  registered and previously counted.
- Do not change `research_report_executed_at` for any remaining reports.
- Do not move the report back to an active agent folder.
- Refresh/defer-refresh the research tracker like other executed-report
  lifecycle commands so coverage no longer includes the invalidated report.

Actions should be easy to audit:

- `research_report_mark_invalid`
- `research_report_invalid_registry_remove`
- `research_report_invalid_already_invalid`
- `research_report_invalid_error`

### Relationship To Existing Rework Path

Keep the existing command for reports that should return to an agent for repair:

```powershell
python .\tools\validator.py invalidate_execute B002 report-name.md --apply
```

Use `invalidate_execute` when the report should be de-executed, corrected by an
agent, and re-executed later. Use the new `executed-mark-invalid` command when
the report should be removed from coverage and archived as invalid instead of
returned for active work.

After rework, the normal path remains:

```powershell
python .\tools\validator.py execute_report B002 report-name.md CURRENTUID --apply
```

### Needs-Revalidation Metadata

Add a validator-owned metadata header for executed reports whose old target
relationship may be stale:

```md
** REPORT-VALIDATION-STATUS: needs-revalidation **
```

Optional reason header for auditability:

```md
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003BM **
```

Header rules:

- The status header is only needed when the report requires review.
- Valid initial status value: `needs-revalidation`.
- Keep the header in the same top header block as `TARGET-REPORT-UID`,
  `AUTHOR-AGENT-ID`, and `AUTHOR-AGENT-SPECS`.
- The reason value should be a short validator-produced diagnostic, not freeform
  agent prose.
- The validator should collapse duplicate status/reason headers in the top
  header window.
- Reports with `needs-revalidation` must not count as normal coverage until the
  marker is cleared by a validator command, even if the UID still exists. This
  covers semantic split/range drift that cannot be proven from registry data
  alone.

Recommended constants/helpers in `validator_background.py`:

- `REPORT_VALIDATION_STATUS_HEADER_RE`
- `REPORT_REVALIDATION_REASON_HEADER_RE`
- `REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION = "needs-revalidation"`
- `upsert_report_revalidation_headers(text, status, reason) -> str`
- `clear_report_revalidation_headers(text) -> str`

### When To Add Needs-Revalidation

Add or update the metadata only when the validator has concrete evidence that
the executed report may not describe the current target anymore:

- `target_uid_unknown` for a central executed report header or registry UID.
- `target_path_missing` for a registered executed report target path.
- `target_header_mismatch` between report header and registry UID.
- `target_header_missing` for a central report that cannot be safely registered.
- UID removal through `--remove-missing --apply` when reports are registered to
  the removed UID.

Do not add `needs-revalidation` for ordinary by-* file renames/moves where the
same UID still exists and the validator updates `[files]`.

Do not add `needs-revalidation` just because a report has `size_changed` or
`sha256_changed`; that is a post-execution content-integrity issue and should
remain handled by supervisor review plus `execute-confirm-change` if accepted.

### Validator-Owned Footer History

Add an append-only validator-owned history block at the bottom of executed
report files. This is a footer, not a top report header, and it records the
permanent lifecycle/audit trail for the report.

Proposed footer format:

```md
<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"timestamp":"2026-07-01T19:00:00-04:00","command_id":"000000004200","event":"executed","uid":"0000A0","agent":"B001","details":"report executed into central archive"} -->
<!-- {"timestamp":"2026-07-02T10:15:00-04:00","command_id":"000000004350","event":"needs-revalidation","uid":"0000A0","issue":"target_uid_unknown: 0000A0","details":"target UID no longer exists in validator.ini [files]"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
```

Rules:

- The footer block is validator-owned and must never be manually edited.
- The validator appends new events inside the block immediately before
  `VALIDATOR-REPORT-HISTORY:END`.
- If the block is missing, the validator may create it at EOF when a lifecycle
  command needs to write a history event.
- If the block is malformed, report a validator error and repair only through a
  dedicated validator command/path, not by hand.
- Keep entries as one JSON object per HTML comment line so they are durable,
  machine-parseable, and unlikely to interfere with report Markdown content.
- Preserve existing report body content and newline style.
- Do not count footer-only history edits as report content edits requiring
  supervisor `execute-confirm-change`; update the stored size/hash because the
  validator made the metadata edit.
- Do not add report count change events for footer-only writes.
- Footer writes must be idempotent per command/event where possible. A retry of
  the same command should not duplicate the same event if the command id and
  event payload already exist.

Minimum event fields:

- `timestamp`: command timestamp in ISO format.
- `command_id`: validator command id display string when available.
- `event`: short event name.
- `uid`: target UID at the time of the event when known.
- `agent`: author/owning agent when known.
- `issue`: diagnostic being recorded, when applicable.
- `old_uid`: old target UID for retarget/revalidation workflows, when known.
- `new_uid`: new/current target UID for re-executed or future retargeted
  workflows, when known.
- `source_path`: previous report path when a move occurs.
- `destination_path`: new report path when a move occurs.
- `details`: short human-readable explanation.

Events to record:

- `executed`: report first moved into `executed-b-agent-research`.
- `registered`: central report registered or repaired by
  `execute-rescan-reports`.
- `registry-error-detected`: validator found a report registry/UID/header
  problem.
- `needs-revalidation`: validator or supervisor marked the report for
  revalidation.
- `revalidation-cleared`: supervisor/validator cleared the revalidation marker
  after review.
- `de-executed-for-rework`: report moved back to active agent research through
  `invalidate_execute`.
- `invalidated`: report moved into
  `executed-b-agent-research/invalidated/<agent>/`.
- `reassigned`: report moved between executed agent folders.
- `content-change-confirmed`: size/hash accepted through
  `execute-confirm-change`.
- `retargeted-after-rework`: report was re-executed against a new/current UID
  after review. This should normally be represented by a de-execute event on
  the old central file plus a new execute event, but the new execution should
  include `old_uid` when the previous UID is known from the repair workflow.

First-entry behavior:

- For new executions, `execute_report` should create the footer and append the
  first `executed` event at the same time it inserts/normalizes the report
  headers and moves the report to central executed research.
- If `execute_report` receives a repaired report that already has footer
  history from a previous execution, preserve that footer and append a new
  event. If the previous header or history identifies an old UID that differs
  from the requested execution UID, append `retargeted-after-rework` with
  `old_uid` and `new_uid` in addition to the normal execution state change.
- For existing registered reports, the one-time migration may synthesize an
  initial `executed` event from existing registry data:
  `research_report_executed_at`, `research_report_uid`,
  `research_report_agent`, `research_report_original_path`, and the current
  central path. Mark the event details as `legacy registry reconstruction`.
- For existing unregistered reports, prefer not to invent a precise first
  execution entry. If the migration touches such files, it may add a
  `legacy-observed` event with file path, parsed header UID/agent if available,
  and details stating that the original execution time was unavailable.
- The one-time migration may omit footer creation for legacy unregistered files
  if preserving uncertainty is cleaner. It must not fabricate a confident
  execution timestamp for them.
- Active B-agent reports that have never been executed should not receive a
  synthesized footer during specs migration. If an active report already carries
  footer history because it was de-executed for rework, preserve it unchanged.

Commands that must write footer history:

- `execute_report`: append `executed`, and append/record
  `retargeted-after-rework` when the report carries a known old UID that differs
  from the current execution UID.
- `execute-rescan-reports --apply`: append `registered` for safe registry
  repair and `registry-error-detected` / `needs-revalidation` for stale report
  cases it tags.
- `executed-mark-needs-revalidation --apply`: append `needs-revalidation`.
- `executed-clear-revalidation --apply`: append `revalidation-cleared`.
- `invalidate_execute --apply`: append `de-executed-for-rework` before moving
  the report back to agent research.
- `executed-mark-invalid --apply`: append `invalidated` before moving the
  report to the invalidated archive.
- `executed-reassign --apply`: append `reassigned`.
- `execute-confirm-change --apply`: append `content-change-confirmed`.
- `migrate-report-agent-specs --apply`: append or synthesize the initial
  legacy event only if the migration is also responsible for introducing the
  footer history block.

Implementation notes:

- Add bounded footer parsing helpers separate from top-header parsing. Footer
  lookup may scan from EOF upward to find the history markers instead of
  scanning the full report multiple times.
- Store footer history only in the report file; do not mirror the entire event
  history into `validator.ini`.
- If the report is moved, write the footer event before the move so the moved
  file carries the event with it.
- Generated tracker errors may summarize the latest footer history state, but
  coverage must continue to use registry data and current report validity, not
  freeform history text.

### Commands That Should Trigger Revalidation Checks

Add a shared helper that can be called from lifecycle and UID-maintenance paths:

```text
mark_report_needs_revalidation(root, config, report_path, reason, apply)
mark_reports_for_uid_needs_revalidation(root, config, uid, reason, apply)
```

Use it from:

- `run_execute_rescan_reports_command(...)` for unregistered central reports
  with unknown/missing target metadata and registered reports with stale target
  metadata.
- `collect_research_tracker_errors(...)` so generated tracker errors show both
  the registry problem and whether the file has/needs the revalidation tag.
- `reconcile_missing_uids(...)` before removing a UID mapping with
  `--remove-missing --apply`, so registered reports for the removed UID are
  tagged before the UID disappears from `[files]`.

If a command tags a registered report, update that report's stored size/hash
only for the validator-owned metadata edit it just performed. Do not treat that
metadata edit as supervisor acceptance of unrelated content changes, do not
change `executed_at`, and do not add a report count change event unless the
report is actually invalidated or de-executed.

### Reporting In `-ag-research-tracker.md`

The tracker `## Errors` section should report stale executed reports with
specific diagnostics, for example:

```md
- `executed-b-agent-research/B001/example.md` needs revalidation: target_uid_unknown: 0003BM.
```

Reports under `executed-b-agent-research/invalidated/` should not appear in
coverage tables or normal executed-report errors. A separate future audit
section may count invalidated reports, but that count is not coverage.

### Documentation Updates For This Feature

Update these files when the validator implementation lands:

- `source-3/project-documentation/tools/validator_README.txt`
  - Document `executed-mark-invalid`.
  - Document when to use `invalidate_execute` versus `executed-mark-invalid`.
  - Document `REPORT-VALIDATION-STATUS: needs-revalidation`.
  - Document the validator-owned `VALIDATOR-REPORT-HISTORY` footer block and
    state that it must never be edited by hand.
  - State that invalidated reports do not count for coverage.
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - Add the supervisor rule: stale executed-report registry/UID drift must be
    handled with validator lifecycle commands, not manual moves.
  - State that report lifecycle history is validator-owned footer state and is
    not part of the agent-authored research body.
  - Tell supervisors to use `invalidate_execute` for rework and
    `executed-mark-invalid` for reports that should be removed from coverage.
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
  - Add review guidance for `needs-revalidation` reports.
  - Tell supervisors to read footer history as audit context but not to edit it.
  - Require claim-by-claim review before re-executing a fixed report against a
    new/current UID.
- `.codex/AGENTS.md`
  - Add a short durable pointer that invalidated executed reports and
    revalidation tags/history footer are validator-owned state.

### Validation For This Feature

After implementation, run:

```powershell
python -m py_compile .\tools\validator_background.py .\tools\validator.py
python .\tools\validator.py execute-rescan-reports --queue-timeout 240
python .\tools\validator.py executed-mark-invalid B002 report-name.md --queue-timeout 240
python .\tools\validator.py executed-mark-invalid B002 report-name.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py execute-rescan-reports --queue-timeout 240
```

Manual verification:

- Confirm the invalidated file moved under
  `executed-b-agent-research/invalidated/<agent>/`.
- Confirm the moved file no longer appears in `research_report_uid`,
  `research_reports`, coverage rows, or normal tracker report paths.
- Confirm a report count change event of `-1` was recorded only when the report
  had been registered/counting.
- Confirm `central_report_files(root)` ignores invalidated reports.
- Confirm stale UID reports get `REPORT-VALIDATION-STATUS: needs-revalidation`
  and a reason when `execute-rescan-reports --apply` is run.
- Confirm lifecycle commands append validator-owned footer history events with
  timestamp, command id, event, issue/reason, UID, and path details.
- Confirm normal by-* renames with unchanged UIDs do not add revalidation tags.

### Command Coverage Audit And Gaps

Current implemented validator commands already cover these cases:

| Case | Existing command path | Gap status |
| --- | --- | --- |
| Execute accepted active report | `execute_report B### report.md [UID] --apply` | Covered |
| Return executed report to active research for rework | `invalidate_execute B### report.md --apply` | Covered, but see event-count note below |
| Re-execute a fixed report against a current/new UID | `invalidate_execute ... --apply`, edit/review, then `execute_report B### report.md CURRENTUID --apply` | Covered |
| Repair safe central executed reports missing from registry | `execute-rescan-reports --apply` | Covered |
| Detect stale report UID/header/hash/size problems | `execute-rescan-reports` and tracker errors | Covered |
| Confirm intentional post-execution content change | `execute-confirm-change B### report.md --apply` | Covered |
| Move executed report to another agent folder | `executed-reassign OLD report.md NEW --apply` | Covered |
| Migrate old executed report locations into central tree | `migrate-executed-reports --apply` | Covered |
| Remove dead by-* UID mappings after files are deleted/split away | `full/documented --remove-missing --apply` | Covered |
| Handle normal by-* renames/moves with same UID | `file/documented --apply` path update and reference propagation | Covered |
| Rebuild generated coverage/tracker output | normal generated refresh, `--wait-generated`, or `--mode autogen --apply` | Covered |

Missing or incomplete command coverage that must be added:

1. Permanent invalid archive:
   - Add `executed-mark-invalid B### report.md --apply`.
   - This closes the gap where a report should stop counting for coverage but
     should not be returned to an active agent research folder.
2. Manual revalidation tagging:
   - Add `executed-mark-needs-revalidation B### report.md --reason "<short reason>" --apply`.
   - This closes the gap where a supervisor identifies semantic drift that the
     validator cannot detect mechanically, such as a split where the old UID
     still exists but the report likely describes only one child.
   - The command must update the report metadata headers and refresh stored
     size/hash for that validator-owned metadata edit.
3. Revalidation clearing:
   - Add `executed-clear-revalidation B### report.md --apply`.
   - This closes the gap where a supervisor verifies the report is still valid
     and no rework/invalid archive is needed.
   - The command should only operate on registered central reports that are not
     already in the invalidated archive.
   - The command should refuse to clear when live validator diagnostics still
     show `target_uid_unknown`, `target_path_missing`,
     `target_header_mismatch`, or `target_header_missing`.
   - It must update stored size/hash after removing the validator-owned
     revalidation headers.
4. Automatic revalidation tagging from detected UID drift:
   - Extend `execute-rescan-reports --apply` and `--remove-missing --apply`
     paths to set `REPORT-VALIDATION-STATUS: needs-revalidation` with a reason
     for report/UID drift.
   - This closes the gap where stale reports are visible as errors but the file
     itself does not carry an obvious review marker.
5. Validator-owned lifecycle history:
   - Add footer-history append support for all executed-report lifecycle
     commands that detect or change report state.
   - This closes the gap where issues and repair decisions are only visible in
     transient command output or `validator.ini`, rather than permanently
     attached to the report file.
6. Wrapper/parser aliases:
   - Add all new lifecycle commands to both `validator_background.py` and
     `validator.py` `COMMAND_ALIASES`, parser choices, queued-mode detection,
     lifecycle dispatch, and generated-refresh rules.
   - Commands to add:
     - `executed-mark-invalid`
     - `executed-mark-needs-revalidation`
     - `executed-clear-revalidation`
     - `migrate-report-agent-specs`
     - `migrate-report-history` if chosen instead of a combined
       `migrate-report-metadata` command

Do not add a direct `executed-retarget` command in the initial implementation.
Retargeting is high-risk because it can make an old report count against a new
UID without forcing claim-by-claim review. The safe path is already available:
`invalidate_execute`, supervisor/agent repair, then `execute_report ... CURRENTUID`.

Existing command behavior to fix while adding this feature:

- `invalidate_execute` currently can move an unregistered central report back to
  agent research, but it calls `add_report_change_event(..., -1, uid or "", ...)`
  even when the report was not registered/counting. Change it so a `-1` event is
  recorded only when `remove_report_registry_path(...)` returns a non-empty UID
  that was actually registered before the move.
- `execute-confirm-change` should not clear or rewrite
  `REPORT-VALIDATION-STATUS`; it should remain only a size/hash acceptance
  command.
- `executed-reassign` should preserve any existing revalidation headers and
  registry error state unless the move itself fixes only an author/folder
  mismatch.
- `execute-rescan-reports --apply` should not add report count events when it
  auto-registers historical safe reports or adds revalidation metadata. Count
  events should only reflect actual execute/de-execute/invalid archive actions.
- Footer-history-only edits should refresh stored size/hash for the affected
  report but should not be treated as report content edits and should not add
  report count events.

After these additions, every known state has a validator-owned exit path:

| State | Resolution path |
| --- | --- |
| Safe unregistered central report | `execute-rescan-reports --apply` |
| Stale UID/missing target but report may be salvageable | auto/manual `needs-revalidation`, then `invalidate_execute`, repair, `execute_report CURRENTUID` |
| Stale UID/missing target and report is invalid | `executed-mark-invalid --apply` |
| Supervisor-reviewed report still valid after drift | `executed-clear-revalidation --apply` |
| Intentional post-execution text edit | `execute-confirm-change --apply` |
| Wrong agent folder | `executed-reassign --apply` |
| Removed by-* file/UID | `full/documented --remove-missing --apply`, plus automatic report revalidation tagging |

## Full Plan Review Findings And Required Adjustments

This review reconciles the plan with the current validator code and the current
workflow/documentation layout. Apply these adjustments before implementation.

### Current Code Reality

- There is no standalone `validate_executed_reports(...)` function in the
  current validator. Executed-report validation is split across
  `run_execute_rescan_reports_command(...)`,
  `collect_research_tracker_errors(...)`, and
  `research_tracker_report_records(...)`. Implement the new specs,
  revalidation, invalidation, and footer-history checks in those actual paths.
- `validator.py` is not a thin pass-through. It has its own `COMMAND_ALIASES`,
  positional normalization, queue mode handling, and frontend-only flags. Every
  new lifecycle command must be added to both `validator.py` and
  `validator_background.py`.
- `queued_dedup_kind(...)` must treat every new mutating lifecycle command as
  `DEDUP_NONE`. Do not allow `executed-mark-invalid`,
  `executed-mark-needs-revalidation`, `executed-clear-revalidation`,
  `migrate-report-agent-specs`, or any history migration command to be
  coalesced as a read-only/global-refresh job.
- `research_tracker_report_records(...)` currently derives coverage records from
  central report files and can fall back to header UID/agent data. The planned
  behavior should be stricter: only registered, non-invalidated,
  non-`needs-revalidation`, currently valid reports should count as coverage.
  Safe unregistered reports should be repaired by `execute-rescan-reports
  --apply`; they should not silently count as covered before repair.
- `central_report_files(root)` currently scans central executed report files.
  It must explicitly exclude `executed-b-agent-research/invalidated/**` even if
  the archive layout changes or a file is accidentally placed directly under
  `invalidated/`.

### Implementation Order

Use this order to avoid corrupting registry state or creating misleading
coverage:

1. Add shared report-header parsing structures:
   - `REPORT_HEADER_SCAN_LINES`
   - structured report header metadata
   - author specs header parsing/normalization
   - revalidation status/reason header parsing
2. Add footer-history helpers:
   - parse existing history block
   - append idempotent event
   - create missing block at EOF
   - detect malformed block as a validator error
3. Extend registry sections and metadata cache:
   - `research_report_agent_specs`
   - cache fields for specs/status/revalidation reason where useful
   - ensure old cache entries missing new fields are treated as incomplete for
     report metadata
4. Update lifecycle commands:
   - `execute_report`
   - clearing revalidation headers on successful re-execution
   - preserving existing footer history on de-executed/reworked reports
   - `invalidate_execute`
   - `execute-rescan-reports`
   - `execute-confirm-change`
   - `executed-reassign`
   - `migrate-executed-reports`
5. Add new lifecycle commands:
   - `executed-mark-invalid`
   - `executed-mark-needs-revalidation`
   - `executed-clear-revalidation`
   - `migrate-report-agent-specs`
   - `migrate-report-history` if footer history backfill is not folded into a
     renamed/combined metadata migration command
6. Update generated tracker logic so coverage excludes invalidated,
   unregistered, and needs-revalidation reports.
   - Add `xHigh`, `High`, and `Medium` columns only to covered-row tables, using
     the same valid report set that makes the row covered.
7. Add migration/backfill behavior for existing files.
8. Update docs and skills after code behavior is verified.

### Migration Scope And Naming

The current plan names the one-time command `migrate-report-agent-specs`, but
the migration may also need to synthesize the first footer-history entry. There
are two acceptable implementation choices; choose one before coding:

- Preferred: keep `migrate-report-agent-specs` focused on the specs header and
  add a separate `migrate-report-history` command for footer-history backfill.
- Acceptable: rename the one-time command to `migrate-report-metadata` before
  implementation and use it for specs plus footer-history backfill.

Do not leave the implementation with a command named only for specs that also
does broad history migration without documenting that behavior in
`validator_README.txt` and command output.

### Footer History Safeguards

- Do not append `registry-error-detected` every time
  `execute-rescan-reports --apply` sees the same unchanged error. Use an issue
  signature, such as `event + report_path + uid + issue`, and append a new
  history row only when the issue first appears, changes, is cleared, or a
  command explicitly changes report state.
- `execute-confirm-change --apply` must append `content-change-confirmed` before
  refreshing stored size/hash, then store the hash of the final file containing
  the history event.
- `executed-reassign --apply`, `invalidate_execute --apply`, and
  `executed-mark-invalid --apply` must append the history event before moving
  the file so the moved file carries the audit row.
- If `invalidate_execute` moves a report back to active agent research, the
  footer remains with the report. B agents may read it but must not edit it.
- If a footer is malformed, do not silently rewrite the whole report. Report a
  clear validator error and provide a validator-owned repair path.

### Revalidation Semantics

- Any report with `REPORT-VALIDATION-STATUS: needs-revalidation` should be
  excluded from coverage until revalidation is cleared, even if the UID still
  exists. This covers semantic split drift that the validator cannot prove from
  registry data alone.
- `executed-clear-revalidation --apply` should run the same live checks used by
  `execute-rescan-reports` before clearing the marker. It should refuse to clear
  if target UID/header/path errors still exist.
- Manual revalidation tagging should require a concise reason. Empty or generic
  reasons should be rejected so the footer history remains useful.
- `size_changed` and `sha256_changed` remain content-integrity issues, not
  automatic revalidation issues. They should not by themselves set
  `needs-revalidation`.

### Path Targeting

- Avoid using `--file` for executed-report path targeting in new lifecycle
  commands because `--file` already means by-* scan target in normal validator
  mode and the frontend normalizes it for that purpose.
- If a path-targeting form is added, prefer `--report-path` and validate that it
  resolves under `executed-b-agent-research/<agent>/` and not under
  `executed-b-agent-research/invalidated/`.
- The initial implementation can avoid path targeting entirely and support only
  the safer `agent_id + report_file` form.

### Documentation Gaps To Close

- `tools/validator_README.txt` needs examples for each new lifecycle command,
  including dry run and `--apply` forms.
- `tools/validator_README.txt` should document that the research tracker's
  covered sections include `xHigh`, `High`, and `Medium` columns derived from
  valid coverage-counting report specs, and that those columns are informational
  only.
- Supervisor docs must state that a `needs-revalidation` report cannot be
  accepted as coverage until the supervisor either clears revalidation through
  validator or sends the report through rework/re-execution.
- B-agent docs/templates must state that top provenance headers are required,
  while footer history is validator-owned and not part of the authored report
  body.
- `.codex/AGENTS.md` should include the durable rule that generated reports,
  validator registry, invalidated archives, revalidation tags, and footer
  history are validator-owned.
- If `migrate-report-history` or `migrate-report-metadata` is chosen, add it to
  the docs checklist alongside `migrate-report-agent-specs`.

### Validation Gaps To Add

Add these checks to the implementation validation pass:

```powershell
python .\tools\validator.py executed-mark-needs-revalidation B002 report-name.md --reason "manual split review required" --queue-timeout 240
python .\tools\validator.py executed-mark-needs-revalidation B002 report-name.md --reason "manual split review required" --apply --wait-generated --queue-timeout 240
python .\tools\validator.py executed-clear-revalidation B002 report-name.md --queue-timeout 240
python .\tools\validator.py executed-clear-revalidation B002 report-name.md --apply --wait-generated --queue-timeout 240
python .\tools\validator.py execute-confirm-change B002 report-name.md --apply --wait-generated --queue-timeout 240
```

Manual checks:

- Re-running the same rescan should not append duplicate
  `registry-error-detected` footer events for the same unchanged issue.
- Marking a report `needs-revalidation` should remove it from coverage until
  cleared or re-executed.
- Clearing revalidation should restore coverage only when the report is
  registered, target UID/path/header checks pass, and the report is not
  invalidated.
- Invalidated reports should remain searchable on disk but absent from normal
  coverage and normal executed-report registry errors.

## Documentation And Skill Updates

Update these files after the validator change lands:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - Update `## Model And Reasoning` so B agents are created with model `gpt-5.5` and reasoning/thinking `xHigh` by default, matching the required migrated report specs value `CHATGPT | 5.5 | xHigh`.
  - Remove or narrow the current contradictory wording that says `Reasoning effort: high` and `Use xHigh only when...` for B-agent source-quality work.
  - Add a supervisor pool-audit rule: at each normal wait/check loop, and whenever creating or replacing a B agent, the supervisor must verify that active B agents are mapped to the correct folder and were created with the expected model/version/thinking level. Any mismatch should be treated like an identity/config mismatch: do not execute reports from that worker until corrected, restart/recreate the worker if needed, and record the correction in supervisor notes/assignment tracking.
  - Add the expected report specs to B-agent assignment/restart prompt guidance so reports written by those agents naturally use `** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **`.
  - Clarify whether A/C agents keep the existing pool default or also move to `xHigh`. If the feature is only for B-report provenance, state that the mandatory specs audit applies to B agents and B reports.
- `source-3/project-documentation/tools/validator_README.txt`
  - In the executed-report lifecycle section, show the new three-line header block.
  - Document `migrate-report-agent-specs`.
  - Document `VALIDATOR-REPORT-HISTORY` as a validator-owned footer history
    block that must never be manually edited.
  - State that missing or malformed specs headers are validator errors.
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - Add `AUTHOR-AGENT-SPECS` to the required B-agent report header list.
  - State the default for current agents is `CHATGPT | 5.5 | xHigh` unless a supervisor explicitly provides a different model/version/thinking value.
  - Add a supervisor reminder that B-agent report acceptance must compare the report specs header with the expected spawned-agent specs when those specs are known.
  - State that lifecycle history footer entries are validator-owned audit
    records and should be read, not edited, by agents.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - Add the header to report-writing requirements and the report lifecycle examples.
  - Keep the existing expected runtime rule, currently `GPT 5.5 with xHigh thinking only`, and align the exact report header spelling with it.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
  - Add the header line to the template.
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
  - Add specs-header presence to supervisor report review checks.
  - Add a supervisor review check that rejects or returns reports when the specs header is missing, malformed, or inconsistent with the supervisor-known model/version/thinking level for that worker.
  - Add footer-history review guidance: use it as audit context for
    revalidation/invalidated/retargeted reports, but never manually edit it.
- `.codex/AGENTS.md`
  - Add a short durable rule that project B-agent reports require target UID, author ID, and author specs headers.
  - Add a short durable rule that report lifecycle history footers are
    validator-owned and must not be edited by hand.
  - Route supervisor model/spec creation rules to `tools/leaser/Agents/Supervisor.md` rather than duplicating pool-management policy here.

Audit notes from the planning pass:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md` is the canonical supervisor pool-creation and supervision-loop document. It must be updated; otherwise supervisors can keep creating B agents at `high` while the B-agent reference and report specs require `xHigh`.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md` already says B agents should be GPT 5.5 with xHigh thinking. The implementation should preserve that rule and only add the concrete report header requirement.
- `source-3/project-documentation/tools/leaser/README.md` is lease-tool documentation and does not need this feature unless the implementation later adds leaser-enforced agent metadata, which is not part of this plan.
- Existing individual `Agent-B###/goal.md` files did not contain durable report-header/model-spec instructions in this audit. Do not bulk-edit all goal files for the durable rule; update the shared workflow/supervisor docs and migrate active report files. Future per-agent `goal.md` assignments may include the expected specs line when useful.
- `.codex/skills/ntk-b-agent-workflow/agents/openai.yaml` only exposes skill metadata and does not need a policy change for this feature.

## Failure Cases To Handle

- Missing specs header in an active report:
  - Normal `execute_report` should insert the default header and continue.
- Missing specs header in an executed report:
  - `execute-rescan-reports` and generated tracker errors should report it.
  - `migrate-report-agent-specs --apply` should repair it.
- Malformed specs header:
  - Report a clear validator error naming the exact file and malformed value.
  - Migration should replace malformed specs with `CHATGPT | 5.5 | xHigh` only in the explicit migration scope.
- Registry specs mismatch:
  - Report a mismatch like the existing author header mismatch.
  - `execute-confirm-change` should refresh size/hash only; it should not rewrite the specs header.
  - The migration command should be the repair path for old missing specs.
- Multiple specs headers in the first header window:
  - `upsert_report_headers` should collapse them into one canonical line.
- Malformed `REPORT-VALIDATION-STATUS` or `REPORT-REVALIDATION-REASON`:
  - Report a clear validator error naming the file and malformed value.
  - Do not count the report as normal coverage while the status/reason cannot
    be trusted.
  - Repair through validator-owned revalidation commands only.
- Malformed `VALIDATOR-REPORT-HISTORY` footer:
  - Report a clear validator error and do not append new lifecycle events until
    a validator-owned repair path fixes the footer structure.
  - Do not ask agents to hand-edit the footer.
- Duplicate footer events:
  - Repeated scans should not append duplicate issue events for the same
    unchanged problem.
  - State-changing commands may append a new event because the command itself is
    a new lifecycle action.
- Existing report has no reliable legacy execution timestamp:
  - Use a `legacy-observed` footer event or omit first-entry backfill for that
    file; do not fabricate a precise `executed` timestamp.

## Non-Goals

- Do not infer actual historic model/provider per report.
- Do not change report acceptance quality rules.
- Do not change coverage scoring.
- Do not add direct in-place executed-report retargeting in the initial
  implementation.
- Do not manually edit `tools/validator.ini`; all registry changes must be validator-owned.
