*** UID:000057 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FlyingObjectPane

## UID0003HU Direct Inheritance And RenderFrame Reuse - 2026-07-16

- Current FlyingObjectPane RTTI complete-object locator `0x0064cfdc`, class hierarchy descriptor `0x0064cff0`, and base array `0x0064d000` enumerate `FlyingObjectPane`, `ItemObjectPane`, `ObjectPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`. This proves ordinary direct inheritance through [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md).
- The Flying constructor initializes inherited `short m_itemId` at `+0x128` and `unsigned char m_paletteFlags` at `+0x12a`. The Flying ordinary destructor restores ItemObjectPane primary/EventHandler/TimerHandler vtables before ObjectPane cleanup.
- Flying primary-vtable cell `0x006204f8` points to [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md), the exact source-ready `void ItemObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)` body.
- The inherited body forwards target, const bounds, inherited item/palette state, null overlay, and zero strength to `g_pItemObjImageLib->DrawItemImage` and ignores the helper status. It performs no Flying-specific branch, lookup, mutation, timer action, or overlay handling.
- Exactly one ItemObjectPane RenderFrame definition is emitted. This class does not add a duplicate override, partial declaration, thunk, raw vtable array, or compiler teardown implementation.
- Historical generic action/update wording is superseded by RenderFrame. Class metadata remains `85/88`, owner/emitter UID0000KG, reconstructable true, blank position/formal; all motion, pool, constructor, destructor, bounds, tick, caller, and historical evidence remains unchanged.

## Status

- Confidence: strong for class identity, exact method anchors, vtable stores, pool storage, and MapPane constructor call sites; medium-high for final field names and source-ready method names.
- Source file parent: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), now assigned after both sides clear the corrected `85/85` gate.
- Core executable split index: [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- Scalar deleting destructor: [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) at `0x0053d1a0-0x0053d237`
- Vtable data: [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md), `FlyingObjectPane` RTTI and vtable tables at `0x00620498`, `0x0062049c`, `0x0062050c`, and `0x0062053c`
- Pool storage: [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md), now `88/93` with the formal file-local definition `static PoolAllocator g_flyingObjectPanePool(0x144, 4);`

## Class Purpose

`FlyingObjectPane` is a temporary map object for thrown or launched item visuals. It interpolates an item glyph along an arc, schedules short timer ticks, plays impact sound, triggers linked-object impact animation when applicable, and either drops a new object or removes the temporary pane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0003HV][0x00537cb0-0x00537d60.FlyingObjectPaneConstructor](by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md) | Called from MapPane update paths at `0x0050e09b` and `0x00512ebe`; constructs the `ObjectPane` base, installs the three `FlyingObjectPane` vtable views, and initializes start/end motion state. |
| non-deleting destructor | [UID:0003HW][0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor](by-memory/0x00537d60-0x00537d7f.FlyingObjectPaneNonDeletingDestructor.md) | Restores inherited `ItemObjectPane` vtables and delegates to `ObjectPane` cleanup; no direct current xrefs. |
| inherited `RenderFrame` | [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) | Reuses the one ItemObjectPane void RenderFrame body through primary slot `0x006204f8`; exact RTTI proves direct inheritance and no Flying duplicate. |
| `GetBoundingRect` | [UID:0003HX][0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect](by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md) | Computes the current arc-interpolated item glyph bounds using MapPane/object-list and item-image/tile globals. |
| `OnAnimationTick` | [UID:0003HY][0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick](by-memory/0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick.md) | Advances the flight, schedules timers, handles impact sound/effects, and resolves final drop/removal through MapPane object helpers. |
| scalar deleting destructor | `0x0053d1a0-0x0053d237` | Restores item/flying vtables, runs object-pane cleanup, and frees through the `0x0069b9d4` pool gate when requested. |

## Evidence Notes

- Exact children [UID:0003HV][0x00537cb0-0x00537d60.FlyingObjectPaneConstructor](by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md) through [UID:0003HY][0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick](by-memory/0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick.md) record the 2026-06-12 live IDA refresh for the constructor, destructor shim, bounds method, and animation tick, including function sizes, caller sites, data refs, and padding.
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) records exact `FlyingObjectPane` RTTI/vtable bases and constructor/destructor store xrefs at `0x00537d1c`, `0x00537d22`, `0x00537d2c`, and the scalar destructor path.
- 2026-07-07 B006 current MCP session `supervisor-nexustk-20260707` reconfirmed [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) as the exact `0x00620498-0x00620544` / `0xac`-byte `FlyingObjectPane` RTTI/vtable child. Evidence includes view sizes `0x70`, `0x30`, and `0x0c`, RTTI pointer dwords `0x00620498 -> 0x0064cfdc`, `0x00620508 -> 0x0064d040`, and `0x00620538 -> 0x0064d054`, primary/adjusted vtable bases `0x0062049c`, `0x0062050c`, and `0x0062053c`, constructor stores `0x00537d1c/0x00537d22/0x00537d2c`, scalar destructor `0x0053d1a0`, adjusted thunks `0x0053cee6/0x0053cef1`, and no string/function evidence in the `.rdata` range. The target remains class-owned source-declared/generated-binary output; do not hand-author raw vtable arrays for this class.
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) confirms the exact zero-filled `0x28`-byte PoolAllocator, block size `324` / `0x144`, chunk count `4`, startup/cleanup wrappers, both allocation paths, shared constructor-failure free, and scalar deleting destructor free. MCP session `545b4991`, used during B002 evidence collection on 2026-07-12, and an independent absolute-pointer byte search both exhausted the same six direct routes; this does not assert later session availability.
- Constructor xrefs from MapPane packet/update helpers are evidence for creation, not source ownership transfer. Keep the caller-side cleanup with [UID:0000L3][MapPane](by-file/MapPane.md).

## Static Pool Definition Support

- Source definition: [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) emits `static PoolAllocator g_flyingObjectPanePool(0x144, 4);` through this class and [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) into `NexusTK/map/ItemObjectPane.cpp`.
- Storage/type evidence: the 2026-07-12 B002 evidence-session MCP calls returned all forty target bytes as `00` in writable `.data`. [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) accounts for the complete `0x28` object as block size, blocks-per-chunk, chunk/free-list pointers, and `CRITICAL_SECTION`; this is a PoolAllocator object rather than raw authored bytes.
- Startup route: compiler wrapper `0x0041a0a0-0x0041a0bd` constructs this pool with direct constants `(0x144, 4)` and registers cleanup `0x0060c350` with `_atexit`.
- Allocation route one: `0x0050dfa0-0x0050e0f7` allocates from this pool and calls this class constructor at `0x0050e09b`.
- Allocation route two: `0x00512d60-0x00512f1c` allocates from this pool and calls the same constructor at `0x00512ebe`.
- Constructor-failure route: compiler EH wrapper `0x00514ba0-0x00514bde` returns failed objects to this pool; two EH references associate that one wrapper with both allocation/constructor regions.
- Delete route: scalar deleting destructor `0x0053d1a0-0x0053d237` performs class/base teardown and returns ordinary deleted objects to this pool. Its alternate sized-delete branch passes size `0x144` to global delete, corroborating this class's allocation size.
- Shutdown route: registered wrapper `0x0060c350-0x0060c35a` destroys this exact PoolAllocator. Exact xrefs and independent target-pointer byte search find these six routes and no hidden seventh use.
- Source name/linkage: `g_flyingObjectPanePool` and file-local `static` are descriptive, highest-probability reconstruction based on [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), accepted neighboring pool definitions, internal references, and consumer-module placement. No preserved global symbol proves exact original spelling or storage class, so the target remains capped at `93` confidence.
- Compiler/generated disposition: do not hand-author the startup, cleanup, EH wrapper, scalar deleting-destructor ABI glue, or raw storage. The concrete pool definition and this class's destructor semantics regenerate those binary artifacts; generated ItemObjectPane.cpp should contain one UID0002WT definition and no UID0002WT Empty Emitter Marker.
- Rejected alternatives: PoolAllocator.cpp owns shared allocator mechanics, not this instance; MapPane owns caller-side creation/update flows, not FlyingObjectPane source; [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md) is a non-emitting mixed aggregate across consumer modules; a raw byte array would discard the proven PoolAllocator type and generated static-lifecycle behavior.
- Historical correction: older target text treated sampled all-`ff` bytes and below-gate assignment as current. The zero-byte evidence collected on 2026-07-12, target `88/93`, this class `85/88`, file root `86/88`, and populated owner/emitter route supersede those assumptions while retaining them as labeled provenance in the target history.

## Assignment Gate

- Child score after the Batch 089 refresh: `COMPLETION:85`, `CONFIDENCE:88`.
- Direct proposed parent: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), refreshed in the same batch to `COMPLETION:85`, `CONFIDENCE:86`.
- Assignment decision: `AUTOGEN_PARENT_UID:0000KG` is justified because `ItemObjectPane.cpp` owns the item-shaped map-object source module, this class is the temporary flying/thrown item companion to [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), and both child and direct parent satisfy the corrected `85/85` gate.
- Final C++ remains blank because motion field names, packet/update helper names, and exact final source declarations are not yet final-audit quality.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:0003HV][0x00537cb0-0x00537d60.FlyingObjectPaneConstructor](by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md)
- [UID:0003HX][0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect](by-memory/0x00537d80-0x00537f1d.FlyingObjectPaneGetBoundingRect.md)
- [UID:0003HY][0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick](by-memory/0x00537f20-0x005380af.FlyingObjectPaneOnAnimationTick.md)
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved `85/88`, UID0000KG owner/emitter, reconstructable true, blank position/formal, and all motion/pool evidence.
  - Added the exact eight-entry RTTI inheritance chain, inherited item/palette fields, ItemObjectPane destructor route, primary `0x006204f8` RenderFrame reuse, exact helper behavior, and no-duplicate-body disposition.
  - No partial Flying class declaration or independent RenderFrame body was added.
- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: temporary thrown-item pane role, constructor, bounds, animation tick, destructor, and key caller evidence are documented with strong confidence; remaining work is deeper layout naming and final C++ reconstruction. Evidence: documented address cluster `0x00537cb0-0x005380af`, destructor `0x0053d1a0-0x0053d237`, IDA constructor xrefs, and ItemObjectPane/MapPane cross-references.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving this temporary item-flight map object unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `76/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x00537cb0`, `0x00537d80`, `0x00537f20`, and `0x0053d1a0`, with constructor callers from `0x0050e09b` and `0x00512ebe` in MapPane-side update paths.
- 2026-06-07 Batch 089 parent-gate refresh:
  - Before: `COMPLETION:76`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID` blank.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID:0000KG`.
  - Summary/evidence: pulled in the current item/flying executable audit, exact FlyingObjectPane vtable-store evidence, destructor-island support, and exact pool-storage evidence. [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) was refreshed to `85/86`, satisfying the direct-parent side of the corrected gate; C++ remains blank under the final-source gate.
- 2026-06-10 B001-035 vtable split update:
  - What existed before: vtable references pointed at the former broad mixed Static/Item/Flying/Attached data group.
  - Changed to: references now point at exact [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md).
  - Evidence: fresh IDA MCP identifies `0x00620498-0x00620544` as the exact `FlyingObjectPane` RTTI/vtable range.
- 2026-07-07 B006 UID00034Z marker support sync:
  - Metadata remains `85/88`; no class-level formal C++ was added.
  - Summary/evidence: [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) is regenerated from the `FlyingObjectPane` class declaration, virtual methods, scalar destructor/adjusted thunks, and the [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) source module. Current MCP session `supervisor-nexustk-20260707` reconfirmed the exact range, RTTI/vtable bases, constructor stores, adjusted thunks, predecessor `ItemObjectPane` boundary, successor `AttachedObjectPane` boundary, and no raw authored table requirement.
- 2026-07-12 B002 UID0002WT pool-definition support sync:
  - Class metadata remains `85/88`, owner/emitter [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) unchanged, and the broad class formal C++ block remains blank because final motion fields and method declarations are outside this narrow callback.
  - UID0002WT now emits the file-local PoolAllocator definition with direct `(0x144, 4)` constants. MCP session `545b4991`, used during B002 evidence collection on 2026-07-12, returned forty zero bytes and corroborated the exact `0x28` layout, startup construction, two allocation-plus-constructor routes, shared EH free, scalar-delete free, and registered shutdown destruction. This is a time-scoped evidence record, not a present session-health claim.
  - `g_flyingObjectPanePool` and `static` remain descriptive rather than original-symbol proof. Compiler wrappers/raw storage remain generated support; PoolAllocator.cpp, MapPane.cpp, and the mixed aggregate remain rejected as direct emitters.
