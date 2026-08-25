** TARGET-REPORT-UID:00033K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00033K BrowserNavigate Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation: UID00033K is reconstructed as source-authored `void Browser::Navigate(const wchar_t *url)` in `NexusTK/browser/Browser.cpp`, owned/emitted by UID000013 `Browser`.
- Final disposition: the accepted callback is complete. Browser `+0x18` is `CComQIPtr<IWebBrowser2> m_webBrowser`; the call at vtable `+0x2c` is inherited `IWebBrowser::Navigate`, not `IWebBrowser2::Navigate2`.
- B001 callback state: C33K-001 through C33K-032, nine destination updates, exactly five managed blocks, nine scoped validators, and the final waited generated verification are complete. No accepted B001 work remains.
- Confidence: very high for range, owner, caller set, interface IID, call slot, argument values/order, cleanup order, HRESULT behavior, and EH lowering; high for `CComQIPtr<IWebBrowser2>` and `CComVariant` source spelling; medium-high for exact project-local method/local names because original source symbols are absent.

## Supporting Research

- Agent-B001 performed this independent report-only pass on 2026-07-12 under `ntk-b-agent-workflow`.
- The evidence session was streamable IDA MCP database `bf5519ae`. At evidence time, `idb_list` returned one active `NexusTK.exe.i64` worker and `server_health` returned `status:ok`, image base `0x00400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Read-only MCP calls used `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `insn_query`, `xrefs_to`, `get_bytes`, and `imports_query`. No IDA mutation or MCP process-management call was made.
- Local SDK/type evidence used `ExDisp.h` for `IWebBrowser`, `IWebBrowser2`, `Navigate`, `Navigate2`, and `BrowserNavConstants`, plus ATL `atlcomcli.h` for `CComQIPtr`, `CComVariant`, `CComBSTR`, `AtlComQIPtrAssign`, and destructor/assignment behavior. These modern headers corroborate stable COM ABI/template shapes; they are not proof of the original compiler/header revision.
- Matching executed reports were searched by `UID00033K`, `0x00470dd0`, `BrowserNavigate`, `BrowserDialogOld`, `BrowserThreadInitializeBrowserHost`, `Browser::Invoke`, `IWebBrowser2`, and `BrowserVariantFromString`. B002/B007/B010/B013 reports were used only as leads and were rechecked against the live IDB and current docs.
- Historical report-only boundary: before Gate 1 acceptance, no by-* file, generated/coverage/tracker/supervisor file, validator, lease, report lifecycle, `execute_report`, move, or archive command was touched.
- Callback boundary: B001 edited only the nine accepted by-* destinations and this report, used short one-file leases, ran the authorized scoped validators and final `--wait-generated` check, and did not manually edit generated/coverage/tracker/supervisor files. B001 ran no report lifecycle, `execute_report`, move, or archive command.

## Target

- Target UID: `00033K`.
- Target path: `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`.
- Source queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue state observed at evidence time: `86/90`, average `88.0`, reconstructable true, report count `0`.
- Historical pre-callback metadata: completion `86`, confidence `90`, canonical owner UID000013, reconstructable true, emitter UID000013, blank position, blank formal C++.
- Current callback metadata: completion `92`, confidence `94`, canonical owner UID000013, reconstructable true, emitter UID000013, blank position, and the accepted formal method body.
- Historical generated state at research time: `auto-generated/NexusTK/browser/Browser.cpp` carried an empty UID00033K emitter marker and a source-emitting UID000335 free helper.
- Generated state verified after command `000000008785` at `2026-07-12T20:54:51-04:00`: exactly one UID00033K method body, no UID000335 marker/helper, the corrected `CComQIPtr<IWebBrowser2>` declaration, and the accepted destructor/host bodies.

## Current Target State

- Preserved facts: exact half-open range, Browser ownership, three call sites, BrowserWindow rejection, null guard on `this+0x18`, raw BSTR/VARIANT/SAFEARRAY activity, and ATL throw-helper edges.
- Resolved interface blocker: `m_webBrowser` is documented and emitted as `CComQIPtr<IWebBrowser2>` from IID/host-assignment/destructor evidence; the former raw/compatible-pointer caveat is retained only as superseded history.
- Resolved C++ state: the target emits the accepted complete formal method body.
- Resolved helper model: UID000335 is ownerless, non-reconstructable, non-emitting ATL `CComVariant(LPCOLESTR)` compiler/template lowering; its exact body/callers remain evidence and its historical project-helper interpretation is preserved.
- Current owner/emitter route is UID00033K -> UID000013 Browser -> UID0000HV Browser file.
- B001 work state: implementation and verification are complete with no remaining accepted item. Report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed by this artifact.

## Executive Recommendation

- UID00033K remains directly owned/emitted by UID000013 `Browser`, reconstructable true, position blank, and is now `92/94` with the exact target block.
- Browser `+0x18` is resolved as `CComQIPtr<IWebBrowser2> m_webBrowser`, not raw `IUnknown *`, raw `IDispatch *`, or BrowserWindow state.
- UID00032W host setup uses `CComQIPtr` assignment/query and preserves Advise/SetObjectRects HRESULT flow; UID00032Y uses `m_webBrowser.Release()` and documents final compiler member cleanup.
- UID000335 is non-reconstructable/non-emitting ATL template/compiler output with blank C++; exact bytes/callers and the historical free-helper interpretation are preserved.
- UID000336/UID00033I remain non-reconstructable with exact `CComVariant` destructor/`AtlThrow(CAtlException)` relationships.
- UID0000HV and UID0000ZF reflect source-ready UID00033K and no-source UID000335; waited generated output confirms the disposition.

## Supervisor Active Recheck

- Historical trigger: independent report-only UID00033K assignment from the updated B001 goal, followed by supervisor Gate 1 acceptance and this implementation callback.
- Split-first result: no target split or new child is required. UID00033K is one complete source method; EH funclets and ATL cleanup thunks lie outside its primary range and remain compiler/support documentation.
- Source-bearing result: one target method and three existing support formal blocks were changed exactly; one existing helper block became blank. Every formal change remains represented by a complete destination-specific managed block below.

## Inference Research Guidance Check

- `by-structure.md` requires the narrowest semantic owner, a valid emitter chain, exact managed insertion shape, behavior-preserving source, and separate handling for compiler/template output. Those rules support Browser class ownership, source emission for UID00033K, and no emission for UID000335.
- Existing Browser/BrowserWindow/BrowserThread docs were treated as hypotheses where they retained the interface caveat, raw-pointer host code, or blank target conclusion.
- Direct IDA facts are addresses, bytes, xrefs, field offsets, immediates, imports, vtable offsets, call order, branch tests, and EH funclets. SDK/ATL declarations are ABI/source-shape corroboration. Human names and exact wrapper spelling remain inference.
- Stale Wave2/Wave3 wording was ignored as evidence. Current by-* docs, live IDB facts, generated output, SDK declarations, and current workflow rules control this report.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Evidence | Disposition |
| --- | --- | --- | --- |
| Class owner | All three routes produce a Browser base pointer; body reads Browser `+0x18`. | Calls `0x4694b9`, `0x46f892`, `0x470d92`; Browser layout/destructor. | UID000013 Browser; reject BrowserWindow/BrowserThread/Dialog owner. |
| Member static type | Host setup QIs `IID_IWebBrowser2` directly into `Browser+0x18` using compare/QI/release-old shape. | GUID `0x00631600`; host disassembly `0x470c7b-0x470cb0`; ATL `CComQIPtr` assignment shape; member-destructor release. | `CComQIPtr<IWebBrowser2> m_webBrowser`. |
| Called interface method | Slot `+0x2c` is the fifth IWebBrowser method after IDispatch and is inherited unchanged by IWebBrowser2. | Target `call [eax+2Ch]`; `ExDisp.h` vtable order/signature. | `m_webBrowser->Navigate(...)`, not `Navigate2`. |
| Return/HRESULT | Source method returns void; COM `HRESULT` is not tested or stored. | `retn 4`; call result immediately discarded; no post-call test. | `void Browser::Navigate`; ignore Navigate HRESULT exactly. |
| URL representation | Input is passed to `SysAllocString`, raw BSTR passed to Navigate, then freed manually. | `0x470e14-0x470e28`, `0x470ec4`, `0x470ee4-0x470ee5`. | Raw `BSTR browserUrl`, not `CComBSTR`; preserve unchecked allocation. |
| Variant family | Four 16-byte locals have CComVariant constructor/destructor and ATL throw patterns. | zero+VariantInit, ClearThrow pattern, `CAtlException` RTTI, four unwind funclets to `VariantClear`. | Use `CComVariant`; reject `_variant_t` and raw hand-written error checks. |
| Post data | Default variant becomes `vt=VT_ARRAY`; `parray=SafeArrayCreate(VT_UI1,0,NULL)`. No data are inserted. | immediates `0x2000`, `0x11`, `0`, `0`; no SafeArray access/put call. | Preserve exact unusual empty post-data representation. |
| Headers | CComVariant null-wide-string construction produces `VT_BSTR` plus `SysAllocString(NULL)`. | first inline ClearThrow sequence at `0x470e4f-0x470e6e`. | `CComVariant headers((LPCOLESTR)NULL)`. |
| Target frame | Same null-BSTR construction as headers. | second inline ClearThrow sequence at `0x470e77-0x470e96`. | `CComVariant targetFrameName((LPCOLESTR)NULL)`. |
| Flags | Local has `vt=VT_I4`, value `2`; SDK enum maps `2` to `navNoHistory`. | `0x470e99-0x470ea5`; `BrowserNavConstants`. | `CComVariant flags(navNoHistory)`. |
| Argument order | Push order reverses headers, postData, targetFrameName, flags, URL, this. | `0x470eac-0x470ec6`; IWebBrowser signature. | URL, flags, target, post, headers exactly. |
| Normal cleanup | Flags, target, headers clear first; then SafeArrayDestroy, SysFreeString, postData clear. | `0x470ec9-0x470eef`. | Preserve source declaration/explicit-cleanup order. |
| Error paths | Only two inline CComVariant string-constructor ClearThrow checks call `0x470960`; Navigate and ordinary cleanup HRESULTs are ignored. | branches `0x470e5b`, `0x470e83`; no other tests. | Do not synthesize COM call error handling. |
| EH lowering | Four unwind funclets call shared `VariantClear` thunk; frame uses CxxFrameHandler3/security cookie. | `0x5faff0-0x5fb026`, thunk `0x470270`. | Compiler output from four CComVariant locals, not source catch blocks. |
| UID000335 helper | Exact body is CComVariant LPCOLESTR constructor/assignment: vt empty, ClearThrow, VT_BSTR, SysAllocString, E_OUTOFMEMORY AtlThrow, return this. | decompile `0x470170`; two calls only; local ATL header match. | Reclassify compiler/template output; no project free helper emission. |
| Source placement | Browser vtable symbols are anonymous-namespace Browser; owner/file docs route to browser/Browser.cpp. | vtable names `anonymous namespace'::Browser`; current UID chain. | Existing Browser.cpp source root, no new source file. |

Ownership and cleanup paths:

- Null member path: when `m_webBrowser` is null, the method returns before constructing or owning any temporary.
- Normal path, including a failed Navigate HRESULT: the ignored COM result does not change control flow. CComVariant destructors clear flags, target frame, and headers; source then calls SafeArrayDestroy on the stored post-data array and SysFreeString on the URL BSTR; the postData CComVariant destructor finally calls VariantClear.
- ATL constructor exception path: the EH state unwinds only CComVariant objects whose construction completed. The raw URL BSTR has no unwind owner, so an exception from either later null-BSTR CComVariant constructor can leak that BSTR; postData itself remains covered by its CComVariant unwind destructor.
- Allocation/API failure path: SysAllocString(url) and SafeArrayCreate results are unchecked; SafeArrayDestroy, SysFreeString, and normal destructor VariantClear results are not propagated. The only explicit HRESULT-to-exception conversion is CComVariant ClearThrow during the two null-BSTR constructions.

Rejected alternatives:

- `BrowserWindow::Navigate`: rejected because BrowserWindow has its own distinct `0x00469ca0` method and no caller route supplies a BrowserWindow object to UID00033K.
- `IWebBrowser *m_webBrowser`: rejected as the stored static type because host setup explicitly queries `IID_IWebBrowser2`; the invoked method is inherited IWebBrowser ABI, but the member's QI type is IWebBrowser2.
- Raw `IWebBrowser2 *`: rejected as the most likely source member because assignment and final destructor behavior match `CComQIPtr` ownership, QI, release-old, and member teardown.
- `IWebBrowser2::Navigate2`: rejected because Navigate2 accepts a VARIANT URL and lies far beyond slot `+0x2c`; the binary passes a BSTR URL to inherited Navigate.
- `_variant_t`: rejected because observed throw RTTI is `ATL::CAtlException` and construction/destruction match `CComVariant`/`AtlThrow`, not `_com_error` behavior.
- `CComBSTR browserUrl`: rejected because the raw URL BSTR has no EH cleanup state and is freed explicitly after SafeArrayDestroy.
- Raw decompiler `VARIANTARG` setup as the final source: rejected because the repeated constructor/destructor patterns and shared helper identify ordinary ATL wrappers.
- Treating `0x470960` calls as Navigate HRESULT handling: rejected; both precede the COM call and arise only from CComVariant null-BSTR construction.
- Leaving UID000335 as a free helper: rejected because the function is an ATL constructor/template instantiation and target-local equivalent code is inlined.

## Evidence Standards Used

- Highest-weight evidence: complete target disassembly/decompilation, exact bytes/range, direct xrefs, host initialization QI/GUID flow, Browser destructor ownership, COM vtable offset, OLEAUT32 imports, and EH funclets.
- Strong corroboration: SDK `ExDisp.h` method order/signatures and ATL `CComQIPtr`/`CComVariant` implementation shape, current Browser class/file docs, and the separate BrowserWindow navigation implementation.
- Old reports and generated C++ were lead material only. Any old interface caveat, blank-code conclusion, or free-helper classification was rechecked rather than inherited.
- Confidence stays below `95` because original source spelling, exact ATL release/header revision, and compile-to-binary equivalence are not proven.

## Evidence Checked

- IDA MCP checks:
  - `idb_list` and `server_health` for `bf5519ae`.
  - `lookup_funcs` for target, boundaries, callers, BrowserWindow navigate, host init, Browser destructor, variant constructor, cleanup thunk, and ATL throw helper.
  - `analyze_function`, complete 123-instruction `disasm`, and addressed `decompile` for `0x00470dd0`.
  - Decompilation/disassembly for `0x00469ca0`, `0x00470a00`, `0x0046f480`, `0x0046ff50`, `0x00470170`, `0x00470960`, and caller windows around all three target xrefs.
  - `xrefs_to` for UID00033K, `0x00470170`, `0x00470270`, `0x00470960`, `IID_IWebBrowser2`, and `CLSID_WebBrowser`.
  - `get_bytes` for GUIDs and target predecessor/successor boundaries.
  - `imports_query` for VariantInit, VariantClear, SysAllocString, SysFreeString, SafeArrayCreate, and SafeArrayDestroy; all resolve to OLEAUT32.
- Documentation checked: UID00033K, UID000013, UID00001B, UID00001A, UID0000HV, UID0000ZF, UID00032W, UID00032Y, UID000331, UID0000Z3, UID000335, UID000336, UID00033I, UID0003OH, generated Browser.cpp, by-memory generated coverage, research tracker, and completion stats.
- Matching executed reports checked as leads: B002 UID0000HV/UID0000Z4, B007 UID000013/UID000331, B010 UID00032W, and B013 UID0000Z3.
- Local declarations checked: `ExDisp.h` IWebBrowser/IWebBrowser2 vtables and BrowserNavConstants; `atlcomcli.h` CComQIPtr/CComVariant construction, assignment, Release, and destruction.
- Negative checks: no fourth target caller, no BrowserWindow route, no Navigate2 slot, no post-data population, no target-frame/header text, no Navigate HRESULT test, no BSTR allocation test, no source catch body, and no target use of `m_navigationBuffer` except through callers.
- Historical report-pass exclusions: IDA rename/type/comment mutation, compile-to-binary experiment, validators, and project-documentation implementation were skipped before Gate 1. The accepted callback later performed only the documented by-* edits and validators; IDA mutation and compile-to-binary work remain unperformed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C33K-001 | Exact target range is `[0x00470dd0,0x00470f10)`, size `0x140`. | Very high | lookup/disasm/bytes. | UID00033K range. | Applied. | Exact range/size retained in target Scope and evidence. |
| C33K-002 | Seven `0xcc` bytes precede the target and sixteen follow it before UID00033L. | Very high | raw bytes and neighbor starts. | UID00033K range/padding. | Applied. | Both padding runs and successor retained in target boundary evidence. |
| C33K-003 | Signature is void thiscall with one wide-string pointer and `retn 4`. | Very high | full disassembly/callers. | UID00033K signature/C++. | Applied. | Formal body emits `void Browser::Navigate(const wchar_t *url)`; ABI evidence retained. |
| C33K-004 | Direct caller set is exactly `0x4694b9`, `0x46f892`, and `0x470d92`. | Very high | xrefs_to. | Target/class/file/caller inventory. | Applied. | All three and no-fourth-caller evidence recorded in target/class/file. |
| C33K-005 | `0x4694b9` tail-dispatches from BrowserDialogOld through control manager and BrowserControlPaneOld `+0x110`. | High | raw caller disassembly/current UID0000Z3. | Target/UID0000Z3 history. | Applied/preserved. | Target and Browser file retain the old-dialog/control-pane route; UID0000Z3 needed no edit. |
| C33K-006 | `0x46f892` adjusts the IDispatch view by `-8` to Browser base before calling. | Very high | caller disassembly/current UID000331. | Target/UID000331 support. | Applied/preserved. | Target records the `-8` adjustment; UID000331 needed no edit. |
| C33K-007 | `0x470d92` loads BrowserThread `+0x68` Browser pointer and passes Browser `+0x228` navigation buffer. | Very high | caller disassembly. | Target/UID00032W. | Applied. | Target and updated UID00032W record the exact final handoff. |
| C33K-008 | Body returns immediately when Browser `+0x18` is null. | Very high | `cmp [esi+18h],0`. | Target behavior/C++. | Applied. | First formal-body guard is `m_webBrowser == NULL`. |
| C33K-009 | Browser `+0x18` is queried as IID_IWebBrowser2 and has CComQIPtr assignment/destructor shape. | High | GUID/host/destructor/ATL. | UID000013/UID00032W/UID00032Y. | Applied. | Complete class, host, and destructor blocks/prose now use `CComQIPtr<IWebBrowser2>`. |
| C33K-010 | Call slot `+0x2c` is inherited IWebBrowser::Navigate, not Navigate2. | Very high | call offset and ExDisp vtable. | Target/class/file. | Applied. | Target/class/file identify inherited Navigate; Navigate2 remains rejected. |
| C33K-011 | URL is copied with SysAllocString into a raw BSTR. | Very high | target disassembly. | Target behavior/C++. | Applied. | Formal body and evidence use raw `BSTR browserUrl = SysAllocString(url)`. |
| C33K-012 | PostData is a default CComVariant later set to `VT_ARRAY`. | High | constructor/EH pattern and immediate. | Target behavior/C++. | Applied. | Formal body/evidence preserve default construction then `postData.vt = VT_ARRAY`. |
| C33K-013 | PostData parray is SafeArrayCreate(VT_UI1,0,NULL), with no data population. | Very high | exact pushes/import/callee absence. | Target behavior/C++. | Applied. | Exact call and no-population negative evidence retained. |
| C33K-014 | Headers is a CComVariant null BSTR. | High | first ClearThrow/SysAllocString(NULL) sequence. | Target behavior/C++. | Applied. | Exact null-LPCOLESTR `headers` construction emitted and documented. |
| C33K-015 | TargetFrameName is a CComVariant null BSTR. | High | second sequence. | Target behavior/C++. | Applied. | Exact null-LPCOLESTR `targetFrameName` construction emitted and documented. |
| C33K-016 | Flags is VT_I4 value 2, source-facing navNoHistory. | Very high | immediate and SDK enum. | Target behavior/C++. | Applied. | Formal body uses `CComVariant flags(navNoHistory)`; value/enum evidence retained. |
| C33K-017 | Navigate argument order is URL, flags, target, post, headers. | Very high | push order and SDK signature. | Target behavior/C++. | Applied. | Formal call preserves exact five-argument order. |
| C33K-018 | Navigate HRESULT is ignored. | Very high | no result store/test. | Target negative evidence. | Applied. | Formal call has no result capture/test; negative evidence retained. |
| C33K-019 | Normal cleanup order is flags, target, headers, SafeArray, URL BSTR, postData. | Very high | `0x470ec9-0x470eef`. | Target cleanup/C++. | Applied. | Declaration/destruction and explicit SafeArray/BSTR cleanup order documented exactly. |
| C33K-020 | VariantClear/SafeArrayDestroy HRESULTs on normal cleanup are ignored. | Very high | no tests after cleanup calls. | Target HRESULT section. | Applied. | Target records and formal source preserves ignored cleanup results. |
| C33K-021 | The two AtlThrow paths are CComVariant ClearThrow lowering before Navigate. | High | branches/throw RTTI/ATL shape. | Target/EH/UID00033I. | Applied. | Target and UID00033I identify pre-Navigate null-BSTR constructor ClearThrow paths. |
| C33K-022 | Four unwind funclets are CComVariant destructors calling VariantClear thunk `0x470270`. | High | EH funclets/xrefs/thunk bytes. | Target/UID000336. | Applied. | Target and UID000336 list thunk plus all four unwind addresses. |
| C33K-023 | Raw URL BSTR is not protected by an unwind destructor state. | High | EH state/funclet inventory. | Target failure semantics. | Applied. | Raw-BSTR exception leak caveat and negative EH evidence retained. |
| C33K-024 | UID000335 is CComVariant LPCOLESTR template/compiler output, not project free source. | High | exact ATL match/two constructor calls. | UID000335/file/aggregate. | Applied. | UID000335 is NONE/false/no emitter/blank; file and aggregate inventories are corrected. |
| C33K-025 | UID000336/UID00033I remain non-reconstructable compiler/library support. | Very high | current docs/live disasm. | Both support pages. | Applied. | Both remain NONE/false/no emitter/blank with refined scores/prose. |
| C33K-026 | BrowserWindow owns distinct `0x00469ca0` NavigateBrowser and does not own target. | Very high | separate complete body/callers. | Target/class history. | Preserved. | Target/class/file retain distinct BrowserWindow method and rejected ownership. |
| C33K-027 | Source root remains browser/Browser.cpp; no new file/group is warranted. | High | owner chain/vtable symbols/current source tree. | Target/class/file. | Applied. | UID0000HV route retained; no new UID/file/group created. |
| C33K-028 | UID00033K formal body is source-ready and uses CComVariant/CComQIPtr abstractions. | High | combined evidence. | UID00033K block. | Applied. | Exact accepted target managed block inserted and validator-confirmed. |
| C33K-029 | Browser class formal member must become CComQIPtr<IWebBrowser2>. | High | host/destructor/ATL. | UID000013 block. | Applied. | Exact complete class block inserted; only accepted member-type delta made. |
| C33K-030 | Host init formal body must use CComQIPtr assignment/query and preserve Advise/SetObjectRects HRESULT flow. | High | host disasm. | UID00032W block. | Applied. | Exact complete host block inserted with both HRESULT gates. |
| C33K-031 | Browser destructor formal body must use m_webBrowser.Release and member cleanup lowering. | High | destructor disasm/ATL. | UID00032Y block. | Applied. | Exact complete destructor block inserted; compiler member cleanup documented. |
| C33K-032 | Browser file/aggregate/helper inventories and scores must reflect source-ready target and no-source UID000335. | High | current docs/generated state. | UID0000HV/UID0000ZF/support scores. | Applied. | Both inventories and all nine accepted scores/metadata verified after validators. |

## Positive Evidence Summary

- Exact IID evidence fixes the member's interface: host setup queries GUID `d30c1661-cdaf-11d0-8a3e-00c04fc9e26e`, IID_IWebBrowser2, into Browser `+0x18`.
- Exact vtable evidence fixes the call: `+0x2c` is IWebBrowser::Navigate with BSTR URL and four VARIANT pointers; Navigate2 has a different URL type and later slot.
- Three independent callers converge on Browser base identity through direct object storage, a `-8` IDispatch adjustment, and a legacy control-child lookup.
- ATL throw RTTI, constructor checks, cleanup thunk, and four unwind funclets identify CComVariant semantics rather than ad hoc raw VARIANT logic.
- Host assignment and destructor teardown identify CComQIPtr ownership rather than a borrowed raw pointer.
- BrowserWindow's parallel method corroborates the same Navigate ABI while proving UID00033K is a distinct Browser method.

## IDA MCP Facts

- Function: `sub_470DD0`, start `0x00470dd0`, size `0x140`, end `0x00470f10`, 123 modeled instructions.
- Prototype currently inferred by IDA: `void __thiscall(_DWORD *this, OLECHAR *psz)`; source refinement is Browser plus const wide string.
- Direct xrefs: `0x004694b9`, `0x0046f892`, `0x00470d92`; no fourth xref.
- Imports: OLEAUT32 VariantInit `0x60d320`, VariantClear `0x60d31c`, SysAllocString `0x60d32c`, SysFreeString `0x60d318`, SafeArrayCreate `0x60d324`, SafeArrayDestroy `0x60d314`.
- Browser `+0x18` host QI uses IID_IWebBrowser2 at `0x00631600`; WebBrowser creation uses CLSID_WebBrowser at `0x00631620` and begins from IID_IOleObject.
- ATL throw helper `0x00470960` throws RTTI type `ATL::CAtlException`; target calls it only at `0x00470f05` and `0x00470f0b`.
- EH uses four cleanup funclets at `0x005faff0`, `0x005faff8`, `0x005fb000`, and `0x005fb008`, all tailing to the VariantClear thunk at `0x00470270`; frame handler is CxxFrameHandler3 with security cookie.
- Padding: target follows seven `0xcc` bytes after host init and is followed by sixteen `0xcc` bytes before UID00033L at `0x00470f20`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Applied status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00470dd0-0x00470f10` | UID00033K | Browser::Navigate | true | UID000013 | `86/90 -> 92/94` | Exact target body emitted. |
| Browser declaration | UID000013 | Browser class/layout | true | UID0000HV | `88/90 -> 90/93` | CComQIPtr member resolved; exact class block applied. |
| `0x00470a00-0x00470dc9` | UID00032W | BrowserThread host init | true | UID00001A | `90/92 -> 91/93` | Correct QIPtr/HRESULT source shape applied. |
| `0x0046f480-0x0046f53e` | UID00032Y | Browser destructor | true | UID000013 | `90/92 -> 91/93` | Correct QIPtr Release source shape applied. |
| `0x00470170-0x004701c9` | UID000335 | CComVariant LPCOLESTR lowering | false | none | `88/91 -> 91/93` | Free-helper emission removed; block blank. |
| `0x004701d0-0x00470278` | UID000336 | mixed cleanup/thunk island | false | none | `86/88 -> 88/91` | CComVariant destructor relationship added. |
| `0x00470960-0x0047097c` | UID00033I | ATL CAtlException throw helper | false | none | `86/89 -> 88/92` | Exact ClearThrow provenance added. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004694b9` | raw tail jump from BrowserDialogOld helper `0x004694a0` | Preserves incoming URL and dispatches through legacy control manager/BrowserControlPaneOld `+0x110` Browser pointer. |
| `0x0046f892` | Browser::Invoke case 250 | Converts IDispatch subobject at Browser `+8` back to Browser base with `lea ecx,[ecx-8]`, then calls with `L"about:blank"`. |
| `0x00470d92` | BrowserThread::InitializeBrowserHost | Loads BrowserThread `+0x68`, pushes Browser `+0x228` navigation buffer, calls target. |
| `0x00470ec6` | indirect call `[m_webBrowser->vtable+0x2c]` | IWebBrowser::Navigate inherited by IWebBrowser2. |
| `0x00470f05`, `0x00470f0b` | CAtlException throw helper | CComVariant null-BSTR constructor ClearThrow failures, not Navigate failures. |
| `0x005faff0-0x005fb00b` | four EH cleanup funclets | CComVariant destruction via shared VariantClear thunk. |

## Documentation Evidence And IDA Status

- Supporting docs preserve Browser ownership/caller identity, BrowserThread `+0x68`, Browser `+0x228`, IDispatch `-8` adjustment, separate BrowserWindow method, IID_IWebBrowser2 GUID, and ATL throw-helper evidence.
- Historical stale points were target blank C++, Browser raw-pointer caveat, UID32W manual raw QI, UID32Y raw cleanup, UID000335 project-helper classification, and aggregate/file rows. All accepted stale points are now corrected while prior evidence/history is retained.
- Generated state at research time mirrored those stale points. Waited command `000000008785` now emits the accepted target/class/host/destructor source and no UID000335 marker/helper.
- No document in the accepted scope contradicts Browser ownership after the B013 correction; this callback preserves that correction and closes the accepted type/C++ blockers.

## Ranked Ownership Analysis

### 1. UID000013 Browser

- Evidence for: all callers produce Browser base identity, body reads Browser `+0x18`, Browser destructor/host init own the same member, and method is declared in the current Browser class block.
- Evidence against: original source method name is not symbol-proven.
- Decision: accepted as direct semantic owner and emitter.

### 2. UID0000HV Browser File

- Evidence for: anonymous-namespace Browser vtable symbols and all COM/OLE support live under the Browser source root.
- Evidence against: by-structure requires the narrower class owner for a class method.
- Decision: generated root only, reached through UID000013.

### 3. UID00001B BrowserWindow

- Evidence for: BrowserWindow has a similar IWebBrowser Navigate body and same `+0x18` offset.
- Evidence against: it owns separate `0x00469ca0`; no UID00033K caller passes BrowserWindow; BrowserThread/Invoke/legacy helper all prove Browser.
- Decision: rejected; preserve as comparative evidence only.

### 4. BrowserThread / BrowserDialogOld / BrowserControlPaneOld

- Evidence for: each participates in one caller route.
- Evidence against: they only locate/hold/call Browser; target body accesses Browser state and no caller-owned fields.
- Decision: rejected as owners.

### Proposed new file/grouping, if applicable

- No new source file or class. UID00033K belongs to the existing anonymous-namespace Browser class in `browser/Browser.cpp`.
- UID000335 should disappear as a source helper; CComVariant source expressions in BrowserWindow/BrowserControlPane/BrowserNavigate regenerate equivalent ATL template code.

## Source Placement

- Recommended placement: `Browser::Navigate` definition in `NexusTK/browser/Browser.cpp`, alongside Browser COM/event-sink methods.
- Class declaration remains in the same generated Browser source context; the binary's anonymous-namespace vtable symbols support a `.cpp`-local class rather than a public cross-module header.
- Rejected placements: BrowserWindow source method, BrowserThread source, BrowserDialogOld source, a generic COM utility file, or a new BrowserNavigate.cpp.
- Remaining placement uncertainty: exact one-file versus historical internal class-file split is not symbol-proven, but no uncertainty affects the existing UID0000HV source root.

## Range / Split / Padding / Reclassification Analysis

- Target range remains exactly `[0x00470dd0,0x00470f10)`; no split is required.
- Predecessor host-init ends at `0x00470dc9`; `[0x00470dc9,0x00470dd0)` is seven-byte alignment padding.
- Target normal return ends at `0x00470f04`; two ATL throw tails occupy `0x00470f04-0x00470f10` and remain part of the method's compiled range.
- `[0x00470f10,0x00470f20)` is sixteen-byte alignment padding before UID00033L.
- EH funclets at `0x005faff0-0x005fb02b` and VariantClear thunk `0x00470270` are compiler support, not target children to merge.
- UID000335 is the only reclassification: exact bytes remain documented, but it becomes non-reconstructable/non-emitting ATL template/compiler output.

## Negative Evidence Summary

- No fourth direct/indirect target xref was found.
- No BrowserWindow pointer route reaches UID00033K.
- No QueryInterface occurs inside UID00033K; interface selection happened earlier in host setup.
- No Navigate2 slot or VARIANT URL is used.
- No PostData bytes, dimensions, bounds, SafeArrayPutElement, SafeArrayAccessData, headers text, or target frame text exist.
- No Navigate HRESULT test, retry, throw, status store, or return propagation exists.
- No SysAllocString or SafeArrayCreate failure check exists in the method.
- No C++ catch block exists; EH funclets are automatic CComVariant cleanup.
- No target read of Browser `+0x228` occurs; that field is a caller-supplied URL source, not target-internal state.
- Address adjacency to BrowserThread and similarity to BrowserWindow are not ownership proof and are outweighed by object identity.

## IDA Rename / Type / Comment Recommendations

- IDA mutation was not requested and none was performed during either report research or callback.
- Source-facing target name/type: `void Browser::Navigate(const wchar_t *url)`.
- Source-facing field type/name: `CComQIPtr<IWebBrowser2> m_webBrowser` at Browser `+0x18`.
- Suggested analysis comment: calls inherited IWebBrowser::Navigate with navNoHistory, null target/headers, empty array post data, ignores HRESULT, and performs explicit normal BSTR/SAFEARRAY cleanup around CComVariant locals.
- UID000335 analysis name should describe `CComVariant(LPCOLESTR)` construction rather than a project Browser helper if a later authorized IDA pass occurs.

## First-Draft C++ Recommendation

- Eligible: yes. Whole-report managed-block count is exactly five: target UID00033K, Browser class UID000013, host init UID00032W, Browser destructor UID00032Y, and blank reclassification block UID000335.
- No other C++ body, declaration, sample, or fragment is proposed elsewhere in this report.

Destination: `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md` (UID00033K).

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-class/Browser.md` (UID000013). This is the complete current class block with only the accepted `m_webBrowser` type correction.

```text
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
```

Destination: `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md` (UID00032W). Complete replacement block preserving unrelated accepted code.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md` (UID00032Y). Complete replacement block.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination: `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` (UID000335). Exact blank formal block after compiler/template reclassification.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: all target immediates, API calls, null handling, argument order, ignored HRESULTs, normal cleanup ordering, and exception-generated cleanup remain represented.
- Source quality: ordinary ATL smart pointers/variants express the source operations that generated the raw binary mechanics; no `sub_`, `unk_`, decompiler temporary, or invented helper remains.
- Third-party import directive: not applicable; this is NexusTK Browser source using platform SDK/ATL declarations.

## Final Recommendation

- C33K-001 through C33K-032 are applied without compression.
- Exactly the five managed blocks above are applied; no additional body/declaration fragment was introduced.
- UID00033K remains owner/emitter UID000013, reconstructable true, position blank, at `92/94`.
- Browser `+0x18` is `CComQIPtr<IWebBrowser2>`; `+0x14` HWND, `+0x1c` advise cookie, `+0x228` navigation buffer, `+0x22c` state flags, and `+0x230` current URL remain distinct fields.
- BrowserWindow's separate `0x00469ca0` method and all three Browser caller routes are preserved.
- UID000335 is removed from emitted source and the by-file free-helper list while its exact ATL constructor-lowering evidence is retained.
- UID000336 cleanup thunks and UID00033I throw support remain non-emitting.
- No new file, new UID, split, rename, manual generated/tracker edit, or IDA mutation occurred.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`.
- Applied metadata: `86/90 -> 92/94`; owner UID000013, reconstructable true, emitter UID000013, and blank position are unchanged.
- The former blank formal block now contains the exact UID00033K block above.
- Exact range/padding, three callers/object adjustments, null guard, CComQIPtr/IWebBrowser2 field, inherited Navigate slot, BSTR URL, four CComVariant locals, SafeArray values, navNoHistory, null target/headers, argument order, ignored HRESULTs, cleanup order, EH funclets, raw-BSTR unwind caveat, and all negative evidence are incorporated.
- The interface caveat and blank-code decision are historicalized; the BrowserWindow ownership correction and earlier provenance are preserved.

## Recommended Support Doc Changes

- `by-class/Browser.md` UID000013:
  - Applied `88/90 -> 90/93`; metadata route unchanged.
  - Exact complete class block applied; only formal declaration delta is `CComQIPtr<IWebBrowser2> m_webBrowser`.
  - Static-type caveat replaced with QI/ATL/destructor proof and complete UID00033K behavior.
- `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md` UID00032W:
  - Applied `90/92 -> 91/93`; owner/emitter/true unchanged.
  - Exact complete support block applied with all unrelated accepted code preserved.
  - CComQIPtr assignment from IOleObject, Advise HRESULT flow, CComQIPtr IOleInPlaceObject query, SetObjectRects HRESULT, and final UID00033K call recorded.
- `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md` UID00032Y:
  - Applied `90/92 -> 91/93`; owner/emitter/true unchanged.
  - Exact complete support block applied; final member-destructor check is documented as compiler CComQIPtr cleanup.
- `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md` UID000335:
  - Applied `88/91 -> 91/93`; owner UID0000HV -> NONE; reconstructable true -> false; emitter UID0000HV -> blank; position blank; C++ blank.
  - Exact body/callers preserved and reframed as out-of-line ATL CComVariant LPCOLESTR constructor/template lowering; project free-helper name historicalized.
- `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md` UID000336:
  - Applied `86/88 -> 88/91`; metadata remains none/false/blank.
  - `0x00470270` identified as CComVariant destructor VariantClear thunk; four UID00033K unwind refs added.
- `by-memory/0x00470960-0x0047097c.CAtlExceptionThrowHelper.md` UID00033I:
  - Applied `86/89 -> 88/92`; metadata remains none/false/blank.
  - Target calls clarified as CComVariant ClearThrow constructor paths, not IWebBrowser Navigate failure handling.
- `by-file/Browser.md` UID0000HV:
  - Applied `87/89 -> 89/92`; FILE root/path unchanged.
  - BrowserVariantFromString removed from source free helpers; UID00033K source-ready behavior, CComQIPtr/CComVariant rationale, and Browser class contents updated.
- `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` UID0000ZF:
  - Applied `91/92 -> 92/93`; remains non-reconstructable, owner/emitter blank.
  - UID000335/UID00033K rows and compiler/support distinctions updated; full split inventory preserved.
- Checked/no-edit support: UID000331 BrowserInvoke, UID0000Z3 BrowserDialogOldCore, UID00001B BrowserWindow, UID00001A BrowserThread, UID0003OH GUID constants. Their current caller/ownership/GUID facts already meet this report.

## Score And Metadata Recommendation

| Item | Pre-callback | Applied | Rationale |
| --- | --- | --- | --- |
| UID00033K | `86/90` | `92/94` | Complete binary/source behavior, formal body, exact interface/caller/EH resolution. |
| UID000013 | `88/90` | `90/93` | Exact member wrapper/type and target method close the static-type caveat. |
| UID00032W | `90/92` | `91/93` | Correct ATL pointer assignment/query and HRESULT flow. |
| UID00032Y | `90/92` | `91/93` | Correct CComQIPtr source cleanup and compiler-member teardown. |
| UID000335 | `88/91` | `91/93` | Exact template/compiler classification; no source body. |
| UID000336 | `86/88` | `88/91` | Exact CComVariant cleanup-thunk role and target unwind refs. |
| UID00033I | `86/89` | `88/92` | Exact CComVariant ClearThrow provenance. |
| UID0000HV | `87/89` | `89/92` | Correct Browser source inventory and target/interface source shape. |
| UID0000ZF | `91/92` | `92/93` | Correct complete split rows and ATL/compiler classification. |

- Reason not higher: no original source/PDB, no exact historical ATL header revision, no compile-to-binary equivalence, and unusual postData VARTYPE intent remains unexplained even though its runtime value is exact.
- Score-improvement work completed: full target disassembly, all callers, QI IID bytes/xrefs, host assignment, destructor member cleanup, SDK vtable/enum, ATL constructor/destructor comparison, OLEAUT imports, BrowserWindow comparison, EH funclets, boundaries, old-report recheck, and generated/source inventory review.

## Open Questions With Attempted Resolution

- Exact member wrapper:
  - Checked host QI assignment, old-pointer release, constructor zeroing, source destructor Release, compiler member destructor, and ATL templates.
  - Resolution: `CComQIPtr<IWebBrowser2>` is the highest-probability source type and is safe for first draft. An equivalent project typedef is possible but does not justify preserving a raw-pointer caveat.
- Navigate versus Navigate2:
  - Checked call slot, URL argument type, SDK inherited vtable order, IID stored in the member.
  - Resolution: inherited IWebBrowser::Navigate is exact; Navigate2 is rejected.
- CComVariant versus `_variant_t`/raw VARIANT:
  - Checked CAtlException RTTI, ClearThrow shape, constructor helper, default constructor, destructors, and EH funclets.
  - Resolution: CComVariant is exact enough for formal C++; `_variant_t` is rejected.
- UID000335 source ownership:
  - Checked every caller, full helper body, return-this convention, ATL implementation, and target inlining of equivalent null-BSTR construction.
  - Resolution: compiler/template output, not a handwritten project helper.
- PostData `vt=VT_ARRAY` with a VT_UI1 zero-dimensional SAFEARRAY:
  - Checked exact immediates, imports, argument order, BrowserWindow comparison, and absence of population calls.
  - Resolution: preserve the exact literal representation; original rationale or historical API quirk remains unknown but is not a code blocker.
- Exact parameter/local spelling:
  - Checked current project conventions and caller vocabulary.
  - Resolution: keep established `Navigate`, `url`, `browserUrl`, `postData`, `headers`, `targetFrameName`, and `flags`; spelling remains inferred and caps confidence below 95.
- No unresolved question blocks owner, emitter, range, metadata, or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Research tracker and generated coverage are validator-owned and must not be edited manually.
- Verified callback effect: waited command `000000008785` replaced the historical UID00033K empty marker with exactly one method body and removed the UID000335 emitted helper/marker after its non-reconstructable reclassification.

## Follow-Up Actions

- External boundary: artifact validation and lifecycle/count/path/move/archive state are supervisor/validator-owned. This report records completed B001 implementation/verification without asserting or directing those external states.
- A-agent actions: none.
- B001 remaining work: none. Compile-equivalence testing or an exact historical ATL header could improve confidence but is not required for the implemented source shape.

## Confidence

- Recommendation confidence: `94/100` for runtime behavior and ownership; `91/100` for exact ATL source wrapper spelling.
- Score confidence: high; all proposed scores remain below the 95+ final-audit threshold.
- Remaining uncertainty: original identifier spelling, exact ATL release/header revision, and why original source used the unusual empty post-data VARTYPE combination.

## Validator Results

- Scoped command shape: `python .\tools\validator.py --mode file --file <changed-by-path> --apply --queue-timeout 240`.
- Final waited command: `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240 --wait-generated`.

| Command ID | Timestamp | Scope | Exit / ok | Generated state / notes |
| --- | --- | --- | --- | --- |
| `000000008772` | `2026-07-12T20:47:30-04:00` | UID00033K target | `0 / 1` | Deferred; score `92/94`, blank -> block, three references added. |
| `000000008773` | `2026-07-12T20:48:21-04:00` | UID000013 Browser class | `0 / 1` | Deferred; score `90/93`, class block hash updated. |
| `000000008774` | `2026-07-12T20:49:02-04:00` | UID00032W host init | `0 / 1` | Deferred; score `91/93`, host block hash updated. |
| `000000008775` | `2026-07-12T20:49:34-04:00` | UID00032Y destructor | `0 / 1` | Deferred; score `91/93`, destructor block hash updated. |
| `000000008776` | `2026-07-12T20:50:52-04:00` | UID000335 ATL lowering | `0 / 1` | Deferred; owner `0000HV -> NONE`, true -> false, emitter/code removed, block -> blank. |
| `000000008777` | `2026-07-12T20:51:24-04:00` | UID000336 cleanup thunks | `0 / 1` | Deferred; score `88/91`. |
| `000000008778` | `2026-07-12T20:51:54-04:00` | UID00033I ATL throw helper | `0 / 1` | Deferred; score `88/92`. |
| `000000008779` | `2026-07-12T20:53:08-04:00` | UID0000HV Browser file | `0 / 1` | Deferred; score `89/92`; 12 pre-existing missing-reference warnings retained. |
| `000000008780` | `2026-07-12T20:53:52-04:00` | UID0000ZF aggregate | `0 / 1` | Deferred; score `92/93`. |
| `000000008785` | `2026-07-12T20:54:51-04:00` | Final UID0000HV `--wait-generated` | `0 / 1` | Completed; generated command/timestamp match. Same 12 pre-existing Browser reference warnings plus project-wide autogen notices; no target-specific failure. |

- Every changed by-* page received one scoped validator under its short lease, and every lease was released immediately after its successful validator. The final waited check was an additional authorized Browser file validation after all leases were released.
- Generated file: `auto-generated/NexusTK/browser/Browser.cpp`, SHA256 `BF1D73CE1A8A59D448EEB5E68724AAC240C6FF9D0CC9A0D8E7DA7B0269F5C389`.
- Generated header: command `000000008785`, refreshed `2026-07-12T20:54:51-04:00`, foreground generated refresh.
- Exact content/order proof: Browser class line 8; `CComQIPtr<IWebBrowser2> m_webBrowser` line 103; destructor line 113 and `m_webBrowser.Release()` line 121; exactly one UID00033K marker/method at lines 486-487; host initializer line 727 and `CComQIPtr<IOleInPlaceObject>` line 800.
- Absence/uniqueness proof: one `void Browser::Navigate(const wchar_t *url)` definition; zero UID000335 markers; zero `BrowserVariantFromString` occurrences; zero raw `IWebBrowser2 *m_webBrowser` declarations; no duplicate target body. The sole `Navigate2` token is unrelated existing `kDispIdBeforeNavigate2` event handling.
- Managed-block proof: all five destination blocks compare exactly to the accepted report blocks after newline normalization, including the intentionally blank UID000335 block.

## Changed Files

- Modified report: `tools/leaser/Agents/Agent-B001/research/00033K-BrowserNavigate-source-quality.md`.
- Modified target: `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`.
- Modified support: `by-class/Browser.md`.
- Modified support: `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`.
- Modified support: `by-memory/0x0046f480-0x0046f53e.BrowserNonDeletingDestructor.md`.
- Modified support: `by-memory/0x00470170-0x004701c9.BrowserVariantFromString.md`.
- Modified support: `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md`.
- Modified support: `by-memory/0x00470960-0x0047097c.CAtlExceptionThrowHelper.md`.
- Modified support: `by-file/Browser.md`.
- Modified support: `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`.
- Renamed: none.
- No-edit checked support: UID000331, UID0000Z3, UID00001B, UID00001A, and UID0003OH.
- Validator-generated side effects were tool-owned updates to validator registry/projected stats/generated artifacts; B001 made no manual generated/coverage/tracker/supervisor edit.
- B001 ran no report lifecycle, `execute_report`, move, or archive command. External report path/count/lifecycle state is not asserted.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 acceptance recorded for exact pre-callback report SHA `C5A1866DFBB4C502BBC367EF2CC976E9601899F95A247F1BFDB39C2B76CD750C`.
- [x] Target/support docs updated: UID00033K, UID000013, UID00032W, UID00032Y, UID000335, UID000336, UID00033I, UID0000HV, and UID0000ZF; checked/no-edit UID000331, UID0000Z3, UID00001B, UID00001A, and UID0003OH preserved.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger contains C33K-001 through C33K-032 with exact destinations/actions.
- [x] All score changes listed in `Score And Metadata Recommendation` applied and validator-confirmed.
- [x] Score-limiting interface, call-slot, variant, SAFEARRAY, BSTR, HRESULT, EH, ownership, and helper blockers researched to resolution or explicit confidence cap.
- [x] Owner/emitter/reconstructable changes applied: UID00033K route retained; UID000335 -> NONE/false/no emitter; all other routes retained.
- [x] Split/rename/new-child decision: no target split, rename, or new UID; UID000335 reclassification only.
- [x] Source placement/range/padding/reclassification resolved.
- [x] Exactly five formal managed blocks applied; no other C++ body/declaration/sample introduced.
- [x] Third-party import directive confirmed not applicable.
- [x] All C33K claims incorporated at report-level detail in target/support docs.
- [x] Historical BrowserWindow correction, old interface caveat as superseded history, unusual postData evidence, rejected alternatives, and all negative evidence preserved.
- [x] Wave2/Wave3 artifacts ignored as stale evidence.
- [x] Open questions resolved or capped with explicit score/C++ impact.
- [x] One scoped validator run per changed by-* page after callback acceptance.
- [x] Final authorized `--wait-generated` verification completed; no manual generated/coverage/tracker/supervisor edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact Gate 1 SHA.
- [x] Exact current paths/blocks re-read before each lease/edit.
- [x] Short one-file leases used and released immediately after each scoped validator.
- [x] C33K-001 through C33K-032 applied without compression.
- [x] Exactly five managed blocks applied with complete destination shape.
- [x] UID000335 no-source reclassification applied and stale free-helper inventory removed without losing binary evidence.
- [x] All score/metadata/owner/emitter/reconstructable changes applied; no exclusion required.
- [x] Valid prior research, historical provenance, rejected alternatives, and negative evidence preserved.
- [x] Ledger updated with applied proof and current real paths/UIDs.
- [x] Every scoped validator command, command ID, timestamp, exit, ok count, warnings, and generated-refresh state recorded.
- [x] Waited Browser.cpp content/order and absence of duplicate/empty target-family output verified.
- [x] Validator Results, Changed Files, current-state wording, and both checklist phases updated claim by claim.
- [x] No manual generated/coverage/tracker/supervisor edit and no lifecycle/execute/move/archive command by B001.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000008814","destination_path":"executed-b-agent-research/B001/00033K-BrowserNavigate-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00033K-BrowserNavigate-source-quality.md","timestamp":"2026-07-12T21:13:21-04:00","uid":"00033K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
