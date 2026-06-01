*** UID:0001V6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MetaTableDecodedPayload

## Status

- Kind: decoded metadata table payload format.
- Owner: [UID:000089][MetaTable](by-class/MetaTable.md) / [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- Confidence: medium-high for field order visible in the materializer; medium for final semantic names.
- Evidence basis: IDA MCP decompilation of [UID:0001CC][0x00524870-0x00524c54.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c54.MetaTableMaterializeRows.md) on 2026-05-25. `wave3.py` was not executed for this pass.

## Purpose

After `MetaTable::DecompressAndValidateData` inflates and CRC-checks a compressed table payload, `MetaTable::MaterializeRowsIfNeeded` parses the decoded bytes into a row tree. This page tracks that decoded byte format.

## Observed Format

```text
MetaTableDecodedPayload
  uint16 rowCount
  MetaTableDecodedRow rows[rowCount]

MetaTableDecodedRow
  uint8 keyByteLength
  char[keyByteLength] keyBytes
  uint16 valueCount
  MetaTableDecodedValue values[valueCount]

MetaTableDecodedValue
  uint16 valueByteLength
  char[valueByteLength] valueBytes
```

Current evidence shows both row keys and values converted with:

```text
MultiByteToWideChar(0, 0, bytes, byteLength, wideBuffer, 0x8000)
```

That is code page `CP_ACP` (`0`), not a UTF-8 code page constant. Treat decoded strings as ANSI/multibyte source strings until a table sample proves otherwise.

## Parser Evidence

- `0x00524870` reads the first field with the 16-bit helper at `0x00575480`/`sub_575480` and then starts row parsing at offset `2`.
- Each row key length is loaded as an unsigned byte from the current offset, followed by that many bytes copied into a temporary 32 KiB multibyte stack buffer.
- Each row's value count is read as a 16-bit value immediately after the row key bytes.
- Each value length is read as a 16-bit value, followed by that many bytes copied and converted to a temporary wide buffer.
- Values are appended to the row node's `SimpleUString` vector; rows are keyed by the converted row key.

2026-05-31 IDA MCP recheck confirms the parser sequence. `sub_524870` still has size `0x3e5`, reads `rowCount` from `this[2]`, starts the row cursor at byte offset `2`, reads the row-key byte length, copies key/value byte spans into a 32 KiB multibyte stack buffer, converts both keys and values through `MultiByteToWideChar(0, 0, ...)`, reads each value count and value byte length through the 16-bit helper, inserts or finds the row node, appends `SimpleUString` values, frees `this[2]`, clears `this[2]`/`this[3]`, and sets the loaded flag at byte offset `+0x18`.

## Relationship To Meta.dat

This is the decompressed per-table payload, not the outer `Meta.dat` file header. `Meta.dat` stores table names, payload sizes/checksums, and compressed payload blocks. `MetaTableDecodedPayload` describes the data after zlib decompression.

## Open Questions

- Whether the one-byte row-key length is always sufficient for all shipped table names, or whether table producers impose a 255-byte row-key limit.
- Exact semantic names for value positions in known tables such as `Collections` and `GroupNames`.
- Whether the server and local cache always encode strings in the active Windows ANSI code page or whether the observed `CP_ACP` conversion is only a client-side fallback.

## Cross-References

- [UID:0001CC][0x00524870-0x00524c54.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c54.MetaTableMaterializeRows.md)
- [UID:0001V7][MetaTableRowNode](by-type/by-struct/MetaTableRowNode.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001RH][meta-dat-metadata-cache](by-resource/meta-dat-metadata-cache.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `78`, confidence `86`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked `0x00524870` on 2026-05-31 and confirms the decoded row/value field order, ANSI-to-wide conversion path, row-node insertion, value append behavior, decoded-buffer free, and loaded flag update. Scores remain below `95` because actual shipped table schemas and final semantic names for decoded value positions are not exhaustively mapped.
