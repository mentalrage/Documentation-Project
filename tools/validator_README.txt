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
`--reference-only` is used. Use `--mode autogen` when only generated C++ and
autogen coverage reports should be rebuilt from already-scanned metadata.

When a by-folder Markdown file is removed, run the missing-entry cleanup:

python validator.py --mode documented --remove-missing --apply

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

Do not remove or rewrite validator-managed header lines. Edit only the intended
value field for each line:

- `COMPLETION` and `CONFIDENCE`: numeric value only.
- `PROPOSED_RECONSTRUCTION_PATH`: path inside quotes only.
- `RECONSTRUCTABLE`, `AUTOGEN_PARENT_UID`, and
  `AUTOGEN_PARENT_POSITION_OPTIONAL`: value after the colon only.
- `RECONSTRUCTION_CPP CODE:BEGIN/END`: C++ between the begin/end lines only.

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
enough detailed documentation for another agent to audit the page directly.

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
source module and is treated as a generated C++ root. Fill
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
   `projected_cpp_move_conflict`, or `projected_cpp_stale`.
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

When the path is valid, the validator creates an empty `.cpp` file under
`project-documentation/auto-generated` if one does not already exist. If the
proposed folder changes, or the by-file Markdown file is renamed, the validator
moves the existing generated `.cpp` file to the new location when there is no
target conflict. After a successful move, empty generated folders below
`auto-generated` are removed.

If a projected path is cleared, becomes invalid, or changes to `NONE`, the
validator does not delete the old generated `.cpp` file automatically. It
reports `projected_cpp_stale` so an agent can decide whether the staged file
should be moved, kept, or removed manually.

The projected-path line is intentionally only for direct singular `by-file`
pages. Do not add it to nested by-file support pages, `-xxx.md` control files,
classes, globals, memory ranges, functions, resources, meta pages, or other
folders. Those pages attach to a `by-file` UID through autogen metadata when
they need to contribute C++.

Reconstruction Autogen Metadata
-------------------------------

Eligible code-bearing documentation pages can contribute reconstructed C++ into
the staged files under `auto-generated/NexusTK`. This applies to singular item
pages such as `by-class`, `by-memory`, `by-global`, `by-function`, `by-item`,
and `by-type` pages.

The validator does not add reconstruction metadata to `by-file`, `by-meta`,
`by-external-research`, `by-project-structure`, `by-resource`, root-level docs,
tool docs, generated docs, or any `-xxx.md` support/control page.

Eligible pages receive these validator-managed lines after UID, COMPLETION, and
CONFIDENCE:

*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

`RECONSTRUCTABLE` accepts blank, `TRUE`, `1`, `FALSE`, and `0`. Blank means
unevaluated. `TRUE` or `1` means the page is confirmed NexusTK-owned source
that must be rebuilt. A reconstructable page may intentionally have no
`AUTOGEN_PARENT_UID` yet; the autogen reports list it as `unassigned` until a
parent relationship is proven well enough. Do not delay setting
`RECONSTRUCTABLE:TRUE` merely because final parent ownership or final C++ code
is not ready.

`AUTOGEN_PARENT_UID` must be an existing validator UID. Do not guess it. If the
parent page is new, validate the parent first or use the TMP reference workflow
elsewhere and come back after the UID exists. Parent chains should eventually
resolve to a singular `by-file` page with a valid `PROPOSED_RECONSTRUCTION_PATH`.
Only fill this when parent ownership is high-confidence enough to affect
generated source structure.

`AUTOGEN_PARENT_POSITION_OPTIONAL` is blank by default. A numeric value sorts
children under the same parent before blank-position children; ties use stable
UID allocation order.

Put real multiline C++ between the BEGIN and END lines only when the item,
parent, dependencies, and surrounding memory ranges meet the reconstruction
quality bar documented in `by-structure.md`. Code without a parent is invalid
because the validator has no safe generated destination. Do not use Markdown
fences inside this managed block. `[[CHILDREN]]` inside the C++ block is the
explicit insertion point for recursively assembled children. If the marker is
present but no child snippets are attached yet, generated output shows
`[[No Children Attached]]` at that point so the placeholder is easy to see. If
a class/struct snippet has children but no marker, the validator attempts a
conservative fallback before the final `};`. Function/method snippets require
the explicit marker before children are inserted inside them.

Autogen Output
--------------

`--mode autogen` rebuilds generated C++ and the `-ag-*` coverage reports from
the current validator registry and Markdown files without inserting missing
metadata into Markdown pages:

python validator.py --mode autogen
python validator.py --mode autogen --apply

Full, documented, and file scans also run autogen output generation unless
`--uid-only` or `--reference-only` is used.

Generated C++ is written only under `project-documentation\auto-generated` and
only to empty files or files already carrying the validator autogen sentinel.
Nonempty files without the sentinel are reported as conflicts and are not
overwritten.

Each assembled child snippet is preceded by a C++ comment identifying the
source documentation item:

// UID:000123 | by-memory/ExampleMethod.md

These comments are emitted at the actual insertion point, including nested
children, so generated files can be traced back to their source docs without
guessing which page contributed a class, method, global, or helper body.

Generated coverage reports live directly under `auto-generated`:

- `-ag-file-coverage.md`
- `-ag-class-coverage.md`
- `-ag-function-coverage.md`
- `-ag-global-coverage.md`
- `-ag-item-coverage.md`
- `-ag-memory-coverage.md`
- `-ag-type-coverage.md`

Each report includes `Total_Type`, `Total_Reconstructable`,
`Total_Not_Reconstructable`, `Total_Reconstructed_Assigned`,
`Total_Reconstructed_Coded`, `Total_Unclassified`, and `Total_Error`.

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
- Autogen phase: refresh reconstruction metadata registry, generated C++ roots,
  and `auto-generated/-ag-*` coverage reports.

Use --uid-only when only the metadata header and validator.ini mapping should be
checked or created. It skips references and generated autogen outputs. Use
--reference-only when only cross-reference annotations should be updated. It
skips UID/header mutation and generated autogen outputs.

Completion Stats
----------------

Full and documented scans update this generated report when --apply is used:

project-level\-auto-completion-stats.md

The report lists the 25 lowest-scored items for Low_Completion,
Low_Confidence, and Low_Both, then the 25 lowest combined-score items for each
direct by-* folder. Combined is the average of COMPLETION and CONFIDENCE.

The same generated report also includes a `projected_path_completion` section.
That section lists every singular `by-file` page whose
`PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. It is a full list, not a
25-item sample, so agents can work through missing source placement assignments
without needing a separate search.

Autogen coverage has moved to the `auto-generated/-ag-*` reports. Do not use
`project-level\-auto-completion-stats.md` as the source for generated C++
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

Dry-run generated C++ and `-ag-*` reconstruction coverage reports:

python validator.py --mode autogen

Apply generated C++ and `-ag-*` reconstruction coverage reports:

python validator.py --mode autogen --apply

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
