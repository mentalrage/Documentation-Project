*** UID:0000E2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: strong for constructor/destructor, bounds helper, singleton/vtable ownership, resource inputs, and source-file placement; medium for final field names.
- Likely source file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Address ranges: [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Vtable: [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- Layout docs: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- Singleton: [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- Parent attachment: attached to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) after the class confidence reached the 80% gate. Final C++ remains blank.

## Class Purpose

`StaticObjImageLib` is the static map object image library behind `g_pStaticObjImageLib`. It parses object records from `SOBJ.TBL`, loads `TILEC` archive metadata, reads tile-class records, and returns tile-aligned bounds for static-object ids.

## Observed Layout

```text
StaticObjImageLib
  +0x00  LObject/vtable
  +0x04  ArchiveMetadataTable* tileCatalog
  +0x08  TileClassEntry* tileClasses
  +0x0c  StaticObjEntry** staticObjEntries
  +0x10  int staticObjCount
```

`StaticObjEntry` records include object id, palette group, layer count, optional cache-chain nodes, and inline tile ids. `TileClassEntry` records are 4 bytes and mirror the high-bit plus 15-bit id pattern used by map tile records.

The shared resource layout and the second compact map-cache parser are tracked in [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md). This class owns the full static-object render/resource view, while [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) is map-gameplay cache state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `StaticObjImageLib::StaticObjImageLib` | `0x004dcf60` | Loads `SOBJ.TBL`, then loads `TILEC` archive/table resources depending on modern/legacy mode. |
| `~StaticObjImageLib` | `0x004dd1e0` | Non-deleting cleanup body omitted by active generated output; releases object records, tile catalog/cache chain, tile classes, and singleton state. |
| `RenderStaticObject` | `0x004dd2c0` | Draws layered static-object tiles and optional overlay masks; active generated output currently leaves this in the disabled companion file. |
| `GetStaticObjectBounds` | `0x004dd850` | Returns local bounds based on object layer count and global tile dimensions. |
| `ClearStaticObjImageLibSingleton` | `0x004e5c00` | Tiny cleanup helper that only clears `g_pStaticObjImageLib`; likely compiler/static cleanup glue. |
| `DeletingDestructor` | `0x004e6990` | Frees static object entries, tile catalog/cache chain, tile-class table, clears global, and optionally deletes `this`. |

## IDA-Backed Ownership Notes

- Live IDA confirms the constructor has one startup caller at `0x004f607b`, while `RenderStaticObject` is only called by [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) and [UID:0000MK][PhotoPane](by-file/PhotoPane.md).
- `GetStaticObjectBounds` is used by map/object setup, [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), and [UID:0000MK][PhotoPane](by-file/PhotoPane.md), keeping the helper with this class rather than those consumers.
- `BuildTilecArchiveTable` is constructor-only; it probes numbered `TILEC%d.EPF` shards and constructs a packed archive metadata table for the modern resource path.
- `g_pStaticObjImageLib` has 13 live IDA xrefs spanning constructor publish, ordinary/helper/scalar destructor clears, shutdown, map/static-object consumers, and photo composition.
- StaticObjImageLib vtable slot `0x0061b704` is written by the constructor, ordinary destructor, and scalar deleting destructor; the vtable data page records the neighboring `.rdata` boundary.
- The aggregate [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md) now records the exact live function inventory, state/resource map, and remaining source-gate caveats.
- 2026-06-08 Batch122 IDA recheck reconfirms [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md) as constructor cleanup glue for this class: `lookup_funcs` reports an exact `0xb` function, decompilation writes `dword_69B448 = 0`, ordinary callers/callees are empty, `xrefs_to` points back to the constructor cleanup region, and singleton data refs group with the constructor/destructor/scalar-destructor/shutdown/consumer lifecycle.

## Data Caveats

- Current `class_StaticObjImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary vtable at `0x0061b704`.
- Active `source-3/simroot_v2/class_StaticObjImageLib.cpp` excludes `RenderStaticObject` at `0x004dd2c0` into `class_StaticObjImageLib.cpp.disabled`.
- Active generated output omits the ordinary destructor at `0x004dd1e0` and the singleton clear helper at `0x004e5c00`.
- Generated and older docs called the third `SOBJ.TBL` per-record byte a name length. IDA render evidence uses the corresponding in-memory byte as `layerCount`, with `uint16` tile ids following the fixed header.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `78`.
- Evidence: the page documents static-object resource responsibility, layout, singleton/vtable/type/resource docs, constructor/destructor/render/bounds/destructor methods, data caveats, and corrected `SOBJ.TBL` semantics; confidence remains capped by provisional field names and active generated omissions.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, non-deleting destructor, render, bounds, singleton-clear helper, and deleting destructor anchors at `0x004dcf60`, `0x004dd1e0`, `0x004dd2c0`, `0x004dd850`, `0x004e5c00`, and `0x004e6990`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06 A005 evidence refresh: raised confidence from `78` to `82` and attached the class to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). Live IDA MCP reconfirmed constructor/destructor/render/bounds/archive-helper/singleton-helper/scalar-destructor boundaries, caller sets, singleton xrefs, vtable writes, resource inputs, and source-file ownership; final field/type names and C++ remain below the final-source gate.
- 2026-06-08 A003 Batch122: Raised confidence from `82` to `85`.
  - Before: the class documented the singleton-clear helper but still scored below the corrected confidence gate.
  - After: the ownership notes record the fresh helper/lifecycle xref evidence and support [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) as a strict-gate source parent.
  - Evidence: Batch122 IDA recheck of `0x004e5c00`, `0x0069b448`, and related constructor/destructor/scalar/shutdown/consumer references.
