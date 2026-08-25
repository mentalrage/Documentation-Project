// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 000577
// Source by-file doc: by-file/AboveFrame.md
// UID:000005 | by-class/AboveFrame.md | Completion:93 | Confidence:95
#pragma once

#include "Pane.h"
#include "EPFTileContext.h"
#include "RectBounds.h"

class AboveFrame : public Pane
{
public:
    AboveFrame(int frameIndex, int top, int left);
    virtual ~AboveFrame();

protected:
    virtual void OnPaint();
    virtual void OnChangeMessage(LObject *owner, Message *message);

private:
    EPFTileContext m_tileContext;
    RectBounds m_bounds;
    unsigned char m_framePaletteMode;
};
