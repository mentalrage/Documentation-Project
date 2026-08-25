*** UID:0000TN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Surface.h"

unsigned char **g_surfaceColorLookup5Bit;
unsigned char **g_surfaceColorLookup6Bit;

SurfaceDrawPixelProc g_pfnDrawPixel;
SurfaceDrawLineDeltaProc g_pfnDrawLineDelta;
SurfaceSpriteBlitProc g_pfnBlitSprite;
SurfaceFillRleProc g_pfnFillRle;
SurfaceScaledRleTintProc g_pfnBlitScaledRleTint;
SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup;
SurfaceBitmaskBlitProc g_pfnBlitBitmask;
SurfaceFillRectProc g_pfnFillRect;
SurfacePackPixelProc g_pfnPackPixel;
SurfaceTransferPixelsProc g_pfnTransferPixels;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DLPalette;
class GrafPort;
class IntAlphaSurface;
struct EPFTileContext;
struct RectBounds;

struct SurfaceSpriteBlitOptions
{
    unsigned char kind;
    float alpha;
    signed char paletteShift;
    unsigned char *maskPixels;
    int maskWidth;
    int maskHeight;
    int maskStride;
    signed char secondaryPaletteShift;
};

typedef int (__thiscall *SurfaceSpriteBlitProc)(
    GrafPort *destination,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    int mode,
    DLPalette *palette,
    const SurfaceSpriteBlitOptions *options);

typedef void (__thiscall *SurfaceDrawPixelProc)(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex);

typedef void (__thiscall *SurfaceDrawLineDeltaProc)(
    GrafPort *port,
    int deltaX,
    int deltaY);

typedef void (__thiscall *SurfaceFillRleProc)(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    DLPalette *palette);

typedef void (__thiscall *SurfaceScaledRleTintProc)(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    float tintAmount,
    int rowOffset,
    float verticalScale,
    float horizontalShear);

typedef void (__thiscall *SurfaceAlphaLookupBlitProc)(
    GrafPort *port,
    const IntAlphaSurface *alphaSurface,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds);

typedef void (__thiscall *SurfaceBitmaskBlitProc)(
    GrafPort *port,
    const unsigned char *maskBits,
    const RectBounds *destinationBounds,
    unsigned char mode);

typedef void (__thiscall *SurfaceFillRectProc)(
    GrafPort *port,
    const RectBounds *bounds);

typedef unsigned short (__cdecl *SurfacePackPixelProc)(
    unsigned char high,
    unsigned char middle,
    unsigned char low);

typedef void (__cdecl *SurfaceTransferPixelsProc)(
    unsigned short *pixels,
    unsigned int pixelCount,
    int fadeStep);

extern SurfaceDrawPixelProc g_pfnDrawPixel;
extern SurfaceDrawLineDeltaProc g_pfnDrawLineDelta;
extern SurfaceSpriteBlitProc g_pfnBlitSprite;
extern SurfaceFillRleProc g_pfnFillRle;
extern SurfaceScaledRleTintProc g_pfnBlitScaledRleTint;
extern unsigned char **g_surfaceColorLookup5Bit;
extern unsigned char **g_surfaceColorLookup6Bit;
extern SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup;
extern SurfaceBitmaskBlitProc g_pfnBlitBitmask;
extern SurfaceFillRectProc g_pfnFillRect;
extern SurfacePackPixelProc g_pfnPackPixel;
extern SurfaceTransferPixelsProc g_pfnTransferPixels;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SurfaceRenderCallbackTable

## UID0000IF ConnStatusPane Slot-7 Consumer - 2026-08-22

- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) `OnPaint` uses the existing slot-7 declaration and storage exactly as `g_pfnFillRect(this, &m_visibleBounds)` when `m_connectionFrame == -1`, after setting draw mode and draw color to zero.
- The physical dispatch storage remains `0x0069b3fc`; `SurfaceFillRectProc` remains `void (__thiscall *)(GrafPort *port, const RectBounds *bounds)`. ConnStatusPane is one consumer only and introduces no callback typedef, global, provider, initializer, score, ownership, emitter, or formal-source change.

## UID0000LO MyItemListPane Fill Callback Link - 2026-08-14

[UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
calls the selected-row fill callback `g_pfnFillRect` from slot/storage
`0x0069b3fc` in both asset branches. The callback table remains the external
ABI/declaration owner; no callback signature, score, emitter, slot, or storage
change is introduced by the target consumer.

## UID00041S Slot-2 Shared ABI Closure - 2026-08-11

- `Surface.h` is the sole complete declaration owner for `SurfaceSpriteBlitOptions`, `SurfaceSpriteBlitProc`, and `extern SurfaceSpriteBlitProc g_pfnBlitSprite`; `Surface.cpp` owns exactly one declaration-ordered `SurfaceSpriteBlitProc g_pfnBlitSprite` definition between slots 1 and 3. Physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) remains storage evidence and does not duplicate source.
- Under the target 32-bit MSVC ABI, `SurfaceSpriteBlitOptions` is exactly `0x20` bytes: `kind +0x00`, implicit padding `+0x01..+0x03`, `alpha +0x04`, `paletteShift +0x08`, implicit padding `+0x09..+0x0b`, `maskPixels +0x0c`, `maskWidth +0x10`, `maskHeight +0x14`, `maskStride +0x18`, `secondaryPaletteShift +0x1c`, and tail padding `+0x1d..+0x1f`. Normal field declarations reproduce the padding; no packing pragma or decompiler byte array is required.
- The exact callback contract is `int (__thiscall *)(GrafPort *destination, const EPFTileContext *sourceContext, const RectBounds *sourceBounds, const RectBounds *destinationBounds, int mode, DLPalette *palette, const SurfaceSpriteBlitOptions *options)`. The final pointer is nullable. The existing `DLPalette`, `GrafPort`, `EPFTileContext`, and `RectBounds` declarations provide header visibility without importing unrelated owning definitions. The 2026-08-22 UID0000JR whole-file pass confirms all GrafPort consumers read rather than mutate the source context, closing the shared const qualification.
- Current consumers jointly prove the complete layout. Item drawing uses kinds `1`, `2`, `3`, and `6`; [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md) uses kind `8` and writes the clipped alpha-surface pixels, width, height, and stride into `+0x0c/+0x10/+0x14/+0x18`; other callers establish kind `4`. Installed compat/RGB565 providers consume the same offsets.
- Partially initialized option records are observed source behavior, not a reason to keep the type opaque. UID00041S kind `3` leaves `secondaryPaletteShift` unwritten before RGB565 reads `+0x1c`; UID00041R and UID00041U have related target-read omissions. The faithful reconstruction declares the shared struct but preserves each caller's exact writes rather than zero-initializing missing fields.
- Slot 2 has 114 direct physical xrefs and paired provider registrations at `0x004bc090` and `0x004c0f80`. The broad GrafPort, image-library, map, text, and pane consumer set supports a shared Surface declaration and rejects caller-local typedefs, callback globals, and feature-specific aliases. Historical opaque-struct/no-concrete-layout conclusions remain preserved below as superseded evidence.

## Status

- Symbol kind: process-wide render callback table / global function-pointer block.
- Storage range: [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- Likely source module: [UID:0000OC][Surface](by-file/Surface.md), with close ties to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
- Current alias surfaces include `dword_69B3E8`, `dword_69B3EC`, `dword_69B3FC`, `g_pfnBlitTileFrame`, `g_pfnBlitSprite`, `g_pfnBlitText`, `g_pfnLockSurface`, `g_preparedCompositionRenderer_69B3E8`, `g_targetCompositionRenderer_69B3EC`, and `g_uiTileRenderer`.
- Confidence: strong for shared callback-table storage, initialization, parent module, broad dispatch fanout, and the now-source-ready slot 0, slot 1, slot 2, slot 3, slot 4, and slot 7 declarations; other slot spellings/signatures remain bounded separately.

## Role

`SurfaceRenderCallbackTable` is a documentation grouping for twelve declaration-ordered typed module globals at `0x0069b3e0-0x0069b410`. [UID:00039V][0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks](by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md) installs them in its retained out-of-line body, and the same source call is fully inlined inside the live startup initializer at `0x00558840`. It selects one of two render-helper families from the active DirectDraw display mode and color mask.

This table is render infrastructure. Callers across panes, EPF/image libraries, composition libraries, map drawing, and UI controls dispatch through these slots. The breadth of the caller set means callsite-specific aliases should not be accepted as source ownership names.

The neighboring flags at [UID:00029U][0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags](by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md) are now documented as `g_surfaceUses32BitPresentation` / raw `byte_69B3D4` and `g_surfaceUsesRgb565Pixels` / raw `byte_69B3D5`. [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) consumes the D5 flag before calling [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md), but the helper is not a callback-table slot or table target. It remains stateless [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) pixel math while this page owns runtime callback dispatch.

## Callback Slots

Complete UID00039V raw disassembly plus the semantic inline copy in `0x00558840` show the following paired assignments. Every target has exactly two setup refs, one from each copy. No consumer or initializer loads/indexes a common table-object base, so the best source shape is independent typed globals; the contiguous range and this page remain useful documentation aggregation.

| Slot | Storage | Non-RGB565/compat target | RGB565-capable target | Current role evidence |
| --- | --- | --- | --- | --- |
| 0 | `0x0069b3e0` / `g_pfnDrawPixel` / raw `dword_69B3E0` | `0x004bb8d0` / source-ready [UID:0002PF][0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback](by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md) | `0x004c0770` / source-ready [UID:0002PI][0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback](by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md) | Exact `SurfaceDrawPixelProc`: source `void`, `GrafPort *` receiver in ECX, then `int x`, `int y`, and `unsigned int colorIndex`. Both file-local targets clip against the active GrafPort, use the global current palette, branch on `m_drawMode`, preserve low-byte direct writes and full-input color keys, and write one 16-bit destination pixel. Compat uses fixed RGB555 blending; RGB565 uses fixed `BlendRgb565Pixel(existing,mapped,0x10)`. |
| 1 | `0x0069b3e4` / `g_pfnDrawLineDelta` / historical raw `dword_69B3E4` | `0x004bb9b0` / body-empty [UID:0002PG][0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback](by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md) | `0x004c0850` / source-ready [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) | Exact `SurfaceDrawLineDeltaProc`: source `void`, `GrafPort *` receiver in ECX, then signed `int deltaX`, `int deltaY`, with physical `retn 8`. Consumers include void [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md), [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), and rain streak drawing. The installed target advances the GrafPort cursor by the original deltas. `DrawLineDelta` is the accepted descriptive source spelling rather than a recovered symbol. |
| 2 | `0x0069b3e8` / `g_pfnBlitSprite` / raw `dword_69B3E8` | `0x004bc090` | `0x004c0f80` | Exact `SurfaceSpriteBlitProc`: `int`, `GrafPort *` destination receiver, `const EPFTileContext *sourceContext`, source/destination bounds, integer mode, nullable palette, and nullable `const SurfaceSpriteBlitOptions *`. The complete `0x20` options layout covers kinds `1`, `2`, `3`, `4`, `6`, and `8`, including mask pixels/dimensions/stride and the secondary palette shift. Consumers include `BlueAlertPane`, `MapTileImageLib`, UID0004H5, UID0004H6, UID000166, UID000167, UID00016A, UID00041R, UID00041S, UID00041U, and UID00017J. Their breadth rejects caller-specific aliases. |
| 3 | `0x0069b3ec` / `g_pfnFillRle` / raw `dword_69B3EC` | `0x004bd420` / source-ready [UID:0002TB][0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback](by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md) | `0x004c3190` / source-ready [UID:0002TF][0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback](by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md) | Exact `SurfaceFillRleProc`: source `void`, `GrafPort *` receiver in ECX, then `const EPFTileContext *`, source and destination bounds, mode byte, and nullable `DLPalette *`. Both families clip/translate rectangles, resolve palette and GrafPort colors, parse signed zero-delimited row runs, and implement four exact copy/color-key/half-blend modes. Compat uses RGB555 masks; RGB565 uses RGB565 masks. [UID:00035C][0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw](by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md) resolves a palette and consumes the slot at `0x004b99e3`; it is not a target or initializer. |
| 4 | `0x0069b3f0` / `g_pfnBlitScaledRleTint` / raw `dword_69B3F0` | `0x004bdcc0` / [UID:0002TC][0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback](by-memory/0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md) | `0x004c3a50` / source-ready [UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md) | Exact `SurfaceScaledRleTintProc`: source `void`, `GrafPort *` receiver in ECX, then `const EPFTileContext *sourceContext`, `const RectBounds *sourceBounds`, `const RectBounds *destinationBounds`, `unsigned char mode`, `float tintAmount`, `int rowOffset`, `float verticalScale`, and `float horizontalShear`. [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) and modeled `MonsterImageLib::RenderMonster` establish the exact arguments; both providers decode signed zero-delimited mask rows and transform existing destination pixels, with RGB555 versus RGB565 channel extraction. |
| 5 | `0x0069b3f4` / `g_pfnBlitAlphaLookup` / historical raw `dword_69B3F4` | `0x004bdf40` / [UID:0002TD][0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback](by-memory/0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md) | `0x004c3cf0` / source-ready [UID:0002TH][0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback](by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md) | Exact `SurfaceAlphaLookupBlitProc`: source `void`, `GrafPort *` receiver in ECX, then `const IntAlphaSurface *`, source bounds, and destination bounds. MapPane dispatches through the typed global at `0x0050a267`; both providers copy a 0x14-byte `AlphaSurfaceBufferView`, clip/translate source and destination rectangles, run a four-pixel bulk prefix, and finish an RGB555/RGB565 scalar lookup tail through the shared 5/6-bit roots. |
| 6 | `0x0069b3f8` / `g_pfnBlitBitmask` / historical raw `dword_69B3F8` | `0x004be0e0` / source-ready [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) | `0x004c3ea0` / source-ready [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) | Exact `SurfaceBitmaskBlitProc`: source `void`, active `GrafPort *` in ECX, then `const unsigned char *maskBits`, `const RectBounds *destinationBounds`, and byte mode. Both providers use raw contiguous MSB-first packed 1bpp rows, clipping and destination-pitch math, canonical GrafPort colors, and four copy/color-key/half-blend modes. Compat uses `BlendRgb555Half`; RGB565 uses `BlendRgb565Pixel`. |
| 7 | `0x0069b3fc` / `g_pfnFillRect` / raw `dword_69B3FC` | `0x004be680` | `0x004c4380` | `void`; receiver plus `const RectBounds *`. [UID:0002YF][0x004be680-0x004bed67.SoftwareRenderCompatFillCallback](by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md) is source-ready `SoftwareRenderCompatFillCallback`, preserving draw guard, clipping, typed destination math, global-current-palette mapping, both `MapColor` calls, software-buffer color-128 override, four RGB555 modes, destination weighting, and exact odd-tail behavior. [UID:0002YK][0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback](by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md) is the source-ready paired `FillRgb565RectCallback`; its mode-3 odd-width overrun is provider-specific and is not copied into the compat body. UID0004JW, UID0002EV, and UID00011R establish control-side fill calls; UID00011R uses the literal direct-global source route `g_pfnFillRect(this, &bounds)`. Generated `g_pfnLockSurface`, target-local `RefreshPaneRegion`, raw `dword_`, and an invented GrafPort member are rejected source names. |
| 8 | `0x0069b400` / `g_pfnExpandPixel` / raw `dword_69B400` | `0x004bed80` | `0x004c46d0` | `void`; packed `unsigned short` plus three `unsigned char *` outputs; `ExpandRgb555Pixel` uses `pixel << 3`, `(pixel >> 2) & 0xf8`, `(pixel >> 7) & 0xf8`, while `ExpandRgb565Pixel` uses `pixel << 3`, `(pixel >> 3) & 0xfc`, `(pixel >> 8) & 0xf8`. [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md) is a consumer. |
| 9 | `0x0069b404` / `g_pfnPackPixel` / raw `dword_69B404` | `0x004bedb0` | `0x004c4700` | Exact `SurfacePackPixelProc`: cdecl `unsigned short`, arguments `unsigned char high`, `middle`, `low`, used as red, green, blue by DLPalette. `PackRgb555Pixel` shifts all channels right by three; `PackRgb565Pixel` shifts red/blue right by three and green right by two. [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md) proves the channel interpretation by reading `RGBTRIPLE` B/G/R bytes and passing R/G/B. |
| 10 | `0x0069b408` / `g_pfnTransformPaletteColor` / raw `dword_69B408` | `0x004bede0` | `0x004c4730` | `unsigned short`; packed pixel plus byte strength. `TransformRgb555PaletteColor` repacks RGB555; `TransformRgb565PaletteColor` uses the 5-bit low/high lookup and 6-bit middle lookup before RGB565 repack. [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) consumes it while rebuilding base, super, and runtime filtered palettes. |
| 11 | `0x0069b40c` / `g_pfnTransferPixels` / historical raw `dword_69B40C` | `0x004bee40` / source-ready [UID:0002YJ][0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback](by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md) | `0x004c4790` / source-ready [UID:0002YO][0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback](by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md) | Exact `SurfaceTransferPixelsProc`: cdecl `void`, mutable `unsigned short *pixels`, `unsigned int pixelCount`, and signed ordinal `int fadeStep`. Both direct ScreenPane consumers ignore EAX, rejecting the decompiler pointer-return shape. Both providers clamp to `0..24`, apply the exact 25-step attenuation sequence, process packed pairs plus one odd tail, preserve step 0, and clear at step 24. Compat uses RGB555 masks; RGB565 uses `0x0841`, `0x18c3`, `0x39c7`, and `0x7bcf` channel-safe shifts. |

The "RGB565-capable" path is selected when the surface description reports 32-bit mode or a 16-bit green mask of `0x07e0`. The other path is likely the retained RGB555/compatibility family, but the final product-level old/new rendering split still needs a broader pass.

## Slot 11 Source-Ready Declaration And Dispatch

- `SurfaceTransferPixelsProc` is exactly `void (__cdecl *)(unsigned short *pixels, unsigned int pixelCount, int fadeStep)`. The buffer is mutable 16-bit surface storage, the count is total pixels, and the third argument is one ordinal fade step rather than a generic mode.
- The source global is `g_pfnTransferPixels`; semantic UID0000TN owns this one typedef, `extern` declaration, and single `Surface.cpp` definition. Physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) only documents the fixed four-byte slot and must not duplicate storage.
- File-local compat/RGB555 provider UID0002YJ is registered at `0x005586f9` and `0x00558bee`. Source-ready RGB565 provider UID0002YO is registered at `0x005587e7` and `0x00558f0a`; [UID:00039V][0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks](by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md) selects one family from the current display format.
- Slot xrefs are exactly `0x005571e6`, `0x005584a4`, `0x005587a9`, `0x00558bee`, and `0x00558f0a`. Presentation consumers `0x005571e6` and `0x005584a4` pass the active surface buffer, width-times-height pixel count, and ScreenPane `m_fadeStep`, then ignore the callback return.
- UID0002YO's RGB565 source masks are `s1=(x>>4)&0x0841`, `s2=(x>>3)&0x18c3`, `s4=(x>>2)&0x39c7`, and `s8=(x>>1)&0x7bcf`, repeated in both halfwords for packed pairs. Steps 0 through 24 are `x`, `x-s1`, `x+s1-s2`, `x-s2`, `x-s1-s2`, `x+s1-s4`, `x-s4`, `x-s1-s4`, `x-s2-s4`, `x-s1-s2-s4`, `x+s1-2*s4`, `x+s1-s8`, `s1+s8`, `s8`, `s8-s1`, `2*s4-s1`, `s1+s2+s4`, `s2+s4`, `s1+s4`, `s4`, `s4-s1`, `s1+s2`, `s2`, `s1`, and `0`.
- The RGB565 body transforms two pixels per packed dword and one final 16-bit pixel for odd counts. It performs no internal rectangle clipping, performs no write for a zero count, preserves full intensity at step 0, and clears exactly `pixelCount * sizeof(unsigned short)` bytes at step 24. The optimized steps 13, 19, 22, and 23 use packed masks `0xf79ef79e`, `0xe71ce71c`, `0xc618c618`, and `0x84108410`, with matching halfword masks on the odd tail.
- Source order is shared typedef/extern in `Surface.h`, one `g_pfnTransferPixels` definition alongside other callback globals in `Surface.cpp`, both provider bodies, initializer selection, then consumers in their accepted source routes. No table object or duplicate physical definition is inferred from contiguous addresses.

## Slot 0 Source-Ready Declaration And Dispatch

- This bounded update resolves slot 0 only. The other eleven slots, their current descriptive aliases, option-layout cautions, consumer inventories, scores, and unresolved exact original typedef spellings are preserved.
- `SurfaceDrawPixelProc` is a source `void` callback with the active `GrafPort *` in ECX and stack arguments `int x`, `int y`, and `unsigned int colorIndex`. Both installed targets end with `retn 0x0c`, and consumers ignore return semantics.
- The source global is `g_pfnDrawPixel`. The fixed storage is `0x0069b3e0`, but raw `dword_69B3E0` is retained only as binary-history evidence.
- The compat target is file-local `SoftwareRenderCompatPixelCallback`; the RGB565 target is file-local `SoftwareRenderRgb565PixelCallback`. Their bodies remain on their exact by-memory pages and are not duplicated in this global declaration.
- Raw and modeled setup choose exactly one family and assign this global. The out-of-line retained initializer and its inlined source call each contain one compat assignment and one RGB565 assignment path, while twelve rain-drawing callsites dispatch through the global.
- `EMITTER_POSITION_OPTIONAL:20` places the slot-0 type/global declaration after earlier Surface globals and before the file-local callback bodies and initializer in generated source order.
- GrafPort is the receiver/layout dependency. Surface owns and emits the typed global and both callback implementations. Callback-table fixed storage documents the physical dword but does not emit a second declaration or body.

## Slot 3 Source-Ready Declaration And Dispatch

- `SurfaceFillRleProc` is a source `void` callback with active `GrafPort *` in ECX and five stack arguments: `const EPFTileContext *sourceContext`, `const RectBounds *sourceBounds`, `const RectBounds *destinationBounds`, `unsigned char mode`, and nullable `DLPalette *palette`. Both installed functions clean `0x14` stack bytes; the decompiler's byte result and EBP input are register-residue artifacts.
- The single source global is `g_pfnFillRle` at physical storage `0x0069b3ec`. Its eleven xrefs include the two family assignments, the palette-resolving forwarder, and broad Surface/image/UI consumers; this breadth rejects caller-specific ownership or naming.
- The compat/RGB555 provider is file-local `SoftwareRenderCompatRleFillCallback`; the RGB565 provider is file-local `SoftwareRenderRgb565RleFillCallback`. The retained out-of-line initializer stores them at `0x00558728` and `0x00558816`, and the live inlined source copy stores them at `0x00558b9e` and `0x00558eba`.
- Both providers apply the same draw-enabled guard, destination clipping and source translation, palette fallback, `m_drawColor` / `m_textBackFillColor` resolution, signed-byte run grammar, bounded clipped-row pre-skip, run clipping, and mode `0..3` semantics. Their only semantic pixel-format difference is RGB555 versus RGB565 half-blend masks and corresponding compiler-generated vector lowering.
- `EMITTER_POSITION_OPTIONAL:20` emits this typedef/global once with the other resolved table declarations. [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) remains the blank physical-storage child; the exact callback bodies remain on UID0002TB and UID0002TF.

## Slot 4 Source-Ready Declaration And Dispatch

- `SurfaceScaledRleTintProc` is a source `void` callback with active `GrafPort *` in ECX and eight stack arguments: `const EPFTileContext *sourceContext`, `const RectBounds *sourceBounds`, `const RectBounds *destinationBounds`, `unsigned char mode`, `float tintAmount`, `int rowOffset`, `float verticalScale`, and `float horizontalShear`.
- The single source global is `g_pfnBlitScaledRleTint` at physical storage `0x0069b3f0`. Exactly twenty-one slot references include broad image/render consumers and three setup/assignment references; this breadth rejects caller-specific ownership and preserves Surface as owner.
- The compat/RGB555 provider is file-local `SoftwareRenderCompatScaledRleTintCallback`; the RGB565 provider is file-local `SoftwareRenderRgb565ScaledRleTintCallback`. The retained initializer selects them at `0x0055873b` and `0x00558829`; the live inlined source copy selects the compat provider at `0x00558ba8` and the RGB565 provider at `0x00558ec4`.
- Riding and Monster consumers independently establish mode, tint amount, row offset, vertical scale, and horizontal shear. Both providers parse `EPFTileContext::encodedMaskBytes` as signed zero-delimited row runs and transform existing destination pixels rather than reading source pixel colors.
- The callback typedef, extern, and one global definition emit here through semantic UID0000TN. The physical UID0001PI page remains non-emitting and covered-by this owner, and each provider body remains on its exact by-memory target.
- The RGB565 provider's target H remains blank because it is file-local. Its source-ready body belongs in `Surface.cpp` after UID0002TF and before UID0002TH.

## Slot 9 Source-Ready Declaration And Dispatch

- `SurfacePackPixelProc` is an exact cdecl callback returning `unsigned short` from three `unsigned char` channels. The accepted argument names `high`, `middle`, and `low` describe provider bit lanes; DLPalette calls them as red, green, and blue.
- The single source global is `g_pfnPackPixel` at physical storage `[0x0069b404,0x0069b408)`. The image value is zero, and runtime initialization chooses compat/RGB555 `PackRgb555Pixel` at `0x004bedb0` or RGB565 `PackRgb565Pixel` at `0x004c4700`.
- The nine refs include four DLPalette consumers and both retained/inlined setup families. Provider target refs are `0x00558705`/`0x00558be4` for RGB555 and `0x005587f3`/`0x00558f00` for RGB565.
- [UID:0004I4][0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette](by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md) independently fixes channel order: its three-byte local has Windows `RGBTRIPLE` B/G/R offsets 0/1/2, while the call pushes red, green, blue. `DLPalette::SetColor`, `LoadFromStream`, and `LoadFromRawRGBA` are the other bounded consumers.
- Raw `dword_69B404` / `unk_69B404` and callsite-specific aliases remain evidence names only. Surface owns one typedef/global declaration and definition; DLPalette owns no duplicate storage, and physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) emits only a covered-by marker.

## Slot 6 Source-Ready Declaration And Dispatch

- `SurfaceBitmaskBlitProc` is the exact source `void __thiscall` contract: active `GrafPort *` in ECX plus three stack arguments, `const unsigned char *maskBits`, `const RectBounds *destinationBounds`, and `unsigned char mode`. Both providers end with `retn 0x0c`; consumers ignore EAX, rejecting the historical byte-return and dummy-EDX decompiler shapes.
- The single source global is `g_pfnBlitBitmask` at physical storage `0x0069b3f8`. Twelve refs include two-family assignment routes and nine exact BalloonObjectPane `PaintBubble` calls; broad function-pointer dispatch rejects feature-specific ownership.
- Compat provider [UID:0002TE][0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback](by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md) is file-local `SoftwareRenderCompatBitmaskBlitCallback`; RGB565 provider [UID:0002TI][0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback](by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md) is file-local `SoftwareRenderRgb565BitmaskBlitCallback`. The out-of-line initializer stores them at `0x0055872f` and `0x0055881d`; the inlined initializer stores them at `0x00558bbc` and `0x00558ed8`.
- Supervisor Gate 2B persisted slot 6 on 2026-07-29. `SurfaceBitmaskBlitProc` now exists in IDA as a four-byte function-pointer type, and every address `0x0069b3f8-0x0069b3fb` resolves to the one item `[0x0069b3f8,0x0069b3fc)`, size four, name `g_pfnBlitBitmask`, and type `SurfaceBitmaskBlitProc`. Its regular comment is blank and its repeatable comment records the RGB555/RGB565 providers and `BalloonObjectPane::PaintBubble` consumer. The protected `g_pfnFillRect` item at `0x0069b3fc` remains separate and unchanged; bytes and twelve slot refs are unchanged. The saved IDB SHA256 is `7F3024691E4C38EA46E9160617C636ADFCA079D9CB76798866616FA1004BFB94`.
- Both providers clip destination bounds, translate clipped output to a zero-origin mask extent, traverse contiguous MSB-first packed 1bpp data, resolve `m_drawColor` and `m_textBackFillColor`, and implement the same four copy/color-key/half-blend modes. Their format-specific difference is RGB555 `BlendRgb555Half` versus RGB565 `BlendRgb565Pixel`.
- Declarations, typedefs, and externs now live in formal H; formal CPP includes `Surface.h` and emits the single global definitions. The prior declaration-in-CPP shape is preserved only as superseded history. Physical UID0001PI remains blank so fixed storage is not emitted twice.

## Evidence

- IDA MCP `xrefs_to` on 2026-05-24 showed `dword_69B3E8` has 114 direct xrefs, `dword_69B3EC` has 11, and `dword_69B3FC` has 206.
- B004 2026-07-13 current MCP-backed UID00039V pass proves the out-of-line helper `[0x00558690,0x0055883d)` and complete inline copy inside UID00039W install identical target pairs. Every one of the 24 callback functions has exactly two setup data refs. The helper's zero inbound start/end refs and zero VA/RVA pointer matches remain valid negative machine-route evidence, while exact inline equivalence proves source liveness.
- UID00039V queries an unseeded 108-byte `DDSURFACEDESC` with only `dwSize` assigned and tests exact `DD_OK`. It sets both format flags for 32-bit, clears both for 24-bit, sets only RGB565 from `dwGBitMask == 0x07e0` for 16-bit, and preserves both prior flags on query failure or another depth before selecting this callback family.
- IDA MCP decompilation of `0x00558840` shows the complete callback-table assignment block, plus construction of two alpha/scale lookup tables at nearby globals `dword_69B3D8` and `dword_69B3DC`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_558840`, size `0x723`, and xrefs to callback-table slots including `0x0069b3e0`, `0x0069b3e8`, and `0x0069b3fc`.
- IDA MCP `py_eval` on 2026-06-07 historically reported all-`0xff` initialized bytes across `0x0069b3d4-0x0069b430`. Current UID0002YK evidence supersedes that byte-value claim for exact slot `0x0069b3fc` with zero image bytes followed by runtime assignment, just as B011's 2026-07-08 UID00029U pass supersedes it for the adjacent flag window `0x0069b3d4-0x0069b3d7`. The 2026-06-07 evidence remains useful for the exact 12-dword bounds and per-slot direct-ref counts `15/26/114/11/21/4/12/206/4/9/8/5`. Its 131-function grouping for slot 7 is historical counting-method evidence: the current target pass classifies 130 modeled caller functions plus seven raw/unmodeled sites while preserving the same 206 total refs.
- B001 2026-07-06 UID0004HT source-ready sync records slot 8 / `dword_69B400` as descriptive `g_pfnExpandPixel` / `SurfaceExpandPixelProc` and records the DLPalette consumer call at `0x00542b8c`. The slot remains Surface callback-table provider infrastructure; UID0004HT remains the DLPalette consumer.
- B011 2026-07-04 UID0002PF source-ready sync records slot 0 / `dword_69B3E0` as the low-level pixel write/blend callback with compat target [UID:0002PF][0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback](by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md). Current MCP session `73c77998` verifies exact range `0x004bb8d0-0x004bb9a5`, size `0xd5`, non-function end, eleven-byte padding before `0x004bb9b0`, zero normal callers, target refs `0x00558745`/`0x00558b80`, 15 refs to slot storage `0x0069b3e0`, receiver-in-`ecx` `GrafPort *` callback direction, draw-enabled `+0x71`, draw mode `+0x70`, `GetClipRect`, `PointInRect`, palette mapping, direct low-byte writes, transparent nonzero checks, and `BlendRgb555` weight `0x10`. This confirms Surface ownership for the installed callback target while this global page remains table/storage documentation.
- B014's 2026-06-26 source-quality pass confirms [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) as a concrete slot-10 consumer: `PaletteLib::UpdatePaletteFilterTables` dispatches through `dword_69B408` while transforming colors `1..255` for the base palette, seven super palettes, and 25 runtime palette-list slots with slot `11` intentionally skipped. This strengthens slot 10 as the shared palette/filter color-transform callback while preserving Surface ownership of the callback table.
- `FittingRoomDownloadControlPane::RenderTileFrame` at `0x004b9980` is only a small wrapper: it resolves a palette, then calls `dword_69B3E8`. The recovered owner label is caller-biased; [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) is another confirmed consumer.
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) border drawing at `0x00500e20` repeatedly resolves `BDFRAME.EPF` frames and calls `dword_69B3E8`.
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) `DrawTile` uses `dword_69B3FC` for fallback fill/invalidation and `dword_69B3E8` for actual tile drawing.
- [UID:0004JW][0x00499310-0x004993a5.EPFImageControlPaneOnPaint](by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md) is a virtual-only primary-vtable consumer that sets draw color zero and calls `dword_69B3FC(this,this+0x44)` before frame lookup. Installed-target behavior and inherited `m_bounds` establish source-facing `FillRect(&m_bounds)` for this call site; historical `LoadAndRenderImage` and one-argument `g_pfnLockSurface(drawSurface)` are rejected source projections.
- [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md) is another exact slot-7 consumer. Current enabled and disabled branches each call `dword_69B3FC(this, &m_bounds)` after `SetDrawColor(0)`; legacy calls `dword_69B3FC(this, &m_contentRect)` after `SetDrawColor(143)`. Installed-target clipping/fill behavior supports source-facing `FillRect` for all three calls and rejects `RefreshPaneRegion` or `g_pfnLockSurface` in ChattingPane source.
- 2026-07-14 UID0002Y1 support resolves slot 4 beyond the earlier generic composition label. Compat `0x004bdcc0` and RGB565 `0x004c3a50` independently decompile to the same void GrafPort-receiver/eight-argument signature. RidingImageLib RenderRiding calls it at `0x004dc9fb`; modeled RenderMonster calls it at `0x004db310`; slot storage has 21 refs. Their arguments establish source context, source/destination rectangles, mode `3`, float MapPane tint, integer row offset `0`, vertical scale/projection divisor, and horizontal shear. RenderRiding's centered branch passes fixed `1.5f/0.0f`; other branches pass MapPane `+0x3d4/+0x3d8`.
- The exact slot-4 consumer evidence does not transfer ownership from Surface or justify caller-specific callback names. `g_pfnBlitScaledRleTint` remains the accepted descriptive global alias, while exact original typedef/token spelling remains a confidence cap. The aggregate stays `89/86` with unchanged owner/emitter and blank formal because broader slot declaration debt is outside this bounded update.
- [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md) is an exact slot-7 consumer. `StaticTextControlPane2::SimpleHelpTextPartPane::OnPaint` sets draw color zero and calls `dword_69B3FC(this, &m_bounds)` before parsing and drawing its text lines. Installed-target clipping/fill behavior supports source-facing `FillRect(&m_bounds)` and rejects generated `g_pfnLockSurface` wording for this callsite; Surface callback-table ownership is unchanged.
- [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md) builds an offset rectangle and forwards through `dword_69B3E8`.
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) uses `dword_69B3E8` in its software/composition path after updating both surface metadata blocks.
- B003 2026-06-18 reanalysis of [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md), amended by B005 on 2026-07-02, supports naming slot 2 descriptively as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`. The caller sets `ecx` to the destination GrafPort and passes `const EPFTileContext *sourceContext`, `sourceRect`, `destinationRect`, `mode`, `paletteOrNull`, and a final NULL options pointer. The installed callback targets `0x004bc090` and `0x004c0f80` both preserve `ecx` as the destination and consume the same first stack arguments, so callsite-specific aliases such as `g_uiTileRenderer` remain rejected. The earlier scalar `int flags` wording is stale: [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) passes a nonzero pointer, and both installed targets dereference the final argument when non-null.
- B004 2026-06-20 EPFTileContext support sync: slot 2 is also an encoded-mask consumer. The source descriptor can be an `EPFTileContext` whose `encodedMaskByteCount`/`encodedMaskBytes` fields at `+0x20/+0x24` come either from ResourceLayout preencoded EPF/EPD rows or from `EPFTileContext::BuildEncodedMask`. Both installed slot-2 families, compat/RGB555 `0x004bc090` and RGB565 `0x004c0f80`, handle masked/transparent spans, so encoded masks are not limited to an old-rendering path.
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) dispatches each rectangle edge through `dword_69B3E4`. B002 2026-06-18 reanalysis supports slot `0x0069b3e4` as the line-delta draw callback used by `GrafPort::LineTo` and `GrafPort::DrawRectFrame`: callers supply the active GrafPort/draw receiver and signed `dx, dy` deltas, and selected software-render implementations such as [UID:0002PG][0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback](by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md) or [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) consume the deltas and advance current draw position.
- B010 2026-07-04 UID000165 split sync confirms the new exact [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md) child as a slot-1 consumer from current MCP session `73c77998`, command `145`: it subtracts `m_currentX` / `m_currentY` from the destination point and calls slot `0x0069b3e4`.
- B010 also resolves [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md) and [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md) as slot-2 consumers, not callback-table targets. Disassembly command `109` shows `DrawSprite` borrowing source alpha and passing source context `+0x1c`; disassembly command `108` shows `RenderTileFrame` resolving a palette name through `g_pPaletteLib` before calling slot `0x0069b3e8`. UID00035C remains the slot-3 raw consumer, and UID000165 parent no longer emits a placeholder.
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) proves slot `0x0069b3e8` is used by `GrafPort::DrawTiledBackground` with `ecx` as the destination `GrafPort`, a `FrameDrawRecord` / EPF-compatible source descriptor pointer, a source `RectBounds *` at descriptor offset `+0x10`, a destination `RectBounds *`, a draw/blit mode byte from `GrafPort+0x70`, a palette pointer from `PaletteLib::GetPaletteByName`, and `NULL` options. This supports `SurfaceSpriteBlitProc` / `g_pfnBlitSprite` and rejects text-specific or caller-specific aliases; zero final arguments are null-options callers, not proof of scalar flags.
- B001 2026-06-20 OverlayMovingImageEffecter support sync adds local `0x004b9980` argument evidence from [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md): the wrapper receives a frame/source descriptor, source rect/view, destination/draw bounds, draw mode, a fifth-argument palette/overlay lookup key consumed by `g_pPaletteLib->GetPaletteByName`, and a sixth options value forwarded as `NULL` before dispatching through slot `0x0069b3e8`. This reinforces slot 2 as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, not a fitting-room-specific renderer.
- B005 2026-07-02 [UID:00041U][0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled](by-memory/0x004df2c0-0x004df455.ItemObjImageLibDrawItemImageScaled.md) support repair proves the slot-2 final parameter is nullable options pointer. UID00041U writes option selector byte `+0` as kind `4` or `6`, conditionally writes palette byte `+8`, and passes the stack block as the final argument. Compat slot target `0x004bc090` reads option bytes/dwords at `+0`, `+8`, and `+0x0c`; RGB565 slot target `0x004c0f80` reads `+0`, `+8`, `+0x0c`, and option-6 byte `+0x1c`. A concrete `SurfaceSpriteBlitOptions` field layout remains unsafe to emit because UID00041U does not initialize `+0x1c`, but the source-facing callback typedef should now use an opaque `const SurfaceSpriteBlitOptions *options`, not `int flags`.
- B003 2026-07-02 [UID:00041R][0x004dee50-0x004defba.ItemObjImageLibDrawItemImage](by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md) support sync adds the unscaled item-draw option family. UID00041R passes either `NULL` options or a stack options record with selector `+0` set to kind `1`, `2`, or `3`. Kind `1` writes alpha at `+0x04`; kind `2` writes palette/tint at `+0x08` and secondary shift zero at `+0x1c`; kind `3` writes alpha at `+0x04` and palette/tint at `+0x08` but does not write `+0x1c`. Compat slot target `0x004bc090` switches on `+0x00` and reads `+0x08`; the bounded recheck found no compat read at `+0x1c`. RGB565 slot target `0x004c0f80` reads `+0x04`, `+0x08`, and the secondary byte at `+0x1c`, including option-kind `3` at `0x004c189d`; broader RGB565 option-family reads also occur at `0x004c138a` and `0x004c1eee`. This preserves the nullable opaque `const SurfaceSpriteBlitOptions *options` support model while proving that a concrete initialized struct policy is still unsafe for UID00041R source emission.
- B007 2026-06-28 UID00035C support sync records [UID:00035C][0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw](by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md) as a concrete slot-3 consumer only. Current MCP session `supervisor_20260628_resume` shows the raw body calls `dword_69B3EC` at `0x004b99e3` after resolving the fifth stack argument through `g_pPaletteLib` / `PaletteLib::GetPaletteByName`, but no xref, VA/RVA pointer literal, direct branch, vtable, or registration route targets `0x004b99c0`. Slot-target refs remain `0x004bd420` at `0x00558728`/`0x00558b9e` and `0x004c3190` at `0x00558816`/`0x00558eba`, so UID00035C must not be modeled as a callback-table target or initializer.
- B001-029 rechecked [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and its exact children with live IDA. The compat targets have no ordinary direct callers; the tail target-address refs remain initializer/table refs at `0x00558bbc`, `0x00558bc6`, `0x00558bda`, `0x00558be4`, `0x00558bd0`, and `0x00558bee`. That evidence resolves the earlier Surface-vs-SoftwareBlend16 question in favor of Surface/render-dispatch ownership for callback-table targets while keeping `SoftwareBlend16` as the owner of reusable stateless pixel/span math.
- B001-033 rechecked [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) and its exact children with live IDA. The RGB565 targets likewise have no ordinary direct callers; each has one raw setup-neighborhood target ref and one `sub_558840` target ref, including tail refs at `0x00558ee2`, `0x00558ef6`, `0x00558f00`, `0x00558eec`, and `0x00558f0a`. This confirms Surface/render-dispatch ownership for the RGB565 callback targets while keeping `SoftwareBlend16` limited to called stateless blend/math helpers such as `BlendRgb565Pixel` and `BlendRgb565Pair`.
- 2026-06-18 B005 retry reclassifies [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) from no-owner Surface-family orphan to `GrafPort`-owned raw callback consumer. It calls slot `dword_69B3E8` at `0x004bb2ca`, but it is not a callback-table target or initializer; the direct owner evidence is the receiver's `GrafPort::UpdateRenderRegion` virtual call and `m_surfaceContext` field writes.
- `NewHumanImageLib` callsites alias the same storage as `g_preparedCompositionRenderer_69B3E8` and `g_targetCompositionRenderer_69B3EC`, showing why callsite-specific names are not stable.
- B005 2026-06-19 confirms [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) is a one-caller leaf helper reached from [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md), not an entry in this callback table. Its dependency on `g_surfaceUsesRgb565Pixels` should be treated as Surface pixel-format context, not callback-table ownership.
- B005 2026-06-19 ProgressBarControlPane implementation records [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) as a concrete control consumer of slot `0x0069b3fc`: the method fills the active and inactive progress rectangles after `SetDrawColor(1)` and `SetDrawColor(143)`. The source-facing wrapper name in control code is `FillRect`; raw `dword_69B3FC` and generated `g_pfnLockSurface` remain evidence/alias names, not preferred handwritten control-source names.
- B004 2026-06-20 SeparatorMenuItem implementation records [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) as a concrete menu-item consumer of slot `0x0069b3fc`: `SeparatorMenuItem::DrawItem(GrafPort *port)` clears active draw mode, calls `GrafPort::SetDrawColor(0x80)`, builds an inset centered separator rectangle from inherited `m_bounds`, and calls the slot as a rectangle fill/invalidate wrapper. The source-facing menu code should use descriptive `g_surfaceRenderCallbacks.fillOrInvalidate` / `FillRect`-style wording; raw `dword_69B3FC` and generated `g_pfnLockSurface` remain evidence/alias names.
- B008 2026-06-21 BalloonObjectPane support sync records [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) / `PaintBubble` as a concrete consumer of slots `dword_69B3E4`, `dword_69B3F8`, and `dword_69B3FC` while drawing speech-balloon frame/tail/fill pieces. This is consumer evidence only; the callback slots remain Surface/GrafPort infrastructure, not BalloonObjectPane-owned globals.
- B012 2026-07-04 UID0002TI support sync records slot 6 / `dword_69B3F8` as source-ready on the RGB565 target side. Current MCP session `73c77998` confirms the RGB565 target is exact `0x004c3ea0-0x004c4364`, has zero direct callers, two target refs (`0x0055881d`, `0x00558ed8`), twelve slot refs, local switch-table bytes at `0x004c4364-0x004c4380`, packed 1bpp row traversal, `RectBounds` clipping, GrafPort surface-context pointer math, palette-mapped `+0x74/+0x78` colors, four numeric mode cases, and [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) calls at weight `16`. BalloonObjectPane remains a slot consumer only, the RGB565 aggregate remains non-emitting, and SoftwareBlend16 remains the helper owner rather than the callback owner.
- B008 2026-06-21 ObjectImageControlPane support sync records [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) / `ObjectImageControlPane::OnPaint` as a concrete slot-7 consumer: the method initializes an `EPFTileContext`, calls `GrafPort::SetDrawColor(0)`, then calls `dword_69B3FC(this, &m_bounds)` before dispatching to human, monster, or item image-library drawing. Source-facing control code should use descriptive `PreparePaneRegion`, `FillRect`, or fill/invalidate wording depending on final slot naming; raw `dword_69B3FC` and generated `g_pfnLockSurface` remain evidence/alias names.
- B012 2026-06-21 SurfaceDrawTilePresentation support sync records [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) as a concrete caller of slot 11 / `dword_69B40C`, not a callback-table target. The helper dispatches the active pixel buffer, computed active-surface area, and `this+0x5ac` block-transfer/effect mode through the slot in its direct presentation path; local PE scans found no pointer/callback route from this table back to `0x005583a0`.

### UID0002YK Slot-7 Provider Resolution

- Slot 7 storage is zero-initialized in the image and populated by Surface setup. Raw
  UID00039V loads RGB565 UID0002YK at `0x00558811` and compat target `0x004be680`
  at `0x00558723`; both reach the shared slot store at `0x00558770`. The inline copy
  writes the same RGB565 target at `0x00558ee2`. The target
  has no direct code caller and only those two address refs, while the slot has 206
  refs across broad render/UI dispatch.
- The accepted logical signature is `void` with destination `GrafPort *` in ECX and one
  `const RectBounds *` stack argument. The source declaration is exact descriptive
  `SurfaceFillRectProc g_pfnFillRect`; historical `g_fillRectCallback`,
  `g_pfnFillOrInvalidateRect`, `g_pfnLockSurface`, and raw `dword_69B3FC` remain
  evidence aliases or rejected source spellings. The child definition uses a file-local
  fastcall receiver and unused EDX shim to realize the ABI.
- UID0002YK is the sole source-body destination. This global page retains its existing
  table ownership and score while emitting only the independently closed slot-0 and
  slot-7 declarations. Other slot typedefs remain broader work, and no callback body is
  duplicated here.

## UID00030C And UID0001JR Slot-7 Consumers

- [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md) calls `g_pfnFillRect(this, &m_bounds)` after setting draw mode/color for the editor background, then calls the same slot with the exact caret rectangle after setting `m_textColor`.
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) calls `g_pfnFillRect(pane, &state->clippedLineRect)` after clipping the current line and selecting black or `m_textBackColor`.
- Both consumers pass a GrafPort-derived TextEditPane receiver and `const RectBounds *`, matching compat target `0x004be680`, RGB565 target `0x004c4380`, raw stores `0x00558723/0x00558770/0x00558811`, inline store `0x00558ee2`, and the 206-reference slot fanout.
- The two consumers strengthen only slot 7. They do not change table ownership, scores, fixed-global source shape, any provider body, or unresolved typedefs for the other ten slots.

## UID00011R RectangleControlPane Slot-7 Consumer - 2026-08-16

- [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) is the exact slot-7 consumer for `RectangleControlPane::OnPaint`. It first calls inherited `GetBounds(&bounds)`, then restores the RectangleControlPane receiver to `ecx`, pushes the local `RectBounds *`, and executes `call dword ptr ds:0x0069b3fc`.
- The source call is `g_pfnFillRect(this, &bounds)`. The receiver is GrafPort-compatible through RectangleControlPane's inheritance, and the sole stack argument matches `const RectBounds *`; this is the exact existing `SurfaceFillRectProc` ABI rather than a caller-specific wrapper type.
- `RectangleControlPane.cpp` consumes the declaration through `../../render/Surface.h`. The generated GrafPort header chain contains no `FillRect` method, so historical `FillRect(&bounds)` prose is only descriptive shorthand and cannot justify inventing a member declaration.
- This consumer adds no callback storage or provider body. UID0000TN remains the semantic global owner/emitter, UID0000OC remains the Surface file owner, the existing typedef/global definition/extern declaration and `94/95` metadata remain unchanged, and UID00011R remains RectangleControlPane-owned method source.

## UID0004WS Generic Scrolled-Text Slot-2 And Slot-7 Consumer

- [UID:0004WS][0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame](by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md) is an exact generic `ScrolledTextControlPane::OnPaintFrame` consumer of slots `0x0069b3fc` and `0x0069b3e8`.
- The method first sets draw color zero and dispatches slot 7 over inherited `m_bounds`. Installed compat/RGB565 fill targets and the broad accepted interface establish source-facing inherited `FillRect(&m_bounds)`; raw `dword_69B3FC`, historical `g_pfnLockSurface`, and caller-specific prepare/invalidate aliases are rejected for this control source.
- It then derives exact source/destination rectangles from `EPFTileContext m_renderedText`, pane bounds, offset, and limit and dispatches slot 2 with destination `GrafPort` receiver in `ecx`, source context, both rectangles, mode `0`, `NULL` palette, and `NULL` options. This matches accepted `SurfaceSpriteBlitProc g_pfnBlitSprite` and does not support a scalar flags parameter or caller-specific global name.
- Fill precedes blit, and there is exactly one call to each slot. UID0004WS adds consumer evidence only: Surface retains both globals/typedefs and installed callbacks, while [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) owns the paint method.
- The parallel made-by paint child [UID:0004MD][0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame](by-memory/0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame.md) has the same callback contract under a separate class identity; neither body is a table target.

## UID0002YF Compat Provider Under Slot-7 Declaration - 2026-08-04

- The existing formal declaration remains authoritative and unchanged: `SurfaceFillRectProc` is `void (__thiscall *)(GrafPort *port, const RectBounds *bounds)`; `Surface.cpp` owns the single `SurfaceFillRectProc g_pfnFillRect` definition and `Surface.h` owns the single `extern` declaration. UID0002YF is file-local provider code and must not add another typedef, global definition, extern, or header declaration.
- Compat target `0x004be680` has no ordinary callers but is loaded at `0x00558723` and directly stored at `0x00558bc6`; both setup routes select slot 7. The physical slot at `0x0069b3fc` remains four zero-initialized bytes before setup and has 206 dispatch xrefs. These facts establish live indirect dispatch rather than dead code.
- `SoftwareRenderCompatFillCallback` receives GrafPort plus `const RectBounds *`, clips the request, computes a 16-bit RGB555 destination from the embedded surface context, maps through the global current palette, preserves both color-map calls, and handles copy, color-key copy, weighted blend, and color-key weighted blend. Raw-color gates apply to modes 1 and 3; alpha is converted to a byte-wrapped 32-based destination weight; RGB555 blending passes destination first and fill second.
- RGB565 target `0x004c4380` remains the paired provider. Both implementations share this declaration and storage, but each exact child owns its body. The compat child uses global-current-palette behavior and exact odd-tail loops; provider-specific RGB565 fallback and mode-3 overrun behavior are not generalized into the table contract.
- The callback-table owner/emitter route remains UID0000TN through UID0000OC. The physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) page remains a covered-by storage description and does not duplicate this semantic formal or either provider body.

## Ownership Decision

Keep this table with [UID:0000OC][Surface](by-file/Surface.md) or a neighboring `render/SurfaceBlitters.cpp` / `render/SoftwareRenderDispatch.cpp` source candidate. Do not move it into `AlertPanes`, fitting-room controls, map tiles, or a specific image library based only on a generated alias.

`SoftwareBlend16` owns reusable pixel/span math. This callback table owns runtime selection and dispatch to the larger 555/565 blit families that consume that math.

## Open Questions

- Exact original symbol and public typedef spellings remain stripped. The twelve `g_pfn*` names and semantic interfaces above are the accepted descriptive source model. Slot 2's complete `0x20` options ABI is now closed; callers that do not initialize every target-read field must preserve those exact partial writes rather than impose a common zero-initialization policy.
- Source shape is resolved to twelve declaration-ordered fixed globals rather than a pointer/indexed runtime table object. `SurfaceRenderCallbackTable` remains a documentation grouping, not an asserted original struct symbol.
- How the RGB555/compatibility path maps to the client old-rendering-mode option.
- Formerly orphaned writes around `0x0055874a` / `0x00558753` are shared stores inside the exact UID00039V function; complete bounded decode and branch targets resolve them as real code, not stale analysis artifacts.

## Score Rationale

### 2026-08-04 Slot-5 Alpha Lookup Closure

- Slot 5 is now exact `SurfaceAlphaLookupBlitProc g_pfnBlitAlphaLookup`, not a byte-result physical direction. Its ABI is logical `void __thiscall` with `GrafPort *port` in ECX and three stack pointers: `const IntAlphaSurface *alphaSurface`, `const RectBounds *sourceBounds`, and `const RectBounds *destinationBounds`.
- Provider refs are compat/RGB555 `0x004bdf40` at `0x005586fe` / `0x00558bb2` and RGB565 `0x004c3cf0` at `0x005587ec` / `0x00558ece`. The live MapPane consumer calls the fixed slot at `0x0050a267`; `0x00558791` is the shared retained-store route.
- Both providers use the exact 0x14-byte `AlphaSurfaceBufferView` copied by `IntAlphaSurface::GetBufferInfo`, the same clip/source-translation contract, and shared lookup roots. They remain separate provider bodies because their bulk helpers and scalar tails implement RGB555 versus RGB565 packing.
- `g_surfaceColorLookup5Bit` is an external `unsigned char **` root with 32 rows of 256 alpha entries for five-bit channels. `g_surfaceColorLookup6Bit` is an external `unsigned char **` root with 64 rows of 256 entries for the six-bit green channel. UID0000TN owns the sole declarations and definitions; physical lookup/storage pages retain evidence without duplicating source storage.
- The generated `RankingEventListPane` aliases, raw `dword_69B3D8` / `dword_69B3DC` / `dword_69B3F4`, byte-return inference, and MM1 ABI inference are historical tool artifacts. They are retained in older change history but rejected from source-facing declarations.
- Completion/confidence rises from `93/94` to `94/95`: slot 5 now has an exact typedef, typed global, providers, consumer, lookup-root declarations, and source placement. Remaining uncertainty is limited to stripped private spellings and later compile/binary comparison.

| Score | Rationale |
| --- | --- |
| Completion `94` | The page documents the aggregate identity, exact storage range, all twelve semantic globals/interfaces, both target families, raw and inline initialization, high-traffic dispatch evidence, alias rejection, fixed-global source shape, Surface ownership, and exact formal typedef/definition closure for slots 0, 1, 2, 3, 4, 5, 6, 7, 9, and 11. It remains below final-audit range because remaining private lexical spellings and the product-level legacy/new-rendering option relationship are not recovered. |
| Confidence `95` | Current and historical IDA evidence confirms bytes, bounds, per-slot xref counts, both initializer copies, all 24 target identities, broad caller fanout, and the complete slot-2 options field/consumer ABI. Remaining uncertainty is lexical or belongs to independently bounded slots; it does not undermine the emitted shared declarations. |

## Cross-References

- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:0002PF][0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback](by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:00039V][0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks](by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:000166][0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md)
- [UID:0004H4][0x004b98f0-0x004b990c.GrafPortLineTo](by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md)
- [UID:0004H5][0x004b9910-0x004b997e.GrafPortDrawSprite](by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md)
- [UID:0004H6][0x004b9980-0x004b99b1.GrafPortRenderTileFrame](by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md)
- [UID:0004H7][0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer](by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md)
- [UID:00035C][0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw](by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:0004L8][0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint](by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md)
- [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md)
- [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md)
- [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)

## 2026-07-23 UID0003PJ Slot-1 Formal Closure

- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) supplies the missing source-quality consumer proof for callback slot 1. Its streak loop calls `0x0069b3e4` exactly 18 times with the current `RainingLayerPane`/GrafPort receiver in ECX and two signed integer deltas on the stack; the installed compat `0x004bb9b0` and RGB565 `0x004c0850` targets return with `retn 8`.
- The exact source contract is therefore `typedef void (__thiscall *SurfaceDrawLineDeltaProc)(GrafPort *port, int deltaX, int deltaY);` and the one semantic storage declaration is `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta;`. It is emitted here beside the already accepted `SurfaceDrawPixelProc g_pfnDrawPixel` and `SurfaceFillRectProc g_pfnFillRect`.
- Rain preserves signed operation order before dispatch:
  - streak start uses inherited `MoveTo(2 * (17 * x / 15), 2 * (15 * y / 13))`;
  - slot 1 receives `2 * (-17 * length / 15)` and `2 * (30 * length / 13)`;
  - signed short table fields and signed division/truncation are required, and the current frame byte is reloaded rather than cached across callbacks.
- Physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) remains blank formal evidence. It must not emit a second typedef or definition set. Runtime initialization remains owned by [UID:00039V][0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks](by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md).
- Final original-style source requires a canonical `Surface.h` with matching slot-0/1/7 typedefs and `extern` declarations for all three globals, while `Surface.cpp` owns exactly one definition of each. The current validator route for this UID is `NexusTK/render/Surface.cpp`; it does not create `Surface.h`, so the managed block is a same-translation-unit ABI/storage closure rather than a claim of current cross-TU standalone compilation.
- This change remains deliberately narrow. It does not make all twelve callback typedefs final and this semantic table does not duplicate callback bodies. [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) now supplies the source-ready RGB565 line body through its own exact child; only `SoftwareRenderCompatLineCallback` remains body-empty among the two installed slot-1 targets.

## 2026-07-24 UID0002PJ Slot-1 Provider Closure

- Historical 2026-07-24 pre-Gate2B state: slot `0x0069b3e4` is a four-byte process-global callback pointer by declaration order, four-byte slot spacing, dword initializer writes, indirect `jmp dword ptr` consumers, and the accepted four-byte `SurfaceDrawLineDeltaProc` source type. That earlier readback found `g_pfnDrawLineDelta` and 26 references but did not expose attached declaration/tinfo. The 2026-07-29 UID0001DV readback below supersedes only that pending-tinfo statement; the ordinary source declaration above remains the accepted one-definition route.
- [UID:0002PJ][0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback](by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md) closes the RGB565 provider body at `0x004c0850-0x004c0f7a`: it consumes the GrafPort receiver, maps `m_drawColor` through the current palette, clips inclusive horizontal/vertical spans, uses packed-pair and scalar RGB565 blending, preserves the vertical mode-3 destination-zero exception, renders general clipped lines with strict-tie all-octant Bresenham, and advances the cursor by the original deltas on every path.
- The body remains on the exact child page and emits after this typedef/global declaration through Surface. Physical UID0001PI remains blank to avoid duplicate storage, and broad UID00016L remains a non-emitting family index.
- Historical source representations using `dword_69B3E4` or treating both line targets as body-empty are superseded. UID0002PG remains the separate body-empty RGB555/compat provider and requires its own source pass.

## Changes

- 2026-08-22 B003 UID0000IF support callback: preserved `94/95`, UID0000OC owner/emitter, position `20`, and both formal channels byte-for-byte; added only the exact ConnStatusPane invalid-frame clear-path consumer of slot 7.

- 2026-08-16 B006 UID00011R slot-7 consumer closure:
  - Added RectangleControlPane::OnPaint as the exact direct-global `g_pfnFillRect(this, &bounds)` consumer, including its bounds setup, ECX receiver, single pointer argument, and implementation-only Surface include.
  - Preserved UID0000TN/UID0000OC ownership, `94/95`, the existing formal typedef/global/extern declarations, providers, initializer routes, and every unrelated slot. Rejected an invented GrafPort member without changing GrafPort documentation or source.

- 2026-08-14 B001 UID0002YO slot-11 source synchronization:
  - Preserved `94/95`, owner/emitter UID0000OC, reconstructable true, the existing `SurfaceTransferPixelsProc` typedef, the single `g_pfnTransferPixels` declaration/definition, and the semantic/physical storage split.
  - Marked the RGB565 provider source-ready and added its exact refs, masks, 25-step formulas, packed-pair and odd-tail loops, zero-count/no-clipping behavior, and 0/no-op and 24/clear endpoints without duplicating provider source or callback storage on this page.

- 2026-08-11 B007 UID0002YJ slot-11 source synchronization:
  - Preserved `94/95`, owner/emitter UID0000OC, reconstructable true, and the semantic/physical storage split.
  - Added exact `SurfaceTransferPixelsProc`, one `g_pfnTransferPixels` definition and extern, paired providers, five slot refs, two ScreenPane consumers, ignored-return rationale, 25-step semantics, and declaration/definition source order.

## 2026-07-29 UID0001DV Slot-1 Current IDA-State Synchronization

- Current names/global catalogs contain `g_pfnDrawLineDelta`, and the applied storage type is `SurfaceDrawLineDeltaProc`. The prior 2026-07-24 missing-tinfo statement is retained only as dated history.
- IDA's containing item remains a one-byte unknown item `[0x0069b3e4,0x0069b3e5)` with blank item-head name, while the four-byte storage `[0x0069b3e4,0x0069b3e8)` is zero-initialized and current Hex-Rays may still render `MEMORY[0x69B3E4]`. Those views do not contradict the catalog name/type or typed source declaration.
- Twenty-six data xrefs include `GrafPort::LineTo`, frame drawing, weather drawing, and [UID:0004YA][0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint](by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md) CScrollBarBackPane::OnPaint. Static zero is expected because renderer setup installs the callback at runtime.
- Supervisor Gate 2B applied address-regular comment `Runtime-installed GrafPort relative-line renderer: (port, deltaX, deltaY).` at `0x0069b3e4`. Address-repeatable remains absent; function-regular/function-repeatable remain absent and unavailable because the item is not a function. The one-byte item head remains blank and non-code/non-data, four-byte storage remains `00 00 00 00`, catalog name/type remain `g_pfnDrawLineDelta` / `SurfaceDrawLineDeltaProc`, Hex-Rays may still render `MEMORY[0x69B3E4]`, and all 26 xrefs plus adjacent slots are unchanged.
- No ordinary metadata, owner/emitter, formal `Surface.h`/`Surface.cpp` declaration-definition, or callback-provider route changes. Historical `dword_69B3E4`, pending-tinfo, and body-empty-both-provider statements remain superseded evidence rather than current truth.

- 2026-07-29 B007 accepted UID0001DV support update synchronized slot 1's current catalog/type/item-head/Hex-Rays distinction. Supervisor Gate 2B then applied and saved the exact address comment without changing `93/94`, owner/emitter/formals, storage classification, adjacent slots, or one-definition source policy. Saved IDB SHA256: `AEBDA49CA5FEF361C301E94AE6CD06168CCC6000E50DA805E167BD018F658E3C`.

- 2026-07-28 B001 UID0004I4 slot-9 source-quality synchronization:
  - Preserved the concurrently accepted `93/94` score and H-declarations/CPP-definitions structure, owner/emitter, position, existing callback declarations, and unresolved-slot caps.
  - Added the exact slot-9 CPP global, H typedef/extern, provider/initializer refs, channel ABI, and UID0004I4 `RGBTRIPLE` consumer evidence. Physical UID0001PI remains storage evidence and emits only covered-by source.

- 2026-07-28 B002 UID0002TE slot-6 closure:
  - Promoted `92/93 -> 93/94`, added exact `SurfaceBitmaskBlitProc` and `g_pfnBlitBitmask`, moved all callback declarations/externs to formal H, and reduced formal CPP to the header include plus global definitions.
  - Resolved the slot-6 return/calling convention, provider names, raw mask/destination-bounds contract, initializer refs, consumer fanout, canonical GrafPort fields, four modes, and pixel-format-specific blend dependencies.
  - Preserved all unresolved sibling slot aliases/signatures and the complete prior callback-table history.

- 2026-07-24 B005 UID0004WS bounded consumer synchronization:
  - Preserved `89/86`, Surface owner/emitter, the complete callback declarations, all twelve slots, provider/initializer evidence, and every unrelated consumer.
  - Added generic ScrolledTextControlPane paint as an exact slot-7 `FillRect` and slot-2 `g_pfnBlitSprite` consumer with fill-before-blit order, exact argument/null contract, and no ownership transfer.

- 2026-07-24 B003 UID0002TF slot-3 declaration synchronization:
  - Raised `91/91` to `92/93`, preserved Surface owner/emitter and position `20`, and extended the complete managed declaration block with `DLPalette`, `EPFTileContext`, exact `SurfaceFillRleProc`, and the single `g_pfnFillRle` definition.
  - Promoted compat UID0002TB and RGB565 UID0002TF to source-ready providers with the exact source-void GrafPort-receiver/five-argument ABI, paired initializer stores, eleven-slot-xref liveness, clipping/palette/RLE contract, four mode semantics, and scalar-source/compiler-SIMD boundary.
  - Preserved all unrelated slots and historical aliases; physical storage remains non-emitting through UID0001PI and provider bodies remain on their exact child pages.

- 2026-07-24 B002 UID0002PJ slot-1 provider synchronization:
  - Preserved `91/91`, owner/emitter UID0000OC, position 20, the complete managed typedef/global set, all twelve slots, both initializer routes, and unrelated provider/consumer evidence.
  - Updated slot 1 with the source-ready RGB565 provider, exact behavior and one-definition route, while retaining the compat provider as body-empty and recording the pending supervisor IDA tinfo attachment separately from ordinary source truth.

- 2026-07-19 B004 UID00030C slot-7 declaration synchronization:
  - Preserved `89/86`, owner/emitter UID0000OC, position 20, all twelve slots, both provider families, initialization history, all unrelated consumers, and broader lexical caps.
  - Extended the complete managed value only with `RectBounds`, exact `SurfaceFillRectProc`, and `g_pfnFillRect`, while retaining the existing slot-0 declaration and adding no callback body.
  - Added UID00030C and UID0001JR as exact slot-7 consumers and rejected stale fill-or-invalidate/lock/raw aliases for source-facing C++.

- 2026-07-16 B001 UID0002PI slot-0 declaration synchronization:
  - Preserved `89/86`, owner/emitter UID0000OC, reconstructable true, all twelve slots, all unrelated callback targets/consumers, and the complete current table evidence.
  - Set emitter position `20` and inserted the accepted `GrafPort` forward declaration, `SurfaceDrawPixelProc` typedef, and single `g_pfnDrawPixel` definition.
  - Marked both compat UID0002PF and RGB565 UID0002PI targets source-ready; documented exact receiver/x/y/colorIndex/void ABI, three setup/storage refs, twelve dispatch refs, fixed-global source shape, and no duplicate target bodies.
  - This update resolves only slot 0. Broader slot declaration debt and original spellings remain explicit confidence limits.

- 2026-07-14 B003 UID0002Y1 slot-4 support synchronization:
  - Preserved `89/86`, Surface owner/emitter, exact twelve-slot storage, blank position/formal, all other slots, initializer routes, and broader typedef/name caveats.
  - Sharpened slot 4 to the exact void GrafPort receiver plus EPFTileContext, source/destination rectangles, mode, float tint, integer row offset, float vertical scale, and float horizontal shear contract from both concrete callback targets.
  - Added retained RidingImageLib RenderRiding and modeled MonsterImageLib RenderMonster as exact consumers, including mode `3`, row offset zero, fixed centered `1.5f/0.0f`, and active MapPane tint/projection inputs. Caller-specific ownership and raw-address source forms remain rejected.

- 2026-07-13 B004 UID00039V initializer/source-shape synchronization:
  - Preserved `89/86`, owner/emitter metadata, storage range, blank position, and blank formal C++; no callback child score/body changed.
  - Added UID00039V as the exact out-of-line initializer and UID00039W as its inline source-call host, all twelve semantic `g_pfn*` names/interfaces, all 24 paired targets, exact flag/failure behavior, fixed-global rather than pointer-table source shape, zero-xref versus inline-liveness distinction, and compiler/source boundary.
  - Corrected slot 7 so raw `0x00558811` selects RGB565 `0x004c4380`, raw compat `0x004be680` is loaded at `0x00558723`, raw shared store is `0x00558770`, and inline RGB565 store is `0x00558ee2`.

- 2026-07-13 B002 UID0002YK slot-7 provider synchronization:
  - Score, owner/emitter, table range, and blank formal C++ remain unchanged at `89/86`.
  - Added exact slot-7 ABI, source-facing FillRect role, UID0002YK `90/92`
    source-ready status/behavior, two setup routes, zero image storage followed by
    runtime assignment, and 206-ref liveness.
  - Historical all-`ff`, 131-function, `g_pfnLockSurface`, and `RefreshPaneRegion`
    forms are explicitly superseded or rejected without finalizing unrelated slots.

- 2026-07-13 B005 UID00011U slot-7 consumer synchronization:
  - Score, metadata, table ownership/storage, installed targets, aliases, and blank formal C++ remain unchanged at `89/86`.
  - Added UID0004L8 as an exact consumer that sets draw color zero and invokes slot 7 over inherited `m_bounds`, supporting source-facing `FillRect(&m_bounds)` while rejecting generated `g_pfnLockSurface` wording for this callsite.
- 2026-07-13 B004 UID0002EV slot-7 support synchronization:
  - Score, metadata, table ownership/storage, installed targets, xref totals, aliases, and blank formal C++ remain unchanged at `89/86`.
  - Added the three exact ChattingPane::OnPaint calls: current enabled/disabled `FillRect(&m_bounds)` after draw color zero and legacy `FillRect(&m_contentRect)` after draw color 143.
  - Rejected historical ChattingPane `RefreshPaneRegion` and generated `g_pfnLockSurface` spellings while retaining broader table-wide name/signature uncertainty.
- 2026-07-13 B001 UID00011J slot-7 support sync:
  - Score and metadata unchanged at `89/86`; formal C++ remains blank because this page still covers the complete shared table rather than one finalized declaration.
  - Added UID0004JW as exact EPF slot-7 consumer: virtual OnPaint, receiver `this`, rectangle `m_bounds`, prior draw color zero, installed compat/RGB565 fill targets, and source-facing `FillRect(&m_bounds)`; historical load/lock naming is retained only as rejected provenance.

- 2026-07-06 B001 UID0004HT slot-8 consumer sync:
  - Score unchanged at `89/86`; formal C++ remains blank because final table declaration style and typedef spelling remain open.
  - Added descriptive slot-8 alias `g_pfnExpandPixel` / `SurfaceExpandPixelProc`, recorded [UID:0004HT][0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw](by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md) as the DLPalette consumer at `0x00542b8c`, and tied the provider targets to RGB555 `0x004bed80` and RGB565 `0x004c46d0`.
  - Evidence: accepted B001 report and existing slot-8 child/provider docs; Surface remains provider context and UID0004HT remains DLPalette-owned.

- 2026-07-04 B010 UID000165 implementation callback:
  - Score unchanged at `89/86`.
  - Added UID000165 split-child callback consumers: `GrafPort::LineTo` as slot-1 consumer, `GrafPort::DrawSprite` and `GrafPort::RenderTileFrame` as slot-2 consumers, and preserved UID00035C as slot-3 raw consumer. UID000165 parent is now non-emitting, so the old empty-marker route is no longer a table concern.
  - Evidence: accepted B010 report, MCP session `73c77998`, command `145` for line delta, command `109` for alpha/source-context slot-2 dispatch, command `108` for palette-resolving slot-2 dispatch, and xref counts `26` / `114` / `11` for slots 1/2/3.

- 2026-07-04 B011 UID0002PF slot-0 source-ready sync:
  - Score unchanged at `89/86`; formal C++ remains blank for the global table because final declaration style and table/typedef spelling remain open.
  - Updated slot 0 / `dword_69B3E0` from open low-level pixel callback wording to source-ready compat target status: UID0002PF emits `SoftwareRenderCompatPixelCallback` through Surface, while the RGB565 peer remains separate.
  - Evidence: accepted B011 report, MCP session `73c77998`, exact target range/profile, zero callers, target refs `0x00558745`/`0x00558b80`, 15 slot refs, eleven-byte padding, receiver-in-`ecx` callback direction, `GrafPort` draw fields and surface-context pointer math, clip/palette helpers, direct/transparent/blend mode cases, `BlendRgb555` dependency, generated empty-marker cause, and rejected Ranking/GrafPort-normal-method/SurfaceRenderCallbackTable-body/SoftwareBlend16/no-owner routes.

- 2026-07-04 B012 UID0002TI slot-6 source-ready sync:
  - Score unchanged at `89/86`; formal C++ remains blank for the table because final declaration style is still open.
  - Updated slot 6 / `dword_69B3F8` with current RGB565 target source-ready status: UID0002TI emits `BlitRgb565BitmaskCallback` through Surface, while the compat target remains separate RGB555 behavior.
  - Evidence: accepted B012 report, MCP session `73c77998`, exact target range/profile, zero direct callers, two target refs, twelve slot refs, local switch table, packed 1bpp traversal, palette-mapped color fields, mode cases, `BlendRgb565Pixel` dependency, and rejected BalloonObjectPane/RGB565-aggregate/SoftwareBlend16 ownership.

- 2026-07-02 B005 UID00041U slot-2 support repair:
  - Score unchanged. Updated slot 2 from open/scalar final-argument wording to accepted `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` support: `int` return, destination draw receiver in `ecx`, six stack arguments, and nullable `const SurfaceSpriteBlitOptions *options`.
  - Evidence: UID00041U passes a nonzero options pointer, writes only selector `+0` and conditionally palette byte `+8`, while installed compat/RGB565 slot targets dereference the final argument and RGB565 option `6` reads `+0x1c`. Zero final-argument callers such as `GrafPort::DrawTiledBackground`, `RenderTileFrame`, and `GrafPort::BlitSurface` are now documented as passing `NULL` options; the older scalar `int flags` wording is rejected for nonzero UID00041U.
- 2026-07-02 B003 UID00041R slot-2 support sync:
  - Score unchanged. Added UID00041R as a direct slot-2 consumer and recorded its option-family evidence on top of the already-present B005 typedef repair.
  - Evidence: UID00041R proves nullable options, kinds `1`/`2`/`3`, selector `+0x00`, alpha `+0x04`, palette/tint `+0x08`, and secondary shift `+0x1c`. Its option kind `3` writes alpha and palette/tint but not `+0x1c`, while RGB565 target `0x004c0f80` reads `+0x1c` for kind `3` at `0x004c189d`; broader RGB565 option-family reads at `0x004c138a` and `0x004c1eee` stay in support context. This keeps `SurfaceSpriteBlitOptions` opaque and rejects a concrete emitted field/init model for UID00041R.
- 2026-06-29 B005 slots 8-10 first-draft implementation-name sync:
  - Score unchanged at `89/86`; formal C++ remains blank because the table declaration style and per-slot typedefs are still open.
  - Slots 8-10 now have first-draft leaf implementation names in their exact child pages: `ExpandRgb555Pixel` / `ExpandRgb565Pixel` for `dword_69B400`, `PackRgb555Pixel` / `PackRgb565Pixel` for `dword_69B404`, and `TransformRgb555PaletteColor` / `TransformRgb565PaletteColor` for `dword_69B408`.
  - Adjacent lookup-root names [UID:00029V][0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers](by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md) `g_surfaceColorLookup5Bit` and `g_surfaceColorLookup6Bit` are first-draft descriptive names for `0x0069b3d8` / `0x0069b3dc`; they support the slot-10 transform leaves but do not settle this table's final source declaration shape.
  - Source-shape note: these names are inferred and lane-oriented. The callback table itself still should not emit C++ in this pass because evidence supports several possible source forms: separate callback globals, a dispatch struct, or a function-pointer table with typedefs.
- 2026-06-28 B007 UID00035C slot-3 consumer sync:
  - Score unchanged at `89/86`.
  - Evidence: recorded [UID:00035C][0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw](by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md) as a consumer of `dword_69B3EC` at `0x004b99e3`, not as a table target or initializer. Current MCP keeps slot-3 target refs at `0x004bd420` (`0x00558728`/`0x00558b9e`) and `0x004c3190` (`0x00558816`/`0x00558eba`), while UID00035C has no modeled function, no inbound route, and blank emitter/C++ on its exact page.
- 2026-06-26 B014 PaletteLib filter-helper support sync:
  - Score unchanged.
  - Evidence: [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md) now records `PaletteLib::UpdatePaletteFilterTables` as a concrete slot-10 / `dword_69B408` consumer, using descriptive `g_pfnTransformPaletteColor` / `SurfacePaletteTransformProc` wording for PaletteLib source prose while preserving this page's Surface callback-table ownership.
- 2026-06-21 B012 SurfaceDrawTilePresentation slot-11 support sync:
  - Score unchanged.
  - Evidence: [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) now documents slot 11 / `dword_69B40C` as a block-transfer callback dependency called by the retained no-entry `DrawTileSurface` helper, while rejecting any callback-table-target route to `0x005583a0`.
- 2026-06-21 B008 BalloonObjectPane support sync:
  - Score unchanged.
  - Evidence: [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) now records `PaintBubble` callback dependencies on slots `0x0069b3e4`, `0x0069b3f8`, and `0x0069b3fc`; this adds another concrete consumer while preserving SurfaceRenderCallbackTable ownership.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) now records `OnPaint` as a concrete slot-7 pane-region preparation/fill-invalidate consumer before human/monster/item image-library dispatch.
- 2026-06-20 B001 OverlayMovingImageEffecter slot-2 support sync:
  - Score unchanged.
  - Evidence: [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) documents `RenderTileFrame` at `0x004b9980` as a shared wrapper whose fifth argument is a palette/overlay lookup key and whose sixth argument is forwarded as zero. B005 2026-07-02 supersedes the old flags/options phrasing by treating that zero as `NULL` options. The wrapper then dispatches through `dword_69B3E8`, strengthening `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` as the slot-2 descriptive alias and rejecting the caller-biased fitting-room label.
- 2026-06-18 B002 DrawTiledBackground slot-2 typing update:
  - Score unchanged.
  - Evidence: [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) dispatches every repeated tile through `dword_69B3E8` with destination `GrafPort` in `ecx`, whole `FrameDrawRecord`, source rect at descriptor `+0x10`, destination rect, mode byte `GrafPort+0x70`, named palette pointer, and zero final argument. B005 2026-07-02 treats that zero as `NULL` options and accepts the slot-2 typedef direction, while the concrete options struct remains open.
- 2026-06-18 B002 GrafPortDrawRectFrame slot-1 typing update:
  - Score unchanged.
  - Evidence: [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) confirms slot `0x0069b3e4` is a line-delta callback rather than a rectangle-frame-specific or sprite-blit callback. The method seeds the GrafPort draw cursor, dispatches four signed deltas through `dword_69B3E4`, and relies on the callback target to advance the live cursor. This strengthens `g_pfnDrawLineDelta` / `DrawLineDelta` as descriptive aliases while keeping original typedef spelling open.
- 2026-06-18 B003 SurfaceSpriteBlitHelper slot-2 typing update:
  - Score unchanged at `89/86`.
  - Evidence: [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) confirms slot `0x0069b3e8` is used as a sprite/surface blit callback with destination GrafPort in `ecx`, source [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), source/destination rectangle arguments, mode, palette/null, and a zero final argument now treated as `NULL` options. B005 2026-07-02 supersedes the earlier `int flags` support wording for nonzero callers while preserving the broader rejection of feature-specific names.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents the storage range, callback slots, initializer behavior, broad caller evidence, render ownership, alias warnings, and open questions; exact slot names and old/new render-mode mapping remain unresolved.
- 2026-06-05: Marked reconstructable and attached to [UID:0000OC][Surface](by-file/Surface.md).
  - Reason: live IDA MCP recheck confirms this source-declared render dispatch table is installed by surface initialization and dispatches shared surface/render callbacks across many callers, making the Surface source root the best current parent.
- 2026-07-08 B011 UID00029U adjacent-flag support sync:
  - Score and formal C++ unchanged at `89/86`; this page continues to document callback-table storage with blank C++ until table declaration style and typedef spellings are final.
  - Added adjacent flag names `g_surfaceUses32BitPresentation` and `g_surfaceUsesRgb565Pixels`, and historicalized the earlier all-`ff` neighborhood byte statement for the UID00029U window based on current zero-byte MCP evidence.
  - Evidence: accepted B011 report and updated UID00029U target; current MCP session `b001-0002wl-readonly` reports zero bytes at `0x0069b3d4-0x0069b3d7`, D4 seven refs, D5 sixteen refs, and D6/D7 zero refs. Callback-table slot bounds, xref counts, and no-code disposition are unchanged.
- 2026-06-07 A007 Batch 041 parent-gate refresh:
  - Before: `88/82`; the page was useful as the global parent for [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) but did not clear the corrected `85/85` confidence gate.
  - After: `89/86`; the global parent now clears the gate and remains attached to [UID:0000OC][Surface](by-file/Surface.md).
  - Evidence: live IDA reconfirmed the then-recorded neighborhood bytes, exact table bounds, per-slot xref counts, and broad caller fanout for `0x0069b3e8` and `0x0069b3fc`; the `Surface` file page now records `88/85` with direct nearby render-global evidence. B011's 2026-07-08 UID00029U pass supersedes the byte-value portion for `0x0069b3d4-0x0069b3d7` with zero bytes.
- 2026-06-17 B002 raw-island support update:
  - Score unchanged at `89/86`.
  - Evidence: recorded [UID:0003XE][0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw](by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md) as a dependency caller of slot `dword_69B3E8`, not a callback-table target or ownership route. B005's later retry reroutes the helper itself to [UID:00005V][GrafPort](by-class/GrafPort.md) while preserving this dependency-only callback-table role.
- 2026-06-19 B005 pixel-format helper cross-reference:
  - Score unchanged.
  - Evidence: [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) and [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) now document `g_surfaceUsesRgb565Pixels` as the flag adjacent to this table. The conversion helper is explicitly rejected as a callback-table slot because it has one ordinary caller and no table registration edge.
- 2026-06-19 B005 ProgressBarControlPane support update:
  - Score unchanged.
  - Evidence: [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) calls slot `0x0069b3fc` twice as an active rectangle fill wrapper after draw colors `1` and `143`; support docs should prefer descriptive `FillRect` wording in control-source C++ while retaining raw slot names in evidence.
- 2026-06-20 B004 SeparatorMenuItem support update:
  - Score unchanged.
  - Evidence: [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) calls slot `0x0069b3fc` as the rectangle fill/invalidate step for a centered separator band after active draw color `0x80`; this strengthens slot-7 `FillRect`/`fillOrInvalidate` descriptive naming and rejects `g_pfnLockSurface` for menu-source prose.
- 2026-08-11 B008 UID0002TG slot-4 source closure:
  - Kept metadata at `94/95` with unchanged Surface owner/emitter route and position `20`.
  - Added exact `SurfaceScaledRleTintProc`, `extern g_pfnBlitScaledRleTint`, and the single global definition; expanded slot 4 with both providers, the exact receiver-plus-eight-argument contract, twenty-one-reference dispatch role, signed EPF mask grammar, and RGB555/RGB565 destination-transform distinction.
  - Kept physical [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md) non-emitting and kept provider bodies on their exact by-memory pages to avoid duplicate storage or code.
  - Gate 2A repair corrected the retained compat assignment from unsupported `0x00558739` to `0x0055873b`; the initializer inventory, physical-table matrix, compat child xrefs, and compat aggregate independently agree on `0x0055873b`, while no current by-* evidence supports `0x00558739`.
