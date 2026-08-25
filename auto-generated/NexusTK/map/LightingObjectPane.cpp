// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KO
// Source by-file doc: by-file/LightingObjectPane.md
// UID:000075 | by-class/LightingObjectPane.md | Completion:94 | Confidence:95
#include "LightingObjectPane.h"

#include "AttachedObjectPane.h"
#include "LightObjImageLib.h"
#include "MapPane.h"
#include "../ui/core/RectBounds.h"

// UID:0001DG | by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md | Completion:90 | Confidence:93
LightingObjectPane::LightingObjectPane(
    ObjectPane *anchorSource,
    int mapY,
    int mapX,
    int localOffsetX,
    int localOffsetY,
    int lightImageIndex)
    : ObjectPane(10, 0, mapX, mapY),
      m_lightImageIndex(lightImageIndex),
      m_localOffsetY(localOffsetY),
      m_localOffsetX(localOffsetX),
      m_anchorSource(anchorSource)
{
}

LightingObjectPane::~LightingObjectPane()
{
    m_anchorSource->DetachObject();
}

// UID:0002TX | by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md | Completion:92 | Confidence:94
float LightingObjectPane::GetBrightness() const
{
    return g_pLightObjImageLib->GetBrightness(m_lightImageIndex);
}

// UID:0001DH | by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md | Completion:94 | Confidence:95
MapPoint *LightingObjectPane::GetAnchorScreenPoint(MapPoint *outPoint) const
{
    const int objectType = m_anchorSource->m_objectType;

    if (objectType == 2 || objectType == 4) {
        static_cast<const AttachedObjectPane *>(m_anchorSource)
            ->GetAttachedScreenPosition(outPoint);
    } else {
        g_activeMapPane->GetObjectScreenPoint(m_anchorSource, outPoint);
    }

    outPoint->row += m_localOffsetY;
    outPoint->column += m_localOffsetX;
    return outPoint;
}

RectBounds *LightingObjectPane::GetLightBounds(RectBounds *outBounds) const
{
    g_pLightObjImageLib->GetLightBounds(m_lightImageIndex, outBounds);

    MapPoint anchor;
    GetAnchorScreenPoint(&anchor);
    OffsetRect(outBounds, anchor.column, anchor.row);
    return outBounds;
}

// UID:0002TY | by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md | Completion:92 | Confidence:94
void LightingObjectPane::QueueLightBounds() const
{
    if (!g_activeMapPane->ShouldUseLivingObjectLightOverlay())
        return;

    RectBounds bounds;
    GetLightBounds(&bounds);
    g_activeMapPane->QueueMotionMessage(&bounds);
}

// UID:0001DI | by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetLightImageIndex.md | Completion:90 | Confidence:93
void LightingObjectPane::SetLightImageIndex(int lightImageIndex)
{
    if (m_lightImageIndex == lightImageIndex)
        return;

    m_anchorSource->DetachObject();
    m_lightImageIndex = lightImageIndex;
    m_anchorSource->AttachObject(this);
}

// UID:0002TZ | by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md | Completion:94 | Confidence:95
void LightingObjectPane::ApplyLightAtAnchor(
    MapPane *mapPane,
    int centerX,
    int centerY) const
{
    g_pLightObjImageLib->DrawLightMode1(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}

// UID:0002U0 | by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md | Completion:92 | Confidence:94
void LightingObjectPane::ApplyLightMode2AtAnchor(
    MapPane *mapPane,
    int centerX,
    int centerY) const
{
    g_pLightObjImageLib->DrawLightMode2(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}

// UID:0001DM | by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Emitted code for this range is covered by [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md).

// UID:000359 | by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md | Completion:90 | Confidence:94
// Emitted code for this range is covered by [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md).
