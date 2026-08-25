*** UID:0000M5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ObjectPane

## UID0003HT Pane And Object-Data Bounds Integration - 2026-07-16

- This file remains `91/92` at `NexusTK/map/`, with the complete current ObjectPane class/source union, exact `0x128` layout, enum, friendships, accessors, SoundObjectPane lifecycle, method children, and compiler exclusions preserved.
- The source-facing virtual contract is `SetBounds(const RectBounds *paneBounds, const RectBounds *objectDataBounds)` and `ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds)`. Historical clip/dirty and ordinal-output names are superseded by the binary-proven pane/object-data roles.
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) is now a source-ready base default with two exact `InitRectBounds(..., 0, 0, 0, 0)` calls. It remains vtable-only, reads no `this`, and introduces no handwritten ABI/vtable mechanics.
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) is now the source-ready base `ObjectPane::ComputeRenderBounds` default. Its exact body clears and returns a caller-owned `RectBounds`; twelve non-Living primary ObjectPane-family tables inherit the method at `+0x60`, while LivingObjectPane overrides that same slot at `0x0053bdc0` with actual sprite-bound computation. MapPane consumes the result for exposed-region clipping. The physical `ObjectPaneGetEmptyRect` slug and former `GetEmptyRect` label remain historical/search vocabulary only.
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) now emits the source-facing `ObjectPane::UpdateRenderRegion` leaf, and [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) now emits the complete source-facing `ObjectPane::SetBounds` body. The latter compares `GetScreenBounds` output, conditionally updates inherited `Point m_origin` and `GrafPort::m_visibleBounds`, then forwards optional `objectDataBounds` or the `paneBounds` fallback to `SetObjectData`. [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) is the exact derived item-glyph override.
- This page remains prose-only and does not duplicate class or child formal C++.

## UID0003XX Bounds Source Integration - 2026-07-16

- `NexusTK/map/ObjectPane.cpp` owns both accepted source bodies:
  - primary `+0x0c` / UID0003XW is `UpdateRenderRegion(const RectBounds *)`;
  - primary `+0x2c` / UID0003XX is `SetBounds(const RectBounds *paneBounds, const RectBounds *objectDataBounds)`.
- Their physical `ObjectPaneSetBounds` and `ObjectPaneUpdateBounds` page titles are preserved as historical/search vocabulary. The current class declaration and Pane vtable contract control source identities.
- UID0003XW performs exactly one 16-byte assignment to inherited `GrafPort::m_visibleBounds` at `+0x44`.
- UID0003XX performs exact screen-bounds query/equivalence testing, conditional origin and local-visible-bounds update, local optional object-data fallback selection, and `SetObjectData` dispatch. `Point m_origin` stores Y at `+0xac` and X at `+0xb0`.
- The target is inherited through 14 ObjectPane-family primary vtables. MapPane UID0004DS reaches primary `+0x2c` with both bounds outputs from a helper having 44 direct callers.
- Historical direct-local-bounds comparison, generic UpdateBounds, clip/dirty, and inverted child-name claims are superseded. Security cookies, SIMD POD copies, vtable loads, thunks, and incidental EAX values remain compiler-generated.
- No source route, class declaration, field, vtable slot, wrapper, or by-file formal metadata changes.

## UID00037X MapPane Access Support

- The complete UID00009R declaration now forward-declares/friends MapPane in addition to preserving ObjectList friendship and the inline `GetObjectId() const` accessor.
- UID0004Q8 reads byte `m_objectType` to select LivingObjectPane interpolation; UID0004QC reads `m_objectId` while collecting movement targets. The binary contains direct field loads rather than accessor calls, so MapPane friendship is source-faithful and layout-neutral.
- Existing inline `GetObjectId()` remains for non-friend consumers, and ObjectList retains its separate direct-access contract. No field is made public and no synthetic MapPane-only ObjectPane method is introduced.
- ObjectPane remains owned by `NexusTK/map/ObjectPane.cpp` / reconstructed header; MapPane definitions remain in MapPane.cpp. Scores/path, exact `0x128` layout, type constants, method children, default virtuals, SoundObjectPane ownership, and compiler-only vtables remain unchanged.

## Status

- Confidence: very strong for `ObjectPane` as a base map-object module, complete `0x128` class/header route, exact `ObjectPaneType` taxonomy, ObjectList friendship/direct-access route, inline `GetObjectId()` consumer contract, exact child-method split, typed SoundObjectPane ownership, vtable/source placement, and field directions.
- Proposed module: `map/ObjectPane.cpp`
- Primary class doc: [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- Main address doc: [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- Evidence basis: live IDA MCP confirms core ObjectPane method boundaries, scattered virtual helpers, subclass construction/destruction reachability, and object-pane-family vtable slots.

## File Role

`ObjectPane.cpp` owns the base pane for renderable map objects. It sits below [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), item/object-info panes, and other map-object visual classes. It combines `Pane` behavior with object type, object id/serial, map coordinates, attached object imagery, local bounds, a 16-byte object-data rectangle, owned auxiliary/image state, and map-position updates. For `ObjectPane+0xfc`, `m_objectId` is the primary current source-facing name used by [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md); `m_objectSerial` remains an alias/caveat for protocol vocabulary.

This file should not be merged into generic [UID:0000MC][Pane](by-file/Pane.md) infrastructure. `Pane` owns generic UI/window behavior; `ObjectPane` owns game-object rendering state and `MapPane` integration.

## ObjectList Header Integration

- `ObjectPane.h` owns the unscoped `ObjectPaneType` declaration with exact values: item `0`, flying `1`, primary effect `2`, living `3`, secondary effect `4`, static `5`, balloon `6`, hit bar `7`, damage number `8`, object info `9`, lighting `10`, and sound `11`.
- The header forward-declares `class ObjectList;` and declares `friend class ObjectList;` inside `ObjectPane`. This remains the highest-probability original-style route for binary-proven ObjectList direct reads of protected/private `m_objectType` at `+0xf8` and `m_objectId` at `+0xfc`; ObjectList must not be rewritten through the accessor or casts.
- Exact constructor producers independently confirm every enum value: Item `0`; Flying post-base override `1`; Effect selector split `2/4`; Living `3`; Static `5`; Balloon `6`; HitBar `7`; DamageNumber `8`; ObjectInfo `9`; Lighting `10`; Sound `11`.
- `ObjectList.h` only needs the `ObjectPane` forward declaration for pointer members/signatures. `ObjectList.cpp` includes the complete `ObjectPane.h` before methods that read ObjectPane fields or call `GetMapPosition`.
- This by-file page remains prose-only. It carries no `RECONSTRUCTION_CPP` metadata and does not duplicate the class declaration or exact child bodies.

## Object Id Accessor Integration

- `ObjectPane.h` defines `int GetObjectId() const { return m_objectId; }` inline in the complete [UID:00009R][ObjectPane](by-class/ObjectPane.md) declaration. The exact `+0xfc` read is binary-proven; inlining explains why no separate function body or address page exists.
- [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) and [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) consume the accessor through source-facing `g_pUserPane`. Their inlined machine reads from the inherited ObjectPane subobject match the accessor exactly.
- The accessor serves non-friend pane consumers only. It does not replace the established `friend class ObjectList` route, alter field visibility, add an out-of-line source definition, or justify a score change for this file page.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectPane` | [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) index plus exact children [UID:0003XN][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md)-[UID:0003Y0][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md) and virtuals [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)/[UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) | Base game-object pane for object type/id, map coordinates, attached object, bounds, object-data rect, owned auxiliary image state, and map position. |
| inline object-id access | `ObjectPane+0xfc`, inlined in UID0004Q0/UID0004Q1 | `GetObjectId() const` returns `m_objectId` for non-friend source consumers without creating an out-of-line body. |
| attached object lifecycle | `0x005374f0`, `0x005375f0` | Replaces/releases attached light/object imagery and recalculates bounds. |
| object data virtuals | `0x00537720`, `0x00537800`, `0x00537880` | Invalidates and sets/gets the 16-byte object-data rect at the object-state buffer. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Bounds defaults | `0x00469050`, `0x00469080` | Source-ready `ClearOutputRects(paneBounds, objectDataBounds)` and `ComputeRenderBounds(outBounds)` base defaults. The latter is inherited at primary slot `+0x60`, overridden by LivingObjectPane, and consumed as render bounds rather than a generic empty-rectangle query. |
| Lifecycle | `0x005372d0`, `0x005373a0` | Constructs `Pane`, installs `ObjectPane` vtables, initializes object type/id/map/object-data/attachment/owned-state fields, and releases attached/owned state in cleanup. |
| Map position | `0x005374d0`, `0x005378a0` | Gets and sets map coordinates at `+0x100/+0x104`, calling active MapPane position update on change. |
| Object identity access | inline `+0xfc` reads in `0x00572b60` and `0x00572c20` | `GetObjectId() const` exposes the inherited object id to SelfLookPane2 packet-record checks; ObjectList retains direct friend access. |
| Attached object ownership | `0x005374f0`, `0x005375f0`, `0x005376c0` | Attaches/detaches object payloads, updates height offsets, returns current attachment, and notifies `MapPane` when active. |
| SoundObjectPane ownership link | `0x005376d0`, `0x00537700` | `ObjectPane::SetSoundObjectPane` deletes/replaces the typed `+0x120` pointer; `ObjectPane::ClearSoundObjectPane` conditionally nulls it without release. The latter has no direct xref but its exact operation is inlined by SoundObjectPane destruction. |
| Container/bounds operations | `0x00537720`, `0x00537740`, `0x00537760` | Invalidates object-data rects; UID0003XW `UpdateRenderRegion` assigns inherited local visible bounds; UID0003XX `SetBounds` compares screen bounds, conditionally updates Y/X origin and localized visible bounds, and forwards optional object-data or pane fallback. |
| Object data | `0x00537800`, `0x00537880` | Updates and copies out the 16-byte object-data rect. |

## Boundary Notes

- `ObjectPane` should be a base map-object source under `map/`, while [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) owns actor-specific movement, animation, command, and packet logic.
- Item/object overlay classes are now documented as companion modules: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) owns ground/flying item objects, [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) owns attached/floating overlays such as balloons, object labels, hit bars, and damage numbers, [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) owns static map props, [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) owns light-source object panes, and [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md) owns positional sound objects.
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) is excluded from the `ObjectPane` family despite its misleading recovered name because it constructs through `Pane` and is allocated by [UID:0000P1][UserPane](by-file/UserPane.md).
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) is now a non-emitting split/index. Exact child pages carry reconstructable ownership and should be used for future C++ emission decisions.
- [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) consumes `ObjectPane+0xfc` as `m_objectId` in `ObjectList::FindByObjectId(int objectId)`. Keep `m_objectSerial` only as an alias/caveat unless later source-vocabulary evidence proves a serial-first spelling.
- [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) and [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) compare packet object ids against the inherited `ObjectPane+0xfc` value. Their exact inlined reads support the header-only `GetObjectId()` contract; they do not create ObjectPane.cpp method bodies.
- [UID:00009R][ObjectPane](by-class/ObjectPane.md) now owns the complete source-safe class declaration: `Pane` inheritance, exact `Pane[0xf8] -> ObjectPane[0x128]` layout, all established fields and method prototypes, pure ordinary destructor, concrete empty `RenderFrame`/`DrawSpriteFrame` defaults, typed `SoundObjectPane *m_soundObjectPane` at `+0x120`, and `[[CHILDREN]]`. Implicit 32-bit alignment supplies three bytes after `m_objectType` and three tail bytes after `m_transientObjectFlag`; no source reserve fields are valid.
- The same class declaration now places `ObjectPaneType` before the class, forward-declares `ObjectList`, and grants ObjectList friendship. This preserves the exact byte type ABI and compile-visible direct-access route used by Add/Remove/GetTypedObjectKey/ContainsTypedObject and FindByObjectId.
- Highest-probability header placement is `ObjectPane.h` including `Pane.h` and `RectBounds.h`, with forward declarations for `GrafPort`, `SoundObjectPane`, and `MapPoint`. `ObjectPane.cpp` includes `ObjectPane.h` followed by `SoundObjectPane.h` before the deleting `SetSoundObjectPane` definition so the pointed type is complete; `ClearSoundObjectPane` requires no delete.
- Source order remains class declaration followed by exact constructor/destructor and method children. Within the current ObjectPane emitter route, the typed setter is position `70`, no-release clear position `80`, and [UID:0002SK][0x00620294-0x00620340.ObjectPaneVtableData](by-memory/0x00620294-0x00620340.ObjectPaneVtableData.md) class-covered compiler marker position `90`.
- The scattered base default [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) emits exactly once through the ObjectPane class route. Its semantic output names match the derived ItemObjectPane override and MapPane caller flow; no duplicate file-level formal block is needed.
- The scattered base default [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) emits exactly once through the same route as `ObjectPane::ComputeRenderBounds`. [UID:00009R][ObjectPane](by-class/ObjectPane.md) owns its one non-const declaration in H; this by-file page remains prose-only and does not duplicate the definition or declaration.
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) and [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) now emit exactly once through this source route as `UpdateRenderRegion` and `SetBounds`. Their physical slugs remain unchanged, and the by-file page remains prose-only.
- The first primary/EventHandler/TimerHandler cells are pure-destructor views, while primary `+0x5c/+0x64` are concrete empty `nullsub_18` defaults. RTTI/vtable arrays, adjusted facets, vptr stores, scalar deleting wrappers, delete flags, and purecall cells are compiler-generated and must not be handwritten.
- Historical `m_ownedObjectImageState` / `m_auxiliaryImageState`, `SetOwnedObjectImageState`, and raw no-route wording remain searchable only as superseded aliases. Both setter callers pass freshly constructed SoundObjectPane objects, and the ordinary/scalar SoundObjectPane destructor clears the exact owner field.
- `ObjectPane::SetObjectData` at `0x00537800-0x0053787a` is a live IDA-verified virtual-slot body that updates the 16-byte object-data rect and conditionally recomputes attached-state geometry. Keep it with this file until a later field-name audit proves a narrower helper owner.
- The `0x0053c810` calls from `AttachObject`, `DetachObject`, and `SetObjectData` are `LightingObjectPane::GetLightBounds(RectBounds *) const` on the attached LightingObjectPane payload. They compute translated light geometry from `m_lightImageIndex`, local offsets, and the borrowed anchor source for lifecycle/data invalidation. These are ObjectPane consumer calls only; method ownership is UID000075/UID0000KO. The former synthetic resolver/private AttachedObjectPane ownership interpretation is dated corrected history.

## IDA MCP Evidence

Targeted checks on 2026-06-05 confirmed:

- `0x00469050-0x0046907a` and `0x00469080-0x004690a5` are real rect-helper virtuals referenced from vtables.
- Current UID00020S reanalysis resolves `0x00469080-0x004690a5` more specifically as primary slot `+0x60` `ComputeRenderBounds`: twelve non-Living tables point to the base default, Living primary cell `0x006209dc` points to override `0x0053bdc0`, and MapPane's indirect call at `0x0050981d` feeds an exposed-region intersection.
- `0x005372d0-0x00537395` is the constructor and has direct constructor-like xrefs from object-pane subclasses.
- `0x005373a0-0x005374cb` is the destructor.
- `0x005374d0-0x005374eb`, `0x005374f0-0x005375e1`, `0x005375f0-0x005376b5`, `0x005376c0-0x005376c7`, `0x005376d0-0x005376f4`, raw no-route `0x00537700-0x00537714`, `0x00537720-0x00537739`, `0x00537740-0x00537751`, `0x00537760-0x005377f2`, `0x00537800-0x0053787a`, `0x00537880-0x00537894`, and `0x005378a0-0x005378fa` are real method/body starts/ranges.
- `SetObjectData`, `GetObjectData`, and `SetPosition` have object-pane-family vtable/data references, while the constructor/destructor caller sets tie the core range to the surrounding map-object subclasses.

## Cross-References

- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- [UID:0003XN][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md)
- [UID:0003XO][0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor](by-memory/0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor.md)
- [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md)
- [UID:0003XQ][0x005374f0-0x005375e1.ObjectPaneAttachObject](by-memory/0x005374f0-0x005375e1.ObjectPaneAttachObject.md)
- [UID:0003XR][0x005375f0-0x005376b5.ObjectPaneDetachObject](by-memory/0x005375f0-0x005376b5.ObjectPaneDetachObject.md)
- [UID:0003XS][0x005376c0-0x005376c7.ObjectPaneGetAttachedObject](by-memory/0x005376c0-0x005376c7.ObjectPaneGetAttachedObject.md)
- [UID:0003XT][0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane](by-memory/0x005376d0-0x005376f4.ObjectPaneSetSoundObjectPane.md)
- [UID:0003XU][0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw](by-memory/0x00537700-0x00537714.ObjectPaneClearSoundObjectPaneRaw.md)
- [UID:0003XV][0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect](by-memory/0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect.md)
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md)
- [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md)
- [UID:0003XY][0x00537800-0x0053787a.ObjectPaneSetObjectData](by-memory/0x00537800-0x0053787a.ObjectPaneSetObjectData.md)
- [UID:0003XZ][0x00537880-0x00537894.ObjectPaneGetObjectData](by-memory/0x00537880-0x00537894.ObjectPaneGetObjectData.md)
- [UID:0003Y0][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md)
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)

## Changes

- 2026-07-25 B004 UID00020S source-root synchronization:
  - Preserved `91/92`, `NexusTK/map/`, the prose-only/no-duplicate-source policy, and all existing ObjectPane source-union evidence.
  - Replaced the unresolved empty-helper role with the accepted source-ready `ObjectPane::ComputeRenderBounds` base default, exact primary-slot inheritance, Living same-slot override, MapPane clipping consumer, and one-definition/one-declaration route through UID00020S and UID00009R.

- 2026-07-16 Agent-B005 UID0003XX accepted callback:
  - Preserved `91/92`, `NexusTK/map/`, the complete current ObjectPane source union, and all unrelated/concurrent enum, layout, friendship, accessor, SoundObjectPane, MapPoint, vtable, and history evidence.
  - Recorded source-ready UID0003XW `UpdateRenderRegion` and UID0003XX `SetBounds` bodies, exact inherited Y/X origin and visible-bounds expressions, comparison/update/fallback order, vtable/runtime caller liveness, and compiler exclusions.
  - Corrected inverted child naming in current prose without renaming either physical page or adding by-file formal C++.
- 2026-07-16 Agent-B005 UID0003HT callback:
  - Preserved `91/92`, `NexusTK/map/`, the complete current ObjectPane source union, and all unrelated/concurrent evidence.
  - Added the source-ready UID00020R base default and exact `paneBounds` / `objectDataBounds` contract; replaced current clip/dirty wording with pane-visible/object-data flow while retaining old terminology only as historical context.
  - Kept the by-file page prose-only and added no duplicate source, raw ABI, or compiler-generated mechanics.
- 2026-07-14 B004 UID00039M packet-update support sync:
  - Retained `91/92` and the finalized ObjectList friendship/direct-access route while documenting the separate inline `GetObjectId() const` header contract for non-friend consumers.
  - Added the exact `ObjectPane+0xfc` return, no-out-of-line-body disposition, and UID0004Q0/UID0004Q1 SelfLookPane2 packet-record consumers without changing the ObjectPane source path, method ownership, or unrelated content.

- 2026-07-14 B002 UID0002BB source-root sync:
  - Retained `91/92` and added the complete `ObjectPaneType` values, exact producer evidence, `ObjectList` forward declaration/friendship, header/include placement, direct-access rationale, and prose-only/no-duplicate-source disposition.
  - Preserved all existing ObjectPane layout, SoundObjectPane integration, child boundaries, vtable/compiler distinctions, and historical provenance.

- 2026-07-14 B002 UID0001DJ callback:
  - Raised `89/88 -> 91/92` and documented the complete ObjectPane header/source route without adding by-file reconstruction metadata.
  - Added the exact layout, forward-declaration/include order, typed SoundObjectPane link lifecycle, method/compiler source order, pure-destructor versus concrete-empty render disposition, and historical alias replacement while preserving all unrelated ObjectPane-family evidence.

- 2026-06-26 B009 ObjectList id-lookup support sync:
  - Recorded [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md) as the ObjectList consumer that compares `ObjectPane+0xfc` as primary `m_objectId`, while preserving `m_objectSerial` as a protocol-vocabulary alias/caveat.

- 2026-06-19 B015 AttachmentAnchorResolver consumer sync:
  - Scores unchanged at `89/88`.
  - Documented that the `0x0053c810` calls from ObjectPane attachment/object-data methods consume `AttachmentAnchorResolver::ComputeScreenBounds` and do not make ObjectPane the resolver owner.
  - Summary/evidence: B015 raw PE reanalysis confirmed the resolver method signature, caller spread through ObjectPane lifecycle/data paths, and private `AttachedObjectPane.cpp` placement recommendation while preserving this file as the base ObjectPane source root.

- 2026-06-17 B001 source-quality split sync:
  - What existed before: the file page was `88/86`, treated [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) as the main address doc, and still described base fields with stale sprite/frame/palette wording.
  - Changed to: `89/88`; [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) is now documented as a non-emitting split/index; exact child pages [UID:0003XN][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md) through [UID:0003Y0][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md) carry ObjectPane method ownership; field wording now uses object type/id, map coordinates, object-data rect, attachment state, and owned auxiliary image state.
  - Evidence: B001 live review confirmed additional child bodies at `0x005374d0`, `0x005376c0`, `0x005376d0`, raw no-route helper `0x00537700`, padding, vtable/source placement, and scattered rect helper relationships.

- 2026-06-05 live IDA refresh:
  - What existed before: the file page already had the right module boundary but retained stale recovery-output caveats and older evidence wording.
  - What changed: raised completion/confidence to `88/86`, removed stale recovery-output references, and updated the evidence around `SetObjectData`, vtable slots, and constructor/destructor reachability.
  - Summary/evidence: live IDA confirms both scattered virtual helpers, all ten core ObjectPane method boundaries, object-pane-family vtable references, and subclass construction/destruction caller sets.

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a reconstruction-path coverage error.
  - Changed to: `NexusTK/map/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `ObjectPane` constructor anchor at `0x005372d0`; proposed-source-tree keeps this game-world object base under `map/`, separate from generic `ui/core/Pane.cpp` and from item/static/sound object companions.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `84`.
- Summary/evidence: the page documents the base map-object role, method families, boundary notes, IDA range checks, and subclass/module cross-references; confidence is strong for source role and remaining uncertainty is mostly final field/slot naming.

## UID0003U6 Map-Position Source Integration - 2026-07-15

- File metadata remains `91/92` with `NexusTK/map/` ownership. [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) is the exact ObjectPane.cpp member definition and now carries complete `92/94` formal C++.
- The accessor writes inherited `m_mapY` to [UID:0004R0][MapPoint](by-type/by-struct/MapPoint.md) `row` at `+0`, `m_mapX` to `column` at `+4`, returns the caller output pointer, and has no callee, guard, side effect, or alternate layout.
- The shared MapPoint declaration is emitted through MapPane.cpp at position 5; ObjectPane.h retains only the source-legal forward declaration and member declaration. No duplicate type, x/y union, standalone coordinate file, or ObjectPane score/formal rewrite is introduced.
- Consumers include [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md), retained UserPane movement-packet helpers, MapPane timer logic, and UserPane screen-position logic. Their use does not move accessor ownership away from ObjectPane.cpp.
