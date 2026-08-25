** TARGET-REPORT-UID:0002IB **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B015 Research Report: 0002IB HierListDefaultInsertWrapper Source Quality

Assignment: `B015-report-0002IB-hier-list-default-insert-wrapper-20260626`  
Rework assignment: `B015-rework-0002IB-hier-list-default-insert-wrapper-20260626`  
Target: [UID:0002IB] `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`  
Report mode: report-only research/rework; no target/support documentation edited.

## Current Recommendation

[UID:0002IB] should no longer keep blank formal C++.

The best source-facing reconstruction is a retained `HierList` wrapper method that inserts a payload as the first row under the optional parent/root scope by forwarding a null sibling/reference payload to the three-argument insert-before core:

```cpp
void HierList::InsertFirst(const void *parentPayload, const void *payload)
{
    InsertBefore(parentPayload, NULL, payload);
}
```

Recommended score after implementation: `COMPLETION:88`, `CONFIDENCE:91`.

The binary behavior is exact and current. The remaining uncertainty is only original source spelling: no PDB/string/export names identify this raw start, and IDA has no function object for it. `InsertFirst` is still strong enough for first-draft C++ because it matches the behavior, the surrounding `List`/`HierList` method naming style, and the already documented `InsertBefore` relationship without exposing a raw helper label as source.

## Report-Only Constraints Followed

- Read current B015 `goal.md` and used the project-level `ntk-b-agent-workflow` skill.
- Used live IDA MCP against session `80de0a67`.
- Did not edit target/support `by-*` documentation, generated/project-level files, coverage reports, validator state/cache, or IDA DB.
- Did not spawn subagents.
- Created/updated only this research report under Agent-B015's `research/` folder.

## Target State Rechecked

Current target documentation records:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000065`
- blank formal C++

The current blocker is source quality, not behavior. The wrapper body, callee, padding, and no-direct-xref state are already substantially documented, but the source-facing form/name and final C++ block were left unresolved.

## Live IDA MCP Evidence

MCP status:

- `idb_list`: active session `80de0a67`, `NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.

Raw target bytes and padding:

- `get_bytes` over `0x004ce830` shows preceding wrapper tail, `0xCC` padding, the full `0002IB` 20-byte body, more `0xCC` padding, then the `0x004ce860` prologue.
- The exact target body is:

```asm
55 8B EC FF 75 0C 6A 00 FF 75 08 E8 10 00 00 00 5D C2 08 00
```

Instruction query over `0x004ce840-0x004ce860`:

```asm
0x004ce840  push ebp
0x004ce841  mov ebp, esp
0x004ce843  push dword ptr [ebp+0Ch]
0x004ce846  push 0
0x004ce848  push dword ptr [ebp+8]
0x004ce84b  call sub_4CE860
0x004ce850  pop ebp
0x004ce851  retn 8
0x004ce854  align 10h
```

IDA function modeling:

- `lookup_funcs` finds no function object at `0x004ce840` or `0x004ce854`.
- `decompile 0x004ce840` fails because IDA does not model the raw start as a function.
- `insn_query` still decodes the complete body with `fn:null`, confirming a real executable island rather than generated markdown drift.

Xrefs:

- `xrefs_to 0x004ce840`: none.
- `xrefs_to 0x004ce860`: four code xrefs:
  - `0x004ce802` from sibling raw wrapper [UID:0002IA].
  - `0x004ce82e` from sibling raw wrapper [UID:0002IA].
  - `0x004ce84b` from this wrapper [UID:0002IB].
  - `0x004f0a3b` from `sub_4F0840`, current Layer-side AddChildBefore/insert-before path.

Uniqueness:

- `make_signature_for_range 0x004ce840-0x004ce854`: `55 8B EC FF 75 ? 6A 00 FF 75 ? E8 ? ? ? ? 5D C2 08 00`, `unique:true`.
- `find_bytes` for the exact 20-byte body returns one match at `0x004ce840`.
- `find_bytes` for little-endian pointer bytes to `0x004ce840` (`40 E8 4C 00`) returns no matches, supporting the no-direct-reference state.

## Insert-Before Core Semantics

`analyze_function 0x004ce860` currently models the callee as `sub_4CE860`, size `0x14d` / 333 bytes, with this effective argument order:

- `this`: target `HierList`.
- first explicit argument: parent payload pointer, optional.
- second explicit argument: sibling/reference payload pointer, optional.
- third explicit argument: source payload copied into the new row.

Important decompiled semantics:

- Allocates a new row with `sub_516050(this[1])`.
- Clears the new row child-list slot with `v5[1] = 0`.
- Copies `this[1] - 11` bytes from the source payload to `newRow + 8`.
- If parent payload is supplied, resolves the parent row with `sub_4CEC30`, lazily creates the parent's child `HierList` if needed, and inserts into that child list.
- If no parent payload is supplied, inserts into the root `HierList`.
- If sibling/reference payload is supplied, resolves it with `sub_4CEC30` and uses the found index.
- If sibling/reference payload is null, sets the index to `-1`.
- Performs virtual `InsertAt(index + 1, 1, newRow)`.

For this target, the wrapper always pushes `0` as the sibling/reference argument. Therefore the core always uses `-1 + 1`, which inserts at index `0` in the selected parent/root list.

## Source-Form Decision

The target should be documented as a source-authored wrapper method, not as padding, a compiler thunk, a macro artifact, or a private raw helper:

- The body has a normal frame, a three-argument call to the core, and `retn 8`, which is exactly a two-explicit-argument `__thiscall` member wrapper shape.
- The callee relation is not a tail-call optimization; the wrapper retains its own prologue/epilogue and stack cleanup.
- The wrapper has no incoming references in this build, but it is bracketed by executable sibling wrappers and alignment padding. This is consistent with retained class API code that is not used by the captured call graph.
- The wrapper is not equivalent to `InsertBefore` itself. It hides the sibling/reference parameter and fixes it to null.
- The wrapper is not `InsertAfter`; `0x004ce9b0` handles that separate core behavior and defaults a null sibling/reference to append (`count - 1`), not first position.

Best source-facing form:

```cpp
void HierList::InsertFirst(const void *parentPayload, const void *payload);
```

Rationale:

- `InsertFirst` states the actual effect produced by the null sibling/reference: insert at index `0`.
- It pairs naturally with the sibling tail/default wrapper [UID:0002IA], whose behavior computes the current tail sibling and forwards to the same core.
- It follows the simple local API style seen in `List`/`HierList` docs: `InsertAt`, `InsertBefore`, `InsertAfter`, `Append`, `GetElementAt`.
- It avoids overloading `InsertBefore` with a misleading two-argument form. A two-argument `InsertBefore(parentPayload, payload)` would hide the absent reference payload and be ambiguous to a reader.
- It avoids the raw documentation-only name `HierListDefaultInsertWrapper`.

Rejected source-facing alternatives:

- `DefaultInsertWrapper`: accurate as a by-memory label but not a source-facing C++ method name.
- `InsertBefore(const void *parentPayload, const void *payload)`: plausible mechanically, but misleading because no "before what" reference is exposed.
- `InsertAtHead`: accurate but less consistent with the concise local naming style than `InsertFirst`.
- `Append`, `InsertLast`, or tail-oriented names: contradicted by `v11 = -1; InsertAt(v11 + 1, ...)`, which inserts at index `0`.
- A blank C++ block: no longer justified because the source-form/name blocker is resolved enough for first-draft formal C++.

## Relation To Sibling And Support Pages

[UID:0002IC] `HierListInsertBefore`:

- Remains the core three-argument implementation.
- This target should be recorded as the source wrapper that calls it as `InsertBefore(parentPayload, NULL, payload)`.
- This report does not change [UID:0002IC] formal C++ because the accepted target is [UID:0002IB], but its caller/context section should know that `0x004ce84b` is the `InsertFirst` wrapper call site.

[UID:0002IA] `HierListTailInsertWrapper`:

- Sibling wrapper computes a tail sibling/reference in parent/root scope, then calls `0x004ce860`.
- This report does not require changing its formal C++.
- The relationship supports the name `InsertFirst` for [UID:0002IB] because [UID:0002IB] is the complementary default-first wrapper that always passes a null sibling/reference.

[UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md` aggregate:

- Aggregate should remain non-emitting.
- Its function table/source-quality notes should identify [UID:0002IB] as first-draft emitted `HierList::InsertFirst(const void *parentPayload, const void *payload)`.

[UID:000065] `by-class/HierList.md` and [UID:0000JV] `by-file/HierList.md`:

- Method map/proposed contents should use `InsertFirst` for `0x004ce840-0x004ce854`.
- The broader class/file pages should keep their class-level C++ blank unless a coordinated class pass fills declarations, but they should no longer describe [UID:0002IB] as source-name unresolved.

## Formal C++ To Insert

Use this exact target block for [UID:0002IB]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void HierList::InsertFirst(const void *parentPayload, const void *payload)
{
    InsertBefore(parentPayload, NULL, payload);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No extra helper function is required.

## Metadata Recommendation

For [UID:0002IB]:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:000065`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000065`
- Keep `EMITTER_POSITION` blank unless the validator requires an ordering value from local convention.

Why `88/91`:

- Positive: exact 20-byte body, exact stack cleanup, exact null sibling/reference push, unique signature, live MCP proof, current core semantics, valid source-facing wrapper shape, and a concrete C++ block.
- Limiting factors: no original symbol/name proof, no direct xrefs to the raw start, IDA does not model the wrapper as a function, and the sibling wrapper's final source name is outside this target's required edit set.

## Required Target-Doc Edits For Implementation Callback

Update [UID:0002IB] `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`:

- Raise metadata to `COMPLETION:88`, `CONFIDENCE:91`.
- Insert the exact formal C++ block above.
- Update Item Summary to name source-facing `HierList::InsertFirst`.
- Add/refine current-session evidence:
  - IDA MCP session `80de0a67`, server health ok, analysis idle, Hex-Rays ready.
  - no modeled function at `0x004ce840`.
  - no xrefs to raw start.
  - xrefs to `0x004ce860` include `0x004ce84b`.
  - exact 20-byte body and unique signature.
- Add a source-form decision section or equivalent prose:
  - wrapper method, not compiler-generated name, not raw-only helper.
  - parameter names `parentPayload` and `payload`.
  - return type `void`.
  - source call `InsertBefore(parentPayload, NULL, payload)`.
- Add a score rationale explaining why the page moves to `88/91`, and why it is not higher.

## Required Support-Doc Edits For Implementation Callback

Update [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`:

- In the function table/source-quality notes, change [UID:0002IB] from unresolved/default raw wrapper wording to first-draft emitted `HierList::InsertFirst(const void *parentPayload, const void *payload)`.
- Keep aggregate non-emitting and avoid adding aggregate C++.

Update [UID:000065] `by-class/HierList.md`:

- In the method map, identify `0x004ce840-0x004ce854` as `InsertFirst(const void *parentPayload, const void *payload)`.
- Note that [UID:0002IB] now has exact-child first-draft C++ while class-level C++ remains governed by class coordination.

Update [UID:0000JV] `by-file/HierList.md`:

- In proposed contents/migration notes, list [UID:0002IB] as emitted `HierList::InsertFirst`.
- Remove any implication that this exact child still has blank C++ due to unresolved source form.

Update [UID:0002IC] `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`:

- In caller/context evidence, identify `0x004ce84b` as the `InsertFirst` wrapper call site that passes a null sibling/reference.
- Do not fill [UID:0002IC] formal C++ from this report unless the supervisor explicitly expands the callback.

Optional, only if needed for consistency after the above edits:

- [UID:0002IA] `by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md`: add a small relationship note that [UID:0002IB] is the complementary first/default wrapper. Do not change [UID:0002IA] formal C++ from this report.

No edit recommended:

- `by-type/by-struct/HierListNode.md`: existing `parent`, `childList`, and `payload` field names already support this target.
- `by-class/List.md` / `by-file/List.md`: existing `InsertAt`/`Append` API evidence is sufficient.
- Layer docs: current Layer caller evidence supports `InsertBefore`; this target is the unused/retained wrapper and needs no Layer-page edit.

## Validator Plan For Implementation Callback

After leasing and editing only the immediate files, run scoped validators from `source-3/project-documentation`:

Validator target UID/path map:

- [UID:0002IB] `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md`
- [UID:00016X] `by-memory/0x004ce730-0x004cee52.HierList.md`
- [UID:000065] `by-class/HierList.md`
- [UID:0000JV] `by-file/HierList.md`
- [UID:0002IC] `by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md`
- Optional [UID:0002IA] `by-memory/0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md`

> Executable block R001 was removed from this report and preserved verbatim in [0002IB-HierListDefaultInsertWrapper-source-quality-removed.md](0002IB-HierListDefaultInsertWrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional sibling relationship note is edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0002IB-HierListDefaultInsertWrapper-source-quality-removed.md](0002IB-HierListDefaultInsertWrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validator completion, inspect generated outputs only, without manual edits:

- `auto-generated/NexusTK/util/HierList.cpp` should include the `InsertFirst` emitter for [UID:0002IB].
- `auto-generated/-ag-research-tracker.md` should show [UID:0002IB] at `88/91`.
- `auto-generated/-ag-coverage-report-by-memory.md` should reflect the updated target score.

No validators were run during this report-only pass because no by-* documentation was edited.

## Report Readiness Proof

- [x] Current `goal.md` read.
- [x] Project-level workflow skill read and applied.
- [x] Target and required support pages checked.
- [x] Live IDA MCP used successfully.
- [x] Raw body, padding, no-start-xref state, callee xrefs, core semantics, uniqueness, and stale tracker/source-doc mismatch checked.
- [x] Source-form/name/C++ blocker resolved in this report.
- [x] Exact formal C++ insertion text supplied.
- [x] Required implementation callback edits and validator plan supplied.
- [x] Supervisor rejection rework corrected support UID/path labels for aggregate [UID:00016X], class [UID:000065], and file [UID:0000JV].

## Implementation Tracking Checklist

- [x] Supervisor accepts this report for implementation.
  - Proof: `goal.md` assignment `B015-implement-0002IB-hier-list-default-insert-wrapper-20260626` states the reworked report was accepted for implementation and lists the exact accepted disposition.
- [x] Lease [UID:0002IB] target doc only while editing.
  - Proof: B015 leased `by-memory/0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md` before the edit batch. The initial B015 lease window covered the target edit; the lease expired before validation, then the same scoped file set was reacquired for validators.
- [x] Update [UID:0002IB] metadata to `88/91`.
  - Proof: target header now has `COMPLETION:88` and `CONFIDENCE:91`; validator `000000002178` recorded `completion_update 0002IB ... 88` and `confidence_update 0002IB ... 91`.
- [x] Insert exact `HierList::InsertFirst(const void *parentPayload, const void *payload)` formal C++ block.
  - Proof: target formal `RECONSTRUCTION_CPP CODE` now contains:

```cpp
void HierList::InsertFirst(const void *parentPayload, const void *payload)
{
    InsertBefore(parentPayload, NULL, payload);
}
```

  - Validator `000000002178` recorded the autogen registry transition for [UID:0002IB] from `blank` to `block`.
- [x] Update [UID:0002IB] Item Summary/current-session evidence/source-form and no-higher-score rationale.
  - Proof: target `Item Summary` now names `HierList::InsertFirst`; target `Evidence` records session `80de0a67`, server health, no modeled function, no start xrefs, `0x004ce84b -> 0x004ce860`, exact 20-byte body, unique signature/body match, and pointer-byte negative search; target `Source Form Decision` and `Score Rationale` record the accepted wrapper form, rejected alternatives, and `88/91` no-higher rationale.
- [x] Release [UID:0002IB] lease after validation batch.
  - Proof: B015 released the target and support leases after all scoped validators; `tools/leaser/Agents/current_leases.md` reported no active leases afterward.
- [x] Lease and update [UID:00016X] aggregate `by-memory/0x004ce730-0x004cee52.HierList.md`; keep aggregate non-emitting.
  - Proof: aggregate function table/source-quality/autogen notes now identify [UID:0002IB] as accepted formal `HierList::InsertFirst`; metadata remains `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS` and blank aggregate C++.
- [x] Lease and update [UID:000065] `by-class/HierList.md` method map/support notes.
  - Proof: class method map now identifies `0x004ce840-0x004ce854` as accepted `HierList::InsertFirst(const void *parentPayload, const void *payload)` with formal exact-child C++; class autogen note keeps class-level C++ blank while listing exact child outputs `InsertLast`, `InsertFirst`, and `FindNodeByPayload`.
- [x] Lease and update [UID:0000JV] `by-file/HierList.md` proposed contents/migration notes.
  - Proof: file proposed contents and migration notes now list `0x004ce840` as accepted formal `HierList::InsertFirst` exact-child C++; no generated/project-level files were manually edited.
- [x] Lease and update [UID:0002IC] caller/context support note for `0x004ce84b` as `InsertFirst`.
  - Proof: [UID:0002IC] evidence and changes now identify `0x004ce84b` as the accepted source-level `InsertFirst` delegate call passing a null sibling/reference; formal C++ remains blank on [UID:0002IC].
- [x] Optionally lease/update [UID:0002IA] only if consistency requires a small sibling relationship note; do not change its formal C++ from this report.
  - Proof: optional sibling note was updated because it otherwise still said [UID:0002IB] had no formal C++; the relationship table now identifies [UID:0002IB] as accepted `InsertFirst`. [UID:0002IA] formal `InsertLast` C++ was not changed.
- [x] Before editing shared HierList support docs, recheck B003 [UID:0002IA] implementation overlap; if B003 already added the shared insertion-family text, mark overlapping support text already present or coordinate with the current B003 implementation instead of duplicating contradictory text.
  - Proof: `tools/leaser/Agents/current_leases.md` was read before editing and showed no active B003/HierList leases; current target/support files were reread under B015 lease. Existing B003 insertion-family text was promoted/superseded in place rather than duplicated.
- [x] Run scoped validators listed in this report from `source-3/project-documentation`.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory\0x004ce840-0x004ce854.HierListDefaultInsertWrapper.md --apply --queue-timeout 240` -> command_id `000000002178`, timestamp `2026-06-26T03:05:10-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004ce730-0x004cee52.HierList.md --apply --queue-timeout 240` -> command_id `000000002179`, timestamp `2026-06-26T03:05:17-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-class\HierList.md --apply --queue-timeout 240` -> command_id `000000002180`, timestamp `2026-06-26T03:05:27-04:00`, exit `0`, `ok: 1`, generated refresh deferred; validator inserted missing [UID:0002IB] link annotations.
    - `python .\tools\validator.py --mode file --file by-file\HierList.md --apply --queue-timeout 240` -> command_id `000000002181`, timestamp `2026-06-26T03:05:38-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004ce860-0x004ce9ad.HierListInsertBefore.md --apply --queue-timeout 240` -> command_id `000000002182`, timestamp `2026-06-26T03:05:45-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
    - `python .\tools\validator.py --mode file --file by-memory\0x004ce7e0-0x004ce839.HierListTailInsertWrapper.md --apply --queue-timeout 240` -> command_id `000000002184`, timestamp `2026-06-26T03:05:51-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- [x] Inspect generated outputs listed in this report without manual edits.
  - Proof: `python .\tools\validator.py --queue-status` returned command_id `000000002185`, timestamp `2026-06-26T03:06:27-04:00`, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
  - Proof: `auto-generated/NexusTK/util/HierList.cpp` header is `validator-command-id: 000000002184`, `validator-refreshed-at: 2026-06-26T03:05:51-04:00`, and contains `void HierList::InsertFirst(const void *parentPayload, const void *payload)`.
  - Proof: `auto-generated/-ag-coverage-report-by-memory.md` header is `validator-command-id: 000000002184`, and its [UID:0002IB] row shows `emits_code:true`, `88%`, `very-strong`, and the updated `InsertFirst` item summary.
  - Proof: `auto-generated/-ag-research-tracker.md` header is `validator-command-id: 000000002184`, and its [UID:0002IB] row shows `88/91`.
- [x] Update this report checklist with proof lines during implementation callback.
  - Proof: this checked checklist records target/support changes, validator command ids/timestamps/exit states, generated-output inspection, and lease release state.
- [x] Release all leases immediately after the validator batch and generated-output inspection.
  - Proof: edit leases were released immediately after the validator batch and before read-only generated inspection; final lease report showed no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002IB-HierListDefaultInsertWrapper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0002IB-HierListDefaultInsertWrapper-source-quality.md","timestamp":"2026-06-26T03:09:29","uid":"0002IB"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IB-HierListDefaultInsertWrapper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0002IB-HierListDefaultInsertWrapper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
