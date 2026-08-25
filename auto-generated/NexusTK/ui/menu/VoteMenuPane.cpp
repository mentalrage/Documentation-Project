// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P6
// Source by-file doc: by-file/VoteMenuPane.md
// UID:0000FX | by-class/VoteMenuPane.md | Completion:93 | Confidence:95
#include "VoteMenuPane.h"

static void GetVoteMenuItemRect(int row, RectBounds *bounds);
static signed char HitTestVoteMenuItem(int y, int x);
static void SubmitVote(const wchar_t *targetName, bool promote);

// UID:0002LQ | by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md | Completion:87 | Confidence:91
VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)
    : Pane(1)
{
    g_pVoteMenuPane = this;
    m_voteRowPressed = false;
    m_voteType = voteType;
    m_highlightedVoteRow = kNoVoteRow;
    wcscpy_s(m_targetName, 0x21, targetName);
}

// UID:0002LR | by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md | Completion:86 | Confidence:90
VoteMenuPane::~VoteMenuPane()
{
    ReleasePaneLayerState();
    ReleasePaneHandlerState();
    g_pVoteMenuPane = NULL;
}

// UID:0002LS | by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md | Completion:93 | Confidence:95
bool VoteMenuPane::HandlePointerOrMouseEvent(Event *event)
{
    const int kind = event->m_type;
    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;

    if (kind == kEventCursorMove) {
        m_highlightedVoteRow = HitTestVoteMenuItem(y, x);
        Invalidate();
        return m_highlightedVoteRow != -1;
    }

    if (kind == kEventLeftButtonDown) {
        if (PointInRect(y, x, &m_visibleBounds)) {
            m_voteRowPressed = true;
            Invalidate();
            return true;
        }

        MarkForDeletion();
        return false;
    }

    if (kind == kEventLeftButtonUp) {
        if (!m_voteRowPressed)
            return false;

        m_voteRowPressed = false;
        m_highlightedVoteRow = -1;

        const signed char row = HitTestVoteMenuItem(y, x);
        if (row == kPromoteRow)
            SubmitVote(m_targetName, true);
        else if (row == kDemoteRow)
            SubmitVote(m_targetName, false);
        else
            return false;

        RightButtonMenuPane::CloseRightClickAndVoteMenus();
    }

    return false;
}

// UID:0002LT | by-memory/0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss.md | Completion:92 | Confidence:94
bool VoteMenuPane::HandleKeyOrTextEvent(Event *)
{
    MarkForDeletion();
    return false;
}

// UID:0002LU | by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md | Completion:93 | Confidence:95
void VoteMenuPane::OnPaint()
{
    DrawBackground();
    DrawBorder();

    const int textX = (m_visibleBounds.left + m_visibleBounds.right) / 2 - 24;

    MoveTo(textX, 21);
    DrawWideText(L"Promote", 7);
    MoveTo(textX + 1, 21);
    DrawWideText(L"Promote", 7);

    MoveTo(textX, 37);
    DrawWideText(L"Demote", 7);
    MoveTo(textX + 1, 37);
    DrawWideText(L"Demote", 7);

    if (m_highlightedVoteRow == kPromoteRow ||
        m_highlightedVoteRow == kDemoteRow) {
        RectBounds itemBounds;
        GetVoteMenuItemRect(m_highlightedVoteRow, &itemBounds);

        const int left = itemBounds.left + 5;
        const int right = itemBounds.right - 5;

        MoveTo(left, itemBounds.bottom);

        if (m_voteRowPressed) {
            SetDrawColor(128);
            LineTo(left, itemBounds.top);
            LineTo(right, itemBounds.top);
            SetDrawColor(143);
        } else {
            SetDrawColor(143);
            LineTo(left, itemBounds.top);
            LineTo(right, itemBounds.top);
            SetDrawColor(128);
        }

        LineTo(right, itemBounds.bottom);
        LineTo(left, itemBounds.bottom);
    }
}

// UID:0002LV | by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md | Completion:92 | Confidence:94
void VoteMenuPane::DrawBackground()
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

// UID:0002LW | by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md | Completion:92 | Confidence:94
void VoteMenuPane::DrawBorder()
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


// UID:0000SP | by-global/g_pVoteMenuPane.md | Completion:87 | Confidence:91
VoteMenuPane *g_pVoteMenuPane = NULL;

// UID:0002LX | by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md | Completion:93 | Confidence:95
static void GetVoteMenuItemRect(int row, RectBounds *bounds)
{
    if (row == -1) {
        InitRectBounds(bounds, -1, -1, -1, -1);
        return;
    }

    InitRectBounds(bounds, 0, row * 16 + 6, 79, row * 16 + 22);
}

// UID:0002LY | by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md | Completion:94 | Confidence:95
static signed char HitTestVoteMenuItem(int y, int x)
{
    RectBounds bounds;

    for (signed char row = 0; row < 2; ++row) {
        GetVoteMenuItemRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }

    return -1;
}

// UID:0002LZ | by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md | Completion:94 | Confidence:95
static void SubmitVote(const wchar_t *targetName, bool promote)
{
    MemoryMan *memoryMan = GetMemoryMan();
    char targetBytes[0x100];
    unsigned char packet[0x12c];

    if (targetName[0] == L'\0')
        return;

    PacketBufferWriteUInt8(0x46, packet);
    PacketBufferWriteUInt8(0, packet + 1);

    const unsigned int targetLength = WideCharToMultiByte(
        CP_ACP,
        0,
        targetName,
        static_cast<short>(wcslen(targetName)),
        targetBytes,
        sizeof(targetBytes),
        NULL,
        NULL);

    targetBytes[targetLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(targetLength), packet + 2);
    memoryMan->MemmoveWrapper(packet + 3, targetBytes, targetLength);
    PacketBufferWriteUInt8(static_cast<unsigned char>(promote), packet + targetLength + 3);

    const unsigned int packetLength = targetLength + 4;
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:0001G3 | by-memory\0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md | Completion:88 | Confidence:93 | Empty Emitter Marker
