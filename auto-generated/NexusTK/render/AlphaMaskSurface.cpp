// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HF
// Source by-file doc: by-file/AlphaMaskSurface.md
// UID:0001TQ | by-type/by-struct/AlphaSurfaceBufferView.md | Completion:94 | Confidence:95
// AlphaSurfaceBufferView is declared in AlphaMaskSurface.h.

// UID:00006K | by-class/IntAlphaSurface.md | Completion:94 | Confidence:95
#include "AlphaMaskSurface.h"
#include "EPFTileContext.h"
#include "SoftwareBlend16.h"

#include <math.h>
#include <new>
#include <stdlib.h>
#include <string.h>

// UID:0000YK | by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md | Completion:92 | Confidence:94
IntAlphaSurface::IntAlphaSurface()
    : m_pixels(NULL),
      m_width(0),
      m_height(0),
      m_stride(0),
      m_ownsBuffer(true)
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);
}

// UID:00054W | by-memory/0x00462170-0x00462227.IntAlphaSurfaceConstructor.md | Completion:93 | Confidence:95
IntAlphaSurface::IntAlphaSurface(int width, int height)
    : m_pixels(NULL),
      m_width(0),
      m_height(0),
      m_stride(0),
      m_ownsBuffer(true)
{
    InitRectBounds(&m_bounds, 0, 0, 0, 0);

    if (width > 0 && height > 0) {
        ReleaseOwnedPixels();
        m_width = width;
        m_height = height;
        m_stride = width;
        m_pixels = static_cast<unsigned char *>(malloc(width * height));
        m_ownsBuffer = true;
        InitRectBounds(&m_bounds, 0, 0, width, height);
    }
}

// UID:0004FR | by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md | Completion:93 | Confidence:95
void IntAlphaSurface::ReleaseOwnedPixels()
{
    if (m_ownsBuffer && m_pixels != NULL) {
        free(m_pixels);
        m_pixels = NULL;
    }
}

// UID:00054X | by-memory/0x004622d0-0x004622f7.IntAlphaSurfaceGetCenterPoint.md | Completion:92 | Confidence:94
void IntAlphaSurface::GetCenterPoint(Point *point) const
{
    InitPointPair(point, m_height / 2, m_width / 2);
}

// UID:00054Y | by-memory/0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo.md | Completion:93 | Confidence:95
void IntAlphaSurface::GetBufferInfo(AlphaSurfaceBufferView *outView) const
{
    outView->pixels = m_pixels;
    outView->width = m_width;
    outView->height = m_height;
    outView->stride = m_stride;
    outView->ownsBuffer = m_ownsBuffer;
    outView->padding[0] = m_padding[0];
    outView->padding[1] = m_padding[1];
    outView->padding[2] = m_padding[2];
}

// UID:00054Z | by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md | Completion:93 | Confidence:95
void IntAlphaSurface::GetClippedBufferInfo(AlphaSurfaceBufferView *outView,
                                            const RectBounds *clipBounds) const
{
    RectBounds surfaceBounds;
    RectBounds clippedBounds;
    InitRectBounds(&surfaceBounds, 0, 0, m_width, m_height);

    if (m_pixels != NULL &&
        IntersectRects(&surfaceBounds, clipBounds, &clippedBounds)) {
        outView->pixels = m_pixels
                        + clippedBounds.left
                        + clippedBounds.top * m_stride;
        outView->width = clippedBounds.right - clippedBounds.left;
        outView->height = clippedBounds.bottom - clippedBounds.top;
        outView->stride = m_stride;
    } else {
        outView->pixels = NULL;
    }

    outView->ownsBuffer = false;
}

// UID:0002NM | by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md | Completion:93 | Confidence:94
IntAlphaSurface *IntAlphaSurface::InitSurfaceView(
    IntAlphaSurface *view,
    const RectBounds *clipBounds) const
{
    view = new (view) IntAlphaSurface();

    if (clipBounds == NULL) {
        view->m_pixels = m_pixels;
        view->m_width = m_width;
        view->m_height = m_height;
        view->m_stride = m_stride;
    } else if (m_pixels != NULL) {
        RectBounds surfaceBounds;
        RectBounds clippedBounds;
        InitRectBounds(&surfaceBounds, 0, 0, m_width, m_height);

        if (IntersectRects(&surfaceBounds, clipBounds, &clippedBounds)) {
            view->m_pixels = m_pixels
                           + clippedBounds.left
                           + clippedBounds.top * m_stride;
            view->m_width = clippedBounds.right - clippedBounds.left;
            view->m_height = clippedBounds.bottom - clippedBounds.top;
            view->m_stride = m_stride;
        } else {
            view->m_pixels = NULL;
        }
    } else {
        view->m_pixels = NULL;
    }

    view->m_ownsBuffer = false;
    return view;
}

// UID:000550 | by-memory/0x00462520-0x00462672.IntAlphaSurfaceApplyRectAlpha.md | Completion:93 | Confidence:95
void IntAlphaSurface::ApplyRectAlpha(const RectBounds *bounds,
                                     unsigned char alpha,
                                     AlphaMaskBlendMode blendMode)
{
    if (m_pixels == NULL) {
        return;
    }

    RectBounds clippedBounds;
    if (bounds == NULL) {
        clippedBounds = m_bounds;
    } else if (!IntersectRects(&m_bounds, bounds, &clippedBounds)) {
        return;
    }

    const int width = clippedBounds.right - clippedBounds.left;
    for (int y = clippedBounds.top; y < clippedBounds.bottom; ++y) {
        unsigned char *pixel = m_pixels + y * m_stride + clippedBounds.left;

        if (blendMode == kAlphaMaskBlendCopy) {
            memset(pixel, alpha, width);
        } else if (blendMode == kAlphaMaskBlendAdd) {
            for (int x = 0; x < width; ++x) {
                pixel[x] = static_cast<unsigned char>(pixel[x] + alpha);
            }
        } else if (blendMode == kAlphaMaskBlendSubtract) {
            for (int x = 0; x < width; ++x) {
                pixel[x] = static_cast<unsigned char>(pixel[x] - alpha);
            }
        }
    }
}

// UID:000551 | by-memory/0x00462680-0x0046286b.IntAlphaSurfaceFillRadialGradient.md | Completion:92 | Confidence:94
void IntAlphaSurface::FillRadialGradient(int centerY,
                                         int centerX,
                                         int radius,
                                         unsigned char centerAlpha,
                                         unsigned char edgeAlpha,
                                         float exponent,
                                         AlphaMaskBlendMode blendMode)
{
    if (m_pixels == NULL || radius <= 0 || exponent <= 0.0f) {
        return;
    }

    RectBounds requestedBounds;
    RectBounds clippedBounds;
    InitRectBounds(&requestedBounds,
                   centerX - radius,
                   centerY - radius,
                   centerX + radius + 1,
                   centerY + radius + 1);
    if (!IntersectRects(&m_bounds, &requestedBounds, &clippedBounds)) {
        return;
    }

    const float alphaScale =
        (edgeAlpha - centerAlpha) / pow(static_cast<float>(radius), exponent);

    for (int y = clippedBounds.top; y < clippedBounds.bottom; ++y) {
        const float dy = static_cast<float>(y - centerY);
        unsigned char *pixel = m_pixels + y * m_stride + clippedBounds.left;

        for (int x = clippedBounds.left; x < clippedBounds.right; ++x, ++pixel) {
            const float dx = static_cast<float>(x - centerX);
            const float distance = static_cast<float>(sqrt(dx * dx + dy * dy));
            if (distance <= radius) {
                const unsigned char alpha = static_cast<unsigned char>(
                    pow(distance, exponent) * alphaScale + centerAlpha + 0.5f);

                if (blendMode == kAlphaMaskBlendCopy) {
                    *pixel = alpha;
                } else if (blendMode == kAlphaMaskBlendAdd) {
                    *pixel = static_cast<unsigned char>(*pixel + alpha);
                } else if (blendMode == kAlphaMaskBlendSubtract) {
                    *pixel = static_cast<unsigned char>(*pixel - alpha);
                }
            }
        }
    }
}

// UID:000552 | by-memory/0x00462870-0x00462e03.IntAlphaSurfaceFillEllipticGradient.md | Completion:92 | Confidence:94
void IntAlphaSurface::FillEllipticGradient(int centerY,
                                           int centerX,
                                           int radiusY,
                                           int radiusX,
                                           int innerRadius,
                                           unsigned char centerAlpha,
                                           unsigned char edgeAlpha,
                                           float exponent,
                                           AlphaMaskBlendMode blendMode)
{
    if (m_pixels == NULL ||
        innerRadius < 0 ||
        radiusY <= 0 ||
        radiusX <= 0 ||
        exponent <= 0.0f) {
        return;
    }

    RectBounds requestedBounds;
    RectBounds clippedBounds;
    InitRectBounds(&requestedBounds,
                   centerX - radiusX,
                   centerY - radiusY,
                   centerX + radiusX + 1,
                   centerY + radiusY + 1);
    if (!IntersectRects(&m_bounds, &requestedBounds, &clippedBounds)) {
        return;
    }

    const int outerRadius = radiusX > radiusY ? radiusX : radiusY;
    float alphaScale = 0.0f;
    if (innerRadius < outerRadius) {
        alphaScale = (edgeAlpha - centerAlpha) /
                     pow(static_cast<float>(outerRadius - innerRadius), exponent);
    }

    const float xScale = radiusX < radiusY
                       ? static_cast<float>(radiusY) / radiusX
                       : 1.0f;
    const float yScale = radiusY < radiusX
                       ? static_cast<float>(radiusX) / radiusY
                       : 1.0f;

    for (int y = clippedBounds.top; y < clippedBounds.bottom; ++y) {
        const float dy = static_cast<float>(y - centerY) * yScale;
        unsigned char *pixel = m_pixels + y * m_stride + clippedBounds.left;

        for (int x = clippedBounds.left; x < clippedBounds.right; ++x, ++pixel) {
            const float dx = static_cast<float>(x - centerX) * xScale;
            const float distance = static_cast<float>(sqrt(dx * dx + dy * dy));
            if (distance <= outerRadius) {
                unsigned char alpha = centerAlpha;
                if (distance > innerRadius) {
                    alpha = static_cast<unsigned char>(
                        pow(distance - innerRadius, exponent) * alphaScale
                        + centerAlpha + 0.5f);
                }

                if (blendMode == kAlphaMaskBlendCopy) {
                    *pixel = alpha;
                } else if (blendMode == kAlphaMaskBlendAdd) {
                    *pixel = static_cast<unsigned char>(*pixel + alpha);
                } else if (blendMode == kAlphaMaskBlendSubtract) {
                    *pixel = static_cast<unsigned char>(*pixel - alpha);
                }
            }
        }
    }
}

// UID:0000YN | by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md | Completion:93 | Confidence:95
void IntAlphaSurface::DrawFrameWithBlendMode(
    const RectBounds *destinationRect,
    const IntAlphaSurface *sourceFrame,
    const RectBounds *sourceRect,
    AlphaMaskBlendMode blendMode)
{
    if (m_pixels == NULL ||
        destinationRect == NULL ||
        sourceFrame == NULL ||
        sourceRect == NULL) {
        return;
    }

    RectBounds clippedDestination;
    if (!IntersectRects(&m_bounds, destinationRect, &clippedDestination)) {
        return;
    }

    const int rowCount = clippedDestination.bottom - clippedDestination.top;
    const int width = clippedDestination.right - clippedDestination.left;
    const int sourceX =
        clippedDestination.left + sourceRect->left - destinationRect->left;
    const int sourceY =
        clippedDestination.top + sourceRect->top - destinationRect->top;

    const unsigned char *source =
        sourceFrame->m_pixels + sourceX + sourceY * sourceFrame->m_stride;
    unsigned char *destination =
        m_pixels + clippedDestination.left + clippedDestination.top * m_stride;

    if (blendMode == kAlphaMaskBlendCopy) {
        ByteSpanCopyRows(source, sourceFrame->m_stride,
                         destination, m_stride, width, rowCount);
    } else if (blendMode == kAlphaMaskBlendAdd) {
        ByteSpanAddRows(source, sourceFrame->m_stride,
                        destination, m_stride, width, rowCount);
    } else if (blendMode == kAlphaMaskBlendSubtract) {
        ByteSpanSubtractRows(source, sourceFrame->m_stride,
                             destination, m_stride, width, rowCount);
    }
}

// UID:0000YO | by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md | Completion:93 | Confidence:95
void IntAlphaSurface::DrawEncodedAlphaFrame(
    const RectBounds *destinationRect,
    const EPFTileContext *sourceContext,
    const RectBounds *sourceOrigin,
    int alphaEndY,
    unsigned char alphaEnd,
    int alphaStartY,
    unsigned char alphaStart,
    AlphaMaskBlendMode blendMode)
{
    if (sourceContext->encodedMaskBytes == NULL) {
        return;
    }

    RectBounds clippedDestination;
    IntersectRects(&m_bounds, destinationRect, &clippedDestination);

    const unsigned char *run =
        reinterpret_cast<const unsigned char *>(sourceContext->encodedMaskBytes);
    int rowsToSkip =
        sourceOrigin->top - destinationRect->top
        + clippedDestination.top - sourceContext->bounds.top;

    while (rowsToSkip-- > 0) {
        while (*run++ != 0) {
        }
    }

    const int width =
        clippedDestination.right - clippedDestination.left;
    const int sourceX =
        clippedDestination.left + sourceOrigin->left - destinationRect->left;
    const float alphaStep =
        static_cast<float>(alphaEnd - alphaStart) /
        static_cast<float>(alphaEndY - alphaStartY);

    for (int y = clippedDestination.top;
         y < clippedDestination.bottom;
         ++y) {
        const unsigned char alpha = static_cast<unsigned char>(
            (y - alphaStartY) * alphaStep + alphaStart + 0.5f);
        unsigned char *destination =
            m_pixels + y * m_stride + clippedDestination.left;
        int x = sourceContext->bounds.left - sourceX;

        unsigned char token;
        while ((token = *run++) != 0) {
            const int count = static_cast<int>(token & 0x7f);
            if ((token & 0x80) != 0) {
                int first = x;
                int last = x + count;
                if (first < 0) {
                    first = 0;
                }
                if (last > width) {
                    last = width;
                }

                for (int column = first; column < last; ++column) {
                    if (blendMode == kAlphaMaskBlendCopy) {
                        destination[column] = alpha;
                    } else if (blendMode == kAlphaMaskBlendAdd) {
                        destination[column] = static_cast<unsigned char>(
                            destination[column] + alpha);
                    } else if (blendMode == kAlphaMaskBlendSubtract) {
                        destination[column] = static_cast<unsigned char>(
                            destination[column] - alpha);
                    }
                }
            }
            x += count;
        }
    }
}

// UID:0000YP | by-memory/0x00463270-0x004632b1.IntAlphaSurface.md | Completion:93 | Confidence:95
IntAlphaSurface::~IntAlphaSurface()
{
    if (m_ownsBuffer && m_pixels != NULL) {
        free(m_pixels);
        m_pixels = NULL;
    }
}
