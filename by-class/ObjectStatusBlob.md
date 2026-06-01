*** UID:00009S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectStatusBlob

## Status

- Confidence: strong for shared parser role.
- Likely source file: [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- Current recovered file: `source-3/simroot_v2/class_ObjectStatusBlob.cpp`

## Class Purpose

`ObjectStatusBlob` is a shared 68-byte object appearance/status packet parser. It is used by map entity updates, user-look/profile flows, and object image preview/dialog code. It should be treated as reusable object packet state, not as a menu-command or one-dialog helper.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ParseTaggedStatus` | `0x004d1f30-0x004d1f99` | Reads a leading mode byte, delegates to full parsing for mode `0`, or parses compact tagged appearance ids for modes `1` and `2`. |
| `ParseFullStatus` | `0x004d1fa0-0x004d2637` | Parses the full appearance/status payload, normalizes title metadata, palette remaps, profile values, equipment, object type, and status/effect bytes. |
| `ParsePartialStatus` | `0x004d2640-0x004d2697` | Parses reduced direction/posture/appearance data and marks the blob as compact status. |

## Layout Notes

- Generated `ObjectStatusBlobFields` is asserted to be 68 bytes.
- The full parser consumes 43 bytes; the partial parser consumes 5 bytes; tagged compact modes consume 4 bytes.
- Global dependencies include `g_displayMode`, `g_pAppearanceRemapTable`, `g_pMetaMan`, and `kStatusTitleMetaTableName`.

## Cross-References

- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite parser role, method ranges, layout-size notes, and subsystem references.
- Changed to: `COMPLETION:72` and `CONFIDENCE:80`.
- Evidence: the page documents the three parser modes, consumed byte counts, 68-byte field blob, global dependencies, and shared use across map/look/object-image code; remaining gaps are exact field-by-field naming and raw parser data-flow detail.
