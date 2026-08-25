// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OQ
// Source by-file doc: by-file/TextPad.md
// UID:0000EU | by-class/TextPad.md | Completion:94 | Confidence:93
#pragma once

#include "../core/DialogPane.h"

class Event;

class TextPad : public DialogPane
{
public:
    TextPad();
    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    void SendText(const wchar_t *commandLine);
    void Open(const wchar_t *path);
    void Save(const wchar_t *path);
    void SetFont(unsigned short fontId);
    void SetColor(unsigned int color);
};
