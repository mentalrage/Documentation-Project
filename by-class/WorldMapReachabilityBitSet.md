*** UID:0000GA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapReachabilityBitSet

## Status

- Confidence: strong for helper behavior, exact method boundaries, caller context, storage layout, and route-state ownership; medium only for final original type name.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- Evidence basis: live IDA MCP disassembly/decompilation on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.

## Class Purpose

`WorldMapReachabilityBitSet` is a private dynamic bitset used by `WorldMapPane::BuildReachabilityData`. It stores reachability flags while scanning the world-map graph from the current node.

The bitset object is the 16-byte storage at `WorldMapPane + 0x274`: dword-buffer pointer at `+0x00`, current/end pointer at `+0x04`, capacity/end pointer at `+0x08`, and bit count at `+0x0c`. The helpers use iterator pairs made from a dword pointer plus a bit offset in the range `0..31`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InsertBits` | `0x005c56a0-0x005c584b` | Inserts a run of bits and returns the iterator just past the inserted range. |
| `EndBitIterator` | `0x005c5ad0-0x005c5b18` | Converts the bit count at `+0x0c` into a `{dword*, bitOffset}` iterator, handling negative offsets with the same signed math as the move helper. |
| `MoveBitRange` | `0x005c5b20-0x005c5c87` | Compacts a source bit range onto a destination range and shrinks the bitset to the copied tail. |

## Evidence Notes

- Live IDA confirms `sub_5C56A0` as `0x005c56a0-0x005c584b`, `sub_5C5AD0` as `0x005c5ad0-0x005c5b18`, and `sub_5C5B20` as `0x005c5b20-0x005c5c87`.
- `BuildReachabilityData` at `0x005c4bd0-0x005c5075` is the direct caller: `0x005c4cb9` calls `MoveBitRange` with `ecx = this + 0x274`, then `0x005c4cd5` calls `InsertBits` on the same bitset storage.
- `InsertBits` computes an insertion bit position as `bitOffset + 32 * ((dwordPtr - begin) >> 2)`, checks `0x7fffffff - bitCount` before growth, calls reserve/grow helper `0x005c53d0`, shifts existing bits through two `EndBitIterator` calls, increments the bit count at `+0x0c`, and writes the inserted run using `bts`/`btr` depending on the fill byte argument.
- `EndBitIterator` reads the buffer pointer at `+0x00` and bit count at `+0x0c`, returns `{begin + 4 * (bitCount >> 5), bitCount & 0x1f}` for non-negative counts, and has the matching signed-negative path used by the range-move code.
- `MoveBitRange` resolves destination/source iterators through `0x005c55e0`, copies bits one by one from the source iterator to the destination iterator, calls shrink helper `0x005c5850` with the copied-tail bit count, and returns the destination iterator after compaction.
- This is private world-map route-state infrastructure and should migrate with [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md).

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)

## Changes

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
