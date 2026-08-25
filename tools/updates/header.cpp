# Reconstruction Header Output Update Plan

## 1. Objective

Add a validator-managed `RECONSTRUCTION_H CODE` block to every reconstruction-eligible Markdown item that receives the existing `RECONSTRUCTION_CPP CODE` block. Header source entered in that block will be assembled through the same emitter graph as C++ source and written to a sibling `.h` file beside the matching generated `.cpp` under `project-documentation/auto-generated/NexusTK`.

This file is an implementation plan only. No live documentation migration or generated-source mutation is part of writing this plan.

## 2. Canonical Managed Block

The exact new block is:

```text
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

The normalized managed-header order is:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<existing C++ source, if any>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<header source, if any>
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
```

Placement requirements:

- Insert the H begin line immediately after the CPP end line, followed by the H end line.
- Preserve the complete CPP block byte-for-byte.
- Preserve all content that currently follows the CPP block, including blank lines, `Item Summary`, `Nested`, body text, tables, and report/history sections.
- `Item Summary` and `Nested` insertion logic must use the H end line as its preferred anchor after this feature is active. It may fall back to the CPP end line only while processing an unmigrated file.
- Do not add a legacy one-line H form. The H channel has only the multiline begin/end form.

In this plan, "all files" means every validator-managed reconstruction-eligible item page that already qualifies for the CPP block. It does not mean generated files, tool documentation, report files, `by-file`, excluded by-* folders, root Markdown files, or `-xxx.md` control files. Those files do not own a CPP block today, so adding an H block to them would violate the existing metadata scope.

## 3. Required Behavior And Invariants

### 3.1 Empty block

- Empty or whitespace-only H content is ignored as source.
- An empty H block creates no `.h` file.
- An empty H block does not make an item coded, filled, covered, or implemented.
- If a previously nonempty assembled header becomes empty, the validator removes the now-stale validator-owned generated `.h` file during the relevant generated refresh.
- Migrating all existing pages with empty H blocks must generate zero `.h` files.

### 3.2 Nonempty block

- Nonblank H source uses the page's existing `EMITTER_UIDS` route.
- The emitter graph and sibling ordering must be identical to the CPP graph and order.
- The generated destination is the matching generated CPP path with only the suffix changed to `.h`.
- Example: `auto-generated/NexusTK/app/Application.cpp` maps to `auto-generated/NexusTK/app/Application.h`.
- Header-only source is permitted when a valid route reaches a by-file source root even if the assembled CPP body is empty. The destination is still derived from that root's projected CPP path.
- Nonblank H source requires the same reconstructable and valid-emitter-route conditions as nonblank CPP source.
- Existing documentation quality gates apply equally to H source. Do not introduce a second or weaker quality standard.

### 3.3 Source separation

- CPP and H are independent channels. A page may contain CPP only, H only, both, or neither.
- H source must not be copied into the generated `.cpp`.
- CPP source must not be copied into the generated `.h`.
- The validator must not automatically add `#include "Name.h"` to generated CPP files.
- The validator must not invent declarations, include guards, `#pragma once`, includes, forward declarations, namespaces, or formatting. Generated H body content must be the assembled user-authored H source plus validator metadata/provenance only.
- Guidance must tell agents to provide any required guard/pragma/include source deliberately in the correct routed H content. Because multiple item fragments can assemble into one file, agents must avoid repeating root-level directives in child fragments.

### 3.4 `[[CHILDREN]]`

- Support `[[CHILDREN]]` independently in the H channel using the existing emitter semantics.
- A parent's H block can place assembled child H fragments at one explicit `[[CHILDREN]]` marker.
- When no marker is present, use the same deterministic child fallback order as CPP assembly and issue an H-specific warning when the existing CPP logic would warn.
- More than one `[[CHILDREN]]` marker in one H block is an error, not an invitation to duplicate declarations.
- A CPP marker affects only CPP children; an H marker affects only H children.

### 3.5 Imports

- Version 1 does not add `<import-from-start>...` support to the H block.
- The existing CPP inline import directive remains unchanged and backward compatible.
- H source is literal multiline source between its managed begin/end lines.
- If H import support is desired later, implement it as a separately specified extension rather than silently sharing the CPP inline parser.

### 3.6 Generated ownership and freshness

- Generated `.h` files are validator-owned exactly like generated `.cpp` files.
- Every generated H file receives the generated-file sentinel and the three validator freshness comments: command ID, refreshed timestamp, and refresh source.
- A command that targets an affected source page refreshes only the affected generated roots. It must not refresh unrelated H or CPP headers.
- A targeted scan refreshes the generated root reached from the targeted page even when that page's source text is unchanged, matching the existing command-freshness contract. It still must not refresh unrelated roots.
- A full project scan targets all generated roots and can refresh all generated H and CPP metadata.
- Corrupt, manually edited, or malformed generated H files are rebuilt automatically from documentation source. They are not treated as manually owned conflicts.
- Existing once-per-day autogen backup throttling remains unchanged. This feature must not rewrite or reuse the daily backup directory during the same day.

## 4. Validator Code Changes

### 4.1 `source-3/project-documentation/tools/validator_background.py`

#### A. Marker constants and recognition

Add constants beside the current CPP constants:

- `RECONSTRUCTION_H_PREFIX`
- `RECONSTRUCTION_H_BEGIN_LINE`
- `RECONSTRUCTION_H_END_LINE`

Extend the functions that identify managed reconstruction metadata so the H prefix is recognized on eligible pages and rejected on ineligible pages. This includes the current prefix checks used by `has_autogen_metadata_line`, `has_reconstruction_metadata_line`, metadata-order validation, and unexpected-metadata reporting.

Do not use a first-N-lines optimization for H extraction. The CPP body may be long, so the H block can be far below the top of the file.

#### B. Managed metadata insertion

Extend `ensure_autogen_metadata_lines()` after it has found or normalized the CPP block:

1. Find the one exact CPP end marker.
2. If no H markers exist, insert the exact empty H block immediately after CPP end.
3. If one valid H begin/end pair exists in the required order, preserve its body unchanged.
4. If H markers are duplicated, reversed, nested, or only one marker exists, return a specific validation error and do not perform a destructive repair that could absorb body text into the source block.
5. Keep the operation idempotent: rescanning a valid page must produce no textual change.

Use specific actions such as:

- `reconstruction_h_insert`
- `reconstruction_h_invalid`
- `reconstruction_h_noop`

Do not reuse a generic CPP repair action because command output and tests must identify which channel changed.

#### C. Summary/nesting anchor

Update `ensure_memory_coverage_metadata_lines()` and any equivalent post-reconstruction insertion code:

- Prefer the exact H end marker as the end of managed reconstruction source metadata.
- Fall back to CPP end only for an unmigrated page in a dry run or interrupted rollout.
- Never blank, replace, regenerate, or move a nonblank `Item Summary`.
- Preserve the current rule that validator-generated `Nested` starts at `0`.

Add a regression test proving that adding the H block does not alter either line or the surrounding body.

#### D. Parsing

Refactor the current `extract_reconstruction_code(lines)` behavior into a shared exact-block extractor plus channel-specific wrappers, or add a parallel `extract_reconstruction_header_code(lines)` that uses the same strict structural checks.

The H parser must:

- Require exactly one begin and one end marker on eligible migrated pages.
- Treat both H markers being absent as an empty pre-migration channel so autogen-only/read-only commands remain backward compatible during rollout. An ordinary applying scan inserts the missing block; one marker without the other is always malformed.
- Require begin before end.
- Return the raw text between markers without Markdown fence stripping or content rewriting.
- Treat whitespace-only source as empty.
- Reject exact marker lines appearing inside the body because they make the managed boundaries ambiguous.
- Report errors using H-specific error names and line numbers.
- Never interpret the old inline CPP field as H source.

#### E. Metadata model and cache

Extend `AutogenMetadata` with fields equivalent to:

- `header_code`
- `header_code_mode`
- `header_code_hash`

No H import-path field is needed in version 1.

Update `parse_autogen_metadata()` so one file read/split populates both CPP and H channels. Do not reread the Markdown file for H parsing.

Extend metadata cache serialization/deserialization for the new fields. Bump `CACHE_VERSION` from `metadata-cache-v5` to `metadata-cache-v6`. If another update changes the cache version before implementation, use the next unused version instead. Old cache records must be discarded normally, not partially interpreted.

Add validator.ini registry sections parallel to the current CPP sections:

- `[reconstruction_h_code_hash]`
- `[reconstruction_h_code_mode]`

The validator owns these sections. Agents must never edit them manually.

#### F. Validation and route rules

Extend `update_autogen_registry_for_metadata()` and related scan validation:

- Nonblank H with `RECONSTRUCTABLE` other than true is an error.
- Nonblank H with blank `EMITTER_UIDS` is an `emitter_header_without_route` error.
- A nonblank H route that cannot reach an active by-file generated source root is reported as an H dead end in autogen diagnostics.
- Empty H does not introduce route errors.
- Existing CPP validation and error names remain unchanged.

Do not add expensive second graph traversals per page. Parse all metadata once, construct one emitter graph, and calculate both channels during one traversal.

#### G. Assembly

Refactor `assemble_autogen_node()` and `assemble_autogen_root()` to assemble a pair of channels in one graph walk. A suitable internal result contains:

- assembled CPP text
- assembled H text
- CPP contributing UIDs
- H contributing UIDs
- channel-specific warnings/errors

Requirements:

- Preserve current CPP output byte-for-byte when all H blocks are empty.
- Reuse the same ordered child list for both channels.
- Keep cycle detection and visited-state behavior shared.
- Apply `[[CHILDREN]]` separately to each channel.
- Emit H provenance comments for each contributing UID in the same deterministic style as CPP provenance.
- Do not concatenate an empty fragment just to make a header appear nonempty.

#### H. Generated content

Add `generated_header_content()` parallel to `generated_cpp_content()`. It must emit:

1. The validator-owned generated sentinel.
2. `// validator-command-id: ...`
3. `// validator-refreshed-at: ...`
4. `// validator-refresh-source: ...`
5. Source-root UID and by-file documentation provenance.
6. The assembled H source.

Do not add a generated timestamp outside the command metadata, because timestamp-only content changes cause unnecessary writes.

#### I. Generated paths and projected-path moves

Replace CPP-only path assumptions with a suffix-restricted generated-source helper, for example `generated_source_path(..., suffix)`, accepting only `.cpp` and `.h`.

Update `sync_generated_cpp()` or rename it to `sync_generated_sources()` and handle a root as a pair:

- Continue creating the existing empty CPP placeholder when a valid by-file projected path establishes a root.
- Never create an empty H placeholder.
- When a projected path changes, preflight old/new CPP and H paths together.
- If either destination is claimed by a different active generated root, move neither member of the pair and report both paths clearly. A corrupt or manually altered file at the destination is still validator-owned and is rebuilt when no different active root claims that path.
- Move the H file only when it exists.
- Keep source and destination resolution confined to `auto-generated/NexusTK`.
- Preserve case-only rename handling on Windows.

#### J. Generated writes and cleanup

Extend `run_autogen_generation()` so each active root can enqueue one CPP write and, only when assembled H is nonblank, one H write.

Use the existing generated write batch, process lock, same-path de-duplication, atomic replace, and bounded parallel writer. Do not add a second serial write pass for H files.

Generalize `cleanup_stale_nexustk_generated_cpp()` to clean validator-owned generated sources:

- Scan both `*.cpp` and `*.h` under `auto-generated/NexusTK`.
- Retain only paths expected from the current active-root set.
- Delete an H file when its root remains active but assembled H is now empty.
- Delete both suffixes when a root is removed or rerouted.
- Rebuild expected H files whose sentinel/body is corrupt.
- Never scan outside the generated NexusTK subtree.

Use bounded actions such as:

- `autogen_header_create`
- `autogen_header_update`
- `autogen_header_noop`
- `autogen_header_stale_delete`
- `autogen_header_rebuild`
- `projected_header_move`
- `projected_header_conflict`

Normal command-line output should summarize counts and show detailed paths only for errors/conflicts or an explicitly verbose mode.

### 4.2 `source-3/project-documentation/tools/validator.py`

Add the dedicated migration mode and forward its options to the background implementation:

- `--mode migrate-reconstruction-h`
- `--migration-id <id>` for applying a previously staged migration

Keep dry run as the default. Require `--apply` plus an exact migration ID for live mutation.

Add the new mode to aliases, argument choices, help text, dispatch, foreground/background eligibility, and command result formatting. Migration output must include the normal validator command ID/timestamp plus the migration ID, manifest path, eligible count, changed count, invalid count, and apply status.

Do not queue a bulk metadata migration as an ordinary background generated refresh. The migration must finish and verify source-page writes before any generated refresh is allowed to run.

### 4.3 `source-3/project-documentation/tools/memory_ranges.py`

Keep existing implementation-code coverage semantics CPP-only. Header declarations must not make a range count as having reconstructed implementation code.

Add exact H marker parsing using the already-read page text and expose separate byte/count metrics:

- `has reconstruction header code`
- `no reconstruction header code yet`

Do not merge these values into the existing `has reconstruction code` / `no reconstruction code yet` calculations. This preserves historical comparison and prevents declaration-only pages from appearing implemented.

Malformed H markers should be reported as page metadata errors, while an empty valid H block simply counts as no header code.

### 4.4 Generated report model

Extend `AutogenReportEntry` with `has_header_code` and, where needed, the generated H destination.

For validator-generated reconstruction coverage tables:

- Keep the existing `Code` column and all existing coded/empty-emitter totals CPP-only.
- Add a separate `Header Code` yes/no column.
- Add `Header Destination` only where the table already shows generated source destinations.
- Add `Total_Reconstructed_Header_Coded` as a separate total.
- Keep `Total_Reconstructable_Emitters_NoCode` based on CPP implementation code so the meaning does not change.
- Do not alter B-agent report coverage, additional-target coverage, or `-ag-research-tracker.md` covered/not-covered semantics as part of this feature.

This separation is required to avoid treating a declaration as a completed implementation.

## 5. One-Time Existing-File Migration

Do not use the broad legacy `migrate-autogen` apply path. It can normalize unrelated metadata and would make it harder to prove that only the two requested H lines changed.

Implement a dedicated migration with the following behavior.

### 5.1 Dry-run staging

Command shape:

```powershell
python .\tools\validator.py --mode migrate-reconstruction-h
```

The dry run must:

1. Acquire the validator process lock.
2. Enumerate only current reconstruction-eligible pages using the same eligibility function as normal scans.
3. Require exactly one valid CPP begin/end pair in each candidate.
4. Classify valid existing H blocks as already migrated.
5. Reject malformed/partial/duplicate H markers.
6. Build each changed file by inserting only the two exact H marker lines immediately after CPP end.
7. Write staged copies under `tools/validator_migrations/reconstruction_h/<migration-id>/files/...`, never beside live Markdown files.
8. Write a machine-readable manifest containing:
   - migration ID and creation timestamp
   - project root and validator version/cache version
   - relative path for every candidate
   - before SHA-256, byte length, newline style, and final-newline state
   - after SHA-256 and staged artifact path
   - CPP/H marker counts and insertion byte/line offset
   - classification: changed, already valid, or invalid
9. Make no changes to live by-* pages, validator.ini, auto-generated files, command cache, or daily autogen backups.

The dry run fails if any candidate cannot be read, any relative path is duplicated, a block is malformed, or a staged artifact cannot be verified.

### 5.2 Apply

Command shape:

```powershell
python .\tools\validator.py --mode migrate-reconstruction-h --migration-id <id> --apply
```

Before writing anything, apply must:

1. Reload the named manifest.
2. Verify every live candidate's current SHA-256 still matches its manifest before hash.
3. Verify every staged artifact still matches its manifest after hash.
4. Re-run scope, marker-count, path-containment, and exact-diff checks.
5. Abort the entire apply before mutation if any file drifted or any check fails.

Apply safety:

- Create one dedicated migration backup at `tools/validator_migrations/reconstruction_h/<migration-id>/backup/...` before replacing any source page.
- This is a source-document migration backup, not another autogen backup; do not bypass or modify the existing once-per-day autogen backup policy.
- Use same-directory temporary files and atomic replace for each live page.
- Maintain an apply journal. If a write fails, restore every page already changed from the migration backup before returning failure.
- A resumed apply must be idempotent: pages matching the after hash are accepted; pages matching neither before nor after abort.
- Record completion in the manifest/journal so the same migration ID cannot be applied as a new migration later.

### 5.3 Exact no-damage proof

For every changed staged/live page, the migration verifier must remove the exact inserted H begin/end lines from the result and prove the remaining bytes equal the original bytes exactly. This catches newline conversion, final-newline changes, summary blanking, body rewriting, encoding changes, and unrelated metadata normalization.

The manifest must record the complete inserted byte span, including only the newline separators required to place the two lines. The inverse proof removes that recorded span, not a broad textual match. This keeps the proof valid when CPP end was originally the final line with no trailing newline.

The migration must preserve each file's encoding/newline style. If an encoding cannot be round-tripped exactly, classify the file as invalid and stop before live apply.

### 5.4 Normal post-migration behavior

After rollout, ordinary targeted and full scans add a missing empty H block to any newly created or genuinely unmigrated eligible page. They must not perform a second project-wide migration automatically.

## 6. Tests Required Before Live Data

Add a dedicated standard-library test module:

`source-3/project-documentation/tools/tests/test_validator_reconstruction_h.py`

All tests must use temporary fixture roots or copied snapshots. They must not point writes at the live by-* registry, live validator.ini, or live `auto-generated/NexusTK`.

### 6.1 Marker and insertion tests

- Missing H block is inserted immediately after CPP end.
- Existing valid empty H block is unchanged.
- Existing nonempty H body is unchanged.
- CPP body remains byte-identical.
- Content after CPP, including `Item Summary`, `Nested`, and arbitrary Markdown, remains byte-identical.
- LF, CRLF, UTF-8 BOM if supported by current reader, with-final-newline, and without-final-newline fixtures are preserved.
- A second scan is byte-identical/idempotent.
- Ineligible and `-xxx.md` files do not receive H metadata.
- Missing begin, missing end, duplicate begin/end, reversed markers, and nested marker-like lines fail closed without mutation.

### 6.2 Parser and cache tests

- Empty and whitespace-only H bodies parse as no header source.
- Nonblank multiline H body round-trips exactly.
- CPP and H bodies are parsed from one read and remain independent.
- H does not accept a legacy inline CPP value or import directive mode.
- One H `[[CHILDREN]]` marker is accepted; duplicates are rejected.
- Cache serialization/deserialization retains H mode/hash/body metadata.
- Cache v5 entries are invalidated after the v6 bump.
- Editing only H changes only the H source hash and affected generated H output.

### 6.3 Assembly tests

- H fragments use the same emitter graph and deterministic order as CPP fragments.
- Parent and child H fragments assemble correctly with and without `[[CHILDREN]]`.
- Multiple emitters route one H fragment to each intended root once.
- Cycles and dead ends produce channel-specific diagnostics without duplicate graph work.
- H-only routed content generates a sibling H file.
- Empty H on all contributors produces no H file.
- Clearing the last nonblank contributor removes the old H file.
- All-empty H fixtures leave generated CPP body bytes unchanged.

### 6.4 Generated-file lifecycle tests

- Create, update, no-op metadata refresh, corruption rebuild, and stale delete for H.
- Generated H contains the sentinel and exact command metadata.
- Targeted refresh changes only the affected H/CPP pair's command metadata.
- Full refresh can update all targeted generated pairs.
- Projected-path move handles CPP/H as one preflighted pair.
- H destination conflict prevents both moves.
- No empty H placeholder is created when a by-file projected path is registered.
- Same-path generated-write de-duplication rejects duplicate H writes without creating a partial file.
- Backup logic still creates at most one autogen backup per day and does not rewrite that day's backup.

### 6.5 Migration tests

- Dry run writes only staging files and a manifest.
- Dry run stages exactly the two marker lines for valid unmigrated fixtures.
- Applying without a migration ID is rejected.
- Source hash drift after dry run aborts before any write.
- Staged artifact drift aborts before any write.
- Apply creates a complete migration backup.
- Simulated mid-apply failure restores already-written files.
- Reapplying a completed migration is a no-op/rejected as already complete.
- The exact no-damage proof succeeds for every fixture.
- Empty migrated blocks produce no generated H files.

### 6.6 Regression suite

Run at minimum:

```powershell
python -m py_compile .\tools\validator.py .\tools\validator_background.py .\tools\memory_ranges.py .\tools\unresolved.py
python -m unittest discover -s .\tools\tests -p "test_*.py"
```

Also verify:

- Existing CPP-only autogen fixtures are byte-equivalent when every H block is empty.
- Existing additional-target report coverage tests remain unchanged.
- Existing research-tracker counts remain unchanged.
- Existing `memory_ranges.py` implementation-code totals remain unchanged; only separate H metrics are added.
- Existing generated write collision, locking, path containment, and stale-cleanup tests still pass.
- A self-contained synthetic generated H/CPP pair passes the repository's configured C++ syntax/compile smoke check when that compiler is available. This validates wrapper/provenance placement without requiring live reconstructed source to compile as a complete project.

## 7. Pre-Live Integration Gate

The live migration is forbidden until all of these stages pass in order:

1. Python compilation checks pass.
2. Full isolated unit/regression suite passes.
3. A representative temporary fixture tree passes targeted file, directory, full, and autogen dry/apply cycles.
4. A copied snapshot of the live documentation tree passes the dedicated migration dry run and apply.
5. The copied snapshot passes a full validator/autogen apply.
6. Removing the inserted H blocks from every migrated snapshot file reproduces every original SHA-256.
7. Generated CPP bodies from before and after the snapshot migration are identical except for command freshness metadata that the test intentionally refreshes.
8. The snapshot creates zero generated H files while all migrated H blocks are empty.
9. Generated report CPP coverage totals and research coverage totals are unchanged.

Any failure blocks live rollout. Fix code/tests and restart this gate from step 1.

## 8. Live Rollout Procedure

Only after Section 7 passes:

1. Ensure no validator migration is active and the background worker is running the new code. Restart the persistent worker if necessary so it cannot execute an older loaded module.
2. Run the dedicated live migration dry run only.
3. Review its manifest and summary. The eligible count is expected to be near the audit snapshot of 5,922 pages, but the current enumerated count is authoritative because agents can add pages.
4. Require zero invalid/malformed candidates.
5. Programmatically verify every staged diff is only the two exact H marker lines after CPP end.
6. Spot-check representative `by-memory`, `by-class`, `by-global`, `by-item`, and `by-type` pages, including pages with long CPP blocks and nonblank summaries.
7. Apply the exact reviewed migration ID.
8. Verify the apply journal and every after hash.
9. Run a full documented validator scan and wait for its generated refresh command ID to finish.
10. Run/confirm autogen apply. It must create no H files because the migrated blocks are empty.
11. Verify every eligible page has exactly one valid H block directly after CPP and every ineligible page has none.
12. Verify current generated CPP bodies and all existing report coverage semantics remain unchanged.
13. Retain the migration manifest, journal, and source backup until the update has completed an agreed observation period.

Only after these checks may agents begin entering nonblank `RECONSTRUCTION_H CODE` content.

## 9. Documentation And Skill Updates

Update durable guidance only. Do not rewrite historical executed reports, old update plans, audit logs, or completed agent notes merely because they mention CPP-only behavior.

### 9.1 `source-3/project-documentation/tools/validator_README.txt`

Update these exact subject areas:

- Managed reconstruction metadata example near the current `RECONSTRUCTION_CPP CODE:BEGIN/END` description: add the canonical H block and immediate placement rule.
- Reconstruction routing section: explain that CPP and H share `EMITTER_UIDS` but assemble independently.
- Code-entry rules: state that empty H is ignored and nonblank H follows the same reconstructable, route, evidence, and score gates.
- `[[CHILDREN]]` section: document independent CPP and H insertion points.
- Third-party import section: state explicitly that version 1 imports remain CPP-only.
- Projected path section: document sibling `.h` destination and pairwise move behavior.
- Generated ownership/corruption section: state that generated H is validator-owned and automatically rebuilt.
- Generated freshness section: show the three H comment headers and targeted/full refresh semantics.
- Autogen/report section: document `Header Code`, header destination, and header-coded totals without redefining CPP coverage.
- Command reference: add dry-run/apply examples for `migrate-reconstruction-h` and the required migration ID.
- Troubleshooting: add malformed H marker, no route, dead-end route, stale H deletion, and path-conflict guidance.

### 9.2 `source-3/project-documentation/by-structure.md`

Update the current reconstruction policy around the paragraphs that define `RECONSTRUCTION_CPP CODE`, `EMITTER_UIDS`, the combined score gate, own-range restrictions, and autogen behavior:

- Add `RECONSTRUCTION_H CODE` to eligible code-bearing metadata.
- Preserve the existing exclusion list, including `by-file`.
- Define H as declarations/header source and CPP as implementation/source-definition output.
- Apply the same own-range and no-speculation rules to H content.
- Require exact formal-block insertion for any proposed header source, just as CPP source must use its formal block.
- Explain that declaration-only H content does not count as completed implementation.
- Explain independent `[[CHILDREN]]` placement and shared emitter routing.
- State that validator does not invent guards/includes or automatically include H from CPP.
- Update autogen text from generated C++ only to generated CPP/H source while preserving CPP-specific coverage language where appropriate.

### 9.3 `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`

Update the first-draft source and implementation callback rules:

- Agents must decide CPP and H disposition separately for every source recommendation.
- Header declarations/source must be entered in or supplied as exact insertion text for the formal H block, not left only in prose or a fenced example.
- Empty H is the correct result when no evidence-backed header source is ready.
- Do not duplicate the same declaration in CPP and H without a source-accurate reason.
- Generated H must be checked with command-ID freshness the same way generated CPP is checked.
- Agents must never edit generated H directly.

### 9.4 Skill reference files

Update these exact files and topics:

- `.codex/skills/ntk-b-agent-workflow/references/b-agent-report-template.md`
  - In `First-Draft C++ Recommendation`, require separate `CPP block disposition` and `H block disposition` entries.
  - In the implementation checklist, add exact target/support H insertion and generated H verification items.
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - Add declaration/include/source-order analysis to target research.
  - Add independent CPP/H callback application and verification.
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-b-report-validation-preflight.md`
  - Add a gate checking that recommended declarations use the H block, marker placement is exact, and H content does not overclaim outside ranges.
  - Require supervisors to reject duplicate or speculative declarations.
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
  - Extend no-loss review to both source channels.
  - Require readback of generated H freshness/provenance when H content was accepted.
  - Keep generated outputs read-only to agents and supervisors.

### 9.5 Supervisor and project guidance

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - Add CPP/H-separated report review, callback, and claim-by-claim verification.
  - Require validation of both affected generated outputs before report execution is considered complete.
- `.codex/AGENTS.md`
  - Add a concise project-wide rule identifying the H block, validator ownership of generated H, and the requirement to use the B-agent workflow for detailed source-quality rules.

### 9.6 Memory-range documentation

- `source-3/project-documentation/tools/memory_ranges_README.md`
  - Extend `Reconstruction Metadata Read By This Tool` with the H block.
  - Clarify that existing reconstruction-code/emitted-C++ metrics remain implementation/CPP metrics.
  - Document the separate header-code metrics and why declaration-only content does not satisfy implementation coverage.

## 10. Performance Requirements

- Read each Markdown page once per scan and parse CPP/H from the same `splitlines` result.
- Hash H source during existing metadata parsing; do not reopen files to hash it.
- Build the emitter graph once and assemble both channels in one traversal.
- Reuse the existing affected-root calculation for targeted generated refreshes.
- Enqueue CPP and H writes in one de-duplicated generated-write batch.
- Skip H rendering and filesystem writes completely when assembled H is empty and no stale H exists.
- Use cached H mode/hash to avoid unnecessary assembly/write work on unaffected roots.
- Preserve bounded parallel writes only after graph assembly; do not parallelize shared-state `scan_file()` mutations.
- Do not update generated H timestamps when a command did not target that root.
- Keep normal CLI output count-based and bounded.

## 11. Acceptance Criteria

The update is complete only when all statements below are true:

- Every reconstruction-eligible page has exactly one valid H block immediately after its CPP block.
- No excluded/ineligible page receives H metadata.
- Existing CPP bodies, summaries, nesting values, documentation bodies, and report history are not changed by migration.
- Empty H blocks generate no H files and do not alter coverage.
- Nonempty H blocks generate the correct sibling H files through the existing emitter route.
- CPP and H `[[CHILDREN]]` placement is independent and deterministic.
- Clearing H source removes the corresponding stale generated H.
- Projected-path changes move existing CPP/H output safely as a pair without creating empty H placeholders.
- Generated H files contain validator ownership/provenance/freshness metadata and are rebuilt on corruption.
- Targeted commands refresh only affected generated roots; full scans refresh all targeted roots.
- Existing CPP code coverage and B-agent research coverage semantics do not change.
- Separate H status appears in relevant reconstruction reports and memory-range metrics.
- Metadata cache and validator.ini track H state without extra file reads.
- Dedicated migration dry run, snapshot apply, regression suite, and exact byte-preservation proof pass before live apply.
- All durable validator, structure, skill, agent, supervisor, and memory-range guidance is updated before agents are permitted to author H content.

## 12. Rollback

If live verification fails:

1. Stop/restart the validator worker so no stale generated task is still running.
2. Restore migrated Markdown pages from the named migration backup and verify original hashes.
3. Remove only validator-owned generated `.h` files created by this feature.
4. Restore validator.ini from its normal protected state or rebuild the new H registry sections from restored docs; do not hand-edit individual entries.
5. Run the previous known-good validator/autogen version and verify generated CPP/report continuity.
6. Preserve the failed manifest, journal, command ID, and diagnostics for correction.

Do not roll back by running a broad text replacement over live Markdown files. The migration backup and manifest are the authoritative reversal path.

## 13. Recommended Implementation Order

1. Add constants, strict H parser, metadata fields, cache/config support, and unit tests.
2. Add managed insertion plus summary/nesting anchor changes and byte-preservation tests.
3. Refactor assembly to dual channels while proving CPP-only output equivalence.
4. Add generated H content, writes, cleanup, corruption rebuild, and projected-path pair handling.
5. Add separate autogen and memory-range H reporting.
6. Add the dedicated staged migration mode and failure/rollback tests.
7. Update all durable documentation and skills listed in Section 9.
8. Run the complete isolated and copied-snapshot gate in Sections 6 and 7.
9. Perform the reviewed live migration and post-apply verification in Section 8.

This order keeps the live corpus untouched until parsing, generation, lifecycle handling, rollback, and no-damage verification are all proven together.
