*** UID:0000IN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DATFile

## Status

- Confidence: strong for `DATFile.cpp` ownership and for `ParseEntries` as a private/static-style helper in that module.
- Proposed module: `NexusTK/archive/DATFile.cpp`
- Current recovered files: `source-3/simroot_v2/class_DATFile.cpp` plus helper files for `LoadDatFileBuffer_004BB120` and `ParseEntries_004A5E60`.
- Evidence basis: Wave3 class summaries and missing-ref checks, generated `simroot_v2` source, existing DAT format notes, and targeted IDA MCP function/caller/callee/decompile checks through 2026-05-25.
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## Proposed Contents

This file should own the per-entry stream reader and the small helpers that treat a DAT-backed resource as a normal input buffer.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003G][DATFile](by-class/DATFile.md) | `0x0049c130-0x0049d2cc` aggregate | `archive/DATFile.cpp` | File-like reader for one DAT entry. |
| [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) | `0x00618924-0x00618950` | `archive/DATFile.h` declaration, `archive/DATFile.cpp` implementation | Implements the shared `File` stream contract over mapped DAT entry payloads. |
| [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) | [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) | `archive/DATFile.cpp` | Convenience loader that constructs `DATFile`, opens a named entry, allocates a buffer, reads bytes, closes, and destructs. |
| [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) | [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) | `archive/DATFile.cpp` private/static helper | Called only by the two bulk-entry readers currently attached to `DATFile`; distinct from standalone [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md). |

[UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) belongs with [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) because it probes the global archive manager and does not instantiate a `DATFile` reader.

## DATFile Methods

IDA MCP confirms these exact function starts and half-open ranges:

| Range | Method | Role |
| --- | --- | --- |
| `0x0049c130-0x0049c15a` | `DATFile::DATFile` | Initializes the 20-byte reader object. |
| `0x0049c160-0x0049c179` | `DATFile::~DATFile` | Releases/clears reader state. |
| `0x0049c180-0x0049c23b` | `Open` | Resolves a named DAT entry through `_DATFileMgr::FindEntryByName`. |
| `0x0049c240-0x0049c260` | `Close` | Clears the active entry. |
| `0x0049c260-0x0049c2cc` | `Seek` | Moves the read cursor within the current entry. |
| `0x0049c2d0-0x0049c2e7` | `Tell` | Returns the current entry cursor. |
| `0x0049c2f0-0x0049c304` | `GetSize` | Returns payload size. |
| `0x0049c310-0x0049c362` | `Read` | Copies payload bytes from the mapped archive into the caller buffer. |
| `0x0049c370-0x0049c3df` | `ReadLineRaw` | Raw line reader over DAT payload data. |
| `0x0049c3e0-0x0049c499` | `ReadLine` | String-oriented line reader. |
| `0x0049c4a0-0x0049c4ef` | `ReadAllEntries` | Bulk entry reader; calls `ParseEntries_004A5E60`. |
| `0x0049c4f0-0x0049c53f` | `ReadAllEntriesAlt` | Alternate bulk reader; also calls `ParseEntries_004A5E60`. |
| `0x0049c550-0x0049c567` | `GetDataPointer` | Returns direct pointer into the current entry payload. |
| `0x0049c600-0x0049c6f2` | `ReadAllLines` | Reads all text lines into a string/list style output. |
| `0x0049c720-0x0049c74b` | `OpenByIndex` | Opens by archive container/index record. |
| `0x0049d280-0x0049d2cc` | scalar deleting destructor | Compiler delete wrapper. |

## File-Level Rationale

- `DATFile` is used broadly by render, palette, sound, dialog, map-name, and resource-loading code, so it is an archive API rather than a caller-specific image or UI helper.
- `Open` depends on the manager lookup API, but the reader object only stores an entry pointer, current offset, and payload size after resolution.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) is a direct lifecycle wrapper around `DATFile`: IDA MCP shows calls to the constructor, `Open`, `GetSize`, allocation/memset helpers, `Read`, `Close`, and destructor. The exact helper range is now documented at [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md).
- `ReadAllEntries` and `ReadAllEntriesAlt` are the only IDA-confirmed callers of [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md). A 2026-05-25 IDA MCP recheck shows both callers only compute `GetSize() >> 1`, read eight bytes, and call the helper, so `ParseEntries` should stay as a private/static-style helper in this file. Do not confuse this with [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md), which is a separate shared helper.
- 2026-05-31 IDA MCP recheck confirms the `DATFile` constructor/open/read-all/destructor function starts, broad constructor/open caller fan-in from render/resource/map/audio consumers, `ParseEntries` caller restriction to `ReadAllEntries` and `ReadAllEntriesAlt`, `LoadDatFileBuffer` as a constructor/open/read/close wrapper, and the `DATFile` vtable at `0x00618924` filling the same stream contract as `File`.

## Dependencies

- Calls into [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) through `_DATFileMgr::FindEntryByName`.
- Consumed by image libraries, palette loading, sound loading, UI profile/map helpers, and generic resource buffer loaders.
- Uses the shared 17-byte [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md) layout exposed by `DATFileContainer`.

## Open Questions

- Confirm original field names for entry pointer, cursor, and payload-size members.
- Confirm whether `OpenByIndex` was public API or manager-only friend/internal access.

## Cross-References

- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00012D][0x0049c130-0x0049d2cb.DATFile](by-memory/0x0049c130-0x0049d2cb.DATFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: per-entry DAT reader ownership, method table, private/static helper placement, load-buffer wrapper, dependencies, open field-name/API questions, and cross-references are documented; confidence is strong because IDA caller/callee evidence tightly ties the helper set to `DATFile.cpp`.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `86/88`, and the module path used `archive/DATFile.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`, scores `87/89`, and proposed module `NexusTK/archive/DATFile.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the per-entry stream reader, `DATFile` vtable, `ParseEntries` caller restriction, and `LoadDatFileBuffer` lifecycle wrapper. No C++ reconstruction code is emitted yet because individual method source rewrites and neighboring-range confidence are below the `95+` final-code gate.
