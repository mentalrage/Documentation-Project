*** UID:0000RG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapTileImageLib *g_pMapTileImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMapTileImageLib

## Status

- Confidence: very strong for address, type, owner, all ten direct refs, direct Singleton base publication/clear cause, storage/definition split, and representative consumers; exact original symbol spelling remains inferred.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md), IDA `dword_67A75C`.
- Canonical owner: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) in [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Live IDA evidence confirms `dword_67A75C` as process-wide singleton storage with ten direct refs: compiler-lowered direct Singleton construction/destruction, shutdown read, and map/photo consumer reads.
- B011's 2026-07-01 accepted callback inserts the single source definition here. The exact backing-storage page [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md) is storage evidence and must not duplicate the global definition.

## Meaning

`g_pMapTileImageLib` is the global pointer to the terrain tile image library. Map rendering, photo composition, and helper/fallback paths read this pointer before drawing map terrain tiles through `MapTileImageLib::DrawTile`.

Keep this global with `render/MapTileImageLib.cpp`. Consumers should not adopt it just because they draw map tiles.

## Write Evidence

IDA MCP on 2026-06-14 reports 10 xrefs to `0x0067a75c`. Write/clear sites include:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004d18a3` | `MapTileImageLib::MapTileImageLib` | Compiler-lowered direct `Singleton<MapTileImageLib>` base publication. |
| `0x004d18aa` | `MapTileImageLib::MapTileImageLib` | Compiler-lowered adjusted-base fallback clear. |
| `0x004d19f9` | [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) | Implicit direct Singleton base destruction after the authored derived cleanup. |
| `0x004e5bc0` | [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonBaseDestructor.md) | EH-only compiler-instantiated direct-base destructor reached from constructor state 1. |
| `0x004e6700` | `MapTileImageLib::ScalarDeletingDestructor` | Implicit direct Singleton base destruction expanded inside the scalar wrapper. |
| `0x004f6622` | `Application` shutdown path | Reads/destroys the singleton through the image-library shutdown sequence. |

The constructor stores either `this` or zero into `dword_67A75C`, installs the `MapTileImageLib` vtable, opens `TILE.EPF`, loads `TILE.TBL`, validates the tile count, and allocates one 4-byte record per tile. Current direct-base analysis classifies the publication/fallback stores as `Singleton<MapTileImageLib>` base construction, not handwritten constructor statements. Likewise, the ordinary and scalar clears are implicit direct-base destruction after the derived cleanup, not handwritten destructor statements.

Original RTTI records `Singleton<MapTileImageLib>` as a direct empty base at PMD `+4/-1/0`. Constructor FuncInfo state 1 reaches UID000180 through adjusted `this+4` tail-jump `0x005ff9bb`. These independent type/control-flow facts explain all four zero-store sequences while preserving this page as the sole typed source definition and UID0001OU as covered storage only.

## Consumer Evidence

Representative readers include:

- `0x004243d0`, a photo/map composition helper that calls `MapTileImageLib::DrawTile`.
- `0x0050d8e0`, [UID:0000L3][MapPane](by-file/MapPane.md) cached tile rendering.
- `0x00549620`, [UID:0000MK][PhotoPane](by-file/PhotoPane.md) map-photo composition.
- `Application` shutdown reads/destroys this singleton as part of the image-library shutdown sequence; it is a lifetime consumer, not the source owner.

The exact 2026-06-14 xref set is `0x00424431`, `0x004d18a3`, `0x004d18aa`, `0x004d19f9`, `0x004e5bc0`, `0x004e6700`, `0x004f6622`, `0x0050c3cb`, `0x0050d978`, and `0x0054976f`. No direct xrefs from another source family write the singleton, so consumer modules should not own or redeclare it.

## Ownership Decision

`g_pMapTileImageLib` is source-owned by `MapTileImageLib`, not by `Application`, `MapPane`, `PhotoPane`, or any renderer that only consumes terrain tiles.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | Exact storage, all ten refs, direct Singleton publication/fallback/EH/ordinary/scalar lifetime, shutdown/map/photo consumers, one-definition route, and accepted formal global definition are documented. |
| Confidence | 94 | Live xrefs plus direct RTTI PMD and constructor-EH adjusted receiver prove the lifetime cause; only exact original global spelling remains inferred. |
| Parent | [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) | This page remains the sole nonblank typed global definition emitted in `auto-generated/NexusTK/render/MapTileImageLib.cpp`; no constructor/destructor/support page duplicates it. |

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md)
- [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- 2026-07-14 B002 UID000180 implementation callback:
  - Raised `88/90` to `91/94`; retained the sole formal definition and file owner/emitter.
  - Reclassified constructor publication/fallback, UID000180 EH clear, ordinary clear, and scalar clear as direct `Singleton<MapTileImageLib>` base lifetime lowering using exact RTTI PMD, FuncInfo, adjusted-receiver, and ten-ref evidence. Preserved consumers, storage split, and original-name confidence cap.
- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `87/88` to `88/90` and inserted the accepted formal global definition `MapTileImageLib *g_pMapTileImageLib = 0;`.
  - Preserved this by-global page as the declaration/definition owner and documented that [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md) is exact backing storage evidence, not a duplicate definition route.
- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0` despite the page already containing strong storage, owner, write/clear, and consumer documentation.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`, plus an explicit shutdown-consumer note.
  - Summary/evidence: exact storage page [UID:0001OU][0x0067a75c-0x0067a760.g_pMapTileImageLib](by-memory/0x0067a75c-0x0067a760.g_pMapTileImageLib.md), owner file/class docs, MapTileImageLib aggregate memory docs, and documented write/clear/read sites support the score. Confidence remains capped because `g_pMapTileImageLib` is still a working source name rather than an original symbol recovered from PDB/source.
- 2026-06-05: Marked reconstructable under [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md). Evidence: live IDA MCP reports 10 xrefs to `0x0067a75c`; decompilation confirms constructor `0x004d1860`, destructor `0x004d19a0`, clear helper `0x004e5bc0`, and scalar deleting destructor `0x004e66a0` write/clear `dword_67A75C`.
- 2026-06-14 A003 score refresh:
  - Before: `86/84`; the target page lagged behind the exact memory page and current direct-xref evidence.
  - Changed to: `87/88`, retaining [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked the full 10-xref set, constructor `0x004d1860`, ordinary destructor `0x004d19a0`, scalar deleting destructor `0x004e66a0`, clear helper `0x004e5bc0`, and map/photo/shutdown consumers. The remaining open issue is only final original symbol spelling, not address, type, lifecycle, or source ownership.
