// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OK
// Source by-file doc: by-file/TextButtonControlPane.md
// UID:0000EJ | by-class/TextButtonControlPane.md | Completion:94 | Confidence:95
#include "TextButtonControlPane.h"
#include <wchar.h>
#include "../../util/MemoryMan.h"

TextButtonControlPane::TextButtonControlPane(const wchar_t *text,
                                             const RectBounds *bounds)
    : ButtonControlPane(*bounds)
{
    MemoryMan *memoryMan = GetMemoryMan();
    const size_t byteCount = (wcslen(text) + 1) * sizeof(wchar_t);

    m_text = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory(byteCount));
    memoryMan->MemmoveWrapper(m_text, text, byteCount);
}

TextButtonControlPane::~TextButtonControlPane()
{
    if (m_text != 0) {
        m_text = static_cast<wchar_t *>(
            GetMemoryMan()->FreeBufferMemory(m_text));
    }
}

short TextButtonControlPane::GetText(wchar_t *destination,
                                     short maxCharacters)
{
    short copied = maxCharacters;
    const short textLength = static_cast<short>(wcslen(m_text));
    if (copied > textLength) {
        copied = textLength;
    }

    GetMemoryMan()->MemmoveWrapper(destination, m_text, copied);
    destination[copied] = L'\0';
    return copied;
}

void TextButtonControlPane::OnPaint()
{
    const unsigned int kNormalTopLeftColor = 192;
    const unsigned int kNormalBottomRightColor = 200;
    const unsigned int kPressedTopLeftColor = 200;
    const unsigned int kPressedBottomRightColor = 192;
    const unsigned int kButtonFillColor = 196;
    const unsigned int kEnabledTextColor = 128;
    const unsigned int kDisabledTextColor = 134;
    const unsigned char kPressedVisualState = 11;
    const int kLabelHalfHeight = 6;

    const bool pressed = (m_visualState == kPressedVisualState);
    const unsigned int topLeftColor =
        pressed ? kPressedTopLeftColor : kNormalTopLeftColor;
    const unsigned int bottomRightColor =
        pressed ? kPressedBottomRightColor : kNormalBottomRightColor;
    const unsigned int textColor =
        m_enabled ? kEnabledTextColor : kDisabledTextColor;

    RectBounds frame = m_visibleBounds;

    SetDrawColor(kButtonFillColor);
    FillRect(&frame);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    InsetRect(&frame, 1, 1);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    RectBounds textRect = m_visibleBounds;
    const int textCenterY = (textRect.top + textRect.bottom) / 2;
    textRect.top = textCenterY - kLabelHalfHeight;
    textRect.bottom = textCenterY + kLabelHalfHeight;

    if (pressed) {
        OffsetRect(&textRect, 1, 1);
    }

    SetTextColor(textColor);
    m_textDrawMode = 1;
    m_textAlign = 1;
    DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), &textRect);

    if (m_enabled && m_controlSelected) {
        SetDrawColor(1);
        m_drawMode = 0;
        DrawRectFrame(&m_visibleBounds);
    }

    if (m_enabled && m_controlActive) {
        SetDrawColor(128);
        m_drawMode = 0;
        DrawRectFrame(&m_visibleBounds);
    }
}

// UID:0002YE | by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md).
