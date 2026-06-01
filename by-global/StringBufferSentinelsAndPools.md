*** UID:0000TM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringBufferSentinelsAndPools

## Status

- Confidence: strong for addresses and string-buffer relationship, medium for final symbol names.
- Current generated owner: `source-3/simroot_v2/class_LObject.cpp`
- Proposed owner: [UID:0000OB][StringUtil](by-file/StringUtil.md), [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), or a future `StringBase.cpp`
- Entity kind: grouped global-data documentation

## Role

The ref-counted ANSI/UTF-16 string implementation uses two shared empty-string sentinels and eight fixed-capacity `PoolAllocator` instances. Constructors attach empty strings to the sentinels, small non-empty strings allocate from the bucket pools, and release paths return small buffers to the matching pool after the 12-byte string header refcount reaches zero.

These eight pools are the confirmed string-buffer pool family. They should not be mistaken for the full PoolAllocator inventory; see [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for the object-pane, `Motion`, `UserPane`, and string-pool inventory.

## Empty Sentinels

| Address | IDA/generated name surface | Use |
| --- | --- | --- |
| `0x00670278` | `Src`, `g_emptyWideBuffer`, `g_emptyWideString` | Shared empty UTF-16 data/header sentinel. |
| `0x00670290` | `off_670290`, `g_emptyAnsiBuffer`, `g_emptyAnsiString` | Shared empty ANSI data/header sentinel. |

IDA xrefs show broad use from the `0x00582500+` string construction, assignment, COW, allocation, and release helpers.

## Pool Globals

| Address | Working name | Used by |
| --- | --- | --- |
| `0x0069bacc` | `g_widePool64` | `AllocateWideBuffer`, `ReleaseWideBuffer` |
| `0x0069baf4` | `g_widePool128` | `AllocateWideBuffer`, `ReleaseWideBuffer` |
| `0x0069bb1c` | `g_widePool256` | `AllocateWideBuffer`, `ReleaseWideBuffer` |
| `0x0069bb44` | `g_widePool512` | `AllocateWideBuffer`, `ReleaseWideBuffer` |
| `0x0069bb6c` | `g_ansiPool64` | `AllocateAnsiBuffer`, `ReleaseAnsiBuffer` |
| `0x0069bb94` | `g_ansiPool128` | `AllocateAnsiBuffer`, `ReleaseAnsiBuffer` |
| `0x0069bbbc` | `g_ansiPool256` | `AllocateAnsiBuffer`, `ReleaseAnsiBuffer` |
| `0x0069bbe4` | `g_ansiPool512` | `AllocateAnsiBuffer`, `ReleaseAnsiBuffer` |

Each pool occupies `0x28` bytes and matches [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md).

## Initialization And Destruction

- Static initialization helpers at `0x0041a180`, `0x0041a1a0`, `0x0041a1c0`, `0x0041a1e0`, `0x0041a200`, `0x0041a220`, `0x0041a240`, and `0x0041a260` construct the eight pools.
- Registered cleanup helpers at `0x0060c3c0`, `0x0060c3d0`, `0x0060c3e0`, `0x0060c3f0`, `0x0060c400`, `0x0060c410`, `0x0060c420`, and `0x0060c430` destroy the same pools.
- Verified constructor examples include `0x0041a180` constructing the ANSI 128 pool with block size `141` and `0x0041a260` constructing the wide 64 pool with block size `142`.

## Allocation Users

- `0x00582d80`: `AllocateAnsiBuffer`, uses `0x00670290` for empty strings and the ANSI pool quartet for 64/128/256/512 buckets.
- `0x00582e30`: `AllocateWideBuffer`, uses `0x00670278` for empty strings and the wide pool quartet for 64/128/256/512 buckets.
- `0x005832f0`: `ReleaseAnsiBuffer`, ignores `0x00670290` and returns matching small buffers to the ANSI pools.
- `0x005833a0`: `ReleaseWideBuffer`, ignores `0x00670278` and returns matching small buffers to the wide pools.

## Ownership Notes

Current generated names place these globals under `LObject`, but they belong to the string-buffer implementation rather than the true `LObject` runtime shell. Keep them with [UID:0000OB][StringUtil](by-file/StringUtil.md) or a future `StringBase.cpp`; [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns the allocator mechanics used by the pool globals.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents sentinel storage, pool globals, initialization/destruction helpers, allocation users, layout refs, and ownership correction away from generated `LObject`; final symbol names remain provisional.
