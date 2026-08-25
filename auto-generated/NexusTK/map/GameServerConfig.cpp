// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JP
// Source by-file doc: by-file/GameServerConfig.md
// UID:00005O | by-class/GameServerConfig.md | Completion:91 | Confidence:92
class GameServerConfig : public LObject
{
public:
    struct NationEntry
    {
        NationEntry()
            : nationId((unsigned short)-1)
        {
        }

        unsigned short nationId;
        wchar_t label[33];
    };

    GameServerConfig();
    virtual ~GameServerConfig();

    NationEntry *CopyNationEntryOrFallback(NationEntry *destination, int nationId);
    void SeedDefaultNationEntries();
    void RequestNationEntries();
    void ParseNationEntries(const unsigned char *packet);

    int GetNationEntryCount() const
    {
        return m_nationEntries.GetCount();
    }

    NationEntry *GetNationEntryAtOrDefault(int index)
    {
        return m_nationEntries.GetAtOrDefault(index);
    }

private:
    ProtectedArray<NationEntry> m_nationEntries;

// UID:0002HV | by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md | Completion:88 | Confidence:90
GameServerConfig::GameServerConfig()
    : LObject(),
      m_nationEntries()
{
    g_gameServerNationTable = this;
    m_nationEntries.m_defaultEntry.nationId = (unsigned short)-1;
    m_nationEntries.m_reservedCount = 10;
    m_nationEntries.m_entries = NULL;
    m_nationEntries.m_count = 0;
}

// UID:0002HW | by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md | Completion:88 | Confidence:90
GameServerConfig::~GameServerConfig()
{
    delete [] m_nationEntries.m_entries;
    g_gameServerNationTable = NULL;
}

// UID:0002HX | by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md | Completion:89 | Confidence:91
GameServerConfig::NationEntry *
GameServerConfig::CopyNationEntryOrFallback(NationEntry *destination, int nationId)
{
    for (int index = 0; index < m_nationEntries.m_count; ++index) {
        NationEntry *entry = &m_nationEntries.m_entries[index];
        if (entry->nationId == nationId) {
            *destination = *entry;
            return destination;
        }
    }

    destination->nationId = 0;
    wcscpy_s(destination->label, 33, L"????");
    return destination;
}

// UID:0002HY | by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md | Completion:88 | Confidence:90
void GameServerConfig::SeedDefaultNationEntries()
{
    m_nationEntries.Resize(2);

    NationEntry *firstEntry = m_nationEntries.GetAtOrDefault(0);
    firstEntry->nationId = 1;
    wcscpy_s(firstEntry->label, 33, g_pLanguageMan->GetLocalizedString(0x9f));

    NationEntry *secondEntry = m_nationEntries.GetAtOrDefault(1);
    secondEntry->nationId = 2;
    wcscpy_s(secondEntry->label, 33, g_pLanguageMan->GetLocalizedString(0xa0));
}

// UID:0002HZ | by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md | Completion:89 | Confidence:91
void GameServerConfig::RequestNationEntries()
{
    if (m_nationEntries.m_count <= 0)
        SendGameServerNationEntryRequestPacket();
}

// UID:0002I0 | by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md | Completion:89 | Confidence:91
void GameServerConfig::ParseNationEntries(const unsigned char *packet)
{
    if (PacketBufferReadUInt16BE(packet) <= 0)
        return;

    int packetOffset = 3;
    int count = packet[2] + 1;
    m_nationEntries.Resize(count);

    for (int index = 0; index < count; ++index) {
        NationEntry *entry = m_nationEntries.GetAtOrDefault(index);
        entry->nationId = packet[packetOffset++];

        int labelLength = packet[packetOffset++];
        int convertedLength = MultiByteToWideChar(
            0,
            0,
            (const char *)(packet + packetOffset),
            labelLength,
            entry->label,
            32);
        entry->label[convertedLength] = 0;
        packetOffset += labelLength;
    }

    NationEntry *neighborhood = m_nationEntries.GetAtOrDefault(count - 1);
    neighborhood->nationId = 10;
    wcscpy_s(neighborhood->label, 33, L"Neighborhood");
}





// UID:0001UP | by-type/by-struct/GameServerNationEntry.md | Completion:88 | Confidence:91
// GameServerConfig::NationEntry is emitted as the nested record declaration
// in [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) GameServerConfig. This page documents the same 0x44-byte
// layout; do not emit a second standalone GameServerNationEntry struct.
};

// UID:0000B4 | by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md | Completion:88 | Confidence:91
// Source uses ProtectedArray<GameServerConfig::NationEntry> as
// GameServerConfig::m_nationEntries. Do not emit a generated wrapper class
// named ProtectedArray_struct_GameServerConfig__NationEntry_; the reusable
// template bodies belong to ProtectedArray support pages, and [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)
// emits the concrete GameServerConfig::NationEntry Resize(int count) body.

// UID:0000Q1 | by-global/g_gameServerNationTable.md | Completion:89 | Confidence:89
static GameServerConfig *g_gameServerNationTable = nullptr;

// UID:000230 | by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md | Completion:86 | Confidence:90
static void SendGameServerNationEntryRequestPacket()
{
    enum
    {
        kGameServerConfigOpcode = 0x66,
        kNationEntryRequestCode = 0x4000,
        kNationEntryRequestPacketLength = 9
    };

    unsigned char packet[0x44];

    PacketBufferWriteUInt8(kGameServerConfigOpcode, packet);
    PacketBufferWriteUInt16BE(kNationEntryRequestCode, packet + 1);
    PacketBufferWriteUInt8(1, packet + 3);
    PacketBufferWriteUInt8(1, packet + 4);
    PacketBufferWriteUInt8(0, packet + 5);
    PacketBufferWriteUInt8(1, packet + 6);
    PacketBufferWriteUInt8(1, packet + 7);
    PacketBufferWriteUInt8(0, packet + 8);

    QueueAndSendPacket(g_packetSender, packet, kNationEntryRequestPacketLength);
}

// UID:000374 | by-memory\0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0003IJ | by-memory\0x0061e708-0x0061e718.GameServerConfigClassVtableData.md | Completion:87 | Confidence:93 | Empty Emitter Marker

// UID:0003C3 | by-memory\0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md | Completion:87 | Confidence:93 | Empty Emitter Marker

// UID:0003IS | by-memory\0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md | Completion:88 | Confidence:93 | Empty Emitter Marker
