*** UID:000088 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MetaMan

## Status

- Likely source file: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Address range: [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- Singleton global: [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) at `0x0069b410`
- Current recovered file: `source-3/simroot_v2/class_MetaMan.cpp`
- Confidence: strong for class role and method ownership, medium for final helper names around `0x005237d0-0x00523c99`.

## Class Purpose

`MetaMan` is the process-wide manager for client metadata tables. It loads the local loose `Meta.dat` cache, synchronizes table payloads with the server through metadata packets, owns a name-keyed set of [UID:000089][MetaTable](by-class/MetaTable.md) objects, and exposes lookup helpers used by item help, collection panes, image/resource helpers, and session/network code.

This is metadata ownership, not raw DAT archive ownership. `Meta.dat` is opened as a loose file and stores compressed metadata table payloads; it should stay with `metadata/MetaMan.cpp`, while the DAT archive reader remains under [UID:0000IN][DATFile](by-file/DATFile.md).

## Observed State

```text
MetaMan
  +0x00  vtable / LObject-like base
          name-keyed table tree/list header
          pending metadata table request count
          synchronized / dirty state flags
```

The exact field layout still needs a struct pass. The durable ownership facts are that the constructor writes [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md), the destructor clears it, and all table lifecycle paths route through `MetaTable` objects stored by wide table name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MetaMan::MetaMan` | `0x005227d0-0x0052285c` | Constructs the metadata manager, initializes the table storage, and sets `g_pMetaMan = this`. |
| `MetaMan::~MetaMan` | `0x00522860-0x005228e2` | Clears manager state, destroys table nodes, releases list storage, and clears `g_pMetaMan`. |
| `LoadMetaDatAndRequestSync` | `0x005228f0-0x00522940` | Loads local `Meta.dat`, then sends opcode `123`, subtype `1` to request metadata synchronization. |
| `HandleMetaPacket` | `0x00522960-0x00522fe2` | Handles metadata sync/checksum lists and table payload responses from the server. |
| `FindEntry` | `0x00523120-0x005231e5` | Public lookup API: applies the alias table first, then returns an indexed `SimpleUString` value or the shared empty string. |
| `LoadStatValues` | `0x005231f0-0x00523325` | Loads multiple row values into caller-owned wide-string row buffers, used by item help/stat presentation. |
| `FindTableByName` | `0x00523330-0x005233c3` | Looks up a `MetaTable*` by wide table name in the manager tree. |
| `DestroyMetaManBase` | `0x005233d0-0x00523465` | Clears all owned table state without freeing the manager object. |
| `LoadMetaDat` | `0x00523470-0x005237bf` | Opens loose `Meta.dat`, reads table records, creates `MetaTable` objects, and inserts them into the manager tree. |
| `SaveMetaDatIfDirty` provisional | `0x005237d0-0x005239fa` | Writes the local `Meta.dat` cache after packet synchronization marks tables dirty. Only called from `HandleMetaPacket`. |
| Direct lookup helpers provisional | `0x00523a00-0x00523c99` | Lower lookup/materialization helpers used by `FindEntry`, `LoadStatValues`, and CollectionPane metadata initialization. |
| `ClearMetaManSingleton` provisional | `0x00524460-0x0052446a` | Small global clear helper referenced near teardown metadata. |
| `ScalarDeletingDestructor` | `0x005244e0-0x00524580` | Destructor wrapper that optionally frees `this`. |
| [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) provisional | `0x00524590-0x005245b1` | Metadata tree-node payload cleanup and 44-byte node free helper called from `MetaMan` cleanup paths. |

## Packet Synchronization

Metadata packets use opcode `123` with a subtype byte:

- subtype `1`: server table/checksum list. The manager prunes local tables absent from the server list, validates existing payloads with `MetaTable::DecompressAndValidateData`, sends subtype `0` requests for missing or stale tables, and tracks the pending request count.
- subtype `0`: single table payload response. The manager finds or allocates the target `MetaTable`, resets stale data when needed, stores the received payload, validates it, marks the cache dirty, decrements the pending count, and writes `Meta.dat` when synchronization completes.

## Lookup Behavior

`FindEntry` and `LoadStatValues` first consult the alias-aware lookup key stored at [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md), documented as [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md). If no alias applies, they fall back to the caller-provided table name.

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
- `simroot_v2` generated source and older Wave2 notes agree on the class methods, but generated helper names around `0x005237d0-0x00523c99` should remain provisional until an ownership dry run is performed.

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
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

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) because this class is 86/80 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed the metadata-manager lifecycle, load/sync, lookup, table-tree, save/cache, singleton-clear, scalar-deleting, and node-destroy starts from `0x005227d0` through `0x00524590`.
- Completion/confidence score update: existed before as `0/0`; changed to `86/80`. Summary: the metadata manager is documented in high detail across singleton ownership, loose `Meta.dat` cache handling, packet synchronization, lookup behavior, consumer relationships, helper ownership, and IDA evidence, but confidence remains medium-high because final helper names around `0x005237d0-0x00523c99` and the exact field layout still need a struct/name pass. Evidence: linked `MetaMan` range, `MetaTable` relationship, `g_pMetaMan`, alias-table lookup, packet subtype breakdown, IDA callers/xrefs, and node-destroy helper evidence.
