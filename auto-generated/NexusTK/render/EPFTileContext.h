// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J4
// Source by-file doc: by-file/EPFTileContext.md
// UID:00004I | by-class/EPFTileContext.md | Completion:94 | Confidence:94
#pragma once

#include "../ui/core/RectBounds.h"

enum EPFTilePixelFormat
{
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};

struct DLPalette;

struct EPFTileContext
{
    EPFTilePixelFormat pixelFormat;
    void *pixelData;
    unsigned short *alphaData;
    int rowStridePixels;
    RectBounds bounds;
    int encodedMaskByteCount;
    unsigned char *encodedMaskBytes;

    EPFTileContext();

    void ReleaseBuffers();
    void BuildEncodedMask();
    void CopyTo(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleCopy() const;
    void AllocateIndexed8Pixels(int width, int height);
    void AllocateRgb16Pixels(int width, int height);
    void AllocateRgb16PixelsWithAlpha(int width, int height);
    void NormalizePostDecodePixels();
    bool ContainsIndexedPixelInRanges(const DLPalette *palette) const;

private:
    void BuildEncodedMask16();
    void CopyRgb16To(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleRgb16Copy() const;
};
