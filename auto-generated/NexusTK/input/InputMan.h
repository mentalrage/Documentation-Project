// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K6
// Source by-file doc: by-file/InputMan.md
// UID:00006J | by-class/InputMan.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_INPUT_INPUTMAN_H
#define NEXUSTK_INPUT_INPUTMAN_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include <windows.h>
#include <imm.h>

class List;

class InputMan : public LObject, public Singleton<InputMan>
{
public:
    InputMan();
    virtual ~InputMan();

    void TrackInputTarget(int targetId, bool active);
    unsigned char GetImeStateByte() const;
    bool HandleWindowMessage(HWND window, UINT message, WPARAM wParam,
                             LPARAM lParam, LRESULT *result);
    bool HandleDefaultWindowMessage(HWND window, UINT message,
                                    WPARAM wParam, LPARAM lParam,
                                    LRESULT *result);
    int GetInputMode() const;
    BOOL SetInputMode(int mode);

private:
    HWND m_defaultImeWindow;
    HIMC m_ownedImeContext;
    HIMC m_restoreImeContext;
    DWORD m_imePropertyFlags;
    WORD m_imeStateWord;
    int m_inputMode;
    List *m_inputTargetList;
};

BOOL __stdcall CompleteImeComposition();
int __stdcall GetCompositionCursorPosition();

extern InputMan *g_pInputMan;

typedef char InputManSizeMustBe32[sizeof(InputMan) == 0x20 ? 1 : -1];

#endif
