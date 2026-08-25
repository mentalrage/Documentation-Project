*** UID:0000M4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectList

## UID00037R External MapPane Refresh Consumer - 2026-08-24

- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) is an external `NexusTK/map/MapPane.cpp` consumer, not an ObjectList source child. At `0x00507027` it calls `ObjectList::MarkVisibleObjectsForRefresh()` (`0x00535900`), then at `0x00507032` it calls `ObjectList::PruneMarkedRowObjects()` (`0x00532e20`) on the same guarded `m_objectList` receiver.
- [UID:00009Q][ObjectList](by-class/ObjectList.md) now declares both methods in `ObjectList.h` in binary-address order, `PruneMarkedRowObjects` before `MarkVisibleObjectsForRefresh`. Existing exact/aggregate ObjectList pages retain definition ownership and source placement; no MapPane body or wrapper is emitted into ObjectList.cpp.
- `RemoveMarkedVisibleObjects()` at `0x005359e0` remains a separate method used by other refresh-completion paths. The UID00037R call to `0x00532e20` must not be rewritten as that method.

## UID00037X MapPane Consumer Synchronization

- The complete ObjectList class declaration now includes `DetachAll(ObjectPane *preserveObject)` and `RemoveMarkedVisibleObjects()` while preserving every existing constructor/destructor, typed-key, lookup, accessor, storage, and child declaration.
- UID0004QE `MapPane::ChangeMap` calls `DetachAll(m_activeObjectPane)` before deleting the old list and constructing `ObjectList(m_visibleTileColumns, m_visibleTileRows)`. The preserve argument and map-change callers agree with the existing `0x00532b80` lifecycle inventory.
- UID0004QA `MapPane::FinishVisibleObjectRefresh` calls `RemoveMarkedVisibleObjects()` and then clears MapPane pending state. UID0001B1 contains the same completion inline, while UID0001AW produces marks/pending state and UID0003TK independently consumes/clears it.
- UID0004QC uses `GetFrontRowBucket` and `FindByObjectId` for directional/selected movement target collection; UID0004QD uses `FindByObjectId` for unchecked squared-distance sorting. UID0004Q8/UID0004QC access ObjectPane fields through MapPane friendship rather than changing ObjectList APIs.
- These are declaration and consumer-route synchronizations only. ObjectList exact child pages remain sole definition owners; MapPane children remain in MapPane.cpp. No ObjectList score/path/layout, raw-helper disposition, compiler table, cookie, vtable, scalar-wrapper, or unrelated source inventory changes.

## Status

- Proposed module: `NexusTK/map/ObjectList.cpp`
- Proposed header: `NexusTK/map/ObjectList.h`
- Current source route: [UID:00009Q][ObjectList](by-class/ObjectList.md) owns the complete human-written class declaration in `ObjectList.h`; exact by-memory children own method bodies routed into `ObjectList.cpp`. [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) now owns the complete `ObjectList::RefreshStaticObjectLighting(unsigned short)` body. Compiler-emitted RTTI, vtable data, and the scalar deleting wrapper remain documented binary evidence and are not handwritten source blocks.
- Confidence: very strong for map-specific module ownership, complete header/class route, lifecycle/vtable ownership, semantic storage/type/key taxonomy, exact helper ranges and child order, accessor methods, typed static-row lookup, and layout agreement. Remaining uncertainty is confined to stripped names in the three unsplit helpers and unrelated raw islands.

## Generated Output Audit

The B008 ObjectList empty-emitter callback used `auto-generated/NexusTK/map/ObjectList.cpp` as a generated-output baseline at validator command `000000003224`, refreshed `2026-07-01T03:54:15-04:00`. That pre-callback generated file had `23` total ObjectList-family emitters, `9` filled bodies, `14` empty markers, `39.1%` filled coverage, and by-file report coverage `0`.

Before the B007 UID0002JS implementation, the later generated `auto-generated/NexusTK/map/ObjectList.cpp` snapshot used validator command `000000007832`, refreshed `2026-07-07T03:37:36-04:00`, and still showed [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) as an empty emitter marker at `85/91`. B007 promotes that child to formal constructor source C++; any generated `ObjectList.cpp` refresh after this documentation update is validator-owned and must not be hand-edited here.

Before the B005 UID0001D1/UID0002JT implementation callback, the generated `auto-generated/NexusTK/map/ObjectList.cpp` snapshot used validator command `000000008089`, refreshed `2026-07-09T12:08:38-04:00`: UID0001D1 emitted the aggregate marker, UID0002JS emitted `ObjectList::ObjectList(int gridWidth, int gridHeight)`, and UID0002JT still remained an empty emitter marker. B005 promotes UID0002JT to formal first-draft `ObjectList::~ObjectList()` source; any generated `ObjectList.cpp` refresh after this documentation update is validator-owned and must not be hand-edited here.

The source route remains [UID:0000M4][ObjectList](by-file/ObjectList.md) / `NexusTK/map/ObjectList.cpp`, while class-owned methods, layout/vtable markers, and helper children route through [UID:00009Q][ObjectList](by-class/ObjectList.md) or exact child pages. Broad by-file and by-class pages must not duplicate exact child method bodies. Rejected owners for this family remain `MapPane`, `MapPaneSpatialIndex`, generic `List`, `RectBounds`, `ObjectPane`, and generic utility/source-helper files; those pages are callers, dependencies, aliases, or payload classes rather than the ObjectList storage owner.

The current pre-callback generated baseline is validator command `000000019926`, refreshed `2026-07-30T10:34:57-04:00` from `foreground-generated-refresh`. `auto-generated/NexusTK/map/ObjectList.cpp` was SHA256 `262B93D950E3D1D2AAEA91D2984FFEE285586C5D75FF17459D66A801D867407A`, `30,650` bytes, and `951` lines. At that checkpoint the complete `ObjectList` declaration was still physically emitted in the CPP and no `ObjectList.h` existed. The accepted [UID:00009Q][ObjectList](by-class/ObjectList.md) formal channels now move that declaration to H and make CPP include `ObjectList.h` before `[[CHILDREN]]`; a later generated refresh is supervisor/validator-owned and must not be performed by editing generated files.

## File Role

`ObjectList.cpp` is the likely original owner of the map-world object indexing container used by [UID:0000L3][MapPane](by-file/MapPane.md). It should not be merged into `util/List.cpp`: it uses the generic [UID:000079][List](by-class/List.md) container internally, but every confirmed constructor/helper caller is map-rendering, map-transition, hit-test, scroll, or object cleanup code.

The strongest working reconstruction is:

```text
map/ObjectList.h
map/ObjectList.cpp
```

with `MapPane.h` holding an `ObjectList*` member around the current `MapPane + 0x424` object-index field.

## Header And Source Placement

- `ObjectList.h` requires the complete `LObject` base declaration before `class ObjectList : public LObject`; `List`, `ObjectPane`, and `StaticObjectPane` may be forward-declared because the class stores only pointers and declares pointer parameters/returns. The header owns `typedef unsigned int ObjectListKey`, the complete `ObjectList` declaration, the typed `FindStaticObjectPaneAt(int tileX, int tileY)` declaration, the class-level `kObjectListKeyNotFound`, semantic fields, public methods, and nine private `Find...ObjectKey` declarations.
- `ObjectList.cpp` requires complete definitions/declarations for `ObjectPane`, `StaticObjectPane`, `LightingObjectPane`, `StaticObjImageLib`, `StaticObjEntry`, `List`, `MapPoint`, `RectBounds`, `MemoryMan`, `GetMemoryMan`, `InitRectBounds`, and encoded-key support before exact child definitions. The class CPP route now includes `ObjectList.h`, `LightingObjectPane.h`, `MapPane.h`, `ObjectPane.h`, `StaticObjectPane.h`, `../render/StaticObjImageLib.h`, and `../util/List.h`. The source must not depend on a fictional `ObjectListPosition`, `GetObjectListPosition`, `RectBoundsContainsPoint`, or target-owned generic lookup helper.
- Exact method emission order follows the registered class children. Within UID0002BB it is address order: `FindStaticObjectKey`, `FindLivingObjectKey`, `FindItemObjectKey`, `FindFlyingObjectKey`, `FindPrimaryEffectObjectKey`, `FindSecondaryEffectObjectKey`, `FindBalloonObjectKey`, `FindHitBarObjectKey`, and `FindDamageNumberObjectKey`.
- Class/vtable declarations regenerate vtable/RTTI/scalar deleting destructor output. Switch tables, security-cookie/SEH support, inter-function alignment, and aggregate markers are compiler or documentation output, not handwritten methods. This by-file page remains prose-only and carries no `RECONSTRUCTION_CPP` metadata.
- Historical structural field/helper names and `LivingObjectPane *` target signatures remain searchable provenance only. Current source uses semantic fields, `ObjectPane *`, `ObjectListKey`, exact pointer-slot dereference, and observed no-check behavior.

## Proposed Contents

| Entity | Current range | Evidence/source-facing caveat | Proposed ownership |
| --- | --- | --- | --- |
| [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) | `0x00530d00-0x00530ed9` | Exact `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)` body. It scans `m_staticObjectRows` through `m_gridHeight + 12`, invalidates matching static panes, and removes, updates, or creates/attaches `LightingObjectPane` companions from signed `StaticObjEntry::lightImageIndex`. The sole `0x0050e300-0x0050e317` MapPane wrapper remains route-negative at its start but tail-jumps here at `0x0050e30e`. | `map/ObjectList.cpp` |
| [UID:00009Q][ObjectList](by-class/ObjectList.md) lifecycle | [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) | Constructor/destructor/vtable stores are exact. [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) carries formal `ObjectList::ObjectList(int gridWidth, int gridHeight)` source under the lifecycle aggregate; [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) now carries formal first-draft `ObjectList::~ObjectList()` source; the scalar deleting destructor is class-owned compiler-generated wrapper output for source-level `ObjectList::~ObjectList`; route it through the class into this source root, not directly to the by-file page. | `map/ObjectList.cpp` |
| [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) | `0x00531480-0x00532530` | IDA-modeled helper cluster plus the retained raw `ContainsTypedObject` switch. Exact children emit `HasValidGridOrigin`, `AddObjectPane`, `RemoveObjectPane`, `ResolveObjectListKey(ObjectListKey)`, `GetTypedObjectKey`, `FindByObjectId`, and `ContainsTypedObject`. Current bodies use `ObjectPaneType`, `ObjectListKey`, and semantic item/flying/effect/living/static/balloon/hit-bar/damage-number/object-info/lighting/sound fields. `FindByObjectId` scans living rows, item objects, then flying objects. The aggregate routes exact child bodies and emits no duplicate source. | `map/ObjectList.cpp` |
| [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) | `0x00532530-0x0053272e` | Exact ObjectList accessor-method child with formal C++ for flat/global and row-bucket accessors. `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` are search aliases only. | `map/ObjectList.cpp` |
| `ObjectList::ShiftAll` candidate / future `ObjectListShiftAll` child | `0x00532730-0x00532b72` | Current B006 MCP evidence shows the MapPane scroll caller passes pixel-scaled deltas through `MapPane+0x424`; the body iterates ObjectList row/global tiers and shifts stored object rectangles. | `map/ObjectList.cpp` |
| `ObjectList::DetachAll` candidate / future `ObjectListDetachAll` child | `0x00532b80-0x00532e11` | Three current callers from MapPane cleanup/change/effect paths; cleanup passes `0`, while change/effect paths pass `[MapPane+0x418]` as preserve object. Final public name remains child-level provisional. | `map/ObjectList.cpp` |
| `ObjectList::PruneMarkedRowObjects` candidate / future exact child | `0x00532e20-0x00532eae` | Current B006 MCP evidence shows the body scans row arrays `+0x1c/+0x20` backward and releases objects whose marker at `+0x13c` is `-1`; this supersedes generic object-prune wording. | `map/ObjectList.cpp` |
| [UID:0004SI][0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt](by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md) `ObjectList::FindStaticObjectPaneAt` | `0x00532eb0-0x00532f67` | Exact typed static-row lookup: two MapPane callers, extended padded bounds, `m_staticObjectRows` indexing by tileY/row, List pointer-slot dereference, MapPoint column/X then row/Y comparison, first match or `NULL`, and complete source body. | `map/ObjectList.cpp` |
| [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) | `0x00532f70-0x0053728e` | Mixed modeled/raw helper aggregate over front-row lookup, encoded-key traversal, viewport-origin update, origin-delta bucket shift, visible-object mark/prune, bounds building, typed-key lookup, and tier insert/remove helpers. The aggregate is a child-routing marker while exact children carry source. [UID:0002BB][0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers](by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md) now carries nine complete ObjectPane-based semantic key methods in exact address order; [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) remains a comment-only mixed child containing route-negative raw helpers, the live decoder, table, and padding. | `map/ObjectList.cpp` |
| [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) | data layout | type doc | `map/ObjectList.h` |

## Evidence

- `ObjectList::ObjectList` allocates 13 internal `List` containers or list-array tables from padded map dimensions, including row-counts of `gridHeight + 4` and `gridHeight + 12`.
- 2026-05-31 IDA MCP verifies the exact constructor range as `0x00530ee0-0x0053125d`, the ordinary destructor range as `0x00531260-0x00531473`, and the bytes between them as three `0xcc` alignment bytes.
- IDA MCP caller checks show constructor calls only from `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`.
- 2026-07-07 B007 current MCP session `43ccf853` promotes [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) from the generated empty-emitter state to formal constructor source. The session reports `server_health ok`, Hex-Rays ready, strings cache ready, `sub_530EE0` size `0x37d`, endpoint `0x0053125d` not a function, two direct MapPane caller sites at `0x0050bc55` and `0x005106e2`, zero endpoint xrefs, zero constructor VA/RVA pointer-pattern hits, exactly two direct rel32 call-pattern hits, and a unique starter signature.
- The accepted constructor body belongs on the exact child and uses `GetMemoryMan()->ZeroAllocateBufferMemory`, `List::List(int elementSize, int pageSize)`, origin/grid fields, all twelve semantic storage names, and the `g_useEpfAssets` / `byte_66DA97` damage-number gate. This file page does not duplicate the body or compiler-only EH/security-cookie/unwind mechanics.
- 2026-07-09 B005 current MCP session `supervisor_nexustk_20260709` promotes [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) from the generated empty-emitter state to formal first-draft destructor source. The session reports `server_health ok`, Hex-Rays ready, strings ready, `sub_531260` size `0x213`, sole scalar-wrapper caller `0x00537296`, direct callees `sub_516030`, `sub_516170`, and `sub_4F4A90`, and a cleanup order over `+0x24`, `+0x28`, `+0x14/+0x18`, paired `+0x1c/+0x20`, and globals `+0x2c/+0x30/+0x34/+0x38/+0x3c/+0x40`.
- The accepted destructor body belongs on the exact child and uses `GetMemoryMan()`, `MemoryMan::FreeBufferMemory`, `delete` on `List *`, the twelve semantic fields, and the matching damage-number cleanup gate. This file page does not duplicate the body or compiler-only vtable restore, base-destructor call, scalar-delete flags, SEH/security-cookie scaffolding, or scalar-wrapper behavior.
- `0x00530d00-0x00530ed9`, `0x00531480-0x00532530`, `0x00532530-0x00532f67`, and `0x00532f70-0x0053728e` are adjacent/discontiguous object-list helper islands. The first is now source-closed as `RefreshStaticObjectLighting`: it scans the exact static-row and lighting-list fields by unsigned static-object id, calls `InvalidateRect(NULL)`, and performs signed-index remove/update/create behavior in source-significant order. The middle clusters categorize, remove, and look up object panes through type-dispatch helpers; the accessor island returns fields at the exact offsets initialized by the constructor; and the extended helper family handles encoded-key and type-specific list lookup/removal work.
- 2026-06-21 B010 Rule 26 incorporation updates the extended helper family with direct PE route evidence and source-facing helper names. It confirms `ObjectList.cpp` owns `FindFrontRowObjectAt`, the six `MoveKeyTo...` traversal helpers, `UpdateForViewportOrigin`, `ShiftObjectBucketsForOriginDelta`, `MarkVisibleObjectsForRefresh`, `RemoveMarkedVisibleObjects`, `BuildPaddedObjectBounds`, encoded-key decode/lookup helpers, and the tier helper cluster. It rejects moving this surface to `MapPane`, `MapPaneSpatialIndex`, generic `List`, rectangle geometry helpers, object-pane classes, target-selection panes, or `MapRefreshDimmer`.
- 2026-06-26 B014 Rule 26 incorporation resolves [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) under this source root with `ObjectListKey`/`rowSelector` terminology, corrected child endpoints, no-route proof for raw starts `0x00535b10`, `0x00535b50`, `0x00535b90`, and `0x00535bd0`, live `DecodeObjectListKey` caller evidence for `0x00535ce0`, and an exact-child split policy that keeps the combined formal block comment-only unless a future decoder UID is assigned.
- 2026-07-01 B008 implementation callback uses generated `ObjectList.cpp` command `000000003224` / refreshed `2026-07-01T03:54:15-04:00` as the pre-callback audit baseline with `23` total emitters, `9` filled, `14` empty, and `39.1%` filled. It promotes [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md) to an emitted `ObjectList::RemoveObjectPane(ObjectPane *object)` exact child body and converts broad aggregate/type/vtable empty markers into explicit child-routing or no-code comment markers.
- 2026-06-22 B001 shared-`GM` literal sync confirms that [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) is the ObjectList source-use route for [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md). The six encoded-key/object-list traversal helpers `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, and `sub_533D00` account for eighteen direct `aGm` xrefs from `0x0053321a` through `0x00533f19`, call `sub_535CE0` and `__wcsicmp`, and compare candidate object-name suffixes against `L"GM"`. ObjectList is the largest consumer but still not the canonical owner of the pooled literal because MapPane and LivingObjectPane own separate direct use sites; generated `ObjectList.cpp` should use normal local literal spelling in exact helper bodies rather than inventing a shared declaration.
- 2026-05-30 IDA MCP revalidated `0x00531480-0x00532530` and the aggregate now has nested child by-memory pages for each method-level helper and switch-table-backed dispatch unit.
- 2026-06-26 B005 Rule 26 incorporation resolves [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) as `ObjectList::HasValidGridOrigin()`. The exact child, not this file page, emits the one-body formal C++ for the `m_minY` then `m_minX` `-30000` sentinel predicate used by the MapPane reindex guard.
- 2026-06-26 B005 established [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) as `ObjectList::AddObjectPane(ObjectPane *object)`. UID0002BB synchronizes its current source to `ObjectPaneType` and semantic storage while preserving normal two-tile bounds, static bottom pad `10`, sound no-bounds behavior, ordering, and `List::InsertAt(index, 1, &object)`.
- 2026-06-26 B005 established [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md); its current signature is `ObjectList::ResolveObjectListKey(ObjectListKey key)`, with semantic fields, live decoder cases `0..9`, `ObjectPane *` return, and default `NULL` above `9`.
- Evidence-time 2026-06-26 B006 resolved [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) as `ObjectList::GetTypedObjectKey(ObjectPane *object)`. The exact child now returns `ObjectListKey`, uses `ObjectPaneType` and semantic helpers, preserves `kObjectListKeyNotFound`, and provides the MapPane traversal seed before `MoveKeyTo...` and `ObjectList::ResolveObjectListKey`.
- 2026-06-26 B009 established [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as `ObjectList::FindByObjectId(int objectId)`. Its current exact body scans `m_livingObjectRows`, `m_itemObjects`, and `m_flyingObjects`, compares `ObjectPane::m_objectId`, and returns `NULL`; the `0xd3` range, thirteen-byte successor alignment, virtual accessor, and 33 xrefs are unchanged.
- 2026-06-21 B006 Rule 26 incorporation resolves the raw child [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) as `ObjectList::ContainsTypedObject(ObjectPane *object)`. The helper dispatches on `ObjectPane::m_objectType` at `+0xf8`, calls the ObjectList type-specific encoded-key lookup helpers, returns `key != 0xffffffff`, and leaves object-id/serial lookup to [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md). The exact child emits first-draft C++; this file page remains the `NexusTK/map/ObjectList.cpp` source root and should not duplicate the child body.
- 2026-06-06 documentation sync records the categorize/lookup aggregate's immediate children through [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md), updates [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as the parent accessor/sweep island, and treated [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) as a compatibility alias. B012 supersedes that by renaming/reclassifying the child as [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md), an exact ObjectList method child that carries the formal accessor C++.
- `MapPane` destructor, map change, effect packet handling, rendering, scroll, and hit-test methods all call into this helper surface.
- `FpsPane::UpdateStatistics` calls read-only ObjectList accessors for diagnostics, which is a consumer relationship and not source ownership.
- 2026-06-04 live IDA MCP recheck confirms exact boundaries for `0x00530d00-0x00530ed9`, `0x00530ee0-0x0053125d`, `0x00531260-0x00531473`, `0x00531480-0x00531498`, `0x005314a0-0x00531bdc`, `0x00531c10-0x00532142`, `0x00532180-0x0053229e`, `0x005322d0-0x00532341`, `0x00532370-0x00532443`, `0x00532530-0x0053272e`, `0x00532730-0x00532b72`, `0x00532b80-0x00532e11`, `0x00532e20-0x00532eae`, `0x00532eb0-0x00532f67`, and `0x00537290-0x005372c8`. The same check reports no function object at raw helper starts `0x00532450`, `0x00532f70`, or `0x00536270`.
- 2026-06-04 live IDA MCP recheck confirms constructor callers at `0x0050bc55` and `0x005106e2`, static-object lighting helper caller `0x0050e30e`, `ShiftAll` caller `0x005058f9`, `DetachAll` callers `0x005045e6`, `0x0050bc1a`, and `0x005106a4`, plus the two then-provisional `FindObjectAt` callers at `0x0050583e` and `0x0050f191`.
- 2026-07-02 B006 current MCP session `1f24c222` revalidates [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as an `87/90` ObjectList aggregate routed through [UID:00009Q][ObjectList](by-class/ObjectList.md). The pass confirms exact helper starts/endpoints, internal alignment padding, predecessor switch-table bytes, xrefs/callees, decompiled roles, and MapPane caller windows for the four later helper ranges. The accepted source-root plan keeps [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as a `[[CHILDREN]]` aggregate and queues exact future child pages for `ObjectListShiftAll`, `ObjectListDetachAll`, `ObjectListPruneMarkedRowObjects`, and `ObjectListFindObjectAt`; no new child pages were created in that callback because new child UID creation needs a separate split/validator batch.
- 2026-07-15 B003 live MCP session `64c11373` resolves the fourth range as exact child UID0004SI with source signature `StaticObjectPane *ObjectList::FindStaticObjectPaneAt(int tileX, int tileY)`. Its exact `0xb7` body/hash, two callers, static-row-only field, List element-slot dereference, MapPoint order, null fallback, ObjectList ownership, and complete human source are now closed. ShiftAll, DetachAll, and PruneMarkedRowObjects remain the only future splits in this aggregate.
- 2026-06-04 live IDA MCP reads `0x00620284 -> ??_R4ObjectList@@6B@`, `0x00620288 -> 0x00537290`, `0x0062028c -> 0x004f4b10`, `0x00620290 -> 0x0041b6c0`, and `0x00620294 -> ??_R4ObjectPane@@6B@`; xrefs to `0x00620288` are the constructor/destructor vptr stores at `0x00530f19` and `0x00531288`.
- The exact [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) sixteen-byte payload is `b4 cc 64 00 90 72 53 00 10 4b 4f 00 c0 b6 41 00`, SHA256 `0185B14135A28B9F2A66A7A9B1CD92708552A7AE4346769D5678477A166DDC2E`. Its leading COL pointer is `0x0064ccb4`; the three canonical slots are `ObjectList::ScalarDeletingDestructor` (`0x00537290`), inherited `LObject::GetRuntimeClass` (`0x004f4b10`), and inherited `LObject::OnChangeMessage` (`0x0041b6c0`). `0x00620294` starts the next `ObjectPane` COL and is not part of the ObjectList vtable.
- Live RTTI evidence resolves direct single inheritance from `LObject`: ObjectList type descriptor `0x0067830c`, class hierarchy descriptor `0x0064ccc8`, base-class array `0x0064ccd8`, and base descriptors `0x0064cce4` (`ObjectList`) plus `0x00640348` (`LObject`). This is compiler metadata generated from `class ObjectList : public LObject`, not a reason to emit RTTI structures by hand.
- The predecessor interval `[0x0062026c,0x00620284)` is the UTF-16 asset literal `L"DLGEXC3.EPD"`, including its terminator. The historical claim that `0x00620280` is an independent terminal byte `0x44` is rejected; it is part of that wide-string payload. The successor boundary at `0x00620294` remains the next class's COL.
- Constructor store `0x00530f19` and ordinary-destructor restore `0x00531288` write `ObjectList::vftable`; the scalar wrapper is live through slot `0x00620288` even though it has no direct `.text` callers. These routes close liveness without reclassifying compiler-emitted data or the deleting wrapper as handwritten source.
- 2026-06-04 live IDA MCP byte reads confirm alignment padding at `0x0053125d-0x00531260`, `0x0053272e-0x00532730`, `0x0053728e-0x00537290`, and `0x005372c8-0x005372d0`.
- 2026-06-11 live IDA MCP parent-gate refresh reconfirms the same source-root relationship for class-owned vtable children: `lookup_funcs` reports the constructor, ordinary destructor, scalar deleting destructor, static-object sync helper, categorize helper, `ShiftAll`, `DetachAll`, and `FindObjectAt` boundaries unchanged; `py_eval` reads the exact ObjectList RTTI/vtable dwords at `0x00620284-0x00620294`; and `xrefs_to` limits `ObjectList::vftable` stores to the constructor/destructor.
- 2026-06-20 B003 Rule 26 incorporation clarifies that [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) is not a direct by-file-owned hand-authored method. It is class-owned source-declared/generated-binary output for `ObjectList::~ObjectList`, with `ObjectList.cpp` remaining the source-root route. The wrapper has no direct `.text` callers, is referenced by the vtable slot at `0x00620288`, delegates to [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), and emits only a comment marker rather than ABI pseudocode.

## Source-Structure Decision

Use `map/ObjectList.h` plus `map/ObjectList.cpp` as a separate companion module beside `map/MapPane.cpp`. The header owns the complete human-written `ObjectList : public LObject` declaration and the source owns exact child method definitions. Folding the class into `MapPane.cpp` would hide a coherent 68-byte class with constructor, destructor, vtable, and a contiguous helper island. Placing it under `util/` would over-generalize a container whose callers and stored objects are map-world specific.

`MapPaneSpatialIndex` now remains only a documentation compatibility/search alias for older generated output. The source model collapses the early accessor surface back onto `ObjectList`; exact method C++ belongs to [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md).

- UID00023D closes the former provisional static-object lighting-sync entry. The accepted source order is the `ObjectList` declaration in `ObjectList.h`, the class CPP include block, then exact child definitions in address/routing order; the lighting-sync body stays on UID00023D and is not duplicated on this prose-only source-root page.
- The method uses `StaticObjImageLib::GetStaticObjectEntry`, `StaticObjEntry::{lightImageIndex,lightHeightClass}`, `StaticObjectPane::{GetStaticObjectId,InvalidateRect,GetAttachedObject,DetachObject,AttachObject}`, `LightingObjectPane::{LightingObjectPane,SetLightImageIndex}`, `List`, and the external tile-dimension declarations. These dependencies justify the current class CPP include route and dedicated H declarations on the payload classes.
- Historical `RemoveByObjectId`, provisional wrapper-blocked naming, detach/disable slot `+0x20`, and `lightIntensity` wording remain rejected search history. The exact target evidence instead supports `RefreshStaticObjectLighting`, pane invalidation, and signed light-image-table index semantics.

## Assignment Gate

This file clears the parent side of the strict gate at `92/93` for the [UID:00009Q][ObjectList](by-class/ObjectList.md) class. Class-owned children attach to the class first; this prose-only file page routes the complete declaration into `NexusTK/map/ObjectList.h` and exact child definitions into `NexusTK/map/ObjectList.cpp` without emitting duplicate C++. The direct `LObject` RTTI relationship, exact three-slot vtable, lifecycle stores, scalar-wrapper route, and compiler-output exclusions are resolved; unrelated stripped helper names remain outside this narrow score increase.

## Migration Notes

- Keep [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) attached to `ObjectList`; [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) is the exact accessor child that emits formal C++.
- Keep [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) as the exact constructor source-body child under the [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md) aggregate and this `NexusTK/map/ObjectList.cpp` source root. The child now emits formal constructor C++; this file page must not duplicate the body or hand-edit generated output.
- Keep [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) with `ObjectList` as exact `void ObjectList::RefreshStaticObjectLighting(unsigned short staticObjectId)` source. The raw `0x0050e300-0x0050e317` MapPane wrapper remains route-negative support evidence and does not block the accepted ObjectList method name or body.
- Keep [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) with `ObjectList`; its embedded switch tables are compiler output for ObjectList dispatch helpers, not separate source files.
- Keep [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) as `ObjectList::HasValidGridOrigin()` under this source root. The child carries the formal sentinel predicate body; this file page should not duplicate the method body.
- Keep [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) as `ObjectList::AddObjectPane(ObjectPane *object)` under this source root. The child carries the formal method body; this file page should not duplicate the method body.
- Keep [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md) as `ObjectList::RemoveObjectPane(ObjectPane *object)` under this source root. The child carries the formal typed removal-dispatch body; this file page should not duplicate the method body, raw helper island bodies, switch-table data, or security-cookie code.
- Keep [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) as `ObjectList::ResolveObjectListKey(ObjectListKey key)` under this source root. The child carries the formal encoded-key resolver body; this file page does not duplicate it.
- Keep [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) as `ObjectList::GetTypedObjectKey(ObjectPane *object)` under this source root. The child carries the formal value-returning typed-key method body; this file page should not duplicate the method body.
- Keep [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as `ObjectList::FindByObjectId(int objectId)` under this source root. The child carries the formal `ObjectPane *` body over `m_livingObjectRows`, `m_itemObjects`, `m_flyingObjects`, and `ObjectPane::m_objectId`; this file page does not duplicate it.
- Keep [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) as an exact child body under this ObjectList route. The no-inbound-static-route finding is a retained/liveness caveat, not evidence for moving the source to `MapPane`, `ObjectPane`, or a generic helper module.
- Keep [UID:0002BB][0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers](by-memory/0x00535df0-0x00536270.ObjectListTypeSpecificEncodedKeyLookupHelpers.md) as nine specialized private `ObjectList` methods in exact address order. Preserve `ObjectPane *`, pointer-slot dereference, no added checks, type-4/category-2, type-8/category-C, and compiler-cookie/alignment exclusions; do not reintroduce shared static helper bodies or structural names.
- Keep [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) with `ObjectList`; the page includes IDA-modeled functions plus IDA-missed helper starts, direct-route evidence, MapPane/ObjectList ownership separation, internal switch/key-table logic, child emission policy, and retained raw-helper no-code treatment.
- Keep [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md) as an ObjectList-owned child under [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md). Its combined formal C++ stays comment-only because it mixes route-negative raw starts, one live decoder, the decoder table, and padding; do not create the `0x00535ce0-0x00535db8` decoder split without a separate supervisor UID/path.
- Preserve `MapPaneSpatialIndex`, `GetLayer0*`, `GetLayer1*`, and `GetInternalList` only as historical/search aliases. Current documentation does not support promoting them as a separate `map/` source module.
- Preserve [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) as an aggregate source route only. UID0004SI now owns the exact lookup definition; the other three later helpers remain future exact-child splits. This by-file page must not duplicate any method body or turn the aggregate into a handwritten source block.
- After merging ownership, update `MapPane` field naming from mixed `m_pObjectGrid` / `m_pObjectList` / `MapPaneSpatialIndex` wording to one `ObjectList*` field.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md)
- [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md)
- [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md)
- [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md)
- [UID:0000KS][List](by-file/List.md)

## Changes

### 2026-08-11 B003 - UID00023D Source-Root Closure

- Preserved `92/93`, owner `FILE`, and `NexusTK/map/`; this by-file schema still has no reconstructable/emitter/position/Nested/formal metadata fields.
- Replaced the provisional target inventory entry with the exact `ObjectList::RefreshStaticObjectLighting(unsigned short)` source route, behavior, wrapper endpoint, and route-negative liveness caveat.
- Added complete CPP/H dependency and source-order context while preserving exact child-only method-body ownership and all prior ObjectList lifecycle/key/accessor/raw-helper history.

### 2026-07-30 B004 - UID0002OF Vtable/RTTI And Header-Source Closure

- Raised `91/93` to `92/93` after synchronizing the exact `[0x00620284,0x00620294)` bytes and SHA, ObjectList COL/type/CHD/base-descriptor chain, direct `LObject` inheritance, three canonical vtable slots, constructor/destructor vptr stores, and scalar-wrapper liveness. The corrected predecessor is the complete `L"DLGEXC3.EPD"` literal; the historical standalone-`0x44` interpretation at `0x00620280` remains searchable only as a rejected assumption.
- Closed the human-source topology as `map/ObjectList.h` plus `map/ObjectList.cpp`. UID00009Q owns the complete guarded class declaration in H and an include/children CPP root, while exact method children own bodies. UID0002OF, the vtable page, and the scalar wrapper retain covered-by markers or blank channels as applicable; no compiler RTTI/vtable structures or deleting-wrapper ABI pseudocode is handwritten.
- Recorded validator command `000000019926` as the dated pre-callback generated baseline: ObjectList.cpp SHA256 `262B93D950E3D1D2AAEA91D2984FFEE285586C5D75FF17459D66A801D867407A`, `30,650` bytes, `951` lines, complete class still in CPP, and H absent. Generated refresh remains supervisor/validator-owned.
- Preserved the full earlier ObjectList method/storage/source-route history, all child ownership, compiler table/cookie exclusions, and the remaining unrelated raw-helper caveats. The accepted IDA naming/type/comment actions for UID0002OF remain supervisor-owned and are not claimed as applied by this ordinary-document callback.

### 2026-07-15 B003 - Typed Static-Row Lookup Source Route

- Raised `90/92` to `91/93`, retained `NexusTK/map/`, preserved the complete concurrent lifecycle/key/accessor/storage/helper union, and synchronized the complete UID00009Q declaration route plus issued child UID0004SI.
- Closed the static-row lookup source signature, tileX/tileY order, pointer-slot semantics, two-caller inventory, source placement, and child-only body ownership; historical generic `FindObjectAt` remains only in evidence-time records.
- Preserved ShiftAll/DetachAll/Prune as the three remaining future splits and retained compiler table/cookie/vtable/scalar-wrapper exclusions. The by-file page remains prose-only.

### 2026-07-14 B002 - UID0002BB Complete Source-Root Sync

- What changed: raised the file page from `85/88` to `90/92`; added exact `ObjectList.h`/`ObjectList.cpp` dependency placement, complete class/child route, semantic storage/type/key vocabulary, nine-method UID0002BB order, pointer-slot/no-check/key-quirk requirements, and compiler-output exclusions. Current categorize/resolver/find/accessor descriptions now match the synchronized exact children.
- Why: UID0002BB and Destinations 1-13 close the target's signature, field, declaration, source-order, and compile-visibility blockers. This by-file page remains prose-only and carries no reconstruction metadata or duplicate method body; unrelated raw-helper uncertainty and all historical provenance remain intact.

### 2026-07-09 B005 - Destructor Source-Root Sync

- What changed: [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) is now recorded as the formal first-draft `ObjectList::~ObjectList()` source-body child under this `NexusTK/map/ObjectList.cpp` route. The generated-output audit records the pre-callback command `000000008089` state where UID0002JT was still an empty marker and defers generated refresh to scoped validators.
- Why: B005 current MCP session `supervisor_nexustk_20260709` confirmed exact destructor range, sole scalar-wrapper caller, callee set, cleanup order, optional `byte_66DA97` / `g_useEpfAssets` tier gate, helper source shape, and compiler-only vtable/base/scalar-wrapper exclusions. This file page remains the source root and must not duplicate the exact child method body.

### 2026-07-02 B006 - Accessor/Sweep Split-Plan Source-Root Sync

- What changed: the proposed contents and evidence now record [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) at `87/90` with current MCP session `1f24c222` evidence and an accepted future exact-child split plan for `ObjectListShiftAll`, `ObjectListDetachAll`, `ObjectListPruneMarkedRowObjects`, and `ObjectListFindObjectAt`.
- Why: the by-file source root needs to reflect that `ObjectList.cpp` owns these methods, while [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) remains a child-routing aggregate and exact method C++ belongs on future split children rather than this source-root page.

### 2026-07-07 B007 - Constructor Source-Root Sync

- What changed: [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) is now recorded as the formal `ObjectList::ObjectList(int gridWidth, int gridHeight)` source-body child under this `NexusTK/map/ObjectList.cpp` route. The generated-output audit records the pre-implementation empty-marker state and defers generated refresh to the scoped validator.
- Why: B007 current MCP session `43ccf853` confirmed exact constructor range, two MapPane callers, negative endpoint/pointer-route checks, unique signature, row/global allocation formulas, optional alternate-tier gate, and compiler-only unwind/security-cookie exclusions. The earlier empty-emitter deferral is historical because accepted List, MemoryMan, ObjectList layout, and tier-name docs now support formal constructor source on the exact child.

### 2026-07-01 B008 - Empty-Emitter Family Callback

- What changed: added the generated-output audit baseline from `auto-generated/NexusTK/map/ObjectList.cpp` command `000000003224` / refreshed `2026-07-01T03:54:15-04:00`, recorded the pre-callback `23` total / `9` filled / `14` empty / `39.1%` state, clarified the class-owned emitter route through [UID:00009Q][ObjectList](by-class/ObjectList.md), and preserved the rejected owner list.
- What changed: [UID:0002CA][0x00531c10-0x00532180.ObjectListTypeDispatchRemove](by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md) is now documented as the emitted `ObjectList::RemoveObjectPane(ObjectPane *object)` exact child body under this source root; broad class/file/aggregate pages must not duplicate exact child method bodies.
- Why: B008 report acceptance resolved the first real ObjectList empty marker while converting intentional aggregate/type/vtable empty markers into explicit no-code or child-routing markers.

### 2026-06-27 B012 - Accessor Method Source-Root Sync

- What changed: the proposed contents, evidence, migration notes, and cross-references now route [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) as exact ObjectList method C++ under `NexusTK/map/ObjectList.cpp`.
- Why: B012 live MCP proved the former `MapPaneSpatialIndex` alias surface is an ObjectList accessor child. The exact child emits formal C++; the file page remains the source root and does not duplicate method bodies.

### 2026-06-26 B014 - Encoded-Key Island Source-Root Sync

- What changed: the proposed contents, evidence, and migration notes now record that `ObjectList.cpp` owns [UID:0002BA][0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers](by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md), which stays comment-only as a mixed retained raw/live decoder/table/padding child unless a future exact decoder split is assigned.
- Why: B014's accepted report resolved the encoded-key island source-quality blockers while preserving `NexusTK/map/ObjectList.cpp` as the source root and avoiding duplicate file-level method emission.

### 2026-06-26 B009 - FindByObjectId Source-Root Sync

- What changed: the proposed contents, evidence, and migration notes now record that `ObjectList.cpp` owns [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) `ObjectList::FindByObjectId(int objectId)` and that the exact child page carries the formal `ObjectPane *` method body.
- Why: B009's accepted report resolved the object-id lookup source shape while preserving `NexusTK/map/ObjectList.cpp` as the source root and avoiding duplicate file-level method emission.

### 2026-06-26 B006 - GetTypedObjectKey Child Route Sync

- What changed: the ObjectList file inventory/evidence/migration notes now name [UID:0002CC][0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch](by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md) as source-facing `ObjectList::GetTypedObjectKey(ObjectPane *object)` and clarify that the exact child, not the file aggregate, carries the formal C++.
- Why: B006's accepted report proved the body returns the encoded ObjectList key used by MapPane traversal wrappers and belongs in `map/ObjectList.cpp` through the ObjectList class route.

### 2026-06-26 B005 - ResolveObjectListKey Source-Root Sync

- What changed: the proposed contents, evidence, and migration notes now record that `ObjectList.cpp` owns [UID:0002CB][0x00532180-0x005322d0.ObjectListEncodedKeyResolve](by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md) `ObjectList::ResolveObjectListKey(unsigned int key)` and that the exact child page carries the formal method body.
- Why: B005's accepted report resolved the encoded-key-to-object resolver source shape while preserving `NexusTK/map/ObjectList.cpp` as the source root and avoiding duplicate file-level method emission.

### 2026-06-26 B005 - HasValidGridOrigin Source-Root Sync

- What changed: the proposed contents, evidence, and migration notes now record that `ObjectList.cpp` owns [UID:0002C8][0x00531480-0x00531498.ObjectListOriginInitializedCheck](by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md) `ObjectList::HasValidGridOrigin()` and that the exact child page carries the formal method body.
- Why: B005's accepted report resolved the origin sentinel predicate source shape while preserving `NexusTK/map/ObjectList.cpp` as the source root and avoiding duplicate file-level method emission.

### 2026-06-26 B005 - AddObjectPane Source-Root Sync

- What changed: the proposed contents, evidence, and migration notes now record that `ObjectList.cpp` owns [UID:0002C9][0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize](by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md) `ObjectList::AddObjectPane(ObjectPane *object)` and that the exact child page carries the formal method body.
- Why: B005's accepted report resolved the active insertion dispatcher source shape while preserving `NexusTK/map/ObjectList.cpp` as the source root and avoiding duplicate file-level method emission.

### 2026-06-21 - ContainsTypedObject Child Route Sync

- What changed: the ObjectList file inventory/evidence/migration notes now name [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) as source-facing `ObjectList::ContainsTypedObject(ObjectPane *object)` and clarify that the exact child, not the file aggregate, carries the draft C++.
- Why: B006 source-quality work resolved the raw helper as a class-owned retained boolean membership predicate while preserving `NexusTK/map/ObjectList.cpp` as the source route.

### 2026-06-21 - Extended Helper Route And Emission Sync

- What changed: the proposed contents, evidence, and migration notes now carry B010's [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) source-facing helper names, route scan results, ObjectList ownership rejection of alternate owners, and exact-child emission policy.
- Why: the source root needs to reflect that `ObjectList.cpp` owns this helper surface, while the broad physical aggregate stays non-emitting and method-level source belongs on exact child/split pages.

### 2026-06-20 - Scalar Deleting Destructor Route Clarification

- What changed: the lifecycle row and evidence now route [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) through [UID:00009Q][ObjectList](by-class/ObjectList.md) into this `NexusTK/map/ObjectList.cpp` source root.
- Why: B003's Rule 26 report proved the wrapper is a class vtable ABI artifact generated from `ObjectList::~ObjectList`; the by-file page is the source route, not the direct owner/emitter.

### 2026-06-06 - Synced Accessor Alias With ObjectList Ownership

- What existed before: the proposed contents table still split the early accessor surface into list and row-bucket rows under the `MapPaneSpatialIndex` wording, and the file page did not mention the latest child-boundary sync for the categorize aggregate.
- What changed: the table now links the exact categorize aggregate and compatibility alias subset pages, the evidence section records the synchronized child and accessor parent relationship, and migration notes keep `MapPaneSpatialIndex` as a search alias only.
- Why: the current by-memory documentation supports `map/ObjectList.cpp` ownership for both the categorize/lookup aggregate and the `0x00532530-0x0053272e` accessor subset; it does not support a separate original `MapPaneSpatialIndex` source module.

### 2026-05-31 - Added Reconstruction Path And Exact Lifecycle Children

- What existed before: the file page proposed `map/ObjectList.cpp` in prose but left the validator-managed reconstruction path blank, and lifecycle was represented primarily by the aggregate page.
- What changed: `PROPOSED_RECONSTRUCTION_PATH` now stages `NexusTK/map/ObjectList.cpp`, and the proposed contents table links the exact constructor/destructor child pages.
- Why: the proposed-source tree already places ObjectList under the map subsystem, and IDA MCP confirms exact lifecycle child ranges plus constructor callers from `MapPane` map-change/effect-packet paths.

### 2026-05-28 - Added Discontiguous ObjectList Helper Ownership

- What existed before: `ObjectList.cpp` ownership started at the lifecycle range `0x00530ee0-0x00531472`, with the earlier `0x00530d00-0x00530ed9` helper left out of the file-level inventory.
- What changed: `0x00530d00-0x00530ed9` is now tracked as an `ObjectList` helper candidate in `map/ObjectList.cpp`.
- Why: IDA MCP decompile shows a `__thiscall` helper walking ObjectList row/global fields by object id and calling into the later ObjectList helper surface.

### 2026-05-30 - Refined Discontiguous Helper Purpose

- What existed before: the file inventory described `0x00530d00-0x00530ed9` as a remove-by-id helper.
- What changed: the file inventory now describes it as a static-object lighting sync helper, with final method name still provisional.
- Why: IDA MCP decompilation shows the helper looks up static-object metadata and removes, updates, or creates attached `LightingObjectPane` companions for matching static object panes.

### 2026-05-28 - Added ObjectList Categorize/Lookup Helper Cluster

- What existed before: the `0x00531472-0x00532530` span was an unknown gap between ObjectList lifecycle and accessor docs.
- What changed: the lifecycle endpoint was corrected to `0x00531473`, and `0x00531480-0x00532530` is now tracked as an `ObjectList` helper cluster.
- Why: IDA MCP reports real helper functions at `0x00531480`, `0x005314a0`, `0x00531c10`, `0x00532180`, `0x005322d0`, and `0x00532370`, plus an undecorated switch helper at `0x00532450`; all dispatch on ObjectList/object-pane data.

### 2026-05-30 - Split Categorize/Lookup Helper Cluster

- What existed before: the file page referenced `0x00531480-0x00532530` as one broad ObjectList helper cluster.
- What changed: [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) now nests child by-memory pages for each method-level helper and switch-table-backed dispatch unit.
- Why: IDA MCP revalidated the modeled function boundaries and the raw `0x00532450` switch helper; keeping these nested under the aggregate preserves `map/ObjectList.cpp` ownership while making method-level reconstruction work traceable.

### 2026-06-01 - Accessor Island Parent Confirmed

- What changed: [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and the early accessor subset now known as [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) were explicitly attached to this file page.
- Why: IDA MCP confirmed the accessor/sweep island uses the same ObjectList fields initialized by the lifecycle code and that `0x0053272e-0x00532730` is alignment before the next ObjectList helper.

### 2026-05-28 - Added Extended Type Lookup Helper Family

- What existed before: `0x00532f67-0x00537290` was an unknown gap between ObjectList accessors and the scalar deleting destructor.
- What changed: `0x00532f67-0x00532f70` and `0x0053728e-0x00537290` are now padding, and `0x00532f70-0x0053728e` is documented as ObjectList extended type lookup/helper code.
- Why: IDA MCP enumerates modeled functions throughout the span and manual disassembly shows additional IDA-missed helper prologues; the helpers use ObjectList fields, encoded object keys, and type-specific list lookup/removal paths.

### 2026-05-28 - Corrected Scalar Destructor Endpoint

- What existed before: the scalar deleting destructor range was listed as `0x00537290-0x005372c7`.
- What changed: the endpoint is now `0x005372c8`.
- Why: IDA MCP function review reports the wrapper ending at exclusive address `0x005372c8`; the following `0x005372c8-0x005372d0` bytes are padding.

### 2026-06-04 - Live IDA Consolidation And Score Update

- What existed before: the page carried `74/84`, stale active-output/source-split wording, and older evidence that did not include the current vtable/padding/caller snapshot.
- What changed: scores are now `84/88`, proposed module/header names use the `NexusTK/map/` path, importer-derived ownership wording was replaced with IDA evidence/source-facing caveats, and the evidence section records current function boundaries, raw-start caveats, caller sets, vtable dwords, and padding ranges.
- Why: live IDA MCP confirms the ObjectList lifecycle, vtable, layout, map-only caller surface, and helper-island boundaries strongly enough to move this out of the low-score queue. Completion/confidence remain below final reconstruction levels because several helper names are still provisional and the extended helper family includes raw starts that IDA does not model as functions.

### 2026-06-11 - Parent-Gate Refresh For Class Children

- What existed before: the file page was the right source root but sat at `84/88`, which kept the ObjectList class/source chain below the strict parent gate for new vtable assignments.
- What changed: completion is now `85`, and the evidence/source-structure sections explicitly record that class-owned vtable children route through [UID:00009Q][ObjectList](by-class/ObjectList.md) into this file.
- Why: live IDA MCP reconfirmed the lifecycle/helper boundaries, vptr stores, exact ObjectList vtable data, and neighboring `ObjectPane` RTTI boundary; unresolved public helper names remain below final C++ quality but no longer block parent-side source-root confidence for narrow ObjectList class children.
