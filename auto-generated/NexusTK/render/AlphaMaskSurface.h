// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HF
// Source by-file doc: by-file/AlphaMaskSurface.md
// UID:0001TQ | by-type/by-struct/AlphaSurfaceBufferView.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_RENDER_ALPHASURFACEBUFFERVIEW_DEFINED
#define NEXUSTK_RENDER_ALPHASURFACEBUFFERVIEW_DEFINED

struct AlphaSurfaceBufferView
{
    unsigned char *pixels;
    int width;
    int height;
    int stride;
    bool ownsBuffer;
    unsigned char padding[3];
};

#endif

// UID:00006K | by-class/IntAlphaSurface.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_RENDER_ALPHAMASKSURFACE_H
#define NEXUSTK_RENDER_ALPHAMASKSURFACE_H

#include "../ui/core/RectBounds.h"

struct EPFTileContext;

enum AlphaMaskBlendMode
{
    kAlphaMaskBlendCopy = 0,
    kAlphaMaskBlendAdd = 1,
    kAlphaMaskBlendSubtract = 2
};

class IntAlphaSurface
{
public:
    virtual ~IntAlphaSurface();
    virtual void ReleaseOwnedPixels();

    // UID:0000YK | by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md | Completion:92 | Confidence:94
    IntAlphaSurface();

// UID:00054W | by-memory/0x00462170-0x00462227.IntAlphaSurfaceConstructor.md | Completion:93 | Confidence:95
    IntAlphaSurface(int width, int height);

// UID:0004FR | by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md | Completion:93 | Confidence:95
    // Declaration is in the class shell to preserve vtable slot order.

// UID:00054X | by-memory/0x004622d0-0x004622f7.IntAlphaSurfaceGetCenterPoint.md | Completion:92 | Confidence:94
    void GetCenterPoint(Point *point) const;

// UID:00054Y | by-memory/0x00462300-0x00462317.IntAlphaSurfaceGetBufferInfo.md | Completion:93 | Confidence:95
    void GetBufferInfo(AlphaSurfaceBufferView *outView) const;

// UID:00054Z | by-memory/0x00462320-0x004623b5.IntAlphaSurfaceGetClippedBufferInfo.md | Completion:93 | Confidence:95
    void GetClippedBufferInfo(AlphaSurfaceBufferView *outView,
                              const RectBounds *clipBounds) const;

// UID:0002NM | by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md | Completion:93 | Confidence:94
    IntAlphaSurface *InitSurfaceView(IntAlphaSurface *view,
                                     const RectBounds *clipBounds) const;

// UID:000550 | by-memory/0x00462520-0x00462672.IntAlphaSurfaceApplyRectAlpha.md | Completion:93 | Confidence:95
    void ApplyRectAlpha(const RectBounds *bounds,
                        unsigned char alpha,
                        AlphaMaskBlendMode blendMode);

// UID:000551 | by-memory/0x00462680-0x0046286b.IntAlphaSurfaceFillRadialGradient.md | Completion:92 | Confidence:94
    void FillRadialGradient(int centerY,
                            int centerX,
                            int radius,
                            unsigned char centerAlpha,
                            unsigned char edgeAlpha,
                            float exponent,
                            AlphaMaskBlendMode blendMode);

// UID:000552 | by-memory/0x00462870-0x00462e03.IntAlphaSurfaceFillEllipticGradient.md | Completion:92 | Confidence:94
    void FillEllipticGradient(int centerY,
                              int centerX,
                              int radiusY,
                              int radiusX,
                              int innerRadius,
                              unsigned char centerAlpha,
                              unsigned char edgeAlpha,
                              float exponent,
                              AlphaMaskBlendMode blendMode);

// UID:0000YN | by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md | Completion:93 | Confidence:95
    void DrawFrameWithBlendMode(const RectBounds *destinationRect,
                                const IntAlphaSurface *sourceFrame,
                                const RectBounds *sourceRect,
                                AlphaMaskBlendMode blendMode);

// UID:0000YO | by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md | Completion:93 | Confidence:95
    void DrawEncodedAlphaFrame(const RectBounds *destinationRect,
                               const EPFTileContext *sourceContext,
                               const RectBounds *sourceOrigin,
                               int alphaEndY,
                               unsigned char alphaEnd,
                               int alphaStartY,
                               unsigned char alphaStart,
                               AlphaMaskBlendMode blendMode);

// UID:0000YP | by-memory/0x00463270-0x004632b1.IntAlphaSurface.md | Completion:93 | Confidence:95
    // Declaration is in the class shell to preserve vtable slot order.

private:
    RectBounds m_bounds;
    unsigned char *m_pixels;
    int m_width;
    int m_height;
    int m_stride;
    bool m_ownsBuffer;
    unsigned char m_padding[3];
};

#endif
