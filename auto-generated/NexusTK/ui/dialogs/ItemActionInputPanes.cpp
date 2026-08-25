// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KC
// Source by-file doc: by-file/ItemActionInputPanes.md
// UID:0004U0 | by-memory/0x005a9f00-0x005a9fd6.CreateWieldInputPane.md | Completion:89 | Confidence:91
WieldInputPane *CreateWieldInputPane()
{
    return new WieldInputPane();
}

// UID:00001J | by-class/ChangeItemSlotInputPane.md | Completion:90 | Confidence:92
class ChangeItemSlotInputPane : public CharArgsInputPane
{
public:
    ChangeItemSlotInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnSubmitInput();
};

// UID:0001M5 | by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md | Completion:87 | Confidence:90
ChangeItemSlotInputPane::ChangeItemSlotInputPane()
    : CharArgsInputPane(g_pLanguageMan->GetLocalizedString(46))
{
}

// UID:0001M6 | by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md | Completion:91 | Confidence:93
bool ChangeItemSlotInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        g_pGeneralPurposePanel->SwitchActiveTab(2, NULL);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharArgsInputPane::HandleKeyOrTextEvent(event);
}

void ChangeItemSlotInputPane::OnSubmitInput()
{
    wchar_t text[128];
    GetInputText(text, 127);

    wchar_t *comma = wcschr(text, L',');
    if (comma == NULL)
        return;

    *comma = L'\0';

    unsigned char sourceSlot = 0xff;
    const wchar_t sourceChar = text[0];
    if (sourceChar >= L'a' && sourceChar <= L'z') {
        sourceSlot = static_cast<unsigned char>(sourceChar - L'a' + 1);
    } else if (sourceChar >= L'A' && sourceChar <= L'Z') {
        sourceSlot = static_cast<unsigned char>(sourceChar - L'A' + 27);
    }

    unsigned char destinationSlot = 0xff;
    const wchar_t destinationChar = comma[1];
    if (destinationChar >= L'a' && destinationChar <= L'z') {
        destinationSlot = static_cast<unsigned char>(destinationChar - L'a' + 1);
    } else if (destinationChar >= L'A' && destinationChar <= L'Z') {
        destinationSlot = static_cast<unsigned char>(destinationChar - L'A' + 27);
    }

    const unsigned char maxItemSlot =
        g_activeUserStatusPane->m_inventorySlotCount;
    if (sourceSlot < 1 || sourceSlot > maxItemSlot ||
        destinationSlot < 1 || destinationSlot > maxItemSlot) {
        return;
    }

    unsigned char packet[5];
    packet[0] = 0x30;
    PacketBufferWriteUInt8(0, &packet[1]);
    PacketBufferWriteUInt8(sourceSlot, &packet[2]);
    PacketBufferWriteUInt8(destinationSlot, &packet[3]);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
}

// UID:000042 | by-class/DropAllInputPane.md | Completion:86 | Confidence:88
// No standalone class-page emission for DropAllInputPane; this page routes ownership for the exact DropAll method bodies documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[No Children Attached]]

// UID:000043 | by-class/DropGoldInputPane.md | Completion:87 | Confidence:88
// No standalone class-page emission for DropGoldInputPane; constructor source is [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) and submit/helper evidence is documented by [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
// UID:0001MH | by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md | Completion:88 | Confidence:90
DropGoldInputPane::DropGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(7))
{
}

// UID:000044 | by-class/DropInputPane.md | Completion:86 | Confidence:88
// No standalone class-page emission for DropInputPane; exact Drop method bodies and gold-branch evidence are documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[No Children Attached]]

// UID:000047 | by-class/EatInputPane.md | Completion:86 | Confidence:88
// No standalone class-page emission for EatInputPane; exact Eat method bodies are documented in [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) and must stay separate from [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md).
[[No Children Attached]]

// UID:00005S | by-class/GiveAllInputPane.md | Completion:85 | Confidence:88
// No standalone class-page emission for GiveAllInputPane; this page routes ownership for the exact GiveAll method bodies documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[No Children Attached]]

// UID:00005T | by-class/GiveGoldInputPane.md | Completion:87 | Confidence:89
// No standalone class-page emission for GiveGoldInputPane; constructor source is [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) and submit/helper evidence is documented by [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
// UID:0001MI | by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md | Completion:88 | Confidence:90
GiveGoldInputPane::GiveGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetLocalizedString(0x2b))
{
}

// UID:00005U | by-class/GiveInputPane.md | Completion:85 | Confidence:88
// No standalone class-page emission for GiveInputPane; exact Give method bodies and gold-branch evidence are documented in [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md).
[[No Children Attached]]

// UID:0000EC | by-class/TakeOffInputPane.md | Completion:90 | Confidence:91
class TakeOffInputPane : public CharInputPane
{
public:
    TakeOffInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void ProcessUnequipCommand();
};

// UID:0001M0 | by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md | Completion:88 | Confidence:90
TakeOffInputPane::TakeOffInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0x22))
{
}

// UID:0004TB | by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md | Completion:90 | Confidence:92
bool TakeOffInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        char packet[2];
        WritePacketByte(0x2d, packet);
        packet[1] = 0;
        QueueAndSendPacket(g_packetSender, packet, 1);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

// UID:0001M1 | by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md | Completion:87 | Confidence:89
// No standalone aggregate emission; TakeOffInputPane source is split across [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md), [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md), and the exact method boundaries recorded by this range.

// UID:0000EY | by-class/ThrowInputPane.md | Completion:86 | Confidence:90
// No standalone class-page emission for ThrowInputPane; exact Throw method bodies are documented in [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md).
[[No Children Attached]]

// UID:0000EZ | by-class/ThrowReallyInputPane.md | Completion:87 | Confidence:89
// No standalone class-page emission for ThrowReallyInputPane; constructor and confirmed-send helper source is routed by [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) and [UID:0003NY][0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw](by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md).
// UID:0001MM | by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md | Completion:88 | Confidence:90
ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0xa5)),
      m_itemSlot(itemSlot)
{
}

// UID:0003NY | by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md | Completion:88 | Confidence:90
void ThrowReallyInputPane::SendThrowConfirmedItemPacket()
{
    char packet[128];

    PacketBufferWriteUInt8(0x17, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt8(m_itemSlot, packet + 2);
    packet[3] = 0;

    g_packetSender->QueueAndSendPacket(packet, 3);
}

// UID:0000FG | by-class/UseInputPane.md | Completion:86 | Confidence:88
// No standalone class-page emission for UseInputPane; live use dispatch remains [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) and adjacent helper source is [UID:0003NZ][0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw](by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md).
[[No Children Attached]]

// UID:0000G0 | by-class/WearInputPane.md | Completion:87 | Confidence:91
// No standalone class-page emission for WearInputPane; method-cluster evidence is [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md) and packet helper source is [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md).
// UID:0001MT | by-memory/0x005b6560-0x005b6760.WearInputPane.md | Completion:87 | Confidence:91
// No standalone aggregate emission; WearInputPane packet helper source is emitted by [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md), and this range records constructor, key-handler, and submit-handler boundaries.

// UID:0002YP | by-memory/0x005b6760-0x005b67c0.SendWearPacket.md | Completion:88 | Confidence:90
static int SendWearPacket(unsigned char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x1e, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:0000G4 | by-class/WieldInputPane.md | Completion:92 | Confidence:94
class WieldInputPane : public CharInputPane
{
public:
    WieldInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnSubmitInput();

private:
    int SendWieldPacket(unsigned char itemSlot);
};

// UID:0004U2 | by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md | Completion:92 | Confidence:94
WieldInputPane::WieldInputPane()
    : CharInputPane(NULL)
{
    wchar_t slotRange[100];
    wchar_t prompt[128];

    g_pUserPane->BuildInventorySlotRangeText(slotRange);
    swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(13), slotRange);
    SetPromptText(prompt);
}

// UID:0004U4 | by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool WieldInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown)
    {
        g_pGeneralPurposePanel->SwitchActiveTab(2, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

// UID:0004U6 | by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md | Completion:92 | Confidence:94
void WieldInputPane::OnSubmitInput()
{
    if (TextLength() != 1)
        return;

    wchar_t input = 0;
    CopyText(&input, 1);

    if (input == L'-')
    {
        unsigned char packet[128];
        PacketBufferWriteUInt8(0x12, packet);
        PacketBufferWriteUInt8(0, packet + 1);
        packet[2] = 0;
        g_packetSender->QueueAndSendPacket(packet, 2);
        return;
    }

    char selectedSlot;
    if (input >= L'a' && input <= L'z')
        selectedSlot = (char)(input - L'a' + 1);
    else if (input >= L'A' && input <= L'Z')
        selectedSlot = (char)(input - L'A' + 27);
    else
        return;

    if (selectedSlot < 1 ||
        selectedSlot > g_activeUserStatusPane->m_inventorySlotCount)
        return;

    SendWieldPacket((unsigned char)selectedSlot);
}

// UID:0001MS | by-memory/0x005b6500-0x005b6560.SendWieldPacket.md | Completion:91 | Confidence:93
int WieldInputPane::SendWieldPacket(unsigned char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x12, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 2);
}

// UID:0000PX | by-global/g_equipmentSlotKeys.md | Completion:90 | Confidence:90
// UID:0001OF | by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md | Completion:90 | Confidence:92
static const wchar_t g_equipmentSlotKeys[23] = {
    L'w', L'a', L's', L'h', L'#', L'n', L'l', L'r',
    L'#', L'#', L'#', L'#', L'f', L'm', L'#', L'c',
    L'#', L'#', L'#', L'[', L']', L'1', L'2'
};

// UID:0001M2 | by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md | Completion:89 | Confidence:90
void SendTakeOffPacket(char equipmentSlotSelector)
{
    char packet[128];

    if (g_activeDialogCount <= 0) {
        PacketBufferWriteUInt8(0x1f, packet);
        PacketBufferWriteUInt8(equipmentSlotSelector, packet + 1);
        packet[2] = 0;
        g_packetSender->QueueAndSendPacket(packet, 2);
    }
}

// UID:00042U | by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md | Completion:88 | Confidence:91
static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)
{
    unsigned char packet[128];

    packet[0] = 0x30;
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt8(sourceSlot, packet + 2);
    PacketBufferWriteUInt8(destinationSlot, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}

// UID:0001MG | by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md | Completion:88 | Confidence:90
// Split/index aggregate for the Drop/Give item-action input-pane range.
// Source for this address island belongs to exact DropAll/Drop/DropGold/GiveAll/Give/GiveGold class and helper pages under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
// Do not emit a synthetic monolithic DropGiveInputPanes body for this mixed range.








// UID:0003NZ | by-memory/0x005b5e60-0x005b5ebe.SendUseItemSlotPacketRaw.md | Completion:88 | Confidence:90
static void SendUseItemSlotPacket(char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    g_packetSender->QueueAndSendPacket(packet, 2);
}


// UID:0001XU | by-type/by-vtable/ItemActionInputPaneVtableFamily.md | Completion:86 | Confidence:89
// No raw vtable emission; ItemActionInputPane vtables are compiler-generated from the item-action pane class declarations and exact child methods under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).

// UID:0003FK | by-memory\0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003FL | by-memory\0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003FM | by-memory\0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003FN | by-memory\0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003FO | by-memory\0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003MW | by-memory\0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003NX | by-memory\0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003J4 | by-memory\0x00630a90-0x00630af0.DropItemConfirmationPromptString.md | Completion:86 | Confidence:92 | Empty Emitter Marker
