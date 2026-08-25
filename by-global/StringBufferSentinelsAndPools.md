*** UID:0000TM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PoolAllocator.h"

namespace mystr {

struct StringBaseAnsiEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    char data[1];
};

struct StringBaseWideEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    wchar_t data[1];
};

static StringBaseWideEmptySentinelStorage g_emptyWideStringStorage = {
    { -1, 0, 0 },
    { L'\0' }
};

static StringBaseAnsiEmptySentinelStorage g_emptyAnsiStringStorage = {
    { -1, 0, 0 },
    { '\0' }
};

wchar_t *g_emptyWideString = g_emptyWideStringStorage.data;
char *g_emptyAnsiString = g_emptyAnsiStringStorage.data;

static const wchar_t g_wideTrimWhitespaceChars[] = L" \t\n\r";

PoolAllocator g_widePool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(wchar_t), 64);
PoolAllocator g_widePool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(wchar_t), 64);

PoolAllocator g_ansiPool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(char), 64);
PoolAllocator g_ansiPool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(char), 64);

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StringBufferSentinelsAndPools

## Status

- Confidence: strong for addresses, sentinel/pool roles, allocation/release relationships, and first-draft source declarations; medium-high for exact original symbol spellings.
- Direct owner: [UID:0000OA][StringBase](by-file/StringBase.md). [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broader utility-string coordinator, and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns allocator mechanics rather than these string-specific static declarations.
- Entity kind: grouped global-data documentation

## Role

The ref-counted ANSI/UTF-16 string implementation uses two shared empty-string sentinels and eight fixed-capacity `PoolAllocator` instances. Constructors attach empty strings to the sentinels, small non-empty strings allocate from the bucket pools, and release paths return small buffers to the matching pool after the 12-byte string header refcount reaches zero.

These eight pools are the confirmed string-buffer pool family. They should not be mistaken for the full PoolAllocator inventory; see [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for the object-pane, `Motion`, `UserPane`, and string-pool inventory.

## Empty Sentinels

| Address | Name surface | Use |
| --- | --- | --- |
| `0x00670278` | `Src`, `g_emptyWideBuffer`, `g_emptyWideString` | Shared empty UTF-16 data/header sentinel. |
| `0x00670290` | `off_670290`, `g_emptyAnsiBuffer`, `g_emptyAnsiString` | Shared empty ANSI data/header sentinel. |

IDA xrefs show broad use from the `0x00582500+` string construction, assignment, COW, allocation, and release helpers.

## Trim Whitespace Pointer

| Address | Name surface | Use |
| --- | --- | --- |
| `0x0067027c` | `off_67027C`, proposed `g_wideTrimWhitespaceChars` | Pointer to the UTF-16 whitespace set at `0x0062d5d8`, decoded as `" \t\n\r"`. |

The exact memory child [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md) keeps the two empty sentinel headers/self-pointers and this trim whitespace pointer together because they are physically adjacent and all participate in the string infrastructure. The whitespace pointer is used by four two-reference call-site groups at `0x004918e0`, `0x0053f830`, `0x00570c80`, and `0x00588800`; each group passes the same set to the wide trim-left and trim-right helpers around `0x00583e70` and `0x00583f70`.

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
- [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md): formal allocation/grow/detach users. `AllocateAnsiBuffer` and `AllocateWideBuffer` consume all eight 64/128/256/512 pool globals and the two empty sentinels; `GrowAnsiBuffer` and `GrowWideBuffer` compare against the empty sentinels before allocating; `DetachAnsiIfShared` and `DetachWideIfShared` allocate same-length replacement storage and release the old pointer through the release users below.
- [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md): direct sentinel users in share-or-copy initialization, empty initialization, and assignment. `ShareOrCopyAnsiFromStringBase`, `InitializeEmptyAnsi`, and `AssignAnsiFromStringBase` reference `g_emptyAnsiString`; `ShareOrCopyWideFromStringBase`, `InitializeEmptyWide`, and `AssignWideFromStringBase` reference `g_emptyWideString`. The target also delegates allocation/release to the helper users listed above.
- [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md): target-local trim and lock users. The four trim caller groups pass `0x0067027c` / `g_wideTrimWhitespaceChars` to `TrimLeftWide` and `TrimRightWide`; `LockAnsiBuffer` compares against `0x00670290`, and `LockWideBuffer` compares against `0x00670278` before marking non-sentinel buffers writable.

## Evidence

- 2026-06-07 live IDA MCP recheck counted 23 refs to the wide sentinel at `0x00670278` and 16 refs to the ANSI sentinel at `0x00670290`. The top ref groups are the string construction/assignment/COW helpers near `0x00582a90-0x005839c0`, with release helpers `0x005833a0` and `0x005832f0` each contributing six sentinel checks.
- 2026-06-07 A007 live IDA MCP recheck confirms the exact sentinel/whitespace child bytes around `0x00670268-0x00670294`: wide sentinel header, `0x00670278 -> 0x00670274`, `0x0067027c -> 0x0062d5d8`, ANSI sentinel header, and `0x00670290 -> 0x0067028c`, ending before the `NUMBER.EPF` TimerPane resource string at `0x00670294`.
- The whitespace target at `0x0062d5d8` decodes as UTF-16 `" \t\n\r"` and is referenced only through the `0x0067027c` pointer slot; the pointer has exactly eight direct refs grouped in `0x004918e0`, `0x0053f830`, `0x00570c80`, and `0x00588800`.
- The same recheck confirmed the eight string-pool xref pattern. Each pool has exactly one static constructor wrapper, one allocation helper, one release helper, and one cleanup wrapper: wide pools use `0x00582e30` / `0x005833a0`, while ANSI pools use `0x00582d80` / `0x005832f0`.
- Representative constructor/cleanup pairs are `0x0041a260` / `0x0060c430` for the wide 64 pool at `0x0069bacc` and `0x0041a240` / `0x0060c420` for the ANSI 64 pool at `0x0069bb6c`; the remaining six pools follow the same ordered 128/256/512 bucket pattern.
- Function-size checks keep the buffer helpers bounded: `AllocateAnsiBuffer` at `0x00582d80` is `0xac` bytes, `AllocateWideBuffer` at `0x00582e30` is `0xb2` bytes, and both release helpers at `0x005832f0` and `0x005833a0` are `0xa2` bytes.
- 2026-06-07 A002 Batch 078 IDA MCP recheck reconfirmed the exact sentinel/whitespace bytes and counts for memory child [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md): `23` wide-sentinel refs, `16` ANSI-sentinel refs, `8` whitespace-pointer refs, `0x0067027c -> 0x0062d5d8`, and successor `aNumberEpf` at `0x00670294`.
- 2026-06-08 A006 Batch135 live IDA MCP parent-gate refresh reconfirmed the same counts: `23` refs to `0x00670278`, `16` refs to `0x00670290`, `8` refs to `0x0067027c`, and `4` refs each to the eight string pool storage records from `0x0069bacc` through `0x0069bbe4`. The key owner helper boundaries also still match the string-buffer core: `0x00582d80`/`0x00582e30` allocation, `0x005832f0`/`0x005833a0` release, and `0x00583720`/`0x00583840` formatting workers.
- 2026-06-25 B003 [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) refresh on current MCP session `80de0a67` reconfirmed these globals from the release/capacity target itself. `ReleaseAnsiBuffer` compares and resets through `0x00670290`, then returns capacities 64/128/256/512 to `0x0069bb6c`, `0x0069bb94`, `0x0069bbbc`, and `0x0069bbe4`; `ReleaseWideBuffer` compares and resets through `0x00670278`, then returns capacities 64/128/256/512 to `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, and `0x0069bb44`. MCP `xrefs_to` still reports 23 refs to the wide sentinel, 16 refs to the ANSI sentinel, and exactly four refs for each of the eight pool globals: constructor, allocation, release, and cleanup.
- 2026-06-25 B006 [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) refresh on current MCP session `80de0a67` confirms target-local empty-sentinel references. `g_emptyAnsiString` / `0x00670290` is referenced at `0x005829f3`, `0x00582a80`, and `0x00582bb3`; `g_emptyWideString` / `0x00670278` is referenced at `0x00582a93`, `0x00582b20`, and `0x00582c63`. These are share-or-copy, empty-initializer, and assignment sentinels, not pool-allocation mechanics, so ownership stays with [UID:0000OA][StringBase](by-file/StringBase.md) while allocator mechanics stay with [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md).
- 2026-06-26 B005 [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) refresh on current MCP session `80de0a67` confirms direct allocation/grow/COW use of these globals. `g_emptyAnsiString` / `0x00670290` is referenced by `AllocateAnsiBuffer` and `GrowAnsiBuffer`; `g_emptyWideString` / `0x00670278` is referenced by `AllocateWideBuffer` and `GrowWideBuffer`. ANSI allocation consumes `0x0069bb6c`, `0x0069bb94`, `0x0069bbbc`, and `0x0069bbe4`; wide allocation consumes `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, and `0x0069bb44`. The target's detach helpers use the same globals indirectly by allocating replacement storage and releasing the old pointer through [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md).
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) refresh on current MCP session `80de0a67` ties `0x0067027c` to the four two-call trim-left/right caller groups at `0x004918e0`, `0x0053f830`, `0x00570c80`, and `0x00588800`. The same target confirms the lock helpers' sentinel refs: `LockAnsiBuffer` checks `0x00670290` and `LockWideBuffer` checks `0x00670278` before writing `refCount = 1` for non-sentinel buffers.
- 2026-06-30 B011 current MCP session `supervisor_resume_20260629` rechecked this empty-emitter family: `xrefs_to` still reports 23 refs to `0x00670278`, 16 refs to `0x00670290`, 8 refs to `0x0067027c`, and exactly four refs for each pool global from `0x0069bacc` through `0x0069bbe4` (static constructor, allocator, release, cleanup). `get_bytes 0x00670268` confirms the two sentinel headers/self-pointers and the trim pointer before the `NUMBER.EPF` successor string, `get_bytes 0x0062d5d8` decodes UTF-16 `" \t\n\r"`, and `get_bytes 0x0069bacc size 0x140` shows zero-filled loader storage before constructors. The formal C++ block now emits the source declarations for the two empty sentinel storage records, two exported data pointers, trim whitespace literal, and eight StringBase-specific `PoolAllocator` instances.

## Ownership Notes

Some current aliases place these globals under `LObject`, but they belong to the string-buffer implementation rather than the true `LObject` runtime shell. Keep the string-specific sentinel, trim, and pool storage declarations with [UID:0000OA][StringBase](by-file/StringBase.md). [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broad utility-string coordinator, and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns only the allocator mechanics used by the pool globals.

## Assignment Gate

This page now attaches to [UID:0000OA][StringBase](by-file/StringBase.md). The child is `93/91`, the direct parent is `91/90`, and the by-structure relationship is direct: the sentinels, trim-whitespace pointer, and eight small-buffer pool objects are source-level static data consumed by the `0x00582500-0x00584d7d` ref-counted ANSI/UTF-16 `StringBase` implementation.

Do not route this page to [UID:0000OB][StringUtil](by-file/StringUtil.md) or [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md). `StringUtil` is the broader utility-string coordinator and still owns separate `SimpleUString`/formatting utility surfaces. `PoolAllocator` owns the fixed-block allocator methods and layout, but the concrete string pool instances are string-buffer storage declarations.

This page remains the direct grouped-global evidence anchor for [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md): it owns the exact wide/ANSI sentinel pointer slots and the adjacent wide-trim whitespace pointer as one string-infrastructure global-data cluster. It also remains the grouped-global evidence anchor for [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md), which contains the eight 40-byte pool-storage records listed above.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md)
- [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md)
- [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md)
- [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md)
- [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md)
- [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md)

## Changes

- 2026-06-30 B011 [UID:0000OA][StringBase](by-file/StringBase.md) empty-emitter implementation:
  - Before: `COMPLETION:92`, `CONFIDENCE:89`, formal C++ blank.
  - After: `COMPLETION:93`, `CONFIDENCE:91`, formal C++ populated with source-level sentinel, whitespace, and eight pool declarations.
  - Summary/evidence: incorporated accepted B011 report `0000OA-StringBase-empty-emitter-family-source-quality.md`. Current MCP session `supervisor_resume_20260629` confirms the sentinel and trim bytes at `0x00670268-0x00670294`, the UTF-16 whitespace literal at `0x0062d5d8`, zero-filled pool storage at `0x0069bacc-0x0069bc0c` before static constructors, constructor wrappers at `0x0041a180` through `0x0041a260`, cleanup wrappers at `0x0060c3c0` through `0x0060c430`, and the four-ref constructor/allocation/release/cleanup pattern for each pool. [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) and [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md) remain exact memory evidence pages and route their formal comments through this global page rather than duplicating source declarations.
- 2026-06-26 B005 [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence that [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) consumes both empty sentinels and all eight string pool globals directly from allocation/grow helpers, while detach helpers allocate replacement storage and release the old storage through [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md). Ownership remains [UID:0000OA][StringBase](by-file/StringBase.md) for string-specific globals and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) for allocator mechanics.
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence that `0x0067027c` / `g_wideTrimWhitespaceChars` feeds four two-call trim-left/right caller groups and that the ANSI/wide empty sentinels are directly used by `LockAnsiBuffer` and `LockWideBuffer`. Ownership remains [UID:0000OA][StringBase](by-file/StringBase.md); the new evidence extends sentinel/trim usage, not allocator mechanics.
- 2026-06-25 B006 [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added target-local empty-sentinel evidence from current MCP session `80de0a67`: ANSI sentinel refs at `0x005829f3`, `0x00582a80`, and `0x00582bb3`, and wide sentinel refs at `0x00582a93`, `0x00582b20`, and `0x00582c63`. This supports [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) while preserving [UID:0000OA][StringBase](by-file/StringBase.md) ownership for string-specific globals and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) ownership for allocator mechanics.
- 2026-06-25 B003 [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` release/capacity evidence from [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md). The target confirms the two empty sentinel paths, 64/128/256/512 ANSI and wide pool return paths, four-ref constructor/allocation/release/cleanup pattern for each pool, and preserves [UID:0000OA][StringBase](by-file/StringBase.md) ownership for string-specific declarations while [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns allocator mechanics.
- 2026-06-20 B004 Rule 26 support update:
  - Changed support wording only; score unchanged.
  - Summary/evidence: updated the stale [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) link to the renamed [0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) container. The sentinel/pool interpretation is unchanged: these globals are string-specific static data under [UID:0000OA][StringBase](by-file/StringBase.md).
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents sentinel storage, pool globals, initialization/destruction helpers, allocation users, layout refs, and ownership correction away from `LObject`; final symbol names remain provisional.
- 2026-06-05: Marked reconstructable and left parent attachment blank.
  - Reason: the sentinels and fixed string-buffer pools are source-declared data, but final ownership is still split between `StringUtil`, allocator mechanics, and a possible `StringBase` source root.
- 2026-06-07: Grading changed from `88/82` to `90/86`.
  - Before: page documented the pool/sentinel family and ownership correction, but confidence was limited by stale xref evidence and uncertain assignment candidates.
  - After: score reflects live sentinel ref counts, exact four-xref pattern for each string pool, allocation/release helper boundaries, and explicit no-parent rationale under the corrected gate.
- 2026-06-07 A007 Batch 031 parent-gate update:
  - Changed to: `COMPLETION:91`, `CONFIDENCE:88`.
  - Summary/evidence: added the adjacent wide-trim whitespace pointer at `0x0067027c`, its UTF-16 target `" \t\n\r"`, its four two-use trim call-site groups, exact sentinel/whitespace child bytes, and direct grouped-global ownership for the exact memory child [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md).
- 2026-06-07 A003 Batch 055:
  - Changed to: added [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) as the exact pool-storage memory child for the eight pool records already listed in this page.
  - Score impact: no score change; the page was already `91/88`, and this edit records the direct child relationship used by the corrected `85/85` assignment gate.
- 2026-06-07 A002 Batch 078 coverage-error repair:
  - Score impact: no score change.
  - Summary/evidence: refreshed the assignment gate after generated memory coverage rejected by-global parent UID `0000TM` for memory child [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md). The child now leaves `AUTOGEN_PARENT_UID` blank while this page remains the semantic evidence anchor; `StringUtil` is `85/88` but broad/coordinating, `StringBase` is still `88/80`, and `PoolAllocator` is still `86/80`, so no single direct source-file parent is justified.
- 2026-06-07 A005 Batch 079 coverage-error repair:
  - Score impact: no score change; parent metadata remains blank.
  - Summary/evidence: applied the same generated-coverage decision to exact pool-storage child [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md). That child now leaves `AUTOGEN_PARENT_UID` blank while this page remains the grouped-global evidence anchor for the eight 40-byte string-buffer pool records.
- 2026-06-08 A006 Batch135 parent-gate repair:
  - Before: `COMPLETION:91`, `CONFIDENCE:88`, no `AUTOGEN_PARENT_UID`.
  - After: `COMPLETION:92`, `CONFIDENCE:89`, `AUTOGEN_PARENT_UID:0000OA`.
  - Summary/evidence: raised [UID:0000OA][StringBase](by-file/StringBase.md) to `88/86` after a live IDA parent-gate refresh. The sentinel/pool globals are now attached to `StringBase.cpp` because they are string-specific static data used by the verified allocation, release, format, and trim helpers; `StringUtil` remains a broad coordinator and `PoolAllocator` remains allocator mechanics only.

## 2026-08-22 UID0000MM Accepted Implementation Callback

The formal source now supplies the allocator constructor's required second argument for every string-buffer pool. All eight pools use a 64-record chunk policy; the first argument remains the header plus terminating payload capacity.

| Pool | Exact storage range | Exact constructor arguments | Exact current direct xrefs |
|---|---|---|---|
| P11 `g_widePool64` | `0x0069bacc-0x0069baf4` | `sizeof(RefCountedStringBufferHeader) + (64 + 1) * sizeof(wchar_t), 64` (binary `0x8e, 0x40`) | `0x0041a267, 0x00582e50, 0x005833cd, 0x0060c430` |
| P12 `g_widePool128` | `0x0069baf4-0x0069bb1c` | `sizeof(RefCountedStringBufferHeader) + (128 + 1) * sizeof(wchar_t), 64` (binary `0x10e, 0x40`) | `0x0041a1a7, 0x00582e6b, 0x005833e8, 0x0060c3d0` |
| P13 `g_widePool256` | `0x0069bb1c-0x0069bb44` | `sizeof(RefCountedStringBufferHeader) + (256 + 1) * sizeof(wchar_t), 64` (binary `0x20e, 0x40`) | `0x0041a1e7, 0x00582e86, 0x00583403, 0x0060c3f0` |
| P14 `g_widePool512` | `0x0069bb44-0x0069bb6c` | `sizeof(RefCountedStringBufferHeader) + (512 + 1) * sizeof(wchar_t), 64` (binary `0x40e, 0x40`) | `0x0041a227, 0x00582ea1, 0x0058341e, 0x0060c410` |
| P15 `g_ansiPool64` | `0x0069bb6c-0x0069bb94` | `sizeof(RefCountedStringBufferHeader) + (64 + 1) * sizeof(char), 64` (binary `0x4d, 0x40`) | `0x0041a244, 0x00582da0, 0x0058331d, 0x0060c420` |
| P16 `g_ansiPool128` | `0x0069bb94-0x0069bbbc` | `sizeof(RefCountedStringBufferHeader) + (128 + 1) * sizeof(char), 64` (binary `0x8d, 0x40`) | `0x0041a187, 0x00582dbb, 0x00583338, 0x0060c3c0` |
| P17 `g_ansiPool256` | `0x0069bbbc-0x0069bbe4` | `sizeof(RefCountedStringBufferHeader) + (256 + 1) * sizeof(char), 64` (binary `0x10d, 0x40`) | `0x0041a1c7, 0x00582dd6, 0x00583353, 0x0060c3e0` |
| P18 `g_ansiPool512` | `0x0069bbe4-0x0069bc0c` | `sizeof(RefCountedStringBufferHeader) + (512 + 1) * sizeof(char), 64` (binary `0x20d, 0x40`) | `0x0041a207, 0x00582df1, 0x0058336e, 0x0060c400` |

The accepted isolated-TX prestate for each row is forty zero bytes fragmented into one-byte undefined items, with no address comments and no field-interior xrefs. Supervisor Gate 2B owns the future one-item `PoolAllocator` materialization, source-facing name, and regular comment. This page remains the sole formal declaration route through [UID:0000OA][StringBase](by-file/StringBase.md); [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md) is evidence-only and must not duplicate the declarations.

- Score change: `93/91 -> 94/94`.
- Reason: the formal source now matches the proved two-argument constructor contract for all eight records and retains exact storage, xref, ownership, and non-duplication evidence.
