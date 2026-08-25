# Validator Reconstruction Autogen Update Plan

Status note, 2026-06-13: this is a historical pre-migration planning document.
It describes the old combined `AUTOGEN_PARENT_UID` /
`AUTOGEN_PARENT_POSITION_OPTIONAL` model and should not be used as current
operator guidance. The active validator metadata model uses:

- `CANONICAL_OWNER` for documentation ownership only.
- `EMITTER_UIDS` for generated-output routing.
- `EMITTER_POSITION_OPTIONAL` for emitter ordering.

When reading older examples in this file, interpret `AUTOGEN_PARENT_UID` as the
previous single field that combined ownership and emission. Current usage is
documented in `validator_README.txt`, `memory_ranges_README.md`, and
`tool-updates.md`.

This plan covers a future validator update that will let normal reconstruction documentation pages contribute C++ snippets into the staged files under `project-documentation/auto-generated`.

The current validator already owns UID headers, completion/confidence headers, UID references, TMP references, queued execution, by-file projected output paths, and completion stats. This update should build on that structure instead of adding a second registry.

## Goals

- Add reconstruction metadata to eligible documentation pages that may contain C++ code to rebuild.
- Keep `by-file` pages as generated source-file roots using their existing `PROPOSED_RECONSTRUCTION_PATH` line.
- Let non-`by-file` reconstruction pages attach to a parent UID such as a source file, class, type, or other containing item.
- Generate draft `.cpp` files under `auto-generated` by recursively assembling attached children.
- Generate auto-coverage reports for files, globals, memory ranges, and other reconstructable item categories.
- Preserve the validator queue/single-writer model so parallel agent calls remain safe.

## Requested Contract To Preserve

The user-facing tags should preserve the requested spelling and intent, even if the internal implementation normalizes values:

```text
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Contract notes:

- Use `RECONSTRUCTABLE`, matching the user's spelling. Do not silently switch the visible tag to `RECONSTRUCTIBLE`.
- Use `RECONSTRUCTION_CPP CODE` with a space in the visible tag because that is the requested format.
- Internal code may use safer Python names such as `reconstruction_cpp_code`, but it should read and write the requested visible tag.
- The default visible values should be blank, not `FALSE`, so unevaluated pages remain distinct from reviewed non-reconstructable pages.
- Do not guess `AUTOGEN_PARENT_UID`. The parent must already have a validator UID. If the parent is new, validate the parent first or leave the autogen parent blank until its UID exists.

## Scope Rules

Eligible pages:

- Direct or nested `by-*` Markdown files that represent singular reconstruction items.
- Examples: `by-class/Foo.md`, `by-memory/0x...FooMethod.md`, `by-global/g_Foo.md`, `by-function/Foo.Bar.md`, and `by-type/by-struct/FooState.md` when the page can provide source declarations or code.

Excluded pages:

- `by-file/*.md`; these are source-file roots and already use `PROPOSED_RECONSTRUCTION_PATH`.
- Any filename beginning with `-`, such as `-guidance.md`, `-coverage-report.md`, `-ignored.md`, generated reports, and rolling ledgers.
- `by-meta`, `by-external-research`, `by-project-structure`, and `by-resource` by default because these folders do not exclusively cover program code that should be assembled into generated C++.
- Root-level docs, `tools/*`, and `auto-generated/*`.

Header placement:

- For eligible non-`by-file` pages, insert reconstruction metadata after UID/completion/confidence and before the blank line that separates metadata from body content.
- For `by-file` pages, keep only the existing `PROPOSED_RECONSTRUCTION_PATH` line after confidence; do not add reconstruction child metadata.
- For support pages excluded by filename or folder, do not add reconstruction metadata during ordinary scans.

## Proposed Metadata Lines

Add these lines after the existing UID/completion/confidence metadata block for eligible pages:

```text
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Accepted `RECONSTRUCTABLE` values:

- blank: unevaluated for autogen.
- `TRUE` or `1`: source code/declaration should be reconstructed and assembled.
- `FALSE` or `0`: not reconstructable as source code for autogen purposes.

Accepted `AUTOGEN_PARENT_UID` value:

- blank when `RECONSTRUCTABLE` is blank or false.
- six-character UID when `RECONSTRUCTABLE` is true.
- Parent UID must exist in validator.ini and must eventually resolve to a `by-file` root through the parent chain.

Accepted `AUTOGEN_PARENT_POSITION_OPTIONAL` value:

- blank for default ordering after positioned children.
- integer value for explicit ordering under the parent.
- If two children share the same integer, keep stable first-registered order.

### Exact Header Grammar

Recommended regex-level grammar:

```text
RECONSTRUCTABLE line:
^\*\*\* RECONSTRUCTABLE:(?P<value>TRUE|1|FALSE|0|)? \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$

AUTOGEN_PARENT_UID line:
^\*\*\* AUTOGEN_PARENT_UID:(?P<value>[A-Z0-9]{6}|)? \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$

AUTOGEN_PARENT_POSITION_OPTIONAL line:
^\*\*\* AUTOGEN_PARENT_POSITION_OPTIONAL:(?P<value>[0-9]+|)? \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$

RECONSTRUCTION_CPP CODE line:
^\*\*\* RECONSTRUCTION_CPP CODE:\[\[\[(?P<value>.*)\]\]\] \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$
```

Parsing notes:

- Strip surrounding whitespace from editable values before validation.
- Store normalized boolean state as `blank`, `true`, `false`, or `invalid`.
- Store the original raw value for error messages.
- Do not allow hidden multiline continuation in the header parser; multiline C++ needs a separate block strategy.

### Important Code-Storage Concern

The requested `RECONSTRUCTION_CPP CODE:[[[]]]` line is useful as a compact status/tag line, but a single metadata line is not a good container for real C++ because reconstructed code will be multiline and may contain brackets, pipes, quotes, Markdown fences, comments, and validator-looking text.

Recommended implementation:

1. Keep the requested top metadata line as the required marker.
2. Store actual C++ in a managed block immediately below the metadata header:

```
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
<raw C++ reconstruction snippet here>
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

3. Treat `*** RECONSTRUCTION_CPP CODE:[[[]]] ... ***` as an empty inline placeholder for pages with no code yet.
4. If exact one-line storage is mandatory later, require escaping or base64; do not silently try to parse arbitrary multiline C++ from one header line.

Default implementation decision: implement the requested top metadata line as the required marker, and use the begin/end block as the canonical storage for real multiline C++ snippets. The inline triple-bracket value can remain empty or hold a short one-line snippet, but multiline C++ should use the block form to avoid ambiguous parsing.

### Exact Header And Code Block Layout

For eligible pages, the validator-managed top region should be ordered exactly like this:

```text
*** UID:000123 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Page Title
```

Layout rules:

- The four requested metadata lines are part of the metadata header.
- The optional begin/end block belongs immediately after the requested `RECONSTRUCTION_CPP CODE:[[[]]]` line and before the blank line that separates metadata from page body.
- When the code block is empty, keep adjacent BEGIN and END lines as shown above.
- When the code block has content, raw C++ lines go between BEGIN and END with no Markdown code fence.
- Do not put Markdown headings, prose, or fenced code inside the managed begin/end block.
- Existing page body content starts after the single blank line following the managed region.
- If an existing page already has body content immediately after the metadata, insert the new reconstruction metadata and empty begin/end block above the first body line, then preserve the body unchanged.

Parser failure rules:

- If BEGIN exists without END, report `autogen_code_block_unclosed` and do not assemble code from that page.
- If END exists without BEGIN, report `autogen_code_block_unmatched` and do not assemble code from that page.
- If more than one BEGIN/END pair exists, report `autogen_code_block_multiple` and use none of them until manually fixed.
- If the raw C++ block contains a line exactly matching the END sentinel, report `autogen_code_block_embedded_end` and require the author to refactor the snippet; do not try to escape it automatically.
- If inline triple-bracket content is nonblank and a begin/end block is also nonblank, prefer the block and report `autogen_inline_ignored`.
- If inline triple-bracket content contains `]]]`, report `autogen_inline_invalid` because the one-line form is ambiguous.

## Validator.ini Additions

Add sections:

```ini
[reconstructable]
UID = blank|true|false|invalid

[autogen_parent]
UID = PARENTUID

[autogen_parent_position]
UID = integer-or-blank

[reconstruction_code_hash]
UID = sha256-or-blank

[reconstruction_code_mode]
UID = inline|block|blank|invalid

[autogen_children]
PARENTUID = UID1;UID2;UID3

[autogen_root]
UID = BYFILEUID-or-blank

[autogen_status]
UID = unclassified|not_reconstructable|assigned|coded|error

[autogen_errors]
bad_autogen_<uid> = message
```

Notes:

- `autogen_children` is the reverse index used for incremental parent/root regeneration.
- `autogen_parent` is the source of truth for graph edges. `autogen_children` is derived state and must be repairable from `[autogen_parent]` plus `[files]`.
- `autogen_root` caches the resolved `by-file` root UID for faster rebuilds and error reporting.
- `reconstruction_code_hash` helps detect whether a child changed and whether generated output needs updating.
- `reconstruction_code_mode` records whether code came from the inline triple-bracket value, the safer begin/end block, or no code.
- Keep keys UID-based so file renames do not break the graph.
- Do not duplicate durable file paths in autogen sections. Use the existing `[files]` UID registry as the only UID-to-document-path authority, and resolve paths from it at read time.
- Store status and hashes only as cache/report helpers; a full scan must be able to rebuild them from current Markdown documents.

## Validator.ini Consistency Rules

The autogen registry must behave like the existing UID/path/reference registry: UID identity is durable, file paths can move, and stale reverse indexes must be cleaned rather than trusted forever.

Per-UID sections:

- `[reconstructable]`
- `[autogen_parent]`
- `[autogen_parent_position]`
- `[reconstruction_code_hash]`
- `[reconstruction_code_mode]`
- `[autogen_root]`
- `[autogen_status]`

Reverse/index sections:

- `[autogen_children]`
- `[autogen_errors]`

Single-file scan update rules:

- Parse the current file and update only that file's per-UID autogen values.
- If the scanned file has a known UID at a new path, update the existing `[files]` UID path first, then apply autogen registry updates under the same UID. Do not allocate a new UID for a moved document.
- Before changing parent/root values, capture the old parent and old root from validator.ini.
- If the parent changes, remove the UID from the old parent's `[autogen_children]` list and add it to the new parent's list.
- If reconstructable changes from true to false/blank, remove the UID from any parent child list and clear its root/status to the correct non-reconstructable or unclassified state.
- If code changes, update `reconstruction_code_hash` and mark the old/new resolved roots dirty.
- If a file path changes but UID stays the same, autogen sections remain keyed by UID and do not need path rewriting.
- Recompute and replace `bad_autogen_<uid>` errors for the scanned UID on every scan. If the previous issue was fixed, remove the stale error immediately.
- When a parent/root change affects descendants, mark descendants' cached `[autogen_root]` and `[autogen_status]` values dirty rather than trusting old cached values.
- If a scanned file is now ineligible but has autogen metadata, report `autogen_metadata_unexpected`; do not erase the registry until the page is manually corrected or a full cleanup confirms the UID is no longer eligible.

Full/documented scan rebuild rules:

- Recompute all autogen per-UID values for scanned eligible files from Markdown, not from old cache values.
- Rebuild `[autogen_children]` from the current parent values rather than merging with old data.
- Rebuild `[autogen_errors]` from current validation errors rather than retaining stale errors.
- Recompute `[autogen_root]` and `[autogen_status]` from the current graph.
- In full mode, current scoped Markdown files are authoritative for autogen-eligible content. Per-UID autogen entries for UIDs absent from the scoped scan should be reported as stale; remove them only when the UID has also been removed from `[files]` by `--remove-missing --apply`.
- In documented mode, preserve per-UID entries for files outside the scan when those files still exist but were not scanned.
- In documented mode, if a registry-known file is missing, report it as a missing documented file and leave autogen registry cleanup to `--remove-missing --apply`.

Missing UID cleanup rules:

- When `--remove-missing --apply` removes a UID from `[files]`, remove that UID from all autogen per-UID sections.
- Remove that UID from every `[autogen_children]` value.
- Remove `[autogen_children]` keys for missing parent UIDs.
- Remove matching `bad_autogen_<uid>` errors.
- Mark any roots affected by the removed UID dirty for the next autogen rebuild.
- If a removed UID was a parent, also mark each former child as `error` until rescanned or until full graph validation assigns a new valid parent.
- If a removed UID was a by-file root, remove cached `[autogen_root]` values pointing at that UID and report affected children as rootless.

Autogen-mode registry rules:

- `--mode autogen` should not insert, remove, or repair Markdown metadata lines.
- `--mode autogen` may rebuild generated `.cpp` and `-ag-*` reports from validator.ini plus the Markdown files referenced by validator.ini.
- If `--mode autogen` detects stale registry state that cannot be repaired without rescanning Markdown, report `autogen_registry_stale` and recommend `--mode full --apply` or a targeted file scan.
- If a referenced Markdown file is missing during autogen mode, skip that graph branch, report it in the relevant `-ag-*` report, and do not silently delete registry rows.
- `--mode autogen --apply` may update generated outputs and reports, but should not write validator.ini except for generated-output hashes or other explicitly documented cache fields that do not affect UID/path identity.

Registry write transaction order:

1. Parse inputs and build the intended new autogen registry in memory.
2. Validate parent links, roots, generated destinations, and stale cleanup actions.
3. If any operation would require destructive cleanup outside the documented rules, abort before writing.
4. Write generated outputs only after the target set is conflict-free for each affected root.
5. Write `validator.ini` last when possible, using the existing atomic write pattern.
6. If generated outputs were written but `validator.ini` fails, report `autogen_state_write_failed` and point to the created backup.

Validation pass invariants:

- Every UID in per-UID autogen sections should exist in `[files]`.
- Every child listed in `[autogen_children]` should exist in `[files]` and have matching `[autogen_parent]`.
- Every `[autogen_root]` value should either be blank or a UID in `[files]` whose path is a singular `by-file` page.
- Every error in `[autogen_errors]` should correspond to a current validation problem.
- Full scans should be able to repair all stale reverse indexes without manual editing of validator.ini.
- Autogen scans should detect stale reverse indexes and either use a safely rebuilt in-memory view or report `autogen_registry_stale` with the scan command needed to repair persistent state.
- Rebuilding `[autogen_children]` from `[autogen_parent]` must produce the same child lists that are written to validator.ini after a clean full scan.
- `bad_autogen_<uid>` entries must disappear automatically once the current scan proves the issue is fixed.

## Planned Validator Action Names

Use consistent action names in dry-run/apply output so agents can understand what happened without reading `validator.ini` directly.

Metadata/header actions:

- `insert_autogen_metadata`
- `restore_autogen_metadata`
- `autogen_metadata_unexpected`
- `autogen_value_invalid`

Code extraction actions:

- `autogen_code_block_empty`
- `autogen_code_block_unclosed`
- `autogen_code_block_unmatched`
- `autogen_code_block_multiple`
- `autogen_code_block_embedded_end`
- `autogen_inline_invalid`
- `autogen_inline_ignored`

Graph actions:

- `autogen_parent_missing`
- `autogen_parent_unknown`
- `autogen_parent_self`
- `autogen_parent_cycle`
- `autogen_parent_ineligible`
- `autogen_root_missing`
- `autogen_root_invalid_projected_path`
- `autogen_registry_cleanup`
- `autogen_registry_rebuild`
- `autogen_registry_stale`
- `autogen_error_clear`
- `autogen_child_index_update`
- `autogen_assigned`

Output actions:

- `autogen_cpp_create`
- `autogen_cpp_update`
- `autogen_cpp_noop`
- `autogen_cpp_conflict`
- `autogen_report_create`
- `autogen_report_update`
- `autogen_report_noop`
- `autogen_placeholder_delete`
- `autogen_placeholder_conflict`
- `autogen_backup_create`
- `autogen_state_write_failed`

## Header Repair Behavior

- Missing reconstruction metadata lines should be inserted for eligible pages.
- Damaged lines should be restored from validator.ini when possible.
- If no stored value exists, use blank defaults.
- If a page becomes ineligible, do not delete existing reconstruction lines automatically; report `autogen_metadata_unexpected` so an agent can review.
- `--uid-only` should insert/check these metadata lines because they are part of the top metadata header.
- `--reference-only` should skip reconstruction metadata mutation and autogen output.

## Validation Rules

For `RECONSTRUCTABLE` blank:

- Parent UID should be blank.
- Position can be blank.
- Code can be blank.
- Status: `unclassified`.

For `RECONSTRUCTABLE` false/0:

- Parent UID should usually be blank.
- Nonblank parent or code should produce a warning, not a hard error, so old work is not lost.
- Status: `not_reconstructable`.

For `RECONSTRUCTABLE` true/1:

- Parent UID is required.
- Parent UID must exist in `[files]`.
- Parent must not be self.
- Parent chain must not cycle.
- Parent chain should resolve to a singular `by-file` page with a valid `PROPOSED_RECONSTRUCTION_PATH`.
- C++ reconstruction code is expected. If it is blank, report the item as reconstructable and assigned when the parent chain is valid, but not `coded`.
- `AUTOGEN_PARENT_POSITION_OPTIONAL` remains optional even when reconstructable is true.
- Status: `assigned` when the parent chain is valid.
- Status: `coded` when assigned and the code snippet is included in generated output.

Position validation:

- Blank is valid.
- Integers are valid.
- Negative integers should be rejected unless explicitly allowed later.
- Duplicate integer positions under one parent are valid and ordered by first-registered child order.

## Parent Attachment Semantics

Recommended parent choices:

- A free function or module helper attaches to the `by-file` UID that owns it, unless there is a stronger semantic owner page that should contain it.
- A global variable, singleton, vtable, callback table, or file-local static attaches to the owning `by-file` UID unless it is truly class-owned.
- A class method attaches to the owning `by-class` UID.
- A class field or nested type attaches to the owning `by-class` UID.
- A struct field or nested declaration attaches to the owning `by-type` UID.
- A class or type attaches to the owning `by-file` UID.
- A memory page attaches to the nearest durable semantic owner. For example, a method memory page should attach to the method/function page if it exists, otherwise to the class or file.

The parent chain should always eventually terminate at a `by-file` page. If it does not, the item is assigned to a parent but not importable into a generated source file.

### C++ Context Rule

The reconstruction snippet must be valid for the location where it will be inserted.

Examples:

- A child inserted inside a class declaration should provide class-body code, such as a field declaration, method declaration, nested type, or inline method body.
- A non-inline method implementation such as `void Foo::Bar() { ... }` usually belongs at file scope. If it must still attach semantically to `Foo`, the class page needs an explicit marker or future named-slot support that can place method declarations inside the class and implementations at file scope.
- A global variable definition usually attaches to the owning `by-file` page unless it is intentionally represented as class-owned static storage.
- A memory-range page can attach to a semantic function/class page for tracking, but its reconstruction snippet should still be suitable for the parent insertion context.

Do not let the validator "fix" invalid C++ placement by rewriting snippets. It should assemble snippets exactly, report unsafe insertion cases, and leave source-layout decisions to documentation authors.

### Parent Selection Examples

| Item kind | Preferred parent | Reason |
| --- | --- | --- |
| `by-memory` method body | matching `by-function` or `by-class` method page if present, otherwise owning class/file | Keeps raw address evidence close to the semantic method. |
| `by-function` free helper | owning `by-file` page | Free helpers generally belong in source-file scope. |
| `by-function` class method | owning `by-class` page | Method code should be nested with the class draft unless the class page delegates to a file-level implementation marker. |
| `by-global` file-local static | owning `by-file` page | File-local storage belongs near the source file. |
| `by-global` class-owned singleton/vtable/table | owning `by-class` page if class ownership is clear, otherwise owning `by-file` page | Avoids forcing uncertain class ownership. |
| `by-type/by-struct` helper struct | owning `by-class` or `by-file` page | Struct placement depends on whether it is nested/private or file-level. |
Do not attach a child directly to a broad `by-meta`, `by-project-structure`, `by-external-research`, or `by-resource` page. Those pages may explain reconstruction or assets, but they are not generated C++ containers in the first implementation.

## Child Insertion Marker

Canonical marker:

```cpp
[[CHILDREN]]
```

When assembling code:

- Replace `[[CHILDREN]]` with the recursively generated child code.
- Remove the marker from final generated output.
- Preserve indentation by detecting whitespace before the marker and applying it to inserted children.
- If multiple markers exist, report `autogen_multiple_child_markers` and use the first marker unless a later design supports named slots.
- If the malformed marker `[[]CHILDREN]` is seen, report a warning and suggest `[[CHILDREN]]`.

Fallback insertion when no marker exists:

- For class/struct code ending with `};`, insert child code before the final `};`.
- For a code block ending with a final `}`, insert before the final `}` only if this is safe and the parent type is known to accept nested content.
- For file roots, append child code at the end.
- For function bodies, do not insert children by default; report a warning unless the function explicitly contains `[[CHILDREN]]`.

## Child Ordering

Sort children under a parent by:

1. `AUTOGEN_PARENT_POSITION_OPTIONAL` numeric value, ascending.
2. First-registered child order when positions conflict.
3. Unpositioned children after positioned children.
4. First-registered child order among unpositioned children.

Implementation detail:

- Use UID allocation order as a deterministic proxy for first-registered order unless a new `[autogen_order]` sequence is added.
- If a page existed before this feature and has an older UID, UID order may not represent actual attachment order. Add `[autogen_order]` if this becomes a problem.

Example:

```text
A: blank
E: 1
C: 5
B: 1
D: 3
```

Generated order:

```text
E
B
D
C
A
```

## Generated C++ Output

Destination roots:

- `by-file` pages with valid `PROPOSED_RECONSTRUCTION_PATH` define the staged `.cpp` destination.
- The destination filename is `<by-file-md-stem>.cpp`.
- Output path remains under `project-documentation/auto-generated/<projected path>/<stem>.cpp`.

Generated file safety:

- If destination file is empty, write generated content.
- If destination file contains the validator autogen sentinel, overwrite it atomically.
- If destination file is nonempty and lacks the sentinel, report `autogen_target_conflict` and do not overwrite.

Recommended sentinel:

```cpp
// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
```

Generation shape:

```cpp
// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// Source by-file UID: 000123
// Source by-file doc: by-file/Foo.md

<assembled code>
```

If the by-file root itself has no C++ code, the file content is just the assembled children.

### Output Layout

Keep generated project source and validator control reports separate:

```text
project-documentation/
  auto-generated/
    -ag-file-coverage.md
    -ag-global-coverage.md
    -ag-memory-coverage.md
    -ag-class-coverage.md
    -ag-function-coverage.md
    -ag-type-coverage.md
    -ag-resource-coverage.md
    NexusTK/
      <projected folders from PROPOSED_RECONSTRUCTION_PATH>
        <ByFileStem>.cpp
```

Rules:

- `-ag-*` coverage reports live directly under `auto-generated`; they are validator control reports, not reconstructed project source files.
- Generated `.cpp` files live under `auto-generated/<PROPOSED_RECONSTRUCTION_PATH>/<ByFileStem>.cpp`.
- The project-root directory spelling must be canonical. The canonical root is `NexusTK/`; do not also generate a parallel `Nexustk/` tree unless the projected-path policy is explicitly changed.
- If the implementation finds an existing empty alternate-casing directory such as `auto-generated/Nexustk`, report it and remove it only if empty. If it contains files, report a casing conflict and do not move or delete automatically without a dedicated cleanup plan.
- Do not place `-ag-*` coverage reports inside the generated project-root directory.

### Assembly Algorithm

Build generated C++ in this order:

1. Load all autogen metadata for scanned/known files.
2. Build the parent-to-children map.
3. Validate graph cycles and root reachability before writing anything.
4. For each valid by-file root, assemble the root code and recursively assemble children.
5. Track each UID included in each generated destination.
6. Write or move only after all conflicts for that root are known.

Recursive assembly for one node:

1. Read the node's reconstruction code.
2. Assemble all valid child snippets in sorted child order.
3. If the node code has `[[CHILDREN]]`, replace the marker with the assembled child text.
4. If the node code has no marker, use fallback insertion by node kind.
5. If the node has no code but has children, emit only child text and report `autogen_parent_has_no_code`.
6. Mark a node `coded` only when its own nonblank code or at least one coded child reaches a generated destination.

Formatting rules:

- Separate sibling snippets with exactly one blank line unless the snippet already starts or ends with blank lines.
- Preserve snippet text exactly except for child marker replacement and indentation adjustment.
- Normalize generated file newlines to `\n`.
- Do not run a C++ formatter inside the validator; formatting should stay explicit in the source snippets.
- Keep the generated header stable. Do not include timestamps or absolute paths in generated `.cpp` output because that would defeat no-op write checks.
- Include the sentinel and root by-file UID/doc comment shown above. Include per-snippet source UID comments only behind a debug flag; normal draft `.cpp` should stay readable C++.

### Generated File Ownership

The validator should distinguish three generated-file states:

- `empty_placeholder`: existing empty `.cpp` created by the by-file projected-path feature.
- `validator_owned`: file contains the autogen sentinel and can be overwritten.
- `manual_or_conflict`: file is nonempty and lacks the sentinel; never overwrite automatically.

If a file moves because the by-file `PROPOSED_RECONSTRUCTION_PATH` changes:

- Move `empty_placeholder` and `validator_owned` files.
- Do not move or overwrite `manual_or_conflict` files; report the conflict.
- Remove empty folders after successful moves, as the current projected-path feature already does.

## Coverage Reports

Current `auto-generated` coverage files exist but are empty:

- `auto-generated/-file-coverage.md`
- `auto-generated/-global-coverage.md`
- `auto-generated/-memory-coverage.md`

The requested new names are:

- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- additional `-ag-<type>-coverage.md` files as more item types are supported.

Current placeholder files without the `-ag-` prefix already exist. Implementation should replace them with the requested `-ag-*` reports and either delete the old empty placeholders or replace them with a short pointer to the new generated report. Do this in a dry-run first so existing open editor tabs do not hide unexpected churn.

Each auto-generated coverage report should begin with stats:

```text
Total_Type: X
Total_Reconstructable: X
Total_Not_Reconstructable: X
Total_Reconstructed_Assigned: X
Total_Reconstructed_Coded: X
```

Recommended extra stat:

```text
Total_Unclassified: X
```

Reason: blank `RECONSTRUCTABLE` is neither reconstructable nor not reconstructable. Without an unclassified count, the totals will not explain all eligible pages.

Stats definitions:

- `Total_Type`: total eligible pages represented by that report's type, including unclassified and errored pages.
- `Total_Reconstructable`: pages with normalized `RECONSTRUCTABLE` true/1.
- `Total_Not_Reconstructable`: pages with normalized `RECONSTRUCTABLE` false/0.
- `Total_Reconstructed_Assigned`: reconstructable pages with a valid parent chain to a by-file root.
- `Total_Reconstructed_Coded`: reconstructable assigned pages whose own code or recursively assembled child code was written into a generated `.cpp`.
- `Total_Unclassified`: eligible pages with blank `RECONSTRUCTABLE`.
- Optional `Total_Error`: pages whose metadata, parent chain, destination, or code extraction has an error.

Stats invariants:

- `Total_Type = Total_Reconstructable + Total_Not_Reconstructable + Total_Unclassified + Total_Error` when invalid metadata is counted as error rather than unclassified.
- `Total_Reconstructed_Coded <= Total_Reconstructed_Assigned <= Total_Reconstructable`.
- A page cannot be counted as coded if the destination `.cpp` was skipped because of a manual-file conflict.
- A page with valid parent chain but blank code counts as assigned, not coded.

Suggested table columns:

```text
| UID | Status | Parent UID | Position | Coded | Destination | Source Doc | Detail |
| --- | --- | --- | ---: | --- | --- | --- | --- |
```

Example report shape:

```text
# Auto Generated Global Coverage

Generated: 2026-05-30 00:00:00

Total_Type: 3
Total_Reconstructable: 2
Total_Not_Reconstructable: 1
Total_Reconstructed_Assigned: 1
Total_Reconstructed_Coded: 1
Total_Unclassified: 0
Total_Error: 1

| UID | Status | Parent UID | Position | Coded | Destination | Source Doc | Detail |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| [UID:000123][g_Foo](by-global/g_Foo.md) | coded | [UID:000010][FooFile](by-file/FooFile.md) | 10 | yes | `auto-generated/NexusTK/app/FooFile.cpp` | `by-global/g_Foo.md` | imported |
```

Rows should use validator-generated UID links when possible:

```text
[UID:000123][Foo](by-class/Foo.md)
```

Because the `auto-generated` folder is not itself a scanned `by-*` folder, coverage report links should be generated directly from validator.ini path mappings. Do not require the auto-generated reports themselves to receive UIDs.

Status meanings:

- `unclassified`: eligible page has blank `RECONSTRUCTABLE`.
- `not_reconstructable`: page is explicitly false/0.
- `reconstructable_unassigned`: true/1 but no valid parent chain.
- `assigned`: true/1 with a valid parent chain to a by-file root.
- `coded`: assigned and included in a generated `.cpp`.
- `error`: invalid metadata or graph conflict prevents assignment/coding.

Report routing:

- `-ag-file-coverage.md`: by-file roots and generated destination status.
- `-ag-global-coverage.md`: `by-global` reconstructable items.
- `-ag-memory-coverage.md`: `by-memory` reconstructable items.
- `-ag-class-coverage.md`: `by-class` reconstructable items.
- `-ag-function-coverage.md`: `by-function` reconstructable items.
- `-ag-type-coverage.md`: `by-type` reconstructable items, including subtype folders.
- `-ag-resource-coverage.md`: defer for the first implementation unless a later explicit rule allows reconstructable `by-resource` pages.

The coverage generator should not mark a page `coded` merely because it has a snippet. It is coded only if the snippet or its assembled children were actually written into a generated destination file.

## End-To-End Example

This example shows the intended flow using stable UIDs. Exact UIDs are illustrative only; agents must use validator-assigned UIDs in real files.

### Source File Root

`by-file/ExampleClient.md` is a source-file root. It does not receive the reconstruction child metadata. It uses the existing by-file projected path:

```text
*** UID:000100 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:25 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
```

Generated destination:

```text
auto-generated/NexusTK/app/ExampleClient.cpp
```

### Class Page

`by-class/ExampleClient.md` attaches to the file root and provides class-level code with an explicit child marker:

```text
*** UID:000101 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:45 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000100 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ExampleClient {
public:
    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Class Child Page

`by-function/ExampleClient.Connect.md` attaches to the class and provides class-body code:

```text
*** UID:000102 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:35 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000101 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Connect();
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Global Page

`by-global/g_ExampleClient.md` attaches to the file root because it is file-scope storage:

```text
*** UID:000103 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:15 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000100 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static ExampleClient* g_ExampleClient = nullptr;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Expected Generated C++

Position ordering under the file root places the global before the class:

```cpp
// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// Source by-file UID: 000100
// Source by-file doc: by-file/ExampleClient.md

static ExampleClient* g_ExampleClient = nullptr;

class ExampleClient {
public:
    void Connect();
};
```

### Expected Coverage Row

`auto-generated/-ag-function-coverage.md` would include the function child as coded because it reached the generated `.cpp`:

```text
| [UID:000102][ExampleClient.Connect](by-function/ExampleClient.Connect.md) | coded | [UID:000101][ExampleClient](by-class/ExampleClient.md) | 1 | yes | `auto-generated/NexusTK/app/ExampleClient.cpp` | `by-function/ExampleClient.Connect.md` | imported |
```

## Integration With Existing Validator Modes

Full/documented scan with `--apply`:

- Ensure metadata headers.
- Rebuild autogen registry sections in validator.ini.
- Rebuild parent/child graph.
- Regenerate all affected `.cpp` files.
- Regenerate all auto-generated coverage reports.
- Regenerate completion stats as it does today.

File scan with `--apply`:

- Ensure metadata for that file.
- Update its autogen registry entry.
- Update reverse parent index for old and new parents.
- Find the affected by-file root(s).
- Regenerate only those affected `.cpp` files and coverage rows when safe.
- If incremental coverage update becomes too complex, update the file's rows and recommend `--mode autogen --apply` when rows drop out.

Autogen mode:

```powershell
python validator.py --mode autogen --apply
```

This is the first-implementation CLI contract for rebuilding generated C++ and `-ag-*` coverage reports from already-scanned metadata. Do not overload `rescore` for this feature in the first implementation.

Recommended mode behavior:

- `--mode file --apply`: update metadata/registry for one file, then regenerate affected roots if enough registry data is current.
- `--mode full --apply`: scan all by-* docs, rebuild registry, regenerate all autogen outputs and reports.
- `--mode documented --apply`: scan registry-known docs, rebuild registry for those docs, regenerate autogen outputs and reports for known roots.
- `--mode rescore --apply`: keep current completion-stat behavior only; do not generate autogen outputs.
- `--mode autogen --apply`: read validator.ini and the referenced Markdown files needed for code snippets, then regenerate generated C++ and `-ag-*` reports without inserting missing metadata into unrelated Markdown files.

Dry-run behavior:

- Every mode should report which generated files would be created, moved, overwritten, skipped, or conflicted.
- Dry run should not update `validator.ini`, generated `.cpp`, or `-ag-*` reports.
- Dry run should still parse enough Markdown to identify graph errors and destination conflicts.

### Exact CLI Contract

Supported commands after implementation:

```powershell
python validator.py --mode file --file by-class\Foo.md
python validator.py --mode file --file by-class\Foo.md --apply
python validator.py --mode full
python validator.py --mode full --apply
python validator.py --mode documented
python validator.py --mode documented --apply
python validator.py --mode autogen
python validator.py --mode autogen --apply
```

Rules:

- `--mode autogen` is report/output generation only. It should not insert missing reconstruction metadata into unrelated Markdown files.
- `--mode autogen` may read Markdown files referenced by validator.ini to extract C++ snippets.
- `--mode autogen` should rebuild `-ag-*` reports and generated `.cpp` files from current registry state.
- `--uid-only` should skip autogen output generation even if metadata changed.
- `--reference-only` should skip autogen metadata and output generation.
- `--mode isolated` remains report-only and should not participate in autogen.
- `--remove-missing` keeps its current meaning for UID mappings; if it removes a UID that participates in autogen, it must also remove stale autogen registry entries for that UID under `--apply`.

## Error Cases To Handle

- Missing parent UID.
- Parent UID not in validator.ini.
- Parent UID points to a missing file.
- Parent UID points to an excluded/support page.
- Parent cycle: A -> B -> A.
- Parent chain does not resolve to a by-file root.
- by-file root has blank/invalid `PROPOSED_RECONSTRUCTION_PATH`.
- Child code exists but `RECONSTRUCTABLE` is false or blank.
- `RECONSTRUCTABLE` true but code is empty.
- Invalid position value.
- Duplicate generated destination path from two by-file docs.
- Generated target conflict with nonempty non-autogen file.
- Multiple `[[CHILDREN]]` markers.
- Missing marker in a parent that has children and cannot be safely auto-inserted.
- Code block parse failure.
- Markdown code fence accidentally left open.
- C++ snippet contains validator metadata-looking text.
- Unicode/encoding read error.
- UID conflict or duplicate UID in files.
- File rename with stale parent/child reverse index.
- Begin/end C++ block is malformed, duplicated, or contains an embedded END sentinel.
- Inline triple-bracket code conflicts with nonblank begin/end block.
- Inline code value contains `]]]`, making the one-line form ambiguous.
- Parent page is `by-file`, but the by-file page lacks a valid projected destination.
- Two by-file pages project to the same generated `.cpp` destination.
- Projected path casing creates competing generated roots such as `NexusTK/` and `Nexustk/`.
- A `-ag-*` coverage report is accidentally generated inside the project source tree instead of directly under `auto-generated`.
- A child attaches to a parent that is marked not reconstructable.
- A parent changes from reconstructable to not reconstructable while children still point to it.
- A UID appears in `autogen_children` but no longer references that parent after a source edit.
- Generated destination was manually edited after validator created it.
- Backup creation fails before an apply-mode generated-output write.
- validator.ini write fails after generated-output writes.
- Agent uses `[[]CHILDREN]` from the user's rough example instead of canonical `[[CHILDREN]]`.
- A snippet contains a class declaration without final `};`, making fallback insertion unsafe.

## Data Model And Parsing Notes

Use structured helpers instead of ad hoc regex spread across the validator:

- `AutogenMetadata` dataclass:
  - `uid`
  - `path`
  - `eligible`
  - `reconstructable_raw`
  - `reconstructable_state`
  - `parent_uid`
  - `position`
  - `code`
  - `code_hash`
  - `errors`

- `AutogenNode` dataclass:
  - `metadata`
  - `children`
  - `root_uid`
  - `destination_path`
  - `status`

Separate phases:

1. Parse/repair metadata headers.
2. Build UID/path map.
3. Build parent graph.
4. Validate graph.
5. Assemble code.
6. Write generated outputs.
7. Write coverage reports.
8. Persist validator.ini.

This separation makes dry-run behavior easier to verify and prevents generated output from being written before all conflicts are known.

## Performance And Scalability Requirements

The implementation should be efficient enough for thousands of Markdown files and many agents queueing validator jobs. Optimize for predictable single-pass work, stable indexes, and minimal filesystem churn.

Core requirements:

- Build UID-to-path, path-to-UID, parent-to-children, child-to-parent, and root-to-descendants maps once per full/autogen scan. Avoid repeated linear searches through all files for each node.
- Treat full scans as `O(files + references + autogen_edges)` plus file I/O. Avoid algorithms that become `O(files * edges)` or `O(files * roots)`.
- Treat single-file scans as incremental. Re-parse the changed file, update its registry rows, then regenerate only affected root `.cpp` files and affected coverage rows where possible.
- Use `reconstruction_code_hash` to skip generated-output writes when assembled content did not change.
- Use output content comparison before atomic replacement. Do not rewrite generated `.cpp`, coverage reports, or `validator.ini` when serialized content is byte-for-byte unchanged.
- Avoid scanning `auto-generated` as input. It is output-only and should never feed back into the autogen graph.
- Avoid using expensive recursive filesystem walks more than once per command. Cache `all_markdown_files(root)` for the run.
- Do not shell out for per-file operations. Use Python path and file APIs in the background process.
- Keep queue processing single-writer, but make each job fast enough that queued agents are not blocked by avoidable full-registry rebuilds.
- Preserve dry-run speed: dry runs should compute the same plan but skip content hashing of unchanged generated files when the target path does not exist or no root is dirty.

Suggested in-memory indexes:

```text
uid_to_path: dict[str, str]
path_to_uid: dict[str, str]
metadata_by_uid: dict[str, AutogenMetadata]
children_by_parent: dict[str, list[str]]
parent_by_child: dict[str, str]
root_by_uid: dict[str, str]
destination_by_root: dict[str, Path]
dirty_roots: set[str]
```

Dirty-root rules for incremental file scans:

- If a child changes code, reconstructable state, position, or parent, mark its old root and new root dirty.
- If a parent changes code or marker placement, mark the parent's resolved root dirty.
- If a by-file projected path changes, mark that by-file root dirty and move/regenerate the destination.
- If a UID path changes, update indexes by UID and mark the old/new roots dirty if the file was part of the autogen graph.
- If a graph error prevents root resolution, mark the affected item in coverage but do not force a global rebuild.

Generated output write strategy:

- Assemble generated C++ into memory per root.
- Compute a hash of assembled content.
- Compare with a stored/generated hash or existing file bytes before writing.
- Write with the existing atomic tempfile-plus-replace pattern only when content changes.
- For coverage reports, generate one string per report and write only if changed.

Memory-use constraints:

- Do not keep full text for every Markdown file longer than needed in file-mode scans.
- In full/autogen scans, keep only parsed metadata, extracted C++ snippet, and needed hashes, not entire Markdown bodies.
- Avoid retaining duplicate generated C++ strings for all roots at once; assemble, compare/write, and release per root unless a later feature needs a full combined manifest.

Benchmark expectations:

- A dry-run single-file scan should remain effectively interactive.
- A full metadata scan should scale linearly with the number of scoped Markdown files.
- Autogen generation should scale with the number of reconstructable nodes plus generated roots, not all documentation pages when run from a single-file change.
- Add optional timing output behind a verbose/debug flag, not normal user output.

## Safety And Rollback

The validator already uses atomic writes. Autogen should add explicit generated-output safety on top of that.

Backup rules:

- Before the first apply-mode autogen run that writes generated `.cpp` or `-ag-*` reports, create a timestamped backup directory under `tools/validator_autogen_backup/<timestamp>/`.
- Back up only files that will be overwritten, moved, or deleted.
- Store paths relative to `project-documentation` inside the backup so restore is straightforward.
- Do not back up unchanged files.
- Do not back up temp-root test fixtures.

Rollback rules:

- Add a future maintenance command to list available autogen backups, for example `--mode autogen-restore --list`.
- Add a future maintenance command to restore one backup, for example `--mode autogen-restore --backup <timestamp> --apply`.
- The first implementation can defer the restore command if the backup directory format is simple and documented, but the backup creation should exist before live autogen writes.

Write safety:

- Never overwrite nonempty generated `.cpp` files without the autogen sentinel.
- Never delete nonempty old coverage placeholder files.
- Never delete or move files outside `project-documentation/auto-generated`.
- Resolve and bounds-check every generated output path before writing.
- Treat path casing conflicts as errors before any write for the affected root.
- If any destination conflict exists for one by-file root, skip writing that root but continue processing unrelated roots.
- If validator.ini write fails after generated outputs were written, report a high-severity `autogen_state_write_failed` action recommending restore from the created backup.

## Backward Compatibility

- Existing docs should get blank defaults only when scanned.
- Existing `by-file` projected path feature must keep working.
- Existing completion stats should not be rewritten unnecessarily during file scans.
- Existing UID/TMP/reference behavior should remain unchanged.
- Existing auto-generated empty `.cpp` files should only be overwritten if empty or carrying the autogen sentinel.
- Existing empty coverage placeholders without the `-ag-` prefix should be handled intentionally when `-ag-*` reports are introduced; do not leave two authoritative report names with conflicting content.
- Existing docs with no reconstruction metadata should not be mass-rewritten unless a full scan is explicitly run with `--apply`.

## Default First-Implementation Decisions

Use these defaults unless the user explicitly changes the feature before coding:

- C++ storage: keep the exact requested `RECONSTRUCTION_CPP CODE:[[[]]]` top line, and use the begin/end block for actual multiline C++.
- Coverage reports: generate the requested `-ag-*` reports directly under `auto-generated`.
- Existing zero-byte non-`-ag` coverage placeholders: delete them when generating the replacement `-ag-*` reports under `--apply`; in dry-run, report the planned deletion.
- Existing nonempty non-`-ag` coverage placeholders: leave them in place and report a conflict/pointer-needed action rather than deleting content.
- Blank `RECONSTRUCTABLE`: count it as `Total_Unclassified`.
- `by-type` pages: eligible for metadata when they are singular non-`-xxx.md` pages, but remain blank/unclassified until an agent marks them reconstructable.
- Generated headers: out of scope for the first implementation. Stage `.cpp` output only; snippets may still include declarations if that is where the documentation author wants them in the draft `.cpp`.
- Root casing: require `NexusTK/` in `PROPOSED_RECONSTRUCTION_PATH`.
- Formatting: do not run automatic C++ formatting in the validator.
- Performance: implement dirty-root regeneration and no-op write checks in the first version, not as later polish.

## Test Plan

Use a temporary documentation root first.

Test 1: metadata insertion

- Create `by-class/Foo.md` with UID/completion/confidence only.
- Dry-run file scan.
- Expect reconstruction metadata insert actions.
- Apply and verify lines are inserted.

Test 2: true but missing parent

- Set `RECONSTRUCTABLE:TRUE`.
- Leave parent blank.
- Apply scan.
- Expect `bad_autogen_<uid>` error and coverage row not assigned.

Test 3: valid by-file root and class child

- Create `by-file/Foo.md` with valid `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.
- Create `by-class/Foo.md` with parent UID of by-file and class code.
- Apply scan/autogen.
- Expect `auto-generated/NexusTK/app/Foo.cpp` containing class code.

Test 4: recursive children marker

- Class contains `[[CHILDREN]]`.
- Add five child methods with positions blank, 1, 5, 1, 3.
- Apply autogen.
- Verify order: position 1 children in registration order, then 3, then 5, then blank.

Test 5: fallback insertion

- Class has no `[[CHILDREN]]` but ends with `};`.
- Add child.
- Verify child inserts before `};` or report warning if parser cannot safely detect it.

Test 6: cycle detection

- A parent B, B parent A.
- Expect cycle error and no generated output for affected root.

Test 7: target conflict

- Create nonempty `auto-generated/NexusTK/app/Foo.cpp` without sentinel.
- Apply autogen.
- Expect conflict and no overwrite.

Test 8: rename

- Rename child doc and scan.
- Verify UID path updates and generated output still includes child.

Test 9: invalid position

- Use `AUTOGEN_PARENT_POSITION_OPTIONAL:abc`.
- Expect invalid-position error.

Test 10: live dry-run

- Run against one existing eligible live doc without `--apply`.
- Confirm no live files are modified and action list is sane.

Test 11: coverage report generation

- Create reconstructable, not reconstructable, unclassified, assigned, coded, and error items.
- Run autogen report generation.
- Verify stats totals and table rows match the fixture.

Test 12: generated destination collision

- Create two by-file docs that resolve to the same projected `.cpp`.
- Run autogen.
- Verify both roots report collision and no unsafe overwrite occurs.

Test 13: stale child reverse index

- Attach a child to parent A, scan, then change it to parent B.
- Verify `[autogen_children]` removes the child from A and adds it to B.

Test 14: excluded pages stay clean

- Scan a `by-file` page, a `-guidance.md` page, a `by-meta` page, a `by-external-research` page, a `by-project-structure` page, and a `by-resource` page.
- Verify none receive reconstruction child metadata.

Test 15: parent UID cannot be guessed

- Set `AUTOGEN_PARENT_UID` to an unknown six-character UID.
- Verify the validator reports the parent as missing and does not treat the item as assigned.

Test 16: performance benchmark

- Build a temp fixture with thousands of Markdown files, hundreds of reconstructable nodes, and several by-file roots.
- Verify full/autogen scan time scales linearly with fixture size.
- Verify a single-file edit regenerates only the affected root and does not rewrite unchanged generated outputs.
- Verify generated reports are not rewritten when their content is unchanged.

Test 17: output layout and casing

- Create by-file roots with projected paths and generate autogen output.
- Verify `-ag-*` reports are directly under `auto-generated`.
- Verify `.cpp` files are under the canonical projected root, currently `auto-generated/NexusTK/...`.
- Verify an empty alternate-casing directory is reported/removed only when safe, and a nonempty alternate-casing directory is reported as a conflict.

Test 18: malformed C++ block handling

- Create fixtures for missing END, END without BEGIN, duplicate blocks, embedded END sentinel, nonblank inline plus nonblank block, and inline content containing `]]]`.
- Verify each case reports the expected action/error and does not assemble code from the malformed page.

Test 19: backup and rollback safety

- Create existing generated `.cpp` and `-ag-*` report files that will be overwritten.
- Run apply-mode autogen.
- Verify changed/deleted files are backed up under `tools/validator_autogen_backup/<timestamp>/`.
- Verify unchanged files are not backed up.
- Force a destination conflict and verify no backup/write happens for that conflicted root.

Test 20: remove-missing autogen cleanup

- Create a reconstructable child with parent/root entries and generated output.
- Delete the child Markdown file.
- Run documented/full scan without `--remove-missing` and verify the missing UID is reported but registry entries are not silently removed.
- Run the same scan with `--remove-missing --apply`.
- Verify the UID is removed from all autogen per-UID sections, removed from every `[autogen_children]` value, and removed from `bad_autogen_<uid>` errors.

Test 21: full scan rebuilds stale reverse indexes

- Manually seed a stale `[autogen_children]` list that disagrees with `[autogen_parent]`.
- Run a full dry-run and verify it reports the repair.
- Run a full apply scan and verify `[autogen_children]` is rebuilt solely from current parent values.

Test 22: autogen mode does not mutate Markdown

- Create an eligible Markdown file missing reconstruction metadata.
- Run `--mode autogen --apply`.
- Verify generated reports/output may update from existing registry data, but the Markdown file does not receive new metadata lines.
- Verify the mode reports that a full or file scan is needed before the missing page can participate.

Test 23: deterministic generated output

- Run autogen twice with no source changes.
- Verify generated `.cpp`, `-ag-*` reports, and `validator.ini` are not rewritten on the second run.
- Verify generated `.cpp` headers contain no timestamps or absolute local paths.

## Implementation Phases

Phase 1: metadata-only support

- Add regex/constants and parsing helpers.
- Add eligibility checks.
- Insert/repair new lines with blank defaults.
- Store parsed values in validator.ini sections.
- Add dry-run tests.

Phase 2: graph validation and coverage reports

- Build parent/child graph.
- Add error handling.
- Generate coverage reports under `auto-generated`.
- Do not generate `.cpp` yet.

Phase 3: C++ code block support

- Resolve the one-line vs block-form decision.
- Implement robust code extraction.
- Add code hash tracking.

Phase 4: `.cpp` assembly

- Implement recursive assembly, child marker replacement, fallback insertion, ordering, cycle protection, and target conflict handling.
- Write only empty or sentinel-owned generated files.

Phase 5: incremental regeneration

- Use reverse indexes to regenerate affected roots during single-file scans.
- Add `--mode autogen` path for complete generated C++/report rebuilds.

Phase 6: documentation

- Update `tools/validator_README.txt`.
- Update `by-structure.md` high-level validator/autogen workflow.
- Update relevant `-guidance.md` files, especially `by-memory`, `by-class`, `by-global`, `by-function`, `by-type`, and `by-file`.

## Current Code Integration Map

Use the current validator structure as the implementation target. Do not create a parallel validator.

Primary file:

- `tools/validator_background.py`

Existing areas to extend:

- Metadata regex/constants near `UID_LINE_RE`, `COMPLETION_LINE_RE`, `CONFIDENCE_LINE_RE`, and `PROJECTED_PATH_LINE_RE`.
- Shared autogen eligibility constants near the metadata constants, including the excluded top-level folder set.
- Metadata line builders near `make_uid_line`, `make_completion_line`, `make_confidence_line`, and `make_projected_path_line`.
- Config section initialization in `load_config`.
- Eligibility helpers near `is_under_by_directory` and `is_by_file_projected_doc`.
- Header insertion/repair in `ensure_metadata_header`.
- Per-file registry update in `scan_file`.
- Target selection in `scan_targets` if a new `autogen` mode is added.
- Completion/report generation patterns near `generate_completion_stats_text`, `update_completion_stats`, and `update_projected_path_stats`.
- Main orchestration in `run_validator`.
- CLI mode choices in `main`.

New helper groups to add in `validator_background.py`:

- Autogen constants and regexes:
  - `RECONSTRUCTABLE_LINE_RE`
  - `AUTOGEN_PARENT_UID_LINE_RE`
  - `AUTOGEN_PARENT_POSITION_LINE_RE`
  - `RECONSTRUCTION_CPP_TAG_LINE_RE`
  - `RECONSTRUCTION_CPP_BEGIN_LINE`
  - `RECONSTRUCTION_CPP_END_LINE`
  - `CHILDREN_MARKER = "[[CHILDREN]]"`

- Autogen dataclasses:
  - `AutogenMetadata`
  - `AutogenNode`
  - `AutogenReportEntry`
  - `AutogenRootOutput`

- Metadata helpers:
  - `is_autogen_metadata_doc(root, path)`
  - `make_reconstructable_line(value)`
  - `make_autogen_parent_uid_line(value)`
  - `make_autogen_parent_position_line(value)`
  - `make_reconstruction_cpp_code_line(value)`
  - `parse_autogen_metadata_lines(lines, start_index)`
  - `ensure_autogen_metadata_header(...)`

- Code extraction helpers:
  - `extract_reconstruction_cpp(text_or_lines)`
  - `extract_reconstruction_cpp_block(lines)`
  - `hash_reconstruction_code(code)`
  - `has_children_marker(code)`

- Graph helpers:
  - `build_autogen_metadata_index(root, config, targets)`
  - `update_autogen_registry_for_file(...)`
  - `build_autogen_graph(metadata_by_uid)`
  - `resolve_autogen_roots(graph)`
  - `detect_autogen_cycles(graph)`
  - `dirty_roots_for_autogen_change(old_metadata, new_metadata, graph)`

- Assembly helpers:
  - `sort_autogen_children(children)`
  - `assemble_autogen_node(uid, graph, metadata_by_uid)`
  - `insert_children_into_code(parent_code, child_code, node_kind)`
  - `fallback_insert_children(parent_code, child_code, node_kind)`
  - `generate_autogen_root_output(root_uid, graph)`

- Output/report helpers:
  - `autogen_report_path(kind)`
  - `generate_autogen_coverage_reports(...)`
  - `write_autogen_reports(...)`
  - `write_autogen_cpp_outputs(...)`
  - `classify_generated_file(path)`
  - `safe_write_if_changed(path, content)`

Queue frontend:

- `tools/validator.py` should not need structural changes for the core feature. It already queues unknown validator args through to `validator_background.py`.
- Only update `validator.py` if a new frontend-only option is required. A new backend mode such as `--mode autogen` should be handled in `validator_background.py`.

Documentation files to update after code exists:

- `tools/validator_README.txt`: command syntax, metadata grammar, autogen mode, reports, generated-output safety, examples.
- `by-structure.md`: high-level workflow and warning not to guess parent UIDs.
- Folder guidance files where agents will author snippets:
  - `by-memory/-guidance.md`
  - `by-class/-guidance.md`
  - `by-function/-guidance.md`
  - `by-global/-guidance.md`
  - `by-type/-guidance.md`
  - `by-file/-guidance.md`
- `by-resource/-guidance.md`: add a short note that resource docs are excluded from autogen metadata in the first implementation unless later explicitly promoted.

## Detailed Algorithms

### Eligibility Algorithm

For a Markdown file to receive the new reconstruction metadata:

1. It must be under a direct `by-*` folder.
2. It must not be under `by-file`.
3. Its filename must not start with `-`.
4. Its top-level folder must not be `by-meta`, `by-external-research`, `by-project-structure`, or `by-resource`.
5. It must not be under `auto-generated`, `tools`, or root-level documentation.
6. It should represent program code, declarations, globals, functions, methods, classes, or code-owned types that can reasonably appear in a rebuilt C++ source file.

If a file already has reconstruction metadata but is no longer eligible, report it as unexpected and do not delete the lines automatically.

Implementation guard:

- Define one shared exclusion set, for example `AUTOGEN_EXCLUDED_TOP_LEVEL_FOLDERS = {"by-file", "by-meta", "by-external-research", "by-project-structure", "by-resource"}`.
- Use that one helper for metadata insertion, file scans, full scans, tests, and autogen registry rebuilds so folder eligibility cannot drift between modes.
- Normalize candidate paths to project-relative POSIX-style parts before checking folder eligibility. Do not compare against absolute paths or junction-expanded paths.

### Root Resolution Algorithm

For each reconstructable true item:

1. Validate parent UID exists.
2. Walk parent links until a by-file UID is reached.
3. Stop with an error if a parent is missing, invalid, ineligible, not reconstructable when it needs to be a container, or repeats in the current path.
4. Validate the by-file root has valid `PROPOSED_RECONSTRUCTION_PATH`.
5. Cache the resolved root UID in `[autogen_root]`.

Use iterative traversal with a visited set rather than recursive parent walking to avoid recursion depth problems and to make cycle errors explicit.

### Child Ordering Algorithm

Sort child UIDs under one parent with this stable key:

```text
(
  has_no_position,          # positioned children first
  position_value_or_0,      # numeric ascending
  registration_order,       # first-come/first-served for ties
  uid                       # deterministic final tie-breaker
)
```

Registration order should come from the existing UID allocation order unless an explicit `[autogen_order]` section is added later.

### Fallback Insertion Algorithm

Preferred insertion is always explicit `[[CHILDREN]]`.

Fallback should be conservative:

- If node kind is class/struct and code ends with a top-level `};`, insert before that final `};`.
- If node kind is file/root, append children at the end.
- If node kind is function/method, require an explicit marker; do not guess insertion inside a function body.
- If the parser cannot identify a safe final `};`, report an error and leave children out rather than corrupting generated C++.

### No-Op Write Algorithm

For generated `.cpp`, `-ag-*` reports, and `validator.ini`:

1. Serialize the intended content.
2. If the target exists, read current bytes/text.
3. If content is identical, skip writing and report `autogen_noop` only in verbose mode.
4. If content differs and target is safe to write, use the existing atomic write pattern.

### Registry Rebuild Algorithm

For full scans:

1. Collect scoped Markdown files and parse current UID/header/autogen metadata.
2. Build new per-UID autogen sections from parsed eligible documents.
3. Preserve existing UID/path data outside autogen sections according to normal validator rules.
4. Build `[autogen_children]` from the new `[autogen_parent]` values.
5. Resolve roots and statuses from the rebuilt graph.
6. Replace old autogen reverse indexes and error sections with the rebuilt versions.
7. Report stale old entries that were dropped from derived sections.

For file scans:

1. Parse the target file and update its per-UID autogen rows.
2. Remove the UID from its old parent child list when parent changed or reconstructable is no longer true.
3. Add the UID to its new parent child list only when reconstructable is true and the parent value is nonblank.
4. Recompute errors for that UID and any directly affected old/new parent/root path.
5. Mark old and new roots dirty for output/report regeneration.

## Requirement Traceability

Use this table during implementation review so the feature stays aligned with the requested end state.

| Requirement | Planned handling | Verification evidence |
| --- | --- | --- |
| Add new top metadata tags for non-`by-file` reconstruction docs | Metadata insertion/repair for eligible singular by-* pages only | Temp fixture and live dry-run show eligible page receives all four lines |
| Do not add tags to `by-file` pages | `by-file` is excluded from reconstruction child metadata and remains a source-file root | Test 14 verifies by-file page stays clean |
| Do not add tags to `-xxx.md` support files | Filename exclusion for leading `-` | Test 14 verifies `-guidance.md` stays clean |
| Default values are empty | Header repair uses blank defaults and stores `blank` state | Metadata insertion test verifies empty values |
| Accept `TRUE`, `1`, `FALSE`, `0` | Boolean parser normalizes values to true/false/blank/invalid | Completion gate verifies accepted/rejected values |
| Reconstructable items need parent assignment | True/1 validation requires `AUTOGEN_PARENT_UID` and graph validation | Tests 2 and 15 verify missing/unknown parent errors |
| Parent is nearest semantic owner | Parent attachment guidance by item kind | Manual review against parent-selection examples |
| Position is optional integer ordering | Position parser accepts blank or integer; sort uses numeric then registration order | Test 4 verifies ordering |
| Conflicting positions use first-come/first-served order | Stable sort key uses position then registration order | Test 4 verifies E/B before D/C/A example behavior |
| C++ reconstruction code is fully converted C++ | Code field/block stores raw reconstructed C++ snippet; no formatter mutates it | Code extraction test verifies snippet preservation |
| Generated files receive assembled code | Recursive assembly writes staged `.cpp` under by-file projected path | Tests 3 and 4 verify generated content |
| `[[CHILDREN]]` inserts recursive children | Assembly replaces marker and recurses through child graph | Test 4 verifies recursive insertion |
| Missing marker has fallback insertion | Class/struct fallback inserts before final `};` when safe | Test 5 verifies fallback |
| Unsafe fallback is refused | Parser reports warning/error when no safe insertion point exists | Test 5 variant and completion gate verify refusal |
| Generate `-ag-*` coverage files | Coverage generator writes requested report names | Test 11 verifies report existence and rows |
| Coverage reports include requested totals | Stats block contains total type/reconstructable/not/assigned/coded | Test 11 verifies stats totals |
| Keep generated reports out of source tree | `-ag-*` reports are written directly under `auto-generated`, while `.cpp` files follow projected source paths | Test 17 verifies layout |
| Assigned means valid parent chain | Status computation separates assigned from coded | Test 11 verifies status rows |
| Coded means imported into destination | Status becomes coded only after generated output includes snippet/children | Test 11 verifies coded rows |
| Do not overwrite manual generated files | Generated-file ownership check refuses non-sentinel nonempty targets | Test 7 verifies conflict |
| Optimize and perform well | Single-pass indexes, dirty roots, hashes, no-op write avoidance | Test 16 verifies performance and no needless rewrites |
| Exclude non-code documentation folders | Folder eligibility excludes `by-file`, `by-meta`, `by-external-research`, `by-project-structure`, `by-resource`, support files, tools, and auto-generated docs | Test 14 verifies excluded pages stay clean |
| Stale reverse indexes are repaired | `[autogen_children]` is derived from `[autogen_parent]` and rebuilt on full scans | Tests 13 and 21 verify old-parent removal and full rebuild |
| Deleted docs clean autogen registry only through explicit cleanup | `--remove-missing --apply` removes per-UID state, child references, root cache, and errors | Test 20 verifies cleanup |
| Autogen-only mode does not rewrite Markdown | `--mode autogen` generates outputs/reports from current registry without metadata insertion | Test 22 verifies no Markdown mutation |
| Generated output stays stable across no-op runs | No timestamps/absolute paths in generated files and no-op writes skip unchanged content | Test 23 verifies deterministic output |

## Implementation Checklist

Before coding:

- Confirm the default first-implementation decisions above still match the latest user direction.
- Check whether any existing `auto-generated` control report placeholders are nonempty before planning deletion or pointer replacement.
- Check whether the background validator worker is running so it can be restarted after code changes.

During coding:

- Add constants and regexes near existing metadata regexes.
- Add an eligibility helper separate from `is_by_file_projected_doc`.
- Extend metadata header repair without changing by-file projected-path behavior.
- Add structured autogen metadata parsing and validation.
- Add validator.ini sections and reverse indexes.
- Add graph build and cycle/root validation.
- Add generated C++ assembly with child marker replacement.
- Add `-ag-*` coverage report generation.
- Add autogen backup creation before live generated-output writes.
- Add dirty-root incremental regeneration.
- Add no-op write checks and timing/debug hooks.

After coding:

- Run temp fixture tests before touching live docs.
- Run live dry-run on one eligible page, one by-file page, and one `-guidance.md`.
- Run `py_compile`.
- Restart the background validator worker so queued commands load the new code.
- Run a queued validator dry-run to verify frontend/background integration.
- Update `validator_README.txt`, `by-structure.md`, and relevant `-guidance.md` files.

## Completion Gates

Do not consider the validator update complete until these are all proven by current-state evidence:

- Eligible non-`by-file`, non-`-xxx.md` docs receive the requested reconstruction metadata lines.
- `by-file`, `by-meta`, `by-external-research`, `by-project-structure`, `by-resource`, root docs, tool docs, auto-generated docs, and `-xxx.md` support docs do not receive the new reconstruction metadata lines.
- Existing UID, score, TMP, UID-reference, queue, and projected-path behavior still works.
- `RECONSTRUCTABLE` accepts blank, `TRUE`, `1`, `FALSE`, and `0`, and rejects bad values with reported errors.
- True reconstructable items require a valid parent UID and valid parent chain to a by-file root.
- Parent ordering matches numeric-position then first-registered ordering.
- `[[CHILDREN]]` recursive insertion works and malformed `[[]CHILDREN]` is reported.
- Fallback insertion works for safe class/struct snippets and refuses unsafe snippets.
- Generated `.cpp` output is written only to empty or validator-owned files.
- `-ag-file-coverage.md`, `-ag-global-coverage.md`, `-ag-memory-coverage.md`, and other supported `-ag-*` reports are generated with correct totals.
- File scans update affected roots without needing a full scan for every edit.
- Full scans rebuild the graph from current docs and clear stale reverse indexes; autogen scans detect stale registry state and avoid persisting unsafe repairs.
- `--remove-missing --apply` removes deleted UIDs from all autogen registry sections and child lists.
- `--mode autogen` does not mutate Markdown metadata and reports stale registry state clearly.
- Dry runs report all intended writes without changing Markdown, `validator.ini`, generated C++, or reports.
- Performance tests show full scans are linear in scoped Markdown/input edges and file scans only regenerate affected roots.
- Unchanged generated files and reports are not rewritten.
- `-ag-*` reports are generated directly under `auto-generated`, and generated `.cpp` files use one canonical project-root casing.

## Deferred Optional Scope

These are not required for the first implementation unless the user explicitly expands the scope:

- Separate generated `.h` files.
- Named child slots such as `[[CHILDREN:DECLARATIONS]]` and `[[CHILDREN:IMPLEMENTATIONS]]`.
- Multiple insertion markers in one snippet.
- Automatic C++ formatting.
- Automatically moving or deleting nonempty old coverage placeholder files.

