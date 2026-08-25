*** UID:0001VS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutBucket

## Status

- Entity kind: non-emitting semantic view over [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- Confidence: very strong that there is no separate bucket allocation, vtable, destructor, or standalone source type in the reviewed path; medium-high for final source spelling and the unused header word.
- Disposition: ignored as a standalone struct. Keep this page only as a search/cross-reference alias for older generated `ResourceLayoutBucket` wording.
- Replacement owner: [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md), attached to [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) with broader source ownership through [UID:0000K2][ImageLib](by-file/ImageLib.md).
- Evidence basis: live IDA MCP decompilation on 2026-06-13 for `ImageLib::ImageLib`, `ResourceLayoutTable::LoadResourceIndex`, the lookup/count/size/rectangle accessors, `FindResourceIndex`, and the two `ImageLib` destructor bodies.

## Current Interpretation

The earlier `ResourceLayoutBucket` model described a separate object reached through a custom store. IDA now shows the registry is a generic [UID:000079][List](by-class/List.md) of 44-byte / `0x2c` [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) elements (Verified with int_convert.py). The "bucket" read by lookup/count/size methods is the same list element:

```text
ResourceLayoutNameRecord / bucket view
  +0x00  wchar_t name[16]
  +0x20  uint16 entryCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* entries
```

Confirmed reads:

- `LookupLayoutEntry`: uses `entryCount` and `entries`.
- `GetEntryRect`: uses `entryCount` and `entries`.
- `GetFrameSize`: uses `frameWidth` / `frameHeight`.
- `GetEntryCount`: uses `entryCount`.

## Live IDA Evidence

Live IDA MCP session `a001_goal2_0002UM` on 2026-06-13 reconfirmed the alias decision:

- `ImageLib::ImageLib` at `0x004cffb0` constructs the object offset `+0x0c` list with `List::List(44, 10)`: 44 / `0x2c` byte elements and page size 10 / `0x0a` (Verified with int_convert.py). No custom bucket/store constructor is called.
- `ResourceLayoutTable::LoadResourceIndex` at `0x004d0120` reads the 8 / `0x08` byte EPF/EPD header into four adjacent 16-bit fields, stores the allocated record pointer immediately after those fields, copies the 16 / `0x10` wchar resource key, then appends the contiguous 44 / `0x2c` byte stack record through the list append slot at vtable `+0x18` (Verified with int_convert.py).
- `FindResourceIndex` at `0x004d17c0` fetches row zero through list slot `+0x10`, compares the row start as a wide string, and advances by 22 / `0x16` UTF-16 code units, which is the same 44 / `0x2c` byte row stride (Verified with int_convert.py).
- `LookupLayoutEntry` at `0x004d02f0` and `GetEntryRect` at `0x004d0530` validate the requested index against the row word at `+0x20` and read the `ResourceLayoutEntry*` at `+0x28` (32 / `0x20` and 40 / `0x28`, Verified with int_convert.py).
- `GetFrameSize` at `0x004d1730` copies row words at `+0x22` and `+0x24` (34 / `0x22` and 36 / `0x24`, Verified with int_convert.py). The decompiler writes `+0x24` to the second output pointer and `+0x22` to the first output pointer.
- `GetEntryCount` at `0x004d1780` returns the row word at `+0x20`; it has no separate bucket lookup or wrapper call.
- Both `ImageLib` destructor bodies at `0x004d0070` and `0x004e64a0` iterate the same list count at list offset `+0x0c`, fetch each 44-byte row through list slot `+0x10`, free only the row payload pointer at `+0x28`, destroy the generic list, and clear [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). There is no bucket destructor or secondary allocation.

## Field-Use Matrix

| Row field | Direct live use | Alias implication |
| --- | --- | --- |
| `+0x00 name[16]` | `FindResourceIndex` compares this wide string and advances by the 44-byte row stride. | The row start is the cache key; there is no separate bucket header before the name. |
| `+0x20 entryCount` | Bounds check in `LookupLayoutEntry` and `GetEntryRect`; return value in `GetEntryCount`. | The "bucket count" is the list-row count word. |
| `+0x22 frameWidth` | First output from `GetFrameSize`. | Bucket-wide frame dimension metadata stored in the list row. |
| `+0x24 frameHeight` | Second output from `GetFrameSize`. | Bucket-wide frame dimension metadata stored in the list row. |
| `+0x26 reservedHeaderWord` | Read by `LoadResourceIndex` as part of the 8-byte header copy; not read by the reviewed accessor/destructor family. | Keep as a named caveat, not proof of a separate bucket type. 38 / `0x26` verified with int_convert.py. |
| `+0x28 entries` | Dereferenced by lookup/rectangle accessors and freed by both `ImageLib` destructor bodies. | The row owns the `ResourceLayoutEntry` array directly. |

## Scoring Rationale

- `COMPLETION:86`: the page now records the replacement owner, non-emitting/ignored disposition, live constructor/loader/accessor/destructor evidence, direct row field-use matrix, and cross-links to the primary struct and method evidence. It stays below final-audit levels because the original source might still have used a local typedef/comment spelling, the exact semantic name of `+0x26` is unresolved, and final header/source spelling is not proved.
- `CONFIDENCE:91`: the no-standalone-bucket conclusion is supported by independent live IDA checks across allocation, append, lookup, accessors, and destruction. Confidence stays below `95` because the final source declaration/naming policy and the unused header word are still open.

## Open Questions

- Whether to keep a named `ResourceLayoutBucket` typedef/comment alias in docs/source for readability, or collapse all references to `ResourceLayoutNameRecord`.
- Whether `frameWidth` and `frameHeight` are maximum dimensions, sheet dimensions, or source frame metrics for the bucket.
- Exact meaning of the fourth 16-bit header word at `+0x26`.

## Cross-References

- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) ImageLib constructor evidence for `List(44, 10)`.
- [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md) ResourceLayout loader evidence for the appended row shape.
- [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) Lookup accessor evidence for `+0x20/+0x28`.
- [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md) Rectangle accessor evidence for `+0x20/+0x28`.
- [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md) Frame-size accessor evidence for `+0x22/+0x24`.
- [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md) Entry-count accessor evidence for `+0x20`.
- [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) Name-scan evidence for the 44-byte row stride.
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) Ordinary destructor evidence for `+0x28` payload release.
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) Scalar deleting destructor evidence for `+0x28` payload release.

## Changes

- 2026-05-31: Scored and marked as not a standalone reconstructable type.
  - Before: metadata was `0/0` with blank reconstruction state even though the page already documented that the bucket is the same 44-byte record as `ResourceLayoutNameRecord`.
  - After: set completion/confidence to `78/86` and `RECONSTRUCTABLE:FALSE` for standalone autogen purposes.
  - Evidence: IDA MCP decompilation on 2026-05-31 confirms `ImageLib::ImageLib` constructs a generic `List(44, 10)`, `FindResourceIndex` advances by 44-byte rows, and accessors read the same row fields; no separate bucket allocation or vtable is visible.
- 2026-06-13 A002 Goal2 low-completion refresh:
  - Changed from: `78/86`, standalone `RECONSTRUCTABLE:FALSE`.
  - Changed to: `86/91`, standalone `RECONSTRUCTABLE:FALSE`.
  - Evidence: live IDA MCP session `a001_goal2_0002UM` reconfirmed `ImageLib::ImageLib` creates a generic `List(44, 10)`, `LoadResourceIndex` appends the contiguous 44-byte record, `FindResourceIndex` advances by the same row stride, `LookupLayoutEntry`/`GetEntryRect`/`GetFrameSize`/`GetEntryCount` consume fields directly from that row, and both `ImageLib` destructors release only the row's `+0x28` payload pointer. The page stays below final-audit scoring because `+0x26` and final alias/typedef policy remain open.
