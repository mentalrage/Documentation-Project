** TARGET-REPORT-UID:000088 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000088 MetaMan Class Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:000088] `MetaMan` as a reconstructable class owned and emitted by [UID:0000LC] `MetaMan`, routed to `NexusTK/metadata/MetaMan.cpp`.
- Recommended target metadata after supervisor acceptance: raise [UID:000088] from `COMPLETION:86`, `CONFIDENCE:85` to `COMPLETION:89`, `CONFIDENCE:88`; keep `CANONICAL_OWNER:0000LC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Recommended C++ policy: the class page is now ready for a first-draft source-style class declaration/prototype block. Do not put the broad method/helper bodies into the class page. Keep compiler-generated scalar deleting destructor and STL/tree helper glue out of formal source; model them through the class declaration and `std::map<SimpleUString, MetaTable *>` ownership.
- Recommended source placement: `metadata/MetaMan.h`/`metadata/MetaMan.cpp` remains the best reconstruction route. A flat original `MetaMan.cpp` is plausible historically, but the current `NexusTK/metadata/` source root is the correct project route because this subsystem owns loose metadata cache/sync behavior, not packed DAT archive behavior or UI consumer behavior.
- Confidence basis: high for ownership, class role, object size/layout, field roles, method inventory, `Meta.dat` cache route, packet subtype behavior, singleton/global use, and helper-family role; medium-high for exact original private member spellings, exact original alias key symbol/literal spelling, and outer `Meta.dat` secondary-field names. No live IDA MCP resources were exposed in this session; current evidence comes from the existing IDA-backed docs, exported function JSON, generated source output, and coverage rows.

## Target
- Target UID: `000088`
- Target path: `source-3/project-documentation/by-class/MetaMan.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/000088-MetaMan-class-source-quality.md`
- Current state: `COMPLETION:86`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000LC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LC`; formal C++ is blank.
- Current target issue: the target still says exact field layout and helper names around `0x005237d0-0x00523c99` need a struct/name pass, and it points at stale generated paths. The current active code-entry gate is `(COMPLETION + CONFIDENCE) / 2 > 85` with a valid emitter route, not the old `95/95` gate. This pass resolves enough source-quality detail to add a class declaration and update support docs while keeping mixed helper aggregates and generated wrappers blank for target-specific reasons.

## Report-Only Scope
- This was report-only work. I did not edit `by-class/MetaMan.md`, support by-* docs, `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, or generated coverage/source files.
- The report preserves support-doc implementation instructions for a later supervisor callback.
- I attempted to read the external loose resource `E:\2026\Resources\Read_Only\NexusTK\Meta.dat` directly, but the session returned access denied for that path. I therefore do not claim a new raw-resource parse in this report; shipped-file facts are taken from [UID:0001RH] `meta-dat-metadata-cache`, which already records a prior raw-resource audit.

## Evidence Checked
- Instruction and workflow docs:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B009/goal.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/tools/leaser/docs/inference_research.md`
  - `source-3/project-documentation/by-meta/proposed-source-tree.md`
- Primary and required support docs:
  - `by-class/MetaMan.md`
  - `by-file/MetaMan.md`
  - `by-memory/0x005227d0-0x00524581.MetaMan.md`
  - `by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md`
  - `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
  - `by-class/MetaTable.md`
  - `by-global/g_pMetaMan.md`
  - `by-global/g_metaAliasTableName.md`
  - `by-memory/0x0069b410-0x0069b414.g_pMetaMan.md`
  - `by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md`
  - `by-resource/meta-dat-metadata-cache.md`
  - `by-meta/client_dat_specifications.md`
  - `by-file/DATFile.md`
  - `by-class/ItemHelpPane.md`
  - `by-class/CollectionPane.md`
  - `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`
- Generated/coverage evidence:
  - `source-3/simroot_v2/metadata/MetaMan.cpp`
  - `source-3/project-documentation/auto-generated/NexusTK/metadata/MetaMan.cpp`
  - `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
  - `source-3/project-documentation/by-class/-coverage-report.md`
  - `source-3/project-documentation/by-memory/-coverage-report.md`
- Exported reverse-engineering data:
  - `resources/exported_data/functions/0x005227d0.json`
  - `resources/exported_data/functions/0x00522860.json`
  - `resources/exported_data/functions/0x005228f0.json`
  - `resources/exported_data/functions/0x00522950.json`
  - `resources/exported_data/functions/0x00522960.json`
  - `resources/exported_data/functions/0x00522ff0.json`
  - `resources/exported_data/functions/0x00523030.json`
  - `resources/exported_data/functions/0x00523120.json`
  - `resources/exported_data/functions/0x005231f0.json`
  - `resources/exported_data/functions/0x00523330.json`
  - `resources/exported_data/functions/0x005233d0.json`
  - `resources/exported_data/functions/0x00523470.json`
  - `resources/exported_data/functions/0x005237d0.json`
  - `resources/exported_data/functions/0x00523a00.json`
  - `resources/exported_data/functions/0x00523a70.json`
  - `resources/exported_data/functions/0x00523b40.json`
  - `resources/exported_data/functions/0x00523ca0.json`
  - `resources/exported_data/functions/0x00523cf0.json`
  - `resources/exported_data/functions/0x00523df0.json`
  - `resources/exported_data/functions/0x00523f50.json`
  - `resources/exported_data/functions/0x005241a0.json`
  - `resources/exported_data/functions/0x005243c0.json`
  - `resources/exported_data/functions/0x00524400.json`
  - `resources/exported_data/functions/0x00524460.json`
  - `resources/exported_data/functions/0x00524470.json`
  - `resources/exported_data/functions/0x005244e0.json`
  - `resources/exported_data/functions/0x00524590.json`
- Tool limitation:
  - `list_mcp_resources` returned no exposed MCP resources in this session. No live IDA rename/type/comment mutation was attempted.

## Source Placement And Ownership
- Best route: [UID:0000LC] `MetaMan` source root, current proposed path `NexusTK/metadata/`, with `metadata/MetaMan.h` and `metadata/MetaMan.cpp`.
- Why this is not `DATFile`: `Meta.dat` is a loose local cache file opened directly by MetaMan through normal file APIs. `DATFile` owns the packed DAT archive API for resources such as `str.res`, palettes, EPF/EPD, audio, and image assets. [UID:0001RH] and [UID:0001QC] explicitly separate these layers.
- Why this is not UI-owned: ItemHelpPane, CollectionPane, and ObjectStatus/resource helpers read `g_pMetaMan` or call MetaMan lookup APIs after data is loaded/materialized. They are consumers, not storage or cache-sync owners.
- Why this is not Application/session-owned: Application constructs the singleton and session/network dispatches sync packets, but the table tree, pending/dirty state, cache load/save, and packet-specific handling are all inside MetaMan.
- Why this should not be no-owner/non-emitting: the target is a real source class with a valid file route and current score above the code-entry threshold. `auto-generated/NexusTK/metadata/MetaMan.cpp` already shows [UID:000088] as an emitted but empty marker.
- Historical alternative: the original source tree may have used a flat `MetaMan.cpp`; keep that caveat in `by-file/MetaMan.md`. For reconstruction, `NexusTK/metadata/` is still the clean route because the project already uses that source root in `PROPOSED_RECONSTRUCTION_PATH`.

## Class Layout Resolution
- The constructor is allocated from `Application::InitializeSubsystems` after `operator new(0x14)`, so the concrete MetaMan object is `0x14` / 20 bytes.
- The implicit vptr is at `+0x00`; source should model this with a virtual destructor, not with an explicit `m_vtable` source member.
- The first explicit source member begins at `+0x04` and behaves like an old MSVC `std::map<SimpleUString, MetaTable *>` object with a tree header/sentinel pointer plus element count.
- Recommended binary/source layout:

```text
0x00  implicit vptr from virtual destructor
+0x04  m_tables tree header / old MSVC std::map sentinel pointer
+0x08  m_tables size / table count
+0x0c  m_pendingTableRequests
+0x10  m_synchronized
+0x11  m_dirty
+0x12  padding/reserved
+0x13  padding/reserved
```

- Recommended source abstraction: `std::map<SimpleUString, MetaTable *> m_tables;` followed by `unsigned int m_pendingTableRequests; bool m_synchronized; bool m_dirty;`. The map explains the raw node helpers and the `0x2c` node size without exposing a hand-written tree implementation as normal source.
- Raw node layout for IDA/comments:

```text
MetaMan table-map node, size 0x2c / 44:
  +0x00 left/link0
  +0x04 parent/link1
  +0x08 right/link2
  +0x0c color
  +0x0d isNil/sentinel flag
  +0x0e padding
  +0x10 SimpleUString key, 24 bytes
  +0x28 MetaTable *table
```

- The node-destroy helper at `0x00524590` confirms this layout: it passes node `+0x10` to the small-string cleanup helper at `0x00524400`, then frees the exact `0x2c` node allocation.

## Method And Helper Inventory

| Range | Current name | Recommended source-facing name | Source policy |
| --- | --- | --- | --- |
| `0x005227d0-0x0052285c` | `sub_5227D0` / `MetaMan` | `MetaMan::MetaMan` | Source-authored constructor. |
| `0x00522860-0x005228e2` | `sub_522860` / `~MetaMan` | `MetaMan::~MetaMan` | Source-authored ordinary destructor; class declaration should generate the deleting wrapper. |
| `0x005228f0-0x00522940` | `sub_5228F0` | `MetaMan::LoadMetaDatAndRequestSync` | Source-authored startup sync method, returns send status. |
| `0x00522950-0x00522955` | `sub_522950` | `MetaMan_SaveMetaDatIfDirtyThunk` | 5-byte jump to `0x005237d0`; no separate source body. Document as thunk/alias wrapper if split. |
| `0x00522960-0x00522fe2` | `sub_522960` | `MetaMan::HandleMetaPacket` | Source-authored packet dispatcher/handler. |
| `0x00522ff0-0x00523029` | Ghidra-only `FUN_00522ff0` | `MetaMan::GetTableRowCount` or `MetaMan_GetMaterializedRowCount` | Real helper body, no current direct callers; should get a child page if source is emitted. |
| `0x00523030-0x00523114` | IDA-unmodeled body | `MetaMan::GetValueCount` / `MetaMan::GetRowValueCount` | Alias-aware value-count counterpart to `FindEntry`; should get a child page. |
| `0x00523120-0x005231e5` | `sub_523120` | `MetaMan::FindEntry` | Source-authored public lookup API, returns a `SimpleUString` pointer/reference or shared empty. |
| `0x005231f0-0x00523325` | `sub_5231F0` | `MetaMan::LoadStatValues` | Source-authored multi-value lookup API for item/stat text. |
| `0x00523330-0x005233c3` | `sub_523330` | `MetaMan::FindTableByName` | Source-authored map lookup. |
| `0x005233d0-0x00523465` | `sub_5233D0` | `MetaMan::ClearTables` | Source-authored table clear helper; `DestroyMetaManBase` is decompiler-shaped. |
| `0x00523470-0x005237bf` | `sub_523470` | `MetaMan::LoadMetaDat` | Source-authored loose-cache loader. |
| `0x005237d0-0x005239fa` | `sub_5237D0` | `MetaMan::SaveMetaDatIfDirty` | Source-authored private dirty-cache writer. Reject generated `FinishMetaSync` as too broad. |
| `0x00523a00-0x00523a65` | `sub_523A00` | `MetaMan_GetDirectRowValueCount` | Static/file-local direct lookup helper; source body belongs in helper child, not class declaration. |
| `0x00523a70-0x00523b39` | `sub_523A70` | `MetaMan_FindDirectRowValue` | Static/file-local direct indexed value helper. |
| `0x00523b40-0x00523c99` | `sub_523B40` | `MetaMan_CopyDirectRowValues` | Static/file-local direct multi-value copy helper. |
| `0x00523ca0-0x00523cea` | `sub_523CA0` | `SimpleUStringEquals` / `MetaMan_StringEquals` | Generic small-string equality helper used to compare lookup results with `g_emptySimpleUString`. |
| `0x00523cf0-0x0052445f` | `sub_523CF0` etc. | `MetaManTableTree_*` helper family | Generated/instantiated old-STL map helper glue; model with map declaration, not standalone source methods unless child docs require no-code proof. |
| `0x00524460-0x0052446a` | `sub_524460` | `ClearMetaManSingleton` | Tiny source/lifecycle helper that clears `g_pMetaMan`. |
| `0x00524470-0x005244db` | `sub_524470` | `MetaManTableMap_FindOrInsertSlot` | Map find-or-insert value-slot helper used by `HandleMetaPacket`. |
| `0x005244e0-0x00524580` | `sub_5244E0` | `MetaManScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper; no formal C++ body. |
| `0x00524590-0x005245b1` | `sub_524590` | `MetaManTableNodeDestroyHelper` | Map-node cleanup helper; no human-authored source method beyond map/container use. |

## Constructor, Destructor, And Singleton Behavior
- `MetaMan::MetaMan` writes `g_pMetaMan = this`, sets the class vtable at `0x0061fad8`, initializes the map/tree header through `0x00453820`, sets table count and pending count to zero, and clears the synchronized/dirty word at `+0x10`.
- The odd constructor guard `this == -4` is a decompiler artifact from taking `this + 4`; source should not reproduce it.
- `MetaMan::~MetaMan` restores the vtable, calls the table clear helper, resets/frees map sentinel storage, zeros the map count, and clears `g_pMetaMan`.
- `ClearMetaManSingleton` at `0x00524460` is a tiny helper used by static cleanup/teardown metadata and should be documented as a singleton clear helper.
- `MetaManScalarDeletingDestructor` at `0x005244e0` is compiler-generated wrapper glue. Source should expose `virtual ~MetaMan();`; the scalar deleting wrapper remains blank/no-code.
- `g_pMetaMan` static bytes are `ff ff ff ff` in the documented memory page. Recommended global source spelling remains `MetaMan *g_pMetaMan = (MetaMan *)-1;` unless a later source-symbol pass proves a named sentinel or zero initializer with loader patching.

## Packet Synchronization Semantics
- Packet opcode: `123` / `0x7b`.
- `LoadMetaDatAndRequestSync` calls `LoadMetaDat`, writes opcode `123`, writes subtype `1`, writes a zero third byte, and sends length `2` through the packet sender. This is the client sync-list request.
- `HandleMetaPacket` subtype `1` handles the server table/checksum list:
  - reads the server table count from packet offset `+2`;
  - walks local `m_tables`;
  - for each local table, scans server records of `nameLength`, narrow table name bytes, and 4-byte checksum;
  - removes local tables absent from the server list and marks `m_dirty`;
  - for each server record, finds the local table and calls `MetaTable::DecompressAndValidateData` / checksum validation;
  - sends subtype `0` requests for missing or invalid tables;
  - increments `m_pendingTableRequests` for each requested table;
  - when no requests remain, sets `m_synchronized = true` and calls `SaveMetaDatIfDirty`.
- `HandleMetaPacket` subtype `0` handles a single table payload response:
  - reads table name length at `packet+2`, table name bytes at `packet+3`;
  - reads a 4-byte checksum after the name;
  - finds the existing `MetaTable` or allocates a new `0x24` byte table and inserts it in `m_tables`;
  - resets stale table data when reusing an existing table;
  - reads a 2-byte payload length, copies payload bytes into a new compressed-payload buffer, stores it at `MetaTable +0x10/+0x14`, validates it, marks `m_dirty`, decrements `m_pendingTableRequests`, and saves the cache when the pending count reaches zero.
- Other nonzero subtype values effectively fall through to success/no-op after stack cleanup; current docs should not invent behavior beyond that.
- Range/error behavior:
  - oversized table-name or payload conversions call `__report_rangecheckfailure`;
  - file-open failure in `LoadMetaDat`/`SaveMetaDatIfDirty` returns/tolerates missing cache rather than making startup fatal;
  - missing/stale metadata is resolved by subtype `0` requests rather than by trusting the local cache.

## Loose Meta.dat Cache Behavior
- `LoadMetaDat` is the source-owned loader for loose `Meta.dat`. It is called before sync request, clears current table state, opens the loose file for read, reads 4-byte table count and 4-byte header byte count, allocates/reads the header block, then creates `MetaTable` objects and reads each compressed payload block.
- `SaveMetaDatIfDirty` is the source-owned dirty-cache writer. It gates on `m_dirty` at `+0x11`, opens `Meta.dat` for write/create, serializes table count, header byte count, header records, and compressed payload blocks, frees each compressed payload buffer after writing, zeroes `MetaTable +0x10/+0x14`, closes the file, and clears `m_dirty`.
- Header-record wording should be reconciled rather than overclaimed:
  - the resource page records `uint16` UTF-16 name length, UTF-16 table name, and 8 secondary bytes;
  - the writer uses the byte packet helper for the length but advances by 2 before copying UTF-16 name bytes, so the source-facing description should say a 16-bit serialized name-length slot whose current values fit in one byte, followed by UTF-16 name bytes;
  - the first four secondary bytes are a big-endian compressed payload size in the audited sample; the next four bytes are zero/reserved in that sample;
  - exact source field names for the secondary 8 bytes remain open.
- `Meta.dat` payload blocks are server/resource-derived compressed metadata data. They should not be emitted as C++ static table bytes.

## Lookup Behavior And Alias Handling
- `g_metaAliasTableName` is a static `SimpleUString` key object owned by MetaMan source. It is initialized empty in the current image, so the final original literal/table-name spelling is not proven. The role name remains the best documentation/source label.
- `FindEntry` and `LoadStatValues` both use alias-first logic:
  - call direct indexed lookup with `g_metaAliasTableName` and the caller's table name as the row key;
  - compare the alias result to `g_emptySimpleUString`;
  - if the first alias lookup is empty, fall back to the caller-provided table name;
  - if later alias lookup is empty, stop/return no result;
  - if an alias table name is returned, perform the row lookup in that alias table.
- `0x00523030` is the same alias-aware pattern for value counts. Best source-facing name is `MetaMan::GetValueCount` or `MetaMan::GetRowValueCount`; `GetValueCount` is shorter and matches the logical public API role. It has no currently observed direct callers, so document it as retained/unused or unreferenced in this binary until a caller is found.
- `0x00522ff0` is a materialized row-count helper for a table name. It calls `FindTableByName`, materializes if needed, and returns the `MetaTable +0x20` row count or zero. It has no direct callers in exported data; recommend a child page before any source emission.
- Direct lookup helpers:
  - `0x00523a00` returns row value count after table lookup/materialization/row find;
  - `0x00523a70` returns a pointer to the indexed `SimpleUString` value or `g_emptySimpleUString`;
  - `0x00523b40` allocates a pointer array and `0x50` byte buffers, copies up to the requested value count with `wcscpy_s(dest, 0x28, src)`, and returns a status/value pointer used by `LoadStatValues`.

## Tree / List / Node Helper Policy
- Helpers from `0x00523cf0` through `0x00524470` are best interpreted as old MSVC `std::map`/tree support emitted from source-level `m_tables`, not as hand-authored MetaMan methods.
- Source declarations should not expose raw tree-node helpers as public APIs.
- Documentation should still name them for audit and IDA:
  - `MetaManTableNode_ConstructKey` at `0x00523cf0`
  - `MetaManTableTree_AttachAndRebalance` at `0x00523df0`
  - `MetaManTableTree_InsertWithHint` at `0x00523f50`
  - `MetaManTableTree_FindOrInsertNode` at `0x005241a0`
  - `MetaManTableTree_LowerBound` at `0x005243c0`
  - `MetaManTableNode_DestroyKey` / `SimpleUString_Reset` at `0x00524400`
  - `MetaManTableMap_FindOrInsertSlot` at `0x00524470`
- `MetaManNodeDestroyHelper` at `0x00524590` has exact no-code proof as a generated/container cleanup helper: one basic block, callers only in tree insert/rollback helpers, calls node key cleanup on `node+0x10`, then frees `0x2c` bytes. It does not need a formal source body beyond the map declaration and normal cleanup paths.

## Support-Document Findings
- `by-file/MetaMan.md`:
  - The current file route is correct. Update stale generated-source references from `source-3/simroot_v2/class_MetaMan.cpp` and `class_MetaTable.cpp` to the current generated evidence path `source-3/simroot_v2/metadata/MetaMan.cpp`.
  - Add `0x00522ff0`, `0x00523030`, `0x00523ca0`, and `0x00523cf0-0x00524470` to the proposed contents/source-quality notes as MetaMan-local helpers that still need exact child coverage or no-code helper policy.
  - Replace "helper names provisional until ownership dry run" with the best names in this report and retain a confidence caveat for exact original spelling.
- `by-memory/0x005227d0-0x00524581.MetaMan.md`:
  - Update the covered-ranges table to include currently omitted helper bodies and padding/split notes: `0x00522950`, `0x00522ff0`, `0x00523ca0`, `0x00523cf0`, `0x00523df0`, `0x00523f50`, `0x005241a0`, `0x005243c0`, `0x00524400`, and `0x00524470`.
  - Keep broad aggregate formal C++ blank. Reason: it covers many source methods, helper clusters, compiler/STL helper glue, and child-worthy bodies; the class declaration belongs on [UID:000088], while method/helper bodies should be emitted only from exact method/child pages after body-level source passes.
  - Raise aggregate completion if edited, because the prior `85/88` page still says final field/packet/helper names are blockers that are now mostly resolved.
- `by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md`:
  - Keep owner/emitter [UID:0000LC].
  - Add the source-facing names `MetaMan_GetDirectRowValueCount`, `MetaMan_FindDirectRowValue`, and `MetaMan_CopyDirectRowValues`.
  - Clarify that these are source/file-local direct helpers under the alias-aware public methods, not CollectionPane-owned code.
  - Formal C++ may remain blank for this callback because the target is the class declaration and the helper cluster should not absorb `0x00523030` or `0x00523ca0`. A future exact helper-body pass can emit the static helper functions.
- `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`:
  - Keep direct class owner [UID:000088].
  - Add explicit no-formal-C++ policy: generated/container cleanup helper emitted from the `m_tables` map/tree implementation; represented in source by `std::map<SimpleUString, MetaTable *>` and normal map cleanup/insert rollback.
- `by-class/MetaTable.md`:
  - No owner change. Add a short dependency note that MetaMan stores compressed payload buffers at `MetaTable +0x10/+0x14`, loaded flag at `+0x18`, row tree header at `+0x1c`, and row count at `+0x20`.
  - Keep MetaTable source body work separate from this class report.
- `by-global/g_pMetaMan.md`:
  - Replace stale "below 95/95" blank-C++ rationale with current gate wording.
  - Recommended first-draft global C++ after supervisor acceptance:

```cpp
MetaMan *g_pMetaMan = (MetaMan *)-1;
```

  - Keep caveat that exact sentinel macro/name is not proven; the static bytes prove the `-1` initializer.
- `by-global/g_metaAliasTableName.md`:
  - Replace stale "literal/name not final" blocker with a best-supported source role.
  - Recommended first-draft global C++ after supervisor acceptance if the supervisor wants support global C++ in the same callback:

```cpp
SimpleUString g_metaAliasTableName;
```

  - Caveat: current initializer is empty; no source literal like `"Alias"` is proven.
- `by-resource/meta-dat-metadata-cache.md`:
  - Add reconciliation note: writer advances by two bytes after the length slot while using the byte helper for current values, so describe the name length as a 16-bit serialized slot whose current high byte is zero/padding unless a later raw parse proves otherwise.
- `by-meta/client_dat_specifications.md`:
  - Keep DAT/Meta.dat separation. No major change needed beyond linking refreshed MetaMan class/source-quality detail.

## Score Recommendation
- Target [UID:000088] should rise from `86/85` to `89/88`.
- Why completion rises:
  - object size `0x14` and private field offsets are now resolved;
  - map/tree node layout is tied to `std::map<SimpleUString, MetaTable *>`;
  - helper names around `0x005237d0-0x00523c99` have best-supported source-facing names;
  - unmodeled helpers at `0x00522ff0` and `0x00523030` are classified;
  - packet subtype behavior, pending/dirty/synchronized fields, and loose-cache save behavior are documented;
  - compiler-generated wrapper/no-code policy is explicit;
  - first-draft class declaration is ready.
- Why confidence stays below `90+`:
  - no live IDA MCP resources were exposed in this session;
  - exact original private member spellings remain inferred role names;
  - exact original `g_metaAliasTableName` symbol/literal spelling is not proven because the object is initialized empty;
  - outer `Meta.dat` secondary-field names and malformed-cache error policy remain only partly reconciled;
  - method/helper body C++ still needs exact child pages for broad aggregate emission.
- Do not raise to `95+`: this is not a final-audit pass for every method body, helper, table payload field, and support page.

## First-Draft C++ For Target Class Page
Recommended for [UID:000088] `by-class/MetaMan.md` only. This is a class/source-shape declaration, not full method-body reconstruction.

```cpp
#include <map>

class SimpleUString;
class MetaTable;

class MetaMan
{
public:
    MetaMan();
    virtual ~MetaMan();

    int LoadMetaDatAndRequestSync();
    bool HandleMetaPacket(const unsigned char *packet);

    unsigned int GetValueCount(const SimpleUString *tableName,
                               const SimpleUString *rowKey);
    const SimpleUString *FindEntry(const SimpleUString *tableName,
                                   const SimpleUString *rowKey,
                                   unsigned int valueIndex);
    bool LoadStatValues(const SimpleUString *tableName,
                        const SimpleUString *rowKey,
                        wchar_t ***outValues,
                        int valueCount);
    MetaTable *FindTableByName(const SimpleUString *tableName);

private:
    typedef std::map<SimpleUString, MetaTable *> TableMap;

    void ClearTables();
    void LoadMetaDat();
    void SaveMetaDatIfDirty();

    TableMap m_tables;
    unsigned int m_pendingTableRequests;
    bool m_synchronized;
    bool m_dirty;
};
```

Notes for the implementing callback:
- The declaration intentionally uses pointers for `SimpleUString` parameters because current function signatures pass string-object addresses and exact const/reference source style is not proven.
- `LoadMetaDatAndRequestSync` returns the packet-send result in the binary; do not make it `void` unless a later source-style pass proves the return is discarded by convention.
- `HandleMetaPacket` returns success as a byte/char. `bool` is the best source-facing type.
- Do not add explicit `m_vtable` or raw tree node members to this class declaration.
- Do not add scalar deleting destructor C++.
- Do not paste `HandleMetaPacket`, lookup helper, or save/load bodies into the class page.

## Open Questions And Resolutions
- Exact original source folder:
  - Best answer: use `NexusTK/metadata/` for reconstruction.
  - Evidence checked: proposed source tree, by-file path, generated output path, DAT distinction docs.
  - Remaining uncertainty: original project may have had flat `MetaMan.cpp`; this does not block current route.
- Exact private field spellings:
  - Best answer: `m_tables`, `m_pendingTableRequests`, `m_synchronized`, `m_dirty`.
  - Evidence checked: constructor zeroing, packet handler increment/decrement, save dirty gate, sync completion writes.
  - Remaining uncertainty: original source may have used shorter Hungarian names or `m_bDirty`/`m_bSynchronized`; role names are source-quality enough but not symbol-proven.
- `0x005237d0` name:
  - Best answer: `SaveMetaDatIfDirty`.
  - Rejected alternative: generated `FinishMetaSync`, because the function is gated on dirty state and writes the loose cache; it is called when sync completes but its own role is cache save.
- `0x00523030` name/source role:
  - Best answer: `MetaMan::GetValueCount` / `GetRowValueCount`.
  - Evidence checked: alias-table walk, direct fallback to `0x00523a00`, row value-count semantics.
  - Remaining uncertainty: no direct callers in exported data, so it may be retained unused source API or an unreferenced helper.
- `0x00522ff0` role:
  - Best answer: `MetaMan::GetTableRowCount` or `MetaMan_GetMaterializedRowCount`.
  - Evidence checked: calls table lookup/materialization and returns `MetaTable +0x20`.
  - Remaining uncertainty: no direct callers in exported data; child page needed before C++ body.
- Tree helpers:
  - Best answer: generated/instantiated map support.
  - Evidence checked: old-STL tree patterns, node size/layout, insert/lower-bound/rotate/rebalance behavior, cleanup helper caller set.
  - No blocker: represent source as `std::map` and document generated helper no-code policy.
- `g_metaAliasTableName` exact source literal:
  - Best answer: role name `g_metaAliasTableName`, source initializer empty/default `SimpleUString`.
  - Evidence checked: memory object bytes, static constructor with empty wide initializer, xrefs from alias-first methods.
  - Remaining uncertainty: original identifier/literal spelling is not proven. This should cap confidence but not block target class declaration.
- `Meta.dat` header secondary fields:
  - Best answer: table count, header byte count, length/name, big-endian compressed payload size, four reserved/zero bytes in audited sample.
  - Evidence checked: resource page, loader/writer decompilation, writer's 8-byte secondary advance.
  - Remaining uncertainty: exact source field names and malformed-cache policy; do not overname checksum/reserved fields.

## IDA Rename / Type / Comment Recommendations
- High-confidence function renames:
  - `sub_5227D0` -> `MetaMan_ctor` / `MetaMan::MetaMan`
  - `sub_522860` -> `MetaMan_dtor` / `MetaMan::~MetaMan`
  - `sub_5228F0` -> `MetaMan_LoadMetaDatAndRequestSync`
  - `sub_522960` -> `MetaMan_HandleMetaPacket`
  - `sub_523120` -> `MetaMan_FindEntry`
  - `sub_5231F0` -> `MetaMan_LoadStatValues`
  - `sub_523330` -> `MetaMan_FindTableByName`
  - `sub_5233D0` -> `MetaMan_ClearTables`
  - `sub_523470` -> `MetaMan_LoadMetaDat`
  - `sub_5237D0` -> `MetaMan_SaveMetaDatIfDirty`
  - `sub_524460` -> `ClearMetaManSingleton`
  - `sub_5244E0` -> `MetaMan_ScalarDeletingDestructor`
  - `sub_524590` -> `MetaManTableNodeDestroyHelper`
- Medium/high-confidence helper renames:
  - `sub_522950` -> `MetaMan_SaveMetaDatIfDirtyThunk`
  - `FUN_00522ff0` -> `MetaMan_GetTableRowCount`
  - `sub_523030` / IDA-unmodeled `0x00523030` -> `MetaMan_GetValueCount`
  - `sub_523A00` -> `MetaMan_GetDirectRowValueCount`
  - `sub_523A70` -> `MetaMan_FindDirectRowValue`
  - `sub_523B40` -> `MetaMan_CopyDirectRowValues`
  - `sub_523CA0` -> `SimpleUStringEquals`
  - `sub_523CF0` -> `MetaManTableNode_ConstructKey`
  - `sub_523DF0` -> `MetaManTableTree_AttachAndRebalance`
  - `sub_523F50` -> `MetaManTableTree_InsertWithHint`
  - `sub_5241A0` -> `MetaManTableTree_FindOrInsertNode`
  - `sub_5243C0` -> `MetaManTableTree_LowerBound`
  - `sub_524400` -> `MetaManTableNode_DestroyKey`
  - `sub_524470` -> `MetaManTableMap_FindOrInsertSlot`
- Data/type recommendations:
  - Apply/comment `g_pMetaMan` at `0x0069b410` as `MetaMan *`.
  - Apply/comment `g_metaAliasTableName` at `0x0066de18` as a 24-byte `SimpleUString`.
  - Model `MetaMan` as 20 bytes with implicit vptr plus map/pending/sync/dirty fields.
  - Add a local `MetaManTableNode` comment/type for the raw 44-byte node only if IDA tree helper analysis needs it; do not expose it as a source class.
  - Comment `0x00522950` as a tail-jump thunk to `MetaMan_SaveMetaDatIfDirty`.
  - Comment `0x005244e0` as compiler-generated scalar deleting destructor wrapper, no source body.

## Exact Recommended Target Edits
For `source-3/project-documentation/by-class/MetaMan.md`:
- Change metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Keep:

```text
*** CANONICAL_OWNER:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Replace stale `Current recovered file: source-3/simroot_v2/class_MetaMan.cpp` with current generated/source evidence:

```text
- Current generated evidence: `source-3/simroot_v2/metadata/MetaMan.cpp`; current autogen route: `source-3/project-documentation/auto-generated/NexusTK/metadata/MetaMan.cpp`.
```

- Replace `Observed State` with the resolved field layout from this report.
- Replace "exact field layout still needs a struct pass" with the 0x14 object-size and field-role evidence.
- Expand `Method Notes` with the resolved helper names and no-code policy for `0x00522950`, `0x00522ff0`, `0x00523030`, `0x00523ca0`, and tree helpers through `0x00524470`.
- Expand `Packet Synchronization` with subtype request/response details and pending/dirty/synchronized field use.
- Expand `Lookup Behavior` with alias-first value count, `FindEntry`, and `LoadStatValues` behavior.
- Add `Source Declaration Readiness` or equivalent section with the first-draft class C++ block above.
- Add `Generated Wrapper / Helper Policy` section:
  - scalar deleting destructor no formal C++;
  - `0x00522950` thunk no formal C++;
  - map/tree helpers represented by `m_tables` map declaration;
  - method/helper bodies should live in exact by-memory pages, not in the class declaration.
- Add a change-log entry:

```text
- 2026-06-19 Agent-B009 source-quality pass:
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`.
  - Summary/evidence: resolved the `0x14` object size, private field layout at `+0x04/+0x08/+0x0c/+0x10/+0x11`, singleton publish/clear behavior, opcode `123` subtype `1`/`0` sync semantics, dirty-cache writer behavior, alias-aware lookup/value-count routes, direct helper names, map/tree helper no-code policy, and current first-draft class declaration readiness. Confidence remains below final-audit level because live IDA MCP was not exposed in this session, exact original private member spelling and alias key literal remain inferred, and broad method/helper bodies still need exact child-page source passes.
```

## Implementation Instructions For Supervisor Callback
1. Lease all target/support docs before editing. Do not edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, or generated coverage/source files.
2. Update [UID:000088] `by-class/MetaMan.md` as described above, including `89/88`, resolved layout, helper names, packet/cache behavior, generated wrapper policy, and the first-draft class declaration block.
3. Update [UID:0000LC] `by-file/MetaMan.md`:
   - Replace stale generated-source paths with `source-3/simroot_v2/metadata/MetaMan.cpp`.
   - Add omitted MetaMan helper inventory: `0x00522ff0`, `0x00523030`, `0x00523ca0`, `0x00523cf0-0x00524470`, and `0x00522950` thunk.
   - Add source route rationale: `metadata/MetaMan.cpp` owns loose `Meta.dat`, MetaMan, MetaTable, globals, lookup helpers, and map/helper glue; UI and DAT archive docs are consumers/dependencies.
   - Recommended score after edit: `COMPLETION:89`, `CONFIDENCE:88` if the support doc is expanded at this detail.
4. Update [UID:0001C8] `by-memory/0x005227d0-0x00524581.MetaMan.md`:
   - Add omitted ranges and names from this report.
   - Replace stale "C++ remains blank pending field/packet/helper names" with target-specific aggregate no-code policy: broad mixed class/function island; exact method/helper children should emit bodies; class declaration is in [UID:000088].
   - Recommended score after edit: `COMPLETION:88`, `CONFIDENCE:88`.
5. Update [UID:0001C9] `by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md`:
   - Add final best helper names and alias/direct relationship.
   - Keep formal C++ blank in this callback unless the supervisor explicitly asks for helper-body implementation too.
   - Recommended score can remain `87/90` or rise slightly to `88/90` if names/no-code policy are added.
6. Update [UID:00023A] `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`:
   - Add exact no-formal-C++ proof through map/tree generated cleanup.
   - Keep owner/emitter as [UID:000088].
   - Score can remain `87/90`; no score change required.
7. Update [UID:0000RL] `by-global/g_pMetaMan.md` if supervisor wants support globals in the same callback:
   - Replace stale 95/95 gate wording.
   - Add first-draft C++ `MetaMan *g_pMetaMan = (MetaMan *)-1;`.
   - Keep current `88/88` unless more direct evidence is added.
8. Update [UID:0000Q2] `by-global/g_metaAliasTableName.md` if supervisor wants support globals in the same callback:
   - Replace stale gate wording.
   - Add best first-draft C++ `SimpleUString g_metaAliasTableName;` with caveat that exact original literal/symbol spelling is not proven.
   - Keep current `88/89`.
9. Update [UID:0001RH] `by-resource/meta-dat-metadata-cache.md` only if the callback scope includes resource support:
   - Add length-slot reconciliation note from this report.
   - Do not hard-code payload bytes or claim a new raw-resource parse from this session.
10. Validator commands from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000088-MetaMan-class-source-quality-removed.md](000088-MetaMan-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only the validators for files actually edited in the callback.

## Exact Pending Coverage Text
Do not edit coverage files directly. If the supervisor applies coverage text manually or regenerates reports after accepted edits, use these replacement rows as applicable.

`by-class/-coverage-report.md` replacement row:

```text
- [UID:000088][MetaMan](by-class/MetaMan.md) : reconstructable : 89% : strong : Source-quality refresh resolves the `0x14` MetaMan object size, private fields at `+0x04/+0x08/+0x0c/+0x10/+0x11`, singleton publish/clear behavior, opcode `123` subtype `1`/`0` metadata sync, loose `Meta.dat` dirty-cache save/load behavior, alias-aware lookup/value-count routes, map/tree node layout and no-code wrapper policy; first-draft class declaration is ready while method/helper bodies remain on exact by-memory children.
```

`by-memory/-coverage-report.md` replacement rows if support docs are updated:

```text
    - [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md) 0x005227d0-0x00524581 | aggregate | MetaMan class/function island : reconstructable : 88% : strong : MetaMan lifecycle, sync, lookup, persistence, teardown, singleton access, object field layout, opcode `123` packet semantics, dirty/pending sync state, omitted helper ranges, map/tree helper policy, and child/split requirements documented; formal C++ remains blank because this broad aggregate mixes class methods, static lookup helpers, and generated map glue.
        - [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) 0x00523a00-0x00523c99 | helper-cluster | MetaMan direct lookup helpers : reconstructable : 88% : strong : Direct metadata row value-count, indexed value, and multi-value copy helpers with exact boundaries, padding, MetaTable materialization/row-find callees, alias-aware caller relationship, and source-facing helper names documented under MetaMan file ownership.
    - [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) 0x00524590-0x005245b1 | helper | MetaMan table-node destroy helper : reconstructable : 87% : strong : Exact one-block node cleanup helper for MetaMan table-map insert/rollback paths; destroys the `SimpleUString` key at node `+0x10`, frees the `0x2c` / 44-byte node, has only MetaMan tree-helper callers, and is represented in source by the `m_tables` map rather than a standalone formal C++ body.
```

If support global C++ is added, generated/global coverage should be regenerated rather than hand-edited. The current primary stale user-visible row is the by-class row above.

## Validation Needs
- Report-only validation completed: report file creation should be checked with `Test-Path`.
- Implementation callback validation must run scoped validator commands for every edited by-* file as listed above.
- After implementation, inspect `auto-generated/NexusTK/metadata/MetaMan.cpp` to confirm [UID:000088] no longer appears only as an empty marker and that no broad method/helper body was accidentally injected through the class page.
- If by-global support C++ is added, inspect the same autogen file to confirm `g_pMetaMan` and/or `g_metaAliasTableName` declarations appear once and do not conflict with class declaration ordering.

## Implementation Readiness
- Ready for supervisor review.
- Ready for later same-agent implementation if accepted.
- Target [UID:000088] is ready for first-draft class declaration C++ under the current gate.
- Broad method-body emission is not ready on [UID:0001C8] because exact body children/splits still need separate source passes.
- Scalar deleting destructor, tail thunk, and map/tree helper glue have target-specific no-code proof and should not be emitted as hand-written methods.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/000088-MetaMan-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"000088"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000088-MetaMan-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/000088-MetaMan-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000088"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
