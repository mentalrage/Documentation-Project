*** UID:0000UC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DAT Entry Record

## Status

- Confidence: strong for observed in-memory/mapped-table layout, medium for exact on-disk naming.
- Current owner hypothesis: [UID:0000IM][DATArchive](by-file/DATArchive.md)
- Primary readers/builders: `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, `DATFile::OpenByIndex`

## Observed Layout

`DATFileContainer` maps a DAT file read-only. The mapped view starts with a 32-bit entry count, and the entry table begins immediately after that count.

```text
mapped DAT view
  +0x00  uint32 entryCount
  +0x04  DATEntryRecord records[entryCount]
```

Each observed entry record is 17 bytes:

```text
DATEntryRecord
  +0x00  uint32 startOffset
  +0x04  char name[13]       // ANSI, uppercased by index loader
```

`DATFile::Open` and `DATFile::OpenByIndex` compute an entry payload size by subtracting this record's `startOffset` from the next record's `startOffset` at `record + 0x11`. This means the "end offset" is not a second field inside the same 17-byte record; it is the next record start offset.

IDA MCP review of `DATFileContainer::DATFileContainer` on 2026-05-22 shows the container caches `*(uint32*)(entryTable + (entryCount - 1) * 17)` at container offset `0x10`. Because `_DATFileMgr::LoadDATFileIndex` skips empty names, the strongest current interpretation is that the final entry-table row is a sentinel/final-payload-offset row, likely with an empty name. At minimum, the final row's first dword supplies the archive's last payload boundary.

## Evidence

- `DATFileContainer::DATFileContainer` sets `m_entryCount = mappedWords[0]` and `m_entryTable = mappedWords + 1`.
- `DATFileContainer::DATFileContainer` sets `m_lastEntryOffset` from the first dword of the final 17-byte row: `entryTable + (entryCount - 1) * 17`.
- `_DATFileMgr::LoadDATFileIndex` uses `recordName = entryTable + entryIndex * 17 + 4`, so the 13 bytes after the first dword are the ANSI entry name.
- `DATFile::Open` and `DATFile::OpenByIndex` read the current record's first dword as `startOffset`, then read the dword at `record + 17` as the next payload offset.
- `DATFile::Read` copies from archive data base at container offset `0x0c` plus the current absolute data offset.

## Open Questions

- Confirm whether the final entry-table row is always an empty-name sentinel, or whether any valid named entry can occupy the last row.
- Confirm maximum entry-name length and whether names are always null-terminated inside the 13-byte field.
- Confirm whether all payloads are raw bytes or whether some resource families add format-specific headers after DAT lookup.

## Cross-References

- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `76/84`.
  - Before: page documented observed mapped DAT entry layout, evidence, and open questions but remained unevaluated.
  - After: score reflects documented in-memory table structure, 17-byte record stride, next-record size derivation, sentinel/final-offset interpretation, and reader/builder evidence, with lower completion for unresolved on-disk naming and final-row semantics.
  - Evidence: IDA review ties `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex` to the mapped count/table layout and next-offset size calculation.
