** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) unchanged as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000PB`.
- Final disposition: valid no-owner-with-emitters pooled/shared UTF-16 literal. The `.PAL` suffix is source-authored and reconstructable, but no single semantic declaration owner is proven.
- Required action: no by-memory metadata change, no split, no merge, no reclassification, no PaletteLib owner, no new shared constants owner, no coverage-report replacement, and no reconstruction C++.
- Confidence: `93/100` for the no-owner-with-emitters disposition. The direct source-use routes are very strong; the remaining uncertainty is only original source declaration style.

## Supporting Research

## Target

- Target UID: `0003JG`.
- Target path: `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner row lists owner `NONE`, emitters ``0000L3`,`0000PB``, and first surfaced output path `auto-generated/NexusTK/map/MapPane.cpp`.
- Current supervisor classification: Goal 2 current no-owner memory pass; recheck whether no-owner with emitters remains correct.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B001/research/executed/0003JG-SharedMapPaletteSuffixString-second-pass.md`.
- Current scores and parent state: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`.

## Executive Recommendation

Keep the target exactly as-is. Live IDA and raw PE evidence prove the physical `.rdata` address `0x0061ea24` is referenced from two current source-use families:

- `0000L3` / [MapPane](by-file/MapPane.md): `sub_510960` has two direct `.PAL` address uses at `0x00510b57` and `0x00511041`.
- `0000PB` / [WorldMapPane](by-file/WorldMapPane.md): `sub_5C2AC0` has one direct `.PAL` address use at `0x005c2eae`.

Do not promote either source family to canonical owner. MapPane has more refs, but use count is not source declaration ownership. WorldMapPane has the semantically obvious constructor/resource use, but MapPane has independent direct uses of the same physical address. PaletteLib is a downstream lookup/loader that receives constructed palette names and does not directly reference this literal. The correct by-structure representation remains `CANONICAL_OWNER:NONE` with both proven emitter UIDs.

## Supervisor Active Recheck

- Supervisor instruction: recheck the current by-memory page, generated coverage rows, related emitter files/classes, and live IDA MCP evidence; decide whether the current no-owner-with-emitters state is still correct.
- Split repair required before final report: no. The target already covers exactly the `.PAL` UTF-16 string plus terminator/alignment at `0x0061ea24-0x0061ea30`; the next string begins at `0x0061ea30`.
- Direct in-scope doc repair required: no. The target metadata, emitter set, and split-index state match current evidence.
- Lease status: no lease was acquired because no file outside the B003 research folder was edited.

## Inference Research Guidance Check

- `by-structure.md` separates semantic ownership from generated-output routing. `CANONICAL_OWNER` must be the direct semantic owner; `EMITTER_UIDS` may contain multiple output routes.
- `by-structure.md` permits `CANONICAL_OWNER:NONE` with multiple emitters for compiler/linker-pooled string literals or shared constants when no single declaration owner is proven but independent source-use contexts are proven.
- `inference_research.md` warns that `.rdata` adjacency, consumer refs, and string pooling are not enough to infer original source ownership. This pass therefore used exact xrefs, function containment, caller/callee relationships, sibling string xref patterns, raw PE reference forms, and negative source/debug evidence.
- Existing docs were treated as leads: the target page, B001 prior report, MapPane, WorldMapPane, PaletteLib, and the split-index page were checked against current IDA/PE facts rather than accepted as authority.

## Evidence Standards Used

- IDA MCP current session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready.
- IDA MCP tools used successfully: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_string`, `xrefs_to`, `analyze_component`, `analyze_function`, `decompile`, `find_regex`, and `find_bytes`.
- Raw PE evidence: section mapping, UTF-16LE bytes, string occurrence counts, exact VA immediate scan, RVA negative scan, rel32 negative scan, and instruction-byte windows around the three target-address pushes.
- Documentation evidence: current target, split-index and sibling pages, MapPane and WorldMapPane file roots, PaletteLib file root, generated memory coverage, by-memory coverage, and proposed source-tree notes.
- Evidence strength: strong enough to keep both emitters and reject canonical owner candidates; no evidence supports a split or new source owner.

## IDA MCP Facts

- `server_health`: status `ok`, module `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready.
- `lookup_funcs` maps `0x00510960`, `0x00510b57`, and `0x00511041` to `sub_510960`, size `0x9e7`.
- `lookup_funcs` maps `0x00511db0` to `sub_511DB0`, size `0xa8a`.
- `lookup_funcs` maps `0x005c2ac0` and `0x005c2eae` to `sub_5C2AC0`, size `0x7ea`.
- `lookup_funcs` maps `0x005c5200` and `0x005c5219` to `sub_5C5200`, size `0x1d0`.
- `lookup_funcs` maps `0x00543d70` to `sub_543D70`, size `0xce`.
- `lookup_funcs` reports `0x0061ea24`, `0x0061ea30`, and `0x0061ea48` are not functions.
- `get_bytes 0x0061ea24 size 0x4c` returns the exact UTF-16LE sequence `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4`.
- `get_string` decodes `0x0061ea24` as `.PAL`, `0x0061ea30` as `wm`, `0x0061ea38` as `WM`, `0x0061ea40` as `wm2`, `0x0061ea48` as `WM2`, `0x0061ea50` as `wm3`, `0x0061ea58` as `WM3`, `0x0061ea60` as `wm4`, `0x0061ea68` as `WM4`, and successor `0x0061ea70` as `%s\Mscfg.dll`.
- `xrefs_to 0x0061ea24` returns exactly three data refs: `0x00510b57` in `sub_510960`, `0x00511041` in `sub_510960`, and `0x005c2eae` in `sub_5C2AC0`.
- `find_bytes "24 EA 61 00"` returns exactly `0x00510b58`, `0x00511042`, and `0x005c2eaf`, the immediate operand bytes for the three target-address pushes.
- `xrefs_to 0x00510960` returns caller `0x00507ffa` in `sub_507C90`, tying the MapPane-side helper into the MapPane packet/handler family.
- `xrefs_to 0x005c2ac0` returns callers `0x0050f2fa` in `sub_50F270` and `0x005126f9` in `sub_511DB0`, tying WorldMapPane construction to world-map creation/show paths while keeping implementation ownership separate.
- `analyze_component` over `0x00510960`, `0x00511db0`, `0x005c2ac0`, `0x005c5200`, and `0x00543d70` reports shared global `0x0061ea24` / `aPal` accessed by `sub_510960` and `sub_5C2AC0`.
- The same component analysis reports shared global `0x0061ea48` / `aWm2_0` accessed by `sub_511DB0` and `sub_5C5200`, supporting the existing split-index model where some siblings are shared and others are MapPane-only.
- Component internal edges include `sub_511DB0 -> sub_5C2AC0` and `sub_5C2AC0 -> sub_543D70`. This proves MapPane can create/use WorldMapPane and WorldMapPane calls PaletteLib lookup, but it does not collapse either implementation into the other owner.
- `decompile 0x005c2ac0` shows WorldMapPane constructor/resource code appending `L".PAL"` to a built string, passing the result to `sub_543D70`, and storing the palette index. This is a WorldMapPane source-use route for the suffix, not PaletteLib ownership of the suffix.
- `analyze_function 0x00543d70` reports prototype `int __thiscall(int this, wchar_t *Source)`, callee `sub_5431C0`, and no direct target string/global refs. This supports PaletteLib as a downstream loaded-palette lookup helper rather than the declaration owner for this literal.
- `find_regex '(?i)\.pdb|RSDS|NB10|\.cpp|\.cxx|\.h'` returns no matches; no embedded source/debug path evidence was found.

## Raw PE Facts

- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE image base: `0x00400000`, machine `0x014c`, four sections.
- `.text`: `0x00401000-0x0060c600`, raw `0x400+0x20b600`, virtual size `0x20b4ac`.
- `.rdata`: `0x0060d000-0x0066c200`, raw `0x20ba00+0x5f200`, virtual size `0x5f0be`.
- Target mapping: `0x0061ea24-0x0061ea30` maps to `.rdata` file offsets `0x21d424-0x21d430`, length `0x0c`.
- Target bytes: `2e 00 50 00 41 00 4c 00 00 00 00 00`, decoded as UTF-16LE `.PAL` plus two zero words.
- The neighborhood decodes to `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`.
- The 12-byte target byte pattern appears `69` times in the PE; the wide `.PAL` string with terminator appears `119` times. This confirms textual suffix reuse is common and cannot prove source ownership.
- The adjacent `wm` string appears once at `0x0061ea30`, `WM2` appears once at `0x0061ea48`, and the successor `%s\Mscfg.dll` appears once at `0x0061ea70`.
- Exact target VA `0x0061ea24` appears in `.text` only as absolute immediate bytes at `0x00510b58`, `0x00511042`, and `0x005c2eaf`.
- No RVA-form or rel32-to-target references to `0x0061ea24` were found in `.text`.
- Instruction-byte windows show push/immediate form at all three sites:
  - `0x00510b55`: `0b 00 68 24 ea 61 00 8d`
  - `0x0051103f`: `0b 00 68 24 ea 61 00 8d`
  - `0x005c2eac`: `6a 04 68 24 ea 61 00 8d`

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea30` | `0003JG` target | Shared UTF-16 `.PAL` palette suffix | `TRUE` | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000L3,0000PB` | `87/93` | Keep unchanged. |
| `0x0061ea24-0x0061ea70` | [UID:0003IX][MapWorldPaletteResourceStrings](by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) | Non-emitting split index over `.PAL` and `WM*` strings | `FALSE` | none | `90/93` | Correct parent/index; no merge. |
| `0x0061ea30-0x0061ea48` | [UID:0003JH][MapPaneWorldMapNameComparisonStrings](by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) | MapPane-only `wm`, `WM`, `wm2` strings | `TRUE` | `0000L3` | `88/93` | Sibling supports split. |
| `0x0061ea48-0x0061ea50` | [UID:0003JI][SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | Shared `WM2` string | `TRUE` | `NONE`; emitters `0000L3,0000PB` | `87/93` | Sibling precedent for shared routing. |
| `0x0061ea50-0x0061ea70` | [UID:0003JJ][MapPaneWorldMapNameThreeFourStrings](by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) | MapPane-only `wm3`, `WM3`, `wm4`, `WM4` strings | `TRUE` | `0000L3` | `88/93` | Sibling supports split. |
| `0x00510960` | `sub_510960` | MapPane helper using `.PAL` twice | code | MapPane source-use route | n/a | Supports emitter `0000L3`. |
| `0x005c2ac0` | [UID:0001O4][WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) | WorldMapPane constructor/resource family using `.PAL` | `TRUE` | `0000PB` | documented under WorldMapPane | Supports emitter `0000PB`. |
| `0x00543d70` | PaletteLib loaded-palette lookup helper | Receives constructed palette name | code | PaletteLib source family | n/a | Rejected as owner/emitter for target literal. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061ea24` | `0x00510b57` in `sub_510960` | MapPane direct `.PAL` source use. |
| `0x0061ea24` | `0x00511041` in `sub_510960` | Second MapPane direct `.PAL` source use. |
| `0x0061ea24` | `0x005c2eae` in `sub_5C2AC0` | WorldMapPane direct `.PAL` source use. |
| `0x0061ea30` | `0x005121a1` in `sub_511DB0` | `wm` sibling is MapPane-only. |
| `0x0061ea38` | `0x005121e3` in `sub_511DB0` | `WM` sibling is MapPane-only. |
| `0x0061ea40` | `0x00512223` in `sub_511DB0` | `wm2` sibling is MapPane-only. |
| `0x0061ea48` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | `WM2` sibling is shared by MapPane and WorldMapPane. |
| `0x0061ea50` | `0x005122a3` in `sub_511DB0` | `wm3` sibling is MapPane-only. |
| `0x0061ea58` | `0x005122e3` in `sub_511DB0` | `WM3` sibling is MapPane-only. |
| `0x0061ea60` | `0x00512323` in `sub_511DB0` | `wm4` sibling is MapPane-only. |
| `0x0061ea68` | `0x0051235f` in `sub_511DB0` | `WM4` sibling is MapPane-only. |
| `0x0061ea70` | `0x00508a42` in `sub_507C90`; raw `0x005142ba` | successor `%s\Mscfg.dll`, not part of `0003JG`. |
| `0x00510960` | caller `0x00507ffa` in `sub_507C90` | MapPane-side dispatch route to `sub_510960`. |
| `0x005c2ac0` | callers `0x0050f2fa` in `sub_50F270` and `0x005126f9` in `sub_511DB0` | WorldMapPane construction routes. |
| `0x00543d70` | callee from `sub_5C2AC0` and many other palette consumers | downstream PaletteLib lookup, not declaration owner. |

## Documentation Evidence And IDA Status

- Current target page records `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L3,0000PB`. Live IDA/PE evidence confirms this state.
- [UID:0000L3][MapPane](by-file/MapPane.md) is a valid file root at `89/85`, path `NexusTK/map/`, and documents MapPane resource-string splits plus the shared `.PAL` and `WM2` children as parentless shared literals.
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) is a valid file root at `90/86`, path `NexusTK/map/`, and documents WorldMapPane as a separate world-map/travel UI module. Live IDA confirms `sub_5C2AC0` as its constructor/resource family.
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md) is relevant palette-manager context but does not document ownership of caller-side map resource suffix literals. Live IDA confirms `sub_543D70` takes a `wchar_t *Source` and lacks direct refs to `0x0061ea24`.
- [UID:0003IX][MapWorldPaletteResourceStrings](by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) is correctly modeled as a non-emitting split index over mixed MapPane-only and shared children.
- `auto-generated/-ag-memory-coverage.md` correctly lists `0003JG` as no-owner with emitters ``0000L3`,`0000PB``.
- `by-memory/-coverage-report.md` currently contains a correct nested row under `0003IX` saying B003 post-migration and B001 second-pass reviews retained `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000L3,0000PB`.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000L3,0000PB`

- Evidence for: direct target-address refs from MapPane and WorldMapPane are current live IDA and PE facts. The by-structure owner/emitter split explicitly supports pooled/shared literals with multiple proven source-use emitters. Both file roots clear the route gate and have valid `NexusTK/map/` paths.
- Evidence against: a shared source declaration is possible, but no debug metadata, named global object, table, or source module proves it.
- Decision: accepted. Keep current target metadata unchanged.

### 2. Canonical owner [UID:0000L3] MapPane

- Evidence for: `sub_510960` has two target-address refs, and MapPane owns several adjacent MapPane-only sibling strings.
- Evidence against: WorldMapPane `sub_5C2AC0` has an independent direct target-address ref. Use count is not declaration ownership. The sibling split already separates MapPane-only children from shared children.
- Decision: reject as canonical owner; keep as emitter `0000L3`.

### 3. Canonical owner [UID:0000PB] WorldMapPane

- Evidence for: WorldMapPane constructor/resource code directly appends `.PAL` to a constructed palette name and calls PaletteLib lookup.
- Evidence against: MapPane `sub_510960` has two independent direct refs to the same physical address. WorldMapPane does not prove ownership of the shared physical literal.
- Decision: reject as canonical owner; keep as emitter `0000PB`.

### 4. Canonical owner or emitter [UID:0000MB] PaletteLib

- Evidence for: the suffix is used to build palette filenames, and WorldMapPane passes the constructed name to PaletteLib lookup.
- Evidence against: `sub_543D70` takes a caller-supplied `wchar_t *Source`; IDA/PE finds no direct reference from PaletteLib to `0x0061ea24`; PaletteLib is a downstream consumer of completed palette names.
- Decision: reject as owner and emitter.

### 5. New shared `MapPaletteConstants` / `MapWorldPaletteConstants` owner

- Evidence for: `.PAL` and `WM2` are both shared by map/world-map paths, so a shared header or constants block is plausible.
- Evidence against: no source/debug metadata, symbol, table abstraction, or relocation pattern proves such an owner. `by-structure.md` says not to invent a standalone helper/global file solely to avoid `NONE`.
- Decision: reject. Do not create a new owner/file.

### 6. Split, merge, or reclassify

- Evidence for split: none. The target is already only one short string plus terminator/alignment.
- Evidence for merge: adjacent strings belong to the same old physical cluster.
- Evidence against merge: sibling xref sets differ materially. `wm`/`WM`/`wm2` and `wm3`/`WM3`/`wm4`/`WM4` are MapPane-only; `.PAL` and `WM2` are shared. The current split reflects this.
- Evidence against reclassification: the suffix is source-authored string data used by reconstructable code paths. It is source-declared/generated-binary, not padding-only or non-reconstructable aggregate data.
- Decision: reject split, merge, and reclassification.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: [UID:0003IX] remains a non-emitting split index; [UID:0000MB] PaletteLib remains downstream; a new shared constants source is unsupported.
- Standalone, narrow, or broad source-file inference: not applicable because the best-supported decision is no canonical owner with two emitters.

## Negative Evidence Summary

- `.PAL` text is common: the PE scan found many copies, so text occurrence or suffix semantics cannot decide ownership.
- Exact address refs prove source-use routes but do not prove a single declaration owner when multiple source families materially use the same address.
- MapPane is not the owner merely because it has two refs and adjacent MapPane-only siblings.
- WorldMapPane is not the owner merely because its constructor/resource path uses the suffix before PaletteLib lookup.
- PaletteLib is not the owner because it does not reference `0x0061ea24`; it receives constructed names.
- The PE scan found no RVA-form or rel32-to-target evidence suggesting a hidden table or shared declaration object.
- No `.pdb`, `RSDS`, `NB10`, `.cpp`, `.cxx`, or `.h` string evidence was found in IDA's string cache.
- No split is needed because there is no smaller meaningful child inside `0x0061ea24-0x0061ea30`.

## Final Recommendation

- Exact changes applied or recommended: no by-* changes applied; no by-* changes recommended.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000L3,0000PB`.
- Exact items left no-owner/non-emitting and why: `0003JG` remains no-owner but not non-emitting, because no single source declaration owner is proven while MapPane and WorldMapPane source-use routes are both proven.
- Coverage-report replacement: none required. The current `by-memory/-coverage-report.md` row is acceptable as-is; no supervisor text application is needed for this pass.
- Reconstruction C++: keep blank. The item is below the `90/90+` code-entry completeness gate and, more importantly, it is a pooled/shared literal that should surface through consuming source contexts rather than a standalone source object.
- Future work outside this assignment: optional research on whether a real shared map/world-map constants header existed, but current binary evidence does not justify creating one.

## Follow-Up Actions

- Supervisor actions: accept the current no-owner-with-emitters state for `0003JG`; no coverage-report edit is required.
- A-agent actions: none required for this target.
- B003 future research actions: no immediate follow-up. Related shared sibling `0003JI` is already separately modeled and should not be merged into this item.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: keep target `COMPLETION:87`, `CONFIDENCE:93`.
- Remaining uncertainty: the binary cannot prove whether the original source repeated identical `.PAL` literals in MapPane and WorldMapPane code or declared the suffix in a shared header/helper. The current `NONE` plus two emitters state accurately preserves that uncertainty while routing proven source uses.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: no target, by-*, generated, project-level, or coverage-report file was edited. The user-required validator `--apply` condition only applies when target changes are needed; this pass found no changes needed.
- Dry runs: none used.
- Unresolved validator warnings/errors: none observed in this assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003JG-SharedMapPaletteSuffixString-current-goal2-pass.md`.
- Modified: none outside the B003 research folder.
- Renamed: none.
- Moved to executed: none.

## Blockers

- None. Current documentation, live IDA MCP evidence, and raw PE evidence were sufficient to make the final Goal 2 recommendation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B003/0003JG-SharedMapPaletteSuffixString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
