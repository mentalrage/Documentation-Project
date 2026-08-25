** TARGET-REPORT-UID:0000HV **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000HV] Browser.cpp empty-emitter family source-quality report

Agent: Agent-B002  
Mode: report-only research  
Target by-file: `by-file/Browser.md`  
Generated file inspected: `auto-generated/NexusTK/browser/Browser.cpp`  
Report path: `tools/leaser/Agents/Agent-B002/research/0000HV-Browser-empty-emitter-family-source-quality.md`

## Final Recommendation

`Browser.cpp` is not a single missing-code problem. The current generated file has 64 emitted UID rows and 51 `Empty Emitter Marker` rows. The empty rows are a mixed family:

- source-ready helpers and data rows that can receive formal C++ now;
- compiler/generated wrapper rows that should receive formal coverage comments only after the real source destructor or method is emitted;
- by-global support rows whose declarations are already emitted by exact storage pages and should receive source-coverage comments, not duplicate declarations;
- aggregate/class rows that still need split/source-placement work before C++ is safe;
- enum/GUID/header rows that need Browser header/source placement decisions before formal declarations should be added.

The next implementation callback should use a bounded first batch, not attempt all 51 rows. The implementation-ready first batch is:

- `000335` `BrowserVariantFromString`: add formal helper C++.
- `00033H` `AdviseConnectionPoint`: add formal helper C++.
- `00033J` `UnadviseConnectionPoint`: add formal helper C++.
- `000215` `BrowserThreadNonDeletingDestructor`: add formal `BrowserThread::~BrowserThread()` C++.
- `00032V` `BrowserThreadScalarDeletingDestructor`: add formal coverage comment after `000215`.
- `00033C` `BrowserPaneScalarDeletingDestructor`: add formal coverage comment to already-emitted ordinary `BrowserPane` destructor `[UID:000408]`.
- `00024V` `BrowserCloseScriptString`: add formal wide string declaration.
- `0002WI` `g_pBrowserDialog` exact storage: add formal global pointer declaration and correct stale initialization notes with live MCP bytes.
- `0000QE`, `0000QO`, `0000PP`: add formal source-coverage comments to already-emitted exact-storage declarations `[UID:0002AD]` and `[UID:0001P9]`.

After that batch, re-run the validator/autogenerator and then review the remaining empty rows as class/split/header-placement work.

## Current Generated State

Observed from `auto-generated/NexusTK/browser/Browser.cpp`:

- Validator command id: `000000001237`
- Validator refreshed at: `2026-06-29T21:33:24-04:00`
- Source by-file UID: `0000HV`
- Source by-file doc: `by-file/Browser.md`
- Total emitted UID rows: 64
- Empty emitter rows: 51

Already non-empty Browser output includes:

- `[UID:000013]` `class Browser`.
- `[UID:00032Y]` `Browser::~Browser()`.
- `[UID:000338]` scalar deleting destructor coverage comment for `Browser`.
- `[UID:00032Z]` `Browser::QueryInterface`.
- `[UID:000332]` DocHost/ShowUI stubs.
- `[UID:000333]` `BrowserLegacyHostWndProc`.
- `[UID:0001OD]` Browser alert string constants.
- `[UID:0001P9]` `BrowserPane *g_activeBrowserPane;`.
- `[UID:0002AD]` `static BrowserThread *g_pBrowserThread;` and `static Browser *g_pCurrentBrowserHost;`.

`by-file/Browser.md` remains a coherent source root at `NexusTK/browser/`, but it should not be raised above the current `COMPLETION:87` / `CONFIDENCE:89` until the empty-emitter family is reduced and class/header split decisions are documented.

## MCP Evidence

MCP was available and the live session used for this report was `supervisor_resume_20260629`.

Verified facts:

- `idb_list` showed one active worker-backed session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Worker PID observed in supervisor facts: `17592`.
- `server_health(database='supervisor_resume_20260629')` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `get_bytes(database='supervisor_resume_20260629', regions=[{addr:'0x00401000', size:1}])` returned `0x8b`.

Targeted MCP checks:

- `0x00470170` decompiled as a `VARIANTARG *` helper: clears the variant, allocates a `BSTR`, throws on failed `VariantClear` or `SysAllocString` out-of-memory. Code xrefs from `0x469d38` and `0x46bdb6`.
- `0x004708d0` decompiled as COM connection-point advise helper: null source returns `E_INVALIDARG`, queries `IConnectionPointContainer`, finds the connection point, calls `Advise`, releases temporary COM interfaces. Code xrefs from `0x469910`, `0x46b898`, `0x470cc3`.
- `0x00470980` decompiled as COM connection-point unadvise helper: same container/find/release structure, calls `Unadvise`. Code xrefs from `0x46998f`, `0x469b08`, `0x46b91a`, `0x46bb1a`, `0x46f4ef`, `0x47039f`, `0x470d69`.
- `0x0046eff0` decompiled as the non-deleting `BrowserThread` destructor: stores the `BrowserThread` vtable, clears `unk_67AB88`, then tail-calls the base thread destructor.
- `0x004706f0` decompiled as the scalar deleting `BrowserThread` wrapper around the same destructor semantics with optional delete.
- `0x00470690` decompiled as the scalar deleting `BrowserPane` wrapper. The ordinary `BrowserPane` destructor is already emitted by `[UID:000408]`, so this row should be comment coverage.
- `0x006139df` bytes decode to a leading alignment byte followed by UTF-16LE `javascript:window.close();` and terminators. Data xref from `0x0046c9a2`.
- `0x0067ab98` current live bytes are `00 00 00 00`. Existing notes that describe this storage as initialized to `0xffffffff` are stale for the current IDB/session.
- `0x0067ab90..0x0067ab9f` and `0x0067ab28` were also zero-initialized in live bytes; paired global declarations should avoid hard-coded nonzero initializers unless a constructor/store proves one.

Searches performed against current docs and archived/central B-agent reports included: `0000HV`, `Browser.cpp`, `Browser empty`, `BrowserOleLegacyAndHelpers`, `BrowserNavigate`, `00033K`, `00470dd0`, `BrowserVariantFromString`, `000335`, `00470170`, `AdviseConnectionPoint`, `00033H`, `UnadviseConnectionPoint`, `00033J`, `PostBrowserNotification`, `00033L`, `browser::Notification`, `BrowserThreadNonDeletingDestructor`, `000215`, `BrowserPanePlaySound`, `BrowserPane CancelTimer`, `BrowserControlPaneCore`, `BrowserWindowCore`, `BrowserPaneAndDialog`.

Relevant prior reports used only as leads:

- `executed-b-agent-research/B001/0000ZF-BrowserOleLegacyAndHelpers.md`: broad range was a split inventory, not a source file. It identifies many exact children now present in the current empty-marker family.
- `executed-b-agent-research/B007/000013-Browser-class-source-quality.md`: keeps Browser under Browser by-file root, rejects BrowserWindow ownership for `Browser::Navigate`, and lists the helper functions as Browser file-level helpers.
- `executed-b-agent-research/B010/0002AD-BrowserThreadHostGlobals-source-quality.md`: exact storage `[UID:0002AD]` already emits `g_pBrowserThread` and `g_pCurrentBrowserHost`, which makes the by-global rows support/coverage rows.
- `executed-b-agent-research/B012/000019-BrowserPane-class-source-quality.md`: `0x004710d0` is a stale `PlaySound` path name; behavior is a `TimerHandler::CancelTimer` thunk and should stay blank until inherited timer-facet naming is accepted.
- `executed-b-agent-research/B006/00032Y-BrowserNonDeletingDestructor-empty-emitter-source-quality.md`: accepted pattern for emitting an ordinary destructor and using a scalar-wrapper coverage comment.
- `executed-b-agent-research/B010/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md`: accepted pattern for not inventing source for no-route clones.

## Empty Marker Inventory

Every current Browser empty marker observed in `Browser.cpp`:

| UID | Source | Score | Disposition |
| --- | --- | --- | --- |
| `000331` | `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md` | 85/88 | Split/aggregate work. Do not add aggregate C++; method/event children need source placement. |
| `00033K` | `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md` | 86/90 | Source route is `Browser::Navigate(const wchar_t *url)`, but exact WebBrowser member/interface names still need local declaration support before first-draft C++. |
| `000015` | `by-class/BrowserControlPane.md` | 88/90 | Class declaration/source-placement pass needed. Do not use aggregate class page as method-body sink. |
| `000339` | `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md` | 85/88 | Wrapper contains real cleanup not yet covered by an ordinary `BrowserControlPane` destructor. Emit ordinary destructor first, then comment wrapper. |
| `000016` | `by-class/BrowserControlPaneOld.md` | 87/89 | Class/source split work. Child constructor/dispatch/draw rows need source names first. |
| `00032T` | `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md` | 85/88 | Method-level C++ possible later, but drawing helper names and old-pane class fields need support. |
| `0002P3` | `by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md` | 85/89 | Constructor source route likely, but field/base layout not ready for formal C++. |
| `0001CO` | `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md` | 85/89 | Dispatch thunk/function pointer support. No standalone source body yet. |
| `000017` | `by-class/BrowserDialog.md` | 87/89 | Class/source split work. Exact singleton storage is separate. |
| `00020X` | `by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md` | 86/91 | Aggregate virtuals; split before C++. |
| `00033A` | `by-memory/0x00470580-0x004705df.BrowserDialogScalarDeletingDestructor.md` | 85/88 | Wrapper cleanup not covered by an ordinary destructor yet. |
| `000018` | `by-class/BrowserDialogOld.md` | 85/87 | Class/source split work. |
| `0000Z3` | `by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md` | 86/91 | Core aggregate; split exact constructor/destructor/dialog methods first. |
| `00033B` | `by-memory/0x004705e0-0x0047068d.BrowserDialogOldScalarDeletingDestructor.md` | 85/88 | Wrapper cleanup not covered by ordinary destructor yet. |
| `000019` | `by-class/BrowserPane.md` | 88/90 | Class page remains support; ordinary destructor already emitted elsewhere. |
| `00033C` | `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` | 86/89 | Immediate coverage comment to `[UID:000408]`. |
| `000217` | `by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md` | 87/91 | Stale path/title family; behavior is `CancelTimer`. Keep blank until TimerHandler facet naming is accepted. |
| `00001A` | `by-class/BrowserThread.md` | 85/88 | Class page support. Immediate destructor work belongs on `000215`. |
| `00032Q` | `by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md` | 85/89 | Method body still has message-loop/helper naming questions. |
| `00032V` | `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md` | 85/90 | Immediate coverage comment after `[UID:000215]`. |
| `00032W` | `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md` | 85/89 | Large initialization method. Needs helper/member names before C++. |
| `00001B` | `by-class/BrowserWindow.md` | 85/88 | Class/source split work. |
| `00020T` | `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md` | 85/91 | Docs should be reconciled with current blank output; likely method stubs but needs local verification before implementation. |
| `000216` | `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` | 85/90 | Compiler adjustor thunks. Comment coverage is appropriate after BrowserWindow COM base layout/Release route is accepted. |
| `000014` | `by-class/browser__Notification.md` | 85/88 | Notification class declaration/field names needed before helper C++. |
| `00033D` | `by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md` | 85/88 | Wrapper should wait for `browser::Notification` destructor/source declaration. |
| `00033L` | `by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md` | 85/89 | Behavior proven, but dispatcher name and `browser::Notification` field names are not stable enough for formal C++. |
| `0000T2` | `by-global/DIID_DWebBrowserEvents2.md` | 88/92 | Header/source import decision: SDK-provided GUID versus local definition. Do not emit duplicate GUID yet. |
| `0000PO` | `by-global/g_activeBrowserControlPane.md` | 88/90 | Exact storage exists at `0001P3`, but linkage/header decision remains open due external consumers. |
| `0000PP` | `by-global/g_activeBrowserPane.md` | 90/91 | Immediate coverage comment to `[UID:0001P9]`, which already emits the declaration. |
| `0000PV` | `by-global/g_browserWindowClassName.md` | 85/90 | Constant/string source placement not yet verified in this pass. |
| `0000Q6` | `by-global/g_pActiveBrowserWindow.md` | 86/88 | Pair with exact storage `0002T5`; choose declaration linkage before C++. |
| `0002T5` | `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md` | 86/88 | Exact storage proven zero-initialized; near-term declaration after linkage decision. |
| `0000QB` | `by-global/g_pBrowserDialogOld.md` | 86/88 | Pair with exact storage `0002WH`; choose declaration linkage before C++. |
| `0002WH` | `by-memory/0x0067ab90-0x0067ab94.g_pBrowserDialogOld.md` | 86/88 | Exact storage proven zero-initialized; near-term declaration after linkage decision. |
| `0000QE` | `by-global/g_pBrowserThread.md` | 86/88 | Immediate coverage comment to `[UID:0002AD]`. |
| `0000QO` | `by-global/g_pCurrentBrowserHost.md` | 87/90 | Immediate coverage comment to `[UID:0002AD]`. |
| `0000Z4` | `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` | 86/90 | Core aggregate. Split exact methods/constructors before formal C++. |
| `00020U` | `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md` | 85/90 | Retained helper/caller policy and message translation names still open. |
| `0000Z6` | `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | 88/92 | Good evidence but too aggregate for one body; split child methods first. |
| `000215` | `by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md` | 86/92 | Immediate formal ordinary destructor C++. |
| `000335` | `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` | 85/89 | Immediate formal helper C++. |
| `00033H` | `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md` | 85/89 | Immediate formal helper C++. |
| `00033J` | `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md` | 85/89 | Immediate formal helper C++. |
| `00024V` | `by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md` | 89/93 | Immediate formal wide string declaration. |
| `0001P3` | `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md` | 86/89 | Exact storage proven zero-initialized, but external linkage/header decision remains open. |
| `0002WI` | `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md` | 86/88 | Immediate formal global pointer declaration with corrected zero-initialization note. |
| `0001SJ` | `by-type/by-enum/BrowserDispatchEventId.md` | 86/90 | Header enum/constants placement not ready. |
| `0001SK` | `by-type/by-enum/BrowserInitFlags.md` | 86/88 | Provisional state word/bitmask. Do not force enum source yet. |
| `0001SL` | `by-type/by-enum/BrowserMessageId.md` | 85/91 | Header constants placement not ready. |
| `0001SM` | `by-type/by-enum/BrowserOverlayStyle.md` | 86/89 | Provisional pair of constants; enum proof not sufficient. |

## Formal C++ For Immediate Batch

All C++ below is intended as exact `RECONSTRUCTION_CPP CODE` insertion text for the named target pages.

### `000335` BrowserVariantFromString

```cpp
static VARIANTARG *BrowserVariantFromString(VARIANTARG *variant, const OLECHAR *text)
{
    HRESULT hr;

    variant->vt = VT_EMPTY;
    hr = VariantClear(variant);
    if (FAILED(hr))
        AtlThrow(hr);

    variant->vt = VT_BSTR;
    variant->bstrVal = SysAllocString(text);
    if (variant->bstrVal == NULL && text != NULL)
    {
        variant->vt = VT_ERROR;
        variant->scode = E_OUTOFMEMORY;
        AtlThrow(E_OUTOFMEMORY);
    }

    return variant;
}
```

Notes:

- `AtlThrow` is the source-level equivalent for the observed throwing helper at `0x00470960`.
- If the project standardizes on another local throw helper name, update the helper reference in the support docs before applying the code.

### `00033H` AdviseConnectionPoint

```cpp
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
```

### `00033J` UnadviseConnectionPoint

```cpp
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
```

### `000215` BrowserThreadNonDeletingDestructor

```cpp
BrowserThread::~BrowserThread()
{
    g_pBrowserThread = NULL;
}
```

Notes:

- The vtable store and tail call to the base thread destructor are compiler mechanics for the C++ destructor chain.
- This source body is what should cover the ordinary destructor semantics.

### `00032V` BrowserThreadScalarDeletingDestructor

```cpp
// Emitted code for this range is covered by [UID:000215].
```

### `00033C` BrowserPaneScalarDeletingDestructor

```cpp
// Emitted code for this range is covered by [UID:000408].
```

### `00024V` BrowserCloseScriptString

```cpp
static const wchar_t kBrowserWindowCloseScriptUrl[] = L"javascript:window.close();";
```

### `0002WI` g_pBrowserDialog

```cpp
BrowserDialog *g_pBrowserDialog;
```

Notes:

- Current live MCP bytes at `0x0067ab98` are zero, so the declaration should not include a nonzero initializer.
- Existing support notes that mention `0xffffffff` initialization should be corrected or marked stale.
- This declaration intentionally uses external linkage because live xrefs include consumers outside the tight BrowserDialog constructor/destructor range.

### `0000QE` g_pBrowserThread

```cpp
// Source declaration for g_pBrowserThread is emitted by [UID:0002AD].
```

### `0000QO` g_pCurrentBrowserHost

```cpp
// Source declaration for g_pCurrentBrowserHost is emitted by [UID:0002AD].
```

### `0000PP` g_activeBrowserPane

```cpp
// Source declaration for g_activeBrowserPane is emitted by [UID:0001P9].
```

## Source-Quality And Ownership Conclusions

Positive conclusions:

- `Browser.md` is still the correct by-file root for this family. The evidence does not justify moving the current rows into `BrowserLegacy.cpp`, `BrowserOld.cpp`, or a separate OLE helper source file yet.
- The helper rows `000335`, `00033H`, and `00033J` are file-level Browser helpers with stable behavior and enough caller evidence for first-draft C++.
- `000215` is an ordinary source destructor for `BrowserThread`; `00032V` is the compiler scalar wrapper and should not get a fake source method.
- `00033C` is another compiler scalar wrapper and can be covered by the already-emitted ordinary `BrowserPane` destructor.
- Exact-storage globals should avoid duplicate declarations from by-global support pages. Coverage comments are the safest current way to remove empty markers while preserving the semantic by-global documentation pages.

Negative conclusions:

- Do not add aggregate C++ to `0000Z6`, `0000Z4`, `0000Z3`, `000331`, `00020X`, `00032W`, or similar broad ranges. They contain multiple source concepts and helper/compiler artifacts.
- Do not emit `000217` from the current path name. The current docs already identify it as a stale `PlaySound` name; behavior is a timer cancel thunk.
- Do not emit `00033L` until `browser::Notification` member names and the notification-posting API name are decided.
- Do not emit local enum/GUID/header declarations for `0000T2`, `0001SJ`, `0001SK`, `0001SL`, or `0001SM` until Browser header/source placement is set.
- Do not hard-code nonzero initializers for Browser globals from old notes. Current MCP bytes for the checked storage locations are zero.

## Score And Metadata Recommendations

Keep `by-file/Browser.md` at `COMPLETION:87` / `CONFIDENCE:89` for now.

Recommended target adjustments after the immediate batch:

| UID | Recommendation |
| --- | --- |
| `000335` | Raise to about 88/91 after formal helper code and support note. |
| `00033H` | Raise to about 88/91 after formal helper code. |
| `00033J` | Raise to about 88/91 after formal helper code. |
| `000215` | Raise to about 88/92 after destructor code. |
| `00032V` | Raise to about 87/90 after coverage comment. |
| `00033C` | Raise to about 87/90 after coverage comment. |
| `00024V` | Keep or slightly raise from 89/93 after formal string declaration. Do not raise to 95+. |
| `0002WI` | Raise cautiously to about 88/89 after declaration and stale-init correction. |
| `0000QE`, `0000QO`, `0000PP` | Keep current scores or raise by at most one completion point after coverage comments. |

Do not use `95+` scores for this batch. The workflow standard treats those as final-audit rare, and this family still has unresolved class/header/source split work.

## Support Docs To Update During Implementation

Required for the immediate batch:

- `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md`: insert formal C++, document `AtlThrow`/throw-helper equivalence.
- `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md`: insert formal C++, record current MCP call shape.
- `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md`: insert formal C++, record current MCP call shape.
- `by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md`: insert formal destructor C++.
- `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md`: insert coverage comment to `[UID:000215]`.
- `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`: insert coverage comment to `[UID:000408]`.
- `by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md`: insert formal wide string declaration.
- `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`: insert formal pointer declaration and correct stale `0xffffffff` note.
- `by-global/g_pBrowserThread.md`: insert coverage comment to `[UID:0002AD]`.
- `by-global/g_pCurrentBrowserHost.md`: insert coverage comment to `[UID:0002AD]`.
- `by-global/g_activeBrowserPane.md`: insert coverage comment to `[UID:0001P9]`.
- `by-file/Browser.md`: add a short implementation note linking this report and summarizing that the first batch covers helpers, one ordinary destructor, scalar coverage, one string, one dialog global, and by-global coverage comments.

Recommended but not part of the first batch:

- Reconcile `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md` with current blank output.
- Add a targeted follow-up for `00033K` `Browser::Navigate` once WebBrowser member/interface declaration names are accepted.
- Add a targeted follow-up for `00033L` and `000014` together so `browser::Notification` fields and `PostBrowserNotification` source names are settled in one pass.
- Add a class/source split pass for `BrowserControlPane`, `BrowserControlPaneOld`, `BrowserDialog`, `BrowserDialogOld`, `BrowserWindow`, and their scalar wrappers.

## Validator Results

Callback implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` while the B002 by-* edit leases were active. All scoped file validators exited `0` with `ok: 1`.

| File | Command id | Timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/Browser.md` | `000000001267` | `2026-06-29T22:04:18-04:00` | 0 | 1 | `uid_link_insert: 12`, `missing_ref_uid: 15` for pre-existing/missing registry UIDs including `000408`/`00040x`, projected stats update, generated refresh deferred. |
| `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` | `000000001268` | `2026-06-29T22:04:19-04:00` | 0 | 1 | Completion/confidence updated to `88/91`; autogen registry changed blank -> block. |
| `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md` | `000000001269` | `2026-06-29T22:04:21-04:00` | 0 | 1 | Completion/confidence updated to `88/91`; autogen registry changed blank -> block. |
| `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md` | `000000001270` | `2026-06-29T22:04:23-04:00` | 0 | 1 | Completion/confidence updated to `88/91`; autogen registry changed blank -> block. |
| `by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md` | `000000001271` | `2026-06-29T22:04:25-04:00` | 0 | 1 | Completion updated to `88`; autogen registry changed blank -> block. |
| `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md` | `000000001272` | `2026-06-29T22:04:26-04:00` | 0 | 1 | Completion updated to `87`; autogen registry changed blank -> block; validator inserted UID links to `000215`. |
| `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md` | `000000001273` | `2026-06-29T22:04:28-04:00` | 0 | 1 | Completion/confidence updated to `87/90`; autogen registry changed blank -> block; warning `missing_ref_uid 000408` because the validator registry does not currently contain that UID reference. |
| `by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md` | `000000001274` | `2026-06-29T22:04:30-04:00` | 0 | 1 | Autogen registry changed blank -> block; score unchanged `89/93`. |
| `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md` | `000000001275` | `2026-06-29T22:04:32-04:00` | 0 | 1 | Completion/confidence updated to `88/89`; autogen registry changed blank -> block. |
| `by-global/g_pBrowserThread.md` | `000000001276` | `2026-06-29T22:04:34-04:00` | 0 | 1 | Autogen registry changed blank -> block; validator inserted UID links to `0002AD`; stats row update for by-global reconstructable. |
| `by-global/g_pCurrentBrowserHost.md` | `000000001277` | `2026-06-29T22:04:36-04:00` | 0 | 1 | Autogen registry changed blank -> block; validator inserted UID links to `0002AD`; stats row update for by-global reconstructable. |
| `by-global/g_activeBrowserPane.md` | `000000001278` | `2026-06-29T22:04:38-04:00` | 0 | 1 | Autogen registry changed blank -> block; validator inserted UID links to `0001P9`. |
| final `by-file/Browser.md --wait-generated` | `000000001279` | `2026-06-29T22:04:48-04:00` | 0 | 1 | `generated_refresh: completed`, `autogen_cpp_update: 1`, `autogen_report_update: 1`, `autogen_registry_rebuild: 1`, `generated_metadata_refresh: 281`, and validator-owned generated backups were created. Broad generated-output warnings included existing `autogen_emitter_has_no_code` and `autogen_children_marker_missing` rows outside this callback. |

Validator-driven side effects observed in the worktree included `tools/validator.ini`, `auto-generated/NexusTK/browser/Browser.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`. These were tool/autogen outputs from scoped validator commands, not manual edits.

Generated `Browser.cpp` inspection after validation:

- `auto-generated/NexusTK/browser/Browser.cpp` contained all 11 accepted rows with no `Empty Emitter Marker` on those rows: `000335`, `00033H`, `00033J`, `000215`, `00032V`, `00033C`, `00024V`, `0002WI`, `0000QE`, `0000QO`, and `0000PP`.
- The generated file contains one storage declaration each for `BrowserPane *g_activeBrowserPane;`, `static BrowserThread *g_pBrowserThread;`, `static Browser *g_pCurrentBrowserHost;`, and `BrowserDialog *g_pBrowserDialog;`.
- The by-global rows for `0000QE`, `0000QO`, and `0000PP` generated comments only, so they did not duplicate the existing declarations from `[UID:0002AD]` or `[UID:0001P9]`.
- Generated freshness: an immediate post-wait inspection briefly showed an older `Browser.cpp` header while generated-refresh jobs were still draining. After the background refresh completed, the final inspected header was `validator-command-id: 000000001286`, `validator-refreshed-at: 2026-06-29T22:06:24-04:00`, `validator-refresh-source: foreground-generated-refresh`, which is newer than the final scoped wait command `000000001279`. Queue status command `000000001288` at `2026-06-29T22:09:12-04:00` reported queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`.

Lease result:

- B002 acquired leases for the 12 edited by-* docs before patching.
- By cleanup time the leases had already expired; `tools/leaser/Agents/current_leases.md` reported `No active leases`.
- One cleanup command included a mistyped path, but the lease report immediately afterward confirmed there were no active B002 or other leases.

## Claim And Incorporation Ledger

| Claim | Evidence | Incorporation target | State |
| --- | --- | --- | --- |
| Browser by-file root remains correct for this family. | `by-file/Browser.md`, B007, current generated `Browser.cpp`, MCP xrefs across Browser functions. | Applied to `by-file/Browser.md` in `2026-06-29 B002 Empty-Emitter First Batch`; validated by `000000001267` and final wait command `000000001279`. | applied |
| `000335` is source-ready helper C++. | MCP decompile at `0x00470170`, xrefs from BrowserWindow and BrowserControlPane paths. | Applied to `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md`: formal C++ inserted, scores `88/91`, Item Summary/evidence/reconstruction notes updated; validated by `000000001268`. | applied |
| `00033H` is source-ready COM advise helper C++. | MCP decompile at `0x004708d0`, three caller xrefs. | Applied to `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md`: formal C++ inserted, scores `88/91`, Item Summary/evidence/reconstruction notes updated; validated by `000000001269`. | applied |
| `00033J` is source-ready COM unadvise helper C++. | MCP decompile at `0x00470980`, seven caller xrefs. | Applied to `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md`: formal C++ inserted, scores `88/91`, stale COM-name blocker historicalized; validated by `000000001270`. | applied |
| `000215` is ordinary `BrowserThread::~BrowserThread()` source. | MCP decompile at `0x0046eff0`, vtable/global store, B006 destructor precedent. | Applied to `by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md`: formal destructor C++ inserted, completion `88`, old 95-gate blocker historicalized; validated by `000000001271`. | applied |
| `00032V` is a scalar deleting wrapper covered by `000215`. | MCP decompile at `0x004706f0`, scalar-wrapper shape, B006 coverage-comment precedent. | Applied to `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md`: formal coverage comment inserted, completion `87`; validated by `000000001272`. | applied |
| `00033C` is a scalar deleting wrapper covered by existing `BrowserPane` destructor `[UID:000408]`. | MCP decompile at `0x00470690`, current emitted ordinary destructor row. | Applied to `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`: formal coverage comment inserted, scores `87/90`; validated by `000000001273` with known `missing_ref_uid 000408` warning. | applied |
| `00024V` is a source string literal for `javascript:window.close();`. | MCP bytes at `0x006139df`, data xref from `0x0046c9a2`. | Applied to `by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md`: formal wide string declaration inserted, old blank-C++/parent-gate wording historicalized; validated by `000000001274`. | applied |
| `0002WI` storage is zero-initialized `g_pBrowserDialog`, not `0xffffffff` initialized in the current IDB. | MCP bytes at `0x0067ab98`, xrefs to constructor/destructor and consumers. | Applied to `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`: formal `BrowserDialog *g_pBrowserDialog;` inserted, scores `88/89`, stale initializer corrected; validated by `000000001275`. | applied |
| `0000QE` and `0000QO` should not duplicate declarations because exact storage emits them. | Existing generated `[UID:0002AD]`, B010 host-global report. | Applied to `by-global/g_pBrowserThread.md` and `by-global/g_pCurrentBrowserHost.md`: formal coverage comments inserted, scores unchanged; validated by `000000001276` and `000000001277`. | applied |
| `0000PP` should not duplicate `g_activeBrowserPane` because exact storage emits it. | Existing generated `[UID:0001P9]`. | Applied to `by-global/g_activeBrowserPane.md`: formal coverage comment inserted, score unchanged; validated by `000000001278`. | applied |
| `000217` is not source-ready under the current path/name. | B012, MCP decompile at `0x004710d0` showing timer cancel tail call. | Excluded from this implementation callback by updated `goal.md`; no edit was made to `by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md`. It remains follow-up inventory only. | excluded-with-reason |
| Aggregate/core rows should not receive broad C++. | Current docs, B001/B007/B012, mixed-method MCP evidence. | Excluded from this implementation callback by updated `goal.md`; no no-code markers or metadata edits were made for `0000Z6`, `0000Z4`, `0000Z3`, `000331`, `00020X`, `00032W`, or other non-accepted Browser inventory rows. | excluded-with-reason |

## Implementation Tracking Checklist

- [x] Insert formal C++ for `000335`. Applied to `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md`; validated by command `000000001268`, exit `0`, `ok: 1`.
- [x] Insert formal C++ for `00033H`. Applied to `by-memory/0x004708d0-0x00470953.AdviseConnectionPoint.md`; validated by command `000000001269`, exit `0`, `ok: 1`.
- [x] Insert formal C++ for `00033J`. Applied to `by-memory/0x00470980-0x00470a00.UnadviseConnectionPoint.md`; validated by command `000000001270`, exit `0`, `ok: 1`.
- [x] Insert formal C++ for `000215`. Applied to `by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md`; validated by command `000000001271`, exit `0`, `ok: 1`.
- [x] Insert formal coverage comment for `00032V`. Applied to `by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md`; validated by command `000000001272`, exit `0`, `ok: 1`.
- [x] Insert formal coverage comment for `00033C`. Applied to `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`; validated by command `000000001273`, exit `0`, `ok: 1`, with known `missing_ref_uid 000408` warning.
- [x] Insert formal C++ for `00024V`. Applied to `by-memory/0x006139df-0x00613a18.BrowserCloseScriptString.md`; validated by command `000000001274`, exit `0`, `ok: 1`.
- [x] Insert formal C++ for `0002WI`. Applied to `by-memory/0x0067ab98-0x0067ab9c.g_pBrowserDialog.md`; validated by command `000000001275`, exit `0`, `ok: 1`.
- [x] Insert formal coverage comment for `0000QE`. Applied to `by-global/g_pBrowserThread.md`; validated by command `000000001276`, exit `0`, `ok: 1`.
- [x] Insert formal coverage comment for `0000QO`. Applied to `by-global/g_pCurrentBrowserHost.md`; validated by command `000000001277`, exit `0`, `ok: 1`.
- [x] Insert formal coverage comment for `0000PP`. Applied to `by-global/g_activeBrowserPane.md`; validated by command `000000001278`, exit `0`, `ok: 1`.
- [x] Update `by-file/Browser.md` with the implementation note and report link. Applied `2026-06-29 B002 Empty-Emitter First Batch`; validated by commands `000000001267` and `000000001279`, both exit `0`, `ok: 1`.
- [x] Run validator/autogenerator. Ran scoped validators for all changed by-* docs plus final `by-file/Browser.md --wait-generated`; final command `000000001279`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Confirm selected empty markers are removed from regenerated `Browser.cpp`. Confirmed by generated inspection: all 11 accepted UIDs had `empty_marker_rows=0`.
- [x] Confirm no duplicate global declarations were introduced. Confirmed by generated inspection: exact storage rows declare `g_activeBrowserPane`, `g_pBrowserThread`, and `g_pCurrentBrowserHost`; by-global rows emit comments only. `g_pBrowserDialog` is declared once by `[UID:0002WI]`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000HV-Browser-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000HV-Browser-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T22:12:39","uid":"0000HV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
