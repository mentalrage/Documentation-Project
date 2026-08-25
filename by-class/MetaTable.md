*** UID:000089 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_METADATA_METATABLE_H
#define NEXUSTK_METADATA_METATABLE_H

#include <map>
#include <vector>
#include "../util/StringUtil.h"

class MetaTable
{
public:
    typedef std::map<SimpleUString,
                     std::vector<SimpleUString> > RowMap;

    MetaTable();
    virtual ~MetaTable();

    bool DecompressAndValidateData(unsigned int expectedChecksum);
    void MaterializeRowsIfNeeded(const wchar_t *tableNameHint);
    void ResetData();

    const RowMap &Rows() const { return m_rows; }
    bool IsMaterialized() const { return m_isLoaded; }

private:
    unsigned int m_checksum;
    unsigned char *m_keyData;
    unsigned int m_keyDataSize;
    unsigned char *m_valueData;
    unsigned int m_valueDataSize;
    bool m_isLoaded;
    RowMap m_rows;
};

typedef char MetaTableSizeMustBe0x24[
    sizeof(MetaTable) == 0x24 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MetaTable

## Status

- Likely source file: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Address range: [UID:0001CB][0x00524630-0x00525914.MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md)
- Generated recovered-file lead: `source-3/simroot_v2/class_MetaTable.cpp` (not final placement proof; current direct owner remains [UID:0000LC][MetaMan](by-file/MetaMan.md) from by-* and IDA evidence)
- Confidence: strong for class role, owned lifecycle/decode/reset/materialization methods, decoded payload ownership, and the corrected `0x00524630-0x00525914` aggregate boundary; medium-high for final helper names after `0x00524870`.
- Assignment gate: direct parent [UID:0000LC][MetaMan](by-file/MetaMan.md) is now `91/90`, and this class is `90/90`, so the strict child/direct-parent `85/85` gate is satisfied for class-owned type children such as [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md).

## Class Purpose

`MetaTable` is the per-table storage object owned by [UID:000088][MetaMan](by-class/MetaMan.md). A table holds compressed or decompressed payload bytes, validates server/file payloads by checksum, and lazily materializes keyed metadata rows into a tree for lookup.

`MetaMan` owns table lookup, file loading, and network synchronization. `MetaTable` owns the payload buffers and decoded row tree for one named metadata table.

B009's MetaMan class pass confirms the dependency boundary from the manager side: `MetaMan` stores compressed payload buffers into `MetaTable +0x10/+0x14`, tests the loaded/materialized flag at `+0x18`, walks the row tree header/sentinel at `+0x1c`, and reads the materialized row count at `+0x20`. These offsets remain `MetaTable` storage, not `MetaMan` fields.

## Observed State

```text
MetaTable
  +0x00  tree/list header or vtable-adjacent storage
  +0x08  m_keyData / decoded payload buffer
  +0x0c  m_keyDataSize
  +0x10  m_valueData / compressed payload buffer
  +0x14  m_valueDataSize
  +0x18  m_isLoaded / rows materialized flag
  +0x1c  m_rows header/sentinel for std::map<SimpleUString, std::vector<SimpleUString>>-style row map
  +0x20  m_rows size / materialized row count
```

The generated field names are useful orientation. B014's accepted materializer pass treats `+0x1c/+0x20` as the preferred source-facing `m_rows` abstraction for the row materializer while preserving the old MSVC tree-header/size implementation details in the row-node/helper docs.

## Formal C++ Disposition

Formal CPP is children-only. The complete guarded H route exposes the accepted `RowMap`, `Rows()`, `IsMaterialized()`, lifecycle/decode/materialize/reset API, exact payload fields, and `0x24` size guard. This is source-ready because current MCP evidence proves the vtable slot, checksum field at `+0x04`, decoded buffer at `+0x08/+0x0c`, compressed buffer at `+0x10/+0x14`, loaded/materialized flag at `+0x18`, and row-map storage at `+0x1c/+0x20`.

The private names `m_keyData`, `m_valueData`, `m_isLoaded`, and `m_rows` are accepted source-facing inferred names, not original-symbol proof. The `RowMap` abstraction preserves compatibility with [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md), [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md), and [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md) while keeping old MSVC row-tree details out of authored methods. Raw row-tree helper calls remain represented by [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md), not by hand-authored calls in ordinary `MetaTable` methods.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MetaTable::MetaTable` | `0x00524630-0x0052468b` | Constructs a table, initializes the row tree sentinel, and clears payload buffer fields. |
| `MetaTable::~MetaTable` | `0x00524690-0x00524726` | Frees key/value buffers and destroys row-tree nodes through `DestroyMetaTableTreeNodes_5258B0`. |
| `DecompressAndValidateData` | `0x00524730-0x0052486e` | Uncompresses `m_valueData` into `m_keyData`, computes CRC32 over decoded bytes, resets on mismatch, and compacts the buffer on success. |
| [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) | `0x00524870-0x00524c55` | `MetaTable::MaterializeRowsIfNeeded(const wchar_t *tableNameHint)` parses decoded metadata rows, converts strings with `MultiByteToWideChar`, appends values through `m_rows[rowKey].push_back(valueText)`, frees/clears `m_keyData` and `m_keyDataSize`, and sets the rows-materialized `m_isLoaded` flag. The caller-provided table-name hint is ABI-retained but unused. |
| `ResetData` | `0x00524c60-0x00524d0d` | Frees payload buffers, destroys row nodes, and resets the table for reuse after a fresh server payload arrives. |
| [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) | `0x00524d10-0x00525914` | Old MSVC row-map/vector support used by the row materializer and tree cleanup: row allocation, tree insertion, `SimpleUString` copy/assignment, 24-byte value-vector append/grow, sentinel allocation, and cleanup. |
| `ScalarDeletingDestructor` | `0x00525780-0x0052582e` | Destructor wrapper that optionally frees `this`. |
| `DestroyMetaTableTreeNodes_5258B0` | `0x005258b0-0x005258f1` | Recursive global/helper function that frees row-tree nodes and row payload strings. |

## Decode And Lookup Flow

1. [UID:000088][MetaMan](by-class/MetaMan.md) reads or receives a compressed table payload into `MetaTable::m_valueData`.
2. `MetaTable::DecompressAndValidateData` inflates the payload into `m_keyData` and checks the expected CRC32.
3. Lookup paths call `MetaTable::MaterializeRowsIfNeeded(const wchar_t *tableNameHint)` if the table has not been decoded into rows yet.
4. The materializer parses the [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) format into [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md) entries. The row count, value count, and value byte lengths are big-endian/network-order reads through `PacketBufferReadUInt16BE`; key/value bytes are converted through `MultiByteToWideChar(0,0,...)`; and values append through the source-facing `m_rows[rowKey].push_back(valueText)` abstraction.
5. `FindEntry`, `LoadStatValues`, and the alias-aware `MetaMan::GetValueCount` wrapper then read row values from the table's tree through [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) and [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md).

The inflate and checksum helpers are bundled [UID:0000PC][Zlib](by-file/Zlib.md) support code. They are dependencies of `MetaTable`, not methods or private helpers owned by this class.

## Ownership Notes

- `DecompressAndValidateData` and `ResetData` are object-owned `MetaTable` methods, not `MetaMan` free helpers. They mutate table payload fields and share the same cleanup path.
- `DestroyMetaTableTreeNodes_5258B0` is a file-local or source-local helper rather than a class method. It is called by `MetaTable` destruction/reset paths and by itself recursively.
- The helper island through `0x00525914` is metadata-table support and now attaches directly to this class. B014's materializer pass resolves the target-level source abstraction to `m_rows[rowKey].push_back(valueText)` over a `std::map<SimpleUString, std::vector<SimpleUString>>`-style member; the raw helper functions remain compiler/container support, not hand-authored calls in target C++. Exact helper names and red/black color polarity stay below-final-audit caveats.
- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) is a source-ready file-local helper, not a `MetaTable::` method. It operates on `m_rowTreeHeader` and [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md) fields, uses the accepted `SimpleUStringLessThan` comparator name, and now has formal first-draft C++ on its exact by-memory page. Broader `MetaTable` helper-island C++ still carries final-audit uncertainty around exact original row-container spelling and red/black color polarity.

## Evidence Notes

- Historical generated/Wave3 lead material `simroot_v2/class_MetaTable.meta_wave3` identifies `MetaTable.cpp` as the imported source file and records five included class methods, but this is not active owner proof; current by-* docs and IDA evidence keep the class routed through [UID:0000LC][MetaMan](by-file/MetaMan.md).
- IDA MCP confirms `MetaTable::MetaTable` has creation callers from `MetaMan::LoadMetaDat` and `MetaMan::HandleMetaPacket`.
- IDA MCP callers show `DecompressAndValidateData` is called only from `MetaMan::HandleMetaPacket`.
- IDA MCP callers show the `0x00524870` row materializer is reached by direct MetaMan lookup helpers and CollectionPane metadata initialization, supporting MetaTable-side ownership.
- IDA MCP decompilation shows `0x00524d10-0x00525914` provides row-node allocation, value-vector growth, tree insertion/rebalancing, `SimpleUString` copy/assignment, and cleanup support for the materializer.
- 2026-06-11 read-only IDA MCP reconfirmed the class-owned function island: `MetaTable::MetaTable` `0x00524630-0x0052468c`, destructor `0x00524690-0x00524727`, decode/CRC method `0x00524730-0x0052486f`, row materializer `0x00524870-0x00524c55`, reset `0x00524c60-0x00524d0d`, scalar deleting destructor `0x00525780-0x0052582e`, tree-header allocator call from the constructor at `0x00524656`, and recursive cleanup calls from destructor/decode/reset/scalar-delete paths.
- The same audit reconfirmed the materializer's decoded payload parser: row count/value counts/value lengths are read through `sub_575480`, keys and values convert through `MultiByteToWideChar`, row nodes are allocated/inserted through `0x00524d10`/`0x00525120`, values append through `0x00524db0`, and the decoded buffer is freed at `0x00524b91`.
- 2026-06-13 C001 live read-only IDA MCP reconfirmed the stale barrier-crossing report was not mixed ownership: every modeled function from `0x00524630` through `0x00525914` belongs to the MetaTable lifecycle/materialization/helper island, `0x00525914-0x00525920` is padding, and `0x00525920` starts the separate MIDI/audio island. `xrefs_to` constrains the row-tree helper entries to `MetaTable::MetaTable`, the materializer, cleanup paths, and internal helper calls.
- 2026-06-25 Agent-B007 read-only source-quality sync confirms [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) uses the row header at `MetaTable +0x1c`, `MetaTableRowNode` links/fields, and `SimpleUStringLessThan` to implement the lower-bound row lookup. The formerly extra `0x005230d1` call belongs to the unmodeled alias-aware `MetaMan::GetValueCount` wrapper, so it no longer blocks this helper's first-draft C++.
- 2026-06-27 Agent-B014 accepted materializer implementation confirms live MCP session `b001_000241_20260627` and resolves [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) to formal first-draft C++. The target's `const wchar_t *tableNameHint` parameter is caller-provided and unused; `m_keyData` is consumed as a decoded payload, then freed and cleared with `m_keyDataSize`; `m_isLoaded` is set as the rows-materialized flag; and `+0x1c/+0x20` are best documented as `m_rows`, a `std::map<SimpleUString, std::vector<SimpleUString>>`-style row map.

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:0001CB][0x00524630-0x00525914.MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md)
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

- 2026-08-16 Agent-B008 UID0003FA accepted callback: raised `90/90 -> 94/93`, moved the accepted table abstraction from CPP into one guarded complete H route, added `RowMap`, `Rows()`, `IsMaterialized()`, exact payload fields, complete StringUtil/map/vector dependencies, and the `0x24` size guard. Formal CPP is now exactly `[[CHILDREN]]`; old-MSVC row-tree helpers remain compiler/container support rather than authored table methods.
- 2026-07-02 Agent-B007 UID0000LC implementation callback:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:90`.
  - Summary/evidence: inserted the formal first-draft `MetaTable` class declaration from the accepted empty-emitter family report, preserving constructor/destructor/decode/reset/materializer route evidence, the `m_rows` abstraction caveat, accepted inferred field names, and raw row helper support as compiler/container implementation evidence rather than hand-written method source. Confidence remains below final audit because exact original private member spelling and final row-container spelling are still inferred.
- 2026-06-19 Agent-B009 MetaMan dependency note:
  - Score unchanged.
  - Summary/evidence: recorded the manager-side dependency on `MetaTable +0x10/+0x14` compressed payload storage, `+0x18` loaded/materialized flag, `+0x1c` row tree header, and `+0x20` row count while preserving MetaTable source-body work for its own class/range pages.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LC][MetaMan](by-file/MetaMan.md) because this class is 84/80 and the parent file is 88/82. Live IDA MCP on `NexusTK.exe` confirmed table lifecycle/decode/materialization/reset/helper starts at `0x00524630`, `0x00524690`, `0x00524730`, `0x00524870`, `0x00524c60`, `0x00524d10`, `0x00525780`, and `0x005258b0`.
- Completion/confidence score update: existed before as `0/0`; changed to `84/80`. Summary: the per-table metadata object has strong lifecycle, payload, decode, validation, reset, materialization, helper-island, and dependency documentation, but field names and helper names remain partly provisional. Evidence: linked `MetaTable` range, materializer and row-tree helper pages, decoded payload/row-node type docs, `MetaMan` lookup flow, IDA creation/caller evidence, and Zlib dependency classification.
- 2026-06-11 A004 strict parent-gate refresh:
  - What existed before: `84/80`, enough for the old assignment threshold but below the current strict `85/85` gate needed by [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md).
  - Changed to: `85/86`.
  - Summary/evidence: read-only IDA MCP reconfirmed constructor/decode/materializer/reset/destructor/helper boundaries, direct callers from MetaMan load/sync and lookup paths, tree-header allocation, cleanup call paths, decoded-payload parser helper calls, row-node insertion/value append calls, decoded-buffer free, and adjacent padding. Confidence remains below `95` because final field/helper names and exact original container spelling remain open.
- 2026-06-13 C001 Goal 2 barrier repair:
  - What existed before: class score `85/86`, with the row-tree helper page still attached directly to [UID:0000LC][MetaMan](by-file/MetaMan.md) and the aggregate memory page using the stale `0x00524630-0x005258f1` range.
  - Changed to: `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed the corrected `0x00524630-0x00525914` MetaTable aggregate, the `0x00525900-0x00525914` cleanup thunk, the `0x00525914-0x00525920` padding, the `0x00525920` MIDI successor, and constrained helper xrefs. [UID:0001CB][0x00524630-0x00525914.MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md) and [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) now attach directly to this class; broad class/helper-island C++ remained blank at that time because helper names, field names, and tree/color source spelling were still below final-audit certainty.
- 2026-06-25 Agent-B007 row lookup sync:
  - Score unchanged.
  - Summary/evidence: synchronized [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) after B007 resolved the alias-aware value-count wrapper call, promoted the exact lookup helper to first-draft formal C++, and confirmed the accepted field names `m_rowTreeHeader`, `MetaTableRowNode`, and `SimpleUStringLessThan` are sufficient for that narrow helper while broader tree helper/color/container spelling remains below final-audit certainty.
- 2026-06-27 Agent-B014 materializer implementation:
  - Score unchanged.
  - Summary/evidence: incorporated the accepted [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) source-quality pass. The class now records `m_rows` as the preferred source-facing abstraction for `+0x1c/+0x20`, documents the unused ABI-retained `tableNameHint`, `m_keyData` consumption/free/clear, `m_keyDataSize` clear, `m_isLoaded` row-materialized semantics, big-endian `PacketBufferReadUInt16BE` decoded fields, and the rejection of raw helper-call source for the materializer.
