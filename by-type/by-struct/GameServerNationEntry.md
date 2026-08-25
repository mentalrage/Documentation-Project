*** UID:0001UP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// GameServerConfig::NationEntry is emitted as the nested record declaration
// in [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) GameServerConfig. This page documents the same 0x44-byte
// layout; do not emit a second standalone GameServerNationEntry struct.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GameServerNationEntry

## Status

- Confidence: strong for size, field offsets, stride, parser writes, lookup copies, and resize behavior; medium for final source-facing type name.
- Likely owner header: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) or a private `MapPane` helper header.
- Current generated spelling: `GameServerConfig::NationEntry`.
- Autogen parent: attached to [UID:00005O][GameServerConfig](by-class/GameServerConfig.md); the class now scores `90/91` and this record scores `88/91`, so both sides satisfy the active direct-parent gate.
- Evidence basis: IDA MCP function lookup, decompile, raw disassembly, xrefs, byte checks, and section-mapped PE reachability scans through 2026-06-16. Generated data is only a naming/ownership lead.

## Layout

```cpp
struct GameServerNationEntry {
    GameServerNationEntry()
        : nationId((std::uint16_t)-1)
    {
    }

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
- The resize helper's per-element first-word initialization is best represented as an inline default constructor or default member initializer setting `nationId = (unsigned short)-1`. The label buffer is populated later by parser/seeder paths and is not zeroed by the reviewed resize body.
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) is a raw retained helper that seeds two records with ids `1` and `2` and localized string labels; current IDA has no function record or caller xrefs to the raw start.
- `ProtectedArray<GameServerConfig::NationEntry>` cleanup at `0x00514d50` frees the backing entry buffer, while `GameServerConfig::ScalarDeletingDestructor` at `0x00514d80` clears the global table pointer.
- 2026-06-16 A001 live IDA refresh reconfirmed raw/no-function status for `0x005039f0`, `0x00503a50`, and `0x00503b60`; modeled lookup/copy `0x00503a80` size `0xd8`; request helper `0x00503c70` size `0x93`; parser `0x00503d10` size `0x167`; and resize helper `0x00514ee0` size `0x8b`.
- The same pass reconfirmed two callers to `GameServerConfigCopyNationEntryOrFallback`, the single parser caller to the resize helper at `0x00503d4f`, and 18 xrefs to [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) across raw constructor/destructor islands, `MapPaneInitialize`, `MapPaneCleanup`, parser/request/user-status consumers, and lookup callers.
- 2026-06-16 decompilation again shows the `68` / `0x44` byte stride, `33` / `0x21` wide-character label capacity, full-record copy as four 16-byte chunks plus a trailing dword, parser writes to id `+0x00` and label `+0x02`, and resize initialization of each first word to `-1` with `34` wide-word steps. These conversions were verified with `tools/int_convert.py`.
- A 2026-06-16 section-mapped PE scan found no absolute VA, RVA, or rel32 call/jump references to raw `0x005039f0`, `0x00503a50`, or `0x00503b60`. The raw constructor/destructor/seeder source-shape caveat remains real, but it does not weaken the two-field record layout.

## Score Rationale

Completion is high but below final-source level because the record size, two fields, parser writes, lookup copies, fallback record, resize behavior, and destructor ownership are now documented from IDA evidence. It remains below `95` because final source naming, header ownership, packet field names, sentinel/default label meaning, and all caller-side semantic names are not yet fully audited.

Confidence is strong for the concrete binary layout and behavior. It stays below `95` because the final human type name and source placement remain a reconstruction hypothesis rather than proven original-source naming.

## Source Placement

Keep this type with the map/gameplay nation table, not with the general configuration system. A reconstructed source tree can name it `GameServerNationEntry`, `NationEntry`, or `GameServerConfig::NationEntry`, but the record belongs next to [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) and [UID:0000L3][MapPane](by-file/MapPane.md).

Do not promote this to a generic configuration record. The current global and caller fanout place it in map/game-server nation presentation and packet parsing. Final source-level declaration spelling still needs a source audit because the nested generated spelling, map-private placement, and packet schema names are not independently proven.

For the concrete resize source emitted by [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), the strongest current declaration spelling is `GameServerConfig::NationEntry` with a trivial default constructor. B009 resolves the formal output route by emitting that nested declaration once on [UID:00005O][GameServerConfig](by-class/GameServerConfig.md); this type page keeps a formal no-duplicate comment.

```cpp
GameServerConfig::NationEntry::NationEntry()
    : nationId((unsigned short)-1)
{
}
```

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

- 2026-06-19 B004 GameServerConfig accepted source-quality sync: score unchanged at `86/90`; updated the parent score reference after [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) rose to `87/89`. The record remains owned by the GameServerConfig nation-table route, while [UID:0000L3][MapPane](by-file/MapPane.md) owns the neighboring active-map and compact `SOBJ.TBL` cache state.
- 2026-07-01 B009 accepted empty-emitter-family implementation: raised to `88/91` and inserted a formal no-duplicate C++ comment. The source declaration now emits once as nested `GameServerConfig::NationEntry` on [UID:00005O][GameServerConfig](by-class/GameServerConfig.md), while this page preserves the `0x44` / 68-byte layout (Verified with int_convert.py), `nationId` at `+0x00`, `label[33]` at `+0x02`, and default `nationId = -1` evidence.
- 2026-06-06: Attached the record to [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) because the generated nested spelling, parser/copy/resize evidence, and `GameServerConfig` class score now clear the parent gate. No completion/confidence score change was made.
- 2026-05-31: Raised from unevaluated `0/0` to `COMPLETION:84` and `CONFIDENCE:88`, and marked `RECONSTRUCTABLE:TRUE`.
  Evidence: IDA MCP confirmed `0x00503a80` record lookup/copy, `0x00503d10` packet parser writes, `0x00514ee0` 68-byte resize helper, destructor cleanup, and raw default-entry seeding at `0x00503b60`. Score remains below `95` because final type/source names and packet/sentinel semantics are not fully proven.
- 2026-06-16 A001 Goal 2 type/layout refresh:
  - Before: `84/88`.
  - Changed to: `86/90`; owner/emitter remain [UID:00005O][GameServerConfig](by-class/GameServerConfig.md).
  - Evidence: live IDA reconfirmed modeled lookup/copy, request, parser, and resize boundaries, raw no-function status for the constructor/destructor/seeder islands, caller/xref sets, global-table fanout, record stride/capacity/copy behavior, and PE-scan absence of references to the raw starts. Completion stays below final-source level because source declaration spelling, packet field names, and raw helper reachability/source placement remain unresolved.
- 2026-06-19 B008 [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) implementation sync:
  - Score unchanged at `86/90`.
  - Added the inferred default constructor/default initializer for `nationId = (unsigned short)-1` that explains the resize helper's per-element initialization loop. The label buffer remains populated later by parser/seeder paths and is not zeroed by the reviewed resize body.
