// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NT
// Source by-file doc: by-file/SoftwareBlend16.md
// UID:0000TW | by-item/AlphaBlendSpan16Blocks_00460B00.md | Completion:86 | Confidence:91
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TW].

// UID:0000TV | by-item/AlphaBlendSpan16_00460500.md | Completion:88 | Confidence:92
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TV].

// UID:0000TZ | by-item/BlendRgb555_004C0710.md | Completion:86 | Confidence:91
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TZ].

// UID:0000U0 | by-item/BlendRgb565Pair_004C60D0.md | Completion:88 | Confidence:90
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000U0].

// UID:0000U1 | by-item/BlendRgb565Pixel_004C6050.md | Completion:86 | Confidence:90
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000U1].

// UID:0000US | by-item/HalfBlendSpan16Blocks_00460C10.md | Completion:85 | Confidence:90
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000US].

// UID:0004BB | by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md | Completion:90 | Confidence:92
static void __cdecl BlitTransparentShadow555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlitTransparentShadow555(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        BlitTransparentShadow555Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x3def;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BC | by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md | Completion:90 | Confidence:92
static void __cdecl ApplyAlphaMap555Blocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl ApplyAlphaMap555(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        ApplyAlphaMap555Blocks(
            pixels,
            pixelPitchBytes,
            alphaBytes,
            alphaPitchBytes,
            blockCount4Pixels,
            rowCount);

        pixels += blockCount4Pixels * 4;
        alphaBytes += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];

            pixels[pixelIndex] = static_cast<unsigned short>(
                (((alpha * (pixel & 0x7c1f)) >> 5) & 0x7c1f) |
                (((alpha * (pixel & 0x03e0)) >> 5) & 0x03e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}

// UID:0004BD | by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md | Completion:90 | Confidence:92
static void __cdecl BlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlendRgb555Span(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount)
{
    const unsigned char alpha = static_cast<unsigned char>(alpha32);
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (alpha == 16) {
        if (blockCount4Pixels > 0) {
            HalfBlendRgb555Blocks(
                sourcePixels,
                sourcePitchBytes,
                destinationPixels,
                destinationPitchBytes,
                blockCount4Pixels,
                rowCount);

            sourcePixels += blockCount4Pixels * 4;
            destinationPixels += blockCount4Pixels * 4;
        }

        while (rowCount-- > 0) {
            for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
                const unsigned int source = sourcePixels[pixelIndex];
                const unsigned int destination = destinationPixels[pixelIndex];
                destinationPixels[pixelIndex] = static_cast<unsigned short>(
                    ((source >> 1) & 0x3def) +
                    ((destination >> 1) & 0x3def) +
                    (source & destination & 0x0421));
            }

            sourcePixels = reinterpret_cast<const unsigned short*>(
                reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
            destinationPixels = reinterpret_cast<unsigned short*>(
                reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
        }

        return;
    }

    if (blockCount4Pixels > 0) {
        BlendRgb555Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            static_cast<unsigned char>(32 - alpha),
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);
    const unsigned int destinationWeight32 = alpha;

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight32 * (source & 0x7c1f) +
                   destinationWeight32 * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight32 * (source & 0x03e0) +
                   destinationWeight32 * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BE | by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md | Completion:90 | Confidence:92
static void __cdecl BlendTransparentRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlendTransparentRgb555Span(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount)
{
    const unsigned char alpha = static_cast<unsigned char>(alpha32);
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        BlendTransparentRgb555Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            static_cast<unsigned char>(32 - alpha),
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);
    const unsigned int destinationWeight32 = alpha;

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight32 * (source & 0x7c1f) +
                   destinationWeight32 * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight32 * (source & 0x03e0) +
                   destinationWeight32 * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BF | by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md | Completion:88 | Confidence:91
static void __cdecl BlitTransparentShadow555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x3def;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BG | by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md | Completion:88 | Confidence:91
static void __cdecl BlendTransparentRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    const unsigned int sourceWeight = sourceWeight32;
    const unsigned int destinationWeight = static_cast<unsigned char>(32 - sourceWeight32);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight * (source & 0x7c1f) +
                   destinationWeight * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight * (source & 0x03e0) +
                   destinationWeight * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BH | by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md | Completion:88 | Confidence:91
static void __cdecl BlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    const unsigned int sourceWeight = sourceWeight32;
    const unsigned int destinationWeight = static_cast<unsigned char>(32 - sourceWeight32);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (((sourceWeight * (source & 0x7c1f) +
                   destinationWeight * (destination & 0x7c1f)) >> 5) & 0x7c1f) |
                (((sourceWeight * (source & 0x03e0) +
                   destinationWeight * (destination & 0x03e0)) >> 5) & 0x03e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BI | by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md | Completion:88 | Confidence:91
static void __cdecl HalfBlendRgb555Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];
            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                ((source >> 1) & 0x3def) +
                ((destination >> 1) & 0x3def) +
                (source & destination & 0x0421));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BJ | by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md | Completion:88 | Confidence:91
static void __cdecl ApplyAlphaMap555Blocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];
            pixels[pixelIndex] = static_cast<unsigned short>(
                (((alpha * (pixel & 0x7c1f)) >> 5) & 0x7c1f) |
                (((alpha * (pixel & 0x03e0)) >> 5) & 0x03e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}

// UID:0004BK | by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md | Completion:90 | Confidence:92
static void __cdecl BlitTransparentShadow565MmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl BlitTransparentShadow565(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        BlitTransparentShadow565MmxBlocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            if (source == 1) {
                source = (destinationPixels[pixelIndex] >> 1) & 0x7bef;
            }

            destinationPixels[pixelIndex] = static_cast<unsigned short>(source);
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0004BL | by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md | Completion:90 | Confidence:92
static void __cdecl Rgb565AlphaMapMmxBlocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl ApplyAlphaMap565(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        Rgb565AlphaMapMmxBlocks(
            pixels,
            pixelPitchBytes,
            alphaBytes,
            alphaPitchBytes,
            blockCount4Pixels,
            rowCount);

        pixels += blockCount4Pixels * 4;
        alphaBytes += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];
            const unsigned int redBlue = (alpha * (pixel & 0xf81f)) >> 5;
            const unsigned int green = (alpha * (pixel & 0x07e0)) >> 5;

            pixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}

// UID:0000YE | by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md | Completion:90 | Confidence:92
static void __cdecl AlphaBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

void __cdecl AlphaBlendSpan16(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount)
{
    const unsigned char alpha = static_cast<unsigned char>(alpha32);
    const int blockCount4Pixels = widthPixels / 4;
    int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (alpha == 16) {
        if (blockCount4Pixels > 0) {
            HalfBlendSpan16Blocks(
                sourcePixels,
                sourcePitchBytes,
                destinationPixels,
                destinationPitchBytes,
                blockCount4Pixels,
                rowCount);

            sourcePixels += blockCount4Pixels * 4;
            destinationPixels += blockCount4Pixels * 4;
        }

        while (rowCount-- > 0) {
            for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
                const unsigned int source = sourcePixels[pixelIndex];
                const unsigned int destination = destinationPixels[pixelIndex];

                destinationPixels[pixelIndex] = static_cast<unsigned short>(
                    ((source >> 1) & 0x7bef) +
                    ((destination >> 1) & 0x7bef) +
                    (source & destination & 0x0821));
            }

            sourcePixels = reinterpret_cast<const unsigned short*>(
                reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
            destinationPixels = reinterpret_cast<unsigned short*>(
                reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
        }

        return;
    }

    if (blockCount4Pixels > 0) {
        AlphaBlendSpan16Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            static_cast<unsigned char>(32 - alpha),
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    const unsigned int destinationWeight32 = alpha;
    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];

            const unsigned int redBlue =
                (sourceWeight32 * (source & 0xf81f) +
                 destinationWeight32 * (destination & 0xf81f)) >> 5;
            const unsigned int green =
                (sourceWeight32 * (source & 0x07e0) +
                 destinationWeight32 * (destination & 0x07e0)) >> 5;

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:000206 | by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md | Completion:88 | Confidence:90
static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl HalfBlendSpan16(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int widthPixels,
    int rowCount)
{
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        HalfBlendSpan16Blocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                ((source >> 1) & 0x7bef) +
                ((destination >> 1) & 0x7bef) +
                (source & destination & 0x0821));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:000207 | by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md | Completion:88 | Confidence:90
static void __cdecl Rgb565TransparentAlphaBlendMmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl Rgb565TransparentAlphaBlendSpan(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned int alpha32,
    int widthPixels,
    int rowCount)
{
    const unsigned char alpha = static_cast<unsigned char>(alpha32);
    const int blockCount4Pixels = widthPixels / 4;
    const int tailPixels = widthPixels - blockCount4Pixels * 4;

    if (blockCount4Pixels > 0) {
        Rgb565TransparentAlphaBlendMmxBlocks(
            sourcePixels,
            sourcePitchBytes,
            destinationPixels,
            destinationPitchBytes,
            static_cast<unsigned char>(32 - alpha),
            blockCount4Pixels,
            rowCount);

        sourcePixels += blockCount4Pixels * 4;
        destinationPixels += blockCount4Pixels * 4;
    }

    const unsigned int sourceWeight32 = static_cast<unsigned char>(32 - alpha);
    const unsigned int destinationWeight32 = alpha;

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < tailPixels; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            const unsigned int redBlue =
                (sourceWeight32 * (source & 0xf81f) +
                 destinationWeight32 * (destination & 0xf81f)) >> 5;
            const unsigned int green =
                (sourceWeight32 * (source & 0x07e0) +
                 destinationWeight32 * (destination & 0x07e0)) >> 5;

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:000208 | by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md | Completion:88 | Confidence:91
static void __cdecl BlitTransparentShadow565MmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    unsigned __int64 shadowMask = 0xf7def7def7def7deui64;
    unsigned __int64 sentinelOne = 0x0001000100010001ui64;
    const unsigned char* sourceRow = (const unsigned char*)sourcePixels;
    unsigned char* destinationRow = (unsigned char*)destinationPixels;
    int blockBytes = blockCount4Pixels << 3;

    __asm {
        pushad
        pxor mm3, mm3
        movq mm4, qword ptr [shadowMask]
        movq mm7, qword ptr [sentinelOne]
        mov eax, sourceRow
        mov ebx, destinationRow
        mov ecx, rowCount

    rowLoop:
        test ecx, ecx
        jz shadowDone
        mov esi, eax
        mov edi, ebx
        mov edx, blockBytes
        add edx, edi

    blockLoop:
        cmp edx, edi
        jbe nextRow

        movq mm0, qword ptr [esi]
        movq mm1, qword ptr [edi]

        movq mm5, mm0
        pcmpeqw mm5, mm3

        movq mm6, mm0
        pcmpeqw mm6, mm7

        movq mm2, mm6
        pandn mm2, mm0

        movq mm0, mm1
        pand mm0, mm4
        psrlw mm0, 1
        pand mm0, mm6

        movq mm6, mm5
        pandn mm6, mm2

        movq mm2, mm5
        pandn mm2, mm0
        por mm6, mm2

        pand mm1, mm5
        por mm6, mm1

        movq qword ptr [edi], mm6
        add esi, 8
        add edi, 8
        jmp blockLoop

    nextRow:
        add eax, sourcePitchBytes
        add ebx, destinationPitchBytes
        dec ecx
        jmp rowLoop

    shadowDone:
        popad
        emms
    }
}

// UID:000209 | by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md | Completion:88 | Confidence:91
static void __cdecl Rgb565TransparentAlphaBlendMmxBlocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    const unsigned int sourceWeight = sourceWeight32;
    const unsigned int destinationWeight = static_cast<unsigned char>(32 - sourceWeight32);

    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            if (source == 0) {
                continue;
            }

            const unsigned int destination = destinationPixels[pixelIndex];
            const unsigned int redBlue =
                (sourceWeight * (source & 0xf81f) +
                 destinationWeight * (destination & 0xf81f)) >> 5;
            const unsigned int green =
                (sourceWeight * (source & 0x07e0) +
                 destinationWeight * (destination & 0x07e0)) >> 5;

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:0000YF | by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md | Completion:88 | Confidence:91
static void __cdecl AlphaBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    unsigned char sourceWeight32,
    int blockCount4Pixels,
    int rowCount)
{
    unsigned int sourceWeightWord = sourceWeight32;
    sourceWeightWord |= sourceWeightWord << 16;

    unsigned int inverseWeightWord = (unsigned char)(32 - sourceWeight32);
    inverseWeightWord |= inverseWeightWord << 16;

    unsigned __int64 sourceWeightVector =
        ((unsigned __int64)sourceWeightWord << 32) | sourceWeightWord;
    unsigned __int64 inverseWeightVector =
        ((unsigned __int64)inverseWeightWord << 32) | inverseWeightWord;
    unsigned __int64 rgb565RedBlueMask = 0x001f001f001f001fui64;
    unsigned __int64 rgb565GreenMask = 0x07e007e007e007e0ui64;
    const unsigned char* sourceRow = (const unsigned char*)sourcePixels;
    unsigned char* destinationRow = (unsigned char*)destinationPixels;
    int blockBytes = blockCount4Pixels << 3;

    __asm {
        pushad
        movq mm2, qword ptr [sourceWeightVector]
        movq mm3, qword ptr [inverseWeightVector]
        movq mm4, qword ptr [rgb565RedBlueMask]
        movq mm5, qword ptr [rgb565GreenMask]
        mov eax, sourceRow
        mov ebx, destinationRow
        mov ecx, rowCount

    rowLoop:
        test ecx, ecx
        jz blendDone
        mov esi, eax
        mov edi, ebx
        mov edx, blockBytes
        add edx, edi

    blockLoop:
        cmp edx, edi
        jbe nextRow
        movq mm0, qword ptr [esi]
        movq mm1, qword ptr [edi]
        movq mm7, mm0
        psrlw mm7, 11
        pmullw mm7, mm2
        psrlw mm7, 5
        psllw mm7, 11
        movq mm6, mm0
        pand mm6, mm5
        psrlw mm6, 5
        pmullw mm6, mm2
        pand mm6, mm5
        por mm7, mm6
        pand mm0, mm4
        pmullw mm0, mm2
        psrlw mm0, 5
        por mm0, mm7
        movq mm7, mm1
        psrlw mm7, 11
        pmullw mm7, mm3
        psrlw mm7, 5
        psllw mm7, 11
        movq mm6, mm1
        pand mm6, mm5
        psrlw mm6, 5
        pmullw mm6, mm3
        pand mm6, mm5
        por mm7, mm6
        pand mm1, mm4
        pmullw mm1, mm3
        psrlw mm1, 5
        por mm1, mm7
        paddw mm1, mm0
        movq qword ptr [edi], mm1
        add esi, 8
        add edi, 8
        jmp blockLoop

    nextRow:
        add eax, sourcePitchBytes
        add ebx, destinationPitchBytes
        dec ecx
        jmp rowLoop

    blendDone:
        popad
        emms
    }
}

// UID:0000YG | by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md | Completion:88 | Confidence:91
static void __cdecl HalfBlendSpan16Blocks(
    const unsigned short* sourcePixels,
    int sourcePitchBytes,
    unsigned short* destinationPixels,
    int destinationPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int source = sourcePixels[pixelIndex];
            const unsigned int destination = destinationPixels[pixelIndex];

            destinationPixels[pixelIndex] = static_cast<unsigned short>(
                ((source >> 1) & 0x7bef) +
                ((destination >> 1) & 0x7bef) +
                (source & destination & 0x0821));
        }

        sourcePixels = reinterpret_cast<const unsigned short*>(
            reinterpret_cast<const unsigned char*>(sourcePixels) + sourcePitchBytes);
        destinationPixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(destinationPixels) + destinationPitchBytes);
    }
}

// UID:00020A | by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md | Completion:88 | Confidence:91
static void __cdecl Rgb565AlphaMapMmxBlocks(
    unsigned short* pixels,
    int pixelPitchBytes,
    const unsigned char* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount)
{
    while (rowCount-- > 0) {
        for (int pixelIndex = 0; pixelIndex < blockCount4Pixels * 4; ++pixelIndex) {
            const unsigned int pixel = pixels[pixelIndex];
            const unsigned int alpha = alphaBytes[pixelIndex];

            const unsigned int redBlue =
                (alpha * (pixel & 0xf81f)) >> 5;
            const unsigned int green =
                (alpha * (pixel & 0x07e0)) >> 5;

            pixels[pixelIndex] = static_cast<unsigned short>(
                (redBlue & 0xf81f) | (green & 0x07e0));
        }

        pixels = reinterpret_cast<unsigned short*>(
            reinterpret_cast<unsigned char*>(pixels) + pixelPitchBytes);
        alphaBytes += alphaPitchBytes;
    }
}

// UID:00020B | by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md | Completion:88 | Confidence:90
static void __cdecl ByteSpanFill8Blocks(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int blockCount8Bytes,
    int rowCount);

static void __cdecl ByteSpanFillRows(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanFill8Blocks(
            destinationBytes,
            destinationPitchBytes,
            value,
            blockCount8Bytes,
            rowCount);

        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = value;
        }

        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020C | by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanCopy8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanCopyRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanCopy8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = sourceBytes[byteIndex];
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020D | by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanAdd8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanAddRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanAdd8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] + sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020E | by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanSubtract8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount);

void __cdecl ByteSpanSubtractRows(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount)
{
    const int blockCount8Bytes = widthBytes / 8;
    const int tailBytes = widthBytes - blockCount8Bytes * 8;

    if (blockCount8Bytes > 0) {
        ByteSpanSubtract8Blocks(
            sourceBytes,
            sourcePitchBytes,
            destinationBytes,
            destinationPitchBytes,
            blockCount8Bytes,
            rowCount);

        sourceBytes += blockCount8Bytes * 8;
        destinationBytes += blockCount8Bytes * 8;
    }

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < tailBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] - sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020F | by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanFill8Blocks(
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    unsigned char value,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = value;
        }

        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020G | by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanCopy8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = sourceBytes[byteIndex];
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020H | by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanAdd8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] + sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:00020I | by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md | Completion:88 | Confidence:91
static void __cdecl ByteSpanSubtract8Blocks(
    const unsigned char* sourceBytes,
    int sourcePitchBytes,
    unsigned char* destinationBytes,
    int destinationPitchBytes,
    int blockCount8Bytes,
    int rowCount)
{
    const int blockBytes = blockCount8Bytes * 8;

    while (rowCount-- > 0) {
        for (int byteIndex = 0; byteIndex < blockBytes; ++byteIndex) {
            destinationBytes[byteIndex] = static_cast<unsigned char>(
                destinationBytes[byteIndex] - sourceBytes[byteIndex]);
        }

        sourceBytes += sourcePitchBytes;
        destinationBytes += destinationPitchBytes;
    }
}

// UID:0003ZP | by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md | Completion:93 | Confidence:95
void ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount)
{
    for (; pixelCount != 0; --pixelCount) {
        const unsigned int pixel = *pixels;
        *pixels++ = static_cast<unsigned short>((pixel & 0x001f) | ((pixel >> 1) & 0x7ff0));
    }
}

// UID:00016K | by-memory/0x004c0710-0x004c076d.BlendRgb555.md | Completion:90 | Confidence:92
unsigned short __cdecl BlendRgb555(
    unsigned short firstPixel,
    unsigned short secondPixel,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int green =
        (firstWeight * (firstPixel & 0x03e0) +
         secondWeight * (secondPixel & 0x03e0)) >> 5;
    const unsigned int redBlue =
        (firstWeight * (firstPixel & 0x7c1f) +
         secondWeight * (secondPixel & 0x7c1f)) >> 5;

    return static_cast<unsigned short>((redBlue & 0x7c1f) | (green & 0x03e0));
}

// UID:00016M | by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md | Completion:90 | Confidence:92
unsigned short __cdecl BlendRgb565Pixel(
    unsigned short firstPixel,
    unsigned short secondPixel,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int redBlue =
        (firstWeight * (firstPixel & 0xf81f) +
         secondWeight * (secondPixel & 0xf81f)) >> 5;
    const unsigned int green =
        (firstWeight * (firstPixel & 0x07e0) +
         secondWeight * (secondPixel & 0x07e0)) >> 5;

    return static_cast<unsigned short>((redBlue & 0xf81f) | (green & 0x07e0));
}

// UID:00016N | by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md | Completion:90 | Confidence:92
unsigned int __cdecl BlendRgb565Pair(
    unsigned int firstPixels,
    unsigned int secondPixels,
    unsigned char firstWeight32)
{
    const unsigned int firstWeight = firstWeight32;
    const unsigned int secondWeight = static_cast<unsigned char>(32 - firstWeight32);

    const unsigned int firstLow = firstPixels & 0xffff;
    const unsigned int secondLow = secondPixels & 0xffff;
    const unsigned int lowRedBlue =
        (firstWeight * (firstLow & 0xf81f) +
         secondWeight * (secondLow & 0xf81f)) >> 5;
    const unsigned int lowGreen =
        (firstWeight * (firstLow & 0x07e0) +
         secondWeight * (secondLow & 0x07e0)) >> 5;
    const unsigned int lowPixel = (lowRedBlue & 0xf81f) | (lowGreen & 0x07e0);

    const unsigned int firstHigh = (firstPixels >> 16) & 0xffff;
    const unsigned int secondHigh = (secondPixels >> 16) & 0xffff;
    const unsigned int highRedBlue =
        (firstWeight * (firstHigh & 0xf81f) +
         secondWeight * (secondHigh & 0xf81f)) >> 5;
    const unsigned int highGreen =
        (firstWeight * (firstHigh & 0x07e0) +
         secondWeight * (secondHigh & 0x07e0)) >> 5;
    const unsigned int highPixel = (highRedBlue & 0xf81f) | (highGreen & 0x07e0);

    return lowPixel | (highPixel << 16);
}

// UID:0002OO | by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md | Completion:88 | Confidence:91
// Emitted source for this read-only MMX mask table is covered by the
// SoftwareBlend16 helper bodies that carry the masks as local constants or
// equivalent scalar immediates: [UID:0004BF][0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks](by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md), [UID:0004BG][0x0045fff0-0x00460111.BlendTransparentRgb555Blocks](by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md),
// [UID:0004BH][0x00460120-0x0046022f.BlendRgb555Blocks](by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md), [UID:0004BI][0x00460230-0x004602a2.HalfBlendRgb555Blocks](by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md), [UID:0004BJ][0x004602b0-0x0046036b.ApplyAlphaMap555Blocks](by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md), [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md),
// [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md), [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md), and [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md).
// No standalone file-scope data declaration is emitted for [UID:0002OO].

// UID:00028W | by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md | Completion:88 | Confidence:91
// Emitted source for this writable MMX weight scratch range is covered by the
// SoftwareBlend16 helper bodies that compute local source/inverse weight
// vectors: [UID:0004BG][0x0045fff0-0x00460111.BlendTransparentRgb555Blocks](by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md), [UID:0004BH][0x00460120-0x0046022f.BlendRgb555Blocks](by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md), [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), and [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md). No standalone
// file-scope data declaration is emitted for [UID:00028W].
