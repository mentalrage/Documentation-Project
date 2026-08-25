*** UID:00008N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MonsterImageLib.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_MONSTERIMAGELIB_H
#define NEXUSTK_RENDER_MONSTERIMAGELIB_H

#include "../util/LObject.h"
#include <hash_map>
#include <vector>

class DATFile;
struct EPFTileContext;
class GrafPort;
class ObjectStatusBlob;
struct FrameDrawRecord;
struct MonsterArchiveBoundsBucket;
struct MonsterImageEntry;
struct RectBounds;

class MonsterImageLib : public LObject
{
public:
    MonsterImageLib();
    virtual ~MonsterImageLib();

    void LoadMonsterTables();
    void LoadMonsterArchives();
    void ClearLoadedData();
    MonsterImageEntry *GetEntryByIndex(unsigned int index);
    void RenderMonster(
        GrafPort *target, const RectBounds *bounds,
        const ObjectStatusBlob *status, unsigned int animationGroup,
        unsigned int frameIndex);
    MonsterArchiveBoundsBucket *GetArchiveBoundsBucket(
        unsigned int archiveIndex);
    void ResolveMonsterArchiveBounds(
        unsigned int frameIndex, EPFTileContext *context);
    int ComputeRenderBounds(
        const ObjectStatusBlob *status, unsigned int direction,
        unsigned int frameIndex, RectBounds *bounds,
        RectBounds *secondaryBounds);
    void RenderMonsterImage(
        GrafPort *port, const RectBounds *destinationBounds,
        const ObjectStatusBlob *status, int direction,
        unsigned int frameIndex, int renderMode,
        unsigned int effectState, FrameDrawRecord *frameRecord,
        float overlayStrength);

private:
    MonsterImageEntry *m_monsters;
    unsigned int m_monsterCount;
    unsigned int m_archiveState;
    std::vector<unsigned int> m_archiveOffsets;
    stdext::hash_map<int, DATFile *> m_openArchiveIndex;
    stdext::hash_map<int, MonsterArchiveBoundsBucket *> m_boundsBucketIndex;
};

[[CHILDREN]]

typedef char MonsterImageLibSizeMustBe92[
    sizeof(MonsterImageLib) == 0x5c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib

## 2026-08-18 Complete Header And ObjectImage Dependency Closure

- Formal H now declares the complete 0x5c class surface: constructor, virtual destructor, table/archive lifecycle, GetEntryByIndex, known RenderMonster, bounds-bucket resolution, bounds computation, image rendering, typed members, and size guard. Its explicit H `[[CHILDREN]]` insertion point is inside the include guard before the size guard, so attached UID0000RR emits the singleton extern exactly once in the guarded assembled H.
- The two exact 0x20 cache members at +0x1c and +0x3c are old-MSVC stdext::hash_map<int, DATFile *> and stdext::hash_map<int, MonsterArchiveBoundsBucket *> objects. The former custom DATIndexVector membership model remains historical compiler-lowering evidence only and creates no member or include.
- Formal CPP includes MonsterImageLib.h and routes exact children. UID0000RR is the position-0 class child, so its one external singleton definition follows the companion-header include and precedes all remaining class children without duplicating storage.
- ObjectImageControlPane is a concrete consumer of ComputeRenderBounds and RenderMonsterImage. Fresh 0x004db100 evidence also closes RenderMonster as the five-argument high-level draw entry; the source declaration returns void.
- Scores are 91/92. Exact layout, cache types, known APIs, singleton route, and CPP/H channels are closed; broader unreconstructed private bodies, inferred original spellings, and absent rebuilt-binary comparison retain the cap.

## 2026-08-17 Typed Cache-Container Source Decision

The two `0x20` cache members are source-facing old-MSVC `stdext::hash_map` instantiations, not project-authored `DATIndexVector` objects: the member at `+0x1c` is `stdext::hash_map<int, DATFile *> m_openArchiveIndex`, and the member at `+0x3c` is `stdext::hash_map<int, MonsterArchiveBoundsBucket *> m_boundsBucketIndex`. Their shared FNV/list/bucket helper ranges are identical-COMDAT compiler/private-library lowering documented by [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md).

At the dated 2026-08-17 boundary, this correction resolved the custom-container type/name blocker without yet adding direct formal-H output; that pre-closure limitation was superseded by the 2026-08-18 complete formal H above. Exact binary offsets, node payloads, constructor/destructor behavior, lookup/insert routes, and historical recovery names remain documented.

## Status

- Confidence: strong for method roles, singleton/static-lifetime ownership, resource/archive ownership, helper reachability, bounds-cache source placement, file parent placement, and the complete formal H/current closure; medium-high for exact original spellings, broader private-body reconstruction, and rebuilt-binary comparison.
- Likely source file: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- Owner/emitter: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md). The formal CPP includes `MonsterImageLib.h` and routes `[[CHILDREN]]`; the separate formal H is the complete guarded `0x5c` class declaration with typed cache members, known API surface, size guard, and the UID0000RR singleton-extern child route. Exact child methods/types/globals emit through this class where accepted, including [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md), ordinary destructor [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md), formal struct declarations, vtable markers, scalar wrapper marker, and the `GetArchiveBoundsBucket` cache/DAT no-code marker.
- Address ranges: [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md), singleton clear helper [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md), archive-index helper [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md), and scalar deleting destructor [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md)
- Singleton: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`
- Vtable: [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) at `0x0061b6e4`
- Layout: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)

## Class Purpose

`MonsterImageLib` is the singleton-backed monster image/rendering library behind [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md). It loads monster animation tables, builds an index over numbered monster DAT archives, renders monster frames with palette/direct renderer callbacks, computes projected bounds, and frees cached archive data.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoadMonsterTables` | `0x004dac40` | [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) parses `MONSTER.DNA` or `MONSTER.DND`, allocates monster table entries, initializes 21 monster group buckets, fills nested animation group/frame records, and now has formal first-draft C++ attached through this class owner. |
| `MonsterImageLib::MonsterImageLib` | `0x004daec0` | Initializes singleton, table/vector/list state, then calls `LoadMonsterTables` and `LoadMonsterArchives`. |
| `~MonsterImageLib` | `0x004db010` | [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) now emits `MonsterImageLib::~MonsterImageLib()` with source body `ClearLoadedData(); delete[] m_monsters;`. The vptr restore, `m_boundsBucketIndex`/`m_openArchiveIndex`/`m_archiveOffsets` member destruction, `LObject` base cleanup, singleton clear, EH state, allocator guard paths, and scalar-delete wrapper are compiler-lowered/generated output. |
| `RenderMonster` | `0x004db100` | High-level projected monster draw path. |
| `GetEntryByIndex` | `0x004db330` | Bounds-checked `MonsterImageEntry` lookup with the default monster animation-table fallback; live callers include UID0003U8 directional animation and UID0002R1 animation/timer source. |
| `RenderMonsterImage` | `0x004db3b0` | Palette/direct monster image draw path with optional overlay pass. |
| `ComputeRenderBounds` | `0x004db5c0` | Computes monster bounds/projection using archive bounds buckets. |
| `LoadMonsterArchives` | `0x004dbc60` | Scans `DATA/MON%d.DAT`, opens each DAT container, and builds archive index records. |
| `GetArchiveBoundsBucket` | `0x004dbe60` | [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) is the class-owned lazy `DATA/MON%d.DAT` bounds-bucket loader: it uses `m_openArchiveIndex` at `+0x1c`, `m_boundsBucketIndex` at `+0x3c`, allocates/caches 0x0c buckets and 0x18 entry rows, and remains formal-C++ blank under the accepted cache/DAT API no-code proof. |
| `ClearLoadedData` | `0x004dc2e0` | Frees cached loaded archive/bounds data and state nodes. |
| `ScalarDeletingDestructor` | `0x004e6750` | Destructor thunk with optional delete; first [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) slot. |

[UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) is a concrete UI preview consumer of the monster render path. Its `OnPaint` status-kind `1` branch calls [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), uses `0x004db5c0` as `ComputeRenderBounds`, and uses `0x004db3b0` as `RenderMonsterImage` with a preview/render-mode constant. This reinforces the current method aliases while keeping exact preview flag spelling provisional.

Singleton/static-lifetime support:

| Function | Address | Role |
| --- | --- | --- |
| `MonsterImageLibSingletonClearHelper` | `0x004e5bd0` | [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) that clears `g_pMonsterImageLib` / `dword_69B440`. |

Batch 121 rechecked this helper as file-local static cleanup glue. It has no ordinary callsites and no `this` parameter; IDA reports a single constructor-associated cleanup-table xref at `0x005ffd87`, and `xrefs_to 0x0069b440` reports 22 lifecycle/consumer references around the class singleton. The helper is therefore parented to [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), while this class page records why it belongs to the `MonsterImageLib` lifetime.

## 2026-06-25 LoadMonsterTables Source-Quality Sync

The B001 accepted implementation callback updates [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) from file-owned/blank-C++ to class-owned formal emission:

- Direct owner/emitter for the method is now this class, [UID:00008N]. The generated route still reaches [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) through the class emitter.
- The old blank-C++ blocker is withdrawn for the loader. The method now uses inferred source-facing names such as `ImageAnimationGroup`, `ImageAnimationFrame`, `AllocateGroups`, `AllocateFrames`, and `g_defaultMonsterAnimationTable` rather than raw `sub_` or `unk_` labels.
- The helper caveat remains class-level: the whole `MonsterImageLib` declaration is still blank until field declarations, archive/cache members, and shared helper declarations are aligned. That does not block [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) from carrying a method-level first draft.
- Field evidence added to the target and [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) resolves the row field names to `animationGroupCount`, `projectionFlag`, `paletteTableId`, and `groups`, with `paletteTableId` still marked weaker than the count/projection/group-pointer evidence.
- The 10-byte frame entry names are synchronized with render/scheduler consumers: `+0x00 frameOffset`, signed `short +0x02 frameDuration`, `+0x04 blendAlpha`, `+0x06 auxFrameId`, `+0x08 paletteIndex`, and `+0x09 effectIndex`. The last three remain inferred/weak and are not claimed as recovered symbols.

## UID0003U8 Live Animation Consumer Synchronization - 2026-07-15

- [UID:0003U8][0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation](by-memory/0x005a3770-0x005a386a.UserPaneStartDirectionalAnimation.md) is a direct live consumer of this class through [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md). Its MonsterObject branch zero-extends appearance id, subtracts `0x8000`, and calls `GetEntryByIndex` at `0x004db330`.
- `GetEntryByIndex` returns `m_monsters + 12 * index` when in range and the existing default monster animation table otherwise. UID0003U8 then selects `ImageAnimationGroup` by signed `direction + 5`, selects `ImageAnimationFrame` by `m_moveFrame`, and schedules signed `frameDuration`.
- The same accepted MonsterImageLib/table vocabulary is now used by [UID:0002R1][0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer](by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md), preventing the target from calling into a contradictory Human/ObjectImageLib support contract.
- This bounded consumer update changes no class score, owner/emitter route, whole-class marker, method body, vtable, layout, singleton lifetime, archive/cache source, or unrelated render consumer. Historical ObjectImageLib ownership and nonexistent `GetFrameGroup` routing are rejected for these monster-animation callers.

## 2026-06-25 Destructor Source Sync

The B011 accepted implementation moves [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) from direct file ownership to this class owner/emitter:

- Direct owner/emitter for the ordinary destructor body is now this class, [UID:00008N]. The generated route still reaches [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) through the class emitter.
- The formal method body is now `ClearLoadedData(); delete[] m_monsters;`. This uses the same source-facing member vocabulary accepted by the loader: `m_monsters` and `m_monsterCount` for the table pointer/count, plus `m_archiveOffsets`, `m_openArchiveIndex`, and `m_boundsBucketIndex` in supporting layout notes.
- B011 live MCP after the outage reconfirmed exact `0x004db010-0x004db0f7` bounds, 231-byte size, no direct xrefs, scalar-deleting parity with [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md), vtable slot `0x0061b6e4 -> 0x004e6750`, 22 singleton refs, helper callees, and post-body `0xcc` alignment.
- The ordinary destructor body does not manually call member/base destructors and does not manually write [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md). Those effects appear after the source body as compiler-lowered member destruction, base destruction, singleton subobject/static-lifetime cleanup, EH state, and allocator checks.
- The scalar deleting destructor peer remains source-declared/generated-binary. The class virtual destructor declaration should regenerate the wrapper and delete-flag logic; do not hand-port the scalar wrapper as method C++.
- The whole-class declaration block on this page remains blank because class-level declaration polish is still separate from the two accepted method-level formal C++ blocks.

## 2026-06-27 GetArchiveBoundsBucket Source-Quality Sync

The B003 accepted implementation updates [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) from a behavior-confirmed blank-code child to an `88/91` exact method child with a target-specific no-code proof:

- Direct owner/emitter remains this class, [UID:00008N], with generated output ultimately routed through [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
- Live MCP session `80de0a67` reconfirmed `0x004dbe60` size `0x315`, normal callers at `0x004db647` and `0x004dc1b9`, raw local call at `0x004dc279`, UTF-16 `DATA/MON%d.DAT` bytes at `0x0061c07c`, and DAT/cache/list/RectBounds callees.
- The accepted source-facing field names stay `m_openArchiveIndex` for the opened reader cache at `+0x1c` and `m_boundsBucketIndex` for cached [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records at `+0x3c`. Raw `this + 7`, `this + 15`, `sub_4DBE60`, and decompiler temporary names remain evidence aliases only.
- The method allocates and caches a 0x0c bucket, reads the 8-byte header, allocates 0x18-byte [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md) rows plus a sentinel, initializes `RectBounds`, rebases payload fields by the DAT payload base, and returns the cached bucket pointer.
- The formal C++ body remains blank because broader DAT reader/container ownership and complete MonsterImageLib class declarations are still incomplete. The cache API itself is no longer a blocker: source uses typed `stdext::hash_map<int, DATFile *>` and `stdext::hash_map<int, MonsterArchiveBoundsBucket *>` operations.
- The raw `0x004dc240-0x004dc2db` prologued helper/gap is outside [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md). It has no xrefs to its start, contains a raw call to `GetArchiveBoundsBucket` at `0x004dc279`, and should be tracked as local cluster evidence rather than merged into this method.

## 2026-06-30 B011 Class Route Audit

The accepted B011 empty-emitter implementation changes this page from a blank class emitter into the source-owner route marker for the `MonsterImageLib` family. The formal block intentionally emits only a no-standalone class marker and `[[CHILDREN]]`; it does not invent a complete class declaration.

Audit routes checked and preserved:

- Constructor route: exact function `0x004daec0`, size `0x14e`, called by startup/singleton wrapper `sub_4F5FB0`; writes [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), initializes `LObject`, installs vtable `0x0061b6e4`, initializes `m_archiveOffsets`, `m_openArchiveIndex`, and `m_boundsBucketIndex`, then calls `LoadMonsterTables` and `LoadMonsterArchives`.
- Destructor route: ordinary destructor [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) emits the authored `MonsterImageLib::~MonsterImageLib()` body; scalar deleting destructor [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) is compiler-generated and now emits a formal no-code marker.
- Vtable slots: RTTI pointer `0x00648c14`; slot `+0x00` `0x004e6750` scalar deleting destructor; slot `+0x04` `0x004f4b10`; slot `+0x08` `0x0041b6c0` / `nullsub_18`. The exact dwords are generated ABI output, not a source-authored table.
- Method inventory checked: constructor `0x004daec0`, `LoadMonsterTables` `0x004dac40`, `LoadMonsterArchives` `0x004dbc60`, `GetArchiveBoundsBucket` `0x004dbe60`, `ClearLoadedData` `0x004dc2e0`, render/accessor local methods at `0x004db100`, `0x004db330`, `0x004db3b0`, `0x004db5c0`, `0x004db8b0`, ordinary/scalar destructors, and singleton clear helper [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md).
- Fields/offsets checked: vptr/base at `+0x00`; `m_monsters` at `+0x04`; `m_monsterCount` at `+0x08`; unresolved/reserved `+0x0c`; `m_archiveOffsets` at `+0x10/+0x14/+0x18`; `m_openArchiveIndex` at `+0x1c`; `m_boundsBucketIndex` at `+0x3c`.
- Base class checked: constructor/destructor paths show `LObject` base construction/destruction.
- Direct child ownership checked: method/type/vtable/global children remain owned by this class or the file family as appropriate. This class marker routes accepted child output but does not collapse all child source into a guessed class body.

Why a full class shell is still unsafe:

- Visibility and inherited virtual declarations are not source-quality.
- Several local method signatures and helper names are still not final source declarations.
- The `+0x0c` field remains observed layout but not source-named.
- Cache field declarations are resolved as typed `stdext::hash_map` members; remaining class blockers concern broader DAT ownership, unrelated fields/helpers, and complete declaration assembly.
- A full class declaration would choose final field/API spelling before the constructor, archive-loader, cache-loader, and shared helper declarations are fully reconciled. The marker plus `[[CHILDREN]]` preserves ownership and generation route without overclaiming source.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck singleton/vtable reachability, archive-index helper ownership, and final field/helper blockers:

- `lookup_funcs` confirms the local method island boundaries: table loader `0x004dac40` size `0x27d`, constructor `0x004daec0` size `0x14e`, ordinary destructor `0x004db010` size `0xe7`, render/lookup/bounds/archive/cache helpers through `0x004dc2e0`, vector grow helper `0x004e5990` size `0xd2`, singleton-clear helper `0x004e5bd0` size `0x0b`, and scalar deleting destructor `0x004e6750` size `0x110`.
- `xrefs_to 0x004daec0` returns the startup/application construction caller at `0x004f60c7`. `xrefs_to 0x0061b6e4` returns constructor/destructor/scalar-delete vtable writes at `0x004daf16`, `0x004db036`, and `0x004e677d`.
- `xrefs_to 0x0069b440` returns 22 singleton refs, including constructor writes, ordinary/scalar destructor clears, singleton-clear helper clear, shutdown/cache-clear reads, and render/object consumers. `xrefs_to 0x004e5bd0` returns the constructor cleanup-table ref at `0x005ffd87`.
- `xrefs_to 0x004e5990` returns a single caller at `0x004dbd8f` inside `LoadMonsterArchives`, keeping the archive-index grow helper with this source module. `xrefs_to 0x0069b424` returns four refs from shared table setup, `LoadMonsterTables`, `GetEntryByIndex`, and a static cleanup wrapper, matching the documented fallback-record ownership caveat.
- `callees` confirms constructor fanout through the base object, DATIndexVector setup, `LoadMonsterTables`, and `LoadMonsterArchives`; destructor/scalar destructor both call `ClearLoadedData`, DATIndexVector destructor, base destructor, and free/invalid-parameter support; lazy bounds lookup uses DATIndexVector find/insert and DATArchive/cache helpers.

These checks strengthen class-level ownership and directly investigate helper/source-placement blockers. The 2026-06-25 B001 implementation supersedes the specific `LoadMonsterTables` no-code blocker by accepting inferred source-facing helper and frame-field names for that method. The 2026-06-27 B003 implementation supersedes the stale disabled/excluded wording for `GetArchiveBoundsBucket`: [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) is owner/emitter-confirmed and emitted as an empty marker/no-code child while formal C++ waits on source-ready cache/DAT API declarations. Remaining class-level blockers are final source-quality names for broader table/cache fields, archive-bounds record members, shared helper declarations outside the loader, and full class declaration shape.

No-code but still emitted exact child:

| Method | Address | Role |
| --- | --- | --- |
| `GetArchiveBoundsBucket` | `0x004dbe60` | [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) per-archive [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md), emitted through this class route as a blank formal-C++ marker under the accepted cache/DAT API no-code proof. |

## Historical DATIndexVector Relationship (Superseded)

IDA MCP caller checks on 2026-05-24 originally led to a custom `DATIndexVector` interpretation for archive-bounds cache lookup/insert paths. The exact calls remain valid binary evidence, but current source interpretation is typed `stdext::hash_map` construction, `find`, `insert`, and destruction for the two independently mapped pointer types. `VectorGrowArchiveIndex_004E5990` remains separate and is only observed from `LoadMonsterArchives`.

IDA MCP checks on 2026-05-25 also show `MonsterImageLib` using shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers for sentinel-node setup, two-word payload-node allocation, and list-state cleanup. Those helpers are generic utility code and should not be migrated into `MonsterImageLib.cpp`.

IDA MCP checks on 2026-05-31 reverified the constructor (`0x004daec0`), ordinary destructor (`0x004db010`), lazy bounds loader (`0x004dbe60`), and clear-loaded-data helper (`0x004dc2e0`). These checks confirm the singleton, vtable, archive-offset vector, `stdext::hash_map<int, DATFile *>` at `+0x1c`, `stdext::hash_map<int, MonsterArchiveBoundsBucket *>` at `+0x3c`, and ownership of the archive-bounds cache structures. The class is reconstructable and routes to [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md). Class-level C++ remains blank because complete unrelated field/helper declarations are not source-final, while [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) now carries method-level C++.

## Shared Table Helper Relationship

`LoadMonsterTables` and [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) both call the two helper classes documented in [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). Their current page names are monster-biased/address-derived evidence aliases. The accepted source-facing vocabulary for the loader is neutral: a 12-byte animation table row/default table owns `ImageAnimationGroup` records, and each group owns `ImageAnimationFrame` records. Source placement may be a common animation-table helper rather than strictly inside `MonsterImageLib`.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-08-22 B010 Gate 2A contradiction repair: historicalized the dated pre-header limitation and made the existing complete formal H/current closure authoritative in active Status prose; the CPP remains the accepted header/include plus `[[CHILDREN]]` route, not a substitute for the complete H declaration.
- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `87/89` to `89/90`.
  - Evidence: populated the formal class route block with the accepted no-standalone class marker and `[[CHILDREN]]`; added the constructor/destructor/vtable/method/field/base/child ownership audit; preserved why a full class shell remains unsafe; and synchronized the class page with the accepted per-child dispositions for scalar wrapper, vtable bytes, struct declarations, singleton/default globals, vector-grow marker, and `GetArchiveBoundsBucket` no-code output.
- 2026-06-27 B003 GetArchiveBoundsBucket implementation callback:
  - Score changed from `86/88` to `87/89`.
  - Evidence: synchronized [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) as a class-owned/emitted exact method child with accepted `88/91` target metadata. Added live MCP session `80de0a67` evidence for target range/callers/string bytes/cache fields/bucket-entry construction, replaced stale disabled/excluded wording with empty-marker/no-code routing, and recorded the raw `0x004dc240-0x004dc2db` helper-gap as out-of-target local evidence.
- 2026-06-25 B011 destructor implementation callback:
  - Score unchanged at `86/88`.
  - Evidence: [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) is now class-owned/emitted through [UID:00008N] and contains formal `MonsterImageLib::~MonsterImageLib()` C++ with `ClearLoadedData(); delete[] m_monsters;`. This class page records the source-vs-compiler-lowered split, the rejection of direct file semantic ownership/no-owner routing/handwritten scalar wrapper/manual member/base destructor calls/manual singleton clear, and the remaining whole-class declaration caveat.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `86/88`.
  - Evidence: [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) is now class-owned/emitted through [UID:00008N] and contains formal first-draft C++. This class page records the loader-specific source-facing helper names, the default table name `g_defaultMonsterAnimationTable`, and the frame-field confidence split while keeping whole-class C++ blank for the broader declaration pass.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: recorded [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) as a concrete UI preview consumer of `ComputeRenderBounds` / `RenderMonsterImage` at `0x004db5c0` / `0x004db3b0`, using status kind `1` as monster appearance through [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md).
- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner and emitter remain [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
  - Evidence: live IDA MCP reconfirmed local method/helper sizes, startup constructor caller, vtable writes, 22 singleton refs, singleton-clear cleanup-table ref, single `VectorGrowArchiveIndex` caller from `LoadMonsterArchives`, fallback-record refs, and constructor/destructor/cache-loader callees. At that time class-level C++ remained blank because table/cache field names, shared helper declarations, and fallback-storage source placement were not source-final; [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) now has method-level C++ after the B001 callback.
- 2026-06-08 A001 Batch 121 static-helper refresh:
  - Before: completion/confidence were `84/82`, and the singleton-clear helper row linked the child but did not record the constructor cleanup-table evidence needed for the corrected parent gate.
  - Changed to: completion `85`, confidence `85`, with the helper described as file-local static cleanup tied to the `MonsterImageLib` constructor/lifetime rather than as a class method.
  - Summary/evidence: live IDA MCP reconfirmed [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md), its `dword_69B440 = 0` body, the single cleanup-table xref at `0x005ffd87`, and 22 singleton global xrefs. Final class C++ stays blank because field/helper declarations are not source-final.
- Completion/confidence score update: existed before as `0/0`; changed to `84/78`. Summary: the singleton monster image library has detailed method, singleton, vtable, layout, DAT archive, cache, render, bounds, table-helper, DATIndexVector, and LinkedList dependency documentation, but final field/type names remain medium confidence. Evidence: linked `MonsterImageLib` range, destructor/get-bounds/singleton-clear pages, `g_pMonsterImageLib`, vtable/layout/type docs, IDA caller checks, and shared monster/riding table-helper notes.
- Reconstructability/confidence update: existed before as `RECONSTRUCTABLE` blank and confidence `78`; changed to `RECONSTRUCTABLE:TRUE` and confidence `82`. Summary: 2026-05-31 IDA MCP rechecked constructor/destructor/cache-loader/cleanup evidence and confirms this class is NexusTK-owned source that must be rebuilt. Owner/emitter routing was not yet assigned during that pass, and final whole-class C++ remained blank because source-quality field/helper names were not ready.
- Method inventory update: `LoadMonsterTables` existed before as an unlinked method row; changed to link the exact [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) child page. Evidence: 2026-05-31 IDA MCP verified `0x004dac40` size `0x27d` and the monster table parse/allocation flow.
- 2026-06-03 parent assignment:
  - What existed before: the class was reconstructable and scored `84/82`, but owner/emitter routing was blank and the status section still cited a recovered-file provenance line.
  - Changed to: parent [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), with final C++ still blank.
  - Summary/evidence: current IDA MCP confirms the constructor, destructor, scalar destructor, vtable, singleton lifecycle, archive/table loaders, and render/bounds helpers belong under the `MonsterImageLib.cpp` file parent, which is now above the parent-confidence gate.
