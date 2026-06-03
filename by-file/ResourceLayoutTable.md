*** UID:0000N5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ResourceLayoutTable

## Status

- Confidence: strong for method-cluster role, medium for original class boundary.
- Proposed module: `render/ImageLib.cpp` plus possibly `render/ResourceLayoutTable.cpp` if a later vtable/type pass proves a separate helper class.
- Current recovered source: `source-3/simroot_v2/class_ResourceLayoutTable.cpp`
- Main address range: `0x004d0120-0x004d182e`
- Primary global instance: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744`, constructed by [UID:0000K2][ImageLib](by-file/ImageLib.md)

## File Role

`ResourceLayoutTable` is the recovered name for the shared EPF/EPD resource-layout method cluster. It should not be treated as a per-control UI helper or as raw DAT archive parsing. The methods lazily open DAT-backed EPF/EPD entries, convert their frame records into an in-memory [UID:0000KS][List](by-file/List.md) of layout-name records, and return `EPFTileContext` or rectangle data to rendering/UI code.

The current best source-file interpretation is that these methods likely lived near [UID:0000K2][ImageLib](by-file/ImageLib.md), because `ImageLib::ImageLib` assigns `g_pEPFLib = this` and initializes the same `+0x0c` list/store field used by the layout methods. The concrete object is now pinned by [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md); the layout methods are not virtual slots in that table. The likely original source file contained:

- `ImageLib`
- `ResourceLayoutTable`
- `ResourceLayoutEntry`
- private layout record structures backed by the generic `List` container
- the global instance declaration used as `g_pEPFLib`

`EPFImageControlPane`, `AboveFrame`, item glyph helpers, minimap/dialog panes, and image libraries are consumers of this registry. They should call it from their own modules rather than own the EPF record table.

## Evidence

- Wave3 class inspection summarizes this class as a shared layout-resource table that resolves named EPF/EPD records by index.
- `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0` has very broad fan-in: hundreds of callers across UI panes, image libraries, and sprite/effect code.
- `EPFImageControlPane::LoadAndRenderImage` calls the same `0x004d02f0` target through `g_pEPFLib`.
- `AboveFrame` uses `g_pEPFLib` for `FRMPART.EPF`, `TABS.EPF`, and `FRMPART.EPD`.
- `ImageLib::ImageLib` at `0x004cffb0` assigns `g_pEPFLib = this`, allocates a 20-byte `List`, and calls `List::List(44, 10)` before storing it at object offset `+0x0c`; `ImageLib::ScalarDeletingDestructor` clears that global.
- Application shutdown deletes `DAT_0067a744`, which matches a process-wide image/resource registry lifetime.
- IDA MCP xrefs to `0x0067a744` on 2026-05-24 show many consumers but the owner writes remain in the `ImageLib` constructor/destructor family.
- IDA MCP vtable review on 2026-05-24 resolves the suspected `ResourceLayoutStore` vtable as the generic `List` vtable at `0x0061ce2c`; `LoadResourceIndex` uses `List::Append` and lookup paths use `List::GetElementAt`.

## Public API Shape

| Method | Address | Role |
| --- | --- | --- |
| `LoadResourceIndex` | `0x004d0120` | Opens a named EPF/EPD resource through `DATFile`, reads its frame records, normalizes offsets, and registers a bucket. |
| `LookupLayoutEntry` | `0x004d02f0` | Lazy-loads a resource when needed and fills an `EPFTileContext` for one entry. |
| `CopyEntryTileContext` | `0x004d04d0` | Loads an entry into a temporary context and copies it to the caller. |
| `GetEntryRect` | `0x004d0530` | Lazy-loads a resource and returns only the stored frame bounds. |
| `GetFrameSize` | `0x004d1730` | Returns bucket-wide frame width/height metadata. |
| `GetEntryCount` | `0x004d1780` | Returns bucket record count. |
| `FindResourceIndex` | `0x004d17c0` | Scans registered resource names and returns the bucket index. |

## Ownership Decision

Use `render/ImageLib.cpp` as the broader owner until the class boundary is resolved. `render/ResourceLayoutTable.cpp` remains a possible helper split if later evidence proves a real separate class, but current constructor/global evidence says the layout methods operate on the `ImageLib` singleton object behind `g_pEPFLib`.

Do not reconstruct a standalone `ResourceLayoutStore` class. The registry field should be modeled as `List*` with 44-byte `ResourceLayoutNameRecord` elements unless later evidence proves the original source wrapped the list in a typed helper.

Do not create an `EPFLibrary` class from current generated references. The generated `EPFLibrary::LoadFrame` call sites are naming artifacts for calls into `ResourceLayoutTable::LookupLayoutEntry`.

Do not absorb the nearby [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md) into this class. They are physically interleaved in the `0x004d` resource neighborhood, but their callers and behavior are shared image-loader glue, not EPF layout-table methods.

## Cross-References

- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md)
- [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document now captures role, proposed contents, public API shape, singleton/global ownership, IDA-backed evidence, ownership exclusions, and cross-references; confidence remains capped by unresolved original class/file boundary between `ImageLib` and a possible helper split.
