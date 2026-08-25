// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M1
// Source by-file doc: by-file/NumberInputDialog.md
// UID:00009K | by-class/NumberInputDialog.md | Completion:94 | Confidence:95
class FunctionObject0;

template <class TArg>
class FunctionObjectT;

class NumberInputDialog : public DialogPane
{
public:
    NumberInputDialog(const wchar_t *promptText,
                      FunctionObjectT<unsigned long> *confirmCallback,
                      FunctionObject0 *cancelCallback,
                      int minValue,
                      int maxValue);
    virtual ~NumberInputDialog();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    enum NumberInputDialogControlId
    {
        kNumberInputOkButtonId = 1,
        kNumberInputCancelButtonId = 2,
        kNumberInputPromptLabelId = 3,
        kNumberInputEditControlId = 4
    };

    enum
    {
        kNumberInputInvalidNumberStringId = 217,
        kNumberInputOkButtonImage = 14,
        kNumberInputCancelButtonImage = 22
    };

    FunctionObjectT<unsigned long> *m_confirmCallback;
    FunctionObject0 *m_cancelCallback;
    int m_minValue;
    int m_maxValue;
};
