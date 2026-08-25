// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OX
// Source by-file doc: by-file/UserCreateAppearanceControls.md
// UID:0000FR | by-class/UserShapeSelectControlPane.md | Completion:92 | Confidence:93
#pragma once

#include "../ui/controls/ListPane.h"
#include "../ui/core/ControlPane.h"
#include "../ui/core/RectBounds.h"

class CreateUserDialogPane;
struct HumanImageRenderParams;
struct MouseEvent;
struct UserCreateColorSwatchItem;

class UserShapeSelectControlPane : public ControlPane
{
public:
    UserShapeSelectControlPane(short initialShapeIndex,
                               bool useMaleShapeBank,
                               const RectBounds *bounds,
                               unsigned char controlFlags);
    virtual ~UserShapeSelectControlPane() {}

    virtual bool OnTimerEvent(int timerId, int, int);
    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *outParams) const;
    void SetMaleShapeBank();
    void SetFemaleShapeBank();
    short StepShapeForward();
    short StepShapeBackward();
    bool IsSelected() const;
    void SetSelected(bool selected);

private:
    unsigned short m_reservedShapeState;
    unsigned short m_shapeIndexLimit;
    short m_selectedShapeIndex;
    unsigned short m_shapeBank;
    unsigned short m_animationFrame;
    unsigned short m_direction;
    unsigned short m_animationTick;
    bool m_selected;
    unsigned short m_shapeSpriteIds[2][10];
};

// UID:0000FL | by-class/UserHairSelectControlPane.md | Completion:91 | Confidence:93
class UserHairSelectControlPane : public ControlPane
{
public:
    enum { kColumns = 9, kRows = 2, kCellWidth = 82, kCellHeight = 58 };

    UserHairSelectControlPane(short selectedHair,
                              unsigned char hairColor,
                              unsigned char gender,
                              const RectBounds *bounds,
                              unsigned char controlFlags);
    virtual ~UserHairSelectControlPane() {}

    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaintFrame();

    void SelectHairAtPoint(int mouseY, int mouseX);
    void SetMaleMode();
    void SetFemaleMode();
    void SetHairColorIndex(unsigned char color) { m_hairColor = color; }
    short GetSelectedHairSlot() const { return m_selectedHair; }
    unsigned short GetSelectedHairPartFrame() const
    {
        return m_hairPartFrames[m_gender][m_selectedHair];
    }

private:
    unsigned char m_reservedState;
    short m_selectedHair;
    unsigned char m_gender;
    unsigned char m_hairColor;
    bool m_mouseTracking;
    unsigned short m_hairPartFrames[2][18];
    unsigned char m_columnCount;
    RectBounds m_hitBounds;
};

// UID:0000FJ | by-class/UserFaceSelectControlPane.md | Completion:91 | Confidence:93
class UserFaceSelectControlPane : public ControlPane
{
public:
    enum { kColumns = 6, kRows = 2, kCellWidth = 82, kCellHeight = 58 };

    UserFaceSelectControlPane(short selectedFace,
                              unsigned char faceColor,
                              unsigned char gender,
                              const RectBounds *bounds,
                              unsigned char controlFlags);
    virtual ~UserFaceSelectControlPane() {}

    virtual bool OnMouseEvent(const MouseEvent *event);
    virtual void OnPaintFrame();

    void SelectFaceAtPoint(int mouseY, int mouseX);
    void SetMaleMode();
    void SetFemaleMode();
    void SetFaceColorIndex(unsigned char color) { m_faceColor = color; }
    short GetSelectedFace() const { return m_selectedFace; }
    unsigned short GetSelectedFacePartId() const
    {
        return m_facePartIds[m_gender][m_selectedFace];
    }

private:
    unsigned char m_reservedState;
    short m_selectedFace;
    unsigned char m_gender;
    unsigned char m_faceColor;
    bool m_mouseTracking;
    unsigned short m_facePartIds[2][12];
    unsigned char m_columnCount;
    RectBounds m_hitBounds;
};

// UID:0000FH | by-class/UserCreatePreviewControlPane.md | Completion:90 | Confidence:92
class UserCreatePreviewControlPane : public ControlPane
{
public:
    UserCreatePreviewControlPane(short faceFrame,
                                 unsigned char faceColor,
                                 short hairFrame,
                                 unsigned char hairColor,
                                 unsigned char gender,
                                 const RectBounds *bounds,
                                 int reserved = 0);
    virtual ~UserCreatePreviewControlPane() {}

    virtual void OnPaint();

    HumanImageRenderParams *BuildPreviewParams(
        HumanImageRenderParams *params) const;
    void AdvanceDirection();
    void UpdatePreview(short faceFrame,
                       short hairFrame,
                       unsigned char gender);
    void UpdatePreview(short faceFrame,
                       unsigned char faceColor,
                       short hairFrame,
                       unsigned char hairColor,
                       unsigned char gender);

private:
    unsigned short m_faceFrameBase;
    unsigned short m_hairFrame;
    unsigned char m_gender;
    unsigned char m_direction;
    unsigned char m_hairColor;
    unsigned char m_faceColor;
    unsigned char m_reservedState;
};

// UID:0000FK | by-class/UserHairColorSelectListPane.md | Completion:90 | Confidence:92
class UserHairColorSelectListPane : public ListPane
{
public:
    explicit UserHairColorSelectListPane(CreateUserDialogPane *owner);
    virtual ~UserHairColorSelectListPane() {}

    int GetSelectedColorValue();
    virtual void DrawItem(int row,
                          const UserCreateColorSwatchItem *item,
                          const RectBounds *bounds);
    virtual void OnItemSelected(int row, int notify);

private:
    CreateUserDialogPane *m_owner;
};

// UID:0000FI | by-class/UserFaceColorSelectListPane.md | Completion:90 | Confidence:92
class UserFaceColorSelectListPane : public ListPane
{
public:
    explicit UserFaceColorSelectListPane(CreateUserDialogPane *owner);
    virtual ~UserFaceColorSelectListPane() {}

    int GetSelectedColorValue();
    virtual void DrawItem(int row,
                          const UserCreateColorSwatchItem *item,
                          const RectBounds *bounds);
    virtual void OnItemSelected(int row, int notify);

private:
    CreateUserDialogPane *m_owner;
};
