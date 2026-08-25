// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M9
// Source by-file doc: by-file/PacketTransform.md
// UID:0000TG | by-global/PacketTransformGlobals.md | Completion:90 | Confidence:92
// Shared global declarations are provided by PacketTransform.h.
// UID:000286 | by-memory/0x0066fe50-0x00670258.PacketTransformAlternateSizeAndLut.md | Completion:89 | Confidence:91
#define PACKET_TRANSFORM_LUT_ENTRY(n) \
    (((unsigned int)(n)) | (((unsigned int)(n)) << 8) | (((unsigned int)(n)) << 16) | (((unsigned int)(n)) << 24))

int g_packetXorAlternateSize = 9;
static int s_packetTransformReserved = 0;

unsigned int g_packetTransformLut[256] = {
    PACKET_TRANSFORM_LUT_ENTRY(0x00), PACKET_TRANSFORM_LUT_ENTRY(0x01), PACKET_TRANSFORM_LUT_ENTRY(0x02), PACKET_TRANSFORM_LUT_ENTRY(0x03),
    PACKET_TRANSFORM_LUT_ENTRY(0x04), PACKET_TRANSFORM_LUT_ENTRY(0x05), PACKET_TRANSFORM_LUT_ENTRY(0x06), PACKET_TRANSFORM_LUT_ENTRY(0x07),
    PACKET_TRANSFORM_LUT_ENTRY(0x08), PACKET_TRANSFORM_LUT_ENTRY(0x09), PACKET_TRANSFORM_LUT_ENTRY(0x0a), PACKET_TRANSFORM_LUT_ENTRY(0x0b),
    PACKET_TRANSFORM_LUT_ENTRY(0x0c), PACKET_TRANSFORM_LUT_ENTRY(0x0d), PACKET_TRANSFORM_LUT_ENTRY(0x0e), PACKET_TRANSFORM_LUT_ENTRY(0x0f),
    PACKET_TRANSFORM_LUT_ENTRY(0x10), PACKET_TRANSFORM_LUT_ENTRY(0x11), PACKET_TRANSFORM_LUT_ENTRY(0x12), PACKET_TRANSFORM_LUT_ENTRY(0x13),
    PACKET_TRANSFORM_LUT_ENTRY(0x14), PACKET_TRANSFORM_LUT_ENTRY(0x15), PACKET_TRANSFORM_LUT_ENTRY(0x16), PACKET_TRANSFORM_LUT_ENTRY(0x17),
    PACKET_TRANSFORM_LUT_ENTRY(0x18), PACKET_TRANSFORM_LUT_ENTRY(0x19), PACKET_TRANSFORM_LUT_ENTRY(0x1a), PACKET_TRANSFORM_LUT_ENTRY(0x1b),
    PACKET_TRANSFORM_LUT_ENTRY(0x1c), PACKET_TRANSFORM_LUT_ENTRY(0x1d), PACKET_TRANSFORM_LUT_ENTRY(0x1e), PACKET_TRANSFORM_LUT_ENTRY(0x1f),
    PACKET_TRANSFORM_LUT_ENTRY(0x20), PACKET_TRANSFORM_LUT_ENTRY(0x21), PACKET_TRANSFORM_LUT_ENTRY(0x22), PACKET_TRANSFORM_LUT_ENTRY(0x23),
    PACKET_TRANSFORM_LUT_ENTRY(0x24), PACKET_TRANSFORM_LUT_ENTRY(0x25), PACKET_TRANSFORM_LUT_ENTRY(0x26), PACKET_TRANSFORM_LUT_ENTRY(0x27),
    PACKET_TRANSFORM_LUT_ENTRY(0x28), PACKET_TRANSFORM_LUT_ENTRY(0x29), PACKET_TRANSFORM_LUT_ENTRY(0x2a), PACKET_TRANSFORM_LUT_ENTRY(0x2b),
    PACKET_TRANSFORM_LUT_ENTRY(0x2c), PACKET_TRANSFORM_LUT_ENTRY(0x2d), PACKET_TRANSFORM_LUT_ENTRY(0x2e), PACKET_TRANSFORM_LUT_ENTRY(0x2f),
    PACKET_TRANSFORM_LUT_ENTRY(0x30), PACKET_TRANSFORM_LUT_ENTRY(0x31), PACKET_TRANSFORM_LUT_ENTRY(0x32), PACKET_TRANSFORM_LUT_ENTRY(0x33),
    PACKET_TRANSFORM_LUT_ENTRY(0x34), PACKET_TRANSFORM_LUT_ENTRY(0x35), PACKET_TRANSFORM_LUT_ENTRY(0x36), PACKET_TRANSFORM_LUT_ENTRY(0x37),
    PACKET_TRANSFORM_LUT_ENTRY(0x38), PACKET_TRANSFORM_LUT_ENTRY(0x39), PACKET_TRANSFORM_LUT_ENTRY(0x3a), PACKET_TRANSFORM_LUT_ENTRY(0x3b),
    PACKET_TRANSFORM_LUT_ENTRY(0x3c), PACKET_TRANSFORM_LUT_ENTRY(0x3d), PACKET_TRANSFORM_LUT_ENTRY(0x3e), PACKET_TRANSFORM_LUT_ENTRY(0x3f),
    PACKET_TRANSFORM_LUT_ENTRY(0x40), PACKET_TRANSFORM_LUT_ENTRY(0x41), PACKET_TRANSFORM_LUT_ENTRY(0x42), PACKET_TRANSFORM_LUT_ENTRY(0x43),
    PACKET_TRANSFORM_LUT_ENTRY(0x44), PACKET_TRANSFORM_LUT_ENTRY(0x45), PACKET_TRANSFORM_LUT_ENTRY(0x46), PACKET_TRANSFORM_LUT_ENTRY(0x47),
    PACKET_TRANSFORM_LUT_ENTRY(0x48), PACKET_TRANSFORM_LUT_ENTRY(0x49), PACKET_TRANSFORM_LUT_ENTRY(0x4a), PACKET_TRANSFORM_LUT_ENTRY(0x4b),
    PACKET_TRANSFORM_LUT_ENTRY(0x4c), PACKET_TRANSFORM_LUT_ENTRY(0x4d), PACKET_TRANSFORM_LUT_ENTRY(0x4e), PACKET_TRANSFORM_LUT_ENTRY(0x4f),
    PACKET_TRANSFORM_LUT_ENTRY(0x50), PACKET_TRANSFORM_LUT_ENTRY(0x51), PACKET_TRANSFORM_LUT_ENTRY(0x52), PACKET_TRANSFORM_LUT_ENTRY(0x53),
    PACKET_TRANSFORM_LUT_ENTRY(0x54), PACKET_TRANSFORM_LUT_ENTRY(0x55), PACKET_TRANSFORM_LUT_ENTRY(0x56), PACKET_TRANSFORM_LUT_ENTRY(0x57),
    PACKET_TRANSFORM_LUT_ENTRY(0x58), PACKET_TRANSFORM_LUT_ENTRY(0x59), PACKET_TRANSFORM_LUT_ENTRY(0x5a), PACKET_TRANSFORM_LUT_ENTRY(0x5b),
    PACKET_TRANSFORM_LUT_ENTRY(0x5c), PACKET_TRANSFORM_LUT_ENTRY(0x5d), PACKET_TRANSFORM_LUT_ENTRY(0x5e), PACKET_TRANSFORM_LUT_ENTRY(0x5f),
    PACKET_TRANSFORM_LUT_ENTRY(0x60), PACKET_TRANSFORM_LUT_ENTRY(0x61), PACKET_TRANSFORM_LUT_ENTRY(0x62), PACKET_TRANSFORM_LUT_ENTRY(0x63),
    PACKET_TRANSFORM_LUT_ENTRY(0x64), PACKET_TRANSFORM_LUT_ENTRY(0x65), PACKET_TRANSFORM_LUT_ENTRY(0x66), PACKET_TRANSFORM_LUT_ENTRY(0x67),
    PACKET_TRANSFORM_LUT_ENTRY(0x68), PACKET_TRANSFORM_LUT_ENTRY(0x69), PACKET_TRANSFORM_LUT_ENTRY(0x6a), PACKET_TRANSFORM_LUT_ENTRY(0x6b),
    PACKET_TRANSFORM_LUT_ENTRY(0x6c), PACKET_TRANSFORM_LUT_ENTRY(0x6d), PACKET_TRANSFORM_LUT_ENTRY(0x6e), PACKET_TRANSFORM_LUT_ENTRY(0x6f),
    PACKET_TRANSFORM_LUT_ENTRY(0x70), PACKET_TRANSFORM_LUT_ENTRY(0x71), PACKET_TRANSFORM_LUT_ENTRY(0x72), PACKET_TRANSFORM_LUT_ENTRY(0x73),
    PACKET_TRANSFORM_LUT_ENTRY(0x74), PACKET_TRANSFORM_LUT_ENTRY(0x75), PACKET_TRANSFORM_LUT_ENTRY(0x76), PACKET_TRANSFORM_LUT_ENTRY(0x77),
    PACKET_TRANSFORM_LUT_ENTRY(0x78), PACKET_TRANSFORM_LUT_ENTRY(0x79), PACKET_TRANSFORM_LUT_ENTRY(0x7a), PACKET_TRANSFORM_LUT_ENTRY(0x7b),
    PACKET_TRANSFORM_LUT_ENTRY(0x7c), PACKET_TRANSFORM_LUT_ENTRY(0x7d), PACKET_TRANSFORM_LUT_ENTRY(0x7e), PACKET_TRANSFORM_LUT_ENTRY(0x7f),
    PACKET_TRANSFORM_LUT_ENTRY(0x80), PACKET_TRANSFORM_LUT_ENTRY(0x81), PACKET_TRANSFORM_LUT_ENTRY(0x82), PACKET_TRANSFORM_LUT_ENTRY(0x83),
    PACKET_TRANSFORM_LUT_ENTRY(0x84), PACKET_TRANSFORM_LUT_ENTRY(0x85), PACKET_TRANSFORM_LUT_ENTRY(0x86), PACKET_TRANSFORM_LUT_ENTRY(0x87),
    PACKET_TRANSFORM_LUT_ENTRY(0x88), PACKET_TRANSFORM_LUT_ENTRY(0x89), PACKET_TRANSFORM_LUT_ENTRY(0x8a), PACKET_TRANSFORM_LUT_ENTRY(0x8b),
    PACKET_TRANSFORM_LUT_ENTRY(0x8c), PACKET_TRANSFORM_LUT_ENTRY(0x8d), PACKET_TRANSFORM_LUT_ENTRY(0x8e), PACKET_TRANSFORM_LUT_ENTRY(0x8f),
    PACKET_TRANSFORM_LUT_ENTRY(0x90), PACKET_TRANSFORM_LUT_ENTRY(0x91), PACKET_TRANSFORM_LUT_ENTRY(0x92), PACKET_TRANSFORM_LUT_ENTRY(0x93),
    PACKET_TRANSFORM_LUT_ENTRY(0x94), PACKET_TRANSFORM_LUT_ENTRY(0x95), PACKET_TRANSFORM_LUT_ENTRY(0x96), PACKET_TRANSFORM_LUT_ENTRY(0x97),
    PACKET_TRANSFORM_LUT_ENTRY(0x98), PACKET_TRANSFORM_LUT_ENTRY(0x99), PACKET_TRANSFORM_LUT_ENTRY(0x9a), PACKET_TRANSFORM_LUT_ENTRY(0x9b),
    PACKET_TRANSFORM_LUT_ENTRY(0x9c), PACKET_TRANSFORM_LUT_ENTRY(0x9d), PACKET_TRANSFORM_LUT_ENTRY(0x9e), PACKET_TRANSFORM_LUT_ENTRY(0x9f),
    PACKET_TRANSFORM_LUT_ENTRY(0xa0), PACKET_TRANSFORM_LUT_ENTRY(0xa1), PACKET_TRANSFORM_LUT_ENTRY(0xa2), PACKET_TRANSFORM_LUT_ENTRY(0xa3),
    PACKET_TRANSFORM_LUT_ENTRY(0xa4), PACKET_TRANSFORM_LUT_ENTRY(0xa5), PACKET_TRANSFORM_LUT_ENTRY(0xa6), PACKET_TRANSFORM_LUT_ENTRY(0xa7),
    PACKET_TRANSFORM_LUT_ENTRY(0xa8), PACKET_TRANSFORM_LUT_ENTRY(0xa9), PACKET_TRANSFORM_LUT_ENTRY(0xaa), PACKET_TRANSFORM_LUT_ENTRY(0xab),
    PACKET_TRANSFORM_LUT_ENTRY(0xac), PACKET_TRANSFORM_LUT_ENTRY(0xad), PACKET_TRANSFORM_LUT_ENTRY(0xae), PACKET_TRANSFORM_LUT_ENTRY(0xaf),
    PACKET_TRANSFORM_LUT_ENTRY(0xb0), PACKET_TRANSFORM_LUT_ENTRY(0xb1), PACKET_TRANSFORM_LUT_ENTRY(0xb2), PACKET_TRANSFORM_LUT_ENTRY(0xb3),
    PACKET_TRANSFORM_LUT_ENTRY(0xb4), PACKET_TRANSFORM_LUT_ENTRY(0xb5), PACKET_TRANSFORM_LUT_ENTRY(0xb6), PACKET_TRANSFORM_LUT_ENTRY(0xb7),
    PACKET_TRANSFORM_LUT_ENTRY(0xb8), PACKET_TRANSFORM_LUT_ENTRY(0xb9), PACKET_TRANSFORM_LUT_ENTRY(0xba), PACKET_TRANSFORM_LUT_ENTRY(0xbb),
    PACKET_TRANSFORM_LUT_ENTRY(0xbc), PACKET_TRANSFORM_LUT_ENTRY(0xbd), PACKET_TRANSFORM_LUT_ENTRY(0xbe), PACKET_TRANSFORM_LUT_ENTRY(0xbf),
    PACKET_TRANSFORM_LUT_ENTRY(0xc0), PACKET_TRANSFORM_LUT_ENTRY(0xc1), PACKET_TRANSFORM_LUT_ENTRY(0xc2), PACKET_TRANSFORM_LUT_ENTRY(0xc3),
    PACKET_TRANSFORM_LUT_ENTRY(0xc4), PACKET_TRANSFORM_LUT_ENTRY(0xc5), PACKET_TRANSFORM_LUT_ENTRY(0xc6), PACKET_TRANSFORM_LUT_ENTRY(0xc7),
    PACKET_TRANSFORM_LUT_ENTRY(0xc8), PACKET_TRANSFORM_LUT_ENTRY(0xc9), PACKET_TRANSFORM_LUT_ENTRY(0xca), PACKET_TRANSFORM_LUT_ENTRY(0xcb),
    PACKET_TRANSFORM_LUT_ENTRY(0xcc), PACKET_TRANSFORM_LUT_ENTRY(0xcd), PACKET_TRANSFORM_LUT_ENTRY(0xce), PACKET_TRANSFORM_LUT_ENTRY(0xcf),
    PACKET_TRANSFORM_LUT_ENTRY(0xd0), PACKET_TRANSFORM_LUT_ENTRY(0xd1), PACKET_TRANSFORM_LUT_ENTRY(0xd2), PACKET_TRANSFORM_LUT_ENTRY(0xd3),
    PACKET_TRANSFORM_LUT_ENTRY(0xd4), PACKET_TRANSFORM_LUT_ENTRY(0xd5), PACKET_TRANSFORM_LUT_ENTRY(0xd6), PACKET_TRANSFORM_LUT_ENTRY(0xd7),
    PACKET_TRANSFORM_LUT_ENTRY(0xd8), PACKET_TRANSFORM_LUT_ENTRY(0xd9), PACKET_TRANSFORM_LUT_ENTRY(0xda), PACKET_TRANSFORM_LUT_ENTRY(0xdb),
    PACKET_TRANSFORM_LUT_ENTRY(0xdc), PACKET_TRANSFORM_LUT_ENTRY(0xdd), PACKET_TRANSFORM_LUT_ENTRY(0xde), PACKET_TRANSFORM_LUT_ENTRY(0xdf),
    PACKET_TRANSFORM_LUT_ENTRY(0xe0), PACKET_TRANSFORM_LUT_ENTRY(0xe1), PACKET_TRANSFORM_LUT_ENTRY(0xe2), PACKET_TRANSFORM_LUT_ENTRY(0xe3),
    PACKET_TRANSFORM_LUT_ENTRY(0xe4), PACKET_TRANSFORM_LUT_ENTRY(0xe5), PACKET_TRANSFORM_LUT_ENTRY(0xe6), PACKET_TRANSFORM_LUT_ENTRY(0xe7),
    PACKET_TRANSFORM_LUT_ENTRY(0xe8), PACKET_TRANSFORM_LUT_ENTRY(0xe9), PACKET_TRANSFORM_LUT_ENTRY(0xea), PACKET_TRANSFORM_LUT_ENTRY(0xeb),
    PACKET_TRANSFORM_LUT_ENTRY(0xec), PACKET_TRANSFORM_LUT_ENTRY(0xed), PACKET_TRANSFORM_LUT_ENTRY(0xee), PACKET_TRANSFORM_LUT_ENTRY(0xef),
    PACKET_TRANSFORM_LUT_ENTRY(0xf0), PACKET_TRANSFORM_LUT_ENTRY(0xf1), PACKET_TRANSFORM_LUT_ENTRY(0xf2), PACKET_TRANSFORM_LUT_ENTRY(0xf3),
    PACKET_TRANSFORM_LUT_ENTRY(0xf4), PACKET_TRANSFORM_LUT_ENTRY(0xf5), PACKET_TRANSFORM_LUT_ENTRY(0xf6), PACKET_TRANSFORM_LUT_ENTRY(0xf7),
    PACKET_TRANSFORM_LUT_ENTRY(0xf8), PACKET_TRANSFORM_LUT_ENTRY(0xf9), PACKET_TRANSFORM_LUT_ENTRY(0xfa), PACKET_TRANSFORM_LUT_ENTRY(0xfb),
    PACKET_TRANSFORM_LUT_ENTRY(0xfc), PACKET_TRANSFORM_LUT_ENTRY(0xfd), PACKET_TRANSFORM_LUT_ENTRY(0xfe), PACKET_TRANSFORM_LUT_ENTRY(0xff)
};

#undef PACKET_TRANSFORM_LUT_ENTRY

// UID:0002AL | by-memory/0x0069ba40-0x0069bac4.PacketTransformMutableState.md | Completion:90 | Confidence:93
unsigned char g_handshakeSeedBytes[12];
unsigned char g_packetNonceScratch[12];
char *g_packetTransformKeyText;
int g_packetTransformStride;
unsigned char g_packetSequenceByte;
static unsigned char s_packetTransformSequencePadding[3];
unsigned char g_packetXorTablePrimary[48];
unsigned char g_packetXorTableAlternate[48];

// UID:0004ME | by-memory/0x00575b90-0x00575c30.InitializePacketTransformAlternateKey.md | Completion:91 | Confidence:92
void InitializePacketTransformAlternateKey(char *keyText)
{
    MemoryMan *memoryMan = GetMemoryMan();
    char *digest = Md5StringHex(keyText);

    memoryMan->MemmoveWrapper(g_packetNonceScratch,
                              digest,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + 2 * g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);
    memoryMan->MemmoveWrapper(g_packetXorTableAlternate + 3 * g_packetXorAlternateSize,
                              g_packetNonceScratch,
                              g_packetXorAlternateSize);

    free(digest);
}

// UID:0004MF | by-memory/0x00575c30-0x00575caa.BuildPacketTransformKeyText.md | Completion:92 | Confidence:94
void BuildPacketTransformKeyText(char *keyText)
{
    char *firstDigest = Md5StringHex(keyText);
    char *secondDigest = Md5StringHex(firstDigest);

    sprintf_s(g_packetTransformKeyText, 1025, "%s", secondDigest);

    free(firstDigest);
    free(secondDigest);

    for (int iteration = 0; iteration < 31; ++iteration) {
        char *nextDigest = Md5StringHex(g_packetTransformKeyText);
        sprintf_s(g_packetTransformKeyText,
                  1025,
                  "%s%s",
                  g_packetTransformKeyText,
                  nextDigest);
        free(nextDigest);
    }
}

// UID:0001I0 | by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md | Completion:89 | Confidence:91
void InitializePacketNonce(unsigned short nonceBase, unsigned char nonceMiddle)
{
    const int alternateSize = g_packetXorAlternateSize;
    int step = nonceMiddle * nonceMiddle;

    for (int index = 0; index < alternateSize; ++index) {
        const int keyIndex = (nonceBase + index * step) % 1024;
        step += 3;
        g_packetNonceScratch[index] = g_packetTransformKeyText[keyIndex];
    }

    if (static_cast<unsigned int>(alternateSize) >= sizeof(g_packetNonceScratch)) {
        __report_rangecheckfailure(alternateSize);
    }

    g_packetNonceScratch[alternateSize] = 0;

    memmove(g_packetXorTableAlternate,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + 2 * alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
    memmove(g_packetXorTableAlternate + 3 * alternateSize,
            g_packetNonceScratch,
            static_cast<size_t>(alternateSize));
}

// UID:0001I2 | by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md | Completion:88 | Confidence:90
void BuildHandshakeBlock(size_t seedLength, void *seedBlock)
{
    MemoryMan *memoryMan = GetMemoryMan();

    memoryMan->MemmoveWrapper(g_handshakeSeedBytes, seedBlock, seedLength);

    const unsigned char originalByte6 = g_handshakeSeedBytes[6];
    g_packetTransformStride = seedLength;

    g_handshakeSeedBytes[6] =
        static_cast<unsigned char>(g_handshakeSeedBytes[7] +
                                   g_handshakeSeedBytes[1] +
                                   6 * ((static_cast<unsigned int>(g_handshakeSeedBytes[2]) + 1) / 0x12) -
                                   originalByte6 -
                                   0x59);

    g_handshakeSeedBytes[3] =
        static_cast<unsigned char>(g_handshakeSeedBytes[7] +
                                   0x31 +
                                   (((static_cast<unsigned int>(g_handshakeSeedBytes[0]) + 3) >> 1) *
                                    ((originalByte6 - g_handshakeSeedBytes[7]) / 2)));

    memoryMan->MemmoveWrapper(g_packetXorTablePrimary,
                              g_handshakeSeedBytes,
                              seedLength);
    memoryMan->MemmoveWrapper(g_packetXorTablePrimary + g_packetTransformStride,
                              g_handshakeSeedBytes,
                              g_packetTransformStride);
    memoryMan->MemmoveWrapper(g_packetXorTablePrimary + 2 * g_packetTransformStride,
                              g_handshakeSeedBytes,
                              g_packetTransformStride);
    memoryMan->MemmoveWrapper(g_packetXorTablePrimary + 3 * g_packetTransformStride,
                              g_handshakeSeedBytes,
                              g_packetTransformStride);

    g_handshakeSeedBytes[3] = 'c';
    g_handshakeSeedBytes[6] = 't';

    memoryMan->FreeBufferMemory(seedBlock);
}

// UID:0001I5 | by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md | Completion:90 | Confidence:91
void XorTransformBuffer(const unsigned char *source,
                        unsigned char *destination,
                        unsigned int length,
                        const void *keyData,
                        unsigned int keyWordCount)
{
    const unsigned char *keyBytes = static_cast<const unsigned char *>(keyData);
    unsigned int blockIndex = 0;
    const unsigned int fullWordCount = length >> 2;

    for (; blockIndex < fullWordCount; ++blockIndex) {
        const unsigned char *key = keyBytes + 4 * (blockIndex % keyWordCount);
        const unsigned char s0 = source[0];
        const unsigned char s1 = source[1];
        const unsigned char s2 = source[2];
        const unsigned char s3 = source[3];

        destination[0] = static_cast<unsigned char>(s0 ^ key[0]);
        destination[1] = static_cast<unsigned char>(s1 ^ key[1]);
        destination[2] = static_cast<unsigned char>(s2 ^ key[2]);
        destination[3] = static_cast<unsigned char>(s3 ^ key[3]);

        source += 4;
        destination += 4;
    }

    const unsigned int tailBytes = length & 3;
    if (tailBytes == 0) {
        return;
    }

    const unsigned char *key = keyBytes + 4 * (blockIndex % keyWordCount);
    destination[0] = static_cast<unsigned char>(source[0] ^ key[0]);

    if (tailBytes >= 2) {
        destination[1] = static_cast<unsigned char>(source[1] ^ key[1]);
    }

    if (tailBytes == 3) {
        destination[2] = static_cast<unsigned char>(source[2] ^ key[2]);
    }
}

// UID:0000V3 | by-item/PacketTransformHelpers.md | Completion:91 | Confidence:93
// Free-helper declarations are provided by PacketTransform.h.
