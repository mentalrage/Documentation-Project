// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HV
// Source by-file doc: by-file/Browser.md
// UID:00000Q | by-class/AutoInit.md | Completion:94 | Confidence:96
namespace
{
class AutoInit
{
public:
    AutoInit()
    {
        OleInitialize(NULL);
    }

    virtual ~AutoInit();
};
}
// UID:0000ZE | by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md | Completion:95 | Confidence:98
AutoInit::~AutoInit()
{
    OleUninitialize();
}

// UID:000013 | by-class/Browser.md | Completion:90 | Confidence:93
class Browser :
    public IOleClientSite,
    public IOleInPlaceSite,
    public IDispatch,
    public IDocHostUIHandler,
    public IDocHostShowUI
{
public:
    Browser();
    Browser(const wchar_t *initialUrl);
    virtual ~Browser();

    STDMETHOD(QueryInterface)(REFIID riid, void **ppvObject);
    STDMETHOD_(ULONG, AddRef)();
    STDMETHOD_(ULONG, Release)();

    // IOleClientSite
    STDMETHOD(SaveObject)();
    STDMETHOD(GetMoniker)(DWORD assign, DWORD whichMoniker, IMoniker **moniker);
    STDMETHOD(GetContainer)(IOleContainer **container);
    STDMETHOD(ShowObject)();
    STDMETHOD(OnShowWindow)(BOOL show);
    STDMETHOD(RequestNewObjectLayout)();

    // IOleWindow / IOleInPlaceSite
    STDMETHOD(GetWindow)(HWND *hwnd);
    STDMETHOD(ContextSensitiveHelp)(BOOL enterMode);
    STDMETHOD(CanInPlaceActivate)();
    STDMETHOD(OnInPlaceActivate)();
    STDMETHOD(OnUIActivate)();
    STDMETHOD(GetWindowContext)(IOleInPlaceFrame **frame,
                                IOleInPlaceUIWindow **doc,
                                LPRECT posRect,
                                LPRECT clipRect,
                                LPOLEINPLACEFRAMEINFO frameInfo);
    STDMETHOD(Scroll)(SIZE scrollExtant);
    STDMETHOD(OnUIDeactivate)(BOOL undoable);
    STDMETHOD(OnInPlaceDeactivate)();
    STDMETHOD(DiscardUndoState)();
    STDMETHOD(DeactivateAndUndo)();
    STDMETHOD(OnPosRectChange)(LPCRECT posRect);

    // IDispatch / DWebBrowserEvents2 sink
    STDMETHOD(GetTypeInfoCount)(UINT *count);
    STDMETHOD(GetTypeInfo)(UINT typeInfo, LCID lcid, ITypeInfo **info);
    STDMETHOD(GetIDsOfNames)(REFIID iid, LPOLESTR *names, UINT count, LCID lcid, DISPID *dispids);
    STDMETHOD(Invoke)(DISPID dispidMember,
                      REFIID iid,
                      LCID lcid,
                      WORD flags,
                      DISPPARAMS *params,
                      VARIANT *result,
                      EXCEPINFO *exceptionInfo,
                      UINT *argError);

    // IDocHostUIHandler
    STDMETHOD(ShowContextMenu)(DWORD id, POINT *pt, IUnknown *commandTarget, IDispatch *dispatchObject);
    STDMETHOD(GetHostInfo)(DOCHOSTUIINFO *info);
    STDMETHOD(ShowUI)(DWORD id,
                      IOleInPlaceActiveObject *activeObject,
                      IOleCommandTarget *commandTarget,
                      IOleInPlaceFrame *frame,
                      IOleInPlaceUIWindow *doc);
    STDMETHOD(HideUI)();
    STDMETHOD(UpdateUI)();
    STDMETHOD(EnableModeless)(BOOL enable);
    STDMETHOD(OnDocWindowActivate)(BOOL activate);
    STDMETHOD(OnFrameWindowActivate)(BOOL activate);
    STDMETHOD(ResizeBorder)(LPCRECT border, IOleInPlaceUIWindow *uiWindow, BOOL frameWindow);
    STDMETHOD(TranslateAccelerator)(LPMSG msg, const GUID *commandGroup, DWORD commandId);
    STDMETHOD(GetOptionKeyPath)(LPOLESTR *key, DWORD reserved);
    STDMETHOD(GetDropTarget)(IDropTarget *dropTarget, IDropTarget **resultDropTarget);
    STDMETHOD(GetExternal)(IDispatch **dispatchObject);
    STDMETHOD(TranslateUrl)(DWORD translate, OLECHAR *urlIn, OLECHAR **urlOut);
    STDMETHOD(FilterDataObject)(IDataObject *dataObject, IDataObject **resultDataObject);

    // IDocHostShowUI
    STDMETHOD(ShowMessage)(HWND hwnd,
                           LPOLESTR text,
                           LPOLESTR caption,
                           DWORD type,
                           LPOLESTR helpFile,
                           DWORD helpContext,
                           LRESULT *result);
    STDMETHOD(ShowHelp)(HWND hwnd,
                        LPOLESTR helpFile,
                        UINT command,
                        DWORD data,
                        POINT mouse,
                        IDispatch *dispatchObject);

    void Navigate(const wchar_t *url);

private:
    HWND m_hWnd;
    CComQIPtr<IWebBrowser2> m_webBrowser;
    DWORD m_adviseCookie;
    wchar_t m_allowedUrlPrefix[0x101];
    unsigned char m_showBrowserAfterLoad;
    long m_pendingDownloadCount;
    wchar_t *m_navigationBuffer;
    unsigned short m_stateFlags;
    WideString m_currentUrl;

// UID:00032Y | by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md | Completion:91 | Confidence:93
Browser::~Browser()
{
    delete [] m_navigationBuffer;
    ::ShowCursor(FALSE);

    if (m_webBrowser != NULL)
    {
        UnadviseConnectionPoint(m_webBrowser, DIID_DWebBrowserEvents2, m_adviseCookie);
        m_webBrowser.Release();
    }

    if (m_hWnd != NULL)
        ::DestroyWindow(m_hWnd);
}

// UID:00032Z | by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md | Completion:89 | Confidence:92
HRESULT Browser::QueryInterface(REFIID riid, void **ppvObject)
{
    if (IsEqualIID(riid, IID_IOleClientSite))
    {
        *ppvObject = static_cast<IOleClientSite *>(this);
        return S_OK;
    }

    if (IsEqualIID(riid, IID_IUnknown))
    {
        *ppvObject = static_cast<IOleClientSite *>(this);
        return S_OK;
    }

    if (IsEqualIID(riid, IID_IOleInPlaceSite))
    {
        *ppvObject = static_cast<IOleInPlaceSite *>(this);
        return S_OK;
    }

    if (IsEqualIID(riid, IID_IDispatch))
    {
        *ppvObject = static_cast<IDispatch *>(this);
        return S_OK;
    }

    if (IsEqualIID(riid, DIID_DWebBrowserEvents2))
    {
        *ppvObject = static_cast<IDispatch *>(this);
        return S_OK;
    }

    if (IsEqualIID(riid, IID_IOleWindow))
    {
        *ppvObject = static_cast<IOleWindow *>(static_cast<IOleInPlaceSite *>(this));
        return S_OK;
    }

    *ppvObject = 0;
    return E_NOINTERFACE;
}

// UID:000330 | by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md | Completion:88 | Confidence:91
ULONG STDMETHODCALLTYPE Browser::AddRef()
{
    return 2;
}

ULONG STDMETHODCALLTYPE Browser::Release()
{
    return 1;
}

HRESULT STDMETHODCALLTYPE Browser::SaveObject()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetMoniker(DWORD /*assign*/, DWORD /*whichMoniker*/, IMoniker ** /*moniker*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetContainer(IOleContainer ** /*container*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::ShowObject()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnShowWindow(BOOL /*show*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::RequestNewObjectLayout()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetWindow(HWND *hwnd)
{
    *hwnd = m_hWnd;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::ContextSensitiveHelp(BOOL /*enterMode*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::CanInPlaceActivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::OnInPlaceActivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::OnUIActivate()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetWindowContext(IOleInPlaceFrame ** /*frame*/,
                                                    IOleInPlaceUIWindow ** /*doc*/,
                                                    LPRECT posRect,
                                                    LPRECT clipRect,
                                                    LPOLEINPLACEFRAMEINFO /*frameInfo*/)
{
    ::GetClientRect(m_hWnd, posRect);
    ::GetClientRect(m_hWnd, clipRect);
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::Scroll(SIZE /*scrollExtant*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnUIDeactivate(BOOL /*undoable*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnInPlaceDeactivate()
{
    return S_OK;
}

HRESULT STDMETHODCALLTYPE Browser::DiscardUndoState()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::DeactivateAndUndo()
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::OnPosRectChange(LPCRECT /*posRect*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetTypeInfoCount(UINT * /*count*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetTypeInfo(UINT /*typeInfo*/, LCID /*lcid*/, ITypeInfo ** /*info*/)
{
    return E_NOTIMPL;
}

HRESULT STDMETHODCALLTYPE Browser::GetIDsOfNames(REFIID /*iid*/,
                                                 LPOLESTR * /*names*/,
                                                 UINT /*count*/,
                                                 LCID /*lcid*/,
                                                 DISPID * /*dispids*/)
{
    return E_NOTIMPL;
}

// UID:000331 | by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md | Completion:88 | Confidence:90
HRESULT STDMETHODCALLTYPE Browser::Invoke(DISPID dispidMember,
                                          REFIID,
                                          LCID,
                                          WORD,
                                          DISPPARAMS *params,
                                          VARIANT *,
                                          EXCEPINFO *,
                                          UINT *)
{
    switch (dispidMember)
    {
    case kDispIdDownloadComplete:
        if (--m_pendingDownloadCount <= 0)
        {
            if (m_showBrowserAfterLoad)
            {
                ShowCursor(TRUE);
                ShowWindow(m_hWnd, SW_SHOW);
                UpdateWindow(m_hWnd);
                m_showBrowserAfterLoad = false;

                browser::Notification *notification = new browser::Notification(0, NULL);
                PostApplicationNotification(kBrowserNotificationChannel, notification);
            }
            m_pendingDownloadCount = 0;
        }
        return S_OK;

    case kDispIdDownloadBegin:
        if (m_pendingDownloadCount <= 0)
            m_pendingDownloadCount = 0;
        ++m_pendingDownloadCount;
        return S_OK;

    case kDispIdBeforeNavigate2:
    {
        const wchar_t *url = V_BSTR(V_VARIANTREF(&params->rgvarg[5]));
        VARIANT_BOOL *cancel = V_BOOLREF(&params->rgvarg[0]);

        if (wcsstr(url, L"close()") != NULL)
        {
            PostThreadMessageA(g_pBrowserThread->ThreadId(), kBrowserThreadCloseMessage, 0, 0);
            Navigate(L"about:blank");
            *cancel = (VARIANT_BOOL)1;
            return S_OK;
        }

        if (wcsstr(url, L"res:") != NULL)
        {
            PostThreadMessageA(g_pBrowserThread->ThreadId(), kBrowserThreadCloseMessage, 0, 0);
        m_currentUrl.assign(g_pLanguageMan->GetLocalizedString(235));
            return S_OK;
        }

        if (m_allowedUrlPrefix[0] != L'\0' && wcsstr(url, m_allowedUrlPrefix) != url)
            *cancel = (VARIANT_BOOL)1;
        return S_OK;
    }

    case kDispIdNavigateComplete2:
        if (m_allowedUrlPrefix[0] != L'\0')
            return S_OK;
        *V_BOOLREF(&params->rgvarg[0]) = (VARIANT_BOOL)1;
        return S_OK;

    case kDispIdNewWindow2:
        *V_BOOLREF(&params->rgvarg[0]) = (VARIANT_BOOL)0;
        PostBrowserNotification(1, m_currentUrl.c_str());
        return S_OK;

    case kDispIdWindowClosing:
        *V_BOOLREF(&params->rgvarg[0]) = (VARIANT_BOOL)1;
        return S_OK;

    default:
        return DISP_E_MEMBERNOTFOUND;
    }
}

// UID:000332 | by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md | Completion:88 | Confidence:91
STDMETHODIMP Browser::ShowContextMenu(DWORD, POINT *, IUnknown *, IDispatch *)
{
    return S_OK;
}

STDMETHODIMP Browser::GetHostInfo(DOCHOSTUIINFO *info)
{
    info->cbSize = sizeof(DOCHOSTUIINFO);
    info->dwFlags =
        DOCHOSTUIFLAG_DIALOG |
        DOCHOSTUIFLAG_DISABLE_HELP_MENU |
        DOCHOSTUIFLAG_NO3DBORDER |
        DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE |
        DOCHOSTUIFLAG_FLAT_SCROLLBAR |
        DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION;
    return S_OK;
}

STDMETHODIMP Browser::ShowUI(DWORD,
                             IOleInPlaceActiveObject *,
                             IOleCommandTarget *,
                             IOleInPlaceFrame *,
                             IOleInPlaceUIWindow *)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::HideUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::UpdateUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::EnableModeless(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::OnDocWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::OnFrameWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::ResizeBorder(LPCRECT, IOleInPlaceUIWindow *, BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::TranslateAccelerator(LPMSG, const GUID *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::GetOptionKeyPath(LPOLESTR *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::GetDropTarget(IDropTarget *, IDropTarget **)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::GetExternal(IDispatch **dispatch)
{
    *dispatch = 0;
    return E_NOTIMPL;
}

STDMETHODIMP Browser::TranslateUrl(DWORD, OLECHAR *, OLECHAR **)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::FilterDataObject(IDataObject *, IDataObject **)
{
    return E_NOTIMPL;
}

STDMETHODIMP Browser::ShowMessage(HWND,
                                  LPOLESTR,
                                  LPOLESTR,
                                  DWORD,
                                  LPOLESTR,
                                  DWORD,
                                  LRESULT *)
{
    return S_OK;
}

STDMETHODIMP Browser::ShowHelp(HWND, LPOLESTR, UINT, DWORD, POINT, IDispatch *)
{
    return S_OK;
}

// UID:000338 | by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md | Completion:88 | Confidence:91
// Emitted code for this range is covered by [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md).

// UID:00033K | by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md | Completion:92 | Confidence:94
void Browser::Navigate(const wchar_t *url)
{
    if (m_webBrowser == NULL)
        return;

    CComVariant postData;
    BSTR browserUrl = SysAllocString(url);

    postData.vt = VT_ARRAY;
    postData.parray = SafeArrayCreate(VT_UI1, 0, NULL);

    CComVariant headers((LPCOLESTR)NULL);
    CComVariant targetFrameName((LPCOLESTR)NULL);
    CComVariant flags(navNoHistory);

    m_webBrowser->Navigate(browserUrl,
                           &flags,
                           &targetFrameName,
                           &postData,
                           &headers);

    SafeArrayDestroy(postData.parray);
    SysFreeString(browserUrl);
}
};

// UID:000015 | by-class/BrowserControlPane.md | Completion:90 | Confidence:92
// UID:0004DG | by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md | Completion:87 | Confidence:91
BrowserControlPane::~BrowserControlPane()
{
    if (m_webBrowser)
        m_webBrowser->Release();

    g_activeBrowserControlPane = 0;
}

// UID:000339 | by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md | Completion:87 | Confidence:91
// Emitted code for this range is covered by [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md).


// UID:00032S | by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md | Completion:88 | Confidence:90
BrowserControlPaneOld::~BrowserControlPaneOld()
{
}

// UID:00032T | by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md | Completion:88 | Confidence:90
void BrowserControlPaneOld::DrawBrowserStatusOverlay()
{
    if (!m_browser->m_showBrowserAfterLoad) {
        return;
    }

    const wchar_t *statusText = g_pLanguageMan->GetLocalizedString(236);

    const int textWidth = g_pScreenPane->GetTextWidth(statusText);
    const int textHeight = g_pScreenPane->GetLineHeight();

    const int x = ((m_bounds.left + m_bounds.right) / 2) - (textWidth / 2);
    const int y = ((m_bounds.top + m_bounds.bottom) / 2) - (textHeight / 2);

    MoveTo(x, y);
    SetTextColor(128);
    DrawWideText(statusText, static_cast<int>(wcslen(statusText)));
}

// UID:00032U | by-memory/0x0046f310-0x0046f47b.BrowserControlPaneOldHandleBrowserMessage.md | Completion:88 | Confidence:91
LRESULT BrowserControlPaneOld::DispatchMessage(MSG *message)
{
    switch (message->message)
    {
    case WM_PAINT:
        InvalidateRect(0);
        break;

    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
        if (message->wParam == VK_TAB || message->wParam == VK_ESCAPE)
        {
            return g_pfnSendMessageW(m_browser->m_hWnd,
                                     message->message,
                                     message->wParam,
                                     message->lParam);
        }
        break;

    default:
        break;
    }

    return DispatchToPreviousHandler(message);
}

// UID:0002P3 | by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md | Completion:90 | Confidence:92
BrowserControlPaneOld::BrowserControlPaneOld(const RectBounds *bounds, const wchar_t *initialUrl)
    : ControlPane(8, bounds),
      MSGHandler(),
      m_browser(NULL)
{
    if (bounds == NULL)
        RectBounds(0, 0, g_clientWidth, g_clientHeight);

    Browser *browser = new Browser(initialUrl);
    BrowserThread *thread = new BrowserThread(browser, *bounds);

    g_pBrowserThread = thread;
    thread->StartThread();

    m_browser = browser;
}


// UID:000017 | by-class/BrowserDialog.md | Completion:89 | Confidence:91
class BrowserDialog : public BrowserPane,
                      public Singleton<BrowserDialog>
{
public:
    BrowserDialog(int,
                  const OLECHAR *initialUrl,
                  int width,
                  int height);
    virtual ~BrowserDialog();

    void NavigateToUrl(const wchar_t *url);

    virtual void OnCloseStateChanged(int state, int reason);
    virtual bool OnInputEventWithBrowserReposition(InputEvent *event);
    virtual void DrawSelectedControlFrame();
    virtual void DrawContentArea();
    virtual void DrawFrameChrome();

protected:
    int GetChildRect(short childId, RectBounds *outBounds) const;

    BrowserControlPane *m_browserControlPane; // +0x26c
    int m_width;                              // +0x278, overlaps the empty Singleton base
    int m_height;                             // +0x27c
};

// UID:0004DH | by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md | Completion:89 | Confidence:92
BrowserDialog::~BrowserDialog()
{
    g_pBrowserDialog = 0;
}


// UID:00033A | by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md | Completion:87 | Confidence:90
// Emitted code for this range is covered by [UID:0004DH][0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor](by-memory/0x0046ad10-0x0046ad39.BrowserDialogNonDeletingDestructor.md).



// UID:000019 | by-class/BrowserPane.md | Completion:90 | Confidence:94
// UID:000408 | by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md | Completion:88 | Confidence:91
BrowserPane::~BrowserPane()
{
}

// UID:00033C | by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md | Completion:87 | Confidence:90
// Emitted code for this range is covered by [UID:000408][0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor](by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md).

// UID:00040B | by-memory/0x0046a910-0x0046aa34.BrowserPaneOnCommand.md | Completion:88 | Confidence:90
bool BrowserPane::OnCommand(int commandId)
{
    const wchar_t *messageText = 0;

    switch (commandId)
    {
    case kBrowserCommandDispose:
        messageText = kBrowserDisposeAlertText;
        break;
    case kBrowserCommandNavigationFailed:
        messageText = kBrowserNavigationFailedAlertText;
        break;
    case kBrowserCommandNavigationTimeout:
        messageText = kBrowserNavigationTimeoutAlertText;
        break;
    case kBrowserCommandWebBoardRequestTimeout:
        messageText = kBrowserWebBoardRequestTimeoutAlertText;
        break;
    default:
        return true;
    }

    new AlertPane(messageText, this, kDialogOkButtonString, 0);
    ActivatePendingControl();
    return true;
}

// UID:0004Y0 | by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md | Completion:94 | Confidence:96
void BrowserPane::ScheduleTimer(int timerId, unsigned int delayMs)
{
    TimerHandler::ScheduleTimer(timerId, delayMs, 0, 0);
}

// UID:000217 | by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md | Completion:94 | Confidence:96
void BrowserPane::CancelTimer(int timerId)
{
    TimerHandler::CancelTimer(timerId);
}


// UID:00032Q | by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md | Completion:88 | Confidence:91
int BrowserThread::RunMessageLoop()
{
    MSG message;

    if (!m_browserHostInitialized)
    {
        m_browserHostInitialized = true;
        InitializeBrowserHost();
    }

    while (true)
    {
        int result = ::GetMessageA(&message, NULL, 0, 0);
        if (result == 0)
            break;

        if (result == -1)
            throw Win32Error();

        if (message.message == kBrowserThreadCloseMessage)
            break;

        if (message.message == kBrowserThreadRedraw)
        {
            ::RedrawWindow(m_browser->m_hWnd,
                           NULL,
                           NULL,
                           RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW);
            continue;
        }

        if (message.message == WM_QUIT ||
            message.message == WM_RBUTTONDOWN ||
            message.message == WM_RBUTTONUP)
        {
            continue;
        }

        if (message.message == WM_KEYDOWN || message.message == WM_SYSKEYDOWN)
        {
            if (message.wParam == VK_F4)
            {
                if ((::GetAsyncKeyState(VK_MENU) & 0x8000) != 0)
                {
                    g_pfnPostMessageW(g_pApplication->GetMainWindowHandle(), WM_QUIT, 0, 0);
                    continue;
                }
            }

            if (message.wParam == VK_ESCAPE)
                break;

            if (message.wParam == VK_TAB)
            {
                g_pfnSendMessageW(m_browser->m_hWnd,
                                  message.message,
                                  VK_TAB,
                                  message.lParam);
                continue;
            }
        }

        ::TranslateMessage(&message);
        g_pfnDispatchMessageW(&message);
    }

    ::ShowWindow(m_browser->m_hWnd, SW_HIDE);
    ::SetFocus(g_pApplication->GetMainWindowHandle());
    PostBrowserNotification(1, m_browser->m_currentUrl.c_str());

    if (m_browser != NULL)
        delete m_browser;

    ::CoUninitialize();
    return 0;
}

// UID:00032V | by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md | Completion:87 | Confidence:90
// Emitted code for this range is covered by [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md).

// UID:00032W | by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md | Completion:91 | Confidence:93
void BrowserThread::InitializeBrowserHost()
{
    wchar_t worldName[100];
    wchar_t playerName[100];
    wchar_t className[256];
    WNDCLASSW wndClass;
    RECT rect;
    Browser *browser;
    IOleObject *oleObject;
    HRESULT hr;

    g_pApplication->CopyWorldName(worldName, 100);
    g_pApplication->CopyPlayerName(playerName, 100);
    _snwprintf_s(className, 256, 255, L"%s.%s.Browser", worldName, playerName);

    memset(&wndClass, 0, sizeof(wndClass));
    wndClass.style = 0x3028;
    wndClass.lpfnWndProc = BrowserLegacyHostWndProc;
    wndClass.hInstance = g_pApplication->GetInstanceHandle();
    wndClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.lpszClassName = className;
    RegisterClassW(&wndClass);

    browser = m_browser;
    g_pCurrentBrowserHost = browser;
    browser->m_hWnd = CreateWindowExW(0,
                                      className,
                                      L"",
                                      WS_CHILD | WS_CLIPSIBLINGS,
                                      m_hostBounds.left,
                                      m_hostBounds.top,
                                      m_hostBounds.right - m_hostBounds.left,
                                      m_hostBounds.bottom - m_hostBounds.top,
                                      g_pApplication->GetMainWindowHandle(),
                                      NULL,
                                      g_pApplication->GetInstanceHandle(),
                                      NULL);
    InvalidateRect(browser->m_hWnd, NULL, TRUE);
    SetWindowLongA(browser->m_hWnd, GWL_USERDATA, (LONG)browser);
    g_pCurrentBrowserHost = NULL;

    oleObject = NULL;
    CoInitialize(NULL);
    hr = CoCreateInstance(CLSID_WebBrowser,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IOleObject,
                          (void **)&oleObject);
    if (SUCCEEDED(hr)) {
        hr = oleObject->SetClientSite(browser);
    }
    if (SUCCEEDED(hr)) {
        SetRect(&rect,
                0,
                0,
                m_hostBounds.right - m_hostBounds.left,
                m_hostBounds.bottom - m_hostBounds.top);
        hr = oleObject->DoVerb(OLEIVERB_INPLACEACTIVATE,
                               NULL,
                               browser,
                               0,
                               browser->m_hWnd,
                               &rect);
    }
    if (SUCCEEDED(hr)) {
        browser->m_webBrowser = oleObject;
        hr = AdviseConnectionPoint(browser->m_webBrowser,
                                   DIID_DWebBrowserEvents2,
                                   browser,
                                   &browser->m_adviseCookie);
    }
    if (SUCCEEDED(hr)) {
        CComQIPtr<IOleInPlaceObject> inPlaceObject(browser->m_webBrowser);
        hr = inPlaceObject->SetObjectRects(&rect, &rect);
    }

    if (FAILED(hr)) {
        if (browser != NULL) {
            UnadviseConnectionPoint(browser->m_webBrowser,
                                    DIID_DWebBrowserEvents2,
                                    browser->m_adviseCookie);
            browser->Release();
            CoUninitialize();
            DestroyWindow(browser->m_hWnd);
        }
    } else {
        browser->m_allowedUrlPrefix[0] = L'\0';
        browser->m_showBrowserAfterLoad = true;
        browser->m_pendingDownloadCount = 0;
    }

    browser->Navigate(browser->m_navigationBuffer);

    if (oleObject != NULL) {
        oleObject->Release();
    }
}


// UID:00020T | by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md | Completion:88 | Confidence:92
STDMETHODIMP BrowserWindow::ShowContextMenu(DWORD, POINT *, IUnknown *, IDispatch *)
{
    return S_OK;
}

STDMETHODIMP BrowserWindow::GetHostInfo(DOCHOSTUIINFO *info)
{
    info->cbSize = sizeof(DOCHOSTUIINFO);
    info->dwFlags =
        DOCHOSTUIFLAG_DIALOG |
        DOCHOSTUIFLAG_DISABLE_HELP_MENU |
        DOCHOSTUIFLAG_NO3DBORDER |
        DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE |
        DOCHOSTUIFLAG_FLAT_SCROLLBAR |
        DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION;

    if (!m_enableScrollBars) {
        info->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO;
    }

    return S_OK;
}

STDMETHODIMP BrowserWindow::ShowUI(DWORD, IOleInPlaceActiveObject *,
                                   IOleCommandTarget *, IOleInPlaceFrame *,
                                   IOleInPlaceUIWindow *)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::HideUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::UpdateUI()
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::EnableModeless(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::OnDocWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::OnFrameWindowActivate(BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::ResizeBorder(LPCRECT, IOleInPlaceUIWindow *, BOOL)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::TranslateAccelerator(LPMSG, const GUID *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetOptionKeyPath(LPOLESTR *, DWORD)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetDropTarget(IDropTarget *, IDropTarget **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::GetExternal(IDispatch **dispatch)
{
    *dispatch = 0;
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::TranslateUrl(DWORD, OLECHAR *, OLECHAR **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::FilterDataObject(IDataObject *, IDataObject **)
{
    return E_NOTIMPL;
}

STDMETHODIMP BrowserWindow::ShowMessage(HWND, LPOLESTR, LPOLESTR, DWORD,
                                        LPOLESTR, DWORD, LRESULT *)
{
    return S_OK;
}

STDMETHODIMP BrowserWindow::ShowHelp(HWND, LPOLESTR, UINT, DWORD, POINT,
                                     IDispatch *)
{
    return S_OK;
}


// UID:00033D | by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md | Completion:86 | Confidence:90
// Compiler-generated scalar deleting destructor for browser::Notification.
// Source reconstruction is the browser::Notification class declaration with its
// LObject base and owned string payload; do not hand-author this wrapper.

// UID:00033L | by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md | Completion:88 | Confidence:91
void PostBrowserNotification(BrowserNotificationState state, const wchar_t *text)
{
    browser::Notification *notification = new browser::Notification(state, NULL);
    if (text != NULL)
        notification->m_text.assign(text);

    PostApplicationNotification(kBrowserNotificationChannel, notification);
}


// UID:0000PO | by-global/g_activeBrowserControlPane.md | Completion:89 | Confidence:92
// Source declaration for g_activeBrowserControlPane is emitted by [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md).

// UID:0000PP | by-global/g_activeBrowserPane.md | Completion:90 | Confidence:91
// Source declaration for g_activeBrowserPane is emitted by [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md).


// UID:0000Q6 | by-global/g_pActiveBrowserWindow.md | Completion:89 | Confidence:91
// Source declaration for g_pActiveBrowserWindow is emitted by [UID:0002T5][0x0067ab94-0x0067ab98.g_pActiveBrowserWindow](by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md).
// UID:0002T5 | by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md | Completion:90 | Confidence:92
static BrowserWindow *g_pActiveBrowserWindow;

// UID:0000QB | by-global/g_pBrowserDialogOld.md | Completion:88 | Confidence:90
// Source declaration for g_pBrowserDialogOld is emitted by [UID:0002WH][0x0067ab90-0x0067ab94.g_pBrowserDialogOld](by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md).
// UID:0002WH | by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md | Completion:90 | Confidence:92
BrowserDialogOld *g_pBrowserDialogOld;

// UID:0000QE | by-global/g_pBrowserThread.md | Completion:86 | Confidence:88
// Source declaration for g_pBrowserThread is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).

// UID:0000QO | by-global/g_pCurrentBrowserHost.md | Completion:87 | Confidence:90
// Source declaration for g_pCurrentBrowserHost is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).

// UID:0000Z4 | by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md | Completion:87 | Confidence:91
// BrowserWindowCore is a split-required BrowserWindow aggregate.
// Do not emit a synthetic aggregate body here; exact BrowserWindow
// method children for this range should carry source bodies after
// the BrowserWindow COM layout and field names are finalized.


// UID:00020V | by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md | Completion:86 | Confidence:90
static LRESULT CALLBACK BrowserWindowHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (GetWindowLongA(hwnd, GWL_USERDATA) == 0) {
        return DefWindowProcA(hwnd, message, wParam, lParam);
    }

    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        BeginPaint(hwnd, &paint);
        EndPaint(hwnd, &paint);
        return 0;
    }

    case WM_SYSCOMMAND:
        switch (wParam & 0xfff0) {
        case SC_SIZE:
        case SC_MOVE:
        case SC_MINIMIZE:
        case SC_MAXIMIZE:
        case SC_CLOSE:
            return 0;
        default:
            break;
        }
        break;
    }

    return DefWindowProcA(hwnd, message, wParam, lParam);
}


// UID:000409 | by-memory/0x0046a8c0-0x0046a8d7.BrowserDialogNavigateToUrl.md | Completion:88 | Confidence:90
void BrowserDialog::NavigateToUrl(const wchar_t *url)
{
    m_browserControlPane->NavigateBrowser(url, 0);
}


// UID:00040C | by-memory/0x0046aa40-0x0046ad0a.BrowserDialogConstructor.md | Completion:90 | Confidence:92
BrowserDialog::BrowserDialog(int,
                             const OLECHAR *initialUrl,
                             int width,
                             int height)
    : BrowserPane(L"", -1, true),
      Singleton<BrowserDialog>(),
      m_width(width != 0 ? width : 662),
      m_height(height != 0 ? height : 562)
{
    RectBounds childBounds;
    RectBounds dialogBounds;

    if (g_useEpfAssets)
    {
        GetChildRect(0, &childBounds);
        AddControl(new ImageButtonControlPane(14, &childBounds));

        GetChildRect(1, &childBounds);
        m_browserControlPane =
            new BrowserControlPane(&childBounds, initialUrl, this);
        AddControl(m_browserControlPane);

        InitRectBoundsFromSize(&dialogBounds,
                               (1024 - m_width) / 2,
                               (768 - m_height) / 2,
                               m_width,
                               m_height);
        OnCreate(&dialogBounds, 0, NULL, g_layoutContext_69B374);
        OnShow(NULL, NULL);
        SlideOpenVertical();
        SetFocusedControl(0);
    }
    else
    {
        InitRectBounds(&dialogBounds,
                       0,
                       0,
                       g_screenWidth,
                       g_screenHeight);
        InitRectBounds(&childBounds, 0, 0, 63, 24);

        ImageButtonControlPane *titleButton =
            new ImageButtonControlPane(14, &childBounds);
        AddControl(titleButton);

        childBounds = dialogBounds;
        m_browserControlPane =
            new BrowserControlPane(&childBounds, initialUrl, this);
        AddControl(m_browserControlPane);

        OnCreate(&dialogBounds, 0, NULL, g_layoutContext_69B374);
        OnShow(NULL, NULL);
        StoreClampRect(&dialogBounds);
        titleButton->Hide();
    }

    SetPendingControl(0);
}


// UID:000215 | by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md | Completion:88 | Confidence:92
BrowserThread::~BrowserThread()
{
    g_pBrowserThread = NULL;
}

// UID:000333 | by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md | Completion:88 | Confidence:91
static LRESULT CALLBACK BrowserLegacyHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Browser *browser = reinterpret_cast<Browser *>(GetWindowLongA(hwnd, GWL_USERDATA));
    if (browser == NULL) {
        browser = g_pCurrentBrowserHost;
    }

    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        BeginPaint(hwnd, &paint);
        EndPaint(hwnd, &paint);
        return 0;
    }

    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    {
        IOleInPlaceActiveObject *activeObject = NULL;
        if (browser != NULL && browser->m_webBrowser != NULL) {
            if (FAILED(browser->m_webBrowser->QueryInterface(IID_IOleInPlaceActiveObject,
                                                             reinterpret_cast<void **>(&activeObject)))) {
                activeObject = NULL;
            }
        }

        if (wParam == VK_TAB) {
            IOleObject *oleObject = NULL;
            if (browser != NULL && browser->m_webBrowser != NULL) {
                if (FAILED(browser->m_webBrowser->QueryInterface(IID_IOleObject,
                                                                 reinterpret_cast<void **>(&oleObject)))) {
                    oleObject = NULL;
                }
            }

            if (oleObject != NULL && browser != NULL) {
                RECT clientRect;
                GetClientRect(browser->m_hWnd, &clientRect);
                oleObject->DoVerb(OLEIVERB_UIACTIVATE,
                                  NULL,
                                  browser,
                                  0,
                                  browser->m_hWnd,
                                  &clientRect);
                oleObject->Release();
            }
        } else if (wParam == VK_ESCAPE || wParam == VK_F4) {
            if (activeObject != NULL) {
                activeObject->Release();
            }
            return 0;
        }

        if (activeObject != NULL) {
            MSG acceleratorMessage;
            acceleratorMessage.message = message;
            acceleratorMessage.wParam = wParam;
            acceleratorMessage.lParam = lParam;
            activeObject->TranslateAccelerator(&acceleratorMessage);
            activeObject->Release();
        }
        return 0;
    }

    default:
        break;
    }

    return g_pfnDefWindowProcW(hwnd, message, wParam, lParam);
}

// UID:00033H | by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md | Completion:88 | Confidence:91
static HRESULT AdviseConnectionPoint(IUnknown *source,
                                     REFIID iid,
                                     IUnknown *sink,
                                     DWORD *cookie)
{
    IConnectionPointContainer *container;
    IConnectionPoint *connectionPoint;
    HRESULT hr;

    if (source == NULL)
        return E_INVALIDARG;

    container = NULL;
    connectionPoint = NULL;

    hr = source->QueryInterface(IID_IConnectionPointContainer,
                                reinterpret_cast<void **>(&container));
    if (SUCCEEDED(hr))
    {
        hr = container->FindConnectionPoint(iid, &connectionPoint);
        if (SUCCEEDED(hr))
            hr = connectionPoint->Advise(sink, cookie);
    }

    if (connectionPoint != NULL)
        connectionPoint->Release();
    if (container != NULL)
        container->Release();

    return hr;
}

// UID:00033J | by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md | Completion:88 | Confidence:91
static HRESULT UnadviseConnectionPoint(IUnknown *source, REFIID iid, DWORD cookie)
{
    IConnectionPointContainer *container;
    IConnectionPoint *connectionPoint;
    HRESULT hr;

    if (source == NULL)
        return E_INVALIDARG;

    container = NULL;
    connectionPoint = NULL;

    hr = source->QueryInterface(IID_IConnectionPointContainer,
                                reinterpret_cast<void **>(&container));
    if (SUCCEEDED(hr))
    {
        hr = container->FindConnectionPoint(iid, &connectionPoint);
        if (SUCCEEDED(hr))
            hr = connectionPoint->Unadvise(cookie);
    }

    if (connectionPoint != NULL)
        connectionPoint->Release();
    if (container != NULL)
        container->Release();

    return hr;
}

// UID:00024V | by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md | Completion:89 | Confidence:93
static const wchar_t kBrowserWindowCloseScriptUrl[] = L"javascript:window.close();";

// UID:0001OD | by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md | Completion:88 | Confidence:92
static const wchar_t kBrowserDisposeAlertText[] = L"Dispose";
static const wchar_t kBrowserNavigationFailedAlertText[] = L"Navigation Failed";
static const wchar_t kBrowserNavigationTimeoutAlertText[] = L"Navigation Timeout";
static const wchar_t kBrowserWebBoardRequestTimeoutAlertText[] = L"Web Board Request Timeout";


// UID:000277 | by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md | Completion:95 | Confidence:96
static AutoInit s_autoInit;

// UID:0001P3 | by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md | Completion:89 | Confidence:92
BrowserControlPane *g_activeBrowserControlPane;

// UID:0001P9 | by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md | Completion:90 | Confidence:91
BrowserPane *g_activeBrowserPane;

// UID:0002AD | by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md | Completion:90 | Confidence:92
static BrowserThread *g_pBrowserThread;
static Browser *g_pCurrentBrowserHost;

// UID:0002WI | by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md | Completion:88 | Confidence:89
BrowserDialog *g_pBrowserDialog;

// UID:000016 | by-class\BrowserControlPaneOld.md | Completion:87 | Confidence:89 | Empty Emitter Marker

// UID:0001CO | by-memory\0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:00020X | by-memory\0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:000018 | by-class\BrowserDialogOld.md | Completion:85 | Confidence:87 | Empty Emitter Marker

// UID:0000Z3 | by-memory\0x00469290-0x0046963c.BrowserDialogOldCore.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:00001A | by-class\BrowserThread.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:00001B | by-class\BrowserWindow.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:000014 | by-class\browser__Notification.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0000T2 | by-global\DIID_DWebBrowserEvents2.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0000PV | by-global\g_browserWindowClassName.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:00020U | by-memory\0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:000407 | by-memory\0x0046a860-0x0046a898.BrowserPaneRawConstructor.md | Completion:87 | Confidence:89 | Empty Emitter Marker

// UID:00040A | by-memory\0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0000Z6 | by-memory\0x0046b520-0x0046cfe0.BrowserControlPaneCore.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003OH | by-memory\0x00631580-0x00631660.BrowserComGuidConstants.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:0001SJ | by-type\by-enum\BrowserDispatchEventId.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0001SK | by-type\by-enum\BrowserInitFlags.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0001SL | by-type\by-enum\BrowserMessageId.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0001SM | by-type\by-enum\BrowserOverlayStyle.md | Completion:86 | Confidence:89 | Empty Emitter Marker
