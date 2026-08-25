// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MX
// Source by-file doc: by-file/QuitDialogs.md
// UID:0000BG | by-class/QuitDialog.md | Completion:89 | Confidence:92
#include "QuitDialogs.h"

// UID:0004GY | by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md | Completion:89 | Confidence:91
QuitDialog::QuitDialog()
    : AlertPane(g_pLanguageMan->GetLocalizedString(3),
                g_pBackPane,
                L"Yes (Y)",
                L"No (N)")
{
}

// UID:0004GZ | by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md | Completion:89 | Confidence:90
bool QuitDialog::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (event->type != 8)
        return false;

    switch (key) {
    case 'Y':
    case 'y':
        OnPrimaryButton();
        CloseDialog();
        return true;

    case 'N':
    case 'n':
        OnSecondaryButton();
        CloseDialog();
        return true;

    default:
        return DialogPane::OnKeyInput(event);
    }
}

// UID:0004H1 | by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md | Completion:90 | Confidence:92
void QuitDialog::OnPrimaryButton()
{
    g_activeMapPane->ExitToMenu(true);
}

// UID:0000BH | by-class/QuitInputPane.md | Completion:92 | Confidence:94
class QuitInputPane : public CharInputPane,
                      public Singleton<QuitInputPane>
{
public:
    QuitInputPane();
    virtual ~QuitInputPane();

    virtual void OnConfirmInput();
};

extern QuitInputPane *g_pQuitInputPane;

// UID:0003ZQ | by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md | Completion:92 | Confidence:94
QuitInputPane::QuitInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(3)),
      Singleton<QuitInputPane>()
{
}

// UID:0003ZR | by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md | Completion:88 | Confidence:91
void QuitInputPane::OnConfirmInput()
{
    if (GetTextLength() != 1)
        return;

    wchar_t answer = 0;
    CopyText(&answer, 1);

    if (answer != L'y' && answer != L'Y')
    {
        MarkForDeletion();
        return;
    }

    TimerHandler *timerOwner = NULL;
    if (g_pCollectionData != NULL)
        timerOwner = &g_pCollectionData->m_timerHandler;

    g_pTimerMgr->RemovePendingTimersForOwner(timerOwner);
    g_activeMapPane->ExitToMenu(true);
}

// UID:0001NC | by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md | Completion:90 | Confidence:94
QuitInputPane::~QuitInputPane()
{
}

// UID:0000TD | by-global/OpenQuitPrompt_5A94B0.md | Completion:91 | Confidence:93
void OpenQuitPrompt();

// UID:0001KP | by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md | Completion:91 | Confidence:93
void OpenQuitPrompt()
{
    if (g_useEpfAssets)
    {
        new QuitDialog;
    }
    else if (g_pQuitInputPane == NULL)
    {
        new QuitInputPane;
    }
}

// UID:0000S1 | by-global/g_pQuitInputPane.md | Completion:90 | Confidence:94
QuitInputPane *g_pQuitInputPane = NULL;

// UID:0003JO | by-memory\0x006309f4-0x00630a14.QuitPromptYesNoStrings.md | Completion:86 | Confidence:92 | Empty Emitter Marker
