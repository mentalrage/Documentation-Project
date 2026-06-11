*** UID:0000TM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringBufferSentinelsAndPools

## Status

- Confidence: strong for addresses, sentinel/pool roles, and allocation/release relationships; medium for final source symbol names.
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

## Evidence

- 2026-06-07 live IDA MCP recheck counted 23 refs to the wide sentinel at `0x00670278` and 16 refs to the ANSI sentinel at `0x00670290`. The top ref groups are the string construction/assignment/COW helpers near `0x00582a90-0x005839c0`, with release helpers `0x005833a0` and `0x005832f0` each contributing six sentinel checks.
- 2026-06-07 A007 live IDA MCP recheck confirms the exact sentinel/whitespace child bytes around `0x00670268-0x00670294`: wide sentinel header, `0x00670278 -> 0x00670274`, `0x0067027c -> 0x0062d5d8`, ANSI sentinel header, and `0x00670290 -> 0x0067028c`, ending before the `NUMBER.EPF` TimerPane resource string at `0x00670294`.
- The whitespace target at `0x0062d5d8` decodes as UTF-16 `" \t\n\r"` and is referenced only through the `0x0067027c` pointer slot; the pointer has exactly eight direct refs grouped in `0x004918e0`, `0x0053f830`, `0x00570c80`, and `0x00588800`.
- The same recheck confirmed the eight string-pool xref pattern. Each pool has exactly one static constructor wrapper, one allocation helper, one release helper, and one cleanup wrapper: wide pools use `0x00582e30` / `0x005833a0`, while ANSI pools use `0x00582d80` / `0x005832f0`.
- Representative constructor/cleanup pairs are `0x0041a260` / `0x0060c430` for the wide 64 pool at `0x0069bacc` and `0x0041a240` / `0x0060c420` for the ANSI 64 pool at `0x0069bb6c`; the remaining six pools follow the same ordered 128/256/512 bucket pattern.
- Function-size checks keep the buffer helpers bounded: `AllocateAnsiBuffer` at `0x00582d80` is `0xac` bytes, `AllocateWideBuffer` at `0x00582e30` is `0xb2` bytes, and both release helpers at `0x005832f0` and `0x005833a0` are `0xa2` bytes.
- 2026-06-07 A002 Batch 078 IDA MCP recheck reconfirmed the exact sentinel/whitespace bytes and counts for memory child [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md): `23` wide-sentinel refs, `16` ANSI-sentinel refs, `8` whitespace-pointer refs, `0x0067027c -> 0x0062d5d8`, and successor `aNumberEpf` at `0x00670294`.
- 2026-06-08 A006 Batch135 live IDA MCP parent-gate refresh reconfirmed the same counts: `23` refs to `0x00670278`, `16` refs to `0x00670290`, `8` refs to `0x0067027c`, and `4` refs each to the eight string pool storage records from `0x0069bacc` through `0x0069bbe4`. The key owner helper boundaries also still match the string-buffer core: `0x00582d80`/`0x00582e30` allocation, `0x005832f0`/`0x005833a0` release, and `0x00583720`/`0x00583840` formatting workers.

## Ownership Notes

Some current aliases place these globals under `LObject`, but they belong to the string-buffer implementation rather than the true `LObject` runtime shell. Keep the string-specific sentinel, trim, and pool storage declarations with [UID:0000OA][StringBase](by-file/StringBase.md). [UID:0000OB][StringUtil](by-file/StringUtil.md) remains the broad utility-string coordinator, and [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns only the allocator mechanics used by the pool globals.

## Assignment Gate

This page now attaches to [UID:0000OA][StringBase](by-file/StringBase.md). The child is `92/89`, the direct parent is `88/86`, and the by-structure relationship is direct: the sentinels, trim-whitespace pointer, and eight small-buffer pool objects are source-level static data consumed by the `0x00582500-0x00584d7d` ref-counted ANSI/UTF-16 `StringBase` implementation.

Do not route this page to [UID:0000OB][StringUtil](by-file/StringUtil.md) or [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md). `StringUtil` is the broader utility-string coordinator and still owns separate `SimpleUString`/formatting utility surfaces. `PoolAllocator` owns the fixed-block allocator methods and layout, but the concrete string pool instances are string-buffer storage declarations.

This page remains the direct grouped-global evidence anchor for [UID:000289][0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer](by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md): it owns the exact wide/ANSI sentinel pointer slots and the adjacent wide-trim whitespace pointer as one string-infrastructure global-data cluster. It also remains the grouped-global evidence anchor for [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md), which contains the eight 40-byte pool-storage records listed above.

## Cross-References

- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0002AN][0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage](by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md)

## Changes

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
