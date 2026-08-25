// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ID
// Source by-file doc: by-file/CommandInputPanes.md
// UID:00004B | by-class/EmotionInputPane.md | Completion:91 | Confidence:93
#pragma once

#include "InputPanes.h"

class EmotionInputPane : public CharInputPane
{
public:
    EmotionInputPane();
    virtual void OnAccept();
};

// UID:00005W | by-class/GroupInputPane.md | Completion:91 | Confidence:93
class GroupInputPane : public LineInputPane
{
public:
    GroupInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kGroupPromptStringId = 0x2f;
};

// UID:0000AO | by-class/PostInputPane.md | Completion:92 | Confidence:94
class PostInputPane : public CharInputPane
{
public:
    PostInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnConfirmInput();
};
