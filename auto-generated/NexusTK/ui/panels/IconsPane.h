// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JZ
// Source by-file doc: by-file/IconsPane.md
// UID:00006B | by-class/IconsPane.md | Completion:92 | Confidence:94
class PaneMouseEvent;

class IconsPane : public Pane, public Singleton<IconsPane>
{
public:
    IconsPane();
    virtual ~IconsPane();

    bool IsShowingAllIcons() const;
    void ShowAllIcons();
    void ShowReducedIcons();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    int HitTestIcon(int y, int x);
    void SetIconHighlight(bool isPressed);

    bool m_showAllIcons;
    int m_selectedIconIndex;
    bool m_isPressed;
};

extern IconsPane *g_pIconsPane;
