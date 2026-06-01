*** UID:0000IR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Deque

## Status

- Proposed module: `util/Deque.cpp`
- Proposed header: `util/Deque.h`
- Confidence: strong for utility ownership, medium for exact original source filename.
- Current recovered source: `source-3/simroot_v2/class_Deque.cpp`
- Primary class: [UID:00003P][Deque](by-class/Deque.md)

## File Role

`Deque.cpp` is the likely shared implementation for a small block-based deque that stores 4-byte entries. It uses a power-of-two block map, four entries per allocated block, a front index, and a count. Current callers use it as stack-local traversal queues, handler traversal state, and directory-scan work storage.

This is generic infrastructure. It should not be owned by EventDispatcher, FolderTreePane, MapPane, WorldMapPane, or SoundManager even though those subsystems call into it.

## Likely Contents

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- raw-entry cleanup: `0x00439e00-0x00439ea3`
- growth/reblock helper: `0x0043e0b0-0x0043e241`
- push-back helper: `0x004a88e0-0x004a8965`
- element-address helper: `0x0054c0c0-0x0054c110`
- non-owning clear helper: `0x0054c160-0x0054c1f1`
- ownership-aware entry cleanup: `0x0057b9e0-0x0057baa3`

## Evidence

- `class_Deque.meta_wave3` imports `Deque` from Wave2 with summary: a 4-byte queue entry container using 4-slot blocks and wrap-safe growth.
- IDA MCP confirms all five active/emitted method starts and sizes.
- IDA caller checks show broad fan-in from EventDispatcher internals, FolderTreePane traversal helpers, MapPane paths, WorldMapPane reachability construction, and SoundManager music-directory scanning.
- 2026-05-31 IDA MCP decompilation corrects the shared layout to `+0x00` auxiliary owned pointer/storage slot, `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count. Generated `class_Deque.cpp` is useful as a lead but is not authoritative for the first field offset.
- A 2026-05-25 IDA MCP recheck identifies `0x0054c0c0` as a 0x50-byte element-address helper: it computes the block-map slot and in-block offset for a 4-byte element. Active `class_Deque.cpp` does not currently emit this helper.
- A 2026-05-26 recheck confirms active `class_Deque.cpp` still omits `0x0054c0c0`; IDA still reports no modeled callers, with the only xref coming from raw `PrimeNumberGenerator::GetPrimeAt` code at `0x0054bce1`.
- A 2026-05-31 IDA MCP recheck confirms the current boundaries for `0x00439e00-0x00439ea3`, `0x0043e0b0-0x0043e241`, `0x004a88e0-0x004a8966`, `0x0054c0c0-0x0054c110`, `0x0054c160-0x0054c1f1`, and `0x0057b9e0-0x0057baa3`. Xrefs still fan into event traversal, folder-tree/map/world-map style callers, prime-table helper code, and SoundManager cleanup, supporting shared utility ownership rather than feature ownership.

## Source-Structure Decision

Use `util/Deque.cpp` as the current source-module hypothesis. It belongs beside [UID:0000KS][List](by-file/List.md), [UID:0000N8][RingBuffer](by-file/RingBuffer.md), and other utility containers, not inside a feature source file.

The final original name may have been a local container helper rather than literally `Deque.cpp`, because the Wave2 import source is `recovered\Deque.cpp`. Until stronger original-source evidence appears, `util/Deque.cpp` is the most useful reconstruction target.

## Generated Output Caveats

- Active `class_Deque.cpp` is good behavioral evidence but uses modernized generated style (`std::uint32_t`, `nullptr`) rather than likely original VC6/VC7-era code style.
- The five methods are non-contiguous in the binary, so do not create one broad migration memory range around them.
- `DestroyOwnedEntries` has SoundManager-specific current caller evidence, but the method behavior is still a generic ownership-aware deque cleanup variant.
- `0x0054c0c0` is physically adjacent to `PrimeNumberGenerator`, but its body is generic Deque layout arithmetic. Keep the raw `PrimeNumberGenerator` accessor at `0x0054bcc0` with `PrimeNumberGenerator`; keep this helper with Deque/container support.

## Cross-References

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md)
- [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md)
- [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md)
- [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md)
- [UID:0000MQ][PrimeNumberGenerator](by-file/PrimeNumberGenerator.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)

## Changes

- 2026-05-27: Existing `Deque::Destroy` range used `0x00439e00-0x00439ea2`. Changed it to `0x00439e00-0x00439ea3`. Evidence: read-only IDA MCP reports `sub_439E00` as `0x00439e00-0x00439ea3`, size `0xa3`; the corresponding by-memory page [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) records the boundary correction.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: shared utility-container role, likely contents, caller fanout, source-structure decision, generated-output caveats, non-contiguous method refs, and boundary correction are documented; confidence is medium-high because utility ownership is strong but exact original filename/folder remains uncertain.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `Deque.cpp` under `util/`, and the 2026-05-31 IDA MCP recheck confirms the documented Deque helpers remain shared non-feature-specific container support.
- 2026-05-31 layout evidence correction:
  - What existed before: the evidence section said active generated `class_Deque.cpp` showed the shared layout as `m_blockMap`, `m_blockCount`, `m_frontIndex`, and `m_count`, which could imply `blockMap` starts at `+0x00`.
  - Changed to: the evidence section now records the IDA-confirmed layout with `+0x00` auxiliary pointer/storage, `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count, and treats generated source as a lead only.
  - Summary/evidence: IDA MCP decompilation of Deque cleanup, growth, push, and ownership-aware cleanup helpers consistently proves the corrected offsets.
