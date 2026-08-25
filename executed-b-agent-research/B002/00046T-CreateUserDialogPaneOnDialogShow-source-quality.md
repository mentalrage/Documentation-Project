** TARGET-REPORT-UID:00046T **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00046T CreateUserDialogPaneOnDialogShow Source-Quality Research

** TARGET: by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md **
** REPORT-CREATED: 2026-07-06T05:39:05-04:00 **
** REPORT-MODE: implementation callback completed; no execute_report or lifecycle/archive command **

## Finalized Report / Current Recommendation

- Callback result: applied accepted UID00046T target update. [UID:00046T] `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md` is now `COMPLETION:88` / `CONFIDENCE:91`, raised from pre-callback `86/89`.
- Keep target metadata `CANONICAL_OWNER:00003B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003B`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Keep the formal C++ block exactly as-is:

```cpp
bool CreateUserDialogPane::OnDialogShow(int reason)
{
    return DialogPane::OnDialogShow(reason);
}
```

- Incorporate current MCP evidence into the target at report-level detail: active session `9600ec5b`, server health `ok`, imagebase `0x400000`, exact 9-byte bridge body, tail jump to inherited `0x0049e240`, sole target xref from the `CreateUserDialogPane` secondary vtable slot at `0x0061fea0`, target VA pointer-pattern singleton hit, target RVA pointer-pattern negative, boundary padding, generated output state, rejected owner/source alternatives, and score rationale.
- Optional narrow support sync after target approval was applied to `by-file/CreateUserDialogPane.md`: the stale prose saying active generated output omitted `OnDialogShow` is now historicalized. Current generated `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` contains UID00046T and the method declaration/body after validator command `000000007574`. No support metadata score change was made.
- Exact blockers left: original proprietary source symbol/path is still not available; direct runtime call/reachability beyond vtable data is not proven; `DialogPane::OnDialogShow` remains the best source-facing inherited-interface spelling rather than an IDA-local symbol. These cap the target below `95+`, but do not block the recommended `88/91`.

## Supporting Research

- Project workflow: read current B002 `goal.md`, the `ntk-b-agent-workflow` skill, the B-agent workflow reference, and the `by-structure.md` IDA MCP Output Discipline.
- Target/support docs checked:
  - `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md`
  - `by-class/CreateUserDialogPane.md`
  - `by-file/CreateUserDialogPane.md`
  - `by-file/CreateUserDialogs.md`
  - `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`
  - `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`
  - `by-file/DialogPane.md`
  - `by-class/DialogPane.md`
  - `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`
  - `auto-generated/-ag-research-tracker.md`
- Current tracker state for UID00046T: `86/89`, combined `87.5`, reconstructable `true`, direct reports `0`.
- Current generated state after callback validators: `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` has `validator-command-id: 000000007574`, `validator-refreshed-at: 2026-07-06T13:19:02-04:00`, `Source by-file UID: 0000IJ`, declares `virtual bool OnDialogShow(int reason);`, and emits UID00046T with the exact formal C++ block at `COMPLETION:88` / `CONFIDENCE:91`.

## Target

- UID: `00046T`
- Path: `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md`
- Current source route: [UID:00003B] `CreateUserDialogPane` class, emitted through [UID:0000IJ] `NexusTK/login/CreateUserDialogPane.cpp`.
- Parent/container context: [UID:0002QT] `CreateUserDialogPaneCore` is a non-emitting split/index; [UID:0000IK] `CreateUserDialogs` is a non-emitting family/index page.
- Function role: tiny secondary-vtable virtual bridge that delegates to inherited `DialogPane` dialog-show/input-control behavior.

## Current Target State

- Pre-callback metadata was `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00003B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003B`, blank emitter position, `Nested:0`.
- Current post-callback metadata is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00003B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003B`, blank emitter position, `Nested:0`.
- Current formal C++ is already populated and source-shaped:

```cpp
bool CreateUserDialogPane::OnDialogShow(int reason)
{
    return DialogPane::OnDialogShow(reason);
}
```

- Pre-callback target Evidence was too sparse for the present state. Callback implementation added the current MCP session/health, function size/body, exact xrefs, pointer-pattern checks, boundary padding, generated freshness, rejected alternatives, and score rationale.

## Heuristic / Inference Reanalysis And Validation

- Source-authored bridge versus inherited slot: if this slot were purely inherited, the `CreateUserDialogPane` secondary vtable could point directly at `0x0049e240`, as many base-dialog vtables do. Instead, current MCP reports a local function at `0x0052ed00` and the vtable slot at `0x0061fea0` points to that local bridge. That supports keeping UID00046T as a reconstructable method child rather than blank/no-code inherited data.
- Bridge versus adjustor thunk: the body has no `ecx` adjustment and no scalar-delete flag logic. It is `push ebp; mov ebp, esp; pop ebp; jmp sub_49E240`, so it is not one of the adjacent multiple-inheritance destructor thunks and should not route through UID0002QU destructor/thunk support.
- CreateUserDialogPane ownership: the only target-start xref and only target-start absolute pointer-pattern hit are the secondary `CreateUserDialogPane` vtable slot at `0x0061fea0`. The secondary table base `0x0061fe9c` has constructor/destructor/fallback refs from the old `CreateUserDialogPane` lifecycle, and the successor `0x0061fed8` has separate `NewUserDialogPane2` refs. This rejects sibling/newer create-user owners.
- Base callee naming: current support docs identify `0x0049e240` as a `DialogPane` inherited input/control dispatch surface. The current class/generator route names this target `CreateUserDialogPane::OnDialogShow(int reason)` and emits `DialogPane::OnDialogShow(reason)` as the best source-facing spelling. The base callee's original source symbol is not proven by IDA, so this remains a confidence cap, not a no-code reason.
- Split/range: UID00046T is already an exact `0x9`-byte modeled function child. `0x0052ecf6-0x0052ed00` is ten `0xcc` bytes after UID00046S, and `0x0052ed09-0x0052ed10` is seven `0xcc` bytes before `nullsub_44`. No range extension or child split is justified.
- Generated-output status: current generated `CreateUserDialogPane.cpp` already emits UID00046T as code, not as an empty marker. This resolves the older support-prose concern that active generated output omitted `OnDialogShow`.

## Evidence Standards Used

- Current IDA MCP evidence is mandatory and was gathered through direct JSON-RPC calls to `http://127.0.0.1:13337/mcp`.
- MCP calls were narrow and schema-current: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `find_bytes`, and `get_bytes`, all scoped to the target, immediate boundaries, base callee, and the relevant vtable range.
- No broad unbounded function lists, call graphs, type searches, or batch-analysis tools were used.
- Existing docs and generated output were used as support evidence, not as a replacement for current MCP.
- No validators were run during this report-only pass.

## Evidence Checked

- MCP session:
  - `idb_list` call id `3`: active session `9600ec5b`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker, not analyzing.
  - `server_health` call id `20`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Function and boundary lookup:
  - `lookup_funcs` call id `21`: `0x0052ed00` is `sub_52ED00`, size `0x9`.
  - `0x0052ecf6` and `0x0052ed09` are not functions.
  - `0x0052ed10` is `nullsub_44`, size `0x1`.
  - `0x0049e240` is `sub_49E240`, size `0x476`; `0x0049e6e0` is `sub_49E6E0`, size `0x379`.
  - Adjacent handlers: `0x0052ecc0` is `sub_52ECC0`, size `0x9`; `0x0052ecd0` is `sub_52ECD0`, size `0x26`.
- Function body:
  - `analyze_function` call id `22`: target size `9`, prototype `char __thiscall(int this, int)`, decompiled as `return sub_49E240(this, a2);`, empty callers/callees arrays, xrefs-to only `0x61fea0` data, one outgoing code ref at `0x52ed01`, basic block count `2`, cyclomatic complexity `1`.
  - `decompile` call id `23`: `char __thiscall sub_52ED00(int this, int a2) { return sub_49E240(this, a2); }`; refs list includes only `0x49e240` / `sub_49E240`.
  - `disasm` call id `24`: four instructions, `push ebp`, `mov ebp, esp`, `pop ebp`, `jmp sub_49E240`; total instruction count `4`.
  - `get_bytes` call id `27`: target bytes `55 8b ec 5d e9 37 f5 f6 ff`.
- Xrefs and pointer-pattern checks:
  - `xrefs_to` call id `25`: target `0x0052ed00` has exactly one xref, data at `0x61fea0`, no code callers.
  - Same call: secondary vtable base `0x0061fe9c` has exactly three data refs at `0x52dda8`, `0x52e6ff`, and `0x52f812`; successor `0x0061fed8` has two refs at `0x52a8e5` and `0x52a98e` from `NewUserDialogPane2`.
  - Same call: base target `0x0049e240` has many code/data refs and includes target jump site `0x52ed04`, supporting that UID00046T is one derived bridge among broad inherited-dialog consumers.
  - `find_bytes` call id `26`: absolute target pointer pattern `00 ED 52 00` has exactly one match at `0x61fea0`.
  - `find_bytes` call id `26`: target RVA pattern `00 ED 12 00` has zero matches.
  - `find_bytes` call id `26`: base absolute pattern `40 E2 49 00` has many table/data matches and was capped at 50; base RVA pattern `40 E2 09 00` has zero matches.
- Boundary bytes:
  - `get_bytes` call id `27`: `0x0052ecf6` size `10` is ten `0xcc` bytes.
  - `get_bytes` call id `27`: `0x0052ed09` size `8` is seven `0xcc` bytes followed by `0xc3` at the `0x0052ed10` nullsub.
  - `get_bytes` call id `27`: secondary vtable bytes at `0x0061fe9c` include `0x0052f73b`, `0x0052ed00` at `0x0061fea0`, `0x0052ecc0`, `0x0049ea60`, `0x0052ecd0`, then inherited/shared helper slots.
- Existing docs:
  - [UID:00003B] class page declares `virtual bool OnDialogShow(int reason);` and records the secondary-vtable wrapper group.
  - [UID:0000IJ] file page records the old-dialog method inventory. Pre-callback it still had one stale line saying active generated output omitted `OnDialogShow`; callback support sync historicalized that line to the current generated state.
  - [UID:0000IK] family page is a non-emitting family/index page and correctly leaves concrete source emission to specific files.
  - [UID:0002QT] split/index lists UID00046T as exact child and non-emits the aggregate.
  - [UID:0002SI] vtable data page identifies `0x0061fe9c` as the secondary `CreateUserDialogPane` vtable and names `0x0061fea0 -> 0x0052ed00` as the `OnDialogShow` slot.
  - `DialogPane` file/class docs identify `0x0049e240` as inherited dialog input/control dispatch.

## Direct Old-Report Search Terms And Results

Search scope: current B-agent `research/` folders, `tools/leaser/Agents/Older-Research`, and the executed archive at `source-3/project-documentation/executed-b-agent-research`. The archive directory exists in this checkout and was searched read-only during the Gate 1 repair; no lifecycle/archive command was run.

Current active/older research-folder results:

| Search term | File count | Relevant results |
| --- | ---: | --- |
| `TARGET-REPORT-UID:00046T` | 0 | No prior direct UID00046T report found. |
| `00046T` | 1 | `tools/leaser/Agents/Agent-B015/research/00046S-CreateUserDialogPaneOnCreateUserReplyEvent-source-quality.md` mentions UID00046T as adjacent support. |
| `0x0052ed00` | 1 | Same B015 UID00046S report; records UID00046T as adjacent show bridge. |
| `0x0052ed09` | 1 | Same B015 UID00046S report; range/padding context. |
| `CreateUserDialogPaneOnDialogShow` | 1 | Same B015 UID00046S report. |
| `OnDialogShow` | 1 | Same B015 UID00046S report. |
| `CreateUserDialogPane` | 2 | B015 UID00046S and B001 UID0002QS reports. B015 is directly adjacent; B001 is newer-variant context. |
| `CreateUserDialogPaneCore` | 2 | B015 UID00046S and B001 UID0002QS. |
| `0002QT` | 2 | B015 UID00046S and B001 UID0002QS. |
| `00003B` | 1 | B015 UID00046S. |
| `0000IJ` | 1 | B015 UID00046S. |
| `0000IK` | 2 | B015 UID00046S and B001 UID0002QS. |
| `DialogPane::OnDialogShow` | 0 | No prior report text found with the exact source-facing base call spelling. |

Executed archive results:

| Search term | Executed file count | Relevant executed archive results |
| --- | ---: | --- |
| `TARGET-REPORT-UID:00046T` | 0 | No direct executed UID00046T report found. |
| `00046T` | 1 | `executed-b-agent-research/B008/0002QT-CreateUserDialogPaneCore-source-quality.md` lists UID00046T as an exact child created by the split callback. |
| `0x0052ed00` | 2 | B004 `00003B` class report and B008 `0002QT` core report. |
| `0x0052ed09` | 1 | B008 `0002QT` core report. |
| `CreateUserDialogPaneOnDialogShow` | 1 | B008 `0002QT` core report. |
| `OnDialogShow` | 2 | B004 `00003B` class report and B008 `0002QT` core report. |
| `CreateUserDialogPane` | 21 | Broad create-user-family hits. Directly opened/relevant for this target: B004 `00003B` and B008 `0002QT`; B010 `0001CR` is family context, while the other hits are sibling/control/global context. |
| `CreateUserDialogPaneCore` | 7 | Directly relevant B004 `00003B` and B008 `0002QT`; broader context includes B001 `0002Q9`, B001 `0002SJ`, B007 `0000FJ`, B009 `0000FL`, and B010 `0001CR`. |
| `0002QT` | 4 | B004 `00003B`, B008 `0002QT`, and B010 `0001CR` are relevant create-user context; B005 `0000YZ` is broad unrelated context. |
| `00003B` | 5 | B004 `00003B` and B008 `0002QT` are directly relevant; B001 `0002SJ`, B009 `0000FL`, and B010 `0001CR` are sibling/family context. |
| `0000IJ` | 4 | B004 `00003B`, B008 `0002QT`, B009 `0000FL`, and B010 `0001CR`; direct target route evidence is in B004/B008. |
| `0000IK` | 15 | Broad family/sibling hits. Directly relevant create-user route evidence is in B004 `00003B`, B008 `0002QT`, and B010 `0001CR`; other hits are sibling dialog/control/global context. |
| `DialogPane::OnDialogShow` | 2 | B004 `00003B` and B008 `0002QT`. |

Directly useful report results:
- Active B015 UID00046S confirms current session `9600ec5b`, adjacent boundary `0x0052ecf6-0x0052ed00` padding, UID00046T as `sub_52ED00` size `0x9`, and current support route through [UID:00003B]/[UID:0000IJ]. It is adjacent evidence, not a substitute for this report's current target MCP calls.
- Executed B008 UID0002QT is the strongest historical target lead: it created `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md` as [UID:00046T], owner/emitter `00003B`, reconstructable exact C++, with validator `000000003376` at `2026-06-26T20:39:19-04:00`; it documents `0x0052ed00-0x0052ed09` as `sub_52ED00`, size `0x9`, a source-authored/base-delegating `OnDialogShow` bridge, and preserves the `0x0049e240` inherited-target caveat.
- Executed B004 UID00003B is useful older class/source-route support: it identifies `0x0052ed00` as an `OnDialogShow(...)` base delegate in the `CreateUserDialogPane` method inventory and secondary vtable. Its generated-output-omission language is historical/stale after the later B008 split and this callback's generated refresh, not a contradiction.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00046T-01 | Current MCP session `9600ec5b` is healthy for `NexusTK.exe`, imagebase `0x400000`. | confirmed | MCP `idb_list` id `3`, `server_health` id `20` | Target Evidence / Current MCP provenance | incorporate | applied |
| C-00046T-02 | `0x0052ed00` is modeled as `sub_52ED00`, size `0x9`; `0x0052ecf6` and `0x0052ed09` are not functions; `0x0052ed10` is `nullsub_44` size `0x1`. | confirmed | MCP `lookup_funcs` id `21` | Target Evidence / Range and boundary notes | incorporate | applied |
| C-00046T-03 | The body bytes are exactly `55 8b ec 5d e9 37 f5 f6 ff`, four instructions, tail-jumping to `0x0049e240`. | confirmed | MCP `get_bytes` id `27`, `disasm` id `24` | Target Evidence / Body bytes and disassembly | incorporate | applied |
| C-00046T-04 | Hex-Rays decompiles the bridge as `return sub_49E240(this, a2);`; source-facing formal C++ should remain `return DialogPane::OnDialogShow(reason);`. | high | MCP `decompile` id `23`, support docs, generated output | Target Evidence and formal C++ block | incorporate | applied |
| C-00046T-05 | Target has no direct code callers; its only incoming xref is data at secondary vtable slot `0x0061fea0`. | confirmed | MCP `analyze_function` id `22`, `xrefs_to` id `25` | Target Evidence / Xrefs and reachability | incorporate | applied |
| C-00046T-06 | Absolute target pointer pattern `00 ED 52 00` occurs exactly once at `0x0061fea0`; target RVA pattern `00 ED 12 00` has zero matches. | confirmed | MCP `find_bytes` id `26` | Target Evidence / Pointer-pattern checks | incorporate | applied |
| C-00046T-07 | `0x0061fe9c` is the relevant secondary `CreateUserDialogPane` vtable base and has constructor/fallback/destructor refs at `0x52dda8`, `0x52e6ff`, and `0x52f812`. | confirmed | MCP `xrefs_to` id `25`, vtable bytes id `27`, vtable doc | Target Evidence / Owner and vtable route | incorporate | applied |
| C-00046T-08 | Successor `0x0061fed8` belongs to separate `NewUserDialogPane2` callback/vtable data and does not extend the `CreateUserDialogPane` vtable target evidence. | high | MCP `xrefs_to 0x0061fed8` id `25`, UID0002SI doc | Target Range / rejected adjacency | incorporate | applied |
| C-00046T-09 | `0x0052ecf6-0x0052ed00` is ten `0xcc` bytes; `0x0052ed09-0x0052ed10` is seven `0xcc` bytes before the nullsub byte. | confirmed | MCP `get_bytes` id `27` | Target Evidence / Boundary padding | incorporate | applied |
| C-00046T-10 | Direct owner/emitter should remain [UID:00003B] `CreateUserDialogPane`; file route remains [UID:0000IJ] `CreateUserDialogPane.cpp`. | high | Target xref, class/file/core/vtable docs, generated output | Target metadata/source placement | already-present | already-present |
| C-00046T-11 | [UID:0002QT] remains a non-emitting split/index; [UID:0000IK] remains a non-emitting family/index and should not own/emit this method body. | high | Core and family docs | Target rejected alternatives / support docs | already-present | already-present |
| C-00046T-12 | Current generated output already emits UID00046T and declares `virtual bool OnDialogShow(int reason);`. | confirmed | `auto-generated/NexusTK/login/CreateUserDialogPane.cpp`, command `000000007574` | Target Evidence / Generated state | incorporate | applied |
| C-00046T-13 | The support file `by-file/CreateUserDialogPane.md` had stale active-generated-output wording for `OnDialogShow`; historicalize it to the current generated state if support sync is authorized. | confirmed | Read of by-file support doc and current generated output | `by-file/CreateUserDialogPane.md` Evidence Notes | historicalize | applied |
| C-00046T-14 | `by-class/CreateUserDialogPane.md`, `by-file/CreateUserDialogs.md`, UID0002QT core, and UID0002SI vtable docs already carry same-or-greater owner/slot/source-route detail. | high | Read-only support doc checks | Support docs | already-present | already-present |
| C-00046T-15 | Reject raw `sub_52ED00` naming, raw vtable C++, scalar deleting destructor/thunk ownership, sibling newer create-user owners, `DialogPane` direct ownership, [UID:0000IK] family ownership, and [UID:0002QT] aggregate emission. | high | MCP body/xrefs, support docs, generated output | Target Rejected alternatives | reject-invalid | applied |
| C-00046T-16 | No split or range repair is needed for UID00046T. | confirmed | MCP function size, padding bytes, adjacent nullsub, vtable slot | Target Range / split analysis | incorporate | applied |
| C-00046T-17 | Recommended target score is `COMPLETION:88`, `CONFIDENCE:91`; not `95+` because original source symbol/path, exact inherited base method spelling, and direct runtime entry remain unproven. | high | All current evidence and remaining caps | Target metadata / Score rationale | incorporate | applied |
| C-00046T-18 | No `execute_report`, dry-run/probing execute variant, registry lifecycle command, manual report move, archive move, generated manual edit, coverage edit, validator-state manual edit, supervisor-ledger edit, or IDA DB edit was performed. | confirmed | Agent action log; changed-file and validator results below | Report Validator Results / Changed Files | not-applicable | applied |

## Positive Evidence Summary

- UID00046T is an exact, modeled 9-byte function and the current formal C++ already matches the decompiler/assembly shape at source level.
- Current MCP proves the only incoming xref and only absolute target pointer hit are the secondary `CreateUserDialogPane` vtable slot at `0x0061fea0`.
- Boundary bytes prove the target is neither part of UID00046S nor part of the following nullsub: ten `0xcc` bytes before, seven `0xcc` bytes after, then `nullsub_44`.
- Support docs align on the direct class owner, source file route, split-index parent, family-index context, and vtable-slot interpretation.
- Current generated output emits UID00046T as code and includes the class virtual declaration.

## Negative Evidence Summary

- There are zero direct code callers to `0x0052ed00`; reachability is vtable/data based.
- Target RVA pointer pattern `00 ED 12 00` has zero matches.
- The callee `0x0049e240` is broad inherited `DialogPane` input/control dispatch with many consumers, so it supports inherited-base delegation but does not by itself prove an original base symbol named exactly `DialogPane::OnDialogShow`.
- No current local IDA source symbol, PDB symbol, or recovered proprietary source path proves the original method spelling beyond the class/vtable/generator inference.
- No evidence supports widening UID00046T into adjacent padding, the following nullsub, UID0002QT aggregate C++, raw vtable data, or destructor/thunk support.

## Ranked Ownership Analysis

### 1. [UID:00003B] CreateUserDialogPane

- Evidence for: secondary vtable slot `0x0061fea0 -> 0x0052ed00`; class declaration includes `virtual bool OnDialogShow(int reason);`; class page groups UID00046T with `OnKeyEvent` and `OnCreateUserReplyEvent`; generated `CreateUserDialogPane.cpp` emits the method body.
- Evidence against: no direct runtime caller beyond vtable data, but this is expected for virtual callbacks and is a score cap, not an ownership blocker.
- Decision: keep direct owner/emitter [UID:00003B].

### 2. [UID:0000IJ] CreateUserDialogPane file

- Evidence for: generated source root is `NexusTK/login/CreateUserDialogPane.cpp`; current generated output has by-file UID `0000IJ` and emits UID00046T.
- Evidence against: file page is source root/output route, not direct by-memory canonical owner when class page owns methods.
- Decision: keep as file route and optional support prose sync target only.

### 3. [UID:0002QT] CreateUserDialogPaneCore split/index

- Evidence for: parent/container range lists UID00046T as exact child.
- Evidence against: page is `RECONSTRUCTABLE:FALSE` and non-emitting; exact children carry C++ or no-code dispositions.
- Decision: reject as direct emitter.

### 4. [UID:0000IK] CreateUserDialogs family/index

- Evidence for: high-level family page covering old/new create-user variants.
- Evidence against: non-emitting family/index with concrete source files split out; no direct target slot evidence.
- Decision: reject as direct owner/emitter.

### 5. DialogPane / sibling create-user variants / destructor-thunk support

- Evidence for DialogPane: target tail-jumps to inherited `0x0049e240`.
- Evidence against DialogPane: target-start xref is in `CreateUserDialogPane` vtable data, not a base vtable slot; the method is a derived bridge.
- Evidence against sibling variants: their vtable ranges and singleton slots are distinct, and successor `0x0061fed8` refs are `NewUserDialogPane2`, not UID00046T.
- Evidence against destructor/thunk support: no ecx adjustment, no scalar-delete flag, ordinary 9-byte base-delegating bridge.
- Decision: reject these alternatives.

## Source Placement

- Recommended source placement: `NexusTK/login/CreateUserDialogPane.cpp`, method `bool CreateUserDialogPane::OnDialogShow(int reason)`, emitted through [UID:00003B].
- Best source-facing base call: `DialogPane::OnDialogShow(reason)`. This is supported by current class/generator route and target decompile to `sub_49E240(this, a2)`, while `DialogPane` docs identify `0x0049e240` as inherited input/control dispatch.
- Rejected source placements: `CreateUserDialogs.cpp` family index, `CreateUserDialogPaneCore` aggregate output, `DialogPane.cpp` direct ownership, `NewCreateUserDialogPane.cpp`, `NewUserDialogPane2.cpp`, vtable data page, destructor/thunk island, or raw `sub_52ED00` helper output.

## First-Draft C++ Recommendation

Keep the formal `RECONSTRUCTION_CPP CODE` block unchanged:

```cpp
bool CreateUserDialogPane::OnDialogShow(int reason)
{
    return DialogPane::OnDialogShow(reason);
}
```

Reasoning:
- The body is a direct tail-jump to the inherited `DialogPane` handler with the same `this` and one integer argument.
- The target has a local vtable slot in `CreateUserDialogPane`, so a source-facing override/bridge body is better than a blank/no-code marker.
- The current generated source already emits this exact block and the class declaration already contains the virtual method.
- Do not emit raw prologue/epilogue, raw `sub_49E240`, raw vtable-pointer data, or a thunk/destructor wrapper.

## Final Recommendation

- Callback result: target enrichment and score update applied; formal C++ unchanged; owner/emitter unchanged.
- Callback result: supervisor-authorized support sync applied to `by-file/CreateUserDialogPane.md` with no support score/metadata change.
- No split, range rename, child creation, manual generated-file edit, validator-state edit, coverage edit, lifecycle/archive command, or `execute_report` was performed.

## Recommended Target Doc Changes

Target: `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md`

Required metadata after callback:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep the formal C++ block exactly unchanged.

Recommended Item Summary replacement:

```text
Current MCP-confirmed 9-byte `CreateUserDialogPane::OnDialogShow` secondary-vtable bridge that tail-jumps to inherited `DialogPane` dialog-show/input-control handling; vtable-only reachability through `0x0061fea0`, exact padding boundaries, generated source emission, and retained inherited-base spelling caveat.
```

Recommended body additions/replacements under `## Evidence`:
- Add current MCP provenance: session `9600ec5b`, server `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis/Hex-Rays ready.
- Add function/boundary facts: `lookup_funcs` reports `0x0052ed00` as `sub_52ED00` size `0x9`; `0x0052ecf6` and `0x0052ed09` are not functions; `0x0052ed10` is `nullsub_44` size `0x1`; `0x0049e240` is inherited `DialogPane` body `sub_49E240` size `0x476`.
- Add body facts: bytes `55 8b ec 5d e9 37 f5 f6 ff`; disassembly `push ebp; mov ebp, esp; pop ebp; jmp sub_49E240`; Hex-Rays decompile `return sub_49E240(this, a2);`.
- Add xref facts: no code callers; exactly one target xref, data at `0x0061fea0`; absolute target pointer pattern `00 ED 52 00` has exactly one match at `0x0061fea0`; RVA pattern `00 ED 12 00` has zero matches.
- Add vtable facts: secondary vtable base `0x0061fe9c` has refs at `0x52dda8`, `0x52e6ff`, and `0x52f812`; bytes show slot order including `0x0052f73b`, `0x0052ed00`, `0x0052ecc0`, `0x0049ea60`, and `0x0052ecd0`; successor `0x0061fed8` has separate `NewUserDialogPane2` refs at `0x52a8e5` and `0x52a98e`.
- Add boundary facts: `0x0052ecf6-0x0052ed00` is ten `0xcc` bytes; `0x0052ed09-0x0052ed10` is seven `0xcc` bytes before the following `0xc3` nullsub byte.
- Add generated-state facts: `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` refreshed at validator command `000000007574` / `2026-07-06T13:19:02-04:00` and emits UID00046T at `88/91` with this source-shaped body.
- Add rejected alternatives: no raw `sub_52ED00`, no direct `DialogPane` ownership, no raw vtable C++, no UID0002QT aggregate emission, no UID0000IK family ownership, no sibling/newer create-user ownership, no scalar deleting destructor/adjustor thunk route, no split/range extension.
- Add score rationale: evidence supports `88/91`; not `95+` because original source symbol/path, exact inherited base method spelling, and direct runtime call/reachability remain unproven.

## Recommended Support Doc Changes

- `by-class/CreateUserDialogPane.md`: no required edit. It already declares `virtual bool OnDialogShow(int reason);`, records the `OnKeyEvent` / `OnCreateUserReplyEvent` / `OnDialogShow` secondary-wrapper group, and routes the class through [UID:0000IJ].
- `by-file/CreateUserDialogPane.md`: applied narrow prose-only support sync. The stale active-generated-output omission sentence is now historicalized; current generated output at `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` contains both the declaration and UID00046T method body after validator command `000000007574`. No metadata score change was made.
- `by-file/CreateUserDialogs.md`: no required edit. It correctly remains a non-emitting family/index page for the create-user dialog family; its `simroot_v2` omission note is historical/source-lead context, not current generated-output state.
- `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`: no required edit. It already lists UID00046T as exact child with owner/emitter [UID:00003B] and formal source-shaped base delegation.
- `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md`: no required edit. It already identifies the secondary table and UID00046T slot.

## Score And Metadata Recommendation

- Recommended target scores: `COMPLETION:88`, `CONFIDENCE:91`.
- Why higher than current `86/89`: current MCP now proves exact body bytes, disassembly, decompile, function/boundary state, single vtable xref, pointer-pattern results, vtable base refs, successor separation, generated emission, and no split/owner repair requirement.
- Why not higher than `91` confidence or `95+`: no original source/PDB symbol or source path proves the exact spelling; `0x0049e240` remains a broad inherited `DialogPane` input/control dispatch method in support docs; no direct runtime call edge to the target was found outside vtable data.
- Metadata to preserve: owner/emitter [UID:00003B], reconstructable true, blank emitter position, `Nested:0`.

## Open Questions With Attempted Resolution

- Is the target source-authored or a compiler-only inherited slot?
  - Resolution: best current answer is source-authored/source-facing bridge. Evidence is the local function at `0x0052ed00` and secondary `CreateUserDialogPane` vtable slot pointing to it, rather than a direct vtable pointer to `0x0049e240`.
- Is `DialogPane::OnDialogShow` the exact original callee spelling?
  - Resolution: best source-facing spelling remains `DialogPane::OnDialogShow(reason)` because current class/generator route names the override `OnDialogShow` and the body delegates to inherited `DialogPane` behavior. Exact original base symbol is not proven, so this caps confidence.
- Is a split/range change needed?
  - Resolution: no. MCP proves exact `0x9` modeled function and `0xcc` padding on both sides before the following nullsub.
- Is support doc drift present?
  - Resolution: yes, one stale generated-output sentence in `by-file/CreateUserDialogPane.md`. It should be historicalized if support edits are authorized. Other checked support docs already carry same-or-greater detail.
- Is direct runtime reachability proven?
  - Resolution: no direct code caller was found. Vtable-only reachability is enough for ownership and C++ emission but remains a score cap.

## Validator Results

- Report-only pass history: no validators were run before Gate 1 callback.
- Target validator run after target edit:

> Executable block R001 was removed from this report and preserved verbatim in [00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md](00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

  - command_id: `000000007572`
  - command_timestamp: `2026-07-06T13:17:43-04:00`
  - exit code: `0`
  - ok: `1`
  - notable output: `completion_update 00046T ... 88`, `confidence_update 00046T ... 91`, `uid_link_insert: 4`, `reference_index_add: 4`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- Support validator runs after authorized support sync:

> Executable block R002 was removed from this report and preserved verbatim in [00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md](00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

  - first support validator command_id: `000000007573`, command_timestamp `2026-07-06T13:18:32-04:00`, exit code `0`, ok `1`; run before final support prose wording cleanup.
  - final support validator command_id: `000000007574`, command_timestamp `2026-07-06T13:19:02-04:00`, exit code `0`, ok `1`; notable output `projected_stats_update: 1`, `generated_refresh: deferred`.
- Generated freshness check: `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` now has `validator-command-id: 000000007574`, `validator-refreshed-at: 2026-07-06T13:19:02-04:00`, `validator-refresh-source: deferred-generated-refresh`, declares `virtual bool OnDialogShow(int reason);`, and emits UID00046T with `Completion:88`, `Confidence:91`, and the preserved `DialogPane::OnDialogShow(reason)` body.

## Changed Files

- Changed by-* target: `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md`.
- Changed by-* support: `by-file/CreateUserDialogPane.md`.
- Updated report: `tools/leaser/Agents/Agent-B002/research/00046T-CreateUserDialogPaneOnDialogShow-source-quality.md`.
- Validator-generated refresh observed, not manually edited: `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` header now reflects command `000000007574`.
- Validator-reported generated/projected stats side effect: `project-level/-auto-completion-stats.md` projected path completion section updated by scoped validators. This was validator-owned output, not a manual edit.
- No coverage reports manually edited.
- No validator state manually edited.
- No supervisor ledgers, lifecycle/archive files, or IDA DB edited.

## Implementation Tracking Checklist

- [x] Leased `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md` only immediately before target editing; lease acquired as B002 and released successfully after target validator/generated-freshness check.
- [x] Target metadata set to `COMPLETION:88` and `CONFIDENCE:91`; preserved `CANONICAL_OWNER:00003B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003B`, blank emitter position, and `Nested:0`.
- [x] Target formal C++ kept exactly unchanged.
- [x] Target prose incorporated C-00046T-01 through C-00046T-12 and C-00046T-15 through C-00046T-17 into Evidence, range/boundary notes, rejected alternatives, generated state, and score rationale.
- [x] Optional support sync was authorized and applied: leased/edited `by-file/CreateUserDialogPane.md` to historicalize the stale active-generated-output omission sentence for `OnDialogShow`; no support metadata score change.
- [x] No edit made to `by-class/CreateUserDialogPane.md`, `by-file/CreateUserDialogs.md`, UID0002QT core, or UID0002SI vtable data; those were already same-or-greater for this callback.
- [x] Did not manually edit generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or IDA DB.
- [x] Did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves.
- [x] Ran scoped target validator from `source-3/project-documentation` after target edits:

> Executable block R003 was removed from this report and preserved verbatim in [00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md](00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

  - command_id `000000007572`, timestamp `2026-07-06T13:17:43-04:00`, exit code `0`, ok `1`.
- [x] Ran scoped support validator after editing `by-file/CreateUserDialogPane.md`.
  - final command_id `000000007574`, timestamp `2026-07-06T13:19:02-04:00`, exit code `0`, ok `1`.
- [x] Inspected `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` without manual generated edits; header is `validator-command-id: 000000007574` / `validator-refreshed-at: 2026-07-06T13:19:02-04:00`, and UID00046T still emits the formal C++ at `88/91`.
- [x] Released target and support leases immediately after their edit/validator/generated-freshness batches; `current_leases.md` shows no active leases.
- [x] Updated this report's Claim And Incorporation Ledger verification states to callback states.
- [x] Updated Validator Results, Changed Files, generated freshness, and lease release confirmation after callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000007591","destination_path":"executed-b-agent-research/B002/00046T-CreateUserDialogPaneOnDialogShow-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00046T-CreateUserDialogPaneOnDialogShow-source-quality.md","timestamp":"2026-07-06T13:42:06-04:00","uid":"00046T"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00046T-CreateUserDialogPaneOnDialogShow-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00046T-CreateUserDialogPaneOnDialogShow-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00046T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
