// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HG
// Source by-file doc: by-file/Application.md
// UID:0000SU | by-global/g_screenWidth.md | Completion:90 | Confidence:93
short g_screenWidth = 1024;

// UID:000294 | by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md | Completion:90 | Confidence:92
#include "Application.h"

Application *g_pApplication = NULL;

// UID:000529 | by-memory/0x0067a9a4-0x0067a9bc.ApplicationMessageHandlerCriticalSection.md | Completion:93 | Confidence:95
#include "../util/CriticalSection.h"

static CriticalSection s_messageHandlerCriticalSection;

// UID:0000ST | by-global/g_screenHeight.md | Completion:90 | Confidence:93
short g_screenHeight = 768;

// UID:00000D | by-class/Application.md | Completion:92 | Confidence:94
#include "../ui/core/BlackHole.h"

// UID:0002GJ | by-memory/0x004669c0-0x00466a69.ApplicationOnActivate.md | Completion:90 | Confidence:93
void Application::OnActivate()
{
    if (m_exitRequested)
        return;

    if (g_pEventMan != NULL)
        g_pEventMan->ClearKeyboardState();

    if (ApplicationActiveGate == 0 && g_pScreenPane != NULL) {
        g_pApplication->m_isRunning = true;
        SurfaceFlipSurfaces(g_pScreenPane);
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_RESTORE);
    }

    if (g_pKeySpeedMgr != NULL)
        ApplyFastKeyboardRepeatSettings();

    if (!g_pSoundManager->IsSoundEffectsEnabled())
        g_pSoundManager->RestoreSoundEffectsAfterAppFocus();

    if (g_pConfig->m_musicPlaybackMode == 0 &&
        !g_pSoundManager->IsPlaybackEnabled() &&
        g_pSoundManager->m_musicOptionEnabled) {
        g_pSoundManager->m_musicOptionEnabled = false;
        g_pMidiPlayer->EnableMidiPlayback();
        g_pSoundManager->m_musicPlaybackEnabled = true;
        g_pSoundManager->m_musicOptionEnabled = true;

        if (g_pSoundManager->m_currentTrackIndex != 0 &&
            AIL_stream_status(g_pSoundManager->m_stream) != 4) {
            const int trackIndex = g_pSoundManager->m_currentTrackIndex;
            const int volumeScale = g_pSoundManager->m_currentTrackVolumeScale;
            const int loopCount = g_pSoundManager->m_currentLoopCount;
            g_pSoundManager->m_currentTrackIndex = 0;
            g_pSoundManager->PlayTrackByIndex(trackIndex, volumeScale, loopCount);
        }

        g_pSoundManager->SetStreamVolume(g_pSoundManager->m_streamVolume);
    }
}

// UID:0002GK | by-memory/0x00466a70-0x00466b23.ApplicationOnDeactivate.md | Completion:90 | Confidence:92
void Application::OnDeactivate()
{
    if (m_exitRequested)
        return;

    m_windowInputActive = false;

    if (ApplicationActiveGate == 0 && g_pScreenPane != NULL) {
        g_pApplication->m_isRunning = false;
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_MINIMIZE);
        g_pScreenPane->RestoreDirectDrawState();
    }

    if (g_pEventMan != NULL)
        g_pEventMan->ResetInputState(false);

    if (g_pKeySpeedMgr != NULL)
        g_pKeySpeedMgr->RestoreSystemKeyboardSettings();

    if (g_activeMapPane != NULL)
        g_activeMapPane->ClearQueuedMapStateRefresh();

    if (g_pConfig->m_soundEffectsEnabled)
        g_pSoundManager->SuspendSoundEffectsForApplicationDeactivate();

    if (g_pConfig->m_musicPlaybackMode == 0) {
        if (g_pSoundManager->m_musicPlaybackEnabled)
            g_pSoundManager->m_musicOptionEnabled = true;

        g_pMidiPlayer->DisableMidiPlayback();
        g_pSoundManager->m_musicPlaybackEnabled = false;
        g_pSoundManager->SetStreamVolume(g_pSoundManager->m_streamVolume);
    }
}

// UID:0002GY | by-memory/0x00463310-0x0046396e.ApplicationConstructor.md | Completion:89 | Confidence:92
// No standalone constructor body is emitted here; Application::Application is documented by UID0002GY, but full class layout, Application+0xa70 state, DAT manager construction, OS-version static grouping, and compiler unwind cleanup remain exact evidence rather than a guessed constructor body.

// UID:0002GZ | by-memory/0x00463970-0x004639c4.ApplicationDestructor.md | Completion:89 | Confidence:92
// No first-draft body yet: Application::~Application cleanup ordering depends on the unresolved
// Application base/member declaration for StringBase, MSGHandler, g_pApplication, and LObject teardown.

// UID:0002H0 | by-memory/0x004639d0-0x00464a52.ApplicationStartup.md | Completion:86 | Confidence:90
// No first-draft body yet: Application::Startup is a 0x1082-byte startup
// orchestrator whose fatal, patcher, Win32Error, DAT-load, window-creation,
// and singleton-construction branches still require branch-level source proof.

// UID:0002H1 | by-memory/0x00464a60-0x00464cc1.ApplicationShutdown.md | Completion:90 | Confidence:92
static const MessageType kPaneTagTerm = 0x7465726d;

void Application::Shutdown()
{
    delete g_pMiscWorkThread;
    delete g_pFileDownloader;

    Message message(kPaneTagTerm);
    ForwardMessage(&message);

    ShowCursor(TRUE);

    fclose(__acrt_iob_func(0));
    fclose(__acrt_iob_func(1));
    fclose(__acrt_iob_func(2));

    g_pKeySpeedMgr->RestoreSystemKeyboardSettings();
    delete g_pKeySpeedMgr;

    delete g_pSoundManager;
    delete g_pEventMan;
    delete g_pScreenPane;
    delete g_pDirectX;

    ShowWindow(m_hMainWnd, SW_HIDE);

    if (s_applicationErrorText.m_count != 0)
        MessageBoxW(NULL, s_applicationErrorText.m_data, L"Error", 0);

    delete g_pEventDispatcher;
    delete g_pMidiPlayer;
    delete g_pCheatDetector;

    if (g_pConfig != NULL)
    {
        g_pConfig->SaveToRegistry();
        delete g_pConfig;
    }

    delete g_pFontImageLib;
    delete g_pEPFLib;
    delete g_pPaletteLib;
    delete g_pInputMan;

    if (g_pApplicationCleanupQueue != NULL)
    {
        g_pApplicationCleanupQueue->ReleaseQueuedOwnedObjects();
        delete g_pApplicationCleanupQueue;
    }

    delete g_pLanguageMan;
    delete g_pChangeMan;
    delete g_pCrasher;
    delete g_pCrashTarget;

    if (m_hShutdownEvent != NULL)
    {
        CloseHandle(m_hShutdownEvent);
        m_hShutdownEvent = NULL;
    }

    delete g_pMiniMapVersionManager;
    delete g_pDATFileMgr;
}

// UID:0002H2 | by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md | Completion:89 | Confidence:92
void Application::RunMessageLoop()
{
    MSG message;

    g_pEventDispatcher->CaptureIdleTickBaseline();

    for (;;) {
        if (++g_applicationMessageLoopThrottleCounter > 10) {
            Sleep(1);
            g_applicationMessageLoopThrottleCounter = 0;
        }

        if (++g_applicationHeartbeatCheckCounter > 1000) {
            CheckTimerSkewAndSendHeartbeat();
            g_applicationHeartbeatCheckCounter = 0;
        }

        DWORD waitResult = MsgWaitForMultipleObjects(1, &m_hShutdownEvent, FALSE, 5, QS_ALLINPUT);
        if (waitResult == WAIT_OBJECT_0) {
            return;
        }

        if (waitResult == WAIT_TIMEOUT) {
            g_pEventDispatcher->ProcessIdleWork();
            continue;
        }

        if (waitResult != WAIT_OBJECT_0 + 1) {
            return;
        }

        while (g_pfnPeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                return;
            }

            if (g_activeBrowserControlPane != NULL &&
                BrowserControlPaneTranslateAcceleratorMessage(&message) == 0) {
                continue;
            }

            int inputMode = g_pInputMan->GetInputMode();
            if (inputMode == 2 || inputMode == 1) {
                TranslateMessage(&message);
            }

            MSGHandler *handler;
            {
                CriticalSectionLock lock(&s_messageHandlerCriticalSection);
                handler = m_activeMessageHandler;
            }

            handler->DispatchMessage(&message);
        }

        g_pEventDispatcher->ProcessIdleWork();
    }
}

// UID:0002H3 | by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md | Completion:90 | Confidence:92
void Application::RequestExit()
{
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserPane->ActivatePendingControl();

    if (g_activeMapPane != NULL)
        g_activeMapPane->ExitToMenu(true);

    if (g_pMiniMapVersionManager != NULL)
        delete g_pMiniMapVersionManager;

    if (g_pScreenPane != NULL)
    {
        typedef void (__thiscall Application::*ApplicationExitCallback)();
        PlainMemberFunctionObject0<ApplicationExitCallback, Application> *callback =
            new PlainMemberFunctionObject0<ApplicationExitCallback, Application>(
                &Application::SignalExitRequested, 0, this);

        ShowCursor(FALSE);
        g_pScreenPane->QueueFadeOutCallback(callback);
        return;
    }

    SetEvent(m_hShutdownEvent);
    m_exitRequested = true;
}

// UID:0002H4 | by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md | Completion:88 | Confidence:94
bool Application::IsExitRequested() const
{
    return m_exitRequested;
}

// UID:0002H5 | by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md | Completion:90 | Confidence:92
const wchar_t *Application::DetectOS()
{
    typedef BOOL (WINAPI *IsWow64ProcessProc)(HANDLE, PBOOL);

    static const unsigned int kApplicationOsWindows95 = 0x776e3935;
    static const unsigned int kApplicationOsWindows98 = 0x776e3938;
    static const unsigned int kApplicationOsWindowsNT = 0x776e6e74;
    static const unsigned int kApplicationOsWindows2000 = 0x776e326b;
    static const unsigned int kApplicationOsWindowsXP = 0x776e7870;
    static const unsigned int kApplicationOsWindowsVista = 0x776e7674;
    static const unsigned int kApplicationOsWindows7 = 0x00776e37;
    static const unsigned int kApplicationOsWindows8 = 0x00776e38;

    m_isWow64 = false;

    IsWow64ProcessProc isWow64Process =
        reinterpret_cast<IsWow64ProcessProc>(
            GetProcAddress(GetModuleHandleW(L"kernel32"), "IsWow64Process"));
    if (isWow64Process != NULL) {
        BOOL isWow64;
        if (isWow64Process(GetCurrentProcess(), &isWow64) != FALSE) {
            m_isWow64 = (isWow64 != FALSE);
        }
    }

    OSVERSIONINFOA versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExA(&versionInfo);

    if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) {
        m_osCode = (versionInfo.dwMinorVersion != 0)
            ? kApplicationOsWindows98
            : kApplicationOsWindows95;
    } else if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        if (versionInfo.dwMajorVersion == 6) {
            if (versionInfo.dwMinorVersion == 0) {
                m_osCode = kApplicationOsWindowsVista;
            } else {
                m_osCode = (versionInfo.dwMinorVersion == 1)
                    ? kApplicationOsWindows7
                    : kApplicationOsWindows8;
            }
        } else if (versionInfo.dwMajorVersion == 5) {
            m_osCode = (versionInfo.dwMinorVersion != 0)
                ? kApplicationOsWindowsXP
                : kApplicationOsWindows2000;
        } else if (versionInfo.dwMajorVersion <= 4) {
            m_osCode = kApplicationOsWindowsNT;
        }
    } else {
        m_osCode = kApplicationOsWindows95;
    }

    const wchar_t *label = L"Unknown";
    bool appendBitnessSuffix = false;

    switch (m_osCode) {
    case kApplicationOsWindows95:
        label = L"Windows95";
        break;
    case kApplicationOsWindows98:
        label = L"Windows98";
        break;
    case kApplicationOsWindowsNT:
        label = L"WindowsNT";
        break;
    case kApplicationOsWindows2000:
        label = L"Windows2000";
        break;
    case kApplicationOsWindowsXP:
        label = L"WindowsXP";
        break;
    case kApplicationOsWindowsVista:
        label = L"WindowsVista";
        break;
    case kApplicationOsWindows7:
        label = L"Windows7";
        appendBitnessSuffix = true;
        break;
    case kApplicationOsWindows8:
        label = L"Windows8";
        appendBitnessSuffix = true;
        break;
    }

    m_osVersionLabel = label;
    if (appendBitnessSuffix) {
        m_osVersionLabel.append(m_isWow64 ? L"_64bit" : L"_32bit");
    }

    return m_osVersionLabel.c_str();
}

// UID:0002JV | by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md | Completion:88 | Confidence:91
int Application::GetOsCode() const
{
    return m_osCode;
}

// UID:0002JW | by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md | Completion:88 | Confidence:91
void Application::ReadProcessorName()
{
    HKEY processorKey;
    DWORD processorNameBytes;
    wchar_t processorName[0x400];

    RegOpenKeyExW(HKEY_LOCAL_MACHINE,
                  L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                  0,
                  KEY_QUERY_VALUE,
                  &processorKey);

    processorNameBytes = sizeof(processorName);
    RegQueryValueExW(processorKey,
                     L"ProcessorNameString",
                     NULL,
                     NULL,
                     reinterpret_cast<LPBYTE>(processorName),
                     &processorNameBytes);
    RegCloseKey(processorKey);

    m_processorName = processorName;
}

// UID:0002GM | by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md | Completion:88 | Confidence:93
HINSTANCE Application::GetInstanceHandle() const
{
    return m_hInstance;
}

// UID:0002GN | by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md | Completion:88 | Confidence:93
HWND Application::GetMainWindowHandle() const
{
    return m_hMainWnd;
}

// UID:0002GO | by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md | Completion:88 | Confidence:93
bool Application::IsRunning() const
{
    return m_isRunning;
}

// UID:0002JY | by-memory/0x004652e0-0x004652fc.ApplicationCopyDatFileName.md | Completion:90 | Confidence:92
errno_t Application::CopyDatFileName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_datFileName);
}

// UID:0002GP | by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md | Completion:88 | Confidence:92
uint16_t Application::GetVersionMajor() const
{
    return m_clientVersionCode;
}

// UID:0002GQ | by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md | Completion:88 | Confidence:92
uint16_t Application::GetVersionMinor() const
{
    return m_clientVersionLowWord;
}

// UID:0002H6 | by-memory/0x00465430-0x0046564c.ApplicationValidateLicense.md | Completion:89 | Confidence:91
int Application::ValidateLicense()
{
    const WORD kVersionInfoFailureCode = 0x0136;
    const WORD kVersionCodeMismatch = 0x02a8;

    wchar_t executablePath[0x104];
    DWORD versionHandle = 0;
    UINT fixedInfoLength = 0;
    VS_FIXEDFILEINFO *fixedInfo = NULL;
    void *versionInfo = NULL;

    BuildExecutablePathForVersionInfo(executablePath);

    const DWORD versionInfoSize =
        g_pfnGetFileVersionInfoSizeW(executablePath, &versionHandle);
    if (versionInfoSize == 0) {
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    try {
        versionInfo = AllocateBufferMemory(versionInfoSize);
    } catch (Win32Error *error) {
        delete error;
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    if (!g_pfnGetFileVersionInfoW(executablePath, 0, versionInfoSize, versionInfo) ||
        !g_pfnVerQueryValueW(versionInfo, L"\\",
                             reinterpret_cast<void **>(&fixedInfo),
                             &fixedInfoLength)) {
        FreeBufferMemory(versionInfo);
        m_clientVersionCode = kVersionInfoFailureCode;
        m_clientVersionLowWord = 0;
        return 0;
    }

    const WORD fileMajor = HIWORD(fixedInfo->dwFileVersionMS);
    const WORD fileMinor = LOWORD(fixedInfo->dwFileVersionMS);
    const WORD fileBuild = HIWORD(fixedInfo->dwFileVersionLS);
    const WORD fileRevision = LOWORD(fixedInfo->dwFileVersionLS);

    FreeBufferMemory(versionInfo);

    const WORD computedCode = static_cast<WORD>(
        (fileMajor % 10) * 100 +
        (fileMinor % 10) * 10 +
        (fileBuild % 10));

    char keyText[0x100];
    sprintf_s(keyText, _countof(keyText), "%s", "7TK5E-KRU-2K");

    char digits[0x100];
    char *digitOut = digits;
    for (const char *cursor = keyText; *cursor != '\0'; ++cursor) {
        if (*cursor >= '0' && *cursor <= '9') {
            *digitOut++ = *cursor;
        }
    }
    *digitOut = '\0';

    const int expectedCode = atoi(digits);
    m_clientVersionLowWord = fileRevision;

    if (computedCode == expectedCode) {
        m_clientVersionCode = computedCode;
        return expectedCode;
    }

    m_clientVersionCode = kVersionCodeMismatch;
    return kVersionCodeMismatch;
}

// UID:0002GR | by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md | Completion:92 | Confidence:95
MSGHandler* Application::ExchangeMSGHandler(MSGHandler* nextHandler)
{
    MSGHandler* previous = m_activeMessageHandler;
    CriticalSectionLock lock(&s_messageHandlerCriticalSection);
    m_activeMessageHandler = nextHandler;
    return previous;
}

// UID:0002GS | by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md | Completion:88 | Confidence:93
int *Application::MapFromScreen(int *mappedPair, const int *screenPair) const
{
    if (m_currentScreenWidth == g_screenWidth &&
        m_currentScreenHeight == g_screenHeight) {
        mappedPair[0] = screenPair[0];
        mappedPair[1] = screenPair[1];
        return mappedPair;
    }

    mappedPair[0] = static_cast<int>(
        static_cast<float>(screenPair[0] * g_screenHeight) /
        static_cast<float>(m_currentScreenHeight) + 0.5f);
    mappedPair[1] = static_cast<int>(
        static_cast<float>(screenPair[1] * g_screenWidth) /
        static_cast<float>(m_currentScreenWidth) + 0.5f);
    return mappedPair;
}

// UID:0002GT | by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md | Completion:88 | Confidence:93
int *Application::MapToScreen(int *mappedPair, const int *clientPair) const
{
    if (m_currentScreenWidth == g_screenWidth &&
        m_currentScreenHeight == g_screenHeight) {
        mappedPair[0] = clientPair[0];
        mappedPair[1] = clientPair[1];
        return mappedPair;
    }

    mappedPair[0] = static_cast<int>(
        static_cast<float>(clientPair[0] * m_currentScreenHeight) /
        static_cast<float>(g_screenHeight) + 0.5f);
    mappedPair[1] = static_cast<int>(
        static_cast<float>(clientPair[1] * m_currentScreenWidth) /
        static_cast<float>(g_screenWidth) + 0.5f);
    return mappedPair;
}

// UID:0002GU | by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md | Completion:95 | Confidence:95
errno_t Application::CopyWorldName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_worldName);
}

// UID:0002GV | by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md | Completion:95 | Confidence:95
errno_t Application::CopyPlayerName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_playerName);
}

// UID:0002GW | by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md | Completion:88 | Confidence:94
BOOL Application::DestroyLoadingDialog()
{
    return DestroyWindow(m_hLoadingDlg);
}

// UID:00050N | by-memory/0x00465ce0-0x00465ce6.ApplicationDispatchMessage.md | Completion:95 | Confidence:97
LRESULT Application::DispatchMessage(MSG *message)
{
    return g_pfnDispatchMessageW(message);
}

// UID:000323 | by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md | Completion:87 | Confidence:91
// Compiler-generated Application scalar deleting destructor; source-level destruction is represented by Application::~Application and compiler delete wrappers, so this range emits no hand-written body.

// UID:0002GX | by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md | Completion:88 | Confidence:92
static const unsigned int kPaneTagGoog = 0x676f6f67;

void Application::SendShutdownMessage()
{
    Message message(kPaneTagGoog);
    ForwardMessage(&message);
}

// UID:00047Y | by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md | Completion:92 | Confidence:95
// Compiler-generated MSVC RTTI complete-object-locator pointer for Application.
// The Application class declaration regenerates this primary vftable[-1] metadata.
// No standalone source object or raw RTTI dword is emitted here.

// UID:0003OD | by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md | Completion:94 | Confidence:95
// Compiler-generated Application primary vftable and MSGHandler secondary vftable.
// Rebuild this .rdata from Application's direct non-virtual bases and virtual declarations;
// no raw vtable entries or complete-object-locator records are authored here.

// UID:00000V | by-class/BaramApp.md | Completion:87 | Confidence:91
// BaramApp class declaration is intentionally withheld here; exact constructor, startup, callback, activation, shutdown, vtable, and compiler-wrapper children carry the Application.cpp source route.
// UID:0002PZ | by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md | Completion:89 | Confidence:92
BaramApp::BaramApp(HINSTANCE hInstance,
                   const wchar_t *publisherName,
                   const wchar_t *applicationTitle)
    : Application(hInstance, publisherName, applicationTitle)
{
}

// UID:0002Q0 | by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md | Completion:92 | Confidence:94
void BaramApp::OpenTerminalPaneAfterStartupLogo()
{
    g_pScreenPane->ShowCursor();
    new TerminalPane;
}

// UID:0002H7 | by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md | Completion:90 | Confidence:91
void BaramApp::Startup()
{
    Application::Startup();

    new IdleWatcher(20000);
    g_packetSender->StartThread();

    new ItemObjImageLib;
    new MapTileImageLib;
    new StaticObjImageLib;
    new NewHumanImageLib;
    new MonsterImageLib;
    new RidingImageLib;
    new EffectObjImageLib;
    new LightObjImageLib;

    new TextFilter;
    new MetaMan;

    g_pScreenPane->InitializeSurfacePresentation();
    new PaletteLib;
    g_pScreenPane->LoadCursorResources();

    ShowWindow(m_hMainWnd, SW_SHOW);
    UpdateWindow(m_hMainWnd);
    SetForegroundWindow(m_hMainWnd);

    DestroyLoadingDialog();
    g_pScreenPane->SetPaneOrder(0, 0);
    g_pScreenPane->StartPresentation();

    g_mainUiLayerSlots.rootPaneLayerContext = new Layer;
    g_mainUiLayerSlots.effectPaneLayerContext = new Layer;
    g_mainUiLayerSlots.overlayPaneLayerContext = new Layer;
    g_pLayoutPaneLayer = new Layer;
    g_pStatusPaneLayer = new Layer;
    g_pIMEPaneLayer = new Layer;

    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext, 0);
    g_pScreenPane->SetLayerFrame(g_pLayoutPaneLayer, 0);
    g_pScreenPane->SetLayerFrame(g_pStatusPaneLayer, 0);
    g_pScreenPane->SetLayerFrame(g_pIMEPaneLayer, 0);

    new IMEPane;

    g_pScreenPane->HideCursor();
    PlayStartupLogoBinkFile();
    g_pTimerMgr->RefreshCurrentTick();

    typedef void (__thiscall BaramApp::*BaramAppCallback0)();
    FunctionObject0 *terminalCallback =
        new PlainMemberFunctionObject0<BaramAppCallback0, BaramApp>(
            &BaramApp::OpenTerminalPaneAfterStartupLogo, 0, static_cast<BaramApp *>(this));

    const wchar_t *startupLogoPath = L"NEXON.LGO";
    if (PathExistsViaStat(startupLogoPath)) {
        new LogoPane(startupLogoPath, terminalCallback);
    } else {
        g_pScreenPane->ShowCursor();
        new TerminalPane;
    }
}

// UID:0002H8 | by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md | Completion:90 | Confidence:92
void BaramApp::Shutdown()
{
    ApplicationPhaseState = 4;

    if (g_pEventMan)
        g_pEventMan->ShutdownPacketEventSource();

    delete g_pIMEPane;

    if (g_pScreenPane) {
        g_pScreenPane->DetachLayerFrame(g_pStatusPaneLayer);
        g_pScreenPane->DetachLayerFrame(g_pLayoutPaneLayer);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_pIMEPaneLayer);
    }

    delete g_pMainMenuPane;

    delete g_pIMEPaneLayer;
    g_pIMEPaneLayer = NULL;

    delete g_pStatusPaneLayer;
    g_pStatusPaneLayer = NULL;

    delete g_mainUiLayerSlots.overlayPaneLayerContext;
    g_mainUiLayerSlots.overlayPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.effectPaneLayerContext;
    g_mainUiLayerSlots.effectPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.rootPaneLayerContext;
    g_mainUiLayerSlots.rootPaneLayerContext = NULL;

    delete g_pLayoutPaneLayer;
    g_pLayoutPaneLayer = NULL;

    delete g_pEffectObjImageLib;
    delete g_pStaticObjImageLib;
    delete g_pNewHumanImageLib;
    delete g_pMonsterImageLib;
    delete g_pRidingImageLib;
    delete g_pMapTileImageLib;
    delete g_pItemObjImageLib;
    delete g_pLightObjImageLib;

    delete g_pIdleWatcher;

    g_packetSender->ForceTerminate();
    delete g_packetSender;

    delete g_pTextFilter;
    delete g_pMetaMan;

    Application::Shutdown();
}

// UID:0002Q2 | by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md | Completion:88 | Confidence:92
// Emitted code for this compiler-generated scalar deleting destructor is covered by [UID:00000V][BaramApp](by-class/BaramApp.md) and [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md).

// UID:0003P2 | by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md | Completion:88 | Confidence:93
// Compiler-emitted BaramApp primary/secondary vtable data is regenerated from
// [UID:00000V][BaramApp](by-class/BaramApp.md) class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HG][Application](by-file/Application.md) Application.cpp source route.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.

// UID:0003P4 | by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md | Completion:92 | Confidence:94
// Compiler-generated RTTI locator pointer and vtable for
// PlainMemberFunctionObject0<void (BaramApp::*)(), BaramApp>;
// regenerated from FunctionObjects template declarations and the
// BaramApp::OpenTerminalPaneAfterStartupLogo binding in Application::Startup().


// UID:0000YQ | by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md | Completion:86 | Confidence:91
// Compiler-emitted _AUTOBUF<wchar_t>/LObject cleanup wrapper for Application error text; this deleting-destructor range emits no hand-written Application source body.

// UID:0000YR | by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md | Completion:85 | Confidence:88
// Application lifecycle aggregate emits no standalone body; exact child pages in this range carry constructor, startup, cleanup, message-loop, helper, wrapper, and data reconstruction.
// UID:0002JX | by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md | Completion:88 | Confidence:91
errno_t __stdcall BuildExecutablePathForVersionInfo(wchar_t *destination,
                                                    rsize_t destinationCount = 0x104)
{
    wchar_t commandLine[0x104];
    wcscpy_s(commandLine, _countof(commandLine), GetCommandLineW());

    wchar_t delimiter = L' ';
    wchar_t *scan = commandLine;
    if (wcschr(commandLine, L'"') != NULL) {
        scan = commandLine + 1;
        delimiter = L'"';
    }

    wchar_t *terminator = wcschr(scan, delimiter);
    if (terminator != NULL) {
        *terminator = L'\0';
    }

    wchar_t *out = destination;
    for (wchar_t *cursor = commandLine; *cursor != L'\0'; ++cursor) {
        wchar_t ch = *cursor;
        if (ch == L'"') {
            do {
                ch = *++cursor;
            } while (ch == L'"');
        }
        *out++ = ch;
    }
    *out = L'\0';

    if (_wcsicmp(out - 4, L".exe") != 0) {
        return wcscat_s(destination, destinationCount, L".exe");
    }
    return 0;
}

// UID:0002JZ | by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md | Completion:88 | Confidence:91
WORD GetExecutableVersionLowWord()
{
    wchar_t executablePath[0x104];
    DWORD versionHandle = 0;
    UINT fixedInfoLength = 0;
    VS_FIXEDFILEINFO *fixedInfo = NULL;

    BuildExecutablePathForVersionInfo(executablePath);

    const DWORD versionInfoSize =
        g_pfnGetFileVersionInfoSizeW(executablePath, &versionHandle);
    if (versionInfoSize == 0) {
        return 0;
    }

    void *versionInfo = AllocateBufferMemory(versionInfoSize);
    if (g_pfnGetFileVersionInfoW(executablePath, 0, versionInfoSize, versionInfo) &&
        g_pfnVerQueryValueW(versionInfo, L"\\",
                            reinterpret_cast<void **>(&fixedInfo),
                            &fixedInfoLength)) {
        const WORD lowWord = LOWORD(fixedInfo->dwFileVersionLS);
        FreeBufferMemory(versionInfo);
        return lowWord;
    }

    FreeBufferMemory(versionInfo);
    return 0;
}

// UID:0002VI | by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md | Completion:89 | Confidence:92
static void FatalErrorDialogAndBreak(const wchar_t *message)
{
    Application *application = GetApplicationSingleton();
    MessageBoxW(application->GetMainWindowHandle(), message, L"Aborted", 0);
    PostQuitMessage(0);
    __loaddll(0);
    __debugbreak();
}

// UID:0000YT | by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md | Completion:88 | Confidence:91
// No first-draft body is emitted for CheckTimerSkewAndSendHeartbeat; UID0000YT documents the 0x40d-byte timer-skew and heartbeat behavior, but current evidence does not safely collapse packet byte writing, function-local static guards, crash diagnostic sender ownership, and g_pUserPane session-byte use into one source-quality helper body.

// UID:0000YV | by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md | Completion:89 | Confidence:92
static void DestroyDATFileMgr()
{
    delete g_pDATFileMgr;
}

// UID:0000YW | by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md | Completion:89 | Confidence:92
static void DestroyExceptionHandler()
{
    delete g_pCrashTarget;
}

// UID:00032B | by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md | Completion:88 | Confidence:92
Application *GetApplicationSingleton()
{
    return g_pApplication;
}

// UID:0000YX | by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md | Completion:90 | Confidence:94
// No first-draft body is emitted for LoadIndexedDATSeries; UID0000YX documents the verified DAT-series algorithm, but current evidence does not safely choose the formatter count/buffer source shape, DAT manager wrapper expression, and StringBase-to-fatal-dialog conversion needed for source-quality C++.


// UID:00047Z | by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md | Completion:90 | Confidence:94
// Shared pooled wide path-separator literal is emitted at source use sites such as version-resource root queries and path construction; no standalone data definition is emitted here.

// UID:000483 | by-memory/0x00612640-0x00612980.ApplicationOsAndRuntimeStringData.md | Completion:88 | Confidence:92
// Emitted source for this literal pool is covered by Application startup/OS/processor/timing code ([UID:0000HG][Application](by-file/Application.md)) and [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) FileErrorConstructor for L"File not found : %s"; this data page emits no standalone static string declarations.

// UID:000484 | by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md | Completion:87 | Confidence:90
// Application registry/display strings are pooled .rdata literals emitted at their documented source use sites; this range emits no standalone static string table.

// UID:000485 | by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md | Completion:88 | Confidence:91
// Application startup resource strings are pooled literals emitted by startup/DAT-loading use sites; this range emits no standalone static string table.

// UID:000487 | by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md | Completion:87 | Confidence:91
// Application patch, version, PasswordGuard, and error strings are pooled literals emitted at their source use sites; this broad range emits no standalone static string table.

// UID:00035N | by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md | Completion:90 | Confidence:94
int g_displayStartupWidth = 1024;
int g_displayStartupDrawType = 1;

// UID:00028Z | by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md | Completion:90 | Confidence:94
int g_applicationPhaseState = 0;
int g_isWindowedDisplayMode = 0;

// UID:000291 | by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md | Completion:89 | Confidence:92
DWORD g_timerSkewTimeGetTimeBaseline = 0;
DWORD g_timerSkewTickCountBaseline = 0;
__time64_t g_timerSkewTime64Baseline = 0;
DWORD g_timerSkewFileTimeSecondsBaseline = 0;
int g_timerSkewReportCount = 0;

// UID:000293 | by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md | Completion:88 | Confidence:91
// Combined Application OSVERSIONINFOW storage and formatted OS-label buffer emits no standalone declaration from this range; constructor-owned initialization and diagnostic-label use are documented here without guessing a byte blob or environment-state struct.

// UID:0002VU | by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md | Completion:88 | Confidence:91
// Heartbeat/timer-skew function-local state and MSVC local-static guard dwords for UID0000YT emit no standalone definitions; guard storage is compiler-generated and source statics belong inside the helper body if that body is later emitted.

// UID:0002VX | by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md | Completion:89 | Confidence:92
int g_applicationHeartbeatCheckCounter = 0;
int g_applicationMessageLoopThrottleCounter = 0;
int g_mouseWheelDeltaAccumulator = 0;

// UID:0003P5 | by-memory\0x0061d24c-0x0061d260.BaramAppLogoResourceString.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003OY | by-memory\0x00612574-0x00612580.ApplicationErrorStateVtableData.md | Completion:86 | Confidence:91 | Empty Emitter Marker
