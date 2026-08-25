// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HV
// Source by-file doc: by-file/Browser.md
// UID:000015 | by-class/BrowserControlPane.md | Completion:90 | Confidence:92
#pragma once

#include "../ui/core/ControlPane.h"
#include "../ui/core/DialogPane.h"
#include <windows.h>
#include <exdisp.h>
#include <mshtmhst.h>
#include <oleidl.h>

class BrowserPane;

class BrowserControlPane :
    public ControlPane,
    public IOleClientSite,
    public IOleInPlaceSite,
    public IDispatch,
    public IDocHostUIHandler,
    public IDocHostShowUI
{
public:
    BrowserControlPane(const RECT *bounds,
                       const OLECHAR *initialUrl,
                       BrowserPane *ownerPane);
    virtual ~BrowserControlPane();

    void ShutdownBrowserWindow();
    void NavigateBrowser(const wchar_t *url);

    STDMETHOD(QueryInterface)(REFIID iid, void **object);
    STDMETHOD_(ULONG, AddRef)();
    STDMETHOD_(ULONG, Release)();

    STDMETHOD(SaveObject)();
    STDMETHOD(GetMoniker)(DWORD assign, DWORD whichMoniker, IMoniker **moniker);
    STDMETHOD(GetContainer)(IOleContainer **container);
    STDMETHOD(ShowObject)();
    STDMETHOD(OnShowWindow)(BOOL show);
    STDMETHOD(RequestNewObjectLayout)();

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

    STDMETHOD(GetTypeInfoCount)(UINT *count);
    STDMETHOD(GetTypeInfo)(UINT typeInfo, LCID lcid, ITypeInfo **info);
    STDMETHOD(GetIDsOfNames)(REFIID iid,
                             LPOLESTR *names,
                             UINT count,
                             LCID lcid,
                             DISPID *dispids);
    STDMETHOD(Invoke)(DISPID dispidMember,
                      REFIID iid,
                      LCID lcid,
                      WORD flags,
                      DISPPARAMS *params,
                      VARIANT *result,
                      EXCEPINFO *exceptionInfo,
                      UINT *argError);

    STDMETHOD(ShowContextMenu)(DWORD id,
                               POINT *point,
                               IUnknown *commandTarget,
                               IDispatch *dispatchObject);
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
    STDMETHOD(ResizeBorder)(LPCRECT border,
                            IOleInPlaceUIWindow *uiWindow,
                            BOOL frameWindow);
    STDMETHOD(TranslateAccelerator)(LPMSG msg,
                                    const GUID *commandGroup,
                                    DWORD commandId);
    STDMETHOD(GetOptionKeyPath)(LPOLESTR *key, DWORD reserved);
    STDMETHOD(GetDropTarget)(IDropTarget *dropTarget,
                             IDropTarget **resultDropTarget);
    STDMETHOD(GetExternal)(IDispatch **dispatchObject);
    STDMETHOD(TranslateUrl)(DWORD translate,
                            OLECHAR *urlIn,
                            OLECHAR **urlOut);
    STDMETHOD(FilterDataObject)(IDataObject *dataObject,
                                IDataObject **resultDataObject);

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

    HWND m_browserHostHwnd; // +0x11c; direct WebBoardDialog consumer contract

private:
    IWebBrowser2 *m_webBrowser;                    // +0x120
    DWORD m_webBrowserEventsCookie;                // +0x124
    unsigned char m_cancelNavigateComplete;        // +0x128
    unsigned char m_refreshState;                  // +0x129
    unsigned char m_browserActiveState;            // +0x12a
    unsigned char m_reserved12b;                   // +0x12b
    wchar_t m_allowedUrlPrefix[256];                // +0x12c
    int m_navigationTimeoutMillis;                 // +0x32c
    unsigned char m_reservedState0;                // +0x330
    unsigned char m_reservedState1;                // +0x331
    unsigned char m_cursorShownByBrowser;           // +0x332
    unsigned char m_deferShowUntilDocumentComplete;// +0x333
    IDispatch *m_topLevelNavigationDispatchCookie; // +0x334
};

// UID:000019 | by-class/BrowserPane.md | Completion:90 | Confidence:94
class InputEvent;

class BrowserPane : public DialogPane
{
public:
    BrowserPane(const wchar_t *title, int dialogConfigId, bool modal);
    virtual ~BrowserPane();

    virtual bool OnKeyEvent(InputEvent *event);
    virtual void OnCommand(int commandId);
    virtual void ScheduleTimer(int timerId, unsigned int delayMs);
    virtual void CancelTimer(int timerId);
    virtual void OnBrowserDialogClosed() { }
    virtual void OnBrowserDialogOpened() { }
};
