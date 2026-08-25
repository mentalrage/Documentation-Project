*** UID:00006V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/PoolAllocator.h"

class ObjectStatusBlob;

class ItemObjectPane : public ObjectPane
{
public:
    ItemObjectPane(
        int objectId,
        int mapX,
        int mapY,
        short itemId,
        unsigned char paletteFlags);
    virtual ~ItemObjectPane();

    void UpdateItemStatus(const ObjectStatusBlob *status);
    virtual void ClearOutputRects(
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);

protected:
    short m_itemId;                          // +0x128
    unsigned char m_paletteFlags;            // +0x12a
};

typedef char ItemObjectPaneSizeMustBe300[
    sizeof(ItemObjectPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemObjectPane

## UID0003HT Source-Ready ClearOutputRects Integration - 2026-07-16

- The complete position-10 declaration above now uses the exact source roles `paneBounds` and `objectDataBounds` for the inherited `ClearOutputRects` override. This is a parameter-name-only ABI refinement; constructor, destructor, `UpdateItemStatus`, `RenderFrame`, fields, size guard, class closure, and `[[CHILDREN]]` remain unchanged.
- [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) is source-ready at `92/94`, owner/emitter UID00006V, reconstructable true, blank position, and `Nested:0`.
- Exact body order is: read `short m_itemId` at `+0x128`; call `g_pItemObjImageLib->GetItemGlyphBounds(m_itemId, paneBounds)`; normalize with `OffsetRect(-left,-top)`; center normalized `right/bottom` in signed-short 48x48 tile dimensions; copy `*paneBounds` to `*objectDataBounds`.
- Exact executable proof is `[0x00537bf0,0x00537c65)`, 117 bytes, 48 instructions, one basic block, SHA256 `43F9407A1A5C0C7AE554699CE331899373557B535355EBDEA6DF353B3B98DF5C`, zero ordinary callers, and one primary-vtable pointer at `0x00620440` / slot `+0x50`.
- MapPane uses the first output as movement-interpolated pane bounds and the second as base-position object-data bounds; ObjectPane slot `+0x2c` consumes them as `SetBounds(paneBounds, objectDataBounds)` and forwards the optional second rectangle to `SetObjectData`.
- The source return is void. Final output-pointer `EAX`, virtual dispatch, signed divide lowering, `movups`, vptr data, and adjacent `0xcc` bytes are compiler/linker effects, not handwritten source.
- Historical `BuildCenteredItemRect`, generic first/second outputs, and clip/dirty interpretations remain searchable only as superseded aliases. No null/singleton/result guard, local temporary, SIMD intrinsic, raw vtable call, or duplicate FlyingObjectPane override is introduced.
- Executed UID0003HQ/HR/HS/HU constructor/destructor/status/render content, both item/flying pools, vtable/scalar coverage, MapPane factories, and all unrelated current evidence remain preserved at same-or-greater detail.

## UID0003HQ Source-Ready Constructor Integration - 2026-07-16

- The complete position-10 managed declaration above remains byte-for-byte unchanged. Its five-parameter constructor declaration is implemented by [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md), now source-ready at `92/94`.
- UID0003HQ is exactly `[0x00537b40,0x00537b91)`, 81 bytes, 23 instructions, one basic block, and SHA256 `6A65B7BD3741F63170B4CFC1A17F113A25EF2680CF9D5B6854C4BCE532CC911D`. Its sole caller is MapPane's typed factory call at `0x00505e8f`; its sole callee is the ObjectPane constructor at `0x005372d0`.
- Exact source definition:
  - `ItemObjectPane::ItemObjectPane(int objectId, int mapX, int mapY, short itemId, unsigned char paletteFlags)`;
  - base initializer `ObjectPane(0, objectId, mapX, mapY)`;
  - body assignments `m_itemId = itemId` and `m_paletteFlags = paletteFlags`.
- The source signature matches this class's exact extension layout: `short m_itemId` at `+0x128`, `unsigned char m_paletteFlags` at `+0x12a`, and exact total size `0x12c`. UID0003HS writes the same fields, and UID0003HU consumes them.
- Numeric base type `0` is the accepted constructor-family spelling and maps to current `kObjectPaneTypeItem`. Symbolic enum spelling and primitive member-initializer syntax remain behavior-identical lexical alternatives, not additional definitions.
- Source/compiler separation is exact:
  - MapPane's `g_itemObjectPanePool` allocation and the `0x00514c20` constructor-failure cleanup are ordinary-new/compiler lowering;
  - hidden return-this in `EAX` is constructor ABI;
  - stores to primary/EventHandler/TimerHandler vtable views are compiler-generated;
  - scalar delete flags, pool return, RTTI, vtable arrays, adjusted thunks, and size guards remain covered by UID000385/UID00034Y/UID0002WS rather than handwritten class methods.
- The seven-byte predecessor and fifteen-byte successor `0xcc` spans remain compiler alignment in `by-memory/-ignored.md`; no padding field or source statement is added.
- Source order is constructor, explicit empty ordinary destructor, `UpdateItemStatus`, `ClearOutputRects`, and `RenderFrame`, followed by FlyingObjectPane. This class declaration continues to emit one class shell and receives child bodies only through `[[CHILDREN]]`.
- Historical blank-constructor, 95/95-entry-gate, generic variant-state, and unresolved-base/field statements are superseded. MapPane ownership, aggregate emission, explicit vptr/pool/EH source, duplicate class bodies, and handwritten ABI wrappers remain rejected.
- Current UID0003HR empty destructor, UID0003HS status update, UID0003HU RenderFrame/Flying reuse, vtable family, file-static pool, factory routes, size guard, fields, class closure, and every unrelated B001/B005/family fact remain unchanged.

## UID0003HU Source-Ready RenderFrame Integration - 2026-07-16

- The complete position-10 managed declaration above is preserved exactly. Its `virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);` declaration is implemented by [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md), now source-ready at `92/94`.
- UID0003HU is the exact half-open `[0x00537c70,0x00537ca2)` ordinary virtual body, owner/emitter UID00006V, reconstructable true, blank position, and `Nested:0`. It calls `g_pItemObjImageLib->DrawItemImage(target, bounds, m_itemId, m_paletteFlags, 0, 0.0f)` and ignores the helper's `int` status.
- Source return is `void`: the ObjectPane primary `+0x5c` contract and all live MapPane virtual callers are void. The machine leaves the final helper result in `EAX`, but this body adds no result handling or return expression.
- The method consumes this class's exact `short m_itemId` at `+0x128` and `unsigned char m_paletteFlags` at `+0x12a`. Constructor and UID0003HS writes, `0x12c` size, helper argument widths, and generated layout remain consistent.
- ItemObjectPane primary-vtable cell `0x0062044c` and FlyingObjectPane primary-vtable cell `0x006204f8` both point to UID0003HU. Flying RTTI lists `FlyingObjectPane`, `ItemObjectPane`, `ObjectPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`, proving ordinary direct inheritance through ItemObjectPane.
- FlyingObjectPane inherits the fields and this exact RenderFrame body. No Flying override, duplicate definition, raw vtable array, thunk, scalar wrapper, or compiler teardown body is added.
- Logical source order remains constructor, explicit empty ordinary destructor, `UpdateItemStatus`, `ClearOutputRects`, `RenderFrame`, then FlyingObjectPane children. Existing destructor, status, pool, vtable, factory, layout, and FlyingObjectPane evidence is preserved without compression.
- Historical `ProcessItemAction` and `BuildCenteredItemRect` are retained only as superseded descriptive aliases. Accepted source-facing names are `RenderFrame` and `ClearOutputRects`.

## UID0003HS Source-Ready UpdateItemStatus Integration - 2026-07-16

- The complete position-10 managed declaration already contains `void UpdateItemStatus(const ObjectStatusBlob *status)` and remains byte-for-byte unchanged with the exact `0x12c` layout, constructor, virtual overrides, fields, size guard, class closure, and `[[CHILDREN]]`.
- Exact implementation child [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md) is source-ready at `92/94`, owner/emitter UID00006V, blank position, and `Nested:0`.
- The method is exactly 41 bytes with SHA256 `7B145A9792807D0647D01512FB8A89BBF5445077F24B0D3BA9B5B845C8D9852F`; its sole UID0003TT caller reaches it only from the item type-zero branch when incoming appearance id is at least `0xc000`.
- Source behavior copies `ObjectStatusBlob::m_appearanceId` to `m_itemId`, copies `m_variantOrPalette` to `m_paletteFlags`, and calls `g_activeMapPane->UpdateObjectPaneScreenBounds(this)` with no added guard, normalization, result handling, or return value.
- The two writes match exact class offsets `+0x128/+0x12a`, constructor/render state, and the existing declaration. ObjectStatusBlob and MapPane remain dependency/source owners; no duplicate record type, raw field accessor, or class-layout change is introduced.
- Historical LivingObjectPane adjacency/misownership, generic record-state wording, and blank-body blocker claims are superseded. The explicit empty ordinary destructor, inherited bounds/render overrides, primary/EventHandler/TimerHandler vtable family, file-static pool, scalar/compiler separation, exact child order, and all FlyingObjectPane evidence remain unchanged.

## UID0003TX Complete Ground-Item Declaration Integration - 2026-07-16

- The class now emits one complete source-era declaration at position `10`: `ItemObjectPane : public ObjectPane`, exact size `0x12c`, inherited base ending at `+0x128`, `short m_itemId` at `+0x128`, `unsigned char m_paletteFlags` at `+0x12a`, one implicit tail byte, size guard, and `[[CHILDREN]]`.
- The exact constructor ABI is `(int objectId, int mapX, int mapY, short itemId, unsigned char paletteFlags)`. UID0002QN calls this order after detaching an old object; ordinary `new` is the source statement while pool acquisition and constructor-failure return are lowering.
- `UpdateItemStatus(const ObjectStatusBlob *)` is the source identity for UID0003HS. UID0003HT is the inherited `ClearOutputRects(RectBounds *, RectBounds *)` override, and UID0003HU is the inherited `RenderFrame(GrafPort *, const RectBounds *)` override. Historical `BuildCenteredItemRect` and `ProcessItemAction` remain descriptive aliases only and are superseded as accepted declarations.
- UID0003HQ/HR/HS/HT/HU retain their exact ranges, owners, and single-emitter routes; this declaration does not duplicate child-owned bodies. Logical/address order remains constructor, ordinary destructor, status update, bounds override, render override. Still-empty children may appear later in the generator's separate diagnostic Empty Emitter Marker group.
- The ordinary destructor is declared once; vptr restoration, adjusted views, scalar deleting flags, ObjectPane cleanup lowering, storage-size guard, and pool return remain compiler-generated/non-emitting. UID00034Y remains covered-by ABI data, and UID0002WS remains the sole pool static definition.
- Existing pool evidence remains exact: file-static `PoolAllocator(sizeof(ItemObjectPane), 8)`, allocation into the constructor, failure cleanup, scalar-delete return, and static teardown. The complete `0x12c` class declaration and active size guard prove the `sizeof` expression preserves the wrapper's literal `0x12c`; no pool call is added to a source method.
- MapPane's item factory resolves `ItemInfo::lightImageIndex` and attaches lighting separately; ItemObjectPane stores only item id and palette flags. FlyingObjectPane remains a same-file companion with independent fields, methods, vtable, and pool storage.
- Historical blank-class, unresolved-field/helper/virtual-order, and final-C++ blocker wording below is preserved as superseded provenance. The complete declaration and exact child inventory now justify `92/94`.

## B001 UID0003HR Destructor Source Closure - 2026-07-16

- [UID:0003HR][0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor](by-memory/0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor.md) now supplies the exact source-authored out-of-line definition:
  - `ItemObjectPane::~ItemObjectPane()`
  - empty body;
  - automatic reverse base destruction only.
- The existing formal declaration above remains complete and unchanged: one `virtual ~ItemObjectPane();` declaration in source order, exact fields/layout, size assertion, and `[[CHILDREN]]`.
- Evidence-time MCP session `64c11373` reconfirmed the target's exact `0x1f` body, three fixed vptr stores, tail transfer to the pure ObjectPane ordinary destructor, zero direct/pointer routes, and byte-identical FlyingObjectPane ordinary lowering.
- The `+0xa0` EventHandler and `+0xa4` TimerHandler views are fixed interface subobjects, not virtual bases. No vbptr/vbtable or dynamic virtual-base adjustment belongs in this declaration.
- [UID:000385][0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor](by-memory/0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor.md) is compiler-generated coverage at `90/94`: primary/adjusted virtual-delete routes, flags `1`/`4`, guarded size `0x12c`, ObjectPane teardown, and pool return are not handwritten class methods.
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) is source-declared/generated-binary coverage at `90/94`; its existing marker and exact RTTI/vtable boundaries remain intact.
- UID0002WS remains the sole file-static pool definition. Constructor allocation, failure cleanup, scalar deletion, and registered static teardown establish the source/compiler boundary without adding allocation calls to the destructor.
- The destructor closes the targeted class source-shape blocker without changing constructor, status-update, bounds, render, field, factory, FlyingObjectPane, or pool evidence.
- Current generated placement of the UID0003HQ/UID0003HS diagnostic markers after filled source and coverage blocks is not source-order evidence and does not justify artificial child positions or implementation outside their own callbacks.

## Status

- Confidence: very strong for the complete declaration/layout, source placement, method anchors, explicit empty ordinary destructor, vtable ownership, scalar/compiler separation, and pool-backed allocation/deletion.
- Direct source file: [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- Assignment gate: this class is `92/94` and the direct file parent is `91/93`, so `AUTOGEN_PARENT_UID` remains `0000KG`.
- Final class C++ is the complete managed declaration above. The ordinary destructor source expression is resolved by UID0003HR; exact child bodies remain child-owned and are inserted through `[[CHILDREN]]`.
- Concrete pool definition: [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) independently emits `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` in this class's source module; the formal H channel remains blank because the storage is file-local.

## Class Purpose

`ItemObjectPane` represents a static item object on the map. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), stores the item graphic/variant fields, centers item glyph bounds in a map tile, and dispatches item-image rendering.

It is the ground-item half of the item-object source module documented by [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md). The paired [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) class covers temporary thrown/flying item behavior, while this class owns the static map item constructor, item glyph centering, item-image RenderFrame dispatch, `ItemObjectPane` vtable family, and item pool-backed scalar deleting destructor.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md) | Builds the `ObjectPane` base for an item object and stores item graphic/flag state. |
| ordinary destructor | [UID:0003HR][0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor](by-memory/0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor.md) | Emits an explicit empty out-of-line `ItemObjectPane::~ItemObjectPane()` body; observed vptr restoration and ObjectPane teardown are compiler lowering. |
| `UpdateItemStatus` | [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md) | Source-ready `void UpdateItemStatus(const ObjectStatusBlob *)`; sole UID0003TT type-zero/high-item caller, exact appearance/palette stores, active MapPane screen-bounds refresh, no extra guard/return, and historical LivingObjectPane correction. |
| `ClearOutputRects` | [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) | Produces normalized, tile-centered pane bounds and matching object-data bounds from `m_itemId`; historical `BuildCenteredItemRect` is superseded. |
| `RenderFrame` | [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) | Source-ready void override forwarding target, const bounds, `m_itemId`, `m_paletteFlags`, null overlay, and zero strength to `g_pItemObjImageLib->DrawItemImage`; inherited by FlyingObjectPane with no duplicate body. |
| scalar deleting destructor | [UID:000385][0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor](by-memory/0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor.md) | Compiler-generated virtual-delete coverage with primary/adjusted routes, flags, guarded size, ObjectPane teardown, and conditional pool return; no handwritten wrapper body. |

## Evidence Notes

- `MapPane::CreateOrUpdateObjectPane` at `0x00505e00` constructs `ItemObjectPane` for decoded item object state.
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) is now a non-emitting split index; exact ItemObjectPane method children [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md) through [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) carry the source ownership, MapPane caller evidence, item-image/tile callees, and padding boundary before FlyingObjectPane.
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) records the exact RTTI pointer and three `ItemObjectPane` vtable views at `0x006203f0`, `0x00620460`, and `0x00620490`.
- 2026-06-29 B013 current MCP support for [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md): active session `agent_b009_0002my_20260628` with server health OK reconfirmed the `0xac`-byte `ItemObjectPane` RTTI/vtable child, vptr stores in the constructor/non-deleting destructor/scalar deleting destructor, adjusted destructor thunks `0x0053cf12` and `0x0053cf1d`, and exact boundaries between the `StaticObjectPane` and `FlyingObjectPane` vtable children. The child now emits a generated-binary marker covered by this class declaration and methods rather than raw vtable arrays or a standalone `.rdata` source body.
- [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) records the exact `0x0053d2e0-0x0053d377` scalar deleting destructor, object-pane cleanup call, adjusted vtable references, and `byte_69B9AC` pool-free gate.
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) records the zero-filled `0x28`-byte static `PoolAllocator` storage, block size `sizeof(ItemObjectPane) == 300 / 0x12c`, chunk count `8`, startup/cleanup wrappers, five direct construction/allocation/free/cleanup xrefs, and formal file-local definition `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);`.
- The pool child is source-bearing: its definition belongs in `NexusTK/map/ItemObjectPane.cpp`, while the observed zero bytes, startup wrapper, `atexit` registration, and cleanup wrapper are compiler/linker-generated consequences. The broad object-pane pool aggregate and wrapper pages remain non-emitting support.
- Current database `5a570ede` resolves the pool as one `[0x0069b9ac,0x0069b9d4)` 40-byte `struct PoolAllocator g_itemObjectPanePool` data item with exact regular/repeatable storage comments. Catalog entry `0350` confirms forty unchanged zero bytes, the five exact base xrefs, no checked interior xrefs or item heads, and preserved startup/allocation/unwind/scalar-delete/cleanup semantics.
- `FlyingObjectPane` is a close companion for temporary thrown/flying item behavior and belongs in the same source module, but its constructor, animation methods, vtable data, and pool storage stay documented on the flying class and exact memory pages.

2026-06-11 A004 live IDA MCP refresh:

- `py_eval` confirms the ground item anchors remain modeled as `sub_537B40` (`0x00537b40-0x00537b91`), `sub_537BF0` (`0x00537bf0-0x00537c65`), `sub_537C70` (`0x00537c70-0x00537ca2`), and scalar deleting destructor `sub_53D2E0` (`0x0053d2e0-0x0053d377`).
- The same live check reconfirms the constructor caller `0x00505e8f` in `sub_505E00`, vtable-store refs to `0x006203f0`, `0x00620460`, and `0x00620490`, and destructor data/code refs through `0x006203f0`, `0x0053cf18`, and `0x0053cf23`.
- Historical 2026-06-11 state: the exact pool-storage child was then `85/91` and assigned to this class. That score was not below the gate used by that pass; it averaged `88.0`. The child later reached `88/93` and emitted its formal pool definition. The former separate class-level C++ blocker is now superseded by the complete declaration and UID0003HR destructor source.

2026-07-12 B004 evidence-time pool-definition synchronization:

- Evidence-time MCP session `cfa0ae1a` confirmed forty zero input-image bytes at `0x0069b9ac-0x0069b9d4`, constructor wrapper `0x0041a0e0` calling the allocator constructor with `(300, 8)`, and cleanup wrapper `0x0060c370` destroying the same allocator.
- The five direct base xrefs are `0x0041a0e7`, `0x00505e66`, `0x00514c45`, `0x0053d330`, and `0x0060c370`. They cover startup construction, allocation, constructor-failure free, scalar-delete free, and static cleanup.
- In `sub_505E00`, allocation from this pool is immediately followed by the `sub_537B40` ItemObjectPane constructor. The `sub_53D2E0` scalar deleting destructor returns ordinary deleted objects to the same pool and corroborates the `0x12c` object size.
- `g_itemObjectPanePool` and file-local `static` are descriptive reconstruction rather than recovered original spelling/linkage. B004's numeric `0x12c` choice was correct for its then-current class state; the completed class declaration and size guard now supersede that blocker and support `sizeof(ItemObjectPane)` without changing behavior.

2026-07-28 B008 supplemental pool-definition synchronization:

- UID0002WS now emits `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` at `92/94`. This class remains `92/94` with the complete declaration, fields, methods, size guard, owner/emitter route, formal code, and all unrelated evidence unchanged.
- The exact `sizeof(ItemObjectPane) == 0x12c` guard ties the human-source pool definition to the same literal block size pushed by startup wrapper `0x0041a0e0`; the generated zero bytes, startup/cleanup wrappers, EH free, and scalar pool return remain compiler/runtime consequences rather than class methods.
- Current name/type/materialization evidence is cross-referenced to UID0002WS. Supervisor Gate 2B A00-A07 is now applied and saved: opaque `PoolAllocator` ordinal `444` is unchanged; already-present `PoolChunkHeader`/`PoolFreeBlock` ordinals `934/935` are unchanged; the pool item/comments are exact; five allocator helper names/types/function-regular comments are restored; and `PoolAllocator_Allocate` remains no-change.
- Persistent type application normalized only physical argument-frame labels for constructor A02 (`blockSize`, `blocksPerChunk`), free A04 (`block`), and chunk allocator A06 (`chunkListHead`, `blocksPerChunk`, `blockSize`). Supervisor stack-rename dry-run rejected raw-name restoration with literal `Argument member`; Hex-Rays names/types, calling conventions, offsets, widths, nonargument frame members, A05/A07 frames, bytes, xrefs, ranges, and protected internal comments remain exact.

## Score Rationale

- Completion remains `92` because the managed declaration already resolves the exact class size, fields, constructor signature, ordinary destructor declaration, status-update method, inherited bounds/render overrides, size assertion, and child insertion point. Exact method bodies remain owned by their by-memory children.
- Confidence rises from `93` to `94` because UID0003HR now resolves the ordinary destructor source as an explicit empty out-of-line definition, current target evidence closes the fixed interface-view/base-teardown route, and UID000385/UID00034Y provide exact compiler coverage without duplicate source.
- Confidence remains below 95 because no PDB or original header proves exact repeated `virtual` keyword use, exact original header filename, or all original lexical spelling. These do not block behavior, layout, ownership, emitter routing, or the accepted formal declaration.

## Historical / Superseded Assumptions

- Earlier Status and score-rationale text said the class formal C++ was blank and field layout, signatures, virtual order, and destructor source remained unresolved. The UID0003TX complete declaration and UID0003HR accepted body supersede those current-facing conclusions.
- Historical `74/86`, `85/88`, `86/89`, blank-class, below-gate, and generic final-C++ blocker states remain in the Changes chronology only.
- Earlier pool-support text correctly avoided adding pool calls to source methods, but its "blank class-level formal" conclusion is superseded. UID0002WS remains the only pool definition and the destructor remains empty.
- Earlier prose described `+0xa0/+0xa4` view restoration without resolving whether it was virtual inheritance. Current evidence identifies fixed EventHandler/TimerHandler interface subobjects and rejects vbptr/vbtable semantics.
- Historical helper aliases `BuildCenteredItemRect` and `ProcessItemAction` remain superseded descriptive names; the accepted declarations remain `ClearOutputRects` and `RenderFrame`.

## Cross-References

- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md)
- [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md)
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md)

## Changes

- 2026-07-16 B005 UID0003HT source-quality callback:
  - Preserved `92/94`, UID0000KG owner/emitter route, exact `0x12c` layout, executed constructor/destructor/status/render content, pools, vtables, scalar/compiler separation, and FlyingObjectPane union.
  - Applied the accepted complete formal block by changing only `ClearOutputRects` parameter names to `paneBounds` and `objectDataBounds`.
  - Added exact target behavior, range/hash/CFG/vtable/output-role/helper/global/source-compiler evidence and historicalized `BuildCenteredItemRect`/clip-dirty aliases.
- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved `92/94`, owner/emitter UID0000KG, position `10`, exact `0x12c` layout, and the complete managed declaration byte-for-byte.
  - Synchronized the validator-renamed UID0003HU RenderFrame link, exact body/helper/void-return/field/vtable/source-order facts, direct FlyingObjectPane inheritance, inherited one-body reuse, negative evidence, and historical alias rejection.
  - Preserved all UID0003HS, destructor, pool, vtable, factory, layout, and unrelated FlyingObjectPane content.
- 2026-07-16 Agent-B005 UID0003TT callback:
  - Preserved `92/94`, owner/emitter UID0000KG, position `10`, exact `0x12c` layout, and the complete managed declaration byte-for-byte.
  - Added the source-ready UID0003HS body/caller/gate/route facts, exact fields and active MapPane refresh, no-extra-guard behavior, and historical LivingObjectPane correction without changing destructor, vtable, pool, child, or FlyingObjectPane content.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: static map item-object role, constructor, centered glyph bounds, action/render delegation, destructor, MapPane creation anchor, and companion FlyingObjectPane relationship are documented with strong confidence; remaining work is field naming and final C++ body reconstruction. Evidence: `ItemAndFlyingObjectPanes`, `FlyingObjectPane`, `ObjectPane`, and MapPane constructor caller note.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the static item-object map pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `74/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x00537b40`, `0x00537bf0`, `0x00537c70`, and `0x0053d2e0`, with constructor caller `0x00505e8f` in the MapPane object-creation path.
- 2026-06-10 A002 strict-gate refresh:
  - Before: `74/86`, `AUTOGEN_PARENT_UID` blank, and the status still depended on generated-source provenance.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000KG`, final C++ still blank.
  - Summary/evidence: the file parent [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) is now `85/86`; the class page now records exact executable child evidence, the exact `ItemObjectPane` vtable-data child [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md), destructor-island support for `0x0053d2e0-0x0053d377`, and pool-static-storage evidence for `0x0069b9ac-0x0069b9d4`. This clears the corrected child/direct-parent `85/85` gate while keeping code emission gated by unresolved field/helper names.
- 2026-06-11 A004 Batch 173 evidence refresh:
  - Before: `85/88`, assigned to [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md).
  - After: `86/89`, same direct file parent.
  - Summary/evidence: live IDA MCP reconfirmed the constructor/helper/destructor ranges, constructor caller, vtable refs, and exact pool xrefs. The associated exact pool-storage page [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) now clears `85/91` and is assigned to this class, so the class evidence chain no longer relies on a below-gate pool child.
- 2026-06-29 B013 vtable marker support sync:
  - Metadata and class formal C++ remain unchanged.
  - Summary/evidence: accepted UID00034Y implementation uses current MCP session `agent_b009_0002my_20260628` to reconfirm the exact `0x006203ec-0x00620498` `ItemObjectPane` RTTI/vtable child and records that the child now emits a generated-binary marker under this class rather than raw arrays.
- 2026-07-12 B004 UID0002WS pool-definition support sync:
  - Metadata and the blank class-level formal C++ remain unchanged at `86/89`; no unrelated class code or score inflation was applied.
  - The exact pool child is now `88/93` and emits `static PoolAllocator g_itemObjectPanePool(0x12c, 8);` through this source module. Current MCP confirms zero-filled `0x28` storage, exact `(0x12c, 8)` construction, five liveness xrefs, allocation into the ItemObjectPane constructor, and scalar-delete return to the same pool.
  - Replaced obsolete blanket `95/95` gate wording with the actual unresolved class-layout/helper/virtual/destructor source-shape limitations. Original pool name/linkage and declaration order remain explicitly unproven.
- 2026-07-28 B008 UID0002WS supplemental support sync:
  - Preserved class `92/94`, owner/emitter UID0000KG, position `10`, complete class declaration, size guard, child routes, and all unrelated method/vtable/FlyingObjectPane evidence.
  - Synchronized the sole pool definition to `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);`; the guard proves exact `0x12c` behavior while formal H remains blank for file-local storage.
  - Recorded the pre-Gate2B `g_itemObjectPanePool` / `struct PoolAllocator` and forty-partition materialization handoff. That pending state is superseded by the applied entry below.
- 2026-07-29 B008 UID0002WS supervisor Gate 2B reconciliation:
  - Catalog entry `0350` materialized the exact 40-byte `g_itemObjectPanePool` item/comments and restored the five shared allocator helper identities/types/function-regular comments while preserving A00 type state and A03 `PoolAllocator_Allocate`.
  - Preserved all target bytes, five base xrefs, ranges, wrappers, neighbors, ABI, nonargument frames, and internal comments. The bounded A02/A04/A06 physical argument-frame normalization and literal `Argument member` rename-stack rejection are analysis presentation only.
  - Saved IDB SHA256 is `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`; prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64` has SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.
- 2026-07-16 B001 UID0003HR accepted callback:
  - Kept completion `92`, raised confidence from `93` to `94`, and preserved owner UID0000KG, reconstructable true, emitter UID0000KG, position `10`, and the complete formal declaration byte-for-byte.
  - Added the explicit empty UID0003HR ordinary destructor source, exact base/scalar/vtable/compiler separation, fixed EventHandler/TimerHandler view semantics, source order, negative evidence, and score rationale.
  - Historicalized the stale blank-class, unresolved-destructor, virtual-inheritance, and lower-score statements without removing their provenance.
