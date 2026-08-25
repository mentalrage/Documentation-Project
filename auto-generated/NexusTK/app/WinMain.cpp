// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000PA
// Source by-file doc: by-file/WinMain.md
// UID:00032A | by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md | Completion:93 | Confidence:95
#include "Application.h"
#include "StartupWindow.h"
#include "../archive/DATFileMgr.h"
#include "../input/KeySpeedMgr.h"
#include "../map/MiniMapVersionManager.h"
#include "../platform/PlatformApi.h"
#include "../ui/core/ScreenPane.h"
#include "../util/Error.h"

#include <shellapi.h>
#include <windows.h>

#include "../util/Singleton.h"

static void DestroyKeySpeedMgr()
{
    delete g_pKeySpeedMgr;
}

// UID:00019G | by-memory/0x004f5c80-0x004f5f17.WinMain.md | Completion:94 | Confidence:95
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
    BaramApp app(hInstance, L"Nexon", L"NexusTK");

    try {
        new MiniMapVersionManager;
        g_pMiniMapVersionManager->LoadHashFile();

        bool shouldRunUpdater = false;
        StartupWindow *startupWindow = new StartupWindow(hInstance);
        int startupResult = startupWindow->RunUpdateCheck(&shouldRunUpdater);
        delete startupWindow;

        if (shouldRunUpdater == StartupWindow::kRunUpdater) {
            MessageBoxW(NULL,
                        L"There is a newer version of Nexus TK available.\nClick 'OK' to proceed.",
                        L"Nexus TK update needed",
                        MB_ICONINFORMATION);

            WCHAR currentDirectory[MAX_PATH];
            g_pfnGetCurrentDirectoryW(MAX_PATH, currentDirectory);

            SHELLEXECUTEINFOA executeInfo = {};
            executeInfo.cbSize = sizeof(executeInfo);
            executeInfo.lpFile = "NexusUpdater.exe";
            executeInfo.lpDirectory = reinterpret_cast<LPCSTR>(currentDirectory);
            executeInfo.nShow = SW_SHOWNORMAL;

            ShellExecuteExA(&executeInfo);
        } else if (startupResult != StartupWindow::kAbortStartup) {
            app.Startup();
            app.RunMessageLoop();
            app.Shutdown();
            return 0;
        }

        if (g_pDATFileMgr != NULL) {
            delete g_pDATFileMgr;
        }

        app.RequestExit();
    } catch (Error *error) {
        WCHAR messageText[0x800];

        error->FormatErrorMessage(messageText, _countof(messageText));

        HWND mainWindow = app.GetMainWindowHandle();
        if (mainWindow != NULL) {
            ShowWindow(mainWindow, SW_HIDE);
        }

        if (g_pScreenPane != NULL) {
            g_pScreenPane->RestoreDirectDrawState();
        }

        if (g_pKeySpeedMgr != NULL) {
            g_pKeySpeedMgr->RestoreSystemKeyboardSettings();
            DestroyKeySpeedMgr();
        }

        MessageBoxW(NULL, messageText, error->GetErrorName(), MB_OK);
        delete error;
    }

    return 0;
}

// UID:0003P3 | by-memory/0x0061d140-0x0061d234.WinMainStartupUpdateStrings.md | Completion:92 | Confidence:94
// WinMain startup/update string literals are emitted at their use sites; this pooled .rdata range emits no standalone static string declarations.
