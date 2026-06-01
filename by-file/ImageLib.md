*** UID:0000K2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ImageLib

## Status

- Confidence: strong for constructor/destructor behavior, medium for exact relationship to the recovered `ResourceLayoutTable` class.
- Proposed module: `render/ImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_ImageLib.cpp`
- Main address ranges: `0x004cffb0-0x004d006f`, `0x004d0070-0x004d011b`, and `0x004e64a0-0x004e6572`
- Primary global instance: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744`
- Confirmed type anchors: [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)

## File Role

`ImageLib` is the process-wide EPF image/library manager behind `g_pEPFLib`. Its constructor initializes an `LObject` base, assigns `g_pEPFLib = this`, installs the image-library vtable, stores the first constructor argument at object offset `+0x08`, sets offset `+0x10` to `1000000`, and allocates a [UID:0000KS][List](by-file/List.md) of 0x2c-byte entries.

Important signature correction: the generated Wave3 method currently appears as `ImageLib::ImageLib(int maxEntries)`, but the binary call site at `0x004644e8` pushes two stack arguments before calling `0x004cffb0`: `0x0f4240` (`1000000`) and `0x4e20` (`20000`). IDA confirms the constructor returns with stack cleanup for two arguments. The observed constructor body stores the first argument and does not obviously consume the second argument. Keep the second parameter in reconstruction notes until its original API name is proven.

The key file-ownership finding is that `ImageLib` and the recovered [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) method cluster appear to operate on the same object layout:

```text
ImageLib / g_pEPFLib object
  +0x00  LObject base / vtable
  +0x04  refCount
  +0x08  constructorLimitOrCacheLimit
  +0x0c  List* entryList / layout record list
  +0x10  maxCacheSize
```

The current best source-structure hypothesis is that the original project likely had a central `ImageLib.cpp` that owned `ImageLib`, `g_pEPFLib`, cache-list lifecycle, and possibly the layout lookup methods currently recovered as `ResourceLayoutTable`.

2026-05-24 IDA MCP evidence strengthens the singleton owner decision:

- `xrefs_to 0x0067a744` shows constructor writes at `0x004cffef` / `0x004cfff6` and destructor cleanup at `0x004d00fa`.
- `xrefs_to 0x0061b654` shows the `ImageLib` vtable is installed only by `ImageLib` construction/destruction paths, not by `ResourceLayoutTable`.
- `ResourceLayoutTable` methods use the object reached through `g_pEPFLib`, but they do not initialize the global.
- `ImageLib::ImageLib` constructs the `+0x0c` registry field with `List::List(44, 10)`. The suspected custom `ResourceLayoutStore` vtable is therefore the generic `List` vtable at `0x0061ce2c`.

2026-05-25 IDA MCP recheck confirms the same boundary. `sub_4CFFB0` decompiles as a three-parameter `thiscall` shape (`this`, first stack argument, second stack argument), stores the first stack argument at `+0x08`, leaves the second stack argument with no obvious body use, installs vtable `0x0061b654`, and constructs the `+0x0c` list with 44-byte elements.

## Class Boundary Caveat

Wave3 currently has two separate recovered classes:

- `ImageLib`, with constructor/destructor and `g_pEPFLib` assignment.
- `ResourceLayoutTable`, with the EPF/EPD lookup and lazy-load methods.

IDA xrefs and generated code show `ImageLib::ImageLib` writes `this` to `DAT_0067a744`, while callers pass `DAT_0067a744` into the `0x004d0120`/`0x004d02f0` method family. That makes `ResourceLayoutTable` more likely an EPF layout facet of `ImageLib`, a base-class slice, or a recovered semantic alias than an independent singleton object.

The vtable also constrains the boundary. IDA shows RTTI for `ImageLib` at `0x0061b650`, a vtable starting at `0x0061b654` with only three slots (`0x004e64a0`, `0x004f4b10`, `0x0041b6c0`), and then RTTI for `MapTileImageLib` at `0x0061b660`. The `ResourceLayoutTable` methods are therefore not `ImageLib` virtual methods; if they belong to the same original class, they are non-virtual public/helper methods or a recovered non-virtual facet.

The ordinary non-deleting destructor at [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) is real IDA-modeled code but is omitted from active Wave3 source. It releases the same 44-byte list-row payloads as the scalar deleting destructor, destroys the list, clears `g_pEPFLib`, and chains to `LObject` cleanup.

Do not split this into two unrelated globals in the reconstructed source until the vtable/type boundary is resolved. The supporting type docs now track the unresolved subobject model:

- [UID:0000KS][List](by-file/List.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: constructor/destructor behavior, `g_pEPFLib`, vtable/layout anchors, cache-list lifecycle, call-site signature correction, and `ResourceLayoutTable` relationship are documented; confidence is capped by unresolved class/facet boundary and second constructor-argument semantics.
- 2026-05-31 projected path and range correction:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the main ranges used old ends `0x004d006e`, `0x004d011a`, and `0x004e6571`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, corrected exclusive-end ranges `0x004d006f`, `0x004d011b`, and `0x004e6572`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP confirmed exact function bounds and decompilation for constructor, ordinary destructor, and scalar deleting destructor. The projected folder follows the documented render/image-library source grouping already used for neighboring image-library modules.
