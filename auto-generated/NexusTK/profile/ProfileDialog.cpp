// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MR
// Source by-file doc: by-file/ProfileDialog.md
// UID:0001DU | by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md | Completion:93 | Confidence:95
namespace {

void RefreshProfileData()
{
    g_activeMapPane->RefreshSelectedProfileData();
}

} // namespace

// UID:0000AU | by-class/ProfileDialog.md | Completion:91 | Confidence:93
// UID:0004E0 | by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md | Completion:92 | Confidence:94
ProfileDialog::ProfileDialog()
    : DialogPane(L"Profile", 12, true)
{
    RectBounds bounds;
    RectBounds dialogBounds;
    TextEditControlPane *profileEdit;
    int profileLength;

    if (g_useEpfAssets) {
        InitRectBounds(&bounds, 0, 0, 285, 238);
        AddControl(new EPFImageControlPane(
            L"DLGPROFL.EPF", 0, 1, &bounds, L"DLGPROFL.PAL"));

        InitRectBounds(&bounds, 68, 54, 225, 174);
        profileEdit = new TextEditControlPane(
            L"", true, 143, 128, &bounds,
            false, true, false, false, 1.0f, false);
        profileEdit->SetHandlesEnterKey(true);
        profileEdit->SetMaxLength(250);
        profileEdit->SetMaxLines(16);
        AddControl(profileEdit);

        profileLength = static_cast<int>(wcslen(g_pConfig->m_selectedProfileName));
        if (profileLength != 0) {
            profileEdit->GetTextEditPane()->InsertTextRange(
                g_pConfig->m_selectedProfileName,
                static_cast<short>(profileLength),
                NULL,
                NULL);
        }

        InitRectBounds(&bounds, 108, 200, 171, 224);
        AddControl(new ImageButtonControlPane(14, &bounds));
        SetHoverControl(1);
        SetFocusedControl(2);
        SetBackgroundResource(L"DLGPROFL.EPF", 0);
        InitRectBounds(&dialogBounds, 130, 10, 415, 248);
    } else {
        InitRectBounds(&bounds, 0, 0, 314, 246);
        AddControl(new EPFImageControlPane(
            L"PR", 0, 1, &bounds, L"NP"));

        InitRectBounds(&bounds, 36, 71, 277, 174);
        profileEdit = new TextEditControlPane(
            L"", true, 143, 128, &bounds,
            false, true, false, false, 1.0f, false);
        profileEdit->SetHandlesEnterKey(true);
        profileEdit->SetMaxLength(250);
        profileEdit->SetMaxLines(16);
        AddControl(profileEdit);

        profileLength = static_cast<int>(wcslen(g_pConfig->m_selectedProfileName));
        if (profileLength != 0) {
            profileEdit->GetTextEditPane()->InsertTextRange(
                g_pConfig->m_selectedProfileName,
                static_cast<short>(profileLength),
                NULL,
                NULL);
        }

        InitRectBounds(&bounds, 83, 196, 155, 212);
        AddControl(new ImageButtonControlPane(14, &bounds));
        InitRectBounds(&bounds, 160, 196, 232, 212);
        AddControl(new ImageButtonControlPane(22, &bounds));
        SetHoverControl(1);
        SetFocusedControl(2);
        SetPendingControl(3);
        SetBackgroundResource(L"PR", 0);
        InitRectBounds(&dialogBounds, 250, 200, 564, 446);
    }

    OnCreate(&dialogBounds, 0, NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:0004E1 | by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md | Completion:88 | Confidence:92
ProfileDialog::~ProfileDialog()
{
}

// UID:0004E2 | by-memory\0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:00038G | by-memory\0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0000V9 | by-item\ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md | Completion:89 | Confidence:93 | Empty Emitter Marker
