*** UID:0000KH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ItemObjImageLib

## UID0000KA Item-Render Consumer - 2026-08-15

Legacy and Pane2 paint methods consume `g_pItemObjImageLib`, `GetItemGlyphBounds`, `DrawItemImage`, and `DrawItemImageIn43x43Slot` through `render/ItemObjImageLib.h` with the accepted argument order and exact item id/icon-style fields. ItemObjImageLib retains glyph/image implementation and global ownership; inventory retains page selection, slot bounds, label/hotkey placement, and view mode. No feature-local draw wrapper or score change is introduced.

## UID00041S Fixed-Slot Draw Source Route - 2026-08-11

- `NexusTK/render/ItemObjImageLib.cpp` now receives exactly one accepted [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) definition as `void ItemObjImageLib::DrawItemImageIn43x43Slot(GrafPort *drawPort, RectBounds *destinationBounds, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`.
- The declaration emits once through [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md); the qualified body emits once through UID00041S. This by-file page remains the prose-only source root at `92/94` and introduces no duplicate class, callback ABI, global, or method body.
- The body preserves all recovered behavior: error-flag early return; unsigned item-entry conversion; legacy translated-band remap and high-entry clamp; fallback ItemInfo; palette-filter gate; `ITEM.EPF`/`ITEM.EPD` lookup; slot-10 palette resolution; source crop; destination recenter into a 43-by-43 slot; nullable slot-2 callback options; and optional encoded-alpha overlay output.
- Compile visibility is explicit. [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) emits `#include "EPFTileContext.h"`, `#include "ImageLib.h"`, and `#include "Surface.h"` before the singleton definition. [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) owns the complete `SurfaceSpriteBlitOptions`/`SurfaceSpriteBlitProc`/`g_pfnBlitSprite` declaration. GrafPort source includes `Surface.h`, while GrafPort's header needs only its existing pointer forward declaration.
- The callback options local intentionally remains uninitialized. Kinds `1`, `2`, and `3` match the exact target writes, and kind `3` leaves `secondaryPaletteShift` at `+0x1c` unwritten before RGB565 consumes it. This recovered latent defect is part of behavioral fidelity; zero-initialization would alter the original executable's behavior.
- Historical generated audits and class-wide summaries that placed all four draw methods under a no-code disposition remain preserved as dated evidence but are superseded for UID00041S only. The other three draw children retain independent dispositions, and generated refresh/readback remains supervisor-owned.

## UID0001OT Direct Singleton And One-Definition Source Route - 2026-07-20

- This prose-only root is now `92/94`. It retains `NexusTK/render/` and carries no reconstruction metadata; exact header declarations, source definitions, and method bodies remain on ordinary class/type/global/method emitters.
- The complete class declaration in UID0001UU derives from `LObject` and `Singleton<ItemObjImageLib>`. Direct RTTI and PMD `0,4,0` prove the empty template base, while empty-base optimization preserves the `0x28` object and all existing `ProtectedArray<ItemInfo>` offsets.
- Header/source one-definition policy is explicit: one `extern ItemObjImageLib *g_pItemObjImageLib;` follows the complete class declaration, and UID0000RA supplies exactly one `ItemObjImageLib *g_pItemObjImageLib = 0;` definition in this module. UID0001OT is physical storage evidence and emits no duplicate declaration or definition.
- The exact slot has 65 xrefs: five compiler-lifetime writes and 60 reads across 26 recognized functions. Constructor publication, ordinary destruction, constructor-unwind destruction, and scalar-wrapper cleanup are direct Singleton lowering; broad UI readers are consumers, not owners.
- UID0002SD emits the authored constructor with a `Singleton<ItemObjImageLib>()` base initializer and no manual global assignment. UID00017O emits the sole authored destructor as an empty body; implicit `ProtectedArray<ItemInfo>`, Singleton, and `LObject` teardown regenerates all observed cleanup.
- UID00017Y is the constructor-unwind-only Singleton base destructor. UID0002VC is the compiler scalar deleting wrapper. UID0001XW and UID0002ML are compiler RTTI/vtable support. All four are false/non-emitting with blank formal C++; no vptr stores, clears, frees, EH wrappers, delete flags, size guards, storage-free calls, RTTI arrays, or vtable dwords are handwritten.
- Generated-source contract: one complete direct-Singleton class declaration, one extern declaration, one zero definition, one constructor with Singleton initializer, one empty ordinary destructor, the accepted UID00041S fixed-slot draw body, and no physical-slot/helper/scalar/vtable/RTTI marker or source pollution. The other three draw children retain their accepted target-specific dispositions.

## UID0000UQ GetItemGlyphBounds Member Source Route - 2026-07-16

- `NexusTK/render/ItemObjImageLib.cpp` now receives exactly one [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) definition as `void ItemObjImageLib::GetItemGlyphBounds(short itemId, RectBounds *outBounds)`.
- The declaration is emitted once through [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md); the qualified body is emitted once through UID0000UQ. This by-file page remains prose-only at `92/94` and carries no reconstruction metadata.
- Exhaustive audit of all 48 direct calls across 23 functions proves every caller supplies `g_pItemObjImageLib` in `ECX`; zero consume the machine result. The body optimizes away unused `this`, so historical free/`__stdcall` classification is superseded.
- Exact behavior remains unsigned `itemId + 0x4000`, legacy translated-band add `0xff53`, clamp to `0x0972`, `ITEM.EPF`/`ITEM.EPD` selection, `g_pEPFLib->GetEntryRect`, and half-tile offset.
- UID0000UQ remains the exact `[0x004df460,0x004df4f9)` child with eleven predecessor and seven successor alignment bytes, 48 direct code xrefs, no raw VA/RVA pointer hit, source-facing void output, and class owner/emitter UID00006W.
- Constructor/destructor, all four draw paths, table reload, frame availability, singleton lifecycle, scalar/vtable/template/compiler coverage, resources, remap constants, and all unrelated file history remain preserved. UID00041S's former options-record no-code conclusion is superseded by its accepted behavior-preserving source body; the other draw children remain independent.
- Generated output must contain one class declaration and one qualified member definition, with no unqualified free definition, duplicate class/global/helper source, or UID0000UQ Empty Emitter Marker.

## UID0003HU General Draw Source Synchronization - 2026-07-16

- UID00041R retains `88/91`, owner/emitter UID00006W, blank formal body, complete general item-draw behavior, and its exact kind-3 options-record no-code proof.
- Its source-facing declaration is refined only to `int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`.
- The complete helper reads but never writes destination bounds; `const` is source-legal and ABI-neutral. The other three draw-method declarations remain unchanged.
- [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) is a direct caller from `NexusTK/map/ItemObjectPane.cpp`. It passes `GrafPort *target`, const bounds, `m_itemId`, `m_paletteFlags`, null overlay, and zero strength, and ignores the helper's `int` status.
- ItemObjImageLib remains the callee owner/source family; ItemObjectPane remains the caller owner. No method migration, duplicate source, cast, or return-type change is introduced.
- This by-file root remains prose-only with path `NexusTK/render/`. Its callback score is `92/94` after complete direct-Singleton, lifetime, one-definition, and compiler/source closure. All current vtable/layout/resource/draw/reload/destructor/helper content is preserved.

## UID0003TX Item-Lighting Source Synchronization - 2026-07-16

- The ItemObjImageLib source family now records the direct MapPane consumer of `ItemInfo::lightImageIndex`: corrected UID0002QN indexes the protected array by unsigned `appearanceId + 0x4000`, uses the embedded default row on miss, and attaches lighting only for a nonnegative index.
- Compile visibility is source-era friendship in the exact layout declaration: `friend class MapPane;`. No synthetic `Find`, public getter, duplicate row type, or runtime wrapper is introduced in `ItemObjImageLib.cpp`.
- The `0x14` ItemInfo row keeps itemTableId, palette slot, alpha, signed light image index, palette-filter flag, and padding. Constructor/reload/default-row/draw/availability consumers and `ITEM.TBL`/`ITEM.TBD` resource policy remain intact.
- Singleton publication/clear, ProtectedArray vtable/storage, entry-buffer allocation/free, scalar deleting wrapper, and compiler startup/cleanup remain exact child/generated behavior. The layout child emits one declaration and exact method children emit their bodies once.
- Historical `renderFlagsOrMode` and unresolved-access wording are superseded; all unrelated resource, draw, destructor, and helper evidence remains preserved. This by-file root stays prose-only with no reconstruction metadata.

## Status

- Confidence: very strong for class role, method ownership, direct Singleton/vtable ownership, one-definition policy, compiler lowering, and resource policy; the exact original header basename remains unproven and caps only filename certainty.
- Proposed module: `render/ItemObjImageLib.cpp`; likely header `render/ItemObjImageLib.h` by module naming pattern, but original header basename is not symbol-proven.
- Current recovered source: `source-3/simroot_v2/class_ItemObjImageLib.cpp`
- Main address ranges: `0x004dec30-0x004df500`, table helper `0x004df500-0x004df668`, frame-availability helper `0x004df670-0x004df7d2`, constructor SEH singleton cleanup helper `0x004e5ba0-0x004e5bab`, and scalar destructor `0x004e6580-0x004e65dc`
- Primary global instance: [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) at `0x0067a758`
- Primary vtable: [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) at `0x0061b73c`
- Layout/type docs: [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md), [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)

## File Role

`ItemObjImageLib` is the item sprite image library. It owns the per-item image metadata loaded from `ITEM.TBL` or `ITEM.TBD`, exposes the shared item drawing API used by item lists and look panes, and applies palette/tint/filter policy before dispatching the low-level item blitter.

This should stay separate from [UID:0000K2][ImageLib](by-file/ImageLib.md). `ImageLib` and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) provide the shared EPF/EPD frame lookup layer, while `ItemObjImageLib` owns item-specific table rows, legacy item-entry remapping, fixed-slot centering, crop-to-fit draw variants, palette slot `10`, and optional overlay/highlight passes.

## Owned And Nearby Helpers

The current class file owns the constructor, four draw methods, ordinary destructor source, and the source declarations that cause compiler singleton/ABI output. UID00017O's raw unmodeled bytes have no direct pointer route but are exactly regenerated by an empty authored destructor plus implicit member/base teardown. UID0002VC routes semantically through UID00006W but is false/non-emitting compiler scalar glue. UID00017Y is likewise false/non-emitting constructor-unwind-only Singleton base destruction, proven by the exact eleven-byte clear body and sole cleanup jump. Neither compiler page is a source helper or emitter.

The adjacent [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) member shares the same item archive globals, legacy item remap constants, and `ITEM.EPF` / `ITEM.EPD` selection as the fixed-slot/scaled draw paths. It resolves item icon bounds for broad UI and ItemObjectPane callers, centering frames with [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md). Its broad use and exhaustive singleton-receiver proof establish a public ItemObjImageLib method, not a UI-owned or separate free helper.

Two exact post-glyph helpers are now part of this module. [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) loads `ITEM.TBL` / `ITEM.TBD` into the `ItemInfo` array and replaces the stale `LightInfoTableLoader` classification. [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) is a private raw/unmodeled helper that now emits first-draft C++; it refreshes `ItemInfo::allowPaletteFilter` from `ITEM.EPF` / `ITEM.EPD` decoded pixels and the row's category-10 `DLPalette`. Current MCP session `359c7886` reconfirms exact raw boundaries and behavior while preserving no function object, direct start xref, or VA/RVA pointer route. Those negatives cap source-name/reachability confidence but do not move the helper away from this module or make it an empty emitter.

Historical B005 2026-06-18 source-quality work raised the exact constructor child [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) to first-draft readiness using then-provisional `renderFlagsOrMode`. The constructor remains in this source root with the same DATFile scalar-reader aliases and now uses `lightImageIndex`, synchronized to the direct MapPane consumer; no other constructor or draw-family fact changes.

B005's 2026-07-12 UID0003ND callback fills the frame-availability helper without changing the broader file score or path. The accepted body uses the existing `ProtectedArray<ItemInfo>` layout and source APIs `EPFTileContext::Initialize`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::GetSlotPalette`, and `EPFTileContext::ContainsIndexedPixelInRanges`. `RefreshItemFrameAvailability` and `allowPaletteFilter` remain descriptive inferred spellings; the exact child preserves the full current MCP branch/call/write and raw-liveness evidence.

B008/B005/B014 historical passes established exact draw children and compiler-wrapper evidence. The 2026-07-20 B002 callback supersedes only the old destructor and comment-emitter conclusions: UID00017O now emits the source-safe empty ordinary destructor, while UID0002VC is false/non-emitting with blank formal C++. Draw children retain their independent options-record dispositions. The current source-facing draw APIs are:

| Method | Signature and role |
| --- | --- |
| [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) `DrawItemImage` | `int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`; general `ITEM.EPF` item draw path with read-only destination bounds, slot-10 palette setup, slot-2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` dispatch, optional overlay output through [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), and direct UID0003HU GrafPort caller evidence. Formal C++ remains blank because option kind `3` leaves RGB565-read secondary byte `+0x1c` unwritten. |
| [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md) `DrawItemImageIn43x43Slot` | `void DrawItemImageIn43x43Slot(GrafPort *drawPort, RectBounds *destinationBounds, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`; source-ready fixed `43x43` slot draw with legacy remap, crop/recenter behavior, `g_pfnBlitSprite` dispatch, deliberate partial options initialization, and optional overlay output. |
| [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md) `DrawItemImageUnscaled` | `int DrawItemImageUnscaled(Pane *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`; direct unscaled `ITEM.EPF` draw path without overlay output. |
| [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) `DrawItemImageScaled` | `int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags)`; scaled/crop-to-fit draw path with legacy remap, slot-10 palette selection, center-crop math, and surface render callback dispatch. Formal C++ remains blank because the target-local slot-2 options record cannot yet be safely represented as a concrete source type. |

Historical all-draw `void *drawOwner` wording is superseded for UID00041S. Its seven caller sites and slot-2 receiver flow establish `GrafPort *drawPort`; UID0001UU now carries that exact declaration. The other draw methods retain their independently supported parameter types until their own caller-specific passes justify refinement.

B005 current MCP session `80de0a67` supersedes the fallback-only B008 provenance for the draw/glyph range. The session confirmed `sub_4DEE50`, `sub_4DEFC0`, `sub_4DF1E0`, `sub_4DF2C0`, and `sub_4DF460` with exact sizes, xref counts 29/7/7/5/48, shared EPF/resource lookup, palette helpers, render callback table, optional overlay helper only in the first two draw paths, legacy remap constants only in fixed-slot/scaled/glyph paths, and padding at every local boundary. Full child evidence lives on the exact by-memory pages above.

B005 2026-07-02 accepted UID00041U callback refines the generated-output disposition for `DrawItemImageScaled`: current MCP session `supervisor_resume_20260629` confirms exact range `0x004df2c0-0x004df455`, five direct callers, helper names, remap constants, palette/filter behavior, callback order, and source-crop math. The remaining formal-C++ blocker is not generic helper naming. Surface slot 2 should be documented as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, returning `int`, with draw receiver in `ecx`, six stack arguments, and nullable `const SurfaceSpriteBlitOptions *options`; UID00041U stays blank because it uses option kind `6` but initializes only `+0` and conditionally `+8`, while the installed RGB565 option-6 path reads `+0x1c`. Raw byte arrays, two-field structs, zero-init structs, partial-init structs, and scalar `int flags` are rejected as decompiler-shaped or behavior-unsafe.

B003 2026-07-02 accepted UID00041R callback refines the generated-output disposition for `DrawItemImage`: current MCP session `supervisor_resume_20260629` confirms exact range `0x004dee50-0x004defba`, size `0x16a`, 29 direct callers, ABI `ret 18h`, current `ITEM.EPF` entry computation `itemId + 0x4000`, helper names `EPFTileContext::InitTileContext`, `ResourceLayoutTable::LookupLayoutEntry`, `PaletteLib::IsPaletteFilterEnabled`, `PaletteLib::GetSlotPalette`, slot-2 `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and `AlphaMaskSurface::DrawEncodedAlphaFrame`. The remaining formal-C++ blocker is not generic helper, callback, or overlay uncertainty. UID00041R stays blank because alpha-plus-palette option kind `3` writes only kind `+0x00`, alpha `+0x04`, and palette/tint `+0x08`, while the installed RGB565 tag-3 path reads target-unwritten secondary byte `+0x1c` at `0x004c189d`. A zero-initialized `SurfaceSpriteBlitOptions` local would change observed behavior; raw byte arrays, target-local casts, partial-init structs, and scalar `int flags` remain rejected.

The generated one-function file name `LookupItemAtlasRect_004DF460.cpp` is stale historical provenance. Current source uses the qualified `ItemObjImageLib::GetItemGlyphBounds` member in this module.

The generated `ProtectedArray_struct_ItemInfo_` file is a concrete template instantiation for this module's item metadata table. Treat [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) as shared utility support and keep item table parsing/drawing here. The [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) documented for this module is the render image-table row loaded from `ITEM.TBL` / `ITEM.TBD`; it should not be confused with broader gameplay item-database records used by item mixing and inventory logic.

[UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) is a concrete UI preview consumer of this module's item path. Its status-kind `2` branch calls [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) with `ObjectStatusBlob` offset `+4` / `m_appearanceId`, then calls [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) with the same item id and offset `+6` / `m_variantOrPalette`. This is consumer evidence only; item table and draw ownership stay in `ItemObjImageLib.cpp`.

## Singleton Global

`g_pItemObjImageLib` is backed by current MCP label `dword_67A758` at [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md). IDA MCP on 2026-05-25, current B002 session `261fb29b`, and B013 current session `b001_000241_20260627` report 65 refs, with lifecycle writes from the constructor at `0x004dec7b` and `0x004dec82`, ordinary destructor clear at `0x004dee3b`, constructor SEH cleanup helper clear at `0x004e5ba0`, and scalar deleting destructor clear at `0x004e659e`.

Current generated material also uses aliases such as `g_pItemObjectImageLib`, `g_pItemImageLib`, and raw `dword_67A758`. Normalize those to `g_pItemObjImageLib` unless stronger original-symbol evidence appears.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `ITEM.TBL` | Main item metadata table in the extended item-archive path. |
| `ITEM.TBD` | Alternate/legacy item metadata table selected by the legacy item-table gate. |
| `ITEM.EPF` | Modern item sprite frame archive. |
| `ITEM.EPD` | Legacy item sprite frame archive used when extended archives are disabled. |
| `ITEM.PAL` | Palette slot `10` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

The legacy item path derives an entry index from `itemId + 0x4000`, rebases a configured translated band by `+16211`, and clamps entries above the archive floor to `2418`. The same policy appears in the draw methods and `GetItemGlyphBounds`.

[UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md) reanalysis resolves the live [UID:0003ZN][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md) subgroup as ItemObjImageLib legacy item-entry remap constants: `g_legacyItemImageMaxEntry = 0x0972`, `g_currentItemImageRemapFirstEntry = 0x0a20`, and `g_currentItemImageRemapLastEntry = 0x0a56`. They are read by [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md), [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md), and [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) when `g_useEpfAssets != 1`; the code remaps entries in `0x0a20..0x0a56` by adding `0xff53` and clamps other entries above `0x0972` back to `0x0972`.

## Batch 012 Parent-Gate Evidence

The exact vtable-data child [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md) is directly owned by this source module. Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) and confirmed the `ItemObjImageLib` RTTI locator at `0x0061b738`, vtable slot dwords at `0x0061b73c-0x0061b744`, constructor/destructor/scalar-deleting-destructor vptr stores, and adjacent `ProtectedArray<ItemInfo>` and `ProtectedArray<LightInfo>` boundaries.

That evidence is enough to treat this by-file page as an `85/85` direct parent for the vtable-data child under the corrected Batch 012 assignment gate. The vtable bytes remain `source-declared/generated-binary`; this page owns the class declaration and virtual method set that should cause the rebuilt compiler/linker to emit the equivalent RTTI/vtable artifact, but the child should not contribute handwritten C++ code.

## 2026-07-01 B007 Generated-Output Audit

Generated `auto-generated/NexusTK/render/ItemObjImageLib.cpp` was audited from the report snapshot with header proof `validator-command-id: 000000003240` and `validator-refreshed-at: 2026-07-01T04:25:52-04:00`. The tracker row showed 16 total emitters, 2 filled, 14 empty, 12.5%, and no by-file report coverage at that time.

At that historical audit, populated output was limited to UID0002SD constructor C++ and a UID0002VC comment-only marker. The latter is superseded by the 2026-07-20 false/non-emitting blank-formal correction.

The 14 empty markers were triaged as follows. [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) is a duplicate class route and now emits only a formal comment marker; the first-draft class/layout declaration is emitted through [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) to avoid duplicate declarations. [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) now emits the first-draft `ItemObjImageLib` declaration with `ProtectedArray<ItemInfo> m_itemInfos` and method prototypes. [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) now emits the first-draft `0x14`-byte row struct. [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) now emits the canonical source-facing singleton declaration `ItemObjImageLib *g_pItemObjImageLib = 0;`.

At that historical audit, UID0001XW, UID0001OT, UID00017O, UID00017Y, and UID0002ML were represented by comment-only markers. Current disposition is different: UID00017O emits the empty authored destructor, while UID0001XW, UID0001OT, UID00017Y, UID0002VC, and UID0002ML are false/non-emitting with literally blank managed C++.

At the 2026-07-01 audit, UID00041R/S/T/U and UID0000UQ were intentionally blank. That snapshot is historical. The later UID0003HT callback resolves UID0000UQ as a source-ready qualified member, and the 2026-08-11 UID00041S callback resolves the fixed-slot draw as source-ready while preserving its partially initialized options behavior. UID00041R, UID00041T, and UID00041U retain their independent dispositions.

The accepted source route is UID0000KH as the prose-only file root, UID00006W as the class route, UID0001UU as the complete declaration, UID0001UT as the row declaration, UID0000RA as the sole singleton definition, and generated path `NexusTK/render/ItemObjImageLib.cpp`. Broad by-file and by-class source remain nonduplicating because declarations and exact bodies are child-owned. Rejected routes include UI ownership, free/static glyph ownership, shared helper-library ownership, physical-slot emission, explicit Singleton assignment/clear, compiler wrapper/table source, and duplicate global definitions.

## Cross-References

- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md)
- [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md)
- [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md)
- [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md)
- [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md)
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md)
- [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md)
- [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md)
- [UID:0003ZN][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)

## Changes

- 2026-07-16 B005 UID0003HT source-quality callback:
  - Preserved `90/88`, `NexusTK/render/`, prose-only by-file disposition, singleton/vtable/layout/resources/draw/reload/destructor/helper inventory, and all unrelated history.
  - Synchronized public UID0000UQ member declaration/qualified definition ownership, exhaustive receiver/result evidence, generated expectations, and superseded free/`__stdcall` route.
  - Kept all four draw-child no-code proofs, constructor/destructor/compiler separation, and no-duplicate-source rules unchanged.
- 2026-07-16 Agent-B001 UID0003HU callback:
  - Preserved path `NexusTK/render/`, file ownership, prose-only disposition, and the authoritative validator-backed `90/88` score.
  - Synchronized only UID00041R's `const RectBounds *dstRect` declaration and the exact UID0003HU GrafPort/bounds/item/palette/null-overlay/zero-strength caller with ignored return.
  - Preserved all unrelated singleton/vtable/layout/resource/draw/reload/destructor/helper content and the kind-3 no-code proof.
- 2026-07-12 B005 UID0003ND source-quality callback:
  - Score/path/grouping unchanged. Updated the post-glyph helper and generated-output disposition so [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) contributes its accepted private first-draft body through `NexusTK/render/ItemObjImageLib.cpp`; preserved no-function/no-caller/no-pointer-route evidence and inferred-name caveats from current MCP session `359c7886`.
- 2026-07-02 B005 UID00041U source-quality callback:
  - Score/path unchanged. Synchronized `DrawItemImageScaled` to the formal-safe `void *drawOwner` declaration and updated the generated-output audit: UID00041U still has blank formal C++, but now for the exact unsafe slot-2 options-record reason rather than broad helper/callback uncertainty.
  - Evidence: UID00041U current MCP session `supervisor_resume_20260629` proves exact range, padding, callers, helper names, remap constants, palette behavior, callback order, target-local options writes, installed slot-target reads, and crop/scale math. Surface support now documents `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with nullable `const SurfaceSpriteBlitOptions *options`.
- 2026-07-02 B003 UID00041R source-quality callback:
  - Score/path unchanged. Synchronized `DrawItemImage` to the formal-safe `void *drawOwner` declaration and updated the generated-output audit: UID00041R still has blank formal C++, but now for the exact kind-3 slot-2 options-record reason rather than broad helper/callback/overlay uncertainty.
  - Evidence: UID00041R current MCP session `supervisor_resume_20260629` proves exact range `0x004dee50-0x004defba`, size `0x16a`, 29 direct xrefs, ABI `ret 18h`, current EPF path without legacy remap constants, helper names, callback order, `DrawEncodedAlphaFrame` route, and target-local options writes. Surface support already documents `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` with nullable `const SurfaceSpriteBlitOptions *options`; UID00041R remains blank because RGB565 tag `3` reads target-unwritten `+0x1c`.
- 2026-07-01 B007 accepted ItemObjImageLib empty-emitter implementation:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:88`, preserving `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"` and `CANONICAL_OWNER:FILE`.
  - Summary/evidence: incorporated the generated-output audit for `validator-command-id: 000000003240`, tracker row `16` total / `2` filled / `14` empty / `12.5%`, populated constructor/scalar-deleting-destructor outputs, first-draft declaration decisions for [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md), and [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md), comment-only no-code dispositions for generated-binary/ABI/storage-duplicate artifacts, and explicit draw/glyph no-code blockers.
- 2026-06-18 B002 Rule 26 incorporation for [UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md):
  - Added the exact [UID:0003ZN][0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants](by-memory/0x0066dad4-0x0066dae0.ItemObjImageLibLegacyItemRemapConstants.md) source route, names, values, draw/glyph consumers, add-immediate `0xff53`, and clamp policy.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: item sprite library role, singleton/vtable/layout anchors, resource inputs, legacy remapping policy, draw/helper ownership, destructor/singleton clear, and alias normalization are documented; confidence is capped by exact original filename and free-helper placement.
- 2026-05-31 projected path and IDA range correction:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the main range summary used old ends `0x004df454` and `0x004e65db`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CONFIDENCE:84`, and corrected exclusive-end ranges `0x004df455` and `0x004e65dc`.
  - Summary/evidence: `proposed-source-tree.md` already places `ItemObjImageLib.cpp` under `render/`; IDA MCP confirmed constructor/draw/scalar bounds and ordinary destructor bytes on 2026-05-31.
- 2026-06-07 A003 Batch 012 parent gate:
  - What existed before: the page was `88/84`, below the corrected direct-parent assignment gate for [UID:0002ML][0x0061b738-0x0061b748.ItemObjImageLibVtableData](by-memory/0x0061b738-0x0061b748.ItemObjImageLibVtableData.md).
  - Changed to: `89/86`, added current hash-backed vtable ownership evidence, and documented why this source-file page directly owns the source declaration effect.
  - Summary/evidence: the source module already documents item sprite resources, table parsing, draw/helper ownership, singleton storage, and method bounds; the Batch 012 IDA recheck closes the specific vtable-data ownership gate while exact original filename and some helper placement details remain below final-audit confidence.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad ItemObjImageLib memory aggregate is now [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md), a non-emitting local cluster that includes the adjacent item glyph bounds helper. Singleton-clear and scalar-deleting destructor pages remain exact separate tails.
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the old `0x004dec30-0x004e65dc` aggregate crossed LightObjImageLib and NewHumanImageLib.
- 2026-06-13 B003 helper-routing repair:
  - Changed to: [UID:0003LZ][0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable](by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md) is reclassified from the stale no-owner `LightInfoTableLoader` hypothesis to this `ItemObjImageLib` source module, and [UID:0003ND][0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability](by-memory/0x004df670-0x004df7d2.ItemObjImageLibRefreshItemFrameAvailability.md) is split as the adjacent raw source helper.
  - Evidence: live IDA MCP confirmed `ITEM.TBL` / `ITEM.TBD`, `ITEM.EPF` / `ITEM.EPD`, `ItemInfo` `0x14` rows, `this+0x08/+0x0c/+0x14` object layout, and `g_pEPFLib` / `g_pPaletteLib` dependencies, with no `LightObjImageLib` owner signals.
- 2026-06-18 B005 constructor source-quality sync:
  - [UID:0002SD][0x004dec30-0x004dee1b.ItemObjImageLibConstructor](by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md) now has first-draft constructor C++ through this file root; no file-level score change.
- 2026-06-19 B008 class source-quality sync:
  - Kept score `89/86`, corrected stale helper end spellings for the ordinary destructor and glyph helper, added likely header wording, documented first-draft draw signatures and the `drawOwner` caveat, and clarified that class/formal C++ is blank because exact draw children and final class declaration/source shape remain pending rather than unresolved constructor helper names.
  - Evidence: existing IDA exports plus a local PE/Capstone pass confirmed constructor/destructor/draw/glyph/helper boundaries, padding, resource/global/remap operands, and representative draw call-site argument order.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: recorded the object-image preview status-kind `2` consumer of `GetItemGlyphBounds` and `DrawItemImage`, including the descriptor `+4/+6` item id and variant/palette byte usage.
- 2026-06-23 B002 ordinary destructor source-quality sync:
  - Score unchanged.
  - Evidence: current IDA MCP session `261fb29b` superseded older fallback-only destructor provenance by confirming no function/decompiler model at `0x004dee20`, exact 45-byte body and padding, no code/data/VA/RVA pointer route to the raw ordinary destructor start, `ItemObjImageLib` vtable refs at `0x004dec8c`/`0x004dee23`/`0x004e6586`, `ProtectedArray<ItemInfo>` vtable refs including `0x004dee2c`, singleton lifecycle refs including `0x004dee3b`, scalar deleting destructor parity, and the accepted blank-C++/no-owner-rejection rationale.
- 2026-06-25 B005 accepted report implementation:
  - Score unchanged. Added exact draw child references [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md), [UID:00041S][0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot](by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md), [UID:00041T][0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled](by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md), and [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md), promoted [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) to exact by-memory, and recorded current MCP session `80de0a67` as the authoritative draw/glyph provenance superseding B008 fallback-only evidence for this range.
- 2026-06-26 B014 scalar deleting destructor source-quality callback:
  - Score/path unchanged. [UID:0002VC][0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor](by-memory/0x004e6580-0x004e65dc.ItemObjImageLibScalarDeletingDestructor.md) now routes through [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) to this `NexusTK/render/ItemObjImageLib.cpp` file root. Its formal marker is a no-code proof for compiler-generated scalar deleting destructor glue; source cleanup remains [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md), and this file page should not hand-write the wrapper.
- 2026-06-27 B013 singleton cleanup helper source-quality callback:
  - Score/path unchanged. [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonBaseDestructor.md) now routes through this `NexusTK/render/ItemObjImageLib.cpp` file root as constructor SEH cleanup glue for the singleton publication/unwind path, not a handwritten file-local helper. Current MCP session `b001_000241_20260627` confirms the exact body, constructor cleanup jump `0x00600158`, negative ordinary caller/callee and pointer-route checks, 65 singleton refs, and blank formal C++ generated-cleanup disposition.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000KH)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- ItemObjImageLib.cpp retains the one-definition global policy and member draw methods. GetItemGlyphBounds remains a free/file-local helper, so the accepted paint route adds no fabricated convenience member.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-092 | 0001UU | UID0002DL's two draw calls use `g_pItemObjImageLib`, while `GetItemGlyphBounds` is a no-receiver file helper. The complete ItemObjImageLib declaration must preserve that distinction and the one extern global. | Certain | Direct UID0002DL callsite receiver setup and current ItemObjImageLib layout/draw evidence. | UID0001UU complete formal; UID0000KH header/source placement; UID0002DL. | reject-stale | implemented |
