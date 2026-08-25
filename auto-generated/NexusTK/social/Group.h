// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JS
// Source by-file doc: by-file/Group.md
// UID:000090 | by-class/NewGroupPane.md | Completion:94 | Confidence:95
#include "../ui/core/PanelPane.h"

class Event;
class Layer;
class ScrollNewGroupPane;

class NewGroupPane : public PanelPane
{
public:
    NewGroupPane();
    virtual ~NewGroupPane();
    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *previousBounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

private:
    void UpdateScrollRange();
    void SetScrollPosition(unsigned char orientation,
                           short oldPosition, short newPosition);
    bool ParseGroupListPacket(const unsigned char *packetData);
    bool UpdateGroupMemberStatus(const unsigned char *packetData);
    void DrawNumberString(const wchar_t *text, int left, int top,
                          unsigned char colorVariant);
    void ToggleExpandedMode();

    unsigned char m_unusedState[4];
    signed char m_firstVisibleMember;
    signed char m_groupMemberCount;
    ScrollNewGroupPane *m_scrollPane;
    char *m_numericGlyphs;
    int m_toggleButtonState;
    bool m_expanded;

    [[No Children Attached]]
};
