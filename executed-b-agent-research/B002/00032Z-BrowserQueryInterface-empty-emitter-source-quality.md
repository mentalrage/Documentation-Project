** TARGET-REPORT-UID:00032Z **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00032Z BrowserQueryInterface Empty-Emitter Source-Quality Research

## Finalized Report / Implementation Callback Result

- Implementation result: [UID:00032Z] remains owned by [UID:000013][Browser](../../../by-class/Browser.md), keeps the emitter route through [UID:000013] to [UID:0000HV][Browser](../../../by-file/Browser.md) / `auto-generated/NexusTK/browser/Browser.cpp`, and now populates the formal C++ block for `Browser::QueryInterface(REFIID riid, void **ppvObject)`.
- Final disposition: the former empty-emitter marker was caused by blank `RECONSTRUCTION_CPP CODE`, not by bad ownership, bad range, bad route, or a no-code compiler thunk classification. UID00032Z now satisfies the active code-entry gate with source-ready formal C++: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:000013`, a valid Browser source route, and target score `89/92`.
- Accepted action applied: target page updated with current MCP session `3fa0535f` evidence, target raised to `89/92`, exact formal C++ inserted, and Browser class/source-root support wording synchronized that UID00032Z now emits source-ready QueryInterface C++. The negative evidence that `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` vtable slices exist but are not directly returned by this checked Browser QI body is preserved.
- Confidence: high for range, owner, route, IID table, pointer adjustments, failure behavior, and first-draft C++ readiness; medium-high for exact SDK macro spelling (`IsEqualIID`, `IsEqualGUID`, or `InlineIsEqualGUID`) because the binary proves the GUID-equality behavior but not original source token spelling.

## Target

- Target UID: `00032Z`
- Target path: `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`
- Generated file: `auto-generated/NexusTK/browser/Browser.cpp`
- Current metadata after implementation: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`, formal C++ populated.
- Current generated state after validator `000000001107`: `auto-generated/NexusTK/browser/Browser.cpp` contains UID00032Z `Browser::QueryInterface(REFIID riid, void **ppvObject)` at completion/confidence `89/92`; UID00032Z no longer appears as an `Empty Emitter Marker`.
- MCP session used after supervisor restore: `3fa0535f`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, health `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Current Target State

The target already had the correct exact range, class owner, emitter route, vtable xref, adjustor-thunk callers, GUID data links, and IID-to-pointer table. The implementation callback filled the formal C++ header and multiline block, so generated Browser.cpp now emits the UID00032Z method body instead of an empty marker.

The by-memory title `Browser QueryInterface` already matches the source-facing method. The implemented formalization expresses the exact binary behavior as a plausible COM method without adding a normal COM `AddRef()` call that the binary does not perform, without inventing direct DocHost UI/ShowUI QI branches, and without emitting the SDK/header-inline GUID helper body as Browser-local source.

## Evidence Checked

- Required instructions: updated `goal.md`, `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and relevant `by-structure.md` code-entry/owner/emitter sections.
- Target/support docs: [UID:00032Z], [UID:000013] `Browser`, [UID:0000HV] `Browser`, [UID:000218] `InlineIsEqualGUID`, [UID:000272] `BrowserComGuidReadOnlyData`, [UID:0003OH] `BrowserComGuidConstants`, and [UID:0000T2] `DIID_DWebBrowserEvents2`.
- Generated/tracker docs: `auto-generated/NexusTK/browser/Browser.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-coverage-report-by-memory.md`.
- Existing B reports searched with `rg` terms `00032Z`, `0x0046f540`, `0x0046f66f`, `BrowserQueryInterface`, `Browser QueryInterface`, `QueryInterface`, `Browser`, `InlineIsEqualGUID`, and related owner/source-family terms across `executed-b-agent-research` and active agent folders.
- Relevant old reports opened/used as leads: B007 `000013-Browser-class-source-quality.md`, B002 `000218-InlineIsEqualGUID.md`, B004 `000330-BrowserComStubMethods-source-quality.md`, B006 `000332-BrowserDocHostShowUiStubs-source-quality.md`, and B006 `00032Y-BrowserNonDeletingDestructor-empty-emitter-source-quality.md`.
- IDA MCP calls after restore: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `xrefs_to`, and `get_bytes` against session `3fa0535f`.
- Negative checks: no function at `0x0046f66f`; next function starts at `0x0046f670`; no function at vtable data slot `0x00613830`; no direct Browser QI xrefs to `IID_IDocHostUIHandler` at `0x00631630` or `IID_IDocHostShowUI` at `0x00631640`; no direct code callers other than compiler adjustor thunks.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00032Z is an eligible source-bearing empty emitter because only its formal C++ block is blank. | High | Target metadata, generated Browser.cpp marker, by-structure code-entry gate. | UID00032Z metadata/reconstruction notes | applied | UID00032Z formal C++ is populated; validator `000000001107` refreshed generated output; generated `Browser.cpp` has UID00032Z body and no UID00032Z empty marker. |
| C02 | The source-facing method is `HRESULT Browser::QueryInterface(REFIID riid, void **ppvObject)`. | High | Browser class declaration, vtable slot `0x00613830`, adjustor thunks, MCP decompile prototype/behavior. | UID00032Z first-draft C++; Browser methods/support wording | applied | Exact formal method block inserted in UID00032Z; Browser class/file support docs now identify UID00032Z as source-ready QueryInterface. |
| C03 | Function body is exactly `0x0046f540-0x0046f66f`; `0x0046f66f` is not a function and the next function starts at `0x0046f670`. | High | MCP `lookup_funcs`, `get_bytes`, target doc. | UID00032Z scope/evidence | applied | UID00032Z evidence and summary now record MCP session `3fa0535f` range, successor, and padding facts; validator `000000001107` accepted the target. |
| C04 | IID checks return `this` for `IID_IOleClientSite` and `IID_IUnknown`. | High | MCP decompile compares `0x00631590` then `0x00631580` and writes raw `a1`; Browser class layout primary `IOleClientSite` view. | UID00032Z behavior/C++ | applied | Formal C++ returns `static_cast<IOleClientSite *>(this)` for both IIDs; UID00032Z and Browser support retain the QI table. |
| C05 | IID checks return `this + 4` for `IID_IOleInPlaceSite` and `IID_IOleWindow`. | High | MCP decompile compares `0x006315e0` inline and calls `InlineIsEqualGUID` for `0x006315b0`; adjustor thunk at `0x00470fdc` backs the `+4` view. | UID00032Z behavior/C++; Browser class QI table | applied | Formal C++ returns the `IOleInPlaceSite`/`IOleWindow` view; UID00032Z and Browser class support record the `+4` view. |
| C06 | IID checks return `this + 8` for `IID_IDispatch` and `DIID_DWebBrowserEvents2`. | High | MCP decompile compares `0x006315f0` and `0x00631610`; DIID page records Browser QI use; adjustor thunk at `0x00470fe6` backs the `+8` view. | UID00032Z behavior/C++; DIID support already-present check | applied; UID0000T2 already-present | Formal C++ returns `static_cast<IDispatch *>(this)` for both IIDs; UID0000T2 did not need edits because existing DIID support already covered the symbol/use. |
| C07 | Unknown IIDs set `*ppvObject = 0` and return `E_NOINTERFACE`; the binary does not call `AddRef`. | High | MCP decompile final path returns `-2147467262`; no callee except `sub_4710E0`; fixed AddRef/Release are separate stubs. | UID00032Z behavior/C++ notes | applied | Formal C++ preserves the zero-out failure path and omits `AddRef`; UID00032Z notes document no-AddRef behavior. |
| C08 | `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` are not directly returned by this checked Browser QI body. | High | MCP `xrefs_to` shows `0x00631630` and `0x00631640` refs only from BrowserWindow/BrowserControlPane QI, not from `0x0046f540`; Browser/B006 docs record the caveat. | UID00032Z negative evidence; Browser support | applied | UID00032Z, Browser class, and Browser file support all preserve the DocHost UI/ShowUI negative evidence and caveat. |
| C09 | Adjustor thunks at `0x00470fdc`, `0x00470fe6`, `0x00470ff0`, and `0x00470ffa` are compiler glue delegating to this method from secondary views and should not be emitted as handwritten source here. | High | MCP `lookup_funcs`, `analyze_function`, and `xrefs_to` show `a1 - 4`, `a1 - 8`, `a1 - 16`, and `a1 - 12` delegates plus vtable refs. | UID00032Z evidence; Browser adjustor support | applied | UID00032Z records the adjustor thunk table and leaves the thunks as compiler glue; no separate handwritten thunk source was added. |
| C10 | Scores can move to `89/92` after adding current MCP proof and formal C++; not higher because exact SDK macro spelling and broader Browser source split remain inferred. | Medium-high | Empty-emitter blocker is resolved; remaining source-token/source-file uncertainty is documented and nonblocking. | UID00032Z metadata/score rationale | applied | UID00032Z metadata now reads `COMPLETION:89` and `CONFIDENCE:92`; validator `000000001107` recorded completion/confidence updates. |
| C11 | UID000218 remains the SDK/header-inline GUID helper dependency, not a new handwritten Browser helper to edit. | High | Existing UID000218 support plus MCP callee/xrefs. | UID000218 support | already-present | No edit required; UID00032Z now references the SDK/header-inline helper dependency and rejected standalone helper emission. |
| C12 | UID0003OH Browser COM GUID constants support is already sufficient for this implementation. | High | Existing GUID constants support and accepted report checks. | UID0003OH support | already-present | No implementation contradiction found; no support-doc edit required. |
| C13 | UID0000T2 DIID_DWebBrowserEvents2 support is already sufficient for this implementation. | High | Existing DIID support and UID00032Z QI branch evidence. | UID0000T2 support | already-present | No implementation contradiction found; no support-doc edit required beyond UID00032Z/Browser class/file synchronization. |

## Positive Evidence Summary

- MCP `lookup_funcs` reports `sub_46F540` at `0x0046f540`, size `0x12f`, with no function at `0x0046f66f`; `sub_46F670` starts at `0x0046f670`.
- MCP `analyze_function 0x0046f540` decompiles a six-branch QueryInterface-style method over GUID/IID inputs and a `void **` out parameter.
- The only callee is `sub_4710E0`, already documented as SDK/header-inline `InlineIsEqualGUID` / equivalent GUID equality source use.
- MCP xrefs to `0x0046f540` are four code refs from adjustor thunks plus Browser vtable data ref `0x00613830`.
- MCP xrefs to `0x004710e0` include BrowserWindow QI, BrowserControlPane QI, and this Browser QI body, confirming SDK helper source-use context.
- MCP xrefs to `0x00631580`, `0x00631590`, `0x006315b0`, `0x006315e0`, `0x006315f0`, and `0x00631610` include the expected `0x0046f540` data refs. MCP xrefs to `0x00631630` and `0x00631640` do not include `0x0046f540`.
- `get_bytes` confirms two `0xcc` bytes before the function, target body bytes through the `E_NOINTERFACE` path, and `0xcc` immediately after the target.

## IDA MCP Facts

### Function/range facts

| Item | MCP result | Meaning |
| --- | --- | --- |
| `0x0046f540` | `sub_46F540`, size `0x12f` | Function body `0x0046f540-0x0046f66f`. |
| `0x0046f66f` | not a function | Correct half-open end. |
| `0x0046f670` | `sub_46F670`, size `0x8` | Successor Browser COM stub, outside this target. |
| `0x00613830` | not a function; vtable data xref target | Primary Browser QI vtable slot. |

### QueryInterface table from current MCP

| Comparison address/data | IID/source name | Returned pointer | Source decision |
| --- | --- | ---: | --- |
| `0x0046f548 -> 0x00631590` | `IID_IOleClientSite` | `this + 0` | Primary `IOleClientSite` view. |
| `0x0046f577 -> 0x00631580` | `IID_IUnknown` | `this + 0` | COM identity through primary view. |
| `0x0046f5a4 -> 0x006315e0` | `IID_IOleInPlaceSite` | `this + 4` | Secondary `IOleInPlaceSite` view. |
| `0x0046f5c5 -> 0x006315f0` | `IID_IDispatch` | `this + 8` | `IDispatch` view. |
| `0x0046f5fc -> 0x00631610` | `DIID_DWebBrowserEvents2` | `this + 8` | Event-sink identity through the `IDispatch` view. |
| `0x0046f630` / call `0x0046f636 -> 0x004710e0` | `IID_IOleWindow` at `0x006315b0` | `this + 4` | Inherited `IOleWindow` view through `IOleInPlaceSite`. |
| final path | other IID | `0` and `E_NOINTERFACE` | No extra QI routes. |

### Adjustor thunk facts

| Address | MCP decompile | Vtable ref | Meaning |
| --- | --- | --- | --- |
| `0x00470fdc` | `return sub_46F540(a1 - 4, a2, a3);` | `0x0061385c` | `IOleInPlaceSite` / `IOleWindow` view QI adjustor. |
| `0x00470fe6` | `return sub_46F540(a1 - 8, a2, a3);` | `0x0061389c` | `IDispatch` view QI adjustor. |
| `0x00470ff0` | `return sub_46F540(a1 - 16, a2, a3);` | `0x00613908` | `IDocHostShowUI` view QI adjustor. |
| `0x00470ffa` | `return sub_46F540(a1 - 12, a2, a3);` | `0x006138bc` | `IDocHostUIHandler` view QI adjustor. |

These thunks explain secondary-interface entrypoints and should remain compiler glue, not handwritten QI bodies.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f540-0x0046f66f` | [UID:00032Z](../../../by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md) | Source-authored `Browser::QueryInterface` body | TRUE | [UID:000013] | current `85/88`, recommend `89/92` | formal C++ ready |
| `0x00470fdc-0x00471004` subset | [UID:00033M](../../../by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md) | QI adjustor thunks into UID00032Z | FALSE/compiler glue | Browser support | existing support | no handwritten source |
| `0x004710e0-0x0047110e` | [UID:000218](../../../by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md) | SDK/header-inline GUID equality helper | FALSE | none | `90/94` | source-use dependency only |

## Ranked Ownership Analysis

### 1. Browser [UID:000013]

Evidence for:

- Primary vtable slot `0x00613830` points to `0x0046f540`.
- The function returns Browser object interface views at offsets `+0`, `+4`, and `+8`, matching Browser class layout.
- Four secondary-interface adjustor thunks subtract offsets and delegate back to this body, which is normal MSVC multiple-inheritance COM glue around one class method.
- Browser class docs already model the five interface slices and QI table.

Evidence against:

- The binary decompiler prints a stripped `__stdcall` function shape rather than a typed C++ method because symbols/types are absent.

Decision: accepted direct owner and emitter. The current source-facing method is `Browser::QueryInterface(REFIID, void **)`.

### 2. Browser source file [UID:0000HV]

Evidence for:

- Browser file is the established source root for the legacy Browser COM object and helper/GUID data.
- Generated route reaches `auto-generated/NexusTK/browser/Browser.cpp`.

Evidence against:

- File ownership alone is broader than the semantic direct owner. The method body belongs to the `Browser` class.

Decision: keep as emitter/source route through [UID:000013], not as direct semantic owner.

### 3. SDK/header-inline helper or GUID pages

Evidence for:

- UID00032Z consumes SDK/OLE GUID constants and `InlineIsEqualGUID` source-use behavior.

Evidence against:

- The QI method owns the control flow and pointer returns; GUID pages own declaration/data policy only, and UID000218 is non-emitting SDK/header-inline support.

Decision: support dependencies only.

### 4. BrowserWindow, BrowserControlPane, BrowserControlPaneOld, BrowserThread

Evidence for:

- BrowserWindow and BrowserControlPane have related QueryInterface bodies; BrowserControlPaneOld and BrowserThread allocate/use Browser objects.

Evidence against:

- This method is reached from Browser vtable data and Browser adjustor thunks, uses Browser interface offsets, and is not called by the old pane/thread as their own method.

Decision: rejected as direct owners.

## Source Placement

Recommended placement remains [UID:0000HV][Browser](../../../by-file/Browser.md) / `NexusTK/browser/Browser.cpp`, under the `Browser` class. A later `BrowserLegacy.cpp` / `BrowserOld.cpp` split remains plausible but unproven and is nonblocking for this exact child because the current Browser source root and class emitter route are already valid.

## Range / Split / Padding / Reclassification Analysis

No split is needed. UID00032Z is one source method body.

- Predecessor: `0x0046f53e-0x0046f540` is `0xcc 0xcc` padding after [UID:00032Y] `Browser::~Browser()`.
- Body: `0x0046f540-0x0046f66f`.
- Successor: `0x0046f66f` is `0xcc`, and `0x0046f670` starts [UID:000330] Browser COM stubs.
- Internal helper call: the `0x004710e0` GUID equality body is outside the range and remains [UID:000218] SDK/header-inline evidence.
- Adjustor thunks: `0x00470fdc-0x00471004` are outside this range and remain compiler glue in UID00033M.

## Negative Evidence Summary

- No direct code callers target the method except compiler adjustor thunks; ordinary COM dispatch reaches it through vtables.
- `IID_IDocHostUIHandler` and `IID_IDocHostShowUI` GUID constants have no xrefs from `0x0046f540`; they are used by BrowserWindow and BrowserControlPane QueryInterface bodies. Do not add those branches to Browser::QueryInterface.
- The binary does not call `AddRef()` in this method. Even though normal COM QueryInterface implementations often do, adding it would change behavior.
- Do not emit `InlineIsEqualGUID` as a Browser helper. UID000218 already proves it is SDK/header-inline source-use evidence.
- Do not merge this target with UID000330 COM stubs or UID00033M adjustor thunks; they have separate source/compiler roles and exact ranges.

## Heuristic / Inference Reanalysis And Validation

- Method name: resolved to `QueryInterface` by Browser class declaration, vtable position, GUID comparisons, HRESULT returns, and `void **` out pointer. This is source-facing, not just descriptive.
- Signature: `HRESULT Browser::QueryInterface(REFIID riid, void **ppvObject)` is the best source shape. The IDA prototype is `int __stdcall(int, _DWORD *, _DWORD *)` only because class/interface types are not applied.
- IID comparisons: use SDK names, not raw `unk_631xxx` labels. `IsEqualIID` is the chosen draft spelling; `IsEqualGUID` or `InlineIsEqualGUID` would also explain the emitted helper body, but `IsEqualIID` is the most natural call-site spelling for QueryInterface.
- Pointer casts: use C++ interface casts rather than arithmetic. `static_cast<IOleClientSite *>(this)`, `static_cast<IOleInPlaceSite *>(this)`, `static_cast<IDispatch *>(this)`, and the inherited `IOleWindow` view through `IOleInPlaceSite` reproduce the `+0`, `+4`, and `+8` returned views.
- Lifetime semantics: omit `AddRef()` because the binary has no such call and Browser's AddRef/Release stubs are fixed-return lifetime placeholders.
- DocHost caveat: preserve it. Browser owns DocHost-shaped vtable slices, but this QI method does not expose their IIDs in the checked body.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00032Z]:

```cpp
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
```

Reason it preserves behavior:

- The branch order matches the binary comparison order.
- Returned interface views match the exact binary offsets: `+0`, `+4`, and `+8`.
- The `IID_IOleWindow` branch returns the inherited IOleWindow view through `IOleInPlaceSite`, matching the `+4` result.
- Unknown IIDs clear the out pointer and return `E_NOINTERFACE`.
- No `AddRef()` or output-parameter null guard is added because the binary does neither.

Reason it matches likely source shape:

- It uses normal COM method signature and SDK IID names rather than IDA labels.
- It relies on the Browser class's already documented multiple inheritance declaration.
- It treats `InlineIsEqualGUID` as SDK/header source use, not as a Browser-authored helper.

## Recommended Target Doc Changes

Target path: `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`

- Recommended metadata:
  - `COMPLETION:89`
  - `CONFIDENCE:92`
  - `CANONICAL_OWNER:000013`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000013`
  - blank `EMITTER_POSITION_OPTIONAL`
- Populate formal C++ with the block above.
- Fill the currently blank `Item Summary` with a concise description of the source-ready Browser QueryInterface body, IID table, returned interface views, adjustor thunks, SDK GUID helper dependency, and DocHost QI negative evidence.
- Add current MCP evidence: session `3fa0535f`, health `ok`, body `0x0046f540-0x0046f66f`, next function `0x0046f670`, xref list, adjustor thunk behavior, GUID xrefs, and padding bytes.
- Update score rationale to say the empty-emitter blocker is closed by formal C++; cap below final because exact `IsEqualIID` vs `IsEqualGUID` macro spelling and broader Browser source split remain inferred.
- Preserve rejected alternatives: no BrowserWindow/BrowserControlPane/BrowserControlPaneOld/BrowserThread ownership, no DocHost UI/ShowUI branches, no AddRef, no standalone SDK GUID helper emission.

## Recommended Support Doc Changes

### [UID:000013] `by-class/Browser.md`

- In the methods/source-readiness wording, state that [UID:00032Z] now has first-draft source-ready `Browser::QueryInterface(REFIID, void **)` C++ when implemented.
- Keep the existing five-vtable-slice class declaration and QueryInterface table.
- Preserve the caveat that `IDocHostUIHandler` and `IDocHostShowUI` vtable slices exist but direct QI exposure is not observed in UID00032Z.

### [UID:0000HV] `by-file/Browser.md`

- Add a source-quality sync note that [UID:00032Z] now emits Browser `QueryInterface` under the Browser source root.
- Preserve the broader one-file `Browser.cpp` versus possible `BrowserLegacy.cpp` / `BrowserOld.cpp` split as nonblocking.

### Already-present support docs

- [UID:000218] `InlineIsEqualGUID` already documents the SDK/header-inline helper identity and Browser QI source-use role at same-or-greater detail.
- [UID:0003OH] `BrowserComGuidConstants` already documents all relevant GUID names and the UID00032Z DocHost negative evidence at same-or-greater detail.
- [UID:0000T2] `DIID_DWebBrowserEvents2` already documents Browser QI returning the `IDispatch` view and destructor/unadvise usage at same-or-greater detail.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner [UID:000013], reconstructable true, emitter [UID:000013], formal C++ blank.
- Recommended score/metadata: `89/92`, owner/emitter/reconstructable unchanged, formal C++ populated.
- Reason not higher: exact source token spelling for the SDK equality macro remains inferred; broader Browser file split remains plausible; the unusual no-AddRef QI behavior is binary-proven but should stay documented as source-specific behavior.
- Reason not lower: current MCP proves exact body, range, xrefs, IID table, pointer results, fallback HRESULT, adjustor thunk relationship, and DocHost negative evidence; the only generated-output blocker is blank formal C++.

## Open Questions With Attempted Resolution

- Exact GUID equality spelling:
  - Checked UID000218, local docs, current MCP callee, and old report. Best implementation spelling is `IsEqualIID` in QI source; `InlineIsEqualGUID`/`IsEqualGUID` remain equivalent support spellings. This limits confidence slightly but does not block C++.
- AddRef behavior:
  - Checked MCP callees and Browser COM stub docs. No AddRef call is present; source must omit AddRef to preserve behavior. This is resolved.
- DocHost UI/ShowUI exposure:
  - Checked current MCP xrefs for `0x00631630` and `0x00631640`, Browser class docs, and B006/B007 reports. Direct exposure is not observed in UID00032Z; preserve as caveat. This is resolved for this target.
- Browser source split:
  - Checked Browser file/class docs. Current route through Browser.cpp remains best supported; possible legacy split is nonblocking and does not change owner/emitter for this exact child.

## Validator Results

- Implementation callback validators run from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-class\Browser.md --apply --queue-timeout 240`
    - `command_id: 000000001105`
    - `command_timestamp: 2026-06-29T19:42:43-04:00`
    - Result: `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240`
    - `command_id: 000000001106`
    - `command_timestamp: 2026-06-29T19:42:48-04:00`
    - Result: `ok: 1`, generated refresh deferred; known/pre-existing missing UID-reference warnings for split-child UIDs remained, and validator added UID00032Z to the Browser file reference index.
  - `python .\tools\validator.py --mode file --file by-memory\0x0046f540-0x0046f66f.BrowserQueryInterface.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000001107`
    - `command_timestamp: 2026-06-29T19:42:57-04:00`
    - Result: `ok: 1`, `completion_update 00032Z ... 89`, `confidence_update 00032Z ... 92`, generated refresh completed.
- Generated freshness proof:
  - `auto-generated/NexusTK/browser/Browser.cpp` now contains `// UID:00032Z ... Completion:89 | Confidence:92` followed by `HRESULT Browser::QueryInterface(REFIID riid, void **ppvObject)`.
  - `rg` inspection found UID00032Z body lines and no UID00032Z `Empty Emitter Marker`. Other unrelated Browser-family empty markers remain.
- Lease proof:
  - Short leases were held for `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`, `by-class/Browser.md`, and `by-file/Browser.md` during the edit/validator batch (`time created: 2026-06-29T23:38:02Z`, `expiration: 2026-06-29T23:43:02Z`).
  - Post-validator explicit `unlease` returned `Rejected[No active lease]` for each B002 path because the short leases had expired before the release command completed.
  - `tools/leaser/Agents/current_leases.md` recheck after the release attempt showed no active Agent-B002 leases.

## Changed Files

- Modified by-* docs:
  - `by-memory/0x0046f540-0x0046f66f.BrowserQueryInterface.md`
  - `by-class/Browser.md`
  - `by-file/Browser.md`
- Modified Agent-B002 report:
  - `tools/leaser/Agents/Agent-B002/research/00032Z-BrowserQueryInterface-empty-emitter-source-quality.md`
- Validator-owned/generated refresh observed, not manually edited:
  - `auto-generated/NexusTK/browser/Browser.cpp`
  - validator-owned generated metadata/reports/index state reported by command `000000001107`
- Report execution: not performed; this report was not moved, archived, or executed by Agent-B002.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: supervisor accepted this report and issued the UID00032Z implementation callback.
- [x] Target/support docs to update: UID00032Z target, Browser class [UID:000013], and Browser file [UID:0000HV] updated. UID000218, UID0003OH, and UID0000T2 are already-present with no contradiction found.
- [x] Current target state and actual evidence checked recorded: report includes target metadata, generated marker state, MCP session health, function/range/xref/decompile/byte evidence, support docs, generated docs, and old report searches.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C01-C13 now record applied or already-present proof.
- [x] Metadata/score changes applied: UID00032Z is `89/92`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution: empty C++ blocker resolved; method/signature resolved; IID table resolved; pointer adjustments resolved; no-AddRef behavior resolved; DocHost negative evidence resolved; SDK helper spelling documented as inferred but nonblocking.
- [x] Owner/emitter/reconstructable changes applied or rejected: no route changes; kept `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`.
- [x] Split/rename/new-child changes applied or rejected: none required.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: preserved range `0x0046f540-0x0046f66f`, preserved adjustor thunks outside target, and made no IDA DB edits.
- [x] First-draft C++ applied: exact `HRESULT Browser::QueryInterface(REFIID riid, void **ppvObject)` formal block inserted into UID00032Z.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP session `3fa0535f`, body/range/padding, QI branch table, returned interface views, failure path, absence of AddRef, SDK helper source-use, adjustor thunk callers, vtable refs, and DocHost UI/ShowUI negative evidence.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: rejected DocHost UI/ShowUI QI branch invention, BrowserWindow/BrowserControlPane/BrowserControlPaneOld/BrowserThread ownership, standalone `InlineIsEqualGUID` emission, stale raw `sub_`/`unk_` names, and COM-normal AddRef insertion.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: Browser file still describes old generated container history; implementation relies on current by-* docs and MCP evidence.
- [x] Open questions closed or documented as evidence-backed unresolved: exact `IsEqualIID` vs `IsEqualGUID` source token remains inferred and score-limiting only; Browser.cpp vs legacy split remains nonblocking.
- [x] Validators run: class command `000000001105`, file command `000000001106`, target command `000000001107` with `--wait-generated`.
- [x] Generated report refresh confirmed: Browser.cpp refreshed and UID00032Z no longer appears as an empty emitter; generated reports/tracker are validator-owned and were not manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded with command IDs/timestamps/results.
- [x] Generated Browser.cpp freshness confirmed against validator command metadata and UID00032Z body/no-empty-marker inspection.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00032Z-BrowserQueryInterface-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00032Z-BrowserQueryInterface-empty-emitter-source-quality.md","timestamp":"2026-06-29T19:47:06","uid":"00032Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
