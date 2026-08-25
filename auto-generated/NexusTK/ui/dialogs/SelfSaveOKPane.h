// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NN
// Source by-file doc: by-file/SelfSaveOKPane.md
// UID:0000CX | by-class/SelfSaveOKPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H
#define NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H

#include "../controls/TextEditPane.h"

class SelfSaveOKPane : public TextBoxPane
{
public:
    SelfSaveOKPane();

protected:
    virtual bool OnTimer(int timerId, int, int);
};

typedef char SelfSaveOKPaneSizeMustBe174[
    (sizeof(SelfSaveOKPane) == 0x174) ? 1 : -1];

#endif
