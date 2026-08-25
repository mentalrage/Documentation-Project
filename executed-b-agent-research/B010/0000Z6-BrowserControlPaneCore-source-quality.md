** TARGET-REPORT-UID:0000Z6 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B010 Source-Quality Report: [UID:0000Z6] BrowserControlPaneCore

## Finalized Report / Current Recommendation

This is a same-report revalidation repair for the archived B010 report returned by validator command `000000006840`. Gate 1 passed on the repaired artifact at SHA256 `D0C768B973761BDA6053F4C3899A91C522261030C3EC59C76309FEAF7E40F3F8`. The implementation/verification callback then checked every accepted ledger claim against the listed target/support by-* docs; all accepted by-* claims were already present at same-or-greater factual detail or excluded with reason, so no by-* edit was needed.

Final recommendation: keep [UID:0000Z6] as the Browser-owned `BrowserControlPaneCore` aggregate, keep current target metadata at `COMPLETION:88` and `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, and keep the aggregate formal C++ blank until exact child method/callback pages are split. Callback verification confirmed the accepted target/support facts are already present at same-or-greater detail or excluded with reason.

Callback compliance: no target/support by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or registry state were edited. No leases were used. No scoped by-* validators were required because no by-* file changed. No `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, or manual report moves were run.

## Supporting Research

Lifecycle context: the executed archive copy was returned to active research because the report lacked `** TARGET-REPORT-UID:0000Z6 **`; the validator-owned history comments at the end of this file are preserved unchanged. The top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_header_missing` fields are historical/revalidation-state provenance, not a new conclusion that the target research itself is invalid.

Current MCP provenance: active IDA MCP session `supervisor_recovery_20260705`, endpoint `http://127.0.0.1:13337/mcp`, HTTP session `3e0c02c4-07d9-400b-8aef-16e93fd841c7`. `idb_list` showed one active database for `NexusTK.exe.i64`; `server_health` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, module `NexusTK.exe`, imagebase `0x400000`, and strings cache ready. Initial malformed PowerShell argument attempts were discarded as client formatting errors; the bounded schema-current calls listed below succeeded.

## Target

- UID: `0000Z6`.
- Target doc: `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`.
- Range: `0x0046b520-0x0046cfe0`.
- Current metadata from the live target doc: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, blank aggregate formal C++.
- Historical archived-report state before implementation/revalidation repair: the old report described the row as `84/90` and recommended `88/92`; that is no longer current.

## Current Target State

Current target/support docs already reflect the central disposition: Browser owner/emitter, aggregate no-code policy pending child split, COM interface views, registered `0x0046cd00` WndProc separated from raw `0x0046ced0`, dispatch and field/global naming, and Browser source placement. Callback verification found no by-* mismatch requiring edits.

Historical original assignment: `B010` report-only source-quality pass for `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`.

Historical assignment target statement from the archived copy: [UID:0000Z6] `0x0046b520-0x0046cfe0`, pre-callback score `84/90`, reconstructable, parent/emitter [UID:0000HV] `Browser`. Current target metadata is `88/92` as stated above.

Report path: `tools/leaser/Agents/Agent-B010/research/0000Z6-BrowserControlPaneCore-source-quality.md`.

Report-only compliance: no by-* documentation files were edited, and `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Keep [UID:0000Z6] as a Browser-owned `BrowserControlPaneCore` class aggregate, but do not emit one monolithic formal C++ block on the aggregate yet. Current target metadata is already `88/92`; preserve that score. The reanalysis resolves the main source-quality blockers: COM interface views are mapped to standard OLE/WebBrowser host interfaces, the registered child WndProc at `0x0046cd00` is separated from the retained raw clone at `0x0046ced0`, browser globals are separated from the `g_pScreenPane` alias, and the raw helper islands have best-supported source-facing names or explicit no-stronger-name proof.

First-draft C++ is eligible at method/callback child-page granularity, not at this aggregate page. The target spans constructor/destructor, multiple independent helpers, COM interface stubs, dispatch switch metadata, a registered WndProc, a raw unreferenced WndProc clone, and compiler jump tables. Emitting a single aggregate source block now would either duplicate future child methods or force compiler data into source. Future structural work should split exact child by-memory pages for source-bearing methods and ignored metadata bands, then emit first-draft C++ for eligible children such as the constructor, shutdown helper, navigation helper, dispatch `Invoke`, `BrowserControlPaneChildWndProc`, and compact COM stubs.

Source placement remains under [UID:0000HV] `Browser` / `auto-generated/NexusTK/browser/Browser.cpp`. Do not move this target to WebBoard, DialogPane, Application, or a new BrowserControlPane-only file in this pass. The source-quality shape is a mid-2000s Browser module implementing `BrowserControlPane` and its nested/embedded COM host interface views in the same Browser translation unit.

## Evidence Standards Used

Evidence was checked against current by-* docs, local exported/cache evidence already incorporated in the prior report, direct PE byte facts, and narrow schema-current IDA MCP calls. The MCP calls were bounded to specific addresses, byte ranges, xrefs, and functions; no broad listing, unbounded search, callgraph, type sweep, or batch analysis was used. MCP evidence is mandatory for this repaired report and is present below.

## Evidence Checked

- Supervisor and agent rules:
  - `tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `tools/leaser/Agents/Agent-B010/goal.md`
  - `tools/leaser/Agents/Agent-B010/notes.md`
  - `tools/leaser/Agents/Agent-B010/by-structure.md`
  - `tools/leaser/Agents/Agent-B010/inference_research.md`
  - `by-project-structure/proposed-source-tree.md`
- Target and support documentation:
  - `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`
  - `by-class/BrowserControlPane.md`
  - `by-file/Browser.md`
  - `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`
  - `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
  - `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
  - `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md`
  - `by-type/by-enum/BrowserDispatchEventId.md`
  - `by-global/DIID_DWebBrowserEvents2.md`
  - `by-global/g_activeBrowserControlPane.md`
  - `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`
  - `by-global/g_activeBrowserPane.md`
  - `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`
  - `by-global/g_browserRuntime.md`
  - `by-memory/0x004710e0-0x0047110e.InlineIsEqualGUID.md`
  - Browser sibling/analogue pages: `BrowserWindowCore`, `BrowserWindowHostWndProc`, `BrowserRawWindowProcClone`, and B010's prior `000333-BrowserLegacyHostWndProc-source-quality.md`.
- Local exported function cache under `resources/exported_data/functions/` for all target starts, especially:
  - `0x0046b520`, `0x0046b990`, `0x0046ba40`, `0x0046ba90`, `0x0046bba0`
  - `0x0046bc70`, `0x0046bca0`, `0x0046bce0`, `0x0046bd10`, `0x0046bd20`
  - `0x0046bd30`, `0x0046be3d`, `0x0046be61`, `0x0046be90`, `0x0046bf10`
  - `0x0046bfd0`, `0x0046c0e0`, `0x0046c250`, `0x0046c390`, `0x0046c4b0`, `0x0046c550`
  - `0x0046c670`, COM stubs through `0x0046c958`, `0x0046c960`, metadata `0x0046caf0-0x0046cbc0`, stubs through `0x0046ccf5`
  - `0x0046cd00`, metadata `0x0046ce55-0x0046ced0`, and raw clone `0x0046ced0`
- Local PE bytes from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`:
  - Section table was read directly from the PE header before extracting vtable dwords.
  - `.text` VA `0x00401000`, `.rdata` VA `0x0060d000`, `.data` VA `0x0066c000`.
  - BrowserControlPane COM vtable slices at `0x006134f0`, `0x00613518`, `0x00613558`, `0x00613578`, and `0x006135c4` were parsed from `.rdata`.
- `by-memory/-coverage-report.md` row text quoted below is historical from the archived report and retained to preserve prior research context; this repair did not edit coverage or re-read/refresh supervisor-owned coverage files.
- Current IDA MCP evidence from session `supervisor_recovery_20260705`: `idb_list`, `server_health`, bounded `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `int_convert`, and `analyze_function` calls for the target starts, vtable starts, WndProc pointers, QueryInterface, Invoke, and the registered WndProc. The old archived statement that MCP was unavailable is obsolete and superseded by this repair.

## Claim And Incorporation Ledger

| Claim ID | Claim text | Confidence | Evidence | Exact destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| Z6-001 | Report identity must include `TARGET-REPORT-UID:0000Z6`; lifecycle history comments must remain intact. | 100 | Goal/revalidation reason `target_header_missing`; validator history command `000000006840`. | This report header and validator-history footer. | Incorporated in report repair only; no by-* destination. | Applied in this report; top status-lock headers removed by supervisor override, footer unchanged. |
| Z6-002 | Current target metadata is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`; archived `84/90` wording is historical. | 98 | Current target doc read; prior report text. | `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` metadata; this report `Target` and `Score And Metadata Recommendation`. | Keep/already present. | Already present: target metadata lines show `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, blank formal C++ block. No by-* edit. |
| Z6-003 | UID0000Z6 remains Browser-owned BrowserControlPane aggregate under Browser source route, not WebBoardDialog, Application, or a new required file route. | 94 | Current target/class/file docs; constructor WebBrowser/OLE work; MCP xrefs/callers; Browser sibling docs. | Target `Scope`/owner notes; `by-class/BrowserControlPane.md` placement; `by-file/Browser.md` BrowserControlPane section. | Keep/already present. | Already present: target Scope/Rule 26 sections keep Browser owner/emitter; `by-class/BrowserControlPane.md` Summary/Likely Original Placement rejects WebBoard/Application and keeps Browser route; `by-file/Browser.md` BrowserControlPane class row records Browser source-root routing and aggregate no-code. No by-* edit. |
| Z6-004 | Aggregate formal C++ must remain blank/no monolithic body until exact child pages exist. | 96 | Mixed constructor/destructor/helpers/COM stubs/dispatch/WndProc/raw clone/table bytes; MCP `lookup_funcs`, `get_bytes`, `analyze_function`. | Target formal C++ block/source-quality notes; class C++ emission state. | Keep/already present. | Already present: target formal block is blank and B009/B010 no-code proof says exact child pages should carry source; class `C++ Emission State` says aggregate-level C++ would duplicate future children and include compiler EH/switch metadata. No by-* edit. |
| Z6-005 | Range stays `0x0046b520-0x0046cfe0`; `0x0046cfe0-0x0046d050` remains ignored switch table/padding. | 95 | PE bytes; MCP `get_bytes` at `0x0046cfe0`; coverage row context. | Target range/split notes; supervisor-owned coverage/ignored row if supervisor refreshes. | Keep target/ignored facts; exclude manual coverage/generated edits. | Already present: target Scope/Recommended Child Split keeps `0x0046b520-0x0046cfe0`; `by-memory/-ignored.md` row `0x0046cfe0-0x0046d050` records BrowserControlPane raw child-window switch table, byte selector table, and padding. Coverage/generated edits excluded with reason. |
| Z6-006 | `0x0046cd00` is the registered child WndProc; `0x0046ced0` is retained raw no-route clone. | 98 | MCP `analyze_function 0x0046cd00`; `find_bytes` pointer to `0x0046cd00` at `0x46b6aa`; no pointer hit for `0x0046ced0`; xrefs zero for clone. | Target WndProc section; `by-class/BrowserControlPane.md`; `by-file/Browser.md` WndProc family notes. | Keep/already present. | Already present: target Covered Ranges/Dispatch And WndProc Semantics and class Dispatch/WndProc Policy identify `0x0046cd00` as registered WndProc and `0x0046ced0` as raw no-route clone; Browser file class row repeats the registered/raw split. No by-* edit. |
| Z6-007 | COM views and QueryInterface map are standard OLE/WebBrowser host interfaces at object offsets `+0x108` through `+0x118`. | 96 | MCP `analyze_function 0x0046c670`; vtable bytes/xrefs at `0x006134f0`, `0x00613518`, `0x00613558`, `0x00613578`, `0x006135c4`; GUID docs. | Target COM Interface Views; `by-class/BrowserControlPane.md`; vtable/GUID support docs if narrower sync is later authorized. | Keep/already present. | Already present: target `COM Interface Views` maps offsets/vtables/QueryInterface identities; class `Field Layout And COM Views` repeats the layout; `BrowserVtablesAndStrings` has the exact BrowserControlPane COM slot map; GUID child docs list the standard COM IDs and BrowserControlPane consumers. No by-* edit. |
| Z6-008 | Dispatch `Invoke` handles events `104`, `250`, `251`, `252`, `259`, `263`, `270` with cancel/cookie/close/active-state behavior. | 94 | MCP `analyze_function 0x0046c960`; local enum docs. | Target Dispatch section; `by-type/by-enum/BrowserDispatchEventId.md` if supervisor authorizes support refresh. | Keep/already present. | Already present: target Dispatch And WndProc Semantics lists all seven cases and behavior; `BrowserDispatchEventId.md` `2026-06-21 BrowserControlPane Invoke Refinement` records case-specific URL/cancel/cookie/document-complete/new-window/window-closing/default behavior. No by-* edit. |
| Z6-009 | Active globals are `g_activeBrowserControlPane`, `g_activeBrowserPane`, application singleton, `g_pScreenPane` alias path, and shared UI helpers; do not reintroduce `g_browserRuntime` as Browser-owned runtime. | 90 | Current global docs; function bodies and prior local cache; MCP dispatch/WndProc behavior. | Target Active Browser Globals; relevant `by-global/*` docs. | Keep/already present. | Already present: target Field And Global Naming lists active globals and rejects `g_browserRuntime`; `g_activeBrowserControlPane` and `g_activeBrowserPane` global/storage pages document constructor/dispatch/accelerator roles; `g_browserRuntime.md` explicitly keeps it ignored as alias of `g_pScreenPane`. No by-* edit. |
| Z6-010 | Child split plan should place first-draft C++ only on exact source-bearing child pages and keep metadata bands ignored. | 93 | Mixed body/table boundaries; MCP function sizes and Not-a-function results at boundaries. | Target `Recommended Child Split`; this report `First-Draft C++ Recommendation`. | Keep/already present; future child creation not part of this callback. | Already present: target `Recommended Child Split` lists method/body/metadata ranges, including metadata bands; report no-code proof keeps first-draft C++ for future exact children only. No child pages created in this verification callback. |
| Z6-011 | Supervisor-owned coverage/tracker/generated outputs must not be manually edited during this repair. | 100 | User boundary and goal.md. | `by-memory/-coverage-report.md`, generated outputs, validator state, lifecycle/archive records. | Exclude with reason. | Excluded with reason: no generated, coverage, validator-state, lifecycle/archive, supervisor-ledger, or manual tracker edits were made. |

## Positive Evidence Summary

The current evidence supports the same core conclusion as the archived report but with restored live IDA MCP backing: UID0000Z6 is the BrowserControlPane aggregate for the newer Browser WebBrowser/OLE host. It contains a coherent constructor/destructor/helper/COM/dispatch/WndProc family, but the range also includes compiler metadata and a retained raw no-route WndProc clone, so aggregate-level C++ remains inappropriate.

## IDA MCP Facts

- `idb_list`: one active database, session `supervisor_recovery_20260705`, `NexusTK.exe.i64`, active worker, auto-analysis not running.
- `server_health`: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, module `NexusTK.exe`, imagebase `0x400000`, strings cache ready.
- `lookup_funcs`: `0x0046b520 sub_46B520 size 0x46e`, `0x0046b990 sub_46B990 size 0xa2`, `0x0046ba40 sub_46BA40 size 0x49`, `0x0046ba90 sub_46BA90 size 0x105`, `0x0046bd30 sub_46BD30 size 0x151`, `0x0046c550 sub_46C550 size 0x10a`, `0x0046c670 sub_46C670 size 0x14c`, `0x0046c960 sub_46C960 size 0x190`, `0x0046cd00 sub_46CD00 size 0x155`; `0x0046ced0` and `0x0046cfe0` are not IDA functions.
- `xrefs_to`: constructor has five code xrefs; accelerator helper has one Application-loop call; QueryInterface has adjustor/vtable reachability; Invoke has vtable reachability; registered WndProc has constructor data ref; raw clone and post-target boundary have no xrefs.
- `find_bytes`: little-endian pointer to `0x0046cd00` found at `0x46b6aa`; little-endian pointers to `0x0046ced0` and `0x0046cfe0` had zero exact hits; positive controls for vtable pointers to `0x0046c670` and `0x0046c960` matched expected vtable rows.
- `get_bytes`: `0x0046ced0` begins as raw code but is not an IDA function and has no route; `0x0046cfe0` begins table/alignment bytes, not a source body; vtable bytes at `0x006134f0` match the COM slot sequence.
- `analyze_function 0x0046c670`: QueryInterface compares Browser COM GUID constants and returns adjusted interface views with AddRef.
- `analyze_function 0x0046c960`: Invoke contains the Browser dispatch switch for events `104`, `250`, `251`, `252`, `259`, `263`, `270`, plus default `DISP_E_MEMBERNOTFOUND`.
- `analyze_function 0x0046cd00`: registered WndProc obtains `this` through `GetWindowLongA(hwnd, -21)`, handles paint/move/timer/syscommand cases, and falls back to `DefWindowProcA`.

## Function / Child Inventory

Function inventory remains the child split plan below. Current/applied aggregate score is `88/92`; the old `84/90` score is only historical pre-callback context. Child pages are still the correct place for formal C++ because the aggregate spans multiple methods, compact COM stubs, callbacks, raw helpers, and compiler metadata bands.

## Direct Xref / Caller Inventory

Direct xref facts are summarized in the existing Caller And Reachability Closure section and refreshed by MCP facts above. Key current points: constructor calls from Browser/WebBoard/BrowserPane creation paths; accelerator helper called from Application loop; QueryInterface/Invoke reached through vtable slots; registered WndProc reached through constructor data; raw clone has no caller/pointer route.

## Documentation Evidence And IDA Status

Current target, class, and Browser file docs already align with the accepted disposition at same-or-greater detail. IDA still names several starts as `sub_*`; this report treats those as database names, not final source names. `0x0046ced0` is retained as documented raw bytes/no-route evidence rather than promoted to a source-emitting function.

## Ranked Ownership Analysis

1. [UID:0000HV] `Browser`: strongest owner and emitter. Constructor, COM interfaces, Browser globals, Browser source docs, and sibling Browser host pages all align here.
2. WebBoardDialog: rejected. It embeds/uses BrowserControlPane but does not own the Browser COM host class.
3. Application: rejected. It calls only the accelerator bridge from the message loop.
4. New required BrowserControlPane-only by-file route: plausible as a human source split later, but not supported as a required route by current metadata or source tree.

## Source Placement

Retain Browser source placement through `by-file/Browser.md` and emitter UID `0000HV`. The source-facing file route remains Browser/Browser.cpp level until a supervisor decides to introduce exact child pages or a narrower source split.

## Historical Coverage Context From Archived Report

The archived report quoted the then-current supervisor-owned `by-memory/-coverage-report.md` target row below. This repair did not refresh or edit coverage files, so the quoted `84%` row is historical coverage context and not the current target metadata:

```text
    - [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) 0x0046b520-0x0046cfe0 | class aggregate | BrowserControlPaneCore : reconstructable : 84% : strong : Live IDA-confirmed constructor/destructor/shutdown/navigation, raw state/document/blit helper islands, browser blit/backdrop/bounds/key handlers, COM stubs, dispatch handler, and promoted/raw child-window message handlers.
```

The archived report also quoted this adjacent ignored row:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046cfe0-0x0046d050 | switch table/padding | BrowserControlPane child-window message switch data : ignored : 90% : strong : Compiler-generated jump table, byte dispatch table, and alignment after the raw BrowserControlPane child-window message handler.
```

## Range / Split / Padding / Reclassification Analysis

Keep the aggregate range as `0x0046b520-0x0046cfe0`. Do not extend through `0x0046d050`; the bytes at `0x0046cfe0-0x0046d050` are switch table/alignment data for the raw WndProc-like clone and already belong to the ignored row. The local Ghidra cache reports raw clone size through `0x0046cfe1`, but the PE bytes and coverage split show `0x0046cfe0` begins post-body compiler data/alignment. Treat the off-by-one as a raw-analysis artifact unless live IDA later proves otherwise.

Recommended child split plan for implementation:

- `0x0046b520-0x0046b98e`: `BrowserControlPane::BrowserControlPane`, source-bearing constructor.
- `0x0046b98e-0x0046b990`: padding/alignment.
- `0x0046b990-0x0046ba32`: `BrowserControlPane::~BrowserControlPane`, non-deleting destructor.
- `0x0046ba32-0x0046ba40`: padding/alignment.
- `0x0046ba40-0x0046ba89`: `BrowserControlPane::RedrawChildWindow`, source-bearing helper.
- `0x0046ba89-0x0046ba90`: padding/alignment.
- `0x0046ba90-0x0046bb95`: `BrowserControlPane::ShutdownBrowser`, source-bearing helper.
- `0x0046bb95-0x0046bba0`: padding/alignment.
- `0x0046bba0-0x0046bc69`: `BrowserControlPane::SetBrowserActiveState`, source-bearing helper.
- `0x0046bc69-0x0046bc70`: padding/alignment.
- `0x0046bc70-0x0046bc93`: raw helper, best name `BrowserControlPane::SetRefreshStateAndRefresh`.
- `0x0046bca0-0x0046bcdd`: raw helper, best name `BrowserControlPane::SetAllowedUrlPrefix`.
- `0x0046bce0-0x0046bd0a`: raw helper, best name `BrowserControlPane::SetNavigationTimeoutMillis`.
- `0x0046bd10-0x0046bd20`: raw byte setter, best name `BrowserControlPane::SetBrowserStateByte0`.
- `0x0046bd20-0x0046bd30`: raw byte setter, best name `BrowserControlPane::SetBrowserStateByte1`.
- `0x0046bd30-0x0046be81`: `BrowserControlPane::NavigateBrowser`, source-bearing navigation helper. Internal starts `0x0046be3d` and `0x0046be61` are EH catch/unwind compiler artifacts inside this helper, not independent source functions.
- `0x0046be81-0x0046be90`: padding/alignment.
- `0x0046be90-0x0046bf06`: `BrowserControlPane::GetDocumentCookie`.
- `0x0046bf10-0x0046bfc8`: `BrowserControlPane::SetDocumentCookie`.
- `0x0046bfc8-0x0046bfd0`: padding/alignment.
- `0x0046bfd0-0x0046c0df`: `BrowserControlPane::BlitBrowserSurfaceToRenderTarget` or `CopyBrowserSurfaceToTarget`, source-bearing blit helper reached by presentation/screenshot code.
- `0x0046c0e0-0x0046c247`: `BrowserControlPane::RefreshBrowserSurface`, source-bearing browser child/surface update helper.
- `0x0046c247-0x0046c250`: padding/alignment.
- `0x0046c250-0x0046c38c`: raw helper, best name `BrowserControlPane::BlitSurfaceRectToBrowser`, source-bearing only after destination/source HDC types are named.
- `0x0046c390-0x0046c4a9`: `BrowserControlPane::DrawBrowserBackdrop` or `PaintBrowserBackdrop`, virtual override.
- `0x0046c4b0-0x0046c549`: `BrowserControlPane::SyncBrowserWindowBounds`, virtual override.
- `0x0046c550-0x0046c65a`: `BrowserControlPaneTranslateAcceleratorMessage`, file-static helper called by the Application message loop.
- `0x0046c65a-0x0046c670`: compiler switch metadata/alignment for the accelerator helper; ignored, not source.
- `0x0046c670-0x0046c7bc`: `BrowserControlPane::QueryInterface`, source-bearing COM method.
- `0x0046c7c0-0x0046c958`: IOleClientSite/IOleInPlaceSite/IDispatch compact COM stubs; source-bearing but should be child-split as a stub cluster or exact methods.
- `0x0046c958-0x0046c960`: padding/alignment.
- `0x0046c960-0x0046caf0`: `BrowserControlPane::Invoke`, DWebBrowserEvents2/IDispatch event handler.
- `0x0046caf0-0x0046cbc0`: compiler dispatch switch metadata; ignored, not source.
- `0x0046cbc0-0x0046ccf5`: IDocHostUIHandler/IDocHostShowUI compact COM stubs; source-bearing but should be child-split as a stub cluster or exact methods.
- `0x0046ccf5-0x0046cd00`: padding/alignment.
- `0x0046cd00-0x0046ce55`: `BrowserControlPaneChildWndProc`, registered window procedure; source-bearing callback.
- `0x0046ce55-0x0046ced0`: compiler switch metadata/alignment for the registered WndProc; ignored, not source.
- `0x0046ced0-0x0046cfe0`: `BrowserControlPaneRawChildWndProcClone` / `BrowserControlPane::RawChildWndProc`, retained raw clone with no route; keep documented but do not emit final C++ until reachability is proved.
- `0x0046cfe0-0x0046d050`: outside target; ignored switch table/padding before [UID:0000Z7] `WebBoardDialog`.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Best-supported owner/emitter remains [UID:0000HV] `Browser`, with implementation under `auto-generated/NexusTK/browser/Browser.cpp`. Evidence:

- Target constructor directly registers `"Nexon.Baram.Browser"` and creates the embedded browser host child window.
- Constructor creates the WebBrowser COM object with `CLSID_WebBrowser` (`0x00631620`), `IID_IOleObject` (`0x006315a0`), and `IID_IWebBrowser2` (`0x00631600`).
- Constructor advises `DIID_DWebBrowserEvents2` (`0x00631610`) through Browser-owned `AdviseConnectionPoint` (`0x004708d0`) and unadvises through `UnadviseConnectionPoint` (`0x00470980`).
- Support [UID:0000HV] already routes `BrowserControlPane`, `BrowserWindow`, `BrowserPane`, `BrowserThread`, `BrowserControlPaneOld`, and Browser helper functions into Browser.
- `by-class/BrowserControlPane.md` already has Browser as owner/emitter and lists these exact methods.
- Sibling BrowserWindow and legacy Browser WndProc pages use the same Browser source family. The target is not owned by WebBoardDialog even though WebBoardDialog embeds a `BrowserControlPane` at `+0x26c`.

Rejected source-placement alternatives:

- `WebBoardDialog.cpp`: rejected because WebBoardDialog only contains a `BrowserControlPane` member and calls BrowserControlPane helpers. The constructor callers include WebBoardDialog paths, but the class, COM interfaces, globals, GUIDs, and WndProc class are Browser-owned.
- `Application.cpp`: rejected because `0x0046c550` is merely called from Application's message loop at `0x00464d88`; it queries `g_activeBrowserControlPane` and delegates to WebBrowser's `IOleInPlaceActiveObject::TranslateAccelerator`.
- A new by-file `BrowserControlPane.cpp`: plausible as a future human source split, but not supported by the current proposed source tree or existing emitter UID. Use Browser.cpp for this implementation cycle.

### COM Interface Map And Final Interface Names

The constructor stores COM view vtables at object offsets:

- `+0x108`: `BrowserControlPaneOleClientSite` / `IOleClientSite` aggregate IUnknown view, vtable `0x006134f0`.
- `+0x10c`: `BrowserControlPaneInPlaceSite` / `IOleWindow` plus `IOleInPlaceSite`, vtable `0x00613518`.
- `+0x110`: `BrowserControlPaneBrowserEvents` / `IDispatch` sink for `DWebBrowserEvents2`, vtable `0x00613558`.
- `+0x114`: `BrowserControlPaneDocHostUIHandler` / `IDocHostUIHandler`, vtable `0x00613578`.
- `+0x118`: `BrowserControlPaneDocHostShowUI` / `IDocHostShowUI`, vtable `0x006135c4`.

`BrowserControlPane::QueryInterface` at `0x0046c670` resolves:

- `IID_IUnknown` (`0x00631580`) and `IID_IOleClientSite` (`0x00631590`) to the client-site view.
- `IID_IOleWindow` (`0x006315b0`) and `IID_IOleInPlaceSite` (`0x006315e0`) to the in-place-site view.
- `DIID_DWebBrowserEvents2` (`0x00631610`) to the event-sink/IDispatch view.
- `IID_IDocHostUIHandler` (`0x00631630`) to the doc-host UI handler view.
- `IID_IDocHostShowUI` (`0x00631640`) to the doc-host show-UI view.
- Unmatched GUIDs set `*ppv = 0` and return `E_NOINTERFACE` (`0x80004002`).

COM slot map from the PE `.rdata` vtables:

- `0x006134f0` `IOleClientSite`:
  - `0x0046c670` `QueryInterface`
  - `0x0046c7c0` `AddRef`
  - `0x0046c7d0` `Release`
  - `0x0046c7e0` `SaveObject`
  - `0x0046c7f0` `GetMoniker`
  - `0x0046c800` `GetContainer`
  - `0x0046c810` `ShowObject`
  - `0x0046c820` `OnShowWindow`
  - `0x0046c830` `RequestNewObjectLayout`
- `0x00613518` `IOleWindow`/`IOleInPlaceSite`:
  - `0x00471004`, `0x00470877`, `0x0047107c`: adjustor/shared `IUnknown` slots; belong to Browser OLE helper/thunk support, not new source methods in this target.
  - `0x0046c840` `GetWindow`
  - `0x0046c860` `ContextSensitiveHelp`
  - `0x0046c870` `CanInPlaceActivate`
  - `0x0046c880` `OnInPlaceActivate`
  - `0x0046c890` `OnUIActivate`
  - `0x0046c8a0` `GetWindowContext`
  - `0x0046c8d0` `Scroll`
  - `0x0046c8e0` `OnUIDeactivate`
  - `0x0046c8f0` `OnInPlaceDeactivate`
  - `0x0046c900` `DiscardUndoState`
  - `0x0046c910` `DeactivateAndUndo`
  - `0x0046c920` `OnPosRectChange`
- `0x00613558` `IDispatch` event sink for `DWebBrowserEvents2`:
  - `0x0047100e`, `0x00470881`, `0x00471086`: adjustor/shared `IUnknown` slots.
  - `0x0046c950` `GetTypeInfoCount`
  - `0x0046c940` `GetTypeInfo`
  - `0x0046c930` `GetIDsOfNames`
  - `0x0046c960` `Invoke`
- `0x00613578` `IDocHostUIHandler`:
  - `0x00471022`, `0x00470895`, `0x0047109a`: adjustor/shared `IUnknown` slots.
  - `0x0046cc90` `ShowContextMenu`
  - `0x0046cc10` `GetHostInfo`
  - `0x0046cca0` `ShowUI`
  - `0x0046cc50` `HideUI`
  - `0x0046ccd0` `UpdateUI`
  - `0x0046cbc0` `EnableModeless`
  - `0x0046cc60` `OnDocWindowActivate`
  - `0x0046cc70` `OnFrameWindowActivate`
  - `0x0046cc80` `ResizeBorder`
  - `0x0046ccb0` `TranslateAccelerator`
  - `0x0046cc40` `GetOptionKeyPath`
  - `0x0046cbe0` `GetDropTarget`
  - `0x0046cbf0` `GetExternal`
  - `0x0046ccc0` `TranslateUrl`
  - `0x0046cbd0` `FilterDataObject`
- `0x006135c4` `IDocHostShowUI`:
  - `0x00471018`, `0x0047088b`, `0x00471090`: adjustor/shared `IUnknown` slots.
  - `0x0046ccf0` `ShowMessage`
  - `0x0046cce0` `ShowHelp`

Validation and negative evidence:

- The vtable lengths match the standard COM interface shapes: `IOleClientSite` has 9 slots, `IOleInPlaceSite` has 15 slots including `IUnknown`/`IOleWindow`, `IDispatch` has 7 slots, `IDocHostUIHandler` has 18 slots, and `IDocHostShowUI` has 5 slots.
- QueryInterface's returned pointer offsets exactly match the constructor's adjacent vtable fields: relative offsets `+0`, `+4`, `+8`, `+12`, and `+16` from the COM aggregate start at object `+0x108`.
- The `0x004710xx` and `0x004708xx` entries are adjustor/shared IUnknown thunks in the broader Browser OLE helper range; do not duplicate them as new BrowserControlPane method bodies.

### Field And Type Names

Best-supported `BrowserControlPane` field names/types:

- `+0x108` `IOleClientSiteVtbl *m_clientSiteVtbl`.
- `+0x10c` `IOleInPlaceSiteVtbl *m_inPlaceSiteVtbl`.
- `+0x110` `IDispatchVtbl *m_eventsVtbl`.
- `+0x114` `IDocHostUIHandlerVtbl *m_docHostUIHandlerVtbl`.
- `+0x118` `IDocHostShowUIVtbl *m_docHostShowUIVtbl`.
- `+0x11c` `HWND m_browserHostHwnd`; constructor creates it with class `"Nexon.Baram.Browser"`, WndProc `0x0046cd00`, `WS_CHILD | WS_VISIBLE`-style value `0x44000000`, and stores `this` via `SetWindowLongA(hwnd, GWL_USERDATA/-21, this)`.
- `+0x120` `IWebBrowser2 *m_webBrowser`; constructor QIs it from `IOleObject`; shutdown calls vtable `+0x38` (`Stop`) and `+0x80` (`Quit`) before release.
- `+0x124` `DWORD m_webBrowserEventsCookie`; filled by `AdviseConnectionPoint`, consumed by `UnadviseConnectionPoint`.
- `+0x128` `uint8_t m_cancelNavigateComplete` or `m_navigateCompleteCancelGate`; dispatch case 251 uses it to decide whether to fall through to the cancel path. Exact UI-facing property name is not proven.
- `+0x129` `uint8_t m_refreshStateByte` or `m_browserRefreshState`; raw helper stores it and calls `IWebBrowser2::Refresh` when the browser exists.
- `+0x12a` `uint8_t m_browserActiveState`; initialized to 1, set by `SetBrowserActiveState`, used by dispatch document-complete restore.
- `+0x12b` padding/unused byte by current evidence.
- `+0x12c-0x32b` `wchar_t m_allowedUrlPrefix[256]`; raw helper copies at most 255 wide chars and manually terminates at `+0x32a`.
- `+0x32c` `int m_navigationTimeoutMillis`; constructor default `30000`, raw setter stores the caller value and notifies the BrowserPane with command/tag `0x4243746f` when set to zero.
- `+0x330` and `+0x331` `uint8_t m_browserStateByte0`, `uint8_t m_browserStateByte1`; constructor initializes both to `2` (`0x0202` word), shutdown clears both as a word, raw setters write them individually. No read or semantic consumer was found in the exported cache, so stronger names would be speculative.
- `+0x332` `uint8_t m_cursorShownByBrowser`; guards balanced `ShowCursor(1)`/`ShowCursor(0)` calls.
- `+0x333` `uint8_t m_deferShowUntilDocumentComplete`; initialized to 1, cleared in dispatch `DocumentComplete` before calling `SetBrowserActiveState`.
- `+0x334` `IDispatch *m_topLevelNavigationDispatchCookie` or raw `DWORD m_topLevelDispatchCookie`; dispatch case 252 stores the first dispatch cookie and case 259 compares/clears it to identify top-level document completion.

Rejected field alternatives:

- `g_browserRuntime` is not a distinct Browser global for this target. The relevant `dword_67A7CC` uses are the existing `g_pScreenPane` alias/runtime screen pane path; the Browser-global doc marks `g_browserRuntime` as an ignored alias.
- `+0x32c` is not the dispatch cookie; dispatch uses `+0x334` relative to the object after accounting for the `IDispatch` subobject pointer.
- `+0x330/+0x331` should not be named as navigation flags, cancel flags, or timer fields without additional read evidence. The only proven actions are initialization, shutdown clear, and raw setter writes.

### Helper Names And Source-Facing Roles

Best-supported source-facing helper names:

- `0x0046b520`: `BrowserControlPane::BrowserControlPane(const RECT *bounds, const OLECHAR *initialUrl, BrowserPane *ownerPane)`. `bounds` is passed to `ControlPane` and used for child HWND width/height; `initialUrl` is optional and passed to `NavigateBrowser`; `ownerPane` is stored in `g_activeBrowserPane`.
- `0x0046b990`: `BrowserControlPane::~BrowserControlPane`, non-deleting destructor. Scalar deleting destructor remains in [UID:0000ZF] at `0x00470410`.
- `0x0046ba40`: `BrowserControlPane::RedrawChildWindow` or `InvalidateBrowserChildWindow`; called at `0x004660d7`.
- `0x0046ba90`: `BrowserControlPane::ShutdownBrowser`; clears the state word at `+0x330`, focuses/hides the child HWND, restores cursor state if necessary, unadvises events, calls WebBrowser stop/quit, releases the COM pointer, destroys the child HWND, and restores focus to the application main window.
- `0x0046bba0`: `BrowserControlPane::SetBrowserActiveState(bool active)`; writes `+0x12a`, toggles cursor visibility using `+0x332`, notifies `g_pScreenPane`/`dword_67A7CC` via `sub_5573f0`, shows with `ShowWindow(..., SW_SHOW)` plus `UpdateWindow` only when active and `+0x333 == 0`, otherwise hides.
- `0x0046bc70`: `BrowserControlPane::SetRefreshStateAndRefresh(uint8_t state)`; writes `+0x129` and calls `IWebBrowser2::Refresh` (`m_webBrowser` vtable `+0x30`) if present.
- `0x0046bca0`: `BrowserControlPane::SetAllowedUrlPrefix(const wchar_t *prefix)`; clears or copies into `m_allowedUrlPrefix[256]`.
- `0x0046bce0`: `BrowserControlPane::SetNavigationTimeoutMillis(int timeoutMillis)`; writes `+0x32c`, emits BrowserPane command/tag `0x4243746f` when set to zero.
- `0x0046bd10`: `BrowserControlPane::SetBrowserStateByte0(uint8_t value)`; best safe name only.
- `0x0046bd20`: `BrowserControlPane::SetBrowserStateByte1(uint8_t value)`; best safe name only.
- `0x0046bd30`: `BrowserControlPane::NavigateBrowser(const OLECHAR *url, const OLECHAR *postDataOrHeaders)`; calls `BrowserVariantFromString` and `IWebBrowser2::Navigate`-style vtable slots, with EH cleanup starts inside the same function.
- `0x0046be90`: `BrowserControlPane::GetDocumentCookie(wchar_t *buffer, rsize_t count)`; obtains `IHTMLDocument2` via `IWebBrowser2::get_Document` (`+0x48`) and `QueryInterface(IID_IHTMLDocument2)`, calls vtable `+0xb0`, copies BSTR to caller, frees BSTR, releases interfaces.
- `0x0046bf10`: `BrowserControlPane::SetDocumentCookie(const wchar_t *name, const wchar_t *value)`; formats `L"%s=%s"` into an OLECHAR buffer, allocates a BSTR, calls `IHTMLDocument2` vtable `+0xac`, frees BSTR, releases interfaces.
- `0x0046bfd0`: `BrowserControlPane::BlitBrowserSurfaceToRenderTarget` / `CopyBrowserSurfaceToTarget`; reached by presentation/screenshot code at `0x00557203`, `0x005572c3`, `0x005579b2`, `0x00557ce8`, `0x00558027`, `0x005584c1`, and `0x00558581`.
- `0x0046c0e0`: `BrowserControlPane::RefreshBrowserSurface`; reached by backdrop/paint and both WndProc timer paths.
- `0x0046c250`: `BrowserControlPane::BlitSurfaceRectToBrowser`; raw HDC/rect blit helper that maps source/destination rectangles and uses `BitBlt`/`StretchBlt`-style paths. Exact render-surface type remains to be incorporated from render docs before final C++.
- `0x0046c390`: `BrowserControlPane::DrawBrowserBackdrop`, a virtual override from the main ControlPane/Pane vtable slice.
- `0x0046c4b0`: `BrowserControlPane::SyncBrowserWindowBounds`, a virtual override that tracks/repositions the hosted child HWND.
- `0x0046c550`: `BrowserControlPaneTranslateAcceleratorMessage(MSG *message)`, file-static helper called by the main Application message loop. It QIs `m_webBrowser` for `IID_IOleInPlaceActiveObject` (`0x006315c0`), handles key messages `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, and `WM_SYSKEYUP`, closes on Escape via `BrowserPane::Close`/`sub_49df20(g_activeBrowserPane)`, bypasses Ctrl+N without Alt, otherwise calls `IOleInPlaceActiveObject::TranslateAccelerator`.
- `0x0046c960`: `BrowserControlPane::Invoke`, DWebBrowserEvents2 event sink.
- `0x0046cd00`: `BrowserControlPaneChildWndProc`, registered `WNDPROC`.
- `0x0046ced0`: `BrowserControlPaneRawChildWndProcClone`, retained raw clone with identical message body except it receives `this` directly and has no `GetWindowLongA` route.

### Dispatch Event Semantics

`BrowserControlPane::Invoke` at `0x0046c960` handles the event IDs already documented in [UID:0001SJ] `BrowserDispatchEventId`:

- `104` (`0x68`): no-op, returns `S_OK`.
- `250` (`0xfa`, `BeforeNavigate2`-like):
  - Reads URL string from the event argument VARIANT structure.
  - If URL begins with internal prefixes at `0x00613994`, `0x006139e0`, or `L"res://"`, it calls `BrowserPane` close/helper `sub_49df20(g_activeBrowserPane)` and cancels navigation.
  - If `m_allowedUrlPrefix` is nonempty, URL starts with `L"http://"`, and URL does not start with the allowed prefix, it cancels navigation.
  - Cancel is implemented by writing `1` through the event cancel VARIANT/bool pointer.
- `251` (`0xfb`, navigate-complete-like): if `m_cancelNavigateComplete` is nonzero, returns without cancellation; otherwise falls through to event `270` cancellation.
- `252` (`0xfc`, navigation cookie/token): stores the first dispatch cookie into `m_topLevelDispatchCookie` if empty.
- `259` (`0x103`, `DocumentComplete`-like):
  - Compares event dispatch cookie with `m_topLevelDispatchCookie`.
  - Clears the stored cookie when it matches.
  - Notifies `g_activeBrowserPane` with command/tag `0x4243746f`.
  - If `m_deferShowUntilDocumentComplete` is set, clears it and calls `SetBrowserActiveState(m_browserActiveState)`.
- `263` (`0x107`, new-window-like): writes cancel `0`, calls `sub_49df20(g_activeBrowserPane)`, returns `S_OK`.
- `270` (`0x10e`, window-closing-like): writes cancel `1`.
- Default:
  - Writes `0` to `g_pScreenPane/dword_67A7CC + 0x5b2`.
  - Calls vtable `+0x20` on `g_pScreenPane/dword_67A7CC`.
  - Returns `DISP_E_MEMBERNOTFOUND` (`0x80020003`).

The dispatch switch metadata at `0x0046caf0-0x0046cbc0` is compiler-generated selector/jump-table data, not a source helper.

### WndProc Promoted/Raw Split

Final WndProc split:

- `0x0046cd00` is the real registered callback. Constructor stores it into `WNDCLASSA.lpfnWndProc` and registers class name `"Nexon.Baram.Browser"`. It reads `BrowserControlPane *this` from `GetWindowLongA(hwnd, -21)`, falls back to `DefWindowProcA` when unset, and handles the message body.
- `0x0046ced0` is a raw retained clone/member-shaped WndProc-like helper. It takes `this` directly, has no IDA pointer/caller hit, and is not used by the constructor. Keep documented for coverage but do not promote to an emitted source callback unless later xrefs prove a route.

Both message bodies:

- `WM_NCPAINT` (`0x85`): calls vtable `+0x20` with argument `0` on `dword_67A740` or fallback `dword_67ABA4` if either global exists.
- `WM_MOVE` (`0x03`): if hosted child HWND at `+0x11c` is visible, `GetClientRect` and `RedrawWindow(hwnd, &rect, 0, 0x181)`.
- `WM_PAINT` (`0x0f`): returns `0`, suppressing default paint handling.
- `WM_SYSCOMMAND` (`0x112`): consumes command classes `0xf000`, `0xf010`, `0xf020`, `0xf030`, and `0xf060` (size, move, minimize, maximize, close classes).
- `WM_TIMER` (`0x113`) with timer ID `1004` (`0x3ec`): if child HWND is visible, calls `BrowserControlPane::RefreshBrowserSurface` at `0x0046c0e0`.
- Otherwise calls `DefWindowProcA`.

Do not merge this WndProc with the legacy Browser WndProc at [UID:000333] `0x0046fcb0-0x0046ff50`; that sibling belongs to the legacy/old browser host path and a separate window class/source route.

### Active Browser Globals

Best-supported globals:

- `g_activeBrowserControlPane` at `0x0067ab28`: type `BrowserControlPane *`. Constructor writes it, destructor/scalar destructor/helper clear it, and `BrowserControlPaneTranslateAcceleratorMessage` reads it. This is the correct name for `dword_67AB28`.
- `g_activeBrowserPane` at `0x0067ab84`: type best as `BrowserPane *` or owner/callback pane pointer. Constructor writes `a4`; dispatch and accelerator helpers use it for close/command callbacks. No direct clear was found in this target.
- `g_pApplication` / application singleton at `0x0067ab1c`: used for `HINSTANCE`, parent HWND, and focus restoration.
- `dword_67A7CC`: use existing `g_pScreenPane`/screen runtime naming, not `g_browserRuntime`.
- `dword_67A740` and `dword_67ABA4`: shared UI/popup/focus helpers used by WndProc `WM_NCPAINT`; not BrowserControlPane-owned fields.
- `byte_66DA97`: mode branch used while notifying `g_pScreenPane`/`sub_5573f0`; not Browser-owned.
- GUID constants remain Browser/OLE read-only data as already documented under [UID:0003OH]/[UID:000272].

### Caller And Reachability Closure

Direct reachability from exported cache and PE/xrefs:

- Constructor `0x0046b520`: calls from `0x0046ab86`, `0x0046ac95`, `0x0046d1f8`, `0x0046e3f4`, and `0x0046e7ca`.
- Destructor `0x0046b990`: no ordinary direct callers in cache; scalar deleting destructor exists at `0x00470410` and clears `g_activeBrowserControlPane`.
- `RedrawChildWindow` `0x0046ba40`: call from `0x004660d7`.
- `ShutdownBrowser` `0x0046ba90`: calls from `0x0046ad57`, `0x0046be50`, `0x0046d377`, `0x0046e269`, and `0x0046e907`.
- `SetBrowserActiveState` `0x0046bba0`: call from dispatch handler `0x0046caa2`.
- Raw helper island `0x0046bc70-0x0046bd30`: no direct callers found in exported cache; keep as raw method records and do not invent external reachability.
- `NavigateBrowser` `0x0046bd30`: calls from `0x0046a8ce`, constructor `0x0046b956`, `0x0046d2ff`, `0x0046da44`, and `0x0046ee5b`.
- `GetDocumentCookie`/`SetDocumentCookie`: no direct callers found in exported cache; source role is still strong because bodies are coherent IHTMLDocument2 cookie accessors.
- `BlitBrowserSurfaceToRenderTarget` `0x0046bfd0`: calls from presentation/screenshot paths `0x00557203`, `0x005572c3`, `0x005579b2`, `0x00557ce8`, `0x00558027`, `0x005584c1`, and `0x00558581`.
- `RefreshBrowserSurface` `0x0046c0e0`: calls from `0x0046c3b8`, registered WndProc `0x0046ce1a`, and raw clone `0x0046cfbb`.
- `DrawBrowserBackdrop` `0x0046c390`: vtable data ref at `0x00613490`.
- `SyncBrowserWindowBounds` `0x0046c4b0`: vtable data ref at `0x0061347c`.
- `BrowserControlPaneTranslateAcceleratorMessage` `0x0046c550`: call from Application message loop `0x00464d88`.
- `QueryInterface` `0x0046c670`: vtable ref at `0x006134f0` and adjustor thunks `0x00471004`, `0x0047100e`, `0x00471018`, `0x00471022`.
- `Invoke` `0x0046c960`: vtable ref at `0x00613570`.
- Registered WndProc `0x0046cd00`: constructor data ref at `0x0046b6a4` / `0x0046b6aa` as `WNDCLASSA.lpfnWndProc`.
- Raw WndProc clone `0x0046ced0`: no direct callers or pointer hits found; keep raw/no-route.

### Rejected Alternatives And Negative Evidence

- Do not call the raw `0x0046ced0` function the real WndProc. The constructor points to `0x0046cd00`, and `0x0046ced0` has no caller/pointer evidence.
- Do not treat `0x0046c65a-0x0046c670`, `0x0046caf0-0x0046cbc0`, `0x0046ce55-0x0046ced0`, or `0x0046cfe0-0x0046d050` as source functions. PE bytes show jump-table/selectors/alignment; coverage already has an ignored row for the post-target table.
- Do not use `sub_`/raw Ghidra names in final docs where interface or source names above are supported.
- Do not over-name `+0x330/+0x331`; search found constructor initialization, shutdown clear, and setter writes only. Best safe source-quality closure is reserved/browser state byte setters.
- Do not route `dword_67A7CC` to Browser runtime. Existing docs mark the Browser-runtime global as an ignored alias; behavior matches shared screen-pane cursor/status notification.
- Do not include `InlineIsEqualGUID` as BrowserControlPane source; it is SDK/header-inline support at [UID:000218] and called by QueryInterface.

## Negative Evidence Summary

Negative evidence is concentrated in route and boundary proof: `0x0046ced0` has no caller or pointer route; `0x0046cfe0` is post-body table/alignment; internal bands at `0x0046c65a-0x0046c670`, `0x0046caf0-0x0046cbc0`, and `0x0046ce55-0x0046ced0` are compiler metadata; `g_browserRuntime` is a rejected alias; WebBoardDialog/Application are caller/container routes rather than source owners; aggregate formal C++ would duplicate future child pages and mix source with compiler data.

## IDA Rename / Type / Comment Recommendations

Do not require IDA renames as part of this verification callback. If a later supervisor callback permits support synchronization, prefer source-facing documentation names already used here: `BrowserControlPane::QueryInterface`, `BrowserControlPane::Invoke`, `BrowserControlPaneChildWndProc`, `BrowserControlPaneRawChildWndProcClone`, `BrowserControlPaneTranslateAcceleratorMessage`, COM view fields at `+0x108..+0x118`, and state/global names from the Field And Type Names and Active Browser Globals sections. Keep IDA raw names visible only as evidence anchors where needed.

## First-Draft C++ Recommendation

Aggregate-level formal C++ should be deferred.

Target-specific no-code/defer proof:

- The target is not one function; it contains constructor/destructor, independent helper methods, raw helper islands, multiple COM interface method clusters, a dispatch `Invoke`, a registered stdcall WndProc, a raw no-route WndProc clone, and compiler metadata.
- The target currently has no child by-memory pages for those source functions. A monolithic `[[RECONSTRUCTION_CPP]]` block would either be artificial or would duplicate child methods after the necessary split.
- Compiler-generated EH starts inside `NavigateBrowser` and switch/jump-table data after accelerator/dispatch/WndProc bodies must not enter formal C++.
- COM stubs should be emitted with standard interface method names and exact HRESULT/body behavior after method-level or cluster child pages exist. The `0x004710xx`/`0x004708xx` shared thunks are outside this target and should not be copied into this target's source block.

Eligible child C++ after split:

- Constructor, destructor, `ShutdownBrowser`, `SetBrowserActiveState`, `NavigateBrowser`, document cookie helpers, browser surface/blit helpers, `BrowserControlPaneTranslateAcceleratorMessage`, `QueryInterface`, compact COM stub clusters, `Invoke`, and `BrowserControlPaneChildWndProc`.
- Raw no-route clone `0x0046ced0` should remain no-code or get an explicit raw-retained helper draft only if the implementation policy permits source for no-route retained clones. Current best recommendation: document, do not emit.

Recommended formal C++ state for [UID:0000Z6] until split: leave the aggregate `RECONSTRUCTION_CPP CODE` block blank and document child split as required before C++ emission. No sample, illustrative, body-only, or marker-replacing aggregate C++ should be added by this report.

## Final Recommendation

READY for supervisor execution after callback verification. The accepted disposition is preserved/current `88/92`, Browser owner/emitter, aggregate no-code, MCP-backed evidence, and same-or-greater detail validation rather than broad by-* rewrites. No by-* documentation edit was required.

## Recommended Target Doc Changes

Callback verification result for [UID:0000Z6]: the target already contains these accepted details at same-or-greater factual detail, so no target edit was required.

- Verify metadata score remains `COMPLETION: 88`, `CONFIDENCE: 92`, keep `RECONSTRUCTABLE: TRUE`, keep `CANONICAL_OWNER: 0000HV`, keep `EMITTER_UIDS: 0000HV`; this is already the current target state.
- Add this report path to the target notes/evidence section.
- Replace raw `sub_`/`FUN_` names in the target inventory with the source-facing names from this report.
- Add the COM interface map, including object offsets `+0x108` through `+0x118`, QueryInterface GUID mapping, and standard slot names for `IOleClientSite`, `IOleInPlaceSite`, `IDispatch`, `IDocHostUIHandler`, and `IDocHostShowUI`.
- Add field/type recommendations for `m_browserHostHwnd`, `m_webBrowser`, `m_webBrowserEventsCookie`, `m_allowedUrlPrefix`, `m_navigationTimeoutMillis`, `m_topLevelDispatchCookie`, cursor/active/defer bytes, and reserved state bytes.
- Clarify active globals: `g_activeBrowserControlPane`, `g_activeBrowserPane`, `g_pApplication`, `g_pScreenPane`/`dword_67A7CC`, `dword_67A740`, `dword_67ABA4`, and GUID constants.
- Update the WndProc section to state that `0x0046cd00` is registered and `0x0046ced0` is a raw no-route clone; keep switch metadata separate.
- Add explicit split recommendation and keep formal C++ blank on the aggregate pending child pages.
- Close existing open questions rather than leaving generic "needs investigation" language.
- Do not edit `by-memory/-coverage-report.md` except under supervisor callback.

## Recommended Support Doc Changes

Callback verification result: these support destinations already contain the accepted details at same-or-greater factual detail, or the row is explicitly supervisor-owned/excluded. No support doc edit was required.

- `by-class/BrowserControlPane.md`: add field layout, COM interface views, final helper names, WndProc registered/raw split, active global use, and aggregate/no-code split decision.
- `by-file/Browser.md`: update Browser source placement with BrowserControlPane COM host shape; distinguish newer BrowserControlPane from BrowserWindow and legacy/old browser host paths; keep current Browser.cpp emitter route.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: label BrowserControlPane vtable slices `0x006134f0`, `0x00613518`, `0x00613558`, `0x00613578`, `0x006135c4` with the COM interface names and slot starts from this report.
- `by-memory/0x00631580-0x00631660.BrowserComGuidConstants.md` and `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`: no ownership change required; optionally add cross-reference that [UID:0000Z6] QueryInterface consumes the specific IID/CLSID constants.
- `by-type/by-enum/BrowserDispatchEventId.md`: add the refined BrowserControlPane `Invoke` behavior for events `104`, `250`, `251`, `252`, `259`, `263`, and `270`.
- `by-global/g_activeBrowserControlPane.md` and `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`: add `BrowserControlPaneTranslateAcceleratorMessage` and constructor/destructor/shutdown relationships.
- `by-global/g_activeBrowserPane.md` and `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`: add that constructor stores the owner pane and dispatch/accelerator helpers use it for close/command callbacks; no clear xref found in this target.
- `by-global/g_browserRuntime.md`: keep ignored/alias status; do not reintroduce as Browser-owned runtime for this target.
- `by-memory/-ignored.md`: if supervisor permits, refine the existing `0x0046cfe0-0x0046d050` ignored row to name the raw clone switch table/padding and, if child split is performed, add ignored rows for internal metadata bands `0x0046c65a-0x0046c670`, `0x0046caf0-0x0046cbc0`, and `0x0046ce55-0x0046ced0`.
- `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`: note that `0x00471004`, `0x0047100e`, `0x00471018`, `0x00471022`, and `0x004708xx` entries are shared COM adjustor/AddRef/Release thunks used by BrowserControlPane interface views.
- Sibling WndProc pages (`BrowserWindowHostWndProc`, `BrowserRawWindowProcClone`, and `BrowserLegacyHostWndProc`): no required edits, but Browser.md should distinguish all three host WndProc families.

## Score And Metadata Recommendation

Recommended/current target metadata:

- `COMPLETION: 88`
- `CONFIDENCE: 92`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000HV`
- `EMITTER_UIDS: 0000HV`
- Formal C++: blank/deferred on aggregate pending child split.
- Source owner: Browser.
- Source path/emitter: `auto-generated/NexusTK/browser/Browser.cpp`.
- Reconstruction readiness: method-level child pages eligible; aggregate source block deferred.

Rationale for `88/92`: COM interface identity, source owner, WndProc split, switch metadata, active globals, dispatch event semantics, and helper names are substantially resolved. Remaining confidence loss is limited to exact user-facing names for the raw `+0x330/+0x331` state bytes and exact render-surface type names for raw blit helpers.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit `by-memory/-coverage-report.md` during this callback. If the supervisor later refreshes coverage/tracker text, use or update the UID0000Z6 row with:

```text
    - [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) 0x0046b520-0x0046cfe0 | class aggregate | BrowserControlPaneCore : reconstructable : 88% : very strong : B010 2026-06-19 source-quality reanalysis keeps Browser owner/emitter [UID:0000HV] and confirms the aggregate as the newer BrowserControlPane COM/OLE WebBrowser host core: constructor registers `Nexon.Baram.Browser` with registered `BrowserControlPaneChildWndProc` at `0x0046cd00`, creates the child HWND, CoCreates `CLSID_WebBrowser`, QIs `IID_IWebBrowser2`, advises `DIID_DWebBrowserEvents2`, and optionally navigates through `NavigateBrowser`; destructor/shutdown clear active state, unadvise events, stop/quit/release the WebBrowser, destroy the child HWND, and restore focus; raw helper islands are best-named as refresh-state, allowed-URL-prefix, navigation-timeout/reserved-state, document-cookie get/set, and raw blit helpers; QueryInterface maps `IOleClientSite`, `IOleWindow`/`IOleInPlaceSite`, `DWebBrowserEvents2`/`IDispatch`, `IDocHostUIHandler`, and `IDocHostShowUI` views; dispatch handles DISPIDs 104, 250, 251, 252, 259, 263, and 270 with URL/cookie/cancel/active-state behavior; active globals resolve to `g_activeBrowserControlPane`, `g_activeBrowserPane`, and existing `g_pScreenPane` alias use rather than separate browser-runtime storage; `0x0046cd00` is the registered child WndProc while `0x0046ced0` remains a retained raw no-route clone; switch metadata at `0x0046c65a-0x0046c670`, `0x0046caf0-0x0046cbc0`, `0x0046ce55-0x0046ced0`, and post-target `0x0046cfe0-0x0046d050` must stay compiler-generated/ignored. Keep aggregate C++ blank pending method-level child split; emit first-draft C++ only on exact child method/callback pages after split.
```

Optional adjacent ignored row replacement if supervisor refreshes switch metadata wording:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0046cfe0-0x0046d050 | switch table/padding | BrowserControlPane raw child-window switch data : ignored : 100% : strong : Compiler-generated jump table, byte selector table, NOP/alignment, and trailing `0xcc` padding after the retained raw BrowserControlPane child-window message handler at [UID:0000Z6]; not source and not part of WebBoardDialog.
```

## Validator Results

No scoped by-* validator command was run during the implementation/verification callback because no by-* documentation file was edited. The archived report contained the historical read-only scoped baseline below; it is preserved as prior evidence only and is not a new command result from this callback.

Historical command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000Z6-BrowserControlPaneCore-source-quality-removed.md](0000Z6-BrowserControlPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`. Key exact direct-scope lines:

```text
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: False
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 0003ZT
autogen_children_fallback_insert: 1
autogen_children_marker_missing: 2
autogen_cpp_conflict: 5
autogen_cpp_noop: 271
autogen_emitter_has_no_code: 597
autogen_registry_rebuild: 1
autogen_report_noop: 7
ok: 1
stats_incremental_skip: 1
ok           0000Z6 by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md UID header exists
stats_incremental_skip 0000Z6 project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The validator baseline was read-only/dry-run. It did not edit the target, any by-* documentation, generated code, or coverage files.

## Open Questions With Attempted Resolution

- COM interface slots/helpers: closed with standard OLE/WebBrowser interface map above.
- Compiler/generated names: switch metadata and EH starts identified; adjustor thunks attributed to Browser OLE helper support.
- Caller/reachability: direct callers and vtable/data refs listed; raw no-route functions explicitly marked.
- Owner/source placement: Browser/[UID:0000HV]/Browser.cpp retained; alternatives rejected.
- WndProc promoted/raw split: closed; `0x0046cd00` registered, `0x0046ced0` raw retained clone.
- Active browser globals: `g_activeBrowserControlPane` and `g_activeBrowserPane` accepted; `g_browserRuntime` alias rejected.
- Raw property/helper islands: best-supported names assigned; `+0x330/+0x331` closed as reserved state byte setters due lack of read evidence.
- C++ readiness: aggregate no-code/defer proof supplied; child-level first-draft C++ recommended after split.

## Changed Files

This implementation/verification callback changed only this report file: `tools/leaser/Agents/Agent-B010/research/0000Z6-BrowserControlPaneCore-source-quality.md`.

No by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or registry state were edited. No leases were acquired because no by-* edit was needed.

## Implementation Tracking Checklist

- [x] Added required `** TARGET-REPORT-UID:0000Z6 **` header and preserved validator-owned lifecycle history comments.
- [x] Preserved `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`.
- [x] Repaired stale current-state wording: live target metadata is `88/92`; archived `84/90` references are labeled historical/pre-callback context.
- [x] Added current MCP evidence from `supervisor_recovery_20260705`, including health/session state, function inventory, xrefs, byte checks, pointer negatives, QueryInterface, Invoke, and registered WndProc.
- [x] Normalized report headings to the current B-agent report shape without discarding valid prior source-quality research.
- [x] Repaired Claim And Incorporation Ledger with claim IDs, confidence, evidence, exact destination docs/sections, actions, and verification states.
- [x] Preserved aggregate no-code proof and clarified that no sample/illustrative aggregate C++ is recommended.
- [x] Relabeled old coverage quote as historical and excluded manual coverage/generated/tracker edits.
- [x] Gate 1 passed at SHA256 `D0C768B973761BDA6053F4C3899A91C522261030C3EC59C76309FEAF7E40F3F8`.
- [x] Verified Z6-001 in this report: target UID header present, top status-lock headers removed by supervisor override, validator-history footer preserved unchanged.
- [x] Verified Z6-002 already present in target metadata: `88/92`, Browser owner/emitter, reconstructable, blank aggregate formal C++.
- [x] Verified Z6-003 already present across target/class/file docs: Browser owner/emitter/source route retained and WebBoardDialog/Application/new required file route rejected.
- [x] Verified Z6-004 already present: aggregate no-code proof and child-page-only C++ policy in target/class docs.
- [x] Verified Z6-005 already present/excluded: target range and split notes retain `0x0046b520-0x0046cfe0`; `by-memory/-ignored.md` owns `0x0046cfe0-0x0046d050`; manual coverage/generated edits excluded.
- [x] Verified Z6-006 already present: registered `0x0046cd00` WndProc and raw no-route `0x0046ced0` clone in target/class/file docs.
- [x] Verified Z6-007 already present: COM view offsets/vtables/QueryInterface identities in target/class/vtable/GUID docs.
- [x] Verified Z6-008 already present: BrowserControlPane `Invoke` cases and behavior in target and `BrowserDispatchEventId.md`.
- [x] Verified Z6-009 already present: active global roles and `g_browserRuntime` rejection in target/global/storage docs.
- [x] Verified Z6-010 already present: target child split plan and no aggregate C++ policy; future child creation not part of this callback.
- [x] Verified Z6-011 excluded with reason: generated, coverage, validator state, lifecycle/archive, and supervisor-owned tracker/ledger files were not edited.
- [x] Scoped validators not run because no by-* docs changed; therefore no validator command IDs/timestamps apply for this callback.

## Follow-Up Actions

Supervisor execution is the next action. Future child split work remains separate from this report execution and should create exact method/callback pages before any formal C++ body is emitted.

## Confidence

High. Current confidence is grounded in live MCP evidence plus already-incorporated by-* documentation. Remaining uncertainty is limited to exact human source file split and non-user-visible names for a few raw state bytes/render-surface helper types, which do not change the owner, range, no-code aggregate policy, or current `88/92` metadata.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006840","destination_path":"tools/leaser/Agents/Agent-B010/research/0000Z6-BrowserControlPaneCore-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md","timestamp":"2026-07-05T06:29:10-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006851","destination_path":"executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000Z6-BrowserControlPaneCore-source-quality.md","timestamp":"2026-07-05T06:51:53-04:00","uid":"0000Z6"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000Z6-BrowserControlPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000Z6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
