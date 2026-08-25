# Validator Executed-Research And Auto-Coverage Update Plan

Source directive: `tools/updates/validator_update_draft.md`.

This plan updates the queued validator frontend/background worker without editing
the draft file. It keeps normal validator single-job serialization, adds
command-driven B-report execution tracking, generates executed-research coverage
state, and adds the first validator-owned by-memory coverage report generator.

## Current State

- `tools/validator.py` is a queue frontend. It normalizes file arguments, writes
  queue jobs, starts `validator_background.py`, and relays output.
- `tools/validator_background.py` owns scanning, `validator.ini`, generated C++
  output, generated `auto-generated/-ag-*-coverage.md`, completion stats, and
  queue worker behavior.
- `project-documentation/executed-b-agent-research/` exists but is empty.
- Old executed B reports currently exist in:
  - `tools/leaser/Agents/Agent-B*/research/executed/`
  - `archived/b-agent-reports-20260623/Agent-B*/research/executed/`
- Current B reports do not consistently have durable target/author headers.
- Existing `auto-generated/-ag-memory-coverage.md` is reconstruction autogen
  routing coverage. It is not the requested executed-research tracker and should
  remain intact.
- Existing `by-memory/-coverage-report.md` stays intact. The new automated
  coverage output will be separate.

## Non-Goals And Guardrails

- Do not edit `tools/updates/validator_update_draft.md`.
- Do not update project skills, supervisor instructions, or agent goal files
  until the program has been run without dry-run and verified. After code and
  full validation, stop and ask the user before those instruction updates.
- Do not manually edit generated state that validator commands should own.
- Do not remove or rewrite existing manual coverage reports.
- Do not silently execute a report for a different agent folder than the command
  supplied, except for explicit reassign commands operating on central executed
  files.

## Part 1 Documentation Completion Note

User approval for the Part 1 skill/supervisor documentation update was given
after validator behavior was verified. The active docs have now been updated so
agents know:

- `auto-generated/-ag-research-tracker.md`,
  `auto-generated/-ag-coverage-report-by-memory.md`, and other `-ag-*`
  reports are validator-owned generated state.
- By-memory auto coverage summaries come from source `Item Summary` and
  `Nested` metadata and must not repeat fields already rendered by the
  generated report.
- Missing by-* files and stale executed-report registry state are fixed through
  validator lifecycle commands, not manual `tools/validator.ini`, queue JSON,
  lock-file, or generated-report edits.
- Current B-report execution uses `execute_report`, `invalidate_execute`,
  `execute-rescan-reports`, `execute-confirm-change`, and `executed-reassign`
  as documented in `tools/validator_README.txt`.

Updated active locations:

- `.codex/AGENTS.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `tools/validator_README.txt`
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `tools/leaser/Agents/SupervisorAssignments.md`
- `tools/leaser/Agents/no_owner_b-agent-tracker.md`
- `tools/leaser/Agents/b-report-coverage.md`
- `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md`

Archived `.codex/old` files and historical tracker row bodies were left as
legacy context.

## New Report Headers

Executed report files will use two plain Markdown header lines at the top:

```text
** TARGET-REPORT-UID:00015I **
** AUTHOR-AGENT-ID:B002 **
```

Rules:

- Parser accepts case-insensitive keys and optional surrounding whitespace.
- `TARGET-REPORT-UID` must be six uppercase base36 UID characters and must exist
  in `validator.ini [files]`.
- `AUTHOR-AGENT-ID` must match `[ABC][0-9]{3}` for future agent-type support, but
  the first implemented execution workflow is B-agent centered.
- If `execute_report AGENT FILE TARGETUID` is called, the validator inserts or
  replaces both headers before moving the report.
- If `execute_report AGENT FILE` is called without an override, the validator
  requires a detectable target UID. Detection order is header, report body, then
  filename prefix.
- Existing report body detection supports:
  - `Target: [UID:000123]`
  - `Target UID: 000123`
  - `Current target: by-...` resolved through `validator.ini [files]`
  - filename prefix `000123-...md`
- If detection is ambiguous or points to a missing UID/path, the command fails
  without moving the report and records the issue in generated tracker errors on
  the next tracker generation.

## New Validator.ini Sections

Add these sections during config load:

```ini
[research_reports]
00015I = executed-b-agent-research/B002/report.md;executed-b-agent-research/B002/report-2.md

[research_report_uid]
executed-b-agent-research/B002/report.md = 00015I

[research_report_agent]
executed-b-agent-research/B002/report.md = B002

[research_report_size]
executed-b-agent-research/B002/report.md = 26616

[research_report_sha256]
executed-b-agent-research/B002/report.md = <sha256>

[research_report_executed_at]
executed-b-agent-research/B002/report.md = 2026-06-24T12:34:56

[research_report_original_path]
executed-b-agent-research/B002/report.md = tools/leaser/Agents/Agent-B002/research/report.md

[research_report_errors]
executed-b-agent-research/B002/report.md = current-size 27000 differs from registered 26616
```

Storage rules:

- `[research_reports]` is a UID-to-semicolon-separated-path reverse index using
  the existing `parse_reference_sources` / `format_reference_sources` style.
- Per-report sections are keyed by documentation-root-relative central executed
  report path.
- Report paths are stored with forward slashes.
- Counts are derived from `[research_reports]`; no separate count field is stored.
- A full rescan can rebuild `[research_reports]` from `[research_report_uid]`.
- `size` and `sha256` are both tracked. The requested file-size change warning is
  emitted when size changes; same-size hash changes are also reported because
  they indicate post-execution content changes.

## Central Executed Report Layout

Central root:

```text
project-documentation/executed-b-agent-research/
```

Initial supported subfolders:

```text
executed-b-agent-research/B001/
executed-b-agent-research/B002/
...
executed-b-agent-research/unknown/
```

Rules:

- Normal execution with `B002` only searches
  `tools/leaser/Agents/Agent-B002/research/`.
- Normal invalidation with `B002` only searches
  `executed-b-agent-research/B002/`.
- `unknown` is allowed only for already-central reports with no reliable author.
- Duplicate target filenames in a destination folder are not overwritten. The
  validator appends `-2`, `-3`, etc. before the extension and records the actual
  stored path internally.
- Reassignment moves only already-executed central reports and updates author
  headers plus registry paths.

## New Command Syntax

The frontend will accept the requested positional command shape and normalize it
before queueing so dedup and mode detection stay correct.

```powershell
python .\tools\validator.py execute_report B002 report-name.md
python .\tools\validator.py execute_report B002 report-name.md 00015I
python .\tools\validator.py invalidate_execute B002 report-name.md
python .\tools\validator.py execute-rescan-reports
python .\tools\validator.py execute-confirm-change B002 report-name.md
python .\tools\validator.py executed-reassign B002 report-name.md B006
python .\tools\validator.py executed-reassign unknown report-name.md B006
python .\tools\validator.py migrate-executed-reports --apply
```

Apply semantics:

- All lifecycle modes honor the existing validator convention: without `--apply`
  they print planned actions and generated-file diffs as validator actions but do
  not move files, edit headers, write generated outputs, or write `validator.ini`.
- Supervisor-facing mutating calls must include `--apply`, for example:

```powershell
python .\tools\validator.py execute_report B002 report-name.md 00015I --apply
python .\tools\validator.py invalidate_execute B002 report-name.md --apply
python .\tools\validator.py execute-confirm-change B002 report-name.md --apply
python .\tools\validator.py executed-reassign B002 report-name.md B006 --apply
```

Background modes:

- `execute-report`
- `invalidate-execute`
- `execute-rescan-reports`
- `execute-confirm-change`
- `executed-reassign`
- `migrate-executed-reports`

Command details:

- `execute_report AGENT FILE [TARGETUID]`
  - Requires `AGENT` to match `[ABC][0-9]{3}`.
  - For B agents, searches only `tools/leaser/Agents/Agent-B###/research/FILE`.
  - Refuses to execute from another agent folder.
  - Inserts/replaces report headers when `TARGETUID` is supplied.
  - Adds missing author header.
  - Moves to `executed-b-agent-research/AGENT/`, collision-renaming as needed.
  - Registers path, UID, agent, size, sha256, executed timestamp, and original
    path.
  - Regenerates `auto-generated/-ag-research-tracker.md`.

- `invalidate_execute AGENT FILE`
  - Searches only `executed-b-agent-research/AGENT/FILE`.
  - Uses `[research_report_original_path]` when present; otherwise returns to
    `tools/leaser/Agents/Agent-B###/research/FILE`.
  - Collision-renames in the active research folder if needed.
  - Removes the central report from report registry sections and from the UID
    reverse index.
  - Regenerates the research tracker.

- `execute-rescan-reports`
  - Scans `executed-b-agent-research/*/*.md`.
  - Rechecks existing registry entries.
  - Reports unregistered files as errors instead of silently registering them.
  - Rebuilds `[research_reports]` from registered per-report metadata.
  - Updates tracker error section.

- `execute-confirm-change AGENT FILE`
  - Searches only `executed-b-agent-research/AGENT/FILE`.
  - Requires the report to already be registered.
  - Recomputes size and sha256 after supervisor review and clears stale change
    errors for that path.
  - Regenerates the research tracker.

- `executed-reassign OLD_AGENT FILE NEW_AGENT`
  - `OLD_AGENT` can be a real agent id or `unknown`.
  - Searches only `executed-b-agent-research/OLD_AGENT/FILE`.
  - Moves the file to `executed-b-agent-research/NEW_AGENT/`, collision-renaming
    as needed.
  - Updates author header, per-report registry keys, and UID reverse index.
  - Regenerates the research tracker.

- `migrate-executed-reports`
  - Dry-run by default; requires `--apply` to move files.
  - Scans old executed folders under both live agents and archived B-agent report
    snapshots.
  - Moves all found executed reports into central per-agent folders, including
    superseded/older filenames.
  - Registers each moved report when target UID can be detected.
  - If target UID cannot be detected, moves to the agent folder when the agent is
    known and records an error; unknown author files go to `unknown`.
  - Is idempotent: already-central files are not moved again, existing registry
    entries are not duplicated, and duplicate destination names are suffix-renamed.

## Generated `-ag-research-tracker.md`

Output path:

```text
auto-generated/-ag-research-tracker.md
```

Generation source:

- `validator.ini [files]`, `[completion]`, `[confidence]`, `[reconstructable]`
- report registry sections above
- central executed report files for error checks

Scope:

- Direct by-* Markdown entries in `validator.ini [files]`.
- Exclude entries where completion or confidence is `-1`.
- Split by by-folder.
- Split each folder into:
  - Not-Covered Files
    - Reconstructable, sorted by `(completion + confidence) / 2` low to high
    - Not Reconstructable, same sort
  - Covered Files
    - Reconstructable, sorted by report count descending, then most recent
      registered execution timestamp descending
    - Not Reconstructable, same sort

Top stats:

- Total tracked scored files.
- Total covered and not covered.
- Overall coverage percent.
- Per by-folder coverage percent.
- Per by-folder reconstructable and not-reconstructable coverage percent.
- Counts remain separate by agent type so future A/C report types do not mix with
  B-agent counts.

Rows include:

- UID link.
- Relative by-* path.
- completion/confidence/combined score.
- reconstructable state.
- report count.
- last executed timestamp.
- report path list.

Error section includes:

- Registered report file missing.
- Central file exists but is unregistered.
- Report target UID missing, malformed, or not in `[files]`.
- Report target path missing.
- Header target and registry target mismatch.
- Author header and folder/registry agent mismatch.
- File size changed after execution.
- File hash changed after execution.
- Duplicate registry references.

Generation is validator-owned with the existing Markdown autogen sentinel and
atomic writes.

## By-Memory Auto Coverage Report

Output path for the initial implementation:

```text
auto-generated/-ag-coverage-report-by-memory.md
```

Existing `by-memory/-coverage-report.md` remains untouched.

New by-memory metadata lines:

```text
*** Item Summary:  | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rules:

- Only ordinary by-memory Markdown files receive these lines. Control/support
  files whose name starts with `-` are excluded from injection.
- Lines are inserted after existing validator-managed reconstruction header/block
  and before the body heading.
- `Item Summary` is a single-line editable summary used as the generated row
  tail.
- `Nested` is an integer relative nesting delta from the previous address-sorted
  generated row. `1` indents under the previous row, `0` keeps the same level,
  and negative values lift back up, clamped at global level `0`.
- Initial injection attempts to parse the existing manual `by-memory/-coverage-report.md`
  rows by UID and reuse their summary and nesting level when a unique row is
  available. Ambiguous repeated UID rows, especially shared control pages, are
  left blank and listed as generator warnings.

Generated line data:

- UID and link from `[files]`.
- Address range and display name parsed from by-memory filename.
- `RECONSTRUCTABLE` from `[reconstructable]`.
- `emits_code:true/false` from nonblank reconstruction code hash/state.
- completion/confidence percent.
- confidence label derived from confidence:
  - `very-strong` for `>= 90`
  - `strong` for `>= 80`
  - `medium` for `>= 60`
  - `weak` otherwise
- source file last-write timestamp.
- `Item Summary` text.

Sorting:

- By numeric memory start address, then numeric end address, then path.
- Rows without parseable memory ranges go after address rows and are listed in
  the error section.
- Nesting changes indentation only; it never changes memory ordering.

## Efficient Generated Writes And Threading

Keep the queue worker single-writer model for config and by-* metadata. Add
parallelism only after all config/data decisions are made:

- Build generated file contents serially from the loaded config and current docs.
- Create one generated-write task per unique output path.
- Reject duplicate tasks for the same output path as a validator action instead
  of allowing concurrent writes to one file.
- Use `ThreadPoolExecutor` for independent generated outputs such as C++ files,
  `-ag-*` autogen coverage files, `-ag-research-tracker.md`, and the new
  by-memory coverage report.
- Use atomic replace for every generated file.
- Protect shared generated-backup root creation with a lock.
- Preserve existing conflict behavior: nonempty generated destinations without
  validator sentinel are not overwritten.

This addresses the draft's worker-per-file requirement without making
`validator.ini` updates concurrent.

## Integration Points

- `load_config`: add research sections.
- `validator.py`: normalize positional report commands before queueing and update
  queue mode detection behavior through normalized argv.
- `validator_background.py` parser: add modes and command arguments.
- Normal scan flow:
  - After full/documented/file/rescore/autogen generated updates, also refresh
    research tracker.
  - File scans that create a UID refresh the tracker on `--apply`.
  - By-memory file scans refresh by-memory auto coverage unless
    `--reference-only`.
- Report command flow:
  - Mutate report files and central directories only under the validator lock.
  - Update config, regenerate tracker, then write `validator.ini` atomically.
- Migration flow:
  - Dry run prints planned moves and registration issues.
  - Apply moves files, updates headers when safe, updates registry, writes tracker,
    and writes `validator.ini`.

## Part 2: Command IDs, Deferred Generated Refresh, And Performance

This second update builds on the executed-research and by-memory auto-coverage
work. It changes validator command reporting and scheduling so normal
file/directory validation returns after the directly requested validation work is
complete, while expensive generated C++ and `auto-generated/-ag-*` report
refreshes can continue as lower-priority background work.

### Part 2 Goals

- Every validator invocation returns a durable command reference id and timestamp.
- Generated reports record the command id and timestamp that last refreshed them.
- Normal `file`, `full`, and `documented` scans return after UID/header,
  reference, registry, score/stat, and requested file/directory work finishes.
- Generated C++ under `auto-generated/NexusTK/` and generated `-ag-*` reports are
  scheduled as lower-priority internal jobs unless the user explicitly requests
  foreground generated refresh.
- Agents can compare their returned command id/timestamp with the metadata in an
  auto-generated report to decide whether that report has caught up.
- File-mode generated refresh should be incremental whenever the affected UID and
  affected generated roots/reports can be determined safely.
- Full/documented scans should gain parallel read/parse phases without making
  `validator.ini` mutation or same-file writes concurrent.
- Persistent metadata caches should reduce repeat parse/read cost across queued
  commands while remaining invalidation-safe.
- Timestamp-only report updates from `Generated: now` must stop causing false
  update churn.
- Documentation and project skills must eventually describe the new command-id,
  deferred-refresh, and report-freshness workflow, but only after code has run
  successfully in non-dry-run mode and the user approves agent/supervisor
  instruction updates.

### Part 2 Non-Goals And Compatibility

- Do not remove the existing queue worker single-writer guarantee for
  `validator.ini`.
- Do not allow two worker threads or jobs to write the same output file at the
  same time.
- Do not require agents to manually edit `validator.ini` or generated reports to
  repair freshness metadata.
- Do not make report freshness ambiguous: every generated report must expose the
  exact command id and timestamp that produced the visible content.
- Do not trust persistent caches without matching stat/hash/schema validation.
- Do not use cache data to skip required writes unless serialized target content
  is proven identical.
- Preserve an escape hatch for callers that need old synchronous behavior, such
  as a `--wait-generated` or equivalent flag.

### Command Reference IDs

Add a persistent command id state file owned by the validator frontend:

```text
tools/validator_command_state.json
```

State shape:

```json
{
  "schema": 1,
  "last_command_id": 10043,
  "last_command_timestamp": "2026-06-24T00:54:32-04:00"
}
```

Rules:

- The id is a monotonically increasing integer allocated under the same queue
  lock used for enqueueing jobs. This makes allocation safe across concurrent
  callers.
- The timestamp is created at command submission time in local timezone ISO-8601
  with offset.
- The returned display format is zero-padded for lexical comparison, for example
  `000000010043`, while the persisted field remains numeric.
- Every user-visible validator command path allocates and prints a command id,
  including queued commands, `--background-direct`, `--queue-status`, and
  `--start-worker`. Queue-administration commands do not schedule generated
  refreshes, but they still provide an audit id so users can reference the exact
  validator call they made.
- The frontend prints the command id/timestamp preamble before queueing,
  dispatching `--background-direct`, or handling queue-administration commands.
  This guarantees `--help`, timeout, and worker-failure paths still expose the
  submitted command reference.
- Queue jobs include `command_id`, `command_id_display`, and
  `command_timestamp`. The worker consumes that context for generated metadata
  and refresh scheduling but must not print a second command preamble for queued
  jobs.
- If the frontend times out waiting for a queued result, the timeout stderr must
  include the queued command id/timestamp and job filename so the caller can
  still reference the submitted command and inspect queue status.
- `--background-direct` debug invocations allocate an id through the same state
  helper and pass it to the background worker as explicit command-context
  arguments.
- Internal deferred generated-refresh jobs carry the originating command id and
  timestamp rather than allocating a user-visible replacement id.
- Every user-facing command output starts with:

```text
command_id: 000000010043
command_timestamp: 2026-06-24T00:54:32-04:00
```

- If a foreground command schedules background generated work, it also prints:

```text
generated_refresh: deferred
generated_refresh_command_id: 000000010043
generated_refresh_timestamp: 2026-06-24T00:54:32-04:00
```

- If the generated work runs in the foreground, it prints:

```text
generated_refresh: completed
generated_refresh_command_id: 000000010043
generated_refresh_timestamp: 2026-06-24T00:54:32-04:00
```

### Generated Report Metadata Header

Every validator-owned Markdown report under `auto-generated/-ag-*.md` must have
a metadata header immediately after the existing autogen sentinel.

Required fields:

```text
<!-- validator-command-id: 000000010043 -->
<!-- validator-refreshed-at: 2026-06-24T00:54:32-04:00 -->
<!-- validator-refresh-source: deferred-generated-refresh -->
```

Rules:

- These fields apply to all generated Markdown reports, including:
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-function-coverage.md`
  - `auto-generated/-ag-global-coverage.md`
  - `auto-generated/-ag-item-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `auto-generated/-ag-research-tracker.md`
  - `auto-generated/-ag-coverage-report-by-memory.md`
- The metadata command id is the command id whose state was used for the refresh.
- If command `000000010044` refreshes a report before command `000000010043`
  finishes its deferred refresh, the report may show `000000010044`; agents with
  `000000010043` can treat that as fresh because it is newer.
- Generated C++ files under `auto-generated/NexusTK/` may keep their current C++
  sentinel format, but any new C++ freshness metadata must be comments and must
  not break compilation if those files are later copied into a build tree.
- The old visible `Generated: <current time>` line must not use wall-clock `now`
  on dry-run comparisons. Either replace it with the metadata header or render it
  from the command timestamp only when the report content is actually refreshed.
- Implement this through one shared Markdown report helper, for example
  `render_generated_markdown_header(context, refresh_source)`, and require every
  generated Markdown renderer to call it:
  `render_autogen_report`, `render_research_tracker`,
  `render_by_memory_auto_coverage`, and any future `auto-generated/-ag-*.md`
  report renderer. Do not hand-code metadata headers separately in each renderer.
- Generated report comparison must ignore old metadata/header-only timestamp
  churn when deciding whether the report body changed. If the existing file has
  no metadata because it predates Part 2, the first apply generated refresh may
  produce a metadata-only `generated_metadata_refresh`; later default dry runs
  must not keep reporting updates solely due to a new wall-clock time.

### Report Freshness Comparison

Agent workflow after a normal validator command:

1. Run a validator command and record the returned `command_id` and
   `command_timestamp`.
2. If the command says `generated_refresh: deferred`, do not assume
   `auto-generated/-ag-*` files are current yet.
3. Open the relevant generated report and read `validator-command-id`.
4. If report command id is equal to or greater than the command id returned to
   the agent, the report includes that command or a newer state.
5. If report command id is lower, the report is still behind or the deferred job
   failed; wait briefly, check queue status, or run explicit foreground autogen.

Timestamp comparison is secondary and only used as a human-readable audit trail.
Command id is the primary ordering key.

### Deferred Generated Refresh Scheduling

Add an internal generated-refresh mode that is queued by normal mutating commands
after foreground work and `validator.ini` writes complete.

Internal job payload fields:

```json
{
  "kind": "generated-refresh",
  "argv": [],
  "internal_mode": "generated-refresh",
  "origin_command_id": 10043,
  "origin_command_id_display": "000000010043",
  "origin_command_timestamp": "2026-06-24T00:54:32-04:00",
  "affected_uids": ["000270"],
  "affected_paths": ["by-memory/0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md"],
  "refresh_scope": "incremental-or-full-fallback"
}
```

Rules:

- The original foreground job writes its result before the internal refresh job
  runs, so the caller returns promptly.
- Internal jobs are not normal `argv` validator jobs. The queue worker must
  branch on `job["kind"] == "generated-refresh"` and call a generated-refresh
  runner directly. Normal `run_queued_validator_job()` remains for user commands.
- Internal jobs do not have a user result path. They write compact JSON results
  under `tools/validator_queue/generated_refresh_results/` and must never cause
  a waiting foreground caller to block.
- Enqueueing an internal generated-refresh job happens after the foreground
  command has completed all direct file/config/report lifecycle writes and after
  any required foreground `validator.ini` write has succeeded. If foreground
  work fails, no internal generated-refresh job is queued.
- The internal refresh job is processed by the same queue worker and same
  validator lock discipline, so config and generated writes remain serialized
  against other validator mutations.
- Multiple pending generated-refresh jobs may be coalesced. A newer command id
  supersedes older refresh jobs because a newer generated report satisfies older
  freshness checks.
- Coalescing must preserve the highest command id/timestamp and union affected
  UID/path sets when incremental refresh is still possible.
- If coalescing makes incremental scope unsafe, fall back to full generated
  refresh under the newest command id.
- Explicit `--mode autogen --apply` and any new `--wait-generated` flag run the
  generated refresh foreground and return `generated_refresh: completed`.
- `--wait-generated` is a foreground command flag accepted by the background
  parser and transparently forwarded by the frontend. For `full`, `documented`,
  `file`, report lifecycle, `rescore`, and `autogen`, it disables deferred
  scheduling and runs the needed generated Markdown/C++ refresh before returning.
  For dry-run it reports what would run but still performs no writes.
- `--no-generated-refresh` is an optional escape hatch for diagnostics. It may
  suppress generated refresh scheduling, but output must say
  `generated_refresh: skipped` and explain that generated reports may lag the
  command id.
- Read-only dry runs should normally not enqueue deferred generated writes. They
  may still report `generated_refresh: would-defer` when useful.

### Foreground Versus Deferred Work

Foreground work for `--mode file`:

- Resolve and scan the supplied file.
- Repair/add UID and metadata headers when `--apply`.
- Update path mapping, completion/confidence, projected path state, canonical
  owner, autogen metadata registry entries for the touched file, references, TMP
  references, and incremental stats rows as existing behavior requires.
- Write changed by-* file and `validator.ini` atomically.
- Return command id, timestamp, action summary, and non-OK action details.
- Schedule generated refresh unless `--uid-only`, `--reference-only`, dry-run, or
  caller explicitly disables generated refresh.

Foreground work for directory-scoped scans:

- Resolve the requested directory to direct by-* Markdown files only.
- Run the same per-file UID/header/reference/config/stat work that file mode
  would run for each file in deterministic sorted order.
- Return after the requested directory's registry/documentation work is durable.
- Schedule one lower-priority generated refresh for the affected UID/path set,
  rather than refreshing generated C++ or `-ag-*` reports before returning.

Foreground work for `--mode full` and `--mode documented`:

- Scan all target by-* files.
- Apply UID/header/reference/config/stat/missing-entry cleanup decisions.
- Write changed by-* files and `validator.ini` atomically.
- Return after those registry/documentation updates.
- Schedule generated refresh unless disabled or dry-run.

Foreground work for report lifecycle commands:

- Move/edit/register/invalidate/reassign/confirm report files.
- Update report registry sections and `validator.ini`.
- Return after lifecycle state is durable.
- Schedule research tracker refresh as deferred generated work unless the caller
  requests foreground generated refresh.

### Incremental File-Mode Autogen

Incremental generated refresh is allowed only when all affected outputs can be
derived safely. Otherwise use full generated refresh.

Affected UID sources:

- The directly scanned file UID.
- Any UID whose path mapping changed.
- Any UID whose `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`,
  `EMITTER_POSITION_OPTIONAL`, or reconstruction code hash changed.
- Any UID whose completion/confidence changed.
- Any UID added, removed, or restored by the command.
- For report lifecycle commands, the target UID(s) covered by changed reports.
- Capture old affected metadata before mutating `config` or use a validated
  cache snapshot. The incremental planner must compare old and new values for
  path, score, projected path, owner, reconstructable state, emitters, emitter
  position, reconstruction code hash, and by-memory summary/nested metadata.
  Without a valid old snapshot, the planner must mark the scope unsafe and fall
  back to full generated refresh.

Affected generated C++ roots:

- Old and new emitter roots for every affected UID.
- If an affected UID is itself a by-file source root, include its old and new
  generated C++ destination.
- If an affected UID was a parent/emitter/root in the old or new autogen graph,
  include every root reachable through old and new graph routes.
- If old graph data is missing from cache or config, fall back to full refresh.

Affected `-ag-*` reports:

- The report for the affected UID's direct by-folder.
- `-ag-file-coverage.md` if a by-file root or projected path changed.
- `-ag-memory-coverage.md` if any by-memory autogen metadata changed.
- `-ag-research-tracker.md` if report coverage, score, reconstructable state, or
  central executed report state changed.
- `-ag-coverage-report-by-memory.md` if any by-memory file metadata, score,
  mtime, summary, nested value, existence, or path changed.
- Full report set when a change can alter aggregate totals in a way the
  incremental renderer cannot prove locally.

Incremental report rendering rules:

- If reports are simple full-table Markdown and no row-level persistence exists,
  rerender a whole affected report file while avoiding unrelated reports and
  unrelated generated C++ roots.
- Do not attempt partial in-place Markdown row editing until row identity,
  sorting, and section-total updates are fully modeled.
- If totals, ordering, or error sections depend on global state that is not
  available from cache, rerender that whole report.
- A first implementation may rerender whole affected reports and whole affected
  generated C++ roots. It must not attempt row-level Markdown patching. If the
  affected-report set cannot be proven complete, use full generated refresh.

### Persistent Metadata Cache

Add a validator-owned cache directory:

```text
tools/validator_cache/
```

Primary cache file:

```text
tools/validator_cache/metadata_cache.json
```

Cache schema:

```json
{
  "schema": 1,
  "validator_version": "metadata-cache-v1",
  "root": "C:/FastStorage/NTK_Sources/source-3/project-documentation",
  "files": {
    "by-memory/example.md": {
      "mtime_ns": 1782260000000000000,
      "size": 12345,
      "sha256": "<optional-or-required-hash>",
      "uid": "000123",
      "completion": 88,
      "confidence": 91,
      "reconstructable": "true",
      "canonical_owner": "0000CB",
      "emitter_uids": ["0000NB"],
      "emitter_positions": [10],
      "code_hash": "<hash>",
      "code_mode": "coded",
      "uid_refs": ["0000CB", "0000NB"],
      "tmp_refs": [],
      "item_summary": "single line summary",
      "nested": 0,
      "errors": []
    }
  }
}
```

Invalidation rules:

- A cache entry is valid only when schema, root, relative path, `mtime_ns`, and
  size match the current filesystem.
- Store `sha256` for files already hashed by existing logic, report files, and
  any file whose content is needed for generated output correctness.
- If mtime/size match but a command needs high-confidence generated C++ or
  report body data, verify sha256 when present.
- If any validation field is missing for the requested operation, parse the file
  normally and update the cache.
- Any `write_text_atomic` call updates or invalidates the matching cache entry.
- Missing files remove their cache entry.
- Cache writes are atomic and happen after command success, not before.
- Cache corruption is non-fatal: report a cache warning, ignore the cache, and
  rebuild entries from source files.
- To guard against a file changing between parallel observation and serial
  decision, store an observation stat tuple. Immediately before applying a
  planned edit for a source by-* file, re-stat the file. If mtime or size differs
  from the observation, discard that observation and rerun that file through the
  existing serial scan path before writing.

Expected cache use:

- Full/documented scans parallel-load stat/hash/read/parse observations.
- File scans reuse cached autogen/report metadata for unrelated files.
- Autogen generation uses cached parsed metadata where valid instead of reading
  every by-* file again.
- By-memory auto coverage uses cached summary/nested/range metadata where valid.
- Research tracker uses cached target UID/author data for unchanged reports.

### Stable Generated Report Timestamps

Replace timestamp-on-render behavior with command-context refresh metadata.

Rules:

- Report content should not change only because a dry-run command was executed.
- In dry-run, if computed report body excluding metadata is identical to the
  current file body, report `*_noop`, not `*_update`.
- In apply/deferred refresh, write new command metadata only when either:
  - the report body changed, or
  - the caller explicitly requested a freshness-only refresh.
- If a freshness-only refresh is supported, it must be an explicit action such
  as `generated_metadata_refresh`, not mixed with content update actions.
- Default behavior should avoid modifying generated files solely to replace a
  timestamp.

### Content-Aware Atomic Writes

Extend atomic write helpers so apply mode avoids no-op file replacement:

- `write_text_atomic(path, text)` should compare existing text first when the
  path exists and is UTF-8 text.
- If content is identical, skip temp-file creation and `os.replace`.
- If content differs, keep current atomic replacement behavior.
- `write_config_atomic(config, ini)` should serialize to memory first, compare
  with existing file text, and skip replacement when identical.
- Generated write actions already compare old/new content; this optimization
  protects config, stats, report lifecycle files, and any future direct writes.
- Skipped no-op writes must still update in-process text cache when needed.

### Parallel Full/Documented Scan Refactor

Do not parallelize the existing `scan_file()` function directly because it
mutates shared config and UID allocation state. Refactor into phases:

1. Parallel observation phase:
   - Read/stat/hash files.
   - Parse existing UID, score lines, projected path, reconstruction metadata,
     UID refs, TMP refs, by-memory summary/nested, and report headers.
   - Produce immutable `FileObservation` objects.
   - Do not mutate config or write files.

2. Serial decision phase:
   - Preserve sorted target order for UID allocation and deterministic output.
   - Reconcile missing/damaged UIDs, path mappings, duplicate UID conflicts,
     completion/confidence updates, projected paths, canonical owners, autogen
     metadata, references, TMP refs, and missing UID cleanup.
   - Produce per-file `PlannedFileEdit` objects and config mutations.

3. Parallel write phase:
   - Execute independent file writes with one task per unique path.
   - Reject duplicate write tasks for one file as a validator action.
   - Keep `validator.ini` write serial and last.
   - Use content-aware atomic write helpers.

4. Deferred generated refresh phase:
   - Schedule internal generated-refresh job using the affected UID/path set.

Correctness requirements:

- UID allocation order must be exactly the same as the current serial sorted
  scan.
- Duplicate UID/path conflict behavior must be unchanged.
- Reference update behavior must be unchanged.
- `--remove-missing` behavior must remain explicit and must remove stale autogen
  registry state only under `--apply`.
- Any uncertainty falls back to the old serial scan path until covered by tests.
- Put the parallel path behind an internal capability guard. If any observation
  lacks fields needed to reproduce current `scan_file()` behavior, use the old
  serial path for that command and emit a `parallel_scan_fallback` action. The
  first implementation may keep mutation decisions serial and conservative while
  still parallelizing read/parse observations.

### Queue And Background Worker Changes

- Add a hidden/internal mode for generated refresh jobs.
- Add generated-refresh dedup/coalescing rules separate from user command dedup.
- Keep worker result files for user commands, but internal generated-refresh jobs
  may write compact status logs under:

```text
tools/validator_queue/generated_refresh_results/
```

- Queue status should show pending/running generated refresh jobs separately if
  practical.
- If a deferred generated refresh fails, preserve a result record containing the
  origin command id, timestamp, exception/action summary, and recommended
  foreground recovery command:

```powershell
python .\tools\validator.py --mode autogen --apply --wait-generated
```
- Coalescing internal refresh jobs must never merge a read-only dry-run
  `would-defer` marker into an applying generated refresh. Only apply-capable
  internal refresh jobs are coalesced.
- Queue status should show at least:
  - queued user jobs,
  - processing user jobs,
  - queued generated-refresh jobs,
  - processing generated-refresh jobs,
  - recent generated-refresh failure result count.

### Implementation Order

Implement Part 2 in this order so every stage has a narrow verification point:

1. Command context:
   - frontend state file and allocation under queue lock;
   - command id/timestamp printed by queued, direct, status, and worker-start
     commands;
   - queued job command context passed into the background worker without
     reallocating.
2. Stable generated Markdown metadata:
   - shared header helper;
   - renderer signatures accept command context and refresh source;
   - old `Generated: now` churn removed from all `auto-generated/-ag-*.md`
     reports;
   - content-aware generated Markdown comparison distinguishes body changes from
     metadata-only refreshes.
3. Content-aware writes:
   - `write_text_atomic` and `write_config_atomic` skip identical writes;
   - generated write no-op behavior remains unchanged except for metadata-only
     refresh actions.
4. Deferred generated refresh:
   - internal queue job kind;
   - foreground command schedules internal refresh after successful direct work;
   - `--wait-generated` runs the same refresh foreground;
   - queue status and failure-result files expose generated-refresh state.
5. Cache:
   - cache read/write/invalidation helpers;
   - use valid cache entries for by-memory auto coverage and autogen report
     metadata reads first;
   - corrupt/stale cache falls back to source reads.
6. Incremental generated refresh:
   - compute affected UID/path sets from command actions and old/new metadata;
   - rerender whole affected reports/roots only when safe;
   - full fallback on uncertainty.
7. Parallel observation:
   - parallel read/stat/parse observations for full/documented scans;
   - serial decision and config mutation;
   - unique-path write batch with duplicate write rejection;
   - serial fallback when behavior cannot be proven equivalent.

### Documentation And Skill Update Requirements

After the code is implemented, dry-run checks pass, and a non-dry-run validation
has confirmed behavior:

- Treat these Part 2 documentation/skill updates as additive to the earlier
  executed-research, by-memory auto-coverage, and validator-owned generated
  report documentation updates already planned in Part 1.
- Update `tools/validator_README.txt` with command id/timestamp output format,
  deferred generated refresh behavior, report metadata header fields, freshness
  comparison workflow, foreground/wait flag, generated-refresh recovery command,
  and cache location/troubleshooting.
- Update `by-structure.md` with high-level validator workflow changes.
- Update project skills and agent/supervisor instructions only after user
  approval, including:
  - `ntk-b-agent-workflow` skill,
  - supervisor instructions that currently imply manual coverage/report updates,
  - B-agent report requirements for target/author headers,
  - guidance that agents compare command id against generated report metadata
    before treating auto-generated coverage/tracker files as current.
- Remove or revise instructions that tell agents to manually update by-memory
  coverage reports when validator-owned auto coverage should be used.
- Keep existing instruction that `tools/validator.ini` is tool-owned and should
  not be manually edited.

## Edge Cases To Code Against

- Supplied report filename attempts path traversal.
- Supplied agent id case differs.
- Supplied target UID case differs.
- Report file exists in wrong agent folder.
- Central destination already exists.
- Returning invalidated report would collide with active research file.
- Header target UID exists but target path has been removed.
- Header target conflicts with override target.
- Body contains multiple different UID candidates.
- Filename prefix is a UID but body/header point elsewhere.
- `unknown` reassignment source.
- Missing central executed root.
- Empty report file.
- UTF-8 BOM in report file.
- Report content changes after execution.
- Same filename executed multiple times by same agent.
- Same report target covered by multiple agents or multiple reports.
- New UID allocated during validator file scan.
- `--uid-only` should not write reconstruction autogen, but tracker should still
  reflect a newly registered UID after apply.
- `--reference-only` should not inject by-memory coverage metadata.
- Dry-run must not move files, write headers, write config, or write generated
  files.
- Command id state file missing, corrupt, or contains a non-integer id.
- Two validators invoked concurrently while command id state is being updated.
- `--background-direct` invoked while the queue worker exists.
- Deferred generated refresh coalesced behind a newer command id.
- Deferred generated refresh fails after the foreground command already
  returned.
- User compares report metadata while generated refresh is still pending.
- A generated report is missing metadata because it predates Part 2.
- A report body is unchanged but metadata timestamp would differ.
- A file mtime/size matches cache but sha256 differs.
- Cache entry points to a path that has been renamed or removed.
- Cache schema version is stale.
- Parallel observation reads a file that changes before the serial decision
  phase.
- Parallel write task list accidentally contains duplicate target paths.
- Incremental autogen cannot determine old and new emitter roots.
- By-file projected path changes generated C++ destination.
- `--uid-only` and `--reference-only` must not accidentally schedule generated
  refreshes unless explicitly requested.
- Explicit foreground autogen must still produce completed generated metadata.
- Queue status must not be confused by internal generated-refresh jobs.

## Validation Plan

1. Syntax check:

```powershell
python -m py_compile .\tools\validator.py .\tools\validator_background.py
```

2. Command help:

```powershell
python .\tools\validator.py --background-direct --help
```

3. Dry-run migration:

```powershell
python .\tools\validator.py migrate-executed-reports --queue-timeout -1
```

4. Dry-run report rescan:

```powershell
python .\tools\validator.py execute-rescan-reports --queue-timeout -1
```

5. Dry-run by-memory file validation on a representative file:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md --queue-timeout -1
```

6. Apply migration:

```powershell
python .\tools\validator.py migrate-executed-reports --apply --queue-timeout -1
```

7. Apply rescan/hash check:

```powershell
python .\tools\validator.py execute-rescan-reports --apply --queue-timeout -1
```

8. Apply representative by-memory validation:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md --apply --queue-timeout -1
```

9. Inspect generated outputs:

```powershell
Get-Content .\auto-generated\-ag-research-tracker.md -TotalCount 80
Get-Content .\auto-generated\-ag-coverage-report-by-memory.md -TotalCount 80
```

10. Run a final non-dry full validator command if scoped checks pass:

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout -1
```

11. Update `tools/validator_README.txt` with tool command usage and generated
    file descriptions only after code behavior is verified.

12. Stop and ask the user before changing project skills, supervisor
    instructions, or agent goal files.

## Part 2 Validation Addendum

13. Command id allocation smoke test:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md --uid-only
```

Expected:

- Output includes `command_id` and `command_timestamp`.
- `tools/validator_command_state.json` records the same id and timestamp.
- No generated refresh is scheduled for `--uid-only`.

14. Deferred file-mode generated refresh test:

```powershell
python .\tools\validator.py --mode file --file by-memory\0x00631184-0x006313fc.WaitableWeatherReadOnlyData.md --apply --queue-timeout -1
```

Expected:

- Foreground output returns after the file/config work relevant to the scanned
  file completes.
- Output says generated refresh was deferred and includes the origin command id.
- Queue later processes the generated refresh.
- Affected `auto-generated/-ag-*` report metadata catches up to the command id
  or a newer id.

15. Foreground generated refresh test:

```powershell
python .\tools\validator.py --mode autogen --apply --queue-timeout -1
```

Expected:

- Command returns only after generated files and reports are refreshed.
- Every `auto-generated/-ag-*.md` report contains the metadata header.
- Re-running without content changes does not rewrite files just because a
  render timestamp changed.

16. Cache correctness test:

```powershell
python .\tools\validator.py --mode autogen --queue-timeout -1
python .\tools\validator.py --mode autogen --queue-timeout -1
```

Expected:

- Second run uses cached file metadata where mtimes/sizes/hashes are unchanged.
- Scanner output and generated report content match uncached behavior.
- Deleting or corrupting the cache falls back to a correct full metadata scan.

17. Incremental generated refresh test:

- Edit one by-memory page summary/score in a validator-owned test case.
- Run scoped file validation with `--apply`.
- Confirm only affected roots/reports are considered when the dependency set is
  known.
- Confirm the validator falls back to full generated refresh when the dependency
  set is uncertain.

18. Parallel full/documented scan test:

```powershell
python .\tools\validator.py --mode documented --remove-missing
python .\tools\validator.py --mode documented --remove-missing --apply --queue-timeout -1
```

Expected:

- Dry-run and apply actions match old serial behavior.
- No duplicate same-file writes are produced.
- `tools/validator.ini` is written once through the serial decision/write path.

19. Deferred failure recovery test:

- Force a generated-output conflict in a temporary validator-owned test path or
  an existing safe conflict fixture.
- Confirm foreground command reports the generated refresh as deferred, not
  completed.
- Confirm the generated refresh failure record includes origin command id,
  timestamp, affected paths, and a recovery command.

20. Documentation update gate:

- Update `tools/validator_README.txt` after Part 2 behavior is implemented and
  verified.
- Do not update agent/supervisor skills, agent goals, or workflow instructions
  until the user approves those separate documentation/skill changes.

## Plan Review Log

Review 1: issue found and fixed. The initial plan did not state whether report
lifecycle commands mutate by default or require `--apply`. The plan now keeps
the validator's existing dry-run-by-default convention and requires `--apply`
for supervisor-facing moves, invalidations, reassignments, and confirmations.

Review 2: no issues found. The reviewed plan covers command syntax, dry-run and
apply behavior, central storage layout, duplicate handling, registry rebuilds,
generated tracker/report ownership, by-memory coverage metadata injection,
threaded generated writes, validation, and the required stop before
skill/supervisor/agent instruction updates.

Review 3: issue found and fixed for Part 2. The first Part 2 outline did not
define how agents compare deferred generated state against their foreground
command. The plan now defines report metadata headers, command-id ordering, and
the exact freshness comparison workflow.

Review 4: issue found and fixed for Part 2. The first Part 2 outline risked
parallelizing `scan_file()` directly even though it mutates shared config and
reference state. The plan now requires a parallel observation phase, serial
decision phase, and parallel unique-path write phase, with serial
`validator.ini` writes.

Review 5: no issues found. The reviewed Part 2 plan covers command id
allocation, output format, deferred generated refresh, report metadata,
incremental file-mode autogen with safe fallback, persistent cache invalidation,
stable generated timestamps, content-aware apply writes, parallel full-scan
refactoring, queue failure handling, validation, and deferred
documentation/skill updates after user approval.

Review 6: no issues found. The second clean review confirmed that the Part 2
plan preserves validator-owned state, avoids same-file concurrent writes, keeps
manual `validator.ini` edits out of the workflow, and provides explicit fallback
paths for cache misses, incremental-scope uncertainty, and generated-refresh
failures.

Review 7: issue found and fixed for Part 2. The queue timeout path could return
before the worker produced stdout, which would have hidden the submitted command
id. The plan now requires timeout stderr to include command id, timestamp, and
job filename.

Review 8: no issues found. Clean review 1 after the reset confirmed command-id
allocation/output semantics cover queued commands, background-direct, queue
status, start-worker, timeout, foreground generated refresh, and deferred
generated refresh.

Review 9: no issues found. Clean review 2 after the reset confirmed all
validator-owned Markdown generated reports use shared command metadata, avoid
`Generated: now` churn, distinguish metadata-only refresh from body updates, and
use content-aware writes.

Review 10: no issues found. Clean review 3 after the reset confirmed
incremental refresh has safe old/new metadata requirements and full fallback,
persistent cache invalidation is guarded by schema/root/stat/hash checks, and
parallel full/documented scans keep mutation decisions serial with fallback on
uncertainty.

Review 11: issue found and fixed during implementation planning. Commands such
as `--help`, worker failure, and queue timeout are safest when the frontend
prints the command preamble before queueing or dispatching. The plan now makes
the frontend the single command-preamble printer and forbids a second worker
preamble for queued jobs.

Review 12: no issues found. Clean review 1 after the second reset confirmed
the frontend-preamble model covers queued commands, `--background-direct`,
`--queue-status`, `--start-worker`, timeout, and worker failure while still
passing command context to the worker for generated metadata.

Review 13: no issues found. Clean review 2 after the second reset confirmed
the shared generated Markdown header, no timestamp-only churn, and content-aware
write rules still cover all current `auto-generated/-ag-*.md` renderers.

Review 14: no issues found. Clean review 3 after the second reset confirmed
incremental refresh, cache invalidation, and parallel observation fallback
requirements remain complete after the frontend-preamble correction.
