// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LY
// Source by-file doc: by-file/NewUserShapeSelectControlPane.md
// UID:00009G | by-class/NewUserShapeSelectControlPane.md | Completion:93 | Confidence:94
#include "../render/NewHumanImageLib.h"
#include "../ui/core/ControlPane.h"

struct MouseEvent;
struct RectBounds;

class NewUserShapeSelectControlPane : public ControlPane
{
public:
    NewUserShapeSelectControlPane(short initialSelectedSlot,
                                  bool useMaleShapeBank,
                                  const RectBounds *bounds,
                                  unsigned char controlFlags);
    virtual ~NewUserShapeSelectControlPane() {}

    virtual bool OnTimerEvent(int timerId, int, int);
    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *outParams,
        unsigned char shapeIndex) const;
    void AdvanceDirection();
    short StepShapeForward();
    short StepShapeBackward();
    short SelectNextPage();
    short SelectPreviousPage();
    bool IsSelected() const;
    void SetSelected(bool selected);

    void SetMaleMode()
    {
        m_bodyMode = 2;
        InvalidateBounds();
    }

    void SetFemaleMode()
    {
        m_bodyMode = 6;
        InvalidateBounds();
    }

    short SelectedShapeSlot() const { return m_selectedShapeSlot; }
    short ShapePage() const { return m_shapePage; }

private:
    int SelectShapeAtPoint(int localY, int localX);

    unsigned short m_reservedShapeState;
    unsigned short m_maxShapeIndex;
    unsigned short m_bodyMode;
    unsigned short m_animationFrame;
    unsigned char m_direction;
    unsigned char m_padding111;
    unsigned short m_animationTick;
    unsigned char m_reservedDrawState;
    unsigned char m_padding115;
    short m_selectedShapeSlot;
    short m_shapePage;
    bool m_mouseTracking;
    unsigned char m_padding11b;

};
