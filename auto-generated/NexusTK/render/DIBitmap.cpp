// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IV
// Source by-file doc: by-file/DIBitmap.md
// UID:00003V | by-class/DIBitmap.md | Completion:92 | Confidence:94
class DIBitmap : public LObject
{
public:
    DIBitmap(HDC hdc, int width, int height);
    virtual ~DIBitmap();

    void *GetBits() const;
    HBITMAP GetBitmapHandle() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetAlignedWidth() const;

private:
    BITMAPINFOHEADER m_bmiHeader;
    HBITMAP m_hBitmap;
    void *m_pBits;
    int m_width;
    int m_height;
};
// UID:000313 | by-memory/0x004a1600-0x004a1738.DIBitmapConstructor.md | Completion:93 | Confidence:94
DIBitmap::DIBitmap(HDC hdc, int width, int height)
    : LObject()
{
    m_pBits = NULL;

    const int bitmapInfoByteCount =
        sizeof(BITMAPINFOHEADER) + 2 * width * height;
    unsigned char *bitmapInfoBytes =
        new unsigned char[bitmapInfoByteCount];

    BITMAPINFOHEADER bitmapHeader;
    bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapHeader.biPlanes = 1;
    bitmapHeader.biBitCount = 16;
    bitmapHeader.biCompression = BI_RGB;
    bitmapHeader.biSizeImage = 0;
    bitmapHeader.biXPelsPerMeter = 0x1710;
    bitmapHeader.biYPelsPerMeter = 0x1710;
    bitmapHeader.biClrUsed = 0;
    bitmapHeader.biClrImportant = 0;

    memset(bitmapInfoBytes, 0, bitmapInfoByteCount);

    bitmapHeader.biWidth =
        width + (width % 4 != 0 ? 4 - width % 4 : 0);
    bitmapHeader.biHeight = -height;

    BITMAPINFO *bitmapInfo =
        reinterpret_cast<BITMAPINFO *>(bitmapInfoBytes);
    bitmapInfo->bmiHeader = bitmapHeader;
    m_bmiHeader = bitmapHeader;

    m_hBitmap = CreateDIBSection(
        hdc,
        bitmapInfo,
        DIB_RGB_COLORS,
        &m_pBits,
        NULL,
        0);
    m_width = width;
    m_height = height;

    delete [] bitmapInfoBytes;
}

// UID:000136 | by-memory/0x004a1740-0x004a17ad.DIBitmapDestructorAndAccessors.md | Completion:90 | Confidence:93
DIBitmap::~DIBitmap()
{
    if (m_hBitmap != NULL) {
        DeleteObject(m_hBitmap);
    }
}

void *DIBitmap::GetBits() const
{
    return m_pBits;
}

HBITMAP DIBitmap::GetBitmapHandle() const
{
    return m_hBitmap;
}

int DIBitmap::GetWidth() const
{
    if (m_pBits == NULL) {
        return 0;
    }

    return m_width;
}

int DIBitmap::GetHeight() const
{
    if (m_pBits == NULL) {
        return 0;
    }

    return m_height;
}

int DIBitmap::GetAlignedWidth() const
{
    if (m_pBits == NULL) {
        return 0;
    }

    return m_bmiHeader.biWidth;
}

// UID:000316 | by-memory/0x004a1b10-0x004a1b5e.DIBitmapScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated scalar deleting destructor for DIBitmap.
// Regenerated from the source-declared virtual ~DIBitmap() and project delete path.
// Do not hand-port the flag-tested wrapper, vtable stores, base cleanup, or allocator calls.

// UID:0002MC | by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md | Completion:90 | Confidence:94
// Compiler-generated DIBitmap RTTI/vtable data.
// Regenerated from DIBitmap inheritance, its virtual destructor, and inherited LObject virtuals.
// Do not hand-emit the 0x00618e50-0x00618e60 binary table as source data.

// UID:0001U6 | by-type/by-struct/DIBitmapLayout.md | Completion:92 | Confidence:94
// Exact DIBitmap layout is emitted by the canonical class declaration [UID:00003V][DIBitmap](by-class/DIBitmap.md).
// Do not emit a duplicate class or standalone mirror structure from this support page.

// UID:0003HO | by-type\by-vtable\DIBitmapVtable.md | Completion:88 | Confidence:93 | Empty Emitter Marker
