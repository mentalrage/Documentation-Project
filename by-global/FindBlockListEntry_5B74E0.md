*** UID:0000PM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FindBlockListEntry_5B74E0

## Status

- Confidence: strong for boundary and local owner.
- Address range: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- Symbol kind: free helper / vector search helper.
- Likely owner file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Current generated alias: `FindBlockedNameInRange_5B74E0` when modeled as a global.
- Historical method status: no method record found by `inspect method 0x005b74e0`.

## Behavior

`FindBlockListEntry_5B74E0` scans a vector-like range of wide-string objects and returns the first iterator whose string compares equal to the search string. It stores the resulting iterator in an output pointer and destroys the temporary search string before returning.

## Evidence

- IDA MCP `lookup_funcs 0x005b74e0` reports `sub_5B74E0`, size `0x73`.
- IDA MCP `callers 0x005b74e0` reports only two callers in this pass: `0x005b6d89` inside [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) and `0x005b720d` inside [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md).
- IDA decompilation shows an iterator loop from begin to end, a string extraction helper, and a comparison helper before storing the matched iterator.

## Data Caveat

Wave3 currently has no method catalog entry for this real helper. Documentation and future source migration should still carry it with `BlockListenInputPanes.cpp` because both current callers are block-list add/delete handlers.

## Cross-References

- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md)
- [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented the vector search helper, exact owner, callers, and Wave3 catalog caveat but remained unevaluated.
  - After: score reflects documented iterator/string comparison behavior, exact block-list owner, and live caller evidence.
  - Evidence: IDA notes confirm `0x005b74e0-0x005b7553`, callers from add/delete block-list input panes, and decompiled loop/search behavior.
