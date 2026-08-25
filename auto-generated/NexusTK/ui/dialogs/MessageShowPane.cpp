// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LB
// Source by-file doc: by-file/MessageShowPane.md
// UID:0000RK | by-global/g_pMessageShowPane.md | Completion:92 | Confidence:94
class MessageShowPane;
MessageShowPane *g_pMessageShowPane = NULL;

// UID:000087 | by-class/MessageShowPane.md | Completion:92 | Confidence:94
class MessageShowPane;
extern MessageShowPane *g_pMessageShowPane;

class MessageShowPane : public Pane,
                        public Singleton<MessageShowPane>
{
public:
    explicit MessageShowPane(wchar_t *messageText);
    virtual ~MessageShowPane();

protected:
    virtual void OnPaint();

public:
    void SetWrappedText(wchar_t *messageText);

private:
    wchar_t m_messageText[0x8000];
    int m_lineCount;
    int m_wrappedLineCount;
    int m_maxTextWidth;
};

// UID:0004HN | by-memory/0x00521da0-0x00521fc0.MessageShowPaneConstructor.md | Completion:92 | Confidence:94
MessageShowPane::MessageShowPane(wchar_t *messageText)
    : Pane(1),
      Singleton<MessageShowPane>(),
      m_lineCount(0),
      m_wrappedLineCount(0),
      m_maxTextWidth(0)
{
    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = GetTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = GetTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    if (m_maxTextWidth > 288)
        m_maxTextWidth = 288;

    RectBounds bounds;
    bounds.left = 806 - m_maxTextWidth;
    bounds.top = 10;
    bounds.right = 809;
    bounds.bottom = 3 * (m_lineCount + 4 * m_wrappedLineCount + 3);
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
}

// UID:000492 | by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md | Completion:92 | Confidence:94
MessageShowPane::~MessageShowPane()
{
    RemoveFromLayer();
}

// UID:0004HO | by-memory/0x00522030-0x00522530.MessageShowPaneOnPaint.md | Completion:92 | Confidence:94
void MessageShowPane::OnPaint()
{
    RectBounds lineBounds;
    GetBounds(&lineBounds);
    SetDrawColor(0);
    FillRect(&lineBounds);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, m_messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;

        const int lineWidth = GetTextWidth(lineStart);
        const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;
        const int textLength = static_cast<int>(wcslen(lineStart));

        RectBounds textBounds = lineBounds;
        textBounds.right -= 3;
        textBounds.bottom = textBounds.top + lineAdvance + 2;

        SetTextColor(143);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(-2, 1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(3, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(-2, 1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);

        SetTextColor(128);
        textBounds.Offset(-1, -1);
        DrawTextInRect(lineStart, textLength, &textBounds);
        textBounds.Offset(1, 0);
        DrawTextInRect(lineStart, textLength, &textBounds);

        lineBounds.Offset(0, lineAdvance + 3);
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    const int lineWidth = GetTextWidth(lineStart);
    const int lineAdvance = 12 * ((lineWidth - 1) / 288) + 12;
    const int textLength = static_cast<int>(wcslen(lineStart));

    RectBounds textBounds = lineBounds;
    textBounds.right -= 3;
    textBounds.bottom = textBounds.top + lineAdvance + 2;

    SetTextColor(143);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(-2, 1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(3, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(-2, 1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);

    SetTextColor(128);
    textBounds.Offset(-1, -1);
    DrawTextInRect(lineStart, textLength, &textBounds);
    textBounds.Offset(1, 0);
    DrawTextInRect(lineStart, textLength, &textBounds);
}

// UID:0001C4 | by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md | Completion:92 | Confidence:94
void MessageShowPane::SetWrappedText(wchar_t *messageText)
{
    RemoveFromLayer();

    m_lineCount = 0;
    m_wrappedLineCount = 0;
    m_maxTextWidth = 0;

    wcscpy_s(m_messageText, 0x8000, messageText);

    wchar_t textCopy[0x8000];
    wcscpy_s(textCopy, 0x8000, messageText);

    wchar_t *lineStart = textCopy;
    wchar_t *lineEnd = wcsstr(lineStart, g_wszNewline);
    while (lineEnd != NULL)
    {
        *lineEnd = 0;
        ++m_lineCount;
        ++m_wrappedLineCount;

        const int lineWidth = GetTextWidth(lineStart);
        if (m_maxTextWidth < lineWidth)
            m_maxTextWidth = lineWidth;

        m_wrappedLineCount += (lineWidth - 1) / 288;
        lineStart = lineEnd + 1;
        lineEnd = wcsstr(lineStart, g_wszNewline);
    }

    ++m_lineCount;
    ++m_wrappedLineCount;

    const int finalLineWidth = GetTextWidth(lineStart);
    if (m_maxTextWidth < finalLineWidth)
        m_maxTextWidth = finalLineWidth;

    m_wrappedLineCount += (finalLineWidth - 1) / 288;

    if (m_maxTextWidth > 288)
        m_maxTextWidth = 288;

    RectBounds bounds;
    bounds.left = 806 - m_maxTextWidth;
    bounds.top = 10;
    bounds.right = 809;
    bounds.bottom = 3 * (m_lineCount + 4 * m_wrappedLineCount + 3);
    AddToLayer(&bounds, 0, 0, g_pRenderLayer1);
    InvalidateRect(&m_visibleBounds);
}
