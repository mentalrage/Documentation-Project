** TARGET-REPORT-UID:000332 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000332] BrowserDocHostShowUiStubs Source-Quality Research

Report status: FINISHED  
Agent: B006  
Assignment: `B006-goal2-browser-doc-host-show-ui-stubs-source-quality-000332-20260619`  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`  
Report-only pass: no `by-*` documentation was edited, and `by-memory/-coverage-report.md` was not edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000332] as a single exact, source-bearing `Browser` COM callback cluster for `IDocHostUIHandler` and `IDocHostShowUI` stubs.
- Final disposition: no split, no merge, no rename required. The range is already a precise half-open child inside [UID:0000ZF], owned by [UID:000013] `Browser` and routed through [UID:000013] to `auto-generated/NexusTK/browser/Browser.cpp`.
- Required action: update the target page with exact method names, vtable slots, return behavior, local IDA export evidence, SDK method-order evidence, the `GetHostInfo` flag interpretation, a first-draft C++ block, and support-doc synchronization. Raise target score from `85/87` to `88/91` after implementation.
- Confidence: high for boundaries, method names, owner, emitter, and first-draft C++ readiness. Remaining uncertainty is limited to broader class-level COM declaration policy, especially the fact that the checked `Browser::QueryInterface` body does not expose `IID_IDocHostUIHandler` or `IID_IDocHostShowUI` even though the vtable slices exist.

## Target

- Target UID: `000332`
- Target path: `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`
- Current score: `COMPLETION:85`, `CONFIDENCE:87`
- Current metadata: `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`, blank formal C++.
- Current direct owner: [UID:000013] `Browser`, currently `85/86`.
- Current source root: [UID:0000HV] `Browser`, currently `86/88`, projected to `NexusTK/browser/`.
- Current generated output state: `project-documentation/auto-generated/NexusTK/browser/Browser.cpp` contains only an empty emitter marker for [UID:000332], so this target has no formal emitted code yet.

## Supervisor Active Recheck

- The user explicitly assigned [UID:000332] as a report-only B-agent source-quality target. That overrides the older B006 `notes.md` ThreadMan assignment.
- The supervisor-owned `by-memory/-coverage-report.md` edit ban remains active. This report includes exact replacement row text for the supervisor instead of modifying that file.
- The target did not require split repair before reporting. The existing range is precise: it starts at `0x0046fb80` after `Browser::Invoke` and its local switch/table child [UID:000331], ends at `0x0046fca5`, and the next function [UID:000333] begins at `0x0046fcb0` after alignment padding.

## Evidence Inputs And Limits

- IDA MCP was checked at `http://127.0.0.1:13337/mcp` during this pass and was unavailable: `Unable to connect to the remote server`.
- Local IDA export evidence was available and used instead:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.c`
- Existing by-* docs were treated as leads and rechecked against local IDA exports where possible.
- Local SDK evidence was checked in `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\MsHtmHst.h` for `IDocHostUIHandler`, `IDocHostShowUI`, and `DOCHOSTUIFLAG_*` method/flag order.
- Numeric conversions checked with `tools/int_convert.py`:
  - `0x14` -> decimal `20` (Verified with int_convert.py)
  - `0x20` -> decimal `32` (Verified with int_convert.py)
  - `0x10097` -> decimal `65687` (Verified with int_convert.py)
  - `0x80004001` -> decimal `2147500033` unsigned representation (Verified with int_convert.py); source-facing name should remain `E_NOTIMPL`.

## Heuristic / Inference Reanalysis And Validation

### Generated function names

The current target still exposes compiler/generated names such as `sub_46FB80`, `sub_46FBD0`, and `sub_46FC90`. The local IDA listing plus Browser vtable order resolve all source-facing names:

| Address | Current name | Best source-facing name | Confidence | Evidence |
| --- | --- | --- | --- | --- |
| `0x0046fc40` | `sub_46FC40` | `Browser::ShowContextMenu` | high | Vtable slot `0x006138c8`, first `IDocHostUIHandler` method after adjusted IUnknown slots, `S_OK`, `retn 0x14`. |
| `0x0046fbd0` | `sub_46FBD0` | `Browser::GetHostInfo` | high | Vtable slot `0x006138cc`, writes `cbSize=0x14` and `dwFlags=0x10097`, returns `S_OK`. |
| `0x0046fc50` | `sub_46FC50` | `Browser::ShowUI` | high | Vtable slot `0x006138d0`, third `IDocHostUIHandler` method, `E_NOTIMPL`, `retn 0x18`. |
| `0x0046fc00` | `sub_46FC00` | `Browser::HideUI` | high | Vtable slot `0x006138d4`, `E_NOTIMPL`, `retn 4`. |
| `0x0046fc80` | `sub_46FC80` | `Browser::UpdateUI` | high | Vtable slot `0x006138d8`, `E_NOTIMPL`, `retn 4`. |
| `0x0046fb80` | `sub_46FB80` | `Browser::EnableModeless` | high | Vtable slot `0x006138dc`, `E_NOTIMPL`, `retn 8`. |
| `0x0046fc10` | `sub_46FC10` | `Browser::OnDocWindowActivate` | high | Vtable slot `0x006138e0`, `E_NOTIMPL`, `retn 8`. |
| `0x0046fc20` | `sub_46FC20` | `Browser::OnFrameWindowActivate` | high | Vtable slot `0x006138e4`, `E_NOTIMPL`, `retn 8`. |
| `0x0046fc30` | `sub_46FC30` | `Browser::ResizeBorder` | high | Vtable slot `0x006138e8`, `E_NOTIMPL`, `retn 0x10`. |
| `0x0046fc60` | `sub_46FC60` | `Browser::TranslateAccelerator` | high | Vtable slot `0x006138ec`, `E_NOTIMPL`, `retn 0x10`. |
| `0x0046fbf0` | `sub_46FBF0` | `Browser::GetOptionKeyPath` | high | Vtable slot `0x006138f0`, `E_NOTIMPL`, `retn 0x0c`. |
| `0x0046fba0` | `sub_46FBA0` | `Browser::GetDropTarget` | high | Vtable slot `0x006138f4`, `E_NOTIMPL`, `retn 0x0c`. |
| `0x0046fbb0` | `sub_46FBB0` | `Browser::GetExternal` | high | Vtable slot `0x006138f8`, writes `*ppDispatch = 0`, returns `E_NOTIMPL`, `retn 8`. |
| `0x0046fc70` | `sub_46FC70` | `Browser::TranslateUrl` | high | Vtable slot `0x006138fc`, `E_NOTIMPL`, `retn 0x10`. |
| `0x0046fb90` | `sub_46FB90` | `Browser::FilterDataObject` | high | Vtable slot `0x00613900`, final `IDocHostUIHandler` method, `E_NOTIMPL`, `retn 0x0c`. |
| `0x0046fca0` | `sub_46FCA0` | `Browser::ShowMessage` | high | Vtable slot `0x00613914`, first `IDocHostShowUI` method after adjusted IUnknown slots, `S_OK`, `retn 0x20`. |
| `0x0046fc90` | `sub_46FC90` | `Browser::ShowHelp` | high | Vtable slot `0x00613918`, second `IDocHostShowUI` method, `S_OK`, `retn 0x20`. |

Rejected alternative: leaving these as raw `sub_*` names is no longer justified. The vtable slot order, stack cleanup sizes, local SDK method order, and simple behaviors independently converge.

### Browser interface meanings

Best inference: this range covers Browser's `IDocHostUIHandler` and `IDocHostShowUI` callback methods.

- `0x006138bc` is the Browser vtable slice for the `IDocHostUIHandler`-style view. Its first three entries are adjusted `QueryInterface`, `AddRef`, and `Release` glue; entries `0x006138c8-0x00613900` are the 15 SDK `IDocHostUIHandler` methods in order.
- `0x00613908` is the Browser vtable slice for the `IDocHostShowUI`-style view. Its first three entries are adjusted IUnknown glue; entries `0x00613914` and `0x00613918` are `ShowMessage` and `ShowHelp`.
- Local SDK `MsHtmHst.h` confirms the method order and signatures for both interfaces, and the local listing confirms matching stack cleanup sizes.

Rejected alternatives:

- `IDocHostUIHandler2` is rejected for this target because the vtable has only the base 15 `IDocHostUIHandler` callbacks before the `IDocHostShowUI` slice; there is no extra `GetOverrideKeyPath`/`GetDropTarget` extension pattern here.
- Treating the range as compiler-generated thunks is rejected. These are fixed-return source-level COM callbacks reached from vtable slots; the compiler-generated adjustor/delegation thunks live in separate pages such as [UID:00033M].
- BrowserWindow ownership is rejected. BrowserWindow has an analogous DocHost island [UID:00020T] at `0x0046a3d0-0x0046a505`, but this target's vtable slots are in the Browser slice `0x006138bc/0x00613908`, not the BrowserWindow slice `0x00613294-0x006132e4`.

### `GetHostInfo` flag interpretation

`0x0046fbd0` writes:

- `pInfo->cbSize = 0x14` (decimal `20`, Verified with int_convert.py), matching 32-bit `DOCHOSTUIINFO`.
- `pInfo->dwFlags = 0x10097` (decimal `65687`, Verified with int_convert.py).

Local SDK `MsHtmHst.h` confirms that `0x10097` decomposes as:

- `DOCHOSTUIFLAG_DIALOG` (`0x1`)
- `DOCHOSTUIFLAG_DISABLE_HELP_MENU` (`0x2`)
- `DOCHOSTUIFLAG_NO3DBORDER` (`0x4`)
- `DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE` (`0x10`)
- `DOCHOSTUIFLAG_FLAT_SCROLLBAR` (`0x80`)
- `DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION` (`0x10000`)

Rejected alternatives:

- Do not keep `0x10097` as an unexplained magic constant after implementation.
- Do not infer `DOCHOSTUIFLAG_SCROLL_NO`; bit `0x8` is not present.
- Do not copy the BrowserWindow `GetHostInfo` conditional flag logic from [UID:00020T]. BrowserWindow checks a flag and can write `0x1009f`; this Browser target always writes `0x10097`.

### QueryInterface exposure caveat

The checked `Browser::QueryInterface` local export at `0x0046f540` returns:

- base pointer for `IID_IOleClientSite` and `IID_IUnknown`,
- `this + 4` for `IID_IOleInPlaceSite` and `IID_IOleWindow`,
- `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`,
- `E_NOINTERFACE` otherwise.

It does not show direct comparisons against `IID_IDocHostUIHandler` or `IID_IDocHostShowUI`. This does not invalidate the target's vtable-method mapping, because the vtable slices and adjustor thunks exist, but it must be preserved as source-quality evidence. Implementation should say "vtable slice is `IDocHostUIHandler`/`IDocHostShowUI` shaped; direct QI exposure is not observed in the checked `Browser::QueryInterface` export."

### Caller/reachability

There are no direct code callers for these tiny functions in normal call-xref form. That is expected for COM callback methods: reachability is through Browser vtable entries in `.rdata`. Existing target docs and local vtable export lines tie each body to `0x006138c8-0x00613918`. This supports source reconstruction through class/interface declarations and method bodies rather than address-level direct-call references.

### Owner/source placement

Best direct owner remains [UID:000013] `Browser`, not [UID:0000HV] directly, because these are class methods on Browser's secondary COM views. Best output route remains [UID:000013] to the Browser source root [UID:0000HV] `NexusTK/browser/Browser.cpp`.

Rejected placements:

- [UID:00001B] `BrowserWindow`: rejected due to distinct vtable island and existing BrowserWindow-specific DocHost page [UID:00020T].
- [UID:000015] `BrowserControlPane`: rejected because it has its own modern browser-control COM path and `QueryInterface`; this target is in the legacy `Browser` class vtable slice.
- [UID:000016] `BrowserControlPaneOld`: rejected because it allocates/holds a `Browser *` but does not own Browser's COM methods.
- [UID:00001A] `BrowserThread`: rejected because the thread initializes/hosts Browser but does not own these callback implementations.
- Broad [UID:0000ZF] aggregate ownership: rejected because that parent is intentionally a non-emitting mixed split inventory.

### Split/range decision

No split is recommended.

- The `IDocHostUIHandler` portion is `0x0046fb80-0x0046fc85` with alignment through `0x0046fc88`.
- The `IDocHostShowUI` portion is `0x0046fc90-0x0046fca2` with alignment through `0x0046fca5`.
- Both portions share the same direct class owner, same Browser source root, same COM-host purpose, and same stub/source-declaration policy. Splitting them would create two tiny sibling pages without improving ownership or C++ readiness.
- The range must not merge forward into [UID:000333] `BrowserLegacyHostWndProc` at `0x0046fcb0`; that is a window procedure/file helper, not a COM callback stub.
- The range must not merge backward into [UID:000331] `BrowserInvokeAndSwitchTable`; `Invoke` and its compiler switch table are a separate `IDispatch` event method.

### Generated-output pollution

Current `project-documentation/auto-generated/NexusTK/browser/Browser.cpp` shows [UID:000332] only as an `Empty Emitter Marker`. That is an implementation gap, not evidence that the target should stay code-blank. The target has valid owner/emitter metadata and `(85+87)/2 > 85`, and this report resolves the method names and C++ source shape.

Generated/simulated source that routes legacy Browser methods through BrowserWindow is stale for this target and should not drive ownership. Current by-* docs already corrected `0x00470dd0` from stale BrowserWindow ownership to Browser; the same caution applies here.

### C++ readiness

The target is ready for first-draft C++ after implementation. The code should be limited to the methods in `0x0046fb80-0x0046fca5`, use ordinary COM method definitions, and not emit vtables, adjustor thunks, padding, raw addresses, or `sub_*` names. The class page may still need a broader declaration pass, but the target method bodies themselves are straightforward and source-quality safe.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046fb80-0x0046fca5` | [UID:000332] `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md` | Browser `IDocHostUIHandler` plus `IDocHostShowUI` method stubs | TRUE | [UID:000013] `Browser` | current `85/87`, recommend `88/91` | Keep single child, populate detailed docs and first-draft C++. |
| `0x0046fb80-0x0046fc88` | nested conceptual region only | `IDocHostUIHandler` callbacks and alignment | TRUE through [UID:000332] | [UID:000013] | no separate page | Do not split unless future tooling requires one function per page. |
| `0x0046fc90-0x0046fca5` | nested conceptual region only | `IDocHostShowUI` callbacks and alignment | TRUE through [UID:000332] | [UID:000013] | no separate page | Keep in [UID:000332]. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006138bc` | Browser `IDocHostUIHandler`-style vtable slice, first adjusted IUnknown slot | Slice starts with adjustor/delegation entries outside the target. |
| `0x006138c8` | `dd offset sub_46FC40` | `ShowContextMenu`. |
| `0x006138cc` | `dd offset sub_46FBD0` | `GetHostInfo`. |
| `0x006138d0` | `dd offset sub_46FC50` | `ShowUI`. |
| `0x006138d4` | `dd offset sub_46FC00` | `HideUI`. |
| `0x006138d8` | `dd offset sub_46FC80` | `UpdateUI`. |
| `0x006138dc` | `dd offset sub_46FB80` | `EnableModeless`. |
| `0x006138e0` | `dd offset sub_46FC10` | `OnDocWindowActivate`. |
| `0x006138e4` | `dd offset sub_46FC20` | `OnFrameWindowActivate`. |
| `0x006138e8` | `dd offset sub_46FC30` | `ResizeBorder`. |
| `0x006138ec` | `dd offset sub_46FC60` | `TranslateAccelerator`. |
| `0x006138f0` | `dd offset sub_46FBF0` | `GetOptionKeyPath`. |
| `0x006138f4` | `dd offset sub_46FBA0` | `GetDropTarget`. |
| `0x006138f8` | `dd offset sub_46FBB0` | `GetExternal`. |
| `0x006138fc` | `dd offset sub_46FC70` | `TranslateUrl`. |
| `0x00613900` | `dd offset sub_46FB90` | `FilterDataObject`. |
| `0x00613908` | Browser `IDocHostShowUI`-style vtable slice | Slice starts with adjusted IUnknown slots. |
| `0x00613914` | `dd offset sub_46FCA0` | `ShowMessage`. |
| `0x00613918` | `dd offset sub_46FC90` | `ShowHelp`. |

## Documentation Evidence And IDA Status

- [UID:000332] already records the exact range, owner, parent inventory, Browser vtable references, fixed return behavior, and score rationale. It leaves final DocHost/ShowUI names provisional and has blank C++.
- [UID:000013] `Browser` records the five Browser vtable views at offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and `+0x10`, and identifies the `+0x0c`/`+0x10` slices as `IDocHostUIHandler` and `IDocHostShowUI` shaped.
- B007's `000013-Browser-class-source-quality.md` resolves `sub_46FBD0` as `Browser::GetHostInfo`, `sub_46FCA0` as `Browser::ShowMessage`, and `sub_46FC90` as `Browser::ShowHelp`, and recommends this target's method role split. This report revalidated that against the local IDA `.lst` and SDK header evidence.
- [UID:0000HV] `Browser` remains the correct source root. The current source-tree hypothesis keeps browser/OLE code under `NexusTK/browser/Browser.cpp` unless a later proof supports a split such as `BrowserLegacy.cpp`.
- [UID:0001OB] `BrowserVtablesAndStrings` records the mixed Browser vtable/string island and places the Browser vtable group at `0x00613830-0x00613908`. It should be updated with the detailed `0x006138bc` and `0x00613908` slice table from this report.
- [UID:0003OH] `BrowserComGuidConstants` identifies `IID_IDocHostUIHandler` at `0x00631630` and `IID_IDocHostShowUI` at `0x00631640`, but those GUID constants are not directly compared by the checked `Browser::QueryInterface`.

## Ranked Ownership Analysis

### 1. [UID:000013] Browser

- Evidence for: vtable slots are in the Browser vtable group, the containing split inventory assigns this child to Browser, B007 maps Browser object offset `+0x0c` to `IDocHostUIHandler` and `+0x10` to `IDocHostShowUI`, and local IDA vtable entries point every target body from Browser slices.
- Evidence against: `Browser::QueryInterface` does not expose the DocHost UI IIDs in the checked local export. This weakens interface-exposure confidence but not vtable ownership.
- Decision: accepted as direct owner and emitter. Preserve the QI caveat in target/support docs.

### 2. [UID:0000HV] Browser source file

- Evidence for: file owns the broader browser/OLE module, projected source path is valid, and [UID:000013] emits through this route.
- Evidence against: too broad for direct semantic ownership because these are class methods.
- Decision: accepted as final source root/emitter ancestor, not direct canonical owner.

### 3. [UID:00001B] BrowserWindow

- Evidence for: BrowserWindow has a highly similar DocHost/ShowUI stub page [UID:00020T], and BrowserWindow `QueryInterface` exposes DocHost UI IIDs in the generated/local evidence.
- Evidence against: different vtable slice addresses (`0x00613294-0x006132e4` for BrowserWindow versus `0x006138c8-0x00613918` for this target), different class, and separate exact page already exists.
- Decision: rejected.

### 4. BrowserControlPane, BrowserControlPaneOld, and BrowserThread

- Evidence for: these classes host, allocate, initialize, or use Browser objects.
- Evidence against: none of their vtable slices point at this target; they are consumers/containers rather than owners of Browser's COM callback methods.
- Decision: rejected.

## Negative Evidence Summary

- No direct code callers were expected or found from the evidence reviewed; vtable-only reachability is normal for COM callbacks.
- `IDocHostUIHandler2` is not supported by the target's slot count.
- `BrowserWindow` owns a separate DocHost range and should not absorb this target.
- The `Browser::QueryInterface` caveat should not be "fixed" by inventing unseen comparisons against `IID_IDocHostUIHandler` or `IID_IDocHostShowUI`.
- Padding/alignment bytes inside the target and after `0x0046fca5` are compiler output and should not be emitted as source.

## First-Draft C++ Recommendation

Populate the target's formal C++ block during implementation unless the supervisor rejects method-body emission pending the class declaration pass. The code below is limited to the target range and avoids vtables, thunks, padding, and raw addresses.

```cpp
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

STDMETHODIMP Browser::ShowUI(DWORD, IOleInPlaceActiveObject *,
                             IOleCommandTarget *, IOleInPlaceFrame *,
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

STDMETHODIMP Browser::ShowMessage(HWND, LPOLESTR, LPOLESTR, DWORD,
                                  LPOLESTR, DWORD, LRESULT *)
{
    return S_OK;
}

STDMETHODIMP Browser::ShowHelp(HWND, LPOLESTR, UINT, DWORD, POINT, IDispatch *)
{
    return S_OK;
}
```

Implementation notes:

- The ORed `DOCHOSTUIFLAG_*` constants equal `0x10097` in the local SDK checked for this report. Keep the named flags for source readability; optionally add a short prose note that the binary writes `0x10097`.
- Do not add null guards to `GetHostInfo` or `GetExternal` if preserving binary behavior; the IDA export writes directly through the out pointer.
- Required headers are ordinary browser/OLE/MSHTML headers, for example `windows.h`, `oleidl.h`, `docobj.h`, and `mshtmhst.h`, but exact include placement belongs to the Browser source/header pass.

## Score Recommendation

Recommended target score after implementation: `COMPLETION:88`, `CONFIDENCE:91`.

Rationale:

- Completion should rise because every generated `sub_*` method in the target has a source-facing method name, vtable slot, interface role, return behavior, stack-cleanup check, and C++ body.
- Confidence should rise because the mapping is independently supported by vtable order, SDK method order, local IDA instruction/decompiler exports, existing Browser class source-quality work, and sibling BrowserWindow DocHost evidence.
- Do not raise to `95+`: the broader Browser class declaration, exact old-vs-new browser source split, and DocHost UI QI exposure caveat are still not final-audit quality.

## Coverage Report Text

Do not edit `by-memory/-coverage-report.md` directly. Supervisor-owned current row text observed in this pass:

```text
      - [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) 0x0046fb80-0x0046fca5 | class COM/UI stubs | BrowserDocHostShowUiStubs : reconstructable : 85% : strong : Browser doc-host/UI stubs assigned to [UID:000013][Browser](by-class/Browser.md); retained as source-bearing Browser stubs distinct from compiler-generated adjustor thunks.
```

Recommended exact replacement row after accepted implementation:

```text
      - [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) 0x0046fb80-0x0046fca5 | class COM/UI stubs | BrowserDocHostShowUiStubs : reconstructable : 88% : very strong : Browser IDocHostUIHandler and IDocHostShowUI callback stubs assigned to [UID:000013][Browser](by-class/Browser.md); B006 source-quality reanalysis maps vtable slice 0x006138bc to the 15 IDocHostUIHandler methods, slice 0x00613908 to ShowMessage/ShowHelp, verifies GetHostInfo writes cbSize 0x14 and flags 0x10097, recommends first-draft stub C++ for the source-bearing methods, and keeps adjustor thunks/padding non-emitting.
```

Current generated `auto-generated/-ag-memory-coverage.md` row, for reference only and not for manual editing:

```text
| [UID:000332][0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs](by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md) | emits | `000013` | `000013` |  | no | `auto-generated/NexusTK/browser/Browser.cpp` | `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md` |  |
```

## Target / Support Implementation Checklist

Target file: `by-memory/0x0046fb80-0x0046fca5.BrowserDocHostShowUiStubs.md`

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:87` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000013`.
- Replace the current compact function inventory with the full method mapping from this report.
- Add evidence from local IDA exports:
  - `NexusTK.exe.lst` lines around `192586-192754` for function bodies and return sizes.
  - `NexusTK.exe.lst` lines around `808508-808533` for vtable entries.
  - `NexusTK.exe.c` lines around `110013-110115` for decompiler return/out-param behavior.
- Add SDK support from `MsHtmHst.h`: `DOCHOSTUIFLAG_*` values around local lines `388-403`, `IDocHostUIHandler` method order around local lines `449-523`, and `IDocHostShowUI` method order around local lines `1094-1106`.
- Add the `Browser::QueryInterface` caveat: direct DocHost UI/ShowUI IID exposure is not observed in the checked `0x0046f540` export even though vtable slices exist.
- Insert the first-draft C++ recommendation above into the formal `RECONSTRUCTION_CPP CODE` block if accepted.
- Add a "Rejected alternatives" or "Negative evidence" paragraph rejecting BrowserWindow ownership, `IDocHostUIHandler2`, compiler-thunk classification, and splitting.

Support docs recommended for the same implementation callback:

- [UID:000013] `by-class/Browser.md`: add or update method inventory and vtable slice table with exact `IDocHostUIHandler` and `IDocHostShowUI` mapping; preserve QI caveat.
- [UID:00032Z] `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`: add exact QI table and negative evidence that DocHost UI IIDs are not returned by this Browser QI export.
- [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: expand Browser vtable entries `0x006138bc-0x00613918` with the method names in this report.
- [UID:0000HV] `by-file/Browser.md`: add a source-quality note that Browser owns these DocHost callbacks while BrowserWindow owns [UID:00020T].
- [UID:0003OH] `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`: cross-link this target as a source-use consumer of DocHost UI interface names, while keeping GUID declarations in the Browser source/root policy.
- [UID:0000ZF] `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`: no structural change required; optionally sync the child row description to say `IDocHostUIHandler/IDocHostShowUI` instead of provisional "doc-host/UI stubs."
- Supervisor-owned `by-memory/-coverage-report.md`: apply the exact replacement row above after the target/support docs are updated and validated.

Validation commands expected after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000332-BrowserDocHostShowUiStubs-source-quality-removed.md](000332-BrowserDocHostShowUiStubs-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation result: each scoped command exits `0` and reports `ok: 1`. The `by-memory/-coverage-report.md` row remains supervisor-owned and should be validated by the supervisor after manual row replacement.

## Open Questions And Closure Status

- Final original source filename: broad `NexusTK/browser/Browser.cpp` is currently best. A narrower `BrowserLegacy.cpp` remains plausible but unproven. This does not block target C++ because the current emitter route is valid.
- Exact Browser class declaration: [UID:000013] still needs a declaration-level implementation pass. This target can still emit method bodies if that class declaration exists or is inserted in the same accepted implementation callback.
- DocHost UI QI exposure: checked Browser QI does not return DocHost UI interfaces. This should remain documented; no high-confidence source repair should invent additional QI branches.
- `DOCHOSTUIINFO` host CSS/namespace fields: binary does not initialize them in this method. Do not add source writes that are not present.

## Validator Results

- No validator command was run because this was a report-only pass and no by-* documentation was edited.
- Report file creation is the only workspace change required by the user assignment.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\000332-BrowserDocHostShowUiStubs-source-quality.md`
- Modified: none outside this research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/000332-BrowserDocHostShowUiStubs-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"000332"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000332-BrowserDocHostShowUiStubs-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/000332-BrowserDocHostShowUiStubs-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000332"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
