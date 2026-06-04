*** UID:0000BY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutTable

## Status

- Confidence: strong for live method boundaries, lazy EPF/EPD registry behavior, row layout, and `ImageLib` singleton ownership; medium for exact original class/facet split and final field names.
- Autogen parent: [UID:0000K2][ImageLib](by-file/ImageLib.md) as the current broader source owner. [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) remains a possible helper-file split if later type evidence proves an independent source boundary.
- Address range: [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md)
- Reconstruction handling: source-authored and reconstructable, but final C++ remains blank until the `ImageLib` versus helper/facet boundary reaches the 95/95 bar.

## Class Purpose

`ResourceLayoutTable` is the recovered name for a lazily populated EPF/EPD frame-resource lookup method cluster. Callers pass a DAT-backed resource name such as `FRMPART.EPF`, `FRMPART.EPD`, `TABS.EPF`, `ITEM.EPF`, or `ITEM.EPD` plus a frame index. The table loads the resource once, stores a named bucket, and returns frame pixel and mask offsets through `EPFTileContext`.

The process-wide instance is [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `DAT_0067a744`. Follow-up evidence shows that [UID:00006E][ImageLib](by-class/ImageLib.md) constructs this global by assigning `g_pEPFLib = this`, so `ResourceLayoutTable` may be a semantic alias, base slice, or helper facet of `ImageLib` rather than an independent original class.

## Observed Object Shape

```text
  +0x00  int reserved0
  +0x04  int reserved1
  +0x08  int reserved2
  +0x0c  List* entryList
```

This overlaps the observed `ImageLib` layout: `ImageLib` has an `LObject` base at `+0x00`, `maxEntries` at `+0x08`, and a `List* entryList` at `+0x0c`. IDA MCP now confirms `ImageLib::ImageLib` constructs that field with `List::List(44, 10)`.

The `entryList` owns 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) rows. The older [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) and [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) names are retained as documentation aliases, but current evidence says the binary uses the generic [UID:000079][List](by-class/List.md) container rather than a custom store class. The element shape is:

```text
ResourceLayoutNameRecord
  +0x00  wchar_t name[16]
  +0x20  uint16 recordCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* records
```

`LoadResourceIndex` appends this 44-byte row through `List::Append`; lookup/count/size methods retrieve it through `List::GetElementAt`.

## Method Notes

- `LoadResourceIndex` reads the EPF/EPD table header, seeks to the raw record table, allocates `entryCount + 1` `ResourceLayoutEntry` records, converts raw bounds to `left, top, right, bottom`, adds `DATFile::GetDataBase() + 0xc` to payload offsets, appends a sentinel, and appends a 44-byte `ResourceLayoutNameRecord` to the `List` under a 16-wchar resource key.
- `LookupLayoutEntry` calls `FindResourceIndex`, falls back to `LoadResourceIndex`, bounds-checks the requested entry, and fills an `EPFTileContext` with pixel pointer, row stride, bounds, encoded-mask size, and mask pointer.
- `GetEntryRect`, `GetFrameSize`, and `GetEntryCount` all share the same lazy-load pattern.
- `FindResourceIndex` scans `ResourceLayoutNameRecord` values using `wcscmp`.

## Live IDA Evidence

- Live IDA MCP verifies the relevant function boundaries: `ImageLib` constructor `0x004cffb0-0x004d006f`, ordinary destructor `0x004d0070-0x004d011b`, `LoadResourceIndex` `0x004d0120-0x004d02e5`, `LookupLayoutEntry` `0x004d02f0-0x004d039e`, raw-buffer lookup helper `0x004d03a0-0x004d04d0`, `CopyEntryTileContext` `0x004d04d0-0x004d0522`, `GetEntryRect` `0x004d0530-0x004d059b`, raw-record rect helper `0x004d05a0-0x004d05e6`, `GetFrameSize` `0x004d1730-0x004d1773`, `GetEntryCount` `0x004d1780-0x004d17b3`, and `FindResourceIndex` `0x004d17c0-0x004d182f`.
- Live byte audit confirms only `0xcc` padding in the local alignment gaps: `0x004d011b-0x004d0120`, `0x004d02e5-0x004d02f0`, `0x004d039e-0x004d03a0`, `0x004d0522-0x004d0530`, `0x004d059b-0x004d05a0`, `0x004d1773-0x004d1780`, and `0x004d17b3-0x004d17c0`.
- Live decompilation of `0x004cffb0` installs vtable `0x0061b654`, writes `g_pEPFLib` at `0x0067a744`, stores the constructor argument at object offset `+0x08`, sets `+0x10` to `1000000`, allocates 20 bytes, and constructs the `+0x0c` registry with `List::List(44, 10)`.
- Live xrefs to `0x0067a744` show broad consumer reads, while owner writes/clears remain in `ImageLib`: constructor write at `0x004cffef`, constructor null fallback at `0x004cfff6`, and destructor clear at `0x004d00fa`.
- Live xrefs to `0x0061b654` show the `ImageLib` vtable installed by constructor `0x004d0009`, ordinary destructor `0x004d009a`, and scalar deleting destructor `0x004e64d1`; no separate `ResourceLayoutTable` vtable was observed for the lookup family.
- Live decompilation of `LoadResourceIndex` shows an 8-byte header read, record-table offset read, allocation of `24 * (entryCount + 1)` bytes, raw top/left/bottom/right plus pixel/mask offsets per record, sentinel construction, 16-wchar key copy, and append into `this[3]`.
- Live decompilation of the lookup/accessor methods confirms the lazy-load pattern: `FindResourceIndex` first, `LoadResourceIndex` on `-1`, then `List::GetElementAt` through `this+0x0c`; `LookupLayoutEntry` maps the row to an `EPFTileContext`, `GetEntryRect` copies a rectangle or zeroes it, `GetFrameSize` returns row header words at `+0x22/+0x24`, and `GetEntryCount` returns the row count at `+0x20`.

## Important Caveats

- `ResourceLayoutTable` stores EPF/EPD frame metadata; it does not decode archive-level DAT directory records.
- `ImageLib` constructor/destructor evidence must be reviewed before moving these methods as a standalone class.
- The provisional `EPFLibrary` name seen in some recovered files is not a confirmed class. Its call targets resolve to `ResourceLayoutTable`.
- The resource key copy in `LoadResourceIndex` uses a 16-wchar local buffer. The earlier `wchar_t name[0x16]` overlay was a stride artifact: 44 bytes equals 22 UTF-16 code units, but the last 12 bytes are metadata and the entries pointer.
- IDA MCP xrefs on 2026-05-24 show `g_pEPFLib` is initialized and cleared by the `ImageLib` constructor/destructor family; this class should remain a method/facet candidate, not a separate singleton owner.
- IDA MCP decompilation on 2026-05-24 shows the `+0x0c` registry object is a generic `List`, so do not create a separate `ResourceLayoutStore` class from current evidence.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)

## Score Rationale

- `COMPLETION:86`: live IDA research now verifies exact method/helper boundaries, local padding, ImageLib owner lifecycle, row-list construction, lazy lookup behavior, and accessor field offsets. Remaining work is the exact original class/facet split and final source names.
- `CONFIDENCE:84`: confidence rises because the active behavior and singleton ownership are supported by current decompilation and xrefs, not just prior notes. It remains below final-source confidence because the lookup family is non-virtual and may have been an `ImageLib` facet, helper class, or separate implementation unit.
- `AUTOGEN_PARENT_UID:0000K2`: the parent attachment uses the current best source owner, `ImageLib`, whose file confidence is above the attachment threshold and whose constructor/destructor own `g_pEPFLib` and the 44-byte row `List`.

## Changes

- 2026-06-04: Raised completion/confidence from `82/76` to `86/84` and attached the reconstructable class/facet to [UID:0000K2][ImageLib](by-file/ImageLib.md) for autogen ownership. The increase is justified by fresh live IDA MCP verification of exact method boundaries, `0xcc` padding spans, ImageLib constructor/destructor ownership of `g_pEPFLib`, `List::List(44, 10)` registry construction at `+0x0c`, lazy-load decompilation for `LookupLayoutEntry`/accessors, and lack of a separate `ResourceLayoutTable` vtable.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/76`.
  - Before: The page was unevaluated despite detailed documentation of lazy EPF/EPD lookup behavior, object shape, record layout, method roles, and ImageLib overlap caveats.
  - After: Scored as high completion with medium-high confidence because observed behavior is strong but the original class boundary and final field names remain partly unresolved.
  - Evidence: Existing object-shape notes, method notes, caveats, global/singleton evidence, and type/class/file cross-references support the score.
- 2026-05-31: Marked the class/facet documentation as reconstructable without adding C++.
  - Before: `RECONSTRUCTABLE` was blank even though IDA-confirmed methods and source-authored data structures require reconstruction.
  - After: set `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank because the final `ImageLib` versus `ResourceLayoutTable` source boundary is still unresolved.
  - Evidence: IDA MCP decompilation of the `0x004d0120-0x004d182e` method family confirms source-authored EPF/EPD layout-table behavior, but the same object is constructed by `ImageLib::ImageLib`.
