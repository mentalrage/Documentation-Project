** TARGET-REPORT-UID:0000Z4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: BrowserWindowCore


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000Z4] as the BrowserWindow core aggregate under [UID:0000HV] Browser and retain the implemented explicit formal no-code/split marker instead of an empty formal C++ block.
- Final disposition: source-authored BrowserWindow methods are present in the range, but the current by-memory page is too broad to receive a synthetic aggregate C++ body. Exact method children should carry future source bodies after the BrowserWindow class declaration, COM base layout, and field names are finalized.
- Implemented action: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md` now carries the accepted current MCP evidence, split/no-code proof, exact child split candidates, `87/91` score, and formal comment block; `by-class/BrowserWindow.md` and `by-file/Browser.md` carry the matching support policy. Scoped validation and generated-output freshness checks are complete.
- Confidence: high for BrowserWindow ownership, Browser source routing, current empty-emitter cause, and no broad aggregate C++; medium-high for exact future child names because IDA has no recovered `BrowserWindow` UDT or original method symbols.

## Supporting Research

Lifecycle/status notes: the accepted UID0000Z4 implementation callback is complete. The pre-implementation artifact passed supervisor Gate 1 at SHA256 `95EE27EA1636102563A8AE829BF034B9CA4C83A8F76D74020DAA7393A9B5B4EA`; that is historical validation context, not a claim about the report's current lifecycle state. Supervisor report validation/execution and the current archive or active-copy state are external validator-owned lifecycle facts recorded in `VALIDATOR-REPORT-HISTORY`. No prior UID0000Z4 target report exists. Prior Browser-family reports remain leads and support evidence, not substitutes for this report's MCP pass.

The key stale state was generated, not behavioral: before callback, `auto-generated/NexusTK/browser/Browser.cpp` contained `// UID:0000Z4 ... Empty Emitter Marker`. After scoped validation with generated refresh command `000000008164`, generated `Browser.cpp` carries UID0000Z4 at `87/91` followed by the accepted four-line no-code/split marker, and `auto-generated/-ag-memory-coverage.md` reports the route as coded through `Browser.cpp`.

## Target

- Target UID: `0000Z4`.
- Target path: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; at implementation verification the UID0000Z4 source row reported `87/91` and reconstructable `true`. Report execution/coverage state is external validator-owned lifecycle data and is not asserted here.
- Current supervisor classification: implementation callback complete for a reconstructable by-memory aggregate that is Browser-routed and now explicitly covered by a formal no-code/split marker.
- Current scores and parent state: target `87/91`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`; direct source root [UID:0000HV] Browser remains `87/89`; class support [UID:00001B] BrowserWindow remains `85/88`.

## Current Target State

- Pre-callback metadata: the target was `86/90`, reconstructable, owner/emitter Browser [UID:0000HV], with a formal C++ header but an empty block. Current metadata is `87/91` with owner/emitter/reconstructable unchanged and the exact accepted marker in the formal block.
- Existing owner/emitter/reconstructable state: owner/emitter route is correct for the current Browser source root. The target should not be reowned to `BrowserWindow` as a file root because [UID:00001B] is a class support page routed through Browser, and the current project still treats one broad `browser/Browser.cpp` versus a future `BrowserWindow.cpp` split as unresolved.
- Current C++/emitter state: generated `Browser.cpp` has the exact formal no-code/split marker for UID0000Z4 at validator command `000000008164`. The target is eligible by score and emitter route, but the aggregate emits no method bodies.
- Existing open questions/blockers: final BrowserWindow header declaration, exact field names for offsets such as `+0x15`, `+0x18`, `+0x1c`, `+0x22`, `+0x24`, `+0x224`, `+0x228`, `+0x229`, `+0x22a`, and `+0x224/+0x228/+0x229` setter roles; final source spellings for constructor/shutdown/navigation/Invoke helpers; raw helper island reachability.
- Related target/support docs checked: Browser file, BrowserWindow class, BrowserWindow DocHost stubs, accelerator helper, host WndProc, release adjustor thunks, active BrowserWindow global/storage, Browser vtables/strings, Browser COM GUID constants, InlineIsEqualGUID, BrowserDispatchEventId, by-memory ignored ledger, generated Browser output, generated tracker/coverage rows, and matching executed reports.
- Current artifact/lifecycle status: implementation callback complete. Scoped validators were run for all three edited by-* docs. Supervisor report validation/execution and the current archive or active-copy state are external validator-owned lifecycle facts recorded in `VALIDATOR-REPORT-HISTORY`; this report body does not assert a pending gate, pending execution, or permanent filesystem location.
- Callback MCP availability note: the first read-only `initialize` attempt to `http://127.0.0.1:13337/mcp` on 2026-07-12 failed because the endpoint was not listening, so all new MCP-dependent investigation stopped. A read-only incident recheck at `2026-07-12T15:52:24-04:00` found listener `127.0.0.1:13337` on PID `13160` plus existing `idalib-mcp.exe`/Python launcher and worker processes; a lightweight follow-up reached HTTP 200 but the shell-serialized body produced a JSON parse error, so no new MCP evidence was accepted. The callback only incorporated the already accepted Gate 1 evidence and did not start, stop, restart, or kill any IDA/MCP/Python process.

## Executive Recommendation

The best repair is a formal no-code/split marker on UID0000Z4 plus target/support documentation updates. Do not paste constructor/destructor/QueryInterface/Invoke C++ into this broad aggregate, and do not reclassify the aggregate to non-reconstructable while the exact source-bearing child pages for the in-range BrowserWindow methods have not been created.

Recommended exact formal block content:

```cpp
// BrowserWindowCore is a split-required BrowserWindow aggregate.
// Do not emit a synthetic aggregate body here; exact BrowserWindow
// method children for this range should carry source bodies after
// the BrowserWindow COM layout and field names are finalized.
```

Do not add `[[CHILDREN]]` to UID0000Z4 now. Existing and future source-ready method children should route through [UID:00001B] BrowserWindow or [UID:0000HV] Browser, not through this aggregate as a source-code insertion parent, unless a later split pass deliberately changes the child-emitter route.

## Supervisor Active Recheck

- Historical triggering instruction: B002 was initially assigned report-only source-quality research for [UID:0000Z4] `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`; that artifact later passed Gate 1 and received this implementation callback.
- Split repair during the callback: not authorized or required. No child page was created; the accepted exact future child ranges were documented without expanding edit scope.
- Current implemented result: target and support docs contain the split/no-code proof, the empty formal target block has the accepted comment, and generated Browser output is current. Future source-bearing child creation remains a separate supervisor assignment.

## Inference Research Guidance Check

By-structure rules control this recommendation:

- `by-memory` formal C++ is limited to the page's own range and should not contain sibling/outside-range source.
- Broad aggregate pages should not receive child method bodies when exact source-level functions/methods need their own pages.
- A routed reconstructable item intentionally not emitting source bodies should not stay as a generic empty emitter; it should carry an explicit formal coverage/no-code comment.
- `RECONSTRUCTABLE:FALSE` would be premature because UID0000Z4 still documents actual BrowserWindow source-authored functions and no exact in-range children currently replace them in coverage.

Wave2/Wave3 generated names were treated only as leads. Current MCP did not recover a `BrowserWindow` UDT, `IDocHostUIHandler` type, `IDocHostShowUI` type, or `DWebBrowserEvents2` type; source-facing names are therefore documentation/SDK inference backed by behavior, vtables, GUIDs, and support docs.

## Heuristic / Inference Reanalysis And Validation

- COM/interface names: `QueryInterface` current decompile compares raw GUID storage and returns `this`, `this+4`, `this+8`, `this+0x0c`, or `this+0x10`. GUID docs and vtable slice docs support the source-facing interfaces `IUnknown`, `IOleClientSite`, `IOleWindow`/`IOleInPlaceSite`, `DIID_DWebBrowserEvents2`/`IDispatch`, `IDocHostUIHandler`, and `IDocHostShowUI`. This is validated by current xrefs to GUID addresses and by [UID:00020T] / [UID:0001OB].
- Helper names: `BrowserWindowHostWndProc`, `g_pActiveBrowserWindow`, `BrowserDispatchEventId`, `BrowserWindowTranslateAcceleratorMessage`, and DocHost method names are already resolved on exact support pages. Constructor/shutdown/navigation/Invoke method names remain descriptive because no original symbols or UDT were recovered.
- Source placement: Browser remains the best source root. BrowserWindow class is a semantic owner/support class routed through Browser; a later `BrowserWindow.cpp` split is plausible but unproven.
- Range/split decision: the range contains 30 promoted functions plus two raw helper islands and trailing switch-table bytes outside the target. This is too broad for one C++ body. Exact future method pages should split the promoted method groups; raw no-function/no-xref islands should stay aggregate-documented until a caller/table/vtable route is proven.
- Raw helper liveness: current `lookup_funcs` reports `Not a function` for `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90`, `0x00469e20`, and `0x00469ea0`; current `xrefs_to` reports zero xrefs to all seven starts. Their bytes are source-shaped and should remain documented, but they are not safe child emitters now.
- C++ readiness: exact method bodies are not yet final-output ready because the aggregate has unresolved class layout, field names, and method boundaries across multiple source concepts. UID00020T and UID00020V prove the pattern for exact child pages that can emit once boundaries and names are strong; UID0000Z4 should not duplicate those bodies.
- Rejected alternatives: broad aggregate C++ is rejected as decompiler-shaped and would mix constructor, destructor, lifecycle helpers, QueryInterface, stubs, Invoke, and no-xref raw islands. Reclassifying the target `FALSE` is rejected because it would hide source-bearing BrowserWindow code before exact in-range children exist. Creating raw helper children now is rejected because no current function objects or xrefs prove callable source entries.

## Evidence Standards Used

Evidence was prioritized as: current IDA MCP facts, exact bytes, function inventory, xrefs/callers/callees, decompilation, current by-* docs, generated output as lead material, executed reports as leads/support, and negative evidence.

The recommendation is strong enough because independent current MCP checks agree with existing support docs: the target has a real BrowserWindow constructor/lifecycle/QI/Invoke range; direct child pages already own adjacent source-ready methods; and generated output is stale only because UID0000Z4 is an empty routed aggregate. Confidence is capped because final source names/layout remain inferred and there is no recovered UDT/type metadata.

## Evidence Checked

IDA MCP/current session:

- JSON-RPC session id: `12526619-f80d-472e-8680-44bbfd0aac73`.
- IDB database: `supervisor_nexustk_20260709`.
- `server_health`: `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- Tools/schemas checked: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `xrefs_to`, `decompile`, `analyze_function`, `type_query`, `find_bytes`.
- Schema mismatch resolved: initial singular `get_bytes addr/size` and `xrefs_to addr` attempts returned missing `regions` / `addrs`; these were retried successfully with the active schema and are not evidence failures.

MCP facts used:

- `entity_query functions 0x00469640-0x0046a39c` reports exactly 30 promoted functions, from `sub_469640` size `0x3d7` through `sub_46A250` size `0x14c`.
- `lookup_funcs` confirms key starts at `0x00469640`, `0x00469a20`, `0x00469a90`, `0x00469b60`, `0x00469ca0`, `0x00469f60`, `0x0046a0b0`, `0x0046a0c0`, `0x0046a220`, and `0x0046a250`; `0x0046a39c` is not a function; successor `0x0046a3d0` is UID00020T.
- `get_bytes 0x0046a39c size 52` confirms the successor jump/selector table bytes and trailing `cc cc cc` before UID00020T.
- `get_bytes 0x00469c09 size 151` and `0x00469e17 size 329` confirm the two raw helper islands with prologue-shaped bodies and padding.
- `xrefs_to` for BrowserWindow vtable bases `0x00613200`, `0x00613228`, `0x00613268`, `0x00613288`, and `0x006132d4` confirms constructor stores and destructor/restores.
- `xrefs_to` for `0x0067ab94` confirms exactly five data refs: constructor publish/fallback-clear, destructor clear, accelerator-helper read, and cleanup clear thunk.
- `xrefs_to` for raw helper starts `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90`, `0x00469e20`, and `0x00469ea0` returns zero refs.
- `lookup_funcs` for the same seven raw helper starts returns `Not a function`.
- `type_query BrowserWindow`, `IDocHostUIHandler`, `IDocHostShowUI`, and `DWebBrowserEvents2` returns zero recovered type rows.
- `decompile 0x00469f60` confirms raw GUID compare chain and adjusted interface returns, including `this+0x0c` for `0x00631630` and `this+0x10` for `0x00631640`.
- `decompile 0x0046a250` confirms Invoke cases `250`, `251`, `252`, `259`, `263`, and `270`, URL prefix checks, cancel-pointer writes, navigation cookie/token handling, `ShowWindow`/`UpdateWindow`, and active-state helper call `sub_469B60(a1 - 8, ...)`.
- `analyze_function` confirms constructor caller `StartupWindow__RunUpdateCheck`, constructor callees `RegisterClassA`, `CreateWindowExA`, `CoCreateInstance`, `SetWindowLongA`, `sub_4708D0`, `sub_470980`, and `sub_469CA0`; navigation helper callees `VariantInit`, `SysAllocString`, `SafeArrayCreate`, `sub_470170`, `SafeArrayDestroy`, and failure `sub_469A90`.

Docs/reports/generated files read:

- `Agent-B002/goal.md`
- `Agent-B002/notes.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `references/b-agent-research-and-implementation-workflow.md`
- `references/b-agent-report-template.md`
- `references/score-blocker-audit-standard.md`
- `by-structure.md`
- `by-memory/-guidance.md`
- `by-class/-guidance.md`
- `by-file/-guidance.md`
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
- `by-file/Browser.md`
- `by-class/BrowserWindow.md`
- `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`
- `by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md`
- `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`
- `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md`
- `by-global/g_pActiveBrowserWindow.md`
- `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`
- `by-type/by-enum/BrowserDispatchEventId.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
- `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`
- `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`
- `by-memory/-ignored.md`
- `auto-generated/NexusTK/browser/Browser.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `executed-b-agent-research/B002/0000HV-Browser-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B005/00020T-BrowserWindowDocHostUiHandlerStubs-source-quality.md`
- Search hits from B001/B004/B009/B010 executed reports were opened only where directly relevant through the current support docs summarized above.

Searches performed before finalizing included: `TARGET-REPORT-UID:0000Z4`, `UID0000Z4`, `0000Z4`, `0x00469640-0x0046a39c`, `BrowserWindowCore`, `BrowserWindow`, `BrowserWindowCore empty emitter`, `0x00469f60`, `0x0046a250`, `0x00469c10`, `0x00469e20`, `BrowserWindowDocHostUiHandlerStubs`, `g_pActiveBrowserWindow`, and `BrowserDispatchEventId`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000Z4-01 | UID0000Z4 is a BrowserWindow source-authored aggregate under Browser, not a standalone new source file. | High | Target metadata, Browser/BrowserWindow docs, MCP vtable stores/restores, constructor caller, generated Browser route. | Target Scope/Reconstruction Notes; BrowserWindow Likely Original Placement; Browser Browser Class Source Boundary | incorporate | applied |
| C-0000Z4-02 | The current generated issue is an empty routed aggregate marker, not lack of behavioral evidence. | High | Generated `Browser.cpp` UID0000Z4 empty marker; generated memory coverage route `Browser.cpp` with body flag `no`; target already has detailed behavior. | Target Current Target State/Changes; Browser file empty-emitter notes | incorporate | applied |
| C-0000Z4-03 | Broad aggregate C++ must not be emitted for the target. | High | By-structure by-memory rules; current function inventory; unresolved class/field layout; prior Browser report negative conclusion. | Target Reconstruction Notes; Formal C++ block; BrowserWindow Open Questions | incorporate | applied |
| C-0000Z4-04 | The formal C++ block should contain only the explicit no-code/split marker comment listed in this report. | High | By-structure no-code marker rule; generated empty-marker state; no exact child source bodies in range yet. | Target `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| C-0000Z4-05 | Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000HV`, and `EMITTER_UIDS:0000HV`. | Medium-high | Source-authored functions in range; Browser source root route; no exact in-range children currently replace source coverage. | Target metadata | incorporate | applied |
| C-0000Z4-06 | Raise target score cautiously to `87/91` after adding current MCP/no-code/split evidence; do not raise higher. | Medium-high | Current MCP revalidation and new negative raw-helper/type evidence; remaining missing final class layout/source children. | Target score/rationale | incorporate | applied |
| C-0000Z4-07 | Exact future child candidates are constructor, non-deleting destructor, shutdown, active-state helper, navigation, QueryInterface, COM client-site/dispatch stubs, and Invoke. | Medium-high | Current 30-function inventory; decompile/analyze facts; target covered-ranges table. | Target Range/Split section; BrowserWindow Methods | incorporate | applied |
| C-0000Z4-08 | Raw helper islands at `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90`, `0x00469e20`, and `0x00469ea0` should not be promoted/emitted now. | High | Current `lookup_funcs` not-function results, current `xrefs_to` zero refs, bytes confirming prologue-shaped islands. | Target Live IDA Evidence/Reconstruction Notes | incorporate | applied |
| C-0000Z4-09 | UID00020T, UID00020V, UID000216, UID0002T5, UID0001SJ, UID0001OB, UID0003OH, and UID000218 already carry the adjacent/external source responsibilities at same-or-greater detail. | High | Support docs read; generated Browser output contains UID00020T/20V code and global declaration; target cross-refs. | Target Cross-References; BrowserWindow Evidence; Browser source-root notes | already-present | already-present |
| C-0000Z4-10 | BrowserWindow `QueryInterface` directly exposes `IDocHostUIHandler` and `IDocHostShowUI` views, but the exact UID0000Z4 body should still wait for a child page. | High | Current decompile `0x00469f60`; GUID xrefs; B005 support docs. | Target QueryInterface row; BrowserWindow Evidence | incorporate | applied |
| C-0000Z4-11 | BrowserWindow `Invoke` dispatch IDs should remain tied to [UID:0001SJ] BrowserDispatchEventId; do not duplicate enum/source constants in UID0000Z4. | High | Current decompile `0x0046a250`; BrowserDispatchEventId doc. | Target Invoke row; BrowserWindow/BrowseDispatch cross-ref | already-present | already-present |
| C-0000Z4-12 | No IDA DB edits are requested; source-facing names remain documentation inferences. | High | Assignment forbids IDA writes; type_query has no recovered UDT/source types. | Target Reconstruction Notes; IDA Rename / Type / Comment Recommendations | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Direct MCP facts support BrowserWindow ownership: constructor and destructor store/restore five BrowserWindow vtable slices, `QueryInterface` returns adjusted BrowserWindow interface views, and `Invoke` is a BrowserWindow event-sink function reached from the vtable.
- Direct MCP facts support Browser source placement: constructor is called from startup update-check browser setup, uses browser/OLE helpers, uses `g_pActiveBrowserWindow`, and neighboring exact BrowserWindow children already route through Browser/BrowserWindow.
- Documentation support is strong: Browser, BrowserWindow, BrowserVtablesAndStrings, BrowserComGuidConstants, BrowserDispatchEventId, UID00020T, UID00020V, UID000216, and UID0002T5 agree with current MCP evidence.
- Generated-output evidence precisely identifies the source-quality issue: UID0000Z4 is routed but emits only a generic empty marker.

## IDA MCP Facts

- Function/range facts: 30 promoted functions in `0x00469640-0x0046a39c`; `sub_469640` size `0x3d7`; `sub_46A250` size `0x14c`; `0x0046a39c` is not a function.
- Data/table/padding facts: `0x0046a39c-0x0046a3d0` is switch/jump/selector table plus `cc` padding before UID00020T; `by-memory/-ignored.md` already tracks this as compiler-generated for UID0000Z4.
- Xref facts: constructor has one live code ref from `StartupWindow__RunUpdateCheck`; navigation helper called by constructor; shutdown called by navigation failure and startup teardown; active-state helper called by Invoke and startup; QueryInterface reached by adjustor thunks and BrowserWindow vtable data.
- Vtable/global/type facts: BrowserWindow vtable bases `0x00613200`, `0x00613228`, `0x00613268`, `0x00613288`, and `0x006132d4` have constructor and destructor refs; `0x0067ab94` has exactly five refs; no recovered BrowserWindow/DocHost/DWebBrowser type rows were found.
- Negative IDA facts: seven raw helper starts are not IDA functions and have zero xrefs; direct UDT/type recovery is absent; no current evidence proves a safe standalone aggregate body.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00469640-0x00469a17` | future exact child candidate | BrowserWindow constructor | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x00469a20-0x00469a8a` | future exact child candidate | BrowserWindow non-deleting destructor; IDA name misleading | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x00469a90-0x00469b5c` | future exact child candidate | `ShutdownBrowserWindow` lifecycle helper | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x00469b60-0x00469c09` | future exact child candidate | active/cursor/window visibility helper | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90` | target aggregate only for now | raw no-function/no-xref setter/helper island | open/source-shaped | unresolved route | aggregate documented | do not promote now |
| `0x00469ca0-0x00469e17` | future exact child candidate | BrowserWindow navigation helper | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x00469e20`, `0x00469ea0` | target aggregate only for now | raw no-function/no-xref document property helpers | open/source-shaped | unresolved route | aggregate documented | do not promote now |
| `0x00469f60-0x0046a0a8` | future exact child candidate | BrowserWindow `QueryInterface` | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x0046a0b0-0x0046a248` | future exact child candidate | AddRef/Release/client-site/dispatch stubs | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x0046a250-0x0046a39c` | future exact child candidate | BrowserWindow `Invoke` | true | BrowserWindow/Browser | not created | split candidate; not final C++ ready |
| `0x0046a39c-0x0046a3d0` | [UID:0000VN] ignored ledger | switch/jump/selector table and padding | false | UID0000Z4 source switch | ignored | already-present |
| `0x0046a3d0-0x0046a505` | [UID:00020T] | DocHost UI/ShowUI callbacks | true | BrowserWindow | 88/92 | already source-ready child outside UID0000Z4 |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00469640` | code ref from `StartupWindow__RunUpdateCheck` | Startup/update-check path constructs BrowserWindow. |
| `0x00469a20` | code ref from `StartupWindow__RunUpdateCheck` | Startup/update-check path destructs BrowserWindow; IDA symbol is misleading. |
| `0x00469a90` | refs from `sub_469CA0` and `StartupWindow__RunUpdateCheck` | Shutdown used on navigation failure and external teardown. |
| `0x00469b60` | refs from `sub_46A250` and `StartupWindow__RunUpdateCheck` | Active-state helper used by Invoke and startup path. |
| `0x00469ca0` | ref from constructor at `0x004699df` | Constructor calls BrowserWindow navigation helper. |
| `0x00469f60` | refs from adjustor thunks and vtable data `0x00613200` | QueryInterface is BrowserWindow COM entrypoint. |
| `0x0046a250` | vtable data ref at `0x00613280` | Invoke is BrowserWindow event sink slot. |
| `0x0067ab94` | five refs across constructor/destructor/accelerator/cleanup thunk | Active BrowserWindow singleton is exact child UID0002T5/global UID0000Q6. |

## Documentation Evidence And IDA Status

- Existing target docs are broadly correct but stop short of an implementation-ready empty-emitter repair. The target already says final C++ remains intentionally blank, but by-structure now prefers an explicit formal no-code marker for routed non-body aggregate pages.
- BrowserWindow class docs already list the major methods, support UID00020T source-ready callbacks, UID00020U retained accelerator helper, UID00020V host WndProc source, UID000216 non-emitting thunks, and the Browser source-root caveat.
- Browser file docs already identify this family as Browser source-root work and preserve the older B002 empty-emitter batch conclusion that aggregate/core rows should not receive broad C++.
- Generated output currently has source-ready code for UID00020T and UID00020V, a source declaration for UID0002T5 through UID0000Q6, and an empty marker for UID0000Z4. That generated marker is the stale item this report targets.

## Ranked Ownership Analysis

### 1. [UID:0000HV] Browser by-file root

- Evidence for: current metadata, projected path `NexusTK/browser/`, Browser family source-root docs, constructor/helper/global dependencies, generated output route, and adjacent source-ready BrowserWindow children.
- Evidence against: original source may have split `browser/BrowserWindow.cpp`, and BrowserWindow is a class-level semantic owner for methods.
- Decision: keep as current emitter/source root. Document split caveat; do not create a new file now.

### 2. [UID:00001B] BrowserWindow class

- Evidence for: vtables, adjusted COM views, constructor/destructor, QueryInterface, Invoke, and support docs all identify BrowserWindow as the semantic class.
- Evidence against: class page is not a generated file root and currently keeps formal declaration work open; exact in-range method children are not split.
- Decision: use as semantic support owner for future method children and support docs. Do not make UID0000Z4 emit through BrowserWindow unless a later callback creates exact child source routes.

### 3. Exact future by-memory method children

- Evidence for: promoted function boundaries and clear roles allow exact future children for constructor, destructor, shutdown, active-state, navigation, QueryInterface, stubs, and Invoke.
- Evidence against: not created now; final C++ dependencies and field names are still unresolved.
- Decision: implementation-ready future split plan, not child creation during this callback.

### 4. No-owner/non-emitting aggregate

- Evidence for: broad aggregate and no safe aggregate body.
- Evidence against: source-authored functions are present and no exact in-range children replace them yet.
- Decision: reject `RECONSTRUCTABLE:FALSE` for UID0000Z4 now. Use an explicit no-code marker while retaining source-routing metadata.

## Source Placement

- Recommended source file/class/global/module placement: BrowserWindow method bodies ultimately belong to the BrowserWindow class under the Browser source root, currently generated through `NexusTK/browser/Browser.cpp`.
- Why this placement fits: Browser file already groups BrowserWindow, BrowserControlPane, BrowserThread, OLE helpers, GUIDs, globals, and related COM event support; current target dependencies are all inside that family.
- Rejected placements: `BrowserThread` is only a caller/host-init neighbor; `BrowserControlPane` is the newer pane analogue; `Application`/`StartupWindow` only instantiate or call the BrowserWindow; GUID/global pages own data declarations but not the core methods.
- Remaining placement uncertainty: `browser/BrowserWindow.cpp` remains plausible but unproven. Keep Browser file route and support a future source-tree split only after the Browser class/file declaration pass.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target begins at `0x00469640` after ignored `0x0046963c-0x00469640` padding and ends at `0x0046a39c`, immediately before `BrowserWindow::Invoke` switch/jump/selector bytes at `0x0046a39c-0x0046a3d0`.
- Children/subranges to create or repair: create exact future method pages for `0x00469640-0x00469a17`, `0x00469a20-0x00469a8a`, `0x00469a90-0x00469b5c`, `0x00469b60-0x00469c09`, `0x00469ca0-0x00469e17`, `0x00469f60-0x0046a0a8`, `0x0046a0b0-0x0046a248`, and `0x0046a250-0x0046a39c` when split execution is authorized.
- Padding/table/data/code distinctions: `0x0046a39c-0x0046a3d0` is already ignored compiler switch/table data; `0x00469c09-0x00469ca0` and `0x00469e17-0x00469f60` contain no-function raw helper bodies plus padding and should stay aggregate-documented until reachability is proven.
- Parent/container impact: keep UID0000Z4 as a source-authored aggregate with a formal no-code/split marker. Do not convert to `FALSE` until exact children replace source coverage.

## Negative Evidence Summary

- No recovered IDB type rows for BrowserWindow or the involved browser COM interfaces were found.
- Raw helper starts are not functions and have zero xrefs, so they cannot be safely promoted or emitted now.
- The broad aggregate has mixed concerns and unresolved field names; a single source body would be artificial.
- BrowserWindow class docs do not prove a separate original `BrowserWindow.cpp`; Browser remains the safest source root.
- Current support docs already own adjacent source responsibilities, so UID0000Z4 should not duplicate UID00020T DocHost methods, UID00020V WndProc, UID0002T5 global declaration, UID000216 release thunks, or UID0001SJ enum declarations.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names for future documentation only: `BrowserWindow::BrowserWindow`, `BrowserWindow::~BrowserWindow`, `BrowserWindow::ShutdownBrowserWindow`, `BrowserWindow::SetActiveState` or `SetBrowserActiveState`, `BrowserWindow::Navigate`, `BrowserWindow::QueryInterface`, `BrowserWindow::Invoke`, and a grouped `BrowserWindow` client-site/dispatch stub page.
- Evidence for each proposed name: behavior and current support docs, not recovered symbols.
- Items intentionally left unchanged: no IDA names, types, comments, or database records should be edited in this report/callback. The raw helper islands should not be named as source methods yet.
- Whether IDA DB edits are safe/requested: not requested and outside this assignment.

## First-Draft C++ Recommendation

- Eligible for draft C++: eligible only for a formal no-code/split marker, not method-body code.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` content to insert into UID0000Z4 if the report is accepted:

```cpp
// BrowserWindowCore is a split-required BrowserWindow aggregate.
// Do not emit a synthetic aggregate body here; exact BrowserWindow
// method children for this range should carry source bodies after
// the BrowserWindow COM layout and field names are finalized.
```

- Reason it preserves exact original behavior: it emits no executable code and therefore cannot introduce a wrong BrowserWindow implementation while exact method children are still missing.
- Reason it matches plausible original source shape: a broad documentation aggregate is not an original C++ function; source bodies should appear as ordinary BrowserWindow methods and file-static helpers on exact child pages.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: none inside the formal marker. The report body documents inferred names without putting them into generated code.
- Reason code should remain blank/no-body except for the marker: unresolved class layout and field names, mixed function cluster, and no-function/no-xref raw helper islands.
- Exact no-code proof: current MCP confirms multiple promoted functions and raw islands in one page, zero recovered class/interface types, no raw-helper xrefs, and existing exact adjacent children owning source-ready method bodies. A broad aggregate C++ body would be less correct than a marker plus future exact method children.

## Final Recommendation

- Exact implemented target changes: added the formal no-code/split marker, current MCP evidence, raw-helper negative evidence, historical generated empty-marker state, future child split table, and updated score rationale to UID0000Z4.
- Exact parent assignments recommended: keep target owner/emitter [UID:0000HV] Browser; keep BrowserWindow class as semantic/support class; do not assign raw helper islands separately.
- Exact items left no-owner/non-emitting and why: raw helper islands remain aggregate-documented because there are no function objects or xrefs; UID000216 remains non-reconstructable compiler glue already handled by its own page.
- Exact future work outside this callback: create exact method child pages and add first-draft method C++ only after each child has current evidence, field names/dependencies, and a safe BrowserWindow declaration route.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`.
- Implementation status: all accepted target changes below are applied and validated.
- Exact report facts to incorporate:
  - Current MCP session/database and `server_health ok`.
  - 30 promoted functions in the aggregate and no function at `0x0046a39c`.
  - Before implementation, generated `Browser.cpp` had UID0000Z4 only as an empty marker; the callback replaced that generated state with the formal no-code/split marker.
  - Formal no-code/split marker comment.
  - Current raw-helper negative evidence: no function objects and zero xrefs for `0x00469c10`, `0x00469c30`, `0x00469c70`, `0x00469c80`, `0x00469c90`, `0x00469e20`, and `0x00469ea0`.
  - Future exact child split candidates listed in the Function / Child Inventory.
  - Do not use broad aggregate C++ and do not duplicate source from UID00020T, UID00020V, UID0002T5, UID000216, UID0001SJ, UID0001OB, UID0003OH, or UID000218.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:87`.
  - `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:0000HV`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000HV`.
  - Replace empty formal C++ with the exact marker comment.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old blank-C++ policy is superseded by explicit marker; broad aggregate body, reclassify-FALSE now, and raw-helper promotion are rejected.

## Recommended Support Doc Changes

- Implementation status: all accepted support changes below are applied and validated without score or routing changes.

- Support path: `by-class/BrowserWindow.md`.
  - Exact facts to incorporate: UID0000Z4 remains the BrowserWindow core aggregate but should emit only an explicit no-code/split marker; future source bodies should come from exact child method pages for constructor/destructor/shutdown/active-state/navigation/QI/stubs/Invoke after BrowserWindow COM layout and field names are final.
  - Metadata/link/score/source-placement changes: no score change recommended; no owner/emitter change.

- Support path: `by-file/Browser.md`.
  - Exact facts to incorporate: UID0000Z4 is no longer a generic Browser empty-emitter row after accepted implementation; it remains Browser-routed with formal no-code marker and exact child-split plan. Preserve the one-file `Browser.cpp` versus possible future `BrowserWindow.cpp` caveat.
  - Metadata/link/score/source-placement changes: no score change recommended; no source-root change.

- Read/check-only support already present at same-or-greater detail: UID00020T, UID00020U, UID00020V, UID000216, UID0002T5, UID0000Q6, UID0001SJ, UID0001OB, UID0003OH, UID000218, and `by-memory/-ignored.md`.

## Score And Metadata Recommendation

- Pre-callback score/metadata: target `86/90`, owner/emitter `0000HV`, reconstructable `TRUE`, empty formal C++.
- Current implemented score/metadata: target `87/91`, owner/emitter unchanged, reconstructable unchanged, formal no-code/split marker inserted.
- Score rationale and reason not higher/lower: one completion point and one confidence point are justified because current MCP revalidated the aggregate, added current negative raw-helper/type evidence, and identifies the generated empty-marker repair precisely. It should not rise above `91` confidence or `87` completion because exact method child pages, final BrowserWindow declaration, field names, and method C++ are still unresolved.
- Score-improvement attempt: constructor, destructor, navigation, QI, Invoke, vtable, global, raw-helper, type-query, generated-output, and support-doc routes were checked. The blocker is converted into an implementation-ready formal marker plus exact child split plan.
- Metadata fields applied or left unchanged: score and formal C++ marker changed; owner/emitter/reconstructable remain unchanged.

## Open Questions With Attempted Resolution

- Open question: should UID0000Z4 become non-reconstructable? Resolution: no, because it still covers source-authored BrowserWindow functions and exact in-range children do not yet replace them.
- Open question: can broad aggregate C++ be written now? Resolution: no, because current evidence shows many source concepts and unresolved class layout/field names. Exact marker is safer.
- Open question: should raw helper islands be split/promoted? Resolution: no for this pass; current MCP found no function records and no xrefs for all seven starts. Future evidence that proves a caller/table/vtable route could change this.
- Open question: should a separate `BrowserWindow.cpp` be created? Resolution: not from this target alone. Browser source root remains strongest; future source-tree pass may split BrowserWindow.
- Open question: are support docs missing accepted details from executed BrowserWindow/Browser reports? Resolution: they already carry the DocHost, WndProc, active global, release-thunk, vtable, GUID, and dispatch-id facts. Only UID0000Z4/BrowserWindow/Browser needed the current no-code/split-marker state, and those edits are now applied.

## Validator Results

- Historical implementation-callback validation record; these commands and results describe the completed by-* implementation, not the report's current validator lifecycle state:
- Initial target command: `python .\tools\validator.py --mode file --file by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md --apply --queue-timeout 240`; exit code `0`, but the queue frontend returned no console command metadata while the worker was starting. It was superseded by the audited target rerun below.
- BrowserWindow class command: `python .\tools\validator.py --mode file --file by-class/BrowserWindow.md --apply --queue-timeout 240`; `command_id: 000000008157`; `command_timestamp: 2026-07-12T15:47:51-04:00`; exit code `0`; `ok: 1`; projected stats updated; generated refresh deferred.
- Browser file command: `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240`; `command_id: 000000008160`; `command_timestamp: 2026-07-12T15:48:47-04:00`; exit code `0`; `ok: 1`; reference index added UID0000Z4; projected stats updated; generated refresh deferred.
- Audited target/freshness command: `python .\tools\validator.py --mode file --file by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000008164`; `command_timestamp: 2026-07-12T15:49:25-04:00`; exit code `0`; `ok: 1`; generated refresh completed with matching `generated_refresh_command_id: 000000008164` and timestamp.
- Relevant warnings: target validation reports existing missing registry UID `0003OH`; Browser validation reports 15 existing `missing_ref_uid` rows including `0003OH`, `000407`-`00040C`, `000408`, and `00040B`. These are validator-owned registry diagnostics; no manual state repair was attempted. The completed target refresh also reports broad pre-existing autogen child-marker/no-code warnings outside UID0000Z4.
- Generated freshness: `auto-generated/NexusTK/browser/Browser.cpp` header is `validator-command-id: 000000008164`, `validator-refreshed-at: 2026-07-12T15:49:25-04:00`, equal to the completed target refresh. Its UID0000Z4 row is `Completion:87 | Confidence:91` and contains the exact four-line formal marker. Generated research tracker row UID0000Z4 is `87/91`; generated memory coverage reports UID0000Z4 as coded through `Browser.cpp`.

## Changed Files

- Historical implementation-callback changed-file record; current report archive/active-copy location is external validator-owned lifecycle state:
- Modified target: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`.
- Modified support: `by-class/BrowserWindow.md`.
- Modified support: `by-file/Browser.md`.
- Modified implementation ledger/report: `tools/leaser/Agents/Agent-B002/research/0000Z4-BrowserWindowCore-source-quality.md`.
- Validator-owned side effects: projected completion stats, validator metadata/index state, generated coverage/research-tracker metadata, and generated C++ refresh. No generated file was edited manually.
- Renamed: none.
- New child pages: none; the callback did not expand split scope.
- Historical B-agent callback fact: B002 did not run an `execute_report` variant, registry lifecycle command, archive command, or manual report move during implementation. Later supervisor/validator lifecycle events are recorded only in `VALIDATOR-REPORT-HISTORY`.

## Implementation Tracking Checklist

Historical completed implementation-callback record; checklist states describe implementation proof and do not assert the report's current validation, execution, archive, or filesystem-location state:

- [x] Supervisor validation completed before implementation: Gate 1 approved pre-implementation report SHA256 `95EE27EA1636102563A8AE829BF034B9CA4C83A8F76D74020DAA7393A9B5B4EA`.
- [x] Target/support docs updated: `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`, `by-class/BrowserWindow.md`, and `by-file/Browser.md` now carry the accepted details.
- [x] Current target state and evidence recorded: current accepted MCP session/database and health, generated before/after state, exact function inventory, raw-helper/type negative evidence, and support-doc evidence are durable in target/support docs.
- [x] Claim And Incorporation Ledger verified: C-0000Z4-01 through C-0000Z4-08 and C-0000Z4-10 are `applied`; C-0000Z4-09 and C-0000Z4-11 are `already-present`; C-0000Z4-12 is `excluded-with-reason` because IDA writes are outside scope.
- [x] Metadata/score applied: target is `COMPLETION:87`, `CONFIDENCE:91`; owner `0000HV`, emitter `0000HV`, and `RECONSTRUCTABLE:TRUE` are unchanged.
- [x] Score blockers converted into an implementation-ready result: the exact formal no-code/split marker and future method-child ranges are present; unresolved class layout/field names remain the documented score cap.
- [x] Owner/emitter/reconstructable state confirmed unchanged in target, class, file, and generated output.
- [x] Split/rename/new-child disposition applied: no child was created; exact future child ranges are recorded on target and BrowserWindow support pages.
- [x] Source placement and IDA-write disposition applied: Browser remains source root, BrowserWindow remains semantic class support, `BrowserWindow.cpp` remains plausible but unproven, and no IDA DB edit was made.
- [x] First-draft C++/no-code proof applied: the target formal block contains only the accepted four-line non-executable split marker.
- [x] Third-party import confirmed not applicable: UID0000Z4 is NexusTK BrowserWindow code.
- [x] Report-level target/support facts incorporated without loss: MCP evidence, generated state, split decision, rejected alternatives, already-present support responsibilities, and non-duplication rules are present.
- [x] Historical/stale assumptions and negative evidence preserved: old generic empty-emitter state is historicalized; broad aggregate C++, raw-helper promotion, and `RECONSTRUCTABLE:FALSE` are rejected; missing UDT/type evidence remains documented.
- [x] Wave2/Wave3 material treated only as historical/generated lead state; no stale generated name was used as authority.
- [x] Open questions documented with impact: BrowserWindow declaration/fields, optional `BrowserWindow.cpp` split, raw-helper reachability, and exact method-child source bodies remain explicit future gates.
- [x] Scoped validators completed: class `000000008157`, file `000000008160`, and audited target/freshness `000000008164`, all exit code `0`, `ok: 1`.
- [x] Generated refresh verified: generated `Browser.cpp` header matches command `000000008164` and contains UID0000Z4 `87/91` plus the exact marker. No manual generated, coverage, tracker, validator-state, lifecycle, archive, or report-move edit was made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000008181","destination_path":"executed-b-agent-research/B002/0000Z4-BrowserWindowCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000Z4-BrowserWindowCore-source-quality.md","timestamp":"2026-07-12T16:00:15-04:00","uid":"0000Z4"} -->
<!-- {"agent":"B002","command_id":"000000008183","destination_path":"tools/leaser/Agents/Agent-B002/research/0000Z4-BrowserWindowCore-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B002/0000Z4-BrowserWindowCore-source-quality.md","timestamp":"2026-07-12T16:03:17-04:00","uid":"0000Z4"} -->
<!-- {"agent":"B002","command_id":"000000008186","destination_path":"executed-b-agent-research/B002/0000Z4-BrowserWindowCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000Z4-BrowserWindowCore-source-quality.md","timestamp":"2026-07-12T16:10:15-04:00","uid":"0000Z4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
