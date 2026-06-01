*** UID:0000Q1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_gameServerNationTable

## Status

- Confidence: strong for storage address and lifecycle, medium for final type name.
- Current Wave3 kind: `global-data`.
- IDA storage: `0x0069b4c4` (`dword_69B4C4`).
- Proposed owner: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) under `map/`, or private [UID:0000L3][MapPane](by-file/MapPane.md) helper state if the table is folded into `MapPane.cpp`.

## Role

`g_gameServerNationTable` is the process-wide pointer to the map/game-server nation-entry table. It backs 68-byte [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) records used by user/status/map presentation code.

Likely declaration during reconstruction:

```cpp
static GameServerConfig* g_gameServerNationTable;
```

If later class cleanup splits the table from the map-pane initializer, prefer a narrower name such as `GameServerNationTable*`.

## Lifecycle

- `0x005039f0-0x00503a41` initializes the table object, installs the `GameServerConfig` and `ProtectedArray<GameServerConfig::NationEntry>` vtables, seeds capacity/count fields, and stores this global.
- `0x00504110-0x00504521` allocates an 88-byte table object during map-pane initialization and stores it in this global.
- `0x00503a50-0x00503a78` is destructor-like code in the local constructor block that frees table data and clears the global, but IDA does not currently model it as a separate function.
- `0x00514d80-0x00514ddc` frees the table data and writes zero to `dword_69B4C4`.
- `0x00504530-0x005046c6` tears down `MapPane` state and calls the table object's virtual destructor when this global is non-null.

## Access Patterns

- `0x00503a80` copies a matching nation entry or returns the fallback `L"????"` record.
- `0x00503c70` sends the fixed opcode `0x66` / subcode `0x4000` request packet when the table is empty.
- IDA xrefs also show readers in the `MapPane` packet path and in the user-list/status UI neighborhood, including `0x00507c90` and `0x0059bc90` range functions.
- 2026-05-25 IDA recheck reports concrete xrefs at `0x00503a0d`, `0x00503a6b`, `0x00504467`, `0x0050446e`, `0x00504668`, `0x00507cf6`, `0x00514d9e`, multiple `0x0059bc90` sites, `0x005a5010`, `0x005a5bd0`, `0x005b8c70`, and `0x005be520`.

## Caveats

The generated name `GameServerConfig` is misleading if read as general configuration. The global is map/gameplay nation state. Keep it out of `config/` unless later evidence proves a broader server-config module existed.

## Cross-References

- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents storage, role, lifecycle, allocation/destruction, access patterns, IDA xrefs, caveats, and owner/type refs, with final type name still medium-confidence.
