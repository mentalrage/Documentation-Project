** TARGET-REPORT-UID:0002IZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003-goal2-maptileimagelib-source-quality-0002IZ-0002J1-20260617

Agent: Agent-B003
Assignment: B003-goal2-maptileimagelib-source-quality-0002IZ-0002J1-20260617
Report path: `tools/leaser/Agents/Agent-B003/research/0002IZ-0002J1-maptileimagelib-source-quality.md`

This is a report-only result. I did not edit by-* docs, generated reports, generated source, the IDA database, or `by-memory/-coverage-report.md`. No split exception was exercised because the two primary targets are already exact child pages and the local aggregate [UID:000177] is already a non-emitting split/index page.

## Executive Recommendation

[UID:0002IZ] `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md`

- Recommendation: raise from `82/88` to `87/91`.
- Keep `RECONSTRUCTABLE: true`.
- Keep owner/emitter `[UID:00007T] MapTileImageLib`; source route remains `[UID:0000L5] NexusTK/render/MapTileImageLib.cpp`.
- Remove the stale 2026-06-06 MCP-timeout caveat as a completion/confidence limiter. Fresh 2026-06-17 IDA MCP evidence validated the exact function, xrefs, callees, decompile shape, field writes, and source placement.
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank for this pass. The target is now source-shaped above the active 85/85 gate, but the formal block would prematurely force unresolved shared type/header names and DATFile/allocator wrappers into one function page.

[UID:0002J1] `by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md`

- Recommendation: raise from `82/88` to `87/91`.
- Keep `RECONSTRUCTABLE: true`.
- Keep owner/emitter `[UID:0000L5] MapTileImageLib file`, not the class and not the shared ImageFrameTable module.
- Source-facing signature recommendation: `static ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName)`.
- Keep the formal `RECONSTRUCTION_CPP CODE` block blank for this pass for the same shared declaration and wrapper reasons described above.

[UID:000177] `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md`

- Keep as a non-emitting local split/index page.
- Correct the coverage row range/status from the stale broad `0x004d1860-0x004e6748 : reconstructable : 82%` row to the actual local cluster `0x004d1860-0x004d1f30 : not_reconstructable : 83%`.
- Do not emit aggregate C++ from [UID:000177]; the exact child pages carry source ownership.

## Existing Report Search

Searched existing executed B reports before finalizing:

_Executable command block removed from the research report; preserved in [0002IZ-0002J1-maptileimagelib-source-quality-removed.md](0002IZ-0002J1-maptileimagelib-source-quality-removed.md)._

Result: no executed B report directly covers [UID:0002IZ] or [UID:0002J1]. Older B001 reports mention nearby fatal resource cleanup and vtable/boundary issues as supporting leads only; they are not authority for this assignment.

## Evidence Checked

Primary docs and support docs read:

- [UID:0002IZ] constructor target.
- [UID:0002J1] metadata-loader target.
- [UID:000177] local method cluster.
- [UID:000178] ordinary destructor.
- [UID:0002J0] `DrawTile`.
- [UID:0002J2] scalar deleting destructor.
- [UID:00007T] MapTileImageLib class.
- [UID:0000L5] MapTileImageLib file.
- [UID:0001V2] MapTileImageLib layout.
- [UID:0001V3] MapTileRecord.
- [UID:0001Y3] MapTileImageLib vtable.
- [UID:0000RG] `g_pMapTileImageLib`.
- [UID:0000UN] EPF/archive metadata table.
- [UID:0000UY] generic `LoadImageFrameTable`.
- [UID:0000UX] `LoadFrameDrawRecord`.
- [UID:0000K1] ImageFrameTable file.
- `by-project-structure/proposed-source-tree.md`.

Fresh IDA MCP validation used the active session for `NexusTK.exe`.

Relevant MCP facts:

- `lookup_funcs`:
  - `0x004d1860` is `sub_4D1860`, size `0x13e`; `0x004d199e` is not a function.
  - `0x004d19a0` is `sub_4D19A0`, size `0x7c`.
  - `0x004d1a20` is `sub_4D1A20`, size `0x152`.
  - `0x004d1b80` is `sub_4D1B80`, size `0x3a2`; `0x004d1f22` is not a function.
  - `0x004d1f30` is the next function, `sub_4D1F30`.
  - `0x004e66a0` is `sub_4E66A0`, size `0xa8`; `0x004e6748` is not a function.
- `xrefs_to`:
  - Constructor `0x004d1860`: one startup/allocation xref at `0x004f6055` in `sub_4F5FB0`.
  - Loader `0x004d1b80`: one code xref at `0x004d18d1` from the constructor.
  - DrawTile `0x004d1a20`: four code xrefs, including the raw MapPane call at `0x0050c3d7`.
  - Ordinary destructor `0x004d19a0`: no direct code xrefs.
  - Scalar deleting destructor `0x004e66a0`: vtable-only xref from `0x0061b664`.
  - `g_pMapTileImageLib` `0x0067a75c`: constructor, destructor, scalar destructor, singleton-clear, startup/shutdown, MapPane, and PhotoPane xrefs.
- Constructor callees: `LObject` constructor, DATFile constructor/open/read/close/destructor helpers, `LoadTileEpfMetadata`, allocation, fatal cleanup, `MessageBoxW`, and `_loaddll`.
- Loader callees: allocator/context helpers, DATFile constructor/open/read/seek/data-pointer/close/destructor helpers, `swprintf` helper, `HasDATEntry`, allocation/free helpers, and rectangle initializer `0x004b7c50`.
- DrawTile callees: palette/filter helper, `EPFTileContext` initializer, DATFile helpers, `LoadFrameDrawRecord`, palette lookup, tile blit callback, fallback fill callback, and color helper.

## Constructor Source Shape

The constructor is source-shaped and no longer blocked by the old MCP timeout note.

Best source shape:

```cpp
MapTileImageLib::MapTileImageLib();
```

Defensible body summary:

- Calls the `LObject` base constructor.
- Stores `this` into `g_pMapTileImageLib`.
- Installs the MapTileImageLib vtable at `0x0061b664`.
- Initializes `tileFrameTable` from `LoadTileEpfMetadata(L"TILE.EPF")`.
- Opens `TILE.TBL` through DATFile.
- Reads and validates the tile count against the first word of the merged metadata table.
- Allocates a 4-byte `MapTileRecord` array for the count.
- For each 16-bit `TILE.TBL` word:
  - low 15 bits become `MapTileRecord::paletteIndex`;
  - high bit becomes `MapTileRecord::allowPaletteFilter`;
  - byte `+0x03` remains padding/reserved.
- Closes/destructs the temporary DATFile.

The `this == -4` style guard in the decompile is a compiler/decompiler artifact around storing `this` through a field-relative temporary. It should not be copied into source documentation or final C++; the source-level effect is the singleton write.

Field recommendations:

```cpp
ArchiveMetadataTable *tileFrameTable;  // this + 0x04
MapTileRecord *tileRecords;            // this + 0x08
```

I prefer `tileFrameTable` over generic `tileMetadata` because the field is passed to `LoadFrameDrawRecord` as the frame-record table for tile frames. `tileMetadata` is acceptable as prose, but docs should use one canonical source-facing field name to avoid reintroducing uncertainty.

Rejected alternatives:

- `tileTable`: too ambiguous; the constructor separately opens `TILE.TBL`.
- `tileEpfMetadata`: overfits the storage source and hides that `DrawTile` consumes it as a frame-record table.
- `frameIndex` for the low 15-bit `TILE.TBL` field: rejected because DrawTile passes the tile id itself to `LoadFrameDrawRecord`; the low 15-bit value is later passed to the palette lookup helper.
- `collision`, `blocking`, `walkable`, or terrain gameplay flag for the high bit: rejected because no map/gameplay code consumes it here; DrawTile only uses it as a palette-filter gate.

Score impact: this resolves the previous source-quality blockers around stale MCP evidence, field roles, tile-record flag semantics, and constructor caller/source placement. It justifies `87/91`, not a lower sub-85 score.

## Metadata Loader Source Shape

The loader is a file-local MapTileImageLib helper, not a shared ImageFrameTable helper and not a class method.

Best source-facing signature:

```cpp
static ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName);
```

Evidence for the one-argument signature:

- The constructor decompile calls `sub_4D1B80(L"TILE.EPF")`.
- IDA decompiles the helper as a `__stdcall` function with one integer/pointer argument.
- The body does not use the parameter; it formats fixed `TILE%d.EPF` shard names.

The parameter should be retained in source documentation as `unusedArchiveName` unless later instruction-level cleanup proves the caller/callee convention can be safely simplified. A no-argument recovered-source signature is plausible as a cleanup in generated decompilation, but it is not the safest documentation signature for the binary-backed target.

Defensible body summary:

- Scans `TILE%d.EPF` for `i < 100`.
- Stops at the first missing shard based on `HasDATEntry`.
- Opens each shard through temporary DATFile objects.
- Reads an 8-byte shard header into an in-memory 12-byte header shape.
- Accumulates total record count and maxima into one merged `ArchiveMetadataTable`.
- Allocates `24 * (recordCount + 1)` bytes for packed archive records.
- For each raw EPF record, reads `top`, `left`, `bottom`, `right`, `payloadStart`, and `payloadEnd`.
- Calls the rectangle initializer with source-order-corrected `left`, `top`, `right`, `bottom`.
- Rebases payload offsets through the DATFile data pointer.
- Appends a zero/sentinel record.
- Closes/destructs temporary DATFile objects and frees temporary arrays.

Type recommendation:

```cpp
struct ArchiveMetadataTable {
    uint16_t entryCount;
    uint16_t maxMetric0;
    uint16_t maxMetric1;
    uint16_t reserved;
    PackedArchiveRecord *records;
};
```

This shared table type belongs with the ImageFrameTable/archive metadata support docs, but this specific tile shard builder belongs in `NexusTK/render/MapTileImageLib.cpp`.

Rejected alternatives:

- Move `LoadTileEpfMetadata` to ImageFrameTable: rejected. The generic `LoadImageFrameTable` at `0x004d0f50` has 25 xrefs across human/riding/static/UI/effect families. In contrast, `LoadTileEpfMetadata` has one caller and hardcodes `TILE%d.EPF` shard names. The shared table type is ImageFrameTable-owned; the asset-specific builder is not.
- Move to DATFile/DAT archive code: rejected. DATFile owns archive IO primitives, not tile resource policy, shard naming, or merged frame metadata semantics.
- Make it a `MapTileImageLib` member method: rejected. IDA shows `__stdcall`/non-thiscall behavior and no `this` use. The constructor is the only caller, but call locality is not evidence of a member function.
- Treat the first argument as an active filename: rejected. The only observed argument is `L"TILE.EPF"`, but the body scans fixed `TILE%d.EPF`; no read from the argument appears in decompile/callee evidence.

Score impact: this resolves the previous source-placement and signature uncertainty enough for `87/91`. The remaining unknown is original spelling/style, not behavior, owner, range, or source placement.

## Tile Record Semantics

Recommended canonical doc type:

```cpp
struct MapTileRecord {
    uint16_t paletteIndex;       // +0x00, low 15 bits of TILE.TBL word
    uint8_t allowPaletteFilter;  // +0x02, high bit of TILE.TBL word
    uint8_t reserved;            // +0x03
};
```

Evidence:

- Constructor masks each `TILE.TBL` word with `0x7fff` and writes the result at record offset `+0x00`.
- Constructor writes `word < 0` into byte offset `+0x02`.
- DrawTile checks the byte at `+0x02` only while palette filtering is active.
- DrawTile passes the low 15-bit field to the palette lookup helper with palette slot `0`.
- DrawTile uses the requested tile id, not this low 15-bit field, for `LoadFrameDrawRecord`.

This should replace provisional wording such as `paletteOrFrameIndex` if the support doc owner wants one canonical name. If the support doc keeps `paletteOrFrameIndex`, it should explicitly state that the best current source-facing role is palette lookup, not frame selection.

## Aggregate And Split Policy

[UID:000177] should remain a non-emitting local method cluster, not an aggregate C++ owner.

Reasons:

- Its current by-memory page range is `0x004d1860-0x004d1f30`, which contains the constructor, ordinary destructor, DrawTile, and the metadata helper before ObjectStatusBlob parsers begin.
- The coverage report row is stale and still says `0x004d1860-0x004e6748` and `reconstructable`. That broad span incorrectly swallows the later scalar deleting destructor range in the row text and makes the local index look source-emitting.
- Exact child pages already exist for the functions in scope:
  - [UID:0002IZ] constructor.
  - [UID:000178] ordinary destructor.
  - [UID:0002J0] DrawTile.
  - [UID:0002J1] metadata helper.
  - [UID:0002J2] scalar deleting destructor.
- The ordinary destructor and singleton-clear omission in generated/recovered output is a source-completeness issue for the class/file docs, not a reason to emit from the aggregate page.

No additional by-structure split is required for this assignment.

## Generated Output And Omission Policy

The active auto-generated route `auto-generated/NexusTK/render/MapTileImageLib.cpp` currently exists as an empty file because the formal C++ blocks for these functions are blank. That is not an owner/emitter failure; it reflects the current documentation gate.

Known recovered/generated-source caveat:

- `simroot_v2/class_MapTileImageLib.cpp` is useful as a lead but is not authoritative.
- It contains source-shaped constructor/DrawTile/scalar-deleting-destructor material.
- It omits the ordinary destructor [UID:000178] and singleton-clear helper [UID:000180].

Support docs should state that final MapTileImageLib source migration must include constructor, ordinary destructor, DrawTile, metadata helper, singleton clear, and compiler-owned scalar deleting wrapper policy. Do not let a recovered class file that omits the ordinary destructor drive ownership or completeness.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- `MapTileImageLib::MapTileImageLib()` is an exact constructor at `0x004d1860-0x004d199e`; fresh IDA evidence removes the stale MCP-timeout caveat.
- `LoadTileEpfMetadata` is a file-local static/helper in `NexusTK/render/MapTileImageLib.cpp`, not a shared ImageFrameTable helper.
- The safest binary-backed loader signature is `static ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName)`.
- `this + 0x04` is `ArchiveMetadataTable *tileFrameTable`.
- `this + 0x08` is `MapTileRecord *tileRecords`.
- `MapTileRecord::paletteIndex` is the low 15 bits of each `TILE.TBL` entry.
- `MapTileRecord::allowPaletteFilter` is the high bit, stored as a byte and consumed only by DrawTile's palette-filter path.
- [UID:000177] is a non-emitting split/index page; exact children should emit if/when their formal C++ blocks are accepted.

Evidence checked:

- Target docs for [UID:0002IZ] and [UID:0002J1].
- Support class/file/layout/record/vtable/global docs.
- Existing executed B reports.
- Proposed source tree.
- Fresh IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, and decompiler output for constructor, loader, DrawTile, destructor/scalar destructor, generic `LoadImageFrameTable`, and nearby archive builders.
- Coverage report rows around the MapTileImageLib cluster.
- Recovered/generated source only as non-authoritative lead material.

Rejected alternatives:

- Leave both targets at `82/88`: rejected. The old blockers were active-evidence gaps and source-placement uncertainty; fresh MCP and support-doc comparison resolve them above the 85/85 supervisor gate.
- Move tile metadata loading to ImageFrameTable: rejected because the tile helper is one-caller and hardcodes `TILE%d.EPF`, while ImageFrameTable's generic loader has broad cross-family xrefs.
- Treat tile metadata loading as DATFile-owned: rejected because DATFile is archive IO, not resource-specific table construction.
- Simplify the loader to a no-arg signature in docs: rejected for now because the constructor passes `L"TILE.EPF"` and IDA shows a one-argument helper even though the body ignores it.
- Name the `TILE.TBL` low field as a frame index: rejected because DrawTile uses tile id for frame lookup and the low field for palette lookup.
- Name the `TILE.TBL` high bit as a gameplay/collision flag: rejected because the only observed consumer is DrawTile's palette-filter gate.
- Emit aggregate C++ from [UID:000177]: rejected because exact child pages exist and the aggregate is an index/split artifact.

Validation of existing docs:

- Constructor behavioral documentation is substantially correct but should drop the stale MCP-timeout caveat, add the fresh xref/callee/decompile evidence, and promote the field/record names above provisional wording.
- Loader behavioral documentation is substantially correct but should close the shared-module uncertainty in favor of file-local MapTileImageLib placement.
- Class/layout/record docs are directionally correct but should standardize `tileFrameTable`, `tileRecords`, `paletteIndex`, and `allowPaletteFilter`.
- File docs are correct to place this source under `NexusTK/render/MapTileImageLib.cpp` and should add that the empty active generated file is caused by blank formal C++ blocks, not owner/emitter uncertainty.
- Coverage report row [UID:000177] is stale and needs exact replacement.

Score/source-placement/final-C++ impact:

- [UID:0002IZ] should become `87/91`, owner/emitter unchanged, source placement unchanged, formal C++ blank for this pass.
- [UID:0002J1] should become `87/91`, owner/emitter unchanged, source placement unchanged, formal C++ blank for this pass.
- [UID:000177] should stay non-emitting and non-reconstructable; coverage should match the current page range/status.
- No remaining evidence blocker caps either primary below 85 completion. The only remaining blockers are formal code integration blockers, not source-quality documentation blockers.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0002IZ] or [UID:0002J1] in this pass, even though both targets should now clear the 85/85 source-quality gate.

Concrete reason:

- A source-quality formal block would depend on accepted shared declarations for `ArchiveMetadataTable`, `PackedArchiveRecord`, `MapTileRecord`, DATFile wrappers, allocator/free wrappers, and the fatal cleanup path.
- Populating only these two by-memory targets now would either duplicate ImageFrameTable-owned archive table declarations in MapTileImageLib or preserve generated names/wrapper artifacts that are not final source quality.
- The active generated route for `MapTileImageLib.cpp` is currently empty and recovered source omits the ordinary destructor/singleton-clear support. Constructor/helper code should be emitted only after the class/file support docs are updated together so the final file does not encode partial class semantics.

Source-facing declarations to use when the support docs are ready:

```cpp
struct MapTileRecord {
    uint16_t paletteIndex;
    uint8_t allowPaletteFilter;
    uint8_t reserved;
};

class MapTileImageLib : public LObject {
public:
    MapTileImageLib();
    ~MapTileImageLib();
    void DrawTile(int x, int y, int tileId);

private:
    ArchiveMetadataTable *tileFrameTable;
    MapTileRecord *tileRecords;
};

static ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName);
```

These declarations are a first-draft source direction, not a formal accepted code block.

## Exact Target Doc Changes Recommended

For [UID:0002IZ], apply these supervisor-owned changes:

- Change metadata score to `COMPLETION: 87` and `CONFIDENCE: 91`.
- Keep `RECONSTRUCTABLE: true`.
- Keep owner/emitter `[UID:00007T] MapTileImageLib`.
- Replace any stale 2026-06-06 MCP-timeout caveat with:

```text
2026-06-17 B003 source-quality recheck: fresh IDA MCP lookup/xref/callee/decompile evidence validates the exact constructor range, startup caller, singleton/vtable writes, DATFile open/read/close flow, LoadTileEpfMetadata call, TILE.TBL count validation, MapTileRecord allocation/decode, and next-function padding. The prior 2026-06-06 MCP timeout is historical only and no longer caps completion/confidence.
```

- Standardize field/record names in the body:
  - `this + 0x04`: `ArchiveMetadataTable *tileFrameTable`.
  - `this + 0x08`: `MapTileRecord *tileRecords`.
  - `MapTileRecord + 0x00`: `uint16_t paletteIndex`.
  - `MapTileRecord + 0x02`: `uint8_t allowPaletteFilter`.
  - `MapTileRecord + 0x03`: `uint8_t reserved`.
- Leave the formal C++ block blank with the First-Draft C++ rationale above.

For [UID:0002J1], apply these supervisor-owned changes:

- Change metadata score to `COMPLETION: 87` and `CONFIDENCE: 91`.
- Keep `RECONSTRUCTABLE: true`.
- Keep owner/emitter `[UID:0000L5] MapTileImageLib file`.
- Add/replace source signature wording with:

```text
Best source-facing signature: `static ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName)`. The constructor passes `L"TILE.EPF"` and IDA models the helper as a one-argument `__stdcall` routine, but the body hardcodes `TILE%d.EPF` shard scanning and does not read the parameter.
```

- Add/replace source-placement wording with:

```text
Keep this helper file-local in `NexusTK/render/MapTileImageLib.cpp`. The shared `ArchiveMetadataTable`/record type belongs with ImageFrameTable support docs, but this builder is tile-resource-specific: it has one constructor caller and hardcoded `TILE%d.EPF` shard policy. Do not move it to ImageFrameTable or DATFile without new source evidence.
```

- Leave the formal C++ block blank with the First-Draft C++ rationale above.

For support docs:

- [UID:000177]: keep non-emitting split/index status and update coverage row as shown below.
- [UID:00007T], [UID:0001V2], [UID:0001V3]: standardize the field/record names above and remove wording that treats them as unresolved blockers.
- [UID:0000L5]: keep `LoadTileEpfMetadata` under `NexusTK/render/MapTileImageLib.cpp`; note that the active generated file is empty because formal C++ blocks are blank, not because owner/emitter routing is wrong.
- [UID:0000UN]/[UID:0000K1]: no ownership change required; they continue to own the shared archive metadata table type and generic frame-table helpers, not the tile-specific shard builder.

## Exact Coverage Row Replacement

Placement context: replace the current [UID:000177] MapTileImageLib block in `by-memory/-coverage-report.md` beginning at the existing row for [UID:000177] and ending at [UID:0002J2]. The sibling rows [UID:000178], [UID:0002J0], and [UID:0002J2] are included unchanged except for being carried in the pasteable block.

```markdown
    - [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) 0x004d1860-0x004d1f30 | class-method-cluster/index | MapTileImageLib local method cluster : not_reconstructable : 83% : strong : Non-emitting local split/index for the MapTileImageLib constructor, ordinary destructor, DrawTile method, and tile EPF metadata helper before ObjectStatusBlobParsers begins at 0x004d1f30; exact child pages carry source ownership/emission, and the later singleton clear/scalar deleting destructor pages are separate support targets rather than aggregate body output.
        - [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) 0x004d1860-0x004d199e | constructor | MapTileImageLib::MapTileImageLib : reconstructable : 87% : very-strong : Fresh 2026-06-17 IDA MCP evidence validates the exact 0x13e constructor range, startup caller, singleton/vtable writes, LoadTileEpfMetadata call, DATFile TILE.TBL validation, 4-byte MapTileRecord allocation/decode, tileFrameTable/tileRecords field roles, paletteIndex/allowPaletteFilter semantics, class parent attachment, and MapTileImageLib.cpp source route while formal C++ remains intentionally blank pending shared type/wrapper integration.
        - [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) 0x004d19a0-0x004d1a1c | destructor | MapTileImageLib::~MapTileImageLib : reconstructable : 82% : strong : Live IDA reconfirms the ordinary source-authored destructor body, exact `0x7c` range, next DrawTile boundary, vtable store, no direct callers/xrefs, metadata payload/table and tile-record frees, `g_pMapTileImageLib` clear, LObject cleanup, scalar-deleting-destructor relationship, and class parent attachment while final C++ remains blank pending class-wide source names.
        - [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) 0x004d1a20-0x004d1b72 | method | MapTileImageLib::DrawTile : reconstructable : 82% : strong : Existing IDA-backed docs now detail the exact `0x152` range, padding before the metadata helper, render-suspension guard, legacy `TILE.TBD` clamp, `EPFTileContext` setup, metadata-field read, `MapTileRecord` palette-filter gate, `TILE.PAL` slot `0` lookup, fallback/blit callbacks, class parent attachment, and blank final C++ while the 2026-06-06 MCP retry timed out after `tools/list`.
        - [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) 0x004d1b80-0x004d1f22 | helper | LoadTileEpfMetadata : reconstructable : 87% : very-strong : Fresh 2026-06-17 IDA MCP evidence validates the exact 0x3a2 helper range, one constructor caller, one-argument unused-name signature, TILE%d.EPF shard scan, DATFile read/data-pointer flow, merged ArchiveMetadataTable allocation, 24-byte packed record rebasing, sentinel append, cleanup, file-local MapTileImageLib.cpp placement, and rejection of shared ImageFrameTable/DATFile ownership while formal C++ remains intentionally blank pending shared type/wrapper integration.
        - [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) 0x004e66a0-0x004e6748 | scalar-deleting-destructor | MapTileImageLib scalar deleting destructor : reconstructable : 82% : strong : Live IDA reconfirms the `0xa8` scalar deleting wrapper, vtable-slot-only xref, no direct callers, metadata/table/tile-record cleanup, `g_pMapTileImageLib` clear, LObject cleanup, deleting flag branches, class parent attachment, and source-declared/generated-binary rebuild handling.
```

## Validation Commands

Commands already run for this report:

> Executable block R001 was removed from this report and preserved verbatim in [0002IZ-0002J1-maptileimagelib-source-quality-removed.md](0002IZ-0002J1-maptileimagelib-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended supervisor validation after applying doc/coverage edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002IZ-0002J1-maptileimagelib-source-quality-removed.md](0002IZ-0002J1-maptileimagelib-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run `--mode autogen --apply` until the supervisor decides whether to keep the formal C++ blocks blank as recommended here.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002IZ-0002J1-maptileimagelib-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002IZ"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IZ-0002J1-maptileimagelib-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002IZ-0002J1-maptileimagelib-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
