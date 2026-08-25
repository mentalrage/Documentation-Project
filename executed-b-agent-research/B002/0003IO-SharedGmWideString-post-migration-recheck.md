** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# 0003IO SharedGmWideString Post-Migration Recheck

## Final Recommendation

Keep the current target metadata unchanged:

```text
UID:0003IO
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

This is a defensible no-owner-with-emitters pooled literal. IDA MCP and raw PE evidence confirm one exact UTF-16LE `GM` literal at `0x0061e6f8-0x0061e700`, with 20 direct code references split across three source roots: MapPane (`0000L3`), LivingObjectPane (`0000KU`), and ObjectList (`0000M4`). No single canonical declaration/source owner is proven, and assigning one of those consumers as `CANONICAL_OWNER` would overclaim the other two direct source-use contexts.

Recommended supervisor action: no by-memory metadata edit, no by-memory/-coverage-report.md edit, no split/merge/reclassification, and no IDA repair. The current generated no-owner row with `EMITTER_UIDS:0000L3,0000KU,0000M4` should remain. The item should not enter final reconstruction C++ as a standalone owned declaration: completion remains `88`, below the active `90/90+` code-entry bar, and the source shape is a pooled use-site literal rather than a proven global declaration.

## Target And Current State

| Field | Current value | Recheck result |
| --- | --- | --- |
| Target | [UID:0003IO] `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | exact target retained |
| Address range | `0x0061e6f8-0x0061e700` | exact 8-byte range retained |
| Classification | `string-data`, reconstructable | retained |
| Score | `88/93` | retained |
| Canonical owner | `NONE` | retained |
| Emitters | `0000L3,0000KU,0000M4` | retained, all three still justified |
| Split/merge | none pending | no split/merge needed |
| C++ entry | blank | remains blank; below 90 completion and no standalone owner |

## IDA MCP Evidence

Live IDA MCP session used: `b001_0003gy`, read-only `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready.

### Function And Xref Facts

IDA MCP `lookup_funcs` and `xrefs_to` results from this pass:

| Address/family | IDA result | Ownership/emitter implication |
| --- | --- | --- |
| `0x00505430` / xref `0x00505505` | function `sub_505430`, size `0x19a` | one direct MapPane source-use; keep emitter `0000L3` |
| `0x00514ea0` / xref `0x00514ec5` | function `sub_514EA0`, size `0x3d` | one direct LivingObjectPane source-use; keep emitter `0000KU` |
| `0x00533170` | function `sub_533170`, size `0x240`; refs at `0x0053321a`, `0x005332b5`, `0x0053334c` | ObjectList helper family; keep emitter `0000M4` |
| `0x005333b0` | function `sub_5333B0`, size `0x24e`; refs at `0x00533445`, `0x00533515`, `0x005335b7` | ObjectList helper family |
| `0x00533600` | function `sub_533600`, size `0x243`; refs at `0x005336a5`, `0x00533738`, `0x005337d7` | ObjectList helper family |
| `0x00533850` | function `sub_533850`, size `0x23d`; refs at `0x005338dc`, `0x0053397a`, `0x00533a1b` | ObjectList helper family |
| `0x00533a90` | function `sub_533A90`, size `0x267`; refs at `0x00533b3a`, `0x00533bfa`, `0x00533ca5` | ObjectList helper family |
| `0x00533d00` | function `sub_533D00`, size `0x26d`; refs at `0x00533d9a`, `0x00533e6a`, `0x00533f19` | ObjectList helper family |
| `0x0061e6f8` | not a function; 20 direct data xrefs | exact literal start |
| `0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe` | 0 xrefs | no interior/tail split evidence |
| `0x0061e700` | 0 xrefs | clean successor boundary |
| `0x0061e6f0` | one xref from data `0x0066db48` | separate `CMAP` child; not part of `GM` route |
| `0x0061e6c0`, `0x0061e6d8` | one direct code xref each | neighboring resource strings have separate owners/use sites |

The complete direct xref set to `0x0061e6f8` is:

```text
0x00505505
0x00514ec5
0x0053321a, 0x005332b5, 0x0053334c
0x00533445, 0x00533515, 0x005335b7
0x005336a5, 0x00533738, 0x005337d7
0x005338dc, 0x0053397a, 0x00533a1b
0x00533b3a, 0x00533bfa, 0x00533ca5
0x00533d9a, 0x00533e6a, 0x00533f19
```

IDA evidence supports exactly three emitter roots and no additional source-use routes.

### Raw PE Evidence

Raw scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

| Check | Result |
| --- | --- |
| Exact bytes at `0x0061e6f8` | `47 00 4d 00 00 00 00 00` (`L"GM"` plus alignment/padding) |
| Exact byte-pattern hits | one hit only, file offset `0x21d0f8`, VA `0x0061e6f8`, section `.rdata` |
| Absolute operand hits for `0x0061e6f8` | 20 hits, all in `.text`, all with preceding opcode byte `0x68` (`push imm32`) |
| Operand hits for `0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe` | none |
| Operand hits for `0x0061e700` | none |
| Operand hit for previous `CMAP` child at `0x0061e6f0` | one data pointer at `0x0066db48`, separate MapPane route |

Raw container bytes from `0x0061e6c0-0x0061e708`:

```text
4d 00 41 00 50 00 4e 00 41 00 4d 00 45 00 2e 00
45 00 50 00 46 00 00 00 4d 00 4d 00 41 00 50 00
42 00 55 00 54 00 2e 00 45 00 50 00 46 00 00 00
43 4d 41 50 00 00 00 00 47 00 4d 00 00 00 00 00
d4 b2 64 00 50 4d 51 00
```

This confirms the existing child boundary: `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, then this exact `GM` literal. There is no raw evidence for merging `GM` back into the mixed parent or splitting it further.

## Documentation Evidence

| Document | Relevant current evidence | Recheck conclusion |
| --- | --- | --- |
| `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | documents `aGm`, exact 8-byte UTF-16LE literal, 20 executable xrefs, `CANONICAL_OWNER:NONE`, emitters `0000L3,0000KU,0000M4` | current metadata is still correct |
| `by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md` | non-emitting mixed container with children for MapNamePane, MiniMapButtonPane, MapPane `CMAP`, and shared `GM` | parent should stay non-emitting; child split is complete enough |
| `by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md` | preceding ANSI `CMAP` child routes through MapPane pointer `0x0066db48` | confirms clean predecessor boundary and different ownership evidence |
| `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` | includes `0x00505430-0x005055ca` MapPane coordinate/object helper surface | supports emitter `0000L3` for the direct `0x00505505` use |
| `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md` | exact LivingObjectPane helper using `GM` suffix compare | supports emitter `0000KU`; helper is a source-use body even though final C++ remains below code-entry confidence |
| `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` | ObjectList helper family covering the six `0x00533170-0x00533d00` functions | supports emitter `0000M4` for the 18 ObjectList direct uses |
| `by-class/MapPane.md` / `by-file/MapPane.md` | MapPane class/file root, source module `NexusTK/map/MapPane.cpp` | valid emitter root, not sole canonical owner |
| `by-class/LivingObjectPane.md` / `by-file/LivingObjectPane.md` | LivingObjectPane class/file root, source module `NexusTK/map/LivingObjectPane.cpp` | valid emitter root, not sole canonical owner |
| `by-class/ObjectList.md` / `by-file/ObjectList.md` | ObjectList class/file root, source module `NexusTK/map/ObjectList.cpp` | valid emitter root, not sole canonical owner |

Per `by-structure.md`, a pooled/shared literal may validly remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while `EMITTER_UIDS` record the source roots that must emit source uses. Per `inference_research.md`, adjacency to nearby literals and string pooling are not source-file proof; the decision here uses direct xrefs and documented function ownership instead.

## Owner And Emitter Decision

### Keep `CANONICAL_OWNER:NONE`

No canonical owner clears the strict gate:

- MapPane has one direct use and owns nearby `CMAP`, but it does not own the LivingObjectPane suffix helper or ObjectList type lookup helpers.
- LivingObjectPane has one direct suffix-check use, but it does not own the MapPane or ObjectList code bodies.
- ObjectList has most references, but count dominance is not declaration ownership. Promoting ObjectList would overclaim the MapPane and LivingObjectPane direct uses.
- The mixed parent `0003C1` is intentionally non-emitting and contains multiple owners; it is an index/container, not a semantic source owner.
- No IDA function, vtable slot, global variable, pointer table, constructor, source path, or common helper proves a standalone declaration owner such as `GmNameRules`, `ObjectNameRules`, or a shared header/source file.

### Keep `EMITTER_UIDS:0000L3,0000KU,0000M4`

Each current emitter has direct source-use evidence:

| Emitter | Keep? | Evidence |
| --- | --- | --- |
| `0000L3` MapPane | yes | direct `push offset aGm` at `0x00505505` inside `sub_505430`, documented in the MapPane coordinate/object helper surface |
| `0000KU` LivingObjectPane | yes | direct `push offset aGm` at `0x00514ec5` inside `sub_514EA0`, documented as the LivingObjectPane GM name suffix check |
| `0000M4` ObjectList | yes | 18 direct `push offset aGm` refs across six ObjectList extended lookup helper functions |

No emitter should be removed: each current emitter has at least one direct code operand to the literal in a documented source root. No emitter should be added: IDA MCP and raw PE scans found no references outside the MapPane, LivingObjectPane, and ObjectList routes.

## Rejected Alternatives

| Alternative | Rejected because |
| --- | --- |
| Assign `CANONICAL_OWNER:0000M4` ObjectList | 18 of 20 refs are ObjectList, but MapPane and LivingObjectPane have direct independent source uses; count dominance is not declaration proof |
| Assign `CANONICAL_OWNER:0000KU` LivingObjectPane | semantic "GM name" intuition is weaker than the direct mixed xref distribution; ObjectList and MapPane do not call a shared LivingObjectPane helper |
| Assign `CANONICAL_OWNER:0000L3` MapPane | MapPane owns the preceding `CMAP` child and one `GM` use, but not the LivingObjectPane/ObjectList helper bodies |
| Route only through `LivingObjectPane.cpp` because the generated row displays that path | the explicit `EMITTER_UIDS` field already records all three routes; the display path is not stronger than direct xrefs |
| Create a new shared source owner | no common function, global declaration, source path, table, or unique owner evidence exists; this would invent a source unit from a pooled literal |
| Split `0x0061e6f8-0x0061e700` further | IDA and raw scans show no interior/tail references; it is one exact wide string plus padding |
| Merge with `0x0061e6c0-0x0061e700` parent | the parent contains separately owned `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and `GM` children; merging would obscure ownership/emitter routing |
| Reclassify as non-reconstructable | direct source-use xrefs prove the literal is source-relevant; reconstructable remains correct |

## Exact Supervisor Actions

No edits are required.

Current target metadata should remain:

```text
*** UID:0003IO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3,0000KU,0000M4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is needed. For comparison, the current generated no-owner row should remain:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

If the supervisor refreshes `by-memory/-coverage-report.md`, the corresponding narrative should remain semantically equivalent to:

```markdown
- [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very-strong : UTF-16LE `GM` pooled source literal; IDA/raw evidence confirms one exact literal at `0x0061e6f8`, 20 direct `push offset aGm` code references split across MapPane, LivingObjectPane, and ObjectList, no interior/tail/successor refs, and no common owner declaration. Keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000L3,0000KU,0000M4`.
```

## Validation And Commands

No by-* documentation or generated coverage files were edited. No dry-run validator was used. Because this is a report-only no-change recommendation, I did not run normal documentation validators or memory-range validation.

Evidence commands performed:

| Command/tool | Result |
| --- | --- |
| IDA MCP `idb_list` | active read-only `NexusTK.exe` session `b001_0003gy` found |
| IDA MCP `server_health` | status ok, auto-analysis ready, Hex-Rays ready |
| IDA MCP `lookup_funcs` | confirmed function owners for `sub_505430`, `sub_514EA0`, and six ObjectList helper functions |
| IDA MCP `xrefs_to` | confirmed 20 xrefs to `0x0061e6f8`, 0 xrefs to interior/tail/end addresses |
| Raw PE Python scan | confirmed one exact UTF-16LE `GM` byte pattern, 20 absolute `push imm32` operands to the literal, and no hidden interior/end operands |
| Documentation reads | checked target, parent/neighbor children, MapPane, LivingObjectPane, ObjectList, generated coverage, tracker, and prior executed reports |

## Open Risks And Blockers

No external blocker remains for this B-agent decision. The residual uncertainty is normal for pooled literals: the binary does not preserve original source declaration spelling or compilation-unit metadata. That uncertainty is exactly why `CANONICAL_OWNER:NONE` remains correct. It does not block the emitter routing because all three current emitters are backed by direct code operands and documented source roots.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B002/0003IO-SharedGmWideString-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
