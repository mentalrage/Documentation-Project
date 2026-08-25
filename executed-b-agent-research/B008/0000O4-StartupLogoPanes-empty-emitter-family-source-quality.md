** TARGET-REPORT-UID:0000O4 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0000O4 StartupLogoPanes Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Assignment: initial report `B008-report-0000O4-StartupLogoPanes-empty-emitter-family-20260630`; implementation callback `B008-implement-0000O4-StartupLogoPanes-empty-emitter-family-20260630`.
- Mode: implementation callback completed after supervisor acceptance. Target/support `by-*` docs listed below were edited; generated/tracker/coverage artifacts were not manually edited, only refreshed by scoped validator `--apply --wait-generated` runs.
- Primary target: [UID:0000O4] `by-file/StartupLogoPanes.md`.
- Queue row checked: `auto-generated/-ag-research-tracker.md` -> Files With Empty Emitters lists `StartupLogoPanes` with 28 total emitters, 10 filled, 18 marked empty, 35.7% complete, generated output `auto-generated/NexusTK/app/StartupLogoPanes.cpp`, and no direct by-file B-report coverage.
- Current recommendation: keep the source root as `NexusTK/app/StartupLogoPanes.cpp`, keep `CANONICAL_OWNER:FILE`, and repair the 18 empty markers by adding formal class/source code where the source-authored body is now good enough, adding formal covered-by comments for compiler/source-declared generated artifacts, and reclassifying the one pure aggregate page.
- Recommended file target metadata: `COMPLETION:89`, `CONFIDENCE:90`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`, `CANONICAL_OWNER:FILE`. The score should rise modestly because the file-family output route and empty-emitter disposition are now implementation-ready, but it should remain below final audit due to the still-plausible static-logo/video split and inferred exact original names.
- Key disposition: this is not an ownership failure. The empty markers are stale blank formal blocks and one aggregate/container classification problem inside an otherwise valid `StartupLogoPanes` emitter chain.

## Target

- Target UID: `0000O4`.
- Target path: `by-file/StartupLogoPanes.md`.
- Current target metadata: `COMPLETION:88`, `CONFIDENCE:86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`, `CANONICAL_OWNER:FILE`.
- Current generated output after callback validation: `auto-generated/NexusTK/app/StartupLogoPanes.cpp`, header `validator-command-id: 000000002376`, `validator-refreshed-at: 2026-06-30T05:03:29-04:00`.
- Initial report generated contents before callback: populated emitters for `LogoPane` constructor/destructor/RequestAdvance/OnTimer, `LogoPlayerPane` declaration/constructor/destructor/advance/OnClose, and `TryAdvanceStartupLogoBinkSegment`; the 18 then-empty markers listed below were resolved by the implementation callback section and validators.

## Current Target State

The file page already correctly places the startup static logo pane, retained/alternate logo movie pane, and standalone Bink startup playback helpers in `app/StartupLogoPanes.cpp`. The current file status acknowledges a plausible alternate split into `LogoPane.cpp` and `LogoPlayerPane.cpp`; that is a file-organization caveat only and does not block the present single-file emitter route.

The generated empty markers are:

| UID | Path | Current issue | Recommendation |
| --- | --- | --- | --- |
| `00007G` | `by-class/LogoPane.md` | Class page is reconstructable/emitting but formal C++ is blank. | Add declaration shell with `[[CHILDREN]]`; raise to `90/91`. |
| `0003LG` | `by-memory/0x004f4f70-0x004f4f94.LogoPaneBlitLogoFrame.md` | Source-authored draw method blank under old renderer-name blocker. | Add first-draft `LogoPane::BlitLogoFrame()` using inferred renderer callback name; raise to `88/91`. |
| `0003LH` | `by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleAdvanceRequest.md` | Source-authored adjusted virtual blank under old signature blocker. | Add first-draft method body; raise to `88/91`. |
| `0003LI` | `by-memory/0x004f4fe0-0x004f502c.LogoPaneOnMouseDown.md` | Source-authored mouse handler blank under old event-name blocker. | Add first-draft method body using accepted event type `kEventLeftButtonUp`; raise to `88/91`. |
| `0003LK` | `by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md` | Source-authored ready callback blank under old return/signature blocker. | Add first-draft method body; raise to `88/91`. |
| `0003LL` | `by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md` | Source-authored completion method blank under old callback/helper-name blocker. | Add first-draft method body using current support names; raise to `88/91`. |
| `0002PO` | `by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md` | Source-authored retained helper pair blank under stale "wait for final names" policy. | Add first-draft retained helper pair; raise to `88/91`. |
| `0002PP` | `by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md` | Source-authored queue helper blank under old callback-template blocker. | Add first-draft queue helper; raise to `88/91`. |
| `0002PR` | `by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md` | Compiler scalar deleting wrapper still appears as empty emitter. | Keep metadata/scores, insert formal covered-by comment for UID0002PM. |
| `0003OP` | `by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md` | Source-declared/generated-binary vtable data still appears as empty emitter. | Keep metadata/scores, insert formal covered-by comment for UID00007G. |
| `00019D` | `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md` | Aggregate/island page is not a source-level emitted object. | Reclassify to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, leave C++ blank; raise to `90/92`. |
| `0002PV` | `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md` | Source-authored two-method range blank under old EventHandler naming blocker. | Add first-draft key/mouse handler bodies; raise to `88/91`. |
| `0002PY` | `by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md` | Compiler scalar deleting wrapper still appears as empty emitter. | Keep metadata/scores, insert formal covered-by comment for UID0002PT. |
| `0002ZH` | `by-global/StartupLogoBinkRestartFlag.md` | Source-declared global blank. | Add `static bool g_startupLogoBinkRestartPending = true;`; raise to `88/92`. |
| `0002ZM` | `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md` | Address-level child duplicates by-global declaration. | Keep metadata/scores, insert formal covered-by comment for UID0002ZH. |
| `0003K6` | `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md` | Source-authored standalone Bink playback helper blank under old callback/message-pump blockers. | Add first-draft playback loop body; raise to `89/92`. |
| `0003K7` | `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md` | Source-authored WndProc blank under old sibling/global-name blocker. | Add first-draft WndProc body; raise to `89/93`. |
| `00029G` | `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md` | Source-declared startup Bink globals blank. | Add file-local static declarations; raise to `88/92`. |

## Evidence Checked

- Required workflow files read: `Agent-B008/goal.md`, `Agent-B008/notes.md`, `.codex/skills/ntk-b-agent-workflow/SKILL.md`, `b-agent-research-and-implementation-workflow.md`, `supervisor-rule26-review-and-incorporation-standard.md`, `score-blocker-audit-standard.md`, and `b-agent-report-template.md`.
- `by-structure.md` rules checked: current C++ gate `(COMPLETION + CONFIDENCE) / 2 > 85`, nonblank emitter route requirement, exact formal `RECONSTRUCTION_CPP CODE` requirement for any draft C++, covered-by comment rule for intentionally covered reconstructable items, container/aggregate `RECONSTRUCTABLE:FALSE` rule, source-declared/generated-binary and compiler/linker-generated rebuild handling labels, and `by-memory` own-range-only rule.
- Read-only generated files checked: `auto-generated/-ag-research-tracker.md` and `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.
- Target/support docs checked: `by-file/StartupLogoPanes.md`, `by-class/LogoPane.md`, `by-class/LogoPlayerPane.md`, the 18 empty-marker docs listed above, `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`, `by-class/Event.md`, `by-global/WideApiDispatchTable.md`, `by-global/g_pScreenPane.md`, `by-file/Application.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, and `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`.
- Existing reports searched with `rg` terms including `0000O4`, `StartupLogoPanes`, `StartupLogoPanes.cpp`, `00007G`, `0003LG`, `0003LH`, `0003LI`, `0003LK`, `0003LL`, `0002PO`, `0002PP`, `0002PR`, `0003OP`, `00019D`, `0002PV`, `0002PY`, `0002ZH`, `0002ZM`, `0003K6`, `0003K7`, `00029G`, `LogoPane`, `LogoPlayerPane`, and `StartupLogoBink`.
- Matching prior reports were treated as leads only and rechecked against current docs/MCP. Relevant executed reports included B002 UID0002PO, B001 UID0002PV, B015 UID0002PY, B013 UID00022U, B010 UID0003LF, B001 UID0003LJ, B004/B003/B011 LogoPlayerPane constructor/advance/destructor/close reports, and B002 UID0002PM.
- No Wave2/Wave3 stale output was used as authority. Generated source was used only to identify the current empty markers.

## IDA MCP Facts

MCP was available and used in this pass, not fallback-only.

- `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` returned active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `17592`, `is_analyzing:false`.
- `server_health` for that session returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and string cache ready.
- `lookup_funcs` exact-address results:
  - `0x004f4f70` size `0x24`, `0x004f4fa0` size `0x3e`, `0x004f4fe0` size `0x4c`, `0x004f5040` size `0x2a`, `0x004f5070` size `0x31`, `0x004f5250` size `0x8e`, `0x004f5300` size `0xa8`.
  - `0x004f55d0` size `0x2c`, `0x004f5600` size `0x1d`, `0x004f5680` size `0x8c`.
  - `0x004f5710` size `0x2b6`, `0x004f59d0` size `0xf7`, `0x004f5ae0` size `0x3e`.
- `xrefs_to` facts:
  - `0x004f4f70`, `0x004f4fa0`, and `0x004f4fe0` are vtable/data referenced from `0x0061cfbc`, `0x0061cfcc`, and `0x0061cfc8`.
  - `0x004f5040` is bound at constructor site `0x004f4e67`.
  - `0x004f5070` is the member callback target stored by `0x004f52a5` inside `LogoPane::QueueAdvanceToNextScreen`.
  - `0x004f5250` has callers at raw `0x004f4f53`, `0x004f4fc6`, `0x004f5012`, and UID0003LJ `0x004f5036`.
  - `0x004f55d0` and `0x004f5600` are vtable/data referenced at `0x0061d078` and `0x0061d074`; both call `0x004f5570`.
  - `0x004f5680` is reached from adjustor thunks `0x004f5670`/`0x004f567b` and primary vtable data `0x0061d018`.
  - `0x004f5710` has one code caller at `0x004f63b5` inside `ApplicationStartup`.
  - `0x004f59d0` is installed from `0x004f585d` inside `0x004f5710`.
  - `0x004f5ae0` is called from `0x004f5aaf` inside the WndProc.
  - `0x0066db42` has only restart helper read/clear refs at `0x004f5ae0` and `0x004f5afa`; `0x0066db43` has no xrefs.
  - strings `LOGO.PAK`, `LOGO.PAD`, and `Bink Error` are referenced from `0x004f5710`.
- `get_bytes` facts:
  - `0x0066db42` bytes are `0x1 0x0`.
  - `0x0069b45c-0x0069b480` is 36 zero bytes.
  - Padding after `0x004f59c6`, `0x004f5ac7`, and `0x004f50a1` is all `0xcc`.
- `get_global_value` facts:
  - `0x0066db42 == 0x1`, `0x0066db43 == 0x0`.
  - Each dword slot from `0x0069b45c` through `0x0069b47c` returned zero.
- `get_string` facts:
  - `0x0061d0c4` = `LOGO.PAK`.
  - `0x0061d0d8` = `LOGO.PAD`.
  - `0x0061d0ec` = `Bink Error`.
- `get_int` vtable facts:
  - `0x0061cff4 -> 0x004f52e9`, `0x0061cff8 -> 0x004f5030`.
  - `0x0061d018 -> 0x004f5680`, `0x0061d070 -> 0x004f566a`, `0x0061d074 -> 0x004f5600`, `0x0061d078 -> 0x004f55d0`, `0x0061d0a0 -> 0x004f5675`.
- Decompilation facts:
  - `0x004f4fa0` and `0x004f4fe0` both normalize `this - 0xa0`, test ready/queued flags, remove pending timers via `0x00597600`, and queue through `0x004f5250`, or latch the early request byte.
  - `0x004f5040` sets ready byte `+0x34d` and schedules timer id `0` through `0x005975e0` with delay `3000` or `0`.
  - `0x004f5070` invokes callback slot `+0x0c`, deletes the callback object via slot `+0x00` with flag `1`, calls `0x00557430`, and tail-calls `0x00544690`.
  - `0x004f5250` sets queued byte `+0x34e`, allocates 24 bytes, builds `PlainMemberFunctionObject0<void (__thiscall LogoPane::*)(void), LogoPane>` targeting `0x004f5070`, captures `this`, and queues through `0x00559110`.
  - `0x004f55d0` handles event type `8`, keys Enter/Escape/Space, calls `0x004f5570`, and returns `1`. `0x004f5600` handles event type `3`, calls `0x004f5570`, and returns `1`.
  - `0x004f5710` is `void __cdecl`, selects `LOGO.PAK`/`LOGO.PAD`, opens a memory-backed Bink stream with flags `67633152` (`BINKFROMMEMORY | BINKNOSKIP`), installs `0x004f59d0` as WndProc, pumps messages/frames, restores the old WndProc, closes Bink, optionally deletes object at `0x0069b470`, and shows `Bink Error` on `BinkBufferOpen` failure.
  - `0x004f59d0` is `LRESULT __stdcall` WndProc handling `WM_ERASEBKGND`, `WM_DESTROY`, `WM_PAINT`, `WM_CLOSE`, `WM_KEYDOWN`, and `WM_LBUTTONDOWN`, otherwise forwarding to `DefWindowProcW`.

## Heuristic / Inference Reanalysis And Validation

The current docs already prove most behavior. The blocker is that many pages still preserve older "final C++ blank until exact names are final" text. That was acceptable when the task was a narrow source-quality pass, but it is now stale for this family-level empty-emitter assignment under the current by-structure C++ gate. Exact original symbol proof is not required when current MCP, owner route, field offsets, callee identities, and support names make a first-draft human-written source shape defensible.

Resolved source-quality decisions:

- `LogoPane` should emit a declaration shell. Current class docs already define the layout and method family strongly enough. The existing blank class block is directly responsible for one empty marker and forces method bodies to appear without a class declaration in generated output.
- The `LogoPane` adjusted handlers are not separate input-handler owners. `this - 0xa0` is the Pane/EventHandler subobject adjustment back to `LogoPane`, matching surrounding pane handler patterns.
- Event type `3` is `kEventLeftButtonUp`, and type `8` is `kEventKeyDown`, supported by EventMan and Event docs. These names are strong enough for the `LogoPlayerPane` input pair and `LogoPane` mouse handler first drafts.
- `0x00557430` is already documented as `g_pScreenPane->ShowCursor(true)` and `0x00544690` as `Pane::MarkForDeletion`. The old raw helper labels should not block UID0003LL.
- `0x0069be8c` and `0x0069be64` are already documented in `WideApiDispatchTable` as `g_pfnPeekMessage` / `PeekMessageW` and `g_pfnDispatchMessage` / `DispatchMessageW`. The standalone Bink loop can use those names.
- `Application::GetMainWindowHandle()` is already source-ready and is the correct source-facing replacement for `sub_4651D0(g_pApplication)`.
- `LogoPane` scalar deleting destructor, `LogoPlayerPane` scalar deleting destructor, and `LogoPane` vtable bytes are not handwritten source bodies. They should still be recognized, but formal covered-by comments are the cleanest way to avoid empty-emitter markers while preserving current reconstructable/source-declared evidence.
- UID00019D is a physical island/aggregate page over constructor, destructor, method, thunk, wrapper, and AUTOBUF children. Under by-structure container rules it is not itself a source-level object because [UID:00007H] carries the class declaration and exact child pages carry method bodies. Reclassify the aggregate to `RECONSTRUCTABLE:FALSE` with blank emitters rather than adding a fake comment.

Rejected alternatives:

- Do not move `LogoPane` to a generic image-loader, palette, zlib, UI-dialog, or MainUiLayerSlots owner. The field layout, `.LGO` contract, constructor, and startup completion path are LogoPane/startup-logo specific.
- Do not move `LogoPlayerPane` to `VideoPlayerPane`. `VideoPlayerPane` owns reusable Bink frame plumbing; `LogoPlayerPane` owns startup segmented payload and skip policy.
- Do not split `StartupLogoPanes.cpp` during this callback. A future `LogoPane.cpp`/`LogoPlayerPane.cpp` split remains plausible, but current file evidence and generated route are strong enough to repair empty emitters without renaming the file root.
- Do not hand-port vtable bytes, adjustor thunks, or scalar deleting destructor mechanics as normal C++ methods. The source representation is class declarations plus ordinary destructor bodies.
- Do not treat retained helper no-xref status for UID0002PO as padding or a reason to remove emission. Current constructor duplicate behavior and helper body shape support retained out-of-line helper definitions.
- Do not keep old `95/95` final-source phrasing as a blocker. Current by-structure uses the combined-score gate and requires formal first-draft C++ or a target-specific no-code proof for eligible emitters.

## Ranked Ownership Analysis

### 1. Existing `StartupLogoPanes.cpp` file root [UID:0000O4]

- Evidence for: file page already owns the startup static logo and standalone Bink startup flow; `ApplicationStartup` constructs `LogoPane` and calls `PlayStartupLogoBinkFile`; all 18 empty markers either route directly to UID0000O4 or through `LogoPane`/`LogoPlayerPane` classes that route to UID0000O4; generated source already contains the populated sibling code in `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.
- Evidence against: a two-file split into `LogoPane.cpp` and `LogoPlayerPane.cpp` remains plausible because static `.LGO` rendering and Bink playback have different dependencies.
- Decision: keep UID0000O4 as current source root and repair empty emitters in place. Do not split during this report's implementation callback.

### 2. Class parents `LogoPane` [UID00007G] and `LogoPlayerPane` [UID00007H]

- Evidence for: vtable slots, method bodies, fields, constructors/destructors, and callback objects all point to the two classes. They are the correct direct owners for methods and class declarations.
- Evidence against: class-level broad C++ should not contain method bodies except via `[[CHILDREN]]`.
- Decision: add/keep declaration shells and route exact method bodies through children.

### 3. `VideoPlayerPane`, `Pane`, `EventHandler`, `PlatformApi`, and support globals

- Evidence for: these supply base methods, input/message types, platform function-pointer storage, and screen/cursor helpers.
- Evidence against: they are dependencies/consumers, not source owners for startup-logo-specific behavior and state.
- Decision: use them as already-present support facts only; do not move ownership.

## Range / Split / Padding / Reclassification Analysis

- UID00019D should be reclassified from reconstructable emitter to non-emitting aggregate/index. Its exact children already cover source-bearing methods and generated ABI support.
- UID0002PR, UID0002PY, UID0003OP, and UID0002ZM should stay as evidence pages but receive formal minimal covered-by comments. This preserves their current source-policy evidence while preventing generated empty markers.
- No new child pages are needed. Exact method/data ranges already exist for every empty marker in this file family.
- No `by-memory` parent should receive C++ for child ranges outside its own range. The class pages should use declarations and `[[CHILDREN]]`; exact by-memory pages own their own bodies.

## First-Draft C++ Recommendation

All code below is exact formal insertion text for each target's `RECONSTRUCTION_CPP CODE` block after supervisor acceptance. The fenced blocks are `text` intentionally, because the sentinel/header lines are Markdown metadata, not C++.

### [UID00007G] `by-class/LogoPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;
struct MouseEvent;

class LogoPane : public Pane
{
public:
    LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback);
    virtual ~LogoPane();

protected:
    virtual int BlitLogoFrame();
    virtual bool HandleAdvanceRequest(int request);
    virtual bool OnMouseDown(const MouseEvent *event);
    virtual bool OnTimer(int timerId, int param1, int param2);

private:
    void RequestAdvance();
    void MarkReadyAndScheduleAdvance();
    void AdvanceToNextScreen();
    void LoadStaticLogoFromFile(const wchar_t *logoPath);
    void AttachStaticLogoSurface();
    void QueueAdvanceToNextScreen();

    EPFTileContext m_logoTileContext;       // +0x0f8
    DLPalette m_logoPalette;                // +0x120
    bool m_advanceRequestedBeforeReady;     // +0x34c
    bool m_logoReady;                       // +0x34d
    bool m_advanceQueued;                   // +0x34e
    unsigned char m_reserved34f;
    FunctionObject0 *m_completionCallback;  // +0x350
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0003LG] `LogoPaneBlitLogoFrame`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int LogoPane::BlitLogoFrame()
{
    return g_pfnDrawEPFTile(
        &m_logoTileContext,
        &m_logoTileContext.bounds,
        &m_bounds,
        0,
        &m_logoPalette,
        0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`g_pfnDrawEPFTile` and inherited `m_bounds` are inferred source-facing names for the renderer callback at `0x0069b3e8` and the inherited `Pane` state at `this + 0x44`.

### [UID0003LH] `LogoPaneHandleAdvanceRequest`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool LogoPane::HandleAdvanceRequest(int)
{
    if (!m_logoReady || m_advanceQueued) {
        m_advanceRequestedBeforeReady = true;
        return true;
    }

    TimerHandler::RemovePendingTimers();
    QueueAdvanceToNextScreen();
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0003LI] `LogoPaneOnMouseDown`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool LogoPane::OnMouseDown(const MouseEvent *event)
{
    if (event->type == kEventLeftButtonUp) {
        if (m_logoReady && !m_advanceQueued) {
            TimerHandler::RemovePendingTimers();
            QueueAdvanceToNextScreen();
            return true;
        }

        m_advanceRequestedBeforeReady = true;
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The by-memory filename says `OnMouseDown`, but the event guard is type `3`, currently documented as left-button release/up. Preserve both by documenting the event-type correction.

### [UID0003LK] `LogoPaneMarkReadyAndScheduleAdvance`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LogoPane::MarkReadyAndScheduleAdvance()
{
    m_logoReady = true;

    const int delay = m_advanceRequestedBeforeReady ? 0 : 3000;
    TimerHandler::ScheduleTimer(0, delay, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0003LL] `LogoPaneAdvanceToNextScreen`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LogoPane::AdvanceToNextScreen()
{
    m_completionCallback->Invoke();
    delete m_completionCallback;

    g_pScreenPane->ShowCursor(true);
    MarkForDeletion();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The binary does not null-check before `Invoke`, so the source body should not add one. `delete m_completionCallback` preserves the compiler null-check before deleting-slot invocation.

### [UID0002PO] `LogoPaneStaticLogoLoaderHelpers`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LogoPane::LoadStaticLogoFromFile(const wchar_t *logoPath)
{
    FILE *logoFile = g_pfnWideOpenFile(logoPath, L"rb");
    if (logoFile == 0)
        return;

    unsigned int compressedImageSize = 0;
    if (fread(&compressedImageSize, sizeof(compressedImageSize), 1, logoFile) != 1)
        return;

    unsigned char *compressedImage =
        static_cast<unsigned char *>(malloc(compressedImageSize));
    if (fread(compressedImage, 1, compressedImageSize, logoFile) != compressedImageSize)
        return;

    uLongf decodedImageSize = static_cast<uLongf>(g_screenWidth * g_screenHeight);
    unsigned char *decodedImage =
        static_cast<unsigned char *>(malloc(decodedImageSize));
    Uncompress(decodedImage, &decodedImageSize, compressedImage, compressedImageSize);
    free(compressedImage);

    m_logoTileContext.pixelData = decodedImage;
    m_logoTileContext.encodedMaskBytes = 0;
    m_logoTileContext.rowStridePixels = g_screenWidth;
    m_logoTileContext.encodedMaskByteCount = 0;
    m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    OnBoundsChangedOrInvalidate(0);

    unsigned int paletteSize = 0;
    if (fread(&paletteSize, sizeof(paletteSize), 1, logoFile) != 1)
        return;

    unsigned char *paletteBytes =
        static_cast<unsigned char *>(malloc(paletteSize));
    if (fread(paletteBytes, 1, paletteSize, logoFile) != paletteSize)
        return;

    m_logoPalette.LoadFromBitmapPalette(paletteBytes, paletteSize);
    free(paletteBytes);
    m_logoTileContext.BuildEncodedMask();
    fclose(logoFile);
}

void LogoPane::AttachStaticLogoSurface()
{
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetSurfaceOriginOrVisibleState(0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The failure-path early returns intentionally do not normalize cleanup; current docs say the binary closes the file only on the fully successful palette path.

### [UID0002PP] `LogoPaneQueueAdvanceToNextScreen`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void LogoPane::QueueAdvanceToNextScreen()
{
    typedef void (__thiscall LogoPane::*LogoPaneCallback0)();

    m_advanceQueued = true;
    g_pScreenPane->QueueFadeOutCallback(
        new PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>(
            &LogoPane::AdvanceToNextScreen, 0, this));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0002PR] `LogoPaneScalarDeletingDestructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0002PM].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0003OP] `LogoPaneVtableData`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:00007G].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID00019D] `LogoPlayerPane` Aggregate

No C++ insertion. Change metadata to:

```text
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave the formal C++ block blank. This page is a reviewed aggregate/index, not the source-level class declaration or a single method body.

### [UID0002PV] `LogoPlayerPaneInputSkipHandlers`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool LogoPlayerPane::OnKeyEvent(const KeyEvent *event)
{
    if (event->type == kEventKeyDown) {
        const unsigned char key = event->keyCode;
        if (key == VK_RETURN || key == VK_ESCAPE || key == VK_SPACE)
            AdvanceToNextSegment();
    }

    return true;
}

bool LogoPlayerPane::OnMouseEvent(const MouseEvent *event)
{
    if (event->type == kEventLeftButtonUp)
        AdvanceToNextSegment();

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0002PY] `LogoPlayerPaneScalarDeletingDestructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0002PT].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0002ZH] `StartupLogoBinkRestartFlag`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool g_startupLogoBinkRestartPending = true;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0002ZM] `StartupLogoBinkRestartFlag` Memory Child

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0002ZH].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID0003K6] `PlayStartupLogoBinkFile`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void PlayStartupLogoBinkFile()
{
    g_startupLogoBinkWindow = g_pApplication->GetMainWindowHandle();

    StdioFile file;
    const wchar_t *moviePath = g_useEpfAssets ? L"LOGO.PAK" : L"LOGO.PAD";
    if (!PathExistsViaStat(moviePath))
        return;

    file.Open(moviePath);

    _AUTOBUF<unsigned char> movieData;
    file.ReadRemaining(movieData);

    const unsigned int firstSegmentSize =
        *reinterpret_cast<const unsigned int *>(movieData.m_data);
    unsigned char *firstSegment = movieData.m_data + sizeof(unsigned int);

    g_startupLogoBinkNextSegment = firstSegment + firstSegmentSize;
    g_startupLogoBinkRemainingSegmentSize =
        movieData.m_count - firstSegmentSize - sizeof(unsigned int);

    void *soundSystem = g_pSoundManager->GetBinkSoundSystem();
    if (soundSystem != 0)
        BinkSetSoundSystem(BinkOpenMiles, soundSystem);

    g_startupLogoBinkHandle =
        BinkOpen(firstSegment, BINKFROMMEMORY | BINKNOSKIP);
    g_startupLogoBinkBuffer =
        BinkBufferOpen(
            g_startupLogoBinkWindow,
            g_startupLogoBinkHandle->Width,
            g_startupLogoBinkHandle->Height,
            2);

    if (g_startupLogoBinkBuffer == 0) {
        MessageBoxA(0, BinkBufferGetError(), "Bink Error", MB_ICONERROR);
        BinkClose(g_startupLogoBinkHandle);
        return;
    }

    LONG oldWndProc = SetWindowLongA(
        g_startupLogoBinkWindow,
        GWL_WNDPROC,
        reinterpret_cast<LONG>(StartupLogoBinkWndProc));

    g_startupLogoBinkLoopActive = true;
    do {
        MSG message;
        if (g_pfnPeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            g_pfnDispatchMessage(&message);
        } else if (!BinkWait(g_startupLogoBinkHandle)) {
            BinkDoFrame(g_startupLogoBinkHandle);

            if (BinkBufferLock(g_startupLogoBinkBuffer)) {
                BinkCopyToBuffer(
                    g_startupLogoBinkHandle,
                    g_startupLogoBinkBuffer->Buffer,
                    g_startupLogoBinkBuffer->BufferPitch,
                    g_startupLogoBinkBuffer->Height,
                    0,
                    0,
                    g_startupLogoBinkBuffer->SurfaceType);
                BinkBufferUnlock(g_startupLogoBinkBuffer);
            }

            const int rectCount =
                BinkGetRects(g_startupLogoBinkHandle, g_startupLogoBinkBuffer->SurfaceType);
            BinkBufferBlit(
                g_startupLogoBinkBuffer,
                g_startupLogoBinkHandle->FrameRects,
                rectCount);

            if (g_startupLogoBinkHandle->FrameNum == g_startupLogoBinkHandle->Frames)
                g_startupLogoBinkLoopActive = false;
            else
                BinkNextFrame(g_startupLogoBinkHandle);
        }
    } while (g_startupLogoBinkLoopActive);

    SetWindowLongA(g_startupLogoBinkWindow, GWL_WNDPROC, oldWndProc);
    BinkClose(g_startupLogoBinkHandle);
    delete g_startupLogoBinkTeardownCallback;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`g_startupLogoBinkTeardownCallback` is an inferred source-facing name for the object slot at `0x0069b470`. The binary invokes the first vtable entry with delete flag `1`, so source-level `delete` is the best current representation; the report does not claim an `Invoke()` callback call here.

### [UID0003K7] `StartupLogoBinkWndProc`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static LRESULT CALLBACK StartupLogoBinkWndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (message) {
    case WM_ERASEBKGND:
        return 1;

    case WM_DESTROY:
    case WM_CLOSE:
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT paint;
        HDC dc = BeginPaint(hWnd, &paint);
        PatBlt(dc, 0, 0, 4096, 4096, BLACKNESS);
        EndPaint(hWnd, &paint);
        return 0;
    }

    case WM_KEYDOWN:
    case WM_LBUTTONDOWN:
        TryAdvanceStartupLogoBinkSegment();
        return 0;
    }

    return DefWindowProcW(hWnd, message, wParam, lParam);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID00029G] `StartupLogoBinkPlaybackGlobals`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static BINK *g_startupLogoBinkHandle = 0;
static BINKBUFFER *g_startupLogoBinkBuffer = 0;
static unsigned int g_startupLogoBinkReserved0 = 0;
static HWND g_startupLogoBinkWindow = 0;
static bool g_startupLogoBinkLoopActive = false;
static unsigned char g_startupLogoBinkLoopReserved[3] = { 0, 0, 0 };
static FunctionObject0 *g_startupLogoBinkTeardownCallback = 0;
static unsigned char *g_startupLogoBinkNextSegment = 0;
static unsigned int g_startupLogoBinkRemainingSegmentSize = 0;
static unsigned int g_startupLogoBinkReserved1 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Target / Support Doc Changes

Primary target:

- `by-file/StartupLogoPanes.md`: update score to `89/90`; add a 2026-06-30 B008 empty-emitter family note preserving the 18-marker inventory, current MCP session evidence, source-placement decision, accepted C++/no-code/reclassification dispositions, and unchanged `NexusTK/app/StartupLogoPanes.cpp` source root.

Direct support docs to edit after supervisor acceptance:

- `by-class/LogoPane.md`: add the exact declaration C++ block, update score to `90/91`, update method rows for UID0003LG/3LH/3LI/3LK/3LL/2PO/2PP as first-draft C++ ready, and historicalize old blank-C++ blocker wording rather than deleting evidence.
- `by-class/LogoPlayerPane.md`: keep existing declaration, add support notes that UID0002PV now emits formal handler C++ and UID0002PY emits only a covered-by comment; preserve constructor-caller absence and retained/alternate movie-pane caveat.
- `by-memory/0x004f4f70-0x004f4f94.LogoPaneBlitLogoFrame.md`: insert formal C++ and document `g_pfnDrawEPFTile`/`m_bounds` as inferred.
- `by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleAdvanceRequest.md`: insert formal C++ and remove the old "exact virtual signature blocks C++" conclusion as superseded.
- `by-memory/0x004f4fe0-0x004f502c.LogoPaneOnMouseDown.md`: insert formal C++, preserve type `3` as left-button release/up and the filename/method-name caveat.
- `by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md`: insert formal C++.
- `by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md`: insert formal C++ using `g_pScreenPane->ShowCursor(true)` and `MarkForDeletion()`.
- `by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md`: insert formal helper-pair C++, preserve retained-helper/no-xref caveat and failure cleanup fidelity.
- `by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md`: insert formal C++.
- `by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md`: insert formal covered-by comment for UID0002PM and keep ABI/no-code proof.
- `by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md`: insert formal covered-by comment for UID00007G and keep source-declared/generated-binary vtable policy.
- `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`: reclassify to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, update score to `90/92`, and preserve aggregate/index evidence.
- `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`: insert formal two-method C++, update old EventHandler naming blocker as superseded by current EventMan/Event docs.
- `by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md`: insert formal covered-by comment for UID0002PT and keep no-code proof.
- `by-global/StartupLogoBinkRestartFlag.md`: insert formal global declaration C++ and update score to `88/92`.
- `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`: insert formal covered-by comment for UID0002ZH.
- `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`: insert formal first-draft C++ and document resolved source names for Application window getter, PlatformApi message slots, Bink globals, `LOGO.PAK`/`LOGO.PAD`, and teardown-object delete.
- `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md`: insert formal WndProc C++.
- `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md`: insert formal static declarations, including reserved dwords and loop padding.

Support facts already present, no edit required unless implementation agent finds stale wording while re-reading current files:

- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` already maps type `3` to `kEventLeftButtonUp` and type `8` to `kEventKeyDown`.
- `by-class/Event.md` already documents `m_type` at `+0x04` and payload slot `+0x08`.
- `by-global/WideApiDispatchTable.md` already documents `g_pfnDispatchMessage` at `0x0069be64` and `g_pfnPeekMessage` at `0x0069be8c`.
- `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` and `by-global/g_pScreenPane.md` already document `0x00557430` as the show-cursor wrapper.
- `by-file/Application.md` and `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md` already resolve the main-window handle getter.

## Score And Metadata Recommendation

| Doc | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `by-file/StartupLogoPanes.md` | `88/86` | `89/90` | Family empty-emitter route is now resolved; file split caveat remains. |
| `by-class/LogoPane.md` | `88/90` | `90/91` | Declaration and child route become source-ready; exact original names still inferred. |
| UID0003LG | `87/91` | `88/91` | Source body formalized; renderer callback name inferred. |
| UID0003LH | `86/90` | `88/91` | Source body formalized; adjusted-this route known. |
| UID0003LI | `86/90` | `88/91` | Source body formalized; event type documented. |
| UID0003LK | `87/91` | `88/91` | Source body formalized; timer behavior exact. |
| UID0003LL | `86/90` | `88/91` | Source body formalized; support helpers known. |
| UID0002PO | `86/90` | `88/91` | Retained helper bodies formalized; no-xref caveat remains. |
| UID0002PP | `85/90` | `88/91` | Callback construction/queue route formalized. |
| UID0002PR | `86/91` | unchanged | No-code policy already strong; add covered-by comment only. |
| UID0003OP | `86/91` | unchanged | Vtable generated-binary policy unchanged; add covered-by comment only. |
| UID00019D | `88/92` | `90/92`, `RECONSTRUCTABLE:FALSE`, blank emitters | Aggregate/index classification resolved. |
| UID0002PV | `87/90` | `88/91` | Formal input handlers can now use accepted event names. |
| UID0002PY | `87/92` | unchanged | No-code policy already strong; add covered-by comment only. |
| UID0002ZH | `86/91` | `88/92` | Source global declaration formalized. |
| UID0002ZM | `87/92` | unchanged | Memory child covered by by-global declaration. |
| UID0003K6 | `87/92` | `89/92` | Formal Bink loop body ready; callback object type remains inferred. |
| UID0003K7 | `86/92` | `89/93` | WndProc body exact enough and direct install route proven. |
| UID00029G | `86/92` | `88/92` | Static declarations formalized; reserved/callback fields remain caveats. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0000O4 remains the current source root `NexusTK/app/StartupLogoPanes.cpp`; no split now. | High | Current file doc, generated output, ApplicationStartup caller, file-level route. | `by-file/StartupLogoPanes.md` Status/Changes | incorporated | applied: file score is `89/90`; 2026-06-30 B008 Changes note preserves `StartupLogoPanes.cpp` source root, `CANONICAL_OWNER:FILE`, and no `LogoPane.cpp`/`LogoPlayerPane.cpp` split. |
| C02 | The 18 empty markers are stale formal C++/classification issues, not ownership route failure. | High | Generated `StartupLogoPanes.cpp`, support docs, MCP exact xrefs. | `by-file/StartupLogoPanes.md` Changes | incorporated | applied: file Changes note enumerates all 18 dispositions; final generated header `000000002376` shows populated target UIDs and no UID00019D emitter marker. |
| C03 | UID00007G should emit a `LogoPane` declaration shell with `[[CHILDREN]]`. | High | Class method/field docs, generated class empty marker. | `by-class/LogoPane.md` C++ block | incorporated | applied: `LogoPane.md` is `90/91` and formal block contains class declaration, fields, private helpers, and `[[CHILDREN]]`. |
| C04 | UID0003LG is source-authored `LogoPane::BlitLogoFrame()` using renderer callback `0x0069b3e8`. | Medium-high | MCP decompile and vtable xref; field docs. | UID0003LG body/evidence | incorporated | applied: UID0003LG is `88/91`, emits `LogoPane::BlitLogoFrame()`, and documents inferred `g_pfnDrawEPFTile`/`m_bounds` caveats. |
| C05 | UID0003LH/3LI/3LK/3LL are source-authored `LogoPane` advance/ready/completion methods, not separate owners. | High | MCP decompiles, xrefs, field offsets, support docs. | Each UID page and `LogoPane.md` | incorporated | applied: UID0003LH/3LI/3LK/3LL are all `88/91` with formal bodies and current evidence notes for adjusted-this, EventMan type `3`, timer delay, callback delete, cursor restore, and `MarkForDeletion()`. |
| C06 | UID0002PO retained helper pair should now receive formal C++ while preserving no-xref and failure-cleanup caveats. | High | Current page, constructor duplicate flow, B002 report lead, support docs. | UID0002PO body/evidence | incorporated | applied: UID0002PO is `88/91`, emits `LoadStaticLogoFromFile()`/`AttachStaticLogoSurface()`, retains no-direct-xref evidence, and explicitly preserves binary-faithful failure cleanup. |
| C07 | UID0002PP queue helper should emit callback allocation/fade queue C++. | High | MCP decompile/xrefs, current method docs, generated sibling code. | UID0002PP body/evidence | incorporated | applied: UID0002PP is `88/91`, emits `QueueAdvanceToNextScreen()`, and records callback allocation, target `0x004f5070`, zero adjustment, captured `this`, and `g_pScreenPane` queue route. |
| C08 | UID0002PR and UID0002PY should not hand-port scalar deleting destructor code; use covered-by comments. | High | Prior accepted reports, MCP xrefs/decompiles, by-structure covered-by rule. | UID0002PR/UID0002PY C++ blocks | incorporated | applied: UID0002PR formal block covers [UID:0002PM]; UID0002PY formal block covers [UID:0002PT]; both keep no hand-written scalar wrapper bodies. |
| C09 | UID0003OP vtable data is source-declared/generated-binary covered by LogoPane declaration. | High | MCP vtable ints/xrefs, by-structure rebuild handling. | UID0003OP C++/evidence | incorporated | applied: UID0003OP formal block covers [UID:00007G] and keeps vtable data generated by class declaration. |
| C10 | UID00019D is only an aggregate/index and should be non-reconstructable/non-emitting. | High | Current aggregate doc, exact child pages, by-structure container rule. | UID00019D metadata/evidence | incorporated | applied: UID00019D is `90/92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal block, with aggregate/index evidence preserved. |
| C11 | UID0002PV should emit `OnKeyEvent`/`OnMouseEvent` using EventMan type `8` and type `3`. | High | MCP decompile, EventMan/Event docs, current class declaration. | UID0002PV body/evidence and `LogoPlayerPane.md` | incorporated | applied: UID0002PV is `88/91`, emits both handlers, and `LogoPlayerPane.md` records the formal input-handler and UID0002PY covered-by support note. |
| C12 | UID0002ZH should emit `static bool g_startupLogoBinkRestartPending = true;`; UID0002ZM is covered by it. | High | MCP bytes/value/xrefs, current by-global/by-memory docs. | UID0002ZH/UID0002ZM C++ blocks | incorporated | applied: by-global UID0002ZH is `88/92` with static bool declaration; UID0002ZM formal block covers [UID:0002ZH]. |
| C13 | UID0003K6 should emit `PlayStartupLogoBinkFile()` with LOGO.PAK/PAD, Bink loop, temporary WndProc, and teardown-object delete. | High | MCP decompile, strings/xrefs, global bytes/values, support docs. | UID0003K6 body/evidence | incorporated | applied: UID0003K6 is `89/92`, emits `static void PlayStartupLogoBinkFile()`, keeps LOGO.PAK/PAD, Bink loop, WndProc install/restore, and `g_startupLogoBinkTeardownCallback` delete semantics. |
| C14 | UID0003K7 should emit exact temporary WndProc behavior. | High | MCP decompile and install/callee xrefs. | UID0003K7 body/evidence | incorporated | applied: UID0003K7 is `89/93` and emits WndProc switch for erase/close/destroy/paint/key/mouse/default forwarding. |
| C15 | UID00029G should emit source-level static declarations for the zero-initialized startup Bink state slots. | Medium-high | MCP zero bytes/values, current data page, Bink loop decompile. | UID00029G C++/evidence | incorporated | applied: UID00029G is `88/92`, emits static declarations for handle, buffer, window, loop flag/reserved padding, teardown callback, next segment, remaining size, and reserved dwords. |
| C16 | EventMan/Event, WideApiDispatchTable, g_pScreenPane, and Application getter support facts are already present. | High | Targeted support doc reads. | Relevant support docs | no edit | already-present: re-read conditional support docs during callback; EventMan/Event type `3` and `8`, `g_pfnWideOpenFile`, `g_pScreenPane`/cursor helpers, and `Application::GetMainWindowHandle()` were already documented, so no conditional support edits were needed. |
| C17 | Manual generated/tracker/coverage edits are not needed; validator/executed-report tooling should refresh generated state later. | High | Workflow and by-structure generated-file rules. | Report/checklist only | excluded | excluded-with-reason: no manual edits were made to generated files, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files; scoped validators refreshed generated/tracker/coverage artifacts as tool-owned side effects. |

## Implementation Callback Update - 2026-06-30

- Current leases were re-read before editing; visible active leases were unrelated MiniMap files. B008 leased the 20 target/support by-* paths immediately before editing. The lease report showed no active leases by validation end; an explicit `B008 unlease` command for all 20 paths returned `Rejected[No active lease]` for each, and `current_leases.md` then reported `No active leases`; a later final re-read showed only unrelated B007 ClanStatusPane/report leases, with no B008 or StartupLogoPanes-family leases active.
- Conditional support docs were re-read and left untouched because the accepted facts were already present: `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`, `by-class/Event.md`, `by-global/WideApiDispatchTable.md`, `by-global/g_pScreenPane.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, `by-file/Application.md`, and `by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md`.
- Generated freshness after validation: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` header is `validator-command-id: 000000002376`, `validator-refreshed-at: 2026-06-30T05:03:29-04:00`, source UID `0000O4`; UID markers for accepted populated/covered entries are present, while UID00019D is absent from generated output because it is now non-emitting.
- No manual generated, coverage, validator/tool state, IDA DB, executed archive, supervisor ledger, or lock-file edits were made.

## Validator Results

All validator commands were run from `E:/NTK/GhidraBridge/source-3/project-documentation` with `--mode file --apply --queue-timeout 240 --wait-generated`.

| File | command_id | command_timestamp | Exit | ok | Generated refresh | Warnings |
| --- | --- | --- | --- | --- | --- | --- |
| `by-file/StartupLogoPanes.md` | `000000002320` | `2026-06-30T04:56:00-04:00` | `0` | `1` | completed; generated refresh command `000000002320` | Global registry/autogen scan warnings only: `autogen_emitter_has_no_code`, `autogen_children_marker_missing`, `autogen_children_fallback_insert`; no target-specific validation failure. |
| `by-class/LogoPane.md` | `000000002331` | `2026-06-30T04:56:45-04:00` | `0` | `1` | completed | 9 generic unrelated Error-family autogen warnings plus `generated_metadata_refresh 0000J5`; no target-specific failure. |
| `by-class/LogoPlayerPane.md` | `000000002334` | `2026-06-30T04:57:01-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f4f70-0x004f4f94.LogoPaneBlitLogoFrame.md` | `000000002337` | `2026-06-30T04:57:21-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleAdvanceRequest.md` | `000000002340` | `2026-06-30T04:57:40-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f4fe0-0x004f502c.LogoPaneOnMouseDown.md` | `000000002342` | `2026-06-30T04:57:50-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md` | `000000002344` | `2026-06-30T04:58:01-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md` | `000000002347` | `2026-06-30T04:58:19-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md` | `000000002349` | `2026-06-30T04:58:30-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md` | `000000002351` | `2026-06-30T04:58:41-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md` | `000000002353` | `2026-06-30T04:58:52-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md` | `000000002355` | `2026-06-30T04:59:05-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md` | `000000002359` | `2026-06-30T04:59:17-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md` | `000000002361` | `2026-06-30T04:59:29-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md` | `000000002363` | `2026-06-30T04:59:41-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-global/StartupLogoBinkRestartFlag.md` | `000000002365` | `2026-06-30T04:59:53-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md` | `000000002367` | `2026-06-30T05:00:05-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md` | `000000002369` | `2026-06-30T05:00:18-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md` | `000000002371` | `2026-06-30T05:00:30-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |
| `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md` | `000000002372` | `2026-06-30T05:00:41-04:00` | `0` | `1` | completed | Same 9 generic unrelated Error-family autogen warnings; no target-specific failure. |

Final generated-header freshness: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` was observed after the validator loop at `validator-command-id: 000000002376`, `validator-refreshed-at: 2026-06-30T05:03:29-04:00`, and `validator-refresh-source: foreground-generated-refresh`. B008 validator loop ended at command `000000002372`.

## Generated / Coverage / Manual Tracker Disposition

- Manual edits: none to `auto-generated/**`, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- Validator-owned side effects: scoped `validator.py --apply --wait-generated` runs refreshed `auto-generated/NexusTK/app/StartupLogoPanes.cpp`, generated metadata, research tracker, and memory auto-coverage as tool-owned outputs. This was required by callback validation and was not a manual edit.
- Generated freshness proof: `auto-generated/NexusTK/app/StartupLogoPanes.cpp` header is fresh at final observed command `000000002376` / `2026-06-30T05:03:29-04:00` and includes the populated/covered UID markers for the accepted implementation.

## Changed Files

Manual documentation changes:

- `by-file/StartupLogoPanes.md`
- `by-class/LogoPane.md`
- `by-class/LogoPlayerPane.md`
- `by-memory/0x004f4f70-0x004f4f94.LogoPaneBlitLogoFrame.md`
- `by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleAdvanceRequest.md`
- `by-memory/0x004f4fe0-0x004f502c.LogoPaneOnMouseDown.md`
- `by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md`
- `by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md`
- `by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md`
- `by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md`
- `by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md`
- `by-memory/0x0061cf78-0x0061d000.LogoPaneVtableData.md`
- `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`
- `by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md`
- `by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md`
- `by-global/StartupLogoBinkRestartFlag.md`
- `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`
- `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`
- `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md`
- `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md`
- `tools/leaser/Agents/Agent-B008/research/0000O4-StartupLogoPanes-empty-emitter-family-source-quality.md`

Lease status:

- Lease acquire command for the 20 by-* files returned `Success` for every path.
- Final explicit unlease command returned `Rejected[No active lease]` for every path because the short leases had already expired during validation.
- Immediate post-unlease `tools/leaser/Agents/current_leases.md` read reported `No active leases`; final sanity read later showed only unrelated B007 ClanStatusPane/report leases, with no B008 or StartupLogoPanes-family leases active.

## Implementation Tracking Checklist

Report-only evidence completed:

- [x] Read Agent-B008 goal and notes, project workflow skill, required workflow references, by-structure rules, target, generated output, relevant support docs, Event/WideApi/Application support docs, and existing report leads.
- [x] Verified IDA MCP availability and gathered current exact-address evidence from active session `supervisor_resume_20260629`.
- [x] Produced report-only Claim And Incorporation Ledger, later updated to callback-applied states below.
- [x] Did not manually edit generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.

Implementation callback completed:

- [x] Re-read current leases and re-read each support doc immediately before editing. Proof: current lease report had no StartupLogoPanes conflict; conditional Event/WideApi/ScreenPane/Application support facts were already present and left untouched.
- [x] Edited `by-file/StartupLogoPanes.md`: score `89/90`; added B008 empty-emitter family note with 18-marker disposition, MCP provenance, unchanged source-root/split caveat, and rejected alternatives.
- [x] Edited `by-class/LogoPane.md`: score `90/91`; inserted exact declaration/`[[CHILDREN]]` formal block; updated stale blank-C++ statements for UID0003LG/3LH/3LI/3LK/3LL/2PO/2PP.
- [x] Edited `by-class/LogoPlayerPane.md`: added support note for UID0002PV formal C++ and UID0002PY covered-by comment while preserving retained/alternate constructor caveat.
- [x] Inserted exact formal C++ into UID0003LG, UID0003LH, UID0003LI, UID0003LK, UID0003LL, UID0002PO, UID0002PP, UID0002PV, UID0002ZH, UID0003K6, UID0003K7, and UID00029G. Proof: final generated header `000000002376` includes their generated UID markers and formal output where they are emitting entries.
- [x] Inserted exact formal covered-by comments into UID0002PR, UID0003OP, UID0002PY, and UID0002ZM. Proof: generated output includes covered-by comments for emitting wrapper/data entries UID0002PR/0003OP/0002PY; UID0002ZM carries its covered-by comment on the by-memory doc and is covered by by-global UID0002ZH rather than appearing as a separate generated emitter.
- [x] Reclassified UID00019D to `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, score `90/92`, with blank formal block and aggregate/index evidence preserved.
- [x] Confirmed support facts already present in EventMan/Event, WideApiDispatchTable, g_pScreenPane/ScreenCursorHelpers, Application/GetMainWindowHandle docs; no conditional support edits were needed.
- [x] Preserved rejected alternatives and historical/stale assumptions: no file split now, no VideoPlayerPane/Pane/EventHandler ownership move, no hand-written vtable/scalar-wrapper bodies, no generated helper labels, no cleanup normalization in UID0002PO.
- [x] Ran scoped validators for every changed `by-*` file from `E:/NTK/GhidraBridge/source-3/project-documentation`, with `--wait-generated`; all 20 commands exited `0` with `ok: 1`.
- [x] Recorded validator command, command_id, command_timestamp, exit code, ok count, warnings, side effects, and generated-header freshness state in this report.
- [x] Updated every Claim And Incorporation Ledger verification state from `proposed` to `applied`, `already-present`, or `excluded-with-reason` with proof.
- [x] Did not manually edit generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files; validator-owned generated refresh is documented separately.
- [x] Ready to return implementation checkpoint after this report update; no unchecked callback blockers remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000O4-StartupLogoPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000O4-StartupLogoPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T05:11:28","uid":"0000O4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
