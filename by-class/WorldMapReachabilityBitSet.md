*** UID:0000GA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WorldMapReachabilityBitSet

## Status

- Disposition: non-emitting documentation facade for old MSVC/Dinkumware `std::vector<bool>` specialization behavior, not a handwritten NexusTK class.
- Confidence: very strong for helper behavior, exact boundaries, callers, 16-byte storage layout, standard-library identity, and rebuild disposition.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), with exact generated `vector<bool>` helper children.
- Evidence basis: live IDA MCP disassembly/decompilation on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Class Purpose

`WorldMapReachabilityBitSet` is a historical documentation label for old MSVC/Dinkumware `std::vector<bool>` specialization bodies used by `WorldMapPane`. It is not an original source class and must not emit a custom declaration or implementation.

One persistent bitset object is the 16-byte `std::vector<bool> m_reachableNodes` at `WorldMapPane + 0x274`: dword-buffer pointer at `+0x00`, current/end pointer at `+0x04`, capacity/end pointer at `+0x08`, and bit count at `+0x0c`. The same representation is used for `m_adjacency` at `+0x264` and local visited state. Helpers use iterator pairs made from a dword pointer plus a bit offset in `0..31`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ReserveBits` | [UID:0003SX][0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits](by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md) | Reserves/grows backing dword storage for bit insertion. |
| position helper | [UID:0003T0][0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper](by-memory/0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md) | Computes/supports bitset iterator positions for insertion. |
| resolver helper | [UID:0003T1][0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator](by-memory/0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md) | Resolves bit iterators for range movement. |
| `InsertBits` | [UID:0003T4][0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits](by-memory/0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md) | Inserts a run of bits and returns the iterator just past the inserted range. |
| `ShrinkToBitCount` | [UID:0003T5][0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount](by-memory/0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md) | Shrinks storage/state after moving copied bit ranges. |
| `EndBitIterator` | [UID:0003T9][0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator](by-memory/0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md) | Converts the bit count at `+0x0c` into a `{dword*, bitOffset}` iterator, handling negative offsets with the same signed math as the move helper. |
| `MoveBitRange` | [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md) | Compacts a source bit range onto a destination range and shrinks the bitset to the copied tail. |

## Evidence Notes

- B001 WorldMapPane executable split on 2026-06-16 created exact by-memory children for the reserve/position/resolve/insert/shrink/end/move helpers and separated [UID:0003T6][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) as non-emitting STL runtime support.
- Live IDA confirms `sub_5C56A0` as `0x005c56a0-0x005c584b`, `sub_5C5AD0` as `0x005c5ad0-0x005c5b18`, and `sub_5C5B20` as `0x005c5b20-0x005c5c87`.
- `BuildReachabilityData` at `0x005c4bd0-0x005c5075` is the direct caller: `0x005c4cb9` calls `MoveBitRange` with `ecx = this + 0x274`, then `0x005c4cd5` calls `InsertBits` on the same bitset storage.
- `InsertBits` computes an insertion bit position as `bitOffset + 32 * ((dwordPtr - begin) >> 2)`, checks `0x7fffffff - bitCount` before growth, calls reserve/grow helper `0x005c53d0`, shifts existing bits through two `EndBitIterator` calls, increments the bit count at `+0x0c`, and writes the inserted run using `bts`/`btr` depending on the fill byte argument.
- `EndBitIterator` reads the buffer pointer at `+0x00` and bit count at `+0x0c`, returns `{begin + 4 * (bitCount >> 5), bitCount & 0x1f}` for non-negative counts, and has the matching signed-negative path used by the range-move code.
- `MoveBitRange` resolves destination/source iterators through `0x005c55e0`, copies bits one by one from the source iterator to the destination iterator, calls shrink helper `0x005c5850` with the copied-tail bit count, and returns the destination iterator after compaction.
- These are generated standard-container operations reached by normal source expressions such as `vector<bool>::assign`, indexing, insertion, and erase/move. Their semantic context remains [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md), but their binary bodies are regenerated by the selected compiler/runtime.

## Source Disposition And Rebuild Handling

- Keep this page and exact children as binary-behavior documentation under semantic source owner [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
- Keep `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, and a blank managed C++ block. No custom class, alias wrapper, handwritten reserve/iterator/insert/shrink/erase body, or separate source file should be emitted.
- Source-facing WorldMapPane members are `std::vector<bool> m_adjacency` at `+0x264` and `std::vector<bool> m_reachableNodes` at `+0x274`; UID0003SR also uses local `std::vector<bool> visitedNodes`.
- UID0003SR invokes the observed move/insert bodies as the compiler expansion of `m_reachableNodes.assign(nodeCount, false)`, then accesses bits through ordinary `operator[]` expressions.
- The runtime diagnostic [UID:0003T6][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) was already false/non-emitting and remains verify-only.
- Historical custom-type naming is retained only to avoid path/UID churn and preserve earlier evidence; it is explicitly rejected as source proof.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- [UID:0003SX][0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits](by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md)
- [UID:0003T4][0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits](by-memory/0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md)
- [UID:0003T9][0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator](by-memory/0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md)
- [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md)

## Changes

- 2026-07-14 B004 UID0003SR callback:
  - What existed before: `86/89`, reconstructable/emitting custom private-bitset hypothesis with blank C++ and unresolved original type name.
  - Changed to: `91/94`, false/non-emitting documentation facade over old-MSVC `std::vector<bool>`, retaining the complete 16-byte layout, helper boundaries/call flow, and WorldMapPane semantic context.
  - Summary/evidence: UID0003SR's `assign` expansion, local backing-word construction, standard length diagnostic, iterator representation, and independent UID0001B2/UID0003T6 support close the source disposition. Ordinary `std::vector<bool>` source regenerates these bodies.

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the reachability bitset insert, end-iterator, and range-move helper starts at `0x005c56a0`, `0x005c5ad0`, and `0x005c5b20`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the private reachability-bitset purpose, insert/move helper mapping, `BuildReachabilityData` caller evidence, storage-layout note, and final-name caveat.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification.
  - Before: the page relied on a stale recovered-file path and did not show the disassembly evidence for the 16-byte layout, iterator representation, bit-count field, or exact reachability-builder call sequence.
  - After: the page records exact helper boundaries, the `WorldMapPane + 0x274` storage offset, bitset field layout, direct builder call sites at `0x005c4cb9` and `0x005c4cd5`, growth/insert behavior, end-iterator helper behavior, and move/shrink behavior.
  - Evidence: live IDA confirms `sub_5C56A0`, `sub_5C5AD0`, `sub_5C5B20`, and caller `sub_5C4BD0`; `CodeRefsTo(0x005c56a0)` reports `0x005c4cd5`, `CodeRefsTo(0x005c5b20)` reports `0x005c4cb9`, and the decompiled builder uses `this + 0x274` for both calls. Scores remain below final reconstruction because the source-facing helper type name is still descriptive rather than recovered.
- 2026-06-16 B001 WorldMapPane executable split:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`; helper evidence was documented but several private bitset helpers lacked exact child pages.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`; added exact children for reserve, position, resolve, insert, shrink, end-iterator, and move helpers, plus non-emitting STL throw-helper context.
  - Summary/evidence: B001 confirmed boundaries, caller/callee graph, `WorldMapPane + 0x274` storage use, `DirectDrawCreate` successor boundary after [UID:0003TA][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md), and lack of independent helper-file evidence. Confidence remains below final source quality because the original private type name is descriptive.
