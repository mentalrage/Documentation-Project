*** UID:0001WO | DO NOT MODIFY OR REMOVE!!! ***
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

# Candidate String Deque Template

## Status

- Entity kind: inferred MSVC/Dinkumware STL template instantiation.
- Current generated class name: [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md)
- Source-level owner: [UID:0000K5][IMEPanes](by-file/IMEPanes.md) and [UID:0000K6][InputMan](by-file/InputMan.md) use the container; the helper implementation should come from the C++ standard library/compiler, not handwritten NexusTK source.
- Rebuild handling: not a NexusTK-owned class/template body. Reconstruct product source as ordinary `std::deque<std::wstring>`-style usage in the owning IME/InputMan code.
- Confidence: very strong for `std::deque<std::wstring>` shape, standard-library-helper classification, ignored-ledger alignment, and IME/InputMan consumer split; medium-high for the exact source-facing typedef/member name.
- Evidence basis: IDA MCP lookup, decompile, disassembly, and caller checks re-verified on 2026-05-31. Wave3/simroot names were treated as provisional.

## Interpretation

The generated `CandidateStringQueue` class is best modeled as a concrete `std::deque<std::wstring>` or equivalent Dinkumware deque template instantiation used for IME candidate strings.

This is not a standalone product class that should become `CandidateStringQueue.cpp` in the rebuilt source tree. The product code should instead express normal container fields and local variables in `IMECandidatePane` / `InputMan`, letting the compiler emit the deque/string helper code.

## Binary Layout Model

Deque object fields observed in the IME candidate paths:

| Offset | Meaning |
| --- | --- |
| `+0x00` | container proxy pointer; construction allocates an 8-byte proxy and stores a back-pointer to the deque object. |
| `+0x04` | map / slot table pointer, effectively `CandidateStringEntry**`. |
| `+0x08` | map slot count. |
| `+0x0c` | head / offset index in the circular map. |
| `+0x10` | active element count. |

Each element is a 0x18-byte wide string object:

| Offset | Meaning |
| --- | --- |
| `+0x00` | inline `wchar_t[8]` storage or heap `wchar_t*`. |
| `+0x10` | character length. |
| `+0x14` | capacity; inline capacity is `7`, heap storage is used when capacity is `>= 8`. |

The 0x18-byte element layout is consistent with an MSVC `std::wstring` / `std::basic_string<wchar_t>` SSO-7 representation. Keep this separate from the project-local [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md), which uses a ref-counted pointer-backed layout.

## Helper Ranges

| Range | Generated name | Template role |
| --- | --- | --- |
| [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md) | `CandidateStringQueue::AssignRange` | Clears destination deque and range-copies candidate strings from a source deque/map range. |
| [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md) | `CandidateStringQueue::ReserveAdditional` | Grows the deque map/slot table, preserving wrapped segments. |
| [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md) | `CandidateStringQueue::Clear` | Releases string element storage and deque map slots. |
| [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md) | `CandidateStringQueue::AppendOwnedString` | Moves a prepared `std::wstring` entry into the next deque slot, equivalent to append/push-back support. |

These exact helper ranges are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md) as STL template support. The surrounding IME pane methods and scalar deleting destructors remain reconstructable product code.

## Evidence Notes

- IDA MCP `disasm 0x0043f190` pushes the literal `deque<T> too long`; `xrefs_to 0x0060f0a8` reaches that helper and `callers 0x0043f190` includes `0x004e89e8` inside [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md).
- IDA MCP `lookup_funcs` rechecked the exact helper boundaries on 2026-05-31: `0x004e8450` size `0x15e`, `0x004e8860` size `0x192`, `0x004e8a00` size `0xe6`, and `0x004e9710` size `0x93`.
- IDA decompilation of [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md) shows map growth with `operator new(4 * slotCount)`, `memmove`, `memset`, a 0x1000 large-allocation threshold, 32-byte alignment, and raw-pointer recovery from `alignedPointer[-1]`, matching MSVC/Dinkumware container allocation code.
- IDA decompilation of [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md) and [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md) shows 0x18-byte elements with inline capacity `7`, heap threshold `>= 8`, and large-allocation validation on string buffer release.
- IDA xrefs show [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md) copies candidate strings through the range-assign helper, while [UID:0000K6][InputMan](by-file/InputMan.md) builds candidate-string entries and appends them during IMM candidate-list message handling.
- `IMECandidatePane` construction initializes the embedded deque object at offset `+0xf8`, including the 8-byte container proxy/back-pointer pattern.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reported `NexusTK.exe` ready with Hex-Rays available, then reconfirmed helper starts and sizes: `0x004e8450` `0x15e`, `0x004e8860` `0x192`, `0x004e8a00` `0xe6`, and `0x004e9710` `0x93`.
- Live `xrefs_to` on `0x004e9710` returned exactly two code xrefs, both from `InputMan::HandleWindowMessage` neighborhood `0x004e8de0` at `0x004e91a6` and `0x004e9234`. Live `xrefs_to` on `0x004e8860` returned exactly the range-assign helper at `0x004e8493` and append helper at `0x004e9726`.
- Live `analyze_function 0x004e9710` confirmed append/move semantics: grow through `0x004e8860` when the deque map has insufficient slots, allocate a `0x18` element when the target slot is empty, copy the prepared wide-string object into the target slot, reset the source string to inline-empty state with capacity `7`, and increment the deque count.
- [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) now independently records the same 2026-06-14 evidence at `85/90`, and `by-type/by-template/-ignored.md` records this page as the ignored template artifact with replacement ownership in [UID:0000K5][IMEPanes](by-file/IMEPanes.md) and [UID:0000K6][InputMan](by-file/InputMan.md).

## Reconstruction Guidance

- In `IMECandidatePane`, model the member as a candidate string container, likely `std::deque<std::wstring>` or a typedef/local alias for that type.
- In `InputMan::HandleWindowMessage`, model temporary candidate-list construction with ordinary wide strings and deque append operations.
- Do not create or migrate an original `CandidateStringQueue.cpp` product file unless later evidence finds handwritten behavior outside the STL helper ranges.
- Keep `RECONSTRUCTABLE:FALSE` for this template artifact unless later evidence proves a NexusTK-owned wrapper/template body exists. This page documents the source-facing container interpretation, not final C++ code to autogenerate.
- Preserve the exact binary helper ranges in memory documentation for address mapping, trace comparison, and decompiler-name cleanup.

## Score Rationale

Completion is `85` because the page now documents the ignored/replacement-source classification, exact helper inventory, deque object and string element layouts, live append/range/reserve caller split, `deque<T> too long` overflow evidence, IME/InputMan source consumers, and matching class/ignored-ledger disposition. Confidence is `90` because the standard-library materialization is supported by live IDA helper bounds, decompilation, caller xrefs, allocation behavior, and the local ignored ledger; it remains below final-audit range because the original source-facing typedef/member spelling is still inferred rather than recovered.

## Cross-References

- [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md)
- [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md)
- [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md)
- [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)
- [UID:0000VN][-ignored](by-memory/-ignored.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-14 A002 Goal2 by-type score refresh:
  - What existed before: the page was `78/88`; it correctly classified the helper body as ignored STL support but did not yet carry the newer live append-helper evidence, class-page support, or ignored-ledger alignment in its score rationale.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, retaining `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters.
  - Summary/evidence: live IDA MCP reconfirmed the four helper starts/sizes, exact append and reserve xrefs, and append/move decompilation; [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) and the local template ignored ledger now agree that this is standard-library `std::deque<std::wstring>` support to express through IMEPanes/InputMan source containers, not a NexusTK-owned template body.
- What existed before: the page had useful standard-library template research but was still scored `0/0`, had blank reconstructability metadata, and pointed three helper roles only at the broad mixed `0x004e8450-0x004e8ae6` range.
- What it was changed to: scores were set to `78/88`, `RECONSTRUCTABLE:FALSE`, and exact helper-range links were added for assign, reserve, and clear.
- Summary and evidence: 2026-05-31 IDA MCP rechecked boundaries, callers, decompilation, and the `deque<T> too long` helper. The evidence supports a Dinkumware/MSVC `std::deque<std::wstring>` helper artifact used by reconstructable IME/InputMan code, not a NexusTK-owned template body.
