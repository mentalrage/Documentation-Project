// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NE
// Source by-file doc: by-file/ScrollableControlPane.md
// UID:0000CE | by-class/ScrollableControlPane.md | Completion:92 | Confidence:94
class Event;
class Layer;
class Pane;
class ScrollablePane;
struct RectBounds;

class ScrollableControlPane : public ControlPane
{
public:
    ScrollableControlPane(const RectBounds *bounds,
                          ScrollablePane *scrollablePane,
                          int horizontalScrollBarOffset,
                          int verticalScrollBarOffset,
                          int scrollBarInset);
    virtual ~ScrollableControlPane();

    ScrollablePane *GetScrollablePane() const
    {
        return m_scrollablePane;
    }

    void SetScrollTargetValue(short targetValue, char axis);
    void SetScrollCurrentValue(short currentValue, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void Enable();
    virtual void Disable();
    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    ScrollablePane *m_scrollablePane;
};
