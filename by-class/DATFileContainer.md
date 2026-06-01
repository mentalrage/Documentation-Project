*** UID:00003H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATFileContainer

## Status

- Confidence: strong for layout and archive-module placement.
- Likely source file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Current recovered file: `source-3/simroot_v2/class_DATFileContainer.cpp`

## Class Purpose

`DATFileContainer` owns one memory-mapped DAT archive file. It opens the archive, creates a read-only file mapping, maps the view, exposes the entry table, and releases the mapping and file handles in its deleting destructor.

## Layout

| Offset | Current field | Interpreted role |
| --- | --- | --- |
| `0x00` | `vftptr_0x0` | Virtual destructor table. |
| `0x04` | `mbr_0x4` | Win32 file handle. |
| `0x08` | `mbr_0x8` | Win32 file-mapping handle. |
| `0x0c` | `mbr_0xc` | Mapped view base. |
| `0x10` | `mbr_0x10` | Final entry payload boundary from the last 17-byte table row. |
| `0x14` | `mbr_0x14` | Entry count from mapped dword 0. |
| `0x18` | `mbr_0x18` | Entry table pointer at mapped view + 4. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DATFileContainer` | `0x0049be80-0x0049c0c9` | Opens the archive, tries a `..\` fallback path, maps the file, reads entry count/table, and records the final payload boundary. |
| `ScalarDeletingDestructor` | `0x0049d2d0-0x0049d349` | Unmaps the view, closes mapping/file handles, clears fields, and optionally frees the object. |

## Evidence Notes

- Wave3 layout inspection reports a 28-byte object with seven 4-byte fields.
- Generated source and IDA evidence show a single mapped archive, despite the current Wave3 class summary saying "multiple DAT archive files".
- IDA MCP confirms `0x0049be80` as a real function with size `0x249` and `0x0049d2d0` with size `0x79`.
- IDA decompilation previously confirmed offset `0x10` is loaded from `entryTable + (entryCount - 1) * 17`, which matches a final boundary/sentinel row.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/86`.
  - Summary/evidence: mapped-file responsibility, full field layout, constructor/destructor ranges, archive-entry boundary evidence, and manager ownership are documented; remaining work is mostly final original field names.
