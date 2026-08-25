// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JN
// Source by-file doc: by-file/FriendListDialog.md
// UID:0000PG | by-global/g_friendNameListSyncEnabled.md | Completion:92 | Confidence:94
// UID:0001OM | by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md | Completion:92 | Confidence:94
bool g_friendNameListSyncEnabled = true;

// UID:00005J | by-class/FriendListDialog.md | Completion:90 | Confidence:93
class FriendListDialog : public DialogPane
{
public:
    FriendListDialog();
    virtual ~FriendListDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);
};

// UID:0001DS | by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md | Completion:92 | Confidence:93
#include "../profile/ProfileStorage.h"

FriendListDialog::FriendListDialog()
    : DialogPane(L"Friend List", 11, true)
{
    RectBounds bounds;
    RectBounds dialogBounds;
    int row;
    int y;
    int slot;
    int left;
    int top;

    if (g_useEpfAssets) {
        InitRectBounds(&bounds, 0, 0, 332, 399);
        AddControl(new EPFImageControlPane(
            L"FRIEND.EPF", 0, 1, &bounds, L"FRIEND.PAL"));

        InitRectBounds(&bounds, 138, 363, 201, 387);
        AddControl(new ImageButtonControlPane(14, &bounds));

        for (row = 0; row < 10; ++row) {
            y = 60 + row * 29;
            InitRectBounds(&bounds, 49, y, 133, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[row].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        for (row = 0; row < 10; ++row) {
            slot = 10 + row;
            y = 60 + row * 29;
            InitRectBounds(&bounds, 199, y, 283, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[slot].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        SetHoverControl(2);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"FRIEND.EPF", 0);

        left = (g_screenWidth - 332) / 2;
        top = (g_screenHeight - 399) / 2;
        InitRectBounds(&dialogBounds, left, top, left + 332, top + 399);
    } else {
        InitRectBounds(&bounds, 0, 0, 407, 391);
        AddControl(new EPFImageControlPane(
            L"FRIEND.EPD", 0, 1, &bounds, L"NPAL8.PAL"));

        InitRectBounds(&bounds, 168, 341, 240, 357);
        AddControl(new ImageButtonControlPane(14, &bounds));

        for (row = 0; row < 10; ++row) {
            y = 94 + row * 21;
            InitRectBounds(&bounds, 104, y, 182, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[row].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        for (row = 0; row < 10; ++row) {
            slot = 10 + row;
            y = 94 + row * 21;
            InitRectBounds(&bounds, 246, y, 324, y + 12);
            AddControl(new TextEditControlPane(
                g_pConfig->m_friendNames[slot].c_str(),
                true, 128, 143, &bounds,
                false, false, false, false, 1.0f, false));
        }

        SetHoverControl(2);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"FRIEND.EPD", 0);

        InitRectBounds(&dialogBounds, 130, 10, 537, 401);
    }

    OnCreate(&dialogBounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

FriendListDialog::~FriendListDialog()
{
}

void FriendListDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    enum {
        kFriendNameSlotCount = 20,
        kFriendNameFirstControlId = 2,
        kFriendNameTextCapacity = 64
    };
    int slot;

    if (controlIndex != 1) {
        return;
    }

    wchar_t text[kFriendNameTextCapacity];

    for (slot = 0; slot < kFriendNameSlotCount; ++slot) {
        TextEditControlPane *edit =
            GetChild<TextEditControlPane>(kFriendNameFirstControlId + slot);
        WideString &friendName = g_pConfig->m_friendNames[slot];

        edit->ReadText(text, kFriendNameTextCapacity);
        friendName.Assign(text);
        friendName.TrimLeft(L" \t\n\r");
        friendName.TrimRight(L" \t\n\r");
    }

    if (g_friendNameListSyncEnabled) {
        g_packetSender->BuildAndSendFriendNameListSync();
    }

    SaveUserSettings();
    CloseDialog();
    g_pGeneralPurposePanel->RemoveDialog(this);
}

void FriendListDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

// UID:00038A | by-memory\0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor.md | Completion:87 | Confidence:92 | Empty Emitter Marker
