** TARGET-REPORT-UID:000013 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 source-quality report: [UID:000013] Browser

Report status: FINISHED  
Report-only pass: no by-* documentation was edited, and `by-memory/-coverage-report.md` was not edited.  
Agent folder: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007`  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Browser.md`  
Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\000013-Browser-class-source-quality.md`

## Current target state

- UID: `000013`
- Current label: `Browser`
- Current score: `COMPLETION:85`, `CONFIDENCE:86`
- Current metadata: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`
- Current source route: `auto-generated/NexusTK/browser/Browser.cpp`
- Current formal C++: blank
- Current documented blocker: COM interface declaration, multiple-inheritance layout, and old-vs-modern browser source split still unresolved.

## Recommendation summary

Keep [UID:000013] `Browser` as a source-bearing class under [UID:0000HV] `Browser`. Raise the class page to `88/90` after implementation because the vtable slices, COM interface roles, core field layout, source owner, and old/new ownership boundaries are now strong enough for a class declaration draft. Do not emit scalar deleting destructor code or adjustor thunk code as handwritten source. Method bodies should continue to be emitted by the method child pages, not by the aggregate class page.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000HV
EMITTER_UIDS:0000HV
```

Recommended C++ policy: populate the class page with a declaration-level first draft, not a large aggregate implementation. The declaration should describe the legacy WebBrowser COM client/event-sink object. It should not merge BrowserWindow, BrowserThread, BrowserControlPane, or BrowserControlPaneOld code into this class.

No `by-memory/-coverage-report.md` row change is recommended by this class-only pass. A `by-class/-coverage-report.md` replacement row is included below.

## Evidence checked

Rules and local instructions:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Primary and support docs:

- `source-3/project-documentation/by-class/Browser.md`
- `source-3/project-documentation/by-file/Browser.md`
- `source-3/project-documentation/by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`
- `source-3/project-documentation/by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md`
- `source-3/project-documentation/by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`
- `source-3/project-documentation/by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md`
- `source-3/project-documentation/by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`
- `source-3/project-documentation/by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`
- `source-3/project-documentation/by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md`
- `source-3/project-documentation/by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`
- `source-3/project-documentation/by-memory/0x00470fdc-0x0047107c.BrowserOleAdjustorAndDelegationThunks.md`
- `source-3/project-documentation/by-memory/0x00613830-0x00613e18.BrowserVtablesAndStrings.md`
- `source-3/project-documentation/by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`
- `source-3/project-documentation/by-global/DIID_DWebBrowserEvents2.md`
- `source-3/project-documentation/by-global/BrowserDispatchEventId.md`
- `source-3/project-documentation/by-global/BrowserInitFlags.md`
- `source-3/project-documentation/by-global/BrowserMessageId.md`
- `source-3/project-documentation/by-class/BrowserWindow.md`
- `source-3/project-documentation/by-class/BrowserControlPane.md`
- `source-3/project-documentation/by-class/BrowserControlPaneOld.md`
- `source-3/project-documentation/by-class/BrowserThread.md`
- `source-3/project-documentation/auto-generated/NexusTK/browser/Browser.cpp`
- `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/by-class/-coverage-report.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`

Prior reports used as leads only:

- `Agent-B001/research/executed/older/0000ZF-BrowserOleLegacyAndHelpers.md`
- `Agent-B002/research/executed/000218-InlineIsEqualGUID.md`
- `Agent-B009/research/0000Z6-BrowserControlPaneCore-source-quality.md`
- `Agent-B009/research/executed/00020V-00020W-BrowserWindowWndProcClone-source-quality.md`

Local binary/decompiler exports:

- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`

IDA MCP availability:

- Checked `http://127.0.0.1:13337/mcp` with `tools/list`; it was unavailable in this session: `Unable to connect to the remote server`.
- This report therefore uses checked by-* docs plus local IDA C/listing exports for instruction-level evidence.

## Exact source-placement decision

`Browser` should remain under [UID:0000HV] `Browser`, with declarations and child method bodies routed to `NexusTK/browser/Browser.cpp` unless a later project-level source split creates a separate browser legacy file. The most defensible original-source shape is:

1. `browser/Browser.cpp` and `browser/Browser.h` contain shared browser support, GUIDs, globals, old Browser COM sink code, and modern browser support classes in one broad browser module.
2. A future split into `BrowserWindow.cpp`, `BrowserControlPane.cpp`, and `BrowserOld.cpp` or `BrowserLegacy.cpp` is plausible, but there is no source/path proof in the current docs or exports. Do not move [UID:000013] to a speculative file now.
3. `Browser` is not owned by `BrowserWindow`, `BrowserThread`, `BrowserControlPane`, or `BrowserControlPaneOld`. Those classes consume or host it; they do not own its source-bearing COM methods.

Boundary decisions:

- `BrowserWindow` owns its own Win32/browser host path and its own `NavigateBrowser` at `0x00469ca0`. It does not own [UID:00033K] `BrowserNavigate` at `0x00470dd0`.
- `BrowserControlPaneOld` owns the old pane wrapper, allocates/holds a `Browser *` at its own offset, and dispatches old UI commands. It should reference `Browser`, not absorb Browser's methods.
- `BrowserThread` owns COM/OLE initialization, the browser host thread loop, and calls `Browser::Navigate` from its host setup path. It should not own the Browser object methods.
- `BrowserControlPane` and `BrowserControlPaneCore` are the newer control path. They should remain separate from the legacy `Browser` COM/event-sink object.

## Exact COM layout and vtable slice meanings

The five vtable pointer stores restored by the ordinary destructor and scalar deleting destructor are meaningful source evidence, not unrelated raw data. The local listing gives the contiguous Browser vtable region at `0x00613830-0x00613918`; the destructor restores views at object offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`.

Recommended source-facing multiple inheritance:

```cpp
class Browser :
    public IOleClientSite,
    public IOleInPlaceSite,
    public IDispatch,
    public IDocHostUIHandler,
    public IDocHostShowUI
```

Rationale:

- `IOleClientSite` is the primary view at object `+0x00`. `QueryInterface` returns base `this` for `IID_IUnknown` and `IID_IOleClientSite`.
- `IOleInPlaceSite` is the view at object `+0x04`. `QueryInterface` returns `this + 4` for `IID_IOleInPlaceSite` and the `IID_IOleWindow` comparison. `IOleWindow` should not be a separate base; it is already a base of `IOleInPlaceSite`.
- `IDispatch` is the view at object `+0x08`. `QueryInterface` returns `this + 8` for both `IID_IDispatch` and `DIID_DWebBrowserEvents2`. Do not model `DWebBrowserEvents2` as a separate data-bearing C++ base; it is the dispatch event-sink identity for the same IDispatch view.
- The object has a full `IDocHostUIHandler`-shaped vtable at object `+0x0c` and a full `IDocHostShowUI`-shaped vtable at object `+0x10`. The local `Browser::QueryInterface` export did not show `IID_IDocHostUIHandler` or `IID_IDocHostShowUI` returns for this class, so the target doc should explicitly preserve that evidence rather than claiming proven QI exposure. The vtable slot counts and stub names are nevertheless strong enough to declare those source-facing interfaces and document the QI exposure as "not observed from this method export".

Do not add a separate `IUnknown` base. All COM interfaces inherit `IUnknown`.

### Vtable slice table

| Object offset | Vtable address | Best source-facing interface | Evidence |
|---:|---:|---|---|
| `+0x00` | `0x00613830` | `IOleClientSite` primary view | QI returns base pointer for `IID_IUnknown` and `IID_IOleClientSite`; slots match `QueryInterface`, fixed `AddRef`, fixed `Release`, six `IOleClientSite` stubs, and a compiler scalar deleting destructor tail. |
| `+0x04` | `0x0061385c` | `IOleInPlaceSite` / `IOleWindow` view | QI returns `this + 4` for `IID_IOleInPlaceSite` and the `IID_IOleWindow` helper comparison; slots match adjusted IUnknown, `GetWindow`, `ContextSensitiveHelp`, and the `IOleInPlaceSite` activation/window-context callbacks. |
| `+0x08` | `0x0061389c` | `IDispatch` / `DWebBrowserEvents2` event-sink view | QI returns `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`; slots match adjusted IUnknown, three IDispatch metadata stubs, and `Invoke`. |
| `+0x0c` | `0x006138bc` | `IDocHostUIHandler`-style view | Slots after adjusted IUnknown match the 15 `IDocHostUIHandler` methods: `ShowContextMenu`, `GetHostInfo`, `ShowUI`, `HideUI`, `UpdateUI`, `EnableModeless`, `OnDocWindowActivate`, `OnFrameWindowActivate`, `ResizeBorder`, `TranslateAccelerator`, `GetOptionKeyPath`, `GetDropTarget`, `GetExternal`, `TranslateUrl`, `FilterDataObject`. |
| `+0x10` | `0x00613908` | `IDocHostShowUI`-style view | Slots after adjusted IUnknown match `ShowMessage` and `ShowHelp`. |

### QueryInterface exact table

The `0x0046f540-0x0046f66f` export supports this exact table:

| Requested IID | Returned pointer | Recommendation |
|---|---:|---|
| `IID_IUnknown` | `this + 0` | Keep primary COM identity through `IOleClientSite`. |
| `IID_IOleClientSite` | `this + 0` | Name primary base `IOleClientSite`. |
| `IID_IOleInPlaceSite` | `this + 4` | Name second base `IOleInPlaceSite`. |
| `IID_IOleWindow` | `this + 4` | Treat as inherited `IOleWindow` view through `IOleInPlaceSite`, not a separate base. |
| `IID_IDispatch` | `this + 8` | Name third base `IDispatch`. |
| `DIID_DWebBrowserEvents2` | `this + 8` | Treat as event-sink identity implemented through the IDispatch view. |
| Other IID | `0`, `E_NOINTERFACE` | Do not infer extra QI routes unless a future live IDA check proves them. |

The current generated/simulated class material that labels the slices as `IUnknown`, `IOleClientSite`, `IDocHostUIHandler`, `IDispatch`, and `IServiceProvider` should be rejected as stale/source-quality-poor. It confuses COM base identity with concrete C++ vptr layout and does not match the checked QueryInterface table.

## Method and child-page inventory

Source-bearing Browser children:

- [UID:00032Y] `BrowserNonDeletingDestructor`, `0x0046f480-0x0046f53e`: source destructor `Browser::~Browser()`.
- [UID:00032Z] `BrowserQueryInterface`, `0x0046f540-0x0046f66f`: source method `Browser::QueryInterface(REFIID, void **)`.
- [UID:000330] `BrowserComStubMethods`, `0x0046f670-0x0046f808`: COM stub methods for `AddRef`, `Release`, `IOleClientSite`, `IOleInPlaceSite`, and IDispatch metadata.
- [UID:000331] `BrowserInvokeAndSwitchTable`, `0x0046f810-0x0046fb80`: source method `Browser::Invoke(...)` plus local switch table bytes.
- [UID:000332] `BrowserDocHostShowUiStubs`, `0x0046fb80-0x0046fca5`: `IDocHostUIHandler` and `IDocHostShowUI` stub methods.
- [UID:00033K] `BrowserNavigate`, `0x00470dd0-0x00470f10`: source method `Browser::Navigate(const wchar_t *url)`.

Compiler/no-code children:

- [UID:000338] `BrowserScalarDeletingDestructor`, `0x00470330-0x00470406`: compiler scalar deleting destructor. Do not write handwritten source for this page; route source behavior to `Browser::~Browser()`.
- [UID:00034E] `BrowserOleAdjustorAndDelegationThunks`, `0x00470fdc-0x0047107c`: compiler adjustor/delegation thunks for secondary COM interface views. Do not write handwritten source for these thunks; class multiple inheritance and source methods cause their emission.

Aggregate/non-emitting support:

- [UID:0000ZF] `BrowserOleLegacyAndHelpers`, `0x0046f010-0x004710b8`: broad split index only. Its older B001 report still has stale `0x00470dd0` BrowserWindow ownership language; the current by-memory child [UID:00033K] correctly routes `0x00470dd0` to `Browser`.
- [UID:0003NT] `BrowserVtablesAndStrings`, `0x00613830-0x00613e18`: mixed data/string index; should document the vtable slice table above.
- [UID:0003OH] `BrowserComGuidConstants`, `0x00631580-0x00631660`: Browser COM GUID support data; source should prefer SDK declarations or `DEFINE_GUID` fallback in Browser COM support, not per-class hardcoded arrays.

## Field layout recommendation

The layout below is the best current source-quality field set. Offsets are base-object offsets. Decompiler variables inside `Browser::Invoke` often use the `IDispatch` slice pointer (`base + 8`), so raw offsets in that function must be adjusted back to base offsets before naming fields.

| Offset | Recommended field name | Type recommendation | Confidence | Evidence and caveat |
|---:|---|---|---|---|
| `+0x00` | `IOleClientSite` vptr | compiler vptr | High | Primary vtable store and QI primary identity. |
| `+0x04` | `IOleInPlaceSite` vptr | compiler vptr | High | QI returns `this + 4` for `IID_IOleInPlaceSite` and `IID_IOleWindow`. |
| `+0x08` | `IDispatch` vptr | compiler vptr | High | QI returns `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`; `Invoke` receives this adjusted view. |
| `+0x0c` | `IDocHostUIHandler` vptr | compiler vptr | Medium-high | Slot count/order matches `IDocHostUIHandler`; QI exposure not observed. |
| `+0x10` | `IDocHostShowUI` vptr | compiler vptr | Medium-high | Slot count/order matches `IDocHostShowUI`; QI exposure not observed. |
| `+0x14` | `m_hWnd` | `HWND` | High | Destructor destroys it; `GetWindow`/`GetWindowContext` return/use it through adjusted `this`. |
| `+0x18` | `m_webBrowser` | `IWebBrowser2 *` or `IUnknown *` stored as WebBrowser automation object | Medium-high | Destructor unadvises/releases it; `Navigate` calls its vtable; connection-point helper receives it. Final static type may be `IWebBrowser2 *`, `IWebBrowser2`-compatible dispatch pointer, or `IUnknown *` depending on original headers. Use `m_webBrowser` in docs and note static-type caveat. |
| `+0x1c` | `m_adviseCookie` | `DWORD` | High | Passed to `UnadviseConnectionPoint` with `DIID_DWebBrowserEvents2`. |
| about `+0x20` to `+0x221` | `m_allowedUrlPrefix` | wide-character buffer | Medium | `Invoke` checks a non-empty wide string and rejects BeforeNavigate URLs not beginning with that prefix. The exact start is obscured by adjusted `IDispatch` pointer math; use a field range rather than a precise array size until constructor writes are rechecked. |
| `+0x222` | `m_showBrowserAfterLoad` | `bool` or `unsigned char` | Medium-high | `Invoke` tests this byte after pending-count decrement; if set, it shows the hosted window and restores cursor visibility. |
| `+0x224` | `m_pendingDownloadCount` | `int` or `LONG` | High | `Invoke` increments on dispatch id `106` and decrements on dispatch id `104`. |
| `+0x228` | `m_navigationBuffer` | `wchar_t *` or owned buffer pointer | Medium | Ordinary and scalar destructors free the pointer with the wide-string/buffer cleanup helper. Keep distinct from the string object at `+0x230`. |
| `+0x22c` | `m_stateFlags` | `WORD` or `unsigned int` subfield | Medium-high | Old control pane setup writes `0x0101`; BrowserInitFlags doc should keep this as a state word/bitmask, not a proven enum. |
| `+0x230` | `m_currentUrl` | project wide-string object | Medium-high | Constructed/destroyed as a string object; `BeforeNavigate` res-prefix path stores the localized fallback/current URL here. Final project type name is still support-doc dependent. |
| `0x234` total | object size | allocation size | High | Old control pane setup allocates/initializes a `0x234` byte Browser object. |

Rejected field alternatives:

- Do not call `+0x18` only `m_unknown`; behavior is consistently browser-control/automation related.
- Do not merge `+0x228` and `+0x230`; destructor treats them as distinct owned resources.
- Do not leave the `+0x222`/`+0x224` fields as raw `byte_`/`dword_` names. Their dispatch-event behavior is clear enough for source-facing load/visibility names.
- Do not treat `0x0101` at `+0x22c` as a final enum name. It is a Browser state/initialization flag word with insufficient bit-level proof.

## Behavior summary to add to target/support docs

Destructor behavior:

- Restores all five Browser interface vptrs.
- Releases/destroys the owned navigation buffer at `+0x228`.
- Calls `ShowCursor(0)`.
- If `m_webBrowser` is non-null, unadvises `DIID_DWebBrowserEvents2` using `m_adviseCookie`, releases the COM pointer, and clears the field.
- Destroys `m_hWnd` if non-null.
- Destroys the wide/current URL string object at `+0x230`.
- Contains a defensive second `m_webBrowser` release check after string destruction; this should be documented as compiler/source defensive cleanup, not a separate field.

QueryInterface behavior:

- Uses GUID comparisons through the SDK-equivalent `InlineIsEqualGUID` helper.
- Returns the exact pointer adjustments listed in the table above.
- Returns `E_NOINTERFACE` and clears `*ppvObject` for unsupported IIDs.

AddRef/Release behavior:

- `AddRef` returns fixed `2`.
- `Release` returns fixed `1`.
- This object is controlled by its containing old browser pane/thread lifetime rather than a real COM reference count.

Invoke behavior:

- The method receives the `IDispatch` adjusted view, so raw decompiler offsets must be converted back to Browser base offsets.
- Dispatch id `106` increments `m_pendingDownloadCount`.
- Dispatch id `104` decrements `m_pendingDownloadCount`; when it reaches zero and `m_showBrowserAfterLoad` is set, it shows and updates the hosted HWND, restores cursor visibility, clears the flag, and posts a `browser::Notification`.
- Dispatch id `250` is the strongest `BeforeNavigate2`-style route. It inspects the target URL, handles `close()`/`res://` cases, posts browser private thread message `0x500`, calls `Browser::Navigate` as needed, stores localized fallback text for resource URLs, and cancels navigation when appropriate.
- Dispatch id `251` is a navigation-complete style guard/cancel path.
- Dispatch id `263` posts a current-URL/new-window style notification and clears cancel state.
- Dispatch id `270` cancels/handles a window-closing style event.
- Unknown dispatch ids return `DISP_E_MEMBERNOTFOUND`.

Navigate behavior:

- Source-facing name should be `Browser::Navigate`.
- Recommended signature: `void Browser::Navigate(const wchar_t *url)` or `void Browser::Navigate(LPCWSTR url)`.
- It uses the stored browser automation/control pointer at `+0x18`, builds BSTR/VARIANT/SafeArray arguments, calls the browser navigate vtable slot, and cleans up COM variants and temporary BSTR state.
- It must stay on the `Browser` class, not `BrowserWindow`.

DocHost/ShowUI stub behavior:

- The `+0x0c` vtable slice should be documented as `IDocHostUIHandler`-shaped.
- The `+0x10` vtable slice should be documented as `IDocHostShowUI`-shaped.
- Most methods return `S_OK`, `E_NOTIMPL`, or constant host-info style values.
- `0x0046fbd0` is the strongest `IDocHostUIHandler::GetHostInfo` candidate because it writes a flags/constants pair before returning `S_OK`.

## Helper/global/GUID placement

Keep these outside the `Browser` class body:

- `InlineIsEqualGUID` / `IsEqualGUID` / `IsEqualIID`: external SDK inline helper; source should call the SDK-style comparison instead of emitting a project helper.
- `IID_IUnknown`, `IID_IOleClientSite`, `IID_IOleObject`, `IID_IOleWindow`, `IID_IOleInPlaceActiveObject`, `IID_IOleInPlaceObject`, `IID_IOleInPlaceSite`, `IID_IDispatch`, `IID_IWebBrowser2`, `DIID_DWebBrowserEvents2`, `CLSID_WebBrowser`, `IID_IDocHostUIHandler`, `IID_IDocHostShowUI`, `IID_IHTMLDocument2`: Browser COM support constants in [UID:0003OH] and related globals. Use SDK declarations when available; use `DEFINE_GUID` fallback only where the period SDK/header set lacks a symbol.
- `BrowserVariantFromString`: Browser file-level helper for string/variant setup, not a `Browser` member unless a direct `this` use is proven.
- `AdviseConnectionPoint` / `UnadviseConnectionPoint`: Browser file-level COM connection-point helpers.
- `PostBrowserNotification`: Browser or browser-notification file helper, not a Browser method unless direct field ownership is shown.
- `BrowserMessageId`, `BrowserDispatchEventId`, `BrowserInitFlags`: Browser support global/enum docs; update them to use the source-facing names above.
- Browser globals such as `g_pBrowserThread`, `g_pCurrentBrowserHost`, `g_pBrowserDialogOld`, `g_pActiveBrowserWindow`, `g_pBrowserDialog`, `g_activeBrowserPane`, `g_browserWindowClassName`, and browser alert strings should remain in [UID:0000HV] Browser support. `g_pBrowserOverlayLayer`, `g_browserRuntime`, and similar aliases/consumers should not be moved into this class without direct storage evidence.

## First-draft class C++

This is suitable for class-page declaration C++. It intentionally omits method bodies and keeps exact custom string/buffer type names marked for support-doc resolution. It avoids modern C++ features.

```cpp
class Browser :
    public IOleClientSite,
    public IOleInPlaceSite,
    public IDispatch,
    public IDocHostUIHandler,
    public IDocHostShowUI
{
public:
    Browser();
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
    STDMETHOD(ShowUI)(DWORD id, IOleInPlaceActiveObject *activeObject,
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
    IWebBrowser2 *m_webBrowser;
    DWORD m_adviseCookie;

    // Wide prefix buffer used to reject unexpected BeforeNavigate2 URLs.
    // The exact source array size should be filled from constructor writes.
    wchar_t m_allowedUrlPrefix[0x101];

    unsigned char m_showBrowserAfterLoad;
    long m_pendingDownloadCount;
    wchar_t *m_navigationBuffer;
    unsigned short m_stateFlags;
    WideString m_currentUrl;
};
```

Implementation caveats for the C++ block:

- `WideString` is a placeholder for the project wide-string wrapper used by `0x00582b70`, `0x00582d20`, and `0x00584540`. If the support docs have a final type name, use that instead.
- The `m_allowedUrlPrefix` array size is a high-probability draft. If the constructor/setup doc proves the exact array start/length, adjust the declaration there before final source emission.
- The class declaration should not include scalar deleting destructor or adjustor thunk prototypes as source methods.
- If the docs standardize on `LPCWSTR`, `Browser::Navigate(LPCWSTR url)` is equally source-quality. Keep one spelling consistently across [UID:00033K] and [UID:000013].

## Exact target-doc implementation checklist

When the supervisor sends an implementation callback, update `source-3/project-documentation/by-class/Browser.md` as follows:

1. Change metadata to:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000HV
EMITTER_UIDS:0000HV
```

2. Replace the unresolved COM/multiple-inheritance open question with the resolved interface declaration:

```text
Browser is the legacy WebBrowser COM client/event-sink object. Its five vtable views map to IOleClientSite at +0x00, IOleInPlaceSite/IOleWindow at +0x04, IDispatch/DWebBrowserEvents2 at +0x08, IDocHostUIHandler-style callbacks at +0x0c, and IDocHostShowUI-style callbacks at +0x10. Browser::QueryInterface is proven to expose IUnknown/IOleClientSite, IOleInPlaceSite/IOleWindow, and IDispatch/DIID_DWebBrowserEvents2; IDocHostUIHandler and IDocHostShowUI vtable slices exist and should be represented in the class declaration, but direct QI exposure for those IIDs was not observed in the checked export.
```

3. Add the vtable slice table from this report to the class page.

4. Add the field layout table from this report to the class page, with the field names:

```text
m_hWnd
m_webBrowser
m_adviseCookie
m_allowedUrlPrefix
m_showBrowserAfterLoad
m_pendingDownloadCount
m_navigationBuffer
m_stateFlags
m_currentUrl
```

5. Update source-placement language to:

```text
Keep Browser under [UID:0000HV] Browser / NexusTK/browser/Browser.cpp. BrowserWindow, BrowserThread, BrowserControlPane, and BrowserControlPaneOld are consumers or neighboring browser subsystem classes, not owners of Browser's COM methods. A later BrowserLegacy.cpp split remains plausible but unproven.
```

6. Update method child notes:

```text
0x0046f480-0x0046f53e is Browser::~Browser().
0x0046f540-0x0046f66f is Browser::QueryInterface(REFIID, void **).
0x0046f670-0x0046f808 are Browser COM stubs, including fixed AddRef/Release and IOleClientSite/IOleInPlaceSite/IDispatch metadata methods.
0x0046f810-0x0046fb80 is Browser::Invoke plus its switch table.
0x0046fb80-0x0046fca5 are Browser IDocHostUIHandler/IDocHostShowUI stub callbacks.
0x00470330-0x00470406 is the compiler scalar deleting destructor and should not emit handwritten source.
0x00470dd0-0x00470f10 is Browser::Navigate(const wchar_t *url).
0x00470fdc-0x0047107c is compiler adjustor/delegation thunk glue caused by the multiple-inheritance COM layout and should not emit handwritten source.
```

7. Insert the first-draft class declaration from this report in the formal C++ section if the current documentation standard permits declaration-only class C++ with placeholder project string type. If placeholders are not allowed in formal C++, keep the code block in "First-draft C++" prose and add a precise blocker stating that only the final project wide-string wrapper name and `m_allowedUrlPrefix` array extent remain to normalize.

8. Remove stale language implying `Browser` might be owned by `BrowserWindow` or that `BrowserNavigate` belongs to `BrowserWindow`.

9. Add a rejected-alternatives paragraph:

```text
Rejected alternatives: BrowserWindow ownership is rejected because BrowserWindow has its own navigate helper at 0x00469ca0 and separate COM host methods. BrowserControlPaneOld ownership is rejected because it holds/allocates Browser but does not own the Browser interface methods. A no-code compiler-generated classification is rejected because Browser contains source-bearing COM methods, event handling, and navigation behavior. Scalar deleting destructor and adjustor thunks remain no-code compiler glue.
```

## Exact support-doc updates

Apply these only during a later accepted implementation callback.

### `by-file/Browser.md`

- Add a Browser class source-quality note:

```text
[UID:000013] Browser is the legacy WebBrowser COM client/event-sink object under the Browser source root. It should remain in NexusTK/browser/Browser.cpp unless a later source-tree pass proves a BrowserLegacy.cpp split. Its methods are distinct from BrowserWindow's modern host/window code, BrowserControlPane's newer pane path, BrowserControlPaneOld's wrapper/owner path, and BrowserThread's thread/OLE setup path.
```

- Update the open question about old-vs-modern split to rank alternatives:

```text
Most likely: one broad browser module/file in the recovered source tree. Plausible but unproven: a BrowserLegacy.cpp or BrowserOld.cpp file containing Browser, BrowserThread, BrowserControlPaneOld, and BrowserDialogOld. Rejected for now: moving Browser methods into BrowserWindow or BrowserControlPaneOld.
```

### `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`

- Add the exact IID-to-pointer table from this report.
- Replace generic "GUID checks" wording with SDK/source names:

```text
The source should read as InlineIsEqualGUID/IsEqualIID checks against SDK/browser COM GUID symbols, not raw byte-array comparisons.
```

- Add the negative evidence:

```text
The checked export does not show direct QueryInterface returns for IID_IDocHostUIHandler or IID_IDocHostShowUI from Browser::QueryInterface, even though Browser owns matching vtable slices. Keep that distinction in the source-quality notes.
```

### `by-memory/0x0046f670-0x0046f808.BrowserComStubMethods.md`

- Rename/role recommendations:

```text
0x0046f670: Browser::AddRef(), fixed return 2.
0x0046f680: Browser::Release(), fixed return 1.
0x0046f6f0: IOleInPlaceSite/IOleWindow GetWindow, returns m_hWnd through the adjusted +0x04 interface view.
0x0046f750: IOleInPlaceSite GetWindowContext-style helper that fills hosted-window client rectangles.
0x0046f7e0/0x0046f7f0/0x0046f800: IDispatch metadata stubs, not arbitrary QueryService/QueryStatus names on the class page.
```

### `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`

- Split the source roles:

```text
0x0046fb80-0x0046fc80 are IDocHostUIHandler-shaped callbacks.
0x0046fc90-0x0046fca5 are IDocHostShowUI-shaped callbacks.
0x0046fbd0 is the best GetHostInfo candidate because it writes a host-info flags/constants pair and returns S_OK.
```

### `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md`

- Add field names:

```text
m_hWnd at +0x14, m_webBrowser at +0x18, m_adviseCookie at +0x1c, m_navigationBuffer at +0x228, m_currentUrl at +0x230.
```

- Add that this is the sole source destructor and should absorb behavior from the scalar deleting destructor page.

### `by-memory/0x00470330-0x00470406.BrowserScalarDeletingDestructor.md`

- Keep `RECONSTRUCTABLE` as no-code/compiler-glue policy if it is currently classified that way by local standards, or keep the child page reconstructable only as evidence but with no formal C++.
- Add exact proof:

```text
This wrapper duplicates Browser::~Browser() teardown and conditionally calls operator delete when the scalar deleting destructor flag is set. The handwritten source is Browser::~Browser(); the wrapper is MSVC compiler glue caused by virtual destruction.
```

### `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`

- Add corrected base-offset field names and warn that the decompiler variable is the `IDispatch` adjusted pointer.
- Add dispatch-id names as high-probability:

```text
104: DownloadComplete/visibility-complete style event.
106: DownloadBegin/pending-load increment style event.
250: BeforeNavigate2-style event.
251: NavigateComplete2-style guard.
263: NewWindow/current-URL notification style event.
270: WindowClosing-style event.
```

Use "style" unless another support doc proves exact imported event constant names.

### `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`

- Keep owner/emitter [UID:000013].
- Standardize signature to:

```cpp
void Browser::Navigate(const wchar_t *url)
```

- Add that the static type of `m_webBrowser` may remain `IWebBrowser2 *` versus `IUnknown *` until constructor/CoCreateInstance code confirms it, but source name should be `m_webBrowser`.

### `by-memory/0x00470fdc-0x0047107c.BrowserOleAdjustorAndDelegationThunks.md`

- Add this class-layout explanation:

```text
The thunks are explained by Browser's multiple-inheritance COM layout: secondary interface views at +0x04, +0x08, +0x0c, and +0x10 adjust back to the Browser base before delegating to Browser::QueryInterface/AddRef/Release. They are compiler glue and should not emit handwritten source.
```

### `by-memory/0x00613830-0x00613e18.BrowserVtablesAndStrings.md`

- Add the vtable slice table from this report.
- Mark `%s.%s.Browser`, `Baram.Browser.Window`, `Nexon.Baram.Browser`, `close()`, `javascript:close();`, `pt:close();`, `res://`, `out:blank`, and `http://` as Browser subsystem strings, not proof of BrowserWindow ownership.

### `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`

- Add cross-link to [UID:000013] for interface declaration use.
- Keep SDK/`DEFINE_GUID` policy.
- Do not duplicate GUID byte arrays in the class page.

### `by-global/DIID_DWebBrowserEvents2.md`

- Add that [UID:000013] returns the `IDispatch` view (`this + 8`) for `DIID_DWebBrowserEvents2`, and destructor/scalar cleanup uses the same DIID for connection-point unadvise.

### `by-global/BrowserDispatchEventId.md`

- Add high-probability dispatch-id mapping above, especially id `250` as `BeforeNavigate2` style and ids `104`/`106` as pending-load begin/complete style events.

### `by-global/BrowserInitFlags.md`

- Add that `0x0101` initializes `Browser::m_stateFlags` at object `+0x22c`.
- Keep it as a state/initialization flag word, not a final enum.

### `by-global/BrowserMessageId.md`

- Add that `Browser::Invoke` posts private message `0x500` for close/resource navigation handling.

### Neighbor class docs

- `by-class/BrowserWindow.md`: keep note that `0x00470dd0` belongs to `Browser`; BrowserWindow owns `0x00469ca0`.
- `by-class/BrowserControlPaneOld.md`: add that it owns/holds a `Browser *`, but Browser method source stays on [UID:000013].
- `by-class/BrowserThread.md`: add that it calls `Browser::Navigate` from host setup but does not own the Browser class.
- `by-class/BrowserControlPane.md`: keep modern pane/core separate; do not merge old Browser COM sink details into it.

## Coverage text

Do not edit `by-memory/-coverage-report.md` for this assignment. Exact text:

```text
No by-memory/-coverage-report.md replacement row is recommended for [UID:000013] Browser because this is a by-class source-quality pass and no by-memory coverage row is directly changed.
```

Recommended exact replacement row for `source-3/project-documentation/by-class/-coverage-report.md`:

```text
- [UID:000013][Browser](by-class/Browser.md) : reconstructable : 88% : very strong : B007 source-quality pass resolves Browser as the legacy WebBrowser COM client/event-sink object under [UID:0000HV][Browser](by-file/Browser.md), maps the five vtable slices at +0x00/+0x04/+0x08/+0x0c/+0x10 to IOleClientSite, IOleInPlaceSite/IOleWindow, IDispatch/DWebBrowserEvents2, IDocHostUIHandler-style, and IDocHostShowUI-style views, distinguishes it from BrowserWindow, BrowserThread, BrowserControlPane, and BrowserControlPaneOld, routes GUIDs/helpers through Browser COM support and SDK InlineIsEqualGUID policy, and recommends class-declaration C++ with method bodies left to child pages.
```

## Rejected alternatives and negative evidence

- BrowserWindow ownership for `BrowserNavigate` is rejected. Current [UID:00033K] and local export evidence show `0x00470dd0` uses Browser object fields at `+0x18` and is called from Browser::Invoke and BrowserThread setup; BrowserWindow owns a separate `0x00469ca0` navigate helper.
- BrowserControlPaneOld ownership is rejected. It allocates/holds the Browser object and routes UI commands, but the object has its own COM vtables, destructor, QueryInterface, Invoke, and Navigate methods.
- BrowserThread ownership is rejected. It owns thread/OLE setup and may call `Browser::Navigate`, but it does not own the Browser COM implementation.
- A compiler-generated/no-code classification for the class is rejected. The scalar deleting destructor and adjustor thunks are compiler glue, but the class as a whole contains source-bearing COM, event-dispatch, and navigation behavior.
- Separate `IUnknown` or separate `IOleWindow` C++ base classes are rejected. `IUnknown` is inherited by all COM interfaces, and `IOleWindow` is the base of `IOleInPlaceSite`.
- Treating `DWebBrowserEvents2` as a separate concrete data base is rejected for now. Browser returns the `IDispatch` view for `DIID_DWebBrowserEvents2`, which is the expected event-sink implementation shape.
- Generated/simroot class labels are rejected as authority where they disagree with the checked exports. They are useful leads only.
- A separate `BrowserLegacy.cpp` source file remains plausible but unproven. Do not move the owner/emitter from [UID:0000HV] without stronger source-tree evidence.

## Open questions and closure status

1. Exact `IDocHostUIHandler`/`IDocHostShowUI` QueryInterface exposure:
   - Checked: Browser QueryInterface export, GUID constants, vtable slots, destructor vptr restores, thunk island.
   - Result: vtable slices are strongly IDocHostUIHandler/IDocHostShowUI shaped, but the checked Browser QI body does not return those IIDs.
   - Recommendation: declare the interfaces to match vtables, but document QI exposure as not observed. This is not a passive blocker for class declaration.

2. Exact custom string type at `+0x230`:
   - Checked: destructor string-object cleanup, resource URL storage, BrowserNavigate notes, BrowserInitFlags.
   - Result: project wide-string object is clear, final type name is not.
   - Recommendation: use `m_currentUrl` in docs and `WideString` as a first-draft placeholder unless a support pass standardizes the exact type.

3. Exact `m_allowedUrlPrefix` start and array size:
   - Checked: Invoke adjusted-pointer math and old control pane initialization summary.
   - Result: role is clear; exact start/extent needs constructor/setup write recheck.
   - Recommendation: document as a wide prefix buffer/range and use `m_allowedUrlPrefix` as source-facing field name. Do not leave it raw.

4. `m_webBrowser` static type:
   - Checked: destructor connection-point cleanup, Navigate COM call, GUID constants.
   - Result: behavior is WebBrowser automation/control pointer. Static type could be `IWebBrowser2 *`, an `IUnknown *` queried to WebBrowser interfaces, or a compatible dispatch/control pointer.
   - Recommendation: use field name `m_webBrowser` with static-type caveat. Prefer `IWebBrowser2 *` in the first-draft class declaration.

5. Old vs modern source file split:
   - Checked: by-file Browser route, auto-generated Browser.cpp, BrowserWindow/ControlPane/Old/Thread docs, prior split reports.
   - Result: broad Browser module is proven; finer file split is not.
   - Recommendation: keep [UID:000013] under [UID:0000HV] and note `BrowserLegacy.cpp` only as a future source-tree possibility.

## IDA rename/type/comment recommendations

Function renames:

- `sub_46F480` -> `Browser::~Browser` (`High`)
- `sub_46F540` -> `Browser::QueryInterface` (`High`)
- `sub_46F670` -> `Browser::AddRef` (`High`)
- `sub_46F680` -> `Browser::Release` (`High`)
- `sub_46F6F0` -> `Browser::GetWindow` (`High`)
- `sub_46F750` -> `Browser::GetWindowContext` (`Medium-high`)
- `sub_46F7E0` -> `Browser::GetIDsOfNames` or IDispatch metadata stub matching exact slot (`Medium`)
- `sub_46F7F0` -> `Browser::GetTypeInfo` or IDispatch metadata stub matching exact slot (`Medium`)
- `sub_46F800` -> `Browser::GetTypeInfoCount` or IDispatch metadata stub matching exact slot (`Medium`)
- `sub_46F810` -> `Browser::Invoke` (`High`)
- `sub_46FBD0` -> `Browser::GetHostInfo` (`Medium-high`)
- `sub_46FC90` -> `Browser::ShowHelp` (`Medium-high`)
- `sub_46FCA0` -> `Browser::ShowMessage` (`Medium-high`)
- `sub_470330` -> `Browser::scalar deleting destructor` or tool-local compiler wrapper name (`High`; no source method)
- `sub_470DD0` -> `Browser::Navigate` (`High`)
- `sub_470FDC`, `sub_470FE6`, `sub_470FF0`, `sub_470FFA`, `sub_471054`, `sub_47105E`, `sub_471068`, `sub_471072` -> Browser COM adjustor/delegation thunk names (`High`; no source methods)

Vtable/type names:

- `0x00613830` -> `Browser::IOleClientSite_vftable` (`High`)
- `0x0061385c` -> `Browser::IOleInPlaceSite_vftable` (`High`)
- `0x0061389c` -> `Browser::IDispatch_vftable` (`High`)
- `0x006138bc` -> `Browser::IDocHostUIHandler_vftable` (`Medium-high`)
- `0x00613908` -> `Browser::IDocHostShowUI_vftable` (`Medium-high`)

Field names:

- `+0x14` -> `m_hWnd` (`High`)
- `+0x18` -> `m_webBrowser` (`Medium-high`)
- `+0x1c` -> `m_adviseCookie` (`High`)
- prefix buffer range near `+0x20` -> `m_allowedUrlPrefix` (`Medium`)
- `+0x222` -> `m_showBrowserAfterLoad` (`Medium-high`)
- `+0x224` -> `m_pendingDownloadCount` (`High`)
- `+0x228` -> `m_navigationBuffer` (`Medium`)
- `+0x22c` -> `m_stateFlags` (`Medium-high`)
- `+0x230` -> `m_currentUrl` (`Medium-high`)

Suggested IDA comments:

- On `Browser::Invoke`: "this is the IDispatch adjusted view (`Browser * + 8`); convert raw decompiler offsets back to Browser base offsets before naming fields."
- On `Browser::QueryInterface`: "Known returns: IOleClientSite/IUnknown base, IOleInPlaceSite/IOleWindow +4, IDispatch/DIID_DWebBrowserEvents2 +8; IDocHost UI/ShowUI vtables exist but direct QI returns not observed in this export."
- On scalar destructor: "MSVC scalar deleting destructor; source behavior is Browser::~Browser()."
- On adjustor thunks: "Multiple-inheritance COM adjustor thunk; no handwritten source."

## Validation commands expected after implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Target and coverage:

> Executable block R001 was removed from this report and preserved verbatim in [000013-Browser-class-source-quality-removed.md](000013-Browser-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Core support docs if edited:

> Executable block R002 was removed from this report and preserved verbatim in [000013-Browser-class-source-quality-removed.md](000013-Browser-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

- Each scoped validator command exits `0` and reports `ok: 1`.
- `by-class/Browser.md` reports `COMPLETION:88`, `CONFIDENCE:90`.
- `auto-generated/NexusTK/browser/Browser.cpp` contains only the class declaration for [UID:000013] unless method child pages separately receive formal C++.
- [UID:000013] no longer has unresolved Browser-vs-BrowserWindow ownership language.
- No `by-memory/-coverage-report.md` validation is needed unless the supervisor separately edits memory coverage rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000013-Browser-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"000013"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000013-Browser-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/000013-Browser-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000013"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
