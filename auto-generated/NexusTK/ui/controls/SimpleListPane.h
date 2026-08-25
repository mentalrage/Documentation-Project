// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NQ
// Source by-file doc: by-file/SimpleListPane.md
// UID:0000D8 | by-class/SimpleListPane.md | Completion:94 | Confidence:93
#ifndef NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H
#define NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H

#include "ListPane.h"

struct RectBounds;

class SimpleListPane : public ListPane
{
public:
    SimpleListPane(int /*unused*/, const RectBounds *bounds);
    virtual ~SimpleListPane();

    void AppendText(const wchar_t *text);
    void InsertText(int index, const wchar_t *text);
    void RemoveText(int index);
    void ReplaceText(int index, const wchar_t *text);
};

#endif // NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H
