** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003JI] `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Required action: no owner change, no emitter change, no score change, no split, no merge, no reclassification, no IDA-safe name repair, and no shared coverage-report replacement.
- Confidence: high. Current IDA MCP and raw PE evidence prove one physical UTF-16 `WM2` literal with exactly two source-use routes: MapPane `sub_511DB0` and WorldMapPane helper `sub_5C5200`. No evidence proves a single declaration owner.

This is a valid no-owner but emitting shared-literal case. It should not be treated as a non-emitting gap.

## Target

- Target UID: `0003JI`
- Target path: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Source row: current Goal 2 no-owner sweep in `auto-generated/-ag-memory-coverage.md`
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active row assigned to `Agent-B002` on 2026-06-14
- Current scores/state: `87/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`
- After this pass: unchanged `87/93`

## Executive Recommendation

Keep the current model: `CANONICAL_OWNER:NONE` with emitters `0000L3,0000PB`.

The item is a source-declared/generated-binary string literal. `MapPane` and `WorldMapPane` both have direct source-use evidence, so both are valid emitters. Neither use proves original declaration ownership. The best reconstruction guidance is to spell/use `L"WM2"` in the eventual MapPane and WorldMapPane consumer code unless later PDB/source/linker-map evidence proves a real named shared constant.

Code-entry gate: the item is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank emitters that route to valid generated file roots, and `(87 + 93) / 2 = 90 > 85`. That satisfies the minimum gate, but this report does not recommend entering standalone C++ for this data page because no standalone source declaration is proven.

## Supervisor Active Recheck

- Supervisor instruction: recheck whether current `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB` is still correct or whether owner/emitter/split/merge/reclass/repair is needed.
- Split repair required: no. The target is already the exact `WM2\0` child at `0x0061ea48-0x0061ea50`.
- By-* edits required: no.
- Shared report edit required: no.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from emitter routing and explicitly allows pooled/shared literals to keep `CANONICAL_OWNER:NONE` while listing multiple proven source-use emitters. `inference_research.md` treats adjacency and consumer xrefs as evidence, not declaration-owner proof by themselves.

Applied here: the MapPane use and WorldMapPane use both prove output routes. The lack of source/debug/object-file evidence, plus one physical pooled literal used by two separate source modules, blocks a single canonical-owner assignment.

## Evidence Standards Used

Evidence checked:

- Current target page and current generated `-ag-memory-coverage.md` rows.
- Current manual `by-memory/-coverage-report.md` row.
- Parent split-index page and neighboring child pages.
- Candidate owners [UID:0000L3] `by-file/MapPane.md` and [UID:0000PB] `by-file/WorldMapPane.md`.
- Live IDA MCP: server health, bytes, function lookup, xrefs, byte-pattern search, and decompilation.
- Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Prior reports from B001/B002/B003 were read as background only, not treated as authority.

## IDA MCP Facts

Current IDA session checked: database `b001_0002bd`, module `NexusTK.exe`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Function/range facts:

- `0x0061ea48`, `0x0061ea4c`, and `0x0061ea50` are not functions.
- `0x00512263` is inside `sub_511DB0`, function start `0x00511db0`, size `0xa8a`.
- `0x005c5219` is inside `sub_5C5200`, function start `0x005c5200`, size `0x1d0`.
- `0x005c48b0` is `sub_5C48B0`, size `0x320`, and calls `sub_5C5200`.
- `0x005c3950` is `sub_5C3950`, size `0x4f1`, and calls `sub_5C48B0`.

Byte facts:

```text
0x0061ea24:
2e 00 50 00 41 00 4c 00 00 00 00 00 77 00 6d 00
00 00 00 00 57 00 4d 00 00 00 00 00 77 00 6d 00
32 00 00 00 57 00 4d 00 32 00 00 00 77 00 6d 00
33 00 00 00 57 00 4d 00 33 00 00 00 77 00 6d 00
34 00 00 00 57 00 4d 00 34 00 00 00 ...

0x0061ea48:
57 00 4d 00 32 00 00 00
```

Direct xrefs:

```text
0x0061ea48:
  0x00512263 data ref in sub_511DB0
  0x005c5219 data ref in sub_5C5200
0x0061ea4c:
  no xrefs
0x0061ea50:
  0x005122a3 data ref in sub_511DB0
```

Neighbor string xrefs:

- `0x0061ea30` `wm`: one ref in `sub_511DB0`.
- `0x0061ea38` `WM`: one ref in `sub_511DB0`.
- `0x0061ea40` `wm2`: one ref in `sub_511DB0`.
- `0x0061ea50` `wm3`: one ref in `sub_511DB0`.
- `0x0061ea58` `WM3`: one ref in `sub_511DB0`.
- `0x0061ea60` `wm4`: one ref in `sub_511DB0`.
- `0x0061ea68` `WM4`: one ref in `sub_511DB0`.

IDA byte-pattern search:

- `57 00 4D 00 32 00 00 00`: one match at `0x0061ea48`.
- `57 00 4D 00 32 00`: one match at `0x0061ea48`.
- ASCII-style `57 4D 32 00`: no matches.
- absolute target dword `48 EA 61 00`: two matches at `0x00512264` and `0x005c521a`.
- interior dword `4C EA 61 00`: no matches.
- successor dword `50 EA 61 00`: one match at `0x005122a4`.
- RVA forms `48 EA 21 00`, `4C EA 21 00`, and `50 EA 21 00`: no matches.
- `B9 48 EA 61 00`: one match at `0x00512263`, the MapPane `mov ecx, offset aWm2_0`.
- `68 48 EA 61 00`: one match at `0x005c5219`, the WorldMapPane `push offset aWm2_0`.

Decompiler facts:

- `sub_511DB0` compares a local wide map-name string against `L"wm2"` at `0x00512236` and `L"WM2"` at `0x00512276`, then later constructs a WorldMapPane object through `sub_5C2AC0`. This is the MapPane source-use route.
- `sub_5C5200` calls `sub_5845B0(L"WM2")` in both display-mode branches at `0x005c5319` and `0x005c5256`. This is the WorldMapPane source-use route.
- `sub_5C48B0` calls `sub_5C5200` at `0x005c4955` and `0x005c4acf`.
- `sub_5C3950` calls `sub_5C48B0` at `0x005c3bd8` and `0x005c3e2b`.

## PE / Raw Evidence

Raw binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, imagebase `0x400000`.

Relevant section mapping:

- `.text`: VA `0x00401000`, raw `0x400`, raw size `0x20b600`.
- `.rdata`: VA `0x0060d000`, raw `0x20ba00`, raw size `0x5f200`.
- `.data`: VA `0x0066d000`, raw `0x26ac00`, raw size `0xd800`.
- `.rsrc`: VA `0x0069d000`, raw `0x278400`, raw size `0x15e00`.

Target mapping and scans:

- VA `0x0061ea48` maps to raw `0x21d448` in `.rdata`.
- bytes at raw `0x21d448`: `57 00 4d 00 32 00 00 00`.
- boundary bytes at `0x0061ea40-0x0061ea58`: `77 00 6d 00 32 00 00 00 57 00 4d 00 32 00 00 00 77 00 6d 00 33 00 00 00`.
- UTF-16 `WM2\0`: one hit at VA `0x0061ea48`.
- UTF-16 `WM2` without final NUL: one hit at VA `0x0061ea48`.
- ASCII `WM2\0`: no hits.
- absolute VA `0x0061ea48`: two hits, operand VAs `0x00512264` and `0x005c521a`.
- absolute VA `0x0061ea4c`: no hits.
- absolute VA `0x0061ea50`: one hit, operand VA `0x005122a4`.
- RVA `0x0021ea48`, `0x0021ea4c`, and `0x0021ea50`: no hits.
- `mov ecx, 0x0061ea48`: one hit at VA `0x00512263`.
- `push 0x0061ea48`: one hit at VA `0x005c5219`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea70` | `0003IX` / `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` | Non-emitting split index for `.PAL` and `WM*` literals | false | `NONE` | `90/93` | Keep as split index |
| `0x0061ea24-0x0061ea30` | `0003JG` / `SharedMapPaletteSuffixString` | Shared `.PAL` suffix | true | `NONE`; emitters `0000L3,0000PB` | `87/93` | Similar shared-literal sibling |
| `0x0061ea30-0x0061ea48` | `0003JH` / `MapPaneWorldMapNameComparisonStrings` | MapPane-only `wm`, `WM`, `wm2` | true | `0000L3` | `88/93` | Separate predecessor; do not merge |
| `0x0061ea48-0x0061ea50` | `0003JI` / `SharedWorldMap2UpperString` | Shared UTF-16 `WM2` | true | `NONE`; emitters `0000L3,0000PB` | `87/93` | Current target; keep unchanged |
| `0x0061ea50-0x0061ea70` | `0003JJ` / `MapPaneWorldMapNameThreeFourStrings` | MapPane-only `wm3`, `WM3`, `wm4`, `WM4` | true | `0000L3` | `88/93` | Separate successor; do not merge |
| `0x00511db0` | `sub_511DB0` | MapPane world-map/object helper, target use at `0x00512263` | true | MapPane route | covered by MapPane docs | Proves emitter `0000L3` |
| `0x005c5200` | `sub_5C5200` | WorldMapPane helper, target use at `0x005c5219` | true | WorldMapPane route | covered by WorldMapPane docs | Proves emitter `0000PB` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00512263 -> 0x0061ea48` | `mov ecx, offset aWm2_0` in `sub_511DB0` | MapPane source-use route for `L"WM2"` |
| `0x005c5219 -> 0x0061ea48` | `push offset aWm2_0` in `sub_5C5200` | WorldMapPane source-use route for `L"WM2"` |
| `0x005c48b0 -> 0x005c5200` | calls at `0x005c4955` and `0x005c4acf` | Places the second use inside WorldMapPane helper logic |
| `0x005c3950 -> 0x005c48b0` | calls at `0x005c3bd8` and `0x005c3e2b` | Further supports the WorldMapPane route |
| `0x0061ea4c` | zero IDA xrefs and zero raw operands | Rejects interior-tail split |
| `0x005122a3 -> 0x0061ea50` | successor `wm3` use in `sub_511DB0` | Keeps successor in MapPane-only `0003JJ` |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- The target page already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`, exact bytes, two direct source-use refs, and the no-single-owner decision.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003JI` as no-owner with emitters `0000L3,0000PB`.
- `by-memory/-coverage-report.md` currently lists the same shared-literal explanation and needs no replacement.
- `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` is correctly modeled as a non-emitting split index.
- `by-file/MapPane.md` is a valid file root at `NexusTK/map/` and documents `sub_511DB0`/world-map comparison context.
- `by-file/WorldMapPane.md` is a valid file root at `NexusTK/map/` and documents WorldMapPane as a separate module, not a MapPane continuation.
- `auto-generated/-ag-file-coverage.md` confirms `0000L3` emits to `auto-generated/NexusTK/map/MapPane.cpp` and `0000PB` emits to `auto-generated/NexusTK/map/WorldMapPane.cpp`.

Current generated source files `auto-generated/NexusTK/map/MapPane.cpp` and `auto-generated/NexusTK/map/WorldMapPane.cpp` exist but are zero bytes. That is not an emitter dead end; it reflects absence of final reconstruction text.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000L3,0000PB`

- Evidence for: one physical pooled UTF-16 `WM2` object, one MapPane ref, one WorldMapPane ref, no single declaration site, and no evidence of a named global/static constant.
- Evidence against: most neighboring `WM*` strings are MapPane-only, and `sub_511DB0` uses this literal in the same comparison ladder.
- Decision: accepted. Direct cross-module use outweighs adjacency.

### 2. `0000L3` MapPane as canonical owner

- Evidence for: direct `sub_511DB0` use and adjacent MapPane-only comparison strings.
- Evidence against: `sub_5C5200` directly uses the same physical literal from the WorldMapPane helper path. No source/debug evidence proves MapPane declared it.
- Decision: reject as canonical owner; retain as emitter.

### 3. `0000PB` WorldMapPane as canonical owner

- Evidence for: direct `sub_5C5200` use and `sub_5C3950 -> sub_5C48B0 -> sub_5C5200` helper chain.
- Evidence against: `sub_511DB0` directly uses the same literal, and the surrounding `WM*` comparison string run is mostly MapPane-side.
- Decision: reject as canonical owner; retain as emitter.

### 4. Parent split index `0003IX`

- Evidence for: physical containment.
- Evidence against: `0003IX` is intentionally `RECONSTRUCTABLE:FALSE` and non-emitting. It is a split index, not a source declaration owner.
- Decision: reject.

### 5. New shared constants file/grouping

- Evidence for: a shared header constant is possible in original source.
- Evidence against: no PDB/source path, linker map, initializer, named global, pointer table, or repeated shared-constant cluster supports it. Inventing a file would only hide unresolved declaration placement.
- Decision: reject.

## Negative Evidence Summary

- No refs to the interior `0x0061ea4c` tail.
- No raw absolute or RVA pointer to `0x0061ea4c`.
- No second UTF-16 `WM2` object.
- No ASCII `WM2` object.
- No third direct xref or hidden RVA-form use.
- No table, initializer, writable global, RTTI, source path, object-file clue, or debug symbol proves declaration ownership by either consumer.
- No IDA-safe name repair is needed; IDA's `aWm2_0` label is adequate for this literal.

## Final Recommendation

Exact metadata to retain:

```text
COMPLETION:87
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

No target edits, by-file/by-class/by-global edits, split repair, or validation-triggering documentation changes are recommended.

## Follow-Up Actions

- Supervisor action: close the active tracker row as `complete-no-change` if this report is accepted.
- A-agent actions: none.
- Future research: revisit only if PDB/source/linker-map evidence or a broader proven shared constants file appears.

Optional tracker close-out row:

```text
| `0003JI` | 0x0061ea48-0x0061ea50.SharedWorldMap2UpperString | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md` | `Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md` |
```

## Exact Supervisor-Owned Shared-Report Text

No `by-memory/-coverage-report.md` edit is recommended. Keep the current row:

```text
                - [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`); B002 reconfirmed no interior-tail refs, no split/merge/reclassification, and no duplicate source object.
```

Generated report rows are read-only and already correct:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `87/93`.
- Remaining uncertainty: the stripped binary cannot prove whether the original source used two direct `L"WM2"` literals, a macro, or a named shared constant. That uncertainty supports `CANONICAL_OWNER:NONE`; it does not weaken the two proven emitter routes.

## Validator Results

- Commands run: none.
- Result: not applicable; no by-* documentation file changed.
- Dry runs: none.
- Unresolved validator warnings/errors: none from this pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

## Lease State

No leases were used. `goal.md` says no lease is required to create or update reports inside `Agent-B002/research`, and no by-* files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B002/0003JI-SharedWorldMap2UpperString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
