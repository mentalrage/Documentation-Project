// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O8
// Source by-file doc: by-file/StaticTextControlPane.md
// UID:0000E3 | by-class/StaticTextControlPane.md | Completion:91 | Confidence:93
#include "StaticTextControlPane.h"
#include "TextEditPane.h"

// UID:000222 | by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md | Completion:91 | Confidence:94
unsigned char StaticTextControlPane::GetControlType(int, int)
{
    return 19;
}

// UID:00011I | by-memory/0x00499030-0x004991ec.StaticTextControlPaneConstructor.md | Completion:88 | Confidence:91
namespace {
const int kStaticTextWideContentWidth = 1000;
const unsigned int kStaticTextPaneStyle = 4;
const unsigned int kStaticTextPaneAlternateStyle = 6;
}

StaticTextControlPane::StaticTextControlPane(const wchar_t *text,
                                             bool useAlternateStyle,
                                             int textColor,
                                             int shadowColor,
                                             const RectBounds *bounds,
                                             bool useWideContentWidth,
                                             bool inputMode)
    : ControlPane(5, bounds),
      m_textStateFlags(0),
      m_textEditPane(NULL)
{
    m_controlFlags = 1;

    const int width = m_bounds.right - m_bounds.left;
    const int height = m_bounds.bottom - m_bounds.top;
    const int contentWidth = useWideContentWidth ? kStaticTextWideContentWidth : width;
    const unsigned int paneStyle = useAlternateStyle ? kStaticTextPaneAlternateStyle : kStaticTextPaneStyle;

    m_textEditPane = new TextEditPane(width,
                                      height,
                                      contentWidth,
                                      height,
                                      textColor,
                                      shadowColor,
                                      false,
                                      false,
                                      paneStyle,
                                      IsLegacyAssetMode(),
                                      true,
                                      inputMode);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);

    m_textEditPane->SetBounds(&childBounds, false);
    m_textEditPane->SetMode(1);
    m_textEditPane->SetTextEditMode(false, false);

    if (text != NULL && text[0] != L'\0')
        m_textEditPane->SetText(text, 0);

    m_controlType = 6;
    m_controlFlags = 0;
    SetMode(4);
}

// UID:0000E4 | by-class/StaticTextControlPane2.md | Completion:92 | Confidence:93
#include "FontStyle.h"

class Layer;
struct RectBounds;

class StaticTextControlPane2 : public ControlPane
{
public:
    class SimpleHelpTextPartPane : public Pane
    {
    public:
        SimpleHelpTextPartPane();
        virtual ~SimpleHelpTextPartPane() {}
        virtual void OnPaint();

    private:
        friend class StaticTextControlPane2;

        void DrawTextLine(const FontStyleRule& style,
                          int x,
                          int y,
                          const wchar_t *text,
                          short charCount);

        SimpleUString m_text;
        int m_horizontalPadding;
        int m_verticalPadding;
        int m_lineSpacing;
        FontStyle *m_fontStyle;
    };

    StaticTextControlPane2(const wchar_t *text,
                           int x,
                           int y,
                           int horizontalAlignment,
                           int verticalAlignment,
                           const FontStyle *fontStyle,
                           int horizontalPadding,
                           int verticalPadding,
                           int lineSpacing);
    virtual ~StaticTextControlPane2();

    void SetCenterPosition(int centerX, int centerY);

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void Show();
    virtual void Hide();
    virtual void OnPaint();
    virtual unsigned char GetControlType(int, int);

private:
    void ApplyStyleState();

    wchar_t m_textBuffer[40];
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    FontStyle m_fontStyle;
    int m_horizontalPadding;
    int m_verticalPadding;
    int m_lineSpacing;
    int m_textWidth;
    int m_textHeight;
    int m_horizontalAlignment;
    int m_verticalAlignment;
    SimpleHelpTextPartPane m_textPart;
};

// UID:0004KS | by-memory/0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor.md | Completion:92 | Confidence:94
StaticTextControlPane2::StaticTextControlPane2(
    const wchar_t *text,
    int x,
    int y,
    int horizontalAlignment,
    int verticalAlignment,
    const FontStyle *fontStyle,
    int horizontalPadding,
    int verticalPadding,
    int lineSpacing)
    : ControlPane(8, NULL),
      m_fillColor(0),
      m_frameColor(0),
      m_fontStyle(),
      m_horizontalPadding(horizontalPadding),
      m_verticalPadding(verticalPadding),
      m_lineSpacing(lineSpacing),
      m_textWidth(0),
      m_textHeight(0),
      m_horizontalAlignment(horizontalAlignment),
      m_verticalAlignment(verticalAlignment),
      m_textPart()
{
    m_fontStyle.SetEnabled(false);
    if (fontStyle != NULL)
        m_fontStyle = *fontStyle;

    const int textLength = static_cast<int>(wcslen(text));
    int lineCount = 1;
    int maxLineWidth = -1;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index) {
        const wchar_t ch = text[index];
        if (ch != L'\r' && ch != L'\n' && ch != L'\t')
            continue;

        ++lineCount;
        const int lineWidth = GetTextWidth(
            text + lineStart,
            static_cast<short>(index - lineStart));
        if (lineWidth > maxLineWidth)
            maxLineWidth = lineWidth;
        lineStart = index + 1;
    }

    const int tailWidth = GetTextWidth(
        text + lineStart,
        static_cast<short>(textLength - lineStart));
    if (tailWidth > maxLineWidth)
        maxLineWidth = tailWidth;

    m_textWidth = maxLineWidth + (2 * m_horizontalPadding);
    m_textHeight = (lineCount * GetLineHeight())
                 + ((lineCount - 1) * m_lineSpacing)
                 + (2 * m_verticalPadding);

    RectBounds bounds;
    if (m_horizontalAlignment == 0)
        bounds.left = x;
    else if (m_horizontalAlignment == 1)
        bounds.left = x - m_textWidth;
    else
        bounds.left = x - (m_textWidth / 2);
    bounds.right = bounds.left + m_textWidth;

    if (m_verticalAlignment == 3)
        bounds.top = y;
    else if (m_verticalAlignment == 4)
        bounds.top = y - m_textHeight;
    else
        bounds.top = y - (m_textHeight / 2);
    bounds.bottom = bounds.top + m_textHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();
    if (bounds.left < 0)
        OffsetRect(&bounds, -bounds.left, 0);
    else if (bounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - bounds.right, 0);
    if (bounds.top < 0)
        OffsetRect(&bounds, 0, -bounds.top);
    else if (bounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - bounds.bottom);

    wcscpy_s(m_textBuffer, 32, text);
    SetBounds(&bounds, false);

    m_textPart.m_text = m_textBuffer;
    m_textPart.m_horizontalPadding = m_horizontalPadding;
    m_textPart.m_verticalPadding = m_verticalPadding;
    m_textPart.m_lineSpacing = m_lineSpacing;
    m_textPart.m_fontStyle = &m_fontStyle;
    m_alpha = 0.2f;

    ApplyStyleState();
}

// UID:0004KT | by-memory/0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor.md | Completion:91 | Confidence:93
StaticTextControlPane2::~StaticTextControlPane2()
{
}

// UID:0004KV | by-memory/0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition.md | Completion:92 | Confidence:94
void StaticTextControlPane2::SetCenterPosition(int centerX, int centerY)
{
    RectBounds bounds;
    if (m_horizontalAlignment == 0)
        bounds.left = centerX;
    else if (m_horizontalAlignment == 1)
        bounds.left = centerX - m_textWidth;
    else
        bounds.left = centerX - (m_textWidth / 2);
    bounds.right = bounds.left + m_textWidth;

    if (m_verticalAlignment == 3)
        bounds.top = centerY;
    else if (m_verticalAlignment == 4)
        bounds.top = centerY - m_textHeight;
    else
        bounds.top = centerY - (m_textHeight / 2);
    bounds.bottom = bounds.top + m_textHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();
    if (bounds.left < 0)
        OffsetRect(&bounds, -bounds.left, 0);
    else if (bounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - bounds.right, 0);
    if (bounds.top < 0)
        OffsetRect(&bounds, 0, -bounds.top);
    else if (bounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - bounds.bottom);

    SetBounds(&bounds, false);
    m_textPart.SetBounds(&bounds, false);
}

// UID:0004KW | by-memory/0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer.md | Completion:91 | Confidence:93
void StaticTextControlPane2::AddToLayer(const RectBounds *bounds,
                                        int order,
                                        Pane *previousPane,
                                        Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);
    m_textPart.AddToLayer(bounds,
                          order,
                          previousPane,
                          g_mainUiLayerSlots.overlayPaneLayerContext);
}

// UID:0004KX | by-memory/0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer.md | Completion:91 | Confidence:93
void StaticTextControlPane2::RemoveFromLayer()
{
    m_textPart.RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0004KY | by-memory/0x0049aae0-0x0049aaf8.StaticTextControlPane2Show.md | Completion:91 | Confidence:93
void StaticTextControlPane2::Show()
{
    Pane::Show();
    m_textPart.Show();
}

// UID:0004KZ | by-memory/0x0049ab00-0x0049ab18.StaticTextControlPane2Hide.md | Completion:91 | Confidence:93
void StaticTextControlPane2::Hide()
{
    Pane::Hide();
    m_textPart.Hide();
}

// UID:0004L0 | by-memory/0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint.md | Completion:92 | Confidence:94
void StaticTextControlPane2::OnPaint()
{
    RectBounds bounds = m_bounds;
    SetDrawColor(m_fillColor);
    FillRect(&bounds);
    SetDrawColor(m_frameColor);
    DrawRectFrame(&bounds);
}

// UID:0004L1 | by-memory/0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState.md | Completion:92 | Confidence:93
void StaticTextControlPane2::ApplyStyleState()
{
    if (!m_fontStyle.IsEnabled())
        return;

    const float parentOpacity = m_fontStyle.GetParentOpacity();
    if (parentOpacity >= 1.0f) {
        SetMode(1);
    } else if (parentOpacity >= 0.0f) {
        SetMode(3);
        m_alpha = parentOpacity;
    }

    m_fillColor = m_fontStyle.GetForegroundColor();
    m_frameColor = m_fontStyle.GetBackgroundColor();

    FontStyle *textStyle = m_textPart.m_fontStyle;
    if (textStyle == NULL || !textStyle->IsEnabled())
        return;

    const float textOpacity = textStyle->GetTextOpacity();
    if (textOpacity <= 0.0f) {
        m_textPart.SetMode(1);
    } else if (textOpacity <= 1.0f) {
        m_textPart.SetMode(3);
        m_textPart.m_alpha = textOpacity;
    }
}

// UID:0004L3 | by-memory/0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor.md | Completion:91 | Confidence:94
// Source-declared/generated-binary only. StaticTextControlPane2's ordinary virtual
// destructor regenerates this scalar deleting destructor, its flags-controlled optional
// operator-delete path, and both secondary-view adjustors. Do not hand-emit MSVC ABI.

// UID:0004L4 | by-memory/0x0049b910-0x0049b915.StaticTextControlPane2GetControlType.md | Completion:92 | Confidence:94
unsigned char StaticTextControlPane2::GetControlType(int, int)
{
    return 24;
}

// UID:0004L5 | by-type/by-vtable/StaticTextControlPane2Vtables.md | Completion:90 | Confidence:94
// Covered by the StaticTextControlPane2 declaration and virtual methods. The compiler
// regenerates the primary, secondary, and tertiary vtable views and RTTI locators.

// UID:0004L6 | by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md | Completion:91 | Confidence:94
// Covered by StaticTextControlPane2Vtables and the class declaration. Do not hand-emit
// raw vtable arrays, RTTI locators, inherited slot pointers, or adjustor addresses.

// UID:0000E5 | by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md | Completion:91 | Confidence:93
// The complete nested declaration is emitted once by StaticTextControlPane2. Preserve all
// accepted UID00011U exact method children here without duplicating the class definition.
// UID:0004L7 | by-memory/0x00499fe0-0x0049a080.StaticTextControlPane2SimpleHelpTextPartPaneConstructor.md | Completion:91 | Confidence:94
StaticTextControlPane2::SimpleHelpTextPartPane::SimpleHelpTextPartPane()
    : Pane(3),
      m_text(),
      m_horizontalPadding(0),
      m_verticalPadding(0),
      m_lineSpacing(0),
      m_fontStyle(NULL)
{
    m_alpha = 0.2f;
}

// UID:0004L8 | by-memory/0x0049a080-0x0049a298.StaticTextControlPane2SimpleHelpTextPartPaneOnPaint.md | Completion:92 | Confidence:94
void StaticTextControlPane2::SimpleHelpTextPartPane::OnPaint()
{
    RectBounds bounds = m_bounds;
    SetDrawColor(0);
    FillRect(&bounds);

    FontStyleRule style;
    style.m_textColor = 0x8f;
    style.m_secondaryColor = 0x80;
    style.m_effect = 0;
    style.m_alignment = 0;

    const wchar_t *text = m_text.c_str();
    SetTextColor(0x8f);

    Point point;
    InitPointPair(&point,
                  GetLineHeight() + m_verticalPadding,
                  m_horizontalPadding);

    int textLength = 0;
    while (text[textLength] != L'\0')
        ++textLength;

    int segmentStart = 0;
    unsigned int lineIndex = 0;
    for (int i = 0; i < textLength; ++i) {
        const wchar_t ch = text[i];
        if (ch != L'\r' && ch != L'\n' && ch != L'\t')
            continue;

        const short charCount = static_cast<short>(i - segmentStart);
        if (m_fontStyle != NULL && m_fontStyle->IsEnabled()) {
            m_fontStyle->GetRule(lineIndex, &style);
            DrawTextLine(style, point.x, point.y, text + segmentStart, charCount);
        } else {
            MoveTo(point.x, point.y);
            DrawWideText(text + segmentStart, charCount);
        }

        point.y += GetLineHeight() + m_lineSpacing;
        ++lineIndex;
        segmentStart = i + 1;
    }

    const short charCount = static_cast<short>(textLength - segmentStart);
    if (m_fontStyle != NULL && m_fontStyle->IsEnabled()) {
        m_fontStyle->GetRule(lineIndex, &style);
        DrawTextLine(style, point.x, point.y, text + segmentStart, charCount);
    } else {
        MoveTo(point.x, point.y);
        DrawWideText(text + segmentStart, charCount);
    }
}

// UID:0004LB | by-memory/0x0049a330-0x0049a403.StaticTextControlPane2SimpleHelpTextPartPaneDrawTextLine.md | Completion:92 | Confidence:94
void StaticTextControlPane2::SimpleHelpTextPartPane::DrawTextLine(
    const FontStyleRule& style,
    int x,
    int y,
    const wchar_t *text,
    short charCount)
{
    m_textAlign = style.m_alignment;
    SetTextColor(style.m_textColor);
    SetTextBackColor(style.m_secondaryColor);

    RectBounds rect;
    InitRectBoundsFromSize(&rect,
                           x,
                           y - 12,
                           m_bounds.right - (2 * x) - m_bounds.left,
                           12);

    switch (style.m_effect) {
    case 0:
        DrawTextInRect(text, charCount, &rect);
        break;
    case 1:
        DrawOutlinedText(text, charCount, &rect);
        break;
    case 3:
        DrawShadowedText(text, charCount, &rect);
        break;
    default:
        break;
    }
}

// UID:0004LD | by-memory/0x0049b560-0x0049b5a8.StaticTextControlPane2SimpleHelpTextPartPaneScalarDeletingDestructor.md | Completion:91 | Confidence:94
// Source-declared/generated-binary only. The inline virtual destructor on
// StaticTextControlPane2::SimpleHelpTextPartPane regenerates this scalar deleting
// destructor, the optional operator-delete path, and both secondary-view adjustors.
// Do not hand-emit an MSVC ABI wrapper.

// UID:0004L9 | by-memory/0x0049a2a0-0x0049a2c2.StaticTextControlPane2SimpleHelpTextPartPaneSetTextLayoutRaw.md | Completion:90 | Confidence:93
// Emitted code for this range is covered by [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md).

// UID:0004LA | by-memory/0x0049a2d0-0x0049a32e.StaticTextControlPane2SimpleHelpTextPartPaneApplyStyleOpacityStateRaw.md | Completion:90 | Confidence:93
// Emitted code for this range is covered by [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md).
