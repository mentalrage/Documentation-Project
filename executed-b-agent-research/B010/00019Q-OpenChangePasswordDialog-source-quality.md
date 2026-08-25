** TARGET-REPORT-UID:00019Q **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00019Q OpenChangePasswordDialog Source-Quality Report

Assignment: `B010-report-00019Q-OpenChangePasswordDialog-source-quality-20260627`
Agent: `Agent-B010`
Mode: report-only research first
Target: [UID:00019Q] `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`

## Recommendation

Keep [UID:00019Q] as a retained `MainMenuPane.cpp` launcher owned/emitted through [UID:0000L0] `MainMenuPane`, and populate first-draft formal C++ as a file-local `static void OpenChangePasswordDialog()` opener. The earlier blank-C++ conclusion is superseded by this rejection amendment: current MCP evidence still does not prove an ABI return consumer, but that is positive evidence against a source-facing pointer-return API, not a reason to omit code. The active duplicate menu path ignores the constructed pointer, and the `ChangePasswordDialogPane` constructor publishes the live singleton through `g_pChangePasswordDialogPane`, so the best source-facing shape is a fire-and-forget opener whose purpose is side-effect construction.

Recommended metadata after implementation:

| Field | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `88` | Current MCP evidence refreshes the exact range, body, padding, xref state, active duplicate case, raw VA/RVA pointer search, singleton publication, and source-facing void opener decision. It also corrects stale current-IDB name wording and resolves the previous formal-C++ blocker. |
| `CONFIDENCE` | `90` | Behavior, owner/emitter route, and void opener source shape are strong. Confidence remains capped because no live caller/callback table is recovered and the original registration/retention route remains unknown. |
| `CANONICAL_OWNER` | `0000L0` | The helper is a main-menu/account launcher, not a `ChangePasswordDialogPane` method. |
| `RECONSTRUCTABLE` | `TRUE` | It is real source-authored project code with exact body evidence. |
| `EMITTER_UIDS` | `0000L0` | If later emitted, it belongs with the other retained `MainMenuPane.cpp` launch helpers. |
| Formal C++ | Populate first-draft formal C++. | Use the exact formal insertion text in the `First-Draft C++ Recommendation` section below. |

Do not move this target to [UID:0000I3] `ChangePasswordDialogPane`, [UID:00001L] `ChangePasswordDialogPane`, MemoryMan, runtime/library, no-owner, or a generated-only bucket. Do not emit it as `ChangePasswordDialogPane *OpenChangePasswordDialog()` unless a future caller/callback route proves a returned pointer contract.

## IDA MCP Status

Live MCP was available and used. No offline-only conclusion is used.

| Check | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` responded to `initialize` and `tools/list`. |
| Original report database | `idb_list` returned session `398b87c1`, `NexusTK.exe.i64`, backend `worker`, active, not analyzing, PID/worker PID `23700`. |
| Health | `server_health` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`. |

### 2026-06-27 Rejection-Amendment MCP Recheck

The rejection-amendment pass used current IDA MCP session `875bf182`. The server was healthy: `server_health` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Additional current-session evidence checked for the rejected blank-C++ conclusion:

- `lookup_funcs` reports `0x004f9060` as `___std_parallel_algorithms_hw_threads@0_0`, size `0x54`; `0x004f90b4` is not a function; neighboring retained helpers remain `0x004f8f10` size `0x85`, `0x004f8fa0` size `0xb5`, `0x004f90c0` size `0x7f`, `0x004f9140` size `0x7f`, and `0x004f91c0` size `0xbd`.
- `analyze_function 0x004f9060 include_asm=true` reports prototype `__int16 *()`, size `84`, no callers, callees only `sub_4F4AA0` and `sub_4FDD40`, and the exact `push 26Ch`, allocator call, null branch, `ecx = eax`, constructor call, and plain `retn` epilogue. `0x54` / 84 and `0x26c` / 620 were verified with `tools/int_convert.py`.
- `analyze_function 0x004f7a10` confirms `MainMenuPane::ActivateMenuItem` case `2` directly duplicates the allocation/constructor sequence and then breaks; it does not consume the constructed pointer as a source-level result.
- `analyze_function 0x004fdd40` reports constructor callers `sub_4F7A10` and `___std_parallel_algorithms_hw_threads@0_0`. Its decompilation writes `unk_69B48C = (int)this` at `0x004fdd96` on normal construction and clears the same singleton slot at `0x004fdd9d` on the fallback path.
- `xrefs_to 0x0069b48c` reports exactly five refs: main-menu cleanup read `0x004f69bf`, constructor publish/fallback writes `0x004fdd96`/`0x004fdd9d`, singleton-clear helper `0x005023a0`, and destructor-family clear `0x00502656`.
- `xrefs_to 0x004f9060` still reports zero inbound xrefs, and `find_bytes` patterns `60 90 4F 00` and `60 90 0F 00` still have zero matches. This preserves the callback-route confidence cap but does not block source-shaped formal C++.
- `get_bytes 0x004f9055 size 0x65` confirms the eleven `0xcc` bytes before the helper and the retained helper body beginning at `0x004f9060`.

## Current Target State

Source page state read during this report:

- `COMPLETION:86`, `CONFIDENCE:90`
- `CANONICAL_OWNER:0000L0`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L0`
- Formal `RECONSTRUCTION_CPP CODE` block is blank.
- The page says current IDA name is `OpenChangePasswordDialog` after the C001 refresh.

Current MCP session `875bf182` does not agree with that last point. `lookup_funcs 0x004f9060` reports the old misleading name `___std_parallel_algorithms_hw_threads@0_0`. The implementation should correct the docs to say current live session `875bf182` still reports the runtime-style name, while `OpenChangePasswordDialog_4F9060` remains the source-facing/proposed documentation name. This report does not request any IDA DB rename or save.

## MCP Evidence Summary

### Function And Boundary

`lookup_funcs` in session `875bf182`:

| Query | Result |
| --- | --- |
| `0x004f9060` | function `___std_parallel_algorithms_hw_threads@0_0`, size `0x54` |
| `0x004f90b4` | not a function |
| `0x004f90c0` | successor `sub_4F90C0`, size `0x7f` |
| `0x004f8fa0` | predecessor helper `sub_4F8FA0`, size `0xb5` |
| `0x004f91c0` | later helper `sub_4F91C0`, size `0xbd` |
| `0x004f7a10` | active `MainMenuPane::ActivateMenuItem` body `sub_4F7A10`, size `0x2d9` |
| `0x004fdd40` | `ChangePasswordDialogPane` constructor target `sub_4FDD40`, size `0x720` |
| `0x004f4aa0` | allocation wrapper `sub_4F4AA0`, size `0x14` |

`analyze_function 0x004f9060` reports size `84`, no callers, and only two callees: `sub_4F4AA0` and `sub_4FDD40`.

Decompile:

```cpp
result = (__int16 *)sub_4F4AA0(620);
if ( result )
    return sub_4FDD40(result);
return result;
```

Disassembly confirms the exact shape:

- `0x004f9083`: `push 26Ch`
- `0x004f9088`: `call sub_4F4AA0`
- `0x004f909a`: `test eax, eax`
- `0x004f909c`: null branch
- `0x004f909e`: `mov ecx, eax`
- `0x004f90a0`: `call sub_4FDD40`
- `0x004f90b3`: `retn`

`int_convert` verifies `0x54` is `84` bytes and `0x26c` is `620`.

`get_bytes` verifies the fences:

- `0x004f9055-0x004f9060`: eleven `0xcc` bytes before the helper.
- `0x004f9060-0x004f90b4`: exact 84-byte helper body.
- `0x004f90b4-0x004f90c0`: twelve `0xcc` bytes before `sub_4F90C0`.

### Reachability And Callback Route

Current direct-reference checks:

- `xrefs_to 0x004f9060`: zero xrefs.
- `xref_query 0x004f9060 direction=to`: zero xrefs.
- `xref_query 0x004f9060 direction=both`: only the internal flow from the function start into its next instruction; no inbound route.
- `find_bytes "60 90 4F 00"`: zero loaded VA-literal matches.
- `find_bytes "60 90 0F 00"`: zero loaded RVA-literal matches.

The broad `insn_query` immediate scan over `.text` was not used as proof: the `op_any` query timed out after 60 seconds, and the narrower `op0`/`op1` queries scanned a truncated prefix with no matches. The negative route conclusion rests on successful xref and raw VA/RVA byte checks, not on the timed-out immediate scan.

No callback table, dispatch table, or raw pointer route to `0x004f9060` was recovered in the current MCP pass.

### Constructor And Active Duplicate Path

`xrefs_to 0x004fdd40` reports exactly two constructor call sites:

| Xref | Function |
| --- | --- |
| `0x004f7b49` | active `sub_4F7A10` / `MainMenuPane::ActivateMenuItem` case `2` |
| `0x004f90a0` | this retained helper |

`decompile 0x004f7a10` confirms active case `2` directly duplicates the helper body:

```cpp
case 2:
    v5 = (__int16 *)sub_4F4AA0(620); /*0x4f7b2d*/
    if ( v5 )                         /*0x4f7b41*/
        sub_4FDD40(v5);               /*0x4f7b49*/
    break;                            /*0x4f7b5d*/
```

This proves behavior equivalence to the active menu path, but it does not prove the retained helper's original call route or callback signature.

## Source Placement Decision

Keep the target with [UID:0000L0] `MainMenuPane`.

Rationale:

- The active duplicate path is `MainMenuPane::ActivateMenuItem` case `2`.
- [UID:0000L0] already groups retained login/main-menu launch helpers and explicitly says to keep `OpenChangePasswordDialog_4F9060` there unless a later xref pass proves a callback target owned elsewhere.
- [UID:0000I3] and [UID:00001L] own the constructed dialog implementation, singleton, validation, submit, packet helpers, and reply handling. They do not own this launcher wrapper.
- The helper's only feature-specific callee is the `ChangePasswordDialogPane` constructor; constructor target alone is dependency evidence, not ownership evidence.
- MemoryMan owns `sub_4F4AA0`; this helper only consumes the shared allocator.

## Heuristic / Inference Reanalysis And Validation

This amendment rechecks the exact blocker that caused supervisor rejection: the prior report described a plausible `void` opener but still kept formal C++ blank because the exact original return type was not proven. Under the current B-agent standard, that is incomplete because the report must choose the best source-facing shape when current evidence supports one.

| Issue | Best current inference | Evidence checked | Rejected alternatives | Score/C++ impact |
| --- | --- | --- | --- | --- |
| Current generated/IDA-style name | Use source-facing `OpenChangePasswordDialog` in emitted C++ and keep `OpenChangePasswordDialog_4F9060` only as the address-suffixed alias/support page. | Current `875bf182` `lookup_funcs` still reports `___std_parallel_algorithms_hw_threads@0_0`; body is allocator plus `ChangePasswordDialogPane` constructor, not library/runtime code. | Keep `___std_parallel_algorithms_hw_threads@0_0` in final code; rename/save IDA from this report. | Resolves the placeholder-name blocker for formal C++; no IDA DB edit requested. |
| Source placement | File-local retained helper in [UID:0000L0] `MainMenuPane.cpp`. | Active `MainMenuPane::ActivateMenuItem` case `2` duplicates the same construction; [UID:0000L0] already owns retained launcher family; constructor target and singleton belong to `ChangePasswordDialogPane`. | Move to `ChangePasswordDialogPane.cpp`, MemoryMan, runtime/library, no-owner, generated-only. | Owner/emitter stay `0000L0`; code should emit in the MainMenuPane source output. |
| Return/signature source shape | `static void OpenChangePasswordDialog()`. | Plain `retn`, no stack cleanup, no caller/callback/table route, no returned-pointer consumer, active duplicate ignores constructed pointer, constructor publishes singleton. | `ChangePasswordDialogPane *OpenChangePasswordDialog()` and blank formal C++. | Raises recommended completion to `88`; confidence remains `90` because callback registration is still absent. |
| Retained helper liveness | Real retained project helper with unresolved registration/reachability. | Zero `xrefs_to 0x004f9060`; zero VA/RVA pointer-byte hits; exact function body and padding; duplicate active menu behavior. | Dead/no-owner, covered-by active menu case, or non-reconstructable runtime helper. | Confidence cap only; not a code-entry blocker. |

## Positive Evidence Summary

- Current MCP session `875bf182` confirms an exact modeled `0x004f9060-0x004f90b4` function, size `0x54` / 84 (Verified with `tools/int_convert.py`), with only allocator and `ChangePasswordDialogPane` constructor callees.
- `MainMenuPane::ActivateMenuItem` case `2` performs the same `0x26c` / 620-byte allocation and constructor call and then exits the switch case without consuming the constructed pointer.
- The constructor at `0x004fdd40` publishes the object through `g_pChangePasswordDialogPane` at `0x0069b48c`, and the singleton page documents the matching constructor publish/fallback clear, cleanup read, singleton-clear helper, and destructor-family clear refs.
- [UID:0002Q6] `OpenTransferServerDialog` is the direct nearby precedent that unresolved retained-helper callback registration can be a confidence cap while first-draft formal C++ is still appropriate when the body/source shape is strong. For [UID:00019Q], the source shape is simpler: no argument, plain `retn`, and no return consumer.

## Negative Evidence Summary

- No direct `xrefs_to 0x004f9060` and no raw VA/RVA pointer-byte route were found in current session `875bf182`.
- No caller/callback table proves a pointer-returning source API. This is negative evidence against `ChangePasswordDialogPane *OpenChangePasswordDialog()`.
- No evidence ties the opener to `ChangePasswordDialogPane` as a class method; the class/file own dialog internals and singleton state, while the retained opener is main-menu launch context.
- The current live IDA name remains runtime-like and misleading. It is negative evidence for relying on IDA labels, not evidence against the source-facing opener name.

## First-Draft C++ Recommendation

Insert first-draft formal C++ for [UID:00019Q]. The prior no-code proof is not sufficient under the current B-agent standard because it treated missing exact return proof as a reason to leave code blank while also documenting enough evidence to choose the best source-facing shape.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
static void OpenChangePasswordDialog()
{
    new ChangePasswordDialogPane;
}
```

Source-shape rationale:

- This helper is a no-argument file-local retained launcher with a plain `retn`, not the `__stdcall`/`retn 4` callback shape used by [UID:0002Q6] `OpenTransferServerDialog`.
- Hex-Rays' `__int16 *()` return guess only reflects the final live value left in `EAX`; no caller, callback registration, table route, or ABI consumer uses that value.
- The active `MainMenuPane::ActivateMenuItem` password case allocates `620` bytes, calls the same `ChangePasswordDialogPane` constructor, then breaks without reading the constructor result. That is source-shape evidence for a side-effect opener.
- The `ChangePasswordDialogPane` constructor publishes the live object through `g_pChangePasswordDialogPane` at `0x0069b48c` and has fallback/teardown clear paths. The source-visible result of opening the dialog is the singleton/object lifecycle side effect, not a returned pointer.
- A pointer-returning source API such as `static ChangePasswordDialogPane *OpenChangePasswordDialog()` is less plausible because it would invent a source contract no current consumer uses. It also does not match the active duplicate case, which does not retain or test the object pointer after construction.
- The recommended `void` helper still preserves the exact observed runtime behavior for a source rebuild: allocation uses the project allocator/operator-new path, construction occurs only after a successful allocation, and the constructor owns singleton publication. The fact that machine `EAX` may retain the constructed pointer after a `void` helper is an ignored ABI artifact, not source API evidence.
- This naming/style follows the accepted `MainMenuPane.cpp` retained-helper style: file-local static opener name, no raw address suffix in emitted C++, and no IDA/decompiler labels in final source. The address-suffixed `OpenChangePasswordDialog_4F9060` remains the historical/search alias in the by-global page.

Rejected C++ alternatives:

| Alternative | Rejection reason |
| --- | --- |
| `static ChangePasswordDialogPane *OpenChangePasswordDialog()` | Would hard-code a returned-pointer contract with no current caller, callback table, or active duplicate consumer. Hex-Rays' return type is unconstrained by inbound use. |
| Leave formal C++ blank. | Current evidence is sufficient for a first-draft source-shaped retained opener. Missing callback-route proof is a confidence cap, matching the accepted `OpenTransferServerDialog` precedent, not a formal-code blocker. |
| Put code only in prose or an example section. | Current rules require even first-draft/example code to be supplied as formal `RECONSTRUCTION_CPP CODE` content. |

Remaining confidence cap: no direct helper-entry xref, callback table, raw VA/RVA pointer route, or registration mechanism to `0x004f9060` has been recovered. That cap affects confidence and retained-route notes, not code eligibility or owner/emitter route.

## Support Docs To Update If Accepted

These are implementation checklist targets, not report-only edits.

| File | Required update |
| --- | --- |
| `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md` | Add the 2026-06-27 MCP session `875bf182` evidence above; update current IDA-name wording to `___std_parallel_algorithms_hw_threads@0_0` for this live session; keep proposed/source-facing alias `OpenChangePasswordDialog_4F9060`; update score to `88/90`; insert the formal `static void OpenChangePasswordDialog()` C++ block; preserve the no-xref/no-pointer callback-route cap as confidence rationale, not a no-code blocker. |
| `by-global/OpenChangePasswordDialog_4F9060.md` | Mirror the current-session name correction, void-opener source-shape rationale, rejected pointer-return/blank-C++ alternatives, and support-alias role. Keep this page as an alias/support page with blank formal C++ unless the supervisor explicitly wants duplicate alias emission. Recommended score can rise to `88/90` if the same evidence is incorporated. |
| `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | Sync the [UID:00019Q] row/evidence: current MCP `875bf182` still reports the runtime-style name and no helper-entry route; active `ActivateMenuItem` case `2` duplicates the allocation/constructor path; the exact child now owns first-draft `static void OpenChangePasswordDialog()` C++. No aggregate score or metadata change required. |
| `by-file/MainMenuPane.md` | Add a short distinction from `OpenTransferServerDialog`: transfer has `__stdcall`/`return true`, while password has no stack argument or return consumer and should emit as a file-local `static void OpenChangePasswordDialog()` opener. No score change required. |
| `by-class/MainMenuPane.md` | Add/sync the retained helper inventory with the accepted `static void OpenChangePasswordDialog()` source shape and no-xref/no-pointer cap. No score change required. |
| `by-file/ChangePasswordDialogPane.md` | Sync launcher-path support: constructor xrefs remain active main-menu case `0x004f7b49` plus retained helper `0x004f90a0`; constructor singleton publication supports the void opener source shape; launcher remains MainMenuPane context. No score change required. |
| `by-class/ChangePasswordDialogPane.md` | Sync the same constructor-xref/singleton-publication note; no ownership or score change required. |
| `by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md` | Optional support sync if not already present: record that singleton publication at `0x004fdd96` is why the retained opener does not need a source-facing returned pointer. No score change required. |

Do not edit generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any manual `-coverage-report.md`.

## Generated And Tracker Notes

Generated artifacts are stale and should refresh only through validator/supervisor tooling:

- `auto-generated/NexusTK/login/MainMenuPane.cpp` still has empty emitter marker lines for [UID:0000TA] at `84/88` and [UID:00019Q] at `80/86`; after accepted implementation and validator refresh, [UID:00019Q] should emit `static void OpenChangePasswordDialog()`.
- `auto-generated/-ag-research-tracker.md` still lists [UID:00019Q] as `80/86`.
- `auto-generated/-ag-coverage-report-by-memory.md` still lists [UID:00019Q] as `80%` / strong.

These were read as state only and were not edited.

Implementation callback note: after the accepted edit, scoped validators refreshed validator-owned generated output. Initial target generated proof showed `auto-generated/NexusTK/login/MainMenuPane.cpp` with validator header `000000004741` / `2026-06-27T23:10:09-04:00` and the [UID:00019Q] `static void OpenChangePasswordDialog()` body. A later validator-owned foreground refresh was observed at validator header `000000004779` / `2026-06-27T23:15:01-04:00`, still containing the same [UID:00019Q] body. Generated reports/project-level generated files remain validator-owned and were not manually edited.

## Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| Move target to `ChangePasswordDialogPane.cpp`. | The helper is launcher context only; dialog class/file docs own the constructed dialog and packet helpers, not the main-menu opener. |
| Treat as runtime/library code due IDA name. | Current decompile/assembly shows a `620`-byte `ChangePasswordDialogPane` allocation wrapper, not standard-library code. |
| Populate `ChangePasswordDialogPane *OpenChangePasswordDialog()`. | No caller proves a returned pointer contract; Hex-Rays return type is unconstrained by inbound use. |
| Leave formal C++ blank because `void` is inferred. | Rejected by this amendment. Current evidence supports `void` as the best source-facing shape; lack of exact original signature proof is not enough to keep an eligible emitter blank. |
| Treat no direct route as dead/no-owner. | The body is an exact retained project helper in a known main-menu launcher band with matching active duplicate behavior. |
| Edit or save the IDA name from this report. | The assignment is report-only and explicitly bans IDA DB edits. |

## Validator Expectations

No validators were run during this report-only assignment.

Expected after accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00019Q-OpenChangePasswordDialog-source-quality-removed.md](00019Q-OpenChangePasswordDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only the validators for files actually edited in the accepted implementation callback. The target validator should use `--wait-generated` if supervisor wants immediate proof that `auto-generated/NexusTK/login/MainMenuPane.cpp` now contains the [UID:00019Q] body.

## Report-Only Execution Notes

- No leases were taken during this report-only pass.
- `tools/leaser/Agents/current_leases.md` was read for proof and showed no `Agent-B010` or `B010` active lease.
- No by-* docs were edited.
- No generated reports, generated C++ files, project-level generated files, coverage reports, validator/tool state, support docs outside the callback, or IDA DB were edited.
- MCP remained available throughout the report. No `PAUSED_MCP_UNAVAILABLE` condition occurred.
- Changed file for this pass: `tools/leaser/Agents/Agent-B010/research/00019Q-OpenChangePasswordDialog-source-quality.md`.
- 2026-06-27 rejection amendment changed the recommendation from blank formal C++ to first-draft `static void OpenChangePasswordDialog()` based on current MCP session `875bf182`; still no by-* docs were edited during this amendment.

## Implementation Tracking Checklist

Implementation callback proof was added by B010 on 2026-06-27.

- [x] Supervisor accepts this report for implementation. Proof: current callback assignment `B010-implement-00019Q-open-change-password-dialog-20260627` in `tools/leaser/Agents/Agent-B010/goal.md` names this report as accepted and supplies the implementation checklist.
- [x] Lease only the immediate target/support files about to be edited; release leases immediately after each edit/validator batch. Proof: B010 leased exactly the eight edited by-* files before editing. After validation, both `tools/leaser/Agents/current_leases.md` and `tools/leaser/Agents/Agent-B010/current_leases.md` showed no active B010 leases; explicit `python tools\leaser\leaser.py B010 unlease ...` then returned `Rejected[No active lease]` for all eight files, so the B010 leases had already expired and no B010 lease remained active.
- [x] Update [UID:00019Q] to `88/90`, keep owner/emitter `0000L0`, and insert formal first-draft `static void OpenChangePasswordDialog()` C++. Proof: `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md` now has `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter `0000L0`, and the exact formal C++ block.
- [x] Add current MCP session `875bf182` function, xref, singleton, bytes, active duplicate, and VA/RVA pointer-search evidence to [UID:00019Q]. Proof: target doc `IDA MCP Evidence`, `Source-Shape And C++ Decision`, `Disposition`, `Score Rationale`, and `Changes` now preserve the accepted `875bf182` evidence and implementation-check session `b001_000241_20260627`; `0x54` / 84 and `0x26c` / 620 are recorded as verified with `tools/int_convert.py`.
- [x] Correct stale current-IDB name wording on [UID:00019Q] and [UID:0000TA]. Proof: both `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md` and `by-global/OpenChangePasswordDialog_4F9060.md` state that current MCP still reports `___std_parallel_algorithms_hw_threads@0_0` and that this label is misleading/not emitted.
- [x] Add the source-shape rationale explaining why `void` is the best source-facing opener, why pointer-return C++ is rejected, and why no-xref/no-pointer route is a confidence cap rather than a blank-C++ blocker. Proof: target and alias docs now document active case `2` ignoring the constructed pointer, constructor publication through `g_pChangePasswordDialogPane`, rejected `ChangePasswordDialogPane *OpenChangePasswordDialog()`, rejected blank C++, and confidence-cap-only no-route evidence.
- [x] Preserve `MainMenuPane.cpp` source placement while rejecting `ChangePasswordDialogPane`, runtime/library, MemoryMan, no-owner, generated-only, pointer-return, and blank-C++ alternatives. Proof: target, alias, aggregate, `MainMenuPane`, `ChangePasswordDialogPane`, and singleton support docs keep owner/emitter [UID:0000L0] and explicitly reject the alternate owners/source shapes.
- [x] Update accepted support docs listed above without expanding beyond the callback scope. Proof: edited only the eight listed by-* docs: `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md`, `by-global/OpenChangePasswordDialog_4F9060.md`, `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`, `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, `by-file/ChangePasswordDialogPane.md`, `by-class/ChangePasswordDialogPane.md`, and `by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md`.
- [x] Do not edit generated files, project-level generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other manual `-coverage-report.md`. Proof: no manual edits were made to those files or IDA DB. Validator-owned generated output refreshed through scoped validator commands; the target-generated `auto-generated/NexusTK/login/MainMenuPane.cpp` was observed at `validator-command-id: 000000004779` and contains UID `00019Q` plus `static void OpenChangePasswordDialog()`.
- [x] Run scoped file-mode validators for every edited by-* file through `tools\validator.py`. Proof: all eight commands below exited `0` with `ok: 1`.
- [x] Record validator command statuses and final touched-file list in the implementation proof. Proof: validator table and touched-file list below.

Validator proof:

| File | Command id | Command timestamp | Exit | ok | Generated refresh / diagnostics |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md` | `000000004736` | `2026-06-27T23:09:32-04:00` | 0 | 1 | Ran with `--wait-generated`; `generated_refresh: completed`. Autogen reported stale registry/missing-file diagnostics outside this target and refreshed generated output. |
| `by-global/OpenChangePasswordDialog_4F9060.md` | `000000004739` | `2026-06-27T23:10:03-04:00` | 0 | 1 | `generated_refresh: deferred`. |
| `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | `000000004742` | `2026-06-27T23:10:10-04:00` | 0 | 1 | `generated_refresh: deferred`; existing `missing_ref_uid 00036Y` reported five times. The referenced file exists at `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`, but the UID is not present in `tools/validator.ini`; no validator state was hand-edited. |
| `by-file/MainMenuPane.md` | `000000004744` | `2026-06-27T23:10:13-04:00` | 0 | 1 | `generated_refresh: deferred`. |
| `by-class/MainMenuPane.md` | `000000004746` | `2026-06-27T23:10:14-04:00` | 0 | 1 | `generated_refresh: deferred`; existing `missing_ref_uid 00036Y` reported five times. The referenced file exists at `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`, but the UID is not present in `tools/validator.ini`; no validator state was hand-edited. |
| `by-file/ChangePasswordDialogPane.md` | `000000004750` | `2026-06-27T23:10:16-04:00` | 0 | 1 | `generated_refresh: deferred`. |
| `by-class/ChangePasswordDialogPane.md` | `000000004752` | `2026-06-27T23:10:20-04:00` | 0 | 1 | `generated_refresh: deferred`. |
| `by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md` | `000000004754` | `2026-06-27T23:10:21-04:00` | 0 | 1 | `generated_refresh: deferred`. |

Validator side effects to report: each scoped validator updated `project-level/-auto-completion-stats.md` projected path completion section; validator also updated `tools/validator.ini`, `auto-generated/NexusTK/login/MainMenuPane.cpp`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` through validator-owned output, not manual edits. Target generated proof: `auto-generated/NexusTK/login/MainMenuPane.cpp` first refreshed for this target at `validator-command-id:000000004741`, `validator-refreshed-at:2026-06-27T23:10:09-04:00`, and a later validator-owned foreground refresh was observed at `validator-command-id:000000004779`, `validator-refreshed-at:2026-06-27T23:15:01-04:00`; both generated versions contain `// UID:00019Q` plus `static void OpenChangePasswordDialog()`. Queue status after validation (`command_id:000000004782`, `2026-06-27T23:15:10-04:00`) showed the validator worker still active with `queued generated refresh jobs:3` and `processing generated refresh jobs:0`; the target generated output was already newer than the target validation command and contained the required body. No manual coverage-report edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00019Q-OpenChangePasswordDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00019Q-OpenChangePasswordDialog-source-quality.md","timestamp":"2026-06-27T23:13:04","uid":"00019Q"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019Q-OpenChangePasswordDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00019Q-OpenChangePasswordDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
