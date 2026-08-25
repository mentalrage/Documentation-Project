// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LH
// Source by-file doc: by-file/ModelessDialogPane.md
// UID:00008K | by-class/ModelessDialogPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H
#define NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H

#include "DialogPane.h"

class Event;

class ModelessDialogPane : public DialogPane
{
public:
    ModelessDialogPane(const wchar_t *titleText);
    virtual bool IsModal();
    virtual bool HandlePointerOrMouseEvent(Event *event);
};

#endif
