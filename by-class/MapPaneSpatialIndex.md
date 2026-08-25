*** UID:00007R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapPaneSpatialIndex

## Status

- Disposition: ignored as a standalone class record; keep as a compatibility/provisional alias for [UID:00009Q][ObjectList](by-class/ObjectList.md) accessors used by [UID:00007Q][MapPane](by-class/MapPane.md).
- Confidence: medium as a generated/provisional alias.
- Likely final owner: [UID:00009Q][ObjectList](by-class/ObjectList.md)
- Likely source file: [UID:0000M4][ObjectList](by-file/ObjectList.md), used by [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)

## Class Purpose

`MapPaneSpatialIndex` is a retained compatibility/search name for the row-bucket and list accessor surface now documented as [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md). Existing IDA-backed ObjectList documentation indicates it is not a separate allocated class. The accessors use the same offsets initialized by [UID:00009Q][ObjectList](by-class/ObjectList.md), and neighboring ObjectList pages place the broader accessor/sweep surface under ObjectList ownership.

Use this page as a compatibility/provisional alias only. The final source model places these methods in `map/ObjectList.cpp` through [UID:00009Q][ObjectList](by-class/ObjectList.md); exact formal method C++ lives on [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetPrimaryCellList` (`GetLayer0List` alias) | `0x00532530-0x00532534` | Returns `m_primaryCellList`. |
| `GetSecondaryCellList` (`GetLayer1List` alias) | `0x00532540-0x00532544` | Returns `m_secondaryCellList`. |
| `GetPrimaryRowBucket` (`GetLayer0RowBucket` alias) | `0x00532550-0x005325ae` | Returns `m_primaryRowLists[row - bounds.top]`. |
| `GetSecondaryRowBucket` (`GetLayer1RowBucket` alias) | `0x005325b0-0x0053260e` | Returns `m_secondaryRowLists[row - bounds.top]`. |
| `GetVisibleObjectList` | `0x00532610-0x00532614` | Returns `m_primaryGlobalList`. |
| `GetSecondaryGlobalList` | `0x00532620-0x00532624` | Returns `m_secondaryGlobalList`. |
| `GetAlternateGlobalList` | `0x00532630-0x00532634` | Returns `m_alternateGlobalList`. |
| `GetTertiaryGlobalList` | `0x00532640-0x00532644` | Returns `m_tertiaryGlobalList`. |
| `GetQuaternaryGlobalList` | `0x00532650-0x00532654` | Returns `m_quaternaryGlobalList`. |
| `GetQuinaryGlobalList` (`GetInternalList` alias) | `0x00532660-0x00532664` | Returns `m_quinaryGlobalList`. |
| `GetFrontRowBucket` | `0x00532670-0x005326ce` | Returns `m_tertiaryRowLists[row - bounds.top]`. |
| `GetBackRowBucket` | `0x005326d0-0x0053272e` | Returns `m_extendedRowLists[row - bounds.top]` with the wider bottom pad. |

## Evidence Notes

- IDA MCP confirms `0x00532530`, `0x00532550`, and `0x005326d0` are real functions.
- 2026-06-01 IDA MCP endpoint review confirms `sub_5326D0` ends at `0x0053272e`; `0x0053272e-0x00532730` is `0xcc` alignment before the next ObjectList helper.
- Callers include MapPane render/hit-test methods such as `RenderMapView`, `FindStaticObjectAtCoords`, and neighboring object-grid paths.
- `ObjectList::ObjectList` initializes the same field offsets used by these accessors: `+0x14`, `+0x18`, `+0x1c`, `+0x20`, `+0x24`, `+0x28`, and `+0x2c`.
- IDA MCP enumerates adjacent non-lifecycle ObjectList helpers from `0x00532530` through `0x0053728e`; see [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md).
- The class is not a standalone feature; it should migrate with `ObjectList` and remain coupled to `MapPane`.
- 2026-06-27 B012 sync records [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) at `90/91` as exact ObjectList accessor methods with formal C++. This page remains ignored as the alias ledger.
- 2026-06-06 A009 sync recorded [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) at `80/86` as a compatibility alias subset and [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) at `84/86` as the broader ObjectList owner range; B012 supersedes only the source-facing identity, not the retained alias evidence.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)

## Changes

### 2026-06-27 B012 - Alias Retained After Accessor Reclassification

- What changed: this ignored alias page now points to [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md), uses the accepted ObjectList accessor names, and keeps older `MapPaneSpatialIndex`/layer/internal names as search aliases only.
- Why: B012 live MCP proved the executable range belongs to ObjectList and is safe for formal child C++, while this class record remains non-reconstructable/non-emitting as a generated/provisional alias.

### 2026-06-06 A009 - Alias Evidence Sync

- What existed before: this ignored alias page still referenced generated-source output while pointing to ObjectList as the replacement owner.
- What changed: removed generated-source framing, linked the refreshed [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) memory range, then still documented as the `MapPaneSpatialIndex` alias, and [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) owner range, and kept `RECONSTRUCTABLE:FALSE` with `-1/-1` scoring.
- Why: local IDA-backed ObjectList documentation is sufficient to preserve this as a compatibility alias without relying on generated source output as evidence.

- 2026-06-05: Marked not reconstructable as a standalone class because this page is already an ignored generated/provisional alias for [UID:00009Q][ObjectList](by-class/ObjectList.md), with replacement owner recorded in [UID:000003][-ignored](by-class/-ignored.md). Live IDA MCP evidence still confirms the accessor starts at `0x00532530`, `0x00532550`, and `0x005326d0`, and `callers` for `0x00532550` come from MapPane/ObjectList paths at `0x00509a3b` and `0x0050e967`; those facts support ObjectList ownership, not a separate allocated class.

### 2026-05-28 - Extended Adjacent ObjectList Helper Surface

- What existed before: this alias page only pointed to adjacent non-lifecycle ObjectList helpers through `0x00532f67`.
- What changed: it now also references the extended ObjectList type lookup helper family at `0x00532f70-0x0053728e`.
- Why: IDA MCP and manual disassembly confirm the formerly unknown span contains ObjectList-shaped encoded-key and list lookup/removal helpers rather than unrelated MapPaneSpatialIndex code.
- Completion/confidence score update: existed before as `0/0` and a reconstructable standalone class row; changed to `-1/-1` as an ignored standalone class alias. Summary: the page remains as a compatibility note, but scoring should follow the replacement owner `ObjectList` because the current evidence says this is not a separately allocated original class. Evidence: existing page notes that the accessors use `ObjectList` offsets, generated `MapPane` callers already name adjacent helpers as `ObjectList::*`, and the replacement owner is documented in `ObjectList` memory ranges.

### 2026-06-01 - Alias Endpoint Sync

- What changed: synced the alias endpoint and links from `0x0053272d` to `0x0053272e`.
- Why: IDA MCP reports `sub_5326D0` as `0x005326d0-0x0053272e`, with only `0x0053272e-0x00532730` as alignment before the next ObjectList helper.
