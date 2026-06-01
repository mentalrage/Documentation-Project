*** UID:0000M6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ObjectStatusBlob

## Status

- Confidence: strong for parser ownership and shared data role.
- Proposed module: `map/ObjectStatusBlob.cpp` or a nearby object/protocol helper source.
- Current generated source: `source-3/simroot_v2/class_ObjectStatusBlob.cpp`
- Primary class doc: [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- Main address doc: [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)

## File Role

`ObjectStatusBlob.cpp` owns a shared 68-byte object appearance/status packet blob. Map packets, user-look/profile packets, and object-image/dialog preview code all parse or copy the same status layout, so this should not be owned by any one UI dialog or by old `MenuCommandRecord`-style projections.

The strongest current placement is a map/object protocol helper near [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000M5][ObjectPane](by-file/ObjectPane.md), and [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md). A later source-layout pass may move it to a broader `game/` or `protocol/` folder if more non-map callers dominate.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectStatusBlob` | `0x004d1f30-0x004d2697` | Shared parser for full, compact tagged, and partial object status data. |
| `ObjectStatusBlobFields` | 68-byte generated layout | Direction, posture, title, appearance, palette, equipment, profile, object-type, and effect/status bytes. |
| title metadata lookup helpers | inside `0x004d1fa0` body | Resolve title metadata values through `g_pMetaMan` and `kStatusTitleMetaTableName`. |

## Boundary Notes

- `ParseTaggedStatus` at `0x004d1f30` dispatches either full parsing or compact tagged appearance parsing.
- `ParseFullStatus` at `0x004d1fa0` consumes the full 43-byte packet payload and normalizes title, palette, profile, equipment, object-type, and status fields.
- `ParsePartialStatus` at `0x004d2640` consumes a 5-byte reduced status payload.
- Current generated source repeats local struct declarations across methods. Treat that as generated staging noise to normalize during migration, not proof of multiple original source files.

## Cross-References

- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `82`.
- Summary/evidence: the page clearly identifies parser ownership, shared data role, boundaries, metadata lookup tie-in, and cross-references; completion is lower because field-level layout detail remains summarized rather than exhaustively documented.
