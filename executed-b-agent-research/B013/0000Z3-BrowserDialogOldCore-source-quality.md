** TARGET-REPORT-UID:0000Z3 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000Z3 BrowserDialogOldCore Source-Quality / Inference Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000Z3] `by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md` as a coherent `BrowserDialogOld` core aggregate, but update its direct owner/emitter from the Browser file root to [UID:000018] `BrowserDialogOld` after applying the evidence and score refresh below.
- Final disposition: the four raw helper starts at `0x004694a0`, `0x004694c0`, `0x004694e0`, and `0x00469510` are real source-shaped BrowserDialogOld private/helper methods, not padding, not BrowserControlPaneOld methods, and not BrowserWindow-owned helpers. They should stay in this aggregate unless a later implementation pass elects to create method-level child pages for final C++ emission.
- Required action: update target evidence/naming, set recommended score to `86/91`, route `CANONICAL_OWNER` and `EMITTER_UIDS` through [UID:000018] `BrowserDialogOld`, and apply the support rename/reowner for [UID:00033K] `0x00470dd0-0x00470f10` from stale `BrowserWindowNavigate` to `Browser::Navigate`.
- First-draft C++ disposition: do **not** populate the target `RECONSTRUCTION_CPP CODE` block yet. The current minimum score/emitter gate can be made to pass, but final code would depend on a support reowner for `0x00470dd0`, exact old-browser header layout, and final source spelling for no-xref raw helpers.
- Confidence: high for raw helper behavior and BrowserDialogOld ownership; medium-high for original source spelling.

## Supporting Research

## Target

- Target UID: `0000Z3`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00469290-0x0046963c.BrowserDialogOldCore.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\0000Z3-BrowserDialogOldCore-source-quality.md`
- Source queue/report row: reconstructable low-score Browser by-memory row with unresolved raw-helper/source-split/source-quality and first-draft C++ questions.
- Current supervisor classification: B-preferred heuristic/source-quality task; do not edit `by-memory/-coverage-report.md`.
- Current target scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, `RECONSTRUCTABLE:TRUE`.
- Recommended target scores and parent state after documentation update: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000018`, `EMITTER_UIDS:000018`, `RECONSTRUCTABLE:TRUE`.

## Executive Recommendation

`0000Z3` should be treated as `BrowserDialogOld` class behavior under the Browser source module. The direct semantic owner should be [UID:000018] `BrowserDialogOld`, not the broader [UID:0000HV] `Browser` file, because every in-range source-bearing body either is a `BrowserDialogOld` constructor/destructor/vtable method or is a private helper that starts from a `BrowserDialogOld *this`. The Browser file remains the final source root through the class emitter chain.

The strongest helper-name recommendations are:

| Range | Recommended descriptive source name | Confidence |
| --- | --- | --- |
| `0x004694a0-0x004694be` | `BrowserDialogOld::NavigateLegacyBrowserControl` / `NavigateBrowserControl` | high for role, medium for exact name |
| `0x004694c0-0x004694d8` | `BrowserDialogOld::PostBrowserThreadCloseMessage` | high |
| `0x004694e0-0x00469501` | `BrowserDialogOld::HideLegacyBrowserWindow` | high |
| `0x00469510-0x00469527` | `BrowserDialogOld::ScheduleDeferredBrowserRedraw` | high |

Support fix: [UID:00033K] `0x00470dd0-0x00470f10.BrowserWindowNavigate.md` is misnamed/misowned. Local PE disassembly plus existing docs show all checked callers pass a legacy [UID:000013] `Browser` object, and the body reads Browser fields `+0x18` and `+0x228`. Recommend rename to `0x00470dd0-0x00470f10.BrowserNavigate.md`, canonical owner/emitter [UID:000013] `Browser`, and update dependent rows in `BrowserWindow`, `Browser`, `BrowserThreadInitializeBrowserHost`, `BrowserInvokeAndSwitchTable`, `BrowserOleLegacyAndHelpers`, and this target.

## Supervisor Active Recheck

- The supervisor assignment specifically asked to reanalyze raw helper bodies, source split, field/global/helper names, vtable/source placement, support changes, scores, and C++ readiness. This report covers each item.
- The assigned item does not require immediate split repair because all in-range raw helpers are same-class `BrowserDialogOld` source behavior. It is not a mixed aggregate like [UID:0000ZF] `BrowserOleLegacyAndHelpers`.
- The target can remain an aggregate for documentation, but method-level child pages are recommended before final C++ is added. That is a final-source emission hygiene recommendation, not an ownership blocker.
- No by-* target page or coverage report was edited by B013 in this pass.

## Inference Research Guidance Check

`by-structure.md` requires direct semantic ownership rather than nearest file ownership. That rule favors [UID:000018] `BrowserDialogOld` for `0000Z3`; [UID:0000HV] `Browser` is the source root, not the narrow owner. It also requires C++ only when the emitter route, names, dependencies, and source shape are strong enough. The current raw-helper behavior is now strong, but support naming and class layout are not final enough for code entry.

`inference_research.md` affected the report in three ways:

- Existing documentation was treated as a lead, not authority. The current `BrowserWindowNavigate` label for `0x00470dd0` is contradicted by caller/object evidence.
- Consumer xrefs were weighed carefully. `BrowserDialogOld` helpers consume `BrowserControlPaneOld`, `Browser`, `BrowserThread`, `TimerHandler`, and `DialogPane`; those dependencies do not transfer ownership away from `BrowserDialogOld`.
- Negative evidence was used for reachability: local PE scan found no absolute dword or direct rel32 call/jump references to any of the four raw helper entrypoints, agreeing with existing IDA-backed no-xref notes.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Rejected alternatives | Final direction / impact |
| --- | --- | --- | --- |
| Raw helper `0x004694a0` role | Local PE bytes disassemble to `mov ecx,[ecx+0x1fc]`, push `0`, virtual call slot `+0x10`, dereference returned control holder, load child/control object `+0x110`, then tail-jump to `0x00470dd0` while preserving the incoming stack argument. Existing `DialogPaneLayout` identifies `+0x1fc` as inherited control manager; `BrowserControlPaneOldConstructor` identifies outer `+0x110` as the Browser object pointer. | Not padding; not a BrowserControlPaneOld method because entry `ecx` is the dialog; not BrowserWindow-owned because the tail target is passed a Browser object; not compiler thunk because it performs real object lookup and argument-preserving tail dispatch. | Name as `BrowserDialogOld::NavigateLegacyBrowserControl(const wchar_t *url)` or similar. Owner `BrowserDialogOld`. The tail callee should be reowned/renamed as `Browser::Navigate`. |
| Raw helper `0x004694c0` role | Disassembly: load `[0x0067ab88]`, push `0,0,0x500`, push `[eax+0x60]`, call IAT `0x0060d3f0`. Local import parse maps `0x0060d3f0` to `USER32!PostThreadMessageA`. `g_pBrowserThread` docs identify `0x0067ab88` as `BrowserThread *`; `0x500` is 1280 (Verified with `tools/int_convert.py`) and documented as the browser thread close message. | Not BrowserThread-owned: it only posts to the thread; not generic notification helper; not a vtable method because no vtable/data ref was found. | Name as `BrowserDialogOld::PostBrowserThreadCloseMessage`. Class-private/file-local spelling remains inferred, but source role is resolved. |
| Raw helper `0x004694e0` role | Disassembly: uses `this+0x1fc` control manager, calls lookup slot `+0x10` with `0`, follows returned control to `+0x110`, pushes `[browser+0x14]`, calls IAT `0x0060d424`; local import parse maps it to `USER32!ShowWindow`. The helper pushes `0` before the HWND, so it calls `ShowWindow(hwnd, SW_HIDE)`. | Not a BrowserWindow method because the entry object is `BrowserDialogOld`; not a generic DialogPane helper because it knows the old browser child layout; not close-message logic because it hides a concrete HWND. | Name as `BrowserDialogOld::HideLegacyBrowserWindow` or `HideBrowserControlWindow`. Owner `BrowserDialogOld`. |
| Raw helper `0x00469510` role | Disassembly pushes event id `0`, delay `0x2bc`, payload args `0,0`, adjusts `ecx += 0xa4`, calls `0x005975e0`. `0x2bc` is 700 decimal (Verified with `tools/int_convert.py`). `TimerHandlerScheduleRemoveWrappers` identifies `0x005975e0` as generic `TimerHandler::ScheduleTimer`. `BrowserDialogOld` constructor/vtable docs show tertiary view at `+0xa4`, and `OnNavigateAction` at `0x00469620` posts browser private redraw message `0x501`. | Not TimerMgr-owned: the schedule wrapper is a generic callee, while this helper chooses BrowserDialogOld's timer subobject and delay; not arbitrary delay/padding; not final C++ ready because the timer-handler subobject declaration is not final. | Name as `BrowserDialogOld::ScheduleDeferredBrowserRedraw`. It schedules timer event `0` after 700 ms to trigger the `+0xa4` callback path that posts `0x501`. |
| `this+0x1fc` field | `DialogPaneLayout` identifies `+0x1fc` / 508 bytes (Verified with `tools/int_convert.py`) as inherited control manager/list pointer. `DialogControlPaneHelpers` documents control-manager lookup/add/selection helpers. | Do not introduce a BrowserDialogOld-local field at `+0x1fc`; do not assign the helper to DialogPane just because it uses inherited state. | Use inherited `DialogPane::m_controlManager` or similar. The source-level lookup is probably `GetControl(0)` / `FindControl(0)` through manager slot `+0x10`; exact manager method name remains provisional. |
| `dword_67AB88` and `+0x60` | `BrowserThreadHostGlobals` and `g_pBrowserThread` identify `0x0067ab88` as `BrowserThread *g_pBrowserThread`; the target methods and helpers use `[g_pBrowserThread + 0x60]` as the thread id passed to `PostThreadMessageA`. `0x60` is 96 decimal (Verified with `tools/int_convert.py`). | Not a BrowserWindow global; not a generic thread manager slot; not `g_activeBrowserPane`. | Rename field direction to `BrowserThread::m_threadId` / `m_dwThreadId` candidate. It is a BrowserThread field consumed by BrowserDialogOld. |
| Browser private messages `0x500`/`0x501` | `BrowserMessageId` documents `0x500` as close and `0x501` as redraw; local disassembly confirms `0x004694c0`, `OnKeyEvent`, and Browser::Invoke post `0x500`, while `OnNavigateAction` posts `0x501`. `0x500` is 1280 and `0x501` is 1281 (Verified with `tools/int_convert.py`). | Do not use vague "post close/browser message" for both; the messages have distinct thread-loop semantics. | Use `kBrowserThreadClose` and `kBrowserThreadRedraw` provisional names. |
| `0x00470dd0` support owner | Local callsite disassembly: `0x00470d89 mov ecx,[esi+0x68]` then pushes `[ecx+0x228]` and calls `0x00470dd0`; `0x0046f887` adjusts a Browser interface pointer with `lea ecx,[ecx-8]`; `0x004694a0` passes BrowserControlPaneOld `+0x110`. Body head reads `[esi+0x18]`. Browser docs identify Browser fields `+0x18` and `+0x228`; BrowserWindow has a separate navigation helper at `0x00469ca0`. | Reject current `BrowserWindowNavigate` ownership and BrowserWindow method inventory entry. Reject free helper ownership because all callers pass a Browser object and body uses Browser fields. | Rename/reowner [UID:00033K] to `Browser::Navigate` / `BrowserNavigate`, owner [UID:000013] `Browser`, emitter [UID:000013]. This is the main support fix. |
| Vtable/source placement | Existing IDA-backed docs show constructor/destructor store primary/secondary/tertiary BrowserDialogOld vtables, event handlers have vtable data refs at `0x006131b8`, `0x006131bc`, and `0x006131e8`; raw helpers have no vtable refs. | Do not classify raw helpers as vtable slots; do not move them to BrowserControlPaneOld just because they call through the child. | Formal virtual methods remain constructor/destructor/key/mouse/timer-redraw callback. Raw helpers are private class/file helpers inside the BrowserDialogOld source island. |
| Generated-output pollution | `auto-generated/NexusTK/browser/Browser.cpp` currently has an empty marker for `0000Z3`. Existing generated Browser output has many empty markers and only unrelated accepted Browser code. | Do not write decompiler-shaped aggregate C++ just to remove the missing-code marker; do not emit code that still says `BrowserWindow::Navigate` for the support callee. | Keep C++ blank pending support reowner and method-level source pass. |

Remaining blocker: the final C++ spelling of the no-xref helpers cannot be proven from binary-only evidence. That blocker should cap confidence below `95`, but it no longer justifies generic helper labels or file-level ownership.

## Evidence Standards Used

- Existing IDA-backed project docs: `BrowserDialogOld`, `BrowserControlPaneOld`, `Browser`, `BrowserThread`, `BrowserMessageId`, `DialogPaneLayout`, `TimerHandlerScheduleRemoveWrappers`, `BrowserThreadHostGlobals`, `BrowserOleLegacyAndHelpers`, and `BrowserVtablesAndStrings`.
- Local PE byte/disassembly evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`, image base `0x00400000`.
- Capstone disassembly of the target raw helper ranges and selected `0x00470dd0` caller/body ranges.
- Local PE import-table parse for IAT names `PostThreadMessageA` and `ShowWindow`.
- Local PE-wide scan for absolute dword references and direct rel32 `call`/`jmp` references to the four raw helper entrypoints.
- `tools/int_convert.py` for numeric conversions cited in this report.

Live IDA MCP caveat: `http://127.0.0.1:13337/mcp` was unreachable in this session on repeated attempts (`Unable to connect to the remote server`). Existing IDA-backed documentation and local PE inspection were used instead; this is why the report labels fresh facts as local PE evidence rather than fresh MCP facts.

## IDA MCP / Local PE Facts

### Local PE Facts

- PE image base is `0x00400000`; `.text` maps target addresses normally.
- Raw helper bytes:
  - `0x004694a0-0x004694be`: function-shaped body ending in `jmp 0x00470dd0`.
  - `0x004694c0-0x004694d8`: `PostThreadMessageA([g_pBrowserThread+0x60], 0x500, 0, 0)`.
  - `0x004694e0-0x00469501`: `ShowWindow([browser+0x14], 0)` after child lookup.
  - `0x00469510-0x00469527`: `TimerHandler::ScheduleTimer(this+0xa4, 0, 0x2bc, 0, 0)`.
- Padding after each raw helper is all `0xcc`: `0x004694be-0x004694c0`, `0x004694d8-0x004694e0`, `0x00469501-0x00469510`, and `0x00469527-0x00469530`.
- Entry reference scan found no absolute dword hits and no direct rel32 `call`/`jmp` hits for `0x004694a0`, `0x004694c0`, `0x004694e0`, or `0x00469510`.
- Import table confirms:
  - `0x0060d3f0` -> `USER32.dll!PostThreadMessageA`
  - `0x0060d424` -> `USER32.dll!ShowWindow`
- `0x00470dd0` body head reads `[this+0x18]` and receives URL-like argument values from callers. Checked callers pass Browser objects, not BrowserWindow:
  - `0x00470d89`: `ecx = [BrowserThread + 0x68]`, then pushes `[ecx+0x228]`.
  - `0x0046f887`: adjusts Browser `Invoke` interface pointer with `lea ecx,[ecx-8]`.
  - `0x004694a0`: reaches BrowserControlPaneOld child `+0x110`.

### Existing IDA-Backed Documentation Facts

- `BrowserDialogOld` constructor/destructor and three vtable-backed methods have IDA-confirmed bounds at `0x00469290-0x00469426`, `0x00469430-0x0046949c`, `0x00469530-0x004695a9`, `0x004695b0-0x0046961c`, and `0x00469620-0x0046963c`.
- Constructor calls `BrowserControlPaneOld::BrowserControlPaneOld` at `0x0046936e` and dispatches through child/control state at `[this+0x1fc]`.
- `BrowserControlPaneOldConstructor` records Browser object pointer storage at outer `+0x110` and Browser URL pointer at `+0x228`.
- `BrowserThreadHostGlobals` records xrefs to `0x0067ab88` from `0x004694c0`, `0x0046955c`, `0x00469582`, `0x004695c0`, and `0x00469620`.
- `BrowserMessageId` documents `0x500` / `0x501` as private close/redraw thread messages.
- `TimerHandlerScheduleRemoveWrappers` documents `0x005975e0` as generic timer schedule wrapper with broad caller fan-in.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00469290-0x00469426` | part of [UID:0000Z3] | `BrowserDialogOld` constructor | true | [UID:000018] | included in `86/91` recommendation | keep in aggregate |
| `0x00469430-0x0046949c` | part of [UID:0000Z3] | `BrowserDialogOld` destructor | true | [UID:000018] | included | keep in aggregate |
| `0x004694a0-0x004694be` | part of [UID:0000Z3] | private navigate-through-child helper | true | [UID:000018] | included | keep in aggregate; optional future child |
| `0x004694c0-0x004694d8` | part of [UID:0000Z3] | private close-thread-message helper | true | [UID:000018] | included | keep in aggregate; optional future child |
| `0x004694e0-0x00469501` | part of [UID:0000Z3] | private hide-browser-window helper | true | [UID:000018] | included | keep in aggregate; optional future child |
| `0x00469510-0x00469527` | part of [UID:0000Z3] | private deferred-redraw timer scheduler | true | [UID:000018] | included | keep in aggregate; optional future child |
| `0x00469530-0x004695a9` | part of [UID:0000Z3] | key/Escape close handler | true | [UID:000018] | included | keep in aggregate |
| `0x004695b0-0x0046961c` | part of [UID:0000Z3] | mouse/bounds/focus handler | true | [UID:000018] | included | keep in aggregate |
| `0x00469620-0x0046963c` | part of [UID:0000Z3] | timer/action callback posting redraw | true | [UID:000018] | included | keep in aggregate |
| `0x00470dd0-0x00470f10` | [UID:00033K] currently `BrowserWindowNavigate` | Browser COM object navigation method | true | recommend [UID:000013] | recommend support refresh | rename/reowner support item |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004694b9` | tail jump to `0x00470dd0` | Dialog helper forwards URL/navigation request to Browser object navigation. |
| `0x004694c0` | xref to `0x0067ab88` | `g_pBrowserThread` close-message sender. |
| `0x0046955c`, `0x00469582` | xrefs to `0x0067ab88` inside `OnKeyEvent` | Escape key paths post close message. |
| `0x004695c0` | xref to `0x0067ab88` inside `OnMouseEvent` | Mouse handler checks browser-thread/window state. |
| `0x00469620` | xref to `0x0067ab88` | Redraw timer/action callback posts `0x501`. |
| `0x00470d92` | call to `0x00470dd0`, `ecx=[BrowserThread+0x68]` | BrowserThread passes Browser object to navigate helper. |
| `0x0046f892` | call to `0x00470dd0`, adjusted Browser interface pointer | Browser::Invoke passes Browser object to navigate helper. |
| raw helper entrypoints | no local PE absolute dword or direct rel32 hits | No ordinary direct reachability found for raw starts; matches existing IDA no-xref notes. |

## Documentation Evidence And Current Status

- Supporting docs that validate the `BrowserDialogOld` route:
  - [UID:000018] `BrowserDialogOld.md` is `85/87`, documents constructor/destructor/event ranges, child `BrowserControlPaneOld` construction, vtable refs, and singleton lifecycle.
  - [UID:000016] `BrowserControlPaneOld.md` is `85/87`, documents the old control pane, embedded MSGHandler, Browser object at outer `+0x110`, and BrowserThread construction.
  - [UID:0002P3] `BrowserControlPaneOldConstructor.md` is `85/89`, documents Browser object allocation, URL field `+0x228`, and BrowserThread handoff.
  - [UID:0000QE] `g_pBrowserThread.md` and [UID:0002AD] `BrowserThreadHostGlobals.md` document `0x0067ab88` as `g_pBrowserThread`.
  - [UID:0001SL] `BrowserMessageId.md` documents `0x500`/`0x501` close/redraw.
  - [UID:0001K8] `TimerHandlerScheduleRemoveWrappers.md` documents `0x005975e0`.
- Stale/incomplete documentation:
  - [UID:00033K] `0x00470dd0-0x00470f10.BrowserWindowNavigate.md` should be renamed/reowned to Browser.
  - [UID:00001B] `BrowserWindow.md` currently lists `0x00470dd0` as a BrowserWindow method even though BrowserWindow has its own navigation helper at `0x00469ca0`.
  - [UID:0000ZF] `BrowserOleLegacyAndHelpers.md` and `by-memory/-coverage-report.md` repeat the stale `BrowserWindowNavigate` row.
  - [UID:0000Z3] currently uses file-level owner/emitter `0000HV`, but direct semantic ownership should be `000018` once the evidence refresh raises the target above the strict child-side gate.

## Ranked Ownership Analysis

### 1. BrowserDialogOld [UID:000018]

- Evidence for: all target functions are in the contiguous BrowserDialogOld core island; constructor/destructor and vtable slots are BrowserDialogOld; raw helpers enter with `BrowserDialogOld *this`, use inherited DialogPane control manager, and coordinate BrowserDialogOld child/control state.
- Evidence against: helpers call into BrowserControlPaneOld/Browsers/BrowserThread/TimerHandler, but these are dependencies, not direct owners.
- Decision: accepted. Recommended `CANONICAL_OWNER:000018`, `EMITTER_UIDS:000018`.

### 2. Browser file [UID:0000HV]

- Evidence for: the Browser file is the correct source root for the browser subsystem and currently emits the target.
- Evidence against: by-structure direct-owner rules prefer class owner for class methods. Using the file as direct owner bypasses [UID:000018] even though it clears `85/85`.
- Decision: rejected as direct owner; keep as final source root through `BrowserDialogOld`.

### 3. BrowserControlPaneOld [UID:000016]

- Evidence for: raw helpers dereference the legacy browser child/control and use the child Browser pointer at `+0x110`.
- Evidence against: entry `this` is the dialog, not the control pane; helpers perform dialog control-manager lookup before reaching the child; no direct code/vtable route into `BrowserControlPaneOld` for these helper starts.
- Decision: rejected as direct owner. It remains an owned dependency.

### 4. BrowserWindow [UID:00001B]

- Evidence for: existing [UID:00033K] page says `0x00470dd0` is `BrowserWindow::Navigate`.
- Evidence against: local PE caller/body evidence shows `0x00470dd0` is reached with Browser objects and uses Browser fields; BrowserWindow already owns a separate navigation helper at `0x00469ca0`.
- Decision: rejected for `0x004694a0` tail target and support item `00033K`; recommend support reowner to [UID:000013] `Browser`.

### Proposed new file/grouping

- Proposed owner/name/path: no new source file is needed. Keep the browser source root [UID:0000HV] `Browser`, with direct class ownership for `BrowserDialogOld`, `BrowserControlPaneOld`, `Browser`, and `BrowserThread`.
- Likely full contents: existing Browser file page already covers the old/new browser classes, BrowserThread, BrowserControlPaneOld, BrowserDialogOld, Browser COM helpers, browser globals/enums, and browser vtable/static data.
- Candidate related items that belong: `0000Z3` under `BrowserDialogOld`; support item `00033K` under `Browser`; `g_pBrowserThread` and `BrowserMessageId` remain Browser file/type/global support.
- Candidate related items rejected: no standalone `BrowserDialogOldHelpers.cpp`; no BrowserWindow ownership for `0x00470dd0`.
- Source-file inference: broad Browser module, possibly split internally into `Browser.cpp`/`BrowserWindow.cpp`/`BrowserThread.cpp`, but current evidence does not justify a new separate old-dialog file.

## Negative Evidence Summary

- No local PE direct references were found to the four raw helper starts. This keeps exact source reachability unresolved, but it does not convert real function-shaped bodies into padding or compiler thunks.
- The raw helpers are not vtable-backed; vtable data supports only the constructor/destructor and key/mouse/timer-action methods. Therefore name them as private helpers, not virtual overrides.
- `this+0x1fc` is inherited `DialogPane` state; it does not prove DialogPane ownership.
- `dword_67AB88` is BrowserThread global state; it does not prove BrowserThread ownership of the posting helper.
- The current `BrowserWindowNavigate` label is contradicted by local caller/body evidence; keeping it would pollute final source names and C++.

## First-Draft C++ / Exact No-Code Proof

Do **not** populate the target `RECONSTRUCTION_CPP CODE` block yet.

Reasoning:

- The recommended metadata after this pass would meet the active minimum code-entry gate: `RECONSTRUCTABLE:TRUE`, emitter route through [UID:000018], and `(86 + 91) / 2 = 88.5 > 85`.
- The gate is only minimum eligibility. This target is still an aggregate containing constructor/destructor, formal vtable methods, and four no-direct-xref raw helpers. Writing a single aggregate block would require final method names, class declarations, inherited `DialogPane` fields, `TimerHandler` subobject spelling at `+0xa4`, and Browser/BrowserControlPaneOld field names.
- A required support correction is still pending: `0x00470dd0` must be renamed/reowned from BrowserWindow to Browser. Any C++ emitted before that correction would likely call the wrong class method.
- The raw helper starts have no direct xrefs, so their source-level names are descriptive/inferred. That is sufficient for score/ownership but not yet final-source quality.
- Recommended implementation path: first apply support rename/reowner for [UID:00033K], update `0000Z3` evidence/metadata, and then create method-level child pages or a carefully reviewed class-method C++ pass. Until then, preserve the blank reconstruction block.

## Exact Recommended Changes

### Target Metadata

After updating the target page with this report's evidence, replace the target metadata with:

```text
*** UID:0000Z3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000018 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000018 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep `RECONSTRUCTION_CPP CODE` blank for now.

### Target Covered Range Wording

Recommended replacements for the four raw helper rows:

```markdown
| `0x004694a0-0x004694be` | raw private helper | `BrowserDialogOld::NavigateLegacyBrowserControl` candidate | Local PE disassembly shows a function-shaped helper that uses inherited `DialogPane::m_controlManager` at `this+0x1fc`, asks the manager for control `0` through virtual slot `+0x10`, follows the returned holder/control to the old browser child and its Browser object at `+0x110`, then tail-jumps to `0x00470dd0` while preserving the incoming URL argument. Support docs should rename/reowner `0x00470dd0` from `BrowserWindowNavigate` to `Browser::Navigate`. No local PE direct refs to this helper start were found. |
| `0x004694c0-0x004694d8` | raw private helper | `BrowserDialogOld::PostBrowserThreadCloseMessage` candidate | Posts private browser thread message `0x500` / 1280 decimal (Verified with `tools/int_convert.py`) through `PostThreadMessageA(g_pBrowserThread->m_threadId, 0x500, 0, 0)`, using `g_pBrowserThread` at `0x0067ab88` and thread-id field candidate `+0x60`. No local PE direct refs to this helper start were found. |
| `0x004694e0-0x00469501` | raw private helper | `BrowserDialogOld::HideLegacyBrowserWindow` candidate | Uses inherited control manager `this+0x1fc`, control lookup slot `+0x10`, old browser child Browser pointer `+0x110`, and Browser HWND field `+0x14`, then calls `ShowWindow(hwnd, 0)` / `SW_HIDE`. No local PE direct refs to this helper start were found. |
| `0x00469510-0x00469527` | raw private helper | `BrowserDialogOld::ScheduleDeferredBrowserRedraw` candidate | Schedules BrowserDialogOld's timer-handler/tertiary subobject at `this+0xa4` through `TimerHandler::ScheduleTimer` (`0x005975e0`) with event id `0`, delay `0x2bc` / 700 ms (Verified with `tools/int_convert.py`), and zero payload args. The paired callback at `0x00469620` posts private browser thread redraw message `0x501` / 1281 decimal (Verified with `tools/int_convert.py`). No local PE direct refs to this helper start were found. |
```

### Support Rename/Reowner For UID 00033K

Recommended path/metadata:

```text
Rename:
by-memory/0x00470dd0-0x00470f10.BrowserWindowNavigate.md
to:
by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md

Metadata:
CANONICAL_OWNER:000013
EMITTER_UIDS:000013
Suggested score after update: 86/90
```

Required support snippets:

- [UID:000013] `Browser.md`: add `0x00470dd0-0x00470f10 Browser::Navigate` to active methods and describe callers from BrowserDialogOld helper, Browser::Invoke, and BrowserThread host initialization.
- [UID:00001B] `BrowserWindow.md`: remove `0x00470dd0` from BrowserWindow method inventory; keep `0x00469ca0` as BrowserWindow's own navigation helper.
- [UID:00032W] `BrowserThreadInitializeBrowserHost.md`: change "calls BrowserWindow::Navigate" to "calls Browser::Navigate on the Browser pointer at `BrowserThread +0x68`".
- [UID:000331] `BrowserInvokeAndSwitchTable.md`: change the case `250` helper reference from BrowserWindow to Browser.
- [UID:0000ZF] `BrowserOleLegacyAndHelpers.md`: update child inventory row for `0x00470dd0` to owner [UID:000013] `Browser`.

### `by-memory/-coverage-report.md` Rows

B013 did not edit `by-memory/-coverage-report.md`. If the supervisor applies this report, replace the current `0000Z3` row with:

```markdown
    - [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) 0x00469290-0x0046963c | class aggregate | BrowserDialogOldCore : reconstructable : 86% : very strong : BrowserDialogOld constructor/destructor/key/mouse/redraw-callback methods plus four raw private helpers rechecked with local PE disassembly, import names, no-entrypoint-reference scan, inherited `DialogPane::m_controlManager` at `+0x1fc`, `g_pBrowserThread` thread-message field at `+0x60`, timer scheduling through `this+0xa4`, and support correction that `0x00470dd0` is Browser-owned navigation rather than BrowserWindow-owned. Direct semantic owner should be [UID:000018][BrowserDialogOld](by-class/BrowserDialogOld.md); final C++ remains blank pending support rename/reowner and method-level source spelling.
```

If the support rename/reowner for [UID:00033K] is applied, replace its current coverage row with:

```markdown
      - [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) 0x00470dd0-0x00470f10 | class method | BrowserNavigate : reconstructable : 86% : very strong : Browser COM object navigation method assigned to [UID:000013][Browser](by-class/Browser.md); local PE disassembly and existing IDA-backed docs show all checked callers pass a Browser object (`BrowserThread +0x68`, adjusted `Browser::Invoke` interface pointer, and `BrowserDialogOld` raw helper through `BrowserControlPaneOld +0x110`), the body uses Browser fields `+0x18` and URL pointer `+0x228`, and it performs BSTR/VARIANT/SafeArray setup before the WebBrowser navigate vtable call.
```

## Follow-Up Actions

- Supervisor actions:
  - Apply or assign the `0000Z3` target metadata/evidence update.
  - Apply or assign the [UID:00033K] BrowserNavigate rename/reowner support fix before any final C++ for `0000Z3`.
  - Apply the exact `by-memory/-coverage-report.md` replacement rows above if target/support docs change.
- A-agent actions:
  - Update target doc sections for raw helper names, `this+0x1fc`, `g_pBrowserThread +0x60`, timer delay semantics, and C++ no-code proof.
  - Update Browser/BrowserWindow/BrowserThread support pages for the `0x00470dd0` owner correction.
- B013 future research actions:
  - If asked to continue this family, audit `BrowserDialogOld` final header/source shape and decide whether the aggregate should be split into method-level child pages before final C++.

## Confidence

- Recommendation confidence: `90/100`.
- Raw helper behavior confidence: `92/100`; local disassembly and imports directly prove behavior.
- Ownership confidence for `0000Z3 -> BrowserDialogOld`: `90/100`; remaining uncertainty is only final source spelling.
- Support reowner confidence for `00033K -> Browser`: `88/100`; strong local caller/body evidence, but should still be confirmed with live IDA MCP when the server is available.
- Score confidence: `86/91` is justified after updating the target text, but not before applying this evidence to the page.
- Remaining uncertainty: no direct callers/xrefs to the four raw helper starts; exact original helper names; exact `TimerHandler`/tertiary-interface declaration at `BrowserDialogOld +0xa4`.

## Validator Results

- Validator not run. This pass created only a B013 research report under the agent folder and did not edit scoped by-* documentation.
- IDA MCP was unavailable in this session; local PE inspection substituted for fresh byte/xref checks and is recorded above.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B013/research/0000Z3-BrowserDialogOldCore-source-quality.md`
- Modified: none outside the created research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000Z3-BrowserDialogOldCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0000Z3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
