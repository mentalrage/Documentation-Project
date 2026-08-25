// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M1
// Source by-file doc: by-file/NumberInputDialog.md
// UID:00009K | by-class/NumberInputDialog.md | Completion:94 | Confidence:95
// [UID:00009K] NumberInputDialog class support: exact method bodies are emitted by registered by-memory children.
// UID:0001CV | by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md | Completion:92 | Confidence:94
NumberInputDialog::NumberInputDialog(const wchar_t *promptText,
                                     FunctionObjectT<unsigned long> *confirmCallback,
                                     FunctionObject0 *cancelCallback,
                                     int minValue,
                                     int maxValue)
    : DialogPane(L"", 16, 1),
      m_confirmCallback(confirmCallback),
      m_cancelCallback(cancelCallback),
      m_minValue(minValue),
      m_maxValue(maxValue)
{
    RectBounds controlBounds;
    RectBounds dialogBounds;

    if (g_useEpfAssets == 1) {
        InitRectBounds(&dialogBounds, 0, 0, 239, 283);
        AddControl(new EPFImageControlPane(L"DLGEXC3.EPF", 0, 1,
                                           &dialogBounds, L"PAL01.PAL"));

        InitRectBounds(&controlBounds, 50, 149, 113, 173);
        AddControl(new ImageButtonControlPane(kNumberInputOkButtonImage,
                                              &controlBounds));

        InitRectBounds(&controlBounds, 129, 149, 192, 173);
        AddControl(new ImageButtonControlPane(kNumberInputCancelButtonImage,
                                              &controlBounds));

        InitRectBounds(&controlBounds, 28, 35, 211, 107);
        AddControl(new StaticTextControlPane(promptText, true, 128, 0,
                                             &controlBounds, false, false));

        InitRectBounds(&controlBounds, 28, 111, 211, 123);
        AddControl(new TextEditControlPane(L"", true, 128, 0,
                                           &controlBounds, false, false,
                                           false, false, 1.0f, false));

        SetBackgroundResource(L"DLGEXC3.EPF", 0);
    } else {
        InitRectBounds(&dialogBounds, 0, 0, 287, 277);
        AddControl(new EPFImageControlPane(L"DLGEXC3.EPD", 0, 1,
                                           &dialogBounds, L"NPAL8.PAL"));

        InitRectBounds(&controlBounds, 69, 225, 141, 241);
        AddControl(new ImageButtonControlPane(kNumberInputOkButtonImage,
                                              &controlBounds));

        InitRectBounds(&controlBounds, 146, 225, 218, 241);
        AddControl(new ImageButtonControlPane(kNumberInputCancelButtonImage,
                                              &controlBounds));

        InitRectBounds(&controlBounds, 37, 36, 249, 119);
        AddControl(new StaticTextControlPane(promptText, true, 128, 0,
                                             &controlBounds, false, false));

        InitRectBounds(&controlBounds, 52, 129, 234, 141);
        AddControl(new TextEditControlPane(L"", true, 128, 0,
                                           &controlBounds, false, false,
                                           false, false, 1.0f, false));

        SetBackgroundResource(L"DLGEXC3.EPD", 0);
    }

    SetHoverControl(kNumberInputEditControlId);
    SetFocusedControl(kNumberInputOkButtonId);
    SetPendingControl(kNumberInputCancelButtonId);
    OnCreate(&dialogBounds, 0, 0,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(0, 0);
    SlideOpenVertical();
}

// UID:0001CX | by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md | Completion:94 | Confidence:96
NumberInputDialog::~NumberInputDialog()
{
    delete m_confirmCallback;
    m_confirmCallback = 0;
}

// UID:0001CY | by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md | Completion:93 | Confidence:95
void NumberInputDialog::OnControlCommand(int controlId, int /*notifyCode*/)
{
    if (controlId == kNumberInputOkButtonId) {
        const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > inputText =
            GetChild<TextEditControlPane>(kNumberInputEditControlId)->GetInputText();
        const int value = static_cast<int>(inputText.ToLong());

        if (value < m_minValue || value > m_maxValue) {
            const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > message =
                g_pLanguageMan->CopyLocalizedString(kNumberInputInvalidNumberStringId);
            new AlertPane(message.c_str(), this, L"OK", 0);
            return;
        }

        if (m_confirmCallback != 0) {
            m_confirmCallback->Invoke(static_cast<unsigned long>(value));
        }

        CloseDialog();
        return;
    }

    if (controlId == kNumberInputCancelButtonId) {
        CloseDialog();

        if (m_cancelCallback != 0) {
            m_cancelCallback->Invoke();
        }
    }
}

// UID:0001D0 | by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md | Completion:93 | Confidence:96
// Emitted code for this range is covered by [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md).

// UID:0003C8 | by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md | Completion:93 | Confidence:96
// Emitted code for this range is covered by [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md).
