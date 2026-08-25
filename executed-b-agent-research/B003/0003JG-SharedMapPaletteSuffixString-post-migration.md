** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# B003 Research Report: UID 0003JG - SharedMapPaletteSuffixString Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, and add multiple output routes with `EMITTER_UIDS:0000L3,0000PB`.
- Final disposition: source-authored/linker-pooled UTF-16 `.PAL` suffix literal with no defensible single semantic owner, but with two proven source-use contexts that should both receive an emitter route.
- Required action: update the target metadata and coverage row through supervisor/normal documentation workflow; do not split, merge, or reclassify the item as non-reconstructable.
- Confidence: 91/100 for no canonical owner plus MapPane and WorldMapPane emitters.

## Supporting Research

## Target

- Target: [UID:0003JG] `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- Range: `0x0061ea24-0x0061ea30`
- Current metadata:
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `EMITTER_POSITION_OPTIONAL:` blank
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists the item as `no-owner` with blank emitters; the current `by-memory/-coverage-report.md` row says "parent blank."
- Assignment: `B003-0003JG-post-migration`, post-migration recheck under the separated `CANONICAL_OWNER` / `EMITTER_UIDS` model.

## Executive Recommendation

The old B001 recommendation remains correct for semantic ownership, but not for output routing under the current model. `0x0061ea24` is a pooled/shared wide string literal that is materially used in both MapPane and WorldMapPane code. No single declaration owner is proven, so `CANONICAL_OWNER:NONE` is still the least misleading owner state. However, by-structure now explicitly allows `CANONICAL_OWNER:NONE` plus multiple `EMITTER_UIDS` for pooled strings/shared constants when multiple source-use contexts are proven. That is exactly this case.

Recommended metadata:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not keep blank `EMITTER_UIDS`. Under the current owner/emitter model, this target is not a valid final "dead/non-emitting reconstructable" item because live IDA and raw PE evidence prove two real source-use contexts. Blank emitters were understandable under the old combined parent model, but now the correct state is no canonical owner and emitted through both proven consumers.

Do not set `RECONSTRUCTABLE:FALSE`. The item is not an audit container, padding span, compiler/runtime helper, section map, or mixed index. It is an exact source-authored UTF-16 suffix literal that must be represented somewhere in reconstructed source.

## Active Recheck / Split Repair

- No split repair is needed. `0x0061ea24-0x0061ea30` is exactly the `.PAL` string plus terminator/alignment. The next child begins at `0x0061ea30` with `L"wm"`.
- No merge is recommended. The surrounding container [UID:0003IX] `MapWorldPaletteResourceStrings` is correctly `RECONSTRUCTABLE:FALSE` as a split index over children with different use patterns.
- No new owner/file/grouping is recommended. A synthetic shared suffix owner would be a modeling convenience, not something proven by debug/source metadata or a broader coherent source island.
- No final `RECONSTRUCTION_CPP CODE` should be written in this pass. The route should be fixed now; final source spelling remains gated by the normal high-confidence reconstruction-code threshold.

## Inference Research Guidance Check

- Existing documentation was treated as a lead, not authority. The target page and B001 report predate the current split between semantic ownership and output routing, so their "parentless" conclusion was re-evaluated.
- IDA fact: `0x0061ea24` decodes to `L".PAL"` and has exactly three direct immediate code references in the live database.
- Documentation evidence: MapPane and WorldMapPane are both established by-file source roots under `NexusTK/map/`, and PaletteLib is an established downstream palette manager.
- Inference: the literal is best modeled as compiler/linker-pooled/shared data. The source-use routes are proven by code references; the declaration owner is not.

## Evidence Standards Used

- IDA MCP facts: `server_health`, `lookup_funcs`, `get_bytes`, `get_string`, `xrefs_to`, `disasm`, `analyze_function`, `find_bytes`, and `find_regex` evidence from database `b001_0003gy`.
- PE/raw facts: direct scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for target bytes, VA immediates, RVA immediates, and `push imm32` references.
- Documentation evidence: current target page, [UID:0003IX] split-index page, B001 executed report, `by-structure.md` owner/emitter rules, MapPane and WorldMapPane by-file pages, PaletteLib by-file page, and current generated coverage rows.
- Negative evidence: no PDB/source-path metadata, no single owner-only xref pattern, no PaletteLib direct xref, no table/vtable adjacency that would make this a class/static member declaration.

## IDA MCP Facts

Live database identity:

- `server_health`: status ok; module `NexusTK.exe`; imagebase `0x400000`; input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; Hex-Rays available; strings cache ready.

Target bytes and decoding:

```text
get_bytes 0x0061ea24 size 12:
2e 00 50 00 41 00 4c 00 00 00 00 00

get_string 0x0061ea24:
.PAL
```

The broader local string island decodes as:

```text
0x0061ea24 L".PAL"
0x0061ea30 L"wm"
0x0061ea38 L"WM"
0x0061ea40 L"wm2"
0x0061ea48 L"WM2"
0x0061ea50 L"wm3"
0x0061ea58 L"WM3"
0x0061ea60 L"wm4"
0x0061ea68 L"WM4"
0x0061ea70 L"%s\\Mscfg.dll"
```

Direct xrefs:

```text
xrefs_to 0x0061ea24:
0x00510b57 in sub_510960
0x00511041 in sub_510960
0x005c2eae in sub_5C2AC0
```

IDA `disasm` reports all three as direct pushes of the same string address:

```text
0x00510b57: push offset aPal ; ".PAL"
0x00511041: push offset aPal ; ".PAL"
0x005c2eae: push offset aPal ; ".PAL"
```

Function context:

- `lookup_funcs 0x00510960`: `sub_510960`, size `0x9e7`; xrefs `0x00510b57` and `0x00511041` are inside this function.
- `analyze_function 0x00510960`: caller is `sub_507C90` at `0x00507ffa`; callee list includes `_wcscpy_s`, `_wcscat_s`, `MultiByteToWideChar`, and local helpers. The two `.PAL` sites append the suffix after map/resource base-name copies, proving a MapPane filename-construction use.
- `lookup_funcs 0x005c2ac0`: `sub_5C2AC0`, size `0x7ea`; xref `0x005c2eae` is inside this function.
- `analyze_function 0x005c2ac0`: callers are `sub_50F270` at `0x0050f2fa` and `sub_511DB0` at `0x005126f9`; the function installs the `WorldMapPane::vftable` and calls `sub_584470`, `sub_584540`, `sub_543D70`, `sub_582A90`, and `sub_582B70`. The `.PAL` use is inside WorldMapPane construction/resource initialization, not in PaletteLib.
- `analyze_function 0x00543d70`: broad palette-loader/lookup callee reached by many callers, including `sub_5C2AC0`; it consumes constructed names and does not directly reference `0x0061ea24`.

Search and negative IDA evidence:

- `find_bytes` for raw VA `24 ea 61 00` found exactly three `.text` hits: `0x00510b58`, `0x00511042`, and `0x005c2eaf`.
- `find_bytes` for `push imm32` form `68 24 ea 61 00` found exactly three `.text` hits: `0x00510b57`, `0x00511041`, and `0x005c2eae`.
- `find_bytes` for RVA `24 ea 21 00` found zero hits.
- `find_regex` for `.pdb|RSDS|NB10` found no debug/source-path metadata.
- `find_regex` for relevant class names finds RTTI/class names such as `MapPane`, `WorldMapPane`, and `PaletteLib`, but no source declaration metadata for this string.

## PE / Raw Evidence

Executable scanned: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

```text
MD5: 4247e04e20b65d6414c7238aa8ff5515
Image base: 0x400000
0x0061ea24 file offset: 0x21d424
Section: .rdata
```

Raw bytes at the target and neighboring child strings:

```text
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

Raw scan results:

- Wide `.PAL` plus terminator appears 119 times in `.rdata`; text uniqueness alone is not an owner signal.
- The exact VA immediate `24 ea 61 00` appears exactly three times, all in `.text`, matching the IDA refs.
- The exact `push 0x0061ea24` byte sequence appears exactly three times, all in `.text`, matching the IDA refs.
- The RVA form `24 ea 21 00` appears zero times.

This confirms the live IDA xref inventory and argues against hidden raw pointer tables, vtable slots, or extra consumers for this exact pooled string address.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea30` | [UID:0003JG] `SharedMapPaletteSuffixString` | Exact `L".PAL"` suffix literal | TRUE | `NONE` | `87/93` | Keep no canonical owner; add emitters `0000L3,0000PB` |
| `0x0061ea24-0x0061ea70` | [UID:0003IX] `MapWorldPaletteResourceStrings` | Split index over adjacent `.PAL` / `WM*` literals | FALSE | `NONE` | `90/very strong` | Correct non-emitting container |
| `0x0061ea30-0x0061ea48` | [UID:0003JH] `MapPaneWorldMapNameComparisonStrings` | `wm`, `WM`, `wm2` strings | TRUE | `0000L3` | `88/93` | MapPane-only sibling |
| `0x0061ea48-0x0061ea50` | [UID:0003JI] `SharedWorldMap2UpperString` | Shared `L"WM2"` string | TRUE | `NONE` | `87/93` | Similar shared-literal pattern; separate target |
| `0x0061ea50-0x0061ea70` | [UID:0003JJ] `MapPaneWorldMapNameThreeFourStrings` | `wm3`, `WM3`, `wm4`, `WM4` strings | TRUE | `0000L3` | `88/93` | MapPane-only sibling |
| `0x00510960` | `sub_510960` | MapPane resource/name helper | TRUE through MapPane model | [UID:0000L3] | by-file `89/85` | Proven emitter context |
| `0x005c2ac0` | [UID:0001O4] `WorldMapPane` constructor family | WorldMapPane construction/resource initialization | TRUE | [UID:0000PB] | `80/85`; by-file `90/86` | Proven emitter context |

## Documentation Evidence And IDA Status

Docs supporting the conclusion:

- `by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`. It states that pooled string literals/shared constants may keep `CANONICAL_OWNER:NONE` while using multiple emitters when multiple source-use contexts are proven. This directly fits 0003JG.
- The target page already documents exact bytes, `L".PAL"` decoding, direct refs from MapPane `sub_510960` and WorldMapPane `sub_5C2AC0`, and a blank owner because no single owner is proven. IDA MCP reconfirmed the material facts.
- The B001 executed report correctly rejected forced MapPane, forced WorldMapPane, Palette/PaletteLib, resource/DAT, and synthetic shared-source owners under the old combined parent model. That ownership reasoning remains valid, but the "no by-* documentation edit" conclusion is stale because current rules now support multi-emitter routing.
- [UID:0000L3] `by-file/MapPane.md` is a `CANONICAL_OWNER:FILE` source root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; it documents MapPane as the source owner for nearby map resource/name logic.
- [UID:0000PB] `by-file/WorldMapPane.md` is a `CANONICAL_OWNER:FILE` source root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; it documents `WorldMapPane.cpp` as separate from `MapPane.cpp` and includes the constructor range `0x005c2ac0-0x005c32aa`.
- [UID:0003IX] confirms the broader range is a non-emitting split index with exact children, not a source owner.

Docs that are stale or need follow-up:

- The target page's "Assignment Gate" says not to assign the child to MapPane or WorldMapPane. That remains true for `CANONICAL_OWNER`, but should be clarified to allow `EMITTER_UIDS:0000L3,0000PB`.
- The target page says "Parent: blank"; under current terminology that should become "canonical owner none; emitted through MapPane and WorldMapPane."
- The `by-memory/-coverage-report.md` row says "parent blank"; that should be replaced with a row that records no canonical owner but MapPane/WorldMapPane emitter routing.
- The generated report currently lists 0003JG in both no-owner/non-emits views because `EMITTER_UIDS` is blank.

## Ranked Ownership / Emitter Analysis

### 1. No canonical owner, emit through MapPane and WorldMapPane

- Evidence for: direct IDA xrefs split across two established source roots; raw PE search confirms exactly those three `push` references; by-structure explicitly supports `CANONICAL_OWNER:NONE` with multiple emitters for pooled/shared literals.
- Evidence against: no direct declaration/source file metadata proves where the original spelling appeared; generated C++ block is still blank.
- Decision: accept. This is the best current model. Use `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`, blank `EMITTER_POSITION_OPTIONAL`.

### 2. Force canonical owner to MapPane

- Evidence for: two of the three direct refs are in MapPane `sub_510960`; adjacent sibling strings 0003JH and 0003JJ are MapPane-only; [UID:0000L3] is a valid file root.
- Evidence against: `sub_5C2AC0` directly references the same literal inside WorldMapPane construction/resource initialization; WorldMapPane is documented as a separate `WorldMapPane.cpp` source module; xref count does not prove declaration ownership for pooled string data.
- Decision: reject as canonical owner. Accept MapPane only as one emitter route.

### 3. Force canonical owner to WorldMapPane

- Evidence for: `sub_5C2AC0` directly uses `.PAL` while constructing/loading world-map resources; [UID:0000PB] is a valid file root.
- Evidence against: MapPane has two independent direct uses in `sub_510960`; adjacent MapPane-only children prove the local island is not exclusively WorldMapPane-owned; WorldMapPane already has separate constructor-owned resource strings elsewhere.
- Decision: reject as canonical owner. Accept WorldMapPane only as one emitter route.

### 4. Assign to Palette / PaletteLib

- Evidence for: WorldMapPane later calls `sub_543D70`, a palette-loader/lookup function, after constructing a palette name.
- Evidence against: no direct `0x0061ea24` xrefs from PaletteLib functions; PaletteLib consumes completed palette names and owns palette management state, not caller-side suffix appends; raw pointer searches found only MapPane and WorldMapPane code refs.
- Decision: reject as owner and emitter.

### 5. Assign to `MapWorldPaletteResourceStrings` / split index 0003IX

- Evidence for: the exact child resides inside the 0003IX address island.
- Evidence against: 0003IX is deliberately `RECONSTRUCTABLE:FALSE` and mixes shared and MapPane-only children; it is an audit/split index, not source-level declaration ownership.
- Decision: reject as owner and emitter.

### 6. Create a new shared suffix/global owner

- Evidence for: `.PAL` is a common suffix and the binary contains many `.PAL` literals.
- Evidence against: no source/debug metadata names a shared suffix table/header; no coherent table of pointers or constants references this specific item; by-structure warns not to invent a standalone owner solely to avoid `NONE` for pooled/shared data.
- Decision: reject.

## Source-Use / Emitter Inventory

Emitter `0000L3` - [UID:0000L3] `by-file/MapPane.md`

- Source path: `NexusTK/map/`
- Candidate file: `map/MapPane.cpp`
- Evidence: `0x00510b57` and `0x00511041` in `sub_510960` push `0x0061ea24`; surrounding disassembly shows `_wcscpy_s` followed by `_wcscat_s`, appending `.PAL` to MapPane resource/palette base names.
- Reachability: `sub_510960` is called from `sub_507C90` at `0x00507ffa`, inside the documented MapPane dispatch/resource path.
- Decision: include in `EMITTER_UIDS`.

Emitter `0000PB` - [UID:0000PB] `by-file/WorldMapPane.md`

- Source path: `NexusTK/map/`
- Candidate file: `map/WorldMapPane.cpp`
- Evidence: `0x005c2eae` in `sub_5C2AC0` pushes `0x0061ea24`; `analyze_function` shows this function installs the `WorldMapPane::vftable`, initializes WorldMapPane resources, and then reaches palette-loading behavior through constructed names.
- Reachability: `sub_5C2AC0` has callers from `sub_50F270` and MapPane helper `sub_511DB0`, but the function body is a WorldMapPane constructor-family method. MapPane creating a WorldMapPane instance does not make MapPane the sole output route for literals used in the constructor body.
- Decision: include in `EMITTER_UIDS`.

Rejected emitter `0000MB` - [UID:0000MB] `by-file/PaletteLib.md`

- Evidence: PaletteLib is a real source root for palette loading and manager state, but the direct string refs stop before PaletteLib. `sub_543D70` receives a completed/constructed palette name and has no direct xref to `0x0061ea24`.
- Decision: do not include.

## Negative Evidence Summary

- No direct owner-only xref pattern exists. Both MapPane and WorldMapPane materially use the same address.
- No PDB, RSDS, NB10, source file path, or debug metadata names a single declaration owner for the literal.
- No raw RVA hits or extra raw VA pointer tables were found for `0x0061ea24`; the only exact raw code references are the three IDA xrefs.
- No vtable/table adjacency makes the target part of a class/static layout. It is a `.rdata` wide-string literal followed by other split string children.
- Palette/PaletteLib has no direct reference to the literal address. Downstream palette loading does not own caller-side filename suffix construction.
- The split index 0003IX is intentionally non-emitting and cannot serve as a source-level owner.
- Reclassifying to `RECONSTRUCTABLE:FALSE` would be wrong because the target is an exact source string literal, not a container or ignored artifact.

## Exact Required Changes

Update target metadata in `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `by-memory/-coverage-report.md` replacement row, at the current 0003JG child position under [UID:0003IX]:

```text
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; live IDA/raw PE confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner.
```

Optional target-page wording cleanup for a future documentation edit:

```text
Parent/routing: canonical owner none; emitted through [UID:0000L3][MapPane](by-file/MapPane.md) and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) because both source-use contexts directly reference the pooled `.PAL` literal.
```

No score change is required. The current `87/93` remains defensible: completion is below final because no final source spelling/code placement is written, while confidence is strong for exact bytes, split boundary, xrefs, and emitter inventory.

## Validation Notes

- No by-* files or generated coverage files were edited by B003 in this pass.
- No lease was required because this report was created inside the Agent-B003 research directory.
- No validator command was run because the task requested a post-migration research report and prohibited direct coverage-report edits; supervisor/normal workflow should apply metadata and regenerate/validate coverage.
- The report file was created at the assigned path: `tools/leaser/Agents/Agent-B003/research/0003JG-SharedMapPaletteSuffixString-post-migration.md`.

## Confidence

- Recommendation confidence: 91/100.
- Score confidence: keep current `87/93`; no independent score edit is recommended.
- Remaining uncertainty: the original source declaration form is still unknown. The literal might have appeared twice in source and been pooled by the compiler/linker, or it might have come from an included shared constant. That uncertainty blocks a single `CANONICAL_OWNER`, but it does not block emitter routing because the source-use contexts are direct and exact.

## Follow-Up Actions

- Supervisor or an authorized documentation agent should update the target metadata to `EMITTER_UIDS:0000L3,0000PB`.
- Apply the coverage-row replacement above or regenerate/refresh the row after metadata application.
- Consider a similar post-migration emitter recheck for sibling [UID:0003JI] `SharedWorldMap2UpperString`, which has the same no-owner/shared-literal shape with MapPane and WorldMapPane direct use.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0003JG-SharedMapPaletteSuffixString-post-migration.md`
- Modified: none outside Agent-B003 research.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B003/0003JG-SharedMapPaletteSuffixString-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
