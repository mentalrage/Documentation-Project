// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O1
// Source by-file doc: by-file/SpellInventoryPane.md
// UID:0000DN | by-class/SpellInventoryPane.md | Completion:93 | Confidence:94
#include "SpellInventoryPane.h"

#include <cwchar>

#include "../MainUiGraph.h"
#include "../InterfaceEfx.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"

wchar_t SlotIndexToHotkeyLetter(int slot);

namespace
{
const int kSpellSlotCount = 52;
const int kSpellPageSize = 13;
const int kSpellClickableRows = 10;
}

SpellInventoryPane::SpellInventoryPane()
    : m_pageIndex(0),
      m_isLastPage(false),
      m_spellInputActive(false),
      m_spellEffect(new InterfaceEfx(
          L"MAGEFX.EPD", 50, 434, 12,
          g_mainUiLayerSlots.rootPaneLayerContext, false, L"INTEFX.PAD"))
{
}

SpellInventoryPane::~SpellInventoryPane()
{
    m_spellEffect->MarkForDeletion();
}

void SpellInventoryPane::OnActivate(const unsigned char *)
{
    m_pageIndex = 0;
    m_isLastPage = false;
    InvalidateRect(&m_visibleBounds);
}

void SpellInventoryPane::PlaySpellEffect()
{
    m_spellEffect->Play();
}

void SpellInventoryPane::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->CopyEntryTileContext(L"SPELLINV.EPD", 0, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"NPAL6.PAL", 0);

    int visibleOrdinal = 0;
    int slot = 1;
    while (slot <= kSpellSlotCount)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (record->active && ++visibleOrdinal > m_pageIndex * kSpellPageSize)
            break;
        ++slot;
    }

    Point textPoint;
    InitPointPair(&textPoint, 63, 35);
    SetDrawColor(0x80);
    SetDrawMode(1);
    int drawn = 0;
    for (; slot <= kSpellSlotCount && drawn < kSpellPageSize; ++slot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (!record->active)
            continue;
        wchar_t text[128];
        swprintf_s(text, 128, L"%c: %s",
                   SlotIndexToHotkeyLetter(slot), record->displayName);
        MoveTo(textPoint.x, textPoint.y);
        DrawWideText(text, (int)wcslen(text));
        textPoint.y += 13;
        textPoint.x = 35;
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kSpellSlotCount; ++slot)
    {
        if (g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    SetDrawColor(0x8f);
    SetDrawMode(2);
    RectBounds bounds;
    if (m_pageIndex == 0)
    {
        InitRectBounds(&bounds, 14, 221, 36, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 6, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
    if (m_isLastPage)
    {
        InitRectBounds(&bounds, 157, 221, 179, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 7, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
}

bool SpellInventoryPane::OnKeyEvent(Event *event)
{
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers);
    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0)
        return false;
    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPaneKeyPageDown)
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

bool SpellInventoryPane::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;
    bool handled = false;
    if (event->m_type == kEventLeftButtonDown)
    {
        const int button = HitTestPageButton(y, x);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            handled = true;
        }
        if (handled)
            InvalidateRect(&m_visibleBounds);
        if (!g_pConfig->m_doubleClickEnabled && !m_spellInputActive && !handled)
        {
            const int row = HitTestSpellRow(y, x);
            if (row >= 0)
            {
                const int slot = VisibleOrdinalToSpellSlot(
                    (short)(m_pageIndex * kSpellPageSize + row + 1));
                if (slot != -1)
                {
                    ActivateSpellSlot((unsigned char)slot);
                    return true;
                }
            }
        }
        return handled;
    }
    if (event->m_type == kEventLeftButtonDoubleClick &&
        g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
    {
        const int row = HitTestSpellRow(y, x);
        if (row >= 0)
        {
            const int slot = VisibleOrdinalToSpellSlot(
                (short)(m_pageIndex * kSpellPageSize + row + 1));
            if (slot != -1)
            {
                ActivateSpellSlot((unsigned char)slot);
                return true;
            }
        }
    }
    return false;
}

bool SpellInventoryPane::OnServerMessage(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if ((unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}

void SpellInventoryPane::ActivateSpellSlot(unsigned char spellSlot)
{
    if ((unsigned char)(spellSlot - 1) > 51)
        return;
    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    if (!record->active)
        return;

    switch (record->inputKind)
    {
    case 1:
        new SpellStringInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 2:
        if (g_activeMapPane->m_selectedObjectActive &&
            g_activeMapPane->m_selectedObjectPane != 0)
        {
            LivingObjectPane *target = g_activeMapPane->m_selectedObjectPane;
            MapPoint position;
            target->GetMapPosition(&position);
            SendTargetedActionPacket(spellSlot,
                (unsigned int)target->GetObjectId(),
                (unsigned short)position.column,
                (unsigned short)position.row);
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
        SendDirectSpellPacket(spellSlot);
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
    }
}

void SpellInventoryPane::SendDirectSpellPacket(unsigned char spellSlot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

void __stdcall SpellInventoryPane::BuildPageButtonRect(
    short button, RectBounds *bounds)
{
    if (button == 0)
        InitRectBounds(bounds, 14, 221, 36, 239);
    else if (button == 1)
        InitRectBounds(bounds, 157, 221, 179, 239);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

void __stdcall SpellInventoryPane::BuildSpellRowRect(
    short row, RectBounds *bounds)
{
    if ((unsigned short)row < kSpellPageSize)
        InitRectBounds(bounds, 22, 51 + 13 * row, 170, 64 + 13 * row);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

short __stdcall SpellInventoryPane::HitTestPageButton(int y, int x)
{
    for (short button = 0; button < 2; ++button)
    {
        RectBounds bounds;
        BuildPageButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}

short __stdcall SpellInventoryPane::HitTestSpellRow(int y, int x)
{
    for (short row = 0; row < kSpellPageSize; ++row)
    {
        RectBounds bounds;
        BuildSpellRowRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }
    return -1;
}

int __stdcall SpellInventoryPane::VisibleOrdinalToSpellSlot(short visibleOrdinal)
{
    for (int slot = 1; slot <= kSpellSlotCount; ++slot)
    {
        if (!g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
            continue;
        if (--visibleOrdinal == 0)
            return slot;
    }
    return -1;
}

// UID:0000DO | by-class/SpellInventoryPane2.md | Completion:93 | Confidence:94
// UID:00044D | by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md | Completion:93 | Confidence:94
SpellInventoryPane2::SpellInventoryPane2()
    : m_pageIndex(0),
      m_isLastPage(false),
      m_spellInputActive(false)
{
}

// UID:00044E | by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md | Completion:93 | Confidence:94
SpellInventoryPane2::~SpellInventoryPane2()
{
}

// UID:00044F | by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md | Completion:94 | Confidence:95
void SpellInventoryPane2::OnActivate(const unsigned char *)
{
    m_pageIndex = 0;
    m_isLastPage = false;
    InvalidateRect(&m_visibleBounds);
}

// UID:00044G | by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md | Completion:92 | Confidence:94
void SpellInventoryPane2::SetSpellInputActive(bool active)
{
    m_spellInputActive = active;
}

// UID:00044I | by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md | Completion:94 | Confidence:95
void SpellInventoryPane2::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->CopyEntryTileContext(L"SPELLINV.EPF", 0, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"ITEMINV.PAL", 0);

    int visibleOrdinal = 0;
    int slot = 1;
    while (slot <= kSpellSlotCount)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (record->active && ++visibleOrdinal > m_pageIndex * kSpellPageSize)
            break;
        ++slot;
    }

    SetDrawMode(1);
    SetTextBackColor(0);
    RectBounds textBounds;
    InitRectBounds(&textBounds, 12, 20, 22, 41);
    int drawn = 0;
    for (; slot <= kSpellSlotCount && drawn < kSpellPageSize; ++slot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (!record->active)
            continue;
        wchar_t text[128];
        swprintf_s(text, 128, L"%c", SlotIndexToHotkeyLetter(slot));
        SetTextColor(0x80);
        OffsetRect(&textBounds, 1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        SetTextColor(1);
        OffsetRect(&textBounds, -1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        textBounds.left += 25;
        textBounds.right = 160;
        swprintf_s(text, 128, L"%s", record->displayName);
        SetTextColor(0x80);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        InitRectBounds(&textBounds, 12, textBounds.top + 23,
                       22, textBounds.bottom + 23);
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kSpellSlotCount; ++slot)
    {
        if (g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
        {
            m_isLastPage = false;
            break;
        }
    }
}

// UID:00044J | by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md | Completion:94 | Confidence:95
bool SpellInventoryPane2::OnKeyEvent(Event *event)
{
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers);
    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0)
        return false;
    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPaneKeyPageDown)
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

// UID:00044K | by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md | Completion:94 | Confidence:95
bool SpellInventoryPane2::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;
    bool handled = false;
    if (event->m_type == kEventLeftButtonDown)
    {
        const int button = HitTestPageButton(y, x);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            handled = true;
        }
        if (handled)
            InvalidateRect(&m_visibleBounds);
        if (!g_pConfig->m_doubleClickEnabled && !m_spellInputActive && !handled)
        {
            const int row = HitTestSpellRow(y, x);
            if (row >= 0)
            {
                const int slot = VisibleOrdinalToSpellSlot(
                    (short)(m_pageIndex * kSpellPageSize + row + 1));
                if (slot != -1)
                {
                    ActivateSpellSlot((unsigned char)slot);
                    return true;
                }
            }
        }
        return handled;
    }
    if (event->m_type == kEventLeftButtonDoubleClick &&
        g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
    {
        const int row = HitTestSpellRow(y, x);
        if (row >= 0)
        {
            const int slot = VisibleOrdinalToSpellSlot(
                (short)(m_pageIndex * kSpellPageSize + row + 1));
            if (slot != -1)
            {
                ActivateSpellSlot((unsigned char)slot);
                return true;
            }
        }
    }
    return false;
}

// UID:00044L | by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md | Completion:94 | Confidence:95
bool SpellInventoryPane2::OnServerMessage(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if ((unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}

// UID:00044M | by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md | Completion:94 | Confidence:95
void SpellInventoryPane2::ActivateSpellSlot(unsigned char spellSlot)
{
    if ((unsigned char)(spellSlot - 1) > 51)
        return;
    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    if (!record->active)
        return;
    switch (record->inputKind)
    {
    case 1: new SpellStringInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 2: new SpellWhoInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 3: new SpellFourArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 4: new SpellThreeArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 5: SendDirectSpellPacket(spellSlot); m_spellInputActive = false; break;
    case 6: new SpellTwoArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 7: new SpellOneArgInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 8: new SpellSlotInputPane((char)spellSlot); m_spellInputActive = true; break;
    }
}

// UID:00044N | by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md | Completion:94 | Confidence:95
void SpellInventoryPane2::SendDirectSpellPacket(unsigned char spellSlot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:00044O | by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md | Completion:94 | Confidence:95
void __stdcall SpellInventoryPane2::BuildPageButtonRect(
    short button, RectBounds *bounds)
{
    if (button == 0)
        InitRectBounds(bounds, 14, 221, 36, 239);
    else if (button == 1)
        InitRectBounds(bounds, 157, 221, 179, 239);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

// UID:00044P | by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md | Completion:94 | Confidence:95
void __stdcall SpellInventoryPane2::BuildSpellRowRect(
    short row, RectBounds *bounds)
{
    if ((unsigned short)row < kSpellClickableRows)
        InitRectBounds(bounds, 2, 10 + 23 * row, 170, 33 + 23 * row);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

// UID:00044Q | by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md | Completion:94 | Confidence:95
short __stdcall SpellInventoryPane2::HitTestPageButton(int y, int x)
{
    for (short button = 0; button < 2; ++button)
    {
        RectBounds bounds;
        BuildPageButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}

// UID:00044R | by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md | Completion:94 | Confidence:95
short __stdcall SpellInventoryPane2::HitTestSpellRow(int y, int x)
{
    for (short row = 0; row < kSpellClickableRows; ++row)
    {
        RectBounds bounds;
        BuildSpellRowRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }
    return -1;
}

// UID:00044S | by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md | Completion:94 | Confidence:95
int __stdcall SpellInventoryPane2::VisibleOrdinalToSpellSlot(short visibleOrdinal)
{
    for (int slot = 1; slot <= kSpellSlotCount; ++slot)
    {
        if (!g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
            continue;
        if (--visibleOrdinal == 0)
            return slot;
    }
    return -1;
}
