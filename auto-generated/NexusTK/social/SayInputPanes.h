// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N9
// Source by-file doc: by-file/SayInputPanes.md
// UID:000099 | by-class/NewSayToUserMessageInputPane.md | Completion:93 | Confidence:94
#pragma once

#include "../ui/dialogs/InputPanes.h"

class NewSayToUserMessageInputPane : public LineInputPane
{
public:
    explicit NewSayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_recipientName[128];
};

// UID:0000C6 | by-class/SayToUserMessageInputPane.md | Completion:93 | Confidence:94
class SayToUserMessageInputPane : public LineInputPane
{
public:
    explicit SayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_recipientName[128];
};

// UID:0000C4 | by-class/SayToGroupMessageInputPane.md | Completion:93 | Confidence:94
class SayToGroupMessageInputPane : public LineInputPane
{
public:
    explicit SayToGroupMessageInputPane(const wchar_t *groupName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_groupName[128];
};

// UID:0000C5 | by-class/SayToPlanMessageInputPane.md | Completion:93 | Confidence:94
class SayToClanMessageInputPane : public LineInputPane
{
public:
    explicit SayToClanMessageInputPane(const wchar_t *clanName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_clanName[128]; // +0x108
};

// UID:0000C3 | by-class/SayInputPane.md | Completion:93 | Confidence:94
class SayInputPane : public LineInputPane
{
public:
    SayInputPane();
    explicit SayInputPane(const wchar_t *initialText);

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_chatHistoryCursor;
};

// UID:0000C7 | by-class/SayToUserNameInputPane.md | Completion:94 | Confidence:95
class SayToUserNameInputPane : public LineInputPane
{
public:
    SayToUserNameInputPane();

protected:
    virtual void OnSubmitInput();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    short m_recentRecipientHistoryIndex;
    short m_fallbackRecipientHistoryIndex;
};

// UID:0000D5 | by-class/ShoutInputPane.md | Completion:93 | Confidence:94
class ShoutInputPane : public LineInputPane
{
public:
    ShoutInputPane();

protected:
    virtual void OnSubmitInput();
};
