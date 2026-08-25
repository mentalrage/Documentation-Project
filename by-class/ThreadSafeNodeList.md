*** UID:0000EX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ThreadSafeNodeList

## Summary

`ThreadSafeNodeList` is a historical generated class-name alias for an intrusive singly linked push-front operation protected by an embedded `CRITICAL_SECTION`. The body pushes a node at the front of the list if the node pointer is non-null.

The same machine-code behavior is exact public [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) free-list return because `PoolAllocator` stores `m_freeList` at `+0x0c` and `m_lock` at `+0x10`. The standalone class identity is rejected for reconstruction; this UID remains an ignored alias only.

## Likely Original Placement

- Historical alias index: [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md), path `NONE`.
- Physical source path: none; do not create `util/ThreadSafeNodeList.cpp` or a corresponding header.
- Disposition: ignored as a standalone class; exact source is `PoolAllocator::Free` through UID000153 -> UID000152 -> UID0000AM -> [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
- Confidence: strong for exact allocator ownership and behavior; the standalone class identity is rejected.

## Methods

- `0x004b14c0-0x004b14ef`: `PushFront`.

## Evidence

- 2026-05-26 IDA confirms `0x004b14c0` as a function start with size `0x2f`.
- 2026-05-26 IDA MCP recheck decompiles the whole body as: null-check the block, enter the critical section at `this + 0x10`, store old head `this + 0x0c` into `block[0]`, replace the head with the block, then leave the critical section.
- IDA `lookup_funcs` confirms the neighboring allocator island as real functions: constructor/init `0x004b13d0` size `0x30`, allocate `0x004b1400` size `0xb8`, free/push helper `0x004b14c0` size `0x2f`, destructor/cleanup `0x004b1520` size `0x65`, and chunk helper `0x00549bd0` size `0x21`.
- Generated source shows the head pointer at `this + 0x0c` and the embedded `CRITICAL_SECTION` beginning at `this + 0x10`.
- Caller fan-in spans allocator-backed object, pane, motion, user-pane, and string-buffer release paths rather than proving a separate list owner.
- String release helpers call the same function at `0x00583322`, `0x0058333d`, `0x00583358`, `0x00583373`, `0x005833d2`, `0x005833ed`, `0x00583408`, and `0x00583423`, matching `PoolAllocator::Free` for the eight string-buffer pools.
- The standalone class record is now listed in [UID:000003][-ignored](by-class/-ignored.md); this ignores only the generated class identity, not the reconstructable function at `0x004b14c0`.

## Closed Questions

- No current non-allocator object proves this layout as a true standalone list helper; all confirmed callers are PoolAllocator returns.
- Generated metadata lifted a shape-compatible list push into a standalone class alias; that alias is historical search vocabulary, not source identity.
- No separate constructor, destructor, declaration, CPP, H, or source-tree path is assigned.

## Cross-References

- File: [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md)
- Memory: [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md)
- Related: [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md), [UID:000079][List](by-class/List.md), [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md)

## Changes

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Closed the standalone placement and open-question language, linked the exact UID000153 Free body and PoolAllocator source route, and retained `-1/-1`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, and blank formal channels.
  - Preserved the class name only as a historical generated alias.

- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page was already excluded from score queues as a generated class identity, but class autogen still reported it as unclassified.
  - After: the standalone `ThreadSafeNodeList` class identity is explicitly non-reconstructable; the underlying function remains tracked through [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) and [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md).
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_4B14C0` at `0x004b14c0` (`0x2f` bytes) and caller fan-in consistent with allocator/free-list use, not proof of a standalone class declaration.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:-1` and `CONFIDENCE:-1`.
- Summary/evidence: this page documents an ignored standalone generated class identity; the reconstructable code remains tracked through `PoolAllocator`/by-memory, so this alias page should not stay in the low-score work queue.
