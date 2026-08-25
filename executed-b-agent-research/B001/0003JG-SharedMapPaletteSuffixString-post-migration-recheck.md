** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](../../../../../by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) unchanged as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000PB`.
- Final disposition: valid no-owner-with-emitters pooled/shared UTF-16 `.PAL` suffix literal. No single semantic declaration/source owner is proven, but live IDA MCP and raw PE evidence prove two exact source-use output routes: [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) and [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md).
- Required action: no metadata change, no score change, no `by-memory/-coverage-report.md` edit, no split, no merge, no reclassification, no new shared constants owner, no IDA repair, and no reconstruction C++.
- Exact metadata recommendation: `COMPLETION:87`; `CONFIDENCE:93`; `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000L3,0000PB`; blank `EMITTER_POSITION_OPTIONAL`; blank `RECONSTRUCTION_CPP CODE`.
- Confidence: `93/100` for retaining the current route. The remaining uncertainty is the original source declaration form: two source spellings pooled by the linker/compiler versus an unproven shared include/helper constant.

## Exact Recommendation

Retain the target header exactly:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. The current manual row is already accurate:

```text
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; B003 post-migration and B001 second-pass reviews confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner, PaletteLib owner, split, merge, or reclassification justified.
```

The current generated rows should remain semantically unchanged after normal tool refresh:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

The generated output-path cell currently displays the first surfaced source path, `auto-generated/NexusTK/map/MapPane.cpp`. That display does not make `0000L3` the canonical owner and does not remove `0000PB` as a valid emitter.

## Supporting Research

## Target

- Target UID: `0003JG`.
- Target path: `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current no-owner row with emitters `0000L3,0000PB`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003JG`, assigned to B001 for `0003JG-SharedMapPaletteSuffixString-post-migration-recheck.md`.
- Prior reports reviewed as background, not accepted without recheck:
  - `tools/leaser/Agents/Agent-B003/research/executed/0003JG-SharedMapPaletteSuffixString-post-migration.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/0003JG-SharedMapPaletteSuffixString-second-pass.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/0003JG-SharedMapPaletteSuffixString.md`
- Current scores and state: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank reconstruction C++.

## Executive Recommendation

Keep the current no-owner-with-emitters state. The target is an exact UTF-16 `.PAL` suffix plus terminator/alignment at `0x0061ea24-0x0061ea30`. It is source-authored string data used by reconstructable code, but the physical literal address is shared by two separately documented source-use contexts.

| Route | Evidence | Decision |
| --- | --- | --- |
| `0000L3` MapPane | Direct pushes at `0x00510b57` and `0x00511041` inside `sub_510960`; decompilation shows `_wcscat_s(..., L".PAL")` during MapPane map/resource-name handling. | Keep as emitter. |
| `0000PB` WorldMapPane | Direct push at `0x005c2eae` inside `sub_5C2AC0`; decompilation shows `sub_584470(..., L".PAL", 4)` followed by `sub_543D70`, inside a function that installs the `WorldMapPane::vftable`. | Keep as emitter. |
| single canonical owner | No debug/source metadata, owner-only xref pattern, table, static-member layout, or coherent shared declaration owner was found. | Keep `CANONICAL_OWNER:NONE`. |

Do not recommend reconstruction C++. Completion is `87`, below the active `90/90+` code-entry bar, and the item has no standalone source object to emit. It should be represented through the two proven consuming source files when those functions are reconstructed.

## Supervisor Active Recheck

- Supervisor instruction: perform a fresh post-migration B-agent review of current `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000PB`.
- Split repair required: no. The target already covers exactly `.PAL` plus terminator/alignment; the next child starts cleanly at `0x0061ea30` with `wm`.
- Parent repair required: no. The broader [UID:0003IX][MapWorldPaletteResourceStrings](../../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) page is a non-emitting split index over mixed MapPane-only and shared strings. The exact child carries the source-use routing.
- Coverage/report change required: no. Current target metadata, generated rows, tracker note, and manual coverage row already reflect the correct state.

## Inference Research Guidance Check

Facts:

- Live IDA MCP decodes `0x0061ea24-0x0061ea30` as `L".PAL"` plus terminator/alignment.
- Live IDA MCP reports exactly three direct xrefs to `0x0061ea24`: two in `sub_510960` and one in `sub_5C2AC0`.
- Independent PE scan finds exactly three raw `push 0x0061ea24` encodings, matching the IDA refs.
- `sub_543D70` / PaletteLib is reached after constructed palette names but does not directly reference `0x0061ea24`.
- No `.pdb`, `RSDS`, `NB10`, `.cpp`, `.cxx`, or `.h` source/debug breadcrumb was found by IDA MCP regex search.

Inference:

- The target is best modeled as a compiler/linker-pooled or shared literal used by both MapPane and WorldMapPane source contexts.
- The direct xrefs prove output routes, not a single semantic declaration owner.
- `CANONICAL_OWNER:NONE` is correct because assigning either consumer as owner would overclaim declaration ownership.
- `EMITTER_UIDS:0000L3,0000PB` is correct because both consumers need the literal surfaced in reconstructed source-use context.

Rule basis from `by-structure.md`:

- `CANONICAL_OWNER` is semantic ownership, not output routing.
- `EMITTER_UIDS` is output routing and may contain multiple emitters.
- Pooled/shared string literals can remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while using multiple emitters for proven source-use contexts.
- Agents should not invent a standalone helper/global file solely to avoid `NONE`.
- Current reconstruction C++ entry gate is approximately `90/90+`; this item remains below that completion threshold.

## Evidence Standards Used

Evidence types used:

- Live IDA MCP `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `analyze_component`, `insn_query`, `find_bytes`, `find_regex`, and filtered decompilation observations.
- Independent read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for section mapping, target bytes, exact literal occurrences, absolute-VA immediate refs, push-immediate refs, RVA refs, and local-neighborhood uniqueness.
- Documentation review of the target page, split-index parent, adjacent children, MapPane file root, WorldMapPane file root, PaletteLib file root, MapPane packet aggregate, WorldMapPane aggregate, WorldMapPane resource strings, generated coverage rows, tracker row, and prior executed reports.

This evidence is strong enough to retain two emitters and reject single-owner or extra-emitter alternatives.

## IDA MCP Facts

Live IDA MCP facts from this recheck:

| Field | Value |
| --- | --- |
| Session | `b001_0003gy` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| Module | `NexusTK.exe` |
| Image base | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready |

Target bytes and local string island:

```text
get_bytes 0x0061ea24 size 0x4c:
2e 00 50 00 41 00 4c 00 00 00 00 00
77 00 6d 00 00 00 00 00
57 00 4d 00 00 00 00 00
77 00 6d 00 32 00 00 00
57 00 4d 00 32 00 00 00
77 00 6d 00 33 00 00 00
57 00 4d 00 33 00 00 00
77 00 6d 00 34 00 00 00
57 00 4d 00 34 00 00 00
```

`get_string` results:

| Address | String | Current child meaning |
| --- | --- | --- |
| `0x0061ea24` | `.PAL` | current target, shared MapPane/WorldMapPane suffix |
| `0x0061ea30` | `wm` | MapPane-only sibling |
| `0x0061ea38` | `WM` | MapPane-only sibling |
| `0x0061ea40` | `wm2` | MapPane-only sibling |
| `0x0061ea48` | `WM2` | shared MapPane/WorldMapPane sibling |
| `0x0061ea50` | `wm3` | MapPane-only sibling |
| `0x0061ea58` | `WM3` | MapPane-only sibling |
| `0x0061ea60` | `wm4` | MapPane-only sibling |
| `0x0061ea68` | `WM4` | MapPane-only sibling |
| `0x0061ea70` | `%s\Mscfg.dll` | successor child boundary |

Direct xrefs to the target:

| Target | Xref | Function | IDA meaning |
| --- | --- | --- | --- |
| `0x0061ea24` | `0x00510b57` | `sub_510960` | data ref, `push offset aPal; ".PAL"` |
| `0x0061ea24` | `0x00511041` | `sub_510960` | data ref, `push offset aPal; ".PAL"` |
| `0x0061ea24` | `0x005c2eae` | `sub_5C2AC0` | data ref, `push offset aPal; ".PAL"` |

Function identity:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x00510960` | `sub_510960`, size `0x9e7` | MapPane map-info/object-removal/resource-name helper context |
| `0x00511db0` | `sub_511DB0`, size `0xa8a` | MapPane object-create/world-map bridge; calls `sub_5C2AC0` |
| `0x005c2ac0` | `sub_5C2AC0`, size `0x7ea` | WorldMapPane constructor/resource initialization family |
| `0x005c5200` | `sub_5C5200`, size `0x1d0` | WorldMapPane helper using sibling `WM2` |
| `0x00543d70` | `sub_543D70`, size `0xce` | PaletteLib loaded-palette lookup/loader helper |
| `0x0061ea24` | not a function | correct data-only target |

`analyze_component` facts:

- Internal edge: `sub_511DB0 -> sub_5C2AC0`.
- Internal edge: `sub_5C2AC0 -> sub_543D70`.
- Shared global `0x0061ea24` / `aPal` is accessed by `sub_510960` and `sub_5C2AC0`.
- Shared global `0x0061ea48` / `aWm2_0` is accessed by `sub_511DB0` and `sub_5C5200`, matching the adjacent shared-literal pattern.
- `sub_543D70` has no direct target access in this component report.

Scoped `insn_query` facts:

| Scope | Matches for operand `0x0061ea24` |
| --- | --- |
| `0x00510000-0x00513000` | `0x00510b57`, `0x00511041`, both in `sub_510960` |
| `0x005c2000-0x005c6000` | `0x005c2eae`, in `sub_5C2AC0` |
| `0x00543000-0x00544500` | none; PaletteLib has no direct operand ref |

Decompilation observations:

- `sub_510960` contains two branches that copy a MapPane-side name buffer and append `L".PAL"` via `_wcscat_s`, corresponding to the direct refs at `0x00510b57` and `0x00511041`.
- `sub_5C2AC0` installs `WorldMapPane::vftable` entries, initializes WorldMapPane state, builds a suffix/name with `L".PAL"` using `sub_584470`, then calls `sub_543D70` to resolve/load the constructed palette name.
- `sub_543D70` accepts a `wchar_t *Source`, compares it with loaded palette names, and calls `sub_5431C0` if missing. It is a downstream palette lookup/loader, not the direct source of the `.PAL` suffix.

Search and negative IDA evidence:

| Query | Result |
| --- | --- |
| `find_bytes "24 ea 61 00"` | 3 hits: `0x00510b58`, `0x00511042`, `0x005c2eaf` |
| `find_bytes "68 24 ea 61 00"` | 3 hits: `0x00510b57`, `0x00511041`, `0x005c2eae` |
| `find_bytes "24 ea 21 00"` | 0 hits |
| `find_regex "(?i)\.pdb|RSDS|NB10|\.cpp|\.cxx|\.h"` | 0 matches |
| `find_regex "(?i)MapPane|WorldMapPane|PaletteLib"` | RTTI/class-name matches for all three families, but no source declaration metadata for this literal |

## PE / Raw Evidence

Independent read-only PE scan:

| Field | Value |
| --- | --- |
| Executable | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| Machine | `0x14c` |
| Image base | `0x400000` |
| Sections | `.text 0x401000-0x60c600`; `.rdata 0x60d000-0x66c200`; `.data 0x66d000-0x69ce24`; `.rsrc 0x69d000-0x6b2e00` |
| Target VA | `0x0061ea24-0x0061ea30` |
| Target file offset | `0x21d424-0x21d430` |
| Target section | `.rdata` |
| Target bytes | `2e 00 50 00 41 00 4c 00 00 00 00 00` |

Raw scan results:

| Pattern | Count | Hits / meaning |
| --- | ---: | --- |
| exact UTF-16 `.PAL` with target-style terminator/alignment | 69 | common text; textual `.PAL` occurrence count is not an owner signal |
| target VA immediate `24 ea 61 00` | 3 | `0x00510b58`, `0x00511042`, `0x005c2eaf` |
| target `push 0x0061ea24` bytes `68 24 ea 61 00` | 3 | `0x00510b57`, `0x00511041`, `0x005c2eae` |
| target RVA immediate `24 ea 21 00` | 0 | no RVA-form refs found |
| exact local prefix `.PAL` plus next `wm` bytes | 1 | only `0x0061ea24`, confirming the split-index neighborhood as a unique local island |

This raw evidence independently confirms the IDA direct-ref inventory and argues against hidden extra emitters, pointer tables, or a PaletteLib-owned raw reference to this exact address.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea30` | [UID:0003JG] `SharedMapPaletteSuffixString` | exact UTF-16 `.PAL` suffix literal | TRUE | owner `NONE`; emitters `0000L3,0000PB` | `87/93` | keep unchanged |
| `0x0061ea24-0x0061ea70` | [UID:0003IX] `MapWorldPaletteResourceStrings` | non-emitting split index over mixed/shared literals | FALSE | owner `NONE`; no emitters | `90/93` | keep as container |
| `0x0061ea30-0x0061ea48` | [UID:0003JH] `MapPaneWorldMapNameComparisonStrings` | `wm`, `WM`, `wm2` | TRUE | owner/emitter `0000L3` | `88/93` | MapPane-only sibling |
| `0x0061ea48-0x0061ea50` | [UID:0003JI] `SharedWorldMap2UpperString` | shared `WM2` literal | TRUE | owner `NONE`; emitters `0000L3,0000PB` | `87/93` | comparable shared sibling |
| `0x0061ea50-0x0061ea70` | [UID:0003JJ] `MapPaneWorldMapNameThreeFourStrings` | `wm3`, `WM3`, `wm4`, `WM4` | TRUE | owner/emitter `0000L3` | `88/93` | MapPane-only sibling |
| `0x00510960` | `sub_510960` | MapPane map/resource-name helper context | TRUE through MapPane aggregate | MapPane route | by-file `89/85` | proven emitter context |
| `0x005c2ac0` | [UID:0001O4] `WorldMapPane` aggregate constructor range | WorldMapPane construction/resource initialization | TRUE | WorldMapPane route | aggregate `80/85`; by-file `90/86` | proven emitter context |
| `0x00543d70` | PaletteLib helper | downstream palette lookup/loader | TRUE through PaletteLib family | no target ref | by-file `88/85` | rejected as emitter for this item |

## Documentation Evidence And IDA Status

Target page:

- Documents `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L3,0000PB`.
- Lists the three direct refs at MapPane `sub_510960` and WorldMapPane `sub_5C2AC0`.
- Live IDA MCP and raw PE evidence confirm the documented xrefs and byte range.

MapPane:

- [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) is a valid source root at `89/85` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- [UID:0001AW][MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) documents `0x00510960` as a MapPane map-info/object-removal helper inside the MapPane packet/helper family.
- IDA confirms two direct `.PAL` refs in `sub_510960`, so MapPane is a proven emitter.
- IDA also confirms WorldMapPane direct use, so MapPane is not a safe canonical owner.

WorldMapPane:

- [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md) is a valid source root at `90/86` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- [UID:0001O4][WorldMapPane](../../../../../by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) documents `0x005c2ac0` as the constructor/resource initialization family.
- IDA confirms `sub_5C2AC0` installs the `WorldMapPane::vftable` and directly references `.PAL`, so WorldMapPane is a proven emitter.
- IDA also confirms MapPane direct use, so WorldMapPane is not a safe canonical owner.

PaletteLib:

- [UID:0000MB][PaletteLib](../../../../../by-file/PaletteLib.md) is a valid source root for palette manager code at `88/85`.
- `sub_543D70` is a PaletteLib lookup/loader reached after callers construct source names.
- IDA and raw PE evidence find no direct `0x0061ea24` ref in the PaletteLib code range. PaletteLib is dependency context, not a source-use emitter for this literal.

Split index / siblings:

- [UID:0003IX] remains a non-reconstructable split index because the local island mixes shared and MapPane-only strings.
- [UID:0003JH] and [UID:0003JJ] are MapPane-only siblings.
- [UID:0003JI] has the same no-owner-with-emitters shape as this target for the `WM2` literal.
- The current split is evidence-backed; merging these children would erase distinct xref/owner patterns.

Generated and warning-state evidence:

- `auto-generated/-ag-memory-coverage.md` lists `0003JG` as `no-owner` with `0000L3,0000PB` emitters.
- `auto-generated/by-memory-tool-report.md` currently has a warning for the parent `0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` missing document text, not for this exact target. That scanner warning does not change this target's ownership/emitter decision.

## Source-Use / Emitter Inventory

Accepted emitter `0000L3` - [MapPane](../../../../../by-file/MapPane.md)

- Source path: `NexusTK/map/`.
- Candidate file: `map/MapPane.cpp`.
- Evidence: `0x00510b57` and `0x00511041` in `sub_510960` push `0x0061ea24`; decompilation shows `_wcscat_s(..., L".PAL")` after copying MapPane-side resource/name text.
- Parent/root gate: `MapPane.md` is `89/85` and `CANONICAL_OWNER:FILE`, sufficient as an emitter root.
- Decision: keep in `EMITTER_UIDS`.

Accepted emitter `0000PB` - [WorldMapPane](../../../../../by-file/WorldMapPane.md)

- Source path: `NexusTK/map/`.
- Candidate file: `map/WorldMapPane.cpp`.
- Evidence: `0x005c2eae` in `sub_5C2AC0` pushes `0x0061ea24`; decompilation shows the function installs `WorldMapPane::vftable`, constructs the palette suffix/name with `.PAL`, and calls `sub_543D70`.
- Parent/root gate: `WorldMapPane.md` is `90/86` and `CANONICAL_OWNER:FILE`, sufficient as an emitter root.
- Decision: keep in `EMITTER_UIDS`.

Rejected emitter `0000MB` - [PaletteLib](../../../../../by-file/PaletteLib.md)

- Evidence for consideration: PaletteLib receives constructed palette names through `sub_543D70`.
- Evidence against: `sub_543D70` and the PaletteLib code range have no direct `0x0061ea24` xref; raw PE finds only the three MapPane/WorldMapPane pushes.
- Decision: do not add as emitter.

Rejected emitter `0003IX` - split index parent

- Evidence for consideration: the target physically resides inside that local string island.
- Evidence against: `0003IX` is `RECONSTRUCTABLE:FALSE` and intentionally non-emitting; it is a documentation/split index, not a source root.
- Decision: do not add as emitter.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000L3,0000PB` - accepted

Evidence for:

- Direct IDA refs prove two material source-use contexts.
- Raw PE finds exactly the same three direct pushes and no RVA/table refs.
- `by-structure.md` explicitly supports `CANONICAL_OWNER:NONE` with multiple emitters for pooled/shared literals.
- No source/debug metadata or owner-only use pattern proves one declaration owner.

Evidence against:

- The original declaration style is unknown; the source may have spelled the literal twice or used an included constant.

Decision:

- Keep unchanged. This is the best current model.

### 2. Canonical owner `0000L3` MapPane - rejected

Evidence for:

- MapPane has two of three direct refs.
- Several adjacent siblings are MapPane-only.
- `MapPane.md` is a valid file root and clears the emitter gate.

Evidence against:

- WorldMapPane constructor/resource initialization has an independent direct ref to the same address.
- Xref count is source-use evidence, not declaration ownership proof for a pooled literal.
- Forcing MapPane as owner would hide the separately documented WorldMapPane source-use context.

Decision:

- Reject as canonical owner; keep as emitter.

### 3. Canonical owner `0000PB` WorldMapPane - rejected

Evidence for:

- `sub_5C2AC0` is clearly WorldMapPane constructor/resource code and directly uses `.PAL`.
- `WorldMapPane.md` is a valid file root and clears the emitter gate.

Evidence against:

- MapPane has two direct uses in `sub_510960`.
- Adjacent local island includes MapPane-only strings, so the physical neighborhood is not exclusively WorldMapPane-owned.

Decision:

- Reject as canonical owner; keep as emitter.

### 4. Canonical owner or emitter `0000MB` PaletteLib - rejected

Evidence for:

- The constructed name is passed to the PaletteLib lookup/loader helper `sub_543D70`.

Evidence against:

- PaletteLib has no direct target ref.
- The caller-side filename suffix construction is performed before PaletteLib lookup.
- Raw PE and IDA find only MapPane/WorldMapPane direct refs.

Decision:

- Reject as owner and emitter.

### 5. Canonical owner or emitter `0003IX` split index - rejected

Evidence for:

- The target is physically inside the `0x0061ea24-0x0061ea70` index.

Evidence against:

- The index is a non-emitting documentation container over mixed-use children.
- It is not a source declaration, file root, class, global, or output route.

Decision:

- Reject.

### 6. New shared constants/source owner - rejected

Evidence for:

- `.PAL` is common and reused throughout the binary.
- A header/shared constant is theoretically possible.

Evidence against:

- No source/debug metadata, table abstraction, coherent shared file inventory, or broader exact-address cluster was found.
- Textual `.PAL` occurs 69 times, so common text alone is weak evidence.
- `by-structure.md` warns not to invent standalone global/helper owners solely to avoid `NONE`.

Decision:

- Reject. The current no-owner-with-emitters route is more honest and more executable.

## Negative Evidence Summary

- No direct owner-only xref pattern exists; both MapPane and WorldMapPane materially use the exact target address.
- No source/debug metadata points to a source file, header, or compilation unit for the literal.
- No raw RVA refs, hidden VA pointer table refs, or extra push refs were found for `0x0061ea24`.
- PaletteLib has no direct xref to the target and should not receive output for a caller-side suffix literal.
- The split index is non-emitting and cannot be treated as a source-level owner.
- The target bytes are not padding-only, compiler runtime, or a resource artifact; it is reconstructable source string data.
- Reconstructable no-owner-with-emitters is not an invalid state here because emitters are present and justified. The invalid state would be blank emitters despite proven source-use contexts; that is not the current state.

## Split / Merge / Repair Decision

No split is recommended:

- The target page already covers exactly `0x0061ea24-0x0061ea30`.
- The next string starts at `0x0061ea30`.
- IDA string decoding and raw bytes match the documented boundary.

No merge is recommended:

- Adjacent children have different xref sets and different owner/emitter semantics.
- `0003JH` and `0003JJ` are MapPane-only.
- `0003JI` is shared but contains distinct text, distinct xrefs, and a separate exact range.

No reclassification is recommended:

- The target is source-declared/generated-binary string data used by reconstructable code.
- It is not a non-reconstructable split index, padding range, compiler/runtime artifact, or ignored asset blob.

No IDA repair is recommended:

- Function boundaries and xrefs are consistent with current documentation.
- The string boundary is clean and the direct refs are exact.

No parent/source repair is required:

- `MapPane.md` and `WorldMapPane.md` are both valid file roots above the emitter gate.
- The absence of a canonical owner is evidence-based, not caused by a failed parent score.

## Score / Coverage Effects

Before:

```text
COMPLETION:87
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
```

After recommendation:

```text
COMPLETION:87
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
```

No score change is recommended. Completion stays below final/code-entry level because no final source spelling/code placement is written and no single declaration owner is proven. Confidence stays high because exact bytes, boundaries, direct refs, emitters, and negative owner evidence are now rechecked live.

## Final Recommendation

Exact recommended target state:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
COMPLETION:87
CONFIDENCE:93
RECONSTRUCTION_CPP CODE:
```

Exact recommended coverage/report action:

- No `by-memory/-coverage-report.md` edit required.
- No generated file manual edit required.
- Normal generated reports may keep showing `0003JG` in no-owner sections with two emitters. That is expected for a valid no-owner-with-emitters shared literal.

Exact items left no-owner:

- `0003JG` stays no-owner because no single semantic declaration owner clears the evidence gate.

Exact items left emitting:

- `0003JG` stays emitting through `0000L3,0000PB` because both source-use contexts are proven by direct code refs and valid by-file roots.

## Follow-Up Actions

Supervisor actions:

- Accept this recheck with no by-* or coverage changes.
- Move this report to `research/executed` if accepted.

A-agent actions:

- Do not attach `0003JG` to only MapPane or only WorldMapPane during routine cleanup.
- Do not add PaletteLib as an emitter unless new direct `0x0061ea24` refs or source metadata are discovered.
- Keep reconstruction C++ blank until the consuming functions reach the active `90/90+` source-output gate.

B001 future research actions:

- Revisit only if later evidence discovers a real shared constants/header owner or a source/debug breadcrumb for this literal family.

## Confidence

- Recommendation confidence: `93/100`.
- Byte/range confidence: `97/100`.
- Emitter-route confidence: `95/100`.
- Canonical-owner rejection confidence: `91/100`.
- Remaining uncertainty: original source declaration style. Current evidence cannot distinguish duplicated source spellings pooled by the compiler/linker from a shared source constant, so a single `CANONICAL_OWNER` should not be asserted.

## Validator Results

- Validator commands run: none.
- Reason: this assignment created only an Agent-B001 research report and recommends no validator-managed by-* documentation edits. The user prohibited dry-run modes, and no normal `--apply` validator action was required for an Agent research Markdown file.
- Dry-run validator modes: not used.
- Memory-range modes: not used.
- Unresolved validator warnings/errors from this pass: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003JG-SharedMapPaletteSuffixString-post-migration-recheck.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.
- Direct `by-memory/-coverage-report.md` edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B001/0003JG-SharedMapPaletteSuffixString-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
