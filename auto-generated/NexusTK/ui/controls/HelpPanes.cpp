// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JU
// Source by-file doc: by-file/HelpPanes.md
// UID:000063 | by-class/HelpPane.md | Completion:92 | Confidence:94
#include "FontStyle.h"

class HelpPane : public Pane
{
public:
    class SimpleHelpTextPartPane : public Pane
    {
    public:
        SimpleHelpTextPartPane();
        virtual ~SimpleHelpTextPartPane() {}
        virtual void OnPaint();

    private:
        friend class HelpPane;

        void DrawStyledTextSegment(const FontStyleRule& style,
                                   int x,
                                   int y,
                                   const wchar_t *text,
                                   short charCount);

        SimpleUString m_text;
        FontStyle *m_fontStyle;
    };

    HelpPane(const wchar_t *text,
             Pane *owner,
             int x,
             int y,
             int horizontalAlign,
             int verticalAlign,
             const FontStyle *fontStyle);
    virtual ~HelpPane();

protected:
    virtual void OnPaintFrame();

private:
    void ApplyStyleState();

    unsigned int m_reserved;
    FontStyle m_fontStyle;
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    SimpleHelpTextPartPane m_textPane;
};

// UID:0003ZY | by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md | Completion:92 | Confidence:94
HelpPane::HelpPane(const wchar_t *text,
                   Pane *owner,
                   int x,
                   int y,
                   int horizontalAlign,
                   int verticalAlign,
                   const FontStyle *fontStyle)
    : Pane(3),
      m_fontStyle(),
      m_textPane()
{
    m_fontStyle.SetEnabled(false);
    if (fontStyle != NULL)
        m_fontStyle = *fontStyle;

    m_fillColor = 1;
    m_frameColor = 128;

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

    const int width = maxLineWidth + 10;
    const int height = lineCount * (GetLineHeight() + 1) + 9;

    RectBounds ownerBounds;
    owner->GetBounds(&ownerBounds);

    RectBounds bounds;
    if (horizontalAlign == 0)
        bounds.left = x;
    else if (horizontalAlign == 1)
        bounds.left = x - width;
    else
        bounds.left = x - (width / 2);
    bounds.right = bounds.left + width;

    if (verticalAlign == 3)
        bounds.top = y;
    else if (verticalAlign == 4)
        bounds.top = y - height;
    else
        bounds.top = y - (height / 2);
    bounds.bottom = bounds.top + height;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    Point ownerOffset;
    owner->GetScreenOffset(&ownerOffset);

    RectBounds screenBounds = bounds;
    OffsetRect(&screenBounds, ownerOffset.x, ownerOffset.y);

    if (screenBounds.left < 0)
        OffsetRect(&bounds, -screenBounds.left, 0);
    else if (screenBounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - screenBounds.right, 0);

    if (screenBounds.top < 0)
        OffsetRect(&bounds, 0, -screenBounds.top);
    else if (screenBounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - screenBounds.bottom);

    owner->GetScreenOffset(&ownerOffset);
    OffsetRect(&bounds, ownerOffset.x, ownerOffset.y);

    AddToLayer(&bounds, 0, 0, g_pStatusPaneLayer);
    SetPaneOrder(0, 0);

    m_textPane.m_text.Assign(text);
    m_textPane.m_fontStyle = &m_fontStyle;
    m_textPane.AddToLayer(&m_visibleBounds, 0, this,
                          g_mainUiLayerSlots.overlayPaneLayerContext);

    m_alpha = 0.2f;
    ApplyStyleState();
}

// UID:0003ZZ | by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md | Completion:92 | Confidence:94
HelpPane::~HelpPane()
{
}

// UID:000400 | by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md | Completion:92 | Confidence:94
void HelpPane::OnPaintFrame()
{
    RectBounds bounds = m_visibleBounds;
    SetDrawColor(m_fillColor);
    FillRect(&bounds);
    SetDrawColor(m_frameColor);
    DrawRectFrame(&bounds);
}

// UID:00022N | by-memory/0x004c6eb0-0x004c6f89.HelpPaneApplyStyleState.md | Completion:92 | Confidence:93
void HelpPane::ApplyStyleState()
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

    FontStyle *textStyle = m_textPane.m_fontStyle;
    if (textStyle == NULL || !textStyle->IsEnabled())
        return;

    const float textOpacity = textStyle->GetTextOpacity();
    if (textOpacity <= 0.0f) {
        m_textPane.SetMode(1);
    } else if (textOpacity <= 1.0f) {
        m_textPane.SetMode(3);
        m_textPane.m_alpha = textOpacity;
    }
}

// UID:000064 | by-class/HelpPane__SimpleHelpTextPartPane.md | Completion:92 | Confidence:94
// The complete nested declaration is emitted once by HelpPane. Preserve all exact
// HelpPane::SimpleHelpTextPartPane method children without duplicating the class.
// UID:0003ZU | by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md | Completion:92 | Confidence:94
HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane()
    : Pane(3),
      m_text(),
      m_fontStyle(NULL)
{
    m_alpha = 0.2f;
}

// UID:0003ZV | by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneOnPaint.md | Completion:92 | Confidence:94
void HelpPane::SimpleHelpTextPartPane::OnPaint()
{
    RectBounds bounds = m_visibleBounds;
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
    InitPointPair(&point, GetLineHeight() + 5, 5);

    int textLength = 0;
    while (text[textLength] != L'\0')
        ++textLength;

    int segmentStart = 0;
    unsigned int lineIndex = 0;
    for (int index = 0; index < textLength; ++index) {
        const wchar_t ch = text[index];
        if (ch != L'\r' && ch != L'\n' && ch != L'\t')
            continue;

        const short charCount = static_cast<short>(index - segmentStart);
        if (m_fontStyle != NULL && m_fontStyle->IsEnabled()) {
            m_fontStyle->GetRule(lineIndex, &style);
            DrawStyledTextSegment(style, point.x, point.y,
                                  text + segmentStart, charCount);
        } else {
            MoveTo(point.x, point.y);
            DrawWideText(text + segmentStart, charCount);
        }

        point.y += GetLineHeight() + 1;
        ++lineIndex;
        segmentStart = index + 1;
    }

    const short charCount = static_cast<short>(textLength - segmentStart);
    if (m_fontStyle != NULL && m_fontStyle->IsEnabled()) {
        m_fontStyle->GetRule(lineIndex, &style);
        DrawStyledTextSegment(style, point.x, point.y,
                              text + segmentStart, charCount);
    } else {
        MoveTo(point.x, point.y);
        DrawWideText(text + segmentStart, charCount);
    }
}

// UID:0003ZX | by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md | Completion:92 | Confidence:94
void HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment(
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
    InitRectFromSize(&rect, x, y - 12,
                     m_visibleBounds.right - (2 * x) - m_visibleBounds.left,
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
    }
}

// UID:0003ZW | by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md | Completion:90 | Confidence:93
// Emitted behavior for this no-entry copy is covered by UID00022N HelpPane::ApplyStyleState.

// UID:0000D6 | by-class/SimpleHelpPane.md | Completion:92 | Confidence:94
#include "HelpPanes.h"

// UID:00048E | by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md | Completion:88 | Confidence:90
SimpleHelpPane::SimpleHelpPane(const wchar_t *text,
                               Pane *owner,
                               int x,
                               int y,
                               int timeoutMs)
    : Pane(2),
      Singleton<SimpleHelpPane>(),
      m_textBuffer(0)
{
    const int textLength = static_cast<int>(wcslen(text));
    m_textBuffer = new wchar_t[textLength + 1];
    wmemcpy(m_textBuffer, text, textLength);
    m_textBuffer[textLength] = L'\0';

    int lineCount = 1;
    int maxLineWidth = -1;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index)
    {
        const wchar_t ch = m_textBuffer[index];
        if (ch == L'\r' || ch == L'\n' || ch == L'\t')
        {
            ++lineCount;

            const int lineWidth = GetTextWidth(m_textBuffer + lineStart,
                                               index - lineStart);
            if (lineWidth > maxLineWidth)
                maxLineWidth = lineWidth;

            lineStart = index + 1;
        }
    }

    const int tailWidth = GetTextWidth(m_textBuffer + lineStart,
                                       textLength - lineStart);
    if (tailWidth > maxLineWidth)
        maxLineWidth = tailWidth;

    const int width = maxLineWidth + 10;
    const int height = lineCount * (GetLineHeight() + 1) + 9;

    RectBounds ownerBounds;
    owner->GetBounds(&ownerBounds);

    RectBounds bounds;
    bounds.left = x - width / 2;
    bounds.top = y - height / 2;
    bounds.right = bounds.left + width;
    bounds.bottom = bounds.top + height;

    if (bounds.left < ownerBounds.left)
        OffsetRect(&bounds, ownerBounds.left - bounds.left, 0);
    else if (bounds.right > ownerBounds.right)
        OffsetRect(&bounds, ownerBounds.right - bounds.right, 0);

    if (bounds.top < ownerBounds.top)
        OffsetRect(&bounds, 0, ownerBounds.top - bounds.top);
    else if (bounds.bottom > ownerBounds.bottom)
        OffsetRect(&bounds, 0, ownerBounds.bottom - bounds.bottom);

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    Point ownerOffset;
    owner->GetScreenOffset(&ownerOffset);

    RectBounds screenBounds = bounds;
    OffsetRect(&screenBounds, ownerOffset.x, ownerOffset.y);

    if (screenBounds.left < 0)
        OffsetRect(&bounds, -screenBounds.left, 0);
    else if (screenBounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - screenBounds.right, 0);

    if (screenBounds.top < 0)
        OffsetRect(&bounds, 0, -screenBounds.top);
    else if (screenBounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - screenBounds.bottom);

    owner->GetScreenOffset(&ownerOffset);
    OffsetRect(&bounds, ownerOffset.x, ownerOffset.y);

    AddToLayer(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);

    SetTimer(timeoutMs);
    m_initialOpacity = 0.2f;
}

// UID:00048F | by-memory/0x004c7290-0x004c7307.SimpleHelpPaneDestructor.md | Completion:92 | Confidence:94
SimpleHelpPane::~SimpleHelpPane()
{
    delete [] m_textBuffer;
}

// UID:00048G | by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md | Completion:89 | Confidence:91
void SimpleHelpPane::OnPaintFrame()
{
    RectBounds bounds = m_bounds;

    SetDrawColor(1);
    FillPaneRect(bounds);

    SetDrawColor(0x80);
    DrawRectFrame(bounds);

    SetTextColor(0x8f);

    const int margin = 5;
    const wchar_t *text = m_textBuffer;
    const int textLength = static_cast<int>(wcslen(text));
    const int drawX = margin;
    int drawY = GetTextLineHeight() + margin;
    int lineStart = 0;

    for (int index = 0; index < textLength; ++index)
    {
        const wchar_t ch = text[index];
        if (ch == L'\r' || ch == L'\n' || ch == L'\t')
        {
            MoveTo(drawX, drawY);
            DrawTextRun(text + lineStart, index - lineStart);

            drawY += GetTextLineHeight() + 1;
            lineStart = index + 1;
        }
    }

    MoveTo(drawX, drawY);
    DrawTextRun(text + lineStart, textLength - lineStart);
}

// UID:00048H | by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md | Completion:91 | Confidence:94
bool SimpleHelpPane::OnTimer(int, int, int)
{
    Close();
    return false;
}

// UID:00048I | by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md | Completion:92 | Confidence:94
bool SimpleHelpPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonDown ||
        event->m_type == kEventRightButtonDown)
    {
        ScheduleTimer(0, 0, 0, 0);
        return true;
    }

    if (event->m_type == kEventCursorMove)
        ScheduleTimer(0, 0, 0, 0);

    return false;
}

// UID:00048J | by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md | Completion:91 | Confidence:94
bool SimpleHelpPane::HandleKeyOrTextEvent(Event *)
{
    Close();
    return false;
}

// UID:0000D7 | by-class/SimpleHelpPane2.md | Completion:92 | Confidence:94
class SimpleHelpPane2 : public HelpPane,
                        public Singleton<SimpleHelpPane2>
{
public:
    SimpleHelpPane2(const wchar_t *text,
                    Pane *owner,
                    int x,
                    int y,
                    const RectBounds *anchorRect,
                    int timeoutMs,
                    int horizontalAlign,
                    int verticalAlign,
                    const FontStyle *style);
    virtual ~SimpleHelpPane2();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    bool IsCursorInsideAnchorRect();

    RectBounds m_anchorRect;
};

extern SimpleHelpPane2 *g_pSimpleHelpPane2;

// UID:00048K | by-memory/0x004c74b0-0x004c75d5.SimpleHelpPane2Constructor.md | Completion:90 | Confidence:93
SimpleHelpPane2::SimpleHelpPane2(const wchar_t *text,
                                 Pane *owner,
                                 int x,
                                 int y,
                                 const RectBounds *anchorRect,
                                 int timeoutMs,
                                 int horizontalAlign,
                                 int verticalAlign,
                                 const FontStyle *style)
    : HelpPane(text, owner, x, y, horizontalAlign, verticalAlign, style),
      Singleton<SimpleHelpPane2>()
{
    if (anchorRect != 0)
    {
        m_anchorRect = *anchorRect;

        RectBounds paneBounds;
        GetBounds(&paneBounds);

        Point ownerOffset;
        if (owner != 0)
            owner->GetScreenOffset(&ownerOffset);
        else
        {
            ownerOffset.x = 0;
            ownerOffset.y = 0;
        }

        m_anchorRect.Offset(ownerOffset.x - paneBounds.left,
                            ownerOffset.y - paneBounds.top);
    }
    else
    {
        m_anchorRect.Clear();
    }

    ScheduleTimer(0, timeoutMs, 0, 0);
}

// UID:00048L | by-memory/0x004c75e0-0x004c7609.SimpleHelpPane2Destructor.md | Completion:92 | Confidence:94
SimpleHelpPane2::~SimpleHelpPane2()
{
}

// UID:00048M | by-memory/0x004c7610-0x004c7620.SimpleHelpPane2OnAccept.md | Completion:88 | Confidence:91
bool SimpleHelpPane2::OnTimer(int, int, int)
{
    Close();
    return true;
}

// UID:00048N | by-memory/0x004c7620-0x004c7668.SimpleHelpPane2HandleEvent.md | Completion:91 | Confidence:94
bool SimpleHelpPane2::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonDown ||
        event->m_type == kEventRightButtonDown ||
        (event->m_type == kEventCursorMove &&
         !PointInRect(event->m_payload.m_pointer.m_y,
                      event->m_payload.m_pointer.m_x,
                      &m_anchorRect)))
    {
        ScheduleTimer(0, 0, 0, 0);
    }

    return false;
}

// UID:00048O | by-memory/0x004c7670-0x004c7680.SimpleHelpPane2OnCancel.md | Completion:91 | Confidence:94
bool SimpleHelpPane2::HandleKeyOrTextEvent(Event *)
{
    Close();
    return false;
}

// UID:00006U | by-class/ItemHelpPane.md | Completion:92 | Confidence:94
#include "HelpPanes.h"

// UID:0003PL | by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md | Completion:92 | Confidence:94
ItemHelpPane::ItemHelpPane(const wchar_t *itemKey,
                           Pane *owner,
                           int x,
                           int y,
                           int timeoutMs,
                           const wchar_t *displayName,
                           int currentDurability,
                           unsigned char protectionCount)
    : Pane(2),
      Singleton<ItemHelpPane>(),
      m_contentWidth(0),
      m_lineCount(1),
      m_isEquipmentItem(false),
      m_hasItemInstanceState(false),
      m_currentDurability(0),
      m_protectionCount(0),
      m_statValueTextBuffers(0)
{
    m_itemMetaKey[0] = L'\0';
    m_itemDisplayName[0] = L'\0';
    m_ownerName[0] = L'\0';
    m_helpDescription[0] = L'\0';

    if (owner == g_pGeneralPurposePanel->GetChildPaneByIndex(2))
    {
        LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(static_cast<char>(_wtol(itemKey)));
        m_hasItemInstanceState = true;
        m_currentDurability = item->currentDurability;
        wcscpy_s(m_itemMetaKey, 64,
                 item->itemMetaKey[0] != L'\0' ? item->itemMetaKey : item->displayName);
        wcscpy_s(m_itemDisplayName, 64, item->displayName);
        wcscpy_s(m_ownerName, 64,
                 item->ownerName[0] != L'\0' ? item->ownerName : L"");
        if (item->protectionCount > 0)
            m_protectionCount = item->protectionCount;
    }
    else if (owner == g_pGeneralPurposePanel->GetChildPaneByIndex(0))
    {
        m_hasItemInstanceState = true;
        m_currentDurability = currentDurability;
        wcscpy_s(m_itemMetaKey, 64,
                 itemKey[0] != L'\0' ? itemKey : displayName);
        wcscpy_s(m_itemDisplayName, 64, displayName);
        m_ownerName[0] = L'\0';
        if (protectionCount != 0)
            m_protectionCount = protectionCount;
    }
    else
    {
        wcscpy_s(m_itemMetaKey, 64, itemKey);
        wcscpy_s(m_itemDisplayName, 64, itemKey);
    }

    PopulateItemData(itemKey);

    const bool hasDescription =
        m_helpDescription[0] != L'\0' && wcscmp(m_helpDescription, L" ") != 0;
    if (hasDescription)
    {
        m_lineCount = 2 + CountTextLines(
            m_helpDescription,
            static_cast<short>(wcslen(m_helpDescription)),
            180);
        m_contentWidth = GetTextWidth(
            m_helpDescription,
            static_cast<int>(wcslen(m_helpDescription)));
        if (m_contentWidth > 180)
            m_contentWidth = 180;
    }

    const int titleWidth = GetTextWidth(
        m_itemDisplayName,
        static_cast<int>(wcslen(m_itemDisplayName))) + 1;
    if (titleWidth > m_contentWidth)
        m_contentWidth = titleWidth;

    if (!m_isEquipmentItem)
    {
        if (m_hasItemInstanceState && m_currentDurability > 0)
        {
            m_lineCount += 4;
            if (m_contentWidth < 156)
                m_contentWidth = 156;
        }
        else
        {
            m_lineCount += 2;
            const int valueWidth =
                GetTextWidth(m_statLabels[1], static_cast<int>(wcslen(m_statLabels[1]))) +
                GetTextWidth(m_statValueTextBuffers[1],
                             static_cast<int>(wcslen(m_statValueTextBuffers[1]))) + 6;
            if (valueWidth > m_contentWidth)
                m_contentWidth = valueWidth;
        }
    }
    else
    {
        ++m_lineCount;
        for (int row = 0; row < 20; ++row)
        {
            if (row < 2 || row == 13 || row == 14 || row == 15)
                continue;
            if (m_statValueTextBuffers[row][0] == L'\0')
                continue;

            ++m_lineCount;
            const int rowWidth =
                GetTextWidth(m_statLabels[row],
                             static_cast<int>(wcslen(m_statLabels[row]))) +
                GetTextWidth(m_statValueTextBuffers[row],
                             static_cast<int>(wcslen(m_statValueTextBuffers[row]))) + 6;
            if (rowWidth > m_contentWidth)
                m_contentWidth = rowWidth;
        }

        m_lineCount += 2;
        if (_wtol(m_statValueTextBuffers[14]) == 0 ||
            _wtol(m_statValueTextBuffers[13]) == 0)
        {
            if (m_contentWidth < 156)
                m_contentWidth = 156;
        }
    }

    if (m_protectionCount > 0)
        ++m_lineCount;

    const int width = m_contentWidth + 20;
    int height = (GetLineHeight() + 1) * m_lineCount + 19;
    if (hasDescription)
    {
        height += 1 - CountTextLines(
            m_helpDescription,
            static_cast<short>(wcslen(m_helpDescription)),
            180);
    }

    RectBounds ownerBounds;
    owner->GetBounds(&ownerBounds);

    RectBounds bounds;
    bounds.left = x - width / 2;
    bounds.top = y - height / 2;
    bounds.right = bounds.left + width;
    bounds.bottom = bounds.top + height;

    if (bounds.left < ownerBounds.left)
        OffsetRect(&bounds, ownerBounds.left - bounds.left, 0);
    else if (bounds.right > ownerBounds.right)
        OffsetRect(&bounds, ownerBounds.right - bounds.right, 0);
    if (bounds.top < ownerBounds.top)
        OffsetRect(&bounds, 0, ownerBounds.top - bounds.top);
    else if (bounds.bottom > ownerBounds.bottom)
        OffsetRect(&bounds, 0, ownerBounds.bottom - bounds.bottom);

    Point ownerOffset;
    owner->GetScreenOffset(&ownerOffset);
    RectBounds screenBounds = bounds;
    OffsetRect(&screenBounds, ownerOffset.x, ownerOffset.y);

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();
    if (screenBounds.left < 0)
        OffsetRect(&bounds, -screenBounds.left, 0);
    else if (screenBounds.right >= screenWidth)
        OffsetRect(&bounds, screenWidth - screenBounds.right, 0);
    if (screenBounds.top < 0)
        OffsetRect(&bounds, 0, -screenBounds.top);
    else if (screenBounds.bottom >= screenHeight)
        OffsetRect(&bounds, 0, screenHeight - screenBounds.bottom);

    owner->GetScreenOffset(&ownerOffset);
    OffsetRect(&bounds, ownerOffset.x, ownerOffset.y);
    AddToLayer(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);
    ScheduleTimer(0, timeoutMs, 0, 0);
    m_initialOpacity = 0.2f;
}

// UID:0003PM | by-memory/0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md | Completion:93 | Confidence:94
ItemHelpPane::~ItemHelpPane()
{
    for (int row = 0; row < 20; ++row)
        delete [] m_statValueTextBuffers[row];
    delete [] m_statValueTextBuffers;
}

// UID:0003PN | by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md | Completion:93 | Confidence:94
void ItemHelpPane::OnPaintFrame()
{
    RectBounds bounds = m_bounds;
    SetDrawColor(0x97);
    FillPaneRect(bounds);
    SetDrawColor(0x80);
    DrawRectFrame(bounds);

    const int left = bounds.left + 10;
    const int right = bounds.right - 10;
    const int center = (left + right) / 2;
    const int lineHeight = GetLineHeight() + 1;
    int drawY = bounds.top + 10;

#define DRAW_ITEM_HELP_TEXT(text, color, x, y) \
    do { \
        SetTextColor(color); \
        MoveTo(x, y); \
        DrawTextRun(text, static_cast<int>(wcslen(text))); \
    } while (0)

#define DRAW_ITEM_HELP_PAIR(label, value) \
    do { \
        const int labelLength = static_cast<int>(wcslen(label)); \
        const int valueLength = static_cast<int>(wcslen(value)); \
        const int pairWidth = GetTextWidth(label, labelLength) + \
                              GetTextWidth(value, valueLength); \
        const int pairLeft = center - pairWidth / 2; \
        DRAW_ITEM_HELP_TEXT(label, 0x8f, pairLeft, drawY); \
        DRAW_ITEM_HELP_TEXT(value, 0x97, \
                            pairLeft + GetTextWidth(label, labelLength), drawY); \
        drawY += lineHeight; \
    } while (0)

    const int titleLength = static_cast<int>(wcslen(m_itemDisplayName));
    const int titleX = center - GetTextWidth(m_itemDisplayName, titleLength) / 2;
    DRAW_ITEM_HELP_TEXT(m_itemDisplayName, 0x80, titleX + 1, drawY + 1);
    DRAW_ITEM_HELP_TEXT(m_itemDisplayName, 0x8f, titleX, drawY);
    drawY += lineHeight;

    if (m_helpDescription[0] != L'\0' && wcscmp(m_helpDescription, L" ") != 0)
    {
        RectBounds descriptionBounds;
        descriptionBounds.left = left;
        descriptionBounds.top = drawY;
        descriptionBounds.right = right;
        descriptionBounds.bottom = bounds.bottom - 10;
        SetTextColor(0x8f);
        DrawTextInRect(m_helpDescription,
                       static_cast<int>(wcslen(m_helpDescription)),
                       &descriptionBounds);
        drawY += lineHeight * CountTextLines(
            m_helpDescription,
            static_cast<short>(wcslen(m_helpDescription)),
            right - left);
        drawY += lineHeight;
    }

    if (!m_isEquipmentItem)
    {
        if (m_hasItemInstanceState && m_currentDurability > 0)
        {
            DRAW_ITEM_HELP_PAIR(m_statLabels[2], m_statValueTextBuffers[2]);
            drawY += lineHeight;
        }
        DRAW_ITEM_HELP_PAIR(m_statLabels[1], m_statValueTextBuffers[1]);
    }
    else
    {
        DRAW_ITEM_HELP_PAIR(m_statLabels[1], m_statValueTextBuffers[1]);
        if (m_hasItemInstanceState && m_currentDurability > 0)
            DRAW_ITEM_HELP_PAIR(m_statLabels[2], m_statValueTextBuffers[2]);

        const int rowOrder[] = { 3, 4, 5, 6, 7, 8, 10, 9, 11, 12, 16, 17 };
        for (int index = 0; index < 12; ++index)
        {
            const int row = rowOrder[index];
            if (m_statValueTextBuffers[row][0] != L'\0')
                DRAW_ITEM_HELP_PAIR(m_statLabels[row], m_statValueTextBuffers[row]);
        }

        if (m_ownerName[0] != L'\0')
            DRAW_ITEM_HELP_PAIR(L"Owner ", m_ownerName);

        if (m_protectionCount > 0)
        {
            wchar_t protectionText[32];
            swprintf_s(protectionText, 32, L"PROTECTED (%d)", m_protectionCount);
            const int protectionLength = static_cast<int>(wcslen(protectionText));
            DRAW_ITEM_HELP_TEXT(protectionText, 0x8f,
                                center - GetTextWidth(protectionText, protectionLength) / 2,
                                drawY);
            drawY += lineHeight;
        }

        const int classRequirement = _wtol(m_statValueTextBuffers[13]);
        const int tierRequirement = _wtol(m_statValueTextBuffers[14]);
        const wchar_t *classText = 0;
        const wchar_t *tierText = 0;

        switch (classRequirement)
        {
        case 0:
            if (tierRequirement == 0)
                classText = L"Any Class";
            break;
        case 1:
            switch (tierRequirement)
            {
            case 0: classText = L"Warrior"; break;
            case 1: tierText = L"Il San (W)"; break;
            case 2: tierText = L"Ee San (W)"; break;
            case 3: tierText = L"Sam San (W)"; break;
            case 4: tierText = L"Sa San (W)"; break;
            }
            break;
        case 2:
            switch (tierRequirement)
            {
            case 0: classText = L"Rogue"; break;
            case 1: tierText = L"Il San (R)"; break;
            case 2: tierText = L"Ee San (R)"; break;
            case 3: tierText = L"Sam San (R)"; break;
            case 4: tierText = L"Sa San (R)"; break;
            }
            break;
        case 3:
            switch (tierRequirement)
            {
            case 0: classText = L"Mage"; break;
            case 1: tierText = L"Il San (M)"; break;
            case 2: tierText = L"Ee San (M)"; break;
            case 3: tierText = L"Sam San (M)"; break;
            case 4: tierText = L"Sa San (M)"; break;
            }
            break;
        case 4:
            switch (tierRequirement)
            {
            case 0: classText = L"Poet"; break;
            case 1: tierText = L"Il San (P)"; break;
            case 2: tierText = L"Ee San (P)"; break;
            case 3: tierText = L"Sam San (P)"; break;
            case 4: tierText = L"Sa San (P)"; break;
            }
            break;
        case 5:
            switch (tierRequirement)
            {
            case 0: classText = L"Archer"; break;
            case 1: tierText = L"Il San (A)"; break;
            case 2: tierText = L"Ee San (A)"; break;
            case 3: tierText = L"Sam San (A)"; break;
            case 4: tierText = L"Sa San (A)"; break;
            }
            break;
        }

        if (tierText != 0)
        {
            const int tierLength = static_cast<int>(wcslen(tierText));
            DRAW_ITEM_HELP_TEXT(tierText, 0x8f,
                                center - GetTextWidth(tierText, tierLength) / 2,
                                drawY);
        }
        else if (classText != 0)
        {
            wchar_t requirementText[128];
            swprintf_s(requirementText, 128, L"%s   Level %s Req ",
                       classText, m_statValueTextBuffers[15]);
            const int requirementLength = static_cast<int>(wcslen(requirementText));
            DRAW_ITEM_HELP_TEXT(requirementText, 0x8f,
                                center - GetTextWidth(requirementText,
                                                      requirementLength) / 2,
                                drawY);
        }
    }

#undef DRAW_ITEM_HELP_PAIR
#undef DRAW_ITEM_HELP_TEXT
}

// UID:0003PP | by-memory/0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md | Completion:93 | Confidence:94
bool ItemHelpPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0)
        Close();
    return false;
}

// UID:0003PQ | by-memory/0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md | Completion:93 | Confidence:94
bool ItemHelpPane::HandlePointerOrMouseEvent(Event *event)
{
    InvalidateRect(&m_bounds);
    if (event->m_type == 1 || event->m_type == 4)
        ScheduleTimer(0, 0, 0, 0);
    return true;
}

// UID:0003PR | by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md | Completion:93 | Confidence:94
bool ItemHelpPane::HandleKeyOrTextEvent(Event *)
{
    delete g_pItemHelpPane;
    return false;
}

// UID:0003PS | by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md | Completion:93 | Confidence:94
void ItemHelpPane::PopulateItemData(const wchar_t *itemKey)
{
    static const wchar_t *const labels[20] =
    {
        L"", L"Value ", L"Durability ", L"Armor    ", L"Hit    ",
        L"Damage ", L"Vitality increase ", L"Mana increase     ",
        L"Might increase    ", L"Grace increase    ",
        L"Will increase     ", L"Wisdom increase   ", L"Con    ",
        L"", L"", L"", L"Regen  ", L"Protection ",
        L"Damage S ", L"       L "
    };

    for (int row = 0; row < 20; ++row)
        wcscpy_s(m_statLabels[row], 20, labels[row][0] != L'\0' ? labels[row] : L" ");
    m_statLabels[0][0] = L'\0';
    m_statLabels[13][0] = L'\0';
    m_statLabels[14][0] = L'\0';
    m_statLabels[15][0] = L'\0';

    SimpleUString key;
    key.Assign(itemKey, static_cast<unsigned int>(wcslen(itemKey)));
    SimpleUString tableName;
    const SimpleUString *entry = &g_emptySimpleUString;
    wchar_t tableBuffer[32];

    for (int index = 0; index < 9; ++index)
    {
        swprintf_s(tableBuffer, 32, L"ItemHelp%d", index);
        tableName.Assign(tableBuffer,
                         static_cast<unsigned int>(wcslen(tableBuffer)));
        entry = g_pMetaMan->FindEntry(&tableName, &key, 0);
        if (*entry != g_emptySimpleUString)
            break;
    }
    if (*entry != g_emptySimpleUString)
        wcscpy_s(m_helpDescription, 64, entry->c_str());

    entry = &g_emptySimpleUString;
    for (int index = 0; index < 9; ++index)
    {
        swprintf_s(tableBuffer, 32, L"ItemInfo%d", index);
        tableName.Assign(tableBuffer,
                         static_cast<unsigned int>(wcslen(tableBuffer)));
        entry = g_pMetaMan->FindEntry(&tableName, &key, 0);
        if (*entry != g_emptySimpleUString)
            break;
    }

    if (*entry != g_emptySimpleUString)
    {
        m_isEquipmentItem = false;
        g_pMetaMan->LoadStatValues(&tableName, &key,
                                   &m_statValueTextBuffers, 20);

        wchar_t ungroupedValue[40];
        wcscpy_s(ungroupedValue, 40, m_statValueTextBuffers[1]);
        const int length = static_cast<int>(wcslen(ungroupedValue));
        int source = length - 1;
        int destination = length + (length - 1) / 3;
        m_statValueTextBuffers[1][destination--] = L'\0';
        int digits = 0;
        while (source >= 0)
        {
            m_statValueTextBuffers[1][destination--] = ungroupedValue[source--];
            if (++digits == 3 && source >= 0)
            {
                m_statValueTextBuffers[1][destination--] = L',';
                digits = 0;
            }
        }
        return;
    }

    entry = &g_emptySimpleUString;
    for (int index = 0; ; ++index)
    {
        swprintf_s(tableBuffer, 32, L"CharicInfo%d", index);
        tableName.Assign(tableBuffer,
                         static_cast<unsigned int>(wcslen(tableBuffer)));
        if (g_pMetaMan->FindTableByName(&tableName) == 0)
            break;
        entry = g_pMetaMan->FindEntry(&tableName, &key, 0);
        if (*entry != g_emptySimpleUString)
            break;
    }

    if (*entry != g_emptySimpleUString)
    {
        m_isEquipmentItem = true;
        g_pMetaMan->LoadStatValues(&tableName, &key,
                                   &m_statValueTextBuffers, 20);

        if (m_hasItemInstanceState)
        {
            const int maximumDurability = _wtol(m_statValueTextBuffers[2]);
            const int percent = maximumDurability == 0
                ? 0 : m_currentDurability * 100 / maximumDurability;
            swprintf_s(m_statValueTextBuffers[2], 40, L"%d/%d (%d%%) ",
                       m_currentDurability, maximumDurability, percent);
        }

        const int positiveRows[] = { 3, 4, 5, 6, 7, 8, 10, 9, 11, 12, 16, 17 };
        for (int index = 0; index < 12; ++index)
        {
            const int row = positiveRows[index];
            if (wcscmp(m_statValueTextBuffers[row], L"0") != 0 &&
                _wtol(m_statValueTextBuffers[row]) > 0)
            {
                const int value = _wtol(m_statValueTextBuffers[row]);
                swprintf_s(m_statValueTextBuffers[row], 40, L"+%d", value);
            }
        }
        return;
    }

    m_isEquipmentItem = false;
    m_statValueTextBuffers = new wchar_t *[20];
    for (int row = 0; row < 20; ++row)
    {
        m_statValueTextBuffers[row] = new wchar_t[40];
        m_statValueTextBuffers[row][0] = L'\0';
    }
    wcscpy_s(m_statValueTextBuffers[1], 40, L"0");
    if (m_hasItemInstanceState && m_currentDurability > 0)
        swprintf_s(m_statValueTextBuffers[2], 40, L"%d", m_currentDurability);
}

// UID:0003PT | by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md | Completion:93 | Confidence:94
short ItemHelpPane::CountTextLines(const wchar_t *text,
                                   short textLength,
                                   int width)
{
    short lineCount = 0;
    int offset = 0;
    while (offset < textLength)
    {
        ++lineCount;
        int fitLength = GetTextFitLength(text + offset, width);
        if (textLength < offset + fitLength)
            fitLength = textLength - offset;
        offset += fitLength;
        if (text[offset] == L' ')
            ++offset;
    }
    return lineCount;
}

// UID:0000G5 | by-class/WillBeChangedItemPane.md | Completion:92 | Confidence:94
// UID:0004V4 | by-memory/0x004c78e0-0x004c7b76.WillBeChangedItemPaneConstructor.md | Completion:91 | Confidence:94
WillBeChangedItemPane::WillBeChangedItemPane(
    Pane *owner,
    char inventorySlot,
    int y,
    int x,
    int pointerY,
    int pointerX,
    bool compactDisplay)
    : Pane(1)
{
    (void)owner;

    RectBounds glyphBounds;
    RectBounds paneBounds;
    RectBounds screenBounds;

    m_inventorySlotRecord =
        g_pUserPane->GetInventorySlotAddress(inventorySlot);
    m_inventorySlot = inventorySlot;
    m_compactDisplay = compactDisplay;
    m_initialPointerY = pointerY;
    m_initialPointerX = pointerX;

    GetItemGlyphBounds(m_inventorySlotRecord->itemId, &glyphBounds);

    int paneY = y;
    int paneX = x;
    if (m_compactDisplay) {
        const int halfWidth =
            (glyphBounds.right - glyphBounds.left) / 2;
        const int halfHeight =
            (glyphBounds.bottom - glyphBounds.top) / 2;
        const int paneHeight =
            halfHeight >= GetLineHeight() + 4
                ? halfHeight
                : GetLineHeight() + 4;

        InitRectBounds(&paneBounds, 0, 0, 170, paneHeight);

        const int candidateX = x - halfWidth / 2 + 6;
        if (candidateX < paneX) {
            paneX = candidateX;
        }

        const int candidateY = y - paneHeight / 2 - 6;
        if (candidateY < paneY) {
            paneY = candidateY;
        }
    } else {
        paneBounds = glyphBounds;
        const int glyphWidth = glyphBounds.right - glyphBounds.left;
        const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
        if (glyphWidth < 43) {
            paneBounds.right += (43 - glyphWidth) / 2;
        }
        if (glyphHeight < 43) {
            paneBounds.bottom += (43 - glyphHeight) / 2;
        }

        g_pGeneralPurposePanel->GetChildPaneByIndex(2)->SetMode(0);
    }

    AddToLayer(
        &paneBounds, 0, 0,
        g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);
    m_origin.y = paneY;
    m_origin.x = paneX;

    GetScreenBounds(&screenBounds);
    m_initialPointerY -= screenBounds.top;
    m_initialPointerX -= screenBounds.left;
    m_drawY = y - screenBounds.top;
    m_drawX = x - screenBounds.left;
}

// UID:0004V5 | by-memory/0x004c7b80-0x004c7ba9.WillBeChangedItemPaneDestructor.md | Completion:92 | Confidence:94
WillBeChangedItemPane::~WillBeChangedItemPane()
{
}

// UID:0004V6 | by-memory/0x004c7bb0-0x004c7efd.WillBeChangedItemPaneOnPaintFrame.md | Completion:91 | Confidence:94
void WillBeChangedItemPane::OnPaintFrame()
{
    RectBounds unusedScreenBounds;
    RectBounds glyphBounds;
    wchar_t slotText[128];

    GetScreenBounds(&unusedScreenBounds);

    if (m_compactDisplay) {
        GetItemGlyphBounds(m_inventorySlotRecord->itemId, &glyphBounds);

        const int halfWidth =
            (glyphBounds.right - glyphBounds.left) / 2;
        const int halfHeight =
            (glyphBounds.bottom - glyphBounds.top) / 2;
        RectBounds imageBounds;
        imageBounds.left = m_drawX - halfWidth / 2 + 6;
        imageBounds.top = m_drawY - halfHeight / 2 - 6;
        imageBounds.right = imageBounds.left + halfWidth;
        imageBounds.bottom = imageBounds.top + halfHeight;

        g_pItemObjImageLib->DrawItemImageUnscaled(
            this, &imageBounds,
            m_inventorySlotRecord->itemId,
            m_inventorySlotRecord->iconStyle);

        swprintf_s(
            slotText, 128, L"%c",
            SlotIndexToHotkeyLetter(m_inventorySlot));
        MoveTo(m_drawX + 25, m_drawY);
        SetTextColor(12);
        DrawWideText(slotText, wcslen(slotText));
        MoveTo(m_drawX + 24, m_drawY);
        SetTextColor(12);
        DrawWideText(slotText, wcslen(slotText));
        SetTextColor(128);
        DrawWideText(
            m_inventorySlotRecord->displayName,
            wcslen(m_inventorySlotRecord->displayName));
    } else {
        RectBounds imageBounds = m_visibleBounds;
        GetItemGlyphBounds(m_inventorySlotRecord->itemId, &glyphBounds);

        const int glyphWidth = glyphBounds.right - glyphBounds.left;
        const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
        if (glyphWidth < 43) {
            imageBounds.left += (43 - glyphWidth) / 2;
        }
        if (glyphHeight < 43) {
            imageBounds.top += (43 - glyphHeight) / 2;
        }

        g_pItemObjImageLib->DrawItemImage(
            this, &imageBounds,
            m_inventorySlotRecord->itemId,
            m_inventorySlotRecord->iconStyle,
            NULL, 0.0f);

        swprintf_s(
            slotText, 128, L"%c",
            SlotIndexToHotkeyLetter(m_inventorySlot));
        MoveTo(m_drawX + 1, m_drawY + 11);
        SetTextColor(12);
        DrawWideText(slotText, wcslen(slotText));
        MoveTo(m_drawX, m_drawY + 11);
        DrawWideText(slotText, wcslen(slotText));
    }
}

// UID:0004V7 | by-memory/0x004c7f00-0x004c7f4e.WillBeChangedItemPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool WillBeChangedItemPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp) {
        MarkForDeletion();
    } else if (event->m_type == kEventCursorMove) {
        m_origin.y +=
            event->m_payload.m_pointer.m_y - m_initialPointerY;
        m_origin.x +=
            event->m_payload.m_pointer.m_x - m_initialPointerX;
        InvalidateRect(&m_visibleBounds);
    }

    return false;
}

// UID:0004V8 | by-memory/0x004c7f50-0x004c7f8f.WillBeChangedItemPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool WillBeChangedItemPane::HandleKeyOrTextEvent(Event *event)
{
    const char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (event->m_type == kEventKeyDown && key != 'i') {
        MarkForDeletion();
    }

    return false;
}

// UID:0000G6 | by-class/WillBeChangedSpellPane.md | Completion:92 | Confidence:94
// UID:0004V9 | by-memory/0x004c7f90-0x004c80c0.WillBeChangedSpellPaneConstructor.md | Completion:91 | Confidence:94
WillBeChangedSpellPane::WillBeChangedSpellPane(
    Pane *owner,
    char spellSlot,
    int y,
    int x,
    int pointerY,
    int pointerX)
    : Pane(1)
{
    (void)owner;

    RectBounds paneBounds;
    RectBounds screenBounds;

    m_spellRecord =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    m_spellSlot = spellSlot;
    m_initialPointerY = pointerY;
    m_initialPointerX = pointerX;

    InitRectBounds(&paneBounds, 0, 0, 160, GetLineHeight());
    AddToLayer(
        &paneBounds, 0, 0,
        g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);
    m_origin.y = y;
    m_origin.x = x;

    GetScreenBounds(&screenBounds);
    m_initialPointerY -= screenBounds.top;
    m_initialPointerX -= screenBounds.left;
    m_drawY = y - screenBounds.top;
    m_drawX = x - screenBounds.left;
}

// UID:0004VA | by-memory/0x004c80c0-0x004c80df.WillBeChangedSpellPaneDestructor.md | Completion:92 | Confidence:94
WillBeChangedSpellPane::~WillBeChangedSpellPane()
{
}

// UID:0004VB | by-memory/0x004c80e0-0x004c8244.WillBeChangedSpellPaneOnPaintFrame.md | Completion:92 | Confidence:94
void WillBeChangedSpellPane::OnPaintFrame()
{
    RectBounds textBounds;
    wchar_t text[128];

    GetBounds(&textBounds);
    swprintf_s(
        text, 128, L"%c",
        SlotIndexToHotkeyLetter(m_spellSlot));

    SetTextColor(12);
    textBounds.Offset(1, 0);
    DrawTextInRect(text, wcslen(text), &textBounds);
    SetTextColor(12);
    textBounds.Offset(-1, 0);
    DrawTextInRect(text, wcslen(text), &textBounds);

    textBounds.left += 25;
    textBounds.right = 160;
    swprintf_s(text, 128, L"%s", m_spellRecord->displayName);
    SetTextColor(143);
    DrawTextInRect(text, wcslen(text), &textBounds);
}

// UID:0004VC | by-memory/0x004c8250-0x004c828a.WillBeChangedSpellPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool WillBeChangedSpellPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp) {
        MarkForDeletion();
    } else if (event->m_type == kEventCursorMove) {
        m_origin.y +=
            event->m_payload.m_pointer.m_y - m_initialPointerY;
        m_origin.x +=
            event->m_payload.m_pointer.m_x - m_initialPointerX;
    }

    return false;
}

// UID:0004VD | by-memory/0x004c8290-0x004c82cf.WillBeChangedSpellPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool WillBeChangedSpellPane::HandleKeyOrTextEvent(Event *event)
{
    const char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (event->m_type == kEventKeyDown && key != '+') {
        MarkForDeletion();
    }

    return false;
}

// UID:0000R9 | by-global/g_pItemHelpPane.md | Completion:92 | Confidence:94
ItemHelpPane *g_pItemHelpPane = NULL;

// UID:0000S9 | by-global/g_pSimpleHelpPane.md | Completion:87 | Confidence:90
SimpleHelpPane *g_pSimpleHelpPane = NULL;

// UID:0001PC | by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md | Completion:87 | Confidence:90
// Emitted declaration for this singleton storage is covered by [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md).

// UID:0000SA | by-global/g_pSimpleHelpPane2.md | Completion:92 | Confidence:94
SimpleHelpPane2 *g_pSimpleHelpPane2 = NULL;

// UID:0001OY | by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md | Completion:90 | Confidence:94
// Emitted definition for this singleton storage is covered by [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md).

// UID:0000SS | by-global/g_pWillBeChangedItemPane.md | Completion:92 | Confidence:94
WillBeChangedItemPane *g_pWillBeChangedItemPane = NULL;

[[No Children Attached]]

// UID:000228 | by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md | Completion:88 | Confidence:93
static void CloseItemHelpPaneSingleton();
static void CloseSimpleHelpPaneSingleton();

static void CloseItemHelpPaneSingleton()
{
    delete g_pItemHelpPane;
}

static void CloseSimpleHelpPaneSingleton()
{
    delete g_pSimpleHelpPane;
}

// UID:00016T | by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md | Completion:90 | Confidence:92
static SimpleHelpPane2 *CreateSimpleHelpPane2(
    const wchar_t *text,
    Pane *owner,
    int x,
    int y,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const FontStyle *style)
{
    SimpleHelpPane2 *pane = g_pSimpleHelpPane2;
    if (pane != 0)
    {
        if (pane->m_preventReplacement)
            return pane;

        delete pane;
    }

    new SimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                        horizontalAlign, verticalAlign, style);
    return g_pSimpleHelpPane2;
}

// UID:00022O | by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md | Completion:90 | Confidence:92
static SimpleHelpPane2 *CreateSimpleHelpPane2Forward(
    const wchar_t *text,
    Pane *owner,
    int y,
    int x,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const FontStyle *style)
{
    return CreateSimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                                 horizontalAlign, verticalAlign, style);
}

static SimpleHelpPane2 *CreateSimpleHelpPane2FromAnchorRect(
    const wchar_t *text,
    Pane *owner,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const FontStyle *style)
{
    const int x = (anchorRect->left + anchorRect->right) / 2;
    const int y = anchorRect->top - 6;

    return CreateSimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                                 horizontalAlign, verticalAlign, style);
}

bool SimpleHelpPane2::IsCursorInsideAnchorRect()
{
    Point cursor;
    g_pEventMan->GetCursorPosition(&cursor);

    Point screenOffset;
    GetScreenOffset(&screenOffset);

    RectBounds anchorRect = m_anchorRect;
    anchorRect.Offset(screenOffset.x, screenOffset.y);

    if (m_anchorRect.IsEmptyOrInvalid())
        return true;

    return PointInRect(cursor.y, cursor.x, &anchorRect);
}
