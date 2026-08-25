// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P8
// Source by-file doc: by-file/WeatherLayerPane.md
// UID:0001ON | by-memory/0x006702c8-0x00670784.RainCoordinateTables.md | Completion:93 | Confidence:94
struct RainStreak {
    short x;
    short y;
    short length;
};

struct RainSplash {
    short x;
    short y;
};

static RainStreak s_targetRainStreaks[3][24] = {
    {
        { 87, 1, 30 }, { 167, 17, 30 }, { 215, 1, 46 },
        { 247, 65, 30 }, { 335, 9, 22 }, { 357, 40, 14 },
        { 39, 113, 30 }, { 103, 97, 46 }, { 151, 161, 30 },
        { 199, 145, 30 }, { 263, 129, 46 }, { 319, 97, 42 },
        { 357, 159, 30 }, { 39, 225, 30 }, { 95, 257, 22 },
        { 199, 257, 22 }, { 228, 295, 4 }, { 295, 289, 8 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 23, 1, 14 }, { 39, 49, 46 }, { 79, 1, 6 },
        { 105, 1, 18 }, { 231, 17, 30 }, { 319, 1, 7 },
        { 335, 33, 30 }, { 355, 73, 26 }, { 55, 145, 46 },
        { 143, 97, 54 }, { 135, 193, 46 }, { 191, 129, 30 },
        { 279, 129, 46 }, { 356, 161, 47 }, { 55, 290, 9 },
        { 103, 303, 3 }, { 199, 209, 30 }, { 215, 273, 17 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 15, 1, 22 }, { 39, 33, 30 }, { 119, 21, 54 },
        { 167, 1, 14 }, { 7, 129, 7 }, { 127, 213, 38 },
        { 215, 33, 46 }, { 237, 83, 52 }, { 256, 185, 14 },
        { 354, 69, 6 }, { 31, 177, 20 }, { 71, 225, 30 },
        { 103, 189, 10 }, { 183, 225, 40 }, { 247, 177, 46 },
        { 279, 257, 23 }, { 336, 265, 20 }, { 307, 1, 14 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    }
};

static RainSplash s_targetRainSmallSplashes[3][7] = {
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    },
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    }
};

static RainSplash s_targetRainLargeSplashes[3][7] = {
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    },
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    }
};

static RainStreak s_rainStreaks[3][24] = {
    {
        { 87, 1, 30 }, { 167, 17, 30 }, { 215, 1, 46 },
        { 247, 65, 30 }, { 335, 9, 22 }, { 357, 40, 14 },
        { 39, 113, 30 }, { 103, 97, 46 }, { 151, 161, 30 },
        { 199, 145, 30 }, { 263, 129, 46 }, { 319, 97, 42 },
        { 357, 159, 30 }, { 39, 225, 30 }, { 95, 257, 22 },
        { 199, 257, 22 }, { 228, 295, 4 }, { 295, 289, 8 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 23, 1, 14 }, { 39, 49, 46 }, { 79, 1, 6 },
        { 105, 1, 18 }, { 231, 17, 30 }, { 319, 1, 7 },
        { 335, 33, 30 }, { 355, 73, 26 }, { 55, 145, 46 },
        { 143, 97, 54 }, { 135, 193, 46 }, { 191, 129, 30 },
        { 279, 129, 46 }, { 356, 161, 47 }, { 55, 290, 9 },
        { 103, 303, 3 }, { 199, 209, 30 }, { 215, 273, 17 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    },
    {
        { 15, 1, 22 }, { 39, 33, 30 }, { 119, 21, 54 },
        { 167, 1, 14 }, { 7, 129, 7 }, { 127, 213, 38 },
        { 215, 33, 46 }, { 237, 83, 52 }, { 256, 185, 14 },
        { 354, 69, 6 }, { 31, 177, 20 }, { 71, 225, 30 },
        { 103, 189, 10 }, { 183, 225, 40 }, { 247, 177, 46 },
        { 279, 257, 23 }, { 336, 265, 20 }, { 307, 1, 14 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
        { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }
    }
};

static RainSplash s_rainSmallSplashes[3][7] = {
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    },
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    }
};

static RainSplash s_rainLargeSplashes[3][7] = {
    {
        { 161, 118 }, { 289, 38 }, { 103, 45 }, { 225, 198 },
        { 273, 278 }, { 321, 314 }, { 353, 294 }
    },
    {
        { 24, 122 }, { 87, 122 }, { 135, 60 }, { 295, 90 },
        { 39, 218 }, { 119, 234 }, { 135, 170 }
    },
    {
        { 273, 102 }, { 273, 134 }, { 353, 134 }, { 97, 182 },
        { 97, 246 }, { 161, 230 }, { 305, 230 }
    }
};

// UID:0001WJ | by-type/by-struct/WeatherLayerDataLayouts.md | Completion:93 | Confidence:94
// RainStreak and RainSplash emit with UID0001ON; the exact unsigned snow arrays emit with [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md); this support page does not duplicate either private CPP body.

// UID:0001OO | by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md | Completion:93 | Confidence:94
static unsigned char s_targetSnowTypeThresholds[4] = {
    0, 50, 100, 0
};

static unsigned char s_targetSnowSizes[4] = {
    4, 3, 0, 0
};

static unsigned char s_targetSnowPatterns[2][16] = {
    {
         0, 15, 15,  0,
        15, 15, 15, 15,
        15, 15, 15, 15,
         0, 15, 15,  0
    },
    {
         0, 15,  0,
        15, 15, 15,
         0, 15,  0,
         0,  0,  0,  0,  0,  0,  0
    }
};

static unsigned char s_snowTypeThresholds[4] = {
    0, 50, 100, 0
};

static unsigned char s_snowSizes[4] = {
    4, 3, 0, 0
};

static unsigned char s_snowPatterns[2][16] = {
    {
         0, 15, 15,  0,
        15, 15, 15, 15,
        15, 15, 15, 15,
         0, 15, 15,  0
    },
    {
         0, 15,  0,
        15, 15, 15,
         0, 15,  0,
         0,  0,  0,  0,  0,  0,  0
    }
};

// UID:0000G1 | by-class/WeatherLayerPane.md | Completion:90 | Confidence:93
// The complete WeatherLayerPane declaration belongs in canonical
// WeatherLayerPane.h; this source route emits its qualified child definitions.
// UID:0003PG | by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md | Completion:92 | Confidence:94
WeatherLayerPane::WeatherLayerPane()
    : Pane(true)
{
    if (g_useEpfAssets) {
        m_weatherBounds.left = 0;
        m_weatherBounds.top = 0;
        m_weatherBounds.right = 15 * g_mapTilePixelWidth;
        m_weatherBounds.bottom = 17 * g_mapTilePixelHeight;
    } else {
        m_weatherBounds.left = 12;
        m_weatherBounds.top = 14;
        m_weatherBounds.right = 15 * g_mapTilePixelWidth + 12;
        m_weatherBounds.bottom = 17 * g_mapTilePixelHeight + 14;
    }

    m_currentFrame = 0;
    m_frameCount = 0;
    m_timerInterval = 0;
    ScheduleTimer(0, 0, 0, 0);
}

// UID:0003PH | by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md | Completion:92 | Confidence:94
bool WeatherLayerPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0) {
        m_currentFrame = (m_currentFrame + 1) % m_frameCount;
        InvalidateRect(&m_visibleBounds);
        OnFrameChanged();
        ScheduleTimer(0, m_timerInterval, 0, 0);
    }

    return true;
}

// UID:0002Z7 | by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md | Completion:88 | Confidence:92
// WeatherLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.

// UID:0000BJ | by-class/RainingLayerPane.md | Completion:91 | Confidence:93
// The complete RainingLayerPane declaration belongs in canonical
// WeatherLayerPane.h; this source route emits its qualified child definitions.
// UID:0003PI | by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md | Completion:92 | Confidence:94
RainingLayerPane::RainingLayerPane()
{
    m_timerInterval = 120;
    m_frameCount = 3;
    m_drawOnTarget = true;
}

// UID:0003PJ | by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md | Completion:92 | Confidence:94
void RainingLayerPane::OnPaint()
{
    SetDrawColor(0);
    g_pfnFillRect(this, &m_bounds);

    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    const unsigned int rainColor = 143;
    SetDrawColor(rainColor);

    int i;
    for (i = 0; i < 18; ++i) {
        MoveTo(
            2 * (17 * s_rainStreaks[m_currentFrame][i].x / 15),
            2 * (15 * s_rainStreaks[m_currentFrame][i].y / 13));
        g_pfnDrawLineDelta(
            this,
            2 * (-17 * s_rainStreaks[m_currentFrame][i].length / 15),
            2 * (30 * s_rainStreaks[m_currentFrame][i].length / 13));
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            this,
            2 * (17 * s_rainSmallSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_rainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            this,
            2 * (17 * (s_rainSmallSplashes[m_currentFrame][i].x + 2) / 15),
            2 * (15 * (s_rainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            this,
            2 * (17 * s_rainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * s_rainLargeSplashes[m_currentFrame][i].y / 13),
            rainColor);
        g_pfnDrawPixel(
            this,
            2 * (17 * s_rainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_rainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            this,
            2 * (17 * (s_rainLargeSplashes[m_currentFrame][i].x + 4) / 15),
            2 * (15 * (s_rainLargeSplashes[m_currentFrame][i].y + 6) / 13),
            rainColor);
        g_pfnDrawPixel(
            this,
            2 * (17 * (s_rainLargeSplashes[m_currentFrame][i].x + 6) / 15),
            2 * (15 * (s_rainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }
}

// UID:0003PK | by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md | Completion:92 | Confidence:94
void RainingLayerPane::DrawOnTarget(
    GrafPort *target,
    const RectBounds *,
    const RectBounds *)
{
    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    const unsigned int rainColor = 143;
    target->SetDrawColor(rainColor);

    int i;
    for (i = 0; i < 18; ++i) {
        target->MoveTo(
            2 * (17 * s_targetRainStreaks[m_currentFrame][i].x / 15),
            2 * (15 * s_targetRainStreaks[m_currentFrame][i].y / 13));
        g_pfnDrawLineDelta(
            target,
            2 * (-17 * s_targetRainStreaks[m_currentFrame][i].length / 15),
            2 * (30 * s_targetRainStreaks[m_currentFrame][i].length / 13));
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainSmallSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_targetRainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainSmallSplashes[m_currentFrame][i].x + 2) / 15),
            2 * (15 * (s_targetRainSmallSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }

    for (i = 0; i < 7; ++i) {
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * s_targetRainLargeSplashes[m_currentFrame][i].y / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * s_targetRainLargeSplashes[m_currentFrame][i].x / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainLargeSplashes[m_currentFrame][i].x + 4) / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 6) / 13),
            rainColor);
        g_pfnDrawPixel(
            target,
            2 * (17 * (s_targetRainLargeSplashes[m_currentFrame][i].x + 6) / 15),
            2 * (15 * (s_targetRainLargeSplashes[m_currentFrame][i].y + 4) / 13),
            rainColor);
    }
}

// UID:0002Z8 | by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md | Completion:89 | Confidence:93
// RainingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.

// UID:0000DC | by-class/SnowingLayerPane.md | Completion:91 | Confidence:93
// SnowingLayerPane class-owned methods, descriptor consumers, and vtable support emit on exact child pages; no duplicate broad class body is emitted here.
// UID:0003O0 | by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md | Completion:92 | Confidence:94
SnowingLayerPane::SnowingLayerPane()
{
    m_currentFrame = 4;
    m_frameCount = 5;
    m_timerInterval = 200;

    for (int i = 0; i < 200; ++i) {
        InitRectBounds(&m_snowParticles[i].bounds, 0, 800, 8, 808);
        m_snowParticles[i].type = 0;
    }

    m_drawOnTarget = true;
}

// UID:0003O1 | by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md | Completion:88 | Confidence:89
void SnowingLayerPane::UpdateAndRenderSnowParticles()
{
    static SnowPatternDescriptor s_snowDescriptors[2];

    s_snowDescriptors[0].pattern = s_snowPatterns[0];
    s_snowDescriptors[0].frameCount = 4;
    SetRect(&s_snowDescriptors[0].sourceRect, 0, 0, 4, 4);

    s_snowDescriptors[1].pattern = s_snowPatterns[1];
    s_snowDescriptors[1].frameCount = 3;
    SetRect(&s_snowDescriptors[1].sourceRect, 0, 0, 3, 3);

    SetDrawColor(0);
    BeginWeatherDraw(this, &m_weatherDrawRect);

    if (g_activeMapPane != NULL && g_activeMapPane->IsWeatherDrawSuppressed())
        return;

    for (int i = 0; i < kSnowParticleCount; ++i) {
        const int dx = (8 * rand()) / 0x7fff - 4;
        const int dy = (25 * rand()) / 0x7fff;
        OffsetRect(&m_snowParticles[i].bounds, dx, dy);
    }

    if (m_snowRefreshMode == 0) {
        memmove(&m_snowParticles[20], &m_snowParticles[0],
                (kSnowParticleCount - 20) * sizeof(m_snowParticles[0]));

        const int spawnWidth = m_snowSpawnRight - m_snowSpawnLeft;
        const int spawnBand = (m_snowSpawnBottom - m_snowSpawnTop) / 10;

        for (int i = 0; i < 20; ++i) {
            SnowParticleEntry& particle = m_snowParticles[i];
            particle.left = (spawnWidth * rand()) / 0x7fff;
            particle.top = (spawnBand * rand()) / 0x7fff - spawnBand;

            const unsigned int roll = (100 * rand()) / 0x7fff;
            for (unsigned char type = 0; type < kSnowTypeCount; ++type) {
                if (s_snowTypeThresholds[type] <= roll &&
                    roll < s_snowTypeThresholds[type + 1]) {
                    particle.type = type;
                    break;
                }
            }

            const int size = s_snowSizes[particle.type];
            particle.right = particle.left + size;
            particle.bottom = particle.top + size;
        }
    }

    for (int i = 0; i < kSnowParticleCount; ++i) {
        const SnowParticleEntry& particle = m_snowParticles[i];
        const SnowPatternDescriptor& descriptor = s_snowDescriptors[particle.type];
        RenderSnowParticle(&descriptor, &descriptor.sourceRect, &particle, 0, 0, 0);
    }
}


// UID:0003O3 | by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md | Completion:88 | Confidence:89
void SnowingLayerPane::RenderSnowParticles(GrafPort *target, int, int, int)
{
    static SnowPatternDescriptor s_snowDescriptors[2];

    (void)target;

    s_snowDescriptors[0].pattern = s_targetSnowPatterns[0];
    s_snowDescriptors[0].frameCount = 4;
    SetRect(&s_snowDescriptors[0].sourceRect, 0, 0, 4, 4);

    s_snowDescriptors[1].pattern = s_targetSnowPatterns[1];
    s_snowDescriptors[1].frameCount = 3;
    SetRect(&s_snowDescriptors[1].sourceRect, 0, 0, 3, 3);

    if (g_activeMapPane != NULL && g_activeMapPane->IsWeatherDrawSuppressed())
        return;

    for (int i = 0; i < kSnowParticleCount; ++i) {
        const SnowParticleEntry& particle = m_snowParticles[i];
        const SnowPatternDescriptor& descriptor = s_snowDescriptors[particle.type];
        RenderSnowParticle(&descriptor, &descriptor.sourceRect, &particle, 0, 0, 0);
    }
}


// UID:0002Z9 | by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md | Completion:88 | Confidence:92
// SnowingLayerPane vtable data is generated from the class declaration and exact virtual method pages; no hand-authored vtable array is emitted here.

// UID:0000E9 | by-class/SwallowLayerPane.md | Completion:95 | Confidence:94
// SwallowLayerPane class-owned methods, resources, and vtable support emit on exact child pages; no duplicate broad class body is emitted here.
// UID:00054K | by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md | Completion:94 | Confidence:95
SwallowLayerPane::SwallowLayerPane()
    : m_swallowActive(false),
      m_swallowX(0),
      m_swallowY(0),
      m_swallowDirection(1)
{

    const wchar_t *resourceName = g_useEpfAssets
        ? L"SWALLOW.EPF"
        : L"SWALLOW.EPD";
    g_pEPFLib->LookupLayoutEntry(resourceName, 0, &m_swallowFrames[0]);
    g_pEPFLib->LookupLayoutEntry(resourceName, 1, &m_swallowFrames[1]);

    ScheduleTimer(kStartFlightTimerId, 0, 0, 0);
    m_drawOnTarget = true;
}

// UID:00054L | by-memory/0x005c2340-0x005c235f.SwallowLayerPaneDestructor.md | Completion:94 | Confidence:95
SwallowLayerPane::~SwallowLayerPane()
{
}

// UID:00054M | by-memory/0x005c2360-0x005c2423.SwallowLayerPaneOnPaint.md | Completion:94 | Confidence:95
void SwallowLayerPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);
    SetDrawColor(0);
    g_pfnFillRect(this, &bounds);

    if (m_swallowActive)
    {
        RectBounds destinationBounds;
        GetCurrentSwallowRect(&destinationBounds);
        EPFTileContext *frame = &m_swallowFrames[m_swallowDirection == 1 ? 0 : 1];
        g_pfnBlitSprite(this, frame, &frame->bounds,
                       &destinationBounds, 1, 0, 0);
    }
}

// UID:00054N | by-memory/0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy.md | Completion:94 | Confidence:95
void SwallowLayerPane::MoveBy(int dx, int dy)
{
    InvalidateSwallowRect();
    m_swallowX += dx;
    m_swallowY += dy;
    InvalidateSwallowRect();
}

// UID:00054O | by-memory/0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer.md | Completion:94 | Confidence:95
bool SwallowLayerPane::OnTimer(int timerId, int, int)
{
    if (timerId == kStartFlightTimerId)
        StartSwallowFlight();
    else if (timerId == kStepFlightTimerId)
        StepSwallowFlight();
    return true;
}

// UID:00054P | by-memory/0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget.md | Completion:94 | Confidence:95
void SwallowLayerPane::DrawOnTarget(GrafPort *port,
                                    const RectBounds *,
                                    const RectBounds *)
{
    if (!m_swallowActive)
        return;

    RectBounds destinationBounds;
    GetCurrentSwallowRect(&destinationBounds);
    EPFTileContext *frame = &m_swallowFrames[m_swallowDirection == 1 ? 0 : 1];
    g_pfnBlitSprite(port, frame, &frame->bounds,
                   &destinationBounds, 1, 0, 0);
}

// UID:00054Q | by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md | Completion:94 | Confidence:95
void SwallowLayerPane::StartSwallowFlight()
{
    m_swallowActive = true;
    m_swallowDirection = rand() % 2 ? -1 : 1;

    RectBounds bounds;
    GetBounds(&bounds);
    m_swallowX = m_swallowDirection == 1 ? 0 : bounds.right;
    m_swallowY = rand() % bounds.bottom;
    InvalidateSwallowRect();
    ScheduleTimer(kStepFlightTimerId, 10, 0, 0);
}

// UID:00054R | by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md | Completion:94 | Confidence:95
void SwallowLayerPane::StepSwallowFlight()
{
    InvalidateSwallowRect();
    m_swallowX += 10 * m_swallowDirection;

    RectBounds bounds;
    GetBounds(&bounds);
    const bool finished = m_swallowDirection == -1
        ? m_swallowX < bounds.left
        : m_swallowDirection != 1 || m_swallowX >= bounds.right;

    if (finished)
    {
        m_swallowActive = false;
        ScheduleTimer(kStartFlightTimerId, rand() % 40000 + 10000, 0, 0);
    }
    else
    {
        InvalidateSwallowRect();
        ScheduleTimer(kStepFlightTimerId, 10, 0, 0);
    }
}

// UID:00054S | by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md | Completion:94 | Confidence:95
void SwallowLayerPane::InvalidateSwallowRect()
{
    RectBounds bounds;
    GetCurrentSwallowRect(&bounds);
    InvalidateRect(&bounds);
}

// UID:0003YQ | by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md | Completion:94 | Confidence:95
void SwallowLayerPane::GetCurrentSwallowRect(RectBounds *outBounds) const
{
    *outBounds = m_swallowFrames[m_swallowDirection == 1 ? 0 : 1].bounds;
    outBounds->Offset(m_swallowX, m_swallowY);
}

// UID:0000TP | by-global/WeatherLayerGlobals.md | Completion:94 | Confidence:94
// Exact rain declarations emit from [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), and exact snow declarations emit from [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md); this broad support page does not duplicate either body.

// UID:0003O2 | by-memory\0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md | Completion:89 | Confidence:91 | Empty Emitter Marker

// UID:0003O4 | by-memory\0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md | Completion:85 | Confidence:88 | Empty Emitter Marker
