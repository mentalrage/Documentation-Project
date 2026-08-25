// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O5
// Source by-file doc: by-file/StartupWindow.md
// UID:000288 | by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md | Completion:92 | Confidence:94
static const char *g_szBaramNoticeWndClass = "BaramNoticeWnd_Class";
static const char *g_szNoticeTitle = "Notice";

// UID:0000DZ | by-class/StartupWindow.md | Completion:92 | Confidence:94
#include "StartupWindow.h"

// UID:0002ZS | by-global/g_pStartupWindow.md | Completion:94 | Confidence:95
static StartupWindow *g_pStartupWindow;

template <>
Singleton<StartupWindow>::Singleton()
{
    g_pStartupWindow = static_cast<StartupWindow *>(this);
}

template <>
Singleton<StartupWindow>::~Singleton()
{
    g_pStartupWindow = NULL;
}

// UID:0002ZQ | by-global/g_startupWindowClassAtom.md | Completion:92 | Confidence:94
static ATOM g_startupWindowClassAtom;

// UID:0000SW | by-global/g_useEpfAssets.md | Completion:88 | Confidence:90
bool g_useEpfAssets = true;
// UID:0003XA | by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md | Completion:92 | Confidence:93
bool IsLegacyAssetMode()
{
    return !g_useEpfAssets;
}

// UID:0001OH | by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md | Completion:88 | Confidence:90
// Exact storage for g_useEpfAssets at 0x0066da97.
// The source declaration is emitted by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) g_useEpfAssets;
// do not duplicate the global definition from this one-byte storage child.

// UID:0004CQ | by-memory/0x005807d0-0x0058080c.StartupWindowConstructor.md | Completion:92 | Confidence:94
StartupWindow::StartupWindow(HINSTANCE instance)
{
    g_useEpfAssets = true;
    m_instance = instance;
    m_assetsLoaded = false;
    m_resultReady = false;
}

// UID:0004CR | by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md | Completion:92 | Confidence:94
StartupWindow::~StartupWindow()
{
    if (m_assetsLoaded) {
        if (m_backgroundImage != NULL) {
            delete m_backgroundImage;
        }

        for (int buttonIndex = 0; buttonIndex < 2; ++buttonIndex) {
            for (int imageIndex = 0; imageIndex < 3; ++imageIndex) {
                if (m_buttons[buttonIndex].images[imageIndex] != NULL) {
                    delete m_buttons[buttonIndex].images[imageIndex];
                }
            }
        }
    }
}

// UID:0004CS | by-memory/0x00580870-0x005810fd.StartupWindowRunUpdateCheck.md | Completion:88 | Confidence:90
int StartupWindow::RunUpdateCheck(bool *runUpdater)
{
    RECT windowRect = { 0, 0, 500, 430 };
    WNDCLASSEXA windowClass = {};

    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_CLASSDC;
    windowClass.lpfnWndProc = StartupWindowUpdateCheckWindowProc;
    windowClass.hInstance = GetModuleHandleW(NULL);
    windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    windowClass.lpszClassName = g_szBaramNoticeWndClass;

    const DWORD windowStyle = WS_POPUP | WS_CLIPCHILDREN;
    AdjustWindowRect(&windowRect, windowStyle, FALSE);

    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    RECT desktopRect;
    HWND desktopWindow = GetDesktopWindow();
    if (desktopWindow != NULL && GetWindowRect(desktopWindow, &desktopRect)) {
        OffsetRect(&windowRect,
                   desktopRect.left + (desktopRect.right - desktopRect.left) / 2 - (windowRect.right - windowRect.left) / 2 - windowRect.left,
                   desktopRect.top + (desktopRect.bottom - desktopRect.top) / 2 - (windowRect.bottom - windowRect.top) / 2 - windowRect.top);
        x = windowRect.left;
        y = windowRect.top;
    }

    if (g_startupWindowClassAtom == 0) {
        g_startupWindowClassAtom = RegisterClassExA(&windowClass);
        if (g_startupWindowClassAtom == 0) {
            return kAbortStartup;
        }
    }

    m_noticeWindow = CreateWindowExA(WS_EX_APPWINDOW,
                                    g_szBaramNoticeWndClass,
                                    g_szNoticeTitle,
                                    windowStyle,
                                    x,
                                    y,
                                    windowRect.right - windowRect.left,
                                    windowRect.bottom - windowRect.top,
                                    GetDesktopWindow(),
                                    NULL,
                                    windowClass.hInstance,
                                    NULL);
    if (m_noticeWindow == NULL) {
        return kAbortStartup;
    }

    ShowWindow(m_noticeWindow, SW_SHOW);
    UpdateWindow(m_noticeWindow);

    BrowserWindow *browser = new BrowserWindow(m_instance, m_noticeWindow, CRect(17, 96, 484, 336), "http://www.nexustk.com/news/news.asp");
    browser->SetVisible(true);

    DWORD localVersion = 0;
    DWORD valueType = REG_DWORD;
    DWORD valueSize = sizeof(localVersion);
    HKEY key = NULL;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\KRU\\NexusTK", 0, KEY_READ, &key) == ERROR_SUCCESS) {
        RegQueryValueExW(key, L"updvr", NULL, &valueType, reinterpret_cast<BYTE *>(&localVersion), &valueSize);
        RegCloseKey(key);
    }

    std::string responseText;
    curl_global_init(CURL_GLOBAL_ALL);
    for (int attempt = 0; attempt < 2 && responseText.empty(); ++attempt) {
        CURL *curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, "https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseText);
        if (curl_easy_perform(curl) != CURLE_OK) {
            responseText.clear();
        }
        curl_easy_cleanup(curl);
    }

    bool versionMatches = false;
    wchar_t minimapVersion[34] = {};
    if (!responseText.empty()) {
        int versionKey = AnsiSmallStringFindFrom(responseText, "version", 0);
        int versionColon = AnsiSmallStringFindFrom(responseText, ":", versionKey + 1);
        int versionStart = AnsiSmallStringFindFrom(responseText, "\n", versionColon + 1);
        int versionEnd = AnsiSmallStringFindFrom(responseText, "\n", versionStart + 1);
        int remoteVersion = atoi(responseText.substr(versionStart + 1, versionEnd - versionStart - 1).c_str());
        versionMatches = (localVersion == static_cast<DWORD>(remoteVersion));

        int minimapKey = AnsiSmallStringFindFrom(responseText, "minimap", 0);
        if (minimapKey >= 0) {
            int minimapColon = AnsiSmallStringFindFrom(responseText, ":", minimapKey + 1);
            int minimapStart = AnsiSmallStringFindFrom(responseText, "\n", minimapColon + 1);
            int minimapEnd = AnsiSmallStringFindFrom(responseText, "\n", minimapStart + 1);
            std::wstring wideValue = StartupAnsiRangeToWideString(responseText.data() + minimapStart + 1, responseText.data() + minimapEnd);
            wcscpy_s(minimapVersion, 34, wideValue.c_str());
        }
    }

    if (_wcsicmp(g_pMiniMapVersionManager->GetVersionString(), minimapVersion) != 0) {
        std::string hashListText;
        for (int attempt = 0; attempt < 2 && hashListText.empty(); ++attempt) {
            CURL *curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, "https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt");
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &hashListText);
            if (curl_easy_perform(curl) != CURLE_OK) {
                hashListText.clear();
            }
            curl_easy_cleanup(curl);
        }
        if (!hashListText.empty()) {
            std::wstring wideHashList = StartupAnsiRangeToWideString(hashListText.data(), hashListText.data() + hashListText.length());
            g_pMiniMapVersionManager->UpdateHashList(minimapVersion, wideHashList.c_str(), true);
        }
    }

    m_resultReady = true;
    int result = kAbortStartup;
    if (versionMatches) {
        *runUpdater = false;
        MSG message;
        while (GetMessageA(&message, NULL, 0, 0) > 0) {
            TranslateMessage(&message);
            if (message.message == WM_CLOSE) {
                break;
            }
            if (message.message == WM_USER + 11) {
                result = static_cast<int>(message.wParam);
                break;
            }
            DispatchMessageA(&message);
        }
    } else {
        *runUpdater = true;
        result = kAbortStartup;
    }

    delete browser;
    ShowWindow(m_noticeWindow, SW_HIDE);
    DestroyWindow(m_noticeWindow);
    m_noticeWindow = NULL;
    return result;
}

// UID:0004CT | by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md | Completion:88 | Confidence:90
static LRESULT CALLBACK StartupWindowUpdateCheckWindowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    StartupWindow *startupWindow = g_pStartupWindow;
    if (startupWindow == NULL) {
        return DefWindowProcA(window, message, wParam, lParam);
    }

    if (message == WM_KEYDOWN || message == WM_SYSKEYDOWN) {
        if (wParam == VK_SPACE || wParam == VK_RETURN) {
            PostMessageA(window, WM_USER + 11, 1, 0);
        } else if (wParam == VK_ESCAPE) {
            PostMessageA(window, WM_CLOSE, 0, 0);
        } else if (wParam == VK_F4 && (GetAsyncKeyState(VK_LMENU) || GetAsyncKeyState(VK_RMENU))) {
            PostMessageA(window, WM_CLOSE, 0, 0);
        }
    }

    switch (message) {
    case WM_PAINT:
        if (GetUpdateRect(window, NULL, FALSE)) {
            PAINTSTRUCT paint;
            HDC dc = BeginPaint(window, &paint);
            if (!startupWindow->m_assetsLoaded) {
                StartupNoticeLoadAssets(startupWindow, dc);
            }
            StartupNoticeDrawPcxImage(dc, startupWindow->m_backgroundImage, 0, 0);
            for (int index = 0; index < 2; ++index) {
                const StartupNoticeButton &button = startupWindow->m_buttons[index];
                StartupNoticeDrawPcxImage(dc, button.images[button.state], button.rect.left, button.rect.top);
            }
            EndPaint(window, &paint);
        }
        return 1;

    case WM_MOUSEMOVE: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button < 0) {
            StartupNoticeResetButtonStates(startupWindow);
        } else if ((wParam & MK_LBUTTON) != 0) {
            StartupNoticeSetButtonState(startupWindow, button, 1);
        } else if (button == 0) {
            StartupNoticeSetButtonState(startupWindow, 0, 2);
        }

        RECT linkRect;
        SetRect(&linkRect, 0, 0, 217, 64);
        OffsetRect(&linkRect, 147, 0);
        POINT cursorPoint;
        cursorPoint.x = LOWORD(lParam);
        cursorPoint.y = HIWORD(lParam);
        SetCursor(LoadCursorA(NULL, (PtInRect(&linkRect, cursorPoint) || button >= 0) ? MAKEINTRESOURCEA(0x92) : IDC_ARROW));
        return DefWindowProcA(window, message, wParam, lParam);
    }

    case WM_LBUTTONUP: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button >= 0) {
            StartupNoticePostButtonResult(startupWindow, button);
        }
        StartupNoticeResetButtonStates(startupWindow);
        return 1;
    }

    case WM_LBUTTONDOWN: {
        int button = StartupNoticeHitTestButton(startupWindow, LOWORD(lParam), HIWORD(lParam));
        if (button >= 0) {
            StartupNoticeSetButtonState(startupWindow, button, 1);
        }
        RECT linkRect;
        SetRect(&linkRect, 0, 0, 217, 64);
        OffsetRect(&linkRect, 147, 0);
        POINT linkPoint;
        linkPoint.x = LOWORD(lParam);
        linkPoint.y = HIWORD(lParam);
        if (PtInRect(&linkRect, linkPoint)) {
            ShellExecuteA(NULL, NULL, "http://www.nexustk.com", NULL, NULL, SW_SHOWNORMAL);
        }
        return 1;
    }
    }

    return DefWindowProcA(window, message, wParam, lParam);
}

// UID:0004CU | by-memory/0x005815b0-0x0058165a.StartupNoticePostButtonResult.md | Completion:88 | Confidence:91
static void StartupNoticePostButtonResult(StartupWindow *startupWindow, int buttonIndex)
{
    SetCursor(LoadCursorA(NULL, IDC_ARROW));

    if (buttonIndex == 1) {
        StartupNoticeButton &button = startupWindow->m_buttons[1];
        if (button.state != 1) {
            button.state = 1;
            InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
        }
        PostMessageA(startupWindow->m_noticeWindow, WM_USER + 11, 2, 0);
    } else if (buttonIndex == 0) {
        StartupNoticeSetButtonState(startupWindow, 0, 1);
        PostMessageA(startupWindow->m_noticeWindow, WM_USER + 11, 1, 0);
    }
}

// UID:0004CV | by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md | Completion:88 | Confidence:92
HINSTANCE StartupWindow::GetInstanceHandle() const
{
    return m_instance;
}

// UID:0004CW | by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md | Completion:89 | Confidence:92
static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        StartupNoticeButton &button = startupWindow->m_buttons[index];
        if (button.state > 0) {
            button.state = 0;
            InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
        }
    }
}

// UID:0004CX | by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md | Completion:88 | Confidence:91
static void StartupNoticeSetButtonState(StartupWindow *startupWindow, int buttonIndex, int state)
{
    StartupNoticeButton &button = startupWindow->m_buttons[buttonIndex];
    if (button.state != state) {
        button.state = state;
        InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
    }
}

// UID:0004CY | by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md | Completion:88 | Confidence:92
static int StartupNoticeHitTestButton(StartupWindow *startupWindow, int x, int y)
{
    POINT point = { x, y };
    for (int index = 0; index < 2; ++index) {
        if (PtInRect(&startupWindow->m_buttons[index].rect, point)) {
            return index;
        }
    }
    return -1;
}

// UID:0004CZ | by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md | Completion:88 | Confidence:91
static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[index].rect, FALSE);
    }
}

// UID:0004D0 | by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md | Completion:88 | Confidence:91
static void StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)
{
    InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[buttonIndex].rect, FALSE);
}

// UID:0004D1 | by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md | Completion:92 | Confidence:94
static void StartupNoticeLoadAssets(StartupWindow *startupWindow, HDC dc)
{
    if (startupWindow->m_assetsLoaded) {
        return;
    }

    startupWindow->m_assetsLoaded = true;
    startupWindow->m_backgroundImage = LoadPcxImage(dc, "brm_main.pcx", -1);

    StartupNoticeButton &startButton = startupWindow->m_buttons[0];
    startButton.images[0] = LoadPcxImage(dc, "brm_st_a.pcx", -1);
    startButton.images[1] = LoadPcxImage(dc, "brm_st_b.pcx", -1);
    startButton.images[2] = LoadPcxImage(dc, "brm_st_c.pcx", -1);
    InitRectBounds(&startButton.rect, 183, 348, 0, 0);
    startButton.rect.right = startButton.rect.left + startButton.images[0]->GetWidth();
    startButton.rect.bottom = startButton.rect.top + startButton.images[0]->GetHeight();
    startButton.state = 0;

    StartupNoticeButton &exitButton = startupWindow->m_buttons[1];
    exitButton.images[0] = LoadPcxImage(dc, "brm_ex_a.pcx", -1);
    exitButton.images[1] = NULL;
    exitButton.images[2] = LoadPcxImage(dc, "brm_ex_b.pcx", -1);
    InitRectBounds(&exitButton.rect, 474, 0, 0, 0);
    exitButton.rect.right = exitButton.rect.left + exitButton.images[0]->GetWidth();
    exitButton.rect.bottom = exitButton.rect.top + exitButton.images[0]->GetHeight();
    exitButton.state = 0;
}

// UID:0004D2 | by-memory/0x005819d0-0x00581b75.StartupNoticeCreateWindowRaw.md | Completion:88 | Confidence:90
static bool StartupNoticeCreateWindow(StartupWindow *startupWindow)
{
    WNDCLASSEXA windowClass = {};
    windowClass.cbSize = sizeof(windowClass);
    windowClass.style = CS_CLASSDC;
    windowClass.lpfnWndProc = StartupWindowUpdateCheckWindowProc;
    windowClass.hInstance = GetModuleHandleW(NULL);
    windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    windowClass.lpszClassName = g_szBaramNoticeWndClass;

    const DWORD windowStyle = WS_POPUP | WS_CLIPCHILDREN;
    RECT windowRect = { 0, 0, 500, 430 };
    AdjustWindowRect(&windowRect, windowStyle, FALSE);

    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;
    HWND desktopWindow = GetDesktopWindow();
    RECT desktopRect;
    if (desktopWindow != NULL && GetWindowRect(desktopWindow, &desktopRect)) {
        OffsetRect(&windowRect,
                   desktopRect.left + (desktopRect.right - desktopRect.left) / 2 - (windowRect.right - windowRect.left) / 2 - windowRect.left,
                   desktopRect.top + (desktopRect.bottom - desktopRect.top) / 2 - (windowRect.bottom - windowRect.top) / 2 - windowRect.top);
        x = windowRect.left;
        y = windowRect.top;
    }

    if (g_startupWindowClassAtom == 0) {
        g_startupWindowClassAtom = RegisterClassExA(&windowClass);
        if (g_startupWindowClassAtom == 0) {
            return false;
        }
    }

    startupWindow->m_noticeWindow = CreateWindowExA(WS_EX_APPWINDOW,
                                                   g_szBaramNoticeWndClass,
                                                   g_szNoticeTitle,
                                                   windowStyle,
                                                   x,
                                                   y,
                                                   windowRect.right - windowRect.left,
                                                   windowRect.bottom - windowRect.top,
                                                   GetDesktopWindow(),
                                                   NULL,
                                                   windowClass.hInstance,
                                                   NULL);
    return startupWindow->m_noticeWindow != NULL;
}

// UID:0001IP | by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md | Completion:90 | Confidence:92
static size_t CurlWriteCallback(char *contents, size_t size, size_t nmemb, void *userData)
{
    std::string *responseText = static_cast<std::string *>(userData);
    responseText->append(contents);
    return size * nmemb;
}

// UID:0004D3 | by-memory/0x00581cf0-0x00581d30.StartupAnsiRangeToWideString.md | Completion:88 | Confidence:91
static std::wstring StartupAnsiRangeToWideString(const char *first, const char *last)
{
    std::wstring text;
    text.reserve(last - first);

    for (const char *it = first; it != last; ++it) {
        text.push_back(static_cast<wchar_t>(*it));
    }

    return text;
}

// UID:0004D5 | by-memory/0x00581dc0-0x00581e35.StartupNoticeDrawPcxImage.md | Completion:89 | Confidence:91
static void StartupNoticeDrawPcxImage(HDC targetDc, DIBitmap *image, int x, int y)
{
    HDC imageDc = CreateCompatibleDC(targetDc);
    if (image != NULL && image->GetBitmapHandle() != NULL) {
        int width = image->GetWidth();
        int height = image->GetHeight();
        HBITMAP bitmap = image->GetBitmapHandle();

        SelectObject(imageDc, bitmap);
        BitBlt(targetDc, x, y, width, height, imageDc, 0, 0, SRCCOPY);
    }

    SelectObject(imageDc, NULL);
    DeleteDC(imageDc);
}

// UID:0004D6 | by-memory/0x00581e40-0x00581f46.AnsiSmallStringFindFrom.md | Completion:88 | Confidence:91
static int AnsiSmallStringFindFrom(const std::string &text, const char *needle, unsigned int offset)
{
    std::string::size_type found = text.find(needle, offset);
    return found == std::string::npos ? -1 : static_cast<int>(found);
}


// UID:000484 | by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md | Completion:87 | Confidence:90
// Application registry/display strings are pooled .rdata literals emitted at their documented source use sites; this range emits no standalone static string table.

// UID:00026K | by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md | Completion:88 | Confidence:92
// StartupWindow read-only strings, vtable, and RTTI/COL data are not a
// standalone handwritten source table. The class declaration, exact method
// bodies, pointer declarations, and literal uses should regenerate this data.

// UID:0003G1 | by-memory\0x0060d94c-0x0060d958.SharedVersionJsonKey.md | Completion:88 | Confidence:93 | Empty Emitter Marker
