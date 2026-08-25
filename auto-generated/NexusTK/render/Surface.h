// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OC
// Source by-file doc: by-file/Surface.md
// UID:00029U | by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md | Completion:90 | Confidence:94
extern bool g_surfaceUsesRgb565Pixels;

// UID:0000TN | by-global/SurfaceRenderCallbackTable.md | Completion:94 | Confidence:95
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
