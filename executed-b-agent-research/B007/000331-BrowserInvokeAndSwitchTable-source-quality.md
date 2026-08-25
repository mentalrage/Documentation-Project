** TARGET-REPORT-UID:000331 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000331 Browser Invoke And Switch Table Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation result: [UID:000331] remains the exact `Browser::Invoke` by-memory child under [UID:000013] `Browser`, emitted through [UID:000013] to [UID:0000HV] `Browser`; the current MCP-backed event map, field-offset conversion, switch-table bytes, inferred helper/name decisions, and first-draft C++ body have been incorporated.
- Final disposition: source-authored Browser `IDispatch::Invoke` body plus compiler-generated switch support bytes; no split or table child is needed.
- Required action: completed in this callback. The target page and support enum/class notes were updated, target score was raised from `85/88` to `88/90`, and the draft body was placed under the target page's formal `RECONSTRUCTION_CPP CODE` block.
- Confidence: high for owner/emitter/range/table disposition and event side effects; medium for exact original symbolic names, but high enough for a source-facing first draft because the chosen names are conventional Browser/WebBrowser-event names and preserve the binary behavior without raw IDA labels.

## Target

- Target UID: `000331`.
- Target path: `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`.
- Source queue/report row before callback: `auto-generated/-ag-research-tracker.md` row was `Not-Covered Files - Reconstructable`, `85/88`, reports `0`; validator command `000000004499` refreshed generated Browser output after implementation.
- Current supervisor classification: implementation callback complete for Browser `Invoke`, switch/table bytes, owner/emitter route, event id/type names, field names, switch-table reconstruction, first-draft C++ readiness, and child/split/table treatment.
- Current scores and parent state after callback: target `88/90`, owner [UID:000013] `Browser` `88/90`, file root [UID:0000HV] `Browser` `87/89`. Current metadata is `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`, formal C++ populated.

## Current Target State

- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, owner/emitter [UID:000013], reconstructable true, blank `RECONSTRUCTION_CPP CODE`, `Nested:6`.
- Existing owner/emitter/reconstructable state: correct. Current MCP confirms the function pointer at Browser IDispatch vtable slot `0x006138b4` contains `0x0046f810`; [UID:000013] owns the IDispatch/DWebBrowserEvents2 view and emits through [UID:0000HV].
- Existing C++/emitter state: generated `auto-generated/NexusTK/browser/Browser.cpp` at validator command `000000004361`, refreshed `2026-07-02T06:32:49-04:00`, still shows `UID:000331` as an `Empty Emitter Marker`.
- Existing blockers: final enum spelling, exact source helper/accessor names for `DISPPARAMS` reversed event arguments, `browser::Notification` constructor/posting source shape, and whether to represent the switch support bytes as raw data. The table/split blocker is resolved here; the helper/name blockers are resolved to source-facing inferred names with confidence notes; the first-draft C++ blocker is resolved by supplying a draft body for supervisor insertion.
- Related target/support docs checked: [UID:000013] `Browser`, [UID:0000HV] `Browser` file, [UID:0001SJ] `BrowserDispatchEventId`, [UID:0000ZF] Browser OLE aggregate, [UID:00033K] `BrowserNavigate`, [UID:000014] `browser::Notification`, [UID:00001A] `BrowserThread`, [UID:00033L] `PostBrowserNotification`.

## Executive Recommendation

Keep the target attached to [UID:000013] `Browser`; no owner/emitter change is needed. The target is not a broad aggregate despite the table bytes: MCP `lookup_funcs` reports the modeled function at `0x0046f810-0x0046fab6`, `0x0046fab6-0x0046fb80` contains switch-support bytes and `0xcc` fill, and the next source method starts at `0x0046fb80`. The support bytes are compiler output from a source `switch (dispidMember)`, not a source-authored static table. Do not create a separate table child unless later tooling requires a documentation-only table page; current evidence supports keeping the bytes inside this exact by-memory page.

Recommended target score after incorporation is `88/90`: completion improves because the table layout, vtable route, current MCP session, event ids, field-offset conversion, string/notification helpers, and first-draft C++ are now specific; confidence improves because MCP reconfirms the boundaries and rejects split/raw-table alternatives. Do not exceed `90` because final event constant names and exact helper/source spelling remain inferred rather than original-proven.

## Supervisor Active Recheck

The active assignment is `B007-report-000331-BrowserInvokeAndSwitchTable-20260702`. It required report-only research, not implementation. Split repair was in scope only if the `Invoke` body/table range proved mixed in a way that required children. Current evidence shows no split is required: the switch table is function-local compiler data, and `0x0046fb80` begins the next Browser DocHost/ShowUI stub function.

## Inference Research Guidance Check

`by-structure.md` requires exact evidence for ownership/emitter and source-quality names, and it treats generated output as lead material only. Existing docs were used as leads and then rechecked against current MCP session `supervisor_resume_20260629`. No Wave2/Wave3 source claims were used as authority. The generated `Browser.cpp` empty marker was used only as read-only emitter-state evidence.

## Heuristic / Inference Reanalysis And Validation

- Owner/source placement: confirmed as `Browser::Invoke` on the adjusted `IDispatch` view. The machine `Block`/`this` in decompile is `Browser base + 8`; raw field offsets inside this function must be converted back to Browser base offsets by adding 8.
- Field names: keep `m_allowedUrlPrefix` at base `+0x20`, `m_showBrowserAfterLoad` at base `+0x222`, `m_pendingDownloadCount` at base `+0x224`, `m_navigationBuffer` at base `+0x228`, and `m_currentUrl` at base `+0x230`. MCP disassembly uses adjusted offsets `+0x18`, `+0x21a`, `+0x21c`, and `+0x228`, which correspond to those Browser-base fields.
- Event ids: use source-facing constants `kDispIdDownloadComplete`, `kDispIdDownloadBegin`, `kDispIdBeforeNavigate2`, `kDispIdNavigateComplete2`, `kDispIdNewWindow2`, and `kDispIdWindowClosing` in the draft. The `2` suffix is strongest for `BeforeNavigate2`, `NavigateComplete2`, and `NewWindow2` because the code reads DWebBrowserEvents2-style reversed arguments. For `DownloadBegin`, `DownloadComplete`, and `WindowClosing`, the Microsoft event names do not need an extra suffix in normal source spelling. Confidence is medium-high, not original-proof.
- Switch/table treatment: resolve as compiler-generated switch support. Direct bytes show `0x0046fab6` has `66 90` alignment, `0x0046fab8` has seven 32-bit target addresses, `0x0046fad4` has a 167-byte selector table for `dispid - 104`, and the range ends with `0xcc` fill before `0x0046fb80`.
- Rejected raw table emission: the table has no independent xrefs except the `Invoke` switch instructions at `0x0046f84c` and `0x0046f845`, so reconstructing it as source data would be decompiler-shaped and behaviorally wrong. The compiler should regenerate it from the source switch.
- First-draft C++ readiness: ready for draft formal body insertion. Current MCP decompilation and disassembly prove the reversed-argument accesses: case `250` loads the URL through `params->rgvarg[5].pvarVal->bstrVal`-equivalent storage (`[rgvarg + 0x58]` then `+8`), and cancel writes use `params->rgvarg[0].pboolVal`. The best source-facing spelling is the standard OLE macro form `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))` and `V_BOOLREF(&params->rgvarg[0])`, which avoids raw pointer arithmetic and matches DWebBrowserEvents2 byref `VARIANT` URL arguments.

## Evidence Standards Used

Evidence used: current IDA MCP `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, `get_int`, `get_string`; current target/support docs; generated Browser output read-only state; generated tracker and stats rows; prior B reports searched with UID/address/name/source-family terms. Numeric conversions were checked with `tools/int_convert.py` where decimal values are named.

## Helper / Name Blocker Reanalysis

The previous report named helper/source-shape blockers but left them open. Current rework checked the target page, [UID:000013] `Browser`, [UID:0000HV] `Browser`, [UID:0001SJ] `BrowserDispatchEventId`, [UID:000014] `browser::Notification`, [UID:00033L] `PostBrowserNotification`, generated `auto-generated/NexusTK/browser/Browser.cpp`, current MCP `decompile`/`disasm` for `0x0046f810`, and current MCP decompile for `0x00470f20`, `0x00582d20`, `0x00584540`, and `0x004aa1d0`.

| Blocker | Best source-facing decision | Confidence | Positive evidence | Rejected alternatives |
| --- | --- | --- | --- | --- |
| Event constants | Use `kDispIdDownloadComplete = 104`, `kDispIdDownloadBegin = 106`, `kDispIdBeforeNavigate2 = 250`, `kDispIdNavigateComplete2 = 251`, `kDispIdNewWindow2 = 263`, `kDispIdWindowClosing = 270`, plus `DISP_E_MEMBERNOTFOUND`. | Medium-high | [UID:0001SJ] already groups these as browser COM/WebBrowser DISPIDs; current MCP switch cases and DWebBrowserEvents2 `IDispatch` view match the Microsoft event family. | Do not use raw numeric cases only; do not claim original-proof enum spelling; do not use stale BrowserWindow-only names because [UID:000331] is Browser-owned. |
| `DISPPARAMS` URL accessor | Use `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))` in the draft, documented as equivalent to the reversed `params->rgvarg[5]` byref URL `VARIANT`. | High | MCP decompile loads case `250` URL through `a6`/`params`, raw disasm reads `arg_14`, `[edi]`, `[eax+0x58]`, then `[eax+8]`; `0x58` is the `pvarVal` field of the sixth reversed `VARIANTARG`, and `+8` reads that referenced variant's BSTR field. | Do not write raw `*(_DWORD *)(*(_DWORD *)params + 88)` in source; the index mapping is inferred from binary and DWebBrowserEvents2 argument order. |
| `DISPPARAMS` cancel accessor | Use `V_BOOLREF(&params->rgvarg[0])` for the first reversed argument's `VARIANT_BOOL *`, then assign `(VARIANT_BOOL)1` or `(VARIANT_BOOL)0` to match the binary's 16-bit writes. | High | MCP writes `**(_WORD **)(*(_DWORD *)a6 + 8)` in cases `250`, `251`/`270`, and `263`; in COM `VARIANTARG` layout this is `params->rgvarg[0].pboolVal`. | Do not model it as a plain `bool *` or `BOOL *`; the binary writes 16-bit `VARIANT_BOOL` values and uses `1`, not `-1`. |
| Notification construction/posting | Use `new browser::Notification(state, text)` for local construction plus `PostApplicationNotification(kBrowserNotificationChannel, notification)` / `PostBrowserNotification(1, text)` as inferred source-facing names. | Medium | [UID:000014] and [UID:00033L] document 12-byte allocation, `LObject` base construction, vtable install, string payload construction at `+0x08`, state at `+0x04`, and channel `0x42726f73` (`Bros`) through `0x004aa1d0`. | Do not expose `sub_4F4AA0`, `sub_4F4A80`, vtable stores, or raw `sub_4AA1D0` in the draft; do not claim final dispatcher spelling because [UID:000014] still marks it inferred. |
| Wide string wrapper methods | Use `m_currentUrl.assign(...)` and `m_currentUrl.c_str()` as source-facing draft shape; document them as project wide-string wrapper calls backed by `0x00582d20` assignment and `0x00584540` pointer extraction. | Medium | MCP `sub_582D20` clears/reserves and `memmove`s UTF-16 text; MCP `sub_584540` returns the backing pointer; Browser class already names `m_currentUrl` as a project wide-string object. | Do not force the final type name beyond existing `WideString` placeholder; do not use raw helper labels in emitted source. |
| Resource/localized text helper | Use `LanguageMan::GetString(235)` or equivalent source-facing note for the resource text loaded by `sub_4F0350(dword_67A750, 235)`. | Medium | Case `250` `res:` branch calls the same localized string lookup pattern before assigning `m_currentUrl`; adjacent browser docs already use localized-resource interpretations. | Do not hard-code the returned localized string because the binary performs a lookup; do not leave `sub_4F0350` in draft code. |

The chosen names are not claimed as original symbols. They are the most plausible source-facing names now available, they match neighboring Browser documentation, and they avoid the previous report's decompiler-shaped blank-C++ outcome.

## Evidence Checked

- IDA MCP session: `supervisor_resume_20260629`, server health ok, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: `0x0046f810` -> `sub_46F810`, size `0x2a6`, so body ends at `0x0046fab6`; `0x0046fab6` is not a function; `0x0046fb80` -> `sub_46FB80`; `0x00470dd0` -> `sub_470DD0`; `0x00470f20` -> `sub_470F20`.
- `decompile 0x0046f810`: switch on dispatch id with cases `104`, `106`, `250`, `251`, `263`, `270`, default `0x80020003`; calls `PostThreadMessageA`, `sub_470DD0`, `sub_470F20`, `_wcsstr`, `ShowCursor`, `ShowWindow`, `UpdateWindow`, string helper `0x582D20`, and notification allocation helpers.
- `disasm 0x0046f810`: switch bias is `dispid - 0x68`; `cmp eax,0xa6` confirms a 167-entry selector span; jump table at `0x0046fab8`; selector table at `0x0046fad4`.
- `xrefs_to`: `0x0046f810` has one data xref from `0x006138b4`; `0x0046fab8` is referenced only by `0x0046f84c`; `0x0046fad4` only by `0x0046f845`; `0x0046fb80` has a data xref from `0x006138dc`.
- `get_int`: `0x006138b4` reads as decimal `4651024` / `0x0046f810`; `0x006138dc` reads as decimal `4651904` / `0x0046fb80`; `0x0046fab8` reads as decimal `4651436` / `0x0046f9ac`.
- `get_bytes`: `0x0046fab8` bytes are seven little-endian branch targets: `0x0046f9ac`, `0x0046f980`, `0x0046f853`, `0x0046f952`, `0x0046fa63`, `0x0046f95b`, `0x0046fa9e`. `0x0046fad4` has 167 selector bytes ending with selectors for `250`, `251`, `263`, and `270`, then `0xcc` fill before `0x0046fb80`.
- String bytes: `0x0061391c` decodes to UTF-16 `close()`, followed by `about:blank`; `0x00613944` begins UTF-16 `res:`. MCP `get_string` truncated `0x0061392c` and `0x00613944` to `a` and `re`, so the raw byte check is the stronger evidence for the full adjacent literals.
- Conversions: `0x500` is decimal `1280`, `0x42726f73` is decimal `1114795891`, `0xeb` is decimal `235`, `0xfa` is decimal `250`, `0xfb` is decimal `251`, `0x107` is decimal `263`, `0x10e` is decimal `270`, and `0x80020003` is decimal `2147614723` (Verified with `tools/int_convert.py`).
- Report search terms: `000331`, `0x0046f810`, `0046f810`, `BrowserInvokeAndSwitchTable`, `Browser::Invoke`, `sub_46F810`, `46F810`. Relevant matches were B007 `000013-Browser-class-source-quality.md`, B001 `0000ZF-BrowserOleLegacyAndHelpers.md`, B004 `000330-BrowserComStubMethods-source-quality.md`, B006 `000332-BrowserDocHostShowUiStubs-source-quality.md`, B013 `0000Z3-BrowserDialogOldCore-source-quality.md`, and B002 Browser empty-emitter family report. No executed report dedicated to `000331` was found.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B007-331-001 | [UID:000331] remains `Browser::Invoke` owned/emitted by [UID:000013] `Browser`; no owner/emitter change. | High | vtable slot `0x006138b4 -> 0x0046f810`, Browser class docs, function boundary. | Target metadata and Scope/IDA Evidence; [UID:000013] active methods. | already-present | applied: target metadata kept `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`; Browser class support updated. |
| B007-331-002 | The half-open range is correct: function `0x0046f810-0x0046fab6`, switch-support bytes/fill through `0x0046fb80`, next function at `0x0046fb80`. | High | `lookup_funcs`, `xrefs_to`, `get_bytes`, DocHost stub support report. | Target Scope, Reconstruction Notes, 2026-07-02 implementation section. | incorporate | applied to target implementation section; no split or range change. |
| B007-331-003 | Switch table should be regenerated from source `switch`, not emitted as raw data or split into a source-authored table child. | High | xrefs only from `0x0046f84c`/`0x0046f845`, selector/jump-table bytes. | Target Reconstruction Notes, implementation section, and Score Rationale. | incorporate | applied; raw table emission and table child rejected. |
| B007-331-004 | `Browser::Invoke` uses adjusted `IDispatch` this pointer (`Browser + 8`), so raw decompile offsets must be converted to Browser-base offsets. | High | `lea ecx,[ecx-8]` before `Browser::Navigate`, Browser class layout. | Target field/layout notes; Browser class field-layout caveat. | incorporate | applied to target; Browser class already had the field caveat and now links the formal `Invoke` source route. |
| B007-331-005 | Cases `104`, `106`, `250`, `251`, `263`, `270` and default `DISP_E_MEMBERNOTFOUND` are current MCP-backed behavior facts. | High | `decompile`, `disasm`, selector bytes. | Target implementation section and [UID:0001SJ] event enum notes. | incorporate | applied to target case map; dispatch enum support updated for accepted `*2` names. |
| B007-331-006 | Event constants should use inferred Browser/WebBrowser source-facing names: `kDispIdDownloadComplete`, `kDispIdDownloadBegin`, `kDispIdBeforeNavigate2`, `kDispIdNavigateComplete2`, `kDispIdNewWindow2`, and `kDispIdWindowClosing`; keep a caveat that exact original spelling is not proven. | Medium-high | [UID:0001SJ] event family, current MCP switch, DWebBrowserEvents2 `IDispatch` route. | Target C++ and implementation section; [UID:0001SJ] Values/Changes. | incorporate | applied to target formal C++ and enum support; original-name caveat preserved. |
| B007-331-007 | Formal C++ should no longer remain blank; insert the accepted draft `Browser::Invoke` body from this report under the target's formal `RECONSTRUCTION_CPP CODE` block. | Medium | Current MCP behavior, helper/name reanalysis, Browser class declaration, notification/source helper docs. | Target `RECONSTRUCTION_CPP CODE` and C++/Score Rationale. | incorporate | applied; generated Browser output now emits UID000331 source at validator command `000000004499`. |
| B007-331-008 | Recommended score after incorporation is `88/90`. | Medium-high | Resolved table/split, current MCP proof, helper/name decisions, and first-draft C++ body; exact original symbols remain inferred. | Target metadata and Score Rationale. | incorporate | applied; validator command `000000004499` recorded `completion_update 000331 ... 88` and `confidence_update 000331 ... 90`. |
| B007-331-009 | `DISPPARAMS` reversed argument access should be documented as `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))` for URL and `V_BOOLREF(&params->rgvarg[0])` for cancel pointer, with exact raw mapping to `rgvarg[5]` and `rgvarg[0]`. | High | Current MCP decompile/disasm for `arg_14` / `a6`, offsets `0x58` and referenced-variant `+8`, 16-bit cancel writes. | Target helper/name notes and C++ block; Browser class note. | incorporate | applied to target formal C++ and Browser class support. |
| B007-331-010 | Notification posting should use inferred source names around `browser::Notification`, `PostBrowserNotification`, `kBrowserNotificationChannel`, and `PostApplicationNotification`; raw allocation/vtable/helper labels are evidence only. | Medium | [UID:000014], [UID:00033L], MCP decompile of `0x00470f20`, inline construction in case `104`. | Target C++ notes; [UID:000014]/[UID:00033L] support. | incorporate | applied to target; [UID:000014]/[UID:00033L] already had same-or-greater notification/channel/helper detail, so not duplicated. |
| B007-331-011 | Project wide-string wrapper usage in the draft should read as `m_currentUrl.assign(...)` and `m_currentUrl.c_str()`, backed by `0x00582d20` assignment and `0x00584540` pointer extraction; final type spelling remains open. | Medium | MCP decompile of `0x00582d20` and `0x00584540`, Browser class `m_currentUrl` docs. | Target C++ notes; [UID:000013] field caveat. | incorporate | applied to target formal C++ and Browser class support; final wrapper type/method caveat preserved. |

## Positive Evidence Summary

- Direct facts: function start `0x0046f810`, modeled function size `0x2a6`, Browser IDispatch vtable slot points to the function, cases and switch table are visible in decompile/disassembly, and the next function starts exactly at `0x0046fb80`.
- Documentation evidence: [UID:000013], [UID:0000HV], [UID:0001SJ], [UID:0000ZF], [UID:00033K], and [UID:00033L] all support Browser class/file ownership and the same browser event family.
- Strongest inference: the original source was a normal COM `IDispatch::Invoke` switch over WebBrowser/DWebBrowserEvents dispatch ids. The compiler emitted the jump/selector tables and padding; source reconstruction should express the switch and side effects, not raw bytes.

## IDA MCP Facts

- Function/range facts: `sub_46F810` is `0x0046f810-0x0046fab6`; `0x0046fab6` is not a function; `sub_46FB80` begins at `0x0046fb80`.
- Data/table/padding facts: `0x0046fab6` begins with `66 90`; `0x0046fab8` is a seven-entry jump-address table; `0x0046fad4` is a 167-byte selector table for dispatch ids `104` through `270`; `0xcc` padding follows before `0x0046fb80`.
- Xref facts: only table xrefs are internal switch references; `0x0046f810` is referenced by Browser vtable data at `0x006138b4`; `0x0046fb80` is referenced by Browser DocHost/ShowUI vtable data at `0x006138dc`.
- String facts: `close()`, `about:blank`, and `res:` are adjacent UTF-16 literals used by the navigation-case checks and fallback navigation.
- Negative IDA facts: no independent code/data owner references the switch table; no function starts at the table; no evidence supports assigning this target to BrowserWindow, BrowserThread, BrowserControlPaneOld, or a new table/global owner.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f810-0x0046fab6` | [UID:000331] target | `Browser::Invoke` source method body | True | [UID:000013] `Browser` | implemented `88/90` | Keep exact child. |
| `0x0046fab6-0x0046fb80` | [UID:000331] target tail | compiler switch support bytes and fill | Generated from method source | [UID:000013] via target | included in target | Keep with target, no raw-table child. |
| `0x0046fb80-0x0046fca5` | [UID:000332] | next Browser DocHost/ShowUI stubs | True | [UID:000013] `Browser` | `88/91` | Separate next child, not part of this target. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006138b4 -> 0x0046f810` | Browser IDispatch vtable slot | Confirms COM event-sink method route. |
| `0x0046f84c -> 0x0046fab8` | switch jump table use | Table is local compiler support. |
| `0x0046f845 -> 0x0046fad4` | selector table use | Selector table is local compiler support. |
| `0x0046f892 -> 0x00470dd0` | case `250` calls `Browser::Navigate` after `lea ecx,[ecx-8]` | Confirms adjusted IDispatch pointer and Browser ownership. |
| `0x0046fa81 -> 0x00470f20` | case `263` calls `PostBrowserNotification(1, currentUrl)` | Confirms browser notification route. |
| `0x0046fa3f -> 0x004aa1d0` | case `104` posts inline `browser::Notification` on channel `0x42726f73` | Confirms inline completion notification. |

## Documentation Evidence And IDA Status

Implementation callback result: the target now records current session provenance, exact table byte/xref proof, explicit no-split/no-raw-table rationale, the first-draft formal C++ body, and updated `88/90` score rationale. Validator command `000000004499` refreshed generated Browser output and replaced the prior UID000331 empty marker with emitted `Browser::Invoke` source.

## Ranked Ownership Analysis

### 1. [UID:000013] Browser

- Evidence for: Browser IDispatch vtable slot points to `0x0046f810`; `QueryInterface` exposes `IDispatch`/`DWebBrowserEvents2` as `this + 8`; case `250` subtracts 8 before calling `Browser::Navigate`; body reads Browser fields and Browser globals; class/file docs already clear the ownership gate.
- Evidence against: none material. Final source file split (`Browser.cpp` versus possible `BrowserLegacy.cpp`) remains broader file-level uncertainty, not a direct-owner blocker.
- Decision: keep as canonical owner and direct emitter.

### 2. [UID:0000HV] Browser file root

- Evidence for: Browser file root owns the browser COM/OLE source module and routes [UID:000013] output to `NexusTK/browser/`.
- Evidence against: file root is broader than the direct class method owner.
- Decision: emitter route remains Browser class -> Browser file root; do not make the file root the direct owner.

### 3. BrowserThread / BrowserControlPaneOld / BrowserWindow / standalone table owner

- Evidence for: BrowserThread receives private messages, BrowserControlPaneOld creates/uses Browser, BrowserWindow has related WebBrowser event handlers, and the target contains table bytes.
- Evidence against: none owns this vtable slot or adjusted `this` state; BrowserWindow has separate navigation/event code; BrowserThread is a consumer of posted messages; table bytes are only referenced by the `Invoke` switch.
- Decision: reject as direct owners.

## Source Placement

Recommended placement remains the legacy Browser COM client/event-sink class under the Browser source root. The method body belongs to `Browser::Invoke(...)`; event id constants belong with browser COM event declarations ([UID:0001SJ]); private message `0x500` belongs with Browser message constants ([UID:0001SL]); notification payload behavior belongs with [UID:000014]/[UID:00033L]. A future `BrowserLegacy.cpp` split remains plausible but unproven and should not change current emitter routing.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: function body `0x0046f810-0x0046fab6`; local switch bytes `0x0046fab6-0x0046fb7b`; `0xcc` fill through `0x0046fb80`; next function `0x0046fb80`.
- Children/subranges: no new child. The table is not source-authored data and has no independent owner.
- Padding/table/data/code distinction: table bytes are compiler-generated from the switch. They are rebuild-relevant only as proof of source switch shape and dispatch ids, not as raw source data.
- Parent/container impact: [UID:0000ZF] remains the non-emitting aggregate; [UID:000332] remains separate.

## Negative Evidence Summary

- No xrefs to `0x0046fab8` or `0x0046fad4` except the two switch instructions inside `sub_46F810`.
- No function starts at `0x0046fab6` or inside the table range.
- No support doc shows final original symbolic names for every event constant used by this legacy Browser sink.
- No current evidence supports raw table emission, standalone table ownership, or BrowserWindow ownership for the `0x00470dd0` call.

## IDA Rename / Type / Comment Recommendations

- Source-facing name: `Browser::Invoke`.
- Event constant names: use descriptive constants such as `kDispIdDownloadComplete`, `kDispIdDownloadBegin`, `kDispIdBeforeNavigate2`, `kDispIdNavigateComplete2`, `kDispIdNewWindow2`, and `kDispIdWindowClosing` as inferred/high-probability names. Preserve "style event" wording where original spelling is not proven.
- Field names: retain `m_allowedUrlPrefix`, `m_showBrowserAfterLoad`, `m_pendingDownloadCount`, `m_navigationBuffer`, and `m_currentUrl`.
- IDA DB edits: not requested in this report-only assignment.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. [UID:000331] is reconstructable, owner/emitter route is confirmed, average score clears the current C++ gate, the method behavior and range are understood, and the remaining names can be handled as explicitly inferred source-facing names rather than raw IDA labels.
- Recommended code: insert the following as the target's formal `RECONSTRUCTION_CPP CODE` if the supervisor accepts this report. It is draft-quality because the exact project wide-string type and event constant spelling remain inferred, but it is intentionally human-written Browser COM source style and preserves the observed behavior.

```cpp
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
            m_currentUrl.assign(LanguageMan::GetString(235));
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
```

- Draft helper assumptions:
  - `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))` is the source-facing expression for `params->rgvarg[5].pvarVal->bstrVal` / sixth reversed argument URL access observed at `0x0046f85b-0x0046f860`.
  - `V_BOOLREF(&params->rgvarg[0])` is the source-facing expression for `params->rgvarg[0].pboolVal`, observed at `0x0046f897-0x0046f8a1`, `0x0046f930-0x0046f93a`, `0x0046f95b-0x0046f968`, and `0x0046fa63-0x0046fa6d`.
  - `kBrowserThreadCloseMessage` is the source-facing private message for `0x500`.
  - `kBrowserNotificationChannel` is the source-facing name for channel `0x42726f73` (`Bros`).
  - `PostApplicationNotification` is the best current source-facing name for `0x004aa1d0`; [UID:000014] keeps exact spelling inferred.
- Rejected no-code branch: leaving formal C++ blank is no longer justified. The current evidence routes attempted all named blockers and produces stable, conventional names with documented confidence and exact raw mappings. A blank block would now hide usable reconstruction work rather than prevent misleading source.
- Third-party import: not applicable.

## Final Recommendation

- Updated [UID:000331] target docs with current MCP session, exact switch/table bytes, xref facts, event case map, adjusted-field conversion, no-split/no-raw-table conclusion, helper/name inference, and first-draft C++.
- Raised score to `88/90`.
- Kept `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`, and blank `EMITTER_POSITION_OPTIONAL`; populated formal C++ with the draft body.
- Updated [UID:0001SJ] to preserve source-facing DWebBrowserEvents2 names while keeping the exact-original-spelling caveat.
- No manual coverage-report or tracker edit was made by B007. Generated tracker/coverage refreshed through validator command `000000004499`.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`.
- Incorporate current MCP session evidence, including session id, function boundary, vtable slot, switch xrefs, table byte layout, string byte facts, and generated empty marker state.
- Add an explicit "Switch Table Disposition" paragraph: table bytes are compiler-generated from `switch (dispidMember)` and should stay inside the page for evidence only; do not emit raw table data or split a table child.
- Added/refreshed first-draft C++ evidence and inserted the draft body under formal `RECONSTRUCTION_CPP CODE`.
- Add helper/name notes for `V_BSTR(V_VARIANTREF(&params->rgvarg[5]))`, `V_BOOLREF(&params->rgvarg[0])`, notification posting, `m_currentUrl.assign`, `m_currentUrl.c_str`, `kBrowserThreadCloseMessage`, and `kBrowserNotificationChannel`, with exact raw evidence and inferred-name caveats.
- Metadata: `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable unchanged.

## Recommended Support Doc Changes

- [UID:0001SJ] `by-type/by-enum/BrowserDispatchEventId.md`: add one short note that current `Browser::Invoke` MCP recheck confirms the legacy-only `106` pending-count increment, `104` pending-count completion/visibility notification, and the table selector span `104..270`; preserve final-name caveat.
- [UID:0001SL] `by-type/by-enum/BrowserMessageId.md`: confirm or add the source-facing close/private thread message name used by the draft for message `0x500` / decimal `1280` (Verified with `tools/int_convert.py`).
- [UID:000014] `by-class/browser__Notification.md` and [UID:00033L] `PostBrowserNotification`: preserve that UID000331 constructs/posts the value `0` notification inline in case `104`, while case `263` uses `PostBrowserNotification(1, m_currentUrl.c_str())`; synchronize accepted source-facing names for `browser::Notification(0, NULL)`, `PostApplicationNotification`, and `kBrowserNotificationChannel`.
- [UID:000013] `by-class/Browser.md`: updated with a short cross-reference that UID000331 now has draft `Browser::Invoke` C++ using standard `V_VARIANTREF`/`V_BSTR` and `V_BOOLREF` dispatch-argument access plus inferred constant/helper names, while exact original spelling remains caveated.
- [UID:0000HV] `by-file/Browser.md`: not touched during implementation because B009 held an active lease; existing source-root route already covers Browser ownership, and generated Browser output now carries the UID000331 emitted body from validator command `000000004499`.

## Score And Metadata Recommendation

- Implemented score/metadata: `88/90`, owner [UID:000013], reconstructable true, emitter [UID:000013], formal C++ populated with the accepted draft body.
- Previous score/metadata before callback: `85/88`, owner/emitter/reconstructable already correct, C++ blank.
- Score rationale and reason not higher: the report resolves table/split/raw-emission, strengthens current MCP proof, resolves named helper/source-shape blockers to documented inferred names, and supplies first-draft C++. Completion remains below `90` because exact original event/helper/string-wrapper spellings remain inferred. Confidence reaches `90` because range, owner, table, and behavior are directly verified; it should not exceed `90` until final C++/source names are audited.
- Score-improvement attempts: table split investigated and rejected; owner/emitter investigated and confirmed; event constants investigated through support docs and MCP and converted to best inferred constants; field names revalidated through adjusted offset conversion; C++ readiness investigated and resolved with a formal draft.
- Metadata fields changed: only `COMPLETION` and `CONFIDENCE`; owner/emitter/reconstructable unchanged.

## Open Questions With Attempted Resolution

- Exact original event constant names: unresolved as original-proof, but no longer blocking. Checked [UID:0001SJ] and current MCP; numeric ids and behavior are strong, so use the inferred constants in the draft with a caveat.
- Exact source expression for `DISPPARAMS` access: resolved to implementation-ready standard OLE macro expressions. MCP proves URL comes from byref `rgvarg[5].pvarVal->bstrVal` and cancel writes go through `rgvarg[0].pboolVal`; target docs should preserve the raw mapping and the argument-index caveat.
- Exact notification constructor/posting names: resolved to implementation-ready inferred names using `browser::Notification`, `PostBrowserNotification`, `kBrowserNotificationChannel`, and `PostApplicationNotification`; exact dispatcher spelling remains caveated but does not block the draft.
- Exact string wrapper method names: resolved to implementation-ready inferred `m_currentUrl.assign(...)` and `m_currentUrl.c_str()` with current `WideString` type caveat.
- Switch-table split: resolved. No split or raw table child is needed.
- Browser owner/emitter route: resolved. Owner/emitter are correct and should remain unchanged.

## Follow-Up Actions

- Supervisor: review this implementation callback and, if accepted, run the supervisor-only report execution step.
- A-agent actions: none required.
- B007 callback actions: complete. Target/support docs were updated or marked already-present, scoped validators ran, generated Browser output freshness was recorded, leases were released, and B007 stops at `READY_FOR_SUPERVISOR_EXECUTE`.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original event constants and notification/string-wrapper support names; the draft formal source body is implementation-ready but still marks those names as inferred.

## Validator Results

- Implementation callback scoped file validators run from `source-3/project-documentation`; no `execute_report` command or variant was run.
- `000000004496` at `2026-07-02T13:36:17-04:00`: `python .\tools\validator.py --mode file --file by-type\by-enum\BrowserDispatchEventId.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred.
- `000000004497` at `2026-07-02T13:36:22-04:00`: `python .\tools\validator.py --mode file --file by-type\by-enum\BrowserMessageId.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred.
- `000000004498` at `2026-07-02T13:36:31-04:00`: `python .\tools\validator.py --mode file --file by-class\Browser.md --apply --queue-timeout 240`; exit `0`, `ok: 1`, generated refresh deferred.
- `000000004499` at `2026-07-02T13:36:38-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md --apply --queue-timeout 240 --wait-generated`; exit `0`, `ok: 1`, `completion_update 000331 ... 88`, `confidence_update 000331 ... 90`, generated refresh completed.
- Generated Browser freshness: `auto-generated/NexusTK/browser/Browser.cpp` now has `validator-command-id: 000000004499`, `validator-refreshed-at: 2026-07-02T13:36:38-04:00`, and emits UID000331 `Browser::Invoke` source instead of the previous empty marker.
- Unresolved validator warnings/errors for changed by-* docs: none. Broad generated refresh produced existing non-scoped warnings such as `autogen_children_marker_missing` and `autogen_emitter_has_no_code`; they are outside this callback's changed-doc validation scope.

## Changed Files

- Modified by B007:
  - `by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md`
  - `by-type/by-enum/BrowserDispatchEventId.md`
  - `by-type/by-enum/BrowserMessageId.md`
  - `by-class/Browser.md`
  - `tools/leaser/Agents/Agent-B007/research/000331-BrowserInvokeAndSwitchTable-source-quality.md`
- Support docs checked but not manually modified:
  - `by-class/browser__Notification.md`: same-or-greater notification/channel details already present.
  - `by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md`: same-or-greater helper/layout/channel details already present.
  - `by-file/Browser.md`: not edited because B009 held an active lease during the B007 edit batch; existing Browser source-root route already covers UID000331 as a Browser child, and the Browser class/target pages now carry the accepted source detail.
- Validator-owned generated refresh: command `000000004499` updated generated Browser output and generated coverage/tracker metadata. These generated files were not manually edited.
- Renamed: none.
- Report execution: not run. B007 must not run `tools/validator.py execute_report`, dry-run/apply variants, registry lifecycle commands, manual report moves, or equivalent report execution/archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation; accepted implementation callback received.
- [x] Target/support docs to update: target, dispatch enum, message enum, and Browser class updated; notification helper/class already-present; `by-file/Browser.md` not edited due active B009 lease and adequate existing route coverage.
- [x] Current target state and actual evidence checked recorded: incorporated MCP session `supervisor_resume_20260629`, server health, function/table/xref/string/generated-empty-marker facts, and report-search terms.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: B007-331-001 through B007-331-011 now marked applied/already-present with destinations.
- [x] Metadata/score changes applied: UID000331 set to `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched and recorded: table/split/raw-emission resolved; owner/emitter resolved; inferred event/helper/string names caveated; `DISPPARAMS` access resolved to standard OLE macro expressions; formal C++ inserted.
- [x] Owner/emitter/reconstructable changes: no changes; confirmed `CANONICAL_OWNER:000013`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000013`.
- [x] Split/rename/new-child changes: none; target explicitly documents no split/table child.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes: target support details applied; no IDA DB edits.
- [x] First-draft C++ applied: accepted `Browser::Invoke` body inserted into the target formal `RECONSTRUCTION_CPP CODE` block.
- [x] Third-party import directive: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: event map, field roles, vtable slot, table bytes, string bytes, adjusted `Browser::Navigate` call, notification paths, `DISPPARAMS` mappings, helper assumptions, default `DISP_E_MEMBERNOTFOUND`, and generated empty-marker state.
- [x] Historical/stale assumptions and negative evidence preserved: raw table emission, separate table child, BrowserWindow/BrowserThread/BrowserControlPaneOld ownership, and original-proof event names rejected.
- [x] Wave2/Wave3 mentions handled: generated Browser output used as read-only pre-state and post-validator freshness proof.
- [x] Open questions documented: exact original event constants, final project `DISPPARAMS` helper/accessor spelling, notification dispatcher spelling, and string-wrapper type/method spelling remain inferred and nonblocking.
- [x] Validators run after callback edits: scoped file validators `000000004496` through `000000004499`, all exit `0` with `ok: 1`.
- [x] Generated report refresh completed by validator command `000000004499`; no manual coverage/tracker text was edited by B007.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already-present/not-edited with reason.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator command `000000004499`.
- [x] Remaining unapplied accepted items listed with exact blocker: no accepted target change remains unapplied; `by-file/Browser.md` optional support sync not edited because B009 held an active lease and same route evidence is already present.

Lease state:
- Acquired B007 leases at `2026-07-02T17:34:32Z` for target, dispatch enum, message enum, and Browser class. `by-file/Browser.md` lease request was rejected because B009 already held it.
- Released B007 leases after validators; current lease report search for B007/UID000331/support paths returned no active B007 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004511","destination_path":"executed-b-agent-research/B007/000331-BrowserInvokeAndSwitchTable-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000331-BrowserInvokeAndSwitchTable-source-quality.md","timestamp":"2026-07-02T13:41:32-04:00","uid":"000331"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
