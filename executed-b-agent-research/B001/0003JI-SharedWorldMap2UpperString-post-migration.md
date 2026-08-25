** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Post-Migration Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003JI] `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` at `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, score `87/93`, blank reconstruction C++, and blank `EMITTER_POSITION_OPTIONAL`, but change `EMITTER_UIDS` from blank to `0000L3,0000PB`.
- Final disposition: this is still a pooled/shared UTF-16 `WM2` literal with no defensible single declaration owner. It should no longer remain non-emitting under the split owner/emitter model because live IDA MCP and raw PE evidence prove two material source-use file roots: [UID:0000L3][MapPane](by-file/MapPane.md) and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md).
- Required action: supervisor should update the target header `EMITTER_UIDS` to `0000L3,0000PB`, optionally refresh the target narrative to describe emitter routing, replace the `by-memory/-coverage-report.md` row text shown below, then regenerate generated reports through the normal validator/autogen flow. Do not hand-edit `auto-generated/-ag-memory-coverage.md`.
- Confidence: `95/100` for bytes, exact range, xrefs, and no-split state; `91/100` for `CANONICAL_OWNER:NONE` with the two-emitter route. Remaining uncertainty is only original source declaration form, not binary use or source-use routing.

## Supporting Research

## Target

- Target UID: `0003JI`
- Target path: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current `no-owner` row with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003JI`, assigned to Agent-B001 as `B001-0003JI-post-migration`.
- Previous report: `tools/leaser/Agents/Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString.md`.
- Current metadata: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.

## Executive Recommendation

The old no-owner conclusion remains correct for canonical ownership, but the old blank-emitter conclusion is stale after the owner/emitter split migration.

The page documents exactly one physical `.rdata` literal: UTF-16LE `WM2` plus terminator at `0x0061ea48-0x0061ea50`. IDA reports exactly two direct refs to that address:

| Emitter route | Proven source-use site | Why this route clears |
| --- | --- | --- |
| [UID:0000L3][MapPane](by-file/MapPane.md) | `0x00512263` in `sub_511DB0` | `sub_511DB0` is the MapPane world-map object-create/packet helper. It compares map/world-map name strings including `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`, then constructs or attaches the `WorldMapPane`. The MapPane file root is `89/85` and already owns the adjacent MapPane-only `WM*` children. |
| [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) | `0x005c5219` in `sub_5C5200` | `sub_5C5200` is reached from WorldMapPane internal helper `sub_5C48B0`, itself called by WorldMapPane draw/input code. It calls `sub_5845B0(L"WM2")` and uses WorldMapPane layout globals for special-region/hit-test behavior. The WorldMapPane file root is `90/86` and documents a separate `map/WorldMapPane.cpp` module. |

Use the file roots as emitters rather than the narrower classes [UID:00007Q][MapPane](by-class/MapPane.md) and [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md). This is a compiler/linker-pooled literal with no proven semantic declaration owner, so emitter routing should record the final source-use file contexts instead of inventing a class static or standalone global.

## Supervisor Active Recheck

- Supervisor instruction: perform a post-migration owner/emitter recheck for the pooled/shared `WM2` literal and specifically test whether one or more emitters are justified even if `CANONICAL_OWNER:NONE` remains correct.
- Split repair required: no. The target is already the exact child `0x0061ea48-0x0061ea50`; IDA confirms `0x0061ea4c` has no interior/tail xrefs, the predecessor `wm2` at `0x0061ea40` has a separate MapPane-only xref, and the successor `wm3` at `0x0061ea50` has a separate MapPane-only xref.
- Parent/source repair required before action: no. Both selected file emitters clear the `85/85` route gate.
- Coverage-report direct edit: not performed. Exact replacement text is included for supervisor application.
- Lease status: no shared by-* documentation files were edited during this pass; only this Agent-B001 research report was created in the assigned research folder.

## Inference Research Guidance Check

`by-structure.md` now separates `CANONICAL_OWNER` from `EMITTER_UIDS`. It permits `CANONICAL_OWNER:NONE` with multiple emitters for pooled string literals when no single declaration owner is proven but source-use contexts are proven. That rule applies directly here.

`inference_research.md` warns that `.rdata` adjacency is weak evidence, especially around string pooling and merged constants. The report therefore treats neighboring `.PAL`, `wm`, `WM`, `wm2`, `wm3`, `WM3`, `wm4`, and `WM4` literals as split-boundary context, not as ownership proof for `WM2`. Direct xrefs and consumer file roots drive the emitter recommendation.

Facts, documentation evidence, and inference are separated as follows:

- IDA facts: bytes, decoded string, exact xrefs, containing functions, no interior/tail refs, and WorldMapPane helper call chain.
- Raw PE facts: full target object occurs once; target VA occurs only as the two direct code immediates; interior/tail/RVA pointer scans are negative.
- Documentation evidence: target page, previous executed B001 report, no-owner tracker, current file/class pages, sibling split pages, current `auto-generated/-ag-memory-coverage.md`, and current `by-memory/-coverage-report.md`.
- Inference: the physical literal is compiler/linker-pooled or otherwise shared source literal data with no defensible single canonical declaration owner, but both observed consumer source roots should receive emitter routes.

## Evidence Standards Used

- IDA MCP session: `b001_0003gy`, active worker for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA tools used: `idb_list`, `server_health`, `get_bytes`, `get_string`, `entity_query`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `search_text`, and `decompile`.
- Raw PE checks: PowerShell byte scan of `NexusTK.exe` for exact target bytes, absolute VA dwords for target/interior/successor addresses, and RVA dwords.
- Documentation checks: target page, prior executed B001 report, no-owner tracker, `by-structure.md`, `inference_research.md`, MapPane and WorldMapPane file/class pages, split-index/sibling literal pages, current `auto-generated/-ag-memory-coverage.md`, and current `by-memory/-coverage-report.md`.

## IDA MCP Facts

Function/range facts:

- `server_health` reported module `NexusTK.exe`, IDB `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs 0x0061ea48` returns `Not a function`.
- `lookup_funcs 0x00512263` returns `sub_511DB0`, size `0xa8a`.
- `lookup_funcs 0x005c5219` returns `sub_5C5200`, size `0x1d0`.
- `lookup_funcs 0x005c48b0` returns `sub_5C48B0`, size `0x320`.
- `lookup_funcs 0x005c3950` returns `sub_5C3950`, size `0x4f1`.

Data/string facts:

- `get_bytes 0x0061ea48 size 8` returns `57 00 4d 00 32 00 00 00`.
- `get_string 0x0061ea48` decodes `WM2`.
- Neighboring decoded strings in the split index are:

| Address | IDA decoded string | Current split meaning |
| --- | --- | --- |
| `0x0061ea24` | `.PAL` | Shared palette suffix child [UID:0003JG]. |
| `0x0061ea30` | `wm` | MapPane-owned comparison child [UID:0003JH]. |
| `0x0061ea38` | `WM` | MapPane-owned comparison child [UID:0003JH]. |
| `0x0061ea40` | `wm2` | MapPane-owned comparison child [UID:0003JH]. |
| `0x0061ea48` | `WM2` | Current shared target [UID:0003JI]. |
| `0x0061ea50` | `wm3` | MapPane-owned comparison child [UID:0003JJ]. |
| `0x0061ea58` | `WM3` | MapPane-owned comparison child [UID:0003JJ]. |
| `0x0061ea60` | `wm4` | MapPane-owned comparison child [UID:0003JJ]. |
| `0x0061ea68` | `WM4` | MapPane-owned comparison child [UID:0003JJ]. |

Xref facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0061ea40` | one data ref at `0x00512223` in `sub_511DB0` | Lowercase `wm2` remains MapPane-only. |
| `0x0061ea48` | exactly two data refs | Current target is shared by MapPane and WorldMapPane code. |
| `0x00512263` | `mov ecx, offset aWm2_0 ; "WM2"` in `sub_511DB0` | MapPane world-map packet/name comparison source-use site. |
| `0x005c5219` | `push offset aWm2_0 ; "WM2"` in `sub_5C5200` | WorldMapPane special-region/hit-test helper source-use site. |
| `0x0061ea4c` | zero xrefs | No interior/tail pointer; no split required. |
| `0x0061ea50` | one data ref in `sub_511DB0` | Successor `wm3` remains MapPane-only. |

Behavior facts:

- `trace_data_flow backward 0x0061ea48` reports the data node `UTF-16LE "WM2"` and exactly the two code nodes `0x00512263` and `0x005c5219`.
- `search_text` in `sub_511DB0` finds the target at `0x00512263`; searching `WM2` in the same range also finds the adjacent lowercase `wm2` use at `0x00512223`.
- `search_text` in `sub_5C5200` finds the target at `0x005c5219`.
- `analyze_component` reports the internal WorldMapPane call graph `sub_5C3950 -> sub_5C48B0 -> sub_5C5200`; `sub_5C5200` is not an unrelated shared utility.
- `decompile 0x00511db0` shows `sub_511DB0` decoding a packet string to a wide string, comparing it against `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`, then constructing/attaching the world-map pane through `sub_5C2AC0`.
- `decompile 0x005c5200` shows `sub_5C5200` calling `sub_5845B0(L"WM2")` and using WorldMapPane layout globals such as `word_66DA94`, `byte_66DA97`, and `word_66DA98` for branch-dependent region/hit-test calculations.
- `decompile 0x005c48b0` shows `sub_5C48B0` calling `sub_5C5200((float *)this, a2, a3)` and using the return value to drive WorldMapPane behavior.

Negative IDA facts:

- No vtable, constructor, initializer, table, RTTI item, global object, or helper function owns `0x0061ea48`.
- No IDA evidence ties the MapPane and WorldMapPane references through a modeled shared constants source file or named global declaration.
- No xrefs to `0x0061ea4c` justify widening, splitting, or creating a tail child.
- No xrefs outside `sub_511DB0` and `sub_5C5200` justify additional emitters.

## Raw PE Facts

PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found:

| Pattern | Result | Meaning |
| --- | --- | --- |
| Full target bytes `57 00 4d 00 32 00 00 00` | one hit at file offset `0x21D448` | The exact target object is unique in the PE image. |
| Absolute VA `0x0061ea48` little-endian | two hits at file offsets `0x111664` and `0x1C461A` | Immediate operand bytes for the two IDA refs. |
| Absolute VA `0x0061ea4c` little-endian | zero hits | No hidden interior/tail pointer. |
| Absolute VA `0x0061ea50` little-endian | one hit at file offset `0x1116A4` | Separate successor `wm3` pointer in the MapPane comparison ladder. |
| RVA `0x0021ea48`, `0x0021ea4c`, and `0x0021ea50` little-endian | zero hits | No RVA-form table/pointer owner found. |

Command/result summary:

```text
UTF16_WM2_NUL count=1
  file+0x21D448
VA_0061EA48_LE count=2
  file+0x111664
  file+0x1C461A
VA_0061EA4C_LE count=0
VA_0061EA50_LE count=1
  file+0x1116A4
RVA_0021EA48_LE count=0
RVA_0021EA4C_LE count=0
RVA_0021EA50_LE count=0
```

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Canonical Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea70` | [UID:0003IX][MapWorldPaletteResourceStrings](by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) | Mixed `.PAL` and `WM*` split index | `FALSE` | `NONE` | blank | `90/93` | Keep non-emitting split index. |
| `0x0061ea24-0x0061ea30` | [UID:0003JG][SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | Shared `.PAL` suffix string | `TRUE` | `NONE` | blank currently | `87/93` | Separate sibling; not part of this assignment. |
| `0x0061ea30-0x0061ea48` | [UID:0003JH][MapPaneWorldMapNameComparisonStrings](by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) | MapPane-only `wm`, `WM`, `wm2` strings | `TRUE` | `0000L3` | `0000L3` | `88/93` | Separate predecessor, no merge. |
| `0x0061ea48-0x0061ea50` | [UID:0003JI][SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | Shared uppercase `WM2` string | `TRUE` | `NONE` | recommend `0000L3,0000PB` | `87/93` | Current target. |
| `0x0061ea50-0x0061ea70` | [UID:0003JJ][MapPaneWorldMapNameThreeFourStrings](by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) | MapPane-only `wm3`, `WM3`, `wm4`, `WM4` strings | `TRUE` | `0000L3` | `0000L3` | `88/93` | Separate successor, no merge. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003JI] documents the exact range, UTF-16 `WM2`, two direct xrefs, and the old parent-blank conclusion. Live IDA confirms the core binary facts.
- Previous report `0003JI-SharedWorldMap2UpperString.md` correctly rejected a single canonical parent, but it predates applying the current emitter model to this item.
- [UID:0000L3][MapPane](by-file/MapPane.md) is `89/85`, proposes `NexusTK/map/MapPane.cpp`, documents the MapPane world-map packet/helper surface, and explicitly keeps WorldMapPane as a separate file. It already owns the adjacent MapPane-only `WM*` children [UID:0003JH] and [UID:0003JJ].
- [UID:00007Q][MapPane](by-class/MapPane.md) is `85/85`, routes through [UID:0000L3], and documents that MapPane triggers WorldMapPane creation from packet handling.
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) is `90/86`, proposes `NexusTK/map/WorldMapPane.cpp`, and documents WorldMapPane as a separate world-map/travel UI module rather than a continuation of `MapPane.cpp`.
- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) is `86/88`, routes through [UID:0000PB], and documents the class's rendering, hit-test, navigation, and travel responsibilities.
- [UID:0001O4][WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) connects the executable range containing `sub_5C5200` to the WorldMapPane source file and says MapPane creates it but should not own the implementation.
- Current post-migration pooled-literal precedents, including accepted B001 reports for shared downloader/user-agent and JSON/version-key literals, use `CANONICAL_OWNER:NONE` with multiple file-root emitters for comparable shared literal cases.

Existing docs that need migration/update:

- [UID:0003JI] still has blank `EMITTER_UIDS`; this is now incomplete for a proven pooled literal with two source-use routes.
- `by-memory/-coverage-report.md` still says only that the parent is blank; it should be updated to record the now-justified emitter routes.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003JI` as no-owner with blank emitters. This should be regenerated after metadata changes, not edited by hand.

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000PB`

Evidence for:

- This exactly matches the current by-structure rule for pooled literals with no proven declaration owner but multiple proven source-use contexts.
- IDA confirms one physical `WM2` literal used by exactly two separate source file roots.
- Raw PE scan finds no hidden pointer table, RVA reference, alignment-tail reference, or declaration object.
- Both file roots clear `85/85`.
- Comparable accepted pages use file-root emitter lists while keeping canonical owner `NONE`.

Evidence against:

- Original source may have repeated the same literal twice and linker pooling merged them, or used a macro/header constant. The stripped binary does not distinguish those forms.

Decision: accepted. This item should be no-owner, but not non-emitting.

### 2. [UID:0000L3] MapPane as canonical owner

Evidence for:

- One direct ref is in `sub_511DB0`, the MapPane packet/name comparison helper.
- Neighboring lowercase/uppercase world-map comparison strings are MapPane-only and already route to [UID:0000L3].
- MapPane creates or triggers WorldMapPane from packet handling.

Evidence against:

- `WM2` has a second direct ref in WorldMapPane helper `sub_5C5200`, not just in MapPane packet dispatch.
- Existing MapPane docs explicitly say WorldMapPane is a separate source file and should not be merged into `MapPane.cpp`.
- Canonical MapPane ownership would overclaim a literal materially used by WorldMapPane implementation code.

Decision: reject as canonical owner; accept [UID:0000L3] as one emitter.

### 3. [UID:0000PB] WorldMapPane as canonical owner

Evidence for:

- One direct ref is in `sub_5C5200`, reached from WorldMapPane internal helper `sub_5C48B0`.
- The target literal's name `WM2` is semantically tied to world-map special handling.
- WorldMapPane owns the implementation range containing `sub_5C5200`.

Evidence against:

- MapPane has an independent direct ref in `sub_511DB0` for packet/name comparison and construction routing.
- The adjacent `wm`/`WM*` comparison ladder is mostly MapPane-owned, so promoting only this shared uppercase value to WorldMapPane canonical ownership would hide the MapPane source-use site.
- No binary evidence shows the string was declared by WorldMapPane and imported by MapPane.

Decision: reject as canonical owner; accept [UID:0000PB] as one emitter.

### 4. New shared constants owner, such as `WorldMapNameConstants`

Evidence for:

- The literal is shared by two source-use contexts and could have originated from a macro/header constant.

Evidence against:

- There is only one exact shared `WM2` value in this assignment, not a broader proven table or named shared constants cluster.
- IDA and PE evidence show direct immediate string references, not a named global object, initializer, pointer table, or helper API.
- Creating a new owner from one pooled literal would invent source structure and would not improve generated output routing beyond the two proven emitters.

Decision: reject for current action. Revisit only if future source/debug/map evidence or a broader shared constants cluster appears.

### 5. Keep blank `EMITTER_UIDS`

Evidence for:

- This matched the old combined parent model because no single parent could own every use.

Evidence against:

- The current model deliberately separates semantic ownership from output routing.
- Both source-use sites are direct, material, and route through file roots above the gate.
- Leaving the item non-emitting would drop a real literal from both reconstructed source-use contexts even though both routes are proven.

Decision: reject. Blank emitters are now stale for this item.

## Metadata Recommendation

Target header changes:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No score change is recommended:

- `COMPLETION:87`
- `CONFIDENCE:93`

No reconstruction C++ is recommended:

- Keep `RECONSTRUCTION_CPP CODE:[[[]]]`
- Reason: this is pooled literal data. The output route is through proven emitter file contexts, not through a standalone source declaration.

Optional target narrative update:

```text
- 2026-06-13 B001 post-migration recheck: retained `CANONICAL_OWNER:NONE` because the UTF-16 `WM2` literal is materially shared by MapPane `sub_511DB0` and WorldMapPane helper `sub_5C5200`, and no single declaration owner or modeled shared constants file is proven. Added emitter routing `EMITTER_UIDS:0000L3,0000PB` because the current owner/emitter model allows no-owner pooled literals to emit through every proven source-use file root.
```

## Coverage / Generated Report Recommendation

Do not directly edit `auto-generated/-ag-memory-coverage.md`. After the target header update and normal regeneration, its current row should move from blank emitters to the expected generated state with emitters `0000L3,0000PB`.

Replace the current `by-memory/-coverage-report.md` row under [UID:0003IX] `0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings`, between [UID:0003JH] and [UID:0003JJ], with:

```text
                - [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001-0003JI post-migration recheck keeps `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but recommends `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`).
```

Expected score/coverage effects:

- Reconstructable state: unchanged.
- No-owner count: unchanged.
- No-owner with blank emitters / non-emitting reconstructable count: decreases by one.
- No-owner with emitters count: increases by one.
- Multiple-emitter routed literal count: increases by one.

## Validation / Commands Performed

No validator dry runs were used. No by-* documentation file was edited in this pass, so no project validator was required for changed by-* files.

Commands/results recorded:

- `Test-Path 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003JI-SharedWorldMap2UpperString-post-migration.md'`
  - Result before report creation: `False`.
- `rg -n "UID:0003JI|CANONICAL_OWNER|EMITTER_UIDS|SharedWorldMap2UpperString|0x00512263|0x005c5219|WM2" "source-3/project-documentation/by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md"`
  - Result: target metadata is `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`; existing body records bytes and the two xrefs.
- `rg -n "0003JI|SharedWorldMap2UpperString" "source-3/project-documentation/auto-generated/-ag-memory-coverage.md" "source-3/project-documentation/by-memory/-coverage-report.md" "source-3/project-documentation/tools/leaser/Agents/no_owner_b-agent-tracker.md"`
  - Result: generated source row and no-owner detail rows show blank emitters; coverage-report row still says parent blank; tracker row assigns B001 post-migration recheck.
- `rg` checks on `by-file/MapPane.md`, `by-class/MapPane.md`, `by-file/WorldMapPane.md`, `by-class/WorldMapPane.md`, and `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`
  - Result: MapPane file root is [UID:0000L3] `89/85`; WorldMapPane file root is [UID:0000PB] `90/86`; both source roots are separately documented and above the route gate.
- PowerShell raw PE scan of `NexusTK.exe`
  - Result: exact target bytes occur once; target VA dword occurs twice; interior/tail and RVA-form scans are negative; successor pointer is separate and MapPane-only.

## Blockers

None. IDA MCP was available, the target split is exact, both emitter routes clear the gate, and no shared documentation file needed direct editing for this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B001/0003JI-SharedWorldMap2UpperString-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
