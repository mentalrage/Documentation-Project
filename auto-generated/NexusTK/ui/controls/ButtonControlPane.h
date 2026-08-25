// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HY
// Source by-file doc: by-file/ButtonControlPane.md
// UID:00001E | by-class/ButtonControlPane.md | Completion:92 | Confidence:94
#pragma once

#include "../../render/EPFTileContext.h"
#include "../core/ControlPane.h"

class Event;
struct RectBounds;

class ButtonControlPane : public ControlPane
{
public:
    explicit ButtonControlPane(const RectBounds &bounds)
        : ControlPane(0, &bounds)
    {
        m_controlActive = false;
        m_controlSelected = false;
        m_controlFlags = 1;
        m_handlesEnterKey = true;
        SetMode(1);
    }

    virtual ~ButtonControlPane() {}

    void SetControlSelected(bool selected);

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);

    bool m_controlSelected;
};

// UID:0000EK | by-class/TextButtonExControlPane.md | Completion:94 | Confidence:96
class Layer;
class TextBoxPane;

class TextButtonExControlPane : public ButtonControlPane
{
public:
    TextButtonExControlPane(const wchar_t *text, const RectBounds &bounds);
    virtual ~TextButtonExControlPane();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

    virtual void Enable();
    virtual void Disable();
    virtual short GetText(wchar_t *destination, short maxCharacters);

protected:
    virtual void SetVisualState(unsigned char visualState);
    virtual void OnPaint();

private:
    void CalculateLabelRect(RectBounds *outRect);
    void CalculateLabelRect(RectBounds *outRect, const wchar_t *text);

    TextBoxPane *m_labelTextBox;
};

[[No Children Attached]]

// UID:00006D | by-class/ImageButtonControlPane.md | Completion:92 | Confidence:94
class ImageButtonControlPane : public ButtonControlPane
{
public:
    ImageButtonControlPane(int imageId, const RectBounds *bounds);
    virtual void SetVisualState(unsigned char visualState);
    virtual void Enable();
    virtual void Disable();

protected:
    virtual void OnPaint();

private:
    int m_imageId;
    int m_imageState;
};

// UID:0000BI | by-class/RadioGroupControlPane.md | Completion:92 | Confidence:94
class RadioGroupControlPane : public ControlPane
{
public:
    explicit RadioGroupControlPane(const RectBounds *bounds);
    virtual ~RadioGroupControlPane();

    void AddOption(const wchar_t *text, const RectBounds *bounds);
    void SetSelectedIndex(int selectedIndex);
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }

    virtual void OnPaint();

private:
    List *m_options;
    int m_selectedIndex;
};

[[No Children Attached]]

// UID:0000DB | by-class/SliderControlPane.md | Completion:92 | Confidence:94
class Event;

class SliderControlPane : public ControlPane
{
public:
    SliderControlPane(const RectBounds *bounds, short maximumValue);

    void SetCurrentValue(short value);

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnTimer();
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    void GetPartRect(unsigned char part, RectBounds *rect) const;
    void BeginInteraction(unsigned char part, int localY, int localX);
    void EndInteraction();
    void ProcessScrollInput();
    void UpdateThumbFromDrag();
    void NotifyValueChanged();
    void ScrollLineBackward();
    void ScrollPageForward();
    void ScrollPageBackward();
    void ScrollLineForward();

    bool m_isHorizontal;
    DLPalette *m_palette;
    EPFTileContext m_frames[12];
    unsigned char m_activePart;
    Point m_dragOffset;
};

[[No Children Attached]]
