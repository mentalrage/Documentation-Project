*** UID:000088 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MetaMan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_METADATA_METAMAN_H
#define NEXUSTK_METADATA_METAMAN_H

#include "../util/Singleton.h"
#include "../util/StringUtil.h"

#include <map>

class MetaTable;

class MetaMan : public Singleton<MetaMan>
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

extern MetaMan *g_pMetaMan;

typedef char MetaManSizeMustBe0x14[
    sizeof(MetaMan) == 0x14 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MetaMan

## ObjectStatusBlob FindEntry consumer

- Full parser UID0004LL is a direct `MetaMan::FindEntry` consumer at callee `0x00523120`. For nonzero riding appearance id, it formats UTF-16 `%d`, uses table `RidableAnimals`, and requests columns 1, 2, and 3.
- The three returned strings are converted with `_wtol` into ObjectStatusBlob `+0x2c` riding definition index, `+0x2e` packed palette/render flags, and signed `+0x30` riding Y offset. `+0x2a` is the riding appearance key and is forced to 1 when legacy assets are active.
- This exact chain rejects the historical title-metadata interpretation. ObjectStatusBlob is a MetaMan client, not MetaMan-owned parser source. No MetaMan declaration/API, score, owner/emitter, vtable, or formal block changes.


## Status

- Likely source file: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Address range: [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- Singleton global: [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) at `0x0069b410`
- Generated routes are `source-3/project-documentation/auto-generated/NexusTK/metadata/MetaMan.cpp` and companion `MetaMan.h`; dated generated receipts are observations, while the latest waited physical readback controls callback truth.
- Confidence: very strong for class role, direct Singleton base, EBO layout, object size, field roles, method ownership, singleton lifetime, metadata packet flow, loose `Meta.dat` cache routing, alias-aware lookup behavior, and table-tree cleanup ownership; capped below final by exact private spellings and outer cache-field names.
- Parent gate: this class now clears the strict `85/85` gate for direct class-owned memory children such as [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md).

## Class Purpose

`MetaMan` is the process-wide manager for client metadata tables and directly derives from `Singleton<MetaMan>`. It loads the local loose `Meta.dat` cache, synchronizes table payloads with the server through metadata packets, owns a name-keyed set of [UID:000089][MetaTable](by-class/MetaTable.md) objects, and exposes lookup helpers used by item help, collection panes, image/resource helpers, and session/network code.

This is metadata ownership, not raw DAT archive ownership. `Meta.dat` is opened as a loose file and stores compressed metadata table payloads; it should stay with `metadata/MetaMan.cpp`, while the DAT archive reader remains under [UID:0000IN][DATFile](by-file/DATFile.md).

## Observed State

```text
MetaMan
  +0x00  implicit vptr from virtual destructor
  +0x04  EBO-overlapped Singleton<MetaMan> base and m_tables tree header
  +0x08  m_tables size / table count
  +0x0c  m_pendingTableRequests
  +0x10  m_synchronized
  +0x11  m_dirty
  +0x12  padding/reserved
  +0x13  padding/reserved
```

The concrete object is `0x14` / 20 bytes; application startup allocates it with `operator new(0x14)`. RTTI lists MetaMan plus direct `Singleton<MetaMan>` with PMD `mdisp=4`, `pdisp=-1`, `vdisp=0`. EBO overlaps the empty base with the first explicit map state at `+0x04`, so adding the source base does not change size or fields. Source models the implicit vptr through `virtual ~MetaMan()` and `m_tables` as `std::map<SimpleUString, MetaTable *>`; raw tree nodes are old MSVC implementation detail. Constructor publication and destructor clear of [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) are direct Singleton base lowering. Table-tree rollback/teardown helpers call UID00023A to clean initialized nodes.

## RTTI And Vtable Source Cause

- [UID:0004SS][0x0061fad0-0x0061fadc.MetaManVtableData](by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md) contains one alignment dword, the MetaMan primary COL pointer, and the sole scalar-deleting-destructor slot.
- MetaMan RTTI has exactly two hierarchy entries: MetaMan and `Singleton<MetaMan>`.
- The table at `0x0061fad8` is installed/restored by MetaMan constructor, ordinary destructor, and scalar deleting wrapper.
- Compiler scalar wrapper `0x005244e0-0x00524581` performs ordinary/table cleanup, implicit Singleton clear, delete flags, optional storage free, and return-this ABI.
- No handwritten vtable array, vptr assignment, Singleton publication/clear, or scalar wrapper belongs in source.

Raw node layout for IDA/comment purposes only:

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

The node-destroy helper at `0x00524590` confirms this layout by passing node `+0x10` to the small-string cleanup helper at `0x00524400`, then freeing the exact `0x2c` node allocation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MetaMan::MetaMan` | `0x005227d0-0x0052285c` | Constructs Singleton and metadata-manager state and initializes table storage; publication is implicit base lowering. |
| `MetaMan::~MetaMan` | `0x00522860-0x005228e2` | Clears manager state, destroys table nodes, releases storage, and implicitly clears the Singleton base. |
| `LoadMetaDatAndRequestSync` | `0x005228f0-0x00522940` | Loads local `Meta.dat`, then sends opcode `123`, subtype `1` to request metadata synchronization. |
| `MetaMan_SaveMetaDatIfDirtyThunk` | `0x00522950-0x00522955` | Five-byte jump to `0x005237d0`; document as an alias/thunk with no separate source body. |
| `HandleMetaPacket` | `0x00522960-0x00522fe2` | Handles metadata sync/checksum lists and table payload responses from the server. |
| `GetTableRowCount` / `GetMaterializedRowCount` | `0x00522ff0-0x00523029` | Real table row-count helper with no observed direct callers; should get an exact child page before any source body emission. |
| `GetValueCount` / `GetRowValueCount` | `0x00523030-0x00523114` | Alias-aware value-count counterpart to `FindEntry`; retained/unreferenced in this binary until a caller is proven. |
| `FindEntry` | `0x00523120-0x005231e5` | Public lookup API: applies the alias table first, then returns an indexed `SimpleUString` value or the shared empty string. |
| `LoadStatValues` | `0x005231f0-0x00523325` | Loads multiple row values into caller-owned wide-string row buffers, used by item help/stat presentation. |
| `FindTableByName` | `0x00523330-0x005233c3` | Looks up a `MetaTable*` by wide table name in the manager tree. |
| `ClearTables` | `0x005233d0-0x00523465` | Clears all owned table state without freeing the manager object; `DestroyMetaManBase` is a decompiler-shaped name. |
| `LoadMetaDat` | `0x00523470-0x005237bf` | Opens loose `Meta.dat`, reads table records, creates `MetaTable` objects, and inserts them into the manager tree. |
| `SaveMetaDatIfDirty` | `0x005237d0-0x005239fa` | Writes dirty local `Meta.dat` cache; reject generated `FinishMetaSync` as too broad because the function is gated on dirty state and serializes the cache. |
| `MetaMan_GetDirectRowValueCount` | `0x00523a00-0x00523a65` | File-local direct row value-count helper. |
| `MetaMan_FindDirectRowValue` | `0x00523a70-0x00523b39` | File-local direct indexed value helper. |
| `MetaMan_CopyDirectRowValues` | `0x00523b40-0x00523c99` | File-local direct multi-value copy helper. |
| `SimpleUStringEquals` / `MetaMan_StringEquals` | `0x00523ca0-0x00523cea` | Generic small-string equality helper used to compare lookup results with `g_emptySimpleUString`. |
| `MetaManTableTree_*` helper family | `0x00523cf0-0x0052445f` | Old MSVC map/tree helper glue; model as `m_tables`, not as hand-authored MetaMan methods. |
| `ClearMetaManSingleton` | `0x00524460-0x0052446a` | Small global clear helper referenced near teardown metadata. |
| `MetaManTableMap_FindOrInsertSlot` | `0x00524470-0x005244db` | Map find-or-insert value-slot helper used by `HandleMetaPacket`. |
| `MetaManScalarDeletingDestructor` | `0x005244e0-0x00524580` | MSVC scalar deleting destructor wrapper; source exposes `virtual ~MetaMan()` and no handwritten wrapper body. |
| [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) | `0x00524590-0x005245b1` | Metadata table-tree node payload cleanup and 44-byte node free helper called from `MetaMan` insert/rollback cleanup paths. |

## Packet Synchronization

Metadata packets use opcode `123` with a subtype byte:

- `LoadMetaDatAndRequestSync` first calls `LoadMetaDat`, writes opcode `123`, writes subtype `1`, writes a zero third byte, and sends length `2` through the packet sender. This is the client sync-list request.
- subtype `1`: server table/checksum list. The handler reads the server table count from packet offset `+2`, walks local `m_tables`, scans server records of `nameLength`, narrow table name bytes, and 4-byte checksum, removes local tables absent from the server list, and marks `m_dirty`. For each server record, it finds the local table, calls `MetaTable::DecompressAndValidateData` / checksum validation, sends subtype `0` requests for missing or invalid tables, and increments `m_pendingTableRequests`. When no requests remain, it sets `m_synchronized = true` and calls `SaveMetaDatIfDirty`.
- subtype `0`: single table payload response. The handler reads the table-name length at `packet+2`, table-name bytes at `packet+3`, and the 4-byte checksum after the name. It finds an existing `MetaTable` or allocates a new `0x24` byte table and inserts it in `m_tables`, resets stale table data when reusing a table, reads a 2-byte payload length, copies the compressed payload into new storage, stores it at `MetaTable +0x10/+0x14`, validates it, marks `m_dirty`, decrements `m_pendingTableRequests`, and saves the cache when the pending count reaches zero.
- Other nonzero subtype values currently fall through to success/no-op after stack cleanup. Do not invent additional behavior without packet evidence.
- Range/error behavior: oversized table-name or payload conversions call `__report_rangecheckfailure`; file-open failure in `LoadMetaDat`/`SaveMetaDatIfDirty` tolerates a missing cache rather than making startup fatal; stale/missing metadata is resolved by subtype `0` requests rather than by trusting local cache bytes.

## Lookup Behavior

`FindEntry` and `LoadStatValues` first consult the alias-aware lookup key stored at [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md), documented as [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md). The object is initialized empty in the current image, so `g_metaAliasTableName` is a best-supported role name rather than proof of a source literal such as `"Alias"`.

Alias-first lookup behavior:

- Call the direct indexed lookup with `g_metaAliasTableName` and the caller's table name as the row key.
- Compare the alias result to [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md).
- If the first alias lookup is empty, fall back to the caller-provided table name.
- If a later alias lookup is empty, stop or return no result.
- If an alias table name is returned, perform the row lookup in that alias table.

`0x00523030` follows the same alias-aware pattern for value counts. `GetValueCount` is the shortest best source-facing name, with `GetRowValueCount` as a reasonable alternative. No direct callers are currently observed in exported data, so document it as retained/unused source API or an unreferenced helper until a caller is found.

Current high-value consumers:

- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) uses `FindEntry` and `LoadStatValues` while formatting rich item tooltip data.
- [UID:00002X][CollectionPane](by-class/CollectionPane.md) uses metadata tables named `Collections` and `GroupNames`.
- Resource/image helper code near `0x004d1fa0` reads metadata text/resources through [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md).
- Network/session code constructs the manager and dispatches sync packets through `LoadMetaDatAndRequestSync` and `HandleMetaPacket`.

## Evidence Notes

- IDA MCP on 2026-05-24 confirms starts and sizes for the major methods from `0x005227d0` through `0x005244e0`.
- IDA MCP callers show `MetaMan::MetaMan` is constructed from application startup, while `LoadMetaDatAndRequestSync` and `HandleMetaPacket` are called from the session/network path with `g_pMetaMan`.
- IDA MCP callers show `0x005237d0` is called only from `HandleMetaPacket`, supporting a private save/finish-sync helper in this source file.
- IDA MCP xrefs to `0x0069b410` show reads from item help, resource helper, session/network, startup request, and CollectionPane code, plus writes in MetaMan constructor/destructor paths.
- IDA MCP xrefs to [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) show calls from the `MetaMan` metadata tree cleanup paths at `0x00523f3e`, `0x0052418c`, and `0x005243a3`.
- 2026-06-13 read-only IDA MCP refreshed the direct class-child evidence for [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md): `lookup_funcs` reports a `0x21` / 33-byte helper (Verified with `int_convert.py`), `analyze_function` reports one basic block and the same three callers inside the `0x00523df0`, `0x00523f50`, and `0x005241a0` local tree insert/rollback helpers, and `get_bytes` confirms all-`0xcc` padding at `0x00524581-0x00524590` and `0x005245b1-0x005245c0`.
- The same 2026-06-13 pass verified the helper calls the `0x00524400` small-string cleanup helper on node `+0x10` and then the `0x005c7526` sized free routine with `0x2c` / 44 bytes (Verified with `int_convert.py`), proving the direct class-owned table-tree node cleanup role without relying on generated source names.
- Current generated evidence has moved from stale flat `class_MetaMan.cpp` references to `source-3/simroot_v2/metadata/MetaMan.cpp` and `source-3/project-documentation/auto-generated/NexusTK/metadata/MetaMan.cpp`.
- Exported function data and existing IDA-backed docs resolve helper names around `0x005237d0-0x00523c99` well enough for first-draft class declaration; exact body C++ still belongs on method/helper child pages.

## Source Declaration Readiness

The class page now emits `#include "MetaMan.h"` plus `[[CHILDREN]]` in CPP and the complete guarded declaration in H. The H route includes complete `Singleton` and `SimpleUString` definitions, forward-declares pointer-only `MetaTable`, exposes the single `g_pMetaMan` extern, and guards exact object size `0x14`. Pointer parameters for `SimpleUString` preserve current binary signatures. `LoadMetaDatAndRequestSync` retains its packet-send result and `HandleMetaPacket` retains best-supported bool source type.

Do not add explicit raw tree-node members to the source declaration. Model the storage as `std::map<SimpleUString, MetaTable *> m_tables`, followed by `m_pendingTableRequests`, `m_synchronized`, and `m_dirty`.

## Generated Wrapper / Helper Policy

- The scalar deleting destructor at `0x005244e0` is compiler-generated ABI glue. Source should expose `virtual ~MetaMan();`; no formal scalar-deleting destructor body should be hand-authored.
- Singleton publication and clear are direct base construction/destruction effects and should not appear as manual MetaMan statements.
- The five-byte `0x00522950` thunk tail-jumps to `SaveMetaDatIfDirty`; it has no separate source body.
- Tree/list helpers from `0x00523cf0` through `0x00524470` are old MSVC map/tree support emitted from `m_tables`; keep their audit names in documentation, but represent them in source through the map declaration unless an exact child page proves a human-authored helper body.
- Broad method/helper bodies such as `HandleMetaPacket`, `LoadMetaDat`, `SaveMetaDatIfDirty`, and the direct lookup helpers should live in exact by-memory pages after body-level source passes. Do not paste broad decompiler bodies into this class declaration.

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0004SS][0x0061fad0-0x0061fadc.MetaManVtableData](by-memory/0x0061fad0-0x0061fadc.MetaManVtableData.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md)
- [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA accepted callback: raised `91/93 -> 94/94`, moved the complete accepted declaration from CPP to guarded `MetaMan.h`, added complete `Singleton.h`/`StringUtil.h`/`<map>` visibility, the single `g_pMetaMan` extern, and the exact `0x14` size guard. Class CPP is now only `#include "MetaMan.h"` plus `[[CHILDREN]]`; raw-tree, reduced-local, duplicate-class, and CPP-local declaration routes remain rejected.
- 2026-07-16 B002 UID0003PC implementation callback:
  - Raised `89/88` to `91/93`, retained owner/emitter UID0000LC and reconstructable true, and preserved every existing API/field/helper/packet/map declaration.
  - Added direct `Singleton<MetaMan>` inheritance, retained `0x14` size through EBO at `+0x04`, and placed `[[CHILDREN]]` after the class-closing `};`.
  - Linked exact compiler child UID0004SS and documented RTTI PMD, lifecycle table stores, implicit singleton publication/clear, scalar-wrapper no-code policy, and one-definition preservation.
- 2026-06-19 Agent-B009 source-quality pass:
  - Changed to: `COMPLETION:89`, `CONFIDENCE:88`.
  - Summary/evidence: resolved the `0x14` object size, private field layout at `+0x04/+0x08/+0x0c/+0x10/+0x11`, singleton publish/clear behavior, opcode `123` subtype `1`/`0` sync semantics, dirty-cache writer behavior, alias-aware lookup/value-count routes, direct helper names, map/tree helper no-code policy, and current first-draft class declaration readiness. Confidence remains below final-audit level because live IDA MCP was not exposed in the B009 session, exact original private member spelling and alias-key literal remain inferred, and broad method/helper bodies still need exact child-page source passes.
- 2026-06-13 Goal 2 parent-gate refresh:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:80`, with strong metadata-manager evidence but confidence below the strict `85/85` gate for newly attached direct class children.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP reconfirmed the [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) boundary, one-block function body, caller set in the `MetaMan` table-tree insert/rollback helpers, small-string payload cleanup at node `+0x10`, `0x2c` / 44-byte node free, and all-`0xcc` padding before the adjacent `MetaTable` lookup helper. Confidence remains below final-audit level because final private field names and exact original container spelling remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) because this class is 86/80 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed the metadata-manager lifecycle, load/sync, lookup, table-tree, save/cache, singleton-clear, scalar-deleting, and node-destroy starts from `0x005227d0` through `0x00524590`.
- Completion/confidence score update: existed before as `0/0`; changed to `86/80`. Summary: the metadata manager is documented in high detail across singleton ownership, loose `Meta.dat` cache handling, packet synchronization, lookup behavior, consumer relationships, helper ownership, and IDA evidence, but confidence remains medium-high because final helper names around `0x005237d0-0x00523c99` and the exact field layout still need a struct/name pass. Evidence: linked `MetaMan` range, `MetaTable` relationship, `g_pMetaMan`, alias-table lookup, packet subtype breakdown, IDA callers/xrefs, and node-destroy helper evidence.
