** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# 0003JG SharedMapPaletteSuffixString Live Goal 2 No-Owner Pass

## Final Recommendation

Keep [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](../../../../../by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) unchanged:

| Field | Recommendation |
| --- | --- |
| `CANONICAL_OWNER` | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000L3,0000PB` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Score | retain `87/93` |
| Split / merge / reclassify | no split, merge, or reclassification |
| Child pages | no new child pages required |
| Coverage-report change | none required |

This is a valid `CANONICAL_OWNER:NONE` with emitters case, not a dead/non-emitting item. Live IDA MCP confirms the exact UTF-16 `.PAL` literal has three direct source-use refs: two in MapPane helper `sub_510960` (`0x00510b57`, `0x00511041`) and one in the WorldMapPane constructor-family function `sub_5C2AC0` (`0x005c2eae`). Current source-routing docs make [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) and [UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md) valid output roots, but the binary does not prove a single original declaration owner. Assigning either source file, the split-index parent, or a speculative shared constants owner would overclaim.

The exact final metadata should remain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
```

No `by-memory/-coverage-report.md` edit is required. The current row already records the correct owner/emitter result and sufficient evidence.

## Assignment

| Item | Value |
| --- | --- |
| Agent | Agent-B002 |
| Date | 2026-06-14 |
| Target UID | `0003JG` |
| Target path | `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` |
| Range | `0x0061ea24-0x0061ea30` |
| Current target state | `COMPLETION:87`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB` |
| Tracker row | Active live Goal 2 no-owner memory pass row assigned to Agent-B002 |

This is a fresh pass. Prior reports and target-page prose were treated as leads only; the decision below uses current documentation, live IDA MCP, and an independent PE byte/reference scan.

## Rule Basis

Current `by-structure.md` separates the two questions:

| Rule area | Applied conclusion |
| --- | --- |
| `CANONICAL_OWNER` | Requires a direct semantic/source declaration owner. Source-use alone is not enough when two independent source roots directly use one pooled object. |
| `EMITTER_UIDS` | Output routing may list multiple proven source-use emitters and is not itself an ownership claim. |
| Shared literals | Pooled/shared literals may stay `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while still routing through all proven source-use emitters. |
| Reconstructable no-owner state | `RECONSTRUCTABLE:TRUE` is correct for a source-declared/generated-binary string literal even when canonical declaration ownership remains unresolved. |

## Current Documentation Checked

| Document | Current evidence | Result |
| --- | --- | --- |
| Target page `0003JG` | Exact `0x0061ea24-0x0061ea30` child, UTF-16 `.PAL`, current `NONE` plus `0000L3,0000PB` | Confirmed by live IDA and PE evidence |
| Split index `0003IX` | Parent island split into `.PAL`, MapPane-only comparison strings, shared `WM2`, and MapPane-only `wm3`/`wm4` strings | Current child split remains necessary and clean |
| Sibling `0003JH` | `wm`, `WM`, `wm2` route to MapPane only | Supports keeping target separate from MapPane-only neighbors |
| Sibling `0003JI` | Shared `WM2` uses same no-owner plus MapPane/WorldMapPane emitter model | Supports the current owner/emitter model; not used as sole proof |
| Sibling `0003JJ` | `wm3`, `WM3`, `wm4`, `WM4` route to MapPane only | Supports no merge back into the full island |
| `by-file/MapPane.md` `0000L3` | `NexusTK/map/MapPane.cpp` source root at `89/85`; records MapPane resource-string children and says shared `.PAL` remains parentless | Valid emitter route `0000L3` |
| `by-file/WorldMapPane.md` `0000PB` | Separate `NexusTK/map/WorldMapPane.cpp` source root at `90/86`; owns world-map UI implementation | Valid emitter route `0000PB` |
| `0x0050e4c0-0x00514920.MapPanePacketHandlers` | Documents `sub_510960` and `sub_511DB0` inside MapPane packet/helper coverage | Places two `.PAL` refs in MapPane source context |
| `0x005c2ac0-0x005c5c87.WorldMapPane` | Documents `sub_5C2AC0` as WorldMapPane constructor-family implementation | Places one `.PAL` ref in WorldMapPane source context |

## Live IDA MCP Evidence

Session used: `a001_goal2_class_batch`.

`server_health` reported active `NexusTK.exe`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

### Exact Bytes And Strings

| Address | Live result |
| --- | --- |
| `0x0061ea24-0x0061ea30` | bytes `2e 00 50 00 41 00 4c 00 00 00 00 00` |
| `0x0061ea24` | `get_string` value `.PAL` |
| `0x0061ea30` | successor string `wm` |
| `0x0061ea48` | separate shared sibling string `WM2` |
| `0x0061ea70` | next successor string `%s\\Mscfg.dll` |

`get_bytes 0x0061ea24 size 0x4c` confirms the full parent island sequence:

```text
.PAL, wm, WM, wm2, WM2, wm3, WM3, wm4, WM4
```

The target half-open range ends before `wm` at `0x0061ea30`; no boundary repair is needed.

### Function Lookup

| Query | IDA function result |
| --- | --- |
| `0x00510960` | `sub_510960`, size `0x9e7` |
| `0x00510b57` | contained in `sub_510960` |
| `0x00511041` | contained in `sub_510960` |
| `0x00511db0` | `sub_511DB0`, size `0xa8a` |
| `0x005c2ac0` | `sub_5C2AC0`, size `0x7ea` |
| `0x005c2eae` | contained in `sub_5C2AC0` |
| `0x005c5200` | `sub_5C5200`, size `0x1d0` |
| `0x0061ea24` | not a function |

### Direct Xrefs

| Referenced address | Count | Live xref sites | Source-routing implication |
| --- | ---: | --- | --- |
| `0x0061ea24` `.PAL` | 3 | `0x00510b57`, `0x00511041` in `sub_510960`; `0x005c2eae` in `sub_5C2AC0` | shared MapPane and WorldMapPane source use |
| `0x0061ea30` `wm` | 1 | `0x005121a1` in `sub_511DB0` | MapPane-only successor child |
| `0x0061ea48` `WM2` | 2 | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | separate shared sibling child |
| `0x0061ea50` `wm3` | 1 | `0x005122a3` in `sub_511DB0` | MapPane-only successor child |
| `0x0061ea70` `%s\\Mscfg.dll` | 2 | successor child refs, outside target | clean next boundary |

### Instruction Text

Filtered `disasm` on the containing functions shows all target refs are direct offset operands:

```text
0x00510b57: push offset aPal; ".PAL" [0x61ea24:aPal]
0x00511041: push offset aPal; ".PAL" [0x61ea24:aPal]
0x005c2eae: push offset aPal; ".PAL" [0x61ea24:aPal]
```

The sibling `WM2` direct WorldMapPane ref is separate:

```text
0x005c5219: push offset aWm2_0; "WM2" [0x61ea48:aWm2_0]
```

### Decompiler Context

Hex-Rays for `sub_510960` shows the MapPane path copies a map/resource name to a wide buffer and appends `L".PAL"` in two branch variants:

```text
wcscpy_s(...);
wcscat_s(..., L".PAL");
```

Hex-Rays for `sub_5C2AC0` shows the WorldMapPane constructor-family path taking the current vector/name value, appending `L".PAL"`, and passing the result to the palette/resource load helper:

```text
sub_584470(..., L".PAL", 4u);
sub_543D70(...);
```

These are source-use contexts for two different file roots. They do not prove which source file declared or owned the pooled literal object.

### Component Analysis

`analyze_component` over `0x00510960`, `0x00511db0`, `0x005c2ac0`, and `0x005c5200` reports:

| Shared global | Accessed by |
| --- | --- |
| `0x61ea24` `aPal` | `sub_510960`, `sub_5C2AC0` |
| `0x61ea48` `aWm2_0` | `sub_511DB0`, `sub_5C5200` |

It also reports the internal call edge `sub_511DB0 -> sub_5C2AC0`, which matches the documented MapPane-to-WorldMapPane creation relationship. That relationship supports both source contexts; it does not collapse WorldMapPane implementation data into MapPane ownership.

## Independent PE Evidence

Raw scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

| Check | Result |
| --- | --- |
| MD5 | `4247e04e20b65d6414c7238aa8ff5515` |
| PE imagebase | `0x400000` |
| Section mapping | `.text` raw `0x400-0x20ba00` -> RVA `0x1000-0x20c600`; `.rdata` raw `0x20ba00-0x26ac00` -> RVA `0x20d000-0x26c200` |
| Full parent island bytes `.PAL, wm, WM, wm2, WM2, wm3, WM3, wm4, WM4` | one hit at file offset `0x21d424`, mapping to VA `0x0061ea24` |
| Target VA immediate `0x0061ea24` | three dword hits at file offsets `0x10ff58`, `0x110442`, `0x1c22af`, mapping to operand VAs `0x00510b58`, `0x00511042`, `0x005c2eaf` |
| Target RVA immediate `0x0021ea24` | no hits |

The many generic UTF-16 `.PAL` extension occurrences in the executable are not ownership evidence by themselves. The unique full parent-island hit and the three absolute target-VA operand hits independently match the live IDA xref set for this exact object.

## Ranked Owner / Emitter Analysis

| Candidate | Decision | Rationale |
| --- | --- | --- |
| `CANONICAL_OWNER:NONE` | keep | Best fit. The exact object is a pooled/shared UTF-16 suffix with material direct use in both MapPane and WorldMapPane. No source metadata, table, initializer, or data owner proves one declaration owner. |
| `EMITTER_UIDS:0000L3,0000PB` | keep | Live IDA and raw PE prove MapPane refs in `sub_510960` and a WorldMapPane ref in `sub_5C2AC0`; current by-file pages make both valid source output roots. |
| Canonical owner `0000L3` MapPane | reject | MapPane has two direct refs and adjacent MapPane-only strings, but WorldMapPane directly uses the same exact `.PAL` object. MapPane canonical ownership would overclaim the shared declaration. |
| Canonical owner `0000PB` WorldMapPane | reject | WorldMapPane has a direct constructor-family use, but MapPane has two independent uses of the same object. WorldMapPane canonical ownership would overclaim in the opposite direction. |
| Canonical owner `0003IX` split index | reject | The parent is a documentation/split index, not a source owner or generated output root. |
| New shared constants/source file | reject | No PDB/source path, source-tree page, named global declaration, initializer table, or exclusive data-owner evidence supports creating a standalone shared constants owner. |
| Merge back into the full `0003IX` island | reject | Neighboring child xref profiles differ: `0003JH`/`0003JJ` are MapPane-only, `0003JI` is a separate shared `WM2` literal, and this target is exactly the shared `.PAL` suffix. |
| Reclassify non-reconstructable | reject | This is source-declared/generated-binary string data with proven source-use contexts and should remain reconstructable. |

## Why No-Owner With Emitters Is Correct

The current system treats ownership and emission separately. `CANONICAL_OWNER:NONE` records that no single original declaration owner is defensible. `EMITTER_UIDS:0000L3,0000PB` records that the literal must be available through both proven source-use roots during generated output.

That is the right shape here:

- A MapPane-only owner would lose the direct WorldMapPane constructor-family use.
- A WorldMapPane-only owner would lose the two direct MapPane helper uses.
- A shared invented owner would add a source file not proven by IDA, PE, or documentation.
- A blank emitter list would be wrong because this target is not an unreferenced helper; it has concrete source-use routes in two valid roots.

So the item remains ownerless because declaration ownership is unresolved, and emitting because source-use routes are resolved.

## Score Before / After

| Metric | Before | After | Reason |
| --- | ---: | ---: | --- |
| Completion | 87 | 87 | The exact range, bytes, xrefs, split boundaries, and emitters are already documented. Completion is not raised because original declaration ownership remains unproven. |
| Confidence | 93 | 93 | Live IDA and PE evidence strongly confirm the current route. Confidence remains below final/source-declaration certainty because no direct owner metadata exists. |

## Coverage Row

No replacement row is required. The current coverage-report row already expresses the correct state:

```text
- [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 .PAL suffix with CANONICAL_OWNER:NONE and EMITTER_UIDS:0000L3,0000PB; prior reviews confirm direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`, with no single semantic declaration owner, PaletteLib owner, split, merge, or reclassification justified.
```

If the supervisor wants provenance refreshed to mention this live Agent-B002 pass, the exact replacement text would be:

```text
- [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) 0x0061ea24-0x0061ea30 | string-data | SharedMapPaletteSuffixString : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000PB`; Agent-B002 live Goal 2 pass on 2026-06-14 reconfirmed bytes `2e 00 50 00 41 00 4c 00 00 00 00 00`, direct source-use refs from MapPane `sub_510960` at `0x00510b57`/`0x00511041`, direct WorldMapPane constructor-family ref from `sub_5C2AC0` at `0x005c2eae`, unique full parent-island PE sequence at VA `0x0061ea24`, and exactly three target-VA immediate operands. No single semantic declaration owner, PaletteLib/shared-constants owner, split, merge, or reclassification is justified.
```

Do not edit `by-memory/-coverage-report.md` directly from this pass.

## Validation Performed

No dry runs were used.

| Evidence source | Result |
| --- | --- |
| Current docs | Re-read target, parent split index, sibling children, MapPane/WorldMapPane file pages, MapPane packet-handler aggregate, WorldMapPane aggregate, generated/tracker context |
| IDA MCP `server_health` / `idb_list` | Confirmed active `a001_goal2_class_batch`, `NexusTK.exe`, imagebase `0x400000`, Hex-Rays and string cache ready |
| IDA MCP `lookup_funcs` | Confirmed containing functions and that target data addresses are not functions |
| IDA MCP `get_bytes` / `get_string` | Confirmed exact `.PAL` bytes/string and neighboring child boundaries |
| IDA MCP `xrefs_to` | Confirmed exactly three refs to `0x0061ea24` and differing sibling xref profiles |
| IDA MCP `disasm` | Confirmed all three target refs are `push offset aPal; ".PAL"` |
| IDA MCP `decompile` | Confirmed MapPane appends `L".PAL"` to wide map-name buffers and WorldMapPane appends `L".PAL"` before palette/resource load |
| IDA MCP `analyze_component` | Confirmed `aPal` is shared by `sub_510960` and `sub_5C2AC0`; confirmed `WM2` is a separate shared sibling |
| Raw PE scan | Confirmed MD5, section mapping, unique full parent-island physical sequence, exactly three target VA-immediate operands, and no target RVA immediate |

## Changed Files

Created this report only:

```text
tools/leaser/Agents/Agent-B002/research/0003JG-SharedMapPaletteSuffixString-live-goal2-no-owner-pass.md
```

No by-* files, generated reports, tracker files, or coverage reports were edited. No lease was needed because the only edit is inside the Agent-B002 research folder.

## Residual Risk

Residual risk is limited to original source-declaration recovery. A future PDB, linker map, source archive, or stronger source-tree evidence could prove a single declaration site for the pooled `.PAL` suffix. Current IDA and PE evidence prove use routes, not declaration ownership, so the correct current state is `CANONICAL_OWNER:NONE` with emitters `0000L3,0000PB`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B002/0003JG-SharedMapPaletteSuffixString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
