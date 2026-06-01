*** UID:0001VV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RidingDefinition

## Status

- Confidence: strong for sizes and offsets observed in `RIDINGS.DNA` parsing, medium for final field names.
- Owner: [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md).
- Source placement: [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md), with nested table helpers from [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).

## RidingDefinition Layout

```text
RidingDefinition
  +0x00  uint32 ridingId
  +0x04  uint8 bucketCount
  +0x05  uint8 defaultBucketIndex
  +0x06  uint16 animationGroupId
  +0x08  RidingBucket* buckets
  sizeof = 0x0c
```

The `+0x08` field is managed by the 12-byte outer table helper currently named `MonsterImageLibTable_5289D0`.

## RidingBucket Layout

```text
RidingBucket
  +0x00  RidingBucketEntry* entries
  +0x04  uint16 entryCount
  +0x06  uint16 helper/reserved state
  sizeof = 0x08
```

The `+0x00` field is managed by the 8-byte child table helper currently named `MonsterImageLibTable_528BE0`.

## RidingBucketEntry Layout

```text
RidingBucketEntry
  +0x00  uint16 startFrame
  +0x02  uint16 endFrame
  +0x04  uint8 direction
  +0x05  uint8 reservedOrPadding
  +0x06  uint16 frameStrideOrDelay
  +0x08  uint8 paletteIndex
  +0x09  uint8 effectIndex
  sizeof = 0x0a
```

## Field Evidence

- [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md) reads definition records in the exact order `+0x00` dword, `+0x04` byte, `+0x05` byte, and `+0x06` word.
- The definition vector allocation uses `count * 0x0c`, and the destructor iterator uses element size `0x0c`.
- For each definition, the parser calls `0x005289d0` with the byte at `+0x04` to allocate `bucketCount` 8-byte child rows.
- For each child row, the parser reads entry count at `+0x04`, calls `0x00528be0`, then reads each 10-byte entry at offsets `+0x00`, `+0x02`, `+0x06`, `+0x04`, `+0x08`, and `+0x09`.
- The global default riding table at [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) seeds 21 default 8-byte child rows with one `RidingBucketEntry` spanning `0..30000`.

## IDA MCP Verification Notes

- 2026-05-31 `lookup_funcs` reports `0x004dc420` as a function with size `0x26d`, matching the parser range `0x004dc420-0x004dc68c`.
- 2026-05-31 `callers` reports the parser is called only from the `RidingImageLib` constructor at `0x004dc6f5`.
- 2026-05-31 parser decompilation verifies the fixed 12-byte definition row, 8-byte bucket row, and 10-byte bucket-entry row sizes and the read/write offsets documented above.
- 2026-05-31 `xrefs_to` confirms `0x0069b438` is referenced only as the global table object's `+0x08` entry-pointer field inside the parser.

## Notes

The helper class names remain monster-biased because the same nested table machinery is shared by monster and riding parsers. Final source should use neutral names or keep these as local nested structs under the sprite animation table helper.

## Cross-References

- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)
- [UID:0001VW][RidingImageLibLayout](by-type/by-struct/RidingImageLibLayout.md)
- [UID:0002LA][0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions](by-memory/0x004dc420-0x004dc68c.RidingImageLibLoadRidingDefinitions.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `78/84` and marked the layout reconstructable.
  - Before: the page contained useful layout notes but was still scored as unevaluated and did not explicitly mark the type as reconstructable.
  - After: the page is scored as a strongly verified but non-final layout and `RECONSTRUCTABLE:TRUE`; autogen parent/code remain blank because final source names and helper ownership are below the 95+ gate.
  - Evidence: IDA MCP verification of `0x004dc420-0x004dc68c`, helper calls at `0x005289d0`/`0x00528be0`, default table xrefs, and exact parser read offsets.
