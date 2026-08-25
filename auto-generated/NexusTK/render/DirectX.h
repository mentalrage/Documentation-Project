// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IW
// Source by-file doc: by-file/DirectX.md
// UID:00003Y | by-class/DirectX.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_RENDER_DIRECTX_H
#define NEXUSTK_RENDER_DIRECTX_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include <ddraw.h>

class DirectX : public LObject, public Singleton<DirectX>
{
public:
    DirectX();
    virtual ~DirectX();

    LPDIRECTDRAW m_pDirectDraw;
};

extern DirectX *g_pDirectX;

typedef char DirectXSizeMustBe0x8[
    sizeof(DirectX) == 0x8 ? 1 : -1];

#endif
