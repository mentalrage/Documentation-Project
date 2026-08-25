// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K5
// Source by-file doc: by-file/IMEPanes.md
// UID:00006F | by-class/IMECandidatePane.md | Completion:92 | Confidence:94
#include "IMEPanes.h"
#include "InputMan.h"
#include "../ui/core/Event.h"

// UID:00018B | by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md | Completion:89 | Confidence:91
void IMECandidatePane::ShowCandidateList(const Event *event)
{
    const CandidateStringList *candidateStrings = event->imeCandidateStrings;
    const int selectedRow = event->imeCandidateSelectedRow;

    int maxTextWidth = 0;
    int popupHeight = 4;
    const int lineStep = GetLineHeight() + 2;

    for (CandidateStringList::const_iterator it = candidateStrings->begin();
         it != candidateStrings->end();
         ++it) {
        const std::wstring &candidate = *it;
        const int textWidth = MeasureTextWidth(candidate.c_str(), static_cast<int>(candidate.length()));
        if (maxTextWidth < textWidth) {
            maxTextWidth = textWidth;
        }
        popupHeight += lineStep;
    }

    RectBounds popupRect;
    popupRect.left = candidateAnchorX;
    popupRect.top = candidateAnchorY;
    popupRect.right = candidateAnchorX + maxTextWidth + 6;
    popupRect.bottom = candidateAnchorY + popupHeight;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    if (popupRect.right >= screenWidth) {
        TranslateRectBounds(&popupRect, screenWidth - popupRect.right, 0);
    }

    if (popupRect.bottom >= screenHeight) {
        if (g_pIMEPane->activeChildPane != NULL) {
            RectBounds activeChildRect;
            g_pIMEPane->activeChildPane->GetBounds(&activeChildRect);
            TranslateRectBounds(&popupRect, 0, activeChildRect.top - popupRect.bottom - 8);
        } else {
            TranslateRectBounds(&popupRect, 0, screenHeight - popupRect.bottom);
        }
    }

    if (popupRect.left < 0) {
        TranslateRectBounds(&popupRect, -popupRect.left, 0);
    }

    SetBounds(&popupRect, 0);

    visibleCandidates.assign(candidateStrings->begin(), candidateStrings->end());
    selectedCandidateRow = selectedRow;
    Invalidate(&bounds);
}

// UID:0004C7 | by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md | Completion:88 | Confidence:91
IMECandidatePane::IMECandidatePane()
    : Pane(0)
{
    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_pIMEPaneLayer);

    selectedCandidateRow = -1;

    if (g_pIMEPane->activeChildPane != NULL) {
        RectBounds activeChildBounds;
        g_pIMEPane->activeChildPane->GetBounds(&activeChildBounds);

        IMECompositionPane *compositionPane =
            static_cast<IMECompositionPane *>(g_pIMEPane->activeChildPane);
        candidateAnchorX = activeChildBounds.left + compositionPane->GetCompositionWidth();
        candidateAnchorY = activeChildBounds.bottom + 4;
    } else {
        candidateAnchorX = 4;
        candidateAnchorY = 4;
    }
}

// UID:00031F | by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md | Completion:91 | Confidence:94
IMECandidatePane::~IMECandidatePane()
{
    // CandidateStringList member storage and Pane base state are destroyed by normal C++ teardown.
}

// UID:0004C8 | by-memory/0x004e7d00-0x004e7d24.IMECandidatePaneHandleIMEMessage.md | Completion:88 | Confidence:91
bool IMECandidatePane::HandleIMEMessage(const Event *event)
{
    if (event->m_type != kEventImeCandidateList) {
        return false;
    }

    ShowCandidateList(event);
    return true;
}

// UID:0004C9 | by-memory/0x004e7d30-0x004e7f1a.IMECandidatePaneOnPaint.md | Completion:88 | Confidence:90
void IMECandidatePane::OnPaint()
{
    SetDrawColor(143);
    FillRect(&bounds);

    SetDrawColor(128);
    DrawRectFrame(&bounds);

    SetTextColor(128);

    const int lineHeight = GetLineHeight();
    const int rowStep = lineHeight + 2;
    int textY = rowStep;
    int row = 0;

    for (CandidateStringList::const_iterator it = visibleCandidates.begin();
         it != visibleCandidates.end();
         ++it, ++row) {
        const std::wstring& candidate = *it;

        MoveTo(1, textY);

        if (row == selectedCandidateRow) {
            RectBounds selectedRowBounds;
            selectedRowBounds.left = 1;
            selectedRowBounds.top = row * rowStep + 2;
            selectedRowBounds.right = bounds.right - bounds.left;
            selectedRowBounds.bottom = selectedRowBounds.top + lineHeight + 1;

            FillRect(&selectedRowBounds);

            SetTextColor(143);
            DrawWideText(candidate.c_str(), static_cast<int>(candidate.length()));
            SetTextColor(128);
        } else {
            DrawWideText(candidate.c_str(), static_cast<int>(candidate.length()));
        }

        textY += rowStep;
    }
}

// UID:00006G | by-class/IMECompositionPane.md | Completion:90 | Confidence:92
#include "IMEPanes.h"
#include "../ui/core/Event.h"

// UID:0004C1 | by-memory/0x004e7380-0x004e744d.IMECompositionPaneConstructor.md | Completion:88 | Confidence:91
IMECompositionPane::IMECompositionPane()
    : Pane(0)
{
    compositionCursorX = 0;
    memset(compositionText, 0, sizeof(compositionText));
    compositionDragActive = false;

    RectBounds initialBounds;
    InitRectBounds(&initialBounds, 0, 0, 0, 0);
    AddToLayer(&initialBounds, 0, NULL, g_pIMEPaneLayer);
    SetPaneOrder(NULL, NULL);
}

// UID:0004C2 | by-memory/0x004e7450-0x004e746f.IMECompositionPaneOrdinaryDestructor.md | Completion:88 | Confidence:91
IMECompositionPane::~IMECompositionPane()
{
}

// UID:00018A | by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md | Completion:90 | Confidence:92
void IMECompositionPane::SetCompositionString(const wchar_t *text, int length)
{
    if (length > 255) {
        length = 255;
    }

    const int popupTextWidth = MeasureTextWidth(text, length);
    const int lineHeight = GetLineHeight();

    IMEPane *imePane = g_pIMEPane;
    imePane->UpdateFocusCaretAnchor();

    const int anchorX = imePane->focusCaretAnchorX;
    const int anchorY = imePane->focusCaretAnchorY;

    RectBounds popupRect;
    popupRect.left = anchorX;
    popupRect.top = anchorY;
    popupRect.right = (popupTextWidth > 0) ? anchorX + popupTextWidth + 4 : anchorX;
    popupRect.bottom = anchorY + lineHeight + 4;

    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    if (popupRect.right >= screenWidth) {
        TranslateRectBounds(&popupRect, screenWidth - popupRect.right, 0);
    }
    if (popupRect.top >= screenHeight) {
        TranslateRectBounds(&popupRect, 0, screenHeight - popupRect.bottom);
    }
    if (popupRect.left < 0) {
        TranslateRectBounds(&popupRect, -popupRect.left, 0);
    }
    if (popupRect.top < 0) {
        TranslateRectBounds(&popupRect, 0, -popupRect.top);
    }

    SetBounds(&popupRect, 0);

    wcsncpy_s(compositionText, 256, text, length);
    compositionText[length] = 0;

    compositionCursorX = MeasureTextWidth(compositionText, GetCompositionCursorPosition()) + 3;
    Invalidate(&bounds);
}

// UID:0004C3 | by-memory/0x004e7640-0x004e7809.IMECompositionPaneOnMouseEvent.md | Completion:88 | Confidence:91
bool IMECompositionPane::OnMouseEvent(const Event *event)
{
    switch (event->type) {
    case kEventCursorMove:
        if (!compositionDragActive) {
            return false;
        }

        {
            RectBounds dragBounds;
            GetBounds(&dragBounds);
            TranslateRectBounds(&dragBounds, event->mouseX - compositionDragStartX, 0);
            TranslateRectBounds(&dragBounds, 0, event->mouseY - compositionDragStartY);
            SetBounds(&dragBounds, 0);

            g_pIMEPane->focusCaretAnchorX = dragBounds.left;
            g_pIMEPane->focusCaretAnchorY = dragBounds.top;
        }
        return true;

    case kEventLeftButtonDown:
        if (compositionDragActive) {
            return false;
        }

        if (!PointInRect(event->mouseY, event->mouseX, &m_bounds)) {
            return false;
        }

        compositionDragActive = true;
        compositionDragStartY = event->mouseY;
        compositionDragStartX = event->mouseX;
        compositionDragSavedMode = m_mode;

        if (compositionDragSavedMode == 2) {
            SetMode(0);
        } else if (compositionDragSavedMode == 3) {
            SetMode(1);
        }
        return true;

    case kEventLeftButtonUp:
        if (!compositionDragActive) {
            return false;
        }

        g_pIMEPane->focusCaretAnchorY = m_origin.y;
        g_pIMEPane->focusCaretAnchorX = m_origin.x;
        SetMode(compositionDragSavedMode);
        compositionDragActive = false;
        return true;

    default:
        return false;
    }
}

// UID:0004C4 | by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md | Completion:88 | Confidence:91
bool IMECompositionPane::OnKeyEvent(const Event *event)
{
    if (event->type != kEventImeCompositionResult) {
        return false;
    }

    SetCompositionString(event->imeCompositionResultText,
                         event->imeCompositionResultLength);
    return true;
}

// UID:0004C5 | by-memory/0x004e7840-0x004e7912.IMECompositionPaneOnPaint.md | Completion:88 | Confidence:91
void IMECompositionPane::OnPaint()
{
    m_drawMode = 0;

    SetDrawColor(143);
    FillRect(&m_bounds);

    SetDrawColor(128);
    DrawRectFrame(&m_bounds);

    SetTextColor(128);
    MoveTo(m_bounds.left + 2, m_bounds.bottom - 2);

    const wchar_t *scan = compositionText;
    while (*scan != L'\0') {
        ++scan;
    }

    DrawWideText(compositionText, static_cast<int>(scan - compositionText));

    RectBounds caretRect;
    caretRect.left = compositionCursorX;
    caretRect.top = 2;
    caretRect.right = compositionCursorX + 1;
    caretRect.bottom = GetLineHeight() + 2;

    SetDrawColor(128);
    FillRect(&caretRect);
}

// UID:0004C6 | by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md | Completion:88 | Confidence:91
int IMECompositionPane::GetCompositionWidth() const
{
    return compositionCursorX;
}

// UID:00006H | by-class/IMEPane.md | Completion:91 | Confidence:94
#include "IMEPanes.h"

// UID:0004CA | by-memory/0x004e7f20-0x004e7ff5.IMEPaneConstructor.md | Completion:88 | Confidence:91
IMEPane::IMEPane()
    : Pane(4),
      focusPaneList(4, 4)
{
    g_pIMEPane = this;

    statusPane = NULL;
    activeChildPane = NULL;
    candidatePane = NULL;

    focusCaretAnchorY = 0;
    focusCaretAnchorX = 0;

    SetPaneOrder(NULL, NULL);
}

// UID:0004CB | by-memory/0x004e8000-0x004e8098.IMEPaneOrdinaryDestructor.md | Completion:91 | Confidence:94
IMEPane::~IMEPane()
{
    if (statusPane != NULL) {
        statusPane->MarkForDeletion();
    }

    if (activeChildPane != NULL) {
        activeChildPane->MarkForDeletion();
    }

    if (candidatePane != NULL) {
        candidatePane->MarkForDeletion();
    }

    g_pIMEPane = NULL;
}

// UID:0004CC | by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md | Completion:89 | Confidence:91
void IMEPane::SetFocusPane(Pane *pane, bool focused)
{
    const int focusPaneCount = focusPaneList.GetCount();
    for (int index = focusPaneCount - 1; index >= 0; --index) {
        Pane **entry = static_cast<Pane **>(focusPaneList.GetElementAt(index));
        if (*entry == pane) {
            focusPaneList.RemoveAt(index, 1);
            break;
        }
    }

    if (focused && pane != NULL) {
        focusPaneList.Append(1, &pane);
    }
}

// UID:00031G | by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md | Completion:91 | Confidence:93
void IMEPane::UpdateFocusCaretAnchor()
{
    const int focusPaneCount = focusPaneList.GetCount();
    if (focusPaneCount > 0) {
        TextEditPane *focusPane =
            *static_cast<TextEditPane **>(
                focusPaneList.GetElementAt(focusPaneCount - 1));

        short caretIndex;
        short caretEnd;
        focusPane->GetCaretRange(&caretIndex, &caretEnd);

        Point caretPoint;
        focusPane->GetCaretLocalPoint(&caretPoint, caretIndex);

        Point paneOrigin;
        focusPane->GetScreenOffset(&paneOrigin);

        focusCaretAnchorX = paneOrigin.x + caretPoint.x;
        focusCaretAnchorY = paneOrigin.y + caretPoint.y;
    } else {
        focusCaretAnchorX = 0;
        focusCaretAnchorY = 0;
    }
}

// UID:0004CD | by-memory/0x004e81a0-0x004e81a5.IMEPaneIsIMESupported.md | Completion:90 | Confidence:92
bool IMEPane::IsIMESupported(const Event * /*event*/)
{
    return true;
}

// UID:0004CE | by-memory/0x004e81b0-0x004e8433.IMEPaneHandleIMEMessage.md | Completion:89 | Confidence:91
bool IMEPane::HandleIMEMessage(const Event *event)
{
    switch (event->m_type) {
    case kEventImeCompositionStart:
        activeChildPane = new IMECompositionPane();
        return true;
    case kEventImeCompositionEnd:
        delete activeChildPane;
        activeChildPane = NULL;
        return true;
    case kEventImeCandidateList:
        if (candidatePane == NULL) {
            candidatePane = new IMECandidatePane();
        }
        candidatePane->HandleIMEMessage(event);
        return true;
    case kEventImeCandidateClose:
        delete candidatePane;
        candidatePane = NULL;
        return true;
    }
    return false;
}

// UID:00006I | by-class/IMEStatusPane.md | Completion:88 | Confidence:90
class Event;
class Pane;

class IMEStatusPane : public Pane
{
public:
    IMEStatusPane();
    virtual ~IMEStatusPane();

    void SetText(const wchar_t *text, int length);

protected:
    virtual bool OnIMEModeChange(const Event *event);
    virtual void OnPaintFrame();

private:
    wchar_t statusText[256];
};

// UID:0004BW | by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md | Completion:89 | Confidence:91
void IMEStatusPane::SetText(const wchar_t *text, int length)
{
    if (length > 255) {
        length = 255;
    }

    const int textWidth = MeasureTextWidth(text, length);
    const int lineHeight = GetLineHeight();
    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    RectBounds statusRect;
    statusRect.right = screenWidth;
    statusRect.bottom = screenHeight;
    statusRect.left = screenWidth;
    if (textWidth > 0) {
        statusRect.left -= textWidth + 4;
    }
    statusRect.top = screenHeight - lineHeight - 4;

    SetBounds(&statusRect, 0);

    wcsncpy_s(statusText, 256, text, length);
    statusText[length] = L'\0';

    Invalidate(&m_bounds);
}

// UID:0004BX | by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md | Completion:88 | Confidence:90
IMEStatusPane::IMEStatusPane()
    : Pane(0)
{
    RectBounds attachBounds;

    memset(statusText, 0, sizeof(statusText));
    InitRectBounds(&attachBounds, 0, 0, 0, 0);
    SetText(L"Closed", 6);
    AddToLayer(&attachBounds, 0, 0, g_pIMEPaneLayer);
    SetPaneOrder(0, 0);
}

// UID:0004BY | by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md | Completion:88 | Confidence:91
IMEStatusPane::~IMEStatusPane()
{
}

// UID:0004BZ | by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md | Completion:88 | Confidence:91
bool IMEStatusPane::OnIMEModeChange(const Event *event)
{
    if (event->m_type != kEventImeOpenStatus) {
        return false;
    }

    if (event->imeOpenStatus == 1) {
        SetText(L"IME", 4);
    } else {
        SetText(L"ENG", 6);
    }

    return true;
}

// UID:0004C0 | by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md | Completion:88 | Confidence:90
void IMEStatusPane::OnPaintFrame()
{
    m_drawMode = 0;

    SetDrawColor(0x8f);
    FillRect(&m_bounds);

    SetDrawColor(0x80);
    DrawRectFrame(&m_bounds);

    SetTextColor(0x80);
    MoveTo(m_bounds.left + 2, m_bounds.bottom - 2);

    int length = 0;
    while (statusText[length] != L'\0')
        ++length;

    DrawWideText(statusText, length);
}

// UID:0000R7 | by-global/g_pIMEPane.md | Completion:90 | Confidence:90
IMEPane *g_pIMEPane = NULL;

// UID:000189 | by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md | Completion:88 | Confidence:91
// Aggregate IME pane method-family range. Exact source bodies are owned by the
// method/class child pages listed below; this page preserves the source-order
// insertion point for the IMEPanes.cpp family.

[[No Children Attached]]

// UID:00025J | by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md | Completion:88 | Confidence:92
// Source-declared/generated-binary data proof for the IME pane RTTI/vtable island.
// The class declarations and status literals produce this read-only data; do not
// hand-author raw vtable arrays or duplicate Closed/IME/ENG outside the owning
// class/method source.
