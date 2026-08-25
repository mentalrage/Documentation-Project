// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K4
// Source by-file doc: by-file/ImageWriters.md
// UID:0002ZG | by-global/JpegScreenshotEoiMarker.md | Completion:92 | Confidence:94
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "jpeglib.h"

static JOCTET s_jpegEoiMarker[2] = { 0xff, JPEG_EOI };

// UID:00018N | by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md | Completion:92 | Confidence:94
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "jpeglib.h"

struct JpegScreenshotErrorManager
{
    jpeg_error_mgr pub;
    jmp_buf setjmpBuffer;
};

struct JpegMemorySourceManager
{
    jpeg_source_mgr pub;
    const JOCTET *sourceBytes;
    size_t sourceByteCount;
    boolean sourceLoaded;
};

static void JpegMemorySourceInit(j_decompress_ptr cinfo);
static boolean JpegMemorySourceFill(j_decompress_ptr cinfo);
static void JpegMemorySourceSkip(j_decompress_ptr cinfo, long byteCount);
static void JpegMemorySourceTerm(j_decompress_ptr cinfo);
static void JpegScreenshotErrorExit(j_common_ptr cinfo);

int WriteJpegFileFromRgb565Surface(
    const unsigned short *pixels,
    int width,
    unsigned int height,
    bool usesRgb565,
    FILE *output)
{
    jpeg_compress_struct cinfo;
    JpegScreenshotErrorManager errorManager;
    JSAMPLE *rgbBuffer = 0;

    cinfo.err = jpeg_std_error(&errorManager.pub);
    errorManager.pub.error_exit = JpegScreenshotErrorExit;
    errorManager.pub.output_message = 0;

    if (setjmp(errorManager.setjmpBuffer) != 0) {
        jpeg_destroy_compress(&cinfo);
        if (rgbBuffer != 0) {
            free(rgbBuffer);
        }
        return -1;
    }

    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, output);
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    const int pixelCount = width * static_cast<int>(height);
    rgbBuffer = static_cast<JSAMPLE *>(malloc(3 * pixelCount));

    if (usesRgb565) {
        for (int i = 0; i < pixelCount; ++i) {
            const unsigned int pixel = pixels[i];
            JSAMPLE *out = rgbBuffer + (3 * i);
            out[0] = static_cast<JSAMPLE>((pixel >> 8) & 0xf8);
            out[1] = static_cast<JSAMPLE>((pixel >> 3) & 0xfc);
            out[2] = static_cast<JSAMPLE>(8 * pixel);
        }
    } else {
        for (int i = 0; i < pixelCount; ++i) {
            const unsigned int pixel = pixels[i];
            JSAMPLE *out = rgbBuffer + (3 * i);
            out[0] = static_cast<JSAMPLE>((pixel >> 7) & 0xf8);
            out[1] = static_cast<JSAMPLE>((pixel >> 2) & 0xf8);
            out[2] = static_cast<JSAMPLE>(8 * pixel);
        }
    }

    const int rowStride = 3 * width;
    while (cinfo.next_scanline < cinfo.image_height) {
        JSAMPROW row = rgbBuffer + (rowStride * cinfo.next_scanline);
        jpeg_write_scanlines(&cinfo, &row, 1);
    }

    free(rgbBuffer);
    rgbBuffer = 0;
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    return 0;
}

static void JpegMemorySourceInit(j_decompress_ptr)
{
}

static boolean JpegMemorySourceFill(j_decompress_ptr cinfo)
{
    JpegMemorySourceManager *source =
        reinterpret_cast<JpegMemorySourceManager *>(cinfo->src);

    if (source->sourceLoaded == FALSE) {
        source->sourceLoaded = TRUE;
        source->pub.next_input_byte = source->sourceBytes;
        source->pub.bytes_in_buffer = source->sourceByteCount;
    } else {
        source->pub.next_input_byte = s_jpegEoiMarker;
        source->pub.bytes_in_buffer = 2;
    }

    return TRUE;
}

static void JpegMemorySourceSkip(j_decompress_ptr cinfo, long byteCount)
{
    if (byteCount > 0) {
        cinfo->src->next_input_byte += byteCount;
        cinfo->src->bytes_in_buffer -= byteCount;
    }
}

static void JpegMemorySourceTerm(j_decompress_ptr)
{
}

static void JpegScreenshotErrorExit(j_common_ptr cinfo)
{
    JpegScreenshotErrorManager *errorManager =
        reinterpret_cast<JpegScreenshotErrorManager *>(cinfo->err);

    if (errorManager->pub.output_message != 0) {
        errorManager->pub.output_message(cinfo);
    }

    longjmp(errorManager->setjmpBuffer, 1);
}
