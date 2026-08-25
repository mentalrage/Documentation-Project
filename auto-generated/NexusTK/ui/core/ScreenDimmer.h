// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NA
// Source by-file doc: by-file/ScreenDimmer.md
// UID:0000C8 | by-class/ScreenDimmer.md | Completion:92 | Confidence:94
#pragma once

#include "Pane.h"
#include "../../util/Singleton.h"

class ScreenDimmer : public Pane, public Singleton<ScreenDimmer>
{
public:
    ScreenDimmer(unsigned char dimLevel, Pane *parentPane);
    virtual ~ScreenDimmer();

    virtual void OnPaint();

private:
    unsigned char m_dimLevel;
};

extern ScreenDimmer *g_pScreenDimmer;
