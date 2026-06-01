*** UID:00003P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Deque

## Summary

`Deque` is a reusable 4-byte-entry deque backed by a power-of-two block map. Each block stores four entries. The container grows by allocating a larger block map and copying entries from the old logical order into contiguous new logical order.

Current evidence shows it is used as a lightweight work queue rather than a UI list or domain-specific collection.

## Likely Original Placement

- Source: [UID:0000IR][Deque](by-file/Deque.md)
- Proposed path: `util/Deque.cpp`
- Confidence: medium for filename, strong for utility ownership.

## Layout

See [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md).

```text
+0x00  void* auxiliaryStorageOrAllocatorSlot
+0x04  uint32_t** blockMap
+0x08  uint32_t blockCount
+0x0c  uint32_t frontIndex
+0x10  uint32_t count
```

## Methods

| Address | Name | Role |
| --- | --- | --- |
| `0x00439e00-0x00439ea3` | `Destroy` | Frees allocated blocks and the block map, then resets state. |
| `0x0043e0b0-0x0043e241` | `EnsureCapacity` | Grows the power-of-two block map and reorders logical entries. |
| `0x004a88e0-0x004a8965` | `PushBack` | Ensures capacity, allocates the target block if needed, and appends one 4-byte entry. |
| `0x0054c0c0-0x0054c110` | `ElementAddress` / `GetAtAddress` | Computes the address of a 4-byte element from `frontIndex + index`; currently not emitted in active `class_Deque.cpp`. |
| `0x0054c160-0x0054c1f1` | `Clear` | Frees all blocks/map and resets state without owned-entry cleanup. |
| `0x0057b9e0-0x0057baa3` | `DestroyOwnedEntries` | Pops entries and releases ref-counted string payloads before freeing storage. |

## Evidence

- IDA MCP decompilation on 2026-05-31 confirms the layout used by `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries`: `+0x04` block map, `+0x08` block count, `+0x0c` front index, and `+0x10` count.
- IDA MCP also shows `Destroy` and `DestroyOwnedEntries` freeing `*(void**)this` after block-map cleanup, while `Clear` leaves that slot untouched; the `+0x00` field is therefore an auxiliary owned pointer/storage slot, not the block map.
- Active generated `class_Deque.cpp` remains useful as a behavioral lead, but its simplified layout naming must not override the IDA-confirmed `+0x00/+0x04/+0x08/+0x0c/+0x10` offsets.
- `class_Deque.meta_wave3` records this as a Wave2-imported class with manual grade 97.3 and notes use by stack-local traversal queues and SoundManager.
- IDA MCP confirms all five active/emitted method boundaries.
- IDA caller fan-in crosses EventDispatcher, FolderTreePane, MapPane, WorldMapPane, and SoundManager, supporting utility placement.
- IDA MCP confirms `0x0054c0c0` as an additional 0x50-byte helper; its raw known caller is `PrimeNumberGenerator::GetPrimeAt` at `0x0054bcc0`.
- 2026-05-26 recheck: active `class_Deque.cpp` still omits `0x0054c0c0`, and IDA still sees the helper only through the raw `0x0054bce1` code reference.

## Open Questions

- Whether the original source used the final class name `Deque`, a project-local helper name, or a template-like private helper.
- Whether there were additional pop/front/back helpers inlined at call sites or still unmodeled elsewhere in the binary. `0x0054c0c0` confirms at least one non-emitted element-address helper exists.

## Cross-References

- File: [UID:0000IR][Deque](by-file/Deque.md)
- Layout: [UID:0001U2][DequeLayout](by-type/by-struct/DequeLayout.md)
- Memory: [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:0001IE][0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries](by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md)
- Related: [UID:000079][List](by-class/List.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-27: Existing `Destroy` method range used `0x00439e00-0x00439ea2`. Changed it to `0x00439e00-0x00439ea3`. Evidence: read-only IDA MCP reports `sub_439E00` as `0x00439e00-0x00439ea3`, size `0xa3`; the corresponding by-memory page [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) records the boundary correction.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/82`.
  - Summary/evidence: layout, reusable-utility placement, core methods, omitted element-address helper, caller fan-in, related containers, and endpoint correction are documented; remaining work is exact original class/template naming and possible additional inlined helpers.
- 2026-05-31 layout and reconstructability correction:
  - Before: the class page mirrored a stale four-field layout beginning with `blockMap` at `+0x00`, and `RECONSTRUCTABLE` was blank.
  - After: the layout now records `+0x00` as an auxiliary owned pointer/storage slot, shifts block map/count/front/count to `+0x04/+0x08/+0x0c/+0x10`, raises confidence to `86`, and marks `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: 2026-05-31 IDA MCP decompilation of `0x00439e00`, `0x0043e0b0`, `0x004a88e0`, `0x0054c160`, and `0x0057b9e0` consistently proves the corrected offsets; `Destroy` and `DestroyOwnedEntries` separately free `+0x00`.
