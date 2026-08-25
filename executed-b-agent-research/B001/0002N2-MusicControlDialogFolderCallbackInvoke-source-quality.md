# 0002N2 MusicControlDialogFolderCallbackInvoke Source-Quality Report
** TARGET-REPORT-UID:0002N2 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: malformed TARGET-REPORT-UID header **

**TARGET-REPORT-UID:** 0002N2  
**ASSIGNMENT:** B001-report-0002N2-music-control-dialog-folder-callback-invoke-20260625  
**MODE:** report-only research; no by-* or generated files edited

## Final Recommendation

[UID:0002N2] `by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md` should remain a concrete `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke-wrapper page with:

- `CANONICAL_OWNER: 0000AL`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000JO`
- blank emitter position
- recommended score `COMPLETION: 87`, `CONFIDENCE: 90`

This is not a MusicControlDialog-owned handwritten method. The exact function bytes are the compiler-emitted invoke wrapper for the concrete FunctionObjects template instance. MusicControlDialog owns the construction site and target member function; `FunctionObjects` owns the reusable source template route.

The target should not get a decompiler-shaped hand-written body. It should get a formal comment-only no-code proof in the C++ block so the emitter no longer treats it as an unexplained empty marker:

```cpp
// Compiler-emitted invoke wrapper for PlainMemberFunctionObjectT<MusicControlDialog, String>;
// generated from the shared FunctionObjects template declaration and the
// MusicControlDialog folder-selection binding in [UID:0003MD].
```

## Current Target State

Current target metadata before implementation:

- `COMPLETION: 85`
- `CONFIDENCE: 88`
- `CANONICAL_OWNER: 0000AL`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000JO`
- formal C++ block blank

The existing prose is directionally correct: it already treats the range as a generated callback invoke wrapper, records the vtable/data xref, records no direct callers, and routes source to the FunctionObjects template plus the MusicControlDialog construction site. The missing piece is target-level current MCP proof and a formal no-code/comment proof that prevents stale generated empty-marker output.

## IDA MCP Evidence

IDA MCP was available and used as mandatory evidence. Active session:

- session `80de0a67`
- IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- module `NexusTK.exe`
- imagebase `0x400000`
- `server_health` status `ok`
- auto-analysis ready and Hex-Rays ready

Target identity:

- `lookup_funcs 0x0052a3e0` returns `sub_52A3E0`, size `0x5e`.
- `lookup_funcs 0x0052a43e` returns successor `sub_52A43E`, size `0xb`, so the target range `0x0052a3e0-0x0052a43e` exactly covers the invoke wrapper and excludes the following adjustor thunk.
- `tools/int_convert.py` confirms `0x5e` is decimal `94`.

Target behavior from MCP decompile and disassembly:

- The wrapper initializes a local string-like temporary, calls `sub_582A90` to copy/prepare the incoming string argument, and then performs an indirect member-function call through the stored callback fields.
- The dispatch sequence loads the target object adjustment fields at callback-object offsets `+0x10` and `+0x0c`, adds them, loads the stored member target from `+0x8`, calls it indirectly, then calls `sub_582B70` for cleanup.
- The function ends with `retn 4`, matching a thiscall-style single explicit argument invoke wrapper.
- MCP `callees` and `analyze_function` report only `sub_582A90` and `sub_582B70` as direct callees.

Cross-reference and vtable evidence:

- `analyze_function 0x0052a3e0` reports no callers and one data xref from `0x0061fcf8`.
- `xref_query` to `0x0052a3e0` reports zero code xrefs and one data xref at `0x0061fcf8`.
- `find_bytes e0 a3 52 00` finds the target function pointer only at `0x0061fcf8`.
- `find_bytes f8 fc 61 00` finds no references to the invoke slot address itself, which is expected for virtual callback dispatch.
- `get_bytes 0x0061fcec` shows the concrete vtable region contains `0x0052a4a0` at `0x0061fcec` and `0x0052a3e0` at `0x0061fcf8`.
- `get_int 0x0061fcec` returns `0x0052a4a0`, the sibling destructor [UID:0002N3].
- `get_int 0x0061fcf8` returns `0x0052a3e0`, this invoke wrapper.

Construction-site evidence:

- `xref_query` to `0x0061fcec` reports the vtable base is stored at `0x00529842` inside `sub_529790` / [UID:0003MD].
- The command-handler case allocates the callback object with size `0x18`; `tools/int_convert.py` confirms `0x18` is decimal `24`.
- At `0x0052983d`, the code calls `sub_4F4A80` for base construction.
- At `0x00529842`, it stores vtable `0x0061fcec`.
- At `0x00529848`, it stores target member `0x00529ee0`, which MCP resolves to `sub_529EE0` / [UID:0003MI].
- At `0x0052984f`, it stores zero adjustment.
- At `0x00529856`, it stores the `MusicControlDialog` object pointer.
- At `0x0052986d`, it passes the constructed callback object into the FolderSelectDialog setup path.

These facts prove the wrapper is live through a vtable/data route even though it has no direct code callers.

## Ownership And Source Placement

Recommended ownership ranking:

1. [UID:0000AL] `PlainMemberFunctionObjectT<void (__thiscall MusicControlDialog::*)(class m::String), class MusicControlDialog>` remains the canonical owner because this range is one concrete class instantiation of the function-object template.
2. [UID:0000JO] `FunctionObjects` remains the emitter because the reusable source belongs to the FunctionObjects template/header family.
3. [UID:0003MD] `MusicControlDialogHandleControlCommand` owns the concrete construction and binding site only.
4. [UID:0003MI] `MusicControlDialogFolderPathSelected` owns the target member behavior only.
5. `FolderSelectDialog` owns storage/consumer dispatch of the callback, not this wrapper implementation.

Rejected alternatives:

- A handwritten concrete C++ invoke body is rejected because the body is generated from the template declaration and would overfit Hex-Rays temporary-string details.
- Keeping the formal block blank is rejected because the current code-entry gate is met and a precise comment-only proof is available.
- Moving ownership to MusicControlDialog is rejected because its proven role is construction and target-member handling, not reusable callback-object implementation.
- Moving ownership to FolderSelectDialog is rejected because it stores and invokes callback interfaces but does not define this concrete wrapper.
- Treating the target as no-owner/non-emitting is rejected because the vtable slot, construction site, and emitter route are proven.

## Recommended Target Updates

For `by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md`:

- Update score to `COMPLETION: 87`, `CONFIDENCE: 90`.
- Keep `CANONICAL_OWNER: 0000AL`, `RECONSTRUCTABLE: TRUE`, `EMITTER_UIDS: 0000JO`, and blank emitter position.
- Replace the blank formal C++ block with the exact comment-only block in the Final Recommendation section.
- Update the item summary to mention the exact vtable slot `0x0061fcf8`, construction-site stores at `0x00529842-0x00529856`, indirect member call through stored fields `+0x8`, `+0x0c`, and `+0x10`, and generated-template no-code status.
- Add a current B001 MCP evidence section recording session `80de0a67`, `sub_52A3E0` size `0x5e` / 94 bytes, no code callers, one data xref from `0x0061fcf8`, construction binding to `sub_529EE0`, and the negative byte-search proof for slot-address references.
- Add score rationale that the target is above the old 85/88 because current MCP evidence now proves exact range, vtable route, construction binding, and body semantics, but below final because the exact original template header spelling and typedef spelling remain unresolved at shared FunctionObjects level.

## Recommended Support Updates

Recommended support edits after supervisor acceptance:

- `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`: add a short B001 target-specific note that [UID:0002N2] now has current MCP proof for the invoke body and should use a formal comment-only no-code proof. Existing B009 vtable and construction evidence is already strong; no score change is required unless the supervisor wants support-score alignment.
- `by-file/FunctionObjects.md`: add or refine the proposed-content note so [UID:0002N2] emits the comment-only no-code proof from the shared template route instead of an empty marker or handwritten concrete body.
- `by-type/by-template/FunctionObjectTemplates.md`: add the same policy for `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke wrappers: exact target pages may carry comment-only proof, while reusable source stays in the shared template declaration and concrete construction site.

No support edit appears necessary for:

- `by-file/MusicControlDialog.md`
- `by-class/MusicControlDialog.md`
- `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`
- `by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md`
- `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`
- `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md`
- `by-file/FolderSelectDialog.md`

Those pages already contain the construction/consumer/vtable split at equal or greater detail. The implementation pass should only touch them if it finds stale score or route references that conflict with the accepted target change.

## Generated Freshness Notes

Read-only generated checks show stale output that should be refreshed by validators after implementation:

- `auto-generated/NexusTK/util/FunctionObjects.cpp` currently contains a stale [UID:0002N2] empty emitter marker with old `Completion:76 | Confidence:86`.
- `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-research-tracker.md` also show stale target score/state for [UID:0002N2].

Do not manually edit those files. The implementation callback should use file validators with `--wait-generated` and then verify the generated `FunctionObjects.cpp` header/entry is refreshed at the validator command and no longer reports the stale empty marker for [UID:0002N2].

## Validator Plan For Implementation Callback

No validators were run during this report-only pass. After supervisor acceptance and by-* edits, run validators for every edited by-* file. Expected commands if the recommended edits are accepted:

> Executable block R001 was removed from this report and preserved verbatim in [0002N2-MusicControlDialogFolderCallbackInvoke-source-quality-removed.md](0002N2-MusicControlDialogFolderCallbackInvoke-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation pass leaves any listed support page unchanged, skip its validator and record why.

## Open Questions

- The exact original FunctionObjects header spelling remains a shared 0000JO/0001WQ issue. This does not block the target comment-only proof because the binary role and source route are proven.
- The exact source typedef spelling for the string argument may be `String` or the longer `mystr::StringBase<wchar_t, ...>` spelling. The report uses `String` as the documented project shorthand and avoids a concrete source body.

## Changed Files In This Report Pass

Only this report file was created:

- `tools/leaser/Agents/Agent-B001/research/0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md`

No by-* documentation, generated files, coverage reports, project-level generated files, validator state/cache, or IDA database files were edited. No leases were needed for the report-only file. Existing unrelated dirty/deleted files in the worktree were not touched.

## Implementation Tracking Checklist

- [x] Supervisor validates and accepts this report before any by-* implementation edits. Proof: supervisor callback on 2026-06-25 accepted this report and assigned implementation for [UID:0002N2].
- [x] Implementation callback confirms no active lease conflicts for every by-* file before editing. Proof: `tools/leaser/Agents/current_leases.md` was checked before leasing; no active lease touched the four edit targets. B001 then leased exactly `by-memory/0x0052a3e0-0x0052a43e.MusicControlDialogFolderCallbackInvoke.md`, `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md`, `by-file/FunctionObjects.md`, and `by-type/by-template/FunctionObjectTemplates.md`.
- [x] Update [UID:0002N2] metadata to `COMPLETION: 87`, `CONFIDENCE: 90`, preserving owner `0000AL`, `RECONSTRUCTABLE: TRUE`, emitter `0000JO`, and blank emitter position. Proof: target metadata now reads `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000AL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JO`, and blank `EMITTER_POSITION_OPTIONAL:`.
- [x] Replace [UID:0002N2]'s blank formal C++ block with the exact comment-only no-code proof from this report. Proof: target `RECONSTRUCTION_CPP CODE` now contains the three comment lines for the compiler-emitted `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke wrapper; validator UID-link insertion expanded `[UID:0003MD]` to the standard target link while preserving the accepted comment-only/no-body proof.
- [x] Add B001 MCP evidence to [UID:0002N2]: session `80de0a67`, size `0x5e` / 94 bytes, one vtable data xref from `0x0061fcf8`, no code callers, construction stores at `0x00529842-0x00529856`, and indirect call through fields `+0x8`, `+0x0c`, `+0x10`. Proof: target `IDA Evidence` now records session `80de0a67`, `lookup_funcs` target/successor facts, 94-byte conversion proof, no code callers, data xref/vtable slot `0x0061fcf8`, negative byte-search proof, construction stores `0x00529842-0x00529856`, target member `0x00529ee0`, and indirect call fields `+0x8/+0x0c/+0x10`.
- [x] Update [UID:0002N2] summary, status, reconstruction notes, score rationale, and recent-changes notes to match the accepted target route. Proof: target item summary, `Status`, `Behavior`, `Reconstruction Notes`, `Ownership, Rejected Alternatives, And Score Rationale`, and `Changes` sections now describe the current comment-only generated-template route and score rationale.
- [x] Add the small [UID:0000AL] support note for [UID:0002N2]'s current invoke-wrapper proof and comment-only no-code status, if accepted. Proof: `by-class/PlainMemberFunctionObjectT_void____thiscall_MusicControlDialog_____class_m__h73bc206d7ae6.md` now updates the invoke row, evidence notes, and changes log with B001 current MCP proof and the formal comment-only target policy.
- [x] Add the [UID:0000JO] FunctionObjects note that [UID:0002N2] should emit the comment-only proof rather than an empty marker or concrete handwritten body, if accepted. Proof: `by-file/FunctionObjects.md` now updates the [UID:0000AL] proposed-content row, adds the B001 policy paragraph/evidence note, and records the 2026-06-25 change entry.
- [x] Add the [UID:0001WQ] FunctionObjectTemplates migration note for `PlainMemberFunctionObjectT<MusicControlDialog, String>` invoke wrappers, if accepted. Proof: `by-type/by-template/FunctionObjectTemplates.md` now records the target-level comment-only policy near the UserPane precedent and replaces the stale MusicControlDialog blank-block guidance with the B001 0002N2 policy.
- [x] Recheck the listed MusicControlDialog, FolderSelectDialog, parent aggregate, read-only data, construction-site, and target-member pages for stale conflicting references; edit only if a conflict is found. Proof: targeted `rg` checked `by-file/MusicControlDialog.md`, `by-class/MusicControlDialog.md`, `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`, `by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md`, `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`, `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md`, and `by-file/FolderSelectDialog.md`; no stale conflict required edits or extra validators.
- [x] Run scoped validators with `--apply --queue-timeout 240 --wait-generated` for every edited by-* file. Proof: all four required validators exited `0` with `ok: 1`: target command `000000001832` at `2026-06-25T17:24:43-04:00`; class command `000000001834` at `2026-06-25T17:24:58-04:00`; FunctionObjects command `000000001837` at `2026-06-25T17:25:18-04:00`; FunctionObjectTemplates command `000000001839` at `2026-06-25T17:25:37-04:00`. Validator output still reports unrelated stale registry/missing-reference warnings already present in the project state.
- [x] Verify generated freshness after validators, especially `auto-generated/NexusTK/util/FunctionObjects.cpp` no longer showing [UID:0002N2] as stale `Completion:76 | Confidence:86 | Empty Emitter Marker`. Proof: generated `auto-generated/NexusTK/util/FunctionObjects.cpp` header is `validator-command-id: 000000001848`, `validator-refreshed-at: 2026-06-25T17:27:33-04:00`, newer than the last scoped validator; [UID:0002N2] now appears as `Completion:87 | Confidence:90` with the comment-only proof and no stale `Completion:76 | Confidence:86 | Empty Emitter Marker` entry.
- [x] Do not manually edit generated files, coverage reports, project-level generated files, validator state/cache, or IDA DB files. Proof: manual edits were limited to four by-* docs plus this B001 report checklist; generated/project-level/tool-state changes were validator side effects only, and IDA MCP use was read-only health/evidence status.
- [x] Release every implementation lease immediately after each edit/validator batch. Proof: B001 unleased the four by-* targets after validators; `tools/leaser/Agents/current_leases.md` was rechecked and shows no active B001 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md","timestamp":"2026-06-25T17:35:00","uid":"0002N2"} -->
<!-- {"agent":"B001","command_id":"000000023041","details":"report marked for revalidation","event":"needs-revalidation","issue":"malformed TARGET-REPORT-UID header","source_path":"executed-b-agent-research/B001/0002N2-MusicControlDialogFolderCallbackInvoke-source-quality.md","timestamp":"2026-08-13T00:49:38-04:00","uid":"0002N2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
