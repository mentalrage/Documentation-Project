** TARGET-REPORT-UID:0001JD **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B005 Source-Quality Report: UID0001JD TerminalPaneReconnectLeaveCallback

## Finalized Report / Current Recommendation

Implementation-callback artifact for [UID:0001JD] `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`.

Implemented recommendation: updated the target from `85/91` to `89/93`, preserved `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, and replaced the empty formal C++ marker with a scoped first-draft `void TerminalPane::OnReconnectOrLeave(unsigned long decision)` method body. The accepted MCP evidence proves the callback object type is `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`, so the older `int` source-facing signature was corrected to `void`; raw Hex-Rays `int` is an EAX/callee-return artifact and not the callback type.

This report remains active in `tools/leaser/Agents/Agent-B005/research/` and now awaits supervisor execute review. The target and scoped support by-* docs were edited during the approved callback, scoped validators were run, and leases were released. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry/report move, manual report move, coverage edit, supervisor-ledger edit, validator-state edit, queue/lock edit, or manual generated-file edit was performed.

## Supporting Research

The useful prior research is contextual rather than a direct UID0001JD B-report:

| Search term set | Result |
| --- | --- |
| `0001JD`, `TerminalPaneReconnectLeaveCallback`, `0x0058b620`, `0x0058b56d`, `OnReconnectOrLeave` in `tools/leaser/Agents` and `executed-b-agent-research` | No direct executed B-report for UID0001JD. Hits were A002 notes, supervisor assignment text, shared-string reports, the B006 parent aggregate report, and B002 alert-callback research. |
| `0x0058b620`, `0x0058b56d`, `TerminalPane` in `executed-b-agent-research/B006/0001JB-TerminalPaneAndSetup-source-quality.md` | B006 identified the child as source-authored, callback-referenced, and ready for child C++; it still used `int TerminalPane::OnReconnectOrLeave(unsigned long decision)` and did not implement the child page. |
| `0x0058b620`, `decision`, `TerminalPane` in `executed-b-agent-research/B002/00012X-versatile-alert-pane-callbacks-source-quality.md` | B002 showed the alert result semantics: nonzero is the primary/reconnect route and zero is the secondary/leave route. |
| `0x0058b620`, `0x0058b5ac`, `0x0058b5b1` in B001/B002/B003 shared `Leave`/`Reconnect` reports | Those reports confirm TerminalPane has one independent prompt-label use and stores this callback, but they are owner/no-owner string reports, not UID0001JD child reports. |

## Target

- UID: `0001JD`
- Target doc: `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`
- Current owner/emitter route: [UID:0000OI] `by-file/TerminalPane.md`
- Current generated file: `auto-generated/NexusTK/login/TerminalPane.cpp`
- Current tracker row after callback: `89/93`, reconstructable, direct B report count `0`

## Current Target State

The target now records `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, blank emitter position, and the accepted formal C++ block. The body documents exact `0x0058b620-0x0058b64f` range evidence, callback store at `0x0058b56d`, zero direct callers, callees `0x005975e0` and `0x00464e40`, prompt-label construction, the typed `void` callback-object evidence, and the accepted source-facing signature `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`.

Generated `auto-generated/NexusTK/login/TerminalPane.cpp` was most recently refreshed by scoped validator command `000000007950` at `2026-07-08T15:27:11-04:00` with `validator-refresh-source: deferred-generated-refresh`. It now shows `UID:0001JD ... Completion:89 | Confidence:93` followed by `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`, `m_timerHandler.ScheduleTimer(0, 0, 0, 0)`, and `g_pApplication->RequestExit()`. This generated refresh was validator-produced; no manual generated-file edit was made.

## Supervisor Active Recheck

Active assignment is UID0001JD implementation callback for Agent-B005 after supervisor Gate 1 approval. I used the project `ntk-b-agent-workflow`, did not retarget, did not spawn subagents, ran only scoped validators for the five edited by-* docs, and did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry/report moves, or manual report moves. MCP evidence used for the accepted report remains session `43ccf853`; no fallback-only evidence was produced.

## Heuristic / Inference Reanalysis And Validation

Facts from IDA are separated from source inference:

- IDA facts: function `sub_58B620` is a `0x2f` byte function at `0x0058b620`; `0x0058b64f` is not a function and is `0xcc` alignment; `sub_58B650` begins at `0x0058b650`; data xref `0x0058b56d` stores `sub_58B620`; code xrefs to the callback entry are zero; the only callees are `sub_5975E0` and `sub_464E40`; the installer writes the decorated `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable at `0x0058b567`.
- Documentation facts: `0x005975e0` is accepted as `TimerHandler::ScheduleTimer`; `0x00464e40` is accepted as `Application::RequestExit`; `0x00622f28` / `0x00622f1c` are pooled `Reconnect` / `Leave` literals emitted at source-use sites, not standalone globals.
- Inference: `decision` is the alert result value. B002 alert-callback research plus current TerminalPane prompt argument order support nonzero as `Reconnect` and zero as `Leave`. The source-facing field name for the `+0xa4` timer subobject is inferred as `m_timerHandler`; the offset/subobject behavior itself is IDA fact.

Stale Wave2/Wave3 or older generated references were ignored where they conflict with the current IDA session and current by-* docs.

## Evidence Standards Used

Accepted evidence requires current IDA MCP proof for address/range/call/xref claims, current by-* docs for source-facing names already accepted elsewhere, and explicit separation of inference from IDA fact. Generated files and coverage reports were read only as freshness/status evidence, not edited.

## Evidence Checked

- Skill and assignment docs: `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, and `tools/leaser/Agents/Agent-B005/goal.md`.
- Target doc: `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`.
- Support docs: `by-file/TerminalPane.md`, `by-class/TerminalPane.md`, `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`, `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md`, `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`, `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`, `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`, `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`, and `by-global/g_pTerminalPane.md`.
- Generated/status evidence read only: `auto-generated/NexusTK/login/TerminalPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `by-memory/-coverage-report.md`.
- Old-report search terms recorded above under Supporting Research.

## Range / Split / Padding / Reclassification Analysis

Current MCP `lookup_funcs` reports `sub_58B620` at `0x0058b620`, size `0x2f`, giving half-open `0x0058b620-0x0058b64f`. The byte at `0x0058b64f` is `0xcc` padding, and `lookup_funcs 0x0058b64f` returns not-a-function. The successor `sub_58B650` starts at `0x0058b650`, size `0xb42`, which preserves the established TerminalSetupPane constructor boundary.

The predecessor side remains padding between `TerminalPane::OnClose()` and the callback. Current bytes over `0x0058b5f0-0x0058b660` show the tail of `sub_58B5E0`, then `0xcc` padding from `0x0058b5fc` through `0x0058b61f`, the callback bytes from `0x0058b620` through `0x0058b64e`, one `0xcc` byte at `0x0058b64f`, and the setup constructor prologue at `0x0058b650`. No split, merge, padding expansion, or non-reconstructable reclassification is recommended.

## IDA MCP Facts

Current MCP session used: `43ccf853`.

`idb_list` reported one active/adopted worker-backed session:

| Field | Value |
| --- | --- |
| session_id | `43ccf853` |
| input_path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| filename | `NexusTK.exe.i64` |
| is_active / is_analyzing | `true` / `false` |
| pid / worker_pid | `14028` / `14028` |

`server_health` for `43ccf853`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

Current target facts:

| Query | Current MCP result |
| --- | --- |
| `lookup_funcs 0x0058b620` | `sub_58B620`, size `0x2f`. |
| `lookup_funcs 0x0058b64f` | Not a function. |
| `lookup_funcs 0x0058b650` | `sub_58B650`, size `0xb42`. |
| `xrefs_to 0x0058b620` | Exactly one data xref: `0x0058b56d` in `sub_58B470`, size `0x170`. |
| `xref_query 0x0058b620 to code` | Total `0`, no ordinary code callers. |
| `xref_query 0x0058b620 to data` | Total `1`, the callback-target store at `0x0058b56d`. |
| `callees 0x0058b620` | `0x005975e0` / `sub_5975E0` and `0x00464e40` / `sub_464E40` only. |
| `disasm 0x0058b620` | `cmp [ebp+arg_0],0`; zero jumps to leave path; nonzero pushes four zeroes, adds `ecx,0xa4`, calls `sub_5975E0`, then `retn 4`; zero loads `unk_67AB1C`, calls `sub_464E40`, then `retn 4`. |
| `decompile 0x0058b620` | Hex-Rays raw body returns `sub_5975E0((void *)(this + 164),0,0,0,0)` for nonzero and `sub_464E40(unk_67AB1C)` for zero. |

Current installer facts from `sub_58B470`:

| Address | Fact |
| --- | --- |
| `0x0058b567` | Stores `??_7?$PlainMemberFunctionObject@P8TerminalPane@@AEXK@ZV1@@@6B@`, the decorated `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable. |
| `0x0058b56d` | Stores callback target `sub_58B620` at callback object offset `+0x08`. |
| `0x0058b574` | Stores zero adjustment at callback object offset `+0x0c`. |
| `0x0058b57b` | Stores the adjusted/normalized `TerminalPane` object pointer at callback object offset `+0x10`. |
| `0x0058b5ac` | Pushes `off_622F1C` / `Leave`. |
| `0x0058b5b1` | Pushes `off_622F28` / `Reconnect`. |
| `0x0058b5b6-0x0058b5c5` | Pushes callback object, owner pointer, message id `0x9d`, calls text builder `sub_4F0350`, then calls `sub_4A0690` alert constructor/wrapper. |

Current callback-support facts:

| Query | Current MCP result |
| --- | --- |
| `xrefs_to 0x0062dde8` | Exactly one xref, data ref from `0x0058b567` in `sub_58B470`. |
| `entity_query names 0x0062dde8-0x0062ddfc` | Vtable name `??_7?$PlainMemberFunctionObject@P8TerminalPane@@AEXK@ZV1@@@6B@`; next name `aIRunregistry` at `0x0062ddfc`. |
| vtable slot `0x0062ddf4` | `0x0049af00`, the generic member-function invoke thunk; it loads object pointer from `+0x10`, applies adjustor `+0x0c`, loads target from `+0x08`, and jumps to it, preserving the caller's argument. |

## Function / Child Inventory

| Range/address | Inventory status | Current conclusion |
| --- | --- | --- |
| `0x0058b5e0-0x0058b5fc` | predecessor function | `TerminalPane::OnClose()` ends before padding. |
| `0x0058b5fc-0x0058b620` | predecessor padding | `0xcc` alignment before this callback. |
| `0x0058b620-0x0058b64f` | target child | Exact callback body for `TerminalPane::OnReconnectOrLeave(unsigned long decision)`. |
| `0x0058b64f-0x0058b650` | successor alignment | One `0xcc` byte. |
| `0x0058b650+` | successor function | `TerminalSetupPane` constructor starts at `sub_58B650`. |

## Direct Xref / Caller Inventory

| Target | Current xref result | Meaning |
| --- | --- | --- |
| `0x0058b620` code refs | `0` | No direct ordinary callers; callback-only reachability. |
| `0x0058b620` data refs | `1`, from `0x0058b56d` | `TerminalPane::OnDisconnect` installs the member callback target. |
| `0x0062dde8` data refs | `1`, from `0x0058b567` | Same installer writes the typed callback vtable. |
| `0x00622f28` data refs | `4`, including `0x0058b5b1` | `Reconnect` is shared pooled literal; TerminalPane owns one source use only. |
| `0x00622f1c` data refs | `4`, including `0x0058b5ac` | `Leave` is shared pooled literal; TerminalPane owns one source use only. |

## Documentation Evidence And IDA Status

- `by-file/TerminalPane.md` correctly routes the child through `NexusTK/login/TerminalPane.cpp`, records `TerminalPane::OnDisconnect`, and mentions the callback target at `0x0058b56d`.
- `by-class/TerminalPane.md` records `OnReconnectOrLeave(unsigned long decision)` but currently sketches it as `int`; this should be corrected to `void` because the IDB vtable type is decorated as `void (__thiscall TerminalPane::*)(unsigned long)`.
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` already contains the split map and callback object type; it should gain the current-session child-C++ readiness and `void` signature correction if absent.
- `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` now records the current session `43ccf853` `xrefs_to 0x0062dde8` proof tying the callback vtable to the single installer write at `0x0058b567`; it remains support data with blank formal C++.
- `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` and `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` are already stronger support pages; do not change their owner/no-owner model for this child. They remain evidence for prompt label semantics.
- `auto-generated/NexusTK/login/TerminalPane.cpp` still shows UID0001JD as an empty emitter marker and should refresh after target/support docs validate in a later implementation callback.
- Live IDA still names the function `sub_58B620`; no IDA DB rename is required for report-only work.

## Ranked Ownership Analysis

| Rank | Candidate | Decision |
| --- | --- | --- |
| 1 | [UID:0000OI] `TerminalPane` file / `NexusTK/login/TerminalPane.cpp` | Accepted owner/emitter. The installer, callback target, object receiver, prompt labels, and TerminalPane source-family docs all converge here. |
| 2 | [UID:0000EG] `TerminalPane` class | Correct class context but not the file-level emitter route; class page should support the method signature and member inventory. |
| 3 | [UID:0000F0] `TimerHandler` / [UID:0000OT] `TimerMgr` | Owns the schedule wrapper callee, not the TerminalPane callback decision method. |
| 4 | [UID:00000D] `Application` | Owns the leave callee `Application::RequestExit`, not the TerminalPane prompt callback. |
| 5 | [UID:0000HE] `AlertPanes` / `VersatileAlertPane` | Owns alert infrastructure and result dispatch, but TerminalPane allocates the callback object and supplies the callback target. |
| 6 | `ReconnectDialog`, shared strings, or pooled-label pages | Rejected for callback ownership; they explain shared labels, not this executable callback body. |
| 7 | No-owner/raw helper | Rejected; typed callback vtable and receiver binding prove a TerminalPane member callback. |

## Source Placement

Place the method body in `NexusTK/login/TerminalPane.cpp` through [UID:0000OI] `TerminalPane`. The exact target is an executable method child and should emit at the by-memory child, while the file/class/aggregate support pages should carry source-shape context. Do not move the method to TimerMgr, Application, FunctionObjects, AlertPanes, ReconnectDialog, or a shared-label source.

## First-Draft C++ Recommendation

Formal target insertion text recommended for UID0001JD:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void TerminalPane::OnReconnectOrLeave(unsigned long decision)
{
    if (decision != 0) {
        m_timerHandler.ScheduleTimer(0, 0, 0, 0);
        return;
    }

    g_pApplication->RequestExit();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes for implementation: `m_timerHandler` is the source-facing name recommended for the embedded `TimerHandler` facet at full-object offset `+0xa4`; the field spelling is inferred and should be documented as such. Do not use the older descriptive helpers `RestartTerminalReconnectFlow` or `StartTerminalReconnectTimer` in target C++. They obscure the now-accepted `TimerHandler::ScheduleTimer` callee. Do not use `int` return type in the formal body; the callback vtable type is `void`, and both callees are source-shaped as void side-effecting APIs.

## Recommended Target Doc Changes

For `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`:

- Set `COMPLETION:89` and `CONFIDENCE:93`.
- Preserve `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, blank optional emitter position, and `Nested:0`.
- Replace the empty formal C++ block with the exact formal block above.
- Change source-facing signature from `int TerminalPane::OnReconnectOrLeave(unsigned long decision)` to `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`.
- Preserve and expand current MCP evidence from session `43ccf853`: health OK, `sub_58B620` size `0x2f`, `0x0058b64f` alignment, successor `sub_58B650`, zero direct code xrefs, one data xref at `0x0058b56d`, two callees only, byte sequence, and installer sequence at `0x0058b567/0x0058b56d/0x0058b574/0x0058b57b/0x0058b5ac/0x0058b5b1`.
- Add the signature correction rationale: decorated callback vtable is `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`; raw `int` comes from Hex-Rays return propagation through callee EAX and is not the source callback type.
- Add rejected alternatives: no free/global helper, no TimerMgr/Application/AlertPanes owner transfer, no raw `sub_58B620` source name, no synthetic reconnect helper when `TimerHandler::ScheduleTimer` is accepted, no pooled-label/global owner, and no aggregate parent C++ duplication.
- Update score rationale: higher than current because all in-scope blockers are now resolved or narrowed; below final-audit confidence because final original method spelling and `m_timerHandler` field spelling remain inferred.

## Recommended Support Doc Changes

Edit only if supervisor sends an implementation callback and current text lacks same-or-greater detail:

| Support doc | Recommendation |
| --- | --- |
| `by-class/TerminalPane.md` | Change the class-shape sketch and method inventory return type from `int OnReconnectOrLeave(unsigned long decision)` to `void OnReconnectOrLeave(unsigned long decision)`; add that `+0xa4` is the embedded timer-handler facet used by the reconnect branch. |
| `by-file/TerminalPane.md` | Add a concise current-session note that UID0001JD is now first-draft C++ ready and that the callback type resolves to `void (__thiscall TerminalPane::*)(unsigned long)`. Preserve the login source-file route. |
| `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` | Sync the child row/source-quality findings to the `void` callback signature, current MCP session `43ccf853`, and child-first C++ readiness; keep the aggregate formal C++ blank. |
| `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` | If edited, add current `xrefs_to 0x0062dde8` proof and keep it as support data/no direct method body. |
| `by-memory/0x00622f1c-0x00622f28.SharedLeaveWideString.md` and `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` | Read/check only unless stale TerminalPane callback signature wording appears; do not change no-owner/two-emitter literal policy. |
| `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` and `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md` | Read/check only; they already provide accepted callee names. |

## IDA Rename / Type / Comment Recommendations

No IDA database edits are requested in this report-first pass. If a future IDA cleanup pass is authorized, safe source-facing comments would be:

- Rename/comment `sub_58B620` as `TerminalPane_OnReconnectOrLeave`.
- Apply or comment type `void (__thiscall TerminalPane::*)(unsigned long)` for the callback target.
- Comment `0x0058b56d` as the `PlainMemberFunctionObject` target store and `0x0062dde8` as the typed callback vtable.

Do not rename or retype `off_622F28`/`off_622F1C` as unique TerminalPane globals; those are pooled label literals with shared source-use emitters.

## Positive Evidence Summary

- Current MCP session `43ccf853` is healthy and current.
- Exact function range, bytes, predecessor/successor padding, and successor function are confirmed.
- The callback has no code callers and exactly one data xref from the TerminalPane installer at `0x0058b56d`.
- The installer writes a decorated `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable, target pointer, zero adjustor, and receiver pointer.
- Current decompile/disassembly matches the intended source behavior: nonzero decision schedules the TerminalPane timer facet at `this+0xa4`; zero decision calls `Application::RequestExit`.
- Existing support docs now provide accepted names for `TimerHandler::ScheduleTimer` and `Application::RequestExit`.
- The alert-callback research and label order support decision semantics: `Reconnect` is the nonzero/primary route, `Leave` is the zero/secondary route.

## Negative Evidence Summary

- No ordinary code callers to `0x0058b620`.
- No second callback-data xref or alternate installer found.
- No split or merge is supported at `0x0058b64f`; it is padding and `0x0058b650` starts the successor.
- No reason to keep raw `int` source signature after the current decorated vtable type was rechecked.
- No evidence supports a TerminalPane-local `RestartTerminalReconnectFlow` helper; the callee is the accepted generic `TimerHandler::ScheduleTimer` wrapper.
- No evidence supports moving ownership to TimerMgr, Application, AlertPanes, FunctionObjects, ReconnectDialog, or the shared string pages.
- No manual coverage/tracker edit is authorized during report-only work.

## Final Recommendation

Implement UID0001JD as a small exact TerminalPane method child with formal first-draft C++. The target should move from empty-marker status to `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`, preserving TerminalPane ownership and using the accepted callee names. Support docs should be synchronized mainly to correct the callback return type and record the current session evidence; aggregate C++ remains blank.

## Executive Recommendation

Score update: `COMPLETION:89`, `CONFIDENCE:93`. Preserve `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, and blank optional emitter position. Insert the formal first-draft C++ block. Route source placement through `NexusTK/login/TerminalPane.cpp`. Do not create split child pages, do not add aggregate formal C++, and do not fabricate a separate reconnect helper/global.

## Score And Metadata Recommendation

```yaml
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:0000OI
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000OI
EMITTER_POSITION_OPTIONAL:
```

Rationale: completion improves because the report resolves the method signature, source-facing callee names, callback object type, receiver adjustment, decision parameter semantics, source placement, and C++ readiness. Confidence improves because current IDA and support docs agree on all material behavior. It remains below 95 because the exact original method name and `m_timerHandler` field spelling are reconstructed rather than source-proven.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Score/C++ impact |
| --- | --- | --- |
| Is the method `int` or `void`? | Current IDB vtable name is decorated as `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>`, and the generic invoke thunk preserves caller arguments. Raw `int` is only Hex-Rays return propagation. | Use `void` in C++; raise confidence. |
| What does `decision` mean? | B002 alert research plus TerminalPane prompt order show nonzero/primary is `Reconnect`, zero/secondary is `Leave`. | Use a neutral parameter name `decision`; no enum needed yet. |
| What is the reconnect helper name? | Current callee support identifies `0x005975e0` as `TimerHandler::ScheduleTimer`; do not invent a TerminalPane helper. | C++ uses `m_timerHandler.ScheduleTimer(0,0,0,0)`. |
| What is the leave helper name? | Current support identifies `0x00464e40` as `Application::RequestExit()`. | C++ uses `g_pApplication->RequestExit()`. |
| What is the callback object source shape? | Current installer writes the typed `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable, target, adjustor zero, and receiver. | Supports member method body and `void` signature. |
| What is the exact timer field name? | IDA proves full-object `+0xa4` timer facet; source spelling is inferred as `m_timerHandler`. | Does not block first-draft C++; keep field-name caveat. |
| Generated output freshness? | Scoped validator command `000000007950` refreshed `auto-generated/NexusTK/login/TerminalPane.cpp` at `2026-07-08T15:27:11-04:00`; UID0001JD still emits the accepted `void` body. | Implementation verified generated freshness; no manual generated edit. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned coverage or tracker text was required during this implementation callback. Scoped validators updated their normal generated/projection outputs; I did not manually edit `by-memory/-coverage-report.md`, `auto-generated/-ag-research-tracker.md`, any generated coverage artifact, or any supervisor-owned tracker.

## Follow-Up Actions

Implementation callback actions are complete. Remaining action is supervisor execute review. Do not run `execute_report` or lifecycle/archive commands from this report; supervisor owns the next execute/lifecycle step.

## Lease And Forbidden-Action Confirmation

Lease use:

- Initial leases were acquired for `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`, `by-class/TerminalPane.md`, `by-file/TerminalPane.md`, and `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` at `2026-07-07T19:50:34Z`; those leases expired before validation after the interrupted/resumed work.
- The same four scoped leases were reacquired immediately before the validator batch; the release command succeeded for all four files immediately after validation.
- Resume support-sync lease was acquired as `B005` for `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`, validator `000000007950` was run while it was active, and the release command succeeded immediately afterward.
- Post-release `current_leases.md` scan found no B005 rows and no TerminalPane/UID0001JD rows.

Forbidden actions not run/performed: no `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry/report move, manual report move, manual generated-file edit, coverage edit, supervisor-ledger edit, validator-state edit, queue/lock edit, unrelated by-* edit, or subagent use.

## Validator Results

Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` for the five edited by-* docs only:

| Command ID | Timestamp | File | Exit/result | Warnings / notes | Generated refresh |
| --- | --- | --- | --- | --- | --- |
| `000000007940` | `2026-07-07T15:59:38-04:00` | `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md` | exit `0`, `ok: 1`, `completion_update: 1`, `confidence_update: 1`, `autogen_registry_update: 2` | `missing_ref_uid` for `0003G3` and `0003G4` because those UID references are not present in `validator.ini`; projected stats update noted. | `generated_refresh: deferred`, command id `000000007940`. |
| `000000007941` | `2026-07-07T15:59:45-04:00` | `by-class/TerminalPane.md` | exit `0`, `ok: 1` | `missing_ref_uid` for `0003DO` and `0003GS` because those UID references are not present in `validator.ini`; projected stats update noted. | `generated_refresh: deferred`, command id `000000007941`. |
| `000000007942` | `2026-07-07T15:59:55-04:00` | `by-file/TerminalPane.md` | exit `0`, `ok: 1`, `stats_row_update: 2` | `missing_ref_uid` for `0003DP`, `0003G7`, `0003B1`, `0003G3`, and `0003G4` because those UID references are not present in `validator.ini`; projected stats update noted. | `generated_refresh: deferred`, command id `000000007942`. |
| `000000007943` | `2026-07-07T16:00:03-04:00` | `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md` | exit `0`, `ok: 1` | `missing_ref_uid` for `0003B1` and `0003DP` because those UID references are not present in `validator.ini`; projected stats update noted. | `generated_refresh: deferred`, command id `000000007943`. |
| `000000007950` | `2026-07-08T15:27:11-04:00` | `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` | exit `0`, `ok: 1` | `missing_ref_uid` for `0003DU` because that UID reference is not present in `validator.ini`; `stats_incremental_noop` for `0003GT`; projected stats update noted. | `generated_refresh: deferred`, command id `000000007950`. |

Generated freshness after validation: `auto-generated/NexusTK/login/TerminalPane.cpp` header now reports `validator-command-id: 000000007950`, `validator-refreshed-at: 2026-07-08T15:27:11-04:00`, `validator-refresh-source: deferred-generated-refresh`, and UID0001JD still emits the accepted `void TerminalPane::OnReconnectOrLeave(unsigned long decision)` body.

## Changed Files

Implementation callback changed:

- `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`
- `by-class/TerminalPane.md`
- `by-file/TerminalPane.md`
- `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`
- `tools/leaser/Agents/Agent-B005/research/0001JD-TerminalPaneReconnectLeaveCallback-source-quality.md`

Scoped validator generated/projected refresh:

- `auto-generated/NexusTK/login/TerminalPane.cpp` was refreshed by validator command `000000007950`; this was not manually edited.
- `project-level/-auto-completion-stats.md` projected path completion was updated by validator command `000000007950`; this was not manually edited.

No coverage reports, supervisor ledgers, validator state files, queues, locks, lifecycle headers/footers, archives, manual report moves, or `-coverage-report.md` files were edited by B005.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0001JD-01 | Target range is exactly `0x0058b620-0x0058b64f`; `0x0058b64f` is padding and `0x0058b650` is successor. | High | MCP `lookup_funcs`, `get_bytes`, disasm. | Target Range/IDA Evidence; aggregate split row. | applied | Target IDA MCP Evidence now records session `43ccf853`, exact `sub_58B620` size `0x2f`, `0x0058b64f` alignment, and successor `sub_58B650`; aggregate covered-ranges row carries same boundary proof. Validator `000000007940` and `000000007943` passed. |
| C-0001JD-02 | Callback has zero code callers and one data xref at `0x0058b56d`. | High | MCP `xrefs_to` and `xref_query`. | Target IDA Evidence; caller inventory. | applied | Target IDA MCP Evidence states `xref_query ... to code` = `0`, `xref_query ... to data` = `1`, and `xrefs_to` store at `0x0058b56d`; class/file/aggregate support pages carry the scoped xref summary. Validators `000000007940`-`000000007943` passed. |
| C-0001JD-03 | Installer writes typed `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable at `0x0058b567`. | High | MCP disasm/decompile `0x0058b470`, `entity_query`, `xrefs_to 0x0062dde8`. | Target Behavior/Callback Object; support data page. | applied | Target Behavior/IDA Evidence, class Live IDA Evidence, file Evidence Notes, aggregate IDA MCP Evidence, and `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md` now record the typed callback-object installation. The support data page specifically records session `43ccf853` `xrefs_to 0x0062dde8` = one data ref from `0x0058b567`; validator `000000007950` passed. |
| C-0001JD-04 | Source-facing signature should be `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`, not `int`. | High | Decorated vtable type plus invoke thunk behavior; raw EAX return artifact explained. | Target Status/C++; class/file/aggregate support. | applied | Target metadata/body/formal C++ now use `void`; class sketch/method row, file map/evidence, and aggregate child row/source-quality findings are synchronized. Generated `TerminalPane.cpp` now emits `void TerminalPane::OnReconnectOrLeave(unsigned long decision)`. |
| C-0001JD-05 | Nonzero decision is reconnect and zero decision is leave. | High | Target branch behavior plus B002 alert-callback result semantics and label order `Reconnect`/`Leave`. | Target Behavior; support docs. | applied | Target Behavior Notes and formal C++ implement nonzero reconnect scheduling and zero leave exit; file/aggregate support rows carry the same branch mapping. |
| C-0001JD-06 | Reconnect branch calls accepted `TimerHandler::ScheduleTimer` through TerminalPane `+0xa4`. | High | MCP disasm/decompile target; timer wrapper support doc. | Target Behavior/C++; class field note. | applied | Target formal C++ calls `m_timerHandler.ScheduleTimer(0, 0, 0, 0)` and notes `+0xa4`; class sketch adds `TimerHandler m_timerHandler` as a documentation-only facet; file/aggregate support notes preserve `TimerHandler::ScheduleTimer`. |
| C-0001JD-07 | Leave branch calls accepted `Application::RequestExit` through global Application pointer at `0x0067ab1c`. | High | MCP disasm/decompile target; ApplicationRequestExit support doc. | Target Behavior/C++; cross refs. | applied | Target formal C++ calls `g_pApplication->RequestExit()` and target Behavior Notes record global pointer `0x0067ab1c`; file/aggregate support notes preserve accepted `Application::RequestExit`. |
| C-0001JD-08 | Formal first-draft C++ should replace the empty marker. | Medium-high | All blockers resolved except original method/field spelling; generated still empty. | Target formal C++ block. | applied | Target formal block now contains the accepted `void` body; validator `000000007940` recorded registry update `blank -> block`; generated `TerminalPane.cpp` most recently refreshed by `000000007950` and still contains the UID0001JD body. |
| C-0001JD-09 | Owner/emitter remains TerminalPane file [UID:0000OI]. | High | Installer, receiver, prompt construction, file/class support docs. | Target metadata and Source Placement. | applied | Target preserved `CANONICAL_OWNER:0000OI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OI`, blank optional emitter position, and `Nested:0`; file/class/aggregate support pages preserve `login/TerminalPane.cpp` ownership. |
| C-0001JD-10 | Support pages need only scoped synchronization; shared string pages remain no-owner/two-emitter and Application/TimerHandler docs remain callee support. | High | Current support docs and old-report search. | Recommended Support Doc Changes. | applied | Edited scoped support docs `by-class/TerminalPane.md`, `by-file/TerminalPane.md`, `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`, and `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`; shared string pages, TimerHandler, and Application pages were read/check already-present or callee support and left unchanged. |

## Implementation Tracking Checklist

Every accepted ledger row is now `applied` with proof or already-present support detail recorded in the ledger.

- [x] C-0001JD-01 applied with proof in target and aggregate boundary text.
- [x] C-0001JD-02 applied with proof in target xref/caller inventory.
- [x] C-0001JD-03 applied with proof in target callback-object section and support data page session `43ccf853` `xrefs_to 0x0062dde8` detail.
- [x] C-0001JD-04 applied with proof in target and class/file/aggregate support signature wording.
- [x] C-0001JD-05 applied with proof in target behavior notes and support rows.
- [x] C-0001JD-06 applied with proof in target C++/behavior and class field caveat.
- [x] C-0001JD-07 applied with proof in target C++/behavior.
- [x] C-0001JD-08 applied with exact formal C++ block proof and generated `TerminalPane.cpp` refresh.
- [x] C-0001JD-09 applied with proof preserving `0000OI`.
- [x] C-0001JD-10 applied for scoped support docs; shared string, TimerHandler, and Application support docs are already-present or callee/no-owner support and left unchanged.
- [x] Scoped validators run only for changed by-* docs after implementation callback: `000000007940`, `000000007941`, `000000007942`, `000000007943`, and `000000007950`.
- [x] Leases acquired for the scoped edit set, expired before validation, reacquired/released for validation, and the resume support-page lease was released immediately after validator `000000007950`.
- [x] No `execute_report`, lifecycle/archive command, manual generated edit, coverage edit, supervisor-ledger edit, validator-state edit, queue/lock edit, or manual report move.

## Confidence

Recommendation confidence: high for implementing a child method body and `void` signature. Score confidence: high for `89/93`, with a deliberate cap below final-audit confidence because exact original spelling of `OnReconnectOrLeave` and `m_timerHandler` is inferred. Remaining uncertainty does not block first-draft C++ because it is restricted to source names, while behavior, callback type, range, owner, and callee routes are current-session IDA-backed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000007961","destination_path":"executed-b-agent-research/B005/0001JD-TerminalPaneReconnectLeaveCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001JD-TerminalPaneReconnectLeaveCallback-source-quality.md","timestamp":"2026-07-08T15:45:53-04:00","uid":"0001JD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
