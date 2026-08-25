*** UID:0000UC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DATEntryRecord is declared only in DATFileMgr.h; no standalone CPP definition is required.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma pack(push, 1)
struct DATEntryRecord
{
    unsigned int startOffset;
    char name[13];
};
#pragma pack(pop)

typedef char DATEntryRecordSizeMustBe0x11[
    sizeof(DATEntryRecord) == 0x11 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DAT Entry Record

## 2026-08-18 Source Declaration Closure

The exact source record is emitted in `DATFileMgr.h` before the mapped-container declaration. It is packed to one-byte alignment, has `unsigned int startOffset` at `+0x00`, `char name[13]` at `+0x04`, and total size `0x11`. `DATFileContainer` maps rows directly, `_DATFileMgr::LoadDATFileIndex` consumes names, and `DATFile::Open`/`OpenByIndex` compute payload length from the next row's `startOffset`. The final row supplies a payload boundary; its name bytes are unused but are not guaranteed zero.

## Status

- Confidence: strong for observed in-memory/mapped-table layout and current-package DAT table evidence, medium for exact source declaration spelling.
- Current owner hypothesis: shared archive declaration consumed by [UID:0000IN][DATFile](by-file/DATFile.md) and populated/indexed through [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
- Owner/emitter: [UID:0000IN][DATFile](by-file/DATFile.md) because that validated archive reader file already records the 17-byte record dependency.
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

IDA MCP review of `DATFileContainer::DATFileContainer` on 2026-05-22 shows the container caches `*(uint32*)(entryTable + (entryCount - 1) * 17)` at container offset `0x10`. The final entry-table row supplies the archive's last payload boundary. Current package evidence shows that this row is usually empty-named but not guaranteed to have zeroed name bytes, so the source-safe claim is boundary-row semantics rather than "always empty sentinel" semantics.

## Evidence

- `DATFileContainer::DATFileContainer` sets `m_entryCount = mappedWords[0]` and `m_entryTable = mappedWords + 1`.
- `DATFileContainer::DATFileContainer` sets `m_lastEntryOffset` from the first dword of the final 17-byte row: `entryTable + (entryCount - 1) * 17`.
- `_DATFileMgr::LoadDATFileIndex` uses `recordName = entryTable + entryIndex * 17 + 4`, so the 13 bytes after the first dword are the ANSI entry name.
- `DATFile::Open` and `DATFile::OpenByIndex` read the current record's first dword as `startOffset`, then read the dword at `record + 17` as the next payload offset.
- `DATFile::Read` copies from archive data base at container offset `0x0c` plus the current absolute data offset.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed the supporting function starts and sizes: `DATFileContainer::DATFileContainer` at `0x0049be80` size `0x249`, `DATFile::Open` at `0x0049c180` size `0xbb`, `DATFile::OpenByIndex` at `0x0049c720` size `0x2b`, and `_DATFileMgr::LoadDATFileIndex` at `0x0049c800` size `0x2c4`.
- The same 2026-06-14 decompile pass reconfirmed `DATFile::Open` and `DATFile::OpenByIndex` compute `record = entryTable + 17 * index` and `size = *(record + 17) - *record`; `17 == 0x11` was verified with `int_convert.py`.
- The container constructor decompile still caches the first dword of the final table row at container offset `+0x10`, while `_DATFileMgr::LoadDATFileIndex` remains the index builder that walks mapped rows at the same 17-byte stride.
- 2026-06-16 live IDA MCP session `b001_selflookpane_0001H7_20260616` (`NexusTK.exe`, image base `0x00400000`, Hex-Rays ready) reconfirmed the same function starts and sizes: `0x0049be80` size `0x249`, `0x0049c180` size `0xbb`, `0x0049c720` size `0x2b`, and `0x0049c800` size `0x2c4`.
- 2026-06-16 decompilation of `DATFileContainer::DATFileContainer` shows the mapped first dword copied to the container entry count field, `mappedView + 4` copied to the entry-table pointer, and the cached final boundary loaded from the first dword of `entryTable + (entryCount - 1) * 17`.
- 2026-06-16 decompilation of `_DATFileMgr::LoadDATFileIndex` shows it iterates while `entryIndex < entryCount`, reads each name from `entryTable + entryIndex * 17 + 4`, only creates index nodes after the temporary string is nonempty and not already found, then advances by `17`. This confirms empty rows are skipped by the name index rather than becoming valid named entries.
- 2026-06-16 A002 package audit found 250 current DAT files under `E:\2026\Resources\Read_Only\NexusTK\Data`; all 250 parsed with a valid count/table, monotonic offsets, offsets within the file, and zero zero-length intervals. Table row counts range from 2 to 260.
- The same package audit found 1,038 non-empty row names, all null-terminated within the 13-byte field. This supports `char name[13]` as a bounded C-string field for exposed rows in the current package.
- Final boundary-row audit: 247 of 250 final rows have an empty name field, while `baramst.dat`, `head0.dat`, and `mus004.dat` have nonzero bytes in the final row's 13-byte name area. This proves the final row's name bytes are not a reliable exposed-entry name field even though the first dword is the final payload boundary.

## Current Archive Split

| Owner / page | Relationship to this record | Reconstruction handling |
| --- | --- | --- |
| [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | Owns `DATFileContainer`, archive mapping, entry-count/table pointers, uppercase-name indexing, `_DATFileMgr::LoadDATFileIndex`, and `HasDATEntry`. | Manager code observes and indexes the mapped records, but this item should not become a manager-only private struct because `DATFile` readers dereference the same layout directly. |
| [UID:0000IN][DATFile](by-file/DATFile.md) | Owns per-entry stream readers, `Open`, `OpenByIndex`, payload-size calculation, `Read`, `LoadDatFileBuffer`, and the separate `DecodeTableValue` scalar path. | Current owner/emitter stays here because the source-facing `DATEntryRecord` declaration is needed by the reader API. `DecodeTableValue` does not consume this record layout. |
| [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) | Memory aggregate for `DATFile` methods that open entries and compute payload size from the next 17-byte row. | Confirms this is not merely metadata; the stream reader's runtime behavior depends on the stride and next-offset convention. |
| [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md) | Memory aggregate for container construction and manager indexing. | Confirms the count/table pointer setup and final-offset cache live with the manager/container implementation. |
| [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md) | Format-level DAT notes. | Keep higher-level file-format naming and resource-family questions there; keep this page focused on the exact 17-byte record consumed by code. |

## Encoded Scalar Non-Relationship

The eight-byte unit handled by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) is not a `DATEntryRecord` and must not be modeled as an alternate form of this struct:

- This page's 17-byte row belongs to the outer mapped DAT archive directory: one four-byte payload start offset followed by a 13-byte ANSI name area.
- `DATFile::Open` and `OpenByIndex` consume these rows and use the next row's offset to derive payload size.
- Exact methods [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) and [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md) operate later inside an already opened payload. Each reads one unrelated eight-byte scalar unit into a local buffer and calls UID00013W.
- UID00013W has no 17-byte stride, entry name, next-record offset, archive directory pointer, sentinel row, allocation, or record container.
- Historical `ParseEntries` / `ReadAllEntries` wording caused the false association. Source-facing names `DecodeTableValue`, `ReadEncodedTableInt`, and `ReadEncodedTableFloat` make the layer distinction explicit.

## Reconstruction Decision

Keep `RECONSTRUCTABLE:TRUE` because this is a source-level archive record declaration: the rebuilt reader/manager code needs an explicit 4-byte payload offset plus 13-byte name layout, even though the exact mapped bytes come from DAT files at runtime.

Do not emit final C++ yet. The page now clears the minimum score/emitter gate, but the final declaration still needs source-quality answers for packed-struct spelling and whether the original source treated the last offset as a synthetic record, a container-level cached boundary, or a normal table row with unused trailing bytes.

## 2026-06-16 Blocker Investigation

- Field/type naming: IDA proves a packed `uint32 + 13-byte char name` row, but no symbol, struct type, or source string recovered the original declaration spelling. `DATEntryRecord` remains a documentation name, not a recovered source type name.
- Sentinel/final row: `DATFileContainer` caches the last row's first dword as the final payload boundary, while `_DATFileMgr::LoadDATFileIndex` walks rows at the same 17-byte stride. The current package audit resolves the earlier empty-sentinel question: most final rows are empty-named, but three current archives contain nonzero final-row name bytes, so the final row should be documented as a boundary row with unused/unreliable name bytes rather than as an always-empty sentinel.
- Name termination: `_DATFileMgr::LoadDATFileIndex` treats the bytes at `record + 4` as an ANSI string source. The current package audit found all 1,038 non-empty exposed row names null-terminated within the 13-byte field; keep the field as `char name[13]` and avoid claiming the final boundary row's padding bytes form a valid name.
- Source placement: owner/emitter remain [UID:0000IN][DATFile](by-file/DATFile.md) because `DATFile::Open`/`OpenByIndex` directly consume the layout for payload sizing; [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) remains a co-owner of mapping/index behavior, not the sole declaration owner.

## Historical Open Questions Resolved By Package And Code Evidence

- Confirm whether older or alternate DAT package distributions follow the same null-terminated exposed-name and mostly-empty final boundary-row pattern as the audited 2026 package.
- Confirm the exact original struct/type spelling and whether the source declared the boundary row with the same record type or handled it as a container-level offset convention.
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
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md)
- [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000IN][DATFile](by-file/DATFile.md).
  - Before: the DAT entry-record layout was documented but unclassified in autogen coverage.
  - After: it is marked as a source-level archive record declaration needed by the DAT reader layer; C++ remains blank because final field/type names and sentinel-row semantics are not source-quality.
  - Evidence: the validated [UID:0000IN][DATFile](by-file/DATFile.md) page explicitly depends on this 17-byte layout, while this page records IDA-backed `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex` use of the mapped table.

- 2026-05-30: Grading changed from `0/0` to `76/84`.
  - Before: page documented observed mapped DAT entry layout, evidence, and open questions but remained unevaluated.
  - After: score reflects documented in-memory table structure, 17-byte record stride, next-record size derivation, sentinel/final-offset interpretation, and reader/builder evidence, with lower completion for unresolved on-disk naming and final-row semantics.
  - Evidence: IDA review ties `DATFileContainer`, `_DATFileMgr::LoadDATFileIndex`, `DATFile::Open`, and `DATFile::OpenByIndex` to the mapped count/table layout and next-offset size calculation.
- 2026-06-07 A009: Raised completion/confidence from `76/84` to `80/86`.
  - Before: the page named the layout and immediate evidence but still described ownership as a broad archive hypothesis.
  - After: documented the current DATFile/DATFileMgr split, reconstruction handling, exact memory/file-level supporting pages, and why C++ remains blank despite `RECONSTRUCTABLE:TRUE`.
  - Evidence: existing DATFile and DATFileMgr pages now separately document reader payload-size use, manager/container mapping and indexing, and the shared 17-byte layout dependency.
- 2026-06-14 A001: Raised completion/confidence from `80/86` to `85/88`.
  - Before: the page relied on earlier IDA notes and support-page synchronization for the 17-byte table layout.
  - After: added a current live IDA MCP refresh for the container, reader, by-index reader, and manager-index builder functions; replaced stale autogen-parent wording with owner/emitter terminology.
  - Evidence: `lookup_funcs`, `analyze_function`, and targeted decompile checks reconfirm the 17-byte stride, next-row size derivation, final-row boundary cache, and DATFile/DATFileMgr split. Final C++ remains blank because sentinel/name-field semantics and source declaration spelling remain below source-quality evidence.
- 2026-06-16 A002: Raised completion/confidence from `85/88` to `86/89`.
  - Before: the page had strong layout evidence but did not record the latest code-side loop details or the attempted resource-file check for remaining archive-format blockers.
  - After: added current IDA MCP lookup/decompile evidence for the container/index/readers, documented the all-row index walk with empty-name skipping, and recorded that no local `.DAT` files were present under the workspace for physical archive inspection.
  - Evidence: live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed the exact supporting function sizes and decompile behavior; the remaining sentinel/name-termination questions are kept as real blockers because code evidence and available local files do not close them safely.
- 2026-06-16 A002 package-evidence follow-up:
  - Before: `86/89`.
  - After: `88/91`.
  - Summary/evidence: widened the physical DAT check from the workspace to the read-only current package at `E:\2026\Resources\Read_Only\NexusTK\Data`. All 250 DAT archives parsed cleanly with monotonic bounded offsets, all 1,038 non-empty exposed names were null-terminated within 13 bytes, and three final boundary rows contained nonzero name-area bytes. The remaining blocker is original source declaration spelling, not the current package's row semantics.
- 2026-07-12 B001 UID00013W callback, scores/metadata/C++ unchanged:
  - Added the explicit distinction between this outer 17-byte archive directory row and UID00013W's inner eight-byte encoded scalar unit.
  - Linked exact typed wrappers UID0004IY/UID0004IZ and historicalized the misleading `ParseEntries`/`ReadAllEntries` association.
  - Preserved all record layout, package, boundary-row, name-termination, ownership, and unresolved declaration-spelling evidence.
