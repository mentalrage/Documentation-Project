*** UID:0004R0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MapPoint
{
    int row;
    int column;
};

typedef char MapPointSizeMustBe8[
    sizeof(MapPoint) == 8 ? 1 : -1];
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact eight-byte shared map coordinate value type with row/Y at +0, column/X at +4, MapPane.cpp ownership, synchronized UserPane/ObjectPane consumers, and no invented x/y compatibility union. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MapPoint

## UID0003ZT Complete Declaration Placement - 2026-07-23

- The exact source declaration remains `struct MapPoint { int row; int column; };`, eight bytes with row first and column second, owned/emitted through [UID:0000L3][MapPane](by-file/MapPane.md) at position `5`.
- Highest-probability human source placement is directly in `NexusTK/map/MapPane.h` before the complete MapPane declaration. A forward declaration is insufficient because MapPane methods instantiate MapPoint locals and expose it through signatures.
- MapPane.cpp and other consumers include MapPane.h rather than duplicating the struct or introducing x/y aliases. The declaration order ensures MapPoint is complete before all six coordinated MapPane definitions.
- This placement preserves `92/93`, every existing consumer and row/column semantic proof, and the exact managed formal; no ownership or emitter change is introduced.

## Status

- Source identity: shared `MapPoint` value type emitted through [UID:0000L3][MapPane](by-file/MapPane.md) in `NexusTK/map/MapPane.cpp` source order at position 5.
- Metadata: `92/93`, canonical owner/emitter UID0000L3, reconstructable true, position 5, `Nested:0`.
- Exact layout: `sizeof(MapPoint) == 8`; signed `int row` occupies `+0`, signed `int column` occupies `+4`.

## Layout And Semantics

- The first dword is map row/Y and the second dword is map column/X. ObjectPane map-position access writes `m_mapY` then `m_mapX`; UserPane viewport access writes `m_viewportRow` then `m_viewportColumn`; direction offsets use the same row/column ordering.
- `DirectionToTileOffset` maps direction 0 to row `-1`, column `0`; direction 1 to row `0`, column `1`; direction 2 to row `1`, column `0`; direction 3 to row `0`, column `-1`; all other values produce zero/zero.
- The structure is a plain source-era two-int value type. Its formal size guard makes the binary contract explicit without compiler pragmas, packing directives, inheritance, constructors, accessors, or STL substitution.

## Consumers And Source Route

- [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md) produces direction offsets and has 32 direct cross-source callers, supporting external MapPane.cpp declaration ownership.
- [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md) writes map row then column and returns the supplied output pointer.
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) selects an ObjectList effect bucket by `mapRow`, obtains each candidate pane's `MapPoint`, and compares only `position.column` with `mapColumn`; the selected bucket already constrains the row. Its null-target create fallback forwards `mapRow` then `mapColumn`, independently confirming the same row/column order.
- [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md) writes viewport row then column and returns the supplied output pointer.
- [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md) consumes both position and direction-offset forms in the live movement path.

## Evidence And Negative Findings

- Direct leaf stores and movement callers converge on the same eight-byte ABI. No consumer requires a third field, packing gap, pointer member, constructor, vtable, or ownership behavior.
- Historical `x/y` spellings describe the same physical values but conflict with the established map row/column contract. They are preserved only as search history; no anonymous union or duplicate aliases are emitted.
- `MapPoint` is not owned by UserPane, ObjectPane, LivingObjectPane, PacketBuffer, or a new standalone source file. Those modules consume the shared MapPane coordinate declaration.
- Exact original header factoring remains uncertain and caps confidence below 95, but it does not block a source-legal declaration or any accepted consumer body.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md)
- [UID:0003XP][0x005374d0-0x005374eb.ObjectPaneGetMapPosition](by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md)
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0002RW][0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition](by-memory/0x005a2de0-0x005a2dfb.UserPaneGetViewportPosition.md)
- [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md)

## Changes

- 2026-07-15 Agent-B005 UID0003TE callback: added the row-bucket/column-comparison and row-before-column create consumer while preserving the exact two-int declaration, size guard, MapPane ownership, and `92/93` metadata.
- 2026-07-15 B001 UID0003U6 callback: created as the exact shared row/column source declaration, with position 5, complete managed C++, consumer evidence, and no fabricated UID or compatibility union.
