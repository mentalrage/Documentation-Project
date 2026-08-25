// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N9
// Source by-file doc: by-file/SayInputPanes.md
// UID:000099 | by-class/NewSayToUserMessageInputPane.md | Completion:93 | Confidence:94
#include "SayInputPanes.h"

#include "Chatting.h"
#include "../auth/PasswordGuard.h"
#include "../ui/core/BlackHole.h"
#include "../ui/panels/UserPane.h"

// UID:000403 | by-memory/0x005b1990-0x005b1d42.NewSayToUserMessageInputPaneMethods.md | Completion:94 | Confidence:95
NewSayToUserMessageInputPane::NewSayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wchar_t prompt[128];

    wcscpy_s(m_recipientName, _countof(m_recipientName), recipientName);
    swprintf_s(prompt, _countof(prompt), L"To %s : ", m_recipientName);
    SetPromptText(prompt);
}

void NewSayToUserMessageInputPane::OnSubmitInput()
{
    if (TextLength() > 0) {
        wchar_t messageText[256];
        char convertedText[256];
        unsigned char packet[0x12c];

        CopyText(messageText, 255);
        ValidateChatInputOrThrowPasswordError(messageText);
        SanitizeWideTextForChat(messageText, wcslen(messageText));

        int packetLength = 0;
        PacketBufferWriteUInt8(0x19, packet + packetLength++);

        const unsigned int recipientLength = WideCharToMultiByte(
            CP_ACP, 0, m_recipientName,
            static_cast<int>(wcslen(m_recipientName)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[recipientLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(recipientLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, recipientLength);
        packetLength += recipientLength;

        const unsigned int messageLength = WideCharToMultiByte(
            CP_ACP, 0, messageText,
            static_cast<int>(wcslen(messageText)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[messageLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(messageLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, messageLength);
        packetLength += messageLength;

        packet[packetLength] = 0;
        g_packetSender->QueueAndSendPacket(
            packet, static_cast<short>(packetLength));
    }
}

bool NewSayToUserMessageInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_payload.m_key.m_modifiers != 0 ||
        key != '\b' ||
        TextLength() > 0) {
        return LineInputPane::HandleKeyOrTextEvent(event);
    }

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    g_pUserPane->ClearActiveLineInputPane();

    if (g_pChattingHandlePane->m_chatTargetPending) {
        g_pUserPane->m_currentSayMode = kSayInputModeDefault;
        g_pChattingVarietyPane->Refresh();
    }

    new SayToUserNameInputPane();
    return true;
}

// UID:0000C6 | by-class/SayToUserMessageInputPane.md | Completion:93 | Confidence:94
// UID:000401 | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md | Completion:94 | Confidence:95
SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wchar_t prompt[128];

    wcscpy_s(m_recipientName, _countof(m_recipientName), recipientName);
    swprintf_s(prompt, _countof(prompt), L"-> %s: ", m_recipientName);
    SetPromptText(prompt);
}

void SayToUserMessageInputPane::OnSubmitInput()
{
    if (TextLength() > 0) {
        wchar_t messageText[256];
        char convertedText[256];
        unsigned char packet[0x12c];

        CopyText(messageText, 255);
        ValidateChatInputOrThrowPasswordError(messageText);
        SanitizeWideTextForChat(messageText, wcslen(messageText));

        int packetLength = 0;
        PacketBufferWriteUInt8(0x19, packet + packetLength++);

        const unsigned int recipientLength = WideCharToMultiByte(
            CP_ACP, 0, m_recipientName,
            static_cast<int>(wcslen(m_recipientName)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[recipientLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(recipientLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, recipientLength);
        packetLength += recipientLength;

        const unsigned int messageLength = WideCharToMultiByte(
            CP_ACP, 0, messageText,
            static_cast<int>(wcslen(messageText)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[messageLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(messageLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, messageLength);
        packetLength += messageLength;

        packet[packetLength] = 0;
        g_packetSender->QueueAndSendPacket(
            packet, static_cast<short>(packetLength));
    }
}

// UID:0000C4 | by-class/SayToGroupMessageInputPane.md | Completion:93 | Confidence:94
// UID:0001LZ | by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md | Completion:90 | Confidence:92
SayToGroupMessageInputPane::SayToGroupMessageInputPane(const wchar_t *groupName)
    : LineInputPane(0)
{
    wcscpy_s(m_groupName, _countof(m_groupName), groupName);
    SetPromptText(L"Group => ");
}

void SayToGroupMessageInputPane::OnSubmitInput()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t messageText[256] = {};
    CopyText(messageText, _countof(messageText) - 1);
    ValidateChatInputOrThrowPasswordError(messageText);
    SanitizeWideTextForChat(messageText, wcslen(messageText));

    char groupNameBytes[256] = {};
    const int groupNameLen = WideCharToMultiByte(
        CP_ACP, 0, m_groupName, static_cast<int>(wcslen(m_groupName)),
        groupNameBytes, sizeof(groupNameBytes), nullptr, nullptr);
    if (groupNameLen >= 0x100) {
        return;
    }

    char messageBytes[256] = {};
    const int messageLen = WideCharToMultiByte(
        CP_ACP, 0, messageText, static_cast<int>(wcslen(messageText)),
        messageBytes, sizeof(messageBytes), nullptr, nullptr);
    if (messageLen >= 0x100) {
        return;
    }

    unsigned char packet[0x230] = {};
    int packetLength = 0;

    packet[packetLength++] = 0x19;
    packet[packetLength++] = static_cast<unsigned char>(groupNameLen);
    memcpy(packet + packetLength, groupNameBytes, groupNameLen);
    packetLength += groupNameLen;
    packet[packetLength++] = static_cast<unsigned char>(messageLen);
    memcpy(packet + packetLength, messageBytes, messageLen);
    packetLength += messageLen;

    if (packetLength >= 0x12c) {
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:0000C5 | by-class/SayToPlanMessageInputPane.md | Completion:93 | Confidence:94
// UID:000406 | by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md | Completion:94 | Confidence:95
SayToClanMessageInputPane::SayToClanMessageInputPane(
    const wchar_t *clanName)
    : LineInputPane(0)
{
    wcscpy_s(m_clanName, _countof(m_clanName), clanName);
    SetPromptText(L"Clan => ");
}

void SayToClanMessageInputPane::OnSubmitInput()
{
    if (TextLength() <= 0)
        return;

    wchar_t messageText[256];
    char convertedText[256];
    unsigned char packet[300];

    CopyText(messageText, 255);
    ValidateChatInputOrThrowPasswordError(messageText);
    SanitizeWideTextForChat(messageText, wcslen(messageText));

    int packetLength = 0;
    PacketBufferWriteUInt8(0x19, packet + packetLength++);

    const unsigned int clanNameLength = WideCharToMultiByte(
        CP_ACP, 0, m_clanName,
        static_cast<int>(wcslen(m_clanName)),
        convertedText, sizeof(convertedText), 0, 0);
    convertedText[clanNameLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(clanNameLength),
        packet + packetLength++);
    memcpy(packet + packetLength, convertedText, clanNameLength);
    packetLength += clanNameLength;

    const unsigned int messageLength = WideCharToMultiByte(
        CP_ACP, 0, messageText,
        static_cast<int>(wcslen(messageText)),
        convertedText, sizeof(convertedText), 0, 0);
    convertedText[messageLength] = '\0';
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(messageLength),
        packet + packetLength++);
    memcpy(packet + packetLength, convertedText, messageLength);
    packetLength += messageLength;

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

// UID:0000C3 | by-class/SayInputPane.md | Completion:93 | Confidence:94
// UID:0002S7 | by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md | Completion:88 | Confidence:91
SayInputPane::SayInputPane()
    : LineInputPane(L"> ")
{
    m_chatHistoryCursor = -1;
}

// UID:000414 | by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md | Completion:92 | Confidence:94
SayInputPane::SayInputPane(const wchar_t *initialText)
    : LineInputPane(L"> ")
{
    m_chatHistoryCursor = -1;

    m_textEditPane->InsertTextRange(
        initialText,
        static_cast<short>(wcslen(initialText)),
        NULL,
        NULL);
}

// UID:000415 | by-memory/0x005b3570-0x005b3670.SayInputPaneHandleKeyInput.md | Completion:94 | Confidence:95
bool SayInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0 ||
        (key != kPaneKeyUp && key != kPaneKeyDown)) {
        return LineInputPane::HandleKeyOrTextEvent(event);
    }

    wchar_t historyText[256];
    if (key == kPaneKeyUp) {
        g_pUserPane->GetPreviousChatHistoryLine(
            &m_chatHistoryCursor, historyText, _countof(historyText));
    } else {
        g_pUserPane->GetNextChatHistoryLine(
            &m_chatHistoryCursor, historyText, _countof(historyText));
    }

    if (historyText[0] != L'\0') {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            historyText,
            static_cast<short>(wcslen(historyText)),
            NULL,
            NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }

    return true;
}

// UID:000416 | by-memory/0x005b3670-0x005b37ea.SayInputPaneSubmitSayChat.md | Completion:88 | Confidence:90
void SayInputPane::OnSubmitInput()
{
    const short textLength = LineInputPane::TextLength();
    if (textLength <= 0) {
        return;
    }

    if (g_pCollectionData->chatInputSendBlocked != 0) {
        return;
    }

    wchar_t wideText[256] = {};
    LineInputPane::CopyText(wideText, 255);
    if (wideText[0] == L'\0') {
        return;
    }

    ValidateChatInputOrThrowPasswordError(wideText);
    SanitizeWideTextForChat(wideText, static_cast<int>(wcslen(wideText)));

    const unsigned char kChatMessageOpcode = 0x0e;
    const unsigned char kSayChatSubtype = 0;

    unsigned char packet[300] = {};
    char multibyteText[256] = {};
    void *packetCopyContext = GetMemoryMan();

    PacketBufferWriteUInt8(kChatMessageOpcode, packet + 0);
    PacketBufferWriteUInt8(kSayChatSubtype, packet + 1);

    const int convertedLength = WideCharToMultiByte(
        0, 0, wideText, static_cast<int>(wcslen(wideText)),
        multibyteText, sizeof(multibyteText), 0, 0);
    if (convertedLength >= 0x100) {
        ReportRangeCheckFailure();
    }

    multibyteText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength);

    const int packetLength = convertedLength + 3;
    if (packetLength >= 0x12c) {
        ReportRangeCheckFailure();
    }

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    g_pUserPane->SaveChatHistoryLine(wideText);
}

// UID:0000C7 | by-class/SayToUserNameInputPane.md | Completion:94 | Confidence:95
// UID:0001MD | by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md | Completion:93 | Confidence:94
SayToUserNameInputPane::SayToUserNameInputPane()
    : LineInputPane(g_useEpfAssets
          ? L"To "
          : g_pLanguageMan->GetLocalizedString(150)),
      m_recentRecipientHistoryIndex(-1),
      m_fallbackRecipientHistoryIndex(-1)
{
    wchar_t recipient[64] = L"";
    if (g_pUserPane->m_whisperHistorySource)
        g_pUserPane->GetPreviousRecentRecipientHistory(
            &m_recentRecipientHistoryIndex, recipient, _countof(recipient));
    else
        g_pUserPane->GetPreviousFallbackRecipientHistory(
            &m_fallbackRecipientHistoryIndex, recipient, _countof(recipient));

    if (recipient[0] != L'\0')
    {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            recipient, static_cast<short>(wcslen(recipient)), NULL, NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }
    m_deferSubmitUntilNextEvent = true;
}

[[No Children Attached]]

void SayToUserNameInputPane::OnSubmitInput()
{
    if (TextLength() <= 0)
        return;

    wchar_t recipient[256];
    CopyText(recipient, _countof(recipient) - 1);
    if (recipient[0] == L'\0')
        return;

    g_pUserPane->UpdateRecentRecipientList(recipient);
    if (g_useEpfAssets)
        new NewSayToUserMessageInputPane(recipient);
    else
        new SayToUserMessageInputPane(recipient);
}

// UID:0001ME | by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md | Completion:94 | Confidence:95
bool SayToUserNameInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    const unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    if (event->m_type != kEventKeyDown ||
        (key != kPaneKeyUp && key != kPaneKeyDown) ||
        (modifiers != 0 && modifiers != 4))
        return LineInputPane::HandleKeyOrTextEvent(event);

    List *history = modifiers == 4
        ? g_pUserPane->m_outgoingWhisperRecipientHistory
        : g_pUserPane->m_incomingWhisperSenderHistory;
    short *historyIndex = modifiers == 4
        ? &m_recentRecipientHistoryIndex
        : &m_fallbackRecipientHistoryIndex;
    wchar_t recipient[256] = L"";

    if (key == kPaneKeyUp)
    {
        if (modifiers == 4)
            g_pUserPane->GetPreviousRecentRecipientHistory(
                historyIndex, recipient, _countof(recipient));
        else
            g_pUserPane->GetPreviousFallbackRecipientHistory(
                historyIndex, recipient, _countof(recipient));
    }
    else if (history->GetCount() > 0)
    {
        const int index = (history->GetCount() + *historyIndex + 1) % history->GetCount();
        *historyIndex = static_cast<short>(index);
        wcscpy_s(recipient, _countof(recipient),
            static_cast<const wchar_t *>(history->GetElementAt(index)));
    }

    if (recipient[0] != L'\0')
    {
        m_textEditPane->SetSelectionRange(0, 0x7fff);
        m_textEditPane->InsertTextRange(
            recipient, static_cast<short>(wcslen(recipient)), NULL, NULL);
        m_textEditPane->SetSelectionRange(0, 0x7fff);
    }
    return true;
}

// UID:0000D5 | by-class/ShoutInputPane.md | Completion:93 | Confidence:94
// UID:0002SA | by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md | Completion:88 | Confidence:91
ShoutInputPane::ShoutInputPane()
    : LineInputPane(L"! ")
{
}

// UID:0001MF | by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md | Completion:90 | Confidence:91
void ShoutInputPane::OnSubmitInput()
{
    const short textLength = LineInputPane::TextLength();
    if (textLength <= 0) {
        return;
    }

    if (g_pCollectionData->chatInputSendBlocked == 2) {
        return;
    }

    wchar_t wideText[256] = {};
    LineInputPane::CopyText(wideText, 255);

    ValidateChatInputOrThrowPasswordError(wideText);
    SanitizeWideTextForChat(wideText, static_cast<int>(wcslen(wideText)));

    const unsigned char kChatMessageOpcode = 0x0e;
    const unsigned char kShoutChatSubtype = 1;

    unsigned char packet[300] = {};
    char multibyteText[256] = {};
    void *packetCopyContext = GetMemoryMan();

    PacketBufferWriteUInt8(kChatMessageOpcode, packet + 0);
    PacketBufferWriteUInt8(kShoutChatSubtype, packet + 1);

    const int convertedLength = WideCharToMultiByte(
        0, 0, wideText, static_cast<int>(wcslen(wideText)),
        multibyteText, sizeof(multibyteText), 0, 0);
    if (convertedLength >= 0x100) {
        ReportRangeCheckFailure();
    }

    multibyteText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    CopyPacketBytes(packetCopyContext, packet + 3, multibyteText, convertedLength);

    const int packetLength = convertedLength + 3;
    if (packetLength >= 0x12c) {
        ReportRangeCheckFailure();
    }

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}
