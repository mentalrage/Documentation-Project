*** UID:0000Q4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_objectRecordCount

## Status

- Confidence: strong for storage address and relationship to `g_objectNationMap`.
- IDA storage: `0x0069b4bc` (`dword_69B4BC`).
- Proposed owner: [UID:0000L3][MapPane](by-file/MapPane.md), with loader notes in [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).

## Role

`g_objectRecordCount` is the process-wide count read from [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) immediately before allocating [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md). It bounds map classification checks that index into the compact object-to-nation/classification byte array.

Likely declaration during reconstruction:

```cpp
static std::uint32_t g_objectRecordCount;
```

## Evidence

- `0x00504110` reads four bytes from `SOBJ.TBL` into `dword_69B4BC`, then allocates `dword_69B4BC + 1` bytes for `dword_69B4C0`.
- `0x00504110` uses the same count as the upper bound for reading static-object classification records into [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).
- `0x00505430` reads the count before checking object ids/indexes against `g_objectNationMap` and direction masks.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4bc-0x0069b4c0`, bytes `ff ff ff ff`, initial dword `0xffffffff`, and five xrefs: loader write/read sites at `0x005042fa`, `0x00504315`, `0x00504331`, `0x00504397`, plus consumer bounds check read `0x00505561`. The exact split memory page is [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md).

## Caveats

`StaticObjImageLib` also reads the first four bytes of `SOBJ.TBL`, but stores that count in its instance field rather than in this global. Keep this global scoped to the map/gameplay cache, not the full static-object render table.

The `MapPane` loader uses slot zero as a sentinel and starts its read/store loop at index `1`; verify the exact record-to-index convention against actual DAT contents before freezing final field names.

## Cross-References

- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/82`. Summary/evidence: the page documents address, relationship to `g_objectNationMap`, loader/count use, consumer bounds checks, and caveats about the map-gameplay cache versus `StaticObjImageLib`; scope is narrow but well-supported.
- 2026-06-05: Marked reconstructable under [UID:0000L3][MapPane](by-file/MapPane.md). Evidence: live IDA MCP xrefs to `0x0069b4bc` are confined to the map loader at `0x00504110` and consumer bounds checks at `0x00505430`; decompilation confirms the count is read before allocating and filling [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md).
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: `84/82`, below the corrected `85/85` gate for assigning an exact memory storage child.
  - After: `86/86`.
  - Evidence: live IDA MCP reconfirmed exact four-byte storage bounds, initial value, loader write/read xrefs, and consumer bounds-check read. The remaining DAT record-to-index caveat affects final field naming, not ownership of this global count slot.
