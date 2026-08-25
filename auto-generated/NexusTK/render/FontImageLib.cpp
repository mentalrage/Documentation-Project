// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JH
// Source by-file doc: by-file/FontImageLib.md
// UID:0000QX | by-global/g_pFontImageLib.md | Completion:92 | Confidence:94
class FontImageLib;

FontImageLib *g_pFontImageLib = 0;

// UID:00005B | by-class/FontImageLib.md | Completion:94 | Confidence:94
#include "FontImageLib.h"

// UID:0002HP | by-memory/0x004b5f00-0x004b5f54.FontImageLibConstructor.md | Completion:92 | Confidence:94
FontImageLib::FontImageLib()
    : LObject(),
      Singleton<FontImageLib>()
{
    memset(m_fontSlots, 0, sizeof(m_fontSlots));
    m_scratchBuffer = 0;
    m_scratchBufferBytes = 0;
}

// UID:00015B | by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md | Completion:92 | Confidence:94
FontImageLib::~FontImageLib()
{
    for (int i = 0; i < 2; ++i) {
        if (m_fontSlots[i].archiveFile != NULL) {
            delete m_fontSlots[i].archiveFile;
        }
    }

    if (m_scratchBuffer != NULL) {
        GetMemoryMan()->FreeBufferMemory(m_scratchBuffer);
    }
}

// UID:0002HQ | by-memory/0x004b5ff0-0x004b6018.FontImageLibGetFontMetrics.md | Completion:90 | Confidence:93
void FontImageLib::GetFontMetrics(int fontId, short *outWidth, short *outHeight)
{
    EnsureFontSlotLoaded(fontId);

    if (outWidth != NULL) {
        *outWidth = 12;
    }
    if (outHeight != NULL) {
        *outHeight = 12;
    }
}

// UID:0002HR | by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md | Completion:90 | Confidence:92
void FontImageLib::MeasureGlyphWidth(int fontId,
                                     unsigned short glyphId,
                                     unsigned short nextGlyphId,
                                     bool clearBeforeDecode,
                                     const unsigned char *paletteMap,
                                     RectBounds *outBounds,
                                     short *outAdvance,
                                     EPFTileContext *outContext)
{
    (void)nextGlyphId;

    FontGlyphRecord *glyph = NULL;
    for (;;) {
        FontSlotStorage *slot = EnsureFontSlotLoaded(fontId);
        glyph = slot->glyphTable[glyphId];
        if (glyph != NULL && glyph->right - glyph->left != 0) {
            break;
        }
        glyphId = 63;
    }

    if (outBounds != NULL) {
        InitRectBounds(outBounds, glyph->left, glyph->top, glyph->right, glyph->bottom);
    }
    if (outAdvance != NULL) {
        *outAdvance = glyph->advance;
    }
    if (outContext != NULL) {
        outContext->ReleaseBuffers();
        DecodeGlyphBitmap(glyph, glyphId, clearBeforeDecode, paletteMap, outContext);
    }
}

// UID:0002HS | by-memory/0x004b60c0-0x004b61d9.FontImageLibEnsureFontSlotLoaded.md | Completion:91 | Confidence:93
FontSlotStorage *FontImageLib::EnsureFontSlotLoaded(int fontId)
{
    int slotIndex = fontId;
    if (slotIndex < 0 || slotIndex >= 2) {
        slotIndex = 0;
    }

    FontSlotStorage *slot = &m_fontSlots[slotIndex];
    if (slot->archiveFile != NULL) {
        return slot;
    }

    wchar_t fileName[32];
    swprintf_s(fileName, 32, L"BARAM%02d.EFT", slotIndex);

    slot->archiveFile = new DATFile;
    slot->archiveFile->Open(fileName);

    unsigned char *payloadBase = static_cast<unsigned char *>(slot->archiveFile->GetDataPointer());
    slot->archiveFile->Read(&slot->maxCellWidth, sizeof(slot->maxCellWidth));
    slot->archiveFile->Read(&slot->maxCellHeightMinus4, sizeof(slot->maxCellHeightMinus4));
    slot->maxCellHeightMinus4 = static_cast<unsigned short>(slot->maxCellHeightMinus4 - 4);

    for (int glyphIndex = 0; glyphIndex < 0x10000; ++glyphIndex) {
        int offset = 0;
        slot->archiveFile->Read(&offset, sizeof(offset));
        slot->glyphTable[glyphIndex] = offset != 0
            ? reinterpret_cast<FontGlyphRecord *>(payloadBase + offset)
            : NULL;
    }

    return slot;
}

// UID:0002HT | by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md | Completion:91 | Confidence:93
int FontImageLib::DecodeGlyphBitmap(const FontGlyphRecord *glyph,
                                    unsigned short glyphId,
                                    bool clearBeforeDecode,
                                    const unsigned char *paletteMap,
                                    EPFTileContext *tileContext)
{
    (void)glyphId;

    InitRectBounds(&tileContext->bounds, glyph->left, glyph->top, glyph->right, glyph->bottom);
    tileContext->rowStridePixels = tileContext->bounds.right - tileContext->bounds.left;

    const int requiredBytes = RectArea(&tileContext->bounds);
    if (requiredBytes > m_scratchBufferBytes) {
        if (m_scratchBuffer != NULL) {
            m_scratchBuffer = static_cast<unsigned char *>(
                GetMemoryMan()->ReallocateBufferMemory(m_scratchBuffer, requiredBytes));
        } else {
            m_scratchBuffer = static_cast<unsigned char *>(
                GetMemoryMan()->AllocateBufferMemory(requiredBytes));
        }
        m_scratchBufferBytes = requiredBytes;
    }

    if (clearBeforeDecode) {
        memset(m_scratchBuffer, 0, m_scratchBufferBytes);
    }

    tileContext->pixelData = m_scratchBuffer;
    tileContext->encodedMaskByteCount = 0;
    tileContext->encodedMaskBytes = 0;

    const unsigned char *encoded = glyph->encodedRows;
    unsigned char *row = m_scratchBuffer;
    const int width = tileContext->bounds.right - tileContext->bounds.left;
    const int height = tileContext->bounds.bottom - tileContext->bounds.top;

    for (int y = 0; y < height; ++y) {
        int x = 0;
        for (;;) {
            const unsigned char token = *encoded++;
            if (token == 0) {
                break;
            }

            const int runStart = x;
            const int runLength = token & 0x1f;
            const int paletteIndex = token >> 5;
            x += runLength;

            if ((!clearBeforeDecode && paletteIndex != 5) ||
                (clearBeforeDecode && paletteIndex != 0)) {
                if (x > 0 && runStart < width) {
                    const int left = runStart > 0 ? runStart : 0;
                    const int right = x < width ? x : width;
                    if (right > left) {
                        memset(row + left, paletteMap[paletteIndex], right - left);
                    }
                }
            }
        }

        row += tileContext->rowStridePixels;
    }

    return height;
}

// UID:0001UK | by-type/by-struct/FontGlyphRecord.md | Completion:92 | Confidence:94
// FontGlyphRecord is declared before FontImageLib by [UID:00005B][FontImageLib](by-class/FontImageLib.md).
// This page remains exact resource-record layout evidence only.

// UID:0001UL | by-type/by-struct/FontImageLibLayout.md | Completion:92 | Confidence:96
// No separate layout C++ should be emitted for [UID:0001UL].
// The FontImageLib declaration owns the LObject base at +0x00, empty
// Singleton<FontImageLib> base and first FontSlotStorage at +0x04,
// second slot at +0x4000c, scratch pointer at +0x80014, and scratch
// byte count at +0x80018. RTTI PMD +0x04 and size 0x8001c prove EBO.

// UID:0001UM | by-type/by-struct/FontSlotStorage.md | Completion:92 | Confidence:94
// FontSlotStorage is declared before FontImageLib by [UID:00005B][FontImageLib](by-class/FontImageLib.md).
// This page remains exact per-font-slot layout evidence only.

// UID:0001XM | by-type/by-vtable/FontImageLibVtable.md | Completion:92 | Confidence:96
// No handwritten vtable or RTTI data should be emitted for [UID:0001XM].
// The FontImageLib declaration, virtual destructor, and direct empty
// Singleton<FontImageLib> base regenerate the three-slot vtable and
// three-entry FontImageLib/LObject/Singleton class hierarchy.

// UID:0003BI | by-memory\0x0061a600-0x0061a61c.FontImageLibResourcePatternString.md | Completion:85 | Confidence:92 | Empty Emitter Marker
