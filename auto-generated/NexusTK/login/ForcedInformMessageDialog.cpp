// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JJ
// Source by-file doc: by-file/ForcedInformMessageDialog.md
// UID:0000QY | by-global/g_pForcedInformMessageDialog.md | Completion:92 | Confidence:94
class ForcedInformMessageDialog;

ForcedInformMessageDialog *g_pForcedInformMessageDialog = NULL;

// UID:00005E | by-class/ForcedInformMessageDialog.md | Completion:93 | Confidence:94
class Event;

class ForcedInformMessageDialog : public DialogPane,
                                  public Singleton<ForcedInformMessageDialog>
{
public:
    ForcedInformMessageDialog(const wchar_t *messageText, Pane *parentPane, Layer *layer);
    virtual ~ForcedInformMessageDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    bool m_bAccepted;
};

extern ForcedInformMessageDialog *g_pForcedInformMessageDialog;


// UID:00048Y | by-memory/0x00587bb0-0x00588073.ForcedInformMessageDialogConstructor.md | Completion:92 | Confidence:94
namespace {
const int kForcedInformDialogConfigId = 15;
const int kForcedInformAcceptButtonImage = 14;
const int kForcedInformDeclineButtonImage = 22;
const int kForcedInformHoverControl = 2;
const int kForcedInformFocusedControl = 2;
const int kForcedInformPendingControl = 3;
const short kForcedInformMaxLines = 2000;
const short kForcedInformMaxLength = 30000;
}

ForcedInformMessageDialog::ForcedInformMessageDialog(const wchar_t *messageText,
                                                     Pane *parentPane,
                                                     Layer *layer)
    : DialogPane(L"", kForcedInformDialogConfigId, 1),
      m_bAccepted(true)
{
    if (g_useEpfAssets == 1) {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 318, 456),
                                           0,
                                           L"DLGSTAFF.EPF",
                                           L"DLGSTAFF.PAL"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(25, 56, 300, 391), L"");
        AddControl(messagePane);
        messagePane->SetMaxLines(kForcedInformMaxLines);
        messagePane->SetMaxLength(kForcedInformMaxLength);
        messagePane->SetEditActiveState(false, false);
        TextEditPane *editor = messagePane->GetTextEditPane();
        editor->SetText(messageText, static_cast<short>(std::wcslen(messageText)), NULL, 0);
        editor->SetSelectionRange(0, 0);
        messagePane->SetControlVisible(false);

        AddControl(new ImageButtonControlPane(MakeRect(86, 419, 149, 443),
                                              kForcedInformAcceptButtonImage));
        AddControl(new ImageButtonControlPane(MakeRect(163, 419, 226, 443),
                                              kForcedInformDeclineButtonImage));

        SetBackgroundResource(L"DLGSTAFF.EPF", NULL);
        SetMode(1);
        const int left = (g_screenWidth - 318) / 2;
        const int top = (g_screenHeight - 456) / 2;
        RectBounds dialogBounds = MakeRect(left, top, left + 318, top + 456);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SetHoverControl(kForcedInformHoverControl);
        SetFocusedControl(kForcedInformFocusedControl);
        SetPendingControl(kForcedInformPendingControl);
        SlideOpenVertical();
    } else {
        AddControl(new EPFImageControlPane(MakeRect(0, 0, 267, 367),
                                           0,
                                           L"DLGSTAFF.EPD",
                                           L"NP"));

        TextEditControlPane *messagePane =
            new TextEditControlPane(MakeRect(39, 70, 230, 306), L"");
        AddControl(messagePane);
        messagePane->SetMaxLines(kForcedInformMaxLines);
        messagePane->SetMaxLength(kForcedInformMaxLength);
        messagePane->SetEditActiveState(false, false);
        TextEditPane *editor = messagePane->GetTextEditPane();
        editor->SetText(messageText, static_cast<short>(std::wcslen(messageText)), NULL, 0);
        editor->SetSelectionRange(0, 0);
        messagePane->SetControlVisible(false);

        SetBackgroundResource(L"DLGSTAFF.EPD", NULL);
        SetMode(1);
        RectBounds dialogBounds = MakeRect(363, 100, 630, 467);
        OnCreate(&dialogBounds, 0, parentPane, layer);
        OnShow(NULL, parentPane);
        SlideOpenVertical();
    }

    if (g_pScreenDimmer != NULL) {
        g_pScreenDimmer->SetDimmed(true);
    }
}

// UID:00048Z | by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md | Completion:92 | Confidence:94
ForcedInformMessageDialog::~ForcedInformMessageDialog()
{
    if (g_useEpfAssets == 1 &&
        m_bAccepted &&
        g_pMainMenuPane != NULL) {
        EnsureLoginDialogPane();
    }
}

// UID:000490 | by-memory/0x00588110-0x0058815d.ForcedInformMessageDialogOnControlCommand.md | Completion:92 | Confidence:94
void ForcedInformMessageDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 2) {
        m_bAccepted = true;
        SlideCloseVertical();
        CloseDialog();
        return;
    }

    if (controlIndex == 3) {
        m_bAccepted = false;
        SlideCloseVertical();
        CloseDialog();
        g_pApplication->RequestExit();
    }
}

// UID:000491 | by-memory/0x00588160-0x005881ed.ForcedInformMessageDialogHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool ForcedInformMessageDialog::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (event->m_type == kEventKeyDown) {
        if (key == 'A' || key == 'a') {
            m_bAccepted = true;
            SlideCloseVertical();
            CloseDialog();
        } else if (key == 'D' || key == 'd') {
            m_bAccepted = false;
            SlideCloseVertical();
            CloseDialog();
            g_pApplication->RequestExit();
        }
    }

    return true;
}

// UID:0003GQ | by-memory\0x0062d9a0-0x0062d9f4.ForcedInformMessageDialogStaffResourceStrings.md | Completion:87 | Confidence:92 | Empty Emitter Marker
