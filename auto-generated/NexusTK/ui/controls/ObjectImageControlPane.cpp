// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M3
// Source by-file doc: by-file/ObjectImageControlPane.md
// UID:00009O | by-class/ObjectImageControlPane.md | Completion:94 | Confidence:94
#include "ObjectImageControlPane.h"

#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../core/ScreenPane.h"
#include "../../render/EPFTileContext.h"
#include "../../render/GrafPort.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/MonsterImageLib.h"
#include "../../render/NewHumanImageLib.h"
#include "../../render/Surface.h"
#include <windows.h>

// UID:0001BU | by-memory/0x00520540-0x00520816.ObjectImageControlPane.md | Completion:94 | Confidence:94
ObjectImageControlPane::ObjectImageControlPane(
    const ObjectStatusBlob *objectStatus, const RectBounds *bounds)
    : ControlPane(8, bounds)
{
    m_objectStatus.m_displayStatusByte = 0x50;
    m_objectStatus = *objectStatus;
}

void ObjectImageControlPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds destinationBounds;

    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject)
    {
        g_pNewHumanImageLib->CalculateBounds(
            &m_objectStatus, 2, NULL, 0, &imageBounds, NULL, 0, true, 0);

        const int width = imageBounds.right - imageBounds.left;
        const int height = imageBounds.bottom - imageBounds.top;
        destinationBounds.left =
            (m_visibleBounds.left + m_visibleBounds.right - width) / 2;
        destinationBounds.top =
            (m_visibleBounds.top + m_visibleBounds.bottom - height) / 2;
        destinationBounds.right = destinationBounds.left + width;
        destinationBounds.bottom = destinationBounds.top + height;

        g_pNewHumanImageLib->Draw(
            this, &destinationBounds, &m_objectStatus, 2, NULL, 0, 0,
            false, NULL, 0.0f, 0, true, 0);
        return;
    }

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        g_pMonsterImageLib->ComputeRenderBounds(
            &m_objectStatus, 3, 0, &imageBounds, NULL);

        const int width = imageBounds.right - imageBounds.left;
        const int height = imageBounds.bottom - imageBounds.top;
        destinationBounds.left =
            (m_visibleBounds.left + m_visibleBounds.right - width) / 2;
        destinationBounds.top =
            (m_visibleBounds.top + m_visibleBounds.bottom - height) / 2;
        destinationBounds.right = destinationBounds.left + width;
        destinationBounds.bottom = destinationBounds.top + height;

        g_pMonsterImageLib->RenderMonsterImage(
            this, &destinationBounds, &m_objectStatus, 3, 0,
            0, 0, NULL, 0.0f);
        return;
    }

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::ItemObject)
    {
        g_pItemObjImageLib->GetItemGlyphBounds(
            m_objectStatus.m_appearanceId, &imageBounds);

        const int width = imageBounds.right - imageBounds.left;
        const int height = imageBounds.bottom - imageBounds.top;
        destinationBounds.left =
            (m_visibleBounds.left + m_visibleBounds.right - width) / 2;
        destinationBounds.top =
            (m_visibleBounds.top + m_visibleBounds.bottom - height) / 2;
        destinationBounds.right = destinationBounds.left + width;
        destinationBounds.bottom = destinationBounds.top + height;

        g_pItemObjImageLib->DrawItemImage(
            this, &destinationBounds, m_objectStatus.m_appearanceId,
            m_objectStatus.m_variantOrPalette, NULL, 0.0f);
        tileContext.ReleaseBuffers();
    }
}

// UID:00009N | by-class/ObjectImageButtonPane.md | Completion:94 | Confidence:94
// UID:0001BV | by-memory/0x00520820-0x00520a97.ObjectImageButtonPaneCore.md | Completion:94 | Confidence:94
ObjectImageButtonPane::ObjectImageButtonPane(
    const ObjectStatusBlob *objectStatus, const RectBounds *bounds)
    : ObjectImageControlPane(objectStatus, bounds),
      m_buttonHighlight(false)
{
    m_controlActive = false;
    m_controlFlags = 1;
    m_handlesEnterKey = true;
}

bool ObjectImageButtonPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown ||
        (key != ' ' && key != '\r'))
        return false;

    DialogPane *dialog = static_cast<DialogPane *>(GetParentPane());
    const int controlIndex = dialog->FindControlIndex(this);

    dialog->SetSelectionVisualState(controlIndex, 11);
    g_pScreenPane->RenderPresentation();
    Sleep(0x85);
    dialog->SetSelectionVisualState(-1, 10);
    g_pScreenPane->RenderPresentation();
    dialog->OnControlCommand(controlIndex, 11);
    return true;
}

void ObjectImageButtonPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds imageBounds;
    RectBounds destinationBounds;

    if (m_buttonHighlight)
    {
        g_pEPFLib->LookupLayoutEntry(L"CAPSULE.EPD", 0, &tileContext);

        const int width =
            tileContext.bounds.right - tileContext.bounds.left;
        const int height =
            tileContext.bounds.bottom - tileContext.bounds.top;
        destinationBounds.left =
            (m_visibleBounds.left + m_visibleBounds.right - width) / 2;
        destinationBounds.top =
            (m_visibleBounds.top + m_visibleBounds.bottom - height) / 2;
        destinationBounds.right = destinationBounds.left + width;
        destinationBounds.bottom = destinationBounds.top + height;

        RenderTileFrame(
            &tileContext, &tileContext.bounds, &destinationBounds,
            0, L"NPAL3.PAL", NULL);
    }

    g_pNewHumanImageLib->CalculateBounds(
        &m_objectStatus, 2, NULL, 0, &imageBounds, NULL, 0, true, 0);

    const int width = imageBounds.right - imageBounds.left;
    const int height = imageBounds.bottom - imageBounds.top;
    destinationBounds.left =
        (m_visibleBounds.left + m_visibleBounds.right - width) / 2;
    destinationBounds.top =
        (m_visibleBounds.top + m_visibleBounds.bottom - height) / 2;
    destinationBounds.right = destinationBounds.left + width;
    destinationBounds.bottom = destinationBounds.top + height;

    g_pNewHumanImageLib->Draw(
        this, &destinationBounds, &m_objectStatus, 2, NULL, 0, 0,
        false, NULL, 0.0f, 0, true, 0);
}

void ObjectImageButtonPane::SetButtonHighlight(bool highlighted)
{
    m_buttonHighlight = highlighted;
}

bool ObjectImageButtonPane::IsButtonHighlighted() const
{
    return m_buttonHighlight;
}
