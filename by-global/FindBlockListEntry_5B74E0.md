*** UID:0000PM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FindBlockListEntry_5B74E0 is a by-global alias for the helper body emitted by [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md).
// Do not emit a duplicate definition from this alias page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FindBlockListEntry_5B74E0

## Status

- Confidence: strong for boundary, caller set, behavior, and local owner.
- Address range: [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md)
- Symbol kind: free helper / vector search helper.
- Likely owner file: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- Temporary alias: `FindBlockedNameInRange_5B74E0` when modeled as a global.

## Behavior

`FindBlockListEntry_5B74E0` is the raw/name-index view of the private [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) helper. Source should model it as a file-local `BlockListenInputPanes.cpp` helper returning `SimpleUStringVector::iterator`, not as a global function with an explicit output pointer.

The helper scans a range of 4-byte pointer-backed `SimpleUStringVector` slots and returns the first iterator whose string matches the by-value search key case-insensitively. The decompiler exposes the hidden iterator return slot as an explicit output pointer; source prose should keep the normal iterator return form. It obtains the key pointer through `0x00584540` (`StringBase::c_str` / `GetStringDataPointer`), compares through `0x00582950` (`WideStringCompareNoCase` / `_wcsicmp` wrapper), and destroys the by-value key through `0x00582b70` before returning.

## Evidence

- IDA MCP `lookup_funcs 0x005b74e0` reports `sub_5B74E0`, size `0x73`.
- IDA MCP `callers 0x005b74e0` reports only two callers in this pass: `0x005b6d89` inside [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) and `0x005b720d` inside [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md).
- IDA decompilation shows an iterator loop from begin to end, a string extraction helper, and a comparison helper before storing the matched iterator.
- IDA MCP recheck on 2026-06-05 confirmed `sub_5B74E0`, size `0x73`, the same two add/delete block-list callers, and string helper callees `0x00582950`, `0x00584540`, and `0x00582b70`.
- Current IDA MCP disassembly records the comparison loop at `0x005b7511-0x005b7531`, the output iterator store at `0x005b7539`, and cleanup via `sub_582B70` at `0x005b753b`.
- Current IDA MCP byte reads confirm three `0xcc` bytes immediately before this helper at `0x005b74dd-0x005b74e0` and thirteen `0xcc` bytes immediately after it at `0x005b7553-0x005b7560`.
- 2026-06-14 live IDA MCP `analyze_function 0x005b74e0` reconfirmed `sub_5B74E0`, size `115` / `0x73`, callers `sub_5B6CC0` and `sub_5B7140`, callees `sub_584540`, `sub_582950`, and `sub_582B70`, nine basic blocks, cyclomatic complexity `2`, and the SEH/security-cookie wrapper around the same iterator comparison loop.
- 2026-06-22 B013 source-quality pass resolves `sub_584540` as the `StringBase::c_str` / data-pointer accessor, `sub_582950` as the `_wcsicmp` / case-insensitive wide compare wrapper, and `sub_582B70` as the wide string by-value parameter release/destructor path. The block-listen name range comes from the `SimpleUStringVector` triplet at `g_pConfig + 0x2918fc/+0x291900`.

## Data Caveat

This real helper should carry with `BlockListenInputPanes.cpp` because both current callers are block-list add/delete handlers. This by-global page is an index/support alias only; emitted source belongs on [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) to avoid duplicate C++.

Formal C++ on this index page is a no-duplicate marker by duplicate-emission policy, not because the helper lacks source-quality evidence. The by-memory target now owns the first-draft source-style `FindBlockListEntry` body, and [UID:0000PM] exists only as a high-traffic by-global alias/search index.

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
- 2026-06-14 A002 Goal 2 by-global score pass: raised from `84/90` to `86/92`.
  - Reason: live IDA MCP `analyze_function` reconfirmed the exact function size, only two block-list callers, three string/vector helper callees, SEH/security-cookie wrapper, loop/output/cleanup behavior, and retained [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) owner/emitter route. At that time final C++ remained blank pending source-quality helper/type names; the 2026-06-22 B013 pass supersedes that no-code reason for the by-memory target, while this by-global page stays blank by duplicate-emission policy.
- 2026-06-22 B013 Rule 26 source-quality incorporation: no score change.
  - Reason: by-global remains a support/index page while the by-memory target now owns the first-draft C++ body. The index now records the case-insensitive `_wcsicmp` lookup, hidden iterator return, by-value search-key cleanup, and config block-listen vector direction.
- 2026-07-01 B007 empty-emitter implementation callback: raised `86/92` to `87/93` and inserted the formal no-duplicate marker. [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) remains the single emitted helper body; this by-global page is an alias/index only.
