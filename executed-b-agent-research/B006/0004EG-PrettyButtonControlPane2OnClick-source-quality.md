** TARGET-REPORT-UID:0004EG **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004EG PrettyButtonControlPane2 OnClick Source-Quality Report

## Finalized Report / Current Recommendation

[UID:0004EG] `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md` should move from a blank-emitter click/notification child to an emitting `PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)`-style virtual handler through [UID:0000AS] `PrettyButtonControlPane2`.

Fresh MCP evidence in live session `9fb70afc` confirms `sub_54BB50` is a modeled `0x39` / decimal 57 byte (Verified with `int_convert.py`) function with one data xref from the class2 tertiary vtable slot `0x00622418`. The body accepts three stack arguments, handles only action values `0` and `1`, schedules timer/action id `1` after `0x96` / decimal 150 ms (Verified with `int_convert.py`) through the inherited `TimerHandler` wrapper `sub_5975E0`, reads the adjusted callback field at `[this+0x84]`, and invokes virtual slot `+0x0c` with no payload arguments when the field is non-null.

Recommended target metadata: raise UID0004EG from `84/88` to `88/91`, keep `CANONICAL_OWNER:0000AS`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AS`, and keep `EMITTER_POSITION_OPTIONAL:` blank unless the supervisor wants explicit method ordering. Recommended formal C++:

```cpp
bool PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)
{
    if (action <= 1) {
        m_timerHandler.ScheduleTimer(1, 150, 0, 0);
        if (m_callback != NULL)
            m_callback->Invoke();
    }

    return true;
}
```

`m_timerHandler`, `m_callback`, `ScheduleTimer`, and `Invoke` are source-facing inferred names/types, not recovered original symbols. They are the best current source-quality names because accepted support docs already route class2 callback storage through `FunctionObject0 *` at complete-object offset `+0x128`, and this target is reached through the tertiary `+0xa4` view; adjusted field `+0x84` plus view offset `+0xa4` equals the complete-object callback field `+0x128`.

## Supporting Research

Assignment context:

- Agent: B006.
- Assignment ID: `B006-report-0004EG-PrettyButtonControlPane2OnClick-20260703`.
- Target UID/path: [UID:0004EG] `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md`.
- Report path: `tools/leaser/Agents/Agent-B006/research/0004EG-PrettyButtonControlPane2OnClick-source-quality.md`.
- Mode: report-only research. No target/support by-* docs were edited.

Operational context:

- Initial MCP was unavailable earlier and B006 paused. Supervisor later restored and verified MCP; this report uses the restored live endpoint and does not rely on the fallback-only paused state.
- Current MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Current MCP session: `9fb70afc`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker pid `5524`.
- `server_health` status was `ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Source-family context:

- [UID:0001F9] is a reviewed non-emitting split/index over the PrettyButtonControlPane and PrettyButtonControlPane2 executable island. Exact child pages carry source-bearing method ranges.
- [UID:0000AS] is the direct class owner for the class2 executable children. [UID:0000MP] is the file route, `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- [UID:0004ED] was accepted as `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` and resolves the class2 callback field at complete-object `+0x128`.
- [UID:0001WQ], [UID:00005L], and [UID:0000JO] define/support `FunctionObject0` as the zero-argument callback base with virtual `Invoke()` at slot `+0x0c` and virtual destructor/delete behavior at slot `+0x00`.

## Target

- Target UID: `0004EG`.
- Target path: `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md`.
- Current title/range: `0x0054bb50-0x0054bb89 PrettyButtonControlPane2 OnClick`.
- Current owner: [UID:0000AS] `PrettyButtonControlPane2`.
- Current source route: [UID:0004EG] -> [UID:0000AS] -> [UID:0000MP] `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Current reconstructable state: `RECONSTRUCTABLE:TRUE`.
- Queue source in assignment: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, assignment-time row `84/88`, combined `86.0`, reports `0`.

## Current Target State

The target currently records:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `84` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `0000AS` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | blank |

Existing target prose correctly says MCP confirms function `0x0054bb50` size `0x39`, animation scheduling through `sub_5975E0`, parent/notification state, and vtable click slot `0x00622418`. The stale blocker is the C++ policy: formal C++ remains blank until click-action names and parent notification API are accepted.

Current evidence resolves that blocker enough for first-draft C++. The handler does not call an unknown parent notification API directly. It invokes the accepted owned `FunctionObject0 *` callback field through virtual slot `+0x0c`. The action values remain numerically named because no enum/original event names are recovered, but the exact behavior for `0` and `1` is clear.

## Heuristic / Inference Reanalysis And Validation

### Function Identity

`sub_54BB50` is a modeled `.text` function at `0x0054bb50`, size `0x39` / decimal 57 bytes (Verified with `int_convert.py`). It has a normal prologue/epilogue, three stack arguments, `retn 0x0c`, five basic blocks, and one data xref from `0x00622418`.

The target is not padding, not a raw helper, not a compiler adjustor thunk, and not scalar deleting destructor glue. The immediately preceding bytes `0x0054bb48-0x0054bb50` are eight `0xcc` bytes, and the successor at `0x0054bb89` starts an adjustor thunk. The target owns exactly the modeled click/notification virtual body between those boundaries.

### Action And Timer Semantics

The first argument is compared against `0` and `1`: the body reaches the action path when `action == 0` or `action == 1`, and returns true without side effects for other values. This is source-level click/action filtering, not an opaque parent dispatch.

The action path calls `sub_5975E0(this, 1, 150, 0, 0)`. Accepted timer docs identify `sub_5975E0` as the generic `TimerHandler` schedule wrapper. Because UID0004EG is reached through the tertiary `+0xa4` view, the `this` pointer seen by the wrapper is the embedded timer-handler subobject. The best first-draft source form is `m_timerHandler.ScheduleTimer(1, 150, 0, 0)`, while preserving that exact original method/field spellings remain inferred.

The timer delay literal is `0x96` / decimal 150 (Verified with `int_convert.py`). The event/action id is `1`. The two extra payload arguments are both `0`.

### Callback Invocation Semantics

The body reads `[esi+0x84]` after saving the adjusted receiver in `esi`. The class2 tertiary vtable view is at complete-object offset `+0xa4`; `0xa4 + 0x84 = 0x128`, matching the accepted class2 callback field from UID0004ED. This resolves the apparent offset mismatch between `OnClick` and `SetCallback`.

If the callback pointer is non-null, the body loads its vtable and calls slot `+0x0c` with no pushed payload arguments. FunctionObject support docs define `FunctionObject0::Invoke()` as the zero-argument virtual callback at that slot family. The source-quality call should be `m_callback->Invoke()`, not raw `(*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(v5)`.

### Return Type

IDA reports `char __thiscall(... unsigned int, int, int)` because the body returns `al = 1`. Source-facing C++ should use `bool`, not `char`, because the routine is a virtual input/click handler that returns success/handled state. The exact ABI effect remains a one-byte true result.

### Method And Parameter Names

`OnClick` is accepted by the current target name, class method inventory, file split inventory, and vtable slot context. No stronger original symbol was recovered. `action`, `x`, and `y` are first-draft parameter names. `action` is behaviorally used; the other two stack arguments are currently unused. Keep them in the signature because the function returns with `retn 0x0c`, and sibling class1 `sub_54B880` has the same prototype shape.

## Evidence Standards Used

- Current live IDA MCP evidence is ground truth for function boundaries, disassembly, decompilation, xrefs, bytes, callee lists, basic block counts, and active IDB/session state.
- Current by-* docs are durable project context for ownership, source route, accepted support names, and prior implementation decisions.
- Accepted executed B reports for adjacent PrettyButton methods are used as precedent only after matching their facts against current docs and current MCP.
- Generated tracker/coverage data is read-only context only. It was not edited or treated as proof of behavior.
- Inferred source names are explicitly labeled. Exact behavior and numeric literals are separated from naming/source-shape inference.

## Evidence Checked

Workflow and assignment inputs:

- Read `tools/leaser/Agents/Agent-B006/goal.md`.
- Read project skill `E:\NTK\GhidraBridge\.codex\skills\ntk-b-agent-workflow\SKILL.md`.
- Read `references/b-agent-research-and-implementation-workflow.md`, `references/score-blocker-audit-standard.md`, and MCP incident playbook when MCP was initially unavailable.
- Read `by-structure.md`, especially IDA MCP output discipline, ownership/emitter rules, and first-draft C++ gate.

Target/support docs:

- Target [UID:0004EG] `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md`.
- Class owner [UID:0000AS] `by-class/PrettyButtonControlPane2.md`.
- File route [UID:0000MP] `by-file/PrettyButtonControlPane.md`.
- Parent split/index [UID:0001F9] `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`.
- Vtable data [UID:0002UX] `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`.
- Class1 analogue [UID:0004E9] `by-memory/0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick.md`.
- FunctionObject support [UID:00005L] `by-class/FunctionObject0.md`, [UID:0001WQ] `by-type/by-template/FunctionObjectTemplates.md`, and [UID:0000JO] `by-file/FunctionObjects.md`.

Old report/search gate:

- Searched active/executed/archived reports and docs with terms: `UID:0004EG`, `0004EG`, `0x0054bb50`, `0054bb50`, `PrettyButtonControlPane2OnClick`, `PrettyButtonControlPane2 OnClick`, `sub_54BB50`, `0x00622418`, `sub_5975E0`, `0x005975e0`, `PrettyButtonControlPane2`, `0000AS`, and `0000MP`.
- Relevant accepted reports opened/read as support: B013 `0004ED-PrettyButtonControlPane2SetCallback-source-quality.md`, B011 `0004EC-PrettyButtonControlPane2StateByteVirtualForwarder-source-quality.md`, and B015 `0004E6-PrettyButtonControlPaneSetCallback-source-quality.md`.
- No prior standalone UID0004EG report was found.

Current MCP calls:

- `initialize` and `tools/list`: confirmed active JSON-RPC schema requiring `database` argument on analysis calls.
- `idb_list`: active session `9fb70afc`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker, active, not analyzing.
- `server_health`: status `ok`, auto-analysis/Hex-Rays/string cache ready.
- `lookup_funcs` on `0x0054bb50`: `sub_54BB50`, size `0x39`.
- `lookup_funcs` on `0x0054b880`: `sub_54B880`, size `0x39`.
- `lookup_funcs` on `0x0054ba00`: not a function, matching accepted class2 callback setter raw-span evidence.
- `lookup_funcs` on `0x0054ba30`, `0x0054baa0`, and `0x005975e0`: modeled functions `sub_54BA30` size `0x62`, `sub_54BAA0` size `0xa8`, and `sub_5975E0` size `0x1f`.
- `analyze_function 0x0054bb50 include_asm=true`: prototype `char __thiscall(_DWORD *this, unsigned int, int, int)`, size `57`, decompile and assembly as summarized here, callee `sub_5975E0`, no code callers, data xref from `0x00622418`, five blocks, complexity 4.
- `decompile 0x0054bb50`: action filter `a2 <= 1`, call `sub_5975E0(this, 1, 150, 0, 0)`, adjusted callback read `this[33]`, virtual slot `+0x0c` invoke, return `1`.
- `disasm 0x0054bb50 max_instructions=80 include_total=true`: 23 total instructions, `retn 0x0c`.
- `analyze_function 0x0054b880 include_asm=true`: class1 analogue has same size/body shape, reads `[esi+0x80]`, vtable data xref from `0x00622374`.
- `xref_query` and `xrefs_to`: `0x0054bb50` has exactly one xref, data from `0x00622418`; `0x00622418` has no xrefs to the slot cell itself.
- `get_bytes 0x0054bb48 size 80`: eight `0xcc` bytes before the target; target body bytes through `c2 0c 00`; following bytes begin adjustor thunk at `0x0054bb89`.
- `insn_query 0x0054bb48-0x0054bb90`: addresses include padding at `0x54bb48`, target body `0x54bb50-0x54bb86`, and successor instructions at `0x54bb89`/`0x54bb8f`; no unbounded scan was used.
- `analyze_component` on `0x0054bb50`, `0x0054b880`, and `0x005975e0`: class2 and class1 click handlers both call `sub_5975E0`; `sub_5975E0` calls `sub_597910`; no shared globals or strings in that narrow component.
- `int_convert`: `0x39` = decimal 57, `0x96` = decimal 150, `0x84` = decimal 132, `0xa4` = decimal 164, `0x128` = decimal 296, `0x0c` = decimal 12 (Verified with `int_convert.py` / MCP `int_convert`).

Failed/stale MCP attempts during current pass:

- Earlier, before supervisor restore, MCP connection failed and B006 paused. Those failures are operational history only and not used as target evidence.
- During the restored pass, stale parameter forms `xrefs_to addr`, `get_bytes addr/size`, and `get_int addr/size` returned schema errors. They were immediately retried with schema-current forms where relevant. The successful schema-current xref and bytes calls above are the evidence used.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0004EG is a modeled source-authored class2 click handler, not padding/thunk/glue. | MCP `lookup_funcs`, `analyze_function`, `disasm`, padding bytes, vtable data xref. | Target metadata/status/evidence. | incorporate | applied in target; validator `000000005005` exit 0 ok 1 |
| Direct owner remains [UID:0000AS] `PrettyButtonControlPane2`. | Current target/class docs, class2 vtable slot `0x00622418`, parent split inventory. | Target metadata and support docs. | incorporate | applied in target, class support, file support, parent split/index support, and vtable text |
| Emitter route should become [UID:0000AS], surfacing to [UID:0000MP]. | Owner route clear, target reconstructable true, current average above C++ gate after recommended score, class/file route already valid. | Target `EMITTER_UIDS`, class/file support notes. | incorporate | target `EMITTER_UIDS:0000AS` applied; file-root source-output note applied; generated output refreshed |
| Body handles only action values `0` and `1`, schedules timer/action id `1` after 150 ms, invokes zero-argument callback when present, and always returns true. | MCP decompile/disasm; `int_convert` for 150 ms and function size. | Target evidence and formal C++. | incorporate | applied in target and generated C++; validators `000000005005` and `000000005007` |
| Adjusted field `[this+0x84]` is the accepted class2 callback field at complete-object `+0x128`. | Tertiary view offset `+0xa4`; accepted UID0004ED report/docs; `0xa4 + 0x84 = 0x128`. | Target ownership/C++ policy; class support note. | incorporate | applied in target/class evidence |
| Callback type should be `FunctionObject0 *` and invocation should be `m_callback->Invoke()`. | FunctionObject0/template docs; accepted UID0004ED setter; virtual slot `+0x0c` zero-arg call. | Target formal C++ and evidence. | incorporate | applied in target/class; generated body calls `m_callback->Invoke()` |
| Timer scheduling should be represented as timer-handler scheduling, not direct feature-dialog notification. | MCP call to `sub_5975E0`; TimerHandler wrapper docs; no parent notify callee in body. | Target C++ policy; support docs. | incorporate | applied in target/class/file/parent support |
| Source return type should be `bool`/true instead of decompiler-shaped `char`. | `mov al,1`; virtual handler shape; `retn 0x0c`; no other return values. | Target formal C++. | incorporate | applied in target/generated C++ |
| Negative evidence: no code callers; only one data xref from vtable slot; no xrefs to the vtable cell itself; exact original enum/parameter/member spellings not recovered. | MCP xref calls and support docs. | Target score rationale and caveats. | incorporate | applied in target evidence/score rationale |
| Do not change UID0001F9 parent metadata, FunctionObjects docs, vtable metadata, or class1 analogue under this report unless supervisor callback explicitly expands scope. | Scope and current docs. | Implementation checklist. | not-applicable | FunctionObjects, TimerHandler, class1, UID0001F9 metadata, and vtable metadata left unchanged; vtable received text-only slot sync |

## Positive Evidence Summary

- MCP confirms UID0004EG is an exact modeled function at `0x0054bb50`, size `0x39`, and not a raw/non-modeled span.
- The function has one direct data xref from `0x00622418`, matching the documented `PrettyButtonControlPane2` tertiary click/notification vtable slot.
- The body is compact and source-shaped: action filter, timer schedule, callback null-check, zero-argument callback invoke, true return.
- The class1 analogue [UID:0004E9] has the same body shape and size, differing only in adjusted callback offset (`+0x80` instead of `+0x84`) and vtable slot (`0x00622374` instead of `0x00622418`).
- Accepted UID0004ED evidence resolves the class2 callback field and `FunctionObject0 *` type, clearing the target's "parent notification API/click-action names" blocker enough for first-draft C++.
- FunctionObjects docs already define `FunctionObject0::Invoke()` as the zero-argument callback dispatch slot, matching the target's virtual slot `+0x0c` call with no payload arguments.

## Negative Evidence Summary

- No code callers are reported for `0x0054bb50`; reachability is vtable/data based.
- `xrefs_to 0x00622418` reports no xrefs to the vtable cell itself; construction/destruction store xrefs target the tertiary vtable base, not the individual click slot cell.
- No recovered original method symbol, enum name for action values `0`/`1`, parameter names, member names, or class declaration was found during this pass.
- The two non-action stack arguments are unused in the body; their semantic names are not recoverable from this target alone.
- `m_timerHandler`, `ScheduleTimer`, `m_callback`, and `Invoke` are source-facing names from accepted support context, not original-symbol proof.
- These negatives cap confidence below final-audit quality but do not justify leaving the target blank/non-emitting.

## Ranked Ownership Analysis

1. [UID:0000AS] `PrettyButtonControlPane2`: accepted.
   Evidence for: current target owner, class2 executable split, class2 vtable slot `0x00622418`, adjusted callback field mapping to accepted class2 `+0x128`, and current class/file docs.
   Evidence against: no code callers and no recovered original class declaration. These cap confidence but do not weaken direct class ownership.
   Decision: keep `CANONICAL_OWNER:0000AS` and set `EMITTER_UIDS:0000AS`.

2. [UID:0000MP] `PrettyButtonControlPane` file root: accepted as source-file route, rejected as direct canonical owner.
   Evidence for: file root owns the two PrettyButton classes under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
   Evidence against: by-structure requires the narrow class owner for a supported class method. Direct file-bucket ownership would bypass [UID:0000AS].
   Decision: retain only as transitive file route.

3. [UID:0000AR] `PrettyButtonControlPane`: rejected for this target.
   Evidence for: class1 analogue [UID:0004E9] has the same handler shape and supports naming.
   Evidence against: UID0004EG is in the class2 address island, has class2 vtable slot `0x00622418`, and reads the class2 adjusted callback offset.
   Decision: use as comparison evidence only.

4. [UID:0000JO] `FunctionObjects` / [UID:00005L] `FunctionObject0`: rejected as owner.
   Evidence for: provides the callback type and invoke-slot semantics.
   Evidence against: UID0004EG is not a FunctionObjects template implementation; it is a PrettyButton method that consumes a callback object.
   Decision: cite as support/type evidence only.

5. TimerHandler/TimerMgr: rejected as owner.
   Evidence for: target schedules through `sub_5975E0`.
   Evidence against: timer wrapper is an inherited dependency called by the PrettyButton click handler, not the source owner of this method.
   Decision: cite as callee/dependency evidence only.

6. CreateUser/NewUser dialog source or no-owner/non-emitting: rejected.
   Evidence for: the broader PrettyButton construction family is used by create-user dialogs, and this target has no code callers.
   Evidence against: vtable reachability, class ownership, source route, and callback/timer behavior are clear. Caller/consumer context does not own reusable styled-button method code.
   Decision: no owner move; no no-owner/non-emitting disposition.

## Source Placement

Recommended source route:

`[UID:0004EG] by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md` -> `[UID:0000AS] by-class/PrettyButtonControlPane2.md` -> `[UID:0000MP] by-file/PrettyButtonControlPane.md` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

Place the method as an ordinary `PrettyButtonControlPane2` virtual click/input handler. It should not be emitted as a FunctionObjects wrapper, TimerHandler helper, vtable data item, feature-dialog method, or parent aggregate code.

## Range / Split / Padding / Reclassification Analysis

No new split or merge is recommended.

| Span | Current disposition | Evidence | Recommendation |
| --- | --- | --- | --- |
| `0x0054bb48-0x0054bb50` | padding | MCP `get_bytes`: eight `0xcc` bytes before target. | Preserve as parent split padding only. |
| `0x0054bb50-0x0054bb89` | [UID:0004EG] modeled click handler | MCP `lookup_funcs` size `0x39`; 23 instructions; data xref from `0x00622418`. | Keep exact child, make it emitting through [UID:0000AS]. |
| `0x0054bb89-0x0054bb94` | [UID:0004EH] secondary adjustor thunk | MCP bytes and existing exact child. | Leave non-emitting compiler ABI thunk unchanged. |

## Function / Child Inventory

| Item | Evidence | Role |
| --- | --- | --- |
| UID0004EG `0x0054bb50-0x0054bb89` | MCP `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`. | Source-authored `PrettyButtonControlPane2::OnClick` style method. |
| UID0004E9 `0x0054b880-0x0054b8b9` | MCP `analyze_function`; current class1 doc. | Class1 analogue, same body shape and timer/callback pattern. |
| UID0004ED `0x0054ba00-0x0054ba24` | Accepted B013 report/current docs. | Class2 callback setter proving complete-object `m_callback` at `+0x128`. |
| UID0001K8 `0x005975e0-0x0059760d` | Current TimerHandler docs and MCP component call. | Generic timer scheduling wrapper dependency. |
| FunctionObject0 support | [UID:00005L], [UID:0001WQ], [UID:0000JO]. | Zero-argument callback base; `Invoke()` source support for slot `+0x0c`. |

## First-Draft C++ Recommendation

UID0004EG is eligible for first-draft formal C++ after supervisor validation:

- `RECONSTRUCTABLE:TRUE`.
- Recommended nonblank `EMITTER_UIDS:0000AS`.
- Recommended score `88/91`, average `89.5`, above the current C++ gate.
- Behavior, direct owner, vtable route, callback type, timer dependency, and range boundaries are supported by current MCP and support docs.

Recommended exact formal C++ for the UID0004EG target:

```cpp
bool PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)
{
    if (action <= 1) {
        m_timerHandler.ScheduleTimer(1, 150, 0, 0);
        if (m_callback != NULL)
            m_callback->Invoke();
    }

    return true;
}
```

Notes for implementation:

- `bool` represents the observed `al = 1` handled/success return.
- `action` is the first stack argument compared against `0` and `1`; keep `x` and `y` only as first-draft unused input-handler parameters until broader class/interface evidence supplies exact names.
- `m_timerHandler` represents the inherited/embedded timer-handler subobject behind the tertiary `+0xa4` view.
- `m_callback` is the accepted class2 callback field at complete-object `+0x128`, reached here as adjusted offset `+0x84`.
- `FunctionObject0::Invoke()` is represented by the virtual slot `+0x0c` call with no payload arguments.
- Do not emit raw decompiler `_DWORD *`, `this[33]`, or function-pointer-call syntax.

## Recommended Target Doc Changes

For `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md` / [UID:0004EG]:

- Change `COMPLETION:84` to `COMPLETION:88`.
- Change `CONFIDENCE:88` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000AS`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:0000AS`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank unless supervisor wants method-order sorting.
- Insert the formal C++ block from `## First-Draft C++ Recommendation`.
- Expand `Evidence` with current MCP session `9fb70afc`, health state, function size, exact decompile/disassembly behavior, one data xref from `0x00622418`, no code callers, bytes/padding, and class1 analogue.
- Replace the C++ policy blocker with a source-ready note: action values `0`/`1` schedule timer id `1` after 150 ms and invoke accepted `FunctionObject0 *m_callback`; exact enum/parameter/member names remain inferred.
- Preserve rejected alternatives: no direct file owner, no FunctionObjects owner, no TimerHandler owner, no CreateUser dialog owner, no parent aggregate emission, no raw decompiler callback invocation, no no-owner/non-emitting disposition.

## Recommended Support Doc Changes

For `by-class/PrettyButtonControlPane2.md`:

- Update the UID0004EG method/child rows from "C++ blank pending notification names" to source-ready `OnClick(unsigned int action, int x, int y)` or equivalent project-preferred click signature.
- Record that UID0004EG uses the accepted callback field at complete-object `+0x128`, reads it as adjusted offset `+0x84` from the tertiary view, invokes `FunctionObject0::Invoke()`, schedules timer id `1` for 150 ms through the inherited timer facet, and returns true.
- Preserve caveats that action enum names and unused coordinate/parameter names are inferred.

For `by-file/PrettyButtonControlPane.md`:

- Update the executable split inventory/source-output note so UID0004EG emits one `PrettyButtonControlPane2::OnClick(...)` body through [UID:0000AS].
- Add concise evidence that current MCP resolved the click-action/callback blocker: `sub_54BB50` size `0x39`, slot `0x00622418`, action values `0`/`1`, timer call `sub_5975E0(...,1,150,0,0)`, adjusted callback field `[this+0x84]` -> complete `+0x128`, and zero-argument `FunctionObject0::Invoke()`.
- No file metadata change is required unless supervisor wants a broader support-score bump after sibling UID0004EE/UID0004EF are resolved.

For `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`:

- Update the UID0004EG split row from generic "Click / notification" to source-ready class2 click handler that schedules timer id `1`, invokes the accepted callback, and emits through UID0000AS.
- Keep parent `RECONSTRUCTABLE:FALSE`, blank emitter, and blank aggregate C++ unchanged.

For `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`:

- Optional text-only sync if supervisor wants vtable support updated: keep slot `0x00622418 -> UID0004EG`, but note UID0004EG is now source-ready/emitting through class2; no metadata change.

For FunctionObjects docs and TimerHandler docs:

- No edit recommended. They already provide support evidence for zero-argument callback dispatch and generic timer scheduling.

For class1 analogue [UID:0004E9] / [UID:0000AR]:

- No edit recommended in this UID0004EG callback. Use it as comparison evidence only unless supervisor separately assigns class1 click handler resolution.

## Score And Metadata Recommendation

Target UID0004EG:

- `COMPLETION`: `84 -> 88`.
- `CONFIDENCE`: `88 -> 91`.
- `CANONICAL_OWNER`: keep `0000AS`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: blank -> `0000AS`.
- `EMITTER_POSITION_OPTIONAL`: keep blank.

Rationale:

- Completion rises because the named click-action/callback blockers are resolved into implementation-ready behavior, support type names, ownership route, and formal C++.
- Confidence rises because current MCP confirms exact function size, body, vtable xref, bytes, class1 analogue, and timer/callback behavior.
- Score should not exceed low 90s because exact original action enum names, parameter names, member names, and final class declaration are still inferred; class2 sibling paint/visual-state methods also remain separate source-quality work.
- The target is now above the formal C++ gate once emitter UID0000AS is added: `(88 + 91) / 2 = 89.5`.

Support score recommendations:

- `by-class/PrettyButtonControlPane2.md`: optional `87/89 -> 88/90` only if supervisor wants support score movement for the resolved click/callback blocker. Conservative recommendation is no required metadata change because sibling UID0004EE and UID0004EF remain unresolved.
- `by-file/PrettyButtonControlPane.md`: no required metadata change; the file is already `88/90` and still has sibling blockers.
- UID0001F9 parent, UID0002UX vtable, FunctionObjects, and TimerHandler support: no score/metadata change.

## Open Questions With Attempted Resolution

- Are click action values `0` and `1` named mouse-down/mouse-up states, press/release states, or generic action ids? Attempted resolution: target body proves only the numeric filter and behavior. No original enum names or caller-side names were recovered in this pass. Score/C++ impact: keep numeric `action <= 1` in first-draft C++ and cap confidence; do not leave C++ blank.
- Is the parent notification API still unknown? Resolved for this target: there is no direct parent notification call in the body. The body invokes the owned `FunctionObject0 *` callback through slot `+0x0c`. Score/C++ impact: callback API is accepted enough for first-draft C++.
- What are the second and third parameters? Attempted resolution: MCP prototype and `retn 0x0c` prove they exist; the body does not read them. Class/interface-wide evidence is needed for exact names. Score/C++ impact: use `x`/`y` or equivalent placeholder-grade input names and preserve unused state.
- Is `m_timerHandler.ScheduleTimer` the exact original source spelling? Attempted resolution: TimerHandler docs resolve `sub_5975E0` as generic scheduling wrapper; exact member/helper spelling is inferred. Score/C++ impact: safe as source-facing first draft, but not final-original proof.
- Should UID0004EG remain blank because exact original enum/member names are unknown? No. The behavior and source route are clear, and current project rules do not require impossible original-symbol proof before first-draft C++ when evidence supports source-quality names.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not manually edit coverage reports, generated reports, or `auto-generated/-ag-research-tracker.md`. Validator-owned generated/tracker updates should occur after a later accepted implementation callback and scoped validators.

## Follow-Up Actions

- Supervisor Gate 1 validate this report artifact.
- If accepted, send B006 an implementation callback for UID0004EG target/support docs.
- During callback, lease only the target and directly edited support docs for the immediate edit/validator batch, then release leases immediately.
- Run scoped file validators for every changed by-* doc.
- Check generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` freshness and confirm UID0004EG emits one method body and no empty marker remains for that UID.
- Future sibling work: class1 UID0004E9, class2 UID0004EE, and class2 UID0004EF can reuse the evidence pattern but should remain separate target/report lanes unless supervisor explicitly broadens scope.

## Confidence

Recommendation confidence: high.

Score confidence: medium-high for `88/91`.

Remaining uncertainty: exact original click action enum names, parameter names, class member names, and final declaration/source spelling are inferred rather than recovered. These are confidence caps, not blockers to first-draft formal C++.

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` with `--mode file --apply --queue-timeout 240` for each edited by-* document:

| File | Command id | Timestamp | Exit | Result | Validator changes |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md` | `000000005005` | `2026-07-03T02:47:26-04:00` | 0 | ok 1 | registry updates for completion/confidence/emitter/formal block, projected stats update, reference index adds, UID link inserts |
| `by-class/PrettyButtonControlPane2.md` | `000000005006` | `2026-07-03T02:47:29-04:00` | 0 | ok 1 | projected stats update |
| `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` | `000000005007` | `2026-07-03T02:47:31-04:00` | 0 | ok 1 | projected stats update and UID link insert |
| `by-file/PrettyButtonControlPane.md` | `000000005037` | `2026-07-03T02:54:53-04:00` | 0 | ok 1 | projected stats update; generated refresh deferred |
| `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` | `000000005038` | `2026-07-03T02:54:55-04:00` | 0 | ok 1 | projected stats update; generated refresh deferred |

Generated freshness observation:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` was validator-owned refreshed first with header `validator-command-id: 000000005007`, then after the later file-root support sync with header `validator-command-id: 000000005037`, `validator-refreshed-at: 2026-07-03T02:54:53-04:00`, and `validator-refresh-source: deferred-generated-refresh`.
- UID0004EG emits exactly one generated body with `Completion:88`, `Confidence:91`, and the accepted `PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)` implementation. No UID0004EG empty marker remains.
- `validator.py --queue-status` command `000000005011` at `2026-07-03T02:48:01-04:00` reported worker running true, queued jobs 1, processing jobs 0, queued generated refresh jobs 2, and processing generated refresh jobs 0. The remaining queued refresh jobs were unrelated to additional manual edits.
- After the support-sync validators, `validator.py --queue-status` command `000000005039` at `2026-07-03T02:55:11-04:00` reported queued jobs 0, processing jobs 0, queued generated refresh jobs 0, and processing generated refresh jobs 1 for `000000005038`. A follow-up queue status command `000000005040` at `2026-07-03T02:55:22-04:00` reported queued jobs 0, processing jobs 0, queued generated refresh jobs 0, and processing generated refresh jobs 0. The generated C++ source header remained `000000005037`, which is current for the file-root source-output sync; the parent split/index validator completed without changing that emitted source file header.

No `execute_report`, dry-run/probing execute-report variant, registry lifecycle command, archive command, manual report move, generated/manual coverage edit, or IDA/MCP process-management command was run.

## Changed Files

Edited by B006 during implementation callback:

- `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md`: metadata, evidence, score rationale, and formal C++ applied.
- `by-class/PrettyButtonControlPane2.md`: UID0004EG method/child rows and evidence notes updated.
- `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`: text-only slot note updated; no metadata change.
- `by-file/PrettyButtonControlPane.md`: UID0004EG executable split/source-output row, evidence notes, score rationale text, and changes ledger updated; no metadata change.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: UID0004EG split row, evidence note, and changes ledger updated; parent metadata, non-emitting state, blank emitter, and blank aggregate C++ kept unchanged.
- `tools/leaser/Agents/Agent-B006/research/0004EG-PrettyButtonControlPane2OnClick-source-quality.md`: callback ledger/checklist/results updated.

Validator-owned/generated updates observed:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` was refreshed by validator commands `000000005007` and `000000005037`; it was not manually edited.
- The validators performed their normal registry/projected-stat/reference-index/UID-link updates for the scoped edited files.

Previously blocked support sync now applied:

- `by-file/PrettyButtonControlPane.md`: initially lease-blocked, later leased successfully, edited, validated by `000000005037`, and released.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: initially lease-blocked, later leased successfully, edited, validated by `000000005038`, and released.

Leases used and released:

- Leased successfully by B006, edited/validated, then released successfully: `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md`, `by-class/PrettyButtonControlPane2.md`, `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`.
- After supervisor verification returned the callback as incomplete, B006 retried and successfully leased `by-file/PrettyButtonControlPane.md` and `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`, edited/validated them, and released both successfully.
- Lease report after release did not show active B006 leases; it showed only unrelated stale Supervisor leases from 2026-06-18.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 accepted report SHA256 `F7EEC8493E4EEC20A48C63CD30C42B60FDD4826FA39444DF2C849A373EC329DA`.
- [x] Update target `by-memory/0x0054bb50-0x0054bb89.PrettyButtonControlPane2OnClick.md` metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000AS`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AS`, keep blank `EMITTER_POSITION_OPTIONAL`.
- [x] Update target evidence with live MCP session `9fb70afc`, health state, `sub_54BB50` size `0x39` / decimal 57, disassembly/decompile behavior, one data xref from `0x00622418`, no code callers, padding bytes, class1 analogue, TimerHandler schedule wrapper, and FunctionObject0 callback invocation.
- [x] Replace target blocker wording with source-ready `PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)` semantics: action values `0`/`1`, timer id `1`, 150 ms delay, callback field adjusted `+0x84` -> complete `+0x128`, `FunctionObject0::Invoke()`, and true return.
- [x] Insert formal C++ into UID0004EG:

```cpp
bool PrettyButtonControlPane2::OnClick(unsigned int action, int x, int y)
{
    if (action <= 1) {
        m_timerHandler.ScheduleTimer(1, 150, 0, 0);
        if (m_callback != NULL)
            m_callback->Invoke();
    }

    return true;
}
```

- [x] Preserve negative evidence in UID0004EG: no code callers, only vtable/data xref, no xrefs to vtable cell itself, no recovered action enum names, no recovered original parameter/member names, no direct file/FunctionObjects/TimerHandler/CreateUser owner.
- [x] Update `by-class/PrettyButtonControlPane2.md` method/child rows and evidence notes for UID0004EG as source-ready click handler emitting through UID0000AS, with callback field and timer facts. No metadata change was made.
- [x] Update `by-file/PrettyButtonControlPane.md` split/source-output notes so UID0004EG emits through UID0000AS into `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; validator `000000005037` exit 0 ok 1.
- [x] Update `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` UID0004EG split row/support note; kept parent non-emitting split/index metadata unchanged; validator `000000005038` exit 0 ok 1.
- [x] Update `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md` with a text-only note that slot `0x00622418` target UID0004EG is now source-ready/emitting; no metadata change.
- [x] Leave FunctionObjects, TimerHandler, class1 UID0004E9, and [UID:0000AR] docs unchanged; use them as support evidence only.
- [x] Run scoped validator for each edited by-* doc and record command, `command_id`, `command_timestamp`, exit code, and `ok` count.
- [x] Inspect generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` freshness; UID0004EG emits exactly one body and no empty marker remains.
- [x] Update this report's Claim And Incorporation Ledger and checklist during callback with applied states and concrete path/validator/generated proof.
- [x] Do not manually edit generated files, manual coverage reports, project-level generated reports, validator state, queue files, supervisor ledgers, lifecycle/archive state, or run any `execute_report` variant.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000005057","destination_path":"executed-b-agent-research/B006/0004EG-PrettyButtonControlPane2OnClick-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004EG-PrettyButtonControlPane2OnClick-source-quality.md","timestamp":"2026-07-03T03:19:22-04:00","uid":"0004EG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
