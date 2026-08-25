// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OO
// Source by-file doc: by-file/TextFilter.md
// UID:0000EQ | by-class/TextFilter.md | Completion:92 | Confidence:95
#ifndef NEXUSTK_UI_CONTROLS_TEXTFILTER_H
#define NEXUSTK_UI_CONTROLS_TEXTFILTER_H

#include "../../util/Singleton.h"

class TextFilter : public Singleton<TextFilter>
{
public:
    TextFilter();
    virtual ~TextFilter();
};

extern TextFilter *g_pTextFilter;

void __stdcall SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);

#endif
