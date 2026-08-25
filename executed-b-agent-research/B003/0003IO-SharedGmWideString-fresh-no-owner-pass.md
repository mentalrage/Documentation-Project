** TARGET-REPORT-UID:0003IO **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003IO **
# 0003IO SharedGmWideString Fresh No-Owner Pass

## Finalized recommendation

Keep `[UID:0003IO] by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:0000L3,0000KU,0000M4`
- `RECONSTRUCTABLE:TRUE`
- `COMPLETION:88`
- `CONFIDENCE:93`
- blank `RECONSTRUCTION_CPP`

This is a pooled/shared UTF-16 source literal, not a uniquely owned global object. Current IDA and PE evidence proves one physical `L"GM"` byte instance with 20 direct executable references split across three independently documented source-use routes: `MapPane` (`0000L3`), `LivingObjectPane` (`0000KU`), and `ObjectList` (`0000M4`). No current evidence proves a single semantic declaration owner, shared helper, or source file definition that should replace `CANONICAL_OWNER:NONE`.

No split, merge, reclassification, IDA-safe name repair, by-* documentation edit, or `by-memory/-coverage-report.md` edit is recommended. The current generated coverage rows are substantively correct.

## Target and scope

- Target UID: `0003IO`
- Target path: `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md`
- Address range: `0x0061e6f8-0x0061e700`
- Current generated source: `auto-generated/-ag-memory-coverage.md`
- Historical report reviewed as evidence only: `tools/leaser/Agents/Agent-B003/research/executed/0003IO-SharedGmWideString-current-no-owner-research.md`
- Active assignment row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` lists B003 for `0003IO` on 2026-06-14.

This pass rechecked the current by-memory page, current generated rows, related by-file/by-class/by-memory pages, live IDA MCP evidence, and raw PE bytes. Prior reports were treated as leads, not authority.

## Evidence standard applied

Current by-structure guidance says `CANONICAL_OWNER` is the direct semantic owner, while `EMITTER_UIDS` are output-routing file owners and may be multiple. It specifically allows pooled strings and shared constants to stay `CANONICAL_OWNER:NONE` when no unique owner is proven, while retaining multiple proven source-use emitters.

The same guidance rejects assigning ownership by adjacency, by highest xref count, or by a consumer that merely uses the literal. The inference guidance treats adjacency and consumer xrefs as evidence, not proof of a declaration owner; direct machine-code xrefs and raw bytes are higher-quality facts.

## Current metadata before and after

Before:

```text
UID:0003IO
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

After:

```text
UID:0003IO
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000L3,0000KU,0000M4
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Score impact: no change. Completion/confidence remain `88/93`. The average score for the active C++ gate is `(88 + 93) / 2 = 90.5`, but code entry is not recommended because this page represents a pooled literal use-site route, not a proven standalone source declaration.

## Current documentation evidence

The target page documents:

- literal bytes `47 00 4D 00 00 00 00 00`
- decoded value `L"GM"`
- parent container `[UID:0003C1] 0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md`
- one MapPane use, one LivingObjectPane use, and eighteen ObjectList uses
- current owner/emitter recommendation `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000L3,0000KU,0000M4`

Related pages are consistent:

- `by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md` is a non-emitting split index over `MAPNAME.EPF`, `MMAPBUT.EPF`, `CMAP`, and `GM`; it correctly leaves ownership to child pages.
- `by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md` routes the adjacent `CMAP` narrow literal through `MapPane` only. That adjacency does not transfer ownership of the following `GM` literal.
- `by-memory/0x0061e700-0x0061e704.GameServerConfigProtectedArrayRttiBoundary.md` documents the successor RTTI/vtable boundary, proving the `GM` range ends at `0x0061e700`.
- `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md` documents the LivingObjectPane suffix check that uses `L"GM"`.
- `by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` documents the ObjectList helper family that contains the eighteen ObjectList references.
- `by-file/MapPane.md`, `by-file/LivingObjectPane.md`, and `by-file/ObjectList.md` are current file roots with generated routes under `NexusTK/map/`.

Current generated file coverage maps the emitters as:

```text
0000L3 -> auto-generated/NexusTK/map/MapPane.cpp
0000KU -> auto-generated/NexusTK/map/LivingObjectPane.cpp
0000M4 -> auto-generated/NexusTK/map/ObjectList.cpp
```

The generated files currently exist but are empty; this is not a dead-end for emitter routing. It reflects that this memory item has no standalone `RECONSTRUCTION_CPP` and should surface through reconstructed consumer code when those functions are entered.

## Live IDA MCP facts

Live session:

```text
session: a001_goal2_class_batch
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x00400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Names near the target:

```text
0x0061e6b8 ??_7MiniMapButtonPane@@6B@_1
0x0061e6c8 aAmeEpf_0
0x0061e6dc aApbutEpf
0x0061e6f0 aCmap
0x0061e6f8 aGm
0x0061e704 ??_7?$ProtectedArray@UNationEntry@GameServerConfig@@@@6B@
0x0061e70c ??_7GameServerConfig@@6B@
0x0061e71c ??_7MapPane@@6B@
```

Raw IDA bytes for the parent region:

```text
0x0061e6c0:
4d 00 41 00 50 00 4e 00 41 00 4d 00 45 00 2e 00
45 00 50 00 46 00 00 00
4d 00 4d 00 41 00 50 00 42 00 55 00 54 00 2e 00
45 00 50 00 46 00 00 00
43 4d 41 50 00 00 00 00
47 00 4d 00 00 00 00 00
d4 b2 64 00 50 4d 51 00 34 b2 64 00 80 4d 51 00
```

Decoded subranges:

```text
0x0061e6c0-0x0061e6d8 UTF-16LE "MAPNAME.EPF"
0x0061e6d8-0x0061e6f0 UTF-16LE "MMAPBUT.EPF"
0x0061e6f0-0x0061e6f8 ASCII     "CMAP"
0x0061e6f8-0x0061e700 UTF-16LE "GM"
0x0061e700-...        vtable/RTTI bytes, not part of the string
```

`get_string` returns `GM` at `0x0061e6f8`, `CMAP` at `0x0061e6f0`, and no valid string at `0x0061e700`. IDA's string-cache query did not list the very short/wide string, so the byte and xref evidence is the authority here.

Direct xrefs to `0x0061e6f8`:

```text
0x00505505 sub_505430
0x00514ec5 sub_514EA0
0x0053321a sub_533170
0x005332b5 sub_533170
0x0053334c sub_533170
0x00533445 sub_5333B0
0x00533515 sub_5333B0
0x005335b7 sub_5333B0
0x005336a5 sub_533600
0x00533738 sub_533600
0x005337d7 sub_533600
0x005338dc sub_533850
0x0053397a sub_533850
0x00533a1b sub_533850
0x00533b3a sub_533A90
0x00533bfa sub_533A90
0x00533ca5 sub_533A90
0x00533d9a sub_533D00
0x00533e6a sub_533D00
0x00533f19 sub_533D00
```

Interior and successor xrefs:

```text
0x0061e6fa: 0 direct xrefs
0x0061e6fc: 0 direct xrefs
0x0061e6fe: 0 direct xrefs
0x0061e700: 0 direct xrefs
0x0061e704: 5 direct xrefs to the successor ProtectedArray/GameServerConfig vtable region
```

`trace_data_flow` for `0x0061e6f8` reports the node as `text "UTF-16LE", 'GM',0`, named `aGm`, and all 20 incoming code uses are `push offset aGm` instructions.

`analyze_component` over the eight referencing functions reports one shared global access:

```text
0x0061e6f8 aGm accessed_by
  sub_505430, sub_514EA0, sub_533170, sub_5333B0,
  sub_533600, sub_533850, sub_533A90, sub_533D00
```

It reports no call-graph edge that unifies those functions behind a shared GM helper or declaration owner.

## PE/raw evidence

Raw PE inspected:

```text
file: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
sha256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
image_base: 0x00400000
.rdata VA: 0x0060d000 raw: 0x0020ba00
target VA: 0x0061e6f8
target raw: 0x0021d0f8
```

Raw scan results:

```text
exact bytes 47 00 4d 00 00 00 00 00: count 1 at VA 0x0061e6f8
VA32 0x0061e6f8: count 20
PUSH 0x0061e6f8 immediate pattern: count 20
RVA32 0x0021e6f8: count 0
VA32 0x0061e6fa: count 0
VA32 0x0061e6fc: count 0
VA32 0x0061e6fe: count 0
VA32 0x0061e700: count 0
VA32 0x0061e704: count 5
```

The 20 raw `push` instruction starts are:

```text
0x00505505
0x00514ec5
0x0053321a
0x005332b5
0x0053334c
0x00533445
0x00533515
0x005335b7
0x005336a5
0x00533738
0x005337d7
0x005338dc
0x0053397a
0x00533a1b
0x00533b3a
0x00533bfa
0x00533ca5
0x00533d9a
0x00533e6a
0x00533f19
```

This raw evidence independently matches the live IDA xref inventory and proves there are no hidden raw references to the interior or end of the `GM` range.

## Function and source-use inventory

| Route | Function(s) | Evidence | Emitter |
| --- | --- | --- | --- |
| MapPane use | `sub_505430` at `0x00505430`, xref at `0x00505505` | Hex-Rays compares a map-related wide field to `L"GM"` with `_wcsicmp`; surrounding calls include MapPane/map coordinate helpers documented under `MapPane`. | `0000L3` |
| LivingObjectPane use | `sub_514EA0` at `0x00514ea0`, xref at `0x00514ec5` | Documented `LivingObjectPaneGmNameSuffixCheck`; scans a name buffer and compares its final two wide chars to `L"GM"` using `_wcsicmp`. | `0000KU` |
| ObjectList uses | `sub_533170`, `sub_5333B0`, `sub_533600`, `sub_533850`, `sub_533A90`, `sub_533D00` | Documented `ObjectListExtendedTypeLookupHelpers`; six ObjectList helper functions contain eighteen direct `L"GM"` references while scanning object records. | `0000M4` |

The xref distribution is 1 MapPane, 1 LivingObjectPane, and 18 ObjectList. That distribution proves source-use routes, not a canonical declaration owner.

## Representative decompilation evidence

`sub_505430` contains a MapPane-side check:

```c
_wcsicmp((const wchar_t *)(...map/name field...), L"GM")
```

`sub_514EA0` walks a LivingObjectPane name buffer and compares the two-character suffix:

```c
return _wcsicmp((const wchar_t *)&this[... + 294], L"GM") == 0;
```

The ObjectList helper family repeatedly calls `sub_535CE0`, scans object/list state, checks object fields, and compares wide fields to `L"GM"` via `_wcsicmp`.

These are independent consumer-side uses of the same pooled literal. None decompiles as a helper that owns or exports a shared GM constant.

## Alternatives rejected

### Canonical owner `0000M4` / ObjectList

Rejected. ObjectList accounts for 18 of 20 xrefs, but by-structure rules do not permit assigning ownership by highest reference count when other material consumers exist. The two non-ObjectList uses are not incidental data references; they are direct executable `push offset aGm` instructions in independently documented MapPane and LivingObjectPane functions.

### Canonical owner `0000KU` / LivingObjectPane

Rejected. LivingObjectPane has a clearly documented suffix-check function, but it has only one direct use and no evidence of a declaration that supplies the other MapPane/ObjectList uses.

### Canonical owner `0000L3` / MapPane

Rejected. `MapPane` owns the adjacent `CMAP` narrow literal through a distinct pointer-anchor route, but adjacency to `CMAP` and the parent resource-string cluster does not prove ownership of `GM`. The MapPane use is one direct consumer use among three source routes.

### Canonical owner through parent `0003C1`

Rejected. `0003C1` is a non-emitting split index over heterogeneous literals. Its children already carry distinct owner/emitter decisions. Promoting the parent to a source owner would erase the child-level evidence and incorrectly couple unrelated resource strings, a MapPane-only `CMAP` signature, and the shared `GM` literal.

### Standalone shared global declaration

Rejected. The only proof is a compiler/linker-pooled literal in `.rdata`, referenced by immediate pushes. No source debug path, map record, unique global symbol, helper function, or non-consumer reference proves a source-level shared declaration such as `static const wchar_t GM[]`.

### Split the 8-byte range

Rejected. The range is exactly the UTF-16LE `GM` literal plus NUL padding/alignment. Interior addresses have no xrefs, and the successor vtable region starts after the range. Splitting would create non-semantic fragments.

### Merge with neighboring ranges

Rejected. The predecessor `CMAP` and successor vtable/RTTI boundary have different semantics and different xref/owner evidence. The parent split index already models physical adjacency without forcing a semantic merge.

### Reclassify as non-reconstructable

Rejected. The literal is source-use reconstructable because it is a source string literal in consumer code. The fact that there is no standalone C++ declaration to enter here does not make the memory range non-reconstructable; it means reconstruction should happen through consumer functions routed by `EMITTER_UIDS`.

## Owner/emitter conclusion

The correct current model is:

```text
CANONICAL_OWNER:NONE
EMITTER_UIDS:0000L3,0000KU,0000M4
```

`NONE` is defensible because no single declaration or semantic owner is proven. The emitters are required because all three source-use routes are proven by direct executable xrefs and current file-root coverage:

- `0000L3` for the MapPane consumer
- `0000KU` for the LivingObjectPane consumer
- `0000M4` for the ObjectList consumer family

No additional emitter was found. No existing emitter should be removed.

## C++ entry eligibility

Minimum gate check:

- `RECONSTRUCTABLE:TRUE`: yes
- confirmed nonblank `EMITTER_UIDS`: yes, `0000L3,0000KU,0000M4`
- emitter routes surface to valid generated source files: yes, `MapPane.cpp`, `LivingObjectPane.cpp`, and `ObjectList.cpp`
- `(COMPLETION + CONFIDENCE) / 2 > 85`: yes, `90.5`

However, code entry is not recommended for this memory page. The source representation should be local `L"GM"` literals inside the reconstructed consumer functions, not a standalone declaration emitted from this by-memory page. Adding a global C++ constant here would overstate the evidence and could create an artificial source artifact.

## Exact required edits

No by-* documentation edits are required.

No direct edit to `by-memory/-coverage-report.md` is required. The current coverage-report text should remain as-is:

```markdown
            - [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) 0x0061e6f8-0x0061e700 | string-data | SharedGmWideString : reconstructable : 88% : very strong : UTF-16LE `GM` pooled source literal with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000L3,0000KU,0000M4`; ownership reviews confirm 20 direct code xrefs across MapPane, LivingObjectPane, and ObjectList consumers, with no single semantic declaration owner.
```

No replacement row is needed for `auto-generated/-ag-memory-coverage.md`; it is generated and already matches the recommended owner/emitter state:

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `NONE` | `0000L3`,`0000KU`,`0000M4` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` |  |
```

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0000M4][ObjectList](by-file/ObjectList.md) |  | `auto-generated/NexusTK/map/LivingObjectPane.cpp` |  |
```

```markdown
| [UID:0003IO][0x0061e6f8-0x0061e700.SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) | no-owner | `by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md` | `0000L3`,`0000KU`,`0000M4` | `auto-generated/NexusTK/map/LivingObjectPane.cpp` |  |
```

## Validation and lease state

- Changed files: `tools/leaser/Agents/Agent-B003/research/0003IO-SharedGmWideString-fresh-no-owner-pass.md`
- by-* files changed: none
- `by-memory/-coverage-report.md` changed: no
- Validator run: not required; no by-* documentation or generated/shared coverage files were edited.
- Leases used: none. The only edited file is inside Agent-B003's own research folder, where the goal instructions do not require a lease.
- Dry runs: none.

## Confidence

Recommendation confidence: high.

The literal bytes, raw PE address references, live IDA xrefs, current related documentation, and by-structure ownership rules all converge on the same conclusion: this is a reconstructable pooled literal with three proven emitter routes and no defensible single canonical owner.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003IO","source_path":"executed-b-agent-research/B003/0003IO-SharedGmWideString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
