** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# Final Recommendation

Keep [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](../../../../../by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) unchanged:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000PB
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

No canonical owner, emitter change, split, merge, reclassification, new child page, IDA repair, or shared coverage-report edit is justified. Fresh IDA MCP and raw PE evidence confirm one physical UTF-16LE `WM2` literal at `0x0061ea48`, exactly two direct references to the literal start, no references to interior addresses, and proven source-use contexts in both MapPane and WorldMapPane. The current model is the correct one: no defensible single declaration owner, but two required source-use emitters.

No project documentation files outside this Agent-B002 research report need editing. No `by-memory/-coverage-report.md` replacement row is required; the current row should be retained.

# Research

## Target And Scope

- Assignment: `B002-goal2-noowner-verification-0003JI`
- Agent: Agent-B002
- Verification date: 2026-06-14
- Target UID: `0003JI`
- Target file: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Coverage source checked: `auto-generated/-ag-memory-coverage.md`
- Prior report used only as evidence lead: `Agent-B003/research/executed/0003JI-SharedWorldMap2UpperString-live-goal2-no-owner-pass.md`

This pass rechecked current target documentation, current generated coverage, current owner/emitter docs, by-structure owner/emitter rules, and fresh IDA MCP/PE evidence. No dry runs were used.

## Current Documentation State

The target page currently records:

- `COMPLETION:87`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000PB`
- Blank C++ block

The page classifies the bytes as a `source-declared/generated-binary` UTF-16 string literal. That classification still fits the current evidence: source must contain equivalent `L"WM2"` use sites, but the exact `.rdata` pooling is a compiler/linker artifact.

The authoritative generated coverage row in `auto-generated/-ag-memory-coverage.md` already matches the target page:

```text
| [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) | no-owner | `NONE` | `0000L3`,`0000PB` |  | no | `auto-generated/NexusTK/map/MapPane.cpp` | `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` |  |
```

`by-memory/-coverage-report.md` currently says the row is reconstructable, no-owner, and emitted through `0000L3,0000PB`; that is still correct.

## Current Structure Context

[UID:0003IX][0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings](../../../../../by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md) is a reviewed non-emitting split index, not a source object. Its exact children remain correctly separated:

| Range | UID | Text | Current route |
| --- | --- | --- | --- |
| `0x0061ea24-0x0061ea30` | `0003JG` | `.PAL` | no owner; emitters `0000L3,0000PB` |
| `0x0061ea30-0x0061ea48` | `0003JH` | `wm`, `WM`, `wm2` | MapPane |
| `0x0061ea48-0x0061ea50` | `0003JI` | `WM2` | no owner; emitters `0000L3,0000PB` |
| `0x0061ea50-0x0061ea70` | `0003JJ` | `wm3`, `WM3`, `wm4`, `WM4` | MapPane |

The by-structure rules explicitly allow `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals when no declaration owner is proven but multiple source-use contexts are proven. They also prohibit inventing a standalone global/helper owner merely to avoid `NONE`.

## Candidate Emitter Docs

[UID:0000L3][MapPane](../../../../../by-file/MapPane.md) is a valid `NexusTK/map/` source root at `89/85`. Its packet-handler aggregate [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](../../../../../by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) documents `0x00511db0 sub_511DB0` as the object-create/world-map helper called from the MapPane packet dispatcher.

[UID:0000PB][WorldMapPane](../../../../../by-file/WorldMapPane.md) is a valid `NexusTK/map/` source root at `90/86`. It documents `map/WorldMapPane.cpp` as a separate world-map/travel UI module, not a continuation of `MapPane.cpp`. [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](../../../../../by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) covers the implementation range containing `sub_5C5200`.

Both emitters clear the source-root gate. Neither one is a complete semantic declaration owner for the pooled literal.

## Fresh IDA MCP Evidence

IDA MCP session:

- Database: `a001_goal2_class_batch`
- Module: `NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Imagebase: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

### Bytes And Strings

`get_bytes` over `0x0061ea24` showed the current string island:

```text
.PAL, wm, WM, wm2, WM2, wm3, WM3, wm4, WM4, then %s\Mscfg.dll
```

The exact target bytes are:

```text
0x0061ea48: 57 00 4d 00 32 00 00 00
```

`get_string` decoded:

| Address | Result |
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

IDA can decode interior substrings at `0x0061ea4a` and `0x0061ea4c`, but those are not source items: `xrefs_to` reports zero references to the interior addresses.

### Direct Xrefs

`xrefs_to` returned:

| Address | Xrefs | Interpretation |
| --- | --- | --- |
| `0x0061ea30` | `0x005121a1` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea38` | `0x005121e3` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea40` | `0x00512223` in `sub_511DB0` | MapPane-only sibling |
| `0x0061ea48` | `0x00512263` in `sub_511DB0`; `0x005c5219` in `sub_5C5200` | target, shared MapPane/WorldMapPane |
| `0x0061ea4a` | none | no interior split |
| `0x0061ea4c` | none | no interior split |
| `0x0061ea4e` | none | no tail split |
| `0x0061ea50` | `0x005122a3` in `sub_511DB0` | successor sibling, MapPane-only |
| `0x0061ea58` | `0x005122e3` in `sub_511DB0` | successor sibling, MapPane-only |
| `0x0061ea60` | `0x00512323` in `sub_511DB0` | successor sibling, MapPane-only |
| `0x0061ea68` | `0x0051235f` in `sub_511DB0` | successor sibling, MapPane-only |

The split is still exact: `WM2` is the only string in this child, and its xref set differs from the adjacent MapPane-only children.

### Function And Instruction Evidence

`lookup_funcs` confirms:

| Query | Function |
| --- | --- |
| `0x00512263` | `sub_511DB0 @ 0x00511db0`, size `0xa8a` |
| `0x005c5219` | `sub_5C5200 @ 0x005c5200`, size `0x1d0` |
| `0x00508307` | `sub_507C90 @ 0x00507c90`, MapPane packet dispatcher |
| `0x005c4955`, `0x005c4acf` | `sub_5C48B0 @ 0x005c48b0` |
| `0x005c3e2b` | `sub_5C3950 @ 0x005c3950` |

Representative MapPane instruction slice:

```text
512263: mov ecx, offset aWm2_0; "WM2"
512268: lea eax, [ebp+WideCharStr]
512270: mov dx, [eax]
512273: cmp dx, [ecx]
512276: jnz short loc_512296
```

`decompile 0x00511db0` shows the converted local `WideCharStr` compared against `L"wm"`, `L"WM"`, `L"wm2"`, `L"WM2"`, `L"wm3"`, `L"WM3"`, `L"wm4"`, and `L"WM4"`, then later constructing/using the world-map path. This is a MapPane source-use context.

Representative WorldMapPane instruction slice:

```text
5c5219: push offset aWm2_0; "WM2"
5c521e: jnz loc_5C5307
...
5c5256: call sub_5845B0
```

`decompile 0x005c5200` shows `sub_5845B0(L"WM2")` in both control-flow branches. This is a WorldMapPane source-use context; `sub_5845B0` is a callee utility and is not an emitter for this literal.

This MCP server did not expose a `callers` tool in this session, so caller-chain evidence was collected with `xrefs_to` on function entrypoints:

| Function entry | Xrefs to entry |
| --- | --- |
| `0x00511db0` | code xref `0x00508307` from `sub_507C90` |
| `0x005c5200` | code xrefs `0x005c4955` and `0x005c4acf` from `sub_5C48B0` |
| `0x005c48b0` | code xref `0x005c3e2b` from `sub_5C3950` |

This preserves the route split: MapPane packet code reaches `sub_511DB0`, while the WorldMapPane implementation reaches `sub_5C5200`.

## Independent PE Evidence

Raw scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found:

| Pattern | Count | Sample raw offsets |
| --- | ---: | --- |
| UTF-16LE `WM2\0` (`57 00 4d 00 32 00 00 00`) | 1 | `0x21d448` |
| UTF-16LE `wm2\0` (`77 00 6d 00 32 00 00 00`) | 1 | `0x21d440` |
| ASCII `WM2\0` (`57 4d 32 00`) | 0 | none |
| VA `0x0061ea48` (`48 ea 61 00`) | 2 | `0x111664`, `0x1c461a` |
| VA `0x0061ea4a` | 0 | none |
| VA `0x0061ea4c` | 0 | none |
| VA `0x0061ea4e` | 0 | none |
| VA `0x0061ea50` | 1 | `0x1116a4` |
| RVA `0x0021ea48` | 0 | none |
| RVA `0x0021ea4a` | 0 | none |
| RVA `0x0021ea4c` | 0 | none |
| RVA `0x0021ea4e` | 0 | none |
| RVA `0x0021ea50` | 0 | none |

The raw PE scan independently matches IDA: one physical `WM2` literal, exactly two VA references to its start, no interior/tail references, and the `0x0061ea50` reference belongs to the successor `wm3` child.

## Candidate Owner And Emitter Analysis

### 1. Keep `CANONICAL_OWNER:NONE`

Decision: accepted.

The literal is a compiler-pooled source-use string. IDA proves two independent use sites, but it does not prove a source-level declaration owner such as a named global, a constants table, or a shared resource class. Choosing one consumer as canonical owner would encode a stronger declaration claim than the evidence supports.

### 2. MapPane as canonical owner

Decision: rejected as overclaiming.

Evidence for MapPane is real: `sub_511DB0` is reached from the MapPane packet dispatcher and compares a local `WideCharStr` against `L"WM2"`. MapPane is therefore a required emitter.

Evidence against canonical ownership is also direct: the same literal has a material WorldMapPane use at `0x005c5219`. MapPane owns the packet-side source use, not the whole pooled declaration.

### 3. WorldMapPane as canonical owner

Decision: rejected as overclaiming.

Evidence for WorldMapPane is real: `sub_5C5200` uses `L"WM2"` and its callers stay in the WorldMapPane implementation chain. WorldMapPane is therefore a required emitter.

Evidence against canonical ownership is the MapPane `sub_511DB0` comparison at `0x00512263`. WorldMapPane owns the world-map helper use, not the whole pooled declaration.

### 4. Parent split index `0003IX`

Decision: rejected.

The parent is a non-reconstructable split index over mixed strings with different xref sets. It is not an original source-level declaration.

### 5. New shared constants/global owner

Decision: rejected.

No IDA fact points to a named constants object, global variable, table initializer, or separate module for `WM2`. The binary shape is immediate references to pooled string storage. Creating a new owner would be less accurate than preserving use-site emitters.

### 6. Emitter set

Decision: keep exactly `0000L3,0000PB`.

`0000L3` is required for the MapPane `sub_511DB0` comparison. `0000PB` is required for the WorldMapPane `sub_5C5200` use. No third source-use family appears in the xrefs, and neither existing emitter can be removed without dropping a proven source-use context.

## Rejected Structural Changes

| Alternative | Reason rejected |
| --- | --- |
| Split `0x0061ea48-0x0061ea50` | The target is one complete UTF-16 `WM2\0` literal; interior/tail xrefs are zero. |
| Merge with predecessor `0003JH` | Predecessor strings are MapPane-only, while `WM2` is shared. |
| Merge with successor `0003JJ` | Successor strings are MapPane-only, while `WM2` is shared. |
| Merge back into parent `0003IX` | Parent is a mixed non-emitting split index; merging would lose correct routing differences. |
| Reclassify non-reconstructable | The text is required by reconstructable MapPane and WorldMapPane source-use sites. |
| Add standalone C++ declaration | Would invent a declaration owner not proven by IDA. Use-site `L"WM2"` is the safer source reconstruction shape. |
| Add `sub_5845B0` or its utility owner as emitter | It receives the pointer from WorldMapPane; it is not the source-use owner that should emit the literal. |

## Exact Recommended Changes

No changes are recommended for the target page, generated coverage, or shared by-memory coverage report.

Retain the current `by-memory/-coverage-report.md` row meaning. If reviewed during a future supervisor sync, no replacement is needed:

```text
- [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` pooled world-map-name literal; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because MapPane, WorldMapPane, the physical split index, and a speculative shared constants owner each overclaim declaration ownership, but retain `EMITTER_UIDS:0000L3,0000PB` because live IDA/PE evidence proves source-use contexts in MapPane `sub_511DB0` (`0x00512263`) and WorldMapPane special-region helper `sub_5C5200` (`0x005c5219`); B002 reconfirmed no interior-tail refs, no split/merge/reclassification, and no duplicate source object.
```

This is retain-only text, not a requested replacement.

## Validation And Execution Notes

- No dry runs used.
- No by-* documentation files edited.
- No generated files edited.
- No `by-memory/-coverage-report.md` edit made.
- No lease acquired because only this Agent-B002 research report was created.
- Validator not run because no validator-managed by-* page changed.
- IDA MCP inspection was read-only.
- The MCP `callers` method was unavailable in this session; `xrefs_to` on code entrypoints was used instead for caller-chain evidence.

## Confidence

Recommendation confidence: high.

The byte identity, unique physical literal, exact xrefs, boundary checks, current source-root docs, generated coverage row, and by-structure pooled-literal rule all agree. Remaining uncertainty is limited to original source style: the binary cannot prove whether the original code wrote two independent `L"WM2"` use-site literals or a shared named constant. That uncertainty is exactly why the page should keep `CANONICAL_OWNER:NONE` while retaining the two proven emitters.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B002/0003JI-SharedWorldMap2UpperString-goal2-verification.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
