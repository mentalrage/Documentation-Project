*** UID:00005O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GameServerConfig

## Status

- Confidence: medium for the class boundary, strong for map/nation-table behavior.
- Proposed file: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- Current generated file: `class_GameServerConfig.cpp`
- Current ranges: `0x005039f0-0x00504520`, `0x00514d80-0x00514ddb`
- Evidence basis: Wave3 class inspection, generated source, Wave2 report notes, and IDA MCP checks.
- Key globals/types: [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md), [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), and [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md).

## Responsibility

`GameServerConfig` currently represents a nation-entry table/helper used by map and status/user presentation code. Its strongest behavior is not generic configuration; it is map/gameplay state around nation metadata, object nation mapping from `SOBJ.TBL`, and the map-pane initializer that creates the table.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00503960-0x005039ed` | raw nation request packet helper | Builds and sends the fixed nation-entry request payload, but is not proven as a live class method because current IDA has no function object or xrefs to the start. |
| [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md) | `InitializeNationEntryTable()` | Initializes `LObject`, installs `GameServerConfig` and protected-array vtables, sets default capacity/count, and stores the global table pointer. |
| [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md) | raw non-deleting destructor | Frees table storage, clears the global table pointer, and tail-jumps to base cleanup. |
| [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md) | `CopyNationEntryOrFallback(unsigned int* destination, int nationId)` | Copies a matching nation-entry record into caller storage, or returns a fallback record with a question-mark label. |
| [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) | raw default-entry seeder | Allocates/seeds two default nation records with string-table ids `0x9f` and `0xa0`; no current IDA function record or caller xrefs. |
| [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md) | `RequestNationEntries()` | Queues the fixed nation-entry request packet when the shared table is empty/stale. |
| [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | nation-entry parser/array resize support | Parses packet-provided nation records and resizes the `ProtectedArray<GameServerConfig::NationEntry>` backing store. |
| [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) | `InitializeMapPane(int mapWidth, int mapHeight)` | Initializes map-pane state, loads object-to-nation mapping from `SOBJ.TBL`, registers the root pane child, and allocates the nation-entry table. |
| `0x00514d80` | `ScalarDeletingDestructor(unsigned int flags)` | Frees nation-entry backing storage, clears global table pointer, destroys base object, and conditionally deletes `this`. |

## Ownership Notes

- `InitializeMapPane` is probably better treated as `MapPane` constructor/initializer code during final source-layout migration, despite current Wave3 class attribution.
- `CopyNationEntryOrFallback` and `RequestNationEntries` are currently excluded in `show method` output and are not emitted in `class_GameServerConfig.cpp`, even though `inspect class` lists them.
- `0x005039f0` has valid IDA disassembly but no IDA function record; treat the start as a boundary caveat.
- [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) is valid adjacent code that sends the same fixed request payload as `RequestNationEntries`, but no current IDA function/caller evidence proves it is an active class method.
- [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md) is destructor-shaped local code with no IDA function record; it resets table vtables, frees table storage, clears `g_gameServerNationTable`, and jumps to base cleanup. The range end was corrected to include the full tail-jump instruction.
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) is valid raw code that seeds two localized default records, but no current caller/function object proves live method ownership.
- Wave3's `g_activeGameServerConfig` alias should be renamed around [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md); IDA shows it is the live `MapPane*`.
- The `SOBJ.TBL` work inside `InitializeMapPane` builds [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), not the full static-object resource table owned by [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- 2026-05-25 IDA recheck confirms `0x00504110` is `MapPane` construction behavior: it writes `dword_67a764`, installs `MapPane` vtables, registers the root child, loads `SOBJ.TBL`, and allocates the nation-entry table. This strengthens the decision to keep the class out of `config/`.
- The current generated file still emits `InitializeNationEntryTable` and `InitializeMapPane`, but omits the two excluded helper bodies at `0x00503a80` and `0x00503c70`.

## Cross-References

- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md)
- [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md)
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
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

- 2026-05-28: Added `0x00503960-0x005039ed` as an adjacent raw packet-helper candidate rather than a confirmed class method. Evidence: IDA MCP shows the same fixed nation-entry request payload behavior as `RequestNationEntries`, but no function object or caller xrefs at `0x00503960`.
- 2026-05-28: Added nation-entry parser/resize support through [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md). Evidence: IDA MCP reports the helper as the sole direct target from the `0x00503d10` nation-entry packet parser and shows 68-byte `GameServerNationEntry` stride behavior.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: nation-table behavior, map-pane initializer caveat, globals, parser/resize support, raw helper caveats, and ownership decisions are well documented, but the class boundary remains medium-confidence. Evidence: memory pages for `0x00503960`, `0x005039f0-0x00504521`, `0x00514d50-0x00514ddc`, and `0x00514ee0-0x00514f6b`, plus global/type/resource cross-references.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE` and replaced broad method rows with exact child by-memory links where IDA MCP verified the boundaries. Evidence: IDA MCP `list_funcs`/raw byte checks found exact function or code-island ranges at `0x005039f0`, `0x00503a50`, `0x00503a80`, `0x00503b60`, `0x00503c70`, `0x00503d10`, and `0x00504110`; the raw destructor end was corrected from `0x00503a78` to `0x00503a7d`.
