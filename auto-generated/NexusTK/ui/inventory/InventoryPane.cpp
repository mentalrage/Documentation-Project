// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KA
// Source by-file doc: by-file/InventoryPane.md
// UID:00006R | by-class/InventoryPane.md | Completion:93 | Confidence:94
#include "InventoryPane.h"

#include <wchar.h>

#include "../MainUiGraph.h"
#include "../../config/Config.h"
#include "../InterfaceEfx.h"
#include "../controls/HelpPanes.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"
#include "../panels/UserPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"

namespace
{
const int kInventorySlotCount = 52;
const int kLegacyPageSize = 15;
const int kCompactPageSize = 9;
const int kListView = 0;
const int kGridView = 1;
const int kButtonNormal = 0;
const int kButtonHover = 1;
const int kButtonPressed = 2;
const int kMouseDown = 1;
const int kMouseDoubleClick = 2;
const int kMouseDrag = 4;
const int kMouseMove = 8;
const int kKeyDown = 8;
const int kPageUp = 0x93;
const int kPageDown = 0x94;
}

InventoryPane::InventoryPane()
    : PanelPane(),
      m_pageIndex(0),
      m_isLastPage(false),
      m_viewMode(kListView),
      m_itemEffect(new InterfaceEfx(
          L"ITEMEFX.EPD", 50, 434, 12,
          g_mainUiLayerSlots.rootPaneLayerContext, false, L"INTEFX.PAD"))
{
}

InventoryPane::~InventoryPane()
{
    if (m_itemEffect != 0)
        m_itemEffect->MarkForDeletion();
}

void InventoryPane::OnActivate(const unsigned char *)
{
    InvalidateRect(&m_visibleBounds);
}

void InventoryPane::PlayItemEffect()
{
    if (m_itemEffect != 0)
        m_itemEffect->Play();
}

void InventoryPane::OnPaint()
{
    EPFTileContext background;
    EPFTileContext buttonFrame;
    g_pEPFLib->CopyEntryTileContext(L"ITEMINV.EPD", 0, &background);
    RenderTileFrame(&background, &background.bounds,
                    &m_visibleBounds, 0, L"NPAL6.PAL", 0);
    int visibleOrdinal = 0;
    int slot = 1;
    int drawn = 0;

    while (slot <= kInventorySlotCount)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (item->active && ++visibleOrdinal > m_pageIndex * kLegacyPageSize)
            break;
        ++slot;
    }

    for (; slot <= kInventorySlotCount && drawn < kLegacyPageSize; ++slot)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (!item->active)
            continue;

        RectBounds itemRect;
        GetSlotRect(drawn, &itemRect);
        if (m_viewMode == kGridView)
        {
            RectBounds drawBounds = itemRect;
            g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
        }
        else
        {
            RectBounds glyphBounds;
            g_pItemObjImageLib->GetItemGlyphBounds(item->itemId, &glyphBounds);
            RectBounds drawBounds = itemRect;
            g_pItemObjImageLib->DrawItemImage(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
            MoveTo(itemRect.left + 24, itemRect.top);
            SetTextColor(0x25);
            DrawWideText(item->displayName,
                         static_cast<int>(wcslen(item->displayName)));
        }
        const wchar_t hotkey = slot <= 26 ? static_cast<wchar_t>(slot + 96)
                              : slot <= 52 ? static_cast<wchar_t>(slot + 38)
                                           : L' ';
        wchar_t hotkeyText[2] = { hotkey, 0 };
        MoveTo(itemRect.left + 1, itemRect.top + 11);
        SetTextColor(9);
        DrawWideText(hotkeyText, 1);
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kInventorySlotCount; ++slot)
    {
        if (g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    RectBounds buttonRect;
    if (m_pageIndex == 0)
    {
        GetButtonRect(0, &buttonRect);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 12, &buttonFrame);
        RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                        &buttonRect, 0, L"NPAL6.PAL", 0);
    }
    if (m_isLastPage)
    {
        GetButtonRect(1, &buttonRect);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 15, &buttonFrame);
        RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                        &buttonRect, 0, L"NPAL6.PAL", 0);
    }
    const int viewButton = m_viewMode == kGridView ? 3 : 2;
    GetButtonRect(viewButton, &buttonRect);
    g_pEPFLib->CopyEntryTileContext(
        L"SPELLBUT.EPD", m_viewMode == kGridView ? 14 : 13, &buttonFrame);
    RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                    &buttonRect, 0, L"NPAL6.PAL", 0);
}

bool InventoryPane::OnKeyEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;

    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (key == kPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    return false;
}

bool InventoryPane::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int mouseX = event->m_payload.m_pointer.m_x;
    const int mouseY = event->m_payload.m_pointer.m_y;

    if (event->m_type == kMouseDrag)
    {
        const int hit = HitTestSlot(mouseX, mouseY);
        if (hit < 0 || hit >= kLegacyPageSize)
            return false;
        const int slot = VisibleOrdinalToInventorySlot(
            hit + kLegacyPageSize * m_pageIndex + 1);
        if (slot == -1)
            return false;

        unsigned char packet[10];
        PacketBufferWriteUInt8(0x66, packet);
        PacketBufferWriteUInt16BE(
            static_cast<unsigned short>(mouseX) & 0x3fff, packet + 1);
        PacketBufferWriteUInt8(0, packet + 3);
        PacketBufferWriteUInt8(1, packet + 4);
        PacketBufferWriteUInt8(1, packet + 5);
        PacketBufferWriteUInt8(static_cast<unsigned char>(slot), packet + 6);
        PacketBufferWriteUInt8(1, packet + 7);
        PacketBufferWriteUInt8(0, packet + 8);
        PacketBufferWriteUInt8(0, packet + 9);
        g_packetSender->QueueAndSendPacket(packet, 10);
        return true;
    }

    if (event->m_type == kMouseDown)
    {
        const int button = HitTestButton(mouseX, mouseY);
        bool changed = false;
        switch (button)
        {
        case 0:
            if (m_pageIndex > 0)
            {
                --m_pageIndex;
                changed = true;
            }
            break;
        case 1:
            if (!m_isLastPage)
            {
                ++m_pageIndex;
                changed = true;
            }
            break;
        case 2:
            m_viewMode = kListView;
            changed = true;
            break;
        case 3:
            m_viewMode = kGridView;
            changed = true;
            break;
        }
        if (changed)
        {
            InvalidateRect(&m_visibleBounds);
            return true;
        }
        if (g_pConfig->m_doubleClickEnabled)
            return false;
    }
    else if (event->m_type == kMouseDoubleClick)
    {
        if (!g_pConfig->m_doubleClickEnabled)
            return false;
    }
    else
    {
        return false;
    }

    const int hit = HitTestSlot(mouseX, mouseY);
    if (hit < 0 || hit >= kLegacyPageSize)
        return false;
    const int slot = VisibleOrdinalToInventorySlot(
        hit + kLegacyPageSize * m_pageIndex + 1);
    if (slot == -1)
        return false;
    g_pUserPane->UseInventorySlot(slot);
    return true;
}

bool InventoryPane::OnServerMessage(Event *message)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        message->m_payload.m_packet.m_data);
    const unsigned char opcode = packet[0];
    if (opcode < 0x0f)
        return false;
    if (opcode <= 0x10)
    {
        NotifyPaneMessageHandled(false);
        return false;
    }
    if (opcode != 0x59 || (packet[1] >> 6) != 0)
        return false;

    const int side = PacketBufferReadUInt16BE(packet + 1) & 0x3fff;
    const unsigned short textLength = PacketBufferReadUInt16BE(packet + 3);
    if (textLength >= 1 && textLength <= 1023)
    {
        wchar_t text[1024];
        const int count = MultiByteToWideChar(
            CP_ACP, 0, reinterpret_cast<const char *>(packet + 5),
            textLength, text, 1023);
        text[count] = 0;

        RectBounds bounds;
        GetBounds(&bounds);
        if (g_pSimpleHelpPane != 0)
            g_pSimpleHelpPane->Close(true);
        new SimpleHelpPane(
            text, this, (bounds.left + bounds.right) / 2, side, 10000);
    }
    return true;
}

void InventoryPane::GetButtonRect(int button, RectBounds *rect)
{
    static const RectBounds kRects[4] = {
        {59, 259, 81, 277}, {112, 259, 134, 277},
        {81, 259, 103, 277}, {104, 259, 112, 277}
    };
    if (button >= 0 && button < 4)
        *rect = kRects[button];
    else
        InitRectBounds(rect, -1, -1, -1, -1);
}

// UID:00051B | by-memory/0x004eb140-0x004eb1b4.InventoryPaneSlotRectBuilderRaw.md | Completion:90 | Confidence:92
void InventoryPane::GetSlotRect(short slot, RectBounds *bounds) const
{
    int left;
    int top;
    int right;
    int bottom;

    if (static_cast<unsigned short>(slot) >= kLegacyPageSize)
    {
        left = -1;
        top = -1;
        right = -1;
        bottom = -1;
    }
    else if (m_viewMode == kListView)
    {
        left = 30;
        top = 46 + 13 * slot;
        right = 160;
        bottom = 59 + 13 * slot;
    }
    else
    {
        const int row = slot / 3;
        const int column = slot % 3;
        left = 40 + 45 * column;
        top = 40 + 41 * row;
        right = 75 + 45 * column;
        bottom = 75 + 41 * row;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}

// UID:00051H | by-memory/0x004eb1c0-0x004eb291.InventoryPaneButtonHitTestRaw.md | Completion:90 | Confidence:92
int InventoryPane::HitTestButton(int x, int y)
{
    RectBounds rect;
    for (int button = 0; button != 4; ++button)
    {
        GetButtonRect(button, &rect);
        if (PointInRect(y, x, &rect))
            return button;
    }
    return -1;
}

int InventoryPane::HitTestSlot(int x, int y) const
{
    RectBounds rect;
    for (int slot = 0; slot != kLegacyPageSize; ++slot)
    {
        GetSlotRect(slot, &rect);
        if (PointInRect(y, x, &rect))
            return slot;
    }
    return -1;
}

int InventoryPane::VisibleOrdinalToInventorySlot(int ordinal)
{
    for (int slot = 1; slot <= kInventorySlotCount; ++slot)
    {
        if (!g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
            continue;
        if (--ordinal == 0)
            return slot;
    }
    return -1;
}

// UID:00006S | by-class/InventoryPane2.md | Completion:94 | Confidence:94
// UID:00031V | by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md | Completion:88 | Confidence:91
InventoryPane2::InventoryPane2()
    : PanelPane(),
      m_pageIndex(0),
      m_isLastPage(false),
      m_viewMode(kListView),
      m_listButtonState(kButtonNormal),
      m_gridButtonState(kButtonNormal)
{
}

// UID:00048P | by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md | Completion:90 | Confidence:92
InventoryPane2::~InventoryPane2()
{
}

// UID:00048Q | by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md | Completion:87 | Confidence:90
void InventoryPane2::OnActivate(const unsigned char *)
{
    InvalidateRect(&m_visibleBounds);
}

// UID:00048R | by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md | Completion:86 | Confidence:92
void InventoryPane2::PlayItemEffect()
{
}

// UID:00048S | by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md | Completion:89 | Confidence:91
void InventoryPane2::OnPaint()
{
    EPFTileContext frame;
    EPFTileContext buttonFrame;
    RectBounds rect;
    int visibleOrdinal = 0;
    int drawn = 0;
    int slot = 1;

    g_pEPFLib->CopyEntryTileContext(
        L"ITEMINV.EPF", m_viewMode == kGridView ? 0 : 1, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"ITEMINV.PAL", 0);

    while (slot <= kInventorySlotCount)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (item->active && ++visibleOrdinal > m_pageIndex * kCompactPageSize)
            break;
        ++slot;
    }

    for (; slot <= kInventorySlotCount && drawn < kCompactPageSize; ++slot)
    {
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot));
        if (!item->active)
            continue;
        GetSlotRect(drawn, &rect);
        if (m_viewMode == kGridView)
        {
            RectBounds drawBounds = rect;
            g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
        }
        else
        {
            RectBounds drawBounds = rect;
            g_pItemObjImageLib->DrawItemImage(
                this, &drawBounds, item->itemId, item->iconStyle, 0, 0.0f);
            MoveTo(rect.left + 24, rect.top);
            SetTextColor(0x8f);
            DrawWideText(item->displayName,
                         static_cast<int>(wcslen(item->displayName)));
        }
        const wchar_t hotkey = slot <= 26 ? static_cast<wchar_t>(slot + 96)
                              : slot <= 52 ? static_cast<wchar_t>(slot + 38)
                                           : L' ';
        wchar_t hotkeyText[2] = { hotkey, 0 };
        MoveTo(rect.left + 1, rect.top + 11);
        SetTextColor(0x80);
        DrawWideText(hotkeyText, 1);
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kInventorySlotCount; ++slot)
    {
        if (g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    GetButtonRect(2, &rect);
    g_pEPFLib->CopyEntryTileContext(
        L"INVENBUT.EPF", 3 * m_listButtonState, &buttonFrame);
    RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                    &rect, 0, L"ITEMINV.PAL", 0);
    GetButtonRect(3, &rect);
    g_pEPFLib->CopyEntryTileContext(
        L"INVENBUT.EPF", 3 * m_gridButtonState + 1, &buttonFrame);
    RenderTileFrame(&buttonFrame, &buttonFrame.bounds,
                    &rect, 0, L"ITEMINV.PAL", 0);
}

// UID:00048T | by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md | Completion:89 | Confidence:91
bool InventoryPane2::OnKeyEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (key == kPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    return false;
}

// UID:00048U | by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md | Completion:89 | Confidence:91
bool InventoryPane2::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int mouseX = event->m_payload.m_pointer.m_x;
    const int mouseY = event->m_payload.m_pointer.m_y;

    if (event->m_type == kMouseMove)
    {
        const int button = HitTestButton(mouseY, mouseX);
        const int listState = button == 2 ? kButtonHover : kButtonNormal;
        const int gridState = button == 3 ? kButtonHover : kButtonNormal;
        if (listState != m_listButtonState || gridState != m_gridButtonState)
        {
            m_listButtonState = listState;
            m_gridButtonState = gridState;
            InvalidateRect(&m_visibleBounds);
        }
        return button == 2 || button == 3;
    }

    if (event->m_type == kMouseDrag)
    {
        const int hit = HitTestSlot(mouseX, mouseY);
        if (hit < 0 || hit >= kCompactPageSize)
            return false;
        const int slot = VisibleOrdinalToInventorySlot(
            hit + kCompactPageSize * m_pageIndex + 1);
        if (slot == -1)
            return false;
        SendDragDropItemPacketRaw(
            static_cast<unsigned char>(slot),
            static_cast<unsigned char>(event->m_payload.m_pointer.m_detail));
        return true;
    }

    if (event->m_type == kMouseDown)
    {
        const int button = HitTestButton(mouseY, mouseX);
        if (button == 0 && m_pageIndex > 0)
            --m_pageIndex;
        else if (button == 1 && !m_isLastPage)
            ++m_pageIndex;
        else if (button == 2)
            m_viewMode = kListView;
        else if (button == 3)
            m_viewMode = kGridView;
        else if (g_pConfig->m_doubleClickEnabled)
            return false;
        else
            goto use_item;

        m_listButtonState = m_viewMode == kListView ? kButtonPressed : kButtonNormal;
        m_gridButtonState = m_viewMode == kGridView ? kButtonPressed : kButtonNormal;
        InvalidateRect(&m_visibleBounds);
        return true;
    }

    if (event->m_type != kMouseDoubleClick || !g_pConfig->m_doubleClickEnabled)
        return false;

use_item:
    const int hit = HitTestSlot(mouseX, mouseY);
    if (hit < 0 || hit >= kCompactPageSize)
        return false;
    const int slot = VisibleOrdinalToInventorySlot(
        hit + kCompactPageSize * m_pageIndex + 1);
    if (slot == -1)
        return false;
    g_pUserPane->UseInventorySlot(slot);
    return true;
}

// UID:00048V | by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md | Completion:89 | Confidence:91
bool InventoryPane2::OnServerMessage(Event *message)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        message->m_payload.m_packet.m_data);
    const unsigned char opcode = packet[0];
    if (opcode < 0x0f)
        return false;
    if (opcode <= 0x10)
    {
        NotifyPaneMessageHandled(false);
        return false;
    }
    if (opcode != 0x59 || (packet[1] >> 6) != 0)
        return false;

    const int side = PacketBufferReadUInt16BE(packet + 1) & 0x3fff;
    const unsigned short textLength = PacketBufferReadUInt16BE(packet + 3);
    if (textLength >= 1 && textLength <= 1023)
    {
        wchar_t text[1024];
        const int count = MultiByteToWideChar(
            CP_ACP, 0, reinterpret_cast<const char *>(packet + 5),
            textLength, text, 1023);
        text[count] = 0;
        RectBounds bounds;
        GetBounds(&bounds);
        if (g_pSimpleHelpPane != 0)
            g_pSimpleHelpPane->Close(true);
        new SimpleHelpPane(
            text, this, (bounds.left + bounds.right) / 2, side, 10000);
    }
    return true;
}

// UID:00048W | by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md | Completion:88 | Confidence:91
void InventoryPane2::SendUseItemSlotPacketRaw(unsigned char slot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(slot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:00048X | by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md | Completion:88 | Confidence:91
void InventoryPane2::SendDragDropItemPacketRaw(
    unsigned char slot, unsigned char dragSource)
{
    unsigned char packet[10];
    PacketBufferWriteUInt8(0x66, packet);
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt8(dragSource, packet + 2);
    PacketBufferWriteUInt8(0, packet + 3);
    PacketBufferWriteUInt8(1, packet + 4);
    PacketBufferWriteUInt8(1, packet + 5);
    PacketBufferWriteUInt8(slot, packet + 6);
    PacketBufferWriteUInt8(1, packet + 7);
    PacketBufferWriteUInt8(0, packet + 8);
    PacketBufferWriteUInt8(0, packet + 9);
    g_packetSender->QueueAndSendPacket(packet, 10);
}

// UID:0003EJ | by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md | Completion:85 | Confidence:91
void InventoryPane2::GetButtonRect(short button, RectBounds *rect) const
{
    switch (button)
    {
    case 0:
        InitRectBounds(rect, 59, 259, 81, 277);
        break;
    case 1:
        InitRectBounds(rect, 112, 259, 134, 277);
        break;
    case 2:
        InitRectBounds(rect, 168, 66, 185, 83);
        break;
    case 3:
        InitRectBounds(rect, 168, 84, 185, 101);
        break;
    default:
        InitRectBounds(rect, -1, -1, -1, -1);
        break;
    }
}

// UID:0003EL | by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md | Completion:92 | Confidence:94
void InventoryPane2::GetSlotRect(short slot, RectBounds *bounds) const
{
    int left;
    int top;
    int right;
    int bottom;

    if (static_cast<unsigned short>(slot) >= kCompactPageSize)
    {
        left = -1;
        top = -1;
        right = -1;
        bottom = -1;
    }
    else if (m_viewMode == kListView)
    {
        left = 2;
        top = 23 + 23 * slot;
        right = 160;
        bottom = 46 + 23 * slot;
    }
    else
    {
        const int row = slot / 3;
        const int column = slot % 3;
        left = 9 + 51 * column;
        top = 18 + 51 * row;
        right = 57 + 51 * column;
        bottom = 66 + 51 * row;
    }

    InitRectBounds(bounds, left, top, right, bottom);
}

// UID:0003EM | by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md | Completion:94 | Confidence:93
short InventoryPane2::HitTestButton(int y, int x) const
{
    RectBounds bounds;
    for (short button = 0; button < 4; ++button)
    {
        GetButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}

// UID:0003EO | by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md | Completion:85 | Confidence:91
int InventoryPane2::HitTestSlot(int x, int y) const
{
    RectBounds rect;
    for (int slot = 0; slot != kCompactPageSize; ++slot)
    {
        GetSlotRect(slot, &rect);
        if (PointInRect(y, x, &rect))
            return slot;
    }
    return -1;
}

// UID:0003EP | by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md | Completion:85 | Confidence:91
int InventoryPane2::VisibleOrdinalToInventorySlot(int ordinal)
{
    for (int slot = 1; slot <= kInventorySlotCount; ++slot)
    {
        if (!g_pUserPane->GetInventorySlotAddress(static_cast<char>(slot))->active)
            continue;
        if (--ordinal == 0)
            return slot;
    }
    return -1;
}
