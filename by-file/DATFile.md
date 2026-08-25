*** UID:0000IN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DATFile

## 2026-08-18 Whole-File Source Closure

`NexusTK/archive/DATFile.cpp/.h` is one of the two authored archive units. Its complete source inventory is sixteen `DATFile` methods, file-local `DecodeTableValue`, and `LoadDatFileBuffer`, for eighteen authored bodies. Exact by-memory children own the constructor, destructor, Open, Close, Seek, GetPosition, GetSize, Read, ReadLineChars, ANSI ReadLine, IsOpen, GetDataPointer, ReadAllLines, and OpenByIndex bodies; the existing encoded-int/float children own the remaining two methods. The scalar deleting destructor and the retained `0x0049c570` copy of `File::ReadLine(StringBaseW&)` are compiler products and emit no authored source.

The source uses the packed 17-byte `DATEntryRecord` declared through `DATFileMgr.h`, computes each payload size from the next record's `startOffset`, preserves signed-count `Read` behavior, and preserves the observed CR/LF cursor increments and inclusive `+1` line-copy count. `ReadAllLines` intentionally calls inherited `File::ReadLine(StringBaseW&)`; the byte-identical zero-caller copy retained in the DAT translation unit does not imply a second DATFile declaration.

Generated acceptance requires all eighteen authored bodies in physical source order, a complete sibling header, and zero DATFile-specific empty-emitter/compiler-product markers.

Exact newly routed children are [UID:00055G][0x0049c130-0x0049c15a.DATFileConstructor](by-memory/0x0049c130-0x0049c15a.DATFileConstructor.md), [UID:00055H][0x0049c160-0x0049c179.DATFileDestructor](by-memory/0x0049c160-0x0049c179.DATFileDestructor.md), [UID:00055I][0x0049c180-0x0049c23b.DATFileOpen](by-memory/0x0049c180-0x0049c23b.DATFileOpen.md), [UID:00055J][0x0049c240-0x0049c260.DATFileClose](by-memory/0x0049c240-0x0049c260.DATFileClose.md), [UID:00055K][0x0049c260-0x0049c2cc.DATFileSeek](by-memory/0x0049c260-0x0049c2cc.DATFileSeek.md), [UID:00055L][0x0049c2d0-0x0049c2e7.DATFileGetPosition](by-memory/0x0049c2d0-0x0049c2e7.DATFileGetPosition.md), [UID:00055M][0x0049c2f0-0x0049c304.DATFileGetSize](by-memory/0x0049c2f0-0x0049c304.DATFileGetSize.md), [UID:00055N][0x0049c310-0x0049c362.DATFileRead](by-memory/0x0049c310-0x0049c362.DATFileRead.md), [UID:00055O][0x0049c370-0x0049c3df.DATFileReadLineChars](by-memory/0x0049c370-0x0049c3df.DATFileReadLineChars.md), [UID:00055P][0x0049c3e0-0x0049c499.DATFileReadLine](by-memory/0x0049c3e0-0x0049c499.DATFileReadLine.md), [UID:00055Q][0x0049c540-0x0049c548.DATFileIsOpen](by-memory/0x0049c540-0x0049c548.DATFileIsOpen.md), [UID:00055R][0x0049c550-0x0049c567.DATFileGetDataPointer](by-memory/0x0049c550-0x0049c567.DATFileGetDataPointer.md), [UID:00055T][0x0049c600-0x0049c6f2.DATFileReadAllLines](by-memory/0x0049c600-0x0049c6f2.DATFileReadAllLines.md), and [UID:00055U][0x0049c720-0x0049c74b.DATFileOpenByIndex](by-memory/0x0049c720-0x0049c74b.DATFileOpenByIndex.md). Compiler/no-code children are [UID:00055S][0x0049c570-0x0049c5fe.DATFileRetainedWideReadLineDuplicate](by-memory/0x0049c570-0x0049c5fe.DATFileRetainedWideReadLineDuplicate.md) and [UID:00055V][0x0049d280-0x0049d2cc.DATFileScalarDeletingDestructor](by-memory/0x0049d280-0x0049d2cc.DATFileScalarDeletingDestructor.md).

## UID0000L2 DATFile Header Consumer Contract - 2026-08-12

- `NexusTK/archive/DATFile.h` must expose [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) as `char *__stdcall LoadDatFileBuffer(const wchar_t *path, int prefixSize, int *outSize);`. The exact body remains owned by `DATFile.cpp` through the same child.
- `MapNamePane::MapNamePane()` calls this generic DAT-backed buffer loader for `L"9X11FONT.BIN"` with prefix size `0` and an output-size pointer. That consumer does not transfer ownership to map/UI code and does not justify a duplicate local declaration or helper body.
- The declaration correction preserves the current file score, FILE ownership, `NexusTK/archive/` path, DAT lifecycle behavior, MemoryMan allocation route, aliases, and all existing source-order/history evidence.

## Status

- Confidence: very strong for `DATFile.cpp` ownership, exact typed scalar wrappers, and `DecodeTableValue` as a file-local helper in that module.
- Proposed module: `NexusTK/archive/DATFile.cpp`
- Related helper pages: [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md).
- Evidence basis: existing DAT format notes plus current IDA MCP function/caller/callee/decompile/disassembly checks; UID00013W and both typed wrappers were rechecked and implemented on 2026-07-12.
- Type docs: [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md), shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), and [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- Exact vtable data: [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)

## Proposed Contents

This file should own the per-entry stream reader and the small helpers that treat a DAT-backed resource as a normal input buffer.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003G][DATFile](by-class/DATFile.md) | [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) aggregate | `archive/DATFile.cpp` | File-like reader for one DAT entry. |
| [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) / [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md) | `0x00618920-0x00618950` | `archive/DATFile.h` declaration, `archive/DATFile.cpp` implementation | Exact `DATFile` RTTI/vtable data and concrete stream slot evidence; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) remains the shared slot-contract index. |
| [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) | [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) | `archive/DATFile.cpp` | Source-ready convenience loader `LoadDatFileBuffer`: constructs `DATFile`, opens a named entry, allocates `payloadSize + prefixSize` through `GetMemoryMan()->AllocateBufferMemory`, optionally returns total size, zero-fills a signed positive prefix, reads bytes, closes, and destructs. The by-global and by-item pages are covered aliases, not duplicate implementations. |
| [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md) | [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) | `archive/DATFile.cpp` private/static helper | Source-ready one-scalar decoder called only by UID0004IY/UID0004IZ; distinct from standalone [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md). |
| [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) | `0x0049c4a0-0x0049c4ef` | `DATFile` method in `archive/DATFile.cpp` | Reads one encoded eight-byte scalar into integer storage; 87 call sites; historical alias `ReadAllEntries`. |
| [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md) | `0x0049c4f0-0x0049c53f` | `DATFile` method in `archive/DATFile.cpp` | Reads one encoded eight-byte scalar into float storage without numeric conversion; six calls in four functions; historical alias `ReadAllEntriesAlt`. |

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
| `0x0049c4a0-0x0049c4ef` | [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) | One encoded integer/count/ID/flag scalar; calls UID00013W. |
| `0x0049c4f0-0x0049c53f` | [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md) | One encoded float scalar bit pattern; calls UID00013W without numeric conversion. |
| `0x0049c550-0x0049c567` | `GetDataPointer` | Returns direct pointer into the current entry payload. |
| `0x0049c600-0x0049c6f2` | `ReadAllLines` | Reads all text lines into a string/list style output. |
| `0x0049c720-0x0049c74b` | `OpenByIndex` | Opens by archive container/index record. |
| `0x0049d280-0x0049d2cc` | scalar deleting destructor | Compiler delete wrapper. |

## File-Level Rationale

- `DATFile` is used broadly by render, palette, sound, dialog, map-name, and resource-loading code, so it is an archive API rather than a caller-specific image or UI helper.
- `Open` depends on the manager lookup API, but the reader object only stores an entry pointer, current offset, and payload size after resolution.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) is a direct lifecycle wrapper around `DATFile`: IDA MCP shows calls to the constructor, `Open`, `GetSize`, allocation/memset helpers, `Read`, `Close`, and destructor. The exact helper range is documented and now source-ready at [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md).
- 2026-06-28 B015 source-quality callback resolved the old blank-emitter state for `LoadDatFileBuffer`. The accepted source-facing helper name is `LoadDatFileBuffer`; `_4BB120` and `_004BB120` remain documentation/search aliases. The emitted body belongs to [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) and uses `GetMemoryMan()->AllocateBufferMemory(totalSize)` after the DATFile `GetSize` call. [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md) emit only formal covered-by comments so `archive/DATFile.cpp` does not duplicate the same function body.
- `LoadDatFileBuffer` caller/resource evidence should not move ownership out of this file. Collection, NumericString, MapName, SelfLook, Group, and status-pane constructors consume the returned `9X11FONT.BIN`/resource buffer, but the loader body is archive access plus MemoryMan allocation. The UTF-16 `L"9X11FONT.BIN"` path at `0x0061682c` is shared UI numeric-font resource evidence; IDA's interior `a11fontBin` label is evidence only and must not become source-facing code.
- UID0004IY and UID0004IZ are the only IDA-confirmed callers of [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md). Both compute unsigned `GetSize() >> 1`, read exactly eight local bytes, and immediately return the decoder's full-register `1`/`0` result.
- UID0004IY's 87 call sites use integer/count/ID/flag storage. UID0004IZ's six call sites in Effect/Item/Light loaders use float fields later consumed as floats. The wrapper/decoder path performs no numeric float conversion.
- Decoder failure leaves caller output untouched but mutates the wrappers' local byte buffer before it is discarded. The path allocates nothing, retains no pointer, transfers no ownership, parses no outer 17-byte DAT directory row, and has no sentinel or record loop.
- Historical `ReadAllEntries`, `ReadAllEntriesAlt`, and `ParseEntries` names are retained for search provenance only. Source-facing names are `ReadEncodedTableInt`, `ReadEncodedTableFloat`, and file-local `DecodeTableValue`.
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) is compiler pooling for UID00013W's local 27-dword initializer. It is non-reconstructable/no-emitter and must not produce a second declaration.
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) is now a non-emitting index; exact source-bearing children carry method/helper bodies.
- Generated source order uses UID00013W position `10` through this file before wrapper children positions `10`/`20` through UID00003G, preventing an artificial forward declaration.
- 2026-07-12 current-package `LIGHT.TBL` produced zero validations out of 385 scalar units. Preserve this as package/version/path mismatch negative evidence; do not infer payload values from it.

## Dependencies

- Calls into [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) through `_DATFileMgr::FindEntryByName`.
- Consumed by image libraries, palette loading, sound loading, UI profile/map helpers, and generic resource buffer loaders.
- Uses the shared 17-byte [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md) layout exposed by `DATFileContainer`.
- The 17-byte outer directory record is distinct from UID00013W's eight-byte scalar encoding inside TBL payloads.

## Historical Open Questions Resolved By Whole-File Closure

- Confirm original field names for entry pointer, cursor, and payload-size members.
- Confirm whether `OpenByIndex` was public API or manager-only friend/internal access.

## Cross-References

- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)
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
- [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md)
- [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md)
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: per-entry DAT reader ownership, method table, private/static helper placement, load-buffer wrapper, dependencies, open field-name/API questions, and cross-references are documented; confidence is strong because IDA caller/callee evidence tightly ties the helper set to `DATFile.cpp`.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `86/88`, and the module path used `archive/DATFile.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`, scores `87/89`, and proposed module `NexusTK/archive/DATFile.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the per-entry stream reader, `DATFile` vtable, `ParseEntries` caller restriction, and `LoadDatFileBuffer` lifecycle wrapper. No C++ reconstruction code is emitted yet because individual method source rewrites and neighboring-range confidence are below the `95+` final-code gate.
- 2026-06-03 ParseEntries evidence cleanup:
  - What changed: status provenance was narrowed to live IDA MCP and DAT-format evidence; scores and reconstruction path are unchanged.
  - Summary/evidence: live IDA MCP reconfirmed `ParseEntries` range `0x004a5e60-0x004a609f`, the two direct DATFile wrapper call sites, wrapper decompile behavior, lack of project callees, and the padding split after the helper.
- 2026-06-07 A008 Batch 082 class-route sync:
  - Scores remain `87/89`.
  - Updated the exact DATFile aggregate reference to [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) after the stale `0x0049d2cb` filename was repaired, and confirmed this file as the direct parent for [UID:00003G][DATFile](by-class/DATFile.md), now `86/88`.
- 2026-06-11 A001 Batch 208 exact vtable child sync:
  - Scores remain `87/89`.
  - Added [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md) as the exact source-declared/generated-binary vtable child for the `DATFile` class/source root.
  - Evidence: the former mixed page was split at `0x00618920`; live IDA MCP confirms the RTTI pointer, vtable slots, constructor install xref, and `0x00618950` UTF-16 string boundary.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `87/89`.
  - Added [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) as the exact source-local vtable child for the `DATFile` class/source root; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now a non-emitting shared slot-layout index.
- 2026-06-28 B015 `LoadDatFileBuffer` empty-emitter implementation:
  - Scores remain `87/89`.
  - Updated the `LoadDatFileBuffer` row and file-level rationale to record that [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) now emits source-ready formal C++ in `archive/DATFile.cpp`, while [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md) are covered aliases.
  - Evidence: accepted B015 report `tools/leaser/Agents/Agent-B015/research/00016G-LoadDatFileBuffer-empty-emitter-source-quality.md`; live MCP session `supervisor_20260628_resume` reconfirmed `sub_4BB120` at `0x004bb120` size `0xb2`, DATFile lifecycle calls, MemoryMan allocation route, direct-call-only reachability, and no split at `0x004bb1d2`.
- 2026-07-12 B001 UID00013W callback:
  - Before: `87/89`, historical bulk-reader/parser names, no exact wrapper pages, blank helper/alias markers, standalone constant-table wording, and an emitting broad aggregate marker.
  - After: `89/92`, source-ready UID00013W plus exact UID0004IY/UID0004IZ definitions, typed caller/failure/lifetime detail, covered aliases, compiler-pool correction, non-emitting aggregate, real source order, and preserved package/ownership negative evidence.
  - Reconstruction path and FILE ownership remain unchanged.
