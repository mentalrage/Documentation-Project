// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LU
// Source by-file doc: by-file/NewSpellInventoryPane.md
// UID:00009A | by-class/NewSpellInventoryPane.md | Completion:94 | Confidence:95
#include "NewSpellInventoryPane.h"
#include "ScrollSpellInventoryPane.h"
#include "../MainUiGraph.h"
#include "../controls/HelpPanes.h"
#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/BackPane.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../map/ObjectPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

#include <cwchar>

namespace
{
    const int kSpellSlotCount = 52;
    const int kCollapsedRowCount = 13;
    const int kExpandedRowCount = 26;

    void SendSwapSpellPacket(unsigned char fromSlot, unsigned char toSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    bool GetButtonRect(short part, RectBounds *bounds);
    short HitTestButton(int localX, int localY);
}

// UID:000534 | by-type/by-struct/NewSpellInventoryPaneLayout.md | Completion:94 | Confidence:95
// NewSpellInventoryPane storage is declared by UID00009A; this exact layout page documents the allocator-proven 0x148 object and emits no duplicate fields.

// UID:00052F | by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md | Completion:94 | Confidence:96
NewSpellInventoryPane::NewSpellInventoryPane()
    : m_scrollPosition(0),
      m_spellListCount(0),
      m_spellInputActive(false),
      m_scrollPane(0),
      m_hoverSpellSlot(-1),
      m_selectedSpellSlot(-1),
      m_activeRepeatTimer(0),
      m_expandButtonState(0),
      m_expanded(false),
      m_draggedSincePress(false)
{
    m_scrollPane = new ScrollSpellInventoryPane(0);
    m_scrollPane->Activate();
}

// UID:00052G | by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md | Completion:92 | Confidence:95
NewSpellInventoryPane::~NewSpellInventoryPane()
{
    delete m_scrollPane;
}

// UID:00052H | by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::OnActivate(const unsigned char *)
{
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}

// UID:00052I | by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds scrollBounds;
    InitRectBounds(&scrollBounds, bounds->right - 20, bounds->top + 57,
                   bounds->right - 7, bounds->bottom - 21);
    m_scrollPane->SetBounds(&scrollBounds, 0);
    PanelPane::UpdateRenderRegion(bounds);
    RebuildSpellList();
}

// UID:00052J | by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::SetBounds(RectBounds *bounds,
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

// UID:00052K | by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md | Completion:94 | Confidence:96
void NewSpellInventoryPane::RebuildSpellList()
{
    unsigned char learnedCount = 0;
    int spellSlot;
    for (spellSlot = 1; spellSlot <= kSpellSlotCount; ++spellSlot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)spellSlot);
        if (record->active)
            m_visibleSpellSlots[++learnedCount] = (unsigned char)spellSlot;
    }

    m_spellListCount = m_expanded ? kSpellSlotCount : learnedCount;
    const int visibleRows = m_expanded ? kExpandedRowCount
                                      : kCollapsedRowCount;
    short maximum = (short)(m_spellListCount - visibleRows);
    if (maximum < 0)
        maximum = 0;
    if (maximum > 30000)
        maximum = 30000;

    if (m_scrollPane->m_scrollRange != maximum)
        m_scrollPane->SetMaxRange(maximum);

    short position = m_scrollPosition < 0 ? 0 : m_scrollPosition;
    if (position > maximum)
        position = maximum;
    if (position > 30000)
        position = 30000;
    if (m_scrollPane->m_scrollPosition != position)
        m_scrollPane->SetScrollPosition(position);
    m_scrollPosition = (signed char)position;
}

// UID:00052L | by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md | Completion:94 | Confidence:96
void NewSpellInventoryPane::OnScrollPositionChanged(
    unsigned char, short oldPosition, short newPosition)
{
    if (oldPosition == newPosition)
        return;

    m_scrollPosition = (signed char)newPosition;
    m_scrollPane->SetScrollPosition(newPosition);
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}

// UID:00052M | by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::AddToLayer(const RectBounds *bounds, int order,
                                       Pane *previousPane, Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);
    RectBounds childBounds;
    m_scrollPane->GetBounds(&childBounds);
    m_scrollPane->AddToLayer(&childBounds, 0, this, layer);
    RebuildSpellList();
}

// UID:00052N | by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:00052O | by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::OnPaint()
{
    EPFTileContext background;
    EPFTileContext button;
    RebuildSpellList();

    const wchar_t *backgroundResource =
        m_expanded ? L"ITEMINVE.EPF" : L"SPELLINV.EPF";
    g_pEPFLib->LookupLayoutEntry(
        backgroundResource, m_expanded ? 2 : 0, &background);
    RenderTileFrame(&background, &background.bounds, &m_visibleBounds,
                    0, L"ITEMINV.PAL", 0);

    m_drawEnabled = true;
    SetTextBackColor(0);

    const int firstTextX = m_expanded ? 17 : 12;
    RectBounds textBounds;
    InitRectBounds(&textBounds, firstTextX, 19, firstTextX + 10, 40);

    const int rowCount = m_expanded ? kExpandedRowCount
                                    : kCollapsedRowCount;
    int row;
    for (row = 0; row < rowCount; ++row)
    {
        const int ordinal = m_scrollPosition + row + 1;
        const int spellSlot = m_expanded
            ? ordinal : m_visibleSpellSlots[ordinal];
        if (spellSlot < 1 || spellSlot > kSpellSlotCount)
            continue;

        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        if (!record->active && !m_expanded)
            continue;

        if (m_hoverSpellSlot == spellSlot)
        {
            RectBounds highlightBounds;
            InitRectBounds(&highlightBounds, 29, textBounds.top - 4,
                           165, textBounds.bottom - 6);
            if (m_expanded)
                OffsetRect(&highlightBounds, 5, 0);
            SetDrawColor(0x8a);
            g_pfnFillRect(this, &highlightBounds);
        }

        wchar_t hotkey = L' ';
        if (spellSlot >= 1 && spellSlot <= 26)
            hotkey = (wchar_t)(L'a' + spellSlot - 1);
        else if (spellSlot >= 27 && spellSlot <= 52)
            hotkey = (wchar_t)(L'A' + spellSlot - 27);

        wchar_t text[128];
        swprintf_s(text, 128, L"%c", hotkey);
        SetTextColor(0x80);
        OffsetRect(&textBounds, 1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        SetTextColor(1);
        OffsetRect(&textBounds, -1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);

        textBounds.left += 25;
        textBounds.right = 160;
        swprintf_s(text, 128, L"%s", record->displayName);
        FitTextAndAppendSuffix(
            text, 128, L"...", textBounds.right - textBounds.left);
        SetTextColor(m_selectedSpellSlot == spellSlot ? 0x8a : 0x80);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);

        InitRectBounds(&textBounds, firstTextX, textBounds.top + 20,
                       firstTextX + 10, textBounds.bottom + 20);
    }

    RectBounds buttonBounds;
    InitRectBounds(&buttonBounds, 168, 37, 185, 54);
    int frameIndex = 7 * m_expandButtonState;
    if (m_expanded)
    {
        OffsetRect(&buttonBounds, 5, 0);
        frameIndex += 3;
    }
    else
    {
        frameIndex += 4;
    }
    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF", frameIndex, &button);
    RenderTileFrame(&button, &button.bounds, &buttonBounds,
                    0, L"invenbut.pal", 0);
}

// UID:00052P | by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md | Completion:93 | Confidence:95
bool NewSpellInventoryPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;

    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (event->m_payload.m_key.m_modifiers == 0 &&
        key == kPaneKeyPageUp)
    {
        short position = (short)(m_scrollPosition - kCollapsedRowCount);
        if (position < 0)
            position = 0;
        m_scrollPosition = (signed char)position;
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
        return true;
    }
    if (event->m_payload.m_key.m_modifiers == 0 &&
        key == kPaneKeyPageDown)
    {
        short maximum = (short)(m_spellListCount - kCollapsedRowCount);
        if (maximum < 0)
            maximum = 0;
        short position = (short)(m_scrollPosition + kCollapsedRowCount);
        if (position > maximum)
            position = maximum;
        m_scrollPosition = (signed char)position;
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
        return true;
    }
    if (key == L'+')
    {
        ToggleExpandedMode();
        return true;
    }

    m_selectedSpellSlot = -1;
    return false;
}

// UID:00052Q | by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md | Completion:93 | Confidence:95
bool NewSpellInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int pointerY = event->m_payload.m_pointer.m_y;
    const int pointerX = event->m_payload.m_pointer.m_x;

    switch (event->m_type)
    {
    case kEventCursorMove:
    {
        if (m_selectedSpellSlot >= 0)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int ordinal = m_scrollPosition + row + 1;
            const int spellSlot = row < 0
                ? -1 : ResolveVisibleSpellSlot((short)ordinal);
            m_hoverSpellSlot =
                spellSlot == m_selectedSpellSlot ? -1 : (signed char)spellSlot;
            InvalidateRect(&m_visibleBounds);

            RectBounds upperRepeat = m_visibleBounds;
            upperRepeat.top -= 90;
            upperRepeat.bottom = m_visibleBounds.top + 20;
            RectBounds lowerRepeat = m_visibleBounds;
            lowerRepeat.top = m_visibleBounds.bottom - 20;
            lowerRepeat.bottom += m_expanded ? 140 : 400;
            if (PointInRect(pointerY, pointerX, &upperRepeat))
            {
                if (m_activeRepeatTimer == 0)
                {
                    m_activeRepeatTimer = 1;
                    ScheduleTimer(1, 50, 0, 0);
                }
            }
            else if (PointInRect(pointerY, pointerX, &lowerRepeat))
            {
                if (m_activeRepeatTimer == 0)
                {
                    m_activeRepeatTimer = 2;
                    ScheduleTimer(2, 50, 0, 0);
                }
            }
            else
            {
                StopActiveRepeatTimer();
            }
        }

        if (!PointInRect(pointerY, pointerX, &m_visibleBounds))
        {
            m_expandButtonState = 0;
            return false;
        }

        if (!g_pConfig->m_doubleClickEnabled &&
            m_selectedSpellSlot >= 0 && !m_draggedSincePress)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0 && spellSlot != m_selectedSpellSlot)
                m_draggedSincePress = true;
        }

        m_expandButtonState = HitTestButton(pointerX, pointerY) == 2 ? 1 : 0;
        if (m_expandButtonState != 0)
            InvalidateRect(&m_visibleBounds);
        break;
    }

    case kEventLeftButtonDown:
    {
        if (HitTestButton(pointerX, pointerY) == 2)
        {
            ToggleExpandedMode();
            break;
        }
        if (g_activeDialogCount <= 0 && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0)
            {
                m_selectedSpellSlot = (signed char)spellSlot;
                m_draggedSincePress = false;
                RectBounds screenBounds;
                GetScreenBounds(&screenBounds);
                Point rowOrigin;
                BuildSpellRowOrigin(&rowOrigin, row);
                new WillBeChangedSpellPane(
                    this, (char)spellSlot,
                    screenBounds.top + rowOrigin.y,
                    screenBounds.left + rowOrigin.x,
                    screenBounds.top + pointerY,
                    screenBounds.left + pointerX);
            }
        }
        break;
    }

    case kEventLeftButtonDoubleClick:
    {
        if (g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0)
                ActivateSpellSlot(spellSlot);
        }
        break;
    }

    case kEventLeftButtonUp:
    {
        if (m_hoverSpellSlot >= 0)
        {
            m_hoverSpellSlot = -1;
            InvalidateRect(&m_visibleBounds);
        }
        if (g_activeDialogCount <= 0)
        {
            StopActiveRepeatTimer();
            if (!PointInRect(pointerY, pointerX, &m_visibleBounds))
                m_selectedSpellSlot = -1;

            if (!m_spellInputActive)
            {
                const int row = HitTestSpellRow(pointerX, pointerY);
                int spellSlot = -1;
                if (row >= 0)
                {
                    const int ordinal = m_scrollPosition + row + 1;
                    spellSlot = m_expanded
                        ? ordinal : ResolveVisibleSpellSlot((short)ordinal);
                }
                if (spellSlot >= 0 && m_selectedSpellSlot >= 0)
                {
                    if (spellSlot == m_selectedSpellSlot)
                    {
                        if (!g_pConfig->m_doubleClickEnabled &&
                            !m_draggedSincePress)
                            ActivateSpellSlot(spellSlot);
                    }
                    else
                    {
                        SendSwapSpellPacket((unsigned char)spellSlot,
                            (unsigned char)m_selectedSpellSlot);
                    }
                }
                m_selectedSpellSlot = -1;
            }
        }
        break;
    }

    case kEventMouseWheel:
        if (PointInRect(pointerY, pointerX, &m_visibleBounds))
        {
            short position = (short)(m_scrollPane->m_scrollPosition -
                                     event->m_payload.m_pointer.m_detail);
            if (position < 0)
                position = 0;
            if (position > m_scrollPane->m_scrollRange)
                position = m_scrollPane->m_scrollRange;
            OnScrollPositionChanged(
                0, m_scrollPane->m_scrollPosition, position);
        }
        break;

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

// UID:00052R | by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md | Completion:93 | Confidence:95
bool NewSpellInventoryPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet != 0 && (unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}

// UID:00052S | by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md | Completion:93 | Confidence:95
bool NewSpellInventoryPane::OnTimer(int timerId, int, int)
{
    const short oldPosition = m_scrollPane->m_scrollPosition;
    short position = oldPosition;
    if (timerId == 1)
    {
        if (position > 0)
            --position;
    }
    else if (timerId == 2)
    {
        if (position < m_scrollPane->m_scrollRange)
            ++position;
    }
    else
        return false;

    if (position != oldPosition)
    {
        m_scrollPosition = (signed char)position;
        m_scrollPane->SetScrollPosition(position);
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
    }
    ScheduleTimer(timerId, 50, 0, 0);
    return true;
}

// UID:00052T | by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md | Completion:94 | Confidence:96
void NewSpellInventoryPane::ActivateSpellSlot(int spellSlot)
{
    if (spellSlot < 1 || spellSlot > kSpellSlotCount)
        return;

    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord((unsigned char)spellSlot);
    if (!record->active)
        return;

    switch (record->inputKind)
    {
    case 1:
        new SpellStringInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 2:
        if (g_activeMapPane != 0 &&
            g_activeMapPane->m_selectedObjectActive &&
            g_activeMapPane->m_selectedObjectPane != 0)
        {
            LivingObjectPane *target =
                g_activeMapPane->m_selectedObjectPane;
            MapPoint position;
            target->GetMapPosition(&position);
            SendTargetedActionPacket(
                (unsigned char)spellSlot,
                (unsigned int)target->GetObjectId(),
                (unsigned short)position.column,
                (unsigned short)position.row);
            m_spellInputActive = false;
        }
        else
        {
            new SpellWhoInputPane((char)spellSlot);
            m_spellInputActive = true;
        }
        break;
    case 3:
        new SpellFourArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 4:
        new SpellThreeArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 5:
    case 9:
        SendDirectSpellPacket((unsigned char)spellSlot);
        m_spellInputActive = false;
        break;
    case 6:
        new SpellTwoArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 7:
        new SpellOneArgInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 8:
        new SpellSlotInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    default:
        m_spellInputActive = false;
        break;
    }
}

// UID:00052U | by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md | Completion:92 | Confidence:95
namespace
{
void SendSwapSpellPacket(unsigned char fromSlot, unsigned char toSlot)
{
    unsigned char packet[5];
    packet[0] = 0x30;
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt8(fromSlot, packet + 2);
    PacketBufferWriteUInt8(toSlot, packet + 3);
    packet[4] = 0;
    g_packetSender->QueueAndSendPacket(packet, 4);
}
}

// UID:00052V | by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md | Completion:93 | Confidence:95
namespace
{
void SendDirectSpellPacket(unsigned char spellSlot)
{
    if (g_activeDialogCount > 0)
        return;

    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}
}

// UID:00052W | by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md | Completion:93 | Confidence:95
namespace
{
bool GetButtonRect(short part, RectBounds *bounds)
{
    if (part != 2)
        return false;
    InitRectBounds(bounds, 168, 37, 185, 54);
    return true;
}
}

// UID:00052X | by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md | Completion:92 | Confidence:95
bool NewSpellInventoryPane::BuildSpellRowRect(
    int row, RectBounds *bounds) const
{
    const int lastRow = m_expanded ? 26 : 12;
    if (row < 0 || row > lastRow)
        return false;
    InitRectBounds(bounds, 2, 16 + 20 * row, 170, 36 + 20 * row);
    return true;
}

// UID:00052Y | by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md | Completion:92 | Confidence:95
namespace
{
short HitTestButton(int localX, int localY)
{
    short part;
    for (part = 0; part <= 2; ++part)
    {
        RectBounds bounds;
        if (GetButtonRect(part, &bounds) &&
            PointInRect(localY, localX, &bounds))
            return part;
    }
    return -1;
}
}

// UID:00052Z | by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md | Completion:93 | Confidence:95
int NewSpellInventoryPane::HitTestSpellRow(int localX, int localY) const
{
    const int lastRow = m_expanded ? 26 : 12;
    int row;
    for (row = 0; row <= lastRow; ++row)
    {
        RectBounds bounds;
        if (BuildSpellRowRect(row, &bounds) &&
            PointInRect(localY, localX, &bounds))
            return row;
    }
    return -1;
}

// UID:000530 | by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md | Completion:93 | Confidence:95
int NewSpellInventoryPane::ResolveVisibleSpellSlot(short visibleOrdinal) const
{
    if (m_expanded)
    {
        const char spellSlot = (char)visibleOrdinal;
        if (spellSlot < 1 || spellSlot > kSpellSlotCount)
            return -1;
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        return record->active ? spellSlot : -1;
    }

    short learnedOrdinal = 0;
    char spellSlot;
    for (spellSlot = 1; spellSlot <= kSpellSlotCount; ++spellSlot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        if (record->active)
            ++learnedOrdinal;
        if (learnedOrdinal == visibleOrdinal)
            return spellSlot;
    }
    return -1;
}

// UID:000531 | by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md | Completion:92 | Confidence:95
void NewSpellInventoryPane::BuildSpellRowOrigin(Point *origin, int row) const
{
    InitPointPair(origin, 19, m_expanded ? 17 : 12);
    origin->y += 20 * row;
}

// UID:000532 | by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::StopActiveRepeatTimer()
{
    if (!m_activeRepeatTimer)
        return;
    CancelTimer(m_activeRepeatTimer);
    m_activeRepeatTimer = 0;
}

// UID:000533 | by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md | Completion:93 | Confidence:95
void NewSpellInventoryPane::ToggleExpandedMode()
{
    m_expandButtonState = 2;
    m_scrollPosition = 0;
    m_expanded = !m_expanded;

    RemoveFromLayer();
    RectBounds bounds;
    SetBounds(&bounds, 0);
    AddToLayer(&bounds, 0, g_pBackPane,
               g_mainUiLayerSlots.rootPaneLayerContext);
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}
