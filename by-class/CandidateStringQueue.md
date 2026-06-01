*** UID:00001G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CandidateStringQueue

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Type interpretation: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- Address ranges: [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md) and [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)
- Current recovered file: `source-3/simroot_v2/class_CandidateStringQueue.cpp`
- Rebuild handling: generated class identity is ignored; source code should use the owning IME/InputMan containers rather than reconstructing a `CandidateStringQueue` class.
- Confidence: strong for behavior and STL deque/wstring shape; medium for final source-facing typedef/member name.

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

- What existed before: the page documented the STL deque/wstring helper interpretation and reconstruction warning, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: range-copy, map-growth, clear, append, overflow string, and IME caller evidence support the template-instantiation interpretation; final source-facing typedef/member names remain open, and this should not be reconstructed as a handwritten product class.
- What existed before: the generated class record was still listed as reconstructable in metadata/coverage even though the page said it should not become a handwritten product class.
- What it was changed to: `RECONSTRUCTABLE:FALSE`, scores were refined to `80/88`, and exact helper subrange pages were linked from the method table.
- Summary and evidence: 2026-05-31 IDA MCP reverified the helper starts, caller graph, decompiled allocation/string behavior, and `deque<T> too long` overflow helper. This supports ignoring the standalone class identity while keeping the source-facing container semantics with IME/InputMan owners.
