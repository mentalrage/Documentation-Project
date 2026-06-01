*** UID:0001U2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DequeLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for offsets `+0x04` through `+0x10`, medium for the exact semantic name of `+0x00` and final original type names.
- Proposed owner: [UID:0000IR][Deque](by-file/Deque.md)
- Evidence basis: 2026-05-31 IDA MCP decompilation of `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries`, plus `lookup_funcs` boundary checks for the Deque helper cluster.

## Layout

```text
DequeLayout
  +0x00  void* auxiliaryStorageOrAllocatorSlot
  +0x04  uint32_t** blockMap
  +0x08  uint32_t blockCount
  +0x0c  uint32_t frontIndex
  +0x10  uint32_t count
```

Observed object size is at least `0x14` bytes.

`+0x00` is not the block map. IDA shows `Destroy` at `0x00439e00` and `DestroyOwnedEntries` at `0x0057b9e0` freeing `*(void**)this` after block-map cleanup, while `Clear` at `0x0054c160` leaves it untouched. Treat it as an auxiliary owned pointer or allocator/storage slot until callers and construction sites identify the exact source-level name.

## Storage Model

- Each allocated block stores four 4-byte entries.
- `blockCount` is grown as a power of two.
- Logical slot mask is `blockCount * 4 - 1`.
- Physical block index is `(logicalIndex >> 2) & (blockCount - 1)`.
- Entry index within a block is `logicalIndex & 3`.
- The non-emitted helper at `0x0054c0c0` implements this exact address calculation for a 4-byte element.

`EnsureCapacity` copies old logical order into a new block map and resets `frontIndex` to zero.

## Cleanup Variants

- `Destroy` and `Clear` free blocks and the block map without interpreting payloads. `Destroy` also frees and clears `+0x00`; `Clear` does not.
- `DestroyOwnedEntries` releases ref-counted string entries before freeing storage. Current caller evidence ties this variant to [UID:0000NV][SoundManager](by-file/SoundManager.md) directory-scan storage.
- `DestroyOwnedEntries` also frees and clears `+0x00` after block-map cleanup.

## IDA Evidence

- `0x00439e00` (`Destroy`) reads and decrements count at `+0x10`, resets front index at `+0x0c` when the last entry is removed, iterates block count at `+0x08`, frees blocks through the block map at `+0x04`, then frees and clears `+0x00`.
- `0x0043e0b0` (`EnsureCapacity`) reads block count at `+0x08`, front index at `+0x0c`, old block map at `+0x04`, installs the new block map at `+0x04`, and increases block count at `+0x08`.
- `0x004a88e0` (`PushBack`) reads count at `+0x10`, front index at `+0x0c`, block count at `+0x08`, and block map at `+0x04`; it allocates 16-byte blocks, writes one 4-byte entry, and increments `+0x10`.
- `0x0054c160` (`Clear`) uses the same `+0x04/+0x08/+0x0c/+0x10` block-map fields and leaves `+0x00` alone.
- `0x0057b9e0` (`DestroyOwnedEntries`) walks entries using `+0x04/+0x08/+0x0c/+0x10`, calls the owned-entry release helper on each entry, then frees blocks, block map, and `+0x00`.

## Open Questions

- Exact source-level meaning/name of `+0x00`.
- Whether the original declaration was a concrete project-local class, a small helper nested in a source file, or a template-like container specialized to 4-byte entries.

## Cross-References

- [UID:00003P][Deque](by-class/Deque.md)
- [UID:0000IR][Deque](by-file/Deque.md)
- [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md)
- [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)

## Changes

- 2026-05-31 layout correction:
  - What existed before: the page listed `+0x00` as `blockMap`, `+0x04` as `blockCount`, `+0x08` as `frontIndex`, and `+0x0c` as `count`, with object size at least `0x10`.
  - Changed to: `+0x00` auxiliary owned pointer/storage slot, `+0x04` block map, `+0x08` block count, `+0x0c` front index, `+0x10` count, with object size at least `0x14`.
  - Summary/evidence: IDA MCP decompilation of `Destroy`, `EnsureCapacity`, `PushBack`, `Clear`, and `DestroyOwnedEntries` consistently uses `+0x04/+0x08/+0x0c/+0x10` for the deque block-map state; `Destroy` and `DestroyOwnedEntries` separately free `*(void**)this`, proving `+0x00` is not the block map.
- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: the core layout and cleanup/growth semantics are now IDA-verified, but the exact `+0x00` semantic name, original type declaration style, and any constructor/initializer sites remain incomplete.
