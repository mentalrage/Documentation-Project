** TARGET-REPORT-UID:00020V **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00020V-00020W BrowserWindow WndProc / Raw Clone Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: Gate 1 passed and the implementation/verification callback is complete. Keep [UID:00020V] `BrowserWindowHostWndProc` as the emitted registered BrowserWindow host WndProc at `86/90`, owner/emitter [UID:0000HV] Browser, with its existing formal `static LRESULT CALLBACK BrowserWindowHostWndProc(...)` C++ intact. Keep [UID:00020W] `BrowserRawWindowProcClone` as Browser-owned reconstructable but non-emitting retained raw code at `86/91`, blank `EMITTER_UIDS:`, and blank formal C++.
- Final disposition: [UID:00020V] is the live registered callback loaded into `WNDCLASSA.lpfnWndProc`; [UID:00020W] is a source-shaped raw clone with no current function object, decompile route, xrefs, or pointer-pattern hits. The two pages are related BrowserWindow-family evidence but should not both emit callback C++.
- Required action: supervisor Gate 2 / execute review. The only concrete target-doc repair accepted in callback, the stale [UID:00020V] `Item Summary` phrase saying final C++ remains blank, was applied; support docs were verified already present at same-or-greater detail and intentionally left unchanged.
- Confidence: high for [UID:00020V] registration/source shape and Browser owner route; high for [UID:00020W] current non-emitting/no-code disposition; medium for the original reason the raw clone remains in the binary.

## Supporting Research

- Assignment source: Agent-B009 `goal.md`, same-report revalidation repair for `tools/leaser/Agents/Agent-B009/research/00020V-00020W-BrowserWindowWndProcClone-source-quality.md`.
- Historical lifecycle: validator command `000000004167` marked the previously executed B009 report `needs-revalidation` for `target_header_missing`; validator command `000000006839` returned it from `executed-b-agent-research/B009/` to the active B009 research path for repair. Those events remain only as validator-owned history comments below.
- Current report status: supervisor narrow override for this de-executed active research copy authorized removing the top-level `REPORT-VALIDATION-STATUS: needs-revalidation` and `REPORT-REVALIDATION-REASON: target_header_missing` lines so this active repair artifact could receive Gate 1 review. Gate 1 has passed for this artifact, and the implementation/verification callback is now applied. The same prior status and reason remain historical here and in the validator-owned history footer. B009 did not run lifecycle, registry, archive, move, dry-run, or `execute_report` commands.
- Current MCP correction: the older report body said live MCP was unavailable. That is now superseded. On 2026-07-05, direct JSON-RPC against `http://127.0.0.1:13337/mcp` initialized successfully, `tools/list` returned schema-current tools, and the active session `supervisor_recovery_20260705` provided the bounded evidence recorded below.
- Scope boundary: initial Gate 1 repair was report-only. During the Gate1-passed implementation callback, B009 edited only the authorized [UID:00020V] target page and this report; validator command `000000006850` updated `project-level/-auto-completion-stats.md` as a tool side effect and left generated refresh deferred. No support by-* docs, generated files, manual coverage reports, validator state, queue/lock files, supervisor ledgers, lifecycle/archive files, or report-history comments were manually edited.

## Target

- Primary target UID: `00020V`
- Primary target path: `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`
- Secondary in-scope target UID: `00020W`
- Secondary target path: `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`
- Related support paths checked: `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`, `by-global/g_browserWindowClassName.md`, and `by-memory/-ignored.md`.
- Generated state checked as read-only context: `auto-generated/-ag-memory-coverage.md` lists [UID:00020V] as `coded` through `auto-generated/NexusTK/browser/Browser.cpp` and [UID:00020W] as `non-emits`; `auto-generated/-ag-research-tracker.md` currently has no counted B009 execution for [UID:00020V] because supervisor execution has not yet run after this revalidation callback, while [UID:00020W] has the later B010 executed report.

## Current Target State

- [UID:00020V] current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, blank `EMITTER_POSITION_OPTIONAL`.
- [UID:00020V] current formal C++: populated as `static LRESULT CALLBACK BrowserWindowHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)`, with the `GWL_USERDATA` guard, `WM_PAINT` `BeginPaint`/`EndPaint`, `WM_SYSCOMMAND` suppression for `SC_SIZE`, `SC_MOVE`, `SC_MINIMIZE`, `SC_MAXIMIZE`, `SC_CLOSE`, and `DefWindowProcA` fallback.
- [UID:00020V] current documentation gap resolved in callback: the `Item Summary` no longer says "final C++ remains blank" and now reflects the populated file-static formal C++ as `BrowserWindowHostWndProc`. The formal C++ block and metadata were preserved unchanged.
- [UID:00020W] current metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- [UID:00020W] current state supersedes the old B009 report's `85/90` and nonblank-emitter wording. B010's 2026-06-28 implementation finalized the page as Browser-owned non-emitting retained raw WndProc clone evidence, not a second source emitter.
- Support docs are current: `Browser.md` and `BrowserWindow.md` distinguish [UID:00020V] as the live emitted callback and [UID:00020W] as a non-emitting retained raw duplicate; `g_browserWindowClassName.md` supports the `"Baram.Browser.Window"` registration context; `by-memory/-ignored.md` owns the generated switch/table/padding ranges.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / score impact |
| --- | --- | --- | --- |
| Missing target report header | Current repaired report, `goal.md`, validator history reason `target_header_missing`. | Add `** TARGET-REPORT-UID:00020V **` as the primary report target header while preserving B009/xHigh provenance and validator history comments. | Reject changing the target UID to `00020W`; [UID:00020W] is secondary in scope and already has separate B010 coverage. |
| Stale MCP-unavailable current truth | Current JSON-RPC `initialize`, `tools/list`, `idb_list`, `server_health`, bounded `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, and `decompile`. | Historicalize the old MCP-unavailable statement. Current MCP is healthy and reconfirms the registration/no-route split. | Reject fallback-only repair; current MCP evidence is now available and mandatory. |
| `sub_46A630` source name | Current decompile of `0x0046a630`, constructor xref/pointer hit at `0x00469758/0x0046975e`, support docs, Browser source route. | Keep inferred/descriptive source-facing name `BrowserWindowHostWndProc` as a file-static Browser helper. | Reject generic `WndProc`; reject `BrowserRawWindowProcClone`; reject class-static method syntax because there is no `this`, no vtable slot, and no dereference of `GWL_USERDATA`. |
| Registered callback versus raw clone | Current `lookup_funcs`, `xrefs_to`, `find_bytes`, decompile success for `0x0046a630`, decompile failure for `0x0046a760`. | [UID:00020V] emits; [UID:00020W] documents raw source-shaped evidence but does not emit. | Reject modeling [UID:00020W] as the live registered callback; no current route points at `0x0046a760`. |
| `GWL_USERDATA` type/dispatch | Decompile of `sub_46A630` checks `GetWindowLongA(hWnd, -21)` and then handles messages directly. | Treat it as a readiness/association gate, not an object dispatch. | Reject inventing `BrowserWindow *self` or a virtual/instance handler call. |
| Message semantics and switch values | Decompile of `sub_46A630`; current bytes for [UID:00020W] selector table; target/support docs; prior `int_convert.py` conversions. | `WM_PAINT` returns `0` after paint validation; `WM_SYSCOMMAND` consumes `0xf000`, `0xf010`, `0xf020`, `0xf030`, and `0xf060`; other messages delegate. | Reject stale `0xf100/0xf200/0xf300/0xf600` wording as byte-offset confusion. Current docs have mostly corrected it. |
| Raw clone source quality | Current bytes at `0x0046a760`, jump table `0x0046a7ec`, selector table `0x0046a7f4`, padding `0x0046a855`, no function/decompile/xref/pointer route. | Keep [UID:00020W] reconstructable as source-authored evidence but non-emitting due to no route. | Reject folding into padding; reject a synthetic formal C++ clone; reject covered-by marker because [UID:00020W] lacks [UID:00020V]'s `GWL_USERDATA` gate. |
| Source placement | `Browser.md`, `BrowserWindow.md`, `g_browserWindowClassName.md`, current generated coverage, prior B009/B010 reports. | Keep direct route through [UID:0000HV] `Browser` / `NexusTK/browser/Browser.cpp`; allow future `browser/BrowserWindow.cpp` split only as broader source-tree work. | Reject PlatformApi/windowing, BrowserThread legacy WndProc, BrowserPane/BrowserControlPane child WndProc ownership, and WebBoard/Dialog ownership. |
| Current target mismatch | [UID:00020V] header/body versus stale `Item Summary`. | Callback applied only the [UID:00020V] `Item Summary` wording repair so it reflects populated formal C++ as `BrowserWindowHostWndProc`. | No score/metadata/formal-C++ change was needed; support docs remained unchanged because they already carried same-or-greater detail. |

## Evidence Standards Used

- Direct IDA MCP facts: current session identity/health, exact function lookup, decompile success/failure, xrefs, raw bytes, pointer-pattern byte search, and tool schema from `tools/list`.
- Documentation evidence: current target pages, Browser and BrowserWindow support pages, BrowserWindow constructor/core page, browser class-name global, ignored-range ledger, generated memory coverage, generated research tracker, and relevant executed B reports.
- Inference evidence: source-facing name and file placement are inferred from registration, message behavior, source-family context, and Browser module routing, not original symbol recovery.
- Negative evidence: zero current xrefs and zero pointer-pattern hits to `0x0046a760`; no IDA function/decompile route for the raw clone; no vtable/instance method signal for the registered WndProc.
- Tool limitations: current MCP gives strong route evidence but not original source file names. Exact `Browser.cpp` versus `BrowserWindow.cpp` remains a source-placement caveat rather than a blocker for current owner/emitter routing.

## Evidence Checked

- MCP availability and schema: `initialize` succeeded; `tools/list` returned schema-current `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, and `decompile`.
- MCP session: `idb_list` returned one active adopted worker session `supervisor_recovery_20260705`, `NexusTK.exe.i64`, PID/worker PID `19604`, not analyzing. `server_health` returned `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.
- MCP function lookup: `lookup_funcs` returned `sub_46A630` at `0x0046a630`, size `0xba`; `0x0046a6ea`, `0x0046a760`, `0x0046a855`, and `0x0046a860` are not functions.
- MCP decompile: `decompile 0x0046a630` returned the WndProc body with `GetWindowLongA(hWnd, -21)`, `WM_PAINT`, `WM_SYSCOMMAND`, consumed cases `0xF000/0xF010/0xF020/0xF030/0xF060`, and `DefWindowProcA`; `decompile 0x0046a760` failed because there is no function object.
- MCP xrefs and pointer bytes: `xrefs_to 0x0046a630` returned one data xref at `0x00469758` in `sub_469640`; `xrefs_to 0x0046a760`, `0x0046a855`, and `0x0046a860` returned zero. `find_bytes` found `30 A6 46 00` at `0x0046975e`, found zero matches for `60 A7 46 00`, and found zero matches for `60 A8 46 00`.
- MCP bytes: `get_bytes 0x0046a760 size 16` returned the raw prologue bytes beginning `55 8b ec 83 ec 44`; `get_bytes 0x0046a7ec size 8` returned jump-table dwords to `0x0046a7d9` and `0x0046a7a6`; `get_bytes 0x0046a7f4 size 97` returned selector bytes with zero entries at offsets `0`, `0x10`, `0x20`, `0x30`, and `0x60`; `get_bytes 0x0046a855 size 11` returned eleven `0xcc` bytes.
- Current target/support docs read: [UID:00020V], [UID:00020W], [UID:0000HV] Browser, [UID:00001B] BrowserWindow, [UID:0000Z4] BrowserWindowCore, [UID:0000PV] `g_browserWindowClassName`, and `by-memory/-ignored.md`.
- Generated read-only state checked: `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-research-tracker.md`.
- Old reports searched with `rg` terms `00020V`, `00020W`, `BrowserWindowHostWndProc`, `BrowserRawWindowProcClone`, `0x0046a630`, and `0x0046a760`. Relevant leads: executed B010 `00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md`, executed B010 `000333-BrowserLegacyHostWndProc-source-quality.md`, executed B001 `00020U-browser-accelerator-source-quality.md`, and the current repaired B009 report history.
- Wave2/Wave3 mentions in existing support docs were treated as historical generated leads only and not used as authority over current MCP/by-* evidence.
- Failed/skipped checks: no broad listing, full-image disassembly, callgraph, type-batch analysis, lifecycle command, validator command, or IDA write was run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| 20V20W-C01 | The report must carry primary target header `** TARGET-REPORT-UID:00020V **` and preserve B009/xHigh provenance. | High | Report header now carries `TARGET-REPORT-UID:00020V`, `AUTHOR-AGENT-ID:B009`, and `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`; validator history remains footer-only. | Report header | incorporate | applied |
| 20V20W-C02 | Current MCP is available via `supervisor_recovery_20260705`; the old MCP-unavailable statement is stale. | High | Report Supporting Research/Evidence Checked records JSON-RPC initialize/tools/list, `idb_list`, and `server_health` for `supervisor_recovery_20260705`; old `needs-revalidation`/MCP-unavailable state is historicalized. | Report Supporting Research / Evidence Checked | historicalize | applied |
| 20V20W-C03 | [UID:00020V] is `sub_46A630` size `0xba`, registered through `WNDCLASSA.lpfnWndProc` at `0x00469758`, with pointer bytes at `0x0046975e`. | High | Already present: [UID:00020V] target records exact 0xba WndProc range and `0x00469758`; [UID:00020W], `Browser.md`, and `BrowserWindow.md` record the `0x00469758/0x0046975e` registered-sibling route. | Target/support docs already; report IDA facts | already-present | already-present |
| 20V20W-C04 | [UID:00020V] source-facing first-draft remains `static LRESULT CALLBACK BrowserWindowHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)`. | High | Already present: [UID:00020V] formal `RECONSTRUCTION_CPP CODE` block begins with the exact static callback signature and contains the documented WndProc behavior. | Target formal C++ | already-present | already-present |
| 20V20W-C05 | [UID:00020V] target `Item Summary` had stale wording that said final C++ remains blank. | High | Applied: leased [UID:00020V], replaced only the stale `Item Summary` clause with populated file-static formal C++ wording, preserved metadata/formal C++, validated with command `000000006850`, and released the lease. | Target Item Summary | incorporate | applied |
| 20V20W-C06 | [UID:00020W] is not an IDA function/decompile target and has no current xrefs or pointer-byte hits at `0x0046a760`. | High | Already present: [UID:00020W] target records no function/decompile route, no xrefs, and zero data-ref/immediate/pointer hits for `0x0046a760`; support docs distinguish the registered sibling. | Target already; report IDA facts | already-present | already-present |
| 20V20W-C07 | [UID:00020W] selector table consumes command classes `0xf000`, `0xf010`, `0xf020`, `0xf030`, and `0xf060`; stale `0xf100`-style command wording is rejected. | High | Already present: [UID:00020W] Item Summary/evidence and `Browser.md`/`BrowserWindow.md` support text record the corrected selector commands and reject old byte-offset confusion. | Target already; support already | already-present | already-present |
| 20V20W-C08 | [UID:00020W] current metadata is `86/91`, owner [UID:0000HV], reconstructable true, blank emitter, blank formal C++; older B009 `85/90`/emitter wording is superseded. | High | Already present: [UID:00020W] header carries `86/91`, [UID:0000HV], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, and blank formal C++; its B010 section states the older `85/90`/emitter state was changed/superseded. | UID00020W target header/body and report current-state sections | historicalize | already-present |
| 20V20W-C09 | Support docs already distinguish [UID:00020V] as the live emitted callback and [UID:00020W] as non-emitting retained raw duplicate. | High | Already present: `by-file/Browser.md` records [UID:00020V] as registered/emitted and [UID:00020W] as non-emitting retained raw duplicate; `by-class/BrowserWindow.md` says [UID:00020W] is not a second callable callback/method. | Recommended Support Doc Changes | already-present | already-present |
| 20V20W-C10 | Keep source route through [UID:0000HV] Browser / `NexusTK/browser/Browser.cpp`; do not move to BrowserWindow as direct owner unless later source split evidence appears. | High | Already present: [UID:00020V]/[UID:00020W] target metadata, `Browser.md`, and `BrowserWindow.md` keep [UID:0000HV] Browser as the direct source root while preserving `BrowserWindow.cpp` only as an unproven future split. | Target/support docs already; report ownership/source sections | already-present | already-present |
| 20V20W-C11 | No manual generated, coverage, validator-state, lifecycle/archive, or supervisor-ledger edit is part of this callback. | High | Excluded with reason: B009 manually edited only the authorized target page and this report, did not run `execute_report` or lifecycle commands, and did not manually edit generated/coverage/state/ledger files; scoped validator `000000006850` reported `projected_stats_update: 1` and `generated_refresh: deferred` as tool side effects. | Changed Files / Checklist | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Current MCP directly proves [UID:00020V] is a modeled function and [UID:00020W] is not.
- The only current xref/pointer route among the pair targets `0x0046a630`, at the BrowserWindow constructor's `WNDCLASSA.lpfnWndProc` assignment.
- Current decompilation of `sub_46A630` matches the target's formal C++ shape: user-data gate, paint validation, selected `WM_SYSCOMMAND` suppression, and `DefWindowProcA` fallback.
- Current raw bytes at `0x0046a760`, `0x0046a7ec`, and `0x0046a7f4` prove [UID:00020W] is source-shaped retained WndProc-like code, not padding.
- Current support docs already carry the Browser source root, BrowserWindow host callback relationship, class-name evidence, and raw-clone distinction at same-or-greater detail.

## IDA MCP Facts

- Function facts: `lookup_funcs` reports `sub_46A630` at `0x0046a630`, size `0xba`; `0x0046a6ea`, `0x0046a760`, `0x0046a855`, and `0x0046a860` are not functions.
- Decompile facts: `decompile 0x0046a630` succeeds with `LRESULT __stdcall sub_46A630(HWND, UINT, WPARAM, LPARAM)` and the expected Win32 message behavior; `decompile 0x0046a760` fails because no function object exists.
- Xref facts: `xrefs_to 0x0046a630` returns one data xref at `0x00469758` in `sub_469640`; `xrefs_to 0x0046a760`, `0x0046a855`, and `0x0046a860` return zero.
- Pointer-pattern facts: `find_bytes` finds the little-endian `0x0046a630` bytes at `0x0046975e`; corresponding patterns for `0x0046a760` and `0x0046a860` return zero matches.
- Byte/table facts: [UID:00020W] starts with a raw function prologue, has two jump-table dwords at `0x0046a7ec`, 97 selector bytes at `0x0046a7f4`, and eleven `0xcc` bytes at `0x0046a855-0x0046a860`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046a630-0x0046a6ea` | [UID:00020V] `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md` | Registered BrowserWindow host WndProc body | TRUE | [UID:0000HV] Browser | current/recommended `86/90` | Formal C++ populated; stale Item Summary phrase should be repaired later |
| `0x0046a6ea-0x0046a760` | [UID:0000VN] `by-memory/-ignored.md` | Compiler switch/table/padding after [UID:00020V] | FALSE standalone | ignored ledger | N/A | No source page needed |
| `0x0046a760-0x0046a855` | [UID:00020W] `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md` | Retained raw WndProc clone plus local tables | TRUE as documentation, non-emitting | [UID:0000HV] Browser | current/recommended `86/91` | Blank `EMITTER_UIDS:` and blank formal C++ |
| `0x0046a855-0x0046a860` | [UID:0000VN] `by-memory/-ignored.md` | Alignment after raw clone | FALSE | ignored ledger | N/A | No source page needed |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00469758` | current `xrefs_to 0x0046a630` data xref in `sub_469640` | Proven BrowserWindow constructor registration of [UID:00020V]. |
| `0x0046975e` | current `find_bytes 30 A6 46 00` hit | Little-endian pointer bytes for `0x0046a630` in the same registration site. |
| `0x0046972a` | documented xref to `"Baram.Browser.Window"` | Browser host class-name setup path. |
| `0x0046a647` | decompiled `GetWindowLongA(hWnd, -21)` | `GWL_USERDATA` readiness/association gate in [UID:00020V]. |
| `0x0046a6c6` / `0x0046a6d1` | `BeginPaint` / `EndPaint` | [UID:00020V] paint validation. |
| `0x0046a760` | zero current xrefs, zero pointer-byte hits, decompile failure | [UID:00020W] has no proven live route. |
| `0x0046a7ec` / `0x0046a7f4` | local raw clone jump/selector table bytes | Internal compiler switch machinery for [UID:00020W]. |

## Documentation Evidence And IDA Status

- [UID:00020V] target page already records the WndProc behavior, Browser owner/emitter, formal C++ body, constructor xref, imports, switch boundary, and B009 source-quality reasoning.
- [UID:00020V] callback repair: the stale `Item Summary` phrase that said final C++ remains blank was replaced with wording that says the file-static formal C++ is populated as `BrowserWindowHostWndProc`; the surrounding target body and formal C++ block were already current.
- [UID:00020W] target page already records current B010 non-emitting disposition, `86/91`, blank emitter, blank formal C++, no-function/no-xref/no-pointer evidence, selector command values, and raw body/table/padding layout.
- [UID:0000HV] Browser already records B009/B010 distinction between emitted [UID:00020V] and non-emitting [UID:00020W], plus the broader Browser source-root route.
- [UID:00001B] BrowserWindow already lists [UID:00020V] as registered host procedure and [UID:00020W] as non-emitting retained raw clone.
- [UID:0000PV] `g_browserWindowClassName` already documents `"Baram.Browser.Window"` as a class-name string used in `WNDCLASSA.lpszClassName`, `RegisterClassA`, and `CreateWindowExA`.
- Generated coverage is current for the target dispositions: `auto-generated/-ag-memory-coverage.md` lists [UID:00020V] as `coded` and [UID:00020W] as `non-emits`.

## Ranked Ownership Analysis

### 1. [UID:0000HV] Browser

- Evidence for: current target metadata, generated route `auto-generated/NexusTK/browser/Browser.cpp`, Browser source root, BrowserWindow support docs, browser host window-class string, and neighboring browser WndProc/helper cluster.
- Evidence against: exact original source split could have used a narrower `browser/BrowserWindow.cpp`, but current project route treats Browser as the source root for this family.
- Decision: keep current owner/emitter route for [UID:00020V]; keep [UID:00020W] Browser-owned but non-emitting.

### 2. [UID:00001B] BrowserWindow

- Evidence for: [UID:00020V] is assigned from the BrowserWindow constructor and is BrowserWindow-specific host-window behavior.
- Evidence against: WNDPROC is a free/static callback signature, does not receive implicit `this`, has no vtable slot, and does not dereference `GWL_USERDATA` into an instance handler. Current metadata routes through Browser file root rather than BrowserWindow class owner.
- Decision: support/context owner only. Do not change `CANONICAL_OWNER` to BrowserWindow.

### 3. BrowserThread legacy host / BrowserPane / BrowserControlPane / generic PlatformApi

- Evidence for: these areas also contain WndProc-like callback patterns in the browser subsystem.
- Evidence against: BrowserThread legacy host WndProc is separate [UID:000333] at `0x0046fcb0`; BrowserPane begins after `0x0046a860`; BrowserControlPane WndProc family is later around `0x0046cd00`/`0x0046ced0`; PlatformApi is dependency/import context, not the BrowserWindow source owner.
- Decision: rejected for [UID:00020V] and [UID:00020W].

### Proposed new file/grouping

- Proposed owner/name/path: no new owner file in this callback/report. Continue current [UID:0000HV] route through `NexusTK/browser/Browser.cpp`.
- Likely full contents if future split occurs: BrowserWindow constructor/destructor/navigation/query/stub helpers, host WndProc [UID:00020V], accelerator helper [UID:00020U], DocHost stubs [UID:00020T], and related BrowserWindow COM adjustor glue.
- Candidate related items rejected from this pair's direct ownership: generic windowing/platform wrappers, BrowserThread legacy WndProc, BrowserControlPane child WndProc, and WebBoard/Dialog code.
- Standalone, narrow, or broad source-file inference: broad browser source root remains current; narrow `browser/BrowserWindow.cpp` is plausible but unproven.

## Source Placement

- Recommended source file/class/global/module placement: [UID:00020V] emits under the Browser source root, likely as a file-scope helper in `browser/Browser.cpp` or a future narrower `browser/BrowserWindow.cpp`; [UID:00020W] remains Browser-owned documentation-only source-shaped evidence with no emitted source.
- Why this placement fits: the registration occurs in BrowserWindow construction, the class-name global is browser-specific, current generated route is `NexusTK/browser/Browser.cpp`, and Browser support docs own the broader embedded browser subsystem.
- Rejected placements: BrowserWindow class-static method due to missing `this`/vtable/instance dispatch; BrowserThread due to separate legacy registration; BrowserPane/BrowserControlPane due to different ranges; generic PlatformApi/windowing due to dependency-only role.
- Remaining uncertainty: exact original one-file `Browser.cpp` versus split `BrowserWindow.cpp` cannot be proven from current IDA evidence. This does not block current owner/emitter route because [UID:0000HV] is the active Browser source root.

## Range / Split / Padding / Reclassification Analysis

- Keep [UID:00020V] half-open range `0x0046a630-0x0046a6ea`; current MCP confirms `sub_46A630` size `0xba`.
- Keep `0x0046a6ea-0x0046a760` in `by-memory/-ignored.md` as compiler switch/table/padding after [UID:00020V].
- Keep [UID:00020W] range `0x0046a760-0x0046a855` as raw clone body and local tables, not padding; current bytes confirm the raw prologue, jump table, selector table, and alignment boundary.
- Keep `0x0046a855-0x0046a860` in `by-memory/-ignored.md` as eleven `0xcc` alignment bytes.
- No split, merge, new child, ignored-range migration, or UID reclassification is recommended by this repair.

## Negative Evidence Summary

- Current MCP finds no function at `0x0046a760`, `0x0046a855`, or `0x0046a860`.
- Current MCP decompilation fails at `0x0046a760` because there is no function object.
- Current MCP finds zero xrefs to `0x0046a760`, `0x0046a855`, and `0x0046a860`.
- Current MCP byte-pattern search finds zero loaded little-endian pointer hits for `0x0046a760` and `0x0046a860`.
- [UID:00020W] lacks [UID:00020V]'s `GWL_USERDATA` gate, so it is not an exact covered-by duplicate of the formal [UID:00020V] body.
- Address adjacency and behavioral similarity do not prove registration, source symbol, or a second emitted callback route.
- No map/PDB/source file/runtime trace currently proves why the raw clone remains in the binary.

## First-Draft C++ Recommendation

[UID:00020V] is eligible and already carries the recommended formal C++ body. Preserve this exact source shape unless a future source audit finds a target-body mismatch:

```cpp
static LRESULT CALLBACK BrowserWindowHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (GetWindowLongA(hwnd, GWL_USERDATA) == 0) {
        return DefWindowProcA(hwnd, message, wParam, lParam);
    }

    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        BeginPaint(hwnd, &paint);
        EndPaint(hwnd, &paint);
        return 0;
    }

    case WM_SYSCOMMAND:
        switch (wParam & 0xfff0) {
        case SC_SIZE:
        case SC_MOVE:
        case SC_MINIMIZE:
        case SC_MAXIMIZE:
        case SC_CLOSE:
            return 0;
        default:
            break;
        }
        break;
    }

    return DefWindowProcA(hwnd, message, wParam, lParam);
}
```

[UID:00020W] is not eligible for formal C++. Exact no-code proof: current MCP and support docs show no function object, no decompile route, no xrefs, no pointer-byte hit, and no registration for `0x0046a760`; the live registered sibling is [UID:00020V] at `0x0046a630`; and [UID:00020W] is not an exact covered-by body because it lacks [UID:00020V]'s `GWL_USERDATA` gate. Therefore the current blank `EMITTER_UIDS:` and blank formal `RECONSTRUCTION_CPP CODE` block are correct.

## Final Recommendation

- Exact report repair applied: primary target report header added; existing B009/xHigh provenance preserved; validator history footer preserved; stale current MCP-unavailable language replaced with current MCP evidence; required Gate 1 headings normalized.
- Exact target/support implementation: do not change scores, owners, emitters, reconstructable flags, ranges, source placement, or formal C++ based on this callback. The only accepted target-doc cleanup, replacing the stale [UID:00020V] `Item Summary` phrase saying "final C++ remains blank" with populated file-static formal-C++ wording, was applied.
- Exact parent assignments recommended: keep [UID:00020V] owner/emitter [UID:0000HV]; keep [UID:00020W] owner [UID:0000HV] with blank emitter.
- Exact items left no-owner/non-emitting: [UID:00020W] is non-emitting, not no-owner; it remains Browser-owned documentation evidence.
- Exact future work outside this assignment: only future source/map/runtime evidence or a broader browser source-tree split pass could prove original `Browser.cpp` versus `BrowserWindow.cpp` or explain raw clone retention.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`
- Callback edit applied: updated only the `Item Summary` stale phrase from "final C++ remains blank" to wording that reflects the current formal C++ block is populated as `BrowserWindowHostWndProc`.
- Metadata/score/owner/emitter/reconstructable/C++ changes: none. Preserve `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, blank emitter position, and existing formal C++.
- Historical/stale assumptions to preserve as historical only: older "blank C++ pending final source naming/registration review" notes before B009 implementation are historical; they should not be presented as the current target state.

- Target path: `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`
- Callback edit: none. The current page already incorporates B009/B010 evidence at same-or-greater detail.
- Metadata/score/owner/emitter/reconstructable/C++ changes: none. Preserve `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, blank emitter position, and blank formal C++.
- Historical/stale assumptions to preserve as historical only: the old B009 report's `85/90` and nonblank-emitter wording is superseded by B010's accepted empty-emitter repair.

## Recommended Support Doc Changes

- `by-file/Browser.md`: no edit required in callback. It already states [UID:00020V] is the registered BrowserWindow host WndProc and [UID:00020W] is a Browser-owned non-emitting retained raw duplicate with no route to `0x0046a760`.
- `by-class/BrowserWindow.md`: no edit required. It already lists [UID:00020V] as registered host WndProc and [UID:00020W] as non-emitting retained raw clone, not a second callable BrowserWindow method.
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`: no edit required for this callback. It supports constructor/browser-host context; current target-level xref evidence is sufficient.
- `by-global/g_browserWindowClassName.md`: no edit required. It already documents `"Baram.Browser.Window"` as class-name evidence for `WNDCLASSA.lpszClassName`, `RegisterClassA`, and `CreateWindowExA`.
- `by-memory/-ignored.md`: no edit required. It already records `0x0046a6ea-0x0046a760` and `0x0046a855-0x0046a860` as generated table/padding/alignment ranges.

## Score And Metadata Recommendation

- [UID:00020V] current/recommended metadata: `86/90`, owner/emitter [UID:0000HV], `RECONSTRUCTABLE:TRUE`, blank emitter position, formal C++ populated.
- [UID:00020W] current/recommended metadata: `86/91`, owner [UID:0000HV], `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, blank emitter position, blank formal C++.
- Score rationale for [UID:00020V]: current MCP and target docs prove registration and behavior strongly enough for 86/90. Score does not rise in this callback because the accepted change was a summary consistency repair only, and the exact original source-file split is still inferred.
- Score rationale for [UID:00020W]: current MCP confirms no emitting route; B010's 86/91 non-emitting score is stronger and newer than this report's old 85/90 state. Do not lower it; do not emit code.
- Score-improvement attempts: current MCP rechecked the function object, xref, pointer, decompile, byte/table, and padding blockers. [UID:00020V] cannot move higher without cleaning target-summary contradiction and resolving original source split. [UID:00020W] cannot move to source-emitting without new route/registration evidence; current evidence supports no-code rather than further source C++.
- Metadata fields changed in callback: none; B009 preserved [UID:00020V] and [UID:00020W] metadata exactly.

## Open Questions With Attempted Resolution

- Open question: was [UID:00020W] a retained unused source function, missed indirect callback, or dead browser-adjacent code?
  - Evidence checked: current MCP function lookup, decompile attempt, xrefs, pointer-byte patterns, raw bytes, existing B010 report, target/support docs, and generated coverage state.
  - Best supported resolution: retained raw source-shaped evidence with no current route; keep Browser ownership but no emitter/formal C++.
  - Remaining uncertainty: only map/PDB/source, runtime trace, relocation/callback table, or alternate binary evidence entering `0x0046a760` would change this.
- Open question: should [UID:00020V] be a Browser free/static helper or BrowserWindow class-static method?
  - Evidence checked: current decompile signature, constructor registration, BrowserWindow support docs, Browser source root.
  - Best supported resolution: file-scope `static LRESULT CALLBACK` helper under Browser source route.
  - Remaining uncertainty: exact original file split inside `browser/` remains unknown and does not change current owner/emitter metadata.
- Open question: does the old MCP-unavailable statement still block the report?
  - Evidence checked: current MCP listener, initialize, tools/list, idb_list, server_health, and exact target calls.
  - Resolution: no. MCP is available and current evidence is incorporated.
- Open question: does the [UID:00020V] stale Item Summary phrase remain after callback?
  - Evidence checked: current target header/body and assignment boundary.
  - Resolution: no. B009 applied the authorized target-only wording repair, preserved metadata/formal C++, and validated the file with command `000000006850`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable for this callback. Do not manually edit `by-memory/-coverage-report.md`, generated coverage, research tracker, validator state, or supervisor ledgers.
- Generated/tracker state should be refreshed only through scoped validator side effects and later supervisor lifecycle. Scoped validator `000000006850` reported `projected_stats_update: 1` for `project-level/-auto-completion-stats.md` and `generated_refresh: deferred`; B009 did not manually edit those files.

## Follow-Up Actions

- Supervisor Gate 2 / execute review: verify the applied target summary repair, already-present support-doc claims, validator command `000000006850`, and this updated ledger/checklist.
- Supervisor lifecycle: execute through documented validator lifecycle only after independent Gate 2 verification. B009 must not run lifecycle commands.

## Confidence

- Recommendation confidence: high for keeping [UID:00020V] emitted and [UID:00020W] non-emitting.
- Score confidence: high for unchanged `00020V 86/90` and `00020W 86/91`.
- Remaining uncertainty: original source file split and raw clone retention reason, neither of which blocks the repaired report's current recommendations.

## Validator Results

- Scoped file validator run after authorized target edit:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md --apply --queue-timeout 240`
  - Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`
  - Command ID: `000000006850`
  - Command timestamp: `2026-07-05T06:50:15-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Warnings: none reported.
  - Side effects: `projected_stats_update: 1`; `stats_incremental_noop: 1`; `project-level/-auto-completion-stats.md` updated projected path completion section; `generated_refresh: deferred` with `generated_refresh_command_id: 000000006850` and `generated_refresh_timestamp: 2026-07-05T06:50:15-04:00`.
- Historical lifecycle commands recorded in validator-owned footer: command `000000004167` marked the old executed report needs-revalidation for `target_header_missing`; command `000000006839` returned the report to active B009 research for rework. B009 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, or manual report moves.

## Changed Files

- Modified by B009 in this callback:
  - `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`
  - `tools/leaser/Agents/Agent-B009/research/00020V-00020W-BrowserWindowWndProcClone-source-quality.md`
- Validator side effect, not a manual B009 edit:
  - `project-level/-auto-completion-stats.md` projected path completion section was updated by scoped validator command `000000006850`.
- Verified and not modified:
  - `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`
  - `by-file/Browser.md`
  - `by-class/BrowserWindow.md`
  - `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
  - `by-global/g_browserWindowClassName.md`
  - `by-memory/-ignored.md`
  - generated files, manual coverage reports, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, and validator-owned history footer comments.
- Leases: `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md` leased by B009 before the edit and released immediately after validator command `000000006850`; no active B009 lease remains for this target.
- Report execution: not run. B009 did not run `execute_report` or any lifecycle/archive equivalent.

## Implementation Tracking Checklist

Implementation callback verification:

- [x] Verified the repaired report header includes `TARGET-REPORT-UID:00020V`, `AUTHOR-AGENT-ID:B009`, and `AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh`; C01 is `applied`.
- [x] Verified current MCP evidence from `supervisor_recovery_20260705` remains in Supporting Research/Evidence Checked and the older MCP-unavailable statement is historicalized; C02 is `applied`.
- [x] Verified [UID:00020V] accepted facts against the target/support docs: `86/90`, owner/emitter [UID:0000HV], formal C++ populated, registration at `0x00469758`, pointer-byte corroboration at `0x0046975e` in support docs, and `BrowserWindowHostWndProc` source shape. C03 and C04 are `already-present`.
- [x] Applied the only concrete target-doc repair: leased `by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md`, replaced only the stale `Item Summary` phrase with populated formal-C++ wording, preserved metadata/formal C++, validated, and released the lease. C05 is `applied`.
- [x] Verified [UID:00020W] accepted facts against its target doc: `86/91`, owner [UID:0000HV], blank `EMITTER_UIDS:`, blank formal C++, no function/decompile/xref/pointer route at `0x0046a760`, raw body/table layout, and selector command values `0xf000/0xf010/0xf020/0xf030/0xf060`. C06, C07, and C08 are `already-present`.
- [x] Verified support docs and intentionally did not edit them because they are already present at same-or-greater detail: `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`, `by-global/g_browserWindowClassName.md`, and `by-memory/-ignored.md`. C09 and C10 are `already-present`.
- [x] Ran the scoped file validator for the changed target page and recorded metadata: command `000000006850`, timestamp `2026-07-05T06:50:15-04:00`, exit `0`, `ok: 1`, no warnings, `projected_stats_update: 1`, and `generated_refresh: deferred`.
- [x] Did not manually edit generated files, manual `-coverage-report.md` files, validator state, queue/lock files, lifecycle/archive files, executed-report records, supervisor ledgers, support docs, or validator-owned report-history footer comments; C11 is `excluded-with-reason` due to validator-only side effects.
- [x] B009 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, or manual report moves. Stop status is `READY_FOR_SUPERVISOR_EXECUTE`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B009/00020V-00020W-BrowserWindowWndProcClone-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006839","destination_path":"tools/leaser/Agents/Agent-B009/research/00020V-00020W-BrowserWindowWndProcClone-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/00020V-00020W-BrowserWindowWndProcClone-source-quality.md","timestamp":"2026-07-05T06:29:08-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006854","destination_path":"executed-b-agent-research/B009/00020V-00020W-BrowserWindowWndProcClone-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00020V-00020W-BrowserWindowWndProcClone-source-quality.md","timestamp":"2026-07-05T06:59:53-04:00","uid":"00020V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
