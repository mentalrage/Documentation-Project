** TARGET-REPORT-UID:00027U **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00027U MonsterImageLibDefaultFrameRecord Advanced-Scan Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](../../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) as reconstructable source-declared data owned and emitted by [UID:0000LK][MonsterImageLibTables](../../../../../by-file/MonsterImageLibTables.md).
- Final disposition: the Advanced-Error-Scan finding was a real scanner-visible body-label gap, not an owner, emitter, range, split, merge, reclassification, or generated-name problem.
- Required action: no `by-memory/-coverage-report.md` edit is required. The target page was repaired in scope and validated.
- Confidence: 94/100 for this recommendation; target score remains `82/86`.

## Supporting Research

## Target

- Target UID: `00027U`
- Target path: `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan, `missing document text for MonsterImageLibDefaultFrameRecord`
- Current supervisor classification: assigned to Agent-B002 in `tools/leaser/Agents/Supervisor_notes.md` on 2026-06-14.
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000LK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LK`, C++ blank.

## Executive Recommendation

Keep the current owner/emitter route. The item is a shared default/fallback 10-byte frame-entry record plus two zero alignment bytes, returned by both monster/riding table frame lookup helpers on out-of-range input. The best direct source owner remains [UID:0000LK][MonsterImageLibTables](../../../../../by-file/MonsterImageLibTables.md), not `MonsterImageLib` alone or `RidingImageLib` alone, because the lookup helpers and record initializer live in the shared helper island used by both image systems.

No split is needed. The predecessor [UID:00027T][NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md) already owns the zero padding up to `0x0066deb0`; [UID:00027V][MusicControlDriveRootBuffers](../../../../../by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md) starts exactly at the next referenced buffer. No final C++ should be entered because the page is `82/86`, and final neutral frame-entry type/field names remain below the active 90/90+ code-entry gate.

## Supervisor Active Recheck

The supervisor assignment asked B002 to determine whether the advanced-scan finding was a real documentation gap, stale filename/label, owner/emitter/range issue, generated-name issue, or harmless scanner wording issue.

Result:

- Real documentation gap: yes, narrow body-label gap. The exact filename label `MonsterImageLibDefaultFrameRecord` was absent from the body before ignored/change sections.
- Stale filename/label: no. The filename label accurately describes the shared default frame record and now appears explicitly in the target body.
- Owner/emitter issue: no. `0000LK` remains correct and currently clears `85/85`.
- Range issue: no. Live IDA and raw PE both confirm `0x0066deb0-0x0066debc`.
- Split/merge issue: no. Neighboring padding and drive-root buffers are already split into separate pages.
- Generated-name issue: no. `MonsterImageLibDefaultFrameRecord` is descriptive, not a generated `unk_`/`sub_`/`DAT_` label.

## Inference Research Guidance Check

`inference_research.md` warns that adjacent globals are weak ownership evidence by themselves, so I used adjacency only for boundary checks. Ownership is based on data-flow facts: both frame lookup helpers return this exact record, the normal record initializer writes the same byte shape into allocated records, and the shared helper file page owns the lookup/initializer family used by monster and riding code.

IDA facts:

- Exact bytes and uniqueness.
- Xrefs only from the two lookup helpers.
- No interior xrefs.
- Successor `RootPathName` and following LivingObjectPane boundary refs.
- Decompiler output for lookup helpers and frame-record initializer.

Documentation evidence:

- Target page, `MonsterImageLibTables` file page, helper island page, helper class pages, and neighboring by-memory pages.

Inference:

- The source likely had a private static/default frame-entry object near the shared table-helper implementation. Final original type/name spelling remains unresolved.

## Evidence Standards Used

Evidence used:

- IDA MCP `idb_list`, `server_health`, `get_bytes`, `xref_query`, `lookup_funcs`, `decompile`, `find_bytes`, and `make_signature_for_range`.
- Raw PE section/offset/byte scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current generated and manual coverage rows.
- Current by-file/by-memory/by-class documentation for `MonsterImageLibTables`, neighboring data, and helper classes.

The evidence is strong enough to keep ownership, route, range, and split state. It is not strong enough for final C++ because neutral source-level helper names and the final frame-entry declaration spelling are still unresolved.

## IDA MCP Facts

Session facts:

- Session: `b001_0003gy`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis and Hex-Rays: ready.

Function/range facts:

- `0x00528b10` is `sub_528B10`, size `0x34`.
- `0x00528d00` is `sub_528D00`, size `0x28`.
- `0x00528d30` is `sub_528D30`, size `0x16`.
- `0x00528be0` is `sub_528BE0`, size `0x9c`.
- `0x0066deb0`, `0x0066debc`, and `0x0066decc` are data, not functions.

Data facts:

```text
0x0066deb0-0x0066debc:
00 00 00 00 ff 00 ff ff 00 00 00 00
```

`make_signature_for_range 0x0066deb0-0x0066debc` returned that sequence and reported it as unique.

Xref facts:

| Target | IDA MCP xrefs | Meaning |
| --- | --- | --- |
| `0x0066de6c` | none | Predecessor padding has no refs. |
| `0x0066deb0` | `0x00528b2f`, `0x00528d11` | The default frame record is returned by both lookup helpers. |
| `0x0066deb4` | none | Interior byte/sentinel field, no separate item. |
| `0x0066deb6` | none | Interior word sentinel, no separate item. |
| `0x0066deb8` | none | Interior tail word, no separate item. |
| `0x0066deba` | none | Alignment tail inside this documented span. |
| `0x0066debc` | `0x00529304`, `0x00529309`, `0x0052a061`, `0x0052a066` | Next `RootPathName`/MusicControl buffer starts after the record. |
| `0x0066decc` | `0x005a8bf7`, `0x005a8c3d` | Following LivingObjectPane word-slot range starts later. |

Decompiler facts:

```c
// 0x00528b10
if ( *(unsigned __int8 *)(this + 4) > a2 )
  v3 += 8 * a2;
if ( *(unsigned __int16 *)(v3 + 4) > a3 )
  return (void *)(*(_DWORD *)v3 + 10 * a3);
else
  return &unk_66DEB0; /*0x528b2f*/
```

```c
// 0x00528d00
if ( this[2] > a2 )
  return (void *)(*(_DWORD *)this + 10 * a2);
else
  return &unk_66DEB0; /*0x528d11*/
```

```c
// 0x00528d30
this[4] = -1;
*(_DWORD *)this = 0;
*((_WORD *)this + 4) = 0;
*((_WORD *)this + 3) = -1;
```

```c
// 0x00528be0
`eh vector constructor iterator'(v4 + 1, 0xAu, a2,
  (void (__thiscall *)(void *))sub_528D30, nullsub_13);
```

Negative IDA facts:

- No xrefs to `0x0066debc` from `MonsterImageLibTables`; those refs belong to the next `MusicControlDialog` buffers.
- No xrefs to interior offsets in the fallback record; all source-use routing is through the base address.
- No xrefs to predecessor padding start `0x0066de6c`; the target starts cleanly at `0x0066deb0`.

## Raw PE Facts

Raw-file check:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Section: `.data`
- VA `0x0066deb0` maps to raw offset `0x26bab0`.
- VA `0x0066debc` maps to raw offset `0x26babc`.
- VA `0x0066decc` maps to raw offset `0x26bacc`.

Raw bytes at `0x26bab0`:

```text
00 00 00 00 FF 00 FF FF 00 00 00 00
```

The predecessor `0x0066de6c-0x0066deb0` maps to raw `0x26ba6c-0x26bab0`, is 68 bytes long, and is all zero. The next 16 bytes at `0x0066debc` are:

```text
58 3A 5C 00 58 00 3A 00 00 00 00 00 50 00 00 00
```

Raw pattern counts:

| Pattern | Count | Raw offsets |
| --- | ---: | --- |
| Target 12-byte fallback record | 1 | `0x26bab0` |
| Little-endian `0x0066deb0` | 2 | `0x127f30`, `0x128112` |
| Little-endian `0x0066debc` | 4 | `0x128705`, `0x12870b`, `0x129462`, `0x129468` |
| Little-endian `0x0066decc` | 2 | `0x1a7ff9`, `0x1a803f` |

Raw PE evidence agrees with IDA xrefs and boundaries.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0066de6c-0x0066deb0` | [UID:00027T][NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md) | Predecessor zero padding | FALSE | NONE | `100/92` | Separate ignored padding. |
| `0x0066deb0-0x0066debc` | [UID:00027U][MonsterImageLibDefaultFrameRecord](../../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) | This shared default frame record | TRUE | `0000LK` | `82/86` | Keep owner/emitter; repaired scanner body text. |
| `0x0066debc-0x0066decc` | [UID:00027V][MusicControlDriveRootBuffers](../../../../../by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md) | Successor drive-root buffers | TRUE | `0000LN` | `84/90` | Separate MusicControlDialog data. |
| `0x00528930-0x00528d51` | [UID:0001CM][MonsterImageLibTables](../../../../../by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) | Shared helper island | TRUE | `0000LK` | `82/88` | Contains lookup helpers and initializer behavior. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00528b2f -> 0x0066deb0` | `sub_528B10` | Outer/group lookup fallback returns this record. |
| `0x00528d11 -> 0x0066deb0` | `sub_528D00` | Inner/frame lookup fallback returns this record. |
| `0x00528d30` | frame-record initializer | Initializes normal 10-byte records with same null/sentinel/tail shape. |
| `0x00528be0 -> 0x00528d30` | vector constructor callback | Allocated frame-record vectors use the same initializer as the fallback record shape. |
| `0x00529304`, `0x00529309`, `0x0052a061`, `0x0052a066 -> 0x0066debc` | MusicControlDialog refs | Successor data starts after this target. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00027U][target page](../../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) already documented bytes, xrefs, helper behavior, `RootPathName` boundary, owner route, and final-C++ blocker.
- [UID:0000LK][MonsterImageLibTables](../../../../../by-file/MonsterImageLibTables.md) is `85/85`, has valid path `NexusTK/render/`, and explicitly lists this shared fallback record as helper-file data.
- [UID:0001CM][MonsterImageLibTables helper island](../../../../../by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) documents the lookup helpers and frame-record initializer.
- [UID:00008O][MonsterImageLibTable_5289D0](../../../../../by-class/MonsterImageLibTable_5289D0.md) and [UID:00008P][MonsterImageLibTable_528BE0](../../../../../by-class/MonsterImageLibTable_528BE0.md) both describe this fallback record as the shared default returned by lookup helpers.
- [UID:00027T][NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md) and [UID:00027V][MusicControlDriveRootBuffers](../../../../../by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md) confirm clean neighbor splits.

Existing docs repaired:

- The target body omitted the exact filename label `MonsterImageLibDefaultFrameRecord`.
- The target did not explicitly state the current canonical owner/emitter wording in its summary.
- The target had older evidence only; current B002 live IDA/raw PE evidence was added.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` already lists `00027U` as emitting through owner/emitter `0000LK` into `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`.
- `by-memory/-coverage-report.md` already has an accurate row for `00027U`; no supervisor replacement is needed.

## Ranked Ownership Analysis

### 1. [UID:0000LK] MonsterImageLibTables

Evidence for:

- The only xrefs to this data are in shared helper functions `0x00528b10` and `0x00528d00`.
- The normal frame-record initializer at `0x00528d30` writes the same field shape used by this fallback.
- The helper island is used by both `MonsterImageLib` and `RidingImageLib`, so the source owner should be the shared helper/type file, not only one consumer.
- Current parent file score is `85/85` and it has a valid generated path.
- Generated coverage already routes this target to `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`.

Evidence against:

- Final neutral type names and exact source spelling remain provisional.
- It is still uncertain whether `MonsterImageLibTables.cpp` was standalone or private helper code inside one render module.

Decision:

- Accept. Keep `CANONICAL_OWNER:0000LK` and `EMITTER_UIDS:0000LK`; keep C++ blank.

### 2. [UID:0000LJ] MonsterImageLib

Evidence for:

- Monster rendering and table-loading code uses the shared helper family.
- Existing names are monster-biased.

Evidence against:

- The lookup helpers that return `0x0066deb0` are shared with riding image paths.
- `MonsterImageLib` owns a separate concrete outer-table default object [UID:00029K](../../../../../by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md); that is not this shared inner-frame fallback.
- Assigning this target to monster-only storage would understate riding/shared helper use.

Decision:

- Reject as direct owner for this target. Keep as a consumer/source-family context.

### 3. [UID:0000N6] RidingImageLib

Evidence for:

- Riding image code calls the same shared table helpers.

Evidence against:

- No direct xrefs from riding-specific code to `0x0066deb0`; refs are in shared lookup helpers.
- The data is not concrete riding-definition global storage; that is documented separately.

Decision:

- Reject as direct owner. Keep as a consumer/context for the shared helper file.

### 4. Successor/predecessor data owners

Evidence for:

- The target sits physically between NCA padding and MusicControlDialog buffers.

Evidence against:

- Address adjacency alone is weak. There are no xrefs from those neighbor owners to `0x0066deb0`.
- The xrefs and helper behavior tie this data to monster/riding table helpers.

Decision:

- Reject. Neighbor pages define boundaries only.

## Negative Evidence Summary

- No xrefs to predecessor padding start `0x0066de6c`.
- No xrefs to interior offsets of the fallback record.
- No owner-relevant xrefs to successor `0x0066debc`; those refs belong to MusicControlDialog.
- No generated/decompiler placeholder in the filename label.
- No evidence that the item should be split into 10-byte record plus 2-byte standalone padding; current docs correctly treat the 2-byte tail as alignment within this small data item until final type recovery proves otherwise.

## Final Recommendation

Exact changes applied:

- Edited [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](../../../../../by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md).
- Added scanner-visible `MonsterImageLibDefaultFrameRecord` body text.
- Added current canonical owner/emitter wording.
- Added current B002 live IDA MCP and raw PE evidence.

Exact parent assignments applied or recommended:

- Keep `CANONICAL_OWNER:0000LK`.
- Keep `EMITTER_UIDS:0000LK`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Keep scores `82/86`.

Exact items left no-owner/non-emitting:

- None in this target. The adjacent padding page `00027T` correctly remains non-reconstructable and emitterless, but it was already handled by B003 and was not edited here.

Future work outside this assignment:

- A later source-reconstruction pass should select neutral helper/frame-entry type names and decide whether the two zero tail bytes are explicit structure fields or linker/source-layout alignment before entering final C++.

## Follow-Up Actions

Supervisor actions:

- No `by-memory/-coverage-report.md` replacement is needed for `00027U`.
- If regenerating `auto-generated/by-memory-tool-report.md`, the `MonsterImageLibDefaultFrameRecord` advanced-scan warning should clear because the exact label now appears in the target body.

A-agent actions:

- None required for this target.

B002 future research actions:

- None for this assigned item.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: target score remains `82/86`; no score increase was applied because this was a label/evidence repair, not a final reconstruction audit.
- Remaining uncertainty: final neutral type names, source-level constant spelling, and the exact structural meaning of the two zero tail bytes remain open.

## Validator Results

Command run without dry run:

> Executable block R001 was removed from this report and preserved verbatim in [00027U-MonsterImageLibDefaultFrameRecord-advanced-scan-removed.md](00027U-MonsterImageLibDefaultFrameRecord-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- `apply: True`
- `scanned markdown files: 1`
- `ok: 1`
- `autogen_registry_rebuild: 1`
- `autogen_report_noop: 7`
- `projected_stats_update: 1`
- `stats_incremental_noop 00027U project-level/-auto-completion-stats.md file is not present in generated stats lists`
- Pre-existing broad notice: `autogen_emitter_has_no_code 00000D by-class/Application.md emitting children only`; unrelated to this target.

Generated report state:

- `auto-generated/-ag-class-coverage.md`: unchanged.
- `auto-generated/-ag-file-coverage.md`: unchanged.
- `auto-generated/-ag-function-coverage.md`: unchanged.
- `auto-generated/-ag-global-coverage.md`: unchanged.
- `auto-generated/-ag-item-coverage.md`: unchanged.
- `auto-generated/-ag-memory-coverage.md`: unchanged.
- `auto-generated/-ag-type-coverage.md`: unchanged.

## Lease State

- Leased target page as `B002` before editing.
- Released target page after validation.
- Final lease check showed no active B002 leases. B003 held an unrelated lease on neighboring [UID:00027W].

## Supervisor-Owned Shared-Report Text

No shared-report edit is required. Keep the existing `by-memory/-coverage-report.md` row for `00027U` exactly as:

```text
    - [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) 0x0066deb0-0x0066debc | default frame record | MonsterImageLibDefaultFrameRecord : reconstructable : 82% : strong : Monster/riding fallback frame record attached to MonsterImageLibTables, with raw bytes, lookup fallback xrefs, initializer match, and `RootPathName` boundary documented.
```

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00027U-MonsterImageLibDefaultFrameRecord-advanced-scan.md`
- Modified: `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md`
- Validator-managed side effect reported: `project-level/-auto-completion-stats.md` projected path completion section updated.
- Not modified: `by-memory/-coverage-report.md`
- Not modified: generated `auto-generated/-ag-*` reports, all reported unchanged.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00027U-MonsterImageLibDefaultFrameRecord-advanced-scan.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00027U"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00027U-MonsterImageLibDefaultFrameRecord-advanced-scan-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00027U-MonsterImageLibDefaultFrameRecord-advanced-scan.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00027U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
