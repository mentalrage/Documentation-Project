# 0004CC IMEPaneSetFocusPane Source-Quality Report

** TARGET-REPORT-UID:0004CC **
** AUTHOR-AGENT-ID:BENCH-MEDIUM **
** BENCHMARK-REASONING:medium **

## Current Target State

- Target: [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Current metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current summary: exact `IMEPane::SetFocusPane` split child; maintains `focusPaneList` and `focusPaneCount` for text controls and self-save/text-box focus registration.
- Current owner route in docs: [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` reports [UID:0004CC] as `non-emits`; `auto-generated/-ag-research-tracker.md` lists [UID:0004CC] at `82/89`, average `85.5`, reconstructable, blank emitters; `auto-generated/NexusTK/input/IMEPanes.cpp` contains the `IMEPane` class shell and `void SetFocusPane(Pane *pane);` declaration, but no [UID:0004CC] method body.
- Starting blank-emitter/no-code disposition is no longer justified. Current IDA MCP and support docs now provide enough function, caller, field, `List`, and source-route evidence to populate first-draft formal C++.

## Evidence Checked

- IDA MCP endpoint/session:
  - JSON-RPC endpoint `http://127.0.0.1:13337/mcp`.
  - `initialize` returned server `ida-pro-mcp` protocol `2025-06-18`.
  - `idb_list` returned active database session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, owned/adopted `true`, PID/worker PID `14860`, `is_analyzing:false`.
  - `server_health` for `supervisor_resume_20260629` returned `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Target MCP checks:
  - `lookup_funcs` on `0x004e80a0` returned `sub_4E80A0`, size `0x6b`.
  - `lookup_funcs` on `0x004e810b` and `0x004e8110` returned `Not a function`, confirming the target half-open end and separation from the raw focus-caret helper.
  - `lookup_funcs` on neighbors returned `sub_4E8000` size `0x98` at `0x004e8000` and `sub_4E81A0` size `0x5` at `0x004e81a0`.
  - `analyze_function 0x004e80a0` returned prototype `void __thiscall(_DWORD *this, int, char)`, size `107`, callers `sub_58DCE0`, `sub_58E140`, `sub_58EA80`, `sub_595390`, xrefs at `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, `0x00595463`, no strings, no constants, and no direct callees because all `List` operations dispatch through the embedded list vtable.
  - `disasm 0x004e80a0` returned 39 instructions. It reads `[ebx+0x110]`, iterates backward over `[ebx+0x104]`, calls list vtable slot `+0x10` to get an element, compares the stored pane pointer to argument 0, calls list vtable slot `+0x1c` with `(index, 1)` to remove a match, then when argument 1 is nonzero and pane is non-null calls list vtable slot `+0x18` with `(1, &pane)` to append one pointer.
- Caller MCP checks:
  - `search_text sub_4E80A0` scoped to `0x0058dce0-0x00595500` returned exactly four rendered-listing hits: `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, `0x00595463`.
  - `analyze_function 0x0058dce0` identified the TextEditPane constructor family and listed `sub_4E80A0` among callees.
  - `disasm 0x0058dce0` around offset 270 proved the constructor path tests editor flag bit `0x04`, calls `sub_544EA0(this, 1)`, loads `unk_69B458`, pushes `1` then `this`, and calls `sub_4E80A0` at `0x0058e0d9`.
  - `analyze_function 0x0058e140` proved the TextEditPane destructor path calls `sub_4E80A0(g_pIMEPane, this, 0)` at `0x0058e20c` after freeing text-edit child objects.
  - `analyze_function 0x0058ea80` proved the editable/active mode setter calls `sub_544EA0(this, 1)` and `sub_4E80A0(g_pIMEPane, this, 1)` on the enabled path, and `sub_544EA0(this, 0)` and `sub_4E80A0(g_pIMEPane, this, 0)` on the disabled or alternate path.
  - `analyze_function 0x00595390` proved the TextBoxPane constructor calls base TextEditPane construction, optional text setup, then when bit `0x04` is being forced on calls `sub_544EA0(this, 0)` and `sub_4E80A0(g_pIMEPane, this, 0)` at `0x00595463`.
- Current docs read:
  - Target page [UID:0004CC].
  - [UID:00006H] `by-class/IMEPane.md`.
  - [UID:0000K5] `by-file/IMEPanes.md`.
  - [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
  - Neighbor exact pages [UID:0004CA] constructor, [UID:0004CB] ordinary destructor, [UID:0004CD] `IsIMESupported`.
  - [UID:0000R7] `by-global/g_pIMEPane.md` and [UID:0001PS] `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`.
  - [UID:000079] `by-class/List.md`, [UID:00022S] `ListCoreMethods`, and [UID:0000KS] `by-file/List.md`.
  - Generated lead files `auto-generated/NexusTK/input/IMEPanes.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md`.
- Existing reports searched/read as leads:
  - Search terms included `0004CC`, `0x004e80a0`, `0x004e810b`, `IMEPaneSetFocusPane`, `SetFocusPane`, `IMEPane`, and `IMEPanes`.
  - Matching executed reports included `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`, `executed-b-agent-research/B008/0002RV-TextBoxPaneConstructor-source-quality.md`, `executed-b-agent-research/B004/0001JO-TextBoxPane-source-quality.md`, and `executed-b-agent-research/B014/00010A-ClanStatusPaneConstructor-source-quality.md`.
- Negative checks:
  - No validator commands were run.
  - No IDA DB write/save calls were made.
  - No broad MCP analysis or unbounded searches were used.
  - No Wave2/Wave3 stale material was used as authority; generated output and old reports were lead material only.

## Positive Evidence

- IDA MCP proves this is an exact modeled function at `0x004e80a0` with size `0x6b` and no overlap with `0x004e8110`.
- The callee body is entirely about the embedded `List` at `IMEPane +0x104`: it reads the count field at `+0x110`, iterates from last to first via `List::GetElementAt`, removes an existing matching pane through `List::RemoveAt(index, 1)`, and optionally appends one pane pointer through `List::Append(1, &pane)`.
- Current `List` docs provide accepted source-facing names for vtable slot `+0x10` as `GetElementAt`, slot `+0x18` as `Append`, and slot `+0x1c` as `RemoveAt`.
- Current `IMEPane` docs already document `focusPaneList +0x104` and `focusPaneCount +0x110`; `focusPaneCount` is the embedded `List::m_count` field, not an unrelated counter.
- The four callers are all text-entry focus lifecycle paths:
  - TextEditPane constructor/register path uses third argument `1`.
  - TextEditPane destructor/unregister path uses third argument `0`.
  - TextEditPane editable/active mode setter uses both `1` and `0`, paired with `SetFocusRegistration`.
  - TextBoxPane constructor path uses `0` while forcing editor flag bit `0x04`, also paired with `SetFocusRegistration(false)`.
- [UID:0000R7] and [UID:0001PS] document `g_pIMEPane` as the active root IME singleton and list the same text-entry callers/read sites.
- [UID:00006H] already declares the method in the `IMEPane` shell, and [UID:0000K5] is already a valid emitting file route (`NexusTK/input/IMEPanes.cpp`).
- The score gate is satisfied after this pass: current target average is already `(82 + 89) / 2 = 85.5`, and the direct owner [UID:00006H] is `88/91` with emitter [UID:0000K5]. With a confirmed emitter route, [UID:0004CC] is eligible for formal first-draft C++.

## Negative Evidence

- Leaving `EMITTER_UIDS` blank is now stale. The target has a valid class owner with an active class-shell emitter and the target's method body is self-contained.
- Leaving the C++ block blank is no longer supported by a target-specific no-code proof. Unlike [UID:00031G], this target is an IDA-modeled function with four direct callers and clear source-shaped behavior.
- The current class-shell declaration `void SetFocusPane(Pane *pane);` is incomplete because IDA and all callers prove a second boolean/char argument.
- TextEditPane, TextBoxPane, and self-save callers are consumers. Their xrefs explain when the list is updated, but they do not own this method body or the embedded focus list.
- `InputMan` is rejected as owner/emitter for this method. It produces Win32/IMM events; it does not own the pane-side root singleton, `focusPaneList`, or text-entry focus registration list.
- A standalone helper/global/source file is rejected. The body uses only `IMEPane` fields and shared `List` APIs, and current source structure already routes `IMEPane` methods through [UID:00006H] -> [UID:0000K5].
- Exact original source spelling for the second parameter is not recovered. This is a confidence cap, not a C++ blocker, because caller behavior strongly supports the descriptive source-facing role.

## Heuristic / Inference Reanalysis

- Method name: `IMEPane::SetFocusPane` remains the best source-facing name. It is already used consistently by `IMEPane`, `IMEPanes`, `g_pIMEPane`, TextBoxPane reports, and generated class shell. `RegisterFocusPane` is too narrow because `false` removes/unregisters without adding. `RemoveFocusPane` is wrong for the true path. `SetActivePane` is too broad and conflicts with separate `activeChildPane +0xfc`.
- Second parameter: recommend `bool trackFocus` for the formal body and support docs. Evidence: true paths pair with `SetFocusRegistration(true)` and append the pane; false paths remove existing entries and skip append. `addToList`, `registerPane`, or `enable` would also describe part of the behavior, but `trackFocus` best captures that the root IME pane should track the pane as the most recent focused text-entry pane. The report should document this as inferred/descriptive, not original-symbol proof.
- Local names: use `index` and `entry` rather than decompiler temporaries. `entry` is a `Pane **` because `List::GetElementAt` returns a pointer to a stored fixed-width element, and this list stores pane pointers as 4-byte elements.
- List-member interpretation: `focusPaneList` is the embedded `List` object starting at `+0x104`; `focusPaneCount` at `+0x110` is the list's count field. The separate documented alias is useful for reconstruction, but support docs should note it is the embedded list count rather than independent state.
- Source shape: a late-1999/early-2000s C++ implementation would be a small method in `IMEPanes.cpp` using the existing `List` virtual API, not hand-written vtable calls or decompiler labels. The remove-before-append pattern should be preserved because it de-duplicates and moves a re-registered pane to the end of the focus list.
- Behavior preservation:
  - Remove the first matching existing entry encountered from the end of the list.
  - Do not continue removing duplicates after the first match; the binary breaks after one removal.
  - If `trackFocus` is false, only removal occurs.
  - If `trackFocus` is true but `pane` is null, no append occurs.
  - If the pane is non-null and `trackFocus` is true, append exactly one pointer element.

## Ranked Owner / Source Placement Disposition

1. [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes` is accepted.
   - Evidence for: body uses `IMEPane +0x104/+0x110`; target sits inside `IMEPane` method cluster; class page already documents the method; file page owns pane-side IME singleton/focus-list state; [UID:0000K5] is an emitting file root.
   - Evidence against: none material. Exact second-parameter spelling is inferred, but that does not weaken owner/source placement.
   - Decision: set `EMITTER_UIDS:00006H`; use `EMITTER_POSITION_OPTIONAL` between destructor and raw focus helper if position ordering is applied by supervisor.
2. [UID:0000K5] direct file ownership is rejected as the canonical owner but remains the final file route.
   - Evidence for: `IMEPanes.cpp` is the final source file.
   - Evidence against: the semantic owner is the `IMEPane` class; by-structure says method bodies should attach to the class when supported.
   - Decision: do not change `CANONICAL_OWNER`; route through the class emitter.
3. TextEditPane/TextBoxPane/self-save caller owners are rejected.
   - Evidence for: all direct callers are text-entry lifecycle paths.
   - Evidence against: they only pass their pane pointer to `g_pIMEPane`; they do not own the root list or method body.
   - Decision: consumer-only support evidence.
4. `InputMan` is rejected.
   - Evidence for: related subsystem.
   - Evidence against: no direct owner evidence for the focus list; existing file split keeps Win32/IMM event production separate from pane-side IME display/focus state.
   - Decision: no ownership or emitter route.

## Score / Metadata Disposition

- Recommended metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00006H` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:00006H`
  - `EMITTER_POSITION_OPTIONAL:` use a class-child order after [UID:0004CB] and before [UID:00031G] if the supervisor applies ordering; otherwise blank is acceptable because the class `[[CHILDREN]]` route already exists.
- Score rationale:
  - Completion should rise from `82` to `88` because current MCP proves exact function size, complete internal behavior, four caller families, boolean parameter meaning, `List` slot names, owner/emitter route, and formal C++ readiness.
  - Confidence should rise from `89` to `91` because direct binary evidence matches current class/file/global/List docs. Keep below `95` because exact original spelling of the boolean parameter and the source-level public API spelling are inferred/descriptive, and the current `IMEPane` class shell still needs a support-doc signature correction.
- Current blank emitter/no-code disposition should be historicalized as a split-callback staging state from 2026-06-30, not retained as a current technical blocker.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, average score is above 85, the owner and route are confirmed, and the method body uses accepted `IMEPane`/`List` names with a small inferred parameter-name cap.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0004CC]:

```cpp
void IMEPane::SetFocusPane(Pane *pane, bool trackFocus)
{
    for (int index = focusPaneCount - 1; index >= 0; --index) {
        Pane **entry = static_cast<Pane **>(focusPaneList.GetElementAt(index));
        if (*entry == pane) {
            focusPaneList.RemoveAt(index, 1);
            break;
        }
    }

    if (trackFocus && pane) {
        focusPaneList.Append(1, &pane);
    }
}
```

Required support C++ declaration sync in [UID:00006H] `IMEPane` class shell:

```cpp
void SetFocusPane(Pane *pane, bool trackFocus);
```

Reason this preserves behavior:
- Backward iteration from `focusPaneCount - 1` matches the binary.
- `GetElementAt(index)` maps to list vtable slot `+0x10`.
- `RemoveAt(index, 1)` maps to list vtable slot `+0x1c`.
- `Append(1, &pane)` maps to list vtable slot `+0x18`.
- The false/null append guards match `cmp arg_4, 0` and `cmp arg_0, 0`.

No-code proof is rejected: this is a modeled function with direct callers and a valid emitter route. Blank C++ would now be a stale empty-emitter artifact.

## Implementation-Ready Target / Support Doc Changes

- Target [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`:
  - Change `COMPLETION` to `88`.
  - Change `CONFIDENCE` to `91`.
  - Set `EMITTER_UIDS:00006H`.
  - Insert the formal C++ body above.
  - Update Status to say the target is now an emitting `IMEPane` child routed through [UID:00006H] -> [UID:0000K5], superseding the 2026-06-30 split-callback blank-C++ staging note.
  - Add MCP evidence: session `supervisor_resume_20260629`, server health OK, `lookup_funcs` size `0x6b`, `analyze_function` prototype/callers/xrefs, `disasm` list-slot behavior, and exact caller semantics.
  - Add a note that `focusPaneCount +0x110` is the embedded `List` count field for `focusPaneList +0x104`.
  - Add a note that `trackFocus` is an inferred/descriptive source-facing parameter name.
- Support [UID:00006H] `by-class/IMEPane.md`:
  - Change declaration from `void SetFocusPane(Pane *pane);` to `void SetFocusPane(Pane *pane, bool trackFocus);`.
  - In Method Notes, mark `SetFocusPane` as `88/91`, formal C++ populated, and describe remove-before-optional-append behavior.
  - In Observed State, clarify `focusPaneCount +0x110` is the embedded `List::m_count` alias.
- Support [UID:0000K5] `by-file/IMEPanes.md`:
  - In the `IMEPane` row, add exact emitting SetFocusPane child [UID:0004CC].
  - Add an Evidence/Changes bullet recording current MCP proof and the route through `IMEPane`.
- Support [UID:000189] aggregate:
  - Update covered-range and split/source-placement rows for [UID:0004CC] to `88/91`, formal C++ populated, and note caller/callee/boolean evidence.
- Optional support [UID:0000R7] / [UID:0001PS]:
  - Existing focus-list caller details are already sufficient; no required edit unless supervisor wants the formal `trackFocus` parameter wording mirrored.
- Validator expectation after implementation:
  - Run scoped validator for target and touched support docs from `source-3/project-documentation` only after edits are accepted. No validator was run during this benchmark because validators are banned.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0004CC] is a modeled function `sub_4E80A0` at `0x004e80a0`, size `0x6b`, ending before non-function `0x004e810b`/`0x004e8110`. | High | MCP `lookup_funcs`, `disasm`. | Target Evidence/Status | incorporate | proposed |
| C02 | The body removes one existing pane entry from the embedded focus list by backward search, then optionally appends the pane. | High | MCP `analyze_function`, `disasm`. | Target Behavior/Reconstruction Notes/C++ | incorporate | proposed |
| C03 | `focusPaneList +0x104` and `focusPaneCount +0x110` are sufficient source-facing names; `focusPaneCount` is the embedded `List::m_count` field. | High | Target docs, [UID:00006H], [UID:000079], disasm offsets. | Target and class Observed State | incorporate | proposed |
| C04 | List vtable slots map to accepted `GetElementAt`, `Append`, and `RemoveAt` source APIs. | High | [UID:000079] `List`, [UID:00022S], target disasm slot offsets. | Target Reconstruction Notes/C++ | incorporate | proposed |
| C05 | Four direct callers are text-entry focus lifecycle paths and prove the boolean parameter semantics. | High | MCP caller analysis and `search_text`. | Target Evidence/Direct Xrefs | incorporate | proposed |
| C06 | `trackFocus` is the best inferred second-parameter name; exact original spelling is not recovered. | Medium-high | Caller true/false behavior and paired `SetFocusRegistration`. | Target Heuristic Notes, class declaration sync | incorporate | proposed |
| C07 | Owner remains [UID:00006H] and emitter route should be [UID:00006H] -> [UID:0000K5]. | High | Current class/file docs and IDA field evidence. | Target metadata, class/file/aggregate support | incorporate | proposed |
| C08 | TextEditPane/TextBoxPane/InputMan are rejected as owners; they are consumers or neighboring producer subsystems. | High | Caller docs, [UID:0000K5] file boundary, MCP xrefs. | Target Ranked Ownership/Negative Evidence | incorporate | proposed |
| C09 | Formal C++ is now safe and blank C++ is stale. | High | Target score gate, owner/emitter gate, complete function behavior. | Target C++ block and status | incorporate | proposed |
| C10 | Raise score to `88/91`, set `EMITTER_UIDS:00006H`, keep canonical owner and reconstructable unchanged. | Medium-high | Evidence completeness and by-structure gate. | Target metadata/score rationale | incorporate | proposed |

## Unchecked Implementation Tracking Checklist

- [ ] Supervisor validation required before implementation.
- [ ] Update target [UID:0004CC] metadata to `COMPLETION:88`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`; leave `CANONICAL_OWNER:00006H` and `RECONSTRUCTABLE:TRUE`.
- [ ] Insert exact formal `IMEPane::SetFocusPane(Pane *pane, bool trackFocus)` C++ into the target `RECONSTRUCTION_CPP CODE` block.
- [ ] Replace stale target no-code/split-callback wording with current emitting route and MCP-backed behavior.
- [ ] Add target evidence for MCP session `supervisor_resume_20260629`, function size, disassembly behavior, caller inventory, and negative owner checks.
- [ ] Update [UID:00006H] `IMEPane` class declaration to include the boolean parameter and mark [UID:0004CC] as formal C++ populated.
- [ ] Clarify in [UID:00006H] that `focusPaneCount +0x110` is the embedded `List` count alias.
- [ ] Update [UID:0000K5] `IMEPanes` source route with [UID:0004CC] as an emitting child.
- [ ] Update [UID:000189] aggregate covered range/source-placement row for [UID:0004CC] to `88/91`, formal C++ populated.
- [ ] Preserve rejected alternatives: TextEditPane/TextBoxPane/InputMan/direct-file-only/no-code routes.
- [ ] Preserve the inferred-name cap for `trackFocus`.
- [ ] Do not edit generated files or coverage reports manually; expect validator-generated memory coverage/research tracker to refresh after accepted scoped validation.
- [ ] Required validators after accepted implementation, not during this benchmark: scoped file validator for each touched target/support by-* doc, with generated refresh/header check if generated C++ matters.

## File Modification Confirmation

For this benchmark pass, the only file intentionally created/modified is:

`E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\benchmark-medium-0004CC-IMEPaneSetFocusPane-source-quality.md`

No target/support by-* docs, generated files, coverage reports, project-level files, validator/tool state, supervisor ledgers, queues, archives, lock files, `goal.md`, `notes.md`, or IDA DB were modified. No validator commands were run.

token usage: unavailable
