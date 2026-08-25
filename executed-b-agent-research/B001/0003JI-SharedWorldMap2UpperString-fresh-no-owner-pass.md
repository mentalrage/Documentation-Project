** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Fresh No-Owner Pass

## Final Recommendation

Keep [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](../../../../../../by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) unchanged:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000PB`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank
- Scores unchanged at `COMPLETION:87`, `CONFIDENCE:93`

This is a source-declared/generated-binary UTF-16 pooled literal for `WM2`. Fresh IDA MCP and raw PE evidence prove two material source-use routes: MapPane packet/world-map creation code and WorldMapPane special-region hit-test code. Neither route proves a single direct semantic declaration owner, and assigning the literal to either consumer would overclaim the shared pooled literal. The existing multi-emitter routing is valid and not a dead end, because both emitters are singular `by-file` roots under `NexusTK/map/`.

No by-memory, by-file, by-class, generated coverage, or by-memory/-coverage-report edits are recommended.

## Target And Scope

- Assignment: fresh Goal 2 no-owner memory pass.
- Target UID: `0003JI`
- Target page: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Prior report reviewed only as historical context: `tools/leaser/Agents/Agent-B002/research/executed/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md`
- Current generated source: `auto-generated/-ag-memory-coverage.md`
- Active rule applied: pooled/shared literals may remain `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` when no single declaration owner is proven and the source-use emitters are proven.

## Current Metadata Before And After

| Field | Before | After | Decision |
| --- | --- | --- | --- |
| UID | `0003JI` | `0003JI` | unchanged |
| Range | `0x0061ea48-0x0061ea50` | `0x0061ea48-0x0061ea50` | exact |
| Name | `SharedWorldMap2UpperString` | `SharedWorldMap2UpperString` | descriptive enough |
| Completion | `87` | `87` | unchanged |
| Confidence | `93` | `93` | unchanged |
| Canonical owner | `NONE` | `NONE` | keep no-owner |
| Reconstructable | `TRUE` | `TRUE` | source-declared/generated-binary literal |
| Emitters | `0000L3,0000PB` | `0000L3,0000PB` | keep both |
| C++ block | blank | blank | no standalone declaration/source snippet recommended |

Combined score: `(87 + 93) / 2 = 90`, which clears the current minimum code-entry score gate. The item also has nonblank emitters that route to valid generated source roots. That makes it metadata-eligible, but I still recommend no C++ entry here: the original source shape is best represented as use-site `L"WM2"` literals in the future MapPane and WorldMapPane method rewrites, with the compiler/linker pooling the read-only bytes. A standalone declaration would invent a source owner not proven by the binary.

## Current Generated Coverage Rows

Current `auto-generated/-ag-memory-coverage.md` primary row:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
```

Current emitter/detail row:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

Current no-owner summary row:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

These rows are correct for the current state. No replacement row is needed.

Current `by-memory/-coverage-report.md` row should also remain unchanged:

```text
- [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`); B002 reconfirmed no interior-tail refs, no split/merge/reclassification, and no duplicate source object.
```

Although that row names prior review history, its substantive owner/emitter conclusion still matches the fresh evidence. No supervisor-owned shared-report edit is required.

## Documentation Evidence Checked

- Target page `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` already records the exact `WM2` literal, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and emitters `0000L3,0000PB`.
- Parent split index [UID:0003IX][0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings](../../../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) is a non-emitting container over `.PAL`, `wm`/`WM`, `wm2`/`WM2`, `wm3`/`WM3`, and `wm4`/`WM4`; it is not a source owner for this exact literal.
- Sibling [UID:0003JG][SharedMapPaletteSuffixString](../../../../../../by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) is the same shared-literal pattern with emitters `0000L3,0000PB`.
- Sibling [UID:0003JH][MapPaneWorldMapNameComparisonStrings](../../../../../../by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) is MapPane-only for `wm`, `WM`, `wm2`; this stops immediately before the target.
- Sibling [UID:0003JJ][MapPaneWorldMapNameThreeFourStrings](../../../../../../by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) is MapPane-only for `wm3`, `WM3`, `wm4`, `WM4`; this starts immediately after the target.
- [UID:0000L3][MapPane](../../../../../../by-file/MapPane.md) is a valid file root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and documents `sub_511DB0` as MapPane packet/world-map creation code.
- [UID:0000PB][WorldMapPane](../../../../../../by-file/WorldMapPane.md) is a valid file root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and documents WorldMapPane as a separate `map/WorldMapPane.cpp` source module.
- [UID:00007Q][MapPane](../../../../../../by-class/MapPane.md) records `0x00511db0` as map transition and world-map creation code.
- [UID:0000G9][WorldMapPane](../../../../../../by-class/WorldMapPane.md) records WorldMapPane as the modal world-map travel pane and routes it to `0000PB`.

## Live IDA MCP Evidence

IDA MCP session:

- Session: `a001_goal2_class_batch`
- Module: `NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Imagebase: `0x400000`
- Hex-Rays ready: yes

Function lookup:

- `lookup_funcs(0x00511db0)` reports `sub_511DB0`, size `0xa8a`.
- `lookup_funcs(0x00512263)` resolves inside `sub_511DB0`.
- `lookup_funcs(0x005c5200)` reports `sub_5C5200`, size `0x1d0`.
- `lookup_funcs(0x005c5219)` resolves inside `sub_5C5200`.
- `lookup_funcs(0x0061ea48)`, `0x0061ea4c`, and `0x0061ea50` report `Not a function`, as expected for `.rdata`.

String/name/byte evidence:

- `entity_query(names, 0x0061ea24-0x0061ea70)` reports contiguous names: `aPal`, `aWm`, `aWm_0`, `aWm2`, `aWm2_0`, `aWm3`, `aWm3_0`, `aWm4`, `aWm4_0`, then `aSMscfgDll`.
- `get_bytes(0x0061ea48, 8)` returns `57 00 4d 00 32 00 00 00`.
- `get_string(0x0061ea48)` returns `WM2`.
- `get_string` over the surrounding island returns `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4`.

Cross-references:

- `xrefs_to(0x0061ea48)` reports exactly two references:
  - `0x00512263`, data ref inside `sub_511DB0`.
  - `0x005c5219`, data ref inside `sub_5C5200`.
- `xrefs_to(0x0061ea4c)` reports zero references. There is no interior-tail split at the NUL terminator or second half of the literal.
- `xrefs_to(0x0061ea50)` reports one successor reference at `0x005122a3` inside `sub_511DB0`, proving the following `wm3` sibling is separate and MapPane-only.
- Surrounding refs support the sibling split:
  - `.PAL` at `0x0061ea24` is referenced from `sub_510960` and `sub_5C2AC0`.
  - `wm`, `WM`, and `wm2` at `0x0061ea30`, `0x0061ea38`, and `0x0061ea40` are referenced only from `sub_511DB0`.
  - `wm3`, `WM3`, `wm4`, and `WM4` at `0x0061ea50`, `0x0061ea58`, `0x0061ea60`, and `0x0061ea68` are referenced only from `sub_511DB0`.

Instruction evidence:

- `insn_query(op_any=0x0061ea48, 0x00512180-0x00512390)` reports:
  - `0x00512263: mov ecx, offset aWm2_0; "WM2"` inside `sub_511DB0`.
- `insn_query(op_any=0x0061ea48, 0x005c5200-0x005c53d0)` reports:
  - `0x005c5219: push offset aWm2_0; "WM2"` inside `sub_5C5200`.
- `insn_query(op_any=0x0061ea50, 0x00512180-0x00512390)` reports:
  - `0x005122a3: mov ecx, offset aWm3; "wm3"` inside `sub_511DB0`, confirming the successor belongs to the MapPane-only sibling, not this range.

Component/decompile evidence:

- `analyze_component(0x00511db0,0x005c5200)` lists `0x0061ea48 aWm2_0` as a shared global accessed by both `sub_511DB0` and `sub_5C5200`; it also shows no internal call edge between those two functions.
- `analyze_function(0x00511db0)` reports caller `sub_507C90` and callees including `sub_5C2AC0`, consistent with MapPane packet dispatch creating or initializing the world-map pane.
- `analyze_function`/`decompile(0x005c5200)` shows WorldMapPane-local hit-test/special-region logic calling `sub_5845B0(L"WM2")`, with callers from `sub_5C48B0`. This is a real WorldMapPane source-use path, not incidental data adjacency.

## Raw PE Evidence

Raw PE read:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Imagebase: `0x400000`
- `.rdata`: VA `0x0060d000`, raw `0x20ba00`

VA/raw mapping:

- `0x0061ea48` maps to `.rdata` raw `0x21d448`.
- Raw bytes at that location: `57 00 4d 00 32 00 00 00 77 00 6d 00 33 00 00 00`, which is `WM2\0` followed by the next UTF-16 `wm3\0`.

Raw search results:

- UTF-16 `WM2\0` (`57 00 4d 00 32 00 00 00`) occurs once, at raw `0x21d448` / VA `0x0061ea48`.
- UTF-16 `WM2` without explicit terminator also occurs once at the same VA.
- ANSI `WM2\0` occurs zero times.
- Absolute VA `0x0061ea48` occurs twice, at `.text` VAs `0x00512264` and `0x005c521a`, the immediate operands of the two IDA instructions.
- Absolute interior `0x0061ea4c` occurs zero times.
- Absolute successor `0x0061ea50` occurs once, at `.text` VA `0x005122a4`, matching the successor `wm3` sibling reference.
- RVA forms `0x0021ea48`, `0x0021ea4c`, and `0x0021ea50` occur zero times.
- `B9 48 EA 61 00` occurs once at `0x00512263`.
- `68 48 EA 61 00` occurs once at `0x005c5219`.

This raw check supports the exact target range, unique literal bytes, two source-use routes, and no hidden duplicate literal or alternate pointer route.

## Owner And Emitter Analysis

`CANONICAL_OWNER:NONE` remains correct.

- MapPane is not a canonical owner: it has a real reference at `0x00512263`, and its adjacent sibling strings are MapPane-owned, but WorldMapPane has an independent material reference at `0x005c5219`.
- WorldMapPane is not a canonical owner: it has a real reference inside `sub_5C5200`, but the MapPane packet/world-map creation path also uses the same pooled literal.
- The physical parent island `0x0061ea24-0x0061ea70` is not a canonical owner: it is a split/index container, not a source-level declaration unit.
- A standalone shared constants/global owner is not justified: IDA and raw PE evidence show a compiler-pooled string literal, not a named global object or separate source module.
- Class ownership is not justified: neither `MapPane` nor `WorldMapPane` proves a static member declaration; both are source-use consumers.

`EMITTER_UIDS:0000L3,0000PB` remains correct.

- `0000L3` is required because `sub_511DB0` is MapPane packet/world-map creation code, and [UID:0000L3][MapPane](../../../../../../by-file/MapPane.md) is the `NexusTK/map/MapPane.cpp` root.
- `0000PB` is required because `sub_5C5200` is WorldMapPane special-region hit-test/helper code, and [UID:0000PB][WorldMapPane](../../../../../../by-file/WorldMapPane.md) is the `NexusTK/map/WorldMapPane.cpp` root.
- No additional emitter is justified. `sub_5845B0` receives the string pointer but is a callee utility, not a source-use file owner for this literal. The parent split index and class pages are not needed as emitters because the current file-root emitters already surface to generated source roots without a dead-end.
- No emitter should be removed. Removing either `0000L3` or `0000PB` would drop a proven source-use route.

## Split, Merge, Reclassify, Rename Analysis

- No split: the range is one complete UTF-16 `WM2\0` literal. IDA and raw PE both show no reference to `0x0061ea4c`, and the bytes have no separately referenced interior element.
- No merge with predecessor: `0x0061ea30-0x0061ea48` is MapPane-only and ends before this shared upper `WM2` literal.
- No merge with successor: `0x0061ea50-0x0061ea70` is MapPane-only, starting with `wm3`, and has a separate xref at `0x005122a3`.
- No merge with `.PAL`: `.PAL` has a different shared-use pattern through `sub_510960` and WorldMapPane construction, and is already an exact sibling page.
- No reclassification: this is not compiler/runtime-only data, padding, or resource-derived data. It is a source-declared/generated-binary string literal required by source behavior.
- No IDA-safe rename repair is needed. IDA's `aWm2_0` is mechanically adequate for the literal, and the documentation name `SharedWorldMap2UpperString` accurately distinguishes it from MapPane-only lower/upper string groups.

## Failed Hypotheses

- Assign to `MapPane`: rejected because fresh xrefs and raw pointer scans prove a separate WorldMapPane source-use at `0x005c5219`.
- Assign to `WorldMapPane`: rejected because fresh xrefs and raw pointer scans prove a MapPane source-use at `0x00512263`, and surrounding MapPane-only comparison strings remain distinct siblings.
- Assign to a shared constants file/global: rejected because no source-level named object, global data xref pattern, or separate module evidence exists; this is best explained as pooled literal storage.
- Collapse into parent `MapWorldPaletteResourceStrings`: rejected because the parent is a non-emitting split index and would mix shared and MapPane-only ownership.
- Reclassify non-reconstructable: rejected because source-level `L"WM2"` uses are required to reproduce behavior, even if the exact pooled storage is linker/compiler output.
- Add final C++ now: rejected because a standalone declaration would invent an owner/source shape. Future method rewrites should use `L"WM2"` at the proven use sites.

## Required Edits

None.

If the supervisor wants an explicit tracker close-out row, use:

```text
| `0003JI` | 0x0061ea48-0x0061ea50.SharedWorldMap2UpperString | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | Agent-B001 | 2026-06-14 | complete-no-change | `Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString-fresh-no-owner-pass.md` | `Agent-B002/research/executed/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md` |
```

No `by-memory/-coverage-report.md` replacement, insertion, or deletion is needed.

## Validation And Lease State

- Changed files: `tools/leaser/Agents/Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString-fresh-no-owner-pass.md` (created first at the requested root path, then moved to `executed` by the B-agent workflow)
- Leases: none acquired; this pass created only an Agent-B001 research file, and no shared by-* documentation was edited.
- Validator: not run because no by-* documentation, metadata, generated output, or coverage report was edited.
- Dry runs: none used.

## Confidence

Recommendation confidence: high.

The current `87/93` target score remains defensible. The evidence includes fresh live IDA MCP function lookup, string/byte checks, xrefs, instruction queries, component analysis, WorldMapPane decompilation, raw PE byte/pointer scans, and current documentation route checks. The remaining uncertainty is not about the bytes or emitters; it is only the usual source-shape uncertainty for pooled literals, which is exactly why `CANONICAL_OWNER:NONE` is the conservative current owner state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B001/0003JI-SharedWorldMap2UpperString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
