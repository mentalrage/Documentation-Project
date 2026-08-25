// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J2
// Source by-file doc: by-file/EPFImageControlPane.md
// UID:00004G | by-class/EPFImageControlPane.md | Completion:92 | Confidence:93
#include "EPFImageControlPane.h"

// UID:0004JN | by-memory/0x004991f0-0x004992a8.EPFImageControlPaneConstructor.md | Completion:92 | Confidence:94
EPFImageControlPane::EPFImageControlPane(const wchar_t *resourceName,
                                         short frameIndex,
                                         unsigned char mode,
                                         const RectBounds *bounds,
                                         const wchar_t *paletteName)
    : ControlPane(8, bounds)
{
    wcscpy_s(m_resourceName, _countof(m_resourceName), resourceName);
    m_frameIndex = frameIndex;
    m_controlFlags = 0;
    SetMode(mode);
    wcscpy_s(m_paletteName,
             _countof(m_paletteName),
             paletteName != NULL ? paletteName : L"BARAM.PAL");
}

// UID:0004JS | by-memory/0x004992b0-0x0049930e.EPFImageControlPaneDestructor.md | Completion:91 | Confidence:94
EPFImageControlPane::~EPFImageControlPane()
{
    m_surfaceContext.ReleaseBuffers();
}

// UID:0004JW | by-memory/0x00499310-0x004993a5.EPFImageControlPaneOnPaint.md | Completion:92 | Confidence:93
void EPFImageControlPane::OnPaint()
{
    EPFTileContext frame;

    SetDrawColor(0);
    FillRect(&m_bounds);

    g_pEPFLib->LookupLayoutEntry(m_resourceName, m_frameIndex, &frame);
    if (frame.pixelData != NULL)
    {
        void *palette = g_pPaletteLib->GetPaletteByName(m_paletteName);
        g_pfnBlitSprite(this,
                        &frame,
                        &frame.bounds,
                        &m_bounds,
                        0,
                        palette,
                        NULL);
    }

    m_surfaceContext.BuildEncodedMask();
}

// UID:0003LO | by-memory/0x0049b1b0-0x0049b24f.EPFImageControlPaneScalarDeletingDestructor.md | Completion:91 | Confidence:94
// Source-declared/generated-binary only. EPFImageControlPane's virtual
// destructor declaration and ordinary destructor definition regenerate this
// scalar deleting destructor, conditional operator delete path, and the
// secondary/tertiary adjustor routes. Do not hand-emit an ABI wrapper.
