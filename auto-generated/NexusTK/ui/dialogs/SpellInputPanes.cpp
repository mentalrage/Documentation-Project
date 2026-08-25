// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O0
// Source by-file doc: by-file/SpellInputPanes.md
// UID:00001M | by-class/ChangeSpellSlotInputPane.md | Completion:90 | Confidence:92
class ChangeSpellSlotInputPane : public CharArgsInputPane
{
public:
    ChangeSpellSlotInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void SubmitSpellSlotChange();
};

// UID:0001M7 | by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md | Completion:88 | Confidence:91
ChangeSpellSlotInputPane::ChangeSpellSlotInputPane()
    : CharArgsInputPane(g_pLanguageMan->GetLocalizedString(45))
{
}

// UID:0001M9 | by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md | Completion:91 | Confidence:93
bool ChangeSpellSlotInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        g_pGeneralPurposePanel->SwitchActiveTab(3, NULL);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharArgsInputPane::HandleKeyOrTextEvent(event);
}

// UID:0001MA | by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md | Completion:88 | Confidence:91
void ChangeSpellSlotInputPane::SubmitSpellSlotChange()
{
    wchar_t text[128];

    GetInputText(text, 127);

    wchar_t *comma = wcschr(text, L',');
    if (comma == NULL) {
        return;
    }

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

    if (sourceSlot < 1 || sourceSlot > 52 ||
        destinationSlot < 1 || destinationSlot > 52) {
        return;
    }

    if (g_pUserPane->m_spellSlotRecords[sourceSlot].active == 1 ||
        g_pUserPane->m_spellSlotRecords[destinationSlot].active == 1) {
        g_pUserPane->m_spellSlotCacheDirty = false;
    }

    unsigned char packet[5];
    packet[0] = 0x30;
    PacketBufferWriteUInt8(1, &packet[1]);
    PacketBufferWriteUInt8(sourceSlot, &packet[2]);
    PacketBufferWriteUInt8(destinationSlot, &packet[3]);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
}

// UID:0002N5 | by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md | Completion:87 | Confidence:91
// Emitted code for this ChangeSpellSlotInputPane vtable/RTTI range is covered by
// [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
// and exact virtual method children [UID:0001M9][0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput](by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md) and [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md).
// Do not hand-emit raw .rdata vtable bytes.


// UID:0000DL | by-class/SpellFourArgsInputPane.md | Completion:91 | Confidence:94
// UID:0001LM | by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md | Completion:91 | Confidence:94
SpellFourArgsInputPane::SpellFourArgsInputPane(char spellIndex)
    : NumberArgsInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0004TY | by-memory/0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor.md | Completion:91 | Confidence:94
SpellFourArgsInputPane::~SpellFourArgsInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001LO | by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md | Completion:88 | Confidence:90
void SpellFourArgsInputPane::OnConfirmInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    wchar_t *firstComma = wcschr(text, L',');
    if (firstComma == NULL) {
        return;
    }

    wchar_t *secondComma = wcschr(firstComma + 1, L',');
    if (secondComma == NULL) {
        return;
    }

    wchar_t *thirdComma = wcschr(secondComma + 1, L',');
    if (thirdComma == NULL) {
        return;
    }

    const short firstArgument = static_cast<short>(_wtol(text));
    const short secondArgument = static_cast<short>(_wtol(firstComma + 1));
    const short thirdArgument = static_cast<short>(_wtol(secondComma + 1));
    const short fourthArgument = static_cast<short>(_wtol(thirdComma + 1));

    unsigned char packet[11];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(firstArgument, packet + 2);
    PacketBufferWriteUInt16BE(secondArgument, packet + 4);
    PacketBufferWriteUInt16BE(thirdArgument, packet + 6);
    PacketBufferWriteUInt16BE(fourthArgument, packet + 8);
    packet[10] = 0;

    QueueAndSendPacket(g_packetSender, packet, 10);
}

// UID:0000DR | by-class/SpellOneArgInputPane.md | Completion:91 | Confidence:94
// UID:0001LT | by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md | Completion:89 | Confidence:93
SpellOneArgInputPane::SpellOneArgInputPane(char spellIndex)
    : NumberArgsInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0004UB | by-memory/0x005b10c0-0x005b1143.SpellOneArgInputPaneDestructor.md | Completion:91 | Confidence:94
SpellOneArgInputPane::~SpellOneArgInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001LU | by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md | Completion:88 | Confidence:90
void SpellOneArgInputPane::OnSubmitInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    const short argument = static_cast<short>(_wtol(text));

    unsigned char packet[5];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(argument, packet + 2);
    packet[4] = 0;

    QueueAndSendPacket(g_packetSender, packet, 4);
}

// UID:0000DS | by-class/SpellSlotInputPane.md | Completion:93 | Confidence:94
#include "SpellInputPanes.h"

// UID:0001LV | by-memory/0x005b1280-0x005b130d.SpellSlotInputPaneConstructor.md | Completion:89 | Confidence:93
SpellSlotInputPane::SpellSlotInputPane(char spellIndex)
    : CharInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0004UC | by-memory/0x005b1310-0x005b1393.SpellSlotInputPaneDestructor.md | Completion:91 | Confidence:94
SpellSlotInputPane::~SpellSlotInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001LW | by-memory/0x005b13a0-0x005b140c.SpellSlotInputPaneKeyInput.md | Completion:91 | Confidence:93
bool SpellSlotInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        g_pGeneralPurposePanel->SwitchActiveTab(3, NULL);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

// UID:0001LX | by-memory/0x005b1410-0x005b14e6.SpellSlotInputPaneSubmitSpellSlot.md | Completion:93 | Confidence:94
void SpellSlotInputPane::SubmitSpellSlot()
{
    if (GetTextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    char inventorySlot = -1;
    if (ch >= L'a' && ch <= L'z') {
        inventorySlot = static_cast<char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        inventorySlot = static_cast<char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (inventorySlot < 1 ||
        inventorySlot > g_activeUserStatusPane->m_inventorySlotCount) {
        return;
    }

    SendSpellUsePacket(inventorySlot);
}

// UID:0003VX | by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md | Completion:93 | Confidence:94
void SpellSlotInputPane::SendSpellUsePacket(char inventorySlot)
{
    unsigned char packet[300];

    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt8(inventorySlot, packet + 2);
    packet[3] = 0;

    g_packetSender->QueueAndSendPacket(packet, 3);
}

// UID:0000DT | by-class/SpellSpellInputPane.md | Completion:90 | Confidence:93
class SpellSpellInputPane : public CharInputPane
{
public:
    SpellSpellInputPane();
    virtual ~SpellSpellInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnAccept();
};

// UID:0001MN | by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md | Completion:86 | Confidence:90
SpellSpellInputPane::SpellSpellInputPane()
    : CharInputPane(false)
{
    wchar_t availableSlots[100];
    wchar_t prompt[128];

    BuildAvailableSpellSlotRangeText(g_pUserPane, availableSlots);

    const wchar_t *format = g_pLanguageMan->GetLocalizedString(36);
    swprintf_s(prompt, 128, format, availableSlots);

    SetPromptText(prompt);
}

// UID:0001MP | by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool SpellSpellInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        g_pGeneralPurposePanel->SwitchActiveTab(3, NULL);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

// UID:0001MQ | by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md | Completion:87 | Confidence:90
void SpellSpellInputPane::OnAccept()
{
    if (GetTextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    unsigned char slot = 0xff;
    if (ch >= L'a' && ch <= L'z') {
        slot = static_cast<unsigned char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        slot = static_cast<unsigned char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (slot != 0xff) {
        g_pUserPane->UseCommandSlot(slot);
    }
}

// UID:0002N7 | by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md | Completion:90 | Confidence:94
// Emitted code for this SpellSpellInputPane vtable/RTTI range is covered by
// [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
// and exact virtual method children [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md) and [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md).
// Do not hand-emit raw .rdata vtable bytes.

// UID:0000DU | by-class/SpellStringInputPane.md | Completion:89 | Confidence:92
// UID:0001KU | by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md | Completion:89 | Confidence:93
SpellStringInputPane::SpellStringInputPane(char spellIndex)
    : LineInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0003AG | by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md | Completion:88 | Confidence:92
SpellStringInputPane::~SpellStringInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001KW | by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md | Completion:90 | Confidence:91
#include "../../auth/PasswordGuard.h"

void SpellStringInputPane::OnConfirmInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t inputText[256];
    CopyText(inputText, 255);

    ValidateChatInputOrThrowPasswordError(inputText);
    SanitizeWideTextForChat(inputText, static_cast<unsigned int>(wcslen(inputText)));

    unsigned char packet[300];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);

    char encodedText[256];
    const int encodedLength = WideCharToMultiByte(
        0,
        0,
        inputText,
        static_cast<int>(wcslen(inputText)),
        encodedText,
        static_cast<int>(sizeof(encodedText)),
        NULL,
        NULL);
    encodedText[encodedLength] = 0;

    memmove(packet + 2, encodedText, encodedLength);

    const int packetLength = encodedLength + 2;
    packet[packetLength] = 0;

    QueueAndSendPacket(g_packetSender, packet, packetLength);
}

// UID:0001NH | by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md | Completion:86 | Confidence:90
// Compiler-generated scalar deleting destructor for SpellStringInputPane.
// Source cleanup is represented by SpellStringInputPane::~SpellStringInputPane()
// at [UID:0003AG][0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor](by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md).

// UID:0000DV | by-class/SpellThreeArgsInputPane.md | Completion:91 | Confidence:94
// UID:0001LP | by-memory/0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md | Completion:89 | Confidence:93
SpellThreeArgsInputPane::SpellThreeArgsInputPane(char spellIndex)
    : NumberArgsInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0004UD | by-memory/0x005b0b50-0x005b0bd3.SpellThreeArgsInputPaneDestructor.md | Completion:91 | Confidence:94
SpellThreeArgsInputPane::~SpellThreeArgsInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001LQ | by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md | Completion:88 | Confidence:90
void SpellThreeArgsInputPane::OnConfirmInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    wchar_t *firstComma = wcschr(text, L',');
    if (firstComma == NULL) {
        return;
    }

    wchar_t *secondComma = wcschr(firstComma + 1, L',');
    if (secondComma == NULL) {
        return;
    }

    const short firstArgument = static_cast<short>(_wtol(text));
    const short secondArgument = static_cast<short>(_wtol(firstComma + 1));
    const short thirdArgument = static_cast<short>(_wtol(secondComma + 1));

    unsigned char packet[9];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(firstArgument, packet + 2);
    PacketBufferWriteUInt16BE(secondArgument, packet + 4);
    PacketBufferWriteUInt16BE(thirdArgument, packet + 6);
    packet[8] = 0;

    QueueAndSendPacket(g_packetSender, packet, 8);
}

// UID:0000DW | by-class/SpellTwoArgsInputPane.md | Completion:91 | Confidence:94
// UID:0001LR | by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md | Completion:89 | Confidence:93
SpellTwoArgsInputPane::SpellTwoArgsInputPane(char spellIndex)
    : NumberArgsInputPane(NULL),
      m_spellIndex(spellIndex)
{
    SetPromptText(g_pUserPane->GetSpellPromptText(spellIndex));
}

// UID:0004UE | by-memory/0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor.md | Completion:91 | Confidence:94
SpellTwoArgsInputPane::~SpellTwoArgsInputPane()
{
    if (g_useEpfAssets) {
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    } else {
        static_cast<SpellInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3))->SetInputModeFlag(false);
    }
}

// UID:0001LS | by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md | Completion:88 | Confidence:90
void SpellTwoArgsInputPane::OnConfirmInput()
{
    if (GetTextLength() <= 0) {
        return;
    }

    wchar_t text[256];
    CopyText(text, 255);

    wchar_t *comma = wcschr(text, L',');
    if (comma == NULL) {
        return;
    }

    const short firstArgument = static_cast<short>(_wtol(text));
    const short secondArgument = static_cast<short>(_wtol(comma + 1));

    unsigned char packet[7];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt16BE(firstArgument, packet + 2);
    PacketBufferWriteUInt16BE(secondArgument, packet + 4);
    packet[6] = 0;

    QueueAndSendPacket(g_packetSender, packet, 6);
}

// UID:0003HJ | by-type\by-vtable\ChangeSpellSlotInputPaneVtables.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003VV | by-memory\0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md | Completion:87 | Confidence:88 | Empty Emitter Marker
