*** UID:0001UP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00005O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GameServerNationEntry

## Status

- Confidence: strong for size, field offsets, stride, parser writes, lookup copies, and resize behavior; medium for final source-facing type name.
- Likely owner header: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) or a private `MapPane` helper header.
- Current generated spelling: `GameServerConfig::NationEntry`.
- Autogen parent: attached to [UID:00005O][GameServerConfig](by-class/GameServerConfig.md); the class scores `82/80` and this record scores `84/88`, so both sides satisfy the 80/80 parent gate.
- Evidence basis: IDA MCP function lookup, decompile, raw disassembly, xrefs, and byte checks on 2026-05-31. Generated data is only a naming/ownership lead.

## Layout

```cpp
struct GameServerNationEntry {
    std::uint16_t nationId;  // +0x00
    wchar_t label[33];       // +0x02, 0x42 bytes on Windows
};
static_assert(sizeof(GameServerNationEntry) == 0x44);
```

| Offset | Size | Field | Notes |
| --- | --- | --- | --- |
| `0x00` | `0x02` | `nationId` | Compared against the requested nation id in `0x00503a80`. |
| `0x02` | `0x42` | `label[33]` | Wide string copied by callers. Fallback text is `L"????"`. |

The protected-array storage advances by `68` bytes per entry. `CopyNationEntryOrFallback` copies exactly four 16-byte chunks plus one trailing dword, which matches the `0x44` byte record size.

## Behavior Evidence

- `GameServerConfig::CopyNationEntryOrFallback` at `0x00503a80` scans `m_tableData + index * 68`, compares the first word, and copies the full record to caller storage.
- If no entry matches, the method builds a local record with `nationId == 0` and `label == L"????"`.
- `GameServerConfig::ParseNationEntries` at [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md) writes the first field from packet data, converts byte strings into the wide label at `+0x02`, and appends a sentinel/default record.
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) allocates `68 * count` bytes, initializes the first word of each record to `-1`, preserves the overlapping old prefix with `memmove`, and updates the protected-array backing pointer/count.
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) is a raw retained helper that seeds two records with ids `1` and `2` and localized string labels; current IDA has no function record or caller xrefs to the raw start.
- `ProtectedArray<GameServerConfig::NationEntry>` cleanup at `0x00514d50` frees the backing entry buffer, while `GameServerConfig::ScalarDeletingDestructor` at `0x00514d80` clears the global table pointer.

## Score Rationale

Completion is high but below final-source level because the record size, two fields, parser writes, lookup copies, fallback record, resize behavior, and destructor ownership are now documented from IDA evidence. It remains below `95` because final source naming, header ownership, packet field names, sentinel/default label meaning, and all caller-side semantic names are not yet fully audited.

Confidence is strong for the concrete binary layout and behavior. It stays below `95` because the final human type name and source placement remain a reconstruction hypothesis rather than proven original-source naming.

## Source Placement

Keep this type with the map/gameplay nation table, not with the general configuration system. A reconstructed source tree can name it `GameServerNationEntry`, `NationEntry`, or `GameServerConfig::NationEntry`, but the record belongs next to [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) and [UID:0000L3][MapPane](by-file/MapPane.md).

## Cross-References

- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md)
- [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md)
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md)
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md)
- [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)

## Changes

- 2026-06-06: Attached the record to [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) because the generated nested spelling, parser/copy/resize evidence, and `GameServerConfig` class score now clear the parent gate. No completion/confidence score change was made.
- 2026-05-31: Raised from unevaluated `0/0` to `COMPLETION:84` and `CONFIDENCE:88`, and marked `RECONSTRUCTABLE:TRUE`.
  Evidence: IDA MCP confirmed `0x00503a80` record lookup/copy, `0x00503d10` packet parser writes, `0x00514ee0` 68-byte resize helper, destructor cleanup, and raw default-entry seeding at `0x00503b60`. Score remains below `95` because final type/source names and packet/sentinel semantics are not fully proven.
