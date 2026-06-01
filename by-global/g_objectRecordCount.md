*** UID:0000Q4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_objectRecordCount

## Status

- Confidence: strong for storage address and relationship to `g_objectNationMap`.
- Current Wave3 kind: `global-data`.
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
