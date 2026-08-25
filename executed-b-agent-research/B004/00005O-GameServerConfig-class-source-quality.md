** TARGET-REPORT-UID:00005O **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Source-Quality Report: UID 00005O GameServerConfig

FINISHED

Target: [UID:00005O] `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\GameServerConfig.md`

Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\00005O-GameServerConfig-class-source-quality.md`

Report-only scope: this pass did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

## Summary Recommendation

Keep `GameServerConfig` attached to [UID:0000JP][GameServerConfig](../../../../../by-file/GameServerConfig.md) under the `NexusTK/map/` source route. The class is a map/gameplay nation-entry table class, not a general settings/config module and not the owner of `MapPane::MapPane`.

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `87` |
| `CONFIDENCE` | `86` | `89` |
| `CANONICAL_OWNER` | `0000JP` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | `0000JP` | unchanged |
| `RECONSTRUCTION_CPP` | blank | keep blank on this class page |

Why raise score: the remaining uncertainty has narrowed. A fresh PE route scan reconfirms that raw starts `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` have no direct rel32 caller and no VA/RVA/raw-offset pointer route, while live modeled methods retain the expected caller sets. Support pages now resolve `0x00504110` as `MapPane::MapPane`, `0x00514ee0` as concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int)`, and `g_activeMapPane` as MapPane-owned alias pollution rather than GameServerConfig state.

Why not higher: the class formal C++ still should not be emitted. Several class-facing methods are source-shaped but intentionally child-owned or no-route raw islands, and the final header/class declaration shape is still not stable enough to encode on the class hub without creating misleading public API/source layout.

## Evidence Checked

Rules and assignment context checked:

- `tools/leaser/Agents/Supervisor.md`, including B-agent report-only workflow, Rule 26 source-quality standard, and coverage-report ownership rules.
- `.codex/AGENTS.md`, including the same report-only and no-coverage-edit constraints.
- `tools/leaser/Agents/Agent-B004/goal.md` and `notes.md`, including B004 report-only folder scope and code-entry gate reminders.

Target and direct support docs checked:

- [UID:00005O][GameServerConfig](../../../../../by-class/GameServerConfig.md)
- [UID:0000JP][GameServerConfig](../../../../../by-file/GameServerConfig.md)
- [UID:0000L3][MapPane](../../../../../by-file/MapPane.md)
- [UID:00007Q][MapPane](../../../../../by-class/MapPane.md)
- [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](../../../../../by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md)
- [UID:0001UP][GameServerNationEntry](../../../../../by-type/by-struct/GameServerNationEntry.md)
- [UID:0001WR][ProtectedArrayTemplates](../../../../../by-type/by-template/ProtectedArrayTemplates.md)
- [UID:0001VM][ProtectedArrayLayout](../../../../../by-type/by-struct/ProtectedArrayLayout.md)
- [UID:0000Q1][g_gameServerNationTable](../../../../../by-global/g_gameServerNationTable.md)
- [UID:0000PR][g_activeMapPane](../../../../../by-global/g_activeMapPane.md)
- [UID:0000Q3][g_objectNationMap](../../../../../by-global/g_objectNationMap.md)
- [UID:0000Q4][g_objectRecordCount](../../../../../by-global/g_objectRecordCount.md)
- [UID:0001RL][SOBJ.TBL](../../../../../by-resource/sobj-tbl.md)

Child memory pages checked:

- [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](../../../../../by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md)
- [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](../../../../../by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md)
- [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](../../../../../by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md)
- [UID:0002HX][0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback](../../../../../by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md)
- [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](../../../../../by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md)
- [UID:0002HZ][0x00503c70-0x00503d03.GameServerConfigRequestNationEntries](../../../../../by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md)
- [UID:0002I0][0x00503d10-0x00503e77.GameServerConfigParseNationEntries](../../../../../by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md)
- [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](../../../../../by-memory/0x00504110-0x00504521.MapPaneInitialize.md)
- [UID:0001B4][0x00514d50-0x00514ddc.GameServerNationTableDelete](../../../../../by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md)
- [UID:000374][0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor](../../../../../by-memory/0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md)
- [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](../../../../../by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md)
- [UID:0003IJ][0x0061e708-0x0061e718.GameServerConfigClassVtableData](../../../../../by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md)
- [UID:0003II][0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData](../../../../../by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md)
- [UID:0003C3][0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString](../../../../../by-memory/0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md)
- [UID:0003IS][0x0061e908-0x0061e924.GameServerConfigNeighborhoodString](../../../../../by-memory/0x0061e908-0x0061e924.GameServerConfigNeighborhoodString.md)
- [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](../../../../../by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md)

Generated/current output checked:

- `source-3/simroot_v2/class_GameServerConfig.cpp`
- `project-documentation/auto-generated/NexusTK/map/GameServerConfig.cpp`
- `project-documentation/auto-generated/-ag-class-coverage.md`
- `project-documentation/auto-generated/-ag-file-coverage.md`
- `project-documentation/auto-generated/-ag-memory-coverage.md`
- `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-memory/-coverage-report.md` for current rows only. No coverage file was edited.

Fresh PE scan:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Relevant sections: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`
- Scan method: local Python PE parser over the executable bytes; for each target VA, mapped VA to file offset, read first 16 bytes, scanned `.text` for direct `E8`/`E9` rel32 calls/jumps, and scanned the full image for dwords equal to target VA, target RVA, and target file offset. Also scanned direct dword-byte references to the relevant globals/vtables.

Fresh PE scan key output:

| Target | File offset | First bytes | Route result |
| --- | ---: | --- | --- |
| raw packet helper `0x00503960` | `0x102d60` | `55 8b ec 83 ec 44 a1 24 2f 67 00 33 c5 89 45 fc` | no rel32 caller; no VA/RVA/raw-offset pointer hit |
| raw constructor `0x005039f0` | `0x102df0` | `55 8b ec 51 56 8b f1 89 75 fc e8 81 10 ff ff 8d` | no rel32 caller; no VA/RVA/raw-offset pointer hit |
| raw destructor `0x00503a50` | `0x102e50` | `56 8b f1 c7 06 0c e7 61 00 ff 76 0c c7 46 04 04` | no rel32 caller; no VA/RVA/raw-offset pointer hit |
| modeled lookup `0x00503a80` | `0x102e80` | normal stack-cookie prologue | rel32 callers `0x005b9318`, `0x005be746` |
| raw seeder `0x00503b60` | `0x102f60` | `55 8b ec 51 53 56 8b f1 bb 02 00 00 00 57 8b 46` | no rel32 caller; no VA/RVA/raw-offset pointer hit |
| modeled request `0x00503c70` | `0x103070` | normal stack-cookie prologue | rel32 callers `0x005a5029`, `0x005a5dcc`, `0x005b92fe`, `0x005be72c` |
| modeled parser `0x00503d10` | `0x103110` | normal parser prologue | rel32 caller `0x00507d00` |
| MapPane constructor `0x00504110` | `0x103510` | normal EH constructor prologue | rel32 callers `0x004f7dfa`, `0x004f85ef` |
| scalar deleting destructor `0x00514d80` | `0x114180` | destructor prologue | one VA dword hit at `0x0061e70c` vtable slot |
| resize `0x00514ee0` | `0x1142e0` | resize prologue | rel32 caller `0x00503d4f` |

Fresh global/vtable direct dword hit counts:

| Storage | Direct dword hits | Samples / interpretation |
| --- | ---: | --- |
| `g_activeMapPane` `0x0067a764` | `360` | high-fanout active MapPane singleton, not GameServerConfig |
| `g_objectRecordCount` `0x0069b4bc` | `5` | MapPane compact `SOBJ.TBL` loader/consumer |
| `g_objectNationMap` `0x0069b4c0` | `6` | MapPane compact object-nation byte cache |
| `g_gameServerNationTable` `0x0069b4c4` | `18` | GameServerConfig nation-table singleton |
| `GameServerConfig` vtable `0x0061e70c` | `4` | constructor/destructor/MapPane allocation/destructor stores |
| `ProtectedArray<GameServerConfig::NationEntry>` vtable `0x0061e704` | `5` | constructor/destructor/MapPane allocation/protected-array destructor stores |

## Heuristic / Inference Reanalysis And Validation

### Class And Source Name

Best-supported source-facing class name: `GameServerConfig`.

Evidence:

- The class vtable child records the `GameServerConfig` complete-object-locator and vtable slots at `0x0061e708-0x0061e718`.
- The outer vtable slot at `0x0061e70c` points to the exact `GameServerConfig` scalar deleting destructor at `0x00514d80`.
- Constructor/destructor-shaped code stores the same vtable at `0x00503a16`, `0x00503a53`, `0x00504478`, and `0x00514d86`.
- The `GameServerConfig::NationEntry` generated spelling is supported by protected-array RTTI/vtable naming and by the exact protected-array vtable child.

Rejected alternative: a generic `Config` or registry/settings owner. The table stores nation-entry records, sends opcode `0x66` nation-entry requests, parses packet-provided labels, is allocated during map startup, and is consumed by user/status presentation. It has no evidence tying it to the general `config/` module.

Rejected alternative: rename the class to `GameServerNationTable` in docs now. That name describes behavior well, but current RTTI/vtable evidence supports `GameServerConfig` as the compiler-visible class name. Use `GameServerNationTable` only as explanatory role wording unless later type descriptors prove a different original name.

### GameServerConfig / MapPane Split

Final ownership split:

- `GameServerConfig` owns the nation-entry class, `g_gameServerNationTable`, `GameServerConfig::NationEntry`, lookup/fallback, request, parser, fallback/default literals, raw constructor/destructor/seeder evidence, and class vtable data.
- `MapPane` owns the live map-pane constructor/destructor, `g_activeMapPane`, compact `SOBJ.TBL` object-nation cache globals, and the `MapPane` field state initialized at `0x00504110`.
- `MapPane::MapPane` allocates the `GameServerConfig` table object as a dependency during map startup; that allocation does not make the entire constructor a GameServerConfig method.

Evidence:

- `0x00504110` has MapPane vtable stores, `g_activeMapPane` publication, base/member construction, visible-tile parameter storage, compact `SOBJ.TBL` loading, root/back-pane registration, overlay allocation, and final effect-list clears.
- Fresh PE scan confirms `0x00504110` has exactly the two expected rel32 construction callers `0x004f7dfa` and `0x004f85ef`.
- [UID:0002I7] already contains first-draft C++ as `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`.
- `g_activeMapPane` has `360` direct dword-byte hits in the binary, matching broad active-map singleton behavior and rejecting `g_activeGameServerConfig`.

Rejected alternative: keep the old generated `GameServerConfig::InitializeMapPane` name. This was Wave3 owner pollution from the embedded `g_gameServerNationTable` allocation. The constructed receiver is MapPane and the active singleton is MapPane.

### Nation-Entry Table Ownership

Best-supported source-level object model:

```cpp
class GameServerConfig : public LObject {
public:
    struct NationEntry {
        unsigned short nationId;
        wchar_t label[33];
    };

private:
    ProtectedArray<GameServerConfig::NationEntry> m_nationEntries;
};

static GameServerConfig* g_gameServerNationTable;
```

This is a source model for reasoning only; do not emit this class skeleton yet from the target page.

Layout evidence:

- `GameServerConfig` object allocation size in `MapPane::MapPane` is `0x58` / 88 bytes.
- `LObject` base occupies the leading object area; embedded protected-array member starts at `this+4`.
- The protected-array concrete object has vtable at `+0x00`, `m_count` at `+0x04`, `m_entries` at `+0x08`, provisional `m_reservedCount` / `m_defaultCapacity` at `+0x0c`, and inline fallback/default entry at `+0x10`.
- `GameServerConfig::NationEntry` is exactly `0x44` / 68 bytes: `uint16_t nationId` at `+0x00`, `wchar_t label[33]` at `+0x02`.
- The raw constructor initializes default `nationId = -1`, count `0`, entries `NULL`, and `+0x0c = 10`.
- The resize helper allocates `68 * count`, initializes each new record's first word to `-1`, copies `min(oldCount,newCount) * 68`, frees old storage, then updates entries/count.

The `+0x0c` protected-array field should not be called ordinary live capacity. The reviewed resize/accessor/destructor bodies do not update or test it. The safest names remain `m_reservedCount` or `m_defaultCapacity`.

### Raw Packet Helper `0x00503960`

Best-supported name: file-local `SendGameServerNationEntryRequestPacket()`.

Evidence:

- Fixed packet bytes: `66 40 00 01 01 00 01 01 00`.
- Helper uses `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `Socket *g_packetSender`, and `QueueAndSendPacket(..., length 9)`.
- Fresh PE scan again found no direct rel32 caller and no VA/RVA/raw-offset pointer route to `0x00503960`.
- Positive controls in the same scan found expected callers for modeled methods and one vtable pointer for the destructor, so the no-route result is meaningful.

Decision: keep this as a reconstructable file-local support helper under [UID:0000JP], not a confirmed class method. The current emitted body in `auto-generated/NexusTK/map/GameServerConfig.cpp` is appropriate.

Rejected alternative: merge it into `GameServerConfig::RequestNationEntries`. The modeled request method has four rel32 callers and the `this+0x08` empty-table guard; this raw helper has no caller route and lacks the guard.

### Raw Constructor `0x005039f0`

Best-supported source role: constructor-shaped `GameServerConfig::GameServerConfig()` initialization island, but no emitted C++ yet.

Evidence:

- Valid body starts with a normal prologue, calls `LObject` construction, stores `g_gameServerNationTable`, writes the `GameServerConfig` and protected-array vtables, initializes protected-array fields, and returns `this`.
- Fresh PE scan found no direct rel32 caller and no VA/RVA/raw-offset pointer route to `0x005039f0`.
- The same initialization sequence is repeated inline in `MapPane::MapPane` when it allocates the `0x58` table object.

Decision: describe as raw constructor-shaped source-owned code, not `InitializeNationEntryTable()` as final source name. Keep C++ blank until a route or a deliberate constructor-declaration policy is accepted.

Rejected alternative: treat it as padding or compiler-only residue. It is real source-shaped object initialization and matches live allocation/destructor behavior.

### Raw Destructor `0x00503a50`

Best-supported source role: non-deleting `GameServerConfig::~GameServerConfig()` cleanup island, but no emitted C++ yet.

Evidence:

- Writes the outer and embedded protected-array vtables, frees the entry backing buffer, clears `g_gameServerNationTable`, and tail-jumps to base `LObject` cleanup.
- Exact range must include the tail jump: `0x00503a50-0x00503a7d`.
- Fresh PE scan found no direct rel32 caller and no VA/RVA/raw-offset pointer route to `0x00503a50`.
- Modeled scalar deleting destructor `0x00514d80` repeats the same cleanup relationship and is reached through the vtable slot.

Decision: retain as reconstructable raw cleanup evidence. Do not emit a standalone source body until route/function modeling is resolved or a constructor/destructor declaration policy covers it.

### Lookup / Fallback Method `0x00503a80`

Best-supported signature direction:

```cpp
GameServerConfig::NationEntry* GameServerConfig::CopyNationEntryOrFallback(
    GameServerConfig::NationEntry* destination,
    int nationId);
```

Evidence:

- Fresh PE scan found rel32 callers `0x005b9318` and `0x005be746`.
- Method scans `this+0x08` count and `this+0x0c` entries using `0x44` stride.
- Match path copies a full 68-byte record to the caller buffer.
- Fallback path writes id `0`, copies the UTF-16 `????` literal, and returns the caller-provided buffer.
- Historical Wave2 context says this was restored as `GameServerConfig::CopyNationEntryOrFallback`; current status/user paint docs support use from user/status presentation.

Decision: keep the generated method name as a high-probability source-facing name for now because it exactly describes the side effect and fallback behavior. If later caller-side names prove the original API was `GetNationEntry` or `CopyNationEntry`, the `OrFallback` suffix can be shortened; current evidence favors preserving the explicit fallback role.

No-code reason for this child remains local, not class-level: final destination type and caller-side public API naming are not yet complete enough for emitted child C++.

### Raw Default Seeder `0x00503b60`

Best-supported role: retained no-route helper for seeding two default nation entries.

High-probability source-facing names:

- `SeedDefaultNationEntries()`
- `InitializeDefaultNationEntries()`

Evidence:

- Fresh PE scan found no rel32 caller and no VA/RVA/raw-offset pointer route to `0x00503b60`.
- Body allocates/resizes for two `0x44` records, initializes ids to `-1`, preserves old prefix, frees old storage, then writes ids `1` and `2`.
- It looks up localized string-table ids `0x9f` and `0xa0` and copies into 33-wide-character label buffers.
- It inlines the same positive-count resize behavior as `ProtectedArray<T>::Resize`.

Decision: keep as raw helper evidence and do not emit C++. The exact localized meanings of ids `0x9f` and `0xa0` are not recoverable from the checked class/global/resource docs; use generic default-entry wording unless string-table evidence is added.

Rejected alternative: a general allocation helper. The hard-coded two records, nation ids, localized labels, and `GameServerConfig::NationEntry` stride make it feature-specific.

### Request Method `0x00503c70`

Best-supported signature:

```cpp
void GameServerConfig::RequestNationEntries();
```

Evidence:

- Fresh PE scan found rel32 callers `0x005a5029`, `0x005a5dcc`, `0x005b92fe`, and `0x005be72c`.
- Historical Wave2 notes identify callers in `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint`, and `SayToPlanMessageInputPane::ProcessDeferredSendState`.
- Body checks `this+0x08` table count, then sends the same nine-byte packet as the raw file-local helper.

Decision: keep `RequestNationEntries()` as source-facing member name. Current child C++ should remain blank until final member declaration and count-field naming are accepted, but the file-local helper emitted by [UID:000230] can be called from a future draft.

Rejected alternative: raw helper owns the live behavior. The modeled method has four callers and the correct lazy-cache guard.

### Parser Method `0x00503d10`

Best-supported signature direction:

```cpp
void GameServerConfig::ParseNationEntries(PacketBuffer* packet);
```

Evidence:

- Fresh PE scan found rel32 caller `0x00507d00` inside the MapPane packet dispatcher route.
- Body checks packet availability, reads count byte at packet offset `+2`, resizes to `count + 1`, parses per-entry id/label pairs, converts byte strings to wide labels, and overwrites the final slot with id `10` and literal `Neighborhood`.
- Sole direct resize caller at `0x00503d4f` passes `ecx = this + 4`, proving the resize target is the embedded protected-array member.

Decision: keep as class-owned packet parser. Final child C++ remains blank because packet field names and opcode schema names are not final. The role and owner are no longer open.

### ProtectedArray Resize `0x00514ee0`

Best-supported source-facing name:

```cpp
void ProtectedArray<GameServerConfig::NationEntry>::Resize(int count);
```

Evidence:

- Fresh PE scan found sole rel32 caller `0x00503d4f`.
- Existing B008 PE/Capstone report and support docs confirm parser passes `ecx = this + 4`, not the outer `GameServerConfig*`.
- Body uses protected-array offsets and 68-byte record stride.
- Current emitted C++ in `auto-generated/NexusTK/map/GameServerConfig.cpp` matches the source shape well.

Decision: this is not a handwritten outer `GameServerConfig` method. It remains in the GameServerConfig output route because the concrete type, caller, and vtable belong to the nation-entry feature. Direct semantic parent stays [UID:0000B4].

Rejected alternatives:

- `GameServerConfig::ResizeNationEntries`: rejected because receiver is the embedded protected-array member.
- `Reserve` / `EnsureCapacity`: rejected because it writes requested `count` to `m_count`, and `count <= 0` is a no-op rather than a clear/free.
- MemoryMan wrapper: rejected because the body is typed container resize and uses allocation/copy/free as implementation details.

### Scalar Deleting Destructor `0x00514d80`

Source role: compiler-generated scalar deleting destructor wrapper for `GameServerConfig`.

Evidence:

- Exact vtable slot at `0x0061e70c`.
- Body restores outer/embedded vtables, frees entries, clears `g_gameServerNationTable`, calls `LObject` cleanup, and conditionally deletes object storage according to scalar-delete flags.
- Fresh PE scan found one VA dword hit at the vtable slot and no rel32 callers, which is expected for virtual destructor dispatch.

Decision: direct semantic owner remains [UID:00005O]. Do not hand-author this as ordinary C++ method body; reconstruct normal destructor/class semantics and let the compiler generate wrapper glue.

### Globals And Alias Pollution

Resolved global directions:

| Storage | Best name | Owner | Evidence |
| --- | --- | --- | --- |
| `0x0069b4c4` | `g_gameServerNationTable` | GameServerConfig / [UID:0000JP] | 18 direct dword hits across constructor/destructor, MapPane allocation/cleanup, status/user consumers, request/lookup paths |
| `0x0067a764` | `g_activeMapPane` | MapPane / [UID:0000L3] | 360 direct dword hits, MapPane constructor/cleanup lifecycle, minimap/weather/UI consumers |
| `0x0069b4c0` | `g_objectNationMap` | MapPane compact `SOBJ.TBL` cache | 6 direct hits in loader/cleanup/consumer |
| `0x0069b4bc` | `g_objectRecordCount` | MapPane compact `SOBJ.TBL` cache | 5 direct hits in loader/count consumer |

Decision: reject `g_activeGameServerConfig` permanently as generated alias pollution. It comes from the stale `GameServerConfig::InitializeMapPane` attribution. `g_activeMapPane` is a broad live map singleton and should not be routed through this class.

### Nation Entry Type

Best-supported declaration spelling inside source:

```cpp
struct GameServerConfig::NationEntry {
    unsigned short nationId;
    wchar_t label[33];
};
```

Evidence:

- `0x44` stride in lookup, parser, seeder, and resize.
- First field is a 16-bit id compared/written by lookup/parser/seeder.
- Label capacity is `0x21` wide characters.
- Fallback literal `????` and final parser literal `Neighborhood` are both direct class-owned string children.

Open-source-name closure: `GameServerNationEntry` is a good documentation/file name, while `GameServerConfig::NationEntry` is the strongest current C++ declaration spelling because the protected-array RTTI/source route uses the nested spelling. Do not promote it to a standalone generic record outside the GameServerConfig table without header/source evidence.

### SOBJ.TBL Split

Final split:

- `StaticObjImageLib` owns the full static-object render metadata parser.
- `MapPane::MapPane` owns the compact `g_objectRecordCount` / `g_objectNationMap` loader/cache.
- `GameServerConfig` owns the separate nation-entry table allocated by MapPane startup, not the compact SOBJ byte cache itself.

Evidence:

- `SOBJ.TBL` support page documents the two parser views over the same resource.
- Package parse confirms count `19,551`, header `0x0001`, first `485` sentinel `0xffffffff` records, first non-sentinel index `485`, and word-count range `0..12`.
- Fresh PE scan confirms `g_objectRecordCount` and `g_objectNationMap` direct hit counts are localized to loader/cleanup/consumer paths, while `g_gameServerNationTable` has a broader nation-table consumer set.

Rejected alternative: assign the full resource schema to GameServerConfig. GameServerConfig only depends on MapPane construction and user/status nation-entry data; the static-object render schema remains elsewhere.

### Vtables, RTTI, Literals, And Compiler-Generated Names

Best-supported generated-name handling:

- `GameServerConfigClassVtableData`: generated by the class declaration. Do not hand-author the dwords.
- `GameServerNationEntryProtectedArrayVtableData`: generated by the concrete protected-array declaration. Do not hand-author the dword.
- `GameServerConfigNationFallbackString`: source literal `L"????"` in lookup fallback path.
- `GameServerConfigNeighborhoodString`: source literal `L"Neighborhood"` in parser final slot.
- `ScalarDeletingDestructor`: compiler wrapper. Keep as documentation evidence, not ordinary handwritten source.
- `InitializeNationEntryTable`: generated/historical label. Prefer constructor-shaped wording.
- `InitializeMapPane`: generated/historical label. Replace source-facing name with `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`.

## Rejected Alternatives

1. `config/` or registry/settings ownership: rejected by packet, map, nation-entry, and status/user presentation evidence.
2. Full MapPane ownership for `GameServerConfig`: rejected because `GameServerConfig` has its own vtable/COL, scalar destructor, protected-array member, global table, and UI/status consumers. MapPane constructs the table but does not own the class.
3. Full GameServerConfig ownership for `0x00504110`: rejected because the body constructs MapPane and publishes `g_activeMapPane`.
4. `g_activeGameServerConfig` as final name: rejected by 360-hit active MapPane singleton behavior and MapPane lifecycle.
5. Raw packet helper as live member method: rejected by no-route scan and by modeled guarded `RequestNationEntries` callers.
6. Raw constructor/destructor/seeder as emitted bodies now: rejected for C++ emission by no function object, no caller route, and final declaration instability. Retain them as reconstructable raw evidence.
7. `ProtectedArray` resize as outer `GameServerConfig` method: rejected because parser passes `this+4` and the body uses protected-array fields.
8. Hand-authored vtable/COL data: rejected because compiler should regenerate them from declarations.
9. Scalar deleting destructor as ordinary source method: rejected because it is compiler-generated destructor glue.

## Open-Question Closure

No generic future-work questions should remain on the class page after implementation. The remaining limitations are specific and bounded:

- Exact physical source file `map/GameServerConfig.cpp` versus private `map/MapPane.cpp` helper placement cannot be proven from binary alone. Highest-probability and current canonical route remains `map/GameServerConfig.cpp` because the class has independent RTTI/vtable identity and non-MapPane status/user consumers.
- Raw starts `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` cannot be promoted to live callable methods after fresh rel32/VA/RVA/raw-offset scans found no route. Preserve them as retained source-shaped code islands with explicit no-route proof.
- Localized string ids `0x9f` and `0xa0` in the raw seeder cannot be semantically named from the checked docs/binary. Keep `default nation-entry labels` wording until a string-table pass maps those ids.
- Packet selector bytes after opcode `0x66` / subcode `0x4000` cannot be safely named from client-side evidence. Keep explicit constants or byte writes.
- A formal class declaration is not ready for class-page C++ because final header/API naming, constructor route policy, and child method body ownership are still being synchronized.

## First-Draft C++ Recommendation

Do not emit new first-draft C++ from the target `by-class/GameServerConfig.md` page now.

Target-specific no-code/defer proof:

- The class page clears the mechanical code-entry gate (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, average score above 85), but this page is a class hub rather than a single source body.
- Current generated output already places eligible support bodies in `auto-generated/NexusTK/map/GameServerConfig.cpp`: [UID:000230] file-local `SendGameServerNationEntryRequestPacket()` and [UID:000234] concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int)`.
- The old simroot body for `GameServerConfig::InitializeMapPane` is wrong-owner output; the accepted source body now lives on [UID:0002I7] as `MapPane::MapPane`.
- The raw constructor/destructor/seeder have no route to their starts and should not be emitted as standalone C++ methods.
- `CopyNationEntryOrFallback`, `RequestNationEntries`, and `ParseNationEntries` are live class methods but their exact child pages still block emitted C++ on packet schema/caller-side API naming, not on class ownership.
- `0x00514d80` and vtable data are compiler-generated output from normal class/destructor declarations, not hand-authored class-page code.

Implementation callback policy: keep the target C++ block blank / empty emitter marker. Do not remove already emitted child/support bodies. If a later callback chooses to add a declaration-only header sketch, it should be done as a project-level class declaration policy, not as an opportunistic body on this class page.

## Implementation Checklist For Later Callback

Target page edits:

- Update [UID:00005O][GameServerConfig](../../../../../by-class/GameServerConfig.md) metadata to `COMPLETION:87`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000JP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JP`.
- Keep `RECONSTRUCTION_CPP` blank.
- Add a B004 source-quality section or update existing sections with the findings in this report:
  - `GameServerConfig` is the compiler-supported class name, while the role is map/game-server nation table.
  - `0x00504110` is `MapPane::MapPane`, not `GameServerConfig::InitializeMapPane`.
  - `g_activeMapPane` is MapPane-owned alias pollution, not GameServerConfig state.
  - `g_gameServerNationTable` is the GameServerConfig singleton/table pointer.
  - `g_objectRecordCount` and `g_objectNationMap` stay MapPane compact SOBJ cache state.
  - `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` are no-route raw islands after PE scan.
  - `0x00503a80`, `0x00503c70`, `0x00503d10`, `0x00504110`, and `0x00514ee0` have the caller sets listed above.
  - `0x00514ee0` is the concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int)` specialization, not an outer class method.
  - Class-level C++ remains blank with the target-specific no-code proof above.

Support docs to synchronize:

- [UID:0000JP][GameServerConfig](../../../../../by-file/GameServerConfig.md): add a short B004 class-level source-quality change note if accepted, especially the fresh PE route scan, class score change, and continued `GameServerConfig.cpp` canonical route.
- [UID:0000L3][MapPane](../../../../../by-file/MapPane.md) and [UID:00007Q][MapPane](../../../../../by-class/MapPane.md): no required content change; existing lifecycle split already covers this evidence. Add only if the supervisor wants a cross-reference note.
- [UID:0000Q1][g_gameServerNationTable](../../../../../by-global/g_gameServerNationTable.md): no required content change; it already records 18 refs and the correct source owner. Optional note can cite this fresh PE scan.
- [UID:0000PR][g_activeMapPane](../../../../../by-global/g_activeMapPane.md): no required content change; alias pollution already resolved.
- [UID:0000Q3][g_objectNationMap](../../../../../by-global/g_objectNationMap.md) and [UID:0000Q4][g_objectRecordCount](../../../../../by-global/g_objectRecordCount.md): no required content change; existing MapPane ownership is correct.
- [UID:0001UP][GameServerNationEntry](../../../../../by-type/by-struct/GameServerNationEntry.md): no required content change; current nested-spelling/default-constructor guidance remains correct.
- [UID:0000B4][ProtectedArray_struct_GameServerConfig__NationEntry_](../../../../../by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md), [UID:0001WR][ProtectedArrayTemplates](../../../../../by-type/by-template/ProtectedArrayTemplates.md), and [UID:0001VM][ProtectedArrayLayout](../../../../../by-type/by-struct/ProtectedArrayLayout.md): no required content change from this class report; B008 already incorporated the resize specialization.
- `project-documentation/auto-generated/NexusTK/map/GameServerConfig.cpp`: expected to remain functionally unchanged unless score metadata comments change. Current emitted bodies [UID:000230] and [UID:000234] should remain.
- `project-documentation/auto-generated/-ag-class-coverage.md`, `-ag-file-coverage.md`, and `-ag-memory-coverage.md`: validator may refresh metadata after target/support edits. Do not edit manually.

Coverage files:

- Do not edit `by-memory/-coverage-report.md`.
- Supervisor-owned target coverage row is in `by-class/-coverage-report.md`.
- No `by-memory/-coverage-report.md` replacement row is required for this class-only report.

## Exact Supervisor-Owned Coverage Row Text

Current exact target row in `by-class/-coverage-report.md`:

```markdown
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) : reconstructable : 85% : strong : Map/nation-table helper class now attached to [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) after the strict `85/85` gate cleared; exact constructor/destructor, lookup/fallback, default seeder, request, parser, resize, raw helper, global, type, protected-array, SOBJ.TBL, and MapPane split evidence are documented.
```

Recommended replacement row:

```markdown
- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) : reconstructable : 87% : strong : B004 2026-06-19 source-quality reanalysis keeps [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) as the map/nation-entry owner/emitter, closes the generated `GameServerConfig::InitializeMapPane` pollution as [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) / `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`, preserves `g_activeMapPane` under MapPane and `g_gameServerNationTable` under GameServerConfig, confirms raw `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` have no rel32/VA/RVA/raw-offset route while modeled lookup/request/parser/MapPane-constructor/resize caller sets remain live, routes [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md) as concrete `ProtectedArray<GameServerConfig::NationEntry>::Resize(int)` rather than an outer method, and keeps class-level C++ blank while emitted support bodies remain the file-local nation request helper and ProtectedArray resize specialization.
```

## Validator Baseline And Commands

Scoped validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [00005O-GameServerConfig-class-source-quality-removed.md](00005O-GameServerConfig-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Working directory:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Result:

```text
Exit code: 0
ok: 1
```

Relevant output line:

```text
ok           00005O by-class/GameServerConfig.md UID header exists
```

Implementation callback validator commands if only the target page is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00005O-GameServerConfig-class-source-quality-removed.md](00005O-GameServerConfig-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation callback validator commands if the file-level support page is also edited:

> Executable block R003 was removed from this report and preserved verbatim in [00005O-GameServerConfig-class-source-quality-removed.md](00005O-GameServerConfig-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Report-Only Confirmation

- Report file created at the required path.
- No `by-*` documentation file was edited in this report-only pass.
- `by-memory/-coverage-report.md` was not edited.
- `by-class/-coverage-report.md` and other coverage files were not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00005O-GameServerConfig-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00005O"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005O-GameServerConfig-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00005O-GameServerConfig-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
