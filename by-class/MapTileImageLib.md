*** UID:00007T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib

## Status

- Confidence: strong for class ownership, method boundaries, singleton/vtable evidence, and source-file parent; medium for final field names and final-source C++ shape.
- Likely source file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Address ranges: [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- Vtable: [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- Layout docs: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- Singleton: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- Reconstructable: true; attached to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), with C++ intentionally blank until names, dependencies, and final source shape reach the reconstruction bar.

## Class Purpose

`MapTileImageLib` is the map terrain tile image library behind `g_pMapTileImageLib`. It loads tile frame metadata from `TILE%d.EPF`, reads per-tile palette/filter metadata from `TILE.TBL`, and draws a terrain tile into a target draw surface.

## Observed Layout

```text
MapTileImageLib
  +0x00  LObject/vtable
  +0x04  ArchiveMetadataTable* tileMetadata
  +0x08  MapTileRecord* tileRecords
```

`MapTileRecord` is 4 bytes: a 15-bit tile palette/frame index plus a high-bit flag that allows drawing while palette filtering is enabled. See [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapTileImageLib::MapTileImageLib` | [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) | Sets `g_pMapTileImageLib`, loads `TILE%d.EPF` metadata, opens `TILE.TBL`, validates counts, and stores tile records. |
| `~MapTileImageLib` | [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) | Non-deleting cleanup body omitted by some generated output; frees metadata and tile records, clears singleton, and calls `LObject` cleanup. |
| `DrawTile` | [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) | Resolves legacy tile ids, loads an `EPFTileContext`, applies palette-filter rules, and dispatches the tile blitter. |
| `LoadTileEpfMetadata` | [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) | File-local/helper metadata loader for tile EPF archive shards. |
| `ClearMapTileImageLibSingleton` | `0x004e5bc0` | Tiny cleanup helper that only clears `g_pMapTileImageLib`; likely compiler/static cleanup glue. |
| `ScalarDeletingDestructor` | [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) | Frees tile metadata payload/table, frees tile records, clears `g_pMapTileImageLib`, and optionally deletes `this`. |

## Evidence Notes

- 2026-06-06 IDA MCP recheck confirms function objects for the constructor `0x004d1860-0x004d199e`, ordinary destructor `0x004d19a0-0x004d1a1c`, draw method `0x004d1a20-0x004d1b72`, metadata loader `0x004d1b80-0x004d1f22`, singleton-clear helper `0x004e5bc0-0x004e5bcb`, and scalar deleting destructor `0x004e66a0-0x004e6748`.
- Constructor callers contain the startup site at `0x004f6055`; `LoadTileEpfMetadata` has the constructor as its only direct caller at `0x004d18d1`; `DrawTile` has three direct callers at `0x00424441`, `0x0050d984`, and `0x005497d0`.
- IDA xrefs to [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) include constructor writes, destructor/scalar-destructor clears, the singleton-clear helper, startup cleanup, and draw consumers. Vtable xrefs to `0x0061b664` come from constructor/destructor setup at `0x004d18bb`, `0x004d19ca`, and `0x004e66d1`.
- Prior generated-output caveats are superseded for scoring by the exact by-memory children: ordinary destructor and singleton-clear helper are real IDA functions even when an emitted generated class view omits them.
- 2026-06-08 Batch133 live IDA recheck confirmed the same method bounds, constructor-only ownership of `LoadTileEpfMetadata`, no direct callers for the scalar deleting destructor, the single startup constructor caller, three `DrawTile` callers, ten `g_pMapTileImageLib` xrefs, and the vtable dwords from `0x0061b660` through the successor `ProtectedArray<HeadInfo>` locator at `0x0061b670`.

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- 2026-06-08 A005 Batch133 parent-gate refresh:
  - Before: `84/84`; direct class parent for [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md) was below the corrected `85/85` gate.
  - After: `85/85`; no parent change because this class was already attached to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
  - Evidence: live IDA MCP reconfirmed all six class method/helper boundaries, caller sets for constructor/draw/helper/deleting destructor, singleton xrefs, and vtable store refs. Confidence remains capped at 85 because final field names and source-level C++ are not final-audit quality.
- 2026-06-06 A004 parent gate and IDA evidence refresh:
  - Before: class was `82/78`, reconstructable but unattached, and still carried generated-data caveats as part of the active confidence explanation.
  - After: raised to `84/84`, attached `AUTOGEN_PARENT_UID` to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), replaced generated-output caveats with current IDA evidence notes, and kept reconstruction C++ blank.
  - Evidence: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) is `86/82`; live IDA MCP `lookup_funcs`, `callers`, `callees`, and `xrefs_to` confirm method boundaries, startup constructor caller, three draw callers, constructor-only metadata helper, singleton lifecycle refs, and vtable setup refs. Confidence remains below stronger layout pages because final field names and source-level C++ are not final-audit quality.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the terrain tile library has substantial documentation for purpose, singleton, vtable, layout, tile records, constructor/destructor/draw behavior, file formats, and generated data caveats, but final field names remain medium confidence. Evidence: linked main memory range, destructor page, `g_pMapTileImageLib`, `MapTileImageLibLayout`, `MapTileRecord`, `TILE%d.EPF`/`TILE.TBL` notes, and IDA-confirmed vtable evidence.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: `MapTileImageLib` is a NexusTK-owned class that must be represented in the rebuilt client. Evidence: IDA-confirmed constructor, draw method, destructors, vtable, singleton, owned resource inputs, and startup constructor call. Parent UID and C++ reconstruction remain blank because final source code is below the `95+` gate.
- Method inventory update: existed before with only address literals for constructor, draw method, helper, and scalar deleting destructor; changed to UID links for exact by-memory child pages. Summary: the broad aggregate now has exact children for the constructor, draw method, metadata loader, and scalar deleting destructor. Evidence: IDA function sizes and padding-byte checks on 2026-05-31.
