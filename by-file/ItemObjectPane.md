*** UID:0000KG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ItemObjectPane

## UID0003HT ClearOutputRects Source Route - 2026-07-16

- `NexusTK/map/ItemObjectPane.cpp` now receives exactly one [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) definition as `void ItemObjectPane::ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds)`.
- The body reads `m_itemId`, obtains glyph bounds through the public nonvirtual `g_pItemObjImageLib->GetItemGlyphBounds` member, normalizes pane bounds to origin, centers normalized right/bottom extents in signed-short 48x48 tile dimensions, then copies pane bounds to object-data bounds.
- Exact child proof remains child-owned: `[0x00537bf0,0x00537c65)`, 117 bytes, 48 instructions, one basic block, SHA256 `43F9407A1A5C0C7AE554699CE331899373557B535355EBDEA6DF353B3B98DF5C`, zero ordinary callers, and one ItemObjectPane primary-vtable pointer at `0x00620440` / slot `+0x50`.
- Source order is complete and singular: UID0003HQ constructor, UID0003HR explicit empty ordinary destructor, UID0003HS `UpdateItemStatus`, UID0003HT `ClearOutputRects`, UID0003HU `RenderFrame`, then FlyingObjectPane content. The complete UID00006V class shell remains singular and child bodies remain child-owned.
- MapPane consumes the two outputs as movement-interpolated pane bounds and base-position object-data bounds. ObjectPane `SetBounds` updates pane geometry from the first and forwards the optional second to `SetObjectData`.
- Source return is void and the body has no null, singleton, resource-result, empty-rect, or clamp guard. Vtable dispatch, signed divide lowering, final `movups`, incidental output-pointer `EAX`, and adjacent padding are compiler/linker effects.
- Historical `BuildCenteredItemRect`, generic first/second output names, clip/dirty semantics, free glyph helper, useful return, raw ABI, and SIMD-source alternatives are superseded or rejected.
- UID0000KG remains prose-only at `91/93`, path `NexusTK/map/`, with no by-file reconstruction metadata. Executed UID0003HQ/HR/HS/HU, both pools, factories, vtables, scalar wrappers, FlyingObjectPane union, and all unrelated current content remain preserved.

## UID0003HQ Constructor Source Route - 2026-07-16

- `NexusTK/map/ItemObjectPane.cpp` now receives exactly one [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md) definition as `ItemObjectPane::ItemObjectPane(int objectId, int mapX, int mapY, short itemId, unsigned char paletteFlags)`.
- The body uses `ObjectPane(0, objectId, mapX, mapY)` and then assigns `m_itemId = itemId` and `m_paletteFlags = paletteFlags`. Numeric object type `0` matches current accepted ObjectPane-derived constructor-family style and the item discriminator.
- Exact target proof remains child-owned: `[0x00537b40,0x00537b91)`, 81 bytes, 23 instructions, one basic block, SHA256 `6A65B7BD3741F63170B4CFC1A17F113A25EF2680CF9D5B6854C4BCE532CC911D`, sole MapPane factory call at `0x00505e8f`, and sole ObjectPane constructor callee.
- Logical source order is compile-complete for this child sequence: complete UID00006V class, UID0003HQ constructor, UID0003HR explicit empty ordinary destructor, UID0003HS UpdateItemStatus, source-ready UID0003HT ClearOutputRects, UID0003HU RenderFrame, then FlyingObjectPane content.
- The constructor is emitted only by UID0003HQ through UID00006V. The complete class shell remains singular, UID0001D7 remains non-emitting, and no class/file/aggregate duplicate constructor is added.
- Compiler/runtime exclusions remain exact:
  - file-static UID0002WS supplies the sole `g_itemObjectPanePool` definition;
  - MapPane allocation and `0x00514c20` failure cleanup are ordinary-new/compiler lowering;
  - vptr stores, hidden return-this, scalar wrapper, RTTI/vtable arrays, adjusted thunks, delete flags, pool return, and padding are not handwritten constructor source.
- The exact seven-byte pre-alignment and fifteen-byte post-alignment remain covered by `by-memory/-ignored.md`. No padding bytes are represented as authored C++.
- Historical blank-constructor, 95/95 gate, generic variant/state, unresolved base/field, MapPane-owner, and pool-wrapper alternatives are superseded or rejected while retained on the child page.
- UID0000KG remains prose-only at `91/93`, path `NexusTK/map/`, and carries no by-file reconstruction metadata. The complete current ItemObjectPane/FlyingObjectPane union, UID0003HR/HS/HT/HU bodies, vtable/scalar markers, two static pools, factory/update routes, and every unrelated B001/B005/family fact remain unchanged.

## UID0003HU RenderFrame Source Route - 2026-07-16

- `NexusTK/map/ItemObjectPane.cpp` now receives exactly one [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) definition as `void ItemObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)`.
- The body forwards `target`, read-only `bounds`, `m_itemId`, `m_paletteFlags`, null overlay, and `0.0f` strength to `g_pItemObjImageLib->DrawItemImage`; its helper status is ignored. There is no branch, guard, state mutation, local rectangle, overlay allocation, result handling, or custom teardown.
- Source return is void despite incidental helper `EAX`: ObjectPane's `+0x5c` slot and current MapPane callers are void. The general DrawItemImage destination contract is const because the complete helper does not write through the rectangle.
- Logical/address source order remains UID0003HQ constructor, UID0003HR explicit empty ordinary destructor, UID0003HS `UpdateItemStatus`, UID0003HT `ClearOutputRects`, UID0003HU `RenderFrame`, then FlyingObjectPane methods. The complete position-10 UID00006V class remains the sole class shell.
- ItemObjectPane primary-vtable cell `0x0062044c` and FlyingObjectPane primary-vtable cell `0x006204f8` both point to UID0003HU. Current eight-entry Flying RTTI proves direct inheritance through ItemObjectPane, so FlyingObjectPane reuses this one body without an override or duplicate definition.
- Exact target range/hash, item/palette field layout, helper/global route, source/compiler boundary, alignment, negative evidence, and superseded `ProcessItemAction` alias remain child-owned at report-level detail.
- UID0000KG remains prose-only at `91/93`, path `NexusTK/map/`, with no by-file reconstruction metadata. Existing UID0003HS, class/destructor, vtable, pool, factory, FlyingObjectPane, and historical content is preserved.

## UID0003HS UpdateItemStatus Source Route - 2026-07-16

- `NexusTK/map/ItemObjectPane.cpp` receives exactly one [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md) definition as `void ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *status)`.
- Logical/address source order remains UID0003HQ constructor, UID0003HR explicit empty ordinary destructor, UID0003HS status update, UID0003HT inherited bounds override, and UID0003HU inherited render override. The complete position-10 UID00006V class declaration remains the sole class shell.
- UID0003HS is exactly 41 bytes with SHA256 `7B145A9792807D0647D01512FB8A89BBF5445077F24B0D3BA9B5B845C8D9852F`; its sole UID0003TT caller reaches it from the item type-zero branch only when incoming appearance id is at least `0xc000`.
- The body copies ObjectStatusBlob appearance and variant/palette into `m_itemId` and `m_paletteFlags`, then refreshes this pane's screen bounds through `g_activeMapPane`. It adds no status/global null guard, result handling, normalization, duplicate record type, or extra return value.
- ObjectStatusBlob.cpp and MapPane.cpp retain dependency/source ownership. Ground-item factory, ItemInfo lighting policy, explicit destructor, class-generated vtables/scalar wrapper, separate item/flying pools, FlyingObjectPane companion union, destructor island, and exact pool-storage pages remain unchanged.
- Historical LivingObjectPane adjacency/misownership and generic record-state/blank-body blockers are superseded. Raw vptr, pool acquisition/free, scalar flags, adjusted thunks, RTTI arrays, register propagation, and tail-call return mechanics remain compiler/runtime output rather than duplicate human source.
- UID0000KG remains prose-only at `91/93`, path `NexusTK/map/`, with no by-file reconstruction metadata. No FlyingObjectPane detail or unrelated current content is compressed or replaced.

## UID0003TX Ground-Item Source Integration - 2026-07-16

- `NexusTK/map/ItemObjectPane.cpp` now has a compile-complete source route: complete position-10 `ItemObjectPane` declaration, exact child-owned source/coverage blocks, and independent ground/flying pool definitions. Logical/address child order remains constructor, ordinary destructor, status update, bounds override, render override; still-empty children are currently listed later in the generator's diagnostic marker group. This by-file root remains prose-only and carries no `RECONSTRUCTION_CPP` metadata.
- Ground-item layout is exact `0x12c`: ObjectPane base through `+0x128`, `short m_itemId` at `+0x128`, `unsigned char m_paletteFlags` at `+0x12a`, and implicit tail padding. Constructor ABI is `(objectId, mapX, mapY, itemId, paletteFlags)` as called by MapPane's corrected factory.
- UID0003HQ/HR/HS/HT/HU remain the sole definitions. Source-facing names are constructor, ordinary destructor, `UpdateItemStatus(const ObjectStatusBlob *)`, inherited `ClearOutputRects(RectBounds *, RectBounds *)`, and inherited `RenderFrame(GrafPort *, const RectBounds *)`; `BuildCenteredItemRect` and `ProcessItemAction` are retained only as superseded descriptive aliases.
- The factory detaches an old object, ordinary-news the class, resolves `ItemInfo::lightImageIndex`, optionally attaches lighting, then follows MapPane's common screen-bounds/ObjectList path. ItemObjectPane itself stores item id/palette flags and does not own ItemInfo lookup or lighting policy.
- Existing `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` and distinct FlyingObjectPane pool remain singly defined. The complete class and exact `sizeof(ItemObjectPane) == 0x12c` guard preserve the startup literal; allocation/free wrappers, startup/cleanup wrappers, vptr stores, scalar-delete flags, size guards, and RTTI/vtable arrays are compiler-generated or exact support-owned, never handwritten duplicate methods.
- FlyingObjectPane remains a same-module companion with its complete stronger class, methods, and pool detail preserved. No ground-item declaration/body replaces or compresses flying-object content.
- Historical blank-class and generic virtual-name blockers are superseded; complete declaration, exact children, factory ABI, pool route, compiler exclusions, and the explicit empty ordinary destructor support `91/93` for this file root.

## B001 UID0003HR Destructor Source Integration - 2026-07-16

- UID0003HR now contributes exactly one source-authored definition to `NexusTK/map/ItemObjectPane.cpp`:
  - `ItemObjectPane::~ItemObjectPane()`
  - empty body;
  - logically/address-ordered after UID0003HQ constructor and before UID0003HS status update; current generated placement of their still-empty diagnostic markers after filled blocks is not source-order evidence.
- The complete position-10 UID00006V class declaration remains unchanged and contains one matching `virtual ~ItemObjectPane();` declaration plus `[[CHILDREN]]`.
- Evidence-time MCP session `64c11373` confirms the ordinary endpoint is exactly `0x00537ba0-0x00537bbf`, restores primary/EventHandler/TimerHandler views, and tail-transfers to the pure ObjectPane ordinary destructor. Those instructions are compiler lowering, not source statements.
- UID000385 is now exact comment-only compiler coverage at `90/94`. Primary/adjusted virtual-delete entry, flags `1` and `4`, guarded size `0x12c`, ObjectPane teardown, and `g_itemObjectPanePool` return remain compiler/runtime output.
- UID00034Y is now `90/94` source-declared/generated-binary RTTI/vtable coverage with its existing marker retained. No raw arrays, thunks, vptr writes, or RTTI data are added to this file's human source.
- UID0001D7 remains a false/non-emitting split index at `90/93`; exact child pages and alignment preserve the ItemObjectPane/FlyingObjectPane union without aggregate duplicate source.
- UID0002WS and UID0002WT remain the sole distinct file-static pool definitions. Their startup/cleanup/EH wrappers and scalar-delete uses stay compiler generated.
- MapPane remains the factory/caller boundary, ObjectPane.cpp owns base teardown, and PoolAllocator.cpp owns shared allocator mechanics. The narrow source root remains this file.
- All current FlyingObjectPane declaration, method, vtable, pool, animation, caller, and historical evidence is preserved unchanged.
- No artificial emitter positions and no UID0003HQ/UID0003HS implementation are introduced to rearrange the generator's temporary diagnostic marker group.

## Status

- Confidence: very strong for ItemObjectPane declaration/layout, explicit ordinary destructor source, exact executable anchors, scalar/vtable/compiler coverage, static pool ownership, MapPane caller boundary, and `NexusTK/map/` placement; medium-high for unrelated remaining FlyingObjectPane field/helper spellings.
- Proposed module: `map/ItemObjectPane.cpp`
- Projected reconstruction path: `NexusTK/map/ItemObjectPane.cpp`
- Primary class docs: [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md), [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- Main address index: [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- Vtable data: [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md), [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- Static pool storage: [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) emits `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);`; distinct [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) emits `static PoolAllocator g_flyingObjectPanePool(0x144, 4);` in this same module.
- Parent gate: this file now clears the corrected `85/85` direct-parent gate for [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) and other independently refreshed item-object children.

## File Role

`ItemObjectPane.cpp` likely owns item-shaped map objects: static ground item panes and the temporary flying/thrown item pane used during launch, impact, and drop flows.

This should stay separate from [UID:0000M5][ObjectPane](by-file/ObjectPane.md). The base file owns common object-pane state; this file owns item image selection, ItemObjectPane RenderFrame dispatch, and item projectile animation.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ItemObjectPane` | source methods `0x00537b40-0x00537ca2`; ordinary destructor `0x00537ba0`; scalar wrapper `0x0053d2e0` | Ground item object with complete declaration, explicit empty ordinary destructor, status/bounds/render methods, and separate compiler-generated scalar deletion coverage. |
| `FlyingObjectPane` | `0x00537cb0-0x005380af`, destructor at `0x0053d1a0` | Temporary flying/thrown item object with arc bounds, timer stepping, impact sound/effects, and drop/removal handling. |
| Item/flying vtable data | `0x006203f0`, `0x00620460`, `0x00620490` in [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md); `0x0062049c`, `0x0062050c`, `0x0062053c` in [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) | Compiler-emitted tables regenerated from the item and flying class declarations, virtual methods, scalar destructor/adjusted thunks, and this source module; UID00034Y and UID00034Z use generated-binary markers instead of raw arrays. |
| Static pools | `0x0069b9ac-0x0069b9d4`, `0x0069b9d4-0x0069b9fc` | Concrete pools stay beside their consumers in this module. UID0002WS defines `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);`; UID0002WT separately defines `static PoolAllocator g_flyingObjectPanePool(0x144, 4);`. Both exact zero-filled storage objects and their startup/cleanup wrappers are compiler-generated consequences of those definitions. |

## ItemObjectPane Pool Definition

- Exact source definition: [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md) contributes `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` to `NexusTK/map/ItemObjectPane.cpp`. Its formal H channel is blank because this is file-local storage, not a public declaration.
- Size/source-shape proof: startup wrapper `0x0041a0e0-0x0041a0fd` pushes block size `0x12c` and chunk count `8`; the complete UID00006V declaration and size guard independently prove `sizeof(ItemObjectPane) == 0x12c`. The `sizeof` form therefore preserves exact execution while expressing the maintainable class/pool relationship a human source file would most likely use.
- Current storage evidence: database `5a570ede` resolves exactly one `[0x0069b9ac,0x0069b9d4)` 40-byte data item as `struct PoolAllocator g_itemObjectPanePool`, with the accepted regular/repeatable comments. All forty bytes remain zero, five base xrefs remain exact, checked interiors have no xrefs or item heads, and this remains one source declaration rather than a split.
- Exact liveness: five direct refs at `0x0041a0e7`, `0x00505e66`, `0x00514c45`, `0x0053d330`, and `0x0060c370` cover startup construction, MapPane allocation followed by the ItemObjectPane constructor, constructor-failure free, scalar-delete free, and registered cleanup. Interior addresses have no refs and do not support field globals or padding children.
- Ownership/source boundary: UID00006V remains the narrow owner/emitter and this UID0000KG page remains the source root. MapPane owns caller/factory behavior, PoolAllocator.cpp owns shared mechanics, and UID0002B4 remains a non-emitting mixed aggregate. Raw bytes, marker-only output, public/header storage, duplicate class-static storage, and handwritten compiler wrappers remain rejected.
- Applied IDA disposition from supervisor catalog entry `0350`: A00 preserves opaque ordinal-444 `PoolAllocator` and already-present ordinal-934/935 `PoolChunkHeader`/`PoolFreeBlock` unchanged; A01 materializes the exact full-range item/comments; A02/A04-A07 restore the five allocator helper names/types/function-regular comments; A03 `PoolAllocator_Allocate` is exact no-change. Function ranges, bytes, xrefs, wrappers, neighbors, and protected internal comments remain exact.
- Typed-signature persistence normalized only physical argument-frame labels for A02 to `blockSize`/`blocksPerChunk`, A04 to `block`, and A06 to `chunkListHead`/`blocksPerChunk`/`blockSize`. A safe rename-stack dry-run rejected raw-label restoration with literal `Argument member`; Hex-Rays names/types, ABI, offsets, widths, nonargument frames, and A05/A07 remain exact.
- Original source spelling, linkage syntax, declaration order, and exact lexical `sizeof` choice remain inferred. These residuals cap UID0002WS at `92/94` without weakening its exact behavior, range, owner/emitter route, or formal source.

## FlyingObjectPane Pool Definition

- Exact source definition: [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md) contributes `static PoolAllocator g_flyingObjectPanePool(0x144, 4);` to `NexusTK/map/ItemObjectPane.cpp` beside the distinct accepted ItemObjectPane pool definition.
- Storage/type evidence collected on 2026-07-12: MCP session `545b4991` returned forty `00` bytes at `0x0069b9d4-0x0069b9fc` inside writable `.data`. [UID:0001VK][PoolAllocatorLayout](by-type/by-struct/PoolAllocatorLayout.md) accounts for all `0x28` bytes as the allocator's block size, blocks-per-chunk, chunk/free-list pointers, and `CRITICAL_SECTION`; do not replace it with raw authored bytes. This records evidence-session results without asserting later session availability.
- Startup construction: compiler wrapper `0x0041a0a0-0x0041a0bd` passes direct constants block size `0x144` / 324 and chunk count `4` to PoolAllocator construction for this object, then registers cleanup `0x0060c350` through `_atexit`.
- First allocation: MapPane-side flow `0x0050dfa0-0x0050e0f7` allocates from this pool and calls [UID:0003HV][0x00537cb0-0x00537d60.FlyingObjectPaneConstructor](by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md) at `0x0050e09b`.
- Second allocation: MapPane-side flow `0x00512d60-0x00512f1c` allocates from this pool and calls the same FlyingObjectPane constructor at `0x00512ebe`.
- Constructor-failure return: compiler EH wrapper `0x00514ba0-0x00514bde` frees through this pool; its two EH references tie the shared wrapper to both allocation/constructor regions.
- Ordinary delete return: scalar deleting destructor `0x0053d1a0-0x0053d237` tears down FlyingObjectPane and returns ordinary deleted objects through this pool. Its sized-delete branch uses `0x144`, independently confirming object size.
- Shutdown destruction: registered wrapper `0x0060c350-0x0060c35a` destroys this exact PoolAllocator. Evidence-session direct-xref enumeration and independent absolute-pointer byte search each found exactly these six pool-base routes and no hidden seventh use.
- Ownership/source placement: the two MapPane paths are callers and remain MapPane-side behavior, while the constructed/deleted object is [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md). This item/flying companion module is therefore the direct source root. [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) owns shared mechanics only, and [UID:0002B4][0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage](by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md) remains a non-emitting mixed aggregate.
- Name/linkage confidence: `g_flyingObjectPanePool` follows [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) and accepted sibling naming; file-local `static` matches internal consumer-instance placement and compiler wrapper shape. No preserved symbol proves exact original spelling or storage class, so UID0002WT confidence remains capped at `93`.
- Compiler/generated disposition: source should contain only the concrete static pool definition. Do not hand-author raw storage, startup/cleanup wrappers, constructor-failure EH glue, or scalar deleting-destructor ABI glue. After validator refresh, generated ItemObjectPane.cpp must contain one UID0002WT definition and no UID0002WT Empty Emitter Marker.
- Rejected alternatives: PoolAllocator.cpp would centralize a consumer-owned instance incorrectly; MapPane.cpp would confuse callers with ownership; aggregate emission would merge distinct source modules; `sizeof(FlyingObjectPane)` is deferred until the class has a final formal layout, so the direct numeric `0x144` remains the behavior-proven first draft.
- Historical correction: the target's former all-`ff` and below-85-gate current wording is superseded by the zero bytes observed during B002 evidence collection on 2026-07-12, target `88/93`, class `85/88`, this file `86/88`, and the populated owner/emitter route. Those older statements remain only as labeled provenance in the target history.

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Ground item creation | `0x00537b40` | Constructed by [UID:0000L3][MapPane](by-file/MapPane.md) object creation at `0x00505e00`. |
| Item bounds and rendering | `0x00537bf0`, `0x00537c70` | Emits one void ItemObjectPane ClearOutputRects body that normalizes/centers pane and object-data bounds plus one void RenderFrame body that delegates to the item image library; FlyingObjectPane inherits RenderFrame without duplication. |
| Flying object creation | `0x00537cb0` | Called by MapPane packet/update handlers at `0x0050dfa0` and `0x00512d60`. |
| Flying object animation | `0x00537d80`, `0x00537f20` | Computes arc bounds and handles timer-driven position updates, impact animation, sound, and final object drop/removal. |
| Destruction and pool free | `0x00537ba0`, `0x00537d60`, `0x0053d1a0`, `0x0053d2e0` | ItemObjectPane emits one explicit empty ordinary destructor; FlyingObjectPane retains its ordinary endpoint. Vptr/base lowering and scalar delete/pool mechanics remain compiler-generated coverage. |

## Boundary Notes

- The constructor/virtual cluster is contiguous from `0x00537b40` through `0x005380af`; scalar deleting destructors are in the nearby object-pane destructor island at `0x0053d1a0` and `0x0053d2e0`.
- IDA confirms `0x0050dfa0` as a real FlyingObjectPane constructor caller. Treat that caller as MapPane-side evidence until ownership is repaired.
- Do not merge these classes into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). `FlyingObjectPane` derives through the item/object path and uses item glyphs; attached overlays derive through attached object behavior.
- 2026-05-26 IDA static-pool review identifies [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for `ItemObjectPane` at `0x0069b9ac` and `FlyingObjectPane` at `0x0069b9d4`; current formal definitions preserve them as distinct file-local pools in this module.
- 2026-07-12 B004 current pool-definition review confirms that `0x0069b9ac-0x0069b9d4` is exactly one zero-filled `0x28`-byte `PoolAllocator` in writable `.data`. Its `0x0041a0e0` startup wrapper constructs `(0x12c, 8)`, and `0x0060c370` destroys it during registered cleanup.
- The exact five direct pool-base xrefs are `0x0041a0e7`, `0x00505e66`, `0x00514c45`, `0x0053d330`, and `0x0060c370`. In `sub_505E00`, allocation from this pool is immediately followed by the `sub_537B40` ItemObjectPane constructor; `sub_53D2E0` returns ordinary deleted objects to the same pool.
- The formal definition belongs in this module rather than `PoolAllocator.cpp`, MapPane, or the broad mixed-pool aggregate. `g_itemObjectPanePool` and file-local `static` remain descriptive reconstruction because original symbol/linkage evidence is absent; the now-complete class and exact size guard support `sizeof(ItemObjectPane)` without changing the wrapper's `0x12c` behavior.
- The 2026-06-12 item/flying executable audit corrects `0x00537bc0-0x00537be9` to [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) ownership: the object-update parser calls it from the non-living `object+0xf8 == 0` branch and it writes the same item id/variant fields used by the ground-item constructor.
- Confirmed padding after the current cluster is `0x005380af-0x005380b0`, immediately before [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md).
- 2026-06-29 B013 source-module support sync: [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) is regenerated from the `ItemObjectPane` class declaration, virtual methods, and destructor wrappers in this source module. Evidence-time MCP session `agent_b009_0002my_20260628` reconfirmed that UID00034Y starts after the `StaticObjectPane` child at `0x006203ec`, ends before the `FlyingObjectPane` child at `0x00620498`, and should stay marker-only rather than broadening this file into a raw `.rdata` owner.
- 2026-07-07 B006 source-module support sync: [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) is regenerated through the `FlyingObjectPane` class declaration, virtual methods, scalar destructor/adjusted thunks, and this `ItemObjectPane.cpp` source module. Evidence-time MCP session `supervisor-nexustk-20260707` reconfirmed that UID00034Z starts after the `ItemObjectPane` child at `0x00620498`, ends before the `AttachedObjectPane` child at `0x00620544`, has vtable bases `0x0062049c`, `0x0062050c`, and `0x0062053c`, and should stay marker-only rather than broadening this file into a hand-authored `.rdata` table owner.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed exact function starts/ranges for:

- `0x00537b40-0x00537b91`, `0x00537bf0-0x00537c65`, `0x00537c70-0x00537ca2`
- `0x00537cb0-0x00537d60`, `0x00537d80-0x00537f1d`, `0x00537f20-0x005380af`
- `0x0053d1a0-0x0053d237`, `0x0053d2e0-0x0053d377`

The later [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) audit adds exact child pages for omitted in-range starts `0x00537ba0`, `0x00537bc0`, and `0x00537d60`, confirms constructor callers at `0x00505e8f`, `0x0050e09b`, and `0x00512ebe`, records item-image/tile and MapPane helper refs, and documents the exact padding around the item/flying cluster.

2026-06-16 A002 live IDA MCP refresh on session `c001_midiplayer_rdata_20260615` rechecked the remaining source-quality blockers:

- `lookup_funcs` reconfirmed every item/flying executable anchor: `0x00537b40` size `0x51`, `0x00537ba0` size `0x1f`, `0x00537bc0` size `0x29`, `0x00537bf0` size `0x75`, `0x00537c70` size `0x32`, `0x00537cb0` size `0xb0`, `0x00537d60` size `0x1f`, `0x00537d80` size `0x19d`, `0x00537f20` size `0x18f`, plus scalar destructors at `0x0053d1a0` and `0x0053d2e0` size `0x97` each.
- `xrefs_to` reconfirmed MapPane-side construction/update reachability: `0x00537b40` from `0x00505e8f`, `0x00537bc0` from `0x00513665`, and `0x00537cb0` from `0x0050e09b` and `0x00512ebe`. These remain caller evidence, not MapPane source ownership for this class module.
- Vtable data refs reconfirmed `ItemObjectPane` vtable stores/restores through `0x006203f0`, `0x00620460`, and `0x00620490` and `FlyingObjectPane` constructor stores through `0x0062049c`, `0x0062050c`, and `0x0062053c`.
- Static pool refs reconfirmed item pool storage `0x0069b9ac` from startup/setup, MapPane allocation, and scalar free paths, and flying pool storage `0x0069b9d4` from startup/setup, MapPane flying-object allocation paths, and scalar free paths.
- 2026-07-12 evidence-time MCP session `cfa0ae1a` strengthened the item-pool side of that statement: all forty input-image bytes are `00`; the constructor and cleanup wrappers are exact compiler patterns; allocation constructs `ItemObjectPane`; constructor-failure and scalar-delete paths free through the same pool. Its then-current no-name/no-UDT and missing-full-range-item statements are superseded by B008 catalog entry `0350`, which resolves and materializes exact `g_itemObjectPanePool` / `struct PoolAllocator` storage.
- `decompile 0x00537bc0` writes decoded item state to `this + 0x128/+0x12a` and refreshes the object through `0x00506980`, supporting the prior correction from LivingObjectPane-adjacent wording to existing ground-item record update.
- `decompile 0x00537f20` shows flight tick behavior through progress fields at `+0x9c/+0x9e`, target object lookup at `+0x98`, impact sound IDs `701/709`, timer scheduling via `0x00597910`, and final drop/removal helpers `0x005060f0/0x00506170`. The helper names and motion field names remain behaviorally understood but not source-quality.
- `get_bytes` reconfirmed `0x00537c65-0x00537c70`, `0x00537d7f`, and `0x005380af-0x005380b0` as `0xcc` alignment; [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md) remains the next executable cluster.

## Corrected Parent Gate Audit

- Current file-root score is `COMPLETION:91`, `CONFIDENCE:93`. The increase is bounded to the accepted UID0003HR ordinary-destructor source closure and its class/scalar/vtable integration; unrelated FlyingObjectPane work is not inflated.
- Direct child now eligible: [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md), refreshed to `85/88`.
- Assignment basis: `ItemObjectPane.cpp` is the direct source root for the ground item and flying item map-object companions because the method cluster, vtable data, destructor island, and pool storage all distinguish item/flying objects from base `ObjectPane`, attached overlays, and MapPane caller-side packet handling.
- Remaining caveat: unrelated FlyingObjectPane field/helper spellings and several exact child bodies remain below final-source certainty, so the file root remains `91/93` and prose-only. That limitation does not reopen the complete ItemObjectPane declaration, explicit destructor, scalar/vtable coverage, or either pool definition.
- 2026-06-16 review outcome: no split/merge/range change is justified. The exact child pages, scalar destructor island, vtable data, pool data, and MapPane caller evidence all still support [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) as the direct source root for both item-object companions.

## Historical / Superseded Assumptions

- Historical file-root scores `82/82`, `85/86`, `86/88`, and `90/92` remain in the Changes chronology but are not current.
- Earlier blank-class, incomplete-field-layout, generic virtual-name, and unresolved ordinary-destructor statements are superseded by the complete UID00006V formal and exact UID0003HR empty source body.
- Earlier descriptions of vptr restoration as source work or of the three views as virtual inheritance are rejected. They are compiler lowering for fixed primary/EventHandler/TimerHandler subobjects.
- Earlier scalar-wrapper source uncertainty is superseded by the UID000385 comment-only compiler-coverage disposition. Flags, pool return, size guard, thunks, RTTI, and vtables remain non-handwritten.
- Historical helper aliases and unrelated FlyingObjectPane uncertainties remain preserved; they do not block the accepted ground-item destructor integration.

## Cross-References

- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md)
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md)
- [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md)
- [UID:0003HQ][0x00537b40-0x00537b91.ItemObjectPaneConstructor](by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md)
- [UID:0003HV][0x00537cb0-0x00537d60.FlyingObjectPaneConstructor](by-memory/0x00537cb0-0x00537d60.FlyingObjectPaneConstructor.md)
- [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md)
- [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md)
- [UID:0002WS][0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage](by-memory/0x0069b9ac-0x0069b9d4.ItemObjectPanePoolStaticStorage.md)
- [UID:0002WT][0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage](by-memory/0x0069b9d4-0x0069b9fc.FlyingObjectPanePoolStaticStorage.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-07-16 B005 UID0003HT source-quality callback:
  - Preserved `91/93`, `NexusTK/map/`, prose-only by-file disposition, executed constructor/destructor/status/render content, complete ground/flying union, two pools, factories, vtables, scalar/compiler exclusions, and unrelated history.
  - Added exactly one source-ready UID0003HT definition route in logical/address order with complete range/hash/behavior/output-role/helper/global/no-guard/source-compiler evidence.
  - Replaced the stale separate-empty-state wording and historicalized `BuildCenteredItemRect`/clip-dirty/free-helper aliases without adding duplicate source.
- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved `91/93`, `NexusTK/map/`, file ownership, prose-only by-file disposition, and the complete current ItemObjectPane/FlyingObjectPane/pool union.
  - Added the validator-renamed UID0003HU route, exact one-body RenderFrame definition, helper call and ignored status, source-void contract, field/source order, direct Flying inheritance reuse, compiler exclusions, negative evidence, and historical `ProcessItemAction` correction.
  - Preserved UID0003HS and all unrelated class/destructor/vtable/pool/factory/FlyingObjectPane content.
- 2026-07-16 Agent-B005 UID0003TT callback:
  - Preserved `91/93`, `NexusTK/map/`, file ownership, prose-only by-file disposition, complete class/pool/destructor/FlyingObjectPane union, and all unrelated history.
  - Added the exact UID0003HS body/source order, UID0003TT caller gate, active MapPane refresh, no-extra-guard behavior, dependency boundaries, compiler exclusions, and historical LivingObjectPane correction.
- 2026-06-16 A002 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed all item/flying function starts and scalar destructor anchors, constructor/update caller refs, vtable-store data refs, static pool refs, alignment padding, the `0x00537bc0` ground-item record update, and `0x00537f20` flying-item tick behavior. Remaining blockers are final field/helper names and source-level method spelling, not ownership, range, or source-placement uncertainty.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/map/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `ItemObjectPane.cpp` under `map/`.
  - After: set the validator path to `NexusTK/map/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ItemObjectPane.cpp` under `map`, and live IDA MCP lookup on 2026-06-05 confirms the `ItemObjectPane` constructor anchor at `0x00537b40` as a real function of size `0x51`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
  - Summary/evidence: item/flying object pane roles, constructor/destructor anchors, method families, MapPane caller evidence, object-pane boundary, static-pool globals, and exact IDA ranges are documented; completion is lower because source-form detail for animation/drop flows is still summarized.
- 2026-06-07 Batch 089 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:82`; the page had a valid `NexusTK/map/` path but was below the corrected direct-parent gate for [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md).
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: incorporated the current item/flying executable audit, vtable-data evidence, destructor-island support, and exact item/flying pool-storage pages. The file now documents why it is the direct source root for the refreshed FlyingObjectPane class while preserving the MapPane caller boundary.
- 2026-06-12 A002 Batch315:
  - Kept scores at `85/86` but updated the method inventory to the exact split children and corrected `0x00537bc0-0x00537be9` from stale LivingObjectPane-adjacent wording to ItemObjectPane record-state update ownership.
- 2026-06-29 B013 UID00034Y marker support sync:
  - Metadata remains `86/88`; no file-level formal C++ was added.
  - Summary/evidence: the `ItemObjectPane` vtable child [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) is covered by this module's class declarations/method definitions, with exact StaticObjectPane and FlyingObjectPane boundaries preserved and raw vtable arrays rejected.
- 2026-07-07 B006 UID00034Z marker support sync:
  - Metadata remains `86/88`; no file-level formal C++ was added and the projected path remains `NexusTK/map/`.
  - Summary/evidence: the `FlyingObjectPane` vtable child [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) is covered by this module's class declarations/method definitions, scalar destructor/adjusted thunks, and source-route placement, with exact ItemObjectPane and AttachedObjectPane boundaries preserved and raw vtable arrays rejected.
- 2026-07-12 B004 UID0002WS pool-definition support sync:
  - Metadata remains `86/88`, projected path remains `NexusTK/map/`, and no unrelated file-level C++ or score change was applied.
  - UID0002WS now emits `static PoolAllocator g_itemObjectPanePool(0x12c, 8);` in this module. Current MCP confirms exact zero-filled `0x28` storage, `(0x12c, 8)` construction, registered cleanup, five direct liveness xrefs, allocation into the ItemObjectPane constructor, and scalar-delete return to the same pool.
  - The generated startup/cleanup bodies and broad adjacent-pool aggregate remain non-emitting. Original name/linkage and declaration order remain unproven, and the numeric size is retained until the formal class layout is complete.
- 2026-07-28 B008 UID0002WS supplemental support sync:
  - Preserved `91/93`, `NexusTK/map/`, file ownership, prose-only by-file disposition, complete ItemObjectPane/FlyingObjectPane union, separate pools, and all unrelated method/vtable/factory/history detail.
  - Synchronized current module/status/proposed-contents text to `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);`; the complete class size guard proves exact `0x12c` behavior.
  - Added the pre-Gate2B `g_itemObjectPanePool` / `struct PoolAllocator`, forty-item partition, exact five-route liveness, source-placement/rejected-alternative rationale, and supervisor A00-A07 handoff. That pending presentation is superseded below.
- 2026-07-29 B008 UID0002WS supervisor Gate 2B reconciliation:
  - Catalog entry `0350` records exact applied target materialization/comments, restored five helper identities/types/function-regular comments, preserved A00 types and A03 allocator entry, and unchanged bytes/xrefs/ranges/internal comments/wrappers/neighbors.
  - Physical argument frame labels normalized only for A02/A04/A06 after accepted typed signatures. Literal `Argument member` rejection prevented unsafe raw-label restoration; source-facing Hex-Rays names/types and executable ABI remain exact.
  - Saved IDB SHA256 `41977C87379D1A8BDC199A9A17DE3E117E365E3A596828DFA6FA0D7C2FA60DD3`, size `143190178`, last write `2026-07-29T03:12:58.7364596-04:00`; prestate backup `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.before-B008-UID0002WS-20260729-031039.i64`, SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`.
- 2026-07-12 B002 UID0002WT pool-definition support sync:
  - Metadata remains `86/88`, projected path remains `NexusTK/map/`, and no broad file-level formal C++ or unrelated score change was applied.
  - UID0002WT now emits `static PoolAllocator g_flyingObjectPanePool(0x144, 4);` beside UID0002WS. MCP session `545b4991`, used during B002 evidence collection on 2026-07-12, returned zero-filled exact `0x28` storage and corroborated startup construction, two allocation-plus-FlyingObjectPane-constructor paths, shared EH free, scalar-delete free, and registered shutdown destruction. This is a time-scoped evidence record, not a present session-health claim.
  - Exact xrefs and independent absolute-pointer search both exhaust six routes. Original name/linkage remain descriptive and confidence-capped; raw storage and compiler wrappers stay non-emitting; PoolAllocator.cpp, MapPane.cpp, and the mixed aggregate remain rejected as direct owners.
- 2026-07-16 B001 UID0003HR accepted callback:
  - Raised the file root from `90/92` to `91/93`; retained `NexusTK/map/`, file ownership, and prose-only by-file disposition.
  - Integrated the exact empty ordinary destructor, complete class declaration relationship, scalar/vtable compiler coverage, fixed interface views, pure ObjectPane base route, source order, liveness, negative evidence, and rejected duplicate source shapes.
- Preserved the complete ItemObjectPane/FlyingObjectPane/pool union and historicalized stale lower-score, blank-class, virtual-inheritance, unresolved-destructor, and custom-scalar-source wording.

## 2026-08-22 UID0000MM Accepted PoolAllocator Dependency Callback

- Formal CPP dependency: `#include "../util/PoolAllocator.h"`, emitted by [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) into this file's existing source route.
- Retained consumer declarations: `static PoolAllocator g_itemObjectPanePool(sizeof(ItemObjectPane), 8);` and `static PoolAllocator g_flyingObjectPanePool(0x144, 4);`.
- Inventory linkage: P08 and P09; exact ranges, bytes, xrefs, wrapper topology, and supervisor-owned materialization actions remain on their UID-bound storage pages and the accepted UID0000MM report.
- Routing: The declarations remain on UID0002WS and UID0002WT under their current class/file owners.
- Formal H disposition: no PoolAllocator declaration is duplicated here; the CPP include supplies the complete standalone utility type.
- Generated acceptance: the earlier command-26311/26323/26351/26355 observations are dated prestates only. The scoped callback validator must regenerate this CPP with the include and unchanged consumer declaration(s), and the dated physical file receipt is recorded in the accepted report.
