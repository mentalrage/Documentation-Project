// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KY
// Source by-file doc: by-file/MacroDialogs.md
// UID:00007I | by-class/MacroDialog.md | Completion:91 | Confidence:93
class MacroDialog : public DialogPane
{
public:
    MacroDialog();
    virtual ~MacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

// UID:00049C | by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md | Completion:90 | Confidence:93
MacroDialog::MacroDialog()
    : DialogPane(kMacroDialogCaption, 4, true)
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;
    Rect dialogBounds;

    if (UseEpfMacroDialogLayout())
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 59 + row * 29;
            AddControl(new TextEditControlPane(
                g_pConfig->m_profileTextSlots[row],
                true,
                0x80,
                0x8f,
                Rect(49, y, 251, y + 12),
                true));
        }

        SetBackgroundResource(L"DLGMACRO.EPF");
        dialogBounds = Rect(130, 10, 419, 409);
    }
    else
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPD", Rect(0, 0, 407, 391), kNpPaletteName));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(168, 341, 240, 357)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 94 + row * 21;
            AddControl(new TextEditControlPane(
                g_pConfig->m_profileTextSlots[row],
                true,
                0x80,
                0x8f,
                Rect(134, y, 291, y + 12),
                true));
        }

        SetBackgroundResource(L"DLGMACRO.EPD");
        dialogBounds = Rect(130, 10, 537, 401);
    }

    SetHoverControl(kFirstRowControlId);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBounds(dialogBounds);
    SetLayer(g_pDialogLayer);
    Show();
}

// UID:00049D | by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md | Completion:90 | Confidence:93
MacroDialog::~MacroDialog()
{
}

// UID:00049E | by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md | Completion:90 | Confidence:93
void MacroDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    if (controlIndex != 1)
        return;

    for (int row = 0; row < 10; ++row)
    {
        TextEditControlPane *edit = GetChild<TextEditControlPane>(2 + row);
        edit->CopyTextTo(g_pConfig->m_profileTextSlots[row], 64);
    }

    CloseDialog();
    g_pGeneralPurposePanel->RemoveDialog(this);
}

// UID:00038C | by-memory/0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated MSVC scalar deleting destructor for MacroDialog;
// covered by MacroDialog::~MacroDialog().

// UID:00006L | by-class/IntegrateMacroDialog.md | Completion:92 | Confidence:94
class KeyEvent;

class IntegrateMacroDialog : public DialogPane
{
public:
    IntegrateMacroDialog();
    virtual ~IntegrateMacroDialog();

    virtual void OnDraw();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleKeyInput(KeyEvent *event);

private:
    void ClearMacroEditFields();
    void AdvanceMacroPage();
    void RetreatMacroPage();
    void RefreshMacroEditFields();

    int m_pageCount;
    int m_currentPage;
    int m_firstMacroRowControlId;
};

// UID:00045D | by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md | Completion:92 | Confidence:94
IntegrateMacroDialog::IntegrateMacroDialog()
    : DialogPane(kMacroDialogCaption, 6, true),
      m_pageCount(3),
      m_currentPage(0)
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;

    g_pGeneralPurposePanel->SwitchActiveChild(3, false);
    PrepareMacroDialogPalette(g_pMacroDialogPalette, 0x198, 100);

    AddControl(new ResourceImagePane(L"DLGMAC2.EPF", Rect(0, 0, 289, 449), L"DLGMACRO.PAL"));
    AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

    for (int row = 0; row < kRowCount; ++row)
    {
        const int y = 54 + row * 29;
        AddControl(new IntegrateMacroEditControlPane(
            &g_pConfig->m_macroHotkeys[row],
            Rect(19, y, 268, y + 20)));
    }

    ImageButtonControlPane *previous = new ImageButtonControlPane(kMacroPreviousImageId, Rect(30, 362, 93, 386));
    previous->Disable();
    AddControl(previous);

    AddControl(new ImageButtonControlPane(kMacroNextImageId, Rect(200, 362, 263, 386)));

    SetHoverControl(kFirstRowControlId);
    SetModal(true);
    SetCloseOnEscape(true);

    m_firstMacroRowControlId = kFirstRowControlId;

    SetBackgroundResource(L"DLGMACRO.EPF");
    SetBounds(Rect(130, 10, 419, 459));
    SetLayer(g_pDialogLayer);
    Show();
}

// UID:00045E | by-memory/0x00541e30-0x00541e4f.IntegrateMacroDialogNonDeletingDestructor.md | Completion:87 | Confidence:92
IntegrateMacroDialog::~IntegrateMacroDialog()
{
}

// UID:00045F | by-memory/0x00541e50-0x00541f96.IntegrateMacroDialogOnDraw.md | Completion:90 | Confidence:92
void IntegrateMacroDialog::OnDraw()
{
    constexpr int kInstructionXInset = 9;
    constexpr int kInstructionLineStep = 18;
    constexpr int kInstructionFirstLineOffset = 36;
    constexpr int kInstructionDrawColor = 0;
    constexpr int kInstructionTextColor = 143;
    constexpr int kInstructionTextBackColor = 128;
    constexpr unsigned char kInstructionTextDrawMode = 1;

    wchar_t text[256];

    SetDrawColor(kInstructionDrawColor);
    FillRect(&m_bounds);
    SetTextColor(kInstructionTextColor);
    SetTextBackColor(kInstructionTextBackColor);
    m_textDrawMode = kInstructionTextDrawMode;
    SetFontId(IsLegacyAssetMode() ? 1 : 0);

    const int x = m_bounds.left + kInstructionXInset;
    const int y = m_bounds.bottom;

    swprintf_s(text, _countof(text), L"Spell : Select 'SPELLS' tab and press key.");
    DrawOutlinedText(x, y - kInstructionFirstLineOffset, text, static_cast<int>(wcslen(text)));

    swprintf_s(text, _countof(text), L"Item  : Select 'ITEMS' tab and press key.");
    DrawOutlinedText(x, y - kInstructionLineStep, text, static_cast<int>(wcslen(text)));

    swprintf_s(text, _countof(text), L"Text  : Press ';' key");
    DrawOutlinedText(x, y, text, static_cast<int>(wcslen(text)));
}

// UID:00045G | by-memory/0x00541fa0-0x005420b1.IntegrateMacroDialogOnControlCommand.md | Completion:92 | Confidence:94
#include "../../profile/ProfileStorage.h"

void IntegrateMacroDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    switch (controlIndex)
    {
    case kDialogCommandOk:
        ClearMacroEditFields();
        Close();
        g_pGeneralPurposePanel->RemoveDialog(this);
        if (g_activeMapPane != NULL)
            SaveUserSettings();
        break;

    case kMacroPreviousPageCommand:
        ClearMacroEditFields();
        if (m_currentPage <= 0)
            break;

        --m_currentPage;

        GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Deactivate();

        if (m_currentPage == 0)
            GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Disable();

        RefreshMacroEditFields();
        break;

    case kMacroNextPageCommand:
        ClearMacroEditFields();
        if (m_currentPage >= m_pageCount - 1)
            break;

        ++m_currentPage;

        GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Deactivate();

        if (m_currentPage == m_pageCount - 1)
            GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Disable();

        RefreshMacroEditFields();
        break;
    }
}

// UID:00045H | by-memory/0x005420c0-0x005420c9.IntegrateMacroDialogHandleKeyInput.md | Completion:88 | Confidence:91
bool IntegrateMacroDialog::HandleKeyInput(KeyEvent *event)
{
    return DialogPane::HandleKeyInput(event);
}

// UID:00045I | by-memory/0x005420d0-0x005420fd.IntegrateMacroDialogClearMacroEditFields.md | Completion:90 | Confidence:92
void IntegrateMacroDialog::ClearMacroEditFields()
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;

    for (int row = 0; row < kRowCount; ++row)
        GetChild<IntegrateMacroEditControlPane>(kFirstRowControlId + row)->SyncEditControl();
}

// UID:00045J | by-memory/0x00542100-0x00542172.IntegrateMacroDialogAdvanceMacroPageRaw.md | Completion:90 | Confidence:91
void IntegrateMacroDialog::AdvanceMacroPage()
{
    if (m_currentPage >= m_pageCount - 1)
        return;

    ++m_currentPage;

    GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Enable();
    GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Deactivate();

    if (m_currentPage == m_pageCount - 1)
        GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Disable();

    RefreshMacroEditFields();
}

// UID:00045K | by-memory/0x00542180-0x005421e3.IntegrateMacroDialogRetreatMacroPageRaw.md | Completion:90 | Confidence:91
void IntegrateMacroDialog::RetreatMacroPage()
{
    if (m_currentPage <= 0)
        return;

    --m_currentPage;

    GetChild<ImageButtonControlPane>(kMacroNextPageCommand)->Enable();
    GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Deactivate();

    if (m_currentPage == 0)
        GetChild<ImageButtonControlPane>(kMacroPreviousPageCommand)->Disable();

    RefreshMacroEditFields();
}

// UID:00045L | by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md | Completion:90 | Confidence:92
void IntegrateMacroDialog::RefreshMacroEditFields()
{
    const int baseIndex = m_currentPage * 10;

    for (int row = 0; row < 10; ++row)
    {
        IntegrateMacroEditControlPane *edit =
            GetChild<IntegrateMacroEditControlPane>(2 + row);
        MacroHotkeyRecord &record = g_pConfig->m_macroHotkeys[baseIndex + row];

        edit->SetMacroData(&record);
        edit->RefreshDisplay();
    }
}

// UID:00038B | by-memory/0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor.md | Completion:90 | Confidence:93
// [UID:00038B] Compiler-generated MSVC scalar deleting destructor wrapper for
// IntegrateMacroDialog is covered by the source-level empty
// IntegrateMacroDialog::~IntegrateMacroDialog() body in [UID:00045E][0x00541e30-0x00541e4f.IntegrateMacroDialogNonDeletingDestructor](by-memory/0x00541e30-0x00541e4f.IntegrateMacroDialogNonDeletingDestructor.md); do not
// hand-emit the ABI wrapper, delete-flag path, or vtable-reset bytes.

// UID:00006M | by-class/IntegrateMacroEditControlPane.md | Completion:92 | Confidence:94
class Event;
class Layer;
class Pane;
class TextEditPane;
struct MacroHotkeyRecord;
struct Rect;
struct RectBounds;

class IntegrateMacroEditControlPane : public ControlPane
{
public:
    IntegrateMacroEditControlPane(MacroHotkeyRecord *record, const Rect &bounds);
    virtual ~IntegrateMacroEditControlPane();

    bool IsTextEditActive() const;
    void SetMacroData(MacroHotkeyRecord *record);
    void RefreshDisplay();
    void SyncEditControl();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    void EnterTextEditMode();
    void LeaveTextEditMode();

    MacroHotkeyRecord *m_macroData;
    bool m_pendingTextEditForward;
    bool m_editActive;
    TextEditPane *m_textEdit;
    unsigned char m_savedTextEditState;
};

// UID:0004AG | by-memory/0x0057fd10-0x0057fefc.IntegrateMacroEditControlPaneConstructor.md | Completion:90 | Confidence:93
IntegrateMacroEditControlPane::IntegrateMacroEditControlPane(MacroHotkeyRecord *record, const Rect &bounds)
    : ControlPane(8, bounds),
      m_macroData(record)
{
    SetSelectable(true);

    const int editWidth = bounds.right - bounds.left - 50;
    const int editHeight = bounds.bottom - bounds.top;
    m_textEdit = new TextEditPane(editWidth,
                                  editHeight,
                                  editWidth,
                                  editHeight,
                                  128,
                                  143,
                                  false,
                                  false,
                                  258,
                                  IsLegacyAssetMode(),
                                  true,
                                  false);

    Rect editBounds = bounds;
    editBounds.right -= 30;
    editBounds.Offset(50 - editBounds.left, 4 - editBounds.top);

    m_textEdit->SetMaxLength(1024);
    m_textEdit->SetMaxLines(1);
    m_textEdit->SetBounds(editBounds);
    m_textEdit->SetMode(1);
    m_textEdit->SetEditActiveState(false, false);
    m_savedTextEditState = m_textEdit->GetMode();

    if (m_editActive)
    {
        m_editActive = false;
        if (m_textEdit != nullptr)
        {
            m_textEdit->SetMode(4);
            m_textEdit->SetEditActiveState(false, false);
        }
    }

    if (m_macroData->state == MacroHotkeyRecord::Text)
        m_textEdit->SetText(m_macroData->text,
                            static_cast<short>(std::wcslen(m_macroData->text)),
                            0,
                            0);
}

// UID:0004AH | by-memory/0x0057ff00-0x0057ff3f.IntegrateMacroEditControlPaneNonDeletingDestructor.md | Completion:92 | Confidence:94
IntegrateMacroEditControlPane::~IntegrateMacroEditControlPane()
{
    if (m_textEdit != NULL)
    {
        delete m_textEdit;
        m_textEdit = NULL;
    }
}

// UID:0004AI | by-memory/0x0057ff40-0x0057ff5b.IntegrateMacroEditControlPaneIsTextEditActive.md | Completion:88 | Confidence:90
bool IntegrateMacroEditControlPane::IsTextEditActive() const
{
    return m_macroData->state == MacroHotkeyRecord::Text && m_editActive;
}

// UID:0004AJ | by-memory/0x0057ff60-0x0057ff9c.IntegrateMacroEditControlPaneSetMacroData.md | Completion:88 | Confidence:91
void IntegrateMacroEditControlPane::SetMacroData(MacroHotkeyRecord *record)
{
    m_macroData = record;
    m_textEdit->ClearText();

    if (m_macroData->state == MacroHotkeyRecord::Text)
        m_textEdit->SetText(m_macroData->text, false);
}

// UID:0004AK | by-memory/0x0057ffa0-0x0057ffaa.IntegrateMacroEditControlPaneRefreshDisplay.md | Completion:92 | Confidence:94
void IntegrateMacroEditControlPane::RefreshDisplay()
{
    InvalidateRect(&m_visibleBounds);
}

// UID:0004AL | by-memory/0x0057ffb0-0x00580313.IntegrateMacroEditControlPaneOnPaint.md | Completion:88 | Confidence:91
void IntegrateMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const int centerY = (row.Height() + row.top + 12) / 2;
    const uint16_t key = m_macroData->key;

    if (key >= 20)
        DrawMacroRowText(row.left + 4, centerY, FormatShortcutNumber(L"Alt+%d", key == 29 ? 0 : key - 19));
    else if (key >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", key == 19 ? 0 : key - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", key == 9 ? 0 : key + 1));

    DrawMacroRowText(row.left + 40, centerY, MacroHotkeyStateName(m_macroData->state));
    DrawMacroRowText(row.left + 50, centerY, DescribeMacroHotkeyRecord(*m_macroData, !m_editActive));

    if (IsFocused())
        DrawMacroRowFocus(row);
}

// UID:0004AM | by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent.md | Completion:90 | Confidence:93
bool IntegrateMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (m_editActive && !m_pendingTextEditForward)
        return m_textEdit->HandleKeyOrTextEvent(event);

    if (m_pendingTextEditForward)
        m_pendingTextEditForward = false;

    if (event->m_type != kEventKeyDown)
        return event->m_type == kEventTextInput;

    const unsigned char key = NarrowInputKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == ';')
    {
        m_pendingTextEditForward = true;
        m_macroData->state = MacroHotkeyRecord::Text;
        EnterTextEditMode();
        InvalidateRect(NULL);
        return true;
    }

    const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
    if (activeChild == 2 || activeChild == 3)
    {
        if ((key < 'a' || key > 'z') &&
            (key < 'A' || key > 'Z'))
            return false;

        m_textEdit->ClearText();
        m_macroData->key = key;
        m_macroData->terminator = 0;
        m_macroData->state = activeChild == 3
            ? MacroHotkeyRecord::Spell
            : MacroHotkeyRecord::Item;
        InvalidateRect(NULL);
    }

    return true;
}

// UID:0004AN | by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent.md | Completion:89 | Confidence:93
bool IntegrateMacroEditControlPane::HandlePointerOrMouseEvent(Event *event)
{
    if (m_editActive)
        return m_textEdit->HandlePointerOrMouseEvent(event);

    return true;
}

// UID:0004AO | by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent.md | Completion:89 | Confidence:93
bool IntegrateMacroEditControlPane::HandleImeEvent(Event *event)
{
    if (m_editActive)
        return m_textEdit->HandleImeEvent(event);

    return true;
}

// UID:0004AP | by-memory/0x005804c0-0x0058050d.IntegrateMacroEditControlPaneEnterTextEditMode.md | Completion:88 | Confidence:90
void IntegrateMacroEditControlPane::EnterTextEditMode()
{
    if (m_editActive)
        return;

    m_editActive = true;
    if (m_textEdit != nullptr)
    {
        m_textEdit->SetStateByte(m_savedTextEditState);
        m_textEdit->SetVisibleAndEnabled(true, true);
        m_textEdit->SelectText(0, 0x7fff);
    }
}

// UID:0004AQ | by-memory/0x00580510-0x00580545.IntegrateMacroEditControlPaneLeaveTextEditMode.md | Completion:88 | Confidence:90
void IntegrateMacroEditControlPane::LeaveTextEditMode()
{
    if (!m_editActive)
        return;

    m_editActive = false;
    if (m_textEdit != nullptr)
    {
        m_textEdit->SetStateByte(4);
        m_textEdit->SetVisibleAndEnabled(false, false);
    }
}

// UID:0004AR | by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md | Completion:92 | Confidence:94
void IntegrateMacroEditControlPane::AddToLayer(const RectBounds *bounds,
                                                int order,
                                                Pane *previousPane,
                                                Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    if (m_textEdit != nullptr)
    {
        RectBounds editBounds;
        m_textEdit->GetBounds(&editBounds);
        m_textEdit->AddToLayer(&editBounds, 0, this, layer);
    }
}

// UID:0004AS | by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md | Completion:92 | Confidence:94
void IntegrateMacroEditControlPane::RemoveFromLayer()
{
    if (m_textEdit != nullptr)
        m_textEdit->RemoveFromLayer();

    Pane::RemoveFromLayer();
}

// UID:0004AT | by-memory/0x005805e0-0x0058063e.IntegrateMacroEditControlPaneSyncEditControl.md | Completion:88 | Confidence:91
void IntegrateMacroEditControlPane::SyncEditControl()
{
    if (m_macroData->state == MacroHotkeyRecord::Text && m_textEdit != nullptr)
    {
        if (m_editActive)
            LeaveTextEditMode();

        m_textEdit->CopyTextTo(m_macroData->text, 64);
    }

    Activate(false);
}

// UID:000094 | by-class/NewMacroDialog.md | Completion:92 | Confidence:94
class NewMacroDialog : public DialogPane
{
public:
    NewMacroDialog();
    virtual ~NewMacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);

private:
    void SaveMacroEntries();
    void LoadMacroPage(int page);

    int m_currentPage;
};

// UID:00049J | by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md | Completion:90 | Confidence:93
NewMacroDialog::NewMacroDialog()
    : DialogPane(kMacroDialogCaption, 6, true),
      m_currentPage(0)
{
    g_pGeneralPurposePanel->SwitchActiveChild(3, false);
    PrepareMacroDialogPalette(g_pMacroDialogPalette, 0x198, 100);

    AddControl(new ResourceImagePane(L"DLGMAC2.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
    AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

    for (int row = 0; row < 10; ++row)
    {
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[row];
        const int y = 54 + row * 29;
        AddControl(new NewMacroEditControlPane(
            record.code,
            row,
            record.isSpellMode,
            Rect(19, y, 268, y + 20)));
    }

    ImageButtonControlPane *previous = new ImageButtonControlPane(kMacroPreviousImageId, Rect(30, 362, 93, 386));
    previous->Disable();
    AddControl(previous);

    AddControl(new ImageButtonControlPane(kMacroNextImageId, Rect(200, 362, 263, 386)));

    SetHoverControl(2);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBackgroundResource(L"DLGMACRO.EPF");
    SetBounds(Rect(130, 10, 419, 409));
    SetLayer(g_pDialogLayer);
}

// UID:00049K | by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md | Completion:88 | Confidence:91
NewMacroDialog::~NewMacroDialog()
{
}

// UID:00049L | by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnControlCommand.md | Completion:91 | Confidence:94
void NewMacroDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    switch (controlIndex)
    {
    case kDialogCommandOk:
        SaveMacroEntries();
        Close();
        g_pGeneralPurposePanel->RemoveDialog(this);
        if (g_activeMapPane != NULL)
            SaveUserSettings();
        break;

    case kMacroFirstPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Disable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Enable();
        SaveMacroEntries();
        LoadMacroPage(0);
        break;

    case kMacroSecondPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Disable();
        SaveMacroEntries();
        LoadMacroPage(1);
        break;
    }
}

// UID:00049M | by-memory/0x0053f170-0x0053f179.NewMacroDialogSetHoverControl.md | Completion:90 | Confidence:94
void NewMacroDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

// UID:00049N | by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md | Completion:89 | Confidence:92
void NewMacroDialog::SaveMacroEntries()
{
    const int baseIndex = m_currentPage * 10;

    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        record.code = edit->GetKey();
        record.isSpellMode = edit->GetSpellMode();
    }
}

// UID:00049O | by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md | Completion:89 | Confidence:92
void NewMacroDialog::LoadMacroPage(int page)
{
    if (m_currentPage == page)
        return;

    m_currentPage = page;

    const int baseShortcutIndex = page * 10;
    for (int row = 0; row < 10; ++row)
    {
        const int shortcutIndex = baseShortcutIndex + row;
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        const CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[shortcutIndex];

        edit->SetShortcutIndex(shortcutIndex);
        edit->SetKey(record.code);
        edit->SetSpellMode(record.isSpellMode);
        edit->Refresh();
    }
}


// UID:000095 | by-class/NewMacroEditControlPane.md | Completion:92 | Confidence:94
class Event;
struct Rect;

class NewMacroEditControlPane : public ControlPane
{
public:
    NewMacroEditControlPane(wchar_t key, int shortcutIndex, unsigned char spellMode, const Rect &bounds);

    wchar_t GetKey() const;
    unsigned char GetSpellMode() const;
    void SetShortcutIndex(int shortcutIndex);
    void SetKey(wchar_t key);
    void SetSpellMode(unsigned char spellMode);
    void Refresh();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_shortcutIndex;
    wchar_t m_key;
    unsigned char m_spellMode;
};

// UID:0004A6 | by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md | Completion:92 | Confidence:94
wchar_t NewMacroEditControlPane::GetKey() const
{
    return m_key;
}

// UID:0004A7 | by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md | Completion:92 | Confidence:94
unsigned char NewMacroEditControlPane::GetSpellMode() const
{
    return m_spellMode;
}

// UID:0004A8 | by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md | Completion:91 | Confidence:94
NewMacroEditControlPane::NewMacroEditControlPane(
    wchar_t key,
    int shortcutIndex,
    unsigned char spellMode,
    const Rect &bounds)
    : ControlPane(8, bounds),
      m_shortcutIndex(shortcutIndex),
      m_key(key),
      m_spellMode(spellMode)
{
    SetSelectable(true);
}

// UID:0004A9 | by-memory/0x0057fa30-0x0057fa40.NewMacroEditControlPaneSetShortcutIndex.md | Completion:92 | Confidence:94
void NewMacroEditControlPane::SetShortcutIndex(int shortcutIndex)
{
    m_shortcutIndex = shortcutIndex;
}

// UID:0004AA | by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md | Completion:92 | Confidence:94
void NewMacroEditControlPane::SetKey(wchar_t key)
{
    m_key = key;
}

// UID:0004AB | by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md | Completion:92 | Confidence:94
void NewMacroEditControlPane::SetSpellMode(unsigned char spellMode)
{
    m_spellMode = spellMode;
}

// UID:0004AC | by-memory/0x0057fa70-0x0057fa7a.NewMacroEditControlPaneRefresh.md | Completion:92 | Confidence:94
void NewMacroEditControlPane::Refresh()
{
    InvalidateRect(&m_visibleBounds);
}

// UID:0004AD | by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md | Completion:88 | Confidence:91
void NewMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const uint16_t normalizedKey = NormalizeSpellKey(m_key);
    const wchar_t *entryName = nullptr;
    if (m_spellMode != 0)
        entryName = g_spellRecords[normalizedKey].displayName;
    else
        entryName = GetLocalInventorySlot(normalizedKey)->displayName;

    const int centerY = (row.Height() + row.top + 12) / 2;
    if (m_shortcutIndex >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", m_shortcutIndex == 19 ? 0 : m_shortcutIndex - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", m_shortcutIndex == 9 ? 0 : m_shortcutIndex + 1));

    DrawMacroRowText(row.left + 48, centerY, m_spellMode != 0 ? L"Spell" : L"Item");
    DrawMacroRowText(row.left + 90, centerY, entryName);

    if (IsFocused())
        DrawMacroRowFocus(row);
}

// UID:0004AE | by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md | Completion:90 | Confidence:93
bool NewMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
        if (activeChild == 2 || activeChild == 3)
        {
            const unsigned char key = NarrowInputKey(
                event->m_payload.m_key.m_key,
                event->m_payload.m_key.m_modifiers);

            if ((key < 'a' || key > 'z') &&
                (key < 'A' || key > 'Z'))
                return false;

            m_key = key;
            m_spellMode = activeChild == 3;
            InvalidateRect(NULL);
        }

        return true;
    }

    return event->m_type == kEventTextInput;
}

// UID:0004AF | by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md | Completion:91 | Confidence:94
bool NewMacroEditControlPane::HandlePointerOrMouseEvent(Event *)
{
    return true;
}

// UID:0000DP | by-class/SpellMacroDialog.md | Completion:92 | Confidence:94
class SpellMacroDialog : public DialogPane
{
public:
    SpellMacroDialog();
    virtual ~SpellMacroDialog();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);
};

// UID:00049F | by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md | Completion:90 | Confidence:93
SpellMacroDialog::SpellMacroDialog()
    : DialogPane(kMacroDialogCaption, 5, true)
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;
    Rect dialogBounds;

    if (UseEpfMacroDialogLayout())
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 54 + row * 29;
            AddControl(new SpellMacroEditControlPane(
                g_pConfig->m_legacyShortcutText[row][0],
                Rect(49, y, 250, y + 20)));
        }

        SetBackgroundResource(L"DLGMACRO.EPF");
        dialogBounds = Rect(130, 10, 419, 409);
    }
    else
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPD", Rect(0, 0, 407, 391), kNpPaletteName));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(168, 341, 240, 357)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 94 + row * 21;
            AddControl(new SpellMacroEditControlPane(
                g_pConfig->m_legacyShortcutText[row][0],
                Rect(134, y, 291, y + 12)));
        }

        SetBackgroundResource(L"DLGMACRO.EPD");
        dialogBounds = Rect(130, 10, 537, 401);
    }

    SetHoverControl(kFirstRowControlId);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBounds(dialogBounds);
    SetLayer(g_pDialogLayer);
    Show();
}

// UID:00049G | by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md | Completion:90 | Confidence:93
SpellMacroDialog::~SpellMacroDialog()
{
}

// UID:00049H | by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md | Completion:91 | Confidence:94
void SpellMacroDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    if (controlIndex != 1)
        return;

    for (int row = 0; row < 10; ++row)
    {
        SpellMacroEditControlPane *edit = GetChild<SpellMacroEditControlPane>(2 + row);
        g_pConfig->m_legacyShortcutText[row][0] = edit->GetSpellKey();
        g_pConfig->m_legacyShortcutText[row][1] = 0;
    }

    Close();
    g_pGeneralPurposePanel->RemoveDialog(this);

    if (g_activeMapPane != NULL)
        SaveUserSettings();
}

// UID:00049I | by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetHoverControl.md | Completion:90 | Confidence:94
void SpellMacroDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}

// UID:00038H | by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated MSVC scalar deleting destructor for SpellMacroDialog;
// covered by SpellMacroDialog::~SpellMacroDialog().

// UID:0000DQ | by-class/SpellMacroEditControlPane.md | Completion:92 | Confidence:94
class Event;
struct RectBounds;

class SpellMacroEditControlPane : public ControlPane
{
public:
    SpellMacroEditControlPane(wchar_t spellKey, const RectBounds &bounds);

    wchar_t GetSpellKey() const;

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t m_spellKey;
};

// UID:0004A1 | by-memory/0x0057f750-0x0057f758.SpellMacroEditControlPaneGetSpellKey.md | Completion:92 | Confidence:94
wchar_t SpellMacroEditControlPane::GetSpellKey() const
{
    return m_spellKey;
}

// UID:0004A2 | by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md | Completion:90 | Confidence:93
SpellMacroEditControlPane::SpellMacroEditControlPane(
    wchar_t spellKey,
    const RectBounds &bounds)
    : ControlPane(8, &bounds),
      m_spellKey(spellKey)
{
    m_controlFlags = 1;
}

// UID:0004A3 | by-memory/0x0057f7d0-0x0057f927.SpellMacroEditControlPaneOnPaint.md | Completion:88 | Confidence:91
void SpellMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const SpellRecord &spell = g_spellRecords[NormalizeSpellKey(m_spellKey)];
    const int centerY = (row.Height() + 12) / 2;

    if (UseEpfMacroDialogLayout())
    {
        DrawMacroRowText(row.left + 5, centerY, FormatSpellKey(m_spellKey));
        DrawMacroRowText(row.left + 15, centerY, spell.displayName);
    }
    else
    {
        DrawMacroRowText(row.left + 1, row.bottom - 1, FormatSpellKey(m_spellKey));
    }

    if (IsFocused())
        DrawMacroRowFocus(row);
}

// UID:0004A4 | by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool SpellMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const unsigned char key = NarrowInputKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

        if ((key >= 'a' && key <= 'z') ||
            (key >= 'A' && key <= 'Z'))
        {
            m_spellKey = key;
            InvalidateRect(NULL);
            return true;
        }
    }
    else if (event->m_type == kEventTextInput)
    {
        return true;
    }

    return false;
}

// UID:0004A5 | by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md | Completion:91 | Confidence:94
bool SpellMacroEditControlPane::HandlePointerOrMouseEvent(Event *)
{
    return true;
}

// UID:0003DB | by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md | Completion:90 | Confidence:94
// [UID:0003DB] Compiler-generated MSVC vtable/RTTI data for SpellMacroEditControlPane,
// NewMacroEditControlPane, and IntegrateMacroEditControlPane is covered by the
// MacroDialogs.cpp class declarations and virtual method definitions; do not
// hand-emit raw .rdata vtable bytes.

// UID:0001Y1 | by-type/by-vtable/MacroDialogFamilyVtables.md | Completion:92 | Confidence:94
// Compiler-generated MSVC RTTI and vtable data for the MacroDialogs class family;
// do not emit handwritten vtable or RTTI arrays.

// UID:00038D | by-memory\0x00542800-0x00542855.NewMacroDialogScalarDeletingDestructor.md | Completion:87 | Confidence:92 | Empty Emitter Marker
