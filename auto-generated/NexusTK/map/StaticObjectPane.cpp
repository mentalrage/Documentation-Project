// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O6
// Source by-file doc: by-file/StaticObjectPane.md
// UID:0000E1 | by-class/StaticObjectPane.md | Completion:90 | Confidence:92
#include "StaticObjectPane.h"
#include "../util/PoolAllocator.h"


// UID:00034X | by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md | Completion:88 | Confidence:92
// Emitted code for this range is covered by [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md).

// UID:0002WM | by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_staticObjectPanePool(0x12c, 0x10);

// UID:0001D6 | by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md | Completion:88 | Confidence:91
StaticObjectPane::StaticObjectPane(int tileX, int tileY, uint16_t staticObjectId)
    : ObjectPane(5, 0, tileX, tileY)
{
    m_staticObjectId = staticObjectId;
}

bool StaticObjectPane::HitTestStaticObjectPixel(int localX, int localY) const
{
    return g_pStaticObjImageLib->HitTestStaticObjectPixel(m_staticObjectId, localX, localY);
}

Rect *StaticObjectPane::CopyStaticObjectBounds(Rect *scratch, Rect *out) const
{
    g_pStaticObjImageLib->GetStaticObjectBounds(m_staticObjectId, scratch);
    *out = *scratch;
    return out;
}

bool StaticObjectPane::RenderStaticObjectForTarget(int renderMode, StaticObjectDrawRequest *request)
{
    return g_pStaticObjImageLib->RenderStaticObject(renderMode, request, m_staticObjectId, 0, 0.0f, true) != 0;
}

bool StaticObjectPane::HandleStaticObjectEvent(const PaneEvent *event)
{
    Rect bounds;

    Rect_Set(&bounds, m_bounds.left, m_bounds.top, m_bounds.right, m_bounds.bottom);

    if (event->type != 1) {
        return false;
    }

    if (!Rect_ContainsPoint(&bounds, event->x, event->y) || (event->flags & 0x04) != 0) {
        return false;
    }

    uint8_t packet[8];
    PacketBuffer_WriteByte(0x43, &packet[0]);
    PacketBuffer_WriteByte(0x03, &packet[1]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileX), &packet[2]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileY), &packet[4]);
    PacketBuffer_WriteByte(0x00, &packet[6]);
    packet[7] = 0;

    QueueAndSendPacket(g_pPacketSender, packet, 7);
    return true;
}

// UID:00023G | by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md | Completion:88 | Confidence:89
void StaticObjectPane::SendInteractionPacket()
{
    uint8_t packet[8];

    PacketBuffer_WriteByte(0x43, &packet[0]);
    PacketBuffer_WriteByte(0x03, &packet[1]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileX), &packet[2]);
    PacketBuffer_WriteUInt16BE(static_cast<uint16_t>(m_tileY), &packet[4]);
    PacketBuffer_WriteByte(0x00, &packet[6]);
    packet[7] = 0;

    QueueAndSendPacket(g_pPacketSender, packet, 7);
}

// UID:000388 | by-memory\0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker
