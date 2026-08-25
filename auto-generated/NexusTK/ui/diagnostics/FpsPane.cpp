// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JK
// Source by-file doc: by-file/FpsPane.md
// UID:00005F | by-class/FpsPane.md | Completion:94 | Confidence:96
#include "FpsPane.h"

#include "../../map/MapPane.h"
#include "../../map/ObjectList.h"
#include "../../util/List.h"
#include "../../util/StringBase.h"
#include "../MainUiGraph.h"

#include <mmsystem.h>
#include <stdio.h>

template <>
Singleton<FpsPane>::Singleton()
{
    g_pFpsPane = static_cast<FpsPane *>(this);
}

template <>
Singleton<FpsPane>::~Singleton()
{
    g_pFpsPane = 0;
}

// UID:00015C | by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md | Completion:93 | Confidence:95
FpsPane::FpsPane()
    : Pane(1),
      m_currentFps(0.0f)
{
    m_hasPendingMotionRegion = true;
}

// UID:00015E | by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md | Completion:93 | Confidence:95
FpsPane::~FpsPane()
{
}

// UID:00015F | by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md | Completion:94 | Confidence:95
void FpsPane::UpdateFpsLogSession(bool startNew)
{
    RectBounds bounds;
    bounds.SetLTRB(10, 10, 490, 22);

    if (startNew && !IsAttachedToLayer()) {
        StartLogSession();
        AddToLayer(&bounds, 0, 0, g_pIMEPaneLayer);
        m_frameCount = 0;
        ScheduleTimer(0, 1000, 0, 0);
        return;
    }

    WriteLogSummary();
    RemoveFromLayer();
    RemovePendingTimers();
}

// UID:00015G | by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md | Completion:93 | Confidence:95
void FpsPane::OnPaint()
{
    ++m_frameCount;

    mystr::StringBase<wchar_t> fpsText(L"%5.1f FPS",
                                       static_cast<double>(m_currentFps));

    RectBounds bounds;
    GetBounds(&bounds);

    SetDrawColor(0);
    FillRect(&bounds);

    SetTextColor(128);
    MoveTo(1, 13);
    DrawWideText(fpsText.c_str(), fpsText.length());

    SetTextColor(14);
    MoveTo(0, 12);
    DrawWideText(fpsText.c_str(), fpsText.length());
}

// UID:00015H | by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md | Completion:94 | Confidence:96
bool FpsPane::OnTimer(int, int, int)
{
    const float fps = static_cast<float>(m_frameCount);
    m_frameCount = 0;
    m_currentFps = fps;

    if (fps < m_minFps)
        m_minFps = fps;

    if (m_maxFps < fps)
        m_maxFps = fps;

    ++m_sampleCount;
    m_totalFps += fps;

    if (g_activeMapPane != 0) {
        MapRect visibleTiles;
        g_activeMapPane->GetClampedVisibleTileBounds(&visibleTiles);

        ObjectList *objectList = g_activeMapPane->m_objectList;
        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row) {
            m_totalLivingObjects += objectList->GetFrontRowBucket(row)->GetCount();
            m_totalStaticObjects += objectList->GetBackRowBucket(row)->GetCount();
        }

        m_totalBalloonObjects += objectList->GetVisibleObjectList()->GetCount();
    }

    ScheduleTimer(0, 1000, 0, 0);
    return true;
}

// UID:00015I | by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md | Completion:92 | Confidence:94
void FpsPane::StartLogSession()
{
    m_logStartTick = timeGetTime();
    m_minFps = 300.0f;
    m_maxFps = 0.0f;
    m_sampleCount = 1;
    m_totalFps = 0.0;
    m_totalLivingObjects = 0;
    m_totalBalloonObjects = 0;
    m_totalStaticObjects = 0;

    if (g_fpsDebugActive != 0) {
        if (g_fpsLogEnabled) {
            FILE *file;

            GetLocalTime(&m_logStartTime);
            sprintf_s(m_logFileName, sizeof(m_logFileName),
                       "FPSDATA-%d-%d-%d-%d-%d.txt",
                       m_logStartTime.wMonth,
                       m_logStartTime.wDay,
                       m_logStartTime.wHour,
                       m_logStartTime.wMinute,
                       m_logStartTime.wSecond);

            fopen_s(&file, m_logFileName, "w");
            fprintf(file, "***NEW_CLIENT***\n");
            fprintf(file,
                    "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xC0\xDB %d\xBF\xF9 %d\xC0\xCF %d\xBD\xC3 %d\xBA\xD0 %d\xC3\xCA\n\n\n",
                    m_logStartTime.wMonth,
                    m_logStartTime.wDay,
                    m_logStartTime.wHour,
                    m_logStartTime.wMinute,
                    m_logStartTime.wSecond);
            fclose(file);
        }

        g_fpsDebugActive = 0;
    }
}

// UID:00015J | by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md | Completion:92 | Confidence:94
void FpsPane::WriteLogSummary()
{
    if (!g_fpsLogEnabled) {
        return;
    }

    FILE *file;
    fopen_s(&file, m_logFileName, "a");

    fprintf(file, "------------------------\n");
    fprintf(file,
            "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xB0\xA3 : %dsec\n",
            (timeGetTime() - m_logStartTick) / 1000);
    fprintf(file, "minFPS : %5.1f\n", (double)m_minFps);
    fprintf(file, "maxFPS : %5.1f\n", (double)m_maxFps);
    fprintf(file, "aveFPS : %5.1f\n", m_totalFps / (double)m_sampleCount);
    fprintf(file, "aveLivingObject  : %d\n", m_totalLivingObjects / m_sampleCount);
    fprintf(file, "aveBalloonObject : %d\n", m_totalBalloonObjects / m_sampleCount);
    fprintf(file, "aveStaticObject  : %d\n", m_totalStaticObjects / m_sampleCount);
    fprintf(file, "------------------------\n\n");

    fclose(file);
}

// UID:00015L | by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md | Completion:91 | Confidence:96
// Compiler-generated scalar deleting destructor for FpsPane; source is FpsPane::~FpsPane().

// UID:0002MJ | by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md | Completion:93 | Confidence:96
// Exact FpsPane vtable bytes [0x0061a61c,0x0061a6a4) are compiler-generated from UID00005F; this page emits no raw array.

// UID:0001UO | by-type/by-struct/FpsPaneLayout.md | Completion:94 | Confidence:96
// FpsPane layout is emitted by UID00005F FpsPane class declaration; this support page emits no duplicate type.

// UID:0001XN | by-type/by-vtable/FpsPane_vtables.md | Completion:93 | Confidence:96
// FpsPane vtables and RTTI are compiler-generated from the UID00005F class declaration; no raw table is handwritten.

// UID:0000PY | by-global/g_fpsDebugActive.md | Completion:92 | Confidence:94
int g_fpsDebugActive = 1;

// UID:0000PZ | by-global/g_fpsLogEnabled.md | Completion:94 | Confidence:96
bool g_fpsLogEnabled;

// UID:0000QZ | by-global/g_pFpsPane.md | Completion:94 | Confidence:96
FpsPane *g_pFpsPane = 0;

// UID:0003BJ | by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md | Completion:93 | Confidence:96
// Exact diagnostic literals [0x0061a6a4,0x0061a7dc) are embedded by the FpsPane method expressions; this page emits no duplicate array.

// UID:00027E | by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md | Completion:92 | Confidence:95
// Exact four-byte storage is emitted by UID0000PY g_fpsDebugActive; this by-memory child records bytes/xrefs only and emits no duplicate definition.

// UID:0002W0 | by-memory/0x0069b334-0x0069b338.g_pFpsPane.md | Completion:94 | Confidence:96
// Exact four-byte storage is emitted by UID0000QZ g_pFpsPane; this by-memory child records bytes/xrefs only and emits no duplicate definition.

// UID:0002W1 | by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md | Completion:94 | Confidence:96
// Exact one-byte storage is emitted by UID0000PZ g_fpsLogEnabled; this by-memory child records bytes/xrefs only and emits no duplicate definition.
