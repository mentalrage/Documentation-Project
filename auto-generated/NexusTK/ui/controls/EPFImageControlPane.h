// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J2
// Source by-file doc: by-file/EPFImageControlPane.md
// UID:00004G | by-class/EPFImageControlPane.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_UI_CONTROLS_EPFIMAGECONTROLPANE_H
#define NEXUSTK_UI_CONTROLS_EPFIMAGECONTROLPANE_H

#include "../core/ControlPane.h"

struct RectBounds;

class EPFImageControlPane : public ControlPane
{
public:
    EPFImageControlPane(const wchar_t *resourceName,
                        short frameIndex,
                        unsigned char mode,
                        const RectBounds *bounds,
                        const wchar_t *paletteName);
    virtual ~EPFImageControlPane();
    virtual void OnPaint();

private:
    wchar_t m_resourceName[16];
    short m_frameIndex;
    wchar_t m_paletteName[16];
};

#endif
