// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IW
// Source by-file doc: by-file/DirectX.md
// UID:00003Y | by-class/DirectX.md | Completion:92 | Confidence:94
#include "DirectX.h"
#include "../util/Error.h"

// UID:0000QS | by-global/g_pDirectX.md | Completion:92 | Confidence:94
DirectX *g_pDirectX = NULL;

template <>
Singleton<DirectX>::Singleton()
{
    g_pDirectX = static_cast<DirectX *>(this);
}

template <>
Singleton<DirectX>::~Singleton()
{
    g_pDirectX = NULL;
}

// UID:000295 | by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md).

// UID:000137 | by-memory/0x004a1b60-0x004a1d6a.DirectX.md | Completion:92 | Confidence:94
DirectX::DirectX()
    : LObject(),
      Singleton<DirectX>(),
      m_pDirectDraw(NULL)
{
    LPDIRECTDRAW lpDD = NULL;
    if (DirectDrawCreate(NULL, &lpDD, NULL) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }

    if (lpDD->QueryInterface(IID_IDirectDraw, (LPVOID *)&m_pDirectDraw) < 0) {
        throw new MyError(L"DirectX not installed, or is corrupted. Please install DirectX again.");
    }
}

DirectX::~DirectX()
{
    m_pDirectDraw->Release();
    m_pDirectDraw = NULL;
}

// UID:0002MD | by-memory/0x00618e60-0x00618e70.DirectXVtableData.md | Completion:92 | Confidence:94
// DirectX vtable and RTTI data are compiler-generated from [UID:00003Y][DirectX](by-class/DirectX.md).

// UID:0003AY | by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md | Completion:92 | Confidence:94
// This literal is emitted by the two failure throws in [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md).

// UID:0003HP | by-type\by-vtable\DirectXVtable.md | Completion:92 | Confidence:94 | Empty Emitter Marker
