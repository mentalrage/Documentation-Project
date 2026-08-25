** TARGET-REPORT-UID:0002H3 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002H3 ApplicationRequestExit Empty-Emitter Source-Quality Report

## Lifecycle Status / Current Disposition

- Initial report-only research completed for [UID:0002H3][by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md](../../../by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md), recommending conversion from an empty emitter to a source-ready Application method with formal first-draft C++.
- Supervisor accepted the report and issued implementation callback `B007-implement-0002H3-ApplicationRequestExit-20260629`.
- Implementation callback completed: target/support by-* docs were edited, UID0002H3 was raised to `COMPLETION:90`, `CONFIDENCE:92`, canonical owner/emitter remained [UID:00000D][Application](../../../by-class/Application.md), formal `Application::RequestExit()` C++ was inserted, validators ran, generated `Application.cpp` was checked read-only, and B007 leases were released.
- Final disposition: no split, rename, owner change, emitter change, ScreenPane/FunctionObjects/MiniMap ownership transfer, helper-body-in-target paste, or manual generated/coverage/tool-state edit was performed.
- Confidence: high for behavior, range, owner, emitter route, event/flag offsets, callback construction, and MiniMap deletion source shape; moderate only for exact original spelling of inferred method/helper names.

## Target

- Target UID: `0002H3`
- Target path: `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
- Assignment ID: `B007-empty-emitter-report-0002H3-ApplicationRequestExit-20260629`
- Historical source queue reason: before implementation, generated `auto-generated/NexusTK/app/Application.cpp` showed `UID:0002H3` as an `Empty Emitter Marker` under the Application root.
- Current implemented state: target page now records `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, and formal first-draft `Application::RequestExit()` C++.

## Target State

Before implementation, the target already documented the broad shutdown request behavior: active browser, map, minimap, and screen checks; a deferred callback path through `PlainMemberFunctionObject0<Application>`; and a direct fallback that signals the Application shutdown event and sets the exit-request flag. The previous blank C++ reason is superseded. The old blocker said pane/global helper names and callback type names were not final-source quality. The accepted report evidence resolved those blockers enough for a formal first-draft C++ block, which is now present in the target:

- `Application+0x83a` is source-facing `m_exitRequested`, cross-checked by [UID:0002H4][ApplicationIsExitRequested](../../../by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md).
- `Application+0x83c` is source-facing `m_hShutdownEvent`, used by the message loop and cleanup docs.
- The callback helper at `0x00464e20` should be referenced as private `Application::SignalExitRequested()`. It is outside the target range, so this report does not recommend pasting its helper body into UID0002H3.
- `g_activeBrowserControlPane`, `g_activeBrowserPane`, `g_activeMapPane`, `g_pMiniMapVersionManager`, and `g_pScreenPane` all have current source-facing documentation.
- The `g_pMiniMapVersionManager` call is best represented as `delete g_pMiniMapVersionManager;`, not as an invented `Shutdown(bool)` or raw virtual call name. It is a vtable slot-0 scalar deleting destructor call with pushed delete flag `1`.
- The callback vtable is documented as `PlainMemberFunctionObject0<void (__thiscall Application::*)(), Application>`, and UID000324 now carries the accepted comment-only generated-template proof.

## Evidence Checked

- Report-only MCP availability at the time of acceptance: `idb_list` and `server_health` were rechecked after supervisor all-clear using then-active session `c9671f69`; session was for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19076`, server health OK. Supervisor later reported `c9671f69` stale/dead after implementation; no new MCP-backed claims were added during this status cleanup.
- Report-only MCP exact range checks: `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `callees`, `get_bytes`, `get_int`, and bounded `find_bytes` checks were used for `0x00464e20`, `0x00464e40`, `0x00464f40`, `0x004671a0`, `0x004673f0`, `0x00612e40`, and immediate callees.
- Report-only MCP source-name checks: targeted decompilation covered `0x0049df20`, `0x005047f0`, `0x00557440`, and `0x00559110` to verify Browser/DialogPane activation, MapPane exit, cursor hide, and ScreenPane fade-out callback enqueue behavior.
- Current docs checked: target UID0002H3, `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, `by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md`, MiniMapVersionManager class/file/global/memory pages, ScreenPane callback docs, MapPane exit docs, BrowserPane/global docs, and FunctionObjects support docs for UID000324/UID00032C/vtable data.
- Historical generated read-only evidence checked before implementation: `auto-generated/NexusTK/app/Application.cpp` showed UID0002H3 at the empty-emitter marker block, and the generated score row was stale compared with the target page.
- Post-callback generated read-only evidence checked after validators: `auto-generated/NexusTK/app/Application.cpp` latest observed header was `validator-command-id: 000000000714`, `validator-refreshed-at: 2026-06-29T12:26:43-04:00`, and UID0002H3 emitted `void Application::RequestExit()` at `90/92` instead of an Empty Emitter Marker.
- Search terms used across existing reports/docs included `0002H3`, `00464e40`, `ApplicationRequestExit`, `ApplicationIsExitRequested`, `Application`, `PlainMemberFunctionObject0`, `000324`, and `0002H4`.
- Negative checks: `lookup_funcs` confirms no function starts at `0x00464e38`, `0x00464f34`, or `0x00464f47`; helper pointer byte search found no ordinary function-pointer table beyond the construction immediate; `0x00464e20` has no direct code callers and is reached through the callback object only.

## Positive Evidence Summary

- Direct MCP fact: `sub_464E40` is a `0xf4` byte function at `0x00464e40-0x00464f34`; no successor code is inside the target page.
- Direct MCP fact: the target checks active Browser, MapPane, MiniMapVersionManager, and ScreenPane globals in that order before the final event/flag path.
- Direct MCP fact: the direct fallback calls `SetEvent(*(this+0x83c))` and writes byte `1` to `this+0x83a` at `0x00464f1c`.
- Direct MCP fact: the deferred path allocates 24 bytes, initializes an `LObject`/FunctionObject base, stores vtable `0x00612e40`, stores helper pointer `0x00464e20`, stores zero adjustment, stores the Application object pointer, hides the cursor, and queues the callback through `sub_559110`.
- Direct MCP fact: helper `0x00464e20-0x00464e38` performs the same `SetEvent` and flag write and is referenced only by the callback construction store at `0x00464ecc`.
- Documentation fact: `by-class/Application.md` already records `m_exitRequested` at `+0x83a`, `m_hShutdownEvent` at `+0x83c`, and private helper name direction `ApplicationSignalExitEvent` / `Application::SignalExitRequested`.
- Documentation fact: [UID:0002H4] emits `bool Application::IsExitRequested() const`, proving the `+0x83a` field is a bool-style exit-request byte rather than a generic status flag.
- Documentation fact: [UID:000324] and FunctionObjects support docs now document the Application callback invoke/object-size wrappers as compiler-generated template output, so UID0002H3 should express the source-level callback construction rather than emit raw callback vtable/invoke code.

## IDA MCP Facts

| Address / item | Current MCP fact | Meaning |
| --- | --- | --- |
| `0x00464e20` | `lookup_funcs` resolves `sub_464E20`, size `0x18`; decompile shows `SetEvent(*(this+0x83c))` then `*(this+0x83a)=1`; analyze shows one block and no code callers. | Private Application exit-signal helper used as the deferred callback target. |
| `0x00464e40` | `lookup_funcs` resolves `sub_464E40`, size `0xf4`; disassembly has 15 blocks and complexity 3. | Exact target range remains `0x00464e40-0x00464f34`. |
| `0x00464e67/0x00464e76` | Reads `g_activeBrowserControlPane`, then calls `sub_49DF20(g_activeBrowserPane)` if the control pane is live. | Source-facing form is guarded active browser control and pending DialogPane/BrowserPane activation. |
| `0x00464e7b/0x00464e87` | Reads `g_activeMapPane`, pushes `1`, calls `0x005047f0`. | Source-facing form is `g_activeMapPane->ExitToMenu(true)`. |
| `0x00464e8c/0x00464e9a` | Reads `g_pMiniMapVersionManager`, loads vtable slot 0, pushes `1`, calls virtual slot. | Source-facing form is `delete g_pMiniMapVersionManager;`; MiniMap docs identify slot 0 as scalar deleting destructor and teardown clears the singleton. |
| `0x00464e9c-0x00464f0b` | If `g_pScreenPane` exists, allocates `0x18`, writes callback vtable `0x00612e40`, helper pointer `0x00464e20`, adjustor `0`, and `this`, calls cursor hide, then queues through `0x00559110`. | Source-facing form is a `PlainMemberFunctionObject0<void (__thiscall Application::*)(), Application>` callback to `Application::SignalExitRequested()`, then `ShowCursor(FALSE)` and `g_pScreenPane->QueueFadeOutCallback(callback)`. |
| `0x00464f10-0x00464f1c` | Direct fallback calls `SetEvent(*(this+0x83c))`, then writes `1` to `this+0x83a`. | Source-facing direct fallback is `SetEvent(m_hShutdownEvent); m_exitRequested = true;`. |
| `0x00612e40` | Vtable slots resolve to `0x004671f0`, `0x004f4b10`, `0x0041b6c0`, `0x004671a0`, and `0x004673f0`. | This is the concrete `PlainMemberFunctionObject0<Application>` callback vtable supporting the source-level callback construction. |

## Negative Evidence Summary

- `0x00464e20` should not become a public Application method page inside UID0002H3: it is outside the target range and has no direct code callers, only the callback-object data reference from the target construction site.
- `ScreenPane` is not the owner of UID0002H3: it receives the fade-out callback after Application creates a callback to its own helper, but Application owns the event handle, exit flag, and callback target.
- `FunctionObjects` is not the owner of UID0002H3: FunctionObjects owns generated callback-template support such as UID000324, while the source-level binding site belongs in Application.
- `MiniMapVersionManager` is not the owner of UID0002H3: the target merely deletes the active singleton during shutdown. The MiniMap manager owns its destructor and singleton storage, not Application shutdown orchestration.
- A raw virtual call name for the minimap path is rejected. The pushed `1` plus slot-0 call and current MiniMap docs identify a scalar deleting destructor pattern, so `delete g_pMiniMapVersionManager;` is more source-faithful than a fabricated `Close(true)` or `Release(true)` method.
- Blank formal C++ is no longer justified. The remaining exact original spelling uncertainty is normal inferred-source risk and does not block a first-draft block because source-facing names and route are documented and the target clears the C++ gate.

## Heuristic / Inference Reanalysis And Validation

The core source-quality problem was whether the target's blank emitter represented a true no-code proof or an unresolved source-shape gap. Current evidence supports source emission.

`RequestExit` is a source-authored Application method because it uses `this` offsets owned by Application, reaches the exact Application exit getter field, and creates a callback to a private Application helper. It coordinates other subsystem singletons but does not belong to those subsystems. The source order should preserve the binary order: browser pending-control activation, map exit-to-menu, minimap manager deletion, screen-pane deferred callback, then direct event fallback.

The source-facing names are inferred but validated against current docs:

- `m_exitRequested` is validated by UID0002H4 and Application field docs.
- `m_hShutdownEvent` is validated by message-loop wait, cleanup close, and both setter paths.
- `Application::SignalExitRequested` is the best helper name because the helper does only `SetEvent` plus `m_exitRequested = true`; `RequestExit`, cleanup, destructor, and general shutdown names were rejected because the helper does not notify Browser/Map/MiniMap/ScreenPane and is not directly called by shutdown callers.
- `delete g_pMiniMapVersionManager` is validated by MiniMapVersionManager docs that identify destructor `0x00456480`, scalar deleting destructor `0x00457480`, singleton clear refs, and the Application transition reader at `0x00464e8c`.
- `QueueFadeOutCallback` is validated by ScreenPane docs and MCP decompile of `0x00559110`, which resets fade transition state and posts event `0x46644f74` (`FdOt`) with the callback object.

The callback helper return-type mismatch is not a blocker. IDA decompiles `0x00464e20` as returning `BOOL` because `SetEvent` leaves a value in `EAX`; the decorated callback vtable type is `void (__thiscall Application::*)()`, and a source `void Application::SignalExitRequested()` can compile to the same observable body with the `SetEvent` result left incidentally in `EAX`.

No Wave2/Wave3 artifact is used as authority. Generated Application.cpp is used only as a read-only symptom of the empty-emitter problem and stale generated scores.

## Ranked Ownership Analysis

### 1. Application class [UID:00000D]

- Evidence for: target is a `thiscall` method using Application-owned offsets `+0x83a` and `+0x83c`; it binds a callback to private Application helper `0x00464e20`; UID0002H4 reads the same flag; current page already has owner/emitter route through Application.
- Evidence against: none material. The method calls many external subsystems, but they are shutdown participants.
- Decision: keep `CANONICAL_OWNER:00000D` and `EMITTER_UIDS:00000D`.

### 2. Application file root [UID:0000HG]

- Evidence for: Application file root emits the class and generated output path `NexusTK/app/Application.cpp`; support docs describe lifecycle methods in this source module.
- Evidence against: by-structure says direct semantic owner should be the narrowest true owner. This is a class method, so the class is the direct owner, with the file root reached through the owner/emitter chain.
- Decision: retain as source placement/file route, not direct canonical owner.

### 3. FunctionObjects support [UID:0000AJ / UID000324]

- Evidence for: target constructs `PlainMemberFunctionObject0<Application>` and relies on callback invoke/object-size wrappers.
- Evidence against: FunctionObjects owns the template support/vtable/invoke machinery, not the Application binding site or shutdown semantics.
- Decision: cite as support evidence only; no FunctionObjects support edit is required unless the supervisor wants to add a cross-reference to the new source-ready UID0002H3 status.

### 4. ScreenPane, MapPane, BrowserPane, MiniMapVersionManager

- Evidence for: all are touched by the shutdown path.
- Evidence against: each is a callee/consumer. None owns `m_exitRequested`, `m_hShutdownEvent`, or `Application::SignalExitRequested`.
- Decision: rejected as owners.

## Source Placement

Recommended source placement is `Application::RequestExit()` in `NexusTK/app/Application.cpp` through Application class [UID:00000D] and file root [UID:0000HG]. The private helper declaration `void Application::SignalExitRequested()` belongs on the Application class/header side or near Application private method declarations, but UID0002H3 should only emit the `RequestExit` body because the helper body is outside the target range.

The final source should include or already have declarations for:

- `g_activeBrowserControlPane` and `g_activeBrowserPane` in the Browser/UI support area.
- `g_activeMapPane` and `MapPane::ExitToMenu(bool)`.
- `g_pMiniMapVersionManager` with a virtual destructor/scalar deleting destructor generated by the compiler.
- `g_pScreenPane` and `ScreenPane::QueueFadeOutCallback(...)`.
- `PlainMemberFunctionObject0` and the zero-argument Application member callback type.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. `0x00464e40-0x00464f34` is one exact function. The private callback helper at `0x00464e20-0x00464e38` is a separate predecessor helper and should remain documented as supporting evidence unless a future exact helper page is assigned. The following getter [UID:0002H4] begins at `0x00464f40`; the `0x00464f34-0x00464f40` gap is `0xcc` padding and should not be absorbed.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:00000D`, and current average score is already greater than 85. The remaining work is source-quality incorporation, not a no-code proof.

Recommended formal insertion content for UID0002H3:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::RequestExit()
{
    if (g_activeBrowserControlPane != NULL)
        g_activeBrowserPane->ActivatePendingControl();

    if (g_activeMapPane != NULL)
        g_activeMapPane->ExitToMenu(true);

    if (g_pMiniMapVersionManager != NULL)
        delete g_pMiniMapVersionManager;

    if (g_pScreenPane != NULL)
    {
        typedef void (__thiscall Application::*ApplicationExitCallback)();
        PlainMemberFunctionObject0<ApplicationExitCallback, Application> *callback =
            new PlainMemberFunctionObject0<ApplicationExitCallback, Application>(
                &Application::SignalExitRequested, 0, this);

        ShowCursor(FALSE);
        g_pScreenPane->QueueFadeOutCallback(callback);
        return;
    }

    SetEvent(m_hShutdownEvent);
    m_exitRequested = true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This preserves the binary's observable behavior: it keeps the same subsystem order, represents the minimap virtual destructor call as source-level deletion, expresses the callback construction that should regenerate the `PlainMemberFunctionObject0<Application>` vtable route, hides the cursor before queueing the fade-out callback, and keeps the direct fallback inline instead of calling the helper.

Reason not to include `Application::SignalExitRequested()` body here: its code range is `0x00464e20-0x00464e38`, outside the UID0002H3 target. The target may reference the private helper by name, but the helper body needs its own exact range page or class/support declaration handling if emitted later.

## Recommended Target Doc Changes

- In `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`, change score from `87/90` to `90/92`.
- Keep `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000D`.
- Replace the blank formal C++ block with the exact `Application::RequestExit()` insertion content above.
- Update the Item Summary to state that current MCP now supports a source-ready first-draft shutdown request method with active subsystem cleanup, minimap deletion, deferred `PlainMemberFunctionObject0<Application>` callback, and direct event/flag fallback.
- Replace stale Reconstruction Notes that say C++ remains blank because helper/callback names are unresolved. Preserve the historical note as superseded, and record the new source-facing name decisions and rejected alternatives.
- Add current MCP session `c9671f69` evidence for exact range, helper, callback construction, vtable slots, direct fallback, callers, and generated empty-emitter symptom.

## Recommended Support Doc Changes

- `by-class/Application.md`: update UID0002H3 method entry to source-ready status; add that `Application::RequestExit()` now emits with private `Application::SignalExitRequested()` callback binding; preserve field evidence for `m_exitRequested` and `m_hShutdownEvent`; mention minimap path is `delete g_pMiniMapVersionManager`.
- `by-file/Application.md`: update the Application lifecycle/source-output discussion so UID0002H3 is no longer listed as blocked by callback enqueue/helper names; note generated Application.cpp should lose the UID0002H3 empty-emitter marker after validator refresh.
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`: update the UID0002H3 child row to `90/92` and source-ready; preserve the parent aggregate as no standalone emitted body.
- `by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md`: add a short relation note that UID0002H3 now emits the writer-side direct fallback and deferred helper binding for `m_exitRequested`; do not change its formal getter body.
- FunctionObjects support docs: no mandatory edit is required. UID000324, UID00032C, and the `0x00612e40` vtable data already document the generated-template route at same-or-greater detail. If edited anyway, only add a cross-reference that UID0002H3 now emits the source-level construction site; do not change ownership or emit raw wrapper code.

## Score And Metadata Recommendation

- Current metadata: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, blank C++.
- Recommended metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`, formal C++ populated.
- Completion rationale: raise to 90 because exact current MCP evidence now documents the range, bytes, direct/deferred paths, callback helper, callback vtable, source-facing dependency names, generated empty-emitter symptom, and implementation-ready formal C++.
- Confidence rationale: raise to 92 because binary behavior and owner/emitter route are strong, and the remaining uncertainty is exact original spelling of private helper/API names, not behavior or source placement.
- Reason not higher: no final-audit `95+` score is warranted because exact original helper spelling, declaration placement, and some surrounding subsystem API names remain inferred.
- Owner/emitter changes: none.
- Split/rename/new child changes: none.

## Open Questions With Attempted Resolution

- Exact original private helper spelling remains unknown. Resolved for implementation by using inferred `Application::SignalExitRequested()`, which directly describes the helper body and matches Application field ownership. This does not block first-draft C++.
- Exact original browser pending-control method spelling remains unknown. Resolved for implementation by using `ActivatePendingControl()`, backed by current `sub_49DF20` docs and the active browser/global evidence. Raw `sub_49DF20` is rejected.
- Exact original ScreenPane queue method spelling remains inferred. Resolved for implementation by using `QueueFadeOutCallback()`, backed by `0x00559110` behavior and existing ScreenPane callback docs.
- MiniMap virtual call source shape is resolved as `delete g_pMiniMapVersionManager;`, based on scalar deleting destructor evidence. A fabricated boolean cleanup method is rejected.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID0002H3 is exact function `0x00464e40-0x00464f34`, no split needed. | High | MCP `lookup_funcs`, disassembly, padding checks. | Target Scope, Boundary Evidence, Range/Split | incorporate | applied: target UID0002H3 IDA Evidence/Reconstruction Notes record exact `0x00464e40-0x00464f34`, separate helper `0x00464e20-0x00464e38`, next getter boundary, and rejected split route. |
| C002 | Direct fallback writes `m_exitRequested` at `+0x83a` and signals `m_hShutdownEvent` at `+0x83c`. | High | MCP decompile/disasm; UID0002H4 getter; Application field docs. | Target Behavior, by-class/Application, UID0002H4 relation note | incorporate | applied: target Behavior/Exit Path Evidence, `by-class/Application.md` field/helper notes, and UID0002H4 writer-sync note all document `SetEvent(m_hShutdownEvent)` plus `m_exitRequested = true`. |
| C003 | Deferred path constructs `PlainMemberFunctionObject0<void (__thiscall Application::*)(), Application>` targeting private helper `0x00464e20`. | High | MCP stores at `0x00464ec6/cc/d3/da`; vtable slots; UID000324 docs. | Target IDA Evidence, First-Draft C++, FunctionObjects cross-reference if edited | incorporate | applied: target C++ block and IDA Evidence document the `PlainMemberFunctionObject0<ApplicationExitCallback, Application>` allocation, helper pointer, vtable `0x00612e40`, and UID000324/UID00032C support route; FunctionObjects docs were already sufficient and were not edited. |
| C004 | Private helper should be referenced as `Application::SignalExitRequested()` but its body is outside UID0002H3 and must not be pasted into this target. | High | Helper range `0x00464e20-0x00464e38`; no code callers; callback-only reference. | Target Reconstruction Notes, by-class/Application | incorporate | applied: target and `by-class/Application.md` name the helper as `Application::SignalExitRequested()` and explicitly reject helper-body-in-target because `0x00464e20-0x00464e38` is outside UID0002H3. |
| C005 | MiniMap manager path should be source-shaped as `delete g_pMiniMapVersionManager;`. | High | MCP slot-0 call with push `1`; MiniMapVersionManager scalar deleting destructor docs and singleton clear refs. | Target Heuristic/Reanalysis, First-Draft C++, Application support docs | incorporate | applied: target C++/Behavior/Reconstruction Notes and Application support docs use `delete g_pMiniMapVersionManager;` and reject fabricated MiniMap cleanup method names. |
| C006 | UID0002H3 should emit formal C++ now; blank emitter is stale. | High | Gate satisfied: reconstructable true, emitter route present, average score greater than 85, names resolved enough for first draft. | Target header/C++ block and generated refresh expectation | incorporate | applied: target now contains formal `void Application::RequestExit()` C++; target validator command `000000000707` completed generated refresh and generated `Application.cpp` latest read-only inspected header command `000000000714` emits UID0002H3 code. |
| C007 | Recommended score is `90/92`; owner/emitter unchanged. | Medium-high | Current evidence improvement, source-ready block, remaining spelling uncertainty. | Target metadata and support child rows | incorporate | applied: target metadata is `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `EMITTER_UIDS:00000D`; support child rows/notes reflect `90/92`. |
| C008 | Pre-callback generated `Application.cpp` showed UID0002H3 as an Empty Emitter Marker with stale score row; the implementation callback was required to remove that generated symptom through validator refresh. | High | Read-only generated Application.cpp inspection before and after callback. | Report generated-refresh expectation; no manual generated edit | incorporate | applied: read-only inspection of `auto-generated/NexusTK/app/Application.cpp` after validators shows latest observed header `validator-command-id: 000000000714`, `validator-refreshed-at: 2026-06-29T12:26:43-04:00`, and UID0002H3 emitted as `void Application::RequestExit()` at lines 146-172, not an Empty Emitter Marker. |
| C009 | FunctionObjects support docs already carry enough callback-template evidence and do not require ownership or C++ changes. | Medium-high | UID000324/UID00032C/vtable support docs. | Report and optional support notes | already-present | already-present/excluded from edit: UID000324/UID00032C/vtable support docs already cover callback-template mechanics; implementation only added target/support references and did not lease or edit FunctionObjects docs to avoid overlap with B002/B008. |

## Validator Results

Implementation callback validators were run from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory\0x00464e40-0x00464f34.ApplicationRequestExit.md --apply --queue-timeout 240 --wait-generated`: exit code `0`, ok `1`, command id `000000000707`, timestamp `2026-06-29T12:20:50-04:00`, generated refresh completed. Notable updates: UID0002H3 completion/confidence `90/92`, owner `00000D`, autogen registry `blank -> block`, reference index additions UID000324/UID00032C, `autogen_cpp_update: 1`. Validator also reported unrelated stale/missing coverage and empty-emitter warnings outside this target set.
- `python .\tools\validator.py --mode file --file by-class\Application.md --apply --queue-timeout 240`: exit code `0`, ok `1`, command id `000000000708`, timestamp `2026-06-29T12:21:15-04:00`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file\Application.md --apply --queue-timeout 240`: exit code `0`, ok `1`, command id `000000000709`, timestamp `2026-06-29T12:21:22-04:00`, generated refresh deferred. Existing unrelated warning remains: `missing_ref_uid 0003OY` in `by-file/Application.md`.
- `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240`: exit code `0`, ok `1`, command id `000000000710`, timestamp `2026-06-29T12:21:29-04:00`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-memory\0x00464f40-0x00464f47.ApplicationIsExitRequested.md --apply --queue-timeout 240`: exit code `0`, ok `1`, command id `000000000711`, timestamp `2026-06-29T12:21:38-04:00`, generated refresh deferred; validator normalized UID0002H4 registry/header metadata.
- Final consistency rerun after the lifecycle historical-supersession sentence was updated: `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply --queue-timeout 240`: exit code `0`, ok `1`, command id `000000000712`, timestamp `2026-06-29T12:24:57-04:00`, generated refresh deferred.

Generated output inspection was read-only. `auto-generated/NexusTK/app/Application.cpp` latest observed header was `validator-command-id: 000000000714` and `validator-refreshed-at: 2026-06-29T12:26:43-04:00`; UID0002H3 appears as `void Application::RequestExit()` with completion/confidence `90/92` and the accepted callback/minimap/direct-fallback body. UID0002H3 no longer appears as an Empty Emitter Marker.

## Changed Files

- Modified target: `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
- Modified support: `by-class/Application.md`, `by-file/Application.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, `by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md`
- Modified report: `tools/leaser/Agents/Agent-B007/research/0002H3-ApplicationRequestExit-empty-emitter-source-quality.md`
- Generated output changed only through validator refresh and was inspected read-only: `auto-generated/NexusTK/app/Application.cpp`
- Leases taken only for immediate edited by-* docs: target UID0002H3, `by-class/Application.md`, `by-file/Application.md`, lifecycle aggregate, and UID0002H4 getter relation page. FunctionObjects docs were not edited. Final release command `python .\leaser.py B007 unlease` returned Success for active B007 target/UID0002H4 leases, and a post-release `current_leases.md` check showed no B007 rows.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation was received for implementation callback `B007-implement-0002H3-ApplicationRequestExit-20260629`.
- [x] Updated `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md` metadata from `87/90` to `90/92`, while preserving `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000D`.
- [x] Inserted the exact formal `Application::RequestExit()` `RECONSTRUCTION_CPP CODE` block from this report into UID0002H3.
- [x] Updated UID0002H3 Item Summary, Behavior, IDA Evidence, Reconstruction Notes, score rationale, and Changes with current MCP session `c9671f69` evidence and the resolved source-facing names.
- [x] Preserved historical blank-C++ notes as superseded rather than deleting useful context.
- [x] Updated `by-class/Application.md` method/field/helper notes for UID0002H3, `m_exitRequested`, `m_hShutdownEvent`, and private `Application::SignalExitRequested()`.
- [x] Updated `by-file/Application.md` so UID0002H3 is no longer described as blocked by callback/helper names and now contributes generated first-draft `Application::RequestExit()` through the Application file route.
- [x] Updated `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` child row and lifecycle discussion for UID0002H3 `90/92` source-ready status while preserving aggregate non-emitting handling.
- [x] Updated `by-memory/0x00464f40-0x00464f47.ApplicationIsExitRequested.md` with the UID0002H3 writer/deferred-helper relation; left its getter C++ unchanged.
- [x] Confirmed FunctionObjects support docs already contain UID000324/UID00032C/vtable route details at same-or-greater detail; no FunctionObjects support doc was leased or edited.
- [x] Preserved rejected alternatives and negative evidence: no ScreenPane/FunctionObjects/MiniMap ownership change, no fabricated minimap cleanup method name, no helper body pasted into UID0002H3, no split.
- [x] Ran the scoped validators listed in `Validator Results`, recording command, command id, timestamp, exit code, and ok count.
- [x] Inspected `auto-generated/NexusTK/app/Application.cpp` read-only after generated refresh and confirmed UID0002H3 no longer appears as an Empty Emitter Marker.
- [x] Updated Claim And Incorporation Ledger verification states after implementation callback with `applied`, `already-present`, and explicit no-edit reasons for each accepted claim.
- [x] Released B007 leases and confirmed `current_leases.md` contains no active B007 rows.
- [x] No manual `-coverage-report.md`, generated file, validator/tool state, IDA DB, executed archive, or supervisor ledger edit was made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002H3-ApplicationRequestExit-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002H3-ApplicationRequestExit-empty-emitter-source-quality.md","timestamp":"2026-06-29T12:37:27","uid":"0002H3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
