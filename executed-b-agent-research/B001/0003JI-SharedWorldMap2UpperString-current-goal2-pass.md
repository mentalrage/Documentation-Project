** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Current Goal 2 Ownership / Emitter Recheck

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003JI] `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank reconstruction C++, score `87/93`.
- Required action: no canonical-owner change, no emitter change, no split, no merge, no reclassification, no score change, and no coverage-report replacement is required.
- Confidence: high. Fresh IDA MCP and raw PE evidence prove exactly two source-use contexts, no interior/tail refs, no duplicate source object, and no single declaration owner.

## Supporting Research

## Target
- Target UID: `0003JI`
- Target path: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Source queue/report row: current no-owner memory item from `auto-generated/-ag-memory-coverage.md`, generated as `no-owner` with canonical owner `NONE` and emitters `0000L3`,`0000PB`.
- Current supervisor classification: `tools/leaser/Agents/no_owner_b-agent-tracker.md` lists `0003JI` assigned to Agent-B001 as a current pass, with B002 second-pass history as background.
- Current scores and parent state: target page currently records `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.

## Executive Recommendation
- Keep the item as a reconstructable shared UTF-16 string literal with no canonical owner and two proven file-root emitters.
- The exact range is one UTF-16 `WM2` literal at `0x0061ea48-0x0061ea50`. It is shared by the MapPane world-map packet/object helper and a WorldMapPane special-region/helper path.
- Assigning the literal to either `MapPane`, `WorldMapPane`, the physical split index, or a new shared constants file would overclaim the evidence. The correct current model is no-owner but emitted through both proven source-use contexts.
- The only evidence that would change this recommendation would be source/debug/linker-map data proving a real original shared declaration owner or one source file as the declaration site.

## Supervisor Active Recheck
- Supervisor instruction: recheck [UID:0003JI] from current documentation and live IDA MCP evidence; decide whether `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000PB` remains correct or needs repair.
- Split repair: not required. The item is already exact and bounded by neighboring strings: `wm2` ends before `0x0061ea48`; successor `wm3` begins at `0x0061ea50`.
- Source-bearing children in scope: none need creation or repair. The mixed parent [UID:0003IX] is already a non-emitting split index, while siblings [UID:0003JH] and [UID:0003JJ] carry MapPane-only strings separately.

## Inference Research Guidance Check
- `by-structure.md` separates semantic ownership from generated-output routing. Shared literals may remain `CANONICAL_OWNER:NONE` while listing all proven source-use emitters.
- `inference_research.md` warns against adjacency-only ownership. I treated the surrounding MapPane-only string island as context, not ownership proof.
- Existing docs and the B002 report were used as leads only. The conclusion is based on fresh IDA MCP xrefs/decompilation, current related docs, generated coverage rows, and an independent raw PE scan.

## Evidence Standards Used
- IDA MCP evidence: `idb_list`, `server_health`, `lookup_funcs`, `get_string`, `get_bytes`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, `search_text`, `trace_data_flow`, `decompile`, and `analyze_component`.
- Raw PE evidence: MD5, section mapping, exact byte scan, ASCII/UTF-16 duplicate checks, absolute VA immediate scans, interior/successor scans, and RVA pattern scans.
- Documentation evidence: current target page, split-index and sibling pages, `MapPane` and `WorldMapPane` file/class docs, generated coverage rows, shared `by-memory/-coverage-report.md`, tracker rows, and the prior B002 report as background.
- The evidence is strong enough to keep the current no-owner/multi-emitter state because it proves the complete use set for the exact object while rejecting split/merge and single-owner alternatives.

## IDA MCP Facts
- Function/range facts:
  - `idb_list` shows active session `b001_0003gy` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - `server_health` reports module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` reports `0x0061ea48`, `0x0061ea4c`, and `0x0061ea50` are not functions.
  - `0x00511db0` and `0x00512263` resolve to `sub_511DB0`, size `0xa8a`.
  - `0x005c5200` and `0x005c5219` resolve to `sub_5C5200`, size `0x1d0`.
  - `0x005c48b0` resolves to `sub_5C48B0`, size `0x320`; `0x005c3950` resolves to `sub_5C3950`, size `0x4f1`.
- Data/string facts:
  - `get_bytes 0x0061ea48 size 8` returns `57 00 4d 00 32 00 00 00`, the UTF-16LE literal `WM2` plus terminator.
  - `get_string 0x0061ea48` returns `WM2`; `get_string 0x0061ea4c` returns interior tail `2`; `get_string 0x0061ea50` returns successor `wm3`.
  - `entity_query` over `0x0061ea20-0x0061ea74` reports names `aPal`, `aWm`, `aWm_0`, `aWm2`, `aWm2_0`, `aWm3`, `aWm3_0`, `aWm4`, `aWm4_0`, and `aSMscfgDll`.
  - `get_string` confirms the local island sequence `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4`, then `%s\\Mscfg.dll` at `0x0061ea70`.
- Xref facts:
  - `xrefs_to 0x0061ea48` reports exactly two data refs: `0x00512263` in `sub_511DB0` and `0x005c5219` in `sub_5C5200`.
  - `xrefs_to 0x0061ea4c` reports no cross-references.
  - `xrefs_to 0x0061ea50` reports one data ref at `0x005122a3` in `sub_511DB0`, proving the successor belongs to the MapPane-only child.
  - Neighbor xrefs confirm `wm`, `WM`, `wm2`, `wm3`, `WM3`, `wm4`, and `WM4` are MapPane-only through `sub_511DB0`, while this `WM2` child is the exception with a second WorldMapPane ref.
- Instruction/decompilation observations:
  - `search_text aWm2_0` in `0x00511db0-0x00512840` finds `0x00512263 sub_511DB0: mov ecx, offset aWm2_0 ; "WM2"`.
  - `search_text aWm2_0` in `0x005c5200-0x005c53d0` finds `0x005c5219 sub_5C5200: push offset aWm2_0 ; "WM2"`.
  - `trace_data_flow` backward from `0x0061ea48` reports the same two code users and no additional owner route.
  - `sub_511DB0` decompilation shows a parsed `WideCharStr` compared against `L"wm"`, `L"WM"`, `L"wm2"`, `L"WM2"`, `L"wm3"`, `L"WM3"`, `L"wm4"`, and `L"WM4"` before constructing/calling into WorldMapPane creation through `sub_5C2AC0`.
  - `sub_5C5200` decompilation shows `sub_5845B0(L"WM2")` in two special-region/hit-test branches, placing the second use in WorldMapPane helper logic.
  - `analyze_component` over `0x00511db0`, `0x005c5200`, `0x005c48b0`, and `0x005c3950` reports shared global `0x0061ea48 aWm2_0` accessed by `sub_511DB0` and `sub_5C5200`.
  - The same component analysis reports an internal call graph `0x005c3950 -> 0x005c48b0 -> 0x005c5200`, supporting the WorldMapPane emitter route independently of MapPane packet creation.
- Negative IDA facts:
  - No IDA xrefs to the interior tail at `0x0061ea4c`.
  - No IDA evidence for a standalone shared constants object, initializer, table, or debug/source owner.
  - No evidence that the non-emitting split index [UID:0003IX] is a source-level declaration owner.

## Raw PE Evidence
- Raw target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- PE imagebase: `0x00400000`.
- Section mapping used for raw scan:
  - `.text` VA `0x00401000`, raw `0x400`, raw size `0x20B600`.
  - `.rdata` VA `0x0060D000`, raw `0x20BA00`, raw size `0x5F200`.
  - `.data` VA `0x0066D000`, raw `0x26AC00`, raw size `0xD800`.
  - `.rsrc` VA `0x0069D000`, raw `0x278400`, raw size `0x15E00`.
- Exact UTF-16 bytes `57 00 4D 00 32 00 00 00` occur once at file offset `0x21D448`, VA `0x0061EA48`.
- UTF-16 `WM2` without the final NUL also occurs only once at file offset `0x21D448`, VA `0x0061EA48`.
- ASCII `WM2\0` does not occur.
- Absolute VA immediate `0x0061EA48` occurs exactly twice, at file offsets `0x111664` and `0x1C461A`, mapping to instruction operand VAs `0x00512264` and `0x005C521A`.
- Absolute VA immediate `0x0061EA4C` does not occur.
- Absolute VA immediate `0x0061EA50` occurs once, at file offset `0x1116A4`, VA `0x005122A4`, matching the successor `wm3` MapPane-only ref.
- RVA patterns for `0x0021EA48`, `0x0021EA4C`, and `0x0021EA50` do not occur.
- The raw bytes around `0x0061EA48` show the exact neighbor boundary: `wm2\0`, then `WM2\0`, then `wm3\0`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea70` | `0003IX` / `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` | Non-emitting split index for `.PAL` and `WM*` string island | No | `NONE` | `90/93` | Keep as split index |
| `0x0061ea24-0x0061ea30` | `0003JG` / `SharedMapPaletteSuffixString` | Shared UTF-16 `.PAL` suffix | Yes | `NONE`; emitters `0000L3,0000PB` | `87/93` | Similar shared-literal precedent |
| `0x0061ea30-0x0061ea48` | `0003JH` / `MapPaneWorldMapNameComparisonStrings` | UTF-16 `wm`, `WM`, `wm2` | Yes | `0000L3`; emitter `0000L3` | `88/93` | MapPane-only predecessor |
| `0x0061ea48-0x0061ea50` | `0003JI` / `SharedWorldMap2UpperString` | UTF-16 `WM2` | Yes | `NONE`; emitters `0000L3,0000PB` | `87/93` | Current target; keep unchanged |
| `0x0061ea50-0x0061ea70` | `0003JJ` / `MapPaneWorldMapNameThreeFourStrings` | UTF-16 `wm3`, `WM3`, `wm4`, `WM4` | Yes | `0000L3`; emitter `0000L3` | `88/93` | MapPane-only successor |
| `0x0050e4c0-0x00514920` | `0001AW` / `MapPanePacketHandlers` | MapPane packet-handler aggregate containing `sub_511DB0` | Yes | `00007Q` / `MapPane` class, file root `0000L3` | `85/88` | Supports emitter `0000L3` |
| `0x005c2ac0-0x005c5c87` | `0001O4` / `WorldMapPane` | WorldMapPane executable aggregate containing `sub_5C5200` helper chain | Yes | `0000PB` | `80/85` | Supports emitter `0000PB` through file/class docs |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00512263 -> 0x0061ea48` | `sub_511DB0`, MapPane packet/object/world-map helper | Proven MapPane source-use route; compare parsed wide map name with `L"WM2"` |
| `0x005c5219 -> 0x0061ea48` | `sub_5C5200`, WorldMapPane helper | Proven WorldMapPane source-use route; special-region/hit-test helper checks `L"WM2"` |
| `0x005c3950 -> 0x005c48b0 -> 0x005c5200` | Internal WorldMapPane component chain | Confirms `sub_5C5200` is not merely MapPane packet construction code |
| `0x0061ea4c` | no xrefs | Interior UTF-16 tail `2`, no split target |
| `0x005122a3 -> 0x0061ea50` | `sub_511DB0` | Successor `wm3` belongs to MapPane-only sibling, not this target |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page [UID:0003JI] already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`, bytes/string evidence, MapPane and WorldMapPane xrefs, and no split/merge need.
  - [UID:0003IX] documents the mixed `.PAL`/`WM*` string island as a non-emitting split index and identifies `0003JI` as the shared `WM2` child.
  - [UID:0003JH] and [UID:0003JJ] document the adjacent MapPane-only string groups; fresh xrefs confirm those pages.
  - [UID:0000L3] `by-file/MapPane.md` and [UID:00007Q] `by-class/MapPane.md` document `sub_511DB0` as MapPane packet/object/world-map handling and clear the strict emitter route gate.
  - [UID:0000PB] `by-file/WorldMapPane.md` and [UID:0000G9] `by-class/WorldMapPane.md` document WorldMapPane as a separate source module and clear the route gate for file-root emission.
  - [UID:0001AW] documents the MapPane packet-handler aggregate and `sub_511DB0`.
  - [UID:0001O4] documents the WorldMapPane executable aggregate and helper-family context.
- Existing docs that are stale, incomplete, or contradicted:
  - No current target/sibling/generated state is contradicted by the fresh checks.
  - Older parent-blank language in prior reports should be interpreted through the current owner/emitter split; the current page has already been updated.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` currently lists `0003JI` as `no-owner`, canonical owner `NONE`, emitters `0000L3`,`0000PB`, and includes it in the multiple-emitter table.
  - `by-memory/-coverage-report.md` currently records the same result with the direct MapPane and WorldMapPane xref evidence. No direct edit is allowed or needed.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with emitters `0000L3,0000PB`
- Evidence for:
  - One exact physical UTF-16 `WM2` object has two direct source-use refs in two separate source roots.
  - MapPane and WorldMapPane both clear the file-root route gate, and their docs show separate source-module responsibilities.
  - Raw PE scans reject hidden duplicate wide/ASCII copies, interior pointers, RVA tables, and third users.
  - by-structure rules explicitly allow no canonical owner with multiple emitters for pooled/shared literals.
- Evidence against:
  - The literal is physically embedded among mostly MapPane-owned `wm`/`WM*` comparison strings, which is a weak adjacency clue toward MapPane.
  - `sub_511DB0` constructs or calls into the WorldMapPane constructor path, so the source relationship is close.
- Decision: accepted. Adjacency and construction flow do not override the material independent WorldMapPane helper use.

### 2. Canonical owner `0000L3` / MapPane
- Evidence for:
  - `sub_511DB0` directly references the literal while comparing parsed wide map names.
  - Neighboring strings before and after the target are MapPane-only.
  - `MapPane.md` lists these resource/comparison strings as part of the MapPane resource-string split context.
- Evidence against:
  - `sub_5C5200` directly references the same physical object inside WorldMapPane helper logic.
  - The exact object has one MapPane ref and one WorldMapPane ref; MapPane does not have an owner-only xref pattern.
  - Physical adjacency is weak evidence in a pooled string island.
- Decision: reject as canonical owner; keep `0000L3` as an emitter.

### 3. Canonical owner `0000PB` / WorldMapPane
- Evidence for:
  - `sub_5C5200` directly references the target.
  - `analyze_component` places `sub_5C5200` under an internal WorldMapPane chain from `sub_5C3950` through `sub_5C48B0`.
  - `WorldMapPane.md` is a valid separate source file root.
- Evidence against:
  - `sub_511DB0` also directly references the same object in the MapPane packet/object helper.
  - Most neighboring `WM*` strings are MapPane-only, so WorldMapPane does not own the whole physical string island.
  - No constructor/static-data evidence proves the literal was declared in WorldMapPane source.
- Decision: reject as canonical owner; keep `0000PB` as an emitter.

### 4. Canonical owner `0003IX` split index
- Evidence for:
  - The target is physically inside the `0x0061ea24-0x0061ea70` split-index range.
- Evidence against:
  - `0003IX` is explicitly `RECONSTRUCTABLE:FALSE`, non-emitting, and mixed-owner.
  - Split indexes are documentation containers, not source declaration owners.
- Decision: reject.

### 5. New shared constants/source file
- Evidence for:
  - A shared literal could have come from a shared header or named constant in original source.
- Evidence against:
  - No PDB/source path, linker map, named global, initializer, string table, repeated shared-constant cluster, or object-file boundary proves such a file.
  - The surrounding island has mixed ownership: `.PAL` and `WM2` are shared, while the other `WM*` strings are MapPane-only.
  - by-structure rules warn against inventing a helper/global file solely to avoid `NONE`.
- Decision: reject.

### 6. Split, merge, or reclassify
- Evidence for:
  - `get_string 0x0061ea4c` decodes `2`, so a superficial string scan might suggest an interior string.
  - The target is part of a contiguous UTF-16 island, so a merge could look simpler.
- Evidence against:
  - IDA and raw PE find no xrefs or operands to `0x0061ea4c`.
  - Neighbor xrefs differ by ownership, so merging would hide the MapPane-only/shared boundary.
  - The target is a source-declared string literal with proven source-use contexts, so it remains reconstructable.
- Decision: reject split, merge, and non-reconstructable reclassification.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: no new source file is justified.
- Candidate related items that belong: none proven. Shared sibling [UID:0003JG] is a similar no-owner/multi-emitter literal, not proof of a constants file.
- Candidate related items rejected: [UID:0003JH] and [UID:0003JJ] are MapPane-only; [UID:0003IX] is a split index; WorldMapPane resource literals under [UID:00035I] are separate WorldMapPane-owned read-only data.
- Standalone, narrow, or broad source-file inference: reject new source file; keeping `NONE` is the more accurate inference.

## Negative Evidence Summary
- Checked target interior: no IDA xrefs or raw operands to `0x0061ea4c`.
- Checked duplicate literals: no second UTF-16 `WM2`, no ASCII `WM2\0`.
- Checked hidden pointer styles: no RVA patterns for target, interior, or successor.
- Checked successor: `0x0061ea50` is `wm3` with a MapPane-only xref, so it remains in [UID:0003JJ].
- Checked generated single path in `auto-generated/-ag-memory-coverage.md`: the path `auto-generated/NexusTK/map/MapPane.cpp` is a routing/report artifact for a multi-emitter item, not canonical ownership evidence.
- Checked candidate owners: each consumer proves an emitter route but does not prove declaration ownership.

## Final Recommendation
- Exact changes applied or recommended: no by-* metadata changes. Preserve:
  - `*** COMPLETION:87`
  - `*** CONFIDENCE:93`
  - `*** CANONICAL_OWNER:NONE`
  - `*** RECONSTRUCTABLE:TRUE`
  - `*** EMITTER_UIDS:0000L3,0000PB`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank `RECONSTRUCTION_CPP`
- Exact parent assignments applied or recommended: no canonical parent. Keep emitter routing to:
  - `0000L3` / `by-file/MapPane.md`, proven by `sub_511DB0` at `0x00512263`.
  - `0000PB` / `by-file/WorldMapPane.md`, proven by `sub_5C5200` at `0x005c5219`.
- Exact items left no-owner/non-emitting and why: `0003JI` remains no-owner but not non-emitting. It has two proven emitters and no proven single declaration owner.
- Exact future work outside this assignment scope: none, unless future source/debug/linker-map evidence recovers a real shared declaration owner.

## Shared Report / Coverage Text
- `by-memory/-coverage-report.md`: no replacement row is required. The current row is already correct and should be preserved:

```markdown
                - [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`); B002 reconfirmed no interior-tail refs, no split/merge/reclassification, and no duplicate source object.
```

- `auto-generated/-ag-memory-coverage.md`: no manual edit. Current generated rows are correct:

```markdown
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

## Follow-Up Actions
- Supervisor actions: no documentation repair is required. Move this report to `executed` after acceptance if following the normal workflow.
- A-agent actions: none for this target.
- B001 future research actions: none for `0003JI`.

## Confidence
- Recommendation confidence: high. Direct IDA and raw PE evidence agree with current docs and generated rows.
- Score confidence: keep `87/93`. The range, xrefs, and emitter routes are very strong, but original declaration placement remains unrecovered and completion is below the `90/90+` code-entry gate.
- Remaining uncertainty: only original source declaration ownership. Current binary evidence proves source-use contexts, not which translation unit first declared or pooled the literal.

## Validator Results
- Commands run: none.
- Results: not applicable. No by-* docs, generated reports, or shared coverage reports were edited, so validator `--apply` was not required. No dry runs were used.
- Any unresolved validator warnings/errors: none from this pass.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003JI-SharedWorldMap2UpperString-current-goal2-pass.md`
- Modified: none outside the B001 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B001/0003JI-SharedWorldMap2UpperString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
