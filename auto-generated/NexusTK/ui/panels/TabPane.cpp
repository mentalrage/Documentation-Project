// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OF
// Source by-file doc: by-file/TabPane.md
// UID:0000EB | by-class/TabPane.md | Completion:93 | Confidence:94
class Event;
struct RectBounds;

class TabPane : public Pane, public Singleton<TabPane>
{
public:
    TabPane();
    virtual ~TabPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();

private:
    void BuildTabActionRect(int actionCode, RectBounds *outRect) const;
    signed char ResolveTabActionCode(int mouseY, int mouseX) const;
};

extern TabPane *g_pTabPane;

// UID:00034L | by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md | Completion:88 | Confidence:90
TabPane::TabPane()
    : Pane(1)
{
    g_pTabPane = this;
}

// UID:00034M | by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md | Completion:88 | Confidence:91
TabPane::~TabPane()
{
    g_pTabPane = NULL;
}

// UID:00034N | by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md | Completion:92 | Confidence:94
void TabPane::OnPaint()
{
}

// UID:00034O | by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool TabPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->m_tabActionInputLocked) {
        return false;
    }

    if (event->m_type != kEventLeftButtonDown &&
        event->m_type != kEventLeftButtonDoubleClick) {
        return false;
    }

    const signed char actionCode = ResolveTabActionCode(
        event->m_payload.m_pointer.m_y,
        event->m_payload.m_pointer.m_x);
    if (actionCode < 0) {
        return false;
    }

    if (event->m_type == kEventLeftButtonDoubleClick &&
        actionCode != 0 && actionCode != 1 &&
        actionCode != 2 && actionCode != 5) {
        return false;
    }

    switch (actionCode) {
    case 0:
        RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime);
        return true;

    case 1:
        SwitchGeneralPurposePanelMode2WithClickSound();
        return true;

    case 2:
        SwitchGeneralPurposePanelMode3WithClickSound();
        return true;

    case 3:
        SwitchGeneralPurposePanelMode4WithClickSound();
        return true;

    case 4:
        g_pUserPane->HandleCollectionTabAction();
        return true;

    case 5:
        SwitchGeneralPurposePanelMode6WithClickSound();
        return true;
    }

    return false;
}

// UID:00034P | by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md | Completion:91 | Confidence:94
bool TabPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}

// UID:00034Q | by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md | Completion:87 | Confidence:89
void TabPane::BuildTabActionRect(int actionCode, RectBounds *outRect) const
{
    switch (actionCode) {
    case 0:
        InitRectBounds(outRect, 2, 1, 20, 46);
        break;
    case 1:
        InitRectBounds(outRect, 2, 47, 20, 93);
        break;
    case 2:
        InitRectBounds(outRect, 2, 95, 20, 140);
        break;
    case 3:
        InitRectBounds(outRect, 2, 142, 20, 187);
        break;
    case 4:
        InitRectBounds(outRect, 2, 189, 20, 234);
        break;
    case 5:
        InitRectBounds(outRect, 2, 236, 20, 281);
        break;
    default:
        InitRectBounds(outRect, -1, -1, -1, -1);
        break;
    }
}

// UID:00034R | by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md | Completion:90 | Confidence:93
signed char TabPane::ResolveTabActionCode(int mouseY, int mouseX) const
{
    for (signed char actionCode = 0; actionCode < 6; ++actionCode) {
        RectBounds rect;
        BuildTabActionRect(actionCode, &rect);

        if (PointInRect(mouseY, mouseX, &rect)) {
            return actionCode;
        }
    }

    return -1;
}

// UID:00034W | by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md | Completion:92 | Confidence:94
// Compiler-generated scalar deleting destructor for TabPane; source is TabPane::~TabPane().

// UID:0000SE | by-global/g_pTabPane.md | Completion:90 | Confidence:92
// Emitted definition for this global storage is covered by [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md).

// UID:00029C | by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md | Completion:92 | Confidence:93
TabPane *g_pTabPane;
