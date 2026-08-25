*** UID:0001VQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

struct RefCountedStringBufferHeader {
    volatile LONG refCount;
    unsigned int length;
    unsigned int capacity;
};

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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

This layout page now attaches to [UID:0000OA][StringBase](by-file/StringBase.md). The child is `90/91`, the direct parent is `91/90`, and the by-structure relationship is direct because this 12-byte header is the internal source-level buffer prefix used throughout the `StringBase` allocation, release, copy-on-write, format, append, trim, compare, search, splice, and substring helpers.

Do not attach this header to [UID:0000OB][StringUtil](by-file/StringUtil.md) or [UID:0000D9][SimpleUString](by-class/SimpleUString.md) under current evidence. Those pages remain important coordination/facade docs, but the actual direct implementation owner for this ref-counted buffer prefix is the dedicated `StringBase` source root.

## Evidence

- `class_LObject.cpp` methods from `0x005829f0` through `0x005833a0` repeatedly derive the header by subtracting 12 bytes from the data pointer.
- `AllocateAnsiBuffer` at `0x00582d80` writes `refCount`, `length`, `capacity`, then returns `header + 3` as the data pointer.
- `ReleaseAnsiBuffer` and `ReleaseWideBuffer` at `0x005832f0` and `0x005833a0` free by bucket capacity after decrementing the header refcount.
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md) records exact sentinel and pool addresses.
- [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) directly exercises all three fields. `ShareOrCopyAnsiFromStringBase` and `ShareOrCopyWideFromStringBase` read source `refCount` to choose share versus private-copy behavior, read `length` for copy size, and use `EnsureAnsiCapacity` / `EnsureWideCapacity` when non-shareable negative-refcount sources require copying. `AssignAnsiFromStringBase` and `AssignWideFromStringBase` read destination `refCount` and `capacity`, read source `refCount` and `length`, clamp private-copy counts to visible `strlen` / `wcslen`, and preserve the binary quirk where sufficient private destination storage is copied into without rewriting stored header length or terminator. `GetWideAt` reads data directly and therefore depends on the same header-backed data pointer model without touching the header itself.
- [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) directly exercises all three fields from allocation, grow, and detach paths. `AllocateAnsiBuffer` and `AllocateWideBuffer` initialize `refCount = 1`, write requested `length`, set bucket or heap `capacity`, return `header + 0x0c`, and terminate the character data. `GrowAnsiBuffer` and `GrowWideBuffer` read the old `length`, temporarily increment the old `refCount`, allocate `oldLength + additionalLength`, copy the old payload, and release the saved old pointer. `DetachAnsiIfShared` and `DetachWideIfShared` check `refCount > 1`, allocate a same-length replacement, copy the payload, and release the old shared storage.
- [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) exercises the same header from split/trim/lock helpers. `TrimLeftWide` and `TrimRightWide` read stored `refCount` and `length` to decide detach/copy and span removal, while `LockAnsiBuffer` and `LockWideBuffer` mark non-sentinel buffers with `refCount = 1` and return the data pointer without allocating, growing, or rewriting stored length/capacity. This lock behavior does not replace the documented negative-refcount private/exclusive state used by detach and assignment paths.

## IDA Verification Notes

- `lookup_funcs 0x00582d80` reports size `0xac`; decompilation selects ANSI bucket pools or heap allocation, writes `header[0] = 1`, `header[1] = requestedLength`, `header[2] = capacity`, writes the `char` terminator at `header + 0x0c + length`, and stores `header + 0x0c` as the returned data pointer.
- `lookup_funcs 0x00582e30` reports size `0xb2`; decompilation performs the same header writes for UTF-16 buffers and writes a `wchar_t` terminator at `header + 0x0c + 2 * length`.
- `lookup_funcs 0x005832f0` and `0x005833a0` report size `0xa2` each; decompilation compares against the ANSI/wide empty sentinels, calls `InterlockedDecrement(data - 0x0c)`, reads capacity at `data - 0x04`, and either returns the header to the matching [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) bucket or frees the heap block.
- 2026-06-25 B003 [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) refresh on MCP session `80de0a67` strengthens the same layout model. `GetBufferHeader` at `0x00583450` returns `m_data - 0x0c`; `ReleaseAnsiBuffer` and `ReleaseWideBuffer` decrement `refCount` at `data - 0x0c`, read `capacity` at `data - 0x04`, and reset to empty sentinels; `SetLengthAnsiAndDetach`, `SetLengthWideAndDetach`, and `MakeExclusiveWide` write `length` at `data - 0x08`, preserve/copy payloads with `memmove`, and mark private buffers `refCount = -1`. The current interpretation of negative refcount remains non-shareable/exclusive/private state, not leaked shared storage.
- `lookup_funcs 0x005829f0` reports size `0x58`; decompilation increments `refCount` at `data - 0x0c` when the incoming buffer is shareable, otherwise allocates/copies a private buffer.
- `lookup_funcs 0x00582a80` and `0x00582b20` report ten-byte empty-initializer helpers that assign the ANSI and wide empty sentinel pointers directly.
- 2026-06-25 B006 [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) refresh on current MCP session `80de0a67` strengthens the layout model from copy/share, assignment, destructor-release, literal assignment, and indexed-access paths. The target reads source and destination `refCount`, `length`, and `capacity` at data pointer `-0x0c/-0x08/-0x04`, treats negative refcount as non-shareable/private-copy state, clamps assignment copy length to the visible C-string length, and confirms that destructor wrappers are compiler scaffolding around release helpers rather than new header fields.
- 2026-06-26 B005 [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) refresh on current MCP session `80de0a67` adds allocation/grow/detach evidence. The target writes header fields in both allocation helpers, reads old `length` and `refCount` during grow, and uses `refCount > 1` plus same-length copy/release behavior for detach-if-shared. This confirms the same one-pointer data model without adding any fields beyond `refCount`, `length`, and `capacity`.
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) refresh on current MCP session `80de0a67` adds trim/lock evidence. `TrimLeftWide` and `TrimRightWide` use stored wide `length` and `refCount` before detaching/removing characters, and the ANSI/wide lock helpers at `0x00584020` and `0x00584040` compare against the empty sentinels then write `data[-3] = 1` for non-sentinel storage only.
- 2026-06-08 A006 Batch135 live IDA MCP refresh reconfirmed the parent-gate evidence: `0x00582d80` and `0x00582e30` remain the ANSI/wide allocation helpers with exact sizes `0xac` and `0xb2`; `0x005832f0` and `0x005833a0` remain the release twins with exact size `0xa2`; `0x005845b0` still reads the wide stored length at `data - 0x08` before calling the range comparator.
- The same decompile refresh showed allocator paths writing `header[1] = requestedLength` and `header[2] = capacity`, release paths subtracting 12 bytes from `data`, decrementing `data - 0x0c`, and switching on `capacity` to return storage to the matching `0x0069ba..`/`0x0069bb..` pool.

## Cross-References

- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md)
- [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md)
- [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md)
- [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md)
- [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md)
- [UID:0001W4][SimpleUStringPointerBackedLayout](by-type/by-struct/SimpleUStringPointerBackedLayout.md)
- [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- 2026-06-30 B011 [UID:0000OA][StringBase](by-file/StringBase.md) empty-emitter implementation:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`, formal C++ blank.
  - After: `COMPLETION:90`, `CONFIDENCE:91`, formal `RefCountedStringBufferHeader` declaration populated.
  - Summary/evidence: incorporated accepted B011 report `0000OA-StringBase-empty-emitter-family-source-quality.md`. The declaration records the stable 12-byte prefix used by the current StringBase helper family: `refCount` at `data[-12]`, `length` at `data[-8]`, and `capacity` at `data[-4]`. The update is supported by current MCP confirmation across suffix, formatting, comparator, wide search, splice/grow, sentinel, and pool evidence pages and by prior formal allocation/release/share/append child implementations.
- 2026-06-26 B005 [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence from [UID:0002RO][0x00582d80-0x00583132.StringBaseAllocationGrowAndCow](by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md): allocation helpers write `refCount`, `length`, and `capacity`; grow helpers read old `length`, retain old storage, allocate/copy/release; detach helpers check `refCount > 1`, allocate same-length replacement storage, copy payload, and release the old shared pointer. This strengthens the existing 12-byte header model without changing field layout or score.
- 2026-06-25 B010 [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence from [UID:0002RQ][0x00583970-0x00584052.StringBaseReplaceTrimAndLocks](by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md): trim helpers read stored `refCount` and `length`, while `LockAnsiBuffer` / `LockWideBuffer` set `refCount = 1` on non-sentinel buffers without allocating, growing, or changing length/capacity. The existing negative-refcount interpretation remains non-shareable/private state for detach and assignment paths.
- 2026-06-25 B006 [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence from [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md): share/copy and assignment helpers read `refCount`, `length`, and `capacity`; negative refcounts select private-copy behavior; assignment private-copy paths clamp to visible string length; and indexed wide access confirms the same one-pointer data model.
- 2026-06-25 B003 [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md) implementation sync:
  - Score unchanged.
  - Summary/evidence: added current MCP session `80de0a67` evidence from [UID:0002RT][0x005832f0-0x00583714.StringBaseReleaseAndCapacity](by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md): the six-byte `GetBufferHeader` accessor returns `m_data - 0x0c`, release helpers decrement `refCount` and switch on `capacity`, set-length/make-exclusive helpers update `length` and mark private storage `refCount = -1`, and the negative refcount interpretation remains non-shareable/private.
- 2026-06-20 B004 Rule 26 support update:
  - Changed support wording only; score unchanged.
  - Summary/evidence: updated [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) to the renamed [0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) non-emitting aggregate. The resolved layout remains the one-pointer `m_data` view with a 12-byte header immediately before the data pointer.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `86`.
- Evidence: IDA MCP verified the 12-byte header layout through ANSI/wide allocation, release, empty-sentinel, sharing, and copy-on-write helpers. Scores remain below `95+` because final type names, exact signedness, complete owner-file placement, and the entire neighboring string-method family still need a full final-source audit.
- 2026-06-08 A006 Batch135 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, no `AUTOGEN_PARENT_UID`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000OA`.
  - Summary/evidence: live IDA reconfirmed allocation/release helper boundaries, header writes, `InterlockedDecrement(data - 0x0c)`, `data - 0x08` length use, pool-capacity switching, and [UID:0000OA][StringBase](by-file/StringBase.md) as the direct source parent after that file reached `88/86`.
