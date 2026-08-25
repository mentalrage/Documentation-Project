// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M8
// Source by-file doc: by-file/PacketBuffer.md
// UID:0003YJ | by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md | Completion:94 | Confidence:94
void PacketBufferWriteUInt8(unsigned char value,
                            unsigned char *destination);
void PacketBufferWriteUInt16BE(unsigned short value,
                               unsigned char *destination);
void PacketBufferWriteUInt24BE(unsigned int value,
                               unsigned char *destination);
void PacketBufferWriteUInt32BE(unsigned int value,
                               unsigned char *destination);
void PacketBufferWriteUInt64BE(unsigned __int64 value,
                               unsigned char *destination);

// UID:0003YK | by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md | Completion:93 | Confidence:94
unsigned short PacketBufferReadUInt16BE(const unsigned char *packet);
unsigned int PacketBufferReadUInt32BE(const unsigned char *packet);

// UID:0003YM | by-memory/0x00575650-0x00575703.PacketBufferCursorAppendBigEndianHelpers.md | Completion:92 | Confidence:93
void PacketBufferAppendUInt8(unsigned char value,
                             unsigned char *packet,
                             int *cursor);
void PacketBufferAppendUInt16BE(unsigned short value,
                               unsigned char *packet,
                               int *cursor);
void PacketBufferAppendUInt24BE(unsigned int value,
                               unsigned char *packet,
                               int *cursor);
void PacketBufferAppendUInt32BE(unsigned int value,
                               unsigned char *packet,
                               int *cursor);
