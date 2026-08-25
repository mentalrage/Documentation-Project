** TARGET-REPORT-UID:0004E4 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004E4 PrettyButtonControlPane Destructor Body Source-Quality Report

## Finalized Report / Current Recommendation

[UID:0004E4] `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md` should move from a blank-emitter destructor-body blocker to an emitting ordinary `PrettyButtonControlPane::~PrettyButtonControlPane()` method through [UID:0000AR] `PrettyButtonControlPane`.

Fresh MCP evidence from restored live IDB session `9fb70afc` confirms the target is a live non-modeled destructor body between the modeled constructor `sub_54B5E0` and modeled selected-state setter `sub_54B700`. The raw body restores the three `PrettyButtonControlPane` vtable views, deletes the owned callback pointer at `this+0x124`, destroys the two string/resource members at `this+0x120` and `this+0x11c`, then tail-jumps to `sub_544580`, the `Pane` base destructor route.

Recommended target metadata: raise UID0004E4 from `84/89` to `88/91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, and keep `EMITTER_POSITION_OPTIONAL:` blank. Recommended formal C++:

```cpp
PrettyButtonControlPane::~PrettyButtonControlPane()
{
    delete m_callback;
}
```

The emitted source should not hand-write the vtable stores, explicit `sub_582B70` member-destructor calls, explicit `Pane::~Pane()` / `sub_544580` call, or scalar-delete flag handling. Those are compiler-generated destructor sequencing around the source destructor body and class members.

## Supporting Research

Assignment context:

- Agent: `B008`.
- Assignment ID: `B008-report-0004E4-PrettyButtonControlPaneDestructorBody-20260703`.
- Target UID/path: [UID:0004E4] `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md`.
- Report path: `tools/leaser/Agents/Agent-B008/research/0004E4-PrettyButtonControlPaneDestructorBody-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Assignment-time queue row: `84/89`, average `86.5`, reconstructable `true`, reports `0`.

Operational context:

- Initial MCP checks at `2026-07-03T02:32-04:00` found no listener on `127.0.0.1:13337`; B008 paused rather than producing a fallback report.
- Supervisor then restored and verified MCP, with endpoint `http://127.0.0.1:13337/mcp`, active IDB session `9fb70afc`, and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- This report uses only the restored live session for current MCP facts and does not rely on the earlier unavailable state.
- Report-only pass: no by-* docs, generated files, coverage reports, project-level generated files, validator state, supervisor ledgers, lifecycle state, archives, IDA DB state, or manual report moves were edited. No validators or `execute_report` commands were run.
- Implementation callback: after supervisor Gate 1 acceptance, B008 edited the target doc, class support doc, scalar-wrapper support doc, file support doc, and parent split/index support doc under short leases and scoped validators. `by-file/PrettyButtonControlPane.md` and parent split/index `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` were initially blocked by B005/B004 leases, then B008 resumed after release, verified they were still stale, applied the UID0004E4 source-output/split-row sync, validated them, and released the leases.

Source-family context:

- [UID:0001F9] is the non-emitting split/index parent for the PrettyButtonControls executable island.
- [UID:0000AR] owns class1 `PrettyButtonControlPane`; [UID:0000MP] routes it to `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- UID0004E6 has already accepted `FunctionObject0 *m_callback` at `this+0x124` and source `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)`.
- UID0004ED has already accepted the class2 sibling callback setter and supports the same FunctionObjects callback-family interpretation.
- UID0004EM documents the compiler-generated scalar deleting destructor wrapper for class1 and duplicates the same cleanup sequence plus delete-flag handling.

## Target

- Target UID: `0004E4`.
- Target path: `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md`.
- Current title: `0x0054b6b0-0x0054b6fb PrettyButtonControlPane Destructor Body`.
- Range: source body `0x0054b6b0-0x0054b6fb`; surrounding padding observed at `0x0054b6a4-0x0054b6b0` and `0x0054b6fb-0x0054b700`.
- Current owner: [UID:0000AR] `PrettyButtonControlPane`.
- Current source file route: [UID:0000AR] -> [UID:0000MP] `PrettyButtonControlPane` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Current reconstructable state: `RECONSTRUCTABLE:TRUE`.
- Current emitter state: blank `EMITTER_UIDS`.
- Current formal C++: blank.

## Current Target State

At the report-only starting point, UID0004E4 recorded the correct class owner, reconstructable status, split range, and high-level cleanup behavior, but left source emission blocked:

- `COMPLETION:84`.
- `CONFIDENCE:89`.
- `CANONICAL_OWNER:0000AR`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:` blank.
- Formal `RECONSTRUCTION_CPP CODE` header/body blank.
- Item summary says the body restores vtables, releases callback-like field `this+0x124`, destroys fields at `this+0x120` and `this+0x11c`, and tail-jumps to `sub_544580`.
- `C++ Policy` says formal C++ remains blank pending accepted destructor source shape and field names.

The blocker is now resolvable. Current MCP reconfirms the exact raw body, and accepted UID0004E6/UID0004ED source-quality work resolves the callback field/type as owned `FunctionObject0 *m_callback`. Constructor evidence initializes the same field and string members; scalar deleting destructor evidence repeats the same cleanup sequence with delete-flag handling. That is enough to emit the ordinary destructor source body while keeping compiler-generated member/base cleanup out of handwritten C++.

## Heuristic / Inference Reanalysis And Validation

### Function Identity And Range

`0x0054b6b0-0x0054b6fb` is a non-modeled but live destructor body. Current `lookup_funcs` returns no function at `0x0054b6b0` or `0x0054b6fb`, while the containing window has modeled neighbors `sub_54B5E0` at `0x0054b5e0` size `0xc4`, `sub_54B700` at `0x0054b700` size `0x19`, and `sub_54B720` at `0x0054b720` size `0x24`. Current `entity_query` over `0x0054b5d0-0x0054b730` returns only those modeled functions, confirming UID0004E4 is outside IDA's function table.

`insn_query` over `0x0054b6a4-0x0054b720` shows `align 10h` at `0x0054b6a4`, the target instructions beginning at `0x0054b6b0`, `align 10h` at `0x0054b6fb`, and the successor `sub_54B700` beginning at `0x0054b700`. `get_bytes` over the same window shows twelve `0xcc` bytes before the target and five `0xcc` bytes after the target before `sub_54B700`.

No split or merge is recommended. The target is already an exact child range, and the neighboring padding/function boundaries are stable.

### Destructor Source Shape

The target body performs normal MSVC derived-destructor sequencing:

- save `esi` and copy `this` from `ecx`;
- load the owned callback pointer from `this+0x124`;
- restore the primary, secondary, and tertiary `PrettyButtonControlPane` vtable views at `this+0`, `this+0xa0`, and `this+0xa4`;
- if the callback pointer is non-null, call virtual slot zero with pushed scalar-delete flag `1`;
- call `sub_582B70` on `this+0x120`;
- call `sub_582B70` on `this+0x11c`;
- move `this` back into `ecx`, pop `esi`, and tail-jump to `sub_544580`.

The source-authored part should be represented as `delete m_callback;`. The explicit vtable restoration is compiler-generated destructor setup. The `sub_582B70` calls are member destructor calls for the two string/resource members that the constructor initializes with `sub_582560`; those should be produced by C++ member declarations, not handwritten in the destructor body. The tail jump to `sub_544580` is base `Pane` destructor chaining and should also remain implicit in source.

### Field And Type Interpretation

The callback field is resolved enough for first-draft C++:

- UID0004E4 reads `this+0x124`, null-checks it, and releases it through virtual slot zero with scalar-delete flag `1`.
- UID0004E6 stores the same field as `this[73]` / `this+0x124` and is already accepted as `FunctionObject0 *m_callback`.
- Constructor `sub_54B5E0` stores `0` at `this+0x124`.
- Class/file support docs document this as the owned zero-argument callback slot.

The string/resource members are also resolved enough for destructor source-shape decisions:

- Constructor `sub_54B5E0` initializes `this+0x11c` and `this+0x120` through `sub_582560`.
- Destructor UID0004E4 and scalar wrapper UID0004EM destroy `this+0x120` then `this+0x11c` through `sub_582B70`.
- Accepted OnPaint evidence uses the same two fields as resource-name/palette-name strings.

The source destructor does not need explicit calls for those fields because normal C++ member destruction covers them. The report should preserve their binary cleanup evidence in documentation but avoid decompiler-shaped source.

### Scalar Deleting Destructor Relationship

UID0004EM `sub_54BC40` is the compiler-generated scalar deleting destructor wrapper. Current MCP decompilation and disassembly show it duplicates the class1 destructor cleanup sequence, then tests delete flags and calls `sub_4F4AC0` only for the normal scalar-delete path. Its primary vtable slot at `0x006222d8` points to `0x0054bc40`, and adjustor thunks at `0x0054bb9f` / `0x0054bbaa` reference the wrapper.

This confirms UID0004E4 is the ordinary source destructor body, while UID0004EM remains ABI/deleting wrapper glue. UID0004E4 should emit the class destructor body; UID0004EM should keep its comment-only wrapper marker.

## Evidence Standards Used

- Current live MCP evidence from session `9fb70afc` is ground truth for function boundaries, raw instructions, bytes, xrefs, decompiler output, vtable references, and helper function identities.
- Current by-* docs are durable project context for owner/source route, class/file support, accepted callback type, vtable pages, and prior split/index decisions.
- Executed B reports for UID0004E6 and UID0004ED are used as already-incorporated source-family evidence for callback type/source shape, not as a substitute for current UID0004E4 MCP.
- Generated coverage reports are read-only state context only.
- Inference is labeled when choosing source-facing names and deciding which binary destructor steps are compiler-generated rather than handwritten source.

## Evidence Checked

Required workflow and assignment inputs:

- Read `tools/leaser/Agents/Agent-B008/goal.md`.
- Read project `ntk-b-agent-workflow` skill.
- Read `references/b-agent-research-and-implementation-workflow.md`.
- Read `references/score-blocker-audit-standard.md`.
- Read `references/mcp-incident-playbook.md` after initial MCP unavailability.
- Read `by-structure.md` IDA MCP Output Discipline and ownership/emitter/C++ gate rules.
- Read `tools/leaser/Agents/Agent-B008/notes.md`; no active notes.

Target/support docs:

- `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md`.
- `by-class/PrettyButtonControlPane.md`.
- `by-file/PrettyButtonControlPane.md`.
- `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md`.
- `by-memory/0x0054b990-0x0054b9db.PrettyButtonControlPane2DestructorBody.md`.

Old report/search gate:

- Searched active and executed B-agent material for `0004E4`, `0x0054b6b0`, `0054b6b0`, `PrettyButtonControlPaneDestructorBody`, `PrettyButtonControlPane Destructor`, `sub_544580`, `sub_582B70`, `0x0054b6fb`, and `0054b6fb`.
- Relevant reports opened: `executed-b-agent-research/B015/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md` and `executed-b-agent-research/B013/0004ED-PrettyButtonControlPane2SetCallback-source-quality.md`.
- Other relevant matches were prior destructor/source-shape reports for pane destructors and shared helper evidence; they support rejecting explicit vtable/base/destructor-helper source but do not replace UID0004E4 current MCP.
- No prior standalone UID0004E4 executed report was found.

Current MCP session and calls:

- `tools/list`: endpoint reachable; active schema requires `database` on IDB-backed tools.
- `idb_list`: session `9fb70afc`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker pid `5524`, `is_analyzing:false`.
- `server_health 9fb70afc`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready with size `2067`.
- `lookup_funcs` on `0x0054b5e0`, `0x0054b6a4`, `0x0054b6b0`, `0x0054b6fb`, `0x0054b700`, `0x0054b720`, `0x00544580`, and `0x00582b70`: constructor `sub_54B5E0` size `0xc4`; target start/end not functions; successor `sub_54B700` size `0x19`; callback setter `sub_54B720` size `0x24`; `sub_544580` size `0x107`; `sub_582B70` size `0x36`.
- `entity_query` over `0x0054b5d0-0x0054b730`: only `sub_54B5E0`, `sub_54B700`, and `sub_54B720` modeled as functions.
- `insn_query 0x0054b6a4-0x0054b720`: target body instructions and padding listed without truncation.
- `get_bytes 0x0054b6a4 size 124`: twelve `0xcc` bytes before target; target byte sequence from `56 8b f1` through `e9 85 8e ff ff`; five `0xcc` bytes after target before `sub_54B700`.
- `xref_query` for `0x0054b6b0` and `0x0054b6fb`: no external target-start code/data xrefs; only local fall-through from `0x0054b6b0` to `0x0054b6b1` appears in both-direction query.
- `xref_query` for vtable bases `0x006222d8`, `0x00622340`, and `0x00622370`: data xrefs from constructor stores at `0x54b636/0x54b63c/0x54b646`, target destructor stores at `0x54b6b9/0x54b6bf/0x54b6c9`, and scalar wrapper stores at `0x54bc4c/0x54bc52/0x54bc5c`.
- `decompile 0x0054b5e0`: constructor initializes frame ids, vtables, string members at `this+284` and `this+288`, state bytes, and callback slot `this+292`.
- `decompile 0x0054b720`: callback setter releases and stores `this[73]`, matching `this+0x124`.
- `decompile 0x00544580`: base `Pane` destructor restores Pane vtables and runs base cleanup, confirming `sub_544580` is not a PrettyButton-specific source call.
- `decompile/disasm 0x0054bc40`: scalar deleting destructor wrapper repeats UID0004E4 cleanup, calls `sub_544580`, then handles delete flags and `sub_4F4AC0`.
- `xrefs_to 0x0054bc40`: refs from class1 adjustor thunks and primary vtable slot `0x006222d8`.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0004E4 is a source-authored ordinary destructor body, not padding, a thunk, or scalar deleting wrapper. | MCP `insn_query` shows complete cleanup body at `0x0054b6b0-0x0054b6fb`; modeled neighbors exclude this range; UID0004EM separately covers scalar deleting destructor. | Target status/evidence and class/file method inventory. | incorporate | applied: target, class support, and file support docs identify UID0004E4 as the source-ready ordinary destructor body; parent split row also records source-ready ordinary destructor disposition. |
| Direct owner remains [UID:0000AR] `PrettyButtonControlPane`. | Current metadata, class/file docs, class1 vtable restores, constructor field offsets, and scalar wrapper parity. | Target metadata and support docs. | incorporate | applied: target kept `CANONICAL_OWNER:0000AR`; class, file, and parent support rows route UID0004E4 through UID0000AR. |
| Emitter route should be [UID:0000AR]. | UID0000AR emits through UID0000MP; target is reconstructable, source-authored, above C++ score gate after recommendation, and class-owned. | Target `EMITTER_UIDS`; class/file support docs. | incorporate | applied: target `EMITTER_UIDS:0000AR`; file and parent support docs state UID0004E4 emits through UID0000AR; generated output includes UID0004E4 through the PrettyButton source root. |
| Source destructor body should be `PrettyButtonControlPane::~PrettyButtonControlPane()` with `delete m_callback;`. | Target body releases `this+0x124`; UID0004E6 accepts `FunctionObject0 *m_callback`; constructor zero-initializes same field. | Target C++ block and source-policy notes. | incorporate | applied: target formal C++ and generated `PrettyButtonControlPane.cpp` contain the destructor body. |
| Vtable stores should not be handwritten source. | Destructor and scalar wrapper both write vtables before cleanup; these are MSVC destructor sequencing artifacts. | Target C++ policy/rejected alternatives. | incorporate | applied: target C++ policy rejects handwritten vtable stores; class support notes preserve compiler-generated sequencing. |
| `sub_582B70(this+0x120)` and `sub_582B70(this+0x11c)` should be documented as compiler-emitted member string destructors, not explicit source calls. | Constructor initializes those members via `sub_582560`; OnPaint uses them as resource/palette strings; destructor destroys them after callback. | Target evidence, class layout notes, rejected alternatives. | incorporate | applied: target and class support docs document implicit member cleanup and keep it out of source C++. |
| Tail `jmp sub_544580` should be documented as implicit base `Pane` destructor chaining, not explicit source. | `sub_544580` decompile restores Pane vtables and performs base cleanup; pane destructor reports use same rule. | Target C++ policy/rejected alternatives. | incorporate | applied: target and class support docs document implicit base teardown and reject explicit source call. |
| UID0004EM remains compiler-generated scalar deleting destructor wrapper with comment-only marker. | Current decompile/disasm `0x0054bc40` adds delete-flag handling after same cleanup sequence and is referenced by vtable/adjustor thunks. | Support doc cross-reference; no target merge. | already-present plus incorporate | applied: UID0004EM support doc now references UID0004E4 as ordinary source destructor and remains comment-only wrapper. |
| UID0004EB class2 destructor body is sibling evidence only. | Class2 body uses same pattern at `this+0x128` / `+0x124` / `+0x120`; separate UID and owner. | Support comparison note only. | not-applicable | excluded-with-reason: UID0004EB was not in callback scope and was not edited. |
| No range split/merge is needed. | Padding before/after target and modeled successor at `0x0054b700`; no modeled function at target. | Target range/split notes. | incorporate | applied: target evidence preserves exact raw span, padding, modeled neighbors, and no-split disposition; parent split row keeps the exact child span and updates the row to source-ready ordinary destructor wording. |

## Positive Evidence Summary

- Current MCP verifies a complete raw destructor sequence at `0x0054b6b0-0x0054b6fb` with stable padding and modeled function neighbors.
- The three vtable stores target the same `PrettyButtonControlPane` vtable bases written by the constructor and scalar deleting destructor wrapper.
- The callback field at `this+0x124` is already resolved by UID0004E6 as owned `FunctionObject0 *m_callback`.
- Constructor evidence initializes `this+0x11c`, `this+0x120`, and `this+0x124`; destructor evidence cleans exactly those lifetime-owned fields.
- Scalar wrapper UID0004EM duplicates the cleanup plus delete-flag handling, confirming UID0004E4 is the ordinary destructor body and UID0004EM is ABI wrapper glue.
- The class/file route through UID0000AR -> UID0000MP already clears the current source-output path.

## Negative Evidence Summary

- IDA still does not model `0x0054b6b0` as a function, and `decompile 0x0054b6b0` is therefore not available.
- No external xref points directly to `0x0054b6b0`; destructor entry reachability is inferred from class destructor/source-shape parity and scalar wrapper/vtable lifecycle.
- No original source symbol or full PrettyButton UDT declaration was recovered.
- Exact original field spellings for the resource strings are still inferred/descriptive, although their offsets and cleanup roles are clear.
- These negatives cap confidence below final-audit range but do not block source emission because behavior, ownership, route, and source body are resolved enough for first-draft C++.

## Ranked Ownership Analysis

1. [UID:0000AR] `PrettyButtonControlPane`: accepted.
   Evidence for: current owner, class1 vtable restores, constructor/scalar-wrapper parity, class docs, callback field at `+0x124`, and source route through UID0000MP.
   Evidence against: full class declaration and exact original member names remain below final audit.
   Decision: keep `CANONICAL_OWNER:0000AR` and set `EMITTER_UIDS:0000AR`.

2. [UID:0000MP] `PrettyButtonControlPane.cpp`: accepted as source-file route, rejected as direct owner.
   Evidence for: file root owns both PrettyButton classes and emits to `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
   Evidence against: target is a class method body, so direct owner should be the class.
   Decision: route through UID0000AR to UID0000MP.

3. [UID:0001F9] PrettyButtonControls split/index: rejected as emitter/direct source owner.
   Evidence for: physically contains UID0004E4.
   Evidence against: already a non-emitting split/index parent; exact children carry source ownership.
   Decision: leave UID0001F9 non-emitting.

4. [UID:0004EM] scalar deleting destructor wrapper: rejected as merge target.
   Evidence for: duplicates cleanup sequence and is vtable-referenced.
   Evidence against: adds delete flags and allocation-free path; already has separate compiler-generated wrapper page.
   Decision: keep separate. UID0004E4 emits ordinary destructor; UID0004EM remains ABI marker.

5. [UID:0000JO] / FunctionObjects: rejected as owner.
   Evidence for: supplies callback object type and destructor semantics.
   Evidence against: target is a PrettyButton destructor deleting a member callback, not a FunctionObjects implementation.
   Decision: cite as type support only through UID0004E6.

6. CreateUser/NewUser dialog code: rejected.
   Evidence for: callers construct PrettyButton controls and callback objects elsewhere.
   Evidence against: callers are consumers; destructor is class-owned and not feature-dialog source.
   Decision: no caller ownership.

7. No-owner/non-emitting: rejected.
   Evidence for: raw entry has no direct external xref and no IDA function object.
   Evidence against: destructor body, class vtable stores, field cleanup, owner route, and scalar wrapper parity are strong enough.
   Decision: source-emitting class method.

## Source Placement

Recommended source placement:

`[UID:0004E4] by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md` -> `[UID:0000AR] by-class/PrettyButtonControlPane.md` -> `[UID:0000MP] by-file/PrettyButtonControlPane.md` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

This placement matches the existing PrettyButton split and accepted sibling methods. The destructor should appear as the ordinary class destructor implementation. It should not be represented as a free helper, callback utility, scalar deleting destructor, vtable-data output, base `Pane` source, or dialog-local cleanup.

## First-Draft C++ Recommendation

UID0004E4 is eligible for formal first-draft C++ after the recommended metadata change:

- `RECONSTRUCTABLE:TRUE`.
- Recommended nonblank `EMITTER_UIDS:0000AR`.
- Recommended score `88/91`, average `89.5`, above the current C++ gate.
- Behavior, owner, route, field role, and source/no-source boundary are supported by current MCP and accepted support docs.

Recommended exact formal C++ for UID0004E4:

```cpp
PrettyButtonControlPane::~PrettyButtonControlPane()
{
    delete m_callback;
}
```

Implementation notes:

- `m_callback` is the accepted source-facing member at `this+0x124`.
- `delete m_callback;` represents the observed null-check plus virtual scalar deleting destructor call with pushed flag `1`.
- Do not emit vtable stores in source.
- Do not explicitly call `sub_582B70`, string destructors, or resource string cleanup helpers in the destructor body; those are emitted from member declarations.
- Do not explicitly call `Pane::~Pane()` / `sub_544580`; base destruction is implicit.
- Do not include scalar delete flags or `sub_4F4AC0`; that belongs only to UID0004EM.

## Recommended Target Doc Changes

For `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md` / [UID:0004E4]:

- Change metadata from `COMPLETION:84`, `CONFIDENCE:89`, blank `EMITTER_UIDS` to `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:0000AR`.
- Keep `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- Expand the item summary and evidence to record restored MCP session `9fb70afc`, non-modeled raw body, exact instructions, padding, vtable stores, `m_callback` release at `+0x124`, member cleanup at `+0x120/+0x11c`, and tail base destructor route.
- Replace current C++ blocker text with source-ready ordinary destructor policy.
- Insert the exact formal C++ from `## First-Draft C++ Recommendation`.
- Add rejected alternatives: no handwritten vtable stores, no explicit `sub_582B70`, no explicit `Pane::~Pane`/`sub_544580`, no scalar-delete wrapper code, no UID0001F9 aggregate emission, no FunctionObjects ownership, no dialog ownership, and no no-owner/non-emitting disposition.
- Preserve negative evidence: no IDA function object, no direct external xref to raw start, inferred member names.
- Add scalar wrapper relationship: UID0004EM duplicates the cleanup and owns delete-flag/free handling as compiler-generated ABI glue.

## Recommended Support Doc Changes

For `by-class/PrettyButtonControlPane.md`:

- Update the destructor method row from blank/blocker state to source-ready `PrettyButtonControlPane::~PrettyButtonControlPane()`.
- Document that the ordinary destructor source body deletes owned `FunctionObject0 *m_callback` at `+0x124`; compiler-generated destructor sequencing accounts for vtable restores, `m_epfResourceName` / `m_paletteResourceName` member cleanup at `+0x11c/+0x120`, and base `Pane` teardown.
- Update the exact child page row for UID0004E4 to say it emits through UID0000AR once accepted.
- Optional support score recommendation: `88/90 -> 89/91` only if the supervisor accepts a class-wide bump for resolving the destructor blocker. Conservative option: leave support scores unchanged because broader constructor/click/class declaration details remain open.

For `by-file/PrettyButtonControlPane.md`:

- Update executable split/source-output notes so UID0004E4 emits one `PrettyButtonControlPane::~PrettyButtonControlPane()` body through UID0000AR.
- Keep source root `NexusTK/ui/controls/PrettyButtonControlPane.cpp` unchanged.
- Preserve UID0001F9 as non-emitting split/index and UID0004EM as compiler-generated scalar deleting destructor wrapper.
- Optional support score recommendation: leave `88/90` unchanged unless the supervisor wants a small file-level bump after the target/class sync.

For `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` / [UID:0001F9]:

- No metadata change required.
- Optional text-only sync: update the UID0004E4 row from "C++ blank until destructor field names are accepted" to source-ready ordinary destructor body emitting through UID0000AR; preserve the parent as non-emitting split/index.

For `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md` / [UID:0004EM]:

- No metadata change required.
- Optional text-only sync: mention that UID0004E4 owns the ordinary source destructor body while UID0004EM remains the scalar deleting wrapper with delete flags and comment-only C++ marker.

For `by-memory/0x0054b990-0x0054b9db.PrettyButtonControlPane2DestructorBody.md` / [UID:0004EB]:

- Do not edit under this UID0004E4 callback unless supervisor explicitly includes sibling support sync. It is comparison evidence only.

For generated output and coverage:

- Do not manually edit generated files or coverage reports.
- After a later implementation callback and scoped validators, expect `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` to include one UID0004E4 destructor body. Validator-owned generated reports/tracker rows should refresh from source metadata.

## Score And Metadata Recommendation

Target UID0004E4:

- `COMPLETION`: `84 -> 88`.
- `CONFIDENCE`: `89 -> 91`.
- `CANONICAL_OWNER`: keep `0000AR`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: blank -> `0000AR`.
- `EMITTER_POSITION_OPTIONAL`: keep blank.

Rationale:

- Completion rises because the named blockers are resolved: destructor source shape, callback field/type, member/base cleanup policy, scalar wrapper relationship, and first-draft C++ are now implementation-ready.
- Confidence rises because restored live MCP confirms exact instructions, bytes, modeled neighbors, vtable refs, constructor/scalar wrapper parity, and helper identities.
- Score should stay below final-audit range because no original destructor symbol/full UDT was recovered, exact string member names remain inferred, the raw body is not IDA-modeled as a function, and direct external xrefs to the ordinary destructor entry are not recovered.
- The recommended score plus emitter route clears the current formal C++ gate: `(88 + 91) / 2 = 89.5`.

Support metadata:

- `by-class/PrettyButtonControlPane.md`: optional `88/90 -> 89/91`, but conservative default is no support score change unless supervisor chooses a class-wide bump.
- `by-file/PrettyButtonControlPane.md`: no score/metadata change required.
- UID0001F9, UID0004EM, UID0004EB, and vtable data pages: no score/metadata change required.

## Open Questions With Attempted Resolution

- Is UID0004E4 live source or padding? Resolved as live source. Evidence: exact instruction body, vtable writes, cleanup calls, padding before/after, modeled neighbors, and scalar wrapper parity.
- Is the callback field/type still a blocker? Resolved through UID0004E6 and current MCP: `this+0x124` is owned `FunctionObject0 *m_callback`.
- Should string/resource cleanup be handwritten? Resolved no. Constructor initializes `+0x11c/+0x120` as members and destructor invokes `sub_582B70`; source should rely on member destructors.
- Should base `Pane` cleanup be handwritten? Resolved no. `sub_544580` is the base destructor route and should be implicit.
- Should UID0004E4 merge with UID0004EM? Resolved no. UID0004EM includes scalar delete flags/free path and remains compiler-generated wrapper glue.
- Is direct reachability recovered? Not to raw entry. Current xrefs do not show an external xref to `0x0054b6b0`; reachability is via class destructor/source-shape and scalar wrapper/vtable lifecycle. Impact: confidence cap, not emission blocker.
- Are exact original member names recovered? Not fully. `m_callback` is accepted; resource string field names remain descriptive from existing OnPaint docs. Impact: keep score below 95 and document inference.

## Validator Results

Report-only pass: no validators were run.

Implementation callback scoped validators from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md --apply --queue-timeout 240`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000005003`
  - `command_timestamp: 2026-07-03T02:47:04-04:00`
  - Relevant updates: completion `88`, confidence `91`, emitter `0000AR`, formal C++ changed from blank to block, UID/reference indexes updated, projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000005004`
  - `command_timestamp: 2026-07-03T02:47:06-04:00`
  - Relevant updates: UID/reference indexes updated, projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-class/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000005036`
  - `command_timestamp: 2026-07-03T02:54:45-04:00`
  - Relevant updates: projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file/PrettyButtonControlPane.md --apply --queue-timeout 240`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000005048`
  - `command_timestamp: 2026-07-03T03:10:13-04:00`
  - Relevant updates: projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md --apply --queue-timeout 240`
  - Exit code: `0`; `ok: 1`
  - `command_id: 000000005049`
  - `command_timestamp: 2026-07-03T03:10:18-04:00`
  - Relevant updates: projected stats updated, generated refresh deferred.
- `python .\tools\validator.py --queue-status`
  - Exit code: `0`
  - `command_id: 000000005045`
  - `command_timestamp: 2026-07-03T03:04:50-04:00`
  - Queue state: worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- `python .\tools\validator.py --queue-status`
  - Exit code: `0`
  - `command_id: 000000005050`
  - `command_timestamp: 2026-07-03T03:10:39-04:00`
  - Queue state: worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.

Generated freshness:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` refreshed to `validator-command-id: 000000005048`, `validator-refreshed-at: 2026-07-03T03:10:13-04:00`, equal to the by-file support validator and newer than edited-file validator commands `000000005003`, `000000005004`, `000000005036`, and `000000005049` for target/class/scalar/parent docs that do not own the generated file root.
- Generated source contains exactly one UID0004E4 body:

```cpp
PrettyButtonControlPane::~PrettyButtonControlPane()
{
    delete m_callback;
}
```

- Generated source still keeps UID0004EM as a comment-only compiler-generated scalar deleting destructor wrapper marker.

No `execute_report`, dry-run/probing execute-report variant, registry lifecycle command, archive command, manual report move, generated/manual coverage edit, or IDA/MCP process-management command was run.

## Changed Files

Created report-only artifact:

- `tools/leaser/Agents/Agent-B008/research/0004E4-PrettyButtonControlPaneDestructorBody-source-quality.md`

Implementation callback changed by-* docs:

- `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md`
- `by-memory/0x0054bc40-0x0054bcbd.PrettyButtonControlPaneScalarDeletingDestructor.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`
- `tools/leaser/Agents/Agent-B008/research/0004E4-PrettyButtonControlPaneDestructorBody-source-quality.md`

Lease-conflict history, later resolved:

- `by-file/PrettyButtonControlPane.md`: initially blocked by B005 lease `2026-07-03T06:58:59Z-07:03:59Z`, then B004 lease `2026-07-03T07:04:22Z-07:09:22Z`; after release, B008 leased, edited, validated with `000000005048`, and released.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: initially blocked by B005 lease `2026-07-03T06:58:59Z-07:03:59Z`, then B004 lease `2026-07-03T07:04:22Z-07:09:22Z`; after release, B008 leased, edited, validated with `000000005049`, and released.

No generated files, coverage reports, project-level generated files, validator state, supervisor ledgers, lifecycle state, archives, or IDA DB state were manually edited.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md` metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`, blank `EMITTER_POSITION_OPTIONAL`. Proof: target header and validator `000000005003`.
- [x] Update UID0004E4 target evidence with restored MCP session `9fb70afc`, health/session state, lookup/entity-query function-boundary evidence, exact `insn_query` body, `get_bytes` padding, vtable xrefs, constructor field initialization, callback setter support, scalar wrapper parity, and helper roles. Proof: target `Evidence` section and validator `000000005003`.
- [x] Replace UID0004E4 blocker wording with source-ready ordinary destructor policy. Proof: target `Status` and `C++ Policy`.
- [x] Insert formal C++ exactly:

```cpp
PrettyButtonControlPane::~PrettyButtonControlPane()
{
    delete m_callback;
}
```

- [x] Preserve negative/rejected evidence in UID0004E4: no IDA function model, no direct external raw-entry xref, no UID0001F9 aggregate emission, no FunctionObjects ownership, no dialog ownership, no handwritten vtable stores, no explicit `sub_582B70`, no explicit `sub_544580` / `Pane::~Pane`, no scalar-delete wrapper code. Proof: target `Evidence` and `C++ Policy`.
- [x] Update `by-class/PrettyButtonControlPane.md` destructor row/evidence to source-ready `PrettyButtonControlPane::~PrettyButtonControlPane()`, with `m_callback` delete source body and compiler-generated member/base cleanup notes. Proof: class `Method Notes`, `Exact Child Pages`, `Evidence Notes`, `Changes`; validator `000000005036`.
- [x] Update `by-file/PrettyButtonControlPane.md` split/source-output notes so UID0004E4 emits through UID0000AR into `NexusTK/ui/controls/PrettyButtonControlPane.cpp`. Proof: row, roll-up source-output note, evidence note, score rationale text, and change log updated after B004 lease release; validator `000000005048`.
- [x] Optionally sync `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` UID0004E4 row if supervisor includes parent support sync; leave parent metadata unchanged. Proof: parent split row, behavior/evidence notes, score rationale text, and change log updated after B004 lease release; validator `000000005049`.
- [x] Optionally sync UID0004EM scalar wrapper text to reference UID0004E4 as ordinary source destructor; leave UID0004EM metadata/comment-only wrapper policy unchanged. Proof: scalar wrapper `Evidence` and `C++ Policy`; validator `000000005004`.
- [x] Do not edit UID0004EB sibling unless supervisor explicitly includes it in callback scope. Proof: UID0004EB was not edited.
- [x] Run scoped validators after implementation callback for each edited by-* doc. Proof: validators `000000005003`, `000000005004`, `000000005036`, `000000005048`, and `000000005049`, all exit `0` / `ok:1`.
- [x] After validators, check generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` freshness and confirm UID0004E4 emits exactly one ordinary destructor body and UID0004EM remains only the scalar deleting wrapper marker. Proof: generated header `validator-command-id: 000000005048`, refreshed `2026-07-03T03:10:13-04:00`; queue status `000000005050` showed no queued or processing refresh jobs.
- [x] Update this report's Claim And Incorporation Ledger and checklist during callback with `applied`, `already-present`, or `excluded-with-reason` states and concrete validator/generated proof. Proof: this section and ledger updated; the prior file/parent lease conflicts were resolved and no checklist item remains blocked.
- [x] Do not edit generated files, manual coverage reports, project-level generated reports, validator state, supervisor ledgers, archives, or report lifecycle state; do not run `execute_report` or any lifecycle/archive/manual move command. Proof: only scoped file validators and queue status were run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000005059","destination_path":"executed-b-agent-research/B008/0004E4-PrettyButtonControlPaneDestructorBody-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004E4-PrettyButtonControlPaneDestructorBody-source-quality.md","timestamp":"2026-07-03T03:19:25-04:00","uid":"0004E4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
