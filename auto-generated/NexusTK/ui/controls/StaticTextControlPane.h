// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O8
// Source by-file doc: by-file/StaticTextControlPane.md
// UID:0000E3 | by-class/StaticTextControlPane.md | Completion:91 | Confidence:93
#pragma once

#include "../core/ControlPane.h"

class TextEditPane;

class StaticTextControlPane : public ControlPane
{
public:
    StaticTextControlPane(const wchar_t *text,
                          bool useAlternateStyle,
                          int textColor,
                          int shadowColor,
                          const RectBounds *bounds,
                          bool useWideContentWidth,
                          bool inputMode);

    virtual unsigned char GetControlType(int, int);

private:
    unsigned short m_textStateFlags;
    TextEditPane *m_textEditPane;
    unsigned char m_savedTextPaneState;
};
