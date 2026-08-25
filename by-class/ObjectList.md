*** UID:00009Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ObjectList.h"
#include "LightingObjectPane.h"
#include "MapPane.h"
#include "ObjectPane.h"
#include "StaticObjectPane.h"
#include "../render/StaticObjImageLib.h"
#include "../util/List.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_OBJECTLIST_H
#define NEXUSTK_MAP_OBJECTLIST_H

#include "../util/LObject.h"

typedef unsigned int ObjectListKey;

class List;
class ObjectPane;
class StaticObjectPane;

class ObjectList : public LObject
{
public:
    ObjectList(int gridWidth, int gridHeight);
    virtual ~ObjectList();

    bool HasValidGridOrigin();
    void AddObjectPane(ObjectPane *object);
    void RemoveObjectPane(ObjectPane *object);
    ObjectPane *ResolveObjectListKey(ObjectListKey key);
    ObjectListKey GetTypedObjectKey(ObjectPane *object);
    ObjectPane *FindByObjectId(int objectId);
    bool ContainsTypedObject(ObjectPane *object);
    void DetachAll(ObjectPane *preserveObject);
    void PruneMarkedRowObjects();
    void MarkVisibleObjectsForRefresh();
    void RemoveMarkedVisibleObjects();
    void RefreshStaticObjectLighting(unsigned short staticObjectId);

    List *GetPrimaryCellList();
    List *GetSecondaryCellList();
    List *GetPrimaryRowBucket(int row);
    List *GetSecondaryRowBucket(int row);
    List *GetVisibleObjectList();
    List *GetSecondaryGlobalList();
    List *GetAlternateGlobalList();
    List *GetTertiaryGlobalList();
    List *GetQuaternaryGlobalList();
    List *GetQuinaryGlobalList();
    List *GetFrontRowBucket(int row);
    List *GetBackRowBucket(int row);
    StaticObjectPane *FindStaticObjectPaneAt(int tileX, int tileY);

private:
    static const ObjectListKey kObjectListKeyNotFound = 0xffffffffu;

    ObjectListKey FindStaticObjectKey(ObjectPane *object);
    ObjectListKey FindLivingObjectKey(ObjectPane *object);
    ObjectListKey FindItemObjectKey(ObjectPane *object);
    ObjectListKey FindFlyingObjectKey(ObjectPane *object);
    ObjectListKey FindPrimaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindSecondaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindBalloonObjectKey(ObjectPane *object);
    ObjectListKey FindHitBarObjectKey(ObjectPane *object);
    ObjectListKey FindDamageNumberObjectKey(ObjectPane *object);

    int m_minX;
    int m_minY;
    int m_gridWidth;
    int m_gridHeight;
    List *m_itemObjects;
    List *m_flyingObjects;
    List **m_primaryEffectRows;
    List **m_secondaryEffectRows;
    List **m_livingObjectRows;
    List **m_staticObjectRows;
    List *m_balloonObjects;
    List *m_hitBarObjects;
    List *m_damageNumberObjects;
    List *m_objectInfoObjects;
    List *m_lightingObjects;
    List *m_soundObjects;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete LObject-derived 0x44 ObjectList declaration with semantic storage taxonomy, exact lifecycle/dispatch/accessor/private-key methods, typed FindStaticObjectPaneAt lookup, public RefreshStaticObjectLighting declaration, complete include/dependency route for the exact lighting-sync child body, preserved remaining helper splits, and compiler table/cookie/vtable/scalar-wrapper exclusions. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectList

## UID00037R MapPane Refresh Consumer Contract - 2026-08-24

- The public declaration now exposes `void PruneMarkedRowObjects();` and `void MarkVisibleObjectsForRefresh();` in binary-address order after `DetachAll`. Existing `RemoveMarkedVisibleObjects()` remains a distinct later method and is not renamed or conflated with either declaration.
- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) supplies the MapPane Ctrl+R consumer: with a nonnull ObjectList, call `MarkVisibleObjectsForRefresh()` at `0x00507027` and then `PruneMarkedRowObjects()` at `0x00507032`.
- The call sequence first marks visible item/living/static objects, then removes row-bucket entries carrying marker `-1`. ObjectList remains the receiver and source owner; MapPane.cpp receives declarations only through `ObjectList.h` and does not duplicate either body.

## Status

- Confidence: very strong for the complete `LObject`-derived declaration, exact `0x44` layout, semantic object-storage taxonomy, lifecycle/vtable ownership, helper ranges, typed-key source surface, accessor methods, typed static-row lookup, and current caller evidence; stripped private identifier spelling caps confidence at `93`.
- Likely source file: [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Parent/C++ status: attached to [UID:0000M4][ObjectList](by-file/ObjectList.md), the `NexusTK/map/ObjectList.h` and `ObjectList.cpp` map object-index root. The formal H channel supplies the complete guarded declaration, semantic fields, and public `RefreshStaticObjectLighting(unsigned short)` declaration. CPP includes `ObjectList.h`, the complete pane/image/list dependencies required by UID00023D, and then the closed `[[CHILDREN]]` route. Exact method-level children such as [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md), [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md), [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md), [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md), and [UID:0002BB][0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers](by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md) remain the sole owners of their method definitions.
- Lifecycle ranges: [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md), [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), and [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md). UID0002JS carries formal constructor source, UID0002JT now carries formal first-draft ordinary destructor source, and UID0001D4 remains comment-only compiler-generated scalar deleting destructor output.
- Accessor/sweep ranges: [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)

## Class Purpose

`ObjectList` is the map-owned world-object index. It builds a padded grid around the current map, owns multiple `List` containers of object pointers, exposes flat render/hit-test lists and row buckets, and sweeps or shifts the objects during map changes, scrolls, cleanup, and render passes.

This is not the generic utility [UID:000079][List](by-class/List.md). `ObjectList` consumes `List` objects internally, but its contents and callers are specific to `MapPane` object panes.

## Layout

The constructor allocates a 68-byte object and installs the `ObjectList` vtable. The observed field layout is:

```text
0x00  vtable
+0x04  int minX
+0x08  int minY
+0x0c  int gridWidth
+0x10  int gridHeight
+0x14  List* itemObjects
+0x18  List* flyingObjects
+0x1c  List** primaryEffectRows
+0x20  List** secondaryEffectRows
+0x24  List** livingObjectRows
+0x28  List** staticObjectRows
+0x2c  List* balloonObjects
+0x30  List* hitBarObjects
+0x34  List* damageNumberObjects
+0x38  List* objectInfoObjects
+0x3c  List* lightingObjects
+0x40  List* soundObjects
```

The UID0002BB constructor/dispatcher reanalysis resolves the former structural tier names to concrete ObjectPane families. The historical aliases `primaryCellList`, `secondaryCellList`, `primaryRowLists`, `secondaryRowLists`, `tertiaryRowLists`, `extendedRowLists`, and the five `*GlobalList` names remain search vocabulary only. Type producers map `+0x14..+0x40` to Item, Flying, PrimaryEffect, SecondaryEffect, Living, Static, Balloon, HitBar, DamageNumber, ObjectInfo, Lighting, and Sound storage. UID0002BC's prefixes `0x80000000`, `0x90000000`, and `0xa0000000` now correspond to object-info, lighting, and sound direct tiers.

See [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) for the type-layout view.

## Method Families

| Range | Evidence/source-facing caveat | Likely `ObjectList` role |
| --- | --- | --- |
| [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) | `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)`; exact source body with one MapPane tail-wrapper edge and route-negative wrapper-start evidence. | Scans `m_staticObjectRows` through `m_gridHeight + 12`, invalidates matching panes, and removes, updates, or creates/attaches `LightingObjectPane` companions through `m_lightingObjects`. |
| [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) | `ObjectList::ObjectList` | Exact source-body constructor child. Allocates semantic item/flying/effect/living/static/direct object-family lists from padded map dimensions; gates `m_damageNumberObjects` at `+0x34` on `g_useEpfAssets`; formal C++ lives only on the child page. |
| [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) | `ObjectList::~ObjectList` | Exact source-body destructor child; releases the same semantic row/direct families and optional damage-number list while excluding vptr/base/scalar-delete/SEH/cookie mechanics from handwritten source. |
| [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) | Exact children for `HasValidGridOrigin`, `AddObjectPane`, `RemoveObjectPane`, `ResolveObjectListKey`, `GetTypedObjectKey`, `FindByObjectId`, and retained `ContainsTypedObject`. | Current exact children use `ObjectPane *`, `ObjectPaneType`, `ObjectListKey`, semantic storage fields, and final private `Find*ObjectKey` declarations. Type-4/category-2 and type-8/category-C behavior is preserved. UID0002CE remains source-shaped/no-inbound; switch tables and padding stay with exact children. |
| [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) | Exact ObjectList accessor-method child with formal C++ on the memory page; `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` are retained only as search aliases. | `GetPrimaryCellList`, `GetSecondaryCellList`, `GetPrimaryRowBucket`, `GetSecondaryRowBucket`, `GetVisibleObjectList`, `GetSecondaryGlobalList`, `GetAlternateGlobalList`, `GetTertiaryGlobalList`, `GetQuaternaryGlobalList`, `GetQuinaryGlobalList`, `GetFrontRowBucket`, and `GetBackRowBucket` over fields `+0x14` through `+0x40`. |
| `0x00532730-0x00532b72` | source-facing `ObjectList::ShiftAll` candidate; accepted future exact child `ObjectListShiftAll` | Shifts every stored object rectangle by pixel-scaled map-scroll deltas, iterating row/global tiers and using object rectangle vslots plus `sub_4B7E10`. |
| `0x00532b80-0x00532e11` | source-facing `ObjectList::DetachAll` candidate; accepted future exact child `ObjectListDetachAll` | Sweeps stored object lists and releases object panes through object vslot `+0`, optionally preserving the supplied active object from MapPane change/effect paths. |
| `0x00532e20-0x00532eae` | source-facing `ObjectList::PruneMarkedRowObjects` candidate; accepted future exact child | Releases entries in row arrays `+0x1c/+0x20` whose object marker at `+0x13c` is `-1`; this supersedes the generic "prune marked objects" label. |
| [UID:0004SI][0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt](by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md) | `StaticObjectPane *ObjectList::FindStaticObjectPaneAt(int tileX, int tileY)` | Exact source-ready static-row lookup: builds extended padded bounds, indexes `m_staticObjectRows` by tileY/row, dereferences List pointer slots, compares MapPoint column/X then row/Y, and returns the first typed match or `NULL`. |
| `0x00532f70-0x0053728e` | [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) | Extended ObjectList helper aggregate over front-row object lookup, encoded-key traversal, viewport-origin update, origin-delta bucket shifting, visible-object mark/prune refresh helpers, padded-bounds building, encoded-key helpers, type-specific key lookups, and tier insert/remove helpers. B010 keeps the aggregate as a child-routing marker while exact child/split pages carry source; B014 resolves [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) as the mixed retained raw/helper-table island with a comment-only marker unless the live decoder is split. |
| [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) | MSVC scalar deleting destructor wrapper generated from `ObjectList::~ObjectList`; not a handwritten source method. | Class-owned wrapper marker. Real cleanup source belongs to [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md); [UID:0000M4][ObjectList](by-file/ObjectList.md) remains the source-file route. |

## Evidence Notes

- IDA MCP confirms `ObjectList::ObjectList` at `0x00530ee0-0x0053125d`, destructor at `0x00531260-0x00531473`, and scalar deleting destructor at `0x00537290-0x005372c8`.
- 2026-05-31 IDA MCP decompilation verifies the constructor writes all fields in [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md), the ordinary destructor cleans up the same row/global list tiers, and `0x0053125d-0x00531260` is `0xcc` padding.
- 2026-07-07 B007 current MCP session `43ccf853` promotes [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) to the formal `ObjectList::ObjectList(int gridWidth, int gridHeight)` source body. The session reports `server_health ok`, Hex-Rays ready, strings cache ready, constructor size `0x37d`, endpoint `0x0053125d` not a function, two direct MapPane caller sites at `0x0050bc55` and `0x005106e2`, zero endpoint xrefs, zero constructor VA/RVA pointer-pattern hits, exactly two direct rel32 call-pattern hits, and a unique constructor starter signature.
- The accepted constructor body uses `GetMemoryMan()->ZeroAllocateBufferMemory` for row-array tables, `new List(sizeof(ObjectPane *), capacity)` for internal lists, full-list capacity `(gridWidth + 4) * (gridHeight + 4) * 100`, row-list capacity `(gridWidth + 4) * 10`, normal row count `gridHeight + 4`, extended row count `gridHeight + 12`, and the `g_useEpfAssets` / `byte_66DA97` gate for `m_alternateGlobalList`. Compiler-only base/vtable writes, SEH frame setup, security-cookie support, and constructor-unwind landing pads are intentionally excluded from source.
- 2026-07-09 B005 current MCP session `supervisor_nexustk_20260709` promotes [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) to formal first-draft `ObjectList::~ObjectList()` source. The session reports `server_health ok`, Hex-Rays ready, strings ready, destructor size `0x213`, sole scalar-wrapper caller `0x00537296`, direct callees `sub_516030`, `sub_516170`, and `sub_4F4A90`, destructor cleanup order over row arrays/direct lists/global tiers, and `byte_66DA97` / `g_useEpfAssets` optional alternate-tier cleanup.
- The accepted destructor body uses `GetMemoryMan()`, `MemoryMan::FreeBufferMemory`, `delete` on `List*`, structural ObjectList field names, normal row count `m_gridHeight + 4`, extended row count `m_gridHeight + 12`, and the `g_useEpfAssets` gate. Compiler-only vtable restore, final base destructor call, scalar-delete flags, and wrapper delete behavior remain represented by compiler/base mechanics and [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md), not handwritten class source.
- 2026-05-30 IDA MCP confirms `0x00530d00-0x00530ed9` as a real `__thiscall` helper over ObjectList layout fields. It is called from a MapPane wrapper through `MapPane + 0x424`, looks up static-object metadata, scans matching static object panes, and removes, updates, or creates attached [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md) companions.
- 2026-08-11 UID00023D closure resolves the method as `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)`. The exact body scans `m_gridHeight + 12` static-row lists, dereferences List pointer slots, filters by `StaticObjectPane::GetStaticObjectId`, invalidates matches, and applies signed `StaticObjEntry::lightImageIndex` remove/update/create behavior. CPP visibility is supplied by `LightingObjectPane.h`, `MapPane.h`, `ObjectPane.h`, `StaticObjectPane.h`, `../render/StaticObjImageLib.h`, and `../util/List.h`; the declaration remains in this class H and the body remains solely on UID00023D.
- 2026-05-30 IDA MCP confirms `0x00531480-0x00532530` as an ObjectList helper cluster now split into child pages for origin initialization, type-dispatch insert/remove, encoded-key resolution, type-specific index lookup, object-id lookup, and the raw `0x00532450` boolean existence helper with jump table.
- 2026-06-26 B005 Rule 26 incorporation resolves [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) as `ObjectList::HasValidGridOrigin()`: it checks `m_minY` at `+0x08` then `m_minX` at `+0x04` against the constructor's `-30000` uninitialized-origin sentinel, has a single MapPane reindex caller at `0x00505955`, and carries the formal body on the exact child page rather than at class level.
- 2026-06-21 B006 Rule 26 incorporation resolves the raw `0x00532450` child as `ObjectList::ContainsTypedObject(ObjectPane *object)`. It is a retained/source-shaped `thiscall` predicate over `ObjectPane::m_objectType` at `+0xf8`, calls the same typed encoded-key helpers as [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md), returns `key != 0xffffffff`, and does not read the id/serial field at `+0xfc`. IDA/Ghidra/raw bytes support the exact body/table split, while a direct PE scan found no ordinary `E8`/`E9` branch or static VA/RVA pointer to the start; this caps liveness confidence without changing ObjectList ownership.
- 2026-06-06 documentation sync records the immediate categorize/lookup children [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md), [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md), [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md), [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md), [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md), [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md), and [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) with predecessor/successor boundary agreement.
- 2026-06-26 B005 Rule 26 incorporation resolves [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) as `ObjectList::AddObjectPane(ObjectPane *object)`: object type cases `0`/`1` select `+0x14`/`+0x18`; cases `2`/`3`/`4`/`5` select row arrays `+0x1c`/`+0x24`/`+0x20`/`+0x28`; cases `6` through `11` select direct global lists `+0x2c`/`+0x30`/`+0x34`/`+0x38`/`+0x3c`/`+0x40`. Cases `0..4` and `6..10` use a normal 2-tile bounds pad, case `5` extends bottom padding to `10`, and case `11` has no bounds gate. Row-bucket tiers order by column within the selected row; direct/global tiers order by row then column. The active dispatcher inlines this logic and does not call [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md)'s raw tier insertion helpers.
- 2026-06-26 B005 Rule 26 incorporation resolves [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) as `ObjectList::ResolveObjectListKey(unsigned int key)`: it calls the live decoder `DecodeObjectListKey` / `sub_535CE0`, switches decoded key types `0..9` to ObjectList storage fields `+0x14` through `+0x38`, dereferences the selected `List::GetElementAt(index)` slot as `ObjectPane **`, and returns `NULL` for decoded categories above `9`. The helper is MapPane-visible through six traversal wrappers but not proven file-static or tied to a source access label by symbols.
- 2026-06-26 B006 Rule 26 incorporation resolves [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) as `ObjectList::GetTypedObjectKey(ObjectPane *object)`: it reads `m_objectType` at `+0xf8`, dispatches cases `0..8` to the typed encoded-key helper family, returns the encoded key as `unsigned int`, and uses `kObjectListKeyNotFound` (`0xffffffff`) for unsupported types. The six MapPane wrappers seed traversal with this key, call the relevant `ObjectList::MoveKeyTo...` helper, then resolve the mutated key through [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) `ObjectList::ResolveObjectListKey`.
- 2026-06-26 B009 Rule 26 incorporation resolves [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as `ObjectList::FindByObjectId(int objectId)`: it returns `ObjectPane *`, scans `m_tertiaryRowLists` at `+0x24`, `m_primaryCellList` at `+0x14`, and `m_secondaryCellList` at `+0x18`, compares `ObjectPane::m_objectId` at `+0xfc`, preserves `m_objectSerial` only as an alias/caveat, and does not touch the direct global tiers at `+0x2c..+0x40`. MCP session `80de0a67` confirmed `sub_532370` size `0xd3` / `211`, body `0x00532370-0x00532443`, thirteen-byte `0xcc` alignment before [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md), no ordinary direct callees because `List::GetElementAt` is virtual, and 33 xrefs across MapPane/object-update consumers.
- 2026-05-28 IDA MCP confirms `0x00532f70-0x0053728e` as the next ObjectList helper family, with modeled functions, encoded-key helpers, type-specific list lookups, and many IDA-missed prologues inside the range.
- 2026-06-21 B010 Rule 26 incorporation resolves [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) at the source-quality level. The helper family remains class-owned and routed through `NexusTK/map/ObjectList.cpp`; direct PE route scanning separates live helpers (`FindFrontRowObjectAt`, six encoded-key traversal helpers, `UpdateForViewportOrigin`, `ShiftObjectBucketsForOriginDelta`, `MarkVisibleObjectsForRefresh`, `RemoveMarkedVisibleObjects`, `BuildPaddedObjectBounds`, the typed-key lookup child, and `0x00537210`) from retained raw/no-route copies. `MapPaneSpatialIndex` remains only a generated compatibility alias, not the owner.
- 2026-06-26 B014 Rule 26 incorporation resolves [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) as an ObjectList-owned mixed no-code child: raw rectangle/key starts `0x00535b10`, `0x00535b50`, `0x00535b90`, and `0x00535bd0` have no xrefs/direct PE branch/static VA/RVA route; live `DecodeObjectListKey` at `0x00535ce0` has seven direct callers; `0x00535db8-0x00535de8` is the decoder table; and exact formal C++ should remain comment-only unless a future decoder split is assigned.
- B010 accepted these descriptive ObjectList method names for draft/source-routing work, with B005 adding the paired key resolver and B006 adding the typed-key producer: `FindFrontRowObjectAt`, `GetTypedObjectKey`, `MoveKeyToPreviousSelectableObject`, `MoveKeyToNextSelectableObject`, `MoveKeyToPreviousItemTargetObject`, `MoveKeyToNextItemTargetObject`, `MoveKeyToPreviousLivingTarget`, `MoveKeyToNextLivingTarget`, `ResolveObjectListKey`, `UpdateForViewportOrigin`, `ShiftObjectBucketsForOriginDelta`, `MarkVisibleObjectsForRefresh`, `RemoveMarkedVisibleObjects`, and `BuildPaddedObjectBounds`. Exact original spellings and final object-type semantic names remain below final-source confidence.
- Constructor callers are `MapPane::ChangeMap` at `0x0050bbb0` and `MapPane::HandleEffectPacket` at `0x005104d0`, both replacing the map object index after map data changes.
- Documented MapPane callers use the helper island as `ObjectList::DetachAll`, `ObjectList::ShiftAll`, typed `ObjectList::FindStaticObjectPaneAt`, and row/global accessor consumers. Historical `FindObjectAt` is superseded for `[0x00532eb0,0x00532f67)` because the body searches only static rows. B012 resolves the old `GetInternalList` candidate as `ObjectList::GetQuinaryGlobalList()`, with `GetInternalList` kept only as a cleanup-path alias.
- B012 reclassified [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) as exact ObjectList accessor methods. Its live MCP pass confirmed the function inventory, direct field-load bytes, row-bucket bodies, endpoint padding, caller fan-in, and unique range signature.
- 2026-06-06 documentation sync formerly framed [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) as a compatibility/provisional alias subset of [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md). B012 supersedes that source-facing identity: UID `0001D2` is now an exact ObjectList accessor child, while [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) remains the ignored compatibility/search alias.
- 2026-06-01 IDA MCP recheck confirms the helper-island starts and sizes from `0x00532530` through `0x00532eb0`, corrects the early alias subset endpoint to `0x0053272e`, and confirms `0x0053272e-0x00532730` is alignment before `ShiftAll`.
- 2026-06-04 live IDA MCP recheck confirms exact boundaries for the lifecycle and helper islands from `0x00530d00` through `0x005372c8`, reports no function object at raw helper starts `0x00532450`, `0x00532f70`, or `0x00536270`, confirms the constructor/destructor vptr stores to `0x00620288`, and reconfirms alignment padding at `0x0053125d-0x00531260`, `0x0053272e-0x00532730`, `0x0053728e-0x00537290`, and `0x005372c8-0x005372d0`.
- 2026-06-04 live IDA MCP recheck confirms constructor callers at `0x0050bc55` and `0x005106e2`, static-object lighting helper caller `0x0050e30e`, `ShiftAll` caller `0x005058f9`, `DetachAll` callers `0x005045e6`, `0x0050bc1a`, and `0x005106a4`, and `FindObjectAt` callers `0x0050583e` and `0x0050f191`.
- 2026-07-02 B006 current MCP session `1f24c222` revalidates [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) at `87/90` with the same direct class owner/emitter. It confirms exact starts/endpoints, internal `0xcc` padding, predecessor switch-table bytes, later-helper xrefs/callees, decompiled roles, and MapPane caller windows. The accepted split plan keeps [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as an aggregate child-routing marker and queues exact future child pages for `ObjectListShiftAll`, `ObjectListDetachAll`, `ObjectListPruneMarkedRowObjects`, and `ObjectListFindObjectAt`; child pages were not created in that callback because new child UID creation needs a separate split/validator batch.
- 2026-07-15 B003 live MCP session `64c11373` resolves that historical lookup candidate as exact UID0004SI. The `0xb7` body has two callers, selects only `m_staticObjectRows` at `+0x28`, uses List pointer-slot semantics, and compares MapPoint column with tileX then row with tileY. The typed declaration is public in the reconstructed class so MapPane callers can use it naturally; exact method C++ remains only on the child.
- 2026-06-11 live IDA MCP parent-gate refresh reconfirms the class-owned vtable and lifecycle chain: constructor `0x00530ee0-0x0053125d` writes `ObjectList::vftable` at `0x00530f19`, destructor `0x00531260-0x00531473` restores it at `0x00531288`, scalar deleting destructor `0x00537290-0x005372c8` delegates to the ordinary destructor, and the `.rdata` dwords at `0x00620284-0x00620294` contain only the ObjectList RTTI plus three slots before `ObjectPane` RTTI.
- 2026-06-20 B003 Rule 26 incorporation resolves [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) as direct class-owned source-declared/generated-binary output. Raw PE/Capstone recheck confirms the wrapper has no direct `.text` callers, its only target VA pointer is the `ObjectList` vtable slot at `0x00620288`, the ordinary destructor call at `0x00537296` is the only direct code caller of [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), the normal delete path reaches [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), and the flag-4 path calls the one-byte `0x0041b6a0` guard/no-op helper with object size `0x44`. Reconstructed source should declare/define the ordinary `ObjectList` destructor and let MSVC regenerate the scalar deleting wrapper; the child emits only a comment marker.
- 2026-07-14 B002 UID0002BB callback resolves the complete semantic field and key surface. Direct ObjectPane constructor producers map object types `0..11` to Item, Flying, PrimaryEffect, Living, SecondaryEffect, Static, Balloon, HitBar, DamageNumber, ObjectInfo, Lighting, and Sound; ObjectList fields `+0x14..+0x40` use those same families. The exact UID0002BB methods take `ObjectPane *`, dereference `List::GetElementAt` as `ObjectPane **`, preserve no-check row/direct scans, and retain the binary's type-4/category-2 and type-8/category-C key quirks.
- The complete declaration uses `typedef unsigned int ObjectListKey`, one class-level `kObjectListKeyNotFound`, all current public lifecycle/dispatch/find/accessor declarations, nine private `Find*ObjectKey` declarations, and semantic fields. [UID:00009R][ObjectPane](by-class/ObjectPane.md) supplies `friend class ObjectList;` because the accepted binary-shaped methods directly load protected `m_objectType` and `m_objectId`; getters are rejected as absent binary calls.
- Source placement remains `ObjectList.h` plus `NexusTK/map/ObjectList.cpp`. The header includes the complete `LObject` declaration and forward-declares `List`/`ObjectPane`; the source includes complete ObjectPane/List/MapPoint/RectBounds/allocator dependencies. The class block emits before its registered `[[CHILDREN]]`, while exact children remain sole definition owners. Blank child positions preserve the existing deterministic source/range order.

## Assignment Gate

This class clears the strict parent side of the `85/85` gate at `92/93`. [UID:0000M4][ObjectList](by-file/ObjectList.md) is the direct source root, while concrete class-owned type/data children such as [UID:0001YB][ObjectList_vtable](by-type/by-vtable/ObjectList_vtable.md), [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md), and [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) attach here rather than bypassing the class to the by-file page. Completion `92` reflects the corrected guarded H declaration and header-including CPP topology; confidence stays `93` because stripped private identifier spelling remains inferred.

## Open Questions

- Semantic tier identity is resolved to the twelve object families recorded in the layout. Exact stripped identifier spellings remain inferential, so the former structural names are retained only as historical/search aliases and confidence is capped at `93`.
- `ContainsTypedObject`, `GetTypedObjectKey`, and the nine `Find*ObjectKey` names are accepted source-facing spellings. Shorter aliases remain historical possibilities, not implementation blockers or simultaneous declarations.
- Type-4 secondary effects deliberately use encoded key category `2`; type-8 damage-number objects deliberately produce noncanonical category `C`. These are closed binary quirks, not open normalization tasks.
- `AddObjectPane` is the preferred source-facing name for [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md). `InsertByType` and `InsertByTypeDispatch` remain acceptable search aliases only where older docs or generated history used them.
- Keep [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) as an ignored compatibility/search alias only. The accessor method names and ObjectList owner for UID `0001D2` are now stabilized enough for formal child C++.
- Keep only the three unsplit ShiftAll, DetachAll, and PruneMarkedRowObjects names under [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as source-facing candidates until exact child pages are created. UID0004SI closes the former `FindObjectAt` name/order blocker with the typed static-only method; its exact private lexeme remains a bounded confidence cap rather than an ownership or C++ blocker.

## Cross-References

- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md)
- [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md)
- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)
- [UID:0001YB][ObjectList_vtable](by-type/by-vtable/ObjectList_vtable.md)
- [UID:000079][List](by-class/List.md)

## Changes

### 2026-08-24 B006 - UID00037R Refresh Declarations

- Added the two accepted public declarations in binary-address order and documented the exact MapPane Ctrl+R call order, while preserving `RemoveMarkedVisibleObjects()` as a separate method and leaving all existing layout, ownership, and method bodies unchanged.

### 2026-08-11 B003 - UID00023D Lighting-Sync Declaration And Includes

- Preserved `92/93`, owner/emitter `0000M4`, reconstructable true, blank emitter position, and the existing nonblank CPP/H channels.
- Added the public `RefreshStaticObjectLighting(unsigned short staticObjectId)` declaration and the exact complete-type/source includes required by the UID00023D method body before `[[CHILDREN]]`.
- Replaced the provisional-name method-family row with the accepted source ABI, exact row/list behavior, direct child route, and route-negative wrapper caveat without duplicating the child body.

### 2026-07-30 B004 - UID0002OF Header/Vtable Source-Quality Closure

- Moved the complete `ObjectList` declaration from the CPP channel into a guarded `ObjectList.h` H channel with the complete generated `../util/LObject.h` dependency, pointer-only forward declarations, semantic `ObjectListKey`, all accepted public/private methods, and exact `0x44` fields. CPP now contains only `#include "ObjectList.h"` plus `[[CHILDREN]]`.
- Raised completion from `91` to `92`; confidence remains `93`. This corrects source topology without pretending stripped private spellings are original-proof.
- [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) is exact class-owned source-declared/generated-binary output: COL plus scalar deleting destructor, inherited `LObject::GetRuntimeClass`, and inherited `LObject::OnChangeMessage`. The class declaration and virtual destructor regenerate it; do not hand-author a vtable array.
- Live B004 evidence proves direct single `ObjectList : LObject` RTTI, exact predecessor/successor fences, constructor/destructor vptr stores, and vtable-only scalar-wrapper liveness. Historical `sub_4F4B10`, `nullsub_18`, separate-`0x44`, blank-header, and class-declaration-in-CPP assumptions are retained only as superseded history.
- Supervisor Gate 2B handoff keeps UDT ordinal 619/size `0x44` and inherited shared functions protected while renaming/typing/commenting only the exact ObjectList constructor, ordinary destructor, and compiler scalar wrapper listed in the accepted UID0002OF report.

### 2026-07-15 B003 - Typed Static-Row Lookup Declaration

- Raised `90/92` to `91/93` and preserved UID0000M4 owner/emitter routing, true reconstructable state, blank position, complete `0x44` layout, all current lifecycle/dispatch/key/accessor declarations, private helpers, fields, and class-before-children placement.
- Applied exact R5 by adding only the `StaticObjectPane` forward declaration and `FindStaticObjectPaneAt(int tileX, int tileY)` declaration to the complete current block; exact formal hash is report R5.
- Linked source-ready child UID0004SI, historicalized only generic `FindObjectAt`/four-future-child wording, preserved the other three future splits, and retained compiler table/cookie/vtable/scalar-wrapper exclusions.

### 2026-07-14 B002 - UID0002BB Complete Declaration And Semantic Taxonomy

- Raised `85/88 -> 90/92` and replaced the child-only comment marker with the complete `LObject`-derived ObjectList declaration followed by the existing closed `[[CHILDREN]]` route.
- Added `ObjectListKey`, one class not-found constant, all current public/private declarations, the exact semantic `0x44` field set, ObjectPane friendship dependency, nine specialized typed-key helpers, and source/header/compiler ordering.
- Historical structural field/helper names, partial type labels, and no-class-declaration state remain preserved below as superseded history; exact method bodies still belong only to their existing exact children.

### 2026-07-09 B005 - Destructor Child Source Body Sync

- What changed: the lifecycle status, method inventory, and evidence now record [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) as the exact formal first-draft `ObjectList::~ObjectList()` source-body child. UID0001D4 remains the comment-only compiler-generated scalar deleting destructor wrapper.
- Why: B005 current MCP session `supervisor_nexustk_20260709` confirmed exact destructor range, sole scalar-wrapper caller, direct callees, cleanup order, optional `byte_66DA97` / `g_useEpfAssets` tier gate, helper source shape, and vtable/base/scalar-wrapper compiler-mechanics exclusions. This class page remains a child-routing owner and must not duplicate the exact child method body.

### 2026-07-02 B006 - Accessor/Sweep Split-Plan Support Sync

- What changed: the method inventory now records the accepted future exact child split plan for [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md): `ObjectListShiftAll`, `ObjectListDetachAll`, `ObjectListPruneMarkedRowObjects`, and `ObjectListFindObjectAt` over the four later helper ranges.
- Why: B006 current MCP session `1f24c222` confirmed starts/endpoints, padding, callers, callees, and decompiled roles while preserving [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as an aggregate `[[CHILDREN]]` marker routed through this ObjectList class.

### 2026-07-07 B007 - Constructor Source Body Sync

- What changed: the method inventory and evidence now record [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) as the formal source-body constructor child `ObjectList::ObjectList(int gridWidth, int gridHeight)`.
- Why: B007 current MCP session `43ccf853` and accepted report evidence resolved the former constructor empty-emitter blocker. Exact constructor C++ belongs on UID0002JS, while this class page continues to emit only the child-routing marker and must not duplicate the method body.

### 2026-07-01 B008 - RemoveObjectPane And Child-Routing Marker Sync

- What changed: the formal block now emits only the class-level child-routing marker `// ObjectList class-owned methods, layout, vtable, and helper children emit below.` plus `[[CHILDREN]]`; it does not duplicate exact child method bodies.
- What changed: [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md) is now part of the exact emitted method surface as `ObjectList::RemoveObjectPane(ObjectPane *object)`.
- Why: B008 report acceptance resolved the first real ObjectList empty method marker while preserving class-level ownership and avoiding duplicate broad class C++.

### 2026-06-27 B012 - Accessor Method Child Source-Quality Sync

- What changed: the method inventory, evidence, open questions, and cross-references now treat [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) as the exact ObjectList accessor child with formal C++ and accepted source-facing method names.
- Why: B012 live MCP proved the field-load accessors, row-bucket accessors, endpoint/padding, caller fan-in, and ObjectList receiver layout. This resolves the previous `MapPaneSpatialIndex` alias/name blocker for the early accessor subset without requiring the class page to emit a full class declaration.

### 2026-06-26 B014 - Encoded-Key Helper Island Sync

- What changed: the method inventory and evidence now record [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) as an ObjectList-owned mixed child with retained route-negative raw helpers, live `DecodeObjectListKey`, table/padding ownership, and target-specific blank-formal no-code policy.
- Why: B014's accepted report resolved the encoded-key island source-quality blockers without requiring the class page to emit a declaration or duplicate child bodies.

### 2026-06-26 B009 - FindByObjectId Child Source-Quality Sync

- What changed: the method inventory and evidence now name [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as `ObjectList::FindByObjectId(int objectId)` and record that the exact child carries the formal `ObjectPane *` body over `m_tertiaryRowLists`, `m_primaryCellList`, `m_secondaryCellList`, and `ObjectPane::m_objectId`.
- Why: B009's accepted source-quality report resolved the object-id lookup source shape and ObjectList class ownership without requiring the class page to emit a full class declaration or duplicate the method body.

### 2026-06-26 B006 - GetTypedObjectKey Child Source-Quality Sync

- What changed: the method inventory, evidence, and open questions now reflect B006's conclusion that [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) is `ObjectList::GetTypedObjectKey(ObjectPane *object)` and carries formal C++ on the exact child page.
- Why: live MCP evidence proved the value-returning typed-key dispatcher seeds MapPane ObjectList traversal wrappers before `MoveKeyTo...` and `ResolveObjectListKey`.

### 2026-06-26 B005 - ResolveObjectListKey Dispatcher Sync

- What changed: the method inventory and evidence now name [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) as `ObjectList::ResolveObjectListKey(unsigned int key)`, record its decoded-key-to-storage map and `ObjectPane *` return, and keep class-level C++ blank while the exact child carries the method body.
- Why: B005's accepted source-quality report resolved the encoded-key resolver source shape and MapPane-visible helper placement without requiring the broad class page to emit a class declaration or duplicate method body.

### 2026-06-26 B005 - HasValidGridOrigin Predicate Sync

- What changed: the method inventory and evidence now name [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) as `ObjectList::HasValidGridOrigin()`, document the `m_minY`/`m_minX` `-30000` sentinel predicate, and keep class-level C++ blank while the exact child carries the method body.
- Why: B005's accepted source-quality report resolved the ObjectList origin predicate and active MapPane reindex guard without requiring the broad class page to emit a class declaration or duplicate method body.

### 2026-06-26 B005 - AddObjectPane Dispatcher Sync

- What changed: the method inventory and evidence now name [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) as `ObjectList::AddObjectPane(ObjectPane *object)`, mark `InsertByType` / `InsertByTypeDispatch` as stale aliases, record the 12-case structural tier map, and keep class-level C++ blank while the exact child carries the method body.
- Why: B005's accepted source-quality report resolved the active insertion dispatcher source shape at method level without requiring the broad class page to emit the full class declaration.

### 2026-06-21 - ContainsTypedObject Child Source-Quality Sync

- What changed: the method inventory, evidence, and open questions now reflect B006's conclusion that [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) is a retained/source-shaped `ObjectList::ContainsTypedObject(ObjectPane *object)` predicate with first-draft C++ on the exact child page.
- Why: the child reanalysis resolved the old generic "raw existence helper" wording, proved the body/table split and no-direct-route caveat, and kept the class as the correct owner.

### 2026-06-21 - Extended Helper Source-Quality Sync

- What changed: the method inventory and evidence now carry B010's [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) route scan, source-facing helper names, ObjectList ownership decision, child emission policy, and `MapPaneSpatialIndex` rejection.
- Why: the report closes the aggregate's old raw-start reachability and vague-name blocker for ordinary static routes while preserving exact child/split pages as the correct place for formal C++.

### 2026-06-20 - Scalar Deleting Destructor Source-Quality Sync

- What changed: the method inventory and evidence now state that [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) is a class-owned MSVC scalar deleting destructor wrapper generated from `ObjectList::~ObjectList`, not a handwritten source method and not a by-file/direct helper owner.
- Why: B003's Rule 26 report matched raw PE/Capstone evidence, vtable data, constructor/destructor vptr stores, no-direct-caller proof, ordinary destructor relationship, and the `0x0041b6a0` flag-4 helper path to the established class-owned wrapper policy.

### 2026-06-06 - Synced Accessor Alias And Child Boundary Evidence

- What existed before: the class page still described the early accessor surface as overlapping `MapPaneSpatialIndex` list/row accessor rows and did not mention the freshly synchronized categorize/lookup child boundary pass.
- What changed: the method inventory now points to the exact categorize aggregate and compatibility alias subset pages, the evidence notes list the synced child pages, and the open alias question now records ObjectList ownership as the current working conclusion.
- Why: the linked by-memory pages now document all immediate `0x00531480-0x00532530` children at the 80+ gate and frame `0x00532530-0x0053272e` as a compatibility alias under the broader ObjectList accessor/sweep island.

### 2026-05-31 - Split Lifecycle Into Exact Constructor And Destructor Pages

- What existed before: the class inventory listed the lifecycle aggregate and inline constructor/destructor ranges without exact child memory pages.
- What changed: the constructor and ordinary destructor now have their own exact by-memory pages and are cross-linked from the class inventory.
- Why: IDA MCP reports `sub_530EE0` as `0x00530ee0-0x0053125d`, `sub_531260` as `0x00531260-0x00531473`, and byte reads confirm the gap between them is alignment padding.

### 2026-05-30 - Refined Discontiguous Helper Method

- What existed before: the class method inventory treated `0x00530d00-0x00530ed9` as a remove/search helper candidate.
- What changed: the helper is now listed as a static-object lighting sync helper, still with its final source-facing name left provisional.
- Why: IDA MCP shows the method using ObjectList row/global tiers, static-object metadata from `g_pStaticObjImageLib`, and `LightingObjectPane` constructor/set-intensity calls to remove, update, or create attached lighting companions.

### 2026-05-28 - Added ObjectList Categorize/Lookup Helper Cluster

- What existed before: the `0x00531472-0x00532530` span was an unknown gap and the destructor endpoint was one byte short.
- What changed: the destructor endpoint is now `0x00531473`, and the `0x00531480-0x00532530` helper cluster is part of the class method inventory.
- Why: IDA MCP confirms the exact helper starts and embedded switch-table structure, all operating on ObjectList/object-pane type dispatch.

### 2026-05-30 - Split ObjectList Categorize/Lookup Child Pages

- What existed before: the class page referenced `0x00531480-0x00532530` only as a single aggregate helper cluster.
- What changed: [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) now owns nested child pages for each method-level helper and switch-table-backed dispatch unit.
- Why: IDA MCP revalidated the modeled starts/endpoints and raw `0x00532450` helper body, making method-level documentation possible without losing the aggregate ObjectList ownership.

### 2026-06-01 - Accessor Island Parent Confirmed

- What changed: the `0x00532530-0x00532f67` accessor/sweep island is now explicitly attached to the ObjectList file page, and the `MapPaneSpatialIndex` alias endpoint is corrected to `0x0053272e`.
- Why: IDA MCP function, decompile, caller, and byte evidence shows the early alias subset uses ObjectList fields and that only `0x0053272e-0x00532730` is padding before the next ObjectList helper.

### 2026-05-28 - Added Extended Type Lookup Helper Family

- What existed before: the class method inventory stopped at the `0x00532530-0x00532f67` accessor/sweep island before the scalar deleting destructor.
- What changed: `0x00532f70-0x0053728e` is now included as an ObjectList extended type lookup/helper family.
- Why: IDA MCP and manual disassembly show modeled and IDA-missed helpers that operate on ObjectList fields, encoded object-list keys, and type-specific list lookup/removal paths.

### 2026-05-28 - Corrected Scalar Destructor Endpoint

- What existed before: the scalar deleting destructor was listed as `0x00537290-0x005372c7`.
- What changed: the endpoint is now `0x005372c8`.
- Why: IDA MCP function review reports the destructor wrapper as `0x00537290-0x005372c8`; byte `0x005372c7` is part of the function body, not padding.

### 2026-06-04 - Live IDA Consolidation And Score Update

- What existed before: the class page carried `74/84` and still described importer/output splits as evidence.
- What changed: scores are now `84/88`, stale importer-derived wording was removed, and the class evidence now records current IDA function boundaries, raw-start caveats, caller sets, vtable dwords, and padding ranges.
- Why: live IDA MCP confirms ObjectList lifecycle, vtable, layout, map-only caller surface, and helper-island boundaries strongly enough to move the class out of low-confidence reconstruction status. It remains below final C++ levels because helper names and some raw starts in the extended family are still unresolved.

### 2026-06-06 A008 Parent-Chain Pass

- What existed before: [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) pointed at this class, but the class had no autogen parent, leaving the layout blocked by `autogen_parent_unknown`.
- What changed: `AUTOGEN_PARENT_UID` is set to [UID:0000M4][ObjectList](by-file/ObjectList.md), the `NexusTK/map/ObjectList.cpp` source root.
- Why: [UID:0000M4][ObjectList](by-file/ObjectList.md) is assigned to that generated source root at `84/88`; this class is `84/88`; and the lifecycle, vtable, layout, map-only caller surface, helper-island, and `MapPaneSpatialIndex` alias evidence all support `map/ObjectList.cpp` ownership.

### 2026-06-11 - Parent-Gate Refresh For Vtable Children

- What existed before: the class carried strong ownership evidence but remained at `84/88`, blocking strict `85/85` assignment for class-owned vtable children.
- What changed: completion is now `85`, and the evidence/assignment sections explicitly record the class as the direct owner for ObjectList vtable/type-data children while retaining [UID:0000M4][ObjectList](by-file/ObjectList.md) as the source root.
- Why: live IDA MCP reconfirmed the lifecycle boundaries, constructor/destructor vtable stores, scalar-deleting-destructor wrapper, exact vtable dwords, and neighboring `ObjectPane` RTTI boundary; the remaining unresolved helper names are still documented but no longer block parent-side ownership for this narrow vtable assignment.

### 2026-06-18 - Tier Helper Source-Quality Sync

- What changed: recorded B001's [UID:0002BC][0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers](by-memory/0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md) conclusion that `+0x38`, `+0x3c`, and `+0x40` are structurally named `tertiaryGlobalList`, `quaternaryGlobalList`, and `quinaryGlobalList`, with lookup prefixes `0x80000000`, `0x90000000`, and `0xa0000000`.
- Why: direct PE reachability and helper-family analysis now close the old high-tier structural naming question for this class, while leaving only semantic render/object-type names deferred to later object-type taxonomy work.

### 2026-07-14 - UID00037X MapPane Lifecycle Declaration Sync

- The complete managed declaration now includes `void DetachAll(ObjectPane *preserveObject)` and `void RemoveMarkedVisibleObjects()` without changing any existing type/key/accessor/private-field declaration or `[[CHILDREN]]` placement.
- `MapPane::ChangeMap` calls `DetachAll(m_activeObjectPane)` before deleting and recreating the map-owned ObjectList. The argument is an optional preserved active object; the method remains an ObjectList lifecycle method and is not moved into MapPane.
- `MapPane::FinishVisibleObjectRefresh` calls `RemoveMarkedVisibleObjects()` through `m_objectList`; the exact out-of-line body and the UID0001B1 inline completion analog both establish the declaration. UID0001AW produces the pending mark/refresh state and UID0003TK consumes/clears it.
- Existing ObjectList docs already resolved both semantic method names in the accessor/sweep and extended-helper inventories. This callback closes only the missing class declaration surface; exact method children remain sole definition owners.
- Scores, owner/emitter, layout, key taxonomy, source route, and all unrelated historical evidence remain unchanged.
