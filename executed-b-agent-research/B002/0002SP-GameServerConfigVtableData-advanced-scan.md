** TARGET-REPORT-UID:0002SP **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002SP GameServerConfigVtableData Advanced-Scan Pass

## Final Recommendation

Keep [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](../../../../../by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) as a non-emitting split container:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `COMPLETION:88`
- `CONFIDENCE:93`

The Advanced-Error-Scan finding was a real scanner-visible label/body-text gap, not a substantive missing-documentation or ownership gap. The target filename still contains `GameServerConfigVtableData`, but the body used the clarified title `GameServerConfig Vtable Boundary Data` and did not include the exact no-space filename label. I repaired the target page by adding scanner-visible `GameServerConfigVtableData` body text and by replacing legacy `AUTOGEN_PARENT_UID` assignment-gate wording with current `CANONICAL_OWNER`/`RECONSTRUCTABLE`/`EMITTER_UIDS` terminology.

No owner, emitter, score, range, split, merge, or reconstruction-code change is needed for the by-memory page. The shared `by-memory/-coverage-report.md` row is stale and needs supervisor replacement; I did not edit that shared report directly.

## Target And Scope

- Source finding: `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan
- Finding text: `0x0061e704-0x0061e71c.GameServerConfigVtableData.md: missing document text for GameServerConfigVtableData`
- Target page: `by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md`
- UID: `0002SP`
- Range: `0x0061e704-0x0061e71c`
- Current subject after split: mixed vtable/RTTI boundary data, retained as a coverage and historical-continuity container.

I rechecked the target page, exact child pages, parent aggregate, related class/file pages, generated coverage rows, live IDA MCP data, and raw PE bytes. The current generated `auto-generated/-ag-memory-coverage.md` state already matches the target metadata: `0002SP` is `not_reconstructable`, owner `NONE`, with blank emitters.

## Evidence Standard Applied

This pass used the Goal 2 B-agent standard:

- Prior reports and existing docs were treated as leads only.
- Live IDA MCP evidence was collected from the current active IDB.
- Raw PE bytes were checked independently from the read-only executable.
- No C++ reconstruction was entered because the item is a non-reconstructable container and no direct source route reaches the 90/90+ reconstruction-code gate for the whole range.
- No direct edit was made to `by-memory/-coverage-report.md`.

## Documentation State Before Repair

The target page already documented the correct three-way split:

- [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](../../../../../by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md) owns the exact `ProtectedArray<GameServerConfig::NationEntry>` one-slot vtable and routes to [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](../../../../../by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md).
- [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](../../../../../by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md) owns the exact `GameServerConfig` COL plus three-slot class vtable and routes to [UID:00005O][GameServerConfig](../../../../../by-class/GameServerConfig.md).
- [UID:0003IK][0x0061e718-0x0061e71c.MapPaneRttiBoundaryData](../../../../../by-memory/0x0061e718-0x0061e71c.MapPaneRttiBoundaryData.md) is an unreferenced `MapPane` COL boundary dword before [UID:0002SQ][0x0061e71c-0x0061e7a0.MapPaneVtableData](../../../../../by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md).

The substantive document gap was narrow: the body did not include the exact scanner label `GameServerConfigVtableData`. The page also still described the blank parent decision through legacy `AUTOGEN_PARENT_UID` wording even though current metadata uses `CANONICAL_OWNER`, `RECONSTRUCTABLE`, and `EMITTER_UIDS`.

## Live IDA MCP Facts

IDA MCP session:

- Session: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis: ready
- Hex-Rays: ready

`get_bytes` for the target range:

```text
0x0061e704:
50 4d 51 00 34 b2 64 00 80 4d 51 00 10 4b 4f 00
c0 b6 41 00 5c b1 64 00
```

IDA MCP `make_signature_for_range 0x0061e704-0x0061e71c` produced the same 24-byte signature and reported it as unique:

```text
50 4D 51 00 34 B2 64 00 80 4D 51 00 10 4B 4F 00 C0 B6 41 00 5C B1 64 00
```

Decoded dwords by address:

| Address | Dword | Meaning |
| --- | --- | --- |
| `0x0061e704` | `0x00514d50` | `ProtectedArray<GameServerConfig::NationEntry>` deleting destructor vtable slot |
| `0x0061e708` | `0x0064b234` | `GameServerConfig` complete-object-locator |
| `0x0061e70c` | `0x00514d80` | `GameServerConfig` scalar deleting destructor vtable slot |
| `0x0061e710` | `0x004f4b10` | `GameServerConfig` vtable slot |
| `0x0061e714` | `0x0041b6c0` | `GameServerConfig` vtable slot |
| `0x0061e718` | `0x0064b15c` | `MapPane` complete-object-locator boundary |
| `0x0061e71c` | `0x00514de0` | Next range start: `MapPane` vtable slot |

IDA MCP `lookup_funcs` confirmed:

- `0x005039f0` and `0x00503a50` are not IDA functions, matching the raw constructor/destructor documentation for [UID:0002HV](../../../../../by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md) and [UID:0002HW](../../../../../by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md).
- `0x00504110` is `sub_504110`, size `0x411`.
- `0x00504530` is `sub_504530`, size `0x196`.
- `0x00514d50` is `sub_514D50`, size `0x2f`.
- `0x00514d80` is `sub_514D80`, size `0x5c`.
- `0x00514de0` is `sub_514DE0`, size `0x3b`.
- `0x0061e704`, `0x0061e70c`, `0x0061e718`, and `0x0061e71c` are data, not functions.

## Xrefs And Function Evidence

IDA MCP `xref_query` results:

| Target | Xrefs | Interpretation |
| --- | --- | --- |
| `0x0061e700` | none | Previous-page boundary COL has no direct source-use refs in this target. |
| `0x0061e704` | `0x00503a1c`, `0x00503a5c`, `0x00504481`, `0x00514d59`, `0x00514d8f` | Protected-array vtable is installed by raw GameServerConfig table init/cleanup, MapPane inlining, protected-array destructor, and GameServerConfig destructor. |
| `0x0061e708` | none | `GameServerConfig` COL boundary, not a separately referenced source route. |
| `0x0061e70c` | `0x00503a16`, `0x00503a53`, `0x00504478`, `0x00514d86` | `GameServerConfig` vtable is installed by raw GameServerConfig table init/cleanup, MapPane inlining, and GameServerConfig destructor. |
| `0x0061e710` | none | Internal vtable slot, not a vtable-base reference. |
| `0x0061e714` | none | Internal vtable slot, not a vtable-base reference. |
| `0x0061e718` | none | `MapPane` COL boundary has no direct refs and should not create a source owner. |
| `0x0061e71c` | `0x0050418b`, `0x00504557` | Next child begins at the `MapPane` vtable, used by MapPane constructor/destructor code. |

Relevant decompiler evidence:

```c
// 0x00514d50
*Block = &ProtectedArray<GameServerConfig::NationEntry>::`vftable'; /*0x514d59*/
```

```c
// 0x00514d80
*Block = &GameServerConfig::`vftable'; /*0x514d86*/
Block[1] = &ProtectedArray<GameServerConfig::NationEntry>::`vftable'; /*0x514d8f*/
unk_69B4C4 = 0; /*0x514d9e*/
```

```c
// 0x00504110
*(_DWORD *)this = &MapPane::`vftable'; /*0x50418b*/
*(_DWORD *)v7 = &GameServerConfig::`vftable'; /*0x504478*/
*(_DWORD *)(v7 + 4) = &ProtectedArray<GameServerConfig::NationEntry>::`vftable'; /*0x504481*/
```

```c
// 0x00504530
*this = &MapPane::`vftable'; /*0x504557*/
```

This supports the current split: `GameServerConfig` uses its own class vtable and the embedded protected-array vtable, while `MapPane` starts at `0x0061e71c`. The dword at `0x0061e718` is a boundary COL for the following `MapPane` vtable, not a `GameServerConfig` slot.

## Raw PE Evidence

Independent raw-file check:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Section: `.rdata`
- VA `0x0061e704` maps to raw offset `0x21d104`
- Bytes at raw `0x21d104`:

```text
50 4D 51 00 34 B2 64 00 80 4D 51 00 10 4B 4F 00 C0 B6 41 00 5C B1 64 00
```

Raw decoded dwords:

| VA | Raw offset | Dword |
| --- | --- | --- |
| `0x0061e704` | `0x21d104` | `0x00514d50` |
| `0x0061e708` | `0x21d108` | `0x0064b234` |
| `0x0061e70c` | `0x21d10c` | `0x00514d80` |
| `0x0061e710` | `0x21d110` | `0x004f4b10` |
| `0x0061e714` | `0x21d114` | `0x0041b6c0` |
| `0x0061e718` | `0x21d118` | `0x0064b15c` |
| `0x0061e71c` | `0x21d11c` | `0x00514de0` |

Raw pattern counts:

| Pattern | Count | Raw offsets |
| --- | ---: | --- |
| Target 24-byte sequence | 1 | `0x21d104` |
| Little-endian ref to `0x0061e704` | 5 | `0x102e1e`, `0x102e5f`, `0x103883`, `0x11415b`, `0x114192` |
| Little-endian ref to `0x0061e70c` | 4 | `0x102e18`, `0x102e55`, `0x10387a`, `0x114188` |
| Little-endian ref to `0x0061e718` | 0 | none |
| Little-endian ref to `0x0061e71c` | 2 | `0x10358d`, `0x103959` |

The raw PE counts match the IDA xref shape and the current child split.

## Alternatives Rejected

### Assign `0002SP` To `GameServerConfig`

Rejected. The range contains `GameServerConfig` data, but not only `GameServerConfig` data. It also contains the protected-array vtable at `0x0061e704` and the `MapPane` COL boundary at `0x0061e718`. Assigning the whole container to [UID:00005O][GameServerConfig](../../../../../by-class/GameServerConfig.md) would overclaim source ownership.

### Assign `0002SP` To `ProtectedArray<GameServerConfig::NationEntry>`

Rejected. Only `0x0061e704-0x0061e708` belongs to that concrete protected-array vtable. The rest of the range is `GameServerConfig` COL/vtable and `MapPane` RTTI boundary data.

### Assign `0002SP` To `MapPane`

Rejected. `MapPane` ownership starts at the unreferenced COL boundary `0x0061e718` and the referenced vtable base `0x0061e71c`. The `0x0061e704-0x0061e718` prefix belongs to the GameServerConfig/protected-array side.

### Add Emitters To `0002SP`

Rejected. Emitters belong on the exact reconstructable children:

- `0003II` emits through `0000B4`.
- `0003IJ` emits through `00005O`.
- `0003IK` remains non-reconstructable and emitterless.

Adding emitters to the parent container would duplicate child routes and imply a source-emitting aggregate that does not exist.

### Rename Or Merge The File

Rejected for this pass. The retained filename label is historical and stable, and the body now explicitly states that `GameServerConfigVtableData` is a scanner-visible historical filename label for a reviewed non-emitting boundary container. A rename would create broader reference churn without improving source ownership. The current exact child split is already sufficient.

### Create Additional Children

Rejected. Existing children cover every dword in the target:

- `0x0061e704-0x0061e708`
- `0x0061e708-0x0061e718`
- `0x0061e718-0x0061e71c`

No uncovered subrange remains.

## In-Scope Edit Performed

Edited `by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md` under lease.

Changes:

- Added scanner-visible body text:

```text
Scanner-visible filename label: `GameServerConfigVtableData`. The retained filename label is historical; the current reviewed subject is a non-emitting boundary container over exact protected-array, `GameServerConfig`, and `MapPane` RTTI/vtable children.
```

- Refreshed the assignment gate from legacy `AUTOGEN_PARENT_UID` wording to current fields:

```text
`CANONICAL_OWNER` remains `NONE`, `RECONSTRUCTABLE` remains `FALSE`, and
`EMITTER_UIDS` remains blank because this page is a reviewed split container,
not a direct source owner or source-emitting item.
```

- Added a dated change-log entry recording that no metadata, score, range, owner, emitter, or reconstruction-code change was made.

## Validator Result

Validator command run without dry run:

> Executable block R001 was removed from this report and preserved verbatim in [0002SP-GameServerConfigVtableData-advanced-scan-removed.md](0002SP-GameServerConfigVtableData-advanced-scan-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

- `apply: True`
- `scanned markdown files: 1`
- `ok: 1`
- `autogen_registry_rebuild: 1`
- `autogen_report_noop: 7`
- Validator reported no changes to the generated reports.
- Validator reported a projected path completion-section update in `project-level/-auto-completion-stats.md`.
- Pre-existing broad notice observed: `autogen_emitter_has_no_code 00000D by-class/Application.md emitting children only`; this is unrelated to `0002SP`.

Lease was released after validation.

## Coverage-Report Supervisor Edit Needed

Do not edit `by-memory/-coverage-report.md` directly from this pass. The row for `0002SP` is stale: it still says `vtable-data`, `reconstructable`, `86%`, and that candidate direct parents fail the corrected 85/85 gate. That no longer matches the current target page or generated coverage state.

Placement context: under [UID:00025S][0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData](../../../../../by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md), replace the existing child row immediately after the `00025S` aggregate row and before the `0002SQ` MapPane row.

Replace this row:

```text
        - [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) 0x0061e704-0x0061e71c | vtable-data | GameServerConfigVtableData : reconstructable : 86% : strong : Live IDA verified the exact one-slot `ProtectedArray<GameServerConfig::NationEntry>` vtable, `GameServerConfig` COL and three-slot vtable, trailing `MapPane` COL boundary at `0x0061e718`, exact bytes, and constructor/destructor xrefs; deliberately left unassigned because candidate direct parents fail the corrected 85/85 gate.
```

With this row:

```text
        - [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) 0x0061e704-0x0061e71c | vtable/rtti-boundary-data | GameServerConfigVtableData : not_reconstructable : 88% : very strong : B002 advanced-scan pass confirmed this is a reviewed non-emitting split container, not a source-owned vtable item; current target page now contains scanner-visible `GameServerConfigVtableData` body text. Exact children carry ownership/routing: [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md) is the `ProtectedArray<GameServerConfig::NationEntry>` vtable routed to [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md), [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md) is the `GameServerConfig` COL/three-slot vtable routed to [UID:00005O][GameServerConfig](by-class/GameServerConfig.md), and [UID:0003IK][0x0061e718-0x0061e71c.MapPaneRttiBoundaryData](by-memory/0x0061e718-0x0061e71c.MapPaneRttiBoundaryData.md) is an unreferenced non-reconstructable `MapPane` COL boundary before [UID:0002SQ][0x0061e71c-0x0061e7a0.MapPaneVtableData](by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md); live IDA/raw PE evidence confirms exact bytes, xrefs, and boundaries.
```

## Confidence

- Recommendation confidence: 93/100.
- Completion for the target remains 88/100.

The evidence is internally consistent across current docs, generated coverage state, live IDA bytes, IDA xrefs, Hex-Rays output, and raw PE bytes. Confidence remains below final audit because this is a non-emitting split container and final source reconstruction belongs to its exact children, not to `0002SP`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002SP-GameServerConfigVtableData-advanced-scan.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002SP"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002SP-GameServerConfigVtableData-advanced-scan-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002SP-GameServerConfigVtableData-advanced-scan.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002SP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
