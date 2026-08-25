// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M2
// Source by-file doc: by-file/NumericStringControlPane.md
// UID:00009M | by-class/NumericStringControlPane.md | Completion:92 | Confidence:93
class NumericStringControlPane : public ControlPane
{
public:
    NumericStringControlPane(const wchar_t *text,
                             int alignment,
                             char colorVariant,
                             const RectBounds *bounds);
    virtual ~NumericStringControlPane();
    virtual void OnPaint();

private:
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > m_text;
    int m_alignment;
    char m_colorVariant;
    char *m_numericGlyphs;
};

// UID:00011L | by-memory/0x00499910-0x004999c1.NumericStringControlPaneConstructor.md | Completion:92 | Confidence:93
NumericStringControlPane::NumericStringControlPane(const wchar_t *text,
                                                   int alignment,
                                                   char colorVariant,
                                                   const RectBounds *bounds)
    : ControlPane(8, bounds)
{
    m_text.AssignWideLiteral(text);
    m_alignment = alignment;
    m_colorVariant = colorVariant;

    int glyphBufferSize;
    m_numericGlyphs =
        LoadDatFileBuffer(L"9X11FONT.BIN", 99, &glyphBufferSize);
}

// UID:00011N | by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md | Completion:90 | Confidence:92
NumericStringControlPane::~NumericStringControlPane()
{
    if (m_numericGlyphs != NULL) {
        m_numericGlyphs = static_cast<char *>(GetMemoryMan()->FreeBufferMemory(m_numericGlyphs));
    }
}

// UID:00011O | by-memory/0x00499a50-0x00499be7.NumericStringControlPaneRenderNumericString.md | Completion:92 | Confidence:93
void NumericStringControlPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);
    SetDrawColor(0);
    FillRect(&bounds);

    const short textWidth =
        static_cast<short>(9 * wcslen(m_text.c_str()));

    int glyphLeft;
    if (m_alignment == 1) {
        glyphLeft = bounds.right - textWidth;
    } else if (m_alignment == 2) {
        glyphLeft =
            bounds.left + (bounds.right - textWidth - bounds.left) / 2;
    } else {
        glyphLeft = bounds.left;
    }

    RectBounds glyphBounds;
    InitRectBounds(&glyphBounds,
                   glyphLeft,
                   bounds.top,
                   glyphLeft + 9,
                   bounds.top + 11);

    EPFTileContext glyphContext;
    for (const wchar_t *character = m_text.c_str();
         *character != L'\0';
         ++character) {
        if (*character == L'-') {
            g_pEPFLib->LookupLayoutEntry(L"FONTSYMB.EPF",
                                         4,
                                         &glyphContext);

            glyphBounds.Offset(glyphContext.bounds.left,
                               glyphContext.bounds.top);
            RenderTileFrame(&glyphContext,
                            &glyphContext.bounds,
                            &glyphBounds,
                            1,
                            L"FONTSYMB.PAL",
                            NULL);
            glyphBounds.Offset(-glyphContext.bounds.left,
                               -glyphContext.bounds.top);
        } else if (*character != L' ' && *character != L'/') {
            InitNumericGlyphTileContext(&glyphContext,
                                        m_numericGlyphs,
                                        *character,
                                        m_colorVariant);
            g_pfnBlitSprite(this,
                            &glyphContext,
                            &glyphContext.bounds,
                            &glyphBounds,
                            1,
                            NULL,
                            NULL);
        }

        OffsetRect(&glyphBounds, 9, 0);
    }
}

// UID:000124 | by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md | Completion:91 | Confidence:93
// [UID:000124] The compiler-generated NumericStringControlPane scalar deleting
// destructor is covered by the source-level virtual destructor in [UID:00011N][0x004999d0-0x00499a4e.NumericStringControlPaneDestructor](by-memory/0x004999d0-0x00499a4e.NumericStringControlPaneDestructor.md).
// Do not hand-emit delete flags, vtable resets, implicit member/base teardown,
// object-free dispatch, or secondary/tertiary this-adjustor routes.

// UID:0003IR | by-type/by-vtable/NumericStringControlPaneVtables.md | Completion:90 | Confidence:93
// [UID:0003IR] NumericStringControlPane's three vtable views are covered by the
// [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md) class declaration and virtual method definitions; the compiler
// generates their RTTI, slot layout, deleting wrapper, and adjustor entries.

// UID:0002OD | by-memory/0x0061838c-0x00618430.NumericStringControlPaneVtableData.md | Completion:91 | Confidence:93
// [UID:0002OD] NumericStringControlPane RTTI and primary, secondary, and tertiary
// vtable bytes are compiler-generated from the [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md) class declaration
// and its virtual destructor/OnPaint definitions; do not emit raw table arrays.

// UID:0003XD | by-memory/0x004bb1e0-0x004bb252.NumericStringGlyphTileContextInit.md | Completion:91 | Confidence:92
static EPFTileContext *InitNumericGlyphTileContext(EPFTileContext *context,
                                                   char *numericGlyphs,
                                                   wchar_t glyph,
                                                   int colorVariant)
{
    RectBounds bounds;
    bounds.SetLTRB(0, 0, 9, 11);

    context->Initialize();
    context->rowStridePixels = 9;
    context->encodedMaskByteCount = 0;
    context->encodedMaskBytes = NULL;
    context->bounds = bounds;
    context->pixelData =
        numericGlyphs + 99 * (glyph + 10 * colorVariant - 47);

    return context;
}
