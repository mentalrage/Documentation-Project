** TARGET-REPORT-UID:000457 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000457 FolderSelectDialogConstructor Source-Quality Report

Agent: B003
Date: 2026-07-03
Mode: implementation callback complete after accepted report-only research
MCP session used for final evidence: `2ec9c08f`

## Finalized Report / Current Recommendation

Recommendation: keep [UID:000457] `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md` as the source-authored `FolderSelectDialog` constructor child, with canonical owner [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), emitter [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `RECONSTRUCTABLE:TRUE`, and emitter position `10`.

The current formal constructor body should not be promoted to a full first-draft C++ constructor body yet. The existing nonblank marker/no-code proof remains the correct formal C++ disposition because the constructor body is source-authored but still depends on unresolved DialogPane/control construction and layout helper APIs. A full body would have to invent source declarations for `sub_49D8A0`, `sub_49DC10`, `sub_49DFD0`, `sub_49E190`, `sub_4B78D0`, `sub_4B78F0`, control constructors, and several virtual control-placement/list calls. It would also risk replacing the constructor's proven inline drive loop with a synthetic `PopulateDriveList()` call, which the live MCP evidence rejects.

Callback result after supervisor acceptance: target metadata was raised from `84/90` to `86/91`, owner/emitter/reconstructable/position were kept unchanged, the formal marker block was kept in place, and current MCP session `2ec9c08f` evidence was incorporated at report-level detail. Stale support docs were updated; support docs already carrying same-or-greater detail are recorded below as already present.

## Supporting Research

Read and used:

- `tools/leaser/Agents/Agent-B003/goal.md`
- Project skill `ntk-b-agent-workflow` and `references/b-agent-research-and-implementation-workflow.md`
- `by-structure.md` sections relevant to by-memory source C++, owner/emitter rules, aggregate/container handling, and IDA MCP output discipline
- Target [UID:000457][0x004b1590-0x004b18d6.FolderSelectDialogConstructor](by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md)
- Support docs [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md), [UID:000459][0x004b1920-0x004b1a00.FolderSelectDialogOnCommand](by-memory/0x004b1920-0x004b1a00.FolderSelectDialogOnCommand.md), [UID:00045A][0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList](by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md), and [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md)
- Prior executed report lead `executed-b-agent-research/B013/000154-FolderSelectDialog-source-quality.md`; treated as a lead and rechecked with current MCP

Historical MCP incident context: an earlier stale/empty-session state was discarded. The final evidence pass used restored live session `2ec9c08f`; `idb_list` showed one active `NexusTK.exe.i64` worker and `server_health` was `ok`.

## Target

- UID: `000457`
- Target path: `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`
- Address range: `0x004b1590-0x004b18d6`
- Current IDA function: `sub_4B1590`, size `0x346` / `838` bytes
- Source role: source-authored `FolderSelectDialog` constructor body
- Direct owner: [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md)
- Source emitter: [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `NexusTK/ui/dialogs/FolderSelectDialog.cpp`
- Split parent: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md)

## Current Target State

After the implementation callback, the target records `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and `EMITTER_POSITION_OPTIONAL:10`.

The current formal `RECONSTRUCTION_CPP CODE` block is a marker:

```cpp
// No first-draft constructor body for 0x004b1590-0x004b18d6:
// the range is source-authored, but exact DialogPane/control construction
// and layout helper APIs are not source-safe enough to emit without inventing
// source declarations. Do not substitute sub_ labels or add a synthetic
// call to PopulateDriveList(); the constructor contains its own drive loop.
```

That marker remains correct after the current MCP pass and was kept unchanged during implementation. The target now captures owner/emitter, major fields, constructor caller, FolderTreePane construction, drive literal/buffer use, no-synthetic-`PopulateDriveList` policy, and the restored-session evidence detail from `2ec9c08f`.

## Heuristic / Inference Reanalysis And Validation

### Boundary and Split

MCP `lookup_funcs` under session `2ec9c08f` returned `0x004b1590` as `sub_4B1590`, size `0x346`, and reported `0x004b18d6` as not a function. It also found the next functions as `0x004b1920` size `0xe0`, `0x004b1a00` size `0x105`, `0x004b1b05` size `0x0b`, `0x004b1b10` size `0x0b`, `0x004b1b20` size `0x67`, and `0x004b1b90` size `0x155`.

`make_signature_for_range` confirmed eleven bytes of `0xCC` preceding the constructor at `0x004b1585-0x004b1590`. The successor range `0x004b18d6-0x004b1920` begins with ten `0xCC` bytes and then constructor cleanup/vtable restoration code, not a source continuation of the constructor. Successor padding `0x004b1b87-0x004b1b90` is nine `0xCC` bytes before the FolderTreePane island.

Conclusion: the half-open child range `0x004b1590-0x004b18d6` remains exact. Do not merge it with cleanup/padding, `OnCommand`, retained helper, adjustor thunks, destructor, or FolderTreePane.

### Constructor Behavior

MCP `decompile 0x004b1590` shows:

- Base/dialog initialization call `sub_49D8A0(this, word_60DB20, 16, 0)` at `0x004b15e4`.
- Three `FolderSelectDialog` vtable stores at `0x004b1601`, `0x004b1607`, and `0x004b1611`.
- Callback argument stored at `this+0x270` (`624`) at `0x004b161b`; accepted field name `m_resultCallback`.
- Multiple control/layout constructions through unresolved helper calls at `0x004b1621-0x004b1735`.
- `GetCurrentDirectoryA(0x104)` and a local drive-root buffer before `FolderTreePane` construction.
- Allocation of `0x17c` / `380` bytes and call to `0x004b1b90` at `0x004b178b`, then storage at `this+0x26c` (`620`); accepted field name `m_folderTreePane`.
- Two virtual calls on the `FolderTreePane` object after a layout rect, then retrieval of the inherited drive-list control through `this+0x1fc` (`508`) and vtable slot `+16`.
- Inline drive enumeration with `GetLogicalDrives`, `GetCurrentDirectoryA(0x104)`, `_toupper`, a `32`-entry loop, writes to `asc_66DA88[0]` / accepted `s_driveRootBuffer[0]`, `StringMenuItem` construction through `0x00516ff0`, append/count/select helper calls, and current-drive selection.
- Final setup call `sub_49DDD0(this, 2)` at `0x004b189b`.
- Optional initial path route: if `a3` is non-null, call `0x004b2730` on `this+0x26c` at `0x004b18b1`.

These facts strengthen behavior documentation but do not make the constructor body source-safe enough for formal C++.

### Caller and Callback Route

MCP `xrefs_to 0x004b1590` under session `2ec9c08f` found exactly one code xref: `0x0052986d` inside `sub_529790`, the documented MusicControlDialog command handler.

Bounded disassembly of `0x00529790` confirms the caller case:

- Allocates `0x274` / `628` bytes for the `FolderSelectDialog` object at `0x005297de-0x005297e3`.
- Reads a MusicControlDialog control/string route through `this+0x1fc`, control id `6`, and `sub_498C20`.
- Allocates a `0x18` / `24` byte concrete callback object at `0x00529823`.
- Stores the `PlainMemberFunctionObjectT<MusicControlDialog, String>` vtable at `0x00529842`.
- Stores method pointer `0x00529ee0` at `0x00529848`, zero adjustment at `0x0052984f`, and MusicControlDialog `this` at `0x00529856`.
- Calls `sub_584540` on the source string, pushes the resulting initial path and callback wrapper, and calls the constructor at `0x0052986d`.

Conclusion: MusicControlDialog is caller and concrete callback provider only. It is not the canonical owner or source emitter of the constructor.

### Vtable and Data Evidence

MCP `xrefs_to` confirms the three vtable base stores:

- `0x0061a45c` has refs at `0x004b1601`, cleanup `0x004b18e9`, and destructor `0x004b1b2c`.
- `0x0061a4bc` has refs at `0x004b1607`, cleanup `0x004b18ef`, and destructor `0x004b1b32`.
- `0x0061a4ec` has refs at `0x004b1611`, cleanup `0x004b18f9`, and destructor `0x004b1b3c`.

MCP `xrefs_to 0x0061a4f4` found the constructor data ref at `0x004b173a`, matching the `L"X:\\"` drive-root literal child. MCP `xrefs_to 0x0066da88` found constructor write/use refs at `0x004b183f` and `0x004b185b`, plus retained-helper refs at `0x004b1a8b` and `0x004b1aaa`.

Conclusion: vtable/data refs support FolderSelectDialog ownership and source placement, and also preserve the boundary between vtable data, read-only drive-root literal, mutable drive-root buffer, and executable method children.

### Retained Helper and No-Synthetic-Call Caveat

MCP `lookup_funcs` found `0x004b1a00` as a function of size `0x105`. MCP `xrefs_to 0x004b1a00` found zero refs.

MCP `decompile 0x004b1a00` shows a real source-shaped helper: inherited drive-list retrieval through `this[127]` / `DialogPane+0x1fc`, `GetLogicalDrives`, `GetCurrentDirectoryA(0x104)`, `_toupper`, a 32-drive loop, `s_driveRootBuffer[0]` writes, `StringMenuItem` construction, append, count, and selected-index calls.

The constructor independently contains an equivalent inline drive loop. There is no current code xref, vtable slot, or constructor call to `0x004b1a00`. The accepted `PopulateDriveList()` helper body on [UID:00045A] is useful retained source, but it must not be inserted as a synthetic constructor call.

### Source-Facing Names and C++ Blocker

Closed source-facing names:

- `this+0x26c` / `620`: `m_folderTreePane`
- `this+0x270` / `624`: `m_resultCallback`
- `this+0x1fc` / `508`: inherited DialogPane control/list infrastructure, not a direct FolderSelectDialog field
- `0x0061a4f4`: `kDefaultDriveRootLiteral` or literal `L"X:\\"`
- `0x0066da88`: `s_driveRootBuffer`, preferred over `s_driveRootName`
- `0x004b1a00`: `PopulateDriveList()` retained/no-entry helper

Still not source-safe for a constructor body:

- Exact DialogPane constructor/helper signature for `sub_49D8A0`
- Exact control insertion helper for `sub_49DC10`
- Exact layout/rect helpers `sub_4B78D0` and `sub_4B78F0`
- Exact frame/background/control setup helpers `sub_49DFD0`, `sub_49E190`, and `sub_49DDD0`
- Exact concrete control constructors for `sub_498040` and `sub_495BF0`
- Exact original callback alias/template spelling behind `FolderSelectCallback`

Therefore a first-draft constructor body would be decompiler-shaped or would invent APIs. The marker/no-code proof is the correct formal C++ output for this child until those support APIs are source-safe.

## Evidence Standards Used

I used live MCP evidence as mandatory authority for boundaries, xrefs, decompilation, disassembly, and numeric conversion. Existing by-* docs and the B013 executed report were treated as leads, then cross-checked against current session `2ec9c08f`.

I kept facts, inference, and rejected alternatives separate:

- Facts: exact function sizes, xrefs, data refs, decompile call sites, vtable stores, bytes/padding, and caller disassembly.
- Inference: source-facing field/helper names and source placement through class/file docs.
- Rejections: alternatives that would contradict current xrefs, data ownership, source split, or formal C++ safety rules.

I did not use generated labels such as raw `sub_` names, `asc_66DA88`, or decompiler temporaries as final source names. I used them only to describe IDA observations.

## Evidence Checked

MCP session `2ec9c08f`:

- `idb_list`: one active worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing, worker pid `12188`.
- `server_health`: `status ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: checked `0x004b1590`, `0x004b18d6`, `0x004b1920`, `0x004b1a00`, `0x004b1b05`, `0x004b1b10`, `0x004b1b20`, `0x004b1b90`, `0x0052986d`, and `0x004b2730`.
- `xrefs_to`: checked constructor, retained helper, vtable bases, drive-root literal, and mutable drive-root buffer.
- `decompile`: checked `0x004b1590` and `0x004b1a00`.
- `disasm`: bounded disassembly for `0x00529790` MusicControlDialog caller route.
- `make_signature_for_range`: checked `0x004b1585-0x004b1590`, `0x004b18d6-0x004b1920`, and `0x004b1b87-0x004b1b90`.
- `int_convert`: converted `0x346`, `0x274`, `0x270`, `0x26c`, `0x1fc`, `0x104`, `0x20`, `0x17c`, `0x114`, and `0x118`.

One schema correction was encountered and resolved: `decompile` rejected unsupported `max_lines`; the calls were retried without that parameter and succeeded. Earlier stale session `e63ee655` / empty-session checks are historical incident context only and are not used as final evidence.

Search/read leads:

- Current target and direct support docs listed under `Supporting Research`.
- Prior executed B013 report for UID000154, opened because it directly concerned this constructor split and child formal block.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination if accepted | Action | Verification state |
| --- | --- | --- | --- | --- |
| Target remains constructor child `0x004b1590-0x004b18d6`, size `0x346` / `838`. | MCP `lookup_funcs`, `make_signature_for_range`, target/parent docs. | Applied to `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`; support rows updated in `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`, `by-class/FolderSelectDialog.md`, and `by-file/FolderSelectDialog.md`. | incorporate | applied |
| Metadata should become `COMPLETION:86`, `CONFIDENCE:91`, owner `000059`, emitter `0000JF`, position `10`, reconstructable true. | Current docs plus refreshed live MCP evidence. | Applied to target metadata; owner/emitter/reconstructable/position preserved; support docs now name `86/91` where the constructor row was stale. | incorporate | applied |
| Formal C++ should remain the existing constructor marker/no-code proof, not a full body. | Constructor decompile still relies on unresolved helper/control APIs and has inline drive loop. | Target formal `RECONSTRUCTION_CPP CODE` block was left unchanged; C++ readiness notes were extended with current blocker proof. | already-present plus evidence refresh | applied |
| Vtable stores at `0x004b1601`, `0x004b1607`, `0x004b1611` to `0x0061a45c`, `0x0061a4bc`, `0x0061a4ec`. | MCP `decompile` and `xrefs_to`. | Applied to target evidence and support notes in class/file/parent. `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md` already had same-or-greater vtable handling and was not edited. | incorporate | applied |
| Callback field at `this+0x270` / `624` is `m_resultCallback`. | MCP decompile store at `0x004b161b`, OnCommand/destructor docs. | Applied to target, class, file, and parent docs. | incorporate | applied |
| FolderTreePane member at `this+0x26c` / `620` is `m_folderTreePane`. | MCP decompile allocation/call/storage at `0x004b176f-0x004b17ac`. | Applied to target, class, file, and parent docs. | incorporate | applied |
| Constructor contains its own drive loop and must not call synthetic `PopulateDriveList()`. | MCP decompile constructor plus `xrefs_to 0x004b1a00` zero. | Applied to target, class, file, and parent docs. `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md` already preserved zero-xref retained-helper proof and no invented caller policy, so it was not edited. | incorporate | applied |
| MusicControlDialog caller route is caller/callback evidence only. | MCP `xrefs_to 0x004b1590`; disasm `0x00529790` case with callback object and call at `0x0052986d`. | Applied to target, class/file/parent support notes, and `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md` with allocation sizes and method pointer proof. | incorporate | applied |
| Reject MusicControlDialog ownership, FolderTreePane ownership, FunctionObjects ownership, aggregate emission, raw sub naming, padding/no-code treatment, and invented constructor body. | Ownership/source split docs plus current MCP. | Applied to target negative/C++ readiness notes and preserved in class/file/parent/caller support notes; drive-root data docs already reject unrelated ownership. | incorporate | applied |
| Current MCP session replaced stale MCP incident state. | `idb_list`/`server_health` under `2ec9c08f`. | Applied to target, class, file, and parent docs as current evidence; stale session history retained only in this report body. | incorporate | applied |
| Drive-root literal and mutable buffer support detail. | Current support docs show literal `L"X:\\"`, constructor ref `0x004b173a`, buffer refs `0x004b183f` / `0x004b185b` and helper refs `0x004b1a8b` / `0x004b1aaa`. | `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md` and `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md` were inspected and already contained same-or-greater accepted detail, so they were not edited. | already-present | already-present |

## Positive Evidence Summary

- `0x004b1590` is a real IDA function start, size `0x346`; `0x004b18d6` is not a function and marks the half-open end before cleanup/padding.
- The constructor installs all three FolderSelectDialog vtable views and is tied to the class vtable-data page.
- The constructor stores the caller callback at `this+0x270` and the hosted `FolderTreePane` at `this+0x26c`.
- One direct caller at `0x0052986d` constructs the object from MusicControlDialog and passes a concrete callback wrapper plus initial path.
- The constructor references the drive-root literal and mutable drive-root buffer, and it enumerates drives inline.
- The separate retained helper at `0x004b1a00` is real source-shaped code but has zero direct xrefs; this supports retaining it as a private helper while prohibiting a synthetic constructor call.
- Current class/file/parent docs already support owner [UID:000059] and emitter [UID:0000JF].

## Negative Evidence Summary

- No evidence supports ownership by MusicControlDialog; it only allocates/calls and supplies the concrete callback wrapper.
- No evidence supports ownership by FolderTreePane; it is allocated/hosted by the dialog and its source island begins after successor padding at `0x004b1b90`.
- No evidence supports FunctionObjects ownership; FunctionObjects owns callback template machinery, not the dialog constructor.
- No direct xref to `0x004b1a00` supports calling `PopulateDriveList()` from the constructor.
- The constructor is not padding or compiler-only no-code; it has a full source-authored constructor body and should remain reconstructable.
- A full first-draft constructor body would require invented final-source names for control construction, layout, and DialogPane helpers.
- Raw labels such as `sub_4B1590`, `sub_49D8A0`, `sub_4B78D0`, `asc_66DA88`, `_DWORD *`, or `this[127]` are not acceptable final source.
- The mixed parent [UID:000154] must remain non-emitting; aggregate emission would duplicate or cross child-owned ranges.

## Ranked Ownership Analysis

1. [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md), emitted through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md): best-supported. The constructor writes FolderSelectDialog vtables, initializes FolderSelectDialog fields, owns the callback pointer and hosted tree member, and belongs to the exact FolderSelectDialog split island.
2. [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md) as direct file emitter: correct emitter, not canonical class owner for the child metadata. The by-file page is the source output route for file-scope method marker/code.
3. [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md) / [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md): rejected as owner. It is a caller and concrete callback provider only.
4. [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) / [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md): rejected as owner. The constructor allocates this hosted control, but FolderTreePane owns its own constructor and tree behavior starting at `0x004b1b90`.
5. [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md): rejected as owner. It owns template callback support, not the dialog.
6. Parent [UID:000154] aggregate emission: rejected. It is already a non-emitting split container and must not absorb child C++.
7. No-owner/non-emitting or padding treatment: rejected. The target is a real source-authored constructor and must remain reconstructable.

## Source Placement

Keep source placement under [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), `NexusTK/ui/dialogs/FolderSelectDialog.cpp`.

The constructor should continue to emit a marker through the file page at position `10`. The class page should continue to emit class-level declaration/`[[CHILDREN]]` only. The parent executable aggregate remains a non-emitting split container. Vtable data remains source-declared/generated-binary covered by the class declaration. FolderTreePane implementation remains under `NexusTK/ui/controls/FolderTreePane.cpp`. MusicControlDialog remains a caller under its own source module.

## First-Draft C++ Recommendation

Do not insert a full constructor body for [UID:000457] during an implementation callback. Keep the formal block as a marker/no-code proof. The existing marker is still acceptable:

```cpp
// No first-draft constructor body for 0x004b1590-0x004b18d6:
// the range is source-authored, but exact DialogPane/control construction
// and layout helper APIs are not source-safe enough to emit without inventing
// source declarations. Do not substitute sub_ labels or add a synthetic
// call to PopulateDriveList(); the constructor contains its own drive loop.
```

Reason: a source-like constructor body would have to name unresolved DialogPane/control helpers and layout APIs. The current evidence supports member names, callback ownership, drive loop behavior, and source placement, but not enough exact source API spelling to avoid decompiler-shaped code. The no-code proof is exact and target-specific rather than a deferral.

## Final Recommendation

Apply a narrow evidence-refresh and score update:

- Target metadata: `COMPLETION:86`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and `EMITTER_POSITION_OPTIONAL:10`.
- Target formal C++: keep existing marker/no-code proof unchanged unless the supervisor wants the marker comment to mention the current MCP session; do not insert a full constructor body.
- Target evidence: add current MCP session `2ec9c08f` facts at report-level detail: range, size, padding, vtable stores/xrefs, callback/tree offsets, MusicControlDialog caller/callback route, inline drive loop, drive-root literal/buffer refs, initial-path selection, retained helper zero-xref proof, and `int_convert` conversions.
- Support docs: update only if current-session detail is absent or stale; otherwise mark already present in the report ledger during implementation.

No split, rename, new child page, owner change, emitter change, or generated/manual coverage edit is recommended.

## Recommended Target Doc Changes

Target: `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`

Recommended edits if accepted:

- Set `COMPLETION:86` and `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:000059`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and `EMITTER_POSITION_OPTIONAL:10`.
- Keep the formal C++ marker/no-code proof unchanged, or only add session evidence in prose outside the formal block.
- Add current MCP session `2ec9c08f` evidence:
  - `idb_list` active `NexusTK.exe.i64`; `server_health` `ok`.
  - `0x004b1590` function size `0x346` / `838`; `0x004b18d6` not a function.
  - Preceding `0xCC` padding and successor cleanup/padding signature.
  - Vtable stores to `0x0061a45c`, `0x0061a4bc`, `0x0061a4ec`.
  - Callback store at `this+0x270` / `624`; tree member store at `this+0x26c` / `620`; inherited control infra at `this+0x1fc` / `508`.
  - `FolderTreePane` allocation `0x17c` / `380` and call at `0x004b178b`; initial-path call to `0x004b2730` at `0x004b18b1`.
  - Inline drive loop using `GetLogicalDrives`, `GetCurrentDirectoryA(0x104)` / `260`, `_toupper`, `32` drive slots, `s_driveRootBuffer`, and `StringMenuItem` allocation `0x118` / `280`.
  - Caller at `0x0052986d` in `sub_529790` with object allocation `0x274` / `628` and concrete callback wrapper allocation `0x18`.
  - Zero xrefs to retained helper `0x004b1a00`; do not synthesize `PopulateDriveList()` call.
- Preserve negative evidence rejecting MusicControlDialog ownership, FolderTreePane ownership, FunctionObjects ownership, aggregate emission, raw naming, padding/no-code treatment, and invented full constructor body.

## Recommended Support Doc Changes

- `by-class/FolderSelectDialog.md`: if stale, update the constructor method row/evidence notes to mention current MCP session `2ec9c08f`, target score `86/91`, and the refreshed no-code proof. Keep class metadata unless supervisor decides the current-session refresh justifies a class score bump; this report does not require one.
- `by-file/FolderSelectDialog.md`: if stale, update the proposed contents/source-output note for UID000457 to say the constructor still emits the marker through UID0000JF at position `10` and current MCP reconfirmed the inline drive loop/no-synthetic-`PopulateDriveList` caveat. Keep file metadata unless separately accepted.
- `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`: update the UID000457 row/evidence notes if it lacks the current `2ec9c08f` evidence and target score `86/91`; preserve parent `RECONSTRUCTABLE:FALSE`, blank emitter/code, and non-emitting split-container role.
- `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`: optional support update only if current-session vtable-store wording is absent; preserve source-declared/generated-binary class-declaration handling.
- `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md`: likely already present at same-or-greater detail; only update if it lacks the refreshed zero-xref proof from `2ec9c08f`.
- `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`: optional; edit only if the caller route lacks the callback-object allocation details and the `0x0052986d` constructor call. It remains a caller/consumer, not owner.
- `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md` and `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`: likely already present. Update only if stale current-session refs need preserving.

## Score And Metadata Recommendation

Current target score: `COMPLETION:84`, `CONFIDENCE:90`.

Recommended target score: `COMPLETION:86`, `CONFIDENCE:91`.

Rationale:

- Completion can rise because the current MCP pass reconfirmed exact boundaries, active session provenance, caller/callback route, vtable/data refs, numeric conversions, and the first-draft C++ blocker with fresh evidence. The page no longer depends only on older B013/B014 evidence.
- Confidence can rise by one point because the restored session `2ec9c08f` independently confirms the same boundary and behavior facts after the MCP incident, including xrefs and decompile details.
- Completion should not rise into the high 80s because the constructor still lacks a formal source body. The exact DialogPane/control construction APIs and final FunctionObjects/control helper spellings remain bounded but not source-safe enough.
- Confidence should remain below final-audit range because exact original source names for constructor helper APIs, layout objects, callback alias, and control constructors are inferred/descriptive rather than symbol-proven.

Owner/emitter changes: none.

Split/rename/new child changes: none.

## Open Questions With Attempted Resolution

- Can the marker be promoted to a first-draft constructor body? Resolved: no. Current MCP confirms source-authored behavior, but unresolved helper/control/layout APIs would force invented source declarations or raw `sub_` code.
- Is the constructor allowed to call `PopulateDriveList()` in source? Resolved for this target: no. The constructor contains its own drive loop and `xrefs_to 0x004b1a00` reports zero refs.
- Are `m_resultCallback` and `m_folderTreePane` still defensible? Resolved: yes. MCP confirms stores at `this+0x270` and `this+0x26c`; support docs already use those names.
- Is `this+0x1fc` a FolderSelectDialog member? Resolved: no. Keep inherited DialogPane control/list infrastructure.
- Is MusicControlDialog the owner because it is the only caller? Resolved: no. It supplies reachability and callback construction only.
- What remains unresolved? Exact original source spelling for `FolderSelectCallback`, DialogPane/control/layout helpers, and control constructors. This is a confidence/C++ cap, not a blocker for ownership or marker emission.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md --apply --queue-timeout 240` | `000000005528` | `2026-07-03T15:10:18-04:00` | `0` | `1` | `completion_update: 1`, `confidence_update: 1`, projected stats update, stats row removals for UID000457, `generated_refresh: deferred`. |
| `by-class/FolderSelectDialog.md` | `python .\tools\validator.py --mode file --file by-class/FolderSelectDialog.md --apply --queue-timeout 240` | `000000005530` | `2026-07-03T15:10:26-04:00` | `0` | `1` | projected stats update, stats incremental noop, `generated_refresh: deferred`. |
| `by-file/FolderSelectDialog.md` | `python .\tools\validator.py --mode file --file by-file/FolderSelectDialog.md --apply --queue-timeout 240` | `000000005532` | `2026-07-03T15:10:29-04:00` | `0` | `1` | projected stats update, stats incremental noop, `generated_refresh: deferred`. |
| `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md --apply --queue-timeout 240` | `000000005534` | `2026-07-03T15:10:31-04:00` | `0` | `1` | projected stats update, stats incremental noop, `generated_refresh: deferred`. |
| `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md` | `python .\tools\validator.py --mode file --file by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md --apply --queue-timeout 240` | `000000005536` | `2026-07-03T15:10:34-04:00` | `0` | `1` | `reference_index_add: 1` for UID000457, projected stats update, stats incremental noop, `generated_refresh: deferred`. |

Warnings/errors: no validator errors; each edited file returned exit `0` and `ok: 1`.

Generated freshness/side effects: validator reported `generated_refresh: deferred` for each scoped file command and updated the projected path completion section in `project-level/-auto-completion-stats.md`. These were validator-owned side effects only; no generated/project-level files, coverage reports, validator state, registries, queues, archives, or lifecycle files were manually edited by B003.

## Changed Files

Changed by-* files:

- `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`
- `by-class/FolderSelectDialog.md`
- `by-file/FolderSelectDialog.md`
- `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`
- `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`

Changed report file:

- `tools/leaser/Agents/Agent-B003/research/000457-FolderSelectDialogConstructor-source-quality.md`

Inspected and left unchanged because accepted detail was already present at same-or-greater depth:

- `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`
- `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md`
- `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`
- `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`

Leases used: B003 leased the five edited by-* files immediately before editing and validation, then released all five immediately after validators completed. Release command succeeded for each leased file.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Target `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`: set `COMPLETION:86`, `CONFIDENCE:91`; kept owner `000059`, reconstructable true, emitter `0000JF`, position `10`. Proof: target metadata updated and validator `000000005528` reported completion/confidence updates with exit `0`, `ok: 1`.
- [x] Target formal C++: kept the existing marker/no-code proof; did not insert a full constructor body. Proof: formal `RECONSTRUCTION_CPP CODE` block remains the marker comment and no synthetic `PopulateDriveList()` call was added.
- [x] Target evidence: added current MCP session `2ec9c08f`, exact range `0x004b1590-0x004b18d6`, size `0x346` / `838`, boundary/padding proof, vtable stores, caller route, field offsets, drive-loop behavior, initial-path route, retained-helper zero-xref proof, and `int_convert` conversions. Proof: target Status, Boundary, Source Behavior, Reachability And Evidence, C++ Readiness Notes, Score Rationale, and Changes sections updated.
- [x] Target negative evidence: preserved no synthetic `PopulateDriveList()` call, rejected raw `sub_`/`asc_` names, rejected padding/no-code treatment, rejected MusicControlDialog/FolderTreePane/FunctionObjects ownership, and rejected parent aggregate emission. Proof: target C++ Readiness Notes, Ownership And Source Placement, Reachability And Evidence, and Changes sections preserve these points.
- [x] Support `by-class/FolderSelectDialog.md`: updated constructor method/evidence row and behavior notes with current-session detail and target score. Proof: method inventory row now records `86/91`, session `2ec9c08f`, numeric offsets/sizes, caller allocation details, and zero-xref retained-helper policy; validator `000000005530` exit `0`, `ok: 1`.
- [x] Support `by-file/FolderSelectDialog.md`: updated proposed contents/evidence notes for UID000457. Proof: UID000457 row and Evidence Notes now include current-session detail, inline drive loop, caller route, zero xrefs to retained helper, and marker-through-file status; validator `000000005532` exit `0`, `ok: 1`.
- [x] Support `by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md`: updated UID000457 row/evidence notes while preserving parent non-emitting metadata and blank C++. Proof: parent row now records `86/91`; parent remains `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++; validator `000000005534` exit `0`, `ok: 1`.
- [x] Support `by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md`: already present at same-or-greater detail. Proof: existing doc already records vtable bases/slots, constructor/cleanup/destructor stores, source-declared/generated-binary class-declaration handling, and no handwritten vtable array; left unchanged.
- [x] Support `by-memory/0x004b1a00-0x004b1b05.FolderSelectDialogPopulateDriveList.md`: already present at same-or-greater detail. Proof: existing doc already records source-shaped retained helper, range `0x004b1a00-0x004b1b05`, zero checked inbound route, first-draft helper body, and no invented constructor call; left unchanged.
- [x] Caller/data supports: updated MusicControlDialog caller doc and marked drive-root data docs already present. Proof: `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md` now records object allocation `0x274` / 628, callback wrapper allocation `0x18`, method pointer `0x00529ee0`, initial-path conversion, and constructor call; validator `000000005536` exit `0`, `ok: 1`. `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md` already records `L"X:\\"` and constructor ref `0x004b173a`; `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md` already records constructor refs `0x004b183f` / `0x004b185b`, helper refs `0x004b1a8b` / `0x004b1aaa`, size/conversions, and source name `s_driveRootBuffer`; both left unchanged.
- [x] Run scoped validators from `source-3/project-documentation` for every edited by-* file and record command, command id, timestamp, exit code, ok count, warnings, side effects, and generated freshness. Proof: validator table above lists commands `000000005528`, `000000005530`, `000000005532`, `000000005534`, and `000000005536`, all exit `0`, `ok: 1`; generated refresh deferred and projected stats updates recorded.
- [x] Update this report's Claim And Incorporation Ledger verification states from `proposed` to `applied`, `already-present`, or `excluded-with-reason`, with exact destinations/proof. Proof: ledger above now records applied/already-present states.
- [x] Update this checklist after implementation; leave no broad unchecked items except explicit blockers. Proof: all accepted items are checked; no blockers remain.

Callback stop condition: `READY_FOR_SUPERVISOR_EXECUTE`. B003 did not run `execute_report`, any dry-run/probing report execution variant, lifecycle/archive command, registry command, manual report move, generated/manual coverage edit, or supervisor-ledger edit.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000005546","destination_path":"executed-b-agent-research/B003/000457-FolderSelectDialogConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/000457-FolderSelectDialogConstructor-source-quality.md","timestamp":"2026-07-03T15:14:51-04:00","uid":"000457"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
