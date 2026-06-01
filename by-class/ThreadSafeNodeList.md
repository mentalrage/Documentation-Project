*** UID:0000EX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ThreadSafeNodeList

## Summary

`ThreadSafeNodeList` is a generated class-name alias for an intrusive singly linked push-front operation protected by an embedded `CRITICAL_SECTION`. The recovered method pushes a node at the front of the list if the node pointer is non-null.

The same machine-code behavior is strongly valid as [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) free-list return because `PoolAllocator` stores `freeList` at `+0x0c` and its lock at `+0x10`. Current evidence does not prove a standalone original `ThreadSafeNodeList` class.

## Likely Original Placement

- Source: [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md)
- Proposed path: alias only unless later evidence proves `util/ThreadSafeNodeList.cpp` or a broader utility-list source.
- Disposition: ignored as a standalone class; reconstruct the code through [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md) unless later non-allocator evidence proves a real class owner.
- Confidence: strong that `0x004b14c0` is real project code, strong for allocator ownership at proven call sites, weak for standalone `ThreadSafeNodeList` class identity.

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

## Open Questions

- Whether any non-allocator object embeds the same layout and calls this function as a true list helper.
- Whether generated metadata lifted a helper method into a standalone class because the machine code is shape-compatible with a list push.
- Constructor/destructor ownership if a real standalone list class is later found.

## Cross-References

- File: [UID:0000OS][ThreadSafeNodeList](by-file/ThreadSafeNodeList.md)
- Memory: [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md)
- Related: [UID:0000AM][PoolAllocator](by-class/PoolAllocator.md), [UID:000079][List](by-class/List.md), [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:-1` and `CONFIDENCE:-1`.
  - Summary/evidence: this page documents an ignored standalone generated class identity; the reconstructable code remains tracked through `PoolAllocator`/by-memory, so this alias page should not stay in the low-score work queue.
