// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MA
// Source by-file doc: by-file/Palette.md
// UID:00003Z | by-class/DLPalette.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_RENDER_PALETTE_H
#define NEXUSTK_RENDER_PALETTE_H

#include "../util/LObject.h"

class File;
struct EPFTileContext;

struct DLPaletteRange
{
    unsigned char firstIndex;
    unsigned char lastIndex;
};

class DLPalette : public LObject
{
    friend struct EPFTileContext;

public:
    // UID:0004HQ | by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md | Completion:90 | Confidence:93
unsigned short MapColor(unsigned int colorIndex) const;

// UID:0004HR | by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md | Completion:89 | Confidence:92
void SetColor(
    unsigned int colorIndex,
    unsigned char red,
    unsigned char green,
    unsigned char blue);

// UID:0004HS | by-memory/0x00542b50-0x00542b63.DLPaletteSetPackedColor.md | Completion:94 | Confidence:96
void SetPackedColor(unsigned int colorIndex, unsigned short packedColor);

// UID:0004HT | by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md | Completion:88 | Confidence:91
void ExpandMappedColor(unsigned int index, unsigned char *low, unsigned char *middle, unsigned char *high);

// UID:0004HV | by-memory/0x00542be0-0x00542c95.DLPaletteCopyConstructor.md | Completion:94 | Confidence:96
DLPalette(const DLPalette &source);

// UID:0004HY | by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md | Completion:88 | Confidence:90
void CopyPaletteState(const DLPalette &source);

// UID:0004I0 | by-memory/0x00542df0-0x00542e5f.DLPaletteLoadFromFile.md | Completion:94 | Confidence:94
void LoadFromFile(const wchar_t *path);

// UID:0004I1 | by-memory/0x00542e60-0x00542f91.DLPaletteLoadFromStream.md | Completion:90 | Confidence:93
void LoadFromStream(File *stream);

// UID:0001E5 | by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md | Completion:90 | Confidence:93
void ApplyPaletteEntryMoves();

// UID:0004I4 | by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md | Completion:94 | Confidence:96
void LoadFromBitmapPalette(const unsigned char *compressedPalette,
                           unsigned int compressedSize);

private:
    DLPaletteRange *m_paletteRanges;
    int m_paletteRangeCount;
    unsigned char m_paletteHeader[32];
    unsigned short m_mappedColors[256];
};

#endif
