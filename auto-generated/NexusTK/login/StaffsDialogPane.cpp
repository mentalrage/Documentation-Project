// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O3
// Source by-file doc: by-file/StaffsDialogPane.md
// UID:0000SC | by-global/g_pStaffsDialog.md | Completion:92 | Confidence:94
class StaffsDialogPane;

StaffsDialogPane *g_pStaffsDialog = NULL;

[[No Children Attached]]

// UID:0002ZI | by-global/StaffsDialogEpfResourcePointer.md | Completion:92 | Confidence:94
static const wchar_t *kStaffsDialogEpfName = L"STAFF.EPF";

[[No Children Attached]]

// UID:0000DY | by-class/StaffsDialogPane.md | Completion:92 | Confidence:94
class StaffsDialogPane : public DialogPane,
                         public Singleton<StaffsDialogPane>
{
public:
    StaffsDialogPane();

protected:
    virtual void OnControlCommand(int controlId, int notifyCode);
};

[[No Children Attached]]

// UID:00019Z | by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md | Completion:92 | Confidence:94
StaffsDialogPane::StaffsDialogPane()
    : DialogPane(g_emptyWideString, -1, true),
      Singleton<StaffsDialogPane>()
{
    RECT frameRect;
    RECT controlRect;
    unsigned char modifierState;

    g_pEventMan->GetModifierState(&modifierState);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    AddControl(new EPFImageControlPane(kStaffsDialogEpfName, 0, true, frameRect, L"NPAL8.PAL"));
    LoadDialogResource(kStaffsDialogEpfName, 0);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    SetRect(&controlRect,
            (frameRect.right - frameRect.left) / 2 - 31,
            322,
            (frameRect.right - frameRect.left) / 2 + 31,
            346);
    AddControl(new ImageButtonControlPane(14, controlRect));

    SetRect(&controlRect, 38, 62, 230, 305);
    AddControl(new ScrolledTextControlPane((modifierState & 0x02) != 0 ? L"STAFFS2" : L"STAFFS",
                                           controlRect,
                                           50));

    SetCloseOnEscape(true);
    SetModal(true);
    EnableKeyboardInput(true);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    OffsetRect(&frameRect, frameRect.left - frameRect.right + 630, 130);
    AttachToLayer(frameRect, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    Show(0, g_pMainMenuPane);
    SlideOpen();
}

void StaffsDialogPane::OnControlCommand(int controlId, int notifyCode)
{
    (void)notifyCode;

    if (controlId == 1) {
        SlideClose();
        CloseDialog();
    }
}
