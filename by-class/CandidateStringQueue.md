*** UID:00001G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CandidateStringQueue

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Type interpretation: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- Address ranges: [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md) and [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)
- Current recovered file: `source-3/simroot_v2/class_CandidateStringQueue.cpp`
- Rebuild handling: generated class identity is ignored; source code should use the owning IME/InputMan containers rather than reconstructing a `CandidateStringQueue` class.
- Confidence: strong for behavior, ignored-class disposition, and STL deque/wstring shape; medium-high for final source-facing typedef/member name.

## Class Purpose

`CandidateStringQueue` is the current generated name for a concrete MSVC/Dinkumware `std::deque<std::wstring>`-style template instantiation used by IME candidate strings. It is useful as a behavioral label for the binary helper ranges, but it should not be treated as proof of an original handwritten NexusTK class or `CandidateStringQueue.cpp` source file.

Source reconstruction should model the product code as ordinary candidate-string containers in [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md) and [UID:0000K6][InputMan](by-file/InputMan.md), letting the compiler and standard library provide the deque/string helper implementation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AssignRange` | [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md) | STL/deque range-copy helper that clears the destination and copies candidate-string entries from a source range. |
| `ReserveAdditional` | [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md) | STL/deque map-growth helper that preserves wrapped entries and handles large aligned allocations. |
| `Clear` | [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md) | STL/deque clear/destructor helper that releases `std::wstring` element storage and map slots. |
| `AppendOwnedString` | `0x004e9710-0x004e97a3` | STL/deque append helper that moves a prepared 0x18-byte `std::wstring` entry into the next slot. |

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- Live IDA MCP on 2026-06-14, session `a001_goal2_class_batch`, reconfirmed the helper function objects: `sub_4E8450` size `0x15e`, `sub_4E8860` size `0x192`, `sub_4E8A00` size `0xe6`, and `sub_4E9710` size `0x93`.
- The same pass decompiled `0x004e9710` as a deque append/move helper: it grows through `sub_4E8860` when capacity is exhausted, allocates a `0x18`-byte element slot when needed, copies a prepared wide-string object into the slot, resets the source to inline-empty state with capacity `7`, and increments the deque count.
- `analyze_function 0x004e9710` reports direct code xrefs at `0x004e91a6` and `0x004e9234`, both inside the `InputMan::HandleWindowMessage` neighborhood, preserving the split where InputMan builds temporary candidate strings and IME panes own display-side container state.
- IDA MCP string/xref checks find `deque<T> too long` at `0x0060f0a8`, referenced through `0x0043f190`; `0x004e8860` calls that overflow helper at `0x004e89e8`.
- IDA decompilation shows a 0x18-byte wide-string element layout with inline capacity `7`, heap threshold `>= 8`, and MSVC-style 0x1000/32-byte aligned large allocation handling.
- `IMECandidatePane` construction initializes the embedded container at offset `+0xf8`, including an 8-byte container-proxy/back-pointer allocation, which matches Dinkumware checked-container/deque layout patterns.
- IDA xrefs show `IMECandidatePane::ShowCandidateList` calls `AssignRange` at `0x004e7b3d`.
- IDA xrefs show `AssignRange` and `AppendOwnedString` call `ReserveAdditional`.
- IDA xrefs show `InputMan::HandleWindowMessage` calls `AppendOwnedString` at `0x004e91a6` and `0x004e9234`.
- IDA xrefs show `Clear` is called by `AssignRange`, `IMEPane::HandleIMEMessage`, and `IMECandidatePane::ScalarDeletingDestructor`.

## Reconstruction Notes

- Treat the generated `class_CandidateStringQueue.cpp` file as Wave3 materialization of STL helper code.
- Keep the source-facing container field with [UID:0000K5][IMEPanes](by-file/IMEPanes.md), likely as an `IMECandidatePane` member.
- Keep the temporary candidate-list construction with [UID:0000K6][InputMan](by-file/InputMan.md).
- The helper ranges themselves are tracked as ignored STL/template support in [UID:0000VN][-ignored](by-memory/-ignored.md), while the caller methods remain product code that must be reconstructed.
- [UID:000003][-ignored](by-class/-ignored.md) also records this generated class identity as ignored with replacement ownership in IMEPanes/InputMan, matching this page's `RECONSTRUCTABLE:FALSE` and blank emitter state.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | Documents the ignored generated-class disposition, source-facing replacement owners, exact helper starts, append/range/reserve/clear method inventory, fresh append decompilation, STL deque/wstring layout evidence, IME/InputMan caller split, by-class ignored-ledger entry, and memory/template support links. Still below final audit because the exact source-facing typedef/member spelling and all IME candidate-string field names remain open. |
| Confidence | 90 | Strong from fresh IDA function bounds/decompile, existing helper pages, ignored-ledger consistency, and Dinkumware deque/wstring allocation behavior. Capped below final audit because the original container typedef/member names are inferred rather than recovered. |

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md)
- [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md)
- [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md)
- [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)

## Changes

- 2026-06-14 A003 Goal 2 low-score by-class refresh:
  - Raised completion/confidence from `80/88` to `85/90`.
  - Evidence: live IDA MCP reconfirmed helper starts/sizes at `0x004e8450`, `0x004e8860`, `0x004e8a00`, and `0x004e9710`; decompilation of `0x004e9710` confirms deque growth, `0x18`-byte wide-string slot allocation, move into the tail slot, inline-empty reset, and caller xrefs from `InputMan::HandleWindowMessage`.
  - Routing: retained `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters because this is an ignored generated STL helper identity, not a handwritten NexusTK class.

- What existed before: the page documented the STL deque/wstring helper interpretation and reconstruction warning, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: range-copy, map-growth, clear, append, overflow string, and IME caller evidence support the template-instantiation interpretation; final source-facing typedef/member names remain open, and this should not be reconstructed as a handwritten product class.
- What existed before: the generated class record was still listed as reconstructable in metadata/coverage even though the page said it should not become a handwritten product class.
- What it was changed to: `RECONSTRUCTABLE:FALSE`, scores were refined to `80/88`, and exact helper subrange pages were linked from the method table.
- Summary and evidence: 2026-05-31 IDA MCP reverified the helper starts, caller graph, decompiled allocation/string behavior, and `deque<T> too long` overflow helper. This supports ignoring the standalone class identity while keeping the source-facing container semantics with IME/InputMan owners.
