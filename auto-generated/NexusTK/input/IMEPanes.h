// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K5
// Source by-file doc: by-file/IMEPanes.md
// UID:00006F | by-class/IMECandidatePane.md | Completion:92 | Confidence:94
#pragma once

#include "../ui/core/Pane.h"

#include <deque>
#include <string>

class Event;
class IMEPane;

typedef std::deque<std::wstring> CandidateStringList;

class IMECandidatePane : public Pane
{
    friend class IMEPane;

public:
    IMECandidatePane();
    virtual ~IMECandidatePane();

    void ShowCandidateList(const Event *event);

protected:
    virtual bool HandleIMEMessage(const Event *event);
    virtual void OnPaint();

private:
    CandidateStringList visibleCandidates;  // +0xf8, display-side visible candidate strings.
    int selectedCandidateRow;               // +0x10c, selected row within the visible page.
    int candidateAnchorY;                   // +0x110, top anchor copied from the root IME pane.
    int candidateAnchorX;                   // +0x114, left anchor copied from the root IME pane.
};

typedef char IMECandidatePaneSizeMustBe280[
    sizeof(IMECandidatePane) == 0x118 ? 1 : -1];

[[No Children Attached]]

// UID:00006G | by-class/IMECompositionPane.md | Completion:90 | Confidence:92
#include "../ui/core/Pane.h"

class Event;
class IMEPane;

class IMECompositionPane : public Pane
{
public:
    IMECompositionPane();
    virtual ~IMECompositionPane();

    void SetCompositionString(const wchar_t *text, int length);
    int GetCompositionWidth() const;

protected:
    virtual bool OnMouseEvent(const Event *event);
    virtual bool OnKeyEvent(const Event *event);
    virtual void OnPaint();

private:
    int compositionCursorX;                  // +0xf8
    wchar_t compositionText[256];            // +0xfc
    bool compositionDragActive;              // +0x2fc
    int compositionDragStartY;               // +0x300
    int compositionDragStartX;               // +0x304
    unsigned char compositionDragSavedMode;  // +0x308
};

typedef char IMECompositionPaneSizeMustBe780[
    sizeof(IMECompositionPane) == 0x30c ? 1 : -1];

[[No Children Attached]]

// UID:00006H | by-class/IMEPane.md | Completion:91 | Confidence:94
#include "../ui/core/Pane.h"
#include "../util/List.h"

class Event;
class IMECandidatePane;
class IMECompositionPane;
class IMEStatusPane;

class IMEPane : public Pane
{
    friend class IMECandidatePane;
    friend class IMECompositionPane;

public:
    IMEPane();
    virtual ~IMEPane();

    void SetFocusPane(Pane *pane, bool focused);
    bool IsIMESupported(const Event *event);
    bool HandleIMEMessage(const Event *event);

private:
    void UpdateFocusCaretAnchor();

    IMEStatusPane *statusPane;
    Pane *activeChildPane;
    IMECandidatePane *candidatePane;
    List focusPaneList;
    int focusCaretAnchorY;
    int focusCaretAnchorX;
};

extern IMEPane *g_pIMEPane;

typedef char IMEPaneSizeMustBe288[
    sizeof(IMEPane) == 0x120 ? 1 : -1];

[[No Children Attached]]
