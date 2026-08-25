// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OC
// Source by-file doc: by-file/Surface.md
// UID:00029U | by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md | Completion:90 | Confidence:94
static bool g_surfaceUses32BitPresentation;
bool g_surfaceUsesRgb565Pixels;

// UID:00029V | by-memory/0x0069b3d8-0x0069b3e0.SurfaceAlphaLookupTablePointers.md | Completion:93 | Confidence:95
// Emitted source for these globals is covered by [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).

// UID:0000TN | by-global/SurfaceRenderCallbackTable.md | Completion:94 | Confidence:95
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

// UID:0002YG | by-memory/0x004bed80-0x004bedaa.SoftwareRenderCompatRgb555ExpandCallback.md | Completion:90 | Confidence:92
static void ExpandRgb555Pixel(unsigned short pixel,
                              unsigned char *low,
                              unsigned char *middle,
                              unsigned char *high)
{
    *low = static_cast<unsigned char>(pixel << 3);
    *middle = static_cast<unsigned char>((pixel >> 2) & 0xf8);
    *high = static_cast<unsigned char>((pixel >> 7) & 0xf8);
}

// UID:0002YH | by-memory/0x004bedb0-0x004bedde.SoftwareRenderCompatRgb555PackCallback.md | Completion:90 | Confidence:92
static unsigned short PackRgb555Pixel(unsigned char high,
                                      unsigned char middle,
                                      unsigned char low)
{
    return static_cast<unsigned short>(((high >> 3) << 10) |
                                       ((middle >> 3) << 5) |
                                       (low >> 3));
}

// UID:0002YI | by-memory/0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md | Completion:90 | Confidence:91
static unsigned short TransformRgb555PaletteColor(unsigned short pixel,
                                                  unsigned char strength)
{
    const unsigned int low =
        g_surfaceColorLookup5Bit[pixel & 0x001f][strength];
    const unsigned int middle =
        g_surfaceColorLookup6Bit[(pixel >> 5) & 0x001f][strength];
    const unsigned int high =
        g_surfaceColorLookup5Bit[(pixel >> 10) & 0x001f][strength];

    return static_cast<unsigned short>(low | (middle << 5) | (high << 10));
}

// UID:0002YL | by-memory/0x004c46d0-0x004c46fa.SoftwareRenderRgb565ExpandCallback.md | Completion:90 | Confidence:92
static void ExpandRgb565Pixel(unsigned short pixel,
                              unsigned char *low,
                              unsigned char *middle,
                              unsigned char *high)
{
    *low = static_cast<unsigned char>(pixel << 3);
    *middle = static_cast<unsigned char>((pixel >> 3) & 0xfc);
    *high = static_cast<unsigned char>((pixel >> 8) & 0xf8);
}

// UID:0002YM | by-memory/0x004c4700-0x004c472e.SoftwareRenderRgb565PackCallback.md | Completion:90 | Confidence:92
static unsigned short PackRgb565Pixel(unsigned char high,
                                      unsigned char middle,
                                      unsigned char low)
{
    return static_cast<unsigned short>(((high >> 3) << 11) |
                                       ((middle >> 2) << 5) |
                                       (low >> 3));
}

// UID:0002YN | by-memory/0x004c4730-0x004c478a.SoftwareRenderRgb565PaletteTransformCallback.md | Completion:90 | Confidence:92
static unsigned short TransformRgb565PaletteColor(unsigned short pixel,
                                                  unsigned char strength)
{
    const unsigned int low =
        g_surfaceColorLookup5Bit[pixel & 0x001f][strength] & 0x1f;
    const unsigned int middle =
        g_surfaceColorLookup6Bit[(pixel >> 5) & 0x003f][strength] & 0x3f;
    const unsigned int high =
        g_surfaceColorLookup5Bit[pixel >> 11][strength];

    return static_cast<unsigned short>(low | (middle << 5) | (high << 11));
}

// UID:00016H | by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md | Completion:90 | Confidence:91
struct LineClipPoint {
    int y;
    int x;
};

static bool __stdcall ClipLineParameter(int delta, int edgeDistance, float *enter, float *leave);

static bool __stdcall ClipLineToRect(LineClipPoint *start,
                                     LineClipPoint *end,
                                     const RectBounds *bounds)
{
    if (PointInRect(start->y, start->x, bounds) &&
        PointInRect(end->y, end->x, bounds)) {
        return true;
    }

    const int deltaY = end->y - start->y;
    const int deltaX = end->x - start->x;
    float enter = 0.0f;
    float leave = 1.0f;

    if (!ClipLineParameter(deltaX, bounds->left - start->x, &enter, &leave) ||
        !ClipLineParameter(-deltaX, start->x - bounds->right + 1, &enter, &leave) ||
        !ClipLineParameter(deltaY, bounds->top - start->y, &enter, &leave) ||
        !ClipLineParameter(-deltaY, start->y - bounds->bottom + 1, &enter, &leave)) {
        return false;
    }

    if (leave < 1.0f) {
        end->x = start->x + static_cast<short>(static_cast<int>(static_cast<float>(deltaX) * leave));
        end->y = start->y + static_cast<short>(static_cast<int>(static_cast<float>(deltaY) * leave));
    }

    if (enter > 0.0f) {
        start->x += static_cast<short>(static_cast<int>(static_cast<float>(deltaX) * enter));
        start->y += static_cast<short>(static_cast<int>(static_cast<float>(deltaY) * enter));
    }

    return true;
}

static bool __stdcall ClipLineParameter(int delta, int edgeDistance, float *enter, float *leave)
{
    if (delta > 0) {
        const float t = static_cast<float>(edgeDistance) / static_cast<float>(delta);
        if (t > *leave) {
            return false;
        }
        if (t > *enter) {
            *enter = t;
        }
        return true;
    }

    if (delta < 0) {
        const float t = static_cast<float>(edgeDistance) / static_cast<float>(delta);
        if (*enter > t) {
            return false;
        }
        if (*leave > t) {
            *leave = t;
        }
        return true;
    }

    return edgeDistance <= 0;
}

// UID:0002PF | by-memory/0x004bb8d0-0x004bb9a5.SoftwareRenderCompatPixelCallback.md | Completion:88 | Confidence:91
static void __thiscall SoftwareRenderCompatPixelCallback(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    port->GetClipRect(&clipRect);
    if (!PointInRect(y, x, &clipRect)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);
    const unsigned char drawMode = port->m_drawMode;

    switch (drawMode) {
    case 0:
    case 1: {
        if (drawMode == 1 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = static_cast<unsigned short>(
            static_cast<unsigned char>(colorIndex));
        break;
    }

    case 2:
    case 3: {
        if (drawMode == 3 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = BlendRgb555(*pixel, mappedColor, 0x10);
        break;
    }

    default:
        break;
    }
}



// UID:0002TB | by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md | Completion:92 | Confidence:94
static __forceinline void FillRgb555Span(
    unsigned short *pixels,
    int count,
    unsigned short color)
{
    if (count & 1) {
        pixels[count - 1] = color;
    }

    const unsigned int pair = color | (static_cast<unsigned int>(color) << 16);
    unsigned int *pairs = reinterpret_cast<unsigned int *>(pixels);
    for (int i = 0; i < count / 2; ++i) {
        pairs[i] = pair;
    }
}

static __forceinline unsigned short BlendRgb555Half(
    unsigned short destination,
    unsigned short source)
{
    const unsigned int redBlue =
        (((destination & 0x7c1f) + (source & 0x7c1f)) >> 1) & 0x7c1f;
    const unsigned int green =
        (((destination & 0x03e0) + (source & 0x03e0)) >> 1) & 0x03e0;
    return static_cast<unsigned short>(redBlue | green);
}

static __forceinline void BlendRgb555Span(
    unsigned short *pixels,
    int count,
    unsigned short color)
{
    for (int i = 0; i < count; ++i) {
        pixels[i] = BlendRgb555Half(pixels[i], color);
    }
}

static __forceinline void DrawRgb555FillRows(
    const EPFTileContext *sourceContext,
    const RectBounds &clippedSource,
    const signed char *runs,
    unsigned short *rowPixels,
    int rowStridePixels,
    unsigned short primaryPixel,
    unsigned short secondaryPixel,
    bool colorKey)
{
    const int width = clippedSource.right - clippedSource.left;
    int height = clippedSource.bottom - clippedSource.top;
    while (height-- > 0) {
        int x = sourceContext->bounds.left - clippedSource.left;
        signed char token;
        while ((token = *runs++) != 0) {
            const int runLeft = x;
            const int runRight = x + (token & 0x7f);
            x = runRight;

            if (runRight <= 0 || runLeft >= width) {
                continue;
            }
            if (colorKey && token >= 0) {
                continue;
            }

            const int spanLeft = runLeft > 0 ? runLeft : 0;
            const int spanRight = runRight < width ? runRight : width;
            FillRgb555Span(
                rowPixels + spanLeft,
                spanRight - spanLeft,
                token < 0 ? primaryPixel : secondaryPixel);
        }

        rowPixels += rowStridePixels;
    }
}

static __forceinline void DrawRgb555BlendRows(
    const EPFTileContext *sourceContext,
    const RectBounds &clippedSource,
    const signed char *runs,
    unsigned short *rowPixels,
    int rowStridePixels,
    unsigned short primaryPixel,
    unsigned short secondaryPixel,
    bool colorKey)
{
    const int width = clippedSource.right - clippedSource.left;
    int height = clippedSource.bottom - clippedSource.top;
    while (height-- > 0) {
        int x = sourceContext->bounds.left - clippedSource.left;
        signed char token;
        while ((token = *runs++) != 0) {
            const int runLeft = x;
            const int runRight = x + (token & 0x7f);
            x = runRight;

            if (runRight <= 0 || runLeft >= width) {
                continue;
            }
            if (colorKey && token >= 0) {
                continue;
            }

            const int spanLeft = runLeft > 0 ? runLeft : 0;
            const int spanRight = runRight < width ? runRight : width;
            BlendRgb555Span(
                rowPixels + spanLeft,
                spanRight - spanLeft,
                token < 0 ? primaryPixel : secondaryPixel);
        }

        rowPixels += rowStridePixels;
    }
}

static void __thiscall SoftwareRenderCompatRleFillCallback(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    DLPalette *palette)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedDestination = *destinationBounds;
    IntersectRects(&clipBounds, &clippedDestination, &clippedDestination);
    if (IsRectEmptyOrInvalid(&clippedDestination)) {
        return;
    }

    RectBounds clippedSource;
    clippedSource.left = sourceBounds->left +
        clippedDestination.left - destinationBounds->left;
    clippedSource.top = sourceBounds->top +
        clippedDestination.top - destinationBounds->top;
    clippedSource.right = sourceBounds->right +
        clippedDestination.right - destinationBounds->right;
    clippedSource.bottom = sourceBounds->bottom +
        clippedDestination.bottom - destinationBounds->bottom;

    if (palette == 0) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    const unsigned short primaryPixel = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);
    const unsigned short rawSecondaryPixel =
        static_cast<unsigned short>(port->m_textBackFillColor);

    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (clippedDestination.top - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStridePixels +
        (clippedDestination.left - port->m_surfaceContext.bounds.left);

    const signed char *runs = reinterpret_cast<const signed char *>(
        sourceContext->encodedMaskBytes);
    int rowsToSkip = clippedSource.top - sourceContext->bounds.top;
    for (int i = 0;
         i < sourceContext->encodedMaskByteCount && rowsToSkip > 0;
         ++i) {
        if (*runs++ == 0) {
            --rowsToSkip;
        }
    }

    const int height = clippedSource.bottom - clippedSource.top;
    if (height <= 0) {
        return;
    }

    switch (mode) {
    case 0:
        DrawRgb555FillRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            rawSecondaryPixel,
            false);
        break;

    case 1:
        DrawRgb555FillRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            rawSecondaryPixel,
            true);
        break;

    case 2:
        DrawRgb555BlendRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            secondaryPixel,
            false);
        break;

    case 3:
        DrawRgb555BlendRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            secondaryPixel,
            true);
        break;

    default:
        break;
    }
}



// UID:0002TE | by-memory/0x004be0e0-0x004be66e.SoftwareRenderCompatBitmaskBlitCallback.md | Completion:94 | Confidence:94
enum BitmaskBlitMode
{
    kBitmaskBlitCopy = 0,
    kBitmaskBlitColorKey = 1,
    kBitmaskBlitBlend = 2,
    kBitmaskBlitColorKeyBlend = 3
};

static void __thiscall SoftwareRenderCompatBitmaskBlitCallback(
    GrafPort *port,
    const unsigned char *maskBits,
    const RectBounds *destinationBounds,
    unsigned char mode)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *destinationBounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    RectBounds maskBounds;
    InitRectBounds(
        &maskBounds,
        0,
        0,
        destinationBounds->right - destinationBounds->left,
        destinationBounds->bottom - destinationBounds->top);

    const int maskWidth = maskBounds.right - maskBounds.left;
    const int sourceTop =
        clippedBounds.top - destinationBounds->top + maskBounds.top;
    const int sourceLeft =
        clippedBounds.left - destinationBounds->left + maskBounds.left;
    const int sourceBottom =
        clippedBounds.bottom - destinationBounds->bottom + maskBounds.bottom;
    const int sourceRight =
        clippedBounds.right - destinationBounds->right + maskBounds.right;
    const int width = sourceRight - sourceLeft;
    const int height = sourceBottom - sourceTop;

    const int startBitOffset = sourceTop * maskWidth + sourceLeft;
    const unsigned char *rowMask = maskBits + startBitOffset / 8;
    unsigned char rowBit =
        static_cast<unsigned char>(startBitOffset % 8);

    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (clippedBounds.top - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStridePixels +
        clippedBounds.left - port->m_surfaceContext.bounds.left;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short primaryPixel =
        palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);

    switch (mode) {
    case kBitmaskBlitCopy:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                *pixel++ = (*mask & (0x80 >> bit)) != 0
                    ? primaryPixel
                    : secondaryPixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKey:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = primaryPixel;
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                const unsigned short sourcePixel =
                    (*mask & (0x80 >> bit)) != 0
                        ? primaryPixel
                        : secondaryPixel;
                *pixel = BlendRgb555Half(*pixel, sourcePixel);
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKeyBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = BlendRgb555Half(*pixel, primaryPixel);
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    default:
        break;
    }
}

// UID:0002YF | by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md | Completion:92 | Confidence:94
static void __fastcall SoftwareRenderCompatFillCallback(
    GrafPort *port,
    int /*unused*/,
    const RectBounds *bounds)
{
    enum FillMode {
        kFillCopy = 0,
        kFillColorKey = 1,
        kFillBlend = 2,
        kFillColorKeyBlend = 3
    };

    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *bounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    const int width = clippedBounds.right - clippedBounds.left;
    const int height = clippedBounds.bottom - clippedBounds.top;
    const int rowStridePixels = port->m_surfaceContext.rowStridePixels;
    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        clippedBounds.left +
        rowStridePixels *
            (clippedBounds.top - port->m_surfaceContext.bounds.top) -
        port->m_surfaceContext.bounds.left;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    unsigned short fillPixel = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);
    (void)secondaryPixel;

    if (port->m_usesSoftwareBuffer && port->m_drawColor == 128) {
        fillPixel = 1;
    }

    switch (port->m_drawMode) {
    case kFillCopy:
        for (int y = 0; y < height; ++y) {
            FillRgb555Span(rowPixels, width, fillPixel);
            rowPixels += rowStridePixels;
        }
        break;

    case kFillColorKey:
        if (port->m_drawColor == 0) {
            return;
        }

        for (int y = 0; y < height; ++y) {
            FillRgb555Span(rowPixels, width, fillPixel);
            rowPixels += rowStridePixels;
        }
        break;

    case kFillBlend: {
        const unsigned char destinationWeight =
            static_cast<unsigned char>(
                static_cast<int>(port->m_alpha * 32.0f + 0.5f));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                rowPixels[x] = BlendRgb555(
                    rowPixels[x], fillPixel, destinationWeight);
            }
            rowPixels += rowStridePixels;
        }
        break;
    }

    case kFillColorKeyBlend: {
        if (port->m_drawColor == 0) {
            return;
        }

        const unsigned char destinationWeight =
            static_cast<unsigned char>(
                static_cast<int>(port->m_alpha * 32.0f + 0.5f));

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                rowPixels[x] = BlendRgb555(
                    rowPixels[x], fillPixel, destinationWeight);
            }
            rowPixels += rowStridePixels;
        }
        break;
    }

    default:
        return;
    }
}

// UID:0002YJ | by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md | Completion:94 | Confidence:95
#define APPLY_RGB555_FADE(pairExpression, pixelExpression)                 \
    do {                                                                  \
        unsigned int *pair = reinterpret_cast<unsigned int *>(pixels);    \
        unsigned int pairCount = pixelCount >> 1;                         \
        while (pairCount-- != 0) {                                        \
            const unsigned int value = *pair;                             \
            *pair++ = (pairExpression);                                   \
        }                                                                 \
        if ((pixelCount & 1) != 0) {                                      \
            unsigned short *lastPixel =                                   \
                reinterpret_cast<unsigned short *>(pair);                 \
            const unsigned int value = *lastPixel;                        \
            *lastPixel = static_cast<unsigned short>(pixelExpression);    \
        }                                                                 \
    } while (0)

static void __cdecl SoftwareRenderCompatBlockTransferCallback(
    unsigned short *pixels,
    unsigned int pixelCount,
    int fadeStep)
{
    if (fadeStep < 0) {
        fadeStep = 0;
    } else if (fadeStep > 24) {
        fadeStep = 24;
    }

    switch (fadeStep) {
    case 0:
        return;
    case 1:
        APPLY_RGB555_FADE(
            value - ((value >> 4) & 0x04210421u),
            value - ((value >> 4) & 0x0421u));
        break;
    case 2:
        APPLY_RGB555_FADE(
            value + ((value >> 4) & 0x04210421u) -
                ((value >> 3) & 0x0c630c63u),
            value + ((value >> 4) & 0x0421u) -
                ((value >> 3) & 0x0c63u));
        break;
    case 3:
        APPLY_RGB555_FADE(
            value - ((value >> 3) & 0x0c630c63u),
            value - ((value >> 3) & 0x0c63u));
        break;
    case 4:
        APPLY_RGB555_FADE(
            value - ((value >> 4) & 0x04210421u) -
                ((value >> 3) & 0x0c630c63u),
            value - ((value >> 4) & 0x0421u) -
                ((value >> 3) & 0x0c63u));
        break;
    case 5:
        APPLY_RGB555_FADE(
            value + ((value >> 4) & 0x04210421u) -
                ((value >> 2) & 0x1ce71ce7u),
            value + ((value >> 4) & 0x0421u) -
                ((value >> 2) & 0x1ce7u));
        break;
    case 6:
        APPLY_RGB555_FADE(
            value - ((value >> 2) & 0x1ce71ce7u),
            value - ((value >> 2) & 0x1ce7u));
        break;
    case 7:
        APPLY_RGB555_FADE(
            value - ((value >> 4) & 0x04210421u) -
                ((value >> 2) & 0x1ce71ce7u),
            value - ((value >> 4) & 0x0421u) -
                ((value >> 2) & 0x1ce7u));
        break;
    case 8:
        APPLY_RGB555_FADE(
            value - ((value >> 3) & 0x0c630c63u) -
                ((value >> 2) & 0x1ce71ce7u),
            value - ((value >> 3) & 0x0c63u) -
                ((value >> 2) & 0x1ce7u));
        break;
    case 9:
        APPLY_RGB555_FADE(
            value - ((value >> 4) & 0x04210421u) -
                ((value >> 3) & 0x0c630c63u) -
                ((value >> 2) & 0x1ce71ce7u),
            value - ((value >> 4) & 0x0421u) -
                ((value >> 3) & 0x0c63u) -
                ((value >> 2) & 0x1ce7u));
        break;
    case 10:
        APPLY_RGB555_FADE(
            value + ((value >> 4) & 0x04210421u) -
                2u * ((value >> 2) & 0x1ce71ce7u),
            value + ((value >> 4) & 0x0421u) -
                2u * ((value >> 2) & 0x1ce7u));
        break;
    case 11:
        APPLY_RGB555_FADE(
            value + ((value >> 4) & 0x04210421u) -
                ((value >> 1) & 0x3def3defu),
            value + ((value >> 4) & 0x0421u) -
                ((value >> 1) & 0x3defu));
        break;
    case 12:
        APPLY_RGB555_FADE(
            ((value >> 4) & 0x04210421u) +
                ((value >> 1) & 0x3def3defu),
            ((value >> 4) & 0x0421u) +
                ((value >> 1) & 0x3defu));
        break;
    case 13:
        APPLY_RGB555_FADE(
            (value & 0x7bde7bdeu) >> 1,
            (value & 0x7bdeu) >> 1);
        break;
    case 14:
        APPLY_RGB555_FADE(
            ((value >> 1) & 0x3def3defu) -
                ((value >> 4) & 0x04210421u),
            ((value >> 1) & 0x3defu) -
                ((value >> 4) & 0x0421u));
        break;
    case 15:
        APPLY_RGB555_FADE(
            2u * ((value >> 2) & 0x1ce71ce7u) -
                ((value >> 4) & 0x04210421u),
            2u * ((value >> 2) & 0x1ce7u) -
                ((value >> 4) & 0x0421u));
        break;
    case 16:
        APPLY_RGB555_FADE(
            ((value >> 4) & 0x04210421u) +
                ((value >> 3) & 0x0c630c63u) +
                ((value >> 2) & 0x1ce71ce7u),
            ((value >> 4) & 0x0421u) +
                ((value >> 3) & 0x0c63u) +
                ((value >> 2) & 0x1ce7u));
        break;
    case 17:
        APPLY_RGB555_FADE(
            ((value >> 3) & 0x0c630c63u) +
                ((value >> 2) & 0x1ce71ce7u),
            ((value >> 3) & 0x0c63u) +
                ((value >> 2) & 0x1ce7u));
        break;
    case 18:
        APPLY_RGB555_FADE(
            ((value >> 4) & 0x04210421u) +
                ((value >> 2) & 0x1ce71ce7u),
            ((value >> 4) & 0x0421u) +
                ((value >> 2) & 0x1ce7u));
        break;
    case 19:
        APPLY_RGB555_FADE(
            (value & 0x739c739cu) >> 2,
            (value & 0x739cu) >> 2);
        break;
    case 20:
        APPLY_RGB555_FADE(
            ((value >> 2) & 0x1ce71ce7u) -
                ((value >> 4) & 0x04210421u),
            ((value >> 2) & 0x1ce7u) -
                ((value >> 4) & 0x0421u));
        break;
    case 21:
        APPLY_RGB555_FADE(
            ((value >> 4) & 0x04210421u) +
                ((value >> 3) & 0x0c630c63u),
            ((value >> 4) & 0x0421u) +
                ((value >> 3) & 0x0c63u));
        break;
    case 22:
        APPLY_RGB555_FADE(
            (value & 0x63186318u) >> 3,
            (value & 0x6318u) >> 3);
        break;
    case 23:
        APPLY_RGB555_FADE(
            (value & 0x42104210u) >> 4,
            (value & 0x4210u) >> 4);
        break;
    case 24:
        memset(pixels, 0, pixelCount * sizeof(*pixels));
        break;
    }
}

#undef APPLY_RGB555_FADE

// UID:0002PI | by-memory/0x004c0770-0x004c0845.SoftwareRenderRgb565PixelCallback.md | Completion:92 | Confidence:94
static void __thiscall SoftwareRenderRgb565PixelCallback(
    GrafPort *port,
    int x,
    int y,
    unsigned int colorIndex)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    port->GetClipRect(&clipRect);
    if (!PointInRect(y, x, &clipRect)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);
    const unsigned char drawMode = port->m_drawMode;

    switch (drawMode) {
    case 0:
    case 1: {
        if (drawMode == 1 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = static_cast<unsigned short>(
            static_cast<unsigned char>(colorIndex));
        break;
    }

    case 2:
    case 3: {
        if (drawMode == 3 && colorIndex == 0) {
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);

        *pixel = BlendRgb565Pixel(*pixel, mappedColor, 0x10);
        break;
    }

    default:
        break;
    }
}

// UID:0002PJ | by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md | Completion:93 | Confidence:94
static void __thiscall SoftwareRenderRgb565LineCallback(
    GrafPort *port,
    int deltaX,
    int deltaY)
{
    RectBounds clipRect;
    if (!port->m_drawEnabled) {
        port->m_currentX += deltaX;
        port->m_currentY += deltaY;
        return;
    }

    port->GetClipRect(&clipRect);
    if (IsRectEmptyOrInvalid(&clipRect)) {
        port->m_currentX += deltaX;
        port->m_currentY += deltaY;
        return;
    }

    const unsigned int colorIndex = port->m_drawColor;
    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short mappedColor = palette->MapColor(colorIndex);

    if (deltaY == 0 &&
        port->m_currentY >= clipRect.top &&
        port->m_currentY < clipRect.bottom) {
        const int endX = port->m_currentX + deltaX;
        int firstX = port->m_currentX;
        int lastX = endX;
        if (deltaX <= 0) {
            firstX = endX;
            lastX = port->m_currentX;
        }

        if (firstX < clipRect.left) {
            firstX = clipRect.left;
        }
        if (lastX >= clipRect.right) {
            lastX = clipRect.right - 1;
        }

        if (lastX < firstX) {
            port->m_currentX = endX;
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (port->m_currentY - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (firstX - port->m_surfaceContext.bounds.left);
        int pixelCount = lastX - firstX + 1;
        const unsigned int packedColor =
            static_cast<unsigned int>(mappedColor) |
            (static_cast<unsigned int>(mappedColor) << 16);

        switch (port->m_drawMode) {
        case 0:
        case 1:
            if (port->m_drawMode == 0 || colorIndex != 0) {
                unsigned int *pair =
                    reinterpret_cast<unsigned int *>(pixel);
                while (pixelCount >= 2) {
                    *pair++ = packedColor;
                    pixelCount -= 2;
                }
                if (pixelCount != 0) {
                    *reinterpret_cast<unsigned short *>(pair) = mappedColor;
                }
            }
            break;

        case 2:
        case 3:
            if (port->m_drawMode == 2 || colorIndex != 0) {
                unsigned int *pair =
                    reinterpret_cast<unsigned int *>(pixel);
                while (pixelCount >= 2) {
                    *pair = BlendRgb565Pair(*pair, packedColor, 0x10);
                    ++pair;
                    pixelCount -= 2;
                }
                if (pixelCount != 0) {
                    unsigned short *lastPixel =
                        reinterpret_cast<unsigned short *>(pair);
                    *lastPixel =
                        BlendRgb565Pixel(*lastPixel, mappedColor, 0x10);
                }
            }
            break;

        default:
            break;
        }

        port->m_currentX += deltaX;
        return;
    }

    if (deltaX == 0 &&
        port->m_currentX >= clipRect.left &&
        port->m_currentX < clipRect.right) {
        const int endY = port->m_currentY + deltaY;
        int firstY = port->m_currentY;
        int lastY = endY;
        if (deltaY <= 0) {
            firstY = endY;
            lastY = port->m_currentY;
        }

        if (firstY < clipRect.top) {
            firstY = clipRect.top;
        }
        if (lastY >= clipRect.bottom) {
            lastY = clipRect.bottom - 1;
        }

        if (lastY < firstY) {
            port->m_currentY = endY;
            return;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (firstY - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (port->m_currentX - port->m_surfaceContext.bounds.left);
        int pixelCount = lastY - firstY + 1;

        switch (port->m_drawMode) {
        case 0:
        case 1:
            if (port->m_drawMode == 0 || colorIndex != 0) {
                while (pixelCount-- != 0) {
                    *pixel = mappedColor;
                    pixel += port->m_surfaceContext.rowStridePixels;
                }
            }
            break;

        case 2:
            while (pixelCount-- != 0) {
                *pixel = BlendRgb565Pixel(*pixel, mappedColor, 0x10);
                pixel += port->m_surfaceContext.rowStridePixels;
            }
            break;

        case 3:
            if (colorIndex != 0) {
                while (pixelCount-- != 0) {
                    if (*pixel != 0) {
                        *pixel =
                            BlendRgb565Pixel(*pixel, mappedColor, 0x10);
                    }
                    pixel += port->m_surfaceContext.rowStridePixels;
                }
            }
            break;

        default:
            break;
        }

        port->m_currentY += deltaY;
        return;
    }

    LineClipPoint start;
    start.y = port->m_currentY;
    start.x = port->m_currentX;

    LineClipPoint end;
    end.y = port->m_currentY + deltaY;
    end.x = port->m_currentX + deltaX;

    if (ClipLineToRect(&start, &end, &clipRect)) {
        int x = start.x;
        int y = start.y;
        int absoluteDeltaX = end.x - start.x;
        int absoluteDeltaY = end.y - start.y;
        const int stepX = absoluteDeltaX < 0 ? -1 : 1;
        const int stepY = absoluteDeltaY < 0 ? -1 : 1;
        if (absoluteDeltaX < 0) {
            absoluteDeltaX = -absoluteDeltaX;
        }
        if (absoluteDeltaY < 0) {
            absoluteDeltaY = -absoluteDeltaY;
        }

        unsigned short *pixel =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            (y - port->m_surfaceContext.bounds.top) *
                port->m_surfaceContext.rowStridePixels +
            (x - port->m_surfaceContext.bounds.left);
        *pixel = mappedColor;

        if (absoluteDeltaX >= absoluteDeltaY) {
            int error = 2 * absoluteDeltaY - absoluteDeltaX;
            while (x != end.x) {
                x += stepX;
                if (error > 0) {
                    y += stepY;
                    error -= 2 * absoluteDeltaX;
                }
                error += 2 * absoluteDeltaY;

                pixel =
                    static_cast<unsigned short *>(
                        port->m_surfaceContext.pixelData) +
                    (y - port->m_surfaceContext.bounds.top) *
                        port->m_surfaceContext.rowStridePixels +
                    (x - port->m_surfaceContext.bounds.left);
                *pixel = mappedColor;
            }
        } else {
            int error = 2 * absoluteDeltaX - absoluteDeltaY;
            while (y != end.y) {
                y += stepY;
                if (error > 0) {
                    x += stepX;
                    error -= 2 * absoluteDeltaY;
                }
                error += 2 * absoluteDeltaX;

                pixel =
                    static_cast<unsigned short *>(
                        port->m_surfaceContext.pixelData) +
                    (y - port->m_surfaceContext.bounds.top) *
                        port->m_surfaceContext.rowStridePixels +
                    (x - port->m_surfaceContext.bounds.left);
                *pixel = mappedColor;
            }
        }
    }

    port->m_currentX += deltaX;
    port->m_currentY += deltaY;
}


// UID:0002TF | by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md | Completion:92 | Confidence:94
static __forceinline void FillRgb565Span(
    unsigned short *pixels,
    int count,
    unsigned short color)
{
    if (count & 1) {
        pixels[count - 1] = color;
    }

    const unsigned int pair = color | (static_cast<unsigned int>(color) << 16);
    unsigned int *pairs = reinterpret_cast<unsigned int *>(pixels);
    for (int i = 0; i < count / 2; ++i) {
        pairs[i] = pair;
    }
}

static __forceinline unsigned short BlendRgb565Half(
    unsigned short destination,
    unsigned short source)
{
    const unsigned int redBlue =
        (((destination & 0xf81f) + (source & 0xf81f)) >> 1) & 0xf81f;
    const unsigned int green =
        (((destination & 0x07e0) + (source & 0x07e0)) >> 1) & 0x07e0;
    return static_cast<unsigned short>(redBlue | green);
}

static __forceinline void BlendRgb565Span(
    unsigned short *pixels,
    int count,
    unsigned short color)
{
    for (int i = 0; i < count; ++i) {
        pixels[i] = BlendRgb565Half(pixels[i], color);
    }
}

static __forceinline void DrawRgb565FillRows(
    const EPFTileContext *sourceContext,
    const RectBounds &clippedSource,
    const signed char *runs,
    unsigned short *rowPixels,
    int rowStridePixels,
    unsigned short primaryPixel,
    unsigned short secondaryPixel,
    bool colorKey)
{
    const int width = clippedSource.right - clippedSource.left;
    int height = clippedSource.bottom - clippedSource.top;
    while (height-- > 0) {
        int x = sourceContext->bounds.left - clippedSource.left;
        signed char token;
        while ((token = *runs++) != 0) {
            const int runLeft = x;
            const int runRight = x + (token & 0x7f);
            x = runRight;

            if (runRight <= 0 || runLeft >= width) {
                continue;
            }
            if (colorKey && token >= 0) {
                continue;
            }

            const int spanLeft = runLeft > 0 ? runLeft : 0;
            const int spanRight = runRight < width ? runRight : width;
            FillRgb565Span(
                rowPixels + spanLeft,
                spanRight - spanLeft,
                token < 0 ? primaryPixel : secondaryPixel);
        }

        rowPixels += rowStridePixels;
    }
}

static __forceinline void DrawRgb565BlendRows(
    const EPFTileContext *sourceContext,
    const RectBounds &clippedSource,
    const signed char *runs,
    unsigned short *rowPixels,
    int rowStridePixels,
    unsigned short primaryPixel,
    unsigned short secondaryPixel,
    bool colorKey)
{
    const int width = clippedSource.right - clippedSource.left;
    int height = clippedSource.bottom - clippedSource.top;
    while (height-- > 0) {
        int x = sourceContext->bounds.left - clippedSource.left;
        signed char token;
        while ((token = *runs++) != 0) {
            const int runLeft = x;
            const int runRight = x + (token & 0x7f);
            x = runRight;

            if (runRight <= 0 || runLeft >= width) {
                continue;
            }
            if (colorKey && token >= 0) {
                continue;
            }

            const int spanLeft = runLeft > 0 ? runLeft : 0;
            const int spanRight = runRight < width ? runRight : width;
            BlendRgb565Span(
                rowPixels + spanLeft,
                spanRight - spanLeft,
                token < 0 ? primaryPixel : secondaryPixel);
        }

        rowPixels += rowStridePixels;
    }
}

static void __thiscall SoftwareRenderRgb565RleFillCallback(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    DLPalette *palette)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedDestination = *destinationBounds;
    IntersectRects(&clipBounds, &clippedDestination, &clippedDestination);
    if (IsRectEmptyOrInvalid(&clippedDestination)) {
        return;
    }

    RectBounds clippedSource;
    clippedSource.left = sourceBounds->left +
        clippedDestination.left - destinationBounds->left;
    clippedSource.top = sourceBounds->top +
        clippedDestination.top - destinationBounds->top;
    clippedSource.right = sourceBounds->right +
        clippedDestination.right - destinationBounds->right;
    clippedSource.bottom = sourceBounds->bottom +
        clippedDestination.bottom - destinationBounds->bottom;

    if (palette == 0) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    const unsigned short primaryPixel = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);
    const unsigned short rawSecondaryPixel =
        static_cast<unsigned short>(port->m_textBackFillColor);

    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (clippedDestination.top - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStridePixels +
        (clippedDestination.left - port->m_surfaceContext.bounds.left);

    const signed char *runs = reinterpret_cast<const signed char *>(
        sourceContext->encodedMaskBytes);
    int rowsToSkip = clippedSource.top - sourceContext->bounds.top;
    for (int i = 0;
         i < sourceContext->encodedMaskByteCount && rowsToSkip > 0;
         ++i) {
        if (*runs++ == 0) {
            --rowsToSkip;
        }
    }

    const int height = clippedSource.bottom - clippedSource.top;
    if (height <= 0) {
        return;
    }

    switch (mode) {
    case 0:
        DrawRgb565FillRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            rawSecondaryPixel,
            false);
        break;

    case 1:
        DrawRgb565FillRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            rawSecondaryPixel,
            true);
        break;

    case 2:
        DrawRgb565BlendRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            secondaryPixel,
            false);
        break;

    case 3:
        DrawRgb565BlendRows(
            sourceContext,
            clippedSource,
            runs,
            rowPixels,
            port->m_surfaceContext.rowStridePixels,
            primaryPixel,
            secondaryPixel,
            true);
        break;

    default:
        break;
    }
}

// UID:0002TG | by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md | Completion:92 | Confidence:94
static void __thiscall SoftwareRenderRgb565ScaledRleTintCallback(
    GrafPort *port,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds,
    unsigned char mode,
    float tintAmount,
    int rowOffset,
    float verticalScale,
    float horizontalShear)
{
    if (!port->m_drawEnabled)
        return;

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    const int projectedRows = static_cast<int>(
        static_cast<float>(
            rowOffset + destinationBounds->bottom - destinationBounds->top) /
        verticalScale);
    int destinationY =
        destinationBounds->bottom - projectedRows + rowOffset - 2;
    float destinationXPosition = static_cast<float>(static_cast<int>(
        static_cast<float>(projectedRows) * horizontalShear +
        static_cast<float>(destinationBounds->left)));
    int destinationX = static_cast<int>(destinationXPosition);
    unsigned short *destinationRow =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        destinationX +
        port->m_surfaceContext.rowStridePixels *
            (destinationY - port->m_surfaceContext.bounds.top) -
        port->m_surfaceContext.bounds.left;

    if (mode != 3)
        return;

    const unsigned char tintStrength = static_cast<unsigned char>(
        static_cast<int>(tintAmount * 32.0f + 0.5f));
    const int sourceWidth = sourceBounds->right - sourceBounds->left;
    const int sourceRowCount = sourceBounds->bottom - sourceBounds->top;
    const signed char *encodedRow =
        reinterpret_cast<const signed char *>(
            sourceContext->encodedMaskBytes);
    float sourceRowPosition = 0.0f;
    int sourceRowsConsumed = 0;

    while (sourceRowsConsumed < sourceRowCount)
    {
        if (clipBounds.top <= destinationY &&
            destinationY < clipBounds.bottom)
        {
            const int clipLeft =
                clipBounds.left > destinationX
                    ? clipBounds.left
                    : destinationX;
            const int destinationRight = destinationX + sourceWidth;
            const int clipRight =
                clipBounds.right < destinationRight
                    ? clipBounds.right
                    : destinationRight;
            const signed char *run = encodedRow;
            int runX = destinationX;
            unsigned short *runPixels = destinationRow;

            while (*run != 0)
            {
                const int runLength =
                    static_cast<unsigned char>(*run) & 0x7f;

                if (*run < 0)
                {
                    const int writeLeft =
                        clipLeft > runX ? clipLeft : runX;
                    const int runRight = runX + runLength;
                    const int writeRight =
                        clipRight < runRight ? clipRight : runRight;
                    unsigned short *pixel =
                        runPixels + (writeLeft - runX);

                    for (int count = writeRight - writeLeft;
                         count > 0;
                         --count, ++pixel)
                    {
                        const unsigned short value = *pixel;
                        const unsigned int red =
                            g_surfaceColorLookup5Bit[value >> 11]
                                                     [tintStrength];
                        const unsigned int green =
                            g_surfaceColorLookup6Bit[(value >> 5) & 0x3f]
                                                     [tintStrength] & 0x3f;
                        const unsigned int blue =
                            g_surfaceColorLookup5Bit[value & 0x1f]
                                                     [tintStrength] & 0x1f;
                        *pixel = static_cast<unsigned short>(
                            (red << 11) | (green << 5) | blue);
                    }
                }

                runX += runLength;
                runPixels += runLength;
                ++run;
            }
        }

        destinationXPosition -= horizontalShear;
        ++destinationY;

        const float nextSourceRowPosition =
            sourceRowPosition + verticalScale;
        const int rowsToAdvance =
            static_cast<int>(nextSourceRowPosition + 0.5f) -
            static_cast<int>(sourceRowPosition + 0.5f);

        destinationX = static_cast<int>(destinationXPosition);
        destinationRow =
            static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
            destinationX +
            destinationY * port->m_surfaceContext.rowStridePixels;

        for (int row = 0; row < rowsToAdvance; ++row)
        {
            while (*encodedRow != 0)
                ++encodedRow;
            ++encodedRow;
        }

        sourceRowPosition = nextSourceRowPosition;
        sourceRowsConsumed += rowsToAdvance;
    }
}

// UID:0002TH | by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md | Completion:92 | Confidence:94
static void __thiscall SoftwareRenderRgb565AlphaLookupBlitCallback(
    GrafPort *port,
    const IntAlphaSurface *alphaSurface,
    const RectBounds *sourceBounds,
    const RectBounds *destinationBounds)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds;
    IntersectRects(&clipBounds, destinationBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    AlphaSurfaceBufferView sourceView;
    alphaSurface->GetBufferInfo(&sourceView);

    const int sourceX =
        sourceBounds->left + clippedBounds.left - destinationBounds->left;
    const int sourceY =
        sourceBounds->top + clippedBounds.top - destinationBounds->top;
    const unsigned char *sourceRow =
        sourceView.pixels + sourceY * sourceView.stride + sourceX;

    const int destinationPitchBytes =
        2 * port->m_surfaceContext.rowStridePixels;
    unsigned char *destinationBytes =
        static_cast<unsigned char *>(port->m_surfaceContext.pixelData) +
        2 * clippedBounds.left +
        destinationPitchBytes * clippedBounds.top;
    unsigned short *destinationRow =
        reinterpret_cast<unsigned short *>(destinationBytes);

    const int width = clippedBounds.right - clippedBounds.left;
    const int height = clippedBounds.bottom - clippedBounds.top;
    const int bulkWidth = width & ~3;

    ApplyAlphaMap565(
        destinationRow,
        destinationPitchBytes,
        sourceRow,
        sourceView.stride,
        bulkWidth,
        height);

    const int tailWidth = width - bulkWidth;
    destinationRow += bulkWidth;
    sourceRow += bulkWidth;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < tailWidth; ++x) {
            const unsigned short pixel = destinationRow[x];
            const unsigned char alpha = sourceRow[x];
            const unsigned int red =
                g_surfaceColorLookup5Bit[pixel >> 11][alpha];
            const unsigned int green =
                g_surfaceColorLookup6Bit[(pixel >> 5) & 0x3f][alpha];
            const unsigned int blue =
                g_surfaceColorLookup5Bit[pixel & 0x1f][alpha];

            destinationRow[x] = static_cast<unsigned short>(
                (red << 11) | (green << 5) | blue);
        }

        destinationRow = reinterpret_cast<unsigned short *>(
            reinterpret_cast<unsigned char *>(destinationRow) +
            destinationPitchBytes);
        sourceRow += sourceView.stride;
    }
}

// UID:0002TI | by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md | Completion:91 | Confidence:93
static void __thiscall SoftwareRenderRgb565BitmaskBlitCallback(
    GrafPort *port,
    const unsigned char *maskBits,
    const RectBounds *destinationBounds,
    unsigned char mode)
{
    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *destinationBounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    RectBounds maskBounds;
    InitRectBounds(
        &maskBounds,
        0,
        0,
        destinationBounds->right - destinationBounds->left,
        destinationBounds->bottom - destinationBounds->top);

    const int maskWidth = maskBounds.right - maskBounds.left;
    const int sourceTop =
        clippedBounds.top - destinationBounds->top + maskBounds.top;
    const int sourceLeft =
        clippedBounds.left - destinationBounds->left + maskBounds.left;
    const int sourceBottom =
        clippedBounds.bottom - destinationBounds->bottom + maskBounds.bottom;
    const int sourceRight =
        clippedBounds.right - destinationBounds->right + maskBounds.right;
    const int width = sourceRight - sourceLeft;
    const int height = sourceBottom - sourceTop;

    const int startBitOffset = sourceTop * maskWidth + sourceLeft;
    const unsigned char *rowMask = maskBits + startBitOffset / 8;
    unsigned char rowBit =
        static_cast<unsigned char>(startBitOffset % 8);

    unsigned short *rowPixels =
        static_cast<unsigned short *>(port->m_surfaceContext.pixelData) +
        (clippedBounds.top - port->m_surfaceContext.bounds.top) *
            port->m_surfaceContext.rowStridePixels +
        clippedBounds.left - port->m_surfaceContext.bounds.left;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short primaryPixel =
        palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_textBackFillColor);

    switch (mode) {
    case kBitmaskBlitCopy:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                *pixel++ = (*mask & (0x80 >> bit)) != 0
                    ? primaryPixel
                    : secondaryPixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKey:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = primaryPixel;
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                const unsigned short sourcePixel =
                    (*mask & (0x80 >> bit)) != 0
                        ? primaryPixel
                        : secondaryPixel;
                *pixel = BlendRgb565Pixel(*pixel, sourcePixel, 16);
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    case kBitmaskBlitColorKeyBlend:
        for (short y = 0; y < height; ++y) {
            const unsigned char *mask = rowMask;
            unsigned char bit = rowBit;
            unsigned short *pixel = rowPixels;

            for (short x = 0; x < width; ++x) {
                if ((*mask & (0x80 >> bit)) != 0) {
                    *pixel = BlendRgb565Pixel(*pixel, primaryPixel, 16);
                }
                ++pixel;

                if (bit == 7) {
                    ++mask;
                    bit = 0;
                } else {
                    ++bit;
                }
            }

            const int nextRowBitOffset = maskWidth + rowBit - maskBounds.left;
            rowMask += nextRowBitOffset / 8;
            rowBit = static_cast<unsigned char>(nextRowBitOffset % 8);
            rowPixels += port->m_surfaceContext.rowStridePixels;
        }
        break;

    default:
        break;
    }
}

// UID:0002YK | by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md | Completion:90 | Confidence:92
static void __fastcall FillRgb565RectCallback(
    GrafPort *port,
    int /*unused*/,
    const RectBounds *bounds)
{
    enum FillMode {
        kFillCopy = 0,
        kFillColorKey = 1,
        kFillBlend = 2,
        kFillColorKeyBlend = 3
    };

    if (!port->m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    port->GetClipRect(&clipBounds);

    RectBounds clippedBounds = *bounds;
    IntersectRects(&clipBounds, &clippedBounds, &clippedBounds);
    if (IsRectEmptyOrInvalid(&clippedBounds)) {
        return;
    }

    const int width = clippedBounds.right - clippedBounds.left;
    const int height = clippedBounds.bottom - clippedBounds.top;
    const int rowStridePixels = port->m_surfaceContext.rowStridePixels;
    unsigned char *pixelBytes =
        static_cast<unsigned char *>(port->m_surfaceContext.pixelData);
    unsigned short *rowPixels = reinterpret_cast<unsigned short *>(
        pixelBytes +
        2 * (clippedBounds.left +
             rowStridePixels *
                 (clippedBounds.top - port->m_surfaceContext.bounds.top) -
             port->m_surfaceContext.bounds.left));

    DLPalette *palette = port->m_palette;
    if (palette == NULL) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    unsigned short fillPixel = palette->MapColor(port->m_drawColor);
    const unsigned short secondaryPixel =
        palette->MapColor(port->m_secondaryDrawColor);
    (void)secondaryPixel;

    if (port->m_usesSoftwareBuffer && port->m_drawColor == 128) {
        fillPixel = 1;
    }

    const unsigned int packedFill =
        static_cast<unsigned int>(fillPixel) |
        (static_cast<unsigned int>(fillPixel) << 16);

    switch (port->m_drawMode) {
    case kFillCopy:
        for (int y = 0; y < height; ++y) {
            if ((width & 1) != 0) {
                rowPixels[width & ~1] = fillPixel;
            }

            unsigned int *pairs =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < width / 2; ++x) {
                pairs[x] = packedFill;
            }

            rowPixels += rowStridePixels;
        }
        break;

    case kFillColorKey:
        if (port->m_drawColor == 0) {
            return;
        }

        for (int y = 0; y < height; ++y) {
            if ((width & 1) != 0) {
                rowPixels[width & ~1] = fillPixel;
            }

            unsigned int *pairs =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < width / 2; ++x) {
                pairs[x] = packedFill;
            }

            rowPixels += rowStridePixels;
        }
        break;

    case kFillBlend: {
        const unsigned char destinationWeight = static_cast<unsigned char>(
            static_cast<int>(port->m_alpha * 32.0f + 0.5f));
        const int evenWidth = width & ~1;

        for (int y = 0; y < height; ++y) {
            unsigned int *pair =
                reinterpret_cast<unsigned int *>(rowPixels);
            for (int x = 0; x < evenWidth; x += 2) {
                *pair = BlendRgb565Pair(
                    *pair, packedFill, destinationWeight);
                ++pair;
            }

            if ((width & 1) != 0) {
                unsigned short *tail =
                    reinterpret_cast<unsigned short *>(pair);
                *tail = BlendRgb565Pixel(
                    *tail, fillPixel, destinationWeight);
            }

            rowPixels += rowStridePixels;
        }
        break;
    }

    case kFillColorKeyBlend: {
        if (port->m_drawColor == 0) {
            return;
        }

        const unsigned char destinationWeight = static_cast<unsigned char>(
            static_cast<int>(port->m_alpha * 32.0f + 0.5f));

        for (int y = 0; y < height; ++y) {
            unsigned int *pair =
                reinterpret_cast<unsigned int *>(rowPixels);

            // Preserve the original odd-width pair-plus-extra-pixel behavior.
            for (int x = 0; x < width; x += 2) {
                *pair = BlendRgb565Pair(
                    *pair, packedFill, destinationWeight);
                ++pair;
            }

            if ((width & 1) != 0) {
                unsigned short *extraPixel =
                    reinterpret_cast<unsigned short *>(pair);
                *extraPixel = BlendRgb565Pixel(
                    *extraPixel, fillPixel, destinationWeight);
            }

            rowPixels += rowStridePixels;
        }
        break;
    }

    default:
        return;
    }
}

// UID:0002YO | by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md | Completion:94 | Confidence:95
#define APPLY_RGB565_FADE(pairExpression, pixelExpression)                 \
    do {                                                                  \
        unsigned int *pair = reinterpret_cast<unsigned int *>(pixels);    \
        unsigned int pairCount = pixelCount >> 1;                         \
        while (pairCount-- != 0) {                                        \
            const unsigned int value = *pair;                             \
            *pair++ = (pairExpression);                                   \
        }                                                                 \
        if ((pixelCount & 1) != 0) {                                      \
            unsigned short *lastPixel =                                   \
                reinterpret_cast<unsigned short *>(pair);                 \
            const unsigned int value = *lastPixel;                        \
            *lastPixel = static_cast<unsigned short>(pixelExpression);    \
        }                                                                 \
    } while (0)

static void __cdecl SoftwareRenderRgb565BlockTransferCallback(
    unsigned short *pixels,
    unsigned int pixelCount,
    int fadeStep)
{
    if (fadeStep < 0) {
        fadeStep = 0;
    } else if (fadeStep > 24) {
        fadeStep = 24;
    }

    switch (fadeStep) {
    case 0:
        return;
    case 1:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u),
            value - ((value >> 4) & 0x0841u));
        break;
    case 2:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u));
        break;
    case 3:
        APPLY_RGB565_FADE(
            value - ((value >> 3) & 0x18c318c3u),
            value - ((value >> 3) & 0x18c3u));
        break;
    case 4:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u));
        break;
    case 5:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 2) & 0x39c739c7u),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 6:
        APPLY_RGB565_FADE(
            value - ((value >> 2) & 0x39c739c7u),
            value - ((value >> 2) & 0x39c7u));
        break;
    case 7:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 8:
        APPLY_RGB565_FADE(
            value - ((value >> 3) & 0x18c318c3u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 3) & 0x18c3u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 9:
        APPLY_RGB565_FADE(
            value - ((value >> 4) & 0x08410841u) -
                ((value >> 3) & 0x18c318c3u) -
                ((value >> 2) & 0x39c739c7u),
            value - ((value >> 4) & 0x0841u) -
                ((value >> 3) & 0x18c3u) -
                ((value >> 2) & 0x39c7u));
        break;
    case 10:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                2u * ((value >> 2) & 0x39c739c7u),
            value + ((value >> 4) & 0x0841u) -
                2u * ((value >> 2) & 0x39c7u));
        break;
    case 11:
        APPLY_RGB565_FADE(
            value + ((value >> 4) & 0x08410841u) -
                ((value >> 1) & 0x7bcf7bcfu),
            value + ((value >> 4) & 0x0841u) -
                ((value >> 1) & 0x7bcfu));
        break;
    case 12:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 1) & 0x7bcf7bcfu),
            ((value >> 4) & 0x0841u) +
                ((value >> 1) & 0x7bcfu));
        break;
    case 13:
        APPLY_RGB565_FADE(
            (value & 0xf79ef79eu) >> 1,
            (value & 0xf79eu) >> 1);
        break;
    case 14:
        APPLY_RGB565_FADE(
            ((value >> 1) & 0x7bcf7bcfu) -
                ((value >> 4) & 0x08410841u),
            ((value >> 1) & 0x7bcfu) -
                ((value >> 4) & 0x0841u));
        break;
    case 15:
        APPLY_RGB565_FADE(
            2u * ((value >> 2) & 0x39c739c7u) -
                ((value >> 4) & 0x08410841u),
            2u * ((value >> 2) & 0x39c7u) -
                ((value >> 4) & 0x0841u));
        break;
    case 16:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 3) & 0x18c318c3u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 4) & 0x0841u) +
                ((value >> 3) & 0x18c3u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 17:
        APPLY_RGB565_FADE(
            ((value >> 3) & 0x18c318c3u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 3) & 0x18c3u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 18:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 2) & 0x39c739c7u),
            ((value >> 4) & 0x0841u) +
                ((value >> 2) & 0x39c7u));
        break;
    case 19:
        APPLY_RGB565_FADE(
            (value & 0xe71ce71cu) >> 2,
            (value & 0xe71cu) >> 2);
        break;
    case 20:
        APPLY_RGB565_FADE(
            ((value >> 2) & 0x39c739c7u) -
                ((value >> 4) & 0x08410841u),
            ((value >> 2) & 0x39c7u) -
                ((value >> 4) & 0x0841u));
        break;
    case 21:
        APPLY_RGB565_FADE(
            ((value >> 4) & 0x08410841u) +
                ((value >> 3) & 0x18c318c3u),
            ((value >> 4) & 0x0841u) +
                ((value >> 3) & 0x18c3u));
        break;
    case 22:
        APPLY_RGB565_FADE(
            (value & 0xc618c618u) >> 3,
            (value & 0xc618u) >> 3);
        break;
    case 23:
        APPLY_RGB565_FADE(
            (value & 0x84108410u) >> 4,
            (value & 0x8410u) >> 4);
        break;
    case 24:
        memset(pixels, 0, pixelCount * sizeof(*pixels));
        break;
    }
}

#undef APPLY_RGB565_FADE


// UID:00039V | by-memory/0x00558690-0x0055883d.InitializeSurfaceRenderCallbacks.md | Completion:91 | Confidence:93
void InitializeSurfaceRenderCallbacks()
{
    DDSURFACEDESC displayMode;
    displayMode.dwSize = sizeof(displayMode);

    if (g_pDirectX->m_pDirectDraw->GetDisplayMode(&displayMode) == DD_OK) {
        switch (displayMode.ddpfPixelFormat.dwRGBBitCount) {
        case 32:
            g_surfaceUses32BitPresentation = true;
            g_surfaceUsesRgb565Pixels = true;
            break;

        case 24:
            g_surfaceUses32BitPresentation = false;
            g_surfaceUsesRgb565Pixels = false;
            break;

        case 16:
            g_surfaceUses32BitPresentation = false;
            g_surfaceUsesRgb565Pixels =
                displayMode.ddpfPixelFormat.dwGBitMask == 0x07e0;
            break;
        }
    }

    if (g_surfaceUsesRgb565Pixels) {
        g_pfnDrawPixel = SoftwareRenderRgb565PixelCallback;
        g_pfnDrawLineDelta = SoftwareRenderRgb565LineCallback;
        g_pfnBlitSprite = SoftwareRenderRgb565SpriteBlitCallback;
        g_pfnFillRle = SoftwareRenderRgb565RleFillCallback;
        g_pfnBlitScaledRleTint = SoftwareRenderRgb565ScaledRleTintCallback;
        g_pfnBlitAlphaLookup = SoftwareRenderRgb565AlphaLookupBlitCallback;
        g_pfnBlitBitmask = SoftwareRenderRgb565BitmaskBlitCallback;
        g_pfnFillRect = FillRgb565RectCallback;
        g_pfnExpandPixel = ExpandRgb565Pixel;
        g_pfnPackPixel = PackRgb565Pixel;
        g_pfnTransformPaletteColor = TransformRgb565PaletteColor;
        g_pfnTransferPixels = SoftwareRenderRgb565BlockTransferCallback;
    } else {
        g_pfnDrawPixel = SoftwareRenderCompatPixelCallback;
        g_pfnDrawLineDelta = SoftwareRenderCompatLineCallback;
        g_pfnBlitSprite = SoftwareRenderCompatSpriteBlitCallback;
        g_pfnFillRle = SoftwareRenderCompatRleFillCallback;
        g_pfnBlitScaledRleTint = SoftwareRenderCompatScaledRleTintCallback;
        g_pfnBlitAlphaLookup = SoftwareRenderCompatAlphaLookupBlitCallback;
        g_pfnBlitBitmask = SoftwareRenderCompatBitmaskBlitCallback;
        g_pfnFillRect = SoftwareRenderCompatFillCallback;
        g_pfnExpandPixel = ExpandRgb555Pixel;
        g_pfnPackPixel = PackRgb555Pixel;
        g_pfnTransformPaletteColor = TransformRgb555PaletteColor;
        g_pfnTransferPixels = SoftwareRenderCompatBlockTransferCallback;
    }
}

// UID:00023S | by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md | Completion:88 | Confidence:91
static void CopyDirectDrawSurfaceToPrimary(ScreenPane *screenPane)
{
    RECT sourceRect = { 0, 0, 2000, 2000 };
    RECT destinationRect = {
        0,
        0,
        g_pApplication->m_presentationWidth,
        g_pApplication->m_presentationHeight
    };

    DDSURFACEDESC surfaceDesc;
    IDirectDrawSurface *scratchSurface = NULL;

    memset(&surfaceDesc, 0, sizeof(surfaceDesc));
    surfaceDesc.dwSize = sizeof(surfaceDesc);
    surfaceDesc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
    surfaceDesc.dwHeight = 2000;
    surfaceDesc.dwWidth = 2000;
    surfaceDesc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    g_pDirectX->m_pDirectDraw->CreateSurface(&surfaceDesc, &scratchSurface, NULL);
    screenPane->m_primarySurface->Blt(&destinationRect,
                                      scratchSurface,
                                      &sourceRect,
                                      DDBLT_WAIT,
                                      NULL);
    scratchSurface->Release();
}

// UID:0002V6 | by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md | Completion:92 | Confidence:94
// Emitted source for this compiler-generated constant pool is covered by
// [UID:0002TB][0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback](by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md), [UID:0002YF][0x004be680-0x004bed67.SoftwareRenderCompatFillCallback](by-memory/0x004be680-0x004bed67.SoftwareRenderCompatFillCallback.md), [UID:0002YJ][0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback](by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md), [UID:0002TF][0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback](by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md), and [UID:0002YO][0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback](by-memory/0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md).
// Their scalar Surface callback expressions produce the RGB555/RGB565 masks,
// fixed-point blend weights, and fade deltas; no standalone data declaration
// is emitted for [UID:0002V6].

// UID:0002PG | by-memory\0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0002PH | by-memory\0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0002TC | by-memory\0x004bdcc0-0x004bdf3e.SoftwareRenderCompatScaledRleTintCallback.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0002TD | by-memory\0x004bdf40-0x004be0db.SoftwareRenderCompatAlphaLookupBlitCallback.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0002PK | by-memory\0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:00039T | by-memory\0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0002AK | by-memory\0x0069ba3c-0x0069ba40.SurfacePresentationTempSurfaceSlot.md | Completion:85 | Confidence:91 | Empty Emitter Marker
