// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OG
// Source by-file doc: by-file/TargetOptionDialog.md
// UID:0000EF | by-class/TargetOptionEditControlPane.md | Completion:90 | Confidence:92
class TargetOptionEditControlPane : public ControlPane
{
public:
    TargetOptionEditControlPane(int optionMode,
                                unsigned char userTargetEnabled,
                                unsigned char monsterTargetEnabled,
                                const RectBounds *bounds);
    virtual ~TargetOptionEditControlPane();

    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual char HitTestPart(int mouseY, int mouseX);

    unsigned char GetUserTargetEnabled() const
    {
        return m_userTargetEnabled;
    }

    unsigned char GetMonsterTargetEnabled() const
    {
        return m_monsterTargetEnabled;
    }

private:
    int m_targetOptionMode;
    unsigned char m_userTargetEnabled;
    unsigned char m_monsterTargetEnabled;
};

// UID:0000EE | by-class/TargetOptionDialog.md | Completion:92 | Confidence:94
#include "../core/BlackHole.h"

class TargetOptionDialog : public DialogPane
{
public:
    TargetOptionDialog();
    virtual ~TargetOptionDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    void SaveTargetOptions();
};
// UID:0004QS | by-memory/0x00542270-0x0054248e.TargetOptionDialogConstructor.md | Completion:92 | Confidence:94
void InitRectBounds(RectBounds *bounds,
                    int left,
                    int top,
                    int right,
                    int bottom);

TargetOptionDialog::TargetOptionDialog()
    : DialogPane(L"", 3, 1)
{
    RegistryConfig &config =
        *static_cast<RegistryConfig *>(g_pConfig);
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 338, 190);
    AddControl(new EPFImageControlPane(
        L"DLGSETUP.EPF", 0, 1, &bounds, L"DLGSETUP.PAL"));

    InitRectBounds(&bounds, 138, 156, 201, 180);
    AddControl(new ImageButtonControlPane(14, &bounds));

    for (int rowIndex = 0; rowIndex < 2; ++rowIndex)
    {
        const int top = 64 + rowIndex * 34;
        InitRectBounds(&bounds, 19, top, 318, top + 20);
        AddControl(new TargetOptionEditControlPane(
            rowIndex,
            config.m_targetOptionRows[rowIndex].userEnabled,
            config.m_targetOptionRows[rowIndex].monsterEnabled,
            &bounds));
    }

    SetHoverControl(1);
    SetFocusedControl(1);
    SetPendingControl(1);
    SetBackgroundResource(L"DLGSETUP.EPF", NULL);

    InitRectBounds(&bounds, 0, 0, 338, 190);
    OnCreate(&bounds,
             0,
             NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:0004QT | by-memory/0x00542490-0x005424af.TargetOptionDialogNonDeletingDestructor.md | Completion:90 | Confidence:93
TargetOptionDialog::~TargetOptionDialog()
{
}

// UID:0004QU | by-memory/0x005424b0-0x00542534.TargetOptionDialogOnControlCommand.md | Completion:92 | Confidence:94
#include "../../profile/ProfileStorage.h"

void TargetOptionDialog::OnControlCommand(int controlIndex, int)
{
    if (controlIndex != 1)
        return;

    SaveTargetOptions();
    SlideCloseVertical();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);

    if (g_activeMapPane != NULL)
        SaveUserSettings();
}

// UID:0004QV | by-memory/0x00542540-0x0054259f.TargetOptionDialogSaveTargetOptionsRaw.md | Completion:91 | Confidence:93
void TargetOptionDialog::SaveTargetOptions()
{
    RegistryConfig &config =
        *static_cast<RegistryConfig *>(g_pConfig);

    for (int rowIndex = 0; rowIndex < 2; ++rowIndex)
    {
        TargetOptionEditControlPane *control =
            GetChild<TargetOptionEditControlPane>(rowIndex + 2);

        config.m_targetOptionRows[rowIndex].userEnabled =
            control->GetUserTargetEnabled();
        config.m_targetOptionRows[rowIndex].monsterEnabled =
            control->GetMonsterTargetEnabled();
    }
}

// UID:00011K | by-memory\0x004993b0-0x0049980c.TargetOptionEditControlPane.md | Completion:86 | Confidence:90 | Empty Emitter Marker
