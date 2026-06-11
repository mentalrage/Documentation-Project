*** UID:00003G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATFile

## Status

- Confidence: strong for responsibility, method/vtable boundaries, source module ownership, and helper relationships; medium-high for final field names.
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Current range: [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- Evidence basis: existing DAT format/helper docs plus IDA MCP caller/callee/decompile/vtable checks through Batch 082.
- Type docs: [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)

## Responsibility

`DATFile` is the per-entry file-like reader for DAT-backed resources. It opens a named entry through the global DAT manager, tracks a current read position over the entry payload, and exposes normal read/seek/tell/size/line-reading helpers.

## Layout

Observed binary layout:

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

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000IN][DATFile](by-file/DATFile.md). This class is now scored `86/88`, and the direct source-file parent is scored `87/89`, so both sides satisfy the corrected 85/85 gate. The parent is direct because the file page is the `NexusTK/archive/DATFile.cpp` source root and explicitly owns this per-entry reader class, its stream vtable, the `LoadDatFileBuffer` lifecycle wrapper, and the private/static-style `ParseEntries` helper used only by the DATFile bulk readers.

## Ownership Notes

- `DATFile` should live in the archive module with [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md).
- `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) should be grouped in the companion [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) module.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) is a strong helper candidate for the same source module because IDA MCP confirms it uses the complete `DATFile` lifecycle.
- `ReadAllEntries` and `ReadAllEntriesAlt` form the direct bridge from archive entry data to the [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) header decoder. The 2026-05-25 IDA MCP recheck shows they are the only callers, which resolves the helper as `archive/DATFile.cpp` private/static-style code rather than a separate shared module.
- `Open` and `OpenByIndex` both interpret DAT entry records as 17-byte records whose first dword is the payload start offset. The payload size is computed from the next record/sentinel start offset.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the constructor, destructor, stream virtuals, bulk readers, support helpers at `0x0049c540`/`0x0049c570`, `OpenByIndex`, scalar deleting destructor endpoint `0x0049d2cc`, and four `0xcc` bytes at `0x0049d2cc-0x0049d2d0`.
- The same refresh reconfirmed broad consumer fan-in: constructor 83 callers, destructor 142 callers, `Open` 67 callers, `Read` 131 callers, `ReadAllEntries` 87 callers, `ReadAllEntriesAlt` 6 callers, and `OpenByIndex` 2 callers; the `DATFile` vtable at `0x00618924` targets the scalar deleting destructor, stream operations, `Open`, `Close`, `Tell`, `Seek`, `GetSize`, `Read`, `ReadLine`, and `ReadLineRaw`.

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
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)

## Score Rationale

- Completion `86`: class purpose, direct source parent, binary layout, method table, vtable contract, broad caller fan-in, DAT manager/helper relationships, private `ParseEntries` ownership, exact aggregate memory child, and open field/API questions are documented.
- Confidence `88`: current IDA MCP evidence strongly supports method boundaries, vtable slots, archive source ownership, and helper relationships. Confidence stays below final-source quality because member field names and source-facing method signatures remain provisional.

## Changes

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the `DATFile` constructor, vtable install, archive/container and entry/cursor/payload fields, and stream virtual methods; no parent/code was attached because final source text is not yet at the 95+ gate.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/82`.
  - Summary/evidence: responsibility, layout, stream methods, DAT-manager links, parser bridge, ownership notes, and open questions are documented from Wave3 and IDA-backed ranges; remaining work is exact field naming and final C++ source reconstruction.
- 2026-06-07 A008 Batch 082 class-coverage pass:
  - Before: `78/82`, `AUTOGEN_PARENT_UID:` blank, and range references still used the stale `0x0049d2cb` filename endpoint.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000IN`, and range references point at [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md).
  - Evidence: current IDA MCP reconfirmed the method/vtable map, broad DATFile caller fan-in, `ParseEntries` and `LoadDatFileBuffer` relationships through existing docs, support-helper caveats, and the `0x0049d2cc` half-open endpoint.
