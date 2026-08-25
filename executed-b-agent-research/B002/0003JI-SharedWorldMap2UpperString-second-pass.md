** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Second-Pass Ownership / Emitter Audit

Assignment: B002-0003JI-second-pass  
Agent: Agent-B002  
Date: 2026-06-13

## Final Recommendation

Keep the current generated state for [UID:0003JI] `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`.

| Field | Recommendation |
| --- | --- |
| `CANONICAL_OWNER` | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000L3,0000PB` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Score | retain `87/93` |
| Split / merge / reclassify | no split, merge, or reclassification |
| IDA repair | no IDA function, string, or boundary repair required |
| Coverage-report change | none required |

This is a valid no-owner-with-emitters case under the current owner/emitter model. The item is a compiler/linker-pooled UTF-16 `WM2` string literal with exactly two proven source-use contexts: `MapPane` packet/object world-map handling and `WorldMapPane` special-region/helper logic. IDA and raw PE evidence prove those emitter routes, but they do not prove a single original declaration/source owner. Assigning `MapPane`, `WorldMapPane`, the physical split index, or a speculative shared constants file as canonical owner would overclaim the evidence.

The current no-owner state is therefore not a dead/non-emitting reconstructable state: `EMITTER_UIDS:0000L3,0000PB` routes the literal to the two proven source contexts while preserving `CANONICAL_OWNER:NONE` for the unresolved pooled declaration.

## Target And Current State

| Item | Value |
| --- | --- |
| UID | `0003JI` |
| Path | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |
| Range | `0x0061ea48-0x0061ea50` |
| Current page score | `COMPLETION:87`, `CONFIDENCE:93` |
| Current page metadata | `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3,0000PB` |
| Current generated row | `no-owner`, canonical owner `NONE`, emitters `0000L3`,`0000PB` |
| Prior report read as background | `Agent-B001/research/executed/0003JI-SharedWorldMap2UpperString-post-migration.md` |

The prior B001 report recommended the current state. This pass independently rechecked the target using live IDA MCP, raw PE scans, current by-* documentation, generated coverage, and the current owner/emitter rules.

## Rule Basis

`by-structure.md` separates semantic ownership from output routing:

| Rule area | Applied conclusion |
| --- | --- |
| `CANONICAL_OWNER` | Must be the narrowest direct semantic owner, not just the nearest file or first generated output root. |
| `EMITTER_UIDS` | Controls output routing and can list multiple UIDs. It is not ownership. |
| Shared literals | Pooled/shared literals may remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while using multiple emitters for proven source-use contexts. |
| Reconstructable no-owner state | Reconstructable ownerless items are acceptable while ownership is not proven; when source uses are proven, emitters should be listed. |
| Source category | String literals are `source-declared/generated-binary`: source declarations/usages matter, but exact bytes are produced by compiler/linker output. |

## IDA MCP Evidence

Session used: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`. `server_health` reported `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

### Exact Bytes And Strings

| Address | IDA result |
| --- | --- |
| `0x0061ea24-0x0061ea70` | UTF-16 string island: `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4` |
| `0x0061ea48-0x0061ea50` | bytes `57 00 4d 00 32 00 00 00` |
| `0x0061ea48` | `get_string` value `WM2`, IDA name `aWm2_0` |
| `0x0061ea4c` | `get_string` decodes interior tail as `2`, but xrefs are zero; this is not a separate object |
| `0x0061ea50` | successor string `wm3`, separate child boundary |

IDA names in the neighborhood:

| Address | IDA name |
| --- | --- |
| `0x0061ea24` | `aPal` |
| `0x0061ea30` | `aWm` |
| `0x0061ea38` | `aWm_0` |
| `0x0061ea40` | `aWm2` |
| `0x0061ea48` | `aWm2_0` |
| `0x0061ea50` | `aWm3` |
| `0x0061ea58` | `aWm3_0` |
| `0x0061ea60` | `aWm4` |
| `0x0061ea68` | `aWm4_0` |

### Direct Xrefs

| Referenced address | Xref count | Xref sites | Owner/emitter implication |
| --- | ---: | --- | --- |
| `0x0061ea30` `wm` | 1 | `0x005121a1` in `sub_511DB0` | MapPane-only sibling child |
| `0x0061ea38` `WM` | 1 | `0x005121e3` in `sub_511DB0` | MapPane-only sibling child |
| `0x0061ea40` `wm2` | 1 | `0x00512223` in `sub_511DB0` | MapPane-only sibling child |
| `0x0061ea48` `WM2` | 2 | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | shared MapPane and WorldMapPane source use |
| `0x0061ea4c` interior | 0 | none | no split at interior tail |
| `0x0061ea50` `wm3` | 1 | `0x005122a3` in `sub_511DB0` | successor child, MapPane-only |
| `0x0061ea58` `WM3` | 1 | `0x005122e3` in `sub_511DB0` | successor child, MapPane-only |
| `0x0061ea60` `wm4` | 1 | `0x00512323` in `sub_511DB0` | successor child, MapPane-only |
| `0x0061ea68` `WM4` | 1 | `0x0051235f` in `sub_511DB0` | successor child, MapPane-only |

`search_text` over `0x00511db0-0x0051283a` found one rendered `aWm2_0` use:

```text
0x00512263 sub_511DB0: mov ecx, offset aWm2_0 ; "WM2"
```

`search_text` over `0x005c5200-0x005c53d0` found one rendered `aWm2_0` use:

```text
0x005c5219 sub_5C5200: push offset aWm2_0 ; "WM2"
```

`trace_data_flow` backward from `0x0061ea48` found the same two direct code users and no additional data-owner path:

| Depth | Address | Function | Instruction |
| ---: | --- | --- | --- |
| 0 | `0x0061ea48` | none | `text "UTF-16LE", 'WM2',0` |
| 1 | `0x00512263` | `sub_511DB0` | `mov ecx, offset aWm2_0; "WM2"` |
| 1 | `0x005c5219` | `sub_5C5200` | `push offset aWm2_0; "WM2"` |

### Function Context

| Function | IDA facts | Documentation/source implication |
| --- | --- | --- |
| `sub_511DB0` at `0x00511db0`, size `0xa8a` | Prototype `char __thiscall(_DWORD *this, int)`, complex packet/object helper; direct `WM2` reference at `0x00512263`; calls include `sub_5C2AC0` | Covered by MapPane packet/object handling and tied to `MapPane.cpp`; valid emitter `0000L3` |
| `sub_5C5200` at `0x005c5200`, size `0x1d0` | Prototype `char __thiscall(float *this, int, int)`; direct `WM2` reference at `0x005c5219`; callee `sub_5845B0` | WorldMapPane internal helper; valid emitter `0000PB` |
| `sub_5C48B0` at `0x005c48b0`, size `0x320` | Calls `sub_5C5200`; caller `sub_5C3950` | Places `sub_5C5200` inside WorldMapPane helper chain |
| `sub_5C3950` at `0x005c3950`, size `0x4f1` | Calls `sub_5C48B0`; data xref from WorldMapPane vtable/read-only area | Further supports WorldMapPane source context, not MapPane ownership |

`analyze_component` on `0x00511db0`, `0x005c5200`, `0x005c48b0`, and `0x005c3950` reported:

| Component result | Evidence |
| --- | --- |
| Internal WorldMapPane chain | `0x5c3950 -> 0x5c48b0 -> 0x5c5200` |
| Shared global/string | `0x61ea48 aWm2_0` accessed by `sub_511DB0` and `sub_5C5200` |
| Interface distinction | `sub_511DB0` listed as interface function; `sub_5C5200`, `sub_5C3950`, and `sub_5C48B0` listed as internal-only in the analyzed component |

This is strong emitter evidence for both `MapPane` and `WorldMapPane`, but it does not prove that either source file uniquely declared the pooled literal.

## Raw PE Evidence

Raw scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

| Pattern | Raw hits | Interpretation |
| --- | ---: | --- |
| UTF-16 exact bytes `57 00 4d 00 32 00 00 00` | `0x21D448` only | one physical `WM2` literal object, mapped to VA `0x0061EA48` |
| UTF-16 `WM2` without final NUL | `0x21D448` only | no second duplicate wide `WM2` object |
| ASCII `WM2\0` | none | no ASCII duplicate |
| VA immediate `0x0061EA48` | `0x111664`, `0x1C461A` | maps to `.text` VAs `0x00512264` and `0x005C521A`, matching the two IDA code xrefs |
| Interior VA immediate `0x0061EA4C` | none | no pointer to interior `2` tail |
| Successor VA immediate `0x0061EA50` | `0x1116A4` | separate successor `wm3` reference in MapPane, not part of this child |
| RVA immediates `0x0021EA48`, `0x0021EA4C`, `0x0021EA50` | none | no hidden RVA table use |

PE sections used for mapping:

| Section | VA | Raw pointer | Raw size |
| --- | --- | --- | --- |
| `.text` | `0x00401000` | `0x400` | `0x20B600` |
| `.rdata` | `0x0060D000` | `0x20BA00` | `0x5F200` |
| `.data` | `0x0066D000` | `0x26AC00` | `0xD800` |
| `.rsrc` | `0x0069D000` | `0x278400` | `0x15E00` |

The raw bytes independently confirm the exact object boundary and reject a further split at `0x0061ea4c`.

## Documentation Evidence

| Document | Evidence used | Result |
| --- | --- | --- |
| Target page `0003JI` | Documents exact `0x0061ea48-0x0061ea50` range, UTF-16 `WM2`, current `NONE` plus `0000L3,0000PB`, and prior IDA/PE facts | Confirmed by this pass |
| `0003IX` split index | Records exact child split for `.PAL` and `WM*` string island; `0003JI` is the only `WM2` shared child | Confirmed; split index remains non-emitting |
| `0003JH` child | `wm`, `WM`, `wm2` are MapPane-only and route to `0000L3` | Confirmed by IDA xrefs |
| `0003JJ` child | `wm3`, `WM3`, `wm4`, `WM4` are MapPane-only and route to `0000L3` | Confirmed by IDA xrefs |
| `0003JG` sibling | Shared `.PAL` literal uses same no-owner-with-MapPane/WorldMapPane-emitter pattern | Strong precedent, but not used as sole proof |
| `by-file/MapPane.md` `[UID:0000L3]` | Valid source root `NexusTK/map/MapPane.cpp`, includes MapPane packet/resource string evidence and excludes WorldMapPane implementation ownership | Supports emitter `0000L3`, not canonical owner |
| `by-file/WorldMapPane.md` `[UID:0000PB]` | Valid source root `NexusTK/map/WorldMapPane.cpp`, separate from MapPane; owns WorldMapPane implementation/helper logic | Supports emitter `0000PB`, not sole canonical owner |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | Documents `sub_511DB0` as MapPane object-create/world-map helper called from MapPane packet flow | Supports emitter `0000L3` |
| `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md` | Documents `0x005c2ac0-0x005c5c87` as WorldMapPane implementation with private helpers | Supports emitter `0000PB` |

Current generated coverage already reflects the correct state:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
```

The generated source path in that row is a report routing artifact for a multi-emitter item; it should not be read as canonical ownership by `MapPane`.

## Ranked Owner / Emitter Analysis

| Candidate | Decision | Rationale |
| --- | --- | --- |
| `CANONICAL_OWNER:NONE` | keep | Best fit. The literal is pooled/shared, has one physical object, and is materially used by independent MapPane and WorldMapPane source contexts. No source metadata or data-owner object proves one declaration owner. |
| `EMITTER_UIDS:0000L3,0000PB` | keep | IDA and raw PE prove the complete use set: `sub_511DB0` under MapPane and `sub_5C5200` under WorldMapPane. Both emitter roots are documented valid file roots. |
| Canonical owner `0000L3` MapPane | reject | MapPane has one direct source-use site and adjacent sibling literals, but WorldMapPane also directly uses this exact literal. Assigning MapPane canonical ownership would overclaim a pooled declaration. |
| Canonical owner `0000PB` WorldMapPane | reject | WorldMapPane has one direct source-use site, but the broader `wm`/`WM*` name-comparison series is mostly MapPane-side and `sub_511DB0` directly uses this exact object. |
| Canonical owner `0003IX` split index | reject | `0003IX` is an audit/split index, not a source declaration owner or output root. |
| New shared constants owner/file | reject | No PDB/source-path, writer, initializer table, named global, or source-tree evidence supports a standalone constants file. Current rules explicitly warn not to invent a helper file solely to avoid `NONE`. |
| Split into `WM` plus `2` tail | reject | IDA and raw PE find zero xrefs to `0x0061ea4c`; the interior `get_string` decode is just the UTF-16 tail of `WM2`. |
| Merge back into surrounding island | reject | Neighboring child xrefs differ: `0003JH`/`0003JJ` are MapPane-only, while `0003JI` and `0003JG` are shared. The exact child page is necessary and already correct. |
| Reclassify non-reconstructable | reject | This is a source-declared/generated-binary string literal with proven source-use contexts. It should remain reconstructable, but without a C++ code block until source shape/output policy requires one. |

## Negative Evidence Checked

- No xrefs to interior address `0x0061ea4c`.
- No raw `0x0061EA4C` immediate.
- No RVA references for the target or interior tail.
- No ASCII duplicate and no second UTF-16 duplicate of `WM2`.
- No third code xref beyond `sub_511DB0` and `sub_5C5200`.
- Neighbor strings do not share the same xref profile; `wm`, `WM`, `wm2`, `wm3`, `WM3`, `wm4`, and `WM4` are MapPane-only.
- Documentation does not provide source/debug metadata proving that either `MapPane.cpp` or `WorldMapPane.cpp` declared the literal.
- The physical split index is not a source owner and should remain non-emitting.
- The current `auto-generated` row's single generated path does not override the multi-emitter metadata.

## Score Before / After

| Metric | Before | After | Reason |
| --- | ---: | ---: | --- |
| Completion | 87 | 87 | The target is already exact and well researched, but final original declaration ownership remains unprovable from available binary evidence. |
| Confidence | 93 | 93 | Exact bytes, raw uniqueness, xrefs, and emitter routes are very strong. Confidence stays below final-audit levels because the original source declaration/file cannot be proven. |

No score change is recommended. The current score correctly represents a high-confidence pooled literal with unresolved canonical declaration ownership.

## Exact Recommended Changes

No by-* documentation changes are required.

No `by-memory/-coverage-report.md` replacement row is required. The current row already expresses the correct state and adequate provenance:

```text
                - [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001-0003JI post-migration recheck keeps `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but recommends `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`).
```

Optional supervisor-only provenance refresh, if desired, can replace `B001-0003JI post-migration recheck` with `B001 post-migration and B002 second-pass rechecks`, but this is not needed for correctness.

No metadata/header edits are required. If the supervisor wants the final metadata stated explicitly, it should remain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
```

## Validation Performed

No dry-run validator mode was used. No memory-range validator mode was used. No by-* documentation was edited, so normal documentation validation was not required.

Commands/evidence collected:

| Evidence source | Result |
| --- | --- |
| IDA MCP `idb_list` / `server_health` | Active session `b001_0003gy`, NexusTK.exe, analysis and Hex-Rays ready |
| IDA MCP `get_bytes` | Confirmed exact `WM2` bytes at `0x0061ea48-0x0061ea50` and neighboring string island bytes |
| IDA MCP `get_string` | Confirmed `.PAL`, `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, `WM4` values |
| IDA MCP `xrefs_to` | Confirmed exactly two xrefs to `0x0061ea48`, zero to `0x0061ea4c`, and MapPane-only xrefs to neighboring child strings |
| IDA MCP `lookup_funcs` | Confirmed `sub_511DB0`, `sub_5C5200`, `sub_5C48B0`, `sub_5C3950`; confirmed target data is not a function |
| IDA MCP `search_text` | Confirmed exact rendered operand use at `0x00512263` and `0x005c5219` |
| IDA MCP `trace_data_flow` | Confirmed two direct code users and no additional owner route |
| IDA MCP `analyze_component` | Confirmed shared global `aWm2_0` across MapPane and WorldMapPane functions and internal WorldMapPane chain |
| Raw PE scan | Confirmed single physical UTF-16 `WM2` object, exactly two target VA immediates, no interior pointer, no RVA pointer, no ASCII duplicate |
| Documentation review | Confirmed current target, split index, siblings, MapPane/WorldMapPane file roots, generated coverage row, coverage-report row, and tracker state |

## Changed Files

Created this final report only:

```text
tools/leaser/Agents/Agent-B002/research/0003JI-SharedWorldMap2UpperString-second-pass.md
```

No by-* files, generated reports, tracker files, or coverage reports were edited.

## Blockers / Residual Risk

No external blocker prevented completion.

Residual risk is limited to original source-declaration recovery: without a matching PDB, linker map, source file, or other debug metadata, the binary proves source-use contexts but not which source file first declared the pooled literal. That residual risk supports retaining `CANONICAL_OWNER:NONE`; it does not block the proven `0000L3,0000PB` emitter routing.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B002/0003JI-SharedWorldMap2UpperString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
