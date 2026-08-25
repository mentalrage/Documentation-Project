** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# [UID:0003JG] SharedMapPaletteSuffixString Goal 2 Verification

## FINAL RECOMMENDATION

No change is recommended. Keep the current generated state for [UID:0003JG] `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000PB`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank
- retain score `87/93`
- no split, merge, reclassification, new child page, IDA repair, or documentation repair required

This is a valid no-owner-with-emitters case under the current owner/emitter model. Fresh IDA MCP and raw PE evidence prove that the exact UTF-16 `.PAL` suffix at `0x0061ea24` is materially used by both [UID:0000L3] `MapPane` and [UID:0000PB] `WorldMapPane`, while no current evidence proves a single original declaration owner. Keeping `CANONICAL_OWNER:NONE` avoids overclaiming source declaration ownership; keeping `EMITTER_UIDS:0000L3,0000PB` preserves the two proven source-use output routes.

No `by-memory/-coverage-report.md` replacement row is required. The current shared coverage row already records the correct no-owner/two-emitter result and does not need supervisor action.

---

## Supporting Research

## Target

- Target UID: `0003JG`
- Target path: `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current no-owner row for `0x0061ea24-0x0061ea30`
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active `2026-06-14 Goal 2 No-Owner Memory Verification Pass`, assigned to `Agent-B001`
- Prior report used as evidence only: `Agent-B002/research/executed/0003JG-SharedMapPaletteSuffixString-live-goal2-no-owner-pass.md`
- Current metadata: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, blank C++

## Rule Basis

Current `by-structure.md` separates semantic ownership from output routing:

- `CANONICAL_OWNER` is the direct semantic/source declaration owner.
- `EMITTER_UIDS` is generated-output routing, not an ownership claim.
- Pooled string literals and shared constants may keep `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while using multiple `EMITTER_UIDS` for proven source-use contexts.
- `source-declared/generated-binary` applies to string literals whose source-level presence must be recreated, but whose exact bytes are emitted by compiler/linker behavior.

That rule fits this target. The `.PAL` object is a literal/suffix source-use item, not a standalone recovered global declaration, and the two consumers are separate valid source roots.

## Current Documentation Checked

Target page `0003JG` currently documents:

- UTF-16 `.PAL` payload at `0x0061ea24-0x0061ea30`.
- `CANONICAL_OWNER:NONE` because the suffix is shared by MapPane and WorldMapPane construction paths.
- `EMITTER_UIDS:0000L3,0000PB` because both source roots have direct source-use evidence.

Generated coverage currently agrees:

- `auto-generated/-ag-memory-coverage.md` lists [UID:0003JG] as `no-owner`, canonical owner `NONE`, emitters `0000L3`,`0000PB`, no code, and generated output path under `auto-generated/NexusTK/map/MapPane.cpp`.
- `by-memory/-coverage-report.md` has the nested split-index row under [UID:0003IX], recording `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`, direct MapPane refs at `0x00510b57`/`0x00511041`, direct WorldMapPane ref at `0x005c2eae`, and no justified single owner.

Candidate roots checked:

- [UID:0000L3] `by-file/MapPane.md`: `89/85`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, `CANONICAL_OWNER:FILE`.
- [UID:0000PB] `by-file/WorldMapPane.md`: `90/86`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, `CANONICAL_OWNER:FILE`.
- [UID:0000MA] `by-file/Palette.md` and [UID:0000MB] `by-file/PaletteLib.md`: valid render/palette owners, but documentation describes palette manager policy, `g_pPaletteLib`, named palette loading, and slot/filter helpers rather than this exact map/world-map suffix literal.

Split and sibling pages checked:

| Item | Current role | Result for this pass |
| --- | --- | --- |
| [UID:0003IX] `0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings` | non-emitting split index over `.PAL`, `wm`/`WM`, `WM2`, `wm3`/`WM4` | keep as split index; no merge |
| [UID:0003JH] `0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings` | MapPane-only `wm`, `WM`, `wm2` | supports clean successor boundary |
| [UID:0003JI] `0x0061ea48-0x0061ea50.SharedWorldMap2UpperString` | shared `WM2`, same `NONE` plus `0000L3,0000PB` model | supports current shared-literal policy |
| [UID:0003JJ] `0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings` | MapPane-only `wm3`, `WM3`, `wm4`, `WM4` | supports no merge back into the full island |

Consumer pages checked:

- [UID:0001AW] `0x0050e4c0-0x00514920.MapPanePacketHandlers` documents `sub_510960` and `sub_511DB0` in the MapPane packet/helper family.
- [UID:0001O4] `0x005c2ac0-0x005c5c87.WorldMapPane` documents `sub_5C2AC0` as the WorldMapPane constructor-family implementation and `sub_5C5200` as a WorldMapPane helper.

## Fresh IDA MCP Evidence

IDA MCP session used:

- Session: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Status: active worker session, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

### Bytes And Strings

IDA `get_bytes` on `0x0061ea24` size `0x4c` confirmed the complete parent island:

```text
.PAL, wm, WM, wm2, WM2, wm3, WM3, wm4, WM4
```

IDA `get_bytes` on the target itself confirmed:

```text
2e 00 50 00 41 00 4c 00 00 00 00 00
```

This is UTF-16LE `.PAL`, a null terminator, and alignment. `0x0061ea30` begins the successor `wm` string, so the target's `0x0061ea24-0x0061ea30` half-open boundary is correct. Length `0x0c` is decimal `12` (verified with `int_convert.py`).

IDA `get_string` results:

| Address | Decoded string |
| --- | --- |
| `0x0061ea24` | `.PAL` |
| `0x0061ea30` | `wm` |
| `0x0061ea38` | `WM` |
| `0x0061ea40` | `wm2` |
| `0x0061ea48` | `WM2` |
| `0x0061ea50` | `wm3` |
| `0x0061ea58` | `WM3` |
| `0x0061ea60` | `wm4` |
| `0x0061ea68` | `WM4` |
| `0x0061ea70` | `%s\Mscfg.dll` |

### Function Lookup

IDA `lookup_funcs` confirmed:

| Query | Result |
| --- | --- |
| `0x00510960` | `sub_510960`, size `0x9e7` |
| `0x00510b57` | inside `sub_510960` |
| `0x00511041` | inside `sub_510960` |
| `0x00511db0` | `sub_511DB0`, size `0xa8a` |
| `0x005c2ac0` | `sub_5C2AC0`, size `0x7ea` |
| `0x005c2eae` | inside `sub_5C2AC0` |
| `0x005c5200` | `sub_5C5200`, size `0x1d0` |
| `0x0061ea24` | not a function |
| `0x0061ea30` | not a function |

### Xrefs

IDA `xrefs_to` confirmed exactly three direct xrefs to the target address:

| Address | Xrefs | Meaning |
| --- | --- | --- |
| `0x0061ea24` `.PAL` | `0x00510b57`, `0x00511041` in `sub_510960`; `0x005c2eae` in `sub_5C2AC0` | shared MapPane and WorldMapPane source-use |

Sibling xref profiles differ:

| Address | Xrefs | Meaning |
| --- | --- | --- |
| `0x0061ea30` `wm` | `0x005121a1` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea38` `WM` | `0x005121e3` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea40` `wm2` | `0x00512223` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea48` `WM2` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | separate shared sibling |
| `0x0061ea50` `wm3` | `0x005122a3` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea58` `WM3` | `0x005122e3` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea60` `wm4` | `0x00512323` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea68` `WM4` | `0x0051235f` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea70` `%s\Mscfg.dll` | `0x00508a42` in `sub_507C90`; raw `0x005142ba` | successor child |

### Instruction Evidence

Filtered IDA disassembly of `sub_510960` shows two MapPane uses:

```text
0x510b57 push offset aPal; ".PAL" refs=0x61ea24:aPal
0x510b68 call _wcscat_s
0x511041 push offset aPal; ".PAL" refs=0x61ea24:aPal
0x511052 call _wcscat_s
```

Hex-Rays for `sub_510960` confirms these are wide-string path construction uses, appending `L".PAL"` after copying the map/resource name.

Filtered IDA disassembly of `sub_5C2AC0` shows the WorldMapPane use:

```text
0x5c2eae push offset aPal; ".PAL" refs=0x61ea24:aPal
0x5c2ebf call sub_584470
0x5c2ed4 call sub_543D70
```

Hex-Rays for `sub_5C2AC0` confirms this path appends `L".PAL"` to a WorldMapPane resource/name value and passes the resulting wide string into the palette/resource load path.

Filtered IDA disassembly also confirms the separate shared sibling `WM2` route:

```text
0x5c5219 push offset aWm2_0; "WM2" refs=0x61ea48:aWm2_0
```

That supports the existing split: `.PAL` and `WM2` are shared children, while the surrounding comparison strings are not.

### Component Evidence

IDA `analyze_component` over `0x00510960`, `0x00511db0`, `0x005c2ac0`, and `0x005c5200` reported:

- `0x0061ea24` / `aPal` accessed by `sub_510960` and `sub_5C2AC0`.
- `0x0061ea48` / `aWm2_0` accessed by `sub_511DB0` and `sub_5C5200`.
- Internal call edge `sub_511DB0 -> sub_5C2AC0`.

The call edge proves MapPane can create/drive WorldMapPane, but it does not make the WorldMapPane constructor-family implementation MapPane-owned. It supports the two-source-context model rather than collapsing both uses into a single owner.

## Fresh PE Evidence

Raw PE scan target:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Imagebase: `0x00400000`
- `.rdata` maps raw `0x20ba00-0x26ac00` to RVA `0x20d000-0x26c200`
- Target VA range: `0x0061ea24-0x0061ea30`
- Target file offset: `0x21d424`
- Parent island range: `0x0061ea24-0x0061ea70`
- Parent island length `0x4c` is decimal `76` (verified with `int_convert.py`)

PE byte scan results:

- The full parent island byte sequence `.PAL, wm, WM, wm2, WM2, wm3, WM3, wm4, WM4` occurs exactly once, at file offset `0x21d424` / VA `0x0061ea24`.
- The standalone `.PAL` target bytes occur 69 times in the executable, so physical `.PAL` byte repetition is not ownership evidence by itself.
- The exact target VA immediate `0x0061ea24` occurs exactly three times, mapping to operand VAs `0x00510b58`, `0x00511042`, and `0x005c2eaf`. These match IDA's instruction-start xrefs at `0x00510b57`, `0x00511041`, and `0x005c2eae`.
- The target RVA immediate `0x0021ea24` has zero hits.

PE scan of embedded debug/source breadcrumbs found:

- `RSDS`: zero hits
- `NB10`: zero hits
- `.pdb`: zero hits
- `.cpp`: zero hits

So current binary evidence does not provide a PDB/source-file declaration owner for the pooled suffix.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` With `EMITTER_UIDS:0000L3,0000PB`

Evidence for:

- IDA proves the same physical `aPal` object is used in `sub_510960` and `sub_5C2AC0`.
- Current docs place `sub_510960` in the MapPane source context and `sub_5C2AC0` in the WorldMapPane source context.
- Both emitter roots clear the source-root gate and have valid `NexusTK/map/` reconstruction paths.
- `by-structure.md` explicitly allows `CANONICAL_OWNER:NONE` plus multiple emitters for pooled literals/shared constants when no single declaration owner is proven.

Evidence against:

- There is no source/debug metadata proving how the original source declared or pooled this literal.

Decision: accept. This is the best current model.

### 2. Canonical Owner [UID:0000L3] `MapPane`

Evidence for:

- MapPane has two direct target xrefs in `sub_510960`.
- MapPane has adjacent MapPane-only strings in this same `.rdata` island.
- `sub_511DB0` can call `sub_5C2AC0`, so MapPane is part of the world-map creation route.

Evidence against:

- WorldMapPane has a direct target xref in its constructor-family function `sub_5C2AC0`.
- MapPane's creation relationship to WorldMapPane does not make WorldMapPane implementation literals MapPane declarations.
- Assigning MapPane as canonical owner would overclaim the shared physical object and ignore the material WorldMapPane use.

Decision: reject as canonical owner; keep as emitter.

### 3. Canonical Owner [UID:0000PB] `WorldMapPane`

Evidence for:

- WorldMapPane directly uses `.PAL` to load/derive palette resource data in `sub_5C2AC0`.
- The suffix is semantically meaningful for world-map resource loading.

Evidence against:

- MapPane has two direct refs in `sub_510960`, using the same physical object for MapPane-side resource path construction.
- WorldMapPane-only ownership would lose the MapPane source-use evidence.

Decision: reject as canonical owner; keep as emitter.

### 4. Canonical Owner [UID:0000MA]/[UID:0000MB] `Palette` / `PaletteLib`

Evidence for:

- The target suffix names a `.PAL` palette resource extension.
- `PaletteLib` owns palette manager policy, named palette loading, `g_pPaletteLib`, palette slot data, and palette filter helpers.

Evidence against:

- Fresh IDA `xrefs_to 0x0061ea24` found no Palette/PaletteLib refs.
- The target is appended by MapPane and WorldMapPane before the resulting name reaches the palette/resource loading path.
- PaletteLib ownership would confuse a consumer-provided filename suffix with palette manager implementation data.

Decision: reject.

### 5. Canonical Owner [UID:0003IX] Split Index

Evidence for:

- The split-index physically covers the target and siblings.

Evidence against:

- [UID:0003IX] is explicitly a non-reconstructable documentation split index, not a source declaration owner or generated output root.
- Its children have different owner/emitter profiles.

Decision: reject.

### 6. New Shared Constants / Map Palette Resource File

Evidence for:

- The `.PAL` suffix is shared by two source roots.

Evidence against:

- No PDB/source path, unique global declaration, initializer table, source-tree entry, or xref cluster proves a standalone shared constants file.
- `by-structure.md` warns not to invent a standalone global/helper file solely to avoid `NONE`.

Decision: reject.

## Split / Merge / Reclassification Analysis

No split is needed. The target already isolates the `.PAL` UTF-16 literal, null terminator, and alignment over `0x0061ea24-0x0061ea30`.

No merge is needed. The successor children have distinct xref profiles:

- `0x0061ea30-0x0061ea48` is MapPane-only.
- `0x0061ea48-0x0061ea50` is a separate shared `WM2` child.
- `0x0061ea50-0x0061ea70` is MapPane-only.
- `0x0061ea70` starts the successor `%s\Mscfg.dll` child.

No reclassification is needed. This is source-declared/generated-binary string data and should remain `RECONSTRUCTABLE:TRUE`.

No IDA repair is required for the target. Current IDA function and xref modeling is sufficient to prove both source-use routes.

## C++ Body Decision

Leave `RECONSTRUCTION_CPP CODE` blank. Although the target has valid emitters and clears the minimum score/emitter gate, a standalone code body for this page would likely invent a shared declaration such as a global/static constant. Current evidence supports source-use routing, not a unique original declaration form.

The safest current source shape is that the final rewritten MapPane and WorldMapPane code will contain the relevant wide string literal uses in context. This page should continue to document and route the pooled literal rather than emit an artificial declaration.

## Final Recommendation

Exact changes applied:

- Created this Agent-B001 research report only.

Exact metadata recommended:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Exact coverage-report action:

- No `by-memory/-coverage-report.md` edit is needed.
- No replacement or insertion text is pending for the supervisor.

No project documentation files need editing for this target beyond this research report.

## Validation And Execution Notes

- No dry runs were used.
- No leases were required because no shared `by-*`, generated, project-level, tracker, or coverage files were edited.
- Validator was not run because this is report-only verification and no validator-managed documentation page changed.
- `int_convert.py` was used to verify `0x0c` -> decimal `12`, `0x4c` -> decimal `76`, and `0x2710` -> decimal `10000`.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B001/research/0003JG-SharedMapPaletteSuffixString-goal2-verification.md
```

Modified:

```text
none
```

## Confidence

Recommendation confidence: high.

The use routes are proven by independent IDA xrefs, disassembly, decompilation context, component analysis, and raw PE operand scans. The remaining uncertainty is only original source declaration ownership, and current rules explicitly support `CANONICAL_OWNER:NONE` with multiple emitters for that situation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B001/0003JG-SharedMapPaletteSuffixString-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
