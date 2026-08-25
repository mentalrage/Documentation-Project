// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MC
// Source by-file doc: by-file/Pane.md
// UID:0000A2 | by-class/Pane.md | Completion:92 | Confidence:94
#include "Pane.h"
#include "../../input/InputMan.h"
#include "Layer.h"

// UID:0002V7 | by-memory/0x005446b0-0x005446d4.PaneSetMode.md | Completion:88 | Confidence:92
void Pane::SetMode(unsigned char mode)
{
    if (m_mode == mode)
        return;

    m_mode = mode;
    InvalidateRect(&m_visibleBounds);
}

// UID:0004IX | by-memory/0x00544a20-0x00544a35.PaneGetDescription.md | Completion:90 | Confidence:93
void Pane::GetDescription(int selectedIndex, wchar_t *outDescription)
{
    if (selectedIndex == -1)
        outDescription[0] = L'\0';
}

// UID:0004ZP | by-memory/0x00544db0-0x00544e09.PaneDefaultEventHandlers.md | Completion:92 | Confidence:94
bool Pane::HandlePointerOrMouseEvent(Event *event)
{
    return EventHandler::HandlePointerOrMouseEvent(event);
}

bool Pane::HandleKeyOrTextEvent(Event *event)
{
    return EventHandler::HandleKeyOrTextEvent(event);
}

bool Pane::HandleImeEvent(Event *event)
{
    return EventHandler::HandleImeEvent(event);
}

bool Pane::HandlePacketEvent(Event *event)
{
    return EventHandler::HandlePacketEvent(event);
}

bool Pane::HandleSystemOrControlEvent(Event *event)
{
    return EventHandler::HandleSystemOrControlEvent(event);
}

bool Pane::HandleType19Event(Event *event)
{
    return EventHandler::HandleType19Event(event);
}

// UID:0004ZQ | by-memory/0x00544e10-0x00544e25.PaneGetLocalOffset.md | Completion:93 | Confidence:95
void Pane::GetLocalOffset(Point *offset)
{
    offset->y = m_origin.y;
    offset->x = m_origin.x;
}

// UID:0004ZR | by-memory/0x00544e30-0x00544e66.PaneGetScreenOffset.md | Completion:93 | Confidence:95
void Pane::GetScreenOffset(Point *offset)
{
    if (m_layer != NULL)
        m_layer->GetScreenOffset(offset, this);
    else
    {
        offset->y = 0;
        offset->x = 0;
    }
}

// UID:0004ZS | by-memory/0x00544e70-0x00544e8a.PaneShouldAcceptEvent.md | Completion:93 | Confidence:95
bool Pane::ShouldAcceptEvent() const
{
    return m_visible && !m_exposedRegion.IsEmpty();
}

// UID:0004ZT | by-memory/0x00544e90-0x00544e95.PaneOnTimer.md | Completion:93 | Confidence:95
bool Pane::OnTimer(int timerId, int arg0, int arg1)
{
    return true;
}

// UID:0004ZU | by-memory/0x00544ea0-0x00544eda.PaneSetFocusRegistration.md | Completion:92 | Confidence:94
void Pane::SetFocusRegistration(bool active)
{
    int state = active ? 1 : 0;

    if (m_inputRegistrationState == state)
        return;

    m_inputRegistrationState = state;
    g_pInputMan->TrackInputTarget(reinterpret_cast<int>(this), active);
}

// UID:0004KU | by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md | Completion:89 | Confidence:92
void Pane::Collapse()
{
    RemoveFromLayer();

    RectBounds emptyBounds = { 0, 0, 0, 0 };
    UpdateRenderRegion(&emptyBounds);
}

// UID:0003CA | by-memory\0x006219e8-0x00621a6c.PaneVtableData.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0001VH | by-type\by-struct\PaneLayout.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003JA | by-type\by-vtable\PaneVtables.md | Completion:90 | Confidence:94 | Empty Emitter Marker
