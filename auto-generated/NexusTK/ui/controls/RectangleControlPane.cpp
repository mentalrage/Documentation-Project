// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N1
// Source by-file doc: by-file/RectangleControlPane.md
// UID:0000BT | by-class/RectangleControlPane.md | Completion:94 | Confidence:95
#include "RectangleControlPane.h"
#include "../../render/Surface.h"

// UID:00011P | by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md | Completion:92 | Confidence:94
RectangleControlPane::RectangleControlPane(int drawColor, const RectBounds *bounds)
    : ControlPane(8, bounds)
{
    SetDrawColor(drawColor);
}

// UID:0004HL | by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md | Completion:92 | Confidence:94
RectangleControlPane::~RectangleControlPane()
{
}

// UID:00011R | by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md | Completion:92 | Confidence:94
void RectangleControlPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);
    g_pfnFillRect(this, &bounds);
}

// UID:000128 | by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md | Completion:94 | Confidence:96
unsigned char RectangleControlPane::HitTestPart(int, int)
{
    return 21;
}
