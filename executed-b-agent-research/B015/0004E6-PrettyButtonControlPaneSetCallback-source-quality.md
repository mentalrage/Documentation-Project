** TARGET-REPORT-UID:0004E6 **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004E6 PrettyButtonControlPane SetCallback Source-Quality Report

## Finalized Report / Current Recommendation

[UID:0004E6] `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md` should move from blank-emitter callback-blocker state to an emitting `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` source method through [UID:0000AR] `PrettyButtonControlPane`.

Fresh MCP evidence in live session `b011_0004EC_20260702` confirms `sub_54B720` is a modeled `0x24` byte function with a 15-instruction body. It loads the existing callback pointer from `this+0x124` / `this[73]`, tests for null, calls virtual slot zero with scalar-delete flag `1`, stores the new argument back to `this+0x124`, and returns with `retn 4`. The source-shaped interpretation is a setter that deletes/releases the previously owned zero-argument callback object and adopts the new `FunctionObject0 *`.

Recommended target metadata: raise UID0004E6 from `84/88` to `88/91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, and keep `EMITTER_POSITION_OPTIONAL:` blank unless the supervisor wants method-order sorting. Recommended formal C++:

```cpp
void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
```

This recommendation resolves the named callback type/helper blocker for UID0004E6. It does not require changing the broader UID0001F9 split parent, vtable data ownership, or the class2 sibling UID0004ED during this target callback, although class/file support docs should be synchronized with the accepted type/name/source-shape decision.

## Supporting Research

Assignment context:

- Agent: B015.
- Assignment ID: `B015-report-0004E6-PrettyButtonControlPaneSetCallback-20260702`.
- Target UID/path: [UID:0004E6] `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md`.
- Report path: `tools/leaser/Agents/Agent-B015/research/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Assignment-time queue row: `84/88`, average `86.0`, reconstructable `true`, B reports `0`.

Operational context:

- Initial MCP attempt found stale sessions `b010_0002r7_20260702` and `b013_0001FN_20260702` unreachable. Per supervisor incident result, those sessions were not used for final evidence.
- A fresh/adopted live session was opened with preferred session id `b015_0004E6_20260702`; MCP returned existing live session `b011_0004EC_20260702` for the same IDB. That session was used for all current MCP facts in this report.
- No by-* docs, generated files, coverage reports, project-level generated files, validator state, supervisor ledgers, lifecycle state, archives, or manual report moves were edited. No validators or `execute_report` commands were run.

Source-family context:

- [UID:0001F9] is already a reviewed non-emitting split/index parent for the PrettyButtonControls executable island. Exact children [UID:0004E3]-[UID:0004EM] carry the executable ranges through [UID:0000AR] `PrettyButtonControlPane` and [UID:0000AS] `PrettyButtonControlPane2`.
- [UID:0000AR] and [UID:0000MP] already document UID0004E6 as a class1 callback replacement child in `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- [UID:0001WQ] `FunctionObjectTemplates`, [UID:00005L] `FunctionObject0`, and [UID:0000JO] `FunctionObjects` already establish `FunctionObject0` as the zero-argument callback base and `PlainMemberFunctionObject0` as the concrete member-function wrapper family. The caller sites for UID0004E6 allocate exactly that concrete wrapper family before calling `sub_54B720`.

## Target

- Target UID: `0004E6`.
- Target path: `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md`.
- Current title: `0x0054b720-0x0054b744 PrettyButtonControlPane SetCallback`.
- Range: `0x0054b720-0x0054b744`.
- Current owner: [UID:0000AR] `PrettyButtonControlPane`.
- Current source file route: [UID:0000AR] -> [UID:0000MP] `PrettyButtonControlPane` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Current reconstructable state: `RECONSTRUCTABLE:TRUE`.
- Current emitter state: blank `EMITTER_UIDS`.
- Current formal C++: blank.

## Current Target State

UID0004E6 currently records the correct class owner, exact range, reconstructable status, and high-level behavior, but leaves output blocked:

- `COMPLETION:84`.
- `CONFIDENCE:88`.
- `CANONICAL_OWNER:0000AR`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:` blank.
- `RECONSTRUCTION_CPP CODE` header and body blank.
- Item summary says MCP confirms function `0x0054b720` size `0x24`, one caller in `sub_52A540`, prior callback release, and callback storage behavior.
- `Ownership And C++ Policy` says formal C++ remains blank until callback type and ownership helper names are accepted.

The blocker is now resolvable. Current MCP shows the body exactly matches a source setter for an owned `FunctionObject0 *`, and current FunctionObjects documentation already accepts the reusable zero-argument callback base/template declaration. The two caller sites allocate `PlainMemberFunctionObject0<void (__thiscall NewUserDialogPane2::*)(), NewUserDialogPane2>` objects immediately before the `sub_54B720` calls, so a `FunctionObject0 *` parameter is the safest source-facing type for this class method. The body's virtual slot-zero call with flag `1` is compiler output for deleting the old callback object, not a hand-authored helper call that should remain as `(**v3)(v3, 1)`.

## Heuristic / Inference Reanalysis And Validation

### Function Identity

`sub_54B720` is not a padding span, compiler thunk, destructor wrapper, vtable artifact, or raw helper detached from source. It is a modeled `.text` function at `0x0054b720`, size `0x24`, with normal prologue/epilogue and `retn 4`. The body has three basic blocks and one null-check branch. It has two direct code xrefs from `sub_52A540`, both associated with constructed `PrettyButtonControlPane` instances in create-user dialog setup.

The best source-facing method name remains `PrettyButtonControlPane::SetCallback`. Existing target/class/file docs already use that name; the caller contexts construct callback objects and pass them into the method; the body only replaces the stored callback pointer. No stronger original spelling was found, but the existing name is behavior-specific, non-decompiler-shaped, and consistent with the class2 sibling's role.

### Callback Type And Field Name

The current blocker can be resolved to `FunctionObject0 *`:

- The current target body stores the argument in `this[73]`, which is byte offset `73 * 4 = 292`, i.e. `0x124`. This matches current target/support docs' callback/object pointer near `+292`.
- The caller decompile at `sub_52A540` allocates 24-byte objects, calls `sub_4F4A80` for the `LObject` shell, installs decorated `PlainMemberFunctionObject0<void (__thiscall NewUserDialogPane2::*)(), NewUserDialogPane2>` vtable `0x0061fed8`, stores member targets `sub_52B090` and `sub_52B1D0`, stores zero this-adjustment, stores the `NewUserDialogPane2` object pointer, and passes the result to `sub_54B720`.
- [UID:0001WQ] defines `class FunctionObject0 : public LObject` with virtual destructor, `Invoke()`, and `GetObjectSize()`, and defines `PlainMemberFunctionObject0<TMember, TObject>` as a `FunctionObject0` derived type.
- The setter only needs the base-pointer storage type; the concrete template type is caller-specific and should stay at the construction sites.

Use `m_callback` as the source-facing field name for UID0004E6. It is a local class member at `PrettyButtonControlPane +0x124`. The name is inferred, not original-symbol proven, but it is consistent with the current class purpose, FunctionObjects family, caller construction, destructor release, and existing docs' "callback replacement" wording. It is more source-grade than `this[73]`, `field_124`, `callbackObject`, or a concrete `PlainMemberFunctionObject0<NewUserDialogPane2>` member type.

### Release Semantics

The target disassembly calls virtual slot zero on the old pointer with pushed immediate `1`. In this codebase and in the FunctionObjects docs, that is compiler-level scalar deleting destructor dispatch for owned callback objects. Source C++ should express this as `delete m_callback;`, not as `m_callback->Release(1)`, `(**m_callback)(m_callback, 1)`, or a named helper. `delete` also explains the explicit null check before the virtual call; MSVC emits no destructor call for null.

The source statement should not call `Invoke()`: UID0004E6 does not dispatch the callback. It only releases the prior callback and stores a replacement. Click/notification behavior lives in UID0004E9 and caller-created `PlainMemberFunctionObject0` targets.

### Return Type

IDA decompiles the body as `int __thiscall sub_54B720(_DWORD *this, int a2)` because `eax` still contains the assigned argument after the store. That does not prove a source return value. A source `void` setter can leave `eax` holding the argument as a compiler artifact. The caller sites ignore the return value: after `sub_54B720`, they immediately pass the constructed button into `sub_49DC10`. The source-shaped recommendation is therefore `void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)`.

### Sibling Comparison

The class2 analogue at `0x0054ba00-0x0054ba24` is not modeled as an IDA function but has the same instruction shape in a raw executable span:

- Loads `this+0x128`.
- Null-checks.
- Calls virtual slot zero with pushed `1`.
- Stores the new argument at `this+0x128`.
- Returns with `retn 4`.
- Has no direct xrefs in the current IDB.

This supports the type/field interpretation for UID0004E6 while also explaining why UID0004ED should not be edited as part of this report unless the supervisor includes it in a later callback: UID0004ED has a separate assignment/report lane and no current caller evidence beyond sibling symmetry.

## Evidence Standards Used

Evidence was ranked as follows:

- Current live IDA MCP evidence from non-stale session `b011_0004EC_20260702` is ground truth for function boundaries, disassembly, decompilation, xrefs, caller context, and bytes.
- Current by-* docs are durable project context for owner/source route, class/file support, FunctionObjects types, and prior split parent conclusions.
- The executed B011 UID0001F9 report is used only as relevant source-family history and already-incorporated split evidence, not as a substitute for current target MCP.
- Generated C++ is read-only lead/freshness context only. It was not edited and is not used as authority for the target behavior.
- Inference is explicitly labeled when choosing source-facing names such as `m_callback`, `SetCallback`, and `FunctionObject0 *`.

## Evidence Checked

Workflow and assignment inputs:

- Read `tools/leaser/Agents/Agent-B015/goal.md`.
- Read `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`.
- Read `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`.
- Read `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`.
- Read `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`.
- Read `by-structure.md` IDA MCP Output Discipline and ownership/emitter/C++ gate rules.

Target/support docs:

- `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md`.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`.
- `by-class/PrettyButtonControlPane.md`.
- `by-file/PrettyButtonControlPane.md`.
- `by-class/PrettyButtonControlPane2.md`.
- `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md`.
- `by-memory/0x0054b5e0-0x0054b6a4.PrettyButtonControlPaneConstructor.md`.
- `by-memory/0x0054b6b0-0x0054b6fb.PrettyButtonControlPaneDestructorBody.md`.
- `by-memory/0x0054b750-0x0054b7b2.PrettyButtonControlPaneSetVisualState.md`.
- `by-memory/0x0054b880-0x0054b8b9.PrettyButtonControlPaneOnClick.md`.
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`.
- `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`.
- `by-type/by-template/FunctionObjectTemplates.md`.
- `by-class/FunctionObject0.md`.
- `by-file/FunctionObjects.md`.

Old report/search gate:

- Searched current and executed B-agent material with `rg` terms including `0004E6`, `0x0054b720`, `PrettyButtonControlPaneSetCallback`, `PrettyButtonControlPane SetCallback`, `SetCallback`, and `PrettyButtonControlPane`.
- Relevant match opened: `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`.
- Other matches were supervisor notes/assignments or active sibling assignment files. No prior standalone UID0004E6 report was found.

MCP session and current target calls:

- `idb_open` requested `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with preferred session id `b015_0004E6_20260702`; MCP returned live session `b011_0004EC_20260702`.
- `server_health` on `b011_0004EC_20260702`: `status: ok`, `idb_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `module: NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `lookup_funcs` on `0x0054b720`: `sub_54B720`, size `0x24`.
- `lookup_funcs` on `0x0054ba00`: not a function, confirming the class2 analogue is a raw/non-modeled executable span.
- `lookup_funcs` on `0x0054b5e0`: `sub_54B5E0`, size `0xc4`.
- `lookup_funcs` on `0x0054b8c0`: `sub_54B8C0`, size `0xcd`.
- `disasm 0x0054b720`, `max_instructions=32`, returned 15 total instructions: load `[esi+124h]`, null test, virtual slot-zero call with pushed `1`, store `[esi+124h]`, `retn 4`.
- `decompile 0x0054b720`, no line addresses, returned `this[73]` prior pointer, `(**v3)(v3, 1)`, assignment `this[73] = a2`, and return of `a2`.
- `analyze_function 0x0054b720` returned prototype `int __thiscall(_DWORD *this, int)`, size `36`, callers `sub_52A540`, xrefs to `0x52a907` and `0x52a9b0`, no direct callees because the virtual call target is indirect, basic-block count `3`, cyclomatic complexity `2`.
- `xrefs_to` and `xref_query` on `0x0054b720`: exactly two code xrefs, from `0x0052a907` and `0x0052a9b0`, both in `sub_52A540` size `0xb07`; no truncation.
- `xrefs_to` and `xref_query` on `0x0054ba00`: zero code xrefs.
- `get_bytes` at `0x0054b719` size `43`: seven `0xcc` bytes before the target, followed by the full target byte sequence ending `5e 5d c2 04 00`.
- `get_bytes` at `0x0054b9f9` size `43`: seven `0xcc` bytes before the class2 analogue, then the same byte sequence except offset `0x128` instead of `0x124`.
- `disasm 0x0054ba00`, `max_instructions=32`, returned the class2 analogue body from `0x54ba00-0x54ba21`, `align 10h` at `0x54ba24`, then the successor modeled `sub_54BA30`.
- `decompile 0x0054ba00` failed because it is not modeled as a function; disassembly and bytes were used instead.
- `decompile 0x0052a540` with addresses returned two relevant construction/call sites: at `0x52a8c9-0x52a907` and `0x52a972-0x52a9b0`, each allocates 24 bytes, calls `sub_4F4A80`, installs `PlainMemberFunctionObject0<void (__thiscall NewUserDialogPane2::*)(), NewUserDialogPane2>` vtable `0x0061fed8`, stores a member target (`sub_52B090` or `sub_52B1D0`), zero this-adjustment, object pointer `this`, then calls `sub_54B720`.

Read-only generated lead:

- `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` currently has validator header `validator-command-id: 000000004924`, `validator-refreshed-at: 2026-07-02T19:12:14-04:00`.
- It contains only scalar deleting destructor markers for UID0004EM/UID0004EL and empty emitter markers for UID0000AR/UID0002UW/UID0000AS/UID0002UX. UID0004E6 is absent because its current target has blank `EMITTER_UIDS`.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0004E6 is a source method, not a non-emitting raw helper. | MCP `lookup_funcs 0x0054b720 -> sub_54B720 size 0x24`; normal 15-instruction function with `retn 4`; two direct callers. | Target metadata/status/evidence in `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md`. | incorporate | applied: target metadata is `88/91`, `EMITTER_UIDS:0000AR`, and target evidence records the modeled `0x24` function, 15-instruction body, and two `sub_52A540` xrefs. |
| Direct owner remains [UID:0000AR] `PrettyButtonControlPane`. | Current target owner, class/file docs, constructor/caller context, class1 offset `+0x124`, and UID0001F9 split route. | Target metadata and class/file support docs. | incorporate | applied: target kept `CANONICAL_OWNER:0000AR`; class/file/parent support docs route UID0004E6 through UID0000AR. |
| Emitter route should be [UID:0000AR], surfacing to [UID:0000MP]. | UID0000AR already emits through UID0000MP; target is reconstructable, average score exceeds C++ gate, and the method has class-owned source. | Target `EMITTER_UIDS`; file/class docs. | incorporate | applied: target `EMITTER_UIDS:0000AR`; file support notes say UID0004E6 emits through UID0000AR into `NexusTK/ui/controls/PrettyButtonControlPane.cpp`. |
| The stored field at `this+0x124` / `this[73]` is an owned zero-argument callback pointer. | Target body loads/stores `+0x124`; caller allocates `PlainMemberFunctionObject0<NewUserDialogPane2>` objects; FunctionObjects docs define `FunctionObject0`. | Target evidence, target/source C++ notes, class method inventory. | incorporate | applied: target and class notes document owned callback storage at `this+0x124` with caller-created zero-argument wrappers. |
| Source-facing field/type should be `FunctionObject0 *m_callback`. | FunctionObjectTemplates/FunctionObject0 docs plus caller concrete wrapper type; base-pointer storage is safer than concrete caller-specific type. | Target C++ and class support notes. | incorporate | applied: formal target C++ uses `FunctionObject0 *callback` and `m_callback`; class/file support docs record the FunctionObjects dependency and field interpretation. |
| Release semantics should be `delete m_callback;`, not a handwritten virtual call. | Disasm uses virtual slot zero with pushed `1`; FunctionObjects scalar-deleting-destructor policy and C++ delete semantics explain the emitted null check and virtual deleting destructor call. | Target C++ recommendation and target evidence. | incorporate | applied: formal target C++ contains `delete m_callback;`; target policy rejects raw virtual-call and `Release(1)` spellings. |
| Source method should return `void` despite decompiler's `int` result. | Callers ignore return; EAX holding assigned argument is compiler residue; setter semantics and name support `void`. | Target C++ recommendation. | incorporate | applied: formal target C++ is `void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)`. |
| Class2 sibling UID0004ED has same body shape at `this+0x128` but no direct xrefs. | MCP `lookup_funcs 0x0054ba00 -> Not a function`; disasm/bytes show analogue; `xrefs_to` zero. | Support comparison note; no target change unless supervisor includes sibling. | already-present | excluded-with-reason: sibling support pages were not edited under this UID0004E6 callback; target evidence preserves the comparison-only note and says UID0004ED remains separate work. |
| UID0001F9 parent remains non-emitting split/index. | Existing parent/report says exact children carry source; UID0004E6 is one exact child. | Support docs; no parent metadata change. | already-present | applied: parent metadata remains `RECONSTRUCTABLE:FALSE` with blank emitter; split row was text-synced to source-ready UID0004E6. |
| Generated `PrettyButtonControlPane.cpp` should gain one UID0004E6 method after callback validation. | Current generated file lacks UID0004E6 because emitter blank; target route through UID0000AR would surface to UID0000MP. | Generated-refresh expectation only; do not edit generated file manually. | incorporate | applied/observed: generated file was not edited manually; after scoped validators and drained queue, `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` header is `validator-command-id: 000000004967` and contains one UID0004E6 `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` body. It also currently contains a UID0004ED sibling body from separate current state; B015 did not edit UID0004ED by-* docs. |

## Positive Evidence Summary

- Current MCP confirms UID0004E6 is an exact modeled function at `0x0054b720`, size `0x24`, not padding or an unmodeled raw tail.
- The body is small, self-contained, and source-shaped: load old member, delete/release old member if non-null, store new argument, return.
- The field offset is exact: `this[73]` is `this+0x124`, matching the current target summary and class1 callback field evidence.
- The two caller sites in `sub_52A540` construct concrete `PlainMemberFunctionObject0` zero-argument callback wrappers and pass them into `sub_54B720`, directly supporting `FunctionObject0 *` as the method parameter.
- [UID:0001WQ] already emits the shared `FunctionObject0` / `PlainMemberFunctionObject0` declarations through [UID:0000JO], so using `FunctionObject0 *` in a PrettyButton method is a project-supported type choice, not a new invented type.
- [UID:0000AR] and [UID:0000MP] already clear the class/source-file route: `PrettyButtonControlPane` is a source class under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, and UID0004E6 is one of its exact method children.
- The class2 analogue bytes are nearly identical, changing only `+0x124` to `+0x128`, reinforcing that this is a normal callback replacement idiom for both styled-button variants.

## Negative Evidence Summary

- Leaving UID0004E6 non-emitting is no longer justified. The prior blocker was callback type/helper naming; current FunctionObjects docs and caller evidence resolve it to `FunctionObject0 *` plus `delete`.
- Routing UID0004E6 directly to [UID:0000MP] instead of [UID:0000AR] would bypass the direct class owner. The method reads `this+0x124` and belongs to the class layout, while UID0000MP is the source file root reached through the class.
- Routing to [UID:0000JO] `FunctionObjects` is wrong. FunctionObjects owns the reusable callback object templates, not the PrettyButton member that stores a callback pointer.
- Routing to [UID:0000AS] `PrettyButtonControlPane2` is wrong. The class2 analogue uses offset `+0x128` and has its own UID0004ED target; UID0004E6 uses class1 offset `+0x124` and has two xrefs from class1 construction sites.
- Routing to CreateUser/NewUser dialog files is wrong. The caller constructs and supplies callback objects, but the called method is a reusable button-control member on `PrettyButtonControlPane`.
- A source body using decompiler syntax such as `(**v3)(v3, 1)` or `this[73] = a2` should be rejected. Those are binary artifacts and raw indexing, not plausible human-written source.
- A source body using concrete `PlainMemberFunctionObject0<NewUserDialogPane2>` as the member type should be rejected. The setter stores a base callback pointer and should accept any `FunctionObject0`-compatible callback object.

## Ranked Ownership Analysis

1. [UID:0000AR] `PrettyButtonControlPane`: accepted.
   Evidence for: current target owner, class docs, exact class1 method inventory, field offset `+0x124`, two direct callers through class1 construction flow, and class1 vtable/source route through UID0000MP.
   Evidence against: final class declaration and complete field list remain below final-audit quality, but that does not block this method-level source route.
   Decision: keep `CANONICAL_OWNER:0000AR` and set `EMITTER_UIDS:0000AR`.

2. [UID:0000MP] `PrettyButtonControlPane.cpp`: accepted as source-file route, rejected as direct canonical owner.
   Evidence for: file root owns the two PrettyButton classes under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
   Evidence against: target is a class method and should route through the direct class page, not skip it.
   Decision: no direct owner change to UID0000MP; generated output reaches UID0000MP through UID0000AR.

3. [UID:0000JO] `FunctionObjects`: rejected as owner.
   Evidence for: provides the callback base/template declarations used by the parameter and concrete caller objects.
   Evidence against: UID0004E6 does not implement FunctionObjects template behavior; it is a PrettyButton member storing a `FunctionObject0 *`.
   Decision: cite FunctionObjects as type support only.

4. [UID:0000AS] `PrettyButtonControlPane2`: rejected for this target.
   Evidence for: sibling body shape at `0x0054ba00` is nearly identical.
   Evidence against: sibling uses different class and offset `+0x128`, is not modeled as this function, and has no direct xrefs. UID0004E6 uses class1 offset `+0x124`.
   Decision: use UID0004ED as comparison support only.

5. CreateUser/NewUser dialog source files: rejected.
   Evidence for: the two xrefs from `sub_52A540` are create-user dialog construction sites.
   Evidence against: callers are consumers/construction sites; class owner, field layout, and source file route belong to `PrettyButtonControlPane`.
   Decision: document caller evidence but do not reroute.

6. UID0001F9 parent aggregate / no-owner / non-emitting: rejected.
   Evidence for: UID0001F9 physically contains this range.
   Evidence against: UID0001F9 is already a non-emitting split/index; exact children carry source ownership. UID0004E6 is exact, reconstructable, and now source-ready enough to emit.
   Decision: no parent aggregate emission; no no-owner/non-emitting disposition.

## Source Placement

Recommended source route is:

`[UID:0004E6] by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md` -> `[UID:0000AR] by-class/PrettyButtonControlPane.md` -> `[UID:0000MP] by-file/PrettyButtonControlPane.md` -> `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

This placement matches the existing PrettyButton split:

- UID0001F9 is the physical split/index parent and remains non-emitting.
- UID0004E6 is the exact source method child.
- UID0000AR is the direct semantic class owner.
- UID0000MP is the file-level source root.
- FunctionObjects is an included/shared utility dependency for `FunctionObject0`, not the source owner.

The method should be placed as an ordinary `PrettyButtonControlPane` member function. It should not be represented as an out-of-line callback factory, ABI thunk, destructor wrapper, free function, or raw helper.

## First-Draft C++ Recommendation

UID0004E6 is eligible for formal first-draft C++ after the accepted callback:

- `RECONSTRUCTABLE:TRUE`.
- Recommended nonblank `EMITTER_UIDS:0000AR`.
- Recommended score `88/91`, average `89.5`, above the current C++ gate.
- Behavior, owner, parameter type, and field role are supported by current MCP and FunctionObjects docs.

Recommended exact formal C++ for the UID0004E6 target:

```cpp
void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
```

Notes for implementation:

- `FunctionObject0` is the accepted zero-argument callback base from [UID:0001WQ]/[UID:00005L].
- `m_callback` is the source-facing member at `this+0x124`.
- `delete m_callback;` represents the null-checked virtual scalar deleting destructor call with flag `1`; do not emit the decompiler virtual-call spelling.
- Do not include a concrete `PlainMemberFunctionObject0<NewUserDialogPane2>` type in the setter signature; that concrete type belongs to caller construction sites.
- Do not force class2 UID0004ED into the same C++ block. If/when accepted, it should receive its own analogous `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` body using its `+0x128` field.

## Recommended Target Doc Changes

For `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md` / [UID:0004E6]:

- Change metadata from `COMPLETION:84`, `CONFIDENCE:88`, blank `EMITTER_UIDS` to `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:0000AR`.
- Keep `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`.
- Expand the item summary to record the current MCP session `b011_0004EC_20260702`, `sub_54B720` size `0x24`, 15-instruction body, two xrefs at `0x52a907` and `0x52a9b0`, `this+0x124` old-callback load/store, virtual slot-zero delete with flag `1`, and `FunctionObject0 *` source type.
- Replace the current C++ policy blocker text with a source-ready note: this is `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` and source C++ should use `delete m_callback; m_callback = callback;`.
- Insert the formal C++ block from `## First-Draft C++ Recommendation`.
- Preserve rejected alternatives: no FunctionObjects owner, no CreateUser owner, no class2 owner, no parent aggregate emission, no decompiler virtual-call source, no concrete caller-specific template parameter type.
- Add caller evidence from `sub_52A540`: two concrete `PlainMemberFunctionObject0<NewUserDialogPane2>` allocations with member targets `sub_52B090` and `sub_52B1D0` immediately before calls to `sub_54B720`.
- Add boundary evidence: seven `0xcc` bytes at `0x0054b719-0x0054b720`; byte sequence ends at `0x0054b744`; successor `0x0054b744-0x0054b750` is padding already tracked by the parent.

## Recommended Support Doc Changes

For `by-class/PrettyButtonControlPane.md`:

- Update the method inventory row for UID0004E6 from "C++ blank pending callback type" to source-ready `SetCallback(FunctionObject0 *callback)` behavior.
- Document member `m_callback` at `+0x124` as an owned `FunctionObject0 *` zero-argument callback slot, with current evidence that destructor body UID0004E4 releases the same callback field and UID0004E6 replaces it.
- If metadata changes are accepted, raise support score only if the supervisor wants a targeted bump; a conservative recommendation is `88/90` from current `87/89` because one major class-level callback blocker is resolved, but final class layout/resource names remain below final-audit quality.

For `by-file/PrettyButtonControlPane.md`:

- Update the executable split inventory/source-shape notes so UID0004E6 is no longer a blank-emitter source method. It should emit one `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` body through UID0000AR.
- Keep the source root `NexusTK/ui/controls/PrettyButtonControlPane.cpp` unchanged.
- Add or sync the FunctionObjects dependency note: PrettyButton source uses `FunctionObject0` from the shared [UID:0000JO]/[UID:0001WQ] callback utility declarations.
- If metadata changes are accepted, a conservative support score recommendation is `88/90` from current `87/89`, for the same reason as the class page.

For `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` / [UID:0001F9]:

- No metadata change is required. It should remain `RECONSTRUCTABLE:FALSE`, blank emitter, and non-emitting split/index.
- Optional text-only sync: update the UID0004E6 split row from generic "Callback replacement" to source-ready "`PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)`; emits through UID0000AR".

For `by-memory/0x0054ba00-0x0054ba24.PrettyButtonControlPane2SetCallback.md` / [UID:0004ED]:

- Do not edit during UID0004E6 callback unless the supervisor explicitly includes the sibling. It is a separate class2 target with no direct xrefs in current MCP.
- If included later, the same type/source-shape evidence supports an analogous `PrettyButtonControlPane2::SetCallback(FunctionObject0 *callback)` body using its `+0x128` callback field, but that should be verified under its own target callback/report lane.

For `by-class/PrettyButtonControlPane2.md`:

- No required UID0004E6 change. Optional note only if UID0004ED is handled later.

For `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` and `by-memory/0x00622378-0x0062241c.PrettyButtonControlPane2VtableData.md`:

- No metadata or source-route change is required. UID0004E6 is not a vtable slot in UID0002UW; it is called directly from construction code. Vtable docs remain useful ownership support only.

For generated output and coverage:

- Do not manually edit generated files or coverage reports.
- After implementation validators, expect `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` to include one UID0004E6 method body and no duplicate body from UID0004ED unless the sibling is separately accepted.
- Validator-owned generated reports/tracker rows should refresh from source metadata after scoped validators and eventual supervisor `execute_report`; B015 should not edit them manually.

## Score And Metadata Recommendation

Target UID0004E6:

- `COMPLETION`: `84 -> 88`.
- `CONFIDENCE`: `88 -> 91`.
- `CANONICAL_OWNER`: keep `0000AR`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: blank -> `0000AR`.
- `EMITTER_POSITION_OPTIONAL`: keep blank.

Rationale:

- Completion rises because the remaining blocker in the current target text is resolved: callback type, ownership helper/source spelling, caller reachability, field role, and formal C++ are now implementation-ready.
- Confidence rises because current MCP confirms exact function shape, bytes, xrefs, caller construction, and sibling analogue, while FunctionObjects docs supply the callback base type.
- Score should not exceed low 90s because final full `PrettyButtonControlPane` class layout, resource constants, other method names, and complete header/source declaration order remain below final-audit quality.
- The target is now above the formal C++ gate once emitter UID0000AR is added: `(88 + 91) / 2 = 89.5`.

Support score recommendations:

- `by-class/PrettyButtonControlPane.md`: optional `87/89 -> 88/90` if callback field/type/source-ready method notes are incorporated.
- `by-file/PrettyButtonControlPane.md`: optional `87/89 -> 88/90` if generated source route/source dependency notes are incorporated.
- UID0001F9 parent: no score/metadata change required.
- UID0004ED sibling: no score/metadata change under this UID0004E6 callback unless separately included.
- Vtable data pages UID0002UW/UID0002UX: no score/metadata change required.

## Open Questions With Attempted Resolution

- Callback type: resolved as `FunctionObject0 *`. Evidence checked: FunctionObjectTemplates formal declaration, FunctionObject0 class doc, caller allocation/decompile, and target body's virtual delete semantics. Score/C++ impact: clears emitter and C++ blocker.
- Field name: resolved as inferred `m_callback`. Evidence checked: offset `+0x124`, destructor body release of same field, target replacement body, and class purpose. Exact original spelling is not proven, but `m_callback` is source-grade and more defensible than raw offset names. Score/C++ impact: safe enough for first-draft method body.
- Release helper name: resolved as `delete`, not a named helper. Evidence checked: pushed scalar-delete flag `1` and FunctionObjects scalar destructor policy. Score/C++ impact: avoids decompiler-shaped virtual call.
- Return type: resolved as `void`. Evidence checked: callers ignore return, setter semantics, and compiler residue in `eax`. Score/C++ impact: first-draft C++ should not expose a fake return value.
- Sibling UID0004ED: resolved as comparison-only for this report. Evidence checked: same bytes with `+0x128`, no direct xrefs, not IDA-modeled. Score/C++ impact: supports confidence for UID0004E6 but does not require sibling edit in this callback.
- Source placement: resolved through UID0000AR/UID0000MP. Evidence checked: class/file docs, parent split report, current xrefs, and FunctionObjects dependency distinction. Score/C++ impact: target can emit without rerouting parent/sibling/support data.

## Validator Results

No validators were run during this report-only assignment. No scoped file validation is appropriate until the supervisor accepts the report and sends an implementation callback. No `execute_report`, dry-run/probing execute-report variant, registry lifecycle command, archive command, or manual report move was run.

Callback validators run after acceptance:

- `python .\tools\validator.py --mode file --file by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`, `command_id: 000000004965`, `command_timestamp: 2026-07-03T01:54:06-04:00`; registered completion `88`, confidence `91`, emitter `0000AR`, and C++ block.
- `python .\tools\validator.py --mode file --file by-class/PrettyButtonControlPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`, `command_id: 000000004966`, `command_timestamp: 2026-07-03T01:54:25-04:00`.
- `python .\tools\validator.py --mode file --file by-file/PrettyButtonControlPane.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`, `command_id: 000000004967`, `command_timestamp: 2026-07-03T01:54:25-04:00`.
- `python .\tools\validator.py --mode file --file by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`, `command_id: 000000004968`, `command_timestamp: 2026-07-03T01:54:25-04:00`.
- All four file validators reported `generated_refresh: deferred` and projected stats updates. Queue status command `000000004971` at `2026-07-03T01:55:38-04:00` showed zero queued/processing generated refresh jobs. Generated source `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` refreshed to `validator-command-id: 000000004967`, `validator-refreshed-at: 2026-07-03T01:54:25-04:00`, matching the by-file validator that drives that generated source.

## Changed Files

Created report-only artifact and callback edits:

- `tools/leaser/Agents/Agent-B015/research/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md`
- `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`

No generated files, coverage-report files, project-level generated files, validator state, supervisor ledgers, lifecycle state, archives, or tool state were edited by hand. Scoped validators updated validator-owned generated/projected state.

## Implementation Tracking Checklist

- [x] Update `by-memory/0x0054b720-0x0054b744.PrettyButtonControlPaneSetCallback.md` metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`, blank `EMITTER_POSITION_OPTIONAL`. Applied in target header; validator `000000004965` confirmed completion/confidence/emitter/C++ registry updates.
- [x] Update UID0004E6 target evidence with live MCP session `b011_0004EC_20260702`, health state, `sub_54B720` size `0x24`, 15-instruction disassembly, decompile behavior, `this+0x124` old/new callback storage, xrefs `0x52a907` and `0x52a9b0`, caller construction, and boundary bytes. Applied in target `Evidence`.
- [x] Replace UID0004E6 blocker wording with source-ready `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` semantics. Applied in target `Ownership And C++ Policy`.
- [x] Insert formal C++ into UID0004E6:

```cpp
void PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)
{
    delete m_callback;
    m_callback = callback;
}
```

- [x] Preserve negative evidence in UID0004E6: reject FunctionObjects as owner, CreateUser/NewUser dialog as owner, PrettyButtonControlPane2 as owner, UID0001F9 aggregate emission, decompiler virtual-call source, fake `int` return, and concrete caller-specific template member type. Applied in target `Ownership And C++ Policy`.
- [x] Update `by-class/PrettyButtonControlPane.md` method inventory and class notes for UID0004E6 as source-ready `SetCallback(FunctionObject0 *callback)`, field `m_callback` at `+0x124`, and optional support score `88/90` if accepted. Method/child inventory and evidence notes updated; optional support score excluded because the callback accepted only the target score disposition.
- [x] Update `by-file/PrettyButtonControlPane.md` split/source-output notes so UID0004E6 emits through UID0000AR into `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; add FunctionObjects dependency note; optional support score `88/90` if accepted. Applied; optional support score excluded because the callback accepted only the target score disposition.
- [x] Leave UID0001F9 parent metadata unchanged; optionally sync its UID0004E6 split row only if supervisor includes parent support sync. Parent metadata unchanged; split row and behavior note synced as support documentation.
- [x] Leave UID0004ED sibling unchanged unless supervisor explicitly includes it; if included later, verify/report it as separate class2 callback work. No UID0004ED by-* files were edited.
- [x] Leave UID0002UW/UID0002UX vtable support docs unchanged unless supervisor requests a cross-reference note; no metadata/source-route change is needed there. No vtable docs were edited.
- [x] Run scoped validators after implementation callback for each edited by-* doc, at minimum UID0004E6 target plus any edited class/file/support docs. Ran validators `000000004965`, `000000004966`, `000000004967`, and `000000004968`; all exited `0` with `ok: 1`.
- [x] After validators, inspect `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` freshness and confirm UID0004E6 emits exactly one `PrettyButtonControlPane::SetCallback(FunctionObject0 *callback)` body with no duplicate UID0004ED body unless sibling work was separately accepted. Inspected after queue drain: header `validator-command-id: 000000004967`, refreshed at `2026-07-03T01:54:25-04:00`; UID0004E6 body appears once. The generated file also currently contains a UID0004ED sibling body from separate current state; B015 did not edit or validate UID0004ED by-* docs.
- [x] Update this report's Claim And Incorporation Ledger and checklist during callback with `applied`, `already-present`, or `excluded-with-reason` states and concrete validator/generated proof. Applied in this ledger/checklist.
- [x] Do not edit generated files, manual coverage reports, project-level generated reports, validator state, supervisor ledgers, lifecycle/archive state, or run any `execute_report` variant. Complied; only scoped file validators and queue status were run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004995","destination_path":"executed-b-agent-research/B015/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0004E6-PrettyButtonControlPaneSetCallback-source-quality.md","timestamp":"2026-07-03T02:26:05-04:00","uid":"0004E6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
