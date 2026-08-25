// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JR
// Source by-file doc: by-file/GrafPort.md
// UID:00005V | by-class/GrafPort.md | Completion:94 | Confidence:95
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

// UID:00022M | by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md | Completion:87 | Confidence:91
void GrafPort::EnableSoftwareBuffer()
{
    m_usesSoftwareBuffer = true;
}

// UID:000560 | by-memory/0x004b8bf0-0x004b8d17.GrafPortConstructor.md | Completion:94 | Confidence:95
GrafPort::GrafPort()
    : m_ddSurface(NULL),
      m_currentY(0),
      m_currentX(0),
      m_drawMode(0),
      m_drawEnabled(true),
      m_drawColor(128),
      m_textBackFillColor(143),
      m_textColor(128),
      m_textBackColor(143),
      m_palette(NULL),
      m_textDrawMode(1),
      m_fontId(0),
      m_textAlign(0),
      m_alpha(0.5f),
      m_usesSoftwareBuffer(false),
      m_softwareBuffer(NULL),
      m_softwarePitchBytes(0)
{
    InitRectBounds(&m_surfaceContext.bounds, 0, 0, 0, 0);
    InitRectBounds(&m_visibleBounds, 0, 0, 0, 0);
    m_surfaceContext.pixelFormat = kEPFTilePixelFormatRgb16;
    m_surfaceContext.pixelData = NULL;
    m_surfaceContext.rowStridePixels = 0;
}

// UID:000561 | by-memory/0x004b8d20-0x004b8dc3.GrafPortDestructor.md | Completion:94 | Confidence:95
GrafPort::~GrafPort()
{
    if (m_usesSoftwareBuffer && m_softwareBuffer != NULL) {
        free(m_softwareBuffer);
        m_softwareBuffer = NULL;
    }

    if (m_ddSurface != NULL &&
        g_pDirectX != NULL &&
        g_pDirectX->m_pDirectDraw != NULL) {
        m_ddSurface->Release();
        m_ddSurface = NULL;
    }

    m_surfaceContext.ReleaseBuffers();
}

// UID:000562 | by-memory/0x004b8dd0-0x004b8de3.GrafPortGetExposedRegion.md | Completion:94 | Confidence:95
void GrafPort::GetExposedRegion(Region *outRegion) const
{
    outRegion->CopyRectFrom(m_exposedRegion);
}

// UID:000563 | by-memory/0x004b8df0-0x004b8df4.GrafPortGetSurfaceContext.md | Completion:94 | Confidence:95
EPFTileContext *GrafPort::GetSurfaceContext()
{
    return &m_surfaceContext;
}

// UID:000161 | by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md | Completion:92 | Confidence:94
RectBounds *GrafPort::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_visibleBounds;
    return outBounds;
}

// UID:000564 | by-memory/0x004b8e20-0x004b94e1.GrafPortUpdateRenderRegion.md | Completion:94 | Confidence:95
void GrafPort::UpdateRenderRegion(const RectBounds *bounds)
{
    if (RectsEquivalent(bounds, &m_visibleBounds)) {
        return;
    }

    m_surfaceContext.ReleaseBuffers();

    if (m_visibleBounds.bottom >= bounds->bottom) {
        if (m_visibleBounds.right >= bounds->right) {
            RectBounds trimRight;
            RectBounds trimBottom;
            InitRectBounds(&trimRight, bounds->right + 1, 0, 0x7fff, 0x7fff);
            InitRectBounds(&trimBottom, 0, bounds->bottom + 1, 0x7fff, 0x7fff);
            m_exposedRegion.SubtractRect(&trimRight);
            m_exposedRegion.SubtractRect(&trimBottom);
            if (!m_clipRegion.IsEmpty()) {
                m_clipRegion.SubtractRect(&trimRight);
                m_clipRegion.SubtractRect(&trimBottom);
            }
        } else {
            RectBounds trimBottom;
            RectBounds growRight;
            InitRectBounds(&trimBottom, 0, bounds->bottom + 1, 0x7fff, 0x7fff);
            InitRectBounds(&growRight, m_visibleBounds.right, 0,
                           bounds->right, bounds->bottom);
            m_exposedRegion.SubtractRect(&trimBottom);
            m_exposedRegion.UnionWithRect(&growRight);
            if (!m_clipRegion.IsEmpty()) {
                m_clipRegion.SubtractRect(&trimBottom);
                m_clipRegion.UnionWithRect(&growRight);
            }
        }
    } else if (m_visibleBounds.right < bounds->right) {
        m_exposedRegion.UnionWithRect(bounds);
        if (!m_clipRegion.IsEmpty()) {
            m_clipRegion.UnionWithRect(bounds);
        }
    } else {
        RectBounds trimRight;
        RectBounds growBottom;
        InitRectBounds(&trimRight, bounds->right + 1, 0, 0x7fff, 0x7fff);
        InitRectBounds(&growBottom, 0, m_visibleBounds.bottom,
                       bounds->right, bounds->bottom);
        m_exposedRegion.SubtractRect(&trimRight);
        m_exposedRegion.UnionWithRect(&growBottom);
        if (!m_clipRegion.IsEmpty()) {
            m_clipRegion.SubtractRect(&trimRight);
            m_clipRegion.UnionWithRect(&growBottom);
        }
    }

    const RectBounds oldBounds = m_visibleBounds;
    m_visibleBounds = *bounds;

    if (IsRectEmptyOrInvalid(bounds)) {
        m_surfaceContext.pixelData = NULL;
        m_surfaceContext.rowStridePixels = 0;
        InitRectBounds(&m_surfaceContext.bounds, 0, 0, 0, 0);

        if (m_ddSurface != NULL) {
            m_ddSurface->Release();
            m_ddSurface = NULL;
        }
        if (m_usesSoftwareBuffer && m_softwareBuffer != NULL) {
            free(m_softwareBuffer);
            m_softwareBuffer = NULL;
        }
        return;
    }

    const int width = bounds->right - bounds->left;
    const int height = bounds->bottom - bounds->top;

    if (!m_usesSoftwareBuffer) {
        DDSURFACEDESC surfaceDesc;
        memset(&surfaceDesc, 0, sizeof(surfaceDesc));
        surfaceDesc.dwSize = sizeof(surfaceDesc);
        surfaceDesc.dwFlags =
            DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH |
            DDSD_PIXELFORMAT | DDSD_CKSRCBLT;
        surfaceDesc.dwWidth = width;
        surfaceDesc.dwHeight = height;
        surfaceDesc.ddsCaps.dwCaps =
            DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
        surfaceDesc.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
        surfaceDesc.ddpfPixelFormat.dwFlags = DDPF_RGB;
        surfaceDesc.ddpfPixelFormat.dwRGBBitCount = 16;
        surfaceDesc.ddpfPixelFormat.dwRBitMask = 0xf800;
        surfaceDesc.ddpfPixelFormat.dwGBitMask = 0x07e0;
        surfaceDesc.ddpfPixelFormat.dwBBitMask = 0x001f;

        if (height > 0x800 &&
            (height & 3) == 0 &&
            4 * width < static_cast<unsigned short>(g_screenWidth)) {
            surfaceDesc.dwHeight = height / 4;
            surfaceDesc.dwWidth = width * 4;
        }

        IDirectDrawSurface *newSurface = NULL;
        const HRESULT result =
            g_pDirectX->m_pDirectDraw->CreateSurface(
                &surfaceDesc, &newSurface, NULL);
        if (FAILED(result)) {
            wchar_t message[256];
            swprintf_s(message, 256,
                       L"surfaceDesc.dwWidth : %d, surfaceDesc.dwHeight : %d",
                       surfaceDesc.dwWidth, surfaceDesc.dwHeight);
            MessageBoxW(g_pApplication->GetMainWindowHandle(),
                        message, L"...", MB_ICONEXCLAMATION);
            throw new DDError(result);
        }

        if (m_ddSurface != NULL) {
            RectBounds overlap;
            if (IntersectRects(bounds, &oldBounds, &overlap)) {
                RECT sourceRect;
                sourceRect.left = overlap.left;
                sourceRect.top = overlap.top;
                sourceRect.right = overlap.right - 1;
                sourceRect.bottom = overlap.bottom - 1;
                newSurface->BltFast(
                    0, 0, m_ddSurface, &sourceRect, DDBLTFAST_WAIT);
            }
            m_ddSurface->Release();
        }
        m_ddSurface = newSurface;
    } else {
        const int oldWidth = oldBounds.right - oldBounds.left;
        const int oldHeight = oldBounds.bottom - oldBounds.top;
        if (width > oldWidth || height > oldHeight) {
            const int newPitchBytes = 2 * width + 8;
            unsigned char *newBuffer =
                static_cast<unsigned char *>(malloc(newPitchBytes * height));

            RectBounds overlap;
            if (IntersectRects(bounds, &oldBounds, &overlap) &&
                m_softwareBuffer != NULL &&
                overlap.top < overlap.bottom) {
                for (int y = overlap.top; y < overlap.bottom; ++y) {
                    memmove(newBuffer + newPitchBytes * y + 2 * overlap.left,
                            static_cast<unsigned char *>(m_softwareBuffer) +
                                m_softwarePitchBytes * y + 2 * overlap.left,
                            2 * (overlap.right - overlap.left));
                }
            }

            if (m_softwareBuffer != NULL) {
                free(m_softwareBuffer);
            }
            m_softwareBuffer = newBuffer;
            m_softwarePitchBytes = newPitchBytes;
        }
    }

    const int contextLeft = m_surfaceContext.bounds.left;
    const int contextTop = m_surfaceContext.bounds.top;
    EPFTileContext emptyContext;
    emptyContext.pixelFormat = kEPFTilePixelFormatRgb16;
    emptyContext.pixelData = NULL;
    emptyContext.rowStridePixels = 0;
    emptyContext.bounds.left = contextLeft;
    emptyContext.bounds.top = contextTop;
    emptyContext.bounds.right = contextLeft + bounds->right;
    emptyContext.bounds.bottom = contextTop + bounds->bottom;
    m_surfaceContext = emptyContext;
}

// UID:0004LN | by-memory/0x004b94f0-0x004b9509.GrafPortReleaseSurface.md | Completion:89 | Confidence:91
void GrafPort::ReleaseSurface()
{
    if (m_ddSurface != NULL) {
        m_ddSurface->Release();
        m_ddSurface = NULL;
    }
}

// UID:0004LO | by-memory/0x004b9510-0x004b951d.GrafPortSetSurfacePixelData.md | Completion:89 | Confidence:91
void GrafPort::SetSurfacePixelData(void *pixelData)
{
    m_surfaceContext.pixelData = pixelData;
}

// UID:0004LP | by-memory/0x004b9520-0x004b952d.GrafPortSetSurfaceRowStride.md | Completion:89 | Confidence:91
void GrafPort::SetSurfaceRowStride(int rowStridePixels)
{
    m_surfaceContext.rowStridePixels = rowStridePixels;
}

// UID:0004LQ | by-memory/0x004b9530-0x004b9545.GrafPortGetOrigin.md | Completion:91 | Confidence:93
Point *GrafPort::GetOrigin(Point *outOrigin) const
{
    outOrigin->x = m_surfaceContext.bounds.left;
    outOrigin->y = m_surfaceContext.bounds.top;
    return outOrigin;
}

// UID:0004LR | by-memory/0x004b9550-0x004b9574.GrafPortSetOrigin.md | Completion:89 | Confidence:91
void GrafPort::SetOrigin(int x, int y)
{
    OffsetRect(&m_surfaceContext.bounds,
               -(m_surfaceContext.bounds.left + x),
               -(m_surfaceContext.bounds.top + y));
}

// UID:0004LS | by-memory/0x004b9580-0x004b958c.GrafPortSetClipRegion.md | Completion:91 | Confidence:93
void GrafPort::SetClipRegion(const Region *clipRegion)
{
    m_clipRegion.CopyRectFrom(*clipRegion);
}

// UID:0004LT | by-memory/0x004b9590-0x004b95a3.GrafPortGetClipRegion.md | Completion:91 | Confidence:93
void GrafPort::GetClipRegion(Region *outClipRegion) const
{
    outClipRegion->CopyRectFrom(m_clipRegion);
}

// UID:0004LU | by-memory/0x004b95b0-0x004b95bc.GrafPortSetClipRect.md | Completion:91 | Confidence:93
void GrafPort::SetClipRect(const RectBounds *clipRect)
{
    m_clipRegion.SetRect(clipRect);
}

// UID:0004LV | by-memory/0x004b95c0-0x004b95c5.GrafPortDisableDrawing.md | Completion:89 | Confidence:91
void GrafPort::DisableDrawing()
{
    m_drawEnabled = false;
}

// UID:0004LW | by-memory/0x004b95d0-0x004b95d5.GrafPortEnableDrawing.md | Completion:89 | Confidence:91
void GrafPort::EnableDrawing()
{
    m_drawEnabled = true;
}

// UID:000162 | by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md | Completion:89 | Confidence:91
void GrafPort::GetDrawPosition(int *outPosition)
{
    outPosition[0] = m_currentY;
    outPosition[1] = m_currentX;
}

void GrafPort::MoveTo(int x, int y)
{
    m_currentX = x;
    m_currentY = y;
}

void GrafPort::OffsetDrawPosition(int deltaX, int deltaY)
{
    m_currentX += deltaX;
    m_currentY += deltaY;
}

void GrafPort::SetFontId(unsigned short fontId)
{
    if (fontId <= 1) {
        m_fontId = fontId;
    }
}

void GrafPort::SetDrawColor(unsigned int color)
{
    m_drawColor = color;
}

void GrafPort::SetTextBackFillColor(unsigned int color)
{
    m_textBackFillColor = color;
}

void GrafPort::SetTextColor(unsigned int color)
{
    m_textColor = color;
}

void GrafPort::SetTextBackColor(unsigned int color)
{
    m_textBackColor = color;
}

// UID:000163 | by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md | Completion:90 | Confidence:92
DLPalette *GrafPort::GetPalette() const
{
    return m_palette;
}

void GrafPort::SetPalette(DLPalette *palette)
{
    m_palette = palette;
}

// UID:000164 | by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md | Completion:89 | Confidence:91
void GrafPort::GetClipRect(RectBounds *outClipRect)
{
    Region effectiveClip;

    effectiveClip.CopyRectFrom(m_exposedRegion);

    if (!m_clipRegion.IsEmpty()) {
        effectiveClip.IntersectWith(m_clipRegion);
    }

    effectiveClip.IntersectWithRect(&m_surfaceContext.bounds);
    effectiveClip.GetRect(outClipRect);
}

// UID:0004DI | by-memory/0x004b9770-0x004b97cf.GrafPortBuildEffectiveClipRegionRaw.md | Completion:92 | Confidence:93
void GrafPort::BuildEffectiveClipRegion(Region *outRegion)
{
    outRegion->CopyRectFrom(m_exposedRegion);
    if (!m_clipRegion.IsEmpty()) {
        outRegion->IntersectWith(m_clipRegion);
    }
    outRegion->IntersectWithRect(&m_surfaceContext.bounds);
}

// UID:0004DJ | by-memory/0x004b97d0-0x004b981e.GrafPortReleaseBackingStore.md | Completion:89 | Confidence:91
void GrafPort::ReleaseBackingStore()
{
    if (m_usesSoftwareBuffer && m_softwareBuffer != NULL) {
        free(m_softwareBuffer);
        m_softwareBuffer = NULL;
    }

    if (m_ddSurface != NULL && g_pDirectX != NULL && g_pDirectX->m_pDirectDraw != NULL) {
        m_ddSurface->Release();
        m_ddSurface = NULL;
    }
}

// UID:0004H2 | by-memory/0x004b9820-0x004b98b8.GrafPortUpdateSurfaceInfo.md | Completion:88 | Confidence:90
void GrafPort::UpdateSurfaceInfo()
{
    if (m_usesSoftwareBuffer) {
        if (m_softwareBuffer != NULL) {
            m_surfaceContext.pixelData = m_softwareBuffer;
            m_surfaceContext.rowStridePixels = m_softwarePitchBytes / sizeof(unsigned short);
        }
        return;
    }

    if (m_ddSurface == NULL) {
        return;
    }

    DDSURFACEDESC surfaceDesc;
    memset(&surfaceDesc, 0, sizeof(surfaceDesc));
    surfaceDesc.dwSize = sizeof(surfaceDesc);

    m_ddSurface->Lock(NULL, &surfaceDesc, DDLOCK_WAIT, NULL);
    m_surfaceContext.pixelData = surfaceDesc.lpSurface;
    m_surfaceContext.rowStridePixels = surfaceDesc.lPitch / sizeof(unsigned short);
}

// UID:0004H3 | by-memory/0x004b98c0-0x004b98ee.GrafPortEndPaint.md | Completion:88 | Confidence:90
void GrafPort::EndPaint()
{
    if (!m_usesSoftwareBuffer && m_ddSurface != NULL) {
        m_ddSurface->Unlock(NULL);
    }

    m_surfaceContext.rowStridePixels = 0;
    m_surfaceContext.pixelData = NULL;
}

// UID:0004H4 | by-memory/0x004b98f0-0x004b990c.GrafPortLineTo.md | Completion:88 | Confidence:91
void GrafPort::LineTo(int x, int y)
{
    g_pfnDrawLineDelta(this, x - m_currentX, y - m_currentY);
}

// UID:0004H5 | by-memory/0x004b9910-0x004b997e.GrafPortDrawSprite.md | Completion:87 | Confidence:90
int GrafPort::DrawSprite(GrafPort *source,
                         const RectBounds *sourceRect,
                         const RectBounds *destinationRect,
                         int mode,
                         DLPalette *palette,
                         const SurfaceSpriteBlitOptions *options)
{
    const float savedAlpha = m_alpha;
    const float sourceAlpha = source->m_alpha;

    if (sourceAlpha <= 1.0f) {
        m_alpha = sourceAlpha;
    }

    const int result = g_pfnBlitSprite(this,
                                       &source->m_surfaceContext,
                                       sourceRect,
                                       destinationRect,
                                       mode,
                                       palette,
                                       options);

    if (savedAlpha <= 1.0f) {
        m_alpha = savedAlpha;
    }

    return result;
}

// UID:0004H6 | by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md | Completion:89 | Confidence:92
int GrafPort::RenderTileFrame(const EPFTileContext *sourceContext,
                              const RectBounds *sourceRect,
                              const RectBounds *destinationRect,
                              int mode,
                              const wchar_t *paletteName,
                              const SurfaceSpriteBlitOptions *options)
{
    DLPalette *palette = g_pPaletteLib->GetPaletteByName(paletteName);

    return g_pfnBlitSprite(this,
                           sourceContext,
                           sourceRect,
                           destinationRect,
                           mode,
                           palette,
                           options);
}

// UID:000166 | by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md | Completion:93 | Confidence:94
int GrafPort::BlitTileContextAt(
    int destinationX,
    int destinationY,
    const EPFTileContext *sourceContext,
    DLPalette *palette,
    unsigned char mode,
    SurfaceSpriteBlitOptions *options)
{
    RectBounds destinationRect;
    InitRectBounds(
        &destinationRect,
        destinationX + sourceContext->bounds.left,
        destinationY + sourceContext->bounds.top,
        destinationX + sourceContext->bounds.right,
        destinationY + sourceContext->bounds.bottom);

    return g_pfnBlitSprite(
        this, sourceContext, &sourceContext->bounds,
        &destinationRect, mode, palette, options);
}

// UID:0004H7 | by-memory/0x004b9a70-0x004ba24a.GrafPortScrollPixelBuffer.md | Completion:92 | Confidence:94
void GrafPort::ScrollPixelBuffer(const RectBounds *scrollRect,
                                 int deltaX,
                                 int deltaY,
                                 Region *dirtyRegion)
{
    MemoryMan *memoryMan = GetMemoryMan();
    dirtyRegion->SetEmpty();

    if (!m_drawEnabled)
        return;

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds clippedRect = *scrollRect;
    IntersectRects(&clippedRect, &clipRect, &clippedRect);
    if (IsRectEmptyOrInvalid(&clippedRect))
        return;

    unsigned short *pixels =
        static_cast<unsigned short *>(m_surfaceContext.pixelData);
    const int rowStridePixels = m_surfaceContext.rowStridePixels;
    const int surfaceLeft = m_surfaceContext.bounds.left;
    const int surfaceTop = m_surfaceContext.bounds.top;
    const int rectWidth = clippedRect.right - clippedRect.left;
    const int rectHeight = clippedRect.bottom - clippedRect.top;
    RectBounds dirtyRect;
    unsigned short *sourcePixels;
    unsigned short *destinationPixels;
    int copyWidth;
    int copyRows;
    int clearWidth;
    int clearRows;
    int clearX;
    int clearY;
    int row;

    if (deltaX > 0) {
        if (deltaY > 0) {
            copyWidth = rectWidth - deltaX;
            copyRows = rectHeight - deltaY;
            sourcePixels = pixels
                + (clippedRect.bottom - deltaY - 1 - surfaceTop)
                    * rowStridePixels
                + clippedRect.left - surfaceLeft;
            destinationPixels = pixels
                + (clippedRect.bottom - 1 - surfaceTop) * rowStridePixels
                + clippedRect.left + deltaX - surfaceLeft;

            if (copyRows > 0 && copyWidth > 0) {
                for (row = 0; row < copyRows; ++row) {
                    memoryMan->MoveBufferMemory(destinationPixels,
                                                sourcePixels,
                                                2 * copyWidth);
                    sourcePixels -= rowStridePixels;
                    destinationPixels -= rowStridePixels;
                }
            }

            clearRows = deltaY;
            if (rectHeight < clearRows)
                clearRows = rectHeight;
            destinationPixels = pixels
                + (clippedRect.top - surfaceTop) * rowStridePixels
                + clippedRect.left - surfaceLeft;
            if (clearRows > 0) {
                for (row = 0; row < clearRows; ++row) {
                    memset(destinationPixels, 0, 2 * rectWidth);
                    destinationPixels += rowStridePixels;
                }
            }
            InitRectBounds(&dirtyRect,
                           clippedRect.left,
                           clippedRect.top,
                           clippedRect.right,
                           clippedRect.top + clearRows);
            dirtyRegion->UnionWithRect(&dirtyRect);

            clearWidth = deltaX;
            if (rectWidth < clearWidth)
                clearWidth = rectWidth;
            copyRows = rectHeight - deltaY;
            destinationPixels = pixels
                + (clippedRect.top + deltaY - surfaceTop) * rowStridePixels
                + clippedRect.left - surfaceLeft;
            if (copyRows > 0) {
                for (row = 0; row < copyRows; ++row) {
                    memset(destinationPixels, 0, 2 * clearWidth);
                    destinationPixels += rowStridePixels;
                }
            }
            InitRectBounds(&dirtyRect,
                           clippedRect.left,
                           clippedRect.top + deltaY,
                           clippedRect.left + clearWidth,
                           clippedRect.bottom);
            dirtyRegion->UnionWithRect(&dirtyRect);
            return;
        }

        copyWidth = rectWidth - deltaX;
        copyRows = rectHeight + deltaY;
        sourcePixels = pixels
            + (clippedRect.top - deltaY - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left + deltaX - surfaceLeft;

        if (copyRows > 0 && copyWidth > 0) {
            for (row = 0; row < copyRows; ++row) {
                memoryMan->MoveBufferMemory(destinationPixels,
                                            sourcePixels,
                                            2 * copyWidth);
                sourcePixels += rowStridePixels;
                destinationPixels += rowStridePixels;
            }
        }

        clearWidth = deltaX;
        if (rectWidth < clearWidth)
            clearWidth = rectWidth;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (copyRows > 0) {
            for (row = 0; row < copyRows; ++row) {
                memset(destinationPixels, 0, 2 * clearWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.top,
                       clippedRect.left + clearWidth,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);

        clearRows = -deltaY;
        clearY = clippedRect.bottom + deltaY;
        if (rectWidth < clearRows) {
            clearRows = rectWidth;
            clearY = clippedRect.top;
        }
        destinationPixels = pixels
            + (clearY - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (clearRows > 0) {
            for (row = 0; row < clearRows; ++row) {
                // Preserve the original branch's four-byte clear width.
                memset(destinationPixels, 0, 4 * rectWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.bottom + deltaY,
                       clippedRect.right,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);
        return;
    }

    if (deltaY > 0) {
        copyWidth = rectWidth + deltaX;
        copyRows = rectHeight - deltaY;
        sourcePixels = pixels
            + (clippedRect.bottom - deltaY - 1 - surfaceTop)
                * rowStridePixels
            + clippedRect.left - deltaX - surfaceLeft;
        destinationPixels = pixels
            + (clippedRect.bottom - 1 - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;

        if (copyRows > 0 && copyWidth > 0) {
            for (row = 0; row < copyRows; ++row) {
                memoryMan->MoveBufferMemory(destinationPixels,
                                            sourcePixels,
                                            2 * copyWidth);
                sourcePixels -= rowStridePixels;
                destinationPixels -= rowStridePixels;
            }
        }

        clearRows = deltaY;
        if (rectHeight < clearRows)
            clearRows = rectHeight;
        destinationPixels = pixels
            + (clippedRect.top - surfaceTop) * rowStridePixels
            + clippedRect.left - surfaceLeft;
        if (clearRows > 0) {
            for (row = 0; row < clearRows; ++row) {
                memset(destinationPixels, 0, 2 * rectWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.left,
                       clippedRect.top,
                       clippedRect.right,
                       clippedRect.top + clearRows);
        dirtyRegion->UnionWithRect(&dirtyRect);

        clearWidth = -deltaX;
        clearX = clippedRect.right + deltaX;
        if (rectWidth < clearWidth) {
            clearWidth = rectWidth;
            clearX = clippedRect.left;
        }
        destinationPixels = pixels
            + (clippedRect.top + deltaY - surfaceTop) * rowStridePixels
            + clearX - surfaceLeft;
        if (copyRows > 0) {
            for (row = 0; row < copyRows; ++row) {
                memset(destinationPixels, 0, 2 * clearWidth);
                destinationPixels += rowStridePixels;
            }
        }
        InitRectBounds(&dirtyRect,
                       clippedRect.right + deltaX,
                       clippedRect.top + deltaY,
                       clippedRect.right,
                       clippedRect.bottom);
        dirtyRegion->UnionWithRect(&dirtyRect);
        return;
    }

    copyWidth = rectWidth + deltaX;
    copyRows = rectHeight + deltaY;
    sourcePixels = pixels
        + (clippedRect.top - deltaY - surfaceTop) * rowStridePixels
        + clippedRect.left - deltaX - surfaceLeft;
    destinationPixels = pixels
        + (clippedRect.top - surfaceTop) * rowStridePixels
        + clippedRect.left - surfaceLeft;

    if (copyRows > 0 && copyWidth > 0) {
        for (row = 0; row < copyRows; ++row) {
            memoryMan->MoveBufferMemory(destinationPixels,
                                        sourcePixels,
                                        2 * copyWidth);
            sourcePixels += rowStridePixels;
            destinationPixels += rowStridePixels;
        }
    }

    clearWidth = -deltaX;
    clearX = clippedRect.right + deltaX;
    if (rectWidth < clearWidth) {
        clearWidth = rectWidth;
        clearX = clippedRect.left;
    }
    destinationPixels = pixels
        + (clippedRect.top - surfaceTop) * rowStridePixels
        + clearX - surfaceLeft;
    if (copyRows > 0) {
        for (row = 0; row < copyRows; ++row) {
            memset(destinationPixels, 0, 2 * clearWidth);
            destinationPixels += rowStridePixels;
        }
    }
    InitRectBounds(&dirtyRect,
                   clippedRect.right + deltaX,
                   clippedRect.top,
                   clippedRect.right,
                   clippedRect.top + copyRows);
    dirtyRegion->UnionWithRect(&dirtyRect);

    clearRows = -deltaY;
    clearY = clippedRect.bottom + deltaY;
    if (rectHeight < clearRows) {
        clearRows = rectHeight;
        clearY = clippedRect.top;
    }
    destinationPixels = pixels
        + (clearY - surfaceTop) * rowStridePixels
        + clippedRect.left - surfaceLeft;
    if (clearRows > 0) {
        for (row = 0; row < clearRows; ++row) {
            memset(destinationPixels, 0, 2 * rectWidth);
            destinationPixels += rowStridePixels;
        }
    }
    InitRectBounds(&dirtyRect,
                   clippedRect.left,
                   clippedRect.bottom + deltaY,
                   clippedRect.right,
                   clippedRect.bottom);
    dirtyRegion->UnionWithRect(&dirtyRect);
}

// UID:000167 | by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md | Completion:91 | Confidence:93
enum GrafPortBlitMode {
    kGrafPortBlitCopy = 0,
    kGrafPortBlitSourceColorKey = 1
};

void GrafPort::BlitSurface(GrafPort *source,
                           const RectBounds *sourceRect,
                           const RectBounds *destinationRect,
                           int mode)
{
    if (m_usesSoftwareBuffer) {
        source->UpdateSurfaceInfo();
        UpdateSurfaceInfo();

        const float savedAlpha = m_alpha;
        if (source->m_alpha <= 1.0f) {
            m_alpha = source->m_alpha;
        }

        g_pfnBlitSprite(this, &source->m_surfaceContext, sourceRect, destinationRect, mode, 0, NULL);

        if (savedAlpha <= 1.0f) {
            m_alpha = savedAlpha;
        }

        if (!m_usesSoftwareBuffer && m_ddSurface != 0) {
            m_ddSurface->Unlock(0);
        }
        m_surfaceContext.pixelData = 0;
        m_surfaceContext.rowStridePixels = 0;

        if (!source->m_usesSoftwareBuffer && source->m_ddSurface != 0) {
            source->m_ddSurface->Unlock(0);
        }
        source->m_surfaceContext.pixelData = 0;
        source->m_surfaceContext.rowStridePixels = 0;
        return;
    }

    RECT ddSourceRect;
    RECT ddDestinationRect;
    SetRect(&ddSourceRect, sourceRect->left, sourceRect->top, sourceRect->right, sourceRect->bottom);
    SetRect(&ddDestinationRect,
            destinationRect->left,
            destinationRect->top,
            destinationRect->right,
            destinationRect->bottom);

    if (mode == kGrafPortBlitSourceColorKey) {
        m_ddSurface->BltFast(ddDestinationRect.left,
                             ddDestinationRect.top,
                             source->m_ddSurface,
                             &ddSourceRect,
                             DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
        return;
    }

    if (mode == kGrafPortBlitCopy) {
        m_ddSurface->BltFast(ddDestinationRect.left,
                             ddDestinationRect.top,
                             source->m_ddSurface,
                             &ddSourceRect,
                             DDBLTFAST_WAIT);
        return;
    }

    source->UpdateSurfaceInfo();
    UpdateSurfaceInfo();

    const float savedAlpha = m_alpha;
    if (source->m_alpha <= 1.0f) {
        m_alpha = source->m_alpha;
    }

    g_pfnBlitSprite(this, &source->m_surfaceContext, sourceRect, destinationRect, mode, 0, NULL);

    if (savedAlpha <= 1.0f) {
        m_alpha = savedAlpha;
    }

    EndPaint();
    source->EndPaint();
}

// UID:000168 | by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md | Completion:88 | Confidence:90
void GrafPort::DrawRectFrame(const RectBounds *rect)
{
    if (!m_drawEnabled) {
        return;
    }

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds visibleRect = *rect;
    IntersectRects(&visibleRect, &clipRect, &visibleRect);
    if (IsRectEmptyOrInvalid(&visibleRect)) {
        return;
    }

    const int oldX = m_currentX;
    const int oldY = m_currentY;

    m_currentX = rect->left;
    m_currentY = rect->top;

    g_pfnDrawLineDelta(this, rect->right - rect->left - 1, 0);
    g_pfnDrawLineDelta(this,
                       rect->right - m_currentX - 1,
                       rect->bottom - m_currentY - 1);
    g_pfnDrawLineDelta(this,
                       rect->left - m_currentX,
                       rect->bottom - m_currentY - 1);
    g_pfnDrawLineDelta(this,
                       rect->left - m_currentX,
                       rect->top - m_currentY);

    m_currentX = oldX;
    m_currentY = oldY;
}

// UID:000169 | by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md | Completion:88 | Confidence:90
void GrafPort::CompositePixels(const RectBounds *rect)
{
    if (!m_drawEnabled)
        return;

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds clippedRect = *rect;
    IntersectRects(&clippedRect, &clipRect, &clippedRect);
    if (IsRectEmptyOrInvalid(&clippedRect))
        return;

    const int width = clippedRect.right - clippedRect.left;
    const int height = clippedRect.bottom - clippedRect.top;
    if (width <= 0 || height <= 0)
        return;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short fillColor =
        palette->MapColor(static_cast<unsigned int>(m_textColor));

    unsigned short *row =
        static_cast<unsigned short *>(m_surfaceContext.pixelData) +
        (clippedRect.top - m_surfaceContext.bounds.top) * m_surfaceContext.rowStridePixels +
        (clippedRect.left - m_surfaceContext.bounds.left);

    for (int y = 0; y < height; ++y) {
        unsigned short *pixel = row;
        for (int x = 0; x < width; ++x, ++pixel) {
            if (*pixel == 0) {
                *pixel = fillColor;
            } else {
                *pixel = static_cast<unsigned short>(~*pixel);
            }
        }

        row += m_surfaceContext.rowStridePixels;
    }
}

// UID:00016A | by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md | Completion:88 | Confidence:91
void GrafPort::DrawTiledBackground(const RectBounds *clipRect,
                                   const FrameDrawRecord *frameRecord,
                                   const wchar_t *paletteName)
{
    Region savedClipRegion;
    savedClipRegion.CopyRectFrom(m_clipRegion);
    m_clipRegion.SetRect(clipRect);

    const RectBounds *sourceRect = &frameRecord->sourceRect;
    const int tileWidth = sourceRect->right - sourceRect->left;
    const int tileHeight = sourceRect->bottom - sourceRect->top;

    if (tileWidth > 0 && tileHeight > 0) {
        const int rowCount =
            (m_visibleBounds.bottom - m_visibleBounds.top - 1) / tileHeight + 1;
        const int columnCount =
            (m_visibleBounds.right - m_visibleBounds.left - 1) / tileWidth + 1;

        RectBounds rowRect = m_visibleBounds;
        rowRect.right = rowRect.left + tileWidth;
        rowRect.bottom = rowRect.top + tileHeight;

        for (int row = 0; row < rowCount; ++row) {
            RectBounds destinationRect = rowRect;

            for (int column = 0; column < columnCount; ++column) {
                DLPalette *palette = g_pPaletteLib->GetPaletteByName(paletteName);

                g_pfnBlitSprite(this,
                    reinterpret_cast<const EPFTileContext *>(frameRecord),
                                sourceRect,
                                &destinationRect,
                                m_drawMode,
                                palette,
                                0);

                OffsetRect(&destinationRect, tileWidth, 0);
            }

            OffsetRect(&rowRect, 0, tileHeight);
        }

        m_clipRegion.CopyRectFrom(savedClipRegion);
    }
}

// UID:00016B | by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md | Completion:88 | Confidence:91
void GrafPort::FitTextAndAppendSuffix(wchar_t *text,
                                      size_t textCapacity,
                                      const wchar_t *suffix,
                                      int maxPixelWidth)
{
    const int textWidth = GetTextWidth(text, static_cast<int>(wcslen(text)));
    if (textWidth <= maxPixelWidth) {
        return;
    }

    const int suffixWidth = GetTextWidth(suffix, static_cast<int>(wcslen(suffix)));
    const int keepCount = CountCharsFittingWidth(text, maxPixelWidth - suffixWidth);

    text[keepCount] = L'\0';
    wcscat_s(text, textCapacity, suffix);
}

int GrafPort::CountCharsFittingWidth(const wchar_t *text, int maxPixelWidth)
{
    const int length = static_cast<int>(wcslen(text));
    StringIter iter(text, length);

    int visibleCount = 0;
    int width = 0;

    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        short advance = 0;
        g_pFontImageLib->MeasureGlyphWidth(m_fontId,
                                           ch,
                                           nextCh,
                                           0,
                                           0,
                                           NULL,
                                           &advance,
                                           NULL);

        width += advance;
        if (width > maxPixelWidth) {
            break;
        }

        ++visibleCount;
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }

    return visibleCount;
}

// UID:00016C | by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md | Completion:90 | Confidence:93
short GrafPort::GetTextWidth(const wchar_t *text, int charCount)
{
    StringIter iter(text, charCount);

    short totalWidth = 0;
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        short advance = 0;
        g_pFontImageLib->MeasureGlyphWidth(m_fontId,
                                           ch,
                                           nextCh,
                                           0,
                                           0,
                                           NULL,
                                           &advance,
                                           NULL);

        totalWidth = static_cast<short>(totalWidth + advance);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }

    return totalWidth;
}

short GrafPort::GetTextWidth(const wchar_t *text)
{
    return GetTextWidth(text, static_cast<int>(wcslen(text)));
}

short GrafPort::GetLineHeight()
{
    short lineHeight = 0;
    g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &lineHeight);
    return lineHeight;
}

unsigned short GrafPort::AdjustVisibleCountForTrailingWhitespace(
    const wchar_t *text, short count)
{
    const wchar_t *scan = text + count - 1;
    while (text <= scan) {
        const wchar_t ch = *scan;
        if (ch != L' ' && ch != L'\t' && ch != L'\r')
            break;
        --scan;
    }

    const int lastVisibleIndex = static_cast<int>(scan - text);
    return count <= lastVisibleIndex
        ? static_cast<unsigned short>(lastVisibleIndex)
        : static_cast<unsigned short>(count);
}

void GrafPort::DrawGlyphWithTextColors(wchar_t ch, wchar_t nextCh)
{
    unsigned char colors[6];

    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    DrawGlyph(ch, nextCh, 0, colors);
}

void GrafPort::DrawWideText(const wchar_t *text, int charCount)
{
    if (static_cast<short>(charCount) < 0)
        return;

    unsigned char colors[6];
    colors[0] = static_cast<unsigned char>(m_textBackColor);
    colors[1] = static_cast<unsigned char>(m_textColor);
    colors[2] = static_cast<unsigned char>(m_textBackColor);
    colors[3] = static_cast<unsigned char>(m_textColor);
    colors[4] = static_cast<unsigned char>(m_textColor);
    colors[5] = static_cast<unsigned char>(m_textBackColor);

    if (m_textDrawMode == 0 || m_textDrawMode == 2) {
        short lineHeight = 0;
        g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &lineHeight);

        RectBounds backgroundRect;
        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - lineHeight;
        backgroundRect.right = m_currentX + GetTextWidth(text, charCount);
        backgroundRect.bottom = m_currentY;

        const unsigned char oldDrawMode = m_drawMode;
        const unsigned int oldDrawColor = m_drawColor;

        m_drawMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillRect(this, &backgroundRect);
        m_drawMode = oldDrawMode;
        m_drawColor = oldDrawColor;
    }

    StringIter iter(text, charCount);
    wchar_t ch = static_cast<wchar_t>(iter.GetNextChar());
    wchar_t nextCh = static_cast<wchar_t>(iter.GetNextChar());

    while (ch != L'\0') {
        DrawGlyph(ch, nextCh, 0, colors);
        ch = nextCh;
        nextCh = static_cast<wchar_t>(iter.GetNextChar());
    }
}

void GrafPort::DrawOutlinedText(int x, int y,
                                const wchar_t *text, int charCount)
{
    const unsigned int oldTextColor = m_textColor;
    m_textColor = m_textBackColor;

    m_currentX = x;
    m_currentY = y - 1;
    DrawWideText(text, charCount);

    m_currentX = x;
    m_currentY = y + 1;
    DrawWideText(text, charCount);

    m_currentX = x - 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_currentX = x + 1;
    m_currentY = y;
    DrawWideText(text, charCount);

    m_textColor = oldTextColor;
    m_currentX = x;
    m_currentY = y;
    DrawWideText(text, charCount);
}

// UID:00016D | by-memory/0x004bad70-0x004baf92.DrawTextInRect.md | Completion:88 | Confidence:91
void GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)
{
    if (!m_drawEnabled) {
        return;
    }

    const int oldY = m_currentY;
    const int oldX = m_currentX;

    short lineHeight = 0;
    g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &lineHeight);

    int index = 0;
    m_currentX = rect->left;
    m_currentY = rect->top;

    while (index < length && m_currentY <= rect->bottom) {
        const wchar_t *lineStart = text + index;
        int fitCount = CountCharsFittingWidth(lineStart, rect->right - rect->left);

        if (index + fitCount > length) {
            fitCount = length - index;
        }

        wchar_t line[256];
        if (fitCount >= static_cast<int>(_countof(line))) {
            __report_rangecheckfailure();
        }

        memmove(line, lineStart, fitCount * sizeof(wchar_t));
        line[fitCount] = L'\0';

        m_currentY += lineHeight;

        if (m_textAlign == 2) {
            m_currentX = rect->right - GetTextWidth(line, fitCount);
        } else if (m_textAlign == 1) {
            const int rectCenter = (rect->left + rect->right) / 2;
            m_currentX = rectCenter - (GetTextWidth(line, fitCount) / 2);
        } else {
            m_currentX = rect->left;
        }

        DrawWideText(line, fitCount);

        index += fitCount;
        if (text[index] == L' ') {
            ++index;
        }
    }

    m_currentX = oldX;
    m_currentY = oldY;
}

// UID:0004NH | by-memory/0x004bafa0-0x004bb06a.GrafPortDrawOutlinedTextInRect.md | Completion:93 | Confidence:94
void GrafPort::DrawOutlinedText(const wchar_t *text, int length, const RectBounds *rect)
{
    const unsigned int oldTextColor = m_textColor;
    m_textColor = m_textBackColor;

    RectBounds outlineRect = *rect;
    outlineRect.Offset(-1, 0);
    DrawTextInRect(text, length, &outlineRect);

    outlineRect.Offset(2, 0);
    DrawTextInRect(text, length, &outlineRect);

    outlineRect.Offset(-1, -1);
    DrawTextInRect(text, length, &outlineRect);

    outlineRect.Offset(0, 2);
    DrawTextInRect(text, length, &outlineRect);

    m_textColor = oldTextColor;
    DrawTextInRect(text, length, rect);
}

// UID:0004NI | by-memory/0x004bb080-0x004bb0db.GrafPortDrawShadowedTextInRect.md | Completion:92 | Confidence:93
void GrafPort::DrawShadowedText(const wchar_t *text, int length, const RectBounds *rect)
{
    RectBounds shadowRect = *rect;
    shadowRect.Offset(1, 0);

    DrawTextInRect(text, length, rect);
    DrawTextInRect(text, length, &shadowRect);
}

// UID:0003XE | by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md | Completion:92 | Confidence:93
void GrafPort::BlitTileContextToSurface(
    const EPFTileContext *sourceContext,
    DLPalette *palette)
{
    MemoryMan *memoryMan = GetMemoryMan();

    UpdateRenderRegion(&sourceContext->bounds);
    if (palette == NULL) {
        palette = g_pPaletteLib->GetCurrentPalette();
    }

    const int rowCount =
        sourceContext->bounds.bottom - sourceContext->bounds.top;
    const int byteCount =
        2 * sourceContext->rowStridePixels * rowCount;
    m_surfaceContext.pixelData =
        memoryMan->ReallocateBufferMemory(
            m_surfaceContext.pixelData, byteCount);
    m_surfaceContext.rowStridePixels = sourceContext->rowStridePixels;
    m_surfaceContext.bounds = sourceContext->bounds;

    g_pfnBlitSprite(this,
                    sourceContext,
                    &sourceContext->bounds,
                    &m_surfaceContext.bounds,
                    0,
                    palette,
                    NULL);
}

// UID:0003XF | by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md | Completion:91 | Confidence:92
static void __stdcall PackTwoColorSixPixelPattern(
    unsigned char foreground,
    unsigned char background,
    unsigned char *pattern)
{
    pattern[0] = background;
    pattern[1] = foreground;
    pattern[2] = background;
    pattern[3] = foreground;
    pattern[4] = foreground;
    pattern[5] = background;
}

// UID:00016I | by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md | Completion:90 | Confidence:92
void GrafPort::DrawGlyph(wchar_t ch, wchar_t nextCh, bool fillBackground, const unsigned char *glyphColors)
{
    EPFTileContext glyphContext;
    RectBounds backgroundRect;
    RectBounds destinationRect;
    short glyphAdvance = 0;
    short fontWidth = 0;
    short fontHeight = 0;
    unsigned char blitMode;


    if (!m_drawEnabled) {
        return;
    }

    g_pFontImageLib->MeasureGlyphWidth(m_fontId,
                                       ch,
                                       0,
                                       1,
                                       glyphColors,
                                       NULL,
                                       &glyphAdvance,
                                       &glyphContext);

    if (fillBackground) {
        unsigned char savedRenderMode;
        unsigned int savedDrawColor;

        g_pFontImageLib->GetFontMetrics(m_fontId, &fontWidth, &fontHeight);

        backgroundRect.left = m_currentX;
        backgroundRect.top = m_currentY - fontHeight;
        backgroundRect.right = m_currentX + fontWidth;
        backgroundRect.bottom = m_currentY;

        savedRenderMode = m_drawMode;
        savedDrawColor = m_drawColor;
        m_drawMode = m_textDrawMode;
        m_drawColor = m_textBackFillColor;
        g_pfnFillRect(this, &backgroundRect);
        m_drawMode = savedRenderMode;
        m_drawColor = savedDrawColor;
    }

    g_pFontImageLib->GetFontMetrics(m_fontId, NULL, &fontHeight);

    if (static_cast<unsigned short>(ch) <= 0x00ff && m_fontId != 0) {
        destinationRect.left = m_currentX + glyphContext.bounds.left - 2;
        destinationRect.top = m_currentY - fontHeight + glyphContext.bounds.top - 1;
        destinationRect.right = m_currentX + glyphContext.bounds.right - 2;
        destinationRect.bottom = m_currentY - fontHeight + glyphContext.bounds.bottom - 1;
    } else {
        destinationRect.left = m_currentX + glyphContext.bounds.left;
        destinationRect.top = m_currentY - fontHeight + glyphContext.bounds.top + 1;
        destinationRect.right = m_currentX + glyphContext.bounds.right;
        destinationRect.bottom = m_currentY - fontHeight + glyphContext.bounds.bottom + 1;
    }

    if (m_textDrawMode == 0) {
        blitMode = 1;
    } else if (m_textDrawMode == 2) {
        blitMode = 3;
    } else {
        blitMode = m_textDrawMode;
    }

    g_pfnBlitSprite(this,
                    &glyphContext,
                    &glyphContext.bounds,
                    &destinationRect,
                    blitMode,
                    m_palette,
                    0);

    m_currentX += glyphAdvance;
}

// UID:0003BE | by-memory/0x0061a8a4-0x0061a8b8.GrafPortVtableData.md | Completion:93 | Confidence:95
// Compiler-generated from the complete GrafPort class declaration and virtual method definitions.

// UID:0002V5 | by-memory/0x0061a8b8-0x0061a920.GrafPortSurfaceDescStringData.md | Completion:94 | Confidence:95
// Source-covered by the wide diagnostic literal in GrafPort::UpdateRenderRegion.
