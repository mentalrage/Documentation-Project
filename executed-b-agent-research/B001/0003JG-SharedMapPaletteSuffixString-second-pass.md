** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# B001-0003JG Second-Pass Ownership/Emitter Report

## Final Recommendation

Keep UID `0003JG` exactly as the current no-owner-with-emitters item:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
```

Score recommendation: keep `COMPLETION:87` and `CONFIDENCE:93`. No score change is justified by this second pass.

This is a valid owner/emitter split case, not a stale no-owner/non-emitting item. The `.PAL` wide suffix at `0x0061ea24` is a pooled/shared source literal. Live IDA evidence shows direct source-use references from both the MapPane family and the WorldMapPane family, while no evidence proves a single semantic declaration/source owner. Under the current by-structure rules, `CANONICAL_OWNER:NONE` is appropriate, and `EMITTER_UIDS:0000L3,0000PB` is the correct output route.

No split, merge, reclassification, IDA repair, parent repair, or coverage-report edit is recommended.

## Supervisor Actions Required

No by-memory metadata edit is required.

No `by-memory/-coverage-report.md` edit is required. The current row should remain unchanged:

```markdown
- [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; live IDA/raw PE confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner.
```

## Scope

Target:

```text
UID: 0003JG
Path: by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md
Range: 0x0061ea24-0x0061ea30
Current state: CANONICAL_OWNER:NONE, EMITTER_UIDS:0000L3,0000PB, RECONSTRUCTABLE:TRUE
```

Read as workflow/rule context:

- `tools/leaser/Agents/Agent-B001/goal.md`
- `by-structure.md`
- `inference_research.md`
- Prior report: `tools/leaser/Agents/Agent-B003/research/executed/0003JG-SharedMapPaletteSuffixString-post-migration.md`
- Earlier historical report: `tools/leaser/Agents/Agent-B001/research/executed/0003JG-SharedMapPaletteSuffixString.md`

Read as project documentation evidence:

- `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md`
- `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- `by-file/MapPane.md`
- `by-file/WorldMapPane.md`
- `by-file/PaletteLib.md`
- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`
- `by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- `tools/leaser/Agents/no_owner_b-agent-tracker.md`

## Rule Basis

Facts from current by-structure rules:

- String literals are `source-declared/generated-binary` artifacts when source-use contexts are proven.
- `CANONICAL_OWNER` records semantic ownership.
- `EMITTER_UIDS` records source-output routing and may contain multiple comma-separated UIDs.
- Pooled/shared literals may validly remain `CANONICAL_OWNER:NONE` when no single declaration/source owner is proven.
- Reconstructable ownerless items should still have emitters when their source uses need output.
- A standalone synthetic owner should not be invented just to avoid `NONE`.

Inference applied here:

- Because the target is a single pooled suffix literal used from two separately documented map source families, semantic ownership and emission routing must remain separated.
- The current item is reconstructable because the literal and its source-use contexts are clear, but it is not semantically owned by one of those contexts.

## IDA MCP Evidence

IDA MCP state:

```text
Input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
Imagebase: 0x00400000
Auto-analysis: ready
Hex-Rays: ready
```

### Target Bytes

`get_bytes(0x0061ea24, 0x4c)` confirms the split-index neighborhood:

```text
0x0061ea24: 2e 00 50 00 41 00 4c 00 00 00 00 00 77 00 6d 00 00 00 00 00
0x0061ea38: 57 00 4d 00 00 00 00 00 77 00 6d 00 32 00 00 00 57 00 4d 00
0x0061ea4c: 32 00 00 00 77 00 6d 00 33 00 00 00 57 00 4d 00 33 00 00 00
0x0061ea60: 77 00 6d 00 34 00 00 00 57 00 4d 00 34 00 00 00
```

`get_string` confirms:

| Address | String | Interpretation |
|---|---:|---|
| `0x0061ea24` | `.PAL` | Target suffix literal |
| `0x0061ea30` | `wm` | MapPane-only sibling |
| `0x0061ea38` | `WM` | MapPane-only sibling |
| `0x0061ea40` | `wm2` | MapPane-only sibling |
| `0x0061ea48` | `WM2` | Shared MapPane/WorldMapPane sibling |
| `0x0061ea50` | `wm3` | MapPane-only sibling |
| `0x0061ea58` | `WM3` | MapPane-only sibling |
| `0x0061ea60` | `wm4` | MapPane-only sibling |
| `0x0061ea68` | `WM4` | MapPane-only sibling |

### Direct Xrefs To Target

`xrefs_to(0x0061ea24)` returns exactly these direct code references:

| Address | Function | Evidence |
|---|---|---|
| `0x00510b57` | `sub_510960` | `push offset aPal ; ".PAL"` |
| `0x00511041` | `sub_510960` | `push offset aPal ; ".PAL"` |
| `0x005c2eae` | `sub_5C2AC0` | `push offset aPal ; ".PAL"` |

`search_text("aPal")` over the relevant code ranges independently locates the same three pushes and no additional target-address users in those ranges.

Function identity from `lookup_funcs`:

| Address | IDA Function | Documentation Route |
|---|---|---|
| `0x00510960` | `sub_510960` | MapPane packet/map helper family |
| `0x00511db0` | `sub_511DB0` | MapPane object-create/world-map bridge |
| `0x005c2ac0` | `sub_5C2AC0` | WorldMapPane constructor/resource initialization family |
| `0x005c5200` | `sub_5C5200` | WorldMapPane helper family |
| `0x00543d70` | `sub_543D70` | PaletteLib loaded-palette lookup helper |

`analyze_component` confirms the internal graph edge `sub_511DB0 -> sub_5C2AC0` and `sub_5C2AC0 -> sub_543D70`. That proves WorldMapPane construction can be reached from MapPane code, but does not make WorldMapPane implementation part of MapPane ownership.

### Adjacent String Xrefs

Live sibling xrefs support the existing split:

| String | Address | Direct Uses |
|---|---:|---|
| `.PAL` | `0x0061ea24` | MapPane `sub_510960` twice; WorldMapPane `sub_5C2AC0` once |
| `wm` | `0x0061ea30` | MapPane `sub_511DB0` |
| `WM` | `0x0061ea38` | MapPane `sub_511DB0` |
| `wm2` | `0x0061ea40` | MapPane `sub_511DB0` |
| `WM2` | `0x0061ea48` | MapPane `sub_511DB0`; WorldMapPane `sub_5C5200` |
| `wm3` | `0x0061ea50` | MapPane `sub_511DB0` |
| `WM3` | `0x0061ea58` | MapPane `sub_511DB0` |
| `wm4` | `0x0061ea60` | MapPane `sub_511DB0` |
| `WM4` | `0x0061ea68` | MapPane `sub_511DB0` |

This pattern does not support merging the whole range into one reconstructable owner. The index contains mixed use: shared entries and MapPane-only entries.

### PaletteLib Check

`analyze_function(0x00543d70)` shows `sub_543D70` takes a `wchar_t *Source`, compares it against loaded palette names, and calls a loader helper when absent. It does not reference `0x0061ea24` and does not construct the `.PAL` suffix itself.

Inference:

- PaletteLib is a downstream consumer of constructed palette names.
- PaletteLib is not the declaration owner or emitter for this specific literal.

### Source/Debug Metadata Search

IDA MCP searches for source breadcrumbs did not find usable stripped-source metadata:

```text
find_regex("(?i)\\.pdb|RSDS|NB10|\\.cpp|\\.cxx|\\.h") -> no matches
```

Inference:

- There is no debug/source path evidence that would promote the literal into a single file owner or a synthetic shared constants source.

## Raw PE Evidence

Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Item | Result |
|---|---|
| Image base | `0x00400000` |
| Target section | `.rdata` |
| Target file offset | `0x21d424-0x21d430` |
| Target bytes | `2e 00 50 00 41 00 4c 00 00 00 00 00` |
| Wide `.PAL` terminator occurrences | `119` |
| Target exact address push occurrences | `3` |
| Target VA immediate occurrences | `3` |
| Target RVA immediate occurrences | `0` |
| Rel32 references to target | none |

Facts:

- The textual suffix `.PAL` is common in the binary.
- The specific pooled address `0x0061ea24` has only the three direct code references already identified by IDA: `0x00510b57`, `0x00511041`, and `0x005c2eae`.

Inference:

- Text uniqueness cannot prove source ownership.
- Exact address use is still enough to prove emitter/source-use contexts for MapPane and WorldMapPane.

## Documentation Evidence

### Target Page

`by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` already states:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000PB`
- Direct refs from MapPane `sub_510960` and WorldMapPane `sub_5C2AC0`

This second pass independently confirms those facts.

### MapPane

`by-file/MapPane.md`:

- UID `0000L3`
- File root for `NexusTK/map/MapPane.cpp`
- Documents MapPane map/object/resource handling.
- Includes the shared `.PAL` suffix and `WM2` strings as parentless shared children with emitter routing.

`by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` documents the MapPane-side code range containing `sub_510960` and `sub_511DB0`.

Inference:

- MapPane is a proven emitter because MapPane code directly references the target literal at `0x00510b57` and `0x00511041`.
- MapPane is not a canonical owner because WorldMapPane code also directly references the same physical literal.

### WorldMapPane

`by-file/WorldMapPane.md`:

- UID `0000PB`
- File root for `NexusTK/map/WorldMapPane.cpp`
- Documents a separate WorldMapPane implementation from MapPane.

`by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md` identifies the WorldMapPane constructor/resource family, including `sub_5C2AC0`.

`by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md` documents a separate WorldMapPane-local resource-string block.

Inference:

- WorldMapPane is a proven emitter because `sub_5C2AC0` directly references the target literal at `0x005c2eae`.
- WorldMapPane is not a canonical owner because MapPane code also directly references the same physical literal.

### PaletteLib

`by-file/PaletteLib.md` documents the palette manager and loaded-palette lookup behavior. It does not document direct ownership of caller-side map resource suffix literals.

Inference:

- PaletteLib is relevant dependency context only.
- It should not be added as `CANONICAL_OWNER` or `EMITTER_UIDS` for UID `0003JG`.

## Source-Use / Emitter Inventory

| Candidate Emitter | UID | Status | Reason |
|---|---:|---|---|
| MapPane | `0000L3` | Keep | Direct address references in MapPane `sub_510960` at `0x00510b57` and `0x00511041`; source output route `NexusTK/map/MapPane.cpp` |
| WorldMapPane | `0000PB` | Keep | Direct address reference in WorldMapPane constructor/resource function `sub_5C2AC0` at `0x005c2eae`; source output route `NexusTK/map/WorldMapPane.cpp` |
| PaletteLib | `0000MB` | Reject | No direct xref to the literal; receives completed palette names downstream |
| Split index parent `0003IX` | none | Reject | Non-reconstructable index page over mixed children; not an output emitter |

## Ranked Ownership Routes

1. `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB` - selected.
   - Best matches the current owner/emitter model.
   - Separates semantic ownership from source-output routing.
   - Preserves both proven source-use contexts.

2. Canonical owner `0000L3` MapPane - rejected.
   - MapPane has two direct references, but direct use count does not prove declaration ownership.
   - WorldMapPane has an independent direct reference from a separately documented source family.
   - Making MapPane the owner would overclaim a literal physically shared with WorldMapPane.

3. Canonical owner `0000PB` WorldMapPane - rejected.
   - WorldMapPane has a direct constructor/resource use, but MapPane has two independent direct references.
   - Adjacent sibling strings are mixed and several are MapPane-only, which weakens a WorldMapPane ownership claim.

4. Canonical owner or emitter `0000MB` PaletteLib - rejected.
   - PaletteLib is downstream of callers that already constructed names.
   - No direct literal reference or source declaration evidence.

5. Synthetic shared constants owner - rejected.
   - No source/debug metadata, table abstraction, or documented source unit proves a shared constants declaration.
   - by-structure warns against inventing owners solely to avoid `NONE`.

## Split / Merge / Repair Decision

No split is recommended:

- The target page already covers exactly the `.PAL` wide string plus terminator/alignment from `0x0061ea24-0x0061ea30`.
- The next string starts at `0x0061ea30`.
- The broader `0003IX` range is already a non-reconstructable split index over mixed resource strings.

No merge is recommended:

- The adjacent siblings have different xref sets and different ownership/emitter semantics.
- `0003JI` is a comparable shared MapPane/WorldMapPane literal, but it has distinct string content and distinct direct users.

No reclassification is recommended:

- The item is source-declared/generated-binary string data, not compiler-generated padding-only data.
- The literal is used by reconstructable code paths.

No IDA repair is recommended:

- IDA string boundaries match the page range.
- Direct xrefs and function boundaries are consistent with current documentation.

No parent/source repair is required:

- The MapPane and WorldMapPane file roots are already documented at sufficient confidence for emitter routing.
- The index page correctly remains non-reconstructable rather than pretending to be a source file.

## Score / Coverage Effects

Before:

```text
COMPLETION:87
CONFIDENCE:93
CANONICAL_OWNER:NONE
EMITTER_UIDS:0000L3,0000PB
RECONSTRUCTABLE:TRUE
```

After recommendation:

```text
COMPLETION:87
CONFIDENCE:93
CANONICAL_OWNER:NONE
EMITTER_UIDS:0000L3,0000PB
RECONSTRUCTABLE:TRUE
```

No coverage score change is recommended. The current generated state is not a problem to reduce; it is the expected representation for a reconstructable pooled literal with multiple proven source-use emitters and no single semantic declaration owner.

## Validation Notes

Validation performed:

- Live IDA MCP evidence checks:
  - `server_health`
  - `get_bytes`
  - `get_string`
  - `xrefs_to`
  - `lookup_funcs`
  - `analyze_component`
  - `analyze_function`
  - `search_text`
  - `find_regex`
  - `find_bytes`
- Read-only raw PE scan of the target bytes and address references.
- Documentation cross-check against current target, parent/index, MapPane, WorldMapPane, PaletteLib, generated coverage, and tracker files.

No project validator was run because this task creates only this B-agent research report and recommends no by-* metadata edits. No dry-run validator or memory-range mode was used.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B001/research/0003JG-SharedMapPaletteSuffixString-second-pass.md
```

No by-memory, by-file, generated, tracker, or coverage-report files were edited.

## Blockers

None.

## Confidence

High. The exact target address has only three direct code references in the raw binary and live IDA, and those references fall cleanly into the two current emitter families. The absence of source/debug metadata prevents a single canonical owner claim, while the direct xrefs make both emitters justified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B001/0003JG-SharedMapPaletteSuffixString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
