// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K3
// Source by-file doc: by-file/ImageLoaders.md
// UID:0002ZF | by-global/ImageDecodeJpegEoiMarker.md | Completion:90 | Confidence:93
static unsigned char s_jpegEoiMarker[2] = { 0xff, 0xd9 };

// UID:0000U9 | by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md | Completion:86 | Confidence:91
// Emitted code for CreateDIBitmapFromPcxBuffer is covered by [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md).

// UID:0000UD | by-item/DecodePcxToRgb565Buffer_00549410.md | Completion:85 | Confidence:90
// Emitted code for DecodePcxToRgb565Buffer is covered by [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md).

// UID:0000UZ | by-item/LoadPcxImage_004A17B0.md | Completion:87 | Confidence:90
// Emitted code for LoadPcxImage is covered by [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md).

// UID:000314 | by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md | Completion:88 | Confidence:90
DIBitmap *LoadPcxImage(HDC hdc, const char *fileName, int transparentIndex)
{
    NtkString localName(fileName);
    NtkWideString archiveName(localName);

    if (!HasDATEntry(archiveName.c_str())) {
        return nullptr;
    }

    DATFileBuffer fileBuffer;
    fileBuffer.Open(archiveName.c_str());

    char *pcxBytes = static_cast<char *>(fileBuffer.GetBytes());
    const int pcxByteCount = fileBuffer.GetByteCount();
    fileBuffer.CloseRead();

    DIBitmap *bitmap = nullptr;
    if (pcxBytes != nullptr) {
        bitmap = CreateDIBitmapFromPcxBuffer(
            hdc,
            pcxBytes,
            pcxByteCount,
            transparentIndex);
    }

    return bitmap;
}

// UID:000315 | by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md | Completion:91 | Confidence:93
DIBitmap *CreateDIBitmapFromPcxBuffer(
    HDC hdc,
    char *pcxBytes,
    int pcxByteCount,
    int transparentIndex)
{
    unsigned short *decodedPixels = nullptr;
    int width = 0;
    int height = 0;

    if (DecodePcxToRgb565Buffer(
            pcxBytes,
            pcxByteCount,
            &decodedPixels,
            &width,
            &height,
            transparentIndex,
            nullptr) < 0 ||
        width <= 0 ||
        height <= 0 ||
        decodedPixels == nullptr) {
        return nullptr;
    }

    DIBitmap *bitmap = new DIBitmap(hdc, width, height);
    if (bitmap == nullptr || bitmap->GetBits() == nullptr) {
        delete bitmap;
        free(decodedPixels);
        return nullptr;
    }

    const int copyWidth = bitmap->GetWidth() < width ? bitmap->GetWidth() : width;
    const int copyHeight = bitmap->GetHeight() < height ? bitmap->GetHeight() : height;

    unsigned char *dst = static_cast<unsigned char *>(bitmap->GetBits());
    for (int row = 0; row < copyHeight; ++row) {
        memmove(
            dst,
            decodedPixels + width * row,
            2 * copyWidth);
        dst += 2 * bitmap->GetAlignedWidth();
    }

    free(decodedPixels);
    return bitmap;
}

// UID:0002TJ | by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md | Completion:88 | Confidence:89
void DecodeZpfFpfToTileContext(
    const unsigned char *zpfBuffer,
    unsigned int zpfBufferSize,
    EPFTileContext *destination)
{
    (void)zpfBufferSize;

    destination->ReleaseBuffers();

    if (strncmp(reinterpret_cast<const char *>(zpfBuffer), "ZPF", 4) != 0) {
        return;
    }

    const unsigned int zpfPayloadSize =
        *reinterpret_cast<const unsigned int *>(zpfBuffer + 4);

    _AUTOBUF<unsigned char> decompressedFpf;
    decompressedFpf.Resize(zpfPayloadSize);

    unsigned int decodedSize = zpfPayloadSize;
    Uncompress(
        decompressedFpf.data,
        &decodedSize,
        zpfBuffer + 8,
        zpfPayloadSize);

    const unsigned char *fpfBuffer = decompressedFpf.data;

    destination->ReleaseBuffers();

    if (*reinterpret_cast<const unsigned short *>(fpfBuffer + 4) != 1 ||
        strncmp(reinterpret_cast<const char *>(fpfBuffer), "FPF", 4) != 0) {
        return;
    }

    const unsigned int width =
        *reinterpret_cast<const unsigned short *>(fpfBuffer + 0x10);
    const unsigned int height =
        *reinterpret_cast<const unsigned short *>(fpfBuffer + 0x12);
    destination->AllocateRgb16Pixels(width, height);

    const unsigned int pixelOffset =
        *reinterpret_cast<const unsigned int *>(fpfBuffer + 0x18);
    memmove(
        destination->pixelData,
        fpfBuffer + pixelOffset,
        2 * (destination->bounds.right - destination->bounds.left) *
            (destination->bounds.bottom - destination->bounds.top));

    destination->NormalizePostDecodePixels();
}

// UID:000175 | by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md | Completion:88 | Confidence:89
// This aggregate is an index over exact ImageLoaders wrapper children. Emitted
// bodies are carried by [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md), [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md), [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md), [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md),
// [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md), [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md), and [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md).

// UID:0002TK | by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md | Completion:88 | Confidence:90
void DecodeFpfToTileContext(const unsigned char *fpfBuffer, EPFTileContext *destination)
{
    destination->ReleaseBuffers();

    if (*reinterpret_cast<const unsigned short *>(fpfBuffer + 0x04) != 1) {
        return;
    }

    if (strncmp(reinterpret_cast<const char *>(fpfBuffer), "FPF", 4) != 0) {
        return;
    }

    const unsigned int width =
        *reinterpret_cast<const unsigned short *>(fpfBuffer + 0x10);
    const unsigned int height =
        *reinterpret_cast<const unsigned short *>(fpfBuffer + 0x12);
    destination->AllocateRgb16Pixels(width, height);

    const unsigned int pixelOffset =
        *reinterpret_cast<const unsigned int *>(fpfBuffer + 0x18);
    const unsigned int pixelBytes =
        2 * (destination->bounds.right - destination->bounds.left) *
            (destination->bounds.bottom - destination->bounds.top);

    memmove(destination->pixelData, fpfBuffer + pixelOffset, pixelBytes);
    destination->NormalizePostDecodePixels();
}

// UID:0002TL | by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md | Completion:88 | Confidence:89
static unsigned short PackRgb888ToRgb565(
    unsigned char red,
    unsigned char green,
    unsigned char blue)
{
    return static_cast<unsigned short>(
        (blue >> 3) |
        ((green & 0xfc) << 3) |
        ((red & 0xf8) << 8));
}

static void DecodeJpegMemoryToTileContext(
    const unsigned char *jpegData,
    int jpegDataSize,
    EPFTileContext *destination)
{
    jpeg_decompress_struct cinfo;
    JpegErrorManager errorManager;

    cinfo.err = jpeg_std_error(&errorManager.pub);
    errorManager.pub.error_exit = JpegErrorExit;

    if (setjmp(errorManager.setjmpBuffer) != 0) {
        jpeg_destroy_decompress(&cinfo);
        return;
    }

    jpeg_create_decompress(&cinfo);
    jpeg_mem_src(&cinfo, jpegData, jpegDataSize);
    jpeg_read_header(&cinfo, TRUE);
    cinfo.out_color_space = JCS_RGB;
    jpeg_start_decompress(&cinfo);

    const int width = static_cast<int>(cinfo.output_width);
    const int height = static_cast<int>(cinfo.output_height);
    destination->AllocateRgb16Pixels(width, height);

    unsigned short *dst = static_cast<unsigned short *>(destination->pixelData);
    const int rowStride = 3 * width;
    JSAMPARRAY scanline = (*cinfo.mem->alloc_sarray)(
        reinterpret_cast<j_common_ptr>(&cinfo),
        JPOOL_IMAGE,
        rowStride,
        1);

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, scanline, 1);
        const unsigned char *src = scanline[0];
        for (int x = 0; x < width; ++x) {
            *dst++ = PackRgb888ToRgb565(src[0], src[1], src[2]);
            src += 3;
        }
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    destination->NormalizePostDecodePixels();
}

void DecodeJpfImageToTileContext(
    const unsigned char *jpfData,
    int jpfDataSize,
    EPFTileContext *destination)
{
    if (strncmp(reinterpret_cast<const char *>(jpfData), "JPF", 4) != 0) {
        return;
    }

    DecodeJpegMemoryToTileContext(jpfData + 4, jpfDataSize, destination);
}

// UID:0002TM | by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md | Completion:88 | Confidence:90
#pragma pack(push, 1)
struct BmpFileHeader {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int bitsOffset;
};

struct BmpInfoHeader {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
};
#pragma pack(pop)

void Decode8BitBmpToTileContext(
    const unsigned char *bmpData,
    int bmpDataSize,
    EPFTileContext *destination,
    DLPalette *palette)
{
    (void)bmpDataSize;

    destination->ReleaseBuffers();
    palette->FreePaletteData();

    const BmpFileHeader *fileHeader =
        reinterpret_cast<const BmpFileHeader *>(bmpData);
    if (fileHeader->type != 0x4d42) {
        return;
    }

    const BmpInfoHeader *infoHeader =
        reinterpret_cast<const BmpInfoHeader *>(bmpData + sizeof(BmpFileHeader));
    if (infoHeader->bitCount != 8) {
        return;
    }

    const int width = infoHeader->width;
    const int signedHeight = infoHeader->height;
    const int height = signedHeight < 0 ? -signedHeight : signedHeight;

    destination->pixelFormat = kEPFTilePixelFormatIndexed8;
    destination->AllocateIndexed8Pixels(width, height);

    const unsigned char *paletteData =
        bmpData + sizeof(BmpFileHeader) + infoHeader->size;
    palette->LoadFromRawRGBA(paletteData);

    const unsigned char *sourcePixels = bmpData + fileHeader->bitsOffset;
    unsigned char *destinationPixels =
        static_cast<unsigned char *>(destination->pixelData);

    if (signedHeight < 0) {
        memmove(destinationPixels, sourcePixels, width * height);
        return;
    }

    for (int row = 0; row < height; ++row) {
        memmove(
            destinationPixels + width * (height - row - 1),
            sourcePixels,
            width);
        sourcePixels += width;
    }
}

// UID:0002TN | by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md | Completion:88 | Confidence:89
void DecodeJpegBufferToTileContext(
    const unsigned char *jpegData,
    int jpegDataSize,
    EPFTileContext *destination)
{
    DecodeJpegMemoryToTileContext(jpegData, jpegDataSize, destination);
}

// UID:00032P | by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md | Completion:88 | Confidence:89
static void CopyRgba32ToRgb565AndAlpha(
    const unsigned char *rgba,
    unsigned int width,
    unsigned int height,
    EPFTileContext *destination)
{
    destination->AllocateRgb16PixelsWithAlpha(width, height);

    unsigned short *dstPixels =
        static_cast<unsigned short *>(destination->pixelData);
    unsigned short *dstAlpha = destination->alphaData;

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            const unsigned int pixel = x + width * y;
            const unsigned char red = rgba[4 * pixel + 0];
            const unsigned char green = rgba[4 * pixel + 1];
            const unsigned char blue = rgba[4 * pixel + 2];
            const unsigned char alpha = rgba[4 * pixel + 3];

            *dstPixels++ = static_cast<unsigned short>(
                (blue >> 3) |
                ((green & 0xfc) << 3) |
                ((red & 0xf8) << 8));
            *dstAlpha++ = static_cast<unsigned short>(
                32 - static_cast<unsigned int>((static_cast<float>(alpha) / 255.0f) * 32.0f));
        }
    }
}

void __stdcall DecodePngFileToTileContext(
    const char *fileName,
    EPFTileContext *destination)
{
    unsigned char *rgba = nullptr;
    unsigned int width = 0;
    unsigned int height = 0;

    lodepng_decode32_file(&rgba, &width, &height, fileName);
    CopyRgba32ToRgb565AndAlpha(rgba, width, height, destination);

    free(rgba);
    destination->NormalizePostDecodePixels();
}

// UID:00032O | by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md | Completion:88 | Confidence:89
int __stdcall DecodePngResourceToTileContext(
    const wchar_t *resourceName,
    EPFTileContext *destination)
{
    DATFileBuffer fileBuffer;
    fileBuffer.Open(resourceName);

    const int byteCount = fileBuffer.GetByteCount();
    unsigned char *fileBytes =
        static_cast<unsigned char *>(NtkAlloc(byteCount));
    fileBuffer.Read(fileBytes, byteCount);

    unsigned char *rgba = nullptr;
    unsigned int width = 0;
    unsigned int height = 0;

    if (lodepng_decode32(&rgba, &width, &height, fileBytes, byteCount) == 0) {
        CopyRgba32ToRgb565AndAlpha(rgba, width, height, destination);
    }

    NtkFree(fileBytes);
    free(rgba);
    destination->NormalizePostDecodePixels();
    return fileBuffer.Close();
}

// UID:0004DP | by-memory/0x004e7030-0x004e7094.InitializeJpegSourceManagerRecord.md | Completion:87 | Confidence:91
// InitializeJpegSourceManagerRecord is ImageLoaders JPEG wrapper source
// setup for the product-side source-manager record. Final body C++ waits for
// accepted callback-record type names; LibJPEG owns jpeg_resync_to_restart,
// but not this product initializer.

// UID:0001F1 | by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md | Completion:89 | Confidence:91
#pragma pack(push, 1)
struct PcxHeader {
    unsigned char manufacturer;
    unsigned char version;
    unsigned char encoding;
    unsigned char bitsPerPixel;
    unsigned short xMin;
    unsigned short yMin;
    unsigned short xMax;
    unsigned short yMax;
    unsigned char reserved[112];
};
#pragma pack(pop)

int DecodePcxToRgb565Buffer(
    char *pcxBytes,
    int pcxByteCount,
    unsigned short **outPixels,
    int *outWidth,
    int *outHeight,
    int transparentIndex,
    const unsigned char *remapTable)
{
    if (*outPixels != nullptr) {
        return -1;
    }

    if (pcxBytes[pcxByteCount - 769] != 0x0c) {
        return -1;
    }

    const PcxHeader *header = reinterpret_cast<const PcxHeader *>(pcxBytes);
    if (header->bitsPerPixel != 8) {
        return -1;
    }

    *outWidth = header->xMax - header->xMin + 1;
    *outHeight = header->yMax - header->yMin + 1;

    const int totalPixels = *outWidth * *outHeight;
    *outPixels = static_cast<unsigned short *>(malloc(2 * totalPixels));
    if (*outPixels == nullptr) {
        return -1;
    }

    const unsigned char *rle = reinterpret_cast<unsigned char *>(pcxBytes + 128);
    const unsigned char *palette =
        reinterpret_cast<unsigned char *>(pcxBytes + pcxByteCount - 768);
    const int encodedRowWidth = *outWidth + (*outWidth & 1);

    int outputIndex = 0;
    int column = 1;
    int runLength = 0;
    unsigned char value = 0;

    while (outputIndex < totalPixels) {
        if (runLength <= 0) {
            value = *rle++;
            runLength = 1;
            if ((value & 0xc0) == 0xc0) {
                runLength = value & 0x3f;
                value = *rle++;
            }
            continue;
        }

        unsigned char paletteIndex = value;
        if (remapTable != nullptr) {
            paletteIndex = remapTable[4 * paletteIndex];
        }

        const bool paddingColumn = ((*outWidth & 1) != 0 && column == encodedRowWidth);
        if (!paddingColumn) {
            if (transparentIndex >= 0 && transparentIndex == paletteIndex) {
                (*outPixels)[outputIndex] = 0;
            } else {
                const unsigned char red = palette[3 * paletteIndex + 0];
                const unsigned char green = palette[3 * paletteIndex + 1];
                const unsigned char blue = palette[3 * paletteIndex + 2];
                (*outPixels)[outputIndex] =
                    static_cast<unsigned short>(
                        (blue >> 3) |
                        ((green & 0xfc) << 3) |
                        ((red & 0xf8) << 8));
            }
            ++outputIndex;
        }

        --runLength;
        ++column;
        if (column > encodedRowWidth) {
            column = 1;
        }
    }

    return 0;
}

// UID:00027L | by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md | Completion:88 | Confidence:92
// Exact storage for [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md) ImageDecodeJpegEoiMarker is emitted by the
// by-global declaration. The two trailing zero bytes are storage/alignment
// bytes and are not a separate source object.
