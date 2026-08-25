** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Fresh No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](../../../../../by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`.
- Required action: none for by-* docs, generated reports, or `by-memory/-coverage-report.md`.
- Confidence: high. Current IDA and PE evidence proves the two source-use emitter routes and does not prove a single canonical declaration owner.

This item should stay ownerless but not non-emitting. It is a pooled/source string suffix used in both MapPane and WorldMapPane filename construction. The valid output routes are [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) and [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md); assigning either one as canonical owner would overclaim the other source-use route.

## Target

- Target UID: `0003JG`
- Target path: `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active 2026-06-14 remaining no-owner sweep row assigned to Agent-B002.
- Prior report reviewed as evidence only: `tools/leaser/Agents/Agent-B001/research/executed/0003JG-SharedMapPaletteSuffixString-current-no-owner-research.md`
- Current generated state: no-owner with emitters `0000L3,0000PB` in `auto-generated/-ag-memory-coverage.md`.
- Current scores and route before this pass: `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`.
- Current scores and route after this pass: unchanged, `87/93`, `NONE`, `TRUE`, emitters `0000L3,0000PB`.

## Executive Recommendation

Keep the exact target as a shared no-owner string literal with two emitters. The direct binary facts are:

- `0x0061ea24-0x0061ea30` stores UTF-16LE `.PAL`, a terminator, and zero alignment.
- The target address has exactly three direct IDA xrefs: two in MapPane `sub_510960` and one in WorldMapPane constructor-family `sub_5C2AC0`.
- `sub_510960` appends `.PAL` while building MapPane palette filenames.
- `sub_5C2AC0` appends `.PAL`, converts the built name, and passes it to `sub_543D70`, the PaletteLib lookup/load path.
- PaletteLib does not directly reference `0x0061ea24`; it receives a caller-provided `wchar_t *Source`.

No split, merge, rename, IDA repair, owner change, emitter change, or score change is warranted.

## Supervisor Active Recheck

The supervisor assignment requested a fresh Goal 2 no-owner pass for one target only, `0003JG`. I did not start another target. I treated the B001 prior report and existing docs as leads, not authority, and rechecked:

- the current target page,
- current generated memory and file coverage rows,
- the split-index and sibling child pages,
- MapPane, WorldMapPane, and PaletteLib file-root docs,
- live IDA MCP xrefs, function membership, bytes, decompilation snippets, and component analysis,
- raw PE bytes and absolute-reference patterns.

The target did not require split repair before final reporting. The existing child range is exact and the neighboring children already carry the different ownership decisions.

## Inference Research Guidance Check

`by-structure.md` separates `CANONICAL_OWNER` from `EMITTER_UIDS`: ownership is semantic declaration ownership, while emitters are generated-output routes. It also explicitly allows compiler/linker-pooled string literals to remain `CANONICAL_OWNER:NONE` with multiple emitters when no single declaration owner is proven. That rule applies here.

`inference_research.md` warns that merged string literals and constant pools are informative but weak as source-file ownership evidence. I therefore did not use the physical `.rdata` string neighborhood or IDA name `aPal` as ownership proof. I used xref/function context as source-use evidence and kept declaration ownership unassigned.

## Evidence Standards Used

- Direct byte evidence: target bytes and target range must match `.PAL` plus terminator/alignment.
- Direct source-use evidence: target xrefs must resolve to concrete functions with defensible by-file roots.
- Owner evidence: a canonical owner must explain the declaration, not just one use site.
- Emitter evidence: a by-file root must be a valid generated source root and must have direct or routed source-use evidence.
- Split evidence: adjacent child xrefs and payloads must remain distinct if their use sets differ.
- Negative evidence: no hidden RVA references, no PaletteLib direct reference, no interior alignment reference, no unique byte-pattern declaration owner, and no single shared-constants object were found.

## IDA MCP Facts

Live IDA MCP state:

- Session: `a001_goal2_class_batch`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x00400000`
- Auto-analysis ready: true
- Hex-Rays ready: true

Function/range facts:

| Query | Current IDA result |
| --- | --- |
| `0x00510960`, `0x00510b57`, `0x00511041` | `sub_510960`, size `0x9e7` |
| `0x00511db0` | `sub_511DB0`, size `0xa8a` |
| `0x005c2ac0`, `0x005c2eae` | `sub_5C2AC0`, size `0x7ea` |
| `0x005c5200`, `0x005c5219` | `sub_5C5200`, size `0x1d0` |
| `0x00543d70` | `sub_543D70`, size `0xce` |
| `0x0061ea24`, `0x0061ea30`, `0x0061ea48` | not functions |

Data/name facts:

- `get_bytes 0x0061ea20 size 96` includes `2e 00 50 00 41 00 4c 00 00 00 00 00` at `0x0061ea24`, decoding as UTF-16LE `.PAL` plus terminator/alignment.
- Neighbor names in IDA are `aPal` at `0x0061ea24`, `aWm` at `0x0061ea30`, `aWm_0` at `0x0061ea38`, `aWm2` at `0x0061ea40`, `aWm2_0` at `0x0061ea48`, then `aWm3`, `aWm3_0`, `aWm4`, `aWm4_0`, and successor `aSMscfgDll` at `0x0061ea70`.
- IDA's string query did not enumerate this small wide string, but direct bytes and names do.

Xref facts:

| Address | Current xrefs | Meaning |
| --- | --- | --- |
| `0x0061ea24` | `0x00510b57`, `0x00511041` in `sub_510960`; `0x005c2eae` in `sub_5C2AC0` | target `.PAL` shared by MapPane and WorldMapPane |
| `0x0061ea2c` | none | no interior/alignment split or owner |
| `0x0061ea30` | `0x005121a1` in `sub_511DB0` | MapPane-only sibling begins |
| `0x0061ea38` | `0x005121e3` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea40` | `0x00512223` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea48` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | separate shared `WM2` sibling |
| `0x0061ea50`, `0x0061ea58`, `0x0061ea60`, `0x0061ea68` | one `sub_511DB0` ref each | MapPane-only sibling |
| `0x0061ea70` | `0x00508a42` in `sub_507C90`; raw/unknown `0x005142ba` | successor child, not part of target |

Instruction and decompiler facts:

- `insn_query` for operand `0x0061ea24` finds `push offset aPal; ".PAL"` at `0x00510b57`, `0x00511041`, and `0x005c2eae`.
- `sub_510960` decompiles to two MapPane appends:
  - `wcscat_s(v61, 0x100u, L".PAL")` at `0x00510b68`.
  - `wcscat_s(v60, 0x100u, L".PAL")` at `0x00511052`.
- `sub_5C2AC0` decompiles to WorldMapPane string construction:
  - `sub_584470(..., L".PAL", 4u)` at `0x005c2ebf`.
  - `sub_584540(...)` at `0x005c2ecc`.
  - `sub_543D70(v31)` at `0x005c2ed4`.
- `sub_543D70` decompiles as `int __thiscall sub_543D70(int this, wchar_t *Source)`, compares the caller-provided `Source` with loaded palette names via `wcscmp`, and may call `sub_5431C0(this, Source)`. It does not build or directly reference the target `.PAL` suffix.
- `sub_511DB0` decompiles adjacent MapPane-only comparisons to `L"wm"`, `L"WM"`, `L"wm2"`, `L"WM2"`, `L"wm3"`, `L"WM3"`, `L"wm4"`, and `L"WM4"`.
- `sub_5C5200` decompiles a separate WorldMapPane helper using `L"WM2"`, supporting the sibling `0003JI` split but not merging it with `.PAL`.

Component analysis facts:

- `analyze_component` over `0x00510960`, `0x00511db0`, `0x005c2ac0`, `0x005c5200`, and `0x00543d70` reports shared global `0x0061ea24` / `aPal` accessed by `sub_510960` and `sub_5C2AC0`.
- The same component analysis reports `0x0061ea48` / `aWm2_0` accessed by `sub_511DB0` and `sub_5C5200`, confirming the separate shared-sibling pattern.
- The internal call graph includes `sub_511DB0 -> sub_5C2AC0` and `sub_5C2AC0 -> sub_543D70`; this makes PaletteLib a downstream lookup/load dependency for the built name, not the source owner of the suffix literal.

## PE / Raw Evidence

Independent raw PE scan used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- File size: `0x28e200`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.text`: VA `0x00401000`, raw `0x00000400`
- `.rdata`: VA `0x0060d000`, raw `0x0020ba00`
- Target VA `0x0061ea24` maps to raw `0x0021d424`.
- Target bytes: `2e 00 50 00 41 00 4c 00 00 00 00 00`
- Target decode: `.PAL`

Pattern results:

| Pattern | Hits | Result |
| --- | ---: | --- |
| full 12-byte `.PAL` target bytes | 69 | target included at raw `0x21d424` / VA `0x0061ea24`; many duplicates mean text uniqueness cannot prove owner |
| UTF-16LE `.PAL` plus null | 119 | confirms widespread reuse/duplication of the text |
| `push 0x0061ea24` bytes `68 24 ea 61 00` | 3 | raw `0x10ff57` / VA `0x00510b57`; raw `0x110441` / VA `0x00511041`; raw `0x1c22ae` / VA `0x005c2eae` |
| absolute dword `0x0061ea24` | 3 | same three operand locations at `0x00510b58`, `0x00511042`, `0x005c2eaf` |
| RVA dword `0x0021ea24` | 0 | no hidden RVA-form route |
| interior absolute dword `0x0061ea2c` | 0 | no interior/alignment ref |
| successor absolute dword `0x0061ea30` | 1 | MapPane-only sibling ref |
| shared-sibling absolute dword `0x0061ea48` | 2 | separate shared `WM2` refs |

Raw PE evidence matches live IDA xrefs and does not reveal a hidden declaration owner, hidden emitter, or split requirement.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea24-0x0061ea70` | [UID:0003IX](../../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) | split index for `.PAL` and `WM*` literals | false | none | `90/93` | keep non-emitting container |
| `0x0061ea24-0x0061ea30` | [UID:0003JG](../../../../../by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | target `.PAL` suffix | true | owner `NONE`; emitters `0000L3,0000PB` | `87/93` | keep current |
| `0x0061ea30-0x0061ea48` | [UID:0003JH](../../../../../by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) | `wm`, `WM`, `wm2` | true | `0000L3` | `88/93` | keep separate MapPane child |
| `0x0061ea48-0x0061ea50` | [UID:0003JI](../../../../../by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | `WM2` | true | owner `NONE`; emitters `0000L3,0000PB` | `87/93` | keep separate shared child |
| `0x0061ea50-0x0061ea70` | [UID:0003JJ](../../../../../by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md) | `wm3`, `WM3`, `wm4`, `WM4` | true | `0000L3` | `88/93` | keep separate MapPane child |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00510b57` | `push offset aPal` in `sub_510960` | MapPane source-use route for `.PAL` |
| `0x00511041` | `push offset aPal` in `sub_510960` | second MapPane source-use route for `.PAL` |
| `0x005c2eae` | `push offset aPal` in `sub_5C2AC0` | WorldMapPane source-use route for `.PAL` |
| `0x005c2ed4` | `sub_5C2AC0` calls `sub_543D70` with the built palette name | PaletteLib receives the name after WorldMapPane constructs it |
| `0x00512263` | `sub_511DB0` uses `WM2` | separate shared sibling, not a reason to merge target |
| `0x005c5219` | `sub_5C5200` uses `WM2` | separate shared sibling, not a reason to merge target |

## Documentation Evidence And IDA Status

Existing docs that current IDA confirms:

- Target page records `.PAL`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, emitters `0000L3,0000PB`, and the three direct xrefs.
- `MapWorldPaletteResourceStrings` records a non-emitting split index and exact child boundaries. Current IDA xrefs still support those boundaries.
- `MapPane.md` is a valid generated file root at `NexusTK/map/`, score `89/85`, and records this resource-string split family.
- `WorldMapPane.md` is a valid generated file root at `NexusTK/map/`, score `90/86`, and documents `sub_5C2AC0` as WorldMapPane constructor-family code.
- `PaletteLib.md` is a valid render file root, but current IDA confirms it is downstream for this target, not a direct owner.

Current generated/coverage state:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
```

Emitter-summary row:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

Generated file-root rows confirm:

- `0000L3` emits to `auto-generated/NexusTK/map/MapPane.cpp`.
- `0000PB` emits to `auto-generated/NexusTK/map/WorldMapPane.cpp`.

Both generated files currently exist but are zero bytes because final reconstruction snippets are not populated. That is not an emitter dead end for this item.

## Ranked Ownership Analysis

### 1. No canonical owner with MapPane and WorldMapPane emitters

- Evidence for: current IDA xrefs prove two MapPane refs and one WorldMapPane ref to the same target address; both by-file roots are valid generated roots; no declaration owner is proven.
- Evidence against: MapPane has the majority of direct refs, but majority use is not declaration ownership.
- Decision: accepted. Keep `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`.

### 2. MapPane as canonical owner

- Evidence for: MapPane has two direct refs in `sub_510960`; `MapPane.md` is a high-confidence file root and adjacent MapPane-only siblings exist.
- Evidence against: WorldMapPane has a material direct ref in `sub_5C2AC0`; no MapPane declaration or shared constant owner is proven; assigning MapPane would overclaim WorldMapPane use.
- Decision: rejected.

### 3. WorldMapPane as canonical owner

- Evidence for: `sub_5C2AC0` constructs a WorldMapPane palette filename with `.PAL`; `WorldMapPane.md` is a high-confidence file root.
- Evidence against: MapPane has two direct refs in a separate function family; no WorldMapPane declaration owner is proven.
- Decision: rejected.

### 4. PaletteLib / Palette as canonical owner

- Evidence for: WorldMapPane passes the built `.PAL` name to `sub_543D70`, a PaletteLib-style lookup/load helper; PaletteLib owns broader render palette state.
- Evidence against: `sub_543D70` takes a caller-provided `wchar_t *Source`, uses `wcscmp`, and may call `sub_5431C0(this, Source)`. It has no direct ref to `0x0061ea24` and does not append `.PAL`.
- Decision: rejected. PaletteLib is a consumer/load API dependency here, not the suffix declaration owner.

### 5. Synthetic shared constants file

- Evidence for: the same suffix is used by more than one source-use family.
- Evidence against: no debug/source metadata, named global, initializer, pointer table, or clustered shared-constants object is present. The raw bytes show `.PAL` is duplicated widely across the binary, so string text reuse is not enough to infer a constants module.
- Decision: rejected. Do not invent a file solely to remove `NONE`.

## Negative Evidence Summary

- No xrefs to interior/alignment address `0x0061ea2c`.
- No RVA-form raw references to target RVA `0x0021ea24`.
- No PaletteLib direct target ref.
- No unique `.PAL` physical string identity; the exact 12-byte pattern appears 69 times and the shorter `.PAL` string appears 119 times.
- No evidence that `0003JG` should merge with `0003JI`: `.PAL` and `WM2` have different payloads and different reference sites.
- No evidence that `0003JG` should merge back into `0003IX`: the surrounding island includes MapPane-only and shared children with different routing decisions.
- No evidence that `0003JG` should be reclassified non-reconstructable: it is source string data used by reconstructable functions.
- No IDA-safe rename is needed: `SharedMapPaletteSuffixString` accurately names the owner-neutral shared suffix.

## Final Recommendation

- Exact changes applied or recommended: none.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`.
- Exact emitters applied or recommended: keep `EMITTER_UIDS:0000L3,0000PB`.
- Exact items left no-owner/non-emitting and why: `0003JG` remains no-owner but not non-emitting. The source-use emitters are proven; declaration ownership is not.
- Exact future work outside this assignment: no immediate work required. A later final-source pass should spell the suffix at consuming MapPane and WorldMapPane use sites unless source/debug evidence proves a named shared declaration.

## C++ Entry Eligibility

Minimum active gate:

- `RECONSTRUCTABLE:TRUE`: yes.
- Confirmed nonblank emitters: yes, `0000L3,0000PB`.
- Emitters surface to generated source roots without dead-end: yes, `MapPane.cpp` and `WorldMapPane.cpp` file roots exist.
- Combined score: `(87 + 93) / 2 = 90`, which is greater than `85`.

Minimum eligibility is met, but final C++ should remain blank for this memory item. The page represents a pooled literal, not a proven standalone declaration. The safe source representation is use-site literals in future MapPane and WorldMapPane function reconstructions unless stronger source evidence proves a shared named constant.

## Follow-Up Actions

- Supervisor actions: none required. Do not change `by-memory/-coverage-report.md` for correctness.
- A-agent actions: none required for this target.
- B002 future research actions: none for `0003JG`; continue only when assigned a new target.

If the supervisor wants a provenance-refresh-only shared-report replacement, use the exact text below in place of the current `0003JG` child row. This is optional and not required for correctness:

```text
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000PB`; 2026-06-14 B002 fresh no-owner pass reconfirmed direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, raw PE `push 0x0061ea24` matches at those three VAs only, no interior/RVA/PaletteLib direct owner refs, and no single semantic declaration owner, split, merge, reclassification, or IDA repair is justified.
```

## Confidence

- Recommendation confidence: high.
- Score confidence: current `87/93` remains defensible.
- Remaining uncertainty: the stripped binary cannot prove whether original source repeated `L".PAL"` at use sites or used an unobserved named constant before pooling. That uncertainty is the reason to keep `CANONICAL_OWNER:NONE` while retaining the proven emitters.

## Validator Results

- Commands run: none.
- Results: not applicable. No by-* target documentation, generated report, project-level report, or shared coverage report was edited.
- Dry runs: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003JG-SharedMapPaletteSuffixString-fresh-no-owner-pass.md`
- Modified: none outside the created Agent-B002 research report.
- Renamed: none.
- Moved to executed: none.
- Leases used: none. B002 research-folder report creation does not require a lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B002/0003JG-SharedMapPaletteSuffixString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
