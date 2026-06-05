*** UID:0000M4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ObjectList

## Status

- Proposed module: `NexusTK/map/ObjectList.cpp`
- Proposed header: `NexusTK/map/ObjectList.h`
- Confidence: strong for map-specific module ownership, lifecycle/vtable boundaries, helper ranges, and layout agreement; medium-high for final source-facing helper names.

## File Role

`ObjectList.cpp` is the likely original owner of the map-world object indexing container used by [UID:0000L3][MapPane](by-file/MapPane.md). It should not be merged into `util/List.cpp`: it uses the generic [UID:000079][List](by-class/List.md) container internally, but every confirmed constructor/helper caller is map-rendering, map-transition, hit-test, scroll, or object cleanup code.

The strongest working reconstruction is:

```text
map/ObjectList.h
map/ObjectList.cpp
```

with `MapPane.h` holding an `ObjectList*` member around the current `MapPane + 0x424` object-index field.

## Proposed Contents

| Entity | Current range | Evidence/source-facing caveat | Proposed ownership |
| --- | --- | --- | --- |
| ObjectList static-object lighting sync helper | `0x00530d00-0x00530ed9` | Real IDA function with a single observed caller at `0x0050e30e`; final source-facing name provisional. | `map/ObjectList.cpp` |
| [UID:00009Q][ObjectList](by-class/ObjectList.md) lifecycle | [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), `0x00537290-0x005372c8` | Constructor/destructor/vtable stores are exact; scalar deleting destructor is vtable-only. | `map/ObjectList.cpp` |
| ObjectList categorize/lookup helpers | `0x00531480-0x00532530` | IDA-modeled helper cluster plus raw `0x00532450` switch helper with no function object. | `map/ObjectList.cpp` |
| ObjectList list accessors | `0x00532530-0x00532660` | Provisional `MapPaneSpatialIndex` alias surface over ObjectList fields. | `map/ObjectList.cpp` |
| ObjectList row-bucket accessors | `0x00532550-0x0053272e` | Provisional accessor alias surface over ObjectList row-list fields. | `map/ObjectList.cpp` |
| `ObjectList::ShiftAll` candidate | `0x00532730-0x00532b72` | anonymous/MapPane call surface | `map/ObjectList.cpp` |
| `ObjectList::DetachAll` candidate | `0x00532b80-0x00532e11` | Three current callers from MapPane cleanup/change/effect paths; final public name provisional. | `map/ObjectList.cpp` |
| object-prune helper | `0x00532e20-0x00532eae` | anonymous/MapPane call surface | `map/ObjectList.cpp` |
| `ObjectList::FindObjectAt` candidate | `0x00532eb0-0x00532f67` | Two current callers from MapPane hit-test/render-neighbor paths; final public name provisional. | `map/ObjectList.cpp` |
| ObjectList extended type lookup helpers | `0x00532f70-0x0053728e` | Mixed modeled/raw helper family; IDA still has no function object at `0x00532f70` or `0x00536270`. | `map/ObjectList.cpp` |
| [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) | data layout | type doc | `map/ObjectList.h` |

## Evidence

- `ObjectList::ObjectList` allocates 13 internal `List` containers or list-array tables from padded map dimensions, including row-counts of `gridHeight + 4` and `gridHeight + 12`.
- 2026-05-31 IDA MCP verifies the exact constructor range as `0x00530ee0-0x0053125d`, the ordinary destructor range as `0x00531260-0x00531473`, and the bytes between them as three `0xcc` alignment bytes.
- IDA MCP caller checks show constructor calls only from `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`.
- `0x00530d00-0x00530ed9`, `0x00531480-0x00532530`, `0x00532530-0x00532f67`, and `0x00532f70-0x0053728e` are adjacent/discontiguous object-list helper islands. The first walks ObjectList row/global fields by static object id to remove, update, or create attached lighting companions; the middle clusters categorize, remove, and look up object panes through type-dispatch helpers; the accessor island returns fields at the exact offsets initialized by the constructor; and the extended helper family handles encoded-key and type-specific list lookup/removal work.
- 2026-05-30 IDA MCP revalidated `0x00531480-0x00532530` and the aggregate now has nested child by-memory pages for each method-level helper and switch-table-backed dispatch unit.
- `MapPane` destructor, map change, effect packet handling, rendering, scroll, and hit-test methods all call into this helper surface.
- `FpsPane::UpdateStatistics` calls read-only ObjectList accessors for diagnostics, which is a consumer relationship and not source ownership.
- 2026-06-04 live IDA MCP recheck confirms exact boundaries for `0x00530d00-0x00530ed9`, `0x00530ee0-0x0053125d`, `0x00531260-0x00531473`, `0x00531480-0x00531498`, `0x005314a0-0x00531bdc`, `0x00531c10-0x00532142`, `0x00532180-0x0053229e`, `0x005322d0-0x00532341`, `0x00532370-0x00532443`, `0x00532530-0x0053272e`, `0x00532730-0x00532b72`, `0x00532b80-0x00532e11`, `0x00532e20-0x00532eae`, `0x00532eb0-0x00532f67`, and `0x00537290-0x005372c8`. The same check reports no function object at raw helper starts `0x00532450`, `0x00532f70`, or `0x00536270`.
- 2026-06-04 live IDA MCP recheck confirms constructor callers at `0x0050bc55` and `0x005106e2`, static-object lighting helper caller `0x0050e30e`, `ShiftAll` caller `0x005058f9`, `DetachAll` callers `0x005045e6`, `0x0050bc1a`, and `0x005106a4`, and `FindObjectAt` callers `0x0050583e` and `0x0050f191`.
- 2026-06-04 live IDA MCP reads `0x00620284 -> ??_R4ObjectList@@6B@`, `0x00620288 -> 0x00537290`, `0x0062028c -> 0x004f4b10`, `0x00620290 -> 0x0041b6c0`, and `0x00620294 -> ??_R4ObjectPane@@6B@`; xrefs to `0x00620288` are the constructor/destructor vptr stores at `0x00530f19` and `0x00531288`.
- 2026-06-04 live IDA MCP byte reads confirm alignment padding at `0x0053125d-0x00531260`, `0x0053272e-0x00532730`, `0x0053728e-0x00537290`, and `0x005372c8-0x005372d0`.

## Source-Structure Decision

Use `map/ObjectList.cpp` as a separate companion module beside `map/MapPane.cpp`. Folding the class into `MapPane.cpp` would hide a coherent 68-byte class with constructor, destructor, vtable, and a contiguous helper island. Placing it under `util/` would over-generalize a container whose callers and stored objects are map-world specific.

`MapPaneSpatialIndex` should remain a temporary documentation alias for the early accessor surface. The final original-source model should collapse that accessor surface back onto `ObjectList`, or document it as a private view of the same layout rather than as a separate allocated class.

## Migration Notes

- Keep [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) attached to `ObjectList`; the `MapPaneSpatialIndex` name is only a provisional alias for the early accessor subset.
- Keep [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md) with `ObjectList`, but leave the final public method name provisional until the caller-side MapPane object update path at `0x0050e300` is split out and reviewed.
- Keep [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) with `ObjectList`; its embedded switch tables are compiler output for ObjectList dispatch helpers, not separate source files.
- Keep [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md) with `ObjectList`; the page includes IDA-modeled functions plus IDA-missed helper starts and internal switch/key-table logic.
- Preserve the existing `MapPaneSpatialIndex` names as provisional method aliases until render-layer names are resolved.
- After merging ownership, update `MapPane` field naming from mixed `m_pObjectGrid` / `m_pObjectList` / `MapPaneSpatialIndex` wording to one `ObjectList*` field.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md)
- [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md)
- [UID:0000KS][List](by-file/List.md)

## Changes

### 2026-05-31 - Added Reconstruction Path And Exact Lifecycle Children

- What existed before: the file page proposed `map/ObjectList.cpp` in prose but left the validator-managed reconstruction path blank, and lifecycle was represented primarily by the aggregate page.
- What changed: `PROPOSED_RECONSTRUCTION_PATH` now stages `NexusTK/map/ObjectList.cpp`, and the proposed contents table links the exact constructor/destructor child pages.
- Why: the proposed-source tree already places ObjectList under the map subsystem, and IDA MCP confirms exact lifecycle child ranges plus constructor callers from `MapPane` map-change/effect-packet paths.

### 2026-05-28 - Added Discontiguous ObjectList Helper Ownership

- What existed before: `ObjectList.cpp` ownership started at the lifecycle range `0x00530ee0-0x00531472`, with the earlier `0x00530d00-0x00530ed9` helper left out of the file-level inventory.
- What changed: `0x00530d00-0x00530ed9` is now tracked as an `ObjectList` helper candidate in `map/ObjectList.cpp`.
- Why: IDA MCP decompile shows a `__thiscall` helper walking ObjectList row/global fields by object id and calling into the later ObjectList helper surface.

### 2026-05-30 - Refined Discontiguous Helper Purpose

- What existed before: the file inventory described `0x00530d00-0x00530ed9` as a remove-by-id helper.
- What changed: the file inventory now describes it as a static-object lighting sync helper, with final method name still provisional.
- Why: IDA MCP decompilation shows the helper looks up static-object metadata and removes, updates, or creates attached `LightingObjectPane` companions for matching static object panes.

### 2026-05-28 - Added ObjectList Categorize/Lookup Helper Cluster

- What existed before: the `0x00531472-0x00532530` span was an unknown gap between ObjectList lifecycle and accessor docs.
- What changed: the lifecycle endpoint was corrected to `0x00531473`, and `0x00531480-0x00532530` is now tracked as an `ObjectList` helper cluster.
- Why: IDA MCP reports real helper functions at `0x00531480`, `0x005314a0`, `0x00531c10`, `0x00532180`, `0x005322d0`, and `0x00532370`, plus an undecorated switch helper at `0x00532450`; all dispatch on ObjectList/object-pane data.

### 2026-05-30 - Split Categorize/Lookup Helper Cluster

- What existed before: the file page referenced `0x00531480-0x00532530` as one broad ObjectList helper cluster.
- What changed: [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) now nests child by-memory pages for each method-level helper and switch-table-backed dispatch unit.
- Why: IDA MCP revalidated the modeled function boundaries and the raw `0x00532450` switch helper; keeping these nested under the aggregate preserves `map/ObjectList.cpp` ownership while making method-level reconstruction work traceable.

### 2026-06-01 - Accessor Island Parent Confirmed

- What changed: [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and the alias subset [UID:0001D2][0x00532530-0x0053272e.MapPaneSpatialIndex](by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md) are now explicitly attached to this file page.
- Why: IDA MCP confirmed the accessor/sweep island uses the same ObjectList fields initialized by the lifecycle code and that `0x0053272e-0x00532730` is alignment before the next ObjectList helper.

### 2026-05-28 - Added Extended Type Lookup Helper Family

- What existed before: `0x00532f67-0x00537290` was an unknown gap between ObjectList accessors and the scalar deleting destructor.
- What changed: `0x00532f67-0x00532f70` and `0x0053728e-0x00537290` are now padding, and `0x00532f70-0x0053728e` is documented as ObjectList extended type lookup/helper code.
- Why: IDA MCP enumerates modeled functions throughout the span and manual disassembly shows additional IDA-missed helper prologues; the helpers use ObjectList fields, encoded object keys, and type-specific list lookup/removal paths.

### 2026-05-28 - Corrected Scalar Destructor Endpoint

- What existed before: the scalar deleting destructor range was listed as `0x00537290-0x005372c7`.
- What changed: the endpoint is now `0x005372c8`.
- Why: IDA MCP function review reports the wrapper ending at exclusive address `0x005372c8`; the following `0x005372c8-0x005372d0` bytes are padding.

### 2026-06-04 - Live IDA Consolidation And Score Update

- What existed before: the page carried `74/84`, stale active-output/source-split wording, and older evidence that did not include the current vtable/padding/caller snapshot.
- What changed: scores are now `84/88`, proposed module/header names use the `NexusTK/map/` path, importer-derived ownership wording was replaced with IDA evidence/source-facing caveats, and the evidence section records current function boundaries, raw-start caveats, caller sets, vtable dwords, and padding ranges.
- Why: live IDA MCP confirms the ObjectList lifecycle, vtable, layout, map-only caller surface, and helper-island boundaries strongly enough to move this out of the low-score queue. Completion/confidence remain below final reconstruction levels because several helper names are still provisional and the extended helper family includes raw starts that IDA does not model as functions.
