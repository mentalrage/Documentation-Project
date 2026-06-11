*** UID:000089 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MetaTable

## Status

- Likely source file: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Address range: [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md)
- Current recovered file: `source-3/simroot_v2/class_MetaTable.cpp`
- Confidence: strong for class role and owned lifecycle/decode/reset methods, medium for final names of table materialization helpers after `0x00524870`.

## Class Purpose

`MetaTable` is the per-table storage object owned by [UID:000088][MetaMan](by-class/MetaMan.md). A table holds compressed or decompressed payload bytes, validates server/file payloads by checksum, and lazily materializes keyed metadata rows into a tree for lookup.

`MetaMan` owns table lookup, file loading, and network synchronization. `MetaTable` owns the payload buffers and decoded row tree for one named metadata table.

## Observed State

```text
MetaTable
  +0x00  tree/list header or vtable-adjacent storage
  +0x08  m_keyData / decoded payload buffer
  +0x0c  m_keyDataSize
  +0x10  m_valueData / compressed payload buffer
  +0x14  m_valueDataSize
  +0x18  m_isLoaded / rows materialized flag
  +0x1c  m_rowTreeHeader
  +0x20  m_rowTreeSize
```

The generated field names are useful orientation, but offsets beyond the raw buffers still need a formal layout pass.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MetaTable::MetaTable` | `0x00524630-0x0052468b` | Constructs a table, initializes the row tree sentinel, and clears payload buffer fields. |
| `MetaTable::~MetaTable` | `0x00524690-0x00524726` | Frees key/value buffers and destroys row-tree nodes through `DestroyMetaTableTreeNodes_5258B0`. |
| `DecompressAndValidateData` | `0x00524730-0x0052486e` | Uncompresses `m_valueData` into `m_keyData`, computes CRC32 over decoded bytes, resets on mismatch, and compacts the buffer on success. |
| [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) provisional | `0x00524870-0x00524c55` | Parses decoded metadata rows, converts strings with `MultiByteToWideChar`, and populates the row tree. Current generated output leaves this as a helper, but callers pass a `MetaTable*`. |
| `ResetData` | `0x00524c60-0x00524d0d` | Frees payload buffers, destroys row nodes, and resets the table for reuse after a fresh server payload arrives. |
| [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) provisional | `0x00524d10-0x00525914` | Local support helpers used by the row materializer and tree/list cleanup. Keep near `MetaTable` unless later evidence proves a shared container owner. |
| `ScalarDeletingDestructor` | `0x00525780-0x0052582e` | Destructor wrapper that optionally frees `this`. |
| `DestroyMetaTableTreeNodes_5258B0` | `0x005258b0-0x005258f1` | Recursive global/helper function that frees row-tree nodes and row payload strings. |

## Decode And Lookup Flow

1. [UID:000088][MetaMan](by-class/MetaMan.md) reads or receives a compressed table payload into `MetaTable::m_valueData`.
2. `MetaTable::DecompressAndValidateData` inflates the payload into `m_keyData` and checks the expected CRC32.
3. Lookup paths call the provisional `0x00524870` materializer if the table has not been decoded into rows yet.
4. The materializer parses the [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) format into [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md) entries.
5. `FindEntry` and `LoadStatValues` then read row values from the table's tree through [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md).

The inflate and checksum helpers are bundled [UID:0000PC][Zlib](by-file/Zlib.md) support code. They are dependencies of `MetaTable`, not methods or private helpers owned by this class.

## Ownership Notes

- `DecompressAndValidateData` and `ResetData` are object-owned `MetaTable` methods, not `MetaMan` free helpers. They mutate table payload fields and share the same cleanup path.
- `DestroyMetaTableTreeNodes_5258B0` is a file-local or source-local helper rather than a class method. It is called by `MetaTable` destruction/reset paths and by itself recursively.
- The helper island through `0x00525914` is metadata-table support, but exact helper names should stay provisional until class ownership is re-run.

## Evidence Notes

- `simroot_v2/class_MetaTable.meta_wave3` identifies `MetaTable.cpp` as the imported source file and records five included class methods.
- IDA MCP confirms `MetaTable::MetaTable` has creation callers from `MetaMan::LoadMetaDat` and `MetaMan::HandleMetaPacket`.
- IDA MCP callers show `DecompressAndValidateData` is called only from `MetaMan::HandleMetaPacket`.
- IDA MCP callers show the `0x00524870` row materializer is reached by direct MetaMan lookup helpers and CollectionPane metadata initialization, supporting MetaTable-side ownership.
- IDA MCP decompilation shows `0x00524d10-0x00525914` provides row-node allocation, value-vector growth, tree insertion/rebalancing, `SimpleUString` copy/assignment, and cleanup support for the materializer.

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md)
- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md)
- [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md)
- [UID:0000PC][Zlib](by-file/Zlib.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) because this class is 84/80 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed table lifecycle/decode/materialization/reset/helper starts at `0x00524630`, `0x00524690`, `0x00524730`, `0x00524870`, `0x00524c60`, `0x00524d10`, `0x00525780`, and `0x005258b0`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the per-table metadata object has strong lifecycle, payload, decode, validation, reset, materialization, helper-island, and dependency documentation, but field names and helper names remain partly provisional. Evidence: linked `MetaTable` range, materializer and row-tree helper pages, decoded payload/row-node type docs, `MetaMan` lookup flow, IDA creation/caller evidence, and Zlib dependency classification.
