// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HG
// Source by-file doc: by-file/Application.md
// UID:0000SU | by-global/g_screenWidth.md | Completion:90 | Confidence:93
#ifndef NEXUSTK_APP_APPLICATION_H
#define NEXUSTK_APP_APPLICATION_H

extern short g_screenWidth;

// UID:0000ST | by-global/g_screenHeight.md | Completion:90 | Confidence:93
extern short g_screenHeight;

// UID:00000D | by-class/Application.md | Completion:92 | Confidence:94
#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"
#include "MSGHandler.h"

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

class Application : public LObject,
                    public Singleton<Application>,
                    public MSGHandler
{
public:
    Application(HINSTANCE hInstance,
                const wchar_t *publisherName,
                const wchar_t *applicationTitle);
    virtual ~Application();

    virtual void Startup();
    virtual void Shutdown();
    virtual void OnActivate();
    virtual void OnDeactivate();
    virtual LRESULT DispatchMessage(MSG *message);

    void RunMessageLoop();
    void RequestExit();
    bool IsExitRequested() const;
    const wchar_t *DetectOS();
    int GetOsCode() const;
    void ReadProcessorName();
    HINSTANCE GetInstanceHandle() const;
    HWND GetMainWindowHandle() const;
    bool IsRunning() const;
    errno_t CopyDatFileName(wchar_t *destination,
                            size_t sizeInWords) const;
    uint16_t GetVersionMajor() const;
    uint16_t GetVersionMinor() const;
    int ValidateLicense();
    MSGHandler *ExchangeMSGHandler(MSGHandler *nextHandler);
    int *MapFromScreen(int *mappedPair,
                       const int *screenPair) const;
    int *MapToScreen(int *mappedPair,
                     const int *clientPair) const;
    errno_t CopyWorldName(wchar_t *destination,
                          size_t sizeInWords) const;
    errno_t CopyPlayerName(wchar_t *destination,
                           size_t sizeInWords) const;
    BOOL DestroyLoadingDialog();
    void SendShutdownMessage();

private:
    void SignalExitRequested();

public:
    int m_osCode;
    unsigned int m_osVersionState;
    bool m_isWow64;
    mystr::StringBase<wchar_t> m_processorName;
    HINSTANCE m_hInstance;
    HANDLE m_hSingleInstanceMutex;
    wchar_t m_worldName[256];
    wchar_t m_playerName[256];
    wchar_t m_datFileName[256];
    wchar_t m_sndFileName[256];
    HWND m_hMainWnd;
    HWND m_hLoadingDlg;
    int m_currentScreenWidth;
    int m_currentScreenHeight;
    bool m_isRunning;
    bool m_windowInputActive;
    bool m_exitRequested;
    HANDLE m_hShutdownEvent;
    bool m_inMapSession;
    uint16_t m_clientVersionLowWord;
    MSGHandler *m_activeMessageHandler;
    DWORD m_startupThreadId;
    bool m_soundDatLoaded;
    bool m_networkStartupComplete;
    bool m_hostLookupSucceeded;
    bool m_musicDirectoryBrowsePending;
    uint16_t m_clientVersionCode;
    mystr::StringBase<wchar_t> m_osVersionLabel;
    wchar_t m_currentServerName[256];
    int m_windowTop;
    int m_windowLeft;
    int m_windowHeight;
    int m_windowWidth;
    int m_presentationWidth;
    int m_presentationHeight;
    const wchar_t *m_executableIntegrityErrorText;
};

extern Application *g_pApplication;

typedef char ApplicationSizeMustBe2676[
    sizeof(Application) == 0xa74 ? 1 : -1];

// UID:00000V | by-class/BaramApp.md | Completion:87 | Confidence:91
class BaramApp : public Application
{
public:
    BaramApp(HINSTANCE hInstance,
             const wchar_t *publisherName,
             const wchar_t *applicationTitle);

    virtual void Startup();
    virtual void Shutdown();

private:
    void OpenTerminalPaneAfterStartupLogo();
};

#endif
