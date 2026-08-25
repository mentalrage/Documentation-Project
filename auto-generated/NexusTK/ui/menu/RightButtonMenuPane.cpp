// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N7
// Source by-file doc: by-file/RightButtonMenuPane.md
// UID:0000C0 | by-class/RightButtonMenuPane.md | Completion:90 | Confidence:94
#include "RightButtonMenuPane.h"
#include "../../map/MapPane.h"

static void __stdcall GetRightButtonMenuItemRect(int itemIndex, RectBounds *bounds);
static signed char __stdcall HitTestRightButtonMenuItem(int y, int x);
static void __stdcall SendRightButtonTargetActionPacket(int targetId);
static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName);

// UID:0004F8 | by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md | Completion:92 | Confidence:94
RightButtonMenuPane::~RightButtonMenuPane()
{
    if (g_activeMapPane->m_highlightedObjectPane != NULL)
    {
        g_activeMapPane->m_highlightedObjectPane->SetHighlightState(false);
        g_activeMapPane->m_highlightedObjectPane = NULL;
    }

    RemoveFromLayer();
    UnregisterEventHandler();
}

// UID:0004F9 | by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md | Completion:92 | Confidence:94
bool RightButtonMenuPane::OnEvent(const PaneEvent *event)
{
    const int y = event->m_y;
    const int x = event->m_x;
    signed char menuItem;

    switch (event->m_type)
    {
    case kEventCursorMove:
        menuItem = HitTestRightButtonMenuItem(y, x);
        if (menuItem != m_highlightedMenuItem)
        {
            m_highlightedMenuItem = menuItem;
            Invalidate();
        }
        if (menuItem != kNoMenuItem && g_pVoteMenuPane != NULL)
            g_pVoteMenuPane->MarkForDeletion();
        return menuItem != kNoMenuItem;

    case kEventLeftButtonDown:
        menuItem = HitTestRightButtonMenuItem(y, x);
        if (menuItem == kNoMenuItem)
            return false;
        m_menuItemPressed = true;
        m_highlightedMenuItem = menuItem;
        Invalidate();
        return true;

    case kEventLeftButtonUp:
        if (!m_menuItemPressed)
            return false;

        menuItem = HitTestRightButtonMenuItem(y, x);
        m_menuItemPressed = false;
        m_highlightedMenuItem = kNoMenuItem;
        Invalidate();

        switch (menuItem)
        {
        case kLookMenuItem:
            if (g_pWebBoardDialog == NULL)
                new WebBoardDialog(4, m_targetName, 0, 0);
            {
                LivingObjectPane *target = static_cast<LivingObjectPane *>(
                    g_activeMapPane->FindObjectPaneById(m_targetId));
                if (target != NULL)
                    target->SetHighlightState(false);
            }
            break;

        case kTradeMenuItem:
            {
                unsigned char packet[7];
                PacketBufferWriteByte(0x4a, packet);
                PacketBufferWriteByte(0, packet + 1);
                PacketBufferWriteUInt32BE(m_targetId, packet + 2);
                packet[6] = 0;
                g_packetSender->QueueAndSendPacket(packet, 6);
            }
            break;

        case kWhisperMenuItem:
            new NewSayToUserMessageInputPane(m_targetName);
            break;

        case kGroupMenuItem:
            {
                char convertedName[0x100];
                unsigned char packet[0x12c];
                PacketBufferWriteByte('.', packet);
                const short wideLength = static_cast<short>(wcslen(m_targetName));
                const int convertedLength = WideCharToMultiByte(
                    CP_ACP,
                    0,
                    m_targetName,
                    wideLength,
                    convertedName,
                    sizeof(convertedName),
                    NULL,
                    NULL);
                convertedName[convertedLength] = '\0';
                PacketBufferWriteByte(
                    static_cast<unsigned char>(convertedLength),
                    packet + 1);
                memmove(packet + 2, convertedName, convertedLength);
                const int packetLength = convertedLength + 2;
                packet[packetLength] = 0;
                g_packetSender->QueueAndSendPacket(
                    packet,
                    static_cast<short>(packetLength));
            }
            break;

        case kInfoMenuItem:
            RequestObjectInfo(m_targetId);
            break;
        }

        CloseRightClickAndVoteMenus();
        return true;

    case kEventRightButtonDown:
        if (!PointInRect(y, x, &m_visibleBounds))
        {
            CloseRightClickAndVoteMenus();
            return true;
        }
        break;
    }

    return false;
}

// UID:0004FB | by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md | Completion:89 | Confidence:91
int RightButtonMenuPane::OnCancel()
{
    CloseRightClickAndVoteMenus();
    return 0;
}

// UID:0004FC | by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md | Completion:93 | Confidence:95
void RightButtonMenuPane::OnPaint()
{
    DrawBackground();
    DrawBorder();

    RectBounds targetNameBounds = m_visibleBounds;
    targetNameBounds.left += 4;
    targetNameBounds.top = 9;
    targetNameBounds.right -= 4;
    targetNameBounds.bottom = 22;

    SetDrawColor(128);
    FillRect(&targetNameBounds);

    SetTextColor(143);

    const int targetNameLength = static_cast<int>(wcslen(m_targetName));
    const int centerX = (m_visibleBounds.left + m_visibleBounds.right) / 2;
    const int targetNameX = centerX - (targetNameLength * 6) / 2;

    MoveTo(targetNameX, 21);
    DrawWideText(m_targetName, targetNameLength);
    MoveTo(targetNameX + 1, 21);
    DrawWideText(m_targetName, targetNameLength);

    SetTextColor(128);

    const int itemTextX = centerX - 24;

    MoveTo(itemTextX, 37);
    DrawWideText(L"Look", 4);
    MoveTo(itemTextX + 1, 37);
    DrawWideText(L"Look", 4);

    MoveTo(itemTextX, 53);
    DrawWideText(L"Trade", 5);
    MoveTo(itemTextX + 1, 53);
    DrawWideText(L"Trade", 5);

    MoveTo(itemTextX, 69);
    DrawWideText(L"Whisper", 7);
    MoveTo(itemTextX + 1, 69);
    DrawWideText(L"Whisper", 7);

    MoveTo(itemTextX, 85);
    DrawWideText(L"Group", 5);
    MoveTo(itemTextX + 1, 85);
    DrawWideText(L"Group", 5);

    MoveTo(itemTextX, 117);
    DrawWideText(L"Info", 4);
    MoveTo(itemTextX + 1, 117);
    DrawWideText(L"Info", 4);

    if (m_highlightedMenuItem >= 0 && m_highlightedMenuItem <= 4)
    {
        RectBounds itemBounds;
        GetRightButtonMenuItemRect(m_highlightedMenuItem, &itemBounds);

        const int left = itemBounds.left + 5;
        const int right = itemBounds.right - 5;

        MoveTo(left, itemBounds.bottom);

        if (m_menuItemPressed)
        {
            SetDrawColor(128);
            LineTo(left, itemBounds.top);
            LineTo(right, itemBounds.top);
            SetDrawColor(143);
        }
        else
        {
            SetDrawColor(143);
            LineTo(left, itemBounds.top);
            LineTo(right, itemBounds.top);
            SetDrawColor(128);
        }

        LineTo(right, itemBounds.bottom);
        LineTo(left, itemBounds.bottom);
    }
}

// UID:0004FD | by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md | Completion:90 | Confidence:92
void RightButtonMenuPane::CloseRightClickAndVoteMenus()
{
    if (g_pVoteMenuPane != NULL)
        g_pVoteMenuPane->MarkForDeletion();

    MarkForDeletion();
}

// UID:0004FE | by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md | Completion:90 | Confidence:92
void RightButtonMenuPane::SetTargetNameAndId(int targetId, const wchar_t *targetName)
{
    m_targetId = targetId;
    wcscpy_s(m_targetName, 0x21, targetName);
}

// UID:0004FF | by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md | Completion:92 | Confidence:94
void RightButtonMenuPane::DrawBackground()
{
    EPFTileContext tile;
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 8, &tile);

    RectBounds backgroundBounds = m_visibleBounds;
    m_drawMode = 1;

    ++backgroundBounds.left;
    ++backgroundBounds.top;
    --backgroundBounds.right;
    --backgroundBounds.bottom;

    DrawTiledBackground(&backgroundBounds, &tile, L"SUBWIN.PAL");
}

// UID:0004FG | by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md | Completion:92 | Confidence:94
void RightButtonMenuPane::DrawBorder()
{
    EPFTileContext tileContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    InitRectBounds(&sourceBounds, 0, 0, 7, 7);

    const int width = m_visibleBounds.right - m_visibleBounds.left;
    const int height = m_visibleBounds.bottom - m_visibleBounds.top;

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 7, 0);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 1, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 7, 0);
    }
    while (destinationBounds.right < sourceBounds.left + width);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 7, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 6, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 7, 0);
    }
    while (destinationBounds.right < sourceBounds.left + width);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 3, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 0, 7);
    }
    while (destinationBounds.bottom < sourceBounds.top + height);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 4, &tileContext);
    do
    {
        RenderTileFrame(&tileContext,
                        &sourceBounds,
                        &destinationBounds,
                        1,
                        L"SUBWIN.PAL",
                        NULL);
        OffsetRect(&destinationBounds, 0, 7);
    }
    while (destinationBounds.bottom < sourceBounds.top + height);

    destinationBounds = sourceBounds;
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 0, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, 0);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 2, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, 0, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 5, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);

    destinationBounds = sourceBounds;
    OffsetRect(&destinationBounds, width - 7, height - 7);
    g_pEPFLib->LookupLayoutEntry(L"SUBWIN.EPF", 7, &tileContext);
    RenderTileFrame(&tileContext,
                    &sourceBounds,
                    &destinationBounds,
                    1,
                    L"SUBWIN.PAL",
                    NULL);
}

// UID:00023Q | by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md | Completion:87 | Confidence:88
static void __stdcall SendRightButtonTargetActionPacket(int targetId)
{
    unsigned char packet[7];

    PacketBufferWriteByte(0x4a, packet);
    PacketBufferWriteByte(0, packet + 1);
    PacketBufferWriteUInt32BE(targetId, packet + 2);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName)
{
    char convertedName[0x100];
    unsigned char packet[0x12c];

    if (targetName[0] == L'\0')
        return;

    PacketBufferWriteByte('.', packet);

    short wideLength = (short)wcslen(targetName);
    int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        targetName,
        wideLength,
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);

    convertedName[convertedLength] = '\0';
    PacketBufferWriteByte((unsigned char)convertedLength, packet + 1);
    memmove(packet + 2, convertedName, convertedLength);

    int packetLength = convertedLength + 2;
    packet[packetLength] = 0;

    g_packetSender->QueueAndSendPacket(packet, (short)packetLength);
}




// UID:0004FH | by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md | Completion:93 | Confidence:95
static void __stdcall GetRightButtonMenuItemRect(int itemIndex, RectBounds *bounds)
{
    if (itemIndex == -1)
    {
        InitRectBounds(bounds, -1, -1, -1, -1);
        return;
    }

    InitRectBounds(bounds, 0, itemIndex * 16 + 22, 79, itemIndex * 16 + 38);
}

// UID:0004FI | by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md | Completion:93 | Confidence:95
static signed char __stdcall HitTestRightButtonMenuItem(int y, int x)
{
    RectBounds bounds;

    for (signed char itemIndex = 0; itemIndex < 5; ++itemIndex)
    {
        GetRightButtonMenuItemRect(itemIndex, &bounds);
        if (PointInRect(y, x, &bounds))
            return itemIndex;
    }

    return -1;
}

// UID:0001G2 | by-memory\0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003CX | by-memory\0x00622f64-0x00622ff4.RightButtonMenuPaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:00029Z | by-memory\0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md | Completion:87 | Confidence:92 | Empty Emitter Marker
