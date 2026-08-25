// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K7
// Source by-file doc: by-file/InputPanes.md
// UID:000077 | by-class/LineInputPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UI_DIALOGS_INPUTPANES_H
#define NEXUSTK_UI_DIALOGS_INPUTPANES_H

#include "../core/Pane.h"

class Event;
class TextBoxPane;
class TextEditPane;
struct InputKeyEvent;
struct RectBounds;

class LineInputPane : public Pane
{
public:
    LineInputPane(const wchar_t *promptText);
    virtual ~LineInputPane();

    void SetPromptText(const wchar_t *promptText);
    void CopyText(wchar_t *buffer, short maxChars) const;
    short TextLength() const;

    virtual void UpdateChildLayout();
    virtual void AttachChildren();
    virtual void ShowChildren();
    virtual bool HitTestEditChild(int x, int y);
    virtual Pane *GetActiveChild();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool ForwardTextEditEvent(InputKeyEvent *event);
    virtual void OnNoOpInputPaneSlot();
    virtual void OnSubmitInput() {}

protected:
    TextBoxPane *m_promptTextPane;
    TextEditPane *m_textEditPane;
    int m_deferredSubmitPending;
    int m_deferSubmitUntilNextEvent;
};

// UID:00001O | by-class/CharArgsInputPane.md | Completion:92 | Confidence:94
class Event;

class CharArgsInputPane : public LineInputPane
{
public:
    CharArgsInputPane(const wchar_t *promptText);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

// UID:00001P | by-class/CharInputPane.md | Completion:92 | Confidence:94
class Event;

class CharInputPane : public LineInputPane
{
public:
    CharInputPane(const wchar_t *promptText);
    virtual ~CharInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnAccept() {}
};

#endif
