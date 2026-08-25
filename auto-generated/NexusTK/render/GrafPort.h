// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JR
// Source by-file doc: by-file/GrafPort.md
// UID:00005V | by-class/GrafPort.md | Completion:94 | Confidence:95
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
