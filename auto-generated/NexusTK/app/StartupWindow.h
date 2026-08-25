// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O5
// Source by-file doc: by-file/StartupWindow.md
// UID:0000DZ | by-class/StartupWindow.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_APP_STARTUPWINDOW_H
#define NEXUSTK_APP_STARTUPWINDOW_H

#include "../util/Singleton.h"
#include <windows.h>

class DIBitmap;

struct StartupNoticeButton
{
    DIBitmap *images[3];
    RECT rect;
    int state;
};

class StartupWindow : public Singleton<StartupWindow>
{
public:
    enum Result
    {
        kRunUpdater = 1,
        kAbortStartup = 2
    };

    StartupWindow(HINSTANCE instance);
    virtual ~StartupWindow();

    int RunUpdateCheck(bool *runUpdater);
    HINSTANCE GetInstanceHandle() const;

    bool m_assetsLoaded;
    HINSTANCE m_instance;
    HWND m_noticeWindow;
    DIBitmap *m_backgroundImage;
    StartupNoticeButton m_buttons[2];
    bool m_resultReady;
};

typedef char StartupNoticeButtonSizeMustBe0x20[
    sizeof(StartupNoticeButton) == 0x20 ? 1 : -1];
typedef char StartupWindowSizeMustBe0x58[
    sizeof(StartupWindow) == 0x58 ? 1 : -1];

// UID:0000SW | by-global/g_useEpfAssets.md | Completion:88 | Confidence:90
extern bool g_useEpfAssets;

// UID:0003XA | by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md | Completion:92 | Confidence:93
bool IsLegacyAssetMode();

#endif
