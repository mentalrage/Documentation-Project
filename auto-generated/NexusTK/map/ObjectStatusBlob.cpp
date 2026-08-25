// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M6
// Source by-file doc: by-file/ObjectStatusBlob.md
// UID:00009S | by-class/ObjectStatusBlob.md | Completion:94 | Confidence:94
#include "ObjectStatusBlob.h"

// UID:0004LK | by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md | Completion:92 | Confidence:94
int ObjectStatusBlob::ParseTaggedStatus(const unsigned char *packet)
{
    switch (packet[0])
    {
    case 0:
        return ParseFullStatus(packet + 1) + 1;

    case 1:
    case 2:
        m_statusKind = static_cast<StatusKind>(packet[0]);
        m_appearanceId = PacketBufferReadUInt16BE(packet + 1);
        m_variantOrPalette = packet[3];
        return 4;

    default:
        return 0;
    }
}

// UID:0004LL | by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md | Completion:91 | Confidence:93
int ObjectStatusBlob::ParseFullStatus(const unsigned char *packet)
{
    const unsigned short kNoPart = 0xffff;

    m_statusKind = HumanObject;
    m_actionState = 11;
    m_gender = packet[0];
    m_compositionMode = packet[1];
    m_ridingAppearanceId = PacketBufferReadUInt16BE(packet + 2);
    m_displayStatusByte = packet[4];

    if (m_ridingAppearanceId != 0)
    {
        if (!g_useEpfAssets)
            m_ridingAppearanceId = 1;

        wchar_t ridingKeyText[128];
        swprintf_s(ridingKeyText,
                   sizeof(ridingKeyText) / sizeof(ridingKeyText[0]),
                   L"%d",
                   static_cast<int>(m_ridingAppearanceId));

        SimpleUString tableName;
        tableName.Assign(L"RidableAnimals", 14);

        SimpleUString ridingKey;
        ridingKey.Assign(ridingKeyText,
                         static_cast<unsigned int>(wcslen(ridingKeyText)));

        const SimpleUString *value =
            g_pMetaMan->FindEntry(&tableName, &ridingKey, 1);
        m_ridingDefinitionIndex =
            static_cast<unsigned short>(_wtol(value->c_str()));

        value = g_pMetaMan->FindEntry(&tableName, &ridingKey, 2);
        m_ridingPaletteFlags =
            static_cast<unsigned short>(_wtol(value->c_str()));

        value = g_pMetaMan->FindEntry(&tableName, &ridingKey, 3);
        m_ridingYOffset = static_cast<short>(_wtol(value->c_str()));
    }

    m_faceId = PacketBufferReadUInt16BE(packet + 5);
    m_hairId = packet[7];
    m_hairColor = packet[8];
    m_faceColor = packet[9];
    m_skinColor = packet[10];

    if (m_faceId != kNoPart &&
        (m_faceId <= 199 ||
         (m_faceId >= 900 && m_faceId <= 999) ||
         m_faceId > 399))
    {
        m_hairId = static_cast<unsigned char>(m_faceId);
        m_faceId = 200;
    }

    if (m_hairId < g_pNewHumanImageLib->m_hairColorEntries.size())
    {
        m_hairColor = static_cast<unsigned char>(
            (m_hairColor & 0xe0) +
            (m_hairColor +
             g_pNewHumanImageLib->m_hairColorEntries[m_hairId]) % 32);
    }

    const unsigned short bodyOrCoatId =
        PacketBufferReadUInt16BE(packet + 11);
    if (bodyOrCoatId <= 9999)
    {
        m_bodyId = bodyOrCoatId;
        m_coatId = kNoPart;
        if (m_bodyId == 0)
            m_bodyId = (m_gender != 0);
    }
    else
    {
        m_coatId = static_cast<unsigned short>(bodyOrCoatId % 10000);
        m_bodyId = kNoPart;
    }

    m_bodyColor = packet[13];
    m_weaponId = PacketBufferReadUInt16BE(packet + 14);
    m_weaponColor = packet[16];
    m_shieldOrArrowId = PacketBufferReadUInt16BE(packet + 17);
    m_shieldOrArrowColor = packet[19];
    m_headgearMode = packet[20];
    m_helmetId = packet[21];
    m_helmetColor = packet[22];
    m_faceDecorationId = PacketBufferReadUInt16BE(packet + 23);
    m_faceDecorationColor = packet[25];
    m_hairDecorationId = PacketBufferReadUInt16BE(packet + 26);
    m_hairDecorationColor = packet[28];
    m_secondFaceDecorationId = PacketBufferReadUInt16BE(packet + 29);
    m_secondFaceDecorationColor = packet[31];
    m_mantleId = PacketBufferReadUInt16BE(packet + 32);
    m_mantleColor = packet[34];
    m_neckId = PacketBufferReadUInt16BE(packet + 35);
    m_neckColor = packet[37];
    m_shoesId = PacketBufferReadUInt16BE(packet + 38);
    m_shoesColor = packet[40];
    m_invisible = packet[41];
    m_faceShape = packet[42];
    m_fullBodyId = kNoPart;

    if (m_coatId == kNoPart)
    {
        if (m_bodyId != 0 &&
            m_bodyId != 1 &&
            m_bodyId != 57 &&
            m_bodyId != 58 &&
            m_bodyId != 160 &&
            m_bodyId != 161)
        {
            m_shoesId = kNoPart;
        }
    }
    else if (m_shoesId == kNoPart)
    {
        m_shoesId = (m_gender != 0);
    }

    if (m_headgearMode == 0)
        m_helmetId = 0xff;
    else if (m_headgearMode == 1 || m_headgearMode == 2)
        m_hairId = 0xff;

    return 43;
}

// UID:0004LM | by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md | Completion:92 | Confidence:94
int ObjectStatusBlob::ParsePartialStatus(const unsigned char *packet)
{
    m_statusKind = CompactLivingObject;
    m_actionState = 11;
    m_displayStatusByte = 0x50;
    m_direction = packet[0];
    m_posture = packet[1];
    m_appearanceId = PacketBufferReadUInt16BE(packet + 2);
    m_variantOrPalette = packet[4];
    return 5;
}
