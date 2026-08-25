// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000N5
// Source by-file doc: by-file/ResourceLayoutTable.md
// UID:0002KQ | by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md | Completion:93 | Confidence:93
#ifndef NEXUSTK_RENDER_RESOURCELAYOUTTABLE_H
#define NEXUSTK_RENDER_RESOURCELAYOUTTABLE_H

struct ArchiveMetadataTable;
struct EPFTileContext;
struct RectBounds;

void __stdcall ResourceLayoutRawBufferLookupEntry(
    const unsigned char *buffer,
    EPFTileContext *outContext);
RectBounds *__stdcall ResourceLayoutRawRecordGetEntryRect(
    const ArchiveMetadataTable *table,
    int entryIndex,
    RectBounds *bounds);

#endif
