// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NZ
// Source by-file doc: by-file/SpelledPane.md
// UID:0000DK | by-class/SpelledPane.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UI_PANELS_SPELLEDPANE_H
#define NEXUSTK_UI_PANELS_SPELLEDPANE_H

#include <vector>
#include "../../util/StringBase.h"
#include "../core/FrameMgr.h"
#include "../controls/TextEditPane.h"

class Event;
struct FrameUpdateContext;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > WideString;

struct SpelledPaneEntry
{
    WideString text;
    int value;
    int group;
};

class SpelledPane : public TextEditPane, public FrameHandler
{
public:
    SpelledPane();
    SpelledPane(int viewportWidth,
                int viewportHeight,
                int textAreaWidth,
                int textAreaHeight);
    virtual ~SpelledPane()
    {
    }

    void DeleteLine(short lineIndex);
    void AddOrUpdateEntry(const wchar_t *text, int value, int group);
    void RemoveEntry(const wchar_t *text, int group);
    void ParseAndLoadEntries(const wchar_t *text, int length);

    void RefreshScrollState()
    {
        RemoveFrame();
        ScheduleNextFrame();
    }

protected:
    virtual bool OnMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnFrameUpdate(const FrameUpdateContext *context);

private:
    void RebuildDisplayText();

    std::vector<SpelledPaneEntry> m_entries;
};

#endif
