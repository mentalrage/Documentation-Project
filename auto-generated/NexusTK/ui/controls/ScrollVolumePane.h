// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NK
// Source by-file doc: by-file/ScrollVolumePane.md
// UID:0000CO | by-class/ScrollVolumePane.md | Completion:93 | Confidence:94
class Event;

enum ScrollVolumePart {
    kScrollVolumePartLeading = 0,
    kScrollVolumePartPageBeforeThumb = 1,
    kScrollVolumePartThumb = 2,
    kScrollVolumePartPageAfterThumb = 3,
    kScrollVolumePartTrailing = 4,
    kScrollVolumePartNone = -1
};

class ScrollVolumePane : public Pane
{
public:
    explicit ScrollVolumePane(unsigned char volumeType);
    void SetTrackStateWord(unsigned short state);
    void SetScrollStyle(unsigned char style);
    void SetRange(short range);
    void SetValue(short value);
    void Enable();
    void Disable();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    enum { kThumbSpan = 38 };
    bool CanAdjust() const;
    ScrollVolumePart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollVolumePart part, RectBounds *rect);
    void SetHoverPart(ScrollVolumePart part);
    void BeginInteraction(ScrollVolumePart part, int localY, int localX);
    void CommitInteraction();
    void NotifyValueChange(int localY, int localX);
    void ResetInteractionState();

    unsigned short m_trackStateWord;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_volumeType;
    short m_value;
    short m_range;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollVolumePaneSizeMustBe272[
    sizeof(ScrollVolumePane) == 0x110 ? 1 : -1];
