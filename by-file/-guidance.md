*** UID:0001ZM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-File Guidance

Use `by-file` for source-file reconstruction: likely original `.cpp`/`.h` ownership, file-local globals, grouped classes, helper functions, include needs, and evidence for why items belong together.

Each page should describe what the original file probably contained and why those items were likely colocated instead of spread across other files. Keep `../by-project-structure/proposed-source-tree.md` synchronized when file names are added, removed, renamed, or reorganized.

Use UID references for linked `by-class`, `by-memory`, `by-global`, `by-type`, and peer `by-file` pages, then run the validator file scan after edits.

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

Blank means source placement has not been assigned. Invalid values are reported
by the validator, tracked in `validator.ini`, and listed in
`../project-level/-auto-completion-stats.md` under `projected_path_completion`.

When the path is valid, the validator creates an empty `.cpp` placeholder if no
generated file exists. If the by-file page is renamed or the projected folder
changes, the validator moves the staged `.cpp` when there is no target conflict
and removes empty generated folders below `auto-generated`. If the path is later
blank or invalid, the validator reports the existing generated file as stale
instead of deleting it.

This path line belongs only on singular `by-file` pages. Classes, globals,
functions, memory ranges, and types attach to a `by-file` UID with autogen
metadata when they need to contribute C++.

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

This folder is the main place to decide whether generated one-class files in `../simroot_v2` should be merged into more plausible original source modules. When source-file documentation or likely original file path/module placement changes, update `../by-project-structure/proposed-source-tree.md` in the same pass. In proposed source-tree views, nest likely owned classes, globals, large helper structs, callback tables, vtables, and major data tables under their source file entry when practical.

## Scoring Discipline

Do not rate a source-file page at `95+` completion or confidence lightly. Those values require an extreme, recorded audit of the whole proposed file: path, source grouping, included classes, helpers, globals, static data, vtables, resources, third-party embeds, neighboring ownership questions, generated-name replacements, and every material cross-reference must be verified and documented. If any included item, dependency, path, or grouping decision still depends on unverified Wave3/Wave2/simroot evidence or incomplete IDA/MCP review, keep the score below `95`.

## Coverage Report Rows

Use proposed source-module names as row keys in `-coverage-report.md`, sorted alphabetically unless a local grouping section makes subsystem ordering clearer. Mark a file reconstructable when there is evidence for original source/header placement, likely contained classes/globals/helpers, and why the grouping is more plausible than the generated `simroot_v2` split. Put confirmed external/runtime/third-party source modules in `-ignored.md` with the replacement dependency or toolchain owner.

## Reconstruction Autogen

`by-file` pages are source roots, not child autogen items. The validator should not add `RECONSTRUCTABLE` or `RECONSTRUCTION_CPP CODE` metadata to these pages. Other reconstructable pages attach to the `by-file` UID, and validator autogen writes the assembled draft to `auto-generated/<PROPOSED_RECONSTRUCTION_PATH>/<ThisPageStem>.cpp`. A child page can be marked `RECONSTRUCTABLE:TRUE` once IDA/MCP or direct binary evidence proves it is NexusTK-owned source that must be rebuilt, even when final file ownership is still open. Do not fill the child `AUTOGEN_PARENT_UID` or `RECONSTRUCTION_CPP CODE` until the owning parent UID, source placement, boundaries, dependencies, and final-source shape are highly verified. For file-root attachment, that usually means the owning `by-file` page has been validated and has a valid projected path.

Do not use file attachment or generated C++ as a shortcut around incomplete research. A child item should normally stay unattached and code-empty until its completion/confidence, dependencies, names, boundaries, and source placement are near the `95+` final-audit standard described in `../by-structure.md`.

Normal validator file/full/documented scans refresh autogen reports unless
`--uid-only` or `--reference-only` is used. Use `../auto-generated/-ag-file-coverage.md`
to review by-file root status and `../auto-generated/-ag-*-coverage.md` for
child reconstruction assignment/coding status. The old non-`ag` coverage
placeholder files are not authoritative.
