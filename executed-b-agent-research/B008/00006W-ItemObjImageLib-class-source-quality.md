** TARGET-REPORT-UID:00006W **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00006W ItemObjImageLib Class Source-Quality Report

## Executive Recommendation

Update [UID:00006W][ItemObjImageLib](../../../../../by-class/ItemObjImageLib.md) from `86/85` to `88/89`. Keep `CANONICAL_OWNER:0000KH`, keep `EMITTER_UIDS:0000KH`, keep `RECONSTRUCTABLE:TRUE`, and keep the formal `RECONSTRUCTION_CPP CODE` block blank for now.

The class is source-quality enough for a first-draft declaration and method prototypes in documentation, but not for formal by-class C++ emission yet. `by-class/-guidance.md` sets the active class-code gate at `90/90+`, and the four draw bodies are still aggregate-only under [UID:00017N][ItemObjImageLibLocalMethodCluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md). Emitting a class declaration now would also duplicate method surface that belongs on exact by-memory draw children once those pages exist.

Recommended source shape:

- Class/file route stays `NexusTK/render/ItemObjImageLib.cpp`; likely header is `NexusTK/render/ItemObjImageLib.h` or an adjacent render image-library header.
- Class state is one embedded `ProtectedArray<ItemInfo> m_itemInfos` at object `+0x04`. The default/fallback `ItemInfo` at object `+0x14` is the protected-array default entry, not a separate top-level `ItemObjImageLib` field.
- The best current draw API names remain `DrawItemImage`, `DrawItemImageIn43x43Slot`, `DrawItemImageUnscaled`, and `DrawItemImageScaled`.
- `GetItemGlyphBounds` remains a free helper in the same item-image module, not an `ItemObjImageLib` method.
- The vtable inherited slots should be named from current `LObject` support: `LObject::GetRuntimeClass` at slot `+0x04` and `LObject::VirtualNoop(int, int)` at slot `+0x08`, rather than "currently unnamed" / `nullsub_18` in source-facing prose.

## Evidence Checked

- Target and direct support docs: [ItemObjImageLib class](../../../../../by-class/ItemObjImageLib.md), [ItemObjImageLib file](../../../../../by-file/ItemObjImageLib.md), [ItemObjImageLibLayout](../../../../../by-type/by-struct/ItemObjImageLibLayout.md), [ItemInfo](../../../../../by-type/by-struct/ItemInfo.md), [ItemObjImageLibVtable](../../../../../by-type/by-vtable/ItemObjImageLibVtable.md), [g_pItemObjImageLib](../../../../../by-global/g_pItemObjImageLib.md), [0x0067a758 storage](../../../../../by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md), [ItemObjImageLibVtableData](../../../../../by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md), [ItemObjImageLibLocalMethodCluster](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md), constructor, ordinary destructor, table loader, frame-availability helper, singleton clear helper, scalar deleting destructor, [GetItemGlyphBounds](../../../../../by-item/GetItemGlyphBounds_004DF460.md), and [ItemObjImageLibLegacyItemRemapConstants](../../../../../by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md).
- Shared support docs: [ProtectedArray](../../../../../by-file/ProtectedArray.md), [ProtectedArrayTemplates](../../../../../by-type/by-template/ProtectedArrayTemplates.md), [ProtectedArrayLayout](../../../../../by-type/by-struct/ProtectedArrayLayout.md), [ProtectedArray_struct_ItemInfo_](../../../../../by-class/ProtectedArray_struct_ItemInfo_.md), [AlphaMaskSurface](../../../../../by-file/AlphaMaskSurface.md), [DrawEncodedAlphaFrame](../../../../../by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), [PaletteLibMethodCluster](../../../../../by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md), [ResourceLayoutTableLookupLayoutEntry](../../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [ResourceLayoutTableGetEntryRect](../../../../../by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md), [SurfaceRenderCallbackTable](../../../../../by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md), and current `LObject` class/file support.
- Prior accepted B report: `Agent-B005/research/executed/0002SD-ItemObjImageLibConstructor-source-quality.md`.
- Local IDA export/decompile JSON: `0x004dec30`, `0x004dee50`, `0x004defc0`, `0x004df1e0`, `0x004df2c0`, `0x004df460`, and `0x004df500` under `C:\Users\admin\Desktop\CTools\Output\ida\decompile`.
- Local PE/Capstone recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section map, exact bytes/bounds/padding, operand hits for vtables/globals/resource names/remap constants, and representative call-site argument setup.
- Generated output checked as a route lead only: `auto-generated/NexusTK/render/ItemObjImageLib.cpp` currently emits constructor code and legacy remap constants, with an empty marker for [UID:00006W].
- Historical `by-memory/-report.old.md` draw-signature rows were checked as non-authoritative leads. The recommendations below derive from current docs plus local IDA/PE evidence, not from Wave2/Wave3 recovered source.
- IDA MCP live endpoint checked on 2026-06-19 at `http://127.0.0.1:13337/mcp`; it was unavailable (`Unable to connect to the remote server`). This report uses existing IDA exports and a fresh local PE/Capstone pass instead.

No target/support by-* docs or coverage reports were edited.

## Binary Boundary And Reference Findings

Local PE/Capstone confirms the current half-open boundaries:

| Range | Size | Source role | Boundary notes |
| --- | ---: | --- | --- |
| `0x004dec30-0x004dee1b` | `0x1eb` | `ItemObjImageLib::ItemObjImageLib` | Returns at `0x004dee1a`; five `0xcc` bytes before ordinary destructor. |
| `0x004dee20-0x004dee4d` | `0x2d` | ordinary destructor body | Three `0xcc` bytes before `DrawItemImage`. |
| `0x004dee50-0x004defba` | `0x16a` | `DrawItemImage` | `ret 0x18`, six stack parameters after `this`; six `0xcc` bytes after. |
| `0x004defc0-0x004df1d4` | `0x214` | `DrawItemImageIn43x43Slot` | `ret 0x18`; twelve `0xcc` bytes after. |
| `0x004df1e0-0x004df2b7` | `0xd7` | `DrawItemImageUnscaled` | `ret 0x10`, four stack parameters after `this`; nine `0xcc` bytes after. |
| `0x004df2c0-0x004df455` | `0x195` | `DrawItemImageScaled` | `ret 0x10`; eleven `0xcc` bytes before glyph helper. |
| `0x004df460-0x004df4f9` | `0x99` | `GetItemGlyphBounds` | `__stdcall`, `ret 8`; seven `0xcc` bytes before table loader. |
| `0x004df500-0x004df668` | `0x168` | `LoadItemInfoTable` | Eight `0xcc` bytes before raw availability helper. |
| `0x004df670-0x004df7d2` | `0x162` | `RefreshItemFrameAvailability` | Fourteen `0xcc` bytes before `LightObjImageLib` constructor. |
| `0x004e5ba0-0x004e5bab` | `0x0b` | singleton clear helper | `mov [0x0067a758],0; ret`; five `0xcc` bytes after. |
| `0x004e6580-0x004e65dc` | `0x5c` | scalar deleting destructor | `ret 4`; four `0xcc` bytes before `LightObjImageLib` scalar deleting destructor. |

Operand scans against `.text` reconfirm key anchors:

- `0x0067a758` / `g_pItemObjImageLib`: 65 direct operand hits, matching existing singleton docs.
- `0x0061b73c` / `ItemObjImageLib` vtable: hits at constructor, ordinary destructor, and scalar deleting destructor vptr stores.
- `0x0061b734` / `ProtectedArray<ItemInfo>` vtable: hits at constructor, ordinary destructor, protected-array destructors, and scalar deleting destructor.
- `ITEM.TBL` / `0x0061c260`: constructor and `LoadItemInfoTable`.
- `ITEM.TBD` / `0x0061c274`: constructor and `LoadItemInfoTable`.
- `ITEM.EPF` / `0x0061c288`: general draw, fixed-slot draw, unscaled draw, scaled draw, glyph helper, and frame-availability helper.
- `ITEM.EPD` / `0x0061c29c`: fixed-slot draw, scaled draw, glyph helper, and frame-availability helper.
- `0x0066dad4/0x0066dad8/0x0066dadc`: three hits each from fixed-slot draw, scaled draw, and glyph helper, proving these live remap constants are item-image constants.

Representative call-site setup confirms the draw signatures:

- `0x005207f8` in `ObjectImageControlPane` pushes `this`/owner object, destination rect, descriptor item id at `+0x10c`, palette/tint byte at `+0x10e`, null overlay mask, and float zero before calling `DrawItemImage`.
- `0x0041f7bc` pushes owner/draw object, destination rect, item id, palette/tint byte, null overlay mask, and float zero before calling `DrawItemImageIn43x43Slot`.
- `0x0041f886`, `0x004ea49f`, and sibling callers push owner/draw object, destination rect, item id, and palette/tint byte before calling `DrawItemImageUnscaled`.
- `0x004aedd4`, `0x004ae2ca`, and item-menu callers push owner/draw object, destination rect, item id, and palette/tint byte before calling `DrawItemImageScaled`.

The first stack parameter after `this` is passed consistently but optimized unused in the four draw bodies. `Pane *drawOwner` is the best source-facing provisional name if the project has a common pane/control base type available; otherwise use `void *drawOwner` rather than overclaiming `GrafPort *`, because `ObjectImageControlPane` passes its own object pointer.

## Field And Layout Resolution

Recommended class layout wording:

```text
0x00  ItemObjImageLib vptr / LObject base
0x04  ProtectedArray<ItemInfo> m_itemInfos
       +0x00  concrete ProtectedArray<ItemInfo> vptr     (object +0x04)
       +0x04  int m_count                               (object +0x08)
       +0x08  ItemInfo *m_entries                       (object +0x0c)
       +0x0c  int m_defaultCapacity / m_reservedCount   (object +0x10)
       +0x10  ItemInfo m_defaultEntry                   (object +0x14)
```

Do not describe `object +0x14` as a separate top-level `fallbackItemInfo` field in a class declaration. It is still useful to call it the fallback/default row in behavior prose, but structurally it is the inline default entry of the embedded protected array.

Recommended `ItemInfo` names remain:

| Offset | Name | Confidence | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `itemTableId` | medium | Loaded from `ITEM.TBL`/`ITEM.TBD`; copied by draw paths; original name not proven. |
| `+0x04` | `paletteSlot` | high | Passed to `PaletteLib::GetSlotPalette` with category `10`. |
| `+0x08` | `alpha` | high | Read by draw paths as a float and used to select alpha/blend render options. |
| `+0x0c` | `renderFlagsOrMode` | medium | Loaded and copied; exact consumer semantics are not fully exposed in current draw decompilation. |
| `+0x10` | `allowPaletteFilter` | medium-high | Constructor loads a bool-like value, draw paths use it with `PaletteLib::IsPaletteFilterEnabled`, and the availability helper refreshes the byte from frame/palette checks. |

Rejected field alternatives:

- Separate top-level `ItemInfo fallbackItemInfo`: rejected for formal class layout because `ProtectedArrayLayout` proves `+0x10` suboffset is the template default entry.
- `itemInfoCountOrCapacity`: stale and ambiguous. Accessors, destructors, and resize support identify count at `ProtectedArray +0x04`; the current-capacity role is not proven for `+0x0c`.
- Strong names like `frameId`, `blendMode`, or `resourceFlags` for `ItemInfo +0x00/+0x0c`: not proven. Keep descriptive names and caveats.
- `frameAvailable` as the only name for `+0x10`: too narrow. The byte is refreshed from frame/palette availability but is also consumed as a palette-filter/draw allowance.

## Method And Helper Shape

Recommended source-facing signatures for documentation and future draw child pages:

```cpp
class ItemObjImageLib : public LObject
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(
        Pane *drawOwner,                 // provisional; body does not read it
        RectBounds *dstRect,
        short itemId,
        unsigned char paletteFlags,
        AlphaMaskSurface *overlayMask,
        float overlayStrength);

    int DrawItemImageIn43x43Slot(
        Pane *drawOwner,                 // provisional; body does not read it
        RectBounds *dstRect,
        short itemId,
        unsigned char paletteFlags,
        AlphaMaskSurface *overlayMask,
        float overlayStrength);

    int DrawItemImageUnscaled(
        Pane *drawOwner,                 // provisional; body does not read it
        RectBounds *dstRect,
        short itemId,
        unsigned char paletteFlags);

    int DrawItemImageScaled(
        Pane *drawOwner,                 // provisional; body does not read it
        RectBounds *dstRect,
        short itemId,
        unsigned char paletteFlags);

    void LoadItemInfoTable();
    void RefreshItemFrameAvailability();

private:
    ProtectedArray<ItemInfo> m_itemInfos;
};
```

Notes:

- Use `void *drawOwner` instead of `Pane *drawOwner` if the implementation pass is not ready to attach the pane/control base type. The parameter exists in all call sites but is optimized unused in these bodies.
- `overlayMask` maps to the optional first argument of [UID:0000YO][DrawEncodedAlphaFrame](../../../../../by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md). The helper belongs to the shared alpha-mask/surface blitter module, not `ItemObjImageLib`.
- `paletteFlags` is the byte whose high bits are passed as `a5 >> 5` to `PaletteLib::GetSlotPalette`; exact original spelling is unknown.
- `DrawItemImage` and `DrawItemImageIn43x43Slot` are overlay-capable (`ret 0x18`). `DrawItemImageUnscaled` and `DrawItemImageScaled` have no overlay output parameter (`ret 0x10`).
- `DrawItemImageIn43x43Slot`, `DrawItemImageScaled`, and `GetItemGlyphBounds` apply the non-EPF legacy remap constants. `DrawItemImage` and `DrawItemImageUnscaled` use the current `ITEM.EPF` path directly in current decompilation.

Helper/source-name resolution:

| Address/global | Recommended name/role | Owner |
| --- | --- | --- |
| `0x00457a60` | `EPFTileContext::InitTileContext` / frame context initializer | EPFTileContext support, dependency only. |
| `0x004d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | ResourceLayoutTable support, dependency only. |
| `0x004d0530` | `ResourceLayoutTable::GetEntryRect` | ResourceLayoutTable support, used by `GetItemGlyphBounds`. |
| `0x00543d20` | `PaletteLib::IsPaletteFilterEnabled` | PaletteLib support, dependency only. |
| `0x00543e40` | `PaletteLib::GetSlotPalette` | PaletteLib support, dependency only. |
| `0x00462f20` | `DrawEncodedAlphaFrame` | AlphaMaskSurface/surface blitter support, dependency only. |
| `0x0069b3e8` | surface render callback slot | Surface render callback table, dependency only. |
| `0x0067a758` | `g_pItemObjImageLib` | ItemObjImageLib file/class singleton. |
| `0x0066da97` | `g_useEpfAssets` | shared asset mode global; true selects EPF/TBL, false selects EPD/TBD. |
| `0x0066dad4/0x0066dad8/0x0066dadc` | `g_legacyItemImageMaxEntry`, `g_currentItemImageRemapFirstEntry`, `g_currentItemImageRemapLastEntry` | ItemObjImageLib file-static remap constants. |

## Relationships And Ownership

- Constructor [UID:0002SD] is already first-draft C++ ready and emitted through [UID:0000KH]. It initializes the singleton, the embedded protected array, the inline default entry, and the `ITEM.TBL`/`ITEM.TBD` records.
- `LoadItemInfoTable` [UID:0003LZ] is source-authored ItemObj class helper behavior, even though it has no direct call xrefs in current IDA. It duplicates the constructor's table load/resize loop and should remain class-owned under [UID:00006W] unless future caller evidence proves a different route.
- `RefreshItemFrameAvailability` [UID:0003ND] is source-authored raw helper behavior, with no IDA function object and no direct start xrefs. The prolog/body/return, `ItemInfo` loop, `ITEM.EPF`/`ITEM.EPD` strings, palette dependency, and `+0x10` writes justify the current class route.
- Ordinary destructor [UID:00017O] is the source destructor body. Scalar deleting destructor [UID:0002VC] is compiler-shaped wrapper glue around the same cleanup. Do not emit a handwritten scalar deleting destructor body in source.
- Singleton clear helper [UID:00017Y] is static-lifetime cleanup glue for `g_pItemObjImageLib`; source may express it through a static cleanup mechanism rather than an explicitly named method.
- Vtable data [UID:0002ML] and vtable type [UID:0001XW] are compiler-emitted from the class declaration. They should not emit hand-written dword tables.
- [UID:0000UQ] `GetItemGlyphBounds` is a free item-image helper with broad caller fanout. Keep it in the `ItemObjImageLib.cpp` module or a tiny item-image helper file, but not as a class method and not under UI pane owners.

Rejected ownership/source alternatives:

- `ImageLib`: dependency only. It provides shared image/resource infrastructure but does not own item-specific table rows, singleton, or remap constants.
- `PaletteLib`, `ResourceLayoutTable`, `EPFTileContext`, `AlphaMaskSurface`: dependencies only.
- UI caller ownership: rejected because callers only consume item drawing APIs and the singleton; they do not own storage, vtable, or resource table logic.
- Separate generated `class_ProtectedArray_struct_ItemInfo_` source: rejected. That is reusable template-instantiation support; the concrete item records and draw policy belong here.
- Handwritten vtable/static dword source: rejected because vtables and scalar deleting destructors are compiler effects of class declarations and virtual methods.

## C++ Readiness

Target formal C++: keep blank.

Target-specific no-code proof for the class page:

- `by-class/-guidance.md` says class C++ should not be emitted until the active `90/90+` reconstruction-code gate. This target should move only to `88/89`.
- The four draw methods do not have exact by-memory child pages yet. Full draw bodies belong on those exact by-memory pages, not on the class page.
- The class declaration/prototypes above are review-ready, but `drawOwner` static type and two `ItemInfo` field names remain inferred.
- Constructor C++ is already emitted through [UID:0002SD], and legacy constants are already emitted through [UID:0003ZN]. Duplicating those on the class page would pollute generated output.

Future C++ readiness:

- Ready now: class declaration draft/prototypes in prose; exact draw child page creation with the signatures above; support-doc slot/name cleanup.
- Not ready now: formal class `RECONSTRUCTION_CPP CODE` and aggregate draw method bodies.
- Draw children should be considered first-draft ready after split if their pages include the current decompile/Capstone evidence, current helper names, legacy remap constants, overlay helper dependency, and the `drawOwner` type caveat.

## Recommended Target Changes

Metadata:

```markdown
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current parent/C++ status wording with:

```markdown
- Parent/C++ status: attached to [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), the `NexusTK/render/ItemObjImageLib.cpp` source root that owns the item sprite singleton, layout, `ItemInfo` row type, global, constructor/destructor, draw paths, table reload helper, frame-availability helper, legacy item remap constants, and nearby glyph-bounds helper. The constructor and legacy remap constants already have first-draft C++ in exact child pages. This class page should keep formal C++ blank until the exact draw-method by-memory children exist and the class reaches the `90/90+` class-code gate; the first-draft declaration/signature shape is documented below.
```

Replace the observed-state section with the layout block from "Field And Layout Resolution" above. Explicitly note that object `+0x14` is `m_itemInfos.m_defaultEntry`, not a separate class member.

Replace method notes for the draw rows with source-facing signatures and helper dependencies:

```markdown
| `int DrawItemImage(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)` | `0x004dee50-0x004defba` | General item draw path. Uses `ITEM.EPF`, `PaletteLib::IsPaletteFilterEnabled`, `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, paletteFlags >> 5)`, surface render callback `dword_69B3E8`, and optional `DrawEncodedAlphaFrame` overlay output. `drawOwner` type remains provisional because the optimized body does not read it. |
| `int DrawItemImageIn43x43Slot(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)` | `0x004defc0-0x004df1d4` | Fixed 43x43 icon-slot draw path. Applies non-EPF legacy remap constants, clamps/recenters large source rectangles, renders through `dword_69B3E8`, and optionally emits overlay mask data. |
| `int DrawItemImageUnscaled(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)` | `0x004df1e0-0x004df2b7` | Direct unscaled `ITEM.EPF` draw path with non-overlay render option setup. |
| `int DrawItemImageScaled(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)` | `0x004df2c0-0x004df455` | Crop-to-fit/scaled item draw path. Applies non-EPF legacy remap constants and adjusts the source rectangle before dispatching the surface render callback. |
```

Add a "Source-Quality Notes" subsection:

```markdown
- The inherited vtable slots should be read as `LObject::GetRuntimeClass` and `LObject::VirtualNoop(int, int)` based on current LObject support docs; `sub_4F4B10` and `nullsub_18` are no longer useful source-facing names for this class page.
- The first stack parameter to all draw methods is passed by callers but optimized unused in the draw bodies. `Pane *drawOwner` is the best current source-facing guess; use `void *drawOwner` if the pane/control base type is not ready in a C++ draft.
- `ItemInfo +0x00` and `+0x0c` remain descriptive names (`itemTableId`, `renderFlagsOrMode`) rather than original-symbol proof. This should cap final confidence but not block child draw-page first drafts.
- `LoadItemInfoTable` and `RefreshItemFrameAvailability` are class helpers despite no direct caller/start-xref evidence. Their object layout, item resources, row stride, and negative LightObj evidence reject no-owner or LightObj routes.
- Formal by-class C++ remains blank by target-specific policy: class is below `90/90`, draw method bodies lack exact child pages, and by-class output must not duplicate constructor/remap child code already emitted through this source file.
```

Add a 2026-06-19 change-log entry:

```markdown
- 2026-06-19 B008 source-quality report: recommended `86/85 -> 88/89`, kept owner/emitter [UID:0000KH], resolved the class layout as one embedded `ProtectedArray<ItemInfo>` with default entry at object `+0x14`, supplied first-draft draw signatures and helper names, synced vtable inherited slots to `LObject::GetRuntimeClass` / `LObject::VirtualNoop(int, int)`, preserved the singleton/global/vtable source route, and kept formal class C++ blank until exact draw by-memory children and the `90/90+` class-code gate are satisfied. Local PE/Capstone confirmed method boundaries, padding spans, resource/global/vtable/remap operands, and representative draw call-site argument order; live IDA MCP was unavailable.
```

## Recommended Support-Doc Changes

Do not apply without supervisor callback.

1. [UID:0000KH][by-file/ItemObjImageLib.md](../../../../../by-file/ItemObjImageLib.md)
   - Keep score `89/86`.
   - Fix stale half-open spelling: ordinary destructor range should be `0x004dee20-0x004dee4d`; glyph helper should be `0x004df460-0x004df4f9`.
   - Add the four draw signatures and the `drawOwner` caveat.
   - Clarify that class formal C++ is blank because the class page is under the `90/90+` gate and draw methods need exact by-memory children, not because constructor helper names remain unresolved.
   - Mention likely header `render/ItemObjImageLib.h` as provisional.

2. [UID:0001UU][by-type/by-struct/ItemObjImageLibLayout.md](../../../../../by-type/by-struct/ItemObjImageLibLayout.md)
   - Recommended score `87/90` if implementation includes the resolved field wording; otherwise score can stay `86/89`.
   - Replace `itemInfoArray` / `fallbackItemInfo` split with `ProtectedArray<ItemInfo> m_itemInfos` and its internal `m_defaultEntry` at object `+0x14`.
   - Replace `itemInfoCountOrCapacity` with `m_itemInfos.m_count`; replace `initialOrGrowCapacity` with provisional `m_defaultCapacity` / `m_reservedCount` and preserve the evidence that reviewed bodies do not use it as ordinary current capacity.

3. [UID:0001UT][by-type/by-struct/ItemInfo.md](../../../../../by-type/by-struct/ItemInfo.md)
   - Keep score unless the supervisor wants a small confidence bump. Existing `85/89` is acceptable.
   - Add draw-signature support for `paletteSlot`, `alpha`, and `allowPaletteFilter`.
   - Preserve caveats for `itemTableId` and `renderFlagsOrMode`.

4. [UID:0001XW][by-type/by-vtable/ItemObjImageLibVtable.md](../../../../../by-type/by-vtable/ItemObjImageLibVtable.md)
   - No metadata change required, but update slot names:
     - `+0x04` -> inherited `LObject::GetRuntimeClass` / runtime-class accessor at `0x004f4b10`.
     - `+0x08` -> inherited `LObject::VirtualNoop(int, int)` at `0x0041b6c0`.
   - Keep the vtable source-declared/generated-binary no-code policy.

5. [UID:0002ML][by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md](../../../../../by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md)
   - Mirror the inherited slot names from the vtable type page.
   - Keep formal C++ blank; this is generated vtable data.

6. [UID:00017N][by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md](../../../../../by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
   - Keep `RECONSTRUCTABLE:FALSE`, owner `NONE`, and blank C++.
   - Add this report's four source-facing draw signatures and explicit recommendation to create exact draw by-memory child pages.
   - Keep the aggregate score unless exact children are created.

7. New exact draw child pages, future/supervisor-directed only
   - `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md`
   - `by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md`
   - `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md`
   - `by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md`
   - Recommended direct owner/emitter for these future method pages: [UID:00006W] class, flowing through [UID:0000KH] file. The constructor can remain file-owned by accepted precedent.

8. [UID:0000UQ][by-item/GetItemGlyphBounds_004DF460.md](../../../../../by-item/GetItemGlyphBounds_004DF460.md)
   - Keep current score/route.
   - Add a class cross-note that it is not a method, but it shares the item-image module, legacy remap constants, and `ITEM.EPF`/`ITEM.EPD` selection with fixed-slot/scaled draw.
   - Future optional promotion to exact by-memory page should use range `0x004df460-0x004df4f9` and free-helper owner/emitter [UID:0000KH].

9. [UID:0000RA][by-global/g_pItemObjImageLib.md](../../../../../by-global/g_pItemObjImageLib.md) and [UID:0001OT][by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md](../../../../../by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
   - No metadata change required.
   - Optionally add the local PE reconfirmation of 65 direct operand hits and representative draw caller consumers.

10. [UID:0000B8][by-class/ProtectedArray_struct_ItemInfo_.md](../../../../../by-class/ProtectedArray_struct_ItemInfo_.md)
    - No score change required.
    - Add a cross-note that `ItemObjImageLib +0x14` is the `ProtectedArray<ItemInfo>` default entry, not a separate class-owned field.

## Score And Metadata Rationale

Recommended target score: `88/89`.

- Completion `88`: class responsibilities, source route, singleton/global/vtable ownership, exact method ranges, constructor/destructor/table-loader/availability-helper relationships, `ProtectedArray<ItemInfo>` layout, `ItemInfo` field names, draw signatures, helper dependencies, legacy remap constants, and formal no-code policy are all now documented. Completion stays below `90` because draw methods are not split into exact child pages and formal class C++ should remain blank.
- Confidence `89`: existing IDA-backed docs, local decompile exports, current local PE/Capstone bytes, support docs, and accepted constructor/remap reports agree on ownership and behavior. Confidence stays below `90+` because live IDA MCP was unavailable, `drawOwner` static type is inferred, and two `ItemInfo` field names are descriptive rather than original-symbol proof.

Owner/emitter recommendation:

- Keep `CANONICAL_OWNER:0000KH` for the class page because the direct by-class page is attached to the source file root and current docs already route generated output through `NexusTK/render/ItemObjImageLib.cpp`.
- Keep `EMITTER_UIDS:0000KH`.
- Future draw child pages should use class owner/emitter [UID:00006W] because they are `this`-based methods and the class clears the parent gate.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` for this class-only implementation. No exact by-memory coverage replacement is recommended until exact draw child pages are created and assigned UIDs.

Recommended replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) : reconstructable : 88% : strong : Item sprite image-library singleton attached to `NexusTK/render/ItemObjImageLib.cpp`, with PE/IDA-export-confirmed constructor/destructor/draw/glyph/helper boundaries, `ProtectedArray<ItemInfo>` member layout (`m_count`, `m_entries`, provisional `m_defaultCapacity`, default `ItemInfo` entry), singleton/vtable/RTTI anchors, source-facing draw signatures, table-loader/frame-availability relationships, inherited `LObject::GetRuntimeClass`/`VirtualNoop` vtable slots, legacy remap constants, and a formal class-C++ no-code decision pending exact draw-method by-memory children and the `90/90+` class-code gate.
```

If the supervisor later creates exact draw child pages, `by-memory/-coverage-report.md` will need new child rows under [UID:00017N] with supervisor-assigned UIDs. Exact final row text cannot be given for those new rows until the UIDs exist; the ranges, names, owners, and signatures above are ready for that later split.

## Open Questions Resolved Or Retained

Resolved/high-probability:

- Source placement: `render/ItemObjImageLib.cpp`; likely header `render/ItemObjImageLib.h`.
- Singleton/global: `g_pItemObjImageLib` at `0x0067a758`, owned by this module.
- Vtable ownership: compiler artifact from `ItemObjImageLib` class declaration; inherited slots now name through `LObject`.
- Layout: one embedded `ProtectedArray<ItemInfo>`, with `m_defaultEntry` at object `+0x14`.
- Draw method argument counts/order: proved by `ret 0x18` / `ret 0x10`, local decompile JSON, and representative call-site push order.
- Overlay helper relationship: overlay-capable methods call shared `DrawEncodedAlphaFrame`; dependency is AlphaMaskSurface/surface support, not ItemObj-owned.
- Legacy remap constants: ItemObj-owned, consumed by fixed-slot draw, scaled draw, and glyph helper.
- `GetItemGlyphBounds`: free helper, not method.

Retained with evidence checked:

- Exact type of draw method first parameter: call sites pass owner/control objects and the bodies do not read the value. `Pane *drawOwner` is the best source-facing guess; `void *drawOwner` is safer if pane/control headers are not ready. `GrafPort *` is rejected as over-specific because `ObjectImageControlPane` passes `this`.
- Original spellings for `ItemInfo +0x00` and `+0x0c`: not recovered. `itemTableId` and `renderFlagsOrMode` remain descriptive names.
- Exact original helper name for `RefreshItemFrameAvailability`: no direct caller/start xrefs and no IDA function object. The current name is high-probability from body behavior and should remain provisional.
- Whether `LoadItemInfoTable` was a public method, private method, or unused/reload helper: no direct xrefs. Body is source-authored and class-owned either way.
- Exact class header basename: inferred from module pattern, not proven by symbols.

## IDA Rename/Type/Comment Recommendations

High confidence:

- Rename `sub_4DEE50` -> `ItemObjImageLib::DrawItemImage`.
- Rename `sub_4DEFC0` -> `ItemObjImageLib::DrawItemImageIn43x43Slot`.
- Rename `sub_4DF1E0` -> `ItemObjImageLib::DrawItemImageUnscaled`.
- Rename `sub_4DF2C0` -> `ItemObjImageLib::DrawItemImageScaled`.
- Rename `sub_4DF460` -> `GetItemGlyphBounds`.
- Ensure `sub_4DF500` is `ItemObjImageLib::LoadItemInfoTable` / `ItemObjImageLibLoadItemInfoTable`.
- Create/name raw function at `0x004df670-0x004df7d2` as `ItemObjImageLib::RefreshItemFrameAvailability` if IDA policy allows raw function creation.
- Rename `dword_67A758` -> `g_pItemObjImageLib`.
- Rename `word_66DAD4`, `word_66DAD8`, `word_66DADC` -> `g_legacyItemImageMaxEntry`, `g_currentItemImageRemapFirstEntry`, `g_currentItemImageRemapLastEntry`.
- Apply `ItemObjImageLib *` to `g_pItemObjImageLib`.

Medium/high confidence:

- Apply prototypes:
  - `int __thiscall ItemObjImageLib::DrawItemImage(ItemObjImageLib *this, Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);`
  - `int __thiscall ItemObjImageLib::DrawItemImageIn43x43Slot(ItemObjImageLib *this, Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);`
  - `int __thiscall ItemObjImageLib::DrawItemImageUnscaled(ItemObjImageLib *this, Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);`
  - `int __thiscall ItemObjImageLib::DrawItemImageScaled(ItemObjImageLib *this, Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);`
- If `Pane` is not available in IDA types, use `void *drawOwner` and add a comment that the parameter is passed but optimized unused.
- Define `struct ItemInfo` with the five fields listed above and 3 bytes trailing padding.
- Define/apply `ProtectedArray<ItemInfo>` layout so object `+0x14` is the template default entry.

Comments to add:

- At `0x004dee50` and `0x004defc0`: "Overlay-capable item draw. Optional overlay target is passed to shared DrawEncodedAlphaFrame."
- At `0x004defc0`, `0x004df2c0`, and `0x004df460`: "Uses ItemObjImageLib legacy item remap constants when g_useEpfAssets != 1."
- At `0x004df500`: "No direct xrefs in current IDA; source-authored table reload helper by body/layout/resource evidence."
- At `0x004df670`: "Raw unmodeled source helper; refreshes ItemInfo +0x10 availability/filter byte from ITEM.EPF/ITEM.EPD and PaletteLib."
- At vtable slot `0x0061b740`: inherited `LObject::GetRuntimeClass`.
- At vtable slot `0x0061b744`: inherited `LObject::VirtualNoop(int, int)`.

## Validation Commands Needed After Implementation Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00006W-ItemObjImageLib-class-source-quality-removed.md](00006W-ItemObjImageLib-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for support files actually edited. Do not edit or validate `by-memory/-coverage-report.md` unless the supervisor explicitly takes ownership of that file or creates exact draw children.

## Implementation Readiness

Ready for supervisor implementation callback on target/support docs. Not ready for formal class C++ emission. Ready for a future exact-draw-child split if the supervisor chooses that next step.

FINISHED report-only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00006W"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00006W-ItemObjImageLib-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00006W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
