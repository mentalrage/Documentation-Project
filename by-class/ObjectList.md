*** UID:00009Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectList

## Status

- Confidence: strong for layout, map-object responsibility, lifecycle/vtable boundaries, helper ranges, and current caller evidence; medium-high for final public method names.
- Likely source file: [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Lifecycle ranges: [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md), [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), and [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md)
- Accessor/sweep ranges: [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)

## Class Purpose

`ObjectList` is the map-owned world-object index. It builds a padded grid around the current map, owns multiple `List` containers of object pointers, exposes flat render/hit-test lists and row buckets, and sweeps or shifts the objects during map changes, scrolls, cleanup, and render passes.

This is not the generic utility [UID:000079][List](by-class/List.md). `ObjectList` consumes `List` objects internally, but its contents and callers are specific to `MapPane` object panes.

## Layout

The constructor allocates a 68-byte object and installs the `ObjectList` vtable. The observed field layout is:

```text
0x00  vtable
+0x04  int minX
+0x08  int minY
+0x0c  int gridWidth
+0x10  int gridHeight
+0x14  List* primaryCellList
+0x18  List* secondaryCellList
+0x1c  List** primaryRowLists
+0x20  List** secondaryRowLists
+0x24  List** tertiaryRowLists
+0x28  List** extendedRowLists
+0x2c  List* primaryGlobalList
+0x30  List* secondaryGlobalList
+0x34  List* alternateGlobalList
+0x38  List* tertiaryGlobalList
+0x3c  List* quaternaryGlobalList
+0x40  List* quinaryGlobalList
```

See [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md) for the type-layout view.

## Method Families

| Range | Evidence/source-facing caveat | Likely `ObjectList` role |
| --- | --- | --- |
| `0x00530d00-0x00530ed9` | Real IDA function with a single observed caller at `0x0050e30e`; final name provisional. | Static-object lighting sync helper that walks ObjectList row/global fields by object id, then removes, updates, or creates attached lighting companions; final name provisional. |
| [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) | `ObjectList::ObjectList` | Allocates all row/global `List` tiers using padded map dimensions. |
| [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) | `ObjectList::~ObjectList` | Releases row-list arrays, global lists, optional `+0x34` tier, and base `LObject`. |
| `0x00531480-0x00532530` | ObjectList categorize/lookup helpers | Categorizes, removes, and looks up object panes through type-dispatch helpers and embedded switch tables. |
| `0x00532530-0x00532660` | Provisional `MapPaneSpatialIndex` alias surface over ObjectList fields. | Accessors for flat/global lists at `+0x14`, `+0x18`, and `+0x2c` through `+0x40`. |
| `0x00532550-0x0053272e` | Provisional accessor alias surface over ObjectList row-list fields. | Row-bucket accessors using `minX/minY/gridWidth/gridHeight` padded bounds. |
| `0x00532730-0x00532b72` | anonymous/global in IDA | Shifts every object in the stored lists by a map-scroll delta. |
| `0x00532b80-0x00532e11` | Three current callers from MapPane cleanup/change/effect paths; final public name provisional. | Sweeps stored object lists and releases object panes, optionally preserving one supplied object. |
| `0x00532e20-0x00532eae` | anonymous/global in IDA | Releases row-bucket entries whose object marker at `+0x13c` is `-1`. |
| `0x00532eb0-0x00532f67` | Two current callers from MapPane hit-test/render-neighbor paths; final public name provisional. | Searches a row bucket for an object at map coordinates. |
| `0x00532f70-0x0053728e` | ObjectList extended type lookup helpers | Encoded-key, type-specific list lookup, and list removal helper family with several IDA-missed internal starts. |
| `0x00537290-0x005372c8` | `ObjectList::ScalarDeletingDestructor` | Destructor wrapper and optional delete. |

## Evidence Notes

- IDA MCP confirms `ObjectList::ObjectList` at `0x00530ee0-0x0053125d`, destructor at `0x00531260-0x00531473`, and scalar deleting destructor at `0x00537290-0x005372c8`.
- 2026-05-31 IDA MCP decompilation verifies the constructor writes all fields in [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md), the ordinary destructor cleans up the same row/global list tiers, and `0x0053125d-0x00531260` is `0xcc` padding.
- 2026-05-30 IDA MCP confirms `0x00530d00-0x00530ed9` as a real `__thiscall` helper over ObjectList layout fields. It is called from a MapPane wrapper through `MapPane + 0x424`, looks up static-object metadata, scans matching static object panes, and removes, updates, or creates attached [UID:000075][LightingObjectPane](by-class/LightingObjectPane.md) companions.
- 2026-05-30 IDA MCP confirms `0x00531480-0x00532530` as an ObjectList helper cluster now split into child pages for origin initialization, type-dispatch insert/remove, encoded-key resolution, type-specific index lookup, object-id lookup, and the raw `0x00532450` boolean existence helper with jump table.
- 2026-05-28 IDA MCP confirms `0x00532f70-0x0053728e` as the next ObjectList helper family, with modeled functions, encoded-key helpers, type-specific list lookups, and many IDA-missed prologues inside the range.
- Constructor callers are `MapPane::ChangeMap` at `0x0050bbb0` and `MapPane::HandleEffectPacket` at `0x005104d0`, both replacing the map object index after map data changes.
- Documented MapPane callers already use the helper island as `ObjectList::DetachAll`, `ObjectList::GetInternalList`, `ObjectList::FindObjectAt`, `ObjectList::ShiftAll`, and `ObjectList::GetRow`.
- The `MapPaneSpatialIndex` accessor docs use exactly the offsets initialized by `ObjectList::ObjectList`, so `MapPaneSpatialIndex` is best treated as a provisional alias over the `ObjectList` accessor surface.
- 2026-06-01 IDA MCP recheck confirms the helper-island starts and sizes from `0x00532530` through `0x00532eb0`, corrects the early alias subset endpoint to `0x0053272e`, and confirms `0x0053272e-0x00532730` is alignment before `ShiftAll`.
- 2026-06-04 live IDA MCP recheck confirms exact boundaries for the lifecycle and helper islands from `0x00530d00` through `0x005372c8`, reports no function object at raw helper starts `0x00532450`, `0x00532f70`, or `0x00536270`, confirms the constructor/destructor vptr stores to `0x00620288`, and reconfirms alignment padding at `0x0053125d-0x00531260`, `0x0053272e-0x00532730`, `0x0053728e-0x00537290`, and `0x005372c8-0x005372d0`.
- 2026-06-04 live IDA MCP recheck confirms constructor callers at `0x0050bc55` and `0x005106e2`, static-object lighting helper caller `0x0050e30e`, `ShiftAll` caller `0x005058f9`, `DetachAll` callers `0x005045e6`, `0x0050bc1a`, and `0x005106a4`, and `FindObjectAt` callers `0x0050583e` and `0x0050f191`.

## Open Questions

- Final names for the five global-list accessors at `0x00532620-0x00532660` need caller-specific render-layer names.
- The exact semantic names of the row-list tiers at `+0x1c`, `+0x20`, `+0x24`, and `+0x28` need one more render/hit-test pass.
- Decide whether `MapPaneSpatialIndex` should collapse into `ObjectList`, or remain as a documented nested/helper view while sharing the same concrete layout.

## Cross-References

- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)
- [UID:0001YB][ObjectList_vtable](by-type/by-vtable/ObjectList_vtable.md)
- [UID:000079][List](by-class/List.md)

## Changes

### 2026-05-31 - Split Lifecycle Into Exact Constructor And Destructor Pages

- What existed before: the class inventory listed the lifecycle aggregate and inline constructor/destructor ranges without exact child memory pages.
- What changed: the constructor and ordinary destructor now have their own exact by-memory pages and are cross-linked from the class inventory.
- Why: IDA MCP reports `sub_530EE0` as `0x00530ee0-0x0053125d`, `sub_531260` as `0x00531260-0x00531473`, and byte reads confirm the gap between them is alignment padding.

### 2026-05-30 - Refined Discontiguous Helper Method

- What existed before: the class method inventory treated `0x00530d00-0x00530ed9` as a remove/search helper candidate.
- What changed: the helper is now listed as a static-object lighting sync helper, still with its final source-facing name left provisional.
- Why: IDA MCP shows the method using ObjectList row/global tiers, static-object metadata from `g_pStaticObjImageLib`, and `LightingObjectPane` constructor/set-intensity calls to remove, update, or create attached lighting companions.

### 2026-05-28 - Added ObjectList Categorize/Lookup Helper Cluster

- What existed before: the `0x00531472-0x00532530` span was an unknown gap and the destructor endpoint was one byte short.
- What changed: the destructor endpoint is now `0x00531473`, and the `0x00531480-0x00532530` helper cluster is part of the class method inventory.
- Why: IDA MCP confirms the exact helper starts and embedded switch-table structure, all operating on ObjectList/object-pane type dispatch.

### 2026-05-30 - Split ObjectList Categorize/Lookup Child Pages

- What existed before: the class page referenced `0x00531480-0x00532530` only as a single aggregate helper cluster.
- What changed: [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md) now owns nested child pages for each method-level helper and switch-table-backed dispatch unit.
- Why: IDA MCP revalidated the modeled starts/endpoints and raw `0x00532450` helper body, making method-level documentation possible without losing the aggregate ObjectList ownership.

### 2026-06-01 - Accessor Island Parent Confirmed

- What changed: the `0x00532530-0x00532f67` accessor/sweep island is now explicitly attached to the ObjectList file page, and the `MapPaneSpatialIndex` alias endpoint is corrected to `0x0053272e`.
- Why: IDA MCP function, decompile, caller, and byte evidence shows the early alias subset uses ObjectList fields and that only `0x0053272e-0x00532730` is padding before the next ObjectList helper.

### 2026-05-28 - Added Extended Type Lookup Helper Family

- What existed before: the class method inventory stopped at the `0x00532530-0x00532f67` accessor/sweep island before the scalar deleting destructor.
- What changed: `0x00532f70-0x0053728e` is now included as an ObjectList extended type lookup/helper family.
- Why: IDA MCP and manual disassembly show modeled and IDA-missed helpers that operate on ObjectList fields, encoded object-list keys, and type-specific list lookup/removal paths.

### 2026-05-28 - Corrected Scalar Destructor Endpoint

- What existed before: the scalar deleting destructor was listed as `0x00537290-0x005372c7`.
- What changed: the endpoint is now `0x005372c8`.
- Why: IDA MCP function review reports the destructor wrapper as `0x00537290-0x005372c8`; byte `0x005372c7` is part of the function body, not padding.

### 2026-06-04 - Live IDA Consolidation And Score Update

- What existed before: the class page carried `74/84` and still described importer/output splits as evidence.
- What changed: scores are now `84/88`, stale importer-derived wording was removed, and the class evidence now records current IDA function boundaries, raw-start caveats, caller sets, vtable dwords, and padding ranges.
- Why: live IDA MCP confirms ObjectList lifecycle, vtable, layout, map-only caller surface, and helper-island boundaries strongly enough to move the class out of low-confidence reconstruction status. It remains below final C++ levels because helper names and some raw starts in the extended family are still unresolved.
