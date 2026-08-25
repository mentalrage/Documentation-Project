** TARGET-REPORT-UID:0001D5 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-objectpane-core-source-quality-0001D5-20260617

Agent: Agent-B001
Target: [UID:0001D5] `by-memory/0x005372d0-0x005378fa.ObjectPane.md`
Current state: `82/88`, owner/emitter [UID:00009R] `ObjectPane`
Disposition requested: report-only source-quality review

## Executive Recommendation

[UID:0001D5] should not remain a reconstructable/emitting aggregate. It should become a parent-blank, non-emitting split/index over exact `ObjectPane` method children.

Recommended metadata for [UID:0001D5]:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `NONE` |
| `RECONSTRUCTABLE` | `FALSE` |
| `EMITTER_UIDS` | blank |
| Final C++ | blank |

Reason: the current page says IDA confirmed ten method starts, but live review found additional in-range executable bodies at `0x005374d0`, `0x005376c0`, and `0x005376d0`, plus a raw/no-route body at `0x00537700`. The current aggregate would duplicate source emission and omit live source-bearing children. Exact child method pages should carry the `ObjectPane` owner/emitter route, while this broad range remains an inventory/index like other repaired mixed method clusters.

## Evidence Reviewed

- Read and followed `goal.md`, `notes.md`, `Supervisor.md`, `by-structure.md`, `inference_research.md`, and `proposed-source-tree.md`.
- Reviewed support docs: target page, [UID:00009R] `ObjectPane`, [UID:0000M5] `ObjectPane`, scattered helpers [UID:00020R]/[UID:00020S], [UID:0002SK] `ObjectPaneVtableData`, [UID:000260] `ObjectPaneReadOnlyData`, [UID:0001D6] `StaticObjectPaneCore`, [UID:0001D7] `ItemAndFlyingObjectPanes`, `MapPaneCreateOrUpdateObjectPane`, `MapPaneRemoveObjectPaneById`, `MapPaneDetachObjectPane`, `ObjectListFindByObjectId`, and relevant subclass/file docs.
- Used generated/Wave context only as weak evidence. `simroot_v2/class_ObjectPane.cpp` and Wave2 show how the stale `spriteIndex/frameIndex/paletteIndex` wording entered the docs, but live IDA/ObjectList evidence rejects that source-facing field model.
- Live IDA evidence already collected in this assignment: `lookup_funcs`, `decompile`, `xrefs_to`, `get_bytes`, and raw VA/RVA/rel32 pointer checks over the target and helper starts.
- Verified decimal offsets/sizes with `tools/int_convert.py` for `0xf8`, `0xfc`, `0x100`, `0x104`, `0x108`, `0x118`, `0x11c`, `0x120`, `0x124`, `0xa0`, `0xa4`, and relevant slot/size constants.

## Exact Range And Split Inventory

Supervisor should split the aggregate into exact children in this order:

| Range | Recommended page/method | Route | Score |
| --- | --- | --- | --- |
| `0x005372d0-0x00537395` | `ObjectPaneConstructor` | owner/emitter [UID:00009R] | `86/90` |
| `0x00537395-0x005373a0` | padding | ignored | `100/strong` |
| `0x005373a0-0x005374cb` | `ObjectPaneNonDeletingDestructor` | owner/emitter [UID:00009R] | `86/90` |
| `0x005374cb-0x005374d0` | padding | ignored | `100/strong` |
| `0x005374d0-0x005374eb` | `ObjectPaneGetMapPosition` | owner/emitter [UID:00009R] | `87/91` |
| `0x005374eb-0x005374f0` | padding | ignored | `100/strong` |
| `0x005374f0-0x005375e1` | `ObjectPaneAttachObject` | owner/emitter [UID:00009R] | `86/90` |
| `0x005375e1-0x005375f0` | padding | ignored | `100/strong` |
| `0x005375f0-0x005376b5` | `ObjectPaneDetachObject` | owner/emitter [UID:00009R] | `86/90` |
| `0x005376b5-0x005376c0` | padding | ignored | `100/strong` |
| `0x005376c0-0x005376c7` | `ObjectPaneGetAttachedObject` | owner/emitter [UID:00009R] | `86/90` |
| `0x005376c7-0x005376d0` | padding | ignored | `100/strong` |
| `0x005376d0-0x005376f4` | `ObjectPaneSetOwnedObjectImageState` | owner/emitter [UID:00009R] | `85/89` |
| `0x005376f4-0x00537700` | padding | ignored | `100/strong` |
| `0x00537700-0x00537714` | `ObjectPaneClearOwnedObjectImageNoReleaseRaw` | owner `NONE`, no emitter | `85/88`, ignored/non-emitting |
| `0x00537714-0x00537720` | padding | ignored | `100/strong` |
| `0x00537720-0x00537739` | `ObjectPaneInvalidateObjectDataRect` | owner/emitter [UID:00009R] | `86/90` |
| `0x00537739-0x00537740` | padding | ignored | `100/strong` |
| `0x00537740-0x00537751` | `ObjectPaneSetBounds` | owner/emitter [UID:00009R] | `86/90` |
| `0x00537751-0x00537760` | padding | ignored | `100/strong` |
| `0x00537760-0x005377f2` | `ObjectPaneUpdateBounds` | owner/emitter [UID:00009R] | `85/90` |
| `0x005377f2-0x00537800` | padding | ignored | `100/strong` |
| `0x00537800-0x0053787a` | `ObjectPaneSetObjectData` | owner/emitter [UID:00009R] | `87/90` |
| `0x0053787a-0x00537880` | padding | ignored | `100/strong` |
| `0x00537880-0x00537894` | `ObjectPaneGetObjectData` | owner/emitter [UID:00009R] | `87/90` |
| `0x00537894-0x005378a0` | padding | ignored | `100/strong` |
| `0x005378a0-0x005378fa` | `ObjectPaneSetMapPosition` | owner/emitter [UID:00009R] | `87/91` |

The existing top-level padding row `0x005378fa-0x00537900` should remain after this aggregate. `StaticObjectPane` begins at `0x00537900`, so there is no successor merge.

Existing scattered helpers should stay exact children of `ObjectPane`, not be folded into the core aggregate:

| UID | Range | Recommendation |
| --- | --- | --- |
| [UID:00020R] | `0x00469050-0x0046907a` | keep owner/emitter [UID:00009R], raise to `86/91`, source-facing role `ObjectPaneClearOutputRects(Rect *primary, Rect *secondary)` or default rect-output virtual |
| [UID:00020S] | `0x00469080-0x004690a5` | keep owner/emitter [UID:00009R], raise to `86/91`, source-facing role `ObjectPaneGetEmptyRect(Rect *out)` or default empty-bounds virtual |

## Source-Facing Names, Fields, And Types

Recommended base layout names:

| Offset | Best current name | Evidence and rejected alternatives |
| --- | --- | --- |
| `+0xf8` / decimal `248` | `m_objectType` / `ObjectPaneType` byte | Constructors and MapPane removal use it as the object-type discriminator. Known values include item/living/static/light/sound subclasses; type `3` is LivingObjectPane in MapPane removal, type `5` is StaticObjectPane, type `10` lighting, type `11` sound. |
| `+0xfc` / decimal `252` | `m_objectId` or `m_objectSerial` | `ObjectListFindByObjectId` scans panes and compares `+0xfc` to requested object id/serial. Reject generated `spriteIndex`; subclass pages store actual item/static ids later at `+0x128` or subclass-specific fields. |
| `+0x100` / decimal `256` | `m_mapX` | Constructor and `SetMapPosition` first coordinate. Generated/Wave notes conflict on X/Y order; best source-facing method should use `SetMapPosition(int mapX, int mapY)` and document that some out-buffer helpers return the pair in caller-specific order. |
| `+0x104` / decimal `260` | `m_mapY` | Constructor and `SetMapPosition` second coordinate. `GetMapPosition` copies these two fields, with observed output ordering `out[0]=+0x104`, `out[1]=+0x100`. |
| `+0x108` / decimal `264` | `m_objectDataRect` or `m_objectData` | Four-word/16-byte record initialized as a rect and passed to MapPane invalidation. It is not the 68-byte `ObjectStatusBlob`. |
| `+0x118` / decimal `280` | `m_attachedObject` / `m_attachedObjectPane` | Attach/detach/destructor read and write this pointer, compute attached bounds, and optionally destroy/remove the old attached object. |
| `+0x11c` / decimal `284` | `m_attachmentHeightOffset` | Float-like offset adjusted by the `g_pLightObjImageLib`/attachment descriptor table on attach/detach/destruction. |
| `+0x120` / decimal `288` | `m_ownedObjectImageState` / `m_auxiliaryImageState` | `0x005376d0` releases the old pointer through vtable slot 0 with flag `1`, then stores the new pointer. `0x00537700` only clears it. |
| `+0x124` / decimal `292` | `m_transientObjectFlag` | Constructor clears the byte and MapPane local-object refresh clears this offset. Exact semantic name remains below C++ readiness. |
| `+0xa0`, `+0xa4` | inherited adjusted vtable views | Constructor/destructor install three ObjectPane vtable views. Treat these as inherited handler/timer/event adjusted subobject views, not data fields. This matches EffectObjectPane destructor reanalysis and ObjectPane vtable data. |

Method names and signatures:

| Address | Recommended source-facing signature direction |
| --- | --- |
| `0x005372d0` | `ObjectPane::ObjectPane(ObjectPaneType type, int objectIdOrSerial, int mapX, int mapY)` |
| `0x005373a0` | `ObjectPane::~ObjectPane()` ordinary/non-deleting destructor body |
| `0x005374d0` | `void ObjectPane::GetMapPosition(MapPoint *out) const` or equivalent two-int output helper |
| `0x005374f0` | `void ObjectPane::AttachObject(ObjectPane *attached)` or `SetAttachedObject` |
| `0x005375f0` | `void ObjectPane::DetachObject()` / `ClearAttachedObject` |
| `0x005376c0` | `ObjectPane *ObjectPane::GetAttachedObject() const` |
| `0x005376d0` | `void ObjectPane::SetOwnedObjectImageState(void *state)` pending final type |
| `0x00537700` | no emitting source method until reachability is found; if retained, name as no-release raw clear helper |
| `0x00537720` | `void ObjectPane::InvalidateObjectDataRect()` / `RefreshObjectRect` rather than `ReleaseFromContainer` |
| `0x00537740` | `void ObjectPane::SetBounds(const Rect *bounds)` |
| `0x00537760` | `void ObjectPane::UpdateBounds(const Rect *bounds, const Rect *clipOrNull)` |
| `0x00537800` | `void ObjectPane::SetObjectData(const Rect *objectDataRect)` |
| `0x00537880` | `void ObjectPane::GetObjectData(Rect *out) const` |
| `0x005378a0` | `void ObjectPane::SetMapPosition(int mapX, int mapY)` |

The base `ObjectPane` page and file page should remove or narrow the current "sprite/frame/palette" wording. That state belongs primarily to subclasses and image-library records, not to the base constructor fields. The base core owns object type/id, map coordinates, object-data rectangle, attached object pointer/height, and owned auxiliary image state.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Versus Exact Children

Best decision: [UID:0001D5] becomes a non-emitting split/index.

Evidence checked:

- `lookup_funcs` reports the documented ten functions but also confirms modeled bodies at `0x005374d0`, `0x005376c0`, and `0x005376d0`.
- Raw byte review shows a body-shaped helper at `0x00537700-0x00537714`, bracketed by `0xcc` padding, not represented as an IDA function.
- The current page's ten-anchor table omits the live position getter, attached-object getter, owned-image setter, and raw no-release clear helper.
- The `ItemAndFlyingObjectPanes` repaired split is a local precedent for moving a broad method cluster to an index while exact children carry owners and emission.

Rejected alternatives:

- Keep [UID:0001D5] reconstructable/emitting: rejected because it would emit multiple unrelated methods as one by-memory body and still miss live children.
- Fold scattered `0x00469050`/`0x00469080` into the aggregate: rejected because they are exact non-contiguous virtual helpers with existing pages and vtable-only reachability.
- Split only the three newly discovered functions and keep the ten-anchor aggregate reconstructable: rejected because even the ten known anchors are separate source methods and should not share one final C++ block.

Impact: [UID:0001D5] should score higher as a reviewed index, but formal C++ must remain blank. Exact children become the future C++ candidates after class/type names settle.

### Reachability

Constructor and destructor are live through subclass construction/destruction paths across static, item/flying, attached, effect, living, lighting, and sound object panes. Virtual methods at `0x005374f0`, `0x005375f0`, `0x00537720`, `0x00537740`, `0x00537760`, `0x00537800`, `0x00537880`, and `0x005378a0` have object-pane-family vtable/data references. `0x005374d0` has broad direct callers in ObjectList/MapPane coordinate scans. `0x005376c0` has a direct ObjectList/static-lighting caller. `0x005376d0` has direct MapPane/object-update callers at `0x0050eda0` and `0x005132c6`.

The raw `0x00537700` helper has no IDA function object, no direct xrefs, no VA/RVA pointer hits, and no rel32 call/jump hits in the PE scan performed during this task. Best inference: it is a retained no-release clear helper for `+0x120`, but it should stay non-emitting/no-route until a caller, vtable cell, or EH cleanup route is found.

### Field And Type Direction

`+0xf8` is confidently `m_objectType`. MapPane removal and detach logic read it directly; subclass constructors pass known category values.

`+0xfc` should be `m_objectId` or `m_objectSerial`, not `spriteIndex`. `ObjectListFindByObjectId` explicitly scans `+0xfc` for the requested id/serial, and MapPane create/remove paths receive object ids from packets. The exact word "serial" versus "id" remains a minor naming choice, but `objectId` is the best source-facing default because existing support docs and caller pages use that language.

`+0x100/+0x104` are map tile coordinates. The best source-facing pair is `mapX/mapY`, with a note that `GetMapPosition` copies the pair into caller storage in the observed output order `out[0]=+0x104`, `out[1]=+0x100`. This does not block source placement but does block formal class C++ until the shared point type is named.

`+0x108` is a 16-byte object-data rectangle, not the 68-byte ObjectStatusBlob. The constructor zeroes it through the rectangle helper, `SetObjectData` copies exactly 16 bytes, `GetObjectData` copies it out, and `InvalidateObjectDataRect` passes it to the active MapPane invalidation slot.

`+0x118/+0x11c/+0x120` are attachment/auxiliary visual state. The attachment pointer interacts with `g_pLightObjImageLib` descriptor rows and attached-object bounds; the `+0x120` pointer is an owned image/auxiliary state pointer released through its own vtable. These are distinct from the generic `0x004b97d0` auxiliary cleanup helper called by `MapPaneDetachObjectPane`.

### Source Placement And Ownership

Best source placement remains `NexusTK/map/ObjectPane.cpp`.

Rejected placements:

- `MapPane.cpp`: rejected because MapPane is a caller/container, while the bodies manipulate `this` as the object-pane base and are installed in ObjectPane-family vtables.
- Subclass modules: rejected for the base methods. Static/item/flying/effect/living/lighting/sound panes call or override these methods but do not own the base fields.
- Generic `Pane.cpp`: rejected because these methods are map-object identity, ObjectList/MapPane integration, attachment, and object-data behavior, not generic UI Pane behavior.
- ObjectStatusBlob source: rejected because the `+0x108` record is 16 bytes and rect-like; packet object status is 68 bytes and lives in separate parser/update code.

### Vtable Slots And Helper Roles

The three base ObjectPane vtable views at `0x00620298`, `0x00620308`, and `0x00620338` are constructor/destructor installed and match the `+0x00/+0xa0/+0xa4` adjusted views. Treat the secondary views as inherited handler/timer/event-style subobjects rather than explicit ObjectPane fields.

`0x00469050` and `0x00469080` are vtable-only default rect helpers. Their current names are acceptable descriptive names, but source docs should avoid claiming original names. `ClearOutputRects` clears two caller-provided rectangles; `GetEmptyRect` writes one empty rectangle and returns.

### Score, Placement, And Final-C++ Impact

The aggregate can rise to `88/91` because the inventory, boundaries, owners, no-route raw helper, scattered helper relationship, source placement, and field/type direction are now known. It cannot emit C++ because it is structurally an index. Exact child methods can score `85+`, but should still keep formal C++ blank until the exact pages exist and shared type names are accepted.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001D5].

Reason: the target should become `RECONSTRUCTABLE:FALSE` and non-emitting. A formal C++ block on the aggregate would mix constructor, destructor, accessors, virtual invalidation, bounds, object-data, map-position, and raw no-route helper behavior in one invalid source item.

Also do not populate formal C++ in this pass for proposed exact children or for [UID:00020R]/[UID:00020S]. Although many exact methods clear the `85/85` score gate, the exact child pages do not yet exist and the final declaration still depends on accepted names for `ObjectPaneType`, `Rect`/`MapPoint`, active `MapPane` global, attachment descriptor type, owned image-state pointer type, and virtual slot names. After supervisor split, trivial getters/setters can be reconsidered for C++ once those type names are resolved.

## Support Docs To Update

- [UID:0001D5] target page: reclassify to non-emitting split/index; add the full child inventory above; remove statement that only ten starts exist.
- Create exact child by-memory pages for all source-bearing children listed above; create/record the raw no-route `0x00537700` item as non-emitting or ignored.
- [UID:00009R] `ObjectPane`: update method list to include `GetMapPosition`, `GetAttachedObject`, `SetOwnedObjectImageState`, and raw `ClearOwnedObjectImageNoRelease`; change base field wording from sprite/frame/palette to object id/map coordinates/object-data/attachment state; recommended score `87/90`.
- [UID:0000M5] `ObjectPane` file: keep `NexusTK/map/`, update proposed contents and method families; recommended score `89/88`.
- [UID:00020R] and [UID:00020S]: raise to `86/91`, keep owner/emitter [UID:00009R], clarify source-facing names are descriptive default rect-output virtuals.
- [UID:0002SK] `ObjectPaneVtableData`: no range change required; optionally add slot-role notes once child pages are created.
- MapPane detach/remove docs: no ownership change required; optionally cross-link the `+0x20` ObjectPane virtual to `ObjectPaneInvalidateObjectDataRect` once split.

## Validation Commands

Commands/evidence used or suitable for supervisor replay:

> Executable block R001 was removed from this report and preserved verbatim in [0001D5-objectpane-core-source-quality-removed.md](0001D5-objectpane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA replay checklist:

```text
lookup_funcs 0x005372d0,0x005373a0,0x005374d0,0x005374f0,0x005375f0,0x005376c0,0x005376d0,0x00537700,0x00537720,0x00537740,0x00537760,0x00537800,0x00537880,0x005378a0,0x00537900,0x00469050,0x00469080
decompile each modeled target function above
xrefs_to each modeled function start and ObjectPane vtable bases 0x00620298,0x00620308,0x00620338
get_bytes across every padding span listed in the split inventory
raw PE VA/RVA pointer and rel32 call/jump scan for 0x00537700
```

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly from B001. Supervisor should allocate real UIDs for `<NEW:...>` placeholders before applying new child rows.

Replacement row for existing [UID:00020R] near current coverage line 600:

```markdown
    - [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) 0x00469050-0x0046907a | class virtual helper | ObjectPaneClearOutputRects : reconstructable : 86% : very-strong : B001 2026-06-17 source-quality reanalysis confirms this exact shared ObjectPane default rect-output virtual; it clears two caller-provided rectangles through the rectangle setter helper, has ObjectPane-family vtable refs only, no ordinary callers, verified padding boundaries, and owner/emitter [UID:00009R]. Formal C++ remains blank pending final Rect/vtable-slot naming.
```

Replacement row for existing [UID:00020S] near current coverage line 602:

```markdown
    - [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md) 0x00469080-0x004690a5 | class virtual helper | ObjectPaneGetEmptyRect : reconstructable : 86% : very-strong : B001 2026-06-17 source-quality reanalysis confirms this exact shared ObjectPane empty-rect virtual; it zeroes and returns one caller-provided rectangle, has ObjectPane-family vtable refs only, no ordinary callers/callees, verified padding boundaries, and owner/emitter [UID:00009R]. Formal C++ remains blank pending final Rect/vtable-slot naming.
```

Replacement row for current [UID:0001D5] near coverage line 2337:

```markdown
    - [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) 0x005372d0-0x005378fa | class split index | ObjectPaneCoreMethods : ignored : 88% : very-strong : B001 2026-06-17 source-quality reanalysis reclassifies this range as a non-emitting ObjectPane core split/index; live IDA found the constructor, ordinary destructor, missed map-position getter, attach/detach, attached-object getter, owned-image setter, raw no-route owned-image clear helper, invalidation/bounds/object-data/map-position virtuals, all internal padding, scattered rect helper relationships, and the StaticObjectPane successor boundary. Exact child pages should carry ObjectPane source emission.
```

Insert these child rows immediately under the replacement [UID:0001D5] row:

```markdown
        - [UID:<NEW:ObjectPaneConstructor>][0x005372d0-0x00537395.ObjectPaneConstructor](by-memory/0x005372d0-0x00537395.ObjectPaneConstructor.md) 0x005372d0-0x00537395 | constructor | ObjectPaneConstructor : reconstructable : 86% : strong : Exact ObjectPane base constructor; calls Pane construction, stores object type at +0xf8, object id/serial at +0xfc, map coordinates at +0x100/+0x104, installs three ObjectPane vtable views, initializes the +0x108 object-data rect and attachment/owned-image state, and has subclass constructor callers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00537395-0x005373a0 | padding | ObjectPane constructor to destructor alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneNonDeletingDestructor>][0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor](by-memory/0x005373a0-0x005374cb.ObjectPaneNonDeletingDestructor.md) 0x005373a0-0x005374cb | ordinary destructor | ObjectPaneNonDeletingDestructor : reconstructable : 86% : strong : Exact ordinary ObjectPane destructor; restores base vtable views, releases attached object state through LightObjImageLib descriptor/MapPane invalidation/ObjectList removal/deleting destructor paths, releases owned image state at +0x120, and chains to Pane cleanup.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005374cb-0x005374d0 | padding | ObjectPane destructor to map-position getter alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneGetMapPosition>][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) 0x005374d0-0x005374eb | accessor | ObjectPaneGetMapPosition : reconstructable : 87% : very-strong : Exact live position getter missed by the old aggregate; copies ObjectPane map coordinate fields +0x100/+0x104 into a caller-provided two-int output and has broad ObjectList/MapPane direct caller evidence.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005374eb-0x005374f0 | padding | ObjectPane map-position getter to attach helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneAttachObject>][0x005374f0-0x005375e1.ObjectPaneAttachObject](by-memory/0x005374f0-0x005375e1.ObjectPaneAttachObject.md) 0x005374f0-0x005375e1 | virtual method | ObjectPaneAttachObject : reconstructable : 86% : strong : Exact ObjectPane attached-object replacement method; removes/deletes any old attached pane, stores the new pointer at +0x118, updates the attachment height offset from the LightObjImageLib descriptor table, recomputes attached geometry when the active MapPane is live, and invalidates object bounds.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005375e1-0x005375f0 | padding | ObjectPane attach to detach alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneDetachObject>][0x005375f0-0x005376b5.ObjectPaneDetachObject](by-memory/0x005375f0-0x005376b5.ObjectPaneDetachObject.md) 0x005375f0-0x005376b5 | virtual method | ObjectPaneDetachObject : reconstructable : 86% : strong : Exact ObjectPane detach/clear helper; subtracts descriptor height from +0x11c, invalidates attached/object rects when active MapPane is live, and clears +0x118 without deleting the detached object in this body.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005376b5-0x005376c0 | padding | ObjectPane detach to attached-object getter alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneGetAttachedObject>][0x005376c0-0x005376c7.ObjectPaneGetAttachedObject](by-memory/0x005376c0-0x005376c7.ObjectPaneGetAttachedObject.md) 0x005376c0-0x005376c7 | accessor | ObjectPaneGetAttachedObject : reconstructable : 86% : strong : Exact seven-byte ObjectPane accessor returning the attached object pointer at +0x118; live code xref from ObjectList/static lighting synchronization context confirms reachability.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005376c7-0x005376d0 | padding | ObjectPane attached-object getter to owned-image setter alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneSetOwnedObjectImageState>][0x005376d0-0x005376f4.ObjectPaneSetOwnedObjectImageState](by-memory/0x005376d0-0x005376f4.ObjectPaneSetOwnedObjectImageState.md) 0x005376d0-0x005376f4 | method | ObjectPaneSetOwnedObjectImageState : reconstructable : 85% : strong : Exact ObjectPane owned auxiliary/image-state setter; releases the old +0x120 pointer through its vtable with flag 1 and stores the new pointer, with direct MapPane/object-update callers at 0x0050eda0 and 0x005132c6.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005376f4-0x00537700 | padding | ObjectPane owned-image setter to raw clear helper alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneClearOwnedObjectImageNoReleaseRaw>][0x00537700-0x00537714.ObjectPaneClearOwnedObjectImageNoReleaseRaw](by-memory/0x00537700-0x00537714.ObjectPaneClearOwnedObjectImageNoReleaseRaw.md) 0x00537700-0x00537714 | raw no-route helper | ObjectPaneClearOwnedObjectImageNoReleaseRaw : ignored : 85% : strong : Raw IDA-missed body zeros the +0x120 owned image/auxiliary pointer without releasing it; no IDA function object, no xrefs, no VA/RVA pointer hits, and no rel32 call/jump hits were found, so keep it non-emitting/no-owner until a route is proven.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00537714-0x00537720 | padding | ObjectPane raw clear helper to invalidation virtual alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneInvalidateObjectDataRect>][0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect](by-memory/0x00537720-0x00537739.ObjectPaneInvalidateObjectDataRect.md) 0x00537720-0x00537739 | virtual method | ObjectPaneInvalidateObjectDataRect : reconstructable : 86% : strong : Exact ObjectPane virtual that forwards the +0x108 object-data rect to the active MapPane invalidation/refresh slot; vtable refs prove reachability and the old ReleaseFromContainer name should be treated as a generated/descriptive alias.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00537739-0x00537740 | padding | ObjectPane invalidation virtual to SetBounds alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneSetBounds>][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) 0x00537740-0x00537751 | virtual method | ObjectPaneSetBounds : reconstructable : 86% : strong : Exact ObjectPane bounds setter; copies one 16-byte Rect into the inherited/current bounds storage at +0x44 and is reached through ObjectPane-family vtable slots.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00537751-0x00537760 | padding | ObjectPane SetBounds to UpdateBounds alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneUpdateBounds>][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) 0x00537760-0x005377f2 | virtual method | ObjectPaneUpdateBounds : reconstructable : 85% : strong : Exact ObjectPane bounds update helper; compares current/new bounds, updates pane-local position and local rect state, normalizes local offsets, then forwards an explicit or fallback clip/dirty rect to the downstream virtual slot.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005377f2-0x00537800 | padding | ObjectPane UpdateBounds to SetObjectData alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneSetObjectData>][0x00537800-0x0053787a.ObjectPaneSetObjectData](by-memory/0x00537800-0x0053787a.ObjectPaneSetObjectData.md) 0x00537800-0x0053787a | virtual method | ObjectPaneSetObjectData : reconstructable : 87% : strong : Exact ObjectPane object-data setter; invalidates before and after copying the 16-byte +0x108 object-data rect and recomputes attached-object geometry when +0x118 is present and active MapPane state allows it.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053787a-0x00537880 | padding | ObjectPane SetObjectData to GetObjectData alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneGetObjectData>][0x00537880-0x00537894.ObjectPaneGetObjectData](by-memory/0x00537880-0x00537894.ObjectPaneGetObjectData.md) 0x00537880-0x00537894 | virtual method | ObjectPaneGetObjectData : reconstructable : 87% : strong : Exact ObjectPane object-data getter; copies the 16-byte +0x108 record to caller output and returns the output buffer, with ObjectPane-family vtable refs.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00537894-0x005378a0 | padding | ObjectPane GetObjectData to SetMapPosition alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding.
        - [UID:<NEW:ObjectPaneSetMapPosition>][0x005378a0-0x005378fa.ObjectPaneSetMapPosition](by-memory/0x005378a0-0x005378fa.ObjectPaneSetMapPosition.md) 0x005378a0-0x005378fa | virtual method | ObjectPaneSetMapPosition : reconstructable : 87% : strong : Exact ObjectPane map-position setter; when coordinates change, calls the active MapPane position-update helper, invalidates before and after storing +0x100/+0x104, and has ObjectPane-family vtable refs.
```

Keep current top-level successor padding row unchanged:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005378fa-0x00537900 | padding | ObjectPane to StaticObjectPane alignment : ignored : 100% : strong : Confirmed `0xcc` alignment bytes.
```

## Changed Files And Leases

Changed files:

- `tools/leaser/Agents/Agent-B001/research/0001D5-objectpane-core-source-quality.md`

Leases used: none. Per `goal.md`, reports under Agent-B001 `research/` do not require a lease.

No by-* docs, generated files, source files, IDA DB files, generated reports, or `by-memory/-coverage-report.md` were edited.

## Blockers And Follow-Up

No blocker for supervisor execution. The only remaining work is supervisor-owned application of the split/metadata/coverage rows and optional support-doc text updates.

Next useful follow-up after split: final-source class declaration pass for `ObjectPaneType`, `Rect`, `MapPoint`, active `MapPane` global naming, attachment descriptor type, and owned image-state type. After that, small exact children such as `GetAttachedObject`, `GetObjectData`, `SetBounds`, and `SetMapPosition` can be reconsidered for formal C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001D5"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001D5-objectpane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001D5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
