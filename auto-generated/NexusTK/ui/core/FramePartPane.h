// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 000578
// Source by-file doc: by-file/FramePartPane.md
// UID:00005I | by-class/FramePartPane.md | Completion:92 | Confidence:94
#pragma once

#include "Pane.h"
#include "RectBounds.h"

class FramePartPane : public Pane
{
public:
    FramePartPane(int partIndex, const RectBounds &bounds);
    virtual ~FramePartPane();

protected:
    virtual void OnPaint();
    virtual void OnChangeMessage(LObject *owner, Message *message);

private:
    int m_partIndex;
};
