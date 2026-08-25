validator.py
============

Scope
-----

This file is the canonical place for validator command and implementation
workflow details. by-structure.md should keep only the required high-level
workflow and point back here for command variants, repair behavior, generated
reference behavior, and completion-stat behavior.

validator.py is now the user-facing queue frontend. It writes each command to a
numbered queue, starts validator_background.py if needed, waits for the queued
job to finish, and relays the background result. validator_background.py owns
the actual validator implementation and processes queued jobs one at a time.

The validator only scans Markdown files below direct by-* folders under
project-documentation, for example:

- by-class
- by-file
- by-function
- by-memory
- by-meta
- by-type

The folder list is not hard-coded. Any direct project-documentation folder whose
name starts with by- is in validator scope.

Root-level Markdown files such as by-structure.md and instructions.md are not
part of the validator UID scope.

Required Workflow
-----------------

When a new Markdown file is created under a scanned by-* folder, run the
validator in file mode for that file immediately so it receives a stable UID
header and validator.ini mapping:

python validator.py --mode file --file ..\by-memory\example.md --apply

After a set of edits to one file is complete, normally run the validator once
for that file. Do not run repeated full or documented scans for ordinary
single-file edits. Use full, documented, or rescore mode only when the broader
registry, reverse references, or completion stats need to be rebuilt.

Normal file/full/documented scans now also refresh reconstruction autogen state
and generated `-ag-*` coverage reports unless `--uid-only` or
`--reference-only` is used. Use `--mode autogen` when only generated CPP/H and
autogen coverage reports should be rebuilt from already-scanned metadata.
For normal `--apply` scans this generated refresh is usually queued as
background work after the requested scan finishes. Use `--wait-generated` when
the generated CPP/H or `auto-generated/-ag-*` reports must be current before the
command returns.

For successful scoped validation, agents should report only command,
`command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh
state, relevant warnings, and target-specific side effects. Full raw stdout
should be included only for failures, unusual diagnostics, or when `--verbose`
was explicitly requested.

When a by-folder Markdown file is removed, run the missing-entry cleanup:

python validator.py --mode documented --remove-missing --apply

Do not manually edit `tools\validator.ini`, queue JSON, lock files, generated
Markdown, or generated report rows to repair missing files. The validator
lifecycle commands are the repair path. Use `--remove-missing` for removed
by-* Markdown files. For executed B-report registry issues, use the
executed-report lifecycle commands in this README instead of moving files or
editing registry entries by hand.

Path note: on this machine, E:\NTK\GhidraBridge\source-3 may resolve through a
Windows junction/symlink to C:\FastStorage\NTK_Sources\source-3. Validator
output may show the resolved C:\FastStorage path even when the command was run
against E:\NTK. Treat these as the same project tree when they resolve to the
same files.

For --mode file, --file accepts all common project path forms. Absolute paths
under either the E:\NTK junction path or the resolved C:\FastStorage path are
valid. Documentation-root relative paths such as by-memory\example.md are
valid. Workspace-relative paths such as
source-3\project-documentation\by-memory\example.md are also valid; the worker
normalizes these by stripping the project-documentation prefix instead of
joining the whole string under the documentation root.

Before queueing a job, validator.py canonicalizes recognizable --file values to
project-documentation-relative by-* paths such as by-class\ScreenPane.md. This
keeps queued jobs independent of the caller's current directory and avoids
accidentally doubling a source-3\project-documentation prefix through the
junction. validator_background.py repeats the same by-* preference when
resolving the queued path, so direct E:\NTK paths, resolved C:\FastStorage
paths, workspace-relative paths, and documentation-root-relative paths should
all resolve to the same scanned file.

Metadata Header
---------------

Validator-managed Markdown files start with this metadata block:

*** UID:000001 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

Direct singular `by-file/*.md` pages whose filename does not start with `-`
also get this validator-managed line immediately after CONFIDENCE:

*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

Do not remove or rewrite validator-managed header lines. Edit only the intended
value field for each line:

- `COMPLETION` and `CONFIDENCE`: numeric value only.
- `PROPOSED_RECONSTRUCTION_PATH`: path inside quotes only.
- `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, and
  `EMITTER_POSITION_OPTIONAL`: value after the colon only.
- `RECONSTRUCTION_CPP CODE:BEGIN/END`: C++ between the begin/end lines only.
  Follow the active code-entry gate in `../by-structure.md`: final-output C++
  may be entered only when the item is `RECONSTRUCTABLE:TRUE`, has one or more
  confirmed nonblank `EMITTER_UIDS` that surface to valid generated source
  output without a dead-end, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
  This is minimum eligibility, not permission for weak or placeholder code:
  dependencies, names, boundaries, and source placement still need enough
  evidence to support final-output source. A 95+ score remains a rare
  final-audit score, but it is not required merely to enter final-quality
  reconstruction C++.

COMPLETION and CONFIDENCE use these values:

- 1-100: evaluated score.
- 0: unevaluated.
- -1: ignored/excluded from completion statistics.

The validator stores and reports these numbers, but it does not prove that a
score is deserved. Do not set either COMPLETION or CONFIDENCE to 95 or higher
unless the page has already received an extreme verification pass and the page
itself records the evidence. A 95+ score is a near-final audit state for the
whole documented item: all material data must be verified, exact boundaries and
surrounding items checked, dependencies/callees and referenced state reviewed,
generated or synthetic names resolved or explicitly justified, and source
placement/rebuild handling documented. If that evidence is incomplete, partly
remembered from the current session, inherited from generated Wave/Wave2/Wave3
data, or not written into the page, keep the score below 95.
Treat 94 as the practical ceiling for normal improvement work; 95+ is reserved
for an explicit final-audit decision on that exact file or item.

Do not set only one metric to 95+ as a shortcut. Completion at 95+ still needs
verified evidence and defensible confidence, and confidence at 95+ still needs
specific written documentation for another agent to audit the page directly.

When the validator finds an existing UID header without COMPLETION or
CONFIDENCE, it adds the missing lines. Normal binary-data documentation defaults
to 0. The folders by-external-research, by-meta, and by-project-structure default
to -1 when score lines are missing because those pages are not scored as direct
binary reconstruction work.

If the UID line is missing or damaged but validator.ini already has exactly one
path mapping for that file, the validator restores the UID from validator.ini
instead of allocating a new one. If a COMPLETION or CONFIDENCE line is damaged,
the validator restores the last known value from validator.ini; if no valid
stored value exists, it uses the folder default.

By-file Projected Reconstruction Paths
--------------------------------------

Every normal singular page directly under `by-file` represents a proposed
source module and is treated as a generated CPP/H root. Fill
`PROPOSED_RECONSTRUCTION_PATH` with the folder in the reconstructed project
where that source file should be emitted. Use a project-root-relative folder
path, with a trailing slash, and no filename or extension. The canonical
project root is `NexusTK/`:

*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

The generated `.cpp` filename is derived from the Markdown filename, not from
the path value. For example, `by-file/AlphaMaskSurface.md` with
`NexusTK/render/` stages:

auto-generated/NexusTK/render/AlphaMaskSurface.cpp

The path rules are strict:

- relative path only;
- must start with exact casing `NexusTK/`;
- must end with `/`;
- folder only, no filename or extension;
- no empty path segments;
- no `.` or `..` segments;
- no Windows-invalid filename characters.

Use forward slashes when editing the value. If backslashes are entered and the
path is otherwise valid, the validator normalizes the saved line to forward
slashes during the next scan.

Recommended workflow:

1. Decide the likely reconstructed folder from the by-file evidence and
   `by-project-structure/proposed-source-tree.md`.
2. Edit only the quoted path value on the by-file page.
3. Run a normal file scan, for example:

   python validator.py --mode file --file by-file\AlphaMaskSurface.md --apply

4. Check validator output for `projected_path_invalid`,
   `projected_cpp_conflict`, `projected_header_conflict`, or stale-source
   deletion diagnostics.
5. Keep `by-project-structure/proposed-source-tree.md` in sync when the path
   establishes or changes the proposed source location.

Blank means the source placement has not been assigned yet. Invalid paths are
recorded in validator.ini [projected_path_errors] with keys starting
`bad_projected_path_...` and are reported during scans.

Use the exact value `NONE` only for a reviewed direct by-file page that should
not emit a standalone generated source root, such as a generated alias/helper,
non-source umbrella note, or planning placeholder. A `NONE` projected path is
recorded as a non-standalone disposition, excluded from
`projected_path_completion`, and shown in file autogen coverage as
`not_reconstructable`. The page must document the corrected owner or the reason
it is intentionally not promoted. Do not use `NONE` to avoid unresolved source
placement research.

During a scan, the validator records the path state in validator.ini:

- [projected_paths]: UID to current proposed path value.
- [projected_path_status]: `blank`, `valid`, `invalid`, or `none`.
- [projected_path_errors]: current invalid-path diagnostics.

When the path is valid, the validator creates an empty `.cpp` placeholder under
`project-documentation/auto-generated` if one does not already exist. It never
creates an empty `.h`; a sibling `.h` exists only while assembled H content is
nonblank. If the proposed folder changes, or the by-file Markdown file is
renamed, the validator preflights and moves the existing generated `.cpp`/`.h`
pair together. A conflict on either destination aborts both moves. After a
successful move, empty generated folders below `auto-generated` are removed.

The full `auto-generated/NexusTK` subtree is validator-owned output. During
autogen, an existing target file in that subtree is replaceable even if it was
created by an older validator version without the current autogen sentinel, was
manually edited, or is no longer readable as UTF-8. The validator backs up
changed generated files under `tools/validator_autogen_backup` and writes fresh
generated content. A full generated refresh also removes stale/orphan `.cpp`
and `.h` files in this subtree that are no longer current validator
destinations. Do not
put manual source edits in `auto-generated/NexusTK`; write source facts and
reconstruction code into the owning by-* documentation and rerun the validator.

Validator-owned `auto-generated/-ag*.md` reports follow the same rebuild rule.
If one is manually edited, corrupted, missing its sentinel, or unreadable, the
next validator command that targets that report backs it up and rewrites it
from source metadata instead of reporting a manual-file conflict.

Validator-generated files include refresh metadata. Generated Markdown uses
HTML comments:

<!-- validator-command-id: 000000000000 -->
<!-- validator-refreshed-at: 2026-01-01T00:00:00-05:00 -->
<!-- validator-refresh-source: foreground-generated-refresh -->

Generated CPP and H under `auto-generated/NexusTK` use the same keys as source
comments so the staged files stay valid:

// validator-command-id: 000000000000
// validator-refreshed-at: 2026-01-01T00:00:00-05:00
// validator-refresh-source: foreground-generated-refresh

Refresh metadata is scoped to the generated artifacts targeted by the command.
A full generated refresh targets all validator-generated artifacts, so all
headers are refreshed. An incremental file scan targets only affected generated
roots and reports; unrelated generated files keep their previous command ID and
timestamp. If a targeted generated artifact's body is unchanged, its refresh
metadata is still updated because that command explicitly refreshed that
artifact.

Every validator frontend call prints:

command_id: 000000000000
command_timestamp: 2026-01-01T00:00:00-05:00

Generated-refresh status also prints `generated_refresh`,
`generated_refresh_command_id`, and `generated_refresh_timestamp`. A normal
file/full/documented `--apply` command may report `generated_refresh: deferred`,
which means the requested by-* scan is done but lower-priority generated output
will be refreshed by a later background job. Do not assume a generated report or
generated CPP/H file opened immediately after that command is current. Compare the
command's returned ID/timestamp with the generated file header:

- equal or newer generated `validator-command-id` means that generated file has
  caught up to that command;
- lower/older generated `validator-command-id` means that generated file is
  still stale for that command or was not targeted by that command.

Use `python validator.py --queue-status` to inspect queued/processing generated
refresh work. Use `--wait-generated` on the original command when an agent must
read current generated output before continuing.

If a projected path is cleared, becomes invalid, or changes to `NONE`, the
validator deletes stale validator-owned `.cpp` files under
`auto-generated/NexusTK` whose embedded source UID no longer resolves to that
generated destination. Changed or deleted generated files are backed up under
`tools/validator_autogen_backup`.

The projected-path line is intentionally only for direct singular `by-file`
pages. Do not add it to nested by-file support pages, `-xxx.md` control files,
classes, globals, memory ranges, functions, resources, meta pages, or other
folders. Direct singular by-file pages use `CANONICAL_OWNER:FILE` with a valid
projected path to become generated source roots. Other pages use
`CANONICAL_OWNER` for semantic ownership and `EMITTER_UIDS` for generated CPP/H
routing when they need to contribute source.

Reconstruction Autogen Metadata
-------------------------------

Validator-managed singular entity pages use `CANONICAL_OWNER` to record the
best direct semantic owner. Eligible code-bearing documentation pages can also
contribute reconstructed CPP/H source into the staged files under
`auto-generated/NexusTK`. This applies to singular item pages such as
`by-class`, `by-memory`, `by-global`, `by-function`, `by-item`, and `by-type`
pages.

The validator does not add reconstruction-emitter metadata to `by-file`,
`by-meta`, `by-external-research`, `by-project-structure`, `by-resource`,
root-level docs, tool docs, generated docs, or any `-xxx.md` support/control
page. Direct by-file pages instead become source roots through
`CANONICAL_OWNER:FILE` and a valid `PROPOSED_RECONSTRUCTION_PATH`.

Eligible pages receive these validator-managed lines after UID, COMPLETION, and
CONFIDENCE:

*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

`CANONICAL_OWNER` accepts `NONE`, `FILE` only on direct by-file source roots,
or an existing validator UID. It is a documentation ownership field only; it
does not route generated CPP/H and it is valid on non-reconstructable pages.
`RECONSTRUCTABLE:FALSE` pages may have canonical owners, but they must not have
nonblank `EMITTER_UIDS` or nonblank reconstruction code.

`RECONSTRUCTABLE` accepts blank, `TRUE`, `1`, `FALSE`, and `0`. Blank means
unevaluated. `TRUE` or `1` means the page is confirmed NexusTK-owned source
that must be rebuilt. A reconstructable page may intentionally have no
canonical owner or emitter route yet; the autogen reports list missing
ownership as `no-owner` and missing output routing as `non-emits` until the
relationships are proven well enough. Do not delay setting
`RECONSTRUCTABLE:TRUE` merely because final ownership, emitter routing, or
final C++ code is not ready.

`EMITTER_UIDS` must be blank or a comma-separated list of existing validator
UIDs. Do not guess them. If an emitter page is new, validate it first or use
the TMP reference workflow elsewhere and come back after the UID exists.
Emitter chains should eventually resolve to a singular `by-file` page with
`CANONICAL_OWNER:FILE` and a valid `PROPOSED_RECONSTRUCTION_PATH`. Only fill
this when output routing is high-confidence enough to affect generated source
structure. Multiple emitters are allowed when the same reconstructable item must
be emitted under multiple parent targets.

`EMITTER_POSITION_OPTIONAL` is blank by default. A single numeric value sorts
the item under every emitter before blank-position children. A comma-separated
list aligns with `EMITTER_UIDS`; empty entries mean no position for that
specific emitter, for example `1,,3`. Items with positions sort before items
without positions. Items with the same position, or no position, preserve
first-seen scan order.

Legacy note: older documentation and research may still mention
`AUTOGEN_PARENT_UID` or `AUTOGEN_PARENT_POSITION_OPTIONAL`. Those names belonged
to the previous combined system. In current terms, old `AUTOGEN_PARENT_UID`
means `CANONICAL_OWNER` when discussing ownership and `EMITTER_UIDS` when
discussing generated output routing. Old `unassigned` report wording generally
maps to `no-owner` and/or `non-emits`.

Put real multiline C++ between the BEGIN and END lines only when the item,
parent, dependencies, and surrounding memory ranges meet the reconstruction
quality bar documented in `by-structure.md`. Code without an emitter route is
invalid because the validator has no safe generated destination. Do not use
Markdown fences inside this managed block. `[[CHILDREN]]` inside the C++ block
is the explicit insertion point for recursively assembled children. If the marker is
present but no child snippets are attached yet, generated output shows
`[[No Children Attached]]` at that point so the placeholder is easy to see. If
a class/struct snippet has children but no marker, the validator attempts a
conservative fallback before the final `};`. Function/method snippets require
the explicit marker before children are inserted inside them.

The `RECONSTRUCTION_H CODE` block is an independent header-source channel. It
must appear immediately after `RECONSTRUCTION_CPP CODE:END`. Empty or
whitespace-only H content is ignored and creates no file. Nonblank H content
uses the same `EMITTER_UIDS` graph and deterministic child order as CPP, but it
is assembled separately into the sibling `.h` for the generated `.cpp` root.
For example, `auto-generated/NexusTK/app/Application.cpp` maps to
`auto-generated/NexusTK/app/Application.h`. `[[CHILDREN]]` may be used once in
each channel independently. A marker in CPP places only CPP children; a marker
in H places only H children.

Header declarations do not make an item implementation-coded and do not clear
the existing CPP no-code/empty-emitter state. Relevant `-ag-*` reconstruction
reports show `Code` and `Header Code` separately. The validator does not invent
`#include` lines, include guards, `#pragma once`, forward declarations,
namespaces, or formatting, and it does not automatically include generated H
from CPP. Put only evidence-backed final-source header text in the H block. The
version-1 third-party import directive remains CPP-only.

H-channel diagnostics are repaired at the source by-* page, then validated:

- `reconstruction_h_invalid`: restore exactly one H BEGIN/END pair immediately
  after CPP END; the validator fails closed and does not guess around malformed,
  duplicated, partial, reversed, or misplaced markers.
- `emitter_header_without_route`: nonblank H source needs a valid
  `RECONSTRUCTABLE:TRUE` emitter route, just like CPP source.
- A dead-end emitter route must be fixed in `EMITTER_UIDS`; header content does
  not hide or bypass the dead end.
- `autogen_header_stale_delete` is normal when the last assembled H fragment is
  cleared or its root is removed; the validator deletes the obsolete sibling.
- `projected_header_conflict` aborts the CPP/H path move as a pair. Resolve the
  conflicting by-file destination/UID and rerun the scoped validator; never move
  generated files manually.

The inline `RECONSTRUCTION_CPP CODE` value can also import vetted third-party
source files instead of carrying direct C++ text. The inline value must be
exactly an import directive:

*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/lodepng/lodepng.cpp","third_party_embeds/lodepng/lodepng.h"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

Import paths must be quoted, comma-separated, relative to the `source-3` root,
start with `third_party_embeds/`, and end in `.c`, `.cpp`, or `.h`. Absolute
paths, drive-letter paths, backslashes, `.` or `..` segments, empty path
segments, duplicate paths, and Windows-invalid filename characters are rejected.
When an import directive is valid, generated C++ reads each listed source file,
emits a source-identifying comment and begin/end separator for each file, and
folds the imported file hash into the reconstruction code hash. Keep the
multiline BEGIN/END block blank when using an import directive.

Use this only when the listed third-party files are the vetted source that
should appear in the staged generated output. Do not paste a copy of the same
third-party source into the multiline block. After editing an import directive,
run a file scan with generated output enabled, for example:

python validator.py --mode file --file by-memory\ExampleThirdPartyItem.md --apply --wait-generated

Autogen Output
--------------

`--mode autogen` rebuilds generated CPP/H source, the `-ag-*` coverage reports, the
executed-research tracker, and the by-memory auto coverage report from the
current validator registry and Markdown files. It does not assign UIDs or update
UID references, but it may insert missing by-memory auto coverage metadata:

python validator.py --mode autogen
python validator.py --mode autogen --apply

Full, documented, and file scans also run autogen output generation unless
`--uid-only` or `--reference-only` is used.

Executed Research Tracker
-------------------------

Executed B-agent research is centralized under:

executed-b-agent-research\<agent-id>

This central tree is the current executed-report home. Per-agent
`tools\leaser\Agents\Agent-B###\research\executed` folders are legacy input
or historical context only; do not manually move newly accepted reports there.

The validator records executed report path, primary target UID, optional
additional target UIDs, author agent, author agent specs, size, SHA-256,
execution timestamp, original path, and report errors in validator.ini.
Generated research coverage is written to:

auto-generated\-ag-research-tracker.md

Normal report execution commands are dry-run by default. Use `--apply` to move
files, edit report headers, update validator.ini, and refresh generated output.
After supervisor verification of a B-agent implementation callback, this is the
normal way to mark the report executed. Do not hand-edit validator.ini or
manually maintain the generated research tracker.

Execute an active agent research report:

python validator.py execute_report B002 report-name.md --apply
python validator.py execute_report B002 report-name.md 00015I --apply

Every normally executed report must already contain a valid primary target
header. The optional command UID is a consistency check and must match it:

** TARGET-REPORT-UID:00015I **

A report may declare additional targets that the same report fully covers:

** TARGET-REPORT-ADDITIONAL-UIDS:00015J,00015K **

This header is optional. Its absence means the report has no additional target
coverage. When present, it must contain one or more comma-separated valid UIDs.
The validator normalizes case/order and rejects empty tokens, duplicate UIDs,
duplicate header lines, unknown target UIDs, and overlap with the primary UID.
Do not add a UID merely because the report mentions or references that item;
each declared UID requires target-specific evidence, recommendations, ledger
entries, implementation checklist work, supervisor Gate 1 review, and Gate 2
implementation verification.

The primary relationship is direct coverage. Relationships declared in
`TARGET-REPORT-ADDITIONAL-UIDS` are additional coverage. Effective coverage is
their union, while the generated tracker keeps direct-only, additional-only,
and direct-plus-additional states distinguishable. When
`Only_Count_B_Reports_For_Coverage = true`, only qualifying B reports affect
either relationship type. One physical report still counts once in report
submission and report-count-change metrics regardless of how many target links
it declares.

Every normally executed report must already contain a valid author header that
matches the command's B-agent ID:

** AUTHOR-AGENT-ID:B002 **

The validator also requires this author model/provenance header:

** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

The specs value is three pipe-separated fields: model/provider label, model
version, and thinking level. Missing or malformed target, additional-target,
author, or specs headers are validator errors. Normal `execute_report` never
invents missing provenance or bypasses a live `needs-revalidation` lock. Only
the explicitly documented one-time legacy migration may apply its historical
default specs value.

Executed reports may also contain validator-owned lifecycle metadata:

** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003BM **

`needs-revalidation` means the report no longer counts as normal coverage until
a validator lifecycle command clears it or the report is de-executed, repaired,
and re-executed. Do not remove these headers by hand.

Executed reports may end with a validator-owned footer:

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"event":"executed","uid":"00015I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->

The footer is an append-only audit trail for execution, revalidation,
invalidation, reassignment, and size/hash confirmation events. It must never be
manually edited.

Invalidate an executed report and move it back to the agent research folder:

python validator.py invalidate_execute B002 report-name.md --apply

Use this command, not manual file moves, when an executed report must be
returned for rework. During invalidation the validator clears any
`REPORT-VALIDATION-STATUS: needs-revalidation` header from the active returned
copy and appends a lifecycle history event; do not remove those headers by hand.
To add, remove, or change additional target coverage on an already executed
report, use this de-execution path, repair and revalidate the active report,
then execute it again. `execute-confirm-change` accepts content changes only;
it deliberately refuses coverage-identity changes.

If a report was returned to `tools\leaser\Agents\Agent-B###\research` by an
older validator before invalidation cleared the status header, use the
validator-owned active repair command:

python validator.py active-clear-revalidation B002 report-name.md --apply

This command is only for active returned reports in an agent research folder.
It clears the active copy's `needs-revalidation` header and appends an
`active-revalidation-cleared` history event without registering or executing the
report. Supervisor Gate 1/Gate 2 review and normal `execute_report` are still
required afterward.

Move an executed report to the invalidated archive so it no longer counts for
coverage:

python validator.py executed-mark-invalid B002 report-name.md --apply
python validator.py executed-mark-invalid --report-path executed-b-agent-research/B002/report-name.md --apply

Use `executed-mark-invalid` when the report should be archived as invalid rather
than returned to active research. Invalidated reports are stored under
`executed-b-agent-research/invalidated/<agent>/` and are excluded from normal
coverage, report counts, and generated tracker report paths.

Mark a registered executed report for manual revalidation:

python validator.py executed-mark-needs-revalidation B002 report-name.md --reason "manual split review required" --apply

Clear a revalidation marker after supervisor review proves the report still
matches the current target:

python validator.py executed-clear-revalidation B002 report-name.md --apply

The clear command refuses to run while live target UID, target path, target
header, author, specs, or integrity diagnostics remain unresolved.

Rescan executed reports for missing registry entries, stale sizes, and stale
hashes:

python validator.py execute-rescan-reports --apply

Use this command for executed-report registry repair. Do not edit
`tools\validator.ini` to add, remove, or update executed-report rows manually.
When a split, UID removal, or target drift makes a report potentially stale,
`execute-rescan-reports --apply` may add `needs-revalidation` metadata and a
footer history event instead of silently counting the report as covered.

After supervisor review of an intentional post-execution content change, accept
the current file size and hash:

python validator.py execute-confirm-change B002 report-name.md --apply

After a supervisor-reviewed bulk cleanup that moved executable automation out
of report bodies into inert same-name `-removed.md` siblings, confirm only
those registered reports whose remaining diagnostics are size/hash drift and
whose source/archive warning linkage validates:

python validator.py execute-confirm-removed-archives --apply

The command fails closed per report for missing registration, malformed report
metadata, any non-integrity diagnostic, missing source/archive linkage, or a
removal archive without an explicit non-authoritative do-not-execute warning.

Reassign an already-executed central report to another agent folder:

python validator.py executed-reassign B002 report-name.md B006 --apply
python validator.py executed-reassign unknown report-name.md B006 --apply

Migrate old executed reports from live and archived agent folders into the
central executed-research tree:

python validator.py migrate-executed-reports --apply

One-time metadata migrations:

python validator.py migrate-report-agent-specs
python validator.py migrate-report-agent-specs --apply
python validator.py migrate-report-history
python validator.py migrate-report-history --apply

`migrate-report-agent-specs` inserts the default author-specs header into
existing central executed reports and active B-agent research reports, updating
executed-report registry size/hash/spec values as needed. `migrate-report-history`
backfills a legacy footer history entry for registered central executed reports
only; it skips unregistered central files rather than inventing execution
history.

`auto-generated/-ag-research-tracker.md` covered-row sections include
informational `xHigh`, `High`, and `Medium` columns. These count valid
coverage-counting reports for that row by the thinking-level field in
`AUTHOR-AGENT-SPECS`; they do not change coverage scoring.

The tracker summary keeps effective `Covered`/`Coverage` totals and also shows
mutually exclusive `Direct Only`, `Additional Only`, and `Direct + Additional`
counts. Per-folder target sections use the same four exclusive states:
not-covered, additional-only, direct-only, and direct-plus-additional, each
split by reconstructable state. Covered rows show separate direct, additional,
and total report counts/paths. The exact assignment queue heading
`### Not-Covered Files - Reconstructable` is retained.

`Report Count Changes` tracks physical executed reports, not target links. Its
columns are `Total Reports Delta`, `Reports Added To Previously Unreported
Targets`, `Reports Added To Already Reported Targets`, `Reconstructable
Additions`, and `Not Reconstructable Additions`. The validator reverse-replays
remove, re-execute, and reassignment events to reconstruct each window's
starting state, then classifies forward additions against that state. Adding
additional target UIDs does not multiply report counts.

By-Memory Auto Coverage
-----------------------

The generated by-memory coverage report is written to:

auto-generated\-ag-coverage-report-by-memory.md

This report is validator-owned generated state. Do not edit it directly. Change
the source by-memory page metadata and rerun the validator instead.

The existing manual `by-memory\-coverage-report.md` remains intact as a legacy
manual report. The generated `-ag-coverage-report-by-memory.md` is the normal
machine-refreshable by-memory coverage view. The validator injects these
editable metadata lines into ordinary by-memory pages when by-memory auto
coverage generation runs with `--apply`:

*** Item Summary:  | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

`Item Summary` is the row summary used by the generated coverage report.
`Nested` is a relative nesting delta from the previous address-sorted row:
positive values indent, zero keeps the current level, and negative values lift
back toward the top level.

Keep `Item Summary` short and factual. Do not repeat fields that the generated
report already renders automatically, including UID, path, address range,
completion, confidence, reconstructable state, owner, emitters, or generated
score/status text. Use the summary for the human-readable role of the memory
range only.

Generated CPP/H is written only under `project-documentation\auto-generated`.
Every file under `auto-generated/NexusTK` is validator-owned: a manually edited,
corrupt, unreadable, or sentinel-missing target is backed up and rebuilt when
that target is refreshed. Such corruption is not preserved as a manual-file
conflict. Keep all authored source in the formal by-* reconstruction blocks.

Each assembled child snippet is preceded by a source comment identifying the
source documentation item:

// UID:000123 | by-memory/ExampleMethod.md | Completion:95 | Confidence:95

These comments are emitted at the actual insertion point, including nested
children, so generated files can be traced back to their source docs without
guessing which page contributed a class, method, global, or helper body.

Empty routed emitters can also emit trace-only marker comments. This is
controlled by validator.ini `[settings]`:

force_empty_emitters_to_emit_marker_comments = true
force_empty_emitters_to_emit_marker_comments_consider_not_coded = true
force_empty_emitters_to_emit_marker_comments_consider_deadend = true

When enabled, a reconstructable document with nonblank `EMITTER_UIDS` and a
blank `RECONSTRUCTION_CPP CODE` block emits a marker such as:

// UID:000123 | by-memory\0x00401000-0x00401010.Example.md | Completion:95 | Confidence:95 | Empty Emitter Marker

The marker is not emitted for documents with blank `EMITTER_UIDS`. With
`consider_not_coded` enabled, marker-only output does not make the item count
as `coded` in the `-ag-*` reports. With `consider_deadend` enabled, an empty
emitter whose route does not reach a by-file generated root is still reported
as a dead end; the marker does not hide the broken route.

Generated coverage reports live directly under `auto-generated`:

- `-ag-file-coverage.md`
- `-ag-class-coverage.md`
- `-ag-function-coverage.md`
- `-ag-global-coverage.md`
- `-ag-item-coverage.md`
- `-ag-memory-coverage.md`
- `-ag-type-coverage.md`

Each report includes `Total_Type`, `Total_Reconstructable`,
`Total_Not_Reconstructable`, `Total_Reconstructable_Routed`,
`Total_Reconstructed_Coded`, `Total_Reconstructed_Header_Coded`,
`Total_Reconstructable_NoOwner`,
`Total_Reconstructable_NoOwner_Emitters`, `Total_Reconstructable_Emits`,
`Total_Reconstructable_Emitters_NoCode`, `Total_Reconstructable_NonEmits`,
`Total_Reconstructable_MultipleEmitters`, `Owner_None`, `Owner_Blank`,
`Owner_Specified`, `Owner_SpecifiedMultiple`, `Total_DeadEnds`,
`Total_Unclassified`, and `Total_Error`. Each report table uses `Canonical
Owner`, `Emitters`, `Code`, `Header Code`, `Destination`, and `Header
Destination` columns. CPP `Code` and `Total_Reconstructed_Coded` retain their
implementation-coverage meaning; declarations are tracked separately.
`Total_Reconstructable_NoOwner_Emitters` counts
reconstructable no-owner rows that still have one or more emitter routes.
`Total_Reconstructable_Emitters_NoCode` counts reconstructable rows that have
emitter routes but no inline reconstruction code yet. `Owner_None` counts
explicit `CANONICAL_OWNER:NONE`; `Owner_Blank` counts missing or blank owner
metadata; `Owner_Specified` counts `FILE` or UID owners;
`Owner_SpecifiedMultiple` is a defensive malformed-owner count and should
normally stay zero because multiple output routing belongs in `EMITTER_UIDS`.
The bottom of each report includes `Multiple Emitters`, `Owner Blank`, `Owner
None`, `Dead Ends`, and `Errors` sections so multi-route items, owner gaps,
routes that do not surface to a file root, and validation errors are visible
without scanning the main table by hand.

The old non-`ag` placeholder reports are no longer authoritative:

- `auto-generated/-file-coverage.md`
- `auto-generated/-global-coverage.md`
- `auto-generated/-memory-coverage.md`

Use the `-ag-*` reports for reconstruction autogen status.

Before overwriting or deleting generated files in apply mode, the validator
backs up changed generated outputs under:

tools\validator_autogen_backup\<timestamp>

UID Allocation
--------------

UIDs are exactly six characters using uppercase base-36 digits:

000001
000002
000003

The allocator uses validator.ini [state] last_used_uid as the source of truth.
When a Markdown file is missing a UID, the tool assigns the next UID after
last_used_uid and records the file path in order under [files]. Completion and
confidence values are recorded under [completion] and [confidence].

If a valid UID maps to an old path and that old path still exists, the validator
reports duplicate_path_conflict instead of overwriting the mapping. This protects
against copied files stealing an existing UID. Real renames are still handled:
when the old mapped path no longer exists, scanning the renamed file updates
[files].

Queued Execution
----------------

Multiple agents may invoke validator.py at the same time. Each invocation is
queued in first-enqueued, first-run order under:

tools\validator_queue

validator.py starts validator_background.py when no worker is running. The
background worker keeps running and holds this single-instance lock:

tools\validator_worker.lock

Only one background worker can run at a time. If a second worker starts, it
exits because the worker lock is already held. The old direct validator state
lock still exists inside validator_background.py:

tools\validator.lock

That direct lock protects validator.ini during the actual job execution and
protects against accidental direct validator_background.py runs. Do not bypass
the queue for normal work. Use validator.py for ordinary commands so concurrent
calls are queued instead of racing validator.ini.

Parallel validator.py calls should be safe for normal use. If many agents call
validator.py at once, their commands are queued and processed one at a time by
the background worker, so simultaneous calls should not corrupt validator.ini or
crash because of concurrent writes. Logs are still easier to read when one
agent runs its own commands sequentially.

Queue deduplication is controlled by validator.ini:

[queue]
enable_dedup = true
enable_strong_dedup = true

When enabled, the worker performs conservative pending-job deduplication:

- Immediately consecutive exact duplicate read-only commands may be coalesced.
  The command runs once and every waiting caller receives the same result
  through its own queued result file.
- With `enable_strong_dedup` enabled, exact duplicate global-refresh commands
  (`full --apply`, `documented --apply`, `autogen --apply`, or
  `rescore --apply`, without `--remove-missing`, `--uid-only`, or
  `--reference-only`) may be coalesced to the newest pending duplicate. Earlier
  callers receive the newest refresh result after intervening queued validator
  mutations have run. This is intended for agents that want the latest generated
  validation/report state rather than the report that would have existed at the
  older queue slot.
- In strong mode, if pending `file --apply` jobs are batched with pending
  global-refresh jobs, the worker runs the file jobs first in their queue order,
  then runs the global refresh. File jobs are not deduped.
- Other mutating commands, including `file --apply`, are not deduped. Their
  ordering and per-command output can matter, so each caller receives the result
  for its own queue position.

When `enable_dedup` is false, the worker returns to the original behavior and
claims one queued job at a time in queue order.

The queue frontend accepts these extra maintenance flags:

- --queue-status: show worker/queue/result counts without enqueueing a job.
- --start-worker: start the background worker if needed, then show status.
- --queue-timeout N: maximum seconds for the caller to wait for its result;
  -1 waits forever.
- --wait-generated: run generated CPP/H and generated Markdown refresh before the
  command returns instead of deferring it as lower-priority background work.
- --no-generated-refresh: skip generated CPP/H and generated Markdown refresh
  scheduling for this command.
- --background-direct: bypass the queue and run validator_background.py
  directly. Use only for debugging the validator itself.

UID References
--------------

References between by-* Markdown files should be authored with the target UID:

- [UID:000123] Optional context text.

When the validator scans a file, it expands references to other documents into
this generated form:

- [UID:000123][TargetFile](by-class/TargetFile.md) Optional context text.

If the second bracket already exists, the validator updates it when the target
filename or path changes. If a referenced UID is not present in validator.ini,
the scan reports missing_ref_uid. Run the validator on the target file first so
it receives a UID and validator.ini entry.

The validator also maintains a reverse-reference index in validator.ini
[references]. The keys are target UIDs and the values are semicolon-separated
source paths that reference the target. When a source file is scanned, its
outgoing UID references are re-read and stale reverse-reference entries for
that source are removed. Full and documented scans rebuild [references] from
the scanned files.

When a target file is renamed or moved and then scanned with the default file
mode, the validator updates the target UID path and uses [references] to update
known source files that still reference that UID. If a listed source file no
longer contains the UID reference, that stale reverse-reference entry is
removed instead. If a source file itself is renamed, scanning that source file
updates its source path in the reverse-reference lists. --uid-only intentionally
skips cross-reference propagation.

Temporary TMP References
------------------------

When a batch creates a new target document and needs to reference it before the
target has a UID, use this temporary authoring form:

[TMP:"by-memory/ExampleTarget.md"]

The quoted form is canonical. The path may be documentation-root relative,
source-file relative, workspace-relative with a source-3\project-documentation
prefix, or an absolute path under either the E:\NTK junction path or the
resolved C:\FastStorage path. The target must be a Markdown file under a direct
by-* folder.

During the reference phase, validator.py resolves each TMP path. If the target
file exists and does not yet have a UID, the validator assigns the target UID
first, records it in validator.ini, then replaces the TMP token in the source
file with the normal generated UID reference:

[UID:000123][ExampleTarget](by-memory/ExampleTarget.md)

This lets an agent create several new pages and write parent references in one
batch without manually validating each target before drafting the parent links.
Do not guess UIDs; use TMP only when the target path is known and the validator
can resolve the target file.

If the TMP path cannot be resolved, the validator leaves the TMP token in place,
records the source file and unresolved target path under validator.ini
[tmp_references], and reports tmp_ref_unresolved. Later validator runs recheck
stored TMP references. If the target path becomes valid, the validator assigns
or reads the target UID, replaces the TMP token, and removes the stored error.
If the TMP token is removed from the source manually, the stored error is also
cleared on a later scan.

--uid-only skips reference processing, so it will not resolve or replace TMP
tokens. Use normal file/full/documented scans, or --reference-only, when TMP
references should be resolved.

Validation Phases
-----------------

By default the validator runs both phases:

- UID phase: check/create the document metadata header and update validator.ini.
- Reference phase: expand/update [UID:...] target annotations.
- Autogen phase: refresh reconstruction metadata registry, generated CPP/H roots,
  and `auto-generated/-ag-*` coverage reports. In normal `--apply` file/full/
  documented scans this phase can be deferred until after the foreground scan
  result is returned unless `--wait-generated` is used.

Use --uid-only when only the metadata header and validator.ini mapping should be
checked or created. It skips references and generated autogen outputs. Use
--reference-only when only cross-reference annotations should be updated. It
skips UID/header mutation and generated autogen outputs.

Completion Stats
----------------

Full and documented scans update this generated report when --apply is used:

project-level\-auto-completion-stats.md

The report lists the configured number of lowest-scored items for
Low_Completion, Low_Confidence, and Low_Both, split into reconstructable and
not-reconstructable buckets. Each direct by-* folder is also split into the
same two buckets. Combined is the average of COMPLETION and CONFIDENCE.

The per-section counts are controlled by validator.ini `[settings]`:

stats_table_limit_reconstructable = 125
stats_table_limit_not_reconstructable = 34

`*_Reconstructable` sections include files whose `RECONSTRUCTABLE` metadata is
`true`. `*_Not_Reconstructable` sections include files whose `RECONSTRUCTABLE`
metadata is false, blank, or invalid, so incomplete metadata remains visible.

The same generated report also includes a `projected_path_completion` section.
That section lists every singular `by-file` page whose
`PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. It is a full list, not a
sample and is not capped by either stats table limit, so agents can work
through missing source placement assignments without needing a separate search.

Autogen coverage has moved to the `auto-generated/-ag-*` reports. Do not use
`project-level\-auto-completion-stats.md` as the source for generated CPP/H
assignment/coding state; use it for documentation scoring and missing by-file
projected paths.

Single-file scans do not rebuild the stats report. When --apply is used, a
single-file scan checks whether that file already appears in the generated
stats report and updates only those existing rows. Each affected list is
re-sorted using that list's score column. Each section checks against that
section's current lowest-position row. If the updated row scores lower priority
than that current lowest row, it is temporarily removed and the list is left
short; the validator does not refill it during single-file scans. If the
updated item was already the lowest-position row before the scan, any score
increase for that section also removes it.

Use rescore mode to regenerate the report from validator.ini without scanning
or editing Markdown files. Rescore should be done occasionally, or when enough
rows have dropped from the generated lists that the report is no longer useful.

Isolated File Scan
------------------

The isolated scan reports scoped by-* Markdown files that exist but are not
referenced by any other scoped by-* Markdown file through UID references.
Self-references do not count. The scan reads files directly and does not rely
on the stored [references] index, so it can be used as a registry hygiene check
after large documentation moves.

Files without a valid UID header are reported as isolated_no_uid because they
cannot be targeted by UID references until a UID/header scan is run.

The isolated scan is report-only. --apply is accepted but does not write files
or validator.ini.

Examples
--------

Dry-run all by-* Markdown files:

python validator.py --mode full

Apply UID headers and validator.ini mappings:

python validator.py --mode full --apply

Report UIDs that are listed in validator.ini but no longer exist in any
scanned by-* Markdown file:

python validator.py --mode full

Dry-run removal of missing validator.ini UID mappings:

python validator.py --mode full --remove-missing

Apply removal of missing validator.ini UID mappings:

python validator.py --mode full --remove-missing --apply

Dry-run a single by-* Markdown file:

python validator.py --mode file --file ..\by-memory\-guidance.md

Apply UID/header changes to a single by-* Markdown file:

python validator.py --mode file --file ..\by-memory\-guidance.md --apply

Apply UID-reference link generation after editing cross-references in one file:

python validator.py --mode file --file ..\by-memory\-guidance.md --apply

Only create/check the metadata header and validator.ini path mapping:

python validator.py --mode file --file ..\by-memory\-guidance.md --uid-only --apply

Only update [UID:...] reference annotations:

python validator.py --mode file --file ..\by-memory\-guidance.md --reference-only --apply

Scan files already listed in validator.ini:

python validator.py --mode documented

Apply documented scan path updates, including renamed files found by UID:

python validator.py --mode documented --apply

Regenerate completion/confidence statistics from validator.ini:

python validator.py --mode rescore --apply

Dry-run generated CPP/H and `-ag-*` reconstruction coverage reports:

python validator.py --mode autogen

Apply generated CPP/H source and `-ag-*` reconstruction coverage reports:

python validator.py --mode autogen --apply

Stage the one-time reconstruction-H metadata migration without changing live
by-* files. The command returns a migration ID and manifest path:

python validator.py --mode migrate-reconstruction-h

Review that manifest and verify `invalid: 0`, then apply that exact staged ID:

python validator.py --mode migrate-reconstruction-h --migration-id <id> --apply

Apply rechecks candidate scope plus live and staged SHA-256 values, creates a
dedicated migration backup, preserves newline/final-newline state, and aborts
on drift. Do not use broad `migrate-autogen` for this insertion and do not
hand-add the block project-wide.

Report files that have no inbound UID references from other by-* Markdown
files:

python validator.py --mode isolated

Equivalent shorthand:

python validator.py --isolated

Also accepted for compatibility with the requested spelling:

python validator.py -isolated

Dry-run removal of documented UIDs whose files cannot be found by UID:

python validator.py --mode documented --remove-missing

Apply removal of documented UIDs whose files cannot be found by UID:

python validator.py --mode documented --remove-missing --apply

Print existing OK rows too:

python validator.py --mode full --verbose

Show queue and worker state without adding a job:

python validator.py --queue-status

Start the background worker if needed:

python validator.py --start-worker

Wait at most 120 seconds for this queued command to finish:

python validator.py --queue-timeout 120 --mode file --file by-memory\-guidance.md

Run a file scan and wait for affected generated CPP/H and generated Markdown
reports before returning:

python validator.py --mode file --file by-memory\-guidance.md --apply --wait-generated

Debug only: bypass the queue and run validator_background.py directly. This
still uses validator.lock around the direct run:

python validator.py --background-direct --mode file --file by-memory\-guidance.md

Debug only: wait indefinitely for the direct validator lock:

python validator.py --background-direct --mode file --file by-memory\-guidance.md --apply --lock-timeout -1

Debug only: fail immediately if another direct validator process owns
validator.lock:

python validator.py --background-direct --mode full --lock-timeout 0

Legacy Link Conversion
----------------------

Report old Markdown links to by-* files that can be converted:

python find_legacy_references.py --limit 40

Create a converted test copy of one file under tools\legacy_test:

python find_legacy_references.py --test-file ..\by-memory\-coverage-report.md --limit 40

Convert all scoped by-* Markdown links in place. The command backs up changed
files under tools\legacy_backup\<timestamp> before writing:

python find_legacy_references.py --apply
