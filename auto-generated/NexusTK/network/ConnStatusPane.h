// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IF
// Source by-file doc: by-file/ConnStatusPane.md
// UID:000037 | by-class/ConnStatusPane.md | Completion:94 | Confidence:96
#ifndef NEXUSTK_NETWORK_CONNSTATUSPANE_H
#define NEXUSTK_NETWORK_CONNSTATUSPANE_H

#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class ConnStatusPane : public Pane, public Singleton<ConnStatusPane>
{
public:
    ConnStatusPane();
    virtual ~ConnStatusPane();

protected:
    virtual void OnPaint();
    virtual bool HandlePacketEvent(Event *event);

private:
    void CaptureLatencyStartTick();
    void UpdateConnectionFrame();

    int m_latencySamples[10];
    int m_pendingLatencyStartTick;
    short m_connectionFrame;
};

extern ConnStatusPane *g_pConnStatusPane;

typedef char ConnStatusPaneSizeMustBe0x128[
    sizeof(ConnStatusPane) == 0x128 ? 1 : -1];

#endif
