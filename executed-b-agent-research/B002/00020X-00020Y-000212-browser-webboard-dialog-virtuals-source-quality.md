** TARGET-REPORT-UID:00020X **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00020X / 00020Y / 000212 Browser/WebBoard Dialog Virtuals Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise all three targets above the active 85/85 gate with current owners/emitters unchanged.
- Final disposition:
  - [UID:00020X] `BrowserDialogPaneVirtuals`: keep owner/emitter [UID:000017] `BrowserDialog`; raise `82/90` to `86/91`; keep formal C++ blank.
  - [UID:00020Y] `WebBoardDialogVirtualCompanions`: keep owner/emitter [UID:0000G2] `WebBoardDialog`; raise `82/90` to `87/91`; populate accepted first-draft C++.
  - [UID:000212] `WebBoardDialogOldDestructionAndMouseCallbacks`: keep owner/emitter [UID:0000G3] `WebBoardDialogOld`; raise `82/90` to `86/91`; populate accepted first-draft C++.
- Required action: update the three target docs and support docs with the inferred source-facing names, resource constants, field/global aliases, generated-output caveats, and the coverage rows below. Do not change owner/emitter routing.
- Confidence: high for ownership, ranges, vtable reachability, globals, and resource names; medium-high for exact original method names because they remain inferred from behavior and vtable position.

## Supporting Research

## Target

- Assignment: `B002-goal2-browser-webboard-dialog-virtuals-source-quality-00020X-00020Y-000212-20260617`.
- Target paths:
  - `by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md`
  - `by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md`
  - `by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md`
- Source queue/report rows: current `by-memory/-coverage-report.md` lines 645, 651, and 667 show all three as `reconstructable : 82% : strong`, with owners/emitters already attached.
- Current supervisor classification: report-only B-agent source-quality/source-inference task. `by-memory/-coverage-report.md` is supervisor-owned.
- Split state: no split repair is required for this assignment. [UID:00020X] remains a broad but single-owner BrowserDialog virtual/helper cluster. [UID:00020Y] and [UID:000212] are compact companion clusters with exact method boundaries and homogeneous owners.

## Executive Recommendation

Keep the source placement already modeled by the project:

- [UID:00020X] belongs to `BrowserDialog` under `NexusTK/browser/Browser.cpp`.
- [UID:00020Y] belongs to active `WebBoardDialog` under `NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- [UID:000212] belongs to legacy `WebBoardDialogOld` in the same `WebBoardDialog.cpp` source family.

The original-source names cannot be proven from symbols, but behavior, vtable slots, constructor geometry, and sibling draw pages support these source-facing descriptive names:

| Range | Recommended source-facing name | Notes |
| --- | --- | --- |
| `0x0046ad10-0x0046ad39` | `BrowserDialog::~BrowserDialog()` | Ordinary destructor body; scalar deleting wrapper is outside this target. |
| `0x0046ad40-0x0046ad7b` | `BrowserDialog::OnCloseStateChanged(int state, int reason)` | Runs teardown when `state == 0`; does not clear the browser-control member after shutdown. |
| `0x0046ad80-0x0046aea8` | `BrowserDialog::OnInputEventWithBrowserReposition(...)` | Derived input/move override; repositions the embedded browser HWND during title-drag/move paths. |
| `0x0046aeb0-0x0046b02d` | `BrowserDialog::DrawSelectedControlFrame()` | Vtable slot `+0x44`; existing `VisualRefresh` name is acceptable but less precise. |
| `0x0046b030-0x0046b0c3` | `BrowserDialog::DrawContentArea()` | Vtable slot `+0x50`; draws/tile-fills the content area from `WBOARDBK.*` in EPF mode. |
| `0x0046b0d0-0x0046b4af` | `BrowserDialog::DrawFrameChrome()` | Vtable slot `+0x54`; draws the board-frame chrome from `WEBBOARD.*`. |
| `0x0046b4b0-0x0046b51d` | `BrowserDialog::GetChildRect(short id, Rect *out)` | Constructor-called child rect helper; id `0` title/icon rect, id `1` browser content rect, else `id - 1`. |
| `0x0046d330-0x0046d359` | `WebBoardDialog::~WebBoardDialog()` | Clears `g_pWebBoardDialog`; source destructor only, not deleting wrapper. |
| `0x0046d360-0x0046d3a5` | `WebBoardDialog::OnCloseStateChanged(int state, int reason)` | Runs when `state == 0`; shuts down and clears `m_browserControlPane`. |
| `0x0046d3b0-0x0046d475` | `WebBoardDialog::OnInputEventWithBrowserReposition(...)` | Active web-board browser HWND inset is `+11,+42`. |
| `0x0046e8c0-0x0046e8e9` | `WebBoardDialogOld::~WebBoardDialogOld()` | Clears `g_pWebBoardDialogOld`. |
| `0x0046e8f0-0x0046e92b` | `WebBoardDialogOld::OnCloseStateChanged(int state, int reason)` | Runs when `state == 1`; this is not a close-button command handler or deleting destructor. |
| `0x0046e930-0x0046e9f5` | `WebBoardDialogOld::OnInputEventWithBrowserReposition(...)` | Legacy fixed-art browser HWND inset is `+30,+30`, matching constructor geometry. |

## Supervisor Active Recheck

- The assignment explicitly asked for current documentation plus IDA/MCP and/or raw PE checks, target/parent/support docs, vtable/static data, globals, coverage rows, generated output pollution, first-draft C++ readiness, and exact support text.
- Existing executed B reports were searched for `00020X`, `00020Y`, `000212`, and the contained addresses. No direct prior report for these three targets was found. The relevant executed sibling report is B001's `000210-webboard-render-escape-source-split.md`, which split and validated the active WebBoard draw helpers at `0x0046dbd0`, `0x0046dd00`, and `0x0046dea0` and established the parallel vtable slot map.
- A sibling executed B002 report for [UID:00020Z]/[UID:000213] had already classified the active/old retained request helpers as source-shaped duplicate helper bodies with no surviving inbound edge; that supports keeping raw request helpers separate from these live vtable callback targets.

## Inference Research Guidance Check

- Facts: IDA function boundaries, decompilation, vtable dword xrefs, constructor calls, global refs, resource string bytes, and local PE pointer/rel32 scan results.
- Documentation evidence: target docs, BrowserDialog/BrowserPane/DialogPane/BrowserControlPane/WebBoardDialog/WebBoardDialogOld class/file docs, browser vtable/read-only data docs, resource docs, global docs, generated coverage tables, and executed sibling reports.
- Inference: final source-facing method names, exact parameter names, field names for inherited layout state, and source-level helper names around the close/visibility and draw-helper vtable slots.

The current owner/emitter assignments are validated, not merely inherited: vtable data points directly into the BrowserDialog, WebBoardDialog, and WebBoardDialogOld vtable blocks, the singleton globals match the class-specific constructors/destructors, and the geometry/resource behavior matches each class's constructor and sibling draw pages.

## Heuristic / Inference Reanalysis And Validation

### Virtual names and signatures

- Best direction: use source-facing names based on behavior and vtable slot role, not raw `sub_` names.
- Evidence checked: IDA decompilation of all target functions; vtable xrefs at `0x006133e0`, `0x006133e4`, `0x006133ec`, `0x006133f0`, `0x00613414`, `0x00613624`, `0x00613654`, `0x006136d4`, and `0x00613704`; sibling active WebBoard draw child pages; BrowserPane/DialogPane docs.
- Accepted names:
  - Close-state callback: `OnCloseStateChanged(int state, int reason)` for `0x46ad40`, `0x46d360`, `0x46e8f0`.
  - Reposition input callback: `OnInputEventWithBrowserReposition(...)` for `0x46ad80`, `0x46d3b0`, `0x46e930`.
  - Draw slots: `DrawSelectedControlFrame`, `DrawContentArea`, `DrawFrameChrome`.
  - Rect helper: `GetChildRect`.
- Rejected alternatives:
  - `OnCloseButton`: rejected for `0x46e8f0` because no button id or command payload is decoded; the old constructor's close button id `30` is separate.
  - deleting destructor / cleanup wrapper: rejected for `0x46e8f0` because scalar deleting destructors are separate wrapper slots; this callback is vtable slot `0x006136d4` and branches on a runtime state parameter.
  - generic `DialogPane::OnInputEvent`: rejected as owner for `0x46d3b0` and `0x46e930` because the functions are stored in WebBoard-specific vtables and use WebBoard-specific browser-control offsets/insets.
- Remaining uncertainty: original source names could have been shorter, such as `OnClose`, `OnMove`, `DrawBack`, or `SetRect`. The descriptive names above are still strong enough for source-quality docs because they express the stable behavior and slot role.

### Field and global names

- Best direction:
  - `this + 0x26c` in active/old WebBoard and `this + 0x26c` through secondary-view arithmetic in BrowserDialog: `m_browserControlPane` (`BrowserControlPane *`).
  - BrowserControlPane `+0x11c`: hosted browser child `HWND`.
  - Secondary-view `+0x168` in the input callbacks corresponds to the primary DialogPane title-drag/move active byte around primary `+0x208`; use `m_isTitleDragActive` or `m_isDialogMoveActive`.
  - `dword_67AB28`: [UID:0000WY] `g_activeBrowserControlPane`.
  - `dword_67A7CC`: [UID:0000S7] `g_pScreenPane`.
  - `dword_67A74C`: [UID:0000Q8] `g_pApplicationCleanupQueue` / BlackHole deferred cleanup queue.
  - `byte_66DA97`: [UID:0000SW] `g_useEpfAssets`.
  - `dword_67A744`: [UID:0000QU] `g_pEPFLib`.
- Evidence checked: BrowserControlPane docs, global pages, BlackHole B002 execution notes, target decompilation, and the canonical `g_useEpfAssets` page.
- Rejected alternatives:
  - `dword_67A74C` as a pane-child registry: stale generated wording; BlackHole docs now prove the deferred-cleanup queue backing pointer.
  - `byte_66DA97` as browser-specific high-res mode: too narrow; global docs show it is a broad EPF/current-layout asset selector with 366 xrefs.
  - `+0x168` as a BrowserControlPane state byte: rejected because it is read before moving the hosted browser and matches inherited DialogPane drag/move state in support docs.

### Resource table names

- Best direction:
  - `off_60DB5C`: `kWBoardBackgroundEpfName` / UTF-16 `L"WBOARDBK.EPF"`.
  - `off_60DB78`: `kWBoardBackgroundPalName` / UTF-16 `L"WBOARDBK.PAL"`.
  - `off_60DB94`: `kWebBoardFrameEpfName` / UTF-16 `L"WEBBOARD.EPF"`.
  - `off_60DBB0`: `kWebBoardFramePalName` / UTF-16 `L"WEBBOARD.PAL"`.
- Evidence checked: IDA byte reads at `0x0060db44` through `0x0060dbc8`, `xrefs_to` counts, `ranking-ui-resources.md`, `webboard-dialog-resources.md`, BrowserDialog target docs, and active WebBoard draw child docs.
- Rejected alternatives:
  - Treating these as old WebBoard fixed-art resources: rejected because WebBoardDialogOld constructor uses different `WEBBOARD.EPD` / `WEBBOARD.PAD` literals at `0x00613b00` / `0x00613ae4`.
  - Treating `WEBBOARD.EPF/PAL` as private BrowserDialog resources: rejected because ranking, fitting-room, user-list/reward, BrowserDialog, and active WebBoard draw paths share the same literals.
- Score impact: resource literal identities are now solved. This removes the stale `off_60DB*` blocker from the target/support docs, but the shared-resource ownership remains with resource docs or existing owner contexts rather than BrowserDialog/WebBoardDialog.

### Source-authored helpers versus generated artifacts

- Best direction:
  - The destructor bodies are ordinary source destructors compiled as class methods; deleting wrappers are separate targets outside these three ranges.
  - The close-state and input/reposition functions are live source-authored virtual overrides, not retained duplicate/dead artifacts, because vtable dwords point to them.
  - BrowserDialog `GetChildRect` at `0x0046b4b0` is source-authored and constructor-called, not dead.
- Evidence checked: vtable dword refs; local PE scan; constructor rel32 call refs to `0x46b4b0`; absence of direct ordinary destructor refs consistent with scalar deleting destructor dispatch.
- Rejected alternatives:
  - No-direct-xref retained duplicate: rejected for every virtual callback with vtable data refs, and for `GetChildRect` because of constructor rel32 calls.
  - Compiler-only artifact: rejected because bodies perform source-level BrowserControlPane/resource/drawing behavior, not thunks or wrapper glue.

### BrowserPane/DialogPane inheritance and owner pollution

- Best direction: keep derived override ownership with `BrowserDialog`, active `WebBoardDialog`, and `WebBoardDialogOld`. Use `DialogPane`/`BrowserPane` only as base-class dependency docs.
- Evidence checked: BrowserDialog/WebBoardDialog/WebBoardDialogOld vtable blocks in [UID:0001OF] Browser vtables/read-only data; class/file docs; IDA vtable xrefs; generated route table.
- Rejected alternatives:
  - `DialogPane.cpp` ownership for `0x46d3b0`/`0x46e930`: rejected because the callback bodies are stored in WebBoard-specific vtables and use BrowserControlPane member state.
  - `RankingDialog.cpp` ownership for old callbacks: rejected by old singleton, `WebBoardDialogOld` vtables, `WEBBOARD.EPD/PAD` constructor resources, and existing WebBoardDialog file docs.
  - `BrowserPane` ownership for all three targets: rejected because BrowserPane supplies shared base behavior; these methods are derived-dialog overrides and class-specific destructors/callbacks.

### Existing docs validation/rejection

- Validated:
  - Target ranges and function sizes are correct.
  - BrowserControlPane field roles at `+0x11c` and `+0x120` are consistent with the HWND/COM host model.
  - Active WebBoard draw child pages validate the parallel `DrawContentArea` / `DrawFrameChrome` slot names.
  - WebBoardDialogOld fixed `+30,+30` inset matches constructor geometry.
  - Current owner/emitter routing is correct.
- Rejected/stale:
  - Resource names left as `off_60DB5C`, `off_60DB78`, `off_60DB94`, `off_60DBB0` should be replaced with the `WBOARDBK`/`WEBBOARD` names above.
  - Any generated `DialogPane` or `RankingDialog` owner text for these target callbacks is pollution and should remain only as historical generated-output caveat.
  - Treating `0x46e8f0` as a close-button-specific handler is too narrow; the binary parameter gate proves close-state/activation-state callback semantics.

### Score, source-placement, and final-C++ impact

- [UID:00020X] can rise to `86/91`: the source-quality blockers around resources, globals, owner, vtable reachability, and derived routing are solved. Formal C++ should remain blank because it is a multi-method cluster containing large draw helpers with unresolved low-level drawing helper signatures and draw-state field names.
- [UID:00020Y] can rise to `87/91`: the compact method cluster has stable source placement, field/global names, range boundaries, and source-shaped behavior. It is safe for first-draft formal C++.
- [UID:000212] can rise to `86/91`: the old callback names are high-probability inferences rather than symbol-proof, but the state gate, fixed-art geometry, singleton, and vtable owner are strong enough. It is safe for first-draft formal C++ with descriptive names.

## Evidence Standards Used

- IDA MCP evidence: function lookup, xrefs, callees, decompilation, vtable refs, globals, resource references, and padding bytes.
- Raw PE evidence: local VA dword and rel32 scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Documentation evidence: current target pages, class/file/global/resource docs, generated coverage, and executed sibling B reports.
- Negative evidence: absence of non-vtable pointers/calls for virtual callbacks beyond known vtable slots; absence of generated source bodies in current `Browser.cpp`/`WebBoardDialog.cpp`; rejection of DialogPane/Ranking pollution.

## IDA MCP And PE Facts

### Function/range facts

- `0x0046ad10` size `0x29`; `0x0046ad40` size `0x3b`; `0x0046ad80` size `0x128`; `0x0046aeb0` size `0x17d`; `0x0046b030` size `0x93`; `0x0046b0d0` size `0x3df`; `0x0046b4b0` size `0x6d`.
- `0x0046d330` size `0x29`; `0x0046d360` size `0x45`; `0x0046d3b0` size `0xc5`.
- `0x0046e8c0` size `0x29`; `0x0046e8f0` size `0x3b`; `0x0046e930` size `0xc5`.
- `0x0046b51d`, `0x0046d475`, and `0x0046e9f5` are not function starts; they are target range ends.

### Xref facts

- BrowserDialog virtual data refs:
  - `0x46aeb0` at `0x006133e0`.
  - `0x46ad40` at `0x006133e4`.
  - `0x46b030` at `0x006133ec`.
  - `0x46b0d0` at `0x006133f0`.
  - `0x46ad80` at `0x00613414`.
- BrowserDialog child-rect helper:
  - `0x46b4b0` has constructor rel32 callers at `0x0046ab1d` and `0x0046ab5f`.
- WebBoardDialog virtual data refs:
  - `0x46d360` at `0x00613624`.
  - `0x46d3b0` at `0x00613654`.
- WebBoardDialogOld virtual data refs:
  - `0x46e8f0` at `0x006136d4`.
  - `0x46e930` at `0x00613704`.
- Ordinary destructors `0x46ad10`, `0x46d330`, and `0x46e8c0` have no direct ordinary code refs in the PE scan, which is expected for source destructors reached through generated deleting-destructor routes.

### Decompilation behavior

- `0x46ad10`: clears `g_pBrowserDialog`, restores BrowserPane/DialogPane vtables, then chains base teardown.
- `0x46d330`: clears `g_pWebBoardDialog`, restores vtables, then chains base teardown.
- `0x46e8c0`: clears `g_pWebBoardDialogOld`, restores vtables, then chains base teardown.
- `0x46ad40`: if `state == 0`, calls a close/deactivate virtual at `+0x68`, shuts down `m_browserControlPane`, calls two inherited lifecycle slots at `+0x38` and `+0x40`, then queues/unregisters through `g_pApplicationCleanupQueue`.
- `0x46d360`: same state-zero path, but also clears `m_browserControlPane` after shutdown.
- `0x46e8f0`: same close-state path, but branches on `state == 1` and does not clear the member after shutdown.
- `0x46ad80`: delegates to base input, repositions the hosted browser HWND; in EPF/current-layout mode the inset is `+11,+42`, otherwise it falls back to the un-inset base rectangle.
- `0x46d3b0`: active WebBoard input/reposition override; always uses `+11,+42`.
- `0x46e930`: old WebBoard input/reposition override; uses fixed `+30,+30`.
- `0x46b030` and `0x46dd00` use `WBOARDBK.EPF/PAL` for content/background fill.
- `0x46b0d0` and `0x46dea0` use `WEBBOARD.EPF/PAL` for frame/chrome tiles.

### Resource/string facts

- Byte inspection at `0x0060db44` decodes UTF-16LE strings for `ERLOOK.EPF`, `WBOARDBK.EPF`, `WBOARDBK.PAL`, `WEBBOARD.EPF`, and `WEBBOARD.PAL`.
- `off_60DB5C` and `off_60DB78` are the `WBOARDBK.EPF` and `WBOARDBK.PAL` literal pointers.
- `off_60DB94` and `off_60DBB0` are the `WEBBOARD.EPF` and `WEBBOARD.PAL` literal pointers.
- `WBOARDBK.*` has nine current literal xrefs per resource in existing resource docs.
- `WEBBOARD.EPF/PAL` has forty-two current literal xrefs per resource in existing resource docs.
- Old fixed-art `WEBBOARD.PAD` at `0x00613ae4` and `WEBBOARD.EPD` at `0x00613b00` are separate WebBoardDialogOld constructor operands, not these EPF/PAL draw helper operands.

### Local PE scan facts

Local PE scan over `NexusTK.exe`, imagebase `0x400000`, found:

| Target VA | Absolute dword hits | rel32 call/jump hits |
| --- | --- | --- |
| `0x0046ad10` | none | none |
| `0x0046ad40` | `0x006133e4` | none |
| `0x0046ad80` | `0x00613414` | none |
| `0x0046aeb0` | `0x006133e0` | none |
| `0x0046b030` | `0x006133ec` | none |
| `0x0046b0d0` | `0x006133f0` | none |
| `0x0046b4b0` | none | `0x0046ab1d`, `0x0046ab5f` |
| `0x0046d330` | none | none |
| `0x0046d360` | `0x00613624` | none |
| `0x0046d3b0` | `0x00613654` | none |
| `0x0046e8c0` | none | none |
| `0x0046e8f0` | `0x006136d4` | none |
| `0x0046e930` | `0x00613704` | none |

This matches IDA's vtable-only reachability for virtual callbacks and constructor-only reachability for BrowserDialog `GetChildRect`.

### Padding facts

- `0x0046ad0a-0x0046ad10`, `0x0046d324-0x0046d330`, and `0x0046e8be-0x0046e8c0` remain documented padding/constructor alignment.
- Internal `0xcc` padding is present at `0x0046d359-0x0046d360`, `0x0046d3a5-0x0046d3b0`, `0x0046e8e9-0x0046e8f0`, `0x0046e92b-0x0046e930`, and `0x0046e9f5-0x0046ea00`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046ad10-0x0046b51d` | [UID:00020X] `BrowserDialogPaneVirtuals` | BrowserDialog destructor, close/input/draw/rect virtual helper cluster | TRUE | [UID:000017] `BrowserDialog` | `86/91` | Keep emitting; formal C++ blank. |
| `0x0046d330-0x0046d475` | [UID:00020Y] `WebBoardDialogVirtualCompanions` | Active WebBoard destructor, close-state, browser reposition callbacks | TRUE | [UID:0000G2] `WebBoardDialog` | `87/91` | Keep emitting; populate draft C++. |
| `0x0046e8c0-0x0046e9f5` | [UID:000212] `WebBoardDialogOldDestructionAndMouseCallbacks` | Old WebBoard destructor, close-state, browser reposition callbacks | TRUE | [UID:0000G3] `WebBoardDialogOld` | `86/91` | Keep emitting; populate draft C++. |

## Documentation Evidence And IDA Status

- `by-class/BrowserDialog.md` and `by-file/Browser.md`: BrowserDialog is browser-owned; target methods already route to `Browser.cpp`. IDA validates this via BrowserDialog vtable slots and `g_pBrowserDialog` destructor clear.
- `by-class/WebBoardDialog.md` and `by-file/WebBoardDialog.md`: active WebBoard owns its browser control, singleton, request/response, and virtual companions. IDA validates this via active vtable slots and `g_pWebBoardDialog`.
- `by-class/WebBoardDialogOld.md` and `by-resource/webboard-dialog-resources.md`: old fixed-art dialog owns `WEBBOARD.EPD/PAD`, `+30,+30` browser rectangle, and old singleton. IDA validates this via vtable slots and fixed reposition inset.
- `by-class/DialogPane.md`: base class docs correctly warn that derived input overrides should not be absorbed by DialogPane. IDA validates this by vtable placement.
- `by-class/BrowserControlPane.md`: field model supports the hosted child HWND at `+0x11c`.
- `by-global/g_useEpfAssets.md`: canonicalizes `byte_66DA97` as the broad EPF/current-layout selector; use this name in target docs.
- `by-resource/ranking-ui-resources.md`: already resolves `WBOARDBK.*` and `WEBBOARD.EPF/PAL`; target docs should reuse those resource names.
- `auto-generated/-ag-memory-coverage.md`: confirms route table emits [UID:00020X] to `auto-generated/NexusTK/browser/Browser.cpp` and [UID:00020Y]/[UID:000212] to `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- Current generated source state: `Browser.cpp` contains only alert strings, and `WebBoardDialog.cpp` is empty despite route rows; this is an omission/blank-formal-C++ consequence, not proof of wrong ownership.

## Ranked Ownership Analysis

### 1. BrowserDialog / WebBoardDialog / WebBoardDialogOld current owners

- Evidence for: class-specific vtables, class-specific singleton clears, matching constructor geometry/resources, direct BrowserControlPane member usage, and existing class/file docs above the gate.
- Evidence against: exact original method names are not symbol-proven; BrowserDialog target is a multi-method cluster.
- Decision: accepted. Keep all owner/emitter assignments unchanged.

### 2. BrowserPane / DialogPane base ownership

- Evidence for: target methods call inherited/base input and lifecycle slots; secondary-vtable pointer arithmetic is present.
- Evidence against: vtable data refs point to derived class vtable blocks, and each body uses derived browser-control geometry/singleton behavior.
- Decision: reject as direct owner. Keep as dependency/source-base context only.

### 3. RankingDialog generated pollution

- Evidence for: older generated output historically misrouted some WebBoardDialogOld content through `RankingDialog.cpp`, and shared `WEBBOARD.EPF/PAL` resources are used by ranking UI.
- Evidence against: old fixed-art constructor uses WebBoardDialogOld vtables, `g_pWebBoardDialogOld`, `WEBBOARD.EPD/PAD`, and old browser-control geometry. Active/old browser packet helpers and response handlers are documented under WebBoardDialog.
- Decision: reject. Mention only as generated-output caveat.

### 4. Resource/global owners

- Evidence for: `WBOARDBK.*`, `WEBBOARD.EPF/PAL`, `g_useEpfAssets`, `g_activeBrowserControlPane`, and `g_pApplicationCleanupQueue` are shared dependencies.
- Evidence against: consumer use does not make the virtual callbacks resource/global-owned.
- Decision: keep these as referenced dependencies; do not change target owner/emitter.

## Negative Evidence Summary

- No PE absolute or rel32 references were found that would move `0x46d3b0` or `0x46e930` into DialogPane ownership.
- No PE absolute or rel32 references were found that would move old WebBoard callbacks into RankingDialog ownership.
- Ordinary destructor bodies have no direct refs, but this does not imply dead code; it is normal for source destructors to be reached through generated deleting destructor wrappers and vtable-controlled destruction.
- Resource literal sharing does not imply RankingDialog/BrowserDialog ownership of the resources; the resource docs already prove a shared board-frame family.

## Exact Metadata / Score Recommendations

### [UID:00020X] `BrowserDialogPaneVirtuals`

- `COMPLETION`: `86`
- `CONFIDENCE`: `91`
- `CANONICAL_OWNER`: keep `000017`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `000017`
- `RECONSTRUCTION_CPP`: keep blank
- Rationale: resource/global/virtual-name/source-routing blockers are now mostly resolved, but formal C++ should wait for a BrowserDialog file-level draw-helper pass because this combined range includes large frame/tiling methods with unresolved low-level draw helper names and draw-state fields.

### [UID:00020Y] `WebBoardDialogVirtualCompanions`

- `COMPLETION`: `87`
- `CONFIDENCE`: `91`
- `CANONICAL_OWNER`: keep `0000G2`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `0000G2`
- `RECONSTRUCTION_CPP`: populate accepted first-draft C++
- Rationale: compact exact cluster, vtable reachability, field/global names, source owner, and behavior are stable enough for first-draft source.

### [UID:000212] `WebBoardDialogOldDestructionAndMouseCallbacks`

- `COMPLETION`: `86`
- `CONFIDENCE`: `91`
- `CANONICAL_OWNER`: keep `0000G3`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `0000G3`
- `RECONSTRUCTION_CPP`: populate accepted first-draft C++
- Rationale: old callback names are inferred, but old singleton/vtables/fixed geometry/state gate are strong enough. The code draft captures exact behavior without leaking RankingDialog/DialogPane ownership.

## Exact Supervisor-Owned Coverage Row Replacements

Placement context: replace the existing rows in `by-memory/-coverage-report.md` under the Browser/WebBoard block at current lines 645, 651, and 667.

```markdown
    - [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md) 0x0046ad10-0x0046b51d | class method cluster | BrowserDialogPaneVirtuals : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis confirms the exact BrowserDialog destructor/close/input/draw/child-rect virtual-helper cluster, function sizes 0x29/0x3b/0x128/0x17d/0x93/0x3df/0x6d, vtable slots for draw-selected-control, close-state, content draw, frame chrome, and input/reposition overrides, constructor-only child-rect helper callers, singleton `g_pBrowserDialog` clear, BrowserControlPane close path at `+0x26c`, browser HWND reposition through `g_activeBrowserControlPane` and `g_pScreenPane`, canonical `g_useEpfAssets` branch behavior, resolved shared board resource literals `WBOARDBK.EPF`/`WBOARDBK.PAL` and `WEBBOARD.EPF`/`WEBBOARD.PAL`, rejected DialogPane/WebBoard/Ranking owner pollution, and blank formal C++ due the combined draw-helper cluster's unresolved low-level drawing helper signatures.
```

```markdown
    - [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md) 0x0046d330-0x0046d475 | class method cluster | WebBoardDialogVirtualCompanions : reconstructable : 87% : very strong : B002 2026-06-17 source-quality reanalysis confirms the exact active WebBoardDialog destructor, close-state callback, and browser-reposition input override, function sizes 0x29/0x45/0xc5, vtable slots 0x00613624 and 0x00613654, singleton `g_pWebBoardDialog` clear, BrowserControlPane shutdown/clear at `+0x26c`, close-state `state == 0` semantics, hosted HWND reposition inset `+11,+42`, dependencies on `g_activeBrowserControlPane`, `g_pScreenPane`, and `g_pApplicationCleanupQueue`, derived WebBoard owner routing over DialogPane pollution, and accepted first-draft C++ readiness for the compact companion cluster.
```

```markdown
    - [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) 0x0046e8c0-0x0046e9f5 | class destructor/callback cluster | WebBoardDialogOldDestructionAndMouseCallbacks : reconstructable : 86% : very strong : B002 2026-06-17 source-quality reanalysis confirms the exact WebBoardDialogOld destructor, close-state callback, and browser-reposition input override, function sizes 0x29/0x3b/0xc5, vtable slots 0x006136d4 and 0x00613704 plus adjacent packet slot 0x00613710, singleton `g_pWebBoardDialogOld` clear, BrowserPane vptr restoration, close-state `state == 1` teardown through BrowserControlPane shutdown and `g_pApplicationCleanupQueue`, fixed legacy browser HWND reposition inset `+30,+30`, alignment padding, rejected close-button/deleting-destructor/DialogPane/Ranking owner alternatives, and accepted first-draft C++ readiness with descriptive callback names.
```

No additional `by-memory/-coverage-report.md` rows need insertion or deletion.

## Support-Doc Update Recommendations

Apply these as target/support doc text; no support score changes are required.

- `by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md`
  - Replace `off_60DB5C/off_60DB78` with `WBOARDBK.EPF` / `WBOARDBK.PAL`.
  - Replace `off_60DB94/off_60DBB0` with `WEBBOARD.EPF` / `WEBBOARD.PAL`.
  - Add the method-name table from this report.
  - Add that `byte_66DA97` is canonical [UID:0000SW] `g_useEpfAssets`.
  - Add explicit do-not-populate formal C++ reason: multi-method draw cluster with unresolved low-level draw helper signatures.
- `by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md`
  - Rename the close helper direction to `WebBoardDialog::OnCloseStateChanged(int state, int reason)`, state-zero branch.
  - Name `this+0x26c` as `m_browserControlPane`; record member clear after shutdown.
  - Record `+11,+42` active browser HWND inset and reject DialogPane ownership.
  - Add accepted first-draft C++ block from this report.
- `by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md`
  - Resolve the open question: `0x46e8f0` is best treated as `WebBoardDialogOld::OnCloseStateChanged(int state, int reason)`, not close-button handler or deleting destructor.
  - Record `state == 1` gate, no observed member-null store after BrowserControlPane shutdown, fixed `+30,+30` inset, and WebBoardDialogOld ownership.
  - Add accepted first-draft C++ block from this report.
- `by-class/BrowserDialog.md`
  - Replace the method table rows for `0x46b030` and `0x46b0d0` with `DrawContentArea` using `WBOARDBK.EPF/PAL` and `DrawFrameChrome` using `WEBBOARD.EPF/PAL`.
  - Add `GetChildRect` child id semantics for ids `0` and `1`.
- `by-class/WebBoardDialog.md`
  - Add `WebBoardDialog::OnCloseStateChanged` and `OnInputEventWithBrowserReposition` names and the `+11,+42` browser-control geometry.
  - Note that current generated `WebBoardDialog.cpp` is empty despite valid route rows until formal C++ is populated.
- `by-class/WebBoardDialogOld.md`
  - Add the resolved old callback names and state gate.
  - State that `0x46e8f0` is not the image-button id `30` command handler; it is a vtable close-state callback.
- `by-file/WebBoardDialog.md`
  - Add that active and old browser virtual companion clusters now clear the source-quality gate and should stay under this file, not `DialogPane.cpp` or `RankingDialog.cpp`.
- `by-class/DialogPane.md` and `by-class/BrowserPane.md`
  - Optional note only: these functions are derived override users of the base input/lifecycle surface; do not absorb their owner rows.
- `by-resource/ranking-ui-resources.md` / `by-resource/webboard-dialog-resources.md`
  - No score change required. Optionally add BrowserDialog/WebBoardDialog target xrefs to the existing `WBOARDBK`/`WEBBOARD.EPF/PAL` shared-consumer notes, while preserving the old `WEBBOARD.EPD/PAD` boundary.

## Generated-Output Implications

- Current route table already sends [UID:00020X] to `auto-generated/NexusTK/browser/Browser.cpp`.
- Current route table already sends [UID:00020Y] and [UID:000212] to `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- Current generated `Browser.cpp` only contains browser alert strings; current generated `WebBoardDialog.cpp` is empty. This is consistent with blank formal C++ blocks, not with owner failure.
- After applying this report, [UID:00020Y] and [UID:000212] should begin emitting draft methods. [UID:00020X] should remain routed but still not emit method bodies until the BrowserDialog draw-helper body is coordinated.

## First-Draft C++ Recommendation

### [UID:00020X] `BrowserDialogPaneVirtuals`

Do not populate formal C++ for [UID:00020X] yet, despite the score clearing the gate. Concrete reason: the page is a seven-method BrowserDialog cluster whose large draw helpers depend on still-provisional low-level GrafPort/resource helper signatures and inherited draw-state fields. Entering a partial body would either omit half of the target range or bake in raw helper names. A later BrowserDialog source pass should either split the draw helpers into exact child pages or populate the whole cluster after shared draw helper names are normalized.

Staging names to use in that later pass:

```cpp
BrowserDialog::~BrowserDialog();
void BrowserDialog::OnCloseStateChanged(int state, int reason);
bool BrowserDialog::OnInputEventWithBrowserReposition(InputEvent *event);
void BrowserDialog::DrawSelectedControlFrame();
void BrowserDialog::DrawContentArea();
void BrowserDialog::DrawFrameChrome();
int BrowserDialog::GetChildRect(short childId, Rect *outRect) const;
```

### [UID:00020Y] `WebBoardDialogVirtualCompanions`

Populate formal C++ for [UID:00020Y] after applying the support-name updates. This draft intentionally uses source-level helper/member names proposed in this report; the supervisor may adjust exact class typedef names to match local style.

```cpp
WebBoardDialog::~WebBoardDialog()
{
    g_pWebBoardDialog = NULL;
}

void WebBoardDialog::OnCloseStateChanged(int state, int reason)
{
    (void)reason;

    if (state != 0)
        return;

    OnBrowserDialogClosed();

    if (m_browserControlPane != NULL)
    {
        m_browserControlPane->Shutdown();
        m_browserControlPane = NULL;
    }

    HideDialog();
    ReleaseDialogControls();

    if (g_pApplicationCleanupQueue != NULL)
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

bool WebBoardDialog::OnInputEventWithBrowserReposition(InputEvent *event)
{
    const bool handled = DialogPane::OnInputEvent(event);

    if (event != NULL && event->type == 0 && m_isTitleDragActive &&
        g_activeBrowserControlPane != NULL && m_browserControlPane != NULL)
    {
        RECT browserClient;
        ::GetClientRect(g_activeBrowserControlPane->GetBrowserWindow(), &browserClient);

        Rect dialogRect;
        GetPaneRect(&dialogRect);

        ::MoveWindow(m_browserControlPane->GetBrowserWindow(),
                     dialogRect.left + 11,
                     dialogRect.top + 42,
                     browserClient.right - browserClient.left,
                     browserClient.bottom - browserClient.top,
                     FALSE);

        if (g_pScreenPane != NULL)
            g_pScreenPane->Refresh();
    }

    return handled;
}
```

### [UID:000212] `WebBoardDialogOldDestructionAndMouseCallbacks`

Populate formal C++ for [UID:000212] after applying the support-name updates. Keep the old callback's `state == 1` gate and do not add a member-null assignment after BrowserControlPane shutdown unless new evidence proves the source did so indirectly.

```cpp
WebBoardDialogOld::~WebBoardDialogOld()
{
    g_pWebBoardDialogOld = NULL;
}

void WebBoardDialogOld::OnCloseStateChanged(int state, int reason)
{
    (void)reason;

    if (state != 1)
        return;

    OnBrowserDialogClosed();

    if (m_browserControlPane != NULL)
        m_browserControlPane->Shutdown();

    HideDialog();
    ReleaseDialogControls();

    if (g_pApplicationCleanupQueue != NULL)
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

bool WebBoardDialogOld::OnInputEventWithBrowserReposition(InputEvent *event)
{
    const bool handled = DialogPane::OnInputEvent(event);

    if (event != NULL && event->type == 0 && m_isTitleDragActive &&
        g_activeBrowserControlPane != NULL && m_browserControlPane != NULL)
    {
        RECT browserClient;
        ::GetClientRect(g_activeBrowserControlPane->GetBrowserWindow(), &browserClient);

        Rect dialogRect;
        GetPaneRect(&dialogRect);

        ::MoveWindow(m_browserControlPane->GetBrowserWindow(),
                     dialogRect.left + 30,
                     dialogRect.top + 30,
                     browserClient.right - browserClient.left,
                     browserClient.bottom - browserClient.top,
                     FALSE);

        if (g_pScreenPane != NULL)
            g_pScreenPane->Refresh();
    }

    return handled;
}
```

## Validation Commands

Recommended supervisor validation after applying docs/C++/coverage updates:

> Executable block R001 was removed from this report and preserved verbatim in [00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality-removed.md](00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Report-side checks performed by B002:

> Executable block R002 was removed from this report and preserved verbatim in [00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality-removed.md](00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/PE checks performed:

- IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and byte checks for the target function starts, vtable slots, resource strings, and padding.
- Local PE scan for absolute VA dwords and rel32 calls/jumps to the target functions, with results recorded above.

## Final Recommendation

- Apply the three score raises and coverage row replacements.
- Keep owners/emitters unchanged.
- Update target/support docs with the resolved method names, resource literal names, global aliases, field directions, and generated-output caveats.
- Populate formal C++ for [UID:00020Y] and [UID:000212] if accepted.
- Do not populate formal C++ for [UID:00020X] until the BrowserDialog draw-helper dependency names are normalized or exact draw-helper children are split.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality.md`
- Modified: none outside the B002 research folder.
- Leases used: none required; B002 research report creation is lease-exempt.
- Blockers: none for supervisor review. The only intentional hold is [UID:00020X] formal C++ readiness for the reasons above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00020X"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00020X-00020Y-000212-browser-webboard-dialog-virtuals-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00020X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
