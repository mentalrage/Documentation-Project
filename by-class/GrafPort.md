*** UID:00005V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "GrafPort.h"

#include "DirectX.h"
#include "FontImageLib.h"
#include "ImageFrameTable.h"
#include "PaletteLib.h"
#include "Surface.h"
#include "../app/Application.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"
#include "../util/StringUtil.h"

#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <ddraw.h>
#include <windows.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_RENDER_GRAFPORT_H
#define NEXUSTK_RENDER_GRAFPORT_H

#include <cstddef>
#include "../util/LObject.h"
#include "../ui/core/RectBounds.h"
#include "../ui/core/Region.h"
#include "EPFTileContext.h"

struct IDirectDrawSurface;
struct DLPalette;
struct FrameDrawRecord;
struct SurfaceSpriteBlitOptions;

class GrafPort : public LObject
{
public:
    GrafPort();
    virtual ~GrafPort();
    virtual void UpdateRenderRegion(const RectBounds *bounds);

    void EnableSoftwareBuffer();
    RectBounds *GetBounds(RectBounds *outBounds) const;
    void GetExposedRegion(Region *outRegion) const;
    EPFTileContext *GetSurfaceContext();
    void ReleaseSurface();
    void SetSurfacePixelData(void *pixelData);
    void SetSurfaceRowStride(int rowStridePixels);
    Point *GetOrigin(Point *outOrigin) const;
    void SetOrigin(int x, int y);
    void SetClipRegion(const Region *clipRegion);
    void GetClipRegion(Region *outClipRegion) const;
    void SetClipRect(const RectBounds *clipRect);
    void DisableDrawing();
    void EnableDrawing();
    void GetDrawPosition(int *outPosition);
    void MoveTo(int x, int y);
    void OffsetDrawPosition(int deltaX, int deltaY);
    void SetFontId(unsigned short fontId);
    void SetDrawMode(unsigned char drawMode) { m_drawMode = drawMode; }
    void SetTextDrawMode(unsigned char mode) { m_textDrawMode = mode; }
    void SetDrawColor(unsigned int color);
    void SetTextBackFillColor(unsigned int color);
    void SetTextColor(unsigned int color);
    void SetTextBackColor(unsigned int color);
    DLPalette *GetPalette() const;
    void SetPalette(DLPalette *palette);
    void GetClipRect(RectBounds *outClipRect);
    void ReleaseBackingStore();
    void UpdateSurfaceInfo();
    void EndPaint();
    void LineTo(int x, int y);
    int DrawSprite(GrafPort *source,
                   const RectBounds *sourceRect,
                   const RectBounds *destinationRect,
                   int mode,
                   DLPalette *palette,
                   const SurfaceSpriteBlitOptions *options);
    int RenderTileFrame(const EPFTileContext *sourceContext,
                        const RectBounds *sourceRect,
                        const RectBounds *destinationRect, int mode,
                        const wchar_t *paletteName,
                        const SurfaceSpriteBlitOptions *options);
    int BlitTileContextAt(int destinationX,
                          int destinationY,
                          const EPFTileContext *sourceContext,
                          DLPalette *palette,
                          unsigned char mode,
                          SurfaceSpriteBlitOptions *options);
    void ScrollPixelBuffer(const RectBounds *scrollRect,
                           int deltaX, int deltaY, Region *dirtyRegion);
    void BlitSurface(GrafPort *source, const RectBounds *sourceRect,
                     const RectBounds *destinationRect, int mode);
    void DrawRectFrame(const RectBounds *rect);
    void CompositePixels(const RectBounds *rect);
    void DrawTiledBackground(const RectBounds *clipRect,
                             const FrameDrawRecord *frameRecord,
                             const wchar_t *paletteName);
    void FitTextAndAppendSuffix(wchar_t *text, std::size_t textCapacity,
                                const wchar_t *suffix, int maxPixelWidth);
    int CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth);
    short GetTextWidth(const wchar_t *text, int charCount);
    short GetTextWidth(const wchar_t *text);
    short GetLineHeight();
    unsigned short AdjustVisibleCountForTrailingWhitespace(
        const wchar_t *text, short count);
    void DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh);
    void DrawWideText(const wchar_t *text, int charCount);
    void DrawOutlinedText(int x, int y,
                          const wchar_t *text, int charCount);
    void DrawTextInRect(const wchar_t *text, int length,
                        const RectBounds *rect);
    void DrawOutlinedText(const wchar_t *text, int length,
                          const RectBounds *rect);
    void DrawShadowedText(const wchar_t *text, int length,
                          const RectBounds *rect);
    void DrawGlyph(wchar_t ch,
                   wchar_t nextCh,
                   bool fillBackground,
                   const unsigned char *glyphColors);

private:
    void BuildEffectiveClipRegion(Region *outRegion);
    void BlitTileContextToSurface(const EPFTileContext *sourceContext,
                                  DLPalette *palette);

protected:
    Region m_exposedRegion;
    IDirectDrawSurface *m_ddSurface;
    EPFTileContext m_surfaceContext;
    RectBounds m_visibleBounds;
    Region m_clipRegion;
    int m_currentY;
    int m_currentX;
    unsigned char m_drawMode;
    bool m_drawEnabled;
    unsigned int m_drawColor;
    unsigned int m_textBackFillColor;
    unsigned int m_textColor;
    unsigned int m_textBackColor;
    DLPalette *m_palette;
    unsigned char m_textDrawMode;
    unsigned short m_fontId;
    int m_textAlign;
    float m_alpha;
    bool m_usesSoftwareBuffer;
    void *m_softwareBuffer;
    int m_softwarePitchBytes;
};

typedef char GrafPortSizeMustBe160[sizeof(GrafPort) == 0xa0 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GrafPort

## 2026-08-18 ObjectImage Render Consumer

- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) and [UID:0001BV][0x00520820-0x00520a97.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md) consume inherited GrafPort rendering state and APIs.
- Base `ObjectImageControlPane::OnPaint` calls `SetDrawColor(0)` and centers the Human, Monster, or Item preview against inherited `m_visibleBounds`. Button `ObjectImageButtonPane::OnPaint` reads the same visible bounds and, when highlighted, dispatches the six-argument `RenderTileFrame` contract for `CAPSULE.EPD` / `NPAL3.PAL` before drawing the centered human image; the accepted button body makes no `SetDrawColor` call.
- These calls do not create ObjectImage-local m_bounds, fill, or abbreviated frame-render APIs. GrafPort retains m_visibleBounds and all draw-method ownership.

## Historical And Superseded UID00041S Shared Surface ABI Visibility - 2026-08-11

- The formal CPP preamble now includes `Surface.h` immediately after `GrafPort.h`. This gives GrafPort child definitions one canonical complete declaration of `SurfaceSpriteBlitOptions`, `SurfaceSpriteBlitProc`, and `g_pfnBlitSprite` from semantic owner [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).
- `GrafPort.h` deliberately retains only `struct SurfaceSpriteBlitOptions;` because every GrafPort declaration uses the type through a pointer. The complete options layout does not belong in GrafPort's header, and importing `Surface.h` there would create unnecessary coupling/cycle risk.
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) consumes the shared definition through this source include and no longer declares a child-local forward/typedef/extern trio. UID00041S also includes `Surface.h` through its ItemObjImageLib position-0 route, so both consumer families use one ABI.
- At the 2026-08-11 UID00041S checkpoint, the complete `GrafPort` declaration, `0xa0` layout, pointer-only forward declarations, all child bodies, and then-current metadata `88/90` remained unchanged because that integration changed compile visibility only. The later 2026-08-22 UID0000JR whole-file resolution superseded only the score/formal-state checkpoint with current `94/95` and complete populated CPP/H channels; callback storage and options ownership still remain external.

## C134 Header Assembly Closure

`GrafPort.h` is a single canonical complete declaration protected by `NEXUSTK_RENDER_GRAFPORT_H`; its method bodies remain CPP children and therefore no empty H-channel child token is emitted. Pointer-only `SurfaceSpriteBlitOptions` remains a forward declaration in the header, while `GrafPort.cpp` includes `Surface.h` for child definitions. The forward declaration is `struct DLPalette`, matching the existing project declaration kind and eliminating command20473's class/struct mismatch without changing the pointer-only use. Guarded LObject, RectBounds, Region, and EPFTileContext dependencies preserve the exact `0xa0` layout assertion across repeated Pane/TextEditPane include routes.

## Status

- Confidence: strong for imported methods and state responsibilities.
- Likely source file: [UID:0000JR][GrafPort](by-file/GrafPort.md)
- Address range: [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- Current recovered file: `source-3/simroot_v2/class_GrafPort.cpp`

## Class Purpose

`GrafPort` is the core graphics-port base class. It gives panes and render objects a clipped region, dirty/exposed region state, default draw attributes, and backing storage. The backing storage can be a DirectDraw surface or an owned software buffer.

Its shared text surface includes the two `GetTextWidth` overloads, `GetLineHeight`, receiver-independent member `AdjustVisibleCountForTrailingWhitespace`, glyph-color packing, wide-text drawing, and outline drawing. The visible-count helper remains a non-static member because all four TextEditPane callers establish their inherited GrafPort receiver in `ECX`; absence of receiver-field reads does not make it file-static source.

## Historical And Superseded B010 2026-08-14 Draw-Mode Setter Closure

- At this 2026-08-14 checkpoint, the class remained then-current `88/90`; that score and incremental-formal description are superseded by the 2026-08-22 UID0000JR complete `94/95` CPP/H closure. The accepted `void SetDrawMode(unsigned char drawMode)` over `m_drawMode +0x70` and `void SetTextDrawMode(unsigned char textDrawMode)` over `m_textDrawMode +0x88` remain public inline one-byte stores and add no object state, padding, virtual slots, or out-of-line child bodies.
- [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md) is the source consumer that closes both declarations. Current mode sets text draw mode `1` before wrapped/outlined text. Legacy mode sets draw mode `0` before tiled-background rendering, then text draw mode `1` before the final text draw.
- Direct binary stores to the two established receiver offsets prove the setter semantics. The methods expose already-modeled state rather than inventing a new API layer; names follow existing `SetTextColor`, `SetTextBackColor`, and other GrafPort setter vocabulary. Exact original lexical spellings remain inferred but raw offset stores do not belong in human source.
- ColorStringChattingMessage owns only the calls. GrafPort retains field/API ownership, [UID:0000JR][GrafPort](by-file/GrafPort.md) retains source placement, and no draw body, palette behavior, compiler table, or Chatting method moves into this class.

## UID000090 Complete Header And Layout Closure - 2026-07-31

- The formal CPP route is now exactly `#include "GrafPort.h"`, `#include "Surface.h"`, a blank line, and `[[CHILDREN]]`; exact method bodies remain on their by-memory emitters and are not duplicated at class level.
- The formal H is a complete `GrafPort : public LObject` declaration. It includes `<cstddef>`, `LObject.h`, shared `RectBounds.h`/`Point`, complete by-value `Region.h`, and `EPFTileContext.h`; only pointer-only `IDirectDrawSurface`, `DLPalette`, `FrameDrawRecord`, and `SurfaceSpriteBlitOptions` remain forward declarations.
- The declaration preserves the accepted virtual surface, method inventory, and exact `0xa0` layout. Natural compiler alignment supplies `+0x72..+0x73`, `+0x89`, and `+0x95..+0x97`; no authored reserve members are introduced.
- Canonical field vocabulary is `m_surfaceContext`, `rowStridePixels`, `m_textBackFillColor`, `m_drawMode`, and `m_fontId`. Stale child spellings `m_tileContext`, `rowStride`, `m_backgroundColor`, `m_renderMode`, and `m_fontStyleId` are historical aliases only and are normalized on their exact child pages.
- A PCH-only base, incomplete by-value `Region`, raw `size_t` without its standard namespace, a second local `Point`, and a truncated `0x88` object are rejected. The size guard remains `GrafPortSizeMustBe160`.

## Observed State

The generated source exposes a packed state block inside `m_stateBuffer`. Important fields include:

```text
0x00  cached handle/state token
0x08  bounds / clip rectangle
0x18  dirty Region subobject
0x30  anchor point
0x38  scale, alpha, color, enabled/default state
0x58  ownsSoftwareBuffer flag
0x5c  software buffer pointer
0x60  software stride
```

The outer object also owns an exposed/dirty `Region` at `this+0x04`, primary surface handle, lock-state fields, draw cursor/color/font fields, and view-origin/bounds helpers.

### UID0002PJ Accepted Draw-State Layout And Slot-1 Contract

- Historical UID0002PJ work correctly fixed the members through borrowed `DLPalette *m_palette +0x84`, but its then-current `0x88` total-size statement is superseded. Compiler construction/destruction, `GrafPort` methods, and embedded-member spacing prove exact size `0xa0`; `+0x88` is the start of a real tail, not the object end.
- Embedded `EPFTileContext m_surfaceContext` starts at `+0x1c` and supplies `pixelData +0x04`, `rowStridePixels +0x0c`, and `RectBounds bounds +0x10` relative to that subobject; [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) uses those fields for exact destination addressing.
- Draw cursor/state fields through the old boundary remain `int m_currentY +0x68`, `int m_currentX +0x6c`, `unsigned char m_drawMode +0x70`, `bool m_drawEnabled +0x71`, `unsigned int m_drawColor +0x74`, `unsigned int m_textBackFillColor +0x78`, `unsigned int m_textColor +0x7c`, `unsigned int m_textBackColor +0x80`, and borrowed `DLPalette *m_palette +0x84`.

The accepted tail is contiguous and ends exactly at `+0xa0`:

| Offset | Size | Source member / role |
| --- | --- | --- |
| `+0x88` | `1` | `unsigned char m_textDrawMode`; text drawing/background mode, not a dirty byte |
| `+0x89` | `1` | implicit/alignment byte; IDA layout name `_alignment89`, not an authored semantic field |
| `+0x8a` | `2` | `unsigned short m_fontId`; font/style id consumed by text measurement/drawing |
| `+0x8c` | `4` | `int m_textAlign`; text alignment state |
| `+0x90` | `4` | `float m_alpha`; callback-visible opacity/alpha state |
| `+0x94` | `1` | `bool m_usesSoftwareBuffer`; selects software backing path |
| `+0x95` | `3` | implicit alignment before the backing pointer; IDA layout name `_alignment95[3]` |
| `+0x98` | `4` | `void *m_softwareBuffer`; optional software backing storage |
| `+0x9c` | `4` | `int m_softwarePitchBytes`; byte pitch/stride for software backing |

- Constructor `0x004b8bf0` writes through terminal field `+0x9c`. `ScrolledTextControlPane` and `ScrolledTextControlPaneForMadeBy` embed GrafPort at `+0x130` and place their next field at `+0x1d0`, independently proving `0x1d0 - 0x130 = 0xa0` (Verified with `tools/int_convert.py`).
- The source model relies on ordinary compiler alignment after `m_textDrawMode` and `m_usesSoftwareBuffer`; do not add semantic reserve/padding members. The accepted current IDA conclusion preserves the existing `0xa0`, 23-member `GrafPort` UDT unchanged. The earlier proposal that Gate 2B could name explicit alignment members is superseded history and is not an active action.
- [UID:0004WP][0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor](by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md) and its made-by sibling construct the embedded GrafPort automatically after `EPFTileContext`; their exact `0x1dc` object layout makes the `0xa0` extent a compiler-enforced class boundary rather than a caller-specific estimate.
- [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md) is exact `void GrafPort::LineTo(int x, int y)`: it subtracts `m_currentX`/`m_currentY` from the absolute endpoint and tail-dispatches `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`. The selected Surface callback, not the wrapper, owns clipping, pixel work, and advancement of the original deltas.
- The RGB565 line callback reads `m_drawColor` and maps it through the process current palette. It does not use `m_palette +0x84` for this operation. Raw array indices, `sub_` labels, and `dword_69B3E4` remain binary-history evidence rather than final class/source names.
- These accepted field names/types are authoritative in the formal source layout. No IDA UDT layout repair is pending or authorized: the current recommendation leaves the existing 23-member UDT unchanged, and this class documentation does not duplicate the callback body under GrafPort.

### UID0002TF Accepted Slot-3 RLE Callback State

- [UID:0002TB][0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback](by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md) and [UID:0002TF][0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback](by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md) are static/file-local Surface callbacks that consume a `GrafPort *` receiver; they are not GrafPort member functions.
- The exact slot-3 contract consumes `m_drawEnabled +0x71`, `m_surfaceContext.pixelData +0x20`, `rowStridePixels +0x28`, and bounds origin at `+0x2c/+0x30`. It obtains the effective clip through `GetClipRect`, intersects destination bounds, and translates the clipped delta back into source coordinates before decoding runs.
- `unsigned int m_drawColor +0x74` is the primary run color. `unsigned int m_textBackFillColor +0x78` is the canonical secondary/background fill color: it is palette-mapped for blend mode and its raw low 16 bits are written by mode `0` positive runs. Historical `m_secondaryDrawColor` is retained as an old callback-specific alias only and is not the canonical class/source spelling.
- The callbacks map through the explicit nullable palette argument or the process current palette. They do not use borrowed `m_palette +0x84` for this slot-3 operation. Compat and RGB565 use the same field layout and RLE/mode contract; only their 16-bit blend masks differ.
- The class is currently `94/95` with a populated complete formal CPP preamble and populated complete formal H declaration. This slot-3 synchronization remains an external callback clarification only and does not add a GrafPort-owned callback body. The accepted IDA disposition preserves the existing `0xa0`, 23-member UDT unchanged; no split or type application remains pending.

### UID0002TE Accepted Slot-6 Bitmask Callback State

- [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) and [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) are static/file-local Surface callbacks that consume a `GrafPort *`; neither is a GrafPort member or class-owned body.
- Exact current layout is `sizeof(GrafPort) == 0xa0`. Embedded `EPFTileContext m_surfaceContext` at `+0x1c` supplies `pixelData +0x04` / receiver `+0x20`, logical-pixel `rowStridePixels +0x0c` / receiver `+0x28`, and `RectBounds bounds +0x10` / receiver `+0x2c`. Slot-6 destination addressing uses those typed members after clipping through `GetClipRect`.
- The draw-enabled gate is `m_drawEnabled +0x71`; primary palette index is `m_drawColor +0x74`; secondary/background-fill palette index is canonical `m_textBackFillColor +0x78`. Historical callback-specific `m_secondaryDrawColor`, generic `rowStride`, and raw receiver offsets remain superseded aliases, not source declarations.
- `SurfaceBitmaskBlitProc` receives raw contiguous MSB-first packed 1bpp mask bytes, destination bounds, and mode. Both providers translate clipped destination geometry into mask coordinates; compat maps RGB555 colors and reuses `BlendRgb555Half`, while RGB565 maps the same fields and uses `BlendRgb565Pixel`.
- GrafPort owns the receiver layout and `GetClipRect`; semantic UID0000TN and file UID0000OC own callback declaration/storage and implementations. BalloonObjectPane is a typed consumer. No class metadata or whole-class formal block changes are justified by this external callback closure.

## UID00037V Exposed-Region Getter Contract

- The compact method at `0x004b8dd0-0x004b8de3` is best source-facing `void GrafPort::GetExposedRegion(Region *out) const`. Its exact 19-byte, one-basic-block body copy-constructs/copies the receiver-owned exposed Region at `this+0x04` into caller storage and returns normally.
- Current evidence records 30 direct xrefs distributed across nine functions, including repeated use by [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md). That broad render/UI fan-in supports a GrafPort state accessor rather than MapPane or any individual caller owner.
- Historical `SaveClipRegion` was caller-biased: the method does not save `m_clipRegion`, mutate the receiver, install a clip, or imply ownership transfer. It only copies out `m_exposedRegion`. `GetExposedRegion` is descriptive because no original symbol survives; spelling remains a lexical confidence cap.
- This support update adds the source contract to the class inventory without introducing a new by-memory emitter or partial class shell. Current class score `94/95`, UID0000JR owner/emitter, the complete populated CPP/H channels, and unrelated GrafPort source remain unchanged.

[UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) is the tiny adjacent `GrafPort::EnableSoftwareBuffer` setter. It writes `1` to byte field `this + 0x94`, now named `m_usesSoftwareBuffer`, and is not a dirty flag. Constructor, `UpdateRenderRegion`, destructor, paint, and blit evidence show this byte selects the software-buffer path using the buffer pointer at `this + 0x98` and pitch/stride at `this + 0x9c`.

[UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) should be treated as `GrafPort::BlitSurface`, not a MapPane method and not a file-local Surface helper. The destination receiver is the GrafPort in `ecx`, and the first argument is the source GrafPort. B003's 2026-06-18 source-quality pass confirms the method reads `m_ddSurface` at `+0x18`, passes the embedded `EPFTileContext` at `+0x1c` to `dword_69B3E8`, clears `m_surfaceContext.pixelData` at `+0x20` and accepted `m_surfaceContext.rowStridePixels` at `+0x28` after paint/callback paths, borrows/restores `m_alpha` at `+0x90`, and branches on `m_usesSoftwareBuffer` at `+0x94`. The earlier generic `rowStride` token is historical and superseded for source-facing declarations. On DirectDraw-backed destinations, mode `0` maps to `BltFast(..., DDBLTFAST_WAIT)` and mode `1` maps to `BltFast(..., DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY)`; other mode values route through the software sprite callback.

[UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) is routed to this class as `GrafPort::BlitTileContextAt`. Current live TInfo and body evidence prove the third argument is `const EPFTileContext *`, not `FrameDrawRecord *`; its `bounds` member supplies both source and translated destination rectangles. The remaining arguments are typed `DLPalette *`, byte-sized mode, and mutable options pointer. The historical `ForwardToTileFrameBlitHelper` / `FrameDrawRecord` interpretation remains provenance only and is superseded by the exact support type and body.

B010's 2026-07-04 UID000165 split added the earlier paint-helper children to this class. [UID:0004H2][0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo](by-memory/0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo.md) and [UID:0004H3][0x004b98c0-0x004b98ee.GrafPortEndPaint](by-memory/0x004b98c0-0x004b98ee.GrafPortEndPaint.md) manage `m_ddSurface`, `m_surfaceContext.pixelData`, accepted `m_surfaceContext.rowStridePixels`, `m_usesSoftwareBuffer`, `m_softwareBuffer`, and `m_softwarePitchBytes`; older generic `rowStride` wording is historical only. [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md) uses `m_currentX` / `m_currentY` and slot 1 / `g_pfnDrawLineDelta`. [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md) and [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md) use `m_alpha`, source tile context, `g_pPaletteLib`, and slot 2 / `g_pfnBlitSprite`.

[UID:0004H7][0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer](by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md) is now source-ready as `void GrafPort::ScrollPixelBuffer(const RectBounds *scrollRect, int deltaX, int deltaY, Region *dirtyRegion)`. It clears the caller-owned Region, gates on `m_drawEnabled`, clips through `GetClipRect`, uses `m_surfaceContext.pixelData`, `rowStridePixels`, and bounds at `+0x20/+0x28/+0x2c`, then performs overlap-safe 16-bit row copies in four direction quadrants. It clears and unions the newly exposed strips, preserving the observed `deltaX > 0 && deltaY <= 0` lower-strip width-based row clamp and `4 * rectWidth` byte clear. Exactly three callers at `0x0050bea3`, `0x0050da81`, and `0x0055eba6` construct and destroy local Regions and ignore a return value. The B010/Wave2 blank-C++, unresolved-`a5`, FolderTreePane-owner, and `bool`-return conclusions are retained only as superseded historical assumptions.

[UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) is retained source as private `GrafPort::BlitTileContextToSurface(const EPFTileContext *, DLPalette *)`. The body calls virtual `UpdateRenderRegion`, resolves a null palette through `PaletteLib`, reallocates and stores `m_surfaceContext.pixelData`, `rowStridePixels`, and bounds, then dispatches `g_pfnBlitSprite`. Zero surviving inbound xrefs cap historical liveness confidence but do not erase this complete source-shaped GrafPort body.

[UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md) is now a `90/92`, `RECONSTRUCTABLE:FALSE`, non-emitting split/index under this class. Its ten exact source children UIDs 0004LN-0004LW define `ReleaseSurface`, `SetSurfacePixelData`, `SetSurfaceRowStride`, pointer-returning `GetOrigin`, `SetOrigin`, `SetClipRegion`, `GetClipRegion`, `SetClipRect`, `DisableDrawing`, and `EnableDrawing`; nine internal `0xcc` spans remain compiler alignment. Every child is owned/emitted by this class with `Nested:0` and complete formal C++.

The UID0003XB children close the target state model without altering unrelated GrafPort declarations: `m_ddSurface` is at `+0x18`; embedded `EPFTileContext m_surfaceContext` begins at `+0x1c` with `pixelData +0x20`, accepted `rowStridePixels +0x28`, and bounds left/top `+0x2c/+0x30`; receiver-owned `Region m_clipRegion` is at `+0x54`; and `bool m_drawEnabled` is at `+0x71` beside separate draw-mode byte `+0x70`. `SetOrigin` establishes `left=-x` and `top=-y` while preserving extents. Set/Get/SetRect clip methods copy in, copy out, and replace from RectBounds respectively.

Current evidence retains zero inbound routes to raw starts `0x004b94f0/9510/9520/9550` and leaves `0x004b95c0/95d0`, but exact bodies are unique and their complete receiver contracts are source-ready rather than compiler-generated. GetOrigin has three direct calls and returns the output pointer; clip wrappers have `21/12/10` direct calls across FittingRoom, Ranking, WebBoard, Chatting, Layer, MapPane, MenuPane, ScrollablePane, and SystemMessage consumers. Constructor/destructor state and the four-slot vtable confirm these are nonvirtual GrafPort methods. The complete class formal CPP/H channels are populated; exact method definitions correctly remain on their by-memory children and assemble through the class CPP `[[CHILDREN]]` route without a target-only partial declaration.

[UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) is a non-emitting split/container for two exact GrafPort children. [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) emits retained private `GrafPort::BuildEffectiveClipRegion(Region *)`: it composes Region state from `m_exposedRegion` at `this+0x04`, optional `m_clipRegion` at `this+0x54`, and `m_surfaceContext.bounds` at `this+0x2c`, matching the sibling [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) operation while retaining a Region result. Dated 2026-07-03 MCP session `3a33af0b` and PE checks found no function or surviving route to `0x004b9770`; those historical facts cap liveness/original-spelling confidence but do not suppress the complete class-owned body. [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) independently emits `GrafPort::ReleaseBackingStore()` with six direct branch callers; it frees `m_softwareBuffer` at `this+0x98` when `m_usesSoftwareBuffer` at `this+0x94` is set, then releases and clears `m_ddSurface` at `this+0x18` when the `g_pDirectX->m_pDirectDraw` guard is valid. ObjectPane, MapPane, Surface, DirectX, generic cleanup-name, and covered-by alternatives remain rejected; exact original private spelling is the remaining cap.

[UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) is now a class-owned, reconstructable draw-state accessor cluster for cursor movement, font id, and color fields. The physical filename keeps the historical inclusive endpoint `0x004b969f`, while dated 2026-07-05 MCP session `supervisor_recovery_20260705` confirmed the actual half-open range is `0x004b95e0-0x004b96a0`, with successor [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) starting exactly at `0x004b96a0`. The eight no-callee leaf helpers are `GetDrawPosition`, `MoveTo`, `OffsetDrawPosition`, `SetFontId`, `SetDrawColor`, `SetTextBackFillColor`, `SetTextColor`, and `SetTextBackColor`, covering receiver fields `+0x68/+0x6c`, word `+0x8a`, and color fields `+0x74/+0x78/+0x7c/+0x80`. Current generated ownership spread across fitting-room, ranking, collection, and target-option classes is caller-biased and rejected; the methods emit through this class route into the GrafPort source file, while exact public method/member spelling and the `GetDrawPosition` output type remain confidence caps.

[UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) is the source-ready GrafPort palette accessor pair `GetPalette` / `SetPalette`. B004's 2026-07-12 evidence narrows `this+0x84` from the historical opaque brush/palette-handle description to borrowed `DLPalette *m_palette`: the constructor initializes it to null, the destructor does not release it, BalloonObjectPane and ColorStringChattingMessage save/install/restore it around temporary palette mutation, hair/face swatch drawers install slot-14/slot-13 palettes and clear it, and [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) forwards it to the sprite-blit callback. Exact original identifiers and getter `const` remain inferred, but broad caller fan-in rejects feature-class ownership and supports formal C++ through this class route.

[UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) is the class-owned `GrafPort::GetClipRect(RectBounds *outClipRect)` method. B009's 2026-06-25 accepted source-quality pass confirms the exact half-open `0x004b96c0-0x004b9768` function, `0xa8` size, `retn 4` at `0x004b9765`, eight bytes of `0xcc` padding at `0x004b9768-0x004b9770`, and 44 direct code refs. The body copies exposed/dirty Region state `m_exposedRegion` at `this+0x04`, conditionally intersects `m_clipRegion` at `this+0x54`, intersects the result with `m_surfaceContext.bounds` at `this+0x2c` through the `0x005547e0` raw-rect intersection wrapper, and writes the caller output. The formal C++ block is now populated; the old blank-C++/`95/95` gate wording is stale under the current combined-score/emitter rule. Generated `RankingEventListPane::GetClipRect` ownership is caller-biased and rejected; caller fan-in spans nearby GrafPort/surface helpers, software-render callbacks, UI controls, and text callbacks.

[UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) is the class-owned `GrafPort::DrawRectFrame(const RectBounds *rect)` method. B002's 2026-06-18 source-quality pass confirms the `0xeb`-byte body, 49 direct rel32 code references, one explicit argument, `m_drawEnabled` at `this+0x71`, `m_currentX` at `this+0x6c`, `m_currentY` at `this+0x68`, `GetClipRect`/`IntersectRects`/`IsRectEmptyOrInvalid` visibility gating, and four `dword_69B3E4` line-delta callback calls. The clipped rectangle is only an accept/reject gate; the frame is drawn from the original caller rectangle, and stale `RankingEventListPane` / Surface ownership is rejected.

[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) routes to this class as `GrafPort::CompositePixels(const RectBounds *rect)`. B003's 2026-06-18 recheck confirms the function is a `ret 4` thiscall method with one rectangle argument, three direct callers from BowGaugeObjectPane and TextEditPane, and no pointer-table or Surface callback route. The body gates on `m_drawEnabled` at `+0x71`, clips the rectangle through `GrafPort::GetClipRect`, writes the embedded `EPFTileContext` pixel buffer at `+0x20` using row stride `+0x28` and bounds `+0x2c/+0x30`, maps the `SetBkColor`/background-color field at `+0x7c` through `PaletteLib::GetCurrentPalette` and `DLPalette::MapColor`, and then fills zero 16-bit pixels with that color while bitwise-inverting nonzero pixels. BowGaugeObjectPane and TextEditPane are consumers only.

[UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) is now source-routed to this class as `GrafPort::DrawTiledBackground`. It saves and replaces `m_clipRegion` at `this+0x54`, reads `m_visibleBounds` at `this+0x44..+0x50`, forwards `m_drawMode` / possible `m_blitMode` at `this+0x70` to slot-2 callback `dword_69B3E8`, depends on `m_alpha` at `this+0x90` as callback-visible receiver state, resolves palettes through `g_pPaletteLib`, and repeatedly blits a `FrameDrawRecord` source rectangle at record offset `+0x10`. Current generated ownership under `RankingEventListPane` is caller-biased.

2026-06-17 WaterFilterEffecter support evidence: [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) sets GrafPort byte `+0x70` to draw mode `2`, calls [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), then restores mode `0`; it also saves/restores scalar `+0x90` as current draw alpha. This supports naming `+0x70` as a draw/blit mode byte and `+0x90` as an alpha/opacity scalar in Pane/GrafPort-derived views.

[UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) is the shared text fit/suffix pair for `GrafPort` text layout. Live A001 evidence confirms the first helper uses the receiver to measure destination/suffix text and append a truncation suffix, while the second helper reads receiver font/style offset `+0x8a`, walks a [UID:0000E7][StringIter](by-class/StringIter.md), and asks [UID:0000JH][FontImageLib](by-file/FontImageLib.md) for glyph advances. Caller fan-in spans clan/item lists, UI controls, wrapped text drawing, and later text paths, so this pair is class-owned shared render text infrastructure rather than clan-item-list code.

[UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) is class-owned GrafPort text-run code rather than a direct file-bucket item. Current source quality resolves the counted and null-terminated `GetTextWidth` overloads, `GetLineHeight`, non-static `AdjustVisibleCountForTrailingWhitespace`, `DrawGlyphWithTextColors`, `DrawWideText`, and `DrawOutlinedText`. The former static/local helper classification is retained only as historical provenance and is superseded by four independent TextEditPane `ECX` receiver calls. The pass also corrects text color fields to `m_textColor` at `this+0x7c` and `m_textBackColor` at `this+0x80`, names `this+0x88` as text draw/background mode rather than a dirty byte, keeps `g_pFontImageLib` as the FontImageLib dependency, and emits formal C++ through `NexusTK/render/GrafPort.cpp`. [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) is the glyph-draw dependency called by the text-run helpers; B002's 2026-06-26 implementation populates its first-draft formal C++ with FontImageLib decode/metric calls, optional fill/invalidation, draw-mode mapping, the `m_palette` callback argument now typed by UID000163, and final cursor advance.

[UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) is retained GrafPort.cpp file-static source as `PackTwoColorSixPixelPattern`. File UID0000JR remains its canonical owner; this class UID00005V is only its assembler emitter, placing the definition after class child UID0003XE and before class child UID00016I. Exact bytes prove the 33-byte `retn 0x0c` body, and `DrawGlyphWithTextColors` / `DrawWideText` independently inline the identical six-byte `{background, foreground, background, foreground, foreground, background}` pattern. No class field is accessed, so file-static placement is stronger than a member method; zero surviving inbound routes cap lexical/liveness confidence only.

[UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) is the adjacent wrapped-rect method. [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md) is now a non-emitting mixed physical index, not a class method. Its source-bearing GrafPort methods are exact children [UID:0004NH][0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect](by-memory/0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect.md) and [UID:0004NI][0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect](by-memory/0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect.md).

[UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) remains emitted through `SystemMessagePanes` today, but it is a future shared text-measure reconciliation candidate in this GrafPort/text-helper neighborhood. B006 2026-06-21 confirms [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) forwards a pane/draw-context receiver in `ecx` and passes `m_text`, UTF-16 length, and width to the helper at call sites `0x00483658` and `0x0048368c`; the helper itself still has no GrafPort state access and returns constant `1`, so this note is not an ownership move or proof of a class method.

### UID00016E Rect Text-Effect Method Surface

- `void DrawOutlinedText(const wchar_t *text, int length, const RectBounds *rect)` is represented by UID0004NH at exact `[0x004bafa0,0x004bb06a)`. The 202-byte/75-instruction one-block method has SHA-256 `C29B61F52A23EC3AB6F240E9072238F82411A1A9BB3B35C31537CB918BD53D69`, saves `m_textColor` at `+0x7c`, installs `m_textBackColor` at `+0x80`, draws original-relative left/right/top/bottom rectangles through `DrawTextInRect`, restores primary color, then draws center.
- `void DrawShadowedText(const wchar_t *text, int length, const RectBounds *rect)` is represented by UID0004NI at exact `[0x004bb080,0x004bb0db)`. The 91-byte/39-instruction one-block method has SHA-256 `112A989B555D30F32D5E4A47C27D256E858048152CF3534B58D8F8DCE364BAF5`, copies/offsets the rectangle by `(1,0)`, draws original first and shifted copy second, and has no explicit color swap.
- Both are nonvirtual `thiscall` GrafPort members with receiver in `ecx`, three stack arguments, `retn 0x0c`, source `void`, a copied 16-byte RectBounds, calls to `RectBounds::Offset` and UID00016D, and compiler-only security-cookie lowering. The full-width integer length and const rectangle match UID00016D and all current callers.
- Exact direct callers are five outlined sites `0x00482f37/0x00483727/0x004837d7/0x0049a3c9/0x004c6919` and two shadowed sites `0x0049a3a7/0x004c68f7`. ChattingColorSelectPane, ColorStringChattingMessage, StaticText2, and HelpPane are inherited GrafPort consumers, not owners.
- No data/vtable/table/pointer route, extra caller, branch/table/EH behavior, or persistent shadow-method state mutation exists. File-local/static, compiler-artifact, Surface, RectBounds, and feature-private ownership are rejected.
- UID00016F remains separately SystemMessagePanes-owned because its constant callback has no GrafPort state. Six/eight-byte internal alignment and five/fifteen-byte successor alignment receive no source. UID0003ZP remains SoftwareBlend16-owned and only closes address-sort nesting.
- `DrawOutlinedText` and `DrawShadowedText` are best-current project-consistent spellings, but original symbols/access visibility are not recovered. This lexical cap explains child scores below 95 and does not block exact signatures or method definitions.
- The complete class formal CPP/H channels are populated. No target-only partial declaration is added; exact UID0004NH/UID0004NI definitions emit through the class CPP child route and their declarations appear once in the complete header.

### UID0002YK RGB565 Fill Callback State

[UID:0002YK][0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback](by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md) is an exact static Surface callback consumer of GrafPort state, not a GrafPort method. The callback uses embedded `void *m_surfaceContext.pixelData` at `+0x20`, logical-pixel `int m_surfaceContext.rowStridePixels` at `+0x28`, and `m_surfaceContext.bounds` left/top at `+0x2c/+0x30`. Compile-valid source first takes an `unsigned char *` byte view of `pixelData`, applies the exact doubled pixel offset, then converts the resulting address to `unsigned short *`; arithmetic on `void *` and the historical generic `rowStride` alias are rejected.

The same callback consumes `m_drawMode` at `+0x70`, `m_drawEnabled` at `+0x71`, canonical primary `m_drawColor` at `+0x74`, canonical `m_textBackFillColor` at `+0x78` (historically described there as `m_secondaryDrawColor`), borrowed `DLPalette *m_palette` at `+0x84`, accepted `m_alpha` at `+0x90`, and `m_usesSoftwareBuffer` at `+0x94`. It maps both colors even though the secondary result is discarded, then forces the mapped RGB565 fill pixel to value `1` when software backing is active and the primary palette index is `128`; index `128` is the trigger, not the resulting pixel value. It uses `m_alpha` as the blend helpers' first-argument weight. Because that first argument is the existing destination pixel, weight `0` selects the fill color while weight `32` preserves the destination. The direct-fill paths process the odd tail before packed pairs, and the mode-3 odd-width path intentionally preserves the observed pair-plus-extra-pixel overrun.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EnableSoftwareBuffer` | `0x004b8be0-0x004b8be8` | Sets `m_usesSoftwareBuffer` so subsequent render-region updates use owned heap backing instead of DirectDraw surface allocation. |
| `GrafPort::GrafPort` | `0x004b8bf0-0x004b8d17` | Initializes base state, regions, defaults, and null backing storage. |
| `UpdateRenderRegion` | `0x004b8e20-0x004b94e1` | Updates bounds/dirty state and creates or resizes DirectDraw/software backing storage. |
| `ReleaseSurface` | `0x004b94f0-0x004b9509` | Conditionally releases and clears per-port `m_ddSurface` without the DirectX-global guard or software-buffer cleanup of ReleaseBackingStore; exact child [UID:0004LN][0x004b94f0-0x004b9509.GrafPortReleaseSurface](by-memory/0x004b94f0-0x004b9509.GrafPortReleaseSurface.md). |
| `SetSurfacePixelData` | `0x004b9510-0x004b951d` | Stores a borrowed `void *` in `m_surfaceContext.pixelData`; exact child [UID:0004LO][0x004b9510-0x004b951d.GrafPortSetSurfacePixelData](by-memory/0x004b9510-0x004b951d.GrafPortSetSurfacePixelData.md). |
| `SetSurfaceRowStride` | `0x004b9520-0x004b952d` | Stores logical `rowStridePixels` in the embedded surface context, not byte pitch; exact child [UID:0004LP][0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride](by-memory/0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride.md). |
| `GetOrigin` | `0x004b9530-0x004b9545` | Copies bounds left/top to Point x/y and returns the caller's output pointer; exact child [UID:0004LQ][0x004b9530-0x004b9545.GrafPortGetOrigin](by-memory/0x004b9530-0x004b9545.GrafPortGetOrigin.md). |
| `SetOrigin` | `0x004b9550-0x004b9574` | Offsets embedded bounds to absolute `left=-x`, `top=-y` while preserving width/height; exact child [UID:0004LR][0x004b9550-0x004b9574.GrafPortSetOrigin](by-memory/0x004b9550-0x004b9574.GrafPortSetOrigin.md). |
| `SetClipRegion` | `0x004b9580-0x004b958c` | Copies caller Region into `m_clipRegion`; exact child [UID:0004LS][0x004b9580-0x004b958c.GrafPortSetClipRegion](by-memory/0x004b9580-0x004b958c.GrafPortSetClipRegion.md) records 21 calls. |
| `GetClipRegion` | `0x004b9590-0x004b95a3` | Copies `m_clipRegion` into caller output; exact child [UID:0004LT][0x004b9590-0x004b95a3.GrafPortGetClipRegion](by-memory/0x004b9590-0x004b95a3.GrafPortGetClipRegion.md) records 12 calls. |
| `SetClipRect` | `0x004b95b0-0x004b95bc` | Replaces `m_clipRegion` from caller RectBounds through Region SetRect; exact child [UID:0004LU][0x004b95b0-0x004b95bc.GrafPortSetClipRect](by-memory/0x004b95b0-0x004b95bc.GrafPortSetClipRect.md) records ten calls. |
| `DisableDrawing` | `0x004b95c0-0x004b95c5` | Writes false to `m_drawEnabled` without changing draw mode; exact child [UID:0004LV][0x004b95c0-0x004b95c5.GrafPortDisableDrawing](by-memory/0x004b95c0-0x004b95c5.GrafPortDisableDrawing.md). |
| `EnableDrawing` | `0x004b95d0-0x004b95d5` | Writes true to `m_drawEnabled`, matching constructor-enabled default; exact child [UID:0004LW][0x004b95d0-0x004b95d5.GrafPortEnableDrawing](by-memory/0x004b95d0-0x004b95d5.GrafPortEnableDrawing.md). |
| `ReleaseBackingStore` | `0x004b97d0-0x004b981e` | Releases per-GrafPort backing storage by freeing the owned software buffer and releasing the retained DirectDraw surface; exact child [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) carries formal C++. |
| `UpdateSurfaceInfo` | `0x004b9820-0x004b98b8` | Opens the current software or DirectDraw-backed surface for drawing and writes `m_surfaceContext.pixelData` / `rowStridePixels`; exact child [UID:0004H2][0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo](by-memory/0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo.md) carries formal C++. Historical generic `rowStride` wording is superseded. |
| `EndPaint` | `0x004b98c0-0x004b98ee` | Unlocks `m_ddSurface` when DirectDraw-backed and clears active surface-context pixel/stride fields; exact child [UID:0004H3][0x004b98c0-0x004b98ee.GrafPortEndPaint](by-memory/0x004b98c0-0x004b98ee.GrafPortEndPaint.md) carries formal C++. |
| `LineTo` | `0x004b98f0-0x004b990c` | Exact `void GrafPort::LineTo(int x, int y)` converts an absolute endpoint to signed `m_currentX`/`m_currentY` deltas and tail-dispatches slot 1 / `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta`; exact child [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md) carries formal C++. Historical `int` return source is superseded. |
| `DrawSprite` | `0x004b9910-0x004b997e` | Temporarily borrows source alpha and dispatches a source tile context through slot 2 / `g_pfnBlitSprite`; exact child [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md) carries formal C++ with exact spelling still inferred. |
| `RenderTileFrame` | `0x004b9980-0x004b99b1` | Resolves a palette name through `g_pPaletteLib` and forwards a tile/frame source through slot 2 / `g_pfnBlitSprite`; exact child [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md) carries formal C++. |
| `BlitTileContextAt` | `0x004b99f0-0x004b9a63` | Translates an `EPFTileContext::bounds` rectangle by destination x/y and forwards the exact source context, palette, mode, and options through `g_pfnBlitSprite`; UID000166 carries formal C++. |
| `ScrollPixelBuffer` | `0x004b9a70-0x004ba24a` | Source-ready `void GrafPort::ScrollPixelBuffer(const RectBounds *, int, int, Region *)`; clips the requested area, copies overlapping 16-bit rows in direction-safe order, clears exposed strips, and unions them into the caller-owned Region. Exact child [UID:0004H7][0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer](by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md) carries the complete formal definition. |
| `BlitSurface` | `0x004ba250-0x004ba444` | Blits from a source GrafPort to this GrafPort, using DirectDraw `BltFast` for modes `0`/`1` when the destination is DirectDraw-backed and using the `dword_69B3E8` software sprite callback otherwise. |
| `DrawRectFrame` | `0x004ba450-0x004ba53b` | Draws a rectangle frame through `dword_69B3E4` line-delta callbacks after a clip/intersection visibility test; saves/restores `m_currentX`/`m_currentY`. |
| `CompositePixels` | `0x004ba540-0x004ba6ad` | Applies a clipped 16-bit selection/highlight composite: zero pixels receive the current background palette color, and nonzero pixels are bitwise inverted. |
| `DrawTiledBackground` | `0x004ba6b0-0x004ba81d` | Tiles a `FrameDrawRecord` source rectangle across `m_visibleBounds` through `dword_69B3E8`, with a temporary `m_clipRegion` replacement, named-palette lookup, and `m_drawMode`/`m_alpha` callback-state dependencies. |
| `AdjustVisibleCountForTrailingWhitespace` | `0x004baad0-0x004bab11` | Public non-static member with source signature `unsigned short (const wchar_t *text, short count)`. It scans backward over space, tab, and carriage return and preserves the shipped count-versus-last-index comparison. TextEditPane calls it at `0x00593c72`, `0x00593d38`, `0x00593ed4`, and `0x00594019` with the inherited receiver in `ECX`. |
| `DrawTextInRect` | `0x004bad70-0x004baf92` | Draws wrapped UTF-16 text inside a rectangle using GrafPort cursor, font, color, and alignment state. |
| UID00016E physical index | `0x004bafa0-0x004bb0db` | Non-emitting mixed range over two exact GrafPort methods, independent UID00016F, and alignment; not a class declaration/body. |
| `DrawOutlinedText(const wchar_t *, int, const RectBounds *)` | `0x004bafa0-0x004bb06a` | Four secondary-color cardinal `DrawTextInRect` passes, restored primary-color center pass; exact child UID0004NH. |
| `DrawShadowedText(const wchar_t *, int, const RectBounds *)` | `0x004bb080-0x004bb0db` | Original-first then `(1,0)` duplicate-offset `DrawTextInRect` pass with no explicit color swap; exact child UID0004NI. |
| scalar deleting destructor | `0x004bb7e0-0x004bb8c4` | Compiler wrapper over the ordinary destructor and optional `operator delete`; no handwritten method body is emitted. |

## Evidence Notes

- UID0003XB current implementation evidence: exact child body hashes and all call addresses live on UIDs 0004LN-0004LW; the parent records the 229-byte range hash and every internal pad. Evidence-time MCP `supervisor_nexustk_20260713` plus independent PE scans found no pointer/table/vtable/branch route to six retained leaves, unique full bodies, and no duplicate ownership candidate. Historical `ReleasePrimarySurface`, `SetSurfaceStatePointer`, `SetSurfaceStateStride`, `GetViewOrigin`, `OffsetViewOrigin`, and blanket blank-C++ assumptions are superseded. Surface and DirectX remain dependencies; feature classes remain consumers.
- Wave3 imports the class with three included methods and high grades.
- IDA MCP reports six constructor callers, with call sites in pane/render object constructors.
- IDA MCP reports fifteen direct callers of `UpdateRenderRegion`, spanning pane, screen, map, and render update code.
- `UpdateRenderRegion` reads `g_pDirectX` and calls the DirectDraw `CreateSurface` slot in the hardware-surface path.
- A 2026-05-26 IDA MCP recheck resolves the generated `g_maxSurfacePitch` reference in `UpdateRenderRegion` to `word_66DA94` / [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), not to a separate GrafPort-owned pitch global.
- 2026-06-13 A003 live IDA MCP review established the exact half-open `0x004b96a0-0x004b96c0` two-leaf shape for [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md): a two-instruction load from `[ecx+84h]`, nine-byte `0xcc` alignment, and one-argument store to `[ecx+84h]`. Its provisional `GetBrushHandle` / `SetBrushHandle` labels are retained as historical aliases; B004's 2026-07-12 type/lifetime pass supersedes them with inferred `GetPalette` / `SetPalette` and borrowed `DLPalette *m_palette`, with source setter return `void` rather than incidental EAX assignment residue.
- Historical 2026-06-08 A004 Batch 119 review confirmed [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) is a 130-caller `__thiscall` wrapped renderer that saves/restores GrafPort cursor fields at `+0x68/+0x6c`, checks enabled byte `+0x71`, uses font/style field `+0x8a`, selects alignment from `+0x8c`, and delegates fit/run/glyph work to adjacent GrafPort text helpers. Its broad UID00016E owner claim is superseded only at parent level: current exact children UID0004NH/UID0004NI carry the two GrafPort methods, while the parent is mixed/non-emitting and UID00016F remains independent.
- 2026-08-22 B003 verified `0x004baad0` as a GrafPort member from exact callee and caller ABI: the helper consumes `const wchar_t *` plus signed-short count, returns an unsigned low word, executes `retn 8`, and lies in the contiguous GrafPort text-method corridor after `GetLineHeight`. All four callers deliberately establish a TextEditPane/GrafPort receiver in `ECX`; the two cdecl callbacks use `pane->...`, and the two raw members use their own receiver. One public declaration after `GetLineHeight` therefore closes valid cross-unit linkage without adding state or a virtual slot.

## UID000161 Inherited Bounds Accessor - 2026-07-15

- [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) is the exact inherited `GrafPort::GetBounds` definition. The source declaration required in the complete GrafPort header union is `RectBounds *GetBounds(RectBounds *outBounds) const;`; the exact out-of-line body emits from UID000161 in `NexusTK/render/GrafPort.cpp`.
- The 17-byte leaf copies the accepted 16-byte `m_visibleBounds` rectangle at `this+0x44` to the caller output and returns that same pointer. It has no callees, branches, EH, strings, internal split, pointer/table route, or compiler-wrapper role; exact leading/trailing padding separates it from neighboring GrafPort methods.
- Receiver and ownership proof is broader than caller naming. UID0003TC directly calls the method on a newly constructed `HitBarObjectPane`; BackPane paint/help and broad UI/map/render paths also call it. Those classes share GrafPort ancestry, while HitBarObjectPane does not derive from BackPane. The surrounding function island and accepted `m_visibleBounds` field independently support GrafPort ownership.
- UID000161 has 103 direct calls and no raw target VA/RVA/raw-offset/end-address pointer hits. Broad call fan-in proves inherited utility, not BackPane ownership. The exact owner/emitter are this class and [UID:0000JR][GrafPort](by-file/GrafPort.md).
- Rejected alternatives: historical BackPane ownership cannot explain the HitBar receiver and would duplicate one body; Pane ownership is less specific than the accepted GrafPort field/island; a free helper conflicts with the `ECX` receiver and `ret 4` member ABI.
- Historical B003 bytes, ABI, padding, return-pointer, and caller inventory remain accepted. Only its `BackPane::GetBounds`/`Pane::m_bounds` owner-member inference is superseded by `GrafPort::GetBounds`/`m_visibleBounds`.
- Current class score/formal state is `94/95` with the complete CPP preamble and complete H declaration populated. This exact child and prose contract remain source-safe because its definition emits from UID000161 while its declaration appears once in the full GrafPort header; no target-only partial shell is introduced.

## Exact Layout

The formal header models a naturally aligned `0xa0`-byte class. The established source members are:

| Offset | Source field | Type / role |
| --- | --- | --- |
| `+0x00` | inherited `LObject` state | polymorphic base/vptr |
| `+0x04` | `m_exposedRegion` | `Region`, size `0x14` |
| `+0x18` | `m_ddSurface` | retained `IDirectDrawSurface *` |
| `+0x1c` | `m_surfaceContext` | embedded `EPFTileContext`, size `0x28` |
| `+0x44` | `m_visibleBounds` | `RectBounds` |
| `+0x54` | `m_clipRegion` | `Region`, size `0x14` |
| `+0x68/+0x6c` | `m_currentY`, `m_currentX` | draw cursor coordinates |
| `+0x70/+0x71` | `m_drawMode`, `m_drawEnabled` | callback mode and drawing gate |
| `+0x74/+0x78` | `m_drawColor`, `m_textBackFillColor` | primary and background-fill palette indices |
| `+0x7c/+0x80` | `m_textColor`, `m_textBackColor` | text foreground/background indices |
| `+0x84` | `m_palette` | borrowed `DLPalette *` |
| `+0x88` | `m_textDrawMode` | text callback mode; compiler aligns next word at `+0x8a` |
| `+0x8a/+0x8c` | `m_fontId`, `m_textAlign` | font selector and alignment |
| `+0x90` | `m_alpha` | callback-visible opacity |
| `+0x94` | `m_usesSoftwareBuffer` | backing-store selector; compiler aligns next pointer at `+0x98` |
| `+0x98/+0x9c` | `m_softwareBuffer`, `m_softwarePitchBytes` | owned software backing and byte pitch |

The constructor writes through `+0x9c`, embedded GrafPort consumers place their next field exactly `0xa0` bytes later, and the complete header retains `GrafPortSizeMustBe160`. Compiler padding at `+0x72..+0x73`, `+0x89`, and `+0x95..+0x97` is not represented as authored semantic fields.

The exact source layout and current IDA UDT are deliberately separate representations. Formal `GrafPort.h` carries the complete source fields and natural alignment above. Current IDA verification preserves the existing `GrafPort` UDT at size `0xa0` with 23 members, including `_grafPortBase`, `_state54`, `_state72`, `_alignment89`, and `_alignment95`; no `declare_type`, `set_type`, member rename, split, replacement, or alignment-member action is part of the accepted conclusion.

## Complete Method Surface

- The class declaration now exposes all 55 out-of-line source-authored methods plus inline `SetDrawMode` and `SetTextDrawMode`.
- Newly closed declarations are `GetExposedRegion`, `GetSurfaceContext`, private `BuildEffectiveClipRegion`, and private `BlitTileContextToSurface`.
- UID000166 is declared as `BlitTileContextAt` over `const EPFTileContext *` and `DLPalette *`; stale `FrameDrawRecord`/`void *` aliases are historical only.
- The source preamble includes all complete dependencies used by child definitions while the header retains forward declarations for pointer-only types.

## Compiler Products

- The locator and four-slot vtable at `0x0061a8a4-0x0061a8b8` are generated from this declaration and must not be emitted as a handwritten table.
- The scalar deleting destructor at `0x004bb7e0-0x004bb8c4` is compiler-generated dispatch/delete glue. The ordinary destructor page emits the handwritten cleanup; no second source body is appropriate.
- Alignment, RTTI framing, cookie checks, register spills, and decompiler temporaries remain compiler products rather than source declarations.

## Open Questions

- Exact original private spellings for `BuildEffectiveClipRegion`, `BlitTileContextToSurface`, and file-static `PackTwoColorSixPixelPattern` are not recoverable from symbols. Their chosen names are the strongest project-consistent human source names supported by exact behavior and sibling vocabulary.
- No behavior, ownership, ABI, class-layout, source-placement, or output-route question remains open. Zero surviving inbound routes to three raw retained bodies are documented evidence, not a reason to omit their complete source.

## Score Rationale

- Completion is `94`: the exact `0xa0` layout, full 55-method out-of-line surface, two inline setters, four formerly missing declarations, private retained helpers, typed dependencies, compiler products, and source route are all documented and present in formal H/CPP channels.
- Confidence is `95`: body, field-offset, vtable, caller, type-layout, and sibling source-family evidence agree on behavior and placement. Only original private lexical spellings remain inferred; no IDA-style labels leak into final source.

## Cross-References

- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- [UID:000560][0x004b8bf0-0x004b8d17.GrafPortConstructor](by-memory/0x004b8bf0-0x004b8d17.GrafPortConstructor.md)
- [UID:000561][0x004b8d20-0x004b8dc3.GrafPortDestructor](by-memory/0x004b8d20-0x004b8dc3.GrafPortDestructor.md)
- [UID:000562][0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion](by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md)
- [UID:000563][0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext](by-memory/0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext.md)
- [UID:000564][0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion](by-memory/0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion.md)
- [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md)
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
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md)
- [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)
- [UID:0004NH][0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect](by-memory/0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect.md)
- [UID:0004NI][0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect](by-memory/0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect.md)
- [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md)
- [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)

## UID0002YF Slot-7 Callback Field-Use Evidence - 2026-08-04

[UID:0002YF][0x004be680-0x004bed67.SoftwareRenderCompatFillCallback](by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md) is a Surface-owned file-local callback whose receiver is a `GrafPort *`. It strengthens the following class-layout and behavior contracts without making the callback a GrafPort member or vtable method:

- `m_drawMode` at `+0x70` selects four exact rectangle-fill operations: copy, raw-color-keyed copy, weighted RGB555 blend, and raw-color-keyed weighted blend. Unknown mode values return without writing.
- `m_drawEnabled` at `+0x71` is the top-level early-return guard. `m_drawColor` at `+0x74` supplies the primary palette index and is also tested as the raw zero key in modes 1 and 3. `m_textBackFillColor` supplies a second palette-map call whose result is discarded but whose call remains part of observable behavior.
- `m_usesSoftwareBuffer` selects the raw-color-128 compatibility override: after palette mapping, `m_drawColor == 128` becomes RGB555 pixel value `1` only for the software buffer.
- `m_alpha` at `+0x90` is converted with `static_cast<unsigned char>(static_cast<int>(m_alpha * 32.0f + 0.5f))`; the wrapped byte is the destination weight passed to `BlendRgb555(destination, fill, destinationWeight)`.
- Embedded `m_surfaceContext.pixelData`, `rowStridePixels`, and `bounds` supply the 16-bit destination address. After clipping, the first pixel is `pixelData + clipped.left + rowStridePixels * (clipped.top - bounds.top) - bounds.left`, and each output row advances by `rowStridePixels`.
- The receiver provides clipping through `GetClipRect`; the body then uses `IntersectRects` and `IsRectEmptyOrInvalid`. Color mapping intentionally uses `g_pPaletteLib->GetCurrentPalette()` and does not read GrafPort's `m_palette`, so member-palette fallback from the RGB565 peer must not be generalized to this callback.

## UID0002TG Scaled-RLE Tint Receiver Dependency

[UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md) consumes a `GrafPort *` receiver but remains a file-local Surface callback, not a GrafPort method.

- It reads `m_drawEnabled` at receiver `+0x71` for the initial early-return gate and calls `GetClipRect(RectBounds *)` before projection and the `mode == 3` branch.
- Destination addressing is read-only against the embedded `m_surfaceContext`: `pixelData` at receiver `+0x20`, logical-pixel `rowStridePixels` at `+0x28`, and bounds origin at `+0x2c/+0x30`.
- The initial pointer applies bounds-origin subtraction, while later row recomputation uses destination X plus destination Y times `rowStridePixels` without that subtraction. The callback documentation preserves this observed asymmetry rather than normalizing it.
- The body transforms existing destination RGB565 pixels for negative encoded-mask spans. It does not modify GrafPort ownership/state declarations, read `m_palette`, or use GrafPort draw colors for source intensity.
- GrafPort owns only the receiver layout and `GetClipRect` dependency. Semantic UID0000TN owns the callback type/global, Surface UID0000OC owns both provider families, and exact UID0002TG owns the RGB565 body. No class metadata or formal class block change is justified.
- Exact target-specific provider/table evidence keeps ownership on [UID:0000OC][Surface](by-file/Surface.md): `SoftwareRenderRgb565ScaledRleTintCallback` at `0x004c3a50` is selected for slot 4 / `g_pfnBlitScaledRleTint` at retained assignment `0x00558829` and inline assignment `0x00558ec4`; the shared slot at `0x0069b3f0` has twenty-one dispatch/setup references, while the provider has no direct code callers. No GrafPort method, vtable, or address-taking route exists. This is class-state usage evidence only; GrafPort metadata and formal C++/H remain unchanged.

## Changes

### Current Whole-File Closure

- 2026-08-23 B007 UID0003XF Gate 2A source-order repair:
  - Preserved file UID0000JR ownership, `91/92`, the blank optional-position field, the exact file-static formal body, and all liveness/source-family evidence.
  - Replaced only the rejected direct-file emitter with this class assembler route. Generated command `000000027223` physically proved `UID0003XE -> UID0003XF -> UID00016I`, with one UID0003XF body and no class-member conversion.
- 2026-08-22 B007 UID0000JR whole-file callback:
  - Raised the class from `89/92` to `94/95` and installed the complete exact formal header plus complete GrafPort.cpp dependency preamble.
  - Added UID000560-UID000564, the complete 55-method out-of-line surface, exact `0xa0` layout, compiler-product dispositions, and resolved-question closure.
  - Superseded UID000166 `FrameDrawRecord`/opaque-palette declarations, UID0003XE blank-source policy, and UID0003XF no-owner policy while retaining those historical assumptions as provenance.

### Historical And Superseded Provenance

The entries below predate or are narrower than the UID0000JR complete `94/95` CPP/H closure. Their then-current score and blank-formal statements are retained only as dated provenance and do not control active class state.

- 2026-08-22 B010 UID0000M3 Gate 2A support repair: corrected ObjectImage paint attribution so base `ObjectImageControlPane::OnPaint` owns `SetDrawColor(0)`, while button `ObjectImageButtonPane::OnPaint` owns the highlight-frame `RenderTileFrame` path and performs no `SetDrawColor` call.
- 2026-08-22 B003 UID0003FC support implementation: raised `88/90` to `89/92`, added the one canonical public `AdjustVisibleCountForTrailingWhitespace(const wchar_t *, short)` declaration after `GetLineHeight`, reclassified the helper from historical static/local wording to a non-static receiver-independent member, and recorded its four TextEditPane receiver routes, exact ABI, source ownership, and shipped comparison without changing layout, vtable, or unrelated methods.
- 2026-08-14 B010 UID0002GH support implementation:
  - Preserved `88/90`, UID0000JR owner/emitter, complete `0xa0` layout, formal CPP child route, all existing methods, and every unrelated render dependency.
  - Added exact public inline `SetDrawMode` and `SetTextDrawMode` declarations over established one-byte fields plus target-specific consumer/source-ownership evidence.

- 2026-08-11 B008 UID0002TG receiver support:
  - Kept class metadata/formal output unchanged at `88/90`, owner/emitter UID0000JR.
  - Added the target-specific read-only `m_drawEnabled`, `m_surfaceContext.pixelData`, `rowStridePixels`, bounds-origin, and `GetClipRect` dependency while explicitly retaining Surface ownership of the callback body.
  - Gate 2A repair removed an unrelated slot-7 fill-provider paragraph from the UID0002TG section and replaced it with exact slot-4 provider, assignment, and twenty-one-reference evidence.

- 2026-07-28 B002 UID0002TE support sync: recorded the exact slot-6 callback receiver fields, `0xa0` class / `0x28` EPFTileContext layout dependency, canonical stride/background-field spellings, packed-mask contract, provider-specific blend helpers, and external Surface ownership; preserved `88/90`, owner/emitter route, and blank whole-class formals.

- 2026-07-24 B005 UID00019W bounded layout synchronization:
  - Preserved class score/owner/emitter/formal state and every unrelated GrafPort method/dependency fact.
  - Historicalized the accepted-at-the-time `0x88` total-size statement, documented the exact `+0x88..+0xa0` tail members/alignment, and added independent constructor/member-spacing proof from the generic/made-by scrolled-text classes.
  - At that date the update deferred exact UDT application/readback to supervisor Gate 2B. The later UID0000JR conclusion supersedes that proposal: current IDA handling is read-only verification of the unchanged `0xa0`, 23-member UDT, with no UDT application.

- 2026-07-24 B003 UID0002TF slot-3 field synchronization:
  - Preserved `88/90`, UID0000JR owner/emitter, blank whole-class formal, complete GrafPort method/state history, and all concurrent UID0002PJ/UID0004H7 detail.
  - Canonicalized `+0x74 m_drawColor` and `+0x78 m_textBackFillColor` for slot-3 RLE callbacks, retained `m_secondaryDrawColor` only as a historical callback alias, and documented surface-context, clip, palette-argument, and nonmember callback use.
  - At that date the synchronization left IDA UDT/type mutation to supervisor Gate 2B and did not duplicate either Surface callback body in GrafPort. The later UID0000JR no-change conclusion supersedes the mutation proposal while preserving the callback evidence.

- 2026-07-24 B002 UID0002PJ GrafPort support synchronization:
  - Preserved class score `88/90`, UID0000JR owner/emitter, blank whole-class formal, all unrelated fields/methods, and existing class history.
  - Added the exact slot-1 void callback coupling and accepted `+0x68..+0x84` cursor/draw-color field map; corrected only LineTo's stale return presentation and kept the Surface callback body on its exact child.

- 2026-07-14 B005 UID00037V support synchronization:
  - Added the `0x004b8dd0-0x004b8de3` `GetExposedRegion(Region *out) const` copy-out contract, exact 19-byte/one-block body, 30 xrefs across nine functions, UID0004QY consumer, and rejection of historical caller-biased `SaveClipRegion` naming.
  - Preserved class score, owner/emitter, blank formal, and all unrelated GrafPort content.
- 2026-07-14 B005 UID00016E implementation synchronization:
  - Class score, UID0000JR owner/emitter route, reconstructable state, and intentionally blank whole-class formal block remain unchanged at `88/90`.
  - Reclassified UID00016E as a mixed non-emitting index and added exact rect overloads UID0004NH/UID0004NI with complete signatures, ranges/hashes/instruction counts, state/offset/draw order, seven callers, callees, compiler/source distinction, ownership rejections, padding/nesting exclusions, and lexical caps.
  - Preserved UID00016F's independent SystemMessagePanes route and all unrelated GrafPort class content.
- 2026-07-13 B001 UID0004H7 implementation callback:
  - Class score, owner/emitter metadata, and intentionally blank whole-class formal block remain unchanged at `88/90`; no unrelated declaration or sibling was changed.
  - Replaced the historical pending-helper/no-code description with the resolved `void` signature, borrowed RectBounds and caller-owned Region contract, exact receiver fields, four direction quadrants, anomalous clear, three callers, and source-ready child route.
  - Historicalized the B010/Wave2 unresolved-`a5`, FolderTreePane, `bool`, and blank-C++ assumptions without removing their provenance.
- 2026-07-13 B002 UID0002YK implementation callback support sync:
  - Class score, owner/emitter metadata, blank class formal block, and unrelated children remain unchanged.
  - Added exact target-specific GrafPort field/type use, compile-valid `void *` byte-to-pixel address routing, both palette mappings, software-buffer color-128 override, direct-fill odd-tail order, destination-weight semantics, and the observed mode-3 odd-width overrun.
  - Replaced current source-facing generic `rowStride` uses with accepted `rowStridePixels`; retained the old token only as explicitly historical provenance.
- 2026-07-13 B004 UID0003XB implementation synchronization:
  - Score `88/90`, class owner/emitter metadata, blank class formal block, and unrelated method content remain unchanged.
  - Replaced target-specific blank-until-entry policy with exact UIDs 0004LN-0004LW, accepted fields, complete method contracts, zero-route retained-source rationale, caller totals/families, lifecycle/vtable evidence, dependency/feature-owner rejections, and historical aliases.
  - Added all ten Method Notes and links. A partial target-only class declaration remains rejected because it would omit unrelated GrafPort fields and methods; source definitions emit from exact by-memory children.

- 2026-07-12 B004 UID000163 implementation sync:
  - Score, metadata, and class formal C++ remain unchanged.
  - Evidence: UID000163 now emits `GrafPort::GetPalette` / `SetPalette` over borrowed `DLPalette *m_palette`; exact getter/setter bytes, ten calls across four consumers, constructor null initialization, no destructor release, and DrawGlyph callback use supersede the historical opaque `m_brushHandle` spelling while preserving it as provenance.
- 2026-07-04 B010 UID000165 implementation callback:
  - Score unchanged at `88/90`.
  - Historically added method notes and class responsibility evidence for `GrafPort::UpdateSurfaceInfo`, `GrafPort::EndPaint`, `GrafPort::LineTo`, `GrafPort::DrawSprite`, `GrafPort::RenderTileFrame`, and then-owner-known/non-emitting `GrafPort::ScrollPixelBuffer`; the latter state was superseded by B001 on 2026-07-13.
  - Evidence: accepted B010 report, MCP session `73c77998`, exact child function sizes and xrefs, receiver-field analysis, callback slots, UID000165 parent no-code proof, and generated empty-marker repair.

- 2026-07-03 Agent-B007 UID0004DI implementation sync:
  - Score unchanged at `88/90`.
  - Historical evidence: at that date [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) was owner-known but non-emitting `86/90`; dated MCP session `3a33af0b` found no function/xrefs/`analyze_function` object and PE scans found zero rel32/short-branch/VA/RVA route hits. The then-expected generated absence and rejection of source-ready C++ were superseded by the 2026-08-22 whole-file source resolution; exact byte/padding proof remains valid. [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md) remains the separate emitted backing-store helper.
- 2026-07-02 B006 UID000166 implementation sync:
  - Score unchanged at `88/90`.
  - Historical evidence: the 2026-07-02 implementation routed [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) through this class under provisional `GrafPort::ForwardToTileFrameBlitHelper` spelling, with formal C++ on the exact child. Dated session `supervisor_resume_20260629` established the `0x73`-byte body, isolated padding, three direct callers, caller-set hidden receiver, target save/restore of `ecx`, then-modeled `FrameDrawRecord` source-rect fields at `+0x10..+0x1c`, slot-2 `dword_69B3E8` dispatch, and nullable opaque options pointer. The later whole-file pass superseded the provisional name/type details with active `BlitTileContextAt`/`EPFTileContext` source while preserving Surface as callback-table/backend dependency context.
- 2026-07-02 Agent-B005 UID0003XC split implementation:
  - Score unchanged at `88/90`.
  - Evidence: [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md) is now a non-emitting split/container with exact children [UID:0004DI][0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw](by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md) and [UID:0004DJ][0x004b97d0-0x004b981e.GrafPortReleaseBackingStore](by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md). The raw child preserved then-current no-function/no-route MCP/PE evidence and blank emitter/code; the B007 row above carries current UID0004DI provenance. The release child emits `GrafPort::ReleaseBackingStore()` through this class after six direct branch callers and field evidence tie it to `m_usesSoftwareBuffer`, `m_softwareBuffer`, and `m_ddSurface`. MapPane/ObjectPane/Surface/DirectX ownership and generic cleanup names are rejected; exact original spelling remains a confidence cap.
- 2026-06-25 B009 GetClipRect implementation sync:
  - Score unchanged at `88/90`.
  - Evidence: [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) is now documented and emitted as `GrafPort::GetClipRect(RectBounds *outClipRect)`, with current MCP evidence for the `0xa8` body, exclusive end `0x004b9768`, `retn 4`, padding at `0x004b9768-0x004b9770`, 44 direct code refs, Region helper callees, constructor support for `m_exposedRegion`/`m_clipRegion`/`m_surfaceContext.bounds`, `UpdateRenderRegion` support for exposed/dirty Region state at `this+0x04`, and rejection of caller-biased `RankingEventListPane` ownership.
- 2026-06-18 B003 CompositePixels support update:
  - Score unchanged at `88/90`.
  - Evidence: B003 reroutes [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) to this class as `GrafPort::CompositePixels(const RectBounds *rect)`, preserving exact padded boundaries, the `ret 4` thiscall shape, BowGauge/TextEdit direct caller set, no Surface callback dispatch, `m_drawEnabled` at `+0x71`, embedded `EPFTileContext` pixel/stride/bounds fields at `+0x20/+0x28/+0x2c/+0x30`, background color at `+0x7c`, `PaletteLib::GetCurrentPalette` / `DLPalette::MapColor`, and SSE/scalar zero-fill/nonzero-invert behavior.
- 2026-06-21 B006 line-count helper support sync:
  - Score unchanged at `88/90`.
  - Evidence: added [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) as a future shared text-measure reconciliation candidate in the GrafPort/text-helper neighborhood, while preserving current non-GrafPort ownership because the helper has no GrafPort state access and returns constant one.
- 2026-06-18 B002 DrawTiledBackground support update:
  - Before: `87/89`; [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) was described as caller-biased generated output with unresolved source-quality details.
  - After: `88/90`.
  - Evidence: B002 reanalysis routes [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) to this class as `GrafPort::DrawTiledBackground(const RectBounds *, const FrameDrawRecord *, const wchar_t *)`, preserving exact `0x16d` body/padding, 26 direct rel32 callers, `m_clipRegion` at `+0x54`, `m_visibleBounds` at `+0x44..+0x50`, draw/blit mode byte `+0x70`, alpha callback dependency `+0x90`, source tile rectangle at `FrameDrawRecord+0x10`, `g_pPaletteLib->GetPaletteByName`, repeated `dword_69B3E8` sprite/tile blits, non-positive tile-dimension restore caveat, and RankingEventListPane/Surface owner rejection.
- 2026-06-18 B002 GrafPortDrawRectFrame support update:
  - Before: `86/88`; [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) still had stale caller-biased generated-owner wording and blank formal C++.
  - After: `87/89`.
  - Evidence: B002 reanalysis routes [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) to this class as `GrafPort::DrawRectFrame(const RectBounds *rect)`, preserving exact `0xeb` body/padding, 49 direct rel32 refs, one-argument `__thiscall` shape, `m_drawEnabled`/`m_currentX`/`m_currentY` field names, the `GetClipRect`/`IntersectRects`/`IsRectEmptyOrInvalid` visibility gate, four `dword_69B3E4` line-delta callback dispatches over the original rectangle, and RankingEventListPane/Surface owner rejection.
- 2026-06-18 B003 SurfaceSpriteBlitHelper support update:
  - Before: `85/87`; [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) was still documented mainly as a Surface bucket helper.
  - After: `86/88`.
  - Evidence: B003 reanalysis routes [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) to this class as `GrafPort::BlitSurface`, preserving the exact receiver/source model, fields `+0x18/+0x1c/+0x20/+0x28/+0x90/+0x94`, DirectDraw `BltFast` flags `0x10`/`0x11`, software callback path through `dword_69B3E8`, mode caveat for values beyond `0`/`1`, MapPane owner rejection, and Surface dependency-only role.
- 2026-06-18 B005 SurfaceTileBufferBlitRaw reroute:
  - Score unchanged at `86/88`.
  - Evidence: [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) now routes through this class at `85/88`, owner/emitter [UID:00005V], with formal C++ blank. The accepted evidence is the combined `UpdateRenderRegion` virtual-slot call and `m_surfaceContext` field writes, while callback/palette use remains dependency context only.
- 2026-06-18 B003 current reanalysis sync:
  - Score unchanged at `85/87`.
  - Evidence: retained [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) as a no-owner/non-emitting GrafPort glyph/text best-family helper only. Fresh PE-byte checks reconfirmed unique bytes/subpattern, exact padding, no VA/RVA pointer or direct branch/call route, and live positive controls for adjacent entries; the broad short-branch candidate was a ModRM-byte false positive inside `GrafPortDrawGlyph`, so class ownership still is not defensible.
- 2026-06-26 B002 GrafPortDrawGlyph implementation sync:
  - Score unchanged.
  - Historical evidence: [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md) gained first-draft formal C++ under this class/emitter route using then-accepted `m_brushHandle`. The B004 UID000163 row above supersedes only that target-related token with typed `m_palette`; all other DrawGlyph content remains intact.
- 2026-06-17 B003 GrafPort split/source-quality update:
  - Score unchanged at `85/87`.
  - Evidence: incorporated [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) as `GrafPort::EnableSoftwareBuffer` and added the split raw-helper support pages [UID:0003XB][0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers](by-memory/0x004b94f0-0x004b95d5.GrafPortStateAndClipRawHelpers.md) and [UID:0003XC][0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease](by-memory/0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md). The former dirty-flag wording is rejected because `this+0x94` selects software backing, while dirty/exposed state remains Region-backed.
- 2026-06-17 B002 raw-island support update:
  - Score unchanged at `85/87`.
  - Evidence: added the no-owner [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) caveat so the class page carries the B002 heuristic result without absorbing the raw island as class-owned source.
- 2026-06-17 B002 WaterFilterEffecter support sync:
  - Score unchanged at `85/87`.
  - Evidence: [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) provides target-backed support for GrafPort byte `+0x70` as a draw/blit mode forwarded through [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), and for scalar `+0x90` as current alpha/opacity state.
- 2026-06-13 A001 clip-helper support update:
  - Score unchanged at `85/87`; the class page already cleared the supervisor parent gate.
  - Evidence: added live IDA-backed support for routing [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md) directly to this class rather than leaving it only on the file-level review bucket. The helper consumes GrafPort exposed/dirty Region, clip-region, and surface-bounds state, calls Region helpers, and has broad draw/render/text caller fan-in.
- 2026-06-13 A001 support update:
  - Score unchanged at `85/87`; the class page already cleared the supervisor parent gate.
  - Evidence: added live IDA-backed support for routing [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) directly to this class rather than leaving it only on the file-level review bucket. The helper pair consumes `GrafPort` receiver state, reads font/style offset `+0x8a`, depends on `StringIter` and `FontImageLib`, and has broad UI/text caller fan-in.
- 2026-06-13 A003 support update:
  - Score unchanged at `85/87`; the class page already cleared the supervisor parent gate.
  - Evidence: added live IDA-backed support for routing [UID:000163][0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md) directly to this class rather than leaving it only on the file-level review bucket.
- 2026-06-08 A004 Batch 119 parent-gate update:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`; the class page documented core GrafPort state and adjacent text-run/glyph helpers but not the wrapped text and text-effect helpers needed for direct parent routing.
  - After: `COMPLETION:85`, `CONFIDENCE:87`.
  - Evidence: Batch 119 IDA-backed review tied [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) and [UID:00016E][0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects](by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md) to GrafPort receiver state and shared text-helper call chains. [UID:0000JR][GrafPort](by-file/GrafPort.md) was also raised to the corrected `85` confidence gate, so the class/file chain now supports direct assignment of those helper bodies to this class.
- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: core graphics-port role, state block, backing storage, dirty/clip/draw helpers, text/glyph helper boundaries, constructor/update/destructor, caller counts, DirectDraw path, and global-name correction are documented in depth; remaining work is exact private field naming and final ownership for a few adjacent helper clusters. Evidence: `0x004b8bf0-0x004bb8c4` memory page, helper memory pages, `FontImageLib` text helper references, DirectX path notes, and `g_screenWidth` correction.
- 2026-06-01: Marked reconstructable and attached to [UID:0000JR][GrafPort](by-file/GrafPort.md).
  - Before: The page described a source-owned graphics-port class but left autogen metadata blank.
  - After: `RECONSTRUCTABLE:TRUE` and parent `0000JR`.
  - Evidence: IDA MCP rechecks on the draw-state and clip helper ranges confirm broad render/UI use through the GrafPort state block, while the proposed source tree places the owner in `render/GrafPort.cpp`.
## FolderSelectDialog Shared RTTI Dependencies R10/R16

These existing GrafPort-owned compiler RTTI records are reached from the FolderSelectDialog base array. They remain external dependency evidence and require no GrafPort or FolderSelectDialog handwritten RTTI source.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R10 | `0x640584-0x6405a0` BCD: TD `0x6739b4`, contained `1`, PMD `0/-1/0`, attrs `0x40`, CHD `0x6405a0` | `xref_query.total=374`; FolderSelectDialog graph edge `0x64783c`; outgoing TD `0x6739b4` and CHD `0x6405a0` | GrafPort-owned compiler RTTI; FolderSelectDialog only references it. |
| R16 | `0x6739b4-0x6739cc` TypeDescriptor `??_R0?AVGrafPort@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVGrafPort@@` | `xref_query.total=3`, including BCD edge `0x640584`; outgoing vfptr `0x635078` | GrafPort-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
