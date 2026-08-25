*** UID:00006W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ItemObjImageLib.h"

// Exact method bodies remain on the ordered child pages.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_ITEMOBJIMAGELIB_H
#define NEXUSTK_RENDER_ITEMOBJIMAGELIB_H

#include "../ui/core/RectBounds.h"
#include "../util/LObject.h"
#include "../util/Singleton.h"

class IntAlphaSurface;
class GrafPort;
class MapPane;
struct ItemInfo;
template <class T> class ProtectedArray;

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib

## UID0000LO Gate 2A Member-Declaration Repair - 2026-08-14

The class route now owns the real `ItemObjImageLib.h` assembly: its formal H
opens the header guard and dependency/forward-declaration prefix, inserts the
ordered child H payload, and closes the guard. UID0001UU supplies the complete
class declaration through that marker, including public
`GetItemGlyphBounds(short, RectBounds *)`; the prior free declaration is
removed. Formal CPP includes the generated header before method children, so
the existing qualified UID0000UQ definition and every
`g_pItemObjImageLib->GetItemGlyphBounds(...)` call resolve against one member
declaration. Completion rises from `92` to `93`; confidence remains `94`.

## UID0000LO Accepted Glyph-Bounds Declaration - 2026-08-14

The H channel now exposes
`void GetItemGlyphBounds(short itemId, RectBounds *outBounds);` as an
ItemObjImageLib member declaration. This matches the established UID0000UQ
qualified body and all singleton-receiver call sites, including
MyItemListPane::DrawListEntry. It supersedes any free-helper interpretation;
the class owner/emitter, score, global singleton ownership, and method body
route remain unchanged.

## UID00041S Fixed-Slot Draw Source-Quality Integration - 2026-08-11

- [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) is now the source-ready public member `void ItemObjImageLib::DrawItemImageIn43x43Slot(GrafPort *drawPort, RectBounds *destinationBounds, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength)`. Seven direct callers pass a `GrafPort *` and ignore `EAX`; the body mutates the destination bounds while crop-clamping and centering the image in a 43-by-43 slot.
- The complete child behavior preserves the early `g_imageLibraryLoadError` return, unsigned `itemId + 0x4000`, non-EPF `0x0a20..0x0a56` remap by `+0xff53`, `0x0972` clamp, fallback `ItemInfo`, palette-filter gate, `ITEM.EPF`/`ITEM.EPD` lookup, slot-10 palette selection, source crop, destination recenter, nullable callback options, and optional `IntAlphaSurface::DrawEncodedAlphaFrame` overlay.
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) is the sole complete declaration owner for `SurfaceSpriteBlitOptions`, `SurfaceSpriteBlitProc`, and `g_pfnBlitSprite`. The target uses kinds `1`, `2`, and `3`; kind `3` deliberately leaves `secondaryPaletteShift` at `+0x1c` unwritten before an installed RGB565 path reads it. This is a recovered latent original-source defect, so the accepted body uses an uninitialized local and does not silently zero-fill the record.
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) owns the matching declaration; this class page remains the semantic owner/index with `[[CHILDREN]]`, and the exact definition remains child-owned. No class declaration, callback ABI, global definition, or method body is duplicated here.
- Historical class-wide statements that all four draw children retained no-code proofs are superseded for UID00041S only. UID00041R, UID00041T, and UID00041U keep their independent contracts and dispositions. Class metadata remains `92/94`, owner/emitter UID0000KH.

## UID0001OT Singleton Lifetime And Source Integration - 2026-07-20

- `ItemObjImageLib` is a direct `LObject` and `Singleton<ItemObjImageLib>` derived class. RTTI base descriptors and Singleton PMD `0,4,0` prove the adjusted empty-base route; empty-base optimization preserves the complete `0x28`-byte object and the existing `ProtectedArray<ItemInfo>` offsets.
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) remains the sole complete declaration emitter and now carries both direct bases plus one header-facing `extern ItemObjImageLib *g_pItemObjImageLib;`. [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) remains the sole zero-initialized external definition in the source module.
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) is the four-byte physical storage index, semantic-owned by UID0000RA but false/non-emitting. Its 65 xrefs comprise five compiler-lifetime writes and 60 reads across 26 recognized consumer functions; no consumer owns publication.
- [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) uses a direct Singleton base initializer. Its apparent writes at `0x004dec7b/0x004dec82` are adjusted base-publication/null lowering, not authored assignments.
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) is the sole handwritten destructor and has an empty source body. `ProtectedArray<ItemInfo>`, `Singleton<ItemObjImageLib>`, and `LObject` destruction implicitly regenerate the observed member free, singleton clear, and base teardown.
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) is the EH-only out-of-line Singleton base destructor. UID0002VC, UID0001XW, and UID0002ML are likewise compiler-generated scalar/vtable/RTTI evidence. All four are false/non-emitting with blank managed C++; no ABI wrapper or table source is handwritten.
- This class remains the semantic owner/index route with the complete `[[CHILDREN]]` union. The direct declaration remains child-emitted by UID0001UU, and all exact method bodies remain on their accepted child pages; no duplicate class or global source is introduced here.

## UID0000UQ Public GetItemGlyphBounds Integration - 2026-07-16

- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) is now the source-ready public nonvirtual `void ItemObjImageLib::GetItemGlyphBounds(short itemId, RectBounds *outBounds)` member at `92/94`, owner/emitter UID00006W.
- The complete declaration remains emitted only through [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md); UID0000UQ owns the one qualified body. This class page remains the owner/index route with its existing comment-only `[[CHILDREN]]` marker and does not duplicate either.
- All 48 direct call sites across 23 functions supply `g_pItemObjImageLib` in `ECX`; zero consume the machine result. The body does not read `this`, so decompiler/free-`__stdcall` presentation is an optimized-unused-receiver artifact.
- Exact member behavior preserves `ITEM.EPF`/`ITEM.EPD` selection, unsigned `itemId + 0x4000`, translated-band add `0xff53`, clamp `0x0972`, `g_pEPFLib->GetEntryRect`, and half-tile `OffsetRect`.
- Broad item-list/look/menu/inventory/preview/ItemObjectPane caller spread supports public class API status. No narrower friend/private caller set, free/static route, UI owner, or separate helper file is supported.
- Class metadata is now `92/94`, owner/emitter UID0000KH, reconstructable true, blank position, and formal route marker. Constructor/destructor, layout/fallback row, four draw methods and their independent no-code proofs, table/availability helpers, compiler coverage, resources, and unrelated history remain preserved.
- Historical free-helper and physical-`__stdcall` claims are retained only as superseded analysis. They no longer describe current ownership, declaration, or generated output.

## UID0003HU General Draw Caller Integration - 2026-07-16

- Exact child UID00041R retains `88/91`, owner/emitter UID00006W, blank formal body, complete behavior, and the kind-3 partially initialized options-record no-code proof.
- Its source-facing declaration is refined only to `int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength)`.
- The complete helper body never writes destination bounds, so `const` is source-legal and ABI-neutral. Fixed-slot, unscaled, and scaled draw signatures remain unchanged.
- [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) is a direct caller that passes `GrafPort *target`, const bounds, `m_itemId`, `m_paletteFlags`, null overlay, and zero strength. Its source return is void and it ignores UID00041R's `int` status.
- This class is `92/94`, owner/emitter UID0000KH, reconstructable true, blank position, and formal route marker. The declaration continues to emit through UID0001UU; no duplicate class declaration or method body is added here.
- Singleton/vtable/layout, ItemInfo fields, constructor/destructor, table/reload/availability helpers, other draw methods, pools/resources, and all unrelated history remain unchanged.

## UID0003TX Item-Lighting Consumer Integration - 2026-07-16

- UID0002QN supplies the direct semantic consumer that resolves `ItemInfo::lightImageIndex` at `+0x0c`: MapPane indexes `m_itemInfos` with unsigned `appearanceId + 0x4000`, tests the signed value for nonnegative, and passes it to `AttachObjectLighting` with half-tile offsets.
- The accepted layout child retains the complete `ItemObjImageLib : public LObject` declaration and adds `friend class MapPane;` for direct protected-array access. No synthetic lookup method, runtime accessor, or duplicate class declaration is added here.
- `ProtectedArray<ItemInfo>` ownership, embedded fallback row, singleton lifecycle, `ITEM.TBL`/`ITEM.TBD` loading, four draw methods, availability refresh, destructor cleanup, and exact child bodies remain unchanged. Fallback `lightImageIndex == -1` means no light attachment.
- Historical `renderFlagsOrMode` is superseded by the direct lighting consumer. Palette, alpha, and filter semantics remain independent fields; the rename does not change the `0x14` row layout.
- This class page remains the owner/index route with `[[CHILDREN]]`; the layout child emits the declaration, and compiler vtable/template, scalar deleting, buffer free, and singleton wrapper lowering remain non-emitting.

## Status

- Confidence: very strong for method roles, direct Singleton/LObject hierarchy, singleton/vtable ownership, source/header placement, compiler lowering, one-definition policy, and the embedded `ProtectedArray<ItemInfo>` layout. Remaining draw-owner and `ItemInfo` spelling uncertainty is confined to unrelated draw children.
- Likely source file: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- Parent/C++ status: attached to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), the `NexusTK/render/ItemObjImageLib.cpp` source root that owns the item sprite singleton, layout, `ItemInfo` row type, global, constructor/destructor, draw paths, table reload helper, frame-availability helper, legacy item remap constants, and public glyph-bounds member. The constructor, empty ordinary destructor, legacy remap constants, UID0000UQ body, and UID00041S fixed-slot draw body have first-draft C++ on exact children; the other three draw pages retain their independent dispositions. UID0002VC is class-owned generated scalar-deleting glue with blank formal C++; source cleanup remains UID00017O. This class page carries only its established route marker and `[[CHILDREN]]` because the complete declaration is emitted through UID0001UU and all exact bodies remain child-owned.
- Address ranges: [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md), draw children [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md), [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md), [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md), [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md), glyph helper [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md), table helper [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md), frame-availability helper [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md), constructor SEH singleton cleanup helper [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md), and scalar deleting destructor [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md)
- Singleton: [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) at [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- Vtable: [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) at `0x0061b73c`
- Layout: [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- Current recovered file: `source-3/simroot_v2/class_ItemObjImageLib.cpp`

## Class Purpose

`ItemObjImageLib` is the direct `Singleton<ItemObjImageLib>`-backed item sprite library behind [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). It loads item metadata from DAT-backed item table files and supplies the shared item draw routines used by item lists, inventory/fitting panes, item menus, look panes, and dialogs.

## Observed State

```text
0x00  ItemObjImageLib vptr / LObject base
0x04  Singleton<ItemObjImageLib> empty base (PMD 0,4,0; no storage)
0x04  ProtectedArray<ItemInfo> m_itemInfos
       +0x00  concrete ProtectedArray<ItemInfo> vptr     (object +0x04)
       +0x04  int m_count                               (object +0x08)
       +0x08  ItemInfo *m_entries                       (object +0x0c)
       +0x0c  int m_defaultCapacity / m_reservedCount   (object +0x10)
       +0x10  ItemInfo m_defaultEntry                   (object +0x14)
```

The object is at least `0x28` bytes. IDA confirms `ProtectedArray<ItemInfo>` uses count at object `+0x08`, entry pointer at object `+0x0c`, and provisional default/reserved capacity at object `+0x10`. Object `+0x14` is the inline `m_itemInfos.m_defaultEntry`, not a separate top-level `ItemObjImageLib` member. Behavior prose may still call it the fallback/default row because draw paths use it when an item entry index is out of range.

Current `ItemInfo` field names are `itemTableId`, `paletteSlot`, `alpha`, `lightImageIndex`, and `allowPaletteFilter`. `paletteSlot`, `alpha`, and `allowPaletteFilter` retain high-confidence draw/availability support; UID0002QN directly proves `lightImageIndex`, while `itemTableId` remains descriptive rather than recovered-symbol text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ItemObjImageLib::ItemObjImageLib` | `0x004dec30-0x004dee1b` | Constructs the singleton, seeds fallback item info, opens `ITEM.TBL` or `ITEM.TBD`, resizes the item array, and reads item metadata rows. |
| `ItemObjImageLib::~ItemObjImageLib` | [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) | Ordinary non-deleting destructor body; current MCP session `261fb29b` does not model the raw start as a function and finds no code/data/VA/RVA pointer route to it, but disassembly shows vtable stores, item-array free, singleton clear, and `LObject` cleanup. |
| `int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength)` | [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) | General item draw path with read-only destination bounds. Uses `ITEM.EPF`, palette helpers, slot-2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and optional `IntAlphaSurface::DrawEncodedAlphaFrame`; UID0003HU is a direct GrafPort/bounds caller that ignores the status. Formal C++ remains blank because option kind `3` leaves RGB565-read secondary byte `+0x1c` unwritten. |
| `void DrawItemImageIn43x43Slot(GrafPort *drawPort, RectBounds *destinationBounds, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength)` | [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) | Source-ready fixed `43x43` icon-slot draw path. Applies non-EPF legacy remap constants, clamps/recenters large source rectangles, dispatches through `g_pfnBlitSprite`, preserves the partially initialized options-record behavior, and optionally emits overlay mask data. |
| `int DrawItemImageUnscaled(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)` | [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md) | Direct unscaled `ITEM.EPF` draw path with non-overlay render option setup. |
| `int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)` | [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) | Crop-to-fit/scaled item draw path. Applies non-EPF legacy remap constants, adjusts the source rectangle around its center when source dimensions exceed twice the destination dimensions, resolves slot-10 palette state, and dispatches `g_pfnBlitSprite` with a nullable options-pointer final argument. Formal C++ remains blank because UID00041U's option-kind-6 path writes only options `+0` and conditionally `+8`, while the installed RGB565 slot target reads `+0x1c`. |
| `void GetItemGlyphBounds(short itemId, RectBounds *outBounds)` | [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) | Public nonvirtual member with exact remap/archive/half-tile body; all 48 direct callers supply the singleton receiver and ignore the machine result. |
| `ItemObjImageLibLoadItemInfoTable` | [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) | Loads `ITEM.TBL` / `ITEM.TBD` rows into the embedded `ProtectedArray<ItemInfo>`; B003 rejected the old `LightInfoTableLoader` name from live IDA row-stride and resource evidence. |
| `RefreshItemFrameAvailability` | [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) | Private raw/unmodeled helper with formal first-draft C++; iterates item rows, checks `ITEM.EPF` / `ITEM.EPD` frames against each row's category-10 `DLPalette`, and refreshes `ItemInfo::allowPaletteFilter` at `+0x10`. Current MCP still finds no function object, direct start xref, or VA/RVA pointer route, so the exact method spelling and live reachability remain inferred/absent rather than code blockers. |
| Constructor SEH singleton cleanup helper | [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) | File-level/generated constructor unwind helper, not a class method or source API. Current MCP session `b001_000241_20260627` confirms exact `0xb` `mov dword_67A758, 0; retn` body, cleanup jump `0x00600158 -> 0x004e5ba0` from `SEH_4DEC30`, no ordinary callers/callees, no data/VA/RVA pointer route, and blank formal C++ through [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md). |
| Compiler scalar deleting destructor | [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md) | False/non-emitting vtable-only compiler wrapper. It duplicates implicit member/Singleton/LObject cleanup before delete flags, size guard, and optional storage free; UID00017O is the sole handwritten destructor source. |

IDA MCP on 2026-05-22 found the constructor has one startup caller at `0x004f602f`. The draw methods have broad UI caller sets, while the destructor is vtable/disposal glue with no direct code refs.

IDA MCP on 2026-05-25 confirms the singleton storage at `0x0067a758` has 65 xrefs across 29 recognized functions. The constructor writes the object pointer at `0x004dec7b`, while cleanup/destructor paths clear it at `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.

B013 2026-06-27 current MCP session `b001_000241_20260627` resolves [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) as file-owned constructor SEH cleanup glue rather than `ItemObjImageLib::ClearSingleton`. The constructor installs `SEH_4DEC30` at `0x004dec35`; the cleanup funclet at `0x00600152-0x0060015b` computes `ecx = [ebp+var_4C] + 4` and jumps at `0x00600158` to `sub_4E5BA0`, whose body ignores `ECX` and clears `dword_67A758`. The same session reports no ordinary callers/callees and no data/VA/RVA pointer route, so class-level C++ remains blank and the exact child keeps a blank formal block as generated cleanup-glue proof.

IDA MCP on 2026-05-26 confirms the primary vtable at `0x0061b73c`, with constructor store `0x004dec8c`, unmodeled ordinary destructor store `0x004dee23`, and scalar deleting destructor store `0x004e6586`. Active generated metadata currently reports `vtable_count: 0`.

IDA MCP on 2026-06-11 rechecked the class-owned vtable parent gate against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`). The constructor at `0x004dec30` stores `??_7ItemObjImageLib@@6B@` at `0x004dec8c` and the embedded `ProtectedArray<ItemInfo>` vtable at `0x004dec92`; the ordinary destructor bytes at `0x004dee20` and scalar deleting destructor at `0x004e6580` restore the same class/template vptr pair before freeing the item array and clearing [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). The vtable dwords at `0x0061b73c-0x0061b744` resolve to the scalar deleting destructor plus inherited `LObject` slots now read as `LObject::GetRuntimeClass` at slot `+0x04` and `LObject::VirtualNoop(int, int)` at slot `+0x08`, bounded by `ProtectedArray<ItemInfo>` and `ProtectedArray<LightInfo>` metadata. This closes the narrow confidence gap for class ownership of [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md), while final field names and the draw-method child split remain open.

Historical B005 2026-06-18 source-quality work resolved constructor helper blockers and then used provisional `renderFlagsOrMode`. UID0003TX synchronizes only that old field alias to `lightImageIndex`; DATFile construction/open/destruction and `ReadEncodedTableInt` / `ReadEncodedTableFloat` evidence remains unchanged.

B005 2026-07-02 accepted source-quality callback refines [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md). Current MCP session `supervisor_resume_20260629` confirms exact range `0x004df2c0-0x004df455`, size `0x195`, nine leading and eleven trailing `0xcc` padding bytes, five direct callers, legacy constants `0x0972`/`0x0a20`/`0x0a56`, helper names `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::IsPaletteFilterEnabled`, and `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, paletteFlags >> 5)`, plus callback order through slot `0x0069b3e8`. The accepted support model is `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, returning `int`, with draw receiver in `ecx`, six stack arguments, and nullable `const SurfaceSpriteBlitOptions *options`. UID00041U remains no-code because it uses option kind `6` but initializes only `+0` and conditionally `+8`; RGB565 option `6` reads `+0x1c`, so raw byte arrays, two-field structs, zero-init structs, partial-init structs, and scalar `int flags` would be decompiler-shaped or behavior-unsafe.

B003 2026-07-02 accepted source-quality callback refines [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md). Current MCP session `supervisor_resume_20260629` confirms exact range `0x004dee50-0x004defba`, size `0x16a`, ABI `ret 18h`, 29 direct code xrefs, helper names `EPFTileContext::InitTileContext`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::IsPaletteFilterEnabled`, `PaletteLib::GetSlotPalette`, slot-2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and `IntAlphaSurface::DrawEncodedAlphaFrame`. The formal-safe signature uses `void *drawOwner` because this body forwards the receiver through `ecx` to slot 2 but does not prove a narrower static pane/control/GrafPort base type. UID00041R uses the current `ITEM.EPF` path directly and does not consume the legacy item-remap constants. Its formal body remains blank for the exact kind-3 options proof: the alpha-plus-palette path writes option kind `3`, alpha `+0x04`, and palette/tint byte `+0x08`, but leaves secondary byte `+0x1c` unwritten while the installed RGB565 tag-3 path reads it at `0x004c189d`.

B008 2026-06-19 source-quality pass used existing IDA exports plus a fresh local PE/Capstone pass after the live IDA MCP endpoint at `http://127.0.0.1:13337/mcp` was unavailable. B005 current MCP session `80de0a67` supersedes the fallback-only draw/glyph provenance from that pass: it reconfirmed half-open draw/helper boundaries, padding, `g_pItemObjImageLib` operand hits, `ITEM.TBL`/`ITEM.TBD`/`ITEM.EPF`/`ITEM.EPD` operands, legacy remap-constant consumers, xref counts 29/7/7/5/48, shared resource/palette/render callees, and optional overlay helper only on the first two draw paths. Representative callers pass an owner/control object, destination rect, item id, palette/tint byte, optional overlay mask, and overlay strength for the two overlay-capable paths; unscaled/scaled paths pass the first four arguments only. The first stack parameter after `this` is passed consistently but optimized unused in the draw bodies except as a callback receiver. B005 2026-07-02 supersedes the old `Pane *drawOwner` guess for formal declarations: use `void *drawOwner` in the layout/formal-safe route until a separate receiver-type pass proves a narrower source type.

B002 2026-06-23 MCP-backed destructor pass supersedes older fallback-only destructor provenance for [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md). Current session `261fb29b` reports no function object at `0x004dee20`, no modeled decompilation/analyze/callee result for the raw start, exact bytes `56 8b f1 c7 06 3c b7 61 00 ff 76 0c c7 46 04 34 b7 61 00 e8 61 89 0e 00 83 c4 04 c7 05 58 a7 67 00 00 00 00 00 8b ce 5e e9 43 5c 01 00`, five `0xcc` pre-padding bytes at `0x004dee1b-0x004dee20`, three `0xcc` post-padding bytes at `0x004dee4d-0x004dee50`, zero direct code refs/data refs/VA pointer bytes/RVA pointer bytes to the raw start, and current disassembly with `dword_67A758` as the backing singleton label. The class vtable refs remain constructor `0x004dec8c`, ordinary destructor `0x004dee23`, and scalar deleting destructor `0x004e6586`; `ProtectedArray<ItemInfo>` vtable refs include constructor `0x004dec92`, ordinary destructor `0x004dee2c`, template cleanups `0x004e5b13`/`0x004e6189`, and scalar deleting destructor `0x004e658f`. This keeps [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) as owner/emitter for [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md), rejects no-owner/global/template/base ownership for the ordinary raw body, and keeps the formal ordinary destructor C++ blank because a hand-written body would either omit the member/base cleanup ordering or expose compiler ABI vptr/free code as source.

B014 2026-06-26 source-quality work resolved the scalar deleting destructor separately from the ordinary raw destructor. The 2026-07-20 B002 callback retains the evidence but supersedes the old direct-emitter/comment-marker disposition: UID0002VC is now semantic-owned by this class, false/non-emitting, and blank-formal because current MCP confirms the vtable-only route `0x0061b73c -> 0x004e6580`, no ordinary callers, `sub_4E6580` size `0x5c` / 92 bytes, class/template vptr stores, singleton clear, no pointer route to `0x004dee20`, and trailing padding. The class-level route must not duplicate or hand-write the ABI wrapper.

B013 2026-06-27 source-quality callback resolves the singleton cleanup helper child separately from class methods and from the scalar deleting destructor. [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) remains reconstructable through the [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) file root because the source-owned effect is the constructor/destructor singleton lifecycle; the binary helper itself is compiler/SEH cleanup glue and must keep formal C++ blank.

[UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) is a concrete UI preview consumer of the item render path. Its status-kind `2` branch calls the public UID0000UQ member with descriptor offset `+4` / `m_objectStatus.m_appearanceId`, then calls [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) with the same item id and descriptor offset `+6` / `m_variantOrPalette`. Receiver setup supplies `g_pItemObjImageLib` for both library operations.

## Source-Quality Notes

- The inherited vtable slots should be read as `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int, int)` based on current `LObject` support docs; `sub_4F4B10` and `nullsub_18` are no longer useful source-facing names for this class page.
- Historical all-draw `void *drawOwner` wording is superseded for UID00041S: its seven callers and callback receiver flow prove `GrafPort *drawPort`. The remaining draw declarations keep their independently supported types until their own source-quality passes prove a narrower contract.
- `ItemInfo +0x00` remains descriptive `itemTableId`; `+0x0c` is behaviorally resolved as `lightImageIndex` by a direct MapPane consumer. Missing original lexical symbols cap confidence but do not block child source.
- `LoadItemInfoTable` and `RefreshItemFrameAvailability` are class helpers despite no direct caller/start-xref evidence. Their object layout, item resources, row stride, and negative LightObj evidence reject no-owner or LightObj routes. [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) now emits a private first-draft body because current MCP session `359c7886` reconfirmed its full raw control/data flow and current support resolves every called API/type; its no-function/no-xref/no-pointer state is preserved as liveness evidence, not used to omit source-authored behavior.
- `GetItemGlyphBounds` is a public nonvirtual ItemObjImageLib member and not a UI-pane helper. Historical free-helper wording is superseded by exhaustive singleton-receiver evidence.
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) is not `ItemObjImageLib::ClearSingleton` and not a source API. It is constructor SEH cleanup glue reached only by `0x00600158 -> 0x004e5ba0`, with no ordinary callers/callees and no data/VA/RVA pointer route; source-level reconstruction should express the singleton lifecycle through constructor/destructor semantics rather than a helper method.
- Formal by-class C++ remains a route marker with `[[CHILDREN]]`: exact by-memory children own bodies, and the complete declaration is emitted through UID0001UU. UID00041S now owns its accepted body; the other draw children retain their specific dispositions. By-class output must not duplicate constructor/remap/destructor/draw child code or hand-write UID0002VC ABI mechanics; UID0002VC is blank-formal false support, while UID00017O emits the accepted empty authored destructor whose implicit lowering regenerates cleanup.

## Closely Related Global

[UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) is the shared public item icon bounds member. It uses the same `ITEM.EPF` versus `ITEM.EPD` selection globals and calls `ResourceLayoutTable::GetEntryRect` before offsetting the rect into the standard icon slot. The exact body is class-owned/emitted by UID00006W while the source file remains UID0000KH.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md)
- [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md)
- [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md)
- [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md)
- [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md)
- [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-07-20 B002 UID0001OT singleton-lifetime callback:
  - Raised the class to `92/94` and preserved owner/emitter UID0000KH, reconstructable route status, complete `[[CHILDREN]]` union, and all unrelated draw/glyph/table/resource evidence.
  - Added the direct Singleton base, PMD/EBO, 65-reference/five-write lifetime, one-definition, constructor/empty-destructor, and compiler-artifact split while leaving the complete declaration on UID0001UU and exact bodies on child pages.

- 2026-07-16 B005 UID0003HT source-quality callback:
  - Preserved `88/89`, UID0000KH class-parent/file route, reconstructable true, comment-only `[[CHILDREN]]` marker, complete class/resource/layout/draw/destructor evidence, and unrelated history.
  - Reclassified UID0000UQ as a public nonvirtual class member from exhaustive 48-call singleton-receiver and zero-result-consumer proof.
  - Synchronized the UID0001UU declaration route, child-owned qualified body, method inventory, generated expectation, and superseded free/`__stdcall` history without changing draw-method no-code proofs.
- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved `88/89`, UID0000KH owner/emitter, reconstructable true, route marker, and the complete current class/support union.
  - Synchronized only UID00041R's `const RectBounds *dstRect` declaration and the exact UID0003HU GrafPort/bounds/item/palette/null-overlay/zero-strength caller with ignored return.
  - Preserved every unrelated method signature/body/no-code proof and added no duplicate class or target body.
- 2026-07-12 B005 UID0003ND source-quality callback:
  - Score and class/file route unchanged. Updated `RefreshItemFrameAvailability` to a private first-draft-emitting exact child and preserved the current raw-liveness caveat: no IDA function object, direct start xref, VA/RVA pointer route, or original symbol. Current MCP session `359c7886` proves the mirrored item-archive loops, ItemInfo row/fallback layout, category-10 `DLPalette` dependency, and `allowPaletteFilter` writes.
  - Added the formal `[[CHILDREN]]` insertion marker required for the existing UID00006W emitter route. Without the marker, generated coverage labeled UID0001UU/UID0002VC/UID0003ND as routed but the assembled `ItemObjImageLib.cpp` omitted them; the marker repairs generated placement without changing ownership or duplicating direct file-owned children.
- 2026-07-02 B005 UID00041U source-quality callback:
  - Score unchanged. Synchronized `DrawItemImageScaled` to the formal-safe `void *drawOwner` signature and replaced generic callback/type uncertainty with the accepted slot-2/options no-code proof.
  - Evidence: UID00041U current MCP session `supervisor_resume_20260629` proves exact range/padding, five direct callers, helper names, legacy remap and palette behavior, callback order, and target-local options writes. Surface support now treats slot 2 as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with nullable `const SurfaceSpriteBlitOptions *options`; UID00041U remains blank because option kind `6` reaches RGB565 option `+0x1c` without target initialization.
- 2026-07-02 B003 UID00041R source-quality callback:
  - Score unchanged. Synchronized `DrawItemImage` to the formal-safe `void *drawOwner` signature and replaced generic helper/callback/overlay blockers with the accepted slot-2 options and `DrawEncodedAlphaFrame` route.
  - Evidence: UID00041R current MCP session `supervisor_resume_20260629` proves exact range `0x004dee50-0x004defba`, size `0x16a`, 29 direct xrefs, ABI `ret 18h`, current `ITEM.EPF` path without legacy remap constants, helper names, slot-2 callback route, and the exact no-code blocker where option kind `3` leaves `+0x1c` unwritten while RGB565 tag `3` reads it at `0x004c189d`.
- 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation:
  - Added a formal comment-only no-code marker for the duplicate class route. The first-draft class/layout declaration is emitted through [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md); exact constructor, scalar destructor, draw, helper, and generated-binary decisions remain child-owned.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: item sprite library role, singleton/vtable/layout, constructor/destructor/draw methods, fallback item info, ProtectedArray storage, startup and global xrefs, related bounds helper, and palette/resource relationships are documented; confidence is capped by final field names and offsets. Evidence: `ItemObjImageLib`, `ItemObjImageLibDestructor`, singleton storage page, `ItemObjImageLibVtable`, `ItemObjImageLibLayout`, `ItemInfo`, `GetItemGlyphBounds`, and ProtectedArray/ResourceLayoutTable references.
- 2026-05-31 IDA range/layout update:
  - What existed before: old method endings, aggregate range `0x004dec30-0x004e65db`, destructor range `0x004dee20-0x004dee4c`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `RECONSTRUCTABLE:TRUE`, corrected exclusive-end method ranges, aggregate range `0x004dec30-0x004e65dc`, destructor range `0x004dee20-0x004dee4d`, and scores `86/84`.
  - Summary/evidence: IDA MCP confirmed exact function bounds, constructor row read order, vtable/global xrefs, and scalar deleting destructor bounds. Scores stay below final level pending exact child-page split for every draw method and final source-facing field names.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) pointed at this class, but the class had no autogen parent, leaving the layout blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), the `NexusTK/render/ItemObjImageLib.cpp` root.
  - Evidence: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) is assigned to that generated source root at `88/84`; this class is `86/84`; and the constructor/destructor, singleton/global, vtable, layout, `ItemInfo`, resource-input, draw-method, and helper evidence all belong to the same render image-library module.
- 2026-06-11 A003 vtable parent-gate update:
  - Before: the class was `86/84`, which blocked direct attachment of [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) under the corrected `85/85` child/direct-parent gate.
  - After: confidence is `85` based on a fresh live IDA recheck of the class vptr stores, exact vtable dwords, adjacent template-vtable boundaries, singleton cleanup, and source-file parent chain.
  - Evidence: the added 2026-06-11 IDA note ties the type-level vtable page to this class declaration while preserving the existing caveats for final field names, exact draw-method child pages, and non-final C++ declarations.
- 2026-06-13 B003 helper-routing repair:
  - Before: the post-`0x004df500` helper was documented as a no-owner `LightInfoTableLoader`, and the raw `0x004df670-0x004df7d2` helper was not split.
  - After: [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) and [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) are direct class-owned reconstructable helpers emitted through this class.
  - Evidence: live IDA MCP showed `ITEM.TBL` / `ITEM.TBD`, `ITEM.EPF` / `ITEM.EPD`, `ItemInfo` `0x14` rows, `this+0x08/+0x0c/+0x14` layout, and no `LightObjImageLib` / `LIGHT.TBL` / `LightInfo` `0x1c` signals in either helper.
- 2026-06-18 B005 constructor source-quality sync:
  - [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) now carries first-draft constructor C++ and updated `87/90` scoring. Class-level C++ remains blank until the draw-method children and final original names are source-quality.
- 2026-06-19 B008 source-quality report:
  - Changed score from `86/85` to `88/89`, kept owner/emitter [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), resolved the class layout as one embedded `ProtectedArray<ItemInfo>` with default entry at object `+0x14`, supplied first-draft draw signatures and helper names, synced vtable inherited slots to `LObject::GetRuntimeClass` / `LObject::VirtualNoop(int, int)`, preserved the singleton/global/vtable source route, and kept formal class C++ blank pending exact draw by-memory children and standardized class declaration/source shape.
  - Evidence: local PE/Capstone confirmed method boundaries, padding spans, resource/global/vtable/remap operands, and representative draw call-site argument order; live IDA MCP was unavailable, so existing IDA exports and current support docs supplied the IDA-backed function/decompile side.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: recorded [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) as a concrete status-kind `2` consumer of `GetItemGlyphBounds` and `ItemObjImageLib::DrawItemImage`, using `ObjectStatusBlob` offsets `+4` and `+6` as item id and variant/palette byte.
- 2026-06-23 B002 destructor source-quality sync:
  - Score unchanged.
  - Evidence: current IDA MCP session `261fb29b` superseded older fallback-only destructor evidence for [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md), confirming no function/decompile model at `0x004dee20`, exact raw bytes and padding, no code/data/VA/RVA pointer route to the raw ordinary destructor start, class/template vtable refs, singleton lifecycle refs, scalar-deleting-destructor parity, and the accepted blank-C++/no-owner-rejection rationale.
- 2026-06-25 B005 accepted report implementation:
  - Score unchanged. Added exact draw child references [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md), [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md), [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md), and [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md), promoted [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) to exact by-memory, and recorded current MCP session `80de0a67` as the authoritative draw/glyph provenance superseding B008 fallback-only evidence for this range.
- 2026-06-26 B014 scalar deleting destructor source-quality callback:
  - Score unchanged. [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md) now routes directly through this class as source-declared/generated-binary scalar deleting destructor glue with a formal comment-only no-code marker. Source cleanup remains [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md); this class page keeps formal C++ blank because executable/no-code decisions live on exact children.
- 2026-06-27 B013 singleton cleanup helper source-quality callback:
  - Score unchanged. Replaced the stale `ItemObjImageLib::ClearSingleton` method label with constructor SEH singleton cleanup helper wording for [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md). Current MCP session `b001_000241_20260627` proves the exact `0xb` body, cleanup jump `0x00600158 -> 0x004e5ba0`, no ordinary callers/callees, negative data/VA/RVA pointer routes, file-level owner/emitter [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), and blank formal C++ generated-cleanup disposition.
