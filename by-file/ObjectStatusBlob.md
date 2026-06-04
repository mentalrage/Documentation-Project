*** UID:0000M6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ObjectStatusBlob

## Status

- Confidence: strong for parser ownership, shared data role, exact parser boundaries, and map/object placement; medium for final source-level field names.
- Proposed module: `map/ObjectStatusBlob.cpp`.
- Primary class doc: [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- Main address doc: [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)

## File Role

`ObjectStatusBlob.cpp` owns a shared 68-byte object appearance/status packet blob. Map packets, user-look/profile packets, and object-image/dialog preview code all parse or copy the same status layout, so this should not be owned by any one UI dialog or by old `MenuCommandRecord`-style projections.

The strongest current placement is a map/object protocol helper near [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000M5][ObjectPane](by-file/ObjectPane.md), and [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md). Non-map callers still use the same blob as a shared object appearance/status packet structure, but the owning packet families are map/object-centered.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `ObjectStatusBlob` class | [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) | Shared parser owner for full, compact tagged, and partial object status data. |
| `ObjectStatusBlobFields` | 68-byte layout | Direction, posture, title, appearance, palette, equipment, profile, object-type, and effect/status bytes. |
| `ParseTaggedStatus` | `0x004d1f30-0x004d1f99` | Reads a leading mode byte, delegates full mode, or parses compact tagged appearance ids. |
| `ParseFullStatus` | `0x004d1fa0-0x004d2637` | Consumes the 43-byte full payload and writes the field run from `+0` through `+64`. |
| `ParsePartialStatus` | `0x004d2640-0x004d2697` | Consumes the 5-byte reduced payload and writes mode/default state plus compact direction/posture/appearance fields. |
| title metadata lookup helpers | inside `0x004d1fa0` body | Resolve title metadata values through `g_pMetaMan` and `kStatusTitleMetaTableName`. |

## Boundary Notes

- `ParseTaggedStatus` at `0x004d1f30` dispatches either full parsing or compact tagged appearance parsing.
- `ParseFullStatus` at `0x004d1fa0` consumes the full 43-byte packet payload and normalizes title, palette, profile, equipment, object-type, and status fields.
- `ParsePartialStatus` at `0x004d2640` consumes a 5-byte reduced status payload.
- The decompiler repeats local struct-shaped expressions across methods. Treat that as a single blob layout to normalize during migration, not proof of multiple original source files.
- Keep C++ blank until the layout member names and trailing 68-byte tail fields are source-quality.

## Live IDA Evidence

- IDA MCP on 2026-06-05 confirms the three normal function starts and sizes: `0x004d1f30` size `0x69`, `0x004d1fa0` size `0x697`, and `0x004d2640` size `0x57`.
- Direct xrefs cover map/object updates (`0x0050fb00`, `0x00513310`), object-image/profile preview paths (`0x005693d0`, `0x00572120`), user-look flow (`0x0059f610`), and several object dialog/image handlers that call the tagged parser.
- Callee checks show the compact/partial parsers only need byte/word readers, while the full parser adds string helpers, metadata lookup at `0x00523120`, `dword_69B410`, `byte_66DA97`, and `dword_67A760`.
- Raw-byte checks keep the span split precise: `0x004d1f99-0x004d1fa0` and `0x004d2637-0x004d2640` are alignment padding between parser bodies.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now has a valid proposed path, exact parser ownership, method boundaries, byte counts, field-layout responsibilities, global dependencies, caller families, and clear file-boundary notes. Completion remains capped by unresolved final member names and the possibility that a future source-layout pass moves it to a broader protocol folder. |
| Confidence `88` | Confidence is supported by current live IDA function enumeration, decompilation, xrefs, callees, globals, and padding checks. It stays below the class/memory confidence because final source grouping outside the map folder is still a minor open question. |

## Cross-References

- [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)

## Changes

- 2026-06-05: Raised completion/confidence from `78/82` to `86/88` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/map/`. Evidence: live IDA MCP confirmed parser boundaries, byte counts, caller families dominated by map/object appearance flows, field-offset writes, metadata/remap globals, and internal padding. The path is strong enough for validator parent assignment, but member names and potential broader protocol placement keep it below final reconstruction confidence.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `82`.
- Summary/evidence: the page clearly identifies parser ownership, shared data role, boundaries, metadata lookup tie-in, and cross-references; completion is lower because field-level layout detail remains summarized rather than exhaustively documented.
