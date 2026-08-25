*** UID:0000JR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# GrafPort

## 2026-08-18 ObjectImage Consumer Route

- `ObjectImageControlPane.cpp` consumes the established `GrafPort.h` surface through inheritance: `m_visibleBounds` for centering; base `ObjectImageControlPane::OnPaint` calls `SetDrawColor(0)`; highlighted `ObjectImageButtonPane::OnPaint` makes no `SetDrawColor` call and instead uses the complete six-argument `RenderTileFrame` call for `CAPSULE.EPD` with `NPAL3.PAL`.
- The ObjectImage source does not define a duplicate rectangle member or rendering wrapper. The exact field and APIs remain implemented by GrafPort.cpp/.h.
- This is a dependency-only inventory addition; GrafPort ownership, formal source, scores, and existing method bodies are unchanged.

## UID0000KA Inherited Render Consumer - 2026-08-15

Both inventory classes consume inherited `GrafPort` declarations for `MoveTo`, `SetTextColor`, `DrawWideText`, and `RenderTileFrame`. Their paint bodies retain exact list/grid coordinates, hotkey text, item labels, resource frames, and local stack bounds; GrafPort owns the drawing API and implementation. No descriptive render wrapper or inventory-owned duplicate declaration is introduced, and scores remain unchanged.

## Status

- Confidence: very strong for the complete source-unit inventory, class responsibility, exact code/data boundaries, shared draw/text helper ownership, formal CPP/H routing, and `render/GrafPort.cpp` placement. Remaining uncertainty is limited to inferred private/static spellings and precise historical include order.
- Reconstruction disposition: reconstructable custom game render code. The supported by-file metadata remains `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`; no unsupported by-file reconstruction header is added.
- Proposed module: `render/GrafPort.cpp`.
- Current recovered source: `source-3/simroot_v2/class_GrafPort.cpp`
- Main address range: `0x004b8bf0-0x004bb8c4`

## File Role

`GrafPort` is the base drawing surface/port used by panes and render code. It owns region state, dirty/exposed region tracking, clip/default draw settings, and either a DirectDraw surface or an owned software buffer. The class is where UI layout bounds become an actual renderable backing store.

The active placement is `render/GrafPort.cpp` because `UpdateRenderRegion` creates RGB565 DirectDraw surfaces and manages pixel buffers, and `by-project-structure/proposed-source-tree.md` lists `GrafPort.cpp` in `render/`. Earlier `ui/core/GrafPort.cpp` placement was considered because pane and control constructors inherit or embed this state heavily; B003 source-quality review keeps the owner in `render/GrafPort.cpp` because the core responsibilities are backing storage, draw state, clipping, and software/DirectDraw render paths rather than UI widget composition.

## UID000090 Complete Header And Source Contract - 2026-07-31

- `NexusTK/render/GrafPort.h` is the declaration owner for the complete `GrafPort : public LObject` type. Its explicit dependencies are `<cstddef>`, `../util/LObject.h`, `../ui/core/RectBounds.h`, `../ui/core/Region.h`, and `EPFTileContext.h`; pointer-only DirectDraw, palette, frame-record, and blit-option types remain forward declarations.
- `NexusTK/render/GrafPort.cpp` includes `GrafPort.h` and receives exact child method definitions through the class emitter route. The class page emits the declaration and source child marker only; it does not duplicate address-owned method bodies.
- The header contract includes the complete `0xa0` field layout, canonical source vocabulary, natural alignment, full method declarations, and the `GrafPortSizeMustBe160` guard. This lets `Pane.h` inherit a complete base and consume `m_visibleBounds` without a false Pane-local `m_bounds` member.
- Incomplete/PCH-only base declarations, a UI-core duplicate GrafPort header, a local duplicate `Point`, and the historical `0x88` truncation are rejected. The accepted physical/source route remains `NexusTK/render/GrafPort.h` plus `NexusTK/render/GrafPort.cpp`.

## Complete Whole-File Inventory

The complete physical neighborhood contains 60 modeled functions and four retained raw bodies. Source reconstruction owns 55 out-of-line `GrafPort` methods plus one file-static helper; `SetDrawMode` and `SetTextDrawMode` remain the two inline header setters. The scalar deleting destructor is compiler-generated. Seven neighboring modeled functions are excluded: the constant line-count helper, RGB565-to-RGB555 conversion, DAT loader, numeric glyph initializer, two line-clipping functions, and the scalar wrapper. Raw `0x004b99c0` is separately excluded through Surface ownership.

| Address span | Complete modeled/source inventory | Disposition |
| --- | --- | --- |
| `0x004b8be0-0x004b94e1` | `EnableSoftwareBuffer`; [UID:000560][0x004b8bf0-0x004b8d17.GrafPortConstructor](by-memory/0x004b8bf0-0x004b8d17.GrafPortConstructor.md) constructor; [UID:000561][0x004b8d20-0x004b8dc3.GrafPortDestructor](by-memory/0x004b8d20-0x004b8dc3.GrafPortDestructor.md) destructor; [UID:000562][0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion](by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md) `GetExposedRegion`; [UID:000563][0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext](by-memory/0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext.md) `GetSurfaceContext`; [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) `GetBounds`; [UID:000564][0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion](by-memory/0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion.md) virtual `UpdateRenderRegion` | Seven authored GrafPort methods. |
| `0x004b94f0-0x004b9768` | [UID:0004LN][0x004b94f0-0x004b9509.GrafPortReleaseSurface](by-memory/0x004b94f0-0x004b9509.GrafPortReleaseSurface.md) `ReleaseSurface`; [UID:0004LO][0x004b9510-0x004b951d.GrafPortSetSurfacePixelData](by-memory/0x004b9510-0x004b951d.GrafPortSetSurfacePixelData.md) `SetSurfacePixelData`; [UID:0004LP][0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride](by-memory/0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride.md) `SetSurfaceRowStride`; [UID:0004LQ][0x004b9530-0x004b9545.GrafPortGetOrigin](by-memory/0x004b9530-0x004b9545.GrafPortGetOrigin.md) `GetOrigin`; [UID:0004LR][0x004b9550-0x004b9574.GrafPortSetOrigin](by-memory/0x004b9550-0x004b9574.GrafPortSetOrigin.md) `SetOrigin`; [UID:0004LS][0x004b9580-0x004b958c.GrafPortSetClipRegion](by-memory/0x004b9580-0x004b958c.GrafPortSetClipRegion.md) `SetClipRegion`; [UID:0004LT][0x004b9590-0x004b95a3.GrafPortGetClipRegion](by-memory/0x004b9590-0x004b95a3.GrafPortGetClipRegion.md) `GetClipRegion`; [UID:0004LU][0x004b95b0-0x004b95bc.GrafPortSetClipRect](by-memory/0x004b95b0-0x004b95bc.GrafPortSetClipRect.md) `SetClipRect`; [UID:0004LV][0x004b95c0-0x004b95c5.GrafPortDisableDrawing](by-memory/0x004b95c0-0x004b95c5.GrafPortDisableDrawing.md) `DisableDrawing`; [UID:0004LW][0x004b95d0-0x004b95d5.GrafPortEnableDrawing](by-memory/0x004b95d0-0x004b95d5.GrafPortEnableDrawing.md) `EnableDrawing`; UID000162 `GetDrawPosition`, `MoveTo`, `OffsetDrawPosition`, `SetFontId`, `SetDrawColor`, `SetTextBackFillColor`, `SetTextColor`, and `SetTextBackColor`; UID000163 `GetPalette` and `SetPalette`; UID000164 `GetClipRect` | Twenty-one authored GrafPort methods; UID0003XB is the non-emitting physical index. |
| `0x004b9770-0x004ba81d` | UID0004DI retained private `BuildEffectiveClipRegion`; UID0004DJ `ReleaseBackingStore`; UID0004H2 `UpdateSurfaceInfo`; UID0004H3 `EndPaint`; UID0004H4 `LineTo`; UID0004H5 `DrawSprite`; UID0004H6 `RenderTileFrame`; UID000166 `BlitTileContextAt`; UID0004H7 `ScrollPixelBuffer`; UID000167 `BlitSurface`; UID000168 `DrawRectFrame`; UID000169 `CompositePixels`; UID00016A `DrawTiledBackground` | Thirteen authored GrafPort methods. Raw UID00035C at `0x004b99c0-0x004b99ee` remains Surface-owned and excluded. |
| `0x004ba820-0x004baf92` | UID00016B `FitTextAndAppendSuffix` and `CountCharsFittingWidth`; UID00016C counted and null-terminated `GetTextWidth`, `GetLineHeight`, `AdjustVisibleCountForTrailingWhitespace`, `DrawGlyphWithTextColors`, `DrawWideText`, and `DrawOutlinedTextAt`; UID00016D `DrawTextInRect` | Nine authored GrafPort text methods. |
| `0x004bafa0-0x004bb0db` | UID0004NH `DrawOutlinedText`; UID0004NI `DrawShadowedText`; UID00016F constant line-count neighbor | Two authored GrafPort methods; UID00016F is SystemMessagePanes-owned and excluded. UID00016E remains a non-emitting physical container. |
| `0x004bb0e0-0x004bb5a5` | UID0003ZP RGB conversion; UID00016G DAT loader; UID0003XD numeric glyph initialization; UID0003XE retained private `BlitTileContextToSurface`; two UID00016H line-clipping functions | One authored GrafPort method; six modeled neighbors remain owned by SoftwareBlend16, DATFile, NumericStringControlPane, and Surface. |
| `0x004bb5b0-0x004bb8c4` | UID0003XF file-static `PackTwoColorSixPixelPattern`; UID00016I `DrawGlyph`; scalar deleting destructor | Two authored definitions and one compiler-generated wrapper. UID0003XF stays owned by this file and uses class UID00005V only as its source-order assembler. |

Additional non-modeled/data evidence is part of the same exhaustive inventory: UID0004DI, UID00035C, UID0003XE, and UID0003XF are the four raw bodies; [UID:0003BE][0x0061a8a4-0x0061a8b8.GrafPortVtableData](by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md) contains the RTTI locator and four-slot vtable; [UID:0002V5][0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData](by-memory/0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData.md) is the exact diagnostic wide string used by `UpdateRenderRegion`; UID000160, UID0003XB, UID0003XC, UID00016E, UID00025F, and UID0002V4 remain non-emitting physical/container pages.

## Source Order

`GrafPort.cpp` follows address/source order: constructor and destructor; exposed-context/bounds accessors; `UpdateRenderRegion`; surface/state/clip/draw helpers; retained private `BuildEffectiveClipRegion`; backing-store and paint helpers; sprite/tile/surface/scroll/rectangle/composite methods; text measurement and rendering methods; retained private `BlitTileContextToSurface`; file-static `PackTwoColorSixPixelPattern`; and `DrawGlyph`. UID0003XF remains canonically file-owned by UID0000JR but uses class UID00005V as the assembler emitter so the generated child stream is exactly `UID0003XE -> UID0003XF -> UID00016I`. The compiler scalar destructor, vtable/RTTI, diagnostic-data object, padding, and excluded neighbors do not receive handwritten definitions.

## Generated Source Audit

The dated pre-callback baseline at validator command `000000026459` contained 48 generated definitions, 51 out-of-line declarations plus two inline setters, 35 routed UID rows with 34 filled emitters, and one UID0002V5 empty marker. It was missing the constructor, destructor, `GetExposedRegion`, `GetSurfaceContext`, `UpdateRenderRegion`, `BuildEffectiveClipRegion`, `BlitTileContextToSurface`, and `PackTwoColorSixPixelPattern` definitions.

The incorporated complete contract is 56 authored definitions, 55 out-of-line class-method declarations plus two inline setters, and zero empty-emitter markers. It removes stale source defects: UID000166 uses `const EPFTileContext *`, `bounds`, `DLPalette *`, and `InitRectBounds`; UID000167 uses `rowStridePixels`; UID000168 calls `g_pfnDrawLineDelta`; UID00016A uses Region reference APIs and an explicit frame-record source-view cast; text helpers use `m_fontId` and `g_pfnFillRect`; and the translation unit sees complete GrafPort, Surface callback, FontImageLib, StringIter, and DDError declarations. Dated validator receipts confirm this incorporated state; later generated rereads are verification boundaries rather than unfinished source work.

## Excluded Neighbors

- UID00035C `[0x004b99c0,0x004b99ee)` is a retained Surface callback forwarder; its callback receiver and existing owner route defeat adjacency-based GrafPort ownership.
- UID00016F `[0x004bb070,0x004bb078)` is the constant SystemMessagePanes line helper and accesses no GrafPort state.
- UID0003ZP `[0x004bb0e0,0x004bb111)` belongs to SoftwareBlend16.
- UID00016G `[0x004bb120,0x004bb1d2)` belongs to DATFile loading.
- UID0003XD `[0x004bb1e0,0x004bb252)` belongs to NumericStringControlPane glyph initialization.
- UID00016H `[0x004bb2e0,0x004bb517)` and `[0x004bb520,0x004bb5a5)` are Surface-owned line-clipping helpers.
- The GrafPort scalar deleting destructor `[0x004bb7e0,0x004bb8c4)` is compiler-generated from the virtual destructor and allocator contract.

## Compiler And Source-Covered Data

[UID:0003BE][0x0061a8a4-0x0061a8b8.GrafPortVtableData](by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md) `[0x0061a8a4,0x0061a8b8)` is the compiler-generated RTTI locator plus four-slot GrafPort vtable and is covered by the complete class declaration; it has no handwritten table definition. [UID:0002V5][0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData](by-memory/0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData.md) `[0x0061a8b8,0x0061a920)` is the exact `surfaceDesc.dwWidth : %d, surfaceDesc.dwHeight : %d` literal with sole xref `0x004b9464`; the `UpdateRenderRegion` body owns the literal and the data page emits only a source-covered comment. Padding and container pages similarly emit no source.

## Source Placement

- `NexusTK/render/GrafPort.cpp` owns the 56 authored definitions and their dependencies.
- `NexusTK/render/GrafPort.h` owns the exact `0xa0` class layout, 55 out-of-line method declarations, and two inline setters.
- Surface callback declarations remain in `Surface.h`; `DDError` remains in `Error.h`; FontImageLib and StringIter declarations remain in their owning headers; globals remain in their owning modules.

## Reconstruction Gate

This file is reconstructable. Runtime behavior, ranges, ownership, method inventory, layout, compiler exclusions, and source routes are closed. Final source must preserve exact behavior while resembling human-written C++03-era game code: use coherent source-facing names and types, normal class/private/static structure, and module dependencies; do not retain `sub_`, `dword_`, raw-offset, or decompiler-temporary vocabulary merely because exact historical spellings are unavailable.

## Open Questions

- The three zero-entry-xref raw bodies are retained source: complete bodies, GrafPort field accesses or inline duplicates, source order, and best human source shape outweigh liveness-negative evidence. Their accepted names are `BuildEffectiveClipRegion`, `BlitTileContextToSurface`, and `PackTwoColorSixPixelPattern`.
- Raw UID00035C remains Surface-owned because semantic receiver/owner evidence outweighs adjacency.
- UID000166 is not a `FrameDrawRecord` helper; live TInfo and body evidence prove `const EPFTileContext *`, `bounds`, `DLPalette *`, and `InitRectBounds`.
- Required FontImageLib, StringIter, and DDError declarations are incorporated through their formal header routes and were physically verified in the dated generated-output receipts.
- Vtable/string/scalar-delete items require no separate definitions because the class declaration, method literal, and virtual destructor generate or cover them.
- No material behavior, ownership, split, declaration, or generated-output question remains. Historical lexical spelling and include-order uncertainty are confidence caps only.

## Score Rationale

Completion and confidence are `94/94` because current incorporated documentation and formal source close the complete whole-file inventory, five formerly missing core children, three retained raw source bodies, exact class/header route, stale source types/names/APIs, compiler/data coverage, exclusions, source ordering, dependency declarations, and generated-output contract. The score remains below `95/95` only because private/static spellings are high-probability source reconstruction rather than recovered original symbols; Gate 2A, Gate 2B, lifecycle execution, and future generated rereads are external verification boundaries and do not represent open file reconstruction work.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `GrafPort` split index | [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) | Non-emitting physical index for the broad GrafPort neighborhood; exact child pages now carry source ownership. |
| [UID:000560][0x004b8bf0-0x004b8d17.GrafPortConstructor](by-memory/0x004b8bf0-0x004b8d17.GrafPortConstructor.md) | `0x004b8bf0-0x004b8d17` | Exact authored constructor with complete defaults, context/bounds initialization, and formal C++. |
| [UID:000561][0x004b8d20-0x004b8dc3.GrafPortDestructor](by-memory/0x004b8d20-0x004b8dc3.GrafPortDestructor.md) | `0x004b8d20-0x004b8dc3` | Exact authored destructor with software-buffer, DirectDraw-surface, and tile-context cleanup. |
| [UID:000562][0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion](by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md) | `0x004b8dd0-0x004b8de3` | Exact `GetExposedRegion` copy-out method with 30 inbound xrefs and formal C++. |
| [UID:000563][0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext](by-memory/0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext.md) | `0x004b8df0-0x004b8df4` | Exact leaf accessor returning embedded `m_surfaceContext`; two ScrolledText callers. |
| [UID:000564][0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion](by-memory/0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion.md) | `0x004b8e20-0x004b94e1` | Exact virtual backing-region update with DirectDraw RGB565, software-buffer, overlap preservation, diagnostic, and error behavior. |
| [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) | `0x004b8be0-0x004b8be8` | `GrafPort::EnableSoftwareBuffer`, a tiny setter for `m_usesSoftwareBuffer` at `this + 0x94`; the legacy dirty-flag name is rejected. |
| `GrafPort::GetExposedRegion` | `0x004b8dd0-0x004b8de3` | Exact 19-byte copy-out accessor now owned by [UID:000562][0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion](by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md), with formal C++ and class declaration. Thirty xrefs across nine functions include repeated UID0004QY MapPane render use. Historical `SaveClipRegion` is caller-biased and rejected. |
| [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) | `0x0066da94` | External screen-width global read by `UpdateRenderRegion`; current generated `g_maxSurfacePitch` is a bad alias over this storage, not a separate GrafPort global. |
| DirectDraw surface descriptor helpers | local to `UpdateRenderRegion` | RGB565 `CreateSurface` setup and overlap preservation logic. |
| [UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md) | `0x004b94f0-0x004b95d5` | `90/92` non-emitting physical index for ten exact source definitions below plus nine compiler-alignment spans; parent formal C++ and emitters are blank. |
| [UID:0004LN][0x004b94f0-0x004b9509.GrafPortReleaseSurface](by-memory/0x004b94f0-0x004b9509.GrafPortReleaseSurface.md) | `0x004b94f0-0x004b9509` | `GrafPort::ReleaseSurface()`: conditionally calls COM Release on `m_ddSurface` and clears it, with no DirectX-global guard or software-buffer cleanup. |
| [UID:0004LO][0x004b9510-0x004b951d.GrafPortSetSurfacePixelData](by-memory/0x004b9510-0x004b951d.GrafPortSetSurfacePixelData.md) | `0x004b9510-0x004b951d` | `GrafPort::SetSurfacePixelData(void *)`: stores borrowed pixel data in the embedded EPFTileContext. |
| [UID:0004LP][0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride](by-memory/0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride.md) | `0x004b9520-0x004b952d` | `GrafPort::SetSurfaceRowStride(int)`: stores logical `rowStridePixels`, not byte pitch. |
| [UID:0004LQ][0x004b9530-0x004b9545.GrafPortGetOrigin](by-memory/0x004b9530-0x004b9545.GrafPortGetOrigin.md) | `0x004b9530-0x004b9545` | `Point *GrafPort::GetOrigin(Point *) const`: copies bounds left/top into Point x/y and returns caller output. |
| [UID:0004LR][0x004b9550-0x004b9574.GrafPortSetOrigin](by-memory/0x004b9550-0x004b9574.GrafPortSetOrigin.md) | `0x004b9550-0x004b9574` | `GrafPort::SetOrigin(int,int)`: translates bounds to `left=-x`, `top=-y` while preserving extents. |
| [UID:0004LS][0x004b9580-0x004b958c.GrafPortSetClipRegion](by-memory/0x004b9580-0x004b958c.GrafPortSetClipRegion.md) | `0x004b9580-0x004b958c` | `GrafPort::SetClipRegion(const Region *)`: copies caller Region into receiver clip state; 21 direct calls. |
| [UID:0004LT][0x004b9590-0x004b95a3.GrafPortGetClipRegion](by-memory/0x004b9590-0x004b95a3.GrafPortGetClipRegion.md) | `0x004b9590-0x004b95a3` | `GrafPort::GetClipRegion(Region *) const`: copies receiver clip state to caller output; 12 direct calls. |
| [UID:0004LU][0x004b95b0-0x004b95bc.GrafPortSetClipRect](by-memory/0x004b95b0-0x004b95bc.GrafPortSetClipRect.md) | `0x004b95b0-0x004b95bc` | `GrafPort::SetClipRect(const RectBounds *)`: replaces receiver clip Region through SetRect; ten direct calls. |
| [UID:0004LV][0x004b95c0-0x004b95c5.GrafPortDisableDrawing](by-memory/0x004b95c0-0x004b95c5.GrafPortDisableDrawing.md) | `0x004b95c0-0x004b95c5` | `GrafPort::DisableDrawing()`: clears `m_drawEnabled` without changing draw mode. |
| [UID:0004LW][0x004b95d0-0x004b95d5.GrafPortEnableDrawing](by-memory/0x004b95d0-0x004b95d5.GrafPortEnableDrawing.md) | `0x004b95d0-0x004b95d5` | `GrafPort::EnableDrawing()`: sets `m_drawEnabled`, matching constructor-enabled default. |
| Draw-state accessors and clip getter | `0x004b95e0-0x004b9768` | Cursor, font id, color, brush, and clip helpers route through the [UID:00005V][GrafPort](by-class/GrafPort.md) class into this source file. [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) now emits formal class-method C++ for the eight leaf draw-state accessors over the actual half-open `0x004b95e0-0x004b96a0` range; its physical filename keeps historical inclusive endpoint `0x004b969f`. [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) emits formal `GrafPort::GetClipRect(RectBounds *outClipRect)` C++ from this file route. |
| [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) | `0x004b9770-0x004b981e` | Non-emitting split/container for the exact effective-clip raw helper and backing-store release helper children below. |
| [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) | `0x004b9770-0x004b97cf` | Retained private `GrafPort::BuildEffectiveClipRegion`. The exact raw body composes exposed, clip, and bounds Regions and now emits formal class-owned C++; zero entry xrefs remain negative liveness evidence rather than a no-source disposition. |
| [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) | `0x004b97d0-0x004b981e` | `GrafPort::ReleaseBackingStore()`, a modeled six-caller helper that frees `m_softwareBuffer` when `m_usesSoftwareBuffer` is set and releases/clears `m_ddSurface` under the `g_pDirectX->m_pDirectDraw` guard. Formal C++ is populated on the child. |
| [UID:0004H2][0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo](by-memory/0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo.md) | `0x004b9820-0x004b98b8` | `GrafPort::UpdateSurfaceInfo()`, source-ready exact child split out of UID000165. Uses `m_usesSoftwareBuffer`, `m_softwareBuffer`, `m_softwarePitchBytes`, `m_ddSurface`, and `m_surfaceContext` fields to open DirectDraw/software pixel access. |
| [UID:0004H3][0x004b98c0-0x004b98ee.GrafPortEndPaint](by-memory/0x004b98c0-0x004b98ee.GrafPortEndPaint.md) | `0x004b98c0-0x004b98ee` | `GrafPort::EndPaint()`, source-ready exact child split out of UID000165. Unlocks the DirectDraw surface when hardware-backed and clears active `m_surfaceContext` pixel/stride state. |
| [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md) | `0x004b98f0-0x004b990c` | Exact 28-byte source-ready `void GrafPort::LineTo(int x, int y)` child split out of UID000165. It computes signed endpoint-minus-`m_currentX`/`m_currentY` deltas and tail-dispatches `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`; historical `int` return source is superseded. |
| [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md) | `0x004b9910-0x004b997e` | `GrafPort::DrawSprite(...)`, source-ready exact child split out of UID000165. Temporarily borrows source alpha and dispatches slot `0x0069b3e8`; exact public spelling remains inferred. |
| [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md) | `0x004b9980-0x004b99b1` | `GrafPort::RenderTileFrame(...)`, source-ready exact child split out of UID000165. Resolves a palette name through `g_pPaletteLib` and dispatches slot `0x0069b3e8`; fitting-room ownership is rejected. |
| [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) | `0x004b99f0-0x004b9a63` | `GrafPort::BlitTileContextAt`, a typed offset blit wrapper over `const EPFTileContext *`, `bounds`, `DLPalette *`, `InitRectBounds`, and nullable `SurfaceSpriteBlitOptions`; stale `FrameDrawRecord`, generic `source`, and opaque-palette wording is superseded. |
| [UID:0004H7][0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer](by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md) | `0x004b9a70-0x004ba24a` | Source-ready `void GrafPort::ScrollPixelBuffer(const RectBounds *, int, int, Region *)` exact child split out of UID000165. It clips the requested bounds, performs overlap-safe 16-bit copies in four directional branches, clears exposed strips, and unions them into the caller-owned Region; the child carries complete formal C++. |
| [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) | `0x004ba250-0x004ba444` | `GrafPort::BlitSurface`, a source-authored destination-GrafPort method that chooses DirectDraw `BltFast` for copy/source-color-key modes or the typed `g_pfnBlitSprite` software callback for software/composition modes, using exact `rowStridePixels` fields. |
| [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) | `0x004ba450-0x004ba53b` | `GrafPort::DrawRectFrame(const RectBounds *rect)`, a class method that gates on `m_drawEnabled`, uses clip/intersection helpers as a visibility test, saves/restores current draw cursor fields, and draws four original-rectangle edges through `g_pfnDrawLineDelta`. |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) | `0x004ba540-0x004ba6ad` | `GrafPort::CompositePixels`, a source-authored clipped 16-bit pixel-effect method used by BowGaugeObjectPane and TextEditPane; it fills zero pixels with the current background palette color and inverts nonzero pixels. |
| [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) | `0x004ba6b0-0x004ba81d` | `GrafPort::DrawTiledBackground`, a class method that temporarily swaps `m_clipRegion`, tiles the explicit `EPFTileContext` source view of a `FrameDrawRecord` across `m_visibleBounds`, resolves a named palette, and dispatches each tile through `g_pfnBlitSprite` using Region reference APIs. |
| [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) | `0x004bb260-0x004bb2d7` | Retained private `GrafPort::BlitTileContextToSurface`. The exact raw body updates the render region, temporarily installs typed context pixels/stride/bounds, resolves an optional palette, dispatches the sprite callback, and restores context state; it now emits formal class-owned C++. |
| Text measurement/drawing helpers | `0x004ba820-0x004bb0db`, `0x004bb5e0-0x004bb7e0` | Shared UTF-16 fit/suffix, width, line-height, wrapped rect draw, outlined/shadowed text effects, run drawing, and per-glyph blit helpers. [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) route through the `GrafPort` class using current `m_fontId` and `g_pfnFillRect` vocabulary. [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) preserves FontImageLib metric/decode behavior, typed `EPFTileContext`, `m_palette`, fill/blit callbacks, draw-mode mapping, and cursor advance. UID00016F remains SystemMessagePanes-owned because it returns constant one and has no GrafPort state access. |
| [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md) | `0x004bafa0-0x004bb0db` | Non-emitting mixed physical index only. It contributes no body or marker to this file; exact GrafPort methods and the independently routed callback follow in address order. |
| [UID:0004NH][0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect](by-memory/0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect.md) | `0x004bafa0-0x004bb06a` | Emits `GrafPort::DrawOutlinedText(const wchar_t *, int, const RectBounds *)` after UID00016D: four secondary-color cardinal passes, restored primary-color center pass. |
| [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) | `0x004bb070-0x004bb078` | Physical neighbor only; emits through SystemMessagePanes, not this file, and retains constant line-count formal source. |
| [UID:0004NI][0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect](by-memory/0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect.md) | `0x004bb080-0x004bb0db` | Emits `GrafPort::DrawShadowedText(const wchar_t *, int, const RectBounds *)` after the independent callback: original-first then `(1,0)` duplicate-offset pass, no explicit color swap. |
| [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) | `0x004bb0e0-0x004bb111` | Physical successor only; emits through SoftwareBlend16 and closes UID00016E child indentation. It contributes no source to GrafPort.cpp. |
| [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) | `0x004bb5b0-0x004bb5d1` | Retained file-static `PackTwoColorSixPixelPattern`, proven by its exact six-byte output order and identical inline pattern in two GrafPort text methods. It emits file-owned formal C++ through class UID00005V's address-ordered assembler, without becoming a class member; zero entry xrefs cap lexical/liveness confidence only. |

## Behavior Summary

`UpdateRenderRegion` compares the requested rectangle with the current bounds, updates exposed/dirty regions, and then synchronizes backing storage. In the DirectDraw path it creates an offscreen surface with RGB565 masks (`0xf800`, `0x07e0`, `0x001f`) and copies the overlapping old surface contents into the new surface. In the software-buffer path it allocates a heap buffer with two bytes per pixel plus small row padding and preserves overlapping contents with `memmove`.

The `0x004b8dd0` exposed-region accessor is part of the same source surface. Its broad caller fan-in and exact copy-out contract place it in `NexusTK/render/GrafPort.cpp`; MapPane and the other eight caller families remain consumers. The accepted descriptive name is `GetExposedRegion`, not historical `SaveClipRegion`, and [UID:000562][0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion](by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md) now provides its exact child and formal source.

IDA MCP recheck on 2026-05-26 shows the generated `g_maxSurfacePitch` operand in this function is actually `word_66DA94` / [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md). The relevant DirectDraw packing branch compares `4 * requestedWidth` against the global screen width after checking for a large aligned pitch. The source-facing name is `g_screenWidth`; the stale generated alias is superseded.

## UID0003XB Source Route And Evidence

- UIDs 0004LN-0004LW are ten source-authored nonvirtual GrafPort methods emitted exactly through this file. UID0003XB itself and all alignment spans emit nothing.
- The methods own only GrafPort state: `m_ddSurface +0x18`, embedded EPFTileContext `pixelData +0x20`, accepted `rowStridePixels +0x28`, bounds left/top `+0x2c/+0x30`, `m_clipRegion +0x54`, and `m_drawEnabled +0x71`. Region/RectGeometry and DirectDraw are dependencies; Surface and DirectX do not own these definitions.
- Dated accepted MCP/PE evidence found zero routes to ReleaseSurface, both context setters, SetOrigin, and the enable/disable pair. Their unique complete bodies and closed source signatures make them retained source definitions rather than compiler support. GetOrigin has three direct calls; clip methods have `21/12/10` calls across broad UI/render consumers.
- Constructor/destructor and GrafPort vtable evidence confirm state ownership and nonvirtual dispatch. ChattingPane's save/apply/restore flow preserves the observed unseeded intersection branch and establishes ordinary source API use for the clip trio.
- Historical `ReleasePrimarySurface`, generic state pointer/stride, `GetViewOrigin`, `OffsetViewOrigin`, and blanket no-code wording are superseded. The current whole-file pass also supersedes the former UID0004DI/UID0003XE blank-source disposition with exact retained private class bodies.
- Rejected placements: Surface owns callback/backend algorithms, not this receiver; DirectX owns device lifetime; Region owns copy/set internals; FittingRoom, Ranking, WebBoard, Chatting, Layer, MapPane, MenuPane, ScrollablePane, and SystemMessage files are consumers only.
- Historical bounded passes did not close the whole file; the exhaustive whole-file closure establishes current `94/94`. Exact methods continue to emit through child/class routes rather than a by-file formal block.

## UID0002TE Surface Slot-6 Receiver Dependency

- Source-ready [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) and [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) consume GrafPort but remain file-local implementations in `Surface.cpp`.
- Exact dependencies are `m_surfaceContext.pixelData`, logical-pixel `m_surfaceContext.rowStridePixels`, `m_surfaceContext.bounds`, `m_drawEnabled`, `m_drawColor`, `m_textBackFillColor`, and class-owned `GetClipRect`. Historical `m_secondaryDrawColor`, generic `rowStride`, raw offsets, and dummy-register signatures are rejected source spellings for these providers.
- Both providers receive raw contiguous MSB-first packed 1bpp mask data plus destination bounds and a mode byte. They share clipping, mask-coordinate, and pitch logic; the compat path uses RGB555 `BlendRgb555Half`, while RGB565 uses `BlendRgb565Pixel`.
- This dependency does not move callback ownership into `GrafPort.cpp`: GrafPort owns receiver state and clip methods, while Surface owns `SurfaceBitmaskBlitProc g_pfnBlitBitmask`, initializer selection, and both provider bodies. BalloonObjectPane remains a consumer rather than owner.
- The current whole-file score is `94/94`; the later exhaustive closure supersedes the narrower support-time score without changing this exact callback contract.

## UID0002YK Callback Source-Layout Support

[UID:0002YK][0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback](by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md) emits from `Surface.cpp`, but its receiver is a GrafPort and its source depends on this file's accepted class layout. The callback reads embedded `void *m_surfaceContext.pixelData`, logical-pixel `int m_surfaceContext.rowStridePixels`, and `m_surfaceContext.bounds`. Compile-valid source takes an `unsigned char *` byte view of `pixelData`, applies the exact doubled pixel offset, and then converts the resulting address to an `unsigned short *`; direct arithmetic on `void *` and the historical generic `rowStride` token are not accepted source.

Additional receiver state is `m_drawMode`, `m_drawEnabled`, inferred `m_drawColor` / `m_secondaryDrawColor`, borrowed `DLPalette *m_palette`, `m_alpha`, and `m_usesSoftwareBuffer`. Target behavior maps both color fields, discards the secondary mapped result, and forces the mapped RGB565 fill pixel to value `1` when software backing is active and the primary palette index is `128`; index `128` is the trigger, not the resulting pixel value. It processes direct-fill odd tails before pairs and passes existing destination pixels as the blend helpers' first argument so `m_alpha` weights the destination. This is source-layout prose only: the by-file root has no reconstruction metadata or target body, and UID0002YK remains the sole callback emitter.

## Ownership Decision

Keep `GrafPort` close to DirectDraw/surface support, but do not merge it into `DirectX.cpp`. `DirectX` owns device lifetime; `GrafPort` owns per-pane/per-render-target storage and dirty-region state.

Also keep low-level RGB blend helpers in a separate helper module such as [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md). `GrafPort` establishes RGB565 backing storage; the blend helpers implement per-pixel and per-span math used by drawing routines.

Use [UID:0000OC][Surface](by-file/Surface.md) as the review bucket for nearby generic paint lifecycle, scroll-buffer, presentation, and callback helpers that Wave3 currently attaches to caller classes such as `FolderTreePane` and `MapPane`.

[UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) routes through `GrafPort` as the incorporated `GrafPort::BlitSurface` method rather than the provisional Surface bucket. The decisive evidence is the `__thiscall` receiver and the concrete GrafPort field model: `+0x18` DirectDraw surface, embedded `EPFTileContext` at `+0x1c`, `+0x20/+0x28` context pixel/stride fields, `+0x90` alpha, and `+0x94` software-buffer flag. Surface remains the callback-table and lifecycle dependency, not the direct semantic owner for this exact method.

[UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) emits through this file as the incorporated `GrafPort::BlitTileContextAt` method. Dated 2026-07-02 evidence from session `supervisor_resume_20260629` established an exact `0x73`-byte function with two bytes of preceding `0xcc` padding, thirteen bytes of following `0xcc` padding, three direct callers at `0x004b5917`, `0x005c3b60`, and `0x005c3db0`, caller-set `ecx`, target receiver save/restore at `0x004b9a01`/`0x004b9a3a`, and a slot-2 call at `0x004b9a4a`. This supersedes prior support wording that claimed no GrafPort receiver. Surface remains the callback-table/backend dependency, not the emitted source route.

B010's 2026-07-04 UID000165 split added the preceding paint-helper methods to this file route as exact GrafPort children: `UpdateSurfaceInfo`, `EndPaint`, `LineTo`, `DrawSprite`, `RenderTileFrame`, and then-owner-known `ScrollPixelBuffer`. Historical session `73c77998` proved the relevant receiver fields (`m_ddSurface`, `m_surfaceContext`, `m_currentX`, `m_currentY`, `m_drawMode`, `m_drawEnabled`, `m_alpha`, `m_usesSoftwareBuffer`, `m_softwareBuffer`, and `m_softwarePitchBytes`), callback slots `0x0069b3e4` / `0x0069b3e8`, and feature-owner pollution.

### 2026-07-24 UID0002PJ LineTo And Slot-1 Source Contract

- Current IDA already models `0x004b98f0-0x004b990c` as `void __thiscall GrafPort_LineTo(GrafPort *this, int x, int y)`. The wrapper subtracts `m_currentX +0x6c` and `m_currentY +0x68` from the absolute endpoint and ends as an indirect tail jump through the four-byte Surface slot at `0x0069b3e4`.
- The semantic slot contract is `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`, where the typedef returns `void` and receives `GrafPort *`, signed `deltaX`, and signed `deltaY`. Therefore `GrafPort::LineTo` also returns `void`; the earlier managed `int` and `return g_pfnDrawLineDelta(...)` source were decompiler-shaped history, not a valid public contract.
- Source ownership remains separated: this file emits the public GrafPort wrapper, [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) emits the callback typedef/global, and Surface exact children emit the selected low-level providers. Source-ready RGB565 provider [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) clips/draws and advances the original cursor deltas; no callback body is duplicated in `GrafPort.cpp`.
- The current whole-file score is `94/94`; the later exhaustive closure supersedes the narrower support-time score without altering this exact contract.

B001's 2026-07-13 UID0004H7 reanalysis supersedes only the historical blank-emitter/no-code conclusion. `ScrollPixelBuffer` now emits here as `void GrafPort::ScrollPixelBuffer(const RectBounds *scrollRect, int deltaX, int deltaY, Region *dirtyRegion)`: target fields are pixel data `+0x20`, pixel stride `+0x28`, surface bounds `+0x2c/+0x30`, and draw-enabled byte `+0x71`; `Region::SetEmpty` and `Region::UnionWithRect` establish the output protocol; and exactly three callers at `0x0050bea3`, `0x0050da81`, and `0x0055eba6` construct/destroy local Regions and ignore a return. Its four directional copy/clear branches and anomalous `4 * rectWidth` lower-strip clear are preserved in the child body. Generated source order is exact-address order: UID0004H7 follows UID000166 and precedes UID000167, with each body appearing once. The later exhaustive whole-file closure establishes current `94/94` while preserving the remaining lexical caveats.

[UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md), and [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) are GrafPort/draw-state class methods or helper families routed through this file. UID000162's filename retains the historical inclusive endpoint `0x004b969f`, while dated accepted MCP evidence proves the actual half-open range is `0x004b95e0-0x004b96a0`; it contains eight zero-callee leaf accessors over `+0x68/+0x6c`, `+0x8a`, and `+0x74/+0x78/+0x7c/+0x80`, with formal first-draft C++ present through the class route. UID000163 is the exact seven-byte getter, nine-byte alignment, and 16-byte setter for borrowed `DLPalette *m_palette` at `+0x84`; its ten calls span balloon/chat save-install-restore and hair/face slot-14/slot-13 install-clear paths, rejecting caller-biased feature ownership and supporting `GetPalette` / `SetPalette` emission here. B009's accepted GetClipRect pass confirms `0x004b96c0-0x004b9768` as an exact emitting `GrafPort::GetClipRect(RectBounds *outClipRect)` method that copies `m_exposedRegion`, optionally intersects `m_clipRegion`, intersects `m_surfaceContext.bounds` through the `0x005547e0` raw-rect wrapper, and rejects caller-biased `RankingEventListPane` ownership.

[UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) now routes through the GrafPort class rather than caller-biased generated owners. B002's 2026-06-18 reanalysis proves a one-argument `GrafPort::DrawRectFrame(const RectBounds *rect)` source shape with exact padded boundaries, 49 rel32 code references, `this+0x71` draw-enabled gating, `this+0x6c/+0x68` current X/Y cursor fields, clip/intersection/empty-rect visibility gating, and four `dword_69B3E4` line-delta dispatches. Surface remains only the callback-table/software-render dependency for slot `0x0069b3e4`.

[UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) emits as the incorporated `GrafPort::DrawTiledBackground` method in `NexusTK/render/GrafPort.cpp`. Older generated output placed it under `RankingEventListPane`, but B002's 26-caller scan and receiver-state analysis reject caller ownership. The body saves/replaces `m_clipRegion`, reads `m_visibleBounds`, forwards `m_drawMode` and callback-visible `m_alpha` state, resolves palettes through `g_pPaletteLib`, and dispatches repeated `FrameDrawRecord` tile blits through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3E8`.

[UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) is retained private `GrafPort::BlitTileContextToSurface(const EPFTileContext *, DLPalette *)` source. B005's 2026-06-18 retry connected the raw body's `call [this->vtable+0x0c]` to the documented `GrafPort::UpdateRenderRegion` virtual slot and connected its `this+0x20/+0x28/+0x2c` stores to accepted `m_surfaceContext.pixelData` / `rowStridePixels` / `bounds` fields. The UID0000JR whole-file resolution then accepted the complete `EPFTileContext` signature and populated formal C++ through class emitter UID00005V. Surface remains callback-table/palette/render dependency context only; zero surviving entry routes cap liveness confidence but do not suppress the retained source body.

[UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) remains a non-emitting split/container whose exact children carry source. Raw child [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) now emits retained private `GrafPort::BuildEffectiveClipRegion(Region *)` through class emitter UID00005V; its complete receiver-specific Region body and sibling parity support formal source even though the B007 MCP/PE recheck finds no surviving function or route to the raw start. Modeled child [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) emits through the same source route as `GrafPort::ReleaseBackingStore()`: six direct callers use it during object cleanup/update, and the body frees the software backing buffer and releases the retained DirectDraw surface stored on GrafPort. MapPane and ObjectPane are caller/receiver contexts, Surface is adjacent render infrastructure, and DirectX is a dependency through `g_pDirectX->m_pDirectDraw`; none own either method.

[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) routes through the GrafPort class as the incorporated `GrafPort::CompositePixels` method rather than the provisional Surface bucket or BowGauge/TextEdit consumers. The decisive evidence is the `__thiscall` receiver plus concrete GrafPort state: draw-enabled byte `+0x71`, embedded `EPFTileContext` pixel/stride/bounds fields at `+0x20/+0x28/+0x2c/+0x30`, and the background-color field at `+0x7c`. Surface remains adjacent render infrastructure context only.

Keep [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md), exact UID0004NH/UID0004NI, and [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) in GrafPort.cpp. UID00016E itself is now a non-emitting mixed index and must not produce the former empty marker. Current generated feature owners such as `ClanItemListPane`, `FittingRoomDownloadControlPane`, `CollectionEntryControlPane`, `RankingEventListPane`, `StaticTextControlPane`, and help/chat paths are caller pollution: exact methods have broad fan-in and use GrafPort draw state while delegating glyph metrics/decode to [UID:0000JH][FontImageLib](by-file/FontImageLib.md). The historical Batch 119 broad-parent claim correctly identified the two method bodies as GrafPort but is superseded at parent level by exact child emission.

[UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) is tracked beside the text-helper family as an independently owned constant helper, not silently folded into GrafPort. B006 2026-06-21 confirms [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) calls it twice with the pane/draw-context receiver in `ecx`, `m_text`, UTF-16 length, and width. The helper ignores all inputs and returns one, so the accepted conclusion keeps its SystemMessagePanes ownership and excludes a `GrafPort::GetTextLineCount` method.

### UID00016E Source Order And Emission Policy

- Source order after UID00016D is UID0004NH definition, no source for six-byte alignment, no GrafPort source for UID00016F, no source for eight-byte alignment, then UID0004NI definition. UID0003ZP and the five/fifteen-byte pads are excluded from this file.
- UID0004NH is a 202-byte/75-instruction one-block `thiscall` method with SHA-256 `C29B61F52A23EC3AB6F240E9072238F82411A1A9BB3B35C31537CB918BD53D69`; UID0004NI is a 91-byte/39-instruction one-block `thiscall` method with SHA-256 `112A989B555D30F32D5E4A47C27D256E858048152CF3534B58D8F8DCE364BAF5`.
- Both use source `void`, `const wchar_t *`, full-width `int`, and `const RectBounds *`, and delegate to UID00016D. UID0004NH uses `m_textColor +0x7c` and `m_textBackColor +0x80`; UID0004NI has no explicit color-field mutation.
- Caller closure is five outlined and two shadowed direct calls across chat/color, StaticText2, and HelpPane consumers. No data/vtable/table/pointer route, additional caller, or source owner outside GrafPort exists.
- Security cookies, XMM rectangle copies, padding, register temporaries, and tail EAX are compiler artifacts and never appear in the generated human source.
- Exact original names/access visibility remain inferred. `DrawOutlinedText` is disambiguated from the existing x/y overload by the RectBounds signature; `DrawShadowedText` is retained from independent effect-3 callers with an explicit same-color duplicate-offset body caveat.
- UID00016E remains linked for physical audit only. Generated output must contain no UID00016E marker/body and exactly one definition from each exact child.

[UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) is retained file-owned GrafPort.cpp source and emits as file-static `PackTwoColorSixPixelPattern` through class UID00005V's assembler. Local PE bytes prove the complete 33-byte `retn 0x0c` body at raw offset `0x000ba9b0`, and live `DrawGlyphWithTextColors` / `DrawWideText` independently build the identical `{m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor}` pattern before calling `GrafPortDrawGlyph`. The complete source-shaped body, exact source-family duplicates, and absence of member state support file-static retention; zero caller/pointer/table/branch routes remain liveness evidence and cap confidence rather than forcing a no-owner/no-code disposition. The assembler route places this definition after UID0003XE and before UID00016I.

## Cross-References

- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md)
- [UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md)
- [UID:0004LN][0x004b94f0-0x004b9509.GrafPortReleaseSurface](by-memory/0x004b94f0-0x004b9509.GrafPortReleaseSurface.md)
- [UID:0004LO][0x004b9510-0x004b951d.GrafPortSetSurfacePixelData](by-memory/0x004b9510-0x004b951d.GrafPortSetSurfacePixelData.md)
- [UID:0004LP][0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride](by-memory/0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride.md)
- [UID:0004LQ][0x004b9530-0x004b9545.GrafPortGetOrigin](by-memory/0x004b9530-0x004b9545.GrafPortGetOrigin.md)
- [UID:0004LR][0x004b9550-0x004b9574.GrafPortSetOrigin](by-memory/0x004b9550-0x004b9574.GrafPortSetOrigin.md)
- [UID:0004LS][0x004b9580-0x004b958c.GrafPortSetClipRegion](by-memory/0x004b9580-0x004b958c.GrafPortSetClipRegion.md)
- [UID:0004LT][0x004b9590-0x004b95a3.GrafPortGetClipRegion](by-memory/0x004b9590-0x004b95a3.GrafPortGetClipRegion.md)
- [UID:0004LU][0x004b95b0-0x004b95bc.GrafPortSetClipRect](by-memory/0x004b95b0-0x004b95bc.GrafPortSetClipRect.md)
- [UID:0004LV][0x004b95c0-0x004b95c5.GrafPortDisableDrawing](by-memory/0x004b95c0-0x004b95c5.GrafPortDisableDrawing.md)
- [UID:0004LW][0x004b95d0-0x004b95d5.GrafPortEnableDrawing](by-memory/0x004b95d0-0x004b95d5.GrafPortEnableDrawing.md)
- [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md)
- [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md)
- [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md)
- [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md)
- [UID:0004H2][0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo](by-memory/0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo.md)
- [UID:0004H3][0x004b98c0-0x004b98ee.GrafPortEndPaint](by-memory/0x004b98c0-0x004b98ee.GrafPortEndPaint.md)
- [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md)
- [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md)
- [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md)
- [UID:0004H7][0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer](by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md)
- [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)
- [UID:0004NH][0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect](by-memory/0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect.md)
- [UID:0004NI][0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect](by-memory/0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect.md)
- [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md)
- [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md)
- [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## UID0002YF Surface Callback Interaction - 2026-08-04

[UID:0002YF][0x004be680-0x004bed67.SoftwareRenderCompatFillCallback](by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md) is emitted from `NexusTK/render/Surface.cpp`, not `GrafPort.cpp`, but its complete receiver use is part of the GrafPort source contract:

- The file-local Surface slot-7 provider receives `GrafPort *port` and `const RectBounds *bounds`, exits when `m_drawEnabled` is false, obtains the current clip through `GrafPort::GetClipRect`, intersects the request, and rejects an empty result.
- It derives the RGB555 destination from embedded `m_surfaceContext.pixelData`, `rowStridePixels`, and `bounds`; the first output index is `clipped.left + rowStridePixels * (clipped.top - context.bounds.top) - context.bounds.left`, and each row advances by the accepted stride.
- It consumes `m_drawMode`, `m_drawColor`, `m_textBackFillColor`, `m_alpha`, and `m_usesSoftwareBuffer`. Modes 0/1/2/3 select copy, raw-color-keyed copy, weighted blend, and raw-color-keyed weighted blend; modes 1/3 test raw draw color zero. Software-buffer color index 128 overrides the mapped RGB555 fill pixel to value 1.
- Color mapping uses `g_pPaletteLib->GetCurrentPalette()`, not GrafPort's borrowed `m_palette`. Both `MapColor(m_drawColor)` and the otherwise discarded `MapColor(m_textBackFillColor)` call remain behaviorally required. The RGB565 peer's optional member-palette behavior is provider-specific and is not a general GrafPort fill rule.
- Weighted modes convert `m_alpha` to a byte-wrapped 32-based destination weight and call `BlendRgb555(existingDestination, fillPixel, destinationWeight)`. Direct modes preserve packed-pair stores and an odd tail; SIMD/mask constants are compiler lowering of these scalar source operations.
- This interaction validates GrafPort field and embedded-context vocabulary only. The callback has no GrafPort member/vtable route, is installed by Surface initializers into `g_pfnFillRect`, and remains owned/emitted by UID0000OC. No GrafPort metadata, formal source, or source path changes here.

## Historical And Superseded Changes

The dated entries below preserve implementation chronology only. Their earlier scores and blank/no-emitter/no-code conclusions lost authority when the 2026-08-22 UID0000JR whole-file resolution populated the complete formal GrafPort source route documented in the active sections above.

- 2026-08-23 UID0003XF Gate 2A source-order repair:
  - Rejected direct-file emitter UID0000JR because generated command `000000027211` placed UID0003XE before UID00016I and only then emitted UID0003XF after covered UID0003BE/UID0002V5 markers. That route contradicted the address/source inventory above.
  - Retained UID0000JR as canonical file owner and moved only assembly emission to class UID00005V, restoring `UID0003XE -> UID0003XF -> UID00016I` without changing the helper's file-static source semantics.
- 2026-07-28 B002 UID0002TE support sync: added exact Surface slot-6 receiver/layout dependencies and rejected stale field/stride aliases without changing GrafPort file score, path, class/source ownership, or method-emission topology.

- 2026-07-24 B002 UID0002PJ GrafPort file synchronization:
  - Preserved `89/88`, `NexusTK/render/`, all unrelated proposed contents, field/method history, and exact child ordering.
  - Corrected UID0004H4 inventory/history to the current IDA-backed void contract and documented the wrapper/table/provider ownership boundary without importing the Surface callback body into GrafPort.

- 2026-07-14 B005 UID00037V support synchronization:
  - Added the source inventory/behavior contract for `0x004b8dd0-0x004b8de3` as `GrafPort::GetExposedRegion(Region *out) const`, preserving exact 19-byte/one-block evidence, 30 xrefs across nine functions, UID0004QY consumer context, and the lexical spelling cap.
  - Rejected historical caller-biased `SaveClipRegion`; file score, path, owner, unrelated inventory, and emission policy remain unchanged.
- 2026-07-14 B005 UID00016E implementation synchronization:
  - File score `89/88`, `NexusTK/render/` path, `CANONICAL_OWNER:FILE`, and all unrelated source inventory remain unchanged.
  - Added exact source order and generated policy for non-emitting UID00016E, source definitions UID0004NH/UID0004NI, independently routed UID00016F, SoftwareBlend16 successor UID0003ZP, and every excluded padding/compiler span.
  - Preserved full ABI/field/color/rectangle/caller/callee/negative/history/lexical evidence and explicitly rejected feature, Surface, RectBounds, SystemMessagePanes, and new-file ownership for the two methods.
- 2026-07-13 B001 UID0004H7 implementation callback:
  - File score, proposed path, owner metadata, unrelated proposed contents, and sibling order remain unchanged at `89/88` and `NexusTK/render/`.
  - Marked UID0004H7 source-ready with its resolved `void` signature, borrowed RectBounds/caller-owned Region contract, exact GrafPort fields, helper identities, three callers, four directional branches, and preserved anomalous clear.
  - Established generated source order after UID000166 and before UID000167, and historicalized B010/Wave2 blank-C++, unresolved-argument, FolderTreePane-owner, and `bool`-return wording.
- 2026-07-13 B002 UID0002YK implementation callback support sync:
  - File score, source path, and unrelated proposed contents remain unchanged; no by-file reconstruction metadata or callback body was added.
  - Added exact target-specific GrafPort field/type dependencies, typed `void *` byte/pixel address routing, color/palette/software-buffer semantics, direct-fill ordering, and destination-weight direction.
  - Replaced current generic `rowStride` field wording with accepted `rowStridePixels`, preserving the former token only as labeled history.
- 2026-07-13 B004 UID0003XB implementation synchronization:
  - Score `89/88`, file owner/path metadata, and all unrelated proposed contents remain unchanged.
  - Replaced the vague UID0003XB row with the exact non-emitting index and ten validator-assigned GrafPort source definitions UIDs 0004LN-0004LW.
  - Added accepted fields, caller/liveness/lifecycle evidence, historical corrections, compiler/source distinction, and rejected Surface/DirectX/Region/feature placements without broader file-score inflation.

- 2026-07-12 B004 UID000163 route/source-readiness sync:
  - Score, metadata, and file formal C++ remain unchanged.
  - Evidence: exact `GrafPort::GetPalette` / `SetPalette` definitions now emit through this file over borrowed `DLPalette *m_palette`; constructor/destructor, ten caller sites, and DrawGlyph callback use supersede historical opaque brush-handle wording without changing sibling methods.
- 2026-07-04 B010 UID000165 implementation callback:
  - Score unchanged at `89/88`.
  - Historically added UID000165 split children to the GrafPort proposed-content route: source-ready `UpdateSurfaceInfo`, `EndPaint`, `LineTo`, `DrawSprite`, and `RenderTileFrame`, plus then-owner-known/non-emitting `ScrollPixelBuffer`; B001 superseded only the latter disposition on 2026-07-13.
  - Evidence: accepted B010 report, MCP session `73c77998`, exact child function sizes, xref counts, callee/callback sets, receiver-field proof, generated empty-marker context, and rejection of Surface direct ownership and feature-owner pollution.

- 2026-07-03 Agent-B007 UID0004DI implementation sync:
  - Score unchanged at `89/88`.
  - Evidence at that date treated [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) as owner-known but non-emitting. MCP session `3a33af0b` and PE route scans found no function, entry refs, `analyze_function` object, or rel32/short-branch/VA/RVA hits; generated `GrafPort.cpp` therefore then had no UID0004DI marker/body while `EMITTER_UIDS` was blank. The 2026-08-22 whole-file resolution superseded that blank-emitter/output conclusion; [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) remains the independently emitted sibling.
- 2026-07-02 B006 UID000166 implementation sync:
  - Score unchanged at `89/88`.
  - Evidence at that date routed [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) through `NexusTK/render/GrafPort.cpp` under the provisional `GrafPort::ForwardToTileFrameBlitHelper` spelling. The exact child recorded the dated B006 session proof for range/padding, three callers, hidden destination receiver, source-record rectangle fields, `dword_69B3E8` slot-2 dispatch, nullable opaque options pointer, and rejection of Surface, feature-owner, callback-table-target, PaletteLib, and no-code routes. The later whole-file pass superseded only the provisional name/type details with `BlitTileContextAt` and exact current formal source.
- 2026-07-02 Agent-B005 UID0003XC split implementation:
  - Score unchanged at `89/88`.
  - Evidence at that date made [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) a non-emitting split/container with exact children [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) and [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md). UID0004DI then remained blank-emitter/code under the dated no-function/no-route proof; the later whole-file resolution superseded that child disposition. The release child emits `GrafPort::ReleaseBackingStore()` after six direct branch callers and field evidence prove GrafPort backing-store ownership. MapPane/ObjectPane callers, Surface adjacency, and `g_pDirectX` dependency remain non-owner evidence; exact original spelling remains inferred.
- 2026-06-26 B002 GrafPortDrawGlyph implementation sync:
  - Score unchanged.
  - Historical evidence: [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) gained first-draft formal C++ through this route with then-accepted `m_brushHandle`; UID000163 now narrows only that target-related token to `m_palette`, preserving every other DrawGlyph behavior and line.
- 2026-06-25 B009 GetClipRect route update:
  - Score unchanged at `89/88`.
  - Evidence: [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) now uses the exclusive end `0x004b9768`, emits formal `GrafPort::GetClipRect(RectBounds *outClipRect)` C++, and routes through `NexusTK/render/GrafPort.cpp`. The accepted evidence preserves the `0xa8` function size, `retn 4`, eight bytes of `0xcc` padding before the raw successor island, 44 direct code refs, `m_exposedRegion` at `this+0x04`, `m_clipRegion` at `this+0x54`, `m_surfaceContext.bounds` at `this+0x2c`, the `0x005547e0` raw-rect intersection wrapper role, and rejection of generated `RankingEventListPane` ownership.
- 2026-06-18 B003 CompositePixels route update:
  - Score unchanged at `89/88`.
  - Evidence: B003 reanalysis routes [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) through this file as `GrafPort::CompositePixels`, with report-level details for exact padded boundary, three direct rel32 callers from BowGaugeObjectPane/TextEditPane, no pointer-table or Surface callback route, `m_drawEnabled`, embedded `EPFTileContext` pixel/stride/bounds fields, `m_backgroundColor` / `SetBkColor` at `+0x7c`, palette mapping through `PaletteLib::GetCurrentPalette` and `DLPalette::MapColor`, zero-pixel fill, nonzero bitwise inversion, and rejected BowGauge/TextEdit/Surface ownership.
- 2026-06-21 B006 line-count helper support sync:
  - Score unchanged at `89/88`.
  - Evidence: added [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) to the text-helper reconciliation notes after [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) confirmed the context/text/length/width call shape from the Chatting source family. Current ownership remains unchanged because the helper has no GrafPort state access and returns constant one.
- 2026-06-18 B002 DrawTiledBackground route update:
  - Before: `88/87`; [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) was listed as a shared helper but still carried unresolved generated-owner and source-quality wording.
  - After: `88/88`.
  - Evidence: B002 reanalysis routes [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) through this file as `GrafPort::DrawTiledBackground`, with report-level details for exact body/padding, 26 direct rel32 references, `m_clipRegion`, `m_visibleBounds`, `m_drawMode`, `m_alpha` callback dependency, `FrameDrawRecord` source rectangle, `g_pPaletteLib->GetPaletteByName`, `dword_69B3E8`, RankingEventListPane/Surface owner rejection, and first-draft C++ readiness.
- 2026-06-18 B002 GrafPortDrawRectFrame route update:
  - Before: `88/86`; [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) was described as a shared rectangle helper with caller-biased generated ownership still visible.
  - After: `88/87`.
  - Evidence: B002 reanalysis routes [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) through this file as `GrafPort::DrawRectFrame`, with report-level details for exact body/padding, 49 direct rel32 references, `m_drawEnabled`, `m_currentX`/`m_currentY`, `RectBounds`, line-delta callback slot `dword_69B3E4`, original-rectangle drawing after clipped visibility acceptance, and rejected RankingEventListPane/Surface ownership.
- 2026-06-18 B003 SurfaceSpriteBlitHelper route update:
  - Before: `88/85`; [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) was still treated as a provisional Surface bucket child.
  - After: `88/86`.
  - Evidence: the target is now documented as `GrafPort::BlitSurface` and emits through `NexusTK/render/GrafPort.cpp`; B003 preserved the destination/source GrafPort receiver model, DirectDraw `BltFast` flags, software callback path through `dword_69B3E8`, field offsets `+0x18/+0x1c/+0x20/+0x28/+0x90/+0x94`, and MapPane/Surface owner rejections.
- 2026-06-18 B005 SurfaceTileBufferBlitRaw reroute:
  - Score unchanged at `89/88`.
  - Evidence: [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) now routes to [UID:00005V][GrafPort](by-class/GrafPort.md) at `85/88` with blank formal C++. B005 rechecked prior no-owner reports and tied the raw helper's virtual `UpdateRenderRegion` call plus `m_surfaceContext` field writes to GrafPort while preserving no-entry/no-signature blockers.
- 2026-06-18 B003 current reanalysis sync:
  - Score unchanged at `88/85`.
  - Evidence: [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) remains a no-owner/non-emitting `PackTwoColorSixPixelPattern` raw helper. Fresh PE-byte checks reconfirmed unique target bytes, unique store-body subpattern, all-`0xcc` padding, no pointer/direct-branch route, and live positive controls for neighboring LineClip/GrafPortDrawGlyph entries; the only broad short-branch candidate was a non-instruction ModRM byte. GrafPort glyph/text support remains descriptive rather than an ownership route.
- 2026-06-17 B003 GrafPort split/source-quality update:
  - Score unchanged at `88/85`.
  - Evidence: converted the broad [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) entry to a non-emitting split/index, incorporated [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) as `GrafPort::EnableSoftwareBuffer`, and added the split raw-helper children [UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md) and [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md). The software-buffer field at `this+0x94` replaces the old dirty-field wording, and source placement is kept under `NexusTK/render/GrafPort.cpp` rather than Surface, DirectX, FontImageLib, or a UI-control module.
- 2026-06-17 B002 raw-island support update:
  - Score unchanged at `88/85`.
  - Evidence: added [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) as a reviewed no-owner two-color six-byte pattern pack helper with GrafPort glyph/text support as best forced family but no direct ownership/emission route.
- 2026-06-08 A004 Batch 119 parent-gate update:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`; the page grouped text helpers broadly but did not explicitly document the wrapped rect draw and text-effect helpers needed for Batch 119 parent routing.
  - After: `COMPLETION:88`, `CONFIDENCE:85`.
  - Evidence: fresh IDA-backed Batch 119 review confirmed `DrawTextInRect` and the outlined/shadowed text-effect helpers are GrafPort receiver methods with broad caller fan-in and shared draw-state/FontImageLib dependencies. This supports [UID:00005V][GrafPort](by-class/GrafPort.md) as the direct class parent for those helpers; the later B003 review keeps final source placement in `render/GrafPort.cpp`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: render-port role, dirty region/surface/buffer behavior, DirectDraw/software paths, draw-state/text/tile helper ownership, and global operand correction are documented. The later B003 review resolves source placement to `render/GrafPort.cpp` and routes exact raw/helper children separately.
- 2026-06-01: Changed proposed reconstruction path from blank to `NexusTK/render/`.
  - Before: The page named `render/GrafPort.cpp` as the strongest placement but left validator path metadata blank.
  - After: Validator metadata now stages `GrafPort.cpp` under `NexusTK/render/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `render/GrafPort.cpp`, and IDA MCP rechecks tie the low-level draw-state, clip, DirectDraw, and buffer helpers to render-port state rather than a feature UI module.

### UID000161 GrafPortGetBounds Source Placement - 2026-07-15

- [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) now belongs in `NexusTK/render/GrafPort.cpp` as the one out-of-line `GrafPort::GetBounds` definition. The corresponding complete-header union declares a const member taking and returning `RectBounds *`; this by-file page remains prose-only and has no reconstruction metadata.
- Exact behavior is a 17-byte, no-callee leaf copying `GrafPort::m_visibleBounds` at `+0x44` to the caller output and returning that pointer. Exact predecessor/successor padding, one explicit `ret 4` argument, 103 direct calls, and zero target pointer/table hits remain preserved.
- The source route is established by a direct call on `HitBarObjectPane` inside UID0003TC, broad BackPane/UI/map/render receivers, common GrafPort ancestry, the accepted `m_visibleBounds` layout, and the surrounding GrafPort function island. BackPane is a consumer through inheritance, not a second definition owner.
- Historical B003 `BackPaneGetBounds`/`BackPane::GetBounds`/`Pane::m_bounds` spelling is retained as superseded provenance only. Pane ownership and a free helper are also rejected; neither matches the accepted field/source island as well as GrafPort, and duplicate definitions would be invalid.
- File metadata remains `89/88`. Existing surface, clip, drawing, glyph, text, software-buffer, DirectDraw, and raw-helper evidence is unchanged; UID000161 closes only this exact inherited accessor route.
