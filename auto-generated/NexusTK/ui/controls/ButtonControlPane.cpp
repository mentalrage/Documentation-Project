// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HY
// Source by-file doc: by-file/ButtonControlPane.md
// UID:00001E | by-class/ButtonControlPane.md | Completion:92 | Confidence:94
#include "ButtonControlPane.h"
#include "TextEditPane.h"



// UID:0003NA | by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md | Completion:95 | Confidence:97
TextButtonExControlPane::~TextButtonExControlPane()
{
    delete m_labelTextBox;
}

// UID:0003NC | by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md | Completion:88 | Confidence:89
void TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect)
{
    wchar_t labelText[128];

    m_labelTextBox->CopyWideText(labelText, 0x7f);

    const short textWidth = GetTextWidth(labelText);

    RectBounds controlBounds;
    GetBounds(&controlBounds);

    outRect->left = (controlBounds.left + controlBounds.right - textWidth) / 2;
    outRect->right = outRect->left + textWidth + 2;
    outRect->top = (controlBounds.top + controlBounds.bottom - 12) / 2;
    outRect->bottom = outRect->top + 12;

    IntersectRects(&controlBounds, outRect, outRect);
}

void TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect, const wchar_t *text)
{
    const short textWidth = GetTextWidth(text);

    RectBounds controlBounds;
    GetBounds(&controlBounds);

    outRect->left = (controlBounds.left + controlBounds.right - textWidth) / 2;
    outRect->right = outRect->left + textWidth + 2;
    outRect->top = (controlBounds.top + controlBounds.bottom - 12) / 2;
    outRect->bottom = outRect->top + 12;

    IntersectRects(&controlBounds, outRect, outRect);
}

// UID:00006D | by-class/ImageButtonControlPane.md | Completion:92 | Confidence:94
// UID:0002XZ | by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md | Completion:88 | Confidence:91
// MSVC scalar deleting destructor wrapper for ImageButtonControlPane.
// Generated from the class destructor/vtable layout; do not hand-author this
// wrapper as source.


// UID:0004X2 | by-memory/0x00495fd0-0x00496005.RadioGroupControlPaneDestructorRaw.md | Completion:92 | Confidence:94
RadioGroupControlPane::~RadioGroupControlPane()
{
    delete m_options;
}

// UID:00011E | by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md | Completion:90 | Confidence:93
// Raw RadioGroupControlPane option-helper island at 0x004964a0-0x0049662f is
// source-authored but has no recovered call, vtable, or pointer route in the
// current IDB. The live RadioGroupControlPane::OnPaint body at 0x00496300 owns
// the reachable option-render loop; do not emit standalone helper bodies from
// this raw island until a route or retained-helper source policy is proven.

// UID:0000CQ | by-class/SelectBoxControlPane.md | Completion:88 | Confidence:89
class SelectBoxControlPane : public ControlPane
{
public:
    explicit SelectBoxControlPane(const RectBounds *bounds);

    bool IsSelected() const;
    void SetSelected(bool selected);

protected:
    virtual bool OnMouseEvent(const EventRecord *event);
    virtual void OnPaint();

private:
    bool m_selected; // +0x108, object size 0x10c
};

// UID:00019V | by-memory/0x004fccf0-0x004fce7e.SelectBoxControlPane.md | Completion:88 | Confidence:91
enum
{
    kSelectBoxControlType = 8,
    kSelectBoxMouseDownEvent = 3,
    kControlPaneVisualStateNormal = 10
};

SelectBoxControlPane::SelectBoxControlPane(const RectBounds *bounds)
    : ControlPane(kSelectBoxControlType, bounds),
      m_selected(false)
{
    SetMode(1);
}

bool SelectBoxControlPane::IsSelected() const
{
    return m_selected;
}

void SelectBoxControlPane::SetSelected(bool selected)
{
    if (m_selected == selected)
        return;

    m_selected = selected;
    InvalidateRect(&m_bounds);
}

bool SelectBoxControlPane::OnMouseEvent(const EventRecord *event)
{
    if (event != NULL &&
        event->type == kSelectBoxMouseDownEvent &&
        PointInRect(event->y, event->x, &m_bounds) &&
        !m_selected)
    {
        m_selected = true;
        InvalidateRect(&m_bounds);
    }

    return true;
}

void SelectBoxControlPane::OnPaint()
{
    RectBounds frame = m_bounds;

    SetDrawColor(0);
    DrawBackgroundRect(&m_bounds);

    if (!m_selected && m_visualState == kControlPaneVisualStateNormal)
        return;

    SetDrawColor(4);
    DrawRectFrame(&frame);
    InsetRect(&frame, 1, 1);
    DrawRectFrame(&frame);
}

// UID:0000CR | by-class/SelectionControlPane.md | Completion:88 | Confidence:90
class SelectionControlPane : public ImageButtonControlPane
{
public:
    void SetSelectionAndRefresh(int selectedValue);

private:
    int m_selectedValue; // +0x10c, selected image/frame/value id
};

// UID:00011D | by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md | Completion:88 | Confidence:91
void SelectionControlPane::SetSelectionAndRefresh(int selectedValue)
{
    m_selectedValue = selectedValue;
    InvalidateRect(NULL);
}

// UID:0001SV | by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md | Completion:87 | Confidence:91
// SelectionControlPane selected-value storage at +0x10c is declared by
// [UID:0000CR][SelectionControlPane](by-class/SelectionControlPane.md) SelectionControlPane and written by [UID:00011D][0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh](by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md)
// SetSelectionAndRefresh. This field-evidence page has no standalone source
// object to emit.

// UID:0000DB | by-class/SliderControlPane.md | Completion:92 | Confidence:94

// UID:000223 | by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md | Completion:90 | Confidence:93
void SliderControlPane::ScrollLineBackward()
{
    int nextValue = 0;
    if (m_rangeCurrent >= 1)
        nextValue = m_rangeCurrent - 1;
    if (nextValue > m_rangeEnd)
        nextValue = m_rangeEnd;

    m_rangeCurrent = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollPageForward()
{
    int nextValue = 0;
    if (m_rangeCurrent >= -10)
        nextValue = m_rangeCurrent + 10;
    if (nextValue > m_rangeEnd)
        nextValue = m_rangeEnd;

    m_rangeCurrent = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollPageBackward()
{
    int nextValue = 0;
    if (m_rangeCurrent >= 10)
        nextValue = m_rangeCurrent - 10;
    if (nextValue > m_rangeEnd)
        nextValue = m_rangeEnd;

    m_rangeCurrent = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollLineForward()
{
    int nextValue = 0;
    if (m_rangeCurrent >= -1)
        nextValue = m_rangeCurrent + 1;
    if (nextValue > m_rangeEnd)
        nextValue = m_rangeEnd;

    m_rangeCurrent = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

// UID:0003N8 | by-memory\0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md | Completion:87 | Confidence:88 | Empty Emitter Marker

// UID:0000EK | by-class\TextButtonExControlPane.md | Completion:94 | Confidence:96 | Empty Emitter Marker

// UID:0000BI | by-class\RadioGroupControlPane.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0003NB | by-memory\0x00497890-0x00497c59.SliderControlPaneRawTailHelpers.md | Completion:89 | Confidence:92 | Empty Emitter Marker
