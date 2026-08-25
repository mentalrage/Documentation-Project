*** UID:0001RH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Meta.dat Metadata Cache

## Status

- Resource kind: loose local metadata cache file.
- Owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: very strong for ownership, loose-cache lifecycle, loader/writer routing, current loose-file provenance, and payload/cache layer split; medium for exact secondary header-field names.

## Observed Role

`Meta.dat` stores local copies of server-provided metadata tables. [UID:000088][MetaMan](by-class/MetaMan.md) loads this file during metadata synchronization startup, validates table payloads against the server's checksum list, requests stale or missing payloads, and writes the file again after successful synchronization.

This file is not the same thing as the client's packed DAT archive system. It is a loose file opened directly by `MetaMan`, while archive-backed resources such as `str.res`, `.PAL`, `.EPF`, `.EPD`, audio, and image assets flow through [UID:0000IN][DATFile](by-file/DATFile.md).

## Payload Provenance

2026-06-14 A002 audited `E:\2026\Resources\Read_Only\NexusTK`. No packed DAT entry named `Meta.dat` was found under `Data`; the current tree instead contains a loose cache file at `E:\2026\Resources\Read_Only\NexusTK\Meta.dat`.

| Evidence | Value | Notes |
| --- | --- | --- |
| Loose file size | `243,932` bytes | Confirms this resource is a shipped/read-only loose cache file in the audited tree, not a packed DAT entry. |
| Top-level header | table count `32`, header byte count `1,048`, payload start offset `1,056` | Matches the loader/writer model of count, header block, then compressed payload blocks. |
| Header records | 16-bit serialized name-length slot, UTF-16 table name, then 8 secondary bytes per record | Current length values fit in one byte, while the writer advances by two bytes before UTF-16 name bytes. The secondary bytes are now known to include a big-endian compressed payload size followed by four zero bytes in this sample; final source field names remain provisional. |
| Table names | `CharicInfo0` through `CharicInfo25`, `Collections`, `GroupNames`, `ItemInfo0`, `ItemInfo1`, `ItemInfo2`, `RidableAnimals` | Header record order matches the following payload block order. |
| Payload blocks | 32 zlib streams totaling `242,876` bytes | Big-endian compressed sizes from the header sum exactly to the remaining file length. Each sampled block starts with zlib header bytes and decompresses successfully. |
| Decoded payload samples | `CharicInfo0` decompresses to `48,768` bytes; `Collections` to `9,800`; `GroupNames` to `69`; `RidableAnimals` to `14,211` | Confirms the cached table blocks are compressed metadata table payloads consumed by `MetaTable`, not source-authored literal tables. |

## Rebuild And Packaging Boundary

| Layer | Rebuild handling | Notes |
| --- | --- | --- |
| Loose `Meta.dat` cache file | `resource-derived` / runtime cache | The rebuilt client should know how to read, validate, request, and rewrite this file, but the checked-in source tree should not hard-code a shipped binary copy as C++ data. |
| Outer cache header | source-authored parser/writer logic | Table count, header byte count, table names, compressed payload sizes, and secondary per-table fields belong to `MetaMan` load/save code. Current payload audit confirms the size field encoding for this sample; exact source names remain provisional until the read and write paths are reconciled. |
| Compressed table payload blocks | server/resource-derived payloads | Payload bytes are cached server metadata table data. They are stored in [UID:000089][MetaTable](by-class/MetaTable.md), decompressed, CRC32-checked, and regenerated through metadata synchronization when stale. |
| Decoded row/value bytes | parsed runtime data | [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) documents the post-zlib format. That format is not the same layer as the outer `Meta.dat` file header. |

## Cache Layer Contract

| Contract point | Source-owned behavior | Payload/runtime data | Boundary notes |
| --- | --- | --- | --- |
| File discovery and open | `MetaMan` builds the loose `Meta.dat` path and opens it through normal file I/O during metadata startup. | The local cache file may be absent, stale, or malformed. | Do not route this through packed `DATFile` archive lookup. |
| Header parse/write | `MetaMan` reads and writes table count, header byte count, table names, payload sizes, and secondary per-table fields. | Header bytes are serialized cache metadata, not final C++ structs until loader/writer fields are reconciled. | Keep field names provisional; exact checksum/reserved ordering is still open. |
| Payload cache | `MetaMan` transfers compressed payload blocks into `MetaTable` objects and writes them back when dirty. | Compressed server metadata table payloads. | Payload bytes should be regenerated by synchronization, not hard-coded into source. |
| Validation/materialization | `MetaTable` decompresses, CRC-validates, and materializes rows for lookup consumers. | Decoded row keys and values documented by the type/memory pages. | This page links the layer, but table-specific column naming belongs with metadata consumer/type docs. |

## Observed Layout

Current loader evidence supports this broad shape:

```text
Meta.dat
  uint32 tableCount
  uint32 headerSize
  header records:
    table name length / UTF-16 table name
    table payload size
    additional per-table fields, likely checksum/reserved data
  payload blocks:
    compressed metadata table data for each table
```

The current loose cache confirms the header-record stride as a two-byte name-length slot, variable UTF-16 name bytes, plus 8 secondary bytes. The writer uses the byte packet/helper path for current length values but advances by two bytes before copying UTF-16 name bytes, so describe this as a 16-bit serialized length slot whose current high byte is zero/padding unless a later raw/source pass proves a different field split. The first four secondary bytes encode the compressed payload size in big-endian order in this sample; the following four bytes are zero for all 32 records. Do not commit final source field names for the secondary per-table fields until the writer at `0x005237d0` and loader at `0x00523470` are reconciled field by field.

## Cache Lifecycle

| Phase | Owner/path | Evidence |
| --- | --- | --- |
| Startup local load | [UID:000088][MetaMan](by-class/MetaMan.md) / [UID:0000LC][MetaMan](by-file/MetaMan.md) | `MetaMan::LoadMetaDatAndRequestSync` calls the local loader before sending the metadata synchronization request. |
| Local cache parse | `0x00523470-0x005237c0` | Opens loose `Meta.dat`, reads table count and header byte count, builds per-table metadata, creates [UID:000089][MetaTable](by-class/MetaTable.md) objects, and reads compressed payload blocks. |
| Server sync | opcode `123`, subtype `1` and subtype `0` | Table-list/checksum packets decide stale or missing tables; individual payload packets refresh table data. |
| Payload validation | [UID:000089][MetaTable](by-class/MetaTable.md) | Incoming and cached payloads are decompressed and CRC32-validated before lookup/materialization. |
| Row materialization | [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) | Decoded bytes become row/key/value structures consumed by metadata lookup helpers. |
| Dirty save | `0x005237d0-0x005239fb` | Writer serializes table count, header byte count, header block, payload blocks, and clears the dirty byte after close. |

## Sync Request And Writeback Matrix

| State | Source behavior | Rebuild implication |
| --- | --- | --- |
| Cache missing | Startup proceeds into metadata synchronization and requests needed tables from the server. | Source must tolerate missing `Meta.dat`; packaging should not require a prebuilt local cache. |
| Cached table present and valid | Payload can be decompressed, CRC-checked, materialized, and used by lookup consumers. | Preserve validation before use rather than trusting stale local bytes. |
| Cached table stale or absent from server checksum list | `MetaMan` requests individual table payloads through opcode `123` metadata sync. | Network protocol and cache refresh logic are source behavior; payload contents remain server/resource-derived. |
| Dirty synchronized cache | Writer serializes the loose cache and clears the dirty byte after the write/close sequence. | Writeback is a runtime cache optimization, not a source asset export step. |

## Failure And Refresh Behavior

- A missing or stale cache is not fatal by itself; `MetaMan` can request missing/stale metadata payloads from the server through the sync packet path.
- Cached table payloads are not trusted blindly. [UID:000089][MetaTable](by-class/MetaTable.md) owns the decompress-and-CRC validation path before decoded rows are used.
- The dirty-save path writes the loose cache after synchronization and clears the dirty byte only after the write/close sequence, so the cache file is an optimization for startup/local lookup rather than the authoritative source of metadata.
- Final behavior for malformed headers and partial cache reads is still not documented deeply enough for source-quality error handling; keep final field and exception names open.

## Source Ownership Evidence

| Candidate owner | Evidence | Decision |
| --- | --- | --- |
| [UID:0000LC][MetaMan](by-file/MetaMan.md) | Proposed source tree places loose `Meta.dat` load/save helpers under `metadata/MetaMan.cpp`, and the file page is scored `86/80` with durable ownership refs. | Source owner for the cache file logic. |
| [UID:0000IN][DATFile](by-file/DATFile.md) / archive system | Archive resources flow through packed DAT file managers; `Meta.dat` is opened as a loose local file by MetaMan. | Not the owner. |
| UI consumers such as [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) and [UID:00002X][CollectionPane](by-class/CollectionPane.md) | They query MetaMan lookup APIs after rows are loaded/materialized. | Consumers only. |

## Layout Confidence

| Layer | Confidence | Notes |
| --- | --- | --- |
| File identity and ownership | Strong | UTF-16 `Meta.dat` string xrefs land in loader/writer code owned by MetaMan. |
| Top-level serialization order | Strong | Loader and writer agree on table count, header byte count, header block, and payload block sequence. |
| Compressed payload ownership | Strong | Payloads are stored in MetaTable objects and later decompressed/validated. |
| Decoded row payload shape | Medium-high | [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) and materializer docs establish row/key/value widths, but table-specific column semantics are still open. |
| Outer header secondary fields | Medium-high | The current loose payload proves table names, compressed payload sizes, and zero secondary words for this sample; exact source-level field names and malformed-cache semantics still need loader-vs-writer reconciliation. |

## Scope Boundaries

- Keep packed DAT archive specifications in [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md); `Meta.dat` uses loose-file I/O and should not be folded into `DATFile` ownership.
- Keep post-zlib row/key/value structure in [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) and [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md); this page should only summarize those layers to explain the cache payload role.
- UI pages such as [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) and [UID:00002X][CollectionPane](by-class/CollectionPane.md) consume metadata lookup APIs and should not duplicate `Meta.dat` parsing details.
- Metadata protocol packet naming belongs with [UID:0000LC][MetaMan](by-file/MetaMan.md), [UID:000088][MetaMan](by-class/MetaMan.md), and packet/memory pages. This resource page only records why those packets refresh the loose cache.
- The loose cache file is rebuild-relevant because the client source must preserve load/validate/request/save behavior; it is not a source-controlled static asset unless later packaging evidence proves a shipped seed file.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms `Meta.dat` is a UTF-16 string at `0x0061fadc` with two observed code xrefs: `0x005234ae` in `sub_523470` and `0x005237fa` in `sub_5237D0`.
- Function analysis reports `sub_523470` at `0x00523470` as an `0x350`-byte loader-like routine with one caller, and `sub_5237D0` at `0x005237d0` as an `0x22b`-byte writer-like routine with one caller.
- The loader at `0x00523470` builds a path from the `Meta.dat` string, opens it for read, reads a 4-byte table count, reads a 4-byte header byte count, allocates that header block, parses per-table name/size metadata from the header, then reads each payload block from the file.
- The writer at `0x005237d0` gates on the dirty byte at object offset `+17`, opens `Meta.dat` for write, serializes the table count, header byte count, header block, then each table payload, and clears the dirty byte after closing the handle.
- `0x00524870-0x00524c55` remains the decoded-payload row materialization path referenced by the type pages; this resource page should not assign final column names until that materializer and table-specific consumers are reconciled.

## Decoded Table Payload

After `MetaTable::DecompressAndValidateData` inflates one table payload, [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) parses the decoded bytes into [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md) entries.

Current evidence for the post-zlib payload format is tracked in [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md). The materializer reads a 16-bit row count, a one-byte row-key length, a multibyte row key, a 16-bit value count, and then 16-bit length-prefixed multibyte value strings. Keys and values are converted with `MultiByteToWideChar(0, 0, ...)`.

## Synchronization

The cache is refreshed through [UID:000088][MetaMan](by-class/MetaMan.md) metadata packets:

- opcode `123`, subtype `1`: table list/checksum synchronization;
- opcode `123`, subtype `0`: individual table payload request/response.

Incoming table payloads are stored in [UID:000089][MetaTable](by-class/MetaTable.md), decompressed, CRC32-validated, and later materialized into lookup rows.

## Known Consumers

Consumers do not read `Meta.dat` directly. They call [UID:000088][MetaMan](by-class/MetaMan.md):

- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- resource/image metadata helper code near `0x004d1fa0`
- session/network synchronization code

## Open Questions

- Exact header record fields and order.
- Whether the four zero secondary bytes in the audited `Meta.dat` header are reserved, checksum state, flags, or a currently unused writer field.
- Per-table semantic meaning of decoded row values; the structural decoded payload format has a first-pass page, but table-specific columns remain unnamed.
- Whether table names in shipped files always use UTF-16 and whether payload names are case-sensitive.
- Whether failed CRC validation always triggers a server payload request or can leave a stale local table in specific error paths.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 89 | The page documents identity, owner, loose-file distinction, rebuild/packaging boundary, cache-layer contract, request/writeback states, loader/writer lifecycle, refresh behavior, decoded payload path, consumers, scope boundaries, current loose-file provenance, 32-record header inventory, compressed payload sizes, and zlib payload validation. Completion remains capped by unresolved source names for secondary header fields, malformed-cache behavior, and table-specific decoded value semantics. |
| Confidence | 92 | Ownership, loose-cache lifecycle, layer split, file existence, header size/counts, table names, compressed-size accounting, and zlib payload blocks are strongly supported by fresh `Meta.dat` xrefs plus direct payload parsing. Confidence is capped by unresolved secondary-field names, malformed-cache behavior, and table-specific decoded value semantics. |

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- [UID:0001CB][0x00524630-0x00525914.MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-19 Agent-B009 MetaMan source-quality reconciliation:
  - Score unchanged.
  - Summary/evidence: reconciled the header name-length wording with the writer behavior: current lengths fit in one byte, but the serialized slot advances by two bytes before UTF-16 name bytes. Retained the known big-endian compressed payload size and four zero/reserved secondary bytes while keeping final source field names open.
- Before: page was scored `0/0` despite having a coherent MetaMan cache model.
- Changed to: `COMPLETION:65`, `CONFIDENCE:82`, with direct IDA MCP evidence for the `Meta.dat` string, loader, writer, and remaining layout caveats.
- Evidence: IDA MCP string/xref search for `0x0061fadc` and decompilation of `0x00523470-0x005237c0` / `0x005237d0-0x005239fb`.
- 2026-06-02: Raised to `72/86`, added cache-lifecycle, source-ownership, layout-confidence, and score-rationale sections. Evidence: existing MetaMan file/class pages, proposed source tree, client DAT specifications, materializer/type pages, and IDA-backed loader/writer notes all support MetaMan ownership while preserving the exact header-field caveat.
- 2026-06-07 A002 loose-cache boundary pass:
  - Before: the page documented the loader/writer lifecycle but did not clearly separate the loose cache file, outer header parser/writer, compressed payload blocks, and decoded row/value payload layers.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:88`, added rebuild/packaging boundaries, failure/refresh behavior, scope boundaries, and a current-session IDA-availability caveat.
  - Summary and evidence: [UID:0000LC][MetaMan](by-file/MetaMan.md), [UID:000088][MetaMan](by-class/MetaMan.md), [UID:000089][MetaTable](by-class/MetaTable.md), [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md), [UID:0001CB][0x00524630-0x00525914.MetaTable](by-memory/0x00524630-0x00525914.MetaTable.md), [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md), and [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md) support the loose-cache owner, payload validation path, decoded format split, and remaining outer-header caveat.
- 2026-06-07 A002 cache-contract pass:
  - Before: `COMPLETION:76`, with layer split and lifecycle documented but no explicit cache contract or missing/stale/valid/dirty state matrix.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, with a cache-layer contract, synchronization/writeback matrix, and tighter scope boundaries for metadata protocol and source-asset ownership.
  - Summary and evidence: existing MetaMan, MetaTable, materializer, decoded-payload, and DAT-specification docs support the file-open/header-parse/payload-cache/validation/writeback split; confidence remains unchanged because outer header secondary fields, malformed-cache behavior, and table-specific column semantics are still unresolved.
- 2026-06-14 A003 score refresh: Raised completion/confidence from `78/88` to `85/89` after live IDA MCP reconfirmed the `Meta.dat` literal xrefs into the local cache loader and writer functions and refreshed function sizes; outer header secondary fields, malformed-cache behavior, and table-specific decoded value semantics remain below-final blockers.
- 2026-06-14 A002 loose-payload provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:89`, with loader/writer evidence but no current loose-file payload audit.
  - After: raised to `COMPLETION:89`, `CONFIDENCE:92`, with current `Meta.dat` loose-file provenance, table count/header size, 32 UTF-16 table names, compressed payload sizes that sum to the file payload length, and zlib decompression checks.
  - Evidence: byte-level parsing of `E:\2026\Resources\Read_Only\NexusTK\Meta.dat`; no packed DAT entry named `Meta.dat` was found in the audited `Data` tree.
