*** UID:0001ZM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-File Guidance

Use `by-file` for source-file reconstruction: likely original `.cpp`/`.h` ownership, file-local globals, grouped classes, helper functions, include needs, and evidence for why items belong together.

Each page should describe what the original file probably contained and why those items were likely colocated instead of spread across other files. Keep `../by-project-structure/proposed-source-tree.md` synchronized when file names are added, removed, renamed, or reorganized.

Use UID references for linked `by-class`, `by-memory`, `by-global`, `by-type`, and peer `by-file` pages, then run the validator file scan after edits.

## Whole-File Research Assignments

Whenever an agent is specifically assigned a `by-file` target, the assignment covers the entire inferred original source file or coherent compilation unit. It is not a request to research one representative function, improve only the by-file page, or stop after the easiest linked children. This rule applies at every score; the stricter `95+` scoring gate below is an additional final-audit standard, not the trigger for whole-file scope.

Before calling the research complete, build and reconcile an exhaustive inventory using current IDA/MCP or manual binary evidence, the by-file page, all linked and discoverable by-* pages, callers/callees/xrefs, neighboring ranges, generated output, and matching reports. Research every reasonably discoverable item belonging to the file:

- every function, method, constructor, destructor, callback, helper, wrapper, thunk, EH helper, compiler-generated body, and compiler-covered or inlined source route;
- every global, static, singleton slot, constant, string/literal, table, initialized or uninitialized data item, and file-local state;
- every class/struct/type/layout/field/enum, vtable/RTTI item, template/helper declaration, import, resource, and dependency required to reconstruct the file;
- every exact code/data range, item boundary, gap/padding span, child, split/merge/container relationship, caller, callee, xref, initialization/destruction route, and declaration/definition/source-order constraint;
- every related `by-memory`, `by-class`, `by-global`, `by-item`, `by-type`, `by-resource`, peer `by-file`, or other support page that documents a file-owned item or is affected by the result.

Give every inventory item an evidence-backed behavior/role, source-facing name/type disposition, ownership and emitter/source-placement decision, separate CPP/H or compiler-covered/no-code disposition, metadata/score impact, and exact documentation/validation destination as applicable. Record excluded membership candidates with the evidence for exclusion. A sampled subset, generic `remaining functions` bucket, aggregate count without identities, deferred page-only cleanup, or unexplained omission means the by-file research is incomplete.

### File-Completion Gate

By-file work means completing the reconstructed source module, not only completing its documentation. Compare the exhaustive inventory with the current emitter graph and validator-generated `.cpp` plus any existing or expected sibling `.h`. Find every missing function, method, helper, callback, definition, initializer, table, child fragment, or other code/data item. Treat stubs, TODOs, placeholders, empty-emitter markers, decompiler-shaped bodies, omitted branches/error paths/state changes, partial data, duplicate fragments, and wrong source order as incomplete work that must be resolved.

Audit the header side independently. Determine whether the inferred module requires a sibling `.h`; if it does, inventory and complete every declaration, prototype, class/struct/enum/type definition, extern, field/layout, constant/template, include, forward declaration, guard, and declaration order needed by the file. A required missing, stale, or incomplete `.h` is a completion blocker. If the module is intentionally private/headerless or all declarations correctly belong to other headers, document exact file-specific evidence; do not invent an empty or speculative header merely to make a `.h` exist.

Apply accepted repairs only in the owning documentation pages' formal `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` channels and correct `EMITTER_UIDS`/child ordering. Generated files under `auto-generated/NexusTK/**` are validator-owned and must never be edited directly. After implementation, run scoped validators for every changed page and a coherent generated refresh, normally with `--wait-generated` when verifying final output. Physically reread the current generated `.cpp` and required `.h`, compare them row by row with the whole-file inventory and source-order plan, and record the validator command ID/timestamp. The work is not complete while any inventoried function/code/data/declaration is missing or partial, while a required `.h` is absent/incomplete, or while the generated output does not match the accepted whole-file report.

Related UIDs receive tracker/report coverage only when the report declares them and independently supplies the target-specific evidence, recommendation, ledger/checklist, implementation, and validation required by the B-agent additional-target rules. UIDs not declared for coverage still remain in whole-file research and support-doc scope when they belong to or materially affect the file.

## Projected Reconstruction Path

Direct singular `by-file/*.md` pages whose filename does not start with `-`
have a validator-managed projected output line after UID, COMPLETION, and
CONFIDENCE:

```text
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
```

Fill only the quoted value with the reconstructed project folder, for example
`NexusTK/app/`. This is the folder path inside the rebuilt project root where
the source file belongs. The generated `.cpp` filename comes from the Markdown
filename, so the path value must never include a filename.

Rules:

- use exact root casing `NexusTK/`;
- keep the path relative, never absolute;
- end with `/`;
- do not include the filename or extension;
- do not use `.` or `..` segments;
- use folder names only, not guessed generated filenames.

Use forward slashes when editing the value. The validator can normalize valid
backslash paths, but forward slashes keep the intended `NexusTK/` root obvious.

The validator derives the staged source path from the projected folder and the
Markdown filename:

```text
by-file/AlphaMaskSurface.md
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"
=> auto-generated/NexusTK/render/AlphaMaskSurface.cpp
```

Blank means source placement has not been chosen. Invalid values are reported
by the validator, tracked in `validator.ini`, and listed in
`../project-level/-auto-completion-stats.md` under `projected_path_completion`.
Use `NONE` only after the page has been reviewed and documented as intentionally
non-standalone: a generated alias, helper/facet, umbrella/source-family note, or
planning placeholder whose code belongs to other source roots. A `NONE` page does
not emit a generated `.cpp`, is excluded from projected-path completion, and must
explain the real owner or non-promotion reason in the page body/change log. Do
not use `NONE` as a shortcut for unresolved source placement.

When the path is valid, the validator creates an empty `.cpp` placeholder if no
generated file exists. If the by-file page is renamed or the projected folder
changes, the validator moves the staged `.cpp` when there is no target conflict
and removes empty generated folders below `auto-generated`. If the path is later
blank or invalid, the validator reports the existing generated file as stale
instead of deleting it.

This path line belongs only on singular `by-file` pages. Classes, globals,
functions, memory ranges, and types attach to a `by-file` UID with autogen
metadata when they need to contribute C++. Do not attach child autogen items to a
`NONE` by-file page; choose a valid source root once ownership is proven.

Recommended workflow:

1. Use this page's source-ownership evidence and
   `../by-project-structure/proposed-source-tree.md` to choose the folder.
2. Fill only the quoted `PROPOSED_RECONSTRUCTION_PATH` value.
3. Run `python ../tools/validator.py --mode file --file by-file/<ThisFile>.md --apply`
   or an equivalent absolute-path command.
4. Review validator output for invalid path, move conflict, or stale generated
   `.cpp` actions.
5. Update `../by-project-structure/proposed-source-tree.md` in the same pass
   when the proposed source location changes.

## Naming

A `by-file` page represents one hypothesized original `.cpp`/`.h` pair or coherent source module, not necessarily one current Wave3 generated file.

Filename examples:

```text
Browser.md
DialogSystem.md
DATFile.md
ProfileStorage.md
```

## Page Contents

Each file page should include:

- proposed original source path and header path, when known or hypothesized;
- confidence level and evidence summary;
- current Wave3 file containers/classes/globals that should belong to the file;
- classes, helper structs, free functions, global data, includes, and resources likely declared/defined there;
- reasoning for why entities should be grouped together instead of spread across separate generated files;
- migration notes for Wave3 actions such as `rename file`, `set file-simpath`, `attach class`, `set global-data-owner`, or global-file creation;
- cross-references to neighboring file docs.
- a reconciled whole-file inventory that identifies every discovered file-owned function and other code/data/type/resource item, records rejected membership candidates, and links each item to its canonical detailed documentation and final source/no-code disposition.
- a generated-source completion audit mapping the inventory to current `.cpp` and required `.h` output, identifying and resolving missing/incomplete functions/code/data/declarations, stubs/placeholders/empty emitters, route/order defects, and any required missing header; include exact evidence when no sibling `.h` is appropriate.

This folder is the main place to decide whether generated one-class files in `../simroot_v2` should be merged into more plausible original source modules. When source-file documentation or likely original file path/module placement changes, update `../by-project-structure/proposed-source-tree.md` in the same pass. In proposed source-tree views, nest likely owned classes, globals, large helper structs, callback tables, vtables, and major data tables under their source file entry when practical.

## Scoring Discipline

Do not rate a source-file page at `95+` completion or confidence lightly. Those values require an extreme, recorded audit of the whole proposed file: path, source grouping, included classes, helpers, globals, static data, vtables, resources, third-party embeds, neighboring ownership questions, generated-name replacements, and every material cross-reference must be verified and documented. If any included item, dependency, path, or grouping decision still depends on unverified Wave3/Wave2/simroot evidence or incomplete IDA/MCP review, keep the score below `95`.

## Coverage Report Rows

Use proposed source-module names as row keys in `-coverage-report.md`, sorted alphabetically unless a local grouping section makes subsystem ordering clearer. Mark a file reconstructable when there is evidence for original source/header placement, likely contained classes/globals/helpers, and why the grouping is more plausible than the generated `simroot_v2` split. Put confirmed external/runtime/third-party source modules in `-ignored.md` with the replacement dependency or toolchain owner.

## Reconstruction Autogen

`by-file` pages are generated source roots, not child emitter items. The validator should not add `RECONSTRUCTABLE`, `EMITTER_UIDS`, or `RECONSTRUCTION_CPP CODE` metadata to these pages. Direct singular by-file pages instead use `CANONICAL_OWNER:FILE` plus a valid `PROPOSED_RECONSTRUCTION_PATH` to become generated roots, and validator autogen writes assembled drafts to `auto-generated/<PROPOSED_RECONSTRUCTION_PATH>/<ThisPageStem>.cpp`. Other reconstructable pages use `CANONICAL_OWNER` for semantic ownership and `EMITTER_UIDS` to route generated output to a by-file root, class, type, global, or other valid emitter chain. A child page can be marked `RECONSTRUCTABLE:TRUE` once IDA/MCP or direct binary evidence proves it is NexusTK-owned source that must be rebuilt, even when final file ownership is still open. Do not fill the child `CANONICAL_OWNER`, `EMITTER_UIDS`, or `RECONSTRUCTION_CPP CODE` until the owner, output route, source placement, boundaries, dependencies, and final-source shape are highly verified. For direct file-root emission, that usually means the owning `by-file` page has been validated and has `CANONICAL_OWNER:FILE` plus a valid projected path.

Do not use file attachment or generated C++ as a shortcut around incomplete research. A child item should normally stay unattached until its owner/output route is evidence-backed and should normally keep `RECONSTRUCTION_CPP CODE` blank until its completion/confidence, dependencies, names, boundaries, and source placement satisfy the active `90/90+` reconstruction-code gate in `../by-structure.md`. The `95+` final-audit scoring standard remains separate and is not required merely to enter code.

Normal validator file/full/documented scans refresh autogen reports unless
`--uid-only` or `--reference-only` is used. Use `../auto-generated/-ag-file-coverage.md`
to review by-file root status and `../auto-generated/-ag-*-coverage.md` for
child reconstruction assignment/coding status. The old non-`ag` coverage
placeholder files are not authoritative.
