// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IZ
// Source by-file doc: by-file/Effects.md
// UID:00002T | by-class/CloudFilterEffecter.md | Completion:85 | Confidence:88
class CloudFilterEffecter : public FilterEffecter
{
public:
    CloudFilterEffecter();
};

// UID:000046 | by-class/EarthquakeEffecter.md | Completion:87 | Confidence:88
class EarthquakeEffecter : public PixelEffecter
{
public:
    EarthquakeEffecter(unsigned short xAmplitude, unsigned short yAmplitude);
    virtual ~EarthquakeEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    unsigned short m_xAmplitude;
    unsigned short m_yAmplitude;
    int m_currentYOffset;
    int m_currentXOffset;
    unsigned int m_lastShakeTick;

    [[No Children Attached]]
};

// UID:000049 | by-class/EffectObjectPane.md | Completion:85 | Confidence:86
#include "../util/PoolAllocator.h"

// EffectObjectPane class-level source remains intentionally withheld here.
// Exact source-bearing children emit the audited methods and static storage.
// UID:0002QV | by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md | Completion:88 | Confidence:92
EffectObjectPane::~EffectObjectPane()
{
}

// UID:0001DA | by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md | Completion:89 | Confidence:92
void EffectObjectPane::StartIdleTimer()
{
    TimerHandler::ScheduleTimer(1, 0, 0, 0);
}

// UID:00023H | by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md | Completion:88 | Confidence:92
bool EffectObjectPane::IsLooping() const
{
    return m_looping;
}


// UID:000351 | by-memory/0x006205f8-0x006206ac.EffectObjectPaneVtableData.md | Completion:88 | Confidence:92
// Emitted code for this range is covered by [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md).

// UID:0002WO | by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md | Completion:92 | Confidence:94
static PoolAllocator g_effectObjectPanePool(0x150, 0x10);

// UID:00004Y | by-class/FilterEffecter.md | Completion:88 | Confidence:90
class FilterEffecter : public ScreenEffecter, public Pane
{
public:
    FilterEffecter();
    virtual ~FilterEffecter();

    bool IsPixelEffecter() const override { return false; }
};

// UID:000070 | by-class/LakeEffecter.md | Completion:86 | Confidence:88
class LakeEffecter : public PixelEffecter
{
public:
    explicit LakeEffecter(float blendFactor);
    virtual ~LakeEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    float m_blendFactor;
    unsigned int m_lastRenderTick;




};

// UID:00009W | by-class/OverlayEffecter.md | Completion:90 | Confidence:91
class OverlayEffecter : public PixelEffecter, public Pane
{
public:
    OverlayEffecter(unsigned char paneMode,
                    unsigned short overlayX,
                    unsigned short overlayY);
    virtual ~OverlayEffecter();

protected:
    unsigned short m_overlayX;
    unsigned short m_overlayY;
};

// UID:00009X | by-class/OverlayFrameImageEffecter.md | Completion:88 | Confidence:91
class OverlayFrameImageEffecter : public OverlayEffecter
{
public:
    OverlayFrameImageEffecter(const wchar_t *frameResourceName,
                              const wchar_t *paletteName,
                              int overlayX,
                              int overlayY,
                              int frameIndex);
    virtual ~OverlayFrameImageEffecter();

    virtual void RenderOverlayFrame();

private:
    wchar_t m_frameResourceName[16];
    wchar_t m_paletteName[16];
    ArchiveMetadataTable *m_frameTable;
    FrameDrawRecord m_frameDrawRecord;
    short m_frameIndex;
};

// UID:00009Y | by-class/OverlayImageEffecter.md | Completion:88 | Confidence:91
OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName,
                                           const wchar_t *paletteName,
                                           unsigned short overlayX,
                                           unsigned short overlayY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    m_tileContext.Init();
    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_paletteName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_tileContext);
    m_isVisible = true;
}

void OverlayImageEffecter::ApplyOverlayImage()
{
    RectBounds viewportBounds;
    g_activeMapPane->GetBounds(&viewportBounds);

    g_activeMapPane->RenderTileFrame(&m_tileContext,
                                     &m_tileContext.bounds,
                                     &viewportBounds,
                                     1,
                                     m_paletteName,
                                     0);
}

// UID:00009Z | by-class/OverlayImageOnPointEffecter.md | Completion:88 | Confidence:91
OverlayImageOnPointEffecter::OverlayImageOnPointEffecter(const wchar_t *imageName,
                                                         const wchar_t *paletteName,
                                                         short overlayX,
                                                         short overlayY,
                                                         short pointX,
                                                         short pointY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    m_frameRecord.tileContext.Init();
    m_frameRecord.imageBlock = LoadImageFrameTable(imageName, 0);

    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_paletteName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_frameRecord.tileContext);

    m_pointX = pointX;
    m_pointY = pointY;
    m_drawPointX = pointX;
    m_drawPointY = pointY;

    m_active = true;
    m_drawBounds.right = 300;
    m_drawBounds.bottom = 300;
}

OverlayImageOnPointEffecter::~OverlayImageOnPointEffecter()
{
    DestroyOwnedImageBlock(g_pEPFLib, m_frameRecord.imageBlock);
}

void OverlayImageOnPointEffecter::RenderOverlayImageAtPoint()
{
    RenderTileFrame(&m_frameRecord.tileContext,
                    &m_frameRecord.sourceRect,
                    &m_drawBounds,
                    m_drawMode,
                    m_paletteName,
                    0);
}

// UID:0000A0 | by-class/OverlayMovingImageEffecter.md | Completion:88 | Confidence:90
enum OverlayMoveDirection {
    kOverlayMoveRight = 1,
    kOverlayMoveLeft = 2,
    kOverlayMoveDown = 3,
    kOverlayMoveUp = 4
};

OverlayMovingImageEffecter::OverlayMovingImageEffecter(const wchar_t *imageName,
                                                       const wchar_t *paletteName,
                                                       short paneWidth,
                                                       short paneHeight,
                                                       short moveRangeY,
                                                       short moveRangeX,
                                                       short stepPixels,
                                                       short directionMode)
    : OverlayEffecter(1, paneWidth, paneHeight)
{
    m_frameRecord.tileContext.Init();
    m_frameRecord.imageBlock = LoadImageFrameTable(imageName, 0);

    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_overlayName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_frameRecord.tileContext);

    m_moveRangeX = moveRangeX;
    m_moveRangeY = moveRangeY;
    m_stepPixels = stepPixels;
    m_directionMode = directionMode;

    m_savedVerticalReset = m_scrollY2;
    m_savedHorizontalReset = m_scrollX;
    m_active = 1;

    m_scrollY2 += m_stepPixels;
    m_scrollX += m_directionMode;
    m_drawBounds.bottom -= m_stepPixels;
    m_drawBounds.right -= m_directionMode;
    m_savedDrawBounds = m_drawBounds;
}

OverlayMovingImageEffecter::~OverlayMovingImageEffecter()
{
    DestroyOwnedImageBlock(g_pEPFLib, m_frameRecord.imageBlock);
}

void OverlayMovingImageEffecter::OnPaint()
{
    switch (m_directionMode) {
    case kOverlayMoveRight:
        m_scrollX += m_stepPixels;
        if (m_scrollX >= m_wrapXStart + m_wrapXSpan) {
            m_scrollX = m_wrapXStart;
        }
        m_drawBounds.right = m_wrapXStart + m_wrapXSpan - m_scrollX;
        break;

    case kOverlayMoveLeft:
        m_scrollX -= m_stepPixels;
        if (m_scrollX + m_viewWidth == g_mapTilePixelWidth) {
            m_scrollX = m_wrapXSpan;
        }
        m_drawBounds.right = g_mapTilePixelWidth + m_wrapXSpan - m_scrollX;
        break;

    case kOverlayMoveDown:
        m_scrollY += m_stepPixels;
        if (m_scrollY == m_wrapYSpan) {
            m_scrollY = m_savedVerticalReset;
        }
        m_drawBounds.bottom = g_mapTilePixelHeight + m_wrapYSpan - m_scrollY;
        break;

    case kOverlayMoveUp:
        m_scrollY -= m_stepPixels;
        if (m_scrollY + m_viewHeight == g_mapTilePixelHeight) {
            m_scrollY = m_wrapYSpan;
        }
        m_drawBounds.bottom = g_mapTilePixelHeight + m_wrapYSpan - m_scrollY;
        break;
    }

    RenderTileFrame(&m_frameRecord,
                    &m_frameRecord.sourceRect,
                    &m_drawBounds,
                    m_drawMode,
                    m_paletteLookupKey,
                    0);
}

// UID:0000AI | by-class/PixelEffecter.md | Completion:85 | Confidence:88
class PixelEffecter : public ScreenEffecter
{
public:
    PixelEffecter();

    bool IsPixelEffecter() const override { return true; }
};

// UID:0000C9 | by-class/ScreenEffecter.md | Completion:86 | Confidence:90
// ScreenEffecter is the root virtual interface for the Effects family.
// Formal class C++ is intentionally withheld until the three state-predicate
// slot names used by AreAllEffectsComplete are source-quality. Current MCP
// confirms the 0x0055c1d0 body and folded true/false stubs, but only the
// IsPixelEffecter direction is naming-ready.

// UID:0000DE | by-class/SolidColorFilterEffecter.md | Completion:85 | Confidence:88
class SolidColorFilterEffecter : public FilterEffecter
{
public:
    SolidColorFilterEffecter(unsigned char red,
                             unsigned char green,
                             unsigned char blue,
                             float alpha);
    virtual ~SolidColorFilterEffecter();

    virtual void FillBuffer();

private:
    unsigned short m_fillColor;
};

// UID:0000E0 | by-class/StaticCloudFilterEffecter.md | Completion:86 | Confidence:87
class StaticCloudFilterEffecter : public FilterEffecter
{
public:
    StaticCloudFilterEffecter();

};

// UID:0000FZ | by-class/WaterFilterEffecter.md | Completion:86 | Confidence:90
class WaterFilterEffecter : public FilterEffecter
{
public:
    WaterFilterEffecter();
    virtual ~WaterFilterEffecter();

    virtual void OnPaint();

private:
    float m_causticDrawAlpha;
    ArchiveMetadataTable *m_causticFrameTable;
    void *m_causticPalette;
    unsigned int m_lastCausticTick;
    unsigned short m_causticFrameIndex;

// UID:0001GF | by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md | Completion:88 | Confidence:91
void WaterFilterEffecter::OnPaint()
{
    FrameDrawRecord frameRecord;

    unsigned int currentTick = g_pTimerMgr->m_currentTick;
    if (currentTick <= m_lastCausticTick + 60) {
        return;
    }

    unsigned short frameIndex = static_cast<unsigned short>(m_causticFrameIndex + 1);
    m_lastCausticTick = currentTick;

    if (frameIndex >= 32) {
        frameIndex = 0;
    }
    m_causticFrameIndex = frameIndex;

    LoadFrameDrawRecord(m_causticFrameTable, frameIndex, &frameRecord);

    float savedAlpha = m_alpha;
    m_alpha = m_causticDrawAlpha;
    m_drawMode = 2;

    DrawTiledBackground(&m_localBounds, &frameRecord, L"CAUST.PAL");

    m_drawMode = 0;
    m_alpha = savedAlpha;
}
};

// UID:0000GC | by-class/XWaveEffecter.md | Completion:86 | Confidence:87
class XWaveEffecter : public PixelEffecter
{
public:
    XWaveEffecter(float amplitude, short wavelength, short period);
    virtual ~XWaveEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    float m_amplitude;
    short m_wavelength;
    short m_period;
    unsigned int m_lastPhaseTick;
};

// UID:0000GD | by-class/YFlipEffecter.md | Completion:86 | Confidence:88
class YFlipEffecter : public PixelEffecter
{
public:
    YFlipEffecter();
    virtual ~YFlipEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);


};

// UID:0000VE | by-item/ScreenEffecterSmallConstructorBoundaries.md | Completion:85 | Confidence:90
// Raw constructor-boundary support only. The six constructor-shaped byte
// islands are source-authored, but current MCP still reports no IDA function
// objects and no direct xrefs to their starts. Emit declarations or exact child
// bodies from the owning class/memory pages, not from this support aggregate.

// UID:0001GE | by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md | Completion:88 | Confidence:90
// ScreenEffecterRuntimeCluster is a broad Effects.cpp aggregate over the
// ScreenEffecter runtime family. Exact class and by-memory method pages emit
// declarations or bodies; this page remains the comment-only evidence marker
// for 0x0055a260-0x0055c1ff boundaries, vtable stores, raw constructor islands,
// callees, and source placement under Effects.cpp.


// UID:0001YO | by-type/by-vtable/ScreenEffecterVtableFamily.md | Completion:88 | Confidence:92
// ScreenEffecter vtable-family bytes are compiler-emitted from the class
// declarations and virtual methods in the Effects family. This page is the
// layout authority and should not hand-author static vtable data.

// UID:000382 | by-memory\0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003HA | by-memory\0x0055b810-0x0055b851.LakeEffecterConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003HC | by-memory\0x0055b860-0x0055b866.LakeEffecterResetVtable.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003HB | by-memory\0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003HD | by-memory\0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003O9 | by-memory\0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003OA | by-memory\0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003OB | by-memory\0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003EH | by-memory\0x00623d18-0x00623d58.ScreenEffecterResourceStringsAndConstants.md | Completion:85 | Confidence:90 | Empty Emitter Marker
