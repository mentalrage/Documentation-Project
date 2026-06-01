*** UID:0001ZQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Project-Structure Guidance

Use `by-project-structure` for top-down reconstruction of the original source tree, folders, build organization, and file grouping.

`proposed-source-tree.md` should be kept current when documentation adds, removes, renames, or reassigns likely source files. Where possible, nest classes, globals, large structures, and important helper groups under their proposed source file for visibility.

Project-structure pages are planning/support documents, not direct binary reconstruction units, so they should normally be scored `COMPLETION:-1` and `CONFIDENCE:-1`.

## Examples

```text
proposed-source-tree.md
ui-dialogs.md
network-and-protocol.md
asset-and-rendering.md
```

## Page Contents

Each project-structure page should include:

- proposed directory tree and source grouping;
- evidence from generated `.vcproj`, import source filenames, class families, string/resource usage, and memory locality;
- nested visibility for likely file contents when practical: classes, globals, large helper structs, callback tables, vtables, and major data tables should be listed under the owning file entry rather than as peer source files;
- unresolved alternatives and why one layout is preferred;
- phased migration plan for Wave3 file renames, simpaths, and class/global ownership changes.

## Coverage Report Rows

Project-structure pages are support/planning docs, so coverage rows should usually be scored `-1` unless a page is explicitly being treated as a direct reconstruction work item. Use source-tree topic names as row keys and keep `proposed-source-tree.md` current when source-file/module additions, removals, renames, or placement changes are made elsewhere.
