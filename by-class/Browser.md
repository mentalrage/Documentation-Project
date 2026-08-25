*** UID:000013 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Browser

## UID00029O Shared Layout-Layer Dependency - 2026-07-21

Browser-family window/layout mapping consumes shared `g_pLayoutPaneLayer`; it does not own that Layer pointer. The old `g_pBrowserOverlayLayer` spelling is a superseded Browser-facing alias. All Browser COM interfaces, host/window state, methods, fields, vtables, scores, and formal content remain unchanged.

## Status

- Confidence: very strong for subsystem placement, Browser COM/event-sink identity, five interface vtable slices, exact promoted method ranges, QueryInterface pointer adjustments, field roles, connection cleanup, dispatch-event behavior, and declaration-level first-draft C++ readiness; medium-high for final custom wide-string type name and exact allowed-prefix array extent.
- Likely source module: [UID:0000HV][Browser](by-file/Browser.md)
- Current relevant ranges: Browser method body cluster `0x0046f480-0x00470406`, notification helper evidence at `0x00470740-0x00470782` / `0x00470f20-0x00470fb9`, connection helpers `0x004708d0-0x00470a00`, GUID helper `0x004710e0-0x0047110e`, and Browser vtable slices at `0x00613830-0x00613918`.
- Evidence basis: live IDA MCP function-boundary, decompile, call/xref, and vtable checks plus linked browser subsystem documentation.

## Responsibility

`Browser` is a COM-style embedded browser object/event sink used by the older browser-control path. The live binary shows five vtable slices stored at offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`, QueryInterface paths over browser COM GUID data, advisory connection cleanup, dispatch-event handling, browser teardown, and notification posting.

Keep this class under [UID:0000HV][Browser](by-file/Browser.md) / `NexusTK/browser/Browser.cpp`. `BrowserWindow`, `BrowserThread`, `BrowserControlPane`, and `BrowserControlPaneOld` are neighboring browser subsystem classes or consumers of this object, not owners of Browser's COM methods. A future `BrowserLegacy.cpp` or `BrowserOld.cpp` split is plausible but unproven; do not move this class out of the Browser source root without stronger source-tree evidence.

## COM Interface Layout

The five Browser vtable pointer stores restored by the ordinary destructor and scalar deleting destructor are source layout evidence. The checked layout is:

```cpp
class Browser :
    public IOleClientSite,
    public IOleInPlaceSite,
    public IDispatch,
    public IDocHostUIHandler,
    public IDocHostShowUI
```

Do not add a separate `IUnknown` base because each COM interface already inherits it. Do not add a separate concrete `IOleWindow` base because `IOleWindow` is the base view of `IOleInPlaceSite`. Do not model `DWebBrowserEvents2` as a separate data-bearing base; `QueryInterface` returns the `IDispatch` view for `DIID_DWebBrowserEvents2`.

| Object offset | Vtable address | Source-facing interface | Evidence |
|---:|---:|---|---|
| `+0x00` | `0x00613830` | `IOleClientSite` primary view | `QueryInterface` returns base `this` for `IID_IUnknown` and `IID_IOleClientSite`; slots match `QueryInterface`, fixed `AddRef`, fixed `Release`, six `IOleClientSite` stubs, and a compiler scalar deleting destructor tail. |
| `+0x04` | `0x0061385c` | `IOleInPlaceSite` / inherited `IOleWindow` view | `QueryInterface` returns `this + 4` for `IID_IOleInPlaceSite` and the `IID_IOleWindow` comparison; slots match adjusted IUnknown, `GetWindow`, `ContextSensitiveHelp`, and `IOleInPlaceSite` activation/window-context callbacks. |
| `+0x08` | `0x0061389c` | `IDispatch` / `DWebBrowserEvents2` event-sink view | `QueryInterface` returns `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`; slots match adjusted IUnknown, three IDispatch metadata stubs, and `Invoke`. |
| `+0x0c` | `0x006138bc` | `IDocHostUIHandler`-style view | Slots after adjusted IUnknown match the 15 `IDocHostUIHandler` methods: `ShowContextMenu`, `GetHostInfo`, `ShowUI`, `HideUI`, `UpdateUI`, `EnableModeless`, `OnDocWindowActivate`, `OnFrameWindowActivate`, `ResizeBorder`, `TranslateAccelerator`, `GetOptionKeyPath`, `GetDropTarget`, `GetExternal`, `TranslateUrl`, and `FilterDataObject`. Direct QI exposure was not observed in the checked `Browser::QueryInterface` export. |
| `+0x10` | `0x00613908` | `IDocHostShowUI`-style view | Slots after adjusted IUnknown match `ShowMessage` and `ShowHelp`. Direct QI exposure was not observed in the checked `Browser::QueryInterface` export. |

[UID:00032Z][0x0046f540-0x0046f66f.BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md) now emits first-draft source-ready `Browser::QueryInterface(REFIID riid, void **ppvObject)` on the exact child page. Current MCP session `3fa0535f` confirms the body `0x0046f540-0x0046f66f`, the returned `+0/+4/+8` interface views, no-`AddRef` behavior, `E_NOINTERFACE` failure path, and compiler adjustor thunk callers. Keep the DocHost slices in the class declaration, but do not infer direct `IID_IDocHostUIHandler` or `IID_IDocHostShowUI` QueryInterface exposure from this body.

`Browser::QueryInterface` currently supports this table:

| Requested IID | Returned pointer | Source decision |
|---|---:|---|
| `IID_IUnknown` | `this + 0` | Primary COM identity through `IOleClientSite`. |
| `IID_IOleClientSite` | `this + 0` | Primary base. |
| `IID_IOleInPlaceSite` | `this + 4` | Second base. |
| `IID_IOleWindow` | `this + 4` | Inherited `IOleWindow` view through `IOleInPlaceSite`. |
| `IID_IDispatch` | `this + 8` | Third base. |
| `DIID_DWebBrowserEvents2` | `this + 8` | Event-sink identity through the IDispatch view. |
| Other IID | `0`, `E_NOINTERFACE` | No additional QI routes should be inferred unless a later live check proves them. |

Generated/simulated class material that labels the slices as `IUnknown`, `IOleClientSite`, `IDocHostUIHandler`, `IDispatch`, and `IServiceProvider` is rejected as stale/source-quality-poor because it confuses COM identity with concrete C++ vptr layout and does not match the checked QueryInterface table.

## Field Layout

Offsets are Browser base-object offsets. `Browser::Invoke` receives the adjusted `IDispatch` view (`base + 8`), so raw decompiler offsets in that method must be converted back to Browser base offsets before naming fields.

| Offset | Field name | Type recommendation | Confidence | Evidence and caveat |
|---:|---|---|---|---|
| `+0x00` | `IOleClientSite` vptr | compiler vptr | High | Primary vtable store and QI primary identity. |
| `+0x04` | `IOleInPlaceSite` vptr | compiler vptr | High | QI returns `this + 4` for `IID_IOleInPlaceSite` and `IID_IOleWindow`. |
| `+0x08` | `IDispatch` vptr | compiler vptr | High | QI returns `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`; `Invoke` receives this adjusted view. |
| `+0x0c` | `IDocHostUIHandler` vptr | compiler vptr | Medium-high | Slot order matches `IDocHostUIHandler`; direct QI exposure not observed. |
| `+0x10` | `IDocHostShowUI` vptr | compiler vptr | Medium-high | Slot order matches `IDocHostShowUI`; direct QI exposure not observed. |
| `+0x14` | `m_hWnd` | `HWND` | High | Destructor destroys it; `GetWindow`/`GetWindowContext` return/use it through adjusted interface views. |
| `+0x18` | `m_webBrowser` | `CComQIPtr<IWebBrowser2>` | High | Host initialization assigns the `IOleObject *` through ATL QI using IID_IWebBrowser2, connection helpers and `Navigate` consume the resulting interface, and destructor lowering matches explicit `Release()` plus compiler member destruction. |
| `+0x1c` | `m_adviseCookie` | `DWORD` | High | Passed to `UnadviseConnectionPoint` with `DIID_DWebBrowserEvents2`. |
| about `+0x20` to `+0x221` | `m_allowedUrlPrefix` | wide-character buffer | Medium | `Invoke` checks a non-empty prefix and rejects `BeforeNavigate2` URLs that do not match it. Exact start/extent still needs constructor/setup-write recheck. |
| `+0x222` | `m_showBrowserAfterLoad` | `bool` or `unsigned char` | Medium-high | `Invoke` tests this byte after pending-count decrement; if set, it shows the hosted window and restores cursor visibility. |
| `+0x224` | `m_pendingDownloadCount` | `int` or `LONG` | High | `Invoke` increments on dispatch id `106` and decrements on dispatch id `104`. |
| `+0x228` | `m_navigationBuffer` | `wchar_t *` or owned buffer pointer | Medium | Ordinary and scalar destructors free this with the wide-string/buffer cleanup helper. Keep distinct from the string object at `+0x230`. |
| `+0x22c` | `m_stateFlags` | `WORD` or unsigned state subfield | Medium-high | Old control pane setup writes `0x0101`; keep as a state word/bitmask, not a proven final enum. |
| `+0x230` | `m_currentUrl` | project wide-string object | Medium-high | Constructed/destroyed as a string object; the resource-prefix path stores localized fallback/current URL text here. Final project type name remains support-doc dependent. |
| `0x234` total | object size | allocation size | High | Old control pane setup allocates/initializes a `0x234` byte Browser object. |

Rejected field alternatives: do not call `+0x18` only `m_unknown`; behavior is consistently WebBrowser automation/control related. Do not merge `+0x228` and `+0x230`; destructor paths treat them as distinct owned resources. Do not leave `+0x222` and `+0x224` as raw byte/dword names; their dispatch-event behavior is clear enough for source-facing load/visibility names. Do not treat `0x0101` at `+0x22c` as a final enum name without bit-level proof.

## Constructor Support

[UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) now requires a source-facing Browser initial-URL constructor or exact equivalent helper. The accepted support declaration is:

```cpp
Browser::Browser(const wchar_t *initialUrl);
```

This is a support declaration for source-quality reconstruction, not a separate ownership move for UID0002P3. The observed constructor-side Browser initialization remains Browser-owned:

- allocation size is `0x234`;
- five Browser interface/vtable slices are installed at `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`;
- `m_hWnd` and `m_webBrowser` are initialized to `NULL`;
- `m_navigationBuffer` is initialized to `NULL`, then replaced by an owned heap copy of `initialUrl`;
- `m_stateFlags` is initialized to `0x0101` as a state word/bitmask, not a final enum;
- `m_currentUrl` is constructed at `+0x230`.

Do not make `BrowserControlPaneOld` write `m_navigationBuffer`, `m_stateFlags`, or `m_currentUrl` directly. Those fields remain private Browser state, and the pane constructor should call `new Browser(initialUrl)` as accepted first-draft source. Do not initialize unrelated Browser fields here unless a separate target proves the corresponding binary writes.

## Methods

Active methods:

- [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md) `Browser::~Browser()`.
- [UID:00032Z][0x0046f540-0x0046f66f.BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md) source-ready `Browser::QueryInterface(REFIID, void **)`.
- [UID:000330][0x0046f670-0x0046f808.BrowserComStubMethods](by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md) COM stubs for fixed `AddRef`/`Release`, `IOleClientSite`, `IOleInPlaceSite`, and `IDispatch` metadata methods.
- [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md) `Browser::Invoke(...)` plus compiler switch table bytes.
- [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) `IDocHostUIHandler` and `IDocHostShowUI` stub callbacks.
- [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) `Browser::Navigate(const wchar_t *url)`.

Disabled/adjustor-like methods:

- [UID:000338][0x00470330-0x00470406.BrowserScalarDeletingDestructor](by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md) is the MSVC scalar deleting destructor wrapper. Do not emit handwritten source for it; route source behavior to `Browser::~Browser()`.
- [UID:00033M][0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks](by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md) contains Browser adjustor/delegation thunks at `0x00470fdc-0x00471004` and `0x00471054-0x0047107c` caused by the secondary COM interface views. Do not emit handwritten source for these thunks.

## Destructor Source Readiness

[UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md) is now source-ready first draft for `Browser::~Browser()`. The accepted B006 report rechecked the ordinary destructor range, vtable stores, field cleanup, `DIID_DWebBrowserEvents2` unadvise route, and [UID:000338][0x00470330-0x00470406.BrowserScalarDeletingDestructor](by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md) scalar-wrapper relationship through current MCP evidence. The formal destructor body belongs on [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md), not on the class declaration page.

The remaining declaration caveat is the final project type name for `m_currentUrl`, not the browser interface member. Host initialization queries IID_IWebBrowser2 through ATL assignment into `m_webBrowser`, and the destructor's final redundant guard is compiler-generated `CComQIPtr<IWebBrowser2>` member cleanup rather than a second handwritten release. The `m_currentUrl` cleanup likewise remains compiler/member cleanup evidence, not a separate handwritten source statement.

[UID:000338][0x00470330-0x00470406.BrowserScalarDeletingDestructor](by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md) remains no-handwritten-source compiler glue. Its vtable slot is `0x00613854`, it duplicates [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md)'s destructor sequence, applies the scalar-delete flag, optionally frees the `0x234`-byte Browser object storage through `sub_5C7526(this, 0x234)`, and returns with `retn 4`. Keep only the minimal formal coverage comment on that page and do not add a handwritten deleting-destructor wrapper body.

## Browser COM Stub Method Map

[UID:000330][0x0046f670-0x0046f808.BrowserComStubMethods](by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md) now carries the exact source-facing names for the pre-`Invoke` Browser COM method island. Use these names in Browser declaration/source work instead of generated `sub_46Fxxx` names or stale service/show-UI labels:

| Address | Source method | Interface slice | Behavior |
| ---: | --- | --- | --- |
| `0x0046f670` | `AddRef` | `IOleClientSite` primary plus secondary adjustors | Fixed return `2`. |
| `0x0046f680` | `Release` | `IOleClientSite` primary plus secondary adjustors | Fixed return `1`. |
| `0x0046f690` | `SaveObject` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6a0` | `GetMoniker` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6b0` | `GetContainer` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6c0` | `ShowObject` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6d0` | `OnShowWindow` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6e0` | `RequestNewObjectLayout` | `IOleClientSite` | `E_NOTIMPL`. |
| `0x0046f6f0` | `GetWindow` | `IOleWindow` inherited by `IOleInPlaceSite` | Writes `m_hWnd` and returns `S_OK`; machine offset `+0x10` from the adjusted view is Browser base `+0x14`. |
| `0x0046f710` | `ContextSensitiveHelp` | `IOleWindow` inherited by `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f720` | `CanInPlaceActivate` | `IOleInPlaceSite` | `S_OK`. |
| `0x0046f730` | `OnInPlaceActivate` | `IOleInPlaceSite` | `S_OK`. |
| `0x0046f740` | `OnUIActivate` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f750` | `GetWindowContext` | `IOleInPlaceSite` | Calls `USER32.dll!GetClientRect` twice for `m_hWnd`, filling position and clipping rectangles, then returns `S_OK`; no binary writes to frame/doc/frame-info outputs were observed. |
| `0x0046f780` | `Scroll` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f790` | `OnUIDeactivate` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f7a0` | `OnInPlaceDeactivate` | `IOleInPlaceSite` | `S_OK`. |
| `0x0046f7b0` | `DiscardUndoState` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f7c0` | `DeactivateAndUndo` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f7d0` | `OnPosRectChange` | `IOleInPlaceSite` | `E_NOTIMPL`. |
| `0x0046f7e0` | `GetIDsOfNames` | `IDispatch` / event-sink view | `E_NOTIMPL`; not `QueryService` or a DocHost callback. |
| `0x0046f7f0` | `GetTypeInfo` | `IDispatch` / event-sink view | `E_NOTIMPL`; not `QueryStatus`. |
| `0x0046f800` | `GetTypeInfoCount` | `IDispatch` / event-sink view | `E_NOTIMPL`; not `TranslateAccelerator`. |

The standard source declaration order remains COM's `GetTypeInfoCount`, `GetTypeInfo`, `GetIDsOfNames`, then `Invoke`, even though the tiny function bodies are laid out as `GetIDsOfNames`, `GetTypeInfo`, and `GetTypeInfoCount` before `Invoke` in this binary. The secondary-interface `AddRef`/`Release` and `QueryInterface` entrypoints remain compiler-generated adjustor thunks documented by [UID:00033G][0x0047084f-0x004708c7.BrowserComAdjustorThunks](by-memory/0x0047084f-0x004708c7.BrowserComAdjustorThunks.md) and [UID:00033M][0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks](by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md).

## Browser DocHost/ShowUI Stub Method Map

[UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) carries the source-bearing method bodies for the Browser `IDocHostUIHandler` and `IDocHostShowUI` views. Keep these as Browser methods in `NexusTK/browser/Browser.cpp`; do not route them to BrowserWindow, BrowserControlPaneOld, BrowserThread, the broad non-emitting aggregate, or the compiler adjustor thunk pages.

| Vtable address | Function address | Source method | Behavior |
| ---: | ---: | --- | --- |
| `0x006138c8` | `0x0046fc40` | `Browser::ShowContextMenu` | Returns `S_OK`; first base `IDocHostUIHandler` callback after adjusted IUnknown slots. |
| `0x006138cc` | `0x0046fbd0` | `Browser::GetHostInfo` | Writes `DOCHOSTUIINFO::cbSize = 0x14` and `dwFlags = 0x10097`, then returns `S_OK`. The flags decompose to `DOCHOSTUIFLAG_DIALOG`, `DISABLE_HELP_MENU`, `NO3DBORDER`, `DISABLE_SCRIPT_INACTIVE`, `FLAT_SCROLLBAR`, and `ENABLE_INPLACE_NAVIGATION`. |
| `0x006138d0` | `0x0046fc50` | `Browser::ShowUI` | Returns `E_NOTIMPL`. |
| `0x006138d4` | `0x0046fc00` | `Browser::HideUI` | Returns `E_NOTIMPL`. |
| `0x006138d8` | `0x0046fc80` | `Browser::UpdateUI` | Returns `E_NOTIMPL`. |
| `0x006138dc` | `0x0046fb80` | `Browser::EnableModeless` | Returns `E_NOTIMPL`. |
| `0x006138e0` | `0x0046fc10` | `Browser::OnDocWindowActivate` | Returns `E_NOTIMPL`. |
| `0x006138e4` | `0x0046fc20` | `Browser::OnFrameWindowActivate` | Returns `E_NOTIMPL`. |
| `0x006138e8` | `0x0046fc30` | `Browser::ResizeBorder` | Returns `E_NOTIMPL`. |
| `0x006138ec` | `0x0046fc60` | `Browser::TranslateAccelerator` | Returns `E_NOTIMPL`. |
| `0x006138f0` | `0x0046fbf0` | `Browser::GetOptionKeyPath` | Returns `E_NOTIMPL`. |
| `0x006138f4` | `0x0046fba0` | `Browser::GetDropTarget` | Returns `E_NOTIMPL`. |
| `0x006138f8` | `0x0046fbb0` | `Browser::GetExternal` | Writes `*ppDispatch = 0`, then returns `E_NOTIMPL`; no binary null guard is present. |
| `0x006138fc` | `0x0046fc70` | `Browser::TranslateUrl` | Returns `E_NOTIMPL`. |
| `0x00613900` | `0x0046fb90` | `Browser::FilterDataObject` | Returns `E_NOTIMPL`; final base `IDocHostUIHandler` callback. |
| `0x00613914` | `0x0046fca0` | `Browser::ShowMessage` | Returns `S_OK`; first `IDocHostShowUI` callback after adjusted IUnknown slots. |
| `0x00613918` | `0x0046fc90` | `Browser::ShowHelp` | Returns `S_OK`; second `IDocHostShowUI` callback. |

B006 rechecked this map against local IDA export `.lst` lines `192586-192754` and vtable lines `808512-808533`, local decompiler export `.c` lines `110013-110115`, and local SDK `MsHtmHst.h` method/flag order. `IDocHostUIHandler2` is rejected because the Browser slice has only the 15 base callbacks and no `GetOverrideKeyPath` extension slot. BrowserWindow owns a similar but separate DocHost island at [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), with different vtable addresses and different host-info behavior.

## Ownership Notes

- `Browser::~Browser` and `ScalarDeletingDestructor` call `UnadviseConnectionPoint`, explicitly release `m_webBrowser`, destroy hosted windows, and clear URL/string state; the trailing guard/release is the compiler-generated `CComQIPtr<IWebBrowser2>` member destructor.
- `Browser::~Browser` restores all five Browser interface vptrs, releases/destroys `m_navigationBuffer` at `+0x228`, calls `ShowCursor(0)`, unadvises `DIID_DWebBrowserEvents2` through `m_webBrowser`/`m_adviseCookie`, releases the COM pointer, destroys `m_hWnd`, destroys `m_currentUrl`, and includes a defensive second `m_webBrowser` release check after string destruction.
- `Browser::QueryInterface` should read as `InlineIsEqualGUID`/`IsEqualIID` checks against SDK/browser COM GUID symbols, not raw byte-array comparisons.
- `Browser::AddRef` returns fixed `2` and `Browser::Release` returns fixed `1`; lifetime is controlled by the old browser pane/thread rather than a real COM reference count.
- `Browser::Invoke` receives the adjusted `IDispatch` view and handles browser event dispatch IDs such as download begin/complete, navigation, and new-window cases. Dispatch id `106` increments `m_pendingDownloadCount`; id `104` decrements it and, when it reaches zero with `m_showBrowserAfterLoad` set, shows/updates the hosted HWND, restores cursor visibility, clears the flag, and posts a browser notification. Id `250` is the strongest `BeforeNavigate2`-style route; it inspects target URLs, handles `close()`/`res://`, posts private message `0x500`, calls `Browser::Navigate`, stores fallback/current URL text, and cancels navigation where appropriate. Id `251` is a navigation-complete style guard, id `263` is a new-window/current-URL notification style route, id `270` is a window-closing style route, and unknown DISPIDs return `DISP_E_MEMBERNOTFOUND`.
- [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md) now emits a first-draft `Browser::Invoke` body on the exact child page. The draft uses standard OLE `DISPPARAMS` accessors `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))` for the reversed URL argument and `V_BOOLREF(&params->rgvarg[0])` for the cancel pointer, with inferred source-facing event/message/notification/string helper names preserved as caveats.
- DocHost/ShowUI stubs are represented by the `+0x0c` and `+0x10` vtable slices. [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) now names every method in SDK order and emits first-draft C++ for the source-bearing callbacks. `0x0046fbd0` is `Browser::GetHostInfo`; it writes `cbSize = 0x14` and `dwFlags = 0x10097`, not the BrowserWindow conditional `0x1009f` path.
- [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) is the corrected owner/name for the former `BrowserWindowNavigate` page. Its three callers pass Browser objects from `BrowserThread +0x68`, adjusted `Browser::Invoke` interface state, and `BrowserControlPaneOld +0x110`; the source-ready body uses `m_webBrowser` and Browser `+0x228` URL storage.
- `Browser::Navigate` has source signature `void Browser::Navigate(const wchar_t *url)`. It creates a raw URL BSTR, four `CComVariant` values, and an empty `VT_UI1` SAFEARRAY, calls inherited `IWebBrowser::Navigate` through vtable slot `+0x2c` with `navNoHistory`, and performs the exact observed cleanup while ignoring Navigate and cleanup HRESULTs. It stays on `Browser`, not `BrowserWindow`.
- Host initialization assigns the created `IOleObject` into `CComQIPtr<IWebBrowser2> m_webBrowser`, preserving the Advise HRESULT, then constructs `CComQIPtr<IOleInPlaceObject>` for `SetObjectRects`. This source shape accounts for IID_IWebBrowser2 QI, smart-pointer assignment, and the destructor's member cleanup.
- Helper/GUID placement remains outside the class body: `AdviseConnectionPoint`, `UnadviseConnectionPoint`, and `PostBrowserNotification` stay Browser-module helpers; the former `BrowserVariantFromString` label is historical compiler/template lowering for `CComVariant(LPCOLESTR)` and is not a project helper; `InlineIsEqualGUID` is SDK/header-inline source-use evidence; Browser COM GUID constants should use SDK declarations or `DEFINE_GUID` fallback; browser globals stay in [UID:0000HV][Browser](by-file/Browser.md) unless exact storage docs prove another owner.
- The shared COM event id and IID evidence is tracked in [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) and [UID:0000T2][DIID_DWebBrowserEvents2](by-global/DIID_DWebBrowserEvents2.md).

Rejected alternatives: BrowserWindow ownership is rejected because BrowserWindow has its own navigate helper at `0x00469ca0` and separate COM host methods. BrowserControlPaneOld ownership is rejected because it holds/allocates a `Browser *` but does not own Browser interface methods. BrowserThread ownership is rejected because it owns thread/OLE setup and calls `Browser::Navigate` but does not own Browser's COM implementation. A no-code compiler-generated class classification is rejected because Browser contains source-bearing COM methods, event handling, and navigation behavior. Scalar deleting destructor and adjustor thunks remain compiler glue. `BrowserLegacy.cpp` remains plausible but unproven and should not change owner/emitter routing.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:0000HV][Browser](by-file/Browser.md). The child class is now `90/93`, and the direct file parent is `89/92`, so both sides clear the corrected `85/85` gate. The file parent is a direct owner because it documents the cohesive browser/OLE source module containing `Browser`, `BrowserWindow`, `BrowserThread`, `BrowserControlPaneOld`, `browser::Notification`, source-authored browser COM helpers, and related vtable/string data. This page emits declaration-level first-draft C++ only; method bodies remain on exact method children. Remaining declaration caveats are the exact project wide-string wrapper type at `+0x230`, exact allowed-prefix buffer extent, and final one-file versus browser-folder split.

## IDA Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms `~Browser` at `0x0046f480-0x0046f53e`, `QueryInterface` at `0x0046f540-0x0046f66f`, `IDispatch` metadata stubs at `0x0046f7e0`, `0x0046f7f0`, and `0x0046f800`, `Invoke` at `0x0046f810-0x0046fab6`, and `ScalarDeletingDestructor` at `0x00470330-0x00470406`.
- Live vtable xrefs show Browser vtable slices stored by the destructor, constructor/setup path, and scalar deleting destructor around `0x0046f4ad-0x0046f4c8`, `0x00470009-0x00470024`, and `0x0047035d-0x00470378`.
- `QueryInterface` compares browser COM GUID/IID data around `0x00631580-0x00631610`, including a call to [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md). That helper is now treated as Windows SDK/header-inline GUID equality source-use evidence, not Browser-authored product logic.
- `~Browser` and `ScalarDeletingDestructor` both reset Browser vtables, release string/state at offset `+0x228`, call `UnadviseConnectionPoint` at `0x00470980` for the connection point/interface at `+0x18` / cookie at `+0x1c`, release the COM interface, destroy the hosted window at `+0x14`, and clean up the wide/string field at `+0x230`.
- `Browser::Invoke` handles dispatch/event cases including `104`, `106`, `250`, `251`, `263`, and `270`, posts thread message `0x500` for close/resource redirects, calls [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) for close/resource navigation handling, and constructs/posts [UID:000014][browser__Notification](by-class/browser__Notification.md) payloads inline or through `0x00470f20`.
- 2026-06-07 Batch080 live IDA MCP `py_eval` rechecked the promoted Browser method starts: `0x0046f480-0x0046f53e`, `0x0046f540-0x0046f66f`, `0x0046f7e0-0x0046f7e8`, `0x0046f7f0-0x0046f7f8`, `0x0046f800-0x0046f808`, `0x0046f810-0x0046fab6`, and `0x00470330-0x00470406`. The same pass confirmed Browser vtable-slice xrefs at `0x00613830` and `0x00613908` from `0x0046f480`, `0x0046ff50`, and `0x00470330`, matching destructor, setup, and scalar-delete vptr stores.

## Score Rationale

- Completion `90`: the page carries exact Browser method boundaries, source placement, vtable-slice meanings, QueryInterface routes, source-facing field names, `CComQIPtr<IWebBrowser2>` member shape, connection cleanup, dispatch-event behavior, notification posting, rejected alternatives, and a complete declaration block. Remaining work is limited to final custom string type, exact allowed-prefix extent, and final browser source split.
- Confidence `93`: class identity, direct browser-module ownership, and the `+0x18` smart-pointer type are backed by IID_IWebBrowser2 host QI, ATL assignment/destructor lowering, live target/caller evidence, child pages, GUID/string/vtable pages, and linked browser subsystem docs. Confidence remains below final audit for the independent string/buffer and source-split caveats.

## Open Questions

- Normalize `WideString` to the final project wide-string wrapper name once support docs settle it.
- Recheck constructor/setup writes to confirm the exact `m_allowedUrlPrefix` start and array extent before final source emission.
- Confirm whether modern and old browser classes coexisted in one `Browser.cpp` file or were separate `.cpp` files in the original project.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md)
- [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-07-12 B001 UID00033K implementation callback:
  - Changed score from `88/90` to `90/93` and changed the complete managed declaration's `m_webBrowser` field from a raw `IWebBrowser2 *` to `CComQIPtr<IWebBrowser2>`.
  - Summary/evidence: host initialization assigns `IOleObject *` through ATL QI for IID_IWebBrowser2, uses the interface for connection-point advice and an `IOleInPlaceObject` smart query, and destructor lowering contains explicit release plus compiler member cleanup. The source-ready UID00033K body calls inherited `IWebBrowser::Navigate`, while UID000335 is historical `CComVariant(LPCOLESTR)` compiler/template lowering rather than a project free helper.

- What existed before: the page documented the COM/browser responsibility, major methods, ownership notes, and IDA evidence, but completion/confidence metadata remained `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: destructor, QueryInterface, Invoke, scalar delete, GUID helper, and vtable/string references make the class identity strong; exact multiple-inheritance layout and final old/new browser source split still need deeper reconstruction.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:78`, with stale generated-output evidence references and only partial method-boundary notes.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA confirms exact ranges for the destructor, QueryInterface, COM stubs, Invoke, scalar deleting destructor, Browser vtable-slice stores, GUID comparison helper, connection-point cleanup, hosted-window destruction, string cleanup, and browser notification posting. Completion remains below high because final COM interface declarations, vtable slice naming, and old/new browser source split still need a full layout pass.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the destructor, QueryInterface, Invoke, and scalar deleting destructor starts at `0x0046f480`, `0x0046f540`, `0x0046f810`, and `0x00470330`. `AUTOGEN_PARENT_UID` remains blank even though [UID:0000HV][Browser](by-file/Browser.md) is the likely owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07 Batch080 class coverage pass:
  - Changed score from `78/84` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000HV` because this class and the direct [UID:0000HV][Browser](by-file/Browser.md) source root both clear the corrected `85/85` gate.
  - Evidence: live IDA MCP rechecked all promoted Browser method boundaries and Browser vtable-slice xrefs from destructor/setup/scalar-delete stores; linked browser file and read-only-data docs support direct source-module ownership. C++ remains blank because the final COM interface declaration, multiple-inheritance layout, and exact header/source split remain unresolved, not because a separate high-score gate blocks first-draft code.
- 2026-06-19 B013 source-quality sync:
  - Added [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) as a Browser method and corrected stale BrowserWindow ownership in the support route.
  - Summary/evidence: B013 local PE checks show `0x00470dd0` is called with Browser objects from `BrowserThread +0x68`, adjusted `Browser::Invoke` interface state, and the old BrowserControlPaneOld child Browser pointer; the method body reads Browser fields including `+0x18` and `+0x228`.
- 2026-06-20 B007 Rule 26 source-quality incorporation:
  - Changed score from `85/86` to `88/90` and populated declaration-level first-draft C++ for the legacy WebBrowser COM client/event-sink object.
  - Summary/evidence: incorporated the exact Browser source-placement decision, five COM vtable-slice table, QueryInterface IID-to-pointer table, source-facing field layout, behavior summaries, helper/GUID placement, rejected alternatives, and C++ caveats from the B007 report. Method bodies still belong on exact child pages; scalar deleting destructor and adjustor thunks remain compiler glue.
- 2026-06-20 B004 Browser COM stub method sync:
  - Added the full [UID:000330][0x0046f670-0x0046f808.BrowserComStubMethods](by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md) pre-`Invoke` COM stub address/name table and corrected the stale generic interpretation of `0x0046f7e0`, `0x0046f7f0`, and `0x0046f800` to `IDispatch::GetIDsOfNames`, `GetTypeInfo`, and `GetTypeInfoCount`.
  - Summary/evidence: local PE/vtable/import reanalysis confirms fixed `AddRef`/`Release`, `IOleClientSite` stubs, `IOleWindow`/`IOleInPlaceSite` stubs, `m_hWnd`/`GetClientRect` behavior, and compiler-generated adjustor thunk separation.
- 2026-06-21 B006 Browser DocHost/ShowUI method sync:
  - Added the exact [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) method map for the `IDocHostUIHandler` and `IDocHostShowUI` slices, including `GetHostInfo` flag decomposition and BrowserWindow/`IDocHostUIHandler2` rejections.
  - Summary/evidence: B006 local IDA export and SDK checks resolve the remaining `sub_*` names in the target while preserving the QueryInterface caveat that direct DocHost UI/ShowUI IID exposure was not observed.
- 2026-06-29 B006 Browser destructor implementation callback:
  - Replaced the old [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md) first-draft blocker with source-ready destructor status and preserved the `m_webBrowser` static-type caveat plus `m_currentUrl` type caveat.
  - Summary/evidence: accepted B006 report `00032Y-BrowserNonDeletingDestructor-empty-emitter-source-quality.md` rechecked the ordinary destructor and [UID:000338][0x00470330-0x00470406.BrowserScalarDeletingDestructor](by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md) scalar wrapper with current MCP evidence. [UID:00032Y][0x0046f480-0x0046f53e.BrowserNonDeletingDestructor](by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md) now emits `Browser::~Browser()`; [UID:000338][0x00470330-0x00470406.BrowserScalarDeletingDestructor](by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md) remains no-handwritten-source scalar deleting destructor glue with only a formal coverage comment.
- 2026-06-29 B002 Browser QueryInterface implementation callback:
  - Score unchanged at `88/90`.
  - Summary/evidence: synchronized [UID:00032Z][0x0046f540-0x0046f66f.BrowserQueryInterface](by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md) as source-ready first draft for `Browser::QueryInterface(REFIID riid, void **ppvObject)`. Current MCP session `3fa0535f` confirms the body range, returned `+0/+4/+8` interface views, no-`AddRef` behavior, `E_NOINTERFACE` failure path, and adjustor thunk callers. The DocHost UI/ShowUI slices remain part of the class layout, but direct DocHost QueryInterface exposure remains unobserved.
- 2026-07-02 B007 UID000331 implementation callback:
  - Score unchanged at `88/90`.
  - Summary/evidence: synchronized [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md) as first-draft `Browser::Invoke` source on the exact child page. Owner/emitter remain Browser; the switch-support bytes remain compiler-generated from the source switch, and the exact event/helper/string-wrapper names remain inferred rather than original-proof.
- 2026-07-03 B009 UID0002P3 constructor support sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: added support declaration `Browser::Browser(const wchar_t *initialUrl)` for [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md). Current MCP session `b010_00032w_20260703` confirms the constructor-side Browser allocation size `0x234`, five interface slices, `m_hWnd`/`m_webBrowser` clearing, `m_navigationBuffer` ownership of an allocated copy of the initial URL, `m_stateFlags = 0x0101`, and `m_currentUrl` construction. The support route keeps Browser private-field initialization inside Browser and rejects raw target-local field writes from BrowserControlPaneOld.
