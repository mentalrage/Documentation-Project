*** UID:00003G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DATFile.h"
#include "DATFileMgr.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"
#include <string.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_ARCHIVE_DAT_FILE_H
#define NEXUSTK_ARCHIVE_DAT_FILE_H

#include "../util/File.h"
#include <vector>

class DATFileContainer;
struct DATEntryRecord;

class DATFile : public File
{
public:
    DATFile();
    virtual ~DATFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    int ReadEncodedTableInt(int *outValue);
    int ReadEncodedTableFloat(float *outValue);
    bool IsOpen() const;
    void *GetDataPointer() const;
    void ReadAllLines(std::vector<StringBaseW> &lines);
    int OpenByIndex(DATFileContainer *archive, int index);

private:
    DATFileContainer *m_archive;
    const DATEntryRecord *m_entry;
    int m_position;
    int m_size;
};

typedef char DATFileSizeMustBe0x14[
    sizeof(DATFile) == 0x14 ? 1 : -1];

char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFile

## 2026-08-18 Complete Declaration And Ownership Closure

This page is the sole human declaration owner for the exact 0x14-byte `DATFile` class. The `File` base occupies `+0x00`; typed fields are `DATFileContainer *m_archive` at `+0x04`, `const DATEntryRecord *m_entry` at `+0x08`, absolute cursor `m_position` at `+0x0c`, and payload size `m_size` at `+0x10`. The guarded H channel declares all sixteen authored methods and intentionally does not redeclare the inherited wide `File::ReadLine(StringBaseW&)` helper.

The CPP channel provides all compile-visible dependencies before `[[CHILDREN]]`. Exact by-memory children own definitions. Vtable data, RTTI, scalar deleting-destructor lowering, and the retained duplicate wide helper are compiler-covered and must not be hand-authored.

Physical child order is constructor [UID:00055G][0x0049c130-0x0049c15a.DATFileConstructor](by-memory/0x0049c130-0x0049c15a.DATFileConstructor.md), destructor [UID:00055H][0x0049c160-0x0049c179.DATFileDestructor](by-memory/0x0049c160-0x0049c179.DATFileDestructor.md), Open [UID:00055I][0x0049c180-0x0049c23b.DATFileOpen](by-memory/0x0049c180-0x0049c23b.DATFileOpen.md), Close [UID:00055J][0x0049c240-0x0049c260.DATFileClose](by-memory/0x0049c240-0x0049c260.DATFileClose.md), Seek [UID:00055K][0x0049c260-0x0049c2cc.DATFileSeek](by-memory/0x0049c260-0x0049c2cc.DATFileSeek.md), GetPosition [UID:00055L][0x0049c2d0-0x0049c2e7.DATFileGetPosition](by-memory/0x0049c2d0-0x0049c2e7.DATFileGetPosition.md), GetSize [UID:00055M][0x0049c2f0-0x0049c304.DATFileGetSize](by-memory/0x0049c2f0-0x0049c304.DATFileGetSize.md), Read [UID:00055N][0x0049c310-0x0049c362.DATFileRead](by-memory/0x0049c310-0x0049c362.DATFileRead.md), ReadLineChars [UID:00055O][0x0049c370-0x0049c3df.DATFileReadLineChars](by-memory/0x0049c370-0x0049c3df.DATFileReadLineChars.md), ANSI ReadLine [UID:00055P][0x0049c3e0-0x0049c499.DATFileReadLine](by-memory/0x0049c3e0-0x0049c499.DATFileReadLine.md), the two encoded scalar methods, IsOpen [UID:00055Q][0x0049c540-0x0049c548.DATFileIsOpen](by-memory/0x0049c540-0x0049c548.DATFileIsOpen.md), GetDataPointer [UID:00055R][0x0049c550-0x0049c567.DATFileGetDataPointer](by-memory/0x0049c550-0x0049c567.DATFileGetDataPointer.md), ReadAllLines [UID:00055T][0x0049c600-0x0049c6f2.DATFileReadAllLines](by-memory/0x0049c600-0x0049c6f2.DATFileReadAllLines.md), and OpenByIndex [UID:00055U][0x0049c720-0x0049c74b.DATFileOpenByIndex](by-memory/0x0049c720-0x0049c74b.DATFileOpenByIndex.md). [UID:00055S][0x0049c570-0x0049c5fe.DATFileRetainedWideReadLineDuplicate](by-memory/0x0049c570-0x0049c5fe.DATFileRetainedWideReadLineDuplicate.md) and [UID:00055V][0x0049d280-0x0049d2cc.DATFileScalarDeletingDestructor](by-memory/0x0049d280-0x0049d2cc.DATFileScalarDeletingDestructor.md) remain non-emitting evidence.

## Status

- Confidence: very strong for responsibility, method/vtable boundaries, typed encoded-scalar methods, source module ownership, and helper relationships; medium-high for final field names.
- Likely source module: [UID:0000IN][DATFile](by-file/DATFile.md)
- Current range: [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- Evidence basis: existing DAT format/helper docs plus IDA MCP caller/callee/decompile/vtable checks through Batch 082.
- Type docs: [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md), shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), and [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- Exact vtable data: [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)

## Responsibility

`DATFile` is the per-entry file-like reader for DAT-backed resources. It opens a named entry through the global DAT manager, tracks a current read position over the entry payload, and exposes normal read/seek/tell/size/line-reading helpers.

## Layout

Observed binary layout:

| Offset | Current field | Interpreted role |
| --- | --- | --- |
| `0x0` | `File` | Four-byte data-member-free File/LObject/vptr base. |
| `0x4` | archive/container field | DATFile-owned active archive/container pointer or handle. |
| `0x8` | entry-record field | Resolved entry pointer/location. |
| `0xc` | current absolute payload offset | Absolute mapped-data cursor; source-facing field name remains inferred. |
| `0x10` | entry payload size | Size returned by GetSize. |

Total known size is 20 bytes. The vtable at `0x00618924` implements the same stream slots as `File` and `StdioFile`; see exact source-local child [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md), shared slot index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), and exact backing child [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0049c130` | `DATFile::DATFile` | Initializes the reader object. |
| `0x0049c160` | `DATFile::~DATFile` | Closes or releases reader state. |
| `0x0049c180` | `Open` | Resolves a named entry; IDA MCP confirms call to `_DATFileMgr::FindEntryByName` at `0x0049cad0`. |
| `0x0049c240` | `Close` | Clears active entry state. |
| `0x0049c260` | `Seek` | Moves current entry read position. |
| `0x0049c2d0` | `GetPosition` | Returns current entry read position; `Tell` is historical vocabulary. |
| `0x0049c2f0` | `GetSize` | Returns entry size. |
| `0x0049c310` | `Read` | Returns `size_t`, takes signed `int count`, substitutes the full payload size when count is negative, copies bytes, and advances the absolute cursor. |
| `0x0049c370` | `ReadLineChars` | Canonical caller-buffer line reader over DAT entry data; `ReadLineRaw` is a historical alias only. |
| `0x0049c3e0` | `ReadLine` | String-oriented line reader. |
| `0x0049c4a0` | [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md) | Reads one encoded eight-byte scalar into integer storage and returns full-register success. Historical alias: `ReadAllEntries`. |
| `0x0049c4f0` | [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md) | Reads one encoded eight-byte scalar into float storage without numeric conversion. Historical alias: `ReadAllEntriesAlt`. |
| `0x0049c550` | `GetDataPointer` | Returns pointer to the current entry data. |
| `0x0049c600` | `ReadAllLines` | Fills a string-vector style output with all lines. |
| `0x0049c720` | `OpenByIndex` | Opens by archive/index location rather than name. |
| `0x0049d280` | `ScalarDeletingDestructor` | Compiler delete wrapper. |

## Assignment Gate

The class remains owner/emitter-routed to [UID:0000IN][DATFile](by-file/DATFile.md) at unchanged `89/92`. Formal CPP includes `DATFile.h` and expands all exact child definitions; formal H now supplies the complete 0x14 class, File overrides, encoded-scalar methods, private field layout, size assertion, and `LoadDatFileBuffer` declaration. This is compile-visible declaration closure, not new score credit. The former blank formal class and `ReadLineRaw` terminology are retained only as historical pre-callback states.

## Ownership Notes

- `DATFile` should live in the archive module with [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) and [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md).
- `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) should be grouped in the companion [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) module.
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md) is a strong helper candidate for the same source module because IDA MCP confirms it uses the complete `DATFile` lifecycle.
- UID0004IY and UID0004IZ form the direct bridge from archive entry data to [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md). They are its only callers, resolving the helper as `archive/DATFile.cpp` file-local code.
- Both methods compute unsigned `GetSize() >> 1`, read exactly eight local bytes, and directly return the decoder's full-register `1`/`0` result. Failure leaves caller output untouched; no allocation, persistent buffer, collection, or outer archive-record parse occurs.
- UID0004IY has 87 integer/count/ID/flag destinations. UID0004IZ has six Effect/Item/Light float destinations in four functions; neither wrapper nor decoder performs numeric float conversion.
- The B001 DATFile owner pass promotes accepted consumer aliases `ReadEncodedTableInt` / `ReadEncodedTableFloat` to source-facing method names. Historical `ReadAllEntries` / `ReadAllEntriesAlt` remain provenance/search aliases only.
- `Open` and `OpenByIndex` both interpret DAT entry records as 17-byte records whose first dword is the payload start offset. The payload size is computed from the next record/sentinel start offset.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the constructor, destructor, stream virtuals, bulk readers, support helpers at `0x0049c540`/`0x0049c570`, `OpenByIndex`, scalar deleting destructor endpoint `0x0049d2cc`, and four `0xcc` bytes at `0x0049d2cc-0x0049d2d0`.
- The same refresh reconfirmed broad consumer fan-in: constructor 83 callers, destructor 142 callers, `Open` 67 callers, `Read` 131 callers, UID0004IY 87 callers, UID0004IZ 6 callers, and `OpenByIndex` 2 callers; the `DATFile` vtable at `0x00618924` targets the scalar deleting destructor, inherited slots, `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, signed-count `Read`, `ReadLine`, and `ReadLineChars`.

## UID0002UV Source-Quality Callback

- Preserved the blank class formal, owner/emitter/source route, complete encoded-scalar work, caller inventory, method inventory, helper relationships, rejected aliases, and all unrelated DAT evidence.
- Corrected the complete 20-byte layout to a four-byte File base plus DATFile-owned fields at `+0x04/+0x08/+0x0c/+0x10`.
- DATFile scalar deleting wrapper's `0x14` size immediate, constructor/open/close/position/size/read field behavior, and vtable installation all agree with this layout.
- `GetPosition` is the current source-facing name; `Tell` remains historical.
- The common Read source contract is `size_t Read(void *buffer, int count)`. This implementation's explicit negative-count full-payload branch is the decisive signed-parameter evidence used across File and StdioFile.
- The historical shared File handle is rejected; `+0x04` is a DATFile field.
- Raised only this page from `88/91` to `89/92`; no DATFile class body was introduced because the complete declaration remains outside this bounded callback.
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md) is compiler pooling for UID00013W's local 27-value initializer, not a separately declared class/file table.
- The eight-byte scalar unit is not the outer 17-byte [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md). The class uses that record only in `Open`/`OpenByIndex`, not in the typed scalar wrappers.
- 2026-06-11 A001 Batch 208 split created [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md) as the exact `DATFile` vtable child after separating it from the adjacent `DATFileContainer` record in the former mixed page.

## Historical Open Questions Resolved By Complete Declaration

- Confirm final field names for offsets `0x8`, `0xc`, and `0x10`.
- Encoded wrapper output types and one-scalar behavior are resolved by UID0004IY/UID0004IZ; no bulk table/container question remains for those methods.
- Confirm whether `OpenByIndex` should be public API or an internal manager hook.

## Cross-References

- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md)
- [UID:0000T4][LoadDatFileBuffer_4BB120](by-global/LoadDatFileBuffer_4BB120.md)
- [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md)
- [UID:0000UW][LoadDatFileBuffer_004BB120](by-item/LoadDatFileBuffer_004BB120.md)
- [UID:0000TH][ParseEntries_004A5E60](by-global/ParseEntries_004A5E60.md)
- [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md)
- [UID:0000V5][ParseEntries_004A5E60](by-item/ParseEntries_004A5E60.md)
- [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md)
- [UID:0004IY][0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt](by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md)
- [UID:0004IZ][0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat](by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md)
- [UID:0003IC][0x006192e0-0x00619340.ParseEntriesConstantTable](by-memory/0x006192e0-0x00619340.ParseEntriesConstantTable.md)

## Score Rationale

- Completion `88`: class purpose, source parent, layout, method/vtable contract, exact typed wrapper children, complete wrapper/decoder behavior, caller fan-in, DAT manager/helper relationships, compiler-pool distinction, aggregate disposition, and remaining field/API questions are documented.
- Confidence `91`: current IDA MCP strongly supports method boundaries, typed destinations, vtable slots, archive ownership, and helper relationships. Confidence remains below final audit because member field names, access specifiers, and exact original method spellings remain inferred.

## Changes

- 2026-08-17 B001 UID0000MG support implementation: score unchanged; installed the complete guarded DATFile H and owner include/children CPP route, standardized the stream method to `ReadLineChars(char *, int)`, preserved the exact four-byte File base plus `+0x04/+0x08/+0x0c/+0x10` fields and 0x14 assertion, and retained every existing method/vtable/helper/history fact.

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
- 2026-06-11 A001 Batch 208 exact vtable child sync:
  - Scores remain `86/88`.
  - Added [UID:0003B7][0x00618920-0x00618950.DATFileVtableData](by-memory/0x00618920-0x00618950.DATFileVtableData.md) as the exact `DATFile` vtable-data child split from the former mixed `DATFileContainer`/`DATFile` page.
  - Evidence: live IDA MCP reconfirmed the `DATFile` RTTI pointer, scalar deleting destructor slot, inherited/base slots, concrete stream slots, constructor vtable-install xref, and neighboring `DATFileContainer`/UTF-16 string boundaries.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `86/88`.
  - Added [UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) as the exact source-local vtable child for this class; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now only the non-emitting shared File/DATFile/StdioFile slot-layout index.
  - Evidence: live IDA MCP reconfirmed `??_7DATFile@@6B@`, concrete stream slot target sizes, constructor install xref, and the unique `0x00618920-0x00618950` signature.
- 2026-06-17 B003 LightObjImageLib consumer-alias sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: B003's LightObjImageLib audit documents how image-library constructors use `0x0049c4a0` and `0x0049c4f0` as scalar encoded int/float table readers. This page retains the DATFile-owned names pending a DATFile owner pass while allowing LightObjImageLib draft C++ to use local semantic aliases.
- 2026-06-18 B005 ItemObjImageLib consumer-alias sync:
  - Score unchanged.
  - Summary/evidence: B005's ItemObjImageLib constructor audit documents the same scalar encoded table-reader use from ItemObjImageLib `ITEM.TBL` / `ITEM.TBD` loading. This page retains DATFile-owned names pending a DATFile owner pass while allowing ItemObjImageLib draft C++ to use the same local semantic aliases as LightObjImageLib.
- 2026-07-12 B001 UID00013W callback:
  - Before: `86/88`, historical `ReadAllEntries`/`ReadAllEntriesAlt`, deferred output types, and no exact method children.
  - After: `88/91`, exact UID0004IY/UID0004IZ children with typed formal definitions, full one-scalar/failure/lifetime contract, source-facing names, local decoder relationship, and compiler-pool/outer-record distinctions.
  - Owner/emitter UID0000IN and blank class block remain unchanged; exact child definitions now emit through this class route.
