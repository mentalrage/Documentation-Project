** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Current Goal 2 Pass

## Finalized Recommendation

- Target: [UID:0003JG] `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- Recommendation: keep `CANONICAL_OWNER:NONE`, keep `EMITTER_UIDS:0000L3,0000PB`, keep `RECONSTRUCTABLE:TRUE`, keep scores `COMPLETION:87` and `CONFIDENCE:93`, and keep the C++ block blank.
- Required by-memory edit: none.
- Required `by-memory/-coverage-report.md` edit: none. Retain the current row text exactly.
- Required generated coverage edit: none. Current generated state already matches the live evidence.
- Split/merge/reclassification: no additional split, merge, or reclassification is warranted.
- Confidence in this recommendation: high. Live IDA MCP and raw PE evidence both confirm exactly two MapPane source-use refs and one WorldMapPane source-use ref to the target address, with no PaletteLib or single-declaration owner proof.

This is a valid current-owner-model case: no defensible single canonical declaration owner is proven, but two independent source-use routes are proven strongly enough for multiple emitters.

## Target and Scope

- Assigned target: `0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString`
- UID: `0003JG`
- Target kind: `string-data`
- Current generated status: `no-owner`; `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000L3,0000PB`
- Current tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active 2026-06-14 remaining no-owner memory sweep, assigns `0003JG` to Agent-B002.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B003/research/executed/0003JG-SharedMapPaletteSuffixString-current-goal2-pass.md`

The assignment explicitly asked not to force a canonical owner merely to remove `NONE`. I treated prior reports and current docs as leads, then rechecked with live IDA MCP and raw PE evidence.

## Evidence Standard Applied

The controlling rule is `by-structure.md` current owner/emitter guidance. The relevant rule says pooled string literals, shared constants, and small read-only data can keep `CANONICAL_OWNER:NONE` when no declaration/source owner is proven, while using multiple `EMITTER_UIDS` for proven source-use contexts. It also says not to invent a standalone global/helper file solely to avoid `NONE` and not to force ownership to the consumer with the most xrefs when other consumers materially use the same pooled item.

Applied to this target:

- A canonical owner would require stronger evidence than "MapPane has two xrefs and WorldMapPane has one xref."
- Emitters require proven source-use output routes. The IDA refs prove MapPane and WorldMapPane both build/use names with this literal.
- PaletteLib can only become owner/emitter if it directly declares or uses the literal, not merely because it later looks up caller-built palette names.
- C++ source entry remains blank because this is string data and the active 90/90+ reconstruction-code gate is not met by `87/93`.

## Current Documentation Checked

Primary target page:

- `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- Header currently has `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`, `COMPLETION:87`, `CONFIDENCE:93`, and blank C++.
- Body states this exact child is UTF-16 `.PAL`, split from `0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings`, shared by MapPane and WorldMapPane consumers, and not owned by PaletteLib.

Related docs:

- `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` is a non-emitting split index. Its child table already separates the mixed island into `0003JG`, `0003JH`, `0003JI`, and `0003JJ`.
- `by-file/MapPane.md` lists MapPane-owned exact children for neighboring MapPane-only literals, while explicitly leaving shared `.PAL` and `WM2` parentless because WorldMapPane refs are material.
- `by-file/WorldMapPane.md` remains a separate map-domain source file for the scrollable world-map/travel UI.
- `by-file/PaletteLib.md` owns palette manager APIs and the `g_pPaletteLib` runtime manager, not caller-side map/world-map filename suffix literals.
- `by-project-structure/proposed-source-tree.md` places `MapPane.cpp` and `WorldMapPane.cpp` under `map/` as separate files and places `PaletteLib` under `render/Palette.cpp`.

Current generated report state:

```markdown
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
```

Current emit-route row:

```markdown
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

Current no-owner queue row:

```markdown
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | `0000L3`,`0000PB` | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

These generated rows are consistent with the recommendation. The generated `auto-generated/NexusTK/map/MapPane.cpp` path is not evidence of sole canonical ownership; the emitter row already preserves the separate WorldMapPane route.

## Live IDA MCP Evidence

IDA MCP session:

- Database/session: `b001_0003gy`
- `server_health`: `status: ok`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x400000`
- `auto_analysis_ready: true`
- `hexrays_ready: true`
- `strings_cache_ready: true`
- `strings_cache_size: 2067`

Function lookup:

| Query | Live IDA result | Meaning for target |
| --- | --- | --- |
| `0x00510960` | `sub_510960`, size `0x9e7` | MapPane helper family |
| `0x00510b57` | inside `sub_510960` | first MapPane `.PAL` use |
| `0x00511041` | inside `sub_510960` | second MapPane `.PAL` use |
| `0x005c2ac0` | `sub_5C2AC0`, size `0x7ea` | WorldMapPane constructor-family range |
| `0x005c2eae` | inside `sub_5C2AC0` | WorldMapPane `.PAL` use |
| `0x005c5200` | `sub_5C5200`, size `0x1d0` | WorldMapPane helper used by sibling `WM2` case |
| `0x00543d70` | `sub_543D70`, size `0xce` | PaletteLib lookup helper, not a literal owner |
| `0x0061ea24` | not a function | target is data |

Direct xrefs to target:

```text
xrefs_to 0x0061ea24:
- 0x00510b57, data, function sub_510960
- 0x00511041, data, function sub_510960
- 0x005c2eae, data, function sub_5C2AC0
- more: false, xref_count: 3
```

Local instruction windows at the three refs:

```text
0x00510b52 call _wcscpy_s
0x00510b57 push offset aPal; ".PAL"
0x00510b5c lea eax, [ebp+var_510]

0x0051103c call _wcscpy_s
0x00511041 push offset aPal; ".PAL"
0x00511046 lea eax, [ebp+var_710]

0x005c2ea7 call sub_582A90
0x005c2eac push 4
0x005c2eae push offset aPal; ".PAL"
0x005c2eb3 lea ecx, [ebp+arg_4]
```

This is direct source-use evidence for:

- MapPane emitter [UID:0000L3]: `sub_510960` at `0x00510b57` and `0x00511041`.
- WorldMapPane emitter [UID:0000PB]: `sub_5C2AC0` at `0x005c2eae`.

Sibling xrefs in the split island:

```text
0x0061ea30 ("wm")  -> 0x005121a1 in sub_511DB0
0x0061ea38 ("WM")  -> 0x005121e3 in sub_511DB0
0x0061ea40 ("wm2") -> 0x00512223 in sub_511DB0
0x0061ea48 ("WM2") -> 0x00512263 in sub_511DB0 and 0x005c5219 in sub_5C5200
0x0061ea50 ("wm3") -> 0x005122a3 in sub_511DB0
0x0061ea58 ("WM3") -> 0x005122e3 in sub_511DB0
0x0061ea60 ("wm4") -> 0x00512323 in sub_511DB0
0x0061ea68 ("WM4") -> 0x0051235f in sub_511DB0
```

The sibling pattern supports the existing split: `0003JH` and `0003JJ` are MapPane-only comparison-string children, while `0003JG` and `0003JI` are materially shared MapPane/WorldMapPane literals.

PaletteLib check:

- `decompile 0x00543d70` returns `int __thiscall sub_543D70(int this, wchar_t *Source)`.
- The helper compares the caller-provided `Source` against loaded palette records using `wcscmp`, calls `sub_5431C0` when needed, and returns a palette object or fallback object.
- It does not directly reference `0x0061ea24`.
- `xrefs_to 0x00543d70` shows broad caller fan-in across the client, confirming it is a shared palette lookup API rather than a declaration site for this particular `.PAL` suffix.

Source/debug search:

- `find_regex '(?i)\\.pdb|RSDS|NB10|\\.cpp|\\.cxx|\\.h'` returned `n:0`.
- No debug/source-path metadata was found to prove a single declaration owner.

## Raw PE Evidence

Raw file checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

PE mapping:

- Image base: `0x00400000`
- Target VA: `0x0061ea24`
- Section: `.rdata`
- File offset: `0x21d424`

Bytes at `0x0061ea24-0x0061ea70`:

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

Decoded UTF-16LE sequence:

```text
0x0061ea24 ".PAL"
0x0061ea30 "wm"
0x0061ea38 "WM"
0x0061ea40 "wm2"
0x0061ea48 "WM2"
0x0061ea50 "wm3"
0x0061ea58 "WM3"
0x0061ea60 "wm4"
0x0061ea68 "WM4"
```

Raw reference scan for absolute VA `0x0061ea24` found exactly three `.text` hits:

```text
0x00510b58
0x00511042
0x005c2eaf
```

These are the immediate little-endian address operands corresponding to IDA instruction starts `0x00510b57`, `0x00511041`, and `0x005c2eae`. The raw scan found no RVA-form hits for `0x0021ea24`.

The raw PE scan also confirms `.PAL` is a common pooled literal pattern elsewhere in `.rdata` (`119` UTF-16 `.PAL\0` hits, `69` padded `.PAL` hits), so the presence of the suffix text alone cannot establish a unique source owner. This reinforces owner `NONE` and requires using direct xrefs for emitter routing.

## Function and Child Inventory

| UID/range | Current role | Current owner/emitter result | Recheck result |
| --- | --- | --- | --- |
| `0003IX` `0x0061ea24-0x0061ea70` | non-emitting split index over `.PAL` and `WM*` literals | `CANONICAL_OWNER:NONE`, no emitters | correct; mixed-index page only |
| `0003JG` `0x0061ea24-0x0061ea30` | `.PAL` UTF-16 suffix | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB` | correct; keep unchanged |
| `0003JH` `0x0061ea30-0x0061ea48` | `wm`, `WM`, `wm2` | MapPane-owned/emitted | sibling xrefs still MapPane-only |
| `0003JI` `0x0061ea48-0x0061ea50` | `WM2` | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB` | sibling shared case supports current model |
| `0003JJ` `0x0061ea50-0x0061ea70` | `wm3`, `WM3`, `wm4`, `WM4` | MapPane-owned/emitted | sibling xrefs still MapPane-only |

No child is missing inside `0x0061ea24-0x0061ea30`; the exact target range is already the smallest useful UTF-16 string/alignment unit.

## Owner and Emitter Analysis

### `CANONICAL_OWNER:NONE` Is Correct

The target is a pooled/static UTF-16 suffix with direct uses from both MapPane and WorldMapPane. The evidence proves use, not declaration ownership. There is no debug/source metadata, no unique global declaration, no single source file that dominates all refs, and no reason under by-structure rules to assign the string to whichever consumer has more xrefs.

### `EMITTER_UIDS:0000L3,0000PB` Is Correct

Both emitters have direct source-use evidence:

- [UID:0000L3] `MapPane`: two direct refs from `sub_510960`, at `0x00510b57` and `0x00511041`, both visible as `push offset aPal; ".PAL"` near `_wcscpy_s` path construction.
- [UID:0000PB] `WorldMapPane`: one direct ref from `sub_5C2AC0`, at `0x005c2eae`, visible as `push offset aPal; ".PAL"` while constructing a wide string.

These are output routes, not ownership claims. Keeping both emitters prevents the literal from disappearing from either reconstructed source context.

### PaletteLib Is Not an Owner or Emitter

PaletteLib is a downstream palette manager and lookup API. The live decompile of `sub_543D70` shows it receives a `wchar_t *Source` and searches/loads palette records. It does not directly reference `0x0061ea24`, does not build the caller-side `.PAL` suffix, and does not prove declaration ownership of this literal. Adding `0000MB` or class UID `0000A1` as an emitter would mix API consumption with source-use emission.

### MapPane Sole Ownership Is Rejected

MapPane has two xrefs, but WorldMapPane has a material direct xref in its own constructor-family range. The by-structure rule explicitly rejects forcing ownership to the consumer with the most xrefs when another independent consumer materially uses the same pooled item.

### WorldMapPane Sole Ownership Is Rejected

WorldMapPane has a direct xref, but it is not exclusive. MapPane has two direct refs in a separate source-use path. Sole WorldMapPane ownership would drop MapPane source-use evidence.

### Synthetic Shared Owner Is Rejected

No current source tree file, class, global, or type corresponds to a real `MapPaletteSuffixConstants` declaration. Creating one solely to avoid `CANONICAL_OWNER:NONE` would violate the current owner/emitter model.

## Split, Merge, Reclassification, and Name Repair

- Split: not needed. `0x0061ea24-0x0061ea30` already isolates the exact UTF-16 `.PAL` literal plus terminator/alignment before `wm`.
- Merge: not needed. Merging back into `0003IX` would lose the already-correct split between shared and MapPane-only children. Merging with sibling `0003JI` would combine different literals with different local uses.
- Reclassification: not needed. The target is correctly `string-data`, reconstructable as a literal/data item, not a function, vtable, global pointer, or split index.
- IDA-safe name repair: not needed. The current label `SharedMapPaletteSuffixString` describes the exact shared `.PAL` suffix and is not a stale owner-biased name.
- Range repair: not needed. Live bytes confirm `0x0061ea24-0x0061ea30` is the exact range for `.PAL` plus terminator/alignment.

## Exact Required Shared Report Text

No supervisor-owned shared-report replacement is required. Retain the current `by-memory/-coverage-report.md` child row exactly:

```markdown
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; B003 post-migration and B001 second-pass reviews confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner, PaletteLib owner, split, merge, or reclassification justified.
```

If the supervisor wants this report reflected in coverage prose later, an optional non-required replacement could append `B002 current Goal 2 pass reconfirmed` to the sentence. I do not recommend that as a required edit because it would churn a correct shared report without changing routing.

Retain the current generated no-owner row exactly:

```markdown
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
```

Retain the current generated emitter row exactly:

```markdown
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

## Validation

- No by-* documentation files were edited.
- `by-memory/-coverage-report.md` was not edited.
- `auto-generated/-ag-memory-coverage.md` was not edited.
- Normal validator `--apply` was not run because this was a report-only no-owner recheck with no by-* file changes.
- No dry runs were used.

## Lease State

- Created the new report placeholder first because the assignment requested report-file lease behavior if a new report path had to be leased after creation.
- Leased `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0003JG-SharedMapPaletteSuffixString-current-goal2-pass.md` as `B002` before writing the final report body.
- No by-* documentation lease was needed or acquired because no by-* file was edited.
- Released the report-file lease after writing and verification. A current lease-report check found no `B002`, `0003JG`, `SharedMapPaletteSuffixString`, or `0061ea24` entries.

## Changed Files

- Added `tools/leaser/Agents/Agent-B002/research/0003JG-SharedMapPaletteSuffixString-current-goal2-pass.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B002/0003JG-SharedMapPaletteSuffixString-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
