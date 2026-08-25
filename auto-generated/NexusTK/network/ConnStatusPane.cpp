// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IF
// Source by-file doc: by-file/ConnStatusPane.md
// UID:000037 | by-class/ConnStatusPane.md | Completion:94 | Confidence:96
#include "ConnStatusPane.h"

#include "../config/Config.h"
#include "../map/MapPane.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../util/TimerMgr.h"

template <>
Singleton<ConnStatusPane>::Singleton()
{
    g_pConnStatusPane = static_cast<ConnStatusPane *>(this);
}

template <>
Singleton<ConnStatusPane>::~Singleton()
{
    g_pConnStatusPane = 0;
}

// UID:0002B9 | by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md | Completion:94 | Confidence:97
ConnStatusPane *g_pConnStatusPane = 0;

// UID:000113 | by-memory/0x00494520-0x004949df.ConnStatusPane.md | Completion:94 | Confidence:95
namespace
{
const int kInvalidLatencySample = -1;
const short kInvalidConnectionFrame = -1;
const short kMapStatusConnectionFrame = 4;
const int kLatencyFastThresholdMs = 400;
const int kLatencyMidThresholdMs = 800;
const int kLatencySlowThresholdMs = 1200;
}

ConnStatusPane::ConnStatusPane()
    : Pane(1)
{
    for (int index = 0; index < 10; ++index)
        m_latencySamples[index] = kInvalidLatencySample;

    m_pendingLatencyStartTick = kInvalidLatencySample;
    m_connectionFrame = kInvalidConnectionFrame;
}

ConnStatusPane::~ConnStatusPane()
{
}

void ConnStatusPane::CaptureLatencyStartTick()
{
    m_pendingLatencyStartTick = static_cast<int>(g_pTimerMgr->m_currentTick);
}

void ConnStatusPane::OnPaint()
{
    if (m_connectionFrame == kInvalidConnectionFrame)
    {
        SetDrawMode(0);
        SetDrawColor(0);
        g_pfnFillRect(this, &m_visibleBounds);
        return;
    }

    EPFTileContext tile;
    g_pEPFLib->LookupLayoutEntry(
        L"CONNSTAT.EPD", m_connectionFrame, &tile);
    RenderTileFrame(
        &tile, &tile.bounds, &m_visibleBounds, 0, L"NPAL7.PAL", 0);
}

bool ConnStatusPane::HandlePacketEvent(Event *event)
{
    const unsigned char packetType =
        *static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    switch (packetType)
    {
    case 4:
    case 11:
    case 21:
    case 38:
        if (g_pConfig->m_mapMovementStatusOption &&
            g_activeMapPane != 0 &&
            g_activeMapPane->AllowsMovementStatusTag())
        {
            if (m_pendingLatencyStartTick != kInvalidLatencySample)
                UpdateConnectionFrame();

            if (m_connectionFrame != kMapStatusConnectionFrame)
            {
                m_connectionFrame = kMapStatusConnectionFrame;
                InvalidateRect(&m_visibleBounds);
            }
        }
        else if (m_pendingLatencyStartTick != kInvalidLatencySample)
        {
            UpdateConnectionFrame();
        }
        break;
    }

    return false;
}

void ConnStatusPane::UpdateConnectionFrame()
{
    for (int index = 0; index < 9; ++index)
        m_latencySamples[index] = m_latencySamples[index + 1];

    m_latencySamples[9] =
        static_cast<int>(g_pTimerMgr->m_currentTick) -
        m_pendingLatencyStartTick;
    m_pendingLatencyStartTick = kInvalidLatencySample;

    int total = 0;
    int sampleCount = 0;
    for (int index = 0; index < 10; ++index)
    {
        if (m_latencySamples[index] != kInvalidLatencySample)
        {
            total += m_latencySamples[index];
            ++sampleCount;
        }
    }

    short nextFrame = kInvalidConnectionFrame;
    if (sampleCount != 0)
    {
        const int average = total / sampleCount;
        if (average < kLatencyFastThresholdMs)
            nextFrame = 3;
        else if (average < kLatencyMidThresholdMs)
            nextFrame = 2;
        else if (average < kLatencySlowThresholdMs)
            nextFrame = 1;
        else
            nextFrame = 0;
    }

    if (m_connectionFrame != nextFrame)
    {
        m_connectionFrame = nextFrame;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00035G | by-memory\0x006179e8-0x00617a34.ConnStatusPanePrimaryVtableData.md | Completion:94 | Confidence:97 | Empty Emitter Marker

// UID:000569 | by-memory\0x00617a34-0x00617a70.ConnStatusPaneAdjustedVtableData.md | Completion:94 | Confidence:97 | Empty Emitter Marker

// UID:00056A | by-memory\0x00617a70-0x00617a8a.ConnStatusPaneResourceStringData.md | Completion:94 | Confidence:97 | Empty Emitter Marker

// UID:000567 | by-memory\0x006457f8-0x006458d0.ConnStatusPaneRttiHierarchyData.md | Completion:94 | Confidence:97 | Empty Emitter Marker

// UID:000568 | by-memory\0x00675738-0x00675784.ConnStatusPaneTypeDescriptorData.md | Completion:94 | Confidence:97 | Empty Emitter Marker
