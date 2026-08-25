// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N1
// Source by-file doc: by-file/RectangleControlPane.md
// UID:0000BT | by-class/RectangleControlPane.md | Completion:94 | Confidence:95
#pragma once

#include "ControlPane.h"

struct RectBounds;

class RectangleControlPane : public ControlPane
{
public:
    RectangleControlPane(int drawColor, const RectBounds *bounds);
    virtual ~RectangleControlPane();

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);
};
