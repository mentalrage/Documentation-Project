** TARGET-REPORT-UID:0002AD **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002AD BrowserThreadHostGlobals Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002AD] `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md` as the exact two-slot Browser-thread host global storage item, keep `CANONICAL_OWNER:0000HV`, keep `EMITTER_UIDS:0000HV`, and keep `RECONSTRUCTABLE:TRUE`.
- Final disposition: the range is source-authored zero-initialized Browser module storage for `g_pBrowserThread` at `0x0067ab88` and `g_pCurrentBrowserHost` at `0x0067ab8c`. It is not compiler-only padding, not a vtable/RTTI table, not a BrowserThread class data member, and not a single by-global item. The current Browser by-file root is the correct combined owner/emitter for this pair.
- Required action: report-only pass. B010 did not edit the target by-memory page, support by-* pages, generated reports, project-level reports, manual coverage reports, validator/tool state, or IDA DB state.
- Recommended score after implementation: raise from `87/91` to `90/92`. The remaining cap is exact original source spelling/linkage and final Browser source split, not behavior, type, reachability, or ownership.
- C++ disposition: populate first-draft C++ after the target/support text is updated. The exact recommended formal `RECONSTRUCTION_CPP CODE` insertion is:

```cpp
static BrowserThread *g_pBrowserThread;
static Browser *g_pCurrentBrowserHost;
```

These names are source-facing project names, not proven PDB symbols. Active live IDA currently renders the slots as `unk_67AB88` and `unk_67AB8C`; older documentation that described saved source-facing IDA labels should be treated as stale for the active MCP session.

## Supporting Research

## Target

- Target UID: `0002AD`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002AD-BrowserThreadHostGlobals-source-quality.md`
- Assignment: continue the report-only source-quality pass for `[UID:0002AD] BrowserThreadHostGlobals`.
- Current target state:
  - `COMPLETION:87`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000HV`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000HV`
  - formal C++ block blank
- Current target summary: Browser thread singleton and current browser-host bridge verified by IDA xrefs and existing browser global docs.
- Current target range: `0x0067ab88-0x0067ab90`, two writable pointer-sized storage slots in the Browser global-data island.

Generated and coverage state checked during this report:

- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show stale `80/85` or `emits_code:false` style rows for this UID. The live by-memory header is newer and should remain authoritative.
- `by-memory/-coverage-report.md` still has an older manual row. This report does not edit it; any manual coverage edit is supervisor-owned or implementation-callback work only if explicitly authorized.

## Executive Recommendation

The target should be documented as a two-global storage item owned by the Browser file source root:

| Address | Active IDA MCP name | Recommended source-facing name | Type | Role |
| --- | --- | --- | --- | --- |
| `0x0067ab88` | `unk_67AB88` | `g_pBrowserThread` | `BrowserThread *` | Browser thread singleton/current browser-thread pointer used by old Browser/BrowserDialog paths. |
| `0x0067ab8c` | `unk_67AB8C` | `g_pCurrentBrowserHost` | `Browser *` | Temporary host-construction bridge used before `GWL_USERDATA` is installed on the host HWND. |

The best first-draft declaration is file-static Browser module storage. If a later Browser source split creates a private Browser module header for cross-file legacy-browser helpers, the declaration may move to that header/source pair, but the current by-file owner remains [UID:0000HV] because no narrower single source root owns both slots.

The active IDA database also contains RTTI names for `Singleton<BrowserThread>` near the BrowserThread type metadata. A targeted repository search found no current documentation proving that `0x0067ab88` must be emitted as an exact template static-member declaration instead of the established source-facing `BrowserThread *g_pBrowserThread` global. Treat the RTTI as a source-spelling caveat, not a blocker to first-draft C++ for this storage item.

## Supervisor Active Recheck

- The supervisor assignment is report-only. I created only this research report.
- I did not edit target/support by-* docs, generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or the IDA database.
- I did not spawn subagents.
- The formal MCP-unavailable override was not triggered. IDA MCP was reachable, had an active worker, and returned health, bytes, xrefs, decompilation, disassembly, and search results. One broad text search timed out, but the listener and worker remained healthy and narrower retry calls succeeded.
- No split repair is recommended. The range is already exact for two adjacent source-authored global pointer slots. Neighbor `0x0067ab84` is a separate browser-pane/global item and should not be merged into this target.

## Structure And Inference Guidance Check

`by-structure.md` and the B-agent source-quality workflow affect this target in these ways:

- The target clears the formal C++ gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000HV`, valid Browser file emitter, and average score above `85`.
- Direct ownership should be the narrowest true semantic owner. For this pair, a single class or by-global page would be too narrow because the two slots are a Browser module global pair consumed by BrowserThread, Browser, BrowserDialogOld, and the legacy WndProc path.
- Existing docs were treated as leads. They correctly identified the source-facing names and roles, but active MCP shows the current IDA labels are `unk_67AB88` and `unk_67AB8C`, not saved `g_pCurrentBrowserHost`/`dword_67AB88` labels.
- Address adjacency alone was not used as ownership proof. The recommendation is based on exact xrefs, producer/consumer behavior, source root, and support docs.
- Lack of original PDB symbol names does not block first-draft C++ when the type, storage, owner, and emitter are otherwise strong.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| Range identity | Live MCP `get_bytes` over `0x0067ab80-0x0067aba4` returns zeros, and xrefs isolate the two slots at `0x0067ab88` and `0x0067ab8c`. | Keep the exact `0x0067ab88-0x0067ab90` storage range. It is two source-authored zero-initialized pointer slots. | Reject padding/unknown-data treatment. Reject merging with adjacent browser globals because xrefs and docs split the neighboring storage. |
| Active IDA names | Live MCP `entity_query`/`list_globals` did not return data names for `0x0067ab88` or `0x0067ab8c`. Text/decompile output renders `unk_67AB88` and `unk_67AB8C`. | Update target prose/table to distinguish active IDA labels from source-facing project names. | Reject claiming the active IDB currently has saved `g_pCurrentBrowserHost` or `dword_67AB88` labels. Older docs are stale on this narrow point. |
| `g_pBrowserThread` storage type | Constructor at `0x0046ff50` allocates/constructs a `0x80` BrowserThread object, writes the pointer to `0x0067ab88`, installs the BrowserThread vtable, stores the Browser object at thread offset `+0x68`, and starts the thread. Destructors at `0x0046eff0` and `0x004706f0` clear the same storage. | Type the slot as `BrowserThread *g_pBrowserThread`. | Reject `void *`, raw `DWORD`, or Browser-owned object pointer. All checked consumers use BrowserThread offsets such as `+0x60`, `+0x68`, and `+0x70`. |
| `g_pBrowserThread` consumers | Live xrefs show BrowserDialogOld/raw helpers and Browser invoke/key paths post private messages through `[g_pBrowserThread + 0x60]`; mouse/bounds path reads `[g_pBrowserThread + 0x70]`. | The global is shared Browser module state used by legacy Browser UI helpers and the Browser thread object. | Reject direct `BrowserThread` class ownership for the storage item. The class owns the object layout, but the source storage is module-level Browser state. |
| `g_pCurrentBrowserHost` storage type | `BrowserThread::InitializeBrowserHost` loads `[BrowserThread + 0x68]`, writes it to `0x0067ab8c`, passes the same value to `SetWindowLongA(hwnd, GWL_USERDATA, browser)`, then clears `0x0067ab8c`. The WndProc fallback reads the slot only when `GetWindowLongA(hwnd, GWL_USERDATA)` returns null. | Type the slot as `Browser *g_pCurrentBrowserHost`. It is a temporary construction bridge for the legacy Browser host object. | Reject `BrowserThread *`, `BrowserWindow *`, or long-lived active-browser singleton. This path uses the legacy `Browser` object and clears the bridge after user-data installation. |
| WndProc bridge behavior | [UID:000333] and live MCP decompilation show `BrowserLegacyHostWndProc` retrieves `GWL_USERDATA`, falls back to `unk_67AB8C`, then uses Browser fields such as `+0x14` and `+0x18`. | Keep `g_pCurrentBrowserHost` as Browser-owned support storage for the WndProc setup window. | Reject assigning this storage to PlatformApi or BrowserWindow. The fallback is Browser object plumbing, not a Win32 dispatch slot. |
| Direct owner/emitter | [UID:0000HV] Browser file groups Browser, BrowserThread, BrowserControlPaneOld, BrowserDialogOld, browser COM helpers, and browser global storage. Direct pages [UID:0000QE] and [UID:0000QO] cover individual slots, but no single by-global page covers the pair. | Keep `CANONICAL_OWNER:0000HV` and `EMITTER_UIDS:0000HV`. | Reject reowner to `BrowserThread`, `Browser`, `BrowserDialogOld`, or either by-global page. Those are support items, not the combined source root for both slots. |
| `Singleton<BrowserThread>` caveat | Live MCP global-name search found BrowserThread RTTI and `Singleton<BrowserThread>` RTTI/type-descriptor names. Targeted repository search found no current docs tying `0x0067ab88` to a required template static-member declaration. | Record a caveat: exact original declaration spelling could have involved the project singleton template, but first-draft source can use `static BrowserThread *g_pBrowserThread`. | Do not block C++ solely on RTTI adjacency. Do not claim exact original source spelling is proven. |
| Formal C++ readiness | The target passes the reconstructable/emitter/score gate; live xrefs and support docs resolve type, lifecycle, and owner. | Populate first-draft C++ with the two declarations shown above. | Reject leaving C++ blank for generic follow-up. The remaining uncertainty is exact original spelling/linkage, which can be documented while still emitting a useful first draft. |
| Score | Current page is already `87/91`, but it still treats some label/type/linkage questions as blockers. Live MCP resolves the active label state, complete xref inventory, and C++ declaration readiness. | Raise to `90/92` after implementation. | Do not raise into final-audit range. Exact source split and original spelling remain unproven. |

Remaining non-blocking uncertainties:

- Exact original source spelling is not proven. `g_pBrowserThread` and `g_pCurrentBrowserHost` are source-facing reconstruction names, not PDB names.
- Exact linkage may have been file-local `static` or private Browser module header storage depending on the final Browser source split. The first-draft target should use `static` until a cross-file split requires an `extern` declaration.
- `Singleton<BrowserThread>` RTTI exists in the active IDB, but no current documentation proves that this storage slot must be represented as a template static member declaration.

## Evidence Standards Used

- Live IDA MCP evidence from the active `NexusTK.exe.i64` database.
- Existing target/support docs: Browser file, BrowserThread class, `g_pBrowserThread`, `g_pCurrentBrowserHost`, `BrowserThreadInitializeBrowserHost`, `BrowserLegacyHostWndProc`, `BrowserControlPaneOldConstructor`, BrowserThread destructors, and BrowserDialogOld/Browser invoke reports.
- Executed B-agent reports: B010 `000333-BrowserLegacyHostWndProc`, B013 `0000Z3-BrowserDialogOldCore`, B001 `0000ZF-BrowserOleLegacyAndHelpers`, and B007 Browser class/source-quality work.
- Generated and manual coverage rows were read only for stale-state awareness. They were not edited.
- Negative evidence: no active saved data names in the IDB for the two slots, no documented template-static requirement for `0x0067ab88`, no extra scoped xrefs beyond the recorded 11 and 3 references, and no reason to split or merge this range.

## Live IDA MCP Status

- Listener status: `Test-NetConnection 127.0.0.1:13337` succeeded.
- MCP initialization and tool listing succeeded.
- Active database session: `80de0a67`.
- Active IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Active module/input: module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Server health: `status ok`, `auto_analysis_ready true`, `hexrays_ready true`, `strings_cache_ready true`.
- Active worker process: backend worker PID `26892`.
- Failed/retried call: a broad `search_text` for `offset unk_67AB8C` over the large code range timed out after 60 seconds. Follow-up listener/health checks succeeded, and scoped searches over the Browser cluster returned expected results. This was a heavy-search timeout, not MCP unavailability.

## Live MCP Facts

### Bytes And Names

- `get_bytes` for `0x0067ab80-0x0067aba4` returned all zero bytes, consistent with zero-initialized writable global storage.
- Active name/global queries around `0x0067ab80-0x0067aba4` returned no saved data names.
- Active text/decompiler output renders the target slots as `unk_67AB88` and `unk_67AB8C`.
- Searches for `*BrowserHost*`, `g_pCurrentBrowserHost`, `dword_67AB88`, and `*67AB*` returned no active data-name matches.
- Searches for `*BrowserThread*` returned BrowserThread vtable/RTTI entries and `Singleton<BrowserThread>` RTTI/type-descriptor names, but not a data label at `0x0067ab88`.

### Direct Xrefs

| Slot | Xrefs | Meaning |
| --- | --- | --- |
| `0x0067ab88` | 11 data refs: `0x4694c0`, `0x46955c`, `0x469582`, `0x4695c0`, `0x469620`, `0x46eff6`, `0x46f870`, `0x46f8cb`, `0x4700ef`, `0x4700f6`, `0x4706fc` | Constructor/destructor lifecycle plus BrowserDialogOld/Browser invoke consumers posting private thread messages or reading thread state. |
| `0x0067ab8c` | 3 data refs: `0x46fcee`, `0x470b3c`, `0x470be3` | WndProc fallback read, InitializeBrowserHost publish, InitializeBrowserHost clear. |

### Function Roles

| Address / function | Live MCP evidence | Source interpretation |
| --- | --- | --- |
| `0x004694c0` | Raw body loads `unk_67AB88`, posts `PostThreadMessageA([eax+0x60], 0x500, 0, 0)`, returns. | BrowserDialogOld close-message helper using `g_pBrowserThread`. |
| `0x00469530` | Key/Escape path reads `unk_67AB88` at `0x46955c` and `0x469582`, posts private close message `0x500`. | BrowserDialogOld keyboard close handling. |
| `0x004695b0` | Mouse/bounds path reads `unk_67AB88` at `0x4695c0` and copies state from `g_pBrowserThread + 0x70`. | BrowserDialogOld/browser-thread bounds interaction. |
| `0x00469620` | Raw callback reads `unk_67AB88` and posts private message `0x501`. | BrowserDialogOld redraw/action callback. |
| `0x0046eff0` | BrowserThread non-deleting destructor stores vtable, clears `unk_67AB88`, tail-jumps to base Thread destructor. | `g_pBrowserThread` lifecycle clear. |
| `0x004706f0` | Scalar deleting destructor stores vtable, clears `unk_67AB88`, calls base Thread destructor, conditionally deletes. | Duplicate destructor clear for delete path. |
| `0x0046f810` | Browser invoke/dispatch path posts private message `0x500` through `[unk_67AB88 + 0x60]` at two sites. | Browser event sink uses current browser thread. |
| `0x0046ff50` | Old Browser control-pane constructor allocates BrowserThread, writes `unk_67AB88`, stores Browser pointer at thread `+0x68`, starts the thread. | Producer for `g_pBrowserThread`; also establishes the object later published through `g_pCurrentBrowserHost`. |
| `0x0046fcb0` | WndProc calls `GetWindowLongA(hwnd, -21)` and conditionally falls back to `unk_67AB8C`. | Early host-window callback bridge through `g_pCurrentBrowserHost`. |
| `0x00470a00` | `BrowserThread::InitializeBrowserHost` writes `[BrowserThread + 0x68]` to `unk_67AB8C`, calls `SetWindowLongA(hwnd, GWL_USERDATA, same pointer)`, then clears `unk_67AB8C`. | Producer and clear site for the temporary current-host bridge. |

## Stored Documentation Facts

- [UID:0000HV] Browser file owns the current Browser source root under `NexusTK/browser/` and already lists `g_pBrowserThread` and `g_pCurrentBrowserHost` as Browser-owned data.
- [UID:00001A] BrowserThread documents the thread object, `InitializeBrowserHost`, and the `+0x68` Browser object pointer used in the host setup path.
- [UID:0000QE] `g_pBrowserThread` identifies `0x0067ab88` as Browser-owned BrowserThread singleton/current-thread storage, with constructor and destructor lifecycle xrefs.
- [UID:0000QO] `g_pCurrentBrowserHost` identifies `0x0067ab8c` as Browser-owned temporary host bridge storage and already narrows the best type to `Browser *`.
- [UID:00032W] `BrowserThreadInitializeBrowserHost` documents `0x00470b33` loading `[BrowserThread+0x68]`, `0x00470b3c` publishing it, `0x00470bd5` storing it with `SetWindowLongA`, and `0x00470be3` clearing the global.
- [UID:000333] `BrowserLegacyHostWndProc` documents the fallback read and already has accepted first-draft C++ that uses `g_pCurrentBrowserHost` as a `Browser *`.
- [UID:0002P3] `BrowserControlPaneOldConstructor` documents Browser object allocation, BrowserThread allocation, `g_pBrowserThread` write, and Browser pointer storage at BrowserThread offset `+0x68`.
- Executed B013 `BrowserDialogOldCore` research confirms the raw helper at `0x004694c0` and nearby BrowserDialogOld event methods are consumers of `g_pBrowserThread`, not owners of the storage.

## Ranked Ownership Analysis

### 1. Browser file source root [UID:0000HV]

This remains the best direct owner/emitter. The two slots are Browser module global state, and the Browser by-file page is the current source root that groups Browser, BrowserThread, BrowserDialogOld, BrowserControlPaneOld, the legacy WndProc, and browser global storage. It can emit both declarations together without splitting one target across two owners.

### 2. Individual by-global pages [UID:0000QE] and [UID:0000QO]

These pages are strong support pages for the individual slots, but neither owns the pair. Reowning the two-slot by-memory item to one by-global page would make the other slot a dependent orphan. Keep both by-global pages as support docs and cross-links.

### 3. BrowserThread class [UID:00001A]

BrowserThread owns the object layout consumed through the `g_pBrowserThread` pointer, and its initialization method publishes the current Browser host pointer. It does not own the module-level storage declarations as class members in current evidence. Keep BrowserThread as a support owner for methods and fields, not the direct owner of this by-memory pair.

### 4. Browser class [UID:000013]

The `g_pCurrentBrowserHost` value is a Browser object pointer, and Browser methods consume `g_pBrowserThread`, but the storage is still file/module state. Do not reowner the pair to the Browser class.

### 5. BrowserDialogOld / BrowserControlPaneOld / PlatformApi

These are consumers or callees in the reachability graph. They do not own this storage. PlatformApi owns unrelated Win32 dispatch slots such as `g_pfnDefWindowProcW`, not Browser globals.

## Recommended Target And Support Updates

Target page [UID:0002AD]:

- Keep `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, and `RECONSTRUCTABLE:TRUE`.
- Update score to `COMPLETION:90`, `CONFIDENCE:92`.
- Change the storage table so active IDA names are `unk_67AB88` and `unk_67AB8C`, with separate source-facing names `g_pBrowserThread` and `g_pCurrentBrowserHost`.
- Add the current live MCP status and exact xref inventory.
- Replace or qualify older "saved label" wording as stale for the active IDA session.
- Populate `RECONSTRUCTION_CPP CODE` exactly with:

```cpp
static BrowserThread *g_pBrowserThread;
static Browser *g_pCurrentBrowserHost;
```

Support docs recommended for implementation callback:

- [UID:0000QE] `by-global/g_pBrowserThread.md`: record the active IDA label `unk_67AB88`, exact 11 xrefs, first-draft declaration readiness, and the `Singleton<BrowserThread>` spelling caveat.
- [UID:0000QO] `by-global/g_pCurrentBrowserHost.md`: record the active IDA label `unk_67AB8C`, exact three xrefs, and upgrade the type/linkage discussion from provisional to first-draft-ready `static Browser *g_pCurrentBrowserHost`.
- [UID:00001A] `by-class/BrowserThread.md`: narrow the open global-declaration question to exact source split/linkage only; behavior/type for these two globals is no longer a C++ blocker.
- [UID:0000HV] `by-file/Browser.md`: add a short Browser global-declaration readiness note for this two-slot storage item and preserve Browser file ownership.
- [UID:00032W] and [UID:000333]: no mandatory semantic rewrite is required, but any future text that cites active IDA labels should use `unk_67AB8C` for live IDB output and `g_pCurrentBrowserHost` for source-facing code.

Generated/manual reports:

- Do not manually edit `auto-generated/*` reports. Refresh them through the normal validator/generator path after target/support docs are implemented.
- Do not edit `by-memory/-coverage-report.md` from this report-only pass. If a supervisor-owned coverage update is later authorized, the row should reflect `90/92`, Browser owner/emitter, and C++ emission readiness.

## Validators And Implementation Checklist

Initial report-only pass:

- [x] Read current goal and project B-agent workflow.
- [x] Rechecked target/support docs and prior executed reports.
- [x] Rechecked live IDA MCP availability and active session health.
- [x] Gathered live MCP bytes, names, xrefs, decompilation/disassembly, and negative search evidence.
- [x] Resolved source-quality disposition, ownership, score, and C++ readiness in this report.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
  - Proof: 2026-06-27 user/supervisor callback `B010-implement-0002AD-browser-thread-host-globals-source-quality-20260627` in `tools/leaser/Agents/Agent-B010/goal.md`.
- [x] Lease discipline followed for the accepted edit/validator batch.
  - Proof: B010 leased exactly five by-* files: `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`, `by-global/g_pBrowserThread.md`, `by-global/g_pCurrentBrowserHost.md`, `by-class/BrowserThread.md`, and `by-file/Browser.md`. The first edit lease expired before validation, so B010 reacquired the same five-file lease for the validator batch and released it immediately after validation. Final `current_leases.md` check showed no active leases.
- [x] [UID:0002AD] target metadata and preserved fields updated correctly.
  - Proof: `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md` now has `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, UID `0002AD`, and exact filename/range `0x0067ab88-0x0067ab90`.
- [x] [UID:0002AD] item summary replaced with concise accepted wording.
  - Proof: target `Item Summary` now states these are source-authored Browser module globals for the BrowserThread singleton and temporary current Browser host bridge, with first-draft formal declarations ready.
- [x] [UID:0002AD] formal `RECONSTRUCTION_CPP CODE` block populated exactly.
  - Proof: target formal block contains only:

```cpp
static BrowserThread *g_pBrowserThread;
static Browser *g_pCurrentBrowserHost;
```

- [x] [UID:0002AD] storage/evidence/status text updated at report-level detail.
  - Proof: target page now records active MCP session `80de0a67`, active IDA names `unk_67AB88` / `unk_67AB8C`, source-facing names `g_pBrowserThread` / `g_pCurrentBrowserHost`, zero-initialized storage over `0x0067ab88-0x0067ab90`, exact 11 and 3 xref inventories, constructor/destructor lifecycle, BrowserDialogOld and Browser invoke consumers, WndProc fallback, `InitializeBrowserHost` publish/install/clear behavior, and `g_pCurrentBrowserHost` as the temporary `Browser *` bridge from `BrowserThread +0x68` before `GWL_USERDATA` is installed.
- [x] [UID:0002AD] rejected alternatives preserved.
  - Proof: target `Rejected Alternatives` rejects padding/unknown data, raw `DWORD`/`void *`, BrowserThread class ownership, individual by-global ownership for the pair, Browser class-only ownership, PlatformApi ownership, persistent `BrowserWindow *`, and mandatory `Singleton<BrowserThread>` template static-member spelling.
- [x] [UID:0002AD] score rationale and change log updated for `90/92`.
  - Proof: target `Score Rationale` explains completion/confidence and caps the page below final audit because exact original source spelling/linkage and one-file versus split-file Browser layout remain unproven. `Changes` includes the 2026-06-27 B010 accepted implementation callback entry.
- [x] [UID:0000QE] `g_pBrowserThread` support doc updated.
  - Proof: `by-global/g_pBrowserThread.md` records active IDA label `unk_67AB88`, exact 11-xref table, source-facing `BrowserThread *g_pBrowserThread`, first-draft declaration readiness through [UID:0002AD], Browser file owner/emitter route, and `Singleton<BrowserThread>` spelling caveat.
- [x] [UID:0000QO] `g_pCurrentBrowserHost` support doc updated.
  - Proof: `by-global/g_pCurrentBrowserHost.md` records active IDA label `unk_67AB8C`, exact three-xref table, accepted first-draft readiness as `static Browser *g_pCurrentBrowserHost`, temporary `Browser *` bridge semantics, and rejection of persistent `BrowserWindow *` for this path.
- [x] [UID:00001A] `BrowserThread` support doc narrowed.
  - Proof: `by-class/BrowserThread.md` records that [UID:0002AD] is no longer a behavior/type/C++ blocker, identifies the accepted declarations, keeps only exact source split/linkage open for these globals, and leaves unrelated BrowserThread C++ blockers separate.
- [x] [UID:0000HV] `Browser` file support doc updated.
  - Proof: `by-file/Browser.md` updates the Browser-owned globals table and adds `BrowserThread Host Global Declaration Readiness`, preserving Browser file ownership, one-file versus legacy-browser split uncertainty, active labels, accepted declarations, and rejected routes.
- [x] [UID:00032W], [UID:000333], generated reports, project-level files, manual `-coverage-report.md`, validator/tool state, and IDA DB were not edited by B010.
  - Proof: implementation patch only touched the five accepted by-* docs and this B010 report; generated output changed only through validator refresh.
- [x] Scoped validators run from `source-3/project-documentation`.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory\0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003735`, `command_timestamp: 2026-06-27T03:01:48-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-global\g_pBrowserThread.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003736`, `command_timestamp: 2026-06-27T03:01:55-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-global\g_pCurrentBrowserHost.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003737`, `command_timestamp: 2026-06-27T03:02:06-04:00`, `ok: 1`, `generated_refresh: deferred`; warning: stale `missing_ref_target 00033K` still points to old `BrowserWindowNavigate.md` path.
    - `python .\tools\validator.py --mode file --file by-class\BrowserThread.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003738`, `command_timestamp: 2026-06-27T03:02:22-04:00`, `ok: 1`, `generated_refresh: deferred`; warning: same stale `00033K` target path.
    - `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003739`, `command_timestamp: 2026-06-27T03:02:30-04:00`, `ok: 1`, `generated_refresh: deferred`; warnings: pre-existing missing UID/target diagnostics for `000408`, `00040B`, `000218`, `0003OH`, `0000PV`, `00033K`, `000407`, `000409`, `00040A`, and `00040C`.
- [x] Generated Browser.cpp refresh checked and current.
  - Proof: `auto-generated/NexusTK/browser/Browser.cpp` header shows `validator-command-id: 000000003739` and `validator-refreshed-at: 2026-06-27T03:02:30-04:00`, equal to the last validator command. The generated file includes `// UID:0002AD | by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md | Completion:90 | Confidence:92` followed by `static BrowserThread *g_pBrowserThread;` and `static Browser *g_pCurrentBrowserHost;`. `python .\tools\validator.py --queue-status` returned `command_id: 000000003740`, `command_timestamp: 2026-06-27T03:02:41-04:00`, zero queued/processing jobs, and zero queued/processing generated refresh jobs.
- [x] Remaining warnings/blockers reported.
  - Proof: no implementation blockers remain for [UID:0002AD]. Validator warnings are stale registry/reference diagnostics outside the accepted edit scope; B010 did not hand-edit validator state.
- [ ] Supervisor verification and `execute_report` remain pending.
  - Proof: per workflow, the supervisor executes `python .\tools\validator.py execute_report B010 0002AD-BrowserThreadHostGlobals-source-quality.md 0002AD --apply` only after claim-by-claim verification.

## Final Conclusion

[UID:0002AD] has been implemented as first-draft-emitting Browser global storage in the accepted callback. The target/support docs now record active IDA labels, exact live xrefs, Browser file owner/emitter, rejected alternatives, support-page implications, and the formal two-line C++ declaration block. The only remaining uncertainty is exact original source spelling/linkage, which caps the score but does not block `RECONSTRUCTION_CPP`; supervisor verification and `execute_report` remain pending.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002AD-BrowserThreadHostGlobals-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002AD-BrowserThreadHostGlobals-source-quality.md","timestamp":"2026-06-27T03:36:21","uid":"0002AD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
