// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HE
// Source by-file doc: by-file/AlertPanes.md
// UID:00000B | by-class/AlertPane.md | Completion:88 | Confidence:92
#pragma once

#include "../core/DialogPane.h"
#include "../../util/FunctionObjects.h"

class Pane;

class AlertPane : public DialogPane
{
public:
    AlertPane(const wchar_t *messageText,
              Pane *layoutReference,
              const wchar_t *primaryButtonText,
              const wchar_t *secondaryButtonText);
    virtual ~AlertPane();

    virtual void DismissDialog(int buttonId, int unused);

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

    Pane *m_layoutReference;
};

// UID:0000FU | by-class/VersatileAlertPane.md | Completion:93 | Confidence:96
class VersatileAlertPane : public AlertPane
{
public:
    VersatileAlertPane(const wchar_t *messageText,
                       Pane *layoutReference,
                       FunctionObjectT<unsigned long> *resultCallback,
                       const wchar_t *primaryButtonText,
                       const wchar_t *secondaryButtonText);
    virtual ~VersatileAlertPane();

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

private:
    FunctionObjectT<unsigned long> *m_resultCallback;
};
