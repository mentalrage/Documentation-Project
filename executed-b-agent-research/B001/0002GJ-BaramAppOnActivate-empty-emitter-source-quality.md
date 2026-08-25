** TARGET-REPORT-UID:0002GJ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002GJ BaramAppOnActivate Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:0002GJ] `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md`.
- Assignment: `B001-empty-emitter-report-0002GJ-BaramAppOnActivate-20260629`.
- Initial mode: report-only research. Callback mode, 2026-06-29: accepted target/support by-* edits were applied under the implementation callback; generated files, coverage reports, validator/tool state, IDA DB, lock files, and executed archives were not edited manually.
- Current recommendation: keep `BaramApp::OnActivate` as [UID:00000V][BaramApp](by-class/BaramApp.md)-owned source code under [UID:0000HG][Application](by-file/Application.md), update current evidence, raise the target from `86/91` to `88/92`, set `EMITTER_POSITION_OPTIONAL:30`, and replace the empty formal C++ block with a first-draft source-shaped body.
- Final disposition: implementation-ready report. The empty emitter is not a no-code item; current MCP decompiles the target and the remaining raw names can be represented through existing source-facing support abstractions.
- Implementation callback status, 2026-06-29: accepted report details were applied to the target and required support docs. Scoped validators returned `ok: 1` for every changed by-* file. Generated `auto-generated/NexusTK/app/Application.cpp` was checked read-only after validator refresh and now shows UID0002GJ as `Completion:88 | Confidence:92` with formal `BaramApp::OnActivate()` C++, not an `Empty Emitter Marker`.

## Target

- Target UID: `0002GJ`
- Target path: `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md`
- Queue source: `auto-generated/-ag-research-tracker.md` -> Files With Empty Emitters.
- Pre-implementation generated stale row checked: `auto-generated/NexusTK/app/Application.cpp` had `// UID:0002GJ ... Completion:80 | Confidence:90 | Empty Emitter Marker`. Callback proof below supersedes this: generated Application.cpp now has UID0002GJ at `88/92` with formal C++.
- Pre-implementation tracker stale row checked: `auto-generated/-ag-research-tracker.md` still had UID0002GJ at `80/90`. Tracker execution/archival remains supervisor-owned through `execute_report`; no manual tracker edit was made.
- Current source page metadata: `COMPLETION:86`, `CONFIDENCE:91`, owner/emitter `00000V`, reconstructable `TRUE`, formal C++ blank.

## Current Target State

The target page already has useful split and lifecycle evidence, but it is internally stale in two places. It still states that the C001 session saved an IDA label `BaramAppOnActivate`, and it still says Hex-Rays currently fails. The fresh MCP session `b6b3c97e` contradicts both current-state conclusions:

- `lookup_funcs 0x004669c0` returns `sub_4669C0`, size `0xa9`; `lookup_funcs BaramAppOnActivate` returns not found. Treat the prior saved label as historical, not current IDB state.
- `analyze_function 0x004669c0` and `decompile 0x004669c0` now succeed. Hex-Rays includes the non-contiguous audio restore chunk at `0x0057a480` in the same function body.
- The function still has no ordinary direct callers. It is reached by vtable data refs at `0x006125f8` and `0x0061d12c`.
- The raw helper/global names are no longer enough reason to leave the emitter blank. Current by-* docs now resolve the key dependencies to canonical source-facing names: `g_pEventMan`, `ApplicationActiveGate`, `g_pScreenPane`, `g_pApplication`, `g_pKeySpeedMgr`, `g_pSoundManager`, `g_pConfig`, and `g_pMidiPlayer`.

## Executive Recommendation

Keep the exact range and owner:

- Range remains `0x004669c0-0x00466a69`; no split is needed for the contiguous target body.
- Owner/emitter remain [UID:00000V][BaramApp](by-class/BaramApp.md), emitted through [UID:0000HG][Application](by-file/Application.md).
- The audio code at `0x0057a480-0x0057a4d8` should not become a standalone child page for this target. Existing [UID:0001I9][SoundManagerPlaybackControls](by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md) already documents it as the raw app-activation music restore chunk that IDA attaches to `BaramAppOnActivate`.
- The target should emit first-draft C++ using source-facing calls for the SoundManager app-focus restore behavior instead of copying raw SoundManager field manipulation into `BaramApp::OnActivate`.

Recommended metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `88` |
| `CONFIDENCE` | `91` | `92` |
| `CANONICAL_OWNER` | `00000V` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | `00000V` | unchanged |
| `EMITTER_POSITION_OPTIONAL` | blank | `30` |
| Formal C++ | blank | first-draft C++ below |

## Supervisor Active Recheck

The initial supervisor/user instruction required report-only research for UID0002GJ using MCP at `http://127.0.0.1:13337/mcp`, with current database session `b6b3c97e`, and forbade by-* edits before validation. MCP was available and healthy. I did not use evidence from the earlier no-session period as sufficient. The 2026-06-29 implementation callback applied the accepted by-* edits after supervisor validation.

## Inference Research Guidance Check

I treated older C/A/Wave-era evidence as leads only. Useful historical facts were kept when confirmed by current docs or current MCP; contradicted current-state claims are marked for historicalization. No Wave2/Wave3 source data was used as proof. The generated C++ and tracker rows are stale generated output, not authoritative source state.

Evidence categories are separated as follows:

- IDA fact: current MCP function boundaries, decompilation, disassembly, callees, xrefs, session health, and lookup results.
- Documentation evidence: current by-* pages for globals, Application/BaramApp, SoundManager, MidiPlayer, EventMan, KeySpeedMgr, SurfaceFlipSurfaces, and Application lifecycle flags.
- Inference: final source-facing helper names such as `RestoreSoundEffectsAfterAppFocus()` and `RestoreMusicAfterAppFocus()` are descriptive first-draft names mapped to existing SoundManager app-focus helper/chunk behavior, not original-symbol proof.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution |
| --- | --- |
| BaramApp/Application ownership split | Keep `BaramApp::OnActivate` under `BaramApp`; the `g_pApplication+0x838` write is Application `m_isRunning` writer evidence, not getter ownership. |
| Exact signature | Current source shape remains `void BaramApp::OnActivate()`. MCP prototype is `void __thiscall(_BYTE *this)` only because class layout is not typed in IDA. |
| Guard byte | `this+0x83a` is a BaramApp/Application transition guard. Use descriptive `m_transitionGuard` in first-draft C++ and document it as inferred. |
| `dword_67A754` | Current singleton page resolves this to `g_pEventMan`; EventMan aggregate maps `0x004a90d0` to `EventMan::ClearKeyboardState()`. |
| `unk_67A93C` | Current [UID:00028Z][ApplicationLifecycleFlags](by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md) resolves `0x0067a93c` as `ApplicationActiveGate`. |
| `dword_67A7CC` and `sub_557470` | Current docs resolve the global as `g_pScreenPane` and the callee as [UID:00039Q][SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md), with a known ScreenPane flag caveat. |
| `unk_67AB1C+0x838/+0x828` | Current docs resolve `unk_67AB1C` as `g_pApplication`; `+0x838` is inferred `Application::m_isRunning`, and `+0x828` is main window handle / `GetMainWindowHandle()`. |
| `dword_67AB48` and `sub_4EFFA0` | Current docs resolve the pointer as `g_pKeySpeedMgr`; current [UID:00018Q] emits file-local `static void ApplyFastKeyboardRepeatSettings()`. |
| SFX restore | Current SoundManager docs resolve `0x0057a790` as app-focus SFX restore helper. Use first-draft `RestoreSoundEffectsAfterAppFocus()`. |
| Music restore tail | Current MCP and SoundManager docs show `0x0057a480` is an app-activation music restore raw chunk. MCP decompile of `0x0057a400` shows the normal `UnmuteMusic` body; `0x0057a480` is the same restore sequence gated by `this+0x4`. Use first-draft `RestoreMusicAfterAppFocus()` and document that it maps to the raw chunk, not a standalone IDA function. |
| Generated-output pollution | Generated `Application.cpp` and tracker still show `80/90` and empty marker, stale against source page `86/91` and current report recommendation. Do not edit generated files manually; validators/generator should refresh them after accepted by-* edits. |
| IDA label | Prior saved label `BaramAppOnActivate` is not present in session `b6b3c97e`; no IDA DB edit was requested in either the report-only pass or implementation callback. Source docs can still use the source-facing method name. |

## Evidence Standards Used

The recommendation uses current MCP disassembly/decompilation as the highest-weight fact, then current by-* docs for source-facing names and ownership. Generated files are only used to identify the queue state and stale empty marker. Historical executed B reports are used only where current docs have incorporated their conclusions.

## Evidence Checked

### Current MCP session

- `server_health` for database `b6b3c97e`: `status:ok`, module `NexusTK.exe`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`:
  - `0x004669c0` -> `sub_4669C0`, size `0xa9`.
  - `BaramAppOnActivate` -> not found.
  - `0x00466a69` -> not a function.
  - `0x00466a70` -> `sub_466A70`, size `0xb3`.
  - `0x0057a480` resolves as part of `sub_4669C0`, confirming the tail chunk association.
- `xrefs_to 0x004669c0`: only data refs at `0x006125f8` and `0x0061d12c`.
- `callees 0x004669c0`: contiguous-body callees `sub_4A90D0`, `sub_557470`, `ShowWindow`, `sub_4EFFA0`, `sub_57A750`, `sub_57A790`, and `sub_57A3D0`.
- `analyze_function 0x004669c0`: decompiles successfully; size `169`; cyclomatic complexity `11`; no direct callers; xrefs from vtable data only.
- `decompile 0x004669c0`: confirms transition guard, event clear, active-gate/screen branch, `g_pApplication+0x838 = 1`, `ShowWindow(..., 9)`, key-repeat restore, SFX restore check, music-mode/playback checks, and the `0x0057a480` tail.
- `disasm 0x004669c0`: confirms `0x00466a62 jmp loc_57A480` and return at `0x00466a68`.
- `decompile 0x0057a400`: confirms the normal SoundManager unmute body calls `MidiPlayer::EnableMidiPlayback`, sets SoundManager bytes `+0x0c` and `+0x04`, conditionally restarts pending stream playback, then calls `SetStreamVolume`.
- `disasm 0x0057a780`: confirms the deactivation-side SFX defer helper clears `+0x41` and sets `+0x5` when SFX was enabled.

### by-* docs and reports checked

- Target and sibling: UID0002GJ `BaramAppOnActivate`; UID0002GK `BaramAppOnDeactivate`.
- Parent/source docs: `by-class/BaramApp.md`, `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`.
- Vtable/data docs: `by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md`, `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`.
- Global/support docs: `g_pEventMan`, `ApplicationLifecycleFlags`, `g_pConfig`, `g_pScreenPane`, `g_pSoundManager`, `g_pApplication`, `g_pKeySpeedMgr`, `g_pMidiPlayer`, `ApplicationDialogTimerAndBackgroundGlobals`.
- Helper docs: `EventManAndEventFactoryHelpers`, `SurfaceFlipSurfaces`, `SoundManagerPlaybackControls`, `MidiPlayerPlaybackToggleMethods`, `ApplyFastKeyboardRepeatSettings`.
- Executed B reports used as leads/current-incorporated context: B005 `ApplicationIsRunning`, B006/B010 KeySpeedMgr aggregate history, B014 BaramApp vtable routing, B003 BaramApp constructor, B004 SoundManager audio helper cluster, B011 MidiPlayer helpers.
- Generated state checked read-only: `auto-generated/NexusTK/app/Application.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`.

### Failed or skipped checks

- One broad MCP xref batch timed out after a successful health check. Narrowed MCP calls succeeded and supplied the required current evidence.
- Initial report-only pass ran no validators because no by-* docs were edited before supervisor validation. Callback validators were run after implementation and are recorded in the checklist.
- No IDA DB changes were requested or made.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002GJ-01 | UID0002GJ remains exact range `0x004669c0-0x00466a69`, BaramApp-owned, virtual-only. | High | MCP `lookup_funcs`, `xrefs_to`; BaramApp vtable docs. | Target Scope, IDA Evidence, Score Rationale; `by-class/BaramApp.md` child matrix. | Incorporate/update. | Applied: target retains exact range and BaramApp owner/emitter; BaramApp child matrix now lists UID0002GJ as `88/92` with virtual-only/current MCP proof. |
| C-0002GJ-02 | Current IDB session does not contain saved label `BaramAppOnActivate`; older C001 saved-label wording is historical. | High | MCP `lookup_funcs BaramAppOnActivate` not found. | Target IDA Evidence/Changes; BaramApp Evidence. | Historicalize, do not delete. | Applied: target and BaramApp evidence state current session `b6b3c97e` reports `sub_4669C0`; C001 saved-label wording is kept as historical context only. |
| C-0002GJ-03 | Current Hex-Rays decompile succeeds; old "Hex-Rays failure blocks final C++" wording is stale. | High | MCP `analyze_function` and `decompile` success. | Target Current Target State, IDA Evidence, Reconstruction Notes. | Rewrite as superseded. | Applied: target evidence/reconstruction notes record current decompile success and supersede the old no-C++ blocker. |
| C-0002GJ-04 | `this+0x83a` is activation transition guard; source name remains descriptive. | Medium-high | MCP disasm/decompile; sibling OnDeactivate same guard. | Target Signature/State and C++ note. | Incorporate with inferred-name caveat. | Applied: target formal C++ uses `m_transitionGuard`, and target notes explicitly mark that spelling as inferred. |
| C-0002GJ-05 | `g_pApplication+0x838 = 1` is Application `m_isRunning` writer evidence, not BaramApp field ownership. | High | MCP `0x004669f5`; B005 ApplicationIsRunning; target current docs. | Target Behavior; Application/BaramApp support docs if touched. | Preserve and update. | Applied/already-present: target and BaramApp document the activation write; `by-file/Application.md` and `by-class/Application.md` already carry same-or-greater `m_isRunning` ownership/write evidence, so they were not edited. |
| C-0002GJ-06 | `dword_67A754`/`sub_4A90D0` should be documented as `g_pEventMan->ClearKeyboardState()`. | Medium-high | `g_pEventMan` page; EventMan aggregate row `0x004a90d0`; MCP call at `0x004669d9`. | Target Behavior/C++; optional EventMan support already present. | Incorporate in target; support already present. | Applied/already-present: target formal C++ and behavior use `g_pEventMan->ClearKeyboardState()`; no EventMan support edit was needed. |
| C-0002GJ-07 | `dword_67A93C` is `ApplicationActiveGate`, and activation only restores the map/window path when it is clear. | High | ApplicationLifecycleFlags doc; MCP `cmp unk_67A93C,0`. | Target Behavior/C++. | Incorporate. | Applied/already-present: target formal C++ uses `ApplicationActiveGate == 0`; `ApplicationLifecycleFlags` already documents activation/deactivation reader families at same-or-greater detail. |
| C-0002GJ-08 | `sub_557470(g_pScreenPane)` is the SurfaceFlipSurfaces setup-side helper; keep Surface/ScreenPane caveat. | Medium-high | SurfaceFlipSurfaces doc; MCP `0x00466a02`; ScreenPane flag caveat. | Target Behavior/C++; `SurfaceFlipSurfaces` support if accepted. | Incorporate and cross-link. | Applied: target formal C++ calls `SurfaceFlipSurfaces(g_pScreenPane)`; SurfaceFlipSurfaces now records UID0002GJ caller `0x00466a02` and preserves owner/caveat. |
| C-0002GJ-09 | `sub_4EFFA0` should remain file-local `ApplyFastKeyboardRepeatSettings()` despite `g_pKeySpeedMgr` null-check caller context. | High | Current ApplyFastKeyboardRepeatSettings page; KeySpeedMgrLayout supersedes B006 member interpretation; MCP call at `0x00466a24`. | Target Behavior/C++; no support edit required unless callback wants caller note. | Incorporate; preserve rejected member-method history only if target mentions it. | Applied/already-present: target formal C++ calls `ApplyFastKeyboardRepeatSettings()` under the `g_pKeySpeedMgr` check; the helper page already documents caller `0x00466a24`, file-local ownership, and rejected member-method history. |
| C-0002GJ-10 | SFX restore check maps to SoundManager app-focus SFX restore helper `0x0057a790`. | High for behavior, medium for final name | SoundManagerPlaybackControls doc; MCP callee `sub_57A790`. | Target C++ and SoundManager support. | Incorporate with descriptive helper name. | Applied: target formal C++ uses `RestoreSoundEffectsAfterAppFocus()` with inferred-name caveat; SoundManagerPlaybackControls documents it as descriptive source-facing abstraction over `0x0057a790`. |
| C-0002GJ-11 | Music restore tail `0x0057a480-0x0057a4d8` is a raw app-activation SoundManager chunk, not a standalone function; first-draft source should call a SoundManager focus-restore abstraction. | High for binary behavior, medium for helper spelling | MCP `0x00466a62 -> 0x0057a480`, decompile target, decompile `0x0057a400`, SoundManagerPlaybackControls raw chunk rows. | Target C++ and SoundManagerPlaybackControls. | Incorporate; explicitly state no new by-memory child. | Applied: target and SoundManagerPlaybackControls record the non-contiguous tail, `0x0057a400` comparison, `RestoreMusicAfterAppFocus()` abstraction, and no-new-child decision. |
| C-0002GJ-12 | Generated Application.cpp/tracker rows are stale and must refresh through validator/generator, not manual edits. | High | Read-only generated file/tracker checks. | Target Changes; Implementation checklist. | Record generated refresh expectation. | Applied: target validator `000000000495` completed generated refresh; read-only generated check shows Application.cpp header `validator-command-id: 000000000496` and UID0002GJ real C++ at `88/92`. Tracker execution remains supervisor-owned through `execute_report`; no manual generated/tracker edits were made. |

## Positive Evidence Summary

- Current MCP proves exact function boundary, virtual-only reachability, successful decompilation, and the non-contiguous audio tail association.
- Current by-* docs resolve every global and helper family that previously blocked the emitter to source-facing names or explicitly documented descriptive abstractions.
- The only remaining non-final names are field/helper spellings, not ownership/range/source-placement blockers. They can be carried as first-draft descriptive names in the formal C++ block with caveats.

## IDA MCP Facts

- Function start: `0x004669c0`, size `0xa9`, exclusive end `0x00466a69`.
- Successor: `0x00466a70` is sibling deactivation function, size `0xb3`.
- Tail chunk: `0x0057a480` resolves into `sub_4669C0`; IDA does not model it as a separate SoundManager function.
- Vtable refs: `0x006125f8` and `0x0061d12c` only.
- Contiguous callees: `sub_4A90D0`, `sub_557470`, `ShowWindow`, `sub_4EFFA0`, `sub_57A750`, `sub_57A790`, `sub_57A3D0`.
- Tail callees in decompilation: `sub_5260B0`, `_AIL_stream_status@4`, `sub_579E30`, `sub_57A340`.
- Negative facts: no current `BaramAppOnActivate` IDA label; no ordinary direct code callers; no current MCP failure after narrowed calls.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004669c0-0x00466a69` | UID0002GJ target | `BaramApp::OnActivate` | TRUE | BaramApp | current `86/91`, recommended `88/92` | Should emit first-draft C++. |
| `0x00466a70-0x00466b23` | UID0002GK sibling | `BaramApp::OnDeactivate` | TRUE | BaramApp | `86/91` | Not in scope for C++; use only as guard/sibling evidence. |
| `0x0057a480-0x0057a4d8` | inside UID0001I9 aggregate | Raw app-activation music restore chunk | TRUE through SoundManager aggregate | SoundManager | aggregate `86/90` | No standalone child; support text should map target C++ helper. |
| `0x0057a790-0x0057a7a9` | inside UID0001I9 aggregate | App-focus SFX restore helper | TRUE through SoundManager aggregate | SoundManager | aggregate `86/90` | Source-facing helper name in target C++. |
| `0x004effa0-0x004effbd` | UID00018Q | Apply fast keyboard repeat settings | TRUE | KeySpeedMgr file | `88/92` | Already emits file-local helper. |
| `0x00557470-0x0055769d` | UID00039Q | SurfaceFlipSurfaces | TRUE | Surface file with ScreenPane caveat | `85/88` | Existing source-facing dependency; target should link/use name. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006125f8 -> 0x004669c0` | data xref | Application/BaramApp vtable route. |
| `0x0061d12c -> 0x004669c0` | data xref | BaramApp primary vtable route. |
| `0x004669d9 -> 0x004a90d0` | call | `g_pEventMan->ClearKeyboardState()`. |
| `0x00466a02 -> 0x00557470` | call | `SurfaceFlipSurfaces(g_pScreenPane)`. |
| `0x00466a14 -> ShowWindow` | call | `ShowWindow(g_pApplication->mainWindow, SW_RESTORE)`. |
| `0x00466a24 -> 0x004effa0` | call | `ApplyFastKeyboardRepeatSettings()`. |
| `0x00466a32 -> 0x0057a750` | call | `SoundManager::IsSoundEffectsEnabled()`. |
| `0x00466a3d -> 0x0057a790` | call | SFX app-focus restore helper. |
| `0x00466a47` | config read | `g_pConfig+0x291908` music source/playback mode dword. |
| `0x00466a52 -> 0x0057a3d0` | call | `SoundManager::IsPlaybackEnabled()`. |
| `0x00466a62 -> 0x0057a480` | tail jump | Raw SoundManager app-focus music restore chunk. |

## Documentation Evidence And IDA Status

Current docs supporting the recommendation:

- `by-class/BaramApp.md` already places activation/deactivation under BaramApp and describes activation as foreground transition policy.
- `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` already emits `Application *g_pApplication = NULL;` and documents Application-owned storage.
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md` already names `ApplicationActiveGate`.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` already documents the `+0x291908..+0x291914` music-control cluster.
- `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` already documents the raw app-activation music restore chunk and app-focus SFX helpers.
- `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md` already emits the file-local helper.

Existing docs that must be corrected:

- Target UID0002GJ says the current IDA label is saved and that Hex-Rays currently fails; both are stale under session `b6b3c97e`.
- Target UID0002GJ says final C++ remains blank because the target cannot safely model helper/global names. That is superseded by current support docs and the first-draft helper abstractions in this report.
- `by-class/BaramApp.md` child matrix still says UID0002GJ has a saved IDA label and blank final C++.

Generated state:

- Generated Application.cpp/tracker rows are stale at `80/90` with empty marker. Do not edit them manually.

## Ranked Ownership Analysis

### 1. BaramApp under Application source module

- Evidence for: vtable slots route to BaramApp; BaramApp class docs list OnActivate; behavior is foreground transition policy; sibling OnDeactivate mirrors route; Application file is current source module for BaramApp.
- Evidence against: it writes Application-owned `m_isRunning` and calls several subsystem helpers.
- Decision: accepted. Those writes/calls are lifecycle policy dependencies, not direct ownership moves.

### 2. Application class/file direct ownership

- Evidence for: `g_pApplication+0x838` write and main-window handle use.
- Evidence against: vtable route and class docs place this as `BaramApp::OnActivate`; Application owns fields, not this virtual override body.
- Decision: rejected as direct owner; Application remains file/module context and field owner.

### 3. SoundManager ownership / split

- Evidence for: music restore tail lives in SoundManager address neighborhood and manipulates SoundManager/MidiPlayer/Miles state.
- Evidence against: IDA attaches `0x0057a480` as a chunk of `sub_4669C0`; the branch condition and dispatch are part of BaramApp activation policy; existing SoundManager docs already carry the raw chunk as support evidence.
- Decision: reject moving UID0002GJ or creating a standalone target child. Add support text mapping the source-facing `RestoreMusicAfterAppFocus()` abstraction to the raw chunk.

### 4. No-code/no-wrapper

- Evidence for: target has historically been blank because helper names and raw tail representation were unresolved.
- Evidence against: current MCP decompiles the function; current support docs resolve the dependency names; a source-shaped first-draft body can preserve the tail behavior through SoundManager abstractions.
- Decision: rejected. Use first-draft formal C++.

## Source Placement

Recommended placement remains `NexusTK/app/Application.cpp` through `BaramApp`. A separate `BaramApp.cpp` remains possible historically, but current docs consistently keep `BaramApp` in the application-shell module. This report does not recommend creating a new source file.

## Range / Split / Padding / Reclassification Analysis

- No target range split: `0x004669c0-0x00466a69` is exact, with seven `0xcc` bytes before `0x00466a70` per existing target evidence.
- No new child page for `0x0057a480`: current SoundManager docs already classify it as a raw app-focus chunk inside UID0001I9. Creating a standalone by-memory child would contradict IDA's current chunk association and duplicate support evidence.
- No generated-binary/no-code reclassification: this is source-authored virtual method code.

## Negative Evidence Summary

- Direct caller absence does not imply no-code; vtable-only virtual dispatch is expected for this method.
- Application field writes do not transfer method ownership from BaramApp to Application.
- Surface/Sound/Midi/KeySpeed/Event global use does not transfer method ownership; these are subsystem dependencies.
- Current absence of saved IDA label does not block source docs from naming the method `BaramApp::OnActivate`; it only means target docs must stop saying the current session contains the saved label.
- Remaining descriptive helper names are not enough to keep the emitter blank because the behavior and source placement are now documented.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are recommended or were made in the report-only pass or implementation callback.

Source-facing names to use in docs/C++ after supervisor acceptance:

- `BaramApp::OnActivate()`
- `m_transitionGuard` for `this+0x83a` as an inferred temporary field name.
- `ApplicationActiveGate` for `0x0067a93c`.
- `g_pEventMan->ClearKeyboardState()`.
- `SurfaceFlipSurfaces(g_pScreenPane)`.
- `ApplyFastKeyboardRepeatSettings()`.
- `SoundManager::RestoreSoundEffectsAfterAppFocus()` for `0x0057a790`.
- `SoundManager::RestoreMusicAfterAppFocus()` for raw `0x0057a480`, explicitly documented as source-facing abstraction over the raw app-activation music restore chunk, not a standalone IDA function.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Exact formal block to insert in UID0002GJ after supervisor acceptance:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BaramApp::OnActivate()
{
    if (m_transitionGuard != 0) {
        return;
    }

    if (g_pEventMan != NULL) {
        g_pEventMan->ClearKeyboardState();
    }

    if (ApplicationActiveGate == 0 && g_pScreenPane != NULL) {
        g_pApplication->m_isRunning = true;
        SurfaceFlipSurfaces(g_pScreenPane);
        ::ShowWindow(g_pApplication->GetMainWindowHandle(), SW_RESTORE);
    }

    if (g_pKeySpeedMgr != NULL) {
        ApplyFastKeyboardRepeatSettings();
    }

    if (!g_pSoundManager->IsSoundEffectsEnabled()) {
        g_pSoundManager->RestoreSoundEffectsAfterAppFocus();
    }

    if (g_pConfig->m_musicPlaybackMode == 0 &&
        !g_pSoundManager->IsPlaybackEnabled()) {
        g_pSoundManager->RestoreMusicAfterAppFocus();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this preserves behavior:

- The guard and branch order matches MCP decompilation and disassembly.
- `SW_RESTORE` represents the literal `9` passed to `ShowWindow`.
- No null checks are added for `g_pApplication`, `g_pSoundManager`, or `g_pConfig`, matching the binary's assumed singleton availability.
- The SoundManager focus-restore helpers are source-facing abstractions for existing SoundManager behavior. They avoid emitting raw `this+0x4/+0x0c/+0x2c` field manipulation inside `BaramApp`.

Why not lower-level C++:

- Copying the `0x0057a480` tail body into `BaramApp::OnActivate` would make BaramApp appear to own SoundManager/MidiPlayer private state.
- Creating a new raw helper function would contradict current IDA chunk evidence and current SoundManager docs.

## Final Recommendation

Apply these edits after supervisor acceptance:

- Target UID0002GJ:
  - Raise score to `88/92`.
  - Set `EMITTER_POSITION_OPTIONAL:30`.
  - Add the formal C++ block above.
  - Update current MCP evidence with session `b6b3c97e`.
  - Historicalize the prior saved-label and Hex-Rays-failure wording.
  - Preserve the non-contiguous audio-tail evidence, but change it from a final-C++ blocker into the reason for the `SoundManager::RestoreMusicAfterAppFocus()` abstraction.
- `by-class/BaramApp.md`:
  - Update child matrix/status for UID0002GJ to `88/92`, first-draft C++ present, current session label absent, Hex-Rays decompile successful.
  - Preserve class-level C++ blank caveat; this report does not make the broad class declaration final.
- `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`:
  - Add UID0002GJ current MCP evidence that `0x0057a480` is the activation music restore chunk, current IDA attaches it to `sub_4669C0`, and first-draft BaramApp source should call a source-facing focus-restore abstraction rather than creating a standalone child.
  - Add the `0x0057a400` decompile comparison: normal unmute body matches the tail's restore sequence after the app-focus guard.
- `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`:
  - Add or confirm the UID0002GJ activation caller at `0x00466a02` passes `g_pScreenPane` and is foreground restore/setup context. Do not change owner in this callback.
- `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md`:
  - Confirm existing caller detail already covers `0x00466a24`. No edit required unless implementation wants to add the MCP session `b6b3c97e` caller refresh.
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`:
  - Confirm existing active-gate reader list already includes activation/deactivation. No edit required unless target cross-link text is desired.
- `by-file/Application.md` and `by-class/Application.md`:
  - If touched, limit edits to a concise support note that UID0002GJ now emits first-draft BaramApp activation source while preserving Application ownership of `m_isRunning` and main-window handle fields.

## Recommended Target Doc Changes

Target path: `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md`

Required target edits:

- Header: `COMPLETION:88`, `CONFIDENCE:92`, `EMITTER_POSITION_OPTIONAL:30`, formal C++ block above.
- Summary: replace empty-emitter/final-source blocker wording with "current MCP decompiles successfully; first-draft source uses source-facing helper abstractions for the non-contiguous SoundManager restore chunk."
- IDA Evidence: add current MCP session `b6b3c97e`, health ok, function `sub_4669C0` size `0xa9`, no saved current label, successful decompile, vtable xrefs, contiguous callees, tail association.
- Reconstruction Notes: state that old C001 saved-label/Hex-Rays-failure notes are historical. Preserve them as superseded, not current.
- Score Rationale: explain score rise to `88/92`; not higher because field names and SoundManager focus-restore helper spelling are descriptive/inferred, and broad `BaramApp` class layout remains unresolved.

## Recommended Support Doc Changes

| Support path | Exact action |
| --- | --- |
| `by-class/BaramApp.md` | Update UID0002GJ child matrix row and behavior/evidence notes: score `88/92`, current MCP decompile successful, current IDB label still `sub_4669C0`, prior saved-label wording historical, first-draft C++ now present on exact child. Keep broad class C++ blank. |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | Add current UID0002GJ session `b6b3c97e` proof that `0x0057a480-0x0057a4d8` is still IDA-attached to `sub_4669C0`; add the `0x0057a400` comparison showing the normal unmute sequence; document first-draft source-facing `RestoreMusicAfterAppFocus()` / `RestoreSoundEffectsAfterAppFocus()` names as descriptive abstractions, not standalone raw-function promotions. |
| `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md` | Add/confirm the foreground activation caller `0x00466a02` from UID0002GJ passing `g_pScreenPane`; keep current Surface owner and ScreenPane flag caveat unchanged. |
| `by-file/Application.md` | Optional support update if the implementation touches parent docs: record UID0002GJ no longer blank in exact child; Application still owns `m_isRunning` and `GetMainWindowHandle()`, while BaramApp owns transition policy. |
| `by-class/Application.md` | Optional support update if touched with Application file: same limited field-owner/consumer distinction; do not move UID0002GJ to Application class. |
| `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md` | Already contains the UID0002GJ caller and file-local helper conclusion. Explicit no-edit reason: same-or-greater detail already present unless supervisor wants session-refresh text. |
| `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md` | Already contains activation/deactivation reader families. Explicit no-edit reason: same-or-greater detail already present. |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | Already contains `+0x291908..+0x291914` music-control cluster. Explicit no-edit reason: same-or-greater detail already present. |

## Score And Metadata Recommendation

Current score: `86/91`.

Recommended score: `88/92`.

Why completion improves:

- Current MCP closes the stale Hex-Rays failure blocker.
- The report resolves the empty-emitter blocker with formal first-draft C++.
- Current support docs provide source-facing routes for every raw global/helper dependency.

Why not higher:

- `this+0x83a` field spelling remains inferred.
- `RestoreSoundEffectsAfterAppFocus()` and `RestoreMusicAfterAppFocus()` are descriptive source-facing helper names, not original symbols.
- `SurfaceFlipSurfaces` still has a documented Surface-vs-ScreenPane ownership caveat.
- The broad `BaramApp` class declaration/source split remains below final C++ quality.

Score-blocker audit:

- BaramApp/Application split: resolved as BaramApp method with Application field dependency.
- Class layout/secondary base spelling: resolved enough for method C++; broad class declaration remains outside target scope and does not block exact method emission.
- Global names: resolved through current singleton docs.
- Audio-tail/source split: resolved as SoundManager support chunk represented by source-facing focus-restore abstraction; no standalone child.
- ScreenPane/Surface dependency: resolved as existing `SurfaceFlipSurfaces(g_pScreenPane)` with caveat preserved.
- KeySpeedMgr dependency: resolved as file-local helper, not class method.
- Caller/reachability/vtable route: resolved through vtable data refs and no direct callers.
- Final C++ readiness: resolved with first-draft formal block.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Exact original name for `this+0x83a` | Target/sibling docs, MCP disasm/decompile, BaramApp class docs. | Use descriptive `m_transitionGuard`; keeps score below final-audit but does not block first-draft C++. |
| Exact original names for SoundManager focus-restore helpers | SoundManagerPlaybackControls docs, MCP target decompile, MCP `0x0057a400` decompile, MCP `0x0057a780` disasm. | Use descriptive `RestoreSoundEffectsAfterAppFocus()` and `RestoreMusicAfterAppFocus()`; support docs must state they are inferred abstractions. |
| Whether `0x0057a480` should be a child page | Current MCP chunk association and SoundManager docs. | No child. It remains raw chunk support under SoundManagerPlaybackControls and IDA function chunk under UID0002GJ. |
| Whether to request IDA rename | Current user forbids IDA DB writes; current session lacks prior saved label. | No IDA edits. Documentation can use source-facing method name. |

## Validator Results

No validators were run during the initial report-only assignment because no by-* docs were edited. Callback validators were run after the accepted implementation and are recorded below.

Recommended implementation validators after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002GJ-BaramAppOnActivate-empty-emitter-source-quality-removed.md](0002GJ-BaramAppOnActivate-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional Application file/class support edits are applied, also validate those exact files.

Generated-output read-only check expected after target validator/generator refresh:

- `auto-generated/NexusTK/app/Application.cpp` should no longer show UID0002GJ as `Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` should refresh away from the stale `80/90` row after supervisor execution/generator refresh; do not edit manually.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md`

Modified:

- None outside this report.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation received; implementation callback applied.
- [x] Target doc `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md`: score is `88/92`, `EMITTER_POSITION_OPTIONAL:30` is set, formal C++ block contains accepted `BaramApp::OnActivate()`, MCP evidence uses session `b6b3c97e`, prior saved-label/Hex-Rays-failure wording is historicalized, and the non-contiguous audio tail is preserved as the reason for SoundManager focus-restore abstraction.
- [x] Support doc `by-class/BaramApp.md`: UID0002GJ child matrix/status now says `88/92`, first-draft C++ present, current MCP decompile successful, current IDB label `sub_4669C0`, prior `BaramAppOnActivate` label historical; broad class C++ remains blank.
- [x] Support doc `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md`: added UID0002GJ current tail evidence, `0x0057a400` unmute comparison, and descriptive `RestoreSoundEffectsAfterAppFocus()` / `RestoreMusicAfterAppFocus()` abstraction caveat; no standalone child promoted for `0x0057a480`.
- [x] Support doc `by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md`: added UID0002GJ foreground activation caller `0x00466a02` with `g_pScreenPane`, active-gate/screen checks, `m_isRunning` write, and pre-`ShowWindow(..., SW_RESTORE)` ordering; owner unchanged.
- [x] No support edit required for `by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md`: already contains caller `0x00466a24` in `sub_4669C0`, file-local helper conclusion, and rejected B006 member-method history at same-or-greater detail.
- [x] No support edit required for `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`: already documents `ApplicationActiveGate` and activation/deactivation reader families, including `0x004669c0` and `0x00466a70`, at same-or-greater detail.
- [x] No support edit required for `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: already documents `+0x291908..+0x291914` music-control settings used by MusicControlDialog and SoundManager, including playback mode and output/playback selection.
- [x] `by-file/Application.md` and `by-class/Application.md` intentionally excluded from edits: both already document Application ownership of `m_isRunning` at `0x838`, BaramApp activation/deactivation writes, and `GetMainWindowHandle`; the changed target and BaramApp support now carry the UID0002GJ no-longer-blank status, so parent edits would duplicate existing facts.
- [x] Claim And Incorporation Ledger updated after implementation with destination and verification state for every accepted claim.
- [x] Historical/stale assumptions preserved as superseded: C001 saved label, old Hex-Rays failure, old empty-emitter blocker, and stale generated `80/90` row are recorded as historical/generated-pre-refresh state.
- [x] Owner/emitter/reconstructable changes: owner/emitter/reconstructable unchanged; `EMITTER_POSITION_OPTIONAL` set to `30`.
- [x] Split/rename/new-child changes: no split, no new child, no IDA rename; target/support docs document why `0x0057a480` remains a raw SoundManager support chunk rather than a child.
- [x] First-draft C++ applied exactly in the formal UID0002GJ block.
- [x] Validators run for every edited by-* file:
  - `python .\tools\validator.py --mode file --file by-memory\0x004669c0-0x00466a69.BaramAppOnActivate.md --apply --queue-timeout 240 --wait-generated`; exit `0`; `command_id: 000000000495`; `command_timestamp: 2026-06-29T09:34:59-04:00`; `ok: 1`; generated refresh completed. Validator-owned side effects included generated metadata/coverage/projected stats refresh and backup creation; unrelated stale registry/missing-file diagnostics remain validator-owned.
  - `python .\tools\validator.py --mode file --file by-class\BaramApp.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000000496`; `command_timestamp: 2026-06-29T09:35:17-04:00`; `ok: 1`; remaining `missing_ref_uid` warnings are existing BaramApp RTTI/vtable sibling refs `0003P4`, `0003P5`, `0003P6`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000000497`; `command_timestamp: 2026-06-29T09:35:23-04:00`; `ok: 1`; remaining `missing_ref_uid` warning is existing `0003ZJ`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00557470-0x0055769d.SurfaceFlipSurfaces.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000000498`; `command_timestamp: 2026-06-29T09:35:29-04:00`; `ok: 1`; remaining `missing_ref_uid` warning is existing `00039R`.
- [x] Generated output checked read-only after target validation/generator refresh: `auto-generated/NexusTK/app/Application.cpp` header shows `validator-command-id: 000000000496`, newer than target refresh `000000000495`; UID0002GJ appears as `Completion:88 | Confidence:92` with formal `BaramApp::OnActivate()` and no UID0002GJ `Empty Emitter Marker`.
- [x] Leases: B001 leased the target plus `by-class/BaramApp.md`, SoundManagerPlaybackControls, and SurfaceFlipSurfaces for the immediate edit/validator batch. Release attempt returned `B001: No active leases`, and the current lease report has no B001 entry.
- [x] No generated files, coverage reports, project-level generated files, validator/tool state, lock files, IDA DB, or executed-report archives were edited manually; generated/project/tool-state side effects were validator-owned only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md","timestamp":"2026-06-29T09:42:33","uid":"0002GJ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GJ-BaramAppOnActivate-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
