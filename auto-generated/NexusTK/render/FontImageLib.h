// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JH
// Source by-file doc: by-file/FontImageLib.md
// UID:00005B | by-class/FontImageLib.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_RENDER_FONTIMAGELIB_H
#define NEXUSTK_RENDER_FONTIMAGELIB_H

#include "../util/LObject.h"
#include "../util/Singleton.h"

class DATFile;
class EPFTileContext;
struct RectBounds;

struct FontGlyphRecord
{
    short advance;
    short top;
    short left;
    short bottom;
    short right;
    short reserved0;
    short reserved1;
    unsigned char encodedRows[1];
};

struct FontSlotStorage
{
    DATFile *archiveFile;
    unsigned short maxCellWidth;
    unsigned short maxCellHeightMinus4;
    FontGlyphRecord *glyphTable[0x10000];
};

class FontImageLib :
    public LObject,
    public Singleton<FontImageLib>
{
public:
    FontImageLib();
    virtual ~FontImageLib();

    void GetFontMetrics(int fontId, short *outWidth, short *outHeight);
    void MeasureGlyphWidth(int fontId,
                           unsigned short ch,
                           unsigned short nextCh,
                           bool decodeBitmap,
                           const unsigned char *colors,
                           RectBounds *outBounds,
                           short *outAdvance,
                           EPFTileContext *outContext);

private:
    FontSlotStorage *EnsureFontSlotLoaded(int fontId);
    int DecodeGlyphBitmap(const FontGlyphRecord *glyph,
                          unsigned short glyphId,
                          bool clearBeforeDecode,
                          const unsigned char *paletteMap,
                          EPFTileContext *tileContext);

    FontSlotStorage m_fontSlots[2];
    unsigned char *m_scratchBuffer;
    int m_scratchBufferBytes;
};

extern FontImageLib *g_pFontImageLib;

#endif
