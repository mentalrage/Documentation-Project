*** UID:00007R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapPaneSpatialIndex

## Status

- Disposition: ignored as a standalone class record; keep as a compatibility/provisional alias for [UID:00009Q][ObjectList](by-class/ObjectList.md) accessors used by [UID:00007Q][MapPane](by-class/MapPane.md).
- Confidence: medium as a generated/provisional alias.
- Likely final owner: [UID:00009Q][ObjectList](by-class/ObjectList.md)
- Likely source file: [UID:0000M4][ObjectList](by-file/ObjectList.md), used by [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001D2][0x00532530-0x0053272e.MapPaneSpatialIndex](by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md)
- Current recovered file: `source-3/simroot_v2/class_MapPaneSpatialIndex.cpp`

## Class Purpose

`MapPaneSpatialIndex` is a useful generated name for the row-bucket accessor surface currently emitted in `class_MapPaneSpatialIndex.cpp`. Fresh IDA/Wave3 comparison indicates it is probably not a separate allocated class. The accessors use the same offsets initialized by [UID:00009Q][ObjectList](by-class/ObjectList.md), and generated `MapPane` callers already refer to adjacent helpers as `ObjectList::*`.

Use this page as a compatibility/provisional alias. The final source model should place these methods in `map/ObjectList.cpp` or document them as a private view over the `ObjectList` layout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetLayer0List` | `0x00532530-0x00532533` | Returns the first flat render/hit-test container. |
| `GetLayer1List` | `0x00532540-0x00532543` | Returns the second flat render container. |
| `GetLayer0RowBucket` | `0x00532550-0x005325ad` | Returns the first row-indexed bucket for a requested row. |
| `GetLayer1RowBucket` | `0x005325b0-0x0053260d` | Returns the second row-indexed bucket for a requested row. |
| `GetVisibleObjectList` | `0x00532610-0x00532613` | Returns the counted visible-object list. |
| global-list accessor | `0x00532620-0x00532623` | Returns the list at `ObjectList + 0x30`. |
| global-list accessor | `0x00532630-0x00532633` | Returns the list at `ObjectList + 0x34`. |
| global-list accessor | `0x00532640-0x00532643` | Returns the list at `ObjectList + 0x38`. |
| global-list accessor | `0x00532650-0x00532653` | Returns the list at `ObjectList + 0x3c`. |
| global-list accessor | `0x00532660-0x00532663` | Returns the list at `ObjectList + 0x40`. |
| `GetFrontRowBucket` | `0x00532670-0x005326cd` | Returns a front-layer row bucket. |
| `GetBackRowBucket` | `0x005326d0-0x0053272e` | Returns a back-layer row bucket. |

## Evidence Notes

- IDA MCP confirms `0x00532530`, `0x00532550`, and `0x005326d0` are real functions.
- 2026-06-01 IDA MCP endpoint review confirms `sub_5326D0` ends at `0x0053272e`; `0x0053272e-0x00532730` is `0xcc` alignment before the next ObjectList helper.
- Callers include MapPane render/hit-test methods such as `RenderMapView`, `FindStaticObjectAtCoords`, and neighboring object-grid paths.
- `ObjectList::ObjectList` initializes the same field offsets used by these accessors: `+0x14`, `+0x18`, `+0x1c`, `+0x20`, `+0x24`, `+0x28`, and `+0x2c`.
- IDA MCP enumerates adjacent non-lifecycle ObjectList helpers from `0x00532530` through `0x0053728e`; see [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md).
- The class is not a standalone feature; it should migrate with `ObjectList` and remain coupled to `MapPane`.
- 2026-05-25 `simroot_v2` comparison confirms `class_MapPaneSpatialIndex.cpp` emits only the early accessors through `0x005326d0`; the larger shift/detach/prune/find helpers remain outside this generated alias but use the same concrete `ObjectList` layout.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001D2][0x00532530-0x0053272e.MapPaneSpatialIndex](by-memory/0x00532530-0x0053272e.MapPaneSpatialIndex.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)

## Changes

### 2026-05-28 - Extended Adjacent ObjectList Helper Surface

- What existed before: this alias page only pointed to adjacent non-lifecycle ObjectList helpers through `0x00532f67`.
- What changed: it now also references the extended ObjectList type lookup helper family at `0x00532f70-0x0053728e`.
- Why: IDA MCP and manual disassembly confirm the formerly unknown span contains ObjectList-shaped encoded-key and list lookup/removal helpers rather than unrelated MapPaneSpatialIndex code.
- Completion/confidence score update: existed before as `0/0` and a reconstructable standalone class row; changed to `-1/-1` as an ignored standalone class alias. Summary: the page remains as a compatibility note, but scoring should follow the replacement owner `ObjectList` because the current evidence says this is not a separately allocated original class. Evidence: existing page notes that the accessors use `ObjectList` offsets, generated `MapPane` callers already name adjacent helpers as `ObjectList::*`, and the replacement owner is documented in `ObjectList` memory ranges.

### 2026-06-01 - Alias Endpoint Sync

- What changed: synced the alias endpoint and links from `0x0053272d` to `0x0053272e`.
- Why: IDA MCP reports `sub_5326D0` as `0x005326d0-0x0053272e`, with only `0x0053272e-0x00532730` as alignment before the next ObjectList helper.
