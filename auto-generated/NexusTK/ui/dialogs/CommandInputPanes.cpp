// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ID
// Source by-file doc: by-file/CommandInputPanes.md
// UID:00004B | by-class/EmotionInputPane.md | Completion:91 | Confidence:93
#include "CommandInputPanes.h"

static void SendEmotionPacket(int selector);

// UID:0001M3 | by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md | Completion:92 | Confidence:93
EmotionInputPane::EmotionInputPane()
    : CharInputPane(0)
{
    wchar_t promptText[128];

    swprintf_s(promptText, _countof(promptText), g_pLanguageMan->GetLocalizedString(32), 112);
    SetPromptText(promptText);
}

void EmotionInputPane::OnAccept()
{
    if (g_useEpfAssets == 1) {
        if (TextLength() != 1) {
            return;
        }

        wchar_t ch = 0;
        CopyText(&ch, 1);

        if (ch >= L'A' && ch <= L'Z') {
            ch = static_cast<wchar_t>(ch + 0x20);
        }

        if (ch >= L'a' && ch <= L'p') {
            if (ch <= L'l') {
                SendEmotionPacket(ch - 0x56);
            } else if (ch <= L'n') {
                SendEmotionPacket(ch - 0x64);
            } else {
                SendEmotionPacket(ch - 0x58);
            }
            return;
        }

        if (ch != L'?') {
            return;
        }

        SystemMessagePane *pane = g_pChattingViewport;
        pane->m_refreshOnAppend = false;
        pane->AppendHeaderMarker();
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(31), 4, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(15), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(16), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(17), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(18), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(19), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(20), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(21), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(22), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(23), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(24), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(25), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(26), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(27), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(28), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(29), 132, 36);
        pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(30), 132, 36);
        pane->AppendFooterMarker();
        pane->RefreshAndPruneMessages();

        new EmotionInputPane();
        return;
    }

    if (TextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    if (ch >= L'A' && ch <= L'Z') {
        ch = static_cast<wchar_t>(ch + 0x20);
    }

    if (ch >= L'a' && ch <= L'p') {
        if (ch <= L'l') {
            SendEmotionPacket(ch - 0x56);
        } else if (ch <= L'n') {
            SendEmotionPacket(ch - 0x64);
        } else {
            SendEmotionPacket(ch - 0x58);
        }
        return;
    }

    if (ch != L'?') {
        return;
    }

    OldSystemMessagePane *pane = g_pOldSystemMessagePane;
    pane->m_refreshOnAppend = false;
    pane->AppendHeaderMarker();
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(31), 4, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(15), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(16), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(17), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(18), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(19), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(20), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(21), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(22), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(23), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(24), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(25), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(26), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(27), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(28), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(29), 132, 36);
    pane->AppendColoredText(g_pLanguageMan->GetLocalizedString(30), 132, 36);
    pane->AppendFooterMarker();
    pane->RefreshAndPruneMessages();

    new EmotionInputPane();
}

// UID:0002N4 | by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md | Completion:91 | Confidence:94
// EmotionInputPane vtables and RTTI are compiler-generated from the class
// declaration and virtual methods. Do not hand-author the
// 0x0062f9b8-0x0062fa40 table or locator dwords as C++.

// UID:0003HI | by-type/by-vtable/EmotionInputPaneVtables.md | Completion:90 | Confidence:94
// EmotionInputPaneVtables is the source-local index for UID0002N4.
// Regenerate the tables through EmotionInputPane; do not duplicate fixed
// vtable, RTTI, scalar-destructor, or adjustor-thunk bytes here.

// UID:0001M4 | by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md | Completion:89 | Confidence:92
static void SendEmotionPacket(int selector)
{
    unsigned char packet[128];

    packet[0] = 0x1d;
    PacketBufferWriteUInt8(static_cast<unsigned char>(selector - 0x0b), packet + 1);
    packet[2] = 0;
    QueueAndSendPacket(g_packetSender, packet, 2);
}

// UID:00005W | by-class/GroupInputPane.md | Completion:91 | Confidence:93
// UID:0002SB | by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md | Completion:90 | Confidence:93
GroupInputPane::GroupInputPane()
    : LineInputPane(g_pLanguageMan->GetLocalizedString(kGroupPromptStringId))
{
}

// UID:0001MJ | by-memory/0x005b5440-0x005b5547.GroupInputPane.md | Completion:91 | Confidence:93
void GroupInputPane::OnConfirmInput()
{
    if (TextLength() <= 0) {
        return;
    }

    wchar_t inputText[256];
    CopyText(inputText, 255);

    unsigned char packet[300];
    PacketBufferWriteUInt8(0x2e, packet);

    char encodedText[256];
    const int encodedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        inputText,
        static_cast<int>(wcslen(inputText)),
        encodedText,
        static_cast<int>(sizeof(encodedText)),
        NULL,
        NULL);
    encodedText[encodedLength] = 0;

    PacketBufferWriteUInt8(static_cast<unsigned char>(encodedLength), packet + 1);
    memmove(packet + 2, encodedText, encodedLength);

    const int packetLength = encodedLength + 2;
    packet[packetLength] = 0;

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:0000AO | by-class/PostInputPane.md | Completion:92 | Confidence:94
// UID:0001MK | by-memory/0x005b5630-0x005b5890.PostInputPane.md | Completion:92 | Confidence:94
namespace {
const unsigned char kPostCommandOpcode = 0x34;
const unsigned char kPostHelpPanelTab = 2;
const int kHelpPanelSoundId = 0x198;
const int kHelpPanelSoundVolume = 100;

static void SendPostSelectionPacket(unsigned char postIndex)
{
    char packet[3];

    WritePacketByte(static_cast<char>(kPostCommandOpcode), packet);
    WritePacketByte(static_cast<char>(postIndex), packet + 1);
    packet[2] = 0;

    QueueAndSendPacket(g_packetSender, packet, 2);
}
}

PostInputPane::PostInputPane()
    : CharInputPane(0)
{
    wchar_t playerName[100];
    wchar_t prompt[128];

    g_pCollectionData->GetLocalPlayerName(playerName);
    swprintf_s(prompt, 128, g_pLanguageMan->GetLocalizedString(11), playerName);
    SetPromptText(prompt);
}

bool PostInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        g_pGeneralPurposePanel->SwitchActiveTab(kPostHelpPanelTab, NULL);
        g_pSoundManager->PlayEffect(kHelpPanelSoundId, kHelpPanelSoundVolume);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

void PostInputPane::OnConfirmInput()
{
    if (GetTextLength() != 1)
        return;

    wchar_t text[2] = {0, 0};
    CopyText(text, 1);

    unsigned char postIndex = 0;
    const wchar_t ch = text[0];

    if (ch >= L'a' && ch <= L'z') {
        postIndex = static_cast<unsigned char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        postIndex = static_cast<unsigned char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (postIndex < 1)
        return;

    if (postIndex > g_activeUserStatusPane->activeSlotLimit)
        return;

    SendPostSelectionPacket(postIndex);
}

// UID:0002N6 | by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md | Completion:92 | Confidence:94
// GroupInputPane and PostInputPane vtables and RTTI are compiler-generated
// from their class declarations and virtual methods. Do not hand-author the
// 0x006300d4-0x006301e8 table or locator dwords as C++.

// UID:0003HK | by-type/by-vtable/GroupPostInputPaneVtables.md | Completion:91 | Confidence:94
// GroupPostInputPaneVtables is the source-local ABI index for UID0002N6.
// Regenerate all six views through GroupInputPane and PostInputPane; do not
// duplicate fixed vtable, RTTI, scalar-destructor, or adjustor-thunk bytes.
