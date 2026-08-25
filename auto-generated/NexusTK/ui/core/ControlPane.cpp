// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IG
// Source by-file doc: by-file/ControlPane.md
// UID:000038 | by-class/ControlPane.md | Completion:91 | Confidence:93
#include "ControlPane.h"

// UID:0002PB | by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md | Completion:89 | Confidence:92
ControlPane::ControlPane(unsigned char controlType, const RectBounds *bounds)
    : Pane(1),
      m_rangeStart(0),
      m_rangeCurrent(0),
      m_rangeEnd(0),
      m_controlType(controlType),
      m_controlFlags(0),
      m_reservedControlState(0),
      m_enabled(true),
      m_controlActive(false),
      m_visualState(10),
      m_ignoreHitTesting(false)
{
    if (bounds != NULL)
        SetBounds(bounds, 0);
}


// UID:0003N3 | by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md | Completion:90 | Confidence:93
void ControlPane::Enable()
{
    if (m_enabled)
        return;

    m_enabled = true;
    Invalidate(&m_bounds);
}

// UID:0003N4 | by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md | Completion:90 | Confidence:93
void ControlPane::Disable()
{
    if (!m_enabled)
        return;

    m_enabled = false;
    Invalidate(&m_bounds);
}

// UID:0002PC | by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md | Completion:88 | Confidence:92
bool ControlPane::IgnoresHitTesting() const
{
    return m_ignoreHitTesting;
}

// UID:0003N5 | by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md | Completion:90 | Confidence:92
void ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)
{
    m_ignoreHitTesting = ignoreHitTesting;
}

// UID:0003N6 | by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md | Completion:92 | Confidence:94
void ControlPane::Deactivate()
{
    if (m_controlActive)
    {
        m_controlActive = false;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:0003N7 | by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md | Completion:92 | Confidence:94
void ControlPane::Activate()
{
    if (!m_controlActive)
    {
        m_controlActive = true;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:0003N2 | by-memory\0x00494b80-0x00494bad.ControlPaneSetVisualState.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003N9 | by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md | Completion:88 | Confidence:89 | Empty Emitter Marker

// UID:0003J8 | by-memory\0x00617a8c-0x00617b30.ControlPaneVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0003J9 | by-type\by-vtable\ControlPaneVtables.md | Completion:88 | Confidence:93 | Empty Emitter Marker
