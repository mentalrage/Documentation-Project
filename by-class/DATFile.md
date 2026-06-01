*** UID:00003G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATFile

## Status

- Confidence: strong for responsibility and methods, medium for field names.
- Current file: `class_DATFile.cpp`
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Current range: `0x0049c130-0x0049d2cb`
- Evidence basis: Wave3 class/layout inspection, helper summaries, and IDA MCP caller/callee/decompile checks through 2026-05-25.
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## Responsibility

`DATFile` is the per-entry file-like reader for DAT-backed resources. It opens a named entry through the global DAT manager, tracks a current read position over the entry payload, and exposes normal read/seek/tell/size/line-reading helpers.

## Layout

Observed Wave3 layout:

| Offset | Current field | Interpreted role |
| --- | --- | --- |
| `0x0` | `File` | Embedded `File` object/storage. |
| `0x8` | `mbr_0x8` | Entry pointer or archive-entry location. |
| `0xc` | `mbr_0xc` | Current absolute payload offset within mapped archive data. |
| `0x10` | `mbr_0x10` | Entry payload size. |

Total known size is 20 bytes. The vtable at `0x00618924` implements the same stream slots as `File` and `StdioFile`; see [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0049c130` | `DATFile::DATFile` | Initializes the reader object. |
| `0x0049c160` | `DATFile::~DATFile` | Closes or releases reader state. |
| `0x0049c180` | `Open` | Resolves a named entry; IDA MCP confirms call to `_DATFileMgr::FindEntryByName` at `0x0049cad0`. |
| `0x0049c240` | `Close` | Clears active entry state. |
| `0x0049c260` | `Seek` | Moves current entry read position. |
| `0x0049c2d0` | `Tell` | Returns current entry read position. |
| `0x0049c2f0` | `GetSize` | Returns entry size. |
| `0x0049c310` | `Read` | Copies bytes from current entry payload. |
| `0x0049c370` | `ReadLineRaw` | Raw line reader over DAT entry data. |
| `0x0049c3e0` | `ReadLine` | String-oriented line reader. |
| `0x0049c4a0` | `ReadAllEntries` | Bulk entry reader; calls `ParseEntries` at `0x004a5e60`. |
| `0x0049c4f0` | `ReadAllEntriesAlt` | Alternate bulk entry reader; also calls `ParseEntries`. |
| `0x0049c550` | `GetDataPointer` | Returns pointer to the current entry data. |
| `0x0049c600` | `ReadAllLines` | Fills a string-vector style output with all lines. |
| `0x0049c720` | `OpenByIndex` | Opens by archive/index location rather than name. |
| `0x0049d280` | `ScalarDeletingDestructor` | Compiler delete wrapper. |

## Ownership Notes

- `DATFile` should live in the archive module with [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md).
- `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) should be grouped in the companion [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) module.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) is a strong helper candidate for the same source module because IDA MCP confirms it uses the complete `DATFile` lifecycle.
- `ReadAllEntries` and `ReadAllEntriesAlt` form the direct bridge from archive entry data to the [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) header decoder. The 2026-05-25 IDA MCP recheck shows they are the only callers, which resolves the helper as `archive/DATFile.cpp` private/static-style code rather than a separate shared module.
- `Open` and `OpenByIndex` both interpret DAT entry records as 17-byte records whose first dword is the payload start offset. The payload size is computed from the next record/sentinel start offset.

## Open Questions

- Confirm final field names for offsets `0x8`, `0xc`, and `0x10`.
- Confirm whether `ReadAllEntries` outputs a DAT entry table, generic integer table, or a caller-specific structure.
- Confirm whether `OpenByIndex` should be public API or an internal manager hook.

## Cross-References

- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:00012D][0x0049c130-0x0049d2cb.DATFile](by-memory/0x0049c130-0x0049d2cb.DATFile.md)

## Changes

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the `DATFile` constructor, vtable install, archive/container and entry/cursor/payload fields, and stream virtual methods; no parent/code was attached because final source text is not yet at the 95+ gate.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/82`.
  - Summary/evidence: responsibility, layout, stream methods, DAT-manager links, parser bridge, ownership notes, and open questions are documented from Wave3 and IDA-backed ranges; remaining work is exact field naming and final C++ source reconstruction.
