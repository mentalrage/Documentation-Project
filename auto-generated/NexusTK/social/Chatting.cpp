// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I5
// Source by-file doc: by-file/Chatting.md
// UID:0002XE | by-global/g_pChattingHandlePane.md | Completion:92 | Confidence:94
class ChattingHandlePane;

ChattingHandlePane *g_pChattingHandlePane = 0;

// UID:0002X1 | by-global/g_pChattingModifyHeightPane.md | Completion:92 | Confidence:94
class ChattingModifyHeightPane;

ChattingModifyHeightPane *g_pChattingModifyHeightPane = 0;

// UID:0002X5 | by-global/g_pChattingVarietyPane.md | Completion:92 | Confidence:94
class ChattingVarietyPane;

ChattingVarietyPane *g_pChattingVarietyPane = NULL;

// UID:0002XA | by-global/g_pChattingVarietySelectPane.md | Completion:92 | Confidence:94
class ChattingVarietySelectPane;

ChattingVarietySelectPane *g_pChattingVarietySelectPane = NULL;

// UID:00001V | by-class/ChattingHandlePane.md | Completion:92 | Confidence:94
struct PaneMouseEvent;

static signed char GetChatButtonAtPoint(int mouseY, int mouseX);

enum ChatHandleButtonHit
{
    kChatHandleButtonNone = -1,
    kChatHandleButtonLeft = 0,
    kChatHandleBody = 1,
    kChatHandleButtonMode = 2,
    kChatHandleButtonSecondary = 3,
};

enum ChatHandleButtonPaintState
{
    kChatHandleButtonNormal = 0,
    kChatHandleButtonHover = 1,
    kChatHandleButtonPressed = 2,
};

struct ChattingHandleRenderState
{
    bool valid;
    bool chatTargetPending;
    int chatHandleModeIndex;
    bool secondaryChatEnabled;
    int leftButtonPaintState;
    int modeButtonPaintState;
    int secondaryButtonPaintState;
};

class ChattingHandlePane : public Pane,
                           public Singleton<ChattingHandlePane>
{
public:
    ChattingHandlePane();
    virtual ~ChattingHandlePane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    bool IsRenderStateCurrent(const ChattingHandleRenderState *state) const;
    void CaptureRenderState(ChattingHandleRenderState *state) const;

    ChattingHandleRenderState m_renderStateSnapshot;
    bool m_mouseCaptured;

public:
    bool m_chatTargetPending;
    int m_chatHandleModeIndex;
    bool m_secondaryChatEnabled;

private:
    bool m_leftButtonPressed;
    bool m_modeButtonPressed;
    bool m_secondaryButtonPressed;
    int m_leftButtonPaintState;
    int m_modeButtonPaintState;
    int m_secondaryButtonPaintState;
};

extern ChattingHandlePane *g_pChattingHandlePane;

// UID:0002FP | by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md | Completion:90 | Confidence:93
bool ChattingHandlePane::IsRenderStateCurrent(
    const ChattingHandleRenderState *state) const
{
    if (!state->valid)
        return false;

    return state->chatTargetPending == m_chatTargetPending &&
           state->chatHandleModeIndex == m_chatHandleModeIndex &&
           state->secondaryChatEnabled == m_secondaryChatEnabled &&
           state->leftButtonPaintState == m_leftButtonPaintState &&
           state->modeButtonPaintState == m_modeButtonPaintState &&
           state->secondaryButtonPaintState == m_secondaryButtonPaintState;
}

// UID:0002FQ | by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md | Completion:90 | Confidence:93
void ChattingHandlePane::CaptureRenderState(
    ChattingHandleRenderState *state) const
{
    state->valid = true;
    state->chatTargetPending = m_chatTargetPending;
    state->chatHandleModeIndex = m_chatHandleModeIndex;
    state->secondaryChatEnabled = m_secondaryChatEnabled;
    state->leftButtonPaintState = m_leftButtonPaintState;
    state->modeButtonPaintState = m_modeButtonPaintState;
    state->secondaryButtonPaintState = m_secondaryButtonPaintState;
}

// UID:0002FR | by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md | Completion:92 | Confidence:94
ChattingHandlePane::ChattingHandlePane()
    : Pane(1),
      Singleton<ChattingHandlePane>()
{
    m_mouseCaptured = false;
    m_chatHandleModeIndex = g_pConfig->m_chatHandleModeIndex;
    m_secondaryChatEnabled = (g_pConfig->m_secondaryChatEnabled != 0);
    m_chatTargetPending = (g_pConfig->m_chatHandleLeftToggle != 0);

    if (m_secondaryChatEnabled)
        g_pChattingDisplayPane->m_scrollWidget->Enable();
    else
        g_pChattingDisplayPane->m_scrollWidget->Disable();

    m_leftButtonPressed = false;
    m_modeButtonPressed = false;
    m_secondaryButtonPressed = false;
    m_leftButtonPaintState = kChatHandleButtonNormal;
    m_modeButtonPaintState = kChatHandleButtonNormal;
    m_secondaryButtonPaintState = kChatHandleButtonNormal;
    m_renderStateSnapshot.valid = false;
}

// UID:0002FS | by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md | Completion:92 | Confidence:94
ChattingHandlePane::~ChattingHandlePane()
{
}

// UID:0002FT | by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md | Completion:89 | Confidence:91
bool ChattingHandlePane::OnMouseEvent(const PaneMouseEvent *event)
{
    bool handled = false;

    if (g_pUserPane->m_inputLocked)
        return false;

    switch (event->type) {
    case kPaneMouseMove:
    {
        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            m_leftButtonPaintState = kChatHandleButtonNormal;
            m_modeButtonPaintState = kChatHandleButtonNormal;
            m_secondaryButtonPaintState = kChatHandleButtonNormal;
            break;
        }

        RectBounds leftButtonRect;
        RectBounds modeButtonRect;
        RectBounds secondaryButtonRect;

        InitRectBounds(&leftButtonRect, 0, 4, 19, 21);
        InitRectBounds(&modeButtonRect, 630, 4, 649, 21);
        InitRectBounds(&secondaryButtonRect, 649, 4, 668, 21);

        const bool overLeft =
            PointInRect(event->mouseY, event->mouseX, &leftButtonRect);
        const bool overMode =
            PointInRect(event->mouseY, event->mouseX, &modeButtonRect);
        const bool overSecondary =
            PointInRect(event->mouseY, event->mouseX, &secondaryButtonRect);

        if (m_mouseCaptured) {
            m_leftButtonPaintState =
                (overLeft && m_leftButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                (overMode && m_modeButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                (overSecondary && m_secondaryButtonPressed)
                    ? kChatHandleButtonPressed
                    : kChatHandleButtonNormal;
        } else {
            m_leftButtonPaintState =
                overLeft ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_modeButtonPaintState =
                overMode ? kChatHandleButtonHover : kChatHandleButtonNormal;
            m_secondaryButtonPaintState =
                overSecondary ? kChatHandleButtonHover : kChatHandleButtonNormal;
        }

        handled = true;
        break;
    }

    case kPaneMouseLeftButtonDown:
        m_mouseCaptured = true;

        switch (GetChatButtonAtPoint(event->mouseY, event->mouseX)) {
        case kChatHandleButtonLeft:
            m_leftButtonPressed = true;
            m_leftButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleBody:
            if (g_pUserPane->m_pendingTargetObject == NULL) {
                OpenInputPaneForCurrentSayMode(g_pUserPane);
                handled = true;
            }
            break;

        case kChatHandleButtonMode:
            m_modeButtonPressed = true;
            m_modeButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            m_secondaryButtonPressed = true;
            m_secondaryButtonPaintState = kChatHandleButtonPressed;
            handled = true;
            break;

        default:
            break;
        }
        break;

    case kPaneMouseLeftButtonUp:
        m_mouseCaptured = false;

        switch (GetChatButtonAtPoint(event->mouseY, event->mouseX)) {
        case kChatHandleButtonLeft:
            if (m_leftButtonPressed)
                m_chatTargetPending = !m_chatTargetPending;
            handled = true;
            break;

        case kChatHandleButtonMode:
            if (m_modeButtonPressed) {
                m_chatHandleModeIndex = (m_chatHandleModeIndex + 1) % 3;
                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
            }
            handled = true;
            break;

        case kChatHandleButtonSecondary:
            if (m_secondaryButtonPressed) {
                m_secondaryChatEnabled = !m_secondaryChatEnabled;

                if (m_secondaryChatEnabled)
                    g_pChattingDisplayPane->m_scrollWidget->Enable();
                else
                    g_pChattingDisplayPane->m_scrollWidget->Disable();

                g_pChattingBackPane->InvalidateRect(&g_pChattingBackPane->m_bounds);
                g_pChattingDisplayPane->InvalidateRect(&g_pChattingDisplayPane->m_bounds);
                g_pChattingModifyHeightPane->InvalidateRect(&g_pChattingModifyHeightPane->m_bounds);
            }
            handled = true;
            break;

        default:
            break;
        }

        m_leftButtonPressed = false;
        m_modeButtonPressed = false;
        m_secondaryButtonPressed = false;

        g_pConfig->m_chatHandleModeIndex = m_chatHandleModeIndex;
        g_pConfig->m_secondaryChatEnabled = m_secondaryChatEnabled;
        g_pConfig->m_chatHandleLeftToggle = m_chatTargetPending;
        break;

    default:
        break;
    }

    if (!m_renderStateSnapshot.valid ||
        m_renderStateSnapshot.chatTargetPending != m_chatTargetPending ||
        m_renderStateSnapshot.chatHandleModeIndex != m_chatHandleModeIndex ||
        m_renderStateSnapshot.secondaryChatEnabled != m_secondaryChatEnabled ||
        m_renderStateSnapshot.leftButtonPaintState != m_leftButtonPaintState ||
        m_renderStateSnapshot.modeButtonPaintState != m_modeButtonPaintState ||
        m_renderStateSnapshot.secondaryButtonPaintState != m_secondaryButtonPaintState) {
        InvalidateRect(&m_bounds);
    }

    return handled;
}

// UID:0002FU | by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md | Completion:89 | Confidence:91
void ChattingHandlePane::OnPaint()
{
    EPFTileContext tile;
    RectBounds drawRect;

    SetPaneDrawMode(0);

    InitRectBounds(&drawRect, 0, 4, 19, 21);
    int frameIndex = 3 * m_leftButtonPaintState;
    if (!m_chatTargetPending)
        frameIndex += 9;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 630, 4, 649, 21);
    frameIndex = 3 * m_modeButtonPaintState;
    if (m_chatHandleModeIndex)
        frameIndex += 1;
    else
        frameIndex += 10;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 649, 4, 668, 21);
    frameIndex = 3 * m_secondaryButtonPaintState;
    if (m_secondaryChatEnabled)
        frameIndex += 2;
    else
        frameIndex += 11;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    m_renderStateSnapshot.valid = true;
    m_renderStateSnapshot.chatTargetPending = m_chatTargetPending;
    m_renderStateSnapshot.chatHandleModeIndex = m_chatHandleModeIndex;
    m_renderStateSnapshot.secondaryChatEnabled = m_secondaryChatEnabled;
    m_renderStateSnapshot.leftButtonPaintState = m_leftButtonPaintState;
    m_renderStateSnapshot.modeButtonPaintState = m_modeButtonPaintState;
    m_renderStateSnapshot.secondaryButtonPaintState = m_secondaryButtonPaintState;
}

// UID:00001W | by-class/ChattingModifyHeightPane.md | Completion:92 | Confidence:94
class Event;
struct PaneMouseEvent;

class ChattingModifyHeightPane : public Pane,
                                 public Singleton<ChattingModifyHeightPane>
{
public:
    ChattingModifyHeightPane();
    virtual ~ChattingModifyHeightPane();

    void SetLineCount(int requestedLineCount);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool m_dragActive;
    int m_dragAnchorY;
    RectBounds m_handleRect;
};

extern ChattingModifyHeightPane *g_pChattingModifyHeightPane;

// UID:0002F4 | by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md | Completion:92 | Confidence:94
ChattingModifyHeightPane::ChattingModifyHeightPane()
    : Pane(1),
      Singleton<ChattingModifyHeightPane>(),
      m_dragActive(false)
{
    InitRectBounds(&m_handleRect, 792, 590, 807, 605);
}

// UID:0002F5 | by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md | Completion:92 | Confidence:94
ChattingModifyHeightPane::~ChattingModifyHeightPane()
{
}

// UID:0002F6 | by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md | Completion:88 | Confidence:92
bool ChattingModifyHeightPane::OnMouseEvent(const PaneMouseEvent *event)
{
    if (!g_pChattingHandlePane->m_secondaryChatEnabled)
        return false;

    switch (event->type) {
    case kPaneMouseMove:
        if (!m_dragActive)
            return false;
        {
            RectBounds currentBounds;
            GetBounds(&currentBounds);

            int clampedY = currentBounds.top + event->mouseY;
            if (clampedY < 50)
                clampedY = 50;
            else if (clampedY > 650)
                clampedY = 650;

            RectBounds previewRect;
            InitRectBounds(&previewRect, 792, clampedY - m_dragAnchorY,
                           807, clampedY - m_dragAnchorY + 15);
            SetBounds(previewRect, false);
        }
        return true;

    case kPaneMouseLeftButtonDown:
        if (PointInRect(event->mouseY, event->mouseX, &m_handleRect)) {
            m_dragActive = true;
            m_dragAnchorY = event->mouseY;
            return true;
        }
        return false;

    case kPaneMouseLeftButtonUp:
        if (!m_dragActive)
            return false;
        {
            m_dragActive = false;

            RectBounds currentBounds;
            GetBounds(&currentBounds);

            int clampedY = currentBounds.top + event->mouseY;
            if (clampedY < 50)
                clampedY = 50;
            else if (clampedY > 650)
                clampedY = 650;

            int visibleLineCount = (710 - clampedY) / 13;
            if (visibleLineCount < 4)
                visibleLineCount = 4;

            g_pChattingBackPane->SetChatViewportLineCount(visibleLineCount);
            g_pChattingDisplayPane->SetVisibleRowCount(visibleLineCount);

            RectBounds handleRect;
            InitRectBounds(&handleRect, 792,
                           693 - 13 * visibleLineCount,
                           807,
                           708 - 13 * visibleLineCount);
            SetBounds(handleRect, false);
            m_handleRect = handleRect;

            g_pConfig->m_chatVisibleLineCount = visibleLineCount;
        }
        return true;
    }

    return false;
}

// UID:0002F7 | by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool ChattingModifyHeightPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == 0x2f || packet[0] == 0x30 || packet[0] == 0x42) {
        m_dragActive = false;
        SetBounds(&m_handleRect, false);
        InvalidateRect(&m_bounds);
    }

    return false;
}

// UID:0002F8 | by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md | Completion:88 | Confidence:92
void ChattingModifyHeightPane::SetLineCount(int requestedLineCount)
{
    int visibleLineCount = 40;
    if (requestedLineCount <= 50)
        visibleLineCount = requestedLineCount;
    if (visibleLineCount < 4)
        visibleLineCount = 4;

    RectBounds backBounds;
    g_pChattingBackPane->GetBounds(&backBounds);

    RectBounds viewport;
    InitRectBounds(&viewport, 9, 700 - 13 * visibleLineCount, 816, 720);
    g_pChattingBackPane->SetBounds(viewport, false);
    g_pChattingBackPane->InvalidateRect(g_pChattingBackPane->m_rect);

    g_pChattingDisplayPane->SetVisibleRowCount(visibleLineCount);

    RectBounds handleRect;
    InitRectBounds(&handleRect, 792,
                   693 - 13 * visibleLineCount,
                   807,
                   708 - 13 * visibleLineCount);
    SetBounds(handleRect, false);
    m_handleRect = handleRect;
}

// UID:0002F9 | by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md | Completion:88 | Confidence:92
void ChattingModifyHeightPane::OnPaint()
{
    if (!g_pChattingHandlePane->m_secondaryChatEnabled) {
        SetMode(1);
        SetGrafPortColorState(0);
        g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);
        return;
    }

    EPFTileContext tile;
    g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &m_rect, 0, L"invenbut.pal", 0);
}

// UID:00001Z | by-class/ChattingVarietySelectPane.md | Completion:93 | Confidence:94
class ChattingColorPane;
class Event;

class ChattingVarietySelectPane : public Pane,
                                  public Singleton<ChattingVarietySelectPane>
{
public:
    ChattingVarietySelectPane();
    virtual ~ChattingVarietySelectPane();

protected:
    virtual void OnPaint();
    virtual void SetupBackground();
    virtual void DrawBorder();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool OnDismiss(Event *event);

private:
    void GetItemRect(int row, RectBounds *outRect);
    signed char HitTest(int mouseY, int mouseX);

    bool m_pressCaptured;
    signed char m_hotRow;
};

extern ChattingVarietySelectPane *g_pChattingVarietySelectPane;

// UID:0002FH | by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md | Completion:92 | Confidence:94
ChattingVarietySelectPane::ChattingVarietySelectPane()
    : Pane(1),
      Singleton<ChattingVarietySelectPane>(),
      m_pressCaptured(false),
      m_hotRow(-1)
{
}

// UID:0002FI | by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md | Completion:92 | Confidence:94
ChattingVarietySelectPane::~ChattingVarietySelectPane()
{
    RemoveFromLayer();
    UnregisterEventHandler();
}

// UID:0002FJ | by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md | Completion:94 | Confidence:95
bool ChattingVarietySelectPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->m_inputLocked)
        return false;

    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;

    switch (event->m_type)
    {
    case kEventCursorMove:
        m_hotRow = HitTest(mouseY, mouseX);
        InvalidateRect(&m_visibleBounds);
        return m_hotRow != -1;

    case kEventLeftButtonDown:
        if (PointInRect(mouseY, mouseX, &m_visibleBounds))
        {
            m_pressCaptured = true;
            InvalidateRect(&m_visibleBounds);
            return true;
        }
        OnDismiss(event);
        return false;

    case kEventLeftButtonUp:
        if (!m_pressCaptured)
            return false;

        m_pressCaptured = false;
        m_hotRow = -1;

        switch (HitTest(mouseY, mouseX))
        {
        case 0:
            g_pUserPane->m_currentSayMode = kSayInputModeDefault;
            OpenInputPaneForCurrentSayMode(g_pUserPane);
            break;
        case 1:
            g_pUserPane->m_currentSayMode = kSayInputModeShout;
            OpenShoutInputPane(g_pUserPane);
            break;
        case 2:
            g_pUserPane->m_currentSayMode = kSayInputModeWhisper;
            OpenSayToUserNameInputPane();
            break;
        case 3:
            g_pUserPane->m_currentSayMode = kSayInputModeGroup;
            OpenSayToGroupMessageInputPane();
            break;
        case 4:
            g_pUserPane->m_currentSayMode = kSayInputModeClan;
            OpenSayToClanMessageInputPane();
            break;
        case 5:
            new ChattingColorPane();
            break;
        default:
            g_pChattingVarietyPane->Refresh();
            if (!PointInRect(mouseY, mouseX, &m_visibleBounds))
                MarkForDeletion();
            return false;
        }

        OnDismiss(event);
        return true;

    default:
        return false;
    }
}

// UID:0002FK | by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md | Completion:94 | Confidence:95
bool ChattingVarietySelectPane::OnDismiss(Event *)
{
    g_pChattingVarietyPane->Refresh();
    MarkForDeletion();
    return false;
}

// UID:0002FL | by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md | Completion:93 | Confidence:95
void ChattingVarietySelectPane::OnPaint()
{
    SetupBackground();
    DrawBorder();

    const int textX = (m_visibleBounds.left + m_visibleBounds.right) / 2 - 18;

    MoveTo(textX, 21);
    DrawWideText(L"Talk", 4);
    MoveTo(textX + 1, 21);
    DrawWideText(L"Talk", 4);

    MoveTo(textX, 37);
    DrawWideText(L"Shout", 5);
    MoveTo(textX + 1, 37);
    DrawWideText(L"Shout", 5);

    MoveTo(textX, 53);
    DrawWideText(L"Whisper", 7);
    MoveTo(textX + 1, 53);
    DrawWideText(L"Whisper", 7);

    MoveTo(textX, 69);
    DrawWideText(L"Group", 5);
    MoveTo(textX + 1, 69);
    DrawWideText(L"Group", 5);

    MoveTo(textX, 85);
    DrawWideText(L"Clan", 4);
    MoveTo(textX + 1, 85);
    DrawWideText(L"Clan", 4);

    MoveTo(textX - 6, 101);
    DrawWideText(L"-Color-", 7);
    MoveTo(textX - 5, 101);
    DrawWideText(L"-Color-", 7);

    if (m_hotRow >= 0 && m_hotRow <= 5) {
        RectBounds itemBounds;
        GetItemRect(m_hotRow, &itemBounds);

        const int left = itemBounds.left + 4;
        const int right = itemBounds.right - 5;

        MoveTo(left, itemBounds.bottom);
        if (m_pressCaptured) {
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

// UID:0002FN | by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md | Completion:92 | Confidence:94
void ChattingVarietySelectPane::SetupBackground()
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

// UID:0002FO | by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md | Completion:92 | Confidence:94
void ChattingVarietySelectPane::DrawBorder()
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

// UID:0002FM | by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md | Completion:92 | Confidence:94
void ChattingVarietySelectPane::GetItemRect(int row, RectBounds *outRect)
{
    if (row == -1)
    {
        InitRectBounds(outRect, -1, -1, -1, -1);
        return;
    }

    InitRectBounds(outRect, 0, row * 16 + 6, 67, row * 16 + 22);
}

// UID:000106 | by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md | Completion:92 | Confidence:94
signed char ChattingVarietySelectPane::HitTest(int mouseY, int mouseX)
{
    for (signed char itemIndex = 0; itemIndex < 6; ++itemIndex)
    {
        RectBounds itemRect;
        GetItemRect(itemIndex, &itemRect);

        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}

// UID:00001Q | by-class/ChatInputPane.md | Completion:87 | Confidence:90
class TextEditPane;
struct PaneKeyEvent;

class ChatInputPane : public MultiLineInputPane
{
public:
    ChatInputPane();
    virtual ~ChatInputPane();

protected:
    virtual bool HandleSpecialInput(PaneKeyEvent *event);
    virtual short SendChatMessage();

private:
    // The inherited LineInputPane edit child is observed at primary +0xfc.
    // The secondary key-handler view receives `this + 0xa0`, so it sees this
    // cursor at secondary +0x68.
    short m_chatHistoryCursor;        // +0x108, initialized to -1.
    unsigned char m_reserved10A[2];   // +0x10a..+0x10b alignment/tail bytes.

    // UID:0002S9 | by-memory/0x005b38e0-0x005b3935.ChatInputPaneRawConstructor.md | Completion:88 | Confidence:91
ChatInputPane::ChatInputPane()
    : MultiLineInputPane(L">"),
      m_chatHistoryCursor(-1)
{
    g_pChatInputPane = this;
}

// UID:0001MC | by-memory/0x005b3940-0x005b3bba.ChatInputPane.md | Completion:88 | Confidence:90
#include "../auth/PasswordGuard.h"

bool ChatInputPane::HandleSpecialInput(PaneKeyEvent *event)
{
    const unsigned char key = NarrowInputEventByte(event);

    if (event->imeActive == 0 &&
        event->eventKind == 8 &&
        (key == 0x81 || key == 0x83)) {
        wchar_t historyText[256] = {};

        if (key == 0x81) {
            GetPreviousChatHistoryEntry(g_pCollectionData, &m_chatHistoryCursor,
                                        historyText, 256);
        } else {
            GetNextChatHistoryEntry(g_pCollectionData, &m_chatHistoryCursor,
                                    historyText, 256);
        }

        if (historyText[0] != L'\0') {
            m_textEditPane->SelectText(0, 0x7fff);
            m_textEditPane->InsertText(historyText,
                                       static_cast<int>(wcslen(historyText)),
                                       0,
                                       0);
            m_textEditPane->SelectText(0, 0x7fff);
        }

        return true;
    }

    return MultiLineInputPane::HandleKeyInput(event);
}

short ChatInputPane::SendChatMessage()
{
    short length = LineInputPane::TextLength();
    if (length <= 0) {
        return length;
    }

    if (g_pCollectionData->chatInputSendBlocked != 0) {
        return length;
    }

    wchar_t wideText[256] = {};
    LineInputPane::CopyText(wideText, 255);
    if (wideText[0] == L'\0') {
        return length;
    }

    ValidateChatInputOrThrowPasswordError(wideText);
    SanitizeWideTextForChat(wideText, static_cast<int>(wcslen(wideText)));

    unsigned char packet[300] = {};
    char multibyteText[256] = {};
    void *packetCopyContext = GetMemoryMan();

    PacketBufferWriteUInt8(0x0e, packet + 0);
    PacketBufferWriteUInt16BE(0, packet + 1);

    const int convertedLength = WideCharToMultiByte(
        0, 0, wideText, static_cast<int>(wcslen(wideText)),
        multibyteText, sizeof(multibyteText), 0, 0);
    if (convertedLength >= 0x100) {
        ReportRangeCheckFailure();
    }

    multibyteText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength);

    const int packetLength = convertedLength + 3;
    if (packetLength >= 0x12c) {
        ReportRangeCheckFailure();
    }

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    return SaveChatHistoryEntry(g_pCollectionData, wideText);
}

};


// UID:0002F1 | by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md | Completion:90 | Confidence:93
ChattingBackPane::ChattingBackPane()
    : Pane(2),
      Singleton<ChattingBackPane>()
{
    m_alpha = 0.6f;
}

// UID:0002F2 | by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md | Completion:88 | Confidence:90
ChattingBackPane::~ChattingBackPane()
{
    g_pChattingBackPane = NULL;
}

// UID:000105 | by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md | Completion:87 | Confidence:91
void ChattingBackPane::SetChatViewportLineCount(int visibleLineCount)
{
    RectBounds currentBounds;
    GetBounds(&currentBounds);

    RectBounds viewport;
    InitRectBounds(&viewport, 9, 700 - 13 * visibleLineCount, 816, 720);
    SetBounds(viewport, false);

    InvalidateRect(m_rect);
}

// UID:0002F3 | by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md | Completion:88 | Confidence:92
void ChattingBackPane::UpdateVisibility()
{
    if (g_pChattingHandlePane->m_chatHandleModeIndex &&
        g_pChattingHandlePane->m_secondaryChatEnabled) {
        m_alpha = (g_pChattingHandlePane->m_chatHandleModeIndex == 1)
            ? 0.7f
            : 0.3f;
        SetMode(2);
        SetGrafPortColorState(0x80);
    } else {
        SetMode(1);
        SetGrafPortColorState(0);
    }

    g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);
}

// UID:00001S | by-class/ChattingColorListPane.md | Completion:86 | Confidence:88
class ChattingColorPane;
struct RectBounds;

struct ChattingColorSwatchItem
{
    int row;
    int colorValue;
};

class ChattingColorListPane : public ListPane
{
public:
    ChattingColorListPane(ChattingColorPane *colorPane, bool isForegroundList);
    virtual ~ChattingColorListPane() {}

    void SelectCurrentColor();
    int GetSelectedColorValue();
    int FindIndexByColorValue(int colorValue);
    virtual void DrawItem(
        int row,
        const ChattingColorSwatchItem *item,
        const RectBounds *drawBounds);
    virtual void OnItemSelected(int row, int notify);

private:
    ChattingColorPane *m_pColorPane;
    bool m_isForegroundList;
};

// UID:0002G7 | by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md | Completion:90 | Confidence:93
ChattingColorListPane::ChattingColorListPane(ChattingColorPane *colorPane, bool isForegroundList)
    : ListPane(8, 18, 18, 18, 0, 1, 16),
      m_pColorPane(colorPane),
      m_isForegroundList(isForegroundList)
{
    static const int kChattingColorSwatchValues[80] = {
        15, 128, 131, 133,
        134, 137, 140, 143,
        12, 14, 10, 2,
        11, 9, 13, 5,
        40, 41, 42, 43,
        44, 45, 46, 47,
        222, 220, 218, 216,
        214, 212, 210, 208,
        32, 33, 34, 35,
        36, 37, 38, 39,
        48, 49, 50, 51,
        52, 53, 54, 55,
        161, 163, 165, 167,
        169, 171, 173, 175,
        56, 57, 58, 59,
        60, 61, 62, 63,
        207, 205, 203, 201,
        199, 197, 195, 193,
        104, 105, 106, 107,
        108, 109, 110, 111
    };

    for (int row = 0; row < 80; ++row) {
        int colorValue = kChattingColorSwatchValues[row];
        if (!isForegroundList && row == 0)
            colorValue = 0;

        ChattingColorSwatchItem item = { row, colorValue };
        AddEntry(&item);
    }
}

// UID:0002G8 | by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md | Completion:87 | Confidence:92
void ChattingColorListPane::SelectCurrentColor()
{
    const int category = m_pColorPane->m_selectedChatColorCategory;
    const int colorValue = m_isForegroundList
        ? m_pColorPane->m_chatColorForeground[category]
        : m_pColorPane->m_chatColorBackground[category];

    SetSelectedIndex(FindIndexByColorValue(colorValue), false);
}

// UID:0002G9 | by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md | Completion:88 | Confidence:91
int ChattingColorListPane::GetSelectedColorValue()
{
    ChattingColorSwatchItem *item =
        static_cast<ChattingColorSwatchItem *>(GetSelectedItem());
    return item->colorValue;
}

// UID:0002GA | by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md | Completion:87 | Confidence:92
int ChattingColorListPane::FindIndexByColorValue(int colorValue)
{
    for (int row = 0; row < GetItemCount(); ++row) {
        ChattingColorSwatchItem *item =
            static_cast<ChattingColorSwatchItem *>(GetItem(row));
        if (item->colorValue == colorValue)
            return row;
    }

    return 0;
}

// UID:0002GB | by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md | Completion:91 | Confidence:94
void ChattingColorListPane::DrawItem(
    int row,
    const ChattingColorSwatchItem *item,
    const RectBounds *drawBounds)
{
    RectBounds bounds;

    if (item->colorValue == 0) {
        InitRectBounds(
            &bounds,
            drawBounds->left + 2,
            drawBounds->top + 2,
            drawBounds->right - 2,
            drawBounds->bottom - 2);
        SetMode(1);
        SetDrawColor(136);
        g_pfnFillRect(this, &bounds);
    }

    if (IsItemSelected(row)) {
        InitRectBounds(
            &bounds,
            drawBounds->left,
            drawBounds->top,
            drawBounds->right,
            drawBounds->bottom);
        SetMode(1);
        SetDrawColor(128);
        g_pfnFillRect(this, &bounds);

        InitRectBounds(
            &bounds,
            drawBounds->left + 2,
            drawBounds->top + 2,
            drawBounds->right - 2,
            drawBounds->bottom - 2);
        SetMode(1);
        SetDrawColor(143);
        g_pfnFillRect(this, &bounds);
    }

    InitRectBounds(
        &bounds,
        drawBounds->left + 3,
        drawBounds->top + 3,
        drawBounds->right - 3,
        drawBounds->bottom - 3);
    SetMode(1);
    SetDrawColor(item->colorValue);
    g_pfnFillRect(this, &bounds);
}

// UID:0002GC | by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md | Completion:87 | Confidence:92
void ChattingColorListPane::OnItemSelected(int row, int notify)
{
    ListPane::OnItemSelected(row, notify);

    ChattingColorSwatchItem *item =
        static_cast<ChattingColorSwatchItem *>(GetSelectedItem());
    const int category = m_pColorPane->m_selectedChatColorCategory;

    if (m_isForegroundList)
        m_pColorPane->m_chatColorForeground[category] = item->colorValue;
    else
        m_pColorPane->m_chatColorBackground[category] = item->colorValue;

    if (m_pColorPane->m_pCategorySelector != NULL)
        m_pColorPane->m_pCategorySelector->InvalidateRect(
            m_pColorPane->m_pCategorySelector->m_rect);
}


// UID:0002FX | by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md | Completion:86 | Confidence:91
ChattingColorPane::ChattingColorPane()
    : DialogPane(L"Chatting Color", 330, 397),
      m_pCategorySelector(NULL),
      m_pForegroundColorList(NULL),
      m_pBackgroundColorList(NULL),
      m_selectedChatColorCategory(ChatColorCategory_Talk)
{
    for (int category = 0; category < ChatColorCategory_Count; ++category) {
        const ChatColorPair &colors = g_pConfig->m_chatColorPairs[category];
        m_chatColorForeground[category] = colors.foreground;
        m_chatColorBackground[category] = colors.background;
    }

    RectBounds bounds;

    InitRectBounds(&bounds, 100, 363, 163, 387);
    AddDialogButton(1, 14, bounds);

    InitRectBounds(&bounds, 175, 363, 238, 387);
    AddDialogButton(2, 22, bounds);

    InitRectBounds(&bounds, 77, 57, 327, 107);
    m_pCategorySelector = new ChattingColorSelectPane(this);
    AddChildPane(m_pCategorySelector, bounds);
    m_pCategorySelector->SetSelectedIndex(ChatColorCategory_Talk, false);

    InitRectBounds(&bounds, 20, 134, 325, 229);
    m_pForegroundColorList = new ChattingColorListPane(this, true);
    AddChildPane(m_pForegroundColorList, bounds);
    m_pForegroundColorList->SelectCurrentColor();

    InitRectBounds(&bounds, 20, 253, 325, 348);
    m_pBackgroundColorList = new ChattingColorListPane(this, false);
    AddChildPane(m_pBackgroundColorList, bounds);
    m_pBackgroundColorList->SelectCurrentColor();

    SetDefaultButton(1);
    SetCancelButton(2);
    CenterDialog();
}

// UID:0002FY | by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md | Completion:87 | Confidence:90
ChattingColorPane::~ChattingColorPane()
{
}

// UID:0002FZ | by-memory/0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse.md | Completion:88 | Confidence:91
void ChattingColorPane::OnButtonResponse(int buttonId, int)
{
    if (buttonId == 1) {
        for (int category = 0; category < ChatColorCategory_Count; ++category) {
            ChatColorPair &colors = g_pConfig->m_chatColorPairs[category];
            colors.foreground = static_cast<unsigned char>(m_chatColorForeground[category]);
            colors.background = static_cast<unsigned char>(m_chatColorBackground[category]);
        }

        CloseDialog();
    } else if (buttonId == 2) {
        CloseDialog();
    }
}

// UID:0002G0 | by-memory/0x00482c40-0x00482c54.ChattingColorPaneRefreshCategorySelectorRaw.md | Completion:87 | Confidence:91
void ChattingColorPane::RefreshCategorySelector()
{
    if (m_pCategorySelector != NULL) {
        m_pCategorySelector->InvalidateRect(m_pCategorySelector->m_rect);
    }
}

// UID:0002G1 | by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw.md | Completion:91 | Confidence:93
void ChattingColorPane::SyncColorListsToCategory()
{
    if (m_pCategorySelector == NULL)
        return;

    m_selectedChatColorCategory = m_pCategorySelector->m_selectedIndex;

    if (m_pForegroundColorList == NULL ||
        m_pBackgroundColorList == NULL)
        return;

    m_pForegroundColorList->SelectCurrentColor();
    m_pBackgroundColorList->SelectCurrentColor();
}


// UID:0002G2 | by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md | Completion:87 | Confidence:90
ChattingColorSelectPane::ChattingColorSelectPane(ChattingColorPane *pColorPane)
    : ListPane(4, 60, 60, 20, false, true, 3),
      m_pColorPane(pColorPane)
{
    for (int category = ChatColorCategory_Talk;
         category < ChatColorCategory_Count;
         ++category) {
        int entry = category;
        AddEntry(&entry);
    }
}

// UID:0002G4 | by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md | Completion:86 | Confidence:90
void ChattingColorSelectPane::SelectDefaultCategoryNoNotify()
{
    SetSelectedIndex(ChatColorCategory_Talk, false);
}

// UID:0002G5 | by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md | Completion:88 | Confidence:92
void ChattingColorSelectPane::DrawItem(
    int row,
    const ChattingColorCategoryItem *item,
    const RectBounds *drawBounds)
{
    static const wchar_t *kChatColorCategoryLabels[ChatColorCategory_Count] = {
        L"Talk",
        L"Shout",
        L"Whisper",
        L"Group",
        L"Clan",
        L"System"
    };

    const int category = item->category;
    RectBounds fillBounds;

    if (IsItemSelected(row)) {
        FillPaletteRect(*drawBounds, 128);

        fillBounds = *drawBounds;
        InsetRectBounds(&fillBounds, 2, 2);
        FillPaletteRect(fillBounds, 143);
    } else {
        fillBounds = *drawBounds;
        InsetRectBounds(&fillBounds, 2, 2);
        FillPaletteRect(fillBounds, 136);
    }

    fillBounds = *drawBounds;
    InsetRectBounds(&fillBounds, 3, 3);
    FillPaletteRect(fillBounds, 0);

    SetTextColor(m_pColorPane->m_chatColorForeground[category]);
    SetTextBackColor(m_pColorPane->m_chatColorBackground[category]);
    MoveTo(drawBounds->left + 4, drawBounds->bottom - 3);

    RectBounds labelBounds = *drawBounds;
    labelBounds.left += 6;
    labelBounds.top += 4;
    labelBounds.right -= 6;
    labelBounds.bottom -= 4;

    const wchar_t *label = kChatColorCategoryLabels[category];
    DrawOutlinedText(label, static_cast<int>(wcslen(label)), &labelBounds);
}

// UID:0002G6 | by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md | Completion:88 | Confidence:91
void ChattingColorSelectPane::OnItemSelected(int row, int notify)
{
    ListPane::OnItemSelected(row, notify);
    m_pColorPane->SyncColorListsToCategory();
}

// UID:00001X | by-class/ChattingPane.md | Completion:92 | Confidence:94
class Event;
class List;
class ChattingMessage;
struct PaneKeyEvent;
struct Point;

class ChattingPane : public ScrollablePane
{
public:
    ChattingPane();
    virtual ~ChattingPane();

    void AddChattingMessage(const wchar_t *text,
                            int foregroundColor,
                            int backgroundColor,
                            unsigned char textStyleFlag,
                            int customForegroundRgb,
                            int customBackgroundRgb);
    void AddIncomingMessage(ChattingMessage *message);
    void SetVisibleRowCount(int visibleRows);
    short ComputeLineCount() const;
    void ScrollToBottom();

protected:
    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta,
                                  char axis,
                                  short oldPosition,
                                  short newPosition);
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool HandleServerSayPacket(const unsigned char *packet);

    List *m_pChatMessageList;
    int m_visibleChatPixelHeight;
};

extern ChattingPane *g_pChattingDisplayPane;

bool HandleChatPacketType10(ChattingPane *pane, const unsigned char *packet);

// UID:0002EO | by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md | Completion:92 | Confidence:94
ChattingPane::ChattingPane()
    : ScrollablePane(false, true)
{
    g_pChattingDisplayPane = this;

    ColorStringChattingMessage blankMessage(L" ", 128, 143, 0, 0, 0);

    if (g_useEpfAssets == 1) {
        m_visibleChatPixelHeight = 104;
        m_pChatMessageList = new List(sizeof(ColorStringChattingMessage *), 1000);

        for (int index = 0; index < 50; ++index) {
            ColorStringChattingMessage *message =
                static_cast<ColorStringChattingMessage *>(blankMessage.Clone());
            m_pChatMessageList->Append(1, &message);
        }
    } else {
        m_pChatMessageList = new List(sizeof(ColorStringChattingMessage *), 1000);

        for (int index = 0; index < 5; ++index) {
            ColorStringChattingMessage *message =
                static_cast<ColorStringChattingMessage *>(blankMessage.Clone());
            m_pChatMessageList->Append(1, &message);
        }
    }

    SyncScrollbars();
    SetSkinIndex(1);
}

// UID:0002EP | by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md | Completion:92 | Confidence:94
ChattingPane::~ChattingPane()
{
    const int count = m_pChatMessageList->GetCount();

    for (int index = 0; index < count; ++index) {
        ColorStringChattingMessage *message =
            *static_cast<ColorStringChattingMessage **>(
                m_pChatMessageList->GetElementAt(index));
        delete message;
    }

    delete m_pChatMessageList;
    m_pChatMessageList = NULL;
    g_pChattingDisplayPane = NULL;
}

// UID:0002EQ | by-memory/0x0047f280-0x0047f36f.ChattingPaneAddChattingMessage.md | Completion:90 | Confidence:92
void ChattingPane::AddChattingMessage(
    const wchar_t *text,
    int foregroundColor,
    int backgroundColor,
    unsigned char textStyleFlag,
    int customForegroundRgb,
    int customBackgroundRgb)
{
    if (g_useEpfAssets == 1) {
        ColorStringChattingMessage message(
            text,
            foregroundColor,
            backgroundColor,
            textStyleFlag,
            customForegroundRgb,
            customBackgroundRgb);
        AddIncomingMessage(&message);
    } else {
        ColorStringChattingMessage message(
            text,
            foregroundColor,
            backgroundColor,
            0,
            0,
            0);
        AddIncomingMessage(&message);
    }
}

// UID:0002ER | by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md | Completion:93 | Confidence:94
void ChattingPane::AddIncomingMessage(ChattingMessage *message)
{
    unsigned char modifierState;
    ChattingMessage *clonedMessage;

    if (g_useEpfAssets == 1)
    {
        g_pEventMan->GetModifierState(&modifierState);
        clonedMessage = message->Clone();
        m_pChatMessageList->Append(1, &clonedMessage);

        if (!HasMouseCapture() &&
            (modifierState & kEventModifierShift) == 0)
        {
            SyncScrollbars();
            short scrollPosition = GetScrollPosition(0);
            ApplyScrollPosition(0, scrollPosition, GetScrollMax(0));
        }

        if (m_pChatMessageList->GetCount() > 1000)
        {
            ChattingMessage **oldestMessage =
                static_cast<ChattingMessage **>(
                    m_pChatMessageList->GetElementAt(0));
            delete *oldestMessage;
            m_pChatMessageList->RemoveAt(0, 1);
            SyncScrollbars();
        }
    }
    else
    {
        g_pEventMan->GetModifierState(&modifierState);
        clonedMessage = message->Clone();
        m_pChatMessageList->Append(1, &clonedMessage);
        SyncScrollbars();

        if (!HasMouseCapture() &&
            (modifierState & kEventModifierShift) == 0)
        {
            short scrollPosition = GetScrollPosition(0);
            ApplyScrollPosition(0, scrollPosition, GetScrollMax(0));
        }

        if (m_pChatMessageList->GetCount() > 1000)
        {
            ChattingMessage **oldestMessage =
                static_cast<ChattingMessage **>(
                    m_pChatMessageList->GetElementAt(0));
            delete *oldestMessage;
            m_pChatMessageList->RemoveAt(0, 1);

            short scrollPosition = GetScrollPosition(0);
            if (scrollPosition > 0)
            {
                ApplyScrollPosition(0, scrollPosition, scrollPosition - 1);
            }
            else
            {
                ApplyScrollPosition(0, scrollPosition, 0);
                InvalidateRect(&m_bounds);
            }

            SyncScrollbars();
        }
    }
}

// UID:0004J8 | by-memory/0x0047f520-0x0047f5b7.ChattingPaneGetScrollRange.md | Completion:92 | Confidence:93
short ChattingPane::GetScrollRange(char axis)
{
    if (g_useEpfAssets == 1) {
        if (axis != 0)
            return 0;

        const int visibleLineCount = m_visibleChatPixelHeight / 13;
        if (ComputeLineCount() - visibleLineCount < 0)
            return 0;

        return static_cast<short>(ComputeLineCount() - visibleLineCount);
    }

    if (axis != 0)
        return 0;
    if (ComputeLineCount() - 5 < 0)
        return 0;

    return static_cast<short>(ComputeLineCount() - 5);
}

// UID:0004J9 | by-memory/0x0047f5c0-0x0047f5f8.ChattingPaneGetOverflowCount.md | Completion:92 | Confidence:93
short ChattingPane::GetOverflowCount(char axis)
{
    if (axis != 0)
        return 0;

    const int pixelOffset = m_contentRect.top - m_scrollContentRect.top;
    if (pixelOffset <= 0)
        return 0;

    return static_cast<short>((pixelOffset - 1) / 13 + 1);
}

// UID:0004JA | by-memory/0x0047f600-0x0047f644.ChattingPaneGetPageSize.md | Completion:92 | Confidence:93
short ChattingPane::GetPageSize(char axis)
{
    if (axis != 0)
        return 1;

    if (g_useEpfAssets == 1)
        return static_cast<short>(m_visibleChatPixelHeight / 13 - 1);

    return 7;
}

// UID:0004JB | by-memory/0x0047f650-0x0047f667.ChattingPaneGetScrollOffset.md | Completion:92 | Confidence:93
short ChattingPane::GetScrollOffset(char axis, short units)
{
    if (axis != 0)
        return 0;

    return static_cast<short>(13 * units);
}

// UID:0004JC | by-memory/0x0047f670-0x0047f6ae.ChattingPaneGetContentSize.md | Completion:92 | Confidence:93
Point *ChattingPane::GetContentSize(Point *outSize)
{
    if (g_useEpfAssets == 1) {
        outSize->y = 13 * ComputeLineCount();
        outSize->x = 783;
    } else {
        outSize->y = 13 * ComputeLineCount();
        outSize->x = 420;
    }

    return outSize;
}

// UID:0004JD | by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md | Completion:92 | Confidence:93
Point *ChattingPane::GetScrollDelta(Point *outDelta,
                                        char axis,
                                        short oldPosition,
                                        short newPosition)
{
    outDelta->x = 0;
    if (axis == 0)
        outDelta->y = 13 * (oldPosition - newPosition);
    else
        outDelta->y = 0;

    return outDelta;
}

// UID:0002ET | by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md | Completion:86 | Confidence:90
bool ChattingPane::OnKeyEvent(const PaneKeyEvent *event)
{
    const signed char key = NarrowPaneKey(event->payload[0], event->keyState);

    if (event->type != kPaneEventKey)
        return false;
    if (event->keyState != kKeyStatePressed)
        return false;

    constexpr signed char kChatScrollLineUpKey = static_cast<signed char>(0x81);
    constexpr signed char kChatScrollLineDownKey = static_cast<signed char>(0x83);
    constexpr signed char kChatScrollPageUpKey = static_cast<signed char>(0x93);
    constexpr signed char kChatScrollPageDownKey = static_cast<signed char>(0x94);
    constexpr unsigned char kVerticalAxis = 0;

    switch (key) {
    case kChatScrollLineUpKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short target =
            current > 0 ? static_cast<unsigned short>(current - 1) : 0;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollPageUpKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const int pageRows = GetPageSize(kVerticalAxis);
        const unsigned short target =
            current > pageRows ? static_cast<unsigned short>(current - pageRows) : 0;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollLineDownKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short maximum = GetScrollMax(kVerticalAxis);
        const unsigned short target =
            current < maximum ? static_cast<unsigned short>(current + 1) : maximum;
        ApplyScrollPosition(kVerticalAxis, current, target);
        return true;
    }

    case kChatScrollPageDownKey: {
        const unsigned short current = GetScrollPosition(kVerticalAxis);
        const unsigned short maximum = GetScrollMax(kVerticalAxis);
        const int pageRows = GetPageSize(kVerticalAxis);
        unsigned int target = current + pageRows;
        if (target > maximum)
            target = maximum;
        ApplyScrollPosition(kVerticalAxis, current, static_cast<unsigned short>(target));
        return true;
    }
    }

    return false;
}

// UID:0002EU | by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md | Completion:92 | Confidence:94
bool ChattingPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == 10)
        return HandleChatPacketType10(this, packet);

    if (packet[0] == 13)
        return HandleServerSayPacket(packet);

    return false;
}

// UID:0002EV | by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md | Completion:91 | Confidence:93
void ChattingPane::OnPaint()
{
    if (g_useEpfAssets == 1) {
        Region savedClip;
        Region clippedRegion;
        const unsigned char savedMode = m_mode;

        if (g_pChattingHandlePane->m_secondaryChatEnabled) {
            SetDrawColor(0);
            FillRect(&m_bounds);

            RectBounds clipRect;
            GetClipRect(&clipRect);

            int y = m_scrollContentRect.top;
            const int count = m_pChatMessageList->GetCount();

            for (int index = 0; index < count; ++index) {
                ColorStringChattingMessage *message =
                    *static_cast<ColorStringChattingMessage **>(
                        m_pChatMessageList->GetElementAt(index));

                RectBounds messageRect;
                messageRect.left = 0;
                messageRect.right = 783;

                const short lineCount =
                    static_cast<short>(message->MeasureLines(this, 783));
                messageRect.top = y;
                y += 13 * lineCount;
                messageRect.bottom = y;

                SetMode(savedMode);

                if (IntersectRects(&messageRect, &clipRect, NULL)) {
                    GetClipRegion(&savedClip);

                    if (savedClip.IsEmpty()) {
                        SetClipRect(&messageRect);
                        message->Draw(this, &messageRect);
                        SetClipRegion(&savedClip);
                    } else if (clippedRegion.IntersectWithRect(&messageRect)) {
                        SetClipRegion(&clippedRegion);
                        message->Draw(this, &messageRect);
                        SetClipRegion(&savedClip);
                    }
                }
            }
        } else {
            SetDrawColor(0);
            FillRect(&m_bounds);
        }
    } else {
        Region savedClip;
        Region clippedRegion;

        SetDrawColor(143);
        FillRect(&m_contentRect);

        RectBounds clipRect;
        GetClipRect(&clipRect);

        int y = m_scrollContentRect.top;
        const int count = m_pChatMessageList->GetCount();

        for (int index = 0; index < count; ++index) {
            ColorStringChattingMessage *message =
                *static_cast<ColorStringChattingMessage **>(
                    m_pChatMessageList->GetElementAt(index));

            RectBounds messageRect;
            messageRect.left = 0;
            messageRect.right = 408;

            const short lineCount =
                static_cast<short>(message->MeasureLines(this, 408));
            messageRect.top = y;
            y += 13 * lineCount;
            messageRect.bottom = y;

            if (IntersectRects(&messageRect, &clipRect, NULL)) {
                GetClipRegion(&savedClip);

                if (savedClip.IsEmpty()) {
                    SetClipRect(&messageRect);
                    message->Draw(this, &messageRect);
                    SetClipRegion(&savedClip);
                } else if (clippedRegion.IntersectWithRect(&messageRect)) {
                    SetClipRegion(&clippedRegion);
                    message->Draw(this, &messageRect);
                    SetClipRegion(&savedClip);
                }
            }
        }
    }
}

// UID:0002EW | by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md | Completion:92 | Confidence:94
void ChattingPane::SetVisibleRowCount(int visibleRows)
{
    RectBounds currentBounds;
    GetBounds(&currentBounds);

    m_visibleChatPixelHeight = 13 * visibleRows;

    RectBounds viewport;
    InitRectBounds(&viewport, 23, 710 - m_visibleChatPixelHeight, 806, 710);
    SetBounds(&viewport, false);

    SyncScrollbars();

    const unsigned short currentPosition = GetScrollPosition(0);
    const unsigned short maximumPosition = GetScrollMax(0);
    ApplyScrollPosition(0, currentPosition, maximumPosition);

    InvalidateRect(&m_bounds);
}

// UID:0002EX | by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md | Completion:90 | Confidence:92
short ChattingPane::ComputeLineCount() const
{
    const int width = (g_useEpfAssets == 1) ? 783 : 408;
    short totalLines = 0;

    const int count = m_pChatMessageList->GetCount();
    for (int index = 0; index < count; ++index) {
        ColorStringChattingMessage *message =
            static_cast<ColorStringChattingMessage *>(m_pChatMessageList->GetAt(index));
        if (message != NULL) {
            totalLines = static_cast<short>(
                totalLines + message->MeasureLines(const_cast<ChattingPane *>(this), width));
        }
    }

    return totalLines;
}

// UID:0002EY | by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md | Completion:87 | Confidence:90
void ChattingPane::ScrollToBottom()
{
    constexpr unsigned char kVerticalAxis = 0;

    const unsigned short currentPosition = GetScrollPosition(kVerticalAxis);
    const unsigned short maximumPosition = GetScrollMax(kVerticalAxis);
    ApplyScrollPosition(kVerticalAxis, currentPosition, maximumPosition);
}

// UID:0002EZ | by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md | Completion:92 | Confidence:92
bool ChattingPane::HandleServerSayPacket(const unsigned char *packet)
{
    enum ServerSaySubtype
    {
        kServerSayNormal = 0,
        kServerSayShout = 1,
        kServerSayBalloonOnly = 2,
        kServerSayUnfiltered = 3,
        kServerSayCustomColor = 4
    };

    wchar_t text[256];

    if (g_useEpfAssets == 1) {
        GetMemoryMan();

        const unsigned char subtype = packet[1];
        const unsigned char textLength = packet[6];
        const int convertedLength = MultiByteToWideChar(
            0,
            0,
            reinterpret_cast<const char *>(packet + 7),
            textLength,
            text,
            256);
        text[static_cast<unsigned char>(convertedLength)] = L'\0';

        unsigned int foreground;
        unsigned int background;
        if (subtype == kServerSayCustomColor) {
            const unsigned short foregroundOffset =
                static_cast<unsigned short>(textLength + 7);
            const unsigned short backgroundOffset =
                static_cast<unsigned short>(textLength + 11);
            foreground = PacketBufferReadUInt32BE(packet + foregroundOffset);
            background = PacketBufferReadUInt32BE(packet + backgroundOffset);
        }

        UserPane *activeUserPane = g_activeMapPane->m_userPane;

        switch (subtype) {
        case kServerSayNormal:
            if (activeUserPane->m_sayDisplayLevel != 0)
                return false;
            AddChattingMessage(text, 143, 128, 0, 0, 0);
            return false;

        case kServerSayShout:
            if (activeUserPane->m_sayDisplayLevel == 2)
                return false;
            AddChattingMessage(text, 14, 128, 0, 0, 0);
            return false;

        case kServerSayUnfiltered:
            AddChattingMessage(text, 143, 128, 0, 0, 0);
            return false;

        case kServerSayCustomColor:
            AddChattingMessage(text, 253, 254, 0, foreground, background);
            return false;
        }

        return false;
    }

    GetMemoryMan();

    const unsigned char subtype = packet[1];
    const unsigned char textLength = packet[6];
    const int convertedLength = MultiByteToWideChar(
        0,
        0,
        reinterpret_cast<const char *>(packet + 7),
        textLength,
        text,
        256);
    text[static_cast<unsigned char>(convertedLength)] = L'\0';

    UserPane *activeUserPane = g_activeMapPane->m_userPane;

    switch (subtype) {
    case kServerSayNormal:
        if (activeUserPane->m_sayDisplayLevel != 0)
            return false;
        AddChattingMessage(text, 128, 143, 0, 0, 0);
        return false;

    case kServerSayShout:
        if (activeUserPane->m_sayDisplayLevel == 2)
            return false;
        AddChattingMessage(text, 12, 143, 0, 0, 0);
        return false;

    case kServerSayUnfiltered:
        AddChattingMessage(text, 128, 143, 0, 0, 0);
        return false;
    }

    return false;
}

// UID:00001Y | by-class/ChattingVarietyPane.md | Completion:90 | Confidence:93
class ChattingVarietySelectPane;
class Event;

class ChattingVarietyPane : public Pane
{
public:
    ChattingVarietyPane();
    virtual ~ChattingVarietyPane();
    void Refresh();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual void OnPaint();

private:
    void GetItemRect(int itemIndex, RectBounds *outRect);
    signed char HitTest(int mouseY, int mouseX);

    unsigned char m_compactButtonState;
    ChattingVarietySelectPane *m_selectPane;
};

extern ChattingVarietyPane *g_pChattingVarietyPane;

// UID:0002FA | by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md | Completion:90 | Confidence:93
ChattingVarietyPane::ChattingVarietyPane()
    : Pane(1)
{
    g_pChattingVarietyPane = this;
    m_compactButtonState = 0;
}

// UID:0002FB | by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md | Completion:88 | Confidence:90
ChattingVarietyPane::~ChattingVarietyPane()
{
    g_pChattingVarietyPane = NULL;
}

// UID:0002FC | by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md | Completion:92 | Confidence:94
bool ChattingVarietyPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->m_inputLocked)
        return false;

    if (event->m_type != kEventLeftButtonDown)
        return false;

    if (HitTest(event->m_payload.m_pointer.m_y,
                event->m_payload.m_pointer.m_x) != 0)
        return false;

    if (g_pChattingVarietySelectPane == NULL) {
        m_selectPane = new ChattingVarietySelectPane();

        RectBounds popupBounds;
        InitRectBounds(&popupBounds, 7, 617, 74, 727);
        m_selectPane->AddToLayer(
            &popupBounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        m_selectPane->SetPaneOrder(0, NULL);
    } else {
        m_selectPane->MarkForDeletion();
    }

    InvalidateRect(&m_bounds);
    return true;
}

// UID:0002FD | by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md | Completion:94 | Confidence:94
void ChattingVarietyPane::OnPaint()
{
    EPFTileContext tileContext;

    SetTextBackFillColor(0);

    g_pEPFLib->LookupLayoutEntry(
        L"CHATVAR.EPF",
        g_pChattingVarietySelectPane != NULL,
        &tileContext);

    RenderTileFrame(
        &tileContext,
        &tileContext.bounds,
        &m_visibleBounds,
        0,
        L"CHATVAR.PAL",
        NULL);

    wchar_t modeText[128];

    switch (g_pUserPane->m_currentSayMode) {
    case kSayInputModeDefault:
        wcscpy_s(modeText, _countof(modeText), L"Talk");
        break;

    case kSayInputModeShout:
        wcscpy_s(modeText, _countof(modeText), L"Shout");
        break;

    case kSayInputModeWhisper:
        wcscpy_s(modeText, _countof(modeText), L"Whisper");
        break;

    case kSayInputModeGroup:
        wcscpy_s(modeText, _countof(modeText), L"Group");
        break;

    case kSayInputModeClan:
        wcscpy_s(modeText, _countof(modeText), L"Clan");
        break;
    }

    const int textLength = static_cast<int>(wcslen(modeText));
    SetTextColor(128);

    const int textX =
        (m_visibleBounds.left + m_visibleBounds.right) / 2
        - (6 * textLength) / 2 - 2;
    const int textY = m_visibleBounds.bottom - 6;

    MoveTo(textX + 1, textY);
    DrawWideText(modeText, textLength);
    MoveTo(textX, textY);
    DrawWideText(modeText, textLength);
}

// UID:0002FF | by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md | Completion:90 | Confidence:93
void ChattingVarietyPane::GetItemRect(int itemIndex, RectBounds *outRect)
{
    if (itemIndex == 0)
        InitRectBounds(outRect, 0, 0, 62, 24);
    else
        InitRectBounds(outRect, -1, -1, -1, -1);
}

// UID:0002FG | by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md | Completion:90 | Confidence:93
signed char ChattingVarietyPane::HitTest(int mouseY, int mouseX)
{
    for (signed char itemIndex = 0; itemIndex < 1; ++itemIndex) {
        RectBounds itemRect;
        GetItemRect(itemIndex, &itemRect);

        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}


// UID:0002GD | by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md | Completion:90 | Confidence:92
ColorStringChattingMessage::ColorStringChattingMessage(
    const wchar_t *text,
    int foregroundColor,
    int backgroundColor,
    unsigned char textStyleFlag,
    int customForegroundRgb,
    int customBackgroundRgb)
{
    MemoryMan *memoryMan = GetMemoryMan();

    size_t byteCount = 0;
    const wchar_t *scan = text;
    do {
        byteCount += sizeof(wchar_t);
    } while (*scan++ != L'\0');

    m_text = static_cast<wchar_t *>(memoryMan->AllocateBufferMemory(byteCount));
    memoryMan->MemmoveWrapper(m_text, text, byteCount);
    m_foregroundColor = foregroundColor;
    m_backgroundColor = backgroundColor;
    m_textStyleFlag = textStyleFlag;
    m_customForegroundRgb = customForegroundRgb;
    m_customBackgroundRgb = customBackgroundRgb;
}

// UID:0002GE | by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md | Completion:86 | Confidence:90
ColorStringChattingMessage::~ColorStringChattingMessage()
{
    if (m_text != NULL)
        m_text = static_cast<wchar_t *>(GetMemoryMan()->FreeBufferMemory(m_text));
}

// UID:0002GF | by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md | Completion:88 | Confidence:92
ChattingMessage *ColorStringChattingMessage::Clone()
{
    return new ColorStringChattingMessage(
        m_text,
        m_foregroundColor,
        m_backgroundColor,
        m_textStyleFlag,
        m_customForegroundRgb,
        m_customBackgroundRgb);
}

// UID:0002GG | by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md | Completion:86 | Confidence:90
int ColorStringChattingMessage::MeasureLines(void *drawContext, int width)
{
    const wchar_t *text = m_text;
    int textLength = 0;
    while (text[textLength] != L'\0')
        ++textLength;

    int lineCount = GetSingleLineCount(drawContext, text, textLength, width);
    if ((short)lineCount < 1)
        return 1;

    text = m_text;
    textLength = 0;
    while (text[textLength] != L'\0')
        ++textLength;

    return static_cast<unsigned short>(
        GetSingleLineCount(drawContext, text, textLength, width));
}

// UID:0002GH | by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md | Completion:94 | Confidence:96
void ColorStringChattingMessage::Draw(GrafPort *grafPort, RectBounds *bounds)
{
    if (g_useEpfAssets == true) {
        EPFTileContext unusedContext;

        grafPort->SetTextDrawMode(1);
        grafPort->SetTextColor(m_foregroundColor);

        if (m_textStyleFlag != 0) {
            grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
            bounds->Offset(1, 0);
            grafPort->SetTextDrawMode(1);
            grafPort->SetTextColor(m_foregroundColor);
            grafPort->SetTextBackColor(0);
            grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
            return;
        }

        grafPort->SetTextBackColor(m_backgroundColor);
        if (m_customForegroundRgb != 0 || m_customBackgroundRgb != 0) {
            DLPalette *textPalette = g_pPaletteLib->GetTextPalette();
            const unsigned short savedForeground = textPalette->MapColor(m_foregroundColor);
            const unsigned short savedBackground = textPalette->MapColor(m_backgroundColor);

            textPalette->SetColor(
                m_foregroundColor,
                static_cast<unsigned char>(m_customForegroundRgb >> 16),
                static_cast<unsigned char>(m_customForegroundRgb >> 8),
                static_cast<unsigned char>(m_customForegroundRgb));
            textPalette->SetColor(
                m_backgroundColor,
                static_cast<unsigned char>(m_customBackgroundRgb >> 16),
                static_cast<unsigned char>(m_customBackgroundRgb >> 8),
                static_cast<unsigned char>(m_customBackgroundRgb));

            DLPalette *savedPalette = grafPort->GetPalette();
            grafPort->SetPalette(textPalette);
            grafPort->DrawOutlinedText(m_text, static_cast<int>(wcslen(m_text)), bounds);
            textPalette->SetPackedColor(m_foregroundColor, savedForeground);
            textPalette->SetPackedColor(m_backgroundColor, savedBackground);
            grafPort->SetPalette(savedPalette);
            return;
        }

        grafPort->DrawOutlinedText(m_text, static_cast<int>(wcslen(m_text)), bounds);
        return;
    }

    EPFTileContext background;

    int frameIndex;
    switch (m_backgroundColor) {
    case 143:
        frameIndex = 0;
        break;
    case 12:
        frameIndex = 1;
        break;
    case 1:
        frameIndex = 2;
        break;
    default:
        return;
    }

    g_pEPFLib->LookupLayoutEntry(L"CHATBACK.EPD", frameIndex, &background);
    grafPort->SetDrawMode(0);
    grafPort->DrawTiledBackground(
        bounds,
        reinterpret_cast<const FrameDrawRecord *>(&background),
        L"NP");
    grafPort->SetTextDrawMode(1);
    grafPort->SetTextColor(m_foregroundColor);
    grafPort->DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), bounds);
}

// UID:0000SX | by-global/GetChatButtonAtPoint.md | Completion:88 | Confidence:92
// Emitted code for GetChatButtonAtPoint is covered by [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md).
// UID:000107 | by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md | Completion:89 | Confidence:92
static signed char GetChatButtonAtPoint(int mouseY, int mouseX)
{
    signed char buttonIndex = 0;
    RectBounds buttonRect;

    while (buttonIndex < 4) {
        switch (buttonIndex) {
        case 0:
            InitRectBounds(&buttonRect, 0, 4, 19, 21);
            break;
        case 1:
            InitRectBounds(&buttonRect, 21, 0, 624, 24);
            break;
        case 2:
            InitRectBounds(&buttonRect, 630, 4, 649, 21);
            break;
        case 3:
            InitRectBounds(&buttonRect, 649, 4, 668, 21);
            break;
        default:
            InitRectBounds(&buttonRect, -1, -1, -1, -1);
            break;
        }

        if (PointInRect(mouseY, mouseX, &buttonRect))
            return buttonIndex;

        ++buttonIndex;
    }

    return -1;
}

// UID:000308 | by-global/g_pChatInputPane.md | Completion:87 | Confidence:90
class ChatInputPane;

ChatInputPane *g_pChatInputPane = NULL;

// UID:0002WZ | by-global/g_pChattingBackPane.md | Completion:87 | Confidence:90
class ChattingBackPane;

ChattingBackPane *g_pChattingBackPane = NULL;

// UID:0002WX | by-global/g_pChattingDisplayPane.md | Completion:92 | Confidence:94
class ChattingPane;

ChattingPane *g_pChattingDisplayPane = NULL;

// UID:0002WY | by-memory/0x0067adcc-0x0067add0.g_pChattingDisplayPane.md | Completion:92 | Confidence:94
// Exact storage for g_pChattingDisplayPane at 0x0067adcc.
// The source definition is emitted by [UID:0002WX][g_pChattingDisplayPane](by-global/g_pChattingDisplayPane.md);
// do not duplicate the pointer definition from this storage child.

// UID:000104 | by-memory/0x0047efb0-0x00483ef7.ChattingUI.md | Completion:88 | Confidence:93
// No standalone ChattingUI aggregate emission; exact chat UI source is split across the child class, method, helper, global, and data pages under [UID:0000I5][Chatting](by-file/Chatting.md).

// UID:0002F0 | by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md | Completion:87 | Confidence:90
enum ChatPacketType10Subtype
{
    ChatType10_Whisper = 0,
    ChatType10_Shout = 4,
    ChatType10_System = 5,
    ChatType10_Group = 11,
    ChatType10_Clan = 12,
    ChatType10_SystemNotice = 17,
    ChatType10_CustomColor = 18
};

static bool DecodeType10Text(const unsigned char *payload,
                             wchar_t *outText,
                             int outTextCount)
{
    const unsigned int byteCount = ReadPacketUInt16BE(payload);
    if (byteCount >= 0x8000)
        return false;

    char ansiText[0x8001];
    CopyPacketBytes(ansiText, payload + 2, byteCount);
    ansiText[byteCount] = '\0';

    const int wideCount = MultiByteToWideChar(CP_ACP, 0, ansiText, -1,
                                              outText, outTextCount);
    return wideCount > 0 && wideCount < outTextCount;
}

static const ChatColorPair &GetType10CurrentColor(unsigned char subtype)
{
    switch (subtype) {
    case ChatType10_Shout:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_Shout];
    case ChatType10_Whisper:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_Whisper];
    case ChatType10_Group:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_Group];
    case ChatType10_Clan:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_Clan];
    case ChatType10_System:
    case ChatType10_SystemNotice:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_System];
    default:
        return g_pConfig->m_chatColorPairs[ChatColorCategory_Talk];
    }
}

static bool RewriteType10SocialText(unsigned char subtype,
                                    const wchar_t *sourceText,
                                    wchar_t *displayText,
                                    int displayTextCount)
{
    const wchar_t marker =
        (subtype == ChatType10_Whisper) ? L'"' :
        (subtype == ChatType10_Group) ? L']' :
        (subtype == ChatType10_Clan) ? L'>' : L'\0';

    if (marker == L'\0')
        return false;

    return FormatChatSocialMessage(sourceText, marker, displayText, displayTextCount);
}

bool HandleChatPacketType10(ChattingPane *pane, const unsigned char *packet)
{
    const unsigned char subtype = packet[1];
    wchar_t text[0x8001];
    wchar_t displayText[0x8001];

    if (g_useEpfAssets == 1) {
        if (subtype == ChatType10_CustomColor) {
            const int customForeground = ReadPacketUInt32BE(packet + 2);
            const int customBackground = ReadPacketUInt32BE(packet + 6);
            if (DecodeType10Text(packet + 10, text, _countof(text)))
                pane->AddChattingMessage(text, 253, 254, 0,
                                         customForeground, customBackground);
            return false;
        }

        if (subtype != ChatType10_Whisper &&
            subtype != ChatType10_Shout &&
            subtype != ChatType10_System &&
            subtype != ChatType10_Group &&
            subtype != ChatType10_Clan &&
            subtype != ChatType10_SystemNotice) {
            return false;
        }

        if (!DecodeType10Text(packet + 2, text, _countof(text)))
            return false;

        const ChatColorPair &colors = GetType10CurrentColor(subtype);
        const wchar_t *messageText = text;
        if (RewriteType10SocialText(subtype, text, displayText, _countof(displayText)))
            messageText = displayText;

        pane->AddChattingMessage(messageText, colors.foreground, colors.background,
                                 0, 0, 0);
        return false;
    }

    if (subtype != ChatType10_Whisper &&
        subtype != ChatType10_Shout &&
        subtype != ChatType10_System &&
        subtype != ChatType10_Group &&
        subtype != ChatType10_Clan &&
        subtype != ChatType10_SystemNotice) {
        return false;
    }

    if (!DecodeType10Text(packet + 2, text, _countof(text)))
        return false;

    int foreground = 1;
    int background = 143;
    switch (subtype) {
    case ChatType10_Shout:
        foreground = 143;
        background = 1;
        break;
    case ChatType10_System:
        foreground = 143;
        background = 12;
        break;
    case ChatType10_Clan:
        foreground = 250;
        background = 143;
        break;
    case ChatType10_SystemNotice:
        foreground = 143;
        background = 5;
        break;
    default:
        break;
    }

    const wchar_t *messageText = text;
    if (RewriteType10SocialText(subtype, text, displayText, _countof(displayText)))
        messageText = displayText;

    pane->AddChattingMessage(messageText, foreground, background, 0, 0, 0);
    return false;
}

// UID:0002FW | by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md | Completion:89 | Confidence:92
static void __stdcall GetChatButtonRect(int buttonIndex, RectBounds *outRect)
{
    switch (buttonIndex) {
    case 0:
        InitRectBounds(outRect, 0, 4, 19, 21);
        return;
    case 1:
        InitRectBounds(outRect, 21, 0, 624, 24);
        return;
    case 2:
        InitRectBounds(outRect, 630, 4, 649, 21);
        return;
    case 3:
        InitRectBounds(outRect, 649, 4, 668, 21);
        return;
    case -1:
    default:
        InitRectBounds(outRect, -1, -1, -1, -1);
        return;
    }
}


// UID:0003AV | by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md | Completion:89 | Confidence:92
// Chatting color table vector constants for [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md) are source-declared/generated-binary support for kChattingColorSwatchValues[80]; do not emit this .rdata seed block as a separate C++ object.

// UID:0003JP | by-memory\0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:00001R | by-class\ChattingBackPane.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:00001T | by-class\ChattingColorPane.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:00001U | by-class\ChattingColorSelectPane.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:00002Z | by-class\ColorStringChattingMessage.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0003AT | by-memory\0x00614cdc-0x00615284.ChattingVtableData.md | Completion:90 | Confidence:94 | Empty Emitter Marker
