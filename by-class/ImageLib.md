*** UID:00006E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ImageLib

## Status

- Confidence: strong for constructor/destructor, medium for full method membership.
- Likely source file: [UID:0000K2][ImageLib](by-file/ImageLib.md)
- Address ranges: [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- Confirmed type anchors: [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) and [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)

## Class Purpose

`ImageLib` is the EPF image-library manager singleton installed as [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). It owns a list-based cache of image/layout entries and releases cached payloads during destruction.

## Observed Layout

```text
ImageLib
  +0x00  LObject base
  +0x04  refCount
  +0x08  int constructorLimitOrCacheLimit
  +0x0c  List* entryList
  +0x10  int maxCacheSize
```

`ResourceLayoutTable` method-local overlays name the `+0x0c` field as `recordStore`; `ImageLib` constructor names the same field as `m_pEntryList`. Treat these as the same storage until proven otherwise.

2026-05-24 IDA MCP follow-up resolved the storage type: `ImageLib::ImageLib` allocates a 20-byte [UID:000079][List](by-class/List.md), calls `List::List(44, 10)`, and stores it at `+0x0c`. The list elements are [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows.

The constructor signature in generated Wave3 data is currently incomplete. The application call site pushes `1000000` and `20000`, and IDA confirms `0x004cffb0` cleans two stack arguments. The first argument is stored at `+0x08`; `+0x10` is also initialized to `1000000`. The second argument has no obvious use in the recovered constructor body.

See [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) for the rebuild-oriented field ledger.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ImageLib::ImageLib` | [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md) | Initializes the singleton, assigns `g_pEPFLib = this`, stores constructor state, and allocates the 44-byte-row entry list. Binary signature has two stack arguments. |
| `ImageLib::~ImageLib` | [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md) | Lower-only/prewave non-deleting destructor body; releases cached payloads and clears `g_pEPFLib`. |
| `ImageLib::ScalarDeletingDestructor` | [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md) | Releases cached payload blocks, destroys the entry list, clears `g_pEPFLib`, chains to base cleanup, and optionally deletes `this`. |

## Ownership Notes

The recovered [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) methods likely belong near this class in the original source. Whether they should be merged into `ImageLib` or kept as a base/helper class is still open, but they should not be treated as a separate process-wide manager with a separate global.

IDA vtable evidence shows only three `ImageLib` virtual slots at `0x0061b654`, followed immediately by `MapTileImageLib` RTTI. This means the `ResourceLayoutTable` lookup family is not virtual on `ImageLib`; it is either non-virtual `ImageLib` API, a helper/base slice, or a recovered type-alias artifact.

IDA MCP xrefs to `0x0067a744` on 2026-05-24 confirm the global storage is written by this constructor/destructor family while `ResourceLayoutTable` methods consume it. Treat [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) as generated/provisional aliases over the [UID:000079][List](by-class/List.md)-backed [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) model until the exact header split is proved.

## Autogen Status

Attach this class to [UID:0000K2][ImageLib](by-file/ImageLib.md) as reconstructable metadata for `render/ImageLib.cpp`. C++ remains blank because the `ResourceLayoutTable` relationship, unused second constructor argument, and final private field names remain below the final-code gate.

## Cross-References

- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001XR][ImageLibVtable](by-type/by-vtable/ImageLibVtable.md)
- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md)
- [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md)
- [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md)
- [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md)
- [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `80/78`. Summary: EPF image-library singleton role, observed layout, constructor/destructor signatures, list-backed resource records, vtable evidence, global storage, and ResourceLayoutTable ownership caveats are documented; confidence remains limited by full method-membership and helper/base split questions. Evidence: `ImageLib`, `ImageLibDestructor`, `ImageLibLayout`, `ImageLibVtable`, `g_pEPFLib`, `ResourceLayoutNameRecord`, and ResourceLayout alias/type pages.
- 2026-05-31 range correction and reconstructable update:
  - What existed before: class used old child bounds, lacked exact constructor/scalar-deleting destructor page references, and `RECONSTRUCTABLE:` was blank.
  - Changed to: `RECONSTRUCTABLE:TRUE`, `COMPLETION:82`, `CONFIDENCE:82`, exact child references for constructor/destructor/scalar-deleting destructor, and corrected aggregate range `0x004cffb0-0x004e6572`.
  - Summary/evidence: IDA MCP confirmed function bounds, constructor/deleting-destructor behavior, vtable xrefs, and singleton writes/clears on 2026-05-31. Scores stay below final level because `ResourceLayoutTable` membership and final source-facing private names remain open.
- 2026-06-02 parent attachment:
  - What existed before: class metadata was reconstructable but had no autogen parent.
  - Changed to: attached to [UID:0000K2][ImageLib](by-file/ImageLib.md), leaving C++ blank.
  - Summary/evidence: class and file scores are both above the 80 confidence attachment threshold and agree on `render/ImageLib.cpp` ownership while documenting unresolved source-shape caveats.
