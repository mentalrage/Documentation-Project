** TARGET-REPORT-UID:0002XQ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Source-Quality Report - [UID:0002XQ] g_objectRecordCount

## Assignment

- Agent: B004.
- Assignment ID: `B004-report-g-object-record-count-source-quality-0002XQ-mcp-20260623`.
- Target: [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](../../../by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md).
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0002XQ-g_objectRecordCount-source-quality.md`.
- Task type: report-only research. No by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files were edited.
- Current target state before this report: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000Q4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000Q4`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Current direct global parent: [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md), currently `88/89`, owner/emitter [UID:0000L3][MapPane](../../../by-file/MapPane.md), blank formal C++.

## Current Documentation State

The target page already correctly identifies the exact `.data` storage range as `0x0069b4bc-0x0069b4c0`, source role as the compact `SOBJ.TBL` object record count, and direct parent as [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md). It also correctly records the corrected active-IDB initial bytes as `00 00 00 00` and keeps the old `0xffffffff` byte note only as superseded history.

The support docs are mostly aligned on source placement: [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md) and [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md) place the compact object-nation cache in [UID:0000L3][MapPane](../../../by-file/MapPane.md), while [UID:0000Q1][g_gameServerNationTable](../../../by-global/g_gameServerNationTable.md) remains [UID:0000JP][GameServerConfig](../../../by-file/GameServerConfig.md)-owned. [UID:0001AO][GameServerNationAndMapInit](../../../by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md) is a non-emitting mixed split/index that explains the MapPane/GameServerConfig boundary.

Stale or incomplete items found:

- [UID:0002XQ] and [UID:0000Q4] still cite the older `b001_selflookpane_0001H7_20260616` session for the most recent live evidence. This report supersedes that with current MCP session `ff68e691`.
- [UID:0000Q4] says C001 saved the IDA data label `g_objectRecordCount`. In the current `ff68e691` session, MCP name/global queries do not find a `g_objectRecordCount` entity and decompilation still renders `unk_69B4BC`. The source-facing name remains well-supported, but the target/support docs should stop treating the saved IDB label as current-session proof.
- `by-memory/-coverage-report.md` row [UID:0002XQ] still says the slot is initialized to `0xffffffff`; that is stale. The parent row [UID:00029X] and sibling rows [UID:0002XR]/[UID:0002XS] also carry stale `0xffffffff` coverage wording even though the by-* pages corrected the bytes to zero.
- [UID:0000Q4] has a source declaration candidate in prose, `static std::uint32_t g_objectRecordCount;`, but formal `RECONSTRUCTION_CPP` remains blank. The current code-entry gate is met for the by-global page and the exact storage child has a target-specific no-duplicate-output reason to stay blank.

## Evidence Checked

### Docs And Generated State

- Read target [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](../../../by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md).
- Read [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md), [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md), and [UID:0000Q1][g_gameServerNationTable](../../../by-global/g_gameServerNationTable.md).
- Read parent [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](../../../by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md).
- Read [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](../../../by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md), [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](../../../by-memory/0x00504110-0x00504521.MapPaneInitialize.md), [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](../../../by-memory/0x00504530-0x005046c6.MapPaneCleanup.md), [UID:0000L3][MapPane](../../../by-file/MapPane.md), [UID:0000JP][GameServerConfig](../../../by-file/GameServerConfig.md), and [UID:0001RL][sobj-tbl](../../../by-resource/sobj-tbl.md).
- Checked `project-level/-auto-completion-stats.md`: [UID:0002XQ] appears in the low-score by-memory rows as `86/86`.
- Checked `auto-generated/-ag-memory-coverage.md`: [UID:0002XQ] emits through [UID:0000Q4] and reaches `auto-generated/NexusTK/map/MapPane.cpp`.
- Checked `auto-generated/NexusTK/map/MapPane.cpp`: constructor/destructor first-draft code uses `g_objectRecordCount`, but the [UID:0000Q4] and [UID:0002XQ] markers are still empty.
- Checked `by-memory/-coverage-report.md`: local coverage block still has stale `0xffffffff` initializer text for [UID:00029X], [UID:0002XQ], [UID:0002XR], and [UID:0002XS].

### Current MCP Session And Binary Provenance

Current MCP endpoint and session:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session: `ff68e691`.
- `idb_list`: one active adopted worker session, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14256`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with `2067` strings.
- `survey_binary minimal`: arch `32`, image size `0x2b3000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, four segments:
  - `.text` `0x00401000-0x0060d000`, `rx`, size `0x20c000`.
  - `.idata` `0x0060d000-0x0060d670`, `r`, size `0x670`.
  - `.rdata` `0x0060d670-0x0066d000`, `r`, size `0x5f990`.
  - `.data` `0x0066d000-0x0069d000`, `rw`, size `0x30000`.
- Supplemental local PE mirror used only for bounded byte-pattern cross-checks: `E:\NTK\Resources\NexusTK\NexusTK.exe`, size `2679296`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

### Exact Storage / Data Item

MCP `get_bytes` on `ff68e691`:

- `0x0069b4bc-0x0069b4c0`: `0x0 0x0 0x0 0x0`.
- Parent window `0x0069b4b4-0x0069b4c8`: twenty zero bytes.
- Sibling [UID:0002XR] `0x0069b4c0-0x0069b4c4`: `0x0 0x0 0x0 0x0`.
- Sibling [UID:0002XS] `0x0069b4c4-0x0069b4c8`: `0x0 0x0 0x0 0x0`.

MCP `get_global_value` by address returns `0x0` for `0x0069b4bc`, `0x0069b4c0`, and `0x0069b4c4`. `get_global_value` by name returns `Not found` for `g_objectRecordCount`, `g_objectNationMap`, and `g_gameServerNationTable`. `entity_query` for names/globals over `0x0069b4b4-0x0069b4c8` returns zero records. This is a current-session label/index limitation and should be documented; it does not invalidate the source-facing names because the use pattern and current docs support them.

MCP `lookup_funcs` confirms `0x0069b4bc` is not a function. The slot is in `.data`, writable, non-executable global storage.

### Xrefs And Loader / Consumer Behavior

MCP `xrefs_to` and `xref_query` for `0x0069b4bc` return exactly five direct data xrefs:

| Xref | Function | Use |
| --- | --- | --- |
| `0x005042fa` | `sub_504110`, size `0x411` | `push offset unk_69B4BC` before `sub_49C310(..., size 4)`: read four bytes from `SOBJ.TBL` into the global count. |
| `0x00504315` | `sub_504110` | `mov eax, dword ptr unk_69B4BC`; increments the count for `g_objectNationMap` allocation size. |
| `0x00504331` | `sub_504110` | compares `g_objectRecordCount` with loop index `edi=1` to decide whether to parse records. |
| `0x00504397` | `sub_504110` | compares incremented loop index against `g_objectRecordCount` to continue record parsing. |
| `0x00505561` | `sub_505430`, size `0x19a` | reads count before bounds/classification tests against [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md). |

MCP `lookup_funcs`:

- `0x00504110` -> `sub_504110`, size `0x411`.
- `0x00504530` -> `sub_504530`, size `0x196`.
- `0x00505430` -> `sub_505430`, size `0x19a`.
- `0x00505561` belongs to `sub_505430`.

MCP disassembly window `0x005042de-0x005043a2` confirms the loader sequence:

- Guard on `unk_69B4C0` at `0x005042de`.
- Open `off_61C1A4` (`SOBJ.TBL`) at `0x005042eb-0x005042f3`.
- Read four bytes into `unk_69B4BC` at `0x005042f8-0x00504302`.
- Read two-byte header at `0x00504307-0x00504310`.
- Allocate `unk_69B4BC + 1` bytes through `sub_516050` and store pointer to `unk_69B4C0` at `0x00504315-0x00504324`.
- Seed `g_objectNationMap[0] = 0` at `0x0050432e`.
- Loop from `edi = 1`, reading a dword, three one-byte fields, and `2 * extraWordCount` bytes, then storing the second one-byte field into `g_objectNationMap[edi]` at `0x0050438b-0x00504393`.
- Continue while `edi < unk_69B4BC` at `0x00504397`.

MCP decompilation of `sub_504110` matches the source-shaped constructor already on [UID:0002I7]: it opens `SOBJ.TBL`, calls the DAT read helper with `&unk_69B4BC` and size `4`, allocates `unk_69B4BC + 1`, sets the byte-map slot zero, loops from index `1`, and stores the second one-byte field into `unk_69B4C0[index]`.

MCP `analyze_function 0x00505430` confirms the consumer:

- Prototype currently decompiler-shaped: `int __thiscall(int this, int, int, char)`, size `410`.
- Nine code call sites are reported by xrefs (`0x0050c9fd`, `0x0050cab1`, `0x0050cb61`, `0x0050cc15`, `0x0050d2d3`, `0x0050d35b`, `0x0050d3e1`, `0x0050d467`, `0x005a3207`), grouped by MCP as callers `sub_50C790`, `sub_50D010`, and `sub_5A2E00`.
- It derives target coordinates from direction, checks map bounds and object blocking, uses `_wcsicmp(..., L"GM")` and object hidden-state gating, calls `sub_50C120` twice to fetch current/target tile records, reads `unk_69B4BC` at `0x00505561`, reads `unk_69B4C0` at `0x0050557e`, and tests `byte_66DD50` / `byte_66DD58` direction masks against the two object-nation bytes before returning pass/fail.
- Disassembly focus:
  - `0x00505561`: `mov edx, dword ptr unk_69B4BC`.
  - `0x00505573`: compare count against first object id/index.
  - `0x0050557a`: compare count against second object id/index.
  - `0x0050557e`: `mov esi, dword ptr unk_69B4C0`.
  - `0x00505588` / `0x00505596`: load map bytes.
  - `0x0050558b` and `0x00505599`: test direction masks.

MCP decompilation of `sub_504530` confirms cleanup reads/clears [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md) and [UID:0000Q1][g_gameServerNationTable](../../../by-global/g_gameServerNationTable.md), but the current raw decompilation does not show a direct `0x0069b4bc` xref in the destructor. The first-draft `MapPane::~MapPane()` reset of `g_objectRecordCount = 0` remains a source-level cleanup choice documented by the MapPane lifecycle pass, not a direct additional data xref to this storage in the current MCP xref set.

### Relationship To Adjacent Slots

MCP `xref_query` for sibling [UID:0002XR] `0x0069b4c0` returns six xrefs:

- `0x005042de`, `0x00504324`, `0x0050438b` in `sub_504110`.
- `0x0050463d`, `0x00504653` in `sub_504530`.
- `0x0050557e` in `sub_505430`.

MCP `xref_query` for sibling [UID:0002XS] `0x0069b4c4` returns eighteen xrefs:

- Raw no-function constructor/destructor sites `0x00503a0d`, `0x00503a6b`.
- MapPane constructor allocation/write sites `0x00504467`, `0x0050446e`.
- MapPane cleanup `0x00504668`.
- Packet/status/request/copy users `0x00507cf6`, `0x0059be2e`, `0x0059c0d2`, `0x0059c9a2`, `0x0059cc30`, `0x0059d2ca`, `0x005a5023`, `0x005a5dc6`, `0x005b92f8`, `0x005b930a`, `0x005be726`, `0x005be738`.
- Scalar destructor clear `0x00514d9e`.

The sibling pattern supports the current split:

- `0x0069b4bc` and `0x0069b4c0` are a pair: count plus compact byte-map pointer, both MapPane-owned.
- `0x0069b4c4` is adjacent but belongs to the GameServerConfig/nation-table family, not to the compact object-nation cache declaration.
- The parent [UID:00029X] remains a mixed physical neighborhood, not a source declaration owner.

### Bounded PE Pattern Scan

Supplemental local PE scan over `E:\NTK\Resources\NexusTK\NexusTK.exe` (SHA-256 matches MCP `survey_binary`) found:

| Pattern | Count | Hits |
| --- | ---: | --- |
| VA `0x0069b4bc` (`bc b4 69 00`) | 5 | raw offsets `0x1036fb`, `0x103716`, `0x103733`, `0x103799`, `0x104963` |
| RVA `0x0029b4bc` | 0 | none |
| raw-offset guess `0x0029a8bc` | 0 | none |
| VA `0x0069b4c0` | 6 | raw offsets matching the six MCP xrefs |
| RVA `0x0029b4c0` | 0 | none |
| VA `0x0069b4c4` | 18 | raw offsets matching the eighteen MCP xrefs |
| RVA `0x0029b4c4` | 0 | none |

Interpretation: the count slot is referenced by direct absolute `.text` data immediates, not by a separate pointer table, RVA table, or raw-file-offset table. This reinforces the global-storage model and rejects a hidden callback/table owner for [UID:0002XQ].

## Positive Evidence

- Exact `.data` range, size, bytes, and zero initializer are current-MCP confirmed.
- Five direct data xrefs are current-MCP confirmed and match previous docs after correcting the old byte/session wording.
- The loader xrefs are all inside [UID:0002I7][MapPaneInitialize](../../../by-memory/0x00504110-0x00504521.MapPaneInitialize.md), which is already accepted as `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)`.
- The consumer xref at `0x00505561` is inside the MapPane movement/object gate helper and pairs the count with [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md).
- The count and pointer slots are used together: count load -> map allocation size -> loop bound -> consumer bounds/mask checks.
- Current [UID:0001RL][sobj-tbl](../../../by-resource/sobj-tbl.md) resource docs independently support a four-byte count of `19,551` records, two-byte header, leading sentinel/reserved records, and a compact MapPane parser view distinct from StaticObjImageLib's full render-metadata view.
- The direct parent [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md) clears the owner/emitter gate and routes to [UID:0000L3][MapPane](../../../by-file/MapPane.md).

## Negative / Counter-Evidence

- Current MCP name/global queries do not resolve `g_objectRecordCount`; current decompilation still uses `unk_69B4BC`. Therefore the exact original/current-IDB label should not be used as confidence proof in this session.
- No separate data table, RVA table, raw-offset table, or pointer-route was found for the count slot beyond the five direct absolute VA xrefs.
- The slot is adjacent to GameServerConfig's global pointer at `0x0069b4c4`, but that adjacency is not ownership evidence; the xrefs split by use family.
- The parent aggregate [UID:00029X] spans MapNamePane, MiniMapButtonPane, MapPane object-cache globals, and GameServerConfig nation-table state. It cannot own a single source declaration.
- [UID:0001AO] is a mixed non-emitting executable index; it documents the loader region but is not a declaration owner for this `.data` slot.
- StaticObjImageLib parses the same `SOBJ.TBL` resource but stores its count in instance/class storage; it does not write or own this global.
- The current raw destructor xrefs do not include `0x0069b4bc`; the source-level destructor reset remains a plausible MapPane source cleanup statement but not a direct data-xref proof for this storage child.

## Heuristic / Inference Reanalysis

### Source-Facing Name

Recommended source name remains `g_objectRecordCount`.

Confidence: strong as a source-facing descriptive name, not proven as an original symbol. It is better than `unk_69B4BC` / `dword_69B4BC` because the loader reads the first four bytes of `SOBJ.TBL` into this slot, uses it as a record count, allocates `g_objectRecordCount + 1`, uses it as the parse loop bound, and later compares object ids/indexes against it before indexing [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md).

Counter-evidence: current MCP does not expose a `g_objectRecordCount` IDB name. Target/support docs should phrase this as the accepted source-facing name and historical/saved-label claim carefully: current session renders `unk_69B4BC`.

### Type And Declaration Shape

Recommended first-draft source declaration for the by-global page:

```cpp
static std::uint32_t g_objectRecordCount = 0;
```

Why not primary `int g_objectRecordCount = 0;`:

- The slot is a four-byte count read from a binary table, not a signed arithmetic quantity.
- The MapPane constructor draft already uses `std::uint32_t index` and `std::uint32_t objectId`; using `std::uint32_t` keeps the table-count type consistent with that accepted source shape.
- The consumer treats compared tile/object ids as unsigned-ish values after `movzx` from word fields.
- No code checks for negative counts or signed semantics.

Acceptable local fallback if the project avoids `<cstdint>` in final source would be `static unsigned int g_objectRecordCount = 0;`. I do not recommend signed `int` as the first choice.

### Target Formal-C++ Disposition

The exact storage child [UID:0002XQ] should keep `RECONSTRUCTION_CPP` blank, with an explicit no-duplicate-output proof added to the target.

Reason: the source declaration belongs to the semantic by-global owner [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md), which emits through [UID:0000L3][MapPane](../../../by-file/MapPane.md). This mirrors the accepted [UID:00027E]/[UID:0000PY] `g_fpsDebugActive` pattern: the by-global page emits the source declaration, while the exact memory child documents address/bytes/xrefs and stays blank to avoid duplicate definitions. [UID:0002XQ] still remains reconstructable and has an emitter route, but its source contribution is evidence for the by-global declaration rather than a second C++ definition.

If the supervisor chooses a memory-page-emits-data convention instead, the same declaration can be placed on [UID:0002XQ] and [UID:0000Q4] must remain blank; do not emit both.

## Ranked Ownership / Source Placement Candidates

1. [UID:0000Q4][g_objectRecordCount](../../../by-global/g_objectRecordCount.md) as direct semantic owner, emitted through [UID:0000L3][MapPane](../../../by-file/MapPane.md). Strongest. It names the source-level global, groups the count with [UID:0000Q3][g_objectNationMap](../../../by-global/g_objectNationMap.md), and routes to the MapPane source file where all direct count xrefs live.
2. [UID:0000L3][MapPane](../../../by-file/MapPane.md) as the source file owner for the by-global declaration. Strong, but it is the file-level emitter rather than the narrow direct owner for the exact storage child. MapPane owns the constructor, destructor draft, and movement/occupancy consumer.
3. [UID:00029X][MapNameMiniMapAndGameServerGlobals](../../../by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) as physical parent aggregate. Rejected as declaration owner. It is a non-emitting split/index over five adjacent four-byte slots with different direct owners.
4. Game-server table family / [UID:0000JP][GameServerConfig](../../../by-file/GameServerConfig.md). Rejected for this count. [UID:0000Q1][g_gameServerNationTable](../../../by-global/g_gameServerNationTable.md) is adjacent and allocated in the same constructor, but it has different xref family and source semantics. GameServerConfig owns the nation-entry table, not the compact object-nation count/map pair.
5. [UID:0001AO][GameServerNationAndMapInit](../../../by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md). Rejected as owner. It is an executable mixed split/index that contains the loader function, not a `.data` declaration owner.
6. Adjacent singleton ownership (`MapNamePane`, `MiniMapButtonPane`, transfer/server/login singletons). Rejected. Adjacency in `.data` is weak and no xrefs from those singleton lifecycles touch `0x0069b4bc`.
7. No-owner/non-emitting. Rejected. The count has exact storage, clear source semantics, direct global parent, nonblank emitter path, and a safe by-global declaration route.

## Score / Metadata Recommendation

Target [UID:0002XQ]:

- `COMPLETION`: raise `86 -> 88`.
- `CONFIDENCE`: raise `86 -> 88`.
- `CANONICAL_OWNER`: keep `0000Q4`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: keep `0000Q4`.
- `EMITTER_POSITION_OPTIONAL`: keep blank.
- `RECONSTRUCTION_CPP`: keep blank with the no-duplicate-output proof above.

Why cap at `88/88`:

- Current MCP strongly confirms bytes, xrefs, route, range, and relationship to siblings.
- The by-memory target still should not emit its own declaration if [UID:0000Q4] emits it.
- Current MCP does not expose `g_objectRecordCount` as an IDB name; decompilation still shows `unk_69B4BC`.
- Exact original spelling, `static`/extern placement, and original table-count typedef remain inferred.
- `SOBJ.TBL` one-byte field names and sentinel/header semantics remain open in the resource docs, though they no longer block this global's name/owner.

Support [UID:0000Q4]:

- Recommend raising `COMPLETION:88 -> 89`; keep `CONFIDENCE:89`.
- Keep owner/emitter [UID:0000L3][MapPane](../../../by-file/MapPane.md).
- Add first-draft C++ declaration:

```cpp
static std::uint32_t g_objectRecordCount = 0;
```

If the implementation callback is intentionally narrower and declines support-page C++, then keep [UID:0000Q4] score/C++ unchanged and preserve this report's first-draft recommendation for a later callback; do not add duplicate C++ to [UID:0002XQ].

## Recommended Target / Support Doc Changes If Accepted

### Target: `by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md`

- Update score to `88/88`; keep owner/emitter/reconstructable metadata unchanged.
- Add a dated `2026-06-23 B004 MCP-backed source-quality recheck` section.
- Include endpoint/session/provenance: endpoint, session `ff68e691`, IDB path, worker PID, health/schema facts, executable SHA-256, `.data` section range, and current-session label caveat.
- Preserve exact bytes: `00 00 00 00` for the child and twenty zero bytes for the parent window.
- Preserve exact xrefs and use classification: write/read-through loader at `0x005042fa`, allocation/loop reads at `0x00504315`, `0x00504331`, `0x00504397`, consumer read at `0x00505561`.
- Add the disassembly/decompilation evidence for `0x00504110` and `0x00505430`.
- Preserve sibling relationship to [UID:0002XR] and [UID:0002XS] with current xref counts `6` and `18`.
- Add the PE immediate/pointer scan: five absolute-VA hits for `0x0069b4bc`; no RVA/raw-offset pointer hits.
- Add target-specific no-code proof: exact storage child stays blank because [UID:0000Q4] should emit the declaration; do not duplicate output.
- Move the old `0xffffffff` wording into superseded history only, not current evidence.

### Support: `by-global/g_objectRecordCount.md`

- Update evidence to current MCP session `ff68e691`.
- Replace "saved IDA label" confidence wording with a current-session caveat: source-facing `g_objectRecordCount` is accepted, but current MCP name/global queries return no named entity and decompilation still renders `unk_69B4BC`.
- Add formal first-draft C++ declaration `static std::uint32_t g_objectRecordCount = 0;`.
- Explain why unsigned 32-bit count is preferred over signed `int`.
- Preserve MapPane owner/emitter route and rejected `StaticObjImageLib`, `GameServerConfig`, parent-aggregate, and no-owner alternatives.

### Support: `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`

- Add current MCP session `ff68e691` evidence for the local window: twenty zero bytes, target slot xref counts `6/6/5/6/18`, current label caveat for `unk_69B4BC`/`unk_69B4C0`/`unk_69B4C4`, and parent non-emitting split/index status.
- Replace any current-evidence phrasing that still implies `0xffffffff` bytes.

### Support: `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`

- Add a small current-session note that `sub_504110` still has size `0x411`, owns the compact object-count/map loader sequence, and the exact loader instructions at `0x005042fa`, `0x00504315`, `0x00504331`, `0x00504397` match [UID:0002XQ].
- Preserve the mixed-owner/non-emitting aggregate conclusion.

### Support: `by-global/g_objectNationMap.md` and `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md`

- Only update if doing a local evidence sync: add current session `ff68e691`, zero bytes, six xrefs, and current label caveat. Do not change score/C++ unless a separate accepted report covers [UID:0002XR].

### Support: `by-global/g_gameServerNationTable.md` and `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md`

- Only update if doing a local evidence sync: add current session `ff68e691`, zero bytes, eighteen xrefs, and current label caveat. Keep GameServerConfig ownership and no MapPane declaration ownership for this slot.

### MapPane / Source-Family Docs

- [UID:0000L3][MapPane](../../../by-file/MapPane.md) is already sufficient at same-or-greater detail for the compact cache ownership and GameServerConfig rejection. No required edit unless the implementation wants to add one short current-session cross-reference.
- [UID:0002I7][MapPaneInitialize](../../../by-memory/0x00504110-0x00504521.MapPaneInitialize.md) already contains the first-draft constructor body using `g_objectRecordCount`; if edited, remove or narrow the stale "no fresh live IDA MCP" score-cap sentence because this report rechecked the constructor with current MCP for the object-count loader path.

## Expected Validators After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002XQ-g_objectRecordCount-source-quality-removed.md](0002XQ-g_objectRecordCount-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for files actually changed. If `g_objectNationMap`, `g_gameServerNationTable`, or `MapPaneInitialize` are already sufficient or are intentionally left for their own assignments, mark them already-present/not-applied with proof in the implementation checklist.

## Supervisor-Owned Coverage Text

Do not edit coverage reports during B-agent implementation. If accepted, supervisor should at minimum replace the [UID:0002XQ] row in `by-memory/-coverage-report.md`:

```text
        - [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md) 0x0069b4bc-0x0069b4c0 | global count | g_objectRecordCount : reconstructable : 88% : strong : Exact zero-initialized four-byte `.data` SOBJ record-count storage; B004 2026-06-23 MCP session `ff68e691` reconfirms bytes `00 00 00 00`, five direct data xrefs at `0x005042fa`, `0x00504315`, `0x00504331`, `0x00504397`, and `0x00505561`, loader/loop/consumer behavior through MapPane, relationship to [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md), assignment to [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), and blank exact-memory C++ because the by-global page carries the source declaration.
```

Recommended coherent local parent-row replacement for the same block:

```text
    - [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) 0x0069b4b4-0x0069b4c8 | mixed global-data cluster | MapNameMiniMapAndGameServerGlobals : ignored/non-emitting : 90% : very strong : Reviewed non-emitting mixed-owner split index over five adjacent zero-initialized four-byte `.data` slots; B004 2026-06-23 MCP session `ff68e691` and prior split docs confirm child xref counts `6/6/5/6/18`, exact children [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md), [UID:0002XP][0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane](by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md), [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md), [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md), and [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md); exact child/global pages carry source ownership and any declarations.
```

If supervisor applies sibling stale-byte cleanup in the same local block, replace [UID:0002XR] and [UID:0002XS] rows with zero-initialized wording:

```text
        - [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md) 0x0069b4c0-0x0069b4c4 | global pointer | g_objectNationMap : reconstructable : 86% : strong : Exact zero-initialized object-nation map pointer storage; current MCP reconfirms six xrefs across loader guard/allocation/fill, teardown read/clear, and consumer read, with assignment to [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) after the direct parent reached the gate.
        - [UID:0002XS][0x0069b4c4-0x0069b4c8.g_gameServerNationTable](by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md) 0x0069b4c4-0x0069b4c8 | global pointer | g_gameServerNationTable : reconstructable : 86% : strong : Exact zero-initialized game-server nation-table pointer storage; current MCP reconfirms 18 xrefs across raw constructor/destructor writes, map initializer writes, teardown reads, status/request users, copy/fallback consumers, and assignment to [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) after the direct parent reached the gate.
```

Recommended by-global coverage row if [UID:0000Q4] gets first-draft C++:

```text
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) : reconstructable : 89% : strong : SOBJ record count with exact split storage child [UID:0002XQ][0x0069b4bc-0x0069b4c0.g_objectRecordCount](by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md), current MCP-backed zero bytes and five xrefs, relation to [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), loader/count use, consumer bounds checks, MapPane compact-cache ownership, current-session IDB-label caveat, and first-draft private MapPane.cpp declaration `static std::uint32_t g_objectRecordCount = 0;`.
```

## Blockers / Open Questions

- Current MCP does not expose the accepted source-facing names as IDB names for this local `.data` window. This caps confidence but does not block documentation/C++ because source names are behavior-backed.
- Exact original spelling is unproven. `g_objectRecordCount` is the best source-facing descriptive name.
- Exact source type spelling is inferred. `static std::uint32_t` is the best first-draft choice; `static unsigned int` is acceptable if the final source style avoids `<cstdint>`.
- Exact source-file placement within `MapPane.cpp` is inferred as file-local static storage. No external consumer proves a header-level `extern` declaration.
- `SOBJ.TBL` header and one-byte field original names remain open, but this affects local parser variable names, not the count global's owner/type.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read current `Agent-B004/goal.md` and the project-level `ntk-b-agent-workflow` skill.
- [x] Read target [UID:0002XQ] and direct/support docs listed in the assignment.
- [x] Used current MCP session `ff68e691`; health/list/schema, session, bytes, xrefs, disassembly/decompilation, and related route checks succeeded.
- [x] Performed supplemental bounded PE byte-pattern checks for direct VA/RVA/raw-offset route evidence.
- [x] Did not edit by-* docs, generated/project-level files, IDA DB, tool state, or any `-coverage-report.md`.
- [x] Wrote this report in the Agent-B004 research folder.

Implementation callback items after supervisor acceptance:

- [x] Leased exact edit set as B004 before editing: target [UID:0002XQ], `by-global/g_objectRecordCount.md`, parent aggregate [UID:00029X], [UID:0001AO], sibling globals/memory children [UID:0000Q3]/[UID:0002XR] and [UID:0000Q1]/[UID:0002XS], and [UID:0002I7] `MapPaneInitialize`. Lease command succeeded for all nine files.
- [x] Target `by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md`: updated to `COMPLETION:88`, `CONFIDENCE:88`; kept owner/emitter/reconstructable metadata unchanged; added current session `ff68e691` MCP/PE evidence, exact zero bytes, five xrefs with route classification, loader/consumer disassembly/decompilation, current label caveat, sibling xref relationship, source-placement/rejected-alternative reasoning, and explicit target no-duplicate-output proof.
- [x] `by-global/g_objectRecordCount.md`: raised to `COMPLETION:89`, kept `CONFIDENCE:89`; added first-draft C++ `static std::uint32_t g_objectRecordCount = 0;`; added current session `ff68e691` evidence, current label caveat, unsigned-count/type rationale, MapPane owner/emitter route, and rejected StaticObjImageLib/GameServerConfig/parent-aggregate/no-owner/duplicate-declaration alternatives.
- [x] `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`: added current zero-byte/window evidence, child xref counts `6/6/5/6/18`, current label caveat for `unk_69B4BC`/`unk_69B4C0`/`unk_69B4C4`, updated [UID:0002XQ]/[UID:0000Q4] score references to `88/88` and `89/89`, and preserved non-emitting mixed-owner split/index status.
- [x] `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`: added current-session loader/xref note for `0x00504110` and [UID:0002XQ] covering `0x005042fa`, `0x00504315`, `0x00504331`, and `0x00504397`; preserved the mixed aggregate/no-C++ disposition.
- [x] `by-global/g_objectNationMap.md` and `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md`: local sibling evidence sync applied because stale saved-label wording contradicted current session `ff68e691`; added zero-byte/six-xref/current-label caveat notes without changing score or C++.
- [x] `by-global/g_gameServerNationTable.md` and `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md`: local sibling evidence sync applied because stale current-label wording contradicted current session `ff68e691`; added zero-byte/eighteen-xref/current-label caveat notes without changing score or C++.
- [x] `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`: narrowed the stale "no fresh live IDA MCP" confidence caveat after current-session recheck, added a `2026-06-23 B004 g_objectRecordCount Route Recheck` section, and kept score/C++ unchanged.
- [x] Preserved rejected alternatives: target/global pages explicitly reject parent aggregate owner, GameServerConfig declaration owner, StaticObjImageLib owner, adjacent singleton ownership, no-owner/non-emitting, signed `int` as primary type, and duplicate declaration on both by-global and exact memory child.
- [x] Preserved superseded history: older `0xffffffff` byte notes remain historical/superseded only; current evidence in target/support docs is zero bytes.
- [x] Supervisor-owned coverage: did not edit any `-coverage-report.md`; exact replacement rows remain in this report for supervisor application after verification.
- [x] Validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:
  - `python .\tools\validator.py --mode file --file by-memory\0x0069b4bc-0x0069b4c0.g_objectRecordCount.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\g_objectRecordCount.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\g_objectNationMap.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0069b4c0-0x0069b4c4.g_objectNationMap.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-global\g_gameServerNationTable.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00504110-0x00504521.MapPaneInitialize.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
- [x] Validator side effects recorded: final concise validation pass reported validator-owned `autogen_registry_rebuild` for `validator.ini` and `projected_stats_update` for `project-level/-auto-completion-stats.md` on each scoped command; no manual generated/project-level edits were made.
- [x] Lease cleanup: `python leaser.py B004 unlease ...` reported `Rejected[No active lease]` for all nine files because the 300-second leases had already expired during the validator batch; `tools/leaser/Agents/current_leases.md` then reported `No active leases`.
- [x] This checklist was updated with implementation proof; no accepted non-coverage item remains unchecked.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002XQ-g_objectRecordCount-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002XQ"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002XQ-g_objectRecordCount-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002XQ-g_objectRecordCount-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002XQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
