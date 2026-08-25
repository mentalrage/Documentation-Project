*** UID:0001RL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SOBJ.TBL

## Status

- Confidence: very strong for loader addresses, consumer split, field widths, current `tile.dat` payload provenance, leading sentinel/reserved-record evidence, and source-facing descriptive render-field names; medium for original field spellings and the header word's exact meaning.
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
| record `+0x00` | `0x04` | `lightIntensity` / signed light metadata | object record address / id-like field |
| record `+0x04` | `0x01` | `lightHeightClass` | source nation/class byte |
| record `+0x05` | `0x01` | discarded/classification byte in the full render loader | mapped nation/class byte |
| record `+0x06` | `0x01` | `layerCount` / tile-id count | skipped word count |
| record `+0x07` | `count * 2` | `uint16 tileIds[layerCount]` | skipped word payload |

The source-facing render names are descriptive rather than proven original identifiers. The byte widths and read order are directly visible in IDA decompilation. IDA render evidence at `0x004dd2c0` proves the `StaticObjImageLib` view uses the third byte as a layer/tile-id count rather than a wide-name length.

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data`. The current package contains one `SOBJ.TBL` payload and no loose duplicate was found in the audited tree.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `SOBJ.TBL` | `tile.dat`, entry index `0`, offset `106`, size `276,147` bytes. | First bytes decode as count `19,551` (`0x00004c5f`) followed by a two-byte header/version word `0x0001`; the first record begins with `0xffffffff` sentinel-style bytes and counted word payload data, matching the two-parser record-width model. |

2026-06-16 A002 reran the package scan with a table-only parser across all current `.dat` archives and reconfirmed that `tile.dat` entry index `0` is the only exact `SOBJ.TBL` DAT entry. A loose exact-name search under `E:\2026\Resources` found no standalone duplicate.

## Payload Inspection

2026-06-16 A002 parsed the complete `tile.dat` payload using the observed variable-width record model. The parse consumed all `276,147` payload bytes and produced exactly `19,551` records, matching the file count. The first `485` records have object id `0xffffffff`; the first non-`0xffffffff` record is at table index `485`, payload offset `7,805`, object id `0x00000009`, field bytes `0` and `15`, and word count `2`. The observed word-count range across the table is `0..12`.

This resolves the prior "record zero" ambiguity far enough for rebuild documentation: record zero is part of a leading reserved/sentinel block, and the map-classification loader's slot-zero seed is consistent with a reserved index convention. It does not prove the source-facing names for the two one-byte classification fields or the exact meaning of the `0x0001` header word.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms UTF-16 `SOBJ.TBL` at `0x0061c1a4` with three observed code xrefs.
- Xrefs to the literal occur at `0x004dcfce` in `sub_4DCF60` (`0x004dcf60`, size `0x278`), `0x004dde4c` in `sub_4DDE10` (`0x004dde10`, size `0x14e`), and `0x005042eb` in `sub_504110` (`0x00504110`, size `0x411`).
- Decompilation at `0x004dde10` opens `SOBJ.TBL`, reads a four-byte count into class storage, then reads a two-byte header before iterating records that contain a four-byte signed light/id-like field, one-byte fields, and a counted word payload.
- Decompilation at `0x00504110` confirms the map/game-server classification path opens the same table and builds the compact object/nation byte map rather than owning the full render metadata.
- 2026-06-16 A002 live MCP refresh on database `b001_selflookpane_0001H7_20260616` reconfirmed `sub_4DCF60` size `0x278`, `sub_4DDE10` size `0x14e`, `MapPaneInitialize` size `0x411`, and the same three `SOBJ.TBL` xrefs. Decompilation still shows the `StaticObjImageLib` constructors reading the signed light/id-like field, two one-byte fields, count byte, and counted `uint16` payloads, while `MapPaneInitialize` seeds `g_objectNationMap[0]` and stores the second one-byte field for loop indexes starting at `1`.

## Static Object Loader

`StaticObjImageLib::StaticObjImageLib` at `0x004dcf60`:

- opens `SOBJ.TBL`;
- reads count and header;
- allocates a pointer table of static-object entries;
- reads each signed light metadata dword, light-height byte, secondary/classification byte, and layer/tile-id count;
- allocates a per-object record and reads `layerCount * 2` bytes of `uint16` tile ids into the entry.

This loader owns static-object render metadata and should stay with `render/StaticObjImageLib.cpp`. B007 ties these fields to [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) as `lightIntensity`, `lightHeightClass`, `layerCount`, and `tileIds`; the second byte is consumed by the compact map/classification parser but is not preserved in the in-memory render record.

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

The `MapPane` loader loop starts at index `1`, while `StaticObjImageLib` iterates records from index `0`. The current `tile.dat` payload confirms record zero is not an ordinary object row: it belongs to a leading block of `485` `0xffffffff` records before the first non-sentinel object id. Keep the final field names conservative because the source meaning of the two one-byte fields, the full role of the sentinel block, and the two-byte header word are still not proven by this parse alone.

## Rebuild Packaging Boundary

- Package `SOBJ.TBL` as one static-object table resource shared by render metadata and map/gameplay classification startup.
- Keep the full static-object image metadata loader with [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), including `lightIntensity`, `lightHeightClass`, the secondary class/nation byte, `layerCount`, and counted `uint16` tile-id payloads.
- Keep the compact `g_objectNationMap` materialization with [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) / [UID:0000L3][MapPane](by-file/MapPane.md); this path consumes one byte from each record and should not become the table's sole schema owner.
- Do not split `SOBJ.TBL` into separate render and map resources unless DAT payload inspection later proves there are multiple files with identical names in different archives.

## Open Questions

- What is the exact source/resource meaning of the leading `485` `0xffffffff` records: reserved tile/object classes, sentinel rows, or layout padding encoded as normal records?
- What are the final source names for the two one-byte classification fields at record `+0x04` and `+0x05`?
- Is the two-byte file header after the count a version, flags word, or reserved field?
- Whether the same `tile.dat` `SOBJ.TBL` payload is used for both render and map classification in all package layouts.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | The page now documents the `SOBJ.TBL` identity, the two-parser consumer model, observed record widths, loader addresses, refreshed xref/function evidence, rebuild packaging boundary, global map-cache links, current `tile.dat` package entry, table count/header evidence, full-payload parse coverage, leading sentinel/reserved-record evidence, word-count range, and remaining field-name/header questions. |
| Confidence `93` | Fresh 2026-06-16 IDA xrefs reconfirm the three consumer functions, and direct package parsing confirms the current `tile.dat` payload, count, header word, exact byte-consumption, and leading `0xffffffff` record block. Confidence remains below final because exact one-byte field names, the sentinel block's source/resource meaning, and the two-byte header meaning are unresolved. |

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- What existed before: the page was scored unevaluated and mixed generated-source wording with IDA observations.
- Changed to: scored `COMPLETION:78` / `CONFIDENCE:88`, removed generated-source dependency from the record-shape statement, and added direct IDA MCP evidence.
- Summary and evidence: `SOBJ.TBL` string/xrefs and loader decompilation now support the two-consumer interpretation; score remains below final because field names and sentinel/record-zero semantics are still provisional.
- 2026-06-14 A003 score refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, with live IDA MCP xrefs reconfirming all three literal consumers and function sizes, plus rebuild packaging boundary, open questions, and score rationale.
  - Summary/evidence: the refreshed xrefs keep `StaticObjImageLib` as the full render-metadata consumer and `GameServerConfig` / `MapPane` as the compact classification-map consumer of the same table; field names, record-zero behavior, header meaning, and DAT provenance remain below-final blockers.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:89`, with IDA consumer evidence but unresolved package provenance.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:91`, with the current `tile.dat` `SOBJ.TBL` entry, payload offset/size, count `19,551`, and header word `0x0001`.
  - Evidence: fixed-table DAT parsing of `tile.dat` under `E:\2026\Resources\Read_Only\NexusTK\Data`.
- 2026-06-16 A002 payload inspection:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`, with record-zero semantics still open.
  - After: raised to `COMPLETION:90`, `CONFIDENCE:93`.
  - Evidence: table-only package scan reconfirmed `tile.dat` as the sole exact `SOBJ.TBL` DAT entry; direct payload parsing consumed all `276,147` bytes into `19,551` records, found `485` leading `0xffffffff` records, found the first non-sentinel object at index `485`, and observed word counts from `0` through `12`. Live MCP on `b001_selflookpane_0001H7_20260616` reconfirmed the three string xrefs and parser function sizes.
- 2026-06-21 B007 Rule 26 incorporation:
  - Scores unchanged at `90/93`.
  - Evidence: updated the `StaticObjImageLib` render view names to `lightIntensity`, `lightHeightClass`, discarded/classification byte, `layerCount`, and `tileIds`; kept the two-parser model and noted that these names are source-facing descriptive names rather than proven original resource labels.
