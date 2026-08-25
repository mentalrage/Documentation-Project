// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P8
// Source by-file doc: by-file/WeatherLayerPane.md
// UID:0001WJ | by-type/by-struct/WeatherLayerDataLayouts.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_MAP_WEATHERLAYERPANE_H
#define NEXUSTK_MAP_WEATHERLAYERPANE_H

#include "../render/EPFTileContext.h"
#include "../ui/core/Pane.h"

struct SnowParticleEntry
{
    RectBounds bounds;
    unsigned char type;
};

// UID:0000G1 | by-class/WeatherLayerPane.md | Completion:90 | Confidence:93
class WeatherLayerPane : public Pane
{
public:
    WeatherLayerPane();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

protected:
    virtual void OnFrameChanged() { }

    signed char m_currentFrame;
    signed char m_frameCount;
    short m_timerInterval;
    RectBounds m_weatherBounds;
};

// UID:0000BJ | by-class/RainingLayerPane.md | Completion:91 | Confidence:93
class RainingLayerPane : public WeatherLayerPane
{
public:
    RainingLayerPane();
    virtual void DrawOnTarget(GrafPort *target,
                              const RectBounds *sourceBounds,
                              const RectBounds *targetBounds);
    virtual void OnPaint();
};

// UID:0000DC | by-class/SnowingLayerPane.md | Completion:91 | Confidence:93
class SnowingLayerPane : public WeatherLayerPane
{
public:
    SnowingLayerPane();
    virtual void UpdateAndRenderSnowParticles();
    virtual void RenderSnowParticles(GrafPort *target,
                                     int arg0,
                                     int arg1,
                                     int arg2);

protected:
    virtual void OnFrameChanged();

private:
    SnowParticleEntry m_snowParticles[200];
};

// UID:0000E9 | by-class/SwallowLayerPane.md | Completion:95 | Confidence:94
class SwallowLayerPane : public WeatherLayerPane
{
public:
    SwallowLayerPane();
    virtual ~SwallowLayerPane();

    virtual void DrawOnTarget(GrafPort *port,
                              const RectBounds *sourceBounds,
                              const RectBounds *targetBounds);
    virtual void OnPaint();
    virtual void MoveBy(int dx, int dy);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    enum
    {
        kStartFlightTimerId = 0x100,
        kStepFlightTimerId = 0x101
    };

    void StartSwallowFlight();
    void StepSwallowFlight();
    void InvalidateSwallowRect();
    void GetCurrentSwallowRect(RectBounds *outBounds) const;

    bool m_swallowActive;
    int m_swallowX;
    int m_swallowY;
    int m_swallowDirection;
    EPFTileContext m_swallowFrames[2];
};

typedef char SnowParticleEntrySizeMustBe0x14[sizeof(SnowParticleEntry) == 0x14 ? 1 : -1];
typedef char WeatherLayerPaneSizeMustBe0x10C[sizeof(WeatherLayerPane) == 0x10c ? 1 : -1];
typedef char RainingLayerPaneSizeMustBe0x10C[sizeof(RainingLayerPane) == 0x10c ? 1 : -1];
typedef char SnowingLayerPaneSizeMustBe0x10AC[sizeof(SnowingLayerPane) == 0x10ac ? 1 : -1];
typedef char SwallowLayerPaneSizeMustBe0x16C[sizeof(SwallowLayerPane) == 0x16c ? 1 : -1];

#endif
