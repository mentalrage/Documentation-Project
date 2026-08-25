*** UID:00003H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DATFileMgr.h"
#include "DATFile.h"
#include "../util/Error.h"
#include "../util/File.h"
#include "../util/PathUtil.h"
#include <hash_map>
#include <stdio.h>
#include <vector>
#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <windows.h>

class DATFile;
class _DATFileMgr;

class DATFileContainer
{
    friend class DATFile;
    friend class _DATFileMgr;

public:
    DATFileContainer(const wchar_t *path);
    virtual ~DATFileContainer();

private:
    HANDLE m_fileHandle;
    HANDLE m_mappingHandle;
    void *m_mappedView;
    unsigned int m_finalPayloadOffset;
    unsigned int m_entryCount;
    DATEntryRecord *m_entries;
};

struct DATEntryLocation
{
    DATFileContainer *archive;
    unsigned int index;
};

typedef char DATEntryLocationSizeMustBe0x08[
    sizeof(DATEntryLocation) == 0x08 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFileContainer

## 2026-08-18 Shared Header And Error-Path Closure

The class declaration belongs in `DATFileMgr.h`, while constructor/destructor definitions remain exact CPP children. Because this is the earliest source-bearing root in `DATFileMgr.cpp`, its CPP channel carries the complete file dependency preamble before those definitions; the later public-wrapper root retains the same dependency contract before its own children. Friendship gives DATFile and `_DATFileMgr` the observed direct access to mapped storage/table fields without inventing accessor APIs. `DATEntryLocation` follows the container declaration and is exactly eight bytes: archive pointer plus entry index.

The constructor's mapping failures are direct source behavior: format `L"UNICreateFileMapping : %s"` or `L"MapViewOfFile : %s Err %d"`, show `MessageBoxW(NULL, message, L"오류", MB_ICONWARNING)`, and `throw new Win32Error()`. Historical `ShowDATFileError` and `ShowDATFileMapError` names are rejected invented helpers.

## Status

- Confidence: strong for layout, mapped-archive lifecycle, vtable evidence, and archive-module placement.
- Likely source file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Current recovered file: `source-3/simroot_v2/class_DATFileContainer.cpp`
- Vtable evidence: exact child [UID:0003B6][0x00618918-0x00618920.DATFileContainerVtableData](by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md), with former mixed inventory [UID:0002UT][0x00618918-0x00618950.DATFileContainerAndDATFileVtableData](by-memory/0x00618918-0x00618950.DATFileContainerAndDATFileVtableData.md).
- Root emitter position: `10`, placing the complete mapped-container declaration and its existing constructor/destructor children before resolver/private/public DAT manager declarations. This is a generated source-order dependency only; score, ownership, code payload, and child behavior are unchanged.

## Class Purpose

`DATFileContainer` owns one memory-mapped DAT archive file. It opens the archive, creates a read-only file mapping, maps the view, exposes the entry table, and releases the mapping and file handles in its deleting destructor.

## Layout

| Offset | Current field | Interpreted role |
| --- | --- | --- |
| `0x00` | vptr | Virtual destructor table. |
| `0x04` | `m_fileHandle` | Win32 file handle, initialized to `INVALID_HANDLE_VALUE` and closed if valid. |
| `0x08` | `m_mappingHandle` | Read-only file-mapping handle, closed when non-null. |
| `0x0c` | `m_mappedView` | Mapped view base, unmapped when non-null and also used as archive payload base for `DATFile` reads. |
| `0x10` | `m_finalPayloadOffset` | Final entry payload boundary from the first dword of the last 17-byte table row. |
| `0x14` | `m_entryCount` | Entry count from mapped dword 0. |
| `0x18` | `m_entries` | Entry table pointer at mapped view + 4. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DATFileContainer` | `0x0049be80-0x0049c0c9` | Opens the archive, tries a `..\` fallback path, maps the file, reads entry count/table, and records the final payload boundary. |
| raw ordinary destructor | `0x0049c0d0-0x0049c130` | Restores vtable `0x0061891c`, unmaps `m_mappedView`, closes `m_mappingHandle`, closes `m_fileHandle` if not `-1`, clears mapped view/entry count/entry pointer, and returns. |
| `ScalarDeletingDestructor` | `0x0049d2d0-0x0049d349` | Compiler-generated wrapper from the virtual destructor; do not hand-author as standalone source. |

The exact constructor body emits through [UID:00043B][0x0049be80-0x0049c0c9.DATFileContainerConstructor](by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md) as B002 C++-6. The exact raw ordinary destructor body emits through [UID:00043C][0x0049c0d0-0x0049c130.DATFileContainerDestructor](by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md) as B002 C++-4. This class page keeps layout and ownership; method C++ belongs on those child pages.

## Evidence Notes

- Wave3 layout inspection reports a 28-byte object with seven 4-byte fields.
- Generated source and IDA evidence show a single mapped archive, despite the current Wave3 class summary saying "multiple DAT archive files".
- IDA MCP confirms `0x0049be80` as a real function with size `0x249` and `0x0049d2d0` with size `0x79`.
- IDA decompilation previously confirmed offset `0x10` is loaded from `entryTable + (entryCount - 1) * 17`, which matches a final boundary/sentinel row.
- 2026-06-11 IDA MCP `py_eval` refresh confirms the exact [UID:0003B6][0x00618918-0x00618920.DATFileContainerVtableData](by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md) child: `0x00618918 -> ??_R4DATFileContainer@@6B@` and `0x0061891c -> 0x0049d2d0`, with vptr-store xrefs from `0x0049bec5`, `0x0049c0d6`, and `0x0049d2d9`.
- The same refresh reports `0x0049d2d0-0x0049d349` as the scalar deleting destructor function extent and shows `0x00618920 -> ??_R4DATFile@@6B@`, proving the container vtable record is exactly one slot and ends before the neighboring `DATFile` stream vtable.
- The adjacent `DATFileMgr` source page now documents this class as a direct member of `NexusTK/archive/DATFileMgr.cpp`, and the parent file is scored `89/85`, so this class can serve as a strict-gate direct parent for an exact `DATFileContainer` vtable child after the current mixed by-memory page is split.
- 2026-06-26 B002 implementation adds the raw ordinary destructor child and formal constructor/destructor C++ routes. The constructor opens the requested path via Win32 file APIs, retries with a `"../"` prefix on direct open failure, creates a read-only mapping, maps the view, reports/throws `Win32Error` on mapping failures, reads `m_entryCount` from mapped dword 0, sets `m_entries = mappedBase + 4`, and records `m_finalPayloadOffset` from the final boundary record. The raw destructor route proves the field aliases above through unmap/close/clear behavior.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). This class is now scored `88/90`, and the direct file parent is `90/88`, so both sides satisfy the corrected 85/85 gate for class-to-file routing. Exact memory child [UID:0003B6][0x00618918-0x00618920.DATFileContainerVtableData](by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md) attaches to this class, not directly to the file page, because the vtable record is emitted from the `DATFileContainer` class declaration.

## 2026-07-01 B008 Empty-Emitter Repair

This class now emits only the source-facing `DATFileContainer` declaration and `[[CHILDREN]]` marker. The constructor and destructor bodies remain on exact child pages [UID:00043B][0x0049be80-0x0049c0c9.DATFileContainerConstructor](by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md) and [UID:00043C][0x0049c0d0-0x0049c130.DATFileContainerDestructor](by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md); this class page must not duplicate those method bodies.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0003B6][0x00618918-0x00618920.DATFileContainerVtableData](by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md)
- [UID:0002UT][0x00618918-0x00618950.DATFileContainerAndDATFileVtableData](by-memory/0x00618918-0x00618950.DATFileContainerAndDATFileVtableData.md)

## Changes

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Set root emitter position `10` for deterministic DATFileContainer/resolver/_DATFileMgr/DATFileMgr source order; preserved score `88/90`, formal class block, and all existing child implementations unchanged.
- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Raised score from `85/87` to `88/90`.
  - Added formal class declaration C++ with `DATEntryRecord`, mapped-file fields, virtual destructor, and `[[CHILDREN]]`.
  - Preserved constructor/destructor child ownership and vtable evidence; no method bodies were duplicated on this class page.
- 2026-06-11 A001 Batch 208 parent-gate repair:
  - Before: score was `80/86`, with layout and constructor/destructor evidence documented but no current vtable subspan evidence or strict-gate rationale for exact child routing.
  - After: score is `85/87`, with exact vtable dwords, vptr-store xrefs, destructor extent, neighboring `DATFile` RTTI boundary, and direct parent-gate decision recorded.
  - Summary/evidence: live IDA MCP confirms `0x00618918-0x00618920` is the one-slot `DATFileContainer` vtable record (`RTTI`, scalar deleting destructor), with stores from constructor/destructor paths; the direct file parent [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) is already `89/85`, so the class now clears the corrected gate for a split memory child.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/86`.
  - Summary/evidence: mapped-file responsibility, full field layout, constructor/destructor ranges, archive-entry boundary evidence, and manager ownership are documented; remaining work is mostly final original field names.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IO`.
  - Evidence: live IDA MCP confirms modeled starts at `0x0049be80` and `0x0049d2d0`, with container construction called from `_DATFileMgr::LoadDATFileIndex` at `0x0049c8bd`; this class and the parent file both meet the 80% completion/confidence attachment gate.
