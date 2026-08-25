// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K1
// Source by-file doc: by-file/ImageFrameTable.md
// UID:0000UN | by-item/EPFArchiveMetadataTable.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_RENDER_IMAGEFRAMETABLE_H
#define NEXUSTK_RENDER_IMAGEFRAMETABLE_H

#include "../ui/core/RectBounds.h"

struct PackedArchiveRecord
{
    RectBounds bounds;
    unsigned char *payloadStart;
    unsigned char *payloadEnd;
};

struct ArchiveMetadataTable
{
    unsigned short frameCount;
    unsigned short maxWidth;
    unsigned short maxHeight;
    unsigned short reserved;
    PackedArchiveRecord *records;
};

struct FrameDrawRecord
{
    int reserved0;
    unsigned char *payloadStart;
    int reserved8;
    int width;
    RectBounds sourceRect;
    int payloadSpan;
    unsigned char *payloadEnd;
};

#endif
