*** UID:00004V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "File.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_FILE_H
#define NEXUSTK_UTIL_FILE_H

#include "LObject.h"
#include "StringBase.h"
#include <stddef.h>

typedef mystr::StringBase<char, mystr::mychar_traits<char> > StringBaseA;
typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class File : public LObject
{
public:
    virtual ~File() {}

    virtual void Open(const wchar_t *path) = 0;
    virtual bool Close() = 0;
    virtual int GetPosition() = 0;
    virtual bool Seek(int offset, int origin) = 0;
    virtual int GetSize() = 0;
    virtual size_t Read(void *buffer, int count) = 0;
    virtual bool ReadLine(StringBaseA &line) = 0;
    virtual int ReadLineChars(char *buffer, int limit) = 0;

    StringBaseA ReadString(int count);
    bool ReadLine(StringBaseW &line);
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# File

## Status

- Confidence: very strong for abstract base role, direct LObject inheritance, four-byte no-field layout, vtable contract, and direct source-root attachment; exact helper spelling/access remains an inference cap.
- Assigned source root: [UID:0000JB][File](by-file/File.md), with the declaration in `NexusTK/util/File.h` and source-authored convenience helpers in `NexusTK/util/File.cpp`. [UID:0000JD][FileIO](by-file/FileIO.md) is a non-emitting coordination umbrella.
- Recovered source leads remain naming evidence only; current class ownership and declaration shape are based on PE/IDA/MCP evidence and concrete DAT/Stdio override parity.
- Address evidence: [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- Size/layout: 4 bytes and data-member-free; see [UID:0003H1][FileBaseLayout](by-type/by-struct/FileBaseLayout.md) and the shared index [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md).
- Vtable/type evidence: [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md), split from shared index [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md), with exact backing data [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)

## Role

`File` is the abstract file-stream base class used by archive-backed and loose-file readers. It contributes the vtable contract and small source-authored convenience helpers over that contract, while concrete subclasses such as [UID:00003G][DATFile](by-class/DATFile.md) and [UID:0000E6][StdioFile](by-class/StdioFile.md) implement open, close, positioning, size, read, and line-read behavior.

## Confirmed Behavior

| Address | Method | Notes |
| --- | --- | --- |
| `0x0049d390` | `ScalarDeletingDestructor` | Restores the `File` vtable, destroys the `LObject` base, and conditionally frees the object. |
| [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) | file-stream string helper pair | B001-021 assigns this pair here: `0x004b12a0` uses slots `+0x14/+0x1c/+0x20` to read a bounded byte span into a string, and `0x004b1340` uses slot `+0x24` to read a line then converts it to the wide/shared string destination. |

IDA vtable inspection shows `File` has pure virtual entries after the inherited/base runtime slots. `StdioFile` fills the same slots with local `FILE*` operations; `DATFile` fills them with mapped-DAT entry operations.

2026-06-07 IDA MCP recheck confirms the destructor body remains `0x0049d390-0x0049d3ce`, with five bytes of preceding `cc` padding and two bytes of following `cc` padding. The only direct xref to the function start is the File vtable data entry at `0x006188e4`.

## Interface Slots

The primary vtable at `0x006188e4` has destructor/base slots at `+0x00` through `+0x08`; slots `+0x0c` through `+0x28` are pure virtual in `File` and concrete in `DATFile`/`StdioFile`. The source-facing order is `Open`, `Close`, `GetPosition`, `Seek`, `GetSize`, `Read`, ANSI `ReadLine`, and `ReadLineChars`. `Tell` is preserved only as historical naming vocabulary. See [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) for the exact source-local vtable child and [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) for the shared slot map.

The adjacent read-only data page records the exact vtable dwords: RTTI at `0x006188e0`, destructor `0x0049d390` at `0x006188e4`, base/runtime slot `0x004f4b10`, no-op slot `0x0041b6c0`, and `__purecall` entries through `0x0061890c`. The five refs at `0x0049c16e`, `0x0049d294`, `0x0049d396`, `0x005820b9`, and `0x005824be` are destructor/restoration paths. No constructor writes the abstract File vptr; DATFile and StdioFile constructors install their concrete tables directly.

Layout note: File is exactly four bytes, consisting only of the inherited LObject/vptr head. The scalar deleting wrappers use object sizes `4` for File, `0x14` for DATFile, and `0x0c` for StdioFile. Concrete fields at `+0x04` therefore belong to the derived classes; the former shared implementation-handle claim is rejected and retained only as superseded history.

## 2026-06-10 B001-021 File-Stream Helper Assignment

B001-021 rechecked [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) after prior docs left it unassigned as a possible string utility helper. Live IDA MCP confirms it is a `File` convenience helper pair:

- `0x004b12a0` dispatches through `this->vtable` slots `+0x14`, `+0x1c`, and `+0x20`.
- `0x004b1340` dispatches through `this->vtable` slot `+0x24`.
- Direct IDA vtable reads show the abstract File vtable keeps those slots as `__purecall`, DATFile implements them at `0x0049c2d0`, `0x0049c2f0`, `0x0049c310`, and `0x0049c3e0`, and StdioFile implements them at `0x00582200`, `0x004f5ad0`, `0x00582230`, and `0x005822d0`.
- The string helper callees allocate/assign the output buffers; they do not make `StringUtil` or `StringBase` the direct owner.

The helper pair has no direct callers or address-taken refs in current IDA, so exact original spelling and public access remain confidence caps. ABI and behavior nevertheless resolve implementation-ready declarations as `StringBaseA ReadString(int count)` and `bool ReadLine(StringBaseW &line)`.

## Ownership Notes

Keep this with the generic file I/O layer, not with DAT parsing. The base class does not know about archive entry tables, stat buffers, or Miles callbacks; those belong to `DATFile`, `StdioFile`, and `SoundManager` consumers respectively.

## Assignment Decision

Assigned to [UID:0000JB][File](by-file/File.md). This class is now `92/93`, emits first at position `0`, and the direct source page is `91/92`. The broader [UID:0000JD][FileIO](by-file/FileIO.md) umbrella is not the direct parent or emitter.

The formal H now carries the complete strongest human-written class surface behind one guard. The inline empty virtual destructor regenerates compiler wrapper/vtable behavior; all eight common virtual signatures match DAT/Stdio behavior. Formal CPP includes `File.h` and expands `[[CHILDREN]]`, so exact helper definitions emit after the declaration without embedding a duplicate class in File.cpp. The former CPP-resident class shell and absent File.h are historical pre-callback states.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The class page records the complete abstract declaration, direct LObject inheritance, four-byte no-field layout, inline destructor, all eight virtual signatures, two source helpers, exact vtable/RTTI/xref/size evidence, direct file parent, source placement, and compiler-generated child policy. |
| Confidence `93` | Binary facts prove class identity, inheritance, method order, parameter/return contracts, and object size. Confidence remains below final only because exact historical helper spelling/access and original header filename are inferred rather than symbol-recovered. |

## UID0002UV Source-Quality Callback

- RTTI proves `File : public LObject` at displacement zero with no virtual or multiple inheritance.
- The File complete-object locator, two-entry base hierarchy, exact 48-byte vtable record, all-dword xrefs, and unique signature are documented by UID0002UV.
- The File/DAT/Stdio scalar-wrapper size immediates `4`, `0x14`, and `0x0c` prove the complete object-size relationship and reject the former shared base handle.
- `Open(const wchar_t *)` is source-void because concrete callers ignore inconsistent incidental EAX values.
- `Close` returns bool; `GetPosition` and `GetSize` return int; `Seek` takes signed offset/origin and returns bool.
- `Read` returns `size_t` but takes signed `int count`; DATFile's `count < 0` full-payload branch makes an unsigned common declaration impossible.
- ANSI `ReadLine` returns bool by reference and `ReadLineChars` returns int for a caller-provided char buffer/limit.
- No separate ordinary File destructor or constructor body is required. The strongest source is an inline empty virtual destructor and implicit trivial File construction between LObject construction and concrete vptr installation.
- The historical 8-byte/shared-handle and unresolved FileIO-owner claims are preserved as rejected/superseded assumptions, not current truth.

## Cross-References

- [UID:0000JB][File](by-file/File.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md)
- [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md)
- [UID:0001UG][FileStreamLayouts](by-type/by-struct/FileStreamLayouts.md)
- [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md)
- [UID:0002UV][0x006188e0-0x00618910.FileVtableData](by-memory/0x006188e0-0x00618910.FileVtableData.md)
- [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md)

## Changes

- 2026-08-17 B001 UID0000MG support implementation: score unchanged; moved the complete File declaration/typedefs from formal CPP to guarded formal H, changed formal CPP to `#include "File.h"` plus `[[CHILDREN]]`, preserved all eight virtual slots, signed `Read` count, helper declarations, four-byte no-field layout, and compiler-generated destructor/vtable dispositions.

- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the abstract `File` vtable at `0x006188e4`, base destructor at `0x0049d390`, and shared virtual stream contract implemented by `DATFile` and `StdioFile`; no parent/code was attached because final declaration shape remains below the 95+ gate.

- Completion/confidence score update: existed before as `0/0`; changed to `76/86`. Summary: abstract base role, known destructor behavior, vtable slot responsibilities, and subclass relationships are documented with strong confidence, while exact recovered source and all consumer paths remain incomplete. Evidence: `0x0049d390` destructor page, `FileStreamVtables`, `FileStreamLayouts`, and cross-references to `DATFile` and `StdioFile`.
- 2026-06-07 Batch088 class coverage audit:
  - Before: scores were `76/86`, `AUTOGEN_PARENT_UID` was blank, and the direct by-file parent was below the corrected parent gate.
  - After: raised to `85/88` and assigned to [UID:0000JB][File](by-file/File.md) after that parent was raised to `85/87`.
  - Summary/evidence: live IDA/MCP recheck and existing by-memory/type docs confirm destructor bounds, vtable dwords, vptr-store xrefs, pure virtual operation slots, and the concrete DAT/Stdio implementations. C++ remains blank under the 95/95 source-emission gate.
- 2026-06-10 B001-021 helper ownership repair:
  - Before: `00022C` remained unassigned as a possible string utility helper even though it dispatched through virtual slots.
  - After: raised this class to `86/89` and accepted [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md) as a File-class helper pair.
  - Summary/evidence: live IDA MCP maps the helper virtual slots to the File stream contract and confirms StringUtil/StringBase are output-buffer dependencies rather than direct owners.
- 2026-06-12 A004 Batch 319 vtable split sync:
  - Scores remain `86/89`.
  - Added [UID:0003HZ][FileVtable](by-type/by-vtable/FileVtable.md) as the exact source-local vtable child for this class; [UID:0001XK][FileStreamVtables](by-type/by-vtable/FileStreamVtables.md) is now only the non-emitting shared File/DATFile/StdioFile slot-layout index.
  - Evidence: live IDA MCP reconfirmed `??_7File@@6B@`, purecall stream slots, restore/store xrefs, and the unique `0x006188e0-0x00618910` signature.
