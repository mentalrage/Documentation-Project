*** UID:0000RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMapTileImageLib

## Status

- Confidence: strong for address, type, owner, write/clear sites, and representative consumers; medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md), IDA `dword_67A75C`.
- Canonical owner: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) in [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Wave3 status: `g_pMapTileImageLib` now owns reviewed storage `0x0067a75c-0x0067a75f` in `class_MapTileImageLib.cpp`, has type `MapTileImageLib*`, and the address-form `0x0067a75c` row resolves to this canonical global-data record.
- Current `simroot_v2/class_MapTileImageLib.cpp.source_map.json` records `global-data:g_pMapTileImageLib` with owner file `class_MapTileImageLib.cpp` and notes that IDA confirms `dword_67A75C` as process-wide singleton storage written by the constructor, cleared by destructors/helpers, and read by consumers.

## Meaning

`g_pMapTileImageLib` is the global pointer to the terrain tile image library. Map rendering, photo composition, and helper/fallback paths read this pointer before drawing map terrain tiles through `MapTileImageLib::DrawTile`.

Keep this global with `render/MapTileImageLib.cpp`. Consumers should not adopt it just because they draw map tiles.

## Write Evidence

IDA MCP on 2026-05-26 reports 10 xrefs to `0x0067a75c`. Write/clear sites include:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004d18a3` | `MapTileImageLib::MapTileImageLib` | Stores the constructed `MapTileImageLib*` singleton. |
| `0x004d18aa` | `MapTileImageLib::MapTileImageLib` | Constructor fallback/guard path clears the singleton. |
| `0x004d19f9` | [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004e5bc0` | [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md) | Tiny cleanup helper that only clears this global. |
| `0x004e6700` | `MapTileImageLib::ScalarDeletingDestructor` | Clears the singleton during deleting destruction. |
| `0x004f6622` | `Application` shutdown path | Reads/destroys the singleton through the image-library shutdown sequence. |

## Consumer Evidence

Representative readers include:

- `0x004243d0`, a photo/map composition helper that calls `MapTileImageLib::DrawTile`.
- `0x0050d8e0`, [UID:0000L3][MapPane](by-file/MapPane.md) cached tile rendering.
- `0x00549620`, [UID:0000MK][PhotoPane](by-file/PhotoPane.md) map-photo composition.
- `Application` shutdown reads/destroys this singleton as part of the image-library shutdown sequence; it is a lifetime consumer, not the source owner.

## Ownership Decision

`g_pMapTileImageLib` is source-owned by `MapTileImageLib`, not by `Application`, `MapPane`, `PhotoPane`, or any renderer that only consumes terrain tiles.

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0` despite the page already containing strong storage, owner, write/clear, and consumer documentation.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`, plus current `simroot_v2` source-map evidence and an explicit shutdown-consumer note.
  - Summary/evidence: exact storage page [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md), owner file/class docs, MapTileImageLib aggregate memory docs, source-map `global-data:g_pMapTileImageLib`, and documented write/clear/read sites support the score. Confidence remains capped because `g_pMapTileImageLib` is still a working source name rather than an original symbol recovered from PDB/source.
