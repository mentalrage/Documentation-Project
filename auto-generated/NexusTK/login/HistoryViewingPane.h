// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JW
// Source by-file doc: by-file/HistoryViewingPane.md
// UID:00054J | by-item/HistoryViewingPaneFileShell.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H
#define NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H

// UID:000066 | by-class/HistoryViewingPane.md | Completion:93 | Confidence:95
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;

class HistoryViewingPane : public Pane,
                           public Singleton<HistoryViewingPane>
{
public:
    explicit HistoryViewingPane(const wchar_t *resourceName);

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void AdvancePage();

    int m_frameIndex;
    int m_lastFrameIndex;
    unsigned int m_pageDelayMs;
    mystr::StringBase<wchar_t> m_resourceName;
};

typedef char HistoryViewingPaneSizeMustBe264[
    sizeof(HistoryViewingPane) == 0x108 ? 1 : -1];

// UID:0000R3 | by-global/g_pHistoryViewingPane.md | Completion:92 | Confidence:94
extern HistoryViewingPane *g_pHistoryViewingPane;

#endif
