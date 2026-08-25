** TARGET-REPORT-UID:0002XR **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002XR g_objectNationMap Source-Quality Research

## Final Recommendation

- Target: [UID:0002XR] `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md`.
- Assignment: `B005-report-g-object-nation-map-source-quality-0002XR-mcp-20260623`.
- Report-only status: no leases taken, no by-* docs edited, no generated/project-level files edited, no IDA DB/tool-state edits, and no `-coverage-report.md` edits.
- Recommendation for [UID:0002XR]: raise from `86/86` to `88/90`, keep `CANONICAL_OWNER:0000Q3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000Q3`, and keep `EMITTER_POSITION_OPTIONAL:` blank.
- C++ recommendation for [UID:0002XR]: keep the exact by-memory storage child C++ blank. The four-byte child is storage documentation; the source declaration should live on [UID:0000Q3] `by-global/g_objectNationMap.md`.
- Support C++ recommendation if accepted: add the declaration to [UID:0000Q3] and raise the global parent from `88/89` to `89/90`:

```cpp
static std::uint8_t* g_objectNationMap = NULL;
```

The pointer role, address, lifecycle, and MapPane source placement are now strong. The original IDB does not currently expose a named `g_objectNationMap` entity, and SOBJ per-record field spellings remain inferred, so confidence should stay below final-source certainty.

## Current Target State

The target page is already useful but still reflects B004 sibling-sync wording and score:

- `COMPLETION:86`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000Q3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000Q3`
- `EMITTER_POSITION_OPTIONAL:` blank
- Formal C++ block: blank.

Current useful target facts to retain:

- Exact range: `0x0069b4c0-0x0069b4c4`.
- Entity kind: four-byte `.data` global pointer storage.
- Initial bytes: `00 00 00 00`.
- Direct parent: [UID:0000Q3] `g_objectNationMap`.
- The slot belongs to the MapPane-owned compact SOBJ object-to-nation/classification cache, alongside [UID:0002XQ] `g_objectRecordCount`.
- Direct references cover loader guard/allocation/fill, teardown read/clear, and collision/classification consumer read.

Current stale or incomplete facts to replace:

- The target names B004 session `ff68e691` as the current evidence basis. This report rechecked the target with active MCP session `80de0a67`.
- The target still leaves the score at `86/86` even though current MCP evidence now covers function/no-function status, exact bytes, xrefs, decompilation of loader/cleanup/consumer functions, name/global negative checks, VA/RVA pointer-pattern checks, and owner/source-placement analysis.
- The target should make clear that current IDA renders the storage as `unk_69B4C0` and exposes no named `g_objectNationMap` record; the source-facing name remains best supported by the project docs, historical label work, and MapPane lifecycle behavior, not by a current IDB symbol.
- The target should not receive formal C++. If accepted, the declaration belongs on [UID:0000Q3] because that by-global page is the source declaration owner.

## MCP And Binary Evidence Checked

Current IDA MCP session evidence:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active database/session used for this report: `80de0a67`.
- JSON-RPC `initialize`, `tools/list`, `server_health(database='80de0a67')`, and `idb_list` succeeded.
- `server_health` returned `status=ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `idb_list` returned active session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, backend worker process active.
- `survey_binary(minimal)` reports PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x400000`, image size `0x2b3000`, `.text 0x00401000-0x0060d000`, `.idata 0x0060d000-0x0060d670`, `.rdata 0x0060d670-0x0066d000`, and `.data 0x0066d000-0x0069d000`.

Target storage evidence:

- `get_bytes(0x0069b4c0, 4)` returned `00 00 00 00`.
- `get_bytes(0x0069b4bc, 12)` returned all zero bytes for `g_objectRecordCount`, `g_objectNationMap`, and `g_gameServerNationTable`.
- `get_bytes(0x0069b4b4, 20)` returned all zero bytes for the full [UID:00029X] adjacent global cluster.
- `get_global_value(0x0069b4bc)`, `get_global_value(0x0069b4c0)`, and `get_global_value(0x0069b4c4)` each returned `0x0`.
- `get_global_value` by the names `g_objectRecordCount`, `g_objectNationMap`, and `g_gameServerNationTable` returned `Not found`.
- `entity_query` over `0x0069b4b4-0x0069b4c8` returned zero names and zero globals.
- `entity_query` for name patterns `g_object`, `objectNation`, `gameServerNation`, and `unk_69B4` returned zero target records.
- `list_globals` filters for `*object*`, `*Nation*`, and `*69B4C0*` did not return `g_objectNationMap` or a named target record.
- `lookup_funcs(0x0069b4c0)`, `lookup_funcs(0x0069b4bc)`, and `lookup_funcs(0x0069b4c4)` each reported not a function.

Direct xref evidence:

- `xrefs_to(0x0069b4c0)` returned six xrefs:
  - `0x005042de` in `sub_504110`: loader guard compares `unk_69B4C0` against zero.
  - `0x00504324` in `sub_504110`: loader stores allocation result to `unk_69B4C0`.
  - `0x0050438b` in `sub_504110`: loader reads the pointer to store per-record bytes.
  - `0x0050463d` in `sub_504530`: cleanup reads the pointer before freeing.
  - `0x00504653` in `sub_504530`: cleanup clears/stores the free-helper result back to `unk_69B4C0`.
  - `0x0050557e` in `sub_505430`: consumer reads the pointer for object classification/direction-mask checks.
- `xrefs_to(0x0069b4bc)` returned five xrefs: `0x005042fa`, `0x00504315`, `0x00504331`, `0x00504397`, and `0x00505561`.
- `xrefs_to(0x0069b4c4)` returned eighteen xrefs, proving `g_gameServerNationTable` is a separate adjacent GameServerConfig table, not the same object as `g_objectNationMap`.
- The exclusive end `0x0069b4c4` is the next four-byte sibling, so xrefs to that address are not boundary evidence against [UID:0002XR].

Function context evidence:

- `lookup_funcs(0x00504110)` returns `sub_504110`, size `0x411`, the MapPane initialization/loader function.
- `lookup_funcs(0x00504530)` returns `sub_504530`, size `0x196`, the MapPane cleanup/teardown function.
- `lookup_funcs(0x00505430)` returns `sub_505430`, size `0x19a`, the object collision/classification consumer helper.
- `xrefs_to(0x00504110)` returns two code xrefs at `0x004f7dfa` and `0x004f85ef`, both inside `sub_4F7D10`.
- `xrefs_to(0x00504530)` returns one code xref at `0x00514de6`, inside `sub_514DE0`.
- `xrefs_to(0x00505430)` returns nine code xrefs: four in `sub_50C790`, four in `sub_50D010`, and one in `sub_5A2E00`.

Loader, cleanup, and consumer decompilation evidence:

- `decompile(0x00504110)` shows `if ( !unk_69B4C0 )`, opens the SOBJ resource path through `off_61C1A4`, reads four bytes into `unk_69B4BC`, reads a two-byte table header, allocates `unk_69B4BC + 1` bytes through `sub_516050`, seeds `*(_BYTE *)unk_69B4C0 = 0`, loops while the record index is less than `unk_69B4BC`, reads `4 + 1 + 1 + 1 + 2 * count` bytes per record shape, and stores the second one-byte field into `*((_BYTE *)unk_69B4C0 + index)`.
- `decompile(0x00504530)` shows `if ( unk_69B4C0 )`, reads the pointer, calls cleanup/free helpers, and assigns the result of `sub_516170(v10)` back to `unk_69B4C0`. Current MCP does not show a direct `0x0069b4bc` count reset xref in this function.
- `decompile(0x00505430)` shows a `__thiscall` helper using map/object lists, `_wcsicmp(..., L"GM")`, two `sub_50C120` calls, `unk_69B4BC` bounds checks, `unk_69B4C0` indexed loads, and direction masks at `byte_66DD50` and `byte_66DD58`. The helper name and mask semantics remain inferred, but the object-map consumer role is direct.

Targeted byte-pattern and negative checks:

- `find_bytes` for the VA little-endian pointer `c0 b4 69 00` returned exactly six matches at the direct xref sites: `0x005042e0`, `0x00504325`, `0x0050438c`, `0x0050463e`, `0x00504654`, and `0x00505580`.
- `find_bytes` for the RVA form `c0 b4 29 00` returned zero matches.
- `find_bytes` for count VA `bc b4 69 00` returned five matches, matching [UID:0002XQ].
- `find_bytes` for count RVA `bc b4 29 00` returned zero matches.
- `find_bytes` for `g_gameServerNationTable` VA `c4 b4 69 00` returned eighteen matches, matching the separate sibling global.
- `find_bytes` for `g_gameServerNationTable` RVA `c4 b4 29 00` returned zero matches.

Documentation/generated evidence checked:

- Target page [UID:0002XR] and parent [UID:0000Q3].
- Related globals [UID:0000Q4] `g_objectRecordCount` and [UID:0000Q1] `g_gameServerNationTable`.
- Source/root pages [UID:0000L3] `MapPane` and [UID:0000JP] `GameServerConfig`.
- Support memory pages [UID:0001AO] `GameServerNationAndMapInit`, `0x00504110-0x00504521.MapPaneInitialize`, `0x00504530-0x005046c6.MapPaneCleanup`, [UID:00029X] `MapNameMiniMapAndGameServerGlobals`, and `0x0066dd50-0x0066dd60.MapObjectDirectionMasks`.
- `by-meta/client_map_system.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`, `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-global-coverage.md`, `by-memory/-coverage-report.md`, and `by-global/-coverage-report.md`.
- No MCP failures occurred during this evidence pass.

## Heuristic And Inference Reanalysis

Claim: `0x0069b4c0-0x0069b4c4` is best documented as source-facing `g_objectNationMap`.

- Confidence: strong for storage and behavior, medium-high for original spelling.
- Direct evidence: the slot is a zero-initialized `.data` pointer, has exactly six direct references, and every reference is part of the MapPane SOBJ compact-cache lifecycle: loader guard/allocation/fill, cleanup/free/clear, and consumer lookup.
- Supporting evidence: [UID:0000Q3], [UID:0000Q4], [UID:0000L3], and MapPane constructor/destructor docs already use `g_objectNationMap` coherently with the accepted MapPane source shape.
- Current caveat: MCP session `80de0a67` does not expose a named `g_objectNationMap` entity and disassembly/decompilation render the storage as `unk_69B4C0`. Historical saved-label work and project-level resolved entries support the source-facing name, but the current IDB does not independently prove spelling.
- Rejected alternate naming: raw `unk_69B4C0` is the current IDB display name, not a source name. `dword_69B4C0` is a storage label, not a semantic source declaration. A generic `g_objectClassificationMap` remains plausible but weaker than the established project name because docs, parent page, count sibling, and MapPane C++ already converge on `g_objectNationMap`.

Claim: the by-global parent should receive C++ rather than this exact by-memory child.

- Confidence: strong.
- Direct evidence: [UID:0002XR] is an exact four-byte storage child. It documents address, bytes, and xrefs, but it is not a function and has no source body.
- Source-shape evidence: [UID:0000Q3] is the source declaration parent, emits through [UID:0000L3] `MapPane`, and is paired with [UID:0000Q4], which already carries `static std::uint32_t g_objectRecordCount = 0;`.
- Recommended declaration: `static std::uint8_t* g_objectNationMap = NULL;`. The `std::uint8_t*` type matches byte-indexing behavior and the sibling `std::uint32_t` count style. `NULL` matches the surrounding MapPane constructor/destructor C++ style. If the project later standardizes on `unsigned char*` or `nullptr`, that is a spelling/style adjustment rather than a behavior change.

Claim: MapPane remains the source placement and GameServerConfig is rejected for this target.

- Confidence: strong.
- Direct evidence: all six xrefs to `0x0069b4c0` occur in MapPane initialization, MapPane cleanup, or MapPane object collision/classification logic. `g_gameServerNationTable` is adjacent at `0x0069b4c4` but has eighteen separate xrefs and a different GameServerConfig ownership route.
- Supporting evidence: [UID:0000L3] already documents `g_objectNationMap` and `g_objectRecordCount` as MapPane compact SOBJ cache globals. [UID:0000JP] already keeps `g_gameServerNationTable` as the GameServerConfig-owned table.
- Rejected source placement: `GameServerConfig.cpp` owns the game-server nation table, not the object map pointer. `StaticObjImageLib` parses the same SOBJ resource family but owns static object image records, not this compact MapPane gameplay/classification cache.

## Positive And Negative Evidence

Positive evidence:

- Exact zero bytes for the target and full adjacent global cluster in current MCP session `80de0a67`.
- Exact `.data` storage range with not-function status at `0x0069b4c0`.
- Six direct xrefs exactly matching loader, cleanup, and consumer behavior.
- Loader decompilation proves lazy allocation of `count + 1`, slot-zero seed, and per-record byte stores into the allocated map.
- Cleanup decompilation proves read/free/clear behavior for the pointer.
- Consumer decompilation proves indexed byte reads from the pointer guarded by record count and combined with direction masks.
- VA byte-pattern search finds only the same six direct target references; RVA pattern search finds none.
- Adjacent count and game-server table siblings have distinct xref sets, supporting the exact four-byte split.
- Source placement through MapPane is consistent with current target/support docs and generated output root `auto-generated/NexusTK/map/MapPane.cpp`.

Negative evidence and rejected alternatives:

- Current IDB named-global proof is absent. `get_global_value` by `g_objectNationMap`, `entity_query`, and `list_globals` do not expose a named record; docs should not claim the current session has a live saved symbol.
- [UID:0000Q4] `g_objectRecordCount` is rejected as direct owner. It is the paired count global and bounds/allocation input, not the pointer storage.
- [UID:0000Q1] `g_gameServerNationTable` is rejected as direct owner. It is the adjacent `0x0069b4c4` pointer with eighteen separate xrefs and a GameServerConfig route.
- [UID:0000JP] `GameServerConfig` is rejected as direct source placement for this pointer. The overlap is neighborhood/resource context only.
- [UID:00029X] parent aggregate is rejected as direct owner/emitter. It is a mixed five-slot cluster over map-pane singletons and game-server globals; exact children/globals carry source ownership.
- [UID:0000L3] `MapPane` is the source file owner/root but should not replace [UID:0000Q3] as the direct canonical owner of this exact storage child while the by-global parent exists and clears the gate.
- Adjacent globals `g_pMapNamePane`, `g_pMiniMapButtonPane`, and `g_gameServerNationTable` are rejected because their addresses and xref sets are distinct.
- No-owner/non-emitting is rejected. The current IDB name caveat caps confidence but does not erase the coherent lifecycle and source owner route.
- A formal C++ body on [UID:0002XR] is rejected. The exact child is storage evidence, not the source declaration page.

## Ranked Ownership And Source Placement

1. [UID:0000Q3] `g_objectNationMap`: accepted as direct canonical owner/emitter for [UID:0002XR]. It is the exact source declaration parent for the pointer storage and emits through MapPane.
2. [UID:0000L3] `MapPane`: accepted as source file/root owner for the by-global parent. All target xrefs are in MapPane loader/cleanup/consumer behavior.
3. [UID:0000Q4] `g_objectRecordCount`: support sibling only. It proves the allocation/bounds/count relationship but does not own the pointer.
4. [UID:0000Q1] `g_gameServerNationTable`: adjacent sibling and GameServerConfig-owned dependency only. Its eighteen xrefs and source route are separate.
5. [UID:0000JP] `GameServerConfig`: rejected as direct owner for [UID:0002XR]. It is source context for the adjacent game-server table, not the object-nation map.
6. [UID:00029X] `MapNameMiniMapAndGameServerGlobals`: non-emitting mixed aggregate. Keep it as the cluster index; do not use it as direct owner.
7. `StaticObjImageLib` / resource parser routes: rejected as owner. They parse related SOBJ data but do not own this compact MapPane cache pointer.
8. No-owner/non-emitting: rejected because the target has a clear by-global parent and coherent MapPane lifecycle evidence.

Recommended source placement remains `NexusTK/map/MapPane.cpp` through [UID:0000L3]. If headers are generated, the declaration could live as a file-static variable in the MapPane implementation unit; the current docs should not move it to `GameServerConfig.cpp`.

## Score And Metadata Recommendation

Recommended [UID:0002XR] metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000Q3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000Q3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Completion rationale:

- Raise to `88` because the current report now includes active MCP session `80de0a67`, PE hash, exact bytes, section role, no-function status, current name/global negative checks, complete xref inventory, loader/cleanup/consumer decompilation, direct disassembly sites, sibling xref comparison, VA/RVA negative pointer-pattern checks, owner/source-placement ranking, C++ no-code proof for the memory child, and specific support/coverage edits.
- Do not raise higher because the exact source-facing symbol spelling is not present in the current IDB, the consumer helper name remains unresolved, and SOBJ one-byte field names are still semantic inferences.

Confidence rationale:

- Raise to `90` because the storage role and behavior are directly proved by bytes, xrefs, decompilation, and sibling negative checks.
- Keep below `92+` because `g_objectNationMap` is a source-facing project name rather than a current live IDB symbol, and the local record-field semantics cannot yet distinguish original terminology from descriptive reconstruction names.

Recommended [UID:0000Q3] by-global metadata if implementation also accepts parent C++:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The parent improvement is warranted because the declaration is now source-ready. It should still stay below final-source confidence for the same current-IDB spelling and field-name caveats.

## First-Draft C++ / No-Code Disposition

[UID:0002XR] no-code proof:

- The target is a four-byte data slot, not a function.
- `lookup_funcs(0x0069b4c0)` reports not a function.
- Its source manifestation is a declaration, not executable code.
- The direct source declaration page exists as [UID:0000Q3] and already emits through [UID:0000L3].
- Adding the declaration to [UID:0002XR] would duplicate the by-global source declaration and risk two emitted declarations for one storage slot.

Recommended [UID:0000Q3] first-draft C++:

```cpp
static std::uint8_t* g_objectNationMap = NULL;
```

Behavior and source-shape requirements:

- Keep the declaration file-static under MapPane source placement.
- Do not assign `0xffffffff`; current bytes and coverage already prove zero initialization.
- Do not initialize with an allocation. Allocation remains in `MapPaneInitialize` / MapPane constructor behavior.
- Do not move the declaration to `GameServerConfig`.
- Preserve caveats that the original source may have used `unsigned char*`, `BYTE*`, `std::uint8_t*`, `nullptr`, or another local style. The recommended draft chooses the style most consistent with current sibling docs.

## Recommended Target And Support Doc Changes

| Path | Recommended change |
| --- | --- |
| `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md` | Change score to `88/90`, keep owner/emitter `0000Q3`, keep C++ blank, replace `ff68e691` current-evidence wording with session `80de0a67`, add PE SHA-256, exact zero bytes, `.data` role, no-function status, no current named global record, six xrefs with addresses/functions, loader/cleanup/consumer decompilation facts, VA/RVA pattern checks, sibling xref comparison, owner rejections, no-code proof, and caveats for original spelling/SOBJ field names. |
| `by-global/g_objectNationMap.md` | Raise to `89/90` if accepted, add first-draft declaration `static std::uint8_t* g_objectNationMap = NULL;`, replace stale `ff68e691` current-proof wording with `80de0a67`, retain historical saved-label context as historical only, add current name/global negative checks, exact xrefs, loader/cleanup/consumer detail, MapPane source placement, GameServerConfig rejection, and unresolved source-spelling/record-field caveats. |
| `by-global/g_objectRecordCount.md` | No score/C++ change required. If touched for support sync, add that session `80de0a67` reconfirmed five xrefs and the paired allocation/bounds relationship; preserve the existing declaration and MapPane ownership. |
| `by-global/g_gameServerNationTable.md` | No score/C++ change required. If touched, add only the negative route clarification that `0x0069b4c4` has eighteen distinct xrefs and remains GameServerConfig-owned, separate from [UID:0002XR]. |
| `by-file/MapPane.md` | Add/refresh support text that the MapPane source owns the compact SOBJ globals `g_objectRecordCount` and `g_objectNationMap`; [UID:0002XR] remains a storage child, while [UID:0000Q3] carries the source declaration. Mention current MCP `80de0a67` and rejected GameServerConfig route. |
| `by-file/GameServerConfig.md` | No material change required if the current split already says GameServerConfig owns `g_gameServerNationTable` and not the object map. If stale wording implies ownership of `g_objectNationMap`, correct it. |
| `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md` | Refresh the aggregate support note: MapPane half loads `g_objectRecordCount` and lazily allocates/fills `g_objectNationMap`; GameServerConfig half owns `g_gameServerNationTable`; aggregate remains non-emitting/mixed-owner. |
| `by-memory/0x00504110-0x00504521.MapPaneInitialize.md` | Replace stale session wording if present, retain constructor C++ shape, add current MCP details for `0x005042de`, `0x00504324`, `0x0050438b`, allocation `count + 1`, slot-zero seed, and per-record second-byte store. Preserve uncertainty over exact SOBJ field names. |
| `by-memory/0x00504530-0x005046c6.MapPaneCleanup.md` | Add current MCP details for `0x0050463d` pointer read and `0x00504653` clear/store. Avoid claiming current MCP directly proves a `g_objectRecordCount` reset in this function unless a separate accepted pass verifies that xref. |
| `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md` | Update the [UID:0002XR] child row/note to `88/90` and session `80de0a67`; keep aggregate ownerless/non-emitting and retain the child/sibling split. |
| `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md` | Optional support update if implementing consumer detail: cite `sub_505430` using `g_objectRecordCount`, `g_objectNationMap`, and direction masks at `byte_66DD50`/`byte_66DD58`; no score/owner change required. |
| `by-meta/client_map_system.md` | Optional support update if current map-system text is too terse: add current-session note that the compact SOBJ object-to-nation cache is MapPane-owned and distinct from GameServerConfig's `g_gameServerNationTable`. |

No new exact child page for `0x00505430` is recommended in this callback. The consumer helper currently lives inside a broader MapPane core page; a future split can handle helper naming and formal C++ when the supervisor assigns it.

## Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` or `by-global/-coverage-report.md` as B005. If accepted, replace the current [UID:0002XR] row in `by-memory/-coverage-report.md` with:

```text
        - [UID:0002XR][0x0069b4c0-0x0069b4c4.g_objectNationMap](by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md) 0x0069b4c0-0x0069b4c4 | global pointer | g_objectNationMap : reconstructable : 88% : very-strong : IDA MCP session `80de0a67` confirms exact zero-initialized four-byte `.data` pointer storage bytes `00 00 00 00`, not-function status, no current named global record for `g_objectNationMap`, six direct xrefs at `0x005042de`, `0x00504324`, `0x0050438b`, `0x0050463d`, `0x00504653`, and `0x0050557e`, loader allocation/fill through `MapPaneInitialize`, teardown read/free/clear through `MapPaneCleanup`, consumer indexed reads in `sub_505430` with `g_objectRecordCount` and direction masks, distinct sibling xref sets for [UID:0002XQ] and [UID:0002XS], assignment to [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), blank exact-memory C++ because the by-global parent carries the source declaration, and caveats for original symbol spelling and SOBJ field names.
```

If accepted, replace the current [UID:0000Q3] row in `by-global/-coverage-report.md` with:

```text
- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) : reconstructable : 89% : very-strong : MapPane-owned compact SOBJ object-to-nation byte-map pointer; IDA MCP session `80de0a67` confirms exact storage child [UID:0002XR], zero initial bytes, six loader/teardown/consumer xrefs, current IDB `unk_69B4C0` naming/no named-global caveat, paired [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) allocation and bounds relationship, distinct [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) rejection, first-draft file-static declaration `static std::uint8_t* g_objectNationMap = NULL;`, and unresolved original spelling/SOBJ record-field caveats.
```

Optional supervisor note: the parent [UID:00029X] aggregate row already says all five slots are zero-initialized and should only need its [UID:0002XR] child score/session wording updated if the supervisor wants coverage cluster sync in the same pass.

## Validator Results After Accepted Implementation

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002XR-g_objectNationMap-source-quality-removed.md](0002XR-g_objectNationMap-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The initial unfiltered validator batch completed with `exit=0` through the final file. A second concise pass over the same seven changed files captured the exact `ok: 1` counts above. Optional docs were not validated because they were not changed.

## Implementation Tracking Checklist

Accepted implementation callback completed by B005.

- [x] Lease exact target/support by-* files only when ready to edit. Proof: B005 successfully leased the seven required changed docs before the implementation patch; after a final wording cleanup, B005 reacquired the same exact seven-file lease set before the post-cleanup validator rerun. Final `unlease` succeeded for all seven B005 paths; the subsequent lease report contained no B005 entries. Later unrelated B001 Application leases do not overlap this assignment.
- [x] Update `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md`: metadata changed to `88/90`; owner/emitter kept `0000Q3`; formal C++ kept blank; added current MCP `80de0a67` evidence, PE SHA-256, exact zero bytes, `.data` and not-function status, no named-global caveat, six xrefs, loader/cleanup/consumer details, VA/RVA negatives, sibling xref comparison, owner rejections, no-code proof, and original spelling/SOBJ field-name caveats. Validator: `exit=0`, `ok: 1`.
- [x] Update `by-global/g_objectNationMap.md`: metadata changed to `89/90`; owner/emitter kept through [UID:0000L3] `MapPane`; added `static std::uint8_t* g_objectNationMap = NULL;` in the reconstruction block using the local empty-inline/block-code convention; added current MCP evidence, no current named-global caveat, exact six-xref lifecycle, MapPane source placement, paired `g_objectRecordCount` relationship, rejected GameServerConfig/sibling/aggregate/no-owner alternatives, and unresolved source-spelling/SOBJ field caveats. Validator: `exit=0`, `ok: 1`; final rerun cleared `0000Q3` autogen metadata and updated `auto-generated/NexusTK/map/MapPane.cpp` with the `UID:0000Q3` declaration.
- [x] Check `by-global/g_objectRecordCount.md`: not edited. Reason: accepted callback did not include it in the allowed target/support set, and the changed MapPane/g_objectNationMap docs now carry the paired count relationship without needing a separate count-page edit.
- [x] Check `by-global/g_gameServerNationTable.md`: not edited. Reason: accepted callback explicitly reserved the GameServerConfig/table side for B003 unless a direct contradiction would make the object-map implementation wrong; no such contradiction was found.
- [x] Update `by-file/MapPane.md`: added the MapPane-owned compact SOBJ cache declaration route, by-global/by-memory split, current MCP `80de0a67` loader/cleanup/consumer xrefs, `g_objectRecordCount` pairing, [UID:0002XR] storage-child role, and GameServerConfig rejection. Validator: `exit=0`, `ok: 1`.
- [x] Check `by-file/GameServerConfig.md`: not edited. Reason: callback prohibited GameServerConfig-side edits unless direct contradiction existed; no direct contradiction was needed to implement the accepted object-map split.
- [x] Update `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`: added the mixed aggregate distinction that the MapPane half loads count/object map while the GameServerConfig half owns `g_gameServerNationTable`, with current object-map loader/cleanup/consumer xrefs and no-emitter rationale. Validator: `exit=0`, `ok: 1`.
- [x] Update `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`: added current `80de0a67` allocation/fill evidence at `0x005042de`, `0x00504324`, and `0x0050438b`, including allocation `count + 1`, slot-zero seed, per-record second-byte store, sibling split, and field-name caveats. Validator: `exit=0`, `ok: 1`.
- [x] Update `by-memory/0x00504530-0x005046c6.MapPaneCleanup.md`: added current pointer read/free/clear evidence at `0x0050463d` and `0x00504653`; explicitly avoided claiming the current MCP pass directly proves a `g_objectRecordCount` reset in this function. Validator: `exit=0`, `ok: 1`.
- [x] Update `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`: updated the [UID:0002XR] child row/note to `88/90`, current session `80de0a67`, and exact xref/name-caveat details while keeping the aggregate non-emitting mixed-owner split index. Validator: `exit=0`, `ok: 1`.
- [x] Optionally update `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md` only if consumer detail materially improves stale text. Not edited. Reason: current page already covers the consumer distinction through `sub_505430`, `g_objectRecordCount`, `g_objectNationMap`, and direction masks at same-or-greater useful detail for this callback.
- [x] Optionally update `by-meta/client_map_system.md` only if map-system overview lacks the compact-cache/GameServerConfig split. Not edited. Reason: current overview already distinguishes the compact SOBJ object-to-nation cache from GameServerConfig table ownership sufficiently for this callback.
- [x] Do not edit `by-memory/-coverage-report.md`; left the supplied [UID:0002XR] replacement row for supervisor-owned application.
- [x] Do not edit `by-global/-coverage-report.md`; left the supplied [UID:0000Q3] replacement row for supervisor-owned application.
- [x] Run validators for every changed by-* doc from `source-3/project-documentation` and record command, exit code, and ok count. Proof: all seven changed by-* docs validated with `exit=0`, `ok: 1`.
- [x] Release any future leases immediately after the edit/scoped-validator batch. Proof: final `python tools\leaser\leaser.py B005 unlease ...` returned `Success` for all seven changed docs; current lease report contains no B005 entries.

## Implementation Completion Notes

- Accepted non-coverage edits are applied. No `-coverage-report.md` file was edited.
- Current accepted evidence remains MCP-backed by session `80de0a67`; no fallback-only implementation evidence was introduced.
- No subagents were spawned.
- No IDA DB or tool-state files were edited by hand. Validator side effects were limited to the scoped validator runs required for changed by-* docs.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002XR-g_objectNationMap-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002XR"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002XR-g_objectNationMap-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002XR-g_objectNationMap-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002XR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
