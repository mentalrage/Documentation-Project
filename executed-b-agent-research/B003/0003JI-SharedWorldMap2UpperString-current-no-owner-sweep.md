** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Current No-Owner Sweep

## Finalized Recommendation

- Keep [UID:0003JI] `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank reconstruction C++, score `87/93`.
- Required action: no owner change, no emitter change, no split, no merge, no reclassification, no IDA-safe name repair, and no shared-report replacement is required.
- Confidence: high for the no-owner/multi-emitter decision. Fresh IDA MCP and raw PE evidence prove one physical UTF-16 `WM2` literal with exactly two source-use routes, one through MapPane and one through WorldMapPane, and no direct declaration-owner evidence.

## Target And Scope

- Target UID: `0003JI`
- Target path: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Target range: `0x0061ea48-0x0061ea50`
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, canonical owner `NONE`, emitters `0000L3`,`0000PB`.
- Current tracker state: `tools/leaser/Agents/no_owner_b-agent-tracker.md` active 2026-06-14 no-owner sweep row assigns `0003JI` to Agent-B003.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString-current-goal2-pass.md`.
- Write restrictions followed: no by-* documentation and no coverage report were directly edited.

## Current Header State

```text
*** UID:0003JI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The current header is correct and should be preserved. The range is reconstructable string data, but the active `90/90+` code-entry gate is not met because completion is `87`, so C++ remains blank.

## Evidence Standards

- IDA MCP checks used: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_string`, `xrefs_to`, `find_bytes`, `search_text`, `trace_data_flow`, `decompile`, and `analyze_component`.
- Raw PE checks used: section mapping, target VA-to-raw mapping, exact byte scan, ASCII/UTF-16 duplicate scan, absolute VA operand scan, push/mov instruction-pattern scan, interior/successor operand scan, and RVA-pattern scan.
- Documentation checked: current target page, parent split-index page, adjacent children, MapPane and WorldMapPane by-file/class pages, MapPane packet-handler aggregate, WorldMapPane executable aggregate, generated coverage rows, shared coverage row, tracker, `by-structure.md`, and `inference_research.md`.
- Prior reports were treated as leads only. The recommendation is based on current documents plus fresh live IDA and raw PE evidence.

## By-Structure Rule Check

- `by-structure.md` separates semantic declaration ownership from generated-output routing. A shared literal may remain `CANONICAL_OWNER:NONE` while listing all proven file-root emitters.
- `by-structure.md` also says not to invent a shared constants/helper file just to avoid `NONE`.
- `inference_research.md` treats physical adjacency and pooled string placement as weak evidence without source/debug/object-file proof.
- Applying those rules here: MapPane and WorldMapPane each prove an emitter route, but neither proves sole declaration ownership.

## Live IDA Facts

- Active IDA session: `idb_list` reports session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Server state: `server_health` reports module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Function boundaries:
  - `0x00512263` and `0x00511db0` resolve to `sub_511DB0`, size `0xa8a`.
  - `0x005c5219` and `0x005c5200` resolve to `sub_5C5200`, size `0x1d0`.
  - `0x005c48b0` resolves to `sub_5C48B0`, size `0x320`.
  - `0x005c3950` resolves to `sub_5C3950`, size `0x4f1`.
  - `0x0061ea48`, `0x0061ea4c`, and `0x0061ea50` are not functions.
- Exact bytes:
  - `get_bytes 0x0061ea48 size 8` returns `57 00 4d 00 32 00 00 00`, the UTF-16LE `WM2` literal plus terminator.
  - Nearby bytes show the boundary sequence `wm2\0`, `WM2\0`, `wm3\0`.
- Strings:
  - `get_string 0x0061ea24` returns `.PAL`.
  - `get_string 0x0061ea30` returns `wm`.
  - `get_string 0x0061ea38` returns `WM`.
  - `get_string 0x0061ea40` returns `wm2`.
  - `get_string 0x0061ea48` returns `WM2`.
  - `get_string 0x0061ea4c` returns the interior tail `2`.
  - `get_string 0x0061ea50` returns `wm3`.
  - `get_string 0x0061ea58` returns `WM3`.
  - `get_string 0x0061ea60` returns `wm4`.
  - `get_string 0x0061ea68` returns `WM4`.
  - `get_string 0x0061ea70` returns `%s\Mscfg.dll`.
- Direct xrefs:
  - `xrefs_to 0x0061ea48` reports exactly two data refs:
    - `0x00512263` in `sub_511DB0`.
    - `0x005c5219` in `sub_5C5200`.
  - `xrefs_to 0x0061ea4c` reports zero refs.
  - `xrefs_to 0x0061ea50` reports one data ref, `0x005122a3` in `sub_511DB0`, proving the successor is a separate MapPane-only child.
- Listing search:
  - `search_text aWm2_0` over `0x00511db0-0x00512840` returns `.text:00512263 mov ecx, offset aWm2_0 ; "WM2"` in `sub_511DB0`.
  - `search_text aWm2_0` over `0x005c5200-0x005c53d0` returns `.text:005C5219 push offset aWm2_0 ; "WM2"` in `sub_5C5200`.
- Hex-Rays:
  - `decompile 0x00511db0` shows `WideCharStr` comparison against `L"wm"`, `L"WM"`, `L"wm2"`, `L"WM2"`, `L"wm3"`, `L"WM3"`, `L"wm4"`, and `L"WM4"`, then the world-map construction path through `sub_5C2AC0`.
  - `decompile 0x005c5200` shows two WorldMapPane helper branches that call `sub_5845B0(L"WM2")`.
  - `decompile 0x005c48b0` shows `sub_5C48B0` calling `sub_5C5200((float *)this, a2, a3)`.
- Data flow/component:
  - `trace_data_flow backward 0x0061ea48` reports the data node `aWm2_0` with code users `sub_511DB0` at `0x512263` and `sub_5C5200` at `0x5c5219`.
  - `analyze_component` over `0x00511db0`, `0x005c5200`, `0x005c48b0`, and `0x005c3950` reports shared global `0x61ea48 aWm2_0` accessed by `sub_511DB0` and `sub_5C5200`.
  - The same component report gives the WorldMapPane internal call edge `0x005c3950 -> 0x005c48b0 -> 0x005c5200`, supporting `0000PB` as a real emitter route rather than a MapPane-only construction artifact.
- IDA byte search:
  - Pattern `48 EA 61 00` appears at `0x512264` and `0x5c521a`, the two target VA operands.
  - Pattern `B9 48 EA 61 00` appears once at `0x512263`, matching `mov ecx, offset aWm2_0`.
  - Pattern `68 48 EA 61 00` appears once at `0x5c5219`, matching `push offset aWm2_0`.
  - Pattern `4C EA 61 00` has zero hits, rejecting the interior-tail pointer.
  - Pattern `50 EA 61 00` appears once at `0x5122a4`, matching the successor `wm3` operand.
  - Pattern `48 EA 21 00` has zero hits, rejecting an RVA-form target pointer in IDA memory.
  - Exact bytes `57 00 4D 00 32 00 00 00` appear once at `0x61ea48`.
  - ASCII `57 4D 32 00` has zero hits.

## Raw PE Evidence

- Raw binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- PE imagebase: `0x00400000`.
- Relevant sections:
  - `.text`: VA `0x00401000`, RVA `0x00001000`, virtual size `0x20B4AC`, raw `0x400`, raw size `0x20B600`.
  - `.rdata`: VA `0x0060D000`, RVA `0x0020D000`, virtual size `0x5F0BE`, raw `0x20BA00`, raw size `0x5F200`.
  - `.data`: VA `0x0066D000`, RVA `0x0026D000`, virtual size `0x2FE24`, raw `0x26AC00`, raw size `0xD800`.
  - `.rsrc`: VA `0x0069D000`, RVA `0x0029D000`, virtual size `0x15C38`, raw `0x278400`, raw size `0x15E00`.
- Target mapping: VA `0x0061EA48` maps to raw `0x21D448` in `.rdata`.
- Target bytes at raw `0x21D448`: `57 00 4d 00 32 00 00 00`.
- Exact UTF-16 `WM2` with terminator occurs once: raw `0x21D448`, VA `0x0061EA48`.
- UTF-16 `WM2` without the final NUL also occurs once at the same location.
- ASCII `WM2\0` does not occur.
- Absolute VA immediate `0x0061EA48` occurs exactly twice:
  - raw `0x111664`, VA `0x00512264`, operand inside the `0x00512263` instruction.
  - raw `0x1C461A`, VA `0x005C521A`, operand inside the `0x005C5219` instruction.
- Pattern `push 0x0061EA48` occurs once: raw `0x1C4619`, VA `0x005C5219`.
- Pattern `mov ecx, 0x0061EA48` occurs once: raw `0x111663`, VA `0x00512263`.
- Absolute VA immediate `0x0061EA4C` does not occur.
- Absolute VA immediate `0x0061EA50` occurs once: raw `0x1116A4`, VA `0x005122A4`, the successor `wm3` operand.
- RVA dwords for target `0x0021EA48`, interior `0x0021EA4C`, and successor `0x0021EA50` do not occur.
- Boundary bytes at `0x0061EA40-0x0061EA58` are `77 00 6d 00 32 00 00 00 57 00 4d 00 32 00 00 00 77 00 6d 00 33 00 00 00`, confirming an exact `wm2`, `WM2`, `wm3` boundary.

## Function And Child Inventory

| Range / item | UID / path | Role | Current owner/emitter state | Decision |
| --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea70` | `0003IX` / `MapWorldPaletteResourceStrings` | Non-emitting split index for `.PAL` and `WM*` literals | `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE` | Keep as split index |
| `0x0061ea24-0x0061ea30` | `0003JG` / `SharedMapPaletteSuffixString` | UTF-16 `.PAL` suffix shared by MapPane and WorldMapPane | `NONE`, emitters `0000L3,0000PB` | Similar shared-literal precedent, not a merge target |
| `0x0061ea30-0x0061ea48` | `0003JH` / `MapPaneWorldMapNameComparisonStrings` | UTF-16 `wm`, `WM`, `wm2` | owner/emitter `0000L3` | Keep as MapPane-only predecessor |
| `0x0061ea48-0x0061ea50` | `0003JI` / `SharedWorldMap2UpperString` | UTF-16 `WM2` | `NONE`, emitters `0000L3,0000PB` | Current target, keep unchanged |
| `0x0061ea50-0x0061ea70` | `0003JJ` / `MapPaneWorldMapNameThreeFourStrings` | UTF-16 `wm3`, `WM3`, `wm4`, `WM4` | owner/emitter `0000L3` | Keep as MapPane-only successor |
| `0x00511db0` | `sub_511DB0` in MapPane packet/object world-map helper context | Direct `WM2` consumer | route to `0000L3` | Proven emitter |
| `0x005c5200` | `sub_5C5200` in WorldMapPane helper chain | Direct `WM2` consumer | route to `0000PB` | Proven emitter |

## Xrefs And Callers

| Address / edge | Evidence | Ownership meaning |
| --- | --- | --- |
| `0x00512263 -> 0x0061ea48` | `mov ecx, offset aWm2_0 ; "WM2"` in `sub_511DB0` | Proves MapPane source-use output route `0000L3` |
| `0x005c5219 -> 0x0061ea48` | `push offset aWm2_0 ; "WM2"` in `sub_5C5200` | Proves WorldMapPane source-use output route `0000PB` |
| `0x005c3950 -> 0x005c48b0 -> 0x005c5200` | IDA component call graph | Supports that the `sub_5C5200` use belongs to the WorldMapPane implementation path |
| `0x0061ea4c` | zero IDA xrefs and zero raw operands | Rejects interior-tail child split |
| `0x005122a3 -> 0x0061ea50` | successor `wm3` ref in `sub_511DB0` | Keeps successor in MapPane-only child `0003JJ` |

## Related Documentation Checked

- Target page `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` already records the exact bytes, decoded string, two direct refs, `CANONICAL_OWNER:NONE`, and emitters `0000L3,0000PB`.
- Parent page `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` is correctly modeled as a mixed, non-emitting split index.
- Sibling pages `0003JH` and `0003JJ` document the adjacent MapPane-only strings; current xrefs support that separation.
- `by-file/MapPane.md` and the MapPane packet-handler memory aggregate document `sub_511DB0` in the MapPane source-use route.
- `by-file/WorldMapPane.md`, `by-class/WorldMapPane.md`, and the WorldMapPane memory aggregate document `sub_5C5200` in the separate WorldMapPane route.
- `auto-generated/-ag-memory-coverage.md` current rows match the target state.
- `by-memory/-coverage-report.md` current row matches the target state.

## Alternatives Rejected

### Assign `0000L3` / MapPane As Canonical Owner

- Evidence for: `sub_511DB0` directly references the literal, and most adjacent `WM*` comparison strings are MapPane-only.
- Evidence against: `sub_5C5200` directly references the same physical literal inside the WorldMapPane helper chain. No source/debug/object-file data proves MapPane declared the literal, and adjacency is weak source-ownership evidence for pooled strings.
- Decision: reject as canonical owner; keep `0000L3` as an emitter.

### Assign `0000PB` / WorldMapPane As Canonical Owner

- Evidence for: `sub_5C5200` directly uses `L"WM2"`, and IDA component analysis places it under the WorldMapPane internal helper path.
- Evidence against: `sub_511DB0` also directly uses the same physical literal. WorldMapPane does not own the surrounding MapPane-only comparison strings, and no declaration-site evidence points to WorldMapPane.
- Decision: reject as canonical owner; keep `0000PB` as an emitter.

### Assign The Parent Split Index `0003IX`

- Evidence for: the target is physically within the `0x0061ea24-0x0061ea70` range.
- Evidence against: `0003IX` is intentionally `RECONSTRUCTABLE:FALSE` and non-emitting. It is a documentation split index, not a source declaration owner.
- Decision: reject.

### Create A Shared Constants Owner

- Evidence for: a named shared constant or header-level literal is possible in original source.
- Evidence against: there is no PDB/source path, linker map, initializer, pointer table, named global object, object-file boundary, or broader shared-constant cluster. Creating a new owner would only hide the unresolved declaration placement.
- Decision: reject.

### Split, Merge, Or Reclassify

- Split evidence considered: `get_string 0x0061ea4c` decodes the interior tail `2`.
- Split evidence rejected: no IDA xrefs, raw absolute operands, or raw RVA operands target `0x0061ea4c`.
- Merge evidence considered: the target is physically contiguous with other `.PAL` and `WM*` literals.
- Merge evidence rejected: the neighboring children have different ownership and emitter routes, so merging would reduce accuracy.
- Reclassification evidence considered: shared literals can be non-owned.
- Reclassification evidence rejected: the literal has exact bytes and proven source-use routes, so it remains reconstructable string data rather than padding/index/runtime-only data.
- Decision: no split, merge, or reclassification.

## Negative Evidence Summary

- No IDA or raw PE evidence for a single declaration owner.
- No second UTF-16 `WM2` object.
- No ASCII `WM2\0` object.
- No interior-tail ref to `0x0061ea4c`.
- No RVA-form pointer to `0x0021ea48`.
- No hidden third direct user in IDA or raw PE absolute-immediate scan.
- No table/global/initializer/RTTI/source-name evidence that can own the literal.
- No reason to rename IDA symbols for this pass; `aWm2_0` is a generated string label but the documentation name already gives the source-level meaning.

## Final Recommendation

- Preserve target metadata exactly:
  - `COMPLETION:87`
  - `CONFIDENCE:93`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000L3,0000PB`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank `RECONSTRUCTION_CPP`
- Preserve emitter routing:
  - `0000L3` / `MapPane`, proven by direct `sub_511DB0` use at `0x00512263`.
  - `0000PB` / `WorldMapPane`, proven by direct `sub_5C5200` use at `0x005c5219`.
- Leave canonical owner as `NONE` because neither consumer proves original declaration ownership.
- No future repair is required unless new source/debug/linker-map evidence identifies a real declaration site.

## Shared Report / Coverage Text

No direct edit to `by-memory/-coverage-report.md` is allowed or needed. If the supervisor wants exact retained text for comparison, keep the current row:

```markdown
                - [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`); B002 reconfirmed no interior-tail refs, no split/merge/reclassification, and no duplicate source object.
```

No manual edit to `auto-generated/-ag-memory-coverage.md` is allowed or needed. Current generated rows are correct:

```markdown
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

## Validation

- Validator commands run: none.
- Reason: no by-* docs, generated reports, project-level docs, or shared coverage reports were edited. This pass created only an Agent-B003 research report.
- No dry runs were used.
- Unresolved validation issues introduced by this pass: none.

## Lease State

- No lease was acquired. `goal.md` states no lease is needed to create or update research reports inside `Agent-B003/research`, and this pass made no edits outside that folder.
- Final lease state: no B003 lease to release for this target.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003JI-SharedWorldMap2UpperString-current-no-owner-sweep.md`.
- Modified: none outside the newly created B003 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B003/0003JI-SharedWorldMap2UpperString-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
