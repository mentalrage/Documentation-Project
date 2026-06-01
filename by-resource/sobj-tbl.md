*** UID:0001RL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SOBJ.TBL

## Status

- Confidence: strong for loader addresses and field widths, medium for final field names.
- Resource family: DAT entry / wide filename `SOBJ.TBL`.
- IDA string evidence: UTF-16 string at `0x0061c1a4`.
- Primary consumers: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) and [UID:0000L3][MapPane](by-file/MapPane.md) initialization through [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).

## Role

`SOBJ.TBL` is the static-object table resource. It is used in two related but distinct ways:

- `StaticObjImageLib` loads the full static-object image metadata table during startup.
- `MapPane` initialization reads [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) and builds [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), a compact byte map used by gameplay/map checks.

These are not two separate resources. They are two parser views over the same binary table.

## Observed Record Shape

Both consumers agree on the outer widths:

| Offset | Size | StaticObjImageLib view | MapPane/GameServerConfig view |
| --- | --- | --- | --- |
| file `+0x00` | `0x04` | `staticObjCount` | `g_objectRecordCount` |
| file `+0x04` | `0x02` | table/header word | table/header word |
| record `+0x00` | `0x04` | object id/address | object record address |
| record `+0x04` | `0x01` | palette group | source nation/class byte |
| record `+0x05` | `0x01` | unused/class byte | mapped nation/class byte |
| record `+0x06` | `0x01` | layer/tile-id count | skipped word count |
| record `+0x07` | `count * 2` | `uint16` tile ids | skipped word payload |

The exact semantic names are still provisional. The byte widths and read order are directly visible in IDA decompilation. IDA render evidence at `0x004dd2c0` proves the `StaticObjImageLib` view uses the third byte as a layer/tile-id count rather than a wide-name length.

## IDA MCP Evidence

- UTF-16 `SOBJ.TBL` was verified at `0x0061c1a4`.
- Xrefs to the literal occur at `0x004dcfce` in `0x004dcf60-0x004dd1d8`, `0x004dde4c` in `0x004dde10-0x004ddf5e`, and `0x005042eb` in `0x00504110-0x00504521`.
- Decompilation at `0x004dde10` opens `SOBJ.TBL`, reads a four-byte count into class storage, then reads a two-byte header before iterating records that contain a four-byte object id, one-byte fields, and a counted word payload.
- Decompilation at `0x00504110` confirms the map/game-server classification path opens the same table and builds the compact object/nation byte map rather than owning the full render metadata.

## Static Object Loader

`StaticObjImageLib::StaticObjImageLib` at `0x004dcf60`:

- opens `SOBJ.TBL`;
- reads count and header;
- allocates a pointer table of static-object entries;
- reads each object id, palette/group byte, secondary byte, and layer/tile-id count;
- allocates a per-object record and reads `layerCount * 2` bytes of `uint16` tile ids into the entry.

This loader owns static-object render metadata and should stay with `render/StaticObjImageLib.cpp`.

## Map Classification Loader

`GameServerConfig::InitializeMapPane` at `0x00504110`:

- opens `SOBJ.TBL` only if `g_objectNationMap` is null;
- reads the same count/header;
- allocates `g_objectRecordCount + 1` bytes;
- sets slot zero to zero;
- reads table records and stores the second one-byte field into `g_objectNationMap[index]`;
- closes the DAT file before registering and finishing map-pane setup.

This is a compact map/gameplay cache, not ownership of the full static-object resource.

## Caveats

The `MapPane` loader loop starts at index `1`, while `StaticObjImageLib` iterates records from index `0`. This may indicate a sentinel slot, a generated-code off-by-one naming artifact, or a resource convention where record zero is special. Verify against actual DAT contents before locking the final table schema.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- What existed before: the page was scored unevaluated and mixed generated-source wording with IDA observations.
- Changed to: scored `COMPLETION:78` / `CONFIDENCE:88`, removed generated-source dependency from the record-shape statement, and added direct IDA MCP evidence.
- Summary and evidence: `SOBJ.TBL` string/xrefs and loader decompilation now support the two-consumer interpretation; score remains below final because field names and sentinel/record-zero semantics are still provisional.
