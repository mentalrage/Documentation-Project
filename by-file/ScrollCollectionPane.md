*** UID:0000NG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollCollectionPane

## Status

- Confidence: medium for standalone file placement; strong for class behavior.
- Proposed module folder: `ui/core/` or `ui/controls/`
- Proposed source file: `ui/core/ScrollCollectionPane.cpp`
- Evidence basis: `class_ScrollCollectionPane.meta_wave3`, generated source, existing scrollbar notes from [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md), and IDA MCP vtable/layout checks on 2026-05-26.

## Hypothesis

Despite its name, `ScrollCollectionPane` should not be treated as collection-feature code by default. It is a 272-byte `Pane`-derived EPF-backed scrollbar with range, position, hover/drag part state, and timer/update hooks. `CollectionPane` constructs it directly, but existing docs already show nearby text-edit and group scrollbar overlap, so final ownership should be decided in a generic scrollbar pass.

IDA currently has partial function-model and generated-output gaps in this range: Wave3 starts at `0x00562e80` and `0x00563200` are raw-code confirmed but not IDA function objects, raw helper `0x00562ef0` is omitted, IDA confirms additional internal helpers at `0x00562fb0` and `0x00563070`, and the real hit-test helper at `0x005628d0` is called by generated code but not emitted as a scoped method.

IDA MCP recheck on 2026-06-01 confirms this as a self-contained sibling themed scrollbar class rather than a collection-private helper or older `ScrollBar.cpp` merge: constructor `0x00561db0` installs `ScrollCollectionPane` vtables `0x00623fa4`, `0x00623ff0`, and `0x00624020`; `CollectionPane` calls only the constructor/range/position/show APIs; the internal hit-test, geometry, draw, highlight, drag, and clear helpers call each other within `0x00561db0-0x0056325c`; and `0x00563260` is the next scrollbar class constructor.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) | `0x00561db0-0x0056325b` | `class_ScrollCollectionPane.cpp` | Scrollbar constructor, range/position setters, input handling, paint, part-rect geometry, highlight state. |
| [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md) | offsets `+0xfc` through `+0x108` | type docs | Orientation, position/range, enabled/highlight/active part, and drag offset fields. |
| [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md) | vtables `0x00623fa4`, `0x00623ff0`, `0x00624020` | type docs | Primary, secondary, and tertiary pane views. |
| [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md) | `0x005628d0-0x00562bed` | omitted scoped method | Maps point/cursor state to region `0..4` or `-1`. |
| scroll resources | data globals | generated global-data aliases | `g_scrollBitmapResource`, `g_scrollThumbResource`, masks, blend modes, and size table. |

## Migration Notes

Initial dry-run target:

```powershell
python source-3\wave3.py create file ScrollCollectionPane.cpp --kind source --simpath ui/core/ScrollCollectionPane.cpp --dry-run
python source-3\wave3.py attach class ScrollCollectionPane --to-file ScrollCollectionPane.cpp --dry-run
```

Before applying this, compare against [UID:0000NF][ScrollBar](by-file/ScrollBar.md), [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md), [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and [UID:0000JS][Group](by-file/Group.md). The final source may be `ScrollBar.cpp` if this is just a themed scrollbar implementation.

## Cross-References

- [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md)
- [UID:0001GT][0x00561db0-0x0056325b.ScrollCollectionPane](by-memory/0x00561db0-0x0056325b.ScrollCollectionPane.md)
- [UID:0001VZ][ScrollCollectionPaneLayout](by-type/by-struct/ScrollCollectionPaneLayout.md)
- [UID:0001YP][ScrollCollectionPaneVtables](by-type/by-vtable/ScrollCollectionPaneVtables.md)
- [UID:0001GU][0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion](by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md)
- [UID:0001GV][0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers](by-memory/0x00562e80-0x00562fb0.ScrollCollectionPaneHighlightRawHelpers.md)
- [UID:0001GW][0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll](by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md)
- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `76`.
  - Evidence: document captures class role, proposed contents, layout/vtable refs, raw/helper gaps, migration notes, and generic-scrollbar caveats; confidence remains limited by unresolved standalone-vs-ScrollBar source placement and partial IDA function modeling.
