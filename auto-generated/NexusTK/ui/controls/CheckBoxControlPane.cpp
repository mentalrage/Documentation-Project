// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I7
// Source by-file doc: by-file/CheckBoxControlPane.md
// UID:000021 | by-class/CheckBoxControlPane.md | Completion:93 | Confidence:95
#include "CheckBoxControlPane.h"

#include "../core/Event.h"
#include "../../render/EPFTileContext.h"

// UID:00011S | by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md | Completion:93 | Confidence:94
CheckBoxControlPane::CheckBoxControlPane(const RectBounds *bounds,
                                         const wchar_t *tileName,
                                         const wchar_t *paletteName,
                                         short checkedFrame,
                                         short uncheckedFrame)
    : ControlPane(7, bounds),
      m_checkedFrame(checkedFrame),
      m_uncheckedFrame(uncheckedFrame),
      m_checked(false)
{
    wcscpy_s(m_tileName, 16, tileName);
    wcscpy_s(m_paletteName, 16, paletteName);
}

void CheckBoxControlPane::SetChecked(bool checked)
{
    m_checked = checked;
}

bool CheckBoxControlPane::GetChecked() const
{
    return m_checked;
}

bool CheckBoxControlPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp &&
        m_bounds.ContainsPoint(event->m_payload.m_pointer.m_y,
                               event->m_payload.m_pointer.m_x)) {
        m_checked = !m_checked;
        InvalidateRect(0);
    }

    return EventHandler::HandlePointerOrMouseEvent(event);
}

void CheckBoxControlPane::OnPaint()
{
    SetDrawColor(0);
    PrepareClientDraw(&m_bounds);

    if (g_pEPFLib == 0) {
        return;
    }

    EPFTileContext tileContext;

    const short frame = m_checked ? m_checkedFrame : m_uncheckedFrame;
    g_pEPFLib->LookupLayoutEntry(m_tileName, frame, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    0,
                    m_paletteName,
                    0);
}

void CheckBoxControlPane::SetVisualState(unsigned char visualState)
{
    if (m_visualState != visualState && visualState == 20) {
        InvalidateRect(0);
    }

    if (m_visualState != visualState) {
        m_visualState = visualState;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004Y2 | by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md | Completion:94 | Confidence:96
unsigned char CheckBoxControlPane::HitTestPart(int, int)
{
    return 20;
}
