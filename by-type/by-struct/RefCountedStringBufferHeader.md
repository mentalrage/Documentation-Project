*** UID:0001VQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RefCountedStringBufferHeader

## Status

- Type kind: inferred struct/layout.
- Direct owner: [UID:0000OA][StringBase](by-file/StringBase.md), with [UID:0000OB][StringUtil](by-file/StringUtil.md) as the broader utility-string coordinator.
- Confidence: strong for 12-byte header shape and `StringBase.cpp` source placement; medium-high for exact signedness and final nested/helper type name.
- Verification basis: IDA MCP `lookup_funcs` and decompilation of allocation, release, empty-sentinel, sharing, and copy-on-write helpers on 2026-05-31. Generated Wave3/simroot data is not used as authority for this score.

## Layout

The ref-counted string implementation stores metadata immediately before the returned character data pointer:

| Offset from data pointer | Field | Notes |
| --- | --- | --- |
| `-0x0c` | `refCount` | Updated with `InterlockedIncrement` and `InterlockedDecrement`; negative values appear to mean non-shareable/static. |
| `-0x08` | `length` | Current character count, not including terminator. |
| `-0x04` | `capacity` | Allocated capacity or pool bucket size. |
| `0x00` | data | ANSI `char[]` or UTF-16 `wchar_t[]`, followed by a terminator. |

## Allocation Model

- Empty strings use shared sentinels at `0x00670278` for wide strings and `0x00670290` for ANSI strings.
- Small buffers use fixed [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) pools for 64/128/256/512 capacity buckets.
- Larger buffers use heap allocation with the same header prefix.
- Assignment and append paths use copy-on-write: shared buffers are retained by incrementing `refCount`; mutating paths detach when `refCount > 1`.

## Assignment Gate

This layout page now attaches to [UID:0000OA][StringBase](by-file/StringBase.md). The child is `86/88`, the direct parent is `88/86`, and the by-structure relationship is direct because this 12-byte header is the internal source-level buffer prefix used throughout the `StringBase` allocation, release, copy-on-write, format, append, trim, and compare helpers.

Do not attach this header to [UID:0000OB][StringUtil](by-file/StringUtil.md) or [UID:0000D9][SimpleUString](by-class/SimpleUString.md) under current evidence. Those pages remain important coordination/facade docs, but the actual direct implementation owner for this ref-counted buffer prefix is the dedicated `StringBase` source root.

## Evidence

- `class_LObject.cpp` methods from `0x005829f0` through `0x005833a0` repeatedly derive the header by subtracting 12 bytes from the data pointer.
- `AllocateAnsiBuffer` at `0x00582d80` writes `refCount`, `length`, `capacity`, then returns `header + 3` as the data pointer.
- `ReleaseAnsiBuffer` and `ReleaseWideBuffer` at `0x005832f0` and `0x005833a0` free by bucket capacity after decrementing the header refcount.
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) records exact sentinel and pool addresses.

## IDA Verification Notes

- `lookup_funcs 0x00582d80` reports size `0xac`; decompilation selects ANSI bucket pools or heap allocation, writes `header[0] = 1`, `header[1] = requestedLength`, `header[2] = capacity`, writes the `char` terminator at `header + 0x0c + length`, and stores `header + 0x0c` as the returned data pointer.
- `lookup_funcs 0x00582e30` reports size `0xb2`; decompilation performs the same header writes for UTF-16 buffers and writes a `wchar_t` terminator at `header + 0x0c + 2 * length`.
- `lookup_funcs 0x005832f0` and `0x005833a0` report size `0xa2` each; decompilation compares against the ANSI/wide empty sentinels, calls `InterlockedDecrement(data - 0x0c)`, reads capacity at `data - 0x04`, and either returns the header to the matching [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) bucket or frees the heap block.
- `lookup_funcs 0x005829f0` reports size `0x58`; decompilation increments `refCount` at `data - 0x0c` when the incoming buffer is shareable, otherwise allocates/copies a private buffer.
- `lookup_funcs 0x00582a80` and `0x00582b20` report ten-byte empty-initializer helpers that assign the ANSI and wide empty sentinel pointers directly.
- 2026-06-08 A006 Batch135 live IDA MCP refresh reconfirmed the parent-gate evidence: `0x00582d80` and `0x00582e30` remain the ANSI/wide allocation helpers with exact sizes `0xac` and `0xb2`; `0x005832f0` and `0x005833a0` remain the release twins with exact size `0xa2`; `0x005845b0` still reads the wide stored length at `data - 0x08` before calling the range comparator.
- The same decompile refresh showed allocator paths writing `header[1] = requestedLength` and `header[2] = capacity`, release paths subtracting 12 bytes from `data`, decrementing `data - 0x0c`, and switching on `capacity` to return storage to the matching `0x0069ba..`/`0x0069bb..` pool.

## Cross-References

- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md)
- [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `86`.
- Evidence: IDA MCP verified the 12-byte header layout through ANSI/wide allocation, release, empty-sentinel, sharing, and copy-on-write helpers. Scores remain below `95+` because final type names, exact signedness, complete owner-file placement, and the entire neighboring string-method family still need a full final-source audit.
- 2026-06-08 A006 Batch135 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, no `AUTOGEN_PARENT_UID`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000OA`.
  - Summary/evidence: live IDA reconfirmed allocation/release helper boundaries, header writes, `InterlockedDecrement(data - 0x0c)`, `data - 0x08` length use, pool-capacity switching, and [UID:0000OA][StringBase](by-file/StringBase.md) as the direct source parent after that file reached `88/86`.
