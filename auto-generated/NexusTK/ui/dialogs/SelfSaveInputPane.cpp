// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NM
// Source by-file doc: by-file/SelfSaveInputPane.md
// UID:0000CW | by-class/SelfSaveInputPane.md | Completion:91 | Confidence:93
class SelfSaveInputPane : public CharInputPane
{
public:
    SelfSaveInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kSelfSavePromptStringId = 0x26;

private:
    void SendSelfSavePacket();
};

// UID:0003O5 | by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md | Completion:88 | Confidence:90
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(kSelfSavePromptStringId))
{
}

// UID:0003O6 | by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md | Completion:92 | Confidence:93
void SelfSaveInputPane::OnConfirmInput()
{
    if (TextLength() != 1)
        return;

    wchar_t response = 0;
    CopyText(&response, 1);
    if (response != L'y' && response != L'Y')
        return;

    SendSelfSavePacket();
}

// UID:0003O7 | by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md | Completion:92 | Confidence:92
void SelfSaveInputPane::SendSelfSavePacket()
{
    unsigned char packet[16];

    PacketBufferWriteUInt8(0x25, packet);
    packet[1] = 0;

    g_packetSender->QueueAndSendPacket(packet, 1);
}

// UID:0002N8 | by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md | Completion:91 | Confidence:94
// SelfSaveInputPane vtables and RTTI are compiler-generated from the class
// declaration and virtual methods. Do not hand-author the
// 0x006305c0-0x00630648 table or locator dwords as C++.

// UID:0003HM | by-type/by-vtable/SelfSaveInputPaneVtables.md | Completion:90 | Confidence:94
// SelfSaveInputPaneVtables is the source-local index for UID0002N8.
// Regenerate the tables through SelfSaveInputPane; do not duplicate fixed
// vtable, RTTI, scalar-destructor, or adjustor-thunk bytes here.

// UID:0001KQ | by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md | Completion:87 | Confidence:88
SelfSaveInputPane *CreateSelfSaveInputPane()
{
    return new SelfSaveInputPane;
}
