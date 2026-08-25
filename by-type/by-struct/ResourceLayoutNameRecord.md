*** UID:0001VT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ResourceLayoutNameRecord is declared once in ImageLib.h; no separate CPP definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutNameRecord

## Status

- Entity kind: support struct
- Confidence: very strong for row width, key fields, and direct ResourceLayoutTable class/facet ownership; medium-high for final source field names.
- Direct owner: [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), with broader source ownership through [UID:0000K2][ImageLib](by-file/ImageLib.md).
- Evidence basis: IDA MCP decompilation of `ImageLib::ImageLib`, `ResourceLayoutTable::LoadResourceIndex`, `FindResourceIndex`, and `List` vtable calls.

## Layout

`ImageLib::ImageLib` constructs the registry as `List::List(44, 10)`, so each resource-layout list element is 44 bytes:

```text
ResourceLayoutNameRecord
  +0x00  wchar_t name[16]
  +0x20  uint16 entryCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* entries
```

`ResourceLayoutTable::LoadResourceIndex` reads the 8-byte EPF/EPD header into the four 16-bit fields at `+0x20` through `+0x26`, allocates `entryCount + 1` [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) rows, stores that pointer at `+0x28`, copies the resource key into `name[16]`, and appends the whole 44-byte record to the [UID:000079][List](by-class/List.md).

`FindResourceIndex` obtains the first row with `List::GetElementAt(0)`, uses `List::count` as the loop bound, and advances by 44 bytes (`v5 += 22` wide characters) while comparing `name` with `wcscmp`.

[UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) is direct destructor evidence that `entries` at `+0x28` is an owned payload pointer. B006 MCP session `80de0a67` confirms the ordinary destructor walks the `ImageLib +0x0c` list, obtains each 44-byte record through the list `GetElementAt` virtual slot, tests row `+0x28`, calls `FreeBufferMemory` for non-null payloads, and stores the returned pointer back to the same field before the list object itself is deleted. The scalar deleting destructor repeats the same row-payload cleanup as wrapper parity.

## Assignment Gate

Batch143 recheck, 2026-06-08: this struct now clears the corrected child gate at `85/89`, and its actual direct parent [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) already clears the parent gate at `87/86`. The direct-owner choice is the class/facet page rather than the broader file because the type is the private 44-byte registry row consumed by `ResourceLayoutTable` lookup/accessor methods. [UID:0000K2][ImageLib](by-file/ImageLib.md) remains the broader source-file parent through the class/facet chain, but it is not the immediate type parent.

Batch 170 recheck, 2026-06-11: live IDA MCP against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed `ImageLib::ImageLib` at `0x004cffb0-0x004d006f`, `LoadResourceIndex` at `0x004d0120-0x004d02e5`, lazy lookup/accessors at `0x004d02f0`, `0x004d0530`, `0x004d1730`, `0x004d1780`, and `FindResourceIndex` at `0x004d17c0-0x004d182f`. It also reconfirmed `g_pEPFLib` xrefs, the `ImageLib` vtable stores at `0x0061b654`, and call/data refs from accessors to `LoadResourceIndex` and `FindResourceIndex`. The row remains a private `ResourceLayoutTable` registry element, so parent [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) is retained.

## 2026-06-30 Source Declaration

B011's accepted ImageLib empty-emitter implementation emits this private 44-byte row as `struct ResourceLayoutNameRecord` under [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md). The declaration is source-quality as a first draft because every field offset is consumed by current method bodies:

- `name[16]` occupies `+0x00-+0x20` and is copied by `LoadResourceIndex`, then compared by `FindResourceIndex`.
- `entryCount` at `+0x20` drives `LookupLayoutEntry`, `GetEntryRect`, and `GetEntryCount`.
- `frameWidth` and `frameHeight` at `+0x22/+0x24` are returned by `GetFrameSize` and consumed by `InterfaceEfx::Play` as effect bounds.
- `reservedHeaderWord` at `+0x26` is preserved from the fourth DAT header word even though no named accessor has been recovered.
- `entries` at `+0x28` owns the heap array of [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) rows and is released by the ImageLib destructor path.

## Notes

- The earlier `name[0x16]` hypothesis was caused by treating the 44-byte stride as all wide characters. The first 32 bytes are the actual name buffer; the remaining 12 bytes are header metadata and the entry pointer.
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) is now best treated as a semantic view of this same 44-byte record, not a separate heap object.
- `reservedHeaderWord` is read from the file header but no current accessor names it.

## 2026-08-16 Declaration Ownership Closure

The exact 44-byte declaration now emits once, before class use, from the formal H channel of [UID:00006E][ImageLib](by-class/ImageLib.md). This support page's formal CPP and H channels are intentionally blank so `ImageLib.cpp` cannot acquire a late duplicate definition. The centralized declaration retains `wchar_t name[16]`, the four 16-bit header fields at `+0x20/+0x22/+0x24/+0x26`, and `ResourceLayoutEntry *entries` at `+0x28`.

The GFACE branch in [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) independently selects this exact type: it reads `entryCount` at `+0x20` and `entries` at `+0x28` from the `List(44, 10)` row. The formerly generated `ResourceLayoutRecord` spelling is historical compile-invalid convenience text, not a distinct type, allocation, row, or declaration route. KO append, KP/KS/KU/KV/KW, private UID00054V `GetEntry`, the inline row accessor, and destructor cleanup all share this one declaration.

## Cross-References

- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: raised `90/92` to `92/94`, moved the sole exact declaration from this page's late CPP channel into UID00006E formal H before class use, and left both local formal channels blank to prevent duplication. Added exact GFACE `+0x20/+0x28` proof and historicalized the undefined `ResourceLayoutRecord` convenience spelling without changing any field, offset, width, ownership, or list-stride evidence.

- 2026-06-30 B011 ImageLib empty-emitter implementation:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000BY`, `EMITTER_UIDS:0000BY`.
  - Implemented accepted first-draft `struct ResourceLayoutNameRecord`, preserving the `44`-byte row size, `name[16]`, header words at `+0x20/+0x22/+0x24/+0x26`, `entries` at `+0x28`, `List(44, 10)` construction, `LoadResourceIndex` append, `FindResourceIndex` stride, and destructor cleanup of the row payload pointer.
  - The field names are descriptive source-facing names; `reservedHeaderWord` remains intentionally conservative because current accessors do not name the fourth header word.
- 2026-06-27 B006 destructor source-quality implementation: no score change. Added [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) as direct cleanup evidence for `entries` at `+0x28`: MCP session `80de0a67` shows the ordinary destructor freeing that field through `FreeBufferMemory` before deleting the containing `List`.
- 2026-05-31: Scored and marked as a reconstructable source-level record.
  - Before: metadata was `0/0` with blank reconstruction state despite strong recorded layout evidence.
  - After: set completion/confidence to `82/88` and `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank because the final source-file owner is still split between `ImageLib` and the `ResourceLayoutTable` helper/facet.
  - Evidence: IDA MCP decompilation on 2026-05-31 confirms the 44-byte `List` element size, 16-wide-character name buffer, header fields at `+0x20` through `+0x26`, entry pointer at `+0x28`, and 44-byte scan stride.
- 2026-06-08 A003 Batch143 direct-parent audit:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:88`, and blank `AUTOGEN_PARENT_UID` because the older note treated the final owner as split between `ImageLib` and `ResourceLayoutTable`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, `AUTOGEN_PARENT_UID:0000BY`; C++ remains blank.
  - Evidence: the class/facet page [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) now documents the same 44-byte row shape, `List(44, 10)` registry ownership, lazy-load/accessor consumers, and parent chain to [UID:0000K2][ImageLib](by-file/ImageLib.md). The direct type parent clears `87/86`, the broader file clears `87/86`, and the row is a private ResourceLayoutTable registry element rather than an independent file-level helper type.
- 2026-06-11 A003 supervisor-row pass:
  - Changed from: `85/89`, parent [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md).
  - Changed to: `86/90`, parent unchanged.
  - Evidence: live IDA reconfirmed the `ImageLib` constructor, `LoadResourceIndex`, lazy accessor and `FindResourceIndex` bounds, registry/list ownership through `g_pEPFLib`, vtable-store refs, and row-consumer call/data refs. Remaining field-name polish keeps this below final-audit scoring.
