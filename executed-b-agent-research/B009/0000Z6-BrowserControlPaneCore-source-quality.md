** TARGET-REPORT-UID:0000Z6 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000Z6 BrowserControlPaneCore Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000Z6] `BrowserControlPaneCore` reconstructable, tighten direct owner/emitter routing from broad [UID:0000HV] `Browser` to [UID:000015] `BrowserControlPane`, and raise the score from `84/90` to `86/90` if the support text below is applied.
- Final disposition: [UID:0000Z6] is a coherent `BrowserControlPane` class aggregate under the Browser source root, not a mixed Browser/WebBoard/AutoInit container. The broad source root remains `NexusTK/browser/Browser.cpp`, with a plausible future split to `browser/BrowserControlPane.cpp`.
- Required action: apply the support text/metadata and coverage replacement rows below. Do not populate formal `RECONSTRUCTION_CPP` for this aggregate yet; exact no-code proof is included under `First-Draft C++ Recommendation`.
- Confidence: high for class ownership, Browser source root, COM GUID/interface identities, global/alias roles, and no-code aggregate decision; medium-high for exact method names, original one-file versus split-file layout, and the raw child-window clone retention model.

## Supporting Research

## Target

- Target UID: `0000Z6`
- Target path: `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`
- Required report path: `tools/leaser/Agents/Agent-B009/research/0000Z6-BrowserControlPaneCore-source-quality.md`
- Source queue/report row: refreshed `project-level/-auto-completion-stats.md` lists `0000Z6` at `84/90`, average `87.0`.
- Current supervisor classification: B-preferred source-quality and heuristic/inference pass for a low-score Browser by-memory row with unresolved COM/WndProc/raw-helper/source-quality and first-draft C++ questions.
- Current scores and parent state:
  - `COMPLETION:84`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000HV`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000HV`
  - formal C++ blank.

## Executive Recommendation

Change the direct semantic route to:

```text
CANONICAL_OWNER:000015
EMITTER_UIDS:000015
COMPLETION:86
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
```

Reasoning:

- The range is explicitly documented as a `class aggregate` and every source-bearing subrange in `0x0046b520-0x0046cfe0` belongs to the newer `BrowserControlPane` object, its COM interface views, or its child-browser window helpers.
- [UID:000015] `BrowserControlPane` is already scored `85/87`, reconstructable, and routed through [UID:0000HV] `Browser`, so it clears the current direct-parent gate.
- The direct source root still remains Browser. Changing this target to [UID:000015] is not a claim that the final source file is separate; it is the by-structure distinction between the direct semantic owner (`BrowserControlPane`) and the broader source file root (`Browser.cpp`).

Do not populate final C++ for the combined aggregate. It meets the minimum combined-score/emitter gate, but the current target is not one source body. It spans constructor/destructor helpers, raw state helpers, navigation, blit/layout helpers, accelerator bridge, QueryInterface, many COM stubs, dispatch handling, a promoted child WndProc-like handler, internal switch metadata, and a raw WndProc-like clone. A whole-range C++ block would either paste many unsplit method bodies into a class aggregate or invent a container body that does not correspond to emitted source.

## Supervisor Active Recheck

- Supervisor instruction rechecked from `Agent-B009/goal.md`: active assignment is [UID:0000Z6] `BrowserControlPaneCore` source-quality, report-only under B009 research unless split repair is mandatory.
- Temporary coverage ban applies: `by-memory/-coverage-report.md` must not be edited directly by B009. Exact replacement rows are provided below.
- Split repair decision: no direct split was performed in this pass. The range is overlarge for final C++ but not mixed-owner. Current documentation already records exact method-family ranges and raw helper islands from prior live IDA. A 54-promoted-function split without live IDA access would be unsafe. If the supervisor wants formal method bodies later, split exact child pages first, then emit through those children.
- Current-session IDA status: IDA MCP at `http://127.0.0.1:13337/mcp` was unavailable (`Unable to connect to the remote server`). This report uses existing IDA-backed documentation evidence and clearly marks local SDK/header checks as support evidence, not fresh IDA facts.

## Inference Research Guidance Check

- `by-structure.md` supports a source-bearing class aggregate, but the direct canonical owner should be the narrow class when the range is a class method cluster and the class page clears the gate.
- `inference_research.md` cautions against adjacency-only ownership. This recommendation uses constructor/destructor write sites, vtable refs, COM GUID/interface usage, global lifetimes, dispatch/event consumers, and source-tree grouping.
- Existing docs were treated as lead material. Validated claims include Browser source root, active global roles, GUID names, and helper family. Rejected or refined claims include broad direct file ownership for this class aggregate, unresolved GUID names, standalone browser-runtime/overlay globals, and "final C++ blocked only by 95/95" wording.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Direct owner/emitter | [UID:0000Z6] says entity kind is `class aggregate`; [UID:000015] lists this as the canonical executable aggregate; [UID:000339] scalar deleting destructor already owns to [UID:000015]; Browser file is the source root. | Change [UID:0000Z6] direct owner/emitter to [UID:000015] `BrowserControlPane`. The generated output path still resolves through Browser to `auto-generated/NexusTK/browser/Browser.cpp`. | Keep direct [UID:0000HV] only as a source root, not the direct semantic owner. Reject BrowserWindow, BrowserPane, BrowserThread, WebBoardDialog, and generic UI owners. |
| 54 promoted functions | Target docs record 54 promoted functions in `0x0046b520-0x0046cfe0`, including the previously omitted promoted bodies at `0x0046ba40`, `0x0046bfd0`, and `0x0046c550`. | Treat as a class aggregate inventory. The future split should create exact children for source-bearing methods/stubs if final method C++ is desired. | Do not emit one monolithic C++ body. Do not assign raw switch metadata as functions. Do not create children now without live IDA refresh. |
| Raw helper island `0x0046bc70` | Target docs identify byte `+0x129`, wide URL text `+0x12c`, command/tag `+0x32c`, and flag bytes `+0x330/+0x331`. | Class-private property/state helper island. Source-facing names should be descriptive, such as URL text setter, navigation command/tag setter, and flag setters, pending exact source names. | Reject standalone global/helper ownership; reject generic string utility ownership. These are object-field helpers. |
| Raw helper island `0x0046be90` | Target docs and GUID page identify browser object vslot `+0x48`, `IID_IHTMLDocument2` at `0x00631650`, read vslot `+0xb0`, write vslot `+0xac`, and `"%s=%s"` at `0x00613988`. Local Windows SDK `MsHTML.h` confirms `IHTMLDocument2::put_cookie` and `get_cookie`. | High-probability `BrowserControlPane` cookie helper pair: query `IHTMLDocument2`, call `put_cookie(BSTR)` for formatted `name=value`, and `get_cookie(BSTR*)` for reads. | Reject unknown document interface now that GUID is known. Reject generic property names in final docs; preserve "cookie" as inferred/descriptive until exact callsites confirm parameter semantics. |
| Raw helper island `0x0046c250` | Target docs describe destination rect mapping, browser surface/DC through vslot `+0x44`, screen metrics, and `BitBlt`/`StretchBlt` fallback. Presentation consumers call browser blit helpers through `g_activeBrowserControlPane`. | BrowserControlPane browser-surface blit/stretch helper, probably used for active-surface capture/presentation synchronization. | Reject generic Surface/Screen ownership: those modules consume the helper through active browser control storage; they do not own the BrowserControlPane method. |
| Raw helper island `0x0046ced0` | Target docs record WndProc-shaped raw body, `WM_PAINT`/redraw paths, `DefWindowProcA`, focus/browser-callback globals, command `0x3ec`, and `byte_46CFEC`/`jpt_46CFDA` switch metadata. | Retained raw child-window WndProc-like clone/alternate body under BrowserControlPane source context. Keep documented; do not populate source C++ until registration/reachability is proven. | Reject padding classification because body/table shape is source-like. Reject treating it as the proven live WndProc because the promoted `0x0046cd00` body is the modeled handler and current docs do not prove raw-start registration. |
| COM GUID names | [UID:0003OH] identifies `IID_IUnknown`, `IID_IOleClientSite`, `IID_IOleWindow`, `IID_IOleInPlaceActiveObject`, `IID_IOleInPlaceSite`, `IID_IDispatch`, `IID_IWebBrowser2`, `DIID_DWebBrowserEvents2`, `CLSID_WebBrowser`, `IID_IDocHostUIHandler`, `IID_IDocHostShowUI`, and `IID_IHTMLDocument2`. | Use standard COM/OLE/MSHTML interface names in support text. Remaining COM uncertainty is method stub semantics and exact class/interface declaration layout, not GUID identity. | Reject generated names like `unk_631610`, `IID_BrowserEventSink`, or raw GUID-address names as final source-facing names. |
| Accelerator bridge `0x0046c550` | Target docs, B001 `00020U` report, [UID:0000PO], and [UID:0001P3] show active `g_activeBrowserControlPane + 0x120 -> IID_IOleInPlaceActiveObject`, Application message-loop caller at `0x00464d88`, `Ctrl+N`, Escape through `g_activeBrowserPane`, and `TranslateAccelerator`. | Source-facing descriptive name: `BrowserControlPaneTranslateAcceleratorMessage(MSG *message)`. This is the active Application-pump helper for the newer control pane. | Reject merging with [UID:00020U] `BrowserWindowTranslateAcceleratorMessage`; that retained BrowserWindow helper reads `g_pActiveBrowserWindow + 0x18` and has no live pump route. |
| Dispatch event handler `0x0046c960` | [UID:0001SJ] records DISPIDs `104`, `250`, `251`, `252`, `259`, `263`, `270`; [UID:0000PP] records active pane callback usage; [UID:0000PU] alias resolves fallback runtime to `g_pScreenPane`. | Source-facing name remains `BrowserControlPane::HandleBrowserDispatchEvent` or `Invoke` implementation depending final COM class declaration. DISPID values should use WebBrowser event names/constants rather than raw numbers where possible. | Reject treating `g_browserRuntime` as browser-owned. Reject generic UI event enum ownership. |
| Child WndProc promoted/raw relationship | Target docs distinguish promoted `0x0046cd00-0x0046ce55`, metadata `0x0046ce55-0x0046ced0`, and raw `0x0046ced0-0x0046cfe0`. BrowserWindow precedent [UID:00020V]/[UID:00020W] shows first-draft code is safe only for registered callbacks with clone separation. | `0x0046cd00` is the primary modeled BrowserControlPane child-window handler candidate; `0x0046ced0` is a retained/raw clone-like handler. Split exact child pages before emitting C++ for either. | Reject a single "BrowserRawWindowProc" name for both. Reject formal C++ for raw clone absent registration/xref proof. |
| `GWL_USERDATA` / instance storage | Target docs say `0x0046cd00` reads instance data with `GetWindowLongA`; constructor docs say browser child window registration/creation and `SetWindowLongA` occur in setup. | High-probability `BrowserControlPane *self = reinterpret_cast<BrowserControlPane *>(GetWindowLongA(hwnd, GWL_USERDATA))` child-window dispatch model. | Do not emit exact code yet because this report could not refresh the constructor `SetWindowLongA` arguments or prove whether raw handler also expects the same user-data model. |
| `this+0x11c` | Target, [UID:0000PO], [UID:0001P3], BrowserDialog/WebBoard reports all use this offset as hosted browser child `HWND`. | Use `m_browserHwnd` / `m_hBrowserWnd` as descriptive field name. | Reject leaving as unresolved `this+0x11c` in future support text. Reject Surface ownership; presentation paths consume the HWND through active control pointer. |
| `this+0x120` | Constructor creates/release browser COM state; destructor/shutdown release it; accelerator helper queries it for `IID_IOleInPlaceActiveObject`; navigation uses WebBrowser-style calls. | Use `m_webBrowser` or `m_browserObject` as descriptive owned COM/browser pointer. | Reject generic `void *field_120` in future source-quality text. Exact interface type remains provisional because setup likely stores an OLE/WebBrowser host object view. |
| URL/state fields | Raw island documents `+0x12c` wide URL text, `+0x32c` command/tag, `+0x330/+0x331` flags; dispatch token behavior records `+548` decimal in sibling enum page, corresponding to navigation token/cookie storage. | Use descriptive field families: `m_urlText`, `m_navigationToken`, `m_commandTag`, `m_navigationFlags` until final class-layout pass. | Reject final names based solely on generated `field_` names. These are enough to remove "unknown field" as an ownership blocker, not enough for 95+ final source. |
| `g_activeBrowserControlPane` | [UID:0000PO]/[UID:0001P3] document constructor writes at `0x0046b58d/0x0046b594`, destructor/clear paths, 24 xrefs, app/presentation consumers, and type `BrowserControlPane *`. | Browser-owned active control pointer, implemented by `BrowserControlPane`; declaration must be visible to Application/presentation consumers via browser header or accessor. | Reject Application/Surface ownership; those are consumers. Reject file-local `static` unless external direct consumers are rewritten through accessors. |
| `g_activeBrowserPane` | [UID:0000PP]/[UID:0001P9] document constructor write at `0x0046b62d`, dispatch consumers, Escape handling, no direct clear xref, likely `BrowserPane *`. | Browser-owned active owner/callback pointer. Type likely `BrowserPane *` or browser-pane callback target; final declaration remains medium-high. | Reject broad Application singleton ownership. No-clear caveat caps final field/type confidence but does not block BrowserControlPaneCore routing. |
| `g_browserRuntime` | [UID:0000PU] marks it non-reconstructable alias over [UID:0000S7]/[UID:0001OX] `g_pScreenPane`. | Use canonical `g_pScreenPane` in future source/support; browser dispatch is a consumer only. | Reject emitting `g_browserRuntime` as a browser global. |
| `g_pBrowserOverlayLayer` | [UID:0000QD] marks it ignored alias over [UID:0001PG] `g_layoutContext_69B374`, owned by MainUiGraph/MainUiLayerSlots. | BrowserControlPane bounds sync consumes shared layout context storage. | Reject browser-owned overlay global declaration. |
| Source split | [UID:0000HV] proposes `browser/Browser.cpp` with possible small browser folder; [UID:000015] says `Browser.cpp` or `BrowserControlPane.cpp`. | Current emitter route should remain through existing Browser source root. Future split candidate: `browser/BrowserControlPane.cpp` containing this class, active control globals/accessors, child WndProc helpers, navigation/blit/dispatch/control-pane methods. | Reject moving to generic `ui/controls`; the OLE/WebBrowser/COM helper family is Browser-specific. Reject WebBoard ownership; WebBoard constructs/uses this class but does not own it. |
| Formal C++ readiness | Active gate is met, but target is a multi-method class aggregate with raw helper islands and switch metadata. No exact child pages exist for each source-bearing method inside the 54-function inventory. | Do not populate [UID:0000Z6] C++. Recommend future split-first exact children for constructor, destructor, navigation, blit, dispatch, QueryInterface/stubs, accelerator bridge, child WndProc, and raw clones. | Reject monolithic class implementation in this aggregate. Reject placeholder `[[CHILDREN]]` until real child pages exist to include. |

## Evidence Standards Used

- Existing IDA-backed documentation: [UID:0000Z6], [UID:000015], [UID:0000HV], [UID:000339], [UID:0003OH], [UID:0001SJ], active global pages, and related BrowserWindow/B001/B002/B009 executed reports.
- Local SDK/header support: Windows Kits `MsHTML.h` confirms `IHTMLDocument2::put_cookie` and `get_cookie`, supporting the cookie-helper inference for vslots `+0xac/+0xb0`.
- Generated/project reports: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-unresolved.md`.
- Negative evidence: current-session IDA MCP was unavailable, so this report does not claim new 2026-06-19 live xref/function refresh. Existing documented live-IDA evidence remains identified as documentation evidence.

## IDA MCP Facts

Current-session IDA MCP:

- `tools/list` request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
- No new live function inventory, xref, byte, or decompilation facts are claimed from this session.

Existing documentation evidence from prior live IDA:

- Function/range facts:
  - [UID:0000Z6] records 54 promoted functions inside `0x0046b520-0x0046cfe0`.
  - Constructor `0x0046b520-0x0046b98e`; destructor `0x0046b990-0x0046ba32`; promoted helper additions at `0x0046ba40`, `0x0046bfd0`, and `0x0046c550`.
  - Raw helper islands at `0x0046bc70`, `0x0046be90`, `0x0046c250`, and `0x0046ced0`.
  - QueryInterface `0x0046c670-0x0046c7bc`; dispatch handler `0x0046c960-0x0046caf0`; promoted child handler `0x0046cd00-0x0046ce55`.
- Data/table/padding facts:
  - `0x0046c65a-0x0046c670`, `0x0046caf0-0x0046cbc0`, and `0x0046ce55-0x0046ced0` are switch metadata/table regions, not standalone source bodies.
  - `0x0046cfe0-0x0046d050` is already covered by ignored switch/padding after the raw child-window handler.
- Xref facts:
  - Constructor writes `g_activeBrowserControlPane` and `g_activeBrowserPane`.
  - Active accelerator helper `0x0046c550` is the Application message-loop route documented by B001.
  - Presentation consumers use `g_activeBrowserControlPane + 0x11c` and call browser blit/redraw helpers.
- Vtable/global/type facts:
  - BrowserControlPane vtable slices are in [UID:0001OB] around `0x0061344c-0x006135c4`.
  - GUID constants are resolved by [UID:0003OH].
  - `g_browserRuntime` and `g_pBrowserOverlayLayer` are aliases, not BrowserControlPane-owned storage.
- Negative IDA facts:
  - No fresh proof is available for the exact `SetWindowLongA` arguments in the BrowserControlPane constructor or for raw handler `0x0046ced0` reachability/registration.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046b520-0x0046b98e` | inside [UID:0000Z6] | BrowserControlPane constructor | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing; split child recommended before final body C++ |
| `0x0046b990-0x0046ba32` | inside [UID:0000Z6] | ordinary destructor | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing; scalar deleting destructor child exists at [UID:000339] |
| `0x0046ba40-0x0046ba89` | inside [UID:0000Z6] | child HWND redraw helper | TRUE | recommended [UID:000015] | aggregate `86/90` | Promoted helper; source-bearing |
| `0x0046ba90-0x0046bb95` | inside [UID:0000Z6] | shutdown/release helper | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046bba0-0x0046bc69` | inside [UID:0000Z6] | active/cursor/visibility helper | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046bc70-0x0046bd30` | inside [UID:0000Z6] | raw state/property helper island | TRUE as code, unsafe as final C++ without split | recommended [UID:000015] | aggregate `86/90` | Split candidate |
| `0x0046bd30-0x0046be81` | inside [UID:0000Z6] | navigation helper | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing; uses [UID:000335] |
| `0x0046be90-0x0046bfd0` | inside [UID:0000Z6] | raw IHTMLDocument2 cookie/property helpers | TRUE as code, unsafe as final C++ without split | recommended [UID:000015] | aggregate `86/90` | Split candidate |
| `0x0046bfd0-0x0046c247` | inside [UID:0000Z6] | promoted browser blit helpers | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046c250-0x0046c390` | inside [UID:0000Z6] | raw browser blit/stretch helper | TRUE as code, unsafe as final C++ without split | recommended [UID:000015] | aggregate `86/90` | Split candidate |
| `0x0046c390-0x0046c549` | inside [UID:0000Z6] | backdrop/bounds sync | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046c550-0x0046c65a` | inside [UID:0000Z6] | active BrowserControlPane accelerator bridge | TRUE | recommended [UID:000015] | aggregate `86/90` | Active Application-pump route; source-bearing |
| `0x0046c65a-0x0046c670` | inside [UID:0000Z6] | switch metadata for accelerator helper | FALSE standalone | none | n/a | Do not emit source |
| `0x0046c670-0x0046c7bc` | inside [UID:0000Z6] | BrowserControlPane `QueryInterface` | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046c7c0-0x0046c958` | inside [UID:0000Z6] | COM client-site/doc-host stubs | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing stubs; split recommended |
| `0x0046c960-0x0046caf0` | inside [UID:0000Z6] | WebBrowser dispatch event handler | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing |
| `0x0046caf0-0x0046cbc0` | inside [UID:0000Z6] | dispatch switch metadata | FALSE standalone | none | n/a | Do not emit source |
| `0x0046cbc0-0x0046ccf5` | inside [UID:0000Z6] | secondary COM/doc-host stubs | TRUE | recommended [UID:000015] | aggregate `86/90` | Source-bearing stubs; split recommended |
| `0x0046cd00-0x0046ce55` | inside [UID:0000Z6] | promoted child-window WndProc-like handler | TRUE | recommended [UID:000015] | aggregate `86/90` | Split before C++ |
| `0x0046ce55-0x0046ced0` | inside [UID:0000Z6] | switch metadata for promoted child handler | FALSE standalone | none | n/a | Do not emit source |
| `0x0046ced0-0x0046cfe0` | inside [UID:0000Z6] | raw child-window WndProc-like clone/body | TRUE as retained code, unsafe as final C++ without reachability | recommended [UID:000015] | aggregate `86/90` | Keep documented; no formal C++ yet |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046b58d` / `0x0046b594` | writes `0x0067ab28` | Constructor publishes or clears active `BrowserControlPane *`. |
| `0x0046b62d` | writes `0x0067ab84` | Constructor stores active browser-pane owner/callback target. |
| `0x0046b898` / `0x0046bb14` | calls [UID:00033H] and [UID:00033J] | BrowserControlPane setup/shutdown uses shared connection-point advise/unadvise helpers. |
| `0x0046bdb6` | calls [UID:000335] | Navigation helper uses shared `BrowserVariantFromString`. |
| `0x0046beb1` / `0x0046bf4f` | refs `0x00631650` | Raw document helper queries `IID_IHTMLDocument2`. |
| `0x0046c575` | reads `g_activeBrowserControlPane` | Active accelerator helper reads control object and queries `+0x120`. |
| `0x0046c617` | calls through `g_activeBrowserPane` on Escape | BrowserPane close/activation callback route. |
| `0x0046c73a`, `0x0046c760`, `0x0046c777` | QueryInterface GUID comparisons | Uses standard Browser COM GUID constants and `InlineIsEqualGUID` source-use helper. |
| `0x0046c9f4`, `0x0046ca77`, `0x0046cabb` | dispatch uses `g_activeBrowserPane` | Internal close, new-window, document-complete owner/callback behavior. |
| `0x0046cacd` / `0x0046cadb` | dispatch fallback reads `0x0067a7cc` | Alias to canonical `g_pScreenPane`, not browser runtime storage. |
| `0x0046c4b7` / `0x0046c4df` | reads `0x0069b374` | Layout/bounds sync consumes shared main-UI layout context, not browser-owned overlay global. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0000Z6] records the method-family map, 54 promoted functions, raw helper islands, switch metadata, COM stubs, dispatch handler, and child-window handlers.
- [UID:000015] class page names [UID:0000Z6] as the canonical executable aggregate and already clears the direct owner gate.
- [UID:000339] scalar deleting destructor uses [UID:000015] as direct owner and [UID:0000HV] as likely source file.
- [UID:0003OH] resolves the browser COM GUID band and specifically identifies `IID_IOleInPlaceActiveObject` and `IID_IHTMLDocument2`.
- [UID:0000PO]/[UID:0001P3] and [UID:0000PP]/[UID:0001P9] resolve active browser-control and active browser-pane storage.
- [UID:0000PU] and [UID:0000QD] resolve browser-runtime/overlay aliases away from browser-owned storage.
- B001 `00020U` report validates `0x0046c550` as the active BrowserControlPane accelerator helper, distinct from the retained BrowserWindow helper.

Existing docs that are stale, incomplete, or contradicted:

- [UID:0000Z6] direct `CANONICAL_OWNER:0000HV` is too broad for a class aggregate now that [UID:000015] clears the gate.
- [UID:0000Z6] says final C++ is not emitted because exact COM method names, original split, and WndProc relation are below a `95/95` threshold. The active code gate is lower; the better no-code reason is source-shape safety for a multi-method aggregate with unsplit children and raw/table islands.
- `project-level/-unresolved.md` still lists `byte_46CFEC`, `jpt_46CFDA`, `sub_46B520`, and `this+0x11c`. These should be treated as local switch labels, constructor placeholder, and hosted browser HWND field respectively, not unresolved global/source blockers.

Generated/coverage report state:

- `by-memory/-coverage-report.md` current row is `84%` and says live IDA-confirmed aggregate behavior.
- `auto-generated/-ag-memory-coverage.md` routes [UID:0000Z6] directly through owner/emitter `0000HV`.
- `project-level/-auto-completion-stats.md` lists [UID:0000Z6] at `84/90`, average `87.0`.

## Ranked Ownership Analysis

### 1. [UID:000015] BrowserControlPane

- Evidence for: target is a class aggregate; constructor/destructor/property/navigation/blit/dispatch/COM/WndProc helpers all operate on `BrowserControlPane` state; class page names this as canonical executable aggregate; scalar deleting destructor already uses this direct owner; active globals are written by this class.
- Evidence against: exact final source file may be broad `Browser.cpp` rather than `BrowserControlPane.cpp`; shared Browser helpers are file-level rather than class methods.
- Decision: accepted as direct `CANONICAL_OWNER` and `EMITTER_UIDS`. Emission resolves to Browser source through class/file routing.

### 2. [UID:0000HV] Browser

- Evidence for: Browser file page owns the subsystem source root, Browser COM helper family, browser GUIDs, strings, active globals, and projected `NexusTK/browser/` path.
- Evidence against: it is the broad source root, not the direct semantic owner of a class aggregate; direct file ownership obscures the class relationship and is inconsistent with related class clusters like [UID:00020X] and [UID:000339].
- Decision: keep as source root and likely file placement, but no longer the direct target owner/emitter.

### 3. Shared helper or global owners

- Evidence for: [UID:000335], [UID:00033H], [UID:00033J], [UID:0003OH], [UID:0000PO], and [UID:0000PP] are dependencies or storage used by the class.
- Evidence against: none owns the class method bodies. Shared helpers are called by BrowserControlPane, but calls do not transfer ownership.
- Decision: reject as direct owners.

### 4. BrowserWindow / BrowserPane / BrowserThread / WebBoardDialog / generic UI

- Evidence for: nearby browser subsystem classes interact with BrowserControlPane or share analogous WndProc/accelerator patterns.
- Evidence against: BrowserWindow helper reads `g_pActiveBrowserWindow`; BrowserPane is owner/callback target; BrowserThread owns legacy host initialization; WebBoardDialog constructs/uses BrowserControlPane; generic UI supplies layout/ScreenPane consumers only.
- Decision: rejected.

### Proposed new file/grouping

- Proposed owner/name/path: no new by-file is required now. A future physical source split could create `browser/BrowserControlPane.cpp` while retaining [UID:0000HV] Browser as folder/source-root context.
- Likely full contents if split:
  - `BrowserControlPane` class constructor/destructor and scalar deleting destructor source-use context.
  - Control-pane shutdown, active/cursor, redraw, navigation, cookie/property, blit, backdrop/bounds, accelerator, QueryInterface, COM stub, dispatch, and child-window handler methods.
  - File-static child WndProc helper(s) if constructor registration is proven.
  - Active control-pane declaration/accessor for `g_activeBrowserControlPane`; possibly `g_activeBrowserPane` declaration if final header/source split chooses browser-control locality.
- Candidate related items that stay in broader Browser support:
  - `BrowserVariantFromString`, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, Browser COM GUID constants, `BrowserDispatchEventId`, and `InlineIsEqualGUID` source-use policy.
- Candidate related items rejected:
  - `g_pScreenPane` and `g_layoutContext_69B374` backing storage stay with ScreenPane/MainUiGraph.
  - WebBoardDialog constructors/virtuals stay with WebBoardDialog source.
  - BrowserWindow WndProc and retained raw clone stay with BrowserWindow/Broad Browser source context.
- Standalone, narrow, or broad source-file inference: broad Browser file now; narrow `BrowserControlPane.cpp` plausible but not required by current reconstructed project structure.

## Negative Evidence Summary

- Current live IDA was unavailable, so no fresh xref/function/pointer scan was possible.
- Address locality alone is not used as owner proof. The accepted class owner comes from constructor/destructor behavior, object offsets, vtable/static data, active globals, and class page context.
- Consumer xrefs from Application, SurfacePresentation, ScreenPane, and MainUiGraph are not ownership proof. They show BrowserControlPane must expose state/helpers across module boundaries, not that those modules own the storage or methods.
- The raw `0x0046ced0` WndProc-like body lacks currently documented registration or reachability proof. That blocks formal C++ for the raw clone and for the aggregate, but it does not block BrowserControlPane ownership.
- Exact original source names for many helpers remain inferred. That caps completion at `86`, but the major prior blockers are now evidence-bound rather than open.

## First-Draft C++ Recommendation

Do not populate [UID:0000Z6] formal `RECONSTRUCTION_CPP CODE` in this pass.

This target is eligible by the minimum combined-score/emitter gate after the recommended owner/emitter fix, but it is not safe for source output as one by-memory block:

- It covers many methods and compiler artifacts, not one function.
- It contains switch metadata ranges that must not emit standalone C++.
- It contains raw helper islands and a raw WndProc-like clone whose exact source/reachability is not final.
- It lacks exact child pages for the 54 promoted functions, so a `[[CHILDREN]]` aggregate skeleton would currently have no children to include.
- Emitting one large class implementation would exceed the target's reliable recovered source shape and would bake in provisional field, COM method, and WndProc names.

Recommended future C++ route:

1. Split exact child pages for the source-bearing methods/helpers and switch/raw islands.
2. Put formal C++ in those exact child pages when each child clears the gate and has source-quality names.
3. Keep [UID:0000Z6] as a class aggregate/inventory with blank C++, or later use only a child-include aggregate skeleton if by-structure/source tooling expects it.

Safe source-facing names for future child drafts, all inferred/descriptive:

```cpp
BrowserControlPane::BrowserControlPane(...);
BrowserControlPane::~BrowserControlPane();
void BrowserControlPane::ShutdownBrowserControl();
void BrowserControlPane::SetBrowserActiveState(...);
HRESULT BrowserControlPane::NavigateBrowser(const wchar_t *url);
HRESULT BrowserControlPane::SetDocumentCookie(const char *name, const char *value);
HRESULT BrowserControlPane::GetDocumentCookie(BSTR *cookie);
void BrowserControlPane::BlitBrowserSurface(...);
void BrowserControlPane::SyncBrowserWindowBounds();
static int __cdecl BrowserControlPaneTranslateAcceleratorMessage(MSG *message);
HRESULT BrowserControlPane::QueryInterface(REFIID riid, void **out);
HRESULT BrowserControlPane::HandleBrowserDispatchEvent(DISPID dispid, DISPPARAMS *params, VARIANT *result);
static LRESULT CALLBACK BrowserControlPaneChildWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
```

These names are recommended only as split-child staging names; they should not be inserted into [UID:0000Z6] as one aggregate C++ body.

## Final Recommendation

- Exact changes recommended:
  - [UID:0000Z6]: change `COMPLETION:84` to `86`.
  - [UID:0000Z6]: keep `CONFIDENCE:90`.
  - [UID:0000Z6]: change `CANONICAL_OWNER:0000HV` to `000015`.
  - [UID:0000Z6]: change `EMITTER_UIDS:0000HV` to `000015`.
  - [UID:0000Z6]: keep `RECONSTRUCTABLE:TRUE`.
  - [UID:0000Z6]: keep formal C++ blank with explicit no-code/source-shape proof.
- Exact parent assignments recommended:
  - Direct owner/emitter: [UID:000015] `BrowserControlPane`.
  - Source root remains [UID:0000HV] `Browser`.
- Exact items left no-owner/non-emitting:
  - Switch metadata/table subranges remain non-source artifacts and should not get owners as source bodies.
  - Alias globals `g_browserRuntime` and `g_pBrowserOverlayLayer` remain ignored aliases; backing storage belongs to ScreenPane/MainUiGraph docs.
- Exact future work outside this assignment:
  - Live IDA refresh for constructor child WndProc registration, raw `0x0046ced0` reachability, and exact `SetWindowLongA`/class-name registration.
  - Exact child split if formal method C++ is required.

## Exact Target / Support Text To Apply If Accepted

### [UID:0000Z6] metadata

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000015 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000015 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Add this section to [UID:0000Z6]:

```markdown
## B009 2026-06-19 Source-Quality Reanalysis

B009 reanalysis classifies this range as the canonical `BrowserControlPane` class aggregate under the Browser source root. The direct semantic owner/emitter should be [UID:000015] `BrowserControlPane`, not the broad [UID:0000HV] Browser file, because the constructor/destructor/navigation/blit/dispatch/COM/WndProc helper families all operate on BrowserControlPane object state and [UID:000015] already clears the 85/85 gate. The generated source path still resolves through [UID:0000HV] `NexusTK/browser/Browser.cpp`; a future physical source split to `browser/BrowserControlPane.cpp` remains plausible but is not required by current project structure.

COM GUID blockers are mostly resolved by [UID:0003OH]: `0x006315c0` is `IID_IOleInPlaceActiveObject`, `0x00631610` is `DIID_DWebBrowserEvents2`, `0x00631630` is `IID_IDocHostUIHandler`, `0x00631640` is `IID_IDocHostShowUI`, and `0x00631650` is `IID_IHTMLDocument2`. The raw document helper island at `0x0046be90` is therefore best modeled as `IHTMLDocument2` cookie/property helper logic; the `"%s=%s"` literal and SDK `IHTMLDocument2::put_cookie` / `get_cookie` slots make cookie get/set the strongest source-facing interpretation.

Active state/global evidence separates real BrowserControlPane storage from aliases. `g_activeBrowserControlPane` is the active `BrowserControlPane *` published/cleared by this class and consumed by Application/presentation paths; `g_activeBrowserPane` is the active browser-pane owner/callback target used by construction, Escape handling, and dispatch callbacks. `g_browserRuntime` is an alias for canonical `g_pScreenPane`, and `g_pBrowserOverlayLayer` is an alias for shared layout context storage at `0x0069b374`; neither should become a BrowserControlPane-owned declaration.

Formal C++ should remain blank on this aggregate. The target covers 54 promoted functions plus raw helper islands and compiler switch metadata, so a single C++ block would be a source-shape regression. Split exact child pages before emitting method bodies, especially for the raw helper islands `0x0046bc70`, `0x0046be90`, `0x0046c250`, the active accelerator helper `0x0046c550`, the dispatch handler `0x0046c960`, the promoted child-window handler `0x0046cd00`, and the raw WndProc-like clone `0x0046ced0`.
```

Replace or update the score rationale with:

```markdown
## Score Rationale

- Completion `86`: the page now has enough source-quality support to route the aggregate through the direct `BrowserControlPane` owner, resolve the major COM GUID/interface names, distinguish active globals from shared aliases, classify raw helper islands, validate the active `0x0046c550` accelerator route, and give an exact no-code proof for the aggregate. Completion remains below final reconstruction because exact child pages, final field names, COM method declarations, child WndProc registration, and raw clone reachability still need a split/source pass.
- Confidence `90`: existing live-IDA-backed docs cover boundaries, 54 promoted functions, raw islands, vtable data, globals, and dispatch behavior, and the support pages agree on BrowserControlPane/Brower source ownership. Confidence is not raised because current-session IDA MCP was unavailable and exact source names/source-file split remain inferred.
```

### Optional [UID:000015] BrowserControlPane support text

```markdown
- B009 2026-06-19 source-quality reanalysis recommends [UID:0000Z6] `BrowserControlPaneCore` use this class as its direct `CANONICAL_OWNER`/`EMITTER_UIDS`, with [UID:0000HV] Browser remaining the source root. The aggregate covers constructor/destructor/navigation/blit/dispatch/COM/child-window helper families, active `g_activeBrowserControlPane` and `g_activeBrowserPane` use, and raw helper islands that are all BrowserControlPane-specific. Formal C++ remains blank on the aggregate until exact child pages are split.
```

### Optional [UID:0000HV] Browser support text

```markdown
- B009 source-quality reanalysis on [UID:0000Z6] tightens the direct semantic owner to [UID:000015] `BrowserControlPane` while preserving this Browser file as the source root. If the future source tree splits the browser module, `BrowserControlPane` methods, child WndProc helpers, active control storage/accessors, and control-pane-specific navigation/blit/dispatch helpers are the likely contents of `browser/BrowserControlPane.cpp`; shared COM helpers and standard GUID policy remain Browser-wide support.
```

## Exact Coverage Replacement Rows

Do not edit `by-memory/-coverage-report.md` directly from B009. If the supervisor applies the recommendation, replace the current [UID:0000Z6] row with:

```markdown
    - [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) 0x0046b520-0x0046cfe0 | class aggregate | BrowserControlPaneCore : reconstructable : 86% : strong : B009 source-quality reanalysis confirms this is the canonical BrowserControlPane class aggregate under Browser source routing, recommends direct owner/emitter [UID:000015] BrowserControlPane, covers the prior 54 promoted-function inventory, raw helper islands at 0x0046bc70/0x0046be90/0x0046c250/0x0046ced0, resolved COM GUID identities including IID_IOleInPlaceActiveObject, DIID_DWebBrowserEvents2, IDocHost UI interfaces, and IID_IHTMLDocument2 cookie helpers, active g_activeBrowserControlPane and g_activeBrowserPane roles, g_browserRuntime/g_pBrowserOverlayLayer alias rejection, constructor/destructor/navigation/blit/dispatch/QueryInterface/COM-stub/child-window helper families, active 0x0046c550 accelerator route, promoted/raw child WndProc relationship, Browser.cpp versus possible BrowserControlPane.cpp source split, and formal C++ intentionally blank pending exact child splits rather than a monolithic aggregate body.
```

If generated coverage is refreshed manually, replace the current [UID:0000Z6] `auto-generated/-ag-memory-coverage.md` row with:

```markdown
| [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) | emits | `000015` | `000015` |  | no | `auto-generated/NexusTK/browser/Browser.cpp` | `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` |  |
```

If project-level stats are refreshed manually, replace the current [UID:0000Z6] `project-level/-auto-completion-stats.md` row with:

```markdown
| `0000Z6` | 86 | 90 | 88.0 | `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` |
```

## Follow-Up Actions

- Supervisor actions: apply the target metadata/support text, coverage row, generated coverage row if appropriate, and stats row after normal refresh/update workflow. Do not populate [UID:0000Z6] C++.
- A-agent actions: if assigned implementation, update [UID:0000Z6], [UID:000015], and [UID:0000HV] support text; validate affected docs; do not hand-edit generated/project-level reports unless workflow allows it.
- B009 future research actions: if reassigned to split this target, first restore live IDA access, then create exact child pages for source-bearing methods and raw islands before any final C++ entry.

## Confidence

- Recommendation confidence: high for owner/emitter change to [UID:000015] and Browser source-root retention.
- Score confidence: `86/90` is justified. Raising above that would require live IDA refresh, exact child splits, and stronger final names/prototypes.
- Remaining uncertainty: original physical file split, exact field names for URL/token/flags, final COM stub method names, child WndProc registration details, and raw `0x0046ced0` retention/reachability.

## Validator Results

- Commands run: none.
- Results: not applicable; this pass created only a B009 research report.
- IDA MCP check: failed to connect to `http://127.0.0.1:13337/mcp`.
- Any unresolved validator warnings/errors: not checked in this pass because no by-* files were edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0000Z6-BrowserControlPaneCore-source-quality.md`
- Modified: none outside this B009 research file.
- Renamed: none.
- Moved to executed: none.
- Leases: no lease was required because the only write was inside the B009 research folder, which B009 may edit without leasing.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000Z6-BrowserControlPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0000Z6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
