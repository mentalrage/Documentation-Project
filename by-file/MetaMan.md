*** UID:0000LC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/metadata/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MetaMan

## Status

- Proposed source path: `metadata/MetaMan.cpp`
- Proposed header path: `metadata/MetaMan.h`
- Current generated sources: `source-3/simroot_v2/class_MetaMan.cpp`, `source-3/simroot_v2/class_MetaTable.cpp`, and `source-3/simroot_v2/recovered/DestroyMetaTableTreeNodes_005258B0.cpp`
- Main ranges: [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md) and [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md)
- Confidence: strong for module ownership, medium for final folder name.

## File Role

`MetaMan.cpp` should own the client metadata table subsystem: local `Meta.dat` cache loading/saving, server synchronization packets, process-wide metadata lookup, and per-table compressed/decompressed storage.

This source should be reconstructed as a metadata/data-definition module, not as a DAT archive module. It consumes normal file APIs and network packets directly, while [UID:0000IN][DATFile](by-file/DATFile.md) owns the separate packed resource archive API used for `.DAT`/EPF/palette/audio resources.

## Proposed Contents

| Entity | Range / address | Role |
| --- | --- | --- |
| [UID:000088][MetaMan](by-class/MetaMan.md) | `0x005227d0-0x00524581` | Singleton metadata manager, `Meta.dat` cache owner, server sync owner, lookup API. |
| [UID:000089][MetaTable](by-class/MetaTable.md) | `0x00524630-0x005258f1` | Per-table payload/decode/tree object owned by `MetaMan`. |
| [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) | `0x0069b410` | Process-wide singleton pointer. |
| [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) | `0x0066daec` | Shared empty return value for failed metadata lookups. Final source owner may be shared string support rather than private metadata state. |
| [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md) | [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) | Static `SimpleUString` key used by alias-aware lookups before fallback lookups. |
| `DestroyMetaTableTreeNodes_5258B0` | `0x005258b0-0x005258f1` | File-local row-tree cleanup helper for `MetaTable`. |
| [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) | `0x00523a00-0x00523c99` | Lower helpers used by `FindEntry`, `LoadStatValues`, and metadata table materialization. |
| [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) | `0x005245c0-0x0052462a` | Source-local row-tree lookup helper in the gap before the `MetaTable` constructor. |
| [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) | `0x00524870-0x00524c55` | Parses decoded table payloads into row nodes and value vectors. |
| [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) | `0x00524d10-0x00525914` | Row-node allocation, vector growth, tree insertion, string copy/assignment, and cleanup helpers. |
| [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md) | `0x00524590-0x005245b1` | Metadata tree-node payload cleanup and node free helper called from `MetaMan` cleanup paths. |

## Likely Original Source Group

```text
metadata/MetaMan.cpp
  class MetaMan
  class MetaTable
  MetaTable row/tree helper structs
  Meta.dat load/save helpers
  metadata packet sync helpers
  g_pMetaMan
  g_emptySimpleUString
  g_metaAliasTableName
```

An original flat project may have used `MetaMan.cpp` at the project root rather than a `metadata/` folder. The proposed folder is a reconstruction convenience: it keeps loose metadata cache/sync code separate from `archive/` DAT parsing and from UI consumers.

## Startup And Synchronization

Application startup constructs `MetaMan` before later render/palette startup work. Session/network code then calls `LoadMetaDatAndRequestSync`, which loads the local cache and sends a metadata sync request. Incoming metadata packets are dispatched to `HandleMetaPacket`.

The manager uses opcode `123` packets:

- subtype `1` requests or receives the table/checksum list;
- subtype `0` requests or receives one named table payload.

When all pending table payloads are current, the private save helper at `0x005237d0` writes dirty metadata state back to loose `Meta.dat`.

## Consumers

Known consumers should stay in their own modules and call into `MetaMan`:

- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) formats tooltip text from item metadata.
- [UID:00002X][CollectionPane](by-class/CollectionPane.md) loads `Collections` and `GroupNames` metadata.
- Resource/image helper code around `0x004d1fa0` queries metadata text/resources.
- Session/network code owns packet dispatch but not metadata table state.

## Data Caveats

- `simroot_v2` is generated evidence. It correctly identifies the main class methods here, but helper names and some ownership around `0x00523a00-0x00525914` should be treated as provisional until a later ownership dry run.
- Older generated owner projections incorrectly pushed some lookup helpers toward CollectionPane or anonymous containers. Current IDA caller/callee evidence supports MetaMan/MetaTable ownership instead.
- `Meta.dat` record field names are not final. The loader clearly reads table count, a header block, UTF-16 table names, and payload sizes before reading table payload blocks, but secondary header fields should remain open until the file format is fully mapped.
- The decompressed per-table payload format now has a first-pass structure in [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md). That structure describes post-zlib row/value bytes, not the outer `Meta.dat` header.

## Cross-References

- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md)
- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md)
- [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md)
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md)
- [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md)
- [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Summary/evidence: the page documents the manager/table split, globals, helper ranges, startup/sync flow, resource behavior, consumers, caveats, and related type/resource docs; confidence stays below very high because final folder name and some secondary `Meta.dat` field names remain open.
- 2026-06-01: set projected reconstruction path to `NexusTK/metadata/` so validated MetaMan/MetaTable memory children can attach to this file root. The narrative still records that an original flat source tree may have used `MetaMan.cpp` at project root.
- 2026-06-03: updated the `MetaTableMaterializeRows` child range to the live IDA half-open boundary `0x00524870-0x00524c55`; the child is now attached here after caller/callee and padding audits.
- 2026-06-03: updated `MetaTableRowTreeHelpers` child evidence and attached it here; live IDA confirms exact helper endpoints, `0x00525830-0x00525849` tree-header allocation, and `DestroyMetaTableTreeNodes_5258B0` ending at `0x005258f1`.
