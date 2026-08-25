// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N5
// Source by-file doc: by-file/ResourceLayoutTable.md
// UID:0002KQ | by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md | Completion:93 | Confidence:93
#include "ResourceLayoutTable.h"

#include "EPFTileContext.h"
#include "ImageFrameTable.h"
#include "ImageLib.h"
#include "../ui/core/RectBounds.h"
#include "../util/MemoryMan.h"

void __stdcall ResourceLayoutRawBufferLookupEntry(
    const unsigned char *buffer,
    EPFTileContext *outContext)
{
    MemoryMan *memory = GetMemoryMan();
    unsigned short header[4];
    int entryTableOffset;
    memory->MemmoveWrapper(header, buffer, sizeof(header));
    memory->MemmoveWrapper(&entryTableOffset, buffer + 8,
                           sizeof(entryTableOffset));

    ResourceLayoutEntry *entries =
        static_cast<ResourceLayoutEntry *>(
            memory->AllocateBufferMemory(
                sizeof(ResourceLayoutEntry) * (header[0] + 1)));
    const unsigned char *record = buffer + 12 + entryTableOffset;
    short top;
    short left;
    short bottom;
    short right;
    int offsets[2];
    memory->MemmoveWrapper(&top, record, sizeof(top));
    memory->MemmoveWrapper(&left, record + 2, sizeof(left));
    memory->MemmoveWrapper(&bottom, record + 4, sizeof(bottom));
    memory->MemmoveWrapper(&right, record + 6, sizeof(right));
    memory->MemmoveWrapper(offsets, record + 8, sizeof(offsets));

    InitRectBounds(reinterpret_cast<RectBounds *>(&entries[0]),
                   left, top, right, bottom);
    unsigned char *payloadBase =
        const_cast<unsigned char *>(buffer + 12);
    entries[0].pixelData = payloadBase + offsets[0];
    entries[0].encodedMaskData = payloadBase + offsets[1];

    if (outContext != 0) {
        outContext->pixelData = entries[0].pixelData;
        outContext->rowStridePixels =
            entries[0].right - entries[0].left;
        outContext->bounds =
            *reinterpret_cast<RectBounds *>(&entries[0]);
        // Preserve the original uninitialized next-row read and leak.
        outContext->encodedMaskByteCount =
            static_cast<int>(entries[1].pixelData -
                             entries[0].encodedMaskData);
        outContext->encodedMaskBytes =
            entries[0].encodedMaskData;
    }
}

// UID:0002KT | by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md | Completion:92 | Confidence:93
RectBounds *__stdcall ResourceLayoutRawRecordGetEntryRect(
    const ArchiveMetadataTable *table,
    int entryIndex,
    RectBounds *bounds)
{
    if (entryIndex < table->frameCount) {
        *bounds = table->records[entryIndex].bounds;
    } else {
        InitRectBounds(bounds, 0, 0, 0, 0);
    }
    return bounds;
}
