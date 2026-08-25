*** UID:0000L5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MapTileImageLib

## Status

- Confidence: very strong for class role, direct Singleton lifetime, helper/global/method ownership, RTTI/vtable/layout routing, and file-root placement; exact original filename and some lexical helper spellings remain bounded aliases.
- Proposed module: `render/MapTileImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_MapTileImageLib.cpp`
- Main address ranges: `0x004d1860-0x004d1f30`, compiler-instantiated Singleton base destructor `0x004e5bc0-0x004e5bcb`, and scalar destructor `0x004e66a0-0x004e6748`
- Primary global instance: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- Vtable: [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- Layout docs: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)

## File Role

`MapTileImageLib` is the terrain tile image library. It owns the loaded map-tile EPF metadata table, the `TILE.TBL` palette/filter table, and the draw path that resolves a tile id into an `EPFTileContext` and selected palette.

This should stay separate from [UID:0000K2][ImageLib](by-file/ImageLib.md). `ImageLib`/`ResourceLayoutTable` provide general EPF/EPD frame lookup, while `MapTileImageLib` owns map-tile-specific metadata, legacy tile-id correction, palette-filter gating, and the terrain-tile draw wrapper.

## Owned Helpers

`LoadTileEpfMetadata` at `0x004d1b80-0x004d1f22` is only called by the `MapTileImageLib` constructor. It scans `TILE%d.EPF` archives, reads their shared frame-record headers, merges them into one `ArchiveMetadataTable`, and appends a sentinel record. Keep this helper file-local in `NexusTK/render/MapTileImageLib.cpp`: the shared `ArchiveMetadataTable`/packed-record declaration belongs with ImageFrameTable/archive metadata support docs, but the shard naming and merge policy are tile-resource specific.

`MapTileImageLib::DrawTile` also calls `LoadFrameDrawRecord_4D1600` to resolve one frame from the loaded metadata table before dispatching the low-level tile blitter.

IDA also confirms an ordinary non-deleting destructor at [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md). Its unique handwritten body frees `tileFrameTable->records`, `tileFrameTable`, and `tileRecords`. The following global clear is implicit direct `Singleton<MapTileImageLib>` base destruction and is intentionally absent from the formal body; exact helper spellings such as `GetMemoryMan`/`MemoryManager::Free` remain bounded source-facing aliases.

[UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) and [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) remain out of handwritten formal C++. UID000180 is the EH-only compiler-instantiated direct-base destructor: constructor state 1 adjusts the complete receiver by `+4` and tail-jumps at `0x005ff9bb`, matching the Singleton RTTI BCD PMD `+4/-1/0`. UID0002J2 is vtable ABI glue at `0x0061b664 -> 0x004e66a0`, expanding the ordinary derived cleanup, implicit Singleton clear, `LObject` teardown, delete flags, size guard, and storage free. Both exact managed blocks are literally blank.

Historical B003/B011/B015 interpretation: UID000180 was described as a probable constructor/static cleanup helper because the zero-store body had no ordinary caller. That interpretation is superseded by the exact constructor FuncInfo/unwind action, adjusted receiver, original three-entry RTTI hierarchy, EBO, and ordinary/scalar base-order copies. The historical helper names remain useful provenance but are not current source APIs.

B015's 2026-06-19 local PE recheck confirms [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) should stay as a non-emitting index over the four exact local bodies, not a file-level source aggregate.

2026-07-01 B011 empty-emitter-family implementation supersedes the old generated-output split. The accepted report used MCP session `8f7e4b74` and generated header `validator-command-id: 000000003584`, `validator-refreshed-at: 2026-07-01T06:21:25-04:00` as the pre-implementation baseline, where `MapTileImageLib.cpp` emitted only [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) and carried empty markers for the class, constructor, draw method, metadata helper, scalar deleting destructor, layout, record, vtable, singleton global, singleton storage, by-item helper alias, and singleton clear helper. Those markers should now be replaced by the formal class/type/global declarations, constructor, DrawTile, metadata helper body, and formal no-code/covered-by comments accepted for duplicate or compiler/generated support pages.

Source-root disposition is unchanged: `NexusTK/render/MapTileImageLib.cpp` remains the source root for `MapTileImageLib`, `TILE%d.EPF`, `TILE.TBL`, `TILE.TBD`, the sole typed singleton definition, direct `Singleton<MapTileImageLib>` class lifetime, record/layout support, vtable support, constructor, draw path, metadata helper, and ordinary destructor. Rejected owner alternatives remain rejected: [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), DATFile support, `MapPane`, `PhotoPane`, and the local-method aggregate are consumers, shared primitives, or indexes rather than declaration owners.

## 2026-07-14 B002 Direct Singleton Source Route

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) emits a complete `class MapTileImageLib : public LObject, public Singleton<MapTileImageLib>` declaration. Original RTTI COL `0x00648774`, CHD `0x00648788`, base array `0x00648798`, and Singleton BCD `0x006487c4` prove the exact three-entry hierarchy and PMD `+4/-1/0`.
- Empty-base optimization overlaps the Singleton base and `tileFrameTable` at `+0x04`; `tileRecords` remains at `+0x08`, and complete size remains `0x0c`.
- [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) explicitly initializes the Singleton base. Compiler lowering owns publication at `0x004d18a3`, fallback clear at `0x004d18aa`, and constructor state-1 EH destruction through UID000180; the body contains no manual global assignment.
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) emits only the unique resource frees. Implicit Singleton base destruction owns the clear at `0x004d19f9` before `LObject` teardown.
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) remains the one typed global definition. [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md) is covered storage only. Ten direct refs span base lifetime, Application shutdown, and map/photo consumers; no duplicate definition or manual method assignment is emitted.
- No handwritten raw vtable/RTTI table, base-destructor function, scalar deleting wrapper, static-cleanup callback, or public/file-local singleton-clear helper belongs in this source module. The class declaration and compiler ABI regenerate those artifacts.
- This by-file root remains prose-only and intentionally has no `RECONSTRUCTION_CPP` metadata.

## 2026-06-08 Batch133 Parent-Gate Evidence

Live IDA MCP rechecked the file parent evidence against `NexusTK.exe` `sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`:

- Function bounds remained stable for constructor `0x004d1860-0x004d199e`, ordinary destructor `0x004d19a0-0x004d1a1c`, draw method `0x004d1a20-0x004d1b72`, metadata loader `0x004d1b80-0x004d1f22`, singleton clear helper `0x004e5bc0-0x004e5bcb`, and scalar deleting destructor `0x004e66a0-0x004e6748`.
- `callers` reports the constructor's single startup caller at `0x004f6055`, `DrawTile` callers at `0x00424441`, `0x0050d984`, and `0x005497d0`, and the metadata loader called only from the constructor at `0x004d18d1`.
- `xrefs_to 0x0067a75c` reports the expected singleton lifecycle/draw references, including constructor writes at `0x004d18a3`/`0x004d18aa`, destructor clear at `0x004d19f9`, clear helper `0x004e5bc0`, scalar deleting destructor clear at `0x004e6700`, startup cleanup `0x004f6622`, and draw consumers.
- `py_eval` and `xrefs_to` reconfirm the vtable locator/table at `0x0061b660/0x0061b664`, vtable stores at `0x004d18bb`, `0x004d19ca`, and `0x004e66d1`, and the successor `ProtectedArray<HeadInfo>` locator at `0x0061b670`.

Historical 2026-06-08 score observation: this raised confidence only to the then-current parent gate. The 2026-07-14 direct-base integration supersedes that active cap; current score is `91/93`, with only exact original filename and lexical helper spellings remaining uncertain.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed the same file-root shape and improved the current evidence set:

- Function objects remain stable for constructor `0x004d1860`, ordinary destructor `0x004d19a0`, `DrawTile` `0x004d1a20`, metadata loader `0x004d1b80`, singleton-clear helper `0x004e5bc0`, and scalar deleting destructor `0x004e66a0`.
- `xrefs_to` reports the single startup constructor caller at `0x004f6055`, the constructor-only metadata-helper call at `0x004d18d1`, and four `DrawTile` call sites at `0x00424441`, raw/no-function `0x0050c3d7`, `0x0050d984`, and `0x005497d0`.
- Singleton and vtable anchors are still clean: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) has ten lifecycle/draw refs, and `0x0061b664` has exactly the constructor, ordinary-destructor, and scalar-deleting-destructor vtable stores.
- IDA string search finds RTTI names for `MapTileImageLib` and its `Singleton` wrapper, but no embedded `MapTileImageLib.cpp` filename. `search_structs MapTileImageLib` returns no local IDA struct/type record.
- Active `simroot_v2/class_MapTileImageLib.cpp` now covers constructor, `DrawTile`, scalar deleting destructor, and `g_pMapTileImageLib`, but a targeted generated-output check found no `0x004d19a0` ordinary destructor or `0x004e5bc0` singleton-clear helper entry in the active C++ file. Keep the exact by-memory pages in the final migration plan.

Historical 2026-06-16 score observation: this raised the file root to `87/86`. It is preserved as evidence-time provenance; current integrated score is `91/93`.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `TILE%d.EPF` | Modern mode map-tile frame/pixel archive shards scanned by `LoadTileEpfMetadata`. |
| `TILE.TBL` | Per-tile table read by the constructor; stores tile palette index and high-bit palette-filter flag. |
| `TILE.TBD` | Legacy mode tile-count guard used by `DrawTile` to clamp invalid tile ids to `0`. |
| `TILE.PAL` | Palette slot `0` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)

## Changes

- 2026-07-14 B002 UID000180 implementation callback:
  - Raised `88/88` to `91/93` without adding prohibited by-file reconstruction metadata.
  - Added the direct Singleton class/constructor/destructor/global route, exact RTTI/PMD/EBO and EH evidence, implicit publication/clear order, literal blank UID000180/UID0002J2 disposition, sole global/storage split, rejected alternatives, and historicalized prior helper/static-cleanup wording. Preserved all unrelated tile loading, resources, draw, metadata-loader, source-tree, aggregate, and provenance detail.
- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `87/86` to `88/88`.
  - Added accepted source-root/generated-output disposition for baseline generated header `000000003584` / `2026-07-01T06:21:25-04:00`, the empty-marker family, rejected owner alternatives, stale blank-C++ supersession, and expectation that regenerated `auto-generated/NexusTK/render/MapTileImageLib.cpp` contains the destructor plus class/type/global declarations, constructor, DrawTile, metadata helper, and no-code/covered-by comments for generated or duplicate support pages.
- 2026-06-17 B003 MapTileImageLib cleanup/source-quality support update:
  - Kept `LoadTileEpfMetadata` in `NexusTK/render/MapTileImageLib.cpp` and rejected moving it to ImageFrameTable or DATFile absent new source evidence.
  - Incorporated B003's ordinary-destructor source-form decision: [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) should emit first-draft `MapTileImageLib::~MapTileImageLib()` with `tileFrameTable`, nested `ArchiveMetadataTable::records`, `tileRecords`, and `g_pMapTileImageLib` cleanup.
  - Recorded the no-code source-form split for [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) and [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md): the first is constructor/static cleanup glue, and the second is compiler deleting-destructor ABI glue.
  - No file-root score or path change was needed.
- 2026-06-19 B015 aggregate/source-routing support sync:
  - File score unchanged. Added that [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) is not a source-emitting file aggregate, and that generated output should continue to reflect the child readiness split instead of fabricating aggregate C++.
  - Evidence: B015 raw PE scan confirms exact local child boundaries, `0x004d1f22-0x004d1f30` padding before ObjectStatusBlobParsers, `0x004e5bc0` singleton-clear tail, and `0x004e66a0` scalar deleting destructor vtable-slot evidence.
- 2026-06-08 A005 Batch133 parent-gate refresh:
  - Before: `86/82`, below the corrected confidence gate for [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) and [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md).
  - Changed to: `86/85`.
  - Summary/evidence: live IDA MCP reconfirmed the method/helper bounds, constructor/draw/helper caller sets, singleton xrefs, vtable dwords/store refs, and successor RTTI boundary. The file now clears the parent-side gate for direct `MapTileImageLib` class/type children, while final source naming keeps confidence capped at 85.
- 2026-06-16 A001 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Evidence: live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed all six method/helper starts, the startup constructor caller, constructor-only metadata loader, four `DrawTile` call sites including raw/no-function `0x0050c3d7`, ten singleton refs, and the clean `0x0061b664` vtable store set. IDA RTTI confirms class names but no `.cpp` filename or local struct; generated C++ still omits the ordinary destructor and singleton-clear helper, keeping final source shape below higher confidence.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: terrain tile image-library role, singleton/vtable/layout anchors, resource inputs, owned metadata loader, destructor gap, `ImageLib` split, and palette/frame dependencies are documented; confidence is capped by exact original filename and helper sharing with image-frame metadata.
- 2026-05-31 projected reconstruction path:
  - What existed before: blank `PROPOSED_RECONSTRUCTION_PATH`.
  - Changed to: `NexusTK/render/`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `MapTileImageLib.cpp` under `render/`, and IDA confirms this class is a distinct terrain tile image-library module with one startup constructor caller, owned singleton [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), owned layout [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), and owned tile resources.
- 2026-05-31 half-open range correction:
  - What existed before: the main helper/scalar ranges used `0x004d1f21` and `0x004e6747` endpoints.
  - Changed to: `0x004d1f22` and `0x004e6748`.
  - Summary/evidence: IDA `lookup_funcs` reports `LoadTileEpfMetadata` at `0x004d1b80` with size `0x3a2` and scalar deleting destructor at `0x004e66a0` with size `0xa8`, so the by-memory half-open endpoints are `0x004d1f22` and `0x004e6748`.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad MapTileImageLib memory aggregate is now [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md), a non-emitting local cluster ending before [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md).
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the old `0x004d1860-0x004e6748` aggregate crossed independent sibling owners and should not be treated as a single reconstructable range.
