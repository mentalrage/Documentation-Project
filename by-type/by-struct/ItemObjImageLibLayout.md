*** UID:0001UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The complete class declaration is header-owned below; no duplicate CPP-local class is emitted.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength);
    void DrawItemImageIn43x43Slot(
        GrafPort *drawPort,
        RectBounds *destinationBounds,
        short itemId,
        unsigned char paletteFlags,
        IntAlphaSurface *overlayMask,
        float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    void GetItemGlyphBounds(short itemId, RectBounds *outBounds);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};

extern ItemObjImageLib *g_pItemObjImageLib;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib Layout

## UID0000LO Gate 2A Header-Channel Repair - 2026-08-14

The complete declaration has moved from the CPP channel to this position-1 H
channel. `GetItemGlyphBounds` is inside the public member list, the stale free
declaration is absent, and the external singleton declaration remains after the
closed class. The class page supplies the guard/includes and `[[CHILDREN]]`
assembly point; this page supplies exactly one class payload and no duplicate
CPP-local class.

## UID00041S Fixed-Slot Draw Declaration Integration - 2026-08-11

- The position-1 managed class declaration carries the accepted source contract `void DrawItemImageIn43x43Slot(GrafPort *drawPort, RectBounds *destinationBounds, short itemId, unsigned char paletteFlags, IntAlphaSurface *overlayMask, float overlayStrength);`. All seven direct callers supply a `GrafPort *` receiver in the first stack slot and ignore `EAX`, while the body mutates the destination rectangle during 43-by-43 crop and recentering; `void *`, `Pane *`, `int` return, and `const RectBounds *` are therefore superseded for this method only.
- [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) owns the one qualified definition. This page supplies only the compile-visible member declaration and preserves the constructor, destructor, three other draw declarations, `GetItemGlyphBounds`, MapPane friendship, private refresh helper, exact `ProtectedArray<ItemInfo>` layout, and singleton declaration.
- The member's formal body is source-ready despite its deliberate partially initialized `SurfaceSpriteBlitOptions` local. Kinds `1`, `2`, and `3` reproduce the exact field writes, including kind `3` leaving `secondaryPaletteShift` at `+0x1c` unwritten before an installed RGB565 callback reads it. Zero-initializing the record would change observable behavior, so the accepted human-looking reconstruction preserves that latent original-source bug rather than replacing it with decompiler-shaped storage.
- Compile visibility is provided by the shared Surface declaration owner [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md), which defines the complete `SurfaceSpriteBlitOptions` ABI and callback typedef once. No duplicate callback/type declaration or method body is introduced in this class-layout page.
- Historical statements that grouped all four draw methods under a common no-code disposition remain useful as earlier audit history, but are superseded for UID00041S only. The other draw methods retain their independent contracts and blockers.

## UID0001OT Direct Singleton And Header Declaration Integration - 2026-07-20

- The position-1 managed declaration is the complete current class/header union. It preserves constructor/destructor, four draw methods, public `GetItemGlyphBounds`, private `RefreshItemFrameAvailability`, `friend class MapPane`, and the sole `ProtectedArray<ItemInfo> m_itemInfos` member while adding direct public `Singleton<ItemObjImageLib>` inheritance.
- Live RTTI independently records ItemObjImageLib, LObject, and `Singleton<ItemObjImageLib>` in the complete hierarchy. The Singleton base-class descriptor PMD is `{mdisp=4,pdisp=-1,vdisp=0}` with direct-base attributes; it is not an inferred synthetic mixin.
- The direct Singleton base is empty and overlaps `m_itemInfos` at complete-object `+0x04` through MSVC empty-base optimization. The object remains `0x28` bytes: LObject/vptr at `+0x00`, empty Singleton base plus protected-array vptr at `+0x04`, count `+0x08`, entries `+0x0c`, default/reserved capacity `+0x10`, and inline default ItemInfo at `+0x14`.
- The direct base source statement regenerates publication at constructor `0x004dec7b/0x004dec82`, constructor-unwind clear through the `0x004e5ba0` base-destructor instantiation, and ordinary/scalar clears. Those operations are compiler/template lowering and are intentionally absent from method bodies.
- Exactly one header-facing `extern ItemObjImageLib *g_pItemObjImageLib;` follows the closed class. [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) emits one position-0 module definition; [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md) is physical false/non-emitting storage.
- The class closes before the external declaration. Child method definitions continue to emit through the existing UID00006W child registry; no class member body, raw vtable data, template static definition, or duplicate global is introduced here.
- Historical layout statements that treated singleton publication/clear as handwritten constructor/destructor behavior are superseded only for source shape. Their exact addresses and binary effects remain valid evidence.

## UID0000UQ Public Glyph-Bounds Declaration Integration - 2026-07-16

- The position-1 managed declaration now includes exact public nonvirtual `void GetItemGlyphBounds(short itemId, RectBounds *outBounds);` after the four draw methods and before the private section.
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) owns the one qualified body at `92/94`; this layout page supplies only the compile-visible declaration and does not duplicate the definition.
- Exhaustive review of all 48 direct call sites across 23 functions proves every caller supplies `g_pItemObjImageLib` in `ECX`, while zero consume the machine result. The body optimizes away unused `this`; the accepted source contract is a void member, not a free `__stdcall` helper.
- Public access is supported by broad item-list/look/menu/inventory/preview and ItemObjectPane use. Exact original access spelling is not symbol-proven, but no private-only friend set covers the caller spread.
- Existing constructor/destructor/four draw declarations, `friend class MapPane`, private `RefreshItemFrameAvailability`, `ProtectedArray<ItemInfo> m_itemInfos`, fallback row, exact layout, and unrelated method/type caveats remain unchanged.
- Metadata remains `89/92`, owner/emitter UID00006W, reconstructable true, and position `1`. Historical free-helper wording belongs only in superseded evidence, not the current declaration route.

## UID0003HU Const General-Draw Declaration Integration - 2026-07-16

- The position-1 managed declaration now applies Destination 3 exactly: only the general `DrawItemImage` destination rectangle is `const RectBounds *dstRect`.
- The complete UID00041R body reads but never writes the destination rectangle. The refinement is source-legal, ABI-neutral, and lets [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) forward its established `const RectBounds *bounds` without a cast.
- UID0003HU forwards `GrafPort *target` as `drawOwner`, `m_itemId`, `m_paletteFlags`, null overlay, and zero strength, then ignores the helper's `int` status. No generic render-owner type stronger than `void *` is introduced.
- The fixed-slot, unscaled, and scaled draw declarations remain mutable exactly as before. Constructor, destructor, MapPane friendship, private refresh helper, `ProtectedArray<ItemInfo> m_itemInfos`, layout, fallback row, and all unrelated declarations remain unchanged.
- Metadata remains `89/92`, owner/emitter UID00006W, reconstructable true, position `1`. UID00041R's independent kind-3 partially initialized options-record no-code proof remains unresolved and is not hidden by this declaration correction.

## UID0003TX MapPane Friendship Integration - 2026-07-16

- The emitted ItemObjImageLib declaration retains its constructor, destructor, four draw methods, private frame-availability helper, and single `ProtectedArray<ItemInfo> m_itemInfos` member. The only source-access addition is `friend class MapPane;` in the private section.
- UID0002QN directly evaluates `g_pItemObjImageLib->m_itemInfos.GetAtOrDefault(unsigned short(status.m_appearanceId + 0x4000))`. Friendship is the period-plausible compile-visible representation of this observed direct access; no synthetic `Find`, `GetItemInfo`, or runtime accessor is introduced.
- Protected-array layout remains vptr `+0x04`, count `+0x08`, entries `+0x0c`, provisional default/reserved capacity `+0x10`, and embedded default `ItemInfo` row `+0x14`. The fallback row remains part of the template member, not a second top-level field.
- ItemInfo `+0x0c` is now source-facing `lightImageIndex`: nonnegative values feed MapPane lighting, while the fallback row's `-1` suppresses attachment. Palette/alpha/filter fields and all resource/reload/draw evidence remain unchanged.
- Constructor singleton publication, ordinary/scalar destructor cleanup, template vptr restoration, entry-buffer free, and singleton clear remain exact child or compiler lowering. They are not duplicated in this declaration.
- Historical lack-of-access and synthetic-wrapper questions are closed. Original friend placement/spelling remains inferred and caps confidence at `92`, but ownership, source placement, and compile visibility are no longer blockers.

## Status

- Confidence: very strong for direct bases, field offsets, `ProtectedArray<ItemInfo>` shape, fallback row placement, singleton/vtable anchors, table reload, destructor lowering, class size, and complete declaration shape. Exact historical header and template-member spelling remain the lexical confidence cap.
- Owner class: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md).
- Autogen parent: attached to [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md); the class and this layout both satisfy the parent gate.
- Evidence: IDA constructor/destructor/draw decompilation, vtable xrefs, singleton xrefs, and byte-boundary checks through 2026-05-31.

## Layout

```text
ItemObjImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<ItemObjImageLib> base (EBO overlap)
  +0x04  ProtectedArray<ItemInfo> m_itemInfos
```

Expanded view:

```text
  +0x04  void* m_itemInfos.vptr
  +0x08  int m_itemInfos.m_count
  +0x0c  ItemInfo* m_itemInfos.m_entries
  +0x10  int m_itemInfos.m_defaultCapacity / m_itemInfos.m_reservedCount
  +0x14  ItemInfo m_itemInfos.m_defaultEntry
```

## Notes

- Direct `Singleton<ItemObjImageLib>` base construction publishes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md); compiler lowering stores the [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md). The authored constructor initializes the protected array with capacity `10` and seeds the embedded default [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) entry with `-1`, `-1`, `0.0`, `-1`, `0`.
- The constructor opens `ITEM.TBL` in the current/extended item-table path and `ITEM.TBD` in the alternate legacy path, then reads `0x14`-byte [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) records.
- Draw methods index the array by an item entry id derived from `itemId + 0x4000`, falling back to the record at `+0x14` when out of range.
- Implicit member destruction frees the entry buffer at `+0x0c`; following direct Singleton-base destruction clears [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), then LObject teardown completes the chain. The scalar deleting destructor is a compiler wrapper around the same source lifetime.
- B002 current MCP session `261fb29b` confirms the ordinary destructor [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) pushes `[this+0x0c]`, restores the `ProtectedArray<ItemInfo>` vtable at `this+0x04`, calls `j_j_j___free_base`, clears current IDA label `dword_67A758` / source-facing [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), and tail-jumps to `LObject` cleanup. It does not touch `+0x08`, `+0x10`, or the inline default row at `+0x14`, reinforcing that `+0x14` is `m_itemInfos.m_defaultEntry`, not a separate top-level field.
- Object `+0x14` should not be declared as a separate top-level `fallbackItemInfo` member. It is the `ProtectedArray<ItemInfo>` inline default entry at suboffset `+0x10`. The fallback/default-row behavior is real, but the structural owner is the embedded protected array.
- The old `itemInfoCountOrCapacity` name is stale: reviewed accessors, destructors, and resize support identify object `+0x08` as the protected-array count. Object `+0x10` remains provisional as default/reserved capacity because reviewed bodies do not prove ordinary current-capacity semantics.
- The formal C++ block now emits the first-draft class/layout declaration only. Method bodies remain exact child-owned, and `void *drawOwner` is used for the unused first draw parameter to avoid overclaiming the pane/control base type before a draw-body source-quality pass.
- [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) now emits the exact private `RefreshItemFrameAvailability` body. The private declaration is included here because current MCP proves a `this`-based ItemObjImageLib row loop but finds no caller/public API route.

2026-05-31 IDA recheck confirms the exact constructor end at `0x004dee1b`, scalar deleting destructor range `0x004e6580-0x004e65dc`, vtable at `0x0061b73c`, and singleton writes/clears at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.

2026-06-16 C001 live IDA refresh reconfirmed the layout from current decompilation and xrefs: constructor `0x004dec30-0x004dee1b` writes the class vtable at `+0x00`, installs `ProtectedArray<ItemInfo>` at `+0x04`, initializes `+0x08/+0x0c/+0x10`, seeds the fallback row at `+0x14` with the documented `ItemInfo` defaults, and allocates/resizes item rows as `20 * count`. The table reload helper `0x004df500-0x004df668` uses the same `this+0x08/+0x0c/+0x14` layout, and scalar deleting destructor `0x004e6580-0x004e65dc` restores both vtables, frees the row buffer at `+0x0c`, and clears the singleton. `xrefs_to 0x0061b73c`, `0x0061b734`, and `0x0067a758` reconfirmed the documented vtable/template-vtable stores and 65 singleton refs. IDA was safely renamed from `sub_4DEC30`, `sub_4DF500`, `sub_4E6580`, and `dword_67A758` to `ItemObjImageLibConstructor`, `ItemObjImageLibLoadItemInfoTable`, `ItemObjImageLibScalarDeletingDestructor`, and `g_pItemObjImageLib`; the IDB was saved.

2026-06-23 B002 MCP session `261fb29b` saw current disassembly still print the singleton storage as `dword_67A758`. This does not change the source-facing documentation name `g_pItemObjImageLib`, but support pages should not imply current MCP already displays that symbol unless a future IDB rename pass reconfirms it.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)

## Changes

- 2026-07-20 B002 UID0001OT accepted source-quality callback:
  - Raised `89/92 -> 92/94` while preserving owner/emitter UID00006W and position `1`.
  - Added direct `Singleton<ItemObjImageLib>` inheritance and exactly one external global declaration after the closed class without losing any current method, access, friendship, field, or child route.
  - Incorporated exact RTTI PMD `+0x04`, EBO overlap, `0x28` size, compiler publication/unwind/ordinary/scalar lifecycle, one-definition, and no-duplicate-source evidence.

- 2026-07-16 B005 UID0003HT source-quality callback:
  - Preserved `89/92`, UID00006W owner/emitter, reconstructable true, position `1`, complete layout, friendship, existing declarations, private refresh helper, and unrelated history.
  - Applied the accepted complete formal block by adding public `GetItemGlyphBounds(short, RectBounds *)`.
  - Added exhaustive singleton-receiver/void-result/member evidence and preserved child-owned qualified definition/no-duplicate-source separation.
- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved `89/92`, UID00006W owner/emitter, reconstructable true, position `1`, exact layout, MapPane friendship, refresh helper, and all unrelated declarations.
  - Applied Destination 3 exactly by changing only the general DrawItemImage destination to `const RectBounds *dstRect`.
  - Added UID0003HU caller/source-legality evidence without changing ABI, other draw signatures, layout, or the helper's no-code disposition.
- 2026-07-12 B005 UID0003ND source-quality callback:
  - Added private `void RefreshItemFrameAvailability();` to the formal class/layout declaration and linked the exact child body. Score and owner/emitter metadata remain unchanged; exact original method spelling and caller reachability remain inferred/absent.
  - Set emitter position `1` so the class declaration precedes the position-`20` UID0003ND method definition in generated `ItemObjImageLib.cpp`.
- 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation:
  - Added the first-draft `ItemObjImageLib` class/layout declaration with `ProtectedArray<ItemInfo> m_itemInfos` and draw method prototypes. This page is the formal declaration route; exact method bodies remain child-owned, and `void *drawOwner` preserves the current type caveat.
- 2026-06-06: Attached the object layout to [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md). Scores remain `84/86`; this parent sync follows the already documented class/layout relationship and 80/80 gate.
- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: constructor, draw, ordinary destructor, scalar deleting destructor, vtable xrefs, singleton xrefs, and boundary bytes confirm the object layout, embedded fallback item info, and `ProtectedArray<ItemInfo>` storage. Scores remain below `95` because final field names and exact original header shape remain open.
- 2026-06-16 C001 assignment `C001-goal2-type-layout-ida-refresh-pursuit-item-light-20260616-11`: raised `84/86 -> 86/89` after live IDA reconfirmed constructor/reload/destructor agreement on the `ProtectedArray<ItemInfo>` header, `0x14` fallback row, `20 * count` item-row allocation, singleton lifecycle refs, and exact class/template vtable stores. Owner/emitter stay [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md); C++ stays blank because final field names and header/source declaration spelling are still provisional.
- 2026-06-19 B008 source-quality sync:
  - Raised `86/89 -> 87/90` after reclassifying object `+0x14` as `m_itemInfos.m_defaultEntry` instead of a separate top-level field, replacing stale count/capacity wording with `m_count`, `m_entries`, and provisional default/reserved capacity names, and preserving the fallback-row behavior in prose.
  - Evidence: local PE/Capstone and existing IDA exports agree with constructor, table reload, draw, ordinary destructor, and scalar deleting destructor use of the embedded `ProtectedArray<ItemInfo>` layout.
- 2026-06-23 B002 ordinary destructor source-quality sync:
  - Score unchanged.
  - Evidence: current MCP session `261fb29b` reconfirmed [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) as freeing only `m_itemInfos.m_entries` at object `+0x0c`, restoring the template vtable at `+0x04`, clearing current label `dword_67A758`, and leaving `+0x08`, `+0x10`, and inline default entry `+0x14` untouched.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0001UU)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The complete ItemObjImageLib declaration is installed with direct LObject and Singleton bases, exact 0x28 layout, typed g_pItemObjImageLib, receiver-backed draw methods, and free/file-local GetItemGlyphBounds because that call has no singleton receiver.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-092 | 0001UU | UID0002DL's two draw calls use `g_pItemObjImageLib`, while `GetItemGlyphBounds` is a no-receiver file helper. The complete ItemObjImageLib declaration must preserve that distinction and the one extern global. | Certain | Direct UID0002DL callsite receiver setup and current ItemObjImageLib layout/draw evidence. | UID0001UU complete formal; UID0000KH header/source placement; UID0002DL. | reject-stale | implemented |
