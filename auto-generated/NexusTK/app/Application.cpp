// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// Source by-file UID: 0000HG
// Source by-file doc: by-file/Application.md
// UID:00000D | by-class/Application.md
// UID:0002GZ | by-memory/0x00463970-0x004639c4.ApplicationDestructor.md
Application::~Application()
{
    if (m_hSingleInstanceMutex != NULL)
    {
        ::CloseHandle(m_hSingleInstanceMutex);
        m_hSingleInstanceMutex = NULL;
    }

    m_osVersionText.clear();
    m_executablePath.clear();
    m_defaultMsgHandler.~MSGHandler();
    g_pApplication = NULL;
}

// UID:0002H4 | by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md
bool Application::IsExitRequested() const
{
    return m_exitRequested != 0;
}

// UID:000199 | by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md
int Application::RegisterChangeListener(void* listener, int messageType, char scopeByte)
{
    return g_pChangeMan->Register(this, listener, messageType, scopeByte);
}

int Application::UnregisterChangeListener(void* listener, int messageType, char scopeByte)
{
    return g_pChangeMan->UnregisterFiltered(this, listener, messageType, scopeByte);
}

// UID:00019B | by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md
bool Application::ForwardMessage(void* message)
{
    return g_pChangeMan->DispatchChangeMessage(this, message) != 0;
}

// UID:0002GM | by-memory/0x004651c0-0x004651c4.ApplicationGetInstanceHandle.md
HINSTANCE Application::GetInstanceHandle() const
{
    return m_hInstance;
}

// UID:0002GN | by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md
HWND Application::GetMainWindowHandle() const
{
    return m_hMainWnd;
}

// UID:0002GO | by-memory/0x004651e0-0x004651e7.ApplicationIsRunning.md
bool Application::IsRunning() const
{
    return m_isRunning != 0;
}

// UID:0002GR | by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md
MSGHandler* Application::ExchangeMSGHandler(MSGHandler* handler)
{
    MSGHandler* previous = m_pMessageDispatcher;

    AutoCriticalSection lock(g_applicationCriticalSection);
    m_pMessageDispatcher = handler;

    return previous;
}

// UID:0002GS | by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md
POINT Application::MapFromScreen(const POINT& point) const
{
    POINT mapped;

    if (m_screenHeight == g_baseScreenHeight && m_screenWidth == g_baseScreenWidth)
    {
        mapped = point;
    }
    else
    {
        mapped.x = static_cast<LONG>((point.x * g_baseScreenWidth) / static_cast<float>(m_screenWidth) + 0.5f);
        mapped.y = static_cast<LONG>((point.y * g_baseScreenHeight) / static_cast<float>(m_screenHeight) + 0.5f);
    }

    return mapped;
}

// UID:0002GT | by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md
POINT Application::MapToScreen(const POINT& point) const
{
    POINT mapped;

    if (m_screenHeight == g_baseScreenHeight && m_screenWidth == g_baseScreenWidth)
    {
        mapped = point;
    }
    else
    {
        mapped.x = static_cast<LONG>((point.x * m_screenWidth) / static_cast<float>(g_baseScreenWidth) + 0.5f);
        mapped.y = static_cast<LONG>((point.y * m_screenHeight) / static_cast<float>(g_baseScreenHeight) + 0.5f);
    }

    return mapped;
}

// UID:0002GU | by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md
errno_t Application::CopyWorldName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_worldName);
}

// UID:0002GV | by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md
errno_t Application::CopyPlayerName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_playerName);
}

// UID:0002GW | by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md
BOOL Application::DestroyLoadingDialog()
{
    return ::DestroyWindow(m_hLoadingDlg);
}

// UID:0002GX | by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md
void Application::SendShutdownMessage()
{
    ChangeMessage message(reinterpret_cast<void*>(0x676f6f67));
    message.SetDword(0);
    ForwardMessage(&message);
}

// UID:00000V | by-class/BaramApp.md
class BaramApp : public Application
{
public:
    BaramApp();
    virtual ~BaramApp();

    virtual void OnActivate();
    virtual void OnDeactivate();
};

// UID:0002GJ | by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md
void BaramApp::OnActivate()
{
    if (m_activationTransitionGuard)
        return;

    ResumeEventTimerOwner();

    if (!g_applicationMinimized && g_pMapPane != nullptr)
    {
        g_pApplication->SetMapPaneActive(true);
        g_pMapPane->ResumeDisplay();
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_RESTORE);
    }

    ResumeBackgroundWork();
    ResumeAudioIfAllowed();
}

// UID:0002GK | by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md
void BaramApp::OnDeactivate()
{
    if (m_activationTransitionGuard)
        return;

    m_isActive = false;

    if (!g_applicationMinimized && g_pMapPane != nullptr)
    {
        g_pApplication->SetMapPaneActive(false);
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_MINIMIZE);
        g_pMapPane->PauseDisplay();
    }

    PauseEventTimerOwner();
    PauseBackgroundWork();
    CancelParcelWalkIfActive();
    PauseAudioIfAllowed();
}

// UID:000294 | by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md
Application* g_pApplication = NULL;

// UID:0000YX | by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md
static bool LoadIndexedDATSeries(const wchar_t* basePath)
{
    wchar_t fileName[64];

    for (int index = 0; index < 99; ++index) {
        swprintf_s(fileName, L"%s%d.DAT", basePath, index);

        FILE* stream = NULL;
        _wfopen_s(&stream, fileName, L"rb");
        if (stream == NULL) {
            break;
        }

        fclose(stream);

        if (!g_pDATFileMgr->LoadDATFile(fileName)) {
            wchar_t message[128];
            swprintf_s(message, L"File not found : %s", fileName);
            FatalError(message);
        }
    }

    return true;
}
