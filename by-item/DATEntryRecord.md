*** UID:0000UC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DAT Entry Record

## Status

- Confidence: strong for observed in-memory/mapped-table layout, medium for exact on-disk naming.
- Current owner hypothesis: shared archive declaration consumed by [UID:0000IN][DATFile](by-file/DATFile.md) and populated/indexed through [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
- Autogen parent: [UID:0000IN][DATFile](by-file/DATFile.md) because that validated archive reader file already records the 17-byte record dependency.
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

## Current Archive Split

| Owner / page | Relationship to this record | Reconstruction handling |
| --- | --- | --- |
| [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Owns `DATFileContainer`, archive mapping, entry-count/table pointers, uppercase-name indexing, `_DATFileMgr::LoadDATFileIndex`, and `HasDATEntry`. | Manager code observes and indexes the mapped records, but this item should not become a manager-only private struct because `DATFile` readers dereference the same layout directly. |
| [UID:0000IN][DATFile](by-file/DATFile.md) | Owns per-entry stream readers, `Open`, `OpenByIndex`, payload-size calculation, `Read`, `LoadDatFileBuffer`, and `ParseEntries`. | Current autogen parent stays here because the source-facing `DATEntryRecord` declaration is needed by the reader API and the `DATFile` page already documents the dependency. |
| [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) | Memory aggregate for `DATFile` methods that open entries and compute payload size from the next 17-byte row. | Confirms this is not merely metadata; the stream reader's runtime behavior depends on the stride and next-offset convention. |
| [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md) | Memory aggregate for container construction and manager indexing. | Confirms the count/table pointer setup and final-offset cache live with the manager/container implementation. |
| [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md) | Format-level DAT notes. | Keep higher-level file-format naming and resource-family questions there; keep this page focused on the exact 17-byte record consumed by code. |

## Reconstruction Decision

Keep `RECONSTRUCTABLE:TRUE` because this is a source-level archive record declaration: the rebuilt reader/manager code needs an explicit 4-byte payload offset plus 13-byte name layout, even though the exact mapped bytes come from DAT files at runtime.

Do not emit final C++ yet. The final declaration still needs source-quality answers for packed-struct spelling, whether the final row is a sentinel or a named terminal entry, whether the 13-byte name field is always null-terminated, and whether the original source treated the last offset as a synthetic record or a container-level cached boundary.

## Open Questions

- Confirm whether the final entry-table row is always an empty-name sentinel, or whether any valid named entry can occupy the last row.
- Confirm maximum entry-name length and whether names are always null-terminated inside the 13-byte field.
- Confirm whether all payloads are raw bytes or whether some resource families add format-specific headers after DAT lookup.

## Cross-References

- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000IN][DATFile](by-file/DATFile.md).
  - Before: the DAT entry-record layout was documented but unclassified in autogen coverage.
  - After: it is marked as a source-level archive record declaration needed by the DAT reader layer; C++ remains blank because final field/type names and sentinel-row semantics are not at the 95/95 final-code bar.
  - Evidence: the validated [UID:0000IN][DATFile](by-file/DATFile.md) page explicitly depends on this 17-byte layout, while this page records IDA-backed `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex` use of the mapped table.

- 2026-05-30: Grading changed from `0/0` to `76/84`.
  - Before: page documented observed mapped DAT entry layout, evidence, and open questions but remained unevaluated.
  - After: score reflects documented in-memory table structure, 17-byte record stride, next-record size derivation, sentinel/final-offset interpretation, and reader/builder evidence, with lower completion for unresolved on-disk naming and final-row semantics.
  - Evidence: IDA review ties `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex` to the mapped count/table layout and next-offset size calculation.
- 2026-06-07 A009: Raised completion/confidence from `76/84` to `80/86`.
  - Before: the page named the layout and immediate evidence but still described ownership as a broad archive hypothesis.
  - After: documented the current DATFile/DATFileMgr split, reconstruction handling, exact memory/file-level supporting pages, and why C++ remains blank despite `RECONSTRUCTABLE:TRUE`.
  - Evidence: existing DATFile and DATFileMgr pages now separately document reader payload-size use, manager/container mapping and indexing, and the shared 17-byte layout dependency.
