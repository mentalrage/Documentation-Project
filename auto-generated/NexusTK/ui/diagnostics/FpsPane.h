// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JK
// Source by-file doc: by-file/FpsPane.md
// UID:00005F | by-class/FpsPane.md | Completion:94 | Confidence:96
#ifndef NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H
#define NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H

#include <windows.h>

#include "../core/Pane.h"
#include "../../util/Singleton.h"

class FpsPane : public Pane, public Singleton<FpsPane>
{
public:
    FpsPane();
    virtual ~FpsPane();

    void UpdateFpsLogSession(bool startNew);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void StartLogSession();
    void WriteLogSummary();

    int m_frameCount;
    unsigned int m_reservedFrameState;
    float m_currentFps;
    char m_logFileName[50];
    SYSTEMTIME m_logStartTime;
    DWORD m_logStartTick;
    float m_minFps;
    float m_maxFps;
    unsigned int m_sampleCount;
    double m_totalFps;
    unsigned int m_totalLivingObjects;
    unsigned int m_totalBalloonObjects;
    unsigned int m_totalStaticObjects;
};

extern int g_fpsDebugActive;
extern bool g_fpsLogEnabled;
extern FpsPane *g_pFpsPane;

typedef char FpsPaneSizeMustBe0x170[(sizeof(FpsPane) == 0x170) ? 1 : -1];

#endif
