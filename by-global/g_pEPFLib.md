*** UID:0000QU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pEPFLib

## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- Current generated aliases: `g_pEPFLib`, `DAT_0067a744`
- Current generated declaration: `ResourceLayoutTable* g_pEPFLib` in `source-3/simroot_v2/class_ImageLib.cpp`
- Proposed owner module: [UID:0000K2][ImageLib](by-file/ImageLib.md)
- Confidence: strong for storage and owner module, medium for final pointer type.

## Role

`g_pEPFLib` is the process-wide EPF/EPD layout and image resource registry. It is constructed by [UID:00006E][ImageLib](by-class/ImageLib.md), then consumed by [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) lookup methods and a broad set of UI/render callers.

The registry's `+0x0c` field is a [UID:000079][List](by-class/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows. The IDA-confirmed [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md) anchor the concrete object; earlier notes used `ResourceLayoutStore` for this field, but current evidence says that is a generated alias over the generic container.

The final type should not be committed as an independent `ResourceLayoutTable*` yet. The same storage is assigned by `ImageLib::ImageLib`, cleared by `ImageLib` destruction, and passed to the `ResourceLayoutTable` method family. Current best interpretation:

```cpp
ImageLib* g_pEPFLib; // exposes ResourceLayoutTable-style non-virtual lookup API
```

Alternative still open: `ResourceLayoutTable` could be a non-virtual base/facet inside `ImageLib`.

## Lifetime Evidence

- IDA MCP disassembly of `0x004cffb0` shows `ImageLib::ImageLib` writes `dword_67A744 = this` after `LObject` construction and vtable setup.
- IDA MCP xrefs to `0x0067a744` include writes inside `ImageLib::ImageLib` at `0x004cffef` / `0x004cfff6` and cleanup in `ImageLib::~ImageLib` at `0x004d00fa`.
- The ordinary destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) and scalar deleting destructor at `0x004e64a0` both release list-row payloads, destroy the `+0x0c` list, and clear this singleton.
- IDA MCP xrefs also show many reads from UI panes and image-library code that use the pointer before calling layout lookup helpers.
- A 2026-05-25 recheck confirms `0x0067a744` remains global storage, not a function, and the `ImageLib` vtable at `0x0061b654` is only referenced by the constructor/destructor family.
- `ImageLib::ScalarDeletingDestructor` at `0x004e64a0` releases cached payload blocks and clears this singleton.

## Consumer Pattern

Typical callers load `g_pEPFLib`, pass it as `this`, then call one of the [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) methods:

- `LookupLayoutEntry` at `0x004d02f0`
- `GetEntryRect` at `0x004d0530`
- `GetFrameSize` at `0x004d1730`
- `GetEntryCount` at `0x004d1780`

Callers span fitting-room/item-shop panes, minimap controls, frame chrome, image libraries, item/effect helpers, and other UI/render code. This breadth supports a central render-resource singleton rather than ownership by any one feature pane.

## Open Questions

- Final C++ declaration type: `ImageLib*`, `ResourceLayoutTable*`, or a named base/interface type.
- Whether the original header exposed the layout APIs directly on `ImageLib` or through an embedded/base helper.
- Whether generated aliases such as `DAT_0067a744` should be normalized everywhere to `g_pEPFLib`.

## Cross-References

- [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page documents memory storage, generated aliases, ImageLib/resource-layout role, object/list layout refs, lifetime evidence, broad consumer pattern, and open final type/base questions.
