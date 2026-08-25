*** UID:0000OS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ThreadSafeNodeList

## Status

- Source path: none. This UID is a non-emitting historical alias, not a standalone original source file.
- Header path: none. No exported `ThreadSafeNodeList` type is reconstructed.
- Disposition: ignored as a standalone generated source-file candidate; keep as an alias page for `PoolAllocator::Free` / locked intrusive push behavior.
- Confidence: strong for the historical behavior alias and closed PoolAllocator ownership; standalone file/class ownership is rejected.

## File Role

`ThreadSafeNodeList` is a historical generated name for a small intrusive-list operation protected by an embedded `CRITICAL_SECTION`. The body pushes a non-null node at the head while holding the lock.

The source split is closed for reconstruction: exact address `0x004b14c0-0x004b14ef` is public `PoolAllocator::Free`, nested under the PoolAllocator core and emitted into `NexusTK/util/PoolAllocator.cpp`. The lock-protected intrusive description remains useful only as dated search vocabulary. This page owns no CPP, H, class declaration, or physical source-tree path.

## Likely Contents

- [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md) generated alias
- node struct with `next` at offset `0`
- embedded `CRITICAL_SECTION` around offset `0x10`
- behavior alias for `PoolAllocator::Free` / free-list return at `0x004b14c0`

## Evidence

- 2026-05-26 IDA MCP confirms `0x004b14c0-0x004b14ef` as a real function.
- 2026-05-26 IDA MCP recheck confirms the local allocator island: `0x004b13d0` (`0x30` bytes), `0x004b1400` (`0xb8` bytes), `0x004b14c0` (`0x2f` bytes), `0x004b1520` (`0x65` bytes), and `0x00549bd0` (`0x21` bytes).
- IDA decompilation of `0x004b14c0` is exactly a free-list push: null-check the node, lock `this + 0x10`, link the node through its first dword to old `this + 0x0c`, update `this + 0x0c`, unlock.
- Generated source shows `PushFront` checking null, entering the embedded critical section, linking the node at `this + 0x0c`, and leaving the critical section.
- IDA caller fan-in spans string-buffer, object-pane, Motion, and UserPane pool return paths. That cross-subsystem set proves shared PoolAllocator mechanics rather than a feature-specific owner or standalone list class.
- IDA decompilation of the neighboring [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) family shows the same offsets are `PoolAllocator::freeList` and `PoolAllocator::lock`.
- IDA xrefs from `ReleaseAnsiBuffer` at `0x005832f0` and `ReleaseWideBuffer` at `0x005833a0` call `0x004b14c0` for string-buffer pool returns, which strongly supports the `PoolAllocator::Free` interpretation at those call sites.
- The standalone file candidate is now listed in [UID:0000HD][-ignored](by-file/-ignored.md); ignore only the generated one-class source split, not the underlying reconstructable allocator code.

## Source-Structure Decision

Do not create `util/ThreadSafeNodeList.cpp` or a corresponding header/class declaration. Keep this page at path `NONE`, owner `NONE`, and `-1/-1` as a non-emitting historical alias. [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md) emits `PoolAllocator::Free` through [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md), [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md), and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).

## Cross-References

- [UID:0000EX][ThreadSafeNodeList](by-class/ThreadSafeNodeList.md)
- [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- 2026-08-22 B001 UID0000MM Gate 2A ordinary repair:
  - Closed the active source split, retired `class_ThreadSafeNodeList.cpp` as historical generated output, and placed the exact PoolAllocator Free route and no-path/no-header disposition in Status, File Role, Evidence, Source-Structure Decision, and Changes.
  - Preserved the generated alias as dated search vocabulary without assigning it source ownership.

- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was blank even though the page is excluded from score queues and documented as a generated alias, so file coverage still reported it as an error.
  - After: the page remains `-1/-1` and non-standalone; no `ThreadSafeNodeList.cpp` generated root should be emitted.
  - Evidence: live IDA MCP `lookup_funcs` confirms `sub_4B14C0` at `0x004b14c0` (`0x2f` bytes), and `callers` shows allocator/string-buffer and UI/object helper fan-in consistent with the documented locked intrusive free-list push alias owned by [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
- 2026-05-30: Excluded this generated-alias page from completion/confidence stats.
  - Before: completion/confidence metadata was ungraded at `0/0`, which placed the page in low-score work queues.
  - After: set completion and confidence to `-1/-1`.
- Evidence: the page disposition says it is ignored as a standalone generated source-file candidate and should remain an alias/warning for `PoolAllocator::Free` locked intrusive-list behavior, not a primary reconstruction target.
