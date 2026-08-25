// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K9
// Source by-file doc: by-file/InterfaceEfx.md
// UID:00006N | by-class/InterfaceEfx.md | Completion:85 | Confidence:88
#ifndef NEXUSTK_UI_INTERFACEEFX_H
#define NEXUSTK_UI_INTERFACEEFX_H

#include "core/Pane.h"

class Layer;

class InterfaceEfx : public Pane
{
public:
    InterfaceEfx(const wchar_t *effectResource,
                 int tickInterval,
                 int anchorX,
                 int anchorY,
                 Layer *layerContext,
                 bool mirrored,
                 const wchar_t *paletteResource);
    virtual ~InterfaceEfx();

    void Play();

private:
    unsigned char m_recoveredEffectState[0x64];
};

typedef char InterfaceEfxSizeMustBe348[
    sizeof(InterfaceEfx) == 0x15c ? 1 : -1];

#endif
