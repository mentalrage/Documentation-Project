** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Current No-Owner Research

## Final Recommendation

- Keep [UID:0003JG] `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` unchanged.
- Final routing: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB`.
- Do not assign a canonical owner. Current IDA evidence proves direct source-use routes in both MapPane and WorldMapPane, but does not prove one source declaration owner or a PaletteLib-owned suffix declaration.
- Do not split, merge, reclassify, rename, or perform an IDA-safe-name repair. The current child range is exactly the UTF-16LE `.PAL` suffix, terminator, and alignment.
- No by-* documentation edits are required. No `by-memory/-coverage-report.md` edit is required.
- Scores stay `COMPLETION:87`, `CONFIDENCE:93`. Before: `87/93`; after: `87/93`.
- Active C++ gate status: minimum gate is met numerically and structurally because `RECONSTRUCTABLE:TRUE`, emitters are nonblank, both emitters are valid file roots, and `(87 + 93) / 2 = 90 > 85`. This pass still should not enter standalone `RECONSTRUCTION_CPP`: the safe source placement is as use-site literals in the future MapPane and WorldMapPane consuming functions unless source/debug evidence later proves a named shared suffix constant.

## Target And Scope

- Assignment: current Goal 2 no-owner ownership/emitter review for one target only.
- Target UID: `0003JG`.
- Target path: `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`.
- Current generated state checked: no-owner, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000PB`.
- Prior reports were read only as historical context. This recommendation is based on the current target page, current generated rows, related by-file/by-memory docs, live IDA MCP evidence, and an independent PE byte/reference scan.

## Evidence Standards Used

- Direct byte evidence must match the claimed range and payload.
- Direct xrefs must resolve to concrete source-use functions and valid by-file roots before an emitter is retained.
- `CANONICAL_OWNER` requires a defensible semantic declaration/source owner, not just the closest code user or downstream API.
- Shared pooled string literals can remain `CANONICAL_OWNER:NONE` with multiple emitters when multiple source-use routes are proven and no single declaration owner is proven.
- Split/merge decisions are based on byte boundaries, xref boundaries, and sibling ownership contrast, not physical adjacency alone.

## Current Documentation Facts

Target header:

```text
*** UID:0003JG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000PB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The page describes the range as UTF-16 string data at `0x0061ea24-0x0061ea30`, decoded payload `.PAL`, and a shared source-use route through [UID:0000L3] MapPane and [UID:0000PB] WorldMapPane.

Generated memory coverage currently reports:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
```

The generated emitted/no-owner route table also resolves the two emitters:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) |  | `auto-generated/NexusTK/map/MapPane.cpp` |  |
```

Emitter roots checked:

| UID | File doc | Current status | Relevance |
| --- | --- | --- | --- |
| `0000L3` | `by-file/MapPane.md` | `COMPLETION:89`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/` | Valid file root for MapPane `sub_510960` source-use refs. |
| `0000PB` | `by-file/WorldMapPane.md` | `COMPLETION:90`, `CONFIDENCE:86`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/` | Valid file root for WorldMapPane constructor-family source-use ref. |
| `0000MB` | `by-file/PaletteLib.md` | `COMPLETION:88`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, path `NexusTK/render/` | Rejected as canonical owner for this literal; PaletteLib consumes caller-provided names and does not reference the suffix directly. |

The local generated roots exist:

```text
auto-generated/NexusTK/map/MapPane.cpp       length 0
auto-generated/NexusTK/map/WorldMapPane.cpp  length 0
```

The empty lengths reflect blank `RECONSTRUCTION_CPP`, not a dead-end emitter chain.

## Live IDA MCP Facts

Live database/session: active IDA MCP worker for `NexusTK.exe`, session `b001_0002bd`.

### Bytes

`get_bytes` at `0x0061ea20` for 96 bytes includes this sequence:

```text
0x0061ea24: 2e 00 50 00 41 00 4c 00 00 00 00 00
```

That is UTF-16LE `.PAL`, a null terminator, and zero-word alignment. The surrounding bytes continue with `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`, matching the current split-index family.

### Xrefs

`xrefs_to` confirms exactly three direct refs to the target address:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x00510b57` | `sub_510960` at `0x00510960` | MapPane source-use route. |
| `0x00511041` | `sub_510960` at `0x00510960` | Second MapPane source-use route. |
| `0x005c2eae` | `sub_5C2AC0` at `0x005c2ac0` | WorldMapPane constructor-family source-use route. |

No xrefs were reported to the interior/alignment address `0x0061ea2c`.

Sibling xrefs checked for boundary contrast:

| Address | Xrefs | Ownership implication |
| --- | --- | --- |
| `0x0061ea30` | `0x005121a1` in `sub_511DB0` | MapPane-only sibling. |
| `0x0061ea38` | `0x005121e3` in `sub_511DB0` | MapPane-only sibling. |
| `0x0061ea40` | `0x00512223` in `sub_511DB0` | MapPane-only sibling. |
| `0x0061ea48` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | Separate shared sibling `0003JI`. |
| `0x0061ea50` through `0x0061ea68` | only `sub_511DB0` refs | MapPane-only siblings. |

This supports the current split: adjacent literals have different use sets, and `0003JG` is one exact shared child.

### Function Membership

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x00510960`, `0x00510b57`, `0x00511041` | `sub_510960`, size `0x9e7` |
| `0x005c2ac0`, `0x005c2eae` | `sub_5C2AC0`, size `0x7ea` |
| `0x00543d70` | `sub_543D70`, size `0xce` |
| `0x0061ea24` | not a function |

### Decompiler Evidence

`sub_510960` contains the two MapPane uses:

```text
wcscat_s(v61, 0x100u, L".PAL"); /*0x510b68*/
wcscat_s(v60, 0x100u, L".PAL"); /*0x511052*/
```

`sub_5C2AC0` contains the WorldMapPane use and then passes the built name to the palette loader:

```text
sub_584470((int *)&a3, L".PAL", 4u); /*0x5c2ebf*/
v31 = (wchar_t *)sub_584540(v30); /*0x5c2ecc*/
v32 = sub_543D70(v31); /*0x5c2ed4*/
```

`sub_543D70` decompiles as a PaletteLib-style lookup that receives `wchar_t *Source`, compares that caller-provided string with loaded palette names via `wcscmp`, and may call `sub_5431C0(this, Source)`. It has no direct ref to `0x0061ea24` and does not construct `.PAL` itself.

### Component Analysis

`analyze_component` over `0x00510960`, `0x00511db0`, `0x005c2ac0`, `0x005c5200`, and `0x00543d70` reports shared global `0x0061ea24`/`aPal` accessed by `sub_510960` and `sub_5C2AC0`. It also reports `0x0061ea48`/`aWm2_0` separately accessed by `sub_511DB0` and `sub_5C5200`, which matches the sibling shared-string pattern and does not collapse the children.

## PE / Raw Evidence

Independent raw scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Check | Result |
| --- | --- |
| Image base | `0x00400000` |
| Target RVA | `0x0021ea24` |
| Target raw offset | `0x0021d424` in `.rdata` |
| Exact 12-byte target pattern | 69 hits overall; target raw offset `0x0021d424` present |
| UTF-16LE `.PAL` plus null, 10 bytes | 119 hits overall |
| `push 0x0061ea24` | 3 hits: raw `0x10ff57 -> VA 0x00510b57`, raw `0x110441 -> VA 0x00511041`, raw `0x1c22ae -> VA 0x005c2eae` |
| Absolute dword `0x0061ea24` | same three operands at `0x00510b58`, `0x00511042`, `0x005c2eaf` |
| RVA dword `0x0021ea24` | 0 hits |

The raw scan independently confirms the target-address refs and also shows `.PAL` is heavily duplicated/pooled elsewhere. The text itself is therefore not unique enough to prove a single source owner.

## Function And Child Inventory

| UID/range | Current role | Current owner/emitter state | Current assessment |
| --- | --- | --- | --- |
| `0003IX` `0x0061ea24-0x0061ea70` | Split index for `.PAL` and `WM*` literals | `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE` | Correct non-emitting container. |
| `0003JG` `0x0061ea24-0x0061ea30` | Target `.PAL` suffix | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB` | Correct shared child. |
| `0003JH` `0x0061ea30-0x0061ea48` | `wm`, `WM`, `wm2` strings | `CANONICAL_OWNER:0000L3`, emitter `0000L3` | MapPane-only sibling; supports split contrast. |
| `0003JI` `0x0061ea48-0x0061ea50` | `WM2` string | `CANONICAL_OWNER:NONE`, emitters `0000L3,0000PB` | Separate shared sibling; do not merge with `.PAL`. |
| `0003JJ` `0x0061ea50-0x0061ea70` | `wm3`, `WM3`, `wm4`, `WM4` strings | `CANONICAL_OWNER:0000L3`, emitter `0000L3` | MapPane-only sibling; supports split contrast. |

## Ownership And Emitter Decision

### Keep `CANONICAL_OWNER:NONE`

This is the correct owner state. The binary proves two source-use families:

- MapPane `sub_510960` appends `.PAL` twice while constructing map palette-related filenames.
- WorldMapPane `sub_5C2AC0` appends `.PAL` once while constructing a world-map palette lookup name.

Neither family proves it declared the suffix for the other. Assigning either file as canonical owner would overclaim source declaration ownership.

### Keep `EMITTER_UIDS:0000L3,0000PB`

Both emitters are justified:

- `0000L3` is justified by direct refs at `0x00510b57` and `0x00511041` in MapPane `sub_510960`.
- `0000PB` is justified by direct ref at `0x005c2eae` in WorldMapPane `sub_5C2AC0`.

Both emitters are by-file roots with reconstruction paths under `NexusTK/map/`. The generated no-owner route table lists both file docs. The fact that the current generated source files are empty is caused by blank reconstruction snippets, not by invalid emitter routing.

## Alternatives Rejected

| Alternative | Rejected because |
| --- | --- |
| Assign `CANONICAL_OWNER:0000L3` MapPane | MapPane has two direct uses, but WorldMapPane has a material direct source-use ref and is documented as a separate file root. No MapPane declaration owner is proven. |
| Assign `CANONICAL_OWNER:0000PB` WorldMapPane | WorldMapPane has one direct use, but MapPane has two direct source-use refs. No WorldMapPane declaration owner is proven. |
| Assign `CANONICAL_OWNER:0000MB` PaletteLib | `sub_543D70` receives caller-provided `wchar_t *Source`; it does not reference `0x0061ea24` or build `.PAL`. PaletteLib is a downstream palette lookup/load API here. |
| Assign the split index `0003IX` as owner | `0003IX` is a non-emitting physical island/split index, not a source declaration owner. |
| Create a synthetic shared constants owner | No source/debug metadata, initializer object, named global, or separate constants module is proven. |
| Drop one emitter | Dropping `0000L3` would lose two direct source-use refs; dropping `0000PB` would lose the WorldMapPane constructor-family source-use ref. |
| Merge with `0003JI` or the full `0003IX` island | Adjacent strings have different xref sets and ownership. Merging would mix MapPane-only and shared literals. |
| Reclassify as not reconstructable | This is an exact source string literal used by generated functions. It is reconstructable, even though no standalone shared declaration is proven. |
| Rename or IDA-safe-name repair | Current name `SharedMapPaletteSuffixString` is accurate, owner-neutral, and consistent with the split. IDA `aPal` is generic but not harmful. |

## Required Edits

No target documentation edits are required.

Do not edit `by-memory/-coverage-report.md` for this target. Current shared report text is acceptable and can remain:

```text
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; B003 post-migration and B001 second-pass reviews confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner, PaletteLib owner, split, merge, or reclassification justified.
```

If the supervisor wants a provenance-refresh-only replacement, use this exact row, but it is not required for correctness:

```text
                - [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; 2026-06-14 B001 current no-owner research reconfirmed direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, raw PE `push 0x0061ea24` matches at those three VAs only, and no single semantic declaration owner, PaletteLib owner, split, merge, reclassification, or IDA repair is justified.
```

Generated memory coverage row should remain:

```text
| [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |  |
```

## Validation And Lease State

- Files changed by this pass: `tools/leaser/Agents/Agent-B001/research/0003JG-SharedMapPaletteSuffixString-current-no-owner-research.md`.
- No by-* target documentation was edited.
- No `by-memory/-coverage-report.md` edit was made.
- No validator was run because only this Agent-B001 research report was created and no schema-bearing target file was changed.
- Leases used: none. The only edited file is inside Agent-B001's own research folder.
- Dry runs used: none.

## Confidence

- Completion remains `87`: the byte range, source-use functions, emitter routes, and split boundaries are well covered; original source spelling/declaration style is still not provable from the stripped binary.
- Confidence remains `93`: IDA bytes, IDA xrefs, decompiler output, component analysis, current documentation, and raw PE reference scanning all agree on the same target facts.
- Residual uncertainty: whether the original source repeated `L".PAL"` in both files or used an unobserved named shared constant before linker pooling. That uncertainty is exactly why `CANONICAL_OWNER:NONE` is the correct current model.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B001/0003JG-SharedMapPaletteSuffixString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
