*** UID:000015 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPane

## UID00029O Shared Layout-Layer Dependency - 2026-07-21

BrowserControlPane's layout/screen mapping consumes independent `g_pLayoutPaneLayer`, backed at `0x0069b374` and defined solely in MainUiGraph.cpp. The former `g_pBrowserOverlayLayer` name is a superseded consumer alias, not Browser-owned storage. The complete COM/browser host surface, active pane state, fields, layout/window mapping behavior, vtables, methods, scores, and formal declarations remain unchanged.

## Summary

`BrowserControlPane` is the newer embedded browser control pane. It wraps an IE/COM browser window, synchronizes browser window bounds with pane layout, draws browser content/backdrop, handles browser dispatch events, and implements COM interface entry points.

The canonical executable aggregate is [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), with later scalar-delete/adjustor support in [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md). B010's 2026-06-21 source-quality pass resolves the class-level COM interface views, field layout, helper names, dispatch semantics, and registered/raw child-window WndProc split; the aggregate remains no-code only because exact child method pages should carry the first-draft C++.

B009's earlier [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) source-quality report is incorporated as class-boundary evidence: the aggregate is semantically `BrowserControlPane` code, not WebBoardDialog, Application, generic UI, or standalone helper ownership. Its proposed direct owner/emitter change to this class is superseded by the current B010 routing decision, which keeps the by-memory aggregate emitted through [UID:0000HV][Browser](by-file/Browser.md) while this class page remains the semantic owner and future child-split home for method-level source.

B007 Rule 26 reanalysis keeps this newer control path separate from legacy [UID:000013][Browser](by-class/Browser.md). `BrowserControlPane` owns its own constructor, shutdown, QueryInterface, dispatch handler, active-pane globals, and hosted-window synchronization. Do not merge old Browser COM client/event-sink fields or method bodies into this class.

B009's 2026-06-27 accepted implementation resolves this class page's `g_activeBrowserPane` caveat: the constructor publishes a `BrowserPane *` owner/callback pointer, and the lack of a direct clear store is now a documented active-control/object lifetime model rather than a remaining BrowserControlPane type or C++ blocker. Broader aggregate child-split and method-level C++ blockers still remain.

B006's 2026-07-07 accepted implementation resolves the parallel `g_activeBrowserControlPane` declaration caveat at storage-definition level. [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) emits the non-static Browser source definition `BrowserControlPane *g_activeBrowserControlPane;`, while [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) emits a coverage comment to that exact storage page. Direct Application and presentation/screenshot consumers keep the header/private-header/accessor visibility question open, but they do not transfer ownership away from Browser or BrowserControlPane.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserControlPane.cpp`
- Confidence: strong for the browser module and parent source root, medium for exact one-file versus split-file layout.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). The class page now emits the complete declaration through H and `[[CHILDREN]]` through CPP; exact child method/callback pages remain responsible for bodies after the [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) split.

## Methods

- `0x0046b520-0x0046b98e` constructor: pane/base setup, browser child window registration/creation, COM object creation, connection-point advise, active global writes, and initial navigation.
- [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) destructor: source-authored ordinary `BrowserControlPane::~BrowserControlPane()` body that releases `m_webBrowser` at `+0x120`, clears [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) at `0x0046ba13`, and then enters shared base pane teardown.
- `0x0046ba40-0x0046ba89` child-window redraw helper.
- `0x0046ba90-0x0046bb95` shutdown helper: unadvises, releases browser state, hides/destroys the child `HWND`, and restores focus.
- `0x0046bba0-0x0046bc69` `SetBrowserActiveState`.
- `0x0046bc70-0x0046bd30` raw state/property helper island: `SetRefreshStateAndRefresh`, `SetAllowedUrlPrefix`, `SetNavigationTimeoutMillis`, `SetBrowserStateByte0`, and `SetBrowserStateByte1`.
- `0x0046bd30-0x0046be81` `NavigateBrowser` using `BrowserVariantFromString`; internal `0x0046be3d`/`0x0046be61` starts are EH artifacts.
- `0x0046be90-0x0046bfd0` `GetDocumentCookie` / `SetDocumentCookie`.
- `0x0046bfd0-0x0046c247` `BlitBrowserSurfaceToRenderTarget` and `RefreshBrowserSurface`. The first helper composites the visible hosted browser `HWND` into a caller-supplied DirectDraw render target; exact screenshot consumers are JPG at `0x005579b2`, [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) at `0x00557ce8`, and [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) at `0x00558027`.
- `0x0046c250-0x0046c390` `BlitSurfaceRectToBrowser`.
- `0x0046c390-0x0046c549` `DrawBrowserBackdrop` / `PaintBrowserBackdrop` and `SyncBrowserWindowBounds`.
- `0x0046c550-0x0046c65a` `BrowserControlPaneTranslateAcceleratorMessage`, file-static Application message-loop bridge through active browser-control storage.
- `0x0046c65a-0x0046c670` switch metadata for the key bridge.
- `0x0046c670-0x0046c7bc` `QueryInterface`.
- `0x0046c7c0-0x0046c958` compact `IOleClientSite`, `IOleWindow`/`IOleInPlaceSite`, and `IDispatch` stubs.
- `0x0046c960-0x0046caf0` `BrowserControlPane::Invoke` / browser dispatch event handler.
- `0x0046caf0-0x0046cbc0` dispatch switch metadata.
- `0x0046cbc0-0x0046ccf5` compact `IDocHostUIHandler` and `IDocHostShowUI` stubs.
- `0x0046cd00-0x0046ce55` `BrowserControlPaneChildWndProc`, the registered browser child-window callback.
- `0x0046ce55-0x0046ced0` switch metadata for the promoted handler.
- `0x0046ced0-0x0046cfe0` `BrowserControlPaneRawChildWndProcClone`, retained raw no-route clone.
- [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) scalar deleting destructor wrapper: compiler-generated deletion dispatch/ABI coverage for [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md), not a handwritten source destructor body.
- `0x00470fc0-0x004710b7` browser pane/control/window adjustor and delegation thunks, including the `0x00471004-0x00471086` BrowserControlPane-related adjustor group.

## Evidence

- B002 UID000212 current callback evidence proves `m_browserHostHwnd` at `+0x11c` is a direct public consumer contract, not merely an internal host field. Old `WebBoardDialogOld::HandlePointerOrMouseEvent` reads `g_activeBrowserControlPane` and then `[object+0x11c]` at `0x0046e964` for `GetClientRect`; active and old callbacks also read their own `m_browserControlPane->m_browserHostHwnd` for `MoveWindow`. Exhaustive current symbol/declaration/call searches find no `GetBrowserWindow()` API. The declaration therefore exposes the evidenced field directly and does not invent an accessor.
- The accepted H declaration preserves the existing `ControlPane` plus five COM-interface base views, complete method inventory, and every mapped field from `+0x11c` through `+0x334`. It is emitted first in `NexusTK/browser/Browser.h`, before [UID:000019][BrowserPane](by-class/BrowserPane.md), so WebBoardDialog-family headers can include `../../browser/Browser.h` and compile direct pointer/member use without duplicating Browser declarations.
- Wave3 reports 23 methods, 21 active and 2 disabled adjustor thunks.
- IDA MCP confirms constructor at `0x0046b520-0x0046b98e` with callers from `BrowserDialog` and other browser setup paths.
- IDA MCP confirms the constructor calls `AdviseConnectionPoint` and `UnadviseConnectionPoint` helpers.
- IDA MCP confirms `BrowserVariantFromString` is called from the navigation method at `0x0046bdb6`.
- IDA MCP confirms `HandleBrowserDispatchEvent` at `0x0046c960-0x0046caef`; that method owns the strongest evidence for [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), and [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) as a browser consumer.
- IDA MCP confirms the constructor writes [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) at `0x0067ab28` and destructor/unwind paths clear it. Application and surface/presentation code read the same storage to route browser accelerators and synchronize/redraw the hosted browser HWND.
- Screenshot capture consumes, but does not own, BrowserControlPane rendering. JPG/BMP/PNG temporarily select the ScreenPane render surface, refresh GrafPort surface state, test `g_activeBrowserControlPane`, and call `BlitBrowserSurfaceToRenderTarget(m_ddSurface)` before encoding. The helper's `GetDC`/`BitBlt` or `StretchBlt`/`ReleaseDC` behavior makes the browser image part of the captured frame while leaving file paths, image encoding, status messages, and proof packets in ScreenshotCapture.cpp.
- IDA MCP shows `QueryInterface` uses [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md) for 16-byte COM GUID/IID comparisons; B002 source-quality reanalysis classifies that body as Windows SDK/header-inline `InlineIsEqualGUID` source-use evidence, not a BrowserControlPane-authored helper.
- [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) is scored `88/92` and attached to [UID:0000HV][Browser](by-file/Browser.md); it records 54 promoted functions in the core range, the missing promoted bodies at `0x0046ba40`, `0x0046bfd0`, and `0x0046c550`, raw helper islands at `0x0046bc70`, `0x0046be90`, `0x0046c250`, and `0x0046ced0`, and the B009/B010 decision to keep aggregate C++ blank until exact child pages carry method-level source.
- The same core page records COM stub vtable data refs, GUID constants used by `QueryInterface`, the `0x0046c960` dispatch switch over browser DISPIDs, the `0x0046c550` accelerator bridge, and boundary/switch metadata that should not become standalone source bodies.
- 2026-06-16 B001 source-quality recheck confirms the accelerator helper at `0x0046c550` is the active Application message-loop route from `sub_464CD0` and should remain BrowserControlPane-owned/routed. It is related to but distinct from the retained BrowserWindow-specific helper at [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), which reads `g_pActiveBrowserWindow + 0x18` rather than `g_activeBrowserControlPane + 0x120`.
- [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) records the exact source-authored ordinary destructor body: BrowserControlPane vtable restore mechanics, hosted browser release at `+0x120`, active global clear at `0x0046ba13`, and base teardown through `0x00544580`.
- [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) records the exact B001-024/B008 scalar deleting destructor wrapper range, vtable ref `0x0061344c`, adjustor callers at `0x0047027e`/`0x00470289`, duplicate active-global clear at `0x00470493`, base teardown, delete flag behavior, optional delete helper, and formal coverage comment to [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md).
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, assigns the browser subsystem to `NexusTK/browser/`, and lists this class as part of the dense `0x00469290-0x004710b7` browser/OLE cluster.
- [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) and [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) document the active `BrowserControlPane *` slot, constructor writes, destructor/cleanup clears, and application/presentation consumers. The exact storage page emits `BrowserControlPane *g_activeBrowserControlPane;`; the by-global page emits a coverage comment so the definition is not duplicated.
- [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) documents the accepted `BrowserPane *` active owner/callback slot used by the constructor and dispatch-event paths. B009 live MCP shows the constructor callers pass BrowserPane-derived `this` pointers and preserves the no-direct-clear fact as a guard/lifetime model rather than a missing teardown blocker. [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) is explicitly an alias over [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not browser-owned storage.

## Field Layout And COM Views

B010 source-quality reanalysis maps the embedded COM host layout without needing a new BrowserControlPane-only owner file:

| Offset | Field / view | Notes |
| ---: | --- | --- |
| `+0x108` | `IOleClientSiteVtbl *m_clientSiteVtbl` | Primary aggregate IUnknown/IOleClientSite view at vtable `0x006134f0`. |
| `+0x10c` | `IOleInPlaceSiteVtbl *m_inPlaceSiteVtbl` | `IOleWindow` / `IOleInPlaceSite` view at `0x00613518`. |
| `+0x110` | `IDispatchVtbl *m_eventsVtbl` | DWebBrowserEvents2 sink view at `0x00613558`; `Invoke` dispatch is `0x0046c960`. |
| `+0x114` | `IDocHostUIHandlerVtbl *m_docHostUIHandlerVtbl` | DocHost UI handler view at `0x00613578`. |
| `+0x118` | `IDocHostShowUIVtbl *m_docHostShowUIVtbl` | ShowUI view at `0x006135c4`. |
| `+0x11c` | `HWND m_browserHostHwnd` | Child window created with class `"Nexon.Baram.Browser"` and registered WndProc `0x0046cd00`. |
| `+0x120` | `IWebBrowser2 *m_webBrowser` | Created through `CLSID_WebBrowser` / `IID_IOleObject` / `IID_IWebBrowser2`; shutdown stops/quits/releases it. |
| `+0x124` | `DWORD m_webBrowserEventsCookie` | Connection-point cookie for `DIID_DWebBrowserEvents2`. |
| `+0x128` | `uint8_t m_cancelNavigateComplete` / navigation-complete gate | Exact original spelling not proven. |
| `+0x129` | `uint8_t m_refreshStateByte` / refresh-state byte | Raw helper stores it and refreshes when a browser object exists. |
| `+0x12a` | `uint8_t m_browserActiveState` | Restored after document complete. |
| `+0x12c-0x32b` | `wchar_t m_allowedUrlPrefix[256]` | BeforeNavigate2-style URL gate. |
| `+0x32c` | `int m_navigationTimeoutMillis` | Default `30000`; zero path notifies `g_activeBrowserPane` with tag `0x4243746f`. |
| `+0x330/+0x331` | reserved browser state bytes | Setter-only by current evidence; do not over-name them as timers/navigation flags. |
| `+0x332` | `uint8_t m_cursorShownByBrowser` | Balances `ShowCursor` calls. |
| `+0x333` | `uint8_t m_deferShowUntilDocumentComplete` | Cleared before restoring active state. |
| `+0x334` | `IDispatch *m_topLevelNavigationDispatchCookie` | Stored on dispatch case `252`, matched/cleared on `259`. |

`QueryInterface` returns the `+0x108`, `+0x10c`, `+0x110`, `+0x114`, and `+0x118` views for `IID_IUnknown`/`IID_IOleClientSite`, `IID_IOleWindow`/`IID_IOleInPlaceSite`, `DIID_DWebBrowserEvents2`, `IID_IDocHostUIHandler`, and `IID_IDocHostShowUI` respectively, and returns `E_NOINTERFACE` with a nulled output pointer for unmatched GUIDs. The `0x004710xx` / `0x004708xx` vtable entries are shared adjustor/IUnknown thunks in the Browser OLE support range, not BrowserControlPane-authored method bodies.

## Dispatch And WndProc Policy

`BrowserControlPane::Invoke` handles DISPIDs `104`, `250`, `251`, `252`, `259`, `263`, and `270`. Case `250` is the URL/cancel gate for close/resource/disallowed HTTP prefixes; `252` stores the first top-level navigation dispatch cookie; `259` clears the matching cookie, notifies `g_activeBrowserPane` with tag `0x4243746f`, and restores deferred active state; `263` routes new-window behavior through the pane close/callback path; `270` cancels window-closing. The default case uses the canonical `g_pScreenPane` storage at `0x0067a7cc`, so generated `g_browserRuntime` remains an ignored alias rather than a BrowserControlPane global.

`0x0046cd00` is the registered `BrowserControlPaneChildWndProc` because the constructor stores that address into `WNDCLASSA.lpfnWndProc` for `"Nexon.Baram.Browser"` and stores `this` with `SetWindowLongA(hwnd, -21, this)`. `0x0046ced0` mirrors the message body but takes `this` directly and has no caller/pointer evidence, so it remains a retained raw no-route clone with blank formal C++. Both bodies cover `WM_NCPAINT`, `WM_MOVE`, `WM_PAINT`, `WM_SYSCOMMAND`, and timer `1004`/`0x3ec` refresh behavior, then defer other messages to `DefWindowProcA`.

## C++ Emission State

The class page emits no method bodies directly: formal CPP is exactly `[[CHILDREN]]`, while formal H carries the complete class declaration and layout. [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) is source-ready for child splitting, but aggregate-level method C++ would duplicate future exact children and include compiler EH/switch metadata. Eligible child pages after split include the constructor, [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md), shutdown, active-state helper, navigation, document-cookie helpers, blit/refresh/backdrop/bounds helpers, accelerator bridge, `QueryInterface`, compact COM stub clusters, `Invoke`, and `BrowserControlPaneChildWndProc`. [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) is compiler wrapper coverage for the ordinary destructor, not a separate source body. The raw no-route clone should remain no-code until reachability or retained-unused-helper policy is proven.

## Touched State And Dependencies

| State or dependency | Evidence | Reconstruction implication |
| --- | --- | --- |
| `0x0067ab28` / [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) | Constructor writes at `0x0046b58d`/`0x0046b594`; ordinary destructor, clear helper, and scalar-delete paths clear it; Application and presentation/screenshot code directly read it. | Browser-owned active control pointer. Exact storage page [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) emits `BrowserControlPane *g_activeBrowserControlPane;`; by-global emits coverage only. Header/private-header/accessor visibility remains a Browser source split caveat, not an ownership transfer. |
| `0x0067ab84` / [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) | Constructor writes the browser-pane owner/callback target at `0x0046b62d`; B009 caller provenance shows BrowserDialog/WebBoardDialog/WebBoardDialogOld pass BrowserPane-derived `this` pointers, and dispatch cases read it for close/new-window/document-complete callbacks. No direct clear xref exists, but teardown clears `g_activeBrowserControlPane` and guards later reachable consumers. | Browser module `BrowserPane *` active owner pointer; exact storage page emits `BrowserPane *g_activeBrowserPane;`. Type/no-clear is no longer a BrowserControlPane blocker, while header/source split remains Browser-file support work. |
| `0x0067a7cc` / [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) | Dispatch fallback uses the generated `g_browserRuntime` alias. | Do not emit a separate browser-runtime global. |
| Child `HWND` at object offset `+0x11c` | Shutdown, redraw, presentation, and child-window handlers use this hosted-browser window. | Final class layout needs a named child-window field. |
| Browser COM object at object offset `+0x120` | Constructor creates it; shutdown/destructor release it; accelerator bridge queries through it. | Final layout needs an owned browser/COM host pointer. |
| URL/state fields around `+0x12c`, `+0x32c`, `+0x330`, and `+0x331` | Raw helper island records wide URL text plus command/flag fields. | Field names remain provisional until source-level rewrite. |
| Browser dispatch IDs [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) | `HandleBrowserDispatchEvent` handles `104`, `250`, `251`, `252`, `259`, `263`, and `270`. | Constants belong in browser COM/event declarations. |
| Shared helpers `BrowserVariantFromString`, `AdviseConnectionPoint`, and `UnadviseConnectionPoint` | Navigation and constructor/shutdown call the browser-local helper family in [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md). | Keep helper declarations in the browser module, not generic UI controls. |

## Score Rationale

| Field | Rationale |
| --- | --- |
| Completion `90` | The page mirrors the canonical core aggregate's method-family map, records parent source ownership, scalar deleting destructor support, COM interface views, complete declaration/field layout, direct hosted-HWND consumer contract, helper names, active globals, dispatch semantics, and WndProc registered/raw split. Completion remains below final reconstruction because exact child bodies and original source-file split are still pending. |
| Confidence `92` | Browser ownership, COM inheritance, offsets, direct `+0x11c` field use, and header route are supported by the Browser file, core memory aggregate, WebBoardDialog consumers, global-storage pages, COM/event enum pages, vtable/GUID support pages, and scalar deleting destructor evidence. Confidence remains below final because several state-field spellings and the one-file versus split-file source layout are inferred. |

## Open Questions

- Review whether the old and new control panes were separate original files or one browser source module. Current owner/emitter stays [UID:0000HV][Browser](by-file/Browser.md).
- Confirm final source spelling for a few descriptive fields, especially `+0x128`, `+0x129`, `+0x330`, and `+0x331`.
- Split [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) before entering additional first-draft method bodies; the class declaration and child assembly route are complete here.
- Keep the `0x0046ced0` raw WndProc clone no-code unless future reachability or retained-unused-helper policy proves a source route.
- `g_activeBrowserPane` type/no-clear, `g_activeBrowserControlPane` storage definition, direct hosted-HWND API, and class declaration/header route are no longer open class blockers. Remaining work is exact aggregate child splitting, a few descriptive state-field spellings, final one-file versus split-file organization, and the raw WndProc clone route.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000017][BrowserDialog](by-class/BrowserDialog.md), [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- Globals/enums: [UID:0000T2][DIID_DWebBrowserEvents2](by-global/DIID_DWebBrowserEvents2.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md), [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md), [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- Memory: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:000218][0x004710e0-0x0047110e.InlineIsEqualGUID](by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md), [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md), [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md), [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)

## Changes

- 2026-08-03 B002 UID000212 implementation callback:
  - Raised the score from `88/90` to `90/92`, set formal CPP to `[[CHILDREN]]`, and populated formal H with the accepted complete Browser.h declaration, COM bases/methods, and field layout through `+0x334`.
  - Exposed `HWND m_browserHostHwnd` at `+0x11c` as the exact direct active/old WebBoardDialog consumer contract; current searches reject an invented `GetBrowserWindow()` accessor.
  - Preserved child-owned method bodies, aggregate split requirements, raw-clone no-code policy, existing field/COM evidence, and all historical research.

- 2026-07-07 B006 g_activeBrowserControlPane implementation sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: incorporated the accepted [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) source-quality result. The active control global type is now `BrowserControlPane *`, the exact storage page emits `BrowserControlPane *g_activeBrowserControlPane;`, and [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) emits a coverage comment. B006 live MCP session `supervisor-nexustk-20260707` confirms zero-filled `unk_67AB28`/`dword_67AB28` storage, value `0x0`, not-a-function status, exactly 24 xrefs, constructor publish/null fallback, ordinary destructor clear, clear helper, scalar wrapper duplicate clear, Application/browser guard consumers, and presentation/screenshot consumers. Direct non-Browser consumers keep header/private-header/accessor visibility open but do not change Browser ownership.
- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, with the scalar deleting destructor only listed as an unresolved later range.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, and linked exact child [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md).
  - Summary/evidence: live IDA MCP confirms `sub_470410` at `0x00470410-0x004704ec`, vtable ref `0x0061344c`, adjustor callers `0x0047027e`/`0x00470289`, `g_activeBrowserControlPane` clear, base teardown, and delete flag behavior. This clears the strict `85/85` parent gate for assigning the destructor child.
- 2026-06-07 A005 class consolidation:
  - Before: `COMPLETION:76`, `CONFIDENCE:82`, parent blank, method list missing the current core aggregate's promoted/raw helper coverage, and no class-level state/dependency table.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000HV`, expanded method-family ranges, touched-state/dependency table, and explicit score rationale.
  - Summary/evidence: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) already documents the IDA-backed 54-function core, promoted helper additions, raw islands, COM stubs, dispatch switch, key bridge, and source gate; [UID:0000HV][Browser](by-file/Browser.md) is `84/88` and groups this class in `NexusTK/browser/`; active global pages document the `0x0067ab28`/`0x0067ab84` state. A005 live MCP spot-check attempts timed out three times during this pass, so no new live-IDA-only claims were added.
- What existed before: the page documented the newer browser control pane, method list, evidence, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor/destructor, COM QueryInterface, dispatch event handling, browser-window synchronization, and active-global usage are documented; exact COM slot typing and final source-file split remain incomplete.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor/destructor/QueryInterface/dispatch/scalar-deleting starts at `0x0046b520`, `0x0046b990`, `0x0046c670`, `0x0046c960`, and `0x00470410`, and `callers` shows construction from browser dialog/setup paths. At that time `AUTOGEN_PARENT_UID` stayed blank even though [UID:0000HV][Browser](by-file/Browser.md) was the likely owner because the class completion score was still below the 80+ attachment gate.
- 2026-06-16 B001 source-quality sync: documented the distinction between active BrowserControlPane accelerator helper `0x0046c550` and retained BrowserWindow-specific helper [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md).
- 2026-06-20 B007 Browser class boundary sync: recorded that BrowserControlPane is the newer control path and should remain separate from legacy [UID:000013][Browser](by-class/Browser.md)'s COM/event-sink object and first-draft class declaration.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Before: `85/87`, with final COM slots, field names, raw helper names, and the promoted/raw child-window relationship still listed as open.
  - Changed to: `88/90`, retaining [UID:0000HV][Browser](by-file/Browser.md) as owner/emitter and leaving class-page C++ blank.
  - Summary/evidence: incorporated the standard OLE/WebBrowser COM view map, `QueryInterface` GUID mapping, field layout, active-global roles, dispatch event behavior, registered `BrowserControlPaneChildWndProc` versus retained no-route raw clone, helper names, and aggregate child-split/no-code policy from B010's source-quality report.
- 2026-06-21 B009 Rule 26 reconciliation:
  - Reviewed the older B009 [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) report against the newer B010 incorporation.
  - Accepted its semantic class-boundary evidence, COM/GUID/helper/global classifications, alias rejections, and aggregate no-code proof.
  - Marked its direct owner/emitter recommendation to [UID:000015] as historical/superseded by the current Browser source-root routing; do not change the target metadata from [UID:0000HV][Browser](by-file/Browser.md) without a future routing pass.
- 2026-06-27 B009 g_activeBrowserPane implementation sync:
  - Score unchanged at `88/90`.
  - Summary/evidence: incorporated the accepted [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) source-quality result. The active owner/global type is now `BrowserPane *`, constructor publication and dispatch/accelerator consumers remain BrowserControlPane evidence, no-direct-clear is documented as a guarded lifetime model, and this target's type/no-clear issue is removed from the class-level blocker list. Broader aggregate child-split and method C++ gates remain unchanged.
- 2026-07-02 B008 destructor split implementation:
  - Score unchanged at `88/90`.
  - Summary/evidence: linked [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md) as the source-authored ordinary destructor and updated [UID:000339][0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor](by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md) as compiler-generated scalar deleting wrapper coverage. This preserves the accepted no-handwritten-wrapper policy while routing destructor source through the exact child.
