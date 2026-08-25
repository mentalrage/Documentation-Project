*** UID:00007T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapTileImageLib : public LObject, public Singleton<MapTileImageLib>
{
public:
    MapTileImageLib();
    virtual ~MapTileImageLib();

    void DrawTile(void *drawTarget, const RectBounds *destinationRect, unsigned int tileId);

private:
    ArchiveMetadataTable *tileFrameTable;
    MapTileRecord *tileRecords;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib

## Status

- Confidence: very strong for class ownership, method boundaries, direct `Singleton<MapTileImageLib>` inheritance, RTTI hierarchy, EBO layout, singleton/vtable evidence, helper ownership, and source-file parent; exact historical template-header/static-member spelling remains unrecovered.
- Likely source file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Address ranges: [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md), compiler-instantiated Singleton base destructor [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md), and scalar deleting destructor [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md)
- Vtable: [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- Layout docs: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- Singleton: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- Reconstructable: true; attached to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md). This page emits the complete class declaration with direct `LObject` and empty `Singleton<MapTileImageLib>` bases plus `[[CHILDREN]]`; source-authored children emit method bodies while UID000180, UID0002J2, and raw vtable/RTTI artifacts remain blank/non-emitting compiler products.

## Class Purpose

`MapTileImageLib` is the map terrain tile image library behind `g_pMapTileImageLib`. It loads tile frame metadata from `TILE%d.EPF`, reads per-tile palette/filter metadata from `TILE.TBL`, and draws a terrain tile into a target draw surface.

## Observed Layout

```text
MapTileImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<MapTileImageLib> base (PMD +4/-1/0, EBO)
  +0x04  ArchiveMetadataTable* tileFrameTable (overlaps the empty base)
  +0x08  MapTileRecord* tileRecords
```

The original RTTI complete hierarchy has exactly three entries: `MapTileImageLib`, `LObject`, and direct `Singleton<MapTileImageLib>`. The Singleton BCD uses PMD `+4/-1/0`; empty-base optimization overlaps it with `tileFrameTable`, so the complete object remains `0x0c` bytes.

`MapTileRecord` is 4 bytes: `paletteIndex` in the low 15 bits of each `TILE.TBL` word, `allowPaletteFilter` from the high bit, and one reserved byte. See [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapTileImageLib::MapTileImageLib` | [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) | Directly initializes the Singleton base, whose compiler lowering publishes `this`; loads `TILE%d.EPF` metadata, opens `TILE.TBL`, validates counts, and stores tile records. |
| `~MapTileImageLib` | [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) | Unique handwritten derived cleanup frees metadata and tile records; implicit Singleton base destruction clears the global before `LObject` teardown. |
| `DrawTile` | [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) | Resolves legacy tile ids, loads an `EPFTileContext`, applies palette-filter rules, and dispatches the tile blitter. |
| `LoadTileEpfMetadata` | [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) | File-local/helper metadata loader for tile EPF archive shards. |
| `Singleton<MapTileImageLib>::~Singleton` | [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) | Compiler-instantiated EH-only direct-base destructor; blank/non-emitting, not a class method or clear-helper API. |
| `ScalarDeletingDestructor` | [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) | Compiler ABI wrapper around ordinary derived cleanup, implicit Singleton clear, `LObject` teardown, delete flags, and optional storage free; blank/non-emitting. |

## Evidence Notes

- 2026-06-06 IDA MCP recheck confirms function objects for the constructor `0x004d1860-0x004d199e`, ordinary destructor `0x004d19a0-0x004d1a1c`, draw method `0x004d1a20-0x004d1b72`, metadata loader `0x004d1b80-0x004d1f22`, singleton-clear helper `0x004e5bc0-0x004e5bcb`, and scalar deleting destructor `0x004e66a0-0x004e6748`.
- Constructor callers contain the startup site at `0x004f6055`; `LoadTileEpfMetadata` has the constructor as its only direct caller at `0x004d18d1`; `DrawTile` has three direct callers at `0x00424441`, `0x0050d984`, and `0x005497d0`.
- IDA xrefs to [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) include constructor writes, destructor/scalar-destructor clears, the singleton-clear helper, startup cleanup, and draw consumers. Vtable xrefs to `0x0061b664` come from constructor/destructor setup at `0x004d18bb`, `0x004d19ca`, and `0x004e66d1`.
- Prior generated-output caveats are superseded for scoring by the exact by-memory children: ordinary destructor and singleton-clear helper are real IDA functions even when an emitted generated class view omits them.
- 2026-06-08 Batch133 live IDA recheck confirmed the same method bounds, constructor-only ownership of `LoadTileEpfMetadata`, no direct callers for the scalar deleting destructor, the single startup constructor caller, three `DrawTile` callers, ten `g_pMapTileImageLib` xrefs, and the vtable dwords from `0x0061b660` through the successor `ProtectedArray<HeadInfo>` locator at `0x0061b670`.
- 2026-06-16 A002 live IDA MCP recheck on `b001_mappane_0001AW_20260616` reconfirmed function objects for constructor `0x004d1860`, ordinary destructor `0x004d19a0`, draw method `0x004d1a20`, metadata loader `0x004d1b80`, singleton-clear helper `0x004e5bc0`, and scalar deleting destructor `0x004e66a0`. Current caller evidence remains constructor-only for `LoadTileEpfMetadata`, startup-only for the constructor, data-vtable-only for the scalar deleting destructor, and one exception/unwind xref from the constructor to the singleton-clear helper. `DrawTile` now shows four code xrefs: three modeled callers plus one raw/no-function caller at `0x0050c3d7`.
- 2026-06-17 B003 source-quality recheck resolves the strongest source-facing field/record-name questions for this pass: `+0x04` is `ArchiveMetadataTable *tileFrameTable`, `+0x08` is `MapTileRecord *tileRecords`, the low `TILE.TBL` bits are `MapTileRecord::paletteIndex`, and the high bit is `MapTileRecord::allowPaletteFilter`. The loader remains file-local in `MapTileImageLib.cpp`; the shared archive table type remains shared support, not ownership of this tile-specific helper.
- 2026-06-17 B003 image-library cleanup audit resolves the ordinary/scalar destructor source-form split: [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) now emits first-draft `MapTileImageLib::~MapTileImageLib()`, while [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) remains blank compiler wrapper glue and [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) remains blank constructor/static cleanup glue.
- 2026-06-19 B015 raw PE/source-quality pass confirms [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) is an index-only local-method boundary, not a class owner or emitter. The class owns the constructor, ordinary destructor, draw method, and scalar deleting wrapper child semantics, while [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) and [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) route through the file page. [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) is confirmed by vtable slot `0x0061b664 -> 0x004e66a0` as a separate generated tail support page outside the `0x004d1860-0x004d1f30` aggregate, so aggregate coverage should not nest it under [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md).
- Remaining final-source caveat: IDA still exposes generated names for the constructor/draw/helper bodies and does not prove exact original spelling for shared wrapper types or DAT/allocator helpers. This is a formal C++ integration blocker, not an ownership/source-placement blocker.
- 2026-07-01 B011 source-output incorporation: the accepted report promotes the best-supported declaration spellings `ArchiveMetadataTable *tileFrameTable`, `MapTileRecord *tileRecords`, `MapTileImageLib::MapTileImageLib`, `virtual ~MapTileImageLib`, and `DrawTile(void *drawTarget, const RectBounds *destinationRect, unsigned int tileId)` into the formal block. The direct method inventory and no-duplicate child route are preserved: [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) remains an index-only aggregate, [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) remains compiler ABI wrapper support, [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) remains cleanup glue, and [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) remains a file-local helper, not a class member.
- 2026-07-14 B002 direct-base reanalysis supersedes the old generic-cleanup sentence above: COL `0x00648774`, CHD `0x00648788`, base array `0x00648798`, Singleton BCD `0x006487c4`, PMD `+4/-1/0`, constructor unwind state 1, and ordinary/scalar base-order copies prove direct `Singleton<MapTileImageLib>` inheritance. UID000180 and UID0002J2 are compiler-generated, semantic class-owned, false/non-emitting pages with literally blank formal blocks.

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

- 2026-07-14 B002 UID000180 implementation callback:
  - Raised `88/90` to `92/94` and installed the complete direct `LObject, Singleton<MapTileImageLib>` class declaration.
  - Added exact three-entry RTTI hierarchy, PMD `+4/-1/0`, `0x0c` EBO layout, implicit constructor publication/destructor clear, corrected UID000180 title/identity, and the non-emitting base-destructor/scalar-wrapper split. Preserved all unrelated tile resource, loader, draw, record, and historical evidence.
- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `86/88` to `88/90` and inserted the accepted formal class declaration plus `[[CHILDREN]]`.
  - Preserved the method inventory, `tileFrameTable`/`tileRecords` layout evidence, [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) no-duplicate aggregate policy, [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) compiler-wrapper policy, and [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) cleanup-glue policy. The old "class still needs a coordinated source pass before emitting final class C++" wording is superseded by the accepted callback's source-ready declaration plus child-emitter route.
- 2026-06-17 B003 MapTileImageLib source-quality support update:
  - Standardized layout/record names to `tileFrameTable`, `tileRecords`, `paletteIndex`, and `allowPaletteFilter`.
  - Closed the old helper-placement uncertainty by keeping `LoadTileEpfMetadata` file-local in `NexusTK/render/MapTileImageLib.cpp` while leaving shared archive table declarations with ImageFrameTable/archive metadata support docs.
  - Kept class score and formal C++ unchanged; the constructor/helper target pages carry the score increases, while the class still needs a coordinated source pass before emitting final class C++.
- 2026-06-17 B003 image-library cleanup audit:
  - Class score unchanged, but the ordinary destructor target is now `88/92` with first-draft C++, the scalar deleting destructor is `87/92` with blank formal C++ by compiler-wrapper policy, and the singleton clear helper is `85/90` with blank formal C++ by cleanup-glue policy.
- 2026-06-19 B015 aggregate-boundary support sync:
  - Class score unchanged. Added the index-only policy for [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md), explicit child ownership split, and separate-tail handling for [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) and [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md).
  - Evidence: B015 local PE byte/range checks verify four exact local child bodies with padding through `0x004d1f30`, ObjectStatusBlob ownership after that boundary, and vtable-slot evidence for the scalar deleting destructor at `0x004e66a0`.
- 2026-06-16 A002 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged at [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
  - Evidence: live IDA MCP reconfirmed method/helper starts, caller sets, ten [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) refs, the `0x0061b664` vtable store refs, and the `DrawTile` consumer set including one raw/no-function caller.
  - Blockers checked: final field names, tile-record helper names, record flag semantics, and exact original folder remain below final-source quality because current IDA and support pages prove behavior and layout but not original declaration spelling.
- 2026-06-08 A005 Batch133 parent-gate refresh:
  - Before: `84/84`; direct class parent for [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md) was below the corrected `85/85` gate.
  - After: `85/85`; no parent change because this class was already attached to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
  - Evidence: live IDA MCP reconfirmed all six class method/helper boundaries, caller sets for constructor/draw/helper/deleting destructor, singleton xrefs, and vtable store refs. Confidence remains capped at 85 because final field names and source-level C++ are not final-audit quality.
- 2026-06-06 A004 parent gate and IDA evidence refresh:
  - Before: class was `82/78`, reconstructable but unattached, and still carried generated-data caveats as part of the active confidence explanation.
  - After: raised to `84/84`, attached `AUTOGEN_PARENT_UID` to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), replaced generated-output caveats with current IDA evidence notes, and kept reconstruction C++ blank.
  - Evidence: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) is `86/82`; live IDA MCP `lookup_funcs`, `callers`, `callees`, and `xrefs_to` confirm method boundaries, startup constructor caller, three draw callers, constructor-only metadata helper, singleton lifecycle refs, and vtable setup refs. Confidence remains below stronger layout pages because final field names and source-level C++ are not final-audit quality.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the terrain tile library has substantial documentation for purpose, singleton, vtable, layout, tile records, constructor/destructor/draw behavior, file formats, and generated data caveats, but final field names remain medium confidence. Evidence: linked main memory range, destructor page, `g_pMapTileImageLib`, `MapTileImageLibLayout`, `MapTileRecord`, `TILE%d.EPF`/`TILE.TBL` notes, and IDA-confirmed vtable evidence.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Historical note: `MapTileImageLib` is a NexusTK-owned class that must be represented in the rebuilt client; older wording left parent UID and C++ reconstruction blank below the `95+` gate. B011's 2026-07-01 callback supersedes that with the accepted class declaration and child-emitter route.
- Method inventory update: existed before with only address literals for constructor, draw method, helper, and scalar deleting destructor; changed to UID links for exact by-memory child pages. Summary: the broad aggregate now has exact children for the constructor, draw method, metadata loader, and scalar deleting destructor. Evidence: IDA function sizes and padding-byte checks on 2026-05-31.
