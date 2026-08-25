// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MA
// Source by-file doc: by-file/Palette.md
// UID:00003Z | by-class/DLPalette.md | Completion:92 | Confidence:94
#include "Palette.h"
#include "../archive/DATFile.h"
#include "Surface.h"
#include "../third_party/zlib/zlib.h"

#include <string.h>
#include <windows.h>

// UID:0004HQ | by-memory/0x00542ac0-0x00542adc.DLPaletteMapColor.md | Completion:90 | Confidence:93
unsigned short DLPalette::MapColor(unsigned int colorIndex) const
{
    if (colorIndex > 0xff)
        return 0;
    return m_mappedColors[colorIndex];
}

// UID:0004HR | by-memory/0x00542ae0-0x00542b4a.DLPaletteSetColor.md | Completion:89 | Confidence:92
void DLPalette::SetColor(
    unsigned int colorIndex,
    unsigned char red,
    unsigned char green,
    unsigned char blue)
{
    if (colorIndex > 0xff)
        return;

    if (red > 0 && red < 8)
        red = 8;
    if (green > 0 && green < 8)
        green = 8;
    if (blue > 0 && blue < 8)
        blue = 8;

    m_mappedColors[colorIndex] = g_pfnPackPixel(red, green, blue);
}

// UID:0004HS | by-memory/0x00542b50-0x00542b63.DLPaletteSetPackedColor.md | Completion:94 | Confidence:96
void DLPalette::SetPackedColor(unsigned int colorIndex,
                               unsigned short packedColor)
{
    m_mappedColors[colorIndex] = packedColor;
}

// UID:0004HT | by-memory/0x00542b70-0x00542baf.DLPaletteExpandMappedColorRaw.md | Completion:88 | Confidence:91
void DLPalette::ExpandMappedColor(unsigned int index,
                                  unsigned char *low,
                                  unsigned char *middle,
                                  unsigned char *high)
{
    if (index > 0xff) {
        *high = 0;
        *middle = 0;
        *low = 0;
        return;
    }

    g_pfnExpandPixel(m_mappedColors[index], low, middle, high);
}


// UID:0004HV | by-memory/0x00542be0-0x00542c95.DLPaletteCopyConstructor.md | Completion:94 | Confidence:96
DLPalette::DLPalette(const DLPalette &source)
{
    memcpy(m_paletteHeader, source.m_paletteHeader, sizeof(m_paletteHeader));
    m_paletteRangeCount = source.m_paletteRangeCount;

    if (source.m_paletteRanges != NULL)
    {
        m_paletteRanges = new DLPaletteRange[m_paletteRangeCount];
        memmove(
            m_paletteRanges,
            source.m_paletteRanges,
            sizeof(DLPaletteRange) * m_paletteRangeCount);
    }
    else
    {
        m_paletteRanges = NULL;
    }

    memcpy(m_mappedColors, source.m_mappedColors, sizeof(m_mappedColors));
}



// UID:0004HY | by-memory/0x00542d00-0x00542d81.DLPaletteRawCopyHelper.md | Completion:88 | Confidence:90
void DLPalette::CopyPaletteState(const DLPalette &source)
{
    memcpy(m_paletteHeader, source.m_paletteHeader, sizeof(m_paletteHeader));
    m_paletteRangeCount = source.m_paletteRangeCount;

    if (source.m_paletteRanges != NULL)
    {
        m_paletteRanges = new DLPaletteRange[m_paletteRangeCount];
        memmove(
            m_paletteRanges,
            source.m_paletteRanges,
            sizeof(DLPaletteRange) * m_paletteRangeCount);
    }
    else
    {
        m_paletteRanges = NULL;
    }

    memcpy(m_mappedColors, source.m_mappedColors, sizeof(m_mappedColors));
}

// UID:0004I0 | by-memory/0x00542df0-0x00542e5f.DLPaletteLoadFromFile.md | Completion:94 | Confidence:94
void DLPalette::LoadFromFile(const wchar_t *path)
{
    DATFile file;

    file.Open(path);
    LoadFromStream(&file);
    file.Close();
}


// UID:0001E5 | by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md | Completion:90 | Confidence:93
void DLPalette::ApplyPaletteEntryMoves()
{
    for (int rangeIndex = 0; rangeIndex < m_paletteRangeCount; ++rangeIndex)
    {
        const unsigned char destination = m_paletteRanges[rangeIndex].firstIndex;
        const unsigned char source = m_paletteRanges[rangeIndex].lastIndex;
        const unsigned short savedColor = m_mappedColors[source];

        if (destination < source)
        {
            for (int index = source; index > destination; --index)
                m_mappedColors[index] = m_mappedColors[index - 1];
        }
        else if (destination > source)
        {
            for (int index = source; index < destination; ++index)
                m_mappedColors[index] = m_mappedColors[index + 1];
        }

        m_mappedColors[destination] = savedColor;
    }
}


// UID:0004I4 | by-memory/0x005430a0-0x00543149.DLPaletteLoadFromBitmapPalette.md | Completion:94 | Confidence:96
void DLPalette::LoadFromBitmapPalette(const unsigned char *compressedPalette,
                                      unsigned int compressedSize)
{
    RGBTRIPLE bitmapPalette[256];
    uLongf bitmapPaletteSize;

    if (uncompress(reinterpret_cast<Bytef *>(bitmapPalette),
                   &bitmapPaletteSize,
                   compressedPalette,
                   compressedSize) == Z_OK)
    {
        for (unsigned int paletteIndex = 0; paletteIndex < 256; ++paletteIndex)
        {
            m_mappedColors[paletteIndex] =
                g_pfnPackPixel(bitmapPalette[paletteIndex].rgbtRed,
                               bitmapPalette[paletteIndex].rgbtGreen,
                               bitmapPalette[paletteIndex].rgbtBlue);
        }
    }
}







// UID:000262 | by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md | Completion:88 | Confidence:92
// UID000262 is source-generated read-only data, not a standalone declaration.
// DLPalette and PaletteLib vtables are emitted from their class declarations.
// The DLPalette signature and palette filename literals are emitted from
// DLPalette/PaletteLib use sites, primarily PaletteLib::PaletteLib().

// UID:0004HU | by-memory\0x00542bb0-0x00542bda.DLPaletteDefaultConstructor.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0004HW | by-memory\0x00542ca0-0x00542ccf.DLPaletteDestructor.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0004HX | by-memory\0x00542cd0-0x00542cf3.DLPaletteFreePaletteData.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0004I1 | by-memory\0x00542e60-0x00542f91.DLPaletteLoadFromStream.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0004I2 | by-memory\0x00543020-0x00543091.DLPaletteLoadFromRawRGBA.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0003MU | by-memory\0x005443b0-0x00544411.DLPaletteScalarDeletingDestructor.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0000V4 | by-item\PaletteSlotTable.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0004HZ | by-memory\0x00542d90-0x00542de3.DLPaletteColorTransformRaw.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003LS | by-memory\0x00543450-0x005435a5.CloneDLPaletteList.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0003LT | by-memory\0x005435b0-0x00543665.ApplyPaletteEntryMovesToCollection.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0002R4 | by-memory\0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker
