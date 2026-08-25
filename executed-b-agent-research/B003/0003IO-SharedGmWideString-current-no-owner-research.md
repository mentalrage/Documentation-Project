** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# 0003IO SharedGmWideString Current No-Owner Research

## Final Recommendation

Keep [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) unchanged:

- `COMPLETION:88`
- `CONFIDENCE:93`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L3,0000KU,0000M4`
- blank `RECONSTRUCTION_CPP`

This is a valid shared/pooled source literal case under the current owner/emitter model. The live IDA and raw PE evidence prove one physical UTF-16LE `GM` literal at `0x0061e6f8`, with 20 executable source-use xrefs split across MapPane, LivingObjectPane, and ObjectList consumers. No single source file, class, helper declaration, pointer slot, or parent read-only-data index owns the full xref set.

No split, merge, reclassification, IDA-safe name repair, target edit, emitter repair, or shared coverage-report edit is recommended.

## Target And Scope

Assigned target:

- UID: `0003IO`
- Path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- Range: `0x0061e6f8-0x0061e700`
- Current generated state: no-owner with multiple emitters, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000KU,0000M4`
- Research folder output: this report only.

Historical reports and existing docs were treated as leads. The conclusion below is based on current target docs, current generated coverage rows, current by-structure/inference rules, current emitter/consumer docs, live IDA MCP evidence, and a raw PE scan.

## Evidence Standards Used

- Current `goal.md` and `Supervisor.md` allow shared literal/data items to remain `CANONICAL_OWNER:NONE` when no single canonical declaration/source owner is defensible, provided all proven source-use output routes are represented in `EMITTER_UIDS`.
- The active C++ code-entry gate is minimum eligibility only: `RECONSTRUCTABLE:TRUE`, nonblank confirmed emitters that route to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`. It does not justify placeholder or poorly placed source blocks.
- The related parent/string index pages were checked only as supporting evidence. The assignment did not authorize by-* edits, and none are needed.

## Current Documentation State

The target page already records:

- exact range `0x0061e6f8-0x0061e700`;
- literal `GM`, represented in IDA as `aGm`;
- `RECONSTRUCTABLE:TRUE`;
- `CANONICAL_OWNER:NONE`;
- `EMITTER_UIDS:0000L3,0000KU,0000M4`;
- blank C++;
- score `88/93`.

The direct mixed parent [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) is correctly non-emitting and split into exact literal children:

- `0003IL`: `MAPNAME.EPF` -> MapNamePane
- `0003IM`: `MMAPBUT.EPF` -> MiniMapButtonPane
- `0003IN`: ANSI `CMAP` -> MapPane through pointer-slot support
- `0003IO`: shared UTF-16 `GM` -> no canonical owner, three emitters

The containing read-only-data page [UID:00025R][0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData](../../../../../by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md) remains a non-emitting mixed index over vtables, strings, and the following RTTI boundary. That parent cannot own this exact shared literal.

## Current Generated Coverage Rows

Current `auto-generated/-ag-memory-coverage.md` reports the target as:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

and lists the emitter files as:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0000M4][ObjectList](by-file/ObjectList.md) |  | `auto-generated/NexusTK/map/LivingObjectPane.cpp` |  |
```

No replacement is required.

## Current Emitter Docs

The three current emitter UIDs are all valid by-file output roots:

| Emitter UID | File doc | Current score | Route evidence |
| --- | --- | ---: | --- |
| `0000L3` | [MapPane](../../../../../by-file/MapPane.md) | `89/85` | `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; MapPane owns the movement/collision consumer at `0x00505430`. |
| `0000KU` | [LivingObjectPane](../../../../../by-file/LivingObjectPane.md) | `88/85` | `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; LivingObjectPane owns the suffix helper at `0x00514ea0`. |
| `0000M4` | [ObjectList](../../../../../by-file/ObjectList.md) | `85/88` | `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; ObjectList owns the extended type lookup helpers at `0x00533170` and siblings. |

These emitters are source-use routes, not a claim that the `GM` bytes are a standalone global declaration.

## Live IDA MCP Evidence

Live MCP session:

- session: `b001_0002bd`
- input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- module: `NexusTK.exe`
- imagebase: `0x400000`
- Hex-Rays and strings cache: ready.

Byte/name/string checks:

- `get_bytes(0x0061e6f8, 8)` returned `47 00 4d 00 00 00 00 00`.
- `get_string(0x0061e6f8)` returned `GM`.
- `entity_query(names, 0x0061e6c0-0x0061e710)` found `aCmap` at `0x0061e6f0`, `aGm` at `0x0061e6f8`, and the successor `ProtectedArray<GameServerConfig::NationEntry>` vtable name at `0x0061e704`.
- `entity_query(strings, 0x0061e6c0-0x0061e710)` did not independently list the short UTF-16 strings, so IDA listing/data-flow plus bytes are the authoritative proof.
- `make_signature_for_range(0x0061e6f8-0x0061e700, wildcard_operands=false)` returned unique signature `47 00 4D 00 00 00 00 00`.

`xrefs_to` current results:

| Consumer group | Xref addresses | Function(s) |
| --- | --- | --- |
| MapPane | `0x00505505` | `sub_505430`, size `0x19a` |
| LivingObjectPane | `0x00514ec5` | `sub_514EA0`, size `0x3d` |
| ObjectList | `0x0053321a`, `0x005332b5`, `0x0053334c` | `sub_533170`, size `0x240` |
| ObjectList | `0x00533445`, `0x00533515`, `0x005335b7` | `sub_5333B0`, size `0x24e` |
| ObjectList | `0x005336a5`, `0x00533738`, `0x005337d7` | `sub_533600`, size `0x243` |
| ObjectList | `0x005338dc`, `0x0053397a`, `0x00533a1b` | `sub_533850`, size `0x23d` |
| ObjectList | `0x00533b3a`, `0x00533bfa`, `0x00533ca5` | `sub_533A90`, size `0x267` |
| ObjectList | `0x00533d9a`, `0x00533e6a`, `0x00533f19` | `sub_533D00`, size `0x26d` |

Negative xref evidence:

- `xrefs_to(0x0061e6fa)`: none.
- `xrefs_to(0x0061e6fc)`: none.
- `xrefs_to(0x0061e6fe)`: none.
- `xrefs_to(0x0061e700)`: none.
- Successor `0x0061e704` has separate vtable/RTTI xrefs and is not part of this string.

Data-flow evidence:

- `trace_data_flow(0x0061e6f8, backward, max_depth=1)` reported `text "UTF-16LE", 'GM',0` at `aGm` and the same 20 code nodes, each as `push offset aGm; "GM"`.
- `analyze_component` over `0x00505430`, `0x00514ea0`, `0x00533170`, `0x005333b0`, `0x00533600`, `0x00533850`, `0x00533a90`, and `0x00533d00` reported shared global `0x61e6f8 aGm` accessed by all eight functions and no internal call-graph owner that unifies them.

Representative decompiler lines:

- MapPane `sub_505430`: compares a computed wide-name suffix with `L"GM"` through `_wcsicmp`.
- LivingObjectPane `sub_514EA0`: returns `_wcsicmp(..., L"GM") == 0`.
- ObjectList `sub_533170` and `sub_5333B0`: each contains repeated `_wcsicmp(..., L"GM")` suffix tests on candidate object names.

## Raw PE Evidence

Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- `.rdata` starts at VA `0x0060d000`, raw pointer `0x20ba00`.
- VA `0x0061e6f8` maps to raw offset `0x21d0f8`.
- Raw bytes at the target are exactly `47 00 4d 00 00 00 00 00`.
- Exact literal pattern `47 00 4d 00 00 00 00 00`: 1 hit, at raw `0x21d0f8`.
- Absolute VA dword `f8 e6 61 00`: 20 hits.
- `push 0x0061e6f8` pattern `68 f8 e6 61 00`: 20 hits.
- Interior/end pointer patterns `0x0061e6fa`, `0x0061e6fc`, `0x0061e6fe`, and `0x0061e700`: 0 hits.
- RVA-form `0x0021e6f8`: 0 hits.
- Successor vtable pointer `0x0061e704`: 5 hits, confirming the next address belongs to a separate RTTI/vtable island.

This raw evidence matches IDA: one pooled literal, direct push-immediate source uses only, no pointer slot or hidden table owner, no interior split, and a clean successor boundary.

## Function And Child Inventory

Relevant documented consumers:

- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](../../../../../by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) contains the MapPane movement/collision helper `0x00505430-0x005055ca`, which references `aGm` once.
- [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](../../../../../by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md) owns the LivingObjectPane suffix predicate and references `aGm` once.
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](../../../../../by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) owns the ObjectList helper family containing six modeled consumers with 18 total `aGm` refs.

Parent/child structure:

- The broad parent [UID:00025R][MapNameMiniMapButtonReadOnlyData](../../../../../by-memory/0x0061e5b4-0x0061e704.MapNameMiniMapButtonReadOnlyData.md) is a mixed read-only-data index and correctly remains `RECONSTRUCTABLE:FALSE`.
- The exact string index [UID:0003C1][MapNameMiniMapResourceStrings](../../../../../by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) is also a mixed non-emitting split index.
- `0003IO` is already the exact minimum child for the `GM` bytes. Further splitting would create unreferenced interior/tail fragments, which both IDA and PE scans reject.

## Ownership Analysis

Rejected canonical owners:

- `MapPane` / `0000L3`: owns the `0x00505430` consumer and the neighboring `CMAP` literal route, but it accounts for only one of 20 `GM` xrefs. It does not own the LivingObjectPane method or ObjectList helper bodies.
- `LivingObjectPane` / `0000KU`: owns the clean suffix-check method and one direct `GM` use, but it does not own the MapPane collision helper or ObjectList lookup helpers.
- `ObjectList` / `0000M4`: owns 18 of 20 `GM` xrefs, but that is consumer dominance rather than declaration ownership. Assigning ObjectList as canonical would incorrectly absorb MapPane and LivingObjectPane source-use literals.
- `MapNameMiniMapResourceStrings` / `0003C1`: this is a non-emitting physical string index, not a source module or source declaration owner.
- A standalone global/string table owner: no pointer slot, symbol table, table index, named accessor, or source-level declaration route was found. All current refs are direct `push offset aGm` use sites.

Accepted routing:

- `CANONICAL_OWNER:NONE` because the physical literal is compiler/linker-pooled across independent source-use contexts.
- `EMITTER_UIDS:0000L3,0000KU,0000M4` because those are the proven by-file roots whose source reconstruction may need the local `L"GM"` literal use.

## Split, Merge, Reclassify, And Repair Checks

- Split: rejected. The current child is exactly eight bytes: `G\0M\0\0\0\0\0`. IDA and PE show no references to interior or end addresses.
- Merge: rejected. The parent ranges mix unrelated owners (`MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, `GM`, vtables, and RTTI). Merging would hide ownership boundaries.
- Reclassify to non-reconstructable: rejected. The literal is source-authored data used by reconstructable functions and has valid emitter routes.
- Canonical owner change: rejected for the reasons above.
- Emitter change: rejected. Current emitters exactly match the three source-use file roots proven by xrefs.
- IDA-safe name repair: not needed. IDA already names the literal `aGm`; this is adequate evidence and does not require an IDB edit.
- Target text repair: not needed. Current target text is scanner-visible and already records the current owner/emitter model.

## C++ Entry Gate

Numeric/minimum gate:

- `RECONSTRUCTABLE:TRUE`: yes.
- Confirmed nonblank emitters: yes, `0000L3,0000KU,0000M4`.
- Combined score: `(88 + 93) / 2 = 90.5`, which is greater than `85`.

Final source-placement result: do not enter or recommend standalone `RECONSTRUCTION_CPP` for this page. The minimum gate allows consideration, but this exact item is a pooled literal whose correct final source representation is local `L"GM"` use inside reconstructed consumer functions, not a separate global declaration or emitted string object from the data page. Keep the C++ block blank.

## Exact Required Edits

No by-* documentation edits are required.

No `by-memory/-coverage-report.md` edit is required. If the supervisor wants an explicit retained row, keep the existing text:

```markdown
            - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

No `auto-generated/-ag-memory-coverage.md` replacement is required. The current row is the desired state:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

## Scores, Validation, And Lease State

- Target score before: `88/93`.
- Target score after: `88/93`.
- Changed files: this report only.
- by-* files changed: none.
- Validation: not run because no by-* documentation files or shared reports were edited.
- Leases: no leases used or required; this report is in the Agent-B003 research folder.
- Supervisor action needed: none, other than marking this B003 recheck complete if accepted.

## Confidence

Recommendation confidence: high. Current docs, generated coverage, live IDA xrefs/data flow, decompiler spot checks, and raw PE scanning all agree: `0003IO` is an exact shared UTF-16 `GM` literal, no canonical declaration owner is proven, the three current emitters are exactly the proven source-use routes, and the item is no-owner but not non-emitting.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B003/0003IO-SharedGmWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
