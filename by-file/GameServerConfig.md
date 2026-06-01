*** UID:0000JP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# GameServerConfig

## Status

- Confidence: medium for class name, strong for map/nation-table ownership.
- Proposed module folder: `map/`
- Candidate file: `map/GameServerConfig.cpp` or private helper code in `map/MapPane.cpp`
- Current generated sources: `class_GameServerConfig.cpp`, `class_ProtectedArray_struct_GameServerConfig__NationEntry_.cpp`
- Evidence basis: Wave3 class inspection, generated source, older Wave2 report notes, and IDA MCP checks on 2026-05-23.
- Related durable symbols: [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md), [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md), [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), and [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md).

## Hypothesis

Despite the name, this is not part of the general `config/` registry/settings module. The useful behavior is a map/gameplay nation-entry table used by status/user panes and map initialization. It should live near `MapPane`, likely under `map/`, because the largest active method constructs map-pane state, loads `SOBJ.TBL`, registers the pane, and allocates the nation-entry table.

Preferred conservative layout:

```text
map/MapPane.cpp
map/GameServerConfig.cpp
```

If later cleanup proves the nation-entry table was only a private `MapPane` helper, fold it into `MapPane.cpp`.

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| raw nation request packet helper | `0x00503960-0x005039ed` | not currently emitted as a modeled function | Retained/raw packet helper that sends the same fixed nation-entry request payload as `RequestNationEntries`, but current IDA has no xrefs to the start. |
| `GameServerConfig::InitializeNationEntryTable` | [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md) | `class_GameServerConfig.cpp` | Nation-entry table constructor; IDA has code here but no function record. |
| raw `GameServerConfig` non-deleting cleanup | [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md) | IDA raw code | Frees backing data, clears the global table pointer, and tail-jumps to base cleanup. |
| `GameServerConfig::CopyNationEntryOrFallback` | [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md) | Wave3 method metadata, not emitted in current class file | Copies a 68-byte nation entry or returns fallback label `L"????"`. |
| raw default nation-entry seeder | [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) | IDA raw code | Allocates/seeds two 68-byte default records using localized string-table ids `0x9f` and `0xa0`; no caller xrefs yet. |
| `GameServerConfig::RequestNationEntries` | [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md) | Wave3 method metadata, not emitted in current class file | Queues the fixed opcode `0x66` nation-entry request packet if the table is not populated. |
| `GameServerConfig` nation-entry parser/resize support | [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | IDA MCP | Parses packet-provided nation entries and resizes the 68-byte nation-entry backing array. |
| `GameServerConfig::InitializeMapPane` | [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) | `class_GameServerConfig.cpp` | Map-pane initializer currently attributed to `GameServerConfig`; likely belongs in `map/MapPane.cpp`. |
| `ProtectedArray<GameServerConfig::NationEntry>` deleting destructor | `0x00514d50-0x00514d7e` | `class_ProtectedArray_struct_GameServerConfig__NationEntry_.cpp` | Frees the nation-entry array backing storage. |
| `GameServerConfig::ScalarDeletingDestructor` | `0x00514d80-0x00514ddb` | `class_GameServerConfig.cpp` | Frees nation-entry backing data and clears the global table pointer. |

## IDA MCP Evidence

- IDA does not currently model `0x005039f0` as a function, but disassembly at `0x005039f0-0x00503a41` is valid code that initializes the `GameServerConfig` and `ProtectedArray<GameServerConfig::NationEntry>` vtables and global `dword_69B4C4`.
- IDA also does not model `0x00503a50` as a function, but disassembly at `0x00503a50-0x00503a78` resets the `GameServerConfig`/`ProtectedArray` vtables, frees table storage, clears `dword_69B4C4`, and jumps to base `LObject` cleanup.
- IDA confirms `0x00503a80-0x00503b58` as a real function with callers at `0x005b8c70` and `0x005be520`.
- 2026-05-31 IDA recheck: raw code at `0x00503b60-0x00503c61` seeds two `0x44` byte nation-entry records with ids `1` and `2`, localized string ids `0x9f` and `0xa0`, and no current function record or caller xrefs.
- IDA confirms `0x00503c70-0x00503d03` as a real function with callers at `0x005a5010`, `0x005a5bd0`, `0x005b8c70`, and `0x005be520`.
- IDA confirms `0x00504110-0x00504521` as a real function called twice from `0x004f7d10`.
- 2026-05-26 IDA recheck: `InitializeMapPane` consumes [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), reading `word_66DAA0` at `0x005042a6` and `word_66DA9C` at `0x005042b0` to size the map-pane bounds from tile counts plus a two-tile border.
- IDA confirms `0x00514d50-0x00514d7f` and `0x00514d80-0x00514ddc` as real destructor functions.
- 2026-05-25 IDA recheck: `CopyNationEntryOrFallback` copies exactly 68 bytes from matching nation-entry records or synthesizes a fallback whose visible label is `L"????"`. `RequestNationEntries` sends opcode `0x66` with subcode `0x4000` only when the table count is not populated.
- 2026-05-28 IDA recheck: [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) is a raw function-shaped helper immediately before the constructor block. It sends the same fixed nine-byte nation-entry request payload as `RequestNationEntries`, but IDA has no function object or xrefs to `0x00503960`.
- 2026-05-25 IDA recheck: `InitializeMapPane` writes [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`, installs `MapPane` vtables, loads `SOBJ.TBL` through `off_61c1a4`, populates [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) and [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), then allocates an 88-byte nation table and stores [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md).

## Source-Layout Decision

Do not place this under `config/` with `RegistryConfig`; it is a gameplay/map helper. The current generated `InitializeMapPane` name and body strongly tie it to `MapPane`:

- constructs `Pane` state;
- stores the active map-pane singleton now documented as [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md);
- sets `MapPane` vtables;
- loads `SOBJ.TBL` into `g_objectNationMap`;
- registers the pane under `g_rootPane`;
- initializes map lighting/fog, selection overlay, and tile dimensions;
- reads the shared [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) rather than owning them as fields;
- allocates the nation-entry table singleton.

The nation-entry lookup/request methods are used by user/status presentation code, but they depend on the same map-owned global table.

## Data Caveats

- Wave3 `inspect class GameServerConfig` includes `CopyNationEntryOrFallback` and `RequestNationEntries`, but `show method` marks both as `excluded: true` and the emitted `class_GameServerConfig.cpp` does not contain their bodies.
- IDA has valid code at `0x005039f0`, but no IDA function record at that start. This should be treated as an IDA/Wave3 boundary caveat before using it as a rename anchor.
- `0x00503960-0x005039ed` is valid packet-construction code with no current IDA function object or xrefs. Keep it as a raw retained helper until call-table, vtable, or manually recovered caller evidence appears.
- IDA shows destructor-like code at `0x00503a50-0x00503a78` in the same local block, but it is not currently modeled as a Wave3 method.
- `SOBJ.TBL` has two parser views: `StaticObjImageLib` owns the full static-object resource table, while this module's map initializer builds only the compact object-to-nation/classification byte map.

## Cross-References

- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)
- [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md)
- [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md)
- [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md)
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md)
- [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md)
- [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md)
- [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)

## Changes

- 2026-05-28: Added the adjacent raw nation-request packet helper at `0x00503960-0x005039ed` as a retained/helper candidate instead of folding it into `GameServerConfig::RequestNationEntries`. Evidence: IDA MCP raw bytes show valid packet-construction code sending the same fixed payload, while xref and function lookup found no modeled function or caller at `0x00503960`.
- 2026-05-28: Added nation-entry parser/resize support through [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md). Evidence: IDA MCP reports the helper as the sole direct target from the `0x00503d10` nation-entry packet parser and shows 68-byte `GameServerNationEntry` stride behavior.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: map/nation-table ownership, raw request packet, nation-entry parser/resize support, `MapPane` initialization relationship, globals/resources, and source-layout decision are documented; confidence is capped by medium class-name certainty, exact `MapPane` split, and raw helper/function-boundary caveats.
- 2026-05-31: Replaced broad address-only rows with exact by-memory child links and added the raw default-entry seeder. Evidence: IDA MCP function listing and raw byte checks found exact child boundaries inside the old `0x005039f0-0x00504521` aggregate, including hidden raw code at `0x00503b60-0x00503c61`.
