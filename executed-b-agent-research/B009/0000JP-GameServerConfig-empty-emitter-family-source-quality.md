** TARGET-REPORT-UID:0000JP **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000JP] GameServerConfig Empty-Emitter Family Source-Quality Report

Assignment: `B009-report-0000JP-GameServerConfig-empty-emitter-family-20260701`  
Agent: B009  
Mode: report-only research. No `by-*`, generated, coverage, validator-state, archive, supervisor-ledger, or IDA DB files were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000JP] `by-file/GameServerConfig.md` as the canonical `NexusTK/map/GameServerConfig.cpp` owner for the map/game-server nation-entry table family, and resolve the current empty-emitter markers with first-draft C++ for the source-bearing class/method/raw lifecycle helpers plus formal no-duplicate comments for the type/support wrapper pages.
- Final disposition: no split, rename, or owner move is needed. The old blanket "blank until exact original names/route" policy is now too conservative for this empty-emitter family. Current live MCP confirms exact function/range facts, xrefs, bytes, and literals; lack of original symbol spelling or raw-start xrefs should cap confidence, not block draft source where behavior and source route are source-shaped.
- Required action if accepted: update the nine visible current empty markers in `auto-generated/NexusTK/map/GameServerConfig.cpp` and the by-file/class support notes at report-level detail. The goal/queue row says `13` total, `3` filled, `10` empty, but the current generated file inspected from validator command `000000003794` shows `3` filled and `9` visible empty markers; preserve this count discrepancy as a generated/tracker freshness note.
- Confidence: high for ownership, source placement, function boundaries, concrete record layout, packet constants, global/vtable/literal evidence, and first-draft code readiness; medium-high for final private field/member names and raw constructor/destructor/seeder reachability.

## Target

- Target UID: `0000JP`
- Target path: `by-file/GameServerConfig.md`
- Generated output lead: `auto-generated/NexusTK/map/GameServerConfig.cpp`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`
- Current queue row in `goal.md`: `13` total emitters, `3` filled, `10` empty, `23.1%`.
- Current generated header checked: `validator-command-id: 000000003794`, `validator-refreshed-at: 2026-07-01T07:34:13-04:00`.
- Current generated visible output: filled [UID:000234] `ProtectedArray<GameServerConfig::NationEntry>::Resize(int count)`, [UID:0000Q1] `static GameServerConfig *g_gameServerNationTable = nullptr;`, and [UID:000230] `static void SendGameServerNationEntryRequestPacket()`. Empty markers visible: [UID:00005O], [UID:0002HV], [UID:0002HW], [UID:0002HX], [UID:0002HY], [UID:0002HZ], [UID:0002I0], [UID:0001UP], and [UID:0000B4].

## Current Target State

- [UID:0000JP] is currently `COMPLETION:87`, `CONFIDENCE:86`, `CANONICAL_OWNER:FILE`, path `NexusTK/map/`, with no formal file-level C++ block.
- [UID:00005O] `GameServerConfig` is currently `87/89`, owner/emitter [UID:0000JP], reconstructable, but formal class C++ is blank.
- The modeled method pages [UID:0002HX], [UID:0002HZ], and [UID:0002I0] are `85/90`, owner/emitter [UID:00005O], reconstructable, but formal C++ is blank because older notes deferred final field/packet names.
- The raw constructor/destructor/seeder pages [UID:0002HV], [UID:0002HW], and [UID:0002HY] are `85/88`, owner/emitter [UID:00005O], reconstructable, but formal C++ is blank because IDA has no function objects or direct raw-start xrefs.
- [UID:0001UP] `GameServerNationEntry` is `86/90`, owner/emitter [UID:00005O], reconstructable, with a source-shaped layout already present in prose but blank formal C++.
- [UID:0000B4] `ProtectedArray_struct_GameServerConfig__NationEntry_` is `87/90`, owner/emitter [UID:0000JP], reconstructable, with source-template/specialization evidence but blank formal C++.

## Evidence Checked

- Required workflow/read gates: `ntk-b-agent-workflow` `SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, `references/score-blocker-audit-standard.md`, `references/b-agent-report-template.md`, `by-structure.md` -> `IDA MCP Output Discipline`, B009 `goal.md`, B009 `notes.md`.
- Target/generated docs: `by-file/GameServerConfig.md`; `auto-generated/NexusTK/map/GameServerConfig.cpp`; `auto-generated/-ag-research-tracker.md`.
- In-scope empty target docs: [UID:00005O], [UID:0002HV], [UID:0002HW], [UID:0002HX], [UID:0002HY], [UID:0002HZ], [UID:0002I0], [UID:0001UP], [UID:0000B4].
- Filled source-shape support docs: [UID:000234] `GameServerNationEntryArrayResize`, [UID:0000Q1] `g_gameServerNationTable`, [UID:000230] `GameServerNationRequestPacketRawHelper`, [UID:000374] `GameServerConfigScalarDeletingDestructor`.
- Additional support docs searched/read as needed: `ProtectedArray`, `ProtectedArrayTemplates`, `ProtectedArrayLayout`, `g_pLanguageMan`, packet helper docs/resolved aliases, LanguageMan lookup helper notes.
- Existing reports searched with terms: `TARGET-REPORT-UID:0000JP`, `GameServerConfig-empty-emitter-family`, `GameServerConfig`, `0000JP`, `00005O`, `0002HV`, `0002HW`, `0002HX`, `0002HY`, `0002HZ`, `0002I0`, `0001UP`, `0000B4`, `005039f0`, `00503a50`, `00503a80`, `00503b60`, `00503c70`, `00503d10`, `GameServerNationEntry`, and `ProtectedArray_struct_GameServerConfig`.
- Matching executed reports opened: B004 `00005O-GameServerConfig-class-source-quality.md`, B003 `000230-GameServerNationRequestPacketRawHelper-source-quality.md`, B008 `000234-GameServerNationEntryArrayResize-source-quality.md`, B003 `0002XS-g_gameServerNationTable-source-quality.md`, and B002 `0002SP-GameServerConfigVtableData-advanced-scan.md`.

## IDA MCP Provenance

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `supervisor_resume_20260629`
- Health: `server_health` returned `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`.
- Schema discipline: used `tools/list` for current schemas; used narrow exact-address `lookup_funcs`, `xrefs_to`, `decompile`, `insn_query`, `get_bytes`, `get_string`, `get_global_value`, capped exact-pattern `find_bytes`, and `int_convert`/project `tools/int_convert.py`. The only oversized call was an initial `disasm` against a no-function address that returned a broad no-function listing; I switched to bounded `insn_query` ranges and do not rely on the oversized portion.

## IDA MCP Facts

- `lookup_funcs` current facts: `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` are not functions; `0x00503a80` is `sub_503A80` size `0xd8` / 216 bytes (Verified with `tools/int_convert.py`); `0x00503c70` is `sub_503C70` size `0x93` / 147 bytes (Verified); `0x00503d10` is `sub_503D10` size `0x167` / 359 bytes (Verified); `0x00504110` is `sub_504110` size `0x411`; `0x00514d50` is size `0x2f`; `0x00514d80` is size `0x5c` / 92 bytes (Verified); `0x00514ee0` is size `0x8b` / 139 bytes (Verified).
- `xrefs_to`: raw starts `0x00503960`, `0x005039f0`, `0x00503a50`, and `0x00503b60` have zero direct xrefs. Modeled `0x00503a80` has callers `0x005b9318` and `0x005be746`; modeled `0x00503c70` has callers `0x005a5029`, `0x005a5dcc`, `0x005b92fe`, and `0x005be72c`; modeled `0x00503d10` has caller `0x00507d00`; resize `0x00514ee0` has sole caller `0x00503d4f`.
- `xrefs_to 0x0069b4c4` returns 18 direct data refs across raw constructor/destructor, MapPane allocation/cleanup, packet/parser route, scalar deleting destructor, status/user/map consumers, request paths, and lookup/fallback consumers.
- `xrefs_to 0x0061e704` returns five refs for `ProtectedArray<GameServerConfig::NationEntry>` vtable stores/use; `xrefs_to 0x0061e70c` returns four refs for `GameServerConfig` vtable stores/use.
- Literal refs: `0x0061e8fc` has one data xref from `0x00503ac7` inside `sub_503A80`; `0x0061e908` has one data xref from `0x00503e5b` inside `sub_503D10`.
- `get_bytes` boundary facts: `0x005039ed-0x005039f0` is `cc cc cc`; `0x00503a42-0x00503a50` is fourteen `0xcc`; `0x00503a7d-0x00503a80` is `cc cc cc`; `0x00503b58-0x00503b60` is eight `0xcc`; `0x00503c61-0x00503c70` is fifteen `0xcc`.
- `get_bytes 0x0069b4c4,4` returns zero bytes. `get_global_value 0x0069b4c4`, `0x0067a7ec`, and `0x0067a750` all return `0x0` current initialized storage.
- `get_bytes 0x0061e8fc,12` is UTF-16 `????` plus null/padding; `get_bytes 0x0061e908,28` decodes as UTF-16 `Neighborhood`. `get_string` renders `0x0061e908` only as `Ne`, so the report relies on raw-byte decoding for the full literal per by-structure string caution.
- Capped `find_bytes` for absolute VA dwords for raw/modeled starts returned zero matches for `60 39 50 00`, `f0 39 50 00`, `50 3a 50 00`, `60 3b 50 00`, `80 3a 50 00`, `70 3c 50 00`, `10 3d 50 00`, and `e0 4e 51 00`. Direct code xrefs are already proven by `xrefs_to` for modeled calls; this capped pattern check mainly rejects hidden data-pointer route assumptions.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best source placement remains `NexusTK/map/GameServerConfig.cpp`, with `GameServerConfig` as a map/gameplay nation-entry table, not a general registry/config class. The file owns `g_gameServerNationTable`, `GameServerConfig::NationEntry`, the lookup/request/parser helpers, the raw lifecycle/seeder source shape, the fallback/default literals, and the concrete `ProtectedArray<GameServerConfig::NationEntry>` route. `MapPane` owns the active map pane, compact `SOBJ.TBL` object-nation cache, and `MapPane::MapPane`; its constructor allocates this object as a dependency.

Rejected placements remain: generic `config/`, full `MapPane` ownership, mixed `.data` aggregate ownership, PacketBuffer/Socket/LanguageMan ownership, and concrete-template generated wrapper ownership. PacketBuffer, Socket, LanguageMan, CRT, and `ProtectedArray<T>` are dependencies or reusable template support, not source owners of the nation-table behavior.

### Empty-Marker Reanalysis

The older no-code blockers are no longer acceptable as written:

- For modeled helpers [UID:0002HX], [UID:0002HZ], and [UID:0002I0], the current binary gives exact modeled functions, callers, callees, layout, constants, literals, and source route. Missing original parameter/member names should produce inferred descriptive names and confidence caps, not blank C++.
- For raw constructor/destructor/seeder pages [UID:0002HV], [UID:0002HW], and [UID:0002HY], current MCP still proves no function objects and no direct xrefs. That negative evidence is real and must be preserved. It is not, by itself, a no-code proof under the current empty-emitter/source-quality rules because each island is complete, source-shaped, range-bounded, class-owned, and mirrored by live inline/lifecycle code. They should receive first-draft source bodies while explicitly preserving the no-function/no-xref caveat.
- For [UID:0001UP], the source-bearing record layout is already documented in prose and used by the emitted resize body. The formal marker should not stay blank. To avoid duplicate declarations, emit the nested record only once through the class page and put a formal no-duplicate comment on the type page.
- For [UID:0000B4], the page is a concrete template-instantiation support wrapper, not an original standalone class named `ProtectedArray_struct_GameServerConfig__NationEntry_`. It should clear the marker with a no-duplicate support comment, while [UID:000234] continues to emit the concrete `Resize(int count)` body and `ProtectedArray` owns reusable template bodies.

### Field / Type Names

Use best inferred names, marked as inferred where needed:

- `GameServerConfig::NationEntry`: `unsigned short nationId; wchar_t label[33];`
- `ProtectedArray<GameServerConfig::NationEntry>` member: `m_nationEntries`
- Protected-array fields in code: `m_count`, `m_entries`, `m_defaultEntry`, and provisional `m_reservedCount` / `m_defaultCapacity` for the `+0x0c` constructor-initialized value `0x0a` / 10 (Verified with `tools/int_convert.py`). Do not call `+0x0c` ordinary current capacity without more evidence; reviewed resize/accessor/destructor bodies do not update/use it.
- Packet/source helpers: `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender->QueueAndSendPacket`, `g_pLanguageMan->GetLocalizedString`, `ProtectedArray<T>::GetAtOrDefault`, and `ProtectedArray<T>::Resize` are supported by current docs and searches.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Current score | Recommended status |
| --- | --- | --- | --- | --- |
| File root | [UID:0000JP] `by-file/GameServerConfig.md` | `map/GameServerConfig.cpp` owner | `87/86` | Raise to `90/91`; record nine visible empty markers resolved by accepted C++/comment actions. |
| Class root | [UID:00005O] `by-class/GameServerConfig.md` | class declaration/support hub | `87/89` | Raise to `90/91`; formal class declaration C++. |
| `0x005039f0-0x00503a42` | [UID:0002HV] | raw constructor-shaped body | `85/88` | Raise to `88/90`; formal first-draft constructor C++. |
| `0x00503a50-0x00503a7d` | [UID:0002HW] | raw ordinary destructor-shaped body | `85/88` | Raise to `88/90`; formal first-draft destructor C++. |
| `0x00503a80-0x00503b58` | [UID:0002HX] | lookup/copy/fallback method | `85/90` | Raise to `89/91`; formal method C++. |
| `0x00503b60-0x00503c61` | [UID:0002HY] | raw default-entry seeder | `85/88` | Raise to `88/90`; formal first-draft seeder C++. |
| `0x00503c70-0x00503d03` | [UID:0002HZ] | guarded request method | `85/90` | Raise to `89/91`; formal method C++ calling existing file-local packet helper. |
| `0x00503d10-0x00503e77` | [UID:0002I0] | packet parser | `85/90` | Raise to `89/91`; formal parser C++. |
| Type page | [UID:0001UP] `by-type/by-struct/GameServerNationEntry.md` | record layout | `86/90` | Raise to `88/91`; formal no-duplicate comment because nested struct emits on [UID:00005O]. |
| Concrete template page | [UID:0000B4] `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md` | concrete `ProtectedArray<NationEntry>` support | `87/90` | Raise to `88/91`; formal no-duplicate comment because source uses `ProtectedArray<GameServerConfig::NationEntry>` and [UID:000234] emits `Resize`. |

## Direct Xref / Caller Inventory

| Address / Item | Current MCP fact | Meaning |
| --- | --- | --- |
| `0x00503960`, `0x005039f0`, `0x00503a50`, `0x00503b60` | zero direct `xrefs_to` and no function objects | Preserve raw/no-route caveat; not a sole blocker for draft source where body is complete and class-owned. |
| `0x00503a80` | callers `0x005b9318`, `0x005be746` | live lookup/fallback method used by status/user presentation paths. |
| `0x00503c70` | callers `0x005a5029`, `0x005a5dcc`, `0x005b92fe`, `0x005be72c` | live guarded request method. |
| `0x00503d10` | caller `0x00507d00` | live map packet-dispatch parser route. |
| `0x00514ee0` | caller `0x00503d4f` | parser resizes embedded `ProtectedArray<NationEntry>` at `this + 4`. |
| `0x0069b4c4` | 18 data refs | singleton/table pointer route, not MapPane active singleton. |
| `0x0061e704`, `0x0061e70c` | protected-array and GameServerConfig vtable refs | compiler-generated layout evidence; source declarations should generate them. |
| `0x0061e8fc`, `0x0061e908` | one literal ref each | `????` fallback and `Neighborhood` final-slot label. |

## First-Draft C++ Recommendation

All snippets below are exact formal `RECONSTRUCTION_CPP CODE` insertion text for the named target if the report is accepted.

### [UID:00005O] `by-class/GameServerConfig.md`

```cpp
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

private:
    ProtectedArray<NationEntry> m_nationEntries;
};
```

Reason: this clears the class marker with a source declaration while not duplicating child method bodies. The nested `NationEntry` declaration is emitted here once because the current generated source route uses `GameServerConfig::NationEntry`.

### [UID:0002HV] `by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md`

```cpp
GameServerConfig::GameServerConfig()
    : LObject(),
      m_nationEntries()
{
    g_gameServerNationTable = this;
    m_nationEntries.m_defaultEntry.nationId = (unsigned short)-1;
    m_nationEntries.m_reservedCount = 10;
    m_nationEntries.m_entries = NULL;
    m_nationEntries.m_count = 0;
}
```

Preserve caveat: IDA still has no function object or direct raw-start xref for `0x005039f0`, and `MapPane::MapPane` repeats this initialization inline after allocating `0x58` / 88 bytes (Verified with `tools/int_convert.py`). The caveat caps confidence but no longer justifies an empty marker.

### [UID:0002HW] `by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md`

```cpp
GameServerConfig::~GameServerConfig()
{
    delete [] m_nationEntries.m_entries;
    g_gameServerNationTable = NULL;
}
```

Preserve caveat: IDA still has no function object or direct raw-start xref for `0x00503a50`; modeled scalar deleting destructor [UID:000374] also repeats this cleanup. Source should be the ordinary destructor body, not a scalar-deleting wrapper.

### [UID:0002HX] `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md`

```cpp
GameServerConfig::NationEntry *
GameServerConfig::CopyNationEntryOrFallback(NationEntry *destination, int nationId)
{
    for (int index = 0; index < m_nationEntries.m_count; ++index) {
        NationEntry *entry = &m_nationEntries.m_entries[index];
        if (entry->nationId == nationId) {
            *destination = *entry;
            return destination;
        }
    }

    destination->nationId = 0;
    wcscpy_s(destination->label, 33, L"????");
    return destination;
}
```

Reason: current decompile copies a full `0x44` / 68-byte record (Verified with `tools/int_convert.py`) on match, otherwise writes id `0` and `????`. Caller-side destination semantic names remain provisional but no longer block draft source.

### [UID:0002HY] `by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md`

```cpp
void GameServerConfig::SeedDefaultNationEntries()
{
    m_nationEntries.Resize(2);

    NationEntry *firstEntry = m_nationEntries.GetAtOrDefault(0);
    firstEntry->nationId = 1;
    wcscpy_s(firstEntry->label, 33, g_pLanguageMan->GetLocalizedString(0x9f));

    NationEntry *secondEntry = m_nationEntries.GetAtOrDefault(1);
    secondEntry->nationId = 2;
    wcscpy_s(secondEntry->label, 33, g_pLanguageMan->GetLocalizedString(0xa0));
}
```

Preserve caveat: IDA still has no function object or direct xref for `0x00503b60`. Current bounded `insn_query` proves constant two-record resize/allocation, ids `1` and `2`, string ids `0x9f` / 159 and `0xa0` / 160 (Verified with `tools/int_convert.py`), and `wcscpy_s` capacity `0x21` / 33 (Verified). Those facts justify draft source even though exact localized-string meanings remain resource-owned.

### [UID:0002HZ] `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md`

```cpp
void GameServerConfig::RequestNationEntries()
{
    if (m_nationEntries.m_count <= 0)
        SendGameServerNationEntryRequestPacket();
}
```

Reason: [UID:000230] already emits the file-local fixed-packet helper with opcode `0x66` / 102 and subcode `0x4000` / 16384 (Verified with `tools/int_convert.py`). This page should emit the live guarded member path with four callers.

### [UID:0002I0] `by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md`

```cpp
void GameServerConfig::ParseNationEntries(const unsigned char *packet)
{
    if (PacketBufferReadUInt16BE(packet) <= 0)
        return;

    int packetOffset = 3;
    int count = packet[2] + 1;
    m_nationEntries.Resize(count);

    for (int index = 0; index < count; ++index) {
        NationEntry *entry = m_nationEntries.GetAtOrDefault(index);
        entry->nationId = packet[packetOffset++];

        int labelLength = packet[packetOffset++];
        int convertedLength = MultiByteToWideChar(
            0,
            0,
            (const char *)(packet + packetOffset),
            labelLength,
            entry->label,
            32);
        entry->label[convertedLength] = 0;
        packetOffset += labelLength;
    }

    NationEntry *neighborhood = m_nationEntries.GetAtOrDefault(count - 1);
    neighborhood->nationId = 10;
    wcscpy_s(neighborhood->label, 33, L"Neighborhood");
}
```

Reason: current decompile shows the `PacketBufferReadUInt16BE`/positive check, packet byte `+2` plus one count, resize call, packet cursor starting at `3`, `MultiByteToWideChar(..., 32)`, explicit terminator, final id `0x0a` / 10 (Verified), and `Neighborhood` literal. Packet schema field names remain provisional but no longer justify blank C++.

### [UID:0001UP] `by-type/by-struct/GameServerNationEntry.md`

```cpp
// GameServerConfig::NationEntry is emitted as the nested record declaration
// in [UID:00005O] GameServerConfig. This page documents the same 0x44-byte
// layout; do not emit a second standalone GameServerNationEntry struct.
```

Reason: the type page must clear its marker without duplicating the nested struct emitted on the class page.

### [UID:0000B4] `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`

```cpp
// Source uses ProtectedArray<GameServerConfig::NationEntry> as
// GameServerConfig::m_nationEntries. Do not emit a generated wrapper class
// named ProtectedArray_struct_GameServerConfig__NationEntry_; the reusable
// template bodies belong to ProtectedArray support pages, and [UID:000234]
// emits the concrete GameServerConfig::NationEntry Resize(int count) body.
```

Reason: the concrete instantiation page is support/ownership evidence, not an original standalone class declaration route.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata |
| --- | --- | --- | --- |
| `0000JP` | `87/86` | `90/91` | Keep `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. |
| `00005O` | `87/89` | `90/91` | Keep `CANONICAL_OWNER:0000JP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JP`; populate class formal C++. |
| `0002HV` | `85/88` | `88/90` | Keep owner/emitter [UID:00005O]; populate constructor formal C++; preserve no-function/no-xref caveat. |
| `0002HW` | `85/88` | `88/90` | Keep owner/emitter [UID:00005O]; populate destructor formal C++; preserve no-function/no-xref caveat and scalar-wrapper distinction. |
| `0002HX` | `85/90` | `89/91` | Keep owner/emitter [UID:00005O]; populate lookup/copy formal C++. |
| `0002HY` | `85/88` | `88/90` | Keep owner/emitter [UID:00005O]; populate seeder formal C++; preserve no-function/no-xref caveat. |
| `0002HZ` | `85/90` | `89/91` | Keep owner/emitter [UID:00005O]; populate guarded request formal C++. |
| `0002I0` | `85/90` | `89/91` | Keep owner/emitter [UID:00005O]; populate parser formal C++. |
| `0001UP` | `86/90` | `88/91` | Keep owner/emitter [UID:00005O]; formal no-duplicate comment. |
| `0000B4` | `87/90` | `88/91` | Keep owner/emitter [UID:0000JP]; formal no-duplicate comment. |

Reason not higher: raw lifecycle/seeder reachability remains zero-xref/no-function in current MCP; source names for several fields and packet schema entries are still inferred; `+0x0c` protected-array field remains provisional; exact original header factoring between class/type pages is inferred.

## Recommended Target Doc Changes

- `by-file/GameServerConfig.md`: update metadata to `90/91`; update Proposed Contents and Changes/Evidence to list all nine current visible empty markers as resolved by accepted first-draft C++ or no-duplicate comment; record current generated count discrepancy (`goal` says ten empty, current generated file shows nine visible markers); preserve map/source placement, MapPane split, raw zero-xref caveats, and generated-refresh expectation.
- `by-class/GameServerConfig.md`: update to `90/91`; replace stale class-level no-code proof with the formal class declaration; update method table/evidence to mark constructor/destructor/copy/seeder/request/parser source-ready with exact caveats; preserve rejected `InitializeMapPane`, generic config, MapPane ownership, vtable/COL hand-authoring, and scalar-deleting-wrapper-as-source alternatives.
- `by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md`: update to `88/90`; insert constructor C++; update Reconstruction Notes to say no-function/no-xref remains a caveat, not a blank-code blocker.
- `by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md`: update to `88/90`; insert destructor C++; preserve exact tail-jump/range/padding and scalar-deleting-wrapper distinction.
- `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md`: update to `89/91`; insert lookup/copy/fallback C++; preserve two callers, `0x44` stride, full-copy behavior, `????` literal evidence, and provisional caller destination names.
- `by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md`: update to `88/90`; insert seeder C++; preserve no-function/no-xref, count two, `0x88` allocation, string ids `0x9f`/`0xa0`, `g_pLanguageMan` route, and capacity `0x21` evidence.
- `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md`: update to `89/91`; insert request C++; preserve four callers and relationship to already-emitted [UID:000230] file-local helper.
- `by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md`: update to `89/91`; insert parser C++; preserve single caller, `PacketBufferReadUInt16BE`/positive check, count plus one, resize caller, cursor and final `Neighborhood` overwrite.
- `by-type/by-struct/GameServerNationEntry.md`: update to `88/91`; insert no-duplicate comment and update layout notes to state nested declaration route is [UID:00005O].
- `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`: update to `88/91`; insert no-duplicate comment and keep [UID:000234] as the concrete resize body route.

## Recommended Support Doc Changes

- `by-file/ProtectedArray.md`, `by-type/by-template/ProtectedArrayTemplates.md`, and `by-type/by-struct/ProtectedArrayLayout.md` are already sufficiently current for this callback because they document `Resize`, `GetAtOrDefault`, `m_count`, `m_entries`, `m_defaultEntry`, and provisional `+0x0c`. Optional implementation callback may add a short cross-reference that `GameServerConfig` now emits its class/method draft bodies, but this is not required to resolve [UID:0000JP].
- No manual `-coverage-report.md` text is recommended. Generated tracker/coverage should refresh through scoped validators after implementation.
- Do not edit IDA DB. Source-facing names are documentation recommendations only.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0000JP] remains `NexusTK/map/GameServerConfig.cpp`, not generic config or full MapPane ownership. | High | Current by-file docs, B004 report, live MCP xrefs/global/vtable facts. | `by-file/GameServerConfig.md` Status/Source-Layout/2026-07-01 B009 section/Changes | incorporate | applied |
| C2 | Current generated file has nine visible empty markers despite goal/queue saying ten. | High | `auto-generated/NexusTK/map/GameServerConfig.cpp` header `000000003794`, `rg` marker count. | `by-file/GameServerConfig.md` Status/2026-07-01 B009 section/Changes | incorporate | applied |
| C3 | [UID:00005O] should emit a class declaration with nested `NationEntry` and member/method declarations. | High | Compiler-supported class/vtable, record layout, method family, generated empty marker. | `by-class/GameServerConfig.md` formal C++ and 2026-07-01 B009 section | incorporate | applied |
| C4 | Raw constructor [UID:0002HV] is source-shaped and should emit first-draft constructor C++ while preserving no-function/no-xref caveat. | Medium-high | `lookup_funcs` not function, zero xrefs, `insn_query` constructor sequence, MapPane inline mirror, vtable/global refs. | Constructor by-memory formal C++, Status, Implementation Notes, Changes | incorporate | applied |
| C5 | Raw destructor [UID:0002HW] should emit ordinary destructor C++ while preserving scalar-wrapper distinction. | Medium-high | `insn_query` cleanup body, scalar deleting destructor decompile, vtable/global refs, zero raw xrefs. | Destructor by-memory formal C++, Status, Implementation Notes, Changes | incorporate | applied |
| C6 | Modeled copy/fallback [UID:0002HX] should emit source method C++. | High | Decompile, two callers, `????` bytes/xref, `0x44` stride/copy. | Copy/fallback by-memory formal C++, Notes, Changes | incorporate | applied |
| C7 | Raw seeder [UID:0002HY] should emit source method C++ with localized string ids, despite zero raw xrefs. | Medium-high | Bounded `insn_query`, zero xrefs, `g_pLanguageMan`/`0x004f0350`, ids `0x9f`/`0xa0`. | Seeder by-memory formal C++, Status, Implementation Notes, Changes | incorporate | applied |
| C8 | Request [UID:0002HZ] should emit guarded source method calling existing file-local packet helper. | High | Decompile, four callers, [UID:000230] already emits fixed-packet helper. | Request by-memory formal C++, Notes, Changes | incorporate | applied |
| C9 | Parser [UID:0002I0] should emit source method C++ with count-plus-one resize, per-record conversion, and final `Neighborhood`. | High | Decompile, single caller, resize xref, literal bytes/xref. | Parser by-memory formal C++, Notes, Changes | incorporate | applied |
| C10 | Type page [UID:0001UP] should clear marker with no-duplicate comment because nested struct emits on class page. | High | Current generated spelling `GameServerConfig::NationEntry`, class declaration route, layout already documented. | Type page formal C++, Source-Placement, Changes | incorporate | applied |
| C11 | Concrete template page [UID:0000B4] should clear marker with no-duplicate comment, not generated wrapper class code. | High | ProtectedArray docs, [UID:000234] concrete resize emission, reusable template route. | Concrete ProtectedArray class page formal C++, Template/Split notes, Changes | incorporate | applied |
| C12 | Scores should rise as listed while remaining below final-audit range. | Medium-high | Empty marker resolution, live MCP evidence, remaining raw reachability/name caveats. | Metadata headers on all ten listed docs | incorporate | applied |

Implementation proof: C1-C2 were applied in `by-file/GameServerConfig.md` header, Status, Proposed Contents, `2026-07-01 B009 Empty-Emitter Family Implementation`, Assignment Gate Rationale, and Changes. C3 was applied in `by-class/GameServerConfig.md` header, formal C++ block, Methods, Ownership Notes, `2026-07-01 B009 Empty-Emitter Implementation Sync`, Assignment Gate Rationale, and Changes. C4-C9 were applied in the six named by-memory pages through metadata headers, formal C++ blocks, status/implementation notes, and Changes. C10 and C11 were applied in their formal no-duplicate C++ blocks plus evidence/changes sections. C12 was applied in all ten metadata headers.

## Open Questions With Attempted Resolution

- Exact original field names: resolved to best inferred names (`m_nationEntries`, `nationId`, `label`, `m_count`, `m_entries`, `m_defaultEntry`, provisional `m_reservedCount`) because current docs and decompilation support these roles. Original proof remains unavailable, so confidence stays below `95`.
- Raw constructor/destructor/seeder reachability: live MCP still finds no function records, no direct xrefs, and no absolute pointer patterns for the starts. Current rules do not allow using that alone as a blank-code blocker. The report resolves them with first-draft source bodies and keeps the negative evidence as a caveat.
- Parser packet schema names: no original packet field names were found. The C++ uses direct `packet`/`packetOffset` names and existing `PacketBufferReadUInt16BE` support instead of inventing protocol enum names.
- `Neighborhood` string rendering: IDA `get_string` partially renders `Ne`; raw bytes decode the full UTF-16 string. Use raw-byte evidence.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`.

| File | Command | command_id / timestamp | Exit / ok | Generated refresh |
| --- | --- | --- | --- | --- |
| `by-file/GameServerConfig.md` | `python .\tools\validator.py --mode file --file by-file/GameServerConfig.md --apply --queue-timeout 240 --wait-generated` | `000000003861` / `2026-07-01T15:27:36-04:00` | exit `0`, `ok: 1` | `completed`, `generated_refresh_command_id: 000000003861`, timestamp `2026-07-01T15:27:36-04:00` |
| `by-class/GameServerConfig.md` | `python .\tools\validator.py --mode file --file by-class/GameServerConfig.md --apply --queue-timeout 240 --wait-generated` | `000000003864` / `2026-07-01T15:28:01-04:00` | exit `0`, `ok: 1` | `completed`, `generated_refresh_command_id: 000000003864`, timestamp `2026-07-01T15:28:01-04:00` |
| `by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md --apply --queue-timeout 240 --wait-generated` | `000000003867` / `2026-07-01T15:28:31-04:00` | exit `0`, `ok: 1` | `completed`; generated refresh reported completed in the validator batch |
| `by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md --apply --queue-timeout 240 --wait-generated` | sequential scoped validator batch after `000000003867`; exact console row was truncated by the UI transcript | exit `0`, `ok: 1` | `completed`; registry now records [UID:0002HW] `88/90`, reconstructable true, coded block |
| `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md --apply --queue-timeout 240 --wait-generated` | sequential scoped validator batch; exact console row was truncated by the UI transcript | exit `0`, `ok: 1` | `completed`; registry now records [UID:0002HX] `89/91`, reconstructable true, coded block |
| `by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md --apply --queue-timeout 240 --wait-generated` | sequential scoped validator batch; exact console row was truncated by the UI transcript | exit `0`, `ok: 1` | `completed`; registry now records [UID:0002HY] `88/90`, reconstructable true, coded block |
| `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md --apply --queue-timeout 240 --wait-generated` | sequential scoped validator batch; exact console row was truncated by the UI transcript | exit `0`, `ok: 1` | `completed`; registry now records [UID:0002HZ] `89/91`, reconstructable true, coded block |
| `by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md` | `python .\tools\validator.py --mode file --file by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md --apply --queue-timeout 240 --wait-generated` | `000000003884` / `2026-07-01T15:30:58-04:00` | exit `0`, `ok: 1` | `completed`, `generated_refresh_command_id: 000000003884`, timestamp `2026-07-01T15:30:58-04:00` |
| `by-type/by-struct/GameServerNationEntry.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/GameServerNationEntry.md --apply --queue-timeout 240 --wait-generated` | `000000003886` / `2026-07-01T15:31:27-04:00` | exit `0`, `ok: 1` | `completed`, `generated_refresh_command_id: 000000003886`, timestamp `2026-07-01T15:31:27-04:00` |
| `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md` | `python .\tools\validator.py --mode file --file by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md --apply --queue-timeout 240 --wait-generated` | `000000003888` / `2026-07-01T15:31:47-04:00` | exit `0`, `ok: 1` | `completed`, `generated_refresh_command_id: 000000003888`, timestamp `2026-07-01T15:31:47-04:00` |

Non-fatal validator diagnostics/warnings observed: `missing_ref_uid` for pre-existing references such as `0003C3`, `0003IS`, `000372`, `000374`, `0003IJ`, and `0003II`; `uid_link_insert` / `uid_link_update`; `autogen_children_marker_missing` / `autogen_children_fallback_insert`; `autogen_emitter_has_no_code`; generated metadata/report refresh notices; `stats_row_remove` / `stats_rescore_recommended` / `stats_incremental_noop`; and validator-owned `research_tracker_update`. Each scoped validator exited `0` with `ok: 1`.

Final generated freshness proof after the interrupted compact proof rerun settled: `auto-generated/NexusTK/map/GameServerConfig.cpp` now has header `validator-command-id: 000000003918`, `validator-refreshed-at: 2026-07-01T15:40:23-04:00`, `validator-refresh-source: foreground-generated-refresh`. This is newer than the successful implementation validator batch above. `tools/validator_command_state.json` also records `last_command_id: 3920`, `last_command_timestamp: 2026-07-01T15:40:49-04:00`; no short-lived validator Python process remained after the final wait.

Generated empty-marker proof: `Select-String` over `auto-generated/NexusTK/map/GameServerConfig.cpp` found the former marker UIDs [UID:00005O], [UID:0002HV], [UID:0002HW], [UID:0002HX], [UID:0002HY], [UID:0002HZ], [UID:0002I0], [UID:0001UP], and [UID:0000B4] now present with formal code/comment output and updated scores. The same search for `EMPTY`, `empty`, `blank`, and `TODO` found no old empty-marker text in that generated file. The generated tracker now lists [UID:0000JP] as `13` total, `12` filled, `1` empty, `92.3%`, replacing the older `3` filled / `10` empty queue row.

## Changed Files

- Modified target/support docs: `by-file/GameServerConfig.md`; `by-class/GameServerConfig.md`; `by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md`; `by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md`; `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md`; `by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md`; `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md`; `by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md`; `by-type/by-struct/GameServerNationEntry.md`; `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`.
- Modified report: `tools/leaser/Agents/Agent-B009/research/0000JP-GameServerConfig-empty-emitter-family-source-quality.md`.
- Validator-owned generated refresh observed: `auto-generated/NexusTK/map/GameServerConfig.cpp` and generated tracker/coverage outputs updated by validator only; B009 did not manually edit generated files, generated reports, coverage reports, queues, archives, supervisor ledgers, by-project-structure docs, or IDA DB.
- Leases: B009 leased the ten edited by-* docs before the edit/validator batch, then released the same ten paths. A post-release `current_leases.md` search for `B009` and `GameServerConfig` returned no rows, proving no active B009 leases remain.
- Report execution: leave blank during B-agent pass. Supervisor executes after review/implementation verification.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Supervisor validation accepted the report before implementation. Proof: supervisor callback assigned `B009-implement-0000JP-GameServerConfig-empty-emitter-family-20260701`.
- [x] Updated `by-file/GameServerConfig.md` to `COMPLETION:90`, `CONFIDENCE:91`; preserved `CANONICAL_OWNER:FILE` and `NexusTK/map/`; incorporated generated state, nine-visible-marker discrepancy, recommended dispositions, MapPane split, raw caveats, and generated-refresh expectation. Proof: header, Status, Proposed Contents, `2026-07-01 B009 Empty-Emitter Family Implementation`, Assignment Gate Rationale, and Changes.
- [x] Updated `by-class/GameServerConfig.md` to `90/91`; inserted formal class declaration C++; updated method/evidence notes for constructor, destructor, copy/fallback, seeder, request, parser, nested record, protected-array member, MapPane split, and rejected alternatives. Proof: header/formal C++ block, Methods, Ownership Notes, `2026-07-01 B009 Empty-Emitter Implementation Sync`, Assignment Gate Rationale, and Changes.
- [x] Updated `by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md` to `88/90`; inserted constructor formal C++; preserved exact range, padding, `LObject`, `g_gameServerNationTable`, vtables, `m_reservedCount = 10`, no-function/no-xref, and MapPane inline mirror. Proof: header/formal C++ block, Status, Implementation Notes, and Changes.
- [x] Updated `by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md` to `88/90`; inserted destructor formal C++; preserved exact range/tail jump, vtable/free/global clear, no-function/no-xref, and scalar deleting destructor distinction. Proof: header/formal C++ block, Status, Implementation Notes, and Changes.
- [x] Updated `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md` to `89/91`; inserted lookup/fallback formal C++; preserved two callers, `0x44` / 68-byte stride, full-copy, id `0`, `????` literal, and provisional destination naming. Proof: header/formal C++ block, Notes, and Changes.
- [x] Updated `by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md` to `88/90`; inserted seeder formal C++; preserved no-function/no-xref, `0x101` / 257-byte body, `0x88` / 136-byte allocation, ids `1`/`2`, string ids `0x9f` / 159 and `0xa0` / 160, and `g_pLanguageMan->GetLocalizedString`. Proof: header/formal C++ block, Status, Implementation Notes, and Changes.
- [x] Updated `by-memory/0x00503c70-0x00503d03.GameServerConfigRequestNationEntries.md` to `89/91`; inserted request formal C++; preserved four callers, table-count guard, opcode/subcode relationship, and [UID:000230] helper reuse. Proof: header/formal C++ block, Notes, and Changes.
- [x] Updated `by-memory/0x00503d10-0x00503e77.GameServerConfigParseNationEntries.md` to `89/91`; inserted parser formal C++; preserved single caller, `PacketBufferReadUInt16BE` check, packet offset `+2` plus one count, resize call, per-record `MultiByteToWideChar`, final id `10`, and `Neighborhood` literal byte proof. Proof: header/formal C++ block, Notes, and Changes.
- [x] Updated `by-type/by-struct/GameServerNationEntry.md` to `88/91`; inserted formal no-duplicate comment; stated nested declaration route through [UID:00005O] and preserved `0x44` / 68-byte layout and default `nationId = -1`. Proof: header/formal C++ block, Layout/Evidence, Source-Placement, and Changes.
- [x] Updated `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md` to `88/91`; inserted formal no-duplicate comment; preserved concrete specialization, [UID:000234] resize, and reusable-template split. Proof: header/formal C++ block, Template/Split notes, Cross-References, and Changes.
- [x] Claim And Incorporation Ledger updated during callback with path/section proof and verification state for every accepted claim. Proof: ledger rows C1-C12 are `applied`, followed by implementation proof paragraph mapping each claim to destination sections.
- [x] Historical/stale assumptions preserved or rejected: old `InitializeMapPane` GameServerConfig ownership rejected; old class blank-C++ proof superseded; raw zero-xref evidence preserved as confidence cap; generated `ProtectedArray_struct_...` wrapper naming rejected as source declaration. Proof: `by-file/GameServerConfig.md` B009 section and Assignment Gate Rationale; `by-class/GameServerConfig.md` Ownership Notes and B009 section; child by-memory caveat notes; type/template no-duplicate comments.
- [x] Validators run: ten scoped `validator.py --mode file` commands with `--apply --queue-timeout 240 --wait-generated`. Proof: Validator Results table above; every completed scoped validator exited `0` with `ok: 1`.
- [x] Generated freshness check complete: `auto-generated/NexusTK/map/GameServerConfig.cpp` header is `validator-command-id: 000000003918`, `validator-refreshed-at: 2026-07-01T15:40:23-04:00`, newer than the implementation validator batch. The nine former empty-marker UIDs are present with code/comment output, and no `EMPTY`/`blank`/`TODO` marker text remains for them.
- [x] No manual coverage/tracker edit by B009. Proof: generated tracker/coverage changes were validator-owned; report records no manual edits to generated reports, generated C++, coverage reports, queues, archives, supervisor ledgers, by-project-structure docs, or IDA DB.
- [x] Lease release proof recorded. Proof: `python .\tools\leaser\leaser.py B009 unlease ...` returned `Success` for all ten leased by-* paths; post-release `current_leases.md` search for `B009` and `GameServerConfig` returned no rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000JP-GameServerConfig-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000JP-GameServerConfig-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T15:43:07","uid":"0000JP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
