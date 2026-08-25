*** UID:0000E2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "StaticObjImageLib.h"
#include "ImageFrameTable.h"
#include "../util/MemoryMan.h"
#include <stdlib.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_STATICOBJIMAGELIB_H
#define NEXUSTK_RENDER_STATICOBJIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

struct ArchiveMetadataTable;
struct Rect;
struct GrafPort;
struct StaticObjectDrawRequest;

struct TileClassEntry
{
    unsigned short tileFrameId;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

#pragma pack(push, 2)
struct StaticObjEntry
{
    int lightImageIndex;
    unsigned char lightHeightClass;
    unsigned char layerCount;
    unsigned short reserved;
    StaticObjEntry *cacheChain;
    unsigned short tileIds[1];
};
#pragma pack(pop)

class StaticObjImageLib : public LObject,
                          public Singleton<StaticObjImageLib>
{
public:
    StaticObjImageLib();
    virtual ~StaticObjImageLib();

    char RenderStaticObject(GrafPort *target,
                            StaticObjectDrawRequest *request,
                            unsigned short staticObjectId,
                            void *overlayBuffer,
                            float overlayAlpha,
                            bool enableBlendClip);
    void GetStaticObjectBounds(unsigned short staticObjectId, Rect *outBounds) const;
    bool HitTestStaticObjectPixel(unsigned short staticObjectId,
                                  int localX,
                                  int localY) const;
    StaticObjEntry *GetStaticObjectEntry(unsigned short staticObjectId) const;

private:
    ArchiveMetadataTable *tileCatalog;
    TileClassEntry *tileClasses;
    StaticObjEntry **staticObjEntries;
    int staticObjCount;
};

extern StaticObjImageLib *g_pStaticObjImageLib;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: strong for constructor/destructor, bounds helper, singleton/vtable ownership, resource inputs, source-file placement, and source-facing descriptive field names; original identifier spellings remain inferred rather than source-proven.
- Likely source file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Address ranges: [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md), Singleton base destructor [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md), and scalar deleting destructor [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Vtable: [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- Layout docs: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- Singleton: [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- Parent attachment: attached to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). The complete guarded class/resource declaration lives in the formal H channel; CPP includes `StaticObjImageLib.h`, shared `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before routing exact method children through `[[CHILDREN]]`. The ordinary destructor, renderer, accessor, and other exact method pages remain the sole owners of their bodies.

## Class Purpose

`StaticObjImageLib` is the static map object image library behind `g_pStaticObjImageLib`. It parses full render/lighting records from `SOBJ.TBL`, loads `TILEC` archive metadata, reads tile-class records, renders layered static-object tiles for live panes and photo composition, exposes bounds/pixel/entry helpers, and returns tile-aligned bounds for static-object ids.

## Observed Layout

```text
StaticObjImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<StaticObjImageLib> base (EBO overlap)
  +0x04  ArchiveMetadataTable* tileCatalog
  +0x08  TileClassEntry* tileClasses
  +0x0c  StaticObjEntry** staticObjEntries
  +0x10  int staticObjCount
```

`StaticObjEntry` records use source-facing descriptive fields `lightImageIndex`, `lightHeightClass`, `layerCount`, `reserved`, `cacheChain`, and inline `tileIds`. Historical `lightIntensity`, `objectId`, `paletteGroup`, and `nameLength` labels are rejected/generated alternatives: the record index/caller argument is the static-object id; `+0x00` is a signed LightObjImageLib/table row whose negative sentinel removes or suppresses lighting; `+0x04` feeds exact tile-height placement; and `+0x05` is the layer/tile-id count.

`TileClassEntry` records are 4 bytes: `tileFrameId` is the low-15-bit `TILEC` value, `allowPaletteFilter` is the encoded high-bit predicate used by the renderer, and `reserved` is the unused stride byte. `paletteRemapFlag` and `highBitSet` are retained only as mechanical/historical aliases; `allowPaletteFilter` better describes the render branch that skips draw/remap when palette filtering is active and the flag is clear.

The shared resource layout and the second compact map-cache parser are tracked in [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md). This class owns the full static-object render/resource view, while [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) is map-gameplay cache state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `StaticObjImageLib::StaticObjImageLib` | `0x004dcf60` | Loads `SOBJ.TBL`, then loads `TILEC` archive/table resources depending on modern/legacy mode. |
| `~StaticObjImageLib` | `0x004dd1e0` | Source-authored derived cleanup uses `MemoryMan::FreeBufferMemory`, preserves two `GetMemoryMan()` acquisitions and unconditional archive-catalog dereference, and releases tile classes through CRT `free`. Reverse implicit base destruction then clears the singleton through `Singleton<StaticObjImageLib>` and tears down `LObject`. |
| `RenderStaticObject` | `0x004dd2c0` | Draws layered static-object tiles and optional overlay masks; [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md) routes through this class owner with an exact binary `char` return contract. Formal method-body C++ is intentionally blank on the target until the shared callback/render-target/translated-clip support declarations are exact. |
| `GetStaticObjectBounds` | `0x004dd850` | Returns local bounds based on object layer count and global tile dimensions. |
| `HitTestStaticObjectPixel` | `0x004dd8b0` | StaticObjectPane pixel/solid-mask helper; source-authored class helper still represented by the local cluster until exact child review. |
| `GetStaticObjectEntry` | `0x004dda30` | Tiny one-based static-object entry accessor used by `MapPane::CreateStaticObjectPaneForTile` and `ObjectList::RefreshStaticObjectLighting`. It returns the `StaticObjEntry *` needed by the formal cross-file consumers. |
| `BuildTilecArchiveTable` | `0x004dda60` | File-local helper that probes numbered `TILEC%d.EPF` shards and builds the modern packed archive metadata table. |
| `LoadStaticObjectRecords` | `0x004dde10` | Source-like retained `SOBJ.TBL` record loader body with no current xrefs; keep in the non-emitting local cluster until exact child review. |
| compiler Singleton base destructor | `0x004e5c00` | EH-only out-of-line destructor for the direct empty `Singleton<StaticObjImageLib>` base; constructor state 1 reaches it with ECX equal to complete `this + 4`. It has no authored source body or formal emission. |
| `DeletingDestructor` | `0x004e6990` | Compiler scalar deleting destructor wrapper; class-owned ABI glue with formal C++ intentionally blank because `virtual ~StaticObjImageLib()` regenerates it. |

## Resource And Ownership Decisions

- The class owns the full `SOBJ.TBL` render/lighting view. [UID:0000L3][MapPane](by-file/MapPane.md) and [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) own only the compact `g_objectNationMap` classification cache view over the same payload.
- The class owns `TILEC` static-object tile-class interpretation: modern `TILEC.EPF` / `TILEC%d.EPF` archive metadata plus `TILEC.TBL`, and legacy `TILEC.EPD` plus `TILEC.TBD`. `TILEC.PAL` remains PaletteLib slot-1 context, not a class field.
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), [UID:0000MK][PhotoPane](by-file/PhotoPane.md), [UID:0000L3][MapPane](by-file/MapPane.md), and ObjectList paths are consumers or caller contexts. They do not own this image-library class, its singleton, vtable, resource tables, or renderer.
- UID00023D's `ObjectList::RefreshStaticObjectLighting` is a direct cross-file consumer. It requires this H to expose `StaticObjEntry`, `GetStaticObjectEntry`, and `g_pStaticObjImageLib`; that visibility is now formal instead of relying on a declaration embedded in generated CPP.
- Direct file ownership for every method is too broad. Class methods route through [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md), which emits through [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). `BuildTilecArchiveTable` remains a file-local helper, while constructor-unwind Singleton destruction, scalar deletion, vtable data, and RTTI are compiler support caused by this class declaration and do not emit independent source.
- B010's 2026-07-01 accepted empty-emitter family report preserves this class page as declaration-level support only. [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md) now emits the source global definition `StaticObjImageLib *g_pStaticObjImageLib = 0;`, while this class declaration keeps only `extern StaticObjImageLib *g_pStaticObjImageLib;`. [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) is exact storage support and no longer claims a stale `0xffffffff` initializer. [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md) now emits first-draft formal C++ through the StaticObjImageLib file root, but its helper body is not part of the class declaration block.
- Shared archive declarations are owned once by [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) through [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) and emitted in `ImageFrameTable.h`. This class H needs only the `ArchiveMetadataTable` forward declaration because it stores a pointer; the class CPP includes the complete shared header because `BuildTilecArchiveTable` and the destructor allocate or dereference that type. `MemoryMan.h` and `<stdlib.h>` similarly provide the exact allocator method and CRT `free` declarations consumed by method children.

## IDA-Backed Ownership Notes

- Live IDA confirms the constructor has one startup caller at `0x004f607b`, while `RenderStaticObject` is only called by [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) and [UID:0000MK][PhotoPane](by-file/PhotoPane.md).
- B001's 2026-06-26 renderer recheck corrects the class declaration for `RenderStaticObject` from a source-safe `bool` sketch to the exact binary `char` return contract. IDA MCP session `80de0a67` reports the renderer prototype as `char __thiscall(void *this, int, int *, unsigned __int16, int *, float, char)`, and the StaticObjectPane caller at `0x005379c3` forwards that raw byte result. Pane-facing call sites may still compare the result to nonzero when documenting pane behavior, but the class method itself is not a normalized `bool` API.
- `GetStaticObjectBounds` is used by map/object setup, [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), and [UID:0000MK][PhotoPane](by-file/PhotoPane.md), keeping the helper with this class rather than those consumers.
- `BuildTilecArchiveTable` is constructor-only; it probes numbered `TILEC%d.EPF` shards and constructs a packed archive metadata table for the modern resource path.
- `g_pStaticObjImageLib` has 13 live IDA xrefs spanning Singleton construction publication/null handling, constructor-unwind base destruction, implicit ordinary/scalar base destruction, shutdown, map/static-object consumers, and photo composition.
- StaticObjImageLib vtable slot `0x0061b704` is written by the constructor, ordinary destructor, and scalar deleting destructor; the vtable data page records the neighboring `.rdata` boundary.
- The aggregate [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md) now records the exact live local function inventory, state/resource map, and remaining source-gate caveats.
- UID000184 reanalysis identifies [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md) as the compiler-emitted destructor for the direct empty Singleton base: exact `0xb` body, no ordinary callers/callees, sole constructor EH state-1 jump, ECX equal to complete `this + 4`, and RTTI PMD `+4,-1,0`.
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) directly emits only the source-authored derived cleanup for `staticObjEntries`, `StaticObjEntry::cacheChain`, `tileCatalog`, and `tileClasses`. It uses the accepted `MemoryMan::FreeBufferMemory` API, preserves two observed `GetMemoryMan()` acquisitions, dereferences `tileCatalog` unconditionally before conditionally freeing records and unconditionally freeing the catalog, and ends with CRT `free(tileClasses)`. The compiler supplies reverse `Singleton<StaticObjImageLib>` then `LObject` base destruction; an explicit source clear is incorrect.

## Direct Singleton Lifecycle And Compiler Support

- Source hierarchy: `StaticObjImageLib` directly inherits `LObject` and empty `Singleton<StaticObjImageLib>` in that order. MSVC RTTI lists the derived type, `LObject`, and the Singleton specialization; the Singleton BCD PMD is `+4,-1,0`.
- Storage remains exactly `0x14` bytes. Empty-base optimization overlaps the Singleton subobject address at `+0x04` with the first derived member `tileCatalog`; no fake Singleton field belongs in the class layout.
- Construction publishes the complete-object pointer through the Singleton base before derived resource work. EH state 1 reaches UID000184 with the adjusted base receiver if later construction unwinds.
- The authored destructor cleans derived resources only. Reverse base destruction invokes the Singleton destructor, which clears `g_pStaticObjImageLib`, then invokes `LObject::~LObject`.
- UID0003M2 is the compiler scalar deleting wrapper and UID0001YX is compiler vtable/RTTI data. Both remain blank non-emitting support; the virtual ordinary destructor and complete class hierarchy regenerate them.
- The global definition remains exactly `StaticObjImageLib *g_pStaticObjImageLib = 0;` through UID0000SD. This H supplies the only `extern` declaration.

## Data Caveats

- Historical Wave3 metadata reported `vtable_count: 0`; it is obsolete and not evidence. Current IDA/type documentation confirms the primary vtable at `0x0061b704`.
- The pre-UID000184 generated snapshot placed class declarations in CPP and emitted a singleton-clear marker. That output is historical lag, not source-shape authority; the accepted class H, CPP child route, and non-emitting compiler-support dispositions control the next coherent generated refresh.
- The post-lifecycle pre-C184-029 class CPP included only `StaticObjImageLib.h`. That was sufficient for the owning declaration but incomplete for method children that dereference `ArchiveMetadataTable`, call `MemoryMan::FreeBufferMemory`, or invoke CRT `free`. The dependency-complete CPP route now includes shared `ImageFrameTable.h`, `MemoryMan.h`, and `<stdlib.h>` before `[[CHILDREN]]`; this correction does not move method bodies into the class page.
- Older `source-3/simroot_v2/class_StaticObjImageLib.cpp` contains useful constructor, renderer, bounds, and scalar-wrapper source leads, but uses stale inclusive/last-byte range ends and raw/global names. Treat it as a source lead, not as authority over owner routing or final names.
- B001 supersedes the B007 renderer C++ readiness note: the renderer target remains reconstructable and class-owned, but its formal method body must not be emitted while the exact shared surface callback typedef, render target type, translated-clip state, and target `+0x90` field are not source-quality declarations. The target page now carries a no-code proof instead of the previous behaviorally wrong `bool` body.
- Generated and older docs called the third `SOBJ.TBL` per-record byte a name length. IDA render evidence uses the corresponding in-memory byte as `layerCount`, with `uint16` tile ids following the fixed header.
- Original source spellings for `tileCatalog`, `tileClasses`, `staticObjEntries`, `staticObjCount`, `lightImageIndex`, `lightHeightClass`, `cacheChain`, `tileFrameId`, and `allowPaletteFilter` are not proven. They are strong descriptive names suitable for first-draft C++, but confidence remains below final-audit levels. `lightIntensity` is preserved only as a superseded historical inference.

## Score Rationale

- `COMPLETION:92`: the page carries the complete formal H declaration, dependency-complete deterministic CPP child route, exact direct-base hierarchy, EBO layout, constructor/unwind/ordinary/scalar lifecycle, global declaration/definition split, compiler-support exclusions, resource ownership, method surface, shared archive-table visibility, accepted allocator/CRT dependencies, and cross-consumer `lightImageIndex` semantics. Unrelated renderer-body and remaining helper-body work still limits whole-class completion.
- `CONFIDENCE:96`: RTTI, PMD, constructor EH states, exact object size, ordinary/scalar destruction, singleton xrefs, and independent StaticObjEntry consumers agree. The remaining uncertainty is original private identifier spelling and unrelated renderer support declarations, not the resolved Singleton lifecycle.

## Historical Superseded Assumptions

- Earlier pages treated `0x004e5c00` as a file-level source-owned singleton clear helper or generic static cleanup hook. The exact body/effect evidence remains valid, but direct-base RTTI, PMD `+4`, EBO, adjusted EH receiver, and inlined normal/scalar copies supersede that source interpretation.
- Earlier destructor C++ explicitly assigned `g_pStaticObjImageLib = 0`. The compiled instruction is real, but it is generated by implicit reverse Singleton base destruction and therefore does not belong in the authored derived destructor body.
- Earlier active declarations used `lightIntensity` at `StaticObjEntry +0x00`. UID00023D proves unchanged flow to `LightingObjectPane` construction and `SetLightImageIndex`; `lightIntensity` is retained only as rejected history.

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

- 2026-08-12 B005 UID000184 C184-029 implementation: preserved `92/96`, owner/emitter UID0000O7, reconstructability, and the complete class H; made formal CPP dependency-complete by adding `ImageFrameTable.h`, `../util/MemoryMan.h`, and `<stdlib.h>` before `[[CHILDREN]]`, documented why shared declarations belong in ImageFrameTable H, and recorded the exact MemoryMan/two-acquisition/unconditional-catalog destructor contract while preserving prior lifecycle and renderer evidence.

- 2026-08-11 B005 UID000184 lifecycle implementation: raised `88/89` to `92/96`, preserved owner/emitter UID0000O7 and reconstructable status, changed formal CPP to `[[CHILDREN]]`, installed the complete guarded H with direct `LObject` and `Singleton<StaticObjImageLib>` bases, packed `StaticObjEntry::lightImageIndex`, and documented EBO, constructor unwind, implicit ordinary/scalar base destruction, compiler-support exclusions, and superseded helper assumptions.

- 2026-08-11 B003 UID00023D additive drift reconciliation: preserved B005's later `92/96` score, direct `Singleton<StaticObjImageLib>` base, packing, EBO/lifecycle evidence, and all guarded H additions. Restored the accepted CPP owning-header include before `[[CHILDREN]]`, matching this page's current parent-attachment prose and the ObjectList cross-file visibility contract; no later valid H content was pruned.

- 2026-08-11 B003 UID00023D support implementation: preserved `88/89`, owner/emitter UID0000O7, reconstructable true, and blank position. Moved the complete declaration from CPP to guarded `StaticObjImageLib.h`, made CPP include that header before `[[CHILDREN]]`, changed `StaticObjEntry::lightIntensity` to cross-consumer `lightImageIndex`, and documented `ObjectList::RefreshStaticObjectLighting` as the second exact accessor consumer. Method bodies remain on exact children and the singleton definition remains solely on UID0000SD.

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
- 2026-06-17 B003 image-library cleanup audit:
  - Class score unchanged, but [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) is now `87/91`, directly class-owned by `0000E2`, and populated with first-draft ordinary destructor C++.
  - Evidence: class-method `this` cleanup, vtable restore, layout names, cache-chain semantics, scalar-wrapper parity with [UID:0003M2][0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor](by-memory/0x004e6990-0x004e6aa6.StaticObjImageLibScalarDeletingDestructor.md), and local PE start-byte confirmation.
- 2026-06-21 B007 Rule 26 incorporation:
  - Raised from `86/85` to `88/89` and populated declaration-level first-draft C++.
  - Evidence: B007 source-quality pass consolidates class/file/resource/memory support around class-owned renderer routing, source-facing descriptive names for `StaticObjImageLib`, `StaticObjEntry`, and `TileClassEntry`, consumer-boundary rejection for StaticObjectPane/PhotoPane/MapPane/ObjectList, `SOBJ.TBL` full render view versus map-classification split, `TILEC` modern/legacy resource split, no-code policy for scalar deleting destructor and singleton cleanup glue, and current generated-output caveats.
- 2026-06-26 B001 renderer return-contract implementation:
  - Class declaration changed from `bool RenderStaticObject(...)` to `char RenderStaticObject(...)` to match the exact binary return contract documented in [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md).
  - Evidence: B001 MCP session `80de0a67` confirms the analyzed renderer prototype, the raw `char` forward in `sub_5379A0`, invalid-path return `0`, success return `0xff`, and load-error guard return from the initialized local draw-record pointer. The method remains class-owned and reconstructable, but the target formal body is intentionally blank until exact support declarations can preserve those return semantics.
- 2026-07-01 B010 StaticObjImageLib empty-emitter family support update:
  - Score unchanged at `88/89`.
  - Historical evidence: B010 kept this page as declaration-level support while UID0000SD emitted the singleton definition, UID0001PP recorded storage, UID0000U6 emitted the Tilec builder, and [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md) emitted a cleanup-glue no-code comment. UID000184 now supersedes only the helper/no-code-comment source conclusion; the prior exact bytes and route evidence remain preserved.
