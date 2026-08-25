// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MJ
// Source by-file doc: by-file/PhoneBookDialog.md
// UID:00003R | by-class/DialDialog.md | Completion:94 | Confidence:95
class SocketPacket;

class DialDialog : public DialogPane {
public:
    DialDialog(const wchar_t *phoneNumber);

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual char ParseModemResponse(SocketPacket *packet);

private:
    wchar_t m_phoneNumber[64];
    int m_modemResponseState;
};
