*** UID:0000PM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FindBlockListEntry_5B74E0

## Status

- Confidence: strong for boundary, caller set, behavior, and local owner.
- Address range: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- Symbol kind: free helper / vector search helper.
- Likely owner file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Temporary alias: `FindBlockedNameInRange_5B74E0` when modeled as a global.

## Behavior

`FindBlockListEntry_5B74E0` scans a vector-like range of wide-string objects and returns the first iterator whose string compares equal to the search string. It stores the resulting iterator in an output pointer and destroys the temporary search string before returning.

## Evidence

- IDA MCP `lookup_funcs 0x005b74e0` reports `sub_5B74E0`, size `0x73`.
- IDA MCP `callers 0x005b74e0` reports only two callers in this pass: `0x005b6d89` inside [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) and `0x005b720d` inside [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md).
- IDA decompilation shows an iterator loop from begin to end, a string extraction helper, and a comparison helper before storing the matched iterator.
- IDA MCP recheck on 2026-06-05 confirmed `sub_5B74E0`, size `0x73`, the same two add/delete block-list callers, and string helper callees `0x00582950`, `0x00584540`, and `0x00582b70`.
- Current IDA MCP disassembly records the comparison loop at `0x005b7511-0x005b7531`, the output iterator store at `0x005b7539`, and cleanup via `sub_582B70` at `0x005b753b`.
- Current IDA MCP byte reads confirm three `0xcc` bytes immediately before this helper at `0x005b74dd-0x005b74e0` and thirteen `0xcc` bytes immediately after it at `0x005b7553-0x005b7560`.

## Data Caveat

This real helper should carry with `BlockListenInputPanes.cpp` because both current callers are block-list add/delete handlers.

Final C++ remains blank because the exact source-level wrapper types and string helper names are not complete enough for the 95/95 final-source gate.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented the vector search helper, exact owner, callers, and catalog caveat but remained unevaluated.
  - After: score reflects documented iterator/string comparison behavior, exact block-list owner, and live caller evidence.
  - Evidence: IDA notes confirm `0x005b74e0-0x005b7553`, callers from add/delete block-list input panes, and decompiled loop/search behavior.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
  - Reason: live IDA MCP recheck confirms source-authored vector search behavior and only block-list add/delete pane callers.
- 2026-06-05: Raised from `80/86` to `84/90`.
  - Reason: current IDA MCP now documents exact caller/callee sets, loop behavior, output store, cleanup, and adjacent padding boundaries on the page.
