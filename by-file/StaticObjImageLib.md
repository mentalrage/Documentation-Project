*** UID:0000O7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: very strong for class role, source root, resource inputs, direct Singleton lifecycle, H/CPP split, class/file ownership, compiler-support exclusions, and source-facing names; exact original private spellings remain inferred.
- Proposed module: `NexusTK/render/StaticObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Main address ranges: local source/compiler cluster `0x004dcf60-0x004ddf60`, EH-only Singleton base destructor `0x004e5c00-0x004e5c0b`, and scalar deleting compiler wrapper `0x004e6990-0x004e6aa6`.
- Primary global instance: [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- Vtable: [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- Layout docs: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- Header route: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) owns the complete guarded `NexusTK/render/StaticObjImageLib.h`. Its formal CPP includes `StaticObjImageLib.h`, shared `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before `[[CHILDREN]]`, allowing exact method children to use complete archive-table, allocator, and CRT declarations without embedding or duplicating those declarations in this file root.

## File Role

`StaticObjImageLib` is the static map object image library. It owns `SOBJ.TBL` render/lighting object records, `TILEC` tile-class metadata, bounds computation for multi-layer static map objects, and the layered static-object draw path used by live object panes and map-photo composition.

This file should stay near `MapTileImageLib` because both consume tile-sized map art and use 25-slot palette families, but it is a distinct source unit: `SOBJ.TBL` object records and `TILEC.*` resources are static-object-specific.

## Owned Helpers

`BuildTilecArchiveTable` at `0x004dda60-0x004dde01` is only called by the constructor. It scans `TILEC%d.EPF` shards and builds the same packed archive metadata table used by other EPF helpers. The shared `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord` declarations are emitted once through [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) into [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)'s `ImageFrameTable.h`; this source file includes that header rather than defining local copies.

The constructor also calls `LoadImageFrameTable_4D0F50` when legacy mode uses `TILEC.EPD`; this helper is shared and should remain with the broader image-frame metadata module.

IDA confirms `StaticObjImageLib::RenderStaticObject` at [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md). IDA callers are only [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) and [UID:0000MK][PhotoPane](by-file/PhotoPane.md), so it belongs to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) as a class method and emits through this file root.

IDA also confirms the source-authored ordinary destructor at [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) and the EH-only direct [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md). The latter is compiler support caused by class inheritance, not a file-local source helper.

`StaticObjImageLib::GetStaticObjectEntry` at `0x004dda30-0x004dda57` is the one-based `StaticObjEntry *` accessor consumed by `MapPane::CreateStaticObjectPaneForTile` and [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md). Both consumers interpret `StaticObjEntry::lightImageIndex` as a signed LightObjImageLib/table selector and `lightHeightClass` as an exact tile-height placement multiplier.

B003's 2026-06-17 cleanup audit correctly routes the ordinary destructor through [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). UID000184 refines its source form: the authored body emits `staticObjEntries`, `staticObjCount`, `StaticObjEntry::cacheChain`, `tileCatalog`, `ArchiveMetadataTable::records`, and `tileClasses` cleanup only. It uses the accepted `MemoryMan::FreeBufferMemory` API, preserves the two observed `GetMemoryMan()` acquisitions, dereferences `tileCatalog` unconditionally before the conditional records free and unconditional catalog free, and releases `tileClasses` through CRT `free`. The compiler performs the subsequent Singleton clear and `LObject` teardown. The cache-chain branch and unsafe catalog contract are source-significant and must not be normalized into generic deletion or an outer null guard.

B007's Rule 26 source-quality pass extended that method-routing decision to [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md): the renderer is class-owned and this by-file page remains the source-root emitter. B001's 2026-06-26 implementation supersedes the B007 renderer-body readiness decision, not the route: the target's formal method body is intentionally blank because the accepted MCP evidence proves the previous `bool` body changed the renderer's raw `char` return contract. The class H owns `tileCatalog`, `tileClasses`, `staticObjEntries`, `staticObjCount`, `StaticObjEntry` image-index/layer/cache-chain fields, `TileClassEntry` frame/filter fields, the singleton extern, and `char RenderStaticObject(...)`; class CPP includes its owning H, shared ImageFrameTable declarations, MemoryMan API, and CRT declarations before exact children. These inferred names cap confidence below final original-spelling proof, and the renderer body remains blocked only by exact callback typedef, render target type, translated-clip state, and target `+0x90` support declarations.

## Parent-Gate Evidence

This file is the source root for class UID0000E2, whose direct `Singleton<StaticObjImageLib>` base causes [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md). The target has no ordinary caller/callee route; constructor EH state 1 reaches it with ECX adjusted to complete `this+4`. RTTI PMD `+4,-1,0`, EBO, ordinary/scalar inlining, and thirteen singleton refs close the source placement without an independent emitter.

Confidence is now `94` because the file root owns the complete class/header source shape, constructor, authored destructor, render/bounds/accessor/helper family, `SOBJ.TBL`/`TILEC` resources, singleton definition, and consumer split. UID000184 and UID0003M2 are non-emitting compiler support; UID0001PP is non-emitting physical storage; UID0001YX is non-emitting vtable/RTTI. Exact original file/member/helper spellings and unrelated renderer/helper body debt keep the file below final-audit completion.

## Resolved Source Shape And Lifecycle

- `StaticObjImageLib.h` declares `TileClassEntry`, packed variable-tail `StaticObjEntry`, and `class StaticObjImageLib : public LObject, public Singleton<StaticObjImageLib>`, plus the one extern singleton declaration.
- `ImageFrameTable.h` supplies the shared complete `PackedArchiveRecord`, `ArchiveMetadataTable`, and `FrameDrawRecord` declarations through UID0000UN; `StaticObjImageLib.h` retains only the archive-table forward declaration because its class layout stores a pointer.
- `StaticObjImageLib.cpp` includes `StaticObjImageLib.h`, `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before receiving exact child methods through the class `[[CHILDREN]]` route. UID0000SD emits the one definition `StaticObjImageLib *g_pStaticObjImageLib = 0;`.
- Construction publishes the complete object through the direct empty Singleton base. EH state 1 invokes UID000184 with `this+4` if derived construction unwinds.
- The authored destructor contains derived resource cleanup only. Its exact source shape uses `MemoryMan::FreeBufferMemory`, two `GetMemoryMan()` acquisitions, an unconditional catalog dereference, conditional records free, unconditional catalog free, and final CRT tile-class free. Reverse implicit Singleton then `LObject` destruction regenerates the measured clear/base tail. UID0003M2 and UID0001YX are compiler ABI/data artifacts, not source bodies.
- `StaticObjEntry +0x00` is active source-facing `lightImageIndex`, not `lightIntensity`; independent ObjectList/MapPane paths forward it unchanged to LightingObjectPane construction and `SetLightImageIndex`.

B001's renderer repair does not change this file route. The source unit remains `NexusTK/render/StaticObjImageLib.cpp`; only the unsafe renderer method body is suppressed until exact support declarations are available. Generated rows and generated C++ should refresh through validator/generator output only, not by manual edits.

## 2026-07-01 B010 Empty-Emitter Family Implementation

B010's accepted report `tools/leaser/Agents/Agent-B010/research/0000O7-StaticObjImageLib-empty-emitter-family-source-quality.md` used live IDA MCP session `supervisor_resume_20260629` and then-current generated output to audit the StaticObjImageLib file. The generated tracker reported `12` total emitters, `2` filled, and `10` empty, while the visible snapshot had one populated class declaration and only four empty markers: UID0000SD, UID0001PP, UID0000U6, and [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md). That historical mismatch remains generated/tracker freshness evidence, not source-shape authority; UID000184 now supersedes the helper identity and emission policy.

The same MCP pass verified the source placement and marker disposition:

- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md) is the source-facing global definition for the StaticObjImageLib singleton and emits through this file root. The class page keeps only the `extern` declaration.
- [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) is the exact storage page for the singleton and must not duplicate the global definition.
- Current MCP `get_global_value 0x0069b448` returned `0x0`, and `get_bytes 0x0069b448` returned `00 00 00 00`. Earlier `0xffffffff` / `ff ff ff ff` wording was stale and has been corrected on the global/storage pages.
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md) has one constructor caller at `0x004dd0f0` and remains this file's file-local `TILEC%d.EPF` archive-table builder. The helper now emits first-draft formal C++ using the accepted `ArchiveMetadataTable`, `PackedArchiveRecord`, `DATFile`, `HasDATEntry`, `InitRectBounds`, and `DATFile::GetDataPointer` source vocabulary.
- Historical B010 conclusion: UID000184 was described as constructor/static cleanup glue with a no-code comment. UID000184 now supersedes that source form: it is the direct Singleton base destructor, remains blank CPP/H, and is regenerated solely by the class inheritance declaration.

Narrow MCP evidence for this pass included `lookup_funcs` for the local StaticObjImageLib family, `xrefs_to 0x004dda60`, `xrefs_to 0x004e5c00`, `xrefs_to 0x0069b448`, `xrefs_to 0x0061b704`, `get_global_value` / `get_bytes` for `0x0069b448`, byte checks at the constructor/destructor singleton write sites, `disasm` / `decompile` for `0x004e5c00`, and `analyze_function` / `decompile` for `0x004dda60`.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `SOBJ.TBL` | Static object table. `StaticObjImageLib` consumes the full render/lighting view: signed `lightImageIndex`, `lightHeightClass`, a discarded/classification byte, `layerCount`, and per-layer `tileIds`. The former `lightIntensity` name is rejected history because independent create/refresh paths pass this field as an image-table row and use negative values as absence sentinels. |
| `TILEC.EPF` / `TILEC%d.EPF` | Modern static object/tile-decoration image archives. |
| `TILEC.TBL` | Modern tile-class table. |
| `TILEC.EPD` | Legacy static object/tile-decoration image archive. |
| `TILEC.TBD` | Legacy tile-class table. |
| `TILEC.PAL` | Palette slot `1` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

`SOBJ.TBL` also has a second map-initialization parser view documented at [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md). `StaticObjImageLib` owns the full render/resource table; [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) is only a compact map-gameplay classification cache built from the same records.

`TILEC` stays with this file's class context: modern mode uses `TILEC.EPF` / `TILEC%d.EPF` archive metadata plus `TILEC.TBL`, while legacy mode uses `TILEC.EPD` and `TILEC.TBD`. `TILEC.PAL` is PaletteLib slot-1 context rather than a `StaticObjImageLib` member.

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md)
- [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-12 B005 UID000184 C184-029 implementation: preserved `90/94`, owner `FILE`, and `NexusTK/render/`; documented `ImageFrameTable.h` as the sole shared archive-declaration route, made the class CPP dependency order explicit, and recorded the accepted MemoryMan/two-acquisition/unconditional-catalog destructor contract while retaining all lifecycle, renderer, resource, and historical evidence.

- 2026-08-11 B005 UID000184 file-root implementation: raised `88/88` to `90/94`, preserved owner `FILE` and `NexusTK/render/`, documented the complete class H/CPP split, direct Singleton lifecycle, authored destructor boundary, non-emitting target/scalar/vtable/storage support, sole global definition, active `lightImageIndex`, and superseded helper/comment/sentinel assumptions.

- 2026-08-11 B003 UID00023D source-root synchronization: preserved `88/88`, owner `FILE`, and `NexusTK/render/`. Recorded the complete class H route, exact CPP include/child route, two current `GetStaticObjectEntry` consumers, signed `lightImageIndex`/`lightHeightClass` semantics, and the ObjectList lighting-sync dependency. Historical intensity terminology remains explicitly rejected rather than deleted; all renderer/lifecycle/resource and singleton-source facts remain intact.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers class role, singleton/vtable/layout anchors, owned helpers, destructor/render body ownership, resource inputs, SOBJ/TILEC split, dependencies, and cross-references; confidence remains capped by exact original filename and current generated-output omissions.
- 2026-05-31: Reconstruction path was blank even though the proposed tree already places this module under `render/StaticObjImageLib.cpp`.
  - Before: `PROPOSED_RECONSTRUCTION_PATH:""`.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Evidence: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md) and [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) rechecked the constructor/render/destructor ownership against IDA MCP, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/StaticObjImageLib.cpp` as the planned source file.
- 2026-06-06: Corrected destructor range wording.
  - Before: the page listed the scalar deleting destructor with last-byte-style end `0x004e6aa5` and the ordinary destructor link inherited the old `0x004dd2bd` end.
  - After: the status line uses scalar destructor range `0x004e6990-0x004e6aa6`, and the owned-helper paragraph records ordinary destructor exclusive end `0x004dd2be` while its filename rename is pending.
  - Evidence: IDA MCP `lookup_funcs` reports `sub_4DD1E0` as `0xde` bytes ending at `0x004dd2be`, and earlier aggregate evidence already confirmed `sub_4E6990` ends at `0x004e6aa6`.
- 2026-06-08 A003 Batch122: Raised confidence from `80` to `85`.
  - Before: the file had strong source-role documentation but did not explicitly support strict `85/85` routing for the singleton clear helper.
  - Historical after-state: added parent-gate evidence tying constructor/destructor/render/bounds/archive-helper/singleton/scalar evidence to this file root and documented [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md) as direct cleanup-glue ownership. The direct-base compiler-support interpretation above supersedes that ownership conclusion.
  - Evidence: Batch122 IDA `lookup_funcs`, `decompile`, `callers`, `callees`, `xrefs_to`, and byte review for `0x004e5c00`, `0x0069b448`, and neighboring helper boundaries.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad StaticObjImageLib memory aggregate is now [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md), and the scalar deleting destructor now has [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md).
  - Evidence: live IDA `entity_query`, `xrefs_to`, `callees`, and `decompile` on 2026-06-12 show the local StaticObjImageLib neighborhood includes helpers at `0x004dd8b0`, `0x004dda30`, and `0x004dde10`, then ends before EffectObjImageLib at `0x004ddf60`; the old broad range crossed later sibling owners.
- 2026-06-17 B003 StaticObjImageLib cleanup/source-quality support update:
  - Score unchanged at `86/85` for the file root.
  - Summary/evidence: incorporated B003's ordinary-destructor direct-owner correction and source-form audit. [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) now belongs directly to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), should emit first-draft destructor C++, and should preserve the documented `StaticObjEntry::cacheChain` cleanup semantics instead of treating the table as a simple `delete[]`.
- 2026-06-21 B007 Rule 26 incorporation:
  - Score unchanged at `86/85` for the file root.
  - Summary/evidence: recorded that [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) now has declaration-level C++ readiness, [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md) routes through the class, field names are source-facing descriptive rather than final original spellings, and `BuildTilecArchiveTable` / singleton cleanup glue remain file-root context.
- 2026-06-26 B001 renderer return-contract implementation:
  - Score unchanged at `86/85` for the file root.
  - Summary/evidence: preserved this file as the source-root emitter for [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), but recorded that [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md) no longer emits the prior `bool` method body. B001's accepted MCP evidence shows the exact renderer return is raw `char`: invalid paths return `0`, success returns `0xff`, the load-error guard returns the low byte of the initialized local draw-record pointer, and `sub_5379A0` forwards that raw byte. The renderer body stays blank until callback/render-target/translated-clip/target-`+0x90` declarations are source-quality.
- 2026-07-01 B010 StaticObjImageLib empty-emitter family implementation:
  - Raised from `86/85` to `88/88`.
  - Historical summary/evidence: incorporated B010's four visible empty-marker findings, including [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md), while the tracker still said `12/2/10`. The pass also verified zero storage, thirteen singleton refs, one constructor xref to UID0000U6, exact UID000184 bytes, and `TILEC%d.EPF` behavior. UID000184 now preserves that evidence while superseding the helper/no-code-comment source conclusion.
