*** UID:0001RH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Meta.dat Metadata Cache

## Status

- Resource kind: loose local metadata cache file.
- Owner module: [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for ownership, cache lifecycle, and high-level loader/writer behavior; medium for exact outer header record field names.

## Observed Role

`Meta.dat` stores local copies of server-provided metadata tables. [UID:000088][MetaMan](by-class/MetaMan.md) loads this file during metadata synchronization startup, validates table payloads against the server's checksum list, requests stale or missing payloads, and writes the file again after successful synchronization.

This file is not the same thing as the client's packed DAT archive system. It is a loose file opened directly by `MetaMan`, while archive-backed resources such as `str.res`, `.PAL`, `.EPF`, `.EPD`, audio, and image assets flow through [UID:0000IN][DATFile](by-file/DATFile.md).

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

The exact header record layout is still open. Do not commit final field names for the secondary per-table fields until the writer at `0x005237d0` and loader at `0x00523470` are reconciled field by field.

## Cache Lifecycle

| Phase | Owner/path | Evidence |
| --- | --- | --- |
| Startup local load | [UID:000088][MetaMan](by-class/MetaMan.md) / [UID:0000LC][MetaMan](by-file/MetaMan.md) | `MetaMan::LoadMetaDatAndRequestSync` calls the local loader before sending the metadata synchronization request. |
| Local cache parse | `0x00523470-0x005237c0` | Opens loose `Meta.dat`, reads table count and header byte count, builds per-table metadata, creates [UID:000089][MetaTable](by-class/MetaTable.md) objects, and reads compressed payload blocks. |
| Server sync | opcode `123`, subtype `1` and subtype `0` | Table-list/checksum packets decide stale or missing tables; individual payload packets refresh table data. |
| Payload validation | [UID:000089][MetaTable](by-class/MetaTable.md) | Incoming and cached payloads are decompressed and CRC32-validated before lookup/materialization. |
| Row materialization | [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) | Decoded bytes become row/key/value structures consumed by metadata lookup helpers. |
| Dirty save | `0x005237d0-0x005239fb` | Writer serializes table count, header byte count, header block, payload blocks, and clears the dirty byte after close. |

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
| Outer header secondary fields | Medium | Table name and payload size behavior are clear; exact order/meaning of checksum/reserved fields still needs loader-vs-writer reconciliation. |

## IDA MCP Evidence

- `Meta.dat` is a UTF-16 string at `0x0061fadc`; IDA xrefs land in `0x00523470-0x005237c0` and `0x005237d0-0x005239fb`.
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
- Per-table semantic meaning of decoded row values; the structural decoded payload format has a first-pass page, but table-specific columns remain unnamed.
- Whether table names in shipped files always use UTF-16 and whether payload names are case-sensitive.
- Whether failed CRC validation always triggers a server payload request or can leave a stale local table in specific error paths.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 72 | The page now documents identity, owner, loose-file distinction, loader/writer lifecycle, sync behavior, decoded payload path, consumers, and remaining layout gaps. |
| Confidence | 86 | Ownership and lifecycle are strongly supported by IDA-backed MetaMan docs and source-structure notes; confidence is capped by unresolved outer header secondary fields and table-specific decoded value semantics. |

## Cross-References

- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000088][MetaMan](by-class/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md)
- [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Before: page was scored `0/0` despite having a coherent MetaMan cache model.
- Changed to: `COMPLETION:65`, `CONFIDENCE:82`, with direct IDA MCP evidence for the `Meta.dat` string, loader, writer, and remaining layout caveats.
- Evidence: IDA MCP string/xref search for `0x0061fadc` and decompilation of `0x00523470-0x005237c0` / `0x005237d0-0x005239fb`.
- 2026-06-02: Raised to `72/86`, added cache-lifecycle, source-ownership, layout-confidence, and score-rationale sections. Evidence: existing MetaMan file/class pages, proposed source tree, client DAT specifications, materializer/type pages, and IDA-backed loader/writer notes all support MetaMan ownership while preserving the exact header-field caveat.
