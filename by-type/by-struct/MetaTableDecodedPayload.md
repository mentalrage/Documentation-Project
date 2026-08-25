*** UID:0001V6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000089 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000089 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MetaTableDecodedPayload is a variable-length decoded byte format parsed by
// MetaTable::MaterializeRowsIfNeeded. It is not emitted as a standalone C++
// struct: the source parser reads uint16be row/value fields, uint8 key lengths,
// and variable key/value byte spans directly from MetaTable::m_keyData.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MetaTableDecodedPayload

## Status

- Kind: decoded metadata table payload format.
- Owner: [UID:000089][MetaTable](by-class/MetaTable.md) / [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- Confidence: medium-high for field order visible in the materializer; medium for final semantic names.
- Assignment: attached to [UID:000089][MetaTable](by-class/MetaTable.md). The payload type is `87/90`, the direct class parent is `90/90`, and the source file [UID:0000LC][MetaMan](by-file/MetaMan.md) is `91/90`, so the strict child/direct-parent `85/85` gate is satisfied.
- Evidence basis: IDA MCP decompilation of [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) on 2026-05-25 and live boundary/callsite recheck on 2026-06-03. `wave3.py` was not executed for this pass.

## Purpose

After `MetaTable::DecompressAndValidateData` inflates and CRC-checks a compressed table payload, `MetaTable::MaterializeRowsIfNeeded` parses the decoded bytes into a row tree. This page tracks that decoded byte format.

The materializer's caller-provided `const wchar_t *tableNameHint` is ABI-retained but unused by the callee and does not change the decoded payload layout.

## Formal No-Standalone-Struct Disposition

The 2026-07-02 Agent-B007 UID0000LC implementation callback replaces the stale empty emitter with a formal no-standalone-struct marker. The decoded payload is source-relevant, but it is a variable-length byte stream consumed directly from `MetaTable::m_keyData`, not a fixed C++ struct declaration.

The source-facing parser remains [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md), which reads `uint16be` row/value fields through `PacketBufferReadUInt16BE`, reads `uint8` row-key lengths, copies variable key/value byte spans, converts through `MultiByteToWideChar(0,0,...)`, appends values through `m_rows[rowKey].push_back(valueText)`, frees/clears `m_keyData`, and sets `m_isLoaded`. This page preserves the format contract and table-specific semantic caveats without duplicating parser source.

## Observed Format

```text
MetaTableDecodedPayload
  uint16be rowCount
  MetaTableDecodedRow rows[rowCount]

MetaTableDecodedRow
  uint8 keyByteLength
  char[keyByteLength] keyBytes
  uint16be valueCount
  MetaTableDecodedValue values[valueCount]

MetaTableDecodedValue
  uint16be valueByteLength
  char[valueByteLength] valueBytes
```

Current evidence shows both row keys and values converted with:

```text
MultiByteToWideChar(0, 0, bytes, byteLength, wideBuffer, 0x8000)
```

That is code page `CP_ACP` (`0`), not a UTF-8 code page constant. Treat decoded strings as ANSI/multibyte source strings until a table sample proves otherwise.

## Parser Evidence

- `0x00524870` reads the first field with the big-endian/network-order 16-bit helper `PacketBufferReadUInt16BE` at `0x00575480`/`sub_575480` and then starts row parsing at offset `2`.
- Each row key length is loaded as an unsigned byte from the current offset, followed by that many bytes copied into a temporary 32 KiB multibyte stack buffer.
- Each row's value count is read as a big-endian/network-order 16-bit value immediately after the row key bytes.
- Each value length is read as a big-endian/network-order 16-bit value, followed by that many bytes copied and converted to a temporary wide buffer.
- Values are appended to the row node's `SimpleUString` vector; rows are keyed by the converted row key.

2026-05-31 IDA MCP recheck confirms the parser sequence. `sub_524870` still has size `0x3e5`, reads `rowCount` from `this[2]`, starts the row cursor at byte offset `2`, reads the row-key byte length, copies key/value byte spans into a 32 KiB multibyte stack buffer, converts both keys and values through `MultiByteToWideChar(0, 0, ...)`, reads each value count and value byte length through the 16-bit helper, inserts or finds the row node, appends `SimpleUString` values, frees `this[2]`, clears `this[2]`/`this[3]`, and sets the loaded flag at byte offset `+0x18`.

2026-06-11 read-only IDA MCP reconfirmed the parse callsites:

- `0x00524918`, `0x005249c7`, and `0x005249f6` call the 16-bit helper `sub_575480` for the row count, row value count, and value byte length.
- `0x00524991` and `0x00524a55` call `MultiByteToWideChar` for row keys and values.
- `0x00524b06`, `0x00524b1a`, `0x00524b36`, and `0x00524b45` call row-node allocation, insertion, key/value copy, and value-vector append helpers.
- `0x00524b91` frees the decoded payload buffer after materialization, and `0x00524c55-0x00524c60` is `0xcc` padding before `MetaTable::ResetData`.

2026-06-27 Agent-B014 amendment analyzed `sub_575480`/`PacketBufferReadUInt16BE` and corrected the generic 16-bit fields from endian-neutral wording to big-endian/network order. The helper returns `a1[1] + (a1[0] << 8)`, so `rowCount`, `valueCount`, and `valueByteLength` are all `uint16be` fields. The one-byte `keyByteLength`, key/value byte spans, `CP_ACP`/`MultiByteToWideChar(0,0,...)` conversions, row-map append handoff, decoded-buffer free/clear, and `m_isLoaded` set are materializer behavior, not table-specific value semantics.

## Assignment Gate

This struct page belongs to [UID:000089][MetaTable](by-class/MetaTable.md), not directly to the resource page or file root. It describes the in-memory decoded payload consumed by `MetaTable::MaterializeRowsIfNeeded`; [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md) documents the outer loose cache layer, and [UID:0000LC][MetaMan](by-file/MetaMan.md) owns the source file. The target and its direct class parent now both clear the strict `85/85` gate.

## Score Rationale

Completion is `87` because the page now records the full decoded field order, big-endian width of each count/length field, cursor progression, ANSI-to-wide conversion behavior, row-node/value-vector handoff, decoded-buffer ownership after materialization, parent routing, layer boundary versus outer `Meta.dat`, and the formal no-standalone-struct output disposition.

Confidence is `90` because the parser callsites, materializer boundary, helper calls, buffer free, parent ownership, and B014 big-endian correction are mutually consistent with the formal variable-format disposition. Confidence remains below final-audit level because shipped table-specific value semantics and final column names are still unresolved.

## Relationship To Meta.dat

This is the decompressed per-table payload, not the outer `Meta.dat` file header. `Meta.dat` stores table names, payload sizes/checksums, and compressed payload blocks. `MetaTableDecodedPayload` describes the data after zlib decompression.

## Open Questions

- Whether the one-byte row-key length is always sufficient for all shipped table names, or whether table producers impose a 255-byte row-key limit.
- Exact semantic names for value positions in known tables such as `Collections` and `GroupNames`.
- Whether the server and local cache always encode strings in the active Windows ANSI code page or whether the observed `CP_ACP` conversion is only a client-side fallback.

## Cross-References

- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-07-02 Agent-B007 UID0000LC implementation callback:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`.
  - Summary/evidence: inserted the formal variable-format no-standalone-struct marker, preserving the big-endian `rowCount`, `valueCount`, and `valueByteLength` fields, one-byte key length, variable key/value byte spans, `CP_ACP` conversion path, row-map append handoff, and the boundary between this decoded payload and the outer loose `Meta.dat` cache layer.
- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `78`, confidence `86`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked `0x00524870` on 2026-05-31 and confirms the decoded row/value field order, ANSI-to-wide conversion path, row-node insertion, value append behavior, decoded-buffer free, and loaded flag update. Scores remain below `95` because actual shipped table schemas and final semantic names for decoded value positions are not exhaustively mapped.
- 2026-06-11 A004 strict parent-gate refresh:
  - What existed before: `78/86`, unassigned, with the decoded format known but the direct [UID:000089][MetaTable](by-class/MetaTable.md) parent below the strict gate.
  - Changed to: `86/89`, `AUTOGEN_PARENT_UID:000089`.
  - Summary/evidence: read-only IDA MCP reconfirmed the materializer boundary, 16-bit count/length helper callsites, one-byte key-length path, `MultiByteToWideChar` conversion calls, row-node insertion/value append helper calls, decoded-buffer free, and reset-function padding boundary. [UID:000089][MetaTable](by-class/MetaTable.md) and [UID:0000LC][MetaMan](by-file/MetaMan.md) were refreshed to satisfy the strict parent gate.
- 2026-06-27 Agent-B014 materializer implementation:
  - Score unchanged.
  - Summary/evidence: incorporated the accepted [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) amendment by marking `rowCount`, `valueCount`, and `valueByteLength` as big-endian/network-order `PacketBufferReadUInt16BE` fields, preserving the one-byte key length and generic key/value byte spans, and clarifying that `tableNameHint` does not affect the decoded payload layout. Table-specific value semantics remain open.
