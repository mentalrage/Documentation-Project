// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MX
// Source by-file doc: by-file/QuitDialogs.md
// UID:0000BG | by-class/QuitDialog.md | Completion:89 | Confidence:92
#pragma once

#include "AlertPanes.h"

struct InputEvent;

class QuitDialog : public AlertPane
{
public:
    QuitDialog();
    virtual bool OnKeyInput(const InputEvent *event);

protected:
    virtual void OnPrimaryButton();
};
