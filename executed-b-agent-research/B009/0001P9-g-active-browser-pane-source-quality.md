** TARGET-REPORT-UID:0001P9 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001P9 g_activeBrowserPane Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001P9] `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md` owned and emitted by [UID:0000HV] `Browser`, resolve the source-facing type as `BrowserPane *`, and enter first-draft formal storage C++ on the exact by-memory page.
- Final disposition: reconstructable Browser module global pointer storage. The target is not a split/container issue and should remain the exact four-byte range `0x0067ab84-0x0067ab88`.
- Required action: update the target and matching by-global support page from `87/89` to `90/91`; preserve Browser owner/emitter [UID:0000HV]; add the exact formal C++ definition `BrowserPane *g_activeBrowserPane;` only on the exact by-memory storage page; update Browser/BrowserPane/BrowserControlPane support prose to remove the stale "type still unresolved" blocker while preserving the header/export visibility caveat.
- Confidence: strong for address, range, Browser ownership, `BrowserPane *` type, and no-clear lifetime model; medium-high for exact original linkage spelling because current source reconstruction still has an open one-file `Browser.cpp` versus split browser-folder/header layout question.

## Supporting Research

## Target

- Target UID: `0001P9`
- Target path: `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`
- Assignment id: `B009-report-0001P9-g-active-browser-pane-source-quality-20260627`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` line 1589 still lists stale `82/84`; current source page is authoritative at `87/89`.
- Current supervisor classification: report-only B-agent source-quality pass for a reconstructable by-memory target with blank formal C++.
- Current scores and parent state: target `87/89`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`; direct file root [UID:0000HV] `Browser` is `87/89` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/browser/"`.

## Current Target State

- Existing metadata: `COMPLETION:87`, `CONFIDENCE:89`, owner/emitter [UID:0000HV], reconstructable true, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing owner/emitter/reconstructable state: Browser source root ownership and emission are already correct.
- Existing C++/emitter state: eligible by score and emitter route, but formal C++ is blank because prior docs left exact pointer type, linkage, and lifetime-clear model open.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims:
  - Prior pages call the type "likely `BrowserPane *`" but still describe final type/linkage as open.
  - `by-global/g_activeBrowserPane.md` proposes `static BrowserPane* g_activeBrowserPane;`; live cross-module Application use makes true file-local `static` unsafe unless the original source kept Application request-exit code in the same translation unit, which current docs reject.
  - Current active MCP session renders the IDB data name as `unk_67AB84`, despite older C001 text saying a `g_activeBrowserPane` IDA label was saved. Treat `g_activeBrowserPane` as the source-facing documentation name and active IDB rename recommendation, not as current live label proof.
  - Generated tracker and generated coverage rows are stale relative to source metadata.
- Related target/support docs checked:
  - `by-global/g_activeBrowserPane.md`
  - `by-file/Browser.md`
  - `by-class/BrowserPane.md`
  - `by-class/BrowserControlPane.md`
  - `by-global/g_activeBrowserControlPane.md`
  - `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`
  - `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
  - `executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md`
  - `executed-b-agent-research/B012/000019-BrowserPane-class-source-quality.md`
  - `executed-b-agent-research/B009/0000Z6-BrowserControlPaneCore-source-quality.md`
  - `executed-b-agent-research/B001/00020U-browser-accelerator-source-quality.md`
  - generated tracker/coverage rows named above.

## Executive Recommendation

The best direct owner remains [UID:0000HV] `Browser`. This is Browser module state rather than a BrowserPane class static member: `BrowserControlPane` constructors publish the owning pane/dialog object, BrowserControlPane dispatch/accelerator code consumes it, and `Application::RequestExit` performs a guarded cross-module close through the same pointer.

The type blocker can be closed. Live constructor caller evidence shows every `BrowserControlPane` construction path passes a `this` pointer from an object that first installs `BrowserPane` vtable views: `BrowserDialog`, `WebBoardDialog`, and `WebBoardDialogOld`. That makes `BrowserPane *g_activeBrowserPane` the best source-facing declaration. `DialogPane *` is too broad because the actual publishers are BrowserPane-derived browser dialogs and the consumer calls hit BrowserPane command/close behavior. `BrowserControlPane *` is wrong because that separate active control storage is `0x0067ab28`.

The no-clear blocker can be downgraded to a documented lifetime model rather than a C++ blocker. Live xrefs still show no clear store to `0x0067ab84`; destructor/shutdown paths clear `g_activeBrowserControlPane` and object fields instead. That is coherent: the active owner pane outlives its child `BrowserControlPane`, and reachable consumers are guarded by the active control/window/object routes or run inside the live BrowserControlPane dispatch path. A stale owner pointer value after control teardown is not used when the active-control guard is cleared.

Formal C++ should now be entered on the target page:

```cpp
BrowserPane *g_activeBrowserPane;
```

Do not duplicate this definition on `by-global/g_activeBrowserPane.md`. The by-global page should become the symbol/evidence record and should state that the exact storage page owns the emitted definition.

## Supervisor Active Recheck

- The supervisor assignment is report-only and specifically asks for source-quality research on [UID:0001P9], including type, declaration/linkage, lifetime-clear/no-clear model, owner/emitter route, source placement, and first-draft C++ readiness.
- No split repair was required. The target is already an exact four-byte pointer slot; predecessor [UID:0002VW] ends at `0x0067ab84`, and successor [UID:0002AD] starts at `0x0067ab88`.
- Every source-quality blocker named in the assignment was chased in this pass:
  - exact pointer type: resolved as `BrowserPane *`;
  - declaration name/linkage: name `g_activeBrowserPane`, non-static global definition with Browser header/source visibility caveat;
  - lifetime-clear/no-clear model: no direct clear remains, but it is safe by active-control/object lifetime guard;
  - owner/emitter route: keep [UID:0000HV] Browser;
  - source placement: `NexusTK/browser/Browser.cpp` definition, Browser header/accessor exposure if Application remains separate;
  - first-draft C++: recommended exact formal definition.

## Inference Research Guidance Check

- IDA facts, documentation evidence, and inference are separated below.
- Existing C001/B010/B012/B001 claims were used as leads and rechecked where they affect this target. Prior A/C work is not treated as direct proof by itself.
- Stale generated tracker rows were explicitly rejected as stale because current source metadata is stronger.
- No Wave2/Wave3 source output was used as authority. Generated names are treated as search leads only.
- The evidence ladder is mostly direct IDA MCP evidence: live bytes, direct xrefs, decompilation of the constructor, active accelerator helper, Application request-exit path, BrowserWindow retained helper, dispatch handler, destructor, shutdown helper, and constructor callsites.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Pointer type | Live decompilation of constructor callers at `0x0046aa40`, `0x0046d050`, `0x0046e2a0`, and `0x0046e640`; BrowserPane and derived vtable writes before `sub_46B520(..., this)` calls. | `BrowserPane *`. All live publishers pass the owning BrowserPane-derived dialog object as the fourth constructor argument. | Reject `void *`/`DWORD` because callsites and consumers are typed enough. Reject `BrowserControlPane *` because that is `0x0067ab28`. Reject plain `DialogPane *` as unnecessarily broad. |
| Source-facing name | Existing docs, source role, and Browser global naming family. Active MCP name inventory around `0x0067ab80-0x0067ab90` returns no named global and decompilation prints `unk_67AB84`. | Keep `g_activeBrowserPane` as the source-facing/global doc name. It matches role and current docs even if active IDB label state is stale. | Do not use `unk_67AB84` or `dword_67AB84` in formal source. Do not rename to `g_pActiveBrowserPane` without a broader naming pass, because current docs and sibling `g_activeBrowserControlPane` use the `g_active...` style. |
| Linkage | Direct cross-module consumer `Application::RequestExit` at `0x00464e40` reads the slot when `g_activeBrowserControlPane` is live. Current source root keeps Application under `app/Application.cpp`, not Browser. | Emit a non-static definition in Browser source, with declaration/access through Browser header or equivalent browser module private header. | Reject true file-local `static` as the default. It would hide the symbol from Application unless source layout changes. |
| Lifetime clear model | `xrefs_to 0x0067ab84` returns exactly 8 refs. Live decompilation shows only constructor assignment to the slot. Destructor `0x0046b990` clears `0x0067ab28`, not `0x0067ab84`; shutdown `0x0046ba90` clears object fields, not the global. | No direct clear is expected/required by current evidence. The owner pane outlives the child control; live uses are guarded by active control/window routes or occur inside live BrowserControlPane dispatch. | Reject "C++ blocked until a clear xref is found." Also reject inventing a destructor clear, because the binary does not write zero to this slot. |
| Owner/emitter route | Browser file root owns the browser module; BrowserPane/BrowserControlPane support pages clear score gate; Application is a consumer only. | Keep owner/emitter [UID:0000HV] Browser. | Reject Application ownership: Application only coordinates shutdown. Reject BrowserControlPane class as canonical owner for this global storage because the value is the owner pane, and the source declaration is Browser module state. |
| Formal C++ readiness | Target is exact 4-byte source-declared pointer storage, score gate is met, emitter route is valid, type and no-clear model are now resolved. | Add exact formal C++ definition on by-memory target. | Reject blank C++ as stale. Reject duplicate C++ on by-global page. |
| Active IDB label | `list_globals "*activeBrowserPane*"` returns no rows; `entity_query` names/globals over `0x0067ab80-0x0067ab90` returns no rows; decompiler refs name `unk_67AB84`. | Report optional future safe IDA rename `unk_67AB84 -> g_activeBrowserPane`; do not edit IDA DB in this report-only pass. | Reject treating older saved-label prose as current live label proof. |
| Generated row state | Current source page `87/89`; generated tracker line 1589 and generated by-memory coverage line 2862 still show `82/84`. | Treat generated rows as stale context only; refresh through validator after implementation, not manual edits. | Do not edit auto-generated reports by hand. |

## Evidence Standards Used

- Direct IDA MCP evidence: live MCP transport session `c78bb7cf-40e4-459a-b30e-5e570694bc2f`, IDB session `b001_000241_20260627`, `NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Storage evidence: `get_bytes 0x0067ab80 size 0x14` returned all zero bytes; `get_int 0x0067ab84 u32le` returned `0`.
- Xref evidence: live `xrefs_to` and `xref_query` confirm exactly 8 direct data refs to `0x0067ab84`.
- Decompiler evidence: constructor, active accelerator, retained accelerator, Application request exit, dispatch handler, destructor, shutdown helper, and constructor callsites were decompiled in this pass.
- Documentation evidence: current by-* docs and executed B reports were checked and treated as leads unless live IDA or current docs corroborate them.
- Negative evidence: no direct clear store among the xref set; no live IDB global/name row for `g_activeBrowserPane`; no xrefs to retained `0x0046a510` BrowserWindow accelerator helper.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health`: active IDB ready.
  - `get_bytes` over `0x0067ab80-0x0067ab94`: all zero bytes.
  - `get_int 0x0067ab84 u32le`: value `0`.
  - `xrefs_to 0x0067ab84`: 8 direct refs, no more pages.
  - `xref_query 0x0067ab84 direction=to include_fn=true`: same 8 refs with function contexts.
  - `lookup_funcs`: `0x00464e40`, `0x0046a510`, `0x0046b520`, `0x0046b990`, `0x0046ba90`, `0x0046c550`, `0x0046c960`.
  - `decompile/analyze_function`: constructor `0x0046b520`, active accelerator `0x0046c550`, dispatch handler `0x0046c960`, destructor `0x0046b990`, shutdown `0x0046ba90`, Application request exit `0x00464e40`, retained BrowserWindow accelerator `0x0046a510`, constructor callers `0x0046aa40`, `0x0046d050`, `0x0046e2a0`, `0x0046e640`.
  - `xrefs_to 0x0046b520`: five constructor callsites.
  - `xrefs_to 0x0046a510`: zero callers.
  - `xrefs_to 0x0046c550`: one Application message-loop caller at `0x00464d88`.
  - `list_globals "*activeBrowserPane*"` and `entity_query` names/globals in `0x0067ab80-0x0067ab90`: no current named rows.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target, by-global, Browser, BrowserPane, BrowserControlPane, active-control sibling pages, ApplicationRequestExit, executed B010/B012/B009/B001 reports, generated tracker and generated by-memory coverage.
- Negative checks performed: no clear xref; no active IDB name/global row for `g_activeBrowserPane`; no live caller for retained `0x0046a510`; no evidence for Application or Surface ownership.
- Failed, unavailable, or intentionally skipped checks and why: no MCP failure occurred. IDA DB edits were intentionally skipped because the assignment forbids IDA DB changes.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x0067ab84-0x0067ab88` is exact four-byte pointer storage. | Confirmed | Live zero bytes and `get_int` value; exact 8-ref set; current target range. | Neighbor pages for `0x0067ab80` and `0x0067ab88` checked; no split/merge need. | None for range. |
| Source-facing type is `BrowserPane *`. | Strong | Constructor writes fourth argument; all five constructor callsites pass `this` from BrowserPane-derived dialog constructors or refresh helpers after BrowserPane vtable setup. | Checked `BrowserControlPane *`, `DialogPane *`, raw `void *`, and Application ownership alternatives. | Exact original typedef/name for BrowserPane base pointer remains unknown but not blocking. |
| Declaration should not be true file-local `static` by default. | Strong | `Application::RequestExit` directly reads the global; current source route puts Application in a separate source root. | Checked sibling `g_activeBrowserControlPane` precedent, which already requires header/accessor exposure for non-browser consumers. | Exact original linkage could be private browser header, external global, or broad original source file; final project source placement decides the header line. |
| No direct clear is safe and should be documented, not treated as a blocker. | Strong | Live xrefs show no clear; destructor/shutdown clear active control and object fields; consumers are guarded by active control/window paths or live object dispatch. | Checked destructor `0x0046b990`, shutdown `0x0046ba90`, Application request-exit guard, retained BrowserWindow helper reachability. | If a future dynamic trace shows stale pointer use after active-control clear, revisit. Current static evidence does not support adding a clear. |
| Formal C++ definition is ready. | Strong | Exact storage page, valid emitter route, score gate met, type/lifetime/linkage resolved enough for source. | Checked aggregate-C++ and duplicate by-global risks. | Generated source ordering/header declarations may need implementation support, but the storage definition itself is ready. |

## Positive Evidence Summary

- Direct facts supporting the recommendation:
  - Live IDA MCP reports exactly 8 direct data refs to `0x0067ab84`.
  - Constructor `0x0046b520` assigns `unk_67AB84 = a4` at `0x0046b62d`.
  - BrowserDialog constructor `0x0046aa40` calls the constructor twice as `sub_46B520(v11/v15, rect, a3, (int)this)` after installing BrowserPane and BrowserDialog vtables.
  - WebBoardDialog constructor `0x0046d050` and refresh helper `0x0046e2a0` call `sub_46B520(..., this)` after BrowserPane/WebBoardDialog vtable setup.
  - WebBoardDialogOld constructor `0x0046e640` calls `sub_46B520(..., (int)this)` after BrowserPane/WebBoardDialogOld vtable setup.
  - Active accelerator `0x0046c550`, Application request exit `0x00464e40`, and dispatch handler `0x0046c960` all consume the pointer as a close/callback target.
- Corroborating documentation/generated-report evidence:
  - Browser, BrowserPane, and BrowserControlPane support pages all point to Browser source ownership.
  - Executed B010 and B012 reports already identified `BrowserPane *` as the best type direction.
  - Current generated rows are stale but still route the target through Browser.
- Strongest inference chain and why it is sufficient:
  - Published constructor argument provenance plus all reachable consumer semantics converge on owner BrowserPane behavior. This is stronger than a name-based guess and enough to enter a source-facing pointer definition.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x0046b520`: `sub_46B520`, size `0x46e`.
  - `lookup_funcs 0x0046c550`: `sub_46C550`, size `0x10a`.
  - `lookup_funcs 0x0046c960`: `sub_46C960`, size `0x190`.
  - `lookup_funcs 0x00464e40`: `sub_464E40`, size `0xf4`.
- Data/table/padding facts:
  - `get_bytes 0x0067ab80 size 0x14`: all zero bytes across the pointer window containing this slot and the following BrowserThread host globals.
  - `get_int 0x0067ab84 u32le`: `0`.
  - `entity_query` over `0x0067ab80-0x0067ab90` returned no current names/globals; active decompiler refs use `unk_67AB84`.
- Xref facts:
  - `0x00464e70` in `sub_464E40`: guarded Application request-exit close path.
  - `0x0046a5d4` in `sub_46A510`: retained BrowserWindow accelerator helper, no callers to helper.
  - `0x0046b62d` in `sub_46B520`: constructor write.
  - `0x0046bcee`: raw helper island ref; documented zero-timeout notify path.
  - `0x0046c617` in `sub_46C550`: active accelerator Escape close.
  - `0x0046c9f4`, `0x0046ca77`, `0x0046cabb` in `sub_46C960`: internal-close, document-complete callback, and new-window/close dispatch uses.
- Vtable/global/type facts:
  - Constructor callers install BrowserPane vtables before publishing `this`.
  - Dispatch handler calls through `(*g_activeBrowserPane)->+0x64` with browser command/tag `0x4243746f`, matching BrowserPane command/callback role.
  - Sibling `g_activeBrowserControlPane` at `0x0067ab28` is the active `BrowserControlPane *` and is cleared by destructor/scalar helper; it is separate from this owner-pane pointer.
- Negative IDA facts:
  - No direct clear xref appears in the 8-ref set.
  - Destructor `0x0046b990` clears `unk_67AB28` but not `unk_67AB84`.
  - Shutdown `0x0046ba90` clears object fields and browser COM/window state but not `unk_67AB84`.
  - Retained BrowserWindow accelerator helper `0x0046a510` has zero xrefs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ab84-0x0067ab88` | [UID:0001P9] target | Browser active owner/callback pane pointer storage | TRUE | [UID:0000HV] Browser | recommend `90/91` | Exact storage, ready for first-draft global definition |
| `0x0067ab28-0x0067ab2c` | [UID:0001P3] | active BrowserControlPane pointer | TRUE | [UID:0000HV] Browser | `86/89` | Separate active-control guard/lifetime storage |
| `0x0046b520-0x0046b98e` | inside [UID:0000Z6] | BrowserControlPane constructor | TRUE | Browser source root | support | Writes target from ownerPane argument |
| `0x00464e40-0x00464f34` | [UID:0002H3] | Application::RequestExit | TRUE | Application | `87/90` | Cross-module guarded consumer |
| `0x0046c550-0x0046c65a` | inside [UID:0000Z6] | active BrowserControlPane accelerator helper | TRUE | Browser source root | support | Live Application message-loop route |
| `0x0046c960-0x0046caf0` | inside [UID:0000Z6] | BrowserControlPane dispatch event handler | TRUE | Browser source root | support | Consumes owner pane for close/document-complete callbacks |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046b62d` | `sub_46B520` writes `unk_67AB84 = a4` | Single confirmed writer; the constructor publishes owner pane. |
| `0x0046ab86`, `0x0046ac95` | `BrowserDialog` constructor calls `sub_46B520(..., (int)this)` | Publisher is BrowserDialog, a BrowserPane-derived object. |
| `0x0046d1f8` | `WebBoardDialog` constructor calls `sub_46B520(..., this)` | Publisher is WebBoardDialog after BrowserPane vtable setup. |
| `0x0046e3f4` | WebBoardDialog refresh/rebuild helper calls `sub_46B520(..., this)` | Reuses same owning BrowserPane-derived object. |
| `0x0046e7ca` | `WebBoardDialogOld` constructor calls `sub_46B520(..., (int)this)` | Publisher is WebBoardDialogOld after BrowserPane vtable setup. |
| `0x00464e70` | `Application::RequestExit` checks `g_activeBrowserControlPane`, then closes via target | Cross-module guarded shutdown consumer. |
| `0x0046c617` | active accelerator helper closes via target on Escape | Live Application message-loop route via `0x00464d88`. |
| `0x0046c9f4` / `0x0046cabb` | dispatch handler calls close/helper via target | Internal close/new-window-like events. |
| `0x0046ca77` | dispatch handler calls vtable slot `+0x64` on target with `0x4243746f` | Document-complete BrowserPane callback/command. |
| `0x0046a5d4` | retained BrowserWindow accelerator helper closes via target | Helper has zero live callers in current IDB; keep as retained consumer evidence only. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - `by-class/BrowserPane.md` already says `g_activeBrowserPane` is high-probability `BrowserPane *` and Browser-owned.
  - `by-class/BrowserControlPane.md` records constructor/dispatch usage and the separate active-control pointer.
  - `by-file/Browser.md` groups this global under Browser-owned data and currently routes browser globals through `NexusTK/browser/Browser.cpp`.
  - `by-global/g_activeBrowserControlPane.md` provides the sibling linkage/accessor precedent for active browser globals consumed outside Browser code.
- Existing docs that are stale, incomplete, or contradicted:
  - `by-global/g_activeBrowserPane.md` should no longer say final type is open. It should change "Likely declaration: static BrowserPane*..." to the accepted definition/visibility model.
  - Target and global pages should replace "no-clear blocks final C++" with the owner-pane lifetime/active-control guard model.
  - C001 saved-label prose is stale for the active MCP session; current IDB still renders `unk_67AB84`.
  - Generated tracker and coverage rows are stale at `82/84`.
- Generated/coverage report state:
  - `auto-generated/-ag-research-tracker.md` line 1589: stale `82/84`.
  - `auto-generated/-ag-coverage-report-by-memory.md` line 2862: stale `82%`, emits_code false.
  - Current generated `auto-generated/NexusTK/browser/Browser.cpp` has empty markers for [UID:0000PP] and [UID:0001P9]; it already contains BrowserThread host global definitions, so a Browser global declaration pattern exists in this source root.

## Ranked Ownership Analysis

### 1. [UID:0000HV] Browser source root

- Evidence for: current Browser file root groups BrowserPane, BrowserControlPane, BrowserDialog, WebBoardDialog browser-control usage, browser COM helpers, and browser-owned globals; all target publishers/consumers are browser-module or browser-coordination uses; emitter route already surfaces to `NexusTK/browser/Browser.cpp`.
- Evidence against: Application request-exit reads the pointer directly, so the definition cannot be assumed file-local without a header/accessor or broader original source-unit explanation.
- Decision: keep as canonical owner/emitter and add linkage visibility caveat. This is the strongest and current-project-consistent route.

### 2. [UID:000019] BrowserPane class

- Evidence for: the stored object type is BrowserPane-derived, and consumers call BrowserPane close/command behavior.
- Evidence against: the slot is module-global active owner state, not a BrowserPane class static member; WebBoardDialog and BrowserDialog publishers share it; Application also consumes it.
- Decision: use BrowserPane for the type, not as the canonical owner.

### 3. [UID:000015] BrowserControlPane class

- Evidence for: constructor writes it, dispatch/accelerator methods read it.
- Evidence against: the stored value is not a BrowserControlPane; `0x0067ab28` is the active BrowserControlPane pointer; `0x0067ab84` stores the owning BrowserPane-derived dialog pointer.
- Decision: reject as canonical owner/type. BrowserControlPane is the main writer/consumer class but not the declaration owner.

### 4. [UID:00000D] Application

- Evidence for: `Application::RequestExit` directly reads the slot during shutdown coordination.
- Evidence against: Application never writes the slot and only consumes it after checking active browser-control state; BrowserControlPane construction and browser dispatch are the real owner/user family.
- Decision: reject ownership. Application is a cross-module consumer that affects linkage visibility.

## Source Placement

- Recommended source file/class/global/module placement: Browser source root [UID:0000HV], currently generated as `NexusTK/browser/Browser.cpp`; declaration visibility through `Browser.h` or a browser-private header/accessor if Application remains in `app/Application.cpp`.
- Why this placement fits source-tree and subsystem context: target sits among Browser globals, is published by BrowserControlPane construction, is consumed by browser dispatch/accelerator paths, and has BrowserPane-derived publisher provenance.
- Rejected placements and why:
  - `Application.cpp`: consumer only, no writer.
  - `BrowserControlPane` class static: wrong stored type and cross-derived-owner semantics.
  - `BrowserPane` class static: type is BrowserPane, but declaration is shared module state rather than per-class state.
  - WebBoardDialog: two publishers are WebBoard-derived, but BrowserDialog also publishes and Browser owns the infrastructure.
- Remaining placement uncertainty: exact original linkage spelling. Use external global definition now; a later browser source split may replace direct global access with a browser header declaration or accessor, but should not change the target's storage/type.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x0067ab84-0x0067ab88`, four-byte pointer storage. Live zero bytes over `0x0067ab80-0x0067ab94` confirm a contiguous zeroed pointer neighborhood.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: source-declared global pointer storage; not padding, table, code, or compiler-only artifact.
- Parent/container impact: no change to predecessor [UID:0002VW] or successor [UID:0002AD].

## Negative Evidence Summary

- No direct clear store to `0x0067ab84` exists in the live 8-ref set.
- No active IDB name/global row proves `g_activeBrowserPane` as a saved IDA label in this worker session.
- No xrefs to retained BrowserWindow accelerator helper `0x0046a510`; its use of the target remains retained-code support, not live pump reachability.
- Application request-exit direct read does not prove Application ownership because constructor and dispatch evidence point to Browser.
- The no-clear model must not be "fixed" by adding a clear in source; the binary clears the active control pointer instead.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name/type: `BrowserPane *g_activeBrowserPane`.
- Evidence: constructor argument provenance from BrowserPane-derived callsites and BrowserPane close/command consumers.
- Items intentionally left unchanged and why:
  - Active IDB name `unk_67AB84` was not changed because this is report-only and IDA DB edits are forbidden.
  - Exact original header/export spelling remains a support/source-layout question.
- Whether IDA DB edits are safe, unsafe, or not requested: a future safe IDA refresh may rename `unk_67AB84` to `g_activeBrowserPane` and apply the pointer type if supervisor permits IDA DB edits. This report does not request or perform IDA DB edits.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, owner/emitter route is confirmed, current combined score is above the code-entry gate, and the page covers an exact global pointer storage declaration.
- Recommended code: replace the target's currently blank formal C++ block with this exact content and leave the inline `RECONSTRUCTION_CPP CODE` value blank:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BrowserPane *g_activeBrowserPane;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable.
- Reason it preserves exact original behavior: an uninitialized file/global-scope pointer definition starts as zero, matching live bytes before runtime writes; constructor writes the owner pane pointer; no source clear is added because the binary has no clear store.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a Browser module global pointer to the active BrowserPane owner/callback target is ordinary VC6/VC7-era C++ for a UI subsystem coordinating browser pane state across browser/control/application shutdown paths.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `BrowserPane`, `g_activeBrowserPane`.
- Naming/coding style convention used and evidence for consistency: project uses `g_activeBrowserControlPane` and `g_activeBrowserPane` for active browser globals; pointer star spacing follows existing accepted BrowserThreadHostGlobals output (`static BrowserThread *g_pBrowserThread;`).
- Reason code should remain blank, if applicable: not applicable for this target. The remaining header/source-order visibility issue belongs in support docs and generated source organization, not in the storage definition itself.

## Final Recommendation

- Exact changes recommended:
  - Target [UID:0001P9] to `COMPLETION:90`, `CONFIDENCE:91`, same owner/emitter [UID:0000HV], formal C++ block containing `BrowserPane *g_activeBrowserPane;`.
  - Support [UID:0000PP] `by-global/g_activeBrowserPane.md` to `90/91`, with type and no-clear model resolved and no duplicate formal C++.
  - Browser, BrowserPane, and BrowserControlPane support docs should say final source-facing type is resolved as `BrowserPane *`; the remaining caveat is linkage/header/source split, not type or lifetime.
- Exact parent assignments recommended: no owner/emitter change; keep [UID:0000HV].
- Exact items left no-owner/non-emitting and why: none for this target. By-global page should remain non-code-emitting to avoid duplicate global definitions.
- Exact future work outside this assignment scope: optional future IDA DB safe rename/type application; broader browser source split/header organization.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`
- Exact report facts to incorporate:
  - Add a `2026-06-27 B009 Live IDA Source-Quality Recheck` section with session `b001_000241_20260627`, health readiness, zero bytes over `0x0067ab80-0x0067ab94`, `get_int 0x0067ab84 u32le == 0`, and the unchanged 8-ref set.
  - Record active IDB label state: live decompilation uses `unk_67AB84`; source-facing name remains `g_activeBrowserPane`.
  - Record constructor assignment `unk_67AB84 = a4` at `0x0046b62d`.
  - Record constructor caller provenance showing BrowserDialog/WebBoardDialog/WebBoardDialogOld pass their `this` pointer after BrowserPane vtable setup.
  - Replace "exact type/linkage and lifetime-clear model unresolved" with "type resolved as `BrowserPane *`; no-clear model is documented and safe under active-control/object lifetime guards; exact header/export split remains open."
  - Add C++ readiness proof and formal C++ block.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:90`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000HV` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:0000HV` unchanged
  - formal C++ block: `BrowserPane *g_activeBrowserPane;`
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve no-clear xref fact, but reclassify from blocker to lifetime model.
  - Preserve generated tracker stale row as context only if useful.
  - Preserve rejected `static` default, Application ownership, BrowserControlPane type, and raw `unk_67AB84` source name.

## Recommended Support Doc Changes

- Support path: `by-global/g_activeBrowserPane.md`
  - Raise to `90/91`.
  - Replace likely declaration block with accepted source-facing declaration model: exact storage page emits `BrowserPane *g_activeBrowserPane;`; by-global page should not duplicate formal C++.
  - Add active IDB label caveat and optional future rename recommendation.
  - Add no-clear lifetime model and cross-module non-static/header visibility caveat.
- Support path: `by-file/Browser.md`
  - Update Browser-owned data row for [UID:0000PP]/[UID:0001P9] from "final type still under review" to "`BrowserPane *` declaration ready on exact storage page; exact header/source split remains open."
  - No score change recommended.
- Support path: `by-class/BrowserPane.md`
  - Strengthen `g_activeBrowserPane` wording from high-probability to accepted source-facing `BrowserPane *` active owner/callback pointer.
  - No score change recommended.
- Support path: `by-class/BrowserControlPane.md`
  - Update touched-state table and open questions so this global's type/no-clear model is no longer a class-level blocker; keep the broader BrowserControlPane aggregate child-split/C++ blockers.
  - No score change recommended.
- Support path: `by-global/g_activeBrowserControlPane.md` and [UID:0001P3] exact memory page
  - No required edits unless the implementer wants to add a one-line cross-reference that `g_activeBrowserPane` follows the same browser-header/accessor visibility issue.

## Score And Metadata Recommendation

- Current score/metadata: `87/89`, owner/emitter [UID:0000HV], reconstructable true, blank C++.
- Recommended score/metadata: `90/91`, same owner/emitter/reconstructable fields, formal C++ definition present.
- Score rationale and reason not higher/lower:
  - Completion rises because the report resolves exact type, source-facing declaration shape, no-clear model, first-draft C++ disposition, stale generated context, and active IDB label caveat.
  - Confidence rises because live IDA directly confirms storage, xrefs, constructor writer, caller argument provenance, and guarded consumers.
  - Scores stay below final-audit range because exact original linkage/header/source split is still inferred, active IDB label is not currently saved in this worker session, and Browser source layout remains broad.
- Score-improvement attempt:
  - Exact pointer type: resolved via caller provenance.
  - Source-facing declaration name/linkage: name retained, linkage resolved as non-static/global definition plus header/accessor visibility caveat.
  - Lifetime clear: resolved as no-clear-by-design/static evidence, not missing work.
  - Owner/emitter/source placement: Browser retained after ranking alternatives.
  - First-draft C++: recommended exact block content.
- Metadata fields to change or leave unchanged:
  - Change `COMPLETION`/`CONFIDENCE`.
  - Leave `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, and `EMITTER_POSITION_OPTIONAL`.

## Open Questions With Attempted Resolution

- Exact original linkage/header spelling:
  - Evidence checked: Application direct read, Browser source root, sibling active-control docs, generated Browser.cpp current shape.
  - Best supported resolution: non-static global definition in Browser source with Browser header/private-header visibility or accessor for Application.
  - Remaining uncertainty: exact original source could have used a broader browser/application source file or private header. This affects final source organization but not target storage type or first-draft definition.
- Active IDB label state:
  - Evidence checked: `list_globals`, `entity_query`, decompiler refs.
  - Best supported resolution: docs keep source-facing `g_activeBrowserPane`; active IDB still has `unk_67AB84`.
  - Remaining uncertainty: whether another IDA session has the saved label. This affects IDA hygiene, not source reconstruction.
- Generated source ordering:
  - Evidence checked: current generated `Browser.cpp` empty markers and existing BrowserThreadHostGlobals definitions.
  - Best supported resolution: emit the storage definition now; if generated ordering lacks a visible `BrowserPane` declaration, solve by Browser header/forward-declaration/source-order support outside this target's range.
  - Remaining uncertainty: final generated source compile order, not the storage definition itself.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not edit manual coverage reports or auto-generated reports for this report-only pass. After accepted implementation and scoped validation, validator-generated tracker/coverage should refresh from source metadata and target `Item Summary`/`Nested` data. No manual `-coverage-report.md` text is requested.

## Follow-Up Actions

- Supervisor actions: verify this implementation claim by claim against the changed docs, validator output, and checked checklist; if accepted, execute the report through the normal `execute_report` validator lifecycle.
- A-agent actions: none required.
- B009 future implementation actions after callback: none for accepted items; all callback edits, scoped validators, and checklist proof are complete.
- Optional future source/IDA hygiene: safe IDA rename/type application for `unk_67AB84` only under explicit IDA DB edit permission; broader Browser source header/split pass.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `90/91`, not final-audit.
- Remaining uncertainty: exact original linkage/header split and active IDB label state.

## Validator Results

- Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x0067ab84-0x0067ab88.g_activeBrowserPane.md --apply --queue-timeout 240`
    - `command_id: 000000004684`
    - `command_timestamp: 2026-06-27T22:49:28-04:00`
    - exit code `0`, `ok: 1`
    - side effects reported: `completion_update 0001P9 90`, `confidence_update 0001P9 91`, `canonical_owner_update 0001P9 0000HV`, `autogen_registry_update`, `insert_header_blank`, `projected_stats_update`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-global\g_activeBrowserPane.md --apply --queue-timeout 240`
    - `command_id: 000000004686`
    - `command_timestamp: 2026-06-27T22:49:35-04:00`
    - exit code `0`, `ok: 1`
    - side effects reported: `completion_update 0000PP 90`, `confidence_update 0000PP 91`, `canonical_owner_update 0000PP 0000HV`, `autogen_registry_update`, `uid_link_insert` for UID links, `reference_index_add`, `projected_stats_update`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240`
    - `command_id: 000000004688`
    - `command_timestamp: 2026-06-27T22:49:58-04:00`
    - exit code `0`, `ok: 1`
    - warnings/side effects reported: pre-existing `missing_ref_target: 9` and `missing_ref_uid: 14`, `projected_stats_update`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\BrowserPane.md --apply --queue-timeout 240`
    - `command_id: 000000004690`
    - `command_timestamp: 2026-06-27T22:50:09-04:00`
    - exit code `0`, `ok: 1`
    - warnings/side effects reported: pre-existing `missing_ref_uid: 13`, `reference_index_add 0001P9`, `projected_stats_update`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\BrowserControlPane.md --apply --queue-timeout 240`
    - `command_id: 000000004692`
    - `command_timestamp: 2026-06-27T22:50:17-04:00`
    - exit code `0`, `ok: 1`
    - warnings/side effects reported: pre-existing `missing_ref_target: 2` for UID `000218`, `completion_update 000015 88`, `confidence_update 000015 90`, `canonical_owner_update 000015 0000HV`, `autogen_registry_update`, `reference_index_add`, `projected_stats_update`, `generated_refresh: deferred`.
- Generated-refresh state: all five scoped validators reported `generated_refresh: deferred`. No generated output was used as proof for this implementation, and no generated report or generated C++ file was manually edited.
- Lease state: B009 leased the five by-* docs immediately before editing/validation and released them immediately after the validator batch. `python .\leaser.py B009 unlease` succeeded for all five paths, and the post-release current lease report contains no B009 active lease rows.
- Any unresolved validator warnings/errors: only pre-existing reference warnings on Browser/BrowserPane/BrowserControlPane support pages; no target-specific B009 validation failure.

## Changed Files

- Created during report-only pass: `tools/leaser/Agents/Agent-B009/research/0001P9-g-active-browser-pane-source-quality.md`
- Modified during implementation callback:
  - `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`
  - `by-global/g_activeBrowserPane.md`
  - `by-file/Browser.md`
  - `by-class/BrowserPane.md`
  - `by-class/BrowserControlPane.md`
  - `tools/leaser/Agents/Agent-B009/research/0001P9-g-active-browser-pane-source-quality.md`
- Validator-owned side effects reported: `autogen_registry_update`, `projected_stats_update`, `uid_link_insert`, and `reference_index_add` as listed above. No generated report, generated C++ file, manual `-coverage-report.md`, project-level generated file, validator/tool state file, or IDA DB was manually edited by B009.
- Renamed: none.
- Report execution: leave blank during B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for implementation under assignment `B009-implement-0001P9-g-active-browser-pane-source-quality-20260627`.
- [x] Target doc `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`: add B009 live MCP evidence, active IDB label caveat, constructor argument provenance, 8-ref inventory, no-clear lifetime model, and first-draft C++ readiness proof. Proof: added `2026-06-27 B009 Live IDA Source-Quality Recheck` with session `b001_000241_20260627`, zero bytes, `get_int`, 8 refs, constructor/caller provenance, no-clear model, rejected alternatives, and formal C++ readiness.
- [x] Target metadata: change `COMPLETION:87 -> 90`, `CONFIDENCE:89 -> 91`; leave `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header now has `COMPLETION:90`, `CONFIDENCE:91`, same owner/reconstructable/emitter fields; validator `000000004684` confirmed the updates.
- [x] Target formal C++: keep inline value blank and insert exactly `BrowserPane *g_activeBrowserPane;` between the target `RECONSTRUCTION_CPP CODE:BEGIN/END` lines. Proof: target formal block contains exactly that one line; inline value remains blank; validator `000000004684` passed.
- [x] Support doc `by-global/g_activeBrowserPane.md`: raise to `90/91`; record accepted `BrowserPane *` type, non-static/header-access visibility caveat, no-clear lifetime model, active IDB `unk_67AB84` caveat, and no duplicate C++ emission. Proof: by-global header is `90/91`, accepted type/emission model is documented, formal C++ remains blank on by-global, and validator `000000004686` passed.
- [x] Support doc `by-file/Browser.md`: update Browser-owned data row/open text so final type is no longer under review; preserve broader Browser.cpp versus split-source uncertainty. Proof: Browser-owned data row now says exact storage emits `BrowserPane *g_activeBrowserPane;` and open questions preserve header/source split uncertainty; validator `000000004688` passed.
- [x] Support doc `by-class/BrowserPane.md`: update `g_activeBrowserPane` wording from high-probability to accepted source-facing `BrowserPane *` owner/callback pointer. Proof: BrowserPane live evidence and changes sections now document accepted `BrowserPane *` source-facing storage and constructor publication; validator `000000004690` passed.
- [x] Support doc `by-class/BrowserControlPane.md`: update active-global/touched-state wording so this target's type/no-clear model is not a remaining BrowserControlPane blocker. Proof: summary, evidence, touched-state table, open questions, and changes now state type/no-clear is resolved while aggregate child-split/method C++ blockers remain; validator `000000004692` passed.
- [x] Score-limiting blockers researched to resolution: exact pointer type, source-facing name, linkage, no-clear model, owner/emitter route, source placement, and first-draft C++ disposition. Proof: incorporated in target/global/support docs and reflected in `90/91` target/global scores.
- [x] Preserve rejected alternatives and negative evidence: no direct clear store, no current IDB saved name in active session, rejected `static` default, rejected Application ownership, rejected BrowserControlPane type, rejected raw `unk_67AB84` source name, and stale generated tracker/coverage rows. Proof: target and by-global document no-clear, active IDB `unk_67AB84`, non-static/header-access caveat, rejected owner/type/name alternatives; stale generated rows remain report context only and no generated/manual coverage files were edited.
- [x] Validators to run after implementation from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x0067ab84-0x0067ab88.g_activeBrowserPane.md --apply --queue-timeout 240`; plus scoped file validators for each changed support doc. Proof: validator commands `000000004684`, `000000004686`, `000000004688`, `000000004690`, and `000000004692` all exited `0` with `ok: 1`.
- [x] Generated report refresh expected through validator/autogen. No manual coverage-report or auto-generated report edits. Proof: all validators reported `generated_refresh: deferred`; no generated report, generated C++, or manual `-coverage-report.md` was manually edited.
- [x] Optional IDA DB rename/type recommendation to document only; do not perform IDA DB edits without explicit supervisor permission. Proof: docs contain optional future IDA rename/type note for `unk_67AB84`; no IDA DB edit was performed.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current callback explicitly accepted this report and listed the same target/support file set.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, by-global, Browser, BrowserPane, and BrowserControlPane docs were updated with accepted type, evidence, no-clear model, rejected alternatives, and source split caveats.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: [UID:0001P9] and [UID:0000PP] are `90/91`; owner/emitter/reconstructable fields remain Browser/true/Browser; target C++ block emits `BrowserPane *g_activeBrowserPane;`; by-global C++ remains blank to avoid duplicate definition.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: docs preserve C001 label caveat versus active `unk_67AB84`, no direct clear store, rejected `static` default, rejected Application ownership, rejected BrowserControlPane type, and rejected raw source name.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: type/no-clear blockers are resolved; exact header/private-header/accessor placement and broader Browser source split remain documented as source organization caveats with score impact.
- [x] Validators run and results recorded with command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state when relevant. Proof: see `Validator Results` above for all five scoped validators.
- [x] Generated report refresh completed by validator or explicitly deferred; no manual coverage text applied by B009. Proof: all scoped validators reported `generated_refresh: deferred`; B009 did not edit manual coverage reports or auto-generated reports.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted items remain unapplied; only optional future IDA rename/type and broader Browser source split/header organization remain outside this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001P9-g-active-browser-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001P9-g-active-browser-pane-source-quality.md","timestamp":"2026-06-27T22:53:05","uid":"0001P9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
