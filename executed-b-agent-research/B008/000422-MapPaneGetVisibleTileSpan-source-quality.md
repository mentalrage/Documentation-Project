** TARGET-REPORT-UID:000422 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 000422 MapPaneGetVisibleTileSpan Source-Quality Research

Agent: Agent-B008
Assignment target: [UID:000422] `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md`
Mode: implementation-callback artifact after supervisor Gate 1 acceptance. The initial pass was report-only; during the callback B008 edited only the accepted target/support by-* docs, ran scoped validators, and did not run `execute_report`, lifecycle/archive commands, registry commands, manual generated edits, coverage edits, or supervisor-ledger edits.
IDA MCP endpoint: `http://127.0.0.1:13337/mcp`
MCP session used for accepted evidence: `60724697`

## Finalized Report / Current Recommendation

Keep the assigned target path as a `MapPane` method owned by [UID:00007Q][MapPane](by-class/MapPane.md), emitted through the same class route and [UID:0000L3][MapPane](by-file/MapPane.md) source module. The callback applied the accepted score change from assignment-time `86/88` to current `88/91`, preserving `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`.

The existing first-draft C++ shape is source-ready and should remain in the target's formal `RECONSTRUCTION_CPP CODE` block. The important correction is evidentiary and wording-level: document the live-session store order precisely. Binary order is `MapPane +0x404` into output offset `+4` and `MapPane +0x408` into output offset `+0`. This matches the current source convention only if `+0x404` is `m_visibleTileColumns`, `+0x408` is `m_visibleTileRows`, and `MapPoint::row` is the first field while `MapPoint::column` is the second.

Also record the UID collision/stale support issue: a separate RankingDialog helper page `by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md` currently also carries `UID:000422`, and RankingDialog support docs refer to `[UID:000422]` while linking to the MapPane target path and describing RankingDialog previous-page behavior. That is not evidence against MapPane ownership. It is a support/lifecycle collision to be repaired only under supervisor-authorized collision scope, not by this MapPane implementation callback.

## Supporting Research

B008 performed this pass after supervisor restored MCP and named live session `60724697`. MCP was reachable during the final evidence pass. `idb_list` returned one active session with `session_id:60724697`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `13932`, and `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Read-only local sources checked:

- Assigned target: `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md`.
- Parent aggregate: `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`.
- MapPane support docs: `by-class/MapPane.md`, `by-file/MapPane.md`.
- Neighbor visible-bounds children: `by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md`, `by-memory/0x00505310-0x0050534d.MapPaneGetVisibleTileBounds.md`, and `by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md`.
- UserPane caller/support: `by-memory/0x005a2530-0x005b8395.UserPane.md` and `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`.
- Generated read-only output: `auto-generated/NexusTK/map/MapPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.
- Prior report: `executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`.
- Collision/stale support check: `by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md`, `by-class/RankingDialog.md`, `by-file/RankingDialog.md`, and `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`.

Historical report-only note: no validators were run during the initial evidence pass because no by-* file was changed then. Current callback state: supervisor Gate 1 accepted this report, B008 applied the accepted target/support by-* updates after taking the required leases, scoped validators `000000006215` through `000000006218` ran, and validator-owned generation refreshed `auto-generated/NexusTK/map/MapPane.cpp` with UID000422 at `88/91`. Lease-release state is recorded below because B008's short lease window expired before the explicit release command, and B006 acquired the MapPane support docs afterward.

## Target

Target UID and path: [UID:000422] `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md`.

Assignment-time target metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007Q`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ already populated as `MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const`.

Post-callback target metadata is now `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, with blank `EMITTER_POSITION_OPTIONAL`. The target emits through `auto-generated/NexusTK/map/MapPane.cpp` at the `MapPane.cpp` route. Validator command `000000006218` refreshed generated output with UID000422's non-empty `MapPane::GetVisibleTileSpan` body at `Completion:88 | Confidence:91`.

## Current Target State

The current target is not an empty emitter. It has source-shaped formal C++ and the correct MapPane class/file route. Before the callback, its main gap was reliance on the accepted 0001AP split note rather than current, function-specific MCP proof; after the callback, the target Evidence and Score Rationale sections carry the session `60724697` range/bytes/caller/padding/type-negative proof.

Current formal C++ in the target and generated output:

```cpp
MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const
{
    outSpan->row = m_visibleTileRows;
    outSpan->column = m_visibleTileColumns;
    return outSpan;
}
```

The target summary says it writes visible tile rows and columns to an output point/span record. That is correct at source level, and the callback added exact offset proof: the binary reads `+0x404` first and stores it at `outSpan +4`, then reads `+0x408` and stores it at `outSpan +0`. Neighboring visible-bounds helpers and the MapPane class field glossary identify `+0x404` as columns and `+0x408` as rows, so the source block remains valid as written.

## Heuristic / Inference Reanalysis And Validation

Owner and source route are strong. The function is a `__thiscall` receiver method that reads only `ecx+0x404` and `ecx+0x408`, the same visible-span fields used by neighboring MapPane visible-bounds helpers. Its only direct caller function is `UserPane::UserPane()` / `sub_5A2530`, where the receiver comes from `UserPane +0x1340f8`; the `UserPaneGetMapPane` page and constructor evidence resolve that field as `MapPane *m_mapPane`. UserPane is a consumer of the helper, not the owner.

The formal C++ should not be blank. The body has one block, nine instructions, no callees, no strings, no table dispatch, no exception handling, and a direct return of the output pointer. The source shape is a plain getter/filler.

The field-order inference was rechecked because the assembly loads columns before rows. The relevant source-level mapping is:

- `MapPane +0x404` -> `m_visibleTileColumns`.
- `MapPane +0x408` -> `m_visibleTileRows`.
- Output offset `+0` -> current `MapPoint::row` convention.
- Output offset `+4` -> current `MapPoint::column` convention.

With that mapping, current C++ is behavior-preserving. The target should document this explicitly so future reviewers do not swap the assignments based only on load order.

Score should remain below final-audit level because IDA has no local `MapPoint` or `MapPane` UDT declaration, original member spelling is inferred from project conventions, and an unrelated RankingDialog UID collision still needs supervisor-scoped support cleanup. Those blockers do not prevent `88/91` source-ready status for this exact method.

## Evidence Standards Used

This pass used narrow MCP calls only: `idb_list`, `server_health`, bounded `lookup_funcs`, bounded `get_bytes`, single-function `disasm`, single-function `decompile`, single-function `func_profile`, bounded `xrefs_to`, bounded `insn_query` windows around the two callsites, and filtered `type_query` for `MapPoint` / `MapPane`.

Local documentation was used only as support context and to detect stale/colliding by-* references. Generated files were read but not edited. The current IDA database was not modified: no rename, type, comment, function-creation, process-management, lifecycle, archive, or report-execution command was run.

## Evidence Checked

MCP request summary from session `60724697`:

- `idb_list`: one active NexusTK session, `60724697`, worker PID `13932`, `is_analyzing:false`.
- `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready.
- `lookup_funcs` for `0x0050534c`, `0x00505350`, `0x0050536b`, `0x00505370`: predecessor `sub_505310` at `0x505310` size `0x3d`, target `sub_505350` at `0x505350` size `0x1b`, `0x0050536b` not a function, successor `sub_505370` at `0x505370` size `0x74`.
- `get_bytes` at `0x0050534d` size `0x23`: three `0xcc` bytes before the target, target bytes `55 8b ec 8b 45 08 8b 91 04 04 00 00 8b 89 08 04 00 00 89 50 04 89 08 5d c2 04 00`, then five `0xcc` bytes through `0x0050536f`.
- `disasm 0x00505350`: `push ebp; mov ebp, esp; mov eax,[ebp+arg_0]; mov edx,[ecx+404h]; mov ecx,[ecx+408h]; mov [eax+4],edx; mov [eax],ecx; pop ebp; retn 4`.
- `decompile 0x00505350`: `_DWORD *__thiscall sub_505350(_DWORD *this, _DWORD *a2)`; assigns `result=a2`, `v3=this[257]`, `v4=this[258]`, `a2[1]=v3`, `*a2=v4`, returns `result`.
- `func_profile 0x00505350`: size `0x1b`, 9 instructions, 1 basic block, caller_count `1`, callee_count `0`, string_ref_count `0`, prototype `_DWORD *__thiscall(_DWORD *this, _DWORD *)`, caller function `sub_5A2530`.
- `xrefs_to 0x00505350`: two code xrefs at `0x005a27fc` and `0x005a2afd`, both inside `sub_5A2530`.
- `xrefs_to 0x0050536b`: no xrefs to the end/padding address.
- `xrefs_to 0x00505370`: six xrefs to the separate successor function, supporting the successor split.
- `insn_query` around `0x005a27e0-0x005a2838` and `0x005a2ae0-0x005a2b38`: both windows load `ecx` from `[ebx+1340F8h]`, test it for null, pass a stack two-dword output record, call `sub_505350`, halve the two returned components, and store half/remainder pairs at `UserPane +0x13eae0/+0x13eae4/+0x13eae8/+0x13eaec`.
- `type_query` for `*MapPoint*` and `*MapPane*`: no local IDA type data, so type/member names remain documentation-level inference.

Local support evidence:

- `by-class/MapPane.md` field glossary already maps `+0x404/+0x408` to `m_visibleTileColumns/m_visibleTileRows`, with a caveat that final constructor-parameter order still needs broader source audit.
- Neighbor visible-bounds children use `m_visibleTileRows` for bottom/height math and `m_visibleTileColumns` for right/width math.
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md` already records the same two constructor callsites after loading `UserPane +0x1340f8` from `g_activeMapPane`, which independently supports the receiver type.
- Generated `auto-generated/NexusTK/map/MapPane.cpp` emits UID000422 as a non-empty MapPane method at `Completion:88 | Confidence:91` after validator command `000000006218`.

## IDA MCP Facts

| Fact | Current evidence |
| --- | --- |
| Session | `60724697`, server health OK, Hex-Rays ready. |
| Target function | `sub_505350`, address `0x00505350`, size `0x1b`, end `0x0050536b`. |
| Prototype shape | `_DWORD *__thiscall(_DWORD *this, _DWORD *)`; returns output pointer. |
| Exact bytes | `55 8b ec 8b 45 08 8b 91 04 04 00 00 8b 89 08 04 00 00 89 50 04 89 08 5d c2 04 00`. |
| Reads | `this +0x404` and `this +0x408`. |
| Writes | output `+4` gets `this+0x404`; output `+0` gets `this+0x408`. |
| Callees | none. |
| Callers | one caller function, two callsites: `0x005a27fc`, `0x005a2afd`, both in `sub_5A2530`. |
| Padding/split | `0x0050534d-0x00505350` and `0x0050536b-0x00505370` are `0xcc` alignment; successor is `sub_505370`, not part of target. |
| Local types | no `MapPoint` or `MapPane` UDT recovered by `type_query`. |

## Function / Child Inventory

| Range | UID | Current role | Recommended disposition |
| --- | --- | --- | --- |
| `0x00505310-0x0050534d` | `000421` | `MapPane::GetVisibleTileBounds` predecessor. | Separate predecessor, already source-emitting; do not merge. |
| `0x0050534d-0x00505350` | ignored padding | three `0xcc` bytes. | Alignment only. |
| `0x00505350-0x0050536b` | `000422` assigned target | `MapPane::GetVisibleTileSpan`. | Keep as exact source-emitting child; raise to `88/91`; add current MCP proof. |
| `0x0050536b-0x00505370` | ignored padding | five `0xcc` bytes. | Alignment only. |
| `0x00505370-0x005053e4` | `000423` | `MapPane::GetExtendedVisibleTileBounds` successor. | Separate successor, already source-emitting; do not merge. |

## Direct Xref / Caller Inventory

`xrefs_to 0x00505350` reports exactly two code xrefs:

| Callsite | Caller function | Receiver/context |
| --- | --- | --- |
| `0x005a27fc` | `sub_5A2530` / `UserPane::UserPane()` aggregate constructor path | `ecx` loaded from `UserPane +0x1340f8`, resolved locally as cached `MapPane *m_mapPane`. |
| `0x005a2afd` | `sub_5A2530` / duplicate constructor branch | Same receiver path and same output-half/remainder setup. |

Both callsites are UserPane consumer evidence. They do not move ownership to UserPane because the called method reads only MapPane receiver fields and is also listed in the MapPane coordinate family. The constructor stores the active map pane pointer into the UserPane member before calling this helper.

## Range / Split / Padding / Reclassification Analysis

The target range is exact. `lookup_funcs` says `0x00505350` is the target function and `0x0050536b` is not a function. `get_bytes` shows pure `0xcc` alignment before and after the target. `xrefs_to 0x0050536b` returns no xrefs, while `xrefs_to 0x00505370` returns references to the next function. There is no basis to extend the target into predecessor or successor code, and no basis to reclassify it as padding, data, a thunk, or raw no-route bytes.

## Ranked Ownership Analysis

1. [UID:00007Q][MapPane](by-class/MapPane.md) and [UID:0000L3][MapPane](by-file/MapPane.md) are the correct owner and source route. Evidence: `__thiscall` receiver reads MapPane visible-span fields; neighboring visible-bounds children use the same field family; parent aggregate `0001AP` lists UID000422 as a MapPane child; generated MapPane output currently emits it.
2. [UID:0000P1][UserPane](by-file/UserPane.md) is a caller/consumer only. Evidence: both direct callsites occur in `UserPane::UserPane()`, but the receiver is a cached `MapPane *m_mapPane`, not a UserPane field pair.
3. RankingDialog ownership is rejected for this target path. The RankingDialog docs and `0x00459600` helper show a duplicate/stale UID collision, not a real code or source-owner relationship to `0x00505350`.
4. Parent aggregate ownership only is rejected. UID0001AP is an index/aggregate; exact child UID000422 is the right granularity for source C++.
5. No-owner/non-emitting is rejected. The function is modeled, reached, source-shaped, and already has a valid owner/emitter route.

## Source Placement

Place and emit this as `MapPane::GetVisibleTileSpan` through the MapPane class/file route. The best current source module remains `NexusTK/map/MapPane.cpp`. The method belongs next to the visible tile bounds helpers rather than in UserPane or RankingDialog files.

The original exact source spelling of `MapPoint`, `m_visibleTileRows`, and `m_visibleTileColumns` is not recovered from IDA types. Current project convention is strong enough for first-draft source because the neighboring methods and field glossary already use those names consistently.

## Positive Evidence Summary

- Current MCP session `60724697` verifies exact function range, bytes, instruction count, prototype shape, no callees, caller count, and two xrefs.
- The body is a plain MapPane visible-span getter/filler: read two MapPane fields, write two output dwords, return the output pointer.
- The output order matches current source C++ when the documented field mapping is applied: rows at MapPane `+0x408` to output `+0`, columns at MapPane `+0x404` to output `+4`.
- Neighbor visible-bounds helpers use `m_visibleTileRows` for bottom/height and `m_visibleTileColumns` for right/width, supporting the field mapping.
- `UserPaneGetMapPane.md` already independently resolves the caller receiver as `MapPane *m_mapPane`.
- Generated MapPane output is not empty for UID000422; validator command `000000006218` refreshed it with the current `88/91` `MapPane::GetVisibleTileSpan` body.

## Negative Evidence Summary

- Not UserPane-owned: UserPane only loads a cached MapPane pointer and calls this MapPane helper.
- Not RankingDialog-owned: the Ranking docs have a duplicate/stale UID collision around a separate `0x00459600` helper, not a real cross-reference to `0x00505350`.
- Not padding: target bytes are a modeled 9-instruction function and are bracketed by `0xcc` alignment.
- Not a range extension: predecessor and successor are separate modeled functions; no xrefs target `0x0050536b`.
- Not a raw no-route helper: direct callsites exist at `0x005a27fc` and `0x005a2afd`.
- Not a table/vtable thunk or compiler artifact: no vtable data, no wrapper pattern, no EH, and no callees.
- Not a blank/no-code case: the behavior is simple enough and already source-shaped enough for formal C++.

## First-Draft C++ Recommendation

Use this exact formal block in the target. It is intentionally the same source shape as the current target block, with stronger evidence attached in the prose sections:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const
{
    outSpan->row = m_visibleTileRows;
    outSpan->column = m_visibleTileColumns;
    return outSpan;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation note: do not swap the visible-row and visible-column source assignments. The binary's load order is columns then rows, but the store order is output `+4` then output `+0`. With the current project convention, the formal C++ above is the correct source-level representation.

## Final Recommendation

Apply this report as a source-quality reinforcement for the assigned MapPane target, not as a source-owner move. Update target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep owner/emitter `00007Q`, preserve the blank optional emitter position, and retain/reinsert the formal `MapPane::GetVisibleTileSpan` C++ block above.

Recommended target doc disposition: source-ready exact child. Add current MCP session `60724697` range, bytes, disassembly, decompilation, callsite, caller-consumer, padding, and type-negative evidence. Clarify that `+0x404` is the column span stored to output `+4`, while `+0x408` is the row span stored to output `+0`.

Recommended parent/support disposition: keep MapPane class/file and UID0001AP aggregate route. Add concise current evidence where stale or missing. Treat UserPane as caller evidence only.

No-owner/non-emitting disposition: rejected for the MapPane target because direct callsites and formal source shape are proven. RankingDialog duplicate UID state is a separate support/lifecycle repair issue; it should be recorded or repaired only under explicit supervisor authorization and should not be used to demote or move the MapPane target.

Future work outside this report: broader constructor-parameter naming and a full `MapPoint`/MapRect layout declaration pass can raise confidence above `91`. Duplicate UID repair for the RankingDialog previous-page helper likely needs supervisor/validator-owned lifecycle handling or a dedicated callback; B008 did not edit it during this MapPane callback.

## Recommended Target Doc Changes

For `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00007Q`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00007Q`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep the formal `RECONSTRUCTION_CPP CODE` block populated with `MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const`.
- Add current MCP session `60724697` proof: exact range `0x00505350-0x0050536b`, size `0x1b`, exact bytes, `__thiscall` prototype shape, no callees, two callsites in `sub_5A2530`, padding before/after, successor split, no local `MapPoint`/`MapPane` IDA types.
- Replace under-specified "accepted 0001AP report records" wording with direct current evidence while preserving the useful 0001AP context.
- Clarify exact offset mapping: `+0x404` is the visible column count stored into output offset `+4`; `+0x408` is the visible row count stored into output offset `+0`.

## Recommended Support Doc Changes

- `by-class/MapPane.md`: add a UID000422 support note under coordinate/visible-bounds helpers or field glossary stating that current MCP session `60724697` rechecked the small getter, confirmed `+0x404` column and `+0x408` row output order, and supports the existing `MapPane::GetVisibleTileSpan` formal C++ route. If editing the field glossary, narrow the old "order should be rechecked" caveat by saying UID000422 verifies getter use while constructor-parameter original spelling remains broader follow-up.
- `by-file/MapPane.md`: add or confirm a source-route note that UID000422 emits through `NexusTK/map/MapPane.cpp` as a source-ready visible-span helper; no ownership move is required.
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: refine the UID000422 covered-range row from one-line inherited evidence to include current range/bytes/xrefs and `88/91` target-ready status if callback is accepted.
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`: already contains same-or-greater caller/receiver proof for the two constructor callsites; likely already-present unless the supervisor wants current session wording appended.
- RankingDialog duplicate/stale UID support docs: `by-class/RankingDialog.md`, `by-file/RankingDialog.md`, `by-memory/0x00458610-0x0045f9f5.RankingDialog.md`, and `by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md` contain a UID000422 collision or links that point UID000422 at the MapPane target while describing RankingDialog previous-page behavior. Do not repair that by hand in a normal UID000422 MapPane callback unless the supervisor explicitly authorizes the UID collision/support repair. Mark it as blocked/deferred if out of callback scope.

## Score And Metadata Recommendation

Recommended target score after implementation: `COMPLETION:88`, `CONFIDENCE:91`.

Rationale:

- Completion increases because this pass adds current, function-specific MCP evidence for range, bytes, callsites, padding, field/output order, and generated output state.
- Confidence increases because owner/emitter route, source body, and direct callsites are proven with live evidence.
- The score remains below `95` because local IDA has no `MapPoint`/`MapPane` UDT, final original field/member spelling is inferred, and unrelated duplicate UID support needs controlled cleanup.

Metadata should remain:

- `CANONICAL_OWNER:00007Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00007Q`
- blank `EMITTER_POSITION_OPTIONAL:`

## Open Questions With Attempted Resolution

| Question | Evidence checked | Attempted resolution | Score/C++ impact | Remaining evidence needed |
| --- | --- | --- | --- | --- |
| Is the current row/column C++ assignment reversed? | MCP disasm/decompile, neighbor visible-bounds C++ pages, MapPane field glossary. | Resolved for this target: binary stores `+0x408` to output `+0` and `+0x404` to output `+4`; with current conventions, existing C++ is correct. | No C++ blocker; supports first-draft formal block. | A future class-layout pass could prove original member spelling and field declarations. |
| Does UserPane ownership supersede MapPane because both xrefs are from `sub_5A2530`? | `xrefs_to`, `insn_query`, `UserPaneGetMapPane.md`, constructor support docs. | Resolved: UserPane loads `m_mapPane` and calls a MapPane receiver method. | No ownership blocker. | None for UID000422. |
| Does duplicate UID000422 in RankingDialog invalidate the MapPane target? | `rg` over by-* docs, RankingDialog helper page, RankingDialog class/file/aggregate support. | Resolved for source placement: no, it is a documentation/UID collision outside the MapPane code evidence. | Keeps confidence capped below final audit and creates support-repair follow-up. | Supervisor-authorized UID collision or validator lifecycle repair outside this MapPane callback. |
| Are local `MapPoint` and `MapPane` IDA types available? | `type_query` for `*MapPoint*` and `*MapPane*`. | Resolved negative: no local type catalog entries. | Exact source names remain inferred; cap confidence at `91`. | Future type-layout research. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000422-01 | UID000422 target range is exact `0x00505350-0x0050536b`, size `0x1b`. | High | MCP `lookup_funcs`, `get_bytes`, `disasm`. | `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md` Evidence; aggregate covered-range row. | incorporate | applied; target and aggregate updated, validator `000000006215` / `000000006218` ok |
| C-000422-02 | Target bytes are `55 8b ec 8b 45 08 8b 91 04 04 00 00 8b 89 08 04 00 00 89 50 04 89 08 5d c2 04 00`. | High | MCP `get_bytes`. | Target Evidence; class/file/aggregate support notes. | incorporate | applied; exact byte string recorded in target and support docs |
| C-000422-03 | Function is a `__thiscall` MapPane output-record getter with no callees and output-pointer return. | High | MCP `decompile`, `func_profile`. | Target Evidence and Score Rationale. | incorporate | applied; target records decompile/prototype/no-callee facts |
| C-000422-04 | `+0x404` maps to visible columns stored at output `+4`; `+0x408` maps to visible rows stored at output `+0`. | High | MCP `disasm` and neighboring MapPane visible-bounds docs. | Target Evidence; `by-class/MapPane.md` field glossary; `by-file/MapPane.md`; aggregate row. | incorporate | applied; mapping recorded in all edited docs |
| C-000422-05 | Existing formal C++ should be retained as source-ready. | High | MCP body, generated MapPane output, field mapping. | Target `RECONSTRUCTION_CPP CODE`; generated `auto-generated/NexusTK/map/MapPane.cpp`. | incorporate | applied; target block preserved and generated command `000000006218` emits UID000422 body at `88/91` |
| C-000422-06 | Direct callsites are `0x005a27fc` and `0x005a2afd`, both in `sub_5A2530`. | High | MCP `xrefs_to`, `insn_query`. | Target Evidence; MapPane class/file/aggregate support. | incorporate | applied; callsites recorded in target and support docs |
| C-000422-07 | UserPane is caller/consumer only; owner remains MapPane. | High | `UserPaneGetMapPane.md` constructor proof and MCP callsite receiver. | Target ownership rationale; MapPane class/file support; UserPane accessor support. | incorporate / already-present | applied for target/MapPane support; already-present in `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`, which was inspected but not edited |
| C-000422-08 | Predecessor/successor splits and padding are exact; no range extension. | High | MCP `lookup_funcs`, `get_bytes`, `xrefs_to 0x0050536b/0x00505370`. | Target Evidence and Range/Split/Padding reasoning; MapPane support. | incorporate | applied; target records predecessor/successor/padding and rejected range-extension |
| C-000422-09 | Target metadata should become `88/91` with owner/emitter preserved. | Medium-high | Current evidence plus score blockers. | Target header/Score Rationale. | incorporate | applied; validator `000000006215` recorded `completion_update 000422 88` and `confidence_update 000422 91` |
| C-000422-10 | MapPane class/file/aggregate support should sync current UID000422 evidence if stale. | Medium-high | Local docs previously contained only inherited 0001AP row-level detail. | `by-class/MapPane.md`, `by-file/MapPane.md`, `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`. | incorporate | applied; support validators `000000006216`, `000000006217`, and `000000006218` ok |
| C-000422-11 | `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md` already contains same-or-greater caller receiver proof. | High | Local support page has exact constructor snippets and callsites. | UserPane accessor support. | already-present | already-present; inspected and not edited because constructor receiver proof was same-or-greater detail |
| C-000422-12 | RankingDialog UID000422 collision/stale support is not evidence against MapPane and should be deferred or explicitly authorized. | High | Duplicate `UID:000422` in `0x00459600` page and stale RankingDialog links. | RankingDialog support/lifecycle notes. | exclude-with-reason | excluded-with-reason; supervisor explicitly kept RankingDialog duplicate UID/support collision out of this callback, so no RankingDialog docs were edited |

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits:

| Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md --apply --queue-timeout 240` | `000000006215` | `2026-07-04T11:42:49-04:00` | 0 | 1 | No warnings. Applied `completion_update 000422 88`, `confidence_update 000422 91`, UID link update for `00024A`, reference index add, projected stats update, and generated refresh state `deferred`. |
| `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240` | `000000006216` | `2026-07-04T11:42:55-04:00` | 0 | 1 | Existing MapPane support warnings: `missing_ref_uid:89` with ten printed and 79 suppressed. Added reference index entry for `00024A`, updated stats row for `00007Q`, generated refresh state `deferred`. |
| `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240` | `000000006217` | `2026-07-04T11:43:07-04:00` | 0 | 1 | Existing MapPane support warnings: `missing_ref_uid:100` with ten printed and 90 suppressed. Added reference index entry for `000422`, updated stats row for `0000L3`, generated refresh state `deferred`. |
| `python .\tools\validator.py --mode file --file by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md --apply --queue-timeout 240` | `000000006218` | `2026-07-04T11:43:17-04:00` | 0 | 1 | No warnings. `stats_incremental_noop 0001AP`, projected stats update, generated refresh state `deferred`. |

Generated freshness observation: `auto-generated/NexusTK/map/MapPane.cpp` was validator-refreshed with header `validator-command-id: 000000006218`, `validator-refreshed-at: 2026-07-04T11:43:17-04:00`, and filesystem last write `2026-07-04T11:43:24-04:00`. It contains UID000422 at lines `405-410` as `MapPane::GetVisibleTileSpan(MapPoint *outSpan) const` with `outSpan->row = m_visibleTileRows;` and `outSpan->column = m_visibleTileColumns;`, no bare empty marker for UID000422.

No validator errors occurred. B008 did not manually edit generated files, coverage reports, validator state, lifecycle/archive state, or supervisor ledgers.

## Lease State

B008 leased the edited by-* files immediately before editing:

> Executable block R001 was removed from this report and preserved verbatim in [000422-MapPaneGetVisibleTileSpan-source-quality-removed.md](000422-MapPaneGetVisibleTileSpan-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The current lease report showed B008 owning those four leases at `2026-07-04T15:38:14Z` with expiration `2026-07-04T15:43:14Z`. B008 attempted to renew the same leases before validation; the lease tool rejected renewal with `Rejected[Already has lease]`, confirming B008 still owned them at that moment.

Validator command timestamps were `15:42:49Z`, `15:42:55Z`, `15:43:07Z`, and `15:43:17Z`. The final aggregate validator timestamp landed just after the five-minute lease expiration. No other agent lease was present on the MapPane files until B006's later lease at `2026-07-04T15:45:53Z`.

B008 then attempted explicit release:

> Executable block R002 was removed from this report and preserved verbatim in [000422-MapPaneGetVisibleTileSpan-source-quality-removed.md](000422-MapPaneGetVisibleTileSpan-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The release command exited `1` because the target had `Rejected[No active lease]`, and the three MapPane support docs had already been acquired by B006 (`Rejected[Lease owned by B006]`). Current lease report confirms B008 holds no active lease on these files; B006 owns `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` until `2026-07-04T15:50:53Z`. B008 performed no further support edits after seeing B006 ownership.

## Changed Files

Manual/apply_patch edits in this callback:

- `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md`
- `by-class/MapPane.md`
- `by-file/MapPane.md`
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `tools/leaser/Agents/Agent-B008/research/000422-MapPaneGetVisibleTileSpan-source-quality.md`

Validator-owned side effects observed from scoped validation:

- `auto-generated/NexusTK/map/MapPane.cpp` refreshed by validator command `000000006218`.
- `project-level/-auto-completion-stats.md` projected/stat rows updated by validators.
- Reference index entries were updated by validators for `00024A` and `000422`.

No RankingDialog duplicate UID files, generated files by hand, coverage reports, lifecycle/archive files, or supervisor ledgers were edited by B008.

## Implementation Tracking Checklist

- [x] Update target `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md` to `COMPLETION:88`, `CONFIDENCE:91`, preserving `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank optional emitter position. Proof: target header and validator `000000006215`.
- [x] Keep/reinsert the exact formal `MapPane::GetVisibleTileSpan` C++ block from this report. Proof: target formal block preserved and generated output command `000000006218` contains the same method body.
- [x] Add current MCP session `60724697` evidence to the target: exact range, size, bytes, disassembly/decompilation, no callees, two callsites, caller receiver proof, padding, successor split, and negative type-query result. Proof: target Evidence and Score Rationale sections.
- [x] Clarify output order in the target: `+0x404` visible columns -> output offset `+4`; `+0x408` visible rows -> output offset `+0`. Proof: target Evidence plus MapPane support sync.
- [x] Sync `by-class/MapPane.md` if stale: UID000422 current proof and narrowed field-order caveat. Proof: field glossary and UID000422 class note added; validator `000000006216` ok.
- [x] Sync `by-file/MapPane.md` if stale: source-ready UID000422 route through `NexusTK/map/MapPane.cpp`. Proof: file-route UID000422 paragraph and changes entry added; validator `000000006217` ok.
- [x] Sync parent aggregate `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` if stale: UID000422 row to `88/91` source-ready current proof. Proof: covered-range row and changes entry updated; validator `000000006218` ok.
- [x] Confirm `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md` as already-present unless supervisor wants current session wording. Proof: inspected; existing Constructor Evidence has the two receiver/callsite snippets, so no edit was needed.
- [x] Do not treat RankingDialog duplicate UID support as MapPane ownership evidence. Proof: marked excluded-with-reason in ledger because supervisor declared RankingDialog duplicate UID/support collision out of scope; no RankingDialog files were edited.
- [x] Run scoped validators for every edited by-* file from `source-3/project-documentation`. Proof: validator commands `000000006215` through `000000006218`, all exit 0 / ok 1.
- [x] Record lease state. Proof: B008 acquired the target/support leases before editing, attempted renewal before validation, then explicit release after expiration returned target `No active lease` and support docs `Lease owned by B006`; current report records no active B008 leases and no further B008 support edits after B006 ownership appeared.
- [x] Do not run `execute_report`, lifecycle/archive commands, registry commands, generated-file edits, coverage-report edits, or MCP process-management commands. Proof: only scoped validators and read-only generated checks were run after by-* edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000006249","destination_path":"executed-b-agent-research/B008/000422-MapPaneGetVisibleTileSpan-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/000422-MapPaneGetVisibleTileSpan-source-quality.md","timestamp":"2026-07-04T12:02:26-04:00","uid":"000422"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000422-MapPaneGetVisibleTileSpan-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/000422-MapPaneGetVisibleTileSpan-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000422"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
