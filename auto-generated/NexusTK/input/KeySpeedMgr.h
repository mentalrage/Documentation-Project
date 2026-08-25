// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KJ
// Source by-file doc: by-file/KeySpeedMgr.md
// UID:00006Z | by-class/KeySpeedMgr.md | Completion:88 | Confidence:91
#ifndef NEXUSTK_INPUT_KEYSPEEDMGR_H
#define NEXUSTK_INPUT_KEYSPEEDMGR_H

#include "../util/LObject.h"
#include <windows.h>

class KeySpeedMgr : public LObject
{
public:
    KeySpeedMgr();
    virtual ~KeySpeedMgr();

    void LoadSystemKeyboardSettings();
    void RestoreSystemKeyboardSettings();

private:
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};

extern KeySpeedMgr *g_pKeySpeedMgr;

#endif
