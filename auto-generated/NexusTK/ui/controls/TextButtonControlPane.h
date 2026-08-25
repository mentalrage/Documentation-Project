// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OK
// Source by-file doc: by-file/TextButtonControlPane.md
// UID:0000EJ | by-class/TextButtonControlPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_CONTROLS_TEXTBUTTONCONTROLPANE_H
#define NEXUSTK_UI_CONTROLS_TEXTBUTTONCONTROLPANE_H

#include "ButtonControlPane.h"

class TextButtonControlPane : public ButtonControlPane
{
public:
    TextButtonControlPane(const wchar_t *text, const RectBounds *bounds);
    virtual ~TextButtonControlPane();

    virtual short GetText(wchar_t *destination, short maxCharacters);

protected:
    virtual void OnPaint();

    wchar_t *m_text;
};

typedef char TextButtonControlPaneSizeMustBe272[
    sizeof(TextButtonControlPane) == 0x110 ? 1 : -1];

#endif
