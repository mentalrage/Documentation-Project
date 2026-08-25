// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J4
// Source by-file doc: by-file/EPFTileContext.md
// UID:00004I | by-class/EPFTileContext.md | Completion:94 | Confidence:94
#include "EPFTileContext.h"
#include "Palette.h"
#include "SoftwareBlend16.h"
#include "Surface.h"
#include "../util/MemoryMan.h"

// UID:0000XY | by-memory/0x00457a60-0x00458610.EPFTileContext.md | Completion:94 | Confidence:94
EPFTileContext::EPFTileContext()
{
    pixelFormat = kEPFTilePixelFormatIndexed8;
    pixelData = NULL;
    alphaData = NULL;
    rowStridePixels = 0;
    InitRectBounds(&bounds, 0, 0, 0, 0);
    encodedMaskByteCount = 0;
    encodedMaskBytes = NULL;
}

void EPFTileContext::BuildEncodedMask()
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        BuildEncodedMask16();
        return;
    }

    MemoryMan *memoryMan = GetMemoryMan();

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }

    unsigned char *rowPixels = static_cast<unsigned char *>(pixelData);
    if (rowPixels == NULL) {
        return;
    }

    unsigned char encodedMask[100000];
    unsigned char *output = encodedMask;
    const int width = bounds.right - bounds.left;

    for (int row = bounds.top; row < bounds.bottom; ++row) {
        unsigned char runLength = 1;
        bool transparent = rowPixels[0] == 0;

        for (int column = 1; column < width; ++column) {
            const bool nextTransparent = rowPixels[column] == 0;

            if (transparent == nextTransparent) {
                ++runLength;
                if (runLength != 127) {
                    continue;
                }
            }

            *output++ = static_cast<unsigned char>(
                runLength | (transparent ? 0 : 0x80));
            ++encodedMaskByteCount;
            runLength = 1;
            transparent = nextTransparent;
        }

        *output++ = static_cast<unsigned char>(
            runLength | (transparent ? 0 : 0x80));
        *output++ = 0;
        encodedMaskByteCount += 2;
        rowPixels += rowStridePixels;
    }

    encodedMaskBytes = static_cast<unsigned char *>(
        memoryMan->AllocateBufferMemory(encodedMaskByteCount));
    memoryMan->MemmoveWrapper(
        encodedMaskBytes, encodedMask, encodedMaskByteCount);
}

void EPFTileContext::BuildEncodedMask16()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }

    unsigned short *rowPixels = static_cast<unsigned short *>(pixelData);
    if (rowPixels == NULL) {
        return;
    }

    unsigned char encodedMask[100000];
    unsigned char *output = encodedMask;
    const int width = bounds.right - bounds.left;

    for (int row = bounds.top; row < bounds.bottom; ++row) {
        unsigned char runLength = 1;
        bool transparent = rowPixels[0] == 0;

        for (int column = 1; column < width; ++column) {
            const bool nextTransparent = rowPixels[column] == 0;

            if (transparent == nextTransparent) {
                ++runLength;
                if (runLength != 127) {
                    continue;
                }
            }

            *output++ = static_cast<unsigned char>(
                runLength | (transparent ? 0 : 0x80));
            ++encodedMaskByteCount;
            runLength = 1;
            transparent = nextTransparent;
        }

        *output++ = static_cast<unsigned char>(
            runLength | (transparent ? 0 : 0x80));
        *output++ = 0;
        encodedMaskByteCount += 2;
        rowPixels += rowStridePixels;
    }

    encodedMaskBytes = static_cast<unsigned char *>(
        memoryMan->AllocateBufferMemory(encodedMaskByteCount));
    memoryMan->MemmoveWrapper(
        encodedMaskBytes, encodedMask, encodedMaskByteCount);
}

void EPFTileContext::CopyTo(EPFTileContext *destination) const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        CopyRgb16To(destination);
        return;
    }

    MemoryMan *memoryMan = GetMemoryMan();
    destination->ReleaseBuffers();
    memoryMan->MemmoveWrapper(destination, this, sizeof(*this));

    const int byteCount =
        rowStridePixels * (bounds.bottom - bounds.top);

    if (pixelData != NULL) {
        destination->pixelData =
            memoryMan->AllocateBufferMemory(byteCount);
        memoryMan->MemmoveWrapper(
            destination->pixelData, pixelData, byteCount);
    }

    if (alphaData != NULL) {
        destination->alphaData = static_cast<unsigned short *>(
            memoryMan->AllocateBufferMemory(byteCount));
        memoryMan->MemmoveWrapper(
            destination->alphaData, alphaData, byteCount);
    }

    if (encodedMaskBytes != NULL) {
        destination->encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->AllocateBufferMemory(encodedMaskByteCount));
        memoryMan->MemmoveWrapper(
            destination->encodedMaskBytes,
            encodedMaskBytes,
            encodedMaskByteCount);
    }
}

void EPFTileContext::CopyRgb16To(EPFTileContext *destination) const
{
    MemoryMan *memoryMan = GetMemoryMan();
    destination->ReleaseBuffers();
    memoryMan->MemmoveWrapper(destination, this, sizeof(*this));

    const int byteCount =
        2 * rowStridePixels * (bounds.bottom - bounds.top);

    if (pixelData != NULL) {
        destination->pixelData =
            memoryMan->AllocateBufferMemory(byteCount);
        memoryMan->MemmoveWrapper(
            destination->pixelData, pixelData, byteCount);
    }

    if (alphaData != NULL) {
        destination->alphaData = static_cast<unsigned short *>(
            memoryMan->AllocateBufferMemory(byteCount));
        memoryMan->MemmoveWrapper(
            destination->alphaData, alphaData, byteCount);
    }

    if (encodedMaskBytes != NULL) {
        destination->encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->AllocateBufferMemory(encodedMaskByteCount));
        memoryMan->MemmoveWrapper(
            destination->encodedMaskBytes,
            encodedMaskBytes,
            encodedMaskByteCount);
    }
}

EPFTileContext *EPFTileContext::CreateHalfScaleCopy() const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        return CreateHalfScaleRgb16Copy();
    }

    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext *copy = new EPFTileContext;

    copy->bounds.left = bounds.left / 2;
    copy->bounds.top = bounds.top / 2;
    copy->bounds.right =
        copy->bounds.left + (bounds.right - bounds.left) / 2;
    copy->bounds.bottom =
        copy->bounds.top + (bounds.bottom - bounds.top) / 2;
    copy->rowStridePixels = copy->bounds.right - copy->bounds.left;
    copy->pixelData = memoryMan->AllocateBufferMemory(
        RectArea(&copy->bounds));

    const unsigned char *sourceRow =
        static_cast<const unsigned char *>(pixelData);
    unsigned char *destination =
        static_cast<unsigned char *>(copy->pixelData);

    for (int row = copy->bounds.top;
         row < copy->bounds.bottom;
         ++row) {
        const unsigned char *source = sourceRow;
        for (int column = copy->bounds.left;
             column < copy->bounds.right;
             ++column) {
            *destination++ = *source;
            source += 2;
        }
        sourceRow += 2 * rowStridePixels;
    }

    return copy;
}

EPFTileContext *EPFTileContext::CreateHalfScaleRgb16Copy() const
{
    MemoryMan *memoryMan = GetMemoryMan();
    EPFTileContext *copy = new EPFTileContext;

    copy->bounds.left = bounds.left / 2;
    copy->bounds.top = bounds.top / 2;
    copy->bounds.right =
        copy->bounds.left + (bounds.right - bounds.left) / 2;
    copy->bounds.bottom =
        copy->bounds.top + (bounds.bottom - bounds.top) / 2;
    copy->rowStridePixels = copy->bounds.right - copy->bounds.left;
    copy->pixelData = memoryMan->AllocateBufferMemory(
        2 * RectArea(&copy->bounds));

    const unsigned short *sourceRow =
        static_cast<const unsigned short *>(pixelData);
    unsigned short *destination =
        static_cast<unsigned short *>(copy->pixelData);

    for (int row = copy->bounds.top;
         row < copy->bounds.bottom;
         ++row) {
        const unsigned short *source = sourceRow;
        for (int column = copy->bounds.left;
             column < copy->bounds.right;
             ++column) {
            *destination++ = *source;
            source += 2;
        }
        sourceRow += 2 * rowStridePixels;
    }

    return copy;
}

void EPFTileContext::AllocateIndexed8Pixels(int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatIndexed8;
    pixelData = GetMemoryMan()->AllocateBufferMemory(width * height);
    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
    alphaData = NULL;
}

void EPFTileContext::AllocateRgb16Pixels(int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatRgb16;
    pixelData = GetMemoryMan()->AllocateBufferMemory(
        2 * width * height);
    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
    alphaData = NULL;
}

void EPFTileContext::AllocateRgb16PixelsWithAlpha(
    int width, int height)
{
    ReleaseBuffers();
    pixelFormat = kEPFTilePixelFormatRgb16;

    const int byteCount = 2 * width * height;
    pixelData = GetMemoryMan()->AllocateBufferMemory(byteCount);
    alphaData = static_cast<unsigned short *>(
        GetMemoryMan()->AllocateBufferMemory(byteCount));

    bounds.left = 0;
    bounds.top = 0;
    bounds.right = width;
    bounds.bottom = height;
    rowStridePixels = width;
}

void EPFTileContext::ReleaseBuffers()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (pixelData != NULL) {
        pixelData = memoryMan->FreeBufferMemory(pixelData);
    }

    if (alphaData != NULL) {
        alphaData = static_cast<unsigned short *>(
            memoryMan->FreeBufferMemory(alphaData));
    }

    if (encodedMaskBytes != NULL) {
        encodedMaskByteCount = 0;
        encodedMaskBytes = static_cast<unsigned char *>(
            memoryMan->FreeBufferMemory(encodedMaskBytes));
    }
}

// UID:000200 | by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md | Completion:92 | Confidence:94
void EPFTileContext::NormalizePostDecodePixels()
{
    if (!g_surfaceUsesRgb565Pixels) {
        ConvertRgb565ToRgb555Pixels(
            static_cast<unsigned short*>(pixelData),
            (bounds.right - bounds.left) * (bounds.bottom - bounds.top));
    }
}

// UID:000201 | by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md | Completion:89 | Confidence:92
bool EPFTileContext::ContainsIndexedPixelInRanges(const DLPalette *palette) const
{
    if (pixelFormat == kEPFTilePixelFormatRgb16) {
        return false;
    }

    const int rowCount = bounds.bottom - bounds.top;
    const int pixelsPerRow = rowStridePixels;
    const unsigned char *rowPixels = static_cast<const unsigned char *>(pixelData);
    const DLPaletteRange *ranges = palette->m_paletteRanges;
    const int rangeCount = palette->m_paletteRangeCount;

    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < pixelsPerRow; ++column) {
            const unsigned char pixel = rowPixels[column];

            for (int rangeIndex = 0; rangeIndex < rangeCount; ++rangeIndex) {
                const unsigned char rangeStart = ranges[rangeIndex].firstIndex;
                const unsigned char rangeEnd = ranges[rangeIndex].lastIndex;

                if (rangeStart <= pixel && pixel <= rangeEnd) {
                    return true;
                }
            }
        }

        rowPixels += pixelsPerRow;
    }

    return false;
}
