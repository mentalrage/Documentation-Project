// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LS
// Source by-file doc: by-file/NewInventoryPane.md
// UID:000093 | by-class/NewInventoryPane.md | Completion:94 | Confidence:95
#include "NewInventoryPane.h"
#include "InventoryScrollPane.h"
#include "../MainUiGraph.h"
#include "../controls/HelpPanes.h"
#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../dialogs/ItemActionInputPanes.h"
#include "../panels/UserPane.h"
#include "../panels/UserStatusPane.h"
#include "../../config/Config.h"
#include "../../map/BackPane.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/Surface.h"

#include <cwchar>

namespace
{
    const int kInventorySlotCount = 52;
    const int kCollapsedGridRows = 5;
    const int kExpandedGridRows = 9;
    const int kCollapsedListRows = 13;
    const int kExpandedListRows = 26;

    bool GetButtonRect(short part, RectBounds *bounds);
    short HitTestButton(int localY, int localX);
}

// UID:00053P | by-memory/0x004eb420-0x004eb510.NewInventoryPaneConstructor.md | Completion:94 | Confidence:96
NewInventoryPane::NewInventoryPane()
    : m_scrollPosition(0),
      m_inventoryListCount(0),
      m_viewMode(kInventoryViewList),
      m_unusedState(0),
      m_listButtonState(0),
      m_gridButtonState(0),
      m_expandButtonState(0),
      m_actionButtonState(0),
      m_scrollPane(0),
      m_hoverInventorySlot(-1),
      m_selectedInventorySlot(-1),
      m_activeRepeatTimer(0),
      m_draggedSincePress(false),
      m_expanded(false)
{
    m_scrollPane = new ScrollInventoryPane(0);
    m_scrollPane->Enable();
}

// UID:00053Q | by-memory/0x004eb510-0x004eb545.NewInventoryPaneDestructor.md | Completion:93 | Confidence:95
NewInventoryPane::~NewInventoryPane()
{
    delete m_scrollPane;
}

// UID:00053R | by-memory/0x004eb550-0x004eb567.NewInventoryPaneOnActivate.md | Completion:93 | Confidence:95
void NewInventoryPane::OnActivate(const unsigned char *)
{
    RebuildInventoryList();
    InvalidateRect(&m_visibleBounds);
}

// UID:00053S | by-memory/0x004eb580-0x004eb608.NewInventoryPaneUpdateRenderRegion.md | Completion:93 | Confidence:95
void NewInventoryPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds scrollBounds;
    InitRectBounds(&scrollBounds, bounds->right - 20, bounds->top + 57,
                   bounds->right - 7, bounds->bottom - 21);
    m_scrollPane->SetBounds(&scrollBounds, 0);
    PanelPane::UpdateRenderRegion(bounds);
    RebuildInventoryList();
}

// UID:00053T | by-memory/0x004eb610-0x004eb6b5.NewInventoryPaneSetBounds.md | Completion:93 | Confidence:95
void NewInventoryPane::SetBounds(RectBounds *bounds,
                                 const RectBounds *)
{
    if (m_expanded)
        InitRectBounds(bounds, 827, 79, 1021, 637);
    else
        InitRectBounds(bounds, 832, 79, 1021, 367);

    InitPointPair(&m_origin, bounds->top, bounds->left);
    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -m_origin.x, -m_origin.y);
    UpdateRenderRegion(&localBounds);
}

// UID:00053U | by-memory/0x004eb6c0-0x004eb9f9.NewInventoryPaneRebuildInventoryList.md | Completion:94 | Confidence:96
void NewInventoryPane::RebuildInventoryList()
{
    unsigned char activeCount = 0;
    int slot;
    for (slot = 1; slot <= kInventorySlotCount; ++slot)
    {
        LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress((char)slot);
        if (item->active)
            m_visibleInventorySlots[++activeCount] = (unsigned char)slot;
    }

    m_inventoryListCount = activeCount;
    const int visibleRows = m_viewMode == kInventoryViewGrid
        ? (m_expanded ? kExpandedGridRows : kCollapsedGridRows)
        : (m_expanded ? kExpandedListRows : kCollapsedListRows);
    const int entryCount = m_expanded ? kInventorySlotCount : activeCount;
    int maximum = m_viewMode == kInventoryViewGrid
        ? (entryCount + 2) / 3 - visibleRows
        : entryCount - visibleRows;
    if (maximum < 0)
        maximum = 0;
    if (maximum > 30000)
        maximum = 30000;

    if (m_scrollPane->m_scrollRange != maximum)
        m_scrollPane->SetMaxRange((short)maximum);
    int position = m_scrollPosition < 0 ? 0 : m_scrollPosition;
    if (position > maximum)
        position = maximum;
    if (position > 30000)
        position = 30000;
    if (m_scrollPane->m_scrollPosition != position)
        m_scrollPane->SetScrollPosition((short)position);
    m_scrollPosition = (signed char)position;
}

// UID:00053V | by-memory/0x004eba00-0x004eba8d.NewInventoryPaneOnScrollPositionChanged.md | Completion:94 | Confidence:96
void NewInventoryPane::OnScrollPositionChanged(
    unsigned char, short oldPosition, short newPosition)
{
    if (oldPosition == newPosition)
        return;
    m_scrollPosition = (signed char)newPosition;
    m_scrollPane->SetScrollPosition(newPosition);
    RebuildInventoryList();
    InvalidateRect(&m_visibleBounds);
}

// UID:00053W | by-memory/0x004eba90-0x004ebaf6.NewInventoryPaneAddToLayer.md | Completion:93 | Confidence:95
void NewInventoryPane::AddToLayer(const RectBounds *bounds, int order,
                                  Pane *previousPane, Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);
    RectBounds childBounds;
    m_scrollPane->GetBounds(&childBounds);
    m_scrollPane->AddToLayer(&childBounds, 0, this, layer);
    RebuildInventoryList();
}

// UID:00053X | by-memory/0x004ebb00-0x004ebb16.NewInventoryPaneRemoveFromLayer.md | Completion:93 | Confidence:95
void NewInventoryPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:00053Y | by-memory/0x004ebb20-0x004ec913.NewInventoryPaneOnPaint.md | Completion:94 | Confidence:95
void NewInventoryPane::OnPaint()
{
    EPFTileContext background;
    EPFTileContext button;
    RebuildInventoryList();

    g_pEPFLib->LookupLayoutEntry(
        m_expanded ? L"ITEMINVE.EPF" : L"ITEMINV.EPF",
        m_viewMode == kInventoryViewGrid ? 0 : 1, &background);
    RenderTileFrame(&background, &background.bounds, &m_visibleBounds,
                    0, L"ITEMINV.PAL", 0);

    const int cells = m_viewMode == kInventoryViewGrid
        ? 3 * (m_expanded ? kExpandedGridRows : kCollapsedGridRows)
        : (m_expanded ? kExpandedListRows : kCollapsedListRows);
    int cell;
    for (cell = 0; cell < cells; ++cell)
    {
        const int ordinal = m_viewMode == kInventoryViewGrid
            ? 3 * m_scrollPosition + cell + 1
            : m_scrollPosition + cell + 1;
        const int slot = ResolveVisibleInventorySlot((short)ordinal);
        if (slot < 1)
            continue;
        LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress((char)slot);
        if (!item->active)
            continue;

        RectBounds itemBounds;
        if (!BuildInventorySlotRect(cell, &itemBounds))
            continue;
        if (m_hoverInventorySlot == slot ||
            m_selectedInventorySlot == slot)
        {
            SetDrawColor(m_selectedInventorySlot == slot ? 0x8a : 0x80);
            g_pfnFrameRect(this, &itemBounds);
        }
        if (m_viewMode == kInventoryViewGrid)
        {
            g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                this, &itemBounds, item->itemId, item->iconStyle, 0, 0.0f);
        }
        else
        {
            RectBounds imageBounds = itemBounds;
            imageBounds.right = imageBounds.left + 43;
            g_pItemObjImageLib->DrawItemImage(
                this, &imageBounds, item->itemId, item->iconStyle, 0, 0.0f);
            MoveTo(itemBounds.left + 45, itemBounds.top + 2);
            SetTextColor(m_selectedInventorySlot == slot ? 0x8a : 0x80);
            DrawWideText(item->displayName, (int)wcslen(item->displayName));
        }

        wchar_t hotkey[2] = { L' ', 0 };
        if (slot <= 26)
            hotkey[0] = (wchar_t)(L'a' + slot - 1);
        else if (slot <= 52)
            hotkey[0] = (wchar_t)(L'A' + slot - 27);
        MoveTo(itemBounds.left + 1, itemBounds.top + 11);
        SetTextColor(0x80);
        DrawWideText(hotkey, 1);
        if (item->quantityOrCount > 1)
        {
            wchar_t quantity[16];
            swprintf_s(quantity, 16, L"%d", item->quantityOrCount);
            MoveTo(itemBounds.right - 28, itemBounds.bottom - 15);
            DrawWideText(quantity, (int)wcslen(quantity));
        }
    }

    const int parts[4] = { 2, 3, 4, 5 };
    const int states[4] = { m_listButtonState, m_gridButtonState,
                            m_expandButtonState, m_actionButtonState };
    int index;
    for (index = 0; index < 4; ++index)
    {
        RectBounds bounds;
        if (!GetButtonRect((short)parts[index], &bounds))
            continue;
        const int frame = 3 * states[index] + index;
        g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF", frame, &button);
        RenderTileFrame(&button, &button.bounds, &bounds,
                        0, L"ITEMINV.PAL", 0);
    }
}

// UID:00053Z | by-memory/0x004ec920-0x004ecb44.NewInventoryPaneHandleKeyOrTextEvent.md | Completion:93 | Confidence:95
bool NewInventoryPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (event->m_payload.m_key.m_modifiers == 0 &&
        (key == kPaneKeyPageUp || key == kPaneKeyPageDown))
    {
        const int page = m_viewMode == kInventoryViewGrid
            ? (m_expanded ? kExpandedGridRows : kCollapsedGridRows)
            : (m_expanded ? kExpandedListRows : kCollapsedListRows);
        int position = m_scrollPosition +
            (key == kPaneKeyPageUp ? -page : page);
        if (position < 0)
            position = 0;
        if (position > m_scrollPane->m_scrollRange)
            position = m_scrollPane->m_scrollRange;
        OnScrollPositionChanged(0, m_scrollPosition, (short)position);
        return true;
    }
    if (key == L'+')
    {
        ToggleExpandedMode();
        return true;
    }
    m_selectedInventorySlot = -1;
    return false;
}

// UID:000540 | by-memory/0x004ecb50-0x004ed9c4.NewInventoryPaneHandlePointerOrMouseEvent.md | Completion:94 | Confidence:95
bool NewInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int x = event->m_payload.m_pointer.m_x;
    const int y = event->m_payload.m_pointer.m_y;
    switch (event->m_type)
    {
    case kEventCursorMove:
        if (m_selectedInventorySlot >= 0)
        {
            const int cell = HitTestInventorySlot(x, y);
            const int ordinal = m_viewMode == kInventoryViewGrid
                ? 3 * m_scrollPosition + cell + 1
                : m_scrollPosition + cell + 1;
            const int slot = cell < 0 ? -1
                                      : ResolveVisibleInventorySlot((short)ordinal);
            m_hoverInventorySlot = slot == m_selectedInventorySlot
                ? -1 : (signed char)slot;
            m_draggedSincePress = slot >= 0 &&
                                  slot != m_selectedInventorySlot;
            InvalidateRect(&m_visibleBounds);
        }
        if (!PointInRect(y, x, &m_visibleBounds))
        {
            m_listButtonState = m_gridButtonState = 0;
            m_expandButtonState = m_actionButtonState = 0;
            return false;
        }
        {
            const short part = HitTestButton(y, x);
            m_listButtonState = part == 2 ? 1 : 0;
            m_gridButtonState = part == 3 ? 1 : 0;
            m_expandButtonState = part == 4 ? 1 : 0;
            m_actionButtonState = part == 5 ? 1 : 0;
            InvalidateRect(&m_visibleBounds);
        }
        break;

    case kEventLeftButtonDown:
    {
        const short part = HitTestButton(y, x);
        if (part == 2 || part == 3)
        {
            m_viewMode = part == 2 ? kInventoryViewList : kInventoryViewGrid;
            (part == 2 ? m_listButtonState : m_gridButtonState) = 2;
            m_scrollPosition = 0;
            RebuildInventoryList();
            InvalidateRect(&m_visibleBounds);
            break;
        }
        if (part == 4)
        {
            ToggleExpandedMode();
            break;
        }
        if (part == 5)
        {
            m_actionButtonState = 2;
            InvalidateRect(&m_visibleBounds);
            g_pUserPane->OpenMixItemDialog();
            break;
        }
        if (g_activeDialogCount <= 0)
        {
            const int cell = HitTestInventorySlot(x, y);
            const int ordinal = m_viewMode == kInventoryViewGrid
                ? 3 * m_scrollPosition + cell + 1
                : m_scrollPosition + cell + 1;
            const int slot = cell < 0 ? -1
                                      : ResolveVisibleInventorySlot((short)ordinal);
            if (slot >= 0)
            {
                m_selectedInventorySlot = (signed char)slot;
                m_draggedSincePress = false;
                Point origin;
                BuildInventorySlotOrigin(&origin, cell);
                RectBounds screenBounds;
                GetScreenBounds(&screenBounds);
                new WillBeChangedItemPane(
                    this, (char)slot,
                    screenBounds.top + origin.y,
                    screenBounds.left + origin.x,
                    screenBounds.top + y,
                    screenBounds.left + x,
                    m_viewMode == kInventoryViewList);
            }
        }
        break;
    }

    case kEventLeftButtonDoubleClick:
        if (g_pConfig->m_doubleClickEnabled)
        {
            const int cell = HitTestInventorySlot(x, y);
            const int ordinal = m_viewMode == kInventoryViewGrid
                ? 3 * m_scrollPosition + cell + 1
                : m_scrollPosition + cell + 1;
            const int slot = cell < 0 ? -1
                                      : ResolveVisibleInventorySlot((short)ordinal);
            if (slot >= 0 && !g_pUserPane->m_nameVisible)
                g_pUserPane->UseInventorySlot((unsigned char)slot);
        }
        break;

    case kEventLeftButtonUp:
        m_hoverInventorySlot = -1;
        StopActiveRepeatTimer();
        if (m_selectedInventorySlot >= 0)
        {
            const int cell = HitTestInventorySlot(x, y);
            const int ordinal = m_viewMode == kInventoryViewGrid
                ? 3 * m_scrollPosition + cell + 1
                : m_scrollPosition + cell + 1;
            const int destination = cell < 0 ? -1
                : ResolveVisibleInventorySlot((short)ordinal);
            if (!PointInRect(y, x, &m_visibleBounds))
            {
                if (g_activeMapPane != 0 &&
                    PointInRect(y, x, &g_activeMapPane->m_visibleBounds))
                    SendDropItemPacket((unsigned char)m_selectedInventorySlot);
            }
            else if (destination == m_selectedInventorySlot)
            {
                if (!g_pConfig->m_doubleClickEnabled &&
                    !m_draggedSincePress)
                    g_pUserPane->UseInventorySlot(
                        (unsigned char)m_selectedInventorySlot);
            }
            else if (destination >= 0)
            {
                SendSwapItemPacket((signed char)destination,
                                   (signed char)m_selectedInventorySlot);
            }
            m_selectedInventorySlot = -1;
            InvalidateRect(&m_visibleBounds);
        }
        break;

    case kEventRightButtonDown:
    {
        const int cell = HitTestInventorySlot(x, y);
        const int ordinal = m_viewMode == kInventoryViewGrid
            ? 3 * m_scrollPosition + cell + 1
            : m_scrollPosition + cell + 1;
        const int slot = cell < 0 ? -1
                                  : ResolveVisibleInventorySlot((short)ordinal);
        if (slot >= 0)
        {
            LocalInventorySlotRecord *item =
                g_pUserPane->GetInventorySlotAddress((char)slot);
            RectBounds screenBounds;
            GetScreenBounds(&screenBounds);
            if (g_pSimpleHelpPane != 0)
                g_pSimpleHelpPane->Close(true);
            new SimpleHelpPane(item->displayName, this,
                screenBounds.left + x, screenBounds.top + y, 10000);
        }
        break;
    }

    case kEventMouseWheel:
    {
        short position = (short)(m_scrollPane->m_scrollPosition -
            event->m_payload.m_pointer.m_detail);
        if (position < 0)
            position = 0;
        if (position > m_scrollPane->m_scrollRange)
            position = m_scrollPane->m_scrollRange;
        OnScrollPositionChanged(0, m_scrollPane->m_scrollPosition, position);
        break;
    }
    default:
        break;
    }

    RectBounds scrollBounds;
    m_scrollPane->GetBounds(&scrollBounds);
    event->m_payload.m_pointer.m_y -= scrollBounds.top;
    event->m_payload.m_pointer.m_x -= scrollBounds.left;
    const bool handled = m_scrollPane->HandlePointerOrMouseEvent(event);
    event->m_payload.m_pointer.m_y += scrollBounds.top;
    event->m_payload.m_pointer.m_x += scrollBounds.left;
    return handled;
}

// UID:000541 | by-memory/0x004ed9f0-0x004edb62.NewInventoryPaneHandlePacketEvent.md | Completion:93 | Confidence:95
bool NewInventoryPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if (packet == 0)
        return false;
    if ((unsigned char)(packet[0] - 15) <= 1)
        OnActivate(0);
    if (packet[0] == 0x59 && (packet[1] >> 6) == 0)
    {
        const int side = PacketBufferReadUInt16BE(packet + 1) & 0x3fff;
        const unsigned short length = PacketBufferReadUInt16BE(packet + 3);
        if (length >= 1 && length <= 1023)
        {
            wchar_t text[1024];
            const int count = MultiByteToWideChar(
                CP_ACP, 0, reinterpret_cast<const char *>(packet + 5),
                length, text, 1023);
            text[count] = 0;
            RectBounds bounds;
            GetBounds(&bounds);
            if (g_pSimpleHelpPane != 0)
                g_pSimpleHelpPane->Close(true);
            new SimpleHelpPane(text, this,
                (bounds.left + bounds.right) / 2, side, 10000);
        }
        return true;
    }
    return false;
}

// UID:000542 | by-memory/0x004edb70-0x004edcc5.NewInventoryPaneOnTimer.md | Completion:93 | Confidence:95
bool NewInventoryPane::OnTimer(int timerId, int, int)
{
    short position = m_scrollPane->m_scrollPosition;
    if (timerId == 1 && position > 0)
        --position;
    else if (timerId == 2 && position < m_scrollPane->m_scrollRange)
        ++position;
    else if (timerId != 1 && timerId != 2)
        return false;
    OnScrollPositionChanged(0, m_scrollPane->m_scrollPosition, position);
    ScheduleTimer(timerId, 50, 0, 0);
    return true;
}

// UID:000543 | by-memory/0x004edcd0-0x004edd39.NewInventoryPaneSendUseItemSlotPacket.md | Completion:93 | Confidence:95
void __stdcall NewInventoryPane::SendUseItemSlotPacket(unsigned char slot)
{
    if (g_activeDialogCount > 0)
        return;
    unsigned char packet[3] = { 0x1c, slot, 0 };
    g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:000544 | by-memory/0x004edd40-0x004eddc5.NewInventoryPaneSendDropItemPacket.md | Completion:93 | Confidence:95
void __stdcall NewInventoryPane::SendDropItemPacket(unsigned char slot)
{
    if (g_activeDialogCount > 0 || g_pUserPane->m_nameVisible)
        return;
    unsigned char packet[4] = { 0x08, slot, 0, 0 };
    g_packetSender->QueueAndSendPacket(packet, 3);
}

// UID:000545 | by-memory/0x004eddd0-0x004ede74.NewInventoryPaneSendItemToObjectPacket.md | Completion:93 | Confidence:95
void __stdcall NewInventoryPane::SendItemToObjectPacket(
    unsigned char slot, unsigned int objectId)
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x66, packet);
    PacketBufferWriteUInt16BE(objectId & 0x3fff, packet + 1);
    PacketBufferWriteUInt8(0, packet + 3);
    PacketBufferWriteUInt8(1, packet + 4);
    PacketBufferWriteUInt8(1, packet + 5);
    PacketBufferWriteUInt8(slot, packet + 6);
    PacketBufferWriteUInt8(1, packet + 7);
    PacketBufferWriteUInt8(0, packet + 8);
    PacketBufferWriteUInt8(0, packet + 9);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

// UID:000546 | by-memory/0x004edfb0-0x004ee080.NewInventoryPaneGetButtonRect.md | Completion:93 | Confidence:95
namespace
{
bool GetButtonRect(short part, RectBounds *bounds)
{
    switch (part)
    {
    case 2: InitRectBounds(bounds, 168, 66, 185, 83); return true;
    case 3: InitRectBounds(bounds, 168, 87, 185, 104); return true;
    case 4: InitRectBounds(bounds, 168, 37, 185, 54); return true;
    case 5: InitRectBounds(bounds, 168, 108, 185, 125); return true;
    default: return false;
    }
}
}

// UID:000547 | by-memory/0x004ee0a0-0x004ee13c.NewInventoryPaneBuildInventorySlotRect.md | Completion:93 | Confidence:95
bool NewInventoryPane::BuildInventorySlotRect(
    int cell, RectBounds *bounds) const
{
    if (m_viewMode == kInventoryViewGrid)
    {
        const int lastCell = m_expanded ? 26 : 14;
        if (cell < 0 || cell > lastCell)
            return false;
        InitRectBounds(bounds, 9 + 51 * (cell % 3),
                       18 + 51 * (cell / 3),
                       57 + 51 * (cell % 3),
                       66 + 51 * (cell / 3));
        return true;
    }
    const int lastRow = m_expanded ? 26 : 12;
    if (cell < 0 || cell > lastRow)
        return false;
    InitRectBounds(bounds, 2, 16 + 20 * cell, 160, 36 + 20 * cell);
    return true;
}

// UID:000548 | by-memory/0x004ee140-0x004ee20b.NewInventoryPaneHitTestButton.md | Completion:93 | Confidence:95
namespace
{
short HitTestButton(int localY, int localX)
{
    const short parts[4] = { 2, 3, 4, 5 };
    int index;
    for (index = 0; index < 4; ++index)
    {
        RectBounds bounds;
        if (GetButtonRect(parts[index], &bounds) &&
            PointInRect(localY, localX, &bounds))
            return parts[index];
    }
    return -1;
}
}

// UID:000549 | by-memory/0x004ee230-0x004ee3b7.NewInventoryPaneHitTestInventorySlot.md | Completion:93 | Confidence:95
int NewInventoryPane::HitTestInventorySlot(int localX, int localY) const
{
    const int lastCell = m_viewMode == kInventoryViewGrid
        ? (m_expanded ? 26 : 14) : (m_expanded ? 26 : 12);
    int cell;
    for (cell = 0; cell <= lastCell; ++cell)
    {
        RectBounds bounds;
        if (BuildInventorySlotRect(cell, &bounds) &&
            PointInRect(localY, localX, &bounds))
            return cell;
    }
    return -1;
}

// UID:00054A | by-memory/0x004ee3c0-0x004ee464.NewInventoryPaneResolveVisibleInventorySlot.md | Completion:93 | Confidence:95
int NewInventoryPane::ResolveVisibleInventorySlot(
    short visibleOrdinal) const
{
    if (visibleOrdinal < 1 || visibleOrdinal > kInventorySlotCount)
        return -1;
    const int slot = m_expanded
        ? visibleOrdinal : m_visibleInventorySlots[visibleOrdinal];
    if (slot < 1 || slot > kInventorySlotCount)
        return -1;
    return g_pUserPane->GetInventorySlotAddress((char)slot)->active
        ? slot : -1;
}

// UID:00054B | by-memory/0x004ee470-0x004ee4ee.NewInventoryPaneSendSwapItemPacket.md | Completion:93 | Confidence:95
void __stdcall NewInventoryPane::SendSwapItemPacket(
    signed char destinationSlot, signed char sourceSlot)
{
    if (g_activeDialogCount > 0)
        return;
    unsigned char packet[5] = { 0x30, 0, destinationSlot, sourceSlot, 0 };
    g_packetSender->QueueAndSendPacket(packet, 4);
}

// UID:00054C | by-memory/0x004ee4f0-0x004ee56f.NewInventoryPaneBuildInventorySlotOrigin.md | Completion:93 | Confidence:95
Point *NewInventoryPane::BuildInventorySlotOrigin(
    Point *origin, unsigned short cell) const
{
    if (m_viewMode == kInventoryViewGrid)
        InitPointPair(origin, 18 + 51 * (cell / 3),
                      9 + 51 * (cell % 3));
    else
        InitPointPair(origin, 16 + 20 * cell, 2);
    return origin;
}

// UID:00054D | by-memory/0x004ee570-0x004ee595.NewInventoryPaneStopActiveRepeatTimer.md | Completion:93 | Confidence:95
void NewInventoryPane::StopActiveRepeatTimer()
{
    if (m_activeRepeatTimer == 0)
        return;
    CancelTimer(m_activeRepeatTimer);
    m_activeRepeatTimer = 0;
}

// UID:00054E | by-memory/0x004ee5a0-0x004ee643.NewInventoryPaneToggleExpandedMode.md | Completion:93 | Confidence:95
void NewInventoryPane::ToggleExpandedMode()
{
    m_expandButtonState = 2;
    m_scrollPosition = 0;
    m_expanded = !m_expanded;
    RemoveFromLayer();
    RectBounds bounds;
    SetBounds(&bounds, 0);
    AddToLayer(&bounds, 0, g_pBackPane,
               g_mainUiLayerSlots.rootPaneLayerContext);
    RebuildInventoryList();
    InvalidateRect(&m_visibleBounds);
}
