// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LH
// Source by-file doc: by-file/ModelessDialogPane.md
// UID:00008K | by-class/ModelessDialogPane.md | Completion:93 | Confidence:94
#include "ModelessDialogPane.h"
#include "ControlPane.h"
#include "Event.h"
#include "ScreenPane.h"

// UID:000310 | by-memory/0x004a0760-0x004a0827.ModelessDialogPaneConstructor.md | Completion:88 | Confidence:90
ModelessDialogPane::ModelessDialogPane(const wchar_t *titleText)
    : DialogPane(titleText, 0xffff, 1)
{
    RectBounds bounds;

    SetRectLTRB(&bounds, 100, 100, 200, 200);
    OnCreate(&bounds, 0, 0, g_dialogRenderContext);
    InitializePaneInteraction(0, 0);
    g_pEventDispatcher->AddToModalList(GetEventHandlerView());
}

// UID:000311 | by-memory/0x004a0830-0x004a0835.ModelessDialogPaneIsModal.md | Completion:90 | Confidence:94
bool ModelessDialogPane::IsModal()
{
    return false;
}

// UID:000312 | by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md | Completion:94 | Confidence:94
bool ModelessDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;
    int controlId;
    signed char hitType;
    bool handled;

    switch (event->m_type)
    {
    case kEventCursorMove:
        if (m_isTitleDragActive)
        {
            m_origin.x = m_origin.x - m_dragOriginX + mouseX;
            m_origin.y = m_origin.y - m_dragOriginY + mouseY;

            if (m_clampDragToBounds)
            {
                if (m_origin.y + m_visibleBounds.bottom > m_dragClampMaxY)
                    m_origin.y = m_dragClampMaxY - m_visibleBounds.bottom;
                if (m_origin.y < m_dragClampMinY)
                    m_origin.y = m_dragClampMinY;
                if (m_origin.x + m_visibleBounds.right > m_dragClampMaxX)
                    m_origin.x = m_dragClampMaxX - m_visibleBounds.right;
                if (m_origin.x < m_dragClampMinX)
                    m_origin.x = m_dragClampMinX;
            }
            return true;
        }

        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (!m_pressedControlActive)
            return false;

        if (controlId == m_pressedControlId && hitType == m_pressedHitType)
            SetSelectionVisualState(controlId, hitType);
        else
            SetSelectionVisualState(-1, 10);

        DispatchInputToControl(event, m_pressedControlId);
        return true;

    case kEventLeftButtonDown:
        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (hitType == 10)
        {
            if (m_isTitleDragActive)
                return true;
            if (!PointInRect(mouseY, mouseX, &m_visibleBounds))
                return false;

            m_dragOriginX = mouseX;
            m_isTitleDragActive = true;
            m_dragOriginY = mouseY;
            m_savedPaneMode = m_mode;

            if (m_savedPaneMode == 2)
                SetMode(0);
            else if (m_savedPaneMode == 3)
                SetMode(1);
            return true;
        }

        if (m_pressedControlActive || hitType < 0)
            return false;

        if (m_activeControlId != controlId)
        {
            ControlPane *control = GetChild<ControlPane>(controlId);
            if (control->IsSelectable())
                SetHoverControl(controlId);
        }

        m_pressedControlActive = true;
        m_pressedControlId = controlId;
        m_pressedHitType = hitType;
        SetSelectionVisualState(controlId, hitType);
        DispatchInputToControl(event, controlId);
        return true;

    case kEventLeftButtonDoubleClick:
        HitTestControls(mouseY, mouseX, &controlId);
        if (controlId == -1 || !PointInRect(mouseY, mouseX, &m_visibleBounds))
            return false;
        DispatchInputToControl(event, controlId);
        return true;

    case kEventLeftButtonUp:
        handled = false;
        if (m_isTitleDragActive)
        {
            SetMode(m_savedPaneMode);
            if (m_dialogConfigId != 0xffff)
            {
                RectBounds bounds;
                GetScreenBounds(&bounds);
                SavePosition(&bounds);
            }
            m_isTitleDragActive = false;
            handled = true;
        }

        if (!m_pressedControlActive)
            return handled;

        m_pressedControlActive = false;
        SetSelectionVisualState(-1, 10);
        DispatchInputToControl(event, m_pressedControlId);
        g_pScreenPane->RenderPresentation();

        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (controlId == m_pressedControlId && hitType == m_pressedHitType)
        {
            OnControlCommand(controlId, hitType);
            RefreshActionButtonState();
        }
        return true;

    case kEventMouseWheel:
        if (PointInRect(mouseY, mouseX, &m_visibleBounds))
        {
            HitTestControls(mouseY, mouseX, &controlId);
            DispatchInputToControl(event, controlId);
        }
        break;

    default:
        break;
    }

    return handled;
}

// UID:0001V9 | by-type\by-struct\ModelessDialogPaneLayout.md | Completion:93 | Confidence:95 | Empty Emitter Marker

// UID:0001Y6 | by-type\by-vtable\ModelessDialogPaneVtables.md | Completion:91 | Confidence:95 | Empty Emitter Marker

// UID:00036P | by-memory\0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md | Completion:91 | Confidence:95 | Empty Emitter Marker
