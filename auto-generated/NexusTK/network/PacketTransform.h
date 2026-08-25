// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M9
// Source by-file doc: by-file/PacketTransform.md
// UID:0000TG | by-global/PacketTransformGlobals.md | Completion:90 | Confidence:92
#pragma once

#include <stddef.h>

extern int g_packetXorAlternateSize;
extern unsigned int g_packetTransformLut[256];
extern unsigned char g_handshakeSeedBytes[12];
extern unsigned char g_packetNonceScratch[12];
extern char *g_packetTransformKeyText;
extern int g_packetTransformStride;
extern unsigned char g_packetSequenceByte;
extern unsigned char g_packetXorTablePrimary[48];
extern unsigned char g_packetXorTableAlternate[48];

// UID:0000V3 | by-item/PacketTransformHelpers.md | Completion:91 | Confidence:93
void InitializePacketTransformAlternateKey(char *keyText);
void BuildPacketTransformKeyText(char *keyText);
void InitializePacketNonce(unsigned short nonceBase,
                           unsigned char nonceMiddle);
void BuildHandshakeBlock(size_t seedLength, void *seedBlock);
void XorTransformBuffer(const unsigned char *source,
                        unsigned char *destination,
                        unsigned int length,
                        const void *keyData,
                        unsigned int keyWordCount);
