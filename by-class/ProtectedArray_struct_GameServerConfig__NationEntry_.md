*** UID:0000B4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProtectedArray_struct_GameServerConfig__NationEntry_

## Status

- Confidence: strong for helper behavior, medium for final type spelling.
- Proposed file: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- Current generated file: `class_ProtectedArray_struct_GameServerConfig__NationEntry_.cpp`
- Current range: `0x00514d50-0x00514d7e`
- Evidence basis: Wave3 class inspection, generated source, and IDA MCP boundary verification.

## Responsibility

This is the protected-array backing container for `GameServerConfig::NationEntry` records. The only current method resets the protected-array vtable, frees the backing entry buffer, and conditionally deletes the container object.

The element layout is tracked separately as [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md): a 68-byte record with a 16-bit nation id followed by a 33-wide-character label.

## Method

| Address | Method | Role |
| --- | --- | --- |
| `0x00514d50` | `ScalarDeletingDestructor(unsigned char deleteFlag)` | Frees `m_entries` and conditionally deletes the protected-array object. |
| [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | resize/reserve helper | Allocates/copies 68-byte nation-entry records and initializes new slots. |

## Ownership Notes

- This should migrate with `map/GameServerConfig.cpp` or remain a private helper near `MapPane` if the nation table is folded into `MapPane.cpp`.
- The exact generated class name is a Wave3 spelling artifact. Prefer a source-level name such as `ProtectedArray<GameServerConfig::NationEntry>` in reconstructed code.
- The reusable template behavior is tracked in [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md); this page remains map-owned because the concrete nation-entry table belongs to `GameServerConfig`.

## Cross-References

- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `74/76`.
  - Before: The page was unevaluated despite documenting the protected-array role, nation-entry layout reference, destructor, resize helper, and ownership caveats.
  - After: Scored as moderate-high completion with medium-high confidence because the final source-level type spelling remains less certain than the helper behavior.
  - Evidence: Existing status, responsibility, method table, ownership notes, and GameServerConfig/global/memory cross-references cover the container role and remaining uncertainty.
