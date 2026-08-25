// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M8
// Source by-file doc: by-file/PacketBuffer.md
// UID:0003YJ | by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md | Completion:94 | Confidence:94
void PacketBufferWriteUInt8(unsigned char value,
                            unsigned char *destination)
{
    destination[0] = value;
    destination[1] = 0;
}

void PacketBufferWriteUInt16BE(unsigned short value,
                               unsigned char *destination)
{
    destination[0] = static_cast<unsigned char>(value >> 8);
    destination[1] = static_cast<unsigned char>(value);
    destination[2] = 0;
}

void PacketBufferWriteUInt24BE(unsigned int value,
                               unsigned char *destination)
{
    destination[0] = static_cast<unsigned char>(value >> 16);
    destination[1] = static_cast<unsigned char>(value >> 8);
    destination[2] = static_cast<unsigned char>(value);
    destination[3] = 0;
}

void PacketBufferWriteUInt32BE(unsigned int value,
                               unsigned char *destination)
{
    destination[0] = static_cast<unsigned char>(value >> 24);
    destination[1] = static_cast<unsigned char>(value >> 16);
    destination[2] = static_cast<unsigned char>(value >> 8);
    destination[3] = static_cast<unsigned char>(value);
    destination[4] = 0;
}

void PacketBufferWriteUInt64BE(unsigned __int64 value,
                               unsigned char *destination)
{
    destination[0] = static_cast<unsigned char>(value >> 56);
    destination[1] = static_cast<unsigned char>(value >> 48);
    destination[2] = static_cast<unsigned char>(value >> 40);
    destination[3] = static_cast<unsigned char>(value >> 32);
    destination[4] = static_cast<unsigned char>(value >> 24);
    destination[5] = static_cast<unsigned char>(value >> 16);
    destination[6] = static_cast<unsigned char>(value >> 8);
    destination[7] = static_cast<unsigned char>(value);
    destination[8] = 0;
}

// UID:0003YK | by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md | Completion:93 | Confidence:94
unsigned short PacketBufferReadUInt16BE(const unsigned char *packet)
{
    return static_cast<unsigned short>(
        (static_cast<unsigned short>(packet[0]) << 8) |
        static_cast<unsigned short>(packet[1]));
}

unsigned int PacketBufferReadUInt32BE(const unsigned char *packet)
{
    return (static_cast<unsigned int>(packet[0]) << 24) |
           (static_cast<unsigned int>(packet[1]) << 16) |
           (static_cast<unsigned int>(packet[2]) << 8) |
           static_cast<unsigned int>(packet[3]);
}

// UID:0003YM | by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md | Completion:92 | Confidence:93
void PacketBufferAppendUInt8(unsigned char value,
                             unsigned char *packet,
                             int *cursor)
{
    unsigned char *destination = packet + *cursor;
    destination[0] = value;
    destination[1] = 0;
    *cursor += 1;
}

void PacketBufferAppendUInt16BE(unsigned short value,
                               unsigned char *packet,
                               int *cursor)
{
    unsigned char *destination = packet + *cursor;
    destination[0] = static_cast<unsigned char>(value >> 8);
    destination[1] = static_cast<unsigned char>(value);
    destination[2] = 0;
    *cursor += 2;
}

void PacketBufferAppendUInt24BE(unsigned int value,
                               unsigned char *packet,
                               int *cursor)
{
    unsigned char *destination = packet + *cursor;
    destination[0] = static_cast<unsigned char>(value >> 16);
    destination[1] = static_cast<unsigned char>(value >> 8);
    destination[2] = static_cast<unsigned char>(value);
    destination[3] = 0;
    *cursor += 3;
}

void PacketBufferAppendUInt32BE(unsigned int value,
                               unsigned char *packet,
                               int *cursor)
{
    unsigned char *destination = packet + *cursor;
    destination[0] = static_cast<unsigned char>(value >> 24);
    destination[1] = static_cast<unsigned char>(value >> 16);
    destination[2] = static_cast<unsigned char>(value >> 8);
    destination[3] = static_cast<unsigned char>(value);
    destination[4] = 0;
    *cursor += 4;
}






// UID:000243 | by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md | Completion:90 | Confidence:92
StringBase *PacketBufferReadAnsiString16(StringBase *out,
                                         const unsigned char *packet,
                                         int *cursor)
{
    StringBase ansiText;
    const unsigned int length =
        (static_cast<unsigned int>(packet[*cursor]) << 8) |
        static_cast<unsigned int>(packet[*cursor + 1]);

    *cursor += 2;
    ansiText.AssignAnsiBytes(
        reinterpret_cast<const char *>(packet + *cursor),
        length);
    *cursor += static_cast<int>(length);

    out->InitializeWideFromAnsiString(ansiText);
    return out;
}

StringBase *PacketBufferReadAnsiBytes16(StringBase *out,
                                        const unsigned char *packet,
                                        int *cursor)
{
    const unsigned int length =
        (static_cast<unsigned int>(packet[*cursor]) << 8) |
        static_cast<unsigned int>(packet[*cursor + 1]);

    *cursor += 2;
    out->AssignAnsiBytes(
        reinterpret_cast<const char *>(packet + *cursor),
        length);
    *cursor += static_cast<int>(length);
    return out;
}

// UID:0000V1 | by-item\PacketBufferHelpers.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0003YL | by-memory\0x00575580-0x0057564e.PacketBufferHostAddressResolutionHelpers.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003YN | by-memory\0x00575710-0x005757c8.PacketBufferCursorReadBigEndianHelpers.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003YO | by-memory\0x005757d0-0x00575a07.PacketBufferStringWriteHelpers.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003YP | by-memory\0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md | Completion:86 | Confidence:90 | Empty Emitter Marker
