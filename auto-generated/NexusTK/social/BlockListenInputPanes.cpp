// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HS
// Source by-file doc: by-file/BlockListenInputPanes.md
// UID:00000A | by-class/AddToBlockListenInputPane.md | Completion:89 | Confidence:90
// AddToBlockListenInputPane emits through exact children in this source file.
// See [UID:0001MZ][0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor](by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md) for the constructor and [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) for SubmitBlockedName().
// UID:0001MZ | by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md | Completion:88 | Confidence:90
AddToBlockListenInputPane::AddToBlockListenInputPane()
    : LineInputPane(g_pLanguageMan->GetLocalizedString(0x28))
{
}

// UID:0001N0 | by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md | Completion:90 | Confidence:91
void AddToBlockListenInputPane::SubmitBlockedName()
{
    if (GetTextLength() <= 0)
        return;

    wchar_t blockedName[256] = {0};
    CopyText(blockedName, 15);

    SimpleUString candidate(blockedName);
    SimpleUStringVector& names = g_pConfig->m_blockListenNames;
    if (FindBlockListEntry(names.begin(), names.end(), candidate) != names.end())
        return;

    if (names.size() >= 0x14)
        return;

    const size_t wideLength = wcslen(blockedName);
    for (size_t i = 0; i < wideLength; ++i)
    {
        const wchar_t ch = blockedName[i];
        if (!((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z')))
        {
            new AlertPane(L"Invalid name", g_activeMapPane, kDialogOkButtonText, NULL);
            return;
        }
    }

    wchar_t localPlayerName[64] = {0};
    wcscpy_s(localPlayerName, 0x40, g_localPlayerName);
    if (GetTextWidth(blockedName, wideLength) > 72)
    {
        new AlertPane(L"Invalid name", g_activeMapPane, kDialogOkButtonText, NULL);
        return;
    }

    _wcsupr_s(localPlayerName, 0x40);
    _wcsupr_s(blockedName, 0x100);
    if (wcscmp(blockedName, localPlayerName) == 0)
    {
        new AlertPane(L"Invalid name", g_activeMapPane, kDialogOkButtonText, NULL);
        return;
    }

    names.push_back(candidate);
    g_pConfig->Save();

    char packet[0x400] = {0};
    char convertedName[0x100] = {0};
    PacketBufferWriteUInt8(0x0d, packet);
    PacketBufferWriteUInt8(0x02, packet + 1);

    const unsigned int convertedLength =
        WideCharToMultiByte(0, 0, blockedName, static_cast<unsigned char>(wideLength),
                            convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName) || convertedLength + 3 >= sizeof(packet))
        __report_rangecheckfailure();

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    memmove(packet + 3, convertedName, convertedLength);
    packet[convertedLength + 3] = 0;
    QueueAndSendPacket(g_packetSender, packet, static_cast<unsigned short>(convertedLength + 3));
}


// UID:00000X | by-class/BlockListenInputPane.md | Completion:90 | Confidence:92
class BlockListenInputPane : public CharInputPane
{
public:
    BlockListenInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void HandleCommandSelection();
};

// UID:0001MV | by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md | Completion:88 | Confidence:90
BlockListenInputPane::BlockListenInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(kBlockListenPromptStringId))
{
}

// UID:0001MX | by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md | Completion:92 | Confidence:93
bool BlockListenInputPane::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == '?' &&
        event->m_payload.m_key.m_modifiers == kEventModifierShift &&
        event->m_type == kEventKeyDown) {
        SimpleUString blockListText;
        for (SimpleUString *it = g_pConfig->m_blockListenNames.begin;
             it != g_pConfig->m_blockListenNames.end;
             ++it) {
            blockListText.AppendWideSliceFromString(*it, 0, it->Length());
            blockListText.AppendWideFill(1, L'\n');
        }

        new AlertPane(blockListText.c_str(),
                      g_activeMapPane,
                      kDialogOkButtonText,
                      NULL);
        return true;
    }

    return CharInputPane::HandleKeyOrTextEvent(event);
}

// UID:0001MY | by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md | Completion:90 | Confidence:91
namespace {
const int kBlockListenCommandMaxEntries = 0x28;
const int kBlockListenListFullStringId = 0xf2;
const int kBlockListenListEmptyStringId = 0xf3;
}

void BlockListenInputPane::HandleCommandSelection()
{
    if (GetTextLength() != 1)
        return;

    wchar_t command = 0;
    CopyText(&command, 1);

    const int blockListenCount =
        static_cast<int>(g_pConfig->m_blockListenNames.end -
                         g_pConfig->m_blockListenNames.begin);

    switch (command)
    {
    case L'A':
    case L'a':
        if (blockListenCount < kBlockListenCommandMaxEntries)
        {
            new AddToBlockListenInputPane();
        }
        else
        {
            new AlertPane(g_pLanguageMan->GetLocalizedString(kBlockListenListFullStringId),
                          g_activeMapPane,
                          kDialogOkButtonText,
                          NULL);
        }
        break;

    case L'D':
    case L'd':
        if (blockListenCount > 0)
        {
            new DeleteFromBlockListenInputPane();
        }
        else
        {
            new AlertPane(g_pLanguageMan->GetLocalizedString(kBlockListenListEmptyStringId),
                          g_activeMapPane,
                          kDialogOkButtonText,
                          NULL);
        }
        break;

    default:
        break;
    }
}

// UID:00003N | by-class/DeleteFromBlockListenInputPane.md | Completion:89 | Confidence:90
// DeleteFromBlockListenInputPane emits through exact children in this source file.
// See [UID:0001N1][0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor](by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md) for the constructor and [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) for OnConfirm().
// UID:0001N1 | by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md | Completion:88 | Confidence:90
DeleteFromBlockListenInputPane::DeleteFromBlockListenInputPane()
    : LineInputPane(g_pLanguageMan->GetLocalizedString(0x29))
{
}

// UID:0001N2 | by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md | Completion:90 | Confidence:90
void DeleteFromBlockListenInputPane::OnConfirm()
{
    if (GetTextLength() <= 0)
        return;

    wchar_t blockedName[256] = {0};
    CopyText(blockedName, 15);

    SimpleUString candidate(blockedName);
    SimpleUStringVector& names = g_pConfig->m_blockListenNames;
    SimpleUStringVector::iterator it = FindBlockListEntry(names.begin(), names.end(), candidate);
    if (it == names.end())
        return;

    names.erase(it);
    g_pConfig->Save();

    char packet[0x400] = {0};
    char convertedName[0x100] = {0};
    PacketBufferWriteUInt8(0x0d, packet);
    PacketBufferWriteUInt8(0x03, packet + 1);

    const unsigned int wideLength = static_cast<unsigned char>(wcslen(blockedName));
    const unsigned int convertedLength =
        WideCharToMultiByte(0, 0, blockedName, wideLength,
                            convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName) || convertedLength + 3 >= sizeof(packet))
        __report_rangecheckfailure();

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    memmove(packet + 3, convertedName, convertedLength);
    packet[convertedLength + 3] = 0;
    QueueAndSendPacket(g_packetSender, packet, static_cast<unsigned short>(convertedLength + 3));
}

// UID:0000PM | by-global/FindBlockListEntry_5B74E0.md | Completion:87 | Confidence:93
// FindBlockListEntry_5B74E0 is a by-global alias for the helper body emitted by [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md).
// Do not emit a duplicate definition from this alias page.

// UID:0002RY | by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md | Completion:88 | Confidence:90
// Retained raw no-route helper: bytes at 0x005b6c30 build the BlockListen opcode 0x0d,
// subcommand 0x01 packet and send two bytes through g_packetSender, but current IDA
// shows no modeled function object and zero incoming xrefs. Do not emit source C++
// until a real entry route is proven.

// UID:0002S0 | by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md | Completion:88 | Confidence:90
static void __stdcall SendAddBlockListenPacket(const wchar_t* blockedName)
{
    char packet[0x400];
    char convertedName[0x100];

    int wideLength = 0;
    while (blockedName[wideLength] != L'\0') {
        ++wideLength;
    }

    PacketBufferWriteUInt8(0x0d, packet);
    PacketBufferWriteUInt8(0x02, packet + 1);

    const int convertedLength = WideCharToMultiByte(
        0,
        0,
        blockedName,
        static_cast<unsigned char>(wideLength),
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);

    if (static_cast<unsigned int>(convertedLength) >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    memmove(packet + 3, convertedName, convertedLength);

    const int packetLength = convertedLength + 3;
    if (static_cast<unsigned int>(packetLength) >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = '\0';
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}

// UID:0002RZ | by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md | Completion:88 | Confidence:90
static void __stdcall SendDeleteBlockListenPacket(const wchar_t* blockedName)
{
    char packet[0x400];
    char convertedName[0x100];

    int wideLength = 0;
    while (blockedName[wideLength] != L'\0') {
        ++wideLength;
    }

    PacketBufferWriteUInt8(0x0d, packet);
    PacketBufferWriteUInt8(0x03, packet + 1);

    const int convertedLength = WideCharToMultiByte(
        0,
        0,
        blockedName,
        static_cast<unsigned char>(wideLength),
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);

    if (static_cast<unsigned int>(convertedLength) >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 2);
    memmove(packet + 3, convertedName, convertedLength);

    const int packetLength = convertedLength + 3;
    if (static_cast<unsigned int>(packetLength) >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = '\0';
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}

// UID:0001N3 | by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md | Completion:87 | Confidence:90
namespace {

static SimpleUStringVector::iterator FindBlockListEntry(
    SimpleUStringVector::iterator first,
    SimpleUStringVector::iterator last,
    SimpleUString name)
{
    const wchar_t* needle = name.c_str();

    for (SimpleUStringVector::iterator it = first; it != last; ++it) {
        if (WideStringCompareNoCase(it->c_str(), needle) == 0) {
            return it;
        }
    }

    return last;
}

} // namespace

// UID:0002N9 | by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md | Completion:88 | Confidence:92
// BlockListenInputPane family vtables are source-declared/generated-binary data.
// They are regenerated from the class declarations and exact method children; do not
// hand-emit the 0x0063064c-0x006307ec table bytes as C++.

// UID:0003HN | by-type/by-vtable/BlockListenInputPaneFamilyVtables.md | Completion:88 | Confidence:92
// BlockListenInputPaneFamilyVtables is a vtable-family index over [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md).
// Exact class methods and constructors emit through their child pages; the vtable bytes
// are compiler-generated from declarations and should not be duplicated here.

// UID:0003EA | by-memory\0x00630c08-0x00630c24.UserStatusInvalidNameLiteral.md | Completion:88 | Confidence:93 | Empty Emitter Marker
