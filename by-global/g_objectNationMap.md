*** UID:0000Q3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_objectNationMap

## Status

- Confidence: strong for storage address and role, medium for final name.
- IDA storage: `0x0069b4c0` (`dword_69B4C0`).
- Related count storage: [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), `0x0069b4bc` (`dword_69B4BC`).
- Proposed owner: [UID:0000L3][MapPane](by-file/MapPane.md), with loader notes in [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).

## Role

`g_objectNationMap` is a lazily allocated byte array loaded from `SOBJ.TBL` during map-pane initialization. It maps static-object record ids or indices to the second one-byte classification field from each `SOBJ.TBL` record.

Likely declaration during reconstruction:

```cpp
static std::uint8_t* g_objectNationMap;
static std::uint32_t g_objectRecordCount;
```

## Loader Behavior

`GameServerConfig::InitializeMapPane` at `0x00504110` performs the load when `dword_69B4C0` is null:

1. Open [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md).
2. Read a 4-byte object record count into `dword_69B4BC`.
3. Read a 2-byte table header.
4. Allocate `g_objectRecordCount + 1` bytes and set `g_objectNationMap[0] = 0`.
5. Iterate the observed records, reading `4 + 1 + 1 + 1 + count * 2` bytes per record.
6. Store the second one-byte field into `g_objectNationMap[index]`.

IDA shows the loop index starts at `1` and continues while it is less than `g_objectRecordCount`. Treat the index/base relationship as a DAT-format caveat until checked against a real `SOBJ.TBL` sample.

## Consumers

- `0x00505430` reads `g_objectRecordCount` and `g_objectNationMap` during map movement/collision or placement logic, combining map bytes with direction masks at `byte_66DD50` and `byte_66DD58`.
- `0x00504530` frees the array during map-pane teardown and clears `dword_69B4C0`.
- `StaticObjImageLib` separately parses the same `SOBJ.TBL` resource for the full static-object image table. That class owns the render/resource object records; this global is a map-gameplay classification cache.
- IDA MCP `py_eval` on 2026-06-07 reconfirmed the exact storage item as `0x0069b4c0-0x0069b4c4`, bytes `ff ff ff ff`, initial dword `0xffffffff`, and six xrefs: loader guard/write/read sites at `0x005042de`, `0x00504324`, `0x0050438b`, teardown read/clear sites at `0x0050463d` and `0x00504653`, and consumer read `0x0050557e`. The exact split memory page is [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md).

## Caveats

Working field names call the first byte `sourceNation`, the second byte `mappedNation`, and the length byte `attributeCount`. `StaticObjImageLib` names the same byte widths as palette/unused/name-length fields. The widths and reads are solid; the semantic names need validation against resource contents and map rules.

## Cross-References

- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents storage, related count global, `SOBJ.TBL` loader behavior, consumers, cleanup, source owner, and DAT semantic caveats; final names for record fields remain medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000L3][MapPane](by-file/MapPane.md). Evidence: live IDA MCP xrefs to `0x0069b4c0` show allocation and stores in `0x00504110`, cleanup in `0x00504530`, and consumer reads in `0x00505430`; decompilation confirms the loader reads `g_objectRecordCount`, allocates `count + 1`, seeds slot zero, and stores one byte per record.
- 2026-06-07 Batch 043 split-parent refresh:
  - Before: confidence `80`, below the corrected `85/85` gate for assigning an exact memory storage child.
  - After: confidence `86`; completion remains `86`.
  - Evidence: live IDA MCP reconfirmed exact four-byte storage bounds, initial value, loader allocation/write/read xrefs, teardown read/clear xrefs, and consumer read. DAT field semantic names remain caveated but no longer weaken the storage/ownership claim.
