*** UID:00009R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ObjectPaneType
{
    kObjectPaneTypeItem = 0,
    kObjectPaneTypeFlying = 1,
    kObjectPaneTypePrimaryEffect = 2,
    kObjectPaneTypeLiving = 3,
    kObjectPaneTypeSecondaryEffect = 4,
    kObjectPaneTypeStatic = 5,
    kObjectPaneTypeBalloon = 6,
    kObjectPaneTypeHitBar = 7,
    kObjectPaneTypeDamageNumber = 8,
    kObjectPaneTypeObjectInfo = 9,
    kObjectPaneTypeLighting = 10,
    kObjectPaneTypeSound = 11
};

class MapPane;
class ObjectList;
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
    friend class MapPane;
    friend class ObjectList;

public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    unsigned char GetObjectType() const
    {
        return m_objectType;
    }
    int GetObjectId() const
    {
        return m_objectId;
    }
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(
        const RectBounds *paneBounds,
        const RectBounds *objectDataBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, byte m_objectType ABI, public inline GetObjectType/GetObjectId accessors, ObjectList and MapPane friendship, exact id/map/bounds/attachment/sound/transient layout, semantic paneBounds/objectDataBounds virtual contracts, source-ready ClearOutputRects default, methods/default virtuals, implicit padding, and compiler vtable coverage. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectPane

## UID0003HT Pane And Object-Data Bounds Contract - 2026-07-16

- The complete declaration remains `92/94`, owner/emitter [UID:0000M5][ObjectPane](by-file/ObjectPane.md), source position `10`, exact size `0x128`, and preserves every current enum, friend, accessor, field, virtual, default body, child insertion, and compiler exclusion.
- `SetBounds(const RectBounds *paneBounds, const RectBounds *objectDataBounds)` and `ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds)` use the two binary-proven output roles. Historical `bounds/clipBounds`, `firstBounds/secondBounds`, and clip/dirty interpretations are superseded.
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) is the source-ready base default. It clears both caller outputs with two exact `InitRectBounds(..., 0, 0, 0, 0)` calls, has ObjectPane-family vtable reachability and no ordinary caller, and does not read `this`.
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) is the source-ready base `ComputeRenderBounds` default. Its exact 37-byte body clears a caller-owned `RectBounds` in bottom/top/right/left store order and returns the same pointer. Twelve non-Living primary ObjectPane-family vtables inherit it at `+0x60`; [UID:0003NW][0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds](by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md) overrides that slot with actual sprite-bound computation, and [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md) consumes the result for exposed-region clipping. The earlier `GetEmptyRect` name described only the base all-zero behavior and is historical.
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) is the source-ready primary `+0x0c` `UpdateRenderRegion` override and copies its 16-byte argument into inherited `GrafPort::m_visibleBounds`. [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) is the source-ready primary `+0x2c` `SetBounds` override: it compares `GetScreenBounds` output with `paneBounds`, updates inherited `Point m_origin` and localized `m_visibleBounds` only on change, then forwards a local copy of optional `objectDataBounds` or the pane fallback to `SetObjectData`. [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) overrides the same output contract for item glyph geometry.
- No new layout byte, vtable slot, wrapper, raw ABI mechanic, or duplicate source body is introduced.

## UID0003XX Bounds Virtual Source Integration - 2026-07-16

- The managed class block remains byte-for-byte unchanged. It already declares source-facing `UpdateRenderRegion(const RectBounds *)` followed by `SetBounds(const RectBounds *paneBounds, const RectBounds *objectDataBounds)` in the correct primary-slot order.
- UID0003XW's physical `ObjectPaneSetBounds` title and UID0003XX's physical `ObjectPaneUpdateBounds` title remain stable historical/search vocabulary. Vtable comparison supplies the current source identities and no physical rename is required.
- UID0003XW is exactly 17 bytes and performs one inherited `m_visibleBounds` assignment. UID0003XX is exactly 146 bytes and performs `GetScreenBounds`, `RectsEquivalent`, conditional `m_origin`/`m_visibleBounds` update, optional object-data fallback selection, and `SetObjectData`.
- The inherited source expressions are declaration-complete through Pane/GrafPort support: `m_visibleBounds` is the 16-byte RectBounds at `+0x44`; `Point m_origin` stores `y` at `+0xac` and `x` at `+0xb0`.
- The target update order is exact: compare current screen bounds, initialize origin from top/Y and left/X, copy pane bounds, offset the inherited local rectangle by negative left/top, then select a local object-data value and dispatch `SetObjectData`.
- Fourteen ObjectPane-family primary vtables inherit UID0003XX. MapPane UID0004DS supplies both bounds outputs and reaches slot `+0x2c` from a helper with 44 direct code callers.
- Historical direct-visible-bounds comparison, generic `UpdateBounds`, and clip/dirty interpretations are superseded. Security-cookie code, SIMD copies, vtable loads, thunk mechanics, and incidental EAX values remain compiler lowering.

## UID0003Z4 Typed Unregister Support - 2026-07-14

- The public inline `GetObjectType()` accessor is the source-legal route used by [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md). It exposes the already-established byte field without changing object size, layout, vtable shape, or emitting a separate body.
- Exact type values 2, 4, 6, 7, 8, and 9 select primary effect, secondary effect, Balloon, HitBar, DamageNumber, and ObjectInfo unregister behavior. Existing MapPane/ObjectList friendship and all unrelated declaration content remain unchanged.
- Direct protected-field access from unrelated code and an invented free type getter are rejected. The inline member accessor is the smallest compilable source integration matching the binary field read.

## Status

- Confidence: very strong for base-class role, exact child-method split, complete object-type taxonomy, ObjectList direct-access contract, source-facing object-id accessor, field-name directions, vtable families, and source placement.
- Source file: [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- Evidence basis: live IDA MCP confirms the core method boundaries, constructor/destructor subclass reachability, scattered rect-helper vtable slots, object-data/position virtual slots, and exact base `ObjectPane` vtable-data child.
- Rebuild handling: source-authored complete abstract class declaration. Exact child pages own ordinary method bodies; the class formal owns the `0x128` layout, declarations, concrete empty render defaults, and child insertion. Compiler vtables, adjusted facets, and deleting wrappers are not handwritten.

## Class Purpose

`ObjectPane` is the base class for renderable game-world objects. It layers object-specific state on top of the exact `0xf8`-byte `Pane`: object type, object id, map coordinates, the 16-byte object-data rectangle, attached-object state, a typed owned `SoundObjectPane` link, and a transient flag. The complete object size is exactly `0x128` bytes.

Classes such as [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), item object panes, and object-info/overlay panes build on this base. `ObjectPane` should be treated as map-object infrastructure rather than generic UI control code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClearOutputRects` | [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) | Source-ready virtual base default that clears `paneBounds` and `objectDataBounds`. |
| `ComputeRenderBounds` | [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) | Non-const primary-slot `+0x60` virtual. The base clears and returns the caller `RectBounds`; LivingObjectPane overrides the same slot with actual sprite bounds. |
| constructor | [UID:0003XN][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md) | Constructs `Pane`, installs `ObjectPane` vtables, initializes object type/id, map coordinates, object-data rect, attachment state, owned image state, and empty bounds. |
| destructor | [UID:0003XO][0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor](by-memory/0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor.md) | Resets vtables, releases attached object/owned image state, and calls `Pane` cleanup. |
| `GetMapPosition` | [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) | Copies map coordinate fields from `+0x100/+0x104` into caller output. |
| inline `GetObjectId` | header-only accessor | Returns exact `m_objectId` at `+0xfc`; gives non-friend consumers such as SelfLookPane2 packet-update methods source-facing access without raw offsets/casts. ObjectList keeps its established friend/direct-field contract. |
| `AttachObject` | [UID:0003XQ][0x005374f0-0x005375e1.ObjectPaneAttachObject](by-memory/0x005374f0-0x005375e1.ObjectPaneAttachObject.md) | Replaces current attached object, updates payload/height, dispatches map payload when active, and refreshes bounds. |
| `DetachObject` | [UID:0003XR][0x005375f0-0x005376b5.ObjectPaneDetachObject](by-memory/0x005375f0-0x005376b5.ObjectPaneDetachObject.md) | Removes attached object payload and clears attachment pointer. |
| `GetAttachedObject` | [UID:0003XS][0x005376c0-0x005376c7.ObjectPaneGetAttachedObject](by-memory/0x005376c0-0x005376c7.ObjectPaneGetAttachedObject.md) | Returns the attached object pointer at `+0x118`. |
| `SetSoundObjectPane` | [UID:0003XT][0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane](by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md) | Deletes the previous typed `SoundObjectPane` at `+0x120`, then stores the new pointer. Both callers install newly constructed SoundObjectPane objects. |
| `ClearSoundObjectPane` | [UID:0003XU][0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw](by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md) | Conditionally clears `+0x120` without release. No direct xref survives, but the exact operation is inlined by SoundObjectPane ordinary/scalar destruction. |
| `InvalidateObjectDataRect` | [UID:0003XV][0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect](by-memory/0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect.md) | Forwards the `+0x108` object-data rect to active MapPane invalidation. |
| `UpdateRenderRegion` | [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) | Source-ready primary `+0x0c` override; stores the 16-byte rectangle in inherited `GrafPort::m_visibleBounds`. Physical SetBounds slug is historical/search vocabulary. |
| `SetBounds` | [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) | Source-ready primary `+0x2c` override; compares current screen bounds, conditionally updates inherited origin/local visible bounds, then sends optional `objectDataBounds` or the `paneBounds` fallback to `SetObjectData`. Physical UpdateBounds slug is historical/search vocabulary. |
| `SetObjectData` | [UID:0003XY][0x00537800-0x0053787a.ObjectPaneSetObjectData](by-memory/0x00537800-0x0053787a.ObjectPaneSetObjectData.md) | Copies a 16-byte object-data rect and invalidates/recomputes attached state when the linked object changes. |
| `GetObjectData` | [UID:0003XZ][0x00537880-0x00537894.ObjectPaneGetObjectData](by-memory/0x00537880-0x00537894.ObjectPaneGetObjectData.md) | Copies the packed 16-byte object-data rect out. |
| `SetMapPosition` | [UID:0003Y0][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md) | Moves the object through active MapPane position update and refreshes bounds before/after the coordinate update. |

## Field Directions

| Offset | Best current name | Notes |
| --- | --- | --- |
| `+0xf8` | `m_objectType` / `ObjectPaneType` | One-byte object-type discriminator. Exact values `0..11` map to Item, Flying, PrimaryEffect, Living, SecondaryEffect, Static, Balloon, HitBar, DamageNumber, ObjectInfo, Lighting, and Sound. The source field remains `unsigned char`; the unscoped enum supplies source constants without changing the byte ABI. |
| `+0xfc` | `m_objectId` / `m_objectSerial` | `m_objectId` is the primary current source-facing name. [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) compares this field in `ObjectList::FindByObjectId(int objectId)`; `m_objectSerial` remains an alias/caveat and stale base `spriteIndex` wording is rejected. |
| `+0x100/+0x104` | `m_mapX` / `m_mapY` | Stored map coordinates used by get/set map-position helpers. |
| `+0x108` | `m_objectDataRect` / `m_objectData` | 16-byte rect-like record used by invalidation and object-data accessors. |
| `+0x118` | `m_attachedObject` | Attached ObjectPane pointer. |
| `+0x11c` | `m_attachmentHeightOffset` | Height/attachment offset updated from attachment descriptor data. |
| `+0x120` | `m_soundObjectPane` | Typed owned `SoundObjectPane *`. `SetSoundObjectPane` virtually deletes/replaces it; `ClearSoundObjectPane` only nulls it; a linked SoundObjectPane destructor clears this owner field. Historical `m_ownedObjectImageState` / `m_auxiliaryImageState` wording is superseded. |
| `+0x124` | `m_transientObjectFlag` | Cleared by constructor/local-object refresh; final semantic name remains open. |

## Complete Declaration And Layout Evidence

- The base [UID:0000A2][Pane](by-class/Pane.md) and [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) establish exact size `0xf8`, including inherited EventHandler and TimerHandler views at complete-object offsets `+0xa0` and `+0xa4`.
- ObjectPane extends that base with `m_objectType` at `+0xf8`, compiler alignment to `m_objectId` at `+0xfc`, map coordinates at `+0x100/+0x104`, `RectBounds m_objectDataRect` at `+0x108`, `m_attachedObject` at `+0x118`, `m_attachmentHeightOffset` at `+0x11c`, typed `m_soundObjectPane` at `+0x120`, and `m_transientObjectFlag` at `+0x124`. Three implicit tail-padding bytes produce exact end `+0x128`; no explicit reserve field is source-authored.
- Constructor `0x005372d0-0x00537395` writes every declared extension field. Thirteen derived constructors call it, and fourteen family/wrapper/EH paths call the ordinary destructor at `0x005373a0-0x005374cb`.
- [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md) proves a 27-cell primary view, 11-cell EventHandler view, and two-cell TimerHandler view. Their first cells are `__purecall`, matching `virtual ~ObjectPane() = 0;` plus UID0003XO's required out-of-line ordinary destructor body.
- Primary slots `+0x5c` and `+0x64` both target `nullsub_18` (`retn 8`). They are concrete empty two-argument `RenderFrame` and `DrawSpriteFrame` defaults, not pure cells. Static, Item/Flying, Effect, hit-bar, damage-number, ObjectInfo, and Living derived vtables selectively override the same signatures; directly constructed LightingObjectPane and SoundObjectPane inherit both defaults and remain concrete.
- Source-facing override declarations map current method children to the vtable contract: `UpdateRenderRegion` (`0x00537740`), `InvalidateRect` (`0x00537720`), semantic `SetBounds(paneBounds, objectDataBounds)` (`0x00537760`), `AttachObject`, `DetachObject`, source-ready `ClearOutputRects(paneBounds, objectDataBounds)`, `SetObjectData`, `GetObjectData`, non-const `ComputeRenderBounds`, and `SetMapPosition`. Existing child slugs remain historical/search vocabulary where their recovered titles differ.
- The two bounds definitions now match those declarations exactly. UID0003XW assigns inherited `m_visibleBounds`; UID0003XX uses inherited `GetScreenBounds`, `Point m_origin` in Y/X order, `m_visibleBounds.Offset`, `RectsEquivalent`, and `SetObjectData`. No class field, accessor, slot, declaration, or layout change is required.
- Header/source placement is source-safe: `ObjectPane.h` includes Pane/RectBounds dependencies, defines `ObjectPaneType`, and forward-declares `ObjectList`, `GrafPort`, `SoundObjectPane`, and `MapPoint`; `ObjectPane.cpp` includes `ObjectPane.h` and then the complete `SoundObjectPane.h` before compiling the deleting setter. The `friend class ObjectList;` declaration continues to permit binary-proven direct `m_objectType` and `m_objectId` loads in ObjectList methods. The small inline `GetObjectId()` separately supports non-friend source consumers such as UID0004Q0/UID0004Q1 and changes neither layout nor ObjectList's direct-access behavior. The clear method needs only the SoundObjectPane forward declaration.
- Negative/compiler boundary: do not hand-author vptr stores, RTTI/vtable arrays, adjusted facets, `__purecall` cells, scalar deleting wrappers, delete flags, or explicit alignment arrays. Those are regenerated by the complete class declaration and ordinary child bodies.

## Object Id Accessor Contract

- The accessor is exact source-facing support: `int GetObjectId() const { return m_objectId; }`. It reads the proven signed 32-bit `+0xfc` field and emits inline in the class declaration, so no new standalone function/page or ABI slot is claimed.
- [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) and [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) compare packet object ids with `g_pUserPane->GetObjectId()`, matching the raw `dword_67A748+0xfc` load while avoiding decompiler-shaped global/offset syntax.
- Existing project source repeatedly uses `GetObjectId()` vocabulary. The accepted accessor is more plausible than casting UserPane, exposing `m_objectId`, adding SelfLookPane2 friendship, or retaining stale `g_pCollectionData->m_selectedObjectKey` identity.
- This addition does not replace `friend class ObjectList`; ObjectList's binary-proven direct reads of `m_objectType` and `m_objectId` remain represented by friendship. No support score, layout field, virtual slot, or child body changes.

Accepted `ObjectPaneType` values from direct constructor producers and ObjectList/MapPane consumers:

| Value | Source-facing enum direction | Evidence |
| --- | --- | --- |
| `0` | `Item` | `ItemObjectPane` constructor `0x00537b40` passes `0`; item update paths test the same value. |
| `1` | `Flying` | `FlyingObjectPane` constructor `0x00537cb0` performs the base call and then stores byte `1` at `+0xf8`. |
| `2` | `PrimaryEffect` | `EffectObjectPane` constructor `0x005387b0` computes type `2` when its sequence selector is `1`; ObjectList uses primary effect rows at `+0x1c`. |
| `3` | `Living` | `LivingObjectPane` constructors `0x0053a110`/`0x0053a360` pass `3`; MapPane teardown applies LivingObjectPane cleanup to the same value. |
| `4` | `SecondaryEffect` | `EffectObjectPane` constructor computes type `4` when the sequence selector is not `1`; ObjectList uses secondary effect rows at `+0x20`. |
| `5` | `Static` | `StaticObjectPane` constructor `0x00537900` passes `5`; ObjectList uses extended static rows at `+0x28`. |
| `6` | `Balloon` | Balloon construction at `0x004682c0` passes `6` through `AttachedObjectPane` constructor `0x005380b0` before installing Balloon vtables. |
| `7` | `HitBar` | HitBarObjectPane constructors `0x00538d50`/`0x00538dc0` pass `7`. |
| `8` | `DamageNumber` | DamageNumberObjectPane constructor `0x00539230` passes `8`; ObjectList stores the family at optional `+0x34`. |
| `9` | `ObjectInfo` | ObjectInfoObjectPane constructor `0x005395b0` passes `9`. |
| `10` | `Lighting` | LightingObjectPane constructor `0x0053c5e0` passes `10`. |
| `11` | `Sound` | SoundObjectPane constructor `0x0053ca20` passes `11`. |

## Evidence Notes

- B001 2026-06-17 split reanalysis confirms all exact child starts and ranges, including missed bodies at `0x005374d0`, `0x005376c0`, `0x005376d0`, and raw no-route body `0x00537700-0x00537714`, plus the two scattered rect-helper virtuals at `0x00469050` and `0x00469080`.
- B002 2026-06-18 MapPane teardown/object-packet pass resolves object-type values used by MapPane cleanup and object update paths: `0` item/ground item, `1` flying item/object, `3` living, and `5` static. Keep these as current high-probability enum directions until all constructors and packet producers are audited.
- B009 2026-06-26 ObjectList id-lookup sync resolves [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as `ObjectList::FindByObjectId(int objectId)`, returning `ObjectPane *` and comparing `ObjectPane::m_objectId` at `+0xfc`. Keep `m_objectSerial` as a searchable alias/caveat, not the primary field or method vocabulary.
- B006 2026-06-21 ObjectList predicate sync uses this field direction explicitly: [UID:0002CE][0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper](by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md) reads only `m_objectType` at `+0xf8` when dispatching `ObjectList::ContainsTypedObject(ObjectPane *object)`. It does not read `m_objectId` / `m_objectSerial` at `+0xfc`, so ObjectList id/serial lookup remains with [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md).
- B002 2026-07-14 UID0002BB callback closes the former four-value enum caveat with all 13 direct ObjectPane-constructor family callers. It also adds the binary-neutral ObjectList friendship required because accepted ObjectList dispatch and id lookup methods directly load protected `m_objectType` and `m_objectId`; a getter-based alternative is rejected because no such calls occur in the binary.
- The constructor has subclass construction callers across the static, item/flying, attached, effect, living, lighting, and sound object-pane families; the destructor is reached from the corresponding wrapper/destructor paths.
- `SetObjectData` at `0x00537800-0x0053787a` is a real executable virtual-slot body: it invalidates before and after updating the 16-byte object-data block and conditionally recomputes attached-state geometry.
- `GetObjectData` and `SetPosition` are vtable-referenced across the ObjectPane family; `SetPosition` updates the stored map coordinates only when they change.
- 2026-06-11 A003 Batch 220 live IDA MCP reconfirmed the exact base vtable data [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md): RTTI pointer at `0x00620294`, primary/adjusted vtable bases at `0x00620298`, `0x00620308`, and `0x00620338`, constructor vptr stores at `0x0053733a`, `0x00537340`, and `0x0053734a`, destructor vptr restores at `0x005373d2`, `0x005373d8`, and `0x005373e2`, and the `0x00620340` `StaticObjectPane` RTTI successor boundary.

## Cross-References

- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md)
- [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md)
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)

## UID00037X MapPane Access Synchronization

- The complete formal preserves the current inline `GetObjectId() const`, ObjectList friendship, all virtual/member declarations, exact fields, and `[[CHILDREN]]`, while adding the accepted `class MapPane;` forward declaration and `friend class MapPane;` only.
- UID0004Q8 directly reads `m_objectType` to select LivingObjectPane interpolation. UID0004QC directly reads `m_objectId` while collecting directional/adjacent movement targets. Those binary field loads contain no accessor calls, so friendship is the source-faithful access representation.
- The existing public inline `GetObjectId()` remains necessary for non-friend consumers and is not replaced by friendship. ObjectList's established direct-field contract also remains unchanged.
- MapPane friendship does not transfer ownership, expose fields publicly, add layout bytes, change vtable slots, or justify new ObjectPane methods. Exact child definitions remain under MapPane.
- Scores, owner/emitter, position, route, layout, and unrelated ObjectPane evidence remain unchanged.

## Changes

- 2026-07-25 B004 UID00020S source-channel and virtual-contract callback:
  - Moved the complete ObjectPane enum/forward-declaration/class block byte-for-text from `RECONSTRUCTION_CPP` to `RECONSTRUCTION_H`, preserving every declaration, friend, inline body, field, and `[[CHILDREN]]` exactly once; class CPP is now blank.
  - Replaced only the stale `virtual RectBounds *GetEmptyRect(RectBounds *outBounds) const;` slot with non-const `virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);`, matching the established LivingObjectPane override.
  - Added the exact UID00020S base-default, twelve inherited primary-slot cells, Living same-slot override, and MapPane clipping-consumer evidence while retaining `92/94`, owner/emitter UID0000M5, and position 10.

- 2026-07-16 Agent-B005 UID0003XX accepted callback:
  - Preserved `92/94`, owner/emitter UID0000M5, position `10`, exact `0x128` layout, complete enum/friend/accessor/field/method/default/`[[CHILDREN]]` declaration, and all concurrent ObjectPane evidence.
  - Corrected the method inventory and prose so UID0003XW is `UpdateRenderRegion` and UID0003XX is `SetBounds`, while preserving both physical slugs as historical/search vocabulary.
  - Added exact target comparison/update/fallback order, inherited `Point m_origin` and `GrafPort::m_visibleBounds` expressions, vtable/runtime caller liveness, source/compiler boundary, and superseded-name history.
  - The managed class block was not changed.
- 2026-07-16 Agent-B005 UID0003HT callback:
  - Preserved `92/94`, owner/emitter, position, complete enum/layout/friend/accessor/method/default/children declaration, and all concurrent ObjectPane evidence.
  - Applied the exact `paneBounds` / `objectDataBounds` parameter contract to `SetBounds` and `ClearOutputRects`, linked source-ready UID00020R, and historicalized clip/dirty and ordinal-output terminology.
  - Added no layout, vtable, compiler-wrapper, or handwritten ABI mechanics.
- 2026-07-14 Agent-B005 UID00037X callback: rebased the complete class declaration with MapPane forward/friend access while preserving the inline object-id accessor and every concurrent declaration/field.

- 2026-07-14 Agent-B004 UID00039M support callback:
  - Preserved `92/94`, owner/emitter UID0000M5, position `10`, exact `0x128` layout, ObjectPaneType, ObjectList friendship/direct access, all methods/default virtuals, child ordering, and compiler exclusions.
  - Added exact inline `int GetObjectId() const { return m_objectId; }` for non-friend SelfLookPane2 packet-update consumers and documented the raw `g_pUserPane+0xfc` equivalence. This bounded accessor does not supersede ObjectList's friend/direct-field behavior; older rejection applied to replacing that direct container contract, not to this later evidenced external consumer surface.

- 2026-07-14 B002 UID0002BB callback:
  - Retained `92/94`, source position `10`, owner/emitter, exact `0x128` layout, and all UID0001DJ declaration/body evidence.
  - Added the exact unscoped `ObjectPaneType` values `0..11`, preserving `unsigned char m_objectType` at `+0xf8`, plus `class ObjectList;` and `friend class ObjectList;` for source-safe direct type/id access.
  - Recorded the complete constructor-producer matrix, ObjectList field-family consumers, header placement, rejected getter alternative, and the historical status of the former partial `0/1/3/5` taxonomy.

- 2026-07-14 B002 UID0001DJ callback:
  - Raised `87/90 -> 92/94`, set source position `10`, and replaced the blank emitter with the complete source-safe `ObjectPane` declaration.
  - Retyped `+0x120` from the superseded generic owned-image alias to `SoundObjectPane *m_soundObjectPane`; declared the exact typed replace/delete and no-release clear methods proven by two construction-flow callers and SoundObjectPane destructor inlining.
  - Recorded the exact `Pane[0xf8] -> ObjectPane[0x128]` layout, implicit alignment, pure ordinary-destructor contract, concrete empty `RenderFrame`/`DrawSpriteFrame` defaults, three-view compiler vtable disposition, complete-type include order, and compiler-only exclusions. Existing method/body evidence and historical aliases remain preserved.

- 2026-06-26 B009 ObjectList id-lookup support sync:
  - Updated `+0xfc` wording so `m_objectId` is primary for [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md), with `m_objectSerial` preserved as an alias/caveat.

- 2026-06-21 B006 ObjectList predicate support sync:
  - Added the cross-reference fact that `ObjectList::ContainsTypedObject(ObjectPane *object)` consumes only `m_objectType` at `+0xf8` and explicitly is not an `m_objectId` / `m_objectSerial` lookup.

- 2026-06-18 B002 MapPane teardown/object-packet sync:
  - Added current `ObjectPaneType` value directions from MapPane object removal/detach evidence and constructor/path cross-checks: `0` item/ground item, `1` flying item/object, `3` living, and `5` static.
- 2026-06-17 B001 source-quality split sync:
  - What existed before: the class page was `85/88`, listed the old aggregate anchors, and still described base fields with stale sprite/frame/palette wording.
  - Changed to: `87/90`, added exact child pages [UID:0003XN][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md) through [UID:0003Y0][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md), documented what was then called the raw no-route helper [UID:0003XU][0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw](by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md), and changed base field direction to object type/id, map coordinates, object-data rect, attachment, and owned auxiliary image state. The old helper/type description is historical and was superseded by the 2026-07-14 typed SoundObjectPane repair above.
  - Evidence: B001 live review confirmed the expanded function inventory, padding, scattered virtual helper relationship, ObjectPane source placement, rejected aggregate emission, and field/type inferences.

- 2026-06-11 A003 Batch 220 parent-gate repair:
  - What existed before: the class page was `84/86`, which blocked exact vtable child [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md) under the strict child/direct-parent `85/85` gate even though the owning file page already cleared the gate.
  - What changed: raised to `85/88`, retained [UID:0000M5][ObjectPane](by-file/ObjectPane.md) as direct file parent, and added the exact `ObjectPane` vtable-data evidence needed to support child assignment.
  - Summary/evidence: live IDA MCP reconfirmed all three base `ObjectPane` vtable views, constructor/destructor vptr-store refs, and the `0x00620340` successor boundary while existing method-range and source-file evidence remained valid.

- 2026-06-06 A002 autogen parent sync:
  - What existed before: the class page identified [UID:0000M5][ObjectPane](by-file/ObjectPane.md) as the likely source file, but `AUTOGEN_PARENT_UID` was blank, leaving child memory pages attached to an unassigned parent in generated coverage.
  - What changed: set `AUTOGEN_PARENT_UID:0000M5` and promoted the status wording from likely source file to source file.
  - Summary/evidence: the file page already has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, this class is `84/86`, the file page is `88/86`, and all three ObjectPane memory children are above the 80/80 attachment gate; final C++ remains blank under the 95/95 gate.

- 2026-06-05 live IDA refresh:
  - What existed before: the page mixed source-facing ObjectPane notes with stale recovery-output status and a lower confidence cap.
  - What changed: raised completion/confidence to `84/86`, removed stale recovery-output references, and added live IDA evidence for method boundaries, subclass caller families, and the object-data/position virtual slots.
  - Summary/evidence: live IDA confirms the ObjectPane core range, scattered rect helpers, constructor/destructor reachability, and vtable/data references for the object-data and position methods.

- Before: completion/confidence metadata were `0/0` even though the page already covered base-class purpose, object state, and method anchors.
- Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
- Evidence: the page documents constructor/destructor, attach/detach, bounds, object-data, position, helper virtuals, and derived-class relationships; confidence remains below final because several field and slot names are still provisional.
- 2026-06-02 reconstructable marker update:
  - What existed before: the class page described a reconstructable ObjectPane base class but left `RECONSTRUCTABLE` blank.
  - What it was changed to: marked `RECONSTRUCTABLE:TRUE` while keeping the C++ block blank.
  - Summary/evidence: ObjectPane owns confirmed constructor/destructor, attach/detach, bounds, object-data, position, and virtual rect helper methods; final class declaration/body shape still waits on layout and virtual-slot naming.

## UID0003U6 MapPoint Accessor Support - 2026-07-15

- Existing `92/94` metadata, UID0000M5 route, complete ObjectPane declaration, field layout, virtuals, friendship, `[[CHILDREN]]`, and unrelated history remain unchanged.
- The existing `struct MapPoint;` forward declaration and `MapPoint *GetMapPosition(MapPoint *outPosition) const;` member now resolve to [UID:0004R0][MapPoint](by-type/by-struct/MapPoint.md), exact eight-byte row/column layout emitted through MapPane.cpp.
- [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) is the exact emitting child at `92/94`: it writes `m_mapY` to `row`, `m_mapX` to `column`, returns the output pointer, and introduces no guard or state mutation.
- [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md) and retained UserPane packet helpers consume this inherited accessor. The bounded synchronization does not move the method to UserPane/LivingObjectPane or alter ObjectPane size, access, scores, or formal class body.
