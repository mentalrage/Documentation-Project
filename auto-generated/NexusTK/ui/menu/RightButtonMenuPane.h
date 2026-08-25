// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N7
// Source by-file doc: by-file/RightButtonMenuPane.md
// UID:0000C0 | by-class/RightButtonMenuPane.md | Completion:90 | Confidence:94
struct PaneEvent;

class RightButtonMenuPane : public Pane, public Singleton<RightButtonMenuPane>
{
public:
    RightButtonMenuPane();
    virtual ~RightButtonMenuPane();

    void CloseRightClickAndVoteMenus();
    void SetTargetNameAndId(int targetId, const wchar_t *targetName);

protected:
    virtual bool OnEvent(const PaneEvent *event);
    virtual int OnCancel();
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kLookMenuItem = 0,
        kTradeMenuItem = 1,
        kWhisperMenuItem = 2,
        kGroupMenuItem = 3,
        kInfoMenuItem = 4,
        kNoMenuItem = -1
    };

    bool m_menuItemPressed;
    signed char m_highlightedMenuItem;
    int m_targetId;
    wchar_t m_targetName[0x21];
};

extern RightButtonMenuPane *g_pRightButtonMenuPane;
