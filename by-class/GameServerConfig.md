*** UID:00005O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GameServerConfig : public LObject
{
public:
    struct NationEntry
    {
        NationEntry()
            : nationId((unsigned short)-1)
        {
        }

        unsigned short nationId;
        wchar_t label[33];
    };

    GameServerConfig();
    virtual ~GameServerConfig();

    NationEntry *CopyNationEntryOrFallback(NationEntry *destination, int nationId);
    void SeedDefaultNationEntries();
    void RequestNationEntries();
    void ParseNationEntries(const unsigned char *packet);

    int GetNationEntryCount() const
    {
        return m_nationEntries.GetCount();
    }

    NationEntry *GetNationEntryAtOrDefault(int index)
    {
        return m_nationEntries.GetAtOrDefault(index);
    }

private:
    ProtectedArray<NationEntry> m_nationEntries;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GameServerConfig

## Status

- Confidence: strong for the compiler-supported class name, map/game-server nation-table behavior, `GameServerConfig.cpp` feature ownership, modeled helper callers, and the `MapPane` split; medium-high only for final source header spelling and raw no-route island retention.
- Proposed file: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- Autogen parent: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md), valid under the strict `85/85` gate; this class is `91/92` and the direct file parent remains independently documented.
- Current generated file: `class_GameServerConfig.cpp`
- Current ranges: `0x005039f0-0x00504520`, `0x00514d80-0x00514ddc`, and class vtable data [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md).
- Evidence basis: Wave3 class inspection, generated source, Wave2 report notes, IDA MCP checks, B003/B008 support implementations, and the B004 2026-06-19 source-quality PE reachability scan.
- Key globals/types: [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md), [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), and [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md).

## Responsibility

`GameServerConfig` is the compiler-supported class name for the map/game-server nation-entry table used by map and status/user presentation code. Its strongest behavior is not generic configuration or registry state; it owns nation metadata, the `g_gameServerNationTable` singleton/table pointer, the packet lookup/request/parser family, and the embedded `ProtectedArray<GameServerConfig::NationEntry>` records. `SOBJ.TBL` object-nation cache construction and the active map-pane singleton are dependencies from the neighboring `MapPane` constructor, not `GameServerConfig` state.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) | file-local support helper `SendGameServerNationEntryRequestPacket()` | Builds and sends the fixed nation-entry request payload, but is not proven as a live class method because current static scans find no function object, caller, or pointer route to the raw start. |
| [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md) | raw constructor-shaped island / `GameServerConfig::GameServerConfig()` | Initializes `LObject`, installs `GameServerConfig` and protected-array vtables, sets default reserved count/count/pointer state, and stores the global table pointer. Fresh MCP still finds no caller, VA/RVA, raw-offset, or rel32 route to the raw start, but B009 resolves that as a confidence cap rather than a blank-C++ blocker; formal first-draft constructor C++ lives on the child page. |
| [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md) | raw non-deleting destructor / `GameServerConfig::~GameServerConfig()` | Frees table storage, clears the global table pointer, and tail-jumps to base cleanup. B009 populates the child with ordinary destructor C++ while preserving the no-function/no-xref caveat and keeping the scalar deleting wrapper separate. |
| [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md) | `CopyNationEntryOrFallback(NationEntry *destination, int nationId)` | Copies a matching 68-byte nation-entry record into caller storage, or returns a fallback record with id `0` and label `L"????"`. B009 populates first-draft C++ on the child while keeping destination/member names provisional. |
| [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) | raw default-entry seeder / `SeedDefaultNationEntries()` | Allocates/seeds two default nation records with ids `1` and `2` and language string ids `0x9f` and `0xa0`; no current IDA function record or caller xrefs. B009 populates first-draft C++ on the child and preserves those negative-route facts as confidence caps. |
| [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md) | `RequestNationEntries()` | Queues the fixed nation-entry request packet when the shared table is empty/stale. B009 populates first-draft C++ on the child and calls the existing file-local packet helper. |
| [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) | nation-entry parser / protected-array resize support | Parses packet-provided nation records. [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) is not a handwritten outer `GameServerConfig` method; it is the concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` instantiation called by the parser with `ecx = this + 4`, while remaining in this feature route. |
| [UID:0003IS][0x0061e908-0x0061e924.GameServerConfigNeighborhoodString](by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md) | default neighborhood label literal | UTF-16 `Neighborhood` literal consumed by the nation-entry parser at `0x00503e5b`. |
| [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) | historical/generated `InitializeMapPane` label only | B002 2026-06-17 resolves this as `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` under [UID:00007Q][MapPane](by-class/MapPane.md). This class remains a dependency owner for the `g_gameServerNationTable` object allocated by the constructor, not the source owner of the constructor body. |
| [UID:000374][0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor](by-memory/0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md) | `ScalarDeletingDestructor(unsigned int flags)` | Frees nation-entry backing storage, clears global table pointer, destroys base object, and conditionally deletes `this`. |

## Ownership Notes

- Historical/generated `InitializeMapPane` is owner pollution from the old generated class attribution. Treat [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) as `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`, not as `GameServerConfig::InitializeMapPane`.
- B002's 2026-06-17 MapPane lifecycle pass upgrades that caveat to an accepted split: [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) is the ordinary `MapPane` constructor and [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](by-memory/0x00504530-0x005046c6.MapPaneCleanup.md) is the ordinary `MapPane` destructor. `GameServerConfig` ownership remains for the nation-entry table object, `GameServerNationEntry` records, and request/parser/resize helpers only.
- Historical `show method` output excluded `CopyNationEntryOrFallback` and `RequestNationEntries` from the old generated class file even though `inspect class` listed them. B009 treats that as stale generated-output evidence: both modeled functions are now emitted as child method bodies under this class route.
- `0x005039f0` has valid IDA disassembly but no IDA function record; treat the start as a boundary caveat.
- [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) is valid adjacent code that sends the same fixed request payload as `RequestNationEntries`, but no current IDA/static route evidence proves it is an active class method. B003's 2026-06-18 pass keeps it as a `GameServerConfig.cpp` private file-local support helper, not a class method: it has no `this` use, no parameter use, no caller/pointer route to `0x00503960`, and its live guarded class-method counterpart remains [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md) with four direct callers.
- [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md) is destructor-shaped local code with no IDA function record; it resets table vtables, frees table storage, clears `g_gameServerNationTable`, and jumps to base cleanup. The range end was corrected to include the full tail-jump instruction.
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md) is valid raw code that seeds two localized default records, but no current caller/function object proves live method ownership.
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) is a concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)` body, not a direct outer `GameServerConfig` method. It remains part of the `GameServerConfig` feature/output route because the sole caller is the nation-entry parser and the parser passes the embedded protected-array member at `this + 4`.
- Wave3's `g_activeGameServerConfig` alias should be renamed around [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md); IDA shows it is the live `MapPane*`.
- The `SOBJ.TBL` work inside `InitializeMapPane` builds [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), not the full static-object resource table owned by [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- 2026-05-25 IDA recheck confirms `0x00504110` is `MapPane` construction behavior: it writes `dword_67a764`, installs `MapPane` vtables, registers the root child, loads `SOBJ.TBL`, and allocates the nation-entry table. This strengthens the decision to keep the class out of `config/`.
- The historical generated file emitted `InitializeNationEntryTable` and `InitializeMapPane`, but that output is now treated as provenance rather than final source structure. `InitializeMapPane` belongs to `MapPane`, while `0x005039f0` remains a no-route constructor-shaped island and the modeled lookup/request bodies remain live class/feature methods even though older `show method` output excluded them.
- 2026-06-12 IDA MCP JSON-RPC reconfirmed [UID:0003C3][0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString](by-memory/0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md) as the exact UTF-16 fallback literal consumed by [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md). The string is assigned here because this class already clears the direct `85/85` gate and the mixed `.rdata` aggregate is not the semantic parent.
- 2026-06-12 C001 IDA MCP JSON-RPC reconfirmed [UID:0003IS][0x0061e908-0x0061e924.GameServerConfigNeighborhoodString](by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md) as the exact UTF-16 `Neighborhood` literal consumed only by [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md) at `0x00503e5b`.
- 2026-06-12 A003 Batch326 split [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) into exact children. [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md) now carries the class-owned `GameServerConfig` COL and three-slot vtable, while the protected-array vtable and following `MapPane` COL boundary are separated.

## 2026-06-19 B004 Source-Quality Decision

B004 keeps `GameServerConfig` as the current source-facing class name and [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) as the canonical owner/emitter. The accepted score is `COMPLETION:87`, `CONFIDENCE:89`; `CANONICAL_OWNER`, `RECONSTRUCTABLE`, and `EMITTER_UIDS` remain unchanged. The confidence gain comes from closing the false `InitializeMapPane` ownership and separating retained raw islands from modeled live methods.

Fresh PE reachability was checked against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, with `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, and `.data 0x0066d000-0x0069ce24`. The retained raw starts all decode as source-shaped code but have no rel32 call/jump route and no absolute VA, RVA, or raw-file-offset pointer route:

| Raw start | PE file offset | First bytes | Source-quality decision |
| --- | --- | --- | --- |
| `0x00503960` | `0x102d60` | `55 8b ec 83 ec 44 a1 24 2f 67 00 33 c5 89 45 fc` | Retain as private file-local support helper evidence for already emitted [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) / `SendGameServerNationEntryRequestPacket()`, not as a class method. |
| `0x005039f0` | `0x102df0` | `55 8b ec 51 56 8b f1 89 75 fc e8 81 10 ff ff 8d` | Retain as constructor-shaped nation-table initialization evidence; do not emit a class constructor body from this page. |
| `0x00503a50` | `0x102e50` | `56 8b f1 c7 06 0c e7 61 00 ff 76 0c c7 46 04 04` | Retain as destructor-shaped local cleanup evidence; do not emit a source destructor body from this page. |
| `0x00503b60` | `0x102f60` | `55 8b ec 51 53 56 8b f1 bb 02 00 00 00 57 8b 46` | Retain as default-entry seeder evidence; no caller/function route currently supports promoting it to a live member. |

The modeled live paths remain real and should keep their current source-facing names or feature roles. `GameServerConfigCopyNationEntryOrFallback` at `0x00503a80` has callers `0x005b9318` and `0x005be746`; `GameServerConfigRequestNationEntries` at `0x00503c70` has callers `0x005a5029`, `0x005a5dcc`, `0x005b92fe`, and `0x005be72c`; `GameServerConfigParseNationEntries` at `0x00503d10` has caller `0x00507d00`; `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` at `0x00504110` has callers `0x004f7dfa` and `0x004f85ef`; and [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) has parser caller `0x00503d4f` with `ecx = this + 4`.

Global ownership is now split as follows. `g_gameServerNationTable` at `0x0069b4c4` is the `GameServerConfig` singleton/table pointer and has 18 direct hits across raw constructor/destructor islands, `MapPane` allocation/teardown, parser/request/user-status consumers, lookup callers, and scalar cleanup. `g_activeMapPane` at `0x0067a764` is MapPane-owned alias pollution from the generated `g_activeGameServerConfig` name and has 360 direct hits. `g_objectRecordCount` at `0x0069b4bc` and `g_objectNationMap` at `0x0069b4c0` are MapPane-owned compact `SOBJ.TBL` cache state, not `GameServerConfig` fields.

[UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) must remain documented as concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int)`. It is feature-local support output because the parser uses the embedded array member, but it is not a handwritten outer `GameServerConfig` method. The neighboring [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) first-draft `SendGameServerNationEntryRequestPacket()` also remains valid support output; neither support body requires this class page to emit a class-level `RECONSTRUCTION_CPP` body.

Rejected and historical alternatives are preserved explicitly:

- `config/` / registry ownership is rejected because all durable behavior is map/gameplay nation state, not settings or registry persistence.
- Full `MapPane` ownership of the class is rejected because the compiler-supported `GameServerConfig` class name, `g_gameServerNationTable`, record type, lookup/request/parser helpers, fallback/default literals, vtable data, and protected-array specialization form a coherent nation-table feature family.
- `GameServerConfig` ownership of [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) is rejected; the final source-facing name is `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`.
- `g_activeGameServerConfig` / `g_activeGameServerConfig*` style naming is rejected as generated alias pollution; use [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) for the storage.
- Treating raw `0x00503960` as a class member remains rejected; it stays a private file-local helper. B009 supersedes the older blank-member policy for raw `0x005039f0`, `0x00503a50`, and `0x00503b60`: those now emit first-draft constructor/destructor/seeder source while preserving no-function/no-xref evidence as confidence caps.
- Treating [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) as an outer `GameServerConfig` method is rejected; it is the concrete protected-array specialization.
- Hand-authored vtables/COL data and scalar deleting destructors are rejected as source methods. They remain compiler-emitted evidence for layout and cleanup.

Historical note: the 2026-06-19 B004 pass kept class-level first-draft C++ blank because the raw constructor/destructor/seeder route and header spelling were not yet accepted. The 2026-07-01 B009 empty-emitter implementation supersedes that blank-C++ policy under the current source-quality rules: the class page now emits only the source declaration, nested `NationEntry`, `ProtectedArray<NationEntry> m_nationEntries`, and method declarations, while child by-memory pages own method bodies and continue to preserve the raw no-function/no-xref caveats.

## 2026-07-01 B009 Empty-Emitter Implementation Sync

B009 applied the accepted [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) empty-emitter-family report. The class score is now `90/91`; owner/emitter remain [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md), and the formal C++ block now carries the source declaration only. This avoids duplicate child bodies while clearing the stale empty marker in `auto-generated/NexusTK/map/GameServerConfig.cpp`.

The nested `NationEntry` declaration is emitted here once because the generated/source route uses `GameServerConfig::NationEntry`: `nationId` is a 16-bit field at offset `+0x00`, `label[33]` starts at `+0x02`, the total record size is `0x44` / 68 bytes (Verified with int_convert.py), and the default constructor initializes `nationId` to `(unsigned short)-1`. [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) now carries a formal no-duplicate marker rather than a second standalone struct declaration.

The protected-array member is source-facing `ProtectedArray<NationEntry> m_nationEntries`. Its binary layout remains evidenced by [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), and [UID:0001VM][ProtectedArrayLayout](by-type/by-struct/ProtectedArrayLayout.md). The `+0x0c` constructor-initialized value remains provisional as `m_reservedCount` / `m_defaultCapacity`; reviewed resize/accessor/destructor bodies do not use it as live current capacity.

B009 preserves the current MCP negative evidence: raw starts `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` still have no modeled function records and no direct raw-start xrefs. That evidence is now a confidence cap rather than a blank-C++ blocker for the constructor/destructor/seeder, because those islands are complete, source-shaped, class-owned, range-bounded, and mirrored by live lifecycle code. The modeled member methods remain route-proven: [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md) has two callers, [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md) has four callers and calls the already-emitted file-local request helper shape, and [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md) has one packet-dispatch caller and the sole direct resize call.

Rejected alternatives remain active: generic `config/` / registry ownership, full `MapPane` ownership of the class, historical `GameServerConfig::InitializeMapPane`, `g_activeGameServerConfig`, hand-authored vtables/COL, scalar deleting destructor as an ordinary source method, duplicate standalone `GameServerNationEntry` struct emission, and generated wrapper class emission for `ProtectedArray_struct_GameServerConfig__NationEntry_`.

## Assignment Gate Rationale

This class now clears the strict child/direct-parent assignment gate at `90/91`, and the direct file parent [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) is also updated to `90/91`. The evidence chain is the exact constructor/destructor-shaped raw islands, lookup/fallback, default seeder, request, parser, and resize children, plus the table global [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md), 68-byte [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md), protected-array specialization [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md), and the now-accepted `MapPane` ownership for `SOBJ.TBL` cache and active-map state. Remaining uncertainty is about exact original private names and raw-start reachability, not whether these nation-entry helpers belong to the `map/` source family.

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
- [UID:0003C3][0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString](by-memory/0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md)
- [UID:0003IS][0x0061e908-0x0061e924.GameServerConfigNeighborhoodString](by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md)
- [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md)
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md)
- [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md)
- [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md)
- [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:000372][0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor](by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md)
- [UID:000374][0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor](by-memory/0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)

## Changes

- 2026-07-14 B004 UID000470 bounded support implementation:
  - Raised `90/91 -> 91/92`, preserved owner/emitter UID0000JP, the accepted class/method surface, all raw no-route caveats, the MapPane ownership split, child bodies, and protected-array/compiler dispositions.
  - Added only the constructor-inlined protected-array access surface proven by UID000470: `GetNationEntryCount() const` and non-const `GetNationEntryAtOrDefault(int)`, both forwarding directly to `m_nationEntries` without a new out-of-line body.
  - The bounded score increase reflects closure of the constructor-side accessor blocker. No source route, field, vtable, raw-helper, or unrelated C++ change was made.

- 2026-06-19 B004 accepted source-quality implementation:
  - Score raised from `85/86` to `87/89`; owner/emitter remain [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md), and class-level `RECONSTRUCTION_CPP` remains blank.
  - Incorporated the accepted PE route scan, final `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` split for [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md), `g_activeMapPane` alias-pollution closure, `g_gameServerNationTable` ownership, MapPane-owned `g_objectRecordCount`/`g_objectNationMap` cache state, and the no-route treatment for raw `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60`.
  - Preserved rejected historical alternatives: generic config ownership, full MapPane ownership of the class, `GameServerConfig::InitializeMapPane`, `g_activeGameServerConfig`, raw helper/member promotion, outer-method resize, source-authored vtables/COL, and scalar deleting destructor-as-source-method.
- 2026-07-01 B009 accepted empty-emitter-family implementation:
  - Score raised from `87/89` to `90/91`; owner/emitter remain [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md).
  - Formal class declaration added with nested `NationEntry`, `ProtectedArray<NationEntry> m_nationEntries`, constructor/destructor/method declarations, and no child method body duplication.
  - Superseded the older class blank-C++ rationale while preserving the raw no-function/no-xref caveats, MapPane split, global/vtable/literal evidence, and rejected ownership/source-shape alternatives.
- 2026-06-18 B003 [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) source-quality sync:
  - Score unchanged at `85/86`.
  - Clarified that [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md) is a `GameServerConfig.cpp` private file-local support helper rather than a confirmed `GameServerConfig` member method.
  - Summary/evidence: B003 found no `this` use, no direct caller, no rel32 branch route, and no VA/RVA/raw-offset pointer route to the raw start; the helper still sends the exact nation-entry request packet through named PacketBuffer writers and `g_packetSender`. Keep member ownership on [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md).
- 2026-06-19 B008 [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) implementation sync:
  - Score unchanged at `85/86`.
  - Clarified that [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) is the concrete protected-array resize called with `ecx = this + 4`, not a handwritten outer `GameServerConfig` method, while still belonging to this feature/output route.
- 2026-06-11 A001 strict-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:80`, `AUTOGEN_PARENT_UID:` blank because both this class and [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) failed the corrected `85/85` gate.
  - After: `COMPLETION:85`, `CONFIDENCE:86`, `AUTOGEN_PARENT_UID:0000JP`.
  - Summary/evidence: accepted the class-to-file parent after the file page reached `86/85` and this class page now explicitly ties the exact constructor/destructor, lookup/fallback, default seeder, request, parser, resize, global, type, protected-array, and resource evidence into one map/game-server nation-entry helper family. The `InitializeMapPane` split caveat remains documented, so final C++ remains blank.
- 2026-06-12 A005 Batch 273: Added [UID:0003C3][0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString](by-memory/0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md) as an exact class-owned source literal after live IDA MCP JSON-RPC reconfirmed its bytes, xref into [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md), and direct parent gate. Score remains `85/86`; this strengthens cross-reference evidence without changing the unresolved final `MapPane` split caveat.
- 2026-06-12 C001 Batch C001-018: Added [UID:0003IS][0x0061e908-0x0061e924.GameServerConfigNeighborhoodString](by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md) as an exact class-owned parser literal. Score remains `85/86`.
- 2026-06-12 A003 Batch326: Added exact read-only vtable child [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md) after splitting the old mixed [UID:0002SP][0x0061e704-0x0061e71c.GameServerConfigVtableData](by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md) container. Score remains `85/86`; the update clarifies direct class ownership without changing the broader `GameServerConfig.cpp` versus private `MapPane.cpp` caveat.
- 2026-05-28: Added `0x00503960-0x005039ed` as an adjacent raw packet-helper candidate rather than a confirmed class method. Evidence: IDA MCP shows the same fixed nation-entry request payload behavior as `RequestNationEntries`, but no function object or caller xrefs at `0x00503960`.
- 2026-05-28: Added nation-entry parser/resize support through [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md). Evidence: IDA MCP reports the helper as the sole direct target from the `0x00503d10` nation-entry packet parser and shows 68-byte `GameServerNationEntry` stride behavior.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: nation-table behavior, map-pane initializer caveat, globals, parser/resize support, raw helper caveats, and ownership decisions are well documented, but the class boundary remains medium-confidence. Evidence: memory pages for `0x00503960`, `0x005039f0-0x00504521`, `0x00514d50-0x00514ddc`, and `0x00514ee0-0x00514f6b`, plus global/type/resource cross-references.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE` and replaced broad method rows with exact child by-memory links where IDA MCP verified the boundaries. Evidence: IDA MCP `list_funcs`/raw byte checks found exact function or code-island ranges at `0x005039f0`, `0x00503a50`, `0x00503a80`, `0x00503b60`, `0x00503c70`, `0x00503d10`, and `0x00504110`; the raw destructor end was corrected from `0x00503a78` to `0x00503a7d`.
- 2026-06-02 parent/confidence update:
  - What existed before: confidence remained `78` and `AUTOGEN_PARENT_UID` was blank.
  - Changed to: `CONFIDENCE:80` and `AUTOGEN_PARENT_UID:0000JP`.
  - Evidence: [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) is now placed under `NexusTK/map/` using the proposed source tree, and this class page links exact IDA-backed raw constructor/destructor, lookup/request/parser, map-initializer, global, type, and resource evidence. The score is only 80 because final source ownership may split some initializer code into [UID:0000L3][MapPane](by-file/MapPane.md).
- 2026-06-10 A002 strict-gate repair:
  - What existed before: `AUTOGEN_PARENT_UID:0000JP` attached this class to the GameServerConfig file page.
  - Changed to: `AUTOGEN_PARENT_UID:` blank with the score left at `82/80`.
  - Evidence at that time: the class was below the child side of the strict `85/85` gate, and the direct file parent [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) was `86/80`, so the parent side also failed confidence. This note is superseded by the later gate refresh that restored class-to-file attachment after both pages cleared `85/85`.
