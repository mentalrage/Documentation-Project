# Validator Additional Report Targets Extension

## Purpose

Extend executed B-agent report coverage so one report can declare one primary
target and zero or more additional targets that the same report substantively
covers.

The extension must preserve the existing meaning and lifecycle ownership of
`TARGET-REPORT-UID`. The primary UID remains the report's canonical target,
archive/lifecycle owner, report-count location, and command target. Additional
UIDs are separate coverage relationships only.

This is an implementation guide. It also bundles correctness and performance
repairs found while auditing the current report lifecycle and tracker code, so
the extension is not built on known-invalid behavior. It does not authorize
manual edits to `tools/validator.ini`, generated files, executed-report history
footers, or executed-report lifecycle metadata.

## Required Header Contract

Canonical report headers:

```md
** TARGET-REPORT-UID:0002Q4 **
** TARGET-REPORT-ADDITIONAL-UIDS:0002Q5,0002Q6,0002Q7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
```

`TARGET-REPORT-ADDITIONAL-UIDS` is optional.

- Missing header means the report has no additional targets. This is valid and
  is the required backward-compatible behavior.
- Existing reports without the header remain valid direct-target-only reports.
- No migration is required merely because the feature is introduced.
- A present header must contain at least one UID.
- Values are comma-separated six-character UIDs.
- Parsing is case-insensitive, but validator-written output is uppercase.
- Spaces around commas may be accepted, but validator-written output should be
  canonicalized without spaces and sorted for deterministic output.
- Empty tokens, malformed UIDs, duplicate UIDs, multiple additional-UID header
  lines, and an additional UID equal to the resolved primary UID are errors.
- Every additional UID must exist in `config["files"]`, and its registered
  by-* path must exist.
- The validator must not infer additional UIDs from filenames, report prose,
  UID mentions, links, implementation checklists, support pages, references,
  source ownership, emitters, or shared generated files.
- Existing `execute_report B### report.md [TARGETUID]` command syntax remains
  unchanged. The optional header is the sole source for additional targets;
  do not add a second CLI source that can disagree with the report artifact.

Examples:

```md
<!-- Valid: no additional coverage -->
** TARGET-REPORT-UID:0002Q4 **

<!-- Valid -->
** TARGET-REPORT-ADDITIONAL-UIDS:0002Q5,0002Q6 **

<!-- Invalid: present but empty -->
** TARGET-REPORT-ADDITIONAL-UIDS: **

<!-- Invalid: duplicate -->
** TARGET-REPORT-ADDITIONAL-UIDS:0002Q5,0002Q5 **

<!-- Invalid when 0002Q4 is the primary target -->
** TARGET-REPORT-ADDITIONAL-UIDS:0002Q4,0002Q5 **
```

## Coverage Semantics

Coverage is evaluated per target UID across all valid, registered, counting
reports. Direct and additional coverage must remain distinguishable.

The four states are mutually exclusive:

| State | Qualifying direct reports | Qualifying additional reports |
| --- | ---: | ---: |
| Not covered | 0 | 0 |
| Direct only | 1 or more | 0 |
| Additional only | 0 | 1 or more |
| Direct and additional | 1 or more | 1 or more |

Important interpretation:

- A report directly covers its `TARGET-REPORT-UID`.
- The same report additionally covers each UID in
  `TARGET-REPORT-ADDITIONAL-UIDS`.
- The primary item does not become `Direct and additional` merely because its
  report lists other UIDs. It becomes `Direct and additional` only if another
  valid report additionally covers that primary UID.
- Effective coverage is the union of direct and additional coverage.
- A report path must be counted at most once for a specific target.
- `Only_Count_B_Reports_For_Coverage = true` applies identically to direct and
  additional coverage. A/C reports may remain visible as report metadata but
  cannot change a target's coverage state while that setting is true.
- A report carrying `REPORT-VALIDATION-STATUS: needs-revalidation`, a malformed
  header, registry drift, a missing target, a size/hash mismatch, an invalid
  history footer, or another existing non-counting condition contributes no
  direct or additional coverage.
- Any report-level invalidation or revalidation lock removes all coverage from
  that report. Do not keep unaffected additional edges counting while the
  report artifact itself is untrusted.

## Quality Requirement For Additional Targets

The new header is a machine-readable claim, not evidence that the claim is
true. Additional coverage must not provide a shortcut around B-report quality
or supervisor verification.

When the header is present, the report must contain target-specific work for
every additional UID:

- The `Target` or target inventory content identifies every additional UID and
  path.
- `Evidence Checked`, positive evidence, negative evidence, inference analysis,
  score/metadata reasoning, source/C++ disposition, and open-question closure
  cover each additional target to the depth required by its claims.
- `Claim And Incorporation Ledger` contains rows mapping each additional
  target's accepted claims to exact destination docs/sections.
- `Recommended Target Doc Changes` and `Recommended Support Doc Changes`
  identify all additional-target edits or give concrete target-specific
  already-present/not-applicable dispositions.
- `Implementation Tracking Checklist` lists and verifies every additional
  target's accepted changes and scoped validators.
- Supervisor Gate 1 audits the report text for all declared UIDs.
- Supervisor Gate 2 verifies implementation claim by claim for all declared
  UIDs before `execute_report`.

If any declared additional target is unsupported, incomplete, stale, or not
implemented, the report must be repaired or the UID removed before execution.
The validator should validate structure and registry integrity; it must not
pretend to replace the supervisor's semantic Gate 1/Gate 2 review.

## Current Implementation Assumptions To Replace

The current implementation is single-target in these areas of
`tools/validator_background.py`:

- Constants and regexes near `REPORT_TARGET_HEADER_RE`.
- `ReportHeaderMetadata` stores one `target_uid`.
- `ResearchReportRecord` stores one `uid`.
- `ResearchTrackerEntry` stores one combined collection of direct reports and
  determines `covered` from direct `coverage_report_paths`.
- `parse_report_headers()` recognizes one primary target header.
- `report_file_metadata()` caches one primary target header.
- `upsert_report_headers()` rewrites only the existing report headers.
- `[research_report_uid]` maps each report path to one primary UID.
- `[research_reports]` maps each primary UID to directly targeted reports.
- `research_report_records_by_uid()` groups reports only by their primary UID.
- `research_tracker_entries()` derives coverage only from that direct group.
- `mark_reports_for_uid_needs_revalidation()` finds only directly targeted
  reports.

The audit also found existing defects that must be repaired in the same update:

- malformed `TARGET-REPORT-UID` headers are not diagnosed because there is no
  permissive primary-target `ANY_RE`;
- normal `execute_report` can ignore parsed header errors, remove a live
  `needs-revalidation` lock, and invent legacy `CHATGPT | 5.5 | xHigh`
  provenance when specs are missing;
- `execute-confirm-change` updates trusted size/hash metadata before proving the
  changed artifact still has valid identity and lifecycle metadata;
- `executed-reassign` can move an unregistered report even when no target UID
  can be resolved;
- missing size/hash registry values can pass counting checks because only
  present values are compared;
- `[research_reports]` consistency is checked reverse-to-forward but not
  forward-to-reverse; and
- `Report Count Changes` uses an ever-seen UID set instead of reconstructing
  active physical report state through add/remove events, so
  remove-then-readd sequences can be classified incorrectly.

The extension must add a parallel additional-target relationship without
changing primary-target behavior.

## Read-Only Audit Findings

A read-only audit on 2026-07-21 found 2,165 registered central reports. The
current registry had no missing report-agent values, malformed/missing size or
SHA-256 values, missing registered files, or direct-index disagreements. The
integrity checks in this guide are preventive hardening and should therefore
leave current valid reports unchanged.

The same audit found three live central reports with a canonical primary header
plus a second malformed primary-header-shaped line that the old strict parser
ignored:

```text
executed-b-agent-research/B001/0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md
executed-b-agent-research/B003/0001E3-CScrollBarBackPaneDestructor-source-quality.md
executed-b-agent-research/B005/0000MF-ParcelPane-empty-emitter-family-source-quality.md
```

The extra lines use the shape `**TARGET-REPORT-UID:** UID`, not the canonical
`** TARGET-REPORT-UID:UID **`. The reports were counted before this update
because the old parser accepted the canonical line and ignored the malformed
lookalike. The hardened parser reports one precise malformed-header error per
file and excludes all three from counting, reducing the initial valid-record
set from 2,165 to 2,162 until repaired. Do not auto-rewrite these executed
artifacts. Repair them only through the normal revalidation/invalidation,
exact-artifact review, and re-execution lifecycle.

A comparison of current and authoritative-state trend algorithms also produced
three live differences in `by-memory`: the current last-6-hour, last-12-hour,
and last-24-hour rows classified 1, 2, and 2 additions respectively as `Added
To Already Covered`; reverse replay from the current registry classified those
as additions to previously unreported targets. This confirms the event-state
repair is behavioral correctness work, not a speculative optimization. The
exact rolling-window counts will naturally change after this audit timestamp.

## Implementation File Map

| File | Required change |
| --- | --- |
| `source-3/project-documentation/tools/validator_background.py` | Header grammar, dataclasses, cache serialization, registry state, diagnostics, lifecycle handling, UID revalidation lookup, tracker aggregation/rendering, history payloads, and the bundled lifecycle/trend correctness fixes. |
| `source-3/project-documentation/tools/validator.py` | No protocol redesign expected; verify foreground/background argument forwarding, concise action output, command IDs, and `--wait-generated` behavior remain unchanged. |
| `source-3/project-documentation/tools/validator.ini` | No manual edit. The validator creates and maintains one new canonical per-report section through normal config initialization and atomic writes. |
| `source-3/project-documentation/auto-generated/-ag-research-tracker.md` | Generated output only; never edit directly. It receives the new summary columns, exclusive buckets, and direct/additional row data. |
| `.codex/skills/ntk-b-agent-workflow/SKILL.md` | Optional-header contract and complete-target quality/verification rules. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md` | Optional header plus conditional per-additional-target report/checklist fields. |
| `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md` | Agent research and callback requirements for every declared target. |
| `.codex/skills/ntk-b-agent-workflow/references/supervisor-b-report-validation-preflight.md` | Gate 1/Gate 2 checks across the complete declared target set. |
| `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md` | No-loss incorporation and rejection rules for additional targets. |
| `source-3/project-documentation/tools/leaser/Agents/Supervisor.md` | Supervisor audit, callback, and execution requirements. |
| `.codex/AGENTS.md` | Concise project-wide provenance/coverage rule and routing to detailed guidance. |
| `source-3/project-documentation/tools/validator_README.txt` | User-facing syntax, lifecycle, tracker output, errors, and backward compatibility. |

No changes should be required in `memory_ranges.py` or `unresolved.py`; add
smoke checks to confirm their command behavior and output remain unaffected.

## Constants And Header Parsing

Add constants near the existing report-header definitions:

```python
RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION = "research_report_additional_uids"

REPORT_TARGET_HEADER_ANY_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-UID\s*:",
    re.IGNORECASE,
)

REPORT_ADDITIONAL_UIDS_HEADER_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-ADDITIONAL-UIDS\s*:\s*(?P<uids>.+?)\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_ADDITIONAL_UIDS_HEADER_ANY_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-ADDITIONAL-UIDS\s*:",
    re.IGNORECASE,
)
```

Both permissive `ANY_RE` patterns are required so malformed or empty instances
are reported rather than silently treated as missing headers. The primary
pattern is a repair for the current parser, not a change in valid syntax.

Add a focused parser helper, for example:

```python
def parse_report_additional_uids(value: str) -> tuple[tuple[str, ...], tuple[str, ...]]:
    ...
```

It should return normalized UIDs and parser errors, or raise a focused value
error that `parse_report_headers()` converts to report diagnostics. Required
checks:

1. Split only on commas.
2. Trim each token.
3. Reject an empty token, including leading/trailing commas and `,,`.
4. Uppercase each token.
5. Require `[A-Z0-9]{6}` exactly.
6. Reject duplicate normalized UIDs.
7. Sort the final tuple for deterministic registry/header output.
8. After all header lines are parsed, reject the primary UID if it appears in
   the additional tuple.

Extend `ReportHeaderMetadata`:

```python
additional_target_uids: tuple[str, ...] = ()
```

Missing optional header must leave this as `()`, with no error.

`parse_report_headers()` must:

- Report a malformed present primary-target header through
  `REPORT_TARGET_HEADER_ANY_RE` when the strict primary regex did not match.
- Parse at most one additional-target header within the existing header scan
  window.
- Report a duplicate header.
- Report malformed present headers.
- Perform the primary/additional overlap check after the primary UID is known.
- Include normalized additional UIDs in the returned metadata.
- Repair validation-status pairing while this parser is being changed: a
  `needs-revalidation` status requires a nonempty reason, and a revalidation
  reason without that status is malformed lifecycle metadata. Neither form may
  count or be silently stripped by normal execution.

Do not use the additional list as an input to `detect_report_target_uid()`.
Primary target detection and the optional positional UID argument to
`execute_report` remain primary-only inputs, but normal execution must no
longer use detection or rewriting to conceal a missing/malformed required
primary header. The resolved command target and valid report header must agree.

## Header Rendering And Preservation

Add:

```python
def make_report_additional_uids_header(uids: tuple[str, ...]) -> str:
    return f"** TARGET-REPORT-ADDITIONAL-UIDS:{','.join(uids)} **"
```

Extend `upsert_report_headers()` with an explicit additional UID parameter.
When the tuple is empty, omit the header. When nonempty, emit it immediately
after `TARGET-REPORT-UID` and before author metadata.

Header rewriting must not conceal invalid input:

- Treat malformed primary and additional target lines the same way: diagnose
  and preserve them until an explicit report repair, rather than stripping them
  as though they were valid headers.
- Strip and canonicalize only a syntactically valid additional-UID header.
- Do not remove a malformed line merely because it matches
  `REPORT_ADDITIONAL_UIDS_HEADER_ANY_RE`.
- Normal execution, reassignment, confirmation, and clearance commands must
  reject malformed header metadata before rewriting the report. The explicit
  legacy migration command may use its documented recovery rules but must
  record unresolved problems and keep the report non-counting.
- Revalidation marking may add status/reason/history metadata while preserving
  the malformed line so the original diagnostic remains inspectable.
- A repaired active report must have the malformed line fixed by the report
  author before it can be executed again.

The implementation must audit every current `upsert_report_headers()` caller.
In particular:

- `clear_report_revalidation_headers()` must preserve parsed additional UIDs.
- `upsert_report_revalidation_headers()` must preserve them.
- `run_execute_report_command()` must preserve and validate the active report's
  declared additional UIDs after resolving the primary UID.
- `run_executed_reassign_command()` must preserve them while changing author
  and path.
- `run_migrate_executed_reports_command()` must preserve a valid existing
  additional header, but must not invent one.
- `migrate_report_specs_in_file()` must preserve them while changing specs.
- Any future header-only update must take the complete parsed header state or
  explicitly document why a field is removed.

This audit is mandatory. Adding a default `()` argument and forgetting callers
would silently erase the new header during unrelated lifecycle commands.

## Metadata Cache

Extend `report_file_metadata()` to cache:

```text
report_header_additional_uids = JSON array/list of normalized UIDs
```

Requirements:

- Add the field to the required cached-report key set.
- Convert a cached list back to a tuple in `ReportHeaderMetadata`.
- Write the normalized list whenever report metadata is parsed.
- If the field is absent in an old cache entry, treat that cache entry as
  incomplete and reread only that report file.
- Do not require a global metadata-cache version bump solely for this field.
  The existing required-key check can lazily refresh report entries and avoids
  invalidating unrelated by-* metadata.
- If cached data has the wrong type, fall back to reparsing instead of treating
  it as an empty list.
- On a cache miss, read report bytes once, compute SHA-256 from those bytes,
  decode the same bytes once, and reuse one `stat()` result. The current path
  reads text, rereads the file in `file_sha256()`, and stats it again.
- Keep mtime/size cache hits; do not hash every report on every tracker render.
- Lifecycle-mutating commands must force fresh metadata for the exact report
  before preflight and invalidate/refresh that entry after writing. They must
  not rely on an earlier in-process cache result when deciding whether a write
  is safe.

This keeps disk overhead to a one-time read for legacy report cache entries and
one byte read for each genuine cache miss.

## Registry Schema

Keep the existing primary indexes unchanged:

```ini
[research_report_uid]
executed-b-agent-research/B001/report.md = 0002Q4

[research_reports]
0002Q4 = executed-b-agent-research/B001/report.md
```

Add one canonical additional-target section:

```ini
[research_report_additional_uids]
executed-b-agent-research/B001/report.md = 0002Q5;0002Q6;0002Q7
```

Rules:

- `[research_report_additional_uids]` is the per-report registered value used
  for header/registry integrity comparison.
- Build `additional_report_paths_by_uid` once in memory from validated
  per-report values for tracker aggregation, removal/split lookup, and
  revalidation handling. Do not persist a second reverse index.
- The report header remains the artifact declaration. Registry disagreement is
  an error; it must not be silently counted.
- Omit the per-report key when the list is empty.
- Add the section to `load_config()` section initialization.
- Do not place additional report paths in existing `[research_reports]`.
  Existing consistency checks require entries there to match the report's
  primary UID, and mixing the relationships would corrupt direct coverage.

Add helpers with normalized path/UID behavior:

```python
def parse_registered_additional_uids(value: str) -> tuple[str, ...]: ...
def format_registered_additional_uids(uids: tuple[str, ...]) -> str: ...
def additional_uids_for_report(config, report_path) -> tuple[str, ...]: ...
def build_additional_report_paths_by_uid(config) -> dict[str, tuple[str, ...]]: ...
def all_report_paths_for_uid(config, additional_paths_by_uid, uid) -> tuple[str, ...]: ...
```

Use a strict dedicated UID-list parser for registry values. Do not reuse
`parse_reference_sources()`: it returns a set and would silently erase duplicate
UIDs and other malformed-list evidence. The registry parser must enforce the
same normalization, empty-token, duplicate, and six-character rules as the
header parser. A semicolon-delimited config value is safe with the current
`ConfigParser(interpolation=None)` construction, but round-trip it in a focused
test rather than relying on that assumption.

`build_additional_report_paths_by_uid()` must run once per command/render that
needs reverse lookup, not once per UID. `all_report_paths_for_uid()` returns a
sorted set union of direct paths and the supplied in-memory additional paths.
At current report counts, an O(L) in-memory build is cheaper and safer than
maintaining a second persisted representation that can drift.

## Registry Mutation

Extend `ResearchReportRecord`:

```python
additional_uids: tuple[str, ...] = ()
```

Update `report_record_from_file()` to accept the tuple and every caller to pass
the parsed header value.

Update `add_report_registry_record()` so one operation:

1. Removes all old primary and additional relationships for the report path.
2. Adds the primary relationship exactly as today.
3. Stores the per-report additional UID list when nonempty.
4. Stores author/specs/size/hash/timestamp/original-path metadata as today.

Update `remove_report_registry_path()` to remove:

- the existing primary reverse/index metadata;
- the per-report additional UID list.

Keep its existing primary-UID return value so current report-count change event
callers continue to count one physical report. Additional relationships must
not create report-count add/remove events.

Keep `rebuild_research_report_reverse_index()` focused on the existing direct
`[research_reports]` index. Additional reverse lookup is rebuilt in memory from
`[research_report_additional_uids]` and must never be serialized. Header parsing
and per-report registration happen before building that lookup.

## Registry And Header Diagnostics

Extend `report_metadata_diagnostics()` with additional-target checks.

For registered reports:

- Compare normalized header additional UIDs with
  `[research_report_additional_uids]`.
- Reject a missing registry list when the header is nonempty.
- Reject a stale registry list when the header is empty.
- Reject any list mismatch.
- Verify every additional UID exists in `[files]`.
- Verify every additional target path exists.
- Reject primary/additional overlap.
- Require a present decimal size and a present canonical 64-hex SHA-256 registry
  value, then compare both to fresh/cached metadata. Missing or malformed
  integrity values are errors, not permission to skip the comparison.
- Require the per-report author registry value and compare it with the header;
  do not leave a non-counting report unexplained merely because the registry
  author is missing.

For unregistered central reports:

- Validate the header list structurally.
- Verify every additional UID and path.
- If valid, `execute-rescan-reports --apply` may register the report using the
  header list exactly as it already registers primary metadata.

Extend `collect_research_tracker_errors()` to validate all canonical state:

- Unknown UIDs, missing files, malformed registry values, duplicate links, and
  primary/additional overlap must appear under `## Errors`.
- Existing direct registry consistency must be checked in both directions:
  every `[research_reports][UID]` path must map back to that UID in
  `[research_report_uid]`, and every `[research_report_uid]` path must appear
  under the matching `[research_reports][UID]` entry.
- Additional relationship consistency is header versus the single canonical
  `[research_report_additional_uids]` value. There is no persisted additional
  reverse index to validate.
- Suppress dependent restatements of one root parser failure. For example, a
  present malformed primary header should emit `target_header_malformed`, not
  that error plus `target_header_missing`; a malformed additional list should
  not also generate one registry mismatch per token. Continue reporting
  independent problems on the same file.

Suggested stable diagnostic names:

```text
additional_target_header_malformed
additional_target_header_duplicate
additional_target_uid_duplicate: UID
additional_target_uid_is_primary: UID
additional_target_uid_unknown: UID
additional_target_path_missing: PATH
additional_target_registry_missing
additional_target_registry_mismatch
report_agent_registry_missing
report_size_registry_missing
report_size_registry_malformed
report_sha256_registry_missing
report_sha256_registry_malformed
direct_reverse_index_missing: UID
direct_reverse_index_mismatch: UID
revalidation_reason_missing
revalidation_reason_without_status
```

Use one canonical message shape so rescan, tracker errors, CLI output, and tests
do not disagree.

Differentiate semantic drift from repairable existing direct-index drift:

- Header versus per-report registry disagreement is semantic coverage drift.
  The report is non-counting and requires revalidation/rework.
- An unknown/missing additional target or primary overlap is semantic drift and
  requires revalidation.
- A direct `[research_reports]`-only disagreement is derived config corruption.
  It is non-counting while present, but `execute-rescan-reports --apply` may
  rebuild the direct reverse index from an otherwise matching primary header
  and per-report registry without changing the report artifact or inventing
  coverage.

## Counting Record Loader

Update `research_tracker_report_records()` so a report is returned only when:

- all existing direct-target, author, specs, size/hash, status, and footer checks
  pass;
- header additional UIDs match the per-report registry;
- all additional UIDs and paths are valid;
- the existing direct reverse index agrees in both directions; and
- the report is not under revalidation.

Populate `ResearchReportRecord.additional_uids` from the validated registered
tuple. One invalid additional target makes the entire report non-counting,
including its primary edge. This matches the report-level integrity and
revalidation model.

Replace the separate counting/error enumeration with one shared state collector,
for example `collect_research_report_state()`. One central-file enumeration and
one diagnostic pass must produce:

```python
valid_records: tuple[ResearchReportRecord, ...]
errors: tuple[str, ...]
direct_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]]
additional_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]]
report_agent_by_path: dict[str, str]
```

Build both maps in O(reports + additional links). Do not call
`central_report_files()` and `report_metadata_diagnostics()` once for counting
and again for errors as `render_research_tracker()` currently does. Do not scan
every report once per target UID.

The collector should maintain a lazy `target_exists_by_uid` cache (or a set of
live target UIDs) so ten reports/links to one UID produce one target path
existence check, not ten. Counting records and error output must derive from the
same diagnostics result so their validity rules cannot drift.

Represent diagnostics internally with a stable key such as
`(report_path, code, detail)` and render a sorted unique set. Do not append the
same underlying mismatch once during report diagnostics and again during index
validation. This prevents the tracker `## Errors` section from multiplying
equivalent errors while preserving distinct problems on the same report.

## ResearchTrackerEntry Changes

Replace ambiguous report collections with explicit fields:

```python
direct_report_paths: tuple[str, ...]
additional_report_paths: tuple[str, ...]
direct_coverage_report_paths: tuple[str, ...]
additional_coverage_report_paths: tuple[str, ...]
report_agents: tuple[str, ...]
thinking_counts: tuple[tuple[str, int], ...]
last_executed_at: str
```

Add properties:

```python
direct_covered
additional_covered
covered                 # direct_covered or additional_covered
coverage_state          # not_covered/direct_only/additional_only/direct_and_additional
all_report_paths        # unique direct + additional paths
coverage_report_paths   # unique qualifying direct + additional paths
```

`research_tracker_entries()` must:

- Fetch direct and additional records independently.
- Preserve non-B records for informational report-path/agent display.
- Apply `Only_Count_B_Reports_For_Coverage` to both relationship types.
- Determine state only from qualifying coverage records.
- Deduplicate report paths before total counts, agent lists, timestamps, and
  thinking-level totals.
- Calculate `xHigh`, `High`, and `Medium` from unique effective coverage reports
  for the item.
- Use the latest execution timestamp among unique direct/additional reports.

## Generated Tracker Output

Only `auto-generated/-ag-research-tracker.md` currently represents executed
report coverage. Reconstruction coverage reports such as
`-ag-memory-coverage.md` must not be changed merely because this relationship
exists.

### Summary

Keep current `Covered` and `Coverage` columns, but define them as effective
coverage: direct or additional. With no additional headers, their values remain
identical to current output.

Add mutually exclusive columns so the total is auditable:

```md
| Folder | Total | Covered | Coverage | Direct Only | Additional Only | Direct + Additional | Reconstructable Covered | Not Reconstructable Covered | B Reports | A Reports | C Reports | Unknown Reports | Additional Coverage Links |
```

Rules:

- `Covered = Direct Only + Additional Only + Direct + Additional`.
- Reconstructable/non-reconstructable coverage percentages use effective
  coverage.
- B/A/C/Unknown report counts remain counts of physical reports by their primary
  target folder. A multi-target report is counted once, not once per edge.
- Compute B/A/C/Unknown counts from unique valid `ResearchReportRecord` paths
  grouped by each record's primary UID folder. Do not flatten
  `ResearchTrackerEntry.all_report_paths`: after this extension that collection
  includes reports whose primary targets belong to other folders and would
  multiply/misplace physical report counts.
- `Additional Coverage Links` counts valid additional UID relationships whose
  additional target belongs to that folder and whose report qualifies under
  the active coverage filter. It is not a report count.
- A single report may add links in several folders without increasing physical
  report counts in those folders.

### Per-Folder Sections

For each folder, render these exclusive sections in this order:

```md
### Not-Covered Files - Reconstructable
### Additionally-Covered-Only Files - Reconstructable
### Directly-Covered-Only Files - Reconstructable
### Directly-And-Additionally-Covered Files - Reconstructable

### Not-Covered Files - Not Reconstructable
### Additionally-Covered-Only Files - Not Reconstructable
### Directly-Covered-Only Files - Not Reconstructable
### Directly-And-Additionally-Covered Files - Not Reconstructable
```

Preserve the exact `## by-memory` ->
`### Not-Covered Files - Reconstructable` assignment queue heading. It should
now contain only targets with neither qualifying direct nor qualifying
additional coverage.

Use these row columns for covered categories:

```md
| UID | Score | Combined | Reconstructable | Direct Reports | Additional Reports | Total Reports | xHigh | High | Medium | Last Executed | Agents | Path | Direct Report Paths | Additional Report Paths |
```

For not-covered rows, omit thinking columns as current output does, but retain
separate direct/additional informational counts and paths when non-counting A/C
reports exist.

Sorting:

- Keep the current score-priority sort for truly not-covered queues.
- Sort covered categories by unique total report count, latest execution time,
  then path, descending where the current covered sort is descending.
- Additional-only rows use the same covered sort.
- Never duplicate one UID across coverage-state sections.

### Executed Reports Submitted And Report Count Changes

Do not treat additional UID links as new reports.

- One executed report increments `Executed Reports Submitted` once.
- One execution adds one `Report Count Changes` physical-report event under the
  primary target's folder.
- Invalidation/de-execution removes one physical report event under the primary
  target's folder.
- Adding five additional UIDs does not add five report events.
- If trend tracking for coverage links is later desired, add a separate event
  type and section; do not overload the existing physical report metrics.

Repair the current trend-state algorithm while touching this section:

- `report_count_change_rows()` must reconstruct active physical report counts
  per UID. Its current `seen_before_window` set records whether a UID ever had a
  positive event and ignores later removals.
- Do not assume the event log contains every historical add: legacy reports may
  have only a current `[research_report_executed_at]` record or a later removal.
  Build one authoritative current physical count per UID from registered report
  paths that currently exist in the central executed archive (regardless of
  whether a revalidation lock makes them non-counting for coverage), then
  reconstruct each window's starting state by reverse-
  applying all in-window deltas to a copy of that current state (`+1` reverses
  to `-1`; `-1` reverses to `+1`).
- Replay the same window events forward from that reconstructed starting state.
  Classify a positive report event against the active count immediately before
  it, then increment; decrement for a negative event without going below zero.
- Use counts rather than live report-path membership for historical state.
  `executed-reassign` changes a report path without adding/removing a physical
  report event, so path-keyed historical membership would fail to match a later
  invalidation under the new path. The UID count correctly survives reassignment
  while still handling multiple reports, de-execution, invalidation, and
  remove-then-reexecute sequences.
- Keep `Total Reports Delta` signed. The current `New Reports` and `Added To
  Already Covered` values count positive physical submissions only, so rename
  them to `Reports Added To Previously Unreported Targets` and
  `Reports Added To Already Reported Targets`, and render them as unsigned
  counts. Avoid the word `Covered`: A/C reports may be physical reports without
  qualifying as coverage under B-only mode. Do not display a misleading
  `+0`/signed format for columns that never decrement.
- Keep `Reconstructable` and `Not Reconstructable` as classifications of
  positive report additions and label/document them accordingly. A removal
  affects `Total Reports Delta` but is not a newly submitted report.
- Preserve existing fallback synthesis from `[research_report_executed_at]` for
  reports that predate explicit add events, while deduplicating by normalized
  report path. The current-state reverse replay prevents those synthetic events
  from double-counting the authoritative present-day registry.
- Build current counts and sort/deduplicate events once. Four fixed windows may
  each reverse/forward replay the relevant event slice; this remains O(R + W*E)
  with W=4 and avoids an error-prone historical baseline guess.

## Lifecycle Command Requirements

### `execute_report`

1. Read fresh bytes/metadata for the active report and parse all report headers
   and the history footer before constructing write actions.
2. Fail on any `ReportHeaderMetadata.errors`, malformed footer, or live
   `REPORT-VALIDATION-STATUS: needs-revalidation`. A locked active report must
   use `active-clear-revalidation` after repair; execution must never erase the
   lock through a normal header upsert.
3. Require valid `TARGET-REPORT-UID`, `AUTHOR-AGENT-ID`, and
   `AUTHOR-AGENT-SPECS` headers. The author ID must match the command's B-agent
   ID. Normal execution must not invent missing provenance.
4. Resolve the primary command UID and require it to equal the valid primary
   header. Treat all target-detection errors, including unknown candidates and
   missing target paths, as blocking instead of archiving the report with a
   registry error.
5. Validate the additional list against the resolved primary UID and live
   target registry/paths.
6. Fail before moving, rewriting, appending history, changing config, or adding
   events when any preflight check fails.
7. Canonicalize and preserve the additional header during header upsert.
8. Include `additional_uids` in the `executed` history event.
9. Register all relationships atomically after the report is moved.
10. Continue adding exactly one report-count event for the primary UID.

For a reworked report with prior validator history, derive any old target from
the latest applicable historical execution/retarget event, not from a
command/header mismatch. If the validated current primary differs, append a
`retargeted-after-rework` event containing old/new UIDs. This preserves retarget
history while still requiring the exact reviewed current header to match the
execution command.

Remove the normal-execution fallback through `default_report_author_specs()`.
Keep `CHATGPT | 5.5 | xHigh` only as the explicit historical migration default
where the migration command documents that legacy provenance policy. Current
new-report workflow requires the actual report header (presently
`CHATGPT | 5.6 | xHigh`) and must preserve whatever valid actual specs it
contains. Also make `report_record_from_file()` require explicit validated
specs in normal callers rather than silently applying the legacy default.

Dry run must report planned primary and additional relationships without
changing files or config.

### `execute-rescan-reports`

- Register valid unregistered central reports from primary and optional
  additional headers.
- Compare registered header/per-report indexes.
- Rebuild the existing direct reverse index on apply and build additional
  reverse lookup only in memory.
- Mark a report `needs-revalidation` when an additional UID is unknown, missing,
  overlaps the primary UID, or no longer resolves to a target path.
- Do not silently replace a registered additional list from edited report text.
  A mismatch is a lifecycle integrity issue requiring revalidation/rework.
- Missing optional headers on legacy reports remain valid empty lists.

### `execute-confirm-change`

This command may confirm size/hash changes only after all additional-target
diagnostics pass. It must not silently adopt a changed additional UID header as
new registry coverage. Introducing or changing declared coverage on an already
executed report requires de-execution, report repair, Gate 1/Gate 2 review, and
re-execution.

This is also a required existing-command repair: perform fresh full diagnostics
before appending history or updating trusted size/hash. Require primary UID,
author ID, author specs, validation status, history footer, and all registry
identity fields to agree. The command may approve ordinary body/content changes
only. On any identity/provenance/coverage/status error, exit with no file,
history, config, cache, or event mutation.

### `invalidate_execute` And `executed-mark-invalid`

- Remove primary and all additional registry relationships.
- Continue recording one physical report removal event for the primary UID.
- Include the prior additional UID tuple in the lifecycle history event.
- Invalidated archives remain excluded from all direct/additional coverage.

### `executed-reassign`

- Require the source path to be registered and resolve a valid primary UID
  before choosing or writing the destination. Do not move an unregistered or
  unresolved report and leave it outside the registry.
- Run fresh full diagnostics first and reject malformed identity/coverage
  headers, missing integrity metadata, or registry drift before mutation. A
  correctly formed existing `needs-revalidation` lock is allowed because
  reassignment may route the report to the agent who will repair it; preserve
  the status/reason and keep the report non-counting.
- Preserve the header list.
- Move primary and additional registry paths from the old report path to the new
  path atomically.
- Preserve original execution timestamp and original-path metadata.
- Include additional UIDs in the reassignment history event.

### Revalidation Commands

- `executed-mark-needs-revalidation` locks all direct/additional edges.
- `executed-clear-revalidation` must refuse to clear while any additional UID,
  path, header, per-report registry, or direct-index diagnostic remains.
- `active-clear-revalidation` must preserve the optional header.
- Revalidation history events should include the complete declared target set.
- Clearance preflight must use fresh metadata. After writing a clearance event,
  refresh the exact cache entry and re-run diagnostics before reporting success.

### UID Removal, Split, Merge, And Retarget Handling

Change `mark_reports_for_uid_needs_revalidation()` to use
`all_report_paths_for_uid()` with one command-scoped in-memory additional-path
map.

`reconcile_missing_uids()` can remove many UIDs in one scan. Build the
additional reverse map once before its UID loop and pass it into each
`mark_reports_for_uid_needs_revalidation()` call; do not rebuild O(L) state for
every missing UID.

- Removing a UID marks reports that target it directly or additionally.
- Splitting a target never transfers coverage automatically to new child UIDs.
- Merging/removing an additional UID marks the whole report for revalidation.
- Retargeting the primary UID does not automatically add the old primary UID to
  the additional list.
- If a new primary UID already appears in the additional list, execution fails
  until the report author resolves the overlap.
- Pure path changes with an unchanged UID follow the same current direct-target
  policy; additional targets must not use weaker rules.

The existing `reconcile_missing_uids()` call into report revalidation is the
critical removal path and must reach the existing direct index plus the
in-memory additional relationship map.

### Existing Executed Reports

Do not implement automatic migration or body-based inference.

An existing executed report without the header remains direct-only. To add
additional coverage to an existing executed report:

1. Use `invalidate_execute` to return it to active research.
2. Repair the existing report text and add the header plus required per-target
   evidence/ledger/checklist content.
3. Run a fresh exact-artifact Gate 1 audit.
4. Complete and verify any implementation callback under Gate 2.
5. Re-execute it normally.

Do not manually edit an executed report and use `execute-confirm-change` as a
coverage-registration shortcut.

## History Footer

Add `additional_uids` as a JSON array to lifecycle events when a report has
additional targets. For no additional targets, either omit the field or emit an
empty array consistently; omitting it is preferred for backward-compatible,
compact legacy history.

Example:

```html
<!-- {"additional_uids":["0002Q5","0002Q6"],"event":"executed","uid":"0002Q4"} -->
```

Extend `make_report_history_event()` with an `additional_uids` tuple/list
parameter. Store it as a JSON array, not as the string representation of a
Python list. Extend `report_history_event_signature()` with a canonical joined
or tuple form of `additional_uids`; otherwise two events with the same command,
event type, and primary UID but different additional relationships could be
incorrectly deduplicated.

History remains append-only and validator-owned. Old events without the field
remain valid.

## Performance Requirements

The feature must not add repeated report-file reads or target-by-report nested
scans.

- Enumerate central report paths once and parse each report once through
  `report_file_metadata()`/the shared report-state collector.
- Cache normalized additional UIDs with existing mtime/size/hash metadata.
- Build direct and additional record maps in one pass.
- Persist only `[research_report_additional_uids]`; derive the reverse map in
  memory once. This removes duplicate config writes, reverse-index repair work,
  and a new class of drift diagnostics.
- Build a set of live target UIDs and, where needed, a cached set/map of existing
  target paths once per tracker render/rescan rather than calling `exists()` for
  every repeated relationship.
- Use set unions for direct/additional report paths and deduplicate before
  sorting/rendering.
- Keep physical report count events unchanged.
- Do not scan report bodies for UIDs.
- Do not globally invalidate unrelated metadata-cache entries.
- On report metadata cache misses, hash/decode one byte buffer and reuse one
  stat result; on cache hits, retain the current cheap mtime/size check.
- Render B/A/C/Unknown summary counts from the same valid-record collection,
  rather than repeatedly flattening per-entry path lists.
- Keep normal CLI output bounded: one concise action may report the primary UID,
  additional-link count, and at most `DEFAULT_ACTION_DETAIL_LIMIT` additional
  UIDs followed by a suppressed-count suffix. Do not emit one action line per
  additional relationship unless `--verbose` is requested. Preserve current
  command ID/timestamp and generated-refresh output.

Expected complexity for tracker aggregation is O(R + L + T), where R is valid
reports, L is declared additional links, and T is tracked target entries.
Memory is O(R + L + T) for the command-scoped state. No persistent whole-body
report cache or per-target nested scan is needed.

### Bundled Autogen Correctness Fix

Full and affected-root autogen cleanup must delete validator-owned NexusTK C++
whose source UID is no longer in the rebuilt active-root set, even when the old
by-file page still has a syntactically valid projected path. Destination-path
comparison alone leaves obsolete files behind after emission is moved or
disabled. Pass the current active-root set into stale cleanup; incremental
selection must still include previous roots so a root that just became inactive
is removed. This is validator-owned deletion with the existing daily backup
policy, not a manual-file deletion. Cover dry-run reporting and apply deletion
with an isolated regression test.

## Documentation And Skill Updates

The implementation is incomplete until all report-producing, reviewing, and
lifecycle guidance agrees on the optional header and its quality meaning.

### `tools/validator_README.txt`

Update `Executed Research Tracker` immediately after the primary target header
description:

- show canonical syntax;
- state that missing means no additional targets;
- list structural validation rules;
- explain direct/additional/effective coverage;
- explain B-only filtering;
- explain lifecycle handling and no automatic migration;
- state that normal execution requires valid matching target/author/specs
  headers and refuses live revalidation locks; only the explicit legacy
  migration path may apply its documented historical specs default;
- explain that one report remains one report in submission/change metrics;
- document how an existing executed report must be de-executed and re-executed
  to add coverage.

Update the generated tracker description to document the new summary columns,
exclusive buckets, row columns, and corrected `Report Count Changes` labels and
state-replay semantics.

### `.codex/skills/ntk-b-agent-workflow/SKILL.md`

Update the provenance-header example and coverage guidance:

- show the optional header;
- state that it is omitted when there are no additional targets;
- require full target-specific report depth, ledger rows, checklist items, Gate
  1, and Gate 2 for every declared UID;
- prohibit using broad additional lists as a shortcut;
- tell supervisors to skip effective-covered targets in the not-covered queue;
- require supervisors to treat execution failures for malformed identity,
  provenance, or revalidation status as report repair work, never as permission
  to use migration/defaulting or manually edit registry state;
- preserve the B-agent prohibition on lifecycle commands.

### `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`

Add the optional header directly after `TARGET-REPORT-UID`:

```md
** TARGET-REPORT-ADDITIONAL-UIDS:<UID>,<UID> **
```

Mark it optional and instruct agents to remove the line entirely when unused.
Add conditional target inventory, ledger, recommendation, and checklist rows
requiring per-additional-UID evidence and implementation proof.

### `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`

In report requirements and callback requirements:

- define primary versus additional target semantics;
- require each additional target to receive full relevant analysis;
- require exact destination and verification entries per UID;
- prohibit inferred or incidental coverage from references/support pages;
- require the same scoped validation and generated-refresh checks as direct
  target work.

### `.codex/skills/ntk-b-agent-workflow/references/supervisor-b-report-validation-preflight.md`

Extend provenance and Gate 1/Gate 2 preflight:

- record the normalized additional UID list in the audit;
- verify no duplicate/overlap/unknown targets;
- audit report section sufficiency per declared UID;
- verify callback implementation per declared UID;
- fail the entire report if any declared target fails.

### `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`

Add explicit no-loss handling for additional targets:

- every accepted claim for every declared UID must be incorporated, already
  present at equal/greater detail, or excluded with a concrete reason;
- no additional UID counts because it was merely mentioned;
- the supervisor must remove unsupported UIDs or return the report for repair;
- execution remains forbidden until both gates cover the complete target set.

### `tools/leaser/Agents/Supervisor.md`

Update provenance checks, audit-entry requirements, callback generation, and
execution verification so the supervisor records and verifies all declared
UIDs. Preserve all existing strict Gate 1/Gate 2 rules.

### `.codex/AGENTS.md`

Update the project B-agent report provenance summary and supervisor coverage
rules. Keep this concise and route detailed mechanics to the skill and validator
README.

## Test Plan

A focused standard-library `unittest` module lives under `tools/tests/` and
uses isolated temporary roots so it never reads or writes the live project
registry. Keep the following cases covered as the implementation evolves.

### Header Parser Tests

- Malformed primary target header is reported and is not replaced through
  normal execution/header upsert.
- Missing optional header returns `()` with no error.
- One valid UID.
- Multiple valid UIDs with mixed case and whitespace normalize correctly.
- Stable sorted canonical rendering.
- Empty header fails.
- Leading comma, trailing comma, and consecutive commas fail.
- Five-character/seven-character/illegal-character UIDs fail.
- Duplicate normalized UIDs fail.
- Duplicate header lines fail.
- Primary UID in additional list fails.
- Revalidation status without reason and reason without status both fail.
- Similar prose outside the header scan window is ignored.

### Cache Tests

- New cache field round-trips list to tuple.
- Legacy cached report entry without the field reparses once.
- Wrong-type cached field reparses.
- Unrelated cached by-* metadata remains valid.
- Instrument a cache miss to confirm one report byte read/hash/decode path and
  no duplicate `file_sha256()` reread.
- Lifecycle preflight bypasses/invalidates a deliberately stale exact-report
  cache entry without invalidating unrelated entries.

### Registry Tests

- Execute one primary with no additional UIDs: registry matches legacy shape.
- Execute one primary with several additional UIDs: the canonical per-report
  list and one-pass in-memory reverse map agree.
- Remove a report: all primary/additional edges disappear.
- Re-add the same path with a changed list: stale additional edges disappear.
- Rebuild the existing direct reverse index from the primary per-report index.
- Detect both directions of existing direct registry drift.
- Reject unknown UID, missing path, overlap, and duplicates.
- Strict registry-list parsing rejects empty/malformed/duplicate tokens and
  semicolon-delimited values round-trip through the actual `ConfigParser`.
- Missing/malformed size, SHA-256, or report-agent registry values are explicit
  errors and make the report non-counting.
- No `[research_additional_reports]` section is created or persisted.

### Lifecycle Tests

- Dry-run execution changes nothing.
- Applied execution preserves/canonicalizes the header and records all edges.
- Normal execution refuses any parsed header error, malformed footer, missing
  required identity/provenance header, command/header author mismatch,
  command/header target mismatch, target-detection error, or active
  `needs-revalidation` status, with byte-identical files/config afterward.
- Normal execution never applies legacy default specs; explicit legacy
  migration still applies its documented default when needed.
- Reworked execution with a changed validated primary UID records old/new UIDs
  from prior history without permitting a command/header mismatch.
- Rescan registers an unregistered valid central report with an optional list.
- Rescan accepts a legacy report with no optional header.
- Rescan marks a report for revalidation when an additional target disappears.
- Clearing revalidation fails while additional-target errors remain.
- De-execution and invalidation remove every edge.
- Reassignment moves every path relationship and preserves timestamp/history.
- Reassignment of an unregistered or unresolved report fails before creating a
  destination or changing the source/config.
- Reassignment may move a valid revalidation-locked report, but preserves its
  status/reason and non-counting state.
- Confirm-change refuses identity/provenance/coverage/status/footer errors and
  leaves history/hash/config untouched; a valid body-only change succeeds.
- Specs migration and revalidation-header updates do not erase the optional
  header.
- Removing a UID reaches reports where it is only an additional target.
- Split children do not inherit parent coverage.

### Tracker Tests

Create fixtures for all four exclusive states and both reconstructable states.
Verify:

- no UID appears in more than one state bucket;
- effective covered totals equal the union of direct/additional UIDs;
- summary exclusive counts add up;
- no-header fixture produces byte-equivalent numerical coverage to current
  direct-only behavior;
- B-only mode ignores A/C direct and additional edges for coverage state;
- all-agent mode accepts them;
- thinking-level counts use unique effective reports;
- direct/additional paths are rendered separately;
- a physical multi-target report contributes one submission/change count;
- additional link count reflects relationships, not physical reports;
- B/A/C/Unknown summary counts use unique physical reports grouped by primary
  target folder, even when additional targets span folders;
- report counting and `## Errors` consume one shared report-state collection;
- equivalent report/index diagnostics render once while distinct errors on the
  same report remain visible;
- malformed-present headers do not also render contradictory generic
  missing-header errors;
- `Report Count Changes` correctly replays multiple-report, remove, re-add,
  remove-then-reexecute, and reassign-then-remove event sequences using active
  physical counts per UID;
- `Total Reports Delta` remains signed while positive-addition columns use
  unsigned values and their clarified labels;
- existing `## by-memory` -> `### Not-Covered Files - Reconstructable`
  heading remains present and contains only truly uncovered entries.

### Live Read-Only/Dry-Run Verification

After isolated tests pass:

1. Run Python compilation for `validator.py` and `validator_background.py`.
2. Run an autogen dry run against the current project.
3. Confirm legacy reports without the optional header produce no additional-
   target errors. The three audited malformed-primary artifacts must each
   produce one precise malformed-header error and become non-counting.
4. Use a temporary copied fixture report/config for positive additional-target
   execution and lifecycle testing; do not mutate a live executed report merely
   to test the feature.
5. Compare current tracker totals before/after code deployment with no new
   headers. They must be unchanged except for the documented 2,165-to-2,162
   valid-report correction caused by the three malformed artifacts.
6. Add one controlled fixture with additional UIDs and verify only the expected
   target states and link counts change.
7. Confirm `Executed Reports Submitted` and `Report Count Changes` count the
   fixture once and that a copied remove/re-add event fixture is classified
   correctly.
8. Confirm command IDs/background generated-refresh behavior remains unchanged.
9. Compare tracker `## Errors` and physical report counts against an independent
   read-only registry enumeration to confirm the one-pass collector did not hide
   or duplicate reports.

## Rollout Order

Implement in this order to avoid partial-state corruption:

1. Add parser, data fields, canonical header rendering, and cache support,
   including malformed-primary detection and one-read cache-miss handling.
2. Add the one config section and atomic registry add/remove helpers; repair
   existing direct reverse-index and integrity diagnostics.
3. Harden execute/confirm/reassign preflight and legacy-default separation.
4. Extend diagnostics and UID-removal/revalidation lookup using one in-memory
   additional reverse map.
5. Add the shared report-state collector and dual-map tracker aggregation.
6. Add coverage-state properties and update tracker summary, sections, and row
   rendering.
7. Repair `Report Count Changes` event-state replay and labels.
8. Add isolated tests and backward-compatibility comparison.
9. Update README, skill, template, workflow, preflight, Rule 26, supervisor, and
   project AGENTS guidance.
10. Run dry-run/live read-only verification.
11. Only after all checks pass may new active reports begin using the header.

Do not enable agents to emit the header before validator execution, rescan,
invalidation, revalidation, and generated tracking all understand it.

## Acceptance Criteria

The extension is complete only when all of the following are true:

- Reports without the optional header behave exactly as direct-only reports.
- Missing optional headers produce no validation errors and require no
  migration.
- Malformed present headers fail with precise diagnostics.
- Primary and additional relationships remain distinct in config and output.
- Additional links have one persisted canonical registry representation and a
  command-scoped in-memory reverse map; no duplicate reverse config can drift.
- Every lifecycle command preserves or removes all relationships correctly.
- UID removal/split handling reaches additional-only relationships.
- Invalid or revalidation-locked reports count nowhere.
- `Only_Count_B_Reports_For_Coverage` applies to both relationship types.
- Tracker state buckets are mutually exclusive and totals reconcile.
- Physical report metrics never multiply by additional target count.
- Normal execution cannot clear a revalidation lock, bless malformed metadata,
  or invent author specs; confirmation and reassignment fail atomically on
  invalid state.
- Missing/malformed integrity registry values and both directions of direct
  reverse-index drift are reported and excluded from counting.
- `Report Count Changes` classifies add/remove/re-add sequences from active
  physical counts per UID rather than historical ever-seen UIDs.
- Existing generated tracker totals are unchanged when no reports use the new
  header, except for the explicitly audited three malformed-primary reports
  that correctly become non-counting.
- Metadata caching prevents repeated disk reads and aggregation is linear in
  reports plus links plus targets.
- A tracker render enumerates/diagnoses central reports once and reuses that
  state for records, errors, summary counts, and direct/additional maps.
- All listed documentation and skill files explain the feature consistently.
- Agents and supervisors understand that the header declares coverage but does
  not replace per-target evidence, incorporation, Gate 1, or Gate 2.

## Explicit Non-Goals

- No automatic migration of existing reports.
- No UID extraction from report bodies or filenames.
- No automatic coverage inheritance across parent/child, split, merge, owner,
  emitter, reference, or generated-source relationships.
- No change to reconstruction/source coverage reports outside the executed
  research tracker.
- No weakening of report quality, supervisor review, or lifecycle ownership.
- No manual editing of validator state or generated tracker files.
